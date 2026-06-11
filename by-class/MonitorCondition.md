*** UID:00008M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MonitorCondition

## Summary

`MonitorCondition` is a condition/semaphore object tied to a parent [UID:00008L][Monitor](by-class/Monitor.md). It tracks its own waiter count, releases the parent monitor while waiting, wakes one waiter on signal, and synchronizes with the monitor semaphore.

## Likely Original Placement

- Source: [UID:0000LI][Monitor](by-file/Monitor.md)
- Proposed path: `util/Monitor.cpp`
- Confidence: strong

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x00528740-0x005287e0` | constructor | Writes the `MonitorCondition` vtable, stores the parent monitor pointer at `+0x04`, clears waiter count `+0x08`, creates the condition semaphore at `+0x0c`, and throws `Win32Error` if creation fails. |
| `0x005287f0-0x00528810` | non-deleting destructor body | Raw function-shaped destructor body not modeled as an IDA function; writes the `MonitorCondition` vtable and closes/clears the condition semaphore at `+0x0c`. |
| `0x00528810-0x00528855` | wait helper | Increments condition waiter count, releases the parent monitor through its mutex/semaphore state, waits on the condition semaphore, and decrements waiter count after wake. |
| `0x00528860-0x00528892` | signal helper | If waiters exist, increments the parent monitor waiter count, releases one condition waiter, waits on the parent monitor semaphore, then decrements the parent monitor waiter count. |
| `0x005288f0-0x00528929` | scalar deleting destructor | Writes the `MonitorCondition` vtable, closes/clears the condition semaphore, and optionally frees storage through the shared delete helper. |

## Evidence

- `RingBuffer::RingBuffer` constructs two conditions at `0x00556456` and `0x00556480`.
- `RingBuffer::Enqueue` waits on the not-full condition and signals the not-empty condition.
- `RingBuffer::Dequeue` waits on the not-empty condition and signals the not-full condition.
- IDA confirms all four function starts in the monitor cluster.
- [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) records the full monitor/condition/gate cluster, including the raw non-deleting condition destructor body, caller/callee sets, field offsets, vtable references, and `0xcc` padding around every body.
- The same memory page records `??_7MonitorCondition@@6B@` at `0x0061fbf0` as referenced by the constructor, raw non-deleting destructor at `0x005287f6`, and scalar deleting destructor.
- [UID:00008L][Monitor](by-class/Monitor.md) is now attached to [UID:0000LI][Monitor](by-file/Monitor.md), and [UID:0000LI][Monitor](by-file/Monitor.md) already lists `MonitorCondition` as part of the same `util/Monitor.cpp` synchronization primitive module.
- This class is a private companion to `Monitor` in the same source family rather than a standalone source root: it only owns condition wait/signaling over a parent monitor and is constructed directly by [UID:0000C1][RingBuffer](by-class/RingBuffer.md).

## Generated Data Caveats

Active `class_MonitorCondition.cpp` has a malformed constructor install marker and omits the constructor/wait/signal bodies. Use IDA-confirmed boundaries before migrating this class.

## Autogen And Reconstruction Notes

- Attached to [UID:0000LI][Monitor](by-file/Monitor.md) at position `20` after this page reached `80/86` and the file parent remained above the 80/80 gate.
- The class is reconstructable because the condition semaphore wrapper, wait/signal protocol, and destructor cleanup are source-authored synchronization behavior.
- `RECONSTRUCTION_CPP CODE` remains blank. Final C++ needs the parent `Monitor` field names, public/private API names for wait/signal, raw destructor declaration shape, and `RequestSyncGate` helper relationship resolved to the 95/95 bar.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 80 | The page now records exact constructor/wait/signal/destructor ranges, raw non-deleting destructor identity, parent monitor fields used during wait/signal, RingBuffer construction/use evidence, file-parent attachment, and final-C++ blockers. |
| Confidence | 86 | Existing live IDA-backed memory docs prove the boundaries, vtable refs, Win32 semaphore behavior, RingBuffer callers, and monitor interaction. Confidence remains below near-final because the final public/private method names, parent field names, and raw destructor declaration shape are still open. |

## Cross-References

- File: [UID:0000LI][Monitor](by-file/Monitor.md)
- Memory: [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md)
- Related: [UID:00008L][Monitor](by-class/Monitor.md), [UID:0000BX][RequestSyncGate](by-class/RequestSyncGate.md), [UID:0000C1][RingBuffer](by-class/RingBuffer.md)

## Changes

- 2026-06-07 A004 attachment/evidence refresh:
  - Before: scored `76/84` and left `AUTOGEN_PARENT_UID` blank because the class was below the parent-attachment completion gate.
  - After: scored `80/86`, attached to [UID:0000LI][Monitor](by-file/Monitor.md) at position `20`, added exact method table entries for the raw non-deleting destructor, wait helper, signal helper, and scalar deleting destructor, and documented monitor-field/vtable evidence plus final-C++ blockers.
  - Evidence: [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) records live IDA-backed constructor/wait/signal/destructor ranges, raw cleanup body, `??_7MonitorCondition@@6B@` refs, Win32 semaphore behavior, RingBuffer construction/use sites, and padding; [UID:0000LI][Monitor](by-file/Monitor.md) is `84/86` with valid `NexusTK/util/` placement.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the condition constructor, wait, signal, and deleting-destructor starts at `0x00528740`, `0x00528810`, `0x00528860`, and `0x005288f0`. Left `AUTOGEN_PARENT_UID` blank because this class is below the 80 completion attachment gate even though [UID:0000LI][Monitor](by-file/Monitor.md) is the likely source-module parent.
- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the condition/semaphore companion object has purpose, method ranges, RingBuffer wait/signal evidence, and generated data caveats documented, but final field names and complete monitor integration still need layout review. Evidence: linked monitor/condition memory cluster, IDA-confirmed constructor/wait/signal/destructor starts, RingBuffer construction/use sites, and active generated-source omission caveat.
