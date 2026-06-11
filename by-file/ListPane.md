*** UID:0000KT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ListPane

## Status

- Confidence: strong.
- Proposed module: `ui/controls/ListPane.cpp`
- Proposed header: `ui/controls/ListPane.h`
- Projected reconstruction path: `NexusTK/ui/controls/ListPane.cpp`
- Recovered source views: `class_ListPane.cpp`, [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md), plus shared helpers currently emitted in article, chat-color, server-item-menu, and selection-state source-output files.
- Main address range: [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)

## File Role

This module should own the reusable selectable list pane. `ListPane` adapts [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md) into a grid/list control with item storage, parallel selection flags, scroll metrics, hit testing, keyboard/mouse navigation, and virtual callbacks for feature-specific item drawing and activation.

The original source was likely a simple late-1990s UI control pair, not a board-dialog-private file. Recovered one-class output currently scatters the list helper methods across whichever feature first used them, but IDA caller fanout shows they are shared list infrastructure.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `ListPane` | `0x004f3a50-0x004f4a77` | Reusable `ScrollablePane`-derived list/grid control. |
| `SimpleListPane` | `0x005739a0`, `0x00573c38-0x00573d15` | Thin fixed-layout `ListPane` subclass for basic list display; keep as a sibling control source or fold into this module. |
| Selection helper methods | `0x004f3dd0-0x004f3f1b` | Multi-select toggle, selection count, selected-index export, and item-selected query. |
| Item-list helper methods | `0x004f3bd0-0x004f3dcf` | Item count, insertion, append, remove, and selected-entry retrieval over the primary list and selection flag list. |
| Adjustor thunks | `0x004f49e0-0x004f49f6` | Compiler-generated secondary-base destructor thunks. |

## Current Source-Output Split

| Current source-output owner | Address | Corrected source-layout decision |
| --- | --- | --- |
| `class_ListPane.cpp` | `0x004f3a50`, `0x004f3f20-0x004f4a77` | Keep in `ListPane.cpp`. |
| `class_SimpleListPane.cpp` | `0x005739a0`, `0x00573c38-0x00573d15` | Keep in reusable controls as [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md), or fold into `ListPane.cpp` if final layout favors compact control files. |
| `class_ServerItemMenuItemList.cpp` | `0x004f3bd0` | Move to `ListPane.cpp` as `GetItemCount`. |
| `class_ArticleListPane.cpp` | `0x004f3c00`, `0x004f3d60`, `0x004f3dd0`, `0x004f3e80` | Move to `ListPane.cpp`; feature panes call these inherited/shared helpers. |
| `class_ChattingColorListPane.cpp` | `0x004f3c50`, `0x004f3dc0`, `0x004f3f00` | Move to `ListPane.cpp`; current chat-color owner is caller pollution. |
| `class_SelectionState.cpp` | `0x004f3e20` | Fold into `ListPane.cpp`; likely `ListPane::GetSelectionCount`, not a standalone class. |

## Ownership Decision

Keep this as `ui/controls/ListPane.cpp`. It is above scrollbar primitives but below feature dialogs:

- Do not merge into `ui/core/ScrollBar.cpp`; [UID:0000CF][ScrollablePane](by-class/ScrollablePane.md) owns scrollbar children and clipping, while `ListPane` owns item/selection semantics.
- Do not keep the shared helpers in [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), [UID:0000I5][Chatting](by-file/Chatting.md), item-menu, spell-menu, or user-list files. Those sources define feature-specific row data and drawing only.
- Keep [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md) as reusable control support. It is a small basic-list adapter over `ListPane`, not a feature list pane.
- Keep derived classes such as [UID:00000L][ArticleListPane](by-class/ArticleListPane.md), [UID:0000FO][UserListPane](by-class/UserListPane.md), [UID:0000AQ][PowerListPane](by-class/PowerListPane.md), `MailListPane`, `TextMenuItemList`, and spell/menu item lists in their feature modules.

## Evidence Notes

- IDA MCP `list_funcs` shows a compact `0x004f3a50-0x004f4a77` function family immediately after lower-level list container routines at `0x004f3020-0x004f3a43`.
- IDA MCP confirms broad direct callers for `0x004f3bd0`, `0x004f3c50`, `0x004f3dc0`, `0x004f3e20`, and `0x004f3f00`, spanning many independent UI features.
- 2026-05-26 IDA `py_eval` recheck found no `SelectionState` names/RTTI, while `ListPane` vtables/RTTI are present; keep `class_SelectionState.cpp` as an alias container for `ListPane::GetSelectionCount`.
- The constructor calls `ScrollablePane::ScrollablePane`, allocates two `List` objects, initializes `selectedIndex` to `-1`, stores row/column size state, and marks the pane visible.
- `OnInputEvent` uses `g_pEventManager` mouse capture/release, while row painting and activation are virtual callbacks supplied by derived feature panes.
- `SimpleListPane` constructor/destructor evidence sits much later at `0x005739a0` and `0x00573c38-0x00573d15`, but its behavior is a small `ListPane` wrapper and destructor cleanup path.
- 2026-06-06 by-memory audit confirms IDA still does not model `0x004f4820` as a function object, but raw disassembly shows a real `ListPane` selection clamp/notify body at `0x004f4820-0x004f487c` plus a `0x004f4910-0x004f4919` frame shim. Treat the disabled `class_ListPane.cpp` lead as unpromoted raw `ListPane` material requiring exact split/name follow-up, not as empty padding.

## Migration Notes

- Source migration after review should place `class_ListPane.cpp` under `ui/controls/ListPane.cpp` and attach the shared helper methods currently emitted under article, chat-color, server-item-menu, and selection-state source-output files.
- Split or name the newly documented raw `ListPane` islands from [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md), especially `0x004f4820-0x004f487c`, before promoting final source C++ for the navigation helper family.
- For `SimpleListPane`, either set a separate simpath `ui/controls/SimpleListPane.cpp` or attach it to `ListPane.cpp` after deciding how granular the original control sources were.
- Rename `0x004f3dd0` away from `SetSortEnabled`; behavior is a selection/multi-select flag update that clears selection bytes and invalidates selection display.
- Treat `SelectionState` as an alias until separate struct/class evidence appears.

## Cross-References

- [UID:00007A][ListPane](by-class/ListPane.md)
- [UID:000194][0x004f3a50-0x004f4a77.ListPane](by-memory/0x004f3a50-0x004f4a77.ListPane.md)
- [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md)
- [UID:0000D8][SimpleListPane](by-class/SimpleListPane.md)
- [UID:0001HP][0x005739a0-0x005739f6.SimpleListPaneConstructor](by-memory/0x005739a0-0x005739f6.SimpleListPaneConstructor.md)
- [UID:0001HQ][0x00573c38-0x00573d15.SimpleListPaneDestructorThunks](by-memory/0x00573c38-0x00573d15.SimpleListPaneDestructorThunks.md)
- [UID:0000CS][SelectionState](by-class/SelectionState.md)
- [UID:0000NF][ScrollBar](by-file/ScrollBar.md)
- [UID:0000NE][ScrollableControlPane](by-file/ScrollableControlPane.md)
- [UID:00000L][ArticleListPane](by-class/ArticleListPane.md)
- [UID:0000AQ][PowerListPane](by-class/PowerListPane.md)

## Changes

- 2026-06-05: Assigned projected reconstruction path `NexusTK/ui/controls/` to resolve the by-file generated-root coverage error.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the document and proposed source tree both place `ListPane.cpp` under `ui/controls/`.
  - After: set the validator path to `NexusTK/ui/controls/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `ListPane.cpp` under `ui/controls`, and live IDA MCP lookup on 2026-06-05 confirms the constructor anchor at `0x004f3a50` as a real function of size `0x10b`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:84`.
  - Summary/evidence: reusable list-pane control role, proposed contents, source-output split corrections, ownership decision, broad caller evidence, `SimpleListPane` relationship, and migration notes are documented; confidence is capped by final `SimpleListPane` split and helper owner pollution.
- 2026-06-06 A007: Synchronized the `0x004f4820` evidence with the refreshed by-memory aggregate audit. The address remains unmodeled as an IDA function object but is now documented as real raw ListPane selection/navigation code; no projected path, score, or source C++ changes.
