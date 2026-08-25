*** UID:00007A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "ListPane.h"
#include "../../util/List.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_CONTROLS_LISTPANE_H
#define NEXUSTK_UI_CONTROLS_LISTPANE_H

#include "../core/ScrollBar.h"

class List;
class MouseEvent;
struct PaneKeyEvent;

class ListPane : public ScrollablePane
{
public:
    ListPane(int entrySize, int listWidth,
             short viewportHeight, short rowHeight,
             bool horizontalScrollEnabled,
             bool verticalScrollEnabled,
             signed char columnCount);
    virtual ~ListPane();

    [[CHILDREN]]

protected:
    virtual void OnListAction() {}
    virtual void GetItemRect(int rowIndex, RectBounds *outBounds);
    virtual void OnItemSelected(int rowIndex, int notify);
    virtual void OnItemActivated() {}
    virtual void DrawListEntry(int rowIndex, void *rowData,
                               RectBounds *rowBounds) {}

    List *m_items;
    int m_selectedIndex;
    List *m_selectionFlags;
    unsigned char m_multipleSelectionEnabled;
    Point m_itemSize;
    signed char m_columnCount;
    unsigned char m_dragSelectionActive;
};

typedef char ListPaneSizeMustBe332[
    sizeof(ListPane) == 0x14c ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ListPane

## UID0000LO Gate 2A U1-U5 Source Closure - 2026-08-14

UID0003U1-UID0003U5 now contribute all source-bearing scroll-metric, mouse/key,
paint/hit-test/geometry, selection/navigation, and ensure-visible definitions
plus every required class declaration. UID0003U4 separately disposes the
unreferenced raw clamp body and compiler frame shim; UID0003U5 separately
disposes both destructor adjustors and the scalar deleting wrapper. The class H
now forward-declares `MouseEvent` and `PaneKeyEvent` before ordered child
declarations. No U1-U5 reconstructable channel remains blank. Completion and
confidence rise from `94/93` to `95/94`.

## UID0000LO Accepted Class And Header Route - 2026-08-14

UID00007A owns one coherent `ListPane.cpp`/`ListPane.h` class route through
UID0000KT. CPP includes its own header and `../../util/List.h`, then emits the
ordered class children. H includes ScrollBar, forward-declares List, owns the
constructor/destructor, all child declarations, five protected virtual slots,
exact recovered fields, and the `0x14c` size guard.

The virtual surface preserves three shared no-op slots (`OnListAction`,
`OnItemActivated`, and default `DrawListEntry`) while `GetItemRect` and
`OnItemSelected` retain their non-empty child implementations. The renderer ABI
is generic `void *` plus `RectBounds *`, allowing MyItemListPane to override the
same slot without typed-parameter drift. Child H declarations are inserted only
at the public `[[CHILDREN]]` marker.

The field contract is `m_items`, `m_selectedIndex`, `m_selectionFlags`, one-byte
multiple-selection flag, `m_itemSize`, signed column count, and drag-selection
byte. Invalidation uses inherited `m_contentRect` for item-storage changes and
`m_scrollContentRect` for multiple-selection reset. UID0000NQ's later research
section below is preserved as integration history, but its conflicting
constructor/field proposal is superseded for this B008 accepted route.

## UID0000NQ Base Header Closure - 2026-08-14

UID00007A now owns one coherent `ListPane.cpp`/`ListPane.h` class route through
UID0000KT. CPP includes its own header and `../../util/List.h`, then emits the
ordered class children. H uses guard `NEXUSTK_UI_CONTROLS_LISTPANE_H`, includes
`../core/ScrollBar.h`, forward-declares `List`, owns the constructor/destructor,
routes all current child declarations inside the class, declares the selection
hook, and preserves exact `+0x110..+0x14b`
state with explicit tail padding.

The generated dependency is complete: `ScrollBar.h` declares `ScrollablePane`,
`RectBounds`, and `Point`; `List` is completed only in CPP. The inherited base
ends at `+0x110`, and the listed fields close `ListPane` at `0x14c`. This makes
[UID:0000D8][SimpleListPane](by-class/SimpleListPane.md) a compilable standalone
derived-class sibling whose `SimpleListPane.h` includes this header. No
SimpleListPane method is folded into the base module, and compiler thunks,
vtables, COLs, and RTTI remain no-literal-source output.

## Status

- Confidence: strong for reusable list-control ownership.
- Likely source file: [UID:0000KT][ListPane](by-file/ListPane.md)
- Address range: [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)
- Historical recovered output scattered shared methods under `class_ArticleListPane.cpp`, `class_ChattingColorListPane.cpp`, `class_ServerItemMenuItemList.cpp`, and `class_SelectionState.cpp`. Those are caller-biased generated placements, not current source ownership.
- Reconstruction route: all exact source-bearing method children emit once through this class's single `[[CHILDREN]]` CPP route and then [UID:0000KT][ListPane](by-file/ListPane.md). UID0003U0 and UID000194 remain non-emitting indexes.
- The item/selection family has thirteen exact UID0003U0 method pages plus the now source-complete UID0003U1-UID0003U5 clusters.

## Class Purpose

`ListPane` is the reusable selectable list/grid pane used by board, mail, clan, exchange, menu, spell, server-select, phone-book, user-list, power-dialog, and other UI flows. It derives from [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md), owns a primary item list at `+0x130`, tracks a selected index at `+0x134`, owns a selection flag list at `+0x138`, and provides virtual hooks for item rectangles, drawing, selection change, double-click activation, and scroll metrics.

Feature panes such as [UID:00000L][ArticleListPane](by-class/ArticleListPane.md) and [UID:0000FO][UserListPane](by-class/UserListPane.md) supply row-specific drawing and behavior. The shared insert/remove/count/selection helpers should stay with `ListPane`, not with those feature panes.

## Method Notes

| Method or role | Address | Notes |
| --- | --- | --- |
| Constructor | `0x004f3a50-0x004f3b5b` | Calls `ScrollablePane`, installs three `ListPane` vptrs, allocates two `List` objects, stores dimensions/selection state, and marks the pane visible. Its final parameter is `signed char columnCount` stored at `+0x148`; multiple-selection state is the separate byte at `+0x13c`. |
| Non-deleting destructor core | `0x004f3b60-0x004f3ba5` | Restores `ListPane` vptrs, destroys the two owned lists, then chains to `ScrollablePane`/base cleanup. Called by derived destructors. |
| `GetItemSize` | [UID:000500][0x004f3bb0-0x004f3bcb.ListPaneGetItemSize](by-memory/0x004f3bb0-0x004f3bcb.ListPaneGetItemSize.md) | Returns `Point m_itemSize` through MSVC hidden-result lowering; retained body has no current route. |
| `GetItemCount` | [UID:000501][0x004f3bd0-0x004f3bdf.ListPaneGetItemCount](by-memory/0x004f3bd0-0x004f3bdf.ListPaneGetItemCount.md) | Returns `m_items->GetCount()` or zero; 69 call sites. |
| `GetRowCount` | [UID:000502][0x004f3be0-0x004f3bfb.ListPaneGetRowCount](by-memory/0x004f3be0-0x004f3bfb.ListPaneGetRowCount.md) | Uses signed `m_columnCount` and preserves non-null empty-list arithmetic; retained body has no current route. |
| `InsertItem` | [UID:000503][0x004f3c00-0x004f3c4b.ListPaneInsertItem](by-memory/0x004f3c00-0x004f3c4b.ListPaneInsertItem.md) | Inserts one primary item and one zero selection byte, synchronizes scrollbars, and invalidates `m_itemBounds`; 12 calls. |
| `AddEntry` | [UID:000504][0x004f3c50-0x004f3ca4.ListPaneAddEntry](by-memory/0x004f3c50-0x004f3ca4.ListPaneAddEntry.md) | Appends at the current item count and mirrors a zero selection byte; 47 calls. |
| `InsertItems` | [UID:000505][0x004f3cb0-0x004f3cfd.ListPaneInsertItems](by-memory/0x004f3cb0-0x004f3cfd.ListPaneInsertItems.md) | Bulk indexed insertion; preserves the compiled one-zero-byte selection payload shape; retained body has no current route. |
| `AddEntries` | [UID:000506][0x004f3d00-0x004f3d56.ListPaneAddEntries](by-memory/0x004f3d00-0x004f3d56.ListPaneAddEntries.md) | Bulk tail append with the same one-zero-byte selection payload shape; retained body has no current route. |
| `RemoveItems` | [UID:000507][0x004f3d60-0x004f3db7.ListPaneRemoveItems](by-memory/0x004f3d60-0x004f3db7.ListPaneRemoveItems.md) | Removes matching ranges, syncs/invalidate, clears selected index, then calls `OnItemSelected(-1,false)`; 37 calls. |
| `GetItem` | [UID:000508][0x004f3dc0-0x004f3dcf.ListPaneGetItem](by-memory/0x004f3dc0-0x004f3dcf.ListPaneGetItem.md) | Generic explicit-index primary-list accessor; `GetSelectedEntry` is caller bias only; 98 calls. |
| `SetMultipleSelectionEnabled` | [UID:0004LX][0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled](by-memory/0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled.md) | If byte `+0x13c` changes, stores it, obtains the raw byte buffer from selection-list `+0x138`, clears exactly its current count backwards, and invalidates bounds at `+0x120`. AddItemDialog passes its constructor flag in EPF mode and forces one in EPD mode. Historical generated name `SetSortEnabled` is rejected. |
| `GetSelectionCount` | [UID:0004M9][0x004f3e20-0x004f3e74.ListPaneGetSelectionCount](by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md) | Exact `int ListPane::GetSelectionCount() const`: returns whether signed `m_selectedIndex >= 0` in single-select mode, otherwise counts every nonzero byte from `m_selectionFlags->GetData()` across `GetCount()`. The historical `SelectionState` emission is superseded alias pollution. |
| `GetSelectedIndices` | [UID:000509][0x004f3e80-0x004f3ef7.ListPaneGetSelectedIndices](by-memory/0x004f3e80-0x004f3ef7.ListPaneGetSelectedIndices.md) | Exports single- or multiple-selection indices up to caller capacity; 19 calls. |
| `IsItemSelected` | [UID:00050A][0x004f3f00-0x004f3f1b.ListPaneIsItemSelected](by-memory/0x004f3f00-0x004f3f1b.ListPaneIsItemSelected.md) | Tests one explicit row's parallel selection byte; 26 calls. |
| Scroll metrics | `0x004f3f20-0x004f4140` | Computes scroll range, overflow count, page size, scroll offsets, content size, and scroll delta. |
| Mouse/key input | `0x004f4190-0x004f43cd` | Handles drag selection, click/double-click, mouse capture through `g_pEventManager`, arrow keys, and page navigation. |
| Paint/hit testing | `0x004f43e0-0x004f45a2` | Iterates visible items, computes item rectangles, hit-tests, and dispatches row drawing through virtual methods. |
| Selection update | `0x004f45b0-0x004f47b1` | Updates single/multi/range selection state and invalidates the dirty selection rectangle. Source-facing call sites may spell the programmatic row update as `SetSelectedIndex(row, notify)` or `SelectItem(row, notify)`, while derived override pages may still describe the slot role as `OnItemSelected`. |
| Navigation helpers and raw fragments | `0x004f47c0-0x004f4919` | Moves selection up/down or by page, ensures visibility, and invokes the selection virtual. The refreshed by-memory audit also records unpromoted raw code at `0x004f4820-0x004f487c` and a frame shim at `0x004f4910-0x004f4919`. |
| `EnsureItemVisible` | `0x004f4920-0x004f49e0` | Scrolls the containing `ScrollablePane` so a target item rectangle is visible. |
| Destructor and thunks | `0x004f49e0-0x004f4a77` | Two adjustor thunks plus the scalar deleting destructor. |

## Item And Selection Method Declarations

The accepted source-facing declarations form one coherent class API. Each exact child owns its corresponding formal `RECONSTRUCTION_H CODE`; this table documents those formal channels without creating a second sample-code block.

| Child | Formal declaration contract |
| --- | --- |
| UID000500 | `Point GetItemSize() const` |
| UID000501 | `int GetItemCount() const` |
| UID000502 | `int GetRowCount() const` |
| UID000503 | `void InsertItem(int index, void *item)` |
| UID000504 | `void AddEntry(void *item)` |
| UID000505 | `void InsertItems(int index, int count, void *items)` |
| UID000506 | `void AddEntries(int count, void *items)` |
| UID000507 | `void RemoveItems(int index, int count)` |
| UID000508 | `void *GetItem(int index)` |
| UID0004LX | `void SetMultipleSelectionEnabled(unsigned char enabled)` |
| UID0004M9 | `int GetSelectionCount() const` |
| UID000509 | `int GetSelectedIndices(int *indices, int maxCount) const` |
| UID00050A | `bool IsItemSelected(int index) const` |

These are documentation of the exact formal child H contracts, not duplicate illustrative source. Exact bodies and declarations remain confined to UID000500-UID00050A and UID0004LX/UID0004M9. The full historical class declaration remains broader than this callback and is not invented from an incomplete IDA UDT.

## Item And Selection Field Map

| Offset | Source-facing field | Evidence and use |
| --- | --- | --- |
| `+0x110` | `m_itemBounds` | Invalidated after insertion/removal; distinct from the content rectangle. |
| `+0x120` | `m_contentBounds` | Invalidated when multiple-selection mode changes. |
| `+0x130` | `List *m_items` | Primary typed-record storage used by count/insert/remove/get/row methods. |
| `+0x134` | `int m_selectedIndex` | Signed single-selection index; reset to `-1` after removal. |
| `+0x138` | `List *m_selectionFlags` | Parallel one-byte-per-item selection storage. |
| `+0x13c` | `unsigned char m_multipleSelectionEnabled` | Chooses single/multiple selection behavior and is changed by UID0004LX. |
| `+0x140/+0x144` | `Point m_itemSize` | Eight-byte item dimensions returned by UID000500. |
| `+0x148` | `signed char m_columnCount` | Constructor tail, UID000502 divisor, and scroll-metric input; values such as 16 reject Boolean typing. |

The spellings are behavior- and subsystem-backed source inference, not recovered symbols. Their offset/type/role evidence is strong enough for human source and avoids raw `field_`/`dword_` names. No complete IDA `ListPane` UDT is asserted or required.

## Evidence Notes

- IDA MCP confirms real functions at `0x004f3a50`, `0x004f3b60`, `0x004f3bd0`, `0x004f3c00`, `0x004f3c50`, `0x004f3d60`, `0x004f3dc0`, `0x004f3dd0`, `0x004f3e20`, `0x004f3e80`, `0x004f3f00`, and the active `ListPane` virtual block through `0x004f4a77`.
- Fresh UID0003U0 reanalysis also resolves retained complete raw bodies at `0x004f3bb0`, `0x004f3be0`, `0x004f3cb0`, and `0x004f3d00`. Each has zero current IDA/PE routes but exact ListPane fields, unique boundaries, neighboring family context, and formal source through UID000500/UID000502/UID000505/UID000506.
- Direct modeled call-site counts are 69 GetItemCount, 12 InsertItem, 47 AddEntry, 37 RemoveItems, 98 GetItem, 5 SetMultipleSelectionEnabled, 14 GetSelectionCount, 19 GetSelectedIndices, and 26 IsItemSelected.
- Constructor callers include board/article lists, chat color lists, clan lists, exchange lists, item/spell menu lists, server-select lists, phone-book lists, and user-list panes.
- Caller fanout for `GetItemCount`, append, indexed-entry, selection-count, selected-indices, and `IsItemSelected` spans many list subclasses. UID0004M9 alone has 14 callers at `0x004729a0`, `0x00474170`, `0x0047a320`, `0x004aea40`, `0x005194c0`, `0x0051ae50`, `0x0051c430`, `0x0051d6c0`, `0x0051e600`, `0x0051f250`, `0x0054fa20`, `0x00550c40`, `0x00574440`, and `0x0058cc40`, proving reusable ListPane ownership.
- UID0004M9 is exactly 84 bytes, 34 instructions, six CFG blocks, with a unique signature, four-byte predecessor padding, twelve-byte successor padding, and no function at its exclusive end. Its formal body uses the existing descriptive fields `m_multipleSelectionEnabled`, `m_selectedIndex`, and `m_selectionFlags`; lexical uncertainty caps `91/93` but does not block source.
- Exact helper `0x004f3dd0` is 76 bytes and has five code xrefs. It performs an early return when the one-byte value already matches; otherwise it writes `+0x13c`, calls List `GetData` and `GetCount` on the parallel selection list at `+0x138`, clears each byte, and dispatches ListPane invalidation through virtual slot `+0x20` with bounds `this+0x120`.
- [UID:0004BM][0x004ae4c0-0x004ae8f5.AddItemDialogConstructor](by-memory/0x004ae4c0-0x004ae8f5.AddItemDialogConstructor.md) calls the helper at `0x004ae652` with `allowMultipleSelection` and at `0x004ae803` with literal one. Other callers `0x0047496a`, `0x0047928a`, and `0x0047982c` establish generic ListPane ownership.
- No caller consumes AL, so source return is `void`. No sort field, comparison, reorder, or ordering operation exists; generated `SetSortEnabled` is historical ownership/name pollution. Descriptive fields `m_multipleSelectionEnabled`, `m_selectionFlags`, and `m_contentBounds` are behavior-backed but not symbol-recovered, which leaves the class score unchanged.
- 2026-06-21 B005 chat-color support pass clarifies two call-site-sensitive names used by [UID:0002G8][0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor](by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md): `0x004f3dc0` is an explicit-index item accessor when the caller pushes a loop/row index, and primary vtable slot `+0x78`/`0x004f45b0` is the inherited selection update/change virtual that may be source-spelled as `SetSelectedIndex(row, notify)` at programmatic-selection call sites.
- 2026-06-19/21 B007 reanalysis of [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) confirms from local PE bytes that `0x004f3dc0` loads the primary list at `this+0x130`, loads its vtable, restores the frame, and tail-dispatches slot `+0x10` with the caller-supplied index still on the stack. Therefore `GetSelectedEntry` should be retained only as a historical/generated or call-site alias when callers pass selected index `+0x134`; the reusable helper role is `GetItem(row)` / `GetEntryAt(row)`.
- 2026-06-19/22 B014 verification of the same [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) helper corroborates that `0x004f3dc0` preserves the caller-supplied index for the primary-list vtable slot `+0x10`, while selected-entry behavior belongs only to callers that pass selected index `+0x134`. Keep `GetItem(row)` / `GetEntryAt(row)` as the reusable source-facing role until the final ListPane header spelling is recovered.
- 2026-05-26 IDA `py_eval` recheck confirmed 14 xrefs and no `SelectionState` RTTI/name evidence. UID0004M9 now formalizes that conclusion: `SelectionState` is a superseded generated alias, not the owner.
- Historical 2026-06-06 audit found the unmodeled `0x004f4820-0x004f487c` clamp/notify body and requested split/name follow-up. The current UID0003U4 callback preserves that evidence and closes it with an exact no-function/no-xref/no-PE-route, behavior-covered-by disposition rather than a speculative standalone source method.
- 2026-06-21 B009 MailDeleteReplyAlert support pass records a mail reply-list callsite: [UID:0002T9][0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete](by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md) calls `GetSelectedIndices` with a 256-entry stack buffer in bulk delete mode, then uses `RemoveItems(index - alreadyRemovedCount, 1)`; single-reply mode also uses `RemoveItems(row, 1)` after a `MailListPane::FindMailIdIndex` lookup.

## Source Layout Decision

Keep `ListPane` in `NexusTK/ui/controls/ListPane.cpp` through [UID:0000KT][ListPane](by-file/ListPane.md). Do not fold it into `BoardDialogs.cpp`, `Chatting.cpp`, item-menu files, `SelectionState`, or `ScrollBar.cpp`. It depends on [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md), but the behavior is selectable list/grid control logic rather than scrollbar drawing. The class has one CPP `[[CHILDREN]]` route; exact method children own their formal CPP/H and no broad aggregate emits duplicate source.

## Score Rationale

- Completion `95` reflects the complete item/selection family, exact declarations, field map, constructor/destructor route, and fully populated UID0003U1-UID0003U5 CPP/H channels with compiler/raw no-code dispositions.
- Confidence `94` reflects fresh exact offsets, behavior, vtable slots, call counts, raw-fragment dispositions, and class/file placement. It remains below 95 only because original lexical spellings are stripped.

## Cross-References

- [UID:0000KT][ListPane](by-file/ListPane.md)
- [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)
- [UID:0003TZ][0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor](by-memory/0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md)
- [UID:0003U0][0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers](by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md)
- [UID:000500][0x004f3bb0-0x004f3bcb.ListPaneGetItemSize](by-memory/0x004f3bb0-0x004f3bcb.ListPaneGetItemSize.md)
- [UID:000501][0x004f3bd0-0x004f3bdf.ListPaneGetItemCount](by-memory/0x004f3bd0-0x004f3bdf.ListPaneGetItemCount.md)
- [UID:000502][0x004f3be0-0x004f3bfb.ListPaneGetRowCount](by-memory/0x004f3be0-0x004f3bfb.ListPaneGetRowCount.md)
- [UID:000503][0x004f3c00-0x004f3c4b.ListPaneInsertItem](by-memory/0x004f3c00-0x004f3c4b.ListPaneInsertItem.md)
- [UID:000504][0x004f3c50-0x004f3ca4.ListPaneAddEntry](by-memory/0x004f3c50-0x004f3ca4.ListPaneAddEntry.md)
- [UID:000505][0x004f3cb0-0x004f3cfd.ListPaneInsertItems](by-memory/0x004f3cb0-0x004f3cfd.ListPaneInsertItems.md)
- [UID:000506][0x004f3d00-0x004f3d56.ListPaneAddEntries](by-memory/0x004f3d00-0x004f3d56.ListPaneAddEntries.md)
- [UID:000507][0x004f3d60-0x004f3db7.ListPaneRemoveItems](by-memory/0x004f3d60-0x004f3db7.ListPaneRemoveItems.md)
- [UID:000508][0x004f3dc0-0x004f3dcf.ListPaneGetItem](by-memory/0x004f3dc0-0x004f3dcf.ListPaneGetItem.md)
- [UID:0004LX][0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled](by-memory/0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled.md)
- [UID:0004M9][0x004f3e20-0x004f3e74.ListPaneGetSelectionCount](by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md)
- [UID:000509][0x004f3e80-0x004f3ef7.ListPaneGetSelectedIndices](by-memory/0x004f3e80-0x004f3ef7.ListPaneGetSelectedIndices.md)
- [UID:00050A][0x004f3f00-0x004f3f1b.ListPaneIsItemSelected](by-memory/0x004f3f00-0x004f3f1b.ListPaneIsItemSelected.md)
- [UID:0004BM][0x004ae4c0-0x004ae8f5.AddItemDialogConstructor](by-memory/0x004ae4c0-0x004ae8f5.AddItemDialogConstructor.md)
- [UID:0003U1][0x004f3f20-0x004f4190.ListPaneScrollMetricVirtuals](by-memory/0x004f3f20-0x004f4190.ListPaneScrollMetricVirtuals.md)
- [UID:0003U2][0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables](by-memory/0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables.md)
- [UID:0003U3][0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry](by-memory/0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry.md)
- [UID:0003U4][0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers](by-memory/0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers.md)
- [UID:0003U5][0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks](by-memory/0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks.md)
- [UID:0000CS][SelectionState](by-class/SelectionState.md) historical generated-alias support only; UID0004M9 is the source owner.
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md)
- [UID:00000L][ArticleListPane](by-class/ArticleListPane.md)
- [UID:0000FO][UserListPane](by-class/UserListPane.md)
- [UID:0000ET][TextMenuItemList](by-class/TextMenuItemList.md)
- [UID:0000AQ][PowerListPane](by-class/PowerListPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-08-14 Agent-B009 UID0000NQ generated-readback correction: current child H routing now supplies `SetMultipleSelectionEnabled` and `GetSelectionCount`; removed only the two duplicate explicit declarations from the class envelope so each method remains declared exactly once inside `ListPane`. Guard, dependency, constructor/destructor, selection hook, fields/padding, and every child declaration are unchanged.
- 2026-08-14 Agent-B009 UID0000NQ accepted callback: installed the exact guarded ListPane support H and exact CPP include envelope required by standalone `SimpleListPane.h`; added the derived-class/dependency cross-link while preserving `94/93`, UID0000KT ownership/emission, the existing method inventory, and the in-class child route.

- 2026-08-02 B008 UID0003U0 accepted implementation callback: raised `90/88` to `93/92`; incorporated validator-issued UID000500-UID00050A, preserved UID0004LX/UID0004M9, documented the complete method declaration surface and offset-backed field map, corrected constructor-tail `signed char columnCount`, retained the single `[[CHILDREN]]` CPP route, and superseded caller-specific/`SelectionState`/`SetSortEnabled` source pollution without inventing a complete IDA UDT.

- 2026-07-13 B005 UID0004BP implementation callback: score/formal class route unchanged at `90/88`; linked validator-issued UID0004M9, complete formal body/field/CFG/padding/14-caller evidence, target consumer, and superseded `SelectionState` alias while preserving UID0004LX and every unrelated raw-helper blocker.

- 2026-07-13 B001 UID0004BM callback: score unchanged at `90/88`; added the exact UID0004LX setter child, its five-call-site/body/void-return evidence, AddItemDialog and cross-feature callers, descriptive field rationale, rejection of generated `SetSortEnabled`, and the managed `[[CHILDREN]]` emission route without claiming a complete ListPane declaration.

- 2026-06-16 Supervisor: Added exact executable child cross-references [UID:0003TZ][0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor](by-memory/0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md)-[UID:0003U5][0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks](by-memory/0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks.md) from the accepted B001 ListPane source-split audit. Class score remains `90/88`; final C++ remains blocked on original helper names, field names, and raw helper reachability.
- Completion/confidence score update: existed before as `0/0`; changed to `90/88`. Summary: the reusable selectable list control is documented in high detail across construction, owned lists, selection, scrolling, hit testing, virtual dispatch, generated ownership pollution, and source layout decision. Evidence: linked full by-memory range, IDA-confirmed helper starts, vtable/RTTI evidence, broad subclass caller fanout, and `SelectionState` alias analysis.
- 2026-06-05: Marked reconstructable and attached to [UID:0000KT][ListPane](by-file/ListPane.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the reusable selectable list control unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000KT`; left the C++ block blank because the page is below the final reconstruction bar.
  - Summary/evidence: live IDA MCP reconfirms the core starts at `0x004f3a50`, `0x004f3b60`, `0x004f3bd0`, `0x004f3c00`, `0x004f3c50`, `0x004f3d60`, `0x004f3e20`, and `0x004f49e0`, with broad subclass caller fanout. The class score `90/88` and parent score `88/84` meet the 80/80 attachment gate.
- 2026-06-06 A007: Synchronized the method/evidence notes with [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md) after live IDA disassembly confirmed `0x004f4820-0x004f487c` is unpromoted raw ListPane code rather than padding or a purely stale disabled-source lead. No score or C++ changes.
- 2026-06-21 B005 Rule 26 support incorporation: no score change. Refined `0x004f3dc0` from unconditional `GetSelectedEntry` wording to explicit-index `GetItem`/`GetEntryAt` semantics and documented the source-facing `SetSelectedIndex(row, notify)` role for slot `+0x78` call sites.
- 2026-06-21 B007 Rule 26 support incorporation: no score change. Added byte-backed [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) evidence that `0x004f3dc0` preserves the caller-supplied row/index for primary-list vtable slot `+0x10`, confirming `GetSelectedEntry` is caller bias rather than the final helper name.
- 2026-06-22 B014 Rule 26 support incorporation: no score change. B014 corroborates the indexed `0x004f3dc0`/`ListPane::GetItem(row)` model from [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) and keeps `GetSelectedEntry` only as a caller-side historical alias.
- 2026-06-21 B009 Rule 26 support incorporation: no score change. Added MailDeleteReplyAlert callsite evidence for `GetSelectedIndices` and `RemoveItems`.
