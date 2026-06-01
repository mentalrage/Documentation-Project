*** UID:0001QB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Crash Diagnostics

## Scope

This page tracks process crash reporting, deliberate crash triggers, and related diagnostic reporting paths. Exact source ownership lives in `by-file`; exact address ranges live in `by-memory`.

## Components

- [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md) installs the top-level unhandled-exception filter and writes crash reports.
- [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md) stores the active exception-handler object used by `TopLevelExceptionFilter`.
- [UID:0000II][Crasher](by-file/Crasher.md) is a small diagnostic [UID:0000A2][Pane](by-class/Pane.md) singleton that deliberately raises an exception through a null write.
- [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md) can send a diagnostic text packet through [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md) when timer skew is repeatedly detected.

## Observed Behavior

- `ExceptionHandler::ExceptionHandler` sets [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md), installs [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md), stores the previous filter, and clears crash-state fields.
- [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md) restores keyboard settings through [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md), checks [UID:0000QN][g_pCrashTarget](by-global/g_pCrashTarget.md), skips normal reporting if byte `[target + 4]` is already set, otherwise calls [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md).
- [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md) writes `BCrash.nfo`, records version, exception code, fault address, register state, and call stack. It attempts to use `IMAGEHLP.DLL` symbols through [UID:00014J][0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper](by-memory/0x004ac230-0x004ac4cb.ImageHlpStackWalkHelper.md) and falls back to frame-chain walking when symbol setup is unavailable.
- `Crasher::TriggerCrash` sets byte `[g_pCrashTarget + 4]` and writes marker `0x6675636b` through address zero.
- [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md) at [UID:0000YW][0x004673a0-0x004673b1.DestroyExceptionHandler](by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md) is a small helper used by resource/image load failure paths to destroy the active exception handler before fatal shutdown. IDA caller checks show it is paired with [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md).

## Open Questions

- Whether `Crasher` was a hidden UI/debug pane, a retained developer helper, or a deliberate suppress-report crash path.
- Final source grouping for `Crasher`: separate `platform/Crasher.cpp`, private class in `ExceptionHandler.cpp`, or diagnostics folder.
- Exact ownership for [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md); it is currently best treated as exception/diagnostics infrastructure called from timer-skew detection.
- Whether all crash-report helper bodies in `0x004abd10-0x004ac4cb` should remain in [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md) or split into local utility functions.

## Cross-References

- [UID:0000J8][ExceptionHandler](by-file/ExceptionHandler.md)
- [UID:00004P][ExceptionHandler](by-class/ExceptionHandler.md)
- [UID:00014D][0x004ab480-0x004ac89a.ExceptionHandler](by-memory/0x004ab480-0x004ac89a.ExceptionHandler.md)
- [UID:00014E][0x004ab740-0x004ab804.CrashDiagnosticTextSender](by-memory/0x004ab740-0x004ab804.CrashDiagnosticTextSender.md)
- [UID:00014F][0x004ab830-0x004ab86f.TopLevelExceptionFilter](by-memory/0x004ab830-0x004ab86f.TopLevelExceptionFilter.md)
- [UID:00014G][0x004ab870-0x004abd10.ExceptionCrashReportWriter](by-memory/0x004ab870-0x004abd10.ExceptionCrashReportWriter.md)
- [UID:00014H][0x004abd10-0x004abe4a.ExceptionCodeStringHelper](by-memory/0x004abd10-0x004abe4a.ExceptionCodeStringHelper.md)
- [UID:00014I][0x004abfa0-0x004ac035.ExceptionLogicalAddressHelper](by-memory/0x004abfa0-0x004ac035.ExceptionLogicalAddressHelper.md)
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
