** TARGET-REPORT-UID:000141 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001 Source-Quality Report: [UID:000141] EventDispatcher

Report-only assignment. I did not edit the target by-memory document, support docs, generated files, or `by-memory/-coverage-report.md`.

## Target

- Primary target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x004a6a80-0x004a82a9.EventDispatcher.md`
- Required report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\000141-EventDispatcher-source-quality.md`
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000J7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000J7`, formal C++ blank.
- Current source target: `auto-generated/NexusTK/ui/core/EventDispatcher.cpp`.

## Evidence Checked

- Governing instructions:
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
  - `.codex/AGENTS.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B001/goal.md`
  - `source-3/project-documentation/by-structure.md`
  - `source-3/project-documentation/inference_research.md`
- Primary target:
  - `source-3/project-documentation/by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md`
- Direct EventDispatcher support:
  - `source-3/project-documentation/by-file/EventDispatcher.md`
  - `source-3/project-documentation/by-class/EventDispatcher.md`
  - `source-3/project-documentation/by-class/ApplicationHelper_4A6C40.md`
  - `source-3/project-documentation/by-class/EventHandler.md`
  - `source-3/project-documentation/by-type/by-struct/EventDispatcherHandlerTreeLayouts.md`
  - `source-3/project-documentation/by-memory/0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler.md`
  - `source-3/project-documentation/by-memory/0x004a7120-0x004a712c.ApplicationIdleTickBaseline.md`
  - `source-3/project-documentation/by-memory/0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator.md`
  - `source-3/project-documentation/by-memory/0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert.md`
  - `source-3/project-documentation/by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md`
  - `source-3/project-documentation/by-memory/0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor.md`
  - `source-3/project-documentation/by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerTreeMutators.md`
  - `source-3/project-documentation/by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md`
  - `source-3/project-documentation/by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordBufferAllocation.md`
  - `source-3/project-documentation/by-memory/0x00619628-0x00619670.EventDispatcherHandlerTreeVtableData.md`
  - `source-3/project-documentation/by-memory/0x0067ab30-0x0067ab34.g_pEventDispatcher.md`
  - `source-3/project-documentation/by-memory/0x0069ae18-0x0069af1c.EventDispatcherKeyboardStateGlobals.md`
  - `source-3/project-documentation/by-memory/0x0069af20-0x0069af21.KeyboardChordGateFlag.md`
- Event/timer/cursor context:
  - `source-3/project-documentation/by-file/Event.md`
  - `source-3/project-documentation/by-class/Event.md`
  - `source-3/project-documentation/by-memory/0x004a90a0-0x004a99c9.EventManAndEventFactoryHelpers.md`
  - `source-3/project-documentation/by-memory/0x00557430-0x00557440.CursorVisibilityWrappers.md`
  - `source-3/project-documentation/by-class/TimerHandler.md`
  - `source-3/project-documentation/by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`
- Prior agent evidence:
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B001/executed/000143-application-idle-tick-baseline-source-quality.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B001/executed/00014A-eventhandler-base-source-quality.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B002/executed/00022A-000148-00022B-eventdispatcher-handler-record-source-quality.md`
  - `source-3/project-documentation/tools/leaser/Agents/Supervisor_notes.md`
- Coverage/status files:
  - `source-3/project-documentation/by-memory/-coverage-report.md`
  - `source-3/project-documentation/auto-generated/-ag-memory-coverage.md`
  - `source-3/project-documentation/project-level/-auto-completion-stats.md`
- Binary evidence:
  - Local PE: `E:\NTK\Resources\NexusTK\NexusTK.exe`
  - MD5: `4247E04E20B65D6414C7238AA8FF5515`
  - Image base: `0x00400000`
  - Cross-checked with the read-only copy at `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - Parsed `.text` bytes, direct rel32 call/jump refs, absolute immediate refs, vtable refs, padding bytes, and exported JSON function ranges.

## Executive Conclusion

`[UID:000141]` is source-owned by the `EventDispatcher` runtime cluster, but it is not a good single formal C++ emission unit. The range is a broad aggregate containing many source-authored methods, exact existing children, remaining child-split candidates, constructor EH cleanup, scalar-deleting destructor glue, and small compiler/runtime helpers. The target should stay blank for aggregate formal C++ and should explain that this is an exact target-specific no-code decision for the aggregate, not a reconstruction failure.

The correct source-quality direction is to keep `EventDispatcher.cpp` as the owner/source file, reject `ApplicationHelper_4A6C40` as a real source class, move C++ into exact source-bearing child docs, and split the remaining unsplit bodies before trying to emit production-style code. Existing exact children `[000144]`, `[000145]`, and `[000147]` are now above the active 85/85 gate and should not keep stale below-95 no-code reasoning.

Recommended immediate metadata for `[000141]`: raise to `COMPLETION:86`, `CONFIDENCE:90`; keep `CANONICAL_OWNER:0000J7`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000J7` until exact child splits absorb all source-authored methods; keep aggregate formal C++ blank with an explicit no-aggregate-C++ proof.

Preferred later state after exact splits: make `[000141]` a non-emitting source-module aggregate/index while exact child docs emit first-draft C++ for constructor, scheduler, ordering/removal, routing, modal/active helpers, traversal, and rebuild bodies.

## Function Inventory and Range Findings

The aggregate currently underdescribes the number of independent routines between `0x004a6a80` and `0x004a82a9`. The target should replace the broad method list with this source-quality inventory. Ranges below are half-open, using the exported function start and size where available.

| Range | Best source-facing role | Evidence and recommendation |
| --- | --- | --- |
| `0x004a6a80-0x004a6bee` | `EventDispatcher::EventDispatcher()` | Constructor called from application startup at `0x00464613`; installs `g_pEventDispatcher`, EventDispatcher vtable `0x0061963c`, handler tree vtable `0x0061962c`, handler-record vector, modal list, idle/cursor/input fields, keyboard globals. Source-authored and first-draft eligible as an exact child. |
| `0x004a6bf0-0x004a6c3c` | constructor EH cleanup funclet | Ghidra-only cleanup path with no normal source method identity. It restores vtables, destroys list/tree/vector/base/timer pieces, clears `g_pEventDispatcher`, and is reached by unwind metadata. No formal C++; document as compiler-generated cleanup. |
| `0x004a6c40-0x004a6cdb` | `EventDispatcher::ProcessIdleWork()` / existing `[000142] ApplicationIdleWorkScheduler` | Called from application idle sites `0x00464df7` and `0x00464e0e` with `ecx=g_pEventDispatcher`. Drains cleanup queue, updates refresh/timer manager, calls traversal rebuild `0x004a7e70`, samples timer ticks, dispatches frame slices through `g_frameRegistry`. Source belongs in `EventDispatcher.cpp`, not `ApplicationHelper_4A6C40`. Validator should recheck child filename/end (`0x004a6cda` doc title versus exported half-open end `0x004a6cdb`). |
| `0x004a6ce0-0x004a6dcd` | `EventDispatcher::SetPaneOrder(EventHandler *handler, EventHandler *afterHandler, EventHandler *parentHandler)` | Uses `FindHandlerIterator`, `InsertHandlerRecordAfterSibling`, and `InsertFirstChildHandlerRecord`. Source-authored ordering/register helper. Split candidate. |
| `0x004a6dd0-0x004a6eef` | `EventDispatcher::RemovePaneEntry(EventHandler *handler)` | Clears active handler if needed, removes matching modal-list node, then calls `RemoveHandlerRecordAndDisableSubtree`. Source-authored unregister helper. Split candidate. |
| `0x004a6ef0-0x004a6f33` | `EventDispatcher::DispatchEvent(Event *event)` | Gate before route; skips route for event type `20` or suspended/blocked application state; frees payload for a heap-payload event predicate after route. Source-authored public dispatch entry. Split candidate. |
| `0x004a6f40-0x004a6f75` | `EventDispatcher::SetActiveHandler(EventHandler *handler)` | Sets or clears active handler fields `+0x14` and `+0x18`; when setting, captures current dispatch handler `+0x1c` as context. Called from Pane/EventHandler paths. Split candidate. |
| `0x004a6f80-0x004a6f9c` | `EventDispatcher::IsActiveOrContextHandler(EventHandler *handler) const` | Returns whether argument matches `+0x14` or `+0x18`. Called from Pane paths. Split candidate. |
| `0x004a6fa0-0x004a6fb2` | `EventDispatcher::ArmTextInputGuardTimer()` | Sets byte `+0x28`, then calls `TimerHandler::ScheduleTimer(0, 10, 0, 0)`. Called by `LineInputPane` construction paths. Route consumes event type `10` with flag byte `event+9 == 1`, then clears the byte. Best inference is a short-lived text/input dispatch suppressor, not a mouse helper. Split candidate. |
| `0x004a6fc0-0x004a7009` | `EventDispatcher::AddModalHandler(EventHandler *handler)` | Allocates a 12-byte modal-list node via `0x004a7af0`, links it before the sentinel, increments count at `+0x24`. Source-authored modal helper. Split candidate. |
| `0x004a7010-0x004a70a3` | `EventDispatcher::RemoveModalHandler(EventHandler *handler)` | Walks modal list, handles matching payload chain, unlinks and frees one node, decrements count. Source-authored modal helper. Split candidate. |
| `0x004a70b0-0x004a70df` | `EventDispatcher::FindFirstEnabledModalHandler()` | Returns first modal-list payload whose EventHandler predicate slot `+0x28` accepts. Called from UI/modal context code. Split candidate. |
| `0x004a70e0-0x004a7104` | `EventDispatcher::ContainsModalHandler(EventHandler *handler) const` | No direct xrefs found in local rel32 scan, but body is a coherent modal-list membership helper adjacent to the modal helper group. Best inference: source-authored retained helper or optimized-away caller elsewhere. Split as a source helper with no-callsite caveat. |
| `0x004a7110-0x004a7119` | `EventDispatcher::OnTimer(...)` / clear input guard callback | EventDispatcher vtable slot; clears byte `+0x28` and returns true. This is the timer callback paired with `ArmTextInputGuardTimer`, not a free helper. Split candidate or merge with `[000143]` support. |
| `0x004a7120-0x004a712c` | `EventDispatcher::CaptureIdleTickBaseline()` | Existing `[000143]`; stores `g_pTimerMgr->m_currentTick` into `+0x2c`. First-draft source is ready. |
| `0x004a7130-0x004a7567` | `EventDispatcher::RouteEventToHandlers(Event *event)` | Main route body. Handles keyboard state, screenshot hotkeys, modal handler selection, idle watcher/cursor show-hide, active handler routing, text guard suppression, translated child routing, and normal child routing. Source-authored and should be split before C++ emission. |
| `0x004a7570-0x004a7684` | `EventDispatcher::DispatchToChildren(...)` | Recursive reverse child traversal over `lastChildIndex -> previousSiblingIndex`, skipping disabled records and calling children before current handler. Source-authored exact helper. |
| `0x004a7690-0x004a77c4` | `EventDispatcher::DispatchToTranslatedChildren(...)` | Same reverse traversal but subtracts handler coordinate offset from event coordinates, recurses/calls, then restores coordinates. Source-authored exact helper. |
| `0x004a77d0-0x004a78ea` | `EventDispatcher::CallHandler(EventHandler *handler, Event *event)` | Sets `m_currentDispatchHandler`, dispatches to EventHandler virtual slots based on Event predicates/type, clears field afterward. Source-authored exact helper. |
| `0x004a78f0-0x004a7979` | existing `[000144] EventDispatcherFindHandlerIterator` | Exact helper scans enabled records for a handler. The stale 95/95 no-code language should be replaced; the child clears the active gate and is first-draft eligible. |
| `0x004a7980-0x004a7aef` | `AssignHandlerRecordVector` / `ReplaceHandlerRecordVectorStorage` | Copies/replaces handler-record vector storage using allocation helpers. Called only by rebuild at `0x004a823f`. Source helper should be split or included in handler-vector support. |
| `0x004a7af0-0x004a7b0a` | `CreateEventHandlerListNode` | Calls `CreateEventHandlerListNodeLinks` (`0x004a8680`) and writes the payload handler pointer into the 12-byte node. Source helper should be split or referenced by modal-list support. |
| `0x004a7b10-0x004a7c2a` | existing `[000145] EventDispatcherHandlerRecordVectorInsert` | Exact vector insert helper. It now has resolved `EventHandlerRecord` fields from B002; stale 95/95 no-code wording should be replaced. |
| `0x004a7c30-0x004a7caa` | shared dword-fill/range helper | Called from EventDispatcher rebuild and also outside the dispatcher cluster. Do not name it as an EventDispatcher method. Best placement is generic utility/runtime support with a comment that dispatcher rebuild uses it. |
| `0x004a7cb0-0x004a7cbd` | `unknown_libname_13` / compiler/runtime dword assignment helper | IDA/runtime-style helper. Called by modal/remove code. No source EventDispatcher C++ should be emitted for this helper. |
| `0x004a7cc0-0x004a7ccb` | clear `g_pEventDispatcher` unwind helper | Only compiler cleanup route observed. No source method; document as EH cleanup glue. |
| `0x004a7cd0-0x004a7df4` | existing `[000146] EventDispatcherHandlerTreeSupport` | Mixed tree/list/destructor/thunk/matcher island. It should remain a support child but should eventually split compiler destructor wrappers from source list/tree destructors. |
| `0x004a7e00-0x004a7e66` | `EventDispatcher` scalar deleting destructor / destructor body | Vtable slot `0x0061963c`; inlines source destructor cleanup plus delete-flag wrapper. Source docs should describe `~EventDispatcher()` responsibilities but not emit the compiler scalar-deleting wrapper as formal C++. |
| `0x004a7e70-0x004a82a9` | `EventDispatcher::RebuildHandlerTraversalOrder()` | Scheduler-only rebuild pass. Builds temporary remap/vector/deque state, compacts live records, remaps parent/child/sibling indices, assigns the new vector, and frees temporaries. Source-authored and should be split before C++ emission. |

Padding checked:

- `0x004a6a76-0x004a6a80`, `0x004a6c3c-0x004a6c40`, `0x004a6cdb-0x004a6ce0`, `0x004a6dcd-0x004a6dd0`, `0x004a6f33-0x004a6f40`, `0x004a6f75-0x004a6f80`, `0x004a6f9c-0x004a6fa0`, `0x004a6fb2-0x004a6fc0`, `0x004a7009-0x004a7010`, `0x004a70a3-0x004a70b0`, `0x004a7104-0x004a7110`, `0x004a7119-0x004a7120`, `0x004a712c-0x004a7130`, `0x004a7567-0x004a7570`, `0x004a7684-0x004a7690`, `0x004a77c4-0x004a77d0`, `0x004a78ea-0x004a78f0`, `0x004a7979-0x004a7980`, `0x004a7b0a-0x004a7b10`, `0x004a7c2a-0x004a7c30`, `0x004a7caa-0x004a7cb0`, `0x004a7cbd-0x004a7cc0`, `0x004a7ccb-0x004a7cd0`, `0x004a7e66-0x004a7e70`, and `0x004a82a9-0x004a82b0` are `0xcc` padding/gaps around the exported functions or compiler support bodies.

## Source Ownership and `ApplicationHelper_4A6C40`

`ApplicationHelper_4A6C40` should remain a generated grouping label, not a source class, not a source file, and not an emitter. The scheduler body at `0x004a6c40` is invoked by application idle call sites, but the called object is `g_pEventDispatcher`. The function touches dispatcher-owned tree/vector fields, timer fields, and frame-registry state, then calls `EventDispatcher::RebuildHandlerTraversalOrder()`.

Recommended final source-facing name for `0x004a6c40`: `EventDispatcher::ProcessIdleWork()`. Existing title `ApplicationIdleWorkScheduler` can remain as a doc title if the body text says the source name should not be `ApplicationHelper_4A6C40`.

Rejected alternatives:

- `ApplicationHelper_4A6C40` as a source class: rejected because support docs already classify it as `RECONSTRUCTABLE:FALSE`, and the binary body is dispatcher-state-heavy.
- TimerManager ownership: rejected because timer manager is a dependency read by the scheduler, not the owner of handler-tree rebuild or frame dispatch.
- `Application` ownership: weaker; application provides call sites, but the method uses dispatcher `this` and vtable/global dispatcher evidence.
- Non-emitting helper-only ownership: rejected for the scheduler body because the body is source-authored and dispatcher-owned. The aggregate itself should be non-emitting only after exact child splits absorb source code.

## Handler Record and Tree Fields

B002 resolved the 28-byte record layout; `[000141]` should consume those names instead of raw offsets:

```cpp
struct EventHandlerRecord {
    int parentIndex;
    int firstChildIndex;
    int lastChildIndex;
    int previousSiblingIndex;
    int nextSiblingIndex;
    EventHandler *handler;
    bool isDisabled;
    unsigned char padding[3];
};
```

Dispatcher and tree fields recommended for docs/IDA:

| Offset | Best field name | Evidence |
| --- | --- | --- |
| `+0x04` | `m_handlerTree` | Constructor installs handler-tree vtable at `0x0061962c`; traversal and rebuild operate through this embedded object. |
| `+0x08` | `m_handlerRecordsBegin` | Vector begin pointer inside handler tree. Used by insertion, find, rebuild, and vector-free helpers. |
| `+0x0c` | `m_handlerRecordsEnd` | Vector end pointer. |
| `+0x10` | `m_handlerRecordsCapacity` | Vector capacity pointer. |
| `+0x14` | `m_activeHandler` | Set by `0x004a6f40`, cleared by `RemovePaneEntry`, used by route. |
| `+0x18` | `m_activeContextHandler` | Set to `m_currentDispatchHandler` when active handler is set; route uses it for translated active-context dispatch. Exact original name unknown, but context/coordinate handler is the best source-quality inference. |
| `+0x1c` | `m_currentDispatchHandler` | Set around `CallHandler`, read by `SetActiveHandler`. |
| `+0x20` | `m_modalHandlersHead` | Circular modal-list sentinel pointer. |
| `+0x24` | `m_modalHandlerCount` | Incremented/decremented by modal-list add/remove helpers. |
| `+0x28` | `m_textInputGuardActive` | Set by `ArmTextInputGuardTimer`, cleared by vtable timer callback and route when suppressing event type `10` with flag `event+9 == 1`. |
| `+0x2c` | `m_idleTickBaseline` | `[000143]` stores `g_pTimerMgr->m_currentTick`. |
| `+0x30` | `m_lastDispatchedIdleSlice` | Scheduler stores the last 20ms slice number after frame dispatch. |
| `+0x34` | `m_cursorHideArmed` | Constructor sets true; route toggles cursor visibility state. Exact original name uncertain. |
| `+0x38` | `m_cursorStillStartTick` | Route stores/checks timer ticks for cursor hide delay. |
| `+0x3c` | `m_cursorHideDelayMs` | Constructor writes `3000`; route compares elapsed cursor-still time. |
| `+0x40` | `m_lastCursorX` | Route stores cursor/event x coordinate; constructor does not initialize in observed body. |
| `+0x44` | `m_lastCursorY` | Route stores cursor/event y coordinate; constructor does not initialize in observed body. |

## Constructor Findings

`0x004a6a80` is source-authored constructor code and should be split if formal C++ is desired. Evidence:

- Called by application startup at `0x00464613`.
- Calls `TimerHandler::TimerHandler` at `0x00597570` and `LObject` construction at `0x004f4a80`.
- Stores `this` in `g_pEventDispatcher` (`0x0067ab30`) and later support cleanup clears it.
- Installs EventDispatcher vtable `0x0061963c` and embedded handler-tree vtable `0x0061962c`.
- Inserts the root/sentinel handler record using `[000145]` with initializer data at `0x00619660`.
- Initializes handler vector pointers, modal-list sentinel/count, active/current handler fields, input guard, idle baseline/slice fields, cursor hide fields, and keyboard globals.
- Calls `GetKeyboardState(&KeyState)` and stores the cached `VK_SCROLL` low bit into `dword_69AF18`.

The constructor cleanup funclet at `0x004a6bf0` should not be emitted as C++. It is a compiler EH path that unwinds already-constructed members and clears `g_pEventDispatcher`.

## Active, Modal, and Input Guard Helpers

The helper cluster at `0x004a6f40-0x004a7119` should be expanded in the target. The current target compresses it too aggressively and hides important source-quality names.

Recommended source-facing helper names:

- `0x004a6f40`: `EventDispatcher::SetActiveHandler(EventHandler *handler)`
- `0x004a6f80`: `EventDispatcher::IsActiveOrContextHandler(EventHandler *handler) const`
- `0x004a6fa0`: `EventDispatcher::ArmTextInputGuardTimer()`
- `0x004a6fc0`: `EventDispatcher::AddModalHandler(EventHandler *handler)`
- `0x004a7010`: `EventDispatcher::RemoveModalHandler(EventHandler *handler)`
- `0x004a70b0`: `EventDispatcher::FindFirstEnabledModalHandler()`
- `0x004a70e0`: `EventDispatcher::ContainsModalHandler(EventHandler *handler) const`
- `0x004a7110`: `EventDispatcher::OnTimer(...)` or `EventDispatcher::OnTimerClearInputGuard(...)`

The `0x004a6fa0` helper should not be called a mouse helper. It is called by `LineInputPane` construction paths, sets byte `+0x28`, schedules a 10-tick timer through `TimerHandler::ScheduleTimer`, and the route body consumes type `10` events with a one-character flag. Event docs show type `10` paths in text/number input code. Best high-probability source meaning: a text/input guard used to suppress the first synthetic or stale character input after line input setup.

`0x004a70e0` has no direct rel32 xrefs in the local scan. It is still best treated as a retained source helper because it is a coherent modal-list membership test, uses the same list layout as its neighbors, and is placed in the exact modal helper cluster. The doc should state the no-direct-xref finding instead of leaving it as a raw function.

## Routing Behavior

`0x004a7130` is the main route body and should be called `EventDispatcher::RouteEventToHandlers(Event *event)` unless a future original-symbol source proves a different spelling.

Behavior to incorporate:

- Initializes the screen/root pane from `dword_67A7CC` before handler tree routing.
- Refreshes keyboard state through `GetKeyboardState(&KeyState)`.
- Tracks the cached `VK_SCROLL` bit (`byte_69AEA9 & 1`) in `dword_69AF18`.
- Shift+Ctrl+`3` and Shift+Ctrl+`4` trigger screenshot helpers, with one-shot gating through `byte_69AF20`. Existing screenshot helper names should be consumed from the screenshot docs rather than invented here.
- Scans modal-list entries and selects the first modal handler whose EventHandler predicate slot `+0x28` accepts the current event.
- Calls idle watcher/cursor activity helpers for cursor/mouse-like events.
- Shows/hides the cursor through the cursor visibility wrappers at `0x00557430` and `0x00557440`.
- Uses cursor fields `+0x34/+0x38/+0x3c/+0x40/+0x44` for a 3000ms cursor-still hide delay and last x/y tracking.
- If active context handler `+0x18` can accept a cursor/mouse-like event, obtains a coordinate offset through an EventHandler virtual slot and dispatches translated coordinates directly.
- Otherwise routes through modal handler or child traversal helpers.
- For the text/input guard path, if byte `+0x28` is set and the event is type `10` with `event+9 == 1`, it clears the guard and consumes/handles the event.
- Uses `DispatchToChildren`, `DispatchToTranslatedChildren`, and `CallHandler` as exact helper bodies.

The event predicate helpers `sub_4A8AC0`, `sub_4A8AD0`, `sub_4A8AE0`, `sub_4A8AF0`, and `sub_4A8B00` should not be renamed beyond conservative `Event_Is...` comments until the Event/EventMan pass owns their exact event names. The route body can still document their role by call path: cursor/mouse-like routing, alternate mouse/keyboard routing, payload-free predicate, event type `19`, and final EventHandler virtual dispatch predicate.

## Handler Tree and Vector Helper Findings

The exact child docs `[00022A]`, `[000148]`, and `[00022B]` now carry high-quality handler-record reconstruction. `[000141]` should cite them and should not duplicate their formal C++.

Valid details to incorporate:

- `InsertFirstChildHandlerRecord`, `InsertHandlerRecordAfterSibling`, `RemoveHandlerRecordAndDisableSubtree`, `CreateEventHandlerListNodeLinks`, `RebindHandlerRecordVectorStorage`, `ReserveHandlerRecordVectorStorage`, `FreeHandlerRecordVector`, `AllocateHandlerRecordBuffer`, and `FreeHandlerRecordBuffer` are now the best source-facing helper names from B002.
- `FindHandlerIterator` / `FindEnabledHandlerRecord` at `[000144]` scans enabled records and is called from ordering/removal/routing code.
- `AssignHandlerRecordVector` at `0x004a7980` is not currently an exact child but should be. It is called by rebuild and copies/replaces vector storage after remapping.
- `CreateEventHandlerListNode` at `0x004a7af0` is not currently an exact child but should be referenced by modal-list add.
- `0x004a7c30` is shared outside EventDispatcher. Do not mark it as an EventDispatcher method or source-owned helper without separate utility evidence.
- `0x004a7cb0` is a compiler/runtime-style assignment helper and should remain no-code.
- `0x004a7cc0` is a constructor unwind helper that clears `g_pEventDispatcher`; no formal source C++.

## Vtable and Global Evidence

- EventDispatcher vtable data at `0x0061963c` references:
  - `0x004a7e00` scalar deleting destructor / destructor wrapper
  - `0x004a7110` timer callback that clears the input guard
- EventDispatcher vtable refs in code:
  - `0x004a6adb`
  - `0x004a6bf6`
  - `0x004a7e08`
- Handler tree vtable `0x0061962c` refs:
  - constructor/tree setup at `0x004a6aec`
  - cleanup paths at `0x004a6c18`, `0x004a7cd8`, `0x004a7d8b`, `0x004a7e2b`
- HandlerFindFunc vtable `0x00619648` is used by `[000144]` and its matcher at `0x004a7d60`.
- Tree iterator vtable `0x00619650` appears in ordering/removal/routing helper setup and cleanup.
- `g_pEventDispatcher` (`0x0067ab30`) has broad executable refs; the constructor sets it, EH cleanup and destructor clear it, and application/pane/event call sites route through it.
- Keyboard globals:
  - `KeyState` at `0x0069ae18`
  - `byte_69AEA9` cached keyboard byte
  - `dword_69AF18` cached scroll-lock bit
  - `byte_69AF20` screenshot hotkey one-shot gate

## C++ Readiness

Formal C++ for `[000141]` should remain blank. This is an exact no-code proof for the aggregate:

- The range contains many independent source methods and exact child docs.
- It contains compiler-generated constructor EH cleanup at `0x004a6bf0`.
- It contains scalar-deleting destructor ABI glue at `0x004a7e00`; source docs should describe `~EventDispatcher()`, not emit the delete-flag wrapper.
- It contains shared/runtime helpers at `0x004a7c30` and `0x004a7cb0`.
- Existing children `[000142]`, `[000143]`, `[000144]`, `[000145]`, `[000146]`, `[000147]`, `[00022A]`, `[000148]`, and `[00022B]` already own exact subranges or should own the exact source work.
- A monolithic aggregate C++ block would duplicate child code and hide split boundaries the validator needs.

Exact child C++ readiness:

- `[000143]` is first-draft ready:

```cpp
void EventDispatcher::CaptureIdleTickBaseline()
{
    m_idleTickBaseline = g_pTimerMgr->m_currentTick;
}
```

- The active/input helper cluster is first-draft ready after exact child split:

```cpp
void EventDispatcher::SetActiveHandler(EventHandler *handler)
{
    if (handler == 0) {
        m_activeHandler = 0;
        m_activeContextHandler = 0;
        return;
    }

    m_activeHandler = handler;
    m_activeContextHandler = m_currentDispatchHandler;
}

bool EventDispatcher::IsActiveOrContextHandler(EventHandler *handler) const
{
    return handler == m_activeHandler || handler == m_activeContextHandler;
}

void EventDispatcher::ArmTextInputGuardTimer()
{
    m_textInputGuardActive = true;
    ScheduleTimer(0, 10, 0, 0);
}

bool EventDispatcher::OnTimer(int, int, int)
{
    m_textInputGuardActive = false;
    return true;
}
```

- The modal-list helpers are first-draft ready once `EventHandlerListNode` is named:

```cpp
void EventDispatcher::AddModalHandler(EventHandler *handler)
{
    EventHandlerListNode *head = m_modalHandlersHead;
    EventHandlerListNode *node = CreateEventHandlerListNode(head, head->previous, handler);
    ++m_modalHandlerCount;
    node->next->previous = node;
    node->previous->next = node;
}

bool EventDispatcher::ContainsModalHandler(EventHandler *handler) const
{
    for (EventHandlerListNode *node = m_modalHandlersHead->next;
         node != m_modalHandlersHead;
         node = node->next) {
        if (node->handler == handler) {
            return true;
        }
    }
    return false;
}
```

- `[000144]`, `[000145]`, and `[000147]` should have stale 95/95 no-code language removed. They now clear the active gate with the resolved `EventHandlerRecord` and modal-list layouts.
- `0x004a7130`, `0x004a7570`, `0x004a7690`, `0x004a77d0`, and `0x004a7e70` are source-authored and reconstructable, but they should be split first. Their first-draft C++ should live in exact child docs rather than in `[000141]`.

## Open Questions and Best Resolutions

- Exact original method spellings are not recovered from symbols or strings. Best source-quality names above are descriptive and consistent with call sites, support docs, and field behavior.
- Exact original name for `+0x18` is unknown. Evidence shows it is captured from `m_currentDispatchHandler` when an active handler is set and is used as a translated active-context route target. `m_activeContextHandler` is the best current name.
- Exact original name for the `+0x28` guard is unknown. Evidence rejects a generic timer flag and rejects mouse-specific naming; `m_textInputGuardActive` / `ArmTextInputGuardTimer` is the best inference because LineInputPane calls the arm helper and route suppresses type `10` text/character input.
- Exact original names for cursor fields `+0x34/+0x38/+0x3c/+0x40/+0x44` are unknown. Behavior is strong enough to document cursor hide/tracking roles and use `m_cursorHideArmed`, `m_cursorStillStartTick`, `m_cursorHideDelayMs`, `m_lastCursorX`, and `m_lastCursorY`.
- Event predicate helper names remain under Event/EventMan ownership. `[000141]` should describe route usage but should not finalize event predicate names without that pass.
- `0x004a70e0` has no direct xrefs. The best resolution is retained source modal-list helper, not dead raw code, because it is a complete modal membership helper adjacent to used modal operations.
- `0x004a7c30` has non-dispatcher consumers. The best resolution is a shared utility/runtime fill helper and not an EventDispatcher method.
- Destructor source shape should not be represented as scalar deleting destructor C++. Document source destructor responsibilities and ABI wrapper separately.

## Score and Metadata Recommendation

Immediate target recommendation:

- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000J7`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000J7`
- Keep formal C++ blank, but replace the current vague C++ blocker with the explicit aggregate no-code proof above.

Rationale:

- Completion can rise from `85` to `86` because source ownership, helper names, handler-record fields, scheduler provenance, vtable/global refs, and split opportunities are now much more resolved.
- Confidence can rise from `86` to `90` because the source-quality story is now supported by local PE range/ref checks, B002 handler-record field resolution, vtable data, and concrete field names.
- Do not raise higher until the remaining source-bearing functions are split and exact child C++ is emitted or explicitly no-coded.

Preferred post-split recommendation:

- Convert `[000141]` to a non-emitting source-module aggregate/index after exact child pages cover all source-authored functions and compiler/runtime helper islands.
- Leave `EventDispatcher.cpp` as the source file for exact children.
- Do not emit aggregate formal C++ after splits.

## Recommended Target Doc Changes

For `source-3/project-documentation/by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md`:

- Update metadata to `COMPLETION:86`, `CONFIDENCE:90`; keep owner/emitter/reconstructable as above for the immediate pass.
- Replace the current covered-methods list with the function inventory table from this report.
- Add a "Source ownership" section that:
  - keeps owner/emitter `[UID:0000J7] EventDispatcher`;
  - rejects `ApplicationHelper_4A6C40` as a source class;
  - names `0x004a6c40` as `EventDispatcher::ProcessIdleWork()`;
  - documents that application idle call sites are callers, not ownership proof.
- Add a field table for offsets `+0x04` through `+0x44` using the names in this report.
- Add a handler-record section consuming B002's `EventHandlerRecord` layout and helper names.
- Add a modal/active/input helper section with the names and behavior above.
- Add a route behavior section covering screenshot hotkeys, keyboard globals, modal selection, idle watcher/cursor show-hide, text-input guard, and traversal helper calls.
- Add an exact C++ readiness section:
  - aggregate formal C++ remains blank by design;
  - exact source-bearing child functions are first-draft ready after split;
  - compiler/runtime sub-bodies remain no-code.
- Add a split checklist for constructor, scheduler, SetPaneOrder, RemovePaneEntry, DispatchEvent, active/modal/input helpers, route/traversal/call-handler bodies, vector assignment, modal node creation, destructor, and rebuild.
- Add a validator note to confirm whether `[000142]` should use half-open end `0x004a6cdb` despite the current filename/title ending at `0x004a6cda`.

## Recommended Support Doc Changes

- `by-file/EventDispatcher.md`:
  - Add the exact helper inventory and field table summary.
  - Replace "helper-name caveats" with specific unresolved original-spelling caveats.
  - State that `ProcessIdleWork`, `CaptureIdleTickBaseline`, modal helpers, active helpers, route helpers, and rebuild are in `EventDispatcher.cpp`.
  - State that aggregate C++ should not be emitted.
- `by-class/EventDispatcher.md`:
  - Add methods for `SetActiveHandler`, `IsActiveOrContextHandler`, `ArmTextInputGuardTimer`, `AddModalHandler`, `RemoveModalHandler`, `FindFirstEnabledModalHandler`, `ContainsModalHandler`, `OnTimer`, `DispatchToChildren`, `DispatchToTranslatedChildren`, `CallHandler`, `AssignHandlerRecordVector`, `CreateEventHandlerListNode`, and `RebuildHandlerTraversalOrder`.
  - Add the field names and offsets.
  - Clarify destructor/source destructor versus scalar deleting destructor wrapper.
- `by-class/ApplicationHelper_4A6C40.md`:
  - Keep non-emitting/generated classification.
  - Add explicit rejection of `ApplicationHelper_4A6C40` as a final source class for `0x004a6c40`.
  - Cross-reference `EventDispatcher::ProcessIdleWork()` and `EventDispatcher::CaptureIdleTickBaseline()`.
- `by-type/by-struct/EventDispatcherHandlerTreeLayouts.md`:
  - Add references to `AssignHandlerRecordVector`, `CreateEventHandlerListNode`, and `FindEnabledHandlerRecord`.
  - Keep B002 field names.
- `[000142] ApplicationIdleWorkScheduler`:
  - Rename/reframe source-facing method to `EventDispatcher::ProcessIdleWork()`.
  - Remove any lingering `ApplicationHelper_4A6C40` source-class implication.
  - Recheck the half-open end address.
- `[000143] ApplicationIdleTickBaseline`:
  - Remove stale companion-blocker language if still present; first-draft C++ is ready.
- `[000144] EventDispatcherFindHandlerIterator`:
  - Remove stale below-95/95 no-code reasoning.
  - Prefer `FindEnabledHandlerRecord` or retain title with source-facing note `FindHandlerIterator`.
- `[000145] EventDispatcherHandlerRecordVectorInsert`:
  - Remove stale below-95/95 no-code reasoning.
  - Use B002 `EventHandlerRecord` field names.
- `[000146] EventDispatcherHandlerTreeSupport`:
  - Add note that tree/list destructors and scalar deleting wrappers are mixed; split compiler wrappers from source destructors where practical.
- `[000147] EventDispatcherHandlerListDestructor`:
  - Remove stale below-95/95 no-code reasoning and add first-draft modal-list destructor readiness.
- Timer support:
  - No ownership change; add that `0x004a6fa0` uses `TimerHandler::ScheduleTimer` to clear the input guard through EventDispatcher's timer callback.
- Event/EventMan support:
  - Add a conservative note that EventDispatcher route uses event type `10` as text/character input in the input guard path, but leave exact predicate helper names to Event/EventMan docs.

## Exact Coverage Row Text

Do not edit `by-memory/-coverage-report.md` in this report-only pass. If accepted, replace the existing `[UID:000141]` row with:

```text
    - [UID:000141][0x004a6a80-0x004a82a9.EventDispatcher](by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md) 0x004a6a80-0x004a82a9 | source-module aggregate | EventDispatcher : reconstructable : 86% : strong : Source-quality reanalysis keeps this as the EventDispatcher.cpp aggregate and not a formal aggregate C++ emission unit; verifies exact function inventory including constructor, constructor EH cleanup, idle scheduler, SetPaneOrder, RemovePaneEntry, DispatchEvent, active/context helpers, text-input guard timer, modal-list helpers, timer callback, route/child/translated-child/call-handler bodies, handler-vector support, scalar deleting destructor, traversal rebuild, vtable/global refs, keyboard/screenshot/cursor side effects, and recommends exact child splits before emitting first-draft C++ from exact source-bearing children.
```

## Validation Commands Needed After Implementation

From `E:\NTK\GhidraBridge`:

> Executable block R001 was removed from this report and preserved verbatim in [000141-EventDispatcher-source-quality-removed.md](000141-EventDispatcher-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If exact child splits are created, validate each new by-memory child and rerun the scoped coverage/range checks for `0x004a6a80-0x004a82a9`. Also perform a targeted validator/range audit for `[000142]` because the exported size points to half-open end `0x004a6cdb` while the current doc title uses `0x004a6cda`.

## IDA Rename, Type, and Comment Recommendations

Function names:

| Address | Recommended name | Confidence |
| --- | --- | --- |
| `0x004a6a80` | `EventDispatcher_ctor` | High |
| `0x004a6bf0` | `EventDispatcher_ctor_eh_cleanup` | High as compiler cleanup |
| `0x004a6c40` | `EventDispatcher_ProcessIdleWork` | High |
| `0x004a6ce0` | `EventDispatcher_SetPaneOrder` | High |
| `0x004a6dd0` | `EventDispatcher_RemovePaneEntry` | High |
| `0x004a6ef0` | `EventDispatcher_DispatchEvent` | High |
| `0x004a6f40` | `EventDispatcher_SetActiveHandler` | High |
| `0x004a6f80` | `EventDispatcher_IsActiveOrContextHandler` | Medium-high |
| `0x004a6fa0` | `EventDispatcher_ArmTextInputGuardTimer` | Medium-high |
| `0x004a6fc0` | `EventDispatcher_AddModalHandler` | High |
| `0x004a7010` | `EventDispatcher_RemoveModalHandler` | High |
| `0x004a70b0` | `EventDispatcher_FindFirstEnabledModalHandler` | High |
| `0x004a70e0` | `EventDispatcher_ContainsModalHandler` | Medium; no direct xrefs |
| `0x004a7110` | `EventDispatcher_OnTimer_ClearInputGuard` | Medium-high |
| `0x004a7120` | `EventDispatcher_CaptureIdleTickBaseline` | High |
| `0x004a7130` | `EventDispatcher_RouteEventToHandlers` | High |
| `0x004a7570` | `EventDispatcher_DispatchToChildren` | High |
| `0x004a7690` | `EventDispatcher_DispatchToTranslatedChildren` | High |
| `0x004a77d0` | `EventDispatcher_CallHandler` | High |
| `0x004a78f0` | `EventDispatcher_FindHandlerIterator` or `EventDispatcher_FindEnabledHandlerRecord` | High role, medium exact spelling |
| `0x004a7980` | `AssignHandlerRecordVector` | Medium-high |
| `0x004a7af0` | `CreateEventHandlerListNode` | High |
| `0x004a7c30` | `FillDwordRange` | Medium; shared utility, not dispatcher method |
| `0x004a7cb0` | keep `unknown_libname_13` / comment runtime assignment helper | High no-source |
| `0x004a7cc0` | `ClearEventDispatcherSingleton_eh_cleanup` | High as compiler cleanup |
| `0x004a7e00` | `EventDispatcher_scalar_deleting_destructor` | High as ABI wrapper |
| `0x004a7e70` | `EventDispatcher_RebuildHandlerTraversalOrder` | High |

Type names:

- `EventDispatcher`
- `EventHandler`
- `EventHandlerRecord`
- `EventHandlerTree`
- `EventHandlerRecordVector`
- `EventHandlerTreeIterator`
- `HandlerFindFunc`
- `EventHandlerListNode`

Comments to add:

- `0x004a6bf0`: "Constructor EH cleanup; not a source method."
- `0x004a6c40`: "Application idle call sites invoke this on g_pEventDispatcher; source name should be EventDispatcher::ProcessIdleWork."
- `0x004a6fa0`: "Arms short text/input guard and schedules EventDispatcher timer callback."
- `0x004a70e0`: "Modal-list membership helper; no direct xrefs found in current executable scan."
- `0x004a7c30`: "Shared fill helper; EventDispatcher rebuild consumer but not EventDispatcher-owned."
- `0x004a7e00`: "Scalar deleting destructor wrapper; formal source C++ should describe ~EventDispatcher(), not the delete-flag ABI wrapper."

## Implementation Checklist If Accepted

1. Update `[000141]` metadata to `86/90` and keep aggregate C++ blank with explicit no-code proof.
2. Replace the function inventory in `[000141]` with the table in this report.
3. Add the dispatcher field table and handler-record layout references.
4. Add source ownership language rejecting `ApplicationHelper_4A6C40` as source class and naming `EventDispatcher::ProcessIdleWork`.
5. Add active/modal/input guard helper names and behavior.
6. Add route behavior details for keyboard/screenshot/cursor/modal/active/text guard handling.
7. Add exact split opportunities and first-draft C++ readiness notes.
8. Update support docs listed above; remove stale 95/95 blocker text from exact children that now clear the active gate.
9. Add the exact replacement row to `by-memory/-coverage-report.md` only when supervisor authorizes coverage edits.
10. Run the validation commands and resolve any validator fallout, especially the `[000142]` half-open end audit.

FINISHED

Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\000141-EventDispatcher-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000141-EventDispatcher-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"000141"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000141-EventDispatcher-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/000141-EventDispatcher-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000141"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
