*** UID:00008L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Monitor

## Summary

`Monitor` is a Win32 mutex/semaphore synchronization object used by `RingBuffer` and `Thread` synchronization paths. It tracks waiter count, owns an unnamed mutex handle, and owns a monitor semaphore used by condition signaling.

## Likely Original Placement

- Source: [UID:0000LI][Monitor](by-file/Monitor.md)
- Proposed path: `util/Monitor.cpp`
- Confidence: strong

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x005285e0-0x005286c8` | constructor | Writes the `Monitor` vtable, creates an unnamed mutex at `+0x04`, clears waiter count `+0x08`, creates the monitor semaphore at `+0x0c`, and throws `Win32Error` on either handle-creation failure. |
| `0x005286d0-0x00528705` | non-deleting destructor body | Raw function-shaped destructor body not modeled as an IDA function; writes the `Monitor` vtable, closes/clears semaphore `+0x0c` and mutex `+0x04`, then returns. |
| `0x005288a0-0x005288ee` | scalar deleting destructor | Performs the same handle cleanup and optionally frees storage through the shared delete helper when the delete flag is set. |

Lock/unlock behavior is currently represented through [UID:0000BX][RequestSyncGate](by-class/RequestSyncGate.md) and MonitorCondition interactions; final method names need layout review.

## Evidence

- `Monitor` constructor callers are [UID:0000C1][RingBuffer](by-class/RingBuffer.md) at `0x0055642c` and [UID:0000EV][Thread](by-class/Thread.md) at `0x0059632d`.
- The constructor throws `Win32Error` when `CreateMutexW` or `CreateSemaphoreW` fails.
- [UID:00008M][MonitorCondition](by-class/MonitorCondition.md) stores a parent monitor pointer and calls back into monitor lock/unlock behavior while waiting and signaling.
- [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) records the complete monitor/condition/gate cluster, including caller/callee sets, field offsets, vtable references, raw destructor bodies, and alignment padding.
- The same memory page records `??_7Monitor@@6B@` at `0x0061fbe8` as referenced by the constructor, the raw non-deleting destructor at `0x005286d6`, and the scalar deleting destructor, tying both cleanup bodies to this class.
- [UID:0000LI][Monitor](by-file/Monitor.md) is already scored `84/86`, has valid `NexusTK/util/` placement, and lists `Monitor` as the first synchronization primitive in the module, so the parent attachment gate is now satisfied.

## Open Questions

- Whether the original class exposed explicit `Lock`/`Unlock` methods directly, via `RequestSyncGate`, or through inline helper wrappers.
- Final field names for mutex handle, semaphore handle, and waiter count.
- Final source-level visibility of the raw non-deleting destructor body; keep it documented as source-authored cleanup behavior, but do not emit final C++ until the class declaration and helper split are audited.

## Autogen And Reconstruction Notes

- Attached to [UID:0000LI][Monitor](by-file/Monitor.md) at position `10` after this class reached `80/86` and the file parent remained above the 80/80 gate.
- The class is reconstructable because the Win32 mutex/semaphore wrapper and destructor cleanup are source-authored synchronization behavior.
- `RECONSTRUCTION_CPP CODE` remains blank. Final C++ needs the monitor field names, public lock/unlock API decision, `RequestSyncGate` relationship, and raw destructor declaration shape resolved to the 95/95 bar.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 80 | The page now records exact constructor/destructor ranges, raw non-deleting destructor identity, field offsets, caller evidence, vtable evidence, parent-module attachment, and final-C++ blockers. |
| Confidence | 86 | Existing live IDA-backed memory docs prove the boundaries, vtable refs, Win32 handle behavior, and RingBuffer/Thread callers. Confidence remains below near-final because lock/unlock exposure, final field names, and raw destructor declaration shape are still open. |

## Cross-References

- File: [UID:0000LI][Monitor](by-file/Monitor.md)
- Memory: [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md)
- Related classes: [UID:00008M][MonitorCondition](by-class/MonitorCondition.md), [UID:0000BX][RequestSyncGate](by-class/RequestSyncGate.md), [UID:0000C1][RingBuffer](by-class/RingBuffer.md), [UID:0000EV][Thread](by-class/Thread.md)

## Changes

- 2026-06-07 A004 attachment/evidence refresh:
  - Before: scored `74/84` and left `AUTOGEN_PARENT_UID` blank because the class was below the parent-attachment completion gate.
  - After: scored `80/86`, attached to [UID:0000LI][Monitor](by-file/Monitor.md) at position `10`, added exact method table entries for the raw non-deleting destructor and scalar deleting destructor, and documented vtable/field-offset evidence plus final-C++ blockers.
  - Evidence: [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) records live IDA-backed constructor/destructor ranges, raw cleanup body, `??_7Monitor@@6B@` refs, Win32 mutex/semaphore behavior, RingBuffer/Thread callers, and padding; [UID:0000LI][Monitor](by-file/Monitor.md) is `84/86` with valid `NexusTK/util/` placement.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the monitor constructor at `0x005285e0` and scalar deleting destructor at `0x005288a0`. Left `AUTOGEN_PARENT_UID` blank because this class is below the 80 completion attachment gate even though [UID:0000LI][Monitor](by-file/Monitor.md) is the likely source-module parent.
- Completion/confidence score update: existed before as `0/0`; changed to `74/84`. Summary: the Win32 synchronization object has clear purpose, source placement, constructor/destructor ranges, caller evidence, and condition relationship, but lock/unlock exposure and final field names remain open. Evidence: linked monitor/condition memory cluster, `RingBuffer` and `Thread` constructor callers, `CreateMutexW`/`CreateSemaphoreW` failure behavior, and `MonitorCondition` wait/signal interactions.
