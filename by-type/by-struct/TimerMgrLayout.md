*** UID:0001WD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000F1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TimerMgrLayout

## Status

- Type kind: inferred class/layout support.
- Direct owner: [UID:0000F1][TimerMgr](by-class/TimerMgr.md). [UID:0000OT][TimerMgr](by-file/TimerMgr.md) remains the source-module owner.
- Confidence: strong for the queue/tick fields that are repeatedly used by IDA-verified functions; medium-high for final source names and the exact class declaration shape.
- Parent assignment: attached to [UID:0000F1][TimerMgr](by-class/TimerMgr.md) after Batch 141 raised the child to `86/88` and refreshed the direct class parent to `87/86`.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `86` | The page now records the working offsets for the `LObject` base, embedded queue state, current tick, timer period, and next-due cache; ties each field family to exact TimerMgr and queue-helper children; and records the parent-gate decision. It remains below final-audit level because the constructor/destructor/dispatch/schedule/removal methods still need exact per-method child pages and final source member names. |
| Confidence | `88` | IDA-backed children repeatedly use the same offsets and state transitions, and the direct class/file parent chain is now above the 85/85 gate. Confidence remains below final source because some source declaration details and callback signatures are still provisional. |

## Working Layout

Active generated code and IDA evidence model the scheduler as a `0x24` byte object:

| Offset | Field | Notes |
| --- | --- | --- |
| `+0x00` | `LObject` / vtable base | `TimerMgr` derives from `LObject`; constructor installs the `TimerMgr` vtable. |
| `+0x04` | `TimerMgrTimerQueue::root` / sentinel | Embedded queue state begins immediately after the base pointer. The queue destructor releases this allocation after freeing queued records and the slot array. |
| `+0x08` | `TimerMgrTimerQueue::slotEntries` | Pointer array for queued [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md) records. |
| `+0x0c` | `TimerMgrTimerQueue::slotCapacity` | Power-of-two slot count used as a physical index mask. |
| `+0x10` | `TimerMgrTimerQueue::startIndex` | Logical ring start; insert/splice helpers move it when the cheaper shift is at the head. |
| `+0x14` | `TimerMgrTimerQueue::count` | Number of queued scheduled timer records. |
| `+0x18` | `currentTick` | Updated from `timeGetTime` in dispatch/setup/refresh paths and mirrored to [UID:000307][0x0069be10-0x0069be14.TimerMgrCurrentTickMirror](by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md). |
| `+0x1c` | `timerResolution` / period | Set by `timeGetDevCaps`/`timeBeginPeriod` and later passed to `timeEndPeriod`. |
| `+0x20` | `nextDueTick` | Cached due tick for the first queued event or `0xffffffff` when empty; dispatch/schedule/removal paths refresh it from the queue head. |

## Queue Layout

The embedded queue uses:

- root/sentinel pointer;
- `ScheduledTimerEvent** slotEntries`;
- `slotCapacity`;
- `startIndex`;
- `count`.

The queue is a logical ring over a power-of-two slot array. Insert/remove paths shift whichever side is cheaper and maintain `startIndex` plus `count`.

## Evidence

- IDA MCP decompilation of `0x00597e40` writes the multimedia timer period into `this[7]`, writes the current tick into `this[6]`, and mirrors the tick into `dword_69BE10` and `dword_69BE0C`; see [UID:0002KY][0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod](by-memory/0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod.md).
- IDA MCP decompilation of `0x00597e90` refreshes `this[6]` and `dword_69BE10`; see [UID:0002KZ][0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick](by-memory/0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md).
- IDA MCP decompilation of `0x00598090` calls `timeEndPeriod(Block[7])`, destroys the embedded queue at `Block + 1`, clears `dword_67AB80`, and runs `LObject` cleanup; see [UID:0002L4][0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor](by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md).
- IDA MCP confirms queue mutation helpers at `0x00598290` and `0x00598480`, capacity growth at `0x005980f0`, and queue reverse/rotate helpers at `0x00597eb0-0x00597fc8`; see the exact child pages under [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md).
- 2026-06-08 live IDA MCP rechecked the TimerMgr/queue method boundaries from `0x005976c0` through `0x005986da`, the static instance xrefs at `0x0069b3ac` from startup `0x00419f90` and destructor wrapper `0x0060c270`, and tick mirror xrefs to `0x0069be0c`/`0x0069be10` from `0x00597e40`, `0x00597e90`, and dispatch `0x005977b0`.

## Cross-References

- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0000F1][TimerMgr](by-class/TimerMgr.md)
- [UID:0000F2][TimerMgrTimerQueue](by-class/TimerMgrTimerQueue.md)
- [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md)
- [UID:0002KY][0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod](by-memory/0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod.md)
- [UID:0002KZ][0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick](by-memory/0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md)
- [UID:0002L4][0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor](by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md)

## Changes

- 2026-06-08 Batch 141 parent-gate refresh:
  - Before: `COMPLETION:74`, `CONFIDENCE:86`, and no parent assignment.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, and `AUTOGEN_PARENT_UID:0000F1`.
  - Summary/evidence: added the offset table for the `0x24` TimerMgr object, live IDA MCP rechecked method boundaries, static storage/tick mirror xrefs, queue helper callers/callees, and [UID:0000F1][TimerMgr](by-class/TimerMgr.md) was refreshed to `87/86`, satisfying the corrected child-and-parent gate for direct class ownership.
- 2026-05-31: Replaced generated-layout-only support with IDA-backed field evidence.
  - What existed before: page scored `0/0` and used generated TimerMgr metadata/output as the main layout evidence.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:86`, marked reconstructable, and tied the queue/tick/period fields to exact IDA-verified TimerMgr functions.
  - Summary/evidence: IDA MCP confirms timer period storage at `this[7]`, current tick at `this[6]`, next-due/cache behavior in dispatch/schedule paths, and embedded queue fields used by exact split queue helper pages.
