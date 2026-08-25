#!/usr/bin/env python3
"""Generate binary memory-range coverage reports from by-memory filenames."""

from __future__ import annotations

import argparse
import json
import re
import tempfile
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Any


TOOL_DIR = Path(__file__).resolve().parent
DOC_ROOT = TOOL_DIR.parent
DEFAULT_DATA_PATH = TOOL_DIR / "memory_ranges.data"
DEFAULT_BY_MEMORY_PATH = DOC_ROOT / "by-memory"
DEFAULT_REPORT_PATH = DOC_ROOT / "auto-generated" / "by-memory-tool-report.md"
MIGRATION_DRYRUN_MANIFEST = TOOL_DIR / "autogen_owner_emitter_migration_dryrun_manifest.json"

RANGE_FILE_RE = re.compile(
    r"^(?P<start>0x[0-9a-fA-F]+)-(?P<end>0x[0-9a-fA-F]+)\.(?P<label>.+)\.md$"
)
RECONSTRUCTABLE_RE = re.compile(
    r"^\*\*\*\s*RECONSTRUCTABLE:(?P<value>[^|\r\n]*)\s*\|",
    re.MULTILINE,
)
AUTOGEN_PARENT_UID_RE = re.compile(
    r"^\*\*\*\s*AUTOGEN_PARENT_UID:(?P<value>[^|\r\n]*)\s*\|",
    re.MULTILINE,
)
CANONICAL_OWNER_RE = re.compile(
    r"^\*\*\*\s*CANONICAL_OWNER:(?P<value>[^|\r\n]*)\s*\|",
    re.MULTILINE,
)
EMITTER_UIDS_RE = re.compile(
    r"^\*\*\*\s*EMITTER_UIDS:(?P<value>[^|\r\n]*)\s*\|",
    re.MULTILINE,
)
RECONSTRUCTION_CPP_INLINE_RE = re.compile(
    r"^\*\*\*\s*RECONSTRUCTION_CPP CODE:\[\[\[(?P<value>.*)\]\]\]\s*\|",
    re.MULTILINE,
)
RECONSTRUCTION_CPP_BEGIN = (
    "*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***"
)
RECONSTRUCTION_CPP_END = "*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***"
RECONSTRUCTION_H_BEGIN = (
    "*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***"
)
RECONSTRUCTION_H_END = "*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***"
HEADING_RE = re.compile(r"^(?P<marks>#{1,6})\s+(?P<title>.+?)\s*$", re.MULTILINE)

DEFAULT_NOT_RECONSTRUCTABLE_TYPES = [
    "CRT/MSVC",
    "third-party-library",
    "compiler-generated",
    "runtime-support",
    "import-thunk",
    "static-initializer-wrapper",
    "aggregate-container",
    "mixed-owner-container",
    "duplicate-container",
    "vtable-rtti-data",
    "resource-data-index",
    "dead-unreferenced",
]

DEFAULT_ADVANCED_GENERATED_NAME_PATTERNS = [
    {
        "name": "ida-function-label",
        "pattern": r"\b(?:sub|func|FUN)_[0-9A-Fa-f]{4,16}\b",
    },
    {
        "name": "ida-data-label",
        "pattern": (
            r"\b(?:byte|word|dword|qword|xmmword|ymmword|zmmword|oword|tbyte|"
            r"unk|off|DAT|PTR|LAB|loc|jpt|vftable|stru|asc|flt|dbl)_[0-9A-Fa-f]{4,16}\b"
        ),
    },
    {
        "name": "generated-class-or-method",
        "pattern": r"\b(?:Class_[0-9A-Fa-f]{4,16}|cls_0x[0-9A-Fa-f]+|meth_0x[0-9A-Fa-f]+)\b",
    },
    {
        "name": "generated-member-or-stack-name",
        "pattern": r"\b(?:field|mbr|slot|vftptr|local|param)_[0-9A-Fa-f]+\b",
    },
    {
        "name": "runtime-nullsub-label",
        "pattern": r"\bnullsub_[0-9]+\b",
    },
]

CLASSIFICATION_ALIASES = {
    "reconstructable": "reconstructable",
    "reconstructible": "reconstructable",
    "not-reconstructable": "not_reconstructable",
    "not_reconstructable": "not_reconstructable",
    "non-reconstructable": "not_reconstructable",
    "non_reconstructable": "not_reconstructable",
    "notreconstructable": "not_reconstructable",
    "ignored": "not_reconstructable",
    "ignore": "not_reconstructable",
    "padding": "padding_zero_filled",
    "zero": "padding_zero_filled",
    "zero-filled": "padding_zero_filled",
    "zero_filled": "padding_zero_filled",
    "padding-zero-filled": "padding_zero_filled",
    "padding_zero_filled": "padding_zero_filled",
    "padding-and-zero-filled": "padding_zero_filled",
    "other": "other",
}

CLASSIFICATION_LABELS = {
    "reconstructable": "Reconstructable",
    "not_reconstructable": "Not-Reconstructable",
    "padding_zero_filled": "Padding-And-Zero-Filled",
    "other": "Other",
    "uncovered": "UNCOVERED",
}

DEFAULT_CONFIG: dict[str, Any] = {
    "binary_range": {
        "start": "0x00401000",
        "end": "0x0069d000",
        "end_semantics": "exclusive",
    },
    "by_memory_path": "../by-memory",
    "report_path": "../auto-generated/by-memory-tool-report.md",
    "largest_ranges_limit": 25,
    "not_reconstructable_types": DEFAULT_NOT_RECONSTRUCTABLE_TYPES,
    "file_classifications": {},
    "manual_ranges": [],
    "ignored_crossings": [],
    "advanced_scan": {
        "run_by_default": False,
        "generated_name_patterns": DEFAULT_ADVANCED_GENERATED_NAME_PATTERNS,
        "ignore_section_heading_patterns": [
            r"\bchanges?\b",
            r"\bchange\s+log\b",
            r"\bchangelog\b",
            r"\bupdates?\b",
            r"\bmodified\b",
            r"\bmodifications?\b",
            r"\bhistory\b",
        ]
    },
}


@dataclass
class RangeRecord:
    start: int
    end: int
    label: str
    classification: str
    source_kind: str
    subtype: str = ""
    reason: str = ""
    path: Path | None = None
    file_name: str = ""
    header_status: str = ""
    canonical_owner: str = ""
    emitter_uids: tuple[str, ...] = ()
    emits_code: bool = False
    emits_header_code: bool = False
    config_index: int | None = None

    @property
    def size(self) -> int:
        return self.end - self.start

    @property
    def source_name(self) -> str:
        if self.file_name:
            return self.file_name
        return self.label or "(manual range)"

    @property
    def has_owner(self) -> bool:
        return self.canonical_owner.strip().upper() not in {"", "NONE"}

    @property
    def emits(self) -> bool:
        return bool(self.emitter_uids)

    @property
    def multiple_emitters(self) -> bool:
        return len(self.emitter_uids) > 1


@dataclass
class LeafSegment:
    start: int
    end: int
    record: RangeRecord | None
    classification: str
    subtype: str = ""

    @property
    def size(self) -> int:
        return self.end - self.start


@dataclass
class IgnoredCrossing:
    parent: RangeRecord
    child: RangeRecord
    reason: str
    config_index: int


def deep_merge(defaults: dict[str, Any], loaded: dict[str, Any]) -> dict[str, Any]:
    merged = dict(defaults)
    for key, value in loaded.items():
        if isinstance(value, dict) and isinstance(merged.get(key), dict):
            merged[key] = deep_merge(merged[key], value)
        else:
            merged[key] = value
    return merged


def read_json(path: Path) -> dict[str, Any]:
    if not path.exists():
        return dict(DEFAULT_CONFIG)
    try:
        loaded = json.loads(path.read_text(encoding="utf-8-sig"))
    except json.JSONDecodeError as exc:
        raise SystemExit(f"failed to parse {path}: {exc}") from exc
    if not isinstance(loaded, dict):
        raise SystemExit(f"{path} must contain a JSON object")
    return deep_merge(DEFAULT_CONFIG, loaded)


def write_json_atomic(data: dict[str, Any], path: Path) -> None:
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


def resolve_config_path(value: str | None, default: Path) -> Path:
    if not value:
        return default
    path = Path(value)
    if path.is_absolute():
        return path
    return (TOOL_DIR / path).resolve()


def parse_hex(value: str, field_name: str = "address") -> int:
    if not isinstance(value, str) or not re.fullmatch(r"0x[0-9a-fA-F]+", value.strip()):
        raise SystemExit(f"{field_name} must be a hex address like 0x00401000")
    return int(value, 16)


def format_hex(value: int) -> str:
    return f"0x{value:08x}"


def format_range(start: int, end: int) -> str:
    return f"{format_hex(start)}-{format_hex(end)}"


def range_overlaps(left_start: int, left_end: int, right_start: int, right_end: int) -> bool:
    return left_start < right_end and right_start < left_end


def parse_end_semantics(config: dict[str, Any]) -> str:
    value = str(config.get("binary_range", {}).get("end_semantics", "exclusive")).casefold()
    if value not in {"exclusive", "inclusive"}:
        raise SystemExit("binary_range.end_semantics must be 'exclusive' or 'inclusive'")
    return value


def end_to_internal(end: int, config: dict[str, Any]) -> int:
    return end + 1 if parse_end_semantics(config) == "inclusive" else end


def parse_config_range(config: dict[str, Any], key: str = "binary_range") -> tuple[int, int]:
    section = config.get(key)
    if not isinstance(section, dict):
        raise SystemExit(f"{key} must be a JSON object")
    start = parse_hex(section.get("start", ""), f"{key}.start")
    end = parse_hex(section.get("end", ""), f"{key}.end")
    if parse_end_semantics(config) == "inclusive":
        end += 1
    if start >= end:
        raise SystemExit(f"{key} start must be below end")
    return start, end


def parse_range_from_file_name(file_name: str) -> tuple[int, int]:
    match = RANGE_FILE_RE.fullmatch(Path(file_name).name)
    if not match:
        raise SystemExit(f"{file_name}: expected 0xSTART-0xEND.Name.md range filename")
    start = int(match.group("start"), 16)
    end = int(match.group("end"), 16)
    if start >= end:
        raise SystemExit(f"{file_name}: start address is not below end address")
    return start, end


def parse_range_token(value: str, field_name: str = "range") -> tuple[int, int]:
    match = re.fullmatch(
        r"\s*(0x[0-9a-fA-F]+)-(0x[0-9a-fA-F]+)\s*",
        value,
    )
    if not match:
        raise SystemExit(f"{field_name} must be a range like 0x00401000-0x00402000")
    start = parse_hex(match.group(1), f"{field_name}.start")
    end = parse_hex(match.group(2), f"{field_name}.end")
    if start >= end:
        raise SystemExit(f"{field_name}: start address is not below end address")
    return start, end


def crossing_key(parent: RangeRecord, child: RangeRecord) -> tuple[int, int, int, int]:
    return parent.start, parent.end, child.start, child.end


def crossing_key_from_ranges(
    parent_start: int,
    parent_end: int,
    child_start: int,
    child_end: int,
) -> tuple[int, int, int, int]:
    return parent_start, parent_end, child_start, child_end


def parse_manual_entry_bounds(
    entry: dict[str, Any],
    index: int,
    config: dict[str, Any],
) -> tuple[int, int, int]:
    start = parse_hex(str(entry.get("start", "")), f"manual_ranges[{index}].start")
    end = parse_hex(str(entry.get("end", "")), f"manual_ranges[{index}].end")
    internal_end = end_to_internal(end, config)
    if start >= internal_end:
        raise SystemExit(f"manual_ranges[{index}]: start address is not below end address")
    return start, end, internal_end


def normalize_classification(value: str) -> str:
    normalized = value.strip().casefold().replace(" ", "-")
    if normalized not in CLASSIFICATION_ALIASES:
        valid = ", ".join(sorted(set(CLASSIFICATION_ALIASES.values())))
        raise SystemExit(f"unknown classification {value!r}; use one of: {valid}")
    return CLASSIFICATION_ALIASES[normalized]


def parse_reconstructable_status(text: str) -> str:
    match = RECONSTRUCTABLE_RE.search(text)
    if not match:
        return "missing"
    raw = match.group("value").strip().upper()
    if raw == "":
        return "blank"
    if raw in {"TRUE", "1"}:
        return "true"
    if raw in {"FALSE", "0"}:
        return "false"
    return "invalid"


def parse_parent_uid(text: str) -> str:
    match = AUTOGEN_PARENT_UID_RE.search(text)
    if not match:
        return ""
    return match.group("value").strip().upper()


def parse_canonical_owner(text: str) -> str:
    match = CANONICAL_OWNER_RE.search(text)
    if match:
        value = match.group("value").strip().upper()
        return value or "NONE"
    legacy_parent = parse_parent_uid(text)
    return legacy_parent or "NONE"


def parse_emitter_uids(text: str, reconstructable_status: str) -> tuple[str, ...]:
    match = EMITTER_UIDS_RE.search(text)
    if match:
        raw = match.group("value").strip().upper()
        if not raw:
            return ()
        return tuple(item.strip().upper() for item in raw.split(",") if item.strip())
    legacy_parent = parse_parent_uid(text)
    if reconstructable_status == "true" and legacy_parent:
        return (legacy_parent,)
    return ()


def parse_emits_code(text: str) -> bool:
    inline = RECONSTRUCTION_CPP_INLINE_RE.search(text)
    if inline and inline.group("value").strip():
        return True

    lines = text.splitlines()
    in_block = False
    block_lines: list[str] = []
    for line in lines:
        if line.strip() == RECONSTRUCTION_CPP_BEGIN:
            in_block = True
            continue
        if line.strip() == RECONSTRUCTION_CPP_END:
            break
        if in_block:
            block_lines.append(line)
    return bool("\n".join(block_lines).strip())


def parse_emits_header_code(text: str) -> bool:
    lines = text.splitlines()
    begin_indexes = [index for index, line in enumerate(lines) if line == RECONSTRUCTION_H_BEGIN]
    end_indexes = [index for index, line in enumerate(lines) if line == RECONSTRUCTION_H_END]
    if len(begin_indexes) != 1 or len(end_indexes) != 1 or begin_indexes[0] > end_indexes[0]:
        return False
    return bool("\n".join(lines[begin_indexes[0] + 1 : end_indexes[0]]).strip())


def parse_file_metadata(text: str) -> tuple[str, str, tuple[str, ...], bool, bool]:
    reconstructable_status = parse_reconstructable_status(text)
    return (
        reconstructable_status,
        parse_canonical_owner(text),
        parse_emitter_uids(text, reconstructable_status),
        parse_emits_code(text),
        parse_emits_header_code(text),
    )


def default_classification_for_header(header_status: str) -> str:
    if header_status == "true":
        return "reconstructable"
    if header_status == "false":
        return "not_reconstructable"
    return "other"


def configured_not_reconstructable_types(config: dict[str, Any]) -> list[str]:
    values = config.get("not_reconstructable_types", DEFAULT_NOT_RECONSTRUCTABLE_TYPES)
    if not isinstance(values, list):
        raise SystemExit("not_reconstructable_types must be a JSON array")
    seen: set[str] = set()
    result: list[str] = []
    for value in values:
        type_name = str(value).strip()
        if not type_name:
            continue
        key = type_name.casefold()
        if key in seen:
            continue
        seen.add(key)
        result.append(type_name)
    return result


def normalize_not_reconstructable_type(type_name: str, config: dict[str, Any]) -> str:
    stripped = type_name.strip()
    if not stripped:
        raise SystemExit("not-reconstructable type must not be blank")
    for built_in in configured_not_reconstructable_types(config):
        if built_in.casefold() == stripped.casefold():
            return built_in
    return stripped


def validate_subtype_for_classification(
    classification: str,
    subtype: str,
    source_name: str,
) -> str | None:
    if subtype and classification != "not_reconstructable":
        return (
            f"{source_name}: type/subtype is only allowed for Not-Reconstructable entries; "
            f"{CLASSIFICATION_LABELS.get(classification, classification)} entries must be untyped"
        )
    return None


def read_text(path: Path) -> str:
    try:
        return path.read_text(encoding="utf-8-sig")
    except UnicodeDecodeError:
        return path.read_text(encoding="utf-8", errors="replace")


def dryrun_artifact_path(path: Path) -> Path:
    return Path(f"{path}.dryrun")


def memory_source_path(path: Path, use_existing_dryrun: bool) -> Path:
    dryrun_path = dryrun_artifact_path(path)
    if use_existing_dryrun and dryrun_path.exists():
        return dryrun_path
    return path


def file_key_from_argument(value: str, by_memory_path: Path) -> str:
    path = Path(value)
    if path.is_absolute():
        return path.name
    parts = list(path.parts)
    lowered = [part.casefold() for part in parts]
    if "by-memory" in lowered:
        index = lowered.index("by-memory")
        if index + 1 < len(parts):
            return parts[index + 1]
    candidate = by_memory_path / value
    if candidate.exists():
        return candidate.name
    return path.name


def get_file_override(config: dict[str, Any], file_name: str) -> dict[str, Any] | None:
    overrides = config.get("file_classifications", {})
    if not isinstance(overrides, dict):
        raise SystemExit("file_classifications must be a JSON object")
    direct = overrides.get(file_name)
    if direct is not None:
        if not isinstance(direct, dict):
            raise SystemExit(f"file classification for {file_name} must be an object")
        return direct
    for key, value in overrides.items():
        if Path(str(key)).name == file_name:
            if not isinstance(value, dict):
                raise SystemExit(f"file classification for {key} must be an object")
            return value
    return None


def validate_classification_against_header(
    classification: str,
    header_status: str,
    source_name: str,
) -> str | None:
    if classification == "not_reconstructable" and header_status != "false":
        return (
            f"{source_name}: marked Not-Reconstructable in memory_ranges.data "
            f"but header RECONSTRUCTABLE status is {header_status!r}"
        )
    if classification == "reconstructable" and header_status != "true":
        return (
            f"{source_name}: marked Reconstructable in memory_ranges.data "
            f"but header RECONSTRUCTABLE status is {header_status!r}"
        )
    return None


def scan_by_memory_files(
    by_memory_path: Path,
    config: dict[str, Any],
    use_existing_dryrun: bool = False,
) -> tuple[list[RangeRecord], list[str], list[str], dict[str, int]]:
    records: list[RangeRecord] = []
    filename_errors: list[str] = []
    general_errors: list[str] = []
    stats = {
        "ignored_support_files": 0,
        "ignored_non_md_files": 0,
        "ignored_non_range_md_files": 0,
    }
    seen_override_keys: set[str] = set()

    if not by_memory_path.exists():
        raise SystemExit(f"by-memory path does not exist: {by_memory_path}")

    for path in sorted(by_memory_path.iterdir(), key=lambda p: p.name.casefold()):
        if not path.is_file():
            continue
        name = path.name
        if name.startswith("-"):
            stats["ignored_support_files"] += 1
            continue
        if path.suffix.casefold() != ".md":
            stats["ignored_non_md_files"] += 1
            if name.casefold().startswith("0x"):
                filename_errors.append(f"{name}: range-like file is not Markdown")
            continue
        if not name.casefold().startswith("0x"):
            stats["ignored_non_range_md_files"] += 1
            continue

        match = RANGE_FILE_RE.match(name)
        if not match:
            filename_errors.append(
                f"{name}: expected 0xSTART-0xEND.Name.md range filename"
            )
            continue

        start = int(match.group("start"), 16)
        end = int(match.group("end"), 16)
        label = match.group("label")
        if start >= end:
            filename_errors.append(f"{name}: start address is not below end address")
            continue

        text = read_text(memory_source_path(path, use_existing_dryrun))
        header_status, canonical_owner, emitter_uids, emits_code, emits_header_code = parse_file_metadata(text)
        classification = default_classification_for_header(header_status)
        subtype = ""
        reason = ""

        override = get_file_override(config, name)
        if override is not None:
            seen_override_keys.add(name)
            raw_classification = str(override.get("classification", classification))
            classification = normalize_classification(raw_classification)
            subtype = str(override.get("type", "")).strip()
            if subtype and classification == "not_reconstructable":
                subtype = normalize_not_reconstructable_type(subtype, config)
            reason = str(override.get("reason", "")).strip()
            error = validate_classification_against_header(
                classification,
                header_status,
                name,
            )
            if error:
                general_errors.append(error)
            error = validate_subtype_for_classification(classification, subtype, name)
            if error:
                general_errors.append(error)

        records.append(
            RangeRecord(
                start=start,
                end=end,
                label=label,
                classification=classification,
                subtype=subtype,
                reason=reason,
                source_kind="file",
                path=path,
                file_name=name,
                header_status=header_status,
                canonical_owner=canonical_owner,
                emitter_uids=emitter_uids,
                emits_code=emits_code,
                emits_header_code=emits_header_code,
            )
        )

    overrides = config.get("file_classifications", {})
    if isinstance(overrides, dict):
        known_file_names = {record.file_name for record in records}
        for key in sorted(overrides):
            file_name = Path(str(key)).name
            if file_name not in known_file_names and file_name not in seen_override_keys:
                general_errors.append(f"{key}: file classification target was not found")

    return records, filename_errors, general_errors, stats


def parse_manual_ranges(
    config: dict[str, Any],
    by_memory_path: Path,
    use_existing_dryrun: bool = False,
) -> tuple[list[RangeRecord], list[str]]:
    manual_ranges = config.get("manual_ranges", [])
    if not isinstance(manual_ranges, list):
        raise SystemExit("manual_ranges must be a JSON array")
    records: list[RangeRecord] = []
    errors: list[str] = []

    for index, entry in enumerate(manual_ranges):
        if not isinstance(entry, dict):
            errors.append(f"manual_ranges[{index}]: entry must be an object")
            continue
        try:
            start, _stored_end, end = parse_manual_entry_bounds(entry, index, config)
        except SystemExit as exc:
            errors.append(str(exc))
            continue
        try:
            classification = normalize_classification(str(entry.get("classification", "other")))
        except SystemExit as exc:
            errors.append(str(exc))
            continue

        label = str(entry.get("label", "")).strip()
        subtype = str(entry.get("type", "")).strip()
        if subtype and classification == "not_reconstructable":
            subtype = normalize_not_reconstructable_type(subtype, config)
        error = validate_subtype_for_classification(
            classification,
            subtype,
            f"manual_ranges[{index}]",
        )
        if error:
            errors.append(error)
        reason = str(entry.get("reason", "")).strip()
        file_name = ""
        header_status = ""
        canonical_owner = ""
        emitter_uids: tuple[str, ...] = ()
        emits_code = False
        emits_header_code = False
        raw_file = str(entry.get("file", "")).strip()
        if raw_file:
            file_name = file_key_from_argument(raw_file, by_memory_path)
            target = by_memory_path / file_name
            if target.exists():
                header_status, canonical_owner, emitter_uids, emits_code, emits_header_code = parse_file_metadata(
                    read_text(memory_source_path(target, use_existing_dryrun))
                )
                error = validate_classification_against_header(
                    classification,
                    header_status,
                    f"manual_ranges[{index}] {file_name}",
                )
                if error:
                    errors.append(error)
            else:
                errors.append(f"manual_ranges[{index}]: file target was not found: {raw_file}")

        records.append(
            RangeRecord(
                start=start,
                end=end,
                label=label or f"manual_ranges[{index}]",
                classification=classification,
                subtype=subtype,
                reason=reason,
                source_kind="manual",
                file_name=file_name,
                header_status=header_status,
                canonical_owner=canonical_owner,
                emitter_uids=emitter_uids,
                emits_code=emits_code,
                emits_header_code=emits_header_code,
                config_index=index,
            )
        )

    for left_index, left in enumerate(records):
        for right in records[left_index + 1 :]:
            if range_overlaps(left.start, left.end, right.start, right.end):
                errors.append(
                    f"manual_ranges[{left.config_index}] {format_range(left.start, left.end)} "
                    f"{left.label!r} overlaps manual_ranges[{right.config_index}] "
                    f"{format_range(right.start, right.end)} {right.label!r}"
                )

    return records, errors


def intersect_range(
    start: int,
    end: int,
    clip_start: int,
    clip_end: int,
) -> tuple[int, int] | None:
    clipped_start = max(start, clip_start)
    clipped_end = min(end, clip_end)
    if clipped_start >= clipped_end:
        return None
    return clipped_start, clipped_end


def compute_leaf_segments(
    records: list[RangeRecord],
    binary_start: int,
    binary_end: int,
) -> list[LeafSegment]:
    boundaries = {binary_start, binary_end}
    usable_records: list[RangeRecord] = []
    for record in records:
        clipped = intersect_range(record.start, record.end, binary_start, binary_end)
        if clipped is None:
            continue
        boundaries.update(clipped)
        usable_records.append(record)

    ordered_boundaries = sorted(boundaries)
    segments: list[LeafSegment] = []

    for start, end in zip(ordered_boundaries, ordered_boundaries[1:]):
        if start >= end:
            continue
        covering = [
            record
            for record in usable_records
            if record.start <= start and end <= record.end
        ]
        if not covering:
            segment = LeafSegment(start, end, None, "uncovered")
        else:
            winner = min(
                covering,
                key=lambda record: (
                    record.size,
                    0 if record.source_kind == "manual" else 1,
                    record.source_name.casefold(),
                ),
            )
            segment = LeafSegment(
                start,
                end,
                winner,
                winner.classification,
                winner.subtype,
            )
        if (
            segments
            and segments[-1].end == segment.start
            and segments[-1].record is segment.record
            and segments[-1].classification == segment.classification
            and segments[-1].subtype == segment.subtype
        ):
            segments[-1].end = segment.end
        else:
            segments.append(segment)

    return segments


def accumulate_segment_bytes(segments: list[LeafSegment]) -> dict[str, int]:
    totals = {
        "reconstructable": 0,
        "not_reconstructable": 0,
        "padding_zero_filled": 0,
        "other": 0,
        "uncovered": 0,
    }
    for segment in segments:
        totals[segment.classification] = totals.get(segment.classification, 0) + segment.size
    return totals


def accumulate_subtype_bytes(
    segments: list[LeafSegment],
    classification: str,
) -> dict[str, int]:
    totals: dict[str, int] = {}
    for segment in segments:
        if segment.classification != classification:
            continue
        subtype = segment.subtype.strip() if segment.subtype else "(untyped)"
        totals[subtype] = totals.get(subtype, 0) + segment.size
    return totals


def accumulate_reconstructable_emission_bytes(segments: list[LeafSegment]) -> dict[str, int]:
    totals = {
        "no_owner": 0,
        "emits": 0,
        "non_emits": 0,
        "multiple_emitters": 0,
        "emits_code": 0,
        "does_not_emit_code": 0,
        "emits_header_code": 0,
        "does_not_emit_header_code": 0,
    }
    for segment in segments:
        if segment.classification != "reconstructable":
            continue
        record = segment.record
        if record is not None and record.emits:
            totals["emits"] += segment.size
            if record.multiple_emitters:
                totals["multiple_emitters"] += segment.size
            if record.emits_code:
                totals["emits_code"] += segment.size
            else:
                totals["does_not_emit_code"] += segment.size
            if record.emits_header_code:
                totals["emits_header_code"] += segment.size
            else:
                totals["does_not_emit_header_code"] += segment.size
        else:
            totals["non_emits"] += segment.size
        if record is None or not record.has_owner:
            totals["no_owner"] += segment.size
    return totals


def percent(part: int, total: int) -> str:
    if total <= 0:
        return "0.000%"
    return f"{(part * 100.0 / total):.3f}%"


def find_barrier_crossings(records: list[RangeRecord]) -> list[tuple[RangeRecord, RangeRecord]]:
    crossings: list[tuple[RangeRecord, RangeRecord]] = []
    ordered = sorted(records, key=lambda r: (r.start, r.end, r.source_name.casefold()))
    for index, first in enumerate(ordered):
        for second in ordered[index + 1 :]:
            if second.start >= first.end:
                break
            if first.start <= second.start and second.end <= first.end:
                continue
            if second.start <= first.start and first.end <= second.end:
                continue
            crossings.append((first, second))
    return crossings


def parse_ignored_crossings(
    config: dict[str, Any],
    crossings: list[tuple[RangeRecord, RangeRecord]],
) -> list[IgnoredCrossing]:
    entries = config.get("ignored_crossings", [])
    if not isinstance(entries, list):
        raise SystemExit("ignored_crossings must be a JSON array")

    current = {crossing_key(parent, child): (parent, child) for parent, child in crossings}
    ignored: list[IgnoredCrossing] = []
    seen: set[tuple[int, int, int, int]] = set()

    for index, entry in enumerate(entries):
        if not isinstance(entry, dict):
            raise SystemExit(f"ignored_crossings[{index}]: entry must be an object")
        parent_range = str(entry.get("parent_range", "")).strip()
        crossing_range = str(entry.get("crossing_range", "")).strip()
        parent_start, parent_end = parse_range_token(
            parent_range,
            f"ignored_crossings[{index}].parent_range",
        )
        child_start, child_end = parse_range_token(
            crossing_range,
            f"ignored_crossings[{index}].crossing_range",
        )
        key = crossing_key_from_ranges(parent_start, parent_end, child_start, child_end)
        if key in seen:
            continue
        seen.add(key)
        pair = current.get(key)
        if pair is None:
            continue
        reason = str(entry.get("reason", "")).strip()
        ignored.append(IgnoredCrossing(pair[0], pair[1], reason, index))

    return ignored


def record_display(record: RangeRecord) -> str:
    base = f"`{format_range(record.start, record.end)}`"
    if record.source_kind == "file":
        base += f" `{record.file_name}`"
    else:
        base += f" manual `{record.label}`"
    base += f" [{CLASSIFICATION_LABELS.get(record.classification, record.classification)}"
    if record.subtype:
        base += f" / {record.subtype}"
    base += "]"
    return base


def normalize_alnum(text: str) -> str:
    return re.sub(r"[^0-9a-z]+", "", text.casefold())


def section_matches_ignored_heading(title: str, patterns: list[str]) -> bool:
    for pattern in patterns:
        try:
            if re.search(pattern, title, re.IGNORECASE):
                return True
        except re.error:
            if pattern.casefold() in title.casefold():
                return True
    return False


def remove_ignored_sections(text: str, patterns: list[str]) -> str:
    matches = list(HEADING_RE.finditer(text))
    if not matches:
        return text

    spans: list[tuple[int, int]] = []
    for index, match in enumerate(matches):
        title = match.group("title")
        level = len(match.group("marks"))
        if level == 1:
            continue
        if not section_matches_ignored_heading(title, patterns):
            continue
        end = len(text)
        for later in matches[index + 1 :]:
            if len(later.group("marks")) <= level:
                end = later.start()
                break
        spans.append((match.start(), end))

    if not spans:
        return text

    kept: list[str] = []
    cursor = 0
    for start, end in spans:
        kept.append(text[cursor:start])
        cursor = end
    kept.append(text[cursor:])
    return "".join(kept)


def configured_generated_name_patterns(config: dict[str, Any]) -> list[tuple[str, re.Pattern[str]]]:
    advanced_config = config.get("advanced_scan", {})
    configured = advanced_config.get(
        "generated_name_patterns",
        DEFAULT_ADVANCED_GENERATED_NAME_PATTERNS,
    )
    if not isinstance(configured, list):
        raise SystemExit("advanced_scan.generated_name_patterns must be a JSON array")

    patterns: list[tuple[str, re.Pattern[str]]] = []
    for index, entry in enumerate(configured):
        if isinstance(entry, dict):
            name = str(entry.get("name", f"pattern_{index}")).strip() or f"pattern_{index}"
            pattern = str(entry.get("pattern", "")).strip()
        else:
            name = f"pattern_{index}"
            pattern = str(entry).strip()
        if not pattern:
            continue
        try:
            patterns.append((name, re.compile(pattern)))
        except re.error as exc:
            raise SystemExit(
                f"advanced_scan.generated_name_patterns[{index}] is invalid: {exc}"
            ) from exc
    return patterns


def advanced_scan_run_by_default(config: dict[str, Any]) -> bool:
    advanced_config = config.get("advanced_scan", {})
    if not isinstance(advanced_config, dict):
        raise SystemExit("advanced_scan must be a JSON object")
    value = advanced_config.get("run_by_default", False)
    if isinstance(value, bool):
        return value
    if isinstance(value, int):
        return value != 0
    if isinstance(value, str):
        normalized = value.strip().casefold()
        if normalized in {"true", "yes", "on", "1", "enabled"}:
            return True
        if normalized in {"false", "no", "off", "0", "disabled", ""}:
            return False
    raise SystemExit("advanced_scan.run_by_default must be boolean-like")


def generated_name_hits(label: str, config: dict[str, Any]) -> list[str]:
    hits: list[str] = []
    for name, pattern in configured_generated_name_patterns(config):
        for match in pattern.finditer(label):
            hits.append(f"{match.group(0)} ({name})")
    return hits


def run_advanced_scan(records: list[RangeRecord], config: dict[str, Any]) -> list[str]:
    advanced_config = config.get("advanced_scan", {})
    patterns = advanced_config.get("ignore_section_heading_patterns", [])
    if not isinstance(patterns, list):
        patterns = []
    pattern_strings = [str(pattern) for pattern in patterns]
    errors: list[str] = []

    for record in records:
        if record.source_kind != "file" or record.path is None:
            continue
        text = read_text(record.path)
        scan_text = remove_ignored_sections(text, pattern_strings)
        lower_text = scan_text.casefold()
        normalized_text = normalize_alnum(scan_text)

        missing: list[str] = []
        if format_hex(record.start) not in lower_text:
            missing.append(format_hex(record.start))
        if format_hex(record.end) not in lower_text:
            missing.append(format_hex(record.end))

        normalized_label = normalize_alnum(record.label)
        if normalized_label and normalized_label not in normalized_text:
            missing.append(record.label)

        if missing:
            errors.append(f"{record.file_name}: missing document text for {', '.join(missing)}")

        if record.classification == "reconstructable":
            hits = generated_name_hits(record.label, config)
            if hits:
                errors.append(
                    f"{record.file_name}: reconstructable filename MAY still contain "
                    f"generated/decompiler names: {', '.join(hits)}"
                )

    return errors


def build_report(
    config: dict[str, Any],
    records: list[RangeRecord],
    filename_errors: list[str],
    general_errors: list[str],
    stats: dict[str, int],
    advanced_scan: bool,
) -> str:
    binary_start, binary_end = parse_config_range(config)
    total_bytes = binary_end - binary_start
    segments = compute_leaf_segments(records, binary_start, binary_end)
    totals = accumulate_segment_bytes(segments)
    covered = total_bytes - totals.get("uncovered", 0)
    largest_limit = int(config.get("largest_ranges_limit", 25))

    for record in records:
        if record.end <= binary_start or record.start >= binary_end:
            general_errors.append(
                f"{record.source_name}: range {format_range(record.start, record.end)} "
                f"is outside binary range {format_range(binary_start, binary_end)}"
            )
        elif record.start < binary_start or record.end > binary_end:
            general_errors.append(
                f"{record.source_name}: range {format_range(record.start, record.end)} "
                f"partly exceeds binary range {format_range(binary_start, binary_end)}"
            )

    advanced_errors = run_advanced_scan(records, config) if advanced_scan else []
    all_crossings = find_barrier_crossings(records)
    ignored_crossings = parse_ignored_crossings(config, all_crossings)
    ignored_crossing_keys = {
        crossing_key(ignored.parent, ignored.child) for ignored in ignored_crossings
    }
    crossings = [
        (parent, child)
        for parent, child in all_crossings
        if crossing_key(parent, child) not in ignored_crossing_keys
    ]
    largest_segments = sorted(
        [segment for segment in segments if segment.classification != "uncovered"],
        key=lambda segment: (segment.size, segment.start),
        reverse=True,
    )[:largest_limit]

    end_semantics = parse_end_semantics(config)
    lines: list[str] = []
    lines.append("# by-memory Tool Report")
    lines.append("")
    lines.append(f"- Last generated: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}")
    lines.append(f"- Configured binary range: `{format_range(binary_start, binary_end)}` ({end_semantics} end)")
    lines.append(f"- Configured binary bytes: {total_bytes}")
    lines.append(f"- Valid 0x range files scanned: {sum(1 for r in records if r.source_kind == 'file')}")
    lines.append(f"- Manual ranges loaded: {sum(1 for r in records if r.source_kind == 'manual')}")
    lines.append(f"- Ignored support files starting with `-`: {stats.get('ignored_support_files', 0)}")
    lines.append(f"- Ignored non-Markdown files: {stats.get('ignored_non_md_files', 0)}")
    lines.append(f"- Ignored non-range Markdown files: {stats.get('ignored_non_range_md_files', 0)}")
    lines.append("")

    lines.append("## Range-Statistics")
    lines.append("")
    lines.append(
        "These percentages are calculated by splitting the configured binary range at every "
        "parsed file/manual range boundary, then marking intervals with no covering range as "
        "`UNCOVERED`. This checks whether the filename/manual range map covers the configured "
        "address space, but it does not read binary bytes, query IDA/MCP, or prove byte-level "
        "documentation quality. Broad section-container pages count as coverage here, so treat "
        "the result as a cautious map-coverage estimate."
    )
    append_quick_reference(
        lines,
        [
            "python memory_ranges.py report",
            "python memory_ranges.py set-binary-range 0xSTART 0xEND",
            "python memory_ranges.py mark-not-reconstructable-file <file.md> <type>",
            "python memory_ranges.py mark-not-reconstructable-range 0xSTART 0xEND <type> --file <file.md> --label <label>",
            "python memory_ranges.py mark-padding-range 0xSTART 0xEND --label <label>",
            "python memory_ranges.py mark-other-range 0xSTART 0xEND --label <label>",
        ],
    )
    lines.append(
        "Built-in Not-Reconstructable types: "
        + ", ".join(f"`{type_name}`" for type_name in configured_not_reconstructable_types(config))
    )
    lines.append("")
    not_reconstructable = totals.get("not_reconstructable", 0)
    lines.append(
        f"- Not-Reconstructable-Coverage Total: {percent(not_reconstructable, total_bytes)} "
        f"({not_reconstructable} bytes)"
    )
    for subtype, value in sorted(
        accumulate_subtype_bytes(segments, "not_reconstructable").items(),
        key=lambda item: (-item[1], item[0].casefold()),
    ):
        lines.append(
            f"  - {subtype}: {percent(value, not_reconstructable)} "
            f"of Not-Reconstructable ({value} bytes)"
        )
    reconstructable = totals.get("reconstructable", 0)
    lines.append(
        f"- Reconstructable-Coverage Total: {percent(reconstructable, total_bytes)} "
        f"({reconstructable} bytes)"
    )
    reconstructable_emission = accumulate_reconstructable_emission_bytes(segments)
    no_owner = reconstructable_emission["no_owner"]
    emits = reconstructable_emission["emits"]
    non_emits = reconstructable_emission["non_emits"]
    multiple_emitters = reconstructable_emission["multiple_emitters"]
    emits_code = reconstructable_emission["emits_code"]
    does_not_emit_code = reconstructable_emission["does_not_emit_code"]
    emits_header_code = reconstructable_emission["emits_header_code"]
    does_not_emit_header_code = reconstructable_emission["does_not_emit_header_code"]
    lines.append(
        f"  - no-owner: {percent(no_owner, reconstructable)} "
        f"of Reconstructable ({no_owner} bytes)"
    )
    lines.append(
        f"  - emits: {percent(emits, reconstructable)} "
        f"of Reconstructable ({emits} bytes)"
    )
    lines.append(
        f"  - non-emits: {percent(non_emits, reconstructable)} "
        f"of Reconstructable ({non_emits} bytes)"
    )
    lines.append(
        f"  - multiple-emitters: {percent(multiple_emitters, reconstructable)} "
        f"of Reconstructable ({multiple_emitters} bytes)"
    )
    lines.append(
        f"    - has reconstruction code: {percent(emits_code, emits)} "
        f"of emits ({emits_code} bytes)"
    )
    lines.append(
        f"    - no reconstruction code yet: {percent(does_not_emit_code, emits)} "
        f"of emits ({does_not_emit_code} bytes)"
    )
    lines.append(
        f"    - has reconstruction header code: {percent(emits_header_code, emits)} "
        f"of emits ({emits_header_code} bytes)"
    )
    lines.append(
        f"    - no reconstruction header code yet: {percent(does_not_emit_header_code, emits)} "
        f"of emits ({does_not_emit_header_code} bytes)"
    )
    padding = totals.get("padding_zero_filled", 0)
    lines.append(
        f"- Padding-And-Zero-Filled(Manual Command): {percent(padding, total_bytes)} "
        f"({padding} bytes)"
    )
    other = totals.get("other", 0)
    lines.append(f"- Other: {percent(other, total_bytes)} ({other} bytes)")
    uncovered = totals.get("uncovered", 0)
    lines.append(f"- UNCOVERED(CALCULATED REMAINDER): {percent(uncovered, total_bytes)} ({uncovered} bytes)")
    lines.append(f"- Total Coverage: {percent(covered, total_bytes)} ({covered} bytes)")
    lines.append("")

    lines.append("## Manual-Ranges")
    lines.append("")
    lines.append(
        "These entries come from manual settings in `memory_ranges.data`. They should be "
        "treated as operator-provided hints unless the linked file/header evidence confirms them."
    )
    append_quick_reference(
        lines,
        [
            "python memory_ranges.py mark-not-reconstructable-file <file.md> <type>",
            "python memory_ranges.py mark-padding-file <file.md>",
            "python memory_ranges.py mark-other-file <file.md>",
            "python memory_ranges.py remove-file <file.md>",
            "python memory_ranges.py mark-not-reconstructable-range 0xSTART 0xEND <type> --file <file.md> --label <label>",
            "python memory_ranges.py mark-padding-range 0xSTART 0xEND --label <label>",
            "python memory_ranges.py mark-other-range 0xSTART 0xEND --label <label>",
            "python memory_ranges.py remove-range 0xSTART 0xEND",
        ],
    )
    file_classifications = config.get("file_classifications", {})
    if file_classifications:
        lines.append("### File Classifications")
        lines.append("")
        for key, entry in sorted(file_classifications.items(), key=lambda item: item[0].casefold()):
            classification = normalize_classification(str(entry.get("classification", "other")))
            subtype = str(entry.get("type", "")).strip()
            reason = str(entry.get("reason", "")).strip()
            detail = f"- `{key}`: {CLASSIFICATION_LABELS.get(classification, classification)}"
            if subtype:
                detail += f" / {subtype}"
            if reason:
                detail += f" - {reason}"
            lines.append(detail)
        lines.append("")
    manual_records = [record for record in records if record.source_kind == "manual"]
    if manual_records:
        lines.append("### Manual Ranges")
        lines.append("")
        for record in sorted(manual_records, key=lambda r: (r.start, r.end, r.label.casefold())):
            detail = f"- {record_display(record)}"
            if record.reason:
                detail += f" - {record.reason}"
            lines.append(detail)
    if not file_classifications and not manual_records:
        lines.append("- No manual ranges or file classifications are configured.")
    lines.append("")

    lines.append("## Barrier Crossings Errors")
    lines.append("")
    lines.append(
        "These are possible boundary conflicts where two ranges overlap without clean containment. "
        "Some may be intentional mixed-owner aggregates, so review the paired pages before treating "
        "them as definite errors. Use `mark-as-ignored` only after review to move one justified "
        "current crossing into `Ignored-Crossings` with a 50+ character reason."
    )
    append_quick_reference(
        lines,
        [
            "python memory_ranges.py report",
            "python memory_ranges.py mark-as-ignored 0xPARENT_START-0xPARENT_END 0xCROSSING_START-0xCROSSING_END <50+ char reason>",
            "python memory_ranges.py mark-not-reconstructable-range 0xSTART 0xEND <type> --file <file.md> --label <label>",
            "python memory_ranges.py mark-padding-range 0xSTART 0xEND --label <label>",
            "python memory_ranges.py mark-other-range 0xSTART 0xEND --label <label>",
            "python memory_ranges.py remove-range 0xSTART 0xEND",
        ],
    )
    if crossings:
        for parent, child in crossings:
            lines.append(f"- Parent/barrier: {record_display(parent)}")
            lines.append(f"  - Crossing range: {record_display(child)}")
    else:
        lines.append("- None.")
    lines.append("")

    lines.append("## Ignored-Crossings")
    lines.append("")
    lines.append(
        "These are current barrier crossings that were intentionally suppressed with "
        "`mark-as-ignored`. The ignore is tied only to the exact numeric parent and crossing "
        "ranges. If either filename range changes, the ignore stops matching and the crossing "
        "returns to the error list. The command records the reviewed crossing here and requires "
        "a reason of at least 50 characters."
    )
    append_quick_reference(
        lines,
        [
            "python memory_ranges.py mark-as-ignored 0xPARENT_START-0xPARENT_END 0xCROSSING_START-0xCROSSING_END <50+ char reason>",
        ],
    )
    if ignored_crossings:
        for ignored in ignored_crossings:
            lines.append(f"- Parent/barrier: {record_display(ignored.parent)}")
            lines.append(f"  - Crossing range: {record_display(ignored.child)}")
            if ignored.reason:
                lines.append(f"  - Reason: {ignored.reason}")
            else:
                lines.append("  - Reason: (none provided)")
    else:
        lines.append("- None.")
    lines.append("")

    lines.append("## General-Errors")
    lines.append("")
    lines.append(
        "These are rule-based validation findings from this tool. They usually indicate something "
        "worth checking, but the report cannot prove the project intent without the source page evidence."
    )
    append_quick_reference(
        lines,
        [
            "python memory_ranges.py report",
            "python memory_ranges.py mark-not-reconstructable-file <file.md> <type>",
            "python memory_ranges.py mark-not-reconstructable-range 0xSTART 0xEND <type> --file <file.md>",
        ],
    )
    if general_errors:
        for error in sorted(set(general_errors)):
            lines.append(f"- {error}")
    else:
        lines.append("- None.")
    lines.append("")

    lines.append("## Filename-Errors")
    lines.append("")
    lines.append(
        "These are likely filename-format problems for files that looked like range files. "
        "They are based only on the naming pattern, so confirm the file purpose before renaming."
    )
    append_quick_reference(
        lines,
        [
            "python memory_ranges.py report",
        ],
    )
    if filename_errors:
        for error in filename_errors:
            lines.append(f"- {error}")
    else:
        lines.append("- None.")
    lines.append("")

    lines.append("## Largest-Ranges")
    lines.append("")
    lines.append(
        "These are the largest leaf spans after splitting overlapping ranges at known boundaries. "
        "They may point to overly broad pages, but large third-party/runtime/data regions can be legitimate."
    )
    append_quick_reference(
        lines,
        [
            "python memory_ranges.py report",
            "Edit memory_ranges.data: largest_ranges_limit",
        ],
    )
    lines.append(
        f"- Showing {len(largest_segments)} largest leaf ranges "
        f"(configured limit: {largest_limit})."
    )
    for index, segment in enumerate(largest_segments, 1):
        record = segment.record
        if record is None:
            continue
        lines.append(
            f"{index}. `{format_range(segment.start, segment.end)}` "
            f"({segment.size} bytes) from {record_display(record)}"
        )
    if not largest_segments:
        lines.append("- None.")
    lines.append("")

    lines.append("## Advanced-Error-Scan")
    lines.append("")
    lines.append(
        "These items MAY have issues such as filenames that no longer match the file contents. "
        "This scan reads Markdown text only: it checks whether the filename start/end addresses "
        "and label text appear in the document body after configured update/change sections are "
        "ignored. It also flags reconstructable filenames that appear to contain generated/decompiler "
        "symbols such as `sub_`, `func_`, `dword_`, `DAT_`, or `field_`. The checks are heuristic, "
        "so each result is only a review candidate rather than a definitive failure."
    )
    lines.append("")
    lines.append(
        f"- Configured default state: {'enabled' if advanced_scan_run_by_default(config) else 'disabled'} "
        "(`advanced_scan.run_by_default`)."
    )
    lines.append(f"- Current report run: {'advanced scan executed' if advanced_scan else 'advanced scan not run'}.")
    append_quick_reference(
        lines,
        [
            "python memory_ranges.py report -advanced-scan",
            "python memory_ranges.py -advanced-scan",
            "python memory_ranges.py toggle-advanced-scan-default",
            "Edit memory_ranges.data: advanced_scan.ignore_section_heading_patterns",
            "Edit memory_ranges.data: advanced_scan.generated_name_patterns",
        ],
    )
    if not advanced_scan:
        lines.append("- Not run. Use `python memory_ranges.py -advanced-scan` or `python memory_ranges.py report -advanced-scan`.")
    elif advanced_errors:
        for error in advanced_errors:
            lines.append(f"- {error}")
    else:
        lines.append("- None.")
    lines.append("")

    return "\n".join(lines)


def write_report(text: str, path: Path) -> None:
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
            handle.write(text)
            if not text.endswith("\n"):
                handle.write("\n")
        temp_path.replace(path)
    except Exception:
        temp_path.unlink(missing_ok=True)
        raise


def register_dryrun_artifact(path: Path) -> None:
    data: dict[str, Any]
    if MIGRATION_DRYRUN_MANIFEST.exists():
        try:
            loaded = json.loads(MIGRATION_DRYRUN_MANIFEST.read_text(encoding="utf-8"))
            data = loaded if isinstance(loaded, dict) else {}
        except (OSError, json.JSONDecodeError):
            data = {}
    else:
        data = {}
    data.setdefault("tool", "memory_ranges.py")
    data.setdefault("mode", "dry-run artifacts")
    data.setdefault("root", str(DOC_ROOT))
    artifacts = data.setdefault("artifacts", [])
    if not isinstance(artifacts, list):
        artifacts = []
        data["artifacts"] = artifacts
    artifact = str(path)
    if artifact not in artifacts:
        artifacts.append(artifact)
    write_json_atomic(data, MIGRATION_DRYRUN_MANIFEST)


def append_quick_reference(lines: list[str], commands: list[str]) -> None:
    lines.append("")
    lines.append("Quick reference:")
    for command in commands:
        lines.append(f"- `{command}`")
    lines.append("")


def run_report(args: argparse.Namespace, config: dict[str, Any]) -> int:
    by_memory_path = resolve_config_path(str(config.get("by_memory_path", "")), DEFAULT_BY_MEMORY_PATH)
    report_path = resolve_config_path(str(config.get("report_path", "")), DEFAULT_REPORT_PATH)
    if getattr(args, "use_existing_dryrun", False) and not getattr(args, "dry_run", False):
        raise SystemExit("--use-existing-dryrun requires --dry-run")
    if getattr(args, "dry_run", False):
        report_path = dryrun_artifact_path(report_path)
    use_existing_dryrun = bool(getattr(args, "use_existing_dryrun", False))
    file_records, filename_errors, general_errors, stats = scan_by_memory_files(
        by_memory_path,
        config,
        use_existing_dryrun=use_existing_dryrun,
    )
    manual_records, manual_errors = parse_manual_ranges(
        config,
        by_memory_path,
        use_existing_dryrun=use_existing_dryrun,
    )
    general_errors.extend(manual_errors)
    all_records = file_records + manual_records
    advanced_scan = (
        advanced_scan_run_by_default(config)
        or bool(getattr(args, "advanced_scan", False))
        or bool(getattr(args, "report_advanced_scan", False))
    )
    report = build_report(
        config,
        all_records,
        filename_errors,
        general_errors,
        stats,
        advanced_scan,
    )
    write_report(report, report_path)
    if getattr(args, "dry_run", False):
        register_dryrun_artifact(report_path)
    print(f"wrote {report_path}")
    return 0


def run_set_binary_range(args: argparse.Namespace, config: dict[str, Any], data_path: Path) -> int:
    start = parse_hex(args.start, "start")
    end = parse_hex(args.end, "end")
    semantics = args.end_semantics
    internal_end = end + 1 if semantics == "inclusive" else end
    if start >= internal_end:
        raise SystemExit("start must be below end")
    config["binary_range"] = {
        "start": format_hex(start),
        "end": format_hex(end),
        "end_semantics": semantics,
    }
    write_json_atomic(config, data_path)
    print(f"updated binary range in {data_path}")
    return 0


def run_toggle_advanced_scan_default(
    _args: argparse.Namespace,
    config: dict[str, Any],
    data_path: Path,
) -> int:
    advanced_config = config.setdefault("advanced_scan", {})
    if not isinstance(advanced_config, dict):
        raise SystemExit("advanced_scan must be a JSON object")
    new_value = not advanced_scan_run_by_default(config)
    advanced_config["run_by_default"] = new_value
    write_json_atomic(config, data_path)
    print(f"advanced_scan.run_by_default is now {'enabled' if new_value else 'disabled'} in {data_path}")
    return 0


def require_file_header_for_classification(
    by_memory_path: Path,
    file_name: str,
    classification: str,
) -> None:
    path = by_memory_path / file_name
    if not path.exists():
        raise SystemExit(f"file not found: {path}")
    header_status = parse_reconstructable_status(read_text(path))
    error = validate_classification_against_header(classification, header_status, file_name)
    if error:
        raise SystemExit(error)


def write_file_classification(
    config: dict[str, Any],
    file_name: str,
    classification: str,
    reason: str = "",
    subtype: str = "",
) -> None:
    if subtype and classification == "not_reconstructable":
        subtype = normalize_not_reconstructable_type(subtype, config)
    error = validate_subtype_for_classification(classification, subtype, file_name)
    if error:
        raise SystemExit(error)

    overrides = config.setdefault("file_classifications", {})
    if not isinstance(overrides, dict):
        raise SystemExit("file_classifications must be a JSON object")
    entry = {
        "classification": classification,
        "reason": reason,
    }
    if classification == "not_reconstructable" and subtype:
        entry["type"] = subtype
    overrides[file_name] = entry


def find_manual_range_conflict(
    manual_ranges: list[Any],
    start: int,
    end: int,
    label: str,
    config: dict[str, Any],
) -> str | None:
    internal_end = end_to_internal(end, config)
    start_key = format_hex(start).casefold()
    end_key = format_hex(end).casefold()
    label_key = label.casefold()

    for index, entry in enumerate(manual_ranges):
        if not isinstance(entry, dict):
            raise SystemExit(f"manual_ranges[{index}]: entry must be an object")
        try:
            existing_start, existing_end, existing_internal_end = parse_manual_entry_bounds(
                entry,
                index,
                config,
            )
        except SystemExit as exc:
            raise SystemExit(f"manual_ranges[{index}] cannot be overlap-checked: {exc}") from exc

        same_entry = (
            str(entry.get("start", "")).casefold() == start_key
            and str(entry.get("end", "")).casefold() == end_key
            and str(entry.get("label", "")).casefold() == label_key
        )
        if same_entry:
            continue
        if range_overlaps(start, internal_end, existing_start, existing_internal_end):
            existing_label = str(entry.get("label", "")).strip() or f"manual_ranges[{index}]"
            return (
                f"manual range {format_range(start, end)} {label!r} overlaps "
                f"manual_ranges[{index}] {format_range(existing_start, existing_end)} "
                f"{existing_label!r}"
            )
    return None


def require_manual_range_inside_file_range(
    file_name: str,
    start: int,
    end: int,
    config: dict[str, Any],
) -> None:
    file_start, file_end = parse_range_from_file_name(file_name)
    internal_end = end_to_internal(end, config)
    if start < file_start or internal_end > file_end:
        raise SystemExit(
            f"manual range {format_range(start, end)} is not contained by linked file "
            f"{file_name} range {format_range(file_start, file_end)}"
        )


def write_manual_range_classification(
    config: dict[str, Any],
    start: int,
    end: int,
    classification: str,
    label: str,
    reason: str = "",
    file_name: str = "",
    subtype: str = "",
) -> None:
    if subtype and classification == "not_reconstructable":
        subtype = normalize_not_reconstructable_type(subtype, config)
    error = validate_subtype_for_classification(classification, subtype, label)
    if error:
        raise SystemExit(error)

    manual_ranges = config.setdefault("manual_ranges", [])
    if not isinstance(manual_ranges, list):
        raise SystemExit("manual_ranges must be a JSON array")

    conflict = find_manual_range_conflict(manual_ranges, start, end, label, config)
    if conflict:
        raise SystemExit(conflict)

    replacement = {
        "classification": classification,
        "end": format_hex(end),
        "file": file_name,
        "label": label,
        "reason": reason,
        "start": format_hex(start),
    }
    if classification == "not_reconstructable" and subtype:
        replacement["type"] = subtype

    manual_ranges[:] = [
        entry
        for entry in manual_ranges
        if not (
            isinstance(entry, dict)
            and str(entry.get("start", "")).casefold() == format_hex(start).casefold()
            and str(entry.get("end", "")).casefold() == format_hex(end).casefold()
            and str(entry.get("label", "")).casefold() == label.casefold()
        )
    ]
    manual_ranges.append(replacement)


def run_mark_not_reconstructable_file(
    args: argparse.Namespace,
    config: dict[str, Any],
    data_path: Path,
) -> int:
    by_memory_path = resolve_config_path(str(config.get("by_memory_path", "")), DEFAULT_BY_MEMORY_PATH)
    file_name = file_key_from_argument(args.file, by_memory_path)
    classification = "not_reconstructable"
    require_file_header_for_classification(by_memory_path, file_name, classification)
    subtype = normalize_not_reconstructable_type(args.type, config)
    write_file_classification(config, file_name, classification, args.reason or "", subtype)
    write_json_atomic(config, data_path)
    print(f"marked {file_name} as not_reconstructable / {subtype} in {data_path}")
    return 0


def run_mark_padding_file(args: argparse.Namespace, config: dict[str, Any], data_path: Path) -> int:
    by_memory_path = resolve_config_path(str(config.get("by_memory_path", "")), DEFAULT_BY_MEMORY_PATH)
    file_name = file_key_from_argument(args.file, by_memory_path)
    target = by_memory_path / file_name
    if not target.exists():
        raise SystemExit(f"file not found: {target}")
    write_file_classification(config, file_name, "padding_zero_filled", args.reason or "")
    write_json_atomic(config, data_path)
    print(f"marked {file_name} as padding_zero_filled in {data_path}")
    return 0


def run_mark_other_file(args: argparse.Namespace, config: dict[str, Any], data_path: Path) -> int:
    by_memory_path = resolve_config_path(str(config.get("by_memory_path", "")), DEFAULT_BY_MEMORY_PATH)
    file_name = file_key_from_argument(args.file, by_memory_path)
    target = by_memory_path / file_name
    if not target.exists():
        raise SystemExit(f"file not found: {target}")
    write_file_classification(config, file_name, "other", args.reason or "")
    write_json_atomic(config, data_path)
    print(f"marked {file_name} as other in {data_path}")
    return 0


def parse_range_args(args: argparse.Namespace, config: dict[str, Any]) -> tuple[int, int]:
    start = parse_hex(args.start, "start")
    end = parse_hex(args.end, "end")
    internal_end = end_to_internal(end, config)
    if start >= internal_end:
        raise SystemExit("start must be below end")
    return start, end


def run_mark_not_reconstructable_range(
    args: argparse.Namespace,
    config: dict[str, Any],
    data_path: Path,
) -> int:
    by_memory_path = resolve_config_path(str(config.get("by_memory_path", "")), DEFAULT_BY_MEMORY_PATH)
    start, end = parse_range_args(args, config)
    file_name = file_key_from_argument(args.file, by_memory_path)
    classification = "not_reconstructable"
    require_file_header_for_classification(by_memory_path, file_name, classification)
    require_manual_range_inside_file_range(file_name, start, end, config)
    subtype = normalize_not_reconstructable_type(args.type, config)
    label = args.label or f"{format_range(start, end)} {subtype}"
    write_manual_range_classification(
        config,
        start,
        end,
        classification,
        label,
        args.reason or "",
        file_name,
        subtype,
    )
    write_json_atomic(config, data_path)
    print(f"marked manual range {format_range(start, end)} as not_reconstructable / {subtype} in {data_path}")
    return 0


def run_mark_padding_range(args: argparse.Namespace, config: dict[str, Any], data_path: Path) -> int:
    start, end = parse_range_args(args, config)
    label = args.label or f"{format_range(start, end)} padding_zero_filled"
    write_manual_range_classification(
        config,
        start,
        end,
        "padding_zero_filled",
        label,
        args.reason or "",
    )
    write_json_atomic(config, data_path)
    print(f"marked manual range {format_range(start, end)} as padding_zero_filled in {data_path}")
    return 0


def run_mark_other_range(args: argparse.Namespace, config: dict[str, Any], data_path: Path) -> int:
    start, end = parse_range_args(args, config)
    label = args.label or f"{format_range(start, end)} other"
    write_manual_range_classification(
        config,
        start,
        end,
        "other",
        label,
        args.reason or "",
    )
    write_json_atomic(config, data_path)
    print(f"marked manual range {format_range(start, end)} as other in {data_path}")
    return 0


def run_remove_file(args: argparse.Namespace, config: dict[str, Any], data_path: Path) -> int:
    by_memory_path = resolve_config_path(str(config.get("by_memory_path", "")), DEFAULT_BY_MEMORY_PATH)
    file_name = file_key_from_argument(args.file, by_memory_path)
    overrides = config.setdefault("file_classifications", {})
    if not isinstance(overrides, dict):
        raise SystemExit("file_classifications must be a JSON object")
    removed = False
    for key in list(overrides):
        if Path(str(key)).name == file_name:
            del overrides[key]
            removed = True
    write_json_atomic(config, data_path)
    print(("removed" if removed else "no entry for") + f" {file_name} in {data_path}")
    return 0


def run_remove_range(args: argparse.Namespace, config: dict[str, Any], data_path: Path) -> int:
    start, end = parse_range_args(args, config)
    manual_ranges = config.setdefault("manual_ranges", [])
    if not isinstance(manual_ranges, list):
        raise SystemExit("manual_ranges must be a JSON array")
    before = len(manual_ranges)
    label = (args.label or "").casefold()
    manual_ranges[:] = [
        entry
        for entry in manual_ranges
        if not (
            isinstance(entry, dict)
            and str(entry.get("start", "")).casefold() == format_hex(start).casefold()
            and str(entry.get("end", "")).casefold() == format_hex(end).casefold()
            and (not label or str(entry.get("label", "")).casefold() == label)
        )
    ]
    write_json_atomic(config, data_path)
    print(f"removed {before - len(manual_ranges)} manual range entries from {data_path}")
    return 0


def run_mark_as_ignored(args: argparse.Namespace, config: dict[str, Any], data_path: Path) -> int:
    parent_start, parent_end = parse_range_token(args.parent_range, "parent/barrier range")
    child_start, child_end = parse_range_token(args.crossing_range, "crossing range")
    reason = " ".join(args.reason).strip()
    if not reason:
        raise SystemExit("mark-as-ignored requires a reason")
    if len(reason) < 50:
        raise SystemExit("mark-as-ignored reason must be at least 50 characters")

    by_memory_path = resolve_config_path(str(config.get("by_memory_path", "")), DEFAULT_BY_MEMORY_PATH)
    file_records, _filename_errors, _general_errors, _stats = scan_by_memory_files(
        by_memory_path,
        config,
    )
    manual_records, manual_errors = parse_manual_ranges(config, by_memory_path)
    if manual_errors:
        raise SystemExit(
            "cannot validate ignored crossing while manual range errors exist: "
            + "; ".join(manual_errors)
        )
    records = file_records + manual_records

    parent_matches = [
        record for record in records if record.start == parent_start and record.end == parent_end
    ]
    child_matches = [
        record for record in records if record.start == child_start and record.end == child_end
    ]
    if not parent_matches:
        raise SystemExit(f"parent/barrier range was not found: {format_range(parent_start, parent_end)}")
    if not child_matches:
        raise SystemExit(f"crossing range was not found: {format_range(child_start, child_end)}")
    if len(parent_matches) > 1:
        names = ", ".join(record.source_name for record in parent_matches)
        raise SystemExit(f"parent/barrier range is ambiguous: {names}")
    if len(child_matches) > 1:
        names = ", ".join(record.source_name for record in child_matches)
        raise SystemExit(f"crossing range is ambiguous: {names}")

    crossings = find_barrier_crossings(records)
    target_key = crossing_key_from_ranges(parent_start, parent_end, child_start, child_end)
    current_keys = {crossing_key(parent, child) for parent, child in crossings}
    if target_key not in current_keys:
        raise SystemExit(
            "the supplied ranges are not a current barrier crossing in parent/crossing order: "
            f"{format_range(parent_start, parent_end)} -> {format_range(child_start, child_end)}"
        )

    ignored_crossings = config.setdefault("ignored_crossings", [])
    if not isinstance(ignored_crossings, list):
        raise SystemExit("ignored_crossings must be a JSON array")

    parent_range = format_range(parent_start, parent_end)
    crossing_range = format_range(child_start, child_end)
    ignored_crossings[:] = [
        entry
        for entry in ignored_crossings
        if not (
            isinstance(entry, dict)
            and str(entry.get("parent_range", "")).casefold() == parent_range.casefold()
            and str(entry.get("crossing_range", "")).casefold() == crossing_range.casefold()
        )
    ]
    ignored_crossings.append(
        {
            "crossing_range": crossing_range,
            "parent_range": parent_range,
            "reason": reason,
        }
    )
    write_json_atomic(config, data_path)
    print(f"ignored barrier crossing {parent_range} -> {crossing_range} in {data_path}")
    return 0


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Generate coverage and overlap reports from by-memory range filenames."
    )

    def add_subcommand_data_option(subparser: argparse.ArgumentParser) -> None:
        subparser.add_argument(
            "--data",
            dest="sub_data",
            default=None,
            help="Path to memory_ranges.data JSON settings.",
        )

    parser.add_argument(
        "--data",
        default=str(DEFAULT_DATA_PATH),
        help="Path to memory_ranges.data JSON settings.",
    )
    parser.add_argument(
        "-advanced-scan",
        "--advanced-scan",
        action="store_true",
        help="Run the optional filename text consistency scan while generating the report.",
    )
    parser.add_argument(
        "--dry-run",
        action="store_true",
        help="Write report output to the .dryrun artifact path instead of the live report.",
    )
    parser.add_argument(
        "--use-existing-dryrun",
        action="store_true",
        help="Read by-memory *.md.dryrun files when present while generating a dry-run report.",
    )

    subparsers = parser.add_subparsers(dest="command")

    report = subparsers.add_parser("report", help="Generate the Markdown report.")
    add_subcommand_data_option(report)
    report.add_argument(
        "-advanced-scan",
        "--advanced-scan",
        dest="report_advanced_scan",
        action="store_true",
        help="Run the optional filename text consistency scan.",
    )
    report.add_argument(
        "--dry-run",
        action="store_true",
        help="Write report output to the .dryrun artifact path instead of the live report.",
    )
    report.add_argument(
        "--use-existing-dryrun",
        action="store_true",
        help="Read by-memory *.md.dryrun files when present while generating a dry-run report.",
    )

    set_binary = subparsers.add_parser("set-binary-range", help="Update binary range settings.")
    add_subcommand_data_option(set_binary)
    set_binary.add_argument("start")
    set_binary.add_argument("end")
    set_binary.add_argument(
        "--end-semantics",
        choices=["exclusive", "inclusive"],
        default="exclusive",
        help="How the supplied end address should be interpreted.",
    )

    toggle_advanced = subparsers.add_parser(
        "toggle-advanced-scan-default",
        help="Toggle whether report generation runs Advanced-Error-Scan by default.",
    )
    add_subcommand_data_option(toggle_advanced)

    list_types = subparsers.add_parser(
        "list-not-reconstructable-types",
        help="List built-in Not-Reconstructable type names.",
    )
    add_subcommand_data_option(list_types)

    mark_not_file = subparsers.add_parser(
        "mark-not-reconstructable-file",
        help="Mark a file as Not-Reconstructable with a built-in or custom type.",
    )
    add_subcommand_data_option(mark_not_file)
    mark_not_file.add_argument("file")
    mark_not_file.add_argument("type")
    mark_not_file.add_argument("--reason", default="")

    mark_padding_file = subparsers.add_parser(
        "mark-padding-file",
        help="Mark a file as Padding-And-Zero-Filled.",
    )
    add_subcommand_data_option(mark_padding_file)
    mark_padding_file.add_argument("file")
    mark_padding_file.add_argument("--reason", default="")

    mark_other_file = subparsers.add_parser(
        "mark-other-file",
        help="Mark a file as Other.",
    )
    add_subcommand_data_option(mark_other_file)
    mark_other_file.add_argument("file")
    mark_other_file.add_argument("--reason", default="")

    remove_file = subparsers.add_parser("remove-file", help="Remove a file classification override.")
    add_subcommand_data_option(remove_file)
    remove_file.add_argument("file")

    mark_not_range = subparsers.add_parser(
        "mark-not-reconstructable-range",
        help="Mark a manual range as Not-Reconstructable with a built-in or custom type.",
    )
    add_subcommand_data_option(mark_not_range)
    mark_not_range.add_argument("start")
    mark_not_range.add_argument("end")
    mark_not_range.add_argument("type")
    mark_not_range.add_argument("--file", required=True, help="Required by-memory file to validate against.")
    mark_not_range.add_argument("--label", default="")
    mark_not_range.add_argument("--reason", default="")

    mark_padding_range = subparsers.add_parser(
        "mark-padding-range",
        help="Mark a manual range as Padding-And-Zero-Filled.",
    )
    add_subcommand_data_option(mark_padding_range)
    mark_padding_range.add_argument("start")
    mark_padding_range.add_argument("end")
    mark_padding_range.add_argument("--label", default="")
    mark_padding_range.add_argument("--reason", default="")

    mark_other_range = subparsers.add_parser(
        "mark-other-range",
        help="Mark a manual range as Other.",
    )
    add_subcommand_data_option(mark_other_range)
    mark_other_range.add_argument("start")
    mark_other_range.add_argument("end")
    mark_other_range.add_argument("--label", default="")
    mark_other_range.add_argument("--reason", default="")

    remove_range = subparsers.add_parser("remove-range", help="Remove manual range classifications.")
    add_subcommand_data_option(remove_range)
    remove_range.add_argument("start")
    remove_range.add_argument("end")
    remove_range.add_argument("--label", default="")

    mark_as_ignored = subparsers.add_parser(
        "mark-as-ignored",
        help="Ignore a currently reported barrier crossing by exact parent/crossing ranges.",
    )
    add_subcommand_data_option(mark_as_ignored)
    mark_as_ignored.add_argument("parent_range")
    mark_as_ignored.add_argument("crossing_range")
    mark_as_ignored.add_argument("reason", nargs=argparse.REMAINDER)

    return parser


def main(argv: list[str] | None = None) -> int:
    parser = build_parser()
    args = parser.parse_args(argv)
    data_arg = getattr(args, "sub_data", None) or args.data
    data_path = Path(data_arg)
    if not data_path.is_absolute():
        data_path = (Path.cwd() / data_path).resolve()
    config = read_json(data_path)

    command = args.command or "report"
    if command == "report":
        return run_report(args, config)
    if command == "set-binary-range":
        return run_set_binary_range(args, config, data_path)
    if command == "toggle-advanced-scan-default":
        return run_toggle_advanced_scan_default(args, config, data_path)
    if command == "list-not-reconstructable-types":
        for type_name in configured_not_reconstructable_types(config):
            print(type_name)
        return 0
    if command == "mark-not-reconstructable-file":
        return run_mark_not_reconstructable_file(args, config, data_path)
    if command == "mark-padding-file":
        return run_mark_padding_file(args, config, data_path)
    if command == "mark-other-file":
        return run_mark_other_file(args, config, data_path)
    if command == "remove-file":
        return run_remove_file(args, config, data_path)
    if command == "mark-not-reconstructable-range":
        return run_mark_not_reconstructable_range(args, config, data_path)
    if command == "mark-padding-range":
        return run_mark_padding_range(args, config, data_path)
    if command == "mark-other-range":
        return run_mark_other_range(args, config, data_path)
    if command == "remove-range":
        return run_remove_range(args, config, data_path)
    if command == "mark-as-ignored":
        return run_mark_as_ignored(args, config, data_path)
    parser.error(f"unknown command {command!r}")
    return 2


if __name__ == "__main__":
    raise SystemExit(main())
