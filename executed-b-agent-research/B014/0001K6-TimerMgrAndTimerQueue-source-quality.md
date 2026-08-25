** TARGET-REPORT-UID:0001K6 **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001K6 TimerMgrAndTimerQueue Source-Quality Reanalysis

Agent: Agent-B014  
Assignment: `B014-goal2-TimerMgrAndTimerQueue-source-quality-0001K6-20260619`  
Target: [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](../../../by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)  
Report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B014\research\0001K6-TimerMgrAndTimerQueue-source-quality.md`  
Mode: report-only. No by-* files and no `by-memory/-coverage-report.md` are edited by this pass.

## Bottom Line

Keep [UID:0001K6] attached to [UID:0000OT][TimerMgr](../../../by-file/TimerMgr.md), keep `RECONSTRUCTABLE:TRUE`, keep `EMITTER_UIDS:0000OT`, and keep the target score at `85/87` for now. The source placement is strong: this is the compact `util/TimerMgr.cpp` scheduler island containing `TimerHandler`, `TimerMgr`, and the embedded `TimerMgrTimerQueue` helper family. The blocker is not ownership. The blocker is source-quality granularity: several middle functions are still only rows inside the aggregate rather than exact child pages with raw body/caller/touched-state evidence.

The active C++ gate is technically satisfied by the target metadata, but this aggregate should not receive first-draft monolithic C++. It covers many independent functions, exact children, compiler padding, vtable/static storage effects, and still-unsplit middle methods. Final C++ belongs in exact function/class/global/type pages and the source file page. The aggregate should keep its C++ block blank, with an explicit aggregate no-code proof replacing the stale "wait for 95/95" wording.

## Evidence Reviewed

- Governing instructions: `Supervisor.md`, `.codex/AGENTS.md`, Agent-B014 `goal.md`, and Agent-B014 `notes.md`.
- Target page: [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](../../../by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md).
- Source/class pages: [UID:0000OT][TimerMgr](../../../by-file/TimerMgr.md), [UID:0000F0][TimerHandler](../../../by-class/TimerHandler.md), [UID:0000F1][TimerMgr](../../../by-class/TimerMgr.md), [UID:0000F2][TimerMgrTimerQueue](../../../by-class/TimerMgrTimerQueue.md).
- Global/type/data pages: [UID:0000SI][g_pTimerMgr](../../../by-global/g_pTimerMgr.md), [UID:0002VW][0x0067ab80-0x0067ab84.g_pTimerMgr](../../../by-memory/0x0067ab80-0x0067ab84.g_pTimerMgr.md), [UID:00029S][0x0069b3ac-0x0069b3d0.TimerMgrStaticObjectStorage](../../../by-memory/0x0069b3ac-0x0069b3d0.TimerMgrStaticObjectStorage.md), [UID:000306][0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror](../../../by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md), [UID:000307][0x0069be10-0x0069be14.TimerMgrCurrentTickMirror](../../../by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md), [UID:0001WD][TimerMgrLayout](../../../by-type/by-struct/TimerMgrLayout.md), [UID:0001VX][ScheduledTimerEvent](../../../by-type/by-struct/ScheduledTimerEvent.md), [UID:0003E0][0x0062e334-0x0062e340.TimerHandlerVtableData](../../../by-memory/0x0062e334-0x0062e340.TimerHandlerVtableData.md), [UID:0003E1][0x0062e344-0x0062e354.TimerMgrVtableData](../../../by-memory/0x0062e344-0x0062e354.TimerMgrVtableData.md).
- Exact executable children: [UID:0001K7], [UID:0001K8], [UID:0001K9], [UID:0001KA], [UID:0002KX], [UID:0002KY], [UID:0002KZ], [UID:0002L0], [UID:0002L1], [UID:0002L2], [UID:0002L3], [UID:0002L4], [UID:0002L5], [UID:0002L6], and [UID:0002L7].
- Boundary/support pages: [UID:0000P7][WaitableTimer](../../../by-file/WaitableTimer.md), [UID:0000OU][TimerPane](../../../by-file/TimerPane.md), [UID:0001QU][client_timing](../../../by-meta/client_timing.md), [UID:00024G][0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators](../../../by-memory/0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators.md), [UID:0000VN][-ignored](../../../by-memory/-ignored.md), and proposed source tree notes.
- Generated coverage and current generated output: `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-type-coverage.md`, `auto-generated/-ag-global-coverage.md`, and `auto-generated/NexusTK/util/TimerMgr.cpp`.
- Historical lead only, not source authority: old `by-memory/-report.old.md` removal-helper entries and current support pages that supersede stale Wave2/Wave3 owner names.

IDA MCP was not available during this B014 pass. A connection attempt to `http://127.0.0.1:13337/mcp` failed with "Unable to connect to the remote server." Therefore, this report does not add new live IDA facts. It revalidates current IDA-backed documentation and generated coverage state.

## Exact Boundary Recheck

The aggregate boundary should remain the half-open executable coverage range `0x00597570-0x005986da`.

| Boundary | Reanalysis |
| --- | --- |
| Predecessor | [UID:0001K5] `ThreadManScalarDeletingDestructor` ends at `0x0059756e`; [UID:0000VN] records `0x0059756e-0x00597570` as two `0xcc` alignment bytes. Do not merge ThreadMan tail padding into TimerMgr. |
| Aggregate start | `0x00597570` is the modeled 9-byte `TimerHandler` constructor body that writes the `TimerHandler` vtable. This is the correct first source byte for the timer scheduler family. |
| Aggregate interior | The current child split is exact from `0x00597dc0` onward. Internal padding spans under [UID:0000VN] are `0x00597e3f-0x00597e40`, `0x00597e8a-0x00597e90`, `0x00597ea3-0x00597eb0`, `0x00597f17-0x00597f20`, `0x00597fc9-0x00597fd0`, `0x00597fdb-0x00597fe0`, `0x00598083-0x00598090`, `0x005980eb-0x005980f0`, `0x00598282-0x00598290`, and `0x00598472-0x00598480`. |
| Last child | [UID:0002L7] filename/title use the last executable byte convention `0x00598480-0x005986d9`, but the exact half-open function extent is `0x00598480-0x005986da`. The page already states this and records final in-function byte `0x005986d9`. No rename is required if the project keeps last-byte filenames for exact children. |
| Successor padding | [UID:0000VN] records `0x005986da-0x005986e0` as six `0xcc` alignment bytes. This proves the aggregate must stop at `0x005986da`, before [UID:0001KB][TimerPane] begins at `0x005986e0`. |
| Successor owner | [UID:0000OU][TimerPane](../../../by-file/TimerPane.md) and [UID:0001QU][client_timing](../../../by-meta/client_timing.md) confirm TimerPane is a map/session UI timer overlay, not part of the scheduler implementation. |

The current target table is mostly correct, but its mixed range style should be clarified during implementation: parent aggregates use half-open coverage ends; some exact child filenames display the last executable byte while their evidence text states the half-open function end.

## Ownership And Source Placement

The best-supported source module remains `NexusTK/util/TimerMgr.cpp`, owned by [UID:0000OT][TimerMgr](../../../by-file/TimerMgr.md).

| Entity | Best-supported placement | Rationale |
| --- | --- | --- |
| `TimerHandler` | Semantic class owner [UID:0000F0], source emitted through [UID:0000OT] | Constructor/destructor/wrappers are immediately before `TimerMgr`, use `g_pTimerMgr`, and have broad timer-owner caller fan-in. Keep as a small companion class in or beside `TimerMgr.cpp`; do not move to caller modules. |
| `TimerMgr` | Semantic class owner [UID:0000F1], source emitted through [UID:0000OT] | Owns singleton publication, static instance, multimedia timer period, current tick, dispatch, schedule, removal, and queue use. |
| `TimerMgrTimerQueue` | Semantic class owner [UID:0000F2], source emitted through [UID:0000OT] | Embedded scheduler-specific queue, not a reusable container. Owns slot array, start/count, capacity, queue destruction, grow, splice, insert, reverse, and rotate helpers. |
| `g_pTimerMgr` | Global owner [UID:0000SI], source declared in [UID:0000OT] | Exact storage [UID:0002VW] is `0x0067ab80-0x0067ab84`; constructor writes, clear/destructor paths null it, wrappers consume it. |
| static `TimerMgr` object | [UID:00029S], source declared in [UID:0000OT] | `0x0069b3ac-0x0069b3d0` is 36-byte process-lifetime storage initialized by startup `0x00419f90` and destroyed via the atexit wrapper at `0x0060c270`. |
| tick mirrors | [UID:000306], [UID:000307], source declared in [UID:0000OT] | `0x0069be0c` and `0x0069be10` are TimerMgr tick mirrors. The mixed Thread/Timer aggregate is not a single owner. |
| vtables | [UID:0003E0] and [UID:0003E1] | Source declarations should regenerate these. Target text should cite the exact data children, not just the `0x0062e338` vtable symbol address. |
| `WaitableTimer` | Separate [UID:0000P7], also `NexusTK/util/` | Lower-level Win32 event/multimedia timer primitive; no current evidence requires merging into `TimerMgr.cpp`. |
| `TimerPane` | Separate [UID:0000OU], `NexusTK/map/` | Timer callback consumer and UI overlay, not scheduler source. |

One support metadata inconsistency is worth correcting on implementation callback: [UID:0001K8][TimerHandlerScheduleRemoveWrappers] is semantically a `TimerHandler` method pair like [UID:0001K7] and [UID:0001K9]. It currently uses `CANONICAL_OWNER:0000OT` and `EMITTER_UIDS:0000OT`. Best-supported direct owner/emitter should be [UID:0000F0][TimerHandler], which still emits to `auto-generated/NexusTK/util/TimerMgr.cpp` through [UID:0000OT]. This is a support-doc metadata cleanup, not a change to source file placement.

For queue helper children already attached to [UID:0001KA] for memory nesting, keep the current metadata unless the supervisor chooses a broader ownership-normalization pass. Their text should continue to say semantic class owner [UID:0000F2] and source file [UID:0000OT].

## Layout, Record, Globals, And Callback Signature

### `TimerMgrLayout`

[UID:0001WD][TimerMgrLayout](../../../by-type/by-struct/TimerMgrLayout.md) is the best current object layout:

| Offset | Field role |
| --- | --- |
| `+0x00` | `LObject` / vtable base. |
| `+0x04` | embedded queue root/sentinel. |
| `+0x08` | `ScheduledTimerEvent **slotEntries`. |
| `+0x0c` | queue slot capacity. |
| `+0x10` | logical ring start index. |
| `+0x14` | queued event count. |
| `+0x18` | current tick, mirrored to `0x0069be10`. |
| `+0x1c` | multimedia timer period/resolution. |
| `+0x20` | next-due tick cache or `0xffffffff` empty sentinel. |

### `ScheduledTimerEvent`

[UID:0001VX][ScheduledTimerEvent](../../../by-type/by-struct/ScheduledTimerEvent.md) should be treated as the queue-owned record type:

| Offset | Field | Best-supported source-facing name |
| --- | --- | --- |
| `+0x00` | `TimerHandler *` | `owner` |
| `+0x04` | event id | `timerId` or `eventId`; prefer `timerId` in callback-facing text and `eventId` in queue text if local style requires distinction. |
| `+0x08` | absolute due tick | `dueTick` |
| `+0x0c` | callback payload 0 | `arg0` until a caller-family-specific semantic name is proven. |
| `+0x10` | callback payload 1 | `arg1` until a caller-family-specific semantic name is proven. |

Evidence is convergent: `ScheduleTimer` fills five dwords, dispatch copies 16 bytes plus the trailing dword, lookup compares owner/event and returns due tick, insert lazily allocates `0x14`, and splice copies `0x14`.

### Timer callback signature

Best-supported source-facing callback signature:

```cpp
virtual bool OnTimer(int timerId, int arg0, int arg1);
```

Use descriptive `arg0`/`arg1` names unless a concrete caller recovers semantics. The signature is supported by:

- the callback-shaped helper at `0x005975d0`, whose bytes return true and `retn 0x0c`;
- derived callback pages such as FittingRoom timer work using `bool <Owner>::OnTimer(int timerId, int, int)`;
- `ScheduledTimerEvent` storing two payload dwords after timer id and due tick;
- dispatch copying the whole record before invoking the owner callback through the `TimerHandler` virtual slot.

Important caveat: [UID:0000F0][TimerHandler](../../../by-class/TimerHandler.md) records the current `TimerHandler` vtable callback slot as `__purecall`, and says `0x005975d0` has no proven direct xrefs. Therefore, do not final-write `TimerHandler::OnTimer` as a non-pure default implementation solely because this helper returns true. The safe conclusion is: the callback signature is `bool(int,int,int)`, while `0x005975d0` remains a `TimerHandlerDefaultOnTimerCandidate` or `TimerHandlerReturnTrueCallbackShape` exact split candidate until vtable ownership is proven.

## Method And Helper Split State

Exact child pages already cover the `TimerHandler` destructor/wrapper island and the entire queue-helper tail after `0x00597dc0`. The remaining middle methods are the true source-quality gap.

| Range | Current status | Implementation recommendation |
| --- | --- | --- |
| `0x00597570-0x00597579` | Aggregate-only `TimerHandler` constructor. | Create exact child `TimerHandlerConstructor` if the aggregate is being pushed toward final audit. |
| `0x005975d0-0x005975d5` | Aggregate-only callback-shaped return-true helper. | Create exact child with caveat: callback-shaped, not proven live base vtable callback. |
| `0x00597650-0x005976b3` | Aggregate-only `TimerHandler` scalar deleting destructor. | Create exact child under [UID:0000F0]. It shares vtable store evidence with [UID:0003E0] and unregisters before optional delete. |
| `0x005976c0-0x00597780` | Aggregate-only `TimerMgr::TimerMgr`. | Create exact child under [UID:0000F1] or [UID:0001K6] memory nesting. Must include static object caller `0x00419f95`, singleton writes `0x00597702`/`0x00597709`, queue root allocation, vtable install, fields initialized, and EH cleanup to [UID:0002L2]. |
| `0x00597780-0x005977aa` | Aggregate-only static destructor body. | Create exact child for the static `TimerMgr` destructor body. It is reached through atexit wrapper `0x0060c270` but executes in the `0x00597780` body. Include `timeEndPeriod`, queue destructor, singleton clear, and base cleanup. |
| `0x005977b0-0x0059790a` | Aggregate-only `TimerMgr::DispatchDueTimers`. | Create exact child. Must cover due-loop, `dword_69BE10` refresh, event copy, call to splice at `0x0059789f`, virtual callback slot call, next-due cache update, and application-loop reachability. |
| `0x00597910-0x00597a0c` | Aggregate-only `TimerMgr::ScheduleTimer`. | Create exact child. Must cover record construction, due tick calculation, sorted insertion point scan, insert call at `0x005979c5`, and broad wrapper/direct caller fan-in. |
| `0x00597a10-0x00597db9` | Aggregate-only removal helper family. | Create child pages only after an IDA refresh confirms exact endpoints. Current evidence supports starts at `0x00597a10`, `0x00597b80`, and `0x00597ca0`; helper roles are owner-only removal, owner+event removal, and owner except event removal. Historical lead says `0x00597ca0` body extends to approximately `0x00597dac`, but this pass cannot assert final child ends without live IDA. |

Best-supported removal names:

- `0x00597a10`: `TimerMgr::RemovePendingTimersForOwner(TimerHandler *owner)`.
- `0x00597b80`: `TimerMgr::CancelTimer(TimerHandler *owner, int timerId)` or `RemovePendingTimerForOwnerAndEvent`.
- `0x00597ca0`: `TimerMgr::CancelPendingTimersExceptEvent(TimerHandler *owner, int keepEventId)`.

These names are supported by [UID:0001K8], [UID:0001K9], the splice helper caller sites `0x00597b05`, `0x00597c7f`, and `0x00597d9f`, the QuitInputPane direct manager-removal caller at `0x005add73`, and the wrapper predicates documented on 2026-06-16. They are descriptive best-supported names, not proven original spellings.

## Heuristic / Inference Reanalysis And Validation

1. `TimerHandler` ownership was rechecked against stale caller-biased alternatives. The destructor and wrappers are not `EventDispatcher`, `InterfaceEfx`, `FittingRoom`, `SoundManager`, browser, or audio code. Their bodies are tiny vtable or `g_pTimerMgr` forwarders, and their caller fan-in spans many timer owners. Best inference: semantic owner [UID:0000F0], source near or in `TimerMgr.cpp`.

2. The target's `TimerHandler` callback question can be narrowed. The callback signature is defensibly `bool OnTimer(int timerId, int arg0, int arg1)`. The exact base implementation remains uncertain because the vtable child records `__purecall` in the callback slot, while `0x005975d0` is only callback-shaped. Best inference: document the signature separately from the unproven default-helper ownership.

3. `TimerMgr` singleton/static ownership is resolved. `g_pTimerMgr` exact storage, static `TimerMgr` storage, constructor publication, destructor/static clear, and atexit wrapper all point to [UID:0000OT]. The adjacent dialog/background slots and ThreadMan tick-global neighbor are physical adjacency only.

4. `TimerMgrTimerQueue` is an embedded queue class, not a generic container. The queue helpers operate on a fixed `ScheduledTimerEvent` record, use `TimerMgrLayout` queue fields, and are only reached from scheduler insert/remove/dispatch paths. Best inference: keep class owner [UID:0000F2], source file [UID:0000OT], and avoid moving helpers to generic `List`, `Queue`, STL, or caller modules.

5. The queue record/type names are sufficiently supported for documentation. `owner`, `eventId/timerId`, `dueTick`, `arg0`, and `arg1` match every documented queue path. Keep payload names descriptive until individual caller families recover semantics.

6. The aggregate boundary is exact despite the child filename/end convention mismatch. The parent is half-open `0x00597570-0x005986da`; [UID:0002L7] last executable byte is `0x005986d9`; padding starts at `0x005986da`; TimerPane starts at `0x005986e0`.

7. Source split decision: keep `TimerHandler`, `TimerMgr`, and `TimerMgrTimerQueue` in one `util/TimerMgr.cpp` reconstruction module for now. If later source evidence proves a tiny `TimerHandler.cpp`, that would only move class method definitions, not change scheduler ownership or queue/global placement.

8. Open child-split decision: do not create a monolithic source body on [UID:0001K6] to compensate for missing child pages. The right action is exact child splits for constructor, static destructor, dispatch, schedule, and removal helpers.

9. Generated-output validation: `auto-generated/NexusTK/util/TimerMgr.cpp` currently contains only empty emitter markers for this family. That output confirms emitter routing but not source completeness. It also means first-draft code insertion should be deliberate and exact, not aggregate-level.

10. Score impact: the ownership/type/global/helper questions are mostly resolved or narrowed, but missing exact child pages for the middle function band materially cap completion and confidence. Keeping `85/87` is more honest than raising the aggregate.

## Rejected Alternatives

- Reject assigning any part of this scheduler cluster to `EventDispatcher.cpp`: [UID:0001K7] only appears as a caller/consumer through timer-owning cleanup paths, while the destructor body writes `TimerHandler::vftable` and unregisters through `g_pTimerMgr`.
- Reject assigning `0x00597600` to `InterfaceEfx`: [UID:0001K8] proves a generic remove-all wrapper.
- Reject assigning `0x00597610`/`0x00597630` to `SoundManager`: [UID:0001K9] proves generic `TimerHandler` cancel wrappers, with SoundManager and LivingObjectPane as consumers.
- Reject assigning queue helpers to caller modules such as `MapPane`, `LivingObjectPane`, `QuitInputPane`, UI panes, or audio code. Those callers schedule or cancel timers, but the queue mutation and ownership are centralized in `TimerMgr`.
- Reject merging [UID:0000P7][WaitableTimer] into this aggregate. It is a lower-level Win32 event/multimedia timer utility with separate function island and source page.
- Reject merging [UID:0000OU][TimerPane] into this aggregate. It starts after confirmed padding and is a map/session UI overlay.
- Reject a generic reusable container owner for `TimerMgrTimerQueue`: record size, due-tick sorting, timer owner/event predicates, and source tree context are scheduler-specific.
- Reject final monolithic aggregate C++ for [UID:0001K6]: it would duplicate child-page responsibilities and hide unresolved exact splits.

## Open-Question Closure

| Target open question | Closure status |
| --- | --- |
| Split remaining aggregate rows. | Not closed by documentation edits in this report-only pass. Best-supported action is exact child pages for `0x00597570`, `0x005975d0`, `0x00597650`, `0x005976c0`, `0x00597780`, `0x005977b0`, `0x00597910`, and removal starts `0x00597a10`/`0x00597b80`/`0x00597ca0` after live boundary confirmation. |
| Resolve final source spellings for queue methods. | Mostly narrowed. Current descriptive names are acceptable documentation names: `FindQueuedTimerDueTick`, `BeginTimerPeriod`, `RefreshCurrentTick`, `ReverseRange`, `RotateRange`, `EnsureCapacity`, `SpliceTimerRange`, `InsertTimer`. Original spelling is still not proven, so keep confidence below final audit. |
| Resolve exact `TimerHandler` callback signature. | Closed enough for source-quality docs: `bool OnTimer(int timerId, int arg0, int arg1)`. Not closed enough to claim `0x005975d0` is the live base vtable implementation because the vtable slot is currently documented as `__purecall`. |
| C++ readiness. | Closed with aggregate no-code proof. The active gate is met, but aggregate C++ is unsafe because this page is a containing source-family range, not one exact function or declaration. |
| Owner/source placement. | Closed for this pass: source root [UID:0000OT] `NexusTK/util/TimerMgr.cpp`; semantic classes [UID:0000F0], [UID:0000F1], [UID:0000F2]; separate `TimerPane` and `WaitableTimer`. |
| Boundary/range decisions. | Closed for parent and current exact children. Only removal-helper sub-splits still need live IDA endpoint confirmation before new child pages are created. |

## First-Draft C++ Eligibility And Aggregate No-Code Proof

Active gate check for [UID:0001K6]:

- `RECONSTRUCTABLE:TRUE`: yes.
- `EMITTER_UIDS:0000OT`: nonblank and reaches `auto-generated/NexusTK/util/TimerMgr.cpp`.
- `(COMPLETION + CONFIDENCE) / 2 = (85 + 87) / 2 = 86`: above active `>85` minimum.

Despite gate eligibility, do not put first-draft C++ in [UID:0001K6].

Exact no-code proof:

1. [UID:0001K6] is a source-family aggregate over multiple independent functions, helper children, vtable/static data implications, and padding. It is not a single compilable function or declaration.
2. Exact child pages already own many source-bearing functions. Aggregate C++ would duplicate or conflict with child C++ once those pages are populated.
3. Middle methods remain unsplit: constructor, static destructor body, dispatch, schedule, and removal helpers are still aggregate rows. Aggregate C++ would necessarily extend across unsplit functions with partially provisional signatures.
4. The target itself says child functions/queue helpers are source-bearing units and vtables/static storage should be regenerated from declarations/globals. That source policy supports blank aggregate C++.
5. Current generated `TimerMgr.cpp` shows [UID:0001K6] and its children as empty emitter markers. This proves routing, not readiness for a monolithic body.

Implementation should replace stale target wording that says "keep final C++ blank until 95/95" with the active-gate-aware reason: this target is eligible by score/route but intentionally blank because it is an aggregate/container page. If the supervisor wants a tracker-visible no-code marker under Rule 28, use only a minimal marker/comment after policy confirmation, not method bodies.

## Proposed Metadata And Score

Target [UID:0001K6]:

```text
COMPLETION:85
CONFIDENCE:87
CANONICAL_OWNER:0000OT
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000OT
RECONSTRUCTION_CPP: keep blank; add aggregate no-code proof text in the page body
```

Rationale for no score raise: this report resolves or narrows most owner/type/callback/source-placement issues, but the target still lacks exact child pages for the middle method band. A raise before those child splits would overstate completion. The current coverage row is stale at `84%`; update only the supervisor-owned coverage text to match the already-current target metadata and source-quality reanalysis.

Support metadata recommendation:

```text
[UID:0001K8] 0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers
CANONICAL_OWNER:0000F0
EMITTER_UIDS:0000F0
```

This aligns [UID:0001K8] with [UID:0001K7] and [UID:0001K9]. Its generated output still lands in `auto-generated/NexusTK/util/TimerMgr.cpp` through the `TimerHandler` class source route.

## Exact Support-Doc Checklist

If accepted, the implementation callback should include the following exact scope.

1. Target [UID:0001K6] [0x00597570-0x005986da.TimerMgrAndTimerQueue](../../../by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
   - Preserve metadata `85/87`, owner [UID:0000OT], reconstructable true, emitter [UID:0000OT].
   - Add a source-quality reanalysis/change note from this B014 report.
   - Replace stale final-C++ gate wording with the aggregate no-code proof under the active score/emitter gate.
   - Clarify callback signature as `bool OnTimer(int timerId, int arg0, int arg1)` while preserving the caveat that `0x005975d0` is callback-shaped and not proven as the live base vtable implementation.
   - Add exact vtable data links [UID:0003E0] and [UID:0003E1]; avoid saying only "vtable island `0x0062e338`" when the exact child is `0x0062e334-0x0062e340`.
   - Clarify boundary convention: aggregate half-open `0x00597570-0x005986da`; [UID:0002L7] final byte `0x005986d9`; padding `0x005986da-0x005986e0`; TimerPane starts `0x005986e0`.
   - Add the remaining exact child-split checklist for constructor/default helper/scalar deleting destructor/TimerMgr ctor/static destructor/dispatch/schedule/removal helper starts.

2. Support [UID:0001K8] [0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](../../../by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md)
   - Change direct semantic owner/emitter to [UID:0000F0] if accepted by supervisor.
   - Preserve source module text as [UID:0000OT] `TimerMgr.cpp`.
   - Add a small note explaining the metadata alignment with [UID:0001K7] and [UID:0001K9].

3. Support [UID:0000F0][TimerHandler](../../../by-class/TimerHandler.md)
   - No required score change.
   - Ensure target-incorporated text preserves the existing caveat: the vtable callback slot is `__purecall`; `0x005975d0` is callback-shaped and no-xref, so final base implementation remains unproven.

4. Support [UID:0000F1][TimerMgr](../../../by-class/TimerMgr.md), [UID:0000F2][TimerMgrTimerQueue](../../../by-class/TimerMgrTimerQueue.md), [UID:0001WD][TimerMgrLayout](../../../by-type/by-struct/TimerMgrLayout.md), and [UID:0001VX][ScheduledTimerEvent](../../../by-type/by-struct/ScheduledTimerEvent.md)
   - No required metadata changes.
   - Cross-check that field/record names in the target match current type pages: queue at `+0x04`, current tick `+0x18`, timer period `+0x1c`, next due `+0x20`; event record `owner/eventId/dueTick/arg0/arg1`.

5. Support [UID:0001KA] and children [UID:0002KX] through [UID:0002L7]
   - No required metadata changes from this report.
   - Do not rename [UID:0002L7] solely because the function half-open end is `0x005986da`; its page already explains the `0x005986d9` final-byte display convention.
   - If supervisor elects a broader coverage refresh, bring stale coverage rows for these children up to their current by-page metadata and assignment text. This report's mandatory exact coverage row below is only for [UID:0001K6].

6. Validation expected after implementation
   - Run `python E:\NTK\GhidraBridge\source-3\project-documentation\tools\validator.py --mode file --file E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00597570-0x005986da.TimerMgrAndTimerQueue.md`.
   - If [UID:0001K8] support metadata is changed, also run the same scoped validator command for `0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md`.
   - Report exit code and `ok` count. Do not edit `by-memory/-coverage-report.md`.

## Supervisor-Owned Coverage Row

Current exact supervisor-owned coverage row text:

```text
    - [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md) 0x00597570-0x005986da | aggregate | TimerMgrAndTimerQueue : reconstructable : 84% : strong : Source-authored Timer scheduler aggregate attached to TimerMgr, with TimerHandler wrappers, TimerMgr lifecycle/dispatch/schedule/remove spans, exact queue-helper children, singleton/static storage links, timer tick/layout records, TimerPane/WaitableTimer boundary caveats, and blank-C++ gate documented.
```

Proposed exact replacement row text for supervisor-owned coverage update:

```text
    - [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md) 0x00597570-0x005986da | aggregate | TimerMgrAndTimerQueue : reconstructable : 85% : strong : B014 source-quality reanalysis preserves TimerMgr.cpp ownership and the exact half-open aggregate boundary, resolves TimerHandler/TimerMgr/TimerMgrTimerQueue routing, documents singleton/static/tick/vtable anchors, ScheduledTimerEvent/TimerMgrLayout field evidence, queue-helper child ownership, callback signature best inference, TimerPane/ThreadMan/WaitableTimer boundaries, remaining middle-method child splits, and aggregate no-code proof under the active C++ gate.
```

Do not let B014 apply this row directly while the shared coverage-report ban is active.

## Scoped Validator Baseline

Command run in report-only mode:

> Executable block R001 was removed from this report and preserved verbatim in [0001K6-TimerMgrAndTimerQueue-source-quality-removed.md](0001K6-TimerMgrAndTimerQueue-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result: exit code `0`, one scanned markdown file, one UID-header ok result:

```text
ok 0001K6 by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md UID header exists
```

The validator run was dry-run/report-only. It did not apply changes. It also produced generated-output no-op lines for `auto-generated/NexusTK/util/TimerMgr.cpp`, which is consistent with the current empty-emitter-marker state.

## Files Touched By This Report Pass

Created:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B014\research\0001K6-TimerMgrAndTimerQueue-source-quality.md
```

Not edited:

```text
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00597570-0x005986da.TimerMgrAndTimerQueue.md
E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\-coverage-report.md
```

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0001K6-TimerMgrAndTimerQueue-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:36","uid":"0001K6"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001K6-TimerMgrAndTimerQueue-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0001K6-TimerMgrAndTimerQueue-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001K6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
