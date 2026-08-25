*** UID:0000OT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# TimerMgr

## 2026-07-19 UID0002KX Source And Standard-Library Closure

- `NexusTK/util/TimerMgr.h` owns the complete `ScheduledTimerEvent` and `TimerMgr` declaration union; `NexusTK/util/TimerMgr.cpp` owns the scheduler method definitions. The header requires `<deque>` and the source member is `std::deque<ScheduledTimerEvent> m_timerQueue`.
- UID0002KX is the public const, nonvirtual `DWORD TimerMgr::FindQueuedTimerDueTick(TimerHandler* owner, int timerId) const` definition. It searches scheduled values newest-to-oldest, returns an absolute due tick for the first owner/id match, and returns zero on miss.
- The existing constructor, virtual ordinary destructor, dispatch, schedule, owner-removal, cancel, cancel-except, timer-period, tick-refresh, TimerHandler wrappers, singleton publication, current-tick mirrors, vtable, and static-storage source union remains in this file. No existing source body is duplicated.
- The binary queue island is the instantiated Dinkumware implementation of the standard deque member. [UID:0000F2][TimerMgrScheduledEventDequeCompilerSupport](by-class/TimerMgrScheduledEventDequeCompilerSupport.md) and its reverse/rotate/destructor/grow/erase/insert children document compiler support only; they are not project classes or handwritten source helpers.
- Historical claims that this file defines `TimerMgrTimerQueue`, pointer slots, nullable event records, iterator APIs, event allocators, reverse/rotate helpers, or bespoke grow/splice/insert methods are retained as superseded decompiler interpretations. Exact machine behavior, call graph, hashes, boundaries, and padding remain evidence for the standard-library classification.
- Compiler-only queue helpers, scalar deleting destructor mechanics, EH singleton clear support, vtable data, and padding are excluded from handwritten source. They are regenerated from the standard container, declarations, ordinary destructor, global/static objects, and compiler ABI.

## UID0000IF Direct TimerMgr Header Closure - 2026-08-24

- [UID:0000F1][TimerMgr](by-class/TimerMgr.md) directly owns the complete `NexusTK/util/TimerMgr.h` declaration union. Its formal H now has sole guard `NEXUSTK_UTIL_TIMERMGR_H`, retains the exact include/declaration order, and closes after `extern TimerMgr *g_pTimerMgr;`.
- No H-emitting child exists, so the former terminal no-child placeholder is removed rather than replaced with an invented fragment. The class CPP remains the self-header include plus namespace-scope child expansion, preserving all existing scheduler method/body routes.
- `ScheduledTimerEvent`, `TimerMgr`, `std::deque<ScheduledTimerEvent> m_timerQueue`, public `DWORD m_currentTick` at `+0x18`, private `m_timerPeriod`/`m_nextDueTick`, extern storage declaration, API, `0x24` layout, FILE ownership, `NexusTK/util/` path, and scores `94/95` remain unchanged.
- Rejected routes remain a child-owned guard, duplicate public declaration, PCH-only completeness, folded TimerHandler type, CPP-local header types, custom `TimerMgrTimerQueue` source API, or any layout/access rewrite.
- Required generated proof is one guard pair, zero placeholders, each include/type/class/extern exactly once in preserved order, unchanged public `DWORD m_currentTick`, and a later ConnStatusPane regeneration retaining its exact TimerMgr-dependent semantics.

## Status

- Proposed module: `util/TimerMgr.cpp`
- Proposed header: `util/TimerMgr.h`
- Confidence: strong for `TimerMgr`, `TimerMgrTimerQueue`, timer singleton/static storage, and tick mirror globals; medium for folding `TimerHandler` and wrapper thunks into the same source file.
- Evidence basis: IDA MCP boundary/caller checks, locality around `0x00597570-0x005986da`, and current project-documentation child pages.

## File Role

`TimerMgr.cpp` owns the client-side timer scheduler. It keeps a singleton pointer in [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md), stores a static process-wide `TimerMgr` instance at `0x0069b3ac`, initializes multimedia timer resolution through `timeGetDevCaps`/`timeBeginPeriod`, mirrors current tick values into globals, and maintains a sorted ring queue of scheduled timer events.

## UID000090 Explicit TimerHandler And TimerMgr Split - 2026-07-31

- `NexusTK/util/TimerMgr.h` owns `ScheduledTimerEvent`, complete `TimerMgr : public LObject`, the `std::deque<ScheduledTimerEvent>` member, scheduler/tick methods, and `g_pTimerMgr`. `TimerMgr.cpp` includes that header and owns exact scheduler/container method bodies.
- Separate [UID:0004ZO][TimerHandler](by-file/TimerHandler.md) owns `TimerHandler.h/.cpp`, the abstract four-byte callback interface, and thin manager-forwarding wrappers. TimerMgr consumes the complete handler declaration; it no longer doubles as the handler declaration owner.
- The explicit split preserves physical adjacency and every binary/body relationship while giving Pane, EventDispatcher, and other derived handlers a complete reusable base header.
- Historical folded TimerHandler-in-TimerMgr source wording remains provenance only. A PCH-only base, CPP-local public declarations, raw lowered deque project API, or duplicate timer-handler definitions are rejected.

The queue is not a generic container. It stores [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md) records sorted by due tick and dispatches them through the owner's `TimerHandler` virtual callback.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:0000F0][TimerHandler](by-class/TimerHandler.md) | `0x00597570-0x005976b3` | Base class for timer callback owners plus thin helpers around the global manager. Current TimerHandler child paths are `by-memory/0x00597570-0x00597579.TimerHandlerConstructor.md`, [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md), `by-memory/0x005975d0-0x005975d5.TimerHandlerOnTimerPureVirtualBody.md`, [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md), [UID:0001K9][0x00597610-0x00597645.TimerHandlerWrappers](by-memory/0x00597610-0x00597645.TimerHandlerWrappers.md), and `by-memory/0x00597650-0x005976b3.TimerHandlerScalarDeletingDestructor.md`. Older NewHumanImageLib path annotations for UID000417/UID000418/UID000419 are stale UID-collision annotations, not TimerMgr evidence. |
| [UID:0000F1][TimerMgr](by-class/TimerMgr.md) | `0x005976c0-0x00597eaa`, scalar deleting destructor wrapper at `0x00598090` | Singleton scheduler, multimedia timer setup, dispatch, cancellation, private query/tick helpers, and generated destructor-wrapper semantics. The middle manager methods are the current TimerMgr child paths `by-memory/0x005976c0-0x00597780.TimerMgrConstructor.md`, `by-memory/0x00597780-0x005977ac.TimerMgrStaticDestructorBody.md`, `by-memory/0x005977b0-0x0059790a.TimerMgrDispatchDueTimers.md`, `by-memory/0x00597910-0x00597a0c.TimerMgrScheduleTimer.md`, `by-memory/0x00597a10-0x00597b73.TimerMgrRemovePendingTimersForOwner.md`, `by-memory/0x00597b80-0x00597c99.TimerMgrCancelTimer.md`, and `by-memory/0x00597ca0-0x00597db9.TimerMgrCancelPendingTimersExceptEvent.md`. Older NewHumanImageLib/VectorGrow annotations for UID00041A-UID00041G are stale UID-collision annotations. The queue-helper tail is mapped at [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md), but that aggregate is non-emitting context rather than a source body. |
| [UID:0000F2][TimerMgrScheduledEventDequeCompilerSupport](by-class/TimerMgrScheduledEventDequeCompilerSupport.md) | `0x00597fe0-0x00598083` plus queue helpers | Embedded ring queue for scheduled timer records. |
| [UID:0002KX][0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick](by-memory/0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick.md) | `0x00597dc0-0x00597e3f` | Scans queued events for an owner/event pair and returns its due tick. |
| [UID:0002KY][0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod](by-memory/0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod.md) | `0x00597e40-0x00597e8a` | Private `TimerMgr` WinMM timer-period setup using `timeGetDevCaps`, `timeBeginPeriod`, `timeGetTime`, `m_timerPeriod`, `m_currentTick`, and tick mirrors. |
| [UID:0002KZ][0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick](by-memory/0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md) | `0x00597e90-0x00597ea3` | Private `TimerMgr` current-tick refresh that writes `m_currentTick` and the current-tick mirror. |
| [UID:0002L0][0x00597eb0-0x00597f17.TimerQueueReverseRange](by-memory/0x00597eb0-0x00597f17.TimerQueueReverseRange.md) | `0x00597eb0-0x00597f16` | Reverses queue slots; called only by rotate helper. |
| [UID:0002L1][0x00597f20-0x00597fc9.TimerQueueRotateRange](by-memory/0x00597f20-0x00597fc9.TimerQueueRotateRange.md) | `0x00597f20-0x00597fc8` | Rotate helper used by `InsertTimer`. |
| [UID:0002L2][0x00597fd0-0x00597fdb.ClearGlobalTimerMgr](by-memory/0x00597fd0-0x00597fdb.ClearGlobalTimerMgr.md) | `0x00597fd0-0x00597fdb` | Compiler/EH constructor-unwind singleton-clear thunk; source effect belongs to `TimerMgr` construction cleanup, not a handwritten helper. |
| [UID:0002L3][0x00597fe0-0x00598083.TimerMgrTimerQueueDestructor](by-memory/0x00597fe0-0x00598083.TimerMgrTimerQueueDestructor.md) | `0x00597fe0-0x00598083` | `TimerMgrTimerQueue::~TimerMgrTimerQueue()`, releasing queued records, slot storage, and root/sentinel storage. |
| [UID:0002L4][0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor](by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md) | `0x00598090-0x005980eb` | Compiler scalar deleting destructor wrapper attached to `TimerMgr`; vtable-reached through `0x0062e344`, not a handwritten aggregate helper. |
| [UID:0002L5][0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity](by-memory/0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity.md) | `0x005980f0-0x00598281` | Reallocates/grows the slot-entry array with MSVC aligned-allocation handling. |
| [UID:0002L6][0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange](by-memory/0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange.md) | `0x00598290-0x00598471` | Queue-owned source-facing `EraseRange(first,last)` helper, filename kept stable under the older splice label. |
| [UID:0002L7][0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer](by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md) | `0x00598480-0x005986d9` | Queue-owned sorted insert helper, source-facing `InsertTimer(Iterator where, const ScheduledTimerEvent &event)`. |
| timer globals | `0x0067ab80`, `0x0069b3ac`, [UID:000306][0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror](by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md), [UID:000307][0x0069be10-0x0069be14.TimerMgrCurrentTickMirror](by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md) | Singleton pointer, static instance, and tick mirrors. |

## Evidence Notes

- `TimerMgr` and `TimerMgrTimerQueue` are documented under this module because their IDA-modeled methods share the same compact scheduler cluster and queue-state dependencies.
- `TimerHandler` may still have been a tiny companion source, but IDA places its constructor/destructor/default-callback/wrapper functions immediately before `TimerMgr`; caller evidence shows the wrappers forward to `g_pTimerMgr`.
- 2026-06-30 B009 implementation of the accepted TimerMgr empty-emitter report keeps this file as `NexusTK/util/TimerMgr.cpp`, raises the score to `92/90`, and resolves the current empty-emitter family by adding formal C++/marker blocks on the 16 child/support pages. The final disk split between `TimerHandler.cpp` and `TimerMgr.cpp` remains unproven, but no current PDB/source-path string proves a separate TimerHandler translation unit, so the generated route through this file remains the source-placement decision.
- B009 reconciles stale UID/path pollution in this page: UID000417-UID00041G references that display NewHumanImageLib or VectorGrow paths are historical validator/registry collisions, not TimerMgr child evidence. Current TimerMgr/TimerHandler path references above are the controlling documentation for this source family, while unrelated NewHumanImageLib and VectorGrow target pages remain untouched.
- B009 current MCP-backed initializer reconciliation supersedes older raw-data prose for TimerMgr globals where it conflicts with the active IDB: `0x0067ab80`, `0x0069b3ac`, `0x0069be0c`, and `0x0069be10` currently read as zero-initialized image bytes. Runtime constructor writes such as `m_nextDueTick = 0xffffffff` remain valid behavior facts and are separate from image initializers.
- IDA confirms the compact cluster from `0x00597570` through `0x005986da`, ending before `TimerPane` at `0x005986e0`.
- 2026-05-31 IDA MCP split pass confirmed exact queue-helper children inside [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md), including timer-period/tick helpers, queue reverse/rotate, clear, destructor, grow, splice, and insert pages.
- `TimerMgr::ScheduleTimer` has broad caller fan-in from UI, object, map, and application systems. That supports a utility scheduler module rather than feature-local timer ownership.
- `TimerMgr::DispatchDueTimers` is called by the application helper/message-loop path at `0x004a6c40`, after the timer resolution setup call.
- 2026-06-23 B002 current-session repair using IDA session `80de0a67` keeps the same `util/TimerMgr.cpp` source-family placement while resolving the former `0x005975d0` no-owner blocker. The current child `by-memory/0x005975d0-0x005975d5.TimerHandlerOnTimerPureVirtualBody.md` is owned/emitted by [UID:0000F0][TimerHandler](by-class/TimerHandler.md) as the retained out-of-line body for the pure virtual timer callback; exact bytes are `b0 01 c2 0c 00`, the body has zero live xrefs/pointer route, and `0x0062e33c -> __purecall` explains why it is not vtable-installed. Older [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md) NewHumanImageLib display text is a stale UID-collision annotation.
- 2026-06-23 B004 current MCP session `ff68e691` reconfirms this file route with current IDB provenance (`E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, endpoint `http://127.0.0.1:13337/mcp`, health `ok`) and stable executable SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`. The aggregate bytes for [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md) remain `0x116a` bytes with SHA-256 `c0a6bd2c92aa4f8c9317f340af5b397ab8508ff7f88ef8579943794b21363fcf`, fenced by `0xcc` padding at `0x0059756e-0x00597570`, `0x00597579-0x00597580`, `0x005975c3-0x005975d0`, `0x005975d5-0x005975e0`, `0x005977ac-0x005977b0`, `0x00597b73-0x00597b80`, `0x00597c99-0x00597ca0`, `0x00597db9-0x00597dc0`, and `0x005986da-0x005986e0`.
- B004 session `ff68e691` keeps the exact source-family inventory in this file: `TimerHandler` constructor/destructor/wrappers/scalar deleting destructor at `0x00597570-0x005976b3`, `TimerMgr` constructor/static destructor body/dispatch/schedule/removal/query/tick helpers at `0x005976c0-0x00597eaa` plus the scalar deleting destructor at `0x00598090`, and `TimerMgrTimerQueue` destructor/capacity/erase/insert helpers at `0x00597fe0-0x005986d9`. The IDA model still reports the `0x00597780` destructor body through `sub_60C270`, but bytes and disassembly place the real static destructor body at `0x00597780-0x005977ac` with the final jump at `0x005977a7` and padding from `0x005977ac`.
- B004 [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) wrapper-specific recheck with the same session keeps this file as the source-family route for exact child C++ while preserving [UID:0000F0][TimerHandler](by-class/TimerHandler.md) as the direct class owner. `lookup_funcs` reports `sub_5975E0` at `0x005975e0` size `0x1f` / 31 and `sub_597600` at `0x00597600` size `0x0d` / 13 (Verified with int_convert.py), with no function at `0x005975ff` or `0x0059760d`. The schedule wrapper loads [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md) from `0x0067ab80` and calls the current manager schedule helper `by-memory/0x00597910-0x00597a0c.TimerMgrScheduleTimer.md`; the remove wrapper loads the same singleton and calls the current owner-removal helper `by-memory/0x00597a10-0x00597b73.TimerMgrRemovePendingTimersForOwner.md`. Current xrefs show 163 code refs to the schedule wrapper, 45 to the remove wrapper, 48 to the manager schedule helper, and 20 to the manager owner-removal helper. Zero data xrefs and zero VA/RVA/raw-offset pointer-pattern hits for `0x005975e0`/`0x00597600` keep the route as direct-call wrapper fan-in, not a table/vtable owner.
- Current source-breadcrumb exhaustion keeps this file route as the safest emitter family. The accepted B002 report checked the executable for `RSDS`, `NB10`, `.pdb`, `TimerHandler.cpp`, `TimerMgr.cpp`, and `OnTimer` strings and found no authoritative source-path clue; Wave2/Wave3 `TimerHandler.cpp` lead data omit `0x005975d0` and remain generated/import evidence, not source proof. A separate `TimerHandler.cpp` remains possible but unsupported by current authoritative evidence.
- Generated output continues to route through exact child pages. `auto-generated/NexusTK/util/TimerMgr.cpp` has child C++ for the already-emitting constructor/wrapper/query/tick/queue helpers, the current TimerHandler pure-virtual body `by-memory/0x005975d0-0x005975d5.TimerHandlerOnTimerPureVirtualBody.md`, and the B009-accepted empty-emitter repairs once validators refresh the file. Aggregate [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md) remains a source-family container; exact children or support docs own the emitted source/marker text.
- [UID:000306][0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror](by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md) and [UID:000307][0x0069be10-0x0069be14.TimerMgrCurrentTickMirror](by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md) now isolate the exact writable tick-mirror storage documented by the `TimerMgrBeginTimerPeriod` and `TimerMgrRefreshCurrentTick` child pages.
- [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md) is a tick consumer, not a TimerMgr owner: its raw constructor seeds `m_lastShakeTick` from `g_pTimerMgr->+0x18 - 0x3c`, and `ApplyEffect` uses the same current-tick field to accept a new random shake sample only when the delta exceeds `0x50`.
- A004 Batch 056 attempted a live IDA MCP refresh of the adjacent tick globals, but repeated `py_eval`, `xrefs_to`, and `idb_meta` calls timed out. The confidence raise uses already written IDA-backed TimerMgr helper pages and the exact memory split, not new live facts.

## Boundary and Ownership Caveats

- IDA decompiles the `0x00597580` non-deleting destructor with a `boost::exception` type label, but its body installs the `TimerHandler` vtable and unregisters from `g_pTimerMgr`.
- `0x00597580` was previously documented as an `EventDispatcher` destructor and `0x00597600` as an `InterfaceEfx` removal helper. IDA body checks resolve both as generic `TimerHandler` cleanup/wrapper code.
- The exact queue-helper page records IDA evidence for `FindQueuedTimerDueTick`, timer-period setup, current-tick refresh, queue reverse/rotate, capacity grow, splice, and insert behavior.
- Historical IDA naming has associated `0x00597780` with `sub_60C270`; B002 MCP session `b880584f` confirms the model oddity by showing `lookup_funcs 0x00597780` resolving to wrapper `sub_60C270` while `disasm`/`get_bytes` place the actual `TimerMgr` destructor body at current child `by-memory/0x00597780-0x005977ac.TimerMgrStaticDestructorBody.md`. Wrapper `0x0060c270` is the static-destruction registration/thunk context for the instance at `0x0069b3ac`.
- B004 MCP session `ff68e691` preserves the same `sub_60C270` model oddity and the same owner rejection set. Keep [UID:0000OU][TimerPane](by-file/TimerPane.md), [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md), ThreadMan, MapPane, feature-local panes, and sound code as neighbors or consumers, not owners of this scheduler/queue source file.
- The unresolved `TimerHandler` file split remains a module-level caveat, but it does not block confidence for the two exact tick-mirror storage children because both are written by TimerMgr-owned timer-period/current-tick helpers.

## Source-Structure Decision

Preserve `TimerMgr`, `TimerMgrTimerQueue`, the timer queue helper functions, and probably `TimerHandler` in one timer scheduler module. If a future original-source clue proves a separate `TimerHandler.cpp`, keep it as a tiny companion source with `TimerMgr.h` owning the shared declarations.

## B015 Queue Helper Routing

B015 `0001KA` source-quality reanalysis treats [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md) as a reviewed non-emitting context page. Source output should route through exact children: `FindQueuedTimerDueTick`, `BeginTimerPeriod`, `RefreshCurrentTick`, and scalar-deleting-destructor semantics attach to [UID:0000F1][TimerMgr](by-class/TimerMgr.md); reverse/rotate, destructor, `EnsureCapacityForInsert`, `EraseRange`, and `InsertTimer` attach to [UID:0000F2][TimerMgrScheduledEventDequeCompilerSupport](by-class/TimerMgrScheduledEventDequeCompilerSupport.md); and `ClearGlobalTimerMgr` is a compiler/EH cleanup thunk with no emitted helper body.

The same pass rejects [UID:0000OU][TimerPane](by-file/TimerPane.md), [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md), feature-local panes, sound code, and map objects as owners for the scheduler tail. Those modules are timer consumers or adjacent timer-related code, not owners of the queue implementation. Draft support names for this module are `m_timerPeriod`, `m_currentTick`, `m_nextDueTick`, `g_timerTickBaselineMirror`, and `g_timerCurrentTickMirror`; the mirror names remain descriptive because stripped binary evidence cannot prove exact original spellings.

## B002 Middle Method Routing

B002 implementation for [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md) does not change this file's source-placement decision. It strengthens it: the newly exact middle children all route either to [UID:0000F0][TimerHandler](by-class/TimerHandler.md) or [UID:0000F1][TimerMgr](by-class/TimerMgr.md), and those class pages emit through this file root.

The file-level source-shape blockers are narrowed. The current child `by-memory/0x005975d0-0x005975d5.TimerHandlerOnTimerPureVirtualBody.md` is source-ready and emits through [UID:0000F0][TimerHandler](by-class/TimerHandler.md). Larger `TimerMgr` child pages still record no-code proofs where final C++ would require settled queue iterator/API declarations or destructor/member-destruction ordering. The aggregate [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md) remains a blank-code source-family container, not a monolithic C++ body.

## Cross-References

- [UID:0000F1][TimerMgr](by-class/TimerMgr.md)
- [UID:0000F2][TimerMgrScheduledEventDequeCompilerSupport](by-class/TimerMgrScheduledEventDequeCompilerSupport.md)
- [UID:0000F0][TimerHandler](by-class/TimerHandler.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- `by-memory/0x00597570-0x00597579.TimerHandlerConstructor.md`
- `by-memory/0x005975d0-0x005975d5.TimerHandlerOnTimerPureVirtualBody.md`
- `by-memory/0x00597650-0x005976b3.TimerHandlerScalarDeletingDestructor.md`
- `by-memory/0x005976c0-0x00597780.TimerMgrConstructor.md`
- `by-memory/0x00597780-0x005977ac.TimerMgrStaticDestructorBody.md`
- `by-memory/0x005977b0-0x0059790a.TimerMgrDispatchDueTimers.md`
- `by-memory/0x00597910-0x00597a0c.TimerMgrScheduleTimer.md`
- `by-memory/0x00597a10-0x00597b73.TimerMgrRemovePendingTimersForOwner.md`
- `by-memory/0x00597b80-0x00597c99.TimerMgrCancelTimer.md`
- `by-memory/0x00597ca0-0x00597db9.TimerMgrCancelPendingTimersExceptEvent.md`
- [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md)
- [UID:0001K7][0x00597580-0x005975c3.TimerHandlerDestructor](by-memory/0x00597580-0x005975c3.TimerHandlerDestructor.md)
- [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)
- [UID:00024G][0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators](by-memory/0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators.md)
- [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md)
- [UID:000306][0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror](by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md)
- [UID:000307][0x0069be10-0x0069be14.TimerMgrCurrentTickMirror](by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md)
- [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md)
- [UID:0001WD][TimerMgrLayout](by-type/by-struct/TimerMgrLayout.md)
- [UID:0001QU][client_timing](by-meta/client_timing.md)
- [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-08-24 B003 UID0000IF C139 ordinary implementation callback:
  - Made UID0000F1's complete TimerMgr H route independently guarded and placeholder-free without changing its CPP child expansion.
  - Preserved all scheduler/TimerHandler/container ownership, declaration order, layout/API, score/path metadata, generated-source ownership, compiler exclusions, and unrelated history. Generated files remain validator-owned and require the exact guard/order/placeholder/tick and downstream ConnStatusPane proof above.

- 2026-06-30 B009 implementation callback for `0000OT`:
  - Score/metadata changed to `92/90`, preserving `CANONICAL_OWNER:FILE` and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`.
  - Summary/evidence: implemented the accepted TimerMgr empty-emitter family report by routing current TimerHandler/TimerMgr child paths through this file, historicalizing older UID000417-UID00041G NewHumanImageLib/VectorGrow display names as stale UID-collision annotations, reconciling current zero-initialized TimerMgr globals against older `0xffffffff` image-byte prose, and documenting that exact child/support pages own the newly emitted C++ or marker blocks.
- 2026-06-23 B002 implementation callback for [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md):
  - Score/metadata unchanged at `90/86`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`.
- Summary/evidence: replaced the obsolete [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md) orphan-callback caveat with a source-emitting TimerHandler child through this file/source-family route. Current MCP session `80de0a67` confirms the exact bytes/padding, zero xrefs/pointer route, vtable `0x0062e33c -> __purecall`, and pure virtual out-of-line body model; current source-breadcrumb checks found no PDB/source-path string proving a separate `TimerHandler.cpp`, so [UID:0000OT] remains the safest emitter route.
- 2026-06-23 B004 implementation callback for `0001K8`:
  - Score/metadata unchanged at `90/86`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`.
  - Summary/evidence: added current [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) support sync from MCP session `ff68e691`, preserving this file as the source-family route for exact TimerHandler wrapper C++ while [UID:0000F0][TimerHandler](by-class/TimerHandler.md) remains the direct owner. The sync records exact wrapper sizes/ranges, direct `g_pTimerMgr` calls to [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md) and [UID:00041E][0x004e4f10-0x004e50a0.VectorGrowAcc2Drw](by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md), 163/45 wrapper caller counts, 48/20 manager helper xrefs, zero data/pointer route to wrapper entries, generated child-C++ state, raw `int` versus source `void` caveat, and unresolved original spelling/source split.
- 2026-06-23 B004 implementation callback for `0001K6`:
  - Score/metadata unchanged at `90/86`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`.
  - Summary/evidence: historical [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md) empty-marker conclusion superseded by the current B002 repair. The `ff68e691` source-route evidence remains valid for executable/IDB provenance, aggregate hash/padding fences, function inventory, the `0x00597780` static destructor wrapper/body oddity, `0x005975d0` zero-route/pointer-search proof with positive controls, `0x0062e33c -> __purecall`, aggregate no-code proof, and rejection of TimerPane/WaitableTimer/ThreadMan/MapPane/feature/sound ownership alternatives.
- 2026-06-23 B002 implementation callback for `0001K6`:
  - Score/metadata unchanged at `90/86`, `CANONICAL_OWNER:FILE`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/"`.
  - Summary/evidence: synchronized the source-placement page with exact B002 middle children [UID:000417][0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord](by-memory/0x004e0d70-0x004e0dcf.NewHumanImageLibLoadPartFrameDrawRecord.md) through [UID:00041G][0x004e5420-0x004e55f6.VectorGrowPart](by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md), reconciled the accepted B002 MCP session `b880584f` evidence, corrected static destructor route/range to `0x00597780-0x005977ac`, preserved the `sub_60C270` wrapper/body distinction, preserved `TimerPane`/`WaitableTimer`/feature-consumer owner rejection, and documented that the aggregate remains blank-code while child C++ blockers are resolved.
- 2026-06-22 Rule 26 incorporation of B015 TimerMgrQueueHelpers report:
  - Score unchanged.
  - Summary/evidence: expanded the module contents with the normalized TimerMgr/TimerMgrTimerQueue child routing, compiler cleanup/destructor-wrapper classifications, first-draft source-facing helper names, TimerPane/WaitableTimer rejection, and descriptive tick mirror/global naming policy.
- 2026-06-19 B007 EarthquakeEffecter support sync:
  - Score unchanged.
  - Summary/evidence: added Earthquake as a current-tick consumer using `g_pTimerMgr->+0x18` for constructor seed and `0x50` shake-sample cadence; ownership remains with the TimerMgr utility module.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `88` and confidence to `80`.
  - Evidence: document covers timer scheduler role, contents, TimerHandler/TimerQueue relation, queue helper functions, static/global data, IDA evidence, boundary/ownership caveats, source-structure decision, and cross-references; confidence is capped by final TimerHandler split.
- 2026-05-31: Assigned projected reconstruction path.
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - After: set path to `NexusTK/util/`.
  - Evidence: the page already documents `util/TimerMgr.cpp` as the working module, and the 2026-05-31 IDA MCP recheck reconfirmed the `g_pTimerMgr` storage at `0x0067ab80`, broad timer xrefs, the constructor at `0x005976c0`, and application dispatch use around `0x004a6c40`.
- 2026-05-31: Replaced plain queue-helper rows with exact by-memory child references.
  - Before: `FindQueuedTimerDueTick`, `ReverseTimerQueueRange`, `RotateTimerQueueRange`, and `EnsureTimerQueueCapacity` were listed as plain address rows with broad/inclusive-end drift.
  - After: rows link to exact IDA-verified child pages under [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md).
  - Evidence: IDA MCP `lookup_funcs`, `callers`, and byte-padding checks confirmed the exact function ranges and helper relationships.
- 2026-06-07 A004 Batch 056 tick-global parent-gate refresh:
  - Before: `88/80`, below the corrected confidence gate for exact timer tick storage assignment.
  - Changed to: `90/86`, linking exact tick storage children [UID:000306][0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror](by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md) and [UID:000307][0x0069be10-0x0069be14.TimerMgrCurrentTickMirror](by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md).
  - Summary/evidence: existing IDA-backed timer-period and current-tick helper pages prove the two global writes, and the unresolved `TimerHandler` source split no longer blocks the narrower TimerMgr tick-storage ownership decision. Live MCP refresh timed out during this pass, so the file remains below final-audit confidence.
