*** UID:0000O7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# StaticObjImageLib

## Status

- Confidence: strong for class role and table inputs, medium for exact original filename.
- Proposed module: `NexusTK/render/StaticObjImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_StaticObjImageLib.cpp`
- Main address ranges: `0x004dcf60-0x004dde01`, singleton clear helper `0x004e5c00-0x004e5c0b`, and scalar destructor `0x004e6990-0x004e6aa5`
- Primary global instance: [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md)
- Vtable: [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md)
- Layout docs: [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md), [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md), [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md)

## File Role

`StaticObjImageLib` is the static map object image library. It owns `SOBJ.TBL` object records, `TILEC` tile-class metadata, bounds computation for multi-layer static map objects, and the layered static-object draw path used by live object panes and map-photo composition.

This file should stay near `MapTileImageLib` because both consume tile-sized map art and use 25-slot palette families, but it is a distinct source unit: `SOBJ.TBL` object records and `TILEC.*` resources are static-object-specific.

## Owned Helpers

`BuildTilecArchiveTable` at `0x004dda60-0x004dde01` is only called by the constructor. It scans `TILEC%d.EPF` shards and builds the same packed archive metadata table used by other EPF helpers.

The constructor also calls `LoadImageFrameTable_4D0F50` when legacy mode uses `TILEC.EPD`; this helper is shared and should remain with the broader image-frame metadata module.

IDA confirms `StaticObjImageLib::RenderStaticObject` at [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md). IDA callers are only [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md) and [UID:0000MK][PhotoPane](by-file/PhotoPane.md), so it belongs here.

IDA also confirms an ordinary non-deleting destructor at [UID:00017I][0x004dd1e0-0x004dd2bd.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2bd.StaticObjImageLibDestructor.md) and a singleton clear helper at [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md). Active generated output currently emits only the scalar deleting destructor at `0x004e6990`.

## Resource Inputs

| Resource | Role |
| --- | --- |
| `SOBJ.TBL` | Static object table. Contains object id, palette group/class bytes, layer/tile-id count, and per-layer tile ids. |
| `TILEC.EPF` / `TILEC%d.EPF` | Modern static object/tile-decoration image archives. |
| `TILEC.TBL` | Modern tile-class table. |
| `TILEC.EPD` | Legacy static object/tile-decoration image archive. |
| `TILEC.TBD` | Legacy tile-class table. |
| `TILEC.PAL` | Palette slot `1` in [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md). |

`SOBJ.TBL` also has a second map-initialization parser view documented at [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md). `StaticObjImageLib` owns the full render/resource table; [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md) is only a compact map-gameplay classification cache built from the same records.

## Cross-References

- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md)
- [UID:00017H][0x004dcf60-0x004e6aa6.StaticObjImageLib](by-memory/0x004dcf60-0x004e6aa6.StaticObjImageLib.md)
- [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md)
- [UID:00017I][0x004dd1e0-0x004dd2bd.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2bd.StaticObjImageLibDestructor.md)
- [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md)
- [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md)
- [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md)
- [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md)
- [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md)
- [UID:0000U6][BuildTilecArchiveTable_004DDA60](by-item/BuildTilecArchiveTable_004DDA60.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `80`.
  - Evidence: document covers class role, singleton/vtable/layout anchors, owned helpers, destructor/render body ownership, resource inputs, SOBJ/TILEC split, dependencies, and cross-references; confidence remains capped by exact original filename and current generated-output omissions.
- 2026-05-31: Reconstruction path was blank even though the proposed tree already places this module under `render/StaticObjImageLib.cpp`.
  - Before: `PROPOSED_RECONSTRUCTION_PATH:""`.
  - After: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.
  - Evidence: [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md) and [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md) rechecked the constructor/render/destructor ownership against IDA MCP, and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already lists `render/StaticObjImageLib.cpp` as the planned source file.
