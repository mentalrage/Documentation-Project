*** UID:0000F1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TimerMgr

## Status

- Likely original source: [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- Proposed header: `util/TimerMgr.h`
- Confidence: strong for class behavior and source grouping with `TimerMgrTimerQueue`.
- Current generated file: `source-3/simroot_v2/class_TimerMgr.cpp`
- Import source file: `TimerMgr.cpp`

## Responsibility

`TimerMgr` is the process-wide scheduler for timer callbacks. It owns the singleton pointer, initializes multimedia timer resolution, tracks current tick values from `timeGetTime`, stores pending [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md) records in an embedded [UID:0000F2][TimerMgrTimerQueue](by-class/TimerMgrTimerQueue.md), dispatches due callbacks, and removes pending timers for destroyed or cancelled owners.

## Method Families

| Range | Current/generated name | Role |
| --- | --- | --- |
| `0x005976c0-0x00597780` | constructor | Initializes `LObject`, singleton pointer, embedded queue/sentinel, and tick state. |
| `0x00597780-0x005977aa` | destructor/static destructor body | Ends multimedia timer period, destroys the embedded queue, clears singleton, tears down `LObject`. |
| `0x005977b0-0x0059790a` | `DispatchDueTimers` | Pulls due entries in order and dispatches owner callback slot `+4`. |
| `0x00597910-0x00597a0c` | `ScheduleTimer` | Inserts a new due-tick record into the queue. |
| `0x00597a10-0x00597db9` | cancellation helpers | Remove by owner, owner/event id, or owner except one event id. |
| `0x00597dc0-0x00597e3e` | [UID:0002KX][0x00597dc0-0x00597e3e.TimerMgrFindQueuedTimerDueTick](by-memory/0x00597dc0-0x00597e3e.TimerMgrFindQueuedTimerDueTick.md) | Looks up an owner/event pair and returns the queued due tick. |
| `0x00597e40-0x00597ea2` | [UID:0002KY][0x00597e40-0x00597e89.TimerMgrBeginTimerPeriod](by-memory/0x00597e40-0x00597e89.TimerMgrBeginTimerPeriod.md), [UID:0002KZ][0x00597e90-0x00597ea2.TimerMgrRefreshCurrentTick](by-memory/0x00597e90-0x00597ea2.TimerMgrRefreshCurrentTick.md) | Initializes timer resolution and updates shared tick globals. |
| `0x00598290-0x005986d9` | [UID:0002L6][0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange](by-memory/0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange.md), [UID:0002L7][0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer](by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md) | Remove and insert ranges in the embedded ring queue. |

## Layout Notes

Generated metadata describes a 36-byte class: `LObject` base plus a 20-byte timer queue and two tick fields. Current generated code also shows `timerResolution`/period storage used by `timeEndPeriod`; treat [UID:0001WD][TimerMgrLayout](by-type/by-struct/TimerMgrLayout.md) as the current layout page until field offsets are reconciled.

## Globals

- [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md) at `0x0067ab80`: broad singleton pointer used by timer owners.
- Static `TimerMgr` instance at `0x0069b3ac`: constructed by startup code at `0x00419f90` and destroyed by the static destructor path.
- `dword_69BE0C` and `dword_69BE10`: tick mirror globals written during timer initialization/refresh.

## Open Questions

- Final names for the query/helper range at `0x00597dc0` and capacity-grow helper at `0x005980f0`; current documentation uses behavior-backed provisional names.
- Whether `TimerHandler` was a separate `TimerHandler.cpp` or a tiny companion class in `TimerMgr.cpp`.
- Exact event callback signature for the `TimerHandler` virtual slot at vtable offset `+4`.

## Cross-References

- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md)
- [UID:0002KX][0x00597dc0-0x00597e3e.TimerMgrFindQueuedTimerDueTick](by-memory/0x00597dc0-0x00597e3e.TimerMgrFindQueuedTimerDueTick.md)
- [UID:0002KY][0x00597e40-0x00597e89.TimerMgrBeginTimerPeriod](by-memory/0x00597e40-0x00597e89.TimerMgrBeginTimerPeriod.md)
- [UID:0002KZ][0x00597e90-0x00597ea2.TimerMgrRefreshCurrentTick](by-memory/0x00597e90-0x00597ea2.TimerMgrRefreshCurrentTick.md)
- [UID:0002L6][0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange](by-memory/0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange.md)
- [UID:0002L7][0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer](by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md)
- [UID:00024G][0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators](by-memory/0x0060c26a-0x0060c320.StaticDestructorWrappersBeforePoolAllocators.md)
- [UID:0000F2][TimerMgrTimerQueue](by-class/TimerMgrTimerQueue.md)
- [UID:0000F0][TimerHandler](by-class/TimerHandler.md)
- [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md)
- [UID:0000SI][g_pTimerMgr](by-global/g_pTimerMgr.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:84`.
  - Summary/evidence: scored from the full scheduler method map, singleton/static instance notes, embedded queue behavior, layout/type cross-references, and explicit remaining questions around final helper names and exact callback signature.
- 2026-05-31: Updated queue-helper method references after exact by-memory split.
  - What existed before: several method-family rows pointed at the broad [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md) aggregate and used pre-split range ends.
  - Changed to: direct UID references for the exact lookup, timer-period, tick-refresh, splice, and insert pages.
  - Summary/evidence: IDA MCP confirmed the exact child function boundaries and caller relationships during the queue-helper split pass.
