*** UID:00007A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ListPane

## Status

- Confidence: strong for reusable list-control ownership.
- Likely source file: [UID:0000KT][ListPane](by-file/ListPane.md)
- Address range: [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)
- Current recovered files: `source-3/simroot_v2/class_ListPane.cpp`, plus helper fragments currently emitted under `class_ArticleListPane.cpp`, `class_ChattingColorListPane.cpp`, `class_ServerItemMenuItemList.cpp`, and `class_SelectionState.cpp`.

## Class Purpose

`ListPane` is the reusable selectable list/grid pane used by board, mail, clan, exchange, menu, spell, server-select, phone-book, user-list, power-dialog, and other UI flows. It derives from [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md), owns a primary item list at `+0x130`, tracks a selected index at `+0x134`, owns a selection flag list at `+0x138`, and provides virtual hooks for item rectangles, drawing, selection change, double-click activation, and scroll metrics.

Feature panes such as [UID:00000L][ArticleListPane](by-class/ArticleListPane.md) and [UID:0000FO][UserListPane](by-class/UserListPane.md) supply row-specific drawing and behavior. The shared insert/remove/count/selection helpers should stay with `ListPane`, not with those feature panes.

## Method Notes

| Method or role | Address | Notes |
| --- | --- | --- |
| Constructor | `0x004f3a50-0x004f3b5b` | Calls `ScrollablePane`, installs three `ListPane` vptrs, allocates two `List` objects, stores row/column dimensions, and marks the pane visible. |
| Non-deleting destructor core | `0x004f3b60-0x004f3ba5` | Restores `ListPane` vptrs, destroys the two owned lists, then chains to `ScrollablePane`/base cleanup. Called by derived destructors. |
| `GetItemCount` | `0x004f3bd0-0x004f3bdf` | Returns `primaryList->count` or zero. Currently emitted as `ServerItemMenuItemList::GetItemCount`. |
| `InsertItem` | `0x004f3c00-0x004f3c4b` | Inserts into the primary list and parallel selection list, syncs scrollbars, and invalidates the content rectangle. Currently emitted under `ArticleListPane`. |
| `AddEntry` / append item | `0x004f3c50-0x004f3ca4` | Appends at the current primary-list count and mirrors a cleared selection byte. Currently emitted under `ChattingColorListPane`. |
| `RemoveItems` | `0x004f3d60-0x004f3db7` | Removes from both lists, syncs scrollbars, invalidates, clears selected index, and calls the selection-change virtual. Currently emitted under `ArticleListPane`. |
| `GetSelectedEntry` | `0x004f3dc0-0x004f3dcf` | Dispatches through the primary list to fetch the selected entry. Currently emitted under `ChattingColorListPane` and used by many list subclasses. |
| Selection-mode toggle | `0x004f3dd0-0x004f3e1c` | Sets byte `+0x13c`, clears selection flags, and invalidates selection region. Current generated name `SetSortEnabled` is misleading. |
| `GetSelectionCount` | `0x004f3e20-0x004f3e74` | Counts selected flags in multi-select mode or returns whether `selectedIndex >= 0`. Currently emitted as the separate `SelectionState` class. |
| `GetSelectedIndices` | `0x004f3e80-0x004f3ef7` | Writes selected indices into a caller buffer, supporting both multi-select and single-selection modes. Currently emitted under `ArticleListPane`. |
| `IsItemSelected` | `0x004f3f00-0x004f3f1b` | Reads a selection byte from the parallel selection list. Currently emitted under `ChattingColorListPane`. |
| Scroll metrics | `0x004f3f20-0x004f4140` | Computes scroll range, overflow count, page size, scroll offsets, content size, and scroll delta. |
| Mouse/key input | `0x004f4190-0x004f43cd` | Handles drag selection, click/double-click, mouse capture through `g_pEventManager`, arrow keys, and page navigation. |
| Paint/hit testing | `0x004f43e0-0x004f45a2` | Iterates visible items, computes item rectangles, hit-tests, and dispatches row drawing through virtual methods. |
| Selection update | `0x004f45b0-0x004f47b1` | Updates single/multi/range selection state and invalidates the dirty selection rectangle. |
| Navigation helpers and raw fragments | `0x004f47c0-0x004f4919` | Moves selection up/down or by page, ensures visibility, and invokes the selection virtual. The refreshed by-memory audit also records unpromoted raw code at `0x004f4820-0x004f487c` and a frame shim at `0x004f4910-0x004f4919`. |
| `EnsureItemVisible` | `0x004f4920-0x004f49e0` | Scrolls the containing `ScrollablePane` so a target item rectangle is visible. |
| Destructor and thunks | `0x004f49e0-0x004f4a77` | Two adjustor thunks plus the scalar deleting destructor. |

## Evidence Notes

- IDA MCP confirms real functions at `0x004f3a50`, `0x004f3b60`, `0x004f3bd0`, `0x004f3c00`, `0x004f3c50`, `0x004f3d60`, `0x004f3dc0`, `0x004f3dd0`, `0x004f3e20`, `0x004f3e80`, `0x004f3f00`, and the active `ListPane` virtual block through `0x004f4a77`.
- Constructor callers include board/article lists, chat color lists, clan lists, exchange lists, item/spell menu lists, server-select lists, phone-book lists, and user-list panes.
- Caller fanout for `GetItemCount`, append, selected-entry, selection-count, selected-indices, and `IsItemSelected` spans many list subclasses. That fanout supports reusable `ListPane` ownership over feature-specific ownership.
- 2026-05-26 IDA `py_eval` recheck confirms the `GetSelectionCount` helper at `0x004f3e20-0x004f3e74` has 14 xrefs and no `SelectionState` RTTI/name evidence; IDA does expose `ListPane` vtables and RTTI, so the generated `SelectionState` class record is an alias.
- 2026-06-06 by-memory audit confirms IDA still does not model `0x004f4820` as a function object, but raw disassembly shows a real `ListPane` selection clamp/notify body at `0x004f4820-0x004f487c`; treat it as unpromoted raw `ListPane` material needing split/name follow-up, not as empty padding.

## Source Layout Decision

Keep `ListPane` in `ui/controls/ListPane.cpp` or a neighboring reusable UI-control source. Do not fold it into `BoardDialogs.cpp`, `Chatting.cpp`, item-menu files, or `ScrollBar.cpp`. It depends on [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md), but the behavior is selectable list control logic rather than scrollbar drawing.

## Cross-References

- [UID:0000KT][ListPane](by-file/ListPane.md)
- [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)
- [UID:0000CS][SelectionState](by-class/SelectionState.md)
- [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md)
- [UID:00000L][ArticleListPane](by-class/ArticleListPane.md)
- [UID:0000FO][UserListPane](by-class/UserListPane.md)
- [UID:0000ET][TextMenuItemList](by-class/TextMenuItemList.md)
- [UID:0000AQ][PowerListPane](by-class/PowerListPane.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `90/88`. Summary: the reusable selectable list control is documented in high detail across construction, owned lists, selection, scrolling, hit testing, virtual dispatch, generated ownership pollution, and source layout decision. Evidence: linked full by-memory range, IDA-confirmed helper starts, vtable/RTTI evidence, broad subclass caller fanout, and `SelectionState` alias analysis.
- 2026-06-05: Marked reconstructable and attached to [UID:0000KT][ListPane](by-file/ListPane.md).
  - Before: `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` were blank, leaving the reusable selectable list control unclassified in generated class coverage.
  - After: set `RECONSTRUCTABLE:TRUE` and `AUTOGEN_PARENT_UID:0000KT`; left the C++ block blank because the page is below the final reconstruction bar.
  - Summary/evidence: live IDA MCP reconfirms the core starts at `0x004f3a50`, `0x004f3b60`, `0x004f3bd0`, `0x004f3c00`, `0x004f3c50`, `0x004f3d60`, `0x004f3e20`, and `0x004f49e0`, with broad subclass caller fanout. The class score `90/88` and parent score `88/84` meet the 80/80 attachment gate.
- 2026-06-06 A007: Synchronized the method/evidence notes with [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md) after live IDA disassembly confirmed `0x004f4820-0x004f487c` is unpromoted raw ListPane code rather than padding or a purely stale disabled-source lead. No score or C++ changes.
