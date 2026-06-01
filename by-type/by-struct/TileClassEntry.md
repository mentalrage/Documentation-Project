*** UID:0001WC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TileClassEntry

## Status

- Confidence: strong for size and fields, medium for final field names.
- Owner class/file: [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md).
- Source resources: `TILEC.TBL` in current mode, `TILEC.TBD` in legacy mode.

## Layout

```text
TileClassEntry
  +0x00  uint16 tileId
  +0x02  uint8  allowPaletteFilter
  +0x03  uint8  padding
```

## Notes

- The constructor reads a signed 16-bit encoded tile-class value for each row.
- `tileId` stores the low 15 bits.
- `allowPaletteFilter` stores whether the original high bit was set.
- `RenderStaticObject` checks this flag when palette filtering is enabled before drawing a layer.

## Evidence

- 2026-05-31 IDA MCP decompilation of `0x004dcf60` confirms `StaticObjImageLib` allocates `4 * tileClassCount` bytes for the tile-class table at object offset `+0x08`, reads one signed/encoded 16-bit row from `TILEC.TBL` or `TILEC.TBD`, stores `value & 0x7fff` as the `uint16` tile id at record offset `+0x00`, and stores whether the original value was negative/high-bit-set at byte `+0x02`.
- 2026-05-31 IDA MCP decompilation of `0x004dd2c0` confirms `RenderStaticObject` indexes the table as `this->tileClasses + 4 * tileId`, reads the `uint16` tile id from `+0x00` for palette/frame lookup, and tests byte `+0x02` when palette filtering is active.
- 2026-05-31 IDA MCP decompilation of `0x004dd1e0` confirms the tile-class table at `StaticObjImageLib + 0x08` is owned by `StaticObjImageLib` and freed by the destructor.

## Cross-References

- [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md)
- [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)

## Changes

- 2026-05-31: Metadata had `COMPLETION:0`, `CONFIDENCE:0`, and no reconstructable flag despite existing layout notes. Changed to `COMPLETION:74`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE` after IDA MCP rechecked constructor allocation/population, render-time table lookup, and destructor ownership. The score remains below final-source level because final original field names and TILEC resource semantics still need broader resource-format audit.
