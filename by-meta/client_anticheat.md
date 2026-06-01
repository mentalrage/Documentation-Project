*** UID:0001Q7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Anticheat And Integrity Checks

## Status

- Scope: client-side anti-cheat, anti-virus/process scanning, suspicious-input controls, and anti-modification checks where they are visible in the recovered client.
- Confidence: medium for module placement, strong for the specific address ranges documented here.
- Current focus: class/file ownership and source-tree placement, not claiming final runtime effectiveness.

## Current Findings

- [UID:0000I6][CheatDetector](by-file/CheatDetector.md) is a small startup-created singleton at `0x00483f00-0x0048402c`. It registers [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md), constructs a timer-handler style base, exposes a vtable slot that currently returns true, and clears the singleton during teardown. The exact omitted/disabled helper cluster is [UID:000109][0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor](by-memory/0x00483fe0-0x0048402d.CheatDetectorVirtualClearAndDestructor.md).
- [UID:0000P5][VirusChecker](by-file/VirusChecker.md) is a retained AhnLab V3 scanner wrapper at `0x005c0460-0x005c0fe1`. It dynamically loads `V3PRO32E.DLL` and `V3PCTRL.DLL`, resolves `AhnExCheckFile`, `AhnExGetVirusName`, `V3PCtrl_EnumProcesses`, and `V3PCtrl_EnumModules`, then enumerates process/module paths through a local string tree before scanning them. Exact support pages cover [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md), [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md), and [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md).
- [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md) records exact IDA-confirmed vtable layouts for both classes: `CheatDetector` has two slots at `0x00615564`, while `VirusChecker` has one slot at `0x006310e0` before adjacent V3 string data begins.
- [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) is not anti-cheat by itself. It belongs in input/platform ownership, but it is security-adjacent because the client deliberately changes global keyboard repeat speed and restores it during cleanup, deactivation, exception handling, and `WinMain` exit. Its exact support pages are [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md), [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md), and [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md).
- [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md) is timer-skew diagnostics, not confirmed `CheatDetector` ownership. IDA caller review now points to [UID:0000HG][Application](by-file/Application.md) message-loop timing; keep anti-tamper interpretation open only as runtime intent, not source ownership.
- Password-protection helpers remain tracked through [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md), which is account/chat safety rather than executable integrity.

## Plain-English Runtime Meaning

- `CheatDetector` is definitely created during application startup, but the recovered class currently shows lifecycle state and a virtual slot that returns true. No concrete detection rule has been proven in this compact island yet.
- `VirusChecker` is real scanner code, but not proven active in normal startup. If something calls it, it loads AhnLab/V3 DLLs, enumerates process/module file paths, scans them with `AhnExCheckFile`, reports the virus name through localized UI, and then drives a close/termination path.
- `KeySpeedMgr` is not a detector. It saves the user's keyboard repeat settings, lets the client force fastest repeat, and restores the original values on cleanup/deactivation/crash/exit paths.

## Evidence Notes

- `Application::Initialize` directly constructs [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) and calls `LoadSystemKeyboardSettings`; the same startup flow constructs [UID:0000I6][CheatDetector](by-file/CheatDetector.md).
- IDA MCP confirms [UID:000108][0x00483f00-0x0048402c.CheatDetector](by-memory/0x00483f00-0x0048402c.CheatDetector.md), including active constructor/destructor functions, a disabled-but-real true-return virtual slot at `0x00483fe0`, and singleton clear helper `0x00483ff0`.
- IDA MCP confirms [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md), including scanner DLL loading at `0x005c05a0`, process/module scan flow at `0x005c07b0`, tree insertion helpers, and recursive node cleanup at `0x005c0fa0`.
- IDA MCP confirms [UID:0001WG][VirusCheckerProcessTreeLayout](by-type/by-struct/VirusCheckerProcessTreeLayout.md): object offset `+0x08` behaves as tree node count, not proven generic state.
- Current IDA xrefs did not prove live construction or activation of `VirusChecker`; treat it as retained scanner code until a caller is found.
- 2026-05-24 `simroot_v2` recheck confirms current active output still omits key helpers: `VirusChecker` lacks scanner/load helpers, `CheatDetector` disables the true-return virtual slot, and `KeySpeedMgr` disables restore despite live cleanup callers.
- 2026-05-26 recheck using `simroot_v2` and IDA MCP only confirms the same active-output gaps, now anchored by exact helper and singleton memory pages linked above.

## Open Questions

- Find a live caller for `VirusChecker::VirusChecker`, `VirusChecker::LoadScannerDlls`, or the scan entry point, or document it as retained/dead code if no caller exists after a full xref pass.
- Identify any file-integrity or code-section checksum routines separate from `CheatDetector` and `VirusChecker`.
- Determine whether `CheatDetector` has timer callbacks or subclass behavior outside the compact `0x00483f00-0x0048402c` island.
- Determine whether timer-skew diagnostics are simply connection/heartbeat health checks or were intended as anti-tamper evidence; current source ownership should remain application timing either way.
- Confirm final folder naming: `security/` is the current proposed source-tree folder for `CheatDetector.cpp` and `VirusChecker.cpp`.
- Continue adding plain-English behavior notes for any newly found integrity, scan, or timer-check routines.

## Cross-References

- [UID:0000I6][CheatDetector](by-file/CheatDetector.md)
- [UID:0000P5][VirusChecker](by-file/VirusChecker.md)
- [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md)
- [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md)
- [UID:0000U8][CheckTimerSkewAndSendHeartbeat_466CA0](by-item/CheckTimerSkewAndSendHeartbeat_466CA0.md)
- [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md)
- [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md)
- [UID:0001WG][VirusCheckerProcessTreeLayout](by-type/by-struct/VirusCheckerProcessTreeLayout.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
