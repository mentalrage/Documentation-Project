*** UID:0000LI | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Monitor

## Status

- Proposed module: `util/Monitor.cpp`
- Proposed header: `util/Monitor.h`
- Confidence: strong for synchronization ownership and the resolved Monitor/CriticalSection source-file split; medium-high only for original private spelling and exact header token style.

## File Role

The `Monitor.cpp` / `Monitor.h` pair is the shared mutex/semaphore synchronization module. `Monitor.h` owns the complete `Monitor` / `MonitorCondition` declarations; `Monitor.cpp` includes that header plus `Error.h` and owns their eight handwritten method bodies. Historical RequestSyncGate labels remain provenance only. CriticalSection and CriticalSectionLock are now resolved to the separate [UID:00051U][CriticalSection](by-file/CriticalSection.md) module and must not enter Monitor output.

This code is lower-level than `Thread.cpp`: [UID:0000OR][Thread](by-file/Thread.md) and [UID:0000N8][RingBuffer](by-file/RingBuffer.md) consume these primitives, but the primitives do not depend on those higher-level classes. `RingBuffer.cpp` includes `Monitor.h` because it constructs/deletes both classes and calls `Lock`, `Unlock`, `Wait`, and `Signal`.

## Likely Contents

- [UID:00008L][Monitor](by-class/Monitor.md)
- [UID:00008M][MonitorCondition](by-class/MonitorCondition.md)
- [UID:0000BX][RequestSyncGate](by-class/RequestSyncGate.md) as a non-emitting historical/recovered-output alias for `Monitor::Lock` / `Monitor::Unlock`
- exact method children UID00051Y, UID000523, UID00051Z, UID000525, UID00052A, UID00052E, UID000526, and UID00052B
- compiler-only children UID000527/UID00052C and vtable/RTTI support UID000528/UID00052D

## Evidence

- IDA MCP confirms the monitor/condition/gate cluster at `0x005285e0-0x00528929`.
- `Monitor::Monitor` creates an unnamed mutex and semaphore and throws `Win32Error` on handle creation failure.
- `RequestSyncGate::Lock` and `RequestSyncGate::Unlock` sit between `Monitor` and `MonitorCondition` in memory and operate on the same mutex/semaphore-style handle layout.
- 2026-06-14 live IDA MCP reconfirmed the exact cluster method inventory: `Monitor` constructor `0x005285e0` size `0xe8`, RequestSyncGate wait/release helpers `0x00528710` size `0x0c` and `0x00528720` size `0x1e`, `MonitorCondition` constructor `0x00528740` size `0xa0`, wait helper `0x00528810` size `0x45`, signal helper `0x00528860` size `0x32`, and scalar deleting destructors `0x005288a0` size `0x4e` and `0x005288f0` size `0x39`.
- The same live pass confirmed the `RequestSyncGate` helpers are paired at all observed call sites, with shared callers in the `0x00556580`/`0x005565f0` synchronization paths and the `0x00596400` through `0x00596a00` request-wait family.
- 2026-06-16 A001 live IDA/PE refresh reconfirmed the same function inventory plus the raw non-deleting destructor byte islands at `0x005286d0` and `0x005287f0`: both starts are still not IDA function objects, have no xrefs, and have no section-mapped PE VA/RVA/direct-branch hits. The same pass expanded the RequestSyncGate evidence to nine lock refs and nine unlock refs across the RingBuffer and Thread synchronization families.
- `MonitorCondition::Wait` releases the parent monitor lock while waiting on the condition semaphore, then reacquires monitor state by decrementing the condition waiter count.
- `MonitorCondition::Signal` releases one condition waiter and synchronizes through the monitor semaphore when waiters exist.
- Backward vtable data-flow from `0x0061fbe8` and `0x0061fbf0` reconfirms `Monitor` and `MonitorCondition` constructor/destructor stores inside the same cluster; no separate vtable exists for the tiny request gate helper.
- [UID:000226][0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers](by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md) and `CriticalSectionLock` at `0x0049bcf0-0x0049bd19` are not memory-adjacent to the monitor cluster, but they are tiny Win32 critical-section synchronization helpers. The RAII lock has application message-loop callers.
- 2026-06-16 A001 rechecked the critical-section companion pages: `0x0049bcb0` remains the modeled initialize wrapper, `0x0049bcc0` is only reached by the static cleanup jump, `0x0049bcd0`/`0x0049bce0` have no direct xrefs, and `CriticalSectionLock` has two constructor/destructor caller pairs in application message-loop/request-exit code.
- 2026-07-05 B003 current MCP callback evidence promotes [UID:000226][0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers](by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md) from an empty marker to first-draft source through this Monitor route. The accepted source shape is a `CriticalSection` utility class with constructor/destructor/enter/leave methods over a `CRITICAL_SECTION` member at offset zero. Current MCP reconfirmed `sub_49BCB0` size `0xe`, the cleanup-tail delete wrapper at `0x0049bcc0`, raw enter/leave bodies at `0x0049bcd0`/`0x0049bce0`, static storage refs at `0x0067a9a4`, and zero current direct xrefs or VA/RVA pointer hits for the raw enter/leave starts.
- 2026-07-04 B009 callback evidence from MCP session `eb7ce28b` makes [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) source-ready through this module: modeled starts/sizes are `0x005285e0`/`0xe8`, `0x00528710`/`0x0c`, `0x00528720`/`0x1e`, `0x00528740`/`0xa0`, `0x00528810`/`0x45`, `0x00528860`/`0x32`, `0x005288a0`/`0x4e`, and `0x005288f0`/`0x39`; raw non-function ordinary destructors remain at `0x005286d0` and `0x005287f0`; vtables `0x0061fbe8` and `0x0061fbf0` tie constructors, raw destructors, and scalar wrappers to `Monitor` and `MonitorCondition`.
- The same B009 pass resolves `0x00528710` and `0x00528720` as `Monitor::Lock` and `Monitor::Unlock` source methods. Older `RequestSyncGate::Lock` / `RequestSyncGate::Unlock` labels describe the same bytes and layout but should not emit duplicate C++ because no separate vtable, constructor, or independent source route proves a distinct class.
- Current generated `RingBuffer` source already uses the intended consumer-facing API: `new Monitor`, `new MonitorCondition(mMonitor)`, `mMonitor->Lock()`, `mMonitor->Unlock()`, `MonitorCondition::Wait()`, and `MonitorCondition::Signal()`.

## Recovery Caveats

UID0001CL now supplies the source-quality declaration plan and formal source block for the monitor/condition cluster. IDA confirms real methods at:

- `0x00528740`: `MonitorCondition` constructor
- `0x00528810`: wait helper
- `0x00528860`: signal helper

The former UID000226/UID00012A/UID00003C Monitor route is superseded. Fresh whole-file neighborhood analysis resolves those items to `CriticalSection.cpp/.h`; their older placement remains historical evidence only and no longer caps Monitor source completion.

## Historical Generated-Output Defect And Resolution

Before the 2026-08-15 UID0000LI whole-file callback, validator-generated `Monitor.cpp` was malformed as a source reconstruction even where individual recovered bodies were behaviorally useful. The broad Monitor route mixed the nonadjacent low-address `CriticalSection` and `CriticalSectionLock` definitions from `[0x0049bcb0,0x0049bd19)` into the distant Monitor/MonitorCondition cluster at `[0x005285e0,0x00528929)`. That output reflected a documentation-owner conflation based on shared synchronization semantics rather than the binary's compilation-unit neighborhoods.

The same pre-callback route was incomplete at the declaration and emitter levels. Broad UID000226/UID00012A/UID0001CL pages were treated as source containers while exact ordinary destructors, raw Enter/Leave bodies, compiler scalar wrappers, vtable data, and the Application-owned static lacked a complete split-child route. `CriticalSection`/`CriticalSectionLock` declarations and definitions were therefore interleaved with Monitor output or represented by incomplete/empty routes, and the generated file could not establish two coherent human-authored module pairs.

The callback corrected rather than erased that historical defect. Exact source-bearing children now route through their direct classes and file roots; broad aggregates are non-emitting indexes; `Monitor.cpp/.h` contains only Monitor and MonitorCondition; `CriticalSection.cpp/.h` contains CriticalSection and CriticalSectionLock; compiler wrappers and vtable/RTTI data remain declaration-generated with blank handwritten source; and the 24-byte Application static remains Application-owned. A coherent validator regeneration then produced separate complete module pairs with no CriticalSection definition, declaration fragment, empty marker, or duplicate RequestSyncGate source in Monitor output. The polluted pre-callback output remains documented here as the reason the split/root regeneration was required, while the separate-root output is the current good state.

## Source-Structure Decision

Use `util/Monitor.cpp` and `util/Monitor.h` only for Monitor and MonitorCondition. Exact child definitions emit through class UIDs 00008L/00008M; class pages own declarations. UID0001CL is a non-emitting index. The separate `util/CriticalSection.cpp/.h` root owns CriticalSection and CriticalSectionLock.

The authoritative source-authored declarations emitted through `NexusTK/util/Monitor.h` are:

```cpp
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
```

Scalar-deleting destructor wrappers remain compiler-generated output from ordinary destructors and vtables. `RequestSyncGate` remains a compatibility/support page for older recovered output and Thread-result-gate wording, not a separate source root for `0x00528710` / `0x00528720`.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `94` | Complete Monitor-only file inventory, ten exact source/compiler children, two class layouts, vtable/RTTI support, callers, imports, padding, CPP/H, pointer throws, compiler exclusions, and generated closure plan are documented. |
| Confidence `94` | Behavior, ranges, layouts, source order, consumers, and the CriticalSection split are independently supported. Original private spelling and exact header token style remain inferred. |

## Cross-References

- [UID:00008L][Monitor](by-class/Monitor.md)
- [UID:00008M][MonitorCondition](by-class/MonitorCondition.md)
- [UID:0000BX][RequestSyncGate](by-class/RequestSyncGate.md)
- [UID:00003C][CriticalSectionLock](by-class/CriticalSectionLock.md)
- [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md)
- [UID:000226][0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers](by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md)
- [UID:00012A][0x0049bcf0-0x0049bd19.CriticalSectionLock](by-memory/0x0049bcf0-0x0049bd19.CriticalSectionLock.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0000N8][RingBuffer](by-file/RingBuffer.md)
- [UID:0001QT][client_threading](by-meta/client_threading.md)

## Changes

- 2026-08-15 B004 UID0000LI whole-file implementation callback:
  - Resolved the former broad synchronization grouping into two exact source pairs. This file now owns only Monitor and MonitorCondition over `[0x005285e0,0x00528929)`; [UID:00051U][CriticalSection](by-file/CriticalSection.md) owns `[0x0049bcb0,0x0049bd19)` and its RAII guard.
  - Created exact children [UID:00051Y][0x005285e0-0x005286c8.MonitorConstructor](by-memory/0x005285e0-0x005286c8.MonitorConstructor.md), [UID:000523][0x005286d0-0x00528705.MonitorDestructorRaw](by-memory/0x005286d0-0x00528705.MonitorDestructorRaw.md), [UID:00051Z][0x00528710-0x0052871c.MonitorLock](by-memory/0x00528710-0x0052871c.MonitorLock.md), [UID:000525][0x00528720-0x0052873e.MonitorUnlock](by-memory/0x00528720-0x0052873e.MonitorUnlock.md), [UID:00052A][0x00528740-0x005287e0.MonitorConditionConstructor](by-memory/0x00528740-0x005287e0.MonitorConditionConstructor.md), [UID:00052E][0x005287f0-0x00528810.MonitorConditionDestructorRaw](by-memory/0x005287f0-0x00528810.MonitorConditionDestructorRaw.md), [UID:000526][0x00528810-0x00528855.MonitorConditionWait](by-memory/0x00528810-0x00528855.MonitorConditionWait.md), [UID:00052B][0x00528860-0x00528892.MonitorConditionSignal](by-memory/0x00528860-0x00528892.MonitorConditionSignal.md), and compiler-only wrappers [UID:000527][0x005288a0-0x005288ee.MonitorScalarDeletingDestructor](by-memory/0x005288a0-0x005288ee.MonitorScalarDeletingDestructor.md) / [UID:00052C][0x005288f0-0x00528929.MonitorConditionScalarDeletingDestructor](by-memory/0x005288f0-0x00528929.MonitorConditionScalarDeletingDestructor.md).
  - Added exact compiler-data support [UID:000528][0x0061fbe4-0x0061fbf4.MonitorVtableData](by-memory/0x0061fbe4-0x0061fbf4.MonitorVtableData.md) and [UID:00052D][MonitorVtables](by-type/by-vtable/MonitorVtables.md). They remain non-emitting because complete virtual class declarations regenerate the two one-slot vtables and self-only RTTI.
  - Formal `Monitor.cpp` now contains only the include preamble and eight handwritten method definitions in binary/source order. Formal `Monitor.h` contains the exact two 16-byte class declarations. Pointer-form `Win32Error` throws, raw ordinary destructors, all caller sets, nineteen padding/support spans, and compiler exclusions are preserved at full detail.
  - Historical CriticalSection/RequestSyncGate placement above remains as superseded provenance. `RequestSyncGate` is not a separate source class, and no CriticalSection body may remain in generated Monitor output.

## Current Complete File Inventory

- Source boundary: `[0x005285e0,0x00528929)` with ten exact children and internal non-source alignment at `[0x005286c8,0x005286d0)`, `[0x00528705,0x00528710)`, `[0x0052871c,0x00528720)`, `[0x0052873e,0x00528740)`, `[0x005287e0,0x005287f0)`, `[0x00528855,0x00528860)`, `[0x00528892,0x005288a0)`, and `[0x005288ee,0x005288f0)`.
- File boundaries: predecessor `[0x005285dd,0x005285e0)` and successor `[0x00528929,0x00528930)` are alignment; MiscWorkThread and MonsterImageLibTables remain separate.
- Handwritten definitions: Monitor constructor/destructor/Lock/Unlock followed by MonitorCondition constructor/destructor/Wait/Signal.
- Compiler products: two scalar-deleting wrappers and the exact four-cell vtable/COL run; none emits handwritten CPP.
- Imports: `CreateMutexW`, `CreateSemaphoreW`, `CloseHandle`, `WaitForSingleObject`, `ReleaseMutex`, and `ReleaseSemaphore`; Win32Error remains owned by Error.
- Consumers: RingBuffer constructs one Monitor and two conditions; Thread-family code constructs and pairs Monitor Lock/Unlock. No file-owned string, resource, global, static, or independent table exists.

- 2026-07-31 B006 UID0001G4 dependency-route callback:
  - Documented the exact `Monitor.cpp` / `Monitor.h` pair, header-owned declarations, CPP-owned method definitions, and RingBuffer consumer include route.
  - Reconciled the declaration example to the accepted `<windows.h>`, forward declaration, virtual destructor, friend, and exact 0x10-field form without changing helper ownership or behavior.
  - Preserved the broader CriticalSection/CriticalSectionLock split caveat, RequestSyncGate no-duplicate role, raw destructor evidence, and compiler-wrapper exclusions.
- 2026-07-05 B004 UID00012A implementation callback:
  - Recorded `CriticalSectionLock` as source-ready through the existing Monitor route and left the Monitor file score unchanged at `86/88`.
  - Preserved UID000226 as already source-ready at `88/91`; after scoped validation, generated `Monitor.cpp` should retain UID000226 source and replace UID00003C/UID00012A empty markers with the accepted `CriticalSectionLock` declaration and method bodies.
  - The exact original split between Monitor and a possible critical-section companion file remains a file-level confidence cap.
- 2026-07-05 B003 UID000226 implementation callback:
  - Recorded [UID:000226][0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers](by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md) as source-ready `CriticalSection` utility methods emitted through this module. The generated `Monitor.cpp` UID000226 entry should no longer be an empty marker after scoped validation refresh.
  - No file-score change in this callback: the broader `CriticalSectionLock`/header/source split still caps the Monitor file below 90, even though the UID000226 empty-emitter blocker is resolved.
- 2026-07-04 B009 UID0001CL implementation callback:
  - Recorded [UID:0001CL][0x005285e0-0x00528929.MonitorAndConditions](by-memory/0x005285e0-0x00528929.MonitorAndConditions.md) as source-ready/source-emitting through this module, with MCP session `eb7ce28b` starts/sizes, raw ordinary destructor starts, vtable refs, caller/callee evidence, byte-boundary evidence, generated RingBuffer call shape, and formal `Monitor` / `MonitorCondition` declaration plan.
  - Historicalized `RequestSyncGate` as compatibility alias/support for `0x00528710` / `0x00528720`; `Monitor::Lock` / `Monitor::Unlock` own the source bodies and `RequestSyncGate` must not duplicate them.
  - No file-score change: the broader `CriticalSectionLock` split remains the file-level cap, but it no longer blocks UID0001CL source output.
- 2026-06-16 A001 file-completion refresh:
  - Before: scored `85/86`.
  - After: scored `86/88`.
  - Evidence: live IDA MCP and section-mapped PE scanning reconfirmed the Monitor/RequestSyncGate/MonitorCondition inventory, raw destructor non-function/no-xref/no-pointer-hit status, nine paired gate lock/unlock caller refs, vtable data-flow anchors, and critical-section wrapper/RAII-lock companion evidence.
  - Scope: owner remains the file source root `NexusTK/util/Monitor.cpp`; no IDA DB renames/comments were applied because the remaining blocker is original source placement/helper naming rather than local disassembly ambiguity.
- 2026-06-14 A001 Goal 2 parent-gate refresh:
  - Before: scored `84/86`.
  - After: scored `85/86`.
  - Why: live IDA MCP reconfirmed the exact `0x005285e0-0x00528929` method inventory, RequestSyncGate paired caller family, and Monitor/MonitorCondition vtable-store data flow, which removes the remaining documentation gap blocking this file from the active `85/85` direct-parent gate. Confidence remains unchanged because the final `CriticalSectionLock` split is still provisional.
- 2026-06-05:
  - Before: scored `82/82`.
  - After: scored `84/86`.
  - Why: removed stale recovered-output wording, converted the remaining output caveats into source-facing recovery caveats, and synced the attached critical-section wrapper evidence to the now-strong `82/90` memory page.
- 2026-06-02:
  - Before: scored `80/78`.
  - After: scored `82/82`.
  - Why: the exact monitor/condition/gate cluster, valid `NexusTK/util/` path, generated-output caveats, and lower-level synchronization role are now sufficient for child attachment; the only remaining uncertainty is final split from `CriticalSectionLock`.
- Before: this file only mentioned `CriticalSectionLock` at `0x0049bcf0-0x0049bd19` as the low-address synchronization helper.
- Changed to: include the adjacent critical-section API wrapper family at `0x0049bcb0-0x0049bce8`.
- Summary/evidence: IDA MCP/raw disassembly shows wrappers for `InitializeCriticalSection`, `DeleteCriticalSection`, `EnterCriticalSection`, and `LeaveCriticalSection` immediately before the RAII lock constructor/destructor.

- Before: the monitor/condition cluster was recorded as ending at `0x00528928`.
- Changed to: the cluster ends at `0x00528929`.
- Summary/evidence: 2026-05-28 IDA MCP shows `MonitorCondition::ScalarDeletingDestructor` ends at `0x00528929`; `0x00528928` is the final `retn 4` operand byte.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `80`, confidence `78`.
- Summary/evidence: the page documents synchronization ownership, contained classes, IDA evidence, recovery caveats, and range corrections; confidence remains medium-high because the original source-file split for `CriticalSectionLock` versus monitor primitives is still unresolved.
