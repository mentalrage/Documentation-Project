*** UID:0004HP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00007Q | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
struct MapPaneTileRecord
{
    unsigned short groundTileId;
    unsigned short flags;
    unsigned short staticObjectId;
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Six-byte live MapPane tile-buffer record owned and emitted with [UID:00007Q][MapPane](by-class/MapPane.md); [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md) writes `groundTileId`, flag bit `0`, and `staticObjectId` from the opcode `0x06` packet, while [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md) reads `staticObjectId` at byte offset `+4`; distinct from [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md), the four-byte MapTileImageLib resource record. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MapPaneTileRecord

## Status

- Disposition: reconstructable NexusTK project type used by the live `MapPane` tile buffer.
- Direct owner/emitter: [UID:00007Q][MapPane](by-class/MapPane.md); file route [UID:0000L3][MapPane](by-file/MapPane.md).
- Source role: per-tile six-byte record addressed from `MapPane +0x3f8` / canonical `m_tileBuffer`.
- Confidence: high for size, word order, and `staticObjectId` byte offset; medium-high for exact original type and member spellings.

## Layout

`MapPaneTileRecord` is a three-word record:

| Offset | Field | Evidence |
| --- | --- | --- |
| `+0x0` | `groundTileId` | UID0003TL writes the first packet word per tile and redraws through `DrawTileAt` when it changes. |
| `+0x2` | `flags` | UID0003TL preserves existing flag bits except bit `0`, then merges bit `0` from the second packet word. |
| `+0x4` | `staticObjectId` | UID0003TL writes the third packet word; UID0003TJ reads this word while reconciling StaticObjectPane children for a tile rectangle. |

The record stride is six bytes. UID0003TL indexes `m_tileBuffer[tileX + tileY * m_mapWidth]`, and the decompiled store sequence writes three unsigned 16-bit values for each clipped tile. Historical `m_mapTileRecords` and `m_mapWidthTiles` spellings are superseded source-shape aliases, not distinct fields.

## Evidence

- Accepted B011 MCP session `b001-0001I5` for [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md) shows the opcode `0x06` handler parsing a clipped tile rectangle, then writing word `0`, bit `0` of word `1`, and word `2` into the MapPane tile buffer at `this+1016`.
- The same pass ties map dimensions `this+1012/+1014` to the row/column stride and confirms the target calls [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md) at `0x00510e28` and `0x00511318` after tile writes.
- [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md) scans tile rectangles, fetches a tile descriptor, and reads the static-object id word at descriptor byte offset `+4` before comparing it against existing StaticObjectPane state.
- [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md) is a different four-byte MapTileImageLib resource record with `paletteIndex`, `allowPaletteFilter`, and `reserved`; it must not be reused for this live MapPane tile-buffer record.
- [UID:0002QJ][0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile](by-memory/0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile.md) computes an exact uncompressed length of `6 * m_mapWidth * m_mapHeight` and inflates the `.cmp` payload into `m_tileBuffer`. The six-byte multiplier independently proves that a four-byte resource record cannot model the live cache.
- [UID:0004PZ][0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer](by-memory/0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer.md) allocates the same six-byte row count and zeroes the full buffer. Its three callers are all inside UID0002QJ and it never frees prior storage.
- Paired [UID:0002QK][0x00504e00-0x00505075.MapPaneSaveCompressedMapFile](by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md) compresses exactly the same `6 * width * height` bytes before successful free/clear. Load, allocation, save, packet writes, and static-object reads therefore agree on one live six-byte type.

## Score Rationale

Completion and confidence are `90/90` because the six-byte stride, three word fields, byte offset `+4` static-object id consumer, owner/emitter route, and conflict with the existing four-byte resource record are documented from current target/support evidence. The score does not exceed `90` because the exact original type and member spellings remain inferred source-facing names rather than recovered symbols.

## Cross-References

- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md)
- [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md)
- [UID:00042K][MapPaneLayout](by-type/by-struct/MapPaneLayout.md)
- [UID:0002QJ][0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile](by-memory/0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile.md)
- [UID:0002QK][0x00504e00-0x00505075.MapPaneSaveCompressedMapFile](by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md)
- [UID:0004PZ][0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer](by-memory/0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer.md)
- [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md)

## Changes

- 2026-07-14 Agent-B005 UID0002QJ callback: synchronized current source role to canonical `m_tileBuffer`/`m_mapWidth`, retained UID0003TL aliases only as superseded history, and added exact compressed-load, allocation/zeroing, and paired-save six-byte stride evidence. Score, owner/emitter, `Nested:0`, and the complete formal struct block are unchanged.

- 2026-07-06 Agent-B011 UID0003TL implementation callback: created this support type through the validator UID workflow for the live MapPane six-byte tile-buffer record. The page preserves the UID0003TL write-side evidence, UID0003TJ `staticObjectId` consumer at byte offset `+4`, and the explicit non-reuse distinction from the existing four-byte MapTileImageLib [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md).
