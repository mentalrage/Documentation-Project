*** UID:0001WD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# TimerMgrLayout

## Status

- Type kind: inferred class/layout support.
- Likely owner: [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- Confidence: strong for the queue/tick fields that are repeatedly used by IDA-verified functions; medium-high for final source names and the exact class declaration shape.

## Working Layout

Active generated code models the scheduler as:

| Field | Notes |
| --- | --- |
| `vtable` / `LObject` base | `TimerMgr` derives from `LObject`; constructor installs `TimerMgr_vtable`. |
| `TimerMgrTimerQueue queue` | Embedded queue beginning immediately after the `LObject`/vtable area. IDA-verified queue helpers use root/sentinel, slot-entry array, capacity, logical start index, and count. |
| `currentTick` | Updated from `timeGetTime` in dispatch/setup/refresh paths and mirrored to `dword_69BE10`. IDA decompilation shows this as `this[6]` in the TimerMgr-shaped methods. |
| `timerResolution` / period | Set by `timeGetDevCaps`/`timeBeginPeriod` and later passed to `timeEndPeriod`; IDA decompilation shows this as `this[7]` / `Block[7]`. |
| `nextDueTick` | Cached due tick for the first queued event or `0xffffffff` when empty; IDA decompilation of dispatch/schedule/removal paths uses this as `this[8]`. |

## Queue Layout

The embedded queue uses:

- root/sentinel pointer;
- `ScheduledTimerEvent** slotEntries`;
- `slotCapacity`;
- `startIndex`;
- `count`.

The queue is a logical ring over a power-of-two slot array. Insert/remove paths shift whichever side is cheaper and maintain `startIndex` plus `count`.

## Evidence

- IDA MCP decompilation of `0x00597e40` writes the multimedia timer period into `this[7]`, writes the current tick into `this[6]`, and mirrors the tick into `dword_69BE10` and `dword_69BE0C`; see [UID:0002KY][0x00597e40-0x00597e89.TimerMgrBeginTimerPeriod](by-memory/0x00597e40-0x00597e89.TimerMgrBeginTimerPeriod.md).
- IDA MCP decompilation of `0x00597e90` refreshes `this[6]` and `dword_69BE10`; see [UID:0002KZ][0x00597e90-0x00597ea2.TimerMgrRefreshCurrentTick](by-memory/0x00597e90-0x00597ea2.TimerMgrRefreshCurrentTick.md).
- IDA MCP decompilation of `0x00598090` calls `timeEndPeriod(Block[7])`, destroys the embedded queue at `Block + 1`, clears `dword_67AB80`, and runs `LObject` cleanup; see [UID:0002L4][0x00598090-0x005980ea.TimerMgrScalarDeletingDestructor](by-memory/0x00598090-0x005980ea.TimerMgrScalarDeletingDestructor.md).
- IDA MCP confirms queue mutation helpers at `0x00598290` and `0x00598480`, capacity growth at `0x005980f0`, and queue reverse/rotate helpers at `0x00597eb0-0x00597fc8`; see the exact child pages under [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md).

## Cross-References

- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0000F1][TimerMgr](by-class/TimerMgr.md)
- [UID:0000F2][TimerMgrTimerQueue](by-class/TimerMgrTimerQueue.md)
- [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md)
- [UID:0002KY][0x00597e40-0x00597e89.TimerMgrBeginTimerPeriod](by-memory/0x00597e40-0x00597e89.TimerMgrBeginTimerPeriod.md)
- [UID:0002KZ][0x00597e90-0x00597ea2.TimerMgrRefreshCurrentTick](by-memory/0x00597e90-0x00597ea2.TimerMgrRefreshCurrentTick.md)
- [UID:0002L4][0x00598090-0x005980ea.TimerMgrScalarDeletingDestructor](by-memory/0x00598090-0x005980ea.TimerMgrScalarDeletingDestructor.md)

## Changes

- 2026-05-31: Replaced generated-layout-only support with IDA-backed field evidence.
  - What existed before: page scored `0/0` and used generated TimerMgr metadata/output as the main layout evidence.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:86`, marked reconstructable, and tied the queue/tick/period fields to exact IDA-verified TimerMgr functions.
  - Summary/evidence: IDA MCP confirms timer period storage at `this[7]`, current tick at `this[6]`, next-due/cache behavior in dispatch/schedule paths, and embedded queue fields used by exact split queue helper pages.
