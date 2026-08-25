*** UID:0001WD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000F1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000F1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// TimerMgr layout is emitted by UID0000F1; this page documents the compiler layout of its std::deque member without declaring a duplicate struct.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# TimerMgrLayout

## 2026-07-19 Standard-Deque Layout Closure

- The source object remains exactly `0x24` bytes: the `LObject`/vptr word at `+0x00`, a five-word `std::deque<ScheduledTimerEvent>` implementation at `+0x04`, `DWORD m_currentTick` at `+0x18`, `UINT m_timerPeriod` at `+0x1c`, and `DWORD m_nextDueTick` at `+0x20`.
- Relative to the deque member, Dinkumware lowering uses proxy `+0x00`, map `+0x04`, map count `+0x08`, front `+0x0c`, and size `+0x10`. The target, constructor, dispatch, schedule, erase, growth, and destruction paths independently exercise these same offsets.
- The source member is `std::deque<ScheduledTimerEvent> m_timerQueue`; the compiler fields are analysis layout, not project-authored member names. A project `TimerMgrTimerQueue`, raw map/proxy members, capacity mask API, nullable slots, or node allocation helpers would expose implementation mechanics in human source.
- The event size is `0x14`, which drives one value per deque block in this library specialization. The map count is maintained as a power of two and grows from a minimum of eight; those facts explain the exact masking without creating source-visible invariants.
- TimerMgr UID0000F1 owns and emits the complete class declaration. This page keeps a covered-by formal marker and emits no duplicate layout struct.

## Status

- Type kind: inferred class/layout support.
- Direct owner: [UID:0000F1][TimerMgr](by-class/TimerMgr.md). [UID:0000OT][TimerMgr](by-file/TimerMgr.md) remains the source-module owner.
- Confidence: strong for the queue/tick fields that are repeatedly used by IDA-verified functions; medium-high for final source names and the exact class declaration shape.
- Parent assignment: attached to [UID:0000F1][TimerMgr](by-class/TimerMgr.md) after Batch 141 raised the child to `86/88` and refreshed the direct class parent to `87/86`.

## Score Rationale

| Metric | Value | Rationale |
| --- | --- | --- |
| Completion | `87` | The page records the working offsets for the `LObject` base, embedded queue state, current tick, timer period, and next-due cache; ties each field family to exact TimerMgr and queue-helper children; records the parent-gate decision; and now carries a formal no-duplicate layout marker. It remains below final-audit level because final source member names and full class declaration shape are still inferred. |
| Confidence | `90` | IDA-backed children repeatedly use the same offsets and state transitions, and the direct class/file parent chain is above the 85/85 gate. B009 confirms this is layout support for the class-owned scheduler object rather than a standalone emitted struct. |

## Working Layout

Active generated code and IDA evidence model the scheduler as a `0x24` byte object:

| Offset | Field | Notes |
| --- | --- | --- |
| `+0x00` | `LObject` / vtable base | `TimerMgr` derives from `LObject`; constructor installs the `TimerMgr` vtable. |
| `+0x04` | `m_timerQueue.m_root` / sentinel | Embedded queue state begins immediately after the base pointer. The queue destructor releases this allocation after freeing queued records and the slot array. |
| `+0x08` | `m_timerQueue.m_slots` / `slotEntries` | Pointer array for queued [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md) records. |
| `+0x0c` | `m_timerQueue.m_capacity` / `slotCapacity` | Power-of-two slot count used as a physical index mask. |
| `+0x10` | `m_timerQueue.m_startIndex` | Logical ring start; insert/splice helpers move it when the cheaper shift is at the head. |
| `+0x14` | `m_timerQueue.m_count` | Number of queued scheduled timer records. |
| `+0x18` | `m_currentTick` | Updated from `timeGetTime` in dispatch/setup/refresh paths and mirrored to [UID:000307][0x0069be10-0x0069be14.TimerMgrCurrentTickMirror](by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md). |
| `+0x1c` | `m_timerPeriod` | Set by `timeGetDevCaps`/`timeBeginPeriod` and later passed to `timeEndPeriod`; B015 prefers the period wording over the older `timerResolution` draft name because this field is the WinMM period value. |
| `+0x20` | `m_nextDueTick` | Cached due tick for the first queued event or `0xffffffff` when empty; dispatch/schedule/removal paths refresh it from the queue head. |

## Queue Layout

The embedded queue uses:

- `m_root` / sentinel pointer;
- `ScheduledTimerEvent** m_slots`;
- `m_capacity`;
- `m_startIndex`;
- `m_count`.

The queue is a logical ring over a power-of-two slot array. Insert/remove paths shift whichever side is cheaper and maintain `startIndex` plus `count`.

## B015 Source-Name Normalization

B015 `0001KA` source-quality reanalysis keeps this type with [UID:0000F1][TimerMgr](by-class/TimerMgr.md) and uses source-facing member names in TimerMgr prose: `m_timerQueue.m_root`, `m_timerQueue.m_slots`, `m_timerQueue.m_capacity`, `m_timerQueue.m_startIndex`, `m_timerQueue.m_count`, `m_currentTick`, `m_timerPeriod`, and `m_nextDueTick`. `slotEntries`, `slotCapacity`, `startIndex`, and `count` remain acceptable descriptive queue-layout terms when discussing low-level helper behavior, but draft C++ should prefer the `m_` names where it models member declarations.

The tick mirror globals named from this layout remain descriptive/inferred. Use `g_timerTickBaselineMirror` for [UID:000306][0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror](by-memory/0x0069be0c-0x0069be10.TimerMgrTickBaselineMirror.md) and `g_timerCurrentTickMirror` for [UID:000307][0x0069be10-0x0069be14.TimerMgrCurrentTickMirror](by-memory/0x0069be10-0x0069be14.TimerMgrCurrentTickMirror.md) only as source-quality draft names, not as proven original spellings.

## Evidence

- IDA MCP decompilation of `0x00597e40` writes the multimedia timer period into `this[7]`, writes the current tick into `this[6]`, and mirrors the tick into `dword_69BE10` and `dword_69BE0C`; see [UID:0002KY][0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod](by-memory/0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod.md).
- IDA MCP decompilation of `0x00597e90` refreshes `this[6]` and `dword_69BE10`; see [UID:0002KZ][0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick](by-memory/0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md).
- IDA MCP decompilation of `0x00598090` calls `timeEndPeriod(Block[7])`, destroys the embedded queue at `Block + 1`, clears `dword_67AB80`, and runs `LObject` cleanup; see [UID:0002L4][0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor](by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md).
- IDA MCP confirms queue mutation helpers at `0x00598290` and `0x00598480`, capacity growth at `0x005980f0`, and queue reverse/rotate helpers at `0x00597eb0-0x00597fc8`; see the exact child pages under [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md).
- 2026-06-08 live IDA MCP rechecked the TimerMgr/queue method boundaries from `0x005976c0` through `0x005986da`, the static instance xrefs at `0x0069b3ac` from startup `0x00419f90` and destructor wrapper `0x0060c270`, and tick mirror xrefs to `0x0069be0c`/`0x0069be10` from `0x00597e40`, `0x00597e90`, and dispatch `0x005977b0`.

## Cross-References

- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0000F1][TimerMgr](by-class/TimerMgr.md)
- [UID:0000F2][TimerMgrScheduledEventDequeCompilerSupport](by-class/TimerMgrScheduledEventDequeCompilerSupport.md)
- [UID:0001VX][ScheduledTimerEvent](by-type/by-struct/ScheduledTimerEvent.md)
- [UID:0001K6][0x00597570-0x005986da.TimerMgrAndTimerQueue](by-memory/0x00597570-0x005986da.TimerMgrAndTimerQueue.md)
- [UID:0001KA][0x00597dc0-0x005986da.TimerMgrQueueHelpers](by-memory/0x00597dc0-0x005986da.TimerMgrQueueHelpers.md)
- [UID:0002KY][0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod](by-memory/0x00597e40-0x00597e8a.TimerMgrBeginTimerPeriod.md)
- [UID:0002KZ][0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick](by-memory/0x00597e90-0x00597ea3.TimerMgrRefreshCurrentTick.md)
- [UID:0002L4][0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor](by-memory/0x00598090-0x005980eb.TimerMgrScalarDeletingDestructor.md)

## Changes

- 2026-06-22 Rule 26 incorporation of B015 TimerMgrQueueHelpers report:
  - Score unchanged.
  - Summary/evidence: normalized the support layout names to `m_timerQueue.*`, `m_currentTick`, `m_timerPeriod`, and `m_nextDueTick`; preserved older low-level queue terms as descriptive aliases; and recorded the inferred tick mirror global names without claiming exact original spellings.
- 2026-06-08 Batch 141 parent-gate refresh:
  - Before: `COMPLETION:74`, `CONFIDENCE:86`, and no parent assignment.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, and `AUTOGEN_PARENT_UID:0000F1`.
  - Summary/evidence: added the offset table for the `0x24` TimerMgr object, live IDA MCP rechecked method boundaries, static storage/tick mirror xrefs, queue helper callers/callees, and [UID:0000F1][TimerMgr](by-class/TimerMgr.md) was refreshed to `87/86`, satisfying the corrected child-and-parent gate for direct class ownership.
- 2026-05-31: Replaced generated-layout-only support with IDA-backed field evidence.
  - What existed before: page scored `0/0` and used generated TimerMgr metadata/output as the main layout evidence.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:86`, marked reconstructable, and tied the queue/tick/period fields to exact IDA-verified TimerMgr functions.
  - Summary/evidence: IDA MCP confirms timer period storage at `this[7]`, current tick at `this[6]`, next-due/cache behavior in dispatch/schedule paths, and embedded queue fields used by exact split queue helper pages.
