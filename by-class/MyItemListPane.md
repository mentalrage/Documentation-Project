*** UID:00008W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../controls/ListPane.h"
#include "../core/RectBounds.h"

[[CHILDREN]]

class MyItemListPane : public ListPane
{
public:
    MyItemListPane();
    unsigned char GetSelectedSlotIndex();

protected:
    virtual void DrawListEntry(
        int rowIndex,
        void *rowData,
        RectBounds *rowBounds);
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MyItemListPane

## UID0000LO Accepted ItemDialogs Route - 2026-08-14

This complete `0x14c` ListPane-derived class now emits through
[UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) at position `20`, between
AddItemDialog (`10`) and AddItemWithCountDialog (`30`). The CPP channel is only
`[[CHILDREN]]`; the H channel owns the includes, child declarations, and class
declaration. [UID:0001VE][MyItemListPaneEntryLayouts](by-type/by-struct/MyItemListPaneEntryLayouts.md)
emits first in the class header, while the constructor, selected-slot accessor,
and generic virtual row renderer emit in positions `10/20/30` through this
class. UID0000LO is retained only as historical whole-file research and does
not emit a standalone source file.

The base declaration is the accepted [UID:00007A][ListPane](by-class/ListPane.md)
header route. The override keeps the binary virtual ABI
`(int, void *, RectBounds *)`; constness is introduced only by the body cast.
The class adds no recovered data field beyond the `0x14c` base size and has no
handwritten destructor. Its primary renderer override is at vtable slot
`+0x80`; secondary/tertiary views and their destructor adjustors remain
compiler-only.

The older split-candidate wording below is historical and superseded by this
accepted current route.

## Status

- Confidence: strong for confirmed functions, row payload support, and class-owned child emission; medium-high for exact source-file split and final source-facing method/API spellings.
- Likely source file: [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md), or folded into [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md) if final source layout favors compact item-dialog files.
- Parent/C++ status: attached to [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md), the validator-managed `NexusTK/ui/dialogs/MyItemListPane.cpp` split-candidate root. The class formal block intentionally contains only a route comment plus `[[CHILDREN]]` so class-owned children can emit through the class while the complete source class declaration remains below final-audit confidence. [UID:0002JO][0x004aeb30-0x004aec77.MyItemListPaneConstructor](by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md), [UID:0002JP][0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex](by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md), and [UID:0002JQ][0x004aec90-0x004af031.MyItemListPaneDrawListEntry](by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md) now emit first-draft bodies through this route.
- Current recovered file: `source-3/simroot_v2/class_MyItemListPane.cpp`
- Vtables: [UID:0001Y8][MyItemListPaneVtables](by-type/by-vtable/MyItemListPaneVtables.md) at `0x00619f28`, `0x00619fb0`, and `0x00619fe0`
- Parent gate: this class now clears `86/88`, supporting direct attachment of the vtable/type pages and the class-owned method children while preserving the broad class declaration below the 95/95 gate.

## Class Purpose

`MyItemListPane` displays the local player's own inventory items as selectable rows. It is a feature-specific `ListPane` subclass used when dialogs need the user to pick an item from their inventory. [UID:0004BM][0x004ae4c0-0x004ae8f5.AddItemDialogConstructor](by-memory/0x004ae4c0-0x004ae8f5.AddItemDialogConstructor.md) creates it as a local, configures inherited multiple-selection state through [UID:0004LX][0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled](by-memory/0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled.md), and transfers ownership to ScrollableControlPane; it is not stored as an AddItemDialog member.

[UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md) later reaches this dynamic MyItemListPane only through DialogPane selector `3`'s ScrollableControlPane and its `GetScrollablePane()` accessor, then calls inherited [UID:0004M9][0x004f3e20-0x004f3e74.ListPaneGetSelectionCount](by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md). This does not create an AddItemDialog list member or transfer UID0004M9 ownership from generic ListPane.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MyItemListPane` | `0x004aeb30-0x004aec77` | [UID:0002JO][0x004aeb30-0x004aec77.MyItemListPaneConstructor](by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md) builds a `ListPane` with row payload size `0x20c`, count/capacity argument `8`, mode-dependent extent `205/170`, row dimension `24`, enumerates player inventory slots, and appends active item rows. |
| `GetSelectedSlotIndex` | `0x004aec80-0x004aec8e` | [UID:0002JP][0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex](by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md), now `88/92`, emits `unsigned char MyItemListPane::GetSelectedSlotIndex()` through this class route; it resolves the selected row payload through the inherited selected-index `ListPane` access path and returns `MyItemListEntry::slotIndex` at payload `+0x00`. |
| `DrawListEntry` | `0x004aec90-0x004af031` | [UID:0002JQ][0x004aec90-0x004af031.MyItemListPaneDrawListEntry](by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md), now `88/90`, draws selected-row fill, item icon, and truncated item name for one row. It is class-owned/emitted by UID00008W and uses [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md) plus `GetItemGlyphBounds`. |
| inherited `GetSelectionCount` | [UID:0004M9][0x004f3e20-0x004f3e74.ListPaneGetSelectionCount](by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md) | Generic ListPane method; AddItemDialog reaches it on this dynamic subclass through the separately owned ScrollableControlPane child, not through a MyItemListPane override or AddItemDialog member. |
| scalar deleting destructor target | [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md) | Shared list-pane destructor target used by this class's primary vtable and related list panes. |

## Layout Notes

- The constructor calls `ListPane::ListPane(sizeof(MyItemListEntry), 8, g_useHighResLayout ? 170 : 205, 24, 0, true, true)`.
- The `205/170` argument is a mode-dependent ListPane extent/dimension, not a proven visible-row count. The first argument is the `0x20c` row payload size.
- The row payload starts with the slot index and item identifiers, followed by a wide item-name string copied from the player item slot.
- The constructor copies text with an explicit `_wcscpy_s(..., 0x100, ...)` count; the row payload's padding bytes at `+0x01` and `+0x05` remain uninitialized.
- The source-facing row payload is `MyItemListEntry`: inventory slot byte at `+0x00`, padding at `+0x01`, item icon id at `+0x02`, style/category byte at `+0x04`, padding at `+0x05`, and inline wide string text at `+0x06`.
- `GetSelectedSlotIndex` consumes the same `MyItemListEntry` declaration as the constructor and draw method: the constructor writes `slotIndex`, the accessor returns it, and the draw method ignores it while using `itemId`, `iconStyle`, and `displayName`.
- `DrawListEntry` branches on `g_useEpfAssets`: EPF mode clips a half-size destination and calls `ItemObjImageLib::DrawItemImageScaled`, while legacy mode centers the full glyph and calls `ItemObjImageLib::DrawItemImage` with no overlay and zero overlay strength.

## Evidence Notes

- IDA MCP confirms `0x004aeb30` as a 0x147-byte function and `0x004aec90` as a 0x3a1-byte function.
- 2026-05-26 IDA MCP vtable pass confirms primary/secondary/tertiary vtables at `0x00619f28`, `0x00619fb0`, and `0x00619fe0`, installed by constructor stores at `0x004aeb9a`, `0x004aeba5`, and `0x004aebb1`.
- IDA MCP constructor caller fanout ties this class to `ClanDepItemDialog`, `AddItemDialog`, and `MixItemDialog`.
- The exact AddItemDialog constructor has two MyItemListPane allocation sites, `0x004ae643` and `0x004ae7f5`. EPF mode immediately calls UID0004LX with the constructor's `allowMultipleSelection` byte; EPD mode passes literal one. Both then pass the local pointer to ScrollableControlPane with branch-specific bounds/inset.
- No UID0004BM instruction stores the local pointer in AddItemDialog, and exact AddItemDialog size `0x270` leaves no claimed list field. This supersedes the historical generated `m_itemList = new MyItemListPane(this)` member shape; ownership is transferred through the wrapper constructor instead.
- The selection setter is inherited generic ListPane behavior, not a MyItemListPane method definition or source-owner transfer. UID0004LX retains ListPane owner/emitter and `ListPane.cpp` placement.
- The selection-count query is likewise inherited generic ListPane behavior. UID0004M9 retains owner/emitter UID00007A and `ListPane.cpp`; this class contributes only the dynamic receiver identity for the UID0004BP consumer route.
- IDA MCP on 2026-05-25 reports `0x004aec90` callees including `0x004df460` (`GetItemGlyphBounds`), `0x004df2c0` (`DrawItemImageScaled`), `0x004dee50` (`DrawItemImage`), `0x004ba820` text fitting, and `0x004bab70` wide text drawing.
- Older generated output omitted or used provisional output for the draw method body. UID0002JQ now carries the authoritative first-draft body; generated output should be refreshed through validators rather than edited manually. The slot-count source still has suspect generated global ownership; see [wave3_data_issues](../wave3_data_issues.md) and [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md).
- Current generated metadata reports `vtable_count: 0`; use the IDA-backed vtable page for layout evidence.
- 2026-05-26 recheck: IDA decompilation reads the constructor slot count from `dword_69AE0C + 0x284`, not the effect image library. Current docs track that singleton as [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md), while the final field name remains unresolved.
- 2026-06-11 live IDA MCP rechecked the function boundaries for constructor `0x004aeb30-0x004aec77`, selected-slot helper `0x004aec80-0x004aec8e`, and draw method `0x004aec90-0x004af031`; constructor vptr stores at `0x004aeb9a`, `0x004aeba5`, and `0x004aebb1`; the three vtable bases and RTTI locators; and the sole draw-method data xref at `0x00619fa8`.
- 2026-07-02 B003 callback incorporated the accepted UID0002JO report: active MCP session `supervisor_resume_20260629` confirmed constructor size `0x147`, four constructor callers from ClanDep/AddItem/Mix flows, ListPane argument vector `(0x20c, 8, 205/170, 24, 0, 1, 1)`, inventory count from `g_activeUserStatusPane->m_inventorySlotCount` at raw `+0x284`, UID0003U9 slot accessor use, row payload offsets, and ListPane append helper `0x004f3c50`.
- 2026-07-02 B004 UID0002JQ implementation callback resolves the draw child to `88/90`: live MCP in `supervisor_resume_20260629` reconfirmed `sub_4AEC90` size `0x3a1`, end boundary `0x004af031` as non-function, vtable-only xref `0x00619fa8`, zero direct callers, inherited ListPane callback shape, selected-row callback `0x0069b3fc`, EPF/legacy item-image branches, row payload offsets, and text-copy/fit/move/draw tail. The class `[[CHILDREN]]` route now supports this class-owned child emitter through [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md).
- UID0002JO now uses this class as `CANONICAL_OWNER` and `EMITTER_UIDS`; the class marker-only C++ block exists solely to pass class-owned child emissions through to [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md).
- 2026-07-05 B004 UID0002JP implementation callback resolves the selected-slot helper to `88/92`: current MCP session `supervisor_recovery_20260705` reconfirmed `sub_4AEC80` size `0x0e`, bytes `ff b1 34 01 00 00 e8 35 51 04 00 8a 00 c3`, callee `0x004f3dc0`, direct callers `0x0048a733` in `ClanDepItemDialog` and `0x0048b6ae` in `ClanBankPane`, and AddItem's inline-equivalent selected-row path. UID0002JP now uses this class as `CANONICAL_OWNER` and `EMITTER_UIDS`, with source-file placement still routed through [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md).

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | Constructor, selected-slot helper, draw method, row payload layout, vtable ownership, shared destructor/adjustor dependency, caller fanout, item-image draw dependencies, generated-data defects, class child-route marker, and source placement are now documented well enough to satisfy the direct-parent gate. UID0002JP is now source-ready through the class route in addition to UID0002JO and UID0002JQ. Completion remains capped because the broad class declaration, player inventory field names, and standalone-file versus ItemDialogs fold remain unresolved. |
| Confidence | 88 | Current IDA evidence strongly supports class ownership and the vtable/method attachment, including exact vtable stores, draw-slot dispatch, selected-slot helper bytes, selected-row ListPane lowering, and direct ClanDep/ClanBank caller contexts. Confidence remains below final-audit levels because generated metadata still omits the vtables and exact original source split/API spellings remain inferential. |

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
- [UID:0000UQ][0x004df460-0x004df4f9.GetItemGlyphBounds](by-memory/0x004df460-0x004df4f9.GetItemGlyphBounds.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [UID:0004BM][0x004ae4c0-0x004ae8f5.AddItemDialogConstructor](by-memory/0x004ae4c0-0x004ae8f5.AddItemDialogConstructor.md)
- [UID:0004LX][0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled](by-memory/0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled.md)
- [UID:0004M9][0x004f3e20-0x004f3e74.ListPaneGetSelectionCount](by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md)
- [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md)
- [UID:000029][ClanDepItemDialog](by-class/ClanDepItemDialog.md)
- [UID:0000I9][ClanBank](by-file/ClanBank.md)

## Changes

- 2026-07-13 B005 UID0004BP support synchronization: score/formal route unchanged at `86/88`; documented the selector-3 ScrollableControlPane wrapper path, dynamic MyItemListPane receiver, inherited UID0004M9 call, and negative AddItemDialog member/ownership-transfer evidence while preserving UID0004LX and all class-specific method/layout details.

- 2026-07-13 B001 UID0004BM callback: score/C++ unchanged at `86/88`; added exact AddItemDialog caller allocation sites, EPF dynamic versus EPD forced selection-mode configuration, borrowed-local ownership transfer to ScrollableControlPane, negative member-store evidence, and UID0004LX's retained generic ListPane ownership.

- Completion/confidence score update: existed before as `0/0`; changed to `82/78`. Summary: the inventory item picker list is well documented across constructor/draw behavior, layout, vtables, caller fanout, item image dependencies, shared destructor, and generated data caveats, but source-file split and some globals/slot fields remain medium confidence. Evidence: linked `MyItemListPane` memory page, vtable/type docs, IDA constructor/draw/vtable checks, `g_pItemObjImageLib`, `g_activeUserStatusPane`, and `ScopedMarkerMissingMethodBodies` note.
- Reconstructability/child split update: existed before as `RECONSTRUCTABLE` blank, confidence `78`, and only constructor/draw method rows; changed to `RECONSTRUCTABLE:TRUE`, confidence `82`, and exact child links for constructor, selected-slot helper, and draw method. Evidence: 2026-05-31 IDA MCP confirmed the real `0x004aec80-0x004aec8e` helper inside the previous padding gap plus exact constructor/draw boundaries and row payload behavior.

- 2026-06-06 A008 parent-chain pass:
  - Before: [UID:0001VE][MyItemListPaneEntryLayouts](by-type/by-struct/MyItemListPaneEntryLayouts.md) pointed at this class, but the class had no autogen parent, leaving the entry-layout page blocked by `autogen_parent_unknown`.
  - After: `AUTOGEN_PARENT_UID` is set to [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md), the current `NexusTK/ui/dialogs/MyItemListPane.cpp` split-candidate root.
  - Evidence: [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md) is assigned to that generated source root at `86/84`; this class is `82/82`; and constructor/helper/draw ranges, vtables, row-layout evidence, caller fanout, and item-image dependencies all align with that file while preserving the possible `ItemDialogs.cpp` fold caveat.
- 2026-06-11 Agent-A005 Batch 152:
  - Before: `82/82`, below the strict direct-parent gate for [UID:0001Y8][MyItemListPaneVtables](by-type/by-vtable/MyItemListPaneVtables.md).
  - After: `85/86`, with final C++ still blank.
  - Evidence: live IDA MCP rechecked exact method boundaries, primary/secondary/tertiary constructor vptr stores, RTTI-backed vtable bases, the single draw-method data xref, and neighboring vtable boundaries. Remaining uncertainty is final source naming and source-file split, not class ownership.
- 2026-07-02 B003 UID0002JO implementation callback:
  - Added marker-only `[[CHILDREN]]` C++ so class-owned child emitters route through the class without inventing a full class declaration.
  - UID0002JO is now class-owned/emitted through this page and retains file placement through [UID:0000LO][MyItemListPane](by-file/MyItemListPane.md).
  - Corrected constructor layout wording from "visibleRows 205/170" to mode-dependent extent/dimension and row payload size `0x20c`.
- 2026-07-02 B004 [UID:0002JQ][0x004aec90-0x004af031.MyItemListPaneDrawListEntry](by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md) implementation callback:
  - Score unchanged at `85/86`; the existing class route marker now supports UID0002JQ's class-owned/class-emitted first-draft body.
  - UID0002JQ is now `88/90`, `CANONICAL_OWNER:00008W`, `EMITTER_UIDS:00008W`, and carries formal `DrawListEntry` C++. No broad class declaration was added because class layout/source split remain below final audit.
  - Evidence: B004 live MCP rechecked `sub_4AEC90` size/end boundary, vtable-only dispatch through `0x00619fa8`, row payload fields, draw-state branch, EPF/legacy item-image calls, helper/global dependency ownership, and text-tail helpers.
- 2026-07-05 B004 [UID:0002JP][0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex](by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md) implementation callback:
  - Score raised from `85/86` to `86/88` because all three exact method children now carry first-draft source bodies or source support through this class route.
  - UID0002JP is now `88/92`, `CANONICAL_OWNER:00008W`, `EMITTER_UIDS:00008W`, `EMITTER_POSITION_OPTIONAL:20`, and emits formal `GetSelectedSlotIndex` C++ returning `MyItemListEntry::slotIndex`.
  - Evidence: current MCP reconfirmed exact UID0002JP bytes, `0x004f3dc0` selected-index lowering, direct ClanDep/ClanBank callers, AddItem inline-equivalent negative evidence, and pre-callback generated empty-marker state. The broad class declaration remains intentionally absent because exact original header/source split is still a confidence cap.
