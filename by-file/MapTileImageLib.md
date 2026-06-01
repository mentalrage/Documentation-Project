*** UID:0000L5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MapTileImageLib

## Status

- Confidence: strong for class role and helper ownership, medium for exact original filename.
- Proposed module: `render/MapTileImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_MapTileImageLib.cpp`
- Main address ranges: `0x004d1860-0x004d1f22`, singleton clear helper `0x004e5bc0-0x004e5bcb`, and scalar destructor `0x004e66a0-0x004e6748`
- Primary global instance: [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md)
- Vtable: [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md)
- Layout docs: [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md), [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md)

## File Role

`MapTileImageLib` is the terrain tile image library. It owns the loaded map-tile EPF metadata table, the `TILE.TBL` palette/filter table, and the draw path that resolves a tile id into an `EPFTileContext` and selected palette.

This should stay separate from [UID:0000K2][ImageLib](by-file/ImageLib.md). `ImageLib`/`ResourceLayoutTable` provide general EPF/EPD frame lookup, while `MapTileImageLib` owns map-tile-specific metadata, legacy tile-id correction, palette-filter gating, and the terrain-tile draw wrapper.

## Owned Helpers

`LoadTileEpfMetadata` at `0x004d1b80-0x004d1f22` is only called by the `MapTileImageLib` constructor. It scans `TILE%d.EPF` archives, reads their shared frame-record headers, merges them into one `ArchiveMetadataTable`, and appends a sentinel record. Keep this helper with `MapTileImageLib` or a tightly shared image-frame metadata module.

`MapTileImageLib::DrawTile` also calls `LoadFrameDrawRecord_4D1600` to resolve one frame from the loaded metadata table before dispatching the low-level tile blitter.

IDA also confirms an ordinary non-deleting destructor at [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md). Active `simroot_v2/class_MapTileImageLib.cpp` currently emits only the scalar deleting destructor at `0x004e66a0`, so use the exact memory page for final lifetime coverage.

## Resource Inputs

| Resource | Role |
| --- | --- |
| `TILE%d.EPF` | Modern mode map-tile frame/pixel archive shards scanned by `LoadTileEpfMetadata`. |
| `TILE.TBL` | Per-tile table read by the constructor; stores tile palette index and high-bit palette-filter flag. |
| `TILE.TBD` | Legacy mode tile-count guard used by `DrawTile` to clamp invalid tile ids to `0`. |
| `TILE.PAL` | Palette slot `0` in [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md). |

## Cross-References

- [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md)
- [UID:000177][0x004d1860-0x004e6748.MapTileImageLib](by-memory/0x004d1860-0x004e6748.MapTileImageLib.md)
- [UID:000178][0x004d19a0-0x004d1a1c.MapTileImageLibDestructor](by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md)
- [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md)
- [UID:0001Y3][MapTileImageLibVtable](by-type/by-vtable/MapTileImageLibVtable.md)
- [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md)
- [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md)
- [UID:0000V0][LoadTileEpfMetadata_004D1B80](by-item/LoadTileEpfMetadata_004D1B80.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000MB][PaletteLib](by-file/PaletteLib.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: terrain tile image-library role, singleton/vtable/layout anchors, resource inputs, owned metadata loader, destructor gap, `ImageLib` split, and palette/frame dependencies are documented; confidence is capped by exact original filename and helper sharing with image-frame metadata.
- 2026-05-31 projected reconstruction path:
  - What existed before: blank `PROPOSED_RECONSTRUCTION_PATH`.
  - Changed to: `NexusTK/render/`.
  - Summary/evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already places `MapTileImageLib.cpp` under `render/`, and IDA confirms this class is a distinct terrain tile image-library module with one startup constructor caller, owned singleton [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md), owned layout [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md), and owned tile resources.
- 2026-05-31 half-open range correction:
  - What existed before: the main helper/scalar ranges used `0x004d1f21` and `0x004e6747` endpoints.
  - Changed to: `0x004d1f22` and `0x004e6748`.
  - Summary/evidence: IDA `lookup_funcs` reports `LoadTileEpfMetadata` at `0x004d1b80` with size `0x3a2` and scalar deleting destructor at `0x004e66a0` with size `0xa8`, so the by-memory half-open endpoints are `0x004d1f22` and `0x004e6748`.
