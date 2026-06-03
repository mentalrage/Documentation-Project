#!/usr/bin/env python3
"""Index unresolved decompiler-style names in project documentation.

Default behavior is a dry run. Pass --apply to write unresolved.ini and the
project-level Markdown report.
"""

from __future__ import annotations

import argparse
import configparser
import json
import os
import re
import sys
import tempfile
from dataclasses import dataclass
from datetime import datetime
from pathlib import Path
from typing import Iterable


TOOL_DIR = Path(__file__).resolve().parent
DEFAULT_ROOT = TOOL_DIR.parent
DEFAULT_JSON = TOOL_DIR / "unresolved.json"
DEFAULT_INI = TOOL_DIR / "unresolved.ini"
DEFAULT_OUTPUT = Path("project-level") / "-unresolved.md"
DEFAULT_RESOLVED_OUTPUT = Path("project-level") / "-resolved.md"
DEFAULT_MULTIPLE_ALIASES_OUTPUT = Path("project-level") / "-resolved-multple-aliases.md"
RESOLVED_NAMES_SECTION = "resolved_names"
RESOLVED_ALIASES_SECTION = "resolved_aliases"
RESOLVED_COVERAGE_SECTION = "resolved_coverage"


@dataclass(frozen=True)
class FilterSpec:
    name: str
    pattern: str
    description: str
    regex: re.Pattern[str]


@dataclass(frozen=True)
class MatchRecord:
    name: str
    files: tuple[str, ...]
    occurrences: tuple["OccurrenceRecord", ...]

    @property
    def protected_occurrences(self) -> int:
        return sum(1 for occurrence in self.occurrences if occurrence.kind != "text")


@dataclass(frozen=True)
class OccurrenceRecord:
    file: str
    line: int
    column: int
    before: str
    after: str
    kind: str


def safe_resolve(path: Path) -> Path:
    try:
        return path.resolve(strict=False)
    except RuntimeError:
        return path.absolute()


def write_text_atomic(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.NamedTemporaryFile(
        "w", encoding="utf-8", newline="\n", delete=False, dir=str(path.parent)
    ) as tmp:
        tmp.write(text)
        tmp_name = tmp.name
    os.replace(tmp_name, path)


def write_config_atomic(config: configparser.ConfigParser, path: Path) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.NamedTemporaryFile(
        "w", encoding="utf-8", newline="\n", delete=False, dir=str(path.parent)
    ) as tmp:
        config.write(tmp)
        tmp_name = tmp.name
    os.replace(tmp_name, path)


def load_json_config(path: Path) -> dict:
    try:
        with path.open("r", encoding="utf-8-sig") as handle:
            data = json.load(handle)
    except FileNotFoundError:
        raise SystemExit(f"missing unresolved JSON config: {path}")
    except json.JSONDecodeError as exc:
        raise SystemExit(f"invalid unresolved JSON config {path}: {exc}") from exc

    if not isinstance(data, dict):
        raise SystemExit(f"unresolved JSON config must be an object: {path}")
    return data


def compile_filters(config: dict) -> list[FilterSpec]:
    flags = 0 if config.get("case_sensitive", True) else re.IGNORECASE
    filters = config.get("filters", [])
    if not isinstance(filters, list):
        raise SystemExit("unresolved JSON field 'filters' must be a list")

    compiled: list[FilterSpec] = []
    for index, item in enumerate(filters):
        if not isinstance(item, dict):
            raise SystemExit(f"filter #{index + 1} must be an object")
        if not item.get("enabled", True):
            continue
        name = str(item.get("name", "")).strip()
        pattern = str(item.get("pattern", "")).strip()
        description = str(item.get("description", "")).strip()
        if not name:
            raise SystemExit(f"filter #{index + 1} has no name")
        if not re.fullmatch(r"[A-Za-z0-9_.-]+", name):
            raise SystemExit(f"filter name contains unsupported characters: {name}")
        if not pattern:
            raise SystemExit(f"filter {name} has no pattern")
        try:
            regex = re.compile(pattern, flags)
        except re.error as exc:
            raise SystemExit(f"invalid regex for filter {name}: {exc}") from exc
        compiled.append(FilterSpec(name=name, pattern=pattern, description=description, regex=regex))

    if not compiled:
        raise SystemExit("unresolved JSON config has no enabled filters")
    return compiled


def load_ini(path: Path) -> configparser.ConfigParser:
    config = configparser.ConfigParser(interpolation=None)
    config.optionxform = str
    if path.exists():
        config.read(path, encoding="utf-8-sig")
    for section in (
        "state",
        "filters",
        "matches",
        "occurrence_summary",
        "occurrences",
        RESOLVED_NAMES_SECTION,
        RESOLVED_ALIASES_SECTION,
        RESOLVED_COVERAGE_SECTION,
    ):
        if section not in config:
            config[section] = {}
    return config


def by_directories(root: Path) -> list[Path]:
    return sorted(path for path in root.iterdir() if path.is_dir() and path.name.startswith("by-"))


def is_excluded_path(path: Path, excluded_dirs: set[str], excluded_suffixes: tuple[str, ...]) -> bool:
    if any(part in excluded_dirs for part in path.parts):
        return True
    return any(path.name.endswith(suffix) for suffix in excluded_suffixes)


def iter_scan_files(root: Path, config: dict) -> list[Path]:
    extensions = config.get("scan_extensions", [".md"])
    if not isinstance(extensions, list) or not extensions:
        raise SystemExit("unresolved JSON field 'scan_extensions' must be a non-empty list")
    normalized_extensions = {str(ext).lower() for ext in extensions}

    excluded_dirs_raw = config.get("exclude_directory_names", [])
    excluded_suffixes_raw = config.get("exclude_file_suffixes", [])
    if not isinstance(excluded_dirs_raw, list):
        raise SystemExit("unresolved JSON field 'exclude_directory_names' must be a list")
    if not isinstance(excluded_suffixes_raw, list):
        raise SystemExit("unresolved JSON field 'exclude_file_suffixes' must be a list")
    excluded_dirs = {str(item) for item in excluded_dirs_raw}
    excluded_suffixes = tuple(str(item) for item in excluded_suffixes_raw)

    targets: list[Path] = []
    for by_dir in by_directories(root):
        for path in by_dir.rglob("*"):
            if not path.is_file():
                continue
            if path.suffix.lower() not in normalized_extensions:
                continue
            if is_excluded_path(path.relative_to(root), excluded_dirs, excluded_suffixes):
                continue
            targets.append(path)
    return sorted(targets)


def relative_path(root: Path, path: Path) -> str:
    try:
        return safe_resolve(path).relative_to(safe_resolve(root)).as_posix()
    except ValueError:
        return safe_resolve(path).as_posix()


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


def resolve_file_argument(root: Path, value: str, cwd: Path) -> Path:
    raw_path = Path(value).expanduser()
    candidates: list[Path] = []

    def add(path: Path) -> None:
        if path not in candidates:
            candidates.append(path)

    if raw_path.is_absolute():
        add(raw_path)
    else:
        add(cwd / raw_path)
        add(root / raw_path)

    suffix = project_documentation_suffix(raw_path)
    if suffix is not None:
        add(root / suffix)
    cwd_suffix = project_documentation_suffix(cwd / raw_path)
    if cwd_suffix is not None:
        add(root / cwd_suffix)

    for candidate in candidates:
        resolved = safe_resolve(candidate)
        try:
            relative = resolved.relative_to(safe_resolve(root))
        except ValueError:
            continue
        if len(relative.parts) >= 2 and relative.parts[0].startswith("by-"):
            return root / relative

    return raw_path if raw_path.is_absolute() else cwd / raw_path


def file_targets(args: argparse.Namespace, root: Path, config: dict) -> list[Path]:
    if args.mode == "full":
        return iter_scan_files(root, config)
    if not args.file:
        raise SystemExit("--file is required when --mode file is used")
    path = resolve_file_argument(root, args.file, Path.cwd())
    try:
        relative = safe_resolve(path).relative_to(safe_resolve(root))
    except ValueError:
        raise SystemExit(f"file is outside documentation root: {path}")
    if len(relative.parts) < 2 or not relative.parts[0].startswith("by-"):
        raise SystemExit(f"file is outside direct by-* folders: {path}")
    if path.suffix.lower() != ".md":
        raise SystemExit(f"file is not Markdown: {path}")
    return [path]


def read_text(path: Path) -> str:
    try:
        return path.read_text(encoding="utf-8-sig")
    except UnicodeDecodeError:
        return path.read_text(encoding="utf-8", errors="replace")


def line_column_for_offset(text: str, offset: int) -> tuple[int, int]:
    line = text.count("\n", 0, offset) + 1
    line_start = text.rfind("\n", 0, offset)
    column = offset + 1 if line_start < 0 else offset - line_start
    return line, column


def find_markdown_link_spans(text: str) -> list[tuple[int, int]]:
    spans: list[tuple[int, int]] = []
    for match in re.finditer(r"!?\[[^\]\r\n]*\]\([^\)\r\n]*\)", text):
        spans.append((match.start(), match.end()))
    for match in re.finditer(r"^\s*\[[^\]\r\n]+\]:\s+\S+", text, re.MULTILINE):
        spans.append((match.start(), match.end()))
    return spans


def offset_in_spans(offset: int, spans: list[tuple[int, int]]) -> bool:
    return any(start <= offset < end for start, end in spans)


def surrounding_token(text: str, start: int, end: int) -> str:
    left = start
    right = end
    stop_chars = set(" \t\r\n`\"'<>")
    while left > 0 and text[left - 1] not in stop_chars:
        left -= 1
    while right < len(text) and text[right] not in stop_chars:
        right += 1
    return text[left:right]


def occurrence_kind(text: str, start: int, end: int, link_spans: list[tuple[int, int]]) -> str:
    if offset_in_spans(start, link_spans):
        return "markdown_link"
    token = surrounding_token(text, start, end)
    token_lower = token.lower()
    if "/" in token or "\\" in token or ".md" in token_lower or ".html" in token_lower:
        return "path"
    return "text"


def occurrence_context(text: str, start: int, end: int, width: int = 20) -> tuple[str, str]:
    before = text[max(0, start - width) : start]
    after = text[end : min(len(text), end + width)]
    return before, after


def scan_files(
    root: Path,
    targets: Iterable[Path],
    filters: list[FilterSpec],
) -> tuple[dict[str, set[str]], dict[str, list[OccurrenceRecord]], dict[str, int], dict[str, str]]:
    matches: dict[str, set[str]] = {}
    occurrences: dict[str, list[OccurrenceRecord]] = {}
    filter_counts = {spec.name: 0 for spec in filters}
    file_texts: dict[str, str] = {}

    for path in targets:
        text = read_text(path)
        rel = relative_path(root, path)
        file_texts[rel] = text
        link_spans = find_markdown_link_spans(text)
        file_names: set[str] = set()
        for spec in filters:
            for match in spec.regex.finditer(text):
                token = match.group(0)
                file_names.add(token)
                filter_counts[spec.name] += 1
                line, column = line_column_for_offset(text, match.start())
                before, after = occurrence_context(text, match.start(), match.end())
                occurrences.setdefault(token, []).append(
                    OccurrenceRecord(
                        file=rel,
                        line=line,
                        column=column,
                        before=before,
                        after=after,
                        kind=occurrence_kind(text, match.start(), match.end(), link_spans),
                    )
                )
        for token in file_names:
            matches.setdefault(token, set()).add(rel)

    return matches, occurrences, filter_counts, file_texts


def sorted_records(
    matches: dict[str, set[str]],
    occurrences: dict[str, list[OccurrenceRecord]],
) -> list[MatchRecord]:
    records = [
        MatchRecord(
            name=name,
            files=tuple(sorted(files, key=str.casefold)),
            occurrences=tuple(
                sorted(
                    occurrences.get(name, []),
                    key=lambda item: (item.file.casefold(), item.line, item.column),
                )
            ),
        )
        for name, files in matches.items()
    ]
    return sorted(records, key=lambda item: (item.name.casefold(), item.name))


def markdown_escape_cell(value: str) -> str:
    return value.replace("\\", "\\\\").replace("|", "\\|")


def inline_context(value: str) -> str:
    return (
        value.replace("\r", "\\r")
        .replace("\n", "\\n")
        .replace("`", "'")
        .replace("|", "\\|")
    )


def occurrence_snippet(name: str, occurrence: OccurrenceRecord) -> str:
    return (
        f"[{inline_context(occurrence.before)}] > `{name}` > "
        f"[{inline_context(occurrence.after)}] ({occurrence.kind}, "
        f"L{occurrence.line}:C{occurrence.column})"
    )


def record_for_files(record: MatchRecord, files: set[str]) -> MatchRecord | None:
    if not files:
        return None
    return MatchRecord(
        name=record.name,
        files=tuple(file_path for file_path in record.files if file_path in files),
        occurrences=tuple(
            occurrence for occurrence in record.occurrences
            if occurrence.file in files
        ),
    )


def split_unresolved_records(
    records: list[MatchRecord],
    resolved_names: dict[str, str],
    aliases: dict[str, str],
    file_texts: dict[str, str],
) -> list[MatchRecord]:
    unresolved: list[MatchRecord] = []
    for record in records:
        resolved_name = resolved_names.get(record.name)
        if not resolved_name:
            unresolved.append(record)
            continue
        pending_files = {
            file_path for file_path in record.files
            if not resolved_name_in_text(resolved_name, aliases, file_texts.get(file_path, ""))
        }
        pending_record = record_for_files(record, pending_files)
        if pending_record is not None:
            unresolved.append(pending_record)
    return unresolved


def generate_report(root: Path, records: list[MatchRecord], filters: list[FilterSpec], filter_counts: dict[str, int], scanned_count: int) -> str:
    generated = datetime.now().isoformat(timespec="seconds")
    total_refs = sum(len(record.files) for record in records)
    total_occurrences = sum(len(record.occurrences) for record in records)
    protected_occurrences = sum(record.protected_occurrences for record in records)
    lines: list[str] = [
        "# Unresolved Name Index",
        "",
        f"Generated: {generated}",
        "",
        "This report is generated by `tools/unresolved.py` from Markdown files under direct `by-*` folders.",
        "It indexes decompiler-style placeholders and raw offsets that still need human-made names or explicit justification.",
        "",
        "## Summary",
        "",
        f"- Scanned files: {scanned_count}",
        f"- Unique unresolved names: {len(records)}",
        f"- File references: {total_refs}",
        f"- Occurrences: {total_occurrences}",
        f"- Markdown link/path occurrences: {protected_occurrences}",
        "",
        "## Filters",
        "",
        "| Filter | Matches | Description |",
        "| --- | ---: | --- |",
    ]
    for spec in filters:
        lines.append(
            f"| `{markdown_escape_cell(spec.name)}` | {filter_counts.get(spec.name, 0)} | "
            f"{markdown_escape_cell(spec.description)} |"
        )

    lines.extend(
        [
            "",
            "## Unresolved Names",
            "",
        ]
    )
    if not records:
        lines.append("_No unresolved names matched the configured filters._")
        lines.append("")
        return "\n".join(lines)

    for record in records:
        lines.extend(
            [
                f"### `{record.name}`",
                "",
                (
                    f"- References: {len(record.files)} "
                    f"Occurrences: {len(record.occurrences)} "
                    f"Markdown link/path occurrences: {record.protected_occurrences}"
                ),
                "",
            ]
        )
        for file_path in record.files:
            file_occurrences = [
                occurrence for occurrence in record.occurrences
                if occurrence.file == file_path
            ]
            if file_occurrences:
                snippets = " | ".join(
                    occurrence_snippet(record.name, occurrence)
                    for occurrence in file_occurrences
                )
                lines.append(f"- `{file_path}` | {snippets}")
            else:
                lines.append(f"- `{file_path}`")
        lines.append("")
    return "\n".join(lines)


def names_for_resolved_name(resolved_name: str, aliases: dict[str, str]) -> list[str]:
    names = [resolved_name]
    names.extend(
        alias for alias, target in sorted(aliases.items(), key=lambda item: item[0].casefold())
        if target == resolved_name
    )
    return names


def aliases_for_resolved_name(resolved_name: str, aliases: dict[str, str]) -> list[str]:
    return [
        alias for alias, target in sorted(aliases.items(), key=lambda item: item[0].casefold())
        if target == resolved_name
    ]


def matched_resolved_names(resolved_name: str, aliases: dict[str, str], text: str) -> list[tuple[str, str]]:
    matches: list[tuple[str, str]] = []
    if resolved_name in text:
        matches.append((resolved_name, "resolved"))
    for alias in aliases_for_resolved_name(resolved_name, aliases):
        if alias in text:
            matches.append((alias, "alias"))
    return matches


def resolved_name_in_text(resolved_name: str, aliases: dict[str, str], text: str) -> bool:
    return bool(matched_resolved_names(resolved_name, aliases, text))


def resolved_status_for_file(
    file_path: str,
    resolved_name: str,
    aliases: dict[str, str],
    file_texts: dict[str, str],
) -> str:
    return "covered" if resolved_name_in_text(resolved_name, aliases, file_texts.get(file_path, "")) else "pending"


def matched_names_text(matches: list[tuple[str, str]]) -> str:
    if not matches:
        return "(none)"
    return ", ".join(f"`{name}` ({kind})" for name, kind in matches)


def generate_resolved_report(
    records: list[MatchRecord],
    resolved_names: dict[str, str],
    aliases: dict[str, str],
    file_texts: dict[str, str],
    scanned_count: int,
) -> str:
    generated = datetime.now().isoformat(timespec="seconds")
    record_by_name = {record.name: record for record in records}
    found_records = [
        record_by_name[name] for name in resolved_names
        if name in record_by_name
    ]
    total_file_refs = sum(len(record.files) for record in found_records)
    total_occurrences = sum(len(record.occurrences) for record in found_records)
    covered_files = 0
    pending_files = 0
    for record in found_records:
        resolved_name = resolved_names[record.name]
        for file_path in record.files:
            if resolved_status_for_file(file_path, resolved_name, aliases, file_texts) == "covered":
                covered_files += 1
            else:
                pending_files += 1

    lines: list[str] = [
        "# Resolved Name Index",
        "",
        f"Generated: {generated}",
        "",
        "This report is generated by `tools/unresolved.py` from resolved-name records in `tools/unresolved.ini`.",
        "A file is `covered` when it contains the generated token and the resolved name or one of its aliases.",
        "",
        "## Summary",
        "",
        f"- Scanned files: {scanned_count}",
        f"- Resolved name records: {len(resolved_names)}",
        f"- Alias records: {len(aliases)}",
        f"- Resolved tokens currently found: {len(found_records)}",
        f"- File references: {total_file_refs}",
        f"- Occurrences: {total_occurrences}",
        f"- Covered file references: {covered_files}",
        f"- Pending file references: {pending_files}",
        "",
        "## Resolved Names",
        "",
    ]
    if not resolved_names:
        lines.append("_No resolved-name records exist._")
        lines.append("")
        return "\n".join(lines)

    for token in sorted(resolved_names, key=lambda item: (item.casefold(), item)):
        resolved_name = resolved_names[token]
        token_aliases = aliases_for_resolved_name(resolved_name, aliases)
        record = record_by_name.get(token)
        alias_text = ", ".join(f"`{alias}`" for alias in token_aliases) if token_aliases else "(none)"
        if record is None:
            lines.extend(
                [
                    f"### `{token}` -> `{resolved_name}`",
                    "",
                    f"- Aliases: {alias_text}",
                    "- References: 0 Occurrences: 0 Covered file references: 0 Pending file references: 0",
                    "",
                    "_The generated token was not found in the current scan._",
                    "",
                ]
            )
            continue

        covered = sum(
            1 for file_path in record.files
            if resolved_status_for_file(file_path, resolved_name, aliases, file_texts) == "covered"
        )
        pending = len(record.files) - covered
        lines.extend(
            [
                f"### `{token}` -> `{resolved_name}`",
                "",
                f"- Aliases: {alias_text}",
                (
                    f"- References: {len(record.files)} "
                    f"Occurrences: {len(record.occurrences)} "
                    f"Covered file references: {covered} "
                    f"Pending file references: {pending}"
                ),
                "",
            ]
        )
        for file_path in record.files:
            status = resolved_status_for_file(file_path, resolved_name, aliases, file_texts)
            matched_names = matched_resolved_names(
                resolved_name,
                aliases,
                file_texts.get(file_path, ""),
            )
            file_occurrences = [
                occurrence for occurrence in record.occurrences
                if occurrence.file == file_path
            ]
            if file_occurrences:
                snippets = " | ".join(
                    occurrence_snippet(record.name, occurrence)
                    for occurrence in file_occurrences
                )
                lines.append(
                    f"- `{file_path}` | `{status}` | matched: {matched_names_text(matched_names)} | {snippets}"
                )
            else:
                lines.append(f"- `{file_path}` | `{status}` | matched: {matched_names_text(matched_names)}")
        lines.append("")
    return "\n".join(lines)


def generate_multiple_aliases_report(
    resolved_names: dict[str, str],
    aliases: dict[str, str],
) -> str:
    generated = datetime.now().isoformat(timespec="seconds")
    rows: list[tuple[str, str, list[str]]] = []
    for token, resolved_name in resolved_names.items():
        token_aliases = aliases_for_resolved_name(resolved_name, aliases)
        if token_aliases:
            rows.append((token, resolved_name, token_aliases))

    rows.sort(key=lambda item: (item[0].casefold(), item[0]))
    lines: list[str] = [
        "# Resolved Names With Aliases",
        "",
        f"Generated: {generated}",
        "",
        "This report is generated by `tools/unresolved.py` from alias records in `tools/unresolved.ini`.",
        "It only lists resolved generated tokens that currently have one or more temporary aliases.",
        "",
        "## Summary",
        "",
        f"- Resolved name records: {len(resolved_names)}",
        f"- Alias records: {len(aliases)}",
        f"- Resolved names with aliases: {len(rows)}",
        "",
        "## Aliases",
        "",
    ]
    if not rows:
        lines.append("_No resolved names currently have aliases._")
        lines.append("")
        return "\n".join(lines)

    lines.extend(
        [
            "| Filtered item | Resolved name | Aliases |",
            "| --- | --- | --- |",
        ]
    )
    for token, resolved_name, token_aliases in rows:
        alias_text = ", ".join(f"`{alias}`" for alias in token_aliases)
        lines.append(f"| `{token}` | `{resolved_name}` | {alias_text} |")
    lines.append("")
    return "\n".join(lines)


def update_ini(
    config: configparser.ConfigParser,
    records: list[MatchRecord],
    filters: list[FilterSpec],
    filter_counts: dict[str, int],
    scanned_count: int,
    resolved_names: dict[str, str],
    aliases: dict[str, str],
    file_texts: dict[str, str],
) -> None:
    config["state"].clear()
    config["state"]["last_generated"] = datetime.now().isoformat(timespec="seconds")
    config["state"]["scanned_files"] = str(scanned_count)
    config["state"]["unique_unresolved_names"] = str(len(records))
    config["state"]["total_file_references"] = str(sum(len(record.files) for record in records))
    config["state"]["total_occurrences"] = str(sum(len(record.occurrences) for record in records))
    config["state"]["total_markdown_link_path_occurrences"] = str(
        sum(record.protected_occurrences for record in records)
    )

    config["filters"].clear()
    for spec in filters:
        config["filters"][spec.name] = str(filter_counts.get(spec.name, 0))

    config["matches"].clear()
    for record in records:
        config["matches"][record.name] = ";".join(record.files)

    config["occurrence_summary"].clear()
    config["occurrences"].clear()
    config[RESOLVED_COVERAGE_SECTION].clear()
    for record in records:
        config["occurrence_summary"][record.name] = (
            f"occurrences={len(record.occurrences)};"
            f"markdown_link_path={record.protected_occurrences};"
            f"files={len(record.files)}"
        )
        config["occurrences"][record.name] = json.dumps(
            [
                {
                    "file": occurrence.file,
                    "line": occurrence.line,
                    "column": occurrence.column,
                    "kind": occurrence.kind,
                    "before": occurrence.before,
                    "after": occurrence.after,
                }
                for occurrence in record.occurrences
            ],
            ensure_ascii=True,
            separators=(",", ":"),
        )
        resolved_name = resolved_names.get(record.name, "")
        if resolved_name:
            covered = sum(
                1 for file_path in record.files
                if resolved_name_in_text(resolved_name, aliases, file_texts.get(file_path, ""))
            )
            pending = len(record.files) - covered
            alias_values = ",".join(
                alias for alias, target in sorted(aliases.items(), key=lambda item: item[0].casefold())
                if target == resolved_name
            )
            config[RESOLVED_COVERAGE_SECTION][record.name] = (
                f"resolved_name={resolved_name};"
                f"aliases={alias_values};"
                f"files={len(record.files)};"
                f"covered={covered};"
                f"pending={pending}"
            )


def output_path_from_config(root: Path, json_config: dict, arg_output: str | None) -> Path:
    value = arg_output or str(json_config.get("output", DEFAULT_OUTPUT.as_posix()))
    raw = Path(value)
    return raw if raw.is_absolute() else root / raw


def resolved_output_path_from_config(root: Path, json_config: dict, arg_output: str | None) -> Path:
    if arg_output:
        raw = Path(arg_output)
    else:
        raw = Path(str(json_config.get("resolved_output", DEFAULT_RESOLVED_OUTPUT.as_posix())))
    return raw if raw.is_absolute() else root / raw


def multiple_aliases_output_path_from_config(root: Path, json_config: dict, arg_output: str | None) -> Path:
    if arg_output:
        raw = Path(arg_output)
    else:
        raw = Path(
            str(json_config.get("multiple_aliases_output", DEFAULT_MULTIPLE_ALIASES_OUTPUT.as_posix()))
        )
    return raw if raw.is_absolute() else root / raw


def parse_args(argv: list[str] | None) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument(
        "command",
        nargs="?",
        choices=["scan", "resolve", "unresolve", "rename", "alias", "unalias"],
        default="scan",
        help="default scan writes reports; resolve/rename/unresolve/alias/unalias mutate resolved names",
    )
    parser.add_argument("token", nargs="?", help="generated token, alias target, or alias name")
    parser.add_argument("resolved_name", nargs="?", help="human name for resolve/rename, or alias value")
    parser.add_argument("--mode", choices=["full", "file"], default="full")
    parser.add_argument("--file", help="Markdown file to scan when --mode file is used")
    parser.add_argument("--root", default=str(DEFAULT_ROOT), help="project-documentation root")
    parser.add_argument("--config", default=str(DEFAULT_JSON), help="unresolved JSON config path")
    parser.add_argument("--ini", default=str(DEFAULT_INI), help="unresolved INI data path")
    parser.add_argument("--output", help="Markdown report path; defaults to JSON output setting")
    parser.add_argument("--resolved-output", help="resolved Markdown report path")
    parser.add_argument("--multiple-aliases-output", help="resolved aliases Markdown report path")
    parser.add_argument("--apply", action="store_true", help="write unresolved.ini and the Markdown report")
    parser.add_argument("--verbose", action="store_true", help="print matched names during the scan")
    return parser.parse_args(argv)


def require_token(args: argparse.Namespace) -> str:
    if not args.token:
        raise SystemExit(f"{args.command} requires a filter token")
    return args.token


def require_resolved_name(args: argparse.Namespace) -> str:
    if not args.resolved_name:
        raise SystemExit(f"{args.command} requires a resolved name")
    return args.resolved_name


def mutate_resolved_name(args: argparse.Namespace, ini_path: Path) -> int:
    config = load_ini(ini_path)
    section = config[RESOLVED_NAMES_SECTION]
    aliases = config[RESOLVED_ALIASES_SECTION]
    token = require_token(args)

    def token_for_resolved_name(name: str) -> str | None:
        for existing_token, existing_name in section.items():
            if existing_name == name:
                return existing_token
        return None

    def canonical_for_alias_target(name: str) -> str | None:
        if token_for_resolved_name(name) is not None:
            return name
        if name in aliases:
            return aliases[name]
        return None

    def validate_new_resolved_name(name: str, owner_token: str | None = None) -> None:
        if name in aliases:
            raise SystemExit(f"resolved name is already an alias: {name} -> {aliases[name]}")
        existing_owner = token_for_resolved_name(name)
        if existing_owner is not None and existing_owner != owner_token:
            raise SystemExit(f"resolved name already used: {name} = {existing_owner}")

    if args.command == "resolve":
        resolved_name = require_resolved_name(args)
        if token in section:
            raise SystemExit(f"already named: {token} = {section[token]}")
        validate_new_resolved_name(resolved_name)
        section[token] = resolved_name
        write_config_atomic(config, ini_path)
        print(f"resolved: {token} = {resolved_name}")
        return 0

    if args.command == "rename":
        resolved_name = require_resolved_name(args)
        if token not in section:
            raise SystemExit(f"not resolved: {token}")
        validate_new_resolved_name(resolved_name, token)
        old_name = section[token]
        section[token] = resolved_name
        for alias_name, target_name in list(aliases.items()):
            if target_name == old_name:
                aliases[alias_name] = resolved_name
        write_config_atomic(config, ini_path)
        print(f"renamed: {token} = {old_name} -> {resolved_name}")
        return 0

    if args.command == "unresolve":
        if token not in section:
            raise SystemExit(f"not resolved: {token}")
        old_name = section[token]
        del section[token]
        removed_aliases = [
            alias_name for alias_name, target_name in list(aliases.items())
            if target_name == old_name
        ]
        for alias_name in removed_aliases:
            del aliases[alias_name]
        write_config_atomic(config, ini_path)
        suffix = f"; removed aliases: {', '.join(removed_aliases)}" if removed_aliases else ""
        print(f"unresolved: {token} was {old_name}{suffix}")
        return 0

    if args.command == "alias":
        alias_name = require_resolved_name(args)
        canonical_name = canonical_for_alias_target(token)
        if canonical_name is None:
            raise SystemExit(f"alias target is not resolved: {token}")
        if alias_name in aliases:
            raise SystemExit(f"alias already exists: {alias_name} -> {aliases[alias_name]}")
        existing_owner = token_for_resolved_name(alias_name)
        if existing_owner is not None:
            raise SystemExit(f"alias name is already a resolved name: {alias_name} = {existing_owner}")
        if alias_name in section:
            raise SystemExit(f"alias name is already a filter token with resolved name: {alias_name}")
        if alias_name == canonical_name:
            raise SystemExit(f"alias name matches resolved name: {alias_name}")
        aliases[alias_name] = canonical_name
        write_config_atomic(config, ini_path)
        print(f"alias: {alias_name} -> {canonical_name}")
        return 0

    if args.command == "unalias":
        if token not in aliases:
            raise SystemExit(f"not an alias: {token}")
        old_target = aliases[token]
        del aliases[token]
        write_config_atomic(config, ini_path)
        print(f"unalias: {token} was {old_target}")
        return 0

    raise SystemExit(f"unknown command: {args.command}")


def main(argv: list[str] | None = None) -> int:
    args = parse_args(argv)
    root = safe_resolve(Path(args.root).expanduser())
    json_path = safe_resolve(Path(args.config).expanduser())
    ini_path = safe_resolve(Path(args.ini).expanduser())

    if args.command in {"resolve", "rename", "unresolve", "alias", "unalias"}:
        return mutate_resolved_name(args, ini_path)

    json_config = load_json_config(json_path)
    filters = compile_filters(json_config)
    targets = file_targets(args, root, json_config)
    matches, occurrences, filter_counts, file_texts = scan_files(root, targets, filters)
    records = sorted_records(matches, occurrences)

    config = load_ini(ini_path)
    resolved_names = dict(config[RESOLVED_NAMES_SECTION])
    aliases = dict(config[RESOLVED_ALIASES_SECTION])
    unresolved_records = split_unresolved_records(records, resolved_names, aliases, file_texts)
    report = generate_report(root, unresolved_records, filters, filter_counts, len(targets))
    resolved_report = generate_resolved_report(records, resolved_names, aliases, file_texts, len(targets))
    multiple_aliases_report = generate_multiple_aliases_report(resolved_names, aliases)
    update_ini(config, records, filters, filter_counts, len(targets), resolved_names, aliases, file_texts)
    output_path = output_path_from_config(root, json_config, args.output)
    resolved_output_path = resolved_output_path_from_config(root, json_config, args.resolved_output)
    multiple_aliases_output_path = multiple_aliases_output_path_from_config(
        root,
        json_config,
        args.multiple_aliases_output,
    )

    if args.verbose:
        for record in records:
            print(f"{record.name}: {len(record.files)} file(s)")

    print("scope: direct by-* folders under root")
    print(f"root: {root}")
    print(f"scanned markdown files: {len(targets)}")
    print(f"unique filtered names: {len(records)}")
    print(f"unique unresolved report names: {len(unresolved_records)}")
    print(f"resolved name records: {len(resolved_names)}")
    print(f"alias records: {len(aliases)}")
    print(f"file references: {sum(len(record.files) for record in unresolved_records)}")
    print(f"occurrences: {sum(len(record.occurrences) for record in unresolved_records)}")
    print(f"markdown link/path occurrences: {sum(record.protected_occurrences for record in unresolved_records)}")
    print(f"output: {output_path}")
    print(f"resolved output: {resolved_output_path}")
    print(f"multiple aliases output: {multiple_aliases_output_path}")
    if args.apply:
        write_config_atomic(config, ini_path)
        write_text_atomic(output_path, report)
        write_text_atomic(resolved_output_path, resolved_report)
        write_text_atomic(multiple_aliases_output_path, multiple_aliases_report)
        print("wrote unresolved.ini and Markdown reports")
    else:
        print("dry run only; pass --apply to write unresolved.ini and Markdown report")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
