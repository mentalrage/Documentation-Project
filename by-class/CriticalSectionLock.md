*** UID:00003C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LI | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# CriticalSectionLock

## Summary

`CriticalSectionLock` is a small RAII helper around a caller-owned `CRITICAL_SECTION`. The constructor enters the critical section and the destructor leaves it.

## Likely Original Placement

- Source: [UID:0000LI][Monitor](by-file/Monitor.md) or a small adjacent utility header/source.
- Proposed path: `util/Monitor.cpp`
- Confidence: medium

## Methods

- `0x0049bcf0-0x0049bd09`: constructor.
- `0x0049bd10-0x0049bd19`: destructor.
- Related low-level API wrappers: [UID:000226][0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers](by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md).

## Evidence

- IDA confirms the two-function range exactly.
- Constructor callers include `Application::RunMessageLoop`-area code at `0x00464db7` and message-handler exchange code at `0x00465666`.
- Generated source behavior is direct Win32 RAII: `EnterCriticalSection` and `LeaveCriticalSection`.

## Open Questions

- Whether this class was header-only in original source and materialized because methods were not inlined.
- Whether final migration should keep it in `Monitor.cpp`, `PlatformApi.cpp`, or an application synchronization helper file.

## Cross-References

- File: [UID:0000LI][Monitor](by-file/Monitor.md)
- Critical-section API wrappers: [UID:000226][0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers](by-memory/0x0049bcb0-0x0049bce8.CriticalSectionApiWrappers.md)
- Memory: [UID:00012A][0x0049bcf0-0x0049bd19.CriticalSectionLock](by-memory/0x0049bcf0-0x0049bd19.CriticalSectionLock.md)
- Related: [UID:0000HG][Application](by-file/Application.md), [UID:00008L][Monitor](by-class/Monitor.md)

## Changes

- Before: this class page only listed the RAII constructor/destructor methods.
- Changed to: cross-reference the adjacent critical-section API wrapper family.
- Summary/evidence: IDA MCP/raw disassembly shows the Win32 critical-section wrapper helpers immediately before the RAII lock method pair.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `84/86`.
  - Summary/evidence: the item is small and the constructor/destructor behavior, bounds, callers, API wrappers, and placement uncertainty are already documented; remaining uncertainty is mostly whether the original implementation lived in a header or a nearby monitor/platform source.
