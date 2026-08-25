*** UID:0001Q7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Anticheat And Integrity Checks

## Status

- Scope: client-side anti-cheat, anti-virus/process scanning, suspicious-input controls, and anti-modification checks where they are visible in the recovered client.
- Confidence: medium for module placement, strong for the specific address ranges documented here.
- Current focus: class/file ownership and source-tree placement, not claiming final runtime effectiveness.

## Current Findings

- [UID:0000I6][CheatDetector](by-file/CheatDetector.md) is a 0x20-byte startup-created security singleton in `NexusTK/security/CheatDetector.cpp`. Current RTTI proves direct source bases `Singleton<CheatDetector>` then `TimerHandler`; Singleton uses PMD `+4,-1,0` empty-base overlap while polymorphic TimerHandler occupies offset zero. [UID:0000QJ][g_pCheatDetector](by-global/g_pCheatDetector.md) owns the sole zero source definition backed by false/non-emitting [UID:0001P5][0x0067ab3c-0x0067ab40.g_pCheatDetector](by-memory/0x0067ab3c-0x0067ab40.g_pCheatDetector.md), with five exact cleanup/publication/unwind/scalar references. Exact source children are [UID:0004UO][0x00483f00-0x00483f86.CheatDetectorConstructor](by-memory/0x00483f00-0x00483f86.CheatDetectorConstructor.md), retained [UID:0002EN][0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper](by-memory/0x00483f90-0x00483fd9.CheatDetectorTimeSnapshotHelper.md), and [UID:0004UP][0x00483fe0-0x00483fe5.CheatDetectorOnTimer](by-memory/0x00483fe0-0x00483fe5.CheatDetectorOnTimer.md), which returns true. Compiler-only UID0004UQ clear, UID0004UR scalar wrapper, and vtable/RTTI pages emit no handwritten ABI source. CaptureTimeSnapshot samples system file time and `g_pTimerMgr` tick state but has exhaustive zero incoming call/jump/VA/RVA/raw-pointer routes, so active detection behavior remains unproven; the source/lifetime classification does not imply an active anti-cheat rule.
- [UID:0000P5][VirusChecker](by-file/VirusChecker.md) is a retained AhnLab V3 scanner wrapper at `0x005c0460-0x005c0fe1`. It dynamically loads `V3PRO32E.DLL` and `V3PCTRL.DLL`, resolves four caller-cleaned cdecl exports, and passes typed callee-cleaned stdcall callbacks through the two enumeration exports. The completed UID0001NW partition reconstructs three authored definitions (`InsertModulePath`, `V3ModuleEnumCallback`, and `V3ProcessEnumCallback`) over private ANSI `ModulePathString`, lexical `ModulePathLess`, and unique `ModulePathSet`; six retained bodies are compiler/Dinkumware node allocation, insertion/rebalance, unique find/insert, Singleton EH clear, scalar deleting destructor, and set destruction and therefore are documented but not handwritten. Current zero-filled module statics, exact callback edges, class/file ownership, and source ordering are closed. No normal constructor/load/scan activation route or external `g_pVirusChecker` consumer was found, so optional/disabled integration remains the runtime interpretation. Exact support pages cover [UID:0001NV][0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan](by-memory/0x005c05a0-0x005c0937.VirusCheckerV3LoadAndScan.md), [UID:0001NW][0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers](by-memory/0x005c0940-0x005c0fe1.VirusCheckerProcessTreeHelpers.md), and [UID:0001Q3][0x0069bf94-0x0069bf98.g_pVirusChecker](by-memory/0x0069bf94-0x0069bf98.g_pVirusChecker.md).
- [UID:0001YU][SecuritySingletonVtables](by-type/by-vtable/SecuritySingletonVtables.md) records exact IDA-confirmed vtable layouts for both classes: `CheatDetector` has two slots at `0x00615564`, while `VirusChecker` has one slot at `0x006310e0` before adjacent V3 string data begins.
- VirusChecker module-path normalization consumes the shared header-visible inline `StringBase<char>::ToLower() const` specialization from `StringBase.h` or an included `.inl`. The inlined VirusChecker form and SoundManager-adjacent outlined/COMDAT form are consumers of the same StringBase-owned definition; neither places authored source in `VirusChecker.cpp`, `SoundManager.cpp`, or `StringBase.cpp`.
- [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) is not anti-cheat by itself. It belongs in input/platform ownership, but it is security-adjacent because the client deliberately changes global keyboard repeat speed and restores it during cleanup, deactivation, exception handling, and `WinMain` exit. Its exact support pages are [UID:00018P][0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings](by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md), [UID:00018Q][0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings](by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md), and [UID:0001P7][0x0067ab48-0x0067ab4c.g_pKeySpeedMgr](by-memory/0x0067ab48-0x0067ab4c.g_pKeySpeedMgr.md).
- [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md) is timer-skew diagnostics, not confirmed `CheatDetector` ownership. IDA caller review now points to [UID:0000HG][Application](by-file/Application.md) message-loop timing; keep anti-tamper interpretation open only as runtime intent, not source ownership.
- Password-protection helpers remain tracked through [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md), which is account/chat safety rather than executable integrity.

## Plain-English Runtime Meaning

- `CheatDetector` is definitely created during application startup, but the recovered class currently shows lifecycle state, a raw retained `CaptureTimeSnapshot` helper, and a virtual slot that returns true. No concrete detection rule has been proven in this compact island yet.
- `VirusChecker` is real scanner code, but not proven active in normal startup. If something calls it, it loads AhnLab/V3 DLLs, enumerates process/module file paths, scans them with `AhnExCheckFile`, reports the virus name through localized UI id `221`, stores Application error text, and then drives `Application::RequestExit`. Current best inference is retained optional/disabled scanner integration rather than a source-ownership transfer to AhnLab or `client_libraries`.
- `KeySpeedMgr` is not a detector. It saves the user's keyboard repeat settings, lets the client force fastest repeat, and restores the original values on cleanup/deactivation/crash/exit paths.

## Evidence Notes

- `Application::Initialize` directly constructs [UID:0000KJ][KeySpeedMgr](by-file/KeySpeedMgr.md) and calls `LoadSystemKeyboardSettings`; the same startup flow constructs [UID:0000I6][CheatDetector](by-file/CheatDetector.md).
- IDA MCP and B002 local PE recheck confirm [UID:000108][0x00483f00-0x0048402d.CheatDetector](by-memory/0x00483f00-0x0048402d.CheatDetector.md), including active constructor/destructor functions, `CaptureTimeSnapshot` at `0x00483f90`, a disabled-but-real true-return virtual slot at `0x00483fe0`, singleton clear helper `0x00483ff0`, and no direct route to the raw helper.
- IDA MCP confirms [UID:0001NU][0x005c0460-0x005c0fe1.VirusChecker](by-memory/0x005c0460-0x005c0fe1.VirusChecker.md), including scanner DLL loading at `0x005c05a0`, process/module scan flow at `0x005c07b0`, tree insertion helpers, and recursive node cleanup at `0x005c0fa0`.
- IDA MCP confirms [UID:0001WG][VirusCheckerProcessTreeLayout](by-type/by-struct/VirusCheckerProcessTreeLayout.md): object offset `+0x08` behaves as tree node count, not proven generic state.
- Dated IDA xref checks did not prove live construction or activation of `VirusChecker`; treat it as retained scanner code until a caller is found. Any future IDA authority requires a fresh supervisor `idb_list`, health/canonical-disk identity, and target-prestate readback.
- Historical 2026-05-24/2026-05-26 `simroot_v2` checks identified generated-output gaps, including missing VirusChecker scanner/load helpers. For VirusChecker, UID0001NV now carries formal first-draft load/reset/scan source; generated-state truth must be reread from the latest coherent validator output rather than treating those old checks or any one generated snapshot as permanent authority.

## Open Questions

- VirusChecker activation was exhaustively attempted rather than deferred: the dated bounded direct-xref and VA/RVA/raw pointer-pattern searches found no constructor/load/scan/insert/clear activation route. The retained class, callback chain, and source/generated partition are nevertheless exact. A future runtime trace may distinguish disabled from distribution-specific optional activation, but no source body, ownership, naming, or score decision remains blocked on that trace.
- Identify any file-integrity or code-section checksum routines separate from `CheatDetector` and `VirusChecker`.
- `CheatDetector`'s visible timer callback is exact child UID0004UP, `CheatDetector::OnTimer(int timerId, int arg0, int arg1)`, inferred from TimerHandler vtable/queue semantics and `ret 0x0c`. The retained private `CaptureTimeSnapshot` helper is route-negative. This is a bounded runtime-confidence limitation, not deferred source work and not evidence that additional active anti-cheat logic exists.
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
