*** UID:00004P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ExceptionHandler

## Status

- Confidence: strong for class responsibility, medium for final folder placement.
- Current Wave3 file: `class_ExceptionHandler.cpp`
- Likely source module: [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)
- Current range: [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md)
- Evidence basis: `simroot_v2`, Wave3 summary, and IDA MCP checks on 2026-05-23.

## Responsibility

`ExceptionHandler` is the process-level crash/exception filter object. It installs a top-level exception filter, owns the active crash target pointer, writes crash reports, and restores the previous filter on destruction.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x004ab480` | `ExceptionHandler` | Sets `g_pCrashTarget`, installs vtable, calls `SetUnhandledExceptionFilter`, and clears crash state. |
| [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) | diagnostic text sender candidate | Encodes and sends a diagnostic text packet; used by timer-skew detection. |
| [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) | `TopLevelExceptionFilter` | Restores keyboard settings, reads [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md), calls crash-report helper, and may chain to previous filter. |
| [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md) | crash-report writer candidate | Writes `BCrash.nfo`, exception/register data, and call stack. |
| [UID:00014H][0x004abd10-0x004abe4a.ExceptionCodeStringHelper](by-memory/0x004abd10-0x004abe4a.ExceptionCodeStringHelper.md) | exception-code string helper | Converts exception codes to wide diagnostic strings. |
| [UID:00014I][0x004abfa0-0x004ac035.ExceptionLogicalAddressHelper](by-memory/0x004abfa0-0x004ac035.ExceptionLogicalAddressHelper.md) | address/module helper | Resolves logical address/module text for crash reports. |
| [UID:00014J][0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper](by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md) | symbol stack-walk helper | Uses IMAGEHLP symbol APIs when available. |
| `0x004ac860` | `ScalarDeletingDestructor` | Restores the previous exception filter, clears `g_pCrashTarget`, and optionally deletes. |

## Ownership Notes

Place in `platform/ExceptionHandler.cpp` for now. Do not group it with generic imported C++ exception/runtime code. Keep [UID:00003A][Crasher](by-class/Crasher.md) as a companion class until source grouping is confirmed.

## Cross-References

- [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)
- [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md)
- [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md)
- [UID:00003A][Crasher](by-class/Crasher.md)
- [UID:0001QB][client_crash_diagnostics](by-meta/client_crash_diagnostics.md)
- [UID:0000J5][Error](by-file/Error.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/80`.
  - Summary/evidence: process exception-filter role, constructor, top-level filter, crash report/text/address/stack helpers, singleton/global ownership, and companion `Crasher` links are documented; remaining uncertainty is final folder placement and exact source-facing helper names.
