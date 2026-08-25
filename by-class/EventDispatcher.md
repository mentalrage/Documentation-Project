*** UID:00004M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "BlackHole.h"
#include "EventDispatcher.h"
#include "FrameMgr.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../../util/TimerHandler.h"
#include "../../util/Tree.h"
#include "EventHandler.h"

class EventDispatcher : public TimerHandler
{
public:
    EventDispatcher();
    virtual ~EventDispatcher();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

    bool SetPaneOrder(EventHandler *first, EventHandler *second,
                      bool placeAfter);
    bool DispatchEvent(Event *event);
    void ProcessIdleWork();
    void ArmTextInputGuardTimer();
    unsigned int CaptureIdleTickBaseline();

private:
    Tree<EventHandler *> m_handlerTree;
    EventHandler *m_activeHandler;
    EventHandler *m_contextHandler;
    EventHandler *m_currentHandler;
    void *m_modalHandlerList;
    int m_modalHandlerCount;
    bool m_textInputGuard;
    unsigned int m_idleTickBaseline;
    unsigned int m_lastDispatchedIdleSlice;
    bool m_cursorHideArmed;
    unsigned int m_cursorStillStartTick;
    unsigned int m_cursorHideDelayMs;
    int m_lastCursorX;
    int m_lastCursorY;
};

extern EventDispatcher *g_pEventDispatcher;

typedef char EventDispatcherSizeMustBe72[
    sizeof(EventDispatcher) == 0x48 ? 1 : -1];

[[CHILDREN]]
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EventDispatcher

## Current Accepted UID0004YK Generic Tree Consumer

EventDispatcher.h now includes ../../util/Tree.h and embeds Tree<EventHandler *> directly. The generic node remains 0x1c bytes: five link dwords, EventHandler* data at +0x14, disabled at +0x18, and three bytes of implicit tail padding. The embedded Tree remains 0x10 bytes and preserves the 0x48 EventDispatcher layout. Historical EventHandlerRecord, EventHandlerRecordVector, and EventHandlerTree declarations below are superseded analysis views; they are not duplicate authored types.

TreeFindFunc, TreeNode, TreeItor, generic Find/insert/remove, std::vector storage, inline destructors, and vtable consequences belong to NexusTK/util/Tree.h. Dispatcher routing, modal-list behavior, HandlerFindFunc, and wrapper calls remain EventDispatcher.cpp responsibilities.

## Historical Superseded UID0003ZT Complete Router Header Contract - 2026-07-23

- The complete public router declaration belongs in `NexusTK/ui/core/EventDispatcher.h`, after `#include "TimerHandler.h"` and `#include "EventHandler.h"` and after dispatcher-local handler-record/storage declarations required by the class layout.
- TimerHandler is a complete base dependency. EventHandler.h supplies EventHandler/EventPointPair and only forward-declares Event/EventDispatcher; it does not contain a partial duplicate router class.
- `EventHandler.cpp` includes EventDispatcher.h before its `SetPaneOrder` forwarding call. `EventDispatcher.cpp` owns constructor, registration, traversal, routing, idle-scheduler, and helper definitions already documented here.
- The complete Event/EventType/payload declaration remains in [UID:0000J6][Event](by-file/Event.md)'s self-contained Event.h. Router implementation includes it where record members are inspected; EventDispatcher.h does not absorb the record.
- MapPane's [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md) occupies the inherited EventHandler system/control slot but does not alter dispatcher ownership.
- The `89/91` score, owner/emitter [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), route-marker formal policy, class layout, and all current routing evidence remain unchanged.

## Summary

`EventDispatcher` is the UI event-routing singleton. It owns a timer-handler base, pane-entry tree/list structures, active/previous pane tracking, dispatch traversal order, modal list insertion, and recursive event dispatch into child handlers.

## Historical Superseded UID000090 Complete Dispatcher Header And Layout Closure - 2026-07-31

- The route-marker formal is replaced by a complete `EventDispatcher.h` declaration and a self-header CPP child route. `TimerHandler.h` provides the complete base and `EventHandler.h` provides the shared handler interface.
- `EventDispatcher.h` is the one-definition owner for `EventHandlerRecord`, `EventHandlerRecordVector`, and by-value `EventHandlerTree`. UID00022A retains iterator/list-node declarations and helper bodies but no longer owns duplicate local tree declarations.
- Exact allocation `operator new(0x48)` before the constructor and router offsets through `m_lastCursorY +0x44` prove the complete `0x48` object. Historical prose treating `+0x44` as an object boundary is superseded.
- Natural alignment supplies three bytes after each instance boolean. The explicit `EventHandlerRecord::reserved[3]` remains source-significant because accepted helper bodies copy and clear those bytes.
- The exact size guards are `EventHandlerRecordSizeMustBe28`, `EventHandlerTreeSizeMustBe16`, and `EventDispatcherSizeMustBe72`. A PCH-only tree declaration, forward-declared by-value tree, and duplicate CPP-local records are rejected.

## Likely Original Placement

- Source: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- Proposed path: `ui/core/EventDispatcher.cpp`
- Confidence: strong

## Methods

- `0x004a6a80` constructor - initializes `TimerHandler`, embedded `LObject` tree, sentinel entries, `FrameMgr`, keyboard state, and `g_pEventDispatcher`.
- `0x004a6ce0` `SetPaneOrder`.
- `0x004a6dd0` `RemovePaneEntry`.
- `0x004a6ef0` `DispatchEvent`.
- `0x004a6f40` `SetActivePaneEntry`.
- `0x004a6f80` `ContainsPaneEntry`.
- `0x004a6fa0` `ArmTextInputGuardTimer` - sets the dispatcher text-input guard and schedules timer id `0` after 10 ms; both LineInputPane constructor branches call it.
- `0x004a6fc0` `AddToModalList`.
- `0x004a7110` `OnTimerTick`.
- `0x004a7130` `RouteEventToHandlers`.
- `0x004a7570` `DispatchToChildren`.
- `0x004a7690` `DispatchToTranslatedChildren`.
- `0x004a77d0` `CallHandler`.
- `0x004a78f0` internal helper to find an enabled matching handler record and update a tree iterator.
- `0x004a7b10` compiler-covered `std::vector<TreeNode<EventHandler *> >` grow/insert instance caused by generic Tree insertion.
- `0x004a7cd0-0x004a7df4` handler tree support island: [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md), [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md), and [UID:000060][HandlerFindFunc](by-class/HandlerFindFunc.md). The linked by-memory filename still uses `0x004a7df3` as an older inclusive-terminal convention, but the audited half-open terminal is `0x004a7df4`.
  - UID000146 now emits only a formal split/index marker for that support island. The marker is an EventDispatcher.cpp output waypoint, not a class-level method body; exact behavior stays in the narrower tree/iterator/predicate/list/vector helper pages and this class-level formal block is a `[[CHILDREN]]` route marker until a full constructor/route/rebuild/destructor/header shell is ready.
- `0x004a7e00` scalar deleting destructor.
- `0x004a7e70` `RebuildHandlerTraversalOrder`.
- `0x004a87a0` compiler-covered `std::vector<TreeNode<EventHandler *> >` free/clear instance.
- `0x00597580` was formerly projected as an `EventDispatcher` destructor, but current docs resolve it as [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md).

The EventDispatcher handler tree uses 28-byte `TreeNode<EventHandler *>` entries with `parentIndex`, `firstChildIndex`, `lastChildIndex`, `previousSiblingIndex`, `nextSiblingIndex`, `data`, and `disabled` fields. The helper cluster at [UID:00022A][0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers](by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md), vector free at [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md), and allocation pair at [UID:00022B][0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers](by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers.md) are concrete `std::vector<TreeNode<EventHandler *> >`/generic Tree compiler instantiations. They remain exact evidence pages but do not emit EventDispatcher-local helper bodies.

UID0004YK resolves the generated [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md) alias as the concrete `Tree<EventHandler *>` instantiation, with `Tree_near_class_EventHandler___` / `near class` retained only as generated documentation spelling. The tree directly stores `std::vector<TreeNode<EventHandler *> >` at offset `+0x04`; `EventHandlerRecordVector records`, `TreeNodeData`, and `cls_0x4a87a0` are historical analysis labels. Generic source belongs to `NexusTK/util/Tree.h`; EventDispatcher remains only the concrete consumer and owns routing, HandlerFindFunc, modal-list behavior, and thin wrapper calls.

2026-06-21 B008 also resolves the Event predicate helpers consumed by route/call-handler code. The dispatcher should describe handler family dispatch as pointer/mouse `0..7`, key/text `8..10`, IME `11..17`, packet `18`, exact special slot `19`, and system/control `20..22`. Event/Event.cpp owns the predicate and producer bodies; EventDispatcher owns route selection and virtual handler invocation.

## Historical Superseded 2026-06-20 Method And Field Refresh

B001's [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md) aggregate report expands this class wrapper from the previously documented high-level routing methods to the full source-family inventory. The broad aggregate should not emit one monolithic C++ body; exact children and class methods should emit draft code from their narrower pages once field/type names are coordinated.

Additional source-facing method roles now tracked here:

| Range | Current best class/member role |
| --- | --- |
| `0x004a6bf0-0x004a6c3c` | constructor EH cleanup funclet, not a hand-written public method. |
| `0x004a6c40-0x004a6cdb` | `ProcessIdleWork()` / idle maintenance companion called from `Application::RunMessageLoop`; generated `ApplicationHelper_4A6C40` is rejected as a final class. |
| `0x004a6f40-0x004a6f75` | `SetActiveHandler` / active event target setter. |
| `0x004a6f80-0x004a6f9c` | active-or-context handler predicate. |
| `0x004a6fa0-0x004a6fb2` | text-input guard timer arming helper. |
| `0x004a7010-0x004a70a3` | remove modal handler from the dispatcher modal/list wrapper. |
| `0x004a70b0-0x004a70df` | find the first enabled modal handler. |
| `0x004a70e0-0x004a7104` | contains-modal-handler predicate. |
| `0x004a7110-0x004a7119` | timer callback that clears the text-input guard state. |
| `0x004a7120-0x004a712c` | `CaptureIdleTickBaseline()` companion to the idle worker. |
| `0x004a7980-0x004a7aef` | handler-record vector assignment/copy support. |
| `0x004a7af0-0x004a7b0a` | handler/modal list-node creation helper. |
| `0x004a7c30-0x004a7caa` | shared dword-fill/range helper used by vector/list setup. |
| `0x004a7cb0-0x004a7cbd` | short runtime assignment helper; source-visible only through tree/vector support. |
| `0x004a7cc0-0x004a7ccb` | constructor-unwind helper that clears `g_pEventDispatcher`. |
| `0x004a7e00-0x004a7e66` | scalar-deleting destructor wrapper and destructor body; source destructor must model normal teardown, while delete-flag behavior is compiler wrapper code. |

Current object-state roles:

| Offset | Current best role |
| --- | --- |
| `+0x00` | TimerHandler/base subobject and vtable-facing dispatcher head. |
| `+0x04` | Embedded handler tree object. |
| `+0x08/+0x0c/+0x10` | Handler-record vector begin/end/capacity pointers through the embedded tree. |
| `+0x14` | Active handler/pane entry. |
| `+0x18` | Context/previous handler slot used by active checks. |
| `+0x1c` | Current-handler/dispatch state used by the broader router; it is not the guard byte written by `0x004a6fa0`. |
| `+0x20/+0x24` | Handler/modal circular list wrapper pointer/count. |
| `+0x28` | Text-input guard byte set by `ArmTextInputGuardTimer` and cleared by the timer callback at `0x004a7110`. |
| `+0x2c` | `m_idleTickBaseline`. |
| `+0x30` | `m_lastDispatchedIdleSlice`. |
| `+0x34` | Frame/timer dispatch scratch. |
| `+0x38/+0x3c/+0x40` | Traversal rebuild/iteration scratch. |
| `+0x44` | Boundary after the known dispatcher-local state in this aggregate. |

[UID:00027B][0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag](by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md) is private `EventDispatcher.cpp` static storage, not an instance field. It gates the one-shot idle timer setup path in `ProcessIdleWork()` and is cleared before `m_idleTickBaseline` (`+0x2c`) and `m_lastDispatchedIdleSlice` (`+0x30`) are refreshed.

## UID00035P Text-Input Guard Source Contract - 2026-07-30

- The source-facing class API includes `void ArmTextInputGuardTimer();`. Its exact body at `0x004a6fa0-0x004a6fb2` writes the one-byte guard at `+0x28` and calls inherited `TimerHandler::ScheduleTimer(0, 10, 0, 0)`.
- [UID:00035P][0x004f1c00-0x004f2009.LineInputPaneConstructor](by-memory/0x004f1c00-0x004f2009.LineInputPaneConstructor.md) calls the method after attaching/ordering the pane in both layout branches. `RouteEventToHandlers` consumes the guard for text-input event routing, and the `0x004a7110` timer callback clears it. These paired set/use/clear paths reject generic timer, mouse-helper, and stale `arg1` interpretations.
- The complete future `EventDispatcher.h` declaration should include `void ArmTextInputGuardTimer();` and the one-byte text-input guard field at `+0x28` when the coordinated class-shell pass replaces this page's route-marker formal. This callback records the exact declaration/field role but does not create a partial duplicate class in the blank H block.
- Historical Gate-2B prestate was raw `sub_4A6FA0`, declaration `void __thiscall sub_4A6FA0(TimerHandler *this)`, stale address-regular `arg1`, the other three comment channels blank, and a sole return-address frame record. Catalog entry 0377 saves current `EventDispatcher__ArmTextInputGuardTimer`, declaration `void __thiscall(EventDispatcher *this)`, blank address regular/repeatable comments, function-regular comment `Arms the short text-input guard by setting the dispatcher guard flag and scheduling timer id 0 after 10 ms.`, and function-repeatable comment `void EventDispatcher::ArmTextInputGuardTimer();`. The frame still contains only `__return_address +0x0/4 _UNKNOWN *`; exact 18 bytes and both incoming xrefs are unchanged.
- UID00035P prestate/backup `4A9360D1...26C94` is dated history. The applied helper poststate is in authoritative saved IDB SHA256 `A0D97FC56A57D864269A7E79227523CB04C3F981C7634F138848D32854375971`, 143,195,218 bytes, saved `2026-07-30T14:32:20.6295670-04:00`.
- Class metadata stays `89/91`, owner/emitter UID0000J7, reconstructable true, and route-marker CPP with `[[CHILDREN]]`; the helper is one narrower method in EventDispatcher.cpp, not a broad class body.

## Historical Binary And Generated Evidence

- IDA MCP confirms the constructor is called from `Application::Initialize` at `0x00464613`.
- IDA MCP confirms `DispatchEvent` has many direct callers, including application event adapter paths.
- IDA MCP confirms `RouteEventToHandlers` calls child dispatch, translated-child dispatch, `CallHandler`, and keyboard-state helper paths.
- IDA MCP recheck on 2026-05-25 confirms the unresolved helper starts under `0x004a78f0-0x004a87a0` are dispatcher handler-tree/list/vector support, not independent feature files.
- IDA MCP confirms `0x00597580` is a function and still names it as a Boost exception destructor, but decompilation writes `TimerHandler::vftable` and calls the timer-manager remove-all helper. Treat `EventDispatcher` as a caller/derived timer owner, not the owner of that range.
- 2026-05-26 recheck against current `simroot_v2` and IDA MCP: the generated source still externs `sub_4A78F0`, still splits the concrete tree/iterator/predicate helper files, and still mis-attaches `0x00597580` to `~EventDispatcher`. IDA callers continue to keep `0x004a78f0`, `0x004a7b10`, `0x004a7d00`, and `0x004a87a0` inside the dispatcher handler-tree/list/vector cleanup paths.
- 2026-06-07 A010 live IDA refresh reconfirmed constructor `0x004a6a80` with caller `0x00464613`, central dispatch `0x004a6ef0` with broad UI/event caller coverage, and `RouteEventToHandlers` at `0x004a7130` as the immediate callee from dispatch. The same refresh keeps `0x004a78f0`, `0x004a7b10`, `0x004a7d00`, and `0x004a87a0` in dispatcher-owned handler search/vector/list cleanup paths through their callers.
- 2026-06-07 callee refresh shows `0x004a7130` calls keyboard-state helpers plus the child-dispatch/helper fanout, including `0x004a78f0`, `0x004a7570`, `0x004a7690`, and `0x004a77d0`; screenshot helper calls from this route are event-action side effects, not evidence for moving the dispatcher to image-writer ownership. `0x00597580` remains a modeled function with a stale public name and is still treated as TimerHandler base cleanup rather than an EventDispatcher method.
- Screenshot routing at `0x004a7130` is now closed at action level. A change in the low toggle bit of `VK_SCROLL` (`0x0069aea9`) relative to cached dword `0x0069af18` dispatches [UID:0004WM][0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP](by-memory/0x00557aa0-0x00557e73.ScreenPaneSaveScreenshotBMP.md) at `0x004a71b6` when Left Shift is held, or [UID:0004WN][0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG](by-memory/0x00557e80-0x00558239.ScreenPaneSaveScreenshotPNG.md) at `0x004a71d1` otherwise. Ctrl+LeftShift+3 dispatches BMP at `0x004a7250`; Ctrl+LeftShift+4 dispatches PNG at `0x004a7296`. One-byte state `0x0069af20` gates both chord branches, is set after either capture, and is cleared at `0x004a72b8` when the chord ends. These are dispatcher input-policy side effects; ScreenPane remains the class owner of the capture methods and ScreenshotCapture.cpp remains their source file.

## Assignment Gate

`CANONICAL_OWNER` / `EMITTER_UIDS` are set to [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md). The child is now `89/91`, the direct source-file parent is now `92/89`, and the relationship is direct by-structure ownership because this class is the principal class implemented by the EventDispatcher file.

## Historical Superseded 2026-06-21 B012 Source-Quality Closure

B012's class-level reanalysis raised this page to `88/90` without adding a broad formal C++ block. B010 now adds the accepted `[[CHILDREN]]` route marker and raises the page to `89/91`: the class is real, reachable, and strongly routed through [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) / `NexusTK/ui/core/EventDispatcher.cpp`, but a broad class-shell method body remains deferred until constructor, route, rebuild, destructor, idle scheduler, and `EventHandler` declaration work are coordinated across exact children.

Evidence basis:

- Local PE validation of `NexusTK.exe` (`MD5 4247e04e20b65d6414c7238aa8ff5515`, image base `0x00400000`) checked constructor, idle worker, dispatch/route, handler search/insert/list/tree/vector helpers, relink/free/allocation helpers, `EventHandlerBase`, `TimerHandlerDestructor`, vtable dwords, direct rel32 refs, read-only data, and padding.
- Current generated coverage correctly routes [UID:00004M], [UID:00004N][EventHandler](by-class/EventHandler.md), [UID:000060][HandlerFindFunc](by-class/HandlerFindFunc.md), [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md), [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md), and [UID:0001UF][EventDispatcherHandlerTreeLayouts](by-type/by-struct/EventDispatcherHandlerTreeLayouts.md) into `auto-generated/NexusTK/ui/core/EventDispatcher.cpp`; older `simroot_v2` and wave3 cache output remains stale for names such as `EventDispatcher::~TimerHandler`, `ApplicationHelper_4A6C40`, `sub_4A78F0`, and synthetic `link*` record fields.
- `Event` and `EventMan` producer/factory code remain in [UID:0000J6][Event](by-file/Event.md). Event/EventMan build payloads and call into the dispatcher; EventDispatcher owns routing, handler traversal, modal/active state, and virtual handler invocation.
- [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md) stays under [UID:0000F0][TimerHandler](by-class/TimerHandler.md) / [UID:0000OT][TimerMgr](by-file/TimerMgr.md). The dispatcher destructor is one consumer of the timer base destructor, not its owner.

Best current source-facing helper names:

| Address | Current best name / role |
| --- | --- |
| `0x004a6c40` | `EventDispatcher::ProcessIdleWork()`; generated `ApplicationHelper_4A6C40` is only a stale grouping label. |
| `0x004a7120` | `EventDispatcher::CaptureIdleTickBaseline()`. |
| `0x004a78f0` | `FindHandlerRecordIterator` / `FindEnabledHandlerRecordIterator`; the name should reflect that the helper mutates the passed iterator index. |
| `0x004a7b10` | `InsertHandlerRecord`; dispatcher-local 28-byte record vector insert/grow helper. |
| `0x004a7d00` | `DestroyEventHandlerList` / `EventHandlerList::~EventHandlerList`; tears down the dispatcher `+0x20` circular modal/list wrapper. |
| `0x004a7d60` | `HandlerFindFunc::IsMatch`; file-local or anonymous-namespace predicate comparing `record.handler` against the expected handler slot. |
| `0x004a7e00` | EventDispatcher scalar deleting destructor wrapper; source docs should model normal `~EventDispatcher()` teardown, not the delete-flag wrapper as hand-authored C++. |
| `0x004a7e70` | `EventDispatcher::RebuildHandlerTraversalOrder()`. |
| `0x004a82b0` | `InsertFirstChildHandlerRecord`. |
| `0x004a8350` | `InsertHandlerRecordAfterSibling`. |
| `0x004a8420` | `RemoveHandlerRecordAndDisableSubtree`. |
| `0x004a8680` | `CreateEventHandlerListNodeLinks`. |
| `0x004a86b0` | `RebindHandlerRecordVectorStorage`. |
| `0x004a8740` | `ReserveHandlerRecordVectorStorage`. |
| `0x004a87a0` | `FreeHandlerRecordVector`. |
| `0x004a8820` | `AllocateHandlerRecordBuffer`. |
| `0x004a8890` | `FreeHandlerRecordBuffer`. |

Best current structure/global names:

- `EventHandlerRecord`: `parentIndex`, `firstChildIndex`, `lastChildIndex`, `previousSiblingIndex`, `nextSiblingIndex`, `handler`, `isDisabled`, and padding.
- `EventHandlerRecordVector`: `begin`, `end`, `capacityEnd`.
- `EventHandlerTree`: vtable plus `EventHandlerRecordVector records`.
- `EventHandlerIterator`: vtable, `tree`, and `index`.
- `EventHandlerListNode`: `next`, `previous`, and handler/payload value.
- Dispatcher fields: `TimerHandler` base at `+0x00`, embedded `EventHandlerTree` at `+0x04`, record-vector pointers at `+0x08/+0x0c/+0x10`, active/context/current handler fields at `+0x14/+0x18/+0x1c`, modal/list wrapper at `+0x20/+0x24`, `m_idleTickBaseline` at `+0x2c`, and `m_lastDispatchedIdleSlice` at `+0x30`.
- Globals/static storage: `g_pEventDispatcher` at `0x0067ab30`, `g_pTimerMgr` at `0x0067ab80`, `g_pApplicationCleanupQueue` at `0x0067a74c`, `g_frameRegistry` at `0x0069ae10`, EventDispatcher keyboard-state storage at `0x0069ae18-0x0069af1c`, the keyboard chord gate at `0x0069af20`, and private file-static [UID:00027B][0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag](by-memory/0x0066d880-0x0066d888.ApplicationIdleSchedulerStaticFlag.md). The adjacent `g_pIdleWatcher` pointer is explicitly not dispatcher-owned.

Header/source placement inference:

- `EventDispatcher.h` should declare the dispatcher class and public routing API.
- `EventHandler.h` or an EventDispatcher-adjacent shared event header is the highest-probability final declaration location for `EventHandler`, because both Pane-derived handlers and EventDispatcher traversal need it. `Pane.h` is a weaker placement and should not be treated as sole owner.
- `Event.cpp` owns `Event`, `EventMan`, event predicates, and event factories. Do not merge producer/factory code into EventDispatcher merely because dispatcher calls consume those events.

Class-level C++ is a route marker rather than a broad class shell because a target-wide class snippet would have to guess too much at once: timer-handler inheritance, embedded tree/vector/list declarations, idle scheduler fields, keyboard globals, EventHandler virtual families, and method bodies whose safest first drafts belong in exact children. Safe helper C++ already exists in [UID:00022A][0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers](by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md), [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md), and [UID:00022B][0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers](by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers.md); B010 also emits first-draft bodies for UID000142/143/144/145/147 and declarations for UID000296/2AV/2AW.

## Score Rationale

- Completion is `89` because the class page now records singleton role, source placement, constructor/dispatch/routing methods, idle scheduler helpers, handler tree/vector/list support, exact record/vector/list/iterator fields, PE-validated helper roles, timer-base exclusion, Event/EventMan split, current generated-route state, stale generated-output exclusions, accepted `[[CHILDREN]]` route marker, and child-emitter source/body routes.
- Confidence is `91` because local PE validation, current by-* child pages, current generated coverage, vtable/read-only-data rows, support docs, and accepted B010 MCP evidence all agree on EventDispatcher ownership and helper boundaries. It remains below final audit because exact historical helper spellings, `EventHandler` virtual-family method names, `EventHandler.h` versus combined `EventDispatcher.h`, and central constructor/route/rebuild/destructor drafts still need coordinated source passes.

## Open Questions

- Exact historical spelling remains open for a few dispatcher-local helpers (`FindHandlerRecordIterator`, `DestroyEventHandlerList`, idle worker helpers), but the helper roles above are now high-probability and should be used instead of `sub_*`, `ApplicationHelper_4A6C40`, or generic `link*` names.
- `EventHandler` virtual-family names remain provisional. Use pointer/mouse, key/text, IME, packet, exact special type `19`, and system/control families until a wider Pane/EventHandler vtable naming pass resolves exact method names.
- `EventHandler` header placement is narrowed to shared `EventHandler.h` or an EventDispatcher-adjacent event header. `Pane.h` is unlikely as sole owner; a combined `EventDispatcher.h` remains possible.
- A broad class-shell formal body remains deferred until central constructor, route, rebuild, destructor, idle-worker, and EventHandler declaration shape are coordinated. The current formal block is a route marker with `[[CHILDREN]]`, and exact child emitters now carry accepted first-draft C++ where safe.

## Cross-References

- File: [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md)
- Related classes: [UID:00004N][EventHandler](by-class/EventHandler.md), [UID:000060][HandlerFindFunc](by-class/HandlerFindFunc.md), [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md), [UID:0000FA][TreeItor_near_class_EventHandler___](by-class/TreeItor_near_class_EventHandler___.md), [UID:00004L][Event](by-class/Event.md), [UID:00000E][ApplicationHelper_4A6C40](by-class/ApplicationHelper_4A6C40.md), [UID:00000D][Application](by-class/Application.md), [UID:0000A2][Pane](by-class/Pane.md)
- Memory: [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md), [UID:000144][0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator](by-memory/0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator.md), [UID:000145][0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert](by-memory/0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert.md), [UID:000146][0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport](by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md), [UID:000147][0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor](by-memory/0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor.md), [UID:00022A][0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers](by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md), [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md), [UID:00022B][0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers](by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers.md), [UID:00014A][0x004a8970-0x004a8a84.EventHandlerBase](by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md), [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md)

## Changes

- 2026-07-30 B008 UID00035P accepted ordinary implementation callback: preserved `89/91` and the route-marker formal; added the exact `ArmTextInputGuardTimer()` method declaration/role, corrected the guard field to `+0x28`, and linked its LineInputPane callers and paired timer clear. The callback itself made no IDA change; supervisor catalog entry 0377 subsequently saved and read back the canonical helper identity/prototype/comments and cleared stale `arg1` while preserving bytes, frame, and callers.

- 2026-06-30 B010 accepted EventDispatcher implementation callback:
  - Before: `COMPLETION:88`, `CONFIDENCE:90`, with the class page still described as blank/no broad C++.
  - Changed to: `COMPLETION:89`, `CONFIDENCE:91`; owner/emitter unchanged as [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), and formal `RECONSTRUCTION_CPP` now emits a `[[CHILDREN]]` route marker rather than a monolithic class shell.
  - Evidence: accepted B010 report used IDA MCP session `supervisor_resume_20260629` and preserved child routing for UID000142/143/144/145/147, UID000296/2AV/2AW, EventHandler UID00004N/14A, and support route markers.
- 2026-06-26 B014 idle scheduler static flag implementation:
  - Score unchanged at `88/90`.
  - Summary/evidence: synchronized class-level wording with UID00027B. The idle setup flag is now `s_idleTimerSetupPending`, private EventDispatcher.cpp static storage used by `ProcessIdleWork()`, not an `EventDispatcher` object field. The instance field map remains centered on `m_idleTickBaseline` at `+0x2c` and `m_lastDispatchedIdleSlice` at `+0x30`.
- 2026-06-21 B012 EventDispatcher class source-quality closure:
  - Before: score `85/86`, broad helper/header questions were still treated as open class blockers, and the class page did not yet carry a target-specific no-class-C++ proof under the active first-draft gate.
  - Changed to: score `88/90`, owner/emitter unchanged at [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md), formal class C++ intentionally blank at that time, and the B012 source-quality closure incorporated. Superseded by the 2026-06-30 B010 `[[CHILDREN]]` route marker above.
  - Summary/evidence: B012 local PE and documentation reanalysis validated the EventDispatcher constructor, idle worker, dispatch/route, handler search/insert/list/tree/vector helpers, relink/free/allocation helpers, EventHandlerBase, TimerHandlerDestructor boundary, vtable/read-only-data rows, rel32 reachability, and padding. The page now records best helper names, resolved `EventHandlerRecord`/vector/tree/iterator/list-node fields, `Event.cpp` producer split, `TimerHandlerDestructor` ownership exclusion, stale `ApplicationHelper_4A6C40`/`EventDispatcher::~TimerHandler` generated-output rejection, current generated coverage route, and the reason exact children rather than the class aggregate should emit first-draft C++.
- 2026-06-07 A010 Batch086 class coverage toss-up:
  - Before: score `82/82`, `AUTOGEN_PARENT_UID` blank.
  - After: score `85/86`, `AUTOGEN_PARENT_UID:0000J7`.
  - Evidence: live IDA reconfirmed constructor caller, broad `DispatchEvent` caller coverage, `RouteEventToHandlers` fanout, handler search/vector/list helper ownership, and the TimerHandler destructor exclusion; [UID:0000J7][EventDispatcher](by-file/EventDispatcher.md) was already `89/85`, so both child and direct parent meet the corrected 85/85 gate.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `82/82`.
  - Summary/evidence: dispatcher singleton role, major routing/tree/vector/modal/timer methods, helper islands, Application construction evidence, stale timer destructor ownership correction, open questions, and detailed memory cross-references are documented; remaining uncertainty is exact original helper spelling and refreshed generated ownership.
- 2026-05-31:
  - Before: `RECONSTRUCTABLE` metadata was blank.
  - After: marked `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP rechecks keep the constructor, event-routing methods, handler tree/list/vector helpers, and dispatcher cleanup paths under project-owned `EventDispatcher` UI infrastructure. Parent attachment and C++ reconstruction code remain blank because final helper declarations/source shape are not at the 95+ gate.
- 2026-06-17 B002 EventDispatcher handler-record source-quality sync:
  - Score unchanged at `85/86`.
  - Summary/evidence: B002's report for [UID:00022A][0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers](by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md), [UID:000148][0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree](by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md), and [UID:00022B][0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers](by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers.md) resolves the 28-byte handler-record fields, source-facing helper names, EventDispatcher ownership/emitter route, and first-draft code-entry status. This class page now points to those child emitters and keeps only exact original spelling/header placement as final-audit caveats.
- 2026-06-20 B001 aggregate source-quality execution:
  - Score unchanged at `85/86`.
  - Summary/evidence: B001's [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md) report expanded the class documentation with the full method/helper inventory, constructor EH cleanup and scalar-deleting destructor separation, active/context/text-input/modal helper roles, idle scheduler companion methods, and the current object field map through `+0x44`. Aggregate C++ remained blank in that historical pass because exact child pages were the proper first-draft emission units; B010 now emits aggregate/class route markers and exact child bodies.
- 2026-06-21 Rule 26 incorporation of B008 Tree specialization source-quality report:
  - Score unchanged at `85/86`.
  - Summary/evidence: B008's pass corrected the handler-tree support island endpoint to half-open `0x004a7df4`, resolved [UID:0000F8][Tree_near_class_EventHandler___](by-class/Tree_near_class_EventHandler___.md) to source-facing `Tree<EventHandler *>`, tied its `records` storage to `EventHandlerRecordVector`, and kept the concrete specialization under this EventDispatcher source family rather than standalone generated Tree output.
- 2026-06-21 Rule 26 incorporation of B008 EventMan/factory helper report:
  - Score unchanged at `85/86`.
  - Summary/evidence: [UID:00014C][0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers](by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md) now documents the Event classifier helper names and accepted type families that drive EventDispatcher's route and handler-family virtual slots. This narrows the remaining class question to exact original predicate/slot spellings, not behavior or ownership.

## 2026-08-24 B001 UID0000JM FrameMgr Dependency Reconciliation

- Preserved `89/91`, owner/emitter UID0000J7, the complete `0x48` EventDispatcher H declaration, all routing/tree/timer/modal source, and UID000142 `ProcessIdleWork` unchanged.
- Added only `#include "FrameMgr.h"` to the CPP preamble after `EventDispatcher.h` and before `[[CHILDREN]]`. `ProcessIdleWork` dereferences `g_frameRegistry` and calls `FrameMgr::DispatchDueFrameCallbacks`, so a complete FrameMgr declaration is a CPP dependency rather than an EventDispatcher.h dependency.
- The H formal is byte-preserved. No FrameMgr type/global definition, callback body, scheduler ownership, or duplicate declaration moved into EventDispatcher; Application/EventDispatcher remain construction/lifetime and idle-dispatch consumers.
