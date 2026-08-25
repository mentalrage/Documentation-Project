*** UID:0000VA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ResolveSpritePartPath source-body ownership belongs to exact helper [UID:0002VD][0x004e19d0-0x004e1f27.ResolveSpritePartPath](by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md); this item page does not emit a duplicate helper body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ResolveSpritePartPath 0x004E19D0

## Status

- Confidence: strong for behavior and `NewHumanImageLib` ownership; below final-source level for exact helper signature and table/record type names.
- Entity kind: shared global helper.
- Likely source module: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
- Exact range: `0x004e19d0-0x004e1f27` half-open; `0x004e1f26` is the final byte inside the function.
- Owner/emitter route: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).
- Memory range: [UID:0002VD][0x004e19d0-0x004e1f27.ResolveSpritePartPath](by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md).
- Rebuild handling: `source-authored` sprite/archive metadata helper. Exact source-body ownership now belongs to [UID:0002VD][0x004e19d0-0x004e1f27.ResolveSpritePartPath](by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md), which carries the accepted first-draft formal C++. This item page is a non-duplicating routing marker and keeps only the formal no-duplicate comment.

## Behavior

`ResolveSpritePartPath` builds an `ArchiveMetadataTable` for a new-human sprite part name. It first probes for numbered archives using `<baseName>0.EPF`; if numbered archives exist, it probes consecutive `<baseName>%d.EPF` shards while incrementing an unsigned-byte shard counter, reads all headers, merges frame records into one metadata table, and appends a sentinel record. If no numbered archive exists, it loads the single `<baseName>.EPF` archive. Current MCP evidence shows no explicit 100-entry cap.

Each record stores normalized bounds plus absolute payload start/end offsets based on the DAT file's mapped payload base.

[UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md) now uses this helper in formal constructor C++ as the source-facing inferred call `ResolveSpritePartPath(part.name)` while constructing `NewHumanPartEntry` rows. [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md) now emits as class-owned `NewHumanImageLib::LoadPartTable` and documents the same helper call shape at `0x004e12fe` in the reusable retained `Part.tbl` loader.

## Evidence

- 2026-06-03 live IDA MCP `lookup_funcs` reports `sub_4E19D0` at `0x004e19d0`, size `0x557`, with half-open end `0x004e1f27`; `0x004e1f26` is inside the function and `0x004e1f27` is not a function.
- 2026-06-03 live IDA MCP caller checks report exactly two direct code references: `0x004e00f0` inside `sub_4DFD10` and `0x004e12fe` inside `sub_4E11B0`, both in the `NewHumanImageLib` family.
- 2026-06-03 live IDA MCP decompile shows the numbered probe path using `L"%s%d.EPF"`, the fallback path using `L"%s.EPF"`, DATFile-backed archive reads, 12-byte table headers, 24-byte records, rectangle normalization, payload-offset rebasing, terminal sentinels, and temporary reader cleanup.
- 2026-07-01 MCP revision evidence from session `supervisor_resume_20260629` reconfirms `sub_4E19D0` size `0x557`, `0x004e1f27` as non-function end, exactly two same-family callers, and numbered-shard probing via an unsigned-byte counter with no explicit fixed 100-shard limit.
- 2026-06-03 live IDA MCP `callees` includes [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), DATFile construction/destruction and vtable access, path formatting, allocation/free helpers, `DATFile::GetDataPointer` style payload-base access, rectangle normalization at `0x004b7c50`, and stack-cookie checking.
- 2026-06-03 IDA Python inspection confirms UTF-16 data refs to `L"%s%d.EPF"` at `0x0061b850` and `L"%s.EPF"` at `0x0061c348`, plus tail `retn 4` followed by `0xcc` padding.

## Ownership Decision

This helper is too specific to new-human part archives to live in raw DAT archive code. Keep it with [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). A later shared render/image metadata helper is possible only if sibling archive builders are consolidated, but the direct caller set currently supports `NewHumanImageLib.cpp` ownership.

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md)
- [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md)
- [UID:0002VD][0x004e19d0-0x004e1f27.ResolveSpritePartPath](by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md)
- [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md)
- [UID:00017R][0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster](by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)

## Changes

- 2026-07-01 B011 empty-emitter implementation: raised this item marker to `87/91`, filled the formal block with the accepted no-duplicate comment, pointed source-body ownership to [UID:0002VD][0x004e19d0-0x004e1f27.ResolveSpritePartPath](by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md), and corrected stale fixed-100-shard wording to the current unsigned-byte consecutive-shard evidence.
- 2026-06-30 B007 LoadPartTable implementation sync:
  - Score unchanged.
  - Updated call-site wording to state that [UID:00041B][0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable](by-memory/0x004e11b0-0x004e13a7.NewHumanImageLibLoadPartTable.md) is now a class-owned/emitting loader and still calls this resolver at `0x004e12fe`.
  - Evidence: current MCP in B007 reported exactly two direct code references to `0x004e19d0`: constructor call `0x004e00f0` and UID00041B call `0x004e12fe`; resolver ownership/C++ stays unchanged because helper-specific archive-table names remain below final implementation quality.
- 2026-06-25 B011 constructor implementation sync:
  - Score unchanged.
  - Replaced stale autogen-parent and old-gate wording with the current owner/emitter route and helper-specific no-code rationale, and linked the accepted constructor call site.
  - Evidence: [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md) now calls `ResolveSpritePartPath(part.name)`; helper C++ remains outside this callback because archive-table/DAT-wrapper/internal record names are not finalized for a standalone helper body.
- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page was marked reconstructable with moderate completion and strong confidence; the 2026-07-01 callback later replaced the blank state with a no-duplicate marker comment and moved the source body to [UID:0002VD][0x004e19d0-0x004e1f27.ResolveSpritePartPath](by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md).
- Summary and evidence: IDA MCP verification on 2026-05-31 confirmed the exact function boundary, two caller sites, DAT/archive helper callees, and EPF filename-format strings. The score remains below 95 because final source ownership and internal `ArchiveMetadataTable` field naming still require a full audit.
- 2026-06-03: Raised from `70/85` to `86/90` and attached to the NewHumanImageLib source route.
  - Before: the page had high-level behavior and older IDA notes, but it still had generated/Wave provenance, no exact by-memory child page, no parent attachment, and no current call-site/data-ref detail.
  - After: live IDA MCP confirms the exact `0x004e19d0-0x004e1f27` half-open range, two same-family direct callers, no external owner callers, numbered/single EPF literals, DAT/HasDATEntry/archive-table callee set, decompiled table merge behavior, sentinel handling, cleanup, and padding. The new [UID:0002VD][0x004e19d0-0x004e1f27.ResolveSpritePartPath](by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md) child page records the exact memory split.
  - Superseded gap: final reconstruction C++ was blank at the time because exact source signature, helper name, and archive-table type names were below helper-specific implementation quality; the 2026-07-01 callback resolved the helper body on [UID:0002VD][0x004e19d0-0x004e1f27.ResolveSpritePartPath](by-memory/0x004e19d0-0x004e1f27.ResolveSpritePartPath.md) and keeps this item page marker-only.
