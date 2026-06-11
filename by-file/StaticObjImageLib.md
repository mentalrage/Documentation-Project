*** UID:0000O7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# StaticObjImageLib

## Status

- Confidence: strong for class role and table inputs, medium for exact original filename.
- Proposed module: `NexusTK/render/StaticObjImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_StaticObjImageLib.cpp`
- Main address ranges: `0x004dcf60-0x004dde01`, singleton clear helper `0x004e5c00-0x004e5c0b`, and scalar destructor `0x004e6990-0x004e6aa6`
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

IDA also confirms an ordinary non-deleting destructor at [UID:00017I][0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md) with exact exclusive end `0x004dd2be`, and a singleton clear helper at [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md). Active generated output currently emits only the scalar deleting destructor at `0x004e6990`.

## Parent-Gate Evidence

This page is the direct source parent for [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md). Batch122 IDA recheck confirms the helper is an exact `0xb` function that writes zero to [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md), has no ordinary callers or callees, is reached by the constructor cleanup jump from the `StaticObjImageLib` constructor region, and participates in the same singleton lifecycle as the constructor, ordinary destructor, scalar deleting destructor, shutdown, static-object consumers, and photo composition.

Confidence is now `85` because the file source root owns the constructor/destructor/render/bounds/archive-helper/singleton-helper/scalar-destructor family, the `SOBJ.TBL`/`TILEC` resources, the vtable and singleton globals, and the consumer split from `StaticObjectPane` and `PhotoPane`. Confidence remains capped at 85 rather than higher because final field names, helper names, and exact original filename are still not final-audit quality.

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
- [UID:00017I][0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor](by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md)
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
- 2026-06-06: Corrected destructor range wording.
  - Before: the page listed the scalar deleting destructor with last-byte-style end `0x004e6aa5` and the ordinary destructor link inherited the old `0x004dd2bd` end.
  - After: the status line uses scalar destructor range `0x004e6990-0x004e6aa6`, and the owned-helper paragraph records ordinary destructor exclusive end `0x004dd2be` while its filename rename is pending.
  - Evidence: IDA MCP `lookup_funcs` reports `sub_4DD1E0` as `0xde` bytes ending at `0x004dd2be`, and earlier aggregate evidence already confirmed `sub_4E6990` ends at `0x004e6aa6`.
- 2026-06-08 A003 Batch122: Raised confidence from `80` to `85`.
  - Before: the file had strong source-role documentation but did not explicitly support strict `85/85` routing for the singleton clear helper.
  - After: added parent-gate evidence tying constructor/destructor/render/bounds/archive-helper/singleton-helper/scalar-destructor evidence to this file source root and documenting [UID:000184][0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper](by-memory/0x004e5c00-0x004e5c0b.StaticObjImageLibSingletonClearHelper.md) as direct cleanup-glue ownership.
  - Evidence: Batch122 IDA `lookup_funcs`, `decompile`, `callers`, `callees`, `xrefs_to`, and byte review for `0x004e5c00`, `0x0069b448`, and neighboring helper boundaries.
