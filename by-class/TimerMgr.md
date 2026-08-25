*** UID:0000F1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "TimerMgr.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UTIL_TIMERMGR_H
#define NEXUSTK_UTIL_TIMERMGR_H

#include <windows.h>
#include <deque>
#include "LObject.h"
#include "TimerHandler.h"

struct ScheduledTimerEvent
{
    TimerHandler *owner;
    int timerId;
    DWORD dueTick;
    int arg0;
    int arg1;
};

class TimerMgr : public LObject
{
public:
    TimerMgr();
    virtual ~TimerMgr();

    void DispatchDueTimers();
    void ScheduleTimer(TimerHandler *owner, int timerId,
                       unsigned int delayMs, int arg0, int arg1);
    void RemovePendingTimersForOwner(TimerHandler *owner);
    void CancelTimer(TimerHandler *owner, int timerId);
    void CancelPendingTimersExceptEvent(TimerHandler *owner, int timerId);
    DWORD FindQueuedTimerDueTick(TimerHandler *owner, int timerId) const;
    void BeginTimerPeriod();
    void RefreshCurrentTick();

private:
    std::deque<ScheduledTimerEvent> m_timerQueue;

public:
    DWORD m_currentTick;

private:
    UINT m_timerPeriod;
    DWORD m_nextDueTick;
};

extern TimerMgr *g_pTimerMgr;

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TimerMgr

## UID0000IF Direct-Header Guard And Child Closure - 2026-08-24

- UID0000F1 owns the complete `NexusTK/util/TimerMgr.h` declaration union directly. The formal H now opens sole guard `NEXUSTK_UTIL_TIMERMGR_H` before the existing includes and closes it after `extern TimerMgr *g_pTimerMgr;`.
- The terminal H `[[CHILDREN]]` placeholder is removed because no TimerMgr H-emitting child exists. Formal CPP remains exactly the self-header include plus namespace-scope `[[CHILDREN]]`, so existing method definitions retain their established owner/emitter routes.
- Include/declaration order remains `<windows.h>`, `<deque>`, `LObject.h`, `TimerHandler.h`, `ScheduledTimerEvent`, `TimerMgr`, public `DWORD m_currentTick`, private tail fields, and extern. No API, layout, type, visibility, source body, owner/emitter, or score changes.
- A child-invented guard, duplicate declaration union, PCH-only dependency, folded TimerHandler declaration, CPP-local public type, or replacement custom queue remains rejected. Generated proof requires one guard pair, zero placeholders, every declaration once in preserved order, and unchanged public `m_currentTick` placement.

## UID0000IF Current-Tick Access Closure - 2026-08-22

- `m_currentTick` remains the existing `DWORD` field at exact offset `+0x18`, between `m_timerQueue` and `m_timerPeriod`; only its access section changes to public.
- [UID:000113][0x00494520-0x004949df.ConnStatusPane](by-memory/0x00494520-0x004949df.ConnStatusPane.md) directly reads `g_pTimerMgr->m_currentTick` in `CaptureLatencyStartTick` and `UpdateConnectionFrame`, matching other direct generated consumers.
- Field order, type, layout, class size, methods, formal CPP, owner/emitter route, and metadata `93/95` are unchanged.

## 2026-07-19 UID0002KX Standard-Deque Header Union

- `TimerMgr` remains the scheduler class owned and emitted by [UID:0000OT][TimerMgr](by-file/TimerMgr.md). Its source declaration belongs in `NexusTK/util/TimerMgr.h`, and method definitions remain in `NexusTK/util/TimerMgr.cpp`.
- The complete managed block now declares `ScheduledTimerEvent` once, closes `TimerMgr`, emits the extern, and closes the sole direct guard without an H child placeholder. It preserves the constructor, virtual ordinary destructor, dispatch, schedule, owner-removal, targeted cancellation, cancel-except, timer-period, tick-refresh, singleton/tick, and TimerHandler-facing method union.
- The embedded source member is `std::deque<ScheduledTimerEvent> m_timerQueue`; the five-word object at class offset `+0x04` is its Dinkumware implementation layout. The compiler map/proxy/front/size fields do not justify a project `TimerMgrTimerQueue` member type or source API.
- `FindQueuedTimerDueTick` is a public, nonvirtual, const member because unrelated MapPane code calls it directly, it has no vtable slot or pointer route, and it performs no receiver writes. It searches deque values newest-to-oldest and returns an absolute `DWORD` due tick or zero.
- The 20-byte `ScheduledTimerEvent` declaration preserves owner, full-width timer id, absolute due tick, and two generic callback arguments. Active records are values rather than nullable heap pointers.
- Historical custom-queue prose and helper names remain useful descriptions of lowered compiler behavior only. `TimerMgrTimerQueue`, pointer slots, allocation/free helpers, map/proxy source fields, and handwritten reverse/rotate/grow/erase/insert APIs are rejected as original project declarations.

## Status

- Likely original source: [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- Proposed header: `util/TimerMgr.h`
- Confidence: strong for class behavior and source grouping with `TimerMgrTimerQueue`.
- Parent gate: direct source parent [UID:0000OT][TimerMgr](by-file/TimerMgr.md) is `92/90`; this class clears `89/90` and is the direct parent for [UID:0001WD][TimerMgrLayout](by-type/by-struct/TimerMgrLayout.md).

## UID000090 Header And Source Split Closure - 2026-07-31

- The complete guarded `ScheduledTimerEvent` and `TimerMgr` declaration union now lives in the formal H block without an H child placeholder. The CPP formal is exactly a self-header include plus namespace-scope `[[CHILDREN]]`; declarations are no longer emitted as CPP-local types.
- `TimerMgr.h` explicitly includes Windows scalar types, VC6-era `std::deque`, complete `LObject.h`, and separate `TimerHandler.h`. It owns `g_pTimerMgr` and keeps `std::deque<ScheduledTimerEvent>` as the source member rather than exposing lowered five-word implementation storage.
- Exact scheduler methods, owner/id/payload fields, tick fields, container semantics, and child body ownership remain unchanged. The split is source-structure closure, not a binary range or behavior change.
- A folded TimerHandler-only declaration, PCH-only bases, CPP-local public types, and a project `TimerMgrTimerQueue` API are rejected and retained only as historical decompiler alternatives.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `89` | The class page maps the scheduler lifecycle, exact dispatch/schedule/removal children, queue helper tail, singleton/static storage, tick mirrors, layout/type docs, direct layout ownership, and settled TimerHandler base callback contract. B009 adds the formal class marker plus `[[CHILDREN]]` and corrects stale child path pollution. It remains below final-audit level because several large exact TimerMgr method children still keep their own formal C++ blank pending method-level source audits. |
| Confidence | `90` | Batch 141 live IDA MCP, B002/B004 evidence, and B009 restored-session review agree on the method-boundary cluster, static instance xrefs, tick mirror xrefs, queue-helper caller/callee sets, current helper names, and file route through TimerMgr.cpp. Confidence remains below final source because exact original public helper spelling and destructor/member-destruction source order are still stripped-binary inference, but queue helper declaration shape is no longer a class-level blocker. |

## Responsibility

`TimerMgr` is the process-wide scheduler for timer callbacks. It owns the singleton pointer, initializes multimedia timer resolution, tracks current tick values from `timeGetTime`, stores pending [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md) records in an embedded [UID:0000F2][TimerMgrScheduledEventDequeCompilerSupport](by-class/TimerMgrScheduledEventDequeCompilerSupport.md), dispatches due callbacks, and removes pending timers for destroyed or cancelled owners.

## Method Families

| Range | Documented/proposed name | Role |
| --- | --- | --- |
| `0x005976c0-0x00597780` | `TimerMgrConstructor` (`by-memory/0x005976c0-0x00597780.TimerMgrConstructor.md`) | Initializes `LObject`, singleton pointer, embedded queue root/sentinel state, vtable, zeroed queue fields, and next-due cache. |
| `0x00597780-0x005977ac` | `TimerMgrStaticDestructorBody` (`by-memory/0x00597780-0x005977ac.TimerMgrStaticDestructorBody.md`) | Corrected destructor/static destructor body: ends multimedia timer period, destroys the embedded queue, clears singleton, and jumps to `LObject` cleanup before padding at `0x005977ac`. |
| `0x005977b0-0x0059790a` | `TimerMgrDispatchDueTimers` (`by-memory/0x005977b0-0x0059790a.TimerMgrDispatchDueTimers.md`) | Pulls due entries in order, erases the dispatched range through the queue helper, updates next-due cache, and dispatches owner callback slot `+4`. |
| `0x00597910-0x00597a0c` | `TimerMgrScheduleTimer` (`by-memory/0x00597910-0x00597a0c.TimerMgrScheduleTimer.md`) | Builds a five-dword scheduled-event record, computes due tick from current tick plus delay, scans sorted insertion position, inserts into the queue, and refreshes next-due cache. |
| `0x00597a10-0x00597b73` | `TimerMgrRemovePendingTimersForOwner` (`by-memory/0x00597a10-0x00597b73.TimerMgrRemovePendingTimersForOwner.md`) | Owner-only removal predicate; removes every event whose owner matches and then refreshes next-due cache or sets it to `0xffffffff`. |
| `0x00597b80-0x00597c99` | `TimerMgrCancelTimer` (`by-memory/0x00597b80-0x00597c99.TimerMgrCancelTimer.md`) | Owner plus matching event/timer id predicate; called by the `TimerHandler` targeted cancel wrapper. |
| `0x00597ca0-0x00597db9` | `TimerMgrCancelPendingTimersExceptEvent` (`by-memory/0x00597ca0-0x00597db9.TimerMgrCancelPendingTimersExceptEvent.md`) | Owner plus nonmatching event/timer id predicate; preserves the supplied event id and removes the rest for that owner. |
| `0x00597dc0-0x00597e3f` | [UID:0002KX][0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick](by-memory/0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick.md) | Looks up an owner/event pair and returns the queued due tick. |
| `0x00597e40-0x00597ea3` | [UID:0002KY][0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod](by-memory/0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod.md), [UID:0002KZ][0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick](by-memory/0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md) | Private `TimerMgr` timer-period setup and tick-refresh methods. |
| `0x00598090-0x005980eb` | [UID:0002L4][0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor](by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md) | Compiler-generated scalar deleting destructor wrapper over `TimerMgr` destructor semantics; vtable-only route through `0x0062e344`. |
| `0x00598290-0x005986d9` | [UID:0002L6][0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange](by-memory/0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange.md), [UID:0002L7][0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer](by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md) | Queue-owned `TimerMgrTimerQueue` erase/insert methods used by TimerMgr schedule/dispatch/remove paths, not direct TimerMgr methods. |

## Layout Notes

Current layout documentation describes a `0x24` byte class: `LObject` base/vtable at `+0x00`, embedded [UID:0000F2][TimerMgrScheduledEventDequeCompilerSupport](by-class/TimerMgrScheduledEventDequeCompilerSupport.md) state at `+0x04` through `+0x14`, current tick at `+0x18`, timer period at `+0x1c`, and next-due cache at `+0x20`. See [UID:0001WD][TimerMgrLayout](by-type/by-struct/TimerMgrLayout.md) for the current field table and remaining source-name caveats.

## Globals

- [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md) at `0x0067ab80`: broad singleton pointer used by timer owners.
- Static `TimerMgr` instance at `0x0069b3ac`: constructed by startup code at `0x00419f90` and destroyed by the static destructor path.
- `dword_69BE0C` and `dword_69BE10`: tick mirror globals written during timer initialization/refresh.
- 2026-06-08 live IDA MCP confirmed `0x0069b3ac` has data xrefs from startup construction at `0x00419f90` and destructor wrapper `0x0060c270`, [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md) has 125 xrefs across 81 functions, and tick mirrors `0x0069be0c`/`0x0069be10` are written/read by the documented timer-period, refresh, and dispatch paths.

## B015 Queue Helper Normalization

The B015 TimerMgrQueueHelpers source-quality report normalizes the tail range [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md) as non-emitting context. Direct source ownership now lands on exact child pages:

- [UID:0002KX][0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick](by-memory/0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick.md), [UID:0002KY][0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod](by-memory/0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod.md), and [UID:0002KZ][0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick](by-memory/0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md) are private `TimerMgr` methods and emit through this class.
- [UID:0002L4][0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor](by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md) is a compiler-generated scalar deleting destructor wrapper attached to `TimerMgr`. It documents destructor semantics, vtable-only reachability through [UID:0003E1][0x0062e344-0x0062e354.TimerMgrVtableData](by-memory/0x0062e344-0x0062e354.TimerMgrVtableData.md), and should not be treated as a handwritten helper body.
- [UID:0002L2][0x00597fd0-0x00597fdb.ClearGlobalTimerMgr](by-memory/0x00597fd0-0x00597fdb.ClearGlobalTimerMgr.md) is constructor-unwind singleton cleanup, not a normal `TimerMgr` method.
- `m_timerPeriod` is preferred over `timerResolution` for `+0x1c` in TimerMgr prose because the value is passed to `timeBeginPeriod`/`timeEndPeriod`. `m_currentTick` at `+0x18` and `m_nextDueTick` at `+0x20` remain the source-facing names.
- `dword_69BE0C` and `dword_69BE10` remain descriptive inferred tick mirrors. Use `g_timerTickBaselineMirror` and `g_timerCurrentTickMirror` where a draft name is needed; do not claim exact original spellings.

## B002 Middle Method Split

B002 implementation created exact by-memory children for the middle `TimerMgr` bodies that were previously only aggregate rows under [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md). The class owner/emitter route is now direct for current TimerMgr children `by-memory/0x005976c0-0x00597780.TimerMgrConstructor.md`, `by-memory/0x00597780-0x005977ac.TimerMgrStaticDestructorBody.md`, `by-memory/0x005977b0-0x0059790a.TimerMgrDispatchDueTimers.md`, `by-memory/0x00597910-0x00597a0c.TimerMgrScheduleTimer.md`, `by-memory/0x00597a10-0x00597b73.TimerMgrRemovePendingTimersForOwner.md`, `by-memory/0x00597b80-0x00597c99.TimerMgrCancelTimer.md`, and `by-memory/0x00597ca0-0x00597db9.TimerMgrCancelPendingTimersExceptEvent.md`. Older UID00041A-UID00041G NewHumanImageLib/VectorGrow display names are stale UID-collision annotations. The [UID:0000OT][TimerMgr](by-file/TimerMgr.md) source root remains the final generated file route.

Important B002 corrections and evidence:

- Static destructor endpoint is `0x00597780-0x005977ac`, not the stale `0x00597780-0x005977aa`; B002 MCP session `b880584f` `disasm`/`get_bytes` shows the final `jmp sub_4F4A90` at `0x005977a7` and padding beginning at `0x005977ac`. `lookup_funcs 0x00597780` still resolves to wrapper `sub_60C270`, so the page must preserve the IDA model oddity instead of treating the wrapper address as the destructor body.
- Removal helper family is split exactly as `0x00597a10-0x00597b73`, `0x00597b80-0x00597c99`, and `0x00597ca0-0x00597db9`, with padding at `0x00597b73-0x00597b80`, `0x00597c99-0x00597ca0`, and `0x00597db9-0x00597dc0`.
- Predicate summary: `by-memory/0x00597a10-0x00597b73.TimerMgrRemovePendingTimersForOwner.md` removes all events for an owner and refreshes next-due cache; `by-memory/0x00597b80-0x00597c99.TimerMgrCancelTimer.md` removes events for an owner whose event/timer id matches the supplied id; `by-memory/0x00597ca0-0x00597db9.TimerMgrCancelPendingTimersExceptEvent.md` removes events for an owner whose event/timer id differs from the supplied id, preserving the supplied event.
- MCP `xrefs_to` in session `b880584f` confirms 48, 20, 3, and 2 incoming references for schedule/remove/cancel/cancel-except helpers respectively, and MCP decompilation confirms the owner-only, owner+matching-event, and owner+nonmatching-event predicates. These caller sets support generic `TimerMgr` ownership rather than feature-consumer ownership.
- Formal C++ is intentionally blank on these new `TimerMgr` child pages during this pass. The pages document exact behavior and routing, but final output needs the queue iterator/API and destructor/member order settled before source-quality method bodies are safe.

## B004 Current-Session Recheck

- B004 current MCP session `ff68e691` revalidated the class-level method map without raising the score. The session used `E:\NTK\Resources\NexusTK\NexusTK.exe.i64` and stable executable SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`; aggregate [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md) remains `0x116a` bytes with SHA-256 `c0a6bd2c92aa4f8c9317f340af5b397ab8508ff7f88ef8579943794b21363fcf`.
- Current-session inventory keeps `0x005976c0` constructor size `0xc0`, `0x00597780` static destructor body at `0x00597780-0x005977ac` despite `lookup_funcs` resolving through `sub_60C270`, `0x005977b0` dispatch size `0x15a`, `0x00597910` schedule size `0xfc`, removal helper sizes `0x163`, `0x119`, and `0x119`, query/tick helper sizes `0x7f`, `0x4a`, and `0x13`, scalar deleting destructor size `0x5b`, and queue helper sizes `0xa3`, `0x192`, `0x1e2`, and `0x25a`.
- B004 xrefs preserve the TimerMgr owner route and source-shape blockers: startup calls `0x005976c0` from `0x00419f95`, static destruction routes through `0x0060c270/0x0060c275`, dispatch is called by the application/message-loop path at `0x004a6c6a`, schedule/remove/cancel/cancel-except have 48/20/3/2 incoming refs, queue erase `0x00598290` is reached from dispatch/removal sites, [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md) has 125 xrefs, static storage `0x0069b3ac` is referenced from startup/destruction, and vtable/global data include `0x0062e344 -> 0x00598090`.
- The [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md) current-session recheck keeps the manager relationship narrow: the schedule wrapper calls `by-memory/0x00597910-0x00597a0c.TimerMgrScheduleTimer.md`, and the remove wrapper calls `by-memory/0x00597a10-0x00597b73.TimerMgrRemovePendingTimersForOwner.md`. The wrappers themselves remain [UID:0000F0][TimerHandler](by-class/TimerHandler.md) owner-facing methods with first-draft `void` C++; the manager bodies remain here as TimerMgr methods. Current B004 data-xref and VA/RVA/raw-offset pointer checks found no table/vtable route to the wrapper entries, so broad feature callers remain consumers rather than TimerMgr ownership evidence for the wrappers.
- The current child `by-memory/0x005975d0-0x005975d5.TimerHandlerOnTimerPureVirtualBody.md` removes the earlier callback-contract caveat for this class. The base `TimerHandler` callback slot remains `__purecall`, and that is consistent with an out-of-line pure-virtual body; this TimerMgr page should not cite older [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md) NewHumanImageLib display text as a manager C++ blocker.
- B009 implementation adds this class-level `[[CHILDREN]]` route marker and the scalar-deleting-destructor marker for `0002L4`. Exact middle TimerMgr method children remain independently documented; class-level C++ is intentionally not promoted into a partial declaration until final declaration/source split evidence exists.

## Open Questions

- Exact original spellings for the private TimerMgr query/tick, dispatch, schedule, and removal method names remain unproven, but `FindQueuedTimerDueTick`, `BeginTimerPeriod`, `RefreshCurrentTick`, `DispatchDueTimers`, `ScheduleTimer`, `RemovePendingTimersForOwner`, `CancelTimer`, and `CancelPendingTimersExceptEvent` are now source-quality supported draft/documentation names.
- Exact original spellings for queue helper names remain with [UID:0000F2][TimerMgrScheduledEventDequeCompilerSupport](by-class/TimerMgrScheduledEventDequeCompilerSupport.md), not this class.
- Whether `TimerHandler` was a separate `TimerHandler.cpp` or a tiny companion class in `TimerMgr.cpp`.
- The timer callback ABI is best modeled as a bool-returning `OnTimer` callback with `timerId`, `arg0`, and `arg1` payloads. `by-memory/0x005975d0-0x005975d5.TimerHandlerOnTimerPureVirtualBody.md` now settles the base out-of-line body while the `TimerHandler` vtable slot remains pure virtual.

## Cross-References

- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- `by-memory/0x005976c0-0x00597780.TimerMgrConstructor.md`
- `by-memory/0x00597780-0x005977ac.TimerMgrStaticDestructorBody.md`
- `by-memory/0x005977b0-0x0059790a.TimerMgrDispatchDueTimers.md`
- `by-memory/0x00597910-0x00597a0c.TimerMgrScheduleTimer.md`
- `by-memory/0x00597a10-0x00597b73.TimerMgrRemovePendingTimersForOwner.md`
- `by-memory/0x00597b80-0x00597c99.TimerMgrCancelTimer.md`
- `by-memory/0x00597ca0-0x00597db9.TimerMgrCancelPendingTimersExceptEvent.md`
- [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md)
- [UID:0002KX][0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick](by-memory/0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick.md)
- [UID:0002KY][0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod](by-memory/0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod.md)
- [UID:0002KZ][0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick](by-memory/0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md)
- [UID:0002L6][0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange](by-memory/0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange.md)
- [UID:0002L7][0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer](by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md)
- [UID:00024G][0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators](by-memory/0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators.md)
- [UID:0000F2][TimerMgrScheduledEventDequeCompilerSupport](by-class/TimerMgrScheduledEventDequeCompilerSupport.md)
- [UID:0000F0][TimerHandler](by-class/TimerHandler.md)
- [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md)
- [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md)

## Changes

- 2026-08-24 B003 UID0000IF C139 support callback: added the sole direct TimerMgr H guard, removed the no-child H placeholder, and preserved formal CPP, exact declaration/include order, public `m_currentTick`, private tail fields, layout/API, owner/emitter, scores, and all unrelated history.

- 2026-08-22 B003 UID0000IF support callback: moved only existing `DWORD m_currentTick` to public visibility in formal H, preserving its `+0x18` order/layout and every unrelated declaration; documented the direct ConnStatusPane consumer requirement.

- 2026-06-30 B009 implementation callback for `0000OT`:
  - Score/metadata changed to `89/90`, owner/emitter remains [UID:0000OT][TimerMgr](by-file/TimerMgr.md), and class-level C++ is the accepted marker with `[[CHILDREN]]`.
  - Summary/evidence: added the accepted class route marker, raised score rationale, normalized active child references to current TimerMgr paths, historicalized UID00041A-UID00041G NewHumanImageLib/VectorGrow display names as stale UID-collision annotations, and kept exact method bodies on their own pages instead of promoting a partial class declaration here.
- 2026-06-23 B002 implementation callback for [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md):
  - Score/metadata unchanged at `87/86`, owner/emitter [UID:0000OT][TimerMgr](by-file/TimerMgr.md), reconstructable true, and blank class C++.
  - Summary/evidence: synchronized callback-contract wording only. [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md) is now settled as the TimerHandler pure-virtual out-of-line body; this removes the old callback-body caveat from TimerMgr class documentation but does not change TimerMgr method scores or class-level C++ blockers.
- 2026-06-23 B004 implementation callback for `0001K8`:
  - Score/metadata unchanged at `87/86`, owner/emitter [UID:0000OT][TimerMgr](by-file/TimerMgr.md), reconstructable true, and blank class C++.
  - Summary/evidence: synchronized manager-side support for [UID:0001K8][0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers](by-memory/0x005975e0-0x0059760d.TimerHandlerScheduleRemoveWrappers.md), confirming the exact wrapper-to-manager call routes to [UID:00041D][0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable](by-memory/0x004e1800-0x004e19c5.NewHumanImageLibLoadAcc2DrwTable.md) `0x00597910` and [UID:00041E][0x004e4f10-0x004e50a0.VectorGrowAcc2Drw](by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md) `0x00597a10`, preserving the wrappers as TimerHandler owner-facing methods, preserving the TimerMgr helper pages' blank C++ blockers, and recording the no table/vtable/pointer route for wrapper entries plus the raw `int`/source `void` caveat as a wrapper-page score cap rather than a TimerMgr method-body change.
- 2026-06-23 B004 implementation callback for `0001K6`:
  - Score/metadata unchanged at `87/86`, owner/emitter [UID:0000OT][TimerMgr](by-file/TimerMgr.md), reconstructable true, and blank class C++.
  - Summary/evidence: added current MCP session `ff68e691` source-quality recheck, stable executable/hash provenance, aggregate byte hash, current TimerMgr method inventory, static destructor wrapper/body oddity, xref counts for constructor/destructor/dispatch/schedule/removal/queue helpers, vtable/global facts, generated-output blank marker state, and the unchanged class-level C++ blockers.
- 2026-06-23 B002 implementation callback for `0001K6`:
  - Score/metadata unchanged at `87/86`, owner/emitter [UID:0000OT][TimerMgr](by-file/TimerMgr.md), reconstructable true, and blank class C++.
  - Summary/evidence: reconciled B002 implementation details with MCP session `b880584f`; corrected static destructor endpoint to `0x00597780-0x005977ac`; preserved the `lookup_funcs 0x00597780` / `sub_60C270` wrapper oddity; replaced broad cancellation-helper family text with exact child ranges [UID:00041E][0x004e4f10-0x004e50a0.VectorGrowAcc2Drw](by-memory/0x004e4f10-0x004e50a0.VectorGrowAcc2Drw.md), [UID:00041F][0x004e50a0-0x004e523e.VectorGrowLayer](by-memory/0x004e50a0-0x004e523e.VectorGrowLayer.md), and [UID:00041G][0x004e5420-0x004e55f6.VectorGrowPart](by-memory/0x004e5420-0x004e55f6.VectorGrowPart.md); added MCP-backed predicate/xref summary and B002 child-route/no-code rationale for the new middle `TimerMgr` method pages.
- 2026-06-22 Rule 26 incorporation of B014 TimerMgrAndTimerQueue report:
  - Score unchanged at `87/86`.
  - Summary/evidence: incorporated the narrowed timer callback ABI while keeping the final source split/helper-spelling caveats. The older base callback-body caveat is superseded by the current [UID:000418][0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount](by-memory/0x004e0dd0-0x004e0dda.NewHumanImageLibGetHeadCount.md) implementation without changing TimerMgr ownership or emitted C++.
- 2026-06-22 Rule 26 incorporation of B015 TimerMgrQueueHelpers report:
  - Score unchanged.
  - Summary/evidence: incorporated direct child ownership for TimerMgr query/tick methods, generated scalar deleting destructor wrapper classification, constructor-unwind singleton-clear exclusion, source-facing field/global names, and the non-emitting disposition of the mixed queue-helper aggregate.
- 2026-06-08 Batch 141 parent-gate refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:84`.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:86`.
  - Summary/evidence: live IDA MCP rechecked TimerMgr method boundaries from `0x005976c0` through `0x005986da`, queue-helper caller/callee sets, static storage and tick mirror xrefs, and the updated [UID:0001WD][TimerMgrLayout](by-type/by-struct/TimerMgrLayout.md) offset table. This clears the corrected direct-parent gate for the TimerMgr layout child while leaving final C++ blank below the 95/95 bar.
- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OT][TimerMgr](by-file/TimerMgr.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed representative scheduler and queue-helper starts at `0x005976c0`, `0x00597780`, `0x005977b0`, `0x00597910`, `0x00597a10`, `0x00597dc0`, `0x00597e40`, `0x00597e90`, `0x00598290`, and `0x00598480`; this page and parent [UID:0000OT][TimerMgr](by-file/TimerMgr.md) both meet the 80/80 parent gate. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:84`.
  - Summary/evidence: scored from the full scheduler method map, singleton/static instance notes, embedded queue behavior, layout/type cross-references, and explicit remaining questions around final helper names and exact callback signature.
- 2026-05-31: Updated queue-helper method references after exact by-memory split.
  - What existed before: several method-family rows pointed at the broad [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md) aggregate and used pre-split range ends.
  - Changed to: direct UID references for the exact lookup, timer-period, tick-refresh, splice, and insert pages.
  - Summary/evidence: IDA MCP confirmed the exact child function boundaries and caller relationships during the queue-helper split pass.
