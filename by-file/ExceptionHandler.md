*** UID:0000J8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/platform/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ExceptionHandler

## Status

- Confidence: strong for class responsibility and helper-family ownership, medium for final folder placement.
- Proposed module: `platform/ExceptionHandler.cpp`
- Current Wave3 file: `class_ExceptionHandler.cpp`
- Main class: [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md)
- Main address docs: [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md)
- Evidence basis: `simroot_v2`, generated recovered output, and IDA MCP lookup/xref checks on 2026-05-23 and 2026-05-24.

## Responsibility

`ExceptionHandler` installs a process top-level exception filter, records crash-related state, writes `BCrash.nfo`, and restores the previous filter when destroyed. It is platform/process infrastructure rather than UI, render, or gameplay code.

## Likely Contents

- `ExceptionHandler` constructor at `0x004ab480`.
- [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md).
- [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) callback at `0x004ab830`.
- [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md) helper at [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md), currently best treated as app/resource failure cleanup that calls the active handler's deleting destructor.
- [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) packet helper at `0x004ab740`.
- [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md) at `0x004ab870`.
- [UID:00014H][0x004abd10-0x004abe4a.ExceptionCodeStringHelper](by-memory/0x004abd10-0x004abe4a.ExceptionCodeStringHelper.md), [UID:00014I][0x004abfa0-0x004ac035.ExceptionLogicalAddressHelper](by-memory/0x004abfa0-0x004ac035.ExceptionLogicalAddressHelper.md), and [UID:00014J][0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper](by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md).
- scalar deleting destructor at `0x004ac860`.
- companion [UID:0000II][Crasher](by-file/Crasher.md) class remains a separate file candidate, but depends on `g_pCrashTarget`.

## Evidence

- Generated source sets `g_pCrashTarget`, installs `ExceptionHandler_vtable`, calls `SetUnhandledExceptionFilter`, stores the previous filter, and clears crash-state fields.
- IDA MCP confirms `0x004ab480-0x004ab4ed`, `0x004ab740-0x004ab804`, `0x004ab830-0x004ab86f`, `0x004ab870-0x004abd10`, `0x004abd10-0x004abe4a`, `0x004abfa0-0x004ac035`, `0x004ac230-0x004ac4cb`, and `0x004ac860-0x004ac89a` as real functions.
- IDA caller evidence shows construction from the app startup region at `0x004639d0`.
- The crash-report helper writes `BCrash.nfo`, records exception code/fault address/registers, attempts `IMAGEHLP.DLL` symbol walking, and falls back to frame-chain walking.

## Placement Notes

Place under `platform/` for now because the implementation is Windows exception-filter and crash-report glue. If later caller/string evidence shows it is tied to the startup application shell, `app/ExceptionHandler.cpp` is also plausible.

## Open Questions

- Final source-level names/signatures for helper bodies at `0x004ab740`, `0x004ab870`, `0x004abd10`, `0x004abfa0`, and `0x004ac230`.
- Determine whether crash log formatting was private in this file or split into a diagnostics source.
- Confirm whether [UID:0000II][Crasher](by-file/Crasher.md) was an adjacent source file or private class in this module.
- Keep [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) separate even though `TopLevelExceptionFilter` restores keyboard settings during crash cleanup.

## Cross-References

- [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md)
- [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md)
- [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md)
- [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md)
- [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md)
- [UID:00014H][0x004abd10-0x004abe4a.ExceptionCodeStringHelper](by-memory/0x004abd10-0x004abe4a.ExceptionCodeStringHelper.md)
- [UID:00014I][0x004abfa0-0x004ac035.ExceptionLogicalAddressHelper](by-memory/0x004abfa0-0x004ac035.ExceptionLogicalAddressHelper.md)
- [UID:00014J][0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper](by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md)
- [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md)
- [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md)
- [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md)
- [UID:0000II][Crasher](by-file/Crasher.md)
- [UID:0001QB][client_crash_diagnostics](by-meta/client_crash_diagnostics.md)
- [UID:0000J5][Error](by-file/Error.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:82`.
  - Summary/evidence: process exception-filter role, likely contents, crash globals, report/filter/helper functions, IDA evidence, placement notes, Crasher/KeySpeed/Error boundaries, and open helper naming questions are documented; confidence is strong with final folder and Crasher colocation still medium.
