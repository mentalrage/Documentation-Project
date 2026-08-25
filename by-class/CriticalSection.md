*** UID:00051V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00051U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:00051U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "CriticalSection.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include <windows.h>

class CriticalSection
{
public:
    CriticalSection();
    ~CriticalSection();

    void Enter();
    void Leave();

private:
    CRITICAL_SECTION m_section;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# CriticalSection

## Summary

`CriticalSection` is the exact 24-byte non-polymorphic wrapper around one Win32 `CRITICAL_SECTION`. It owns initialization, deletion, enter, and leave methods and is emitted through [UID:00051U][CriticalSection](by-file/CriticalSection.md). The Application-owned static instance is a consumer, not class-owned storage.

## Layout

| Offset | Type | Source member | Evidence |
| --- | --- | --- | --- |
| `0x00` | `CRITICAL_SECTION` / 24 bytes | `m_section` | All four wrappers pass object address directly to the corresponding Win32 API; `_RTL_CRITICAL_SECTION` is exactly 24 bytes on this target. |

The object closes at `0x18` with no vptr, base class, tail member, or class-local padding. The separate four-byte alignment after the Application static does not enlarge this type.

## Exact Methods

| Range | Source method | Binary/source disposition |
| --- | --- | --- |
| [UID:000520][0x0049bcb0-0x0049bcbe.CriticalSectionConstructor](by-memory/0x0049bcb0-0x0049bcbe.CriticalSectionConstructor.md) | `CriticalSection::CriticalSection()` | Calls `InitializeCriticalSection(&m_section)`; one static-init caller at `0x00419ec5`. |
| [UID:00051W][0x0049bcc0-0x0049bcc8.CriticalSectionDestructorSharedTail](by-memory/0x0049bcc0-0x0049bcc8.CriticalSectionDestructorSharedTail.md) | `CriticalSection::~CriticalSection()` | Calls `DeleteCriticalSection(&m_section)`; retained source destructor with a linker-shared cleanup-tail route from `0x0060c0e5`. |
| [UID:000524][0x0049bcd0-0x0049bcd8.CriticalSectionEnterRaw](by-memory/0x0049bcd0-0x0049bcd8.CriticalSectionEnterRaw.md) | `CriticalSection::Enter()` | Calls `EnterCriticalSection(&m_section)`; complete raw body with zero inbound xrefs because observed guard uses were inlined. |
| [UID:000521][0x0049bce0-0x0049bce8.CriticalSectionLeaveRaw](by-memory/0x0049bce0-0x0049bce8.CriticalSectionLeaveRaw.md) | `CriticalSection::Leave()` | Calls `LeaveCriticalSection(&m_section)`; complete raw body with the same source/optimizer disposition. |

Exact method pages own the CPP definitions and attach as ordered children of this class. Declarations remain centralized in this H channel.

## Ownership And Relationships

- Direct file owner/emitter: [UID:00051U][CriticalSection](by-file/CriticalSection.md).
- Same-file companion: [UID:00003C][CriticalSectionLock](by-class/CriticalSectionLock.md), which stores a non-owning pointer and brackets a scope with Enter/Leave.
- Aggregate index: [UID:000226][0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers](by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md), retained as non-emitting after child split.
- Application static index: [UID:000292][0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics](by-memory/0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics.md).

## Source-Quality Decisions

- `CriticalSection` is preferred over IDA-style wrapper labels because the exact wrapped type and all four API operations are proven.
- `m_section` follows project `m_` field style and is the highest-probability human source name; exact private spelling is not recoverable from the binary.
- The class is non-virtual. No explicit vtable, RTTI, scalar-deleting wrapper, copy operation, ownership transfer, or null guard belongs in source.
- The formal H block is authoritative. CPP definitions belong only to exact method children so the aggregate cannot duplicate them.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `94` | Exact size/layout, all four methods, caller/optimizer/tail-sharing evidence, owner/emitter route, Application consumer, source/no-code decisions, and complete H declaration are recorded. |
| Confidence `95` | Behavior and layout are direct; only original private spelling and source formatting remain inferred. |

## Changes

- 2026-08-15 child UID reconciliation: constructor [UID:000520][0x0049bcb0-0x0049bcbe.CriticalSectionConstructor](by-memory/0x0049bcb0-0x0049bcbe.CriticalSectionConstructor.md), destructor [UID:00051W][0x0049bcc0-0x0049bcc8.CriticalSectionDestructorSharedTail](by-memory/0x0049bcc0-0x0049bcc8.CriticalSectionDestructorSharedTail.md), Enter [UID:000524][0x0049bcd0-0x0049bcd8.CriticalSectionEnterRaw](by-memory/0x0049bcd0-0x0049bcd8.CriticalSectionEnterRaw.md), and Leave [UID:000521][0x0049bce0-0x0049bce8.CriticalSectionLeaveRaw](by-memory/0x0049bce0-0x0049bce8.CriticalSectionLeaveRaw.md) are the ordered CPP children.

- 2026-08-15 B004 UID0000LI accepted implementation callback:
  - Created this exact class owner with the 24-byte layout, four-method inventory, separate CriticalSection module route, complete formal declaration, and ordered child insertion point.
