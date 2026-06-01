#!/usr/bin/env python3
"""Find legacy Markdown links that can become UID references.

This is intentionally report-only. It scans Markdown files, finds inline links
like [label](../by-class/Foo.md), resolves only targets under direct by-*
folders, and reports the UID-reference form that a future converter could use.
"""

from __future__ import annotations

import argparse
import configparser
import os
import re
import shutil
import tempfile
import datetime as _dt
from collections import Counter
from dataclasses import dataclass
from pathlib import Path
from urllib.parse import unquote


TOOL_DIR = Path(__file__).resolve().parent
DEFAULT_ROOT = TOOL_DIR.parent
DEFAULT_INI = TOOL_DIR / "validator.ini"
DEFAULT_TEST_DIR = TOOL_DIR / "legacy_test"
DEFAULT_BACKUP_DIR = TOOL_DIR / "legacy_backup"

UID_LINE_RE = re.compile(
    r"^\*\*\* UID:(?P<uid>[A-Z0-9]{6}) \| DO NOT MODIFY OR REMOVE!!! \*\*\*$"
)
INLINE_LINK_RE = re.compile(
    r"(?<!\!)\[(?P<label>[^\]\r\n]+)\]\((?P<target>[^)\r\n]+\.md(?:#[^) \r\n]+)?)\)"
)
GENERATED_UID_PREFIX_RE = re.compile(r"\[UID:[A-Z0-9]{6}\]$")


@dataclass(frozen=True)
class LinkHit:
    source: Path
    line_no: int
    label: str
    target_text: str
    target_path: Path
    uid: str | None
    status: str


def load_config(path: Path) -> configparser.ConfigParser:
    config = configparser.ConfigParser()
    config.optionxform = str
    if path.exists():
        config.read(path, encoding="utf-8-sig")
    if "files" not in config:
        config["files"] = {}
    return config


def relative_path(root: Path, path: Path) -> str:
    try:
        return path.resolve().relative_to(root.resolve()).as_posix()
    except ValueError:
        return path.resolve().as_posix()


def by_directories(root: Path) -> list[Path]:
    return sorted(
        path for path in root.iterdir()
        if path.is_dir() and path.name.startswith("by-")
    )


def is_under_by_directory(root: Path, path: Path) -> bool:
    try:
        relative = path.resolve().relative_to(root.resolve())
    except ValueError:
        return False
    return len(relative.parts) > 1 and relative.parts[0].startswith("by-")


def source_markdown_files(root: Path, include_root_docs: bool) -> list[Path]:
    files: list[Path] = []
    for directory in by_directories(root):
        files.extend(path for path in directory.rglob("*.md") if path.is_file())
    if include_root_docs:
        files.extend(path for path in root.glob("*.md") if path.is_file())
    return sorted(set(files))


def target_uid_map(root: Path, config: configparser.ConfigParser) -> dict[Path, str]:
    result: dict[Path, str] = {}
    for uid, stored_path in config["files"].items():
        path = Path(stored_path)
        if not path.is_absolute():
            path = root / path
        if is_under_by_directory(root, path):
            result[path.resolve()] = uid
    return result


def write_text_atomic(path: Path, text: str) -> None:
    with tempfile.NamedTemporaryFile(
        "w", encoding="utf-8", newline="", delete=False, dir=str(path.parent)
    ) as tmp:
        tmp.write(text)
        tmp_name = tmp.name
    os.replace(tmp_name, path)


def strip_fragment(target: str) -> tuple[str, str]:
    if "#" not in target:
        return target, ""
    path_part, fragment = target.split("#", 1)
    return path_part, "#" + fragment


def resolve_target(source: Path, target_text: str) -> Path:
    path_part, _fragment = strip_fragment(target_text)
    path_part = unquote(path_part).replace("/", "\\")
    target = Path(path_part)
    if not target.is_absolute():
        target = source.parent / target
    return target.resolve()


def is_fence_line(line: str) -> bool:
    stripped = line.lstrip()
    return stripped.startswith("```") or stripped.startswith("~~~")


def is_generated_uid_link(line: str, match_start: int) -> bool:
    return GENERATED_UID_PREFIX_RE.search(line[:match_start]) is not None


def scan_file(root: Path, source: Path, uid_by_path: dict[Path, str]) -> list[LinkHit]:
    hits: list[LinkHit] = []
    try:
        lines = source.read_text(encoding="utf-8-sig").splitlines()
    except UnicodeDecodeError:
        return hits

    in_fence = False
    for line_no, line in enumerate(lines, start=1):
        if is_fence_line(line):
            in_fence = not in_fence
            continue
        if in_fence:
            continue
        for match in INLINE_LINK_RE.finditer(line):
            if is_generated_uid_link(line, match.start()):
                continue
            label = match.group("label")
            target_text = match.group("target")
            if label.startswith("UID:"):
                continue

            try:
                target_path = resolve_target(source, target_text)
            except OSError:
                continue

            if not is_under_by_directory(root, target_path):
                continue

            uid = uid_by_path.get(target_path)
            if target_path.exists() and uid:
                status = "convertible"
            elif target_path.exists():
                status = "missing_uid"
            else:
                status = "missing_target"
            hits.append(LinkHit(source, line_no, label, target_text, target_path, uid, status))
    return hits


def proposed_reference(hit: LinkHit) -> str:
    if not hit.uid:
        return "<no UID>"
    suffix = ""
    _path_part, fragment = strip_fragment(hit.target_text)
    if fragment:
        suffix = f" {fragment}"
    return f"[UID:{hit.uid}] {hit.label}{suffix}"


def generated_reference(root: Path, hit: LinkHit, source_path: Path) -> str:
    if not hit.uid:
        return f"[{hit.label}]({hit.target_text})"
    try:
        relative_text = hit.target_path.resolve().relative_to(root.resolve()).as_posix()
    except ValueError:
        relative_text = os.path.relpath(
            hit.target_path.resolve(), source_path.resolve().parent
        ).replace("\\", "/")
    _path_part, fragment = strip_fragment(hit.target_text)
    if fragment:
        relative_text += fragment
    return f"[UID:{hit.uid}][{hit.target_path.stem}]({relative_text})"


def convert_file_text(root: Path, source: Path, uid_by_path: dict[Path, str]) -> tuple[str, list[LinkHit]]:
    text = source.read_text(encoding="utf-8-sig")
    hits: list[LinkHit] = []
    in_fence = False

    def replace_line(line: str, line_no: int) -> str:
        def replace(match: re.Match[str]) -> str:
            label = match.group("label")
            target_text = match.group("target")
            if is_generated_uid_link(line, match.start()):
                return match.group(0)
            if label.startswith("UID:"):
                return match.group(0)
            try:
                target_path = resolve_target(source, target_text)
            except OSError:
                return match.group(0)
            if not is_under_by_directory(root, target_path):
                return match.group(0)
            uid = uid_by_path.get(target_path)
            if not target_path.exists() or not uid:
                return match.group(0)
            hit = LinkHit(source, line_no, label, target_text, target_path, uid, "convertible")
            hits.append(hit)
            return generated_reference(root, hit, source)

        return INLINE_LINK_RE.sub(replace, line)

    output_lines: list[str] = []
    for line_no, line in enumerate(text.splitlines(keepends=True), start=1):
        if is_fence_line(line):
            in_fence = not in_fence
            output_lines.append(line)
            continue
        if in_fence:
            output_lines.append(line)
            continue
        output_lines.append(replace_line(line, line_no))

    return "".join(output_lines), hits


def convert_all_files(
    root: Path,
    sources: list[Path],
    uid_by_path: dict[Path, str],
    backup_root: Path,
    apply: bool,
) -> tuple[int, int, Path | None]:
    changed_files = 0
    converted_links = 0
    actual_backup_root: Path | None = None
    if apply:
        timestamp = _dt.datetime.now().strftime("%Y%m%d-%H%M%S")
        actual_backup_root = backup_root.resolve() / timestamp

    for source in sources:
        original = source.read_text(encoding="utf-8-sig")
        converted, hits = convert_file_text(root, source, uid_by_path)
        if converted == original:
            continue
        changed_files += 1
        converted_links += len(hits)
        if apply:
            assert actual_backup_root is not None
            relative_source = source.resolve().relative_to(root.resolve())
            backup_path = actual_backup_root / relative_source
            backup_path.parent.mkdir(parents=True, exist_ok=True)
            shutil.copy2(source, backup_path)
            write_text_atomic(source, converted)

    return changed_files, converted_links, actual_backup_root


def target_syntax(target_text: str) -> str:
    path_part, fragment = strip_fragment(target_text)
    fragment_suffix = " + fragment" if fragment else ""
    normalized = path_part.replace("\\", "/")
    if re.match(r"^[A-Za-z]:/", normalized):
        return "absolute path" + fragment_suffix
    if normalized.startswith("../"):
        return "../ relative" + fragment_suffix
    if normalized.startswith("./"):
        return "./ relative" + fragment_suffix
    if "/" in normalized:
        return "subpath relative" + fragment_suffix
    return "same-directory relative" + fragment_suffix


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--root", type=Path, default=DEFAULT_ROOT)
    parser.add_argument("--ini", type=Path, default=DEFAULT_INI)
    parser.add_argument("--include-root-docs", action="store_true")
    parser.add_argument("--limit", type=int, default=80, help="maximum detail rows to print")
    parser.add_argument("--status", choices=("all", "convertible", "missing_uid", "missing_target"), default="all")
    parser.add_argument("--test-file", type=Path, help="write converted copy of one file under tools/legacy_test")
    parser.add_argument("--test-dir", type=Path, default=DEFAULT_TEST_DIR)
    parser.add_argument("--apply", action="store_true", help="convert all scoped legacy links in place")
    parser.add_argument("--backup-dir", type=Path, default=DEFAULT_BACKUP_DIR)
    args = parser.parse_args()

    root = args.root.resolve()
    config = load_config(args.ini.resolve())
    uid_by_path = target_uid_map(root, config)

    if args.test_file:
        source = args.test_file.resolve()
        if not source.exists():
            raise SystemExit(f"test file not found: {source}")
        if not source.suffix.lower() == ".md":
            raise SystemExit(f"test file is not Markdown: {source}")
        if not is_under_by_directory(root, source):
            raise SystemExit(f"test file is outside direct by-* folders: {source}")

        converted, hits = convert_file_text(root, source, uid_by_path)
        relative_source = source.relative_to(root)
        output = (args.test_dir.resolve() / relative_source)
        output.parent.mkdir(parents=True, exist_ok=True)
        output.write_text(converted, encoding="utf-8")

        print(f"root: {root}")
        print(f"source: {source}")
        print(f"output: {output}")
        print("mode: test-file converted copy only")
        print(f"converted links: {len(hits)}")
        for hit in hits[:args.limit]:
            print(
                f"convertible    {hit.uid} "
                f"{relative_path(root, hit.source)}:{hit.line_no} "
                f"[{hit.label}]({hit.target_text}) -> {generated_reference(root, hit, source)}"
            )
        return 0

    sources = source_markdown_files(root, args.include_root_docs)
    if args.apply:
        changed_files, converted_links, backup_root = convert_all_files(
            root, sources, uid_by_path, args.backup_dir, apply=True
        )
        print(f"root: {root}")
        print(f"ini: {args.ini.resolve()}")
        print(f"source scope: direct by-* folders{' plus root docs' if args.include_root_docs else ''}")
        print("mode: apply")
        print(f"changed files: {changed_files}")
        print(f"converted links: {converted_links}")
        print(f"backup root: {backup_root}")
        return 0

    hits: list[LinkHit] = []
    for source in sources:
        hits.extend(scan_file(root, source, uid_by_path))

    if args.status != "all":
        hits = [hit for hit in hits if hit.status == args.status]

    status_counts = Counter(hit.status for hit in hits)
    syntax_counts = Counter(target_syntax(hit.target_text) for hit in hits)
    source_counts = Counter(relative_path(root, hit.source) for hit in hits)
    target_counts = Counter(relative_path(root, hit.target_path) for hit in hits)

    print(f"root: {root}")
    print(f"ini: {args.ini.resolve()}")
    print(f"source scope: direct by-* folders{' plus root docs' if args.include_root_docs else ''}")
    print("mode: dry-run/report-only")
    print(f"legacy by-* md links found: {len(hits)}")
    for status, count in sorted(status_counts.items()):
        print(f"{status}: {count}")
    print(f"sources with hits: {len(source_counts)}")
    print(f"targets with hits: {len(target_counts)}")

    print()
    print("target syntax patterns:")
    for syntax, count in syntax_counts.most_common():
        print(f"  {count:5d} {syntax}")

    print()
    print("top source files:")
    for source, count in source_counts.most_common(15):
        print(f"  {count:5d} {source}")

    print()
    print("top target files:")
    for target, count in target_counts.most_common(15):
        print(f"  {count:5d} {target}")

    print()
    print(f"details (first {args.limit}):")
    for hit in hits[:args.limit]:
        uid = hit.uid or "------"
        print(
            f"{hit.status:14} {uid} "
            f"{relative_path(root, hit.source)}:{hit.line_no} "
            f"[{hit.label}]({hit.target_text}) -> {proposed_reference(hit)}"
        )

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
