*** UID:00007T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MapTileImageLib

## Status

- Confidence: strong for method roles, medium for final field names.
- Likely source file: [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- Address ranges: [UID:000177][0x004d1860-0x004e6748.MapTileImageLib](by-memory/0x004d1860-0x004e6748.MapTileImageLib.md)
- Current recovered file: `source-3/simroot_v2/class_MapTileImageLib.cpp`
- Vtable: [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md)
- Layout docs: [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md), [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md)
- Singleton: [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md)

## Class Purpose

`MapTileImageLib` is the map terrain tile image library behind `g_pMapTileImageLib`. It loads tile frame metadata from `TILE%d.EPF`, reads per-tile palette/filter metadata from `TILE.TBL`, and draws a terrain tile into a target draw surface.

## Observed Layout

```text
MapTileImageLib
  +0x00  LObject/vtable
  +0x04  ArchiveMetadataTable* tileMetadata
  +0x08  MapTileRecord* tileRecords
```

`MapTileRecord` is 4 bytes: a 15-bit tile palette/frame index plus a high-bit flag that allows drawing while palette filtering is enabled. See [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MapTileImageLib::MapTileImageLib` | [UID:0002IZ][0x004d1860-0x004d199e.MapTileImageLibConstructor](by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md) | Sets `g_pMapTileImageLib`, loads `TILE%d.EPF` metadata, opens `TILE.TBL`, validates counts, and stores tile records. |
| `~MapTileImageLib` | [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md) | Non-deleting cleanup body omitted by some generated output; frees metadata and tile records, clears singleton, and calls `LObject` cleanup. |
| `DrawTile` | [UID:0002J0][0x004d1a20-0x004d1b72.MapTileImageLibDrawTile](by-memory/0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md) | Resolves legacy tile ids, loads an `EPFTileContext`, applies palette-filter rules, and dispatches the tile blitter. |
| `LoadTileEpfMetadata` | [UID:0002J1][0x004d1b80-0x004d1f22.LoadTileEpfMetadata](by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md) | File-local/helper metadata loader for tile EPF archive shards. |
| `ClearMapTileImageLibSingleton` | `0x004e5bc0` | Tiny cleanup helper that only clears `g_pMapTileImageLib`; likely compiler/static cleanup glue. |
| `ScalarDeletingDestructor` | [UID:0002J2][0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor](by-memory/0x004e66a0-0x004e6748.MapTileImageLibScalarDeletingDestructor.md) | Frees tile metadata payload/table, frees tile records, clears `g_pMapTileImageLib`, and optionally deletes `this`. |

## Data Caveats

- Current `class_MapTileImageLib.meta_wave3` reports `vtable_count: 0`, but IDA confirms the primary vtable at `0x0061b664`.
- Active `source-3/simroot_v2/class_MapTileImageLib.cpp` omits the ordinary destructor at `0x004d19a0` and the tiny singleton clear helper at `0x004e5bc0`.
- Current generated metadata still treats `g_pMapTileImageLib` as unresolved global data in some consumer files; the backing storage is IDA `dword_67A75C` at `0x0067a75c`.

## Cross-References

- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:0000V0][LoadTileEpfMetadata_004D1B80](by-item/LoadTileEpfMetadata_004D1B80.md)
- [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md)
- [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md)
- [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md)
- [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md)
- [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `82/78`. Summary: the terrain tile library has substantial documentation for purpose, singleton, vtable, layout, tile records, constructor/destructor/draw behavior, file formats, and generated data caveats, but final field names remain medium confidence. Evidence: linked main memory range, destructor page, `g_pMapTileImageLib`, `MapTileImageLibLayout`, `MapTileRecord`, `TILE%d.EPF`/`TILE.TBL` notes, and IDA-confirmed vtable evidence.
- Reconstructable metadata: existed before as blank; changed to `TRUE`. Summary: `MapTileImageLib` is a NexusTK-owned class that must be represented in the rebuilt client. Evidence: IDA-confirmed constructor, draw method, destructors, vtable, singleton, owned resource inputs, and startup constructor call. Parent UID and C++ reconstruction remain blank because final source code is below the `95+` gate.
- Method inventory update: existed before with only address literals for constructor, draw method, helper, and scalar deleting destructor; changed to UID links for exact by-memory child pages. Summary: the broad aggregate now has exact children for the constructor, draw method, metadata loader, and scalar deleting destructor. Evidence: IDA function sizes and padding-byte checks on 2026-05-31.
