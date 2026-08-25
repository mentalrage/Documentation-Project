** TARGET-REPORT-UID:00004M **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B012 EventDispatcher Class Source-Quality Reanalysis

Assignment: `B012-goal2-event-dispatcher-class-source-quality-00004M-20260619`  
Agent: `Agent-B012`  
Target: [UID:00004M] `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\EventDispatcher.md`  
Report-only output: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B012\research\00004M-EventDispatcher-class-source-quality.md`

Status: `FINISHED`.

This pass did not edit any `by-*` documentation file, generated source file, or coverage report. `by-memory/-coverage-report.md` was not edited.

## Recommendation

Raise [UID:00004M] from `COMPLETION:85`, `CONFIDENCE:86` to `COMPLETION:88`, `CONFIDENCE:90`.

Keep:

- `CANONICAL_OWNER:0000J7`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000J7`
- blank `EMITTER_POSITION_OPTIONAL`
- blank formal `RECONSTRUCTION_CPP` on the class page for now

The class page is no longer blocked by generic handler-record field names, generated `sub_*` helper labels, or the stale EventDispatcher ownership of `0x00597580`. The class should remain below final-audit status because the central class/method declaration set is not yet source-quality enough for a target-level class C++ block: exact `EventHandler` virtual-family names, `EventHandler.h` versus `EventDispatcher.h` declaration placement, central `RouteEventToHandlers`/constructor/rebuild method drafts, and idle-scheduler source split still need a coordinated EventDispatcher source pass. Exact helper children already carry first-draft code where safe, so the class page should document and route those children rather than paste a broad synthetic class layout.

Best source placement remains `NexusTK/ui/core/EventDispatcher.cpp` with header `NexusTK/ui/core/EventDispatcher.h`. `EventHandler` is best treated as shared UI event infrastructure implemented/emitted through the EventDispatcher source family, with a high-probability final declaration in a small `ui/core/EventHandler.h` or EventDispatcher-adjacent event header. `Event` and `EventMan` producer/factory code should remain in [UID:0000J6] `NexusTK/ui/core/Event.cpp`, not be merged into EventDispatcher.

## Evidence Checked

### Documentation and generated outputs

I reviewed:

- Target [UID:00004M] `by-class/EventDispatcher.md`.
- Source root [UID:0000J7] `by-file/EventDispatcher.md`.
- Related source roots [UID:0000J6] `by-file/Event.md`, [UID:0000OT] `by-file/TimerMgr.md`, and [UID:0000MC] `by-file/Pane.md`.
- Related classes [UID:00004L] `Event`, [UID:00004N] `EventHandler`, [UID:0000F0] `TimerHandler`, [UID:000060] `HandlerFindFunc`, [UID:0000F8] `Tree_near_class_EventHandler___`, [UID:0000FA] `TreeItor_near_class_EventHandler___`, and [UID:00000E] `ApplicationHelper_4A6C40`.
- EventDispatcher memory children:
  - [UID:000141] `0x004a6a80-0x004a82a9.EventDispatcher`
  - [UID:000142] `0x004a6c40-0x004a6cda.ApplicationIdleWorkScheduler`
  - [UID:000143] `0x004a7120-0x004a712c.ApplicationIdleTickBaseline`
  - [UID:000144] `0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator`
  - [UID:000145] `0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert`
  - [UID:000146] `0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport`
  - [UID:000147] `0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor`
  - [UID:00022A] `0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers`
  - [UID:000148] `0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree`
  - [UID:00022B] `0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers`
  - [UID:00014A] `0x004a8970-0x004a8a84.EventHandlerBase`
  - [UID:0001K7] `0x00597580-0x005975c3.TimerHandlerDestructor`
- Type/data pages [UID:0001UF] `EventDispatcherHandlerTreeLayouts`, [UID:0003I5] `0x00619628-0x00619670.EventDispatcherHandlerTreeVtableData`, [UID:0003I6] `0x00619670-0x006196a0.EventHandlerVtableData`, and [UID:000296] `0x0067ab30-0x0067ab34.g_pEventDispatcher`.
- `auto-generated/-ag-class-coverage.md`, which now routes [UID:00004M], [UID:00004N], [UID:000060], [UID:0000F8], [UID:0000FA], and [UID:0001UF] to `auto-generated/NexusTK/ui/core/EventDispatcher.cpp`, while [UID:00000E] `ApplicationHelper_4A6C40` is `not_reconstructable`.
- `auto-generated/NexusTK/ui/core/EventDispatcher.cpp`, which currently contains first-draft code from [UID:00022A], [UID:000148], and [UID:00022B], then empty emitter markers for [UID:00004M], [UID:00004N], [UID:00014A], [UID:000060], [UID:0000FA], [UID:0000F8], [UID:000141], [UID:000142], [UID:000143], [UID:000144], [UID:000145], [UID:000146], [UID:000147], [UID:0003I5], [UID:00027B], [UID:000296], [UID:0002AV], [UID:0002AW], and [UID:0001UF].
- Stale generated leads in `simroot_v2/ui/core/EventDispatcher.cpp`, `simroot_v2/ui/core/EventDispatcher.meta_wave3`, and `core/data/cache/wave3/files/class_EventDispatcher.cpp.json`. These still carry older low-quality code such as `EventDispatcher::~TimerHandler(this)`, stale `0x00597580` metadata, ambiguous `link*` record fields, and synthetic layout overlays. They are not current source-quality truth.

### Local PE validation

I used a local Capstone/PE parser over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.

Binary identity:

- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Image base: `0x00400000`

Focused range checks:

- `0x004a6a80-0x004a6bed` constructor: 365 bytes, 96 decoded instructions. It calls `TimerHandler` constructor `0x00597570`, writes `g_pEventDispatcher` at `0x0067ab30`, installs EventDispatcher vtable `0x0061963c`, installs `Tree<EventHandler*>` vtable `0x0061962c`, calls `0x004a7b10` for handler-record insertion, calls `0x004a8680` for list sentinel/node creation, calls `0x004b6dc0` for frame manager work, and snapshots keyboard state at `0x0069ae18`.
- `0x004a6c40-0x004a6cda` idle worker: 154 bytes, 43 decoded instructions. It drains `g_pApplicationCleanupQueue` at `0x0067a74c`, gates timer refresh on `0x0066d880`, calls TimerMgr helpers, calls traversal rebuild `0x004a7e70`, reads `g_pTimerMgr` `0x0067ab80`, writes idle baseline/slice fields at `this+0x2c/+0x30`, and dispatches frame slices through `g_frameRegistry` at `0x0069ae10`.
- `0x004a7130-0x004a7567` routing body: 1079 bytes, 376 decoded instructions. It refreshes keyboard state, uses screenshot hotkey calls `0x00557aa0` and `0x00557e80`, calls child/translated-child dispatch helpers, calls `0x004a78f0` twice, and writes/reads the one-byte chord gate at `0x0069af20`.
- `0x004a78f0-0x004a7979`: 137 bytes, 60 decoded instructions. It constructs the `HandlerFindFunc` vtable `0x00619648`, scans `0x1c`-byte records, skips disabled records, calls the predicate virtually, and writes the iterator index.
- `0x004a7b10-0x004a7c2a`: 282 bytes, 109 decoded instructions. It uses the divide-by-28 reciprocal `0x92492493`, calls allocator `0x004a8820`, memmove, vector rebind `0x004a86b0`, and overflow helper `0x00421500`.
- `0x004a7d00-0x004a7d43`: 67 bytes, 29 decoded instructions. It resets a circular list sentinel, clears count, frees 12-byte nodes, and frees the sentinel.
- `0x004a7e00-0x004a7e66`: 102 bytes, 33 decoded instructions. It reinstalls EventDispatcher vtable `0x0061963c`, closes frame registry if present, calls list teardown `0x004a7d00`, reinstalls tree vtable `0x0061962c`, calls vector free `0x004a87a0`, base cleanup `0x004f4a90`, clears `g_pEventDispatcher`, calls `TimerHandler` destructor `0x00597580`, then conditionally frees the object.
- `0x004a7e70-0x004a82a9`: 1081 bytes, 370 decoded instructions. It calls allocation/deque/rebuild helpers, calls `0x004a8740`, `0x004a7b10`, `0x004a7980`, `0x004a87a0`, and Deque destroy `0x00439e00`.
- `0x004a82b0-0x004a8795`: 1253 bytes, 449 decoded instructions. Calls match the relink helper family: `0x004a7b10`, Deque allocation/grow/destroy, list-node allocation, vector allocator `0x004a8820`, and rebind `0x004a86b0`.
- `0x004a87a0-0x004a8810`: 112 bytes, 40 decoded instructions. It frees a vector buffer with the MSVC large-allocation saved-base validation and clears begin/end/capacity pointers.
- `0x004a8820-0x004a88d2`: 178 bytes, 68 decoded instructions. It contains the paired record-buffer allocator/free helper, including zero-count null return, `0x09249249` max count, small direct allocation, large 32-byte aligned allocation, saved-base validation, and invalid-parameter hard-fail.
- `0x004a8970-0x004a8a84`: 276 bytes, 176 decoded instructions. It contains EventHandler constructor/destructor/default bodies/deleting wrapper. Vtable stores use `0x00619674`; dispatcher-forwarding default at `0x004a89f0` reads `g_pEventDispatcher`.
- `0x00597580-0x005975c3`: 67 bytes, 21 decoded instructions. It writes `TimerHandler` vtable `0x0062e338`, reads `g_pTimerMgr` at `0x0067ab80`, and calls timer unregister helper `0x00597a10`.

Padding checks:

- `0x004a82a9-0x004a82b0`: seven `0xcc` bytes.
- `0x004a8795-0x004a87a0`: eleven `0xcc` bytes.
- `0x004a8810-0x004a8820`: sixteen `0xcc` bytes.
- `0x004a88d2-0x004a88e0`: fourteen `0xcc` bytes.
- `0x004a8a84-0x004a8a90`: twelve `0xcc` bytes.
- `0x005975c3-0x005975d0`: thirteen `0xcc` bytes.

Direct rel32/call reachability:

- Constructor `0x004a6a80`: one direct caller, `0x00464613`.
- Idle worker `0x004a6c40`: two direct callers, `0x00464df7` and `0x00464e0e`.
- `SetPaneOrder` `0x004a6ce0`: direct callers `0x004a8a01` and `0x00544d66`.
- `RemovePaneEntry` `0x004a6dd0`: direct callers `0x00544641`, `0x00544da7`, and `0x00545018`.
- `DispatchEvent` `0x004a6ef0`: 46 direct refs, mostly Event/EventMan producer/factory paths.
- `RouteEventToHandlers` `0x004a7130`: one direct caller from `DispatchEvent` at `0x004a6f12`.
- `FindHandlerIterator` `0x004a78f0`: five local callers at `0x004a6d2f`, `0x004a6d6a`, `0x004a6e23`, `0x004a73e8`, and `0x004a750a`.
- `RecordVectorInsert` `0x004a7b10`: four local callers at `0x004a6b3f`, `0x004a80f5`, `0x004a8345`, and `0x004a840a`.
- `HandlerListDestructor` `0x004a7d00`: normal destructor caller `0x004a7e20`, constructor cleanup `0x004a6c0d`, and unwind thunk `0x005fda87`.
- `RebuildHandlerTraversalOrder` `0x004a7e70`: one direct caller from idle worker `0x004a6c72`.
- Relink helpers: `0x004a82b0` called once from `SetPaneOrder`; `0x004a8350` twice from `SetPaneOrder`; `0x004a8420` once from `RemovePaneEntry`; `0x004a8680` from constructor/list init; `0x004a86b0` from insert/reserve; `0x004a8740` from rebuild.
- `FreeHandlerRecordVector` `0x004a87a0`: constructor cleanup, tree destructor, one-instruction thunk, tree scalar deleting destructor, EventDispatcher destructor, and rebuild cleanup.
- `AllocateHandlerRecordBuffer` `0x004a8820`: three direct callers; `FreeHandlerRecordBuffer` `0x004a8890`: one direct caller.
- EventHandler constructor/destructor: constructor called from Pane construction; ordinary destructor from Pane cleanup and an unwind path. EventHandler virtuals are vtable-reached, not normal direct calls.
- TimerHandler destructor `0x00597580`: fifteen direct refs across timer-owning families. EventDispatcher is one consumer at `0x004a7e48`, not the owner.

Read-only data dwords:

- `0x00619628 -> 0x00646eb4`, `0x0061962c -> 0x004a7d80`, `0x00619630 -> 0x004f4b10`, `0x00619634 -> 0x0041b6c0`: `Tree<EventHandler*>`.
- `0x00619638 -> 0x00646f48`, `0x0061963c -> 0x004a7e00`, `0x00619640 -> 0x004a7110`: `EventDispatcher` COL/vtable. This proves the `0x004a7e00` deleting-destructor wrapper and `0x004a7110` timer callback slot are class virtuals.
- `0x00619644 -> 0x00646fe8`, `0x00619648 -> 0x004a7d60`: `HandlerFindFunc`.
- `0x0061964c -> 0x00646f00`, `0x00619650 -> 0x004a7dd0`, then zeros and `0xffffffff` sentinels: `TreeItor<EventHandler*>`.
- `0x00619670 -> 0x00647068`, `0x00619674 -> 0x004a8a60`, six `__purecall` slots, `0x004a89f0`, `0x004a8a10`, `0x004a8a30`, `0x004a8a50`: `EventHandler`.

## Heuristic / Inference Reanalysis And Validation

### Source ownership and placement

`EventDispatcher` remains owned by [UID:0000J7] `EventDispatcher`, source path `NexusTK/ui/core/EventDispatcher.cpp`.

Evidence: constructor xref from `Application::Initialize`, singleton publication at `g_pEventDispatcher`, UI event routing fan-in, handler traversal state, keyboard shortcut state, idle scheduler glue, read-only vtable data, and current auto-generated coverage all converge on the UI-core EventDispatcher source family.

Rejected alternatives:

- Do not move EventDispatcher to `Application.cpp`. Application constructs and calls it, but the body owns UI routing state and handler traversal.
- Do not move handler traversal to a generic container source. Every normal caller of the handler-search/insert/relink/free/allocation cluster is dispatcher-local, and the record layout is EventHandler-specific.
- Do not preserve `ApplicationHelper_4A6C40.cpp` as a final source. It is a generated wrapper label with no lifecycle/vtable/allocation evidence; exact source-bearing children are routed through EventDispatcher.

`Event` and `EventMan` should remain under [UID:0000J6] `Event.cpp`.

Evidence: `DispatchEvent` has 46 call refs from Event/EventMan producer/factory paths; those factories build event payloads and then dispatch through `g_pEventDispatcher`. That makes Event/EventMan producers consumers of EventDispatcher, not members of the dispatcher class. The base Event constructor/destructor and EventMan/factory pages are already split under `Event.cpp`.

Best header inference:

- `EventDispatcher.h`: EventDispatcher class and public dispatcher API.
- `Event.h`: Event payload and EventMan/event factory declarations.
- `EventHandler.h` is the highest-probability final declaration location for the shared EventHandler interface because both Pane and EventDispatcher need it. Keeping the implementation/emission in `EventDispatcher.cpp` is still the best current route because the EventHandler methods/vtable data are physically adjacent to dispatcher support and current coverage routes [UID:00004N] through [UID:0000J7]. `Pane.h` is a weaker placement because EventHandler is not Pane-private. A single large `EventDispatcher.h` remains possible, but less clean as a final header inference.

### TimerHandler boundary

`0x00597580-0x005975c3` is [UID:0001K7] `TimerHandlerDestructor`, owned by [UID:0000F0] `TimerHandler` and emitted through [UID:0000OT] `TimerMgr`, not EventDispatcher.

Evidence:

- Body writes `TimerHandler` vtable `0x0062e338`.
- Body reads `g_pTimerMgr` `0x0067ab80` and calls unregister helper `0x00597a10`.
- It has fifteen callers across timer-owning classes; EventDispatcher is one base-cleanup caller.
- EventDispatcher deleting destructor at `0x004a7e00` calls it after clearing dispatcher-specific state and `g_pEventDispatcher`.

Rejected stale wording:

- simroot/wave3 cache still contains `EventDispatcher::~TimerHandler(this)` and records `0x00597580` in EventDispatcher metadata. This is stale generated ownership. Use the by-* TimerHandler page and local PE evidence instead.

### Internal helper names

Best-supported source-facing names:

| Address | Recommended source-facing role/name | Evidence and residual risk |
| --- | --- | --- |
| `0x004a6c40` | `EventDispatcher::ProcessIdleWork` or file-local `ProcessIdleWork(EventDispatcher *)` | Called only by `Application::RunMessageLoop`, receives `g_pEventDispatcher` as `ecx`, drains cleanup queue, dispatches timers, rebuilds traversal, dispatches frame slices. Exact original spelling is not recovered; do not keep `ApplicationHelper_4A6C40` as final. |
| `0x004a7120` | `EventDispatcher::CaptureIdleTickBaseline()` | Single message-loop caller passes `g_pEventDispatcher`; reads `g_pTimerMgr+0x18`, writes `this+0x2c`. |
| `0x004a78f0` | `FindHandlerRecordIterator` / `FindEnabledHandlerRecordIterator` | Scans 28-byte records, skips disabled byte `+0x18`, compares `record+0x14` through `HandlerFindFunc`, writes iterator `+0x08`. Prefer a name that mentions iterator mutation; old `FindPaneEntryInTree` is too generated/pane-specific. |
| `0x004a7b10` | `InsertHandlerRecord` | Typed insert/grow for `EventHandlerRecordVector`; copies one 28-byte record and rebinds vector storage. |
| `0x004a7d00` | `DestroyEventHandlerList` / `EventHandlerList::~EventHandlerList` | Destroys dispatcher `+0x20` circular list wrapper and 12-byte nodes. Exact list wrapper original name remains inferred. |
| `0x004a7d60` | `HandlerFindFunc::IsMatch` | Vtable dword `0x00619648`, compares candidate handler pointer/value against expected handler at functor `+0x04`. Anonymous-namespace or file-local predicate is high-probability. |
| `0x004a7e00` | MSVC scalar deleting destructor wrapper for `EventDispatcher` | EventDispatcher vtable first slot. Do not model as ordinary source-authored `~EventDispatcher()` body alone; source-authored destructor content is inside the wrapper before optional delete. |
| `0x004a7e70` | `EventDispatcher::RebuildHandlerTraversalOrder` | Only normal direct caller is idle worker. Reorders/normalizes handler traversal vector and rebuilds index links. |
| `0x004a82b0` | `InsertFirstChildHandlerRecord` | First-child insertion, parent `firstChildIndex`/`lastChildIndex` update, appends new record. First-draft C++ already present in [UID:00022A]. |
| `0x004a8350` | `InsertHandlerRecordAfterSibling` | Appends after sibling, updates parent tail when appropriate. First-draft C++ already present. |
| `0x004a8420` | `RemoveHandlerRecordAndDisableSubtree` | Uses Deque scratch stack, marks target/descendants disabled, repairs parent/sibling links. First-draft C++ already present. |
| `0x004a8680` | `CreateEventHandlerListNodeLinks` | Allocates 12-byte self-linked sentinel or caller-linked node. |
| `0x004a86b0` | `RebindHandlerRecordVectorStorage` | Frees old vector storage with large-allocation validation, publishes new begin/end/capacity. |
| `0x004a8740` | `ReserveHandlerRecordVectorStorage` | Allocates larger buffer, memmoves records, rebinds storage. |
| `0x004a87a0` | `FreeHandlerRecordVector` | Frees and clears vector begin/end/capacity. First-draft C++ already present in [UID:000148]. |
| `0x004a8820` | `AllocateHandlerRecordBuffer` | Count-based 28-byte record allocation helper. First-draft C++ already present in [UID:00022B]. |
| `0x004a8890` | `FreeHandlerRecordBuffer` | Count-aware paired free helper. First-draft C++ already present. |

### Field, type, and global names

Best-supported internal types:

- `EventHandlerRecord`
  - `+0x00 int parentIndex`
  - `+0x04 int firstChildIndex`
  - `+0x08 int lastChildIndex`
  - `+0x0c int previousSiblingIndex`
  - `+0x10 int nextSiblingIndex`
  - `+0x14 EventHandler *handler`
  - `+0x18 unsigned char isDisabled`
  - `+0x19..0x1b padding`
- `EventHandlerRecordVector`
  - `+0x00 EventHandlerRecord *begin`
  - `+0x04 EventHandlerRecord *end`
  - `+0x08 EventHandlerRecord *capacityEnd`
- `EventHandlerTree`
  - `+0x00 vtable`
  - `+0x04 EventHandlerRecordVector records`
- `EventHandlerIterator`
  - `+0x00 vtable`
  - `+0x04 EventHandlerTree *tree`
  - `+0x08 int index`
- `EventHandlerListNode`
  - `+0x00 next`
  - `+0x04 previous`
  - `+0x08 handler/payload value`

Best-supported EventDispatcher state:

- `this+0x00`: `TimerHandler` base subobject. Constructor calls `0x00597570`; destructor calls base cleanup `0x00597580`.
- `this+0x04`: embedded `Tree<EventHandler*>`/`EventHandlerTree` support object.
- `this+0x08/+0x0c/+0x10`: record vector begin/end/capacity through tree offset `+0x04`.
- `this+0x20`: handler/modal circular list wrapper. [UID:000147] proves the list destructor receives dispatcher `+0x20`.
- `this+0x2c`: `m_idleTickBaseline`.
- `this+0x30`: `m_lastDispatchedIdleSlice`.

Best-supported globals:

- `0x0067ab30`: `EventDispatcher *g_pEventDispatcher`.
- `0x0067ab80`: `g_pTimerMgr`, consumed by idle/timer/EventHandler-related paths but owned by TimerMgr.
- `0x0067a74c`: `g_pApplicationCleanupQueue`, consumed by idle worker through BlackHole cleanup.
- `0x0069ae10`: `g_frameRegistry`, consumed by EventDispatcher idle/destructor paths but owned by FrameMgr.
- `0x0069ae18-0x0069af1c`: EventDispatcher keyboard-state buffer/cache child. Direct refs: `0x0069ae18` buffer, `0x0069aea9` VK `0x91` byte, `0x0069af18` cached low bit.
- `0x0069af20`: one-byte keyboard chord gate.
- `0x0069af1c-0x0069af20`: `g_pIdleWatcher`, explicitly excluded from EventDispatcher keyboard storage.
- `0x0066d880`: idle-scheduler timer-resolution/refresh dirty flag, owned with EventDispatcher idle scheduler children.

### Generated ownership refresh issues

Current validator-generated coverage now routes EventDispatcher and support identities to `auto-generated/NexusTK/ui/core/EventDispatcher.cpp`; this is good and should be reflected in the class page.

However, old `simroot_v2` and wave3 cache source still carry stale details:

- `EventDispatcher::~TimerHandler(this)` appears in old generated destructor code.
- `0x00597580` remains mentioned in old metadata as an EventDispatcher destructor-related address even though it is TimerHandler base cleanup.
- Old generated helper names use `sub_4A78F0`, ambiguous `link0/link2/link3` fields, synthetic overlays, and missing helper declarations.

Implementation should treat the current by-* pages and local PE evidence as authority, not the stale simroot method code.

### Open-question closure

Closed or narrowed:

- Handler-record field names are no longer open placeholders. Use `parentIndex`, `firstChildIndex`, `lastChildIndex`, `previousSiblingIndex`, `nextSiblingIndex`, `handler`, and `isDisabled`.
- `Tree<EventHandler*>`, `TreeItor<EventHandler*>`, and `HandlerFindFunc` are EventDispatcher-local support identities, not independent feature modules.
- `ApplicationHelper_4A6C40` is a generated wrapper, not a reconstructable class/source file.
- `0x00597580` is TimerHandler base destructor code, not EventDispatcher code.
- Event/EventMan production belongs to `Event.cpp`; EventDispatcher only routes events already constructed by producers.

Still not source-final, with exact reason:

- Exact original spelling for `FindHandlerRecordIterator`, `DestroyEventHandlerList`, and idle worker helpers is not recovered from strings/symbols. Local PE and docs support descriptive names, but not exact source spellings.
- `EventHandler` header placement cannot be uniquely proven from binary evidence. The highest-probability final direction is a shared `EventHandler.h`, with implementation still emitted through EventDispatcher source family. `EventDispatcher.h` as a combined event-router header remains possible. `Pane.h` is unlikely as sole owner.
- EventHandler event-family virtual names remain provisional. `EventHandlerBase` has purecall slots plus source-defined false-return bodies reached by Pane thunks; final names require a wider Pane/EventHandler vtable coordination pass.
- Class-level formal C++ should remain blank until central EventDispatcher constructor/route/rebuild/destructor method drafts and EventHandler declaration shape are coordinated. Exact support helper children already have draft C++ where safe.

## First-Draft C++ Decision

Do not emit formal C++ in [UID:00004M] `by-class/EventDispatcher.md` yet.

This is a class-level no-code/defer proof, not a no-entry/no-reachability proof:

- The class is real and heavily reachable; constructor, dispatch, timer callback, route, and destructor vtable evidence are strong.
- The target page is an aggregate class documentation page, not one exact method body. A class-level snippet would need to declare a layout spanning `TimerHandler`, embedded tree/vector/list state, idle scheduler fields, keyboard globals, EventHandler interface types, and TimerMgr/FrameMgr dependencies.
- Exact support children already emit draft code for the safest portions: [UID:00022A], [UID:000148], and [UID:00022B]. Duplicating those declarations on the class page risks conflicting type definitions in `auto-generated/NexusTK/ui/core/EventDispatcher.cpp`.
- Central bodies still need method-specific source-quality passes before code: constructor `0x004a6a80`, `RouteEventToHandlers` `0x004a7130`, deleting destructor/source destructor split `0x004a7e00`, traversal rebuild `0x004a7e70`, and idle worker pair `0x004a6c40`/`0x004a7120`.
- `EventHandler` formal code is explicitly deferred by [UID:00014A] until event-family virtual names, pair-output names, dispatcher-forwarding slot name, pure-virtual/default-body declaration style, and header/source placement are coordinated.
- Current generated old simroot method bodies demonstrate the hazard: they contain `EventDispatcher::~TimerHandler`, synthetic overlays, unresolved helper names, and wrong/old record fields.

Acceptable review-only draft fragments for a later coordinated source pass:

```cpp
class EventDispatcher : public TimerHandler {
public:
    EventDispatcher();
    virtual ~EventDispatcher();
    virtual bool OnTimerTick(/* timer callback args */);

    void SetPaneOrder(EventHandler *handler, EventHandler *after, EventHandler *before);
    void RemovePaneEntry(EventHandler *handler);
    void DispatchEvent(Event *event);
    void RebuildHandlerTraversalOrder();

private:
    EventHandlerTree m_handlerTree;
    /* active/previous/list and idle scheduler fields still need a coordinated class layout pass */
};
```

Do not paste this into `RECONSTRUCTION_CPP`; it is only an orientation sketch.

## Implementation Checklist For Later Callback

### Target: `by-class/EventDispatcher.md`

- Update metadata to `COMPLETION:88`, `CONFIDENCE:90`; keep owner/emitter [UID:0000J7].
- Replace stale open questions with the closed/narrowed conclusions above.
- Add or expand sections for:
  - PE-validated constructor, dispatch, idle, route, helper, destructor, and vtable evidence.
  - Current best helper names and record/vector/list/iterator field names.
  - Generated ownership refresh: current auto-generated coverage is routed to `auto-generated/NexusTK/ui/core/EventDispatcher.cpp`, while old simroot/wave3 cache remains stale for `EventDispatcher::~TimerHandler`, `0x00597580`, and ambiguous link fields.
  - Event/EventMan source split: producers/factories stay in [UID:0000J6] `Event.cpp`.
  - EventHandler declaration/source direction: implementation/emission through EventDispatcher source family; highest-probability header is small shared `EventHandler.h`, with `EventDispatcher.h` as a possible original combined header and `Pane.h` rejected as sole owner.
  - TimerHandler boundary: [UID:0001K7] `0x00597580-0x005975c3` remains [UID:0000F0]/[UID:0000OT], not EventDispatcher.
  - Formal C++ no-code/defer proof for this class page.

### Support docs to synchronize

- `by-file/EventDispatcher.md`
  - Add the B012 class-level reanalysis conclusion.
  - Replace remaining "exact helper names open" wording with the best names from this report.
  - Record that current auto-generated coverage now routes dispatcher/support class identities to `auto-generated/NexusTK/ui/core/EventDispatcher.cpp`.
  - Preserve stale simroot caveat for old source/cache output.
  - Do not force a file score bump unless the implementation also incorporates current class-level and helper-name closure thoroughly.

- `by-class/EventHandler.md`
  - Add high-probability header placement direction: shared `ui/core/EventHandler.h` or EventDispatcher-adjacent event header; reject Pane-only ownership.
  - Keep owner/emitter through [UID:0000J7].
  - Preserve formal-C++ deferral until virtual-family names and declaration style are coordinated.

- `by-memory/0x004a8970-0x004a8a84.EventHandlerBase.md`
  - Cross-link the EventDispatcher class decision.
  - Preserve no-code decision and exact reason: virtual names/header placement/pure-default declaration shape.

- `by-class/HandlerFindFunc.md`
  - Update open questions to a narrower statement: anonymous-namespace/file-local predicate under EventDispatcher; use `m_expectedHandler`/`expectedHandler` as best field role but exact spelling unrecovered.
  - Keep no formal code unless the source pass adds the tiny predicate with surrounding helper declarations.

- `by-class/Tree_near_class_EventHandler___.md` and `by-class/TreeItor_near_class_EventHandler___.md`
  - Sync current generated-route evidence and note they are dispatcher-local template/support specializations.
  - Preserve blank formal C++ unless the coordinated EventDispatcher handler-tree type declaration pass emits them.

- `by-type/by-struct/EventDispatcherHandlerTreeLayouts.md`
  - Already contains the key field names; add a cross-link to this class report and remove any residual implication that `+0x04/+0x08` are generic ambiguous links.

- `by-memory/0x004a6a80-0x004a82a9.EventDispatcher.md`
  - Update aggregate C++-gate wording to reflect that exact child pages now emit support helper C++ where safe, while central constructor/route/rebuild/destructor bodies still need method-specific drafts.
  - Add PE xref counts and vtable-slot facts from this pass if not already present.

- `by-memory/0x004a78f0-0x004a7979.EventDispatcherFindHandlerIterator.md`
  - Replace "final helper name open" with best current `FindHandlerRecordIterator`/`FindEnabledHandlerRecordIterator` direction and explain why iterator mutation matters.

- `by-memory/0x004a7b10-0x004a7c2a.EventDispatcherHandlerRecordVectorInsert.md`
  - Sync `InsertHandlerRecord` as best helper name and link the resolved record fields.

- `by-memory/0x004a7cd0-0x004a7df3.EventDispatcherHandlerTreeSupport.md` and `by-memory/0x004a7d00-0x004a7d43.EventDispatcherHandlerListDestructor.md`
  - Add the class-level conclusion and best `DestroyEventHandlerList`/list wrapper naming direction.

- `by-memory/0x004a82b0-0x004a8795.EventDispatcherHandlerRecordRelinkHelpers.md`, `by-memory/0x004a87a0-0x004a8810.EventDispatcherHandlerRecordVectorFree.md`, and `by-memory/0x004a8820-0x004a88d2.EventDispatcherHandlerRecordVectorAllocationHelpers.md`
  - These are already high-quality after B002. Only add a small cross-link to the class-level source-quality closure if desired; do not churn working C++.

- `by-file/Event.md`
  - Optional, only if the EventDispatcher implementation adds support wording: record that Event/EventMan producers stay in `Event.cpp` and call EventDispatcher; no score change needed.

- `by-file/TimerMgr.md`, `by-class/TimerHandler.md`, and `by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md`
  - No required edits for this callback; current docs already reject EventDispatcher ownership. If touched, only add a cross-reference that EventDispatcher is one destructor consumer.

### Generated docs/source

Do not hand-edit `auto-generated` files. The validator/autogen route already surfaces EventDispatcher output. Any generated updates should come from by-* source docs during the implementation callback.

### Coverage

Do not edit `by-memory/-coverage-report.md`. For this by-class target, supervisor-owned pending row text belongs in `by-class/-coverage-report.md` if accepted:

```text
- [UID:00004M][EventDispatcher](by-class/EventDispatcher.md) : reconstructable : 88% : strong : B012 2026-06-19 source-quality reanalysis keeps `EventDispatcher` under [UID:0000J7] `NexusTK/ui/core/EventDispatcher.cpp`, resolves dispatcher-local handler-record fields and helper roles from local PE xrefs and exact support pages, keeps Event/EventMan producers in [UID:0000J6] `Event.cpp`, keeps [UID:0001K7] `TimerHandlerDestructor` under [UID:0000F0]/[UID:0000OT] instead of EventDispatcher, rejects stale `ApplicationHelper_4A6C40` and old simroot `EventDispatcher::~TimerHandler` ownership labels, and records a target-specific no-class-C++ proof while first-draft helper code remains in the exact EventDispatcher support children.
```

## Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00004M-EventDispatcher-class-source-quality-removed.md](00004M-EventDispatcher-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`
- `ok: 1`
- Important target line: `ok 00004M by-class/EventDispatcher.md UID header exists`
- Dry run only; no `--apply`.
- The validator reported generated/autogen dry-run updates elsewhere, but no files were intentionally edited by this report-only pass.

## Report-Only Change Record

Files intentionally created/updated by this pass:

- Created `tools/leaser/Agents/Agent-B012/research/00004M-EventDispatcher-class-source-quality.md`
- Updated `tools/leaser/Agents/Agent-B012/notes.md`

Files intentionally not edited:

- `by-class/EventDispatcher.md`
- any other `by-*` documentation file
- `by-memory/-coverage-report.md`
- generated source/coverage files

FINISHED.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000004165","destination_path":"executed-b-agent-research/B012/00004M-EventDispatcher-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"00004M"} -->
<!-- {"agent":"B012","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00004M-EventDispatcher-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B012/00004M-EventDispatcher-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00004M"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
