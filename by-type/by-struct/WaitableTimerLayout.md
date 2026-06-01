*** UID:0001WI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WaitableTimer Layout

## Status

- Entity kind: class/object layout
- Owner class: [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md)
- Owner module: [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md)
- Size evidence: `0x2c` byte scalar-delete size in `0x005c1210`.
- Confidence: strong for offsets; medium for final field names.
- 2026-05-31 IDA MCP verification confirms the field map from constructor/decompile, raw start/stop disassembly, callback/decompile, destructor/decompile, vtable xrefs, and `dword_69BE3C` xrefs.

## Layout

| Offset | Size | Proposed field | Evidence |
| --- | --- | --- | --- |
| `+0x00` | `4` | `vftable` | Constructor, cleanup, and destructor store `0x00631188`. |
| `+0x04` | `4` | `m_hCompletionEvent` | Constructor creates it through `g_pfnCreateEventW`; cleanup/cancel/destructor call `ResetEvent`; callback calls `SetEvent`; cleanup/destructor close it. |
| `+0x08` | `0x18` | `m_criticalSection` | Constructor calls `InitializeCriticalSection`; lifecycle/cancel/callback paths call enter/leave/delete. |
| `+0x20` | `1` | `m_isRunning` | Constructor clears it; raw start helper sets it; cleanup/cancel/callback/destructor clear it. |
| `+0x21` | `3` | padding | Implied alignment before `+0x24`. |
| `+0x24` | `4` | `m_timerId` | Raw start helper stores `timeSetEvent` result; cleanup/cancel/destructor call `timeKillEvent`; callback and reset paths clear it. |
| `+0x28` | `4` | `m_hCallbackGateEvent` | Raw start helper creates it through `g_pfnCreateEventW`, stores it, and signals it after timer registration; callback waits/closes it; cancel/destructor close it. |

## Correction Notes

Generated metadata currently calls `+0x28` `m_hWorkerThread`. IDA evidence does not support that name. The field is created by `dword_69BE3C`, and [UID:0000WD][0x0041a280-0x0041a4a8.WideApiDispatchInit](by-memory/0x0041a280-0x0041a4a8.WideApiDispatchInit.md) installs `CreateEventW` at that address. The callback waits on `+0x28` only as a startup gate after `timeSetEvent`; it is not a thread handle.

The class name `WaitableTimer` is inherited/generated and may be semantically broad. The implementation is specifically a multimedia timer wrapper with event synchronization, not a Win32 `CreateWaitableTimer` object.

## IDA Verification Notes

- `lookup_funcs` on 2026-05-31 confirms modeled function bodies at `0x005c0ff0`, `0x005c10a0`, `0x005c11c0`, and `0x005c1210`, and reports the raw helper starts `0x005c1120` and `0x005c1170` as not IDA functions.
- Decompilation of the constructor writes the vtable, calls `dword_69BE3C(0,0,0,0)`, stores the result at `+0x04`, initializes the critical section at `+0x08`, clears byte `+0x20`, and clears dwords `+0x24` and `+0x28`.
- Raw disassembly of [UID:0002L8][0x005c1120-0x005c1167.WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c1167.WaitableTimerStartMultimediaTimer.md) sets `+0x20`, creates the `+0x28` event through `dword_69BE3C`, calls `timeSetEvent`, stores `+0x24`, and signals `+0x28`.
- Raw disassembly of [UID:0002L9][0x005c1170-0x005c11b4.WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b4.WaitableTimerCancelMultimediaTimer.md) kills `+0x24`, closes and clears `+0x28`, resets `+0x04`, and leaves the critical section intact.
- Decompilation of `0x005c11c0` waits on `+0x28`, closes it, clears `+0x24/+0x28`, sets the completion event at `+0x04`, and leaves the critical section.
- Decompilation of `0x005c1210` repeats the timer/gate cleanup, deletes the critical section, closes `+0x04`, and optionally frees the object.

## Cross-References

- [UID:0000P7][WaitableTimer](by-file/WaitableTimer.md)
- [UID:0000FY][WaitableTimer](by-class/WaitableTimer.md)
- [UID:0001NX][0x005c0ff0-0x005c129a.WaitableTimer](by-memory/0x005c0ff0-0x005c129a.WaitableTimer.md)
- [UID:0001NY][0x005c1120-0x005c11b4.WaitableTimerRawStartStop](by-memory/0x005c1120-0x005c11b4.WaitableTimerRawStartStop.md)
- [UID:0002L8][0x005c1120-0x005c1167.WaitableTimerStartMultimediaTimer](by-memory/0x005c1120-0x005c1167.WaitableTimerStartMultimediaTimer.md)
- [UID:0002L9][0x005c1170-0x005c11b4.WaitableTimerCancelMultimediaTimer](by-memory/0x005c1170-0x005c11b4.WaitableTimerCancelMultimediaTimer.md)
- [UID:0001Z2][WaitableTimerVtable](by-type/by-vtable/WaitableTimerVtable.md)
- [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md)

## Changes

- 2026-05-31 IDA-backed grading:
  - What existed before: the page was detailed but still carried `COMPLETION:0`, `CONFIDENCE:0`, and blank reconstructable status.
  - Changed to: `COMPLETION:78`, `CONFIDENCE:88`, and `RECONSTRUCTABLE:TRUE`; parent/code remain blank because the layout is below the 95+ final-code gate and final public method names/live caller path are unresolved.
  - Summary/evidence: IDA MCP decompilation and raw disassembly verify the field offsets, event/timer ownership, `+0x28` correction, vtable writes, and helper boundaries.
