*** UID:0000KH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ItemObjImageLib

## Status

- Confidence: strong for class role and method ownership, medium for exact original filename.
- Proposed module: `render/ItemObjImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_ItemObjImageLib.cpp`
- Main address ranges: `0x004dec30-0x004df455` and `0x004e6580-0x004e65dc`
- Primary global instance: [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md) at `0x0067a758`
- Primary vtable: [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md) at `0x0061b73c`
- Layout/type docs: [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md), [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md)

## File Role

`ItemObjImageLib` is the item sprite image library. It owns the per-item image metadata loaded from `ITEM.TBL` or `ITEM.TBD`, exposes the shared item drawing API used by item lists and look panes, and applies palette/tint/filter policy before dispatching the low-level item blitter.

This should stay separate from [UID:0000K2][ImageLib](by-file/ImageLib.md). `ImageLib` and [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) provide the shared EPF/EPD frame lookup layer, while `ItemObjImageLib` owns item-specific table rows, legacy item-entry remapping, fixed-slot centering, crop-to-fit draw variants, palette slot `10`, and optional overlay/highlight passes.

## Owned And Nearby Helpers

The current class file owns the constructor, four draw methods, and scalar deleting destructor. IDA also confirms an unmodeled ordinary destructor body at `0x004dee20-0x004dee4c` and a tiny singleton-clear helper at `0x004e5ba0-0x004e5baa`.

The adjacent helper [UID:0000UQ][GetItemGlyphBounds_004DF460](by-item/GetItemGlyphBounds_004DF460.md) at `0x004df460-0x004df4f8` shares the same item archive globals and resolves item icon bounds for many UI callers, centering frames with the shared [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md). It is broad enough to remain a free helper in documentation, but it likely belongs in this module or a tiny item-image helper file rather than in a UI pane.

The generated one-function file name `LookupItemAtlasRect_004DF460.cpp` is stale relative to the current canonical global name `GetItemGlyphBounds`.

The generated `ProtectedArray_struct_ItemInfo_` file is a concrete template instantiation for this module's item metadata table. Treat [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md) as shared utility support and keep item table parsing/drawing here. The [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md) documented for this module is the render image-table row loaded from `ITEM.TBL` / `ITEM.TBD`; it should not be confused with broader gameplay item-database records used by item mixing and inventory logic.

## Singleton Global

`g_pItemObjImageLib` is backed by IDA `dword_67A758` at [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md). IDA MCP on 2026-05-25 reports 65 xrefs across 29 recognized functions, with writes from the constructor, scalar deleting destructor, and small cleanup helpers.

Current generated material also uses aliases such as `g_pItemObjectImageLib`, `g_pItemImageLib`, and raw `dword_67A758`. Normalize those to `g_pItemObjImageLib` unless stronger original-symbol evidence appears.

## Resource Inputs

| Resource | Role |
| --- | --- |
| `ITEM.TBL` | Main item metadata table in the extended item-archive path. |
| `ITEM.TBD` | Alternate/legacy item metadata table selected by the legacy item-table gate. |
| `ITEM.EPF` | Modern item sprite frame archive. |
| `ITEM.EPD` | Legacy item sprite frame archive used when extended archives are disabled. |
| `ITEM.PAL` | Palette slot `10` in [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md). |

The legacy item path derives an entry index from `itemId + 0x4000`, rebases a configured translated band by `+16211`, and clamps entries above the archive floor to `2418`. The same policy appears in the draw methods and `GetItemGlyphBounds`.

## Cross-References

- [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md)
- [UID:00017N][0x004dec30-0x004e65dc.ItemObjImageLib](by-memory/0x004dec30-0x004e65dc.ItemObjImageLib.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)
- [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md)
- [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md)
- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md)
- [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md)
- [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md)
- [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md)
- [UID:0000UQ][GetItemGlyphBounds_004DF460](by-item/GetItemGlyphBounds_004DF460.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000MB][PaletteLib](by-file/PaletteLib.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:82`.
  - Summary/evidence: item sprite library role, singleton/vtable/layout anchors, resource inputs, legacy remapping policy, draw/helper ownership, destructor/singleton clear, and alias normalization are documented; confidence is capped by exact original filename and free-helper placement.
- 2026-05-31 projected path and IDA range correction:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the main range summary used old ends `0x004df454` and `0x004e65db`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, `CONFIDENCE:84`, and corrected exclusive-end ranges `0x004df455` and `0x004e65dc`.
  - Summary/evidence: `proposed-source-tree.md` already places `ItemObjImageLib.cpp` under `render/`; IDA MCP confirmed constructor/draw/scalar bounds and ordinary destructor bytes on 2026-05-31.
