*** UID:0001QB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Crash Diagnostics

## Scope

This page tracks process crash reporting, deliberate crash triggers, and related diagnostic reporting paths. Exact source ownership lives in `by-file`; exact address ranges live in `by-memory`.

## Components

- [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md) installs the top-level unhandled-exception filter and writes crash reports.
- [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) stores the active exception-handler object used by `TopLevelExceptionFilter`.
- [UID:0000II][Crasher](by-file/Crasher.md) is a small diagnostic [UID:0000A2][Pane](by-class/Pane.md) singleton that deliberately raises an exception through a null write. Current source-placement evidence favors keeping it as separate `platform/Crasher.cpp`, companion to but not merged into [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md).
- [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md) can send a diagnostic text packet through [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) when timer skew is repeatedly detected.
- [UID:00014I][0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress](by-memory/0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress.md) is private static `bool ExceptionHandler::GetLogicalAddress(PVOID, PTSTR, DWORD, DWORD &, DWORD &)`, the source-ready address-to-module/section helper used six times by the report writer, raw formatters, and ImageHlp stack-walk path.
- [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md) is source-ready `void ExceptionHandler::GenerateExceptionReport(EXCEPTION_POINTERS *)` and owns the Windows-directory `BCrash.nfo` report behavior.
- [UID:0004WT][0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions](by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md), [UID:0004WU][0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk](by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md), and [UID:00014J][0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper](by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md) are the exact source-ready ImageHlp resolver, x86 EBP fallback, and symbol-aware stack-walk member children.

## Observed Behavior

- `ExceptionHandler::ExceptionHandler` sets [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md), installs [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md), stores the previous filter, and clears crash-state fields.
- [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) is first-draft C++ ready as `static LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS *)`. It restores keyboard settings through [UID:0000RB][g_pKeySpeedMgr](by-global/g_pKeySpeedMgr.md) / [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md), checks [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md), skips normal reporting and previous-filter chaining if `m_skipCrashReport` at object offset `+0x04` is set, otherwise calls [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md) and then chains through `m_previousFilter` at object offset `+0x08` when present. The suppressed/no-target/no-previous-filter paths return `EXCEPTION_CONTINUE_SEARCH` / `0`.
- [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md) obtains the Windows directory through `GetWindowsDirectoryW`, builds `BCrash.nfo`, records version, exception/fault/register/timer/phase/RGB565 state, and preserves the original duplicate exception-string call and unconditional separator write even if file open failed. It calls [UID:0004WT][0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions](by-memory/0x004ac040-0x004ac0ed.ExceptionHandlerInitImagehlpFunctions.md), then [UID:00014J][0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper](by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md) and `m_symCleanup` on success, or [UID:0004WU][0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk](by-memory/0x004ac0f0-0x004ac221.ExceptionHandlerIntelStackWalk.md) on failure. The first two helpers have retained zero-xref definitions because their calls were inlined into the target; they remain ordinary source methods.
- UID00014I calls `VirtualQuery`, then the PlatformApi-owned `GetModuleFileNameW` dispatch through source-facing generic `GetModuleFileName`, and walks DOS/NT/section headers. It uses inclusive `max(SizeOfRawData, Misc.VirtualSize)` containment and writes a one-based section number plus section-relative offset only on success.
- The six direct calls are `0x004ab939`, `0x004abc52`, `0x004ac190`, `0x004ac3e1`, `0x004ac440`, and `0x004ac7b4`. Four are in modeled writer/stack-walk functions and two are in raw parent-contained formatters. Every call passes capacity `0x104` / 260 characters and ignores the Boolean result.
- Caller initialization is intentionally nonuniform: the first fault-address writer call leaves module/section/offset uninitialized; later fallback paths generally zero them; the repeated ImageHlp call at `0x004ac440` resets module and offset while retaining the prior section. The helper itself does not clear outputs, so failure before `VirtualQuery` leaves everything untouched and later PE failure can leave module text populated while DWORD outputs retain caller state.
- [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) is best treated as nonvirtual `ExceptionHandler::SendCrashDiagnosticText(const char *)` emitted through [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md). It is called by Application timer-skew diagnostics after the human-readable ANSI text is already formatted; caller `0x00466e80` passes [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) in `ECX`, pushes the formatted text as the sole explicit argument, and then sets the one-shot report-sent latch at `0x0067ab6c`. The helper accepts lengths `1..0xFFF`, writes `{0x42, 0x01, length16be, payload, 0}`, sends `length + 5` through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / Socket-owned `QueueAndSendPacket`, and rejects Application, direct file-static ownership, Socket, PacketBuffer, CashShopRequest, and a new `CrashDiagnostics.cpp` file as direct owners.
- `Crasher::TriggerCrash` is reached through the tertiary `+0xa4` Pane event/update vtable slot `0x006188dc`, sets the `ExceptionHandler` offset `+4` byte now best named descriptively as `m_skipCrashReport`, and writes marker `0x6675636b` through address zero. B015 closes this for draft source shape: [UID:0000II][Crasher](by-file/Crasher.md) stays a separate `platform/Crasher.cpp` companion, with source-authored constructor, ordinary destructor, and trigger callback bodies; vtables, RTTI/COL data, destructor adjustors, scalar deleting destructor glue, and raw vtable stores are compiler output.
- [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md) at [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md) is a small helper used by resource/image load failure paths to destroy the active exception handler before fatal shutdown. IDA caller checks show it is paired with [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md); B001-013 assigns the helper body to [UID:0000HG][Application](by-file/Application.md) fatal-load cleanup while [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md) keeps [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) and normal crash-handler lifecycle ownership.

## Open Questions

- Closed for draft source: [UID:00003A][Crasher](by-class/Crasher.md) stays in separate [UID:0000II][Crasher](by-file/Crasher.md) unless future source-order evidence proves colocation with [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md); [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md) offset `+0x04` is `m_skipCrashReport`; Crasher constructor/destructor/trigger bodies are first-draft ready.
- Exact higher-level event/timer/hidden command path that dispatches through the tertiary Pane callback to `Crasher::TriggerCrash`.
- Final source-facing name for the Pane callback that dispatches to `Crasher::TriggerCrash`.
- Project-wide source convention for singleton globals initialized in the image as `0xffffffff`, including [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md).
- Exact original spelling for [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) remains inferred. Current source placement is closed as `ExceptionHandler.cpp` member helper `ExceptionHandler::SendCrashDiagnosticText(const char *)`; the earlier file-static reading is retained only as a rejected historical assumption from callee-only evidence.
- Current best source placement keeps crash-report helpers in `platform/ExceptionHandler.cpp`; no separate diagnostics utility file is justified without new source-path, initializer, or non-ExceptionHandler caller evidence.
- [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) no longer has a child-body or report-method-name blocker; it calls `GenerateExceptionReport`. Remaining uncertainty is exact original linkage/access style. `Crasher.cpp`, `KeySpeedMgr.cpp`, Application, ImageHlp, packet, Error, CRT, and generic runtime exception code remain rejected as direct owners for the callback body.
- Closed for the report family: `GenerateExceptionReport`, `InitImagehlpFunctions`, `IntelStackWalk`, and `ImagehlpStackWalk` identities, exact child splits/formals, six callback typedefs, Windows-directory output, and retained-helper inlining are resolved. Dated `WriteCrashReport`, client/current-directory output, and generic raw-helper labels are historical only.
- Closed: `GetLogicalAddress` is not file-static and `0x0069be74` is not an unknown module helper. Exact source/header lineage proves private static class ownership, while current WideApi/PlatformApi evidence identifies `GetModuleFileNameW`. The remaining uncertainty is only descriptive local/parameter spelling and unrelated complete-class/raw-helper debt.

## Changes

- 2026-07-16 B003 GetLogicalAddress family synchronization:
  - Added the exact private static helper identity, six-call modeled/raw family role, one-based section/offset contract, inclusive PE extent, `GetModuleFileNameW` dependency, caller initialization differences, and failure-side mutation behavior.
  - Historicalized file-static, four-call, pointer-output, and unknown-module-helper wording without changing unrelated Crasher, timer-skew, filter, packet, Application cleanup, or diagnostic-source evidence.
- 2026-06-22 B015 Crasher class source-quality incorporation:
  - Updated [UID:00003A][Crasher](by-class/Crasher.md), [UID:0000II][Crasher](by-file/Crasher.md), and [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md) status after B015: Crasher source placement remains separate `platform/Crasher.cpp`, `ExceptionHandler +0x04` is closed for draft source as `m_skipCrashReport`, and first-draft constructor/destructor/trigger callback C++ is ready while callback dispatch spelling/path and singleton sentinel convention remain final-audit caps.
- 2026-06-20 B001/B015 TopLevelExceptionFilter child sync:
  - Historical snapshot: first-draft `TopLevelExceptionFilter` used descriptive `ExceptionHandler::WriteCrashReport`; the 2026-07-24 family closure supersedes that spelling with exact source identity `GenerateExceptionReport` while preserving all callback behavior and ownership conclusions.
- 2026-07-24 B001 GenerateExceptionReport family synchronization:
  - Added exact method/helper names, Windows-directory report placement, dynamic ImageHlp setup, six callback types, exact helper-child routes UID0004WT/UID0004WU/UID00014J, retained/inlined source shape, fallback/cleanup split, and Nexus-specific no-`FreeLibrary` and null-stream behavior.
- 2026-06-20 B005 CrashDiagnosticTextSender child sync:
  - Historical note: the B005 pass closed the [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) ownership question as direct file-static [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md) source, with first-draft C++ on the exact child page. B013 supersedes that direct-owner decision using caller-side `ECX` evidence.
- 2026-06-22 B013 CrashDiagnosticTextSender member-call correction:
  - Corrected [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) to `ExceptionHandler::SendCrashDiagnosticText(const char *)` under [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md), emitted via [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md). Remaining uncertainty is exact original method/API spelling, not behavior, source placement, or member-vs-file-static direction.

## Cross-References

- [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)
- [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md)
- [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md)
- [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md)
- [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md)
- [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md)
- [UID:00014H][0x004abd10-0x004abe4a.ExceptionHandlerGetExceptionString](by-memory/0x004abd10-0x004abe4a.ExceptionHandlerGetExceptionString.md)
- [UID:00014I][0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress](by-memory/0x004abfa0-0x004ac035.ExceptionHandlerGetLogicalAddress.md)
- [UID:00014J][0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper](by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md)
- [UID:0000II][Crasher](by-file/Crasher.md)
- [UID:000129][0x0049bae0-0x0049bbef.Crasher](by-memory/0x0049bae0-0x0049bbef.Crasher.md)
- [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md)
- [UID:0000QM][g_pCrasher](by-global/g_pCrasher.md)
- [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md)
- [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md)
- [UID:0000U8][CheckTimerSkewAndSendHeartbeat_466CA0](by-item/CheckTimerSkewAndSendHeartbeat_466CA0.md)
- [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md)
- [UID:0001QU][client_timing](by-meta/client_timing.md)
