*** UID:0001V3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct MapTileRecord
{
    unsigned short paletteIndex;
    unsigned char allowPaletteFilter;
    unsigned char reserved;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MapTileRecord

## Status

- Entity kind: small resource-derived struct.
- Confidence: strong for size, bit unpacking, source route, and accepted source-facing type/field names.
- Owner: [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md), emitted through [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md).
- Owner/emitter route: attached to [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md), currently `85/85`, and emitted through [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md), currently `86/85`.
- Evidence basis: IDA MCP decompile checks for [UID:0002IZ][0x004d1860-0x004d199e.MapTileImageLibConstructor](by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md) and [UID:0002J0][0x004d1a20-0x004d1b72.MapTileImageLibDrawTile](by-memory/0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md).

## Layout

```text
MapTileRecord
  +0x00  uint16 paletteIndex
  +0x02  uint8  allowPaletteFilter
  +0x03  uint8  reserved/padding
```

Observed size is `4` bytes.

## Resource Decode

`MapTileImageLib::MapTileImageLib` reads one 16-bit packed value per tile from `TILE.TBL`:

- low 15 bits become `paletteIndex`;
- high bit becomes `allowPaletteFilter`.
- byte `+0x03` is not explicitly initialized by the observed constructor and should remain padding/reserved until source evidence proves otherwise.

`MapTileImageLib::DrawTile` uses this record after resolving the terrain tile id. If the palette filter is enabled through [UID:0000MB][PaletteLib](by-file/PaletteLib.md), the high-bit flag must be set for the tile to draw; otherwise the tile draw is skipped. When drawing proceeds, the low 15-bit field is passed to `PaletteLib::GetSlotPalette` to select the actual palette slot used by the low-level tile blitter.

The 2026-06-19 B015 aggregate pass adds no new record fields, but it keeps the source route explicit: [UID:0002IZ][0x004d1860-0x004d199e.MapTileImageLibConstructor](by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md) decodes the four-byte records from `TILE.TBL`, and [UID:0002J0][0x004d1a20-0x004d1b72.MapTileImageLibDrawTile](by-memory/0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md) is the active consumer of `paletteIndex` and `allowPaletteFilter`. [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md) is only an index over those children and should not emit a duplicate record definition.

## IDA Evidence

- 2026-06-14 live IDA MCP in session `a001_goal2_class_batch` reports `MapTileImageLib` constructor `0x004d1860` size `0x13e` and draw helper `0x004d1a20` size `0x152`; the documented half-open endpoints `0x004d199e` and `0x004d1b72` are not function starts.
- Live decompilation of `0x004d1860` opens `TILE.EPF`, then `TILE.TBL`, reads a four-byte count with `sub_49C310(&v7, 4)`, validates that count against the EPF header word, allocates `4 * count` bytes at object `+0x08`, and loops over two-byte packed tile records.
- In the constructor loop, each packed word read by `sub_49C310(&v8, 2)` writes `(v8 < 0)` to record byte `+0x02` and `(v8 & 0x7fff)` to record word `+0x00`. No write to byte `+0x03` appears in the live decompilation.
- Live decompilation of `0x004d1a20` reads `v6[2][2 * tileId]` for `paletteIndex` and `LOBYTE(v6[2][2 * tileId + 1])` for `allowPaletteFilter`, passes the low word to `sub_543E40(0, value, 0)`, and skips drawing when the palette-filter gate is enabled and the flag byte is clear.
- Live `xrefs_to` confirms constructor use from startup `0x004f6055` and draw helper calls from map/tile render paths at `0x00424441`, `0x0050d984`, and `0x005497d0`, plus one raw/unmodeled caller site at `0x0050c3d7`.

## Score Rationale

- Completion is raised to `88` because the page now records current function bounds, constructor resource validation, packed-word decode details, draw-path field reads, caller xrefs, current owner/emitter route, padding caveat, and accepted formal `MapTileRecord` definition.
- Confidence is raised to `91` because live constructor and draw decompilation independently agree on the 4-byte stride, low 15-bit palette-index field, high-bit palette-filter flag, and unused padding byte. It stays below final-audit levels because exact original type spelling remains provisional.

## Cross-References

- [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md)
- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md)
- [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)

## Changes

- 2026-07-01 B011 empty-emitter-family implementation:
  - Raised from `85/90` to `88/91` and inserted the accepted `struct MapTileRecord` formal block.
  - Preserved `reserved` as unwritten padding: constructor evidence writes only the word at `+0x00` and flag byte at `+0x02`, and the formal struct must not imply constructor initialization of byte `+0x03`.
- 2026-06-17 B003 source-quality support update:
  - Standardized the low 15-bit field name from `paletteOrFrameIndex` to `paletteIndex` because `DrawTile` uses the requested tile id for frame lookup and passes this field to the palette lookup helper.
  - Kept `allowPaletteFilter` for the high bit because the only observed consumer is the render palette-filter gate; rejected collision/walkability/gameplay interpretations.
  - Kept score unchanged at `85/90`; B003's evidence improves source-facing names but does not add a new independent final-audit proof of original type spelling.
- 2026-06-19 B015 aggregate support sync:
  - Score unchanged. Added that B015's aggregate/index audit does not alter the four-byte record layout and keeps constructor/draw child pages as the authoritative producer/consumer evidence.
  - Evidence: B015 raw PE range work confirms [UID:000177][0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster](by-memory/0x004d1860-0x004d1f30.MapTileImageLibLocalMethodCluster.md) is non-emitting, so this type should be emitted through MapTileImageLib class/file support rather than through the aggregate.
- 2026-06-06 A004 parent-gate sync: moved `AUTOGEN_PARENT_UID` from [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md) to [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md) after the class page was refreshed to `84/84` and attached to the file root. Scores remain `82/88`; this is a parent metadata cleanup.
- 2026-06-06: Attached the decoded tile row to [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md). Scores remain `82/88`; the record is file-owned resource-derived state rather than a standalone class.
- Completion/confidence metadata: existed before as `0/0`; changed to `82/88`. Summary: the record size, packed `TILE.TBL` decode, palette-filter flag, draw-path usage, and padding caveat are now IDA-backed. Evidence: constructor writes `(packed & 0x7fff)` at record `+0x00` and `(packed < 0)` at `+0x02`; draw path reads those fields through object `+0x08`.
- Reconstructable metadata: existed before as blank; changed to `TRUE`. Historical note: older wording left C++ blank below the `95+` gate; B011's 2026-07-01 callback supersedes that with the accepted source-facing POD struct while keeping exact original spelling caveats documented in history.
- 2026-06-14 A002 Goal2 score pass:
  - Before: `COMPLETION:82`, `CONFIDENCE:88`, stale parent score text, and no dedicated current-session evidence section.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:90`, current owner/emitter wording, current class/file parent scores, and live IDA evidence for constructor/draw bounds, `TILE.TBL` validation, packed-word decode, draw-path field reads, and caller xrefs.
  - Summary/evidence: IDA MCP session `a001_goal2_class_batch` reconfirmed `+0x00` low 15-bit palette/frame storage, `+0x02` high-bit filter flag, and no observed write to `+0x03`. Historical final-C++ blocker was superseded by B011 on 2026-07-01 with the accepted POD struct.
