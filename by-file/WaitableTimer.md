*** UID:0000P7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# WaitableTimer

## Status

- Proposed module: `util/WaitableTimer.cpp`
- Proposed header: `util/WaitableTimer.h`
- Confidence: strong for binary island and utility ownership; medium for final public method names.
- Current recovered source: `source-3/simroot_v2/class_WaitableTimer.cpp`

## File Role

`WaitableTimer.cpp` is a small Win32 event plus multimedia-timer wrapper. It owns a completion event, a critical section, a running flag, a multimedia timer id, and a short-lived callback gate event used to coordinate `timeSetEvent` startup with the timer callback.

This is a utility/platform-adjacent source file. It should not be merged into [UID:0000OT][TimerMgr](by-file/TimerMgr.md) until caller and lifetime evidence proves that the original project treated it as part of the same timer-manager source.

## Likely Contents

- [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md)
- [UID:0001WI][WaitableTimerLayout](by-type/by-struct/WaitableTimerLayout.md)
- [UID:0001Z2][WaitableTimerVtable](by-type/by-vtable/WaitableTimerVtable.md)
- raw start/cancel helpers at `0x005c1120` and `0x005c1170`
- timer callback at `0x005c11c0`
- non-deleting cleanup body at `0x005c10a0`

## Evidence

- IDA MCP confirms `WaitableTimer` functions at `0x005c0ff0`, `0x005c10a0`, `0x005c11c0`, and `0x005c1210`.
- IDA MCP recheck on 2026-05-25 confirms the same four function starts with sizes `0xac`, `0x71`, `0x4e`, and `0x8a`.
- 2026-05-26 IDA MCP gap disassembly confirms raw helper starts at `0x005c1120` and `0x005c1170`; IDA has no function objects or direct xrefs for those starts.
- [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) assigns `CreateEventW` to `dword_69BE3C` / `g_pfnCreateEventW` at `0x0041a30c`, and both the constructor and raw start helper call that dispatch entry.
- The constructor creates an unnamed auto-reset event, initializes a critical section, and clears running/timer/gate fields.
- The raw `0x005c1120` helper sets the running flag, creates a second event gate at `+0x28`, registers `0x005c11c0` with `timeSetEvent(delay, 5, callback, this, 0)`, stores the timer id at `+0x24`, and signals the gate after registration succeeds.
- The raw `0x005c1170` helper cancels the timer, closes the gate event, clears `+0x24/+0x28`, resets the completion event, and leaves the object otherwise alive.
- The callback at `0x005c11c0` clears the running flag, waits on the gate event, closes it, resets fields, signals the completion event, and leaves the critical section.
- The scalar deleting destructor kills the multimedia timer, closes the gate event, resets the completion event, deletes the critical section, closes the completion event, and optionally frees the object.
- No direct constructor xrefs were found in this pass, so live use remains unresolved.

## Generated Output Caveats

Current `source-3/simroot_v2/class_WaitableTimer.cpp` emits the constructor, non-deleting cleanup body as `WaitableTimer::Cleanup`, scalar deleting destructor, and the multimedia timer callback as global helper `WaitableTimerCompletion_5C11C0`. It still omits the raw `0x005c1120` start/register helper and the raw `0x005c1170` cancel/reset helper. Treat generated names as useful current provenance, not final proof of original source spelling.

Generated metadata names field `+0x28` as `m_hWorkerThread`, but IDA shows the field is created with the same `CreateEventW` dispatch entry as the completion event, waited by the callback, and closed as an event gate. Do not propagate the worker-thread name into reconstructed source without new caller evidence.

Current `class_WaitableTimer.meta_wave3` reports `vtable_count: 0`, but IDA confirms the one-slot `WaitableTimer` vtable at `0x00631188`.

## Source-Structure Decision

Use `util/WaitableTimer.cpp`. This file is adjacent in the proposed tree to [UID:0000OT][TimerMgr](by-file/TimerMgr.md), but remains separate because the confirmed implementation is a reusable Win32 event/critical-section/multimedia timer primitive and no final caller ownership was established in this pass.

## Cross-References

- [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md)
- [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md)
- [UID:0001NY][0x005c1120-0x005c11b4.WaitableTimerRawStartStop](by-memory/0x005c1120-0x005c11b4.WaitableTimerRawStartStop.md)
- [UID:0002L8][0x005c1120-0x005c1167.WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c1167.WaitableTimerStartMultimediaTimer.md)
- [UID:0002L9][0x005c1170-0x005c11b4.WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b4.WaitableTimerCancelMultimediaTimer.md)
- [UID:0001WI][WaitableTimerLayout](by-type/by-struct/WaitableTimerLayout.md)
- [UID:0001Z2][WaitableTimerVtable](by-type/by-vtable/WaitableTimerVtable.md)
- [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md)
- [UID:0000OT][TimerMgr](by-file/TimerMgr.md)
- [UID:0001QT][client_threading](by-meta/client_threading.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents the Win32 timer/event utility role, class/layout/vtable refs, raw start-stop helpers, IDA evidence, and generated-output caveats; final public method names and live callers remain medium-confidence.

- 2026-05-31 projected reconstruction path and raw helper split:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, and the raw helper inventory only pointed at the combined `0x005c1120-0x005c11b4` range.
  - Changed to: `NexusTK/util/`, matching the existing proposed source tree `util/WaitableTimer.cpp`, and exact child links for the start/register and cancel/reset helper bodies.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` already lists `WaitableTimer.cpp` under `NexusTK/util/`; IDA MCP verifies this is a standalone Win32 event/multimedia timer utility island with no caller evidence requiring merge into `TimerMgr.cpp`.
