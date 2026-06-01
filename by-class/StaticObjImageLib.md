*** UID:0000E2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# StaticObjImageLib

## Status

- Confidence: strong for constructor/destructor and bounds helper, medium for field names.
- Likely source file: [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- Address ranges: [UID:00017H][0x004dcf60-0x004e6aa6.StaticObjImageLib](by-memory/0x004dcf60-0x004e6aa6.StaticObjImageLib.md)
- Current recovered file: `source-3/simroot_v2/class_StaticObjImageLib.cpp`
- Vtable: [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md)
- Layout docs: [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md), [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md), [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md)
- Singleton: [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md)

## Class Purpose

`StaticObjImageLib` is the static map object image library behind `g_pStaticObjImageLib`. It parses object records from `SOBJ.TBL`, loads `TILEC` archive metadata, reads tile-class records, and returns tile-aligned bounds for static-object ids.

## Observed Layout

```text
StaticObjImageLib
  +0x00  LObject/vtable
  +0x04  ArchiveMetadataTable* tileCatalog
  +0x08  TileClassEntry* tileClasses
  +0x0c  StaticObjEntry** staticObjEntries
  +0x10  int staticObjCount
```

`StaticObjEntry` records include object id, palette group, layer count, optional cache-chain nodes, and inline tile ids. `TileClassEntry` records are 4 bytes and mirror the high-bit plus 15-bit id pattern used by map tile records.

The shared resource layout and the second compact map-cache parser are tracked in [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md). This class owns the full static-object render/resource view, while [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md) is map-gameplay cache state.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `StaticObjImageLib::StaticObjImageLib` | `0x004dcf60` | Loads `SOBJ.TBL`, then loads `TILEC` archive/table resources depending on modern/legacy mode. |
| `~StaticObjImageLib` | `0x004dd1e0` | Non-deleting cleanup body omitted by active generated output; releases object records, tile catalog/cache chain, tile classes, and singleton state. |
| `RenderStaticObject` | `0x004dd2c0` | Draws layered static-object tiles and optional overlay masks; active generated output currently leaves this in the disabled companion file. |
| `GetStaticObjectBounds` | `0x004dd850` | Returns local bounds based on object layer count and global tile dimensions. |
| `ClearStaticObjImageLibSingleton` | `0x004e5c00` | Tiny cleanup helper that only clears `g_pStaticObjImageLib`; likely compiler/static cleanup glue. |
| `DeletingDestructor` | `0x004e6990` | Frees static object entries, tile catalog/cache chain, tile-class table, clears global, and optionally deletes `this`. |

## Data Caveats

- Current `class_StaticObjImageLib.meta_wave3` reports `vtable_count: 0`, but IDA confirms the primary vtable at `0x0061b704`.
- Active `source-3/simroot_v2/class_StaticObjImageLib.cpp` excludes `RenderStaticObject` at `0x004dd2c0` into `class_StaticObjImageLib.cpp.disabled`.
- Active generated output omits the ordinary destructor at `0x004dd1e0` and the singleton clear helper at `0x004e5c00`.
- Generated and older docs called the third `SOBJ.TBL` per-record byte a name length. IDA render evidence uses the corresponding in-memory byte as `layerCount`, with `uint16` tile ids following the fixed header.

## Cross-References

- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md)
- [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md)
- [UID:0001YX][StaticObjImageLibVtable](by-type/by-vtable/StaticObjImageLibVtable.md)
- [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md)
- [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md)
- [UID:0001WC][TileClassEntry](by-type/by-struct/TileClassEntry.md)
- [UID:00017J][0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject](by-memory/0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md)
- [UID:0000U6][BuildTilecArchiveTable_004DDA60](by-item/BuildTilecArchiveTable_004DDA60.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `78`.
- Evidence: the page documents static-object resource responsibility, layout, singleton/vtable/type/resource docs, constructor/destructor/render/bounds/destructor methods, data caveats, and corrected `SOBJ.TBL` semantics; confidence remains capped by provisional field names and active generated omissions.
