# memory_ranges.py

`memory_ranges.py` builds a by-memory coverage report from Markdown filenames in
`../by-memory` and settings in `memory_ranges.data`.

Default report:

```powershell
python memory_ranges.py
python memory_ranges.py report
```

The report is written to:

```text
../auto-generated/by-memory-tool-report.md
```

Dry-run report output is available for migration testing:

```powershell
python memory_ranges.py report --dry-run
python memory_ranges.py report --dry-run --use-existing-dryrun
```

Dry-run mode writes `../auto-generated/by-memory-tool-report.md.dryrun`. With
`--use-existing-dryrun`, the tool prefers existing `*.md.dryrun` inputs so a
migration can be tested repeatedly without regenerating every source dry-run
file from the originals.

## Coverage Model

The tool treats range filenames as half-open memory ranges:

```text
0xSTART-0xEND.Name.md
```

It splits the configured binary range at every parsed filename/manual range
boundary. Any interval with no covering file/manual range becomes `UNCOVERED`.

This is map coverage from filenames and settings, not proof of final byte-level
audit quality. The tool does not read binary bytes and does not query IDA/MCP;
doing that belongs in a separate targeted audit. Broad section-container pages
count as coverage.

## Reconstruction Metadata Read By This Tool

For each `by-memory/*.md` page, the report reads the validator-managed header
fields used by the current reconstruction system:

- `CANONICAL_OWNER`: semantic documentation ownership. `NONE` means the page is
  currently `no-owner` for ownership tracking. This field does not route or
  emit generated C++.
- `RECONSTRUCTABLE`: whether the range is confirmed source that should be
  represented in the rebuilt project.
- `EMITTER_UIDS`: comma-separated generated-output routing targets. A
  reconstructable range with one or more emitters is counted as `emits`; a
  reconstructable range without emitters is counted as `non-emits`.
- `RECONSTRUCTION_CPP CODE`: implementation/source-definition content used by
  the existing `has reconstruction code` metric.
- `RECONSTRUCTION_H CODE`: declaration/header content reported separately as
  `has reconstruction header code`.

`memory_ranges.py` keeps legacy `AUTOGEN_PARENT_UID` fallback parsing only so
old pre-migration files or temporary migration artifacts can still be read. New
documentation should use `CANONICAL_OWNER` and `EMITTER_UIDS`. If old notes or
research mention `AUTOGEN_PARENT_UID`, interpret it as `CANONICAL_OWNER` for
ownership claims and as `EMITTER_UIDS` only when the old text is discussing
generated output routing.

The generated memory-range report includes byte totals for `no-owner`,
`emits`, `non-emits`, `multiple-emitters`, `has reconstruction code`, `no
reconstruction code yet`, `has reconstruction header code`, and `no
reconstruction header code yet`. These are byte-coverage summaries over parsed memory
ranges, not final source-quality judgments.

The existing reconstruction-code percentage remains CPP implementation
coverage. Header declarations are shown separately and do not make an item
implementation-coded. The report does not decide whether either source channel
is ready. Use the active gate in `../by-structure.md`:
final-output C++ may be entered only when the item is `RECONSTRUCTABLE:TRUE`,
has one or more confirmed nonblank `EMITTER_UIDS` that surface to valid
generated source output without a dead-end, and `(COMPLETION + CONFIDENCE) / 2
> 85`. Older page text that says `90/90` or `95/95` describes previous
code-entry thresholds; `95+` now remains a rare final-audit score, not a
prerequisite for entering final-quality reconstruction code.

## Settings

Settings live in `memory_ranges.data`, which is JSON despite the `.data` suffix.

Important fields:

- `binary_range`: configured address range for coverage math.
- `largest_ranges_limit`: number of largest leaf ranges to show.
- `file_classifications`: file-level manual classifications written by commands.
- `manual_ranges`: manual range classifications written by commands.
- `ignored_crossings`: exact parent/crossing barrier pairs suppressed by `mark-as-ignored`.
- `not_reconstructable_types`: built-in Not-Reconstructable type names.
- `advanced_scan.run_by_default`: when true, `python memory_ranges.py` runs the advanced scan.
- `advanced_scan.ignore_section_heading_patterns`: sections ignored by filename/content checks.
- `advanced_scan.generated_name_patterns`: generated/decompiler filename patterns.

## Advanced Scan

One-off run:

```powershell
python memory_ranges.py report -advanced-scan
python memory_ranges.py -advanced-scan
```

Toggle default behavior:

```powershell
python memory_ranges.py toggle-advanced-scan-default
```

When enabled, normal report generation runs `Advanced-Error-Scan` without flags.
The generated report states both the configured default and whether the current
report run executed the advanced scan.

Advanced-scan findings are review candidates, not definitive failures. Current
checks include:

- filename start/end addresses and filename label text that may not appear in
  the Markdown document body, ignoring configured change/update sections;
- reconstructable filenames that appear to contain generated/decompiler names
  such as `sub_`, `func_`, `dword_`, `DAT_`, `field_`, or similar configured
  patterns.

The advanced scan reads Markdown text only. It does not read binary bytes and
does not query IDA/MCP.

## Classification Commands

List built-in Not-Reconstructable types:

```powershell
python memory_ranges.py list-not-reconstructable-types
```

Mark Not-Reconstructable with a built-in or custom type:

```powershell
python memory_ranges.py mark-not-reconstructable-file <file.md> <type>
python memory_ranges.py mark-not-reconstructable-range 0xSTART 0xEND <type> --file <file.md> --label <label>
```

Not-Reconstructable commands validate that the linked by-memory file header is
actually `RECONSTRUCTABLE:FALSE`. Manual Not-Reconstructable ranges must also
be contained by the linked file's filename range.

Mark padding/zero-filled or other:

```powershell
python memory_ranges.py mark-padding-file <file.md>
python memory_ranges.py mark-padding-range 0xSTART 0xEND --label <label>
python memory_ranges.py mark-other-file <file.md>
python memory_ranges.py mark-other-range 0xSTART 0xEND --label <label>
```

Only Not-Reconstructable entries can have types/subtypes.

Manual range commands reject overlaps with existing manual ranges. If
`manual_ranges` is edited by hand and overlaps are introduced, the report lists
them under `General-Errors`.

Remove manual settings:

```powershell
python memory_ranges.py remove-file <file.md>
python memory_ranges.py remove-range 0xSTART 0xEND
```

## Barrier Crossing Ignores

If a barrier crossing is intentional, mark the exact current crossing as ignored:

```powershell
python memory_ranges.py mark-as-ignored 0xPARENT_START-0xPARENT_END 0xCROSSING_START-0xCROSSING_END <50+ char reason>
```

The command validates that both ranges exist and that the pair is currently
reported as a barrier crossing in that parent/crossing order. The reason is
required and must be at least 50 characters so the report records a meaningful
justification. The generated report moves the item from `Barrier Crossings
Errors` to `Ignored-Crossings` and records the reason.

Ignores are tied only to the numeric ranges in the filenames/manual range
records. If either range changes, the ignore no longer matches and the crossing
returns to the normal error list.

## Binary Range

Update the configured binary range:

```powershell
python memory_ranges.py set-binary-range 0xSTART 0xEND
```

The default end semantics are exclusive. You can pass `--end-semantics inclusive`
when the supplied end address should be stored as inclusive.
