*** UID:0000J7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# EventDispatcher

## Proposed Original Placement

- Proposed source path: `ui/core/EventDispatcher.cpp`
- Proposed header path: `ui/core/EventDispatcher.h`
- Confidence: strong for `EventDispatcher`; medium for including `ApplicationHelper_4A6C40` in this file.

## Current Wave3 Containers

- `class_EventDispatcher.cpp`
- `class_EventHandler.cpp`
- `class_Tree_near_class_EventHandler___.cpp`
- `class_TreeItor_near_class_EventHandler___.cpp`
- `class_HandlerFindFunc.cpp`
- `class_Event.cpp`
- `class_ApplicationHelper_4A6C40.cpp`

## Responsibilities

This module owns the UI event-routing spine. It registers pane handlers, maintains dispatch traversal order, routes keyboard/pointer/timer events to pane handlers, handles modal list entries, and performs timer-driven dispatch maintenance. It also contains a small message-loop scheduler/helper currently named `ApplicationHelper_4A6C40`.

`ApplicationHelper_4A6C40` is called by `Application::RunMessageLoop`, but its code is adjacent to `EventDispatcher` in the binary and calls the dispatcher traversal rebuild path. The most likely original placement is either a local helper in `EventDispatcher.cpp` or a small `MessageLoopScheduler` helper in the UI core folder. Its first step is draining [UID:0000HR][BlackHole](by-file/BlackHole.md), the deferred deletion queue, before timer and frame scheduling work.

## Likely File Contents

- `class EventDispatcher`.
- `class Event`, either in this file or in a small adjacent [UID:0000J6][Event](by-file/Event.md) file, depending on how fine-grained the original UI event module was.
- `EventMan` and the IME/packet event factory helpers are better candidates for [UID:0000J6][Event](by-file/Event.md) than for `EventDispatcher.cpp`: they create events, while this module routes already-built events.
- [UID:00004N][EventHandler](by-class/EventHandler.md), [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md), [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md), and [UID:000060][HandlerFindFunc](by-class/HandlerFindFunc.md) as handler traversal/support types.
- handler tree/list node structs and iterator helpers.
- `ApplicationHelper_4A6C40`, or preferably a renamed file-local `MessageLoopScheduler` helper used by `Application::RunMessageLoop`.
- globals such as `g_pEventDispatcher`, keyboard state snapshots, caps-lock state, frame registry references, and timer manager references.

## Evidence

- Wave3 reports `EventDispatcher` as a 15-method singleton with `TimerHandler` at offset `0x0`, an embedded `LObject`/tree at offset `0x4`, a handler-list sentinel pattern, a `FrameMgr` instance, and a default timer interval of 3000 ms.
- IDA MCP confirms the constructor at `0x004a6a80-0x004a6bee` is called from `Application::Initialize` at `0x00464613`.
- IDA MCP confirms `ApplicationHelper_4A6C40::ProcessIdleWork` at `0x004a6c40-0x004a6cda` is called from `Application::RunMessageLoop` at `0x00464df7` and `0x00464e0e`.
- IDA decompilation of `ProcessIdleWork` begins with `BlackHole::ReleaseQueuedOwnedObjects(dword_67A74C)`, then proceeds into timer and frame-dispatch work.
- IDA MCP disassembly on 2026-05-26 shows `ProcessIdleWork` calls `EventDispatcher::RebuildHandlerTraversalOrder` on helper offset `+0x4`, stores timer baseline/slice fields at `+0x2c` and `+0x30`, and dispatches changed slices through [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md).
- IDA MCP confirms `DispatchEvent` at `0x004a6ef0-0x004a6f33` has many callers, including application event adapter paths and event-object call sites.
- IDA MCP confirms `RouteEventToHandlers` at `0x004a7130-0x004a7567` calls `CallHandler`, translated-child dispatch, child-tree traversal, and key-state helpers.
- IDA MCP confirms `RouteEventToHandlers` also triggers [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) hotkeys, including BMP capture at `0x00557aa0` and PNG capture at `0x00557e80`; the screenshot implementation remains outside the dispatcher.
- 2026-05-26 IDA MCP recheck shows the screenshot hotkey calls remain in `RouteEventToHandlers`: BMP at `0x004a71b6` and `0x004a7250`, PNG at `0x004a71d1` and `0x004a7296`.
- Generated helper classes at `0x004a7cd0-0x004a7df3` document the concrete `Tree<EventHandler*>`, `TreeItor<EventHandler*>`, and `HandlerFindFunc` support island used by dispatcher traversal.
- IDA MCP recheck on 2026-05-25 resolves adjacent helper starts: `0x004a78f0` is enabled-handler iterator search, `0x004a7b10` is 28-byte handler-record vector insert/grow, `0x004a7d00` is handler/modal-list destruction, and `0x004a87a0` is handler-record vector free/clear.
- 2026-05-26 current-state recheck: `simroot_v2` still emits the concrete helper classes as standalone `class_Tree_near_class_EventHandler___.cpp`, `class_TreeItor_near_class_EventHandler___.cpp`, and `class_HandlerFindFunc.cpp`; `class_EventDispatcher.cpp` still references `sub_4A78F0` as an external helper from `RouteEventToHandlers`.
- 2026-05-26 IDA MCP recheck keeps the helper owners inside dispatcher infrastructure: `0x004a78f0` is called from `SetPaneOrder`, `RemovePaneEntry`, and `RouteEventToHandlers`; `0x004a7b10` is called from constructor/rebuild helper paths; `0x004a7d00` is called by the scalar deleting destructor path; and `0x004a87a0` is called by tree/destructor/rebuild cleanup paths.
- Generated `EventHandler` methods at `0x004a8970-0x004a8a83` document the base event-handler interface used by panes and dispatcher call sites.
- Older generated data projected `0x00597580` as an `EventDispatcher` destructor, but IDA body checks show it writes `TimerHandler::vftable` and unregisters through [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md). Keep that range with [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md), not this file.
- 2026-05-26 current-state recheck: `class_EventDispatcher.cpp` and `class_EventDispatcher.meta_wave3` still carry `0x00597580` as `~EventDispatcher`; treat that as stale generated ownership until the data issue is fixed.

## Migration Notes

- Rename or set simpath for `class_EventDispatcher.cpp` to `ui/core/EventDispatcher.cpp`.
- Attach the event-handler support classes and handler tree/list/vector helpers to this source family or declare them in adjacent UI event headers; do not migrate the generated one-class files as standalone feature modules.
- When migrating generated helpers, preserve the exact internal helper coverage for `0x004a78f0`, `0x004a7b10`, `0x004a7d00`, and `0x004a87a0`; current generated output omits or externs some of these bodies.
- Attach `ApplicationHelper_4A6C40` to this file as a helper, or split it only as a small `ui/core/MessageLoopScheduler.cpp` companion if future source-line evidence supports that. Do not preserve `ApplicationHelper_4A6C40.cpp` as a final source name.
- Keep [UID:0000J6][Event](by-file/Event.md) near this module. If the final project prefers one class per file for base event objects, use `ui/core/Event.cpp`; keep `EventMan` and the free event factories there or in an adjacent `EventMan.cpp`, not inside dispatcher routing code.
- Do not classify the dispatcher as application-core even though `Application` constructs it; event dispatch is UI infrastructure.

## Cross-References

- Classes: [UID:00004M][EventDispatcher](by-class/EventDispatcher.md), [UID:00004N][EventHandler](by-class/EventHandler.md), [UID:000060][HandlerFindFunc](by-class/HandlerFindFunc.md), [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md), [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md), [UID:00004L][Event](by-class/Event.md), [UID:00004O][EventMan](by-class/EventMan.md), [UID:00000E][ApplicationHelper_4A6C40](by-class/ApplicationHelper_4A6C40.md), [UID:00000W][BlackHole](by-class/BlackHole.md), [UID:00000D][Application](by-class/Application.md)
- Neighboring files: [UID:0000J6][Event](by-file/Event.md), [UID:0000HR][BlackHole](by-file/BlackHole.md), [UID:0000HG][Application](by-file/Application.md), [UID:0000K6][InputMan](by-file/InputMan.md), [UID:0000MC][Pane](by-file/Pane.md), [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- Memory: [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md), [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md), [UID:000143][0x004a7120-0x004a712b.ApplicationIdleTickBaseline](by-memory/0x004a7120-0x004a712b.ApplicationIdleTickBaseline.md), [UID:000144][0x004a78f0-0x004a7978.EventDispatcherFindHandlerIterator](by-memory/0x004a78f0-0x004a7978.EventDispatcherFindHandlerIterator.md), [UID:000145][0x004a7b10-0x004a7c29.EventDispatcherHandlerRecordVectorInsert](by-memory/0x004a7b10-0x004a7c29.EventDispatcherHandlerRecordVectorInsert.md), [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md), [UID:000147][0x004a7d00-0x004a7d42.EventDispatcherHandlerListDestructor](by-memory/0x004a7d00-0x004a7d42.EventDispatcherHandlerListDestructor.md), [UID:00022A][0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers](by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md), [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md), [UID:00022B][0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers](by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers.md), [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md), [UID:00014B][0x004a8a90-0x004ab434.EventObjects](by-memory/0x004a8a90-0x004ab434.EventObjects.md), [UID:00014C][0x004a8b40-0x004ab476.EventMan](by-memory/0x004a8b40-0x004ab476.EventMan.md), [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:80`.
  - Summary/evidence: event-routing responsibility, source placement, generated containers, likely contents, helper ownership, IDA call/xref evidence, migration notes, stale timer-handler ownership exclusion, and extensive class/file/memory cross-references are documented; confidence remains at 80 because `ApplicationHelper_4A6C40` final ownership and some generated helper splits remain open.
- 2026-05-31 projected path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/ui/core/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` already places `EventDispatcher.cpp` under `ui/core`, and this page documents strong IDA-backed UI event-routing ownership for the module.
