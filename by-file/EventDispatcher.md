*** UID:0000J7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# EventDispatcher

## Current Accepted UID0004YK Tree Integration

EventDispatcher remains a NexusTK/ui/core consumer and includes ../../util/Tree.h. Its embedded member is Tree<EventHandler *>, not duplicate EventHandlerRecord/EventHandlerRecordVector/EventHandlerTree source. The concrete 0x1c node layout, 0x10 Tree layout, and 0x48 dispatcher layout are preserved by TreeNode<EventHandler *>, std::vector storage, and normal alignment.

HandlerFindFunc and the thin search wrapper remain file-local dispatcher source. Generic Find, insertion, subtree removal, iterator layout, and inline destruction come from Tree.h. The 28-byte vector assignment/insert/growth/free helpers, concrete Tree/TreeItor destructors, vtables, RTTI, EH actions, and alignment are compiler consequences retained as evidence only. Historical record-wrapper and active-wave prose below is superseded, not a current lifecycle statement.

## Historical Superseded UID0003ZT Header Dependency Contract - 2026-07-23

- `NexusTK/ui/core/EventDispatcher.h` includes `TimerHandler.h` and `EventHandler.h` before declaring dispatcher-local handler records/storage and the complete `EventDispatcher` router shell. TimerHandler is a complete base dependency; EventHandler supplies handler pointers and `EventPointPair`.
- `NexusTK/ui/core/EventHandler.h` contains only forward declarations for Event and EventDispatcher plus the handler interface and `extern EventDispatcher *g_pEventDispatcher`; it must not embed a partial `EventDispatcher` class.
- `EventHandler.cpp` includes EventHandler.h and EventDispatcher.h before defining the forwarding method that calls `SetPaneOrder`.
- The complete Event/EventType/payload record remains owned by [UID:0000J6][Event](by-file/Event.md) in self-contained `Event.h`. Dispatcher implementation may include Event.h to inspect records, but neither EventDispatcher.h nor EventHandler.h absorbs or duplicates that declaration.
- `Pane.h` consumes the handler/timer facets separately, and MapPane's [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md) overrides the inherited system/control slot. No ownership or route change follows from that consumer.
- This committed graph preserves `92/89`, all existing routing/helper/idle-scheduler evidence, and the documented EventDispatcher.h/EventDispatcher.cpp source root.

## Historical Superseded UID000090 Complete Header And Record Ownership - 2026-07-31

- `NexusTK/ui/core/EventDispatcher.h` includes `../../util/TimerHandler.h` and `EventHandler.h`, then owns complete `EventHandlerRecord`, `EventHandlerRecordVector`, `EventHandlerTree`, and `EventDispatcher` declarations. This is the single declaration route for the by-value tree member.
- The dispatcher object is exactly `0x48` bytes. Allocation at `0x004645ef`, constructor call `0x00464613`, and router fields through `m_lastCursorY +0x44` reject the historical assertion that `+0x44` is the next-object boundary.
- `EventHandlerRecord` is exactly `0x1c` bytes and explicitly retains `reserved[3]` because accepted UID00022A source bodies copy and clear the complete tail dword. The tree is exactly `0x10` bytes; natural alignment supplies instance padding around dispatcher booleans.
- `EventDispatcher.cpp` includes its self-header and receives exact method/helper children through [UID:00004M][EventDispatcher](by-class/EventDispatcher.md). [UID:00022A][0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers](by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md) owns iterator/list-node/helper bodies only and consumes the header declarations.
- PCH-only record definitions, a forward-declared by-value tree, duplicate CPP-local record declarations, the old route-marker-only class formal, and historical `EventPointPair` wording are superseded and rejected. Shared offset outputs use `Point` from `RectBounds.h` through [UID:0004ZN][EventHandler](by-file/EventHandler.md).

## Proposed Original Placement

- Proposed source path: `ui/core/EventDispatcher.cpp`
- Proposed header path: `ui/core/EventDispatcher.h`
- Confidence: strong for `EventDispatcher`, dispatcher-local handler traversal support, idle scheduler helpers, and keyboard/chord global state; medium-high for exact original header factoring.

## Historical Generated Wave3 Containers

- `class_EventDispatcher.cpp`
- `class_EventHandler.cpp`
- `class_Tree_near_class_EventHandler___.cpp`
- `class_TreeItor_near_class_EventHandler___.cpp`
- `class_HandlerFindFunc.cpp`
- `class_Event.cpp`
- `class_ApplicationHelper_4A6C40.cpp`

## Responsibilities

This module owns the UI event-routing spine. It registers pane handlers, maintains dispatch traversal order, routes keyboard/pointer/timer events to pane handlers, handles modal list entries, and performs timer-driven dispatch maintenance. It also contains the message-loop idle scheduler helpers currently documented by the generated `ApplicationHelper_4A6C40` label.

`ApplicationHelper_4A6C40` is called by `Application::RunMessageLoop`, but its code is adjacent to `EventDispatcher` in the binary, receives `g_pEventDispatcher` as `ecx`, and calls the dispatcher traversal rebuild path. Treat the label as generated grouping terminology, not a final source class or source file. The best current source-facing placement is private/file-local EventDispatcher idle scheduler code, especially `EventDispatcher::ProcessIdleWork()` and `EventDispatcher::CaptureIdleTickBaseline()`. A small `MessageLoopScheduler` helper in the UI core folder remains a weaker future organization option. The idle worker first drains [UID:0000HR][BlackHole](by-file/BlackHole.md) through [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md), the deferred deletion queue, before timer and frame scheduling work. Its file-local data includes [UID:00027B][0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag](by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md), a private static bool emitted before the scheduler helper code rather than an `EventDispatcher` instance field.

## Likely File Contents

- `class EventDispatcher`.
- `class Event` declarations may be included by this source, but [UID:0000J6][Event](by-file/Event.md) is the current owner for Event/EventMan producer, predicate, and factory code.
- `EventMan` and the IME/packet event factory helpers should remain with [UID:0000J6][Event](by-file/Event.md), not `EventDispatcher.cpp`: they create events, while this module routes already-built events.
- Event predicate helpers are also Event/Event.cpp support, not dispatcher-owned factories. B008 resolves the dispatcher-consumed predicates as pointer/mouse `0..7`, key/text `8..10`, IME `11..17`, packet `18`, and system/control `20..22`, while EventDispatcher handles exact type `19` as a special route.
- [UID:00004N][EventHandler](by-class/EventHandler.md) and [UID:000060][HandlerFindFunc](by-class/HandlerFindFunc.md) remain dispatcher-facing support; [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md) and [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md) are concrete generic-instantiation evidence whose authored declarations and algorithms come from UID0004YK `Tree.h`.
- The embedded member is `Tree<EventHandler *>` with direct `std::vector<TreeNode<EventHandler *> >` storage. Standalone generated Tree files, generic `Tree.cpp`, and custom EventHandlerRecord/EventHandlerRecordVector/EventHandlerTree declarations are rejected.
- Dispatcher-local handler/modal list-node structures and HandlerFindFunc behavior remain local; generic tree iterators and algorithms do not.
- The 28-byte binary records are `TreeNode<EventHandler *>` with generic link, `data`, and `disabled` fields. UID00022A/UID000145/UID000148/UID00022B retain exact compiler-instantiation evidence for generic Tree/vector operations but emit no custom helper source.
- `ApplicationHelper_4A6C40` source-bearing children as private EventDispatcher idle scheduler helpers, with `EventDispatcher::CaptureIdleTickBaseline` as the current best descriptive name for [UID:000143][0x004a7120-0x004a712c.ApplicationIdleTickBaseline](by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md) and `s_idleTimerSetupPending` as the private file-static flag for [UID:00027B][0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag](by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md).
- globals such as `g_pEventDispatcher`, [UID:0002AV][0x0069ae18-0x0069af1c.EventDispatcherKeyboardStateGlobals](by-memory/0x0069ae18-0x0069af1c.EventDispatcherKeyboardStateGlobals.md), [UID:0002AW][0x0069af20-0x0069af21.KeyboardChordGateFlag](by-memory/0x0069af20-0x0069af21.KeyboardChordGateFlag.md), frame registry references, and timer manager references. The adjacent [UID:0002VY][0x0069af1c-0x0069af20.g_pIdleWatcher](by-memory/0x0069af1c-0x0069af20.g_pIdleWatcher.md) pointer is not dispatcher-owned storage.

## Historical Superseded 2026-06-20 Source-Quality Inventory

B001's [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md) source-quality report re-audits this file as the `EventDispatcher.cpp` source-module aggregate rather than a single C++ emission unit. The aggregate should stay attached to this file, but formal aggregate-level C++ should remain blank: the covered range contains many independent methods, compiler EH cleanup code, scalar-deleting wrappers, tree/list/vector support helpers, and exact child emitters that must emit from narrower by-memory pages.

The exact current inventory for this source family is:

| Range | Source role |
| --- | --- |
| `0x004a6a80-0x004a6bee` | `EventDispatcher` constructor, including timer-handler base setup, embedded tree/list initialization, keyboard state, `FrameMgr`, and `g_pEventDispatcher` publication. |
| `0x004a6bf0-0x004a6c3c` | Constructor EH cleanup funclet; source-visible only as unwind cleanup around partially constructed dispatcher state. |
| `0x004a6c40-0x004a6cdb` | `EventDispatcher::ProcessIdleWork()` / [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md); current filename uses the older `0x004a6cda` end and should be audited before any range rename. |
| `0x004a6ce0-0x004a6dcd` | `SetPaneOrder`, using handler-record lookup and relink support. |
| `0x004a6dd0-0x004a6eef` | `RemovePaneEntry`, using handler-record lookup and removal/disable paths. |
| `0x004a6ef0-0x004a6f33` | `DispatchEvent`, broad UI event-entry point. |
| `0x004a6f40-0x004a6f75` | Active handler setter. |
| `0x004a6f80-0x004a6f9c` | Active/context handler predicate. |
| `0x004a6fa0-0x004a6fb2` | `EventDispatcher::ArmTextInputGuardTimer()`: exact 18-byte member sets guard byte `+0x28` and schedules inherited timer id `0` after 10 ms; both LineInputPane constructor branches call it. |
| `0x004a6fc0-0x004a7009` | Modal handler insertion helper. |
| `0x004a7010-0x004a70a3` | Modal handler removal helper. |
| `0x004a70b0-0x004a70df` | Find first enabled modal handler. |
| `0x004a70e0-0x004a7104` | Modal-list membership predicate. |
| `0x004a7110-0x004a7119` | Timer callback that clears the text-input guard. |
| `0x004a7120-0x004a712c` | `EventDispatcher::CaptureIdleTickBaseline()` / [UID:000143][0x004a7120-0x004a712c.ApplicationIdleTickBaseline](by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md). |
| `0x004a7130-0x004a7567` | Main route-to-handlers method, including keyboard-state reads, screenshot hotkeys, cursor/timer side effects, and child/translated-child/call-handler dispatch. |
| `0x004a7570-0x004a7684` | Dispatch to child handlers. |
| `0x004a7690-0x004a77c4` | Dispatch to translated child handlers. |
| `0x004a77d0-0x004a78ea` | Call one handler through the pane/event virtual path. |
| `0x004a78f0-0x004a7979` | [UID:000144][0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator](by-memory/0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator.md). |
| `0x004a7980-0x004a7aef` | Handler-record vector assignment/copy support. |
| `0x004a7af0-0x004a7b0a` | Handler/modal list-node creation helper. |
| `0x004a7b10-0x004a7c2a` | [UID:000145][0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert](by-memory/0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert.md). |
| `0x004a7c30-0x004a7caa` | Shared dword-fill/range helper used by record/vector setup. |
| `0x004a7cb0-0x004a7cbd` | Short runtime assignment helper, not a standalone product feature. |
| `0x004a7cc0-0x004a7ccb` | Constructor-unwind helper that clears `g_pEventDispatcher`. |
| `0x004a7cd0-0x004a7df4` | [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md), with short `Tree<EventHandler *>` / `TreeItor<EventHandler *>` wrappers, `HandlerFindFunc`, list teardown, vector-free thunk, and padding; filename uses the older inclusive-terminal convention while the audited half-open end is `0x004a7df4`. |
| `0x004a7e00-0x004a7e66` | EventDispatcher scalar-deleting destructor/destructor body. |
| `0x004a7e70-0x004a82a9` | `RebuildHandlerTraversalOrder`, rebuilding the traversal vector/tree from pane ownership state. |

UID000146 source-family note: [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md) is an accepted formal split/index marker for the half-open `0x004a7cd0-0x004a7df4` handler-tree support island. It is not a blank emitter and should not become a synthetic monolithic C++ body; exact behavior remains represented by dispatcher-local `Tree<EventHandler *>`, `TreeItor<EventHandler *>`, `HandlerFindFunc`, handler-list, and handler-record helper pages owned/emitted through this [UID:0000J7] source file. Generated `EventDispatcher.cpp` must refresh from any stale UID000146 `82/86` Empty Emitter Marker state through validator output, not by hand-editing generated files.

Observed EventDispatcher object state now has stable source-facing roles: `+0x04` embedded handler tree, `+0x08/+0x0c/+0x10` handler-record vector pointers, `+0x14` active handler, `+0x18` context/previous handler, `+0x1c` current-handler/dispatch state, `+0x20/+0x24` handler/modal circular list wrapper, `+0x28` text-input guard byte, `+0x2c` `m_idleTickBaseline`, `+0x30` `m_lastDispatchedIdleSlice`, `+0x34` frame/timer scratch, `+0x38/+0x3c/+0x40` traversal scratch fields, and `+0x44` the next object-area boundary. `ArmTextInputGuardTimer` sets `+0x28`, route logic consumes it, and the timer callback clears it. These names are still descriptive rather than recovered source spellings, but they are strong enough for draft child C++ where the exact child emitter is otherwise ready.

## UID00035P Text-Input Guard Ownership - 2026-07-30

- `EventDispatcher.cpp` owns `void EventDispatcher::ArmTextInputGuardTimer()` at `[0x004a6fa0,0x004a6fb2)`. The receiver, adjacent router methods, guard field, TimerHandler base, route consumer, and timer clear callback all belong to EventDispatcher; Application, InputPanes, TimerMgr, and a free helper are dependencies/callers rather than owners.
- [UID:00035P][0x004f1c00-0x004f2009.LineInputPaneConstructor](by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md) calls this member after pane registration in both exact layout branches. The method sets byte `+0x28`, calls `ScheduleTimer(0,10,0,0)`, and is paired with the `0x004a7110` callback that clears the guard.
- Historical pre-Gate-2B physical state was `sub_4A6FA0`, a TimerHandler-shaped declaration, stale address-regular `arg1`, blank remaining comment channels, and a sole return-address frame record. Catalog entry 0377 saves current `EventDispatcher__ArmTextInputGuardTimer`, declaration `void __thiscall(EventDispatcher *this)`, blank address comments, exact function regular/repeatable comments for the guard action and source declaration, and the unchanged sole `__return_address +0x0/4 _UNKNOWN *` frame record. Exact 18 bytes and two incoming xrefs remain unchanged.
- UID00035P prestate/backup `4A9360D1...26C94` is dated history; authoritative saved IDB SHA256 `A0D97FC56A57D864269A7E79227523CB04C3F981C7634F138848D32854375971`, 143,195,218 bytes, saved `2026-07-30T14:32:20.6295670-04:00`, contains the applied poststate. This synchronization changes no source-file ownership or header factoring.
- File metadata remains `92/89`, `CANONICAL_OWNER:FILE`, and `NexusTK/ui/core/`; the helper is one EventDispatcher.cpp method and does not alter header factoring or the ownership of Event/EventMan producer code.

## Evidence

- Wave3 reports `EventDispatcher` as a 15-method singleton with `TimerHandler` at offset `0x0`, an embedded `LObject`/tree at offset `0x4`, a handler-list sentinel pattern, a `FrameMgr` instance, and a default timer interval of 3000 ms.
- IDA MCP confirms the constructor at `0x004a6a80-0x004a6bee` is called from `Application::Initialize` at `0x00464613`.
- IDA MCP confirms `ApplicationHelper_4A6C40::ProcessIdleWork` at `0x004a6c40-0x004a6cda` is called from `Application::RunMessageLoop` at `0x00464df7` and `0x00464e0e`.
- IDA decompilation of `ProcessIdleWork` begins with `BlackHole::ReleaseQueuedOwnedObjects` using [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md) / historical `dword_67A74C`, then proceeds into timer and frame-dispatch work.
- IDA MCP disassembly on 2026-05-26 shows `ProcessIdleWork` calls `EventDispatcher::RebuildHandlerTraversalOrder` on helper offset `+0x4`, stores timer baseline/slice fields at `+0x2c` and `+0x30`, and dispatches changed slices through [UID:0000Q0][g_frameRegistry](by-global/g_frameRegistry.md).
- 2026-06-26 B014 implementation for [UID:00027B][0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag](by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md) resolves the idle scheduler's private static as `s_idleTimerSetupPending`: exact bytes `01 00 00 00 00 00 00 00`, direct refs only at `0x004a6c4f`, `0x004a6c77`, and `0x004a6c92` inside `ProcessIdleWork`, and padding before the separate EventMan key table at `0x0066d888`.
- 2026-06-17 B001 source-quality audit for [UID:000143][0x004a7120-0x004a712c.ApplicationIdleTickBaseline](by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md) confirms `Application::RunMessageLoop` passes `g_pEventDispatcher` as `ecx`, selects `EventDispatcher::CaptureIdleTickBaseline` as the best helper name, and records `+0x2c` / `+0x30` as `m_idleTickBaseline` / `m_lastDispatchedIdleSlice`.
- IDA MCP confirms `DispatchEvent` at `0x004a6ef0-0x004a6f33` has many callers, including application event adapter paths and event-object call sites.
- IDA MCP confirms `RouteEventToHandlers` at `0x004a7130-0x004a7567` calls `CallHandler`, translated-child dispatch, child-tree traversal, and key-state helpers.
- `RouteEventToHandlers` owns screenshot hotkey selection but not screenshot implementation. It dispatches exact [UID:0004WM][0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP](by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md) and [UID:0004WN][0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG](by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md), both emitted through [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md).
- Scroll Lock routing uses the keyboard-state table at `0x0069ae18`: the low toggle bit of `VK_SCROLL` byte `0x0069aea9` is compared with the previous value in dword `0x0069af18`. Only a transition dispatches a capture. Left Shift held selects BMP at call `0x004a71b6`; without Left Shift, the same transition selects PNG at `0x004a71d1`. The constructor and route refs remain `0x004a6ba1`/`0x004a717b` for the table, `0x004a6bcc`/`0x004a718d` for the Scroll Lock byte, and `0x004a6bd6`, `0x004a7197`, and `0x004a71a4` for the cached low bit.
- Chord routing requires Ctrl plus Left Shift. Translated key `0x33` / `3` dispatches BMP at `0x004a7250`, and translated key `0x34` / `4` dispatches PNG at `0x004a7296`, but only while the one-byte latch [UID:0002AW][0x0069af20-0x0069af21.KeyboardChordGateFlag](by-memory/0x0069af20-0x0069af21.KeyboardChordGateFlag.md) is clear. The route compares the latch at `0x004a7245` and `0x004a728b`, sets it at `0x004a7255` and `0x004a729b` after dispatch, and clears it at `0x004a72b8` when the chord is no longer active. This prevents repeated captures while the chord remains held.
- The same refresh confirms `0x0069af1c` is the [UID:00006C][IdleWatcher](by-class/IdleWatcher.md) singleton pointer, with constructor/destructor/shutdown/main-menu refs outside dispatcher ownership; that tail is now split to [UID:0002VY][0x0069af1c-0x0069af20.g_pIdleWatcher](by-memory/0x0069af1c-0x0069af20.g_pIdleWatcher.md), leaving [UID:0002AV][0x0069ae18-0x0069af1c.EventDispatcherKeyboardStateGlobals](by-memory/0x0069ae18-0x0069af1c.EventDispatcherKeyboardStateGlobals.md) as a clean dispatcher child.
- Generated helper classes at `0x004a7cd0-0x004a7df3` document the concrete `Tree<EventHandler*>`, `TreeItor<EventHandler*>`, and `HandlerFindFunc` support island used by dispatcher traversal.
- IDA MCP recheck on 2026-05-25 resolves adjacent helper starts: `0x004a78f0` is enabled-handler iterator search, `0x004a7b10` is 28-byte handler-record vector insert/grow, `0x004a7d00` is handler/modal-list destruction, and `0x004a87a0` is handler-record vector free/clear.
- 2026-05-26 current-state recheck: `simroot_v2` still emits the concrete helper classes as standalone `class_Tree_near_class_EventHandler___.cpp`, `class_TreeItor_near_class_EventHandler___.cpp`, and `class_HandlerFindFunc.cpp`; `class_EventDispatcher.cpp` still references `sub_4A78F0` as an external helper from `RouteEventToHandlers`.
- 2026-05-26 IDA MCP recheck keeps the helper owners inside dispatcher infrastructure: `0x004a78f0` is called from `SetPaneOrder`, `RemovePaneEntry`, and `RouteEventToHandlers`; `0x004a7b10` is called from constructor/rebuild helper paths; `0x004a7d00` is called by the scalar deleting destructor path; and `0x004a87a0` is called by tree/destructor/rebuild cleanup paths.
- Generated `EventHandler` methods at `0x004a8970-0x004a8a84` document the base event-handler interface used by panes and dispatcher call sites; `0x004a8a84-0x004a8a90` is the padding boundary before the Event base constructor/destructor page.
- Older generated data projected `0x00597580` as an `EventDispatcher` destructor, but IDA body checks show it writes `TimerHandler::vftable` and unregisters through [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md). Keep that range with [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md), not this file.
- 2026-05-26 current-state recheck: `class_EventDispatcher.cpp` and `class_EventDispatcher.meta_wave3` still carry `0x00597580` as `~EventDispatcher`; treat that as stale generated ownership until the data issue is fixed.

## Current UID0004YK Migration Contract

- Keep `EventDispatcher.h` and `EventDispatcher.cpp` as consumers of `../../util/Tree.h`; the embedded member is `Tree<EventHandler *>` and its storage is `std::vector<TreeNode<EventHandler *> >`.
- Keep `HandlerFindFunc`, dispatcher routing, modal/list-node behavior, idle scheduling, and thin generic-tree call sites in the EventDispatcher source family.
- Treat the relink/search/vector/destructor/vtable pages as concrete generic-template or compiler/library evidence. They do not authorize duplicate `EventHandlerRecord`, `EventHandlerRecordVector`, or `EventHandlerTree` declarations or hand-lowered helper bodies.

## Historical Superseded Migration Notes

- 2026-06-21 B012 class-level reanalysis keeps this file as the EventDispatcher source-family owner and records the current source-quality decisions:
  - Current generated coverage routes [UID:00004M][EventDispatcher](by-class/EventDispatcher.md), [UID:00004N][EventHandler](by-class/EventHandler.md), [UID:000060][HandlerFindFunc](by-class/HandlerFindFunc.md), [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md), [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md), and [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) into `auto-generated/NexusTK/ui/core/EventDispatcher.cpp`.
  - The best helper names are now `EventDispatcher::ProcessIdleWork`, `EventDispatcher::CaptureIdleTickBaseline`, `FindHandlerRecordIterator` / `FindEnabledHandlerRecordIterator`, `InsertHandlerRecord`, `DestroyEventHandlerList`, `HandlerFindFunc::IsMatch`, `EventDispatcher::RebuildHandlerTraversalOrder`, `InsertFirstChildHandlerRecord`, `InsertHandlerRecordAfterSibling`, `RemoveHandlerRecordAndDisableSubtree`, `CreateEventHandlerListNodeLinks`, `RebindHandlerRecordVectorStorage`, `ReserveHandlerRecordVectorStorage`, `FreeHandlerRecordVector`, `AllocateHandlerRecordBuffer`, and `FreeHandlerRecordBuffer`.
  - `EventHandlerRecord`, `EventHandlerRecordVector`, `EventHandlerTree`, `EventHandlerIterator`, and `EventHandlerListNode` field names are no longer generic `link*` placeholders; use the resolved names in [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md).
  - Stale `simroot_v2` / wave3 output that emits `EventDispatcher::~TimerHandler(this)`, retains `0x00597580` as EventDispatcher-owned, or preserves `ApplicationHelper_4A6C40.cpp` / `sub_*` helpers as final source must be treated as historical generated output, not current source-quality truth.
  - [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md) remains [UID:0000F0][TimerHandler](by-class/TimerHandler.md) / [UID:0000OT][TimerMgr](by-file/TimerMgr.md) code. EventDispatcher is a derived/base-cleanup consumer only.

- Rename or set simpath for `class_EventDispatcher.cpp` to `ui/core/EventDispatcher.cpp`.
- Attach the event-handler support classes and handler tree/list/vector helpers to this source family or declare them in adjacent UI event headers; do not migrate the generated one-class files as standalone feature modules.
- When migrating generated helpers, preserve the exact internal helper coverage for `0x004a78f0`, `0x004a7b10`, `0x004a7d00`, and `0x004a87a0`; current generated output omits or externs some of these bodies.
- B010's 2026-06-30 accepted empty-emitter implementation resolves the 16 current empty generated markers for this source root. Formal first-draft declarations/bodies now emit from [UID:00004N][EventHandler](by-class/EventHandler.md), [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md), [UID:000060][HandlerFindFunc](by-class/HandlerFindFunc.md), [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md), [UID:000143][0x004a7120-0x004a712c.ApplicationIdleTickBaseline](by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md), [UID:000144][0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator](by-memory/0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator.md), [UID:000145][0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert](by-memory/0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert.md), [UID:000147][0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor](by-memory/0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor.md), [UID:000296][0x0067ab30-0x0067ab34.g_pEventDispatcher](by-memory/0x0067ab30-0x0067ab34.g_pEventDispatcher.md), [UID:0002AV][0x0069ae18-0x0069af1c.EventDispatcherKeyboardStateGlobals](by-memory/0x0069ae18-0x0069af1c.EventDispatcherKeyboardStateGlobals.md), and [UID:0002AW][0x0069af20-0x0069af21.KeyboardChordGateFlag](by-memory/0x0069af20-0x0069af21.KeyboardChordGateFlag.md). Formal route/source-placement markers with `[[CHILDREN]]` now emit from [UID:00004M][EventDispatcher](by-class/EventDispatcher.md), [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md), [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md), [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md), and [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md).
- Current MCP bytes for the keyboard globals are zero-filled, not image-initialized `0xff`. Runtime initialization occurs through `GetKeyboardState` and EventDispatcher route writes. Keep [UID:0002AV][0x0069ae18-0x0069af1c.EventDispatcherKeyboardStateGlobals](by-memory/0x0069ae18-0x0069af1c.EventDispatcherKeyboardStateGlobals.md) and [UID:0002AW][0x0069af20-0x0069af21.KeyboardChordGateFlag](by-memory/0x0069af20-0x0069af21.KeyboardChordGateFlag.md) under this file, and keep [UID:0002VY][0x0069af1c-0x0069af20.g_pIdleWatcher](by-memory/0x0069af1c-0x0069af20.g_pIdleWatcher.md) outside dispatcher ownership.
- Attach the source-bearing `ApplicationHelper_4A6C40` children to this file as private idle scheduler helpers, or split them only as a small `ui/core/MessageLoopScheduler.cpp` companion if future source-line evidence supports that. Do not preserve `ApplicationHelper_4A6C40.cpp` as a final source name.
- Emit [UID:00027B][0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag](by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md) as private EventDispatcher.cpp static storage before `EventDispatcher::ProcessIdleWork()`; do not model it as an object field, TimerMgr/EventMan global, or Application-owned data.
- Keep [UID:0000J6][Event](by-file/Event.md) near this module. If the final project prefers one class per file for base event objects, use `ui/core/Event.cpp`; keep `EventMan` and the free event factories there or in an adjacent `EventMan.cpp`, not inside dispatcher routing code.
- Do not classify the dispatcher as application-core even though `Application` constructs it; event dispatch is UI infrastructure.

## Cross-References

- Classes: [UID:00004M][EventDispatcher](by-class/EventDispatcher.md), [UID:00004N][EventHandler](by-class/EventHandler.md), [UID:000060][HandlerFindFunc](by-class/HandlerFindFunc.md), [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md), [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md), [UID:00004L][Event](by-class/Event.md), [UID:00004O][EventMan](by-class/EventMan.md), [UID:00000E][ApplicationHelper_4A6C40](by-class/ApplicationHelper_4A6C40.md), [UID:00000W][BlackHole](by-class/BlackHole.md), [UID:00000D][Application](by-class/Application.md)
- Neighboring files: [UID:0000J6][Event](by-file/Event.md), [UID:0000HR][BlackHole](by-file/BlackHole.md), [UID:0000HG][Application](by-file/Application.md), [UID:0000K6][InputMan](by-file/InputMan.md), [UID:0000MC][Pane](by-file/Pane.md), [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- Globals: [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md)
- Memory: [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md), [UID:000142][0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler](by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md), [UID:000143][0x004a7120-0x004a712c.ApplicationIdleTickBaseline](by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md), [UID:000144][0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator](by-memory/0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator.md), [UID:000145][0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert](by-memory/0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert.md), [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md), [UID:000147][0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor](by-memory/0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor.md), [UID:00022A][0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers](by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md), [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md), [UID:00022B][0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers](by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers.md), [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md), [UID:00014B][0x004a8a90-0x004a8abf.EventBaseConstructorDestructor](by-memory/0x004a8a90-0x004a8abf.EventBaseConstructorDestructor.md), [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md), [UID:0002AV][0x0069ae18-0x0069af1c.EventDispatcherKeyboardStateGlobals](by-memory/0x0069ae18-0x0069af1c.EventDispatcherKeyboardStateGlobals.md), [UID:0002AW][0x0069af20-0x0069af21.KeyboardChordGateFlag](by-memory/0x0069af20-0x0069af21.KeyboardChordGateFlag.md), [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md)

## Changes

- 2026-07-30 B008 UID00035P accepted ordinary implementation callback: preserved `92/89` and the established source root; recorded exact EventDispatcher.cpp ownership, `ArmTextInputGuardTimer()` behavior/callers, corrected guard-byte `+0x28` state, and paired timer clear. The ordinary callback made no IDA change; supervisor catalog entry 0377 later applied and read back the canonical helper name/prototype/comments and stale-address-comment removal under saved IDB `A0D97FC5...4375971`.

- 2026-06-30 B010 accepted empty-emitter implementation:
  - Before: `COMPLETION:89`, `CONFIDENCE:85`, with 16 empty generated emitters under this source root and stale `0xff` initializer wording in keyboard support pages.
  - Changed to: `COMPLETION:92`, `CONFIDENCE:89`; owner/path unchanged as `CANONICAL_OWNER:FILE`, `NexusTK/ui/core/`.
  - Summary/evidence: B010 report `tools/leaser/Agents/Agent-B010/research/0000J7-EventDispatcher-empty-emitter-family-source-quality.md` applied formal EventHandler interface/default bodies, dispatcher helper bodies, route markers with `[[CHILDREN]]`, and source data declarations. MCP session `supervisor_resume_20260629` confirmed the EventHandler vtable/default bodies, dispatcher helper function sizes, singleton pointer, zero-filled keyboard globals, and `0x69af1c` IdleWatcher exclusion. Score remains below final audit because constructor/route/destructor/rebuild full bodies and exact header split are still inferred.
- 2026-06-26 B014 idle scheduler static flag implementation:
  - Score unchanged at `89/85`.
  - Summary/evidence: incorporated the accepted UID00027B source decision into this source-file page. `s_idleTimerSetupPending` is now documented as private EventDispatcher.cpp static storage used by `EventDispatcher::ProcessIdleWork()`, with exact xrefs and the EventMan successor boundary preserved. This resolves the earlier provisional `ApplicationHelper_4A6C40` static-flag wording without changing aggregate C++ policy.
- 2026-06-07 A009 Batch038 parent-gate refresh:
  - Before: `COMPLETION:88`, `CONFIDENCE:80`; keyboard globals were summarized generically, and the page did not yet carry the direct xref evidence required to serve as the parent for the one-byte chord gate under the corrected 85/85 child-and-parent gate.
  - After: `COMPLETION:89`, `CONFIDENCE:85`; added live IDA evidence for `KeyState`, `byte_69AEA9`, `dword_69AF18`, and [UID:0002AW][0x0069af20-0x0069af21.KeyboardChordGateFlag](by-memory/0x0069af20-0x0069af21.KeyboardChordGateFlag.md), while explicitly excluding the adjacent `IdleWatcher` singleton pointer from dispatcher ownership.
  - Why: current IDA xrefs justify direct EventDispatcher ownership of the keyboard/chord globals. Residual uncertainty around `ApplicationHelper_4A6C40` placement remains documented, so confidence rises only to the parent-gate threshold rather than final.
- 2026-06-07 A009 Batch038 split follow-up:
  - Updated references after [UID:0002AV][0x0069ae18-0x0069af1c.EventDispatcherKeyboardStateGlobals](by-memory/0x0069ae18-0x0069af1c.EventDispatcherKeyboardStateGlobals.md) was split from [UID:0002VY][0x0069af1c-0x0069af20.g_pIdleWatcher](by-memory/0x0069af1c-0x0069af20.g_pIdleWatcher.md).
  - Why: the EventDispatcher parent now owns the keyboard subrange directly, while the IdleWatcher singleton pointer has its own app-level parent.

- 2026-06-07: Replaced the raw `dword_67A74C` idle-work cleanup reference with canonical [UID:0000Q8][g_pApplicationCleanupQueue](by-global/g_pApplicationCleanupQueue.md) wording.
  - Before: the `ProcessIdleWork` evidence described the BlackHole drain through the historical generated global only.
  - After: the page links the resolved deferred-cleanup singleton while retaining the historical label for IDA traceability.
  - Evidence: the generated resolved-name report maps `dword_67A74C` to `g_pApplicationCleanupQueue`, and the existing IDA evidence places the drain at the start of `ApplicationHelper_4A6C40::ProcessIdleWork`.

- 2026-06-17 B001 idle-baseline source-quality sync:
  - Score unchanged at `89/85`.
  - Summary/evidence: B001's [UID:000143][0x004a7120-0x004a712c.ApplicationIdleTickBaseline](by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md) report rechecked the EventDispatcher baseline helper and confirmed the source-facing route through this file, with `EventDispatcher::CaptureIdleTickBaseline`, `m_idleTickBaseline`, and `m_lastDispatchedIdleSlice` as current best descriptive names. Formal C++ remains deferred to a coordinated EventDispatcher idle-scheduler source pass.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:80`.
  - Summary/evidence: event-routing responsibility, source placement, generated containers, likely contents, helper ownership, IDA call/xref evidence, migration notes, stale timer-handler ownership exclusion, and extensive class/file/memory cross-references are documented; confidence remains at 80 because `ApplicationHelper_4A6C40` final ownership and some generated helper splits remain open.
- 2026-05-31 projected path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/ui/core/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` already places `EventDispatcher.cpp` under `ui/core`, and this page documents strong IDA-backed UI event-routing ownership for the module.
- 2026-06-17 B002 EventDispatcher handler-record source-quality sync:
  - Score unchanged at `89/85`.
  - Summary/evidence: B002's report for [UID:00022A][0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers](by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md), [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md), and [UID:00022B][0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers](by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers.md) resolves the dispatcher-local `EventHandlerRecord` field names, helper roles, vector allocation/free policy, first-draft code-entry status, and confirms these by-memory emitters belong under `ui/core/EventDispatcher.cpp`. Exact original helper spelling remains a final-audit item, not a reason to keep draft C++ blank.
- 2026-06-20 B001 EventDispatcher aggregate source-quality execution:
  - Score unchanged at `89/85`.
  - Summary/evidence: B001's [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md) report was incorporated into this source-file page. The page now records the exact constructor, EH cleanup, idle scheduler, active/context/text-input/modal helpers, dispatch/child/translated-child/call-handler helpers, handler-vector/tree/list support, scalar-deleting destructor, and traversal-rebuild inventory; rejects `ApplicationHelper_4A6C40.cpp` as a final source file; and keeps aggregate-level C++ blank because first-draft source should emit from exact child by-memory pages rather than from this broad source-module aggregate.
- 2026-06-21 Rule 26 incorporation of B008 Tree specialization source-quality report:
  - Score unchanged at `89/85`.
  - Summary/evidence: B008's report resolves [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md) as concrete `Tree<EventHandler *>` support under this file, replaces `TreeNodeData`/`near_class` generated wording with `EventHandlerRecordVector records`, verifies the local PE destructor ranges and inherited `LObject` vtable slots, rejects standalone generated Tree source files, and keeps the class-page C++ blank until reusable `Tree<T>` header/template factoring is proven.
- 2026-06-21 Rule 26 incorporation of B008 EventMan/factory helper report:
  - Score unchanged at `89/85`.
  - Summary/evidence: [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md) now records the Event predicate helper names and route families consumed by EventDispatcher. This file remains the route/handler owner, while Event/Event.cpp owns event producers, predicates, EventMan methods, IME/packet factories, and notification routing.
