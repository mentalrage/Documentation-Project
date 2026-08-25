*** UID:0001VX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000F1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000F1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ScheduledTimerEvent is declared once by UID0000F1's complete TimerMgr header block.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ScheduledTimerEvent

## 2026-07-19 TimerMgr-Owned Deque Value Closure

- `ScheduledTimerEvent` is a 20-byte value type declared once in [UID:0000F1][TimerMgr](by-class/TimerMgr.md), not a heap object owned by a project queue class. Direct owner/emitter routing therefore moves from the historical UID0000F2 grouping to UID0000F1.
- Exact field order is `TimerHandler* owner` at `+0x00`, `int timerId` at `+0x04`, `DWORD dueTick` at `+0x08`, `int arg0` at `+0x0c`, and `int arg1` at `+0x10`. Schedule constructs all five words, dispatch copies them, and the due-tick query compares the first two and returns the third.
- The Dinkumware `std::deque<ScheduledTimerEvent>` specialization allocates one 20-byte value per block. Direct target dereferences and generic container controls reject nullable pointer elements and per-event allocation/free source helpers.
- The trailing callback arguments remain descriptive `arg0`/`arg1`; no binary or source artifact proves narrower lexical names. That lexical limit is retained while the layout, width, ownership, and value lifetime are closed.
- The formal block is intentionally a covered-by marker so the struct is emitted exactly once in TimerMgr's complete header union and is not duplicated as a standalone declaration.

## Status

- Type kind: inferred struct/layout.
- Direct owner: [UID:0000F2][TimerMgrScheduledEventDequeCompilerSupport](by-class/TimerMgrScheduledEventDequeCompilerSupport.md). The queue class owns storage, allocation, copying, insertion, and removal of this record type; [UID:0000OT][TimerMgr](by-file/TimerMgr.md) remains the source-module owner.
- Confidence: strong for field order and size from IDA decompilation of schedule/dispatch/insert/splice paths.
- Parent assignment: attached to [UID:0000F2][TimerMgrScheduledEventDequeCompilerSupport](by-class/TimerMgrScheduledEventDequeCompilerSupport.md) after Batch 141 raised the child to `85/90` and refreshed the direct queue-class parent to `85/85`.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `88` | The page records the exact `0x14` record size, five dword fields, schedule/dispatch/lookup/insert/splice evidence, queue-class ownership, source-module context, parent-gate rationale, and now emits the formal source struct declaration. It remains below final-audit level because `arg0` and `arg1` are still generic callback payload names. |
| Confidence | `92` | Multiple independently documented IDA-backed paths use the same five-field record: `TimerMgr::ScheduleTimer` creates it, dispatch copies it before callback, lookup reads the first three dwords, and queue splice/insert copy exactly 16 bytes plus the trailing dword. B009 keeps `timerId` over `eventId` for callback-facing source consistency while preserving the generic payload caveat. |

## Layout

IDA decompilation of the TimerMgr scheduler repeatedly reconstructs a 20-byte scheduled timer record:

| Offset | Field | Notes |
| --- | --- | --- |
| `0x00` | `owner` | Pointer identity for the `TimerHandler` owner. `FindQueuedTimerDueTick` and cancellation helpers compare this field directly to the owner argument. |
| `0x04` | `timerId` / `eventId` | Timer event code used for cancellation/query and callback dispatch. B015 prefers `timerId` in callback-facing prose and draft declarations, while `eventId` remains acceptable in low-level queue text inherited from older helper pages. |
| `0x08` | `dueTick` | Absolute `timeGetTime` tick when the event should dispatch. `ScheduleTimer` stores `delay + currentTick`; dispatch and sorted insert compare this field. |
| `0x0c` | `arg0` | Stored callback argument copied by schedule/insert/dispatch; final semantic name unresolved. |
| `0x10` | `arg1` | Stored callback argument copied by schedule/insert/dispatch; final semantic name unresolved. |

## Behavior

- [UID:0002L7][0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer](by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md) allocates/copies exactly `0x14` bytes per queued record: a 16-byte block plus trailing dword.
- `TimerMgr::ScheduleTimer` at `0x00597910` fills five dwords before calling the insert helper: owner, event id, due tick, and two callback arguments.
- `TimerMgr::DispatchDueTimers` at `0x005977b0` copies a 16-byte block plus trailing dword from the due record, removes that queue entry, then dispatches the owner callback through virtual slot `+4`.
- [UID:0002KX][0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick](by-memory/0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick.md) compares `record[0]` and `record[1]` and returns `record[2]`, confirming the first three fields.
- [UID:0002L6][0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange](by-memory/0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange.md) copies each record as `*(_OWORD *)dst = *(_OWORD *)src` plus `*(dst + 16)`, confirming `0x14` byte stride.
- 2026-06-08 live IDA MCP rechecked the queue-helper caller chain in `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515`: `0x00598480` is called from `TimerMgr::ScheduleTimer` at `0x005979c5`, `0x00598290` is called from dispatch/removal helpers at `0x0059789f`, `0x00597b05`, `0x00597c7f`, and `0x00597d9f`, and all queue-helper gaps around the splice/insert functions remain `0xcc` padding.

## B015 Source-Name Normalization

B015 `0001KA` source-quality reanalysis keeps this record owned by [UID:0000F2][TimerMgrScheduledEventDequeCompilerSupport](by-class/TimerMgrScheduledEventDequeCompilerSupport.md) and recommends the callback-facing signature `virtual bool OnTimer(int timerId, int arg0, int arg1)`. The two trailing fields remain generic `arg0` and `arg1` at this support level; more specific names should only be introduced on caller-family pages that prove a narrower meaning. Queue internals may still use `eventId` when discussing older low-level helper text, but draft source declarations should prefer `timerId` for the second dword.

## Cross-References

- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0000F1][TimerMgr](by-class/TimerMgr.md)
- [UID:0000F2][TimerMgrScheduledEventDequeCompilerSupport](by-class/TimerMgrScheduledEventDequeCompilerSupport.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- [UID:0001WD][TimerMgrLayout](by-type/by-struct/TimerMgrLayout.md)
- [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md)
- [UID:0002KX][0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick](by-memory/0x00597dc0-0x00597e3f.TimerMgrFindQueuedTimerDueTick.md)
- [UID:0002L7][0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer](by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md)

## Changes

- 2026-06-22 Rule 26 incorporation of B015 TimerMgrQueueHelpers report:
  - Score unchanged.
  - Summary/evidence: added the `timerId`/`eventId` naming policy, preserved generic `arg0`/`arg1` until caller-family evidence proves stronger names, and tied the support record to the current `OnTimer(int timerId, int arg0, int arg1)` callback-facing model.
- 2026-06-08 Batch 141 parent-gate refresh:
  - Before: `COMPLETION:78`, `CONFIDENCE:88`, and no parent assignment.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:90`, and `AUTOGEN_PARENT_UID:0000F2`.
  - Summary/evidence: live IDA MCP rechecked queue-helper boundaries, caller chains, and `0xcc` padding around the splice/insert helpers; [UID:0000F2][TimerMgrScheduledEventDequeCompilerSupport](by-class/TimerMgrScheduledEventDequeCompilerSupport.md) was refreshed to `85/85`, making it the actual direct owner of the queued `0x14` event records while [UID:0000OT][TimerMgr](by-file/TimerMgr.md) remains source-module context.
- 2026-05-31: Replaced generated-code-only evidence with IDA-backed record-layout evidence.
  - What existed before: page scored `0/0` and described the 20-byte record mainly from generated TimerMgr code.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, marked reconstructable, and added IDA-backed evidence from schedule, dispatch, lookup, insert, and splice helpers.
  - Summary/evidence: IDA MCP confirms the `0x14` byte record stride, first-three-field comparisons/returns, due-tick sorted insertion, callback dispatch copy, and 20-byte copy behavior in exact TimerMgr queue helper pages.
