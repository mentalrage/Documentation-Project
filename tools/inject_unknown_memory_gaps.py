#!/usr/bin/env python3
"""Build the by-memory coverage map with inline UNKNOWN gap rows.

This intentionally uses only the existing coverage-report rows. It does not
query IDA, Wave3, or simroot. It combines covered reconstructable and ignored
range rows into one address-ordered section, then inserts one UNKNOWN row for
each uncovered span between adjacent covered ranges.
"""

from __future__ import annotations

import argparse
import datetime as _dt
import re
import shutil
from dataclasses import dataclass
from pathlib import Path


DEFAULT_REPORT = Path(__file__).resolve().parents[1] / "by-memory" / "-coverage-report.md"

RANGE_ANY_RE = re.compile(r"0x[0-9a-fA-F]+-0x[0-9a-fA-F]+")
POINT_ROW_RE = re.compile(r"^(?P<indent>\s*)- \[(?P<addr>0x[0-9a-fA-F]+)\](?P<tail>.*)$")


@dataclass
class Row:
    line: str
    start: int | None
    end: int | None
    order: int
    generated_unknown: bool = False

    @property
    def is_range(self) -> bool:
        return self.start is not None and self.end is not None and self.end > self.start

    @property
    def is_point(self) -> bool:
        return self.start is not None and self.end == self.start


def detect_newline(text: str) -> str:
    return "\r\n" if "\r\n" in text else "\n"


def parse_row(line: str, order: int) -> Row | None:
    if not line.lstrip().startswith("- "):
        return None

    ranges = []
    for text_range in RANGE_ANY_RE.findall(line):
        start_text, end_text = text_range.split("-", 1)
        start = int(start_text, 16)
        end = int(end_text, 16)
        if end > start:
            ranges.append((start, end))

    if ranges:
        return Row(
            line=line,
            start=min(start for start, _end in ranges),
            end=max(end for _start, end in ranges),
            order=order,
            generated_unknown=("UNKNOWN" in line.upper() or "NOT COVERED" in line.upper()),
        )

    point_match = POINT_ROW_RE.match(line)
    if point_match:
        addr = int(point_match.group("addr"), 16)
        return Row(line=line, start=addr, end=addr, order=order)

    return None


def format_addr(value: int) -> str:
    return f"0x{value:08x}"


def format_unknown_row(start: int, end: int, newline: str) -> str:
    size = end - start
    return (
        f"- [{format_addr(start)}-{format_addr(end)} ({size} bytes) | UNKNOWN] : "
        f"unknown : 0% : open : Range between adjacent documented by-memory rows; "
        f"not manually investigated.{newline}"
    )


def section_name(line: str) -> str | None:
    if not line.startswith("## "):
        return None
    return line[3:].strip()


def is_covered_section(name: str | None) -> bool:
    return name in {
        "Covered Items",
        "Covered Items To Replicate",
        "Covered Items To Ignore",
    }


def split_report(lines: list[str]):
    prefix: list[str] = []
    suffix: list[str] = []
    covered_rows: list[Row] = []
    seen_first_covered = False
    skipping_covered_section = False
    order = 0

    i = 0
    while i < len(lines):
        name = section_name(lines[i])
        if is_covered_section(name):
            if not seen_first_covered:
                seen_first_covered = True
                newline = detect_newline("".join(lines))
                prefix.append("## Covered Items" + newline + newline)
            skipping_covered_section = True
            i += 1
            continue

        if name is not None and skipping_covered_section:
            skipping_covered_section = False

        if skipping_covered_section:
            row = parse_row(lines[i], order)
            order += 1
            if row is not None:
                covered_rows.append(row)
            i += 1
            continue

        if seen_first_covered:
            suffix.append(lines[i])
        else:
            prefix.append(lines[i])
        i += 1

    return prefix, covered_rows, suffix


def sort_rows(rows: list[Row]) -> list[Row]:
    def key(row: Row):
        if row.start is None:
            return (1 << 63, 0, row.order)
        # Longer same-start aggregate rows first; this makes overlapping owners
        # less likely to visually hide their parent range.
        length = 0 if row.end is None else row.end - row.start
        return (row.start, -length, row.order)

    return sorted(rows, key=key)


def build_covered_section(rows: list[Row], newline: str):
    lines: list[str] = []
    current_end: int | None = None
    inserted_unknown: list[tuple[int, int]] = []
    removed_generated = 0

    for row in sort_rows(rows):
        if row.generated_unknown:
            removed_generated += 1
            continue

        if row.is_range:
            assert row.start is not None and row.end is not None
            if current_end is not None and row.start > current_end:
                lines.append(format_unknown_row(current_end, row.start, newline))
                inserted_unknown.append((current_end, row.start))
            lines.append(row.line)
            current_end = row.end if current_end is None else max(current_end, row.end)
        else:
            # Point-only rows are still covered findings, but they do not define
            # enough extent to create or close a memory gap.
            lines.append(row.line)

    if lines and lines[-1].strip():
        lines.append(newline)

    return lines, {
        "removed_generated": removed_generated,
        "inserted_unknown": len(inserted_unknown),
        "first_unknown": inserted_unknown[:10],
    }


def update_summary(text: str) -> str:
    lines = text.splitlines(keepends=True)
    rec_count = 0
    ignored_count = 0
    unknown_count = 0
    uncovered_count = 0

    for line in lines:
        if " : reconstructable : " in line:
            rec_count += 1
        elif " : ignored : " in line:
            ignored_count += 1
        elif " : unknown : " in line:
            unknown_count += 1
        elif " : uncovered : " in line:
            uncovered_count += 1

    updated = []
    for line in lines:
        newline = "\r\n" if line.endswith("\r\n") else "\n"
        if line.startswith("- Coverage summary:"):
            updated.append(
                f"- Coverage summary: {rec_count} reconstructable rows, "
                f"{ignored_count} ignored rows, {unknown_count} unknown gap rows, "
                f"{uncovered_count} uncovered inventory rows.{newline}"
            )
        elif line.startswith("- Gap-row status:"):
            updated.append(
                "- Gap-row status: explicit `UNKNOWN` rows are generated between "
                "adjacent covered by-memory ranges in the single address-ordered "
                "`Covered Items` section. These rows mean the span has not been "
                f"manually investigated yet.{newline}"
            )
        elif line.startswith("- Ordering:"):
            updated.append(
                "- Ordering: `by-memory` covered rows are sorted low-to-high by "
                f"address, with reconstructable, ignored, and unknown rows together.{newline}"
            )
        elif line.startswith("- by-memory EMPTY gap classification"):
            updated.append(
                "- by-memory EMPTY gap classification : uncovered : 0% : open : `UNKNOWN` "
                "rows are not yet classified as `EMPTY`; only convert a row after "
                f"byte/padding verification proves no meaningful data/code exists.{newline}"
            )
        else:
            updated.append(line)
    return "".join(updated)


def validate_unknown_rows(text: str) -> None:
    seen: set[tuple[int, int]] = set()
    for line_no, line in enumerate(text.splitlines(), start=1):
        row = parse_row(line, line_no)
        if row is None or "UNKNOWN" not in line:
            continue
        size_match = re.search(r"\((\d+) bytes\)", line)
        if not size_match:
            raise ValueError(f"UNKNOWN row on line {line_no} is missing byte size")
        assert row.start is not None and row.end is not None
        expected = row.end - row.start
        actual = int(size_match.group(1))
        if expected != actual:
            raise ValueError(
                f"UNKNOWN row on line {line_no} has size {actual}, expected {expected}"
            )
        key = (row.start, row.end)
        if key in seen:
            raise ValueError(f"duplicate UNKNOWN row on line {line_no}: {key}")
        seen.add(key)


def rewrite_report(text: str):
    newline = detect_newline(text)
    lines = text.splitlines(keepends=True)
    prefix, rows, suffix = split_report(lines)
    covered_lines, stats = build_covered_section(rows, newline)
    rewritten = "".join(prefix + covered_lines + suffix)
    rewritten = update_summary(rewritten)
    validate_unknown_rows(rewritten)
    stats["covered_input_rows"] = len(rows)
    return rewritten, stats


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--report", type=Path, default=DEFAULT_REPORT)
    parser.add_argument("--apply", action="store_true", help="write the rewritten report")
    args = parser.parse_args()

    report = args.report.resolve()
    original = report.read_text(encoding="utf-8")
    rewritten, stats = rewrite_report(original)

    print(f"report: {report}")
    print(f"covered input rows: {stats['covered_input_rows']}")
    print(f"removed generated UNKNOWN/NOT COVERED rows: {stats['removed_generated']}")
    print(f"inserted UNKNOWN rows: {stats['inserted_unknown']}")
    if stats["first_unknown"]:
        print("first UNKNOWN rows:")
        for start, end in stats["first_unknown"]:
            print(f"  {format_addr(start)}-{format_addr(end)} ({end - start} bytes)")

    if not args.apply:
        print("dry run only; pass --apply to write changes")
        return 0

    timestamp = _dt.datetime.now().strftime("%Y%m%d-%H%M%S")
    backup = report.with_name(f"{report.name}.bak-{timestamp}")
    shutil.copy2(report, backup)
    report.write_text(rewritten, encoding="utf-8")
    print(f"backup: {backup}")
    print("updated report written")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
