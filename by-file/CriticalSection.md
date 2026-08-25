*** UID:00051U | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# CriticalSection

## Status

- Reconstruction source: `NexusTK/util/CriticalSection.cpp`.
- Reconstruction header: `NexusTK/util/CriticalSection.h`.
- Confidence: very strong for the separate utility-module split, exact method inventory, class layouts, Application dependency, and complete CPP/H route. Original private spelling and pointer-versus-reference style remain inferred.

## File Role

This source pair owns the narrow Win32 `CRITICAL_SECTION` wrapper and its four-byte RAII guard. It is separate from [UID:0000LI][Monitor](by-file/Monitor.md): the CriticalSection methods form the contiguous low-address source family `[0x0049bcb0,0x0049bd19)`, whereas Monitor and MonitorCondition form the independent `[0x005285e0,0x00528929)` mutex/semaphore family. Application owns the static CriticalSection instance used to protect its active message-handler pointer; this utility module owns only the reusable types and methods.

## Complete Inventory And Source Order

1. [UID:00051V][CriticalSection](by-class/CriticalSection.md) declaration, include preamble, and constructor/destructor/Enter/Leave child route.
2. [UID:00003C][CriticalSectionLock](by-class/CriticalSectionLock.md) declaration and constructor/destructor child route.
3. [UID:000226][0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers](by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md) as a non-emitting exact-child index.
4. [UID:00012A][0x0049bcf0-0x0049bd19.CriticalSectionLock](by-memory/0x0049bcf0-0x0049bd19.CriticalSectionLock.md) as a non-emitting exact-child index.
5. Exact children [UID:000520][0x0049bcb0-0x0049bcbe.CriticalSectionConstructor](by-memory/0x0049bcb0-0x0049bcbe.CriticalSectionConstructor.md), [UID:00051W][0x0049bcc0-0x0049bcc8.CriticalSectionDestructorSharedTail](by-memory/0x0049bcc0-0x0049bcc8.CriticalSectionDestructorSharedTail.md), [UID:000524][0x0049bcd0-0x0049bcd8.CriticalSectionEnterRaw](by-memory/0x0049bcd0-0x0049bcd8.CriticalSectionEnterRaw.md), [UID:000521][0x0049bce0-0x0049bce8.CriticalSectionLeaveRaw](by-memory/0x0049bce0-0x0049bce8.CriticalSectionLeaveRaw.md), [UID:00051X][0x0049bcf0-0x0049bd09.CriticalSectionLockConstructor](by-memory/0x0049bcf0-0x0049bd09.CriticalSectionLockConstructor.md), and [UID:000522][0x0049bd10-0x0049bd19.CriticalSectionLockDestructor](by-memory/0x0049bd10-0x0049bd19.CriticalSectionLockDestructor.md). Padding and the DATFileMgr successor remain outside source output.

The source order is CriticalSection constructor, destructor, Enter, Leave, then CriticalSectionLock constructor and destructor. The constructor at `0x0049bcb0` has the Application static-init caller `0x00419ec5`; the tail-shared destructor body at `0x0049bcc0` is reached from cleanup thunk `0x0060c0e5`; Enter and Leave have no out-of-line callers because their RAII uses were inlined; the lock constructor/destructor have paired callers at `0x00464db7`/`0x00464dc5` and `0x00465666`/`0x00465677`.

## Layout And Behavior

- `CriticalSection` is exactly 24 bytes and contains one `CRITICAL_SECTION m_section` at offset zero.
- Construction calls `InitializeCriticalSection`; destruction calls `DeleteCriticalSection`.
- `Enter` and `Leave` call the corresponding Win32 APIs on `m_section`.
- `CriticalSectionLock` is exactly four bytes and stores a non-owning `CriticalSection *m_criticalSection` at offset zero.
- The RAII constructor stores the pointer and calls `Enter`; the destructor calls `Leave`. No ownership transfer, null check, or extra state is introduced.
- The Application static occupies `[0x0067a9a4,0x0067a9bc)` and remains Application-owned. The following `[0x0067a9bc,0x0067a9c0)` is alignment, not another member.

## Boundary And Negative Evidence

- `[0x0049bca9,0x0049bcb0)`, `[0x0049bcbe,0x0049bcc0)`, `[0x0049bcc8,0x0049bcd0)`, `[0x0049bcd8,0x0049bce0)`, `[0x0049bce8,0x0049bcf0)`, `[0x0049bd09,0x0049bd10)`, and `[0x0049bd19,0x0049bd20)` are compiler/linker alignment.
- `[0x0049bd20,0x0049bd2c)` is a DATFileMgr forwarding thunk: it loads the DATFileMgr member at `this+4` and jumps to the DATFileMgr helper at `0x0049cad0`. It is not part of this source file.
- `[0x0049bd2c,0x0049bd30)` is DATFileMgr-side alignment.
- No vtable, RTTI, resource, string, table, or independent global is owned by this module. Both classes are non-polymorphic.
- The raw Enter/Leave bodies and tail-shared destructor are retained source methods despite their optimizer/linker shape; the source remains ordinary human C++ rather than raw labels or assembly wrappers.

## Dependencies And Consumers

- Header dependency: `<windows.h>` for `CRITICAL_SECTION` and Win32 synchronization APIs.
- Application consumers: [UID:0002H2][0x00464cd0-0x00464e1f.ApplicationRunMessageLoop](by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md) and [UID:0002GR][0x00465650-0x00465686.ApplicationExchangeMSGHandler](by-memory/0x00465650-0x00465686.ApplicationExchangeMSGHandler.md).
- Application static storage remains indexed by [UID:000292][0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics](by-memory/0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics.md).
- Monitor, RingBuffer, and Thread are separate synchronization modules and do not own these definitions.

## Reconstruction Route

The first class page emits `#include "CriticalSection.h"` and the CriticalSection methods; the companion CriticalSectionLock class emits its declaration and two method children afterward. Exact method pages own every body. Aggregate pages, alignment, and the DATFileMgr successor emit nothing.

The formal source is intentionally human-written Visual C++-era utility code: normal class declarations, an RAII guard, direct Win32 calls, and no IDA labels, explicit vtable arrays, raw frame variables, or decompiler scaffolding.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `94` | The page records the complete two-class/six-method inventory, exact boundaries and padding, Application static dependency, caller sets, source order, split decision, CPP/H route, and all no-code/exclusion dispositions. |
| Confidence `95` | Independent code-neighborhood, Win32 API, layout, caller, and Application-lifetime evidence prove the module split and behavior. Only unrecoverable original private spelling and pointer/reference source style remain inferred. |

## Changes

- 2026-08-15 B004 UID0000LI accepted implementation callback:
  - Created the separate `NexusTK/util/CriticalSection.cpp/.h` source root and removed the former provisional placement under Monitor.
  - Recorded all six exact source methods, two exact class layouts, Application dependency, optimizer/tail-sharing evidence, padding, DATFileMgr exclusion, and deterministic CPP/H assembly route without pruning historical evidence from existing support pages.
  - Validator assigned file UID00051U, class UID00051V, and method UIDs 000520/00051W/000524/000521/00051X/000522; all routes now use those literal identities.
