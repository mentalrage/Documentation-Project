*** UID:0001V2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:00007T | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MapTileImageLib Layout

## Status

- Entity kind: class layout support struct.
- Confidence: strong for observed offsets, medium for final field names.
- Proposed owner: [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md), emitted through [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md).
- Autogen parent: attached to [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md); the class scores `84/84`, the owning file scores `86/82`, and this layout scores `84/88`, so the direct class parent and file root both satisfy the 80/80 parent gate.
- Evidence basis: IDA MCP constructor/destructor/draw decompile checks, vtable xrefs, singleton xrefs, and current exact by-memory child pages. Generated `simroot_v2` data is only a lead source.

## Layout

```text
MapTileImageLib
  +0x00  LObject base / MapTileImageLib vptr
  +0x04  ArchiveMetadataTable* tileMetadata
  +0x08  MapTileRecord* tileRecords
```

Observed object size is `0x0c` bytes.

## Field Evidence

- The constructor stores [UID:0000V0][LoadTileEpfMetadata_004D1B80](by-item/LoadTileEpfMetadata_004D1B80.md)'s return value at `+0x04`.
- `DrawTile` reads `+0x04` before calling `LoadFrameDrawRecord_4D1600` / `0x004d1600`.
- The constructor allocates `4 * tileCount` bytes and stores the result at `+0x08`.
- The constructor decodes each `TILE.TBL` packed word into one [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md) at `+0x08 + 4 * index`.
- The ordinary and scalar deleting destructors free both `+0x04` metadata storage and the `+0x08` tile-record array, then clear [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md).

## 2026-05-31 IDA Recheck

- `sub_4D1860` stores [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md), writes [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md), stores the [UID:0000V0][LoadTileEpfMetadata_004D1B80](by-item/LoadTileEpfMetadata_004D1B80.md) result at object `+0x04`, and stores the allocated [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md) array at object `+0x08`.
- `sub_4D1A20` reads `this[1]` / object `+0x04` as the frame metadata table and `this[2]` / object `+0x08` as the 4-byte tile-record array.
- `sub_4D19A0` and `sub_4E66A0` release the metadata payload/table and the tile-record array, confirming both non-base fields are owned by this object.
- `xrefs_to 0x0061b664` lands only in the constructor, ordinary destructor, and scalar deleting destructor. The vtable ends before the next RTTI pointer at `0x0061b670`.

## Cross-References

- [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md)
- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md)
- [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:000177][0x004d1860-0x004e6748.MapTileImageLib](by-memory/0x004d1860-0x004e6748.MapTileImageLib.md)

## Changes

- 2026-06-06 A004 parent-gate sync: moved `AUTOGEN_PARENT_UID` from [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md) to [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md) after the class page was refreshed to `84/84` and attached to the file root. Scores remain `84/88`; this is a parent metadata cleanup.
- 2026-06-06: Attached the layout to [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md) as a file-level parent. Scores remain `84/88`; this was a parent metadata cleanup while the direct class page remained below the confidence gate.
- Completion/confidence metadata: existed before as `0/0`; changed to `84/88`. Summary: object size, vtable install, singleton, owned metadata pointer, owned tile-record array, draw-path reads, and cleanup sites are now directly documented from IDA. Evidence: [UID:0002IZ][0x004d1860-0x004d199e.MapTileImageLibConstructor](by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md), [UID:0002J0][0x004d1a20-0x004d1b72.MapTileImageLibDrawTile](by-memory/0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md), [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md), and [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md).
- Reconstructable metadata: existed before as blank; changed to `TRUE`. Summary: this layout represents NexusTK-owned class state needed for the rebuilt `MapTileImageLib`; parent UID and C++ reconstruction remain blank because final source names and source-shape are below the `95+` final-source gate.
