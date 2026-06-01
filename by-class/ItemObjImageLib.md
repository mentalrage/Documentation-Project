*** UID:00006W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ItemObjImageLib

## Status

- Confidence: strong for method roles, medium for final field names and offsets.
- Likely source file: [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- Address ranges: [UID:00017N][0x004dec30-0x004e65dc.ItemObjImageLib](by-memory/0x004dec30-0x004e65dc.ItemObjImageLib.md)
- Singleton: [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md) at [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md)
- Vtable: [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md) at `0x0061b73c`
- Layout: [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md)
- Current recovered file: `source-3/simroot_v2/class_ItemObjImageLib.cpp`

## Class Purpose

`ItemObjImageLib` is the singleton-backed item sprite library behind [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md). It loads item metadata from DAT-backed item table files and supplies the shared item draw routines used by item lists, inventory/fitting panes, item menus, look panes, and dialogs.

## Observed State

```text
ItemObjImageLib
  +0x00  LObject/vtable
  +0x04  ProtectedArray<ItemInfo> itemInfoArray
  +0x14  ItemInfo fallbackItemInfo
```

The object is at least `0x28` bytes. IDA confirms `ProtectedArray<ItemInfo>` uses count/capacity at `+0x08`, entry pointer at `+0x0c`, and growth/default capacity at `+0x10`. The fallback [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md) at `+0x14` is used when an item entry index is out of range.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ItemObjImageLib::ItemObjImageLib` | `0x004dec30-0x004dee1b` | Constructs the singleton, seeds fallback item info, opens `ITEM.TBL` or `ITEM.TBD`, resizes the item array, and reads item metadata rows. |
| `ItemObjImageLib::~ItemObjImageLib` | [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md) | Ordinary non-deleting destructor body; IDA does not currently model it as a function, but disassembly shows vtable stores, item-array free, singleton clear, and `LObject` cleanup. |
| `DrawItemImage` | `0x004dee50-0x004defba` | General item draw path for item/list/look callers; resolves `ITEM.EPF`, selects palette/tint state, draws the sprite, and optionally performs the overlay pass. |
| `DrawItemImageIn43x43Slot` | `0x004defc0-0x004df1d4` | Fixed `43x43` slot draw path that clamps oversized source rects and recenters the destination. |
| `DrawItemImageUnscaled` | `0x004df1e0-0x004df2b7` | Direct draw path without recentering or overlay. |
| `DrawItemImageScaled` | `0x004df2c0-0x004df455` | Crop-to-fit/scaled item draw path for item menu and preview UI. |
| `ItemObjImageLib::ClearSingleton` | `0x004e5ba0-0x004e5bab` | Tiny helper that clears [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md). |
| `ScalarDeletingDestructor` | `0x004e6580-0x004e65dc` | Frees item records, clears [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md), runs `LObject` teardown, and optionally deletes `this`. |

IDA MCP on 2026-05-22 found the constructor has one startup caller at `0x004f602f`. The draw methods have broad UI caller sets, while the destructor is vtable/disposal glue with no direct code refs.

IDA MCP on 2026-05-25 confirms the singleton storage at `0x0067a758` has 65 xrefs across 29 recognized functions. The constructor writes the object pointer at `0x004dec7b`, while cleanup/destructor paths clear it at `0x004dec82`, `0x004dee3b`, `0x004e5ba0`, and `0x004e659e`.

IDA MCP on 2026-05-26 confirms the primary vtable at `0x0061b73c`, with constructor store `0x004dec8c`, unmodeled ordinary destructor store `0x004dee23`, and scalar deleting destructor store `0x004e6586`. Active generated metadata currently reports `vtable_count: 0`.

## Closely Related Global

[UID:0000UQ][GetItemGlyphBounds_004DF460](by-item/GetItemGlyphBounds_004DF460.md) is not a class method, but it is the shared item icon bounds lookup helper. It uses the same `ITEM.EPF` versus `ITEM.EPD` selection globals and calls `ResourceLayoutTable::GetEntryRect` before offsetting the rect into the standard icon slot.

## Cross-References

- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)
- [UID:0001OT][0x0067a758-0x0067a75c.g_pItemObjImageLib](by-memory/0x0067a758-0x0067a75c.g_pItemObjImageLib.md)
- [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md)
- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md)
- [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md)
- [UID:00017N][0x004dec30-0x004e65dc.ItemObjImageLib](by-memory/0x004dec30-0x004e65dc.ItemObjImageLib.md)
- [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md)
- [UID:00017Y][0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper](by-memory/0x004e5ba0-0x004e5bab.ItemObjImageLibSingletonClearHelper.md)
- [UID:0000UQ][GetItemGlyphBounds_004DF460](by-item/GetItemGlyphBounds_004DF460.md)
- [UID:0000MU][ProtectedArray](by-file/ProtectedArray.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:0000A1][PaletteLib](by-class/PaletteLib.md)
- [UID:0000V4][PaletteSlotTable](by-item/PaletteSlotTable.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `84/82`. Summary: item sprite library role, singleton/vtable/layout, constructor/destructor/draw methods, fallback item info, ProtectedArray storage, startup and global xrefs, related bounds helper, and palette/resource relationships are documented; confidence is capped by final field names and offsets. Evidence: `ItemObjImageLib`, `ItemObjImageLibDestructor`, singleton storage page, `ItemObjImageLibVtable`, `ItemObjImageLibLayout`, `ItemInfo`, `GetItemGlyphBounds`, and ProtectedArray/ResourceLayoutTable references.
- 2026-05-31 IDA range/layout update:
  - What existed before: old method endings, aggregate range `0x004dec30-0x004e65db`, destructor range `0x004dee20-0x004dee4c`, and `RECONSTRUCTABLE:` blank.
  - Changed to: `RECONSTRUCTABLE:TRUE`, corrected exclusive-end method ranges, aggregate range `0x004dec30-0x004e65dc`, destructor range `0x004dee20-0x004dee4d`, and scores `86/84`.
  - Summary/evidence: IDA MCP confirmed exact function bounds, constructor row read order, vtable/global xrefs, and scalar deleting destructor bounds. Scores stay below final level pending exact child-page split for every draw method and final source-facing field names.
