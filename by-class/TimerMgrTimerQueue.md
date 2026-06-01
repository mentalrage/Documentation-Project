*** UID:0000F2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

## Responsibility

`TimerMgrTimerQueue` is the embedded queue inside [UID:0000F1][TimerMgr](by-class/TimerMgr.md). It stores pointers to `ScheduledTimerEvent` records in a ring-style slot array, tracks logical start and count, grows capacity as needed, shifts entries for insert/remove, and releases queued event records during destruction.

This is not a general project container. Its element type and helpers are specific to timer scheduling.

## Method and Helper Families

| Range | Current/generated name | Role |
| --- | --- | --- |
| `0x00597fe0-0x00598082` | [UID:0002L3][0x00597fe0-0x00598082.TimerMgrTimerQueueDestructor](by-memory/0x00597fe0-0x00598082.TimerMgrTimerQueueDestructor.md) | Frees queued event records, frees slot array, frees sentinel/root allocation. |
| `0x005980f0-0x00598281` | [UID:0002L5][0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity](by-memory/0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity.md) | Allocates/reallocates the slot-entry array, preserving wrapped ring contents. |
| `0x00598290-0x00598471` | [UID:0002L6][0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange](by-memory/0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange.md) | Removes a contiguous logical range by shifting the cheaper side. |
| `0x00598480-0x005986d9` | [UID:0002L7][0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer](by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md) | Inserts a scheduled timer record and rotates surrounding slots into position. |
| `0x00597eb0-0x00597fc8` | [UID:0002L0][0x00597eb0-0x00597f16.TimerQueueReverseRange](by-memory/0x00597eb0-0x00597f16.TimerQueueReverseRange.md), [UID:0002L1][0x00597f20-0x00597fc8.TimerQueueRotateRange](by-memory/0x00597f20-0x00597fc8.TimerQueueRotateRange.md) | Local rotate support used by insert. |

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

## Cross-References

- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0000F1][TimerMgr](by-class/TimerMgr.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md)
- [UID:0002L0][0x00597eb0-0x00597f16.TimerQueueReverseRange](by-memory/0x00597eb0-0x00597f16.TimerQueueReverseRange.md)
- [UID:0002L1][0x00597f20-0x00597fc8.TimerQueueRotateRange](by-memory/0x00597f20-0x00597fc8.TimerQueueRotateRange.md)
- [UID:0002L3][0x00597fe0-0x00598082.TimerMgrTimerQueueDestructor](by-memory/0x00597fe0-0x00598082.TimerMgrTimerQueueDestructor.md)
- [UID:0002L5][0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity](by-memory/0x005980f0-0x00598281.TimerMgrTimerQueueEnsureCapacity.md)
- [UID:0002L6][0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange](by-memory/0x00598290-0x00598471.TimerMgrTimerQueueSpliceTimerRange.md)
- [UID:0002L7][0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer](by-memory/0x00598480-0x005986d9.TimerMgrTimerQueueInsertTimer.md)
- [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: scored from the queue-specific method/helper family, embedded layout notes, allocation/grow/remove/insert behavior, and generated-output caveats around omitted helper ownership and provisional names.
- 2026-05-31: Updated method/helper map after exact queue-helper split.
  - What existed before: queue methods pointed at broad [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md) aggregate rows with several pre-split range ends.
  - Changed to: exact UID references for destructor, capacity, splice, insert, reverse, and rotate helpers.
  - Summary/evidence: IDA MCP confirmed every child boundary and caller relationship during the split pass.
