*** UID:0000VA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ResolveSpritePartPath 0x004E19D0

## Status

- Confidence: strong for behavior and `NewHumanImageLib` ownership; below final-source level for exact helper signature and table/record type names.
- Entity kind: shared global helper.
- Likely source module: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
- Exact range: `0x004e19d0-0x004e1f27` half-open; `0x004e1f26` is the final byte inside the function.
- Autogen parent: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
- Memory range: [UID:0002VD][0x004e19d0-0x004e1f27.ResolveSpritePartPath](by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md).
- Rebuild handling: `source-authored` sprite/archive metadata helper. It should be rebuilt, but final C++ is blank until the helper's signature and internal record/table types reach the `95/95` gate.

## Behavior

`ResolveSpritePartPath` builds an `ArchiveMetadataTable` for a new-human sprite part name. It first probes for numbered archives using `<baseName>0.EPF`; if numbered archives exist, it scans `<baseName>%d.EPF` up to 100 shards, reads all headers, merges frame records into one metadata table, and appends a sentinel record. If no numbered archive exists, it loads the single `<baseName>.EPF` archive.

Each record stores normalized bounds plus absolute payload start/end offsets based on the DAT file's mapped payload base.

## Evidence

- 2026-06-03 live IDA MCP `lookup_funcs` reports `sub_4E19D0` at `0x004e19d0`, size `0x557`, with half-open end `0x004e1f27`; `0x004e1f26` is inside the function and `0x004e1f27` is not a function.
- 2026-06-03 live IDA MCP caller checks report exactly two direct code references: `0x004e00f0` inside `sub_4DFD10` and `0x004e12fe` inside `sub_4E11B0`, both in the `NewHumanImageLib` family.
- 2026-06-03 live IDA MCP decompile shows the numbered probe path using `L"%s%d.EPF"`, the fallback path using `L"%s.EPF"`, DATFile-backed archive reads, 12-byte table headers, 24-byte records, rectangle normalization, payload-offset rebasing, terminal sentinels, and temporary reader cleanup.
- 2026-06-03 live IDA MCP `callees` includes [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), DATFile construction/destruction and vtable access, path formatting, allocation/free helpers, `DATFile::GetDataPointer` style payload-base access, rectangle normalization at `0x004b7c50`, and stack-cookie checking.
- 2026-06-03 IDA Python inspection confirms UTF-16 data refs to `L"%s%d.EPF"` at `0x0061b850` and `L"%s.EPF"` at `0x0061c348`, plus tail `retn 4` followed by `0xcc` padding.

## Ownership Decision

This helper is too specific to new-human part archives to live in raw DAT archive code. Keep it with [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). A later shared render/image metadata helper is possible only if sibling archive builders are consolidated, but the direct caller set currently supports `NewHumanImageLib.cpp` ownership.

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md)
- [UID:0002VD][0x004e19d0-0x004e1f27.ResolveSpritePartPath](by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md)
- [UID:00017R][0x004dfd10-0x004e68a8.NewHumanImageLib](by-memory/0x004dfd10-0x004e68a8.NewHumanImageLib.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 confirmed the exact function boundary, two caller sites, DAT/archive helper callees, and EPF filename-format strings. The score remains below 95 because final source ownership and internal `ArchiveMetadataTable` field naming still require a full audit.
- 2026-06-03: Raised from `70/85` to `86/90` and attached `AUTOGEN_PARENT_UID:0000LR`.
  - Before: the page had high-level behavior and older IDA notes, but it still had generated/Wave provenance, no exact by-memory child page, no parent attachment, and no current call-site/data-ref detail.
  - After: live IDA MCP confirms the exact `0x004e19d0-0x004e1f27` half-open range, two same-family direct callers, no external owner callers, numbered/single EPF literals, DAT/HasDATEntry/archive-table callee set, decompiled table merge behavior, sentinel handling, cleanup, and padding. The new [UID:0002VD][0x004e19d0-0x004e1f27.ResolveSpritePartPath](by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md) child page records the exact memory split.
  - Remaining gap: final reconstruction C++ stays blank because exact source signature, helper name, and archive-table type names remain below the `95/95` threshold.
