*** UID:0001V3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MapTileRecord

## Status

- Entity kind: small resource-derived struct.
- Confidence: strong for size and bit unpacking; medium for final original type/field names.
- Owner: [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md).
- Evidence basis: IDA MCP decompile checks for [UID:0002IZ][0x004d1860-0x004d199e.MapTileImageLibConstructor](by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md) and [UID:0002J0][0x004d1a20-0x004d1b72.MapTileImageLibDrawTile](by-memory/0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md).

## Layout

```text
MapTileRecord
  +0x00  uint16 paletteOrFrameIndex
  +0x02  uint8  allowPaletteFilter
  +0x03  uint8  reserved/padding
```

Observed size is `4` bytes.

## Resource Decode

`MapTileImageLib::MapTileImageLib` reads one 16-bit packed value per tile from `TILE.TBL`:

- low 15 bits become `paletteOrFrameIndex`;
- high bit becomes `allowPaletteFilter`.
- byte `+0x03` is not explicitly initialized by the observed constructor and should remain padding/reserved until source evidence proves otherwise.

`MapTileImageLib::DrawTile` uses this record after resolving the terrain tile id. If the palette filter is enabled through [UID:0000MB][PaletteLib](by-file/PaletteLib.md), the high-bit flag must be set for the tile to draw; otherwise the tile draw is skipped. When drawing proceeds, the low 15-bit field is passed to `PaletteLib::GetSlotPalette` to select the actual palette slot used by the low-level tile blitter.

## Cross-References

- [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md)
- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md)
- [UID:000177][0x004d1860-0x004e6748.MapTileImageLib](by-memory/0x004d1860-0x004e6748.MapTileImageLib.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)

## Changes

- Completion/confidence metadata: existed before as `0/0`; changed to `82/88`. Summary: the record size, packed `TILE.TBL` decode, palette-filter flag, draw-path usage, and padding caveat are now IDA-backed. Evidence: constructor writes `(packed & 0x7fff)` at record `+0x00` and `(packed < 0)` at `+0x02`; draw path reads those fields through object `+0x08`.
- Reconstructable metadata: existed before as blank; changed to `TRUE`. Summary: this resource-derived record must be represented in rebuilt `MapTileImageLib` state. Parent UID and C++ reconstruction remain blank because final member names and original source shape are below the `95+` final-source gate.
