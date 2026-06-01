*** UID:0001W8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StaticObjEntry

## Status

- Confidence: strong for offsets and render use, medium for final field names.
- Owner class/file: [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md).
- Source resource: [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md).

## Layout

```text
StaticObjEntry
  +0x00  uint32 objectId
  +0x04  uint8  paletteGroup
  +0x05  uint8  layerCount
  +0x06  uint16 reservedOrClass
  +0x08  StaticObjEntry* cacheChain
  +0x0c  uint16 tileIds[layerCount]
```

## Notes

- The constructor allocates each record as `0x0c + 2 * layerCount` bytes and copies the trailing `uint16` list from `SOBJ.TBL`.
- `RenderStaticObject` reads `layerCount` from offset `+0x05`, then draws tile ids from the inline list in reverse order.
- Earlier docs and generated variable names called the byte at record file offset `+0x06` a name length. IDA render evidence shows the corresponding in-memory byte is a layer/tile-id count, not a wide-name character count.
- The `cacheChain` field is cleared and released by the destructor before the main entry is freed.

## Evidence

- 2026-05-31 IDA MCP decompilation of `0x004dcf60` confirms the constructor reads four object-id bytes, one palette/group byte, one unused/class byte, and one layer-count byte from `SOBJ.TBL`; allocates each record as `2 * layerCount + 0x0c`; copies the inline `uint16` tile-id list at `+0x0c`; stores object id at `+0x00`, palette/group at `+0x04`, layer count at `+0x05`, clears `+0x06`, and clears `cacheChain` at `+0x08`.
- 2026-05-31 IDA MCP decompilation of `0x004dd2c0` confirms the renderer loads the record pointer from `this+0x0c`, reads byte `+0x05` as the layer count, starts at `entry + 0x0c + 2 * (layerCount - 1)`, and walks the tile ids backward while drawing stacked layers.
- 2026-05-31 IDA MCP decompilation of `0x004dd850` confirms bounds calculation uses byte `+0x05` as the layer count to derive vertical extent.
- 2026-05-31 IDA MCP decompilation of `0x004dd1e0` confirms destructor cleanup uses `+0x08` as a linked cache-chain pointer before freeing the main entry table.

## Cross-References

- [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md)
- [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md)
- [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md)

## Changes

- 2026-05-31: Metadata had `COMPLETION:0`, `CONFIDENCE:0`, and no reconstructable flag despite existing layout notes. Changed to `COMPLETION:76`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE` after IDA MCP rechecked constructor, renderer, bounds, and destructor use of the fields. The score stays below final-source level because final original field names and the exact meaning of the file byte copied through local scratch storage into `+0x06` remain partly open.
