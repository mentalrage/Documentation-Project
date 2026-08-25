*** UID:00008L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Monitor.h"
#include "Error.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include <windows.h>

class MonitorCondition;

class Monitor
{
    friend class MonitorCondition;

public:
    Monitor();
    virtual ~Monitor();

    void Lock();
    void Unlock();

private:
    HANDLE m_mutex;
    int m_waiterCount;
    HANDLE m_semaphore;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Monitor

## Summary

`Monitor` is a Win32 mutex/semaphore synchronization object used by `RingBuffer` and `Thread` synchronization paths. It tracks `m_waiterCount`, owns an unnamed mutex handle `m_mutex`, and owns a monitor semaphore `m_semaphore` used by condition signaling.

## Likely Original Placement

- Source: [UID:0000LI][Monitor](by-file/Monitor.md)
- Proposed path: `util/Monitor.cpp`
- Confidence: strong

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| [UID:00051Y][0x005285e0-0x005286c8.MonitorConstructor](by-memory/0x005285e0-0x005286c8.MonitorConstructor.md) | `Monitor::Monitor` | Writes the `Monitor` vtable, creates an unnamed mutex at `+0x04`, clears waiter count `+0x08`, creates the monitor semaphore at `+0x0c`, and throws `Win32Error *` on either handle-creation failure. |
| [UID:000523][0x005286d0-0x00528705.MonitorDestructorRaw](by-memory/0x005286d0-0x00528705.MonitorDestructorRaw.md) | `Monitor::~Monitor` | Source ordinary virtual destructor not modeled as an IDA function; writes the `Monitor` vtable, closes/clears semaphore `+0x0c` and mutex `+0x04`, then returns. |
| [UID:00051Z][0x00528710-0x0052871c.MonitorLock](by-memory/0x00528710-0x0052871c.MonitorLock.md) | `Monitor::Lock` | Waits indefinitely on `m_mutex` at `+0x04`; consumed by RingBuffer/Thread synchronization paths. Earlier `RequestSyncGate::Lock` naming is historical alias evidence only. |
| [UID:000525][0x00528720-0x0052873e.MonitorUnlock](by-memory/0x00528720-0x0052873e.MonitorUnlock.md) | `Monitor::Unlock` | Releases `m_semaphore` at `+0x0c` when `m_waiterCount` at `+0x08` is positive, otherwise releases `m_mutex` at `+0x04`; earlier `RequestSyncGate::Unlock` naming must not emit a duplicate body. |
| [UID:000527][0x005288a0-0x005288ee.MonitorScalarDeletingDestructor](by-memory/0x005288a0-0x005288ee.MonitorScalarDeletingDestructor.md) | scalar deleting destructor | Compiler-generated delete-flag wrapper regenerated from the virtual ordinary destructor; blank formal source and no separate handwritten method. |

Lock/unlock behavior is IDA-confirmed at `0x00528710` and `0x00528720` and is now accepted as `Monitor::Lock` / `Monitor::Unlock` source. Exact original public/private spelling remains inferred, but the source body route is no longer blocked by `RequestSyncGate`.

## Field Layout

| Offset | Current source-facing field | Evidence |
| --- | --- | --- |
| `+0x00` | `void **vftable` | Current catalog-0375 UDT models the primary vtable storage explicitly; constructor/raw destructor/scalar-wrapper stores and `??_7Monitor@@6B@` prove this exact slot. It remains compiler-managed in human source. |
| `+0x04` | `HANDLE m_mutex` | Constructor stores `CreateMutexW(0, FALSE, 0)` here; `Monitor::Lock` waits on it; `Monitor::Unlock` releases it when no monitor waiters exist; destructor closes/clears it. |
| `+0x08` | `int m_waiterCount` | Constructor clears it; `Monitor::Unlock` tests it; `MonitorCondition::Signal` increments/decrements it around the monitor semaphore handoff. |
| `+0x0c` | `HANDLE m_semaphore` | Constructor stores `CreateSemaphoreW(0, 0, 0x7fffffff, 0)` here; `Monitor::Unlock` and condition signal/wait handoff use it; destructor closes/clears it. |

## Evidence

- `Monitor` constructor callers are [UID:0000C1][RingBuffer](by-class/RingBuffer.md) at `0x0055642c` and [UID:0000EV][Thread](by-class/Thread.md) at `0x0059632d`.
- The constructor throws `Win32Error` when `CreateMutexW` or `CreateSemaphoreW` fails.
- [UID:00008M][MonitorCondition](by-class/MonitorCondition.md) stores a parent monitor pointer and calls back into monitor lock/unlock behavior while waiting and signaling.
- [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) records the complete monitor/condition/gate cluster, including caller/callee sets, field offsets, vtable references, raw destructor bodies, and alignment padding.
- The same memory page records `??_7Monitor@@6B@` at `0x0061fbe8` as referenced by the constructor, the raw non-deleting destructor at `0x005286d6`, and the scalar deleting destructor, tying both cleanup bodies to this class.
- [UID:0000LI][Monitor](by-file/Monitor.md) is now `94/94`, retains valid `NexusTK/util/` placement, and owns only the Monitor/MonitorCondition compilation unit after the CriticalSection split.
- 2026-06-14 C001 IDA MCP recheck on `a001_goal2_class_batch` confirms constructor `0x005285e0` size `0xe8`, lock helper `0x00528710` size `0x0c`, unlock helper `0x00528720` size `0x1e`, condition helpers at `0x00528740`, `0x00528810`, `0x00528860`, scalar deleting destructor `0x005288a0`, and the condition scalar destructor at `0x005288f0`. The raw non-deleting destructor at `0x005286d0` still is not an IDA function.
- Xrefs confirm constructor callers at `0x0055642c` and `0x0059632d`; lock/unlock helper caller sets from RingBuffer/Thread paths; scalar deleting destructor vtable xref from `0x0061fbe8`; and vtable refs at constructor `0x0052860e`, raw destructor `0x005286d6`, and scalar destructor `0x005288a9`.
- `get_bytes` over `0x005286c0-0x00528710` confirms padding after the constructor, then the raw destructor body that writes the Monitor vtable, calls `CloseHandle` for semaphore and mutex handles when non-null, zeroes both fields, returns, and is followed by `0xcc` padding before the lock helper.
- 2026-07-04 B009 MCP session `eb7ce28b` reconfirmed `Monitor::Monitor` size `0xe8`, `Monitor::Lock` size `0x0c`, `Monitor::Unlock` size `0x1e`, raw destructor start `0x005286d0` as a non-function with no direct xrefs, vtable `0x0061fbe8` refs from constructor/raw destructor/scalar wrapper, and exact `WaitForSingleObject` / `ReleaseSemaphore` / `ReleaseMutex` behavior.
- Current generated RingBuffer source already calls `mMonitor->Lock()` and `mMonitor->Unlock()`, supporting the accepted source-facing names and rejecting duplicate `RequestSyncGate` output.

## Post-Gate2 IDA Reconciliation

- Supervisor catalog entry `0375` completed the existing `Monitor` type under MCP session `07b29e1b`. The saved poststate is IDB SHA256 `DAA597458433CFB4230D3EE96AA0BCE8683FEFB5CDD6D88E22B33D1687462C17`, 143,192,163 bytes, saved `2026-07-30T12:47:29.2294093-04:00`; the byte-identical prestate backup is `E:\NTK\Resources\NexusTK\NexusTK.exe.i64.bak-UID0004EO-prestate-20260730-124522`, SHA256 `DADC487F51F66A37C85D62C994F49C545E170AB2F18061AEEDC679828967C6A4`, 143,192,050 bytes.
- Current read-only `type_inspect Monitor` returns `exists:true`, `is_udt:true`, size `16`, and exactly four members: `vftable +0x00`, size 4, `void **`; `m_mutex +0x04`, size 4, `HANDLE`; `m_waiterCount +0x08`, size 4, `int`; `m_semaphore +0x0c`, size 4, `HANDLE`.
- The dependency order was deterministic: the existing incomplete `Monitor` declaration was completed before `MonitorCondition`, allowing the latter's parent pointer to resolve exactly. No method range, function identity, vtable value, source emission route, or RingBuffer pointer-member type changed.
- The applied UDT member spellings remain source-facing inferences backed by the documented constructor/destructor/lock/unlock/wait/signal accesses; they are not recovered PDB symbols. That spelling uncertainty is the reason the current `94/95` score remains below final certainty.

## Open Questions

- Exact original access specifier for `Lock` / `Unlock` remains inferred. The accepted callback uses public methods because generated RingBuffer consumers already call `mMonitor->Lock()` and `mMonitor->Unlock()`.
- Exact original field spellings are inferred as `m_mutex`, `m_waiterCount`, and `m_semaphore`; behavior and offsets are fixed by MCP evidence.
- The raw non-deleting destructor body is represented as ordinary `Monitor::~Monitor()` source in UID0001CL. The scalar-deleting destructor remains compiler wrapper output.

## Autogen And Reconstruction Notes

- Attached to [UID:0000LI][Monitor](by-file/Monitor.md) after this class reached `80/86` and the file parent remained above the then-active attachment gate.
- The class is reconstructable because the Win32 mutex/semaphore wrapper and destructor cleanup are source-authored synchronization behavior.
- This class page now owns the authoritative Monitor declaration, Monitor CPP include root, and ordered `[[CHILDREN]]` insertion. Exact children UID00051Y, UID000523, UID00051Z, and UID000525 emit the four handwritten definitions; aggregate UID0001CL is a non-emitting index.
- `RequestSyncGate` is a historical/recovered-output alias for the same lock/unlock bytes, not a separate source emitter. The scalar-deleting destructor remains compiler-generated wrapper policy.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 94 | The page records exact layout, all handwritten and compiler-covered methods, caller/xref and vtable evidence, the authoritative CPP/H root, exact child routing, pointer-throw behavior, and no-duplicate RequestSyncGate policy. |
| Confidence | 95 | Binary evidence fixes behavior, boundaries, vtable use, handle fields, and consumers. Only exact original access specifiers and private spellings remain inferred. |

## Cross-References

- File: [UID:0000LI][Monitor](by-file/Monitor.md)
- Memory: [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md)
- Related classes: [UID:00008M][MonitorCondition](by-class/MonitorCondition.md), [UID:0000BX][RequestSyncGate](by-class/RequestSyncGate.md), [UID:0000C1][RingBuffer](by-class/RingBuffer.md), [UID:0000EV][Thread](by-class/Thread.md)

## Changes

- 2026-08-15 B004 UID0000LI callback:
  - Raised to `94/95`, installed the authoritative Monitor.h declaration and Monitor.cpp include/child root, and attached exact children UID00051Y/000523/00051Z/000525 in positions 100-130.
  - The exact 16-byte layout is vptr `+0x00`, `HANDLE m_mutex +0x04`, `int m_waiterCount +0x08`, and `HANDLE m_semaphore +0x0c`. The one-slot vtable is generated by `virtual ~Monitor()`; UID000527 remains blank-code compiler support.
  - All nine Lock callers and nine Unlock callers remain documented in the exact children. RequestSyncGate is historical alias evidence only.

- 2026-07-30 B006 UID0004EO post-Gate2 reconciliation:
  - Added the exact current 16-byte/four-member `Monitor` UDT readback, catalog-0375 backup/save identity, dependency order, and protected no-method/no-route-change disposition.
  - Preserved all method, caller, raw-destructor, vtable, source-route, and historical evidence; no IDA mutation occurred during this documentation pass.
- 2026-07-04 B009 UID0001CL callback:
  - Recorded `m_mutex`, `m_waiterCount`, and `m_semaphore`; accepted `0x00528710` / `0x00528720` as `Monitor::Lock` / `Monitor::Unlock`; represented raw `0x005286d0` as ordinary destructor source through UID0001CL; and kept `0x005288a0` as scalar-deleting destructor compiler-wrapper output.
  - Evidence: MCP session `eb7ce28b` reconfirmed sizes, callers, vtable refs, raw destructor bytes/no-xrefs, Win32 API behavior, and generated RingBuffer `mMonitor->Lock()` / `mMonitor->Unlock()` call shape.
  - No metadata change: source output is intentionally centralized in [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) to avoid duplicate class-page emission.
- 2026-06-07 A004 attachment/evidence refresh:
  - Before: scored `74/84` and left owner/emitter routing blank because the class was below the parent-attachment completion gate.
  - After: scored `80/86`, attached to [UID:0000LI][Monitor](by-file/Monitor.md), added exact method table entries for the raw non-deleting destructor and scalar deleting destructor, and documented vtable/field-offset evidence plus final-C++ blockers.
  - Evidence: [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) records live IDA-backed constructor/destructor ranges, raw cleanup body, `??_7Monitor@@6B@` refs, Win32 mutex/semaphore behavior, RingBuffer/Thread callers, and padding; [UID:0000LI][Monitor](by-file/Monitor.md) is `84/86` with valid `NexusTK/util/` placement.
- 2026-06-14 C001 Goal 2 refresh:
  - Before: score was `80/86`, parent-score and code-entry wording were stale, and the lock/unlock helpers were described only through related classes.
  - After: score is `86/88`; owner/emitter routing remains [UID:0000LI][Monitor](by-file/Monitor.md), and C++ remains blank.
  - Summary/evidence: current IDA MCP confirms constructor, lock helper, unlock helper, scalar destructor, raw destructor byte range, vtable refs, and RingBuffer/Thread caller sets. Final field names and API exposure remain open.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the monitor constructor at `0x005285e0` and scalar deleting destructor at `0x005288a0`. Owner/emitter routing was still left blank at that time because this class was below the then-active completion attachment gate even though [UID:0000LI][Monitor](by-file/Monitor.md) was the likely source-module parent.
- Completion/confidence score update: existed before as `0/0`; changed to `74/84`. Summary: the Win32 synchronization object has clear purpose, source placement, constructor/destructor ranges, caller evidence, and condition relationship, but lock/unlock exposure and final field names remain open. Evidence: linked monitor/condition memory cluster, `RingBuffer` and `Thread` constructor callers, `CreateMutexW`/`CreateSemaphoreW` failure behavior, and `MonitorCondition` wait/signal interactions.
