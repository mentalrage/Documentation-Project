*** UID:0000UX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LoadFrameDrawRecord 0x004D1600

## Status

- Confidence: strong for behavior and range, medium for final structure names.
- Entity kind: shared global helper.
- Current Wave3 owner file: `LoadFrameDrawRecord_004D1600.cpp`
- Likely source module: [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- Exact range: `0x004d1600-0x004d165d`
- Canonical memory page: [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md)
- Evidence basis: generated recovered source and Wave3 global summary as leads, with IDA MCP boundary/caller/callee/xref/decompile/disassembly checks through 2026-06-03.

## Behavior

`LoadFrameDrawRecord_4D1600` extracts draw metrics for one frame from a loaded frame metadata table.

If `frameIndex` is out of range, it clears at least the output image id and baseline fields. Otherwise it reads one 0x18-byte frame-table record and fills an output draw record with:

- image/payload id or pointer value from record field `+0x10`;
- frame width from `right - left`;
- left/top/right/bottom bounds;
- baseline or payload-end field from record `+0x14`;
- payload span or vertical extent from the following boundary record's `+0x10` field minus the current record's `+0x14`.

The generated output type still contains synthetic reserved fields, so the final table/output type names and exact field names should be reviewed before source migration.

## Caller Evidence

IDA MCP reports ten caller functions:

- `0x004d1a20` map-tile draw path.
- `0x004dd2c0`, `0x004de190` static/effect image draw paths, including [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md).
- `0x004e0d70`, `0x004e21d0`, `0x004e2eb0`, `0x004e4210`, `0x004e4280` item/new-human/sprite draw paths.
- `0x004ff7d0` UI/effect frame user.
- `0x0055b5d0` [UID:0000FZ][WaterFilterEffecter](by-class/WaterFilterEffecter.md) caustic-frame update path.

IDA MCP reports no project callees for this helper; it is a pure table read/record projection.

IDA MCP recheck on 2026-05-31 confirms `sub_4D1600` starts at `0x004d1600`, ends half-open at `0x004d165d`, has no project callees, and decompiles as a bounds check plus fixed record projection. The same recheck found many raw entry references beyond the ten high-level caller functions listed above, including references in ranges that IDA has not modeled as functions. Treat caller inventory as incomplete until those references are triaged.

IDA MCP recheck on 2026-06-03 confirms the same modeled helper at `0x004d1600` with size `0x5d`, no callees, and twelve modeled call sites across ten functions. `xrefs_to 0x004d1600` also reports many raw code references in the `0x004d51xx-0x004d75xx` bands plus `0x004dcb74` and `0x004e4e21`, so modeled callers are still not the full inventory.

The 2026-06-03 disassembly resolves the prior `entry[10] - entry[5]` question: the helper reads `[record + 0x28] - [record + 0x14]`, i.e. the following 24-byte record's `+0x10` boundary/start field minus the current record's `+0x14` end/baseline field. This matches [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)'s sentinel/boundary-record model. Representative callers such as `0x004ff7d0` consume the output rectangle at `+0x10..+0x1f` and derive dimensions from those bounds, while renderer callbacks receive the whole 0x28-byte draw record.

## Ownership Decision

Place this with [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md), beside `LoadImageFrameTable_4D0F50` and the shared `EPFArchiveMetadataTable` record shape. It is too generic for any one asset image library, and it is not a DAT archive parser.

## Open Questions

- Confirm the output struct layout and whether `imageId` is actually a payload pointer, frame id, or offset.
- Confirm final names for the payload-boundary/span field and the baseline/end field after type cleanup.
- Add a manual Wave3 note/grade after the structure names are cleaned up.

## Cross-References

- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:000176][0x004d0f50-0x004d165d.ImageFrameTable](by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md)
- [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md)

## Changes

- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `50/65` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the table projection helper, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now reflects verified rebuild relevance while staying conservative because output-structure names and the full caller inventory remain open.
  - Evidence: IDA MCP confirms the exact function range, no project callees, the decompiled bounds-check/record-copy behavior, and additional raw entry references that need later caller triage.

- 2026-06-01: Completion/confidence changed from `50/65` to `68/80`.
  - Before: the page relied on the broad aggregate memory range for canonical details.
  - After: the page points to exact memory documentation for `0x004d1600-0x004d165d`.
  - Evidence: [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) records IDA MCP function boundary, caller/callee inventory, the decompiled projection body, confirmed table offsets, and the unresolved `v3[10] - v3[5]` field relation.

- 2026-06-03: Completion/confidence changed from `68/80` to `76/86`.
  - Before: the page still treated the `entry[10] - entry[5]` relation as unresolved and listed only the modeled caller inventory.
  - After: the page records the exact disassembly-level boundary-record read and the broader raw xref inventory while keeping final type names open.
  - Evidence: IDA MCP `lookup_funcs`, `callers`, `callees`, `xrefs_to`, `decompile`, `disasm`, and representative caller decompilation confirm the helper reads `[record + 0x28] - [record + 0x14]`, has no callees, feeds broad render callbacks, and still has raw unmodeled references beyond the formal caller list.
