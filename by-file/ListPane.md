*** UID:0000KT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ListPane

## UID0000LO Gate 2A U1-U5 File Closure - 2026-08-14

The canonical file route now emits every source-bearing UID0003U1-UID0003U5
definition and declaration through UID00007A's ordered child markers. Exact
target-specific dispositions exclude the two unreferenced raw navigation
fragments and three compiler destructor wrappers without treating them as
missing source. `ListPane.cpp`/`.h` therefore has no reconstructable blank
emitter in the scroll, input, paint, selection/navigation, or ensure-visible
families. Score rises from `94/93` to `95/94`.

## UID0000LO Accepted Coherent CPP/H Source Root - 2026-08-14

`NexusTK/ui/controls/ListPane.cpp` and `ListPane.h` are now a complete paired
route. UID00007A owns the CPP includes/child marker and the full H class;
UID0003TZ contributes the ordinary constructor and non-deleting destructor;
the exact method children contribute one CPP body and one public H declaration
each. UID000194 and UID0003U0 remain non-emitting inventory/index pages.

The constructor forwards horizontal/vertical flags to the resolved
ScrollablePane constructor, allocates item and one-byte selection lists, sets
selected index `-1`, initializes flags/column state, stores row height and
viewport extent in `m_itemSize.y/x`, and calls `SetMode(1)`. The destructor
deletes both List objects; scalar-deleting wrappers and base teardown are
compiler output.

The source root includes `ListPane.h` and `../../util/List.h`. The header
includes `../core/ScrollBar.h`, which in turn exposes the accepted
ScrollablePane declaration. This closes the former missing-header dependency;
no separate support task or deferred class declaration remains.

## Status

- Confidence: very strong for the ListPane source family, class route, exact item/selection method split, and reusable-control ownership.
- Proposed module: `ui/controls/ListPane.cpp`
- Proposed header: `ui/controls/ListPane.h`
- Projected reconstruction path: `NexusTK/ui/controls/ListPane.cpp`
- Historical recovered views scattered shared methods across `class_ListPane.cpp`, article, chat-color, server-item-menu, and selection-state output. The accepted source route consolidates those shared methods under ListPane; caller-specific output is retained only as historical pollution evidence.
- Main address range: [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)
- Exact executable children: [UID:0003TZ][0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor](by-memory/0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md) through [UID:0003U5][0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks](by-memory/0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks.md). Inside non-emitting UID0003U0, thirteen exact item/selection method children emit through [UID:00007A][ListPane](by-class/ListPane.md): UID000500-UID00050A plus UID0004LX/UID0004M9.

## File Role

This module should own the reusable selectable list pane. `ListPane` adapts [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md) into a grid/list control with item storage, parallel selection flags, scroll metrics, hit testing, keyboard/mouse navigation, and virtual callbacks for feature-specific item drawing and activation.

The original source was likely a simple late-1990s UI control pair, not a board-dialog-private file. Recovered one-class output currently scatters the list helper methods across whichever feature first used them, but IDA caller fanout shows they are shared list infrastructure.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `ListPane` | `0x004f3a50-0x004f4a77` | Reusable `ScrollablePane`-derived list/grid control. |
| `SimpleListPane` | `0x005739a0-0x00573d15` source/compiler island | Thin fixed-layout `ListPane` subclass for basic list display; final placement is the standalone sibling `NexusTK/ui/controls/SimpleListPane.cpp` plus `SimpleListPane.h`. |
| UID000500 / UID000501 / UID000502 | `0x004f3bb0-0x004f3bfb` exact bodies | `GetItemSize`, null-safe `GetItemCount`, and signed-column `GetRowCount`; all formal source routes through ListPane. |
| UID000503 / UID000504 | `0x004f3c00-0x004f3ca4` exact bodies | One-item indexed insertion and tail append with parallel zero selection bytes, sync, and invalidation. |
| UID000505 / UID000506 | `0x004f3cb0-0x004f3d56` exact retained bodies | Bulk indexed/tail insertion preserving the compiled one-zero-byte selection payload shape. |
| UID000507 / UID000508 | `0x004f3d60-0x004f3dcf` exact bodies | Paired range removal/reset/notification and generic explicit-index item retrieval. |
| [UID:0004LX][0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled](by-memory/0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled.md) | `0x004f3dd0-0x004f3e1c` | Exact mode setter: early return, byte store, parallel selection clear, content invalidation. |
| [UID:0004M9][0x004f3e20-0x004f3e74.ListPaneGetSelectionCount](by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md) | `0x004f3e20-0x004f3e74` | Exact integer selection count across single/multiple modes; 14 callers. |
| UID000509 / UID00050A | `0x004f3e80-0x004f3f1b` exact bodies | Bounded selected-index export and explicit-index selection-byte query. |
| Adjustor thunks | `0x004f49e0-0x004f49f6` | Compiler-generated secondary-base destructor thunks. |

## Current Source-Output Split

| Current source-output owner | Address | Corrected source-layout decision |
| --- | --- | --- |
| `class_ListPane.cpp` | `0x004f3a50`, `0x004f3f20-0x004f4a77` | Keep in `ListPane.cpp`. |
| `class_SimpleListPane.cpp` | `0x005739a0-0x00573d15` source/compiler island | Route the six source methods through standalone sibling [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md); compiler thunks, scalar deleting destructor, vtables, and RTTI emit no raw source. |
| `class_ServerItemMenuItemList.cpp` | `0x004f3bd0` | Historical caller-biased placement; UID000501 emits `ListPane::GetItemCount` through UID00007A. |
| `class_ArticleListPane.cpp` | `0x004f3c00`, `0x004f3d60`, `0x004f3e80` plus historical `0x004f3dd0` pollution | Historical caller-biased placement; UID000503/UID000507/UID000509 and UID0004LX emit through ListPane. |
| `class_ChattingColorListPane.cpp` | `0x004f3c50`, `0x004f3dc0`, `0x004f3f00` | Historical caller-biased placement; UID000504/UID000508/UID00050A emit through ListPane. UID000508 is generic indexed access, not selected-only. |
| `class_SelectionState.cpp` | `0x004f3e20` | Historical synthetic alias superseded by UID0004M9; no standalone `SelectionState` source owner. |

## Exact Item And Selection Source Family

| Exact child | Source member / evidence |
| --- | --- |
| [UID:000500][0x004f3bb0-0x004f3bcb.ListPaneGetItemSize](by-memory/0x004f3bb0-0x004f3bcb.ListPaneGetItemSize.md) | `GetItemSize`; retained Point-return body, zero current routes. |
| [UID:000501][0x004f3bd0-0x004f3bdf.ListPaneGetItemCount](by-memory/0x004f3bd0-0x004f3bdf.ListPaneGetItemCount.md) | `GetItemCount`; null returns zero; 69 calls. |
| [UID:000502][0x004f3be0-0x004f3bfb.ListPaneGetRowCount](by-memory/0x004f3be0-0x004f3bfb.ListPaneGetRowCount.md) | `GetRowCount`; signed `m_columnCount`; retained body, zero routes. |
| [UID:000503][0x004f3c00-0x004f3c4b.ListPaneInsertItem](by-memory/0x004f3c00-0x004f3c4b.ListPaneInsertItem.md) | `InsertItem`; 12 calls. |
| [UID:000504][0x004f3c50-0x004f3ca4.ListPaneAddEntry](by-memory/0x004f3c50-0x004f3ca4.ListPaneAddEntry.md) | `AddEntry`; tail append, 47 calls. |
| [UID:000505][0x004f3cb0-0x004f3cfd.ListPaneInsertItems](by-memory/0x004f3cb0-0x004f3cfd.ListPaneInsertItems.md) | `InsertItems`; retained bulk body and exact one-zero-byte payload shape. |
| [UID:000506][0x004f3d00-0x004f3d56.ListPaneAddEntries](by-memory/0x004f3d00-0x004f3d56.ListPaneAddEntries.md) | `AddEntries`; retained bulk tail body and exact one-zero-byte payload shape. |
| [UID:000507][0x004f3d60-0x004f3db7.ListPaneRemoveItems](by-memory/0x004f3d60-0x004f3db7.ListPaneRemoveItems.md) | `RemoveItems`; paired removal/reset/callback, 37 calls. |
| [UID:000508][0x004f3dc0-0x004f3dcf.ListPaneGetItem](by-memory/0x004f3dc0-0x004f3dcf.ListPaneGetItem.md) | `GetItem`; generic explicit-index getter, 98 calls. |
| [UID:0004LX][0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled](by-memory/0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled.md) | `SetMultipleSelectionEnabled`; five calls; `SetSortEnabled` rejected. |
| [UID:0004M9][0x004f3e20-0x004f3e74.ListPaneGetSelectionCount](by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md) | `GetSelectionCount`; 14 calls; `SelectionState` rejected. |
| [UID:000509][0x004f3e80-0x004f3ef7.ListPaneGetSelectedIndices](by-memory/0x004f3e80-0x004f3ef7.ListPaneGetSelectedIndices.md) | `GetSelectedIndices`; bounded single/multiple export, 19 calls. |
| [UID:00050A][0x004f3f00-0x004f3f1b.ListPaneIsItemSelected](by-memory/0x004f3f00-0x004f3f1b.ListPaneIsItemSelected.md) | `IsItemSelected`; explicit-index byte query, 26 calls. |

The shared field model is `m_itemBounds:+0x110`, `m_contentBounds:+0x120`, `m_items:+0x130`, `m_selectedIndex:+0x134`, `m_selectionFlags:+0x138`, `m_multipleSelectionEnabled:+0x13c`, `m_itemSize:+0x140/+0x144`, and signed-byte `m_columnCount:+0x148`. Constructor and scroll/row behavior prove that the final constructor byte is column count rather than the separate multiple-selection mode.

## Ownership Decision

Keep this as `ui/controls/ListPane.cpp`. It is above scrollbar primitives but below feature dialogs:

- Do not merge into `ui/core/ScrollBar.cpp`; [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md) owns scrollbar children and clipping, while `ListPane` owns item/selection semantics.
- Do not keep the shared helpers in [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), [UID:0000I5][Chatting](by-file/Chatting.md), item-menu, spell-menu, or user-list files. Those sources define feature-specific row data and drawing only.
- Keep [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md) as reusable control support. It is a small basic-list adapter over `ListPane`, not a feature list pane.
- Keep derived classes such as [UID:00000L][ArticleListPane](by-class/ArticleListPane.md), [UID:0000FO][UserListPane](by-class/UserListPane.md), [UID:0000AQ][PowerListPane](by-class/PowerListPane.md), `MailListPane`, `TextMenuItemList`, and spell/menu item lists in their feature modules.

## Evidence Notes

- IDA MCP `list_funcs` shows a compact `0x004f3a50-0x004f4a77` function family immediately after lower-level list container routines at `0x004f3020-0x004f3a43`.
- IDA MCP confirms broad direct callers for `0x004f3bd0`, `0x004f3c50`, `0x004f3dc0`, `0x004f3e20`, and `0x004f3f00`, spanning many independent UI features.
- 2026-06-14 C001 support-route refresh reconfirmed the live IDA function family for `0x004f3a50`, `0x004f3b60`, `0x004f3bd0`, `0x004f3c00`, `0x004f3c50`, `0x004f3d60`, `0x004f3dc0`, `0x004f3dd0`, `0x004f3e20`, `0x004f3e80`, `0x004f3f00`, `0x004f3f20`, `0x004f49e0`, `0x004f49eb`, and `0x004f4a00`; `0x004f4820` and `0x004f4910` remain raw non-function islands already documented by [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md).
- 2026-06-14 C001 IDA `xrefs_to` tied all three [UID:0003OM][0x0061ce84-0x0061cf44.ListPaneVtableData](by-memory/0x0061ce84-0x0061cf44.ListPaneVtableData.md) table heads to the same constructor/destructor/scalar-destructor store family at `0x004f3a50`, `0x004f3b60`, and `0x004f4a00`, while the `0x0061cf44` successor ref confirms the `LObject` type-name boundary.
- 2026-06-14 C001 IDA caller refresh found broad cross-feature use of the core helper methods, including 69 refs to `0x004f3bd0`, 47 refs to `0x004f3c50`, 98 refs to `0x004f3dc0`, 14 refs to `0x004f3e20`, and 26 refs to `0x004f3f00`; shared virtual helpers such as `0x004f4190`, `0x004f4300`, `0x004f43e0`, and `0x004f45b0` also have mixed code/vtable refs, matching reusable control ownership rather than feature-file ownership.
- 2026-06-21 B005 chat-color support pass reinforces that `0x004f3dc0` should not be globally named `GetSelectedEntry`: [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) pushes a loop index, so the source-facing API is closer to `GetItem(row)` / `GetEntryAt(row)`. The inherited selection-update virtual at `0x004f45b0` may be called as `SetSelectedIndex(row, notify)` by programmatic refresh helpers such as [UID:0002G8][0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor](by-memory/0x00483210-0x0048325b.ChattingColorListPaneSelectCurrentColor.md), while derived override pages can keep `OnItemSelected` role wording.
- 2026-06-19/21 B007 target [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) reanalysis confirmed from local PE bytes that `0x004f3dc0` preserves the caller-supplied index for the primary list vtable slot `+0x10`; the selected-entry wording should be retained only as a historical/generated alias, not the final helper name.
- 2026-06-19/22 B014 verification of [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) corroborates the same source-output split: `0x004f3dc0` is reusable indexed primary-list access for `ListPane.cpp`, not a chat-color helper and not selected-entry-only; selected-index behavior is call-site-specific.
- 2026-06-21 B009 MailDeleteReplyAlert support pass adds another reusable-list callsite: [UID:0002T9][0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete](by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md) uses `ListPane::GetSelectedIndices` and `ListPane::RemoveItems` for mail reply-list mutation in bulk selected-reply mode, and `RemoveItems` again after `MailListPane::FindMailIdIndex` in single-reply mode. This reinforces `ListPane.cpp` ownership for selection/removal helpers rather than feature-dialog ownership.
- 2026-07-13 UID0004BM support reanalysis resolves `0x004f3dd0-0x004f3e1c` as UID0004LX. The 76-byte function has five code xrefs, compares/stores byte `+0x13c`, gets the raw buffer/count from selection list `+0x138`, clears every byte backwards, and invalidates bounds `+0x120` through ListPane virtual slot `+0x20`. No caller consumes AL, so source return is `void`.
- AddItemDialog calls UID0004LX twice: EPF mode passes its `allowMultipleSelection` byte; EPD mode forces one. Calls at `0x0047496a`, `0x0047928a`, and `0x0047982c` prove the helper is generic ListPane source, not ItemDialogs or MyItemListPane source.
- Historical generated `SetSortEnabled` is invalid: the exact body has no sort field, comparator, reorder, or ordering operation. Accepted descriptive spellings are `SetMultipleSelectionEnabled`, `m_multipleSelectionEnabled`, `m_selectionFlags`, and `m_contentBounds`, with lexical uncertainty retained as a score cap.
- 2026-05-26 IDA `py_eval` recheck found no `SelectionState` names/RTTI, while `ListPane` vtables/RTTI are present; keep `class_SelectionState.cpp` as an alias container for `ListPane::GetSelectionCount`.
- Validator-issued UID0004M9 formalizes `0x004f3e20` as `int ListPane::GetSelectionCount() const` at `91/93`. Single-select mode returns `m_selectedIndex >= 0`; multi-select mode counts every nonzero byte from `m_selectionFlags->GetData()` through `GetCount()`. Exact four-byte predecessor and twelve-byte successor padding stay parent-only.
- Its 14 callers span dialogs, menus, lists, spell flows, and [UID:0004BP][0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton](by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md), proving reusable ListPane ownership rather than caller/feature ownership.
- The constructor calls `ScrollablePane::ScrollablePane`, allocates two `List` objects, initializes `selectedIndex` to `-1`, stores row/column size state, and marks the pane visible.
- `OnInputEvent` uses `g_pEventManager` mouse capture/release, while row painting and activation are virtual callbacks supplied by derived feature panes.
- `SimpleListPane` constructor/destructor evidence sits much later at `0x005739a0` and `0x00573c38-0x00573d15`, but its behavior is a small `ListPane` wrapper and destructor cleanup path.
- 2026-06-06 by-memory audit confirms IDA still does not model `0x004f4820` as a function object, but raw disassembly shows a real `ListPane` selection clamp/notify body at `0x004f4820-0x004f487c` plus a `0x004f4910-0x004f4919` frame shim. Treat the disabled `class_ListPane.cpp` lead as unpromoted raw `ListPane` material requiring exact split/name follow-up, not as empty padding.

## Migration Notes

- Source output belongs under `NexusTK/ui/controls/ListPane.cpp`; exact item/selection methods now route from their by-memory pages through UID00007A instead of feature/caller-generated files.
- UID0003U0 remains fully split, and UID0003U1-UID0003U5 now carry complete formal source or exact per-fragment no-code dispositions. UID0003U4's raw selection/navigation material is preserved as evidence but is no longer an unresolved blank channel.
- `SimpleListPane` is finalized as sibling `NexusTK/ui/controls/SimpleListPane.cpp/.h`. Its header includes this module's externally owned `ListPane.h`; ListPane stays the complete base declaration and no SimpleListPane body is folded into `ListPane.cpp`.
- UID0004LX now emits `0x004f3dd0` as `SetMultipleSelectionEnabled`; retain `SetSortEnabled` only as rejected historical generated pollution.
- Treat `SelectionState` as a rejected/superseded generated alias for UID0004M9, not as current source ownership.
- Keep UID0003U0 and UID000194 non-emitting; their exact children provide source and prevent duplicate broad-range output.

## Score Rationale

Completion is `95` because the page documents the complete source-family map, all thirteen exact UID0003U0 method emitters, fully populated UID0003U1-UID0003U5 channels, field and constructor semantics, generated-owner corrections, aggregate non-emission, and the finalized sibling SimpleListPane relationship. Confidence is `94` because fresh canonical IDA/PE evidence confirms exact behavior, vtable order, call fanout, fields, raw no-route state, compiler-wrapper identity, reusable-control ownership, and the complete CPP/H dependency chain. Original lexical spellings remain the only material confidence cap.

## Cross-References

- [UID:00007A][ListPane](by-class/ListPane.md)
- [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)
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
- [UID:0004BM][0x004ae4c0-0x004ae8f5.AddItemDialogConstructor](by-memory/0x004ae4c0-0x004ae8f5.AddItemDialogConstructor.md)
- [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md)
- [UID:0000D8][SimpleListPane](by-class/SimpleListPane.md)
- [UID:0001HP][0x005739a0-0x005739f6.SimpleListPaneConstructor](by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md)
- [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md)
- [UID:0004M9][0x004f3e20-0x004f3e74.ListPaneGetSelectionCount](by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md)
- [UID:000509][0x004f3e80-0x004f3ef7.ListPaneGetSelectedIndices](by-memory/0x004f3e80-0x004f3ef7.ListPaneGetSelectedIndices.md)
- [UID:00050A][0x004f3f00-0x004f3f1b.ListPaneIsItemSelected](by-memory/0x004f3f00-0x004f3f1b.ListPaneIsItemSelected.md)
- [UID:0000CS][SelectionState](by-class/SelectionState.md) historical alias support only.
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md)
- [UID:00000L][ArticleListPane](by-class/ArticleListPane.md)
- [UID:0000AQ][PowerListPane](by-class/PowerListPane.md)

## Changes

- 2026-08-14 Agent-B009 UID0000NQ accepted callback: replaced every tentative SimpleListPane fold choice with final sibling `NexusTK/ui/controls/SimpleListPane.cpp/.h` placement; recorded the external `ListPane.h` base dependency and six-source-method/compiler-no-raw-source split. ListPane path, FILE ownership, `94/93` score, and existing source route are unchanged.

- 2026-08-02 B008 UID0003U0 accepted implementation callback: raised `89/87` to `93/92`; added the complete validator-issued UID000500-UID00050A method family alongside UID0004LX/UID0004M9, documented exact source routes/caller counts/field semantics and signed constructor `columnCount`, historicalized caller-generated placements, and preserved UID000194/UID0003U0 as non-emitting indexes. `PROPOSED_RECONSTRUCTION_PATH` and FILE ownership remain unchanged.

- 2026-07-13 B005 UID0004BP implementation callback: score/path/FILE ownership unchanged at `89/87` and `NexusTK/ui/controls/`; linked UID0004M9, exact formal body/fields/range/padding/CFG/14-caller evidence, target consumer, and superseded SelectionState ownership while preserving UID0004LX, remaining raw helpers, and SimpleListPane split caveats.

- 2026-07-13 B001 UID0004BM callback: score/path unchanged at `89/87` and `NexusTK/ui/controls/`; added exact setter child UID0004LX, body/return/five-caller evidence, AddItemDialog call semantics, class/file route, and historicalized generated `SetSortEnabled` pollution while preserving unresolved raw-helper and SimpleListPane decisions.

- 2026-06-16 Supervisor: Executed B001 [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md) source-split report. Raised this support file from `88/85` to `89/87`, linked exact ListPane executable children [UID:0003TZ][0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor](by-memory/0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md)-[UID:0003U5][0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks](by-memory/0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks.md), and updated migration notes so raw no-route islands are investigated inside the exact ListPane children before final C++.
- 2026-06-14 Agent-C001 Goal 2 batch `C001-goal2-listpane-support-route-20260614-1`: raised confidence from `84` to `85` for the strict owner/emitter gate after a live IDA refresh reconfirmed the modeled function family, [UID:0003OM][0x0061ce84-0x0061cf44.ListPaneVtableData](by-memory/0x0061ce84-0x0061cf44.ListPaneVtableData.md) store refs, `LObject` successor boundary, and cross-feature helper fanout. Completion remains `88`; no IDA database edits or source C++ changes were made.
- 2026-06-05: Assigned projected reconstruction path `NexusTK/ui/controls/` to resolve the by-file generated-root coverage error.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the document and proposed source tree both place `ListPane.cpp` under `ui/controls/`.
  - After: set the validator path to `NexusTK/ui/controls/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `ListPane.cpp` under `ui/controls`, and live IDA MCP lookup on 2026-06-05 confirms the constructor anchor at `0x004f3a50` as a real function of size `0x10b`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:84`.
  - Summary/evidence: reusable list-pane control role, proposed contents, source-output split corrections, ownership decision, broad caller evidence, `SimpleListPane` relationship, and migration notes are documented; confidence is capped by final `SimpleListPane` split and helper owner pollution.
- 2026-06-06 A007: Synchronized the `0x004f4820` evidence with the refreshed by-memory aggregate audit. The address remains unmodeled as an IDA function object but is now documented as real raw ListPane selection/navigation code; no projected path, score, or source C++ changes.
- 2026-06-21 B005 Rule 26 support incorporation: no score change. Clarified explicit-index item accessor semantics for `0x004f3dc0` and the programmatic-selection role of `0x004f45b0`/vtable slot `+0x78` for chat color-list refresh code.
- 2026-06-21 B007 Rule 26 support incorporation: no score change. Updated the current-source split and evidence notes so `0x004f3dc0` is documented as the indexed `ListPane::GetItem` / `GetEntryAt` helper, with `GetSelectedEntry` retained only as a stale/generated call-site alias.
- 2026-06-22 B014 Rule 26 support incorporation: no score change. B014 independently verified the [UID:0002GA][0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue](by-memory/0x00483270-0x004832b9.ChattingColorListPaneFindIndexByColorValue.md) loop-row callsite and reinforces that `0x004f3dc0` belongs in `ListPane.cpp` as indexed entry access.
- 2026-06-21 B009 Rule 26 support incorporation: no score change. Added the MailDeleteReplyAlert callsite for `GetSelectedIndices` and `RemoveItems`.
