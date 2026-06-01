*** UID:0001QV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client UI Core

## Status

- Scope: reusable UI base classes, pane tree, event routing, root screen pane, frame scheduling/chrome, scrollbar infrastructure, and shared dirty-region helpers.
- Confidence: medium-to-strong for the current source grouping; some original filename choices remain open.
- Primary source-tree section: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Core Source Groups

| Proposed file | Primary docs | Responsibility |
| --- | --- | --- |
| `ui/core/Pane.cpp` | [UID:0000MC][Pane](by-file/Pane.md) | Base visible UI object, layer membership, event/timer hooks, dirty/clip state, and repaint/bounds behavior. |
| `ui/core/BlackHole.cpp` | [UID:0000HR][BlackHole](by-file/BlackHole.md) | Deferred pane/object deletion queue; current `PaneChildRegistry` data is a stale generated alias. |
| `ui/core/Layer.cpp` | [UID:0000KL][Layer](by-file/Layer.md) | Pane tree, z-order, recursive render traversal, clip propagation, motion, and dirty-region build/copy. |
| `ui/core/RectBounds.cpp` | [UID:0000N2][RectBounds](by-file/RectBounds.md) | Four-int rectangle/point value helpers shared by UI, render, map, and resource code. |
| `ui/core/Region.cpp` | [UID:0000N3][Region](by-file/Region.md) | Small `Region` object and `Motion`-named rectangle helpers used by dirty-region and clipping code. |
| `ui/core/ScreenPane.cpp` | [UID:0000NB][ScreenPane](by-file/ScreenPane.md) | Full-screen root pane singleton, fade/frame callbacks, DirectDraw surface cleanup, and display-mode teardown. |
| `ui/core/CursorManager.cpp` | [UID:0000IL][CursorManager](by-file/CursorManager.md) | Provisional typed view over `g_pScreenPane` for cursor switching and screen-dimension accessors; generated [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md) is an alias over the same storage, and current evidence favors folding this code into `ScreenPane.cpp` unless a later original split is proven. |
| `ui/core/DialogPane.cpp` | [UID:0000IT][DialogPane](by-file/DialogPane.md) | Modal dialog base, common dialog lifecycle, focus/hover/selection state, and config-backed positioning. |
| `ui/core/ModelessDialogPane.cpp` | [UID:0000LH][ModelessDialogPane](by-file/ModelessDialogPane.md) / [UID:0001Y6][ModelessDialogPaneVtables](by-type/by-vtable/ModelessDialogPaneVtables.md) | Shared non-modal dialog shell and mouse-event router. |
| `ui/core/ControlPane.cpp` | [UID:0000IG][ControlPane](by-file/ControlPane.md) | Base clickable/input control pane and common control metadata. |
| `ui/core/PanelPane.cpp` | [UID:0000ME][PanelPane](by-file/PanelPane.md) | Reusable pane-derived base for side panels and panel-style feature surfaces; IDA caller checks show direct use by inventory, option, group, collection, self-look, spell-inventory, system-message, and user-look panes. |
| `ui/core/Event.cpp` | [UID:0000J6][Event](by-file/Event.md) | Event objects, `EventMan`, and event factories between `InputMan` and the dispatcher. |
| `ui/core/EventDispatcher.cpp` | [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) | Handler registration, `EventHandler`/handler-tree support, modal/modeless event traversal, timer/frame dispatch bridge, and idle work helper. |
| `ui/core/FrameMgr.cpp` | [UID:0000JM][FrameMgr](by-file/FrameMgr.md) | Frame callback scheduler and `FrameHandler` base, not visible frame artwork. |
| `ui/core/FrameChrome.cpp` | [UID:0000JL][FrameChrome](by-file/FrameChrome.md) | Visible `FRMPART`/`TABS` frame-border panes and frame-part factories. |
| `ui/core/ScrollBar.cpp` | [UID:0000NF][ScrollBar](by-file/ScrollBar.md) | Generic scrollbar panes, scroll widgets, scrollable viewport pane, and scrollbar size/resource tables. |
| `ui/core/ScrollCollectionPane.cpp` | [UID:0000NG][ScrollCollectionPane](by-file/ScrollCollectionPane.md) | EPF-backed scrollbar variant; still under review for folding into `ScrollBar.cpp`. |
| `ui/controls/SimpleListPane.cpp` | [UID:0000NQ][SimpleListPane](by-file/SimpleListPane.md) | Small fixed-layout `ListPane` adapter and list-entry cleanup support. |
| `ui/controls/FontStyle.cpp` | [UID:0000JI][FontStyle](by-file/FontStyle.md) | Compact text-style descriptor and rule-vector support consumed by static text labels and help panes. |
| `ui/controls/DescPane.cpp` | [UID:0000IS][DescPane](by-file/DescPane.md) / [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md) | Singleton-backed reusable description display pane fed by an external source/index provider. |
| `ui/controls/ScrollVolumePane.cpp` | [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md) | Vertical audio-volume slider control and [UID:0001YT][ScrollVolumePaneVtables](by-type/by-vtable/ScrollVolumePaneVtables.md) consumed by option UI; separate from generic scrollbar infrastructure and audio policy. |
| `ui/core/VideoPlayerPane.cpp` | [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md) | Reusable Bink playback pane used by startup logo/movie code. |

## Boundary Rules

- Keep UI base files separate from feature dialogs. Constructor fan-in proves reuse; it should not move a base class into the first feature that calls it.
- Keep `FrameMgr` separate from `FrameChrome`: scheduler callbacks and visible border artwork are unrelated source responsibilities despite the shared word "frame".
- Keep [UID:0000N2][RectBounds](by-file/RectBounds.md) separate from `Region.cpp`: raw four-int geometry helpers are lower-level primitives, while `Region` owns dirty-region wrapper behavior.
- Keep `Region.cpp`/dirty-rectangle helpers separate from timer-driven [UID:0000LL][Motion](by-file/Motion.md) animation until a later pass proves the original source intentionally combined them.
- Keep `ScrollableControlPane`, `ListPane`, `TextEditPane`, [UID:0000JI][FontStyle](by-file/FontStyle.md), [UID:0000IS][DescPane](by-file/DescPane.md), [UID:0000NK][ScrollVolumePane](by-file/ScrollVolumePane.md), and other control adapters/support types under `ui/controls`; they consume UI core, but they are higher-level control modules.
- Treat generated aliases such as [UID:0000QP][g_pCursorManager](by-global/g_pCursorManager.md), `PaneChildRegistry`, feature-owned list helpers, and base-destructor owner names as data issues until IDA xrefs and local ranges support the ownership.
- For cursor helpers, use the current generated `CursorManager` label as a search/index aid only. Source reconstruction should prefer `ScreenPane.cpp` ownership because IDA confirms the helpers operate on the root `ScreenPane` object and no separate cursor-manager lifetime has been found.

## Evidence Summary

- IDA caller evidence shows high constructor fan-in for `Pane`, `DialogPane`, and `ControlPane`, which supports reusable core ownership.
- `Pane` attach/remove calls the `Layer` API directly, while `Layer` owns tree traversal and dirty-region propagation.
- The `RectBounds`/raw-geometry helper island has broad caller fanout, including 1500+ `InitRectBounds` callers in IDA output; the later `Region`/dirty-rectangle helper island has broad `Layer`, `GrafPort`, pane, scroll, text, and map/UI caller fanout.
- `ScreenPane::ScreenPane` writes `g_pScreenPane` at `0x0067a7cc`; generated cursor helpers read fields from the same root object, so cursor-manager naming remains provisional. A 2026-05-26 IDA MCP recheck reports this storage as a 4-byte `.data` item with 145 refs, confirms dimensions at `+0x112/+0x114`, confirms cursor state at `+0x550/+0x580`, and leaves cursor-handle initialization unresolved.
- `Event.cpp` produces event objects and payloads; `EventDispatcher.cpp` routes already-built events and drains deferred deletion/idle work.
- `EventHandler` is the base receiver interface embedded by panes, while `Tree<EventHandler*>`, `TreeItor<EventHandler*>`, and `HandlerFindFunc` are dispatcher support types for handler traversal.
- `ModelessDialogPane` is anchored by three IDA-confirmed vtables at `0x00618c48`, `0x00618ca8`, and `0x00618cd8`; the current generated `vtable_count: 0` should not be used to weaken the class/file assignment.

## Cross-References

- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [UID:0000N2][RectBounds](by-file/RectBounds.md)
- [UID:0001QQ][client_s5-ui-and-gameworld-rendering](by-meta/client_s5-ui-and-gameworld-rendering.md)
- [UID:0001QD][client_input_and_text_entry](by-meta/client_input_and_text_entry.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)
- [UID:0001QJ][client_old_redering_mode](by-meta/client_old_redering_mode.md)
