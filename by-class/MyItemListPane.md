*** UID:00008W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MyItemListPane

## Status

- Confidence: strong for confirmed functions; medium for exact source-file split.
- Likely source file: [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md), or folded into [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) if final source layout favors compact item-dialog files.
- Current recovered file: `source-3/simroot_v2/class_MyItemListPane.cpp`
- Vtables: [UID:0001Y8][MyItemListPaneVtables](by-type/by-vtable/MyItemListPaneVtables.md) at `0x00619f28`, `0x00619fb0`, and `0x00619fe0`

## Class Purpose

`MyItemListPane` displays the local player's own inventory items as selectable rows. It is a feature-specific `ListPane` subclass used when dialogs need the user to pick an item from their inventory.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MyItemListPane` | `0x004aeb30-0x004aec77` | [UID:0002JO][0x004aeb30-0x004aec77.MyItemListPaneConstructor](by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md) builds a `ListPane` with old/new rendering-mode dimensions, enumerates player inventory slots, and appends active item rows. |
| `GetSelectedSlotIndex` | `0x004aec80-0x004aec8e` | [UID:0002JP][0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex](by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md) resolves the selected row payload and returns payload byte `+0x00`, the inventory slot index. |
| `DrawListEntry` | `0x004aec90-0x004af031` | [UID:0002JQ][0x004aec90-0x004af031.MyItemListPaneDrawListEntry](by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md) draws selected-row fill, item icon, and truncated item name for one row. Uses [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md) plus `GetItemGlyphBounds`. |
| scalar deleting destructor target | [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md) | Shared list-pane destructor target used by this class's primary vtable and related list panes. |

## Layout Notes

- The constructor calls `ListPane::ListPane(524, 8, visibleRows, 24, 0, 1, 1)`.
- `visibleRows` is `205` in the default mode and `170` when `g_useHighResLayout == 1`.
- The row payload starts with the slot index and item identifiers, followed by a wide item-name string copied from the player item slot.
- The draw entry layout has the item icon id at `+0x02`, style/category byte at `+0x04`, and inline wide string text at `+0x06`.
- `DrawListEntry` branches on `g_useEpfAssets`: EPF mode calls `ItemObjImageLib::DrawItemImageScaled`, while legacy mode calls `ItemObjImageLib::DrawItemImage`.

## Evidence Notes

- IDA MCP confirms `0x004aeb30` as a 0x147-byte function and `0x004aec90` as a 0x3a1-byte function.
- 2026-05-26 IDA MCP vtable pass confirms primary/secondary/tertiary vtables at `0x00619f28`, `0x00619fb0`, and `0x00619fe0`, installed by constructor stores at `0x004aeb9a`, `0x004aeba5`, and `0x004aebb1`.
- IDA MCP constructor caller fanout ties this class to `ClanDepItemDialog`, `AddItemDialog`, and `MixItemDialog`.
- IDA MCP on 2026-05-25 reports `0x004aec90` callees including `0x004df460` (`GetItemGlyphBounds`), `0x004df2c0` (`DrawItemImageScaled`), `0x004dee50` (`DrawItemImage`), `0x004ba820` text fitting, and `0x004bab70` wide text drawing.
- Active generated output omits the draw method body and has suspect global ownership for the slot-count source; see [wave3_data_issues](../wave3_data_issues.md) and [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md).
- Current generated metadata reports `vtable_count: 0`; use the IDA-backed vtable page for layout evidence.
- 2026-05-26 recheck: IDA decompilation reads the constructor slot count from `dword_69AE0C + 0x284`, not the effect image library. Current docs track that singleton as [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md), while the final field name remains unresolved.

## Cross-References

- [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md)
- [UID:00014U][0x004aeb30-0x004af031.MyItemListPane](by-memory/0x004aeb30-0x004af031.MyItemListPane.md)
- [UID:0002JO][0x004aeb30-0x004aec77.MyItemListPaneConstructor](by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md)
- [UID:0002JP][0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex](by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md)
- [UID:0002JQ][0x004aec90-0x004af031.MyItemListPaneDrawListEntry](by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md)
- [UID:0001Y8][MyItemListPaneVtables](by-type/by-vtable/MyItemListPaneVtables.md)
- [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md)
- [UID:0001VE][MyItemListPaneEntryLayouts](by-type/by-struct/MyItemListPaneEntryLayouts.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000UQ][GetItemGlyphBounds_004DF460](by-item/GetItemGlyphBounds_004DF460.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:00007A][ListPane](by-class/ListPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `82/78`. Summary: the inventory item picker list is well documented across constructor/draw behavior, layout, vtables, caller fanout, item image dependencies, shared destructor, and generated data caveats, but source-file split and some globals/slot fields remain medium confidence. Evidence: linked `MyItemListPane` memory page, vtable/type docs, IDA constructor/draw/vtable checks, `g_pItemObjImageLib`, `g_activeUserStatusPane`, and `ScopedMarkerMissingMethodBodies` note.
- Reconstructability/child split update: existed before as `RECONSTRUCTABLE` blank, confidence `78`, and only constructor/draw method rows; changed to `RECONSTRUCTABLE:TRUE`, confidence `82`, and exact child links for constructor, selected-slot helper, and draw method. Evidence: 2026-05-31 IDA MCP confirmed the real `0x004aec80-0x004aec8e` helper inside the previous padding gap plus exact constructor/draw boundaries and row payload behavior.
