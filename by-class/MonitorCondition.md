*** UID:00008M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:20 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MonitorCondition
{
public:
    explicit MonitorCondition(Monitor *monitor);
    virtual ~MonitorCondition();

    void Wait();
    void Signal();

private:
    Monitor *m_monitor;
    int m_waiterCount;
    HANDLE m_semaphore;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MonitorCondition

## Summary

`MonitorCondition` is a condition/semaphore object tied to a parent [UID:00008L][Monitor](by-class/Monitor.md). It stores `m_monitor`, tracks `m_waiterCount`, owns a condition `m_semaphore`, releases the parent monitor while waiting, wakes one waiter on signal, and synchronizes with the monitor semaphore.

## Likely Original Placement

- Source: [UID:0000LI][Monitor](by-file/Monitor.md)
- Proposed path: `util/Monitor.cpp`
- Confidence: strong

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| [UID:00052A][0x00528740-0x005287e0.MonitorConditionConstructor](by-memory/0x00528740-0x005287e0.MonitorConditionConstructor.md) | `MonitorCondition::MonitorCondition` | Writes the vtable, stores the parent monitor pointer at `+0x04`, clears waiter count `+0x08`, creates the condition semaphore at `+0x0c`, and throws `Win32Error *` if creation fails. |
| [UID:00052E][0x005287f0-0x00528810.MonitorConditionDestructorRaw](by-memory/0x005287f0-0x00528810.MonitorConditionDestructorRaw.md) | `MonitorCondition::~MonitorCondition` | Source ordinary virtual destructor not modeled as an IDA function; writes the vtable and closes/clears the condition semaphore at `+0x0c`. |
| [UID:000526][0x00528810-0x00528855.MonitorConditionWait](by-memory/0x00528810-0x00528855.MonitorConditionWait.md) | `MonitorCondition::Wait` | Increments the condition waiter count, releases the parent monitor, waits on the condition semaphore, and decrements the count after wake. |
| [UID:00052B][0x00528860-0x00528892.MonitorConditionSignal](by-memory/0x00528860-0x00528892.MonitorConditionSignal.md) | `MonitorCondition::Signal` | If waiters exist, increments the parent waiter count, releases one condition waiter, waits on the parent monitor semaphore, then decrements the parent count. |
| [UID:00052C][0x005288f0-0x00528929.MonitorConditionScalarDeletingDestructor](by-memory/0x005288f0-0x00528929.MonitorConditionScalarDeletingDestructor.md) | scalar deleting destructor | Compiler-generated delete-flag wrapper regenerated from the virtual ordinary destructor; blank formal source and no separate handwritten method. |

## Field Layout

| Offset | Current source-facing field | Evidence |
| --- | --- | --- |
| `+0x00` | `void **vftable` | Current catalog-0375 UDT models the primary vtable storage explicitly; constructor/raw destructor/scalar-wrapper stores and `??_7MonitorCondition@@6B@` prove this exact slot. It remains compiler-managed in human source. |
| `+0x04` | `Monitor *m_monitor` | Constructor stores the parent pointer; wait/signal use parent `m_mutex`, `m_waiterCount`, and `m_semaphore`. |
| `+0x08` | `int m_waiterCount` | Constructor clears it; `Wait()` increments/decrements it around the condition wait; `Signal()` tests it. |
| `+0x0c` | `HANDLE m_semaphore` | Constructor stores `CreateSemaphoreW(0, 0, 0x7fffffff, 0)` here; `Wait()` waits on it; `Signal()` releases it; destructor closes/clears it. |

## Evidence

- `RingBuffer::RingBuffer` constructs two conditions at `0x00556456` and `0x00556480`.
- `RingBuffer::Enqueue` waits on the not-full condition and signals the not-empty condition.
- `RingBuffer::Dequeue` waits on the not-empty condition and signals the not-full condition.
- 2026-06-14 C001 IDA MCP recheck confirms the constructor at `0x00528740` has size `0xa0`, the wait helper at `0x00528810` has size `0x45`, the signal helper at `0x00528860` has size `0x32`, and the scalar deleting destructor at `0x005288f0` has size `0x39`; `0x005287f0` remains raw function-shaped destructor bytes rather than an IDA-modeled function.
- The same live pass found constructor xrefs from [UID:0000C1][RingBuffer](by-class/RingBuffer.md) construction at `0x00556456` and `0x00556480`, wait/signal xrefs from RingBuffer enqueue/dequeue paths, the scalar deleting destructor vtable slot at `0x0061fbf0`, and byte evidence for `0xcc` padding around the raw non-deleting destructor body.
- [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) records the full monitor/condition/gate cluster, including the raw non-deleting condition destructor body, caller/callee sets, field offsets, vtable references, and `0xcc` padding around every body.
- The same memory page records `??_7MonitorCondition@@6B@` at `0x0061fbf0` as referenced by the constructor, raw non-deleting destructor at `0x005287f6`, and scalar deleting destructor.
- [UID:00008L][Monitor](by-class/Monitor.md) is now attached to [UID:0000LI][Monitor](by-file/Monitor.md), and [UID:0000LI][Monitor](by-file/Monitor.md) already lists `MonitorCondition` as part of the same `util/Monitor.cpp` synchronization primitive module.
- This class is a private companion to `Monitor` in the same source family rather than a standalone source root: it only owns condition wait/signaling over a parent monitor and is constructed directly by [UID:0000C1][RingBuffer](by-class/RingBuffer.md).
- 2026-07-04 B009 MCP session `eb7ce28b` reconfirmed `MonitorCondition::MonitorCondition` size `0xa0`, `MonitorCondition::Wait` size `0x45`, `MonitorCondition::Signal` size `0x32`, scalar wrapper size `0x39`, raw ordinary destructor start `0x005287f0` as a non-function with no direct xrefs, vtable `0x0061fbf0` refs from constructor/raw destructor/scalar wrapper, and exact `CreateSemaphoreW`, `ReleaseSemaphore`, `ReleaseMutex`, `WaitForSingleObject`, and `CloseHandle` behavior.
- Current generated RingBuffer source already constructs `new MonitorCondition(mMonitor)` and calls `Wait()` / `Signal()` on the not-full and not-empty conditions, supporting the accepted source-facing names.

## Post-Gate2 IDA Reconciliation

- Supervisor catalog entry `0375` completed the existing `MonitorCondition` type under MCP session `07b29e1b`. The saved poststate is IDB SHA256 `DAA597458433CFB4230D3EE96AA0BCE8683FEFB5CDD6D88E22B33D1687462C17`, 143,192,163 bytes, saved `2026-07-30T12:47:29.2294093-04:00`; the byte-identical prestate backup is `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID0004EO-prestate-20260730-124522`, SHA256 `DADC487F51F66A37C85D62C994F49C545E170AB2F18061AEEDC679828967C6A4`, 143,192,050 bytes.
- Current read-only `type_inspect MonitorCondition` returns `exists:true`, `is_udt:true`, size `16`, and exactly four members: `vftable +0x00`, size 4, `void **`; `m_monitor +0x04`, size 4, `Monitor *`; `m_waiterCount +0x08`, size 4, `int`; `m_semaphore +0x0c`, size 4, `HANDLE`.
- `Monitor` was completed first as an exact 16-byte UDT, so `m_monitor` resolves to the intended parent type. RingBuffer fields `mNotFull` and `mNotEmpty` remain exact `MonitorCondition *` members; no constructor/wait/signal/destructor range, vtable value, source emission route, or formal source changed.
- The applied UDT member spellings remain source-facing inferences backed by constructor/destructor/wait/signal accesses rather than recovered PDB symbols. The exact layout is now present in IDA while the existing `86/88` confidence calibration remains appropriate.

## Generated Data Caveats

Pre-callback generated `class_MonitorCondition.cpp` had a malformed constructor install marker and omitted the constructor/wait/signal bodies. UID0001CL now owns the formal `MonitorCondition` constructor/destructor/wait/signal source block through [UID:0000LI][Monitor](by-file/Monitor.md); this class page remains declaration/support evidence to avoid duplicate class-page emission.

## Autogen And Reconstruction Notes

- Attached to [UID:0000LI][Monitor](by-file/Monitor.md) after this page and the file parent both cleared the current documentation gate.
- The class is reconstructable because the condition semaphore wrapper, wait/signal protocol, and destructor cleanup are source-authored synchronization behavior.
- This class page owns the authoritative companion declaration and ordered `[[CHILDREN]]` insertion. Exact children UID00052A, UID00052E, UID000526, and UID00052B emit the handwritten definitions; aggregate UID0001CL is a non-emitting index.
- The raw `0x005287f0` body is represented as ordinary `MonitorCondition::~MonitorCondition()` source in UID0001CL. The scalar-deleting destructor at `0x005288f0` remains compiler-wrapper output.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 94 | The page records the exact layout, all handwritten and compiler-covered methods, RingBuffer callers, parent-monitor protocol, authoritative H declaration, exact child routing, pointer-throw behavior, and scalar-wrapper no-code policy. |
| Confidence | 95 | Binary and consumer evidence fixes boundaries, vtable use, semaphore behavior, and monitor interaction. Only exact original access specifiers and private spellings remain inferred. |

## Cross-References

- File: [UID:0000LI][Monitor](by-file/Monitor.md)
- Memory: [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md)
- Related: [UID:00008L][Monitor](by-class/Monitor.md), [UID:0000BX][RequestSyncGate](by-class/RequestSyncGate.md), [UID:0000C1][RingBuffer](by-class/RingBuffer.md)

## Changes

- 2026-08-15 B004 UID0000LI callback:
  - Raised to `94/95`, installed the authoritative companion declaration/child route, and attached exact children UID00052A/00052E/000526/00052B in positions 200-230.
  - The exact 16-byte layout is vptr `+0x00`, `Monitor *m_monitor +0x04`, `int m_waiterCount +0x08`, and `HANDLE m_semaphore +0x0c`. The one-slot vtable is generated by the virtual ordinary destructor; UID00052C remains compiler-only blank-code evidence.
  - Wait/Signal preserve friend access, count mutation order, semaphore/mutex handoff, and the two exact RingBuffer caller pairs.

- 2026-07-30 B006 UID0004EO post-Gate2 reconciliation:
  - Added exact current 16-byte/four-member `MonitorCondition` UDT readback, catalog-0375 backup/save identity, parent-type dependency order, and protected no-method/no-route-change disposition.
  - Preserved all constructor/wait/signal/destructor, caller, raw-body, vtable, source-route, and historical evidence; no IDA mutation occurred during this documentation pass.
- 2026-07-04 B009 UID0001CL callback:
  - Recorded `m_monitor`, `m_waiterCount`, and `m_semaphore`; accepted constructor/wait/signal/ordinary-destructor source output through UID0001CL; and kept `0x005288f0` as scalar-deleting destructor compiler-wrapper output.
  - Evidence: MCP session `eb7ce28b` reconfirmed sizes, callers, vtable refs, raw destructor bytes/no-xrefs, Win32 API behavior, and generated RingBuffer `new MonitorCondition(mMonitor)` / `Wait()` / `Signal()` call shape.
  - No metadata change: source output is intentionally centralized in [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) to avoid duplicate class-page emission.
- 2026-06-07 A004 attachment/evidence refresh:
  - Before: scored `76/84` and left legacy parent metadata blank because the class was below the then-current parent-attachment completion gate.
  - After: scored `80/86`, attached to [UID:0000LI][Monitor](by-file/Monitor.md) at position `20`, added exact method table entries for the raw non-deleting destructor, wait helper, signal helper, and scalar deleting destructor, and documented monitor-field/vtable evidence plus final-C++ blockers.
  - Evidence: [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) records live IDA-backed constructor/wait/signal/destructor ranges, raw cleanup body, `??_7MonitorCondition@@6B@` refs, Win32 semaphore behavior, RingBuffer construction/use sites, and padding; [UID:0000LI][Monitor](by-file/Monitor.md) is `84/86` with valid `NexusTK/util/` placement.
- 2026-06-14 C001 Goal 2 IDA refresh:
  - Before: `80/86`, with stale attachment-gate and final-code-gate wording.
  - After: `86/88`, with live IDA 9.1 evidence for the constructor/wait/signal/scalar-destructor function sizes, raw destructor non-function status, RingBuffer construction/use xrefs, vtable-slot refs, and raw byte padding. Owner/emitter routing remains [UID:0000LI][Monitor](by-file/Monitor.md); final C++ stays blank until source-quality names and the raw destructor declaration shape are resolved.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the condition constructor, wait, signal, and deleting-destructor starts at `0x00528740`, `0x00528810`, `0x00528860`, and `0x005288f0`. At that time legacy parent metadata remained blank under the older attachment threshold even though [UID:0000LI][Monitor](by-file/Monitor.md) was the likely source-module parent.
- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the condition/semaphore companion object has purpose, method ranges, RingBuffer wait/signal evidence, and generated data caveats documented, but final field names and complete monitor integration still need layout review. Evidence: linked monitor/condition memory cluster, IDA-confirmed constructor/wait/signal/destructor starts, RingBuffer construction/use sites, and active generated-source omission caveat.
