*** UID:0000F2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TimerMgrTimerQueue

## Status

- Likely original source: [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- Confidence: strong for embedding in `TimerMgr`; medium for exact helper names.
- Current generated file: `source-3/simroot_v2/class_TimerMgrTimerQueue.cpp`
- Import source file: `TimerMgr.cpp`
- Parent gate: direct source parent [UID:0000OT][TimerMgr](by-file/TimerMgr.md) is `90/86`; this class now clears `85/85` and is the direct parent for [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md).

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `85` | The page documents the queue's scheduler-specific responsibility, embedded layout fields, destructor/grow/splice/insert/reverse/rotate helper family, allocation behavior, generated-output caveats, and direct ownership of the `ScheduledTimerEvent` element type. It remains near the gate because final helper names and member-vs-static declaration shape are still provisional. |
| Confidence | `85` | Exact child memory pages and Batch 141 live IDA MCP agree on the queue-local helper boundaries, callers, callees, record size, and embedding in `TimerMgr`. Confidence is held at the gate because decompiler iterator noise still obscures final signatures. |

## Responsibility

`TimerMgrTimerQueue` is the embedded queue inside [UID:0000F1][TimerMgr](by-class/TimerMgr.md). It stores pointers to `ScheduledTimerEvent` records in a ring-style slot array, tracks logical start and count, grows capacity as needed, shifts entries for insert/remove, and releases queued event records during destruction.

This is not a general project container. Its element type and helpers are specific to timer scheduling.

## Method and Helper Families

| Range | Current/generated name | Role |
| --- | --- | --- |
| `0x00597fe0-0x00598082` | [UID:0002L3][0x00597fe0-0x00598083.TimerMgrTimerQueueDestructor](by-memory/0x00597fe0-0x00598083.TimerMgrTimerQueueDestructor.md) | Frees queued event records, frees slot array, frees sentinel/root allocation. |
| `0x005980f0-0x00598281` | [UID:0002L5][0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity](by-memory/0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity.md) | Allocates/reallocates the slot-entry array, preserving wrapped ring contents. |
| `0x00598290-0x00598471` | [UID:0002L6][0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange](by-memory/0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange.md) | Removes a contiguous logical range by shifting the cheaper side. |
| `0x00598480-0x005986d9` | [UID:0002L7][0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer](by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md) | Inserts a scheduled timer record and rotates surrounding slots into position. |
| `0x00597eb0-0x00597fc8` | [UID:0002L0][0x00597eb0-0x00597f17.TimerQueueReverseRange](by-memory/0x00597eb0-0x00597f17.TimerQueueReverseRange.md), [UID:0002L1][0x00597f20-0x00597fc9.TimerQueueRotateRange](by-memory/0x00597f20-0x00597fc9.TimerQueueRotateRange.md) | Local rotate support used by insert. |

## Layout Notes

See [UID:0001WD][TimerMgrLayout](by-type/by-struct/TimerMgrLayout.md). The queue portion is currently modeled as:

- root/sentinel pointer;
- pointer array of `ScheduledTimerEvent*`;
- slot capacity;
- logical start index;
- count.

Large slot arrays use MSVC-style aligned allocation with a raw allocation pointer stored just before the aligned pointer. The destructor validates the alignment slack before freeing.

## Generated Output Caveats

Active `class_TimerMgrTimerQueue.cpp` only emits the destructor. The remove/insert/grow helpers are either emitted under `class_TimerMgr.cpp` or omitted entirely, even though IDA confirms they are queue-local functions in the same memory neighborhood.

The exact queue-helper memory page now records the omitted helper evidence for `0x00597eb0`, `0x00597f20`, and `0x005980f0`; restore those as queue-local helpers during migration even if the generator leaves them outside the active queue class file.

## Live Evidence Refresh

- 2026-06-08 live IDA MCP on `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515` confirmed the queue helper boundaries: reverse `0x00597eb0-0x00597f17`, rotate `0x00597f20-0x00597fc9`, destructor `0x00597fe0-0x00598083`, grow `0x005980f0-0x00598282`, splice `0x00598290-0x00598472`, and insert `0x00598480-0x005986da`.
- The same pass confirmed the queue-local caller/callee shape: rotate is called only by insert and calls reverse three times; grow is called only from insert; splice is called by dispatch/removal helpers; insert is called from `TimerMgr::ScheduleTimer` at `0x005979c5`; splice and insert are separated by `0xcc` padding.
- This supports treating [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md) as a queue-owned element record even though the public scheduler methods that create and consume records live on [UID:0000F1][TimerMgr](by-class/TimerMgr.md).

## Cross-References

- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0000F1][TimerMgr](by-class/TimerMgr.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md)
- [UID:0002L0][0x00597eb0-0x00597f17.TimerQueueReverseRange](by-memory/0x00597eb0-0x00597f17.TimerQueueReverseRange.md)
- [UID:0002L1][0x00597f20-0x00597fc9.TimerQueueRotateRange](by-memory/0x00597f20-0x00597fc9.TimerQueueRotateRange.md)
- [UID:0002L3][0x00597fe0-0x00598083.TimerMgrTimerQueueDestructor](by-memory/0x00597fe0-0x00598083.TimerMgrTimerQueueDestructor.md)
- [UID:0002L5][0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity](by-memory/0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity.md)
- [UID:0002L6][0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange](by-memory/0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange.md)
- [UID:0002L7][0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer](by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md)
- [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md)

## Changes

- 2026-06-08 Batch 141 parent-gate refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:80`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:85`.
  - Summary/evidence: live IDA MCP rechecked all queue-helper boundaries, caller/callee sets, and padding around splice/insert; [UID:0000OT][TimerMgr](by-file/TimerMgr.md) already clears `90/86`, and this page now justifies direct ownership of [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md) while keeping final helper signatures open.
- Before: reconstruction autogen metadata was unclassified.
- Changed to: marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000OT][TimerMgr](by-file/TimerMgr.md).
- Evidence: 2026-06-05 IDA MCP on `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirmed the documented queue-local reverse, rotate, destructor, capacity, splice, and insert helper starts at `0x00597eb0`, `0x00597f20`, `0x00597fe0`, `0x005980f0`, `0x00598290`, and `0x00598480`; this page and parent [UID:0000OT][TimerMgr](by-file/TimerMgr.md) both meet the 80/80 parent gate. No C++ was emitted because the page is below the 95/95 reconstruction-code bar.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: scored from the queue-specific method/helper family, embedded layout notes, allocation/grow/remove/insert behavior, and generated-output caveats around omitted helper ownership and provisional names.
- 2026-05-31: Updated method/helper map after exact queue-helper split.
  - What existed before: queue methods pointed at broad [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md) aggregate rows with several pre-split range ends.
  - Changed to: exact UID references for destructor, capacity, splice, insert, reverse, and rotate helpers.
  - Summary/evidence: IDA MCP confirmed every child boundary and caller relationship during the split pass.
