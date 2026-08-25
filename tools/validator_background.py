#!/usr/bin/env python3
"""Validate stable documentation UIDs, score headers, and UID references.

Default behavior is a dry run. Pass --apply to write Markdown headers and
validator.ini updates.
"""

from __future__ import annotations

import argparse
import configparser
import concurrent.futures
import contextlib
import hashlib
import io
import json
import os
import re
import shutil
import sys
import tempfile
import threading
import time
import traceback
import uuid
from dataclasses import dataclass, field
from datetime import datetime, timedelta
from pathlib import Path


UID_CHARS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
UID_LENGTH = 6
UID_LINE_RE = re.compile(
    r"^\*\*\* UID:(?P<uid>[A-Z0-9]{6}) \| DO NOT MODIFY OR REMOVE!!! \*\*\*$"
)
DAMAGED_UID_LINE_RE = re.compile(r"^\*\*\* UID:.*\*\*\*$")
UID_REF_RE = re.compile(
    r"\[UID:(?P<uid>[A-Z0-9]{6})\]"
    r"(?P<link>(?:\[[^\]\r\n]+\]\([^) \r\n]+\.md(?:#[^) \r\n]+)?\)|\[[^\]\r\n]*\]))?"
)
TMP_REF_RE = re.compile(
    r"\[TMP:\"(?P<quoted>[^\"\r\n]+)\"\]"
    r"|\[TMP:(?P<bare>[^\]\r\n]+)\]"
)
STATS_ROW_RE = re.compile(
    r"^\|\s*`?(?P<uid>[A-Z0-9]{6})`?\s*\|"
    r"\s*(?P<completion>-?\d+)\s*\|"
    r"\s*(?P<confidence>-?\d+)\s*\|"
    r"\s*-?\d+(?:\.\d+)?\s*\|"
    r"\s*`(?P<path>[^`]+)`\s*\|\s*$"
)
COMPLETION_LINE_RE = re.compile(
    r"^\*\*\* COMPLETION:(?P<value>-?\d+) \| ONLY MODIFY VALUE - DO NOT REMOVE!!! \*\*\*$"
)
CONFIDENCE_LINE_RE = re.compile(
    r"^\*\*\* CONFIDENCE:(?P<value>-?\d+) \| ONLY MODIFY VALUE - DO NOT REMOVE!!! \*\*\*$"
)
PROJECTED_PATH_LINE_RE = re.compile(
    r"^\*\*\* PROPOSED_RECONSTRUCTION_PATH:\"(?P<value>[^\"\r\n]*)\" "
    r"\| ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! \*\*\*$"
)
PROJECTED_PATH_PREFIX = "*** PROPOSED_RECONSTRUCTION_PATH:"
PROJECTED_PATH_INVALID_CHARS_RE = re.compile(r'[<>:"|?*]')
RECONSTRUCTABLE_LINE_RE = re.compile(
    r"^\*\*\* RECONSTRUCTABLE:(?P<value>[^|\r\n]*) "
    r"\| ONLY MODIFY VALUE - DO NOT REMOVE!!! \*\*\*$"
)
AUTOGEN_PARENT_UID_LINE_RE = re.compile(
    r"^\*\*\* AUTOGEN_PARENT_UID:(?P<value>[^|\r\n]*) "
    r"\| ONLY MODIFY VALUE - DO NOT REMOVE!!! \*\*\*$"
)
AUTOGEN_PARENT_POSITION_LINE_RE = re.compile(
    r"^\*\*\* AUTOGEN_PARENT_POSITION_OPTIONAL:(?P<value>[^|\r\n]*) "
    r"\| ONLY MODIFY VALUE - DO NOT REMOVE!!! \*\*\*$"
)
CANONICAL_OWNER_LINE_RE = re.compile(
    r"^\*\*\* CANONICAL_OWNER:(?P<value>[^|\r\n]*) "
    r"\| ONLY MODIFY VALUE - DO NOT REMOVE!!! \*\*\*$"
)
EMITTER_UIDS_LINE_RE = re.compile(
    r"^\*\*\* EMITTER_UIDS:(?P<value>[^|\r\n]*) "
    r"\| ONLY MODIFY VALUE - DO NOT REMOVE!!! \*\*\*$"
)
EMITTER_POSITION_LINE_RE = re.compile(
    r"^\*\*\* EMITTER_POSITION_OPTIONAL:(?P<value>[^|\r\n]*) "
    r"\| ONLY MODIFY VALUE - DO NOT REMOVE!!! \*\*\*$"
)
RECONSTRUCTION_CPP_LINE_RE = re.compile(
    r"^\*\*\* RECONSTRUCTION_CPP CODE:\[\[\[(?P<value>.*)\]\]\] "
    r"\| ONLY MODIFY VALUE - DO NOT REMOVE!!! \*\*\*$"
)
RECONSTRUCTABLE_PREFIX = "*** RECONSTRUCTABLE:"
AUTOGEN_PARENT_UID_PREFIX = "*** AUTOGEN_PARENT_UID:"
AUTOGEN_PARENT_POSITION_PREFIX = "*** AUTOGEN_PARENT_POSITION_OPTIONAL:"
CANONICAL_OWNER_PREFIX = "*** CANONICAL_OWNER:"
EMITTER_UIDS_PREFIX = "*** EMITTER_UIDS:"
EMITTER_POSITION_PREFIX = "*** EMITTER_POSITION_OPTIONAL:"
RECONSTRUCTION_CPP_PREFIX = "*** RECONSTRUCTION_CPP CODE:"
RECONSTRUCTION_CPP_BEGIN_LINE = (
    "*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***"
)
RECONSTRUCTION_CPP_END_LINE = "*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***"
RECONSTRUCTION_H_PREFIX = "*** RECONSTRUCTION_H CODE:"
RECONSTRUCTION_H_BEGIN_LINE = (
    "*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***"
)
RECONSTRUCTION_H_END_LINE = "*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***"
RECONSTRUCTION_IMPORT_START = "<import-from-start>"
RECONSTRUCTION_IMPORT_END = "</import-from-end>"
RECONSTRUCTION_IMPORT_RE = re.compile(
    rf"^{re.escape(RECONSTRUCTION_IMPORT_START)}(?P<paths>.*){re.escape(RECONSTRUCTION_IMPORT_END)}$"
)
RECONSTRUCTION_IMPORT_PATH_LIST_RE = re.compile(r'^\s*"[^"\r\n]+"\s*(?:,\s*"[^"\r\n]+"\s*)*$')
RECONSTRUCTION_IMPORT_EXTENSIONS = {".c", ".cpp", ".h"}
RECONSTRUCTION_IMPORT_ROOT_PREFIX = "third_party_embeds/"
CHILDREN_MARKER = "[[CHILDREN]]"
MALFORMED_CHILDREN_MARKER = "[[]CHILDREN]"
NO_CHILDREN_MARKER = "[[No Children Attached]]"
AUTOGEN_SENTINEL = "// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND."
AUTOGEN_MARKDOWN_SENTINEL = "<!-- AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND. -->"
AUTOGEN_CPP_SOURCE_UID_RE = re.compile(r"^// Source by-file UID: (?P<uid>[A-Z0-9]{6})$", re.MULTILINE)
AUTOGEN_EXCLUDED_TOP_LEVEL_FOLDERS = {
    "by-external-research",
    "by-file",
    "by-meta",
    "by-project-structure",
    "by-resource",
}
AUTOGEN_TOP_LEVEL_REPORTS = {
    "by-class": "-ag-class-coverage.md",
    "by-function": "-ag-function-coverage.md",
    "by-global": "-ag-global-coverage.md",
    "by-item": "-ag-item-coverage.md",
    "by-memory": "-ag-memory-coverage.md",
    "by-type": "-ag-type-coverage.md",
}
AUTOGEN_FILE_REPORT = "-ag-file-coverage.md"
AG_RESEARCH_TRACKER_REPORT = "-ag-research-tracker.md"
AG_COVERAGE_REPORT_BY_MEMORY = "-ag-coverage-report-by-memory.md"
VALIDATOR_AUTOGEN_REPORT_NAMES = frozenset(
    [
        *AUTOGEN_TOP_LEVEL_REPORTS.values(),
        AUTOGEN_FILE_REPORT,
        AG_RESEARCH_TRACKER_REPORT,
        AG_COVERAGE_REPORT_BY_MEMORY,
    ]
)
OLD_COVERAGE_PLACEHOLDERS = (
    "-file-coverage.md",
    "-global-coverage.md",
    "-memory-coverage.md",
)

TOOL_DIR = Path(__file__).resolve().parent
DEFAULT_ROOT = TOOL_DIR.parent
DEFAULT_INI = TOOL_DIR / "validator.ini"
DEFAULT_LOCK = TOOL_DIR / "validator.lock"
DEFAULT_QUEUE_DIR = TOOL_DIR / "validator_queue"
DEFAULT_QUEUE_LOCK = TOOL_DIR / "validator_queue.lock"
DEFAULT_WORKER_LOCK = TOOL_DIR / "validator_worker.lock"
DEFAULT_GENERATED_REFRESH_RESULTS_DIR = DEFAULT_QUEUE_DIR / "generated_refresh_results"
DEFAULT_CACHE_DIR = TOOL_DIR / "validator_cache"
DEFAULT_METADATA_CACHE = DEFAULT_CACHE_DIR / "metadata_cache.json"
CACHE_SCHEMA = 1
CACHE_VERSION = "metadata-cache-v6"
STATS_RELATIVE_PATH = Path("project-level") / "-auto-completion-stats.md"
TMP_REFERENCE_SECTION = "tmp_references"
PROJECTED_PATH_SECTION = "projected_paths"
PROJECTED_PATH_STATUS_SECTION = "projected_path_status"
PROJECTED_PATH_ERROR_SECTION = "projected_path_errors"
PROJECTED_PATH_NONE_VALUE = "NONE"
RECONSTRUCTABLE_SECTION = "reconstructable"
AUTOGEN_PARENT_SECTION = "autogen_parent"
AUTOGEN_PARENT_POSITION_SECTION = "autogen_parent_position"
CANONICAL_OWNER_SECTION = "canonical_owner"
EMITTER_UIDS_SECTION = "emitter_uids"
EMITTER_POSITION_SECTION = "emitter_position"
RECONSTRUCTION_CODE_HASH_SECTION = "reconstruction_code_hash"
RECONSTRUCTION_CODE_MODE_SECTION = "reconstruction_code_mode"
RECONSTRUCTION_H_CODE_HASH_SECTION = "reconstruction_h_code_hash"
RECONSTRUCTION_H_CODE_MODE_SECTION = "reconstruction_h_code_mode"
AUTOGEN_CHILDREN_SECTION = "autogen_children"
AUTOGEN_EMITTER_CHILDREN_SECTION = "autogen_emitter_children"
AUTOGEN_ROOT_SECTION = "autogen_root"
AUTOGEN_ROOTS_SECTION = "autogen_roots"
AUTOGEN_DEAD_END_SECTION = "autogen_dead_ends"
AUTOGEN_STATUS_SECTION = "autogen_status"
AUTOGEN_ERROR_SECTION = "autogen_errors"
RESEARCH_REPORTS_SECTION = "research_reports"
RESEARCH_REPORT_UID_SECTION = "research_report_uid"
RESEARCH_REPORT_AGENT_SECTION = "research_report_agent"
RESEARCH_REPORT_AGENT_SPECS_SECTION = "research_report_agent_specs"
RESEARCH_REPORT_SIZE_SECTION = "research_report_size"
RESEARCH_REPORT_SHA256_SECTION = "research_report_sha256"
RESEARCH_REPORT_EXECUTED_AT_SECTION = "research_report_executed_at"
RESEARCH_REPORT_ORIGINAL_PATH_SECTION = "research_report_original_path"
RESEARCH_REPORT_ERROR_SECTION = "research_report_errors"
RESEARCH_REPORT_CHANGE_EVENTS_SECTION = "research_report_change_events"
RESEARCH_REPORT_ADDITIONAL_UIDS_SECTION = "research_report_additional_uids"
MIGRATION_DRYRUN_MANIFEST = TOOL_DIR / "autogen_owner_emitter_migration_dryrun_manifest.json"
MIGRATION_DRYRUN_REPORT = TOOL_DIR / "autogen_owner_emitter_migration_dryrun.md.dryrun"
AUTO_GENERATED_RELATIVE_PATH = Path("auto-generated")
AUTOGEN_NEXUSTK_RELATIVE_PATH = AUTO_GENERATED_RELATIVE_PATH / "NexusTK"
EXECUTED_RESEARCH_RELATIVE_PATH = Path("executed-b-agent-research")
LOCK_POLL_SECONDS = 0.5
WORKER_POLL_SECONDS = 0.25
DEDUP_COALESCE_SECONDS = 0.5
DEFAULT_ACTION_DETAIL_LIMIT = 10
DEDUP_CONFIG_SECTION = "queue"
DEDUP_CONFIG_KEY = "enable_dedup"
STRONG_DEDUP_CONFIG_KEY = "enable_strong_dedup"
SETTINGS_CONFIG_SECTION = "settings"
STATS_RECONSTRUCTABLE_TABLE_LIMIT_KEY = "stats_table_limit_reconstructable"
STATS_NOT_RECONSTRUCTABLE_TABLE_LIMIT_KEY = "stats_table_limit_not_reconstructable"
FORCE_EMPTY_EMITTERS_MARKER_COMMENTS_KEY = "force_empty_emitters_to_emit_marker_comments"
EMPTY_EMITTER_MARKERS_CONSIDER_NOT_CODED_KEY = "force_empty_emitters_to_emit_marker_comments_consider_not_coded"
EMPTY_EMITTER_MARKERS_CONSIDER_DEADEND_KEY = "force_empty_emitters_to_emit_marker_comments_consider_deadend"
ONLY_COUNT_B_REPORTS_FOR_COVERAGE_KEY = "Only_Count_B_Reports_For_Coverage"
DEFAULT_STATS_RECONSTRUCTABLE_TABLE_LIMIT = 125
DEFAULT_STATS_NOT_RECONSTRUCTABLE_TABLE_LIMIT = 34
DEFAULT_FORCE_EMPTY_EMITTERS_MARKER_COMMENTS = True
DEFAULT_EMPTY_EMITTER_MARKERS_CONSIDER_NOT_CODED = True
DEFAULT_EMPTY_EMITTER_MARKERS_CONSIDER_DEADEND = True
DEFAULT_ONLY_COUNT_B_REPORTS_FOR_COVERAGE = True
REPORT_TARGET_HEADER_RE = re.compile(
    r"^\*\*\s*TARGET-REPORT-UID\s*:\s*(?P<uid>[A-Z0-9]{6})\s*\*\*\s*$",
    re.IGNORECASE,
)
REPORT_TARGET_HEADER_ANY_RE = re.compile(r"^\*\*\s*TARGET-REPORT-UID\s*:", re.IGNORECASE)
REPORT_ADDITIONAL_UIDS_HEADER_RE = re.compile(
    r"^\*\*\s*TARGET-REPORT-ADDITIONAL-UIDS\s*:\s*(?P<uids>.+?)\s*\*\*\s*$",
    re.IGNORECASE,
)
REPORT_ADDITIONAL_UIDS_HEADER_ANY_RE = re.compile(
    r"^\*\*\s*TARGET-REPORT-ADDITIONAL-UIDS\s*:",
    re.IGNORECASE,
)
REPORT_AUTHOR_HEADER_RE = re.compile(
    r"^\*\*\s*AUTHOR-AGENT-ID\s*:\s*(?P<agent>[ABC][0-9]{3})\s*\*\*\s*$",
    re.IGNORECASE,
)
REPORT_AUTHOR_HEADER_ANY_RE = re.compile(r"^\*\*\s*AUTHOR-AGENT-ID\s*:", re.IGNORECASE)
REPORT_AUTHOR_SPECS_HEADER_RE = re.compile(
    r"^\*\*\s*AUTHOR-AGENT-SPECS\s*:\s*(?P<specs>.+?)\s*\*\*\s*$",
    re.IGNORECASE,
)
REPORT_AUTHOR_SPECS_HEADER_ANY_RE = re.compile(r"^\*\*\s*AUTHOR-AGENT-SPECS\s*:", re.IGNORECASE)
REPORT_VALIDATION_STATUS_HEADER_RE = re.compile(
    r"^\*\*\s*REPORT-VALIDATION-STATUS\s*:\s*(?P<status>.+?)\s*\*\*\s*$",
    re.IGNORECASE,
)
REPORT_VALIDATION_STATUS_HEADER_ANY_RE = re.compile(
    r"^\*\*\s*REPORT-VALIDATION-STATUS\s*:",
    re.IGNORECASE,
)
REPORT_REVALIDATION_REASON_HEADER_RE = re.compile(
    r"^\*\*\s*REPORT-REVALIDATION-REASON\s*:\s*(?P<reason>.+?)\s*\*\*\s*$",
    re.IGNORECASE,
)
REPORT_REVALIDATION_REASON_HEADER_ANY_RE = re.compile(
    r"^\*\*\s*REPORT-REVALIDATION-REASON\s*:",
    re.IGNORECASE,
)
REPORT_HEADER_SCAN_LINES = 15
DEFAULT_AUTHOR_AGENT_SPECS = "CHATGPT | 5.5 | xHigh"
REPORT_VALIDATION_STATUS_NEEDS_REVALIDATION = "needs-revalidation"
VALIDATOR_REPORT_HISTORY_BEGIN = "<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->"
VALIDATOR_REPORT_HISTORY_END = "<!-- VALIDATOR-REPORT-HISTORY:END -->"
VALIDATOR_REPORT_HISTORY_LINE_RE = re.compile(r"^<!--\s*(?P<json>\{.*\})\s*-->$")
TRACKER_THINKING_BUCKETS = ("xHigh", "High", "Medium")
TRACKER_THINKING_BUCKET_BY_LOWER = {bucket.lower(): bucket for bucket in TRACKER_THINKING_BUCKETS}
REPORT_TARGET_UID_LINE_RE = re.compile(
    r"^\s*(?:[-*]\s*)?(?:target(?:\s+uid)?|current\s+target)\s*:\s*(?P<value>.+)$",
    re.IGNORECASE,
)
REPORT_BODY_UID_RE = re.compile(r"(?:UID:)?(?P<uid>[A-Z0-9]{6})")
REPORT_BODY_PATH_RE = re.compile(r"`?(?P<path>by-[^`\s]+?\.md)`?", re.IGNORECASE)
REPORT_FILENAME_UID_RE = re.compile(r"^(?P<uid>[A-Z0-9]{6})(?:[-_.]|$)")
AGENT_ID_RE = re.compile(r"^[ABC][0-9]{3}$", re.IGNORECASE)
BY_MEMORY_RANGE_RE = re.compile(
    r"^0x(?P<start>[0-9A-Fa-f]+)-0x(?P<end>[0-9A-Fa-f]+)\.(?P<name>.+)\.md$"
)
ITEM_SUMMARY_LINE_RE = re.compile(
    r"^\*\*\* Item Summary:\s*(?P<value>.*?)\s+\| ONLY MODIFY VALUE - DO NOT REMOVE!!! \*\*\*$"
)
ITEM_SUMMARY_ANY_LINE_RE = re.compile(r"^\*\*\* Item Summary:.*$")
NESTED_LINE_RE = re.compile(
    r"^\*\*\* Nested:(?P<value>-?\d*) \| ONLY MODIFY VALUE - DO NOT REMOVE!!! \*\*\*$"
)
NESTED_ANY_LINE_RE = re.compile(r"^\*\*\* Nested:.*$")
MANUAL_MEMORY_ROW_RE = re.compile(
    r"^(?P<indent>\s*)-\s+\[UID:(?P<uid>[A-Z0-9]{6})\]"
    r".*?\]\((?P<path>[^)]+)\)(?P<tail>.*)$"
)
MANUAL_MEMORY_STATUS_SUMMARY_RE = re.compile(
    r"\s:\s(?:ignored|reconstructable(?:/no-owner)?|not[_ -]reconstructable|nonreconstructable|unknown)"
    r"\s:\s\d+%\s:\s(?:very[- ]strong|medium[- ]high|strong|medium|weak)\s:\s(?P<summary>.*)$",
    re.IGNORECASE,
)
MEMORY_SUMMARY_AUTO_PREFIX_RE = re.compile(
    r"^\s*(?:-\s*)?(?:(?:ignored|reconstructable(?:/no-owner)?|not[_ -]reconstructable|nonreconstructable|unknown)"
    r"\s*:\s*\d+%\s*:\s*(?:very[- ]strong|medium[- ]high|strong|medium|weak)\s*:\s*)+",
    re.IGNORECASE,
)
MEMORY_SUMMARY_CONFIDENCE_PREFIX_RE = re.compile(
    r"^(?:-\s*)?Confidence(?:\s+`?\d{1,3}`?|\s*:\s*(?:very[- ]strong|medium[- ]high|strong|medium|weak))?"
    r"(?:\s+(?:after|for|that)\s+|[;:.]\s*)",
    re.IGNORECASE,
)
COMMAND_ALIASES = {
    "execute_report": "execute-report",
    "execute-report": "execute-report",
    "invalidate_execute": "invalidate-execute",
    "invalidate-execute": "invalidate-execute",
    "execute_rescan_reports": "execute-rescan-reports",
    "execute-rescan-reports": "execute-rescan-reports",
    "execute_confirm_change": "execute-confirm-change",
    "execute-confirm-change": "execute-confirm-change",
    "execute_confirm_removed_archives": "execute-confirm-removed-archives",
    "execute-confirm-removed-archives": "execute-confirm-removed-archives",
    "executed_reassign": "executed-reassign",
    "executed-reassign": "executed-reassign",
    "executed_mark_invalid": "executed-mark-invalid",
    "executed-mark-invalid": "executed-mark-invalid",
    "executed_mark_needs_revalidation": "executed-mark-needs-revalidation",
    "executed-mark-needs-revalidation": "executed-mark-needs-revalidation",
    "executed_clear_revalidation": "executed-clear-revalidation",
    "executed-clear-revalidation": "executed-clear-revalidation",
    "active_clear_revalidation": "active-clear-revalidation",
    "active-clear-revalidation": "active-clear-revalidation",
    "migrate_executed_reports": "migrate-executed-reports",
    "migrate-executed-reports": "migrate-executed-reports",
    "migrate_report_agent_specs": "migrate-report-agent-specs",
    "migrate-report-agent-specs": "migrate-report-agent-specs",
    "migrate_report_history": "migrate-report-history",
    "migrate-report-history": "migrate-report-history",
    "migrate_reconstruction_h": "migrate-reconstruction-h",
    "migrate-reconstruction-h": "migrate-reconstruction-h",
}
DEDUP_NONE = "none"
DEDUP_READ_ONLY = "read_only"
DEDUP_GLOBAL_REFRESH = "global_refresh"
IGNORED_SCORE_FOLDERS = {
    "by-external-research",
    "by-meta",
    "by-project-structure",
}

_TEXT_CACHE: dict[Path, tuple[int, int, str]] = {}
_FILE_HASH_CACHE: dict[Path, tuple[int, int, str]] = {}
_RESOLVE_CACHE: dict[Path, Path] = {}
_DEDUP_CONFIG_CACHE: tuple[int | None, bool, bool] = (None, False, False)
_METADATA_CACHE_DIRTY = False
_METADATA_CACHE: dict | None = None


@dataclass
class ScanAction:
    action: str
    uid: str | None
    path: Path
    detail: str = ""


@dataclass(frozen=True)
class StatsEntry:
    uid: str
    path: str
    folder: str
    completion: int
    confidence: int
    reconstructable: str = "blank"

    @property
    def combined(self) -> float:
        return (self.completion + self.confidence) / 2.0


@dataclass(frozen=True)
class ProjectedPathEntry:
    uid: str
    status: str
    projected_path: str
    path: str
    detail: str


@dataclass(frozen=True)
class StatsTableLimits:
    reconstructable: int
    not_reconstructable: int


@dataclass
class AutogenMetadata:
    uid: str
    path: str
    folder: str
    eligible: bool
    reconstructable: str = "blank"
    canonical_owner: str = "NONE"
    canonical_owner_raw: str = ""
    canonical_owner_seen: bool = False
    emitter_uids: list[str] = field(default_factory=list)
    emitter_uids_raw: str = ""
    emitter_positions: list[int | None] = field(default_factory=list)
    emitter_position: int | None = None
    emitter_position_raw: str = ""
    parent_uid: str = ""
    parent_position: int | None = None
    parent_position_raw: str = ""
    code: str = ""
    code_mode: str = "blank"
    code_hash: str = ""
    import_paths: tuple[str, ...] = ()
    header_code: str = ""
    header_code_mode: str = "blank"
    header_code_hash: str = ""
    errors: list[str] | None = None


@dataclass(frozen=True)
class AutogenReportEntry:
    uid: str
    path: str
    folder: str
    status: str
    canonical_owner: str = ""
    owner_state: str = "blank"
    emitter_uids: tuple[str, ...] = ()
    emitter_targets: tuple[tuple[str, str], ...] = ()
    position: str = ""
    has_code: bool = False
    has_header_code: bool = False
    destination: str = ""
    header_destination: str = ""
    detail: str = ""
    dead_end_detail: str = ""


@dataclass(frozen=True)
class GeneratedWrite:
    path: Path
    text: str
    uid: str | None
    create_action: str
    update_action: str
    noop_action: str
    conflict_action: str
    backup_enabled: bool = True
    metadata_refresh_action: str = "generated_metadata_refresh"


@dataclass(frozen=True)
class FileObservation:
    path: Path
    rel: str
    error: str | None = None
    uid: str | None = None
    item_summary: str = ""
    nested: int | None = None
    has_item_summary: bool = False
    has_nested: bool = False
    autogen_metadata: AutogenMetadata | None = None
    autogen_actions: tuple[ScanAction, ...] = ()


@dataclass(frozen=True)
class CommandContext:
    command_id: int = 0
    command_id_display: str = "000000000000"
    command_timestamp: str = ""

    @property
    def has_command(self) -> bool:
        return self.command_id > 0 and bool(self.command_timestamp)


@dataclass(frozen=True)
class ReportHeaderMetadata:
    target_uid: str | None = None
    additional_target_uids: tuple[str, ...] = ()
    author_agent: str | None = None
    author_specs: str | None = None
    validation_status: str | None = None
    revalidation_reason: str | None = None
    errors: tuple[str, ...] = ()


@dataclass(frozen=True)
class ReportFileMetadata:
    header: ReportHeaderMetadata
    size: int
    sha256: str
    read_error: str | None = None
    footer_error: str | None = None


@dataclass(frozen=True)
class ResearchReportRecord:
    path: str
    uid: str
    agent: str
    agent_specs: str
    size: int
    sha256: str
    executed_at: str
    additional_uids: tuple[str, ...] = ()
    original_path: str = ""
    validation_status: str = ""
    revalidation_reason: str = ""

    @property
    def thinking_level_bucket(self) -> str:
        return thinking_level_bucket_from_specs(self.agent_specs)


@dataclass(frozen=True)
class ResearchTrackerEntry:
    uid: str
    path: str
    folder: str
    completion: int
    confidence: int
    reconstructable: str
    direct_report_paths: tuple[str, ...]
    additional_report_paths: tuple[str, ...]
    report_agents: tuple[str, ...]
    direct_coverage_report_paths: tuple[str, ...]
    additional_coverage_report_paths: tuple[str, ...]
    thinking_counts: tuple[tuple[str, int], ...]
    last_executed_at: str

    @property
    def combined(self) -> float:
        return (self.completion + self.confidence) / 2.0

    @property
    def covered(self) -> bool:
        return self.direct_covered or self.additional_covered

    @property
    def direct_covered(self) -> bool:
        return bool(self.direct_coverage_report_paths)

    @property
    def additional_covered(self) -> bool:
        return bool(self.additional_coverage_report_paths)

    @property
    def coverage_state(self) -> str:
        if self.direct_covered and self.additional_covered:
            return "direct_and_additional"
        if self.direct_covered:
            return "direct_only"
        if self.additional_covered:
            return "additional_only"
        return "not_covered"

    @property
    def all_report_paths(self) -> tuple[str, ...]:
        return tuple(sorted(set(self.direct_report_paths) | set(self.additional_report_paths)))

    @property
    def coverage_report_paths(self) -> tuple[str, ...]:
        return tuple(
            sorted(set(self.direct_coverage_report_paths) | set(self.additional_coverage_report_paths))
        )


@dataclass(frozen=True)
class ResearchReportState:
    valid_records: tuple[ResearchReportRecord, ...]
    errors: tuple[str, ...]
    direct_records_by_uid: dict[str, tuple[ResearchReportRecord, ...]]
    additional_records_by_uid: dict[str, tuple[ResearchReportRecord, ...]]
    report_agent_by_path: dict[str, str]


@dataclass(frozen=True)
class EmptyEmitterFileEntry:
    root_uid: str
    root_path: str
    destination: str
    total_emitters: int
    empty_emitters: int


@dataclass(frozen=True)
class MemoryCoverageEntry:
    uid: str
    path: str
    start: int | None
    end: int | None
    name: str
    completion: int
    confidence: int
    reconstructable: str
    emits_code: bool
    summary: str
    nested_delta: int
    updated_at: str
    errors: tuple[str, ...] = ()


class ValidatorLock:
    """Single-process file lock for validator.ini and reference state."""

    def __init__(self, path: Path, timeout_seconds: float) -> None:
        self.path = path
        self.timeout_seconds = timeout_seconds
        self.handle = None

    def __enter__(self) -> "ValidatorLock":
        self.acquire()
        return self

    def __exit__(self, exc_type, exc, tb) -> None:
        self.release()

    def acquire(self) -> None:
        self.path.parent.mkdir(parents=True, exist_ok=True)
        self.handle = self.path.open("a+", encoding="utf-8")
        deadline = None if self.timeout_seconds < 0 else time.monotonic() + self.timeout_seconds
        announced_wait = False

        while True:
            try:
                self._lock_nonblocking()
                break
            except OSError:
                if self.timeout_seconds == 0:
                    self.handle.close()
                    self.handle = None
                    raise SystemExit(f"validator lock is held by another process: {self.path}")
                if deadline is not None and time.monotonic() >= deadline:
                    self.handle.close()
                    self.handle = None
                    raise SystemExit(
                        f"timed out waiting for validator lock after {self.timeout_seconds:g}s: {self.path}"
                    )
                if not announced_wait:
                    print(f"waiting for validator lock: {self.path}", file=sys.stderr)
                    announced_wait = True
                time.sleep(LOCK_POLL_SECONDS)

        self.handle.seek(0)
        self.handle.truncate()
        self.handle.write(
            f"pid={os.getpid()}\n"
            f"started={datetime.now().isoformat(timespec='seconds')}\n"
        )
        self.handle.flush()

    def release(self) -> None:
        if self.handle is None:
            return
        try:
            self._unlock()
        finally:
            self.handle.close()
            self.handle = None

    def _lock_nonblocking(self) -> None:
        assert self.handle is not None
        self.handle.seek(0)
        if os.name == "nt":
            import msvcrt

            msvcrt.locking(self.handle.fileno(), msvcrt.LK_NBLCK, 1)
        else:
            import fcntl

            fcntl.flock(self.handle.fileno(), fcntl.LOCK_EX | fcntl.LOCK_NB)

    def _unlock(self) -> None:
        assert self.handle is not None
        self.handle.seek(0)
        if os.name == "nt":
            import msvcrt

            msvcrt.locking(self.handle.fileno(), msvcrt.LK_UNLCK, 1)
        else:
            import fcntl

            fcntl.flock(self.handle.fileno(), fcntl.LOCK_UN)


def make_uid_line(uid: str) -> str:
    return f"*** UID:{uid} | DO NOT MODIFY OR REMOVE!!! ***"


def make_completion_line(value: int) -> str:
    return f"*** COMPLETION:{value} | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***"


def make_confidence_line(value: int) -> str:
    return f"*** CONFIDENCE:{value} | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***"


def make_projected_path_line(value: str) -> str:
    return (
        f"*** PROPOSED_RECONSTRUCTION_PATH:\"{value}\" "
        "| ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***"
    )


def make_reconstructable_line(value: str) -> str:
    return f"*** RECONSTRUCTABLE:{value} | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***"


def make_autogen_parent_uid_line(value: str) -> str:
    return f"*** AUTOGEN_PARENT_UID:{value} | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***"


def make_autogen_parent_position_line(value: str) -> str:
    return (
        f"*** AUTOGEN_PARENT_POSITION_OPTIONAL:{value} "
        "| ONLY MODIFY VALUE - DO NOT REMOVE!!! ***"
    )


def make_canonical_owner_line(value: str) -> str:
    return f"*** CANONICAL_OWNER:{value} | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***"


def make_emitter_uids_line(value: str) -> str:
    return f"*** EMITTER_UIDS:{value} | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***"


def make_emitter_position_line(value: str) -> str:
    return (
        f"*** EMITTER_POSITION_OPTIONAL:{value} "
        "| ONLY MODIFY VALUE - DO NOT REMOVE!!! ***"
    )


def make_reconstruction_cpp_line(value: str) -> str:
    return f"*** RECONSTRUCTION_CPP CODE:[[[{value}]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***"


def is_valid_score(value: int) -> bool:
    return value == -1 or 0 <= value <= 100


def detect_newline(text: str) -> str:
    if "\r\n" in text:
        return "\r\n"
    return "\n"


def path_cache_key(path: Path) -> Path:
    return Path(os.path.normcase(os.path.abspath(path)))


def resolved_path(path: Path) -> Path:
    key = path_cache_key(path)
    cached = _RESOLVE_CACHE.get(key)
    if cached is not None:
        return cached
    try:
        resolved = path.resolve(strict=False)
    except RuntimeError:
        resolved = path.absolute()
    _RESOLVE_CACHE[key] = resolved
    return resolved


def read_text(path: Path) -> str:
    key = path_cache_key(path)
    stat = path.stat()
    cached = _TEXT_CACHE.get(key)
    if cached is not None and cached[0] == stat.st_mtime_ns and cached[1] == stat.st_size:
        return cached[2]
    text = path.read_text(encoding="utf-8-sig")
    _TEXT_CACHE[key] = (stat.st_mtime_ns, stat.st_size, text)
    return text


def remember_text_cache(path: Path, text: str) -> None:
    key = path_cache_key(path)
    stat = path.stat()
    _TEXT_CACHE[key] = (stat.st_mtime_ns, stat.st_size, text)


def first_line(text: str) -> str:
    newline_index = text.find("\n")
    line = text if newline_index == -1 else text[:newline_index]
    return line[:-1] if line.endswith("\r") else line


def first_line_uid(text: str) -> str | None:
    match = UID_LINE_RE.match(first_line(text))
    if not match:
        return None
    return match.group("uid")


def first_folder_from_relative(path: str) -> str:
    return path.replace("\\", "/").split("/", 1)[0]


def folder_for_uid(config: configparser.ConfigParser, uid: str | None) -> str:
    if uid and uid in config["files"]:
        return first_folder_from_relative(config["files"].get(uid, ""))
    return "unknown"


def default_score_for_relative_path(path: str) -> int:
    folder = first_folder_from_relative(path)
    return -1 if folder in IGNORED_SCORE_FOLDERS else 0


def default_score_for_path(root: Path, path: Path) -> int:
    return default_score_for_relative_path(relative_path(root, path))


def score_from_match(match: re.Match[str]) -> int | None:
    value = int(match.group("value"))
    return value if is_valid_score(value) else None


def parse_completion_line(line: str) -> int | None:
    match = COMPLETION_LINE_RE.match(line)
    return score_from_match(match) if match else None


def parse_confidence_line(line: str) -> int | None:
    match = CONFIDENCE_LINE_RE.match(line)
    return score_from_match(match) if match else None


def parse_projected_path_line(line: str) -> str | None:
    match = PROJECTED_PATH_LINE_RE.match(line)
    return match.group("value") if match else None


def parse_reconstructable_value(value: str) -> str:
    normalized = value.strip().upper()
    if normalized == "":
        return "blank"
    if normalized in {"TRUE", "1"}:
        return "true"
    if normalized in {"FALSE", "0"}:
        return "false"
    return "invalid"


def parse_reconstructable_line(line: str) -> tuple[str, str] | None:
    match = RECONSTRUCTABLE_LINE_RE.match(line)
    if not match:
        return None
    raw = match.group("value").strip()
    return raw, parse_reconstructable_value(raw)


def parse_parent_uid_line(line: str) -> tuple[str, bool] | None:
    match = AUTOGEN_PARENT_UID_LINE_RE.match(line)
    if not match:
        return None
    raw = match.group("value").strip().upper()
    return raw, raw == "" or re.fullmatch(r"[A-Z0-9]{6}", raw) is not None


def parse_parent_position_line(line: str) -> tuple[str, int | None, bool] | None:
    match = AUTOGEN_PARENT_POSITION_LINE_RE.match(line)
    if not match:
        return None
    raw = match.group("value").strip()
    if raw == "":
        return raw, None, True
    if re.fullmatch(r"[0-9]+", raw):
        return raw, int(raw), True
    return raw, None, False


def parse_canonical_owner_line(line: str) -> tuple[str, bool] | None:
    match = CANONICAL_OWNER_LINE_RE.match(line)
    if not match:
        return None
    raw = match.group("value").strip().upper()
    return raw, raw in {"", "NONE", "FILE"} or re.fullmatch(r"[A-Z0-9]{6}", raw) is not None


def parse_emitter_uids_line(line: str) -> tuple[str, list[str], bool] | None:
    match = EMITTER_UIDS_LINE_RE.match(line)
    if not match:
        return None
    raw = match.group("value").strip().upper()
    if raw == "":
        return raw, [], True
    emitters = [item.strip().upper() for item in raw.split(",")]
    ok = all(re.fullmatch(r"[A-Z0-9]{6}", item) is not None for item in emitters)
    ok = ok and all(item != "" for item in emitters)
    return ",".join(emitters), emitters, ok


def parse_emitter_position_line(line: str) -> tuple[str, list[int | None], bool] | None:
    match = EMITTER_POSITION_LINE_RE.match(line)
    if not match:
        return None
    raw = match.group("value").strip()
    if raw == "":
        return raw, [], True

    parts = [item.strip() for item in raw.split(",")]
    positions: list[int | None] = []
    ok = True
    for item in parts:
        if item == "":
            positions.append(None)
        elif re.fullmatch(r"[0-9]+", item):
            positions.append(int(item))
        else:
            ok = False
            positions.append(None)
    normalized = ",".join(parts)
    return normalized, positions, ok


def parse_reconstruction_cpp_line(line: str) -> str | None:
    match = RECONSTRUCTION_CPP_LINE_RE.match(line)
    return match.group("value") if match else None


def code_hash(code: str) -> str:
    if code == "":
        return ""
    return hashlib.sha256(code.encode("utf-8")).hexdigest()


def validate_reconstruction_import_path(value: str) -> tuple[str, str | None]:
    if value.strip() != value:
        return value, "path must not have leading or trailing whitespace"
    if "\\" in value:
        return value, "path must use forward slashes"
    if value.startswith("/") or re.match(r"^[A-Za-z]:", value):
        return value, "path must be relative"
    if PROJECTED_PATH_INVALID_CHARS_RE.search(value):
        return value, "path contains characters that are invalid in Windows paths"
    if not value.startswith(RECONSTRUCTION_IMPORT_ROOT_PREFIX):
        return value, f"path must start with {RECONSTRUCTION_IMPORT_ROOT_PREFIX}"
    path = Path(value)
    if path.suffix.lower() not in RECONSTRUCTION_IMPORT_EXTENSIONS:
        return value, "path must end with .c, .cpp, or .h"
    parts = value.split("/")
    if any(part == "" for part in parts):
        return value, "path contains an empty segment"
    if any(part in {".", ".."} for part in parts):
        return value, "path must not contain . or .. segments"
    return value, None


def parse_reconstruction_import_directive(value: str) -> tuple[tuple[str, ...], list[str]] | None:
    match = RECONSTRUCTION_IMPORT_RE.fullmatch(value)
    if not match:
        return None
    raw_paths = match.group("paths")
    if not RECONSTRUCTION_IMPORT_PATH_LIST_RE.fullmatch(raw_paths):
        return (), ["import_from_invalid: paths must be quoted and comma-separated"]
    paths: list[str] = []
    errors: list[str] = []
    for raw_path in re.findall(r'"([^"\r\n]+)"', raw_paths):
        path, error = validate_reconstruction_import_path(raw_path)
        if error is not None:
            errors.append(f"import_from_invalid: {path}: {error}")
        paths.append(path)
    if len(paths) != len(set(paths)):
        errors.append("import_from_duplicate: duplicate import path")
    return tuple(paths), errors


def reconstruction_import_source_path(root: Path, import_path: str) -> Path:
    source_root = root.parent if root.name == "project-documentation" else root
    return source_root / Path(import_path)


def reconstruction_import_hash_input(root: Path, inline_value: str, import_paths: tuple[str, ...]) -> tuple[str, list[str]]:
    parts = [inline_value]
    errors: list[str] = []
    for import_path in import_paths:
        source_path = reconstruction_import_source_path(root, import_path)
        try:
            digest = file_sha256(source_path)
        except OSError as exc:
            errors.append(f"import_from_read_error: {import_path}: {exc}")
            continue
        parts.append(f"{import_path}:{digest}")
    return "\n".join(parts), errors


def uid_for_relative_path(config: configparser.ConfigParser, rel: str) -> str | None:
    normalized = rel.replace("\\", "/")
    matches = [
        uid for uid, stored_path in config["files"].items()
        if stored_path.replace("\\", "/") == normalized
    ]
    return matches[0] if len(matches) == 1 else None


def stored_score_or_default(
    config: configparser.ConfigParser,
    section: str,
    uid: str,
    rel: str,
) -> tuple[int, str]:
    raw_value = config[section].get(uid)
    if raw_value is None:
        return default_score_for_relative_path(rel), "default"
    try:
        value = int(raw_value)
    except ValueError:
        return default_score_for_relative_path(rel), "default"
    if is_valid_score(value):
        return value, "stored"
    return default_score_for_relative_path(rel), "default"


def stored_autogen_value(
    config: configparser.ConfigParser,
    section: str,
    uid: str,
) -> str:
    return config[section].get(uid, "").strip()


def positive_settings_int(
    config: configparser.ConfigParser,
    key: str,
    default: int,
) -> int:
    raw_value = config[SETTINGS_CONFIG_SECTION].get(key, str(default))
    try:
        value = int(raw_value)
    except ValueError:
        return default
    if value <= 0:
        return default
    return value


def stats_table_limits(config: configparser.ConfigParser) -> StatsTableLimits:
    return StatsTableLimits(
        reconstructable=positive_settings_int(
            config,
            STATS_RECONSTRUCTABLE_TABLE_LIMIT_KEY,
            DEFAULT_STATS_RECONSTRUCTABLE_TABLE_LIMIT,
        ),
        not_reconstructable=positive_settings_int(
            config,
            STATS_NOT_RECONSTRUCTABLE_TABLE_LIMIT_KEY,
            DEFAULT_STATS_NOT_RECONSTRUCTABLE_TABLE_LIMIT,
        ),
    )


def settings_bool(
    config: configparser.ConfigParser,
    key: str,
    default: bool,
) -> bool:
    try:
        return config.getboolean(SETTINGS_CONFIG_SECTION, key, fallback=default)
    except ValueError:
        return default


def ensure_settings_bool(
    config: configparser.ConfigParser,
    key: str,
    default: bool,
) -> None:
    if key not in config[SETTINGS_CONFIG_SECTION]:
        config[SETTINGS_CONFIG_SECTION][key] = "true" if default else "false"
        return
    try:
        config.getboolean(SETTINGS_CONFIG_SECTION, key)
    except ValueError:
        config[SETTINGS_CONFIG_SECTION][key] = "true" if default else "false"


def force_empty_emitter_marker_comments(config: configparser.ConfigParser) -> bool:
    return settings_bool(
        config,
        FORCE_EMPTY_EMITTERS_MARKER_COMMENTS_KEY,
        DEFAULT_FORCE_EMPTY_EMITTERS_MARKER_COMMENTS,
    )


def empty_emitter_markers_consider_not_coded(config: configparser.ConfigParser) -> bool:
    return settings_bool(
        config,
        EMPTY_EMITTER_MARKERS_CONSIDER_NOT_CODED_KEY,
        DEFAULT_EMPTY_EMITTER_MARKERS_CONSIDER_NOT_CODED,
    )


def empty_emitter_markers_consider_deadend(config: configparser.ConfigParser) -> bool:
    return settings_bool(
        config,
        EMPTY_EMITTER_MARKERS_CONSIDER_DEADEND_KEY,
        DEFAULT_EMPTY_EMITTER_MARKERS_CONSIDER_DEADEND,
    )


def only_count_b_reports_for_coverage(config: configparser.ConfigParser) -> bool:
    return settings_bool(
        config,
        ONLY_COUNT_B_REPORTS_FOR_COVERAGE_KEY,
        DEFAULT_ONLY_COUNT_B_REPORTS_FOR_COVERAGE,
    )


def ensure_positive_settings_int(
    config: configparser.ConfigParser,
    key: str,
    default: int,
) -> None:
    if key not in config[SETTINGS_CONFIG_SECTION]:
        config[SETTINGS_CONFIG_SECTION][key] = str(default)
        return
    if positive_settings_int(config, key, default) != default:
        return
    try:
        parsed = int(config[SETTINGS_CONFIG_SECTION].get(key, ""))
    except ValueError:
        parsed = 0
    if parsed <= 0:
        config[SETTINGS_CONFIG_SECTION][key] = str(default)


def base36_to_int(uid: str) -> int:
    value = 0
    for char in uid:
        if char not in UID_CHARS:
            raise ValueError(f"invalid UID character {char!r}")
        value = value * len(UID_CHARS) + UID_CHARS.index(char)
    return value


def int_to_base36(value: int) -> str:
    if value < 0:
        raise ValueError("UID value cannot be negative")
    chars: list[str] = []
    base = len(UID_CHARS)
    for _ in range(UID_LENGTH):
        value, rem = divmod(value, base)
        chars.append(UID_CHARS[rem])
    if value:
        raise RuntimeError("UID space exhausted")
    return "".join(reversed(chars))


def next_uid(last_uid: str) -> str:
    return int_to_base36(base36_to_int(last_uid) + 1)


def load_config(path: Path) -> configparser.ConfigParser:
    config = configparser.ConfigParser(interpolation=None)
    config.optionxform = str
    if path.exists():
        config.read(path, encoding="utf-8-sig")
    if "state" not in config:
        config["state"] = {}
    if "files" not in config:
        config["files"] = {}
    if "completion" not in config:
        config["completion"] = {}
    if "confidence" not in config:
        config["confidence"] = {}
    if "references" not in config:
        config["references"] = {}
    if SETTINGS_CONFIG_SECTION not in config:
        config[SETTINGS_CONFIG_SECTION] = {}
    ensure_positive_settings_int(
        config,
        STATS_RECONSTRUCTABLE_TABLE_LIMIT_KEY,
        DEFAULT_STATS_RECONSTRUCTABLE_TABLE_LIMIT,
    )
    ensure_positive_settings_int(
        config,
        STATS_NOT_RECONSTRUCTABLE_TABLE_LIMIT_KEY,
        DEFAULT_STATS_NOT_RECONSTRUCTABLE_TABLE_LIMIT,
    )
    ensure_settings_bool(
        config,
        FORCE_EMPTY_EMITTERS_MARKER_COMMENTS_KEY,
        DEFAULT_FORCE_EMPTY_EMITTERS_MARKER_COMMENTS,
    )
    ensure_settings_bool(
        config,
        EMPTY_EMITTER_MARKERS_CONSIDER_NOT_CODED_KEY,
        DEFAULT_EMPTY_EMITTER_MARKERS_CONSIDER_NOT_CODED,
    )
    ensure_settings_bool(
        config,
        EMPTY_EMITTER_MARKERS_CONSIDER_DEADEND_KEY,
        DEFAULT_EMPTY_EMITTER_MARKERS_CONSIDER_DEADEND,
    )
    ensure_settings_bool(
        config,
        ONLY_COUNT_B_REPORTS_FOR_COVERAGE_KEY,
        DEFAULT_ONLY_COUNT_B_REPORTS_FOR_COVERAGE,
    )
    if TMP_REFERENCE_SECTION not in config:
        config[TMP_REFERENCE_SECTION] = {}
    if PROJECTED_PATH_SECTION not in config:
        config[PROJECTED_PATH_SECTION] = {}
    if PROJECTED_PATH_STATUS_SECTION not in config:
        config[PROJECTED_PATH_STATUS_SECTION] = {}
    if PROJECTED_PATH_ERROR_SECTION not in config:
        config[PROJECTED_PATH_ERROR_SECTION] = {}
    for section in [
        RECONSTRUCTABLE_SECTION,
        AUTOGEN_PARENT_SECTION,
        AUTOGEN_PARENT_POSITION_SECTION,
        CANONICAL_OWNER_SECTION,
        EMITTER_UIDS_SECTION,
        EMITTER_POSITION_SECTION,
        RECONSTRUCTION_CODE_HASH_SECTION,
        RECONSTRUCTION_CODE_MODE_SECTION,
        RECONSTRUCTION_H_CODE_HASH_SECTION,
        RECONSTRUCTION_H_CODE_MODE_SECTION,
        AUTOGEN_CHILDREN_SECTION,
        AUTOGEN_EMITTER_CHILDREN_SECTION,
        AUTOGEN_ROOT_SECTION,
        AUTOGEN_ROOTS_SECTION,
        AUTOGEN_DEAD_END_SECTION,
        AUTOGEN_STATUS_SECTION,
        AUTOGEN_ERROR_SECTION,
        RESEARCH_REPORTS_SECTION,
        RESEARCH_REPORT_UID_SECTION,
        RESEARCH_REPORT_AGENT_SECTION,
        RESEARCH_REPORT_AGENT_SPECS_SECTION,
        RESEARCH_REPORT_SIZE_SECTION,
        RESEARCH_REPORT_SHA256_SECTION,
        RESEARCH_REPORT_EXECUTED_AT_SECTION,
        RESEARCH_REPORT_ORIGINAL_PATH_SECTION,
        RESEARCH_REPORT_ERROR_SECTION,
        RESEARCH_REPORT_CHANGE_EVENTS_SECTION,
        RESEARCH_REPORT_ADDITIONAL_UIDS_SECTION,
    ]:
        if section not in config:
            config[section] = {}
    last_uid = config["state"].get("last_used_uid", "000000").strip().upper()
    if not re.fullmatch(r"[A-Z0-9]{6}", last_uid):
        last_uid = "000000"
    config["state"]["last_used_uid"] = last_uid
    return config


def write_config_atomic(config: configparser.ConfigParser, path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    buffer = io.StringIO()
    config.write(buffer)
    text = buffer.getvalue()
    try:
        if path.exists() and read_text(path) == text:
            remember_text_cache(path, text)
            return
    except UnicodeDecodeError:
        pass
    with tempfile.NamedTemporaryFile(
        "w", encoding="utf-8", newline="\n", delete=False, dir=str(path.parent)
    ) as tmp:
        tmp.write(text)
        tmp_name = tmp.name
    os.replace(tmp_name, path)
    remember_text_cache(path, text)


def write_text_atomic(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    try:
        if path.exists() and read_text(path) == text:
            remember_text_cache(path, text)
            return
    except UnicodeDecodeError:
        pass
    with tempfile.NamedTemporaryFile(
        "w", encoding="utf-8", newline="", delete=False, dir=str(path.parent)
    ) as tmp:
        tmp.write(text)
        tmp_name = tmp.name
    os.replace(tmp_name, path)
    remember_text_cache(path, text)


def dryrun_artifact_path(path: Path) -> Path:
    return Path(f"{path}.dryrun")


def dryrun_config_path(path: Path) -> Path:
    return Path(f"{path}.dryrun")


def live_path_from_dryrun(path: Path) -> Path:
    raw = str(path)
    return Path(raw[:-7]) if raw.endswith(".dryrun") else path


def command_context_from_args(args) -> CommandContext:
    raw_id = getattr(args, "command_id", 0) or 0
    try:
        command_id = max(0, int(raw_id))
    except (TypeError, ValueError):
        command_id = 0
    display = getattr(args, "command_id_display", "") or ""
    if not re.fullmatch(r"\d{12}", display):
        display = f"{command_id:012d}"
    timestamp = getattr(args, "command_timestamp", "") or ""
    if command_id and not timestamp:
        timestamp = datetime.now().astimezone().isoformat(timespec="seconds")
    return CommandContext(command_id, display, timestamp)


def render_generated_markdown_header(context: CommandContext, refresh_source: str) -> list[str]:
    timestamp = context.command_timestamp or datetime.now().astimezone().isoformat(timespec="seconds")
    command_id = context.command_id_display if context.command_id else "000000000000"
    source = refresh_source or "foreground-generated-refresh"
    return [
        AUTOGEN_MARKDOWN_SENTINEL,
        f"<!-- validator-command-id: {command_id} -->",
        f"<!-- validator-refreshed-at: {timestamp} -->",
        f"<!-- validator-refresh-source: {source} -->",
    ]


def render_generated_cpp_metadata_header(context: CommandContext, refresh_source: str) -> list[str]:
    timestamp = context.command_timestamp or datetime.now().astimezone().isoformat(timespec="seconds")
    command_id = context.command_id_display if context.command_id else "000000000000"
    source = refresh_source or "foreground-generated-refresh"
    return [
        f"// validator-command-id: {command_id}",
        f"// validator-refreshed-at: {timestamp}",
        f"// validator-refresh-source: {source}",
    ]


GENERATED_METADATA_RE = re.compile(
    r"^<!-- validator-(?:command-id|refreshed-at|refresh-source): .* -->$"
)
GENERATED_CPP_METADATA_RE = re.compile(
    r"^// validator-(?:command-id|refreshed-at|refresh-source): .*$"
)


def strip_generated_markdown_metadata(text: str) -> str:
    lines = text.splitlines()
    stripped: list[str] = []
    for line in lines:
        if GENERATED_METADATA_RE.fullmatch(line):
            continue
        if line.startswith("Generated: "):
            continue
        stripped.append(line)
    suffix = "\n" if text.endswith("\n") else ""
    return "\n".join(stripped) + suffix


def generated_markdown_has_metadata(text: str) -> bool:
    return "<!-- validator-command-id:" in text and "<!-- validator-refreshed-at:" in text


def strip_generated_cpp_metadata(text: str) -> str:
    lines = text.splitlines()
    stripped: list[str] = []
    for line in lines:
        if GENERATED_CPP_METADATA_RE.fullmatch(line):
            continue
        stripped.append(line)
    suffix = "\n" if text.endswith("\n") else ""
    return "\n".join(stripped) + suffix


def generated_cpp_has_metadata(text: str) -> bool:
    return "// validator-command-id:" in text and "// validator-refreshed-at:" in text


def load_metadata_cache(root: Path) -> dict:
    global _METADATA_CACHE
    if _METADATA_CACHE is not None:
        return _METADATA_CACHE
    try:
        data = json.loads(DEFAULT_METADATA_CACHE.read_text(encoding="utf-8"))
    except (FileNotFoundError, json.JSONDecodeError, OSError):
        data = {}
    if not isinstance(data, dict):
        data = {}
    if (
        data.get("schema") != CACHE_SCHEMA
        or data.get("validator_version") != CACHE_VERSION
        or data.get("root") != str(root)
        or not isinstance(data.get("files"), dict)
    ):
        data = {
            "schema": CACHE_SCHEMA,
            "validator_version": CACHE_VERSION,
            "root": str(root),
            "files": {},
        }
    _METADATA_CACHE = data
    return _METADATA_CACHE


def save_metadata_cache(root: Path) -> None:
    global _METADATA_CACHE_DIRTY
    if not _METADATA_CACHE_DIRTY:
        return
    cache = load_metadata_cache(root)
    write_json_atomic(cache, DEFAULT_METADATA_CACHE)
    _METADATA_CACHE_DIRTY = False


def valid_cached_file_entry(root: Path, rel: str, path: Path) -> dict | None:
    cache = load_metadata_cache(root)
    entry = cache.get("files", {}).get(rel)
    if not isinstance(entry, dict):
        return None
    try:
        stat = path.stat()
    except OSError:
        return None
    if entry.get("mtime_ns") != stat.st_mtime_ns or entry.get("size") != stat.st_size:
        return None
    cached_sha256 = entry.get("sha256")
    if not isinstance(cached_sha256, str) or not cached_sha256:
        return None
    return entry


def update_metadata_cache_entry(root: Path, rel: str, path: Path, values: dict) -> None:
    global _METADATA_CACHE_DIRTY
    cache = load_metadata_cache(root)
    payload = dict(values)
    try:
        stat = path.stat()
        sha256 = payload.pop("_file_sha256", None)
        if not isinstance(sha256, str) or not sha256:
            sha256 = file_sha256(path)
    except OSError:
        cache["files"].pop(rel, None)
        _METADATA_CACHE_DIRTY = True
        return
    existing = cache["files"].get(rel)
    same_current_file = (
        isinstance(existing, dict)
        and existing.get("mtime_ns") == stat.st_mtime_ns
        and existing.get("size") == stat.st_size
        and existing.get("sha256") == sha256
    )
    entry = {
        **(existing if same_current_file else {}),
        "mtime_ns": stat.st_mtime_ns,
        "size": stat.st_size,
        "sha256": sha256,
        **payload,
    }
    if cache["files"].get(rel) != entry:
        cache["files"][rel] = entry
        _METADATA_CACHE_DIRTY = True


def relative_path(root: Path, path: Path) -> str:
    try:
        return resolved_path(path).relative_to(resolved_path(root)).as_posix()
    except ValueError:
        return resolved_path(path).as_posix()


def absolute_path(root: Path, stored_path: str) -> Path:
    path = Path(stored_path)
    if path.is_absolute():
        return path
    return root / path


def by_directories(root: Path) -> list[Path]:
    return sorted(
        path for path in root.iterdir()
        if path.is_dir() and path.name.startswith("by-")
    )


def is_under_by_directory(root: Path, path: Path) -> bool:
    try:
        relative = resolved_path(path).relative_to(resolved_path(root))
    except ValueError:
        return False
    return len(relative.parts) > 1 and relative.parts[0].startswith("by-")


def is_by_file_projected_doc(root: Path, path: Path) -> bool:
    try:
        relative = resolved_path(path).relative_to(resolved_path(root))
    except ValueError:
        return False
    return (
        len(relative.parts) == 2
        and relative.parts[0] == "by-file"
        and path.suffix.lower() == ".md"
        and not path.name.startswith("-")
    )


def project_relative_parts(root: Path, path: Path) -> tuple[str, ...] | None:
    try:
        return resolved_path(path).relative_to(resolved_path(root)).parts
    except ValueError:
        return None


def is_autogen_metadata_doc(root: Path, path: Path) -> bool:
    return is_reconstruction_metadata_doc(root, path)


def is_owner_metadata_doc(root: Path, path: Path) -> bool:
    parts = project_relative_parts(root, path)
    if parts is None:
        return False
    if len(parts) < 2:
        return False
    if not parts[0].startswith("by-"):
        return False
    if parts[0] in {"by-meta", "by-external-research", "by-project-structure"}:
        return False
    if path.suffix.lower() != ".md":
        return False
    if path.name.startswith("-"):
        return False
    return True


def is_reconstruction_metadata_doc(root: Path, path: Path) -> bool:
    parts = project_relative_parts(root, path)
    if parts is None:
        return False
    if len(parts) < 2:
        return False
    if not parts[0].startswith("by-"):
        return False
    if parts[0] in AUTOGEN_EXCLUDED_TOP_LEVEL_FOLDERS:
        return False
    if path.suffix.lower() != ".md":
        return False
    if path.name.startswith("-"):
        return False
    return True


def has_autogen_metadata_line(lines: list[str]) -> bool:
    prefixes = (
        CANONICAL_OWNER_PREFIX,
        RECONSTRUCTABLE_PREFIX,
        EMITTER_UIDS_PREFIX,
        EMITTER_POSITION_PREFIX,
        AUTOGEN_PARENT_UID_PREFIX,
        AUTOGEN_PARENT_POSITION_PREFIX,
        RECONSTRUCTION_CPP_PREFIX,
    )
    return (
        any(line.startswith(prefixes) for line in lines[:20])
        or any(line in {RECONSTRUCTION_H_BEGIN_LINE, RECONSTRUCTION_H_END_LINE} for line in lines)
    )


def has_reconstruction_metadata_line(lines: list[str]) -> bool:
    prefixes = (
        RECONSTRUCTABLE_PREFIX,
        EMITTER_UIDS_PREFIX,
        EMITTER_POSITION_PREFIX,
        AUTOGEN_PARENT_UID_PREFIX,
        AUTOGEN_PARENT_POSITION_PREFIX,
        RECONSTRUCTION_CPP_PREFIX,
    )
    return (
        any(line.startswith(prefixes) for line in lines[:20])
        or any(line in {RECONSTRUCTION_H_BEGIN_LINE, RECONSTRUCTION_H_END_LINE} for line in lines)
    )


def is_projected_path_candidate(stored_path: str) -> bool:
    normalized = stored_path.replace("\\", "/")
    parts = normalized.split("/")
    return (
        len(parts) == 2
        and parts[0] == "by-file"
        and parts[1].lower().endswith(".md")
        and not parts[1].startswith("-")
    )


def normalize_projected_path(value: str) -> str:
    return value.replace("\\", "/")


def validate_projected_path(value: str) -> tuple[str, str, str]:
    """Return normalized value, status, and error detail."""
    if value == "":
        return "", "blank", ""
    if value.strip() != value:
        return value, "invalid", "path must not have leading or trailing whitespace"
    if value.upper() == PROJECTED_PATH_NONE_VALUE:
        return PROJECTED_PATH_NONE_VALUE, "none", ""

    normalized = normalize_projected_path(value)
    if normalized != value:
        value = normalized

    if value.startswith(("/", "\\")) or re.match(r"^[A-Za-z]:", value):
        return value, "invalid", "path must be relative to the reconstructed project root"
    if PROJECTED_PATH_INVALID_CHARS_RE.search(value):
        return value, "invalid", "path contains characters that are invalid in Windows paths"
    if not value.endswith("/"):
        return value, "invalid", "path must end with / and must not include a filename"

    parts = value[:-1].split("/")
    if not parts or any(part == "" for part in parts):
        return value, "invalid", "path contains an empty folder segment"
    if any(part in {".", ".."} for part in parts):
        return value, "invalid", "path must not contain . or .. segments"
    if parts[0] != "NexusTK":
        return value, "invalid", "path must start with NexusTK/"
    if "." in parts[-1]:
        return value, "invalid", "last segment looks like a filename; provide the containing folder only"
    return value, "valid", ""


def projected_error_key(uid: str) -> str:
    return f"bad_projected_path_{uid}"


def generated_source_path(root: Path, projected_path: str, stem: str, suffix: str) -> Path:
    if suffix not in {".cpp", ".h"}:
        raise ValueError(f"unsupported generated source suffix: {suffix}")
    parts = [part for part in projected_path.strip("/").split("/") if part]
    target = root / AUTO_GENERATED_RELATIVE_PATH / Path(*parts) / f"{stem}{suffix}"
    generated_root = resolved_path(root / AUTO_GENERATED_RELATIVE_PATH)
    resolved = resolved_path(target)
    try:
        resolved.relative_to(generated_root)
    except ValueError as exc:
        raise ValueError(f"generated path escapes auto-generated root: {target}") from exc
    return target


def generated_cpp_path(root: Path, projected_path: str, stem: str) -> Path:
    return generated_source_path(root, projected_path, stem, ".cpp")


def generated_header_path(root: Path, projected_path: str, stem: str) -> Path:
    return generated_source_path(root, projected_path, stem, ".h")


def remove_empty_generated_dirs(root: Path, start: Path) -> list[Path]:
    removed: list[Path] = []
    generated_root = resolved_path(root / AUTO_GENERATED_RELATIVE_PATH)
    current = resolved_path(start)
    while current != generated_root:
        try:
            current.relative_to(generated_root)
        except ValueError:
            break
        if not current.exists() or not current.is_dir():
            current = current.parent
            continue
        try:
            next(current.iterdir())
            break
        except StopIteration:
            current.rmdir()
            removed.append(current)
            current = current.parent
    return removed


def safe_resolve(path: Path) -> Path:
    return resolved_path(path)


def docs_relative_candidate(root: Path, candidate: Path) -> str | None:
    try:
        relative = safe_resolve(candidate).relative_to(safe_resolve(root))
    except ValueError:
        return None
    if len(relative.parts) < 2 or not relative.parts[0].startswith("by-"):
        return None
    return relative.as_posix()


def project_documentation_suffix(path: Path) -> Path | None:
    parts = path.parts
    lower_parts = [part.lower() for part in parts]
    if "project-documentation" not in lower_parts:
        return None
    index = len(lower_parts) - 1 - lower_parts[::-1].index("project-documentation")
    suffix_parts = parts[index + 1 :]
    if not suffix_parts:
        return None
    return Path(*suffix_parts)


def all_markdown_files(root: Path) -> list[Path]:
    files: list[Path] = []
    for directory in by_directories(root):
        files.extend(path for path in directory.rglob("*.md") if path.is_file())
    return sorted(files)


def is_fence_line(line: str) -> bool:
    stripped = line.lstrip()
    return stripped.startswith("```") or stripped.startswith("~~~")


def find_uid_in_tree(root: Path, uid: str) -> Path | None:
    for path in all_markdown_files(root):
        try:
            if first_line_uid(read_text(path)) == uid:
                return path
        except UnicodeDecodeError:
            continue
    return None


def parse_reference_sources(value: str) -> set[str]:
    return {
        item.strip().replace("\\", "/")
        for item in value.split(";")
        if item.strip()
    }


def format_reference_sources(sources: set[str]) -> str:
    return ";".join(sorted(sources))


def collect_uid_references(text: str, parent_uid: str | None) -> set[str]:
    targets: set[str] = set()
    in_fence = False
    for line in text.splitlines(keepends=True):
        if is_fence_line(line):
            in_fence = not in_fence
            continue
        if in_fence:
            continue
        for match in UID_REF_RE.finditer(line):
            target_uid = match.group("uid")
            if target_uid != parent_uid:
                targets.add(target_uid)
    return targets


def update_reference_index_for_source(
    path: Path,
    root: Path,
    config: configparser.ConfigParser,
    text: str,
    apply: bool,
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    parent_uid = first_line_uid(text)
    source_rel = relative_path(root, path)
    target_uids = collect_uid_references(text, parent_uid)
    known_targets = {
        target_uid for target_uid in target_uids
        if target_uid in config["files"]
    }

    for target_uid in list(config["references"].keys()):
        sources = parse_reference_sources(config["references"].get(target_uid, ""))
        if source_rel not in sources:
            continue
        if target_uid in known_targets:
            continue
        sources.remove(source_rel)
        detail = "source no longer references target"
        actions.append(ScanAction("reference_index_remove", target_uid, path, detail))
        if apply:
            if sources:
                config["references"][target_uid] = format_reference_sources(sources)
            else:
                config["references"].pop(target_uid, None)

    for target_uid in sorted(known_targets):
        sources = parse_reference_sources(config["references"].get(target_uid, ""))
        if source_rel in sources:
            continue
        sources.add(source_rel)
        actions.append(ScanAction("reference_index_add", target_uid, path, source_rel))
        if apply:
            config["references"][target_uid] = format_reference_sources(sources)

    return actions


def update_reference_source_path(
    config: configparser.ConfigParser,
    old_source_path: str,
    new_source_path: str,
    current_uid: str,
    path: Path,
    apply: bool,
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    old_source_path = old_source_path.replace("\\", "/")
    new_source_path = new_source_path.replace("\\", "/")
    if old_source_path == new_source_path:
        return actions

    for target_uid in list(config["references"].keys()):
        sources = parse_reference_sources(config["references"].get(target_uid, ""))
        if old_source_path not in sources:
            continue
        sources.remove(old_source_path)
        sources.add(new_source_path)
        actions.append(
            ScanAction(
                "reference_source_path_update",
                current_uid,
                path,
                f"{old_source_path} -> {new_source_path} for target {target_uid}",
            )
        )
        if apply:
            config["references"][target_uid] = format_reference_sources(sources)
    return actions


def sync_generated_cpp(
    root: Path,
    uid: str,
    doc_path: Path,
    old_doc_rel: str | None,
    old_projected_path: str | None,
    new_projected_path: str,
    apply: bool,
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    new_cpp = generated_cpp_path(root, new_projected_path, doc_path.stem)
    new_header = generated_header_path(root, new_projected_path, doc_path.stem)
    old_cpp: Path | None = None
    old_header: Path | None = None

    if old_projected_path:
        old_normalized, old_status, _ = validate_projected_path(old_projected_path)
        if old_status == "valid":
            old_stem = Path(old_doc_rel.replace("\\", "/")).stem if old_doc_rel else doc_path.stem
            old_cpp = generated_cpp_path(root, old_normalized, old_stem)
            old_header = generated_header_path(root, old_normalized, old_stem)

    def different_spelling(old_path: Path, new_path: Path) -> bool:
        return str(old_path.absolute()) != str(new_path.absolute())

    move_pairs: list[tuple[Path, Path, str]] = []
    if old_cpp is not None and old_header is not None:
        for old_target, new_target, source_type in [
            (old_cpp, new_cpp, "cpp"),
            (old_header, new_header, "header"),
        ]:
            if old_target.exists() and different_spelling(old_target, new_target):
                move_pairs.append((old_target, new_target, source_type))

    conflicts: list[tuple[Path, Path, str, str]] = []
    for old_target, new_target, source_type in [
        (old_cpp, new_cpp, "cpp"),
        (old_header, new_header, "header"),
    ]:
        if not new_target.exists():
            continue
        if old_target is not None and path_cache_key(old_target) == path_cache_key(new_target):
            continue
        destination_uid = generated_source_uid(new_target)
        if destination_uid not in {None, uid}:
            conflicts.append((old_target or new_target, new_target, source_type, destination_uid))
    if conflicts:
        for old_target, new_target, source_type, destination_uid in conflicts:
            actions.append(
                ScanAction(
                    f"projected_{source_type}_conflict",
                    uid,
                    new_target,
                    f"destination belongs to active source UID {destination_uid}; not moving {relative_path(root, old_target)}",
                )
            )
        return actions

    moved_parents: set[Path] = set()
    for old_target, new_target, source_type in move_pairs:
        actions.append(
            ScanAction(
                f"projected_{source_type}_move",
                uid,
                new_target,
                f"from {relative_path(root, old_target)}",
            )
        )
        if apply:
            new_target.parent.mkdir(parents=True, exist_ok=True)
            moved_parents.add(old_target.parent)
            if path_cache_key(old_target) == path_cache_key(new_target):
                temporary = new_target.with_name(f".{new_target.name}.validator-case-move")
                temporary.unlink(missing_ok=True)
                old_target.replace(temporary)
                temporary.replace(new_target)
            else:
                new_target.unlink(missing_ok=True)
                old_target.replace(new_target)
    if apply:
        for old_parent in moved_parents:
            for removed in remove_empty_generated_dirs(root, old_parent):
                actions.append(ScanAction("projected_folder_remove", uid, removed, "empty generated folder"))

    if new_cpp.exists():
        return actions

    actions.append(ScanAction("projected_cpp_create", uid, new_cpp, "empty reconstructed source placeholder"))
    if apply:
        new_cpp.parent.mkdir(parents=True, exist_ok=True)
        write_text_atomic(new_cpp, "")
    return actions


def update_projected_path_tracking(
    root: Path,
    config: configparser.ConfigParser,
    uid: str,
    path: Path,
    rel: str,
    old_doc_rel: str | None,
    projected_path_value: str | None,
    apply: bool,
    sync_generated: bool = True,
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    if projected_path_value is None:
        return actions

    normalized, status, error = validate_projected_path(projected_path_value)
    old_projected = config[PROJECTED_PATH_SECTION].get(uid)
    old_status = config[PROJECTED_PATH_STATUS_SECTION].get(uid)
    value_to_store = normalized if status in {"valid", "none"} else projected_path_value

    if old_projected != value_to_store:
        detail = "blank" if value_to_store == "" else value_to_store
        if old_projected is not None:
            detail = f"{old_projected} -> {detail}"
        actions.append(ScanAction("projected_path_update", uid, path, detail))
        if apply:
            config[PROJECTED_PATH_SECTION][uid] = value_to_store

    if old_status != status:
        actions.append(ScanAction("projected_path_status", uid, path, status))
        if apply:
            config[PROJECTED_PATH_STATUS_SECTION][uid] = status

    error_key = projected_error_key(uid)
    if status == "invalid":
        detail = f"{rel}: {error}"
        actions.append(ScanAction("projected_path_invalid", uid, path, error))
        if apply:
            config[PROJECTED_PATH_ERROR_SECTION][error_key] = detail
    elif error_key in config[PROJECTED_PATH_ERROR_SECTION]:
        actions.append(ScanAction("projected_path_error_clear", uid, path, "path is no longer invalid"))
        if apply:
            config[PROJECTED_PATH_ERROR_SECTION].pop(error_key, None)

    if status == "valid" and sync_generated:
        actions.extend(sync_generated_cpp(root, uid, path, old_doc_rel, old_projected, normalized, apply))
    elif old_projected and sync_generated:
        old_normalized, old_validity, _ = validate_projected_path(old_projected)
        if old_validity == "valid":
            old_stem = Path(old_doc_rel.replace("\\", "/")).stem if old_doc_rel else path.stem
            old_target = generated_cpp_path(root, old_normalized, old_stem)
            if old_target.exists():
                actions.append(
                    ScanAction(
                        "projected_cpp_stale",
                        uid,
                        old_target,
                        "projected path no longer emits generated source; generated file not deleted",
                    )
                )

    return actions


def documented_targets(root: Path, config: configparser.ConfigParser) -> tuple[list[Path], list[ScanAction]]:
    targets: list[Path] = []
    actions: list[ScanAction] = []
    for uid, stored_path in config["files"].items():
        path = Path(stored_path)
        if not path.is_absolute():
            path = root / path
        if not is_under_by_directory(root, path):
            actions.append(ScanAction("skipped", uid, path, "outside direct by-* folders"))
            continue
        if path.exists():
            targets.append(path)
            continue
        moved = find_uid_in_tree(root, uid)
        if moved is None:
            actions.append(ScanAction("missing", uid, path, "documented path not found"))
            continue
        targets.append(moved)
    return sorted(set(targets)), actions


def reconstructable_display_value(stored: str) -> str:
    normalized = stored.strip().lower()
    if normalized == "true":
        return "TRUE"
    if normalized == "false":
        return "FALSE"
    if normalized in {"1", "0"}:
        return normalized
    return ""


def first_header_line(lines: list[str], prefix: str) -> str | None:
    for line in lines[:20]:
        if line.startswith(prefix):
            return line
    return None


def existing_reconstructable_display(lines: list[str], config: configparser.ConfigParser, uid: str) -> str:
    line = first_header_line(lines, RECONSTRUCTABLE_PREFIX)
    if line is not None:
        parsed = parse_reconstructable_line(line)
        if parsed is not None and parsed[1] != "invalid":
            return parsed[0].strip().upper()
    return reconstructable_display_value(stored_autogen_value(config, RECONSTRUCTABLE_SECTION, uid))


def existing_legacy_parent(lines: list[str], config: configparser.ConfigParser, uid: str) -> tuple[str, bool]:
    line = first_header_line(lines, AUTOGEN_PARENT_UID_PREFIX)
    if line is not None:
        parsed = parse_parent_uid_line(line)
        if parsed is None:
            return "", False
        raw, ok = parsed
        return raw, ok
    fallback = stored_autogen_value(config, AUTOGEN_PARENT_SECTION, uid).strip().upper()
    if fallback and re.fullmatch(r"[A-Z0-9]{6}", fallback) is None:
        return "", False
    return fallback, True


def existing_legacy_position(lines: list[str], config: configparser.ConfigParser, uid: str) -> str:
    line = first_header_line(lines, AUTOGEN_PARENT_POSITION_PREFIX)
    if line is not None:
        parsed = parse_parent_position_line(line)
        if parsed is not None and parsed[2]:
            return parsed[0]
        return ""
    fallback = stored_autogen_value(config, AUTOGEN_PARENT_POSITION_SECTION, uid)
    return fallback if re.fullmatch(r"[0-9]+", fallback) else ""


def by_file_default_owner(root: Path, path: Path, lines: list[str], config: configparser.ConfigParser, uid: str) -> str:
    if not is_by_file_projected_doc(root, path):
        return "NONE"
    projected = config[PROJECTED_PATH_SECTION].get(uid, "")
    line = first_header_line(lines, PROJECTED_PATH_PREFIX)
    if line is not None:
        parsed = parse_projected_path_line(line)
        if parsed is not None:
            projected = parsed
    _, status, _ = validate_projected_path(projected)
    return "FILE" if status == "valid" else "NONE"


def ensure_autogen_metadata_lines(
    lines: list[str],
    index: int,
    uid: str,
    path: Path,
    root: Path,
    config: configparser.ConfigParser,
) -> tuple[int, bool, list[ScanAction]]:
    actions: list[ScanAction] = []
    changed = False

    owner_eligible = is_owner_metadata_doc(root, path)
    reconstruction_eligible = is_reconstruction_metadata_doc(root, path)

    if not owner_eligible:
        if has_autogen_metadata_line(lines):
            actions.append(
                ScanAction(
                    "autogen_metadata_unexpected",
                    uid,
                    path,
                    "reconstruction metadata is only managed for eligible code-bearing docs",
                )
            )
        return index, changed, actions

    reconstructable_fallback = existing_reconstructable_display(lines, config, uid)
    reconstructable_state = parse_reconstructable_value(reconstructable_fallback)
    legacy_parent, legacy_parent_ok = existing_legacy_parent(lines, config, uid)
    position_fallback = existing_legacy_position(lines, config, uid)

    canonical_owner_fallback = config[CANONICAL_OWNER_SECTION].get(uid, "").strip().upper()
    if not canonical_owner_fallback:
        canonical_owner_fallback = legacy_parent if legacy_parent_ok and legacy_parent else by_file_default_owner(root, path, lines, config, uid)
    if canonical_owner_fallback == "":
        canonical_owner_fallback = "NONE"
    if not (canonical_owner_fallback in {"NONE", "FILE"} or re.fullmatch(r"[A-Z0-9]{6}", canonical_owner_fallback)):
        canonical_owner_fallback = "NONE"

    emitter_uids_fallback = config[EMITTER_UIDS_SECTION].get(uid, "").strip().upper()
    if not emitter_uids_fallback and legacy_parent_ok and legacy_parent and reconstructable_state == "true":
        emitter_uids_fallback = legacy_parent
    parsed_emitters = parse_emitter_uids_line(make_emitter_uids_line(emitter_uids_fallback))
    if parsed_emitters is None or not parsed_emitters[2] or reconstructable_state != "true":
        emitter_uids_fallback = ""

    emitter_position_fallback = config[EMITTER_POSITION_SECTION].get(uid, "").strip()
    parsed_position_fallback = parse_emitter_position_line(make_emitter_position_line(emitter_position_fallback))
    if parsed_position_fallback is None or not parsed_position_fallback[2]:
        emitter_position_fallback = position_fallback
        parsed_position_fallback = parse_emitter_position_line(make_emitter_position_line(emitter_position_fallback))
    if parsed_position_fallback is None or not parsed_position_fallback[2]:
        emitter_position_fallback = ""

    if index < len(lines) and CANONICAL_OWNER_LINE_RE.match(lines[index]):
        index += 1
    elif index < len(lines) and lines[index].startswith(CANONICAL_OWNER_PREFIX):
        lines[index] = make_canonical_owner_line(canonical_owner_fallback)
        changed = True
        actions.append(ScanAction("restore_owner_metadata", uid, path, "CANONICAL_OWNER"))
        index += 1
    else:
        lines.insert(index, make_canonical_owner_line(canonical_owner_fallback))
        changed = True
        actions.append(ScanAction("insert_owner_metadata", uid, path, "CANONICAL_OWNER"))
        index += 1

    if not reconstruction_eligible:
        if any(
            line.startswith((RECONSTRUCTABLE_PREFIX, EMITTER_UIDS_PREFIX, EMITTER_POSITION_PREFIX, AUTOGEN_PARENT_UID_PREFIX, AUTOGEN_PARENT_POSITION_PREFIX, RECONSTRUCTION_CPP_PREFIX, RECONSTRUCTION_H_PREFIX))
            for line in lines[index:index + 8]
        ):
            actions.append(
                ScanAction(
                    "autogen_metadata_unexpected",
                    uid,
                    path,
                    "reconstruction metadata is only managed for eligible code-bearing docs",
                )
            )
        return index, changed, actions

    if index < len(lines) and RECONSTRUCTABLE_LINE_RE.match(lines[index]):
        index += 1
    elif index < len(lines) and lines[index].startswith(RECONSTRUCTABLE_PREFIX):
        lines[index] = make_reconstructable_line(reconstructable_fallback)
        changed = True
        actions.append(ScanAction("restore_autogen_metadata", uid, path, "RECONSTRUCTABLE"))
        index += 1
    else:
        lines.insert(index, make_reconstructable_line(reconstructable_fallback))
        changed = True
        actions.append(ScanAction("insert_autogen_metadata", uid, path, "RECONSTRUCTABLE"))
        index += 1

    if index < len(lines) and EMITTER_UIDS_LINE_RE.match(lines[index]):
        index += 1
    elif index < len(lines) and lines[index].startswith((EMITTER_UIDS_PREFIX, AUTOGEN_PARENT_UID_PREFIX)):
        lines[index] = make_emitter_uids_line(emitter_uids_fallback)
        changed = True
        actions.append(ScanAction("restore_autogen_metadata", uid, path, "EMITTER_UIDS"))
        index += 1
    else:
        lines.insert(index, make_emitter_uids_line(emitter_uids_fallback))
        changed = True
        actions.append(ScanAction("insert_autogen_metadata", uid, path, "EMITTER_UIDS"))
        index += 1

    if index < len(lines) and EMITTER_POSITION_LINE_RE.match(lines[index]):
        index += 1
    elif index < len(lines) and lines[index].startswith((EMITTER_POSITION_PREFIX, AUTOGEN_PARENT_POSITION_PREFIX)):
        lines[index] = make_emitter_position_line(emitter_position_fallback)
        changed = True
        actions.append(
            ScanAction("restore_autogen_metadata", uid, path, "EMITTER_POSITION_OPTIONAL")
        )
        index += 1
    else:
        lines.insert(index, make_emitter_position_line(emitter_position_fallback))
        changed = True
        actions.append(
            ScanAction("insert_autogen_metadata", uid, path, "EMITTER_POSITION_OPTIONAL")
        )
        index += 1

    if index < len(lines) and RECONSTRUCTION_CPP_LINE_RE.match(lines[index]):
        index += 1
    elif index < len(lines) and lines[index].startswith(RECONSTRUCTION_CPP_PREFIX):
        lines[index] = make_reconstruction_cpp_line("")
        changed = True
        actions.append(ScanAction("restore_autogen_metadata", uid, path, "RECONSTRUCTION_CPP CODE"))
        index += 1
    else:
        lines.insert(index, make_reconstruction_cpp_line(""))
        changed = True
        actions.append(ScanAction("insert_autogen_metadata", uid, path, "RECONSTRUCTION_CPP CODE"))
        index += 1

    if index < len(lines) and lines[index] == RECONSTRUCTION_CPP_BEGIN_LINE:
        end_index = index + 1
        while end_index < len(lines) and lines[end_index] != RECONSTRUCTION_CPP_END_LINE:
            end_index += 1
        if end_index < len(lines):
            index = end_index + 1
        else:
            actions.append(ScanAction("autogen_code_block_unclosed", uid, path, "BEGIN without END"))
            lines.insert(index + 1, RECONSTRUCTION_CPP_END_LINE)
            changed = True
            index += 2
    elif index < len(lines) and lines[index].startswith(RECONSTRUCTION_CPP_PREFIX):
        lines[index] = RECONSTRUCTION_CPP_BEGIN_LINE
        lines.insert(index + 1, RECONSTRUCTION_CPP_END_LINE)
        changed = True
        actions.append(ScanAction("restore_autogen_metadata", uid, path, "RECONSTRUCTION_CPP CODE block"))
        index += 2
    else:
        lines.insert(index, RECONSTRUCTION_CPP_BEGIN_LINE)
        lines.insert(index + 1, RECONSTRUCTION_CPP_END_LINE)
        changed = True
        actions.append(ScanAction("insert_autogen_metadata", uid, path, "RECONSTRUCTION_CPP CODE block"))
        index += 2

    header_begin_indexes = [
        line_index for line_index, line in enumerate(lines)
        if line == RECONSTRUCTION_H_BEGIN_LINE
    ]
    header_end_indexes = [
        line_index for line_index, line in enumerate(lines)
        if line == RECONSTRUCTION_H_END_LINE
    ]
    header_prefixed_indexes = [
        line_index for line_index, line in enumerate(lines)
        if line.startswith(RECONSTRUCTION_H_PREFIX)
    ]
    if not header_prefixed_indexes:
        lines.insert(index, RECONSTRUCTION_H_BEGIN_LINE)
        lines.insert(index + 1, RECONSTRUCTION_H_END_LINE)
        changed = True
        actions.append(ScanAction("reconstruction_h_insert", uid, path, "empty RECONSTRUCTION_H CODE block"))
        index += 2
    elif (
        len(header_begin_indexes) == 1
        and len(header_end_indexes) == 1
        and len(header_prefixed_indexes) == 2
        and header_begin_indexes[0] == index
        and header_begin_indexes[0] < header_end_indexes[0]
    ):
        index = header_end_indexes[0] + 1
    else:
        actions.append(
            ScanAction(
                "reconstruction_h_invalid",
                uid,
                path,
                "expected one exact BEGIN/END block immediately after RECONSTRUCTION_CPP CODE",
            )
        )

    return index, changed, actions


def ensure_metadata_header(
    text: str,
    uid: str,
    path: Path,
    root: Path,
    config: configparser.ConfigParser,
    uid_status: str,
) -> tuple[str, int | None, int | None, str | None, list[ScanAction]]:
    actions: list[ScanAction] = []
    newline = detect_newline(text)
    rel = relative_path(root, path)
    completion_fallback, completion_source = stored_score_or_default(config, "completion", uid, rel)
    confidence_fallback, confidence_source = stored_score_or_default(config, "confidence", uid, rel)

    lines = text.splitlines()
    original_had_final_newline = text.endswith(("\n", "\r"))
    changed = False

    if uid_status in {"insert_missing", "restore_missing"}:
        lines.insert(0, make_uid_line(uid))
        changed = True
        action = "insert_uid" if uid_status == "insert_missing" else "restore_uid"
        detail = "missing first-line UID" if uid_status == "insert_missing" else "restored from validator.ini path mapping"
        actions.append(ScanAction(action, uid, path, detail))
    elif uid_status in {"replace_damaged", "restore_damaged"}:
        if lines:
            lines[0] = make_uid_line(uid)
        else:
            lines.insert(0, make_uid_line(uid))
        changed = True
        action = "replace_damaged_uid" if uid_status == "replace_damaged" else "restore_uid"
        detail = "replaced damaged UID header" if uid_status == "replace_damaged" else "restored from validator.ini path mapping"
        actions.append(ScanAction(action, uid, path, detail))

    index = 1
    completion: int | None = None
    confidence: int | None = None
    projected_path_value: str | None = None

    if index < len(lines) and COMPLETION_LINE_RE.match(lines[index]):
        completion = parse_completion_line(lines[index])
        if completion is None:
            lines[index] = make_completion_line(completion_fallback)
            completion = completion_fallback
            changed = True
            actions.append(
                ScanAction("restore_completion", uid, path, f"{completion_source} {completion_fallback}")
            )
        index += 1
    elif index < len(lines) and lines[index].startswith("*** COMPLETION:"):
        lines[index] = make_completion_line(completion_fallback)
        completion = completion_fallback
        changed = True
        actions.append(
            ScanAction("restore_completion", uid, path, f"{completion_source} {completion_fallback}")
        )
        index += 1
    else:
        lines.insert(index, make_completion_line(completion_fallback))
        completion = completion_fallback
        changed = True
        actions.append(
            ScanAction("insert_completion", uid, path, f"{completion_source} {completion_fallback}")
        )
        index += 1

    if index < len(lines) and CONFIDENCE_LINE_RE.match(lines[index]):
        confidence = parse_confidence_line(lines[index])
        if confidence is None:
            lines[index] = make_confidence_line(confidence_fallback)
            confidence = confidence_fallback
            changed = True
            actions.append(
                ScanAction("restore_confidence", uid, path, f"{confidence_source} {confidence_fallback}")
            )
        index += 1
    elif index < len(lines) and lines[index].startswith("*** CONFIDENCE:"):
        lines[index] = make_confidence_line(confidence_fallback)
        confidence = confidence_fallback
        changed = True
        actions.append(
            ScanAction("restore_confidence", uid, path, f"{confidence_source} {confidence_fallback}")
        )
        index += 1
    else:
        lines.insert(index, make_confidence_line(confidence_fallback))
        confidence = confidence_fallback
        changed = True
        actions.append(
            ScanAction("insert_confidence", uid, path, f"{confidence_source} {confidence_fallback}")
        )
        index += 1

    if is_by_file_projected_doc(root, path):
        projected_fallback = config[PROJECTED_PATH_SECTION].get(uid, "")
        if index < len(lines) and PROJECTED_PATH_LINE_RE.match(lines[index]):
            projected_path_value = parse_projected_path_line(lines[index])
            assert projected_path_value is not None
            normalized, status, _ = validate_projected_path(projected_path_value)
            if status == "valid" and normalized != projected_path_value:
                lines[index] = make_projected_path_line(normalized)
                projected_path_value = normalized
                changed = True
                actions.append(ScanAction("normalize_projected_path", uid, path, normalized))
            index += 1
        elif index < len(lines) and lines[index].startswith(PROJECTED_PATH_PREFIX):
            lines[index] = make_projected_path_line(projected_fallback)
            projected_path_value = projected_fallback
            changed = True
            actions.append(ScanAction("restore_projected_path", uid, path, "stored value or blank"))
            index += 1
        else:
            lines.insert(index, make_projected_path_line(projected_fallback))
            projected_path_value = projected_fallback
            changed = True
            actions.append(ScanAction("insert_projected_path", uid, path, "by-file reconstruction path"))
            index += 1
    elif index < len(lines) and lines[index].startswith(PROJECTED_PATH_PREFIX):
        actions.append(
            ScanAction(
                "projected_path_unexpected",
                uid,
                path,
                "line is only managed for singular by-file pages",
            )
        )
        index += 1

    index, autogen_changed, autogen_actions = ensure_autogen_metadata_lines(
        lines,
        index,
        uid,
        path,
        root,
        config,
    )
    changed = changed or autogen_changed
    actions.extend(autogen_actions)

    if any(action.action == "reconstruction_h_invalid" for action in autogen_actions):
        return text, completion, confidence, projected_path_value, actions

    next_is_memory_metadata = (
        index < len(lines)
        and (
            ITEM_SUMMARY_ANY_LINE_RE.match(lines[index]) is not None
            or NESTED_ANY_LINE_RE.match(lines[index]) is not None
        )
    )
    if not next_is_memory_metadata and (index >= len(lines) or lines[index].strip() != ""):
        lines.insert(index, "")
        changed = True
        actions.append(ScanAction("insert_header_blank", uid, path, "after metadata header"))

    if not changed:
        return text, completion, confidence, projected_path_value, actions

    new_text = newline.join(lines)
    if original_had_final_newline:
        new_text += newline
    return new_text, completion, confidence, projected_path_value, actions


def extract_reconstruction_code(lines: list[str]) -> tuple[str, str, tuple[str, ...], list[str]]:
    errors: list[str] = []
    begin_indexes = [index for index, line in enumerate(lines) if line == RECONSTRUCTION_CPP_BEGIN_LINE]
    end_indexes = [index for index, line in enumerate(lines) if line == RECONSTRUCTION_CPP_END_LINE]

    inline_values = [
        value for value in (parse_reconstruction_cpp_line(line) for line in lines[:20])
        if value is not None
    ]
    inline_value = inline_values[0].strip() if inline_values else ""
    if inline_value and "]]]" in inline_value:
        errors.append("autogen_inline_invalid: inline value contains ]]]")
    import_paths: tuple[str, ...] = ()
    import_parse = parse_reconstruction_import_directive(inline_value) if inline_value else None
    if import_parse is not None:
        import_paths, import_errors = import_parse
        errors.extend(import_errors)

    block_code = ""
    block_valid = False
    if begin_indexes or end_indexes:
        if len(begin_indexes) != 1 or len(end_indexes) != 1:
            if not begin_indexes:
                errors.append("autogen_code_block_unmatched: END without BEGIN")
            elif not end_indexes:
                errors.append("autogen_code_block_unclosed: BEGIN without END")
            else:
                errors.append("autogen_code_block_multiple: more than one BEGIN/END block")
        elif begin_indexes[0] > end_indexes[0]:
            errors.append("autogen_code_block_unmatched: END before BEGIN")
        else:
            block_valid = True
            block_lines = lines[begin_indexes[0] + 1 : end_indexes[0]]
            block_code = "\n".join(block_lines).strip("\n")

    if inline_value and block_valid and block_code.strip():
        errors.append("autogen_inline_ignored: nonblank block takes precedence over inline value")

    if block_valid and block_code.strip():
        return block_code, "block", (), errors
    if import_parse is not None:
        return inline_value, "import", import_paths, errors
    if inline_value:
        return inline_value, "inline", (), errors
    if errors:
        return "", "invalid", (), errors
    return "", "blank", (), errors


def extract_reconstruction_header_code(lines: list[str]) -> tuple[str, str, list[str]]:
    errors: list[str] = []
    begin_indexes = [index for index, line in enumerate(lines) if line == RECONSTRUCTION_H_BEGIN_LINE]
    end_indexes = [index for index, line in enumerate(lines) if line == RECONSTRUCTION_H_END_LINE]
    prefixed_indexes = [index for index, line in enumerate(lines) if line.startswith(RECONSTRUCTION_H_PREFIX)]

    if not prefixed_indexes:
        return "", "blank", errors
    if len(prefixed_indexes) != len(begin_indexes) + len(end_indexes):
        errors.append("autogen_header_code_block_malformed: H marker does not match the exact managed form")
    if len(begin_indexes) != 1 or len(end_indexes) != 1:
        if not begin_indexes:
            errors.append("autogen_header_code_block_unmatched: END without BEGIN")
        elif not end_indexes:
            errors.append("autogen_header_code_block_unclosed: BEGIN without END")
        else:
            errors.append("autogen_header_code_block_multiple: more than one BEGIN/END block")
        return "", "invalid", errors
    if begin_indexes[0] > end_indexes[0]:
        errors.append("autogen_header_code_block_unmatched: END before BEGIN")
        return "", "invalid", errors
    if errors:
        return "", "invalid", errors

    block_lines = lines[begin_indexes[0] + 1 : end_indexes[0]]
    block_code = "\n".join(block_lines).strip("\n")
    if not block_code.strip():
        return "", "blank", errors
    return block_code, "block", errors


def parse_autogen_metadata(
    root: Path,
    path: Path,
    text: str,
) -> tuple[AutogenMetadata | None, list[ScanAction]]:
    actions: list[ScanAction] = []
    uid = first_line_uid(text)
    if uid is None:
        return None, actions

    rel = relative_path(root, path)
    folder = first_folder_from_relative(rel)
    eligible = is_autogen_metadata_doc(root, path)
    lines = text.splitlines()
    if not eligible:
        if has_reconstruction_metadata_line(lines):
            actions.append(
                ScanAction(
                    "autogen_metadata_unexpected",
                    uid,
                    path,
                    "reconstruction metadata is only managed for eligible code-bearing docs",
                )
            )
        return None, actions

    errors: list[str] = []
    reconstructable = "blank"
    canonical_owner = "NONE"
    canonical_owner_raw = ""
    canonical_owner_seen = False
    emitter_uids: list[str] = []
    emitter_uids_raw = ""
    emitter_uids_seen = False
    emitter_position_raw = ""
    emitter_positions: list[int | None] = []
    emitter_position: int | None = None
    parent_uid = ""
    position_raw = ""
    position: int | None = None

    for line in lines[:20]:
        if line.startswith(CANONICAL_OWNER_PREFIX):
            parsed_owner = parse_canonical_owner_line(line)
            canonical_owner_seen = True
            if parsed_owner is None:
                errors.append("canonical_owner_invalid: malformed CANONICAL_OWNER line")
            else:
                canonical_owner_raw, owner_ok = parsed_owner
                canonical_owner = canonical_owner_raw or "NONE"
                if not owner_ok:
                    errors.append(f"canonical_owner_invalid: invalid CANONICAL_OWNER value {canonical_owner!r}")
        elif line.startswith(RECONSTRUCTABLE_PREFIX):
            parsed_reconstructable = parse_reconstructable_line(line)
            if parsed_reconstructable is None:
                errors.append("autogen_value_invalid: malformed RECONSTRUCTABLE line")
            else:
                raw, reconstructable = parsed_reconstructable
                if reconstructable == "invalid":
                    errors.append(f"autogen_value_invalid: invalid RECONSTRUCTABLE value {raw!r}")
        elif line.startswith(EMITTER_UIDS_PREFIX):
            parsed_emitters = parse_emitter_uids_line(line)
            emitter_uids_seen = True
            if parsed_emitters is None:
                errors.append("emitter_uids_invalid: malformed EMITTER_UIDS line")
            else:
                emitter_uids_raw, emitter_uids, emitters_ok = parsed_emitters
                if not emitters_ok:
                    errors.append(f"emitter_uids_invalid: invalid EMITTER_UIDS value {emitter_uids_raw!r}")
                if len(emitter_uids) != len(set(emitter_uids)):
                    errors.append("emitter_duplicate: duplicate UID in EMITTER_UIDS")
        elif line.startswith(EMITTER_POSITION_PREFIX):
            parsed_emitter_position = parse_emitter_position_line(line)
            if parsed_emitter_position is None:
                errors.append("autogen_value_invalid: malformed EMITTER_POSITION_OPTIONAL line")
            else:
                emitter_position_raw, emitter_positions, emitter_position_ok = parsed_emitter_position
                emitter_position = emitter_positions[0] if emitter_positions else None
                if not emitter_position_ok:
                    errors.append(
                        f"autogen_value_invalid: invalid EMITTER_POSITION_OPTIONAL value {emitter_position_raw!r}"
                    )
        elif line.startswith(AUTOGEN_PARENT_UID_PREFIX):
            parsed_parent = parse_parent_uid_line(line)
            if parsed_parent is None:
                errors.append("autogen_value_invalid: malformed AUTOGEN_PARENT_UID line")
            else:
                parent_uid, parent_ok = parsed_parent
                if not parent_ok:
                    errors.append(f"autogen_value_invalid: invalid AUTOGEN_PARENT_UID value {parent_uid!r}")
        elif line.startswith(AUTOGEN_PARENT_POSITION_PREFIX):
            parsed_position = parse_parent_position_line(line)
            if parsed_position is None:
                errors.append("autogen_value_invalid: malformed AUTOGEN_PARENT_POSITION_OPTIONAL line")
            else:
                position_raw, position, position_ok = parsed_position
                if not position_ok:
                    errors.append(
                        f"autogen_value_invalid: invalid AUTOGEN_PARENT_POSITION_OPTIONAL value {position_raw!r}"
                    )

    if not canonical_owner_seen:
        canonical_owner = parent_uid if parent_uid else "NONE"
        canonical_owner_raw = ""
    if not emitter_uids_seen and parent_uid and reconstructable == "true":
        emitter_uids = [parent_uid]
        emitter_uids_raw = parent_uid
    if emitter_position_raw == "":
        emitter_position_raw = position_raw
        emitter_positions = [position] if position is not None else []
        emitter_position = position

    code, mode, import_paths, code_errors = extract_reconstruction_code(lines)
    errors.extend(code_errors)
    code_hash_input = code
    if mode == "import" and not any(
        error.startswith(("import_from_invalid", "import_from_duplicate"))
        for error in code_errors
    ):
        code_hash_input, import_hash_errors = reconstruction_import_hash_input(root, code, import_paths)
        errors.extend(import_hash_errors)
    if MALFORMED_CHILDREN_MARKER in code:
        errors.append("autogen_children_marker_malformed: use [[CHILDREN]]")
    if code.count(CHILDREN_MARKER) > 1:
        errors.append("autogen_children_marker_multiple: only one [[CHILDREN]] marker is supported")
    header_code, header_mode, header_errors = extract_reconstruction_header_code(lines)
    errors.extend(header_errors)
    if any(line == RECONSTRUCTION_H_BEGIN_LINE for line in lines):
        cpp_end_indexes = [index for index, line in enumerate(lines) if line == RECONSTRUCTION_CPP_END_LINE]
        header_begin_index = next(
            (index for index, line in enumerate(lines) if line == RECONSTRUCTION_H_BEGIN_LINE),
            None,
        )
        if len(cpp_end_indexes) != 1 or header_begin_index != cpp_end_indexes[0] + 1:
            errors.append(
                "autogen_header_code_block_position: H block must immediately follow RECONSTRUCTION_CPP CODE"
            )
    if MALFORMED_CHILDREN_MARKER in header_code:
        errors.append("autogen_header_children_marker_malformed: use [[CHILDREN]]")
    if header_code.count(CHILDREN_MARKER) > 1:
        errors.append("autogen_header_children_marker_multiple: only one [[CHILDREN]] marker is supported")

    return (
        AutogenMetadata(
            uid=uid,
            path=rel,
            folder=folder,
            eligible=True,
            reconstructable=reconstructable,
            canonical_owner=canonical_owner,
            canonical_owner_raw=canonical_owner_raw,
            canonical_owner_seen=canonical_owner_seen,
            emitter_uids=emitter_uids,
            emitter_uids_raw=emitter_uids_raw,
            emitter_positions=emitter_positions,
            emitter_position=emitter_position,
            emitter_position_raw=emitter_position_raw,
            parent_uid=parent_uid,
            parent_position=position,
            parent_position_raw=position_raw,
            code=code,
            code_mode=mode,
            code_hash=code_hash(code_hash_input),
            import_paths=import_paths,
            header_code=header_code,
            header_code_mode=header_mode,
            header_code_hash=code_hash(header_code),
            errors=errors,
        ),
        actions,
    )


def autogen_metadata_to_cache(metadata: AutogenMetadata | None) -> dict | None:
    if metadata is None:
        return None
    return {
        "uid": metadata.uid,
        "path": metadata.path,
        "folder": metadata.folder,
        "eligible": metadata.eligible,
        "reconstructable": metadata.reconstructable,
        "canonical_owner": metadata.canonical_owner,
        "canonical_owner_raw": metadata.canonical_owner_raw,
        "canonical_owner_seen": metadata.canonical_owner_seen,
        "emitter_uids": list(metadata.emitter_uids),
        "emitter_uids_raw": metadata.emitter_uids_raw,
        "emitter_positions": list(metadata.emitter_positions),
        "emitter_position": metadata.emitter_position,
        "emitter_position_raw": metadata.emitter_position_raw,
        "parent_uid": metadata.parent_uid,
        "parent_position": metadata.parent_position,
        "parent_position_raw": metadata.parent_position_raw,
        "code": metadata.code,
        "code_mode": metadata.code_mode,
        "code_hash": metadata.code_hash,
        "import_paths": list(metadata.import_paths),
        "header_code": metadata.header_code,
        "header_code_mode": metadata.header_code_mode,
        "header_code_hash": metadata.header_code_hash,
        "errors": list(metadata.errors or []),
    }


def optional_int_from_cache(value) -> int | None:
    if value is None:
        return None
    try:
        return int(value)
    except (TypeError, ValueError):
        return None


def optional_int_list_from_cache(value) -> list[int | None]:
    if not isinstance(value, list):
        return []
    return [optional_int_from_cache(item) for item in value]


def autogen_metadata_from_cache(data) -> AutogenMetadata | None:
    if not isinstance(data, dict):
        return None
    uid = str(data.get("uid", "")).strip().upper()
    path = str(data.get("path", ""))
    folder = str(data.get("folder", ""))
    if not re.fullmatch(r"[A-Z0-9]{6}", uid) or not path:
        return None
    emitter_uids = [
        str(item).strip().upper()
        for item in data.get("emitter_uids", [])
        if isinstance(item, str) and re.fullmatch(r"[A-Z0-9]{6}", item.strip().upper())
    ]
    errors = data.get("errors", [])
    import_paths = tuple(
        str(item)
        for item in data.get("import_paths", [])
        if isinstance(item, str)
    )
    return AutogenMetadata(
        uid=uid,
        path=path,
        folder=folder or first_folder_from_relative(path),
        eligible=bool(data.get("eligible", True)),
        reconstructable=str(data.get("reconstructable", "blank")),
        canonical_owner=str(data.get("canonical_owner", "NONE")),
        canonical_owner_raw=str(data.get("canonical_owner_raw", "")),
        canonical_owner_seen=bool(data.get("canonical_owner_seen", False)),
        emitter_uids=emitter_uids,
        emitter_uids_raw=str(data.get("emitter_uids_raw", "")),
        emitter_positions=optional_int_list_from_cache(data.get("emitter_positions", [])),
        emitter_position=optional_int_from_cache(data.get("emitter_position")),
        emitter_position_raw=str(data.get("emitter_position_raw", "")),
        parent_uid=str(data.get("parent_uid", "")),
        parent_position=optional_int_from_cache(data.get("parent_position")),
        parent_position_raw=str(data.get("parent_position_raw", "")),
        code=str(data.get("code", "")),
        code_mode=str(data.get("code_mode", "blank")),
        code_hash=str(data.get("code_hash", "")),
        import_paths=import_paths,
        header_code=str(data.get("header_code", "")),
        header_code_mode=str(data.get("header_code_mode", "blank")),
        header_code_hash=str(data.get("header_code_hash", "")),
        errors=[str(item) for item in errors] if isinstance(errors, list) else [],
    )


def scan_actions_to_cache(root: Path, actions: list[ScanAction] | tuple[ScanAction, ...]) -> list[dict]:
    cached: list[dict] = []
    for action in actions:
        cached.append(
            {
                "action": action.action,
                "uid": action.uid,
                "path": relative_path(root, action.path),
                "detail": action.detail,
            }
        )
    return cached


def scan_actions_from_cache(root: Path, data) -> list[ScanAction]:
    if not isinstance(data, list):
        return []
    actions: list[ScanAction] = []
    for item in data:
        if not isinstance(item, dict):
            continue
        action = str(item.get("action", ""))
        if not action:
            continue
        uid = item.get("uid")
        uid_value = str(uid) if uid else None
        path_value = str(item.get("path", ""))
        actions.append(
            ScanAction(
                action,
                uid_value,
                absolute_path(root, path_value) if path_value else root,
                str(item.get("detail", "")),
            )
        )
    return actions


def parse_canonical_owner_metadata(
    root: Path,
    path: Path,
    text: str,
) -> tuple[str | None, list[ScanAction]]:
    actions: list[ScanAction] = []
    uid = first_line_uid(text)
    if uid is None or not is_owner_metadata_doc(root, path):
        return None, actions

    for line in text.splitlines()[:20]:
        if not line.startswith(CANONICAL_OWNER_PREFIX):
            continue
        parsed = parse_canonical_owner_line(line)
        if parsed is None:
            actions.append(ScanAction("canonical_owner_invalid", uid, path, "malformed CANONICAL_OWNER line"))
            return "NONE", actions
        owner, ok = parsed
        owner = owner or "NONE"
        if not ok:
            actions.append(
                ScanAction("canonical_owner_invalid", uid, path, f"invalid CANONICAL_OWNER value {owner!r}")
            )
        return owner, actions

    return "NONE", actions


def autogen_error_key(uid: str) -> str:
    return f"bad_autogen_{uid}"


def set_config_value_action(
    config: configparser.ConfigParser,
    section: str,
    uid: str,
    value: str,
    path: Path,
    action_name: str,
    apply: bool,
) -> list[ScanAction]:
    old_value = config[section].get(uid)
    if old_value == value:
        return []
    detail = value if old_value is None else f"{old_value} -> {value}"
    actions = [ScanAction(action_name, uid, path, detail)]
    if apply:
        config[section][uid] = value
    return actions


def remove_uid_from_children(config: configparser.ConfigParser, uid: str, apply: bool) -> list[str]:
    changed_parents: list[str] = []
    for parent_uid in list(config[AUTOGEN_CHILDREN_SECTION].keys()):
        original = parse_reference_sources(config[AUTOGEN_CHILDREN_SECTION].get(parent_uid, ""))
        if uid not in original:
            continue
        children = sorted(item for item in original if item != uid)
        changed_parents.append(parent_uid)
        if apply:
            if children:
                config[AUTOGEN_CHILDREN_SECTION][parent_uid] = format_reference_sources(set(children))
            else:
                config[AUTOGEN_CHILDREN_SECTION].pop(parent_uid, None)
    return changed_parents


def remove_autogen_uid(config: configparser.ConfigParser, uid: str, apply: bool) -> None:
    for section in [
        RECONSTRUCTABLE_SECTION,
        AUTOGEN_PARENT_SECTION,
        AUTOGEN_PARENT_POSITION_SECTION,
        CANONICAL_OWNER_SECTION,
        EMITTER_UIDS_SECTION,
        EMITTER_POSITION_SECTION,
        RECONSTRUCTION_CODE_HASH_SECTION,
        RECONSTRUCTION_CODE_MODE_SECTION,
        RECONSTRUCTION_H_CODE_HASH_SECTION,
        RECONSTRUCTION_H_CODE_MODE_SECTION,
        AUTOGEN_ROOT_SECTION,
        AUTOGEN_ROOTS_SECTION,
        AUTOGEN_DEAD_END_SECTION,
        AUTOGEN_STATUS_SECTION,
    ]:
        if apply:
            config[section].pop(uid, None)
    if apply:
        config[AUTOGEN_CHILDREN_SECTION].pop(uid, None)
        config[AUTOGEN_ERROR_SECTION].pop(autogen_error_key(uid), None)
    remove_uid_from_children(config, uid, apply)
    if apply:
        for child_uid, root_uid in list(config[AUTOGEN_ROOT_SECTION].items()):
            if root_uid == uid:
                config[AUTOGEN_ROOT_SECTION].pop(child_uid, None)


def update_autogen_registry_for_metadata(
    root: Path,
    config: configparser.ConfigParser,
    metadata: AutogenMetadata | None,
    path: Path,
    apply: bool,
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    if metadata is None:
        return actions

    uid = metadata.uid
    actions.extend(
        set_config_value_action(
            config,
            RECONSTRUCTABLE_SECTION,
            uid,
            metadata.reconstructable,
            path,
            "autogen_registry_update",
            apply,
        )
    )
    actions.extend(
        set_config_value_action(
            config,
            CANONICAL_OWNER_SECTION,
            uid,
            metadata.canonical_owner,
            path,
            "autogen_registry_update",
            apply,
        )
    )
    actions.extend(
        set_config_value_action(
            config,
            EMITTER_UIDS_SECTION,
            uid,
            ",".join(metadata.emitter_uids),
            path,
            "autogen_registry_update",
            apply,
        )
    )
    actions.extend(
        set_config_value_action(
            config,
            EMITTER_POSITION_SECTION,
            uid,
            metadata.emitter_position_raw,
            path,
            "autogen_registry_update",
            apply,
        )
    )
    actions.extend(
        set_config_value_action(
            config,
            RECONSTRUCTION_CODE_HASH_SECTION,
            uid,
            metadata.code_hash,
            path,
            "autogen_registry_update",
            apply,
        )
    )
    actions.extend(
        set_config_value_action(
            config,
            RECONSTRUCTION_CODE_MODE_SECTION,
            uid,
            metadata.code_mode,
            path,
            "autogen_registry_update",
            apply,
        )
    )
    actions.extend(
        set_config_value_action(
            config,
            RECONSTRUCTION_H_CODE_HASH_SECTION,
            uid,
            metadata.header_code_hash,
            path,
            "autogen_registry_update",
            apply,
        )
    )
    actions.extend(
        set_config_value_action(
            config,
            RECONSTRUCTION_H_CODE_MODE_SECTION,
            uid,
            metadata.header_code_mode,
            path,
            "autogen_registry_update",
            apply,
        )
    )

    error_key = autogen_error_key(uid)
    line_errors = metadata.errors or []
    if metadata.canonical_owner == "FILE" and not is_by_file_projected_doc(root, path):
        line_errors.append("canonical_owner_file_invalid: FILE used outside singular by-file")
    elif (
        metadata.canonical_owner not in {"", "NONE", "FILE"}
        and metadata.canonical_owner not in config["files"]
    ):
        line_errors.append("canonical_owner_unknown: owner UID is not in validator.ini")
    if metadata.reconstructable == "true" and not metadata.emitter_uids and metadata.code.strip():
        line_errors.append("emitter_code_without_route: RECONSTRUCTION_CPP CODE requires EMITTER_UIDS")
    if metadata.reconstructable == "true" and not metadata.emitter_uids and metadata.header_code.strip():
        line_errors.append("emitter_header_without_route: RECONSTRUCTION_H CODE requires EMITTER_UIDS")
    if metadata.reconstructable in {"blank", "false"} and (
        metadata.emitter_uids or metadata.code.strip() or metadata.header_code.strip()
    ):
        line_errors.append("emitter_inactive_has_data: nonblank emitters/code present while not reconstructable")
    for emitter_uid in metadata.emitter_uids:
        if emitter_uid not in config["files"]:
            line_errors.append(f"emitter_uid_unknown: emitter UID {emitter_uid} is not in validator.ini")
    if len(metadata.emitter_uids) != len(set(metadata.emitter_uids)):
        line_errors.append("emitter_duplicate: duplicate UID in EMITTER_UIDS")
    if len(metadata.emitter_positions) > 1 and len(metadata.emitter_positions) > len(metadata.emitter_uids):
        line_errors.append("emitter_position_extra: more EMITTER_POSITION_OPTIONAL values than EMITTER_UIDS")

    if line_errors:
        detail = f"{metadata.path}: {'; '.join(line_errors)}"
        actions.append(ScanAction("autogen_value_invalid", uid, path, "; ".join(line_errors)))
        if apply:
            config[AUTOGEN_ERROR_SECTION][error_key] = detail
    elif error_key in config[AUTOGEN_ERROR_SECTION]:
        actions.append(ScanAction("autogen_error_clear", uid, path, "autogen metadata is now valid"))
        if apply:
            config[AUTOGEN_ERROR_SECTION].pop(error_key, None)

    return actions


def update_canonical_owner_registry(
    root: Path,
    config: configparser.ConfigParser,
    uid: str,
    path: Path,
    owner: str | None,
    apply: bool,
) -> list[ScanAction]:
    if owner is None:
        return []

    actions = set_config_value_action(
        config,
        CANONICAL_OWNER_SECTION,
        uid,
        owner,
        path,
        "canonical_owner_update",
        apply,
    )

    owner_errors: list[str] = []
    if owner == "FILE" and not is_by_file_projected_doc(root, path):
        owner_errors.append("canonical_owner_file_invalid: FILE used outside singular by-file")
    elif owner not in {"", "NONE", "FILE"} and owner not in config["files"]:
        owner_errors.append("canonical_owner_unknown: owner UID is not in validator.ini")

    error_key = autogen_error_key(uid)
    if owner_errors:
        detail = f"{relative_path(root, path)}: {'; '.join(owner_errors)}"
        actions.append(ScanAction("canonical_owner_invalid", uid, path, "; ".join(owner_errors)))
        if apply:
            config[AUTOGEN_ERROR_SECTION][error_key] = detail
    elif error_key in config[AUTOGEN_ERROR_SECTION] and not is_reconstruction_metadata_doc(root, path):
        actions.append(ScanAction("canonical_owner_error_clear", uid, path, "canonical owner is now valid"))
        if apply:
            config[AUTOGEN_ERROR_SECTION].pop(error_key, None)

    return actions


def scan_file(
    path: Path,
    root: Path,
    config: configparser.ConfigParser,
    generated_order: list[str],
    apply: bool,
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    text = read_text(path)
    uid = first_line_uid(text)
    rel = relative_path(root, path)
    damaged_uid = uid is None and DAMAGED_UID_LINE_RE.match(first_line(text)) is not None
    uid_status = "ok"

    restored_uid = uid_for_relative_path(config, rel)
    if uid is not None and restored_uid is not None and restored_uid != uid:
        uid = restored_uid
        uid_status = "restore_damaged"
    elif uid is None:
        if restored_uid is not None:
            uid = restored_uid
            uid_status = "restore_damaged" if damaged_uid else "restore_missing"
        else:
            uid = next_uid(config["state"]["last_used_uid"])
            config["state"]["last_used_uid"] = uid
            generated_order.append(uid)
            uid_status = "replace_damaged" if damaged_uid else "insert_missing"

    assert uid is not None
    try:
        if base36_to_int(uid) > base36_to_int(config["state"]["last_used_uid"]):
            config["state"]["last_used_uid"] = uid
            actions.append(ScanAction("last_uid_advance", uid, path, "advanced from existing UID header"))
    except ValueError:
        pass
    old_path = config["files"].get(uid)
    new_text, completion, confidence, projected_path_value, header_actions = ensure_metadata_header(
        text,
        uid,
        path,
        root,
        config,
        uid_status,
    )
    coverage_text, coverage_actions = ensure_memory_coverage_metadata_lines(new_text, uid, path, root)
    new_text = coverage_text
    header_actions.extend(coverage_actions)
    if uid_status == "ok":
        actions.append(ScanAction("ok", uid, path, "UID header exists"))
    actions.extend(header_actions)
    if new_text != text and apply:
        write_text_atomic(path, new_text)

    path_mapping_conflicted = False
    if old_path != rel:
        old_abs = absolute_path(root, old_path) if old_path is not None else None
        old_still_exists = (
            old_abs is not None
            and old_abs.exists()
            and resolved_path(old_abs) != resolved_path(path)
        )
        if old_still_exists:
            actions.append(
                ScanAction(
                    "duplicate_path_conflict",
                    uid,
                    path,
                    f"validator.ini maps UID to existing file: {old_path}",
                )
            )
            path_mapping_conflicted = True
        else:
            detail = "new UID mapping" if old_path is None else f"was {old_path}"
            actions.append(ScanAction("path_update", uid, path, detail))
            if apply:
                config["files"][uid] = rel
            if old_path is not None:
                actions.extend(
                    update_reference_source_path(
                        config,
                        old_path,
                        rel,
                        uid,
                        path,
                        apply,
                    )
                )
                old_tmp_key = old_path.replace("\\", "/")
                new_tmp_key = rel.replace("\\", "/")
                if old_tmp_key in config[TMP_REFERENCE_SECTION] and old_tmp_key != new_tmp_key:
                    existing = parse_reference_sources(config[TMP_REFERENCE_SECTION].get(new_tmp_key, ""))
                    moved = parse_reference_sources(config[TMP_REFERENCE_SECTION].get(old_tmp_key, ""))
                    actions.append(
                        ScanAction(
                            "tmp_ref_source_path_update",
                            uid,
                            path,
                            f"{old_tmp_key} -> {new_tmp_key}",
                        )
                    )
                    if apply:
                        merged = existing | moved
                        if merged:
                            config[TMP_REFERENCE_SECTION][new_tmp_key] = format_reference_sources(merged)
                        config[TMP_REFERENCE_SECTION].pop(old_tmp_key, None)

    if completion is not None:
        completion_value = str(completion)
        if config["completion"].get(uid) != completion_value:
            actions.append(ScanAction("completion_update", uid, path, completion_value))
            if apply:
                config["completion"][uid] = completion_value

    if confidence is not None:
        confidence_value = str(confidence)
        if config["confidence"].get(uid) != confidence_value:
            actions.append(ScanAction("confidence_update", uid, path, confidence_value))
            if apply:
                config["confidence"][uid] = confidence_value

    if path_mapping_conflicted:
        actions.append(
            ScanAction(
                "projected_path_skip",
                uid,
                path,
                "skipped because UID path mapping conflicts with an existing file",
            )
        )
    else:
        actions.extend(
            update_projected_path_tracking(
                root,
                config,
                uid,
                path,
                rel,
                old_path,
                projected_path_value,
                apply,
            )
        )
        canonical_owner, owner_parse_actions = parse_canonical_owner_metadata(root, path, new_text)
        actions.extend(owner_parse_actions)
        actions.extend(
            update_canonical_owner_registry(
                root,
                config,
                uid,
                path,
                canonical_owner,
                apply,
            )
        )
        autogen_metadata, autogen_parse_actions = parse_autogen_metadata(root, path, new_text)
        actions.extend(autogen_parse_actions)
        actions.extend(
            update_autogen_registry_for_metadata(
                root,
                config,
                autogen_metadata,
                path,
                apply,
            )
        )

    return actions


def make_uid_reference_link(root: Path, source_path: Path, target_path: Path) -> str:
    try:
        relative = resolved_path(target_path).relative_to(resolved_path(root)).as_posix()
    except ValueError:
        relative = os.path.relpath(resolved_path(target_path), resolved_path(source_path).parent).replace("\\", "/")
    return f"[{target_path.stem}]({relative})"


def tmp_reference_target(match: re.Match[str]) -> str:
    return (match.group("quoted") or match.group("bare") or "").strip()


def collect_tmp_references(text: str) -> set[str]:
    targets: set[str] = set()
    in_fence = False
    for line in text.splitlines(keepends=True):
        if is_fence_line(line):
            in_fence = not in_fence
            continue
        if in_fence:
            continue
        for match in TMP_REF_RE.finditer(line):
            target = tmp_reference_target(match)
            if target:
                targets.add(target)
    return targets


def resolve_tmp_reference_target(root: Path, source_path: Path, value: str) -> tuple[Path | None, str]:
    raw_value = value.strip()
    if not raw_value:
        return None, "empty TMP target path"

    raw_path = Path(raw_value).expanduser()
    candidates: list[Path] = []

    def add_candidate(path: Path) -> None:
        if path not in candidates:
            candidates.append(path)

    if raw_path.is_absolute():
        add_candidate(raw_path)
    else:
        add_candidate(source_path.parent / raw_path)
        add_candidate(root / raw_path)
        add_candidate(Path.cwd() / raw_path)

    for base in [raw_path, source_path.parent / raw_path, Path.cwd() / raw_path]:
        suffix = project_documentation_suffix(base)
        if suffix is not None:
            add_candidate(root / suffix)

    best_missing: Path | None = None
    for candidate in candidates:
        relative = docs_relative_candidate(root, candidate)
        if relative is not None:
            docs_candidate = root / relative
            best_missing = docs_candidate
            if docs_candidate.exists():
                candidate = docs_candidate
            else:
                continue

        if not candidate.exists():
            continue
        resolved = resolved_path(candidate)
        if resolved.suffix.lower() != ".md":
            return None, f"TMP target is not a Markdown file: {resolved}"
        if not is_under_by_directory(root, resolved):
            return None, f"TMP target is outside direct by-* folders: {resolved}"
        return resolved, ""

    if best_missing is not None:
        return None, f"TMP target path does not exist: {best_missing}"
    return None, f"TMP target path does not exist: {raw_value}"


def target_uid_from_scan_actions(actions: list[ScanAction]) -> str | None:
    for action in actions:
        if action.uid and action.action in {
            "ok",
            "insert_uid",
            "restore_uid",
            "replace_damaged_uid",
            "path_update",
        }:
            return action.uid
    for action in actions:
        if action.uid:
            return action.uid
    return None


def ensure_tmp_target_uid(
    target_path: Path,
    root: Path,
    config: configparser.ConfigParser,
    generated_order: list[str],
    apply: bool,
) -> tuple[str | None, list[ScanAction]]:
    actions = scan_file(target_path, root, config, generated_order, apply)
    text = read_text(target_path)
    uid = first_line_uid(text)
    if uid is None:
        uid = target_uid_from_scan_actions(actions)
    if uid is None:
        actions.append(
            ScanAction(
                "tmp_ref_target_no_uid",
                None,
                target_path,
                "target exists but UID could not be read or assigned",
            )
        )
    else:
        rel = relative_path(root, target_path)
        if config["files"].get(uid) is None:
            config["files"][uid] = rel
    return uid, actions


def update_tmp_reference_errors_for_source(
    config: configparser.ConfigParser,
    source_rel: str,
    source_path: Path,
    previous: set[str],
    current: set[str],
    unresolved: set[str],
    apply: bool,
) -> list[ScanAction]:
    actions: list[ScanAction] = []

    cleared = previous - unresolved
    for target in sorted(cleared):
        if target in current:
            detail = f"resolved TMP reference: {target}"
        else:
            detail = f"TMP reference no longer present: {target}"
        actions.append(ScanAction("tmp_ref_error_clear", None, source_path, detail))

    if apply:
        if unresolved:
            config[TMP_REFERENCE_SECTION][source_rel] = format_reference_sources(unresolved)
        else:
            config[TMP_REFERENCE_SECTION].pop(source_rel, None)

    return actions


def update_uid_references(
    path: Path,
    root: Path,
    config: configparser.ConfigParser,
    apply: bool,
    update_index: bool = True,
    generated_order: list[str] | None = None,
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    text = read_text(path)
    parent_uid = first_line_uid(text)
    source_rel = relative_path(root, path)
    previous_tmp_errors = parse_reference_sources(config[TMP_REFERENCE_SECTION].get(source_rel, ""))
    current_tmp_refs: set[str] = set()
    unresolved_tmp_refs: set[str] = set()
    generated_order = generated_order if generated_order is not None else []
    changed = False

    def replace_tmp(match: re.Match[str]) -> str:
        nonlocal changed
        target_value = tmp_reference_target(match)
        if not target_value:
            actions.append(ScanAction("tmp_ref_unresolved", None, path, "empty TMP target path"))
            return match.group(0)

        current_tmp_refs.add(target_value)
        target_path, error = resolve_tmp_reference_target(root, path, target_value)
        if target_path is None:
            unresolved_tmp_refs.add(target_value)
            actions.append(ScanAction("tmp_ref_unresolved", None, path, f"{target_value}: {error}"))
            return match.group(0)

        target_uid, target_actions = ensure_tmp_target_uid(
            target_path,
            root,
            config,
            generated_order,
            apply,
        )
        actions.extend(target_actions)
        if target_uid is None:
            unresolved_tmp_refs.add(target_value)
            actions.append(
                ScanAction(
                    "tmp_ref_unresolved",
                    None,
                    path,
                    f"{target_value}: target UID could not be assigned",
                )
            )
            return match.group(0)

        expected_link = make_uid_reference_link(root, path, target_path)
        replacement = f"[UID:{target_uid}]{expected_link}"
        actions.append(ScanAction("tmp_ref_replace", target_uid, path, f"{target_value} -> {replacement}"))
        changed = True
        return replacement

    def replace(match: re.Match[str]) -> str:
        nonlocal changed
        target_uid = match.group("uid")
        existing_link = match.group("link")

        if target_uid == parent_uid:
            return match.group(0)

        stored_path = config["files"].get(target_uid)
        if stored_path is None:
            actions.append(
                ScanAction(
                    "missing_ref_uid",
                    target_uid,
                    path,
                    "UID reference is not present in validator.ini",
                )
            )
            return match.group(0)

        target_path = Path(stored_path)
        if not target_path.is_absolute():
            target_path = root / target_path
        if not target_path.exists():
            actions.append(
                ScanAction(
                    "missing_ref_target",
                    target_uid,
                    path,
                    f"target path does not exist: {stored_path}",
                )
            )
            return match.group(0)

        expected_link = make_uid_reference_link(root, path, target_path)
        if existing_link == expected_link:
            return match.group(0)

        action = "uid_link_insert" if existing_link is None else "uid_link_update"
        detail = f"{existing_link or '<missing>'} -> {expected_link}"
        actions.append(ScanAction(action, target_uid, path, detail))
        changed = True
        return f"[UID:{target_uid}]{expected_link}"

    in_fence = False
    output_lines: list[str] = []
    for line in text.splitlines(keepends=True):
        if is_fence_line(line):
            in_fence = not in_fence
            output_lines.append(line)
            continue
        if in_fence:
            output_lines.append(line)
            continue
        line = TMP_REF_RE.sub(replace_tmp, line)
        output_lines.append(UID_REF_RE.sub(replace, line))
    new_text = "".join(output_lines)
    actions.extend(
        update_tmp_reference_errors_for_source(
            config,
            source_rel,
            path,
            previous_tmp_errors,
            current_tmp_refs,
            unresolved_tmp_refs,
            apply,
        )
    )
    if changed and apply:
        write_text_atomic(path, new_text)
    if update_index:
        actions.extend(update_reference_index_for_source(path, root, config, new_text, apply))
    return actions


def reconcile_missing_uids(
    root: Path,
    config: configparser.ConfigParser,
    original_files: dict[str, str],
    seen_file_uids: dict[str, Path],
    remove_missing: bool,
    apply: bool,
    command_context: CommandContext | None = None,
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    command_context = command_context or CommandContext()
    additional_paths_by_uid = (
        build_additional_report_paths_by_uid(config) if remove_missing else {}
    )
    for uid, stored_path in original_files.items():
        if uid in seen_file_uids:
            continue

        path = Path(stored_path)
        if not path.is_absolute():
            path = root / path
        if not is_under_by_directory(root, path):
            continue

        action_name = "remove_missing" if remove_missing else "missing_uid"
        if remove_missing:
            detail = "removed from validator.ini" if apply else "would remove from validator.ini"
        else:
            detail = "not found in scanned by-* Markdown files"
        actions.append(ScanAction(action_name, uid, path, detail))
        if remove_missing and apply:
            actions.extend(
                mark_reports_for_uid_needs_revalidation(
                    root,
                    config,
                    uid,
                    f"target_uid_removed: {uid}",
                    apply,
                    command_context,
                    additional_paths_by_uid,
                )
            )
            config["files"].pop(uid, None)
            config["completion"].pop(uid, None)
            config["confidence"].pop(uid, None)
            config["references"].pop(uid, None)
            remove_autogen_uid(config, uid, apply)
            source_rel = stored_path.replace("\\", "/")
            for target_uid in list(config["references"].keys()):
                sources = parse_reference_sources(config["references"].get(target_uid, ""))
                if source_rel not in sources:
                    continue
                sources.remove(source_rel)
                if sources:
                    config["references"][target_uid] = format_reference_sources(sources)
                else:
                    config["references"].pop(target_uid, None)
    return actions


def resolve_file_argument(root: Path, value: str) -> Path:
    raw_path = Path(value).expanduser()
    candidates: list[Path] = []

    def add_candidate(path: Path) -> None:
        normalized = path
        if normalized not in candidates:
            candidates.append(normalized)

    if raw_path.is_absolute():
        add_candidate(raw_path)
    else:
        add_candidate(Path.cwd() / raw_path)
        add_candidate(root / raw_path)

    suffix = project_documentation_suffix(raw_path)
    if suffix is not None:
        add_candidate(root / suffix)

    cwd_suffix = project_documentation_suffix(Path.cwd() / raw_path)
    if cwd_suffix is not None:
        add_candidate(root / cwd_suffix)

    for candidate in candidates:
        relative = docs_relative_candidate(root, candidate)
        if relative is not None:
            return resolved_path(root / relative)

    for candidate in candidates:
        if candidate.exists():
            return resolved_path(candidate)

    if suffix is not None and len(suffix.parts) >= 2 and suffix.parts[0].startswith("by-"):
        return resolved_path(root / suffix)

    if candidates:
        return resolved_path(candidates[-1])
    return resolved_path(raw_path)


def scan_targets(args, root: Path, config: configparser.ConfigParser) -> tuple[list[Path], list[ScanAction]]:
    if args.mode == "full":
        return all_markdown_files(root), []
    if args.mode == "documented":
        return documented_targets(root, config)
    if args.mode in {"rescore", "isolated", "autogen"}:
        return [], []
    if args.mode == "file":
        if not args.file:
            raise SystemExit("--file is required when --mode file is used")
        path = resolve_file_argument(root, args.file)
        if not path.exists():
            raise SystemExit(f"file not found: {path}")
        if path.suffix.lower() != ".md":
            raise SystemExit(f"not a Markdown file: {path}")
        if not is_under_by_directory(root, path):
            raise SystemExit(f"file is outside direct by-* folders: {path}")
        return [path], []
    raise SystemExit(f"unknown mode: {args.mode}")


def scan_isolated_files(root: Path) -> tuple[list[Path], list[ScanAction]]:
    targets = all_markdown_files(root)
    actions: list[ScanAction] = []
    uid_to_path: dict[str, Path] = {}
    inbound: dict[str, set[str]] = {}

    texts: dict[Path, str] = {}
    uids_by_path: dict[Path, str] = {}
    for path in targets:
        try:
            text = read_text(path)
        except UnicodeDecodeError as exc:
            actions.append(ScanAction("read_error", None, path, str(exc)))
            continue

        texts[path] = text
        uid = first_line_uid(text)
        if uid is None:
            actions.append(
                ScanAction(
                    "isolated_no_uid",
                    None,
                    path,
                    "missing UID header; cannot be targeted by UID references",
                )
            )
            continue

        uids_by_path[path] = uid
        previous = uid_to_path.get(uid)
        if previous is not None and previous != path:
            actions.append(
                ScanAction(
                    "duplicate",
                    uid,
                    path,
                    f"also present in {relative_path(root, previous)}",
                )
            )
            continue

        uid_to_path[uid] = path
        inbound.setdefault(uid, set())

    for source_path, text in texts.items():
        source_uid = uids_by_path.get(source_path)
        source_rel = relative_path(root, source_path)
        for target_uid in collect_uid_references(text, source_uid):
            if target_uid in inbound:
                inbound[target_uid].add(source_rel)

    for uid, path in sorted(uid_to_path.items(), key=lambda item: relative_path(root, item[1])):
        sources = inbound.get(uid, set())
        if sources:
            continue
        actions.append(
            ScanAction(
                "isolated",
                uid,
                path,
                "no inbound UID references from other by-* Markdown files",
            )
        )

    return targets, actions


def uid_link(uid: str, stored_path: str) -> str:
    normalized = stored_path.replace("\\", "/")
    return f"[UID:{uid}][{Path(stored_path).stem}]({normalized})"


def autogen_parse_metadata_from_file(
    root: Path,
    config: configparser.ConfigParser,
    uid: str,
    use_dryrun_artifacts: bool = False,
) -> tuple[AutogenMetadata | None, list[ScanAction]]:
    stored_path = config["files"].get(uid)
    if not stored_path:
        return None, []
    path = absolute_path(root, stored_path)
    if not path.exists():
        return (
            None,
            [ScanAction("autogen_registry_stale", uid, path, "registered file is missing")],
        )
    if not is_autogen_metadata_doc(root, path):
        return None, []
    try:
        source_path = dryrun_artifact_path(path) if use_dryrun_artifacts and dryrun_artifact_path(path).exists() else path
        if source_path == path:
            cached = valid_cached_file_entry(root, stored_path, path)
            if cached is not None and "autogen_metadata_present" in cached:
                cached_metadata = cached.get("autogen_metadata")
                import_paths = cached_metadata.get("import_paths", []) if isinstance(cached_metadata, dict) else []
                if not import_paths:
                    metadata = autogen_metadata_from_cache(cached_metadata)
                    actions = scan_actions_from_cache(root, cached.get("autogen_actions", []))
                    if metadata is not None or not bool(cached.get("autogen_metadata_present")):
                        return metadata, actions
        metadata, parse_actions = parse_autogen_metadata(root, path, read_text(source_path))
        if source_path == path:
            update_metadata_cache_entry(
                root,
                stored_path,
                path,
                {
                    "uid": uid,
                    "autogen_metadata_present": metadata is not None,
                    "autogen_metadata": autogen_metadata_to_cache(metadata),
                    "autogen_actions": scan_actions_to_cache(root, parse_actions),
                },
            )
        return metadata, parse_actions
    except UnicodeDecodeError as exc:
        return None, [ScanAction("read_error", uid, path, str(exc))]


def autogen_metadata_index(
    root: Path,
    config: configparser.ConfigParser,
    use_dryrun_artifacts: bool = False,
) -> tuple[dict[str, AutogenMetadata], list[ScanAction]]:
    metadata_by_uid: dict[str, AutogenMetadata] = {}
    actions: list[ScanAction] = []
    candidate_uids = set(config[RECONSTRUCTABLE_SECTION].keys())
    candidate_uids.update(
        uid for uid, stored_path in config["files"].items()
        if is_autogen_metadata_doc(root, absolute_path(root, stored_path))
    )

    for uid in sorted(candidate_uids, key=lambda item: config["files"].get(item, "")):
        metadata, parse_actions = autogen_parse_metadata_from_file(root, config, uid, use_dryrun_artifacts)
        actions.extend(parse_actions)
        if metadata is not None:
            metadata_by_uid[uid] = metadata
    return metadata_by_uid, actions


def emitter_position_for_parent(metadata: AutogenMetadata, parent_uid: str) -> int | None:
    if not metadata.emitter_uids:
        return None
    if len(metadata.emitter_positions) == 1:
        return metadata.emitter_positions[0]
    try:
        index = metadata.emitter_uids.index(parent_uid)
    except ValueError:
        return None
    if index >= len(metadata.emitter_positions):
        return None
    return metadata.emitter_positions[index]


def sort_autogen_children(
    parent_uid: str,
    children: list[str],
    metadata_by_uid: dict[str, AutogenMetadata],
) -> list[str]:
    def sort_key(uid: str) -> tuple[int, int]:
        metadata = metadata_by_uid.get(uid)
        position = emitter_position_for_parent(metadata, parent_uid) if metadata else None
        has_no_position = 1 if position is None else 0
        position_value = 0 if position is None else position
        return (has_no_position, position_value)

    return sorted(children, key=sort_key)


def build_autogen_children(metadata_by_uid: dict[str, AutogenMetadata]) -> dict[str, list[str]]:
    children: dict[str, list[str]] = {}
    for uid, metadata in metadata_by_uid.items():
        if metadata.reconstructable != "true" or not metadata.emitter_uids:
            continue
        for emitter_uid in metadata.emitter_uids:
            children.setdefault(emitter_uid, []).append(uid)
    return {
        parent_uid: sort_autogen_children(parent_uid, child_uids, metadata_by_uid)
        for parent_uid, child_uids in children.items()
    }


def projected_root_error(
    config: configparser.ConfigParser,
    root_uid: str,
) -> str | None:
    projected_path = config[PROJECTED_PATH_SECTION].get(root_uid, "")
    _, status, error = validate_projected_path(projected_path)
    if status != "valid":
        detail = "non-standalone projected path" if status == "none" else error or "blank projected path"
        return f"emitter_root_invalid_projected_path: {detail}"
    owner_value = config[CANONICAL_OWNER_SECTION].get(root_uid, "")
    if owner_value and owner_value != "FILE":
        return "canonical_owner_file_missing: by-file root does not have CANONICAL_OWNER:FILE"
    return None


def resolve_emitter_roots(
    uid: str,
    root: Path,
    config: configparser.ConfigParser,
    metadata_by_uid: dict[str, AutogenMetadata],
) -> tuple[list[str], list[str]]:
    errors: list[str] = []
    metadata = metadata_by_uid.get(uid)
    if metadata is None:
        return [], ["autogen_registry_stale: missing metadata"]
    if metadata.reconstructable != "true":
        return [], []
    if not metadata.emitter_uids:
        return [], []

    roots: list[str] = []

    def walk(route_uid: str, seen: set[str]) -> None:
        if route_uid in seen:
            errors.append("emitter_route_cycle: emitter chain repeats")
            return
        seen.add(route_uid)
        route_path = config["files"].get(route_uid)
        if route_path is None:
            errors.append(f"emitter_uid_unknown: emitter UID {route_uid} is not in validator.ini")
            return
        if is_projected_path_candidate(route_path):
            root_error = projected_root_error(config, route_uid)
            if root_error:
                errors.append(root_error)
                return
            roots.append(route_uid)
            return
        route_metadata = metadata_by_uid.get(route_uid)
        if route_metadata is None:
            errors.append("emitter_route_ineligible: emitter is not a reconstruction metadata document")
            return
        if route_metadata.reconstructable != "true":
            errors.append("emitter_route_ineligible: emitter is not marked reconstructable")
            return
        if not route_metadata.emitter_uids:
            errors.append("emitter_route_dead_end: emitter chain does not surface to a file root")
            return
        for next_uid in route_metadata.emitter_uids:
            walk(next_uid, set(seen))

    for emitter_uid in metadata.emitter_uids:
        walk(emitter_uid, {uid})
    return sorted(set(roots), key=lambda item: config["files"].get(item, "")), errors


def rebuild_autogen_registry(
    root: Path,
    config: configparser.ConfigParser,
    apply: bool,
    use_dryrun_artifacts: bool = False,
) -> tuple[dict[str, AutogenMetadata], dict[str, list[str]], dict[str, list[str]], dict[str, str], dict[str, list[str]], list[ScanAction]]:
    metadata_by_uid, actions = autogen_metadata_index(root, config, use_dryrun_artifacts)
    for uid, metadata in metadata_by_uid.items():
        path = absolute_path(root, metadata.path)
        actions.extend(
            set_config_value_action(
                config,
                RECONSTRUCTION_H_CODE_HASH_SECTION,
                uid,
                metadata.header_code_hash,
                path,
                "autogen_registry_update",
                apply,
            )
        )
        actions.extend(
            set_config_value_action(
                config,
                RECONSTRUCTION_H_CODE_MODE_SECTION,
                uid,
                metadata.header_code_mode,
                path,
                "autogen_registry_update",
                apply,
            )
        )
    children_by_parent = build_autogen_children(metadata_by_uid)
    roots_by_uid: dict[str, list[str]] = {}
    status_by_uid: dict[str, str] = {}
    errors_by_uid: dict[str, list[str]] = {}
    dead_ends_by_uid: dict[str, list[str]] = {}

    for uid, metadata in metadata_by_uid.items():
        errors = list(metadata.errors or [])
        if metadata.reconstructable == "invalid":
            errors.append("autogen_value_invalid: invalid RECONSTRUCTABLE value")
            status_by_uid[uid] = "error"
        elif metadata.reconstructable == "blank":
            status_by_uid[uid] = "unclassified"
        elif metadata.reconstructable == "false":
            status_by_uid[uid] = "not_reconstructable"
        else:
            roots, root_errors = resolve_emitter_roots(uid, root, config, metadata_by_uid)
            errors.extend(error for error in root_errors if not error.startswith("emitter_route_dead_end"))
            dead_end_errors = [error for error in root_errors if error.startswith("emitter_route_dead_end")]
            if (
                dead_end_errors
                and force_empty_emitter_marker_comments(config)
                and is_empty_emitter_marker_candidate(metadata)
                and not empty_emitter_markers_consider_deadend(config)
            ):
                dead_end_errors = []
            if roots:
                roots_by_uid[uid] = roots
            if dead_end_errors:
                dead_ends_by_uid[uid] = dead_end_errors
            if dead_end_errors:
                status_by_uid[uid] = "dead-end"
            elif metadata.canonical_owner == "NONE":
                status_by_uid[uid] = "no-owner"
            elif len(metadata.emitter_uids) > 1:
                status_by_uid[uid] = "multiple-emitters"
            elif metadata.emitter_uids:
                status_by_uid[uid] = "emits"
            else:
                status_by_uid[uid] = "non-emits"
        if errors:
            errors_by_uid[uid] = errors
            status_by_uid[uid] = "error"

    if apply:
        config[AUTOGEN_CHILDREN_SECTION].clear()
        config[AUTOGEN_EMITTER_CHILDREN_SECTION].clear()
        for parent_uid, children in children_by_parent.items():
            if children:
                joined = ";".join(children)
                config[AUTOGEN_EMITTER_CHILDREN_SECTION][parent_uid] = joined

        config[AUTOGEN_ROOT_SECTION].clear()
        config[AUTOGEN_ROOTS_SECTION].clear()
        for uid, root_uids in roots_by_uid.items():
            joined = ",".join(root_uids)
            config[AUTOGEN_ROOTS_SECTION][uid] = joined

        config[AUTOGEN_DEAD_END_SECTION].clear()
        for uid, errors in dead_ends_by_uid.items():
            config[AUTOGEN_DEAD_END_SECTION][uid] = "; ".join(errors)

        config[AUTOGEN_STATUS_SECTION].clear()
        for uid, status in status_by_uid.items():
            config[AUTOGEN_STATUS_SECTION][uid] = status

        config[AUTOGEN_ERROR_SECTION].clear()
        for uid, errors in errors_by_uid.items():
            config[AUTOGEN_ERROR_SECTION][autogen_error_key(uid)] = (
                f"{metadata_by_uid[uid].path}: {'; '.join(errors)}"
            )

    actions.append(
        ScanAction(
            "autogen_registry_rebuild",
            None,
            root / DEFAULT_INI.name,
            f"{len(metadata_by_uid)} metadata nodes, {sum(len(v) for v in children_by_parent.values())} edges",
        )
    )
    return metadata_by_uid, children_by_parent, roots_by_uid, status_by_uid, dead_ends_by_uid, actions


def generated_cpp_destination(root: Path, config: configparser.ConfigParser, root_uid: str) -> Path | None:
    stored_path = config["files"].get(root_uid)
    if stored_path is None:
        return None
    projected_path = config[PROJECTED_PATH_SECTION].get(root_uid, "")
    normalized, status, _ = validate_projected_path(projected_path)
    if status != "valid":
        return None
    return generated_cpp_path(root, normalized, Path(stored_path).stem)


def generated_header_destination(root: Path, config: configparser.ConfigParser, root_uid: str) -> Path | None:
    stored_path = config["files"].get(root_uid)
    if stored_path is None:
        return None
    projected_path = config[PROJECTED_PATH_SECTION].get(root_uid, "")
    normalized, status, _ = validate_projected_path(projected_path)
    if status != "valid":
        return None
    return generated_header_path(root, normalized, Path(stored_path).stem)


def fallback_insert_children(code: str, children_text: str, folder: str) -> tuple[str, str | None]:
    if not children_text:
        if CHILDREN_MARKER in code:
            return code.replace(CHILDREN_MARKER, NO_CHILDREN_MARKER), None
        return code, None
    if not code.strip():
        return children_text, "autogen_emitter_has_no_code"
    if CHILDREN_MARKER in code:
        return code.replace(CHILDREN_MARKER, children_text), None
    if folder in {"by-class", "by-type"}:
        stripped = code.rstrip()
        if stripped.endswith("};"):
            suffix_len = len(code) - len(stripped)
            insert_at = code.rfind("};")
            return (
                code[:insert_at].rstrip() + "\n\n" + children_text.strip("\n") + "\n" + code[insert_at:] + code[len(stripped):],
                "autogen_children_fallback_insert",
            )
    return code, "autogen_children_marker_missing"


def join_snippets(snippets: list[str]) -> str:
    return "\n\n".join(snippet.strip("\n") for snippet in snippets if snippet.strip("\n"))


def autogen_score_suffix(config: configparser.ConfigParser, metadata: AutogenMetadata) -> str:
    completion = score_from_config(config, "completion", metadata.uid, metadata.path)
    confidence = score_from_config(config, "confidence", metadata.uid, metadata.path)
    return f" | Completion:{completion} | Confidence:{confidence}"


def autogen_snippet_header(metadata: AutogenMetadata, config: configparser.ConfigParser) -> str:
    return f"// UID:{metadata.uid} | {metadata.path}{autogen_score_suffix(config, metadata)}"


def is_empty_emitter_marker_candidate(metadata: AutogenMetadata) -> bool:
    return (
        metadata.reconstructable == "true"
        and bool(metadata.emitter_uids)
        and not metadata.code.strip()
    )


def empty_emitter_marker_comment(metadata: AutogenMetadata, config: configparser.ConfigParser) -> str:
    marker_path = metadata.path.replace("/", "\\")
    return f"// UID:{metadata.uid} | {marker_path}{autogen_score_suffix(config, metadata)} | Empty Emitter Marker"


def is_empty_emitter_marker_line(line: str) -> bool:
    return line.startswith("// UID:") and " | Empty Emitter Marker" in line


def move_empty_emitter_markers_to_end(text: str) -> str:
    if "Empty Emitter Marker" not in text:
        return text
    body_lines: list[str] = []
    marker_lines: list[str] = []
    for line in text.splitlines():
        if is_empty_emitter_marker_line(line):
            marker_lines.append(line.strip())
        else:
            body_lines.append(line)
    if not marker_lines:
        return text
    body = "\n".join(body_lines).strip("\n")
    markers = "\n\n".join(marker_lines)
    return body + ("\n\n" if body else "") + markers


def imported_reconstruction_code(
    root: Path,
    metadata: AutogenMetadata,
    config: configparser.ConfigParser,
    actions: list[ScanAction],
) -> str:
    chunks: list[str] = []
    for import_path in metadata.import_paths:
        source_path = reconstruction_import_source_path(root, import_path)
        try:
            source_text = read_text(source_path).strip("\n")
        except (OSError, UnicodeDecodeError) as exc:
            actions.append(ScanAction("autogen_import_error", metadata.uid, source_path, str(exc)))
            continue
        chunks.append(
            "\n".join(
                [
                    f"// UID:{metadata.uid} | {metadata.path}{autogen_score_suffix(config, metadata)} | Imported source: {import_path}",
                    f"// ---- begin imported source: {import_path} ----",
                    "",
                    source_text,
                    "",
                    f"// ---- end imported source: {import_path} ----",
                ]
            )
        )
    return "\n\n".join(chunks).strip("\n")


def assemble_autogen_node(
    uid: str,
    metadata_by_uid: dict[str, AutogenMetadata],
    children_by_parent: dict[str, list[str]],
    status_by_uid: dict[str, str],
    coded_uids: set[str],
    header_coded_uids: set[str],
    actions: list[ScanAction],
    root: Path,
    config: configparser.ConfigParser,
    stack: set[str] | None = None,
) -> tuple[str, str]:
    stack = set() if stack is None else set(stack)
    if uid in stack:
        actions.append(ScanAction("autogen_emitter_cycle", uid, absolute_path(root, config["files"].get(uid, ".")), "cycle during assembly"))
        return "", ""
    stack.add(uid)

    metadata = metadata_by_uid.get(uid)
    if metadata is None or status_by_uid.get(uid) == "error":
        return "", ""

    child_results = [
        assemble_autogen_node(
            child_uid,
            metadata_by_uid,
            children_by_parent,
            status_by_uid,
            coded_uids,
            header_coded_uids,
            actions,
            root,
            config,
            stack,
        )
        for child_uid in children_by_parent.get(uid, [])
    ]
    children_text = join_snippets([result[0] for result in child_results])
    header_children_text = join_snippets([result[1] for result in child_results])
    code = (
        imported_reconstruction_code(root, metadata, config, actions)
        if metadata.code_mode == "import"
        else metadata.code
    )
    assembled, warning = fallback_insert_children(code, children_text, metadata.folder)
    marker_emitted = (
        force_empty_emitter_marker_comments(config)
        and is_empty_emitter_marker_candidate(metadata)
    )
    if marker_emitted:
        marker = empty_emitter_marker_comment(metadata, config)
        assembled = marker + ("\n\n" + assembled.strip("\n") if assembled.strip() else "")
    if warning:
        actions.append(
            ScanAction(
                warning,
                uid,
                absolute_path(root, metadata.path),
                "explicit [[CHILDREN]] marker is preferred" if warning != "autogen_emitter_has_no_code" else "emitting children only",
            )
        )
        if warning == "autogen_children_marker_missing":
            assembled = code

    if assembled.strip():
        if marker_emitted:
            if not empty_emitter_markers_consider_not_coded(config):
                coded_uids.add(uid)
            cpp_result = assembled.strip("\n")
        else:
            coded_uids.add(uid)
            cpp_result = autogen_snippet_header(metadata, config) + "\n" + assembled.strip("\n")
    else:
        cpp_result = assembled

    header_assembled, header_warning = fallback_insert_children(
        metadata.header_code,
        header_children_text,
        metadata.folder,
    )
    if header_warning:
        header_action = "autogen_header_" + header_warning.removeprefix("autogen_")
        actions.append(
            ScanAction(
                header_action,
                uid,
                absolute_path(root, metadata.path),
                "explicit [[CHILDREN]] marker is preferred"
                if header_warning != "autogen_emitter_has_no_code"
                else "emitting header children only",
            )
        )
        if header_warning == "autogen_children_marker_missing":
            header_assembled = metadata.header_code

    if header_assembled.strip():
        if metadata.header_code.strip():
            header_coded_uids.add(uid)
            header_result = autogen_snippet_header(metadata, config) + "\n" + header_assembled.strip("\n")
        else:
            header_result = header_assembled.strip("\n")
    else:
        header_result = header_assembled

    return cpp_result, header_result


def assemble_autogen_root(
    root_uid: str,
    metadata_by_uid: dict[str, AutogenMetadata],
    children_by_parent: dict[str, list[str]],
    status_by_uid: dict[str, str],
    root: Path,
    config: configparser.ConfigParser,
    actions: list[ScanAction],
) -> tuple[str, str, set[str], set[str]]:
    coded_uids: set[str] = set()
    header_coded_uids: set[str] = set()
    results = [
        assemble_autogen_node(
            child_uid,
            metadata_by_uid,
            children_by_parent,
            status_by_uid,
            coded_uids,
            header_coded_uids,
            actions,
            root,
            config,
        )
        for child_uid in children_by_parent.get(root_uid, [])
    ]
    cpp = move_empty_emitter_markers_to_end(join_snippets([result[0] for result in results]))
    header = join_snippets([result[1] for result in results])
    return cpp, header, coded_uids, header_coded_uids


def generated_cpp_content(
    root_uid: str,
    root_path: str,
    assembled: str,
    command_context: CommandContext,
    refresh_source: str,
) -> str:
    body = assembled.strip("\n")
    header = "\n".join(
        [
            AUTOGEN_SENTINEL,
            *render_generated_cpp_metadata_header(command_context, refresh_source),
            f"// Source by-file UID: {root_uid}",
            f"// Source by-file doc: {root_path}",
            "",
        ]
    )
    return header + (body + "\n" if body else "")


def generated_header_content(
    root_uid: str,
    root_path: str,
    assembled: str,
    command_context: CommandContext,
    refresh_source: str,
) -> str:
    return generated_cpp_content(root_uid, root_path, assembled, command_context, refresh_source)


def generated_source_uid(path: Path) -> str | None:
    try:
        text = read_text(path)
    except (FileNotFoundError, UnicodeDecodeError):
        return None
    if not text.startswith(AUTOGEN_SENTINEL):
        return None
    match = AUTOGEN_CPP_SOURCE_UID_RE.search(text)
    if match is None:
        return None
    return match.group("uid")


def generated_cpp_source_uid(path: Path) -> str | None:
    return generated_source_uid(path)


def cleanup_stale_nexustk_generated_sources(
    root: Path,
    config: configparser.ConfigParser,
    apply: bool,
    backup_state: dict[str, Path | None],
    selected_root_uids: set[str] | None = None,
    affected_uids: set[str] | None = None,
    active_root_uids: set[str] | None = None,
    active_header_root_uids: set[str] | None = None,
) -> list[ScanAction]:
    generated_root = root / AUTOGEN_NEXUSTK_RELATIVE_PATH
    if not generated_root.exists():
        return []
    actions: list[ScanAction] = []
    affected_uids = affected_uids or set()
    full_scan = selected_root_uids is None
    selected_paths: set[Path] = set()
    if selected_root_uids is not None:
        for root_uid in selected_root_uids:
            for destination in (
                generated_cpp_destination(root, config, root_uid),
                generated_header_destination(root, config, root_uid),
            ):
                if destination is not None:
                    selected_paths.add(path_cache_key(destination))
    paths = sorted([*generated_root.rglob("*.cpp"), *generated_root.rglob("*.h")])
    for path in paths:
        source_type = "header" if path.suffix.lower() == ".h" else "cpp"
        uid = generated_source_uid(path)
        if uid is None:
            if not full_scan and path_cache_key(path) not in selected_paths:
                continue
            detail = "validator-owned NexusTK file is not a current generated source"
            actions.append(ScanAction(f"autogen_{source_type}_orphan_delete", None, path, detail))
            if apply:
                backup_generated_file(root, path, backup_state)
                parent = path.parent
                path.unlink(missing_ok=True)
                for removed in remove_empty_generated_dirs(root, parent):
                    actions.append(ScanAction("projected_folder_remove", None, removed, "empty generated folder"))
            continue
        if selected_root_uids is not None and uid not in selected_root_uids and uid not in affected_uids:
            continue
        if active_root_uids is not None and uid not in active_root_uids:
            detail = "source UID no longer has an active generated root"
            actions.append(ScanAction(f"autogen_{source_type}_stale_delete", uid, path, detail))
            if apply:
                backup_generated_file(root, path, backup_state)
                parent = path.parent
                path.unlink(missing_ok=True)
                for removed in remove_empty_generated_dirs(root, parent):
                    actions.append(ScanAction("projected_folder_remove", uid, removed, "empty generated folder"))
            continue
        if source_type == "header" and active_header_root_uids is not None and uid not in active_header_root_uids:
            detail = "assembled header source is now empty"
            actions.append(ScanAction("autogen_header_stale_delete", uid, path, detail))
            if apply:
                backup_generated_file(root, path, backup_state)
                parent = path.parent
                path.unlink(missing_ok=True)
                for removed in remove_empty_generated_dirs(root, parent):
                    actions.append(ScanAction("projected_folder_remove", uid, removed, "empty generated folder"))
            continue
        current_target = (
            generated_header_destination(root, config, uid)
            if source_type == "header"
            else generated_cpp_destination(root, config, uid)
        )
        if current_target is not None and resolved_path(current_target) == resolved_path(path):
            continue
        detail = "source UID no longer emits this generated destination"
        actions.append(ScanAction(f"autogen_{source_type}_stale_delete", uid, path, detail))
        if apply:
            backup_generated_file(root, path, backup_state)
            parent = path.parent
            path.unlink(missing_ok=True)
            for removed in remove_empty_generated_dirs(root, parent):
                actions.append(ScanAction("projected_folder_remove", uid, removed, "empty generated folder"))
    return actions


def cleanup_stale_nexustk_generated_cpp(
    root: Path,
    config: configparser.ConfigParser,
    apply: bool,
    backup_state: dict[str, Path | None],
    selected_root_uids: set[str] | None = None,
    affected_uids: set[str] | None = None,
    active_root_uids: set[str] | None = None,
    active_header_root_uids: set[str] | None = None,
) -> list[ScanAction]:
    return cleanup_stale_nexustk_generated_sources(
        root,
        config,
        apply,
        backup_state,
        selected_root_uids,
        affected_uids,
        active_root_uids,
        active_header_root_uids,
    )


def classify_generated_file(path: Path) -> str:
    if not path.exists():
        return "missing"
    if path.stat().st_size == 0:
        return "empty_placeholder"
    try:
        text = read_text(path)
    except UnicodeDecodeError:
        return "manual_or_conflict"
    if AUTOGEN_SENTINEL in text or AUTOGEN_MARKDOWN_SENTINEL in text:
        return "validator_owned"
    return "manual_or_conflict"


def is_autogen_nexustk_path(root: Path, path: Path) -> bool:
    try:
        Path(relative_path(root, path)).relative_to(AUTOGEN_NEXUSTK_RELATIVE_PATH)
    except ValueError:
        return False
    return True


def is_validator_autogen_report_path(root: Path, path: Path) -> bool:
    rel = Path(relative_path(root, path))
    return rel.parent == AUTO_GENERATED_RELATIVE_PATH and rel.name in VALIDATOR_AUTOGEN_REPORT_NAMES


def autogen_backup_exists_for_today(root: Path, now: datetime) -> bool:
    backup_base = root / "tools" / "validator_autogen_backup"
    if not backup_base.exists():
        return False
    today_prefix = now.strftime("%Y%m%d-")
    try:
        return any(child.is_dir() and child.name.startswith(today_prefix) for child in backup_base.iterdir())
    except OSError:
        return False


def backup_generated_file(root: Path, path: Path, state: dict[str, Path | None]) -> Path | None:
    backup_root = state.get("backup_root")
    if backup_root is None:
        now = datetime.now()
        if autogen_backup_exists_for_today(root, now):
            return None
        timestamp = now.strftime("%Y%m%d-%H%M%S")
        backup_root = root / "tools" / "validator_autogen_backup" / timestamp
        state["backup_root"] = backup_root
    assert isinstance(backup_root, Path)
    rel = Path(relative_path(root, path))
    target = backup_root / rel
    target.parent.mkdir(parents=True, exist_ok=True)
    if path.exists():
        shutil.copy2(path, target)
    else:
        write_text_atomic(target, "")
    return backup_root


def safe_write_generated_text(
    root: Path,
    path: Path,
    text: str,
    uid: str | None,
    apply: bool,
    backup_state: dict[str, Path | None],
    create_action: str,
    update_action: str,
    noop_action: str,
    conflict_action: str,
    backup_enabled: bool = True,
    backup_lock: threading.Lock | None = None,
    metadata_refresh_action: str = "generated_metadata_refresh",
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    state = classify_generated_file(path)
    nexus_generated_path = is_autogen_nexustk_path(root, path)
    validator_report_path = is_validator_autogen_report_path(root, path)
    if state == "manual_or_conflict" and not nexus_generated_path and not validator_report_path:
        return [ScanAction(conflict_action, uid, path, "nonempty file lacks validator autogen sentinel")]
    if path.exists():
        old_text: str | None
        try:
            old_text = read_text(path)
        except UnicodeDecodeError:
            if not nexus_generated_path and not validator_report_path:
                return [ScanAction(conflict_action, uid, path, "existing file is not UTF-8 text")]
            old_text = None
        if old_text is not None and old_text == text:
            return [ScanAction(noop_action, uid, path, "unchanged")]
        if (
            old_text is not None
            and old_text.startswith(AUTOGEN_MARKDOWN_SENTINEL)
            and text.startswith(AUTOGEN_MARKDOWN_SENTINEL)
            and strip_generated_markdown_metadata(old_text) == strip_generated_markdown_metadata(text)
        ):
            detail = "generated report metadata refreshed"
            if not generated_markdown_has_metadata(old_text):
                detail = "generated report metadata inserted"
            actions.append(ScanAction(metadata_refresh_action, uid, path, detail))
        elif (
            old_text is not None
            and old_text.startswith(AUTOGEN_SENTINEL)
            and text.startswith(AUTOGEN_SENTINEL)
            and strip_generated_cpp_metadata(old_text) == strip_generated_cpp_metadata(text)
        ):
            source_label = "header" if path.suffix.lower() == ".h" else "C++"
            detail = f"generated {source_label} metadata refreshed"
            if not generated_cpp_has_metadata(old_text):
                detail = f"generated {source_label} metadata inserted"
            actions.append(ScanAction(metadata_refresh_action, uid, path, detail))
        else:
            detail = "validator-owned generated file"
            if nexus_generated_path and state == "manual_or_conflict":
                detail = "validator-owned NexusTK generated file rebuilt"
            elif validator_report_path and state == "manual_or_conflict":
                detail = "validator-owned generated report rebuilt"
            elif old_text is None:
                if nexus_generated_path:
                    detail = "validator-owned NexusTK generated file rebuilt from unreadable content"
                elif validator_report_path:
                    detail = "validator-owned generated report rebuilt from unreadable content"
            actions.append(ScanAction(update_action, uid, path, detail))
        if apply:
            if backup_enabled:
                if backup_lock is None:
                    backup_generated_file(root, path, backup_state)
                else:
                    with backup_lock:
                        backup_generated_file(root, path, backup_state)
            write_text_atomic(path, text)
    else:
        actions.append(ScanAction(create_action, uid, path, "new generated file"))
        if apply:
            write_text_atomic(path, text)
    return actions


def run_generated_write_batch(
    root: Path,
    writes: list[GeneratedWrite],
    apply: bool,
    backup_state: dict[str, Path | None],
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    unique: dict[Path, GeneratedWrite] = {}
    for write in writes:
        key = path_cache_key(write.path)
        if key in unique:
            actions.append(
                ScanAction(
                    "generated_write_duplicate",
                    write.uid,
                    write.path,
                    "more than one generated task targeted this file",
                )
            )
            continue
        unique[key] = write

    tasks = list(unique.values())
    if not tasks:
        return actions

    backup_lock = threading.Lock()

    def run_one(write: GeneratedWrite) -> list[ScanAction]:
        return safe_write_generated_text(
            root,
            write.path,
            write.text,
            write.uid,
            apply,
            backup_state,
            write.create_action,
            write.update_action,
            write.noop_action,
            write.conflict_action,
            backup_enabled=write.backup_enabled,
            backup_lock=backup_lock,
            metadata_refresh_action=write.metadata_refresh_action,
        )

    if len(tasks) == 1:
        actions.extend(run_one(tasks[0]))
        return actions

    max_workers = min(8, len(tasks))
    with concurrent.futures.ThreadPoolExecutor(max_workers=max_workers) as executor:
        futures = [executor.submit(run_one, write) for write in tasks]
        for future in concurrent.futures.as_completed(futures):
            actions.extend(future.result())
    return sorted(
        actions,
        key=lambda action: (
            relative_path(root, action.path) if action.path.is_absolute() else action.path.as_posix(),
            action.action,
            action.uid or "",
        ),
    )


def autogen_owner_state(canonical_owner: str, owner_raw: str = "", owner_seen: bool = True) -> str:
    raw = owner_raw.strip().upper()
    owner = canonical_owner.strip().upper()
    if "," in raw or "," in owner:
        return "specified-multiple"
    if not owner_seen or raw == "":
        return "blank"
    if owner == "NONE":
        return "none"
    return "specified"


def autogen_report_stats(entries: list[AutogenReportEntry]) -> list[str]:
    reconstructable_statuses = {"no-owner", "emits", "multiple-emitters", "non-emits", "coded", "dead-end", "error"}
    total_type = len(entries)
    total_reconstructable = sum(1 for entry in entries if entry.status in reconstructable_statuses)
    total_not = sum(1 for entry in entries if entry.status == "not_reconstructable")
    total_routed = sum(1 for entry in entries if entry.status in {"emits", "multiple-emitters", "coded"})
    total_coded = sum(1 for entry in entries if entry.status == "coded")
    total_header_coded = sum(1 for entry in entries if entry.has_header_code)
    total_no_owner = sum(1 for entry in entries if entry.status == "no-owner")
    total_no_owner_emitters = sum(1 for entry in entries if entry.status == "no-owner" and entry.emitter_uids)
    total_unclassified = sum(1 for entry in entries if entry.status == "unclassified")
    total_error = sum(1 for entry in entries if entry.status == "error")
    total_emits = sum(1 for entry in entries if entry.emitter_uids or entry.status in {"emits", "multiple-emitters", "coded"})
    total_emitters_no_code = sum(
        1 for entry in entries if entry.status in reconstructable_statuses and entry.emitter_uids and not entry.has_code
    )
    total_non_emits = sum(1 for entry in entries if entry.status in {"non-emits", "no-owner"} and not entry.emitter_uids)
    total_multiple_emitters = sum(1 for entry in entries if len(entry.emitter_uids) > 1)
    total_dead_ends = sum(1 for entry in entries if entry.status == "dead-end" or entry.dead_end_detail)
    total_owner_none = sum(1 for entry in entries if entry.owner_state == "none")
    total_owner_blank = sum(1 for entry in entries if entry.owner_state == "blank")
    total_owner_specified = sum(1 for entry in entries if entry.owner_state == "specified")
    total_owner_specified_multiple = sum(1 for entry in entries if entry.owner_state == "specified-multiple")
    return [
        f"Total_Type: {total_type}",
        f"Total_Reconstructable: {total_reconstructable}",
        f"Total_Not_Reconstructable: {total_not}",
        f"Total_Reconstructable_Routed: {total_routed}",
        f"Total_Reconstructed_Coded: {total_coded}",
        f"Total_Reconstructed_Header_Coded: {total_header_coded}",
        f"Total_Reconstructable_NoOwner: {total_no_owner}",
        f"Total_Reconstructable_NoOwner_Emitters: {total_no_owner_emitters}",
        f"Total_Reconstructable_Emits: {total_emits}",
        f"Total_Reconstructable_Emitters_NoCode: {total_emitters_no_code}",
        f"Total_Reconstructable_NonEmits: {total_non_emits}",
        f"Total_Reconstructable_MultipleEmitters: {total_multiple_emitters}",
        f"Owner_None: {total_owner_none}",
        f"Owner_Blank: {total_owner_blank}",
        f"Owner_Specified: {total_owner_specified}",
        f"Owner_SpecifiedMultiple: {total_owner_specified_multiple}",
        f"Total_DeadEnds: {total_dead_ends}",
        f"Total_Unclassified: {total_unclassified}",
        f"Total_Error: {total_error}",
    ]


def render_autogen_report(
    title: str,
    entries: list[AutogenReportEntry],
    command_context: CommandContext,
    refresh_source: str,
) -> str:
    lines = [
        *render_generated_markdown_header(command_context, refresh_source),
        "",
        f"# {title}",
        "",
        *autogen_report_stats(entries),
        "",
        "| UID | Status | Canonical Owner | Emitters | Position | Code | Header Code | Destination | Header Destination | Path | Detail |",
        "| --- | --- | --- | --- | ---: | --- | --- | --- | --- | --- | --- |",
    ]
    for entry in sorted(entries, key=lambda item: (item.status, item.path, item.uid)):
        owner = f"`{entry.canonical_owner}`" if entry.canonical_owner else ""
        emitters = ",".join(f"`{uid}`" for uid in entry.emitter_uids)
        position = entry.position
        code = "yes" if entry.has_code else "no"
        header_code = "yes" if entry.has_header_code else "no"
        destination = f"`{entry.destination}`" if entry.destination else ""
        header_destination = f"`{entry.header_destination}`" if entry.header_destination else ""
        lines.append(
            f"| {uid_link(entry.uid, entry.path)} | {entry.status} | {owner} | {emitters} | {position} | "
            f"{code} | {header_code} | {destination} | {header_destination} | `{entry.path}` | {entry.detail} |"
        )
    multiple_emitter_entries = [entry for entry in entries if len(entry.emitter_uids) > 1]
    owner_blank_entries = [entry for entry in entries if entry.owner_state == "blank"]
    owner_none_entries = [entry for entry in entries if entry.owner_state == "none"]
    dead_end_entries = [entry for entry in entries if entry.dead_end_detail]
    error_entries = [entry for entry in entries if entry.status == "error"]
    lines.extend(["", "## Multiple Emitters", ""])
    if multiple_emitter_entries:
        lines.extend(["| UID | Path | Emitter Targets | Position | Destination | Detail |", "| --- | --- | --- | ---: | --- | --- |"])
        for entry in sorted(multiple_emitter_entries, key=lambda item: (item.path, item.uid)):
            emitter_targets = []
            for emitter_uid, emitter_path in entry.emitter_targets:
                if emitter_path:
                    emitter_targets.append(uid_link(emitter_uid, emitter_path))
                else:
                    emitter_targets.append(f"`{emitter_uid}`")
            if not emitter_targets:
                emitter_targets = [f"`{uid}`" for uid in entry.emitter_uids]
            destination = f"`{entry.destination}`" if entry.destination else ""
            lines.append(
                f"| {uid_link(entry.uid, entry.path)} | `{entry.path}` | {', '.join(emitter_targets)} | "
                f"{entry.position} | {destination} | {entry.detail} |"
            )
    else:
        lines.append("_No multiple-emitter items._")
    lines.extend(["", "## Owner Blank", ""])
    if owner_blank_entries:
        lines.extend(["| UID | Status | Path | Emitters | Destination | Detail |", "| --- | --- | --- | --- | --- | --- |"])
        for entry in sorted(owner_blank_entries, key=lambda item: (item.path, item.uid)):
            emitters = ",".join(f"`{uid}`" for uid in entry.emitter_uids)
            destination = f"`{entry.destination}`" if entry.destination else ""
            lines.append(
                f"| {uid_link(entry.uid, entry.path)} | {entry.status} | `{entry.path}` | "
                f"{emitters} | {destination} | {entry.detail} |"
            )
    else:
        lines.append("_No blank-owner items._")
    lines.extend(["", "## Owner None", ""])
    if owner_none_entries:
        lines.extend(["| UID | Status | Path | Emitters | Destination | Detail |", "| --- | --- | --- | --- | --- | --- |"])
        for entry in sorted(owner_none_entries, key=lambda item: (item.path, item.uid)):
            emitters = ",".join(f"`{uid}`" for uid in entry.emitter_uids)
            destination = f"`{entry.destination}`" if entry.destination else ""
            lines.append(
                f"| {uid_link(entry.uid, entry.path)} | {entry.status} | `{entry.path}` | "
                f"{emitters} | {destination} | {entry.detail} |"
            )
    else:
        lines.append("_No NONE-owner items._")
    lines.extend(["", "## Dead Ends", ""])
    if dead_end_entries:
        lines.extend(["| UID | Path | Emitters | Detail |", "| --- | --- | --- | --- |"])
        for entry in sorted(dead_end_entries, key=lambda item: (item.path, item.uid)):
            emitters = ",".join(f"`{uid}`" for uid in entry.emitter_uids)
            lines.append(f"| {uid_link(entry.uid, entry.path)} | `{entry.path}` | {emitters} | {entry.dead_end_detail} |")
    else:
        lines.append("_No dead ends._")
    lines.extend(["", "## Errors", ""])
    if error_entries:
        lines.extend(["| UID | Path | Detail |", "| --- | --- | --- |"])
        for entry in sorted(error_entries, key=lambda item: (item.path, item.uid)):
            lines.append(f"| {uid_link(entry.uid, entry.path)} | `{entry.path}` | {entry.detail} |")
    else:
        lines.append("_No errors._")
    return "\n".join(lines) + "\n"


def autogen_report_entries(
    root: Path,
    config: configparser.ConfigParser,
    metadata_by_uid: dict[str, AutogenMetadata],
    roots_by_uid: dict[str, list[str]],
    status_by_uid: dict[str, str],
    dead_ends_by_uid: dict[str, list[str]],
    coded_uids: set[str],
    header_coded_uids: set[str],
) -> dict[str, list[AutogenReportEntry]]:
    reports: dict[str, list[AutogenReportEntry]] = {name: [] for name in AUTOGEN_TOP_LEVEL_REPORTS.values()}
    reports[AUTOGEN_FILE_REPORT] = []

    for uid, stored_path in config["files"].items():
        if is_projected_path_candidate(stored_path):
            destination = ""
            target = generated_cpp_destination(root, config, uid)
            if target is not None:
                destination = relative_path(root, target)
            has_header_code = any(
                uid in root_uids and child_uid in header_coded_uids
                for child_uid, root_uids in roots_by_uid.items()
            )
            header_destination = ""
            header_target = generated_header_destination(root, config, uid)
            if has_header_code and header_target is not None:
                header_destination = relative_path(root, header_target)
            status = "coded" if any(uid in root_uids and child_uid in coded_uids for child_uid, root_uids in roots_by_uid.items()) else "emits"
            projected = config[PROJECTED_PATH_STATUS_SECTION].get(uid, "blank")
            detail = "by-file generated root"
            if projected == "none":
                status = "not_reconstructable"
                detail = "reviewed non-standalone by-file page; no generated root"
            elif projected != "valid":
                status = "error"
            owner_raw = config[CANONICAL_OWNER_SECTION].get(uid, "").strip().upper()
            if owner_raw:
                owner_value = owner_raw
                owner_state = autogen_owner_state(owner_value, owner_raw, True)
            elif config.has_option(CANONICAL_OWNER_SECTION, uid):
                owner_value = ""
                owner_state = "blank"
            else:
                owner_value = "FILE"
                owner_state = "specified"
            reports[AUTOGEN_FILE_REPORT].append(
                AutogenReportEntry(
                    uid=uid,
                    path=stored_path,
                    folder="by-file",
                    status=status,
                    canonical_owner=owner_value,
                    owner_state=owner_state,
                    has_header_code=has_header_code,
                    destination=destination,
                    header_destination=header_destination,
                    detail=detail,
                )
            )

    for uid, metadata in metadata_by_uid.items():
        status = status_by_uid.get(uid, "unclassified")
        if uid in coded_uids:
            status = "coded"
        report_name = AUTOGEN_TOP_LEVEL_REPORTS.get(metadata.folder)
        if report_name is None:
            continue
        destination = ""
        header_destination = ""
        root_uids = roots_by_uid.get(uid, [])
        if root_uids:
            root_uid = root_uids[0]
            target = generated_cpp_destination(root, config, root_uid)
            if target is not None:
                destination = relative_path(root, target)
            header_target = generated_header_destination(root, config, root_uid)
            if metadata.header_code.strip() and header_target is not None:
                header_destination = relative_path(root, header_target)
        detail = ""
        error_text = config[AUTOGEN_ERROR_SECTION].get(autogen_error_key(uid), "")
        if status == "error" and error_text:
            detail = error_text
        reports[report_name].append(
            AutogenReportEntry(
                uid=uid,
                path=metadata.path,
                folder=metadata.folder,
                status=status,
                canonical_owner=metadata.canonical_owner,
                owner_state=autogen_owner_state(
                    metadata.canonical_owner,
                    metadata.canonical_owner_raw,
                    metadata.canonical_owner_seen,
                ),
                emitter_uids=tuple(metadata.emitter_uids),
                emitter_targets=tuple((emitter_uid, config["files"].get(emitter_uid, "")) for emitter_uid in metadata.emitter_uids),
                position=metadata.emitter_position_raw,
                has_code=bool(metadata.code.strip()),
                has_header_code=bool(metadata.header_code.strip()),
                destination=destination,
                header_destination=header_destination,
                detail=detail,
                dead_end_detail="; ".join(dead_ends_by_uid.get(uid, [])),
            )
        )
    return reports


def cleanup_old_coverage_placeholders(
    root: Path,
    apply: bool,
    backup_state: dict[str, Path | None],
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    for name in OLD_COVERAGE_PLACEHOLDERS:
        path = root / AUTO_GENERATED_RELATIVE_PATH / name
        if not path.exists():
            continue
        if path.stat().st_size == 0:
            actions.append(ScanAction("autogen_placeholder_delete", None, path, "old empty non-ag coverage placeholder"))
            if apply:
                backup_generated_file(root, path, backup_state)
                path.unlink()
        else:
            actions.append(ScanAction("autogen_placeholder_conflict", None, path, "old non-ag coverage placeholder is nonempty"))
    return actions


def normalize_stored_path(value: str) -> str:
    return value.replace("\\", "/").strip()


def parse_autogen_root_uids(value: str) -> set[str]:
    roots: set[str] = set()
    for item in re.split(r"[,;]", value or ""):
        uid = item.strip().upper()
        if re.fullmatch(r"[A-Z0-9]{6}", uid):
            roots.add(uid)
    return roots


def autogen_report_name_for_path(stored_path: str) -> str | None:
    folder = first_folder_from_relative(normalize_stored_path(stored_path))
    if folder == "by-file":
        return AUTOGEN_FILE_REPORT
    return AUTOGEN_TOP_LEVEL_REPORTS.get(folder)


def selected_incremental_autogen_targets(
    config: configparser.ConfigParser,
    roots_by_uid: dict[str, list[str]],
    affected_uids: set[str],
    affected_paths: set[str],
    previous_roots_by_uid: dict[str, set[str]],
    previous_paths_by_uid: dict[str, str],
) -> tuple[set[str], set[str]]:
    selected_roots: set[str] = set()
    selected_reports: set[str] = set()
    normalized_affected_paths = {normalize_stored_path(path) for path in affected_paths}
    uids_to_consider = set(affected_uids)

    uid_by_path = {normalize_stored_path(path): uid for uid, path in config["files"].items()}
    for rel in normalized_affected_paths:
        report_name = autogen_report_name_for_path(rel)
        if report_name is not None:
            selected_reports.add(report_name)
        uid = uid_by_path.get(rel)
        if uid:
            uids_to_consider.add(uid)

    for uid in uids_to_consider:
        stored_path = normalize_stored_path(config["files"].get(uid, ""))
        previous_path = normalize_stored_path(previous_paths_by_uid.get(uid, ""))
        for candidate_path in {stored_path, previous_path}:
            if not candidate_path:
                continue
            report_name = autogen_report_name_for_path(candidate_path)
            if report_name is not None:
                selected_reports.add(report_name)
            if is_projected_path_candidate(candidate_path):
                selected_roots.add(uid)
                selected_reports.add(AUTOGEN_FILE_REPORT)
        selected_roots.update(previous_roots_by_uid.get(uid, set()))
        selected_roots.update(roots_by_uid.get(uid, []))

    return selected_roots, selected_reports


def run_autogen_generation(
    root: Path,
    config: configparser.ConfigParser,
    apply: bool,
    use_dryrun_artifacts: bool = False,
    output_dryrun_artifacts: bool = False,
    command_context: CommandContext | None = None,
    refresh_source: str = "foreground-generated-refresh",
    affected_uids: set[str] | None = None,
    affected_paths: set[str] | None = None,
) -> list[ScanAction]:
    command_context = command_context or CommandContext()
    actions: list[ScanAction] = []
    backup_state: dict[str, Path | None] = {"backup_root": None}
    write_tasks: list[GeneratedWrite] = []
    previous_roots_by_uid: dict[str, set[str]] = {}
    previous_paths_by_uid: dict[str, str] = {}
    normalized_affected_uids = {uid.strip().upper() for uid in (affected_uids or set()) if re.fullmatch(r"[A-Z0-9]{6}", uid.strip().upper())}
    normalized_affected_paths = {normalize_stored_path(path) for path in (affected_paths or set()) if normalize_stored_path(path)}
    incremental = affected_uids is not None or affected_paths is not None
    if incremental:
        for uid in normalized_affected_uids:
            previous_roots_by_uid[uid] = parse_autogen_root_uids(config[AUTOGEN_ROOTS_SECTION].get(uid, ""))
            previous_paths_by_uid[uid] = config["files"].get(uid, "")
    metadata_by_uid, children_by_parent, roots_by_uid, status_by_uid, dead_ends_by_uid, registry_actions = rebuild_autogen_registry(root, config, apply, use_dryrun_artifacts)
    actions.extend(registry_actions)

    all_coded_uids: set[str] = set()
    all_header_coded_uids: set[str] = set()
    active_header_root_uids: set[str] = set()
    all_root_uids = sorted(
        {root_uid for root_uids in roots_by_uid.values() for root_uid in root_uids},
        key=lambda uid: config["files"].get(uid, ""),
    )
    selected_root_uids: set[str] | None = None
    selected_report_names: set[str] | None = None
    if incremental:
        selected_root_uids, selected_report_names = selected_incremental_autogen_targets(
            config,
            roots_by_uid,
            normalized_affected_uids,
            normalized_affected_paths,
            previous_roots_by_uid,
            previous_paths_by_uid,
        )
        actions.append(
            ScanAction(
                "autogen_incremental_scope",
                None,
                root,
                f"{len(selected_root_uids)} roots, {len(selected_report_names)} reports",
            )
        )
    for root_uid in all_root_uids:
        target = generated_cpp_destination(root, config, root_uid)
        header_target = generated_header_destination(root, config, root_uid)
        if target is None or header_target is None:
            if selected_root_uids is None or root_uid in selected_root_uids:
                actions.append(
                    ScanAction("autogen_root_invalid_projected_path", root_uid, root, "root has no valid generated destination")
                )
            continue
        if output_dryrun_artifacts:
            target = dryrun_artifact_path(target)
            header_target = dryrun_artifact_path(header_target)
        assembled, header_assembled, coded_uids, header_coded_uids = assemble_autogen_root(
            root_uid,
            metadata_by_uid,
            children_by_parent,
            status_by_uid,
            root,
            config,
            actions,
        )
        all_coded_uids.update(coded_uids)
        all_header_coded_uids.update(header_coded_uids)
        if header_assembled.strip():
            active_header_root_uids.add(root_uid)
        if selected_root_uids is not None and root_uid not in selected_root_uids:
            continue
        root_path = config["files"].get(root_uid, "")
        if assembled.strip():
            content = generated_cpp_content(root_uid, root_path, assembled, command_context, refresh_source)
            write_tasks.append(
                GeneratedWrite(
                    path=target,
                    text=content,
                    uid=root_uid,
                    create_action="autogen_cpp_create",
                    update_action="autogen_cpp_update",
                    noop_action="autogen_cpp_noop",
                    conflict_action="autogen_cpp_conflict",
                    backup_enabled=not output_dryrun_artifacts,
                )
            )
        else:
            actions.append(ScanAction("autogen_cpp_noop", root_uid, target, "no assembled code for root"))
        if header_assembled.strip():
            header_content = generated_header_content(
                root_uid,
                root_path,
                header_assembled,
                command_context,
                refresh_source,
            )
            write_tasks.append(
                GeneratedWrite(
                    path=header_target,
                    text=header_content,
                    uid=root_uid,
                    create_action="autogen_header_create",
                    update_action="autogen_header_update",
                    noop_action="autogen_header_noop",
                    conflict_action="autogen_header_conflict",
                    backup_enabled=not output_dryrun_artifacts,
                    metadata_refresh_action="autogen_header_metadata_refresh",
                )
            )
        else:
            actions.append(ScanAction("autogen_header_noop", root_uid, header_target, "no assembled header code for root"))

    if apply:
        for uid in all_coded_uids:
            if uid in config[AUTOGEN_STATUS_SECTION]:
                config[AUTOGEN_STATUS_SECTION][uid] = "coded"

    reports = autogen_report_entries(
        root,
        config,
        metadata_by_uid,
        roots_by_uid,
        status_by_uid,
        dead_ends_by_uid,
        all_coded_uids,
        all_header_coded_uids,
    )
    for name, entries in sorted(reports.items()):
        if selected_report_names is not None and name not in selected_report_names:
            continue
        report_path = root / AUTO_GENERATED_RELATIVE_PATH / name
        if output_dryrun_artifacts:
            report_path = dryrun_artifact_path(report_path)
        report_text = render_autogen_report(
            Path(name).stem.lstrip("-"),
            entries,
            command_context,
            refresh_source,
        )
        write_tasks.append(
            GeneratedWrite(
                path=report_path,
                text=report_text,
                uid=None,
                create_action="autogen_report_create",
                update_action="autogen_report_update",
                noop_action="autogen_report_noop",
                conflict_action="autogen_report_conflict",
                backup_enabled=not output_dryrun_artifacts,
            )
        )
    actions.extend(run_generated_write_batch(root, write_tasks, apply, backup_state))
    if not output_dryrun_artifacts:
        actions.extend(
            cleanup_stale_nexustk_generated_cpp(
                root,
                config,
                apply,
                backup_state,
                selected_root_uids=selected_root_uids,
                affected_uids=normalized_affected_uids,
                active_root_uids=set(all_root_uids),
                active_header_root_uids=active_header_root_uids,
            )
        )
    if not output_dryrun_artifacts and selected_root_uids is None and selected_report_names is None:
        actions.extend(cleanup_old_coverage_placeholders(root, apply, backup_state))
    save_metadata_cache(root)
    if backup_state.get("backup_root") is not None:
        actions.append(ScanAction("autogen_backup_create", None, backup_state["backup_root"], "changed generated files backed up"))
    return actions


def make_report_target_header(uid: str) -> str:
    return f"** TARGET-REPORT-UID:{uid.upper()} **"


def make_report_additional_uids_header(uids: tuple[str, ...]) -> str:
    return f"** TARGET-REPORT-ADDITIONAL-UIDS:{','.join(uids)} **"


def make_report_author_header(agent: str) -> str:
    return f"** AUTHOR-AGENT-ID:{agent.upper()} **"


def normalize_author_agent_specs(value: str) -> str:
    if value is None:
        raise ValueError("author agent specs are missing")
    raw = value.strip()
    if "\n" in raw or "\r" in raw:
        raise ValueError("author agent specs must be on one line")
    parts = [part.strip() for part in raw.split("|")]
    if len(parts) != 3 or any(not part for part in parts):
        raise ValueError("author agent specs must contain three non-empty pipe-separated fields")
    return " | ".join(parts)


def default_report_author_specs() -> str:
    return DEFAULT_AUTHOR_AGENT_SPECS


def make_report_author_specs_header(specs: str) -> str:
    return f"** AUTHOR-AGENT-SPECS: {normalize_author_agent_specs(specs)} **"


def make_report_validation_status_header(status: str) -> str:
    return f"** REPORT-VALIDATION-STATUS: {status.strip()} **"


def make_report_revalidation_reason_header(reason: str) -> str:
    return f"** REPORT-REVALIDATION-REASON: {reason.strip()} **"


def make_item_summary_line(value: str) -> str:
    return f"*** Item Summary: {value} | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***"


def make_nested_line(value: int) -> str:
    return f"*** Nested:{value} | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***"


def normalize_agent_id(value: str, allow_unknown: bool = False) -> str:
    if value is None:
        raise SystemExit("agent id is required")
    normalized = value.strip().upper()
    if allow_unknown and normalized == "UNKNOWN":
        return "unknown"
    if not AGENT_ID_RE.fullmatch(normalized):
        raise SystemExit(f"invalid agent id: {value}")
    return normalized


def central_agent_folder(agent: str) -> str:
    return "unknown" if agent.lower() == "unknown" else agent.upper()


def safe_report_filename(value: str) -> str:
    if value is None:
        raise SystemExit("report filename is required")
    raw = Path(value)
    if raw.is_absolute() or len(raw.parts) != 1 or raw.name != value:
        raise SystemExit(f"report filename must be a simple filename: {value}")
    if raw.suffix.lower() != ".md":
        raise SystemExit(f"report filename must be a Markdown file: {value}")
    return raw.name


def agent_research_dir(root: Path, agent: str) -> Path:
    return root / "tools" / "leaser" / "Agents" / f"Agent-{agent.upper()}" / "research"


def central_executed_dir(root: Path, agent: str) -> Path:
    return root / EXECUTED_RESEARCH_RELATIVE_PATH / central_agent_folder(agent)


def executed_root(root: Path) -> Path:
    return root / EXECUTED_RESEARCH_RELATIVE_PATH


def report_relpath(root: Path, path: Path) -> str:
    return relative_path(root, path).replace("\\", "/")


def file_sha256(path: Path) -> str:
    key = path_cache_key(path)
    stat = path.stat()
    cached = _FILE_HASH_CACHE.get(key)
    if cached is not None and cached[0] == stat.st_mtime_ns and cached[1] == stat.st_size:
        return cached[2]
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for chunk in iter(lambda: handle.read(1024 * 1024), b""):
            digest.update(chunk)
    value = digest.hexdigest()
    _FILE_HASH_CACHE[key] = (stat.st_mtime_ns, stat.st_size, value)
    return value


def unique_destination_path(directory: Path, filename: str) -> Path:
    candidate = directory / filename
    if not candidate.exists():
        return candidate
    stem = candidate.stem
    suffix = candidate.suffix
    counter = 2
    while True:
        numbered = directory / f"{stem}-{counter}{suffix}"
        if not numbered.exists():
            return numbered
        counter += 1


def parse_report_additional_uids(value: str) -> tuple[tuple[str, ...], tuple[str, ...]]:
    normalized: list[str] = []
    errors: list[str] = []
    seen: set[str] = set()
    for raw_token in value.split(","):
        token = raw_token.strip().upper()
        if not token:
            errors.append("additional target UID list contains an empty token")
            continue
        if re.fullmatch(r"[A-Z0-9]{6}", token) is None:
            errors.append(f"additional target UID is malformed: {token}")
            continue
        if token in seen:
            errors.append(f"additional target UID is duplicated: {token}")
            continue
        seen.add(token)
        normalized.append(token)
    return tuple(sorted(normalized)), tuple(errors)


def parse_report_headers(text: str) -> ReportHeaderMetadata:
    target_uid: str | None = None
    additional_target_uids: tuple[str, ...] = ()
    author_agent: str | None = None
    author_specs: str | None = None
    validation_status: str | None = None
    revalidation_reason: str | None = None
    errors: list[str] = []
    target_header_seen = False
    additional_header_seen = False

    for line in text.splitlines()[:REPORT_HEADER_SCAN_LINES]:
        stripped = line.strip()
        target_match = REPORT_TARGET_HEADER_RE.match(stripped)
        if target_match:
            if target_header_seen:
                errors.append("duplicate TARGET-REPORT-UID header")
            target_header_seen = True
            target_uid = target_match.group("uid").upper()
            continue
        if REPORT_TARGET_HEADER_ANY_RE.match(stripped):
            target_header_seen = True
            errors.append("malformed TARGET-REPORT-UID header")
            continue

        additional_match = REPORT_ADDITIONAL_UIDS_HEADER_RE.match(stripped)
        if additional_match:
            if additional_header_seen:
                errors.append("duplicate TARGET-REPORT-ADDITIONAL-UIDS header")
            additional_header_seen = True
            parsed_uids, parsed_errors = parse_report_additional_uids(additional_match.group("uids"))
            additional_target_uids = parsed_uids
            errors.extend(f"malformed TARGET-REPORT-ADDITIONAL-UIDS header: {error}" for error in parsed_errors)
            continue
        if REPORT_ADDITIONAL_UIDS_HEADER_ANY_RE.match(stripped):
            additional_header_seen = True
            errors.append("malformed TARGET-REPORT-ADDITIONAL-UIDS header")
            continue

        author_match = REPORT_AUTHOR_HEADER_RE.match(stripped)
        if author_match:
            if author_agent is not None:
                errors.append("duplicate AUTHOR-AGENT-ID header")
            author_agent = author_match.group("agent").upper()
            continue
        if REPORT_AUTHOR_HEADER_ANY_RE.match(stripped):
            errors.append("malformed AUTHOR-AGENT-ID header")
            continue

        specs_match = REPORT_AUTHOR_SPECS_HEADER_RE.match(stripped)
        if specs_match:
            if author_specs is not None:
                errors.append("duplicate AUTHOR-AGENT-SPECS header")
            try:
                author_specs = normalize_author_agent_specs(specs_match.group("specs"))
            except ValueError as exc:
                errors.append(f"malformed AUTHOR-AGENT-SPECS header: {exc}")
            continue
        if REPORT_AUTHOR_SPECS_HEADER_ANY_RE.match(stripped):
            errors.append("malformed AUTHOR-AGENT-SPECS header")
            continue

        status_match = REPORT_VALIDATION_STATUS_HEADER_RE.match(stripped)
        if status_match:
            if validation_status is not None:
                errors.append("duplicate REPORT-VALIDATION-STATUS header")
            status = status_match.group("status").strip().lower()
            if status != REPORT_VALIDATION_STATUS_NEEDS_REVALIDATION:
                errors.append(f"unsupported REPORT-VALIDATION-STATUS: {status}")
            validation_status = status
            continue
        if REPORT_VALIDATION_STATUS_HEADER_ANY_RE.match(stripped):
            errors.append("malformed REPORT-VALIDATION-STATUS header")
            continue

        reason_match = REPORT_REVALIDATION_REASON_HEADER_RE.match(stripped)
        if reason_match:
            if revalidation_reason is not None:
                errors.append("duplicate REPORT-REVALIDATION-REASON header")
            reason = reason_match.group("reason").strip()
            if not reason:
                errors.append("empty REPORT-REVALIDATION-REASON header")
            revalidation_reason = reason
            continue
        if REPORT_REVALIDATION_REASON_HEADER_ANY_RE.match(stripped):
            errors.append("malformed REPORT-REVALIDATION-REASON header")

    if target_uid and target_uid in additional_target_uids:
        errors.append(f"additional target UID is primary target: {target_uid}")
    if validation_status == REPORT_VALIDATION_STATUS_NEEDS_REVALIDATION and not revalidation_reason:
        errors.append("revalidation reason is missing")
    if revalidation_reason and validation_status != REPORT_VALIDATION_STATUS_NEEDS_REVALIDATION:
        errors.append("revalidation reason exists without needs-revalidation status")

    return ReportHeaderMetadata(
        target_uid=target_uid,
        additional_target_uids=additional_target_uids,
        author_agent=author_agent,
        author_specs=author_specs,
        validation_status=validation_status,
        revalidation_reason=revalidation_reason,
        errors=tuple(errors),
    )


def parse_report_history_events(text: str) -> tuple[list[dict], str | None]:
    lines = text.splitlines()
    begin_indexes = [index for index, line in enumerate(lines) if line.strip() == VALIDATOR_REPORT_HISTORY_BEGIN]
    end_indexes = [index for index, line in enumerate(lines) if line.strip() == VALIDATOR_REPORT_HISTORY_END]
    if not begin_indexes and not end_indexes:
        return [], None
    if len(begin_indexes) != 1 or len(end_indexes) != 1:
        return [], "malformed VALIDATOR-REPORT-HISTORY footer markers"
    begin = begin_indexes[0]
    end = end_indexes[0]
    if begin >= end:
        return [], "malformed VALIDATOR-REPORT-HISTORY footer marker order"
    events: list[dict] = []
    for line in lines[begin + 1 : end]:
        stripped = line.strip()
        if not stripped:
            continue
        match = VALIDATOR_REPORT_HISTORY_LINE_RE.match(stripped)
        if not match:
            return [], "malformed VALIDATOR-REPORT-HISTORY event line"
        try:
            data = json.loads(match.group("json"))
        except json.JSONDecodeError as exc:
            return [], f"malformed VALIDATOR-REPORT-HISTORY JSON: {exc}"
        if not isinstance(data, dict):
            return [], "malformed VALIDATOR-REPORT-HISTORY event payload"
        events.append(data)
    return events, None


def report_footer_error(text: str) -> str | None:
    _, error = parse_report_history_events(text)
    return error


def report_history_event_signature(event: dict) -> tuple[str, ...]:
    additional_uids = event.get("additional_uids", ())
    if not isinstance(additional_uids, (list, tuple)):
        additional_uids = (str(additional_uids),)
    return (
        str(event.get("command_id", "")),
        str(event.get("event", "")),
        str(event.get("uid", "")),
        str(event.get("old_uid", "")),
        str(event.get("new_uid", "")),
        str(event.get("issue", "")),
        str(event.get("source_path", "")),
        str(event.get("destination_path", "")),
        ",".join(str(uid) for uid in additional_uids),
    )


def make_report_history_event(
    command_context: CommandContext,
    event: str,
    uid: str | None = None,
    agent: str | None = None,
    issue: str | None = None,
    old_uid: str | None = None,
    new_uid: str | None = None,
    source_path: str | None = None,
    destination_path: str | None = None,
    details: str | None = None,
    additional_uids: tuple[str, ...] = (),
) -> dict:
    payload = {
        "timestamp": command_context.command_timestamp or datetime.now().astimezone().isoformat(timespec="seconds"),
        "command_id": command_context.command_id_display if command_context.command_id else "",
        "event": event,
    }
    optional = {
        "uid": uid,
        "agent": agent,
        "issue": issue,
        "old_uid": old_uid,
        "new_uid": new_uid,
        "source_path": source_path,
        "destination_path": destination_path,
        "details": details,
    }
    for key, value in optional.items():
        if value:
            payload[key] = str(value)
    if additional_uids:
        payload["additional_uids"] = list(additional_uids)
    return payload


def append_report_history_event(text: str, event: dict) -> str:
    events, error = parse_report_history_events(text)
    if error is not None:
        raise ValueError(error)
    signature = report_history_event_signature(event)
    if any(report_history_event_signature(existing) == signature for existing in events):
        return text

    newline = detect_newline(text)
    original_had_final_newline = text.endswith(("\n", "\r"))
    lines = text.splitlines()
    event_line = f"<!-- {json.dumps(event, sort_keys=True, separators=(',', ':'))} -->"
    if not events and VALIDATOR_REPORT_HISTORY_BEGIN not in [line.strip() for line in lines]:
        if lines and lines[-1] != "":
            lines.append("")
        lines.extend([VALIDATOR_REPORT_HISTORY_BEGIN, event_line, VALIDATOR_REPORT_HISTORY_END])
    else:
        end_index = next(index for index, line in enumerate(lines) if line.strip() == VALIDATOR_REPORT_HISTORY_END)
        lines.insert(end_index, event_line)
    new_text = newline.join(lines)
    if original_had_final_newline or text == "":
        new_text += newline
    return new_text


def report_file_metadata(
    root: Path,
    report_path: str,
    path: Path,
    force_refresh: bool = False,
) -> ReportFileMetadata:
    cached = None if force_refresh else valid_cached_file_entry(root, report_path, path)
    if cached is not None and {
        "report_header_uid",
        "report_header_additional_uids",
        "report_header_agent",
        "report_header_specs",
        "report_validation_status",
        "report_revalidation_reason",
        "report_header_errors",
        "report_sha256",
    }.issubset(cached) and isinstance(cached.get("report_header_additional_uids"), list):
        cached_additional_uids = cached.get("report_header_additional_uids", [])
        if not all(isinstance(uid, str) for uid in cached_additional_uids):
            cached = None
    if cached is not None:
        return ReportFileMetadata(
            header=ReportHeaderMetadata(
                target_uid=str(cached.get("report_header_uid") or "") or None,
                additional_target_uids=tuple(cached.get("report_header_additional_uids") or ()),
                author_agent=str(cached.get("report_header_agent") or "") or None,
                author_specs=str(cached.get("report_header_specs") or "") or None,
                validation_status=str(cached.get("report_validation_status") or "") or None,
                revalidation_reason=str(cached.get("report_revalidation_reason") or "") or None,
                errors=tuple(cached.get("report_header_errors") or ()),
            ),
            size=int(cached.get("size", 0)),
            sha256=str(cached.get("report_sha256", "")),
            read_error=None,
            footer_error=str(cached.get("report_footer_error") or "") or None,
        )

    try:
        data = path.read_bytes()
        stat = path.stat()
        sha256 = hashlib.sha256(data).hexdigest()
        text = data.decode("utf-8-sig")
    except (OSError, UnicodeDecodeError) as exc:
        try:
            size = path.stat().st_size
        except OSError:
            size = 0
        return ReportFileMetadata(
            header=ReportHeaderMetadata(),
            size=size,
            sha256="",
            read_error=str(exc),
        )

    key = path_cache_key(path)
    _FILE_HASH_CACHE[key] = (stat.st_mtime_ns, stat.st_size, sha256)
    _TEXT_CACHE[key] = (stat.st_mtime_ns, stat.st_size, text)

    header = parse_report_headers(text)
    footer_error = report_footer_error(text)
    update_metadata_cache_entry(
        root,
        report_path,
        path,
        {
            "_file_sha256": sha256,
            "report_header_uid": header.target_uid or "",
            "report_header_additional_uids": list(header.additional_target_uids),
            "report_header_agent": header.author_agent or "",
            "report_header_specs": header.author_specs or "",
            "report_validation_status": header.validation_status or "",
            "report_revalidation_reason": header.revalidation_reason or "",
            "report_header_errors": list(header.errors),
            "report_footer_error": footer_error or "",
            "report_sha256": sha256,
        },
    )
    return ReportFileMetadata(
        header=header,
        size=stat.st_size,
        sha256=sha256,
        read_error=None,
        footer_error=footer_error,
    )


def upsert_report_headers(
    text: str,
    target_uid: str | None,
    agent: str | None,
    specs: str | None = None,
    additional_target_uids: tuple[str, ...] = (),
    validation_status: str | None = None,
    revalidation_reason: str | None = None,
) -> str:
    newline = detect_newline(text)
    original_had_final_newline = text.endswith(("\n", "\r"))
    lines = text.splitlines()
    remaining: list[str] = []
    for index, line in enumerate(lines):
        stripped = line.strip()
        if index < REPORT_HEADER_SCAN_LINES and (
            REPORT_TARGET_HEADER_RE.match(stripped)
            or REPORT_ADDITIONAL_UIDS_HEADER_RE.match(stripped)
            or REPORT_AUTHOR_HEADER_RE.match(stripped)
            or REPORT_AUTHOR_SPECS_HEADER_RE.match(stripped)
            or REPORT_VALIDATION_STATUS_HEADER_RE.match(stripped)
            or REPORT_REVALIDATION_REASON_HEADER_RE.match(stripped)
        ):
            continue
        remaining.append(line)

    headers: list[str] = []
    if target_uid:
        headers.append(make_report_target_header(target_uid))
    if additional_target_uids:
        headers.append(make_report_additional_uids_header(tuple(sorted(additional_target_uids))))
    if agent:
        headers.append(make_report_author_header(agent))
    if specs:
        headers.append(make_report_author_specs_header(specs))
    if validation_status:
        headers.append(make_report_validation_status_header(validation_status))
        if revalidation_reason:
            headers.append(make_report_revalidation_reason_header(revalidation_reason))
    h1_index = next(
        (
            index
            for index, line in enumerate(remaining)
            if re.match(r"^#(?!#)\s+\S", line.strip())
        ),
        None,
    )
    if h1_index is None:
        new_lines = headers + remaining
    else:
        insert_at = h1_index + 1
        new_lines = remaining[:insert_at] + headers + remaining[insert_at:]
    new_text = newline.join(new_lines)
    if original_had_final_newline or text == "":
        new_text += newline
    return new_text


def clear_report_revalidation_headers(text: str) -> str:
    header = parse_report_headers(text)
    return upsert_report_headers(
        text,
        header.target_uid,
        header.author_agent,
        header.author_specs,
        header.additional_target_uids,
    )


def upsert_report_revalidation_headers(text: str, reason: str) -> str:
    header = parse_report_headers(text)
    return upsert_report_headers(
        text,
        header.target_uid,
        header.author_agent,
        header.author_specs,
        header.additional_target_uids,
        validation_status=REPORT_VALIDATION_STATUS_NEEDS_REVALIDATION,
        revalidation_reason=reason,
    )


def uid_from_report_path(config: configparser.ConfigParser, value: str) -> str | None:
    normalized = value.strip().strip("`").replace("\\", "/")
    if normalized.startswith("./"):
        normalized = normalized[2:]
    return uid_for_relative_path(config, normalized)


def detect_report_target_uid(
    root: Path,
    config: configparser.ConfigParser,
    path: Path,
    text: str,
) -> tuple[str | None, list[str]]:
    candidates: dict[str, str] = {}
    errors: list[str] = []
    header = parse_report_headers(text)
    if header.target_uid:
        candidates[header.target_uid] = "header"

    for line in text.splitlines()[:80]:
        line_match = REPORT_TARGET_UID_LINE_RE.match(line)
        if not line_match:
            continue
        value = line_match.group("value")
        for uid_match in UID_REF_RE.finditer(value):
            candidates[uid_match.group("uid").upper()] = "target-line"
        for uid_match in REPORT_BODY_UID_RE.finditer(value):
            uid = uid_match.group("uid").upper()
            if uid in config["files"]:
                candidates[uid] = "target-line"
        for path_match in REPORT_BODY_PATH_RE.finditer(value):
            uid = uid_from_report_path(config, path_match.group("path"))
            if uid:
                candidates[uid] = "target-path"

    filename_match = REPORT_FILENAME_UID_RE.match(path.name)
    if filename_match:
        uid = filename_match.group("uid").upper()
        if uid in config["files"]:
            candidates[uid] = "filename"

    if not candidates:
        return None, ["target_uid_missing: no target UID could be detected"]
    valid = {uid: source for uid, source in candidates.items() if uid in config["files"]}
    invalid = sorted(set(candidates) - set(valid))
    if invalid:
        errors.append(f"target_uid_unknown: {', '.join(invalid)}")
    if len(valid) > 1:
        detail = ", ".join(f"{uid} from {source}" for uid, source in sorted(valid.items()))
        return None, [f"target_uid_ambiguous: {detail}", *errors]
    uid = next(iter(valid))
    target_path = absolute_path(root, config["files"].get(uid, ""))
    if not target_path.exists():
        errors.append(f"target_path_missing: {config['files'].get(uid, '')}")
    return uid, errors


def remove_report_registry_path(config: configparser.ConfigParser, report_path: str) -> str | None:
    normalized = report_path.replace("\\", "/")
    uid = config[RESEARCH_REPORT_UID_SECTION].pop(normalized, None)
    config[RESEARCH_REPORT_AGENT_SECTION].pop(normalized, None)
    config[RESEARCH_REPORT_AGENT_SPECS_SECTION].pop(normalized, None)
    config[RESEARCH_REPORT_SIZE_SECTION].pop(normalized, None)
    config[RESEARCH_REPORT_SHA256_SECTION].pop(normalized, None)
    config[RESEARCH_REPORT_EXECUTED_AT_SECTION].pop(normalized, None)
    config[RESEARCH_REPORT_ORIGINAL_PATH_SECTION].pop(normalized, None)
    config[RESEARCH_REPORT_ERROR_SECTION].pop(normalized, None)
    config[RESEARCH_REPORT_ADDITIONAL_UIDS_SECTION].pop(normalized, None)
    if uid:
        sources = parse_reference_sources(config[RESEARCH_REPORTS_SECTION].get(uid, ""))
        if normalized in sources:
            sources.remove(normalized)
        if sources:
            config[RESEARCH_REPORTS_SECTION][uid] = format_reference_sources(sources)
        else:
            config[RESEARCH_REPORTS_SECTION].pop(uid, None)
    return uid


def add_report_registry_record(
    config: configparser.ConfigParser,
    record: ResearchReportRecord,
) -> None:
    remove_report_registry_path(config, record.path)
    sources = parse_reference_sources(config[RESEARCH_REPORTS_SECTION].get(record.uid, ""))
    sources.add(record.path)
    config[RESEARCH_REPORTS_SECTION][record.uid] = format_reference_sources(sources)
    config[RESEARCH_REPORT_UID_SECTION][record.path] = record.uid
    config[RESEARCH_REPORT_AGENT_SECTION][record.path] = record.agent
    config[RESEARCH_REPORT_AGENT_SPECS_SECTION][record.path] = record.agent_specs
    config[RESEARCH_REPORT_SIZE_SECTION][record.path] = str(record.size)
    config[RESEARCH_REPORT_SHA256_SECTION][record.path] = record.sha256
    config[RESEARCH_REPORT_EXECUTED_AT_SECTION][record.path] = record.executed_at
    if record.additional_uids:
        config[RESEARCH_REPORT_ADDITIONAL_UIDS_SECTION][record.path] = format_registered_additional_uids(
            record.additional_uids
        )
    if record.original_path:
        config[RESEARCH_REPORT_ORIGINAL_PATH_SECTION][record.path] = record.original_path
    else:
        config[RESEARCH_REPORT_ORIGINAL_PATH_SECTION].pop(record.path, None)
    config[RESEARCH_REPORT_ERROR_SECTION].pop(record.path, None)


def report_record_from_file(
    root: Path,
    path: Path,
    uid: str,
    agent: str,
    agent_specs: str | None = None,
    additional_uids: tuple[str, ...] = (),
    original_path: str = "",
    executed_at: str | None = None,
) -> ResearchReportRecord:
    if not agent_specs:
        raise ValueError("validated author agent specs are required")
    specs = normalize_author_agent_specs(agent_specs)
    report_path = report_relpath(root, path)
    metadata = report_file_metadata(root, report_path, path, force_refresh=True)
    if metadata.read_error:
        raise OSError(f"cannot read report metadata for {report_path}: {metadata.read_error}")
    return ResearchReportRecord(
        path=report_path,
        uid=uid,
        agent=agent.upper(),
        agent_specs=specs,
        size=metadata.size,
        sha256=metadata.sha256,
        executed_at=executed_at or datetime.now().isoformat(timespec="seconds"),
        additional_uids=tuple(sorted(additional_uids)),
        original_path=original_path,
    )


def set_report_error(config: configparser.ConfigParser, report_path: str, errors: list[str]) -> None:
    normalized = report_path.replace("\\", "/")
    if errors:
        config[RESEARCH_REPORT_ERROR_SECTION][normalized] = "; ".join(errors)
    else:
        config[RESEARCH_REPORT_ERROR_SECTION].pop(normalized, None)


def central_report_files(root: Path) -> list[Path]:
    base = executed_root(root)
    if not base.exists():
        return []
    invalidated = resolved_path(base / "invalidated")
    files: list[Path] = []
    for path in base.glob("*/*.md"):
        if not path.is_file():
            continue
        if path.name.lower().endswith("-removed.md"):
            continue
        try:
            resolved_path(path).relative_to(invalidated)
            continue
        except ValueError:
            pass
        if path.parent.name.lower() == "invalidated":
            continue
        files.append(path)
    return sorted(files)


def central_removed_report_archives(root: Path) -> list[Path]:
    base = executed_root(root)
    if not base.exists():
        return []
    return sorted(
        path
        for path in base.glob("*/*-removed.md")
        if path.is_file() and path.parent.name.lower() != "invalidated"
    )


def central_agent_from_path(root: Path, path: Path) -> str:
    try:
        relative = resolved_path(path).relative_to(resolved_path(executed_root(root)))
    except ValueError:
        return "unknown"
    if not relative.parts:
        return "unknown"
    folder = relative.parts[0]
    return "unknown" if folder.lower() == "unknown" else folder.upper()


def old_executed_report_files(root: Path) -> list[tuple[str, Path]]:
    sources: list[tuple[str, Path]] = []
    roots = [
        root / "tools" / "leaser" / "Agents",
        root / "archived",
    ]
    for base in roots:
        if not base.exists():
            continue
        for path in sorted(base.rglob("*.md")):
            normalized = path.as_posix()
            if "/research/executed/" not in normalized:
                continue
            match = re.search(r"Agent-([ABC][0-9]{3})/research/executed/", normalized, re.IGNORECASE)
            agent = match.group(1).upper() if match else "unknown"
            sources.append((agent, path))
    return sources


def table_cell(value: str) -> str:
    return value.replace("\n", " ").replace("|", "\\|")


def parse_registered_additional_uids(value: str) -> tuple[str, ...]:
    if not value.strip():
        raise ValueError("additional target UID registry value is empty")
    normalized: list[str] = []
    seen: set[str] = set()
    for raw_token in value.split(";"):
        token = raw_token.strip().upper()
        if not token:
            raise ValueError("additional target UID registry contains an empty token")
        if re.fullmatch(r"[A-Z0-9]{6}", token) is None:
            raise ValueError(f"additional target UID registry token is malformed: {token}")
        if token in seen:
            raise ValueError(f"additional target UID registry token is duplicated: {token}")
        seen.add(token)
        normalized.append(token)
    return tuple(sorted(normalized))


def format_registered_additional_uids(uids: tuple[str, ...]) -> str:
    return ";".join(sorted(uids))


def additional_uids_for_report(config: configparser.ConfigParser, report_path: str) -> tuple[str, ...]:
    normalized = report_path.replace("\\", "/")
    if normalized not in config[RESEARCH_REPORT_ADDITIONAL_UIDS_SECTION]:
        return ()
    return parse_registered_additional_uids(
        config[RESEARCH_REPORT_ADDITIONAL_UIDS_SECTION].get(normalized, "")
    )


def build_additional_report_paths_by_uid(
    config: configparser.ConfigParser,
) -> dict[str, tuple[str, ...]]:
    grouped: dict[str, set[str]] = {}
    for report_path in config[RESEARCH_REPORT_ADDITIONAL_UIDS_SECTION]:
        try:
            additional_uids = additional_uids_for_report(config, report_path)
        except ValueError:
            continue
        for uid in additional_uids:
            grouped.setdefault(uid, set()).add(report_path.replace("\\", "/"))
    return {uid: tuple(sorted(paths)) for uid, paths in grouped.items()}


def report_paths_for_uid(config: configparser.ConfigParser, uid: str) -> tuple[str, ...]:
    return tuple(sorted(parse_reference_sources(config[RESEARCH_REPORTS_SECTION].get(uid, ""))))


def build_direct_index_errors_by_report(
    config: configparser.ConfigParser,
) -> dict[str, tuple[str, ...]]:
    grouped: dict[str, list[str]] = {}
    for indexed_uid, source_text in config[RESEARCH_REPORTS_SECTION].items():
        for report_path in parse_reference_sources(source_text):
            registered_uid = config[RESEARCH_REPORT_UID_SECTION].get(report_path, "").strip().upper()
            if registered_uid != indexed_uid:
                grouped.setdefault(report_path, []).append(
                    f"direct_reverse_index_mismatch: {indexed_uid} != {registered_uid or '<missing>'}"
                )
    return {path: tuple(sorted(set(errors))) for path, errors in grouped.items()}


def all_report_paths_for_uid(
    config: configparser.ConfigParser,
    additional_paths_by_uid: dict[str, tuple[str, ...]],
    uid: str,
) -> tuple[str, ...]:
    return tuple(sorted(set(report_paths_for_uid(config, uid)) | set(additional_paths_by_uid.get(uid, ()))))


def report_timestamp_from_file(path: Path) -> str:
    return datetime.fromtimestamp(path.stat().st_mtime).isoformat(timespec="seconds")


def thinking_level_bucket_from_specs(specs: str) -> str:
    try:
        normalized = normalize_author_agent_specs(specs)
    except ValueError:
        return ""
    parts = [part.strip() for part in normalized.split("|")]
    if len(parts) != 3:
        return ""
    return TRACKER_THINKING_BUCKET_BY_LOWER.get(parts[2].lower(), "")


def research_tracker_report_records(
    root: Path,
    config: configparser.ConfigParser,
) -> list[ResearchReportRecord]:
    return list(collect_research_report_state(root, config).valid_records)


def research_report_records_by_uid(
    records: list[ResearchReportRecord],
) -> dict[str, tuple[ResearchReportRecord, ...]]:
    grouped: dict[str, list[ResearchReportRecord]] = {}
    for record in records:
        grouped.setdefault(record.uid, []).append(record)
    return {uid: tuple(items) for uid, items in grouped.items()}


def research_tracker_entries(
    config: configparser.ConfigParser,
    direct_records_by_uid: dict[str, tuple[ResearchReportRecord, ...]],
    additional_records_by_uid: dict[str, tuple[ResearchReportRecord, ...]] | None = None,
) -> list[ResearchTrackerEntry]:
    entries: list[ResearchTrackerEntry] = []
    require_b_reports = only_count_b_reports_for_coverage(config)
    additional_records_by_uid = additional_records_by_uid or {}
    for uid, stored_path in config["files"].items():
        completion = score_from_config(config, "completion", uid, stored_path)
        confidence = score_from_config(config, "confidence", uid, stored_path)
        if completion == -1 or confidence == -1:
            continue
        direct_records = direct_records_by_uid.get(uid, ())
        additional_records = additional_records_by_uid.get(uid, ())
        direct_paths = tuple(record.path for record in direct_records)
        additional_paths = tuple(record.path for record in additional_records)
        direct_coverage_records = tuple(
            record
            for record in direct_records
            if not require_b_reports or record.agent.upper().startswith("B")
        )
        additional_coverage_records = tuple(
            record
            for record in additional_records
            if not require_b_reports or record.agent.upper().startswith("B")
        )
        coverage_records_by_path = {
            record.path: record
            for record in (*direct_coverage_records, *additional_coverage_records)
        }
        all_records_by_path = {record.path: record for record in (*direct_records, *additional_records)}
        thinking_counts = tuple(
            (
                bucket,
                sum(1 for record in coverage_records_by_path.values() if record.thinking_level_bucket == bucket),
            )
            for bucket in TRACKER_THINKING_BUCKETS
        )
        agents = tuple(
            sorted(
                {
                    record.agent
                    for record in all_records_by_path.values()
                    if record.agent
                }
            )
        )
        timestamps = [
            record.executed_at
            for record in all_records_by_path.values()
            if record.executed_at
        ]
        entries.append(
            ResearchTrackerEntry(
                uid=uid,
                path=stored_path,
                folder=first_folder_from_relative(stored_path),
                completion=completion,
                confidence=confidence,
                reconstructable=parse_reconstructable_value(
                    config[RECONSTRUCTABLE_SECTION].get(uid, "")
                ),
                direct_report_paths=direct_paths,
                additional_report_paths=additional_paths,
                report_agents=agents,
                direct_coverage_report_paths=tuple(record.path for record in direct_coverage_records),
                additional_coverage_report_paths=tuple(record.path for record in additional_coverage_records),
                thinking_counts=thinking_counts,
                last_executed_at=max(timestamps) if timestamps else "",
            )
        )
    return entries


def coverage_percent(covered: int, total: int) -> str:
    if total <= 0:
        return "0.0%"
    return f"{covered * 100.0 / total:.1f}%"


EXECUTED_REPORT_SUBMISSION_WINDOWS: tuple[tuple[str, timedelta], ...] = (
    ("Last hour", timedelta(hours=1)),
    ("Last 3 hours", timedelta(hours=3)),
    ("Last 6 hours", timedelta(hours=6)),
    ("Last 12 hours", timedelta(hours=12)),
    ("Last 24 hours", timedelta(hours=24)),
    ("Last week", timedelta(days=7)),
)


REPORT_COUNT_CHANGE_WINDOWS: tuple[tuple[str, timedelta], ...] = (
    ("Last hour", timedelta(hours=1)),
    ("Last 6 hours", timedelta(hours=6)),
    ("Last 12 hours", timedelta(hours=12)),
    ("Last 24 hours", timedelta(hours=24)),
)


def parse_executed_report_timestamp(value: str) -> datetime | None:
    text = value.strip()
    if not text:
        return None
    if text.endswith("Z"):
        text = f"{text[:-1]}+00:00"
    try:
        parsed = datetime.fromisoformat(text)
    except ValueError:
        return None
    if parsed.tzinfo is not None:
        parsed = parsed.astimezone().replace(tzinfo=None)
    return parsed


def executed_report_submission_counts(config: configparser.ConfigParser) -> list[tuple[str, int]]:
    now = datetime.now()
    timestamps = [
        parsed
        for value in config[RESEARCH_REPORT_EXECUTED_AT_SECTION].values()
        if (parsed := parse_executed_report_timestamp(value)) is not None
    ]
    counts: list[tuple[str, int]] = []
    for label, window in EXECUTED_REPORT_SUBMISSION_WINDOWS:
        count = sum(1 for timestamp in timestamps if timedelta(0) <= now - timestamp <= window)
        counts.append((label, count))
    return counts


def report_change_event_key(timestamp: str, report_path: str, delta: int) -> str:
    digest = hashlib.sha1(f"{timestamp}|{report_path}|{delta}|{uuid.uuid4().hex}".encode("utf-8")).hexdigest()[:12]
    safe_timestamp = re.sub(r"[^0-9A-Za-z]", "", timestamp)
    return f"{safe_timestamp}_{digest}"


def add_report_change_event(
    config: configparser.ConfigParser,
    delta: int,
    uid: str,
    folder: str,
    report_path: str,
    timestamp: str | None = None,
) -> None:
    timestamp = timestamp or datetime.now().isoformat(timespec="seconds")
    event = {
        "timestamp": timestamp,
        "delta": delta,
        "uid": uid,
        "folder": folder or "unknown",
        "report_path": report_path.replace("\\", "/"),
        "reconstructable": parse_reconstructable_value(
            config[RECONSTRUCTABLE_SECTION].get(uid, "")
        ),
    }
    config[RESEARCH_REPORT_CHANGE_EVENTS_SECTION][report_change_event_key(timestamp, report_path, delta)] = json.dumps(
        event,
        sort_keys=True,
        separators=(",", ":"),
    )


def report_change_events(config: configparser.ConfigParser) -> list[tuple[datetime, int, str, str, str, str]]:
    events: list[tuple[datetime, int, str, str, str, str]] = []
    for value in config[RESEARCH_REPORT_CHANGE_EVENTS_SECTION].values():
        try:
            data = json.loads(value)
        except json.JSONDecodeError:
            continue
        if not isinstance(data, dict):
            continue
        timestamp = parse_executed_report_timestamp(str(data.get("timestamp", "")))
        if timestamp is None:
            continue
        try:
            delta = int(data.get("delta", 0))
        except (TypeError, ValueError):
            continue
        if delta == 0:
            continue
        uid = str(data.get("uid", "")).strip().upper()
        folder = str(data.get("folder", "") or "unknown")
        report_path = str(data.get("report_path", "")).replace("\\", "/")
        reconstructable = parse_reconstructable_value(str(data.get("reconstructable", "")))
        if reconstructable == "blank" and uid:
            reconstructable = parse_reconstructable_value(config[RECONSTRUCTABLE_SECTION].get(uid, ""))
        events.append((timestamp, delta, uid, folder, report_path, reconstructable))
    return sorted(events, key=lambda item: item[0])


def signed_count(value: int) -> str:
    return f"+{value}" if value >= 0 else str(value)


def report_count_change_rows(
    root: Path,
    config: configparser.ConfigParser,
) -> dict[str, list[tuple[str, int, int, int, int, int]]]:
    now = datetime.now()
    change_events = report_change_events(config)
    explicit_add_paths = {report_path for _, delta, _, _, report_path, _ in change_events if delta > 0 and report_path}
    report_events: list[tuple[datetime, int, str, str, str, str]] = list(change_events)
    for report_path, value in config[RESEARCH_REPORT_EXECUTED_AT_SECTION].items():
        normalized_report_path = report_path.replace("\\", "/")
        if normalized_report_path in explicit_add_paths:
            continue
        timestamp = parse_executed_report_timestamp(value)
        if timestamp is None:
            continue
        uid = config[RESEARCH_REPORT_UID_SECTION].get(report_path, "").strip().upper()
        folder = folder_for_uid(config, uid)
        reconstructable = parse_reconstructable_value(config[RECONSTRUCTABLE_SECTION].get(uid, ""))
        report_events.append((timestamp, 1, uid, folder, normalized_report_path, reconstructable))
    report_events.sort(key=lambda item: item[0])

    current_counts: dict[str, int] = {}
    executed_base = resolved_path(executed_root(root))
    for report_path, uid_value in config[RESEARCH_REPORT_UID_SECTION].items():
        path = absolute_path(root, report_path)
        try:
            relative = resolved_path(path).relative_to(executed_base)
        except ValueError:
            continue
        if not path.is_file() or not relative.parts or relative.parts[0].lower() == "invalidated":
            continue
        uid = uid_value.strip().upper()
        if uid:
            current_counts[uid] = current_counts.get(uid, 0) + 1

    rows_by_folder: dict[str, list[tuple[str, int, int, int, int, int]]] = {}
    for label, window in REPORT_COUNT_CHANGE_WINDOWS:
        start = now - window
        window_events = [event for event in report_events if start <= event[0] <= now]
        active_counts = dict(current_counts)
        for _, delta, uid, _, _, _ in reversed(window_events):
            if uid:
                active_counts[uid] = max(0, active_counts.get(uid, 0) - delta)
        rows: dict[str, list[int]] = {}
        for _, delta, uid, folder, _, reconstructable in window_events:
            row = rows.setdefault(folder, [0, 0, 0, 0, 0])
            row[0] += delta
            active_before = active_counts.get(uid, 0) if uid else 0
            if delta > 0:
                if reconstructable == "true":
                    row[3] += delta
                else:
                    row[4] += delta
                if active_before > 0:
                    row[2] += 1
                else:
                    row[1] += 1
            if uid:
                active_counts[uid] = max(0, active_before + delta)
        for folder, (total_delta, new_reports, already_covered, reconstructable, not_reconstructable) in rows.items():
            rows_by_folder.setdefault(folder, []).append(
                (label, total_delta, new_reports, already_covered, reconstructable, not_reconstructable)
            )

    active_folders = {
        folder
        for folder, rows in rows_by_folder.items()
        if any(
            label == "Last 24 hours"
            and (
                total_delta != 0
                or new_reports != 0
                or already_covered != 0
                or reconstructable != 0
                or not_reconstructable != 0
            )
            for label, total_delta, new_reports, already_covered, reconstructable, not_reconstructable in rows
        )
    }
    return {
        folder: [
            next(
                (row for row in rows_by_folder.get(folder, []) if row[0] == label),
                (label, 0, 0, 0, 0, 0),
            )
            for label, _ in REPORT_COUNT_CHANGE_WINDOWS
        ]
        for folder in sorted(active_folders)
    }


def render_report_count_changes(root: Path, config: configparser.ConfigParser) -> str:
    rows_by_folder = report_count_change_rows(root, config)
    if not rows_by_folder:
        return "_No report count changes in the last 24 hours._\n"
    lines: list[str] = []
    for folder, rows in rows_by_folder.items():
        lines.extend(
            [
                f"### `{folder}`",
                "",
                "| Time Window | Total Reports Delta | Reports Added To Previously Unreported Targets | Reports Added To Already Reported Targets | Reconstructable Additions | Not Reconstructable Additions |",
                "| --- | ---: | ---: | ---: | ---: | ---: |",
            ]
        )
        for label, total_delta, new_reports, already_covered, reconstructable, not_reconstructable in rows:
            lines.append(
                f"| {label} | {signed_count(total_delta)} | "
                f"{new_reports} | {already_covered} | "
                f"{reconstructable} | {not_reconstructable} |"
            )
        lines.append("")
    return "\n".join(lines).rstrip() + "\n"


def config_emitter_uids(config: configparser.ConfigParser, uid: str) -> list[str]:
    parsed = parse_emitter_uids_line(make_emitter_uids_line(config[EMITTER_UIDS_SECTION].get(uid, "")))
    if parsed is None:
        return []
    _, emitter_uids, ok = parsed
    return emitter_uids if ok else []


def is_empty_emitter_uid(config: configparser.ConfigParser, uid: str) -> bool:
    return (
        parse_reconstructable_value(config[RECONSTRUCTABLE_SECTION].get(uid, "")) == "true"
        and bool(config_emitter_uids(config, uid))
        and not config[RECONSTRUCTION_CODE_HASH_SECTION].get(uid, "").strip()
    )


def empty_emitter_file_entries(
    root: Path,
    config: configparser.ConfigParser,
) -> list[EmptyEmitterFileEntry]:
    emitters_by_root: dict[str, set[str]] = {}
    for uid, root_text in config[AUTOGEN_ROOTS_SECTION].items():
        if uid not in config["files"]:
            continue
        if parse_reconstructable_value(config[RECONSTRUCTABLE_SECTION].get(uid, "")) != "true":
            continue
        for root_uid in parse_autogen_root_uids(root_text):
            root_path = config["files"].get(root_uid, "")
            if not root_path or generated_cpp_destination(root, config, root_uid) is None:
                continue
            emitters_by_root.setdefault(root_uid, set()).add(uid)

    entries: list[EmptyEmitterFileEntry] = []
    for root_uid, emitter_uids in emitters_by_root.items():
        root_path = config["files"].get(root_uid, "")
        destination_path = generated_cpp_destination(root, config, root_uid)
        destination = relative_path(root, destination_path) if destination_path is not None else ""
        empty_count = sum(1 for uid in emitter_uids if is_empty_emitter_uid(config, uid))
        entries.append(
            EmptyEmitterFileEntry(
                root_uid=root_uid,
                root_path=root_path,
                destination=destination,
                total_emitters=len(emitter_uids),
                empty_emitters=empty_count,
            )
        )
    return sorted(
        entries,
        key=lambda entry: (
            -entry.empty_emitters,
            -entry.total_emitters,
            entry.root_path,
            entry.root_uid,
        ),
    )


def empty_emitter_file_row(entry: EmptyEmitterFileEntry) -> str:
    filled_emitters = entry.total_emitters - entry.empty_emitters
    return (
        f"| {uid_link(entry.root_uid, entry.root_path)} | "
        f"{entry.total_emitters} | {filled_emitters} | {entry.empty_emitters} | "
        f"{coverage_percent(filled_emitters, entry.total_emitters)} | "
        f"`{table_cell(entry.destination)}` | `{table_cell(entry.root_path)}` |"
    )


def empty_emitter_file_table(entries: list[EmptyEmitterFileEntry]) -> str:
    if not entries:
        return "_No reconstructable generated files with routed emitters._\n"
    lines = [
        "| File | Total Emitters | Filled | Marked Empty | Complete | Generated File | Path |",
        "| --- | ---: | ---: | ---: | ---: | --- | --- |",
    ]
    lines.extend(empty_emitter_file_row(entry) for entry in entries)
    return "\n".join(lines) + "\n"


def report_metadata_diagnostics(
    root: Path,
    config: configparser.ConfigParser,
    report_path: str,
    path: Path,
    metadata: ReportFileMetadata,
    registered: bool,
    target_exists_by_uid: dict[str, bool] | None = None,
    direct_index_errors_by_report: dict[str, tuple[str, ...]] | None = None,
) -> tuple[list[str], list[str]]:
    errors: list[str] = []
    revalidation_reasons: list[str] = []
    target_exists_by_uid = target_exists_by_uid if target_exists_by_uid is not None else {}
    direct_index_errors_by_report = (
        direct_index_errors_by_report
        if direct_index_errors_by_report is not None
        else build_direct_index_errors_by_report(config)
    )

    def add_error(error: str, revalidate: bool = False) -> None:
        if error not in errors:
            errors.append(error)
        if revalidate and error not in revalidation_reasons:
            revalidation_reasons.append(error)

    def target_path_exists(uid: str) -> bool:
        if uid not in target_exists_by_uid:
            stored_path = config["files"].get(uid, "")
            target_exists_by_uid[uid] = bool(stored_path) and absolute_path(root, stored_path).exists()
        return target_exists_by_uid[uid]

    if metadata.read_error is not None:
        return [f"read_error: {metadata.read_error}"], []
    if metadata.footer_error is not None:
        add_error(metadata.footer_error)
    for header_error in metadata.header.errors:
        add_error(
            header_error,
            "TARGET-REPORT-UID" in header_error
            or "TARGET-REPORT-ADDITIONAL-UIDS" in header_error
            or "additional target UID" in header_error,
        )
    header = metadata.header
    primary_header_broken = any("TARGET-REPORT-UID" in error for error in header.errors)
    additional_header_broken = any(
        "TARGET-REPORT-ADDITIONAL-UIDS" in error or "additional target UID" in error
        for error in header.errors
    )

    uid = config[RESEARCH_REPORT_UID_SECTION].get(report_path, "").strip().upper() if registered else ""
    if registered:
        if not uid:
            add_error("registry_uid_missing")
        elif uid not in config["files"]:
            reason = f"target_uid_unknown: {uid}"
            add_error(reason, True)
        elif not target_path_exists(uid):
            add_error(f"target_path_missing: {config['files'].get(uid, '')}", True)
        if not header.target_uid and not primary_header_broken:
            reason = "target_header_missing"
            add_error(reason, True)
        elif uid and header.target_uid is not None and header.target_uid != uid:
            reason = f"target_header_mismatch: {header.target_uid} != {uid}"
            add_error(reason, True)
        if uid and report_path not in parse_reference_sources(config[RESEARCH_REPORTS_SECTION].get(uid, "")):
            add_error(f"direct_reverse_index_missing: {uid}")
        for index_error in direct_index_errors_by_report.get(report_path, ()):
            add_error(index_error)
    else:
        if not header.target_uid and not primary_header_broken:
            reason = "target_header_missing"
            add_error(reason, True)
        elif header.target_uid and header.target_uid not in config["files"]:
            reason = f"target_uid_unknown: {header.target_uid}"
            add_error(reason, True)
        elif header.target_uid and not target_path_exists(header.target_uid):
            add_error(f"target_path_missing: {config['files'].get(header.target_uid, '')}", True)

    registered_additional_uids: tuple[str, ...] = ()
    additional_registry_present = report_path in config[RESEARCH_REPORT_ADDITIONAL_UIDS_SECTION]
    if registered and additional_registry_present:
        try:
            registered_additional_uids = additional_uids_for_report(config, report_path)
        except ValueError as exc:
            add_error(f"additional_target_registry_malformed: {exc}")
    if registered and not additional_header_broken:
        if header.additional_target_uids and not additional_registry_present:
            add_error("additional_target_registry_missing", True)
        elif not header.additional_target_uids and additional_registry_present:
            add_error("additional_target_registry_stale", True)
        elif header.additional_target_uids != registered_additional_uids:
            add_error("additional_target_registry_mismatch", True)

    if not additional_header_broken:
        for additional_uid in header.additional_target_uids:
            if additional_uid == header.target_uid:
                add_error(f"additional_target_uid_is_primary: {additional_uid}", True)
            elif additional_uid not in config["files"]:
                add_error(f"additional_target_uid_unknown: {additional_uid}", True)
            elif not target_path_exists(additional_uid):
                add_error(
                    f"additional_target_path_missing: {config['files'].get(additional_uid, '')}",
                    True,
                )

    agent = config[RESEARCH_REPORT_AGENT_SECTION].get(report_path, "").strip().upper() if registered else ""
    folder_agent = central_agent_from_path(root, path)
    if not header.author_agent:
        add_error("author_header_missing")
    elif registered and not agent:
        add_error("report_agent_registry_missing")
    elif registered and agent and header.author_agent.upper() != agent:
        add_error(f"author_header_mismatch: {header.author_agent} != {agent}")
    elif not registered and folder_agent.lower() != "unknown" and header.author_agent.upper() != folder_agent.upper():
        add_error(f"author_header_mismatch: {header.author_agent} != {folder_agent}")

    if not header.author_specs:
        add_error("author_specs_header_missing")
    else:
        bucket = thinking_level_bucket_from_specs(header.author_specs)
        if not bucket:
            add_error(f"unsupported_tracker_thinking_bucket: {header.author_specs}")
    if registered:
        stored_specs = config[RESEARCH_REPORT_AGENT_SPECS_SECTION].get(report_path, "")
        if not stored_specs:
            add_error("author_specs_registry_missing")
        else:
            try:
                normalized_stored_specs = normalize_author_agent_specs(stored_specs)
            except ValueError as exc:
                add_error(f"author_specs_registry_malformed: {exc}")
            else:
                if header.author_specs and normalized_stored_specs != header.author_specs:
                    add_error(f"author_specs_mismatch: {header.author_specs} != {normalized_stored_specs}")

    if header.validation_status == REPORT_VALIDATION_STATUS_NEEDS_REVALIDATION:
        reason = header.revalidation_reason or "needs-revalidation"
        add_error(f"needs-revalidation: {reason}")

    if registered:
        stored_size = config[RESEARCH_REPORT_SIZE_SECTION].get(report_path, "")
        if not stored_size:
            add_error("report_size_registry_missing")
        elif not stored_size.isdigit():
            add_error(f"report_size_registry_malformed: {stored_size}")
        elif int(stored_size) != metadata.size:
            add_error(f"size_changed: {stored_size} -> {metadata.size}")
        stored_hash = config[RESEARCH_REPORT_SHA256_SECTION].get(report_path, "")
        if not stored_hash:
            add_error("report_sha256_registry_missing")
        elif re.fullmatch(r"[0-9a-fA-F]{64}", stored_hash) is None:
            add_error(f"report_sha256_registry_malformed: {stored_hash}")
        elif metadata.sha256 and stored_hash.lower() != metadata.sha256.lower():
            add_error("sha256_changed")
    return errors, revalidation_reasons


def collect_research_report_state(
    root: Path,
    config: configparser.ConfigParser,
) -> ResearchReportState:
    valid_records: list[ResearchReportRecord] = []
    error_keys: set[tuple[str, str]] = set()
    error_lines: list[str] = []
    paths_with_current_errors: set[str] = set()
    registered_paths = {path.replace("\\", "/") for path in config[RESEARCH_REPORT_UID_SECTION]}
    central_path_map = {report_relpath(root, path): path for path in central_report_files(root)}
    central_paths = set(central_path_map)
    target_exists_by_uid: dict[str, bool] = {}
    direct_index_errors_by_report = build_direct_index_errors_by_report(config)

    def add_error(report_path: str, code: str, detail: str, current: bool = True) -> None:
        key = (report_path, code)
        if key in error_keys:
            return
        error_keys.add(key)
        if current:
            paths_with_current_errors.add(report_path)
        error_lines.append(detail)

    for report_path in sorted(registered_paths):
        if report_path not in central_paths:
            path = absolute_path(root, report_path)
            detail = "registered report file is missing" if not path.exists() else "registered report is outside the live central archive"
            add_error(report_path, detail, f"`{report_path}` {detail}.")
            continue
        path = central_path_map[report_path]
        metadata = report_file_metadata(root, report_path, path)
        diagnostics, _ = report_metadata_diagnostics(
            root,
            config,
            report_path,
            path,
            metadata,
            registered=True,
            target_exists_by_uid=target_exists_by_uid,
            direct_index_errors_by_report=direct_index_errors_by_report,
        )
        for diagnostic in diagnostics:
            add_error(report_path, diagnostic, f"`{report_path}` {diagnostic}.")
        if diagnostics:
            continue

        uid = config[RESEARCH_REPORT_UID_SECTION].get(report_path, "").strip().upper()
        agent = config[RESEARCH_REPORT_AGENT_SECTION].get(report_path, "").strip().upper()
        agent_specs = normalize_author_agent_specs(
            config[RESEARCH_REPORT_AGENT_SPECS_SECTION].get(report_path, "")
        )
        additional_uids = additional_uids_for_report(config, report_path)
        executed_at = config[RESEARCH_REPORT_EXECUTED_AT_SECTION].get(report_path, "") or report_timestamp_from_file(path)
        valid_records.append(
            ResearchReportRecord(
                path=report_path,
                uid=uid,
                agent=agent,
                agent_specs=agent_specs,
                size=metadata.size,
                sha256=metadata.sha256,
                executed_at=executed_at,
                additional_uids=additional_uids,
                original_path=config[RESEARCH_REPORT_ORIGINAL_PATH_SECTION].get(report_path, ""),
                validation_status=metadata.header.validation_status or "",
                revalidation_reason=metadata.header.revalidation_reason or "",
            )
        )

    for report_path in sorted(central_paths - registered_paths):
        path = central_path_map[report_path]
        metadata = report_file_metadata(root, report_path, path)
        diagnostics, _ = report_metadata_diagnostics(
            root,
            config,
            report_path,
            path,
            metadata,
            registered=False,
            target_exists_by_uid=target_exists_by_uid,
            direct_index_errors_by_report=direct_index_errors_by_report,
        )
        detail_suffix = f": {'; '.join(diagnostics)}" if diagnostics else ""
        add_error(
            report_path,
            "unregistered_central_report",
            f"`{report_path}` exists in central executed research but is not registered{detail_suffix}.",
        )

    for report_path, detail in sorted(config[RESEARCH_REPORT_ERROR_SECTION].items()):
        normalized = report_path.replace("\\", "/")
        if detail and normalized not in paths_with_current_errors:
            add_error(
                normalized,
                f"registry_error:{detail}",
                f"`{normalized}` registry error: {detail}.",
                current=False,
            )

    for report_path in sorted(config[RESEARCH_REPORT_ADDITIONAL_UIDS_SECTION]):
        normalized = report_path.replace("\\", "/")
        if normalized not in registered_paths:
            add_error(
                normalized,
                "additional_registry_unregistered",
                f"`{normalized}` has additional-target registry state but is not a registered report.",
            )

    valid_records.sort(key=lambda record: record.path)
    direct_grouped: dict[str, list[ResearchReportRecord]] = {}
    additional_grouped: dict[str, list[ResearchReportRecord]] = {}
    for record in valid_records:
        direct_grouped.setdefault(record.uid, []).append(record)
        for uid in record.additional_uids:
            additional_grouped.setdefault(uid, []).append(record)
    return ResearchReportState(
        valid_records=tuple(valid_records),
        errors=tuple(sorted(error_lines)),
        direct_records_by_uid={uid: tuple(records) for uid, records in direct_grouped.items()},
        additional_records_by_uid={uid: tuple(records) for uid, records in additional_grouped.items()},
        report_agent_by_path={record.path: record.agent for record in valid_records},
    )


def collect_research_tracker_errors(root: Path, config: configparser.ConfigParser) -> list[str]:
    return list(collect_research_report_state(root, config).errors)


def research_tracker_row(entry: ResearchTrackerEntry, include_thinking_columns: bool = False) -> str:
    direct_reports = (
        "<br>".join(f"`{table_cell(path)}`" for path in entry.direct_report_paths)
        if entry.direct_report_paths
        else ""
    )
    additional_reports = (
        "<br>".join(f"`{table_cell(path)}`" for path in entry.additional_report_paths)
        if entry.additional_report_paths
        else ""
    )
    agents = ", ".join(f"`{agent}`" for agent in entry.report_agents)
    last = entry.last_executed_at
    cells = [
        uid_link(entry.uid, entry.path),
        f"{entry.completion}/{entry.confidence}",
        f"{entry.combined:.1f}",
        entry.reconstructable,
        str(len(entry.direct_report_paths)),
        str(len(entry.additional_report_paths)),
        str(len(entry.all_report_paths)),
    ]
    if include_thinking_columns:
        counts = {bucket: 0 for bucket in TRACKER_THINKING_BUCKETS}
        counts.update(dict(entry.thinking_counts))
        cells.extend([str(counts["xHigh"]), str(counts["High"]), str(counts["Medium"])])
    cells.extend(
        [last, agents, f"`{table_cell(entry.path)}`", direct_reports, additional_reports]
    )
    return "| " + " | ".join(cells) + " |"


def research_tracker_table(entries: list[ResearchTrackerEntry], include_thinking_columns: bool = False) -> str:
    if not entries:
        return "_No files in this bucket._\n"
    if include_thinking_columns:
        lines = [
            "| UID | Score | Combined | Reconstructable | Direct Reports | Additional Reports | Total Reports | xHigh | High | Medium | Last Executed | Agents | Path | Direct Report Paths | Additional Report Paths |",
            "| --- | ---: | ---: | --- | ---: | ---: | ---: | ---: | ---: | ---: | --- | --- | --- | --- | --- |",
        ]
    else:
        lines = [
            "| UID | Score | Combined | Reconstructable | Direct Reports | Additional Reports | Total Reports | Last Executed | Agents | Path | Direct Report Paths | Additional Report Paths |",
            "| --- | ---: | ---: | --- | ---: | ---: | ---: | --- | --- | --- | --- | --- |",
        ]
    lines.extend(research_tracker_row(entry, include_thinking_columns) for entry in entries)
    return "\n".join(lines) + "\n"


def render_research_tracker(
    root: Path,
    config: configparser.ConfigParser,
    command_context: CommandContext,
    refresh_source: str,
) -> str:
    report_state = collect_research_report_state(root, config)
    entries = research_tracker_entries(
        config,
        report_state.direct_records_by_uid,
        report_state.additional_records_by_uid,
    )
    require_b_reports = only_count_b_reports_for_coverage(config)
    folders = sorted({entry.folder for entry in entries} | {directory.name for directory in by_directories(root)})
    covered = [entry for entry in entries if entry.covered]
    errors = list(report_state.errors)
    records_by_primary_folder: dict[str, list[ResearchReportRecord]] = {}
    for record in report_state.valid_records:
        records_by_primary_folder.setdefault(folder_for_uid(config, record.uid), []).append(record)

    lines = [
        *render_generated_markdown_header(command_context, refresh_source),
        "",
        "# ag-research-tracker",
        "",
        "## Summary",
        "",
        f"- Tracked scored files: {len(entries)}",
        f"- Covered files: {len(covered)}",
        f"- Not covered files: {len(entries) - len(covered)}",
        f"- Overall coverage: {coverage_percent(len(covered), len(entries))}",
        f"- Coverage report filter: {'B-agent reports only' if require_b_reports else 'all executed reports'}",
        "",
        "| Folder | Total | Covered | Coverage | Direct Only | Additional Only | Direct + Additional | Reconstructable Covered | Not Reconstructable Covered | B Reports | A Reports | C Reports | Unknown Reports | Additional Coverage Links |",
        "| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |",
    ]
    for folder in folders:
        folder_entries = [entry for entry in entries if entry.folder == folder]
        folder_covered = [entry for entry in folder_entries if entry.covered]
        recon = [entry for entry in folder_entries if entry.reconstructable == "true"]
        not_recon = [entry for entry in folder_entries if entry.reconstructable != "true"]
        recon_covered = [entry for entry in recon if entry.covered]
        not_recon_covered = [entry for entry in not_recon if entry.covered]
        direct_only = [entry for entry in folder_entries if entry.coverage_state == "direct_only"]
        additional_only = [entry for entry in folder_entries if entry.coverage_state == "additional_only"]
        direct_and_additional = [
            entry for entry in folder_entries if entry.coverage_state == "direct_and_additional"
        ]
        agent_counts = {"A": 0, "B": 0, "C": 0, "unknown": 0}
        for record in records_by_primary_folder.get(folder, []):
            agent = record.agent
            if agent and agent[0] in agent_counts:
                agent_counts[agent[0]] += 1
            else:
                agent_counts["unknown"] += 1
        additional_link_count = sum(
            len(entry.additional_coverage_report_paths) for entry in folder_entries
        )
        lines.append(
            f"| `{folder}` | {len(folder_entries)} | {len(folder_covered)} | "
            f"{coverage_percent(len(folder_covered), len(folder_entries))} | "
            f"{len(direct_only)} | {len(additional_only)} | {len(direct_and_additional)} | "
            f"{coverage_percent(len(recon_covered), len(recon))} | "
            f"{coverage_percent(len(not_recon_covered), len(not_recon))} | "
            f"{agent_counts['B']} | {agent_counts['A']} | {agent_counts['C']} | {agent_counts['unknown']} | "
            f"{additional_link_count} |"
        )

    lines.extend(["", "## Executed Reports Submitted", ""])
    for label, count in executed_report_submission_counts(config):
        lines.append(f"- {label}: {count}")

    lines.extend(["", "## Report Count Changes", ""])
    lines.append(render_report_count_changes(root, config))

    lines.extend(["", "## Files With Empty Emitters", ""])
    lines.append(empty_emitter_file_table(empty_emitter_file_entries(root, config)))

    for folder in folders:
        folder_entries = [entry for entry in entries if entry.folder == folder]
        not_covered_sort = lambda entry: (
            entry.combined,
            entry.completion,
            entry.confidence,
            entry.path,
        )
        covered_sort = lambda entry: (
            len(entry.all_report_paths),
            entry.last_executed_at,
            entry.path,
        )

        def bucket(state: str, reconstructable: bool) -> list[ResearchTrackerEntry]:
            selected = [
                entry
                for entry in folder_entries
                if entry.coverage_state == state
                and ((entry.reconstructable == "true") == reconstructable)
            ]
            return sorted(
                selected,
                key=not_covered_sort if state == "not_covered" else covered_sort,
                reverse=state != "not_covered",
            )

        lines.extend(
            [
                "",
                f"## {folder}",
                "",
                "### Not-Covered Files - Reconstructable",
                "",
                research_tracker_table(bucket("not_covered", True)),
                "### Additionally-Covered-Only Files - Reconstructable",
                "",
                research_tracker_table(bucket("additional_only", True), include_thinking_columns=True),
                "### Directly-Covered-Only Files - Reconstructable",
                "",
                research_tracker_table(bucket("direct_only", True), include_thinking_columns=True),
                "### Directly-And-Additionally-Covered Files - Reconstructable",
                "",
                research_tracker_table(bucket("direct_and_additional", True), include_thinking_columns=True),
                "### Not-Covered Files - Not Reconstructable",
                "",
                research_tracker_table(bucket("not_covered", False)),
                "### Additionally-Covered-Only Files - Not Reconstructable",
                "",
                research_tracker_table(bucket("additional_only", False), include_thinking_columns=True),
                "### Directly-Covered-Only Files - Not Reconstructable",
                "",
                research_tracker_table(bucket("direct_only", False), include_thinking_columns=True),
                "### Directly-And-Additionally-Covered Files - Not Reconstructable",
                "",
                research_tracker_table(bucket("direct_and_additional", False), include_thinking_columns=True),
            ]
        )

    lines.extend(["", "## Errors", ""])
    if errors:
        lines.extend(f"- {error}" for error in errors)
    else:
        lines.append("_No report tracking errors._")
    return "\n".join(lines) + "\n"


def run_research_tracker_generation(
    root: Path,
    config: configparser.ConfigParser,
    apply: bool,
    backup_state: dict[str, Path | None] | None = None,
    command_context: CommandContext | None = None,
    refresh_source: str = "foreground-generated-refresh",
) -> list[ScanAction]:
    command_context = command_context or CommandContext()
    state = backup_state if backup_state is not None else {"backup_root": None}
    actions = run_generated_write_batch(
        root,
        [
            GeneratedWrite(
                path=root / AUTO_GENERATED_RELATIVE_PATH / AG_RESEARCH_TRACKER_REPORT,
                text=render_research_tracker(root, config, command_context, refresh_source),
                uid=None,
                create_action="research_tracker_create",
                update_action="research_tracker_update",
                noop_action="research_tracker_noop",
                conflict_action="research_tracker_conflict",
            )
        ],
        apply,
        state,
    )
    save_metadata_cache(root)
    if backup_state is None and state.get("backup_root") is not None:
        actions.append(ScanAction("autogen_backup_create", None, state["backup_root"], "changed generated files backed up"))
    return actions


_MANUAL_MEMORY_COVERAGE_CACHE: dict[Path, tuple[dict[str, tuple[str, int]], set[str]]] = {}
_MANUAL_MEMORY_COVERAGE_ABSOLUTE_CACHE: dict[Path, tuple[dict[str, tuple[str, int]], set[str]]] = {}


def sanitize_memory_coverage_summary(value: str) -> str:
    summary = " ".join(value.strip().split())
    previous = None
    while previous != summary:
        previous = summary
        summary = MEMORY_SUMMARY_AUTO_PREFIX_RE.sub("", summary).strip()
    summary = MEMORY_SUMMARY_CONFIDENCE_PREFIX_RE.sub("", summary).strip()
    if summary.startswith("- "):
        summary = summary[2:].strip()
    return summary


def extract_manual_memory_summary(tail: str) -> str:
    match = MANUAL_MEMORY_STATUS_SUMMARY_RE.search(tail)
    if match:
        return sanitize_memory_coverage_summary(match.group("summary"))
    return sanitize_memory_coverage_summary(tail.strip(" :|"))


def memory_coverage_sort_key_from_stored_path(stored_path: str) -> tuple[bool, int, int, str]:
    normalized = stored_path.replace("\\", "/")
    filename = normalized.rsplit("/", 1)[-1]
    match = BY_MEMORY_RANGE_RE.match(filename)
    if match:
        start = int(match.group("start"), 16)
        end = int(match.group("end"), 16)
        return (False, start, -end, normalized)
    return (True, 0, 0, normalized)


def memory_coverage_absolute_defaults_from_report(path: Path) -> tuple[dict[str, tuple[str, int]], set[str]]:
    defaults: dict[str, tuple[str, int]] = {}
    ambiguous: set[str] = set()
    if not path.exists():
        return defaults, ambiguous

    try:
        lines = read_text(path).splitlines()
    except UnicodeDecodeError:
        return defaults, ambiguous

    for line in lines:
        match = MANUAL_MEMORY_ROW_RE.match(line)
        if not match:
            continue
        stored_path = match.group("path").replace("\\", "/")
        if stored_path.rsplit("/", 1)[-1].startswith("-"):
            continue
        indent = len(match.group("indent").replace("\t", "    "))
        summary = extract_manual_memory_summary(match.group("tail"))
        if stored_path in defaults:
            ambiguous.add(stored_path)
            continue
        defaults[stored_path] = (summary, indent)
    return defaults, ambiguous


def manual_memory_coverage_absolute_defaults(root: Path) -> tuple[dict[str, tuple[str, int]], set[str]]:
    key = path_cache_key(root)
    cached = _MANUAL_MEMORY_COVERAGE_ABSOLUTE_CACHE.get(key)
    if cached is not None:
        return cached
    path = root / "by-memory" / "-coverage-report.md"
    defaults, ambiguous = memory_coverage_absolute_defaults_from_report(path)
    _MANUAL_MEMORY_COVERAGE_ABSOLUTE_CACHE[key] = (defaults, ambiguous)
    return defaults, ambiguous


def manual_memory_coverage_defaults(root: Path) -> tuple[dict[str, tuple[str, int]], set[str]]:
    key = path_cache_key(root)
    cached = _MANUAL_MEMORY_COVERAGE_CACHE.get(key)
    if cached is not None:
        return cached
    absolute_defaults, ambiguous = manual_memory_coverage_absolute_defaults(root)
    sortable: list[tuple[tuple[bool, int, int, str], str, str, int]] = []
    for stored_path, (summary, indent) in absolute_defaults.items():
        sortable.append((memory_coverage_sort_key_from_stored_path(stored_path), stored_path, summary, indent))
    defaults: dict[str, tuple[str, int]] = {}
    previous_indent = 0
    for _, stored_path, summary, indent in sorted(sortable, key=lambda item: item[0]):
        defaults[stored_path] = (summary, indent - previous_indent)
        previous_indent = indent
    _MANUAL_MEMORY_COVERAGE_CACHE[key] = (defaults, ambiguous)
    return defaults, ambiguous


def desired_memory_coverage_metadata_defaults(
    root: Path,
    config: configparser.ConfigParser,
) -> dict[str, tuple[str | None, int | None]]:
    absolute_defaults, _ = manual_memory_coverage_absolute_defaults(root)
    sortable = [
        (memory_coverage_sort_key_from_stored_path(stored_path), uid, stored_path.replace("\\", "/"))
        for uid, stored_path in config["files"].items()
        if first_folder_from_relative(stored_path) == "by-memory"
        and not stored_path.replace("\\", "/").rsplit("/", 1)[-1].startswith("-")
        and score_from_config(config, "completion", uid, stored_path) != -1
        and score_from_config(config, "confidence", uid, stored_path) != -1
    ]
    defaults: dict[str, tuple[str | None, int | None]] = {}
    previous_indent = 0
    for _, uid, stored_path in sorted(sortable, key=lambda item: item[0]):
        if stored_path in absolute_defaults:
            summary, indent = absolute_defaults[stored_path]
            defaults[uid] = (summary, indent - previous_indent)
            previous_indent = indent
        else:
            current_delta = 0
            path = absolute_path(root, stored_path)
            if path.exists():
                try:
                    _, nested_value, _, has_nested = parse_memory_coverage_metadata(read_text(path))
                    if has_nested and nested_value is not None:
                        current_delta = nested_value
                except (OSError, UnicodeDecodeError):
                    current_delta = 0
            indent = max(0, previous_indent + current_delta)
            defaults[uid] = (None, current_delta)
            previous_indent = indent
    return defaults


def is_memory_coverage_metadata_doc(root: Path, path: Path) -> bool:
    try:
        relative = resolved_path(path).relative_to(resolved_path(root))
    except ValueError:
        return False
    return (
        len(relative.parts) == 2
        and relative.parts[0] == "by-memory"
        and relative.name.endswith(".md")
        and not relative.name.startswith("-")
    )


def parse_memory_coverage_metadata(text: str) -> tuple[str, int | None, bool, bool]:
    summary = ""
    nested: int | None = None
    has_summary = False
    has_nested = False
    for line in text.splitlines():
        summary_match = ITEM_SUMMARY_LINE_RE.match(line)
        if summary_match:
            summary = summary_match.group("value").strip()
            has_summary = True
            continue
        nested_match = NESTED_LINE_RE.match(line)
        if nested_match:
            raw = nested_match.group("value").strip()
            nested = int(raw) if raw not in {"", "-"} else 0
            has_nested = True
    return summary, nested, has_summary, has_nested


def ensure_memory_coverage_metadata_lines(
    text: str,
    uid: str,
    path: Path,
    root: Path,
) -> tuple[str, list[ScanAction]]:
    if not is_memory_coverage_metadata_doc(root, path):
        return text, []
    current_summary, current_nested, has_summary, has_nested = parse_memory_coverage_metadata(text)
    lines = text.splitlines()
    summary_line_count = 0
    nested_line_count = 0
    malformed_metadata = False
    for line in lines:
        if ITEM_SUMMARY_ANY_LINE_RE.match(line):
            summary_line_count += 1
            if not ITEM_SUMMARY_LINE_RE.match(line):
                malformed_metadata = True
        if NESTED_ANY_LINE_RE.match(line):
            nested_line_count += 1
            if not NESTED_LINE_RE.match(line):
                malformed_metadata = True
    malformed_metadata = malformed_metadata or summary_line_count > 1 or nested_line_count > 1

    summary = current_summary if has_summary else ""
    nested = current_nested
    if not has_nested or nested is None:
        nested = 0
    if has_summary and has_nested and current_summary == summary and current_nested == nested and not malformed_metadata:
        return text, []

    actions: list[ScanAction] = []
    newline = detect_newline(text)
    original_had_final_newline = text.endswith(("\n", "\r"))
    cleaned: list[str] = []
    for line in lines:
        if ITEM_SUMMARY_ANY_LINE_RE.match(line) or NESTED_ANY_LINE_RE.match(line):
            continue
        cleaned.append(line)

    insert_at = None
    for index, line in enumerate(cleaned):
        if line == RECONSTRUCTION_H_END_LINE:
            insert_at = index + 1
            break
    if insert_at is None:
        for index, line in enumerate(cleaned):
            if line == RECONSTRUCTION_CPP_END_LINE:
                insert_at = index + 1
                break
    if insert_at is None:
        insert_at = 0
        while insert_at < len(cleaned) and cleaned[insert_at].startswith("*** "):
            insert_at += 1
    cleaned[insert_at:insert_at] = [make_item_summary_line(summary), make_nested_line(nested)]
    new_text = newline.join(cleaned)
    if original_had_final_newline:
        new_text += newline
    detail = "inserted by-memory coverage metadata"
    action_name = "memory_coverage_metadata_insert"
    if summary_line_count or nested_line_count:
        detail = "updated by-memory coverage metadata"
        action_name = "memory_coverage_metadata_update"
    if malformed_metadata:
        detail += "; repaired malformed metadata line"
    actions.append(ScanAction(action_name, uid, path, detail))
    return new_text, actions


def run_by_memory_coverage_metadata_injection(
    root: Path,
    config: configparser.ConfigParser,
    apply: bool,
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    for uid, stored_path in sorted(config["files"].items(), key=lambda item: memory_coverage_sort_key_from_stored_path(item[1])):
        path = absolute_path(root, stored_path)
        if not is_memory_coverage_metadata_doc(root, path):
            continue
        if not path.exists():
            actions.append(
                ScanAction(
                    "memory_coverage_metadata_missing_file",
                    uid,
                    path,
                    "by-memory coverage metadata injection skipped; file is missing",
                )
            )
            continue
        try:
            text = read_text(path)
        except UnicodeDecodeError:
            actions.append(
                ScanAction(
                    "memory_coverage_metadata_read_error",
                    uid,
                    path,
                    "by-memory coverage metadata injection skipped; file is not valid UTF-8",
                )
            )
            continue
        new_text, file_actions = ensure_memory_coverage_metadata_lines(
            text,
            uid,
            path,
            root,
        )
        actions.extend(file_actions)
        if apply and new_text != text:
            write_text_atomic(path, new_text)
    return actions


def by_memory_entry_from_config(
    root: Path,
    config: configparser.ConfigParser,
    uid: str,
    stored_path: str,
) -> MemoryCoverageEntry | None:
    if first_folder_from_relative(stored_path) != "by-memory":
        return None
    path = absolute_path(root, stored_path)
    if path.name.startswith("-"):
        return None
    completion = score_from_config(config, "completion", uid, stored_path)
    confidence = score_from_config(config, "confidence", uid, stored_path)
    if completion == -1 or confidence == -1:
        return None
    errors: list[str] = []
    range_match = BY_MEMORY_RANGE_RE.match(path.name)
    start = end = None
    name = path.stem
    if range_match:
        start = int(range_match.group("start"), 16)
        end = int(range_match.group("end"), 16)
        name = range_match.group("name")
    else:
        errors.append("memory_range_unparseable")

    summary = ""
    nested = 0
    updated_at = ""
    if path.exists():
        try:
            cached = valid_cached_file_entry(root, stored_path, path)
            if cached is not None and {
                "item_summary",
                "nested",
                "has_item_summary",
                "has_nested",
            }.issubset(cached):
                summary = str(cached.get("item_summary", ""))
                try:
                    nested_value = int(cached.get("nested", 0))
                except (TypeError, ValueError):
                    nested_value = 0
                has_summary = bool(cached.get("has_item_summary"))
                has_nested = bool(cached.get("has_nested"))
            else:
                text = read_text(path)
                summary, nested_value, has_summary, has_nested = parse_memory_coverage_metadata(text)
                update_metadata_cache_entry(
                    root,
                    stored_path,
                    path,
                    {
                        "uid": uid,
                        "item_summary": summary,
                        "nested": nested_value if nested_value is not None else 0,
                        "has_item_summary": has_summary,
                        "has_nested": has_nested,
                    },
                )
            if nested_value is not None:
                nested = nested_value
            if not has_summary:
                errors.append("item_summary_missing")
            if not has_nested:
                errors.append("nested_missing")
        except UnicodeDecodeError:
            errors.append("read_error")
        updated_at = datetime.fromtimestamp(path.stat().st_mtime).strftime("%Y-%m-%d %H:%M:%S")
    else:
        errors.append("file_missing")

    return MemoryCoverageEntry(
        uid=uid,
        path=stored_path,
        start=start,
        end=end,
        name=name,
        completion=completion,
        confidence=confidence,
        reconstructable=parse_reconstructable_value(config[RECONSTRUCTABLE_SECTION].get(uid, "")),
        emits_code=bool(config[RECONSTRUCTION_CODE_HASH_SECTION].get(uid, "").strip()),
        summary=summary,
        nested_delta=nested,
        updated_at=updated_at,
        errors=tuple(errors),
    )


def memory_confidence_label(confidence: int) -> str:
    if confidence >= 90:
        return "very-strong"
    if confidence >= 80:
        return "strong"
    if confidence >= 60:
        return "medium"
    return "weak"


def render_by_memory_auto_coverage(
    root: Path,
    config: configparser.ConfigParser,
    command_context: CommandContext,
    refresh_source: str,
) -> str:
    entries = [
        entry for uid, stored_path in config["files"].items()
        if (entry := by_memory_entry_from_config(root, config, uid, stored_path)) is not None
    ]
    entries.sort(key=lambda entry: (
        entry.start is None,
        entry.start if entry.start is not None else 0,
        -(entry.end if entry.end is not None else 0),
        entry.path,
    ))
    reconstructable_count = sum(1 for entry in entries if entry.reconstructable == "true")
    not_reconstructable_count = len(entries) - reconstructable_count
    coded_count = sum(1 for entry in entries if entry.emits_code)
    error_entries = [entry for entry in entries if entry.errors]
    lines = [
        *render_generated_markdown_header(command_context, refresh_source),
        "",
        "# ag-coverage-report-by-memory",
        "",
        f"Total: {len(entries)}",
        f"Reconstructable: {reconstructable_count}",
        f"Not_Reconstructable: {not_reconstructable_count}",
        f"Emits_Code: {coded_count}",
        f"Errors: {len(error_entries)}",
        "",
        "## Items",
        "",
    ]
    indent_spaces = 0
    for entry in entries:
        indent_spaces = max(0, indent_spaces + entry.nested_delta)
        indent = " " * indent_spaces
        range_text = f"0x{entry.start:08x}-0x{entry.end:08x}" if entry.start is not None and entry.end is not None else ""
        status = "reconstructable" if entry.reconstructable == "true" else "not_reconstructable"
        lines.append(
            f"{indent}- {uid_link(entry.uid, entry.path)} {range_text} | emits_code:{str(entry.emits_code).lower()} | "
            f"{entry.name} : {status} : {entry.completion}% : {memory_confidence_label(entry.confidence)} : "
            f"updated {entry.updated_at} : {entry.summary}"
        )
    lines.extend(["", "## Errors", ""])
    if error_entries:
        for entry in error_entries:
            lines.append(f"- {uid_link(entry.uid, entry.path)}: {', '.join(entry.errors)}")
    else:
        lines.append("_No by-memory auto coverage errors._")
    return "\n".join(lines) + "\n"


def run_by_memory_auto_coverage_generation(
    root: Path,
    config: configparser.ConfigParser,
    apply: bool,
    backup_state: dict[str, Path | None] | None = None,
    command_context: CommandContext | None = None,
    refresh_source: str = "foreground-generated-refresh",
) -> list[ScanAction]:
    command_context = command_context or CommandContext()
    actions = run_by_memory_coverage_metadata_injection(root, config, apply)
    state = backup_state if backup_state is not None else {"backup_root": None}
    actions.extend(run_generated_write_batch(
        root,
        [
            GeneratedWrite(
                path=root / AUTO_GENERATED_RELATIVE_PATH / AG_COVERAGE_REPORT_BY_MEMORY,
                text=render_by_memory_auto_coverage(root, config, command_context, refresh_source),
                uid=None,
                create_action="memory_auto_coverage_create",
                update_action="memory_auto_coverage_update",
                noop_action="memory_auto_coverage_noop",
                conflict_action="memory_auto_coverage_conflict",
            )
        ],
        apply,
        state,
    ))
    save_metadata_cache(root)
    if backup_state is None and state.get("backup_root") is not None:
        actions.append(ScanAction("autogen_backup_create", None, state["backup_root"], "changed generated files backed up"))
    return actions


def score_from_config(
    config: configparser.ConfigParser,
    section: str,
    uid: str,
    stored_path: str,
) -> int:
    raw_value = config[section].get(uid)
    if raw_value is None:
        return default_score_for_relative_path(stored_path)
    try:
        value = int(raw_value)
    except ValueError:
        return default_score_for_relative_path(stored_path)
    return value if is_valid_score(value) else default_score_for_relative_path(stored_path)


def stats_entries_from_config(config: configparser.ConfigParser) -> list[StatsEntry]:
    entries: list[StatsEntry] = []
    for uid, stored_path in config["files"].items():
        folder = first_folder_from_relative(stored_path)
        entries.append(
            StatsEntry(
                uid=uid,
                path=stored_path,
                folder=folder,
                completion=score_from_config(config, "completion", uid, stored_path),
                confidence=score_from_config(config, "confidence", uid, stored_path),
                reconstructable=parse_reconstructable_value(
                    config[RECONSTRUCTABLE_SECTION].get(uid, "")
                ),
            )
        )
    return entries


def projected_path_entries_from_config(config: configparser.ConfigParser) -> list[ProjectedPathEntry]:
    entries: list[ProjectedPathEntry] = []
    for uid, stored_path in config["files"].items():
        if not is_projected_path_candidate(stored_path):
            continue
        projected_path = config[PROJECTED_PATH_SECTION].get(uid, "")
        normalized, status, error = validate_projected_path(projected_path)
        stored_status = config[PROJECTED_PATH_STATUS_SECTION].get(uid)
        if stored_status in {"blank", "valid", "invalid", "none"} and status == "blank" and projected_path:
            status = stored_status
        if status in {"valid", "none"}:
            continue
        detail = error if status == "invalid" else "missing PROPOSED_RECONSTRUCTION_PATH"
        entries.append(
            ProjectedPathEntry(
                uid=uid,
                status=status,
                projected_path=normalized if status == "valid" else projected_path,
                path=stored_path,
                detail=detail,
            )
        )
    return sorted(entries, key=lambda entry: (entry.status, entry.path, entry.uid))


def scored_entries(entries: list[StatsEntry]) -> list[StatsEntry]:
    return [
        entry for entry in entries
        if entry.completion != -1 and entry.confidence != -1
    ]


def markdown_stats_table(entries: list[StatsEntry], limit: int) -> str:
    if not entries:
        return "_No scored files._\n"

    lines = [
        "| UID | Completion | Confidence | Combined | Path |",
        "| --- | ---: | ---: | ---: | --- |",
    ]
    for entry in entries[:limit]:
        lines.append(format_stats_row(entry))
    return "\n".join(lines) + "\n"


def markdown_projected_path_table(config: configparser.ConfigParser) -> str:
    entries = projected_path_entries_from_config(config)
    if not entries:
        return "_All by-file documents have valid projected reconstruction paths or reviewed non-standalone dispositions._\n"

    lines = [
        "| UID | Status | Proposed Path | Path | Detail |",
        "| --- | --- | --- | --- | --- |",
    ]
    for entry in entries:
        projected_path = entry.projected_path if entry.projected_path else "(blank)"
        lines.append(
            f"| `{entry.uid}` | {entry.status} | `{projected_path}` | `{entry.path}` | {entry.detail} |"
        )
    return "\n".join(lines) + "\n"


def format_stats_row(entry: StatsEntry) -> str:
    return (
        f"| `{entry.uid}` | {entry.completion} | {entry.confidence} | "
        f"{entry.combined:.1f} | `{entry.path}` |"
    )


def parse_stats_row(line: str) -> StatsEntry | None:
    match = STATS_ROW_RE.match(line)
    if not match:
        return None
    path = match.group("path")
    return StatsEntry(
        uid=match.group("uid"),
        path=path,
        folder=first_folder_from_relative(path),
        completion=int(match.group("completion")),
        confidence=int(match.group("confidence")),
    )


def stats_entry_for_uid(config: configparser.ConfigParser, uid: str) -> StatsEntry | None:
    stored_path = config["files"].get(uid)
    if stored_path is None:
        return None
    return StatsEntry(
        uid=uid,
        path=stored_path,
        folder=first_folder_from_relative(stored_path),
        completion=score_from_config(config, "completion", uid, stored_path),
        confidence=score_from_config(config, "confidence", uid, stored_path),
        reconstructable=parse_reconstructable_value(
            config[RECONSTRUCTABLE_SECTION].get(uid, "")
        ),
    )


def stats_table_base_name(table_name: str) -> str:
    if table_name.endswith("_Not_Reconstructable"):
        return table_name.removesuffix("_Not_Reconstructable")
    if table_name.endswith("_Reconstructable"):
        return table_name.removesuffix("_Reconstructable")
    return table_name


def stats_table_bucket(table_name: str) -> str | None:
    if table_name.endswith("_Not_Reconstructable"):
        return "not_reconstructable"
    if table_name.endswith("_Reconstructable"):
        return "reconstructable"
    return None


def entry_matches_stats_bucket(entry: StatsEntry, bucket: str | None) -> bool:
    if bucket == "reconstructable":
        return entry.reconstructable == "true"
    if bucket == "not_reconstructable":
        return entry.reconstructable != "true"
    return True


def stats_limit_for_table(table_name: str, limits: StatsTableLimits) -> int:
    bucket = stats_table_bucket(table_name)
    if bucket == "not_reconstructable":
        return limits.not_reconstructable
    return limits.reconstructable


def stats_sort_key(entry: StatsEntry, table_name: str) -> tuple[float, int, int, str]:
    base_name = stats_table_base_name(table_name)
    if base_name == "Low_Completion":
        return (float(entry.completion), entry.confidence, 0, entry.path)
    if base_name == "Low_Confidence":
        return (float(entry.confidence), entry.completion, 0, entry.path)
    return (entry.combined, entry.completion, entry.confidence, entry.path)


def stats_score_key(entry: StatsEntry, table_name: str) -> tuple[float, int, int]:
    base_name = stats_table_base_name(table_name)
    if base_name == "Low_Completion":
        return (float(entry.completion), entry.confidence, 0)
    if base_name == "Low_Confidence":
        return (float(entry.confidence), entry.completion, 0)
    return (entry.combined, entry.completion, entry.confidence)


def generate_completion_stats_text(root: Path, config: configparser.ConfigParser) -> str:
    entries = stats_entries_from_config(config)
    scored = scored_entries(entries)
    ignored_count = len(entries) - len(scored)
    limits = stats_table_limits(config)
    folders = sorted(
        {entry.folder for entry in entries}
        | {directory.name for directory in by_directories(root)}
    )

    scored_reconstructable = [
        entry for entry in scored
        if entry.reconstructable == "true"
    ]
    scored_not_reconstructable = [
        entry for entry in scored
        if entry.reconstructable != "true"
    ]

    low_completion_reconstructable = sorted(
        scored_reconstructable,
        key=lambda entry: (entry.completion, entry.confidence, entry.path),
    )
    low_completion_not_reconstructable = sorted(
        scored_not_reconstructable,
        key=lambda entry: (entry.completion, entry.confidence, entry.path),
    )
    low_confidence_reconstructable = sorted(
        scored_reconstructable,
        key=lambda entry: (entry.confidence, entry.completion, entry.path),
    )
    low_confidence_not_reconstructable = sorted(
        scored_not_reconstructable,
        key=lambda entry: (entry.confidence, entry.completion, entry.path),
    )
    low_both_reconstructable = sorted(
        scored_reconstructable,
        key=lambda entry: (entry.combined, entry.completion, entry.confidence, entry.path),
    )
    low_both_not_reconstructable = sorted(
        scored_not_reconstructable,
        key=lambda entry: (entry.combined, entry.completion, entry.confidence, entry.path),
    )

    def paired_score_section(
        base_name: str,
        reconstructable_entries: list[StatsEntry],
        not_reconstructable_entries: list[StatsEntry],
    ) -> list[str]:
        return [
            f"## {base_name}_Reconstructable",
            "",
            "Lowest-scored files whose `RECONSTRUCTABLE` metadata is `true`.",
            "",
            markdown_stats_table(reconstructable_entries, limits.reconstructable),
            f"## {base_name}_Not_Reconstructable",
            "",
            "Lowest-scored files whose `RECONSTRUCTABLE` metadata is false, blank, or invalid.",
            "",
            markdown_stats_table(not_reconstructable_entries, limits.not_reconstructable),
        ]

    lines = [
        "# Auto Completion Stats",
        "",
        "Scores use `COMPLETION` and `CONFIDENCE` metadata from validator-scanned by-* Markdown files.",
        "`0` means unevaluated. `-1` means ignored and is excluded from low-score lists.",
        "`Combined` is the average of completion and confidence.",
        "Scored tables are split by `RECONSTRUCTABLE:true` versus every other reconstructable state.",
        "",
        "## Summary",
        "",
        f"- Tracked files: {len(entries)}",
        f"- Scored files: {len(scored)}",
        f"- Scored reconstructable files: {len(scored_reconstructable)}",
        f"- Scored not reconstructable/blank files: {len(scored_not_reconstructable)}",
        f"- Ignored files: {ignored_count}",
        f"- Reconstructable row limit per scored section: {limits.reconstructable}",
        f"- Not reconstructable row limit per scored section: {limits.not_reconstructable}",
        "",
        "## projected_path_completion",
        "",
        "By-file documents whose `PROPOSED_RECONSTRUCTION_PATH` is blank or invalid. `NONE` marks a reviewed non-standalone page and is excluded.",
        "",
        markdown_projected_path_table(config),
        *paired_score_section(
            "Low_Completion",
            low_completion_reconstructable,
            low_completion_not_reconstructable,
        ),
        *paired_score_section(
            "Low_Confidence",
            low_confidence_reconstructable,
            low_confidence_not_reconstructable,
        ),
        *paired_score_section(
            "Low_Both",
            low_both_reconstructable,
            low_both_not_reconstructable,
        ),
        "## By Folder",
        "",
    ]

    for folder in folders:
        folder_reconstructable_entries = [
            entry for entry in scored
            if entry.folder == folder and entry.reconstructable == "true"
        ]
        folder_not_reconstructable_entries = [
            entry for entry in scored
            if entry.folder == folder and entry.reconstructable != "true"
        ]
        folder_reconstructable_entries.sort(
            key=lambda entry: (entry.combined, entry.completion, entry.confidence, entry.path)
        )
        folder_not_reconstructable_entries.sort(
            key=lambda entry: (entry.combined, entry.completion, entry.confidence, entry.path)
        )
        lines.extend([
            f"### {folder}_Reconstructable",
            "",
            markdown_stats_table(folder_reconstructable_entries, limits.reconstructable),
            f"### {folder}_Not_Reconstructable",
            "",
            markdown_stats_table(folder_not_reconstructable_entries, limits.not_reconstructable),
        ])

    return "\n".join(lines)


def projected_path_stats_section(config: configparser.ConfigParser) -> str:
    return "\n".join(
        [
            "## projected_path_completion",
            "",
            "By-file documents whose `PROPOSED_RECONSTRUCTION_PATH` is blank or invalid. `NONE` marks a reviewed non-standalone page and is excluded.",
            "",
            markdown_projected_path_table(config).rstrip("\n"),
            "",
        ]
    )


def replace_projected_path_stats_section(text: str, config: configparser.ConfigParser) -> str:
    section_text = projected_path_stats_section(config).splitlines()
    lines = text.splitlines()
    original_had_final_newline = text.endswith(("\n", "\r"))
    newline = detect_newline(text)
    start = None
    for index, line in enumerate(lines):
        if line.strip() == "## projected_path_completion":
            start = index
            break

    if start is None:
        insert_at = next(
            (index for index, line in enumerate(lines) if line.strip() == "## Low_Completion_Reconstructable"),
            len(lines),
        )
        lines[insert_at:insert_at] = section_text
    else:
        end = start + 1
        while end < len(lines):
            if lines[end].startswith("## ") and lines[end].strip() != "## projected_path_completion":
                break
            end += 1
        lines[start:end] = section_text

    new_text = newline.join(lines)
    if original_had_final_newline:
        new_text += newline
    return new_text


def update_completion_stats(
    root: Path,
    config: configparser.ConfigParser,
    apply: bool,
) -> ScanAction:
    path = root / STATS_RELATIVE_PATH
    detail = "updated completion/confidence stats" if apply else "would update completion/confidence stats"
    if apply:
        write_text_atomic(path, generate_completion_stats_text(root, config))
    return ScanAction("stats_update", None, path, detail)


def update_projected_path_stats(
    root: Path,
    config: configparser.ConfigParser,
    apply: bool,
) -> ScanAction:
    path = root / STATS_RELATIVE_PATH
    if not path.exists():
        return ScanAction(
            "projected_stats_missing",
            None,
            path,
            "generated stats file does not exist; run --mode rescore --apply",
        )
    detail = "updated projected path completion section" if apply else "would update projected path completion section"
    if apply:
        text = read_text(path)
        new_text = replace_projected_path_stats_section(text, config)
        if new_text != text:
            write_text_atomic(path, new_text)
    return ScanAction("projected_stats_update", None, path, detail)


def update_stats_table_rows(
    rows: list[StatsEntry],
    entry: StatsEntry,
    table_name: str,
    limit: int,
) -> tuple[list[StatsEntry], str | None]:
    matching = [
        row for row in rows
        if row.uid == entry.uid or row.path == entry.path
    ]
    if not matching:
        return rows, None

    old_rows = sorted(rows, key=lambda row: stats_sort_key(row, table_name))
    old_last = old_rows[-1] if old_rows else None
    old_entry = next(
        (row for row in old_rows if row.uid == entry.uid or row.path == entry.path),
        None,
    )
    target_was_lowest = (
        old_last is not None
        and old_entry is not None
        and (old_last.uid == old_entry.uid or old_last.path == old_entry.path)
    )
    remaining = [
        row for row in rows
        if row.uid != entry.uid and row.path != entry.path
    ]
    sorted_remaining = sorted(remaining, key=lambda row: stats_sort_key(row, table_name))

    if entry.completion == -1 or entry.confidence == -1:
        return sorted_remaining, "remove"

    if (
        target_was_lowest
        and old_entry is not None
        and stats_score_key(entry, table_name) > stats_score_key(old_entry, table_name)
    ):
        return sorted_remaining, "remove"

    updated_rows = sorted_remaining + [entry]
    updated_rows.sort(key=lambda row: stats_sort_key(row, table_name))
    target_indexes = [
        index for index, row in enumerate(updated_rows)
        if row.uid == entry.uid
    ]
    if not target_indexes:
        return sorted_remaining, "remove"

    target_index = target_indexes[0]
    if target_index >= limit:
        return sorted_remaining[:limit], "remove"

    if old_last is not None and stats_score_key(entry, table_name) > stats_score_key(old_last, table_name):
        return sorted_remaining, "remove"

    return updated_rows[:limit], "update"


def update_stats_text_for_entry(
    text: str,
    entry: StatsEntry,
    stats_path: Path,
    limits: StatsTableLimits,
) -> tuple[str, list[ScanAction]]:
    lines = text.splitlines()
    original_had_final_newline = text.endswith(("\n", "\r"))
    newline = detect_newline(text)
    actions: list[ScanAction] = []
    changed = False
    matched_any = False
    current_table = ""
    i = 0

    while i < len(lines):
        line = lines[i]
        if line.startswith("## "):
            current_table = line[3:].strip()
        elif line.startswith("### "):
            current_table = line[4:].strip()

        if (
            line.strip() == "| UID | Completion | Confidence | Combined | Path |"
            and i + 1 < len(lines)
            and lines[i + 1].strip() == "| --- | ---: | ---: | ---: | --- |"
        ):
            rows_start = i + 2
            rows_end = rows_start
            rows: list[StatsEntry] = []
            while rows_end < len(lines):
                parsed = parse_stats_row(lines[rows_end])
                if parsed is None:
                    break
                rows.append(parsed)
                rows_end += 1

            table_entry = entry
            bucket = stats_table_bucket(current_table)
            if not entry_matches_stats_bucket(entry, bucket):
                table_entry = StatsEntry(
                    uid=entry.uid,
                    path=entry.path,
                    folder=entry.folder,
                    completion=-1,
                    confidence=-1,
                    reconstructable=entry.reconstructable,
                )

            updated_rows, action = update_stats_table_rows(
                rows,
                table_entry,
                current_table,
                stats_limit_for_table(current_table, limits),
            )
            if action is not None:
                matched_any = True
                replacement = (
                    [format_stats_row(row) for row in updated_rows]
                    if updated_rows
                    else ["_No scored files._"]
                )
                if updated_rows:
                    lines[rows_start:rows_end] = replacement
                    i = rows_start + len(replacement)
                else:
                    lines[i:rows_end] = replacement
                    i = i + len(replacement)
                changed = True
                actions.append(
                    ScanAction(
                        "stats_row_update" if action == "update" else "stats_row_remove",
                        entry.uid,
                        stats_path,
                        current_table,
                    )
                )
                continue

            i = rows_end
            continue

        i += 1

    if not matched_any:
        actions.append(
            ScanAction(
                "stats_incremental_noop",
                entry.uid,
                stats_path,
                "file is not present in generated stats lists",
            )
        )
        return text, actions

    if any(action.action == "stats_row_remove" for action in actions):
        actions.append(
            ScanAction(
                "stats_rescore_recommended",
                entry.uid,
                stats_path,
                "run full/documented/rescore occasionally after enough rows drop from generated lists",
            )
        )

    if not changed:
        return text, actions

    new_text = newline.join(lines)
    if original_had_final_newline:
        new_text += newline
    return new_text, actions


def update_completion_stats_incremental(
    root: Path,
    config: configparser.ConfigParser,
    uid: str,
    apply: bool,
) -> list[ScanAction]:
    stats_path = root / STATS_RELATIVE_PATH
    entry = stats_entry_for_uid(config, uid)
    if entry is None:
        return [
            ScanAction(
                "stats_incremental_skip",
                uid,
                stats_path,
                "UID is not present in validator.ini [files]",
            )
        ]

    if not stats_path.exists():
        return [
            ScanAction(
                "stats_incremental_missing",
                uid,
                stats_path,
                "generated stats file does not exist; run --mode rescore --apply",
            )
        ]

    text = read_text(stats_path)
    new_text, actions = update_stats_text_for_entry(
        text,
        entry,
        stats_path,
        stats_table_limits(config),
    )
    if new_text != text and apply:
        write_text_atomic(stats_path, new_text)
    return actions


def propagate_reference_updates_for_target(
    target_uid: str,
    root: Path,
    config: configparser.ConfigParser,
    apply: bool,
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    source_rels = parse_reference_sources(config["references"].get(target_uid, ""))
    if not source_rels:
        return actions

    for source_rel in sorted(source_rels):
        source_path = absolute_path(root, source_rel)
        if not source_path.exists():
            actions.append(
                ScanAction(
                    "reference_index_remove",
                    target_uid,
                    source_path,
                    "source file no longer exists",
                )
            )
            if apply:
                sources = parse_reference_sources(config["references"].get(target_uid, ""))
                sources.discard(source_rel)
                if sources:
                    config["references"][target_uid] = format_reference_sources(sources)
                else:
                    config["references"].pop(target_uid, None)
            continue

        if not is_under_by_directory(root, source_path):
            actions.append(
                ScanAction(
                    "reference_propagation_skip",
                    target_uid,
                    source_path,
                    "source is outside direct by-* folders",
                )
            )
            continue

        text = read_text(source_path)
        if target_uid not in collect_uid_references(text, first_line_uid(text)):
            actions.extend(update_reference_index_for_source(source_path, root, config, text, apply))
            continue

        actions.extend(update_uid_references(source_path, root, config, apply, update_index=True))
    return actions


def recheck_tmp_reference_errors(
    root: Path,
    config: configparser.ConfigParser,
    apply: bool,
    skip_sources: set[str],
    generated_order: list[str],
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    for source_rel in sorted(list(config[TMP_REFERENCE_SECTION].keys())):
        source_rel = source_rel.replace("\\", "/")
        if source_rel in skip_sources:
            continue

        source_path = absolute_path(root, source_rel)
        if not source_path.exists():
            actions.append(
                ScanAction(
                    "tmp_ref_source_missing",
                    None,
                    source_path,
                    "source file with unresolved TMP references no longer exists",
                )
            )
            if apply:
                config[TMP_REFERENCE_SECTION].pop(source_rel, None)
            continue

        if not is_under_by_directory(root, source_path):
            actions.append(
                ScanAction(
                    "tmp_ref_source_skip",
                    None,
                    source_path,
                    "source file with unresolved TMP references is outside direct by-* folders",
                )
            )
            continue

        actions.extend(
            update_uid_references(
                source_path,
                root,
                config,
                apply,
                update_index=True,
                generated_order=generated_order,
            )
        )
    return actions


def parallel_observation_prewarm(root: Path, targets: list[Path]) -> list[ScanAction]:
    if len(targets) < 2:
        return []
    actions: list[ScanAction] = []

    def read_one(path: Path) -> FileObservation:
        rel = relative_path(root, path)
        try:
            text = read_text(path)
        except (OSError, UnicodeDecodeError) as exc:
            return FileObservation(path=path, rel=rel, error=str(exc))

        uid = first_line_uid(text)
        item_summary = ""
        nested_value: int | None = None
        has_item_summary = False
        has_nested = False
        if is_memory_coverage_metadata_doc(root, path):
            item_summary, nested_value, has_item_summary, has_nested = parse_memory_coverage_metadata(text)

        autogen_metadata: AutogenMetadata | None = None
        autogen_actions: tuple[ScanAction, ...] = ()
        if is_autogen_metadata_doc(root, path):
            autogen_metadata, parsed_actions = parse_autogen_metadata(root, path, text)
            autogen_actions = tuple(parsed_actions)

        return FileObservation(
            path=path,
            rel=rel,
            uid=uid,
            item_summary=item_summary,
            nested=nested_value,
            has_item_summary=has_item_summary,
            has_nested=has_nested,
            autogen_metadata=autogen_metadata,
            autogen_actions=autogen_actions,
        )

    max_workers = min(8, len(targets))
    errors = 0
    with concurrent.futures.ThreadPoolExecutor(max_workers=max_workers) as executor:
        observations = list(executor.map(read_one, targets))

    for observation in observations:
        if observation.error:
            errors += 1
            actions.append(ScanAction("parallel_observation_error", None, observation.path, observation.error))
            continue
        if is_memory_coverage_metadata_doc(root, observation.path):
            update_metadata_cache_entry(
                root,
                observation.rel,
                observation.path,
                {
                    "uid": observation.uid or "",
                    "item_summary": observation.item_summary,
                    "nested": observation.nested if observation.nested is not None else 0,
                    "has_item_summary": observation.has_item_summary,
                    "has_nested": observation.has_nested,
                },
            )
        if is_autogen_metadata_doc(root, observation.path):
            update_metadata_cache_entry(
                root,
                observation.rel,
                observation.path,
                {
                    "uid": observation.uid or "",
                    "autogen_metadata_present": observation.autogen_metadata is not None,
                    "autogen_metadata": autogen_metadata_to_cache(observation.autogen_metadata),
                    "autogen_actions": scan_actions_to_cache(root, observation.autogen_actions),
                },
            )
    save_metadata_cache(root)
    detail = f"preloaded {len(targets) - errors} files; errors {errors}"
    actions.insert(0, ScanAction("parallel_observation", None, root, detail))
    return actions


def summarize(actions: list[ScanAction]) -> dict[str, int]:
    counts: dict[str, int] = {}
    for action in actions:
        counts[action.action] = counts.get(action.action, 0) + 1
    return counts


def print_actions(actions: list[ScanAction], root: Path, verbose: bool) -> None:
    printed_by_action: dict[str, int] = {}
    suppressed_by_action: dict[str, int] = {}
    for action in actions:
        if not verbose and action.action == "ok":
            continue
        if not verbose:
            printed = printed_by_action.get(action.action, 0)
            if printed >= DEFAULT_ACTION_DETAIL_LIMIT:
                suppressed_by_action[action.action] = suppressed_by_action.get(action.action, 0) + 1
                continue
            printed_by_action[action.action] = printed + 1
        uid = action.uid or "------"
        print(f"{action.action:12} {uid} {relative_path(root, action.path)} {action.detail}".rstrip())
    if verbose:
        return
    for action_name, count in sorted(suppressed_by_action.items()):
        print(
            f"{action_name:12} ------ <suppressed> "
            f"{count} more rows; use --verbose for full detail"
        )


def migration_source_path(doc_path: Path, use_existing_dryrun: bool) -> Path:
    dryrun_path = dryrun_artifact_path(doc_path)
    if use_existing_dryrun and dryrun_path.exists():
        return dryrun_path
    return doc_path


def scan_file_for_migration_dryrun(
    doc_path: Path,
    source_path: Path,
    root: Path,
    config: configparser.ConfigParser,
    generated_order: list[str],
    artifact_paths: set[Path],
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    text = read_text(source_path)
    uid = first_line_uid(text)
    rel = relative_path(root, doc_path)
    damaged_uid = uid is None and DAMAGED_UID_LINE_RE.match(first_line(text)) is not None
    uid_status = "ok"

    restored_uid = uid_for_relative_path(config, rel)
    if uid is not None and restored_uid is not None and restored_uid != uid:
        uid = restored_uid
        uid_status = "restore_damaged"
    elif uid is None:
        if restored_uid is not None:
            uid = restored_uid
            uid_status = "restore_damaged" if damaged_uid else "restore_missing"
        else:
            uid = next_uid(config["state"]["last_used_uid"])
            config["state"]["last_used_uid"] = uid
            generated_order.append(uid)
            uid_status = "replace_damaged" if damaged_uid else "insert_missing"

    assert uid is not None
    try:
        if base36_to_int(uid) > base36_to_int(config["state"]["last_used_uid"]):
            config["state"]["last_used_uid"] = uid
            actions.append(ScanAction("last_uid_advance", uid, doc_path, "advanced from existing UID header"))
    except ValueError:
        pass

    new_text, completion, confidence, projected_path_value, header_actions = ensure_metadata_header(
        text,
        uid,
        doc_path,
        root,
        config,
        uid_status,
    )
    if uid_status == "ok":
        actions.append(ScanAction("ok", uid, doc_path, "UID header exists"))
    actions.extend(header_actions)

    output_path = dryrun_artifact_path(doc_path)
    artifact_paths.add(output_path)
    output_existed = output_path.exists()
    old_output = read_text(output_path) if output_existed else None
    if old_output != new_text:
        write_text_atomic(output_path, new_text)
        action = "migration_dryrun_update" if output_existed else "migration_dryrun_create"
        actions.append(ScanAction(action, uid, output_path, f"from {relative_path(root, source_path)}"))
    else:
        actions.append(ScanAction("migration_dryrun_noop", uid, output_path, "unchanged"))

    old_path = config["files"].get(uid)
    if old_path != rel:
        detail = "new UID mapping" if old_path is None else f"was {old_path}"
        actions.append(ScanAction("path_update", uid, doc_path, detail))
        config["files"][uid] = rel

    if completion is not None:
        completion_value = str(completion)
        if config["completion"].get(uid) != completion_value:
            actions.append(ScanAction("completion_update", uid, doc_path, completion_value))
            config["completion"][uid] = completion_value

    if confidence is not None:
        confidence_value = str(confidence)
        if config["confidence"].get(uid) != confidence_value:
            actions.append(ScanAction("confidence_update", uid, doc_path, confidence_value))
            config["confidence"][uid] = confidence_value

    actions.extend(
        update_projected_path_tracking(
            root,
            config,
            uid,
            doc_path,
            rel,
            old_path,
            projected_path_value,
            True,
            sync_generated=False,
        )
    )
    canonical_owner, owner_parse_actions = parse_canonical_owner_metadata(root, doc_path, new_text)
    actions.extend(owner_parse_actions)
    actions.extend(update_canonical_owner_registry(root, config, uid, doc_path, canonical_owner, True))
    autogen_metadata, autogen_parse_actions = parse_autogen_metadata(root, doc_path, new_text)
    actions.extend(autogen_parse_actions)
    actions.extend(update_autogen_registry_for_metadata(root, config, autogen_metadata, doc_path, True))
    return actions


def render_migration_dryrun_report(actions: list[ScanAction], root: Path, artifact_paths: set[Path]) -> str:
    lines = [
        "# Autogen Owner/Emitter Migration Dry Run",
        "",
        f"Root: `{root}`",
        "",
        "## Summary",
        "",
    ]
    for name, count in sorted(summarize(actions).items()):
        lines.append(f"- `{name}`: {count}")
    lines.extend(["", "## Artifacts", ""])
    for path in sorted(artifact_paths, key=lambda item: str(item).lower()):
        lines.append(f"- `{relative_path(root, path)}`")
    lines.extend(["", "## Actions", ""])
    lines.append("| Action | UID | Path | Detail |")
    lines.append("| --- | --- | --- | --- |")
    for action in actions:
        uid = action.uid or "------"
        detail = action.detail.replace("|", "\\|")
        lines.append(f"| `{action.action}` | `{uid}` | `{relative_path(root, action.path)}` | {detail} |")
    return "\n".join(lines) + "\n"


def write_migration_manifest(root: Path, ini: Path, artifact_paths: set[Path]) -> None:
    merged_artifacts = {str(path) for path in artifact_paths}
    if MIGRATION_DRYRUN_MANIFEST.exists():
        try:
            existing = json.loads(MIGRATION_DRYRUN_MANIFEST.read_text(encoding="utf-8"))
            if isinstance(existing, dict):
                existing_artifacts = existing.get("artifacts", [])
                if isinstance(existing_artifacts, list):
                    merged_artifacts.update(item for item in existing_artifacts if isinstance(item, str))
        except (OSError, json.JSONDecodeError):
            pass
    data = {
        "tool": "validator_background.py",
        "mode": "migrate-autogen --dry-run",
        "created_at": datetime.now().isoformat(timespec="seconds"),
        "root": str(root),
        "ini": str(ini),
        "artifacts": sorted(merged_artifacts, key=str.lower),
    }
    write_json_atomic(data, MIGRATION_DRYRUN_MANIFEST)


def clear_legacy_autogen_config_sections(config: configparser.ConfigParser) -> None:
    config[AUTOGEN_PARENT_SECTION].clear()
    config[AUTOGEN_PARENT_POSITION_SECTION].clear()
    config[AUTOGEN_CHILDREN_SECTION].clear()
    config[AUTOGEN_ROOT_SECTION].clear()


def run_migration_dryrun(args, root: Path, ini: Path, lock_path: Path) -> int:
    dry_ini = dryrun_config_path(ini)
    source_ini = dry_ini if args.use_existing_dryrun and dry_ini.exists() else ini
    config = load_config(source_ini)
    targets = all_markdown_files(root)
    generated_order: list[str] = []
    actions: list[ScanAction] = []
    artifact_paths: set[Path] = set()

    for doc_path in targets:
        source_path = migration_source_path(doc_path, args.use_existing_dryrun)
        try:
            actions.extend(
                scan_file_for_migration_dryrun(
                    doc_path,
                    source_path,
                    root,
                    config,
                    generated_order,
                    artifact_paths,
                )
            )
        except UnicodeDecodeError as exc:
            actions.append(ScanAction("read_error", None, doc_path, str(exc)))

    clear_legacy_autogen_config_sections(config)
    autogen_actions = run_autogen_generation(
        root,
        config,
        True,
        use_dryrun_artifacts=True,
        output_dryrun_artifacts=True,
    )
    actions.extend(autogen_actions)
    for action in autogen_actions:
        if str(action.path).endswith(".dryrun"):
            artifact_paths.add(action.path)

    artifact_paths.add(dry_ini)
    artifact_paths.add(MIGRATION_DRYRUN_REPORT)
    artifact_paths.add(MIGRATION_DRYRUN_MANIFEST)
    write_config_atomic(config, dry_ini)
    write_text_atomic(MIGRATION_DRYRUN_REPORT, render_migration_dryrun_report(actions, root, artifact_paths))
    write_migration_manifest(root, dry_ini, artifact_paths)

    print(f"root: {root}")
    print(f"ini: {ini}")
    print(f"dryrun ini: {dry_ini}")
    print(f"lock: {lock_path}")
    print("mode: migrate-autogen")
    print("dry-run artifacts: True")
    print(f"use existing dryrun: {args.use_existing_dryrun}")
    print(f"scanned markdown files: {len(targets)}")
    print(f"artifacts: {len(artifact_paths)}")
    for name, count in sorted(summarize(actions).items()):
        print(f"{name}: {count}")
    if args.verbose:
        print_actions(actions, root, True)
    print(f"migration dry-run report: {MIGRATION_DRYRUN_REPORT}")
    return 0


def run_migration_apply(args, root: Path, ini: Path, lock_path: Path) -> int:
    config = load_config(ini)
    targets = all_markdown_files(root)
    generated_order: list[str] = []
    actions: list[ScanAction] = []

    for path in targets:
        actions.extend(scan_file(path, root, config, generated_order, True))
    clear_legacy_autogen_config_sections(config)
    actions.extend(run_autogen_generation(root, config, True))
    actions.append(update_completion_stats(root, config, True))
    write_config_atomic(config, ini)

    print(f"root: {root}")
    print(f"ini: {ini}")
    print(f"lock: {lock_path}")
    print("mode: migrate-autogen")
    print("apply: True")
    print(f"scanned markdown files: {len(targets)}")
    print(f"last used UID: {config['state']['last_used_uid']}")
    for name, count in sorted(summarize(actions).items()):
        print(f"{name}: {count}")
    if args.verbose:
        print_actions(actions, root, True)
    return 0


def run_clear_dryrun_files(args, root: Path, ini: Path, lock_path: Path) -> int:
    actions: list[ScanAction] = []
    if not MIGRATION_DRYRUN_MANIFEST.exists():
        actions.append(ScanAction("dryrun_manifest_missing", None, MIGRATION_DRYRUN_MANIFEST, "nothing to clear"))
    else:
        try:
            data = json.loads(MIGRATION_DRYRUN_MANIFEST.read_text(encoding="utf-8"))
            raw_artifacts = data.get("artifacts", [])
            if not isinstance(raw_artifacts, list):
                raw_artifacts = []
        except (OSError, json.JSONDecodeError) as exc:
            raw_artifacts = []
            actions.append(ScanAction("dryrun_manifest_invalid", None, MIGRATION_DRYRUN_MANIFEST, str(exc)))

        for raw_path in sorted((item for item in raw_artifacts if isinstance(item, str)), reverse=True):
            path = Path(raw_path)
            allowed = str(path).endswith(".dryrun") or resolved_path(path) == resolved_path(MIGRATION_DRYRUN_MANIFEST)
            if not allowed:
                actions.append(ScanAction("dryrun_clear_skip", None, path, "manifest path is not a dryrun artifact"))
                continue
            if not path.exists():
                actions.append(ScanAction("dryrun_clear_missing", None, path, "already absent"))
                continue
            actions.append(ScanAction("dryrun_clear_delete", None, path, "manifest artifact"))
            if args.apply:
                path.unlink()

    print(f"root: {root}")
    print(f"ini: {ini}")
    print(f"lock: {lock_path}")
    print("mode: clear-dryrun-files")
    print(f"apply: {args.apply}")
    for name, count in sorted(summarize(actions).items()):
        print(f"{name}: {count}")
    if args.verbose:
        print_actions(actions, root, True)
    if not args.apply:
        print("dry run only; pass --apply to delete manifest-listed dryrun artifacts")
    return 0


def run_migrate_autogen(args, root: Path, ini: Path, lock_path: Path) -> int:
    if args.dry_run and args.apply:
        raise SystemExit("--dry-run and --apply are mutually exclusive for --mode migrate-autogen")
    if not args.dry_run and not args.apply:
        raise SystemExit("--mode migrate-autogen requires --dry-run or --apply")
    if args.use_existing_dryrun and not args.dry_run:
        raise SystemExit("--use-existing-dryrun only applies with --mode migrate-autogen --dry-run")
    if args.dry_run:
        return run_migration_dryrun(args, root, ini, lock_path)
    return run_migration_apply(args, root, ini, lock_path)


def reconstruction_h_migration_base(ini: Path) -> Path:
    return ini.parent / "validator_migrations" / "reconstruction_h"


def migration_bytes_sha256(data: bytes) -> str:
    return hashlib.sha256(data).hexdigest()


def write_bytes_atomic(path: Path, data: bytes) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.NamedTemporaryFile("wb", delete=False, dir=path.parent) as handle:
        handle.write(data)
        temporary = Path(handle.name)
    try:
        temporary.replace(path)
    except Exception:
        temporary.unlink(missing_ok=True)
        raise


def append_json_line_durable(path: Path, payload: dict) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    encoded = (json.dumps(payload, sort_keys=True) + "\n").encode("utf-8")
    with path.open("ab") as handle:
        handle.write(encoded)
        handle.flush()
        os.fsync(handle.fileno())


def migration_line_content(line: bytes) -> bytes:
    return line.rstrip(b"\r\n")


def stage_reconstruction_h_bytes(data: bytes) -> tuple[bytes, bytes, int, str, str | None]:
    bom = b"\xef\xbb\xbf"
    bom_length = len(bom) if data.startswith(bom) else 0
    payload = data[bom_length:]
    try:
        payload.decode("utf-8")
    except UnicodeDecodeError as exc:
        return data, b"", -1, "invalid", f"not valid UTF-8: {exc}"

    newline = b"\r\n" if b"\r\n" in payload else b"\n"
    newline_name = "CRLF" if newline == b"\r\n" else "LF"
    lines = payload.splitlines(keepends=True)
    cpp_end = RECONSTRUCTION_CPP_END_LINE.encode("ascii")
    h_begin = RECONSTRUCTION_H_BEGIN_LINE.encode("ascii")
    h_end = RECONSTRUCTION_H_END_LINE.encode("ascii")
    h_prefix = RECONSTRUCTION_H_PREFIX.encode("ascii")
    contents = [migration_line_content(line) for line in lines]
    cpp_end_indexes = [index for index, line in enumerate(contents) if line == cpp_end]
    h_begin_indexes = [index for index, line in enumerate(contents) if line == h_begin]
    h_end_indexes = [index for index, line in enumerate(contents) if line == h_end]
    h_prefixed_indexes = [index for index, line in enumerate(contents) if line.startswith(h_prefix)]

    if len(cpp_end_indexes) != 1:
        return data, b"", -1, "invalid", "expected exactly one RECONSTRUCTION_CPP CODE:END line"
    if h_prefixed_indexes:
        valid = (
            len(h_begin_indexes) == 1
            and len(h_end_indexes) == 1
            and len(h_prefixed_indexes) == 2
            and h_begin_indexes[0] == cpp_end_indexes[0] + 1
            and h_end_indexes[0] > h_begin_indexes[0]
        )
        if not valid:
            return data, b"", -1, "invalid", "malformed or misplaced RECONSTRUCTION_H CODE block"
        return data, b"", -1, "already-valid", None

    cpp_index = cpp_end_indexes[0]
    payload_offset = sum(len(line) for line in lines[: cpp_index + 1])
    cpp_line_has_newline = lines[cpp_index].endswith((b"\n", b"\r"))
    if cpp_line_has_newline:
        inserted = h_begin + newline + h_end + newline
    else:
        inserted = newline + h_begin + newline + h_end
    absolute_offset = bom_length + payload_offset
    staged = data[:absolute_offset] + inserted + data[absolute_offset:]
    if staged[:absolute_offset] + staged[absolute_offset + len(inserted):] != data:
        return data, b"", -1, "invalid", "inverse byte-preservation proof failed"
    return staged, inserted, absolute_offset, "changed", None


def normalized_migration_id(value: str) -> str:
    migration_id = value.strip()
    if not migration_id or re.fullmatch(r"[A-Za-z0-9._-]+", migration_id) is None:
        raise SystemExit(f"invalid migration id: {value}")
    return migration_id


def generated_reconstruction_h_migration_id(args) -> str:
    context = command_context_from_args(args)
    timestamp = datetime.now().astimezone().strftime("%Y%m%dT%H%M%S%z")
    suffix = context.command_id_display if context.command_id else uuid.uuid4().hex[:12]
    return f"{timestamp}-{suffix}"


def reconstruction_h_manifest_path(ini: Path, migration_id: str) -> Path:
    return reconstruction_h_migration_base(ini) / migration_id / "manifest.json"


def run_reconstruction_h_migration_dryrun(args, root: Path, ini: Path, lock_path: Path) -> int:
    migration_id = normalized_migration_id(args.migration_id) if args.migration_id else generated_reconstruction_h_migration_id(args)
    migration_dir = reconstruction_h_migration_base(ini) / migration_id
    manifest_path = migration_dir / "manifest.json"
    if manifest_path.exists():
        raise SystemExit(f"migration id already exists: {migration_id}")

    entries: list[dict] = []
    actions: list[ScanAction] = []
    invalid = 0
    candidates = [path for path in all_markdown_files(root) if is_reconstruction_metadata_doc(root, path)]
    for path in candidates:
        rel = relative_path(root, path)
        try:
            before = path.read_bytes()
        except OSError as exc:
            entries.append({"path": rel, "classification": "invalid", "error": str(exc)})
            actions.append(ScanAction("reconstruction_h_migration_invalid", None, path, str(exc)))
            invalid += 1
            continue
        staged, inserted, offset, classification, error = stage_reconstruction_h_bytes(before)
        entry = {
            "path": rel,
            "classification": classification,
            "before_sha256": migration_bytes_sha256(before),
            "before_size": len(before),
            "after_sha256": migration_bytes_sha256(staged),
            "after_size": len(staged),
            "insert_offset": offset,
            "inserted_hex": inserted.hex(),
            "newline": "CRLF" if b"\r\n" in before else "LF",
            "final_newline": before.endswith((b"\n", b"\r")),
        }
        if error:
            entry["error"] = error
            invalid += 1
            actions.append(ScanAction("reconstruction_h_migration_invalid", None, path, error))
        elif classification == "changed":
            staged_path = migration_dir / "files" / Path(rel)
            write_bytes_atomic(staged_path, staged)
            entry["staged_path"] = str(staged_path.relative_to(migration_dir).as_posix())
            actions.append(ScanAction("reconstruction_h_migration_stage", None, staged_path, rel))
        else:
            actions.append(ScanAction("reconstruction_h_migration_noop", None, path, "already valid"))
        entries.append(entry)

    manifest = {
        "schema": 1,
        "tool": "validator_background.py",
        "mode": "migrate-reconstruction-h",
        "migration_id": migration_id,
        "status": "invalid" if invalid else "staged",
        "created_at": datetime.now().astimezone().isoformat(timespec="seconds"),
        "root": str(resolved_path(root)),
        "ini": str(resolved_path(ini)),
        "cache_version": CACHE_VERSION,
        "eligible_count": len(candidates),
        "changed_count": sum(1 for entry in entries if entry.get("classification") == "changed"),
        "already_valid_count": sum(1 for entry in entries if entry.get("classification") == "already-valid"),
        "invalid_count": invalid,
        "entries": entries,
    }
    write_json_atomic(manifest, manifest_path)
    print(f"root: {root}")
    print(f"ini: {ini}")
    print(f"lock: {lock_path}")
    print("mode: migrate-reconstruction-h")
    print("apply: False")
    print(f"migration_id: {migration_id}")
    print(f"migration_manifest: {manifest_path}")
    print(f"eligible: {len(candidates)}")
    print(f"changed: {manifest['changed_count']}")
    print(f"already_valid: {manifest['already_valid_count']}")
    print(f"invalid: {invalid}")
    print_actions(actions, root, args.verbose)
    if invalid:
        print("migration_status: invalid; fix all errors and create a new migration id")
        return 1
    print("migration_status: staged; review the manifest, then apply this exact migration id")
    return 0


def load_reconstruction_h_manifest(root: Path, ini: Path, migration_id: str) -> tuple[Path, dict]:
    manifest_path = reconstruction_h_manifest_path(ini, migration_id)
    try:
        manifest = json.loads(manifest_path.read_text(encoding="utf-8"))
    except (FileNotFoundError, OSError, json.JSONDecodeError) as exc:
        raise SystemExit(f"cannot read reconstruction H migration manifest {manifest_path}: {exc}")
    if not isinstance(manifest, dict) or manifest.get("schema") != 1:
        raise SystemExit(f"invalid reconstruction H migration manifest: {manifest_path}")
    if manifest.get("migration_id") != migration_id:
        raise SystemExit("migration manifest id does not match requested id")
    if resolved_path(Path(str(manifest.get("root", "")))) != resolved_path(root):
        raise SystemExit("migration manifest root does not match --root")
    if int(manifest.get("invalid_count", 0)):
        raise SystemExit("migration manifest contains invalid candidates")
    return manifest_path, manifest


def run_reconstruction_h_migration_apply(args, root: Path, ini: Path, lock_path: Path) -> int:
    if not args.migration_id:
        raise SystemExit("--mode migrate-reconstruction-h --apply requires --migration-id")
    migration_id = normalized_migration_id(args.migration_id)
    manifest_path, manifest = load_reconstruction_h_manifest(root, ini, migration_id)
    if manifest.get("status") == "applied":
        print(f"mode: migrate-reconstruction-h")
        print(f"migration_id: {migration_id}")
        print("migration_status: already-applied")
        return 0
    if manifest.get("status") not in {"staged", "applying"}:
        raise SystemExit(f"migration manifest is not applyable: {manifest.get('status')}")

    migration_dir = manifest_path.parent
    entries = manifest.get("entries", [])
    if not isinstance(entries, list):
        raise SystemExit("migration manifest entries are invalid")
    manifest_paths = {
        str(entry.get("path", ""))
        for entry in entries
        if isinstance(entry, dict) and entry.get("classification") in {"changed", "already-valid"}
    }
    current_paths = {
        relative_path(root, path)
        for path in all_markdown_files(root)
        if is_reconstruction_metadata_doc(root, path)
    }
    if manifest_paths != current_paths:
        added = sorted(current_paths - manifest_paths)
        removed = sorted(manifest_paths - current_paths)
        raise SystemExit(
            "migration candidate scope drift: "
            f"added={len(added)} removed={len(removed)}; create a new migration dry run"
        )
    pending: list[tuple[dict, Path, Path, bytes]] = []
    already_written: list[tuple[dict, Path]] = []
    for entry in entries:
        if not isinstance(entry, dict):
            raise SystemExit("migration manifest contains a non-object entry")
        classification = entry.get("classification")
        if classification not in {"changed", "already-valid"}:
            raise SystemExit(f"migration manifest contains an invalid classification: {classification}")
        rel = str(entry.get("path", ""))
        live_path = absolute_path(root, rel)
        try:
            resolved_path(live_path).relative_to(resolved_path(root))
        except ValueError:
            raise SystemExit(f"migration path escapes root: {rel}")
        try:
            current = live_path.read_bytes()
        except OSError as exc:
            raise SystemExit(f"migration preflight read failed for {rel}: {exc}")
        current_hash = migration_bytes_sha256(current)
        if classification == "already-valid":
            if current_hash != entry.get("before_sha256"):
                raise SystemExit(f"live source hash drift: {rel}")
            continue

        staged_path = migration_dir / str(entry.get("staged_path", ""))
        try:
            resolved_path(staged_path).relative_to(resolved_path(migration_dir / "files"))
        except ValueError:
            raise SystemExit(f"staged migration path escapes files directory: {rel}")
        try:
            staged = staged_path.read_bytes()
        except OSError as exc:
            raise SystemExit(f"migration staged read failed for {rel}: {exc}")
        if migration_bytes_sha256(staged) != entry.get("after_sha256"):
            raise SystemExit(f"staged artifact hash drift: {rel}")
        if current_hash == entry.get("after_sha256"):
            already_written.append((entry, live_path))
            continue
        if current_hash != entry.get("before_sha256"):
            raise SystemExit(f"live source hash drift: {rel}")
        inserted = bytes.fromhex(str(entry.get("inserted_hex", "")))
        offset = int(entry.get("insert_offset", -1))
        if offset < 0 or staged[:offset] + staged[offset + len(inserted):] != current:
            raise SystemExit(f"inverse byte-preservation proof failed: {rel}")
        pending.append((entry, live_path, staged_path, current))

    backup_root = migration_dir / "backup"
    for entry, live_path, _, current in pending:
        backup_path = backup_root / Path(str(entry["path"]))
        if backup_path.exists():
            if migration_bytes_sha256(backup_path.read_bytes()) != entry.get("before_sha256"):
                raise SystemExit(f"migration backup hash mismatch: {entry['path']}")
        else:
            write_bytes_atomic(backup_path, current)
    for entry, _ in already_written:
        backup_path = backup_root / Path(str(entry["path"]))
        if not backup_path.exists():
            raise SystemExit(f"migration resume backup is missing: {entry['path']}")
        if migration_bytes_sha256(backup_path.read_bytes()) != entry.get("before_sha256"):
            raise SystemExit(f"migration backup hash mismatch: {entry['path']}")

    progress_path = migration_dir / "apply-journal.jsonl"
    if manifest.get("status") == "staged":
        progress_path.unlink(missing_ok=True)
    manifest["status"] = "applying"
    manifest["apply_started_at"] = datetime.now().astimezone().isoformat(timespec="seconds")
    manifest["applied_paths"] = [str(entry["path"]) for entry, _ in already_written]
    manifest["progress_journal"] = progress_path.name
    write_json_atomic(manifest, manifest_path)
    written: list[tuple[dict, Path]] = []
    try:
        for entry, live_path, staged_path, _ in pending:
            if migration_bytes_sha256(live_path.read_bytes()) != entry.get("before_sha256"):
                raise OSError(f"live source changed during migration apply: {entry['path']}")
            write_bytes_atomic(live_path, staged_path.read_bytes())
            if migration_bytes_sha256(live_path.read_bytes()) != entry.get("after_sha256"):
                raise OSError(f"post-write hash mismatch: {entry['path']}")
            written.append((entry, live_path))
            append_json_line_durable(
                progress_path,
                {
                    "path": str(entry["path"]),
                    "after_sha256": str(entry["after_sha256"]),
                    "applied_at": datetime.now().astimezone().isoformat(timespec="seconds"),
                },
            )
    except Exception:
        for entry, live_path in [*already_written, *written]:
            backup_path = backup_root / Path(str(entry["path"]))
            if backup_path.exists():
                write_bytes_atomic(live_path, backup_path.read_bytes())
        manifest["status"] = "staged"
        manifest["applied_paths"] = []
        manifest["rollback_at"] = datetime.now().astimezone().isoformat(timespec="seconds")
        write_json_atomic(manifest, manifest_path)
        progress_path.unlink(missing_ok=True)
        raise

    manifest["status"] = "applied"
    manifest["applied_at"] = datetime.now().astimezone().isoformat(timespec="seconds")
    manifest["applied_paths"] = [
        str(entry["path"])
        for entry in entries
        if isinstance(entry, dict) and entry.get("classification") == "changed"
    ]
    write_json_atomic(manifest, manifest_path)
    print(f"root: {root}")
    print(f"ini: {ini}")
    print(f"lock: {lock_path}")
    print("mode: migrate-reconstruction-h")
    print("apply: True")
    print(f"migration_id: {migration_id}")
    print(f"migration_manifest: {manifest_path}")
    print(f"eligible: {manifest.get('eligible_count', 0)}")
    print(f"changed: {manifest.get('changed_count', 0)}")
    print("invalid: 0")
    print("migration_status: applied")
    return 0


def run_migrate_reconstruction_h(args, root: Path, ini: Path, lock_path: Path) -> int:
    if args.apply and args.dry_run:
        raise SystemExit("--dry-run and --apply are mutually exclusive for --mode migrate-reconstruction-h")
    if args.use_existing_dryrun:
        raise SystemExit("--use-existing-dryrun does not apply to --mode migrate-reconstruction-h")
    if args.apply:
        return run_reconstruction_h_migration_apply(args, root, ini, lock_path)
    return run_reconstruction_h_migration_dryrun(args, root, ini, lock_path)


def normalize_target_uid(value: str, config: configparser.ConfigParser) -> str:
    uid = value.strip().upper()
    if not re.fullmatch(r"[A-Z0-9]{6}", uid):
        raise SystemExit(f"invalid target UID: {value}")
    if uid not in config["files"]:
        raise SystemExit(f"target UID is not present in validator.ini [files]: {uid}")
    return uid


def report_command_summary(
    args,
    root: Path,
    ini: Path,
    lock_path: Path,
    actions: list[ScanAction],
) -> int:
    print(f"root: {root}")
    print(f"ini: {ini}")
    print(f"lock: {lock_path}")
    print(f"mode: {args.mode}")
    print(f"apply: {args.apply}")
    for name, count in sorted(summarize(actions).items()):
        print(f"{name}: {count}")
    print_actions(actions, root, args.verbose)
    if not args.apply:
        print("dry run only; pass --apply to write changes")
    return 0


def generated_refresh_allowed(args) -> bool:
    if getattr(args, "no_generated_refresh", False):
        return False
    if getattr(args, "uid_only", False) or getattr(args, "reference_only", False):
        return False
    return True


def enqueue_generated_refresh_job(
    args,
    root: Path,
    command_context: CommandContext,
    affected_uids: set[str] | None = None,
    affected_paths: set[str] | None = None,
    refresh_scope: str = "full-fallback",
) -> None:
    if not command_context.has_command:
        return
    queue_dir = DEFAULT_QUEUE_DIR
    jobs_dir = queue_dir / "jobs"
    jobs_dir.mkdir(parents=True, exist_ok=True)
    job_name = f"zz-generated-refresh-{command_context.command_id_display}-{uuid.uuid4().hex[:12]}.json"
    job_path = jobs_dir / job_name
    job = {
        "kind": "generated-refresh",
        "argv": [],
        "cwd": str(Path.cwd()),
        "root": str(root),
        "ini": str(getattr(args, "ini", DEFAULT_INI)),
        "lock": str(getattr(args, "lock", DEFAULT_LOCK)),
        "origin_command_id": command_context.command_id,
        "origin_command_id_display": command_context.command_id_display,
        "origin_command_timestamp": command_context.command_timestamp,
        "affected_uids": sorted(affected_uids or []),
        "affected_paths": sorted(affected_paths or []),
        "refresh_scope": refresh_scope,
        "enqueued_at": datetime.now().astimezone().isoformat(timespec="seconds"),
    }
    with ValidatorLock(DEFAULT_QUEUE_LOCK, -1):
        write_json_atomic(job, job_path)


def print_generated_refresh_status(
    status: str,
    command_context: CommandContext,
    detail: str = "",
) -> None:
    print(f"generated_refresh: {status}")
    if command_context.has_command:
        print(f"generated_refresh_command_id: {command_context.command_id_display}")
        print(f"generated_refresh_timestamp: {command_context.command_timestamp}")
    if detail:
        print(f"generated_refresh_detail: {detail}")


def update_report_registry_file_metadata(
    config: configparser.ConfigParser,
    root: Path,
    report_path: str,
    path: Path,
) -> None:
    metadata = report_file_metadata(root, report_path, path, force_refresh=True)
    if metadata.read_error:
        raise OSError(f"cannot refresh report metadata for {report_path}: {metadata.read_error}")
    config[RESEARCH_REPORT_SIZE_SECTION][report_path] = str(metadata.size)
    config[RESEARCH_REPORT_SHA256_SECTION][report_path] = metadata.sha256


def resolve_executed_report_path_from_args(args, root: Path) -> tuple[str, Path]:
    report_path_arg = getattr(args, "report_path", "") or ""
    if report_path_arg:
        candidate = absolute_path(root, report_path_arg)
        try:
            rel = resolved_path(candidate).relative_to(resolved_path(executed_root(root)))
        except ValueError:
            raise SystemExit(f"executed report path must be under executed-b-agent-research: {report_path_arg}")
        if len(rel.parts) < 2 or rel.parts[0].lower() == "invalidated":
            raise SystemExit(f"executed report path must target a non-invalidated agent report: {report_path_arg}")
        if candidate.suffix.lower() != ".md":
            raise SystemExit(f"executed report path must be a Markdown report: {report_path_arg}")
        return rel.parts[0].upper(), candidate

    agent = normalize_agent_id(args.agent_id, allow_unknown=True)
    filename = safe_report_filename(args.report_file)
    return agent, central_executed_dir(root, agent) / filename


def append_history_to_report_text(
    text: str,
    command_context: CommandContext,
    event: str,
    uid: str | None = None,
    agent: str | None = None,
    issue: str | None = None,
    old_uid: str | None = None,
    new_uid: str | None = None,
    source_path: str | None = None,
    destination_path: str | None = None,
    details: str | None = None,
    additional_uids: tuple[str, ...] = (),
) -> str:
    return append_report_history_event(
        text,
        make_report_history_event(
            command_context,
            event,
            uid=uid,
            agent=agent,
            issue=issue,
            old_uid=old_uid,
            new_uid=new_uid,
            source_path=source_path,
            destination_path=destination_path,
            details=details,
            additional_uids=additional_uids,
        ),
    )


def report_revalidation_reason_from_errors(errors: list[str]) -> str:
    for error in errors:
        if error.startswith(
            (
                "target_uid_unknown",
                "target_path_missing",
                "target_header_mismatch",
                "target_header_missing",
                "malformed TARGET-REPORT-UID",
                "additional_target_",
                "malformed TARGET-REPORT-ADDITIONAL-UIDS",
            )
        ):
            return error
    return ""


def lifecycle_additional_uids(
    config: configparser.ConfigParser,
    report_path: str,
    header: ReportHeaderMetadata,
) -> tuple[str, ...]:
    if report_path in config[RESEARCH_REPORT_ADDITIONAL_UIDS_SECTION]:
        try:
            return additional_uids_for_report(config, report_path)
        except ValueError:
            pass
    return header.additional_target_uids


def validate_additional_target_paths(
    root: Path,
    config: configparser.ConfigParser,
    primary_uid: str,
    additional_uids: tuple[str, ...],
) -> list[str]:
    errors: list[str] = []
    for uid in additional_uids:
        if uid == primary_uid:
            errors.append(f"additional_target_uid_is_primary: {uid}")
        elif uid not in config["files"]:
            errors.append(f"additional_target_uid_unknown: {uid}")
        else:
            target_path = absolute_path(root, config["files"].get(uid, ""))
            if not target_path.exists():
                errors.append(f"additional_target_path_missing: {config['files'].get(uid, '')}")
    return errors


def previous_report_target_uid(text: str, current_uid: str) -> str | None:
    events, error = parse_report_history_events(text)
    if error is not None:
        return None
    for event in reversed(events):
        candidate = str(event.get("new_uid") or event.get("uid") or "").strip().upper()
        if re.fullmatch(r"[A-Z0-9]{6}", candidate) and candidate != current_uid:
            return candidate
    return None


def compact_uid_detail(uids: tuple[str, ...]) -> str:
    shown = uids[:DEFAULT_ACTION_DETAIL_LIMIT]
    detail = ",".join(shown)
    hidden = len(uids) - len(shown)
    if hidden:
        detail = f"{detail} (+{hidden} more)"
    return detail


def mark_report_needs_revalidation(
    root: Path,
    config: configparser.ConfigParser,
    report_path: str,
    reason: str,
    apply: bool,
    command_context: CommandContext,
) -> list[ScanAction]:
    path = absolute_path(root, report_path)
    uid = config[RESEARCH_REPORT_UID_SECTION].get(report_path, "")
    registered = report_path in config[RESEARCH_REPORT_UID_SECTION]
    actions = [ScanAction("research_report_needs_revalidation", uid or None, path, reason)]
    if not apply:
        return actions
    if not path.exists():
        set_report_error(config, report_path, [f"needs-revalidation: {reason}", "registered file is missing"])
        return actions
    text = read_text(path)
    header = parse_report_headers(text)
    additional_uids = lifecycle_additional_uids(config, report_path, header)
    new_text = upsert_report_revalidation_headers(text, reason)
    new_text = append_history_to_report_text(
        new_text,
        command_context,
        "needs-revalidation",
        uid=uid or None,
        agent=config[RESEARCH_REPORT_AGENT_SECTION].get(report_path, ""),
        issue=reason,
        source_path=report_path,
        details="report marked for revalidation",
        additional_uids=additional_uids,
    )
    if new_text != text:
        write_text_atomic(path, new_text)
        if registered:
            update_report_registry_file_metadata(config, root, report_path, path)
        else:
            sha256 = file_sha256(path)
            update_metadata_cache_entry(root, report_path, path, {"_file_sha256": sha256, "report_sha256": sha256})
    set_report_error(config, report_path, [f"needs-revalidation: {reason}"])
    return actions


def mark_reports_for_uid_needs_revalidation(
    root: Path,
    config: configparser.ConfigParser,
    uid: str,
    reason: str,
    apply: bool,
    command_context: CommandContext,
    additional_paths_by_uid: dict[str, tuple[str, ...]] | None = None,
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    additional_paths_by_uid = (
        additional_paths_by_uid
        if additional_paths_by_uid is not None
        else build_additional_report_paths_by_uid(config)
    )
    for report_path in all_report_paths_for_uid(config, additional_paths_by_uid, uid):
        actions.extend(mark_report_needs_revalidation(root, config, report_path, reason, apply, command_context))
    return actions


def run_execute_report_command(args, root: Path, config: configparser.ConfigParser) -> list[ScanAction]:
    command_context = command_context_from_args(args)
    agent = normalize_agent_id(args.agent_id)
    filename = safe_report_filename(args.report_file)
    source = agent_research_dir(root, agent) / filename
    if not source.exists():
        raise SystemExit(f"report not found for {agent}: {source}")
    source_rel = report_relpath(root, source)
    metadata = report_file_metadata(root, source_rel, source, force_refresh=True)
    if metadata.read_error:
        raise SystemExit(f"cannot read report {source_rel}: {metadata.read_error}")
    if metadata.footer_error:
        raise SystemExit(f"cannot execute report with invalid history footer: {metadata.footer_error}")
    header = metadata.header
    if header.errors:
        raise SystemExit(f"cannot execute report with invalid headers: {'; '.join(header.errors)}")
    if header.validation_status == REPORT_VALIDATION_STATUS_NEEDS_REVALIDATION:
        raise SystemExit("cannot execute report while needs-revalidation status is active; clear it after repair")
    if not header.target_uid:
        raise SystemExit("cannot execute report without TARGET-REPORT-UID header")
    if not header.author_agent:
        raise SystemExit("cannot execute report without AUTHOR-AGENT-ID header")
    if header.author_agent.upper() != agent:
        raise SystemExit(f"report author {header.author_agent} does not match command agent {agent}")
    if not header.author_specs:
        raise SystemExit("cannot execute report without AUTHOR-AGENT-SPECS header")
    if not thinking_level_bucket_from_specs(header.author_specs):
        raise SystemExit(f"unsupported report thinking level: {header.author_specs}")

    if args.target_uid:
        target_uid = normalize_target_uid(args.target_uid, config)
        if target_uid != header.target_uid:
            raise SystemExit(
                f"command target {target_uid} does not match TARGET-REPORT-UID {header.target_uid}"
            )
    else:
        target_uid = header.target_uid
    if target_uid not in config["files"]:
        raise SystemExit(f"target UID is not registered: {target_uid}")
    target_path = absolute_path(root, config["files"].get(target_uid, ""))
    if not target_path.exists():
        raise SystemExit(f"target path is missing: {config['files'].get(target_uid, '')}")
    additional_errors = validate_additional_target_paths(
        root,
        config,
        target_uid,
        header.additional_target_uids,
    )
    if additional_errors:
        raise SystemExit(f"cannot execute report with invalid additional targets: {'; '.join(additional_errors)}")

    text = read_text(source)
    old_uid = previous_report_target_uid(text, target_uid)
    new_text = upsert_report_headers(
        text,
        target_uid,
        agent,
        header.author_specs,
        header.additional_target_uids,
    )
    destination = unique_destination_path(central_executed_dir(root, agent), source.name)
    destination_rel = report_relpath(root, destination)
    try:
        new_text = append_history_to_report_text(
            new_text,
            command_context,
            "executed",
            uid=target_uid,
            agent=agent,
            source_path=source_rel,
            destination_path=destination_rel,
            details="report executed into central archive",
            additional_uids=header.additional_target_uids,
        )
        if old_uid:
            new_text = append_history_to_report_text(
                new_text,
                command_context,
                "retargeted-after-rework",
                uid=target_uid,
                agent=agent,
                old_uid=old_uid,
                new_uid=target_uid,
                source_path=source_rel,
                destination_path=destination_rel,
                details="report re-executed against a new/current UID",
                additional_uids=header.additional_target_uids,
            )
    except ValueError as exc:
        raise SystemExit(f"cannot append validator report history for {source_rel}: {exc}")
    actions = [
        ScanAction(
            "research_execute_report",
            target_uid,
            destination,
            f"{source_rel} -> {destination_rel}; additional={len(header.additional_target_uids)}"
            + (f" [{compact_uid_detail(header.additional_target_uids)}]" if header.additional_target_uids else ""),
        )
    ]
    if new_text != text:
        actions.append(
            ScanAction(
                "research_report_header_update",
                target_uid,
                source,
                "report headers/history",
            )
        )

    if args.apply:
        if new_text != text:
            write_text_atomic(source, new_text)
        destination.parent.mkdir(parents=True, exist_ok=True)
        source.replace(destination)
        record = report_record_from_file(
            root,
            destination,
            target_uid,
            agent,
            agent_specs=header.author_specs,
            additional_uids=header.additional_target_uids,
            original_path=source_rel,
        )
        add_report_registry_record(config, record)
        add_report_change_event(
            config,
            1,
            target_uid,
            folder_for_uid(config, target_uid),
            record.path,
            timestamp=record.executed_at,
        )
    return actions


def invalidation_destination(root: Path, agent: str, source: Path, original_path: str) -> Path:
    active_dir = agent_research_dir(root, agent)
    if original_path:
        original = absolute_path(root, original_path)
        try:
            relative = resolved_path(original).relative_to(resolved_path(active_dir))
            if relative.parts:
                return unique_destination_path(active_dir / Path(*relative.parts[:-1]), relative.parts[-1])
        except ValueError:
            pass
    return unique_destination_path(active_dir, source.name)


def run_invalidate_execute_command(args, root: Path, config: configparser.ConfigParser) -> list[ScanAction]:
    command_context = command_context_from_args(args)
    agent = normalize_agent_id(args.agent_id)
    filename = safe_report_filename(args.report_file)
    source = central_executed_dir(root, agent) / filename
    if not source.exists():
        raise SystemExit(f"executed report not found for {agent}: {source}")
    source_rel = report_relpath(root, source)
    original_path = config[RESEARCH_REPORT_ORIGINAL_PATH_SECTION].get(source_rel, "")
    destination = invalidation_destination(root, agent, source, original_path)
    uid = config[RESEARCH_REPORT_UID_SECTION].get(source_rel)
    actions = [
        ScanAction("research_invalidate_execute", uid, source, f"{source_rel} -> {report_relpath(root, destination)}")
    ]
    if args.apply:
        text = read_text(source)
        header = parse_report_headers(text)
        additional_uids = lifecycle_additional_uids(config, source_rel, header)
        text_without_revalidation = clear_report_revalidation_headers(text)
        try:
            new_text = append_history_to_report_text(
                text_without_revalidation,
                command_context,
                "de-executed-for-rework",
                uid=uid,
                agent=agent,
                source_path=source_rel,
                destination_path=report_relpath(root, destination),
                details="report returned to active agent research for rework",
                additional_uids=additional_uids,
            )
        except ValueError as exc:
            raise SystemExit(f"cannot append validator report history for {source_rel}: {exc}")
        if new_text != text:
            write_text_atomic(source, new_text)
        destination.parent.mkdir(parents=True, exist_ok=True)
        source.replace(destination)
        removed_uid = remove_report_registry_path(config, source_rel)
        if removed_uid:
            add_report_change_event(
                config,
                -1,
                removed_uid,
                folder_for_uid(config, removed_uid),
                source_rel,
            )
    return actions


def run_active_clear_revalidation_command(args, root: Path, config: configparser.ConfigParser) -> list[ScanAction]:
    command_context = command_context_from_args(args)
    agent = normalize_agent_id(args.agent_id)
    filename = safe_report_filename(args.report_file)
    path = agent_research_dir(root, agent) / filename
    if not path.exists():
        raise SystemExit(f"active research report not found for {agent}: {path}")
    report_path = report_relpath(root, path)
    metadata = report_file_metadata(root, report_path, path, force_refresh=True)
    if metadata.header.validation_status != REPORT_VALIDATION_STATUS_NEEDS_REVALIDATION:
        raise SystemExit(f"active research report does not have needs-revalidation status: {report_path}")
    errors, _ = report_metadata_diagnostics(root, config, report_path, path, metadata, registered=False)
    blocking = [error for error in errors if not error.startswith("needs-revalidation")]
    if blocking:
        raise SystemExit(f"cannot clear active revalidation while report has live errors: {'; '.join(blocking)}")
    uid = metadata.header.target_uid or uid_from_report_path(config, report_path)
    additional_uids = metadata.header.additional_target_uids
    actions = [ScanAction("research_active_revalidation_cleared", uid, path, report_path)]
    if args.apply:
        text = read_text(path)
        new_text = clear_report_revalidation_headers(text)
        try:
            new_text = append_history_to_report_text(
                new_text,
                command_context,
                "active-revalidation-cleared",
                uid=uid,
                agent=agent,
                source_path=report_path,
                details="active returned report revalidation marker cleared after de-execution repair",
                additional_uids=additional_uids,
            )
        except ValueError as exc:
            raise SystemExit(f"cannot append validator report history for {report_path}: {exc}")
        if new_text != text:
            write_text_atomic(path, new_text)
        refreshed = report_file_metadata(root, report_path, path, force_refresh=True)
        refreshed_errors, _ = report_metadata_diagnostics(
            root, config, report_path, path, refreshed, registered=False
        )
        if refreshed_errors:
            raise SystemExit(
                f"active revalidation clearance left report invalid: {'; '.join(refreshed_errors)}"
            )
    return actions


def invalidated_report_dir(root: Path, agent: str) -> Path:
    return executed_root(root) / "invalidated" / central_agent_folder(agent)


def run_executed_mark_invalid_command(args, root: Path, config: configparser.ConfigParser) -> list[ScanAction]:
    command_context = command_context_from_args(args)
    agent, source = resolve_executed_report_path_from_args(args, root)
    if not source.exists():
        raise SystemExit(f"executed report not found for {agent}: {source}")
    source_rel = report_relpath(root, source)
    destination = unique_destination_path(invalidated_report_dir(root, agent), source.name)
    destination_rel = report_relpath(root, destination)
    uid = config[RESEARCH_REPORT_UID_SECTION].get(source_rel)
    actions = [
        ScanAction("research_report_mark_invalid", uid, source, f"{source_rel} -> {destination_rel}")
    ]
    if args.apply:
        text = read_text(source)
        header = parse_report_headers(text)
        additional_uids = lifecycle_additional_uids(config, source_rel, header)
        try:
            new_text = append_history_to_report_text(
                text,
                command_context,
                "invalidated",
                uid=uid,
                agent=agent,
                source_path=source_rel,
                destination_path=destination_rel,
                details="report moved to invalidated archive and removed from coverage",
                additional_uids=additional_uids,
            )
        except ValueError as exc:
            raise SystemExit(f"cannot append validator report history for {source_rel}: {exc}")
        if new_text != text:
            write_text_atomic(source, new_text)
        destination.parent.mkdir(parents=True, exist_ok=True)
        source.replace(destination)
        removed_uid = remove_report_registry_path(config, source_rel)
        config[RESEARCH_REPORT_ERROR_SECTION].pop(source_rel, None)
        if removed_uid:
            add_report_change_event(
                config,
                -1,
                removed_uid,
                folder_for_uid(config, removed_uid),
                source_rel,
            )
    return actions


def rebuild_research_report_reverse_index(config: configparser.ConfigParser) -> None:
    config[RESEARCH_REPORTS_SECTION].clear()
    for report_path, uid in config[RESEARCH_REPORT_UID_SECTION].items():
        if not uid:
            continue
        sources = parse_reference_sources(config[RESEARCH_REPORTS_SECTION].get(uid, ""))
        sources.add(report_path)
        config[RESEARCH_REPORTS_SECTION][uid] = format_reference_sources(sources)


def run_execute_rescan_reports_command(args, root: Path, config: configparser.ConfigParser) -> list[ScanAction]:
    command_context = command_context_from_args(args)
    actions: list[ScanAction] = []
    registered_paths = set(config[RESEARCH_REPORT_UID_SECTION].keys())
    central_paths = {report_relpath(root, path): path for path in central_report_files(root)}

    if args.apply:
        config[RESEARCH_REPORT_ERROR_SECTION].clear()
        rebuild_research_report_reverse_index(config)
    target_exists_by_uid: dict[str, bool] = {}
    direct_index_errors_by_report = build_direct_index_errors_by_report(config)

    for report_path, path in sorted(central_paths.items()):
        if report_path not in registered_paths:
            folder_agent = central_agent_from_path(root, path)
            metadata = report_file_metadata(root, report_path, path, force_refresh=True)
            errors, revalidation_reasons = report_metadata_diagnostics(
                root,
                config,
                report_path,
                path,
                metadata,
                registered=False,
                target_exists_by_uid=target_exists_by_uid,
                direct_index_errors_by_report=direct_index_errors_by_report,
            )
            if errors:
                actions.append(ScanAction("research_report_error", metadata.header.target_uid or None, path, "; ".join(errors)))
                if revalidation_reasons and metadata.header.validation_status != REPORT_VALIDATION_STATUS_NEEDS_REVALIDATION:
                    reason = revalidation_reasons[0]
                    actions.extend(mark_report_needs_revalidation(root, config, report_path, reason, args.apply, command_context))
                if args.apply:
                    set_report_error(config, report_path, errors)
                continue
            assert metadata.header.target_uid is not None
            assert metadata.header.author_agent is not None
            assert metadata.header.author_specs is not None
            actions.append(
                ScanAction(
                    "research_report_register",
                    metadata.header.target_uid,
                    path,
                    "central file registered from report headers",
                )
            )
            if args.apply:
                text = read_text(path)
                try:
                    new_text = append_history_to_report_text(
                        text,
                        command_context,
                        "registered",
                        uid=metadata.header.target_uid,
                        agent=metadata.header.author_agent.upper(),
                        source_path=report_path,
                        details="central report registered from headers",
                        additional_uids=metadata.header.additional_target_uids,
                    )
                except ValueError as exc:
                    raise SystemExit(f"cannot append validator report history for {report_path}: {exc}")
                if new_text != text:
                    write_text_atomic(path, new_text)
                    metadata = report_file_metadata(root, report_path, path, force_refresh=True)
                add_report_registry_record(
                    config,
                    ResearchReportRecord(
                        path=report_path,
                        uid=metadata.header.target_uid,
                        agent=metadata.header.author_agent.upper(),
                        agent_specs=metadata.header.author_specs,
                        size=metadata.size,
                        sha256=metadata.sha256,
                        executed_at=report_timestamp_from_file(path),
                        additional_uids=metadata.header.additional_target_uids,
                    ),
                )
                registered_paths.add(report_path)
            continue

        uid = config[RESEARCH_REPORT_UID_SECTION].get(report_path, "")
        metadata = report_file_metadata(root, report_path, path, force_refresh=True)
        errors, revalidation_reasons = report_metadata_diagnostics(
            root,
            config,
            report_path,
            path,
            metadata,
            registered=True,
            target_exists_by_uid=target_exists_by_uid,
            direct_index_errors_by_report=direct_index_errors_by_report,
        )
        if errors:
            actions.append(ScanAction("research_report_error", uid or None, path, "; ".join(errors)))
            if revalidation_reasons and metadata.header.validation_status != REPORT_VALIDATION_STATUS_NEEDS_REVALIDATION:
                actions.extend(
                    mark_report_needs_revalidation(root, config, report_path, revalidation_reasons[0], args.apply, command_context)
                )
        else:
            actions.append(ScanAction("research_report_ok", uid or None, path, "registered report verified"))
        if args.apply:
            set_report_error(config, report_path, errors)

    for report_path in sorted(registered_paths - set(central_paths)):
        actions.append(ScanAction("research_report_missing", config[RESEARCH_REPORT_UID_SECTION].get(report_path), absolute_path(root, report_path), "registered file is missing"))
        if args.apply:
            set_report_error(config, report_path, ["registered file is missing"])

    if args.apply:
        rebuild_research_report_reverse_index(config)
    save_metadata_cache(root)
    return actions


def run_execute_confirm_change_command(args, root: Path, config: configparser.ConfigParser) -> list[ScanAction]:
    command_context = command_context_from_args(args)
    agent = normalize_agent_id(args.agent_id)
    filename = safe_report_filename(args.report_file)
    path = central_executed_dir(root, agent) / filename
    if not path.exists():
        raise SystemExit(f"executed report not found for {agent}: {path}")
    report_path = report_relpath(root, path)
    uid = config[RESEARCH_REPORT_UID_SECTION].get(report_path)
    if not uid:
        raise SystemExit(f"executed report is not registered: {report_path}")
    metadata = report_file_metadata(root, report_path, path, force_refresh=True)
    errors, _ = report_metadata_diagnostics(root, config, report_path, path, metadata, registered=True)
    blocking = [error for error in errors if not error.startswith(("size_changed", "sha256_changed"))]
    if blocking:
        raise SystemExit(f"cannot confirm report content change with live errors: {'; '.join(blocking)}")
    additional_uids = lifecycle_additional_uids(config, report_path, metadata.header)
    actions = [ScanAction("research_report_confirm_change", uid, path, "size/hash refreshed")]
    if args.apply:
        text = read_text(path)
        try:
            new_text = append_history_to_report_text(
                text,
                command_context,
                "content-change-confirmed",
                uid=uid,
                agent=agent,
                source_path=report_path,
                details="post-execution content change accepted; size/hash refreshed",
                additional_uids=additional_uids,
            )
        except ValueError as exc:
            raise SystemExit(f"cannot append validator report history for {report_path}: {exc}")
        if new_text != text:
            write_text_atomic(path, new_text)
        update_report_registry_file_metadata(config, root, report_path, path)
        metadata = report_file_metadata(root, report_path, path, force_refresh=True)
        errors, _ = report_metadata_diagnostics(root, config, report_path, path, metadata, registered=True)
        set_report_error(config, report_path, errors)
    return actions


def run_execute_confirm_removed_archives_command(
    args,
    root: Path,
    config: configparser.ConfigParser,
) -> list[ScanAction]:
    command_context = command_context_from_args(args)
    actions: list[ScanAction] = []
    target_exists_by_uid: dict[str, bool] = {}
    direct_index_errors_by_report = build_direct_index_errors_by_report(config)

    for archive in central_removed_report_archives(root):
        source = archive.with_name(archive.name[: -len("-removed.md")] + ".md")
        if not source.exists():
            actions.append(
                ScanAction(
                    "research_report_removed_archive_error",
                    None,
                    archive,
                    "matching executed report is missing",
                )
            )
            continue

        report_path = report_relpath(root, source)
        uid = config[RESEARCH_REPORT_UID_SECTION].get(report_path, "").strip().upper()
        if not uid:
            actions.append(
                ScanAction(
                    "research_report_removed_archive_error",
                    None,
                    archive,
                    f"matching executed report is not registered: {report_path}",
                )
            )
            continue

        archive_text = read_text(archive)
        archive_lower = archive_text.lower()
        authority_ok = "non-authoritative" in archive_lower or any(
            phrase in archive_lower
            for phrase in ("not a b-agent research report", "not a b agent research report")
        )
        warning_ok = authority_ok and any(
            phrase in archive_lower
            for phrase in ("must not be executed", "must never be executed", "do not execute")
        )
        source_text = read_text(source)
        link_ok = archive.name in source_text
        if not warning_ok or not link_ok:
            detail = []
            if not warning_ok:
                detail.append("archive lacks the inert non-authoritative/do-not-execute warning")
            if not link_ok:
                detail.append("matching report does not name its removal archive")
            actions.append(
                ScanAction(
                    "research_report_removed_archive_error",
                    uid,
                    archive,
                    "; ".join(detail),
                )
            )
            continue

        metadata = report_file_metadata(root, report_path, source, force_refresh=True)
        errors, _ = report_metadata_diagnostics(
            root,
            config,
            report_path,
            source,
            metadata,
            registered=True,
            target_exists_by_uid=target_exists_by_uid,
            direct_index_errors_by_report=direct_index_errors_by_report,
        )
        integrity_errors = [
            error for error in errors if error.startswith(("size_changed", "sha256_changed"))
        ]
        blocking = [error for error in errors if error not in integrity_errors]
        if blocking:
            actions.append(
                ScanAction(
                    "research_report_removed_archive_error",
                    uid,
                    source,
                    "; ".join(blocking),
                )
            )
            continue
        if not integrity_errors:
            actions.append(
                ScanAction(
                    "research_report_removed_archive_ok",
                    uid,
                    source,
                    "registered content identity already current",
                )
            )
            continue

        actions.append(
            ScanAction(
                "research_report_removed_archive_confirm_change",
                uid,
                source,
                f"confirmed cleanup with inert sibling {archive.name}",
            )
        )
        if not args.apply:
            continue

        additional_uids = lifecycle_additional_uids(config, report_path, metadata.header)
        try:
            new_text = append_history_to_report_text(
                source_text,
                command_context,
                "content-change-confirmed",
                uid=uid,
                agent=central_agent_from_path(root, source),
                source_path=report_path,
                details=(
                    "supervisor-confirmed removal of executable report automation; "
                    f"inert archive preserved at {archive.name}"
                ),
                additional_uids=additional_uids,
            )
        except ValueError as exc:
            raise SystemExit(f"cannot append validator report history for {report_path}: {exc}")
        if new_text != source_text:
            write_text_atomic(source, new_text)
        update_report_registry_file_metadata(config, root, report_path, source)
        refreshed = report_file_metadata(root, report_path, source, force_refresh=True)
        refreshed_errors, _ = report_metadata_diagnostics(
            root,
            config,
            report_path,
            source,
            refreshed,
            registered=True,
            target_exists_by_uid=target_exists_by_uid,
            direct_index_errors_by_report=direct_index_errors_by_report,
        )
        set_report_error(config, report_path, refreshed_errors)
    return actions


def run_executed_mark_needs_revalidation_command(args, root: Path, config: configparser.ConfigParser) -> list[ScanAction]:
    reason = (getattr(args, "reason", "") or "").strip()
    if not reason:
        raise SystemExit("--reason is required for executed-mark-needs-revalidation")
    if reason.lower() in {"needs revalidation", "needs-revalidation", "revalidation"}:
        raise SystemExit("--reason must describe the concrete revalidation issue")
    _agent, path = resolve_executed_report_path_from_args(args, root)
    if not path.exists():
        raise SystemExit(f"executed report not found: {path}")
    report_path = report_relpath(root, path)
    if report_path not in config[RESEARCH_REPORT_UID_SECTION]:
        raise SystemExit(f"executed report is not registered: {report_path}")
    return mark_report_needs_revalidation(root, config, report_path, reason, args.apply, command_context_from_args(args))


def run_executed_clear_revalidation_command(args, root: Path, config: configparser.ConfigParser) -> list[ScanAction]:
    command_context = command_context_from_args(args)
    agent, path = resolve_executed_report_path_from_args(args, root)
    if not path.exists():
        raise SystemExit(f"executed report not found for {agent}: {path}")
    report_path = report_relpath(root, path)
    uid = config[RESEARCH_REPORT_UID_SECTION].get(report_path)
    if not uid:
        raise SystemExit(f"executed report is not registered: {report_path}")
    metadata = report_file_metadata(root, report_path, path, force_refresh=True)
    errors, _ = report_metadata_diagnostics(root, config, report_path, path, metadata, registered=True)
    blocking = [
        error
        for error in errors
        if not error.startswith("needs-revalidation")
    ]
    if blocking:
        raise SystemExit(f"cannot clear revalidation while report has live errors: {'; '.join(blocking)}")
    additional_uids = lifecycle_additional_uids(config, report_path, metadata.header)
    actions = [ScanAction("research_report_revalidation_cleared", uid, path, report_path)]
    if args.apply:
        text = read_text(path)
        new_text = clear_report_revalidation_headers(text)
        try:
            new_text = append_history_to_report_text(
                new_text,
                command_context,
                "revalidation-cleared",
                uid=uid,
                agent=config[RESEARCH_REPORT_AGENT_SECTION].get(report_path, ""),
                source_path=report_path,
                details="revalidation marker cleared after supervisor/validator review",
                additional_uids=additional_uids,
            )
        except ValueError as exc:
            raise SystemExit(f"cannot append validator report history for {report_path}: {exc}")
        if new_text != text:
            write_text_atomic(path, new_text)
        update_report_registry_file_metadata(config, root, report_path, path)
        metadata = report_file_metadata(root, report_path, path, force_refresh=True)
        new_errors, _ = report_metadata_diagnostics(root, config, report_path, path, metadata, registered=True)
        set_report_error(config, report_path, new_errors)
    return actions


def run_executed_reassign_command(args, root: Path, config: configparser.ConfigParser) -> list[ScanAction]:
    command_context = command_context_from_args(args)
    old_agent = normalize_agent_id(args.agent_id, allow_unknown=True)
    new_agent = normalize_agent_id(args.new_agent_id)
    filename = safe_report_filename(args.report_file)
    source = central_executed_dir(root, old_agent) / filename
    if not source.exists():
        raise SystemExit(f"executed report not found for {old_agent}: {source}")
    source_rel = report_relpath(root, source)
    uid = config[RESEARCH_REPORT_UID_SECTION].get(source_rel)
    if not uid:
        raise SystemExit(f"executed report is not registered: {source_rel}")
    metadata = report_file_metadata(root, source_rel, source, force_refresh=True)
    errors, _ = report_metadata_diagnostics(root, config, source_rel, source, metadata, registered=True)
    blocking = [error for error in errors if not error.startswith("needs-revalidation")]
    if blocking:
        raise SystemExit(f"cannot reassign report with live errors: {'; '.join(blocking)}")
    header = metadata.header
    if not header.author_specs:
        raise SystemExit("cannot reassign report without AUTHOR-AGENT-SPECS header")
    additional_uids = lifecycle_additional_uids(config, source_rel, header)
    text = read_text(source)
    destination = unique_destination_path(central_executed_dir(root, new_agent), source.name)
    destination_rel = report_relpath(root, destination)
    original_path = config[RESEARCH_REPORT_ORIGINAL_PATH_SECTION].get(source_rel, "")
    executed_at = config[RESEARCH_REPORT_EXECUTED_AT_SECTION].get(source_rel, datetime.now().isoformat(timespec="seconds"))
    actions = [
        ScanAction("research_report_reassign", uid, source, f"{source_rel} -> {destination_rel}; {old_agent} -> {new_agent}")
    ]
    if args.apply:
        new_text = upsert_report_headers(
            text,
            uid,
            new_agent,
            header.author_specs,
            additional_uids,
            validation_status=header.validation_status,
            revalidation_reason=header.revalidation_reason,
        )
        try:
            new_text = append_history_to_report_text(
                new_text,
                command_context,
                "reassigned",
                uid=uid,
                agent=new_agent,
                source_path=source_rel,
                destination_path=destination_rel,
                details=f"executed report reassigned from {old_agent} to {new_agent}",
                additional_uids=additional_uids,
            )
        except ValueError as exc:
            raise SystemExit(f"cannot append validator report history for {source_rel}: {exc}")
        if new_text != text:
            write_text_atomic(source, new_text)
        destination.parent.mkdir(parents=True, exist_ok=True)
        source.replace(destination)
        remove_report_registry_path(config, source_rel)
        if uid:
            add_report_registry_record(
                config,
                report_record_from_file(
                    root,
                    destination,
                    uid,
                    new_agent,
                    agent_specs=header.author_specs,
                    additional_uids=additional_uids,
                    original_path=original_path,
                    executed_at=executed_at,
                ),
            )
    return actions


def run_migrate_executed_reports_command(args, root: Path, config: configparser.ConfigParser) -> list[ScanAction]:
    command_context = command_context_from_args(args)
    actions: list[ScanAction] = []
    for agent, source in old_executed_report_files(root):
        if not source.exists():
            continue
        text = read_text(source)
        target_uid, detection_errors = detect_report_target_uid(root, config, source, text)
        destination_agent = agent if agent != "unknown" else "unknown"
        destination = unique_destination_path(central_executed_dir(root, destination_agent), source.name)
        source_rel = report_relpath(root, source)
        destination_rel = report_relpath(root, destination)
        actions.append(
            ScanAction(
                "research_migrate_executed_report",
                target_uid,
                destination,
                f"{source_rel} -> {destination_rel}",
            )
        )
        if detection_errors:
            actions.append(ScanAction("research_migrate_detection_warning", target_uid, source, "; ".join(detection_errors)))
        if args.apply:
            header = parse_report_headers(text)
            specs = header.author_specs or default_report_author_specs()
            additional_uids = header.additional_target_uids
            new_text = upsert_report_headers(
                text,
                target_uid,
                agent if agent != "unknown" else None,
                specs,
                additional_uids,
            )
            try:
                new_text = append_history_to_report_text(
                    new_text,
                    command_context,
                    "executed",
                    uid=target_uid,
                    agent=agent if agent != "unknown" else None,
                    source_path=source_rel,
                    destination_path=destination_rel,
                    details="legacy executed report migrated into central archive",
                    additional_uids=additional_uids,
                )
            except ValueError as exc:
                raise SystemExit(f"cannot append validator report history for {source_rel}: {exc}")
            if new_text != text:
                write_text_atomic(source, new_text)
            destination.parent.mkdir(parents=True, exist_ok=True)
            source.replace(destination)
            if target_uid:
                record = report_record_from_file(
                    root,
                    destination,
                    target_uid,
                    agent if agent != "unknown" else "unknown",
                    agent_specs=specs,
                    additional_uids=additional_uids,
                    original_path=source_rel,
                )
                add_report_registry_record(config, record)
                add_report_change_event(
                    config,
                    1,
                    target_uid,
                    folder_for_uid(config, target_uid),
                    record.path,
                    timestamp=record.executed_at,
                )
                migration_errors = [*detection_errors, *header.errors]
                if migration_errors:
                    set_report_error(config, record.path, migration_errors)
            else:
                set_report_error(config, destination_rel, detection_errors or ["target UID could not be detected"])
    return actions


def active_b_agent_research_reports(root: Path) -> list[Path]:
    agents_root = root / "tools" / "leaser" / "Agents"
    if not agents_root.exists():
        return []
    reports: list[Path] = []
    for agent_dir in sorted(agents_root.glob("Agent-B*")):
        research = agent_dir / "research"
        if not research.exists():
            continue
        for path in sorted(research.rglob("*.md")):
            if path.name.lower().endswith("-removed.md"):
                continue
            try:
                relative = path.relative_to(research)
            except ValueError:
                relative = Path(path.name)
            if any(part.lower() == "executed" for part in relative.parts):
                continue
            reports.append(path)
    return reports


def migrate_report_specs_in_file(
    root: Path,
    config: configparser.ConfigParser,
    path: Path,
    specs: str,
    apply: bool,
    executed: bool,
) -> list[ScanAction]:
    report_path = report_relpath(root, path)
    actions: list[ScanAction] = []
    try:
        text = read_text(path)
    except UnicodeDecodeError as exc:
        return [ScanAction("research_report_agent_specs_error", None, path, str(exc))]
    header = parse_report_headers(text)
    uid = header.target_uid or config[RESEARCH_REPORT_UID_SECTION].get(report_path)
    registered = executed and report_path in config[RESEARCH_REPORT_UID_SECTION]
    new_text = upsert_report_headers(
        text,
        header.target_uid,
        header.author_agent,
        specs,
        header.additional_target_uids,
        validation_status=header.validation_status,
        revalidation_reason=header.revalidation_reason,
    )
    registry_needs_update = registered and config[RESEARCH_REPORT_AGENT_SPECS_SECTION].get(report_path, "") != specs
    if new_text != text:
        action = "research_report_agent_specs_update" if header.author_specs else "research_report_agent_specs_add"
        actions.append(ScanAction(action, uid, path, specs))
    elif registry_needs_update:
        actions.append(ScanAction("research_report_agent_specs_registry_update", uid, path, specs))
    else:
        actions.append(ScanAction("research_report_agent_specs_ok", uid, path, specs))

    if apply:
        if new_text != text:
            write_text_atomic(path, new_text)
        if registered:
            config[RESEARCH_REPORT_AGENT_SPECS_SECTION][report_path] = specs
            update_report_registry_file_metadata(config, root, report_path, path)
    return actions


def run_migrate_report_agent_specs_command(args, root: Path, config: configparser.ConfigParser) -> list[ScanAction]:
    specs = default_report_author_specs()
    actions: list[ScanAction] = []
    for path in central_report_files(root):
        actions.extend(migrate_report_specs_in_file(root, config, path, specs, args.apply, executed=True))
    for path in active_b_agent_research_reports(root):
        actions.extend(migrate_report_specs_in_file(root, config, path, specs, args.apply, executed=False))
    save_metadata_cache(root)
    return actions


def run_migrate_report_history_command(args, root: Path, config: configparser.ConfigParser) -> list[ScanAction]:
    command_context = command_context_from_args(args)
    actions: list[ScanAction] = []
    for path in central_report_files(root):
        report_path = report_relpath(root, path)
        uid = config[RESEARCH_REPORT_UID_SECTION].get(report_path, "")
        if not uid:
            actions.append(ScanAction("research_report_history_skip", None, path, "unregistered central report"))
            continue
        try:
            text = read_text(path)
        except UnicodeDecodeError as exc:
            actions.append(ScanAction("research_report_history_error", uid, path, str(exc)))
            continue
        events, footer_error = parse_report_history_events(text)
        if footer_error is not None:
            actions.append(ScanAction("research_report_history_error", uid, path, footer_error))
            continue
        if events:
            actions.append(ScanAction("research_report_history_ok", uid, path, "history already present"))
            continue
        timestamp = config[RESEARCH_REPORT_EXECUTED_AT_SECTION].get(report_path, "") or report_timestamp_from_file(path)
        event = make_report_history_event(
            command_context,
            "executed",
            uid=uid,
            agent=config[RESEARCH_REPORT_AGENT_SECTION].get(report_path, ""),
            source_path=config[RESEARCH_REPORT_ORIGINAL_PATH_SECTION].get(report_path, ""),
            destination_path=report_path,
            details="legacy registry reconstruction",
            additional_uids=lifecycle_additional_uids(config, report_path, parse_report_headers(text)),
        )
        event["timestamp"] = timestamp
        actions.append(ScanAction("research_report_history_add", uid, path, "legacy registry reconstruction"))
        if args.apply:
            try:
                new_text = append_report_history_event(text, event)
            except ValueError as exc:
                raise SystemExit(f"cannot append validator report history for {report_path}: {exc}")
            if new_text != text:
                write_text_atomic(path, new_text)
                update_report_registry_file_metadata(config, root, report_path, path)
    save_metadata_cache(root)
    return actions


def run_report_lifecycle_mode(args, root: Path, ini: Path, lock_path: Path) -> int:
    command_context = command_context_from_args(args)
    config = load_config(ini)
    if args.mode == "execute-report":
        actions = run_execute_report_command(args, root, config)
    elif args.mode == "invalidate-execute":
        actions = run_invalidate_execute_command(args, root, config)
    elif args.mode == "execute-rescan-reports":
        actions = run_execute_rescan_reports_command(args, root, config)
    elif args.mode == "execute-confirm-change":
        actions = run_execute_confirm_change_command(args, root, config)
    elif args.mode == "execute-confirm-removed-archives":
        actions = run_execute_confirm_removed_archives_command(args, root, config)
    elif args.mode == "executed-reassign":
        actions = run_executed_reassign_command(args, root, config)
    elif args.mode == "executed-mark-invalid":
        actions = run_executed_mark_invalid_command(args, root, config)
    elif args.mode == "executed-mark-needs-revalidation":
        actions = run_executed_mark_needs_revalidation_command(args, root, config)
    elif args.mode == "executed-clear-revalidation":
        actions = run_executed_clear_revalidation_command(args, root, config)
    elif args.mode == "active-clear-revalidation":
        actions = run_active_clear_revalidation_command(args, root, config)
    elif args.mode == "migrate-executed-reports":
        actions = run_migrate_executed_reports_command(args, root, config)
    elif args.mode == "migrate-report-agent-specs":
        actions = run_migrate_report_agent_specs_command(args, root, config)
    elif args.mode == "migrate-report-history":
        actions = run_migrate_report_history_command(args, root, config)
    else:
        raise SystemExit(f"unknown report lifecycle mode: {args.mode}")

    affected_uids = {action.uid for action in actions if action.uid}
    affected_paths = {relative_path(root, action.path) for action in actions if action.path}
    generated_status = "skipped"
    generated_detail = ""
    defer_generated_refresh = False
    metadata_only_lifecycle = args.mode in {"migrate-report-agent-specs", "migrate-report-history"}
    if metadata_only_lifecycle:
        generated_detail = "metadata-only lifecycle command"
    elif generated_refresh_allowed(args):
        if args.wait_generated:
            actions.extend(
                run_research_tracker_generation(
                    root,
                    config,
                    args.apply,
                    command_context=command_context,
                    refresh_source="foreground-generated-refresh",
                )
            )
            generated_status = "completed"
        elif args.apply:
            defer_generated_refresh = True
            generated_status = "deferred"
        else:
            generated_status = "would-defer"
    else:
        generated_detail = "disabled by uid/reference/no-generated-refresh option"
    if args.apply:
        write_config_atomic(config, ini)
    if defer_generated_refresh:
        enqueue_generated_refresh_job(
            args,
            root,
            command_context,
            affected_uids=affected_uids,
            affected_paths=affected_paths,
            refresh_scope="research-tracker",
        )
    result = report_command_summary(args, root, ini, lock_path, actions)
    print_generated_refresh_status(generated_status, command_context, generated_detail)
    return result


def run_validator(args, root: Path, ini: Path, lock_path: Path) -> int:
    command_context = command_context_from_args(args)
    if args.mode == "migrate-autogen":
        return run_migrate_autogen(args, root, ini, lock_path)
    if args.mode == "migrate-reconstruction-h":
        return run_migrate_reconstruction_h(args, root, ini, lock_path)
    if args.mode == "clear-dryrun-files":
        return run_clear_dryrun_files(args, root, ini, lock_path)
    if args.mode in {
        "execute-report",
        "invalidate-execute",
        "execute-rescan-reports",
        "execute-confirm-change",
        "execute-confirm-removed-archives",
        "executed-reassign",
        "executed-mark-invalid",
        "executed-mark-needs-revalidation",
        "executed-clear-revalidation",
        "active-clear-revalidation",
        "migrate-executed-reports",
        "migrate-report-agent-specs",
        "migrate-report-history",
    }:
        return run_report_lifecycle_mode(args, root, ini, lock_path)

    config = load_config(ini)

    if args.mode == "isolated":
        targets, actions = scan_isolated_files(root)
        actions.extend(recheck_tmp_reference_errors(root, config, False, set(), []))
        if args.remove_missing:
            actions.append(
                ScanAction(
                    "skipped",
                    None,
                    root,
                    "--remove-missing does not apply to isolated scans",
                )
            )
        print(f"root: {root}")
        print(f"ini: {ini}")
        print(f"lock: {lock_path}")
        print(f"mode: {args.mode}")
        print("scope: direct by-* folders under root")
        print(f"apply: {args.apply}")
        print(f"remove missing: {args.remove_missing}")
        print("uid phase: False")
        print("reference phase: False")
        print(f"scanned markdown files: {len(targets)}")
        print(f"last used UID: {config['state']['last_used_uid']}")
        for name, count in sorted(summarize(actions).items()):
            print(f"{name}: {count}")
        print_actions(actions, root, args.verbose)
        if args.apply:
            print("isolated scan is report-only; --apply made no changes")
        else:
            print("dry run only; isolated scan is report-only")
        return 0

    original_files = dict(config["files"])
    targets, pre_actions = scan_targets(args, root, config)

    generated_order: list[str] = []
    actions: list[ScanAction] = list(pre_actions)
    if args.mode in {"full", "documented"}:
        actions.extend(parallel_observation_prewarm(root, targets))
    seen_file_uids: dict[str, Path] = {}
    path_updated_uids: set[str] = set()
    run_uid_phase = not args.reference_only and args.mode != "autogen"
    run_reference_phase = not args.uid_only and args.mode != "autogen"

    if run_uid_phase:
        for path in targets:
            file_actions = scan_file(path, root, config, generated_order, args.apply)
            for action in file_actions:
                if action.action == "path_update" and action.uid:
                    path_updated_uids.add(action.uid)
            for action in file_actions:
                if action.uid and action.action in {"ok", "insert_uid", "restore_uid", "replace_damaged_uid"}:
                    previous = seen_file_uids.get(action.uid)
                    if previous is not None and previous != path:
                        actions.append(
                            ScanAction(
                                "duplicate",
                                action.uid,
                                path,
                                f"also present in {relative_path(root, previous)}",
                            )
                        )
                    else:
                        seen_file_uids[action.uid] = path
            actions.extend(file_actions)
    else:
        for path in targets:
            uid = first_line_uid(read_text(path))
            if uid is None:
                actions.append(
                    ScanAction(
                        "missing_uid",
                        None,
                        path,
                        "reference-only scan skipped top-line UID creation",
                    )
                )
                continue
            previous = seen_file_uids.get(uid)
            if previous is not None and previous != path:
                actions.append(
                    ScanAction(
                        "duplicate",
                        uid,
                        path,
                        f"also present in {relative_path(root, previous)}",
                    )
                )
            else:
                seen_file_uids[uid] = path

    if run_reference_phase:
        if args.mode in {"full", "documented"} and args.apply:
            config["references"].clear()
        for path in targets:
            actions.extend(
                update_uid_references(
                    path,
                    root,
                    config,
                    args.apply,
                    generated_order=generated_order,
                )
            )
        if args.mode == "file" and args.apply:
            for uid in sorted(path_updated_uids):
                actions.extend(propagate_reference_updates_for_target(uid, root, config, args.apply))
        skip_sources = {relative_path(root, path) for path in targets}
        actions.extend(
            recheck_tmp_reference_errors(
                root,
                config,
                args.apply,
                skip_sources,
                generated_order,
            )
        )

    if run_uid_phase and args.mode in {"full", "documented"}:
        actions.extend(
            reconcile_missing_uids(
                root,
                config,
                original_files,
                seen_file_uids,
                args.remove_missing,
                args.apply,
                command_context,
            )
        )
    elif args.remove_missing:
        actions.append(
            ScanAction(
                "skipped",
                None,
                root,
                "--remove-missing only applies to full or documented scans",
            )
        )

    if args.mode in {"full", "documented", "rescore"}:
        actions.append(update_completion_stats(root, config, args.apply))
    elif args.mode == "file" and run_uid_phase:
        if args.apply:
            for uid in seen_file_uids:
                actions.extend(update_completion_stats_incremental(root, config, uid, args.apply))
            actions.append(update_projected_path_stats(root, config, args.apply))
        else:
            for uid in seen_file_uids:
                actions.append(
                    ScanAction(
                        "stats_incremental_skip",
                        uid,
                        root / STATS_RELATIVE_PATH,
                        "dry run; pass --apply to update generated stats rows",
                    )
                )

    generated_modes = {"full", "documented", "file", "rescore", "autogen"}
    generated_status = "skipped"
    generated_detail = ""
    defer_generated_refresh = False
    affected_uids = set(seen_file_uids)
    affected_paths = {relative_path(root, path) for path in targets}
    generated_refresh_applicable = args.mode in generated_modes and generated_refresh_allowed(args)
    if generated_refresh_applicable:
        foreground_generated = args.mode == "autogen" or args.wait_generated
        if foreground_generated:
            if (
                args.mode in {"full", "documented", "file", "autogen"}
                and not args.uid_only
                and not args.reference_only
            ):
                actions.extend(
                    run_autogen_generation(
                        root,
                        config,
                        args.apply,
                        command_context=command_context,
                        refresh_source="foreground-generated-refresh",
                    )
                )

            if args.mode in generated_modes and not args.reference_only:
                actions.extend(
                    run_research_tracker_generation(
                        root,
                        config,
                        args.apply,
                        command_context=command_context,
                        refresh_source="foreground-generated-refresh",
                    )
                )
                actions.extend(
                    run_by_memory_auto_coverage_generation(
                        root,
                        config,
                        args.apply,
                        command_context=command_context,
                        refresh_source="foreground-generated-refresh",
                    )
                )
            generated_status = "completed"
        elif args.apply:
            defer_generated_refresh = True
            generated_status = "deferred"
        else:
            generated_status = "would-defer"
    else:
        if args.no_generated_refresh:
            generated_detail = "disabled by --no-generated-refresh"
        elif args.uid_only:
            generated_detail = "disabled by --uid-only"
        elif args.reference_only:
            generated_detail = "disabled by --reference-only"

    if args.apply:
        write_config_atomic(config, ini)
    if defer_generated_refresh:
        refresh_scope = "file-incremental" if args.mode == "file" else "full-fallback"
        enqueue_generated_refresh_job(
            args,
            root,
            command_context,
            affected_uids=affected_uids,
            affected_paths=affected_paths,
            refresh_scope=refresh_scope,
        )

    print(f"root: {root}")
    print(f"ini: {ini}")
    print(f"lock: {lock_path}")
    print(f"mode: {args.mode}")
    print("scope: direct by-* folders under root")
    print(f"apply: {args.apply}")
    print(f"remove missing: {args.remove_missing}")
    print(f"uid phase: {run_uid_phase}")
    print(f"reference phase: {run_reference_phase}")
    print(f"scanned markdown files: {len(targets)}")
    print(f"last used UID: {config['state']['last_used_uid']}")
    for name, count in sorted(summarize(actions).items()):
        print(f"{name}: {count}")
    print_actions(actions, root, args.verbose)
    if not args.apply:
        print("dry run only; pass --apply to write changes")
    print_generated_refresh_status(generated_status, command_context, generated_detail)
    return 0


def write_json_atomic(data: dict, path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    handle = tempfile.NamedTemporaryFile(
        "w",
        encoding="utf-8",
        newline="\n",
        dir=path.parent,
        delete=False,
    )
    temp_path = Path(handle.name)
    try:
        with handle:
            json.dump(data, handle, indent=2, sort_keys=True)
            handle.write("\n")
        temp_path.replace(path)
    except Exception:
        temp_path.unlink(missing_ok=True)
        raise


def queue_dedup_settings(ini: Path = DEFAULT_INI) -> tuple[bool, bool]:
    global _DEDUP_CONFIG_CACHE

    try:
        mtime = ini.stat().st_mtime_ns
    except OSError:
        _DEDUP_CONFIG_CACHE = (None, False, False)
        return False, False

    cached_mtime, cached_dedup, cached_strong = _DEDUP_CONFIG_CACHE
    if cached_mtime == mtime:
        return cached_dedup, cached_strong

    config = configparser.ConfigParser(interpolation=None)
    config.optionxform = str
    try:
        config.read(ini, encoding="utf-8-sig")
        dedup_value = config.getboolean(DEDUP_CONFIG_SECTION, DEDUP_CONFIG_KEY, fallback=False)
        strong_value = config.getboolean(DEDUP_CONFIG_SECTION, STRONG_DEDUP_CONFIG_KEY, fallback=False)
    except (configparser.Error, OSError, ValueError):
        dedup_value = False
        strong_value = False

    _DEDUP_CONFIG_CACHE = (mtime, dedup_value, strong_value)
    return dedup_value, strong_value


def queue_dedup_enabled(ini: Path = DEFAULT_INI) -> bool:
    return queue_dedup_settings(ini)[0]


def queued_arg_value(argv: list[str], flag: str, default: str | None = None) -> str | None:
    for index, item in enumerate(argv):
        if item == flag and index + 1 < len(argv):
            return argv[index + 1]
        if item.startswith(f"{flag}="):
            return item.split("=", 1)[1]
    return default


def queued_flag_present(argv: list[str], *flags: str) -> bool:
    return any(item in flags for item in argv)


def queued_command_mode(argv: list[str]) -> str:
    if queued_flag_present(argv, "--isolated", "-isolated"):
        return "isolated"
    return queued_arg_value(argv, "--mode", "full") or "full"


def queued_dedup_kind(job: dict) -> str:
    if job.get("kind") == "generated-refresh":
        return DEDUP_NONE
    argv = job.get("argv", [])
    if not isinstance(argv, list) or not all(isinstance(item, str) for item in argv):
        return DEDUP_NONE

    mode = queued_command_mode(argv)
    apply = queued_flag_present(argv, "--apply")
    remove_missing = queued_flag_present(argv, "--remove-missing")
    uid_only = queued_flag_present(argv, "--uid-only")
    reference_only = queued_flag_present(argv, "--reference-only")

    if mode in {
        "migrate-autogen",
        "migrate-reconstruction-h",
        "clear-dryrun-files",
        "execute-report",
        "invalidate-execute",
        "execute-rescan-reports",
        "execute-confirm-change",
        "execute-confirm-removed-archives",
        "executed-reassign",
        "executed-mark-invalid",
        "executed-mark-needs-revalidation",
        "executed-clear-revalidation",
        "active-clear-revalidation",
        "migrate-executed-reports",
        "migrate-report-agent-specs",
        "migrate-report-history",
    }:
        return DEDUP_NONE

    if not apply or mode == "isolated":
        return DEDUP_READ_ONLY

    if (
        mode in {"full", "documented", "rescore", "autogen"}
        and not remove_missing
        and not uid_only
        and not reference_only
    ):
        return DEDUP_GLOBAL_REFRESH

    return DEDUP_NONE


def queued_is_file_apply(job: dict) -> bool:
    argv = job.get("argv", [])
    if not isinstance(argv, list) or not all(isinstance(item, str) for item in argv):
        return False

    return queued_command_mode(argv) == "file" and queued_flag_present(argv, "--apply")


def queued_dedup_key(job: dict) -> str | None:
    argv = job.get("argv", [])
    cwd = job.get("cwd", "")
    if not isinstance(argv, list) or not all(isinstance(item, str) for item in argv):
        return None
    if not isinstance(cwd, str):
        return None

    return json.dumps(
        {
            "argv": argv,
            "cwd": cwd,
        },
        sort_keys=True,
        separators=(",", ":"),
    )


def job_result_paths(job: dict, queue_dir: Path, job_stem: str) -> list[Path]:
    raw_paths: list[str] = []

    result_path = job.get("result_path")
    if isinstance(result_path, str) and result_path:
        raw_paths.append(result_path)

    result_paths = job.get("result_paths")
    if isinstance(result_paths, list):
        raw_paths.extend(item for item in result_paths if isinstance(item, str) and item)

    if not raw_paths:
        raw_paths.append(str(queue_dir / "results" / f"{job_stem}.result.json"))

    seen: set[str] = set()
    paths: list[Path] = []
    for raw_path in raw_paths:
        path = Path(raw_path)
        key = os.path.normcase(str(path.resolve(strict=False)))
        if key in seen:
            continue
        seen.add(key)
        paths.append(path)
    return paths


def merge_result_paths(target_job: dict, target_path: Path, queue_dir: Path, source_jobs: list[tuple[Path, dict]]) -> None:
    merged = [str(path) for path in job_result_paths(target_job, queue_dir, target_path.stem)]
    seen = {os.path.normcase(str(Path(path).resolve(strict=False))) for path in merged}

    for source_path, source_job in source_jobs:
        for result_path in job_result_paths(source_job, queue_dir, source_path.stem):
            key = os.path.normcase(str(result_path.resolve(strict=False)))
            if key in seen:
                continue
            seen.add(key)
            merged.append(str(result_path))

    target_job["result_paths"] = merged
    write_json_atomic(target_job, target_path)


def read_queue_job(path: Path) -> dict | None:
    try:
        job = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return None
    return job if isinstance(job, dict) else None


def recover_processing_jobs(queue_dir: Path) -> None:
    jobs_dir = queue_dir / "jobs"
    processing_dir = queue_dir / "processing"
    jobs_dir.mkdir(parents=True, exist_ok=True)
    processing_dir.mkdir(parents=True, exist_ok=True)
    for path in sorted(processing_dir.glob("*.json")):
        target = jobs_dir / path.name
        if target.exists():
            target = jobs_dir / f"{path.stem}.recovered-{os.getpid()}{path.suffix}"
        path.replace(target)


def next_queued_job(queue_dir: Path) -> Path | None:
    jobs_dir = queue_dir / "jobs"
    jobs_dir.mkdir(parents=True, exist_ok=True)
    for path in sorted(jobs_dir.glob("*.json")):
        return path
    return None


def claim_queued_job(queue_dir: Path, path: Path) -> Path | None:
    processing_dir = queue_dir / "processing"
    processing_dir.mkdir(parents=True, exist_ok=True)
    claimed = processing_dir / path.name
    try:
        path.replace(claimed)
    except FileNotFoundError:
        return None
    return claimed


def queue_job_age_seconds(path: Path) -> float:
    try:
        return max(0.0, time.time() - path.stat().st_mtime)
    except OSError:
        return 0.0


def unlink_queue_jobs(paths: list[Path]) -> None:
    for path in paths:
        path.unlink(missing_ok=True)


def pending_jobs(queue_dir: Path) -> list[tuple[Path, dict | None]]:
    jobs_dir = queue_dir / "jobs"
    jobs_dir.mkdir(parents=True, exist_ok=True)
    return [(path, read_queue_job(path)) for path in sorted(jobs_dir.glob("*.json"))]


def job_has_merged_callers(job: dict) -> bool:
    result_paths = job.get("result_paths")
    return isinstance(result_paths, list) and bool(result_paths)


def strong_dedup_batch(jobs: list[tuple[Path, dict | None]]) -> list[tuple[Path, dict]]:
    batch: list[tuple[Path, dict]] = []
    for path, job in jobs:
        if job is None:
            break

        if queued_dedup_kind(job) == DEDUP_GLOBAL_REFRESH or queued_is_file_apply(job):
            batch.append((path, job))
            continue

        break
    return batch


def claim_strong_dedup_batch(
    queue_dir: Path,
    jobs: list[tuple[Path, dict | None]],
    first_path: Path,
    first_job: dict,
) -> Path | None:
    if queued_dedup_kind(first_job) != DEDUP_GLOBAL_REFRESH:
        return None

    batch = strong_dedup_batch(jobs)
    if not batch or batch[0][0] != first_path:
        return None

    for path, job in batch[1:]:
        if queued_is_file_apply(job):
            return claim_queued_job(queue_dir, path)

    if merge_global_refresh_to_latest(queue_dir, batch, first_path, first_job):
        return None

    return None


def merge_global_refresh_to_latest(
    queue_dir: Path,
    jobs: list[tuple[Path, dict | None]],
    first_path: Path,
    first_job: dict,
) -> bool:
    first_key = queued_dedup_key(first_job)
    if first_key is None or queued_dedup_kind(first_job) != DEDUP_GLOBAL_REFRESH:
        return False

    if job_has_merged_callers(first_job):
        return False

    matches: list[tuple[Path, dict]] = []
    for path, job in jobs:
        if job is None:
            continue
        if queued_dedup_kind(job) != DEDUP_GLOBAL_REFRESH:
            continue
        if queued_dedup_key(job) == first_key:
            matches.append((path, job))

    if len(matches) <= 1 or matches[0][0] != first_path:
        return False

    latest_path, latest_job = matches[-1]
    if job_has_merged_callers(latest_job):
        return False

    older_matches = matches[:-1]
    merge_result_paths(latest_job, latest_path, queue_dir, older_matches)
    unlink_queue_jobs([path for path, _ in older_matches])
    return True


def claim_read_only_duplicates(
    queue_dir: Path,
    jobs: list[tuple[Path, dict | None]],
    first_path: Path,
    first_job: dict,
) -> Path | None:
    first_key = queued_dedup_key(first_job)
    if first_key is None or queued_dedup_kind(first_job) != DEDUP_READ_ONLY:
        return claim_queued_job(queue_dir, first_path)

    duplicate_jobs: list[tuple[Path, dict]] = []
    for path, job in jobs[1:]:
        if job is None:
            break

        kind = queued_dedup_kind(job)
        if kind != DEDUP_READ_ONLY:
            break

        if queued_dedup_key(job) != first_key:
            break

        duplicate_jobs.append((path, job))

    if duplicate_jobs:
        merge_result_paths(first_job, first_path, queue_dir, duplicate_jobs)

    claimed = claim_queued_job(queue_dir, first_path)
    if claimed is not None and duplicate_jobs:
        unlink_queue_jobs([path for path, _ in duplicate_jobs])
    return claimed


def claim_next_queued_job(
    queue_dir: Path,
    queue_lock: Path,
    dedup_enabled: bool,
    strong_dedup_enabled: bool,
) -> Path | None:
    with ValidatorLock(queue_lock, -1):
        jobs = pending_jobs(queue_dir)
        if not jobs:
            return None

        first_path, first_job = jobs[0]
        if first_job is None:
            return claim_queued_job(queue_dir, first_path)

        if not dedup_enabled:
            return claim_queued_job(queue_dir, first_path)

        if queue_job_age_seconds(first_path) < DEDUP_COALESCE_SECONDS:
            return None

        if strong_dedup_enabled:
            strong_claimed = claim_strong_dedup_batch(queue_dir, jobs, first_path, first_job)
            if strong_claimed is not None:
                return strong_claimed
            refreshed_jobs = pending_jobs(queue_dir)
            if refreshed_jobs != jobs:
                return None

        return claim_read_only_duplicates(queue_dir, jobs, first_path, first_job)


def run_queued_validator_job(job: dict) -> dict:
    argv = job.get("argv", [])
    if not isinstance(argv, list) or not all(isinstance(item, str) for item in argv):
        return {
            "exit_code": 2,
            "stdout": "",
            "stderr": "invalid queued validator argv\n",
        }
    if "command_id" in job and "--command-id" not in argv:
        argv = [
            "--command-id",
            str(job.get("command_id", 0)),
            "--command-id-display",
            str(job.get("command_id_display", "")),
            "--command-timestamp",
            str(job.get("command_timestamp", "")),
            *argv,
        ]

    stdout_buffer = io.StringIO()
    stderr_buffer = io.StringIO()
    old_cwd = Path.cwd()
    cwd = job.get("cwd")
    try:
        if isinstance(cwd, str) and cwd:
            os.chdir(cwd)
        with contextlib.redirect_stdout(stdout_buffer), contextlib.redirect_stderr(stderr_buffer):
            try:
                exit_code = main(argv)
            except SystemExit as exc:
                if isinstance(exc.code, int):
                    exit_code = exc.code
                elif exc.code is None:
                    exit_code = 0
                else:
                    print(exc.code, file=sys.stderr)
                    exit_code = 1
            except BaseException:
                traceback.print_exc(file=sys.stderr)
                exit_code = 1
    finally:
        os.chdir(old_cwd)

    return {
        "exit_code": int(exit_code),
        "stdout": stdout_buffer.getvalue(),
        "stderr": stderr_buffer.getvalue(),
    }


def normalized_uid_set(values) -> set[str]:
    if not isinstance(values, list):
        return set()
    return {
        value.strip().upper()
        for value in values
        if isinstance(value, str) and re.fullmatch(r"[A-Z0-9]{6}", value.strip().upper())
    }


def normalized_path_set(values) -> set[str]:
    if not isinstance(values, list):
        return set()
    return {normalize_stored_path(value) for value in values if isinstance(value, str) and normalize_stored_path(value)}


def affected_paths_include_folder(
    config: configparser.ConfigParser,
    affected_uids: set[str],
    affected_paths: set[str],
    folder: str,
) -> bool:
    for rel in affected_paths:
        if first_folder_from_relative(rel) == folder:
            return True
    for uid in affected_uids:
        stored_path = config["files"].get(uid, "")
        if stored_path and first_folder_from_relative(normalize_stored_path(stored_path)) == folder:
            return True
    return False


def affected_paths_include_autogen(
    config: configparser.ConfigParser,
    affected_uids: set[str],
    affected_paths: set[str],
) -> bool:
    for rel in affected_paths:
        if autogen_report_name_for_path(rel) is not None:
            return True
    for uid in affected_uids:
        stored_path = config["files"].get(uid, "")
        if stored_path and autogen_report_name_for_path(stored_path) is not None:
            return True
        if parse_autogen_root_uids(config[AUTOGEN_ROOTS_SECTION].get(uid, "")):
            return True
    return False


def print_generated_refresh_summary(
    root: Path,
    ini: Path,
    lock_path: Path,
    refresh_scope: str,
    affected_uids: set[str],
    affected_paths: set[str],
    actions: list[ScanAction],
) -> None:
    print(f"root: {root}")
    print(f"ini: {ini}")
    print(f"lock: {lock_path}")
    print("mode: generated-refresh")
    print(f"refresh scope: {refresh_scope}")
    print(f"affected UIDs: {len(affected_uids)}")
    print(f"affected paths: {len(affected_paths)}")
    for name, count in sorted(summarize(actions).items()):
        print(f"{name}: {count}")
    print_actions(actions, root, False)


def run_generated_refresh_direct(job: dict) -> tuple[int, list[ScanAction]]:
    command_context = CommandContext(
        command_id=int(job.get("origin_command_id", 0) or 0),
        command_id_display=str(job.get("origin_command_id_display", "") or "000000000000"),
        command_timestamp=str(job.get("origin_command_timestamp", "") or ""),
    )
    root = Path(job.get("root") or str(DEFAULT_ROOT)).resolve()
    ini = Path(job.get("ini") or str(DEFAULT_INI)).resolve()
    lock_path = Path(job.get("lock") or str(DEFAULT_LOCK)).resolve()
    refresh_scope = str(job.get("refresh_scope", "") or "full-fallback")
    affected_uids = normalized_uid_set(job.get("affected_uids", []))
    affected_paths = normalized_path_set(job.get("affected_paths", []))
    actions: list[ScanAction] = []

    with ValidatorLock(lock_path, -1):
        config = load_config(ini)
        backup_state: dict[str, Path | None] = {"backup_root": None}

        if refresh_scope == "research-tracker":
            actions.extend(
                run_research_tracker_generation(
                    root,
                    config,
                    True,
                    backup_state=backup_state,
                    command_context=command_context,
                    refresh_source="deferred-generated-refresh",
                )
            )
        elif refresh_scope == "file-incremental":
            if affected_paths_include_autogen(config, affected_uids, affected_paths):
                actions.extend(
                    run_autogen_generation(
                        root,
                        config,
                        True,
                        command_context=command_context,
                        refresh_source="deferred-generated-refresh",
                        affected_uids=affected_uids,
                        affected_paths=affected_paths,
                    )
                )
            else:
                actions.append(
                    ScanAction(
                        "autogen_incremental_skip",
                        None,
                        root,
                        "affected file does not feed autogen reports",
                    )
                )
            actions.extend(
                run_research_tracker_generation(
                    root,
                    config,
                    True,
                    backup_state=backup_state,
                    command_context=command_context,
                    refresh_source="deferred-generated-refresh",
                )
            )
            if affected_paths_include_folder(config, affected_uids, affected_paths, "by-memory"):
                actions.extend(
                    run_by_memory_auto_coverage_generation(
                        root,
                        config,
                        True,
                        backup_state=backup_state,
                        command_context=command_context,
                        refresh_source="deferred-generated-refresh",
                    )
                )
        else:
            actions.extend(
                run_autogen_generation(
                    root,
                    config,
                    True,
                    command_context=command_context,
                    refresh_source="deferred-generated-refresh",
                )
            )
            actions.extend(
                run_research_tracker_generation(
                    root,
                    config,
                    True,
                    backup_state=backup_state,
                    command_context=command_context,
                    refresh_source="deferred-generated-refresh",
                )
            )
            actions.extend(
                run_by_memory_auto_coverage_generation(
                    root,
                    config,
                    True,
                    backup_state=backup_state,
                    command_context=command_context,
                    refresh_source="deferred-generated-refresh",
                )
            )

        if backup_state.get("backup_root") is not None:
            actions.append(ScanAction("autogen_backup_create", None, backup_state["backup_root"], "changed generated files backed up"))
        write_config_atomic(config, ini)
        save_metadata_cache(root)

    print_generated_refresh_summary(root, ini, lock_path, refresh_scope, affected_uids, affected_paths, actions)
    return 0, actions


def run_generated_refresh_job(job: dict) -> dict:
    command_id = job.get("origin_command_id", 0)
    command_id_display = job.get("origin_command_id_display", "")
    command_timestamp = job.get("origin_command_timestamp", "")
    stdout_buffer = io.StringIO()
    stderr_buffer = io.StringIO()
    try:
        with contextlib.redirect_stdout(stdout_buffer), contextlib.redirect_stderr(stderr_buffer):
            exit_code, _ = run_generated_refresh_direct(job)
    except BaseException:
        traceback.print_exc(file=stderr_buffer)
        exit_code = 1
    result = {
        "exit_code": int(exit_code),
        "stdout": stdout_buffer.getvalue(),
        "stderr": stderr_buffer.getvalue(),
    }
    result.update(
        {
            "kind": "generated-refresh",
            "origin_command_id": command_id,
            "origin_command_id_display": command_id_display,
            "origin_command_timestamp": command_timestamp,
            "affected_uids": job.get("affected_uids", []),
            "affected_paths": job.get("affected_paths", []),
            "refresh_scope": job.get("refresh_scope", ""),
            "recovery_command": "python .\\tools\\validator.py --mode autogen --apply --wait-generated",
        }
    )
    return result


def process_queued_job(queue_dir: Path, job_path: Path) -> None:
    result_path: Path | None = None
    result_paths: list[Path] = []
    try:
        job = json.loads(job_path.read_text(encoding="utf-8"))
        if job.get("kind") == "generated-refresh":
            result = run_generated_refresh_job(job)
            results_dir = queue_dir / "generated_refresh_results"
            results_dir.mkdir(parents=True, exist_ok=True)
            write_json_atomic(result, results_dir / f"{job_path.stem}.result.json")
            job_path.unlink(missing_ok=True)
            return
        raw_result_path = job.get("result_path")
        if isinstance(raw_result_path, str) and raw_result_path:
            result_path = Path(raw_result_path)
        else:
            result_path = queue_dir / "results" / f"{job_path.stem}.result.json"
        result_paths = job_result_paths(job, queue_dir, job_path.stem)
        result = run_queued_validator_job(job)
    except BaseException:
        if result_path is None:
            result_path = queue_dir / "results" / f"{job_path.stem}.result.json"
        if not result_paths:
            result_paths = [result_path]
        result = {
            "exit_code": 1,
            "stdout": "",
            "stderr": traceback.format_exc(),
        }

    if not result_paths:
        result_paths = [result_path]
    for path in result_paths:
        write_json_atomic(result, path)
    job_path.unlink(missing_ok=True)


def worker_main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description="Run the serialized validator background queue worker.")
    parser.add_argument("--queue-dir", type=Path, default=DEFAULT_QUEUE_DIR)
    parser.add_argument("--queue-lock", type=Path, default=DEFAULT_QUEUE_LOCK)
    parser.add_argument("--worker-lock", type=Path, default=DEFAULT_WORKER_LOCK)
    parser.add_argument("--poll-seconds", type=float, default=WORKER_POLL_SECONDS)
    parser.add_argument(
        "--idle-timeout",
        type=float,
        default=0.0,
        help="seconds to exit after no queued jobs; 0 keeps the worker alive",
    )
    args = parser.parse_args(argv)

    queue_dir = args.queue_dir.resolve()
    queue_lock = args.queue_lock.resolve()
    worker_lock = args.worker_lock.resolve()
    queue_dir.mkdir(parents=True, exist_ok=True)
    last_activity = time.monotonic()

    with ValidatorLock(worker_lock, 0):
        with ValidatorLock(queue_lock, -1):
            recover_processing_jobs(queue_dir)
        while True:
            dedup_enabled, strong_dedup_enabled = queue_dedup_settings()
            job_path = claim_next_queued_job(
                queue_dir,
                queue_lock,
                dedup_enabled,
                strong_dedup_enabled,
            )
            if job_path is not None:
                process_queued_job(queue_dir, job_path)
                last_activity = time.monotonic()
                continue

            if args.idle_timeout > 0 and time.monotonic() - last_activity >= args.idle_timeout:
                return 0
            time.sleep(max(args.poll_seconds, 0.05))


def command_positionals(items: list[str], maximum: int) -> tuple[list[str], list[str]]:
    positionals: list[str] = []
    rest: list[str] = []
    options_started = False
    for item in items:
        if not options_started and len(positionals) < maximum and not item.startswith("-"):
            positionals.append(item)
        else:
            options_started = True
            rest.append(item)
    return positionals, rest


def normalize_command_aliases(argv: list[str]) -> list[str]:
    if not argv:
        return argv
    command = COMMAND_ALIASES.get(argv[0])
    if command is None:
        return argv
    if command == "execute-report":
        positionals, rest = command_positionals(argv[1:], 3)
        if len(positionals) < 2:
            return argv
        normalized = ["--mode", command, "--agent-id", positionals[0], "--report-file", positionals[1]]
        if len(positionals) >= 3:
            normalized.extend(["--target-uid", positionals[2]])
        return normalized + rest
    if command in {
        "invalidate-execute",
        "execute-confirm-change",
        "executed-mark-invalid",
        "executed-mark-needs-revalidation",
        "executed-clear-revalidation",
        "active-clear-revalidation",
    }:
        positionals, rest = command_positionals(argv[1:], 2)
        if len(positionals) < 2 and "--report-path" not in rest and not any(item.startswith("--report-path=") for item in rest):
            return argv
        normalized = ["--mode", command]
        if len(positionals) >= 2:
            normalized.extend(["--agent-id", positionals[0], "--report-file", positionals[1]])
        return [*normalized, *rest]
    if command == "executed-reassign":
        positionals, rest = command_positionals(argv[1:], 3)
        if len(positionals) < 3:
            return argv
        return [
            "--mode",
            command,
            "--agent-id",
            positionals[0],
            "--report-file",
            positionals[1],
            "--new-agent-id",
            positionals[2],
            *rest,
        ]
    return ["--mode", command, *argv[1:]]


def main(argv: list[str] | None = None) -> int:
    if argv is None:
        argv = sys.argv[1:]
    argv = normalize_command_aliases(argv)
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=DEFAULT_ROOT)
    parser.add_argument("--ini", type=Path, default=DEFAULT_INI)
    parser.add_argument("--lock", type=Path, default=DEFAULT_LOCK)
    parser.add_argument(
        "--lock-timeout",
        type=float,
        default=300.0,
        help="seconds to wait for another validator process; use -1 to wait forever or 0 to fail immediately",
    )
    parser.add_argument(
        "--mode",
        choices=(
            "full",
            "documented",
            "file",
            "rescore",
            "isolated",
            "autogen",
            "migrate-autogen",
            "migrate-reconstruction-h",
            "clear-dryrun-files",
            "execute-report",
            "invalidate-execute",
            "execute-rescan-reports",
            "execute-confirm-change",
            "execute-confirm-removed-archives",
            "executed-reassign",
            "executed-mark-invalid",
            "executed-mark-needs-revalidation",
            "executed-clear-revalidation",
            "active-clear-revalidation",
            "migrate-executed-reports",
            "migrate-report-agent-specs",
            "migrate-report-history",
        ),
        default="full",
    )
    parser.add_argument(
        "-isolated",
        "--isolated",
        action="store_true",
        help="alias for --mode isolated; report by-* Markdown files with no inbound UID references",
    )
    parser.add_argument("--file", help="Markdown file to scan when --mode file is used")
    parser.add_argument("--agent-id", help="agent id for executed-report lifecycle modes")
    parser.add_argument("--new-agent-id", help="new agent id for executed-reassign")
    parser.add_argument("--report-file", help="report filename for executed-report lifecycle modes")
    parser.add_argument("--report-path", help="executed report path for lifecycle modes that support path targeting")
    parser.add_argument("--migration-id", help="staged migration id for migrate-reconstruction-h --apply")
    parser.add_argument("--reason", help="reason for executed-mark-needs-revalidation")
    parser.add_argument("--target-uid", help="target UID override for execute-report")
    parser.add_argument("--command-id", type=int, default=0, help=argparse.SUPPRESS)
    parser.add_argument("--command-id-display", default="", help=argparse.SUPPRESS)
    parser.add_argument("--command-timestamp", default="", help=argparse.SUPPRESS)
    parser.add_argument("--refresh-source", default="foreground-generated-refresh", help=argparse.SUPPRESS)
    parser.add_argument(
        "--wait-generated",
        action="store_true",
        help="run generated CPP/H and auto-generated Markdown refresh before returning",
    )
    parser.add_argument(
        "--no-generated-refresh",
        action="store_true",
        help="skip generated CPP/H and auto-generated Markdown refresh scheduling",
    )
    parser.add_argument("--apply", action="store_true", help="write Markdown and validator.ini changes")
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="with --mode migrate-autogen, write migrated *.dryrun artifacts and validator.ini.dryrun",
    )
    parser.add_argument(
        "--use-existing-dryrun",
        action="store_true",
        help="with --mode migrate-autogen --dry-run, use existing *.dryrun inputs and validator.ini.dryrun",
    )
    parser.add_argument(
        "--remove-missing",
        action="store_true",
        help="with full/documented scans, remove validator.ini UID mappings not found in by-* Markdown files",
    )
    phase_group = parser.add_mutually_exclusive_group()
    phase_group.add_argument(
        "--uid-only",
        action="store_true",
        help="only check/create document metadata headers and validator.ini mappings",
    )
    phase_group.add_argument(
        "--reference-only",
        action="store_true",
        help="only update [UID:...] reference annotations; do not create missing document UIDs",
    )
    parser.add_argument("--verbose", action="store_true", help="print ok rows too")
    args = parser.parse_args(argv)

    if args.isolated:
        args.mode = "isolated"

    root = args.root.resolve()
    ini = args.ini.resolve()
    lock_path = args.lock.resolve()
    with ValidatorLock(lock_path, args.lock_timeout):
        return run_validator(args, root, ini, lock_path)


if __name__ == "__main__":
    if len(sys.argv) > 1 and sys.argv[1] == "--worker":
        raise SystemExit(worker_main(sys.argv[2:]))
    raise SystemExit(main())
