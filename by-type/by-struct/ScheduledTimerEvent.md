*** UID:0001VX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScheduledTimerEvent

## Status

- Type kind: inferred struct/layout.
- Likely owner: [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- Confidence: strong for field order and size from IDA decompilation of schedule/dispatch/insert/splice paths.

## Layout

IDA decompilation of the TimerMgr scheduler repeatedly reconstructs a 20-byte scheduled timer record:

| Offset | Field | Notes |
| --- | --- | --- |
| `0x00` | `owner` | Pointer identity for the `TimerHandler` owner. `FindQueuedTimerDueTick` and cancellation helpers compare this field directly to the owner argument. |
| `0x04` | `eventId` | Timer event code used for cancellation/query and callback dispatch. |
| `0x08` | `dueTick` | Absolute `timeGetTime` tick when the event should dispatch. `ScheduleTimer` stores `delay + currentTick`; dispatch and sorted insert compare this field. |
| `0x0c` | `arg0` | Stored callback argument copied by schedule/insert/dispatch; final semantic name unresolved. |
| `0x10` | `arg1` | Stored callback argument copied by schedule/insert/dispatch; final semantic name unresolved. |

## Behavior

- [UID:0002L7][0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer](by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md) allocates/copies exactly `0x14` bytes per queued record: a 16-byte block plus trailing dword.
- `TimerMgr::ScheduleTimer` at `0x00597910` fills five dwords before calling the insert helper: owner, event id, due tick, and two callback arguments.
- `TimerMgr::DispatchDueTimers` at `0x005977b0` copies a 16-byte block plus trailing dword from the due record, removes that queue entry, then dispatches the owner callback through virtual slot `+4`.
- [UID:0002KX][0x00597dc0-0x00597e3e.TimerMgrFindQueuedTimerDueTick](by-memory/0x00597dc0-0x00597e3e.TimerMgrFindQueuedTimerDueTick.md) compares `record[0]` and `record[1]` and returns `record[2]`, confirming the first three fields.
- [UID:0002L6][0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange](by-memory/0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange.md) copies each record as `*(_OWORD *)dst = *(_OWORD *)src` plus `*(dst + 16)`, confirming `0x14` byte stride.

## Cross-References

- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0000F1][TimerMgr](by-class/TimerMgr.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- [UID:0001WD][TimerMgrLayout](by-type/by-struct/TimerMgrLayout.md)
- [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md)
- [UID:0002KX][0x00597dc0-0x00597e3e.TimerMgrFindQueuedTimerDueTick](by-memory/0x00597dc0-0x00597e3e.TimerMgrFindQueuedTimerDueTick.md)
- [UID:0002L7][0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer](by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md)

## Changes

- 2026-05-31: Replaced generated-code-only evidence with IDA-backed record-layout evidence.
  - What existed before: page scored `0/0` and described the 20-byte record mainly from generated TimerMgr code.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, marked reconstructable, and added IDA-backed evidence from schedule, dispatch, lookup, insert, and splice helpers.
  - Summary/evidence: IDA MCP confirms the `0x14` byte record stride, first-three-field comparisons/returns, due-tick sorted insertion, callback dispatch copy, and 20-byte copy behavior in exact TimerMgr queue helper pages.
