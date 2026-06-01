*** UID:0000IY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# EffectObjImageLib

## Status

- Confidence: strong for class role, resource ownership, singleton storage, and core method boundaries; medium for exact original filename and final field names.
- Proposed module: `render/EffectObjImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_EffectObjImageLib.cpp`
- Disabled generated source containing a real method: `source-3/simroot_v2/class_EffectObjImageLib.cpp.disabled`
- Main address ranges: `0x004ddf60-0x004dec23`, `0x004e5b70-0x004e5b7b`, and `0x004e62f0-0x004e6456` (`[start,end)` for exact function pages where rechecked)
- Primary global instance: [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md), backed by [UID:0001PQ][0x0069b44c-0x0069b450.g_pEffectObjImageLib](by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md)
- Primary vtable: [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md) at `0x0061b724`
- Layout/type docs: [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md), [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md), [UID:0001U7][EffectFrameRecord](by-type/by-struct/EffectFrameRecord.md), [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md)

## File Role

`EffectObjImageLib` is the effect sprite image library. It owns `EFFECT.TBL` effect descriptors, `EFFECT.FRM` frame-to-pixmap/palette remaps, the merged effect EPF archive metadata table, and effect bounds/render helper behavior.

This should remain a separate render source file from map/static object libraries. It shares the same EPF archive-table loader pattern, but the data model is effect-specific: each [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) descriptor has two heap-owned [UID:0001U7][EffectFrameRecord](by-type/by-struct/EffectFrameRecord.md) arrays, while the `EFFECT.FRM` table maps effect animation frames to four-byte [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md) remap entries.

This file is also separate from the runtime [UID:0000IZ][Effects](by-file/Effects.md) module. `EffectObjImageLib` loads and indexes effect sprite assets; runtime classes such as `EffectObjectPane`, `OverlayEffecter`, `FilterEffecter`, `WaterFilterEffecter`, and `XWaveEffecter` consume those assets or render over the map.

The generated `ProtectedArray_struct_EffectInfo_` and `ProtectedArray_struct_EffectPixMapInfo_` files are template-instantiation artifacts for the descriptor and frame-remap arrays owned here. Keep the reusable template in [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md), not as effect-specific standalone source files.

## Owned Methods And Helpers

| Range | Function | Role |
| --- | --- | --- |
| `0x004ddf60-0x004de04e` | [UID:0002H9][0x004ddf60-0x004de04e.EffectObjImageLibConstructor](by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md) | Constructs the singleton, initializes effect descriptor/remap arrays, loads effect tables, builds effect EPF metadata, and validates frame coverage. |
| `0x004de050-0x004de189` | [UID:00017L][0x004de050-0x004de189.EffectObjImageLibDestructor](by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md) | Non-deleting cleanup body for effect frame arrays, EPF metadata, descriptor arrays, and singleton state. |
| `0x004de190-0x004de29f` | [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md) | Real effect sprite draw method. Current active generated output omits it because Wave3 places it in the disabled partition. |
| `0x004de2a0-0x004de3d1` | [UID:0000UR][GetSpriteBounds_004DE2A0](by-item/GetSpriteBounds_004DE2A0.md) | Effect-frame bounds helper using `EFFECT%d.EPF` in current mode or `EFFECT.EPD` in legacy mode. |
| `0x004de3e0-0x004de420` | [UID:0002HA][0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo](by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md) | Copies a 1-based effect descriptor, falling back to the scratch descriptor when out of range. |
| `0x004de420-0x004de7c1` | [UID:0000U4][BuildEffectArchiveTable_004DE420](by-item/BuildEffectArchiveTable_004DE420.md) | One-caller helper that scans `EFFECT%d.EPF` shards and builds the packed archive metadata table. |
| `0x004de7d0-0x004dec23` | [UID:0002HB][0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables](by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md) | Loads `EFFECT.TBL` and `EFFECT.FRM` into descriptor/remap arrays. |
| `0x004e5b70-0x004e5b7a` | [UID:00017W][0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper](by-memory/0x004e5b70-0x004e5b7b.EffectObjImageLibSingletonClearHelper.md) | Clears the singleton pointer during static/runtime teardown. |
| `0x004e62f0-0x004e6456` | [UID:0002HC][0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor](by-memory/0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor.md) | Virtual/delete destructor body; mirrors ordinary cleanup and optionally deletes `this`. |

## Resource Inputs

| Resource | Role |
| --- | --- |
| `EFFECT.TBL` | Effect descriptor table. Header count followed by 52-byte [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md) descriptors and two variable-length 16-byte frame arrays per descriptor. |
| `EFFECT.FRM` | Frame-remap table. Header count followed by four-byte [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md) records used by `RenderEffectFrame`. |
| `EFFECT.EPF` / `EFFECT%d.EPF` | Current effect image archive inputs and numbered archive shards. |
| `EFFECT.EPD` | Legacy effect bounds/image lookup path used by `GetSpriteBounds`. |
| `EFFECT.PAL` | Palette category `11` through [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md). |

## Evidence

- IDA MCP confirms the vtable at `0x0061b724`; constructor, ordinary destructor, and scalar deleting destructor all store that vtable.
- IDA MCP confirms singleton storage [UID:0001PQ][0x0069b44c-0x0069b450.g_pEffectObjImageLib](by-memory/0x0069b44c-0x0069b450.g_pEffectObjImageLib.md) as `dword_69B44C`, with constructor writes, destructor clears, application shutdown read, and effect/map consumer reads.
- IDA MCP caller checks show `RenderEffectFrame` at `0x004de190` has a modeled caller at `0x00538ba0` in the `EffectObjectPane` render path.
- IDA MCP caller checks show `BuildEffectArchiveTable` and `LoadEffectTables` are only called by the constructor.
- IDA MCP recheck on 2026-05-31 confirms exact boundaries for constructor (`0xee` bytes), `GetEffectInfo` (`0x40` bytes), `LoadEffectTables` (`0x453` bytes), and scalar deleting destructor (`0x166` bytes).
- Current `class_EffectObjImageLib.meta_wave3` reports `vtable_count: 0` and keeps `RenderEffectFrame` disabled, so the IDA-backed docs are the accuracy anchor until generated data catches up.

## Cross-References

- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:00017K][0x004ddf60-0x004e6455.EffectObjImageLib](by-memory/0x004ddf60-0x004e6455.EffectObjImageLib.md)
- [UID:0002H9][0x004ddf60-0x004de04e.EffectObjImageLibConstructor](by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md)
- [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md)
- [UID:0001XG][EffectObjImageLibVtable](by-type/by-vtable/EffectObjImageLibVtable.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md)
- [UID:0001U7][EffectFrameRecord](by-type/by-struct/EffectFrameRecord.md)
- [UID:0001UA][EffectPixMapInfo](by-type/by-struct/EffectPixMapInfo.md)
- [UID:0002HA][0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo](by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md)
- [UID:0002HB][0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables](by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md)
- [UID:0002HC][0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor](by-memory/0x004e62f0-0x004e6456.EffectObjImageLibScalarDeletingDestructor.md)
- [UID:0000U4][BuildEffectArchiveTable_004DE420](by-item/BuildEffectArchiveTable_004DE420.md)
- [UID:0000UR][GetSpriteBounds_004DE2A0](by-item/GetSpriteBounds_004DE2A0.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000IZ][Effects](by-file/Effects.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:84`.
  - Summary/evidence: effect image-library role, resource ownership, singleton/vtable/layout/type anchors, method/helper map, generated disabled-method caveat, asset/runtime separation, and cross-references are documented; confidence is strong with only final field names and exact original filename still medium.
- 2026-05-31 projected path and exact memory-page split:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and several method rows were text-only entries inside the broad file page.
  - Changed to: projected path `NexusTK/render/`, with exact by-memory pages linked for constructor, `GetEffectInfo`, `LoadEffectTables`, and scalar deleting destructor.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `EffectObjImageLib.cpp` under `render/`, and IDA MCP rechecked exact function sizes, callers, resource names, and core field offsets on 2026-05-31.
