#!/usr/bin/env python3
"""Validate stable documentation UIDs, score headers, and UID references.

Default behavior is a dry run. Pass --apply to write Markdown headers and
validator.ini updates.
"""

from __future__ import annotations

import argparse
import configparser
import contextlib
import hashlib
import io
import json
import os
import re
import shutil
import sys
import tempfile
import time
import traceback
from dataclasses import dataclass
from datetime import datetime
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
RECONSTRUCTION_CPP_LINE_RE = re.compile(
    r"^\*\*\* RECONSTRUCTION_CPP CODE:\[\[\[(?P<value>.*)\]\]\] "
    r"\| ONLY MODIFY VALUE - DO NOT REMOVE!!! \*\*\*$"
)
RECONSTRUCTABLE_PREFIX = "*** RECONSTRUCTABLE:"
AUTOGEN_PARENT_UID_PREFIX = "*** AUTOGEN_PARENT_UID:"
AUTOGEN_PARENT_POSITION_PREFIX = "*** AUTOGEN_PARENT_POSITION_OPTIONAL:"
RECONSTRUCTION_CPP_PREFIX = "*** RECONSTRUCTION_CPP CODE:"
RECONSTRUCTION_CPP_BEGIN_LINE = (
    "*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***"
)
RECONSTRUCTION_CPP_END_LINE = "*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***"
CHILDREN_MARKER = "[[CHILDREN]]"
MALFORMED_CHILDREN_MARKER = "[[]CHILDREN]"
NO_CHILDREN_MARKER = "[[No Children Attached]]"
AUTOGEN_SENTINEL = "// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND."
AUTOGEN_MARKDOWN_SENTINEL = "<!-- AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND. -->"
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
STATS_RELATIVE_PATH = Path("project-level") / "-auto-completion-stats.md"
TMP_REFERENCE_SECTION = "tmp_references"
PROJECTED_PATH_SECTION = "projected_paths"
PROJECTED_PATH_STATUS_SECTION = "projected_path_status"
PROJECTED_PATH_ERROR_SECTION = "projected_path_errors"
PROJECTED_PATH_NONE_VALUE = "NONE"
RECONSTRUCTABLE_SECTION = "reconstructable"
AUTOGEN_PARENT_SECTION = "autogen_parent"
AUTOGEN_PARENT_POSITION_SECTION = "autogen_parent_position"
RECONSTRUCTION_CODE_HASH_SECTION = "reconstruction_code_hash"
RECONSTRUCTION_CODE_MODE_SECTION = "reconstruction_code_mode"
AUTOGEN_CHILDREN_SECTION = "autogen_children"
AUTOGEN_ROOT_SECTION = "autogen_root"
AUTOGEN_STATUS_SECTION = "autogen_status"
AUTOGEN_ERROR_SECTION = "autogen_errors"
AUTO_GENERATED_RELATIVE_PATH = Path("auto-generated")
LOCK_POLL_SECONDS = 0.5
WORKER_POLL_SECONDS = 0.25
DEDUP_COALESCE_SECONDS = 0.5
DEDUP_CONFIG_SECTION = "queue"
DEDUP_CONFIG_KEY = "enable_dedup"
STRONG_DEDUP_CONFIG_KEY = "enable_strong_dedup"
DEDUP_NONE = "none"
DEDUP_READ_ONLY = "read_only"
DEDUP_GLOBAL_REFRESH = "global_refresh"
IGNORED_SCORE_FOLDERS = {
    "by-external-research",
    "by-meta",
    "by-project-structure",
}

_TEXT_CACHE: dict[Path, tuple[int, int, str]] = {}
_RESOLVE_CACHE: dict[Path, Path] = {}
_DEDUP_CONFIG_CACHE: tuple[int | None, bool, bool] = (None, False, False)


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


@dataclass
class AutogenMetadata:
    uid: str
    path: str
    folder: str
    eligible: bool
    reconstructable: str = "blank"
    parent_uid: str = ""
    parent_position: int | None = None
    parent_position_raw: str = ""
    code: str = ""
    code_mode: str = "blank"
    code_hash: str = ""
    errors: list[str] | None = None


@dataclass(frozen=True)
class AutogenReportEntry:
    uid: str
    path: str
    folder: str
    status: str
    parent_uid: str = ""
    position: str = ""
    has_code: bool = False
    destination: str = ""
    detail: str = ""


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


def parse_reconstruction_cpp_line(line: str) -> str | None:
    match = RECONSTRUCTION_CPP_LINE_RE.match(line)
    return match.group("value") if match else None


def code_hash(code: str) -> str:
    if code == "":
        return ""
    return hashlib.sha256(code.encode("utf-8")).hexdigest()


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
        RECONSTRUCTION_CODE_HASH_SECTION,
        RECONSTRUCTION_CODE_MODE_SECTION,
        AUTOGEN_CHILDREN_SECTION,
        AUTOGEN_ROOT_SECTION,
        AUTOGEN_STATUS_SECTION,
        AUTOGEN_ERROR_SECTION,
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
    with tempfile.NamedTemporaryFile(
        "w", encoding="utf-8", newline="\n", delete=False, dir=str(path.parent)
    ) as tmp:
        config.write(tmp)
        tmp_name = tmp.name
    os.replace(tmp_name, path)


def write_text_atomic(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.NamedTemporaryFile(
        "w", encoding="utf-8", newline="", delete=False, dir=str(path.parent)
    ) as tmp:
        tmp.write(text)
        tmp_name = tmp.name
    os.replace(tmp_name, path)
    remember_text_cache(path, text)


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
        RECONSTRUCTABLE_PREFIX,
        AUTOGEN_PARENT_UID_PREFIX,
        AUTOGEN_PARENT_POSITION_PREFIX,
        RECONSTRUCTION_CPP_PREFIX,
    )
    return any(line.startswith(prefixes) for line in lines[:20])


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


def generated_cpp_path(root: Path, projected_path: str, stem: str) -> Path:
    parts = [part for part in projected_path.strip("/").split("/") if part]
    target = root / AUTO_GENERATED_RELATIVE_PATH / Path(*parts) / f"{stem}.cpp"
    generated_root = resolved_path(root / AUTO_GENERATED_RELATIVE_PATH)
    resolved = resolved_path(target)
    try:
        resolved.relative_to(generated_root)
    except ValueError as exc:
        raise ValueError(f"generated path escapes auto-generated root: {target}") from exc
    return target


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
    new_target = generated_cpp_path(root, new_projected_path, doc_path.stem)
    old_target: Path | None = None

    if old_projected_path:
        old_normalized, old_status, _ = validate_projected_path(old_projected_path)
        if old_status == "valid":
            old_stem = Path(old_doc_rel.replace("\\", "/")).stem if old_doc_rel else doc_path.stem
            old_target = generated_cpp_path(root, old_normalized, old_stem)

    if old_target is not None and resolved_path(old_target) != resolved_path(new_target):
        if old_target.exists():
            if new_target.exists():
                actions.append(
                    ScanAction(
                        "projected_cpp_conflict",
                        uid,
                        new_target,
                        f"target exists; not moving {relative_path(root, old_target)}",
                    )
                )
                return actions
            actions.append(
                ScanAction(
                    "projected_cpp_move",
                    uid,
                    new_target,
                    f"from {relative_path(root, old_target)}",
                )
            )
            if apply:
                new_target.parent.mkdir(parents=True, exist_ok=True)
                old_parent = old_target.parent
                old_target.replace(new_target)
                for removed in remove_empty_generated_dirs(root, old_parent):
                    actions.append(ScanAction("projected_folder_remove", uid, removed, "empty generated folder"))
            return actions

    if new_target.exists():
        return actions

    actions.append(ScanAction("projected_cpp_create", uid, new_target, "empty reconstructed source placeholder"))
    if apply:
        new_target.parent.mkdir(parents=True, exist_ok=True)
        write_text_atomic(new_target, "")
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

    if status == "valid":
        actions.extend(sync_generated_cpp(root, uid, path, old_doc_rel, old_projected, normalized, apply))
    elif old_projected:
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

    if not is_autogen_metadata_doc(root, path):
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

    reconstructable_fallback = reconstructable_display_value(
        stored_autogen_value(config, RECONSTRUCTABLE_SECTION, uid)
    )
    parent_fallback = stored_autogen_value(config, AUTOGEN_PARENT_SECTION, uid)
    if not re.fullmatch(r"[A-Z0-9]{6}", parent_fallback):
        parent_fallback = ""
    position_fallback = stored_autogen_value(config, AUTOGEN_PARENT_POSITION_SECTION, uid)
    if not re.fullmatch(r"[0-9]+", position_fallback):
        position_fallback = ""

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

    if index < len(lines) and AUTOGEN_PARENT_UID_LINE_RE.match(lines[index]):
        index += 1
    elif index < len(lines) and lines[index].startswith(AUTOGEN_PARENT_UID_PREFIX):
        lines[index] = make_autogen_parent_uid_line(parent_fallback)
        changed = True
        actions.append(ScanAction("restore_autogen_metadata", uid, path, "AUTOGEN_PARENT_UID"))
        index += 1
    else:
        lines.insert(index, make_autogen_parent_uid_line(parent_fallback))
        changed = True
        actions.append(ScanAction("insert_autogen_metadata", uid, path, "AUTOGEN_PARENT_UID"))
        index += 1

    if index < len(lines) and AUTOGEN_PARENT_POSITION_LINE_RE.match(lines[index]):
        index += 1
    elif index < len(lines) and lines[index].startswith(AUTOGEN_PARENT_POSITION_PREFIX):
        lines[index] = make_autogen_parent_position_line(position_fallback)
        changed = True
        actions.append(
            ScanAction("restore_autogen_metadata", uid, path, "AUTOGEN_PARENT_POSITION_OPTIONAL")
        )
        index += 1
    else:
        lines.insert(index, make_autogen_parent_position_line(position_fallback))
        changed = True
        actions.append(
            ScanAction("insert_autogen_metadata", uid, path, "AUTOGEN_PARENT_POSITION_OPTIONAL")
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

    if index >= len(lines) or lines[index].strip() != "":
        lines.insert(index, "")
        changed = True
        actions.append(ScanAction("insert_header_blank", uid, path, "after metadata header"))

    if not changed:
        return text, completion, confidence, projected_path_value, actions

    new_text = newline.join(lines)
    if original_had_final_newline:
        new_text += newline
    return new_text, completion, confidence, projected_path_value, actions


def extract_reconstruction_code(lines: list[str]) -> tuple[str, str, list[str]]:
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
        return block_code, "block", errors
    if inline_value:
        return inline_value, "inline", errors
    if errors:
        return "", "invalid", errors
    return "", "blank", errors


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
        if has_autogen_metadata_line(lines):
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
    parent_uid = ""
    position_raw = ""
    position: int | None = None

    for line in lines[:20]:
        if line.startswith(RECONSTRUCTABLE_PREFIX):
            parsed_reconstructable = parse_reconstructable_line(line)
            if parsed_reconstructable is None:
                errors.append("autogen_value_invalid: malformed RECONSTRUCTABLE line")
            else:
                raw, reconstructable = parsed_reconstructable
                if reconstructable == "invalid":
                    errors.append(f"autogen_value_invalid: invalid RECONSTRUCTABLE value {raw!r}")
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

    code, mode, code_errors = extract_reconstruction_code(lines)
    errors.extend(code_errors)
    if MALFORMED_CHILDREN_MARKER in code:
        errors.append("autogen_children_marker_malformed: use [[CHILDREN]]")
    if code.count(CHILDREN_MARKER) > 1:
        errors.append("autogen_children_marker_multiple: only one [[CHILDREN]] marker is supported")

    return (
        AutogenMetadata(
            uid=uid,
            path=rel,
            folder=folder,
            eligible=True,
            reconstructable=reconstructable,
            parent_uid=parent_uid,
            parent_position=position,
            parent_position_raw=position_raw,
            code=code,
            code_mode=mode,
            code_hash=code_hash(code),
            errors=errors,
        ),
        actions,
    )


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
        RECONSTRUCTION_CODE_HASH_SECTION,
        RECONSTRUCTION_CODE_MODE_SECTION,
        AUTOGEN_ROOT_SECTION,
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
            AUTOGEN_PARENT_SECTION,
            uid,
            metadata.parent_uid,
            path,
            "autogen_registry_update",
            apply,
        )
    )
    actions.extend(
        set_config_value_action(
            config,
            AUTOGEN_PARENT_POSITION_SECTION,
            uid,
            metadata.parent_position_raw,
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

    error_key = autogen_error_key(uid)
    line_errors = metadata.errors or []
    if metadata.reconstructable == "true" and not metadata.parent_uid and metadata.code.strip():
        line_errors.append("autogen_code_without_parent: RECONSTRUCTION_CPP CODE requires AUTOGEN_PARENT_UID")
    if metadata.reconstructable in {"blank", "false"} and (metadata.parent_uid or metadata.code):
        line_errors.append("autogen_inactive_has_data: parent/code present while not reconstructable")

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
) -> list[ScanAction]:
    actions: list[ScanAction] = []
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
        return parse_autogen_metadata(root, path, read_text(path))
    except UnicodeDecodeError as exc:
        return None, [ScanAction("read_error", uid, path, str(exc))]


def autogen_metadata_index(
    root: Path,
    config: configparser.ConfigParser,
) -> tuple[dict[str, AutogenMetadata], list[ScanAction]]:
    metadata_by_uid: dict[str, AutogenMetadata] = {}
    actions: list[ScanAction] = []
    candidate_uids = set(config[RECONSTRUCTABLE_SECTION].keys())
    candidate_uids.update(
        uid for uid, stored_path in config["files"].items()
        if is_autogen_metadata_doc(root, absolute_path(root, stored_path))
    )

    for uid in sorted(candidate_uids, key=lambda item: config["files"].get(item, "")):
        metadata, parse_actions = autogen_parse_metadata_from_file(root, config, uid)
        actions.extend(parse_actions)
        if metadata is not None:
            metadata_by_uid[uid] = metadata
    return metadata_by_uid, actions


def sort_autogen_children(children: list[str], metadata_by_uid: dict[str, AutogenMetadata]) -> list[str]:
    def sort_key(uid: str) -> tuple[int, int, int, str]:
        metadata = metadata_by_uid.get(uid)
        position = metadata.parent_position if metadata and metadata.parent_position is not None else None
        has_no_position = 1 if position is None else 0
        position_value = 0 if position is None else position
        try:
            order = base36_to_int(uid)
        except ValueError:
            order = 0
        return (has_no_position, position_value, order, uid)

    return sorted(children, key=sort_key)


def build_autogen_children(metadata_by_uid: dict[str, AutogenMetadata]) -> dict[str, list[str]]:
    children: dict[str, list[str]] = {}
    for uid, metadata in metadata_by_uid.items():
        if metadata.reconstructable != "true" or not metadata.parent_uid:
            continue
        children.setdefault(metadata.parent_uid, []).append(uid)
    return {
        parent_uid: sort_autogen_children(child_uids, metadata_by_uid)
        for parent_uid, child_uids in children.items()
    }


def resolve_autogen_root(
    uid: str,
    root: Path,
    config: configparser.ConfigParser,
    metadata_by_uid: dict[str, AutogenMetadata],
) -> tuple[str | None, list[str]]:
    errors: list[str] = []
    metadata = metadata_by_uid.get(uid)
    if metadata is None:
        return None, ["autogen_registry_stale: missing metadata"]
    if metadata.reconstructable != "true":
        return None, []
    if not metadata.parent_uid:
        return None, ["autogen_parent_missing: missing AUTOGEN_PARENT_UID"]

    seen = {uid}
    parent_uid = metadata.parent_uid
    while True:
        if parent_uid in seen:
            errors.append("autogen_parent_cycle: parent chain repeats")
            return None, errors
        seen.add(parent_uid)
        parent_path = config["files"].get(parent_uid)
        if parent_path is None:
            errors.append("autogen_parent_unknown: parent UID is not in validator.ini")
            return None, errors
        if is_projected_path_candidate(parent_path):
            projected_path = config[PROJECTED_PATH_SECTION].get(parent_uid, "")
            _, status, error = validate_projected_path(projected_path)
            if status != "valid":
                detail = "non-standalone projected path" if status == "none" else error or "blank projected path"
                errors.append(f"autogen_root_invalid_projected_path: {detail}")
                return None, errors
            return parent_uid, errors
        parent_metadata = metadata_by_uid.get(parent_uid)
        if parent_metadata is None:
            errors.append("autogen_parent_ineligible: parent is not an autogen metadata document")
            return None, errors
        if parent_metadata.reconstructable != "true":
            errors.append("autogen_parent_ineligible: parent is not marked reconstructable")
            return None, errors
        parent_uid = parent_metadata.parent_uid


def rebuild_autogen_registry(
    root: Path,
    config: configparser.ConfigParser,
    apply: bool,
) -> tuple[dict[str, AutogenMetadata], dict[str, list[str]], dict[str, str], dict[str, str], list[ScanAction]]:
    metadata_by_uid, actions = autogen_metadata_index(root, config)
    children_by_parent = build_autogen_children(metadata_by_uid)
    root_by_uid: dict[str, str] = {}
    status_by_uid: dict[str, str] = {}
    errors_by_uid: dict[str, list[str]] = {}

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
            if not metadata.parent_uid:
                status_by_uid[uid] = "unassigned"
            else:
                root_uid, root_errors = resolve_autogen_root(uid, root, config, metadata_by_uid)
                errors.extend(root_errors)
                if root_uid:
                    root_by_uid[uid] = root_uid
                    status_by_uid[uid] = "assigned"
                else:
                    status_by_uid[uid] = "error"
        if errors:
            errors_by_uid[uid] = errors
            status_by_uid[uid] = "error"

    if apply:
        config[AUTOGEN_CHILDREN_SECTION].clear()
        for parent_uid, children in children_by_parent.items():
            if children:
                config[AUTOGEN_CHILDREN_SECTION][parent_uid] = ";".join(children)

        config[AUTOGEN_ROOT_SECTION].clear()
        for uid, root_uid in root_by_uid.items():
            config[AUTOGEN_ROOT_SECTION][uid] = root_uid

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
    return metadata_by_uid, children_by_parent, root_by_uid, status_by_uid, actions


def generated_cpp_destination(root: Path, config: configparser.ConfigParser, root_uid: str) -> Path | None:
    stored_path = config["files"].get(root_uid)
    if stored_path is None:
        return None
    projected_path = config[PROJECTED_PATH_SECTION].get(root_uid, "")
    normalized, status, _ = validate_projected_path(projected_path)
    if status != "valid":
        return None
    return generated_cpp_path(root, normalized, Path(stored_path).stem)


def fallback_insert_children(code: str, children_text: str, folder: str) -> tuple[str, str | None]:
    if not children_text:
        if CHILDREN_MARKER in code:
            return code.replace(CHILDREN_MARKER, NO_CHILDREN_MARKER), None
        return code, None
    if not code.strip():
        return children_text, "autogen_parent_has_no_code"
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


def autogen_snippet_header(metadata: AutogenMetadata) -> str:
    return f"// UID:{metadata.uid} | {metadata.path}"


def assemble_autogen_node(
    uid: str,
    metadata_by_uid: dict[str, AutogenMetadata],
    children_by_parent: dict[str, list[str]],
    status_by_uid: dict[str, str],
    coded_uids: set[str],
    actions: list[ScanAction],
    root: Path,
    config: configparser.ConfigParser,
    stack: set[str] | None = None,
) -> str:
    stack = set() if stack is None else set(stack)
    if uid in stack:
        actions.append(ScanAction("autogen_parent_cycle", uid, absolute_path(root, config["files"].get(uid, ".")), "cycle during assembly"))
        return ""
    stack.add(uid)

    metadata = metadata_by_uid.get(uid)
    if metadata is None or status_by_uid.get(uid) == "error":
        return ""

    child_snippets = [
        assemble_autogen_node(child_uid, metadata_by_uid, children_by_parent, status_by_uid, coded_uids, actions, root, config, stack)
        for child_uid in children_by_parent.get(uid, [])
    ]
    children_text = join_snippets(child_snippets)
    code = metadata.code
    assembled, warning = fallback_insert_children(code, children_text, metadata.folder)
    if warning:
        actions.append(
            ScanAction(
                warning,
                uid,
                absolute_path(root, metadata.path),
                "explicit [[CHILDREN]] marker is preferred" if warning != "autogen_parent_has_no_code" else "emitting children only",
            )
        )
        if warning == "autogen_children_marker_missing":
            assembled = code

    if assembled.strip():
        coded_uids.add(uid)
        return autogen_snippet_header(metadata) + "\n" + assembled.strip("\n")
    return assembled


def assemble_autogen_root(
    root_uid: str,
    metadata_by_uid: dict[str, AutogenMetadata],
    children_by_parent: dict[str, list[str]],
    status_by_uid: dict[str, str],
    root: Path,
    config: configparser.ConfigParser,
    actions: list[ScanAction],
) -> tuple[str, set[str]]:
    coded_uids: set[str] = set()
    snippets = [
        assemble_autogen_node(child_uid, metadata_by_uid, children_by_parent, status_by_uid, coded_uids, actions, root, config)
        for child_uid in children_by_parent.get(root_uid, [])
    ]
    return join_snippets(snippets), coded_uids


def generated_cpp_content(root_uid: str, root_path: str, assembled: str) -> str:
    body = assembled.strip("\n")
    header = "\n".join(
        [
            AUTOGEN_SENTINEL,
            f"// Source by-file UID: {root_uid}",
            f"// Source by-file doc: {root_path}",
            "",
        ]
    )
    return header + (body + "\n" if body else "")


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


def backup_generated_file(root: Path, path: Path, state: dict[str, Path | None]) -> Path:
    backup_root = state.get("backup_root")
    if backup_root is None:
        timestamp = datetime.now().strftime("%Y%m%d-%H%M%S")
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
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    state = classify_generated_file(path)
    if state == "manual_or_conflict":
        return [ScanAction(conflict_action, uid, path, "nonempty file lacks validator autogen sentinel")]
    if path.exists():
        try:
            old_text = read_text(path)
        except UnicodeDecodeError:
            return [ScanAction(conflict_action, uid, path, "existing file is not UTF-8 text")]
        if old_text == text:
            return [ScanAction(noop_action, uid, path, "unchanged")]
        actions.append(ScanAction(update_action, uid, path, "validator-owned generated file"))
        if apply:
            backup_generated_file(root, path, backup_state)
            write_text_atomic(path, text)
    else:
        actions.append(ScanAction(create_action, uid, path, "new generated file"))
        if apply:
            write_text_atomic(path, text)
    return actions


def autogen_report_stats(entries: list[AutogenReportEntry]) -> list[str]:
    total_type = len(entries)
    total_reconstructable = sum(1 for entry in entries if entry.status in {"unassigned", "assigned", "coded", "error"})
    total_not = sum(1 for entry in entries if entry.status == "not_reconstructable")
    total_assigned = sum(1 for entry in entries if entry.status in {"assigned", "coded"})
    total_coded = sum(1 for entry in entries if entry.status == "coded")
    total_unassigned = sum(1 for entry in entries if entry.status == "unassigned")
    total_unclassified = sum(1 for entry in entries if entry.status == "unclassified")
    total_error = sum(1 for entry in entries if entry.status == "error")
    return [
        f"Total_Type: {total_type}",
        f"Total_Reconstructable: {total_reconstructable}",
        f"Total_Not_Reconstructable: {total_not}",
        f"Total_Reconstructed_Assigned: {total_assigned}",
        f"Total_Reconstructed_Coded: {total_coded}",
        f"Total_Reconstructable_Unassigned: {total_unassigned}",
        f"Total_Unclassified: {total_unclassified}",
        f"Total_Error: {total_error}",
    ]


def render_autogen_report(title: str, entries: list[AutogenReportEntry]) -> str:
    lines = [
        AUTOGEN_MARKDOWN_SENTINEL,
        "",
        f"# {title}",
        "",
        *autogen_report_stats(entries),
        "",
        "| UID | Status | Parent | Position | Code | Destination | Path | Detail |",
        "| --- | --- | --- | ---: | --- | --- | --- | --- |",
    ]
    for entry in sorted(entries, key=lambda item: (item.status, item.path, item.uid)):
        parent = f"`{entry.parent_uid}`" if entry.parent_uid else ""
        position = entry.position
        code = "yes" if entry.has_code else "no"
        destination = f"`{entry.destination}`" if entry.destination else ""
        lines.append(
            f"| {uid_link(entry.uid, entry.path)} | {entry.status} | {parent} | {position} | "
            f"{code} | {destination} | `{entry.path}` | {entry.detail} |"
        )
    return "\n".join(lines) + "\n"


def autogen_report_entries(
    root: Path,
    config: configparser.ConfigParser,
    metadata_by_uid: dict[str, AutogenMetadata],
    root_by_uid: dict[str, str],
    status_by_uid: dict[str, str],
    coded_uids: set[str],
) -> dict[str, list[AutogenReportEntry]]:
    reports: dict[str, list[AutogenReportEntry]] = {name: [] for name in AUTOGEN_TOP_LEVEL_REPORTS.values()}
    reports[AUTOGEN_FILE_REPORT] = []

    for uid, stored_path in config["files"].items():
        if is_projected_path_candidate(stored_path):
            destination = ""
            target = generated_cpp_destination(root, config, uid)
            if target is not None:
                destination = relative_path(root, target)
            status = "coded" if any(root_uid == uid and child_uid in coded_uids for child_uid, root_uid in root_by_uid.items()) else "assigned"
            projected = config[PROJECTED_PATH_STATUS_SECTION].get(uid, "blank")
            detail = "by-file generated root"
            if projected == "none":
                status = "not_reconstructable"
                detail = "reviewed non-standalone by-file page; no generated root"
            elif projected != "valid":
                status = "error"
            reports[AUTOGEN_FILE_REPORT].append(
                AutogenReportEntry(
                    uid=uid,
                    path=stored_path,
                    folder="by-file",
                    status=status,
                    destination=destination,
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
        root_uid = root_by_uid.get(uid)
        if root_uid:
            target = generated_cpp_destination(root, config, root_uid)
            if target is not None:
                destination = relative_path(root, target)
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
                parent_uid=metadata.parent_uid,
                position=metadata.parent_position_raw,
                has_code=bool(metadata.code.strip()),
                destination=destination,
                detail=detail,
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


def run_autogen_generation(
    root: Path,
    config: configparser.ConfigParser,
    apply: bool,
) -> list[ScanAction]:
    actions: list[ScanAction] = []
    backup_state: dict[str, Path | None] = {"backup_root": None}
    metadata_by_uid, children_by_parent, root_by_uid, status_by_uid, registry_actions = rebuild_autogen_registry(root, config, apply)
    actions.extend(registry_actions)

    all_coded_uids: set[str] = set()
    for root_uid in sorted(set(root_by_uid.values()), key=lambda uid: config["files"].get(uid, "")):
        target = generated_cpp_destination(root, config, root_uid)
        if target is None:
            actions.append(
                ScanAction("autogen_root_invalid_projected_path", root_uid, root, "root has no valid generated destination")
            )
            continue
        assembled, coded_uids = assemble_autogen_root(
            root_uid,
            metadata_by_uid,
            children_by_parent,
            status_by_uid,
            root,
            config,
            actions,
        )
        all_coded_uids.update(coded_uids)
        if not assembled.strip():
            actions.append(ScanAction("autogen_cpp_noop", root_uid, target, "no assembled code for root"))
            continue
        root_path = config["files"].get(root_uid, "")
        content = generated_cpp_content(root_uid, root_path, assembled)
        actions.extend(
            safe_write_generated_text(
                root,
                target,
                content,
                root_uid,
                apply,
                backup_state,
                "autogen_cpp_create",
                "autogen_cpp_update",
                "autogen_cpp_noop",
                "autogen_cpp_conflict",
            )
        )

    if apply:
        for uid in all_coded_uids:
            if uid in config[AUTOGEN_STATUS_SECTION]:
                config[AUTOGEN_STATUS_SECTION][uid] = "coded"

    reports = autogen_report_entries(root, config, metadata_by_uid, root_by_uid, status_by_uid, all_coded_uids)
    for name, entries in sorted(reports.items()):
        report_path = root / AUTO_GENERATED_RELATIVE_PATH / name
        report_text = render_autogen_report(Path(name).stem.lstrip("-"), entries)
        actions.extend(
            safe_write_generated_text(
                root,
                report_path,
                report_text,
                None,
                apply,
                backup_state,
                "autogen_report_create",
                "autogen_report_update",
                "autogen_report_noop",
                "autogen_report_conflict",
            )
        )
    actions.extend(cleanup_old_coverage_placeholders(root, apply, backup_state))
    if backup_state.get("backup_root") is not None:
        actions.append(ScanAction("autogen_backup_create", None, backup_state["backup_root"], "changed generated files backed up"))
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


def markdown_stats_table(entries: list[StatsEntry], limit: int = 25) -> str:
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
    )


def stats_sort_key(entry: StatsEntry, table_name: str) -> tuple[float, int, int, str]:
    if table_name == "Low_Completion":
        return (float(entry.completion), entry.confidence, 0, entry.path)
    if table_name == "Low_Confidence":
        return (float(entry.confidence), entry.completion, 0, entry.path)
    return (entry.combined, entry.completion, entry.confidence, entry.path)


def stats_score_key(entry: StatsEntry, table_name: str) -> tuple[float, int, int]:
    if table_name == "Low_Completion":
        return (float(entry.completion), entry.confidence, 0)
    if table_name == "Low_Confidence":
        return (float(entry.confidence), entry.completion, 0)
    return (entry.combined, entry.completion, entry.confidence)


def generate_completion_stats_text(root: Path, config: configparser.ConfigParser) -> str:
    entries = stats_entries_from_config(config)
    scored = scored_entries(entries)
    ignored_count = len(entries) - len(scored)
    folders = sorted(
        {entry.folder for entry in entries}
        | {directory.name for directory in by_directories(root)}
    )

    low_completion = sorted(scored, key=lambda entry: (entry.completion, entry.confidence, entry.path))
    low_confidence = sorted(scored, key=lambda entry: (entry.confidence, entry.completion, entry.path))
    low_both = sorted(scored, key=lambda entry: (entry.combined, entry.completion, entry.confidence, entry.path))

    lines = [
        "# Auto Completion Stats",
        "",
        f"Generated: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}",
        "",
        "Scores use `COMPLETION` and `CONFIDENCE` metadata from validator-scanned by-* Markdown files.",
        "`0` means unevaluated. `-1` means ignored and is excluded from low-score lists.",
        "`Combined` is the average of completion and confidence.",
        "",
        "## Summary",
        "",
        f"- Tracked files: {len(entries)}",
        f"- Scored files: {len(scored)}",
        f"- Ignored files: {ignored_count}",
        "",
        "## projected_path_completion",
        "",
        "By-file documents whose `PROPOSED_RECONSTRUCTION_PATH` is blank or invalid. `NONE` marks a reviewed non-standalone page and is excluded.",
        "",
        markdown_projected_path_table(config),
        "## Low_Completion",
        "",
        markdown_stats_table(low_completion),
        "## Low_Confidence",
        "",
        markdown_stats_table(low_confidence),
        "## Low_Both",
        "",
        markdown_stats_table(low_both),
        "## By Folder",
        "",
    ]

    for folder in folders:
        folder_entries = [
            entry for entry in scored
            if entry.folder == folder
        ]
        folder_entries.sort(key=lambda entry: (entry.combined, entry.completion, entry.confidence, entry.path))
        lines.extend([
            f"### {folder}",
            "",
            markdown_stats_table(folder_entries),
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
            (index for index, line in enumerate(lines) if line.strip() == "## Low_Completion"),
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
    if target_index >= 25:
        return sorted_remaining[:25], "remove"

    if old_last is not None and stats_score_key(entry, table_name) > stats_score_key(old_last, table_name):
        return sorted_remaining, "remove"

    return updated_rows[:25], "update"


def update_stats_text_for_entry(
    text: str,
    entry: StatsEntry,
    stats_path: Path,
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

            updated_rows, action = update_stats_table_rows(rows, entry, current_table)
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
    new_text, actions = update_stats_text_for_entry(text, entry, stats_path)
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


def summarize(actions: list[ScanAction]) -> dict[str, int]:
    counts: dict[str, int] = {}
    for action in actions:
        counts[action.action] = counts.get(action.action, 0) + 1
    return counts


def print_actions(actions: list[ScanAction], root: Path, verbose: bool) -> None:
    for action in actions:
        if not verbose and action.action == "ok":
            continue
        uid = action.uid or "------"
        print(f"{action.action:12} {uid} {relative_path(root, action.path)} {action.detail}".rstrip())


def run_validator(args, root: Path, ini: Path, lock_path: Path) -> int:
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
        print_actions(actions, root, args.verbose or not args.apply)
        if args.apply:
            print("isolated scan is report-only; --apply made no changes")
        else:
            print("dry run only; isolated scan is report-only")
        return 0

    original_files = dict(config["files"])
    targets, pre_actions = scan_targets(args, root, config)

    generated_order: list[str] = []
    actions: list[ScanAction] = list(pre_actions)
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
                        "missing_parent_uid",
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

    if (
        args.mode in {"full", "documented", "file", "autogen"}
        and not args.uid_only
        and not args.reference_only
    ):
        actions.extend(run_autogen_generation(root, config, args.apply))

    if args.apply:
        write_config_atomic(config, ini)

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
    print_actions(actions, root, args.verbose or not args.apply)
    if not args.apply:
        print("dry run only; pass --apply to write changes")
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
    argv = job.get("argv", [])
    if not isinstance(argv, list) or not all(isinstance(item, str) for item in argv):
        return DEDUP_NONE

    mode = queued_command_mode(argv)
    apply = queued_flag_present(argv, "--apply")
    remove_missing = queued_flag_present(argv, "--remove-missing")
    uid_only = queued_flag_present(argv, "--uid-only")
    reference_only = queued_flag_present(argv, "--reference-only")

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


def process_queued_job(queue_dir: Path, job_path: Path) -> None:
    result_path: Path | None = None
    result_paths: list[Path] = []
    try:
        job = json.loads(job_path.read_text(encoding="utf-8"))
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


def main(argv: list[str] | None = None) -> int:
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
        choices=("full", "documented", "file", "rescore", "isolated", "autogen"),
        default="full",
    )
    parser.add_argument(
        "-isolated",
        "--isolated",
        action="store_true",
        help="alias for --mode isolated; report by-* Markdown files with no inbound UID references",
    )
    parser.add_argument("--file", help="Markdown file to scan when --mode file is used")
    parser.add_argument("--apply", action="store_true", help="write Markdown and validator.ini changes")
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
