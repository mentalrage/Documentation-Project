** TARGET-REPORT-UID:0000HG **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000HG Application Empty-Emitter Family Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: implement a targeted empty-emitter cleanup for [UID:0000HG] `by-file/Application.md` by preserving the Application source route, adding first-draft C++ where current MCP and docs now support source-quality code, and converting the remaining intentional blank routes into exact formal no-code/comment markers or exact duplicate/index metadata repairs.
- Final disposition: `Application.cpp` is the correct generated source root. The current 39 generated empty markers are not one uniform problem: 15 are immediate first-draft code/data candidates, 22 are intentional no-code/comment-only markers backed by target-specific proof, and 2 are duplicate/index route repairs with exact metadata changes. No row remains at "wait for names/source placement" as a final rationale.
- Required action: update target/support by-* docs listed below after supervisor acceptance; run scoped file validators for each changed by-* doc and inspect regenerated `auto-generated/NexusTK/app/Application.cpp` for reduced empty markers.
- Confidence: high for marker inventory, route classification, current MCP recheck, duplicate/index repair, and the code-ready helper/global subset; medium-high for exact original spelling of newly proposed helper/global names.

## Target

- Target UID: `0000HG`
- Target path: `by-file/Application.md`
- Assignment: `B013-revise-0000HG-Application-empty-emitter-family-20260629`
- Queue row: `auto-generated/-ag-research-tracker.md` -> `## Files With Empty Emitters`
- Current generated root: `auto-generated/NexusTK/app/Application.cpp`
- Current row state: total `72`, filled `33`, empty `39`, filled `45.8%`, reports `0` in the by-file tracker context.
- Current target metadata: `COMPLETION:86`, `CONFIDENCE:90`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/"`, `CANONICAL_OWNER:FILE`.

## Current Target State

`Application.md` is already a valid generated source root for `NexusTK/app/Application.cpp`. It strongly documents the process shell, `Application`/`BaramApp` source family, singleton storage, lifecycle methods, startup/shutdown, message loop, fatal helpers, default screen dimensions, vtables, and string/data pools. The generated output is current enough to be meaningful: the checked generated file header is `validator-command-id: 000000001256`, `validator-refreshed-at: 2026-06-29T21:40:04-04:00`, and it still lists 39 `Empty Emitter Marker` rows at the end.

The main source-quality issue is not file ownership. The issue is that many reconstructable child pages are routed to `Application.cpp` but their formal `RECONSTRUCTION_CPP CODE` blocks are blank because older docs cite the retired `95/95` code gate or because they are legitimate compiler/data/aggregate/index pages. Current by-structure rules allow C++ when the route is proven, `RECONSTRUCTABLE:TRUE`, and `(COMPLETION + CONFIDENCE) / 2 > 85`, but that is still a minimum gate; broad helpers and layout-dependent pages should receive formal evidence-backed marker comments, not weak bodies.

## Supervisor Active Recheck

- The assignment requires current IDA MCP evidence. MCP is available now under database `supervisor_resume_20260629`.
- No split execution or by-* edits are allowed during this report-only pass.
- No leases were taken.
- No subagents were spawned.
- No generated file, coverage file, validator state, IDA DB, executed archive, by-* doc, or supervisor ledger was edited.

## Evidence Checked

### MCP availability

- `idb_list` via MCP HTTP JSON-RPC returned HTTP `200` with active session `supervisor_resume_20260629`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `17592`, `is_analyzing:false`, `is_active:true`.
- `server_health` with `database='supervisor_resume_20260629'` returned HTTP `200`, `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- `get_bytes` at `0x00401000`, size `1`, returned `0x8b`, matching the supervisor's base sanity check.
- Active MCP schema was checked with `tools/list`; relevant calls used `database='supervisor_resume_20260629'`, `lookup_funcs`, `get_bytes`, `disasm`, `decompile`, `xrefs_to`, and `callees`.
- 2026-06-29 revision recheck used the same listener and session. `idb_list` returned HTTP `200`, one active `supervisor_resume_20260629` session, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `17592`, and `is_analyzing:false`. `server_health` returned HTTP `200`, `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and `strings_cache_size:2067`.
- One local PowerShell wrapper attempt omitted the `database` argument because the wrapper parameter was named `$args`; MCP returned HTTP `200` with `isError:true` and `"database is required"`. This was a local wrapper error, not an MCP outage. The corrected wrapper supplied `database='supervisor_resume_20260629'`; all subsequent target MCP calls returned `isError:false`.

### Generated/source docs

- Read `by-file/Application.md`, `by-file/-guidance.md`, `by-structure.md`, and the B-agent workflow/score/report-template references.
- Read current generated `auto-generated/NexusTK/app/Application.cpp` read-only and inventoried every `Empty Emitter Marker`.
- Checked `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-file-coverage.md`: Application row remains the active empty-emitter source root and file coverage says `coded`.
- Searched old/current B reports with terms including `0000HG`, `Application.cpp`, `Application empty emitter`, `ApplicationMapFromScreen`, `ApplicationMapToScreen`, `ApplicationDestroyLoadingDialog`, `ApplicationScalarDeletingDestructor`, `GetApplicationSingleton`, `LoadIndexedDATSeries`, `ApplicationLifecycle`, and relevant UIDs. Dedicated prior reports exist for related empty-marker repairs such as UID0002H0, UID0002GZ, UID0002Q2, UID0002GY, and g_pApplication; no dedicated executed report was found for UID0002GS/UID0002GT/UID0002GW/UID00032B.
- Revision search also covered the supervisor-named blocker rows by UID/name/address: UID0002JX, UID0002JZ, UID0000YT, UID0000YX, UID00035N, UID00028Z, UID000291, UID000292, UID000293, UID0002VU, UID0002VX, UID0000U8, and UID0000T5. Existing docs/reports were used as leads only; current MCP evidence above is the controlling proof.

### Current MCP facts used

- `lookup_funcs` confirms current function boundaries:
  - `0x004632c0` `sub_4632C0`, size `0x4b`.
  - `0x00463310` `Application__Constructor`, size `0x65e`.
  - `0x004651f0` `sub_4651F0`, size `0xec`.
  - `0x00465320` `sub_465320`, size `0x104`.
  - `0x00465690` `sub_465690`, size `0x9d`.
  - `0x00465730` `sub_465730`, size `0x9d`.
  - `0x00465bb0` `sub_465BB0`, size `0xd`.
  - `0x00465cb0` `sub_465CB0`, size `0x30`.
  - `0x00466ca0` `sub_466CA0`, size `0x40d`.
  - `0x00467230` `sub_467230`, size `0x87`.
  - `0x00467380` `sub_467380`, size `0x11`.
  - `0x004673a0` `sub_4673A0`, size `0x11`.
  - `0x004673e0` `sub_4673E0`, size `0x6`.
  - `0x00467410` `sub_467410`, size `0xdd`.
  - `0x004f5f20` is not a function start in IDA, but current bytes decode the raw `BaramApp` constructor prologue and Application constructor forwarding call.
  - `.rdata` and `.data` marker addresses such as `0x006125e0`, `0x0061d140`, `0x0061d234`, `0x0066d408`, and `0x0067a938` are not functions.
- `disasm`/`decompile` current proof for selected code-ready helpers:
  - UID0002GS `MapFromScreen`: 49 instructions, no callees, current/base dimension test, copy path, scale path using `word_66DA98`, `word_66DA94`, `Application+0xa60`, `Application+0xa64`, and `0.5f` at `0x006104b0`; xrefs at `0x0046c1cf`, `0x0046c1f2`, `0x0046c32b`, `0x0046c34e`.
  - UID0002GT `MapToScreen`: 49 instructions, no callees, reciprocal formulas; xrefs at `0x0046c4fd` and `0x0046c522`.
  - UID0002GW `DestroyLoadingDialog`: exact three-instruction body `push [ecx+0x82c]`, `call DestroyWindow`, `retn`; sole xref `0x004f61f6` in Application startup.
  - UID00032B `GetApplicationSingleton`: exact two-instruction body `mov eax, [0x0067ab1c]`, `retn`; 15 direct xrefs in current capped query, including fatal dialog and parser failure paths.
  - UID0002VI `FatalErrorDialogAndBreak`: 15-instruction `__noreturn` body; loads `GetApplicationSingleton`, calls `GetMainWindowHandle`, calls `MessageBoxW` with caption bytes at `0x00612ea8` (`Aborted` UTF-16), calls `PostQuitMessage(0)`, calls `__loaddll(0)`, then `int 3`; 15 call sites.
  - UID0000YV and UID0000YW: current bytes are exact seven-instruction nullable singleton delete wrappers over `g_pDATFileMgr` and `g_pCrashTarget`, respectively; neither clears the singleton.
  - UID000323 `ApplicationScalarDeletingDestructor`: current disassembly proves Application vtable writes, `CloseHandle`, StringBase/member teardown, `g_pApplication` clear, `LObject` cleanup, and conditional delete/guard helper paths; keep comment-only as compiler wrapper rather than hand-written method body.
- 2026-06-29 revision `decompile` proof for formerly under-resolved executable helpers:
  - UID0002JX `0x004651f0`: current Hex-Rays returns `errno_t __stdcall sub_4651F0(wchar_t *Destination, rsize_t SizeInWords)`. The body copies `GetCommandLineW()` into a `0x104`-wide local buffer, chooses quote or space delimiter with `wcschr`, terminates the delimiter, copies characters to the destination while skipping quote characters, compares the last four destination characters to the `.exe` wide literal at `0x00612e54`, and appends that suffix with `wcscat_s(Destination, SizeInWords, L".exe")` on mismatch.
  - UID0002JZ `0x00465320`: current Hex-Rays returns `__int16 sub_465320()`. It calls UID0002JX with a `260`-wide buffer and size `0x104`, calls the PlatformApi VERSION dispatch slots at `0x0069beb0/0x0069beb4/0x0069beb8`, allocates/frees the version-info block through `0x00516050/0x00516170`, queries the root literal at `0x0061260c`, reads `VS_FIXEDFILEINFO.dwFileVersionLS` at offset `+0x14`, returns its low word, and returns zero on size/load/query failure.
  - UID0000YX `0x00467410`: current Hex-Rays returns `char __cdecl sub_467410(int ArgList)`. It loops `index < 99`, formats `L"%s%d.DAT"` into a local wide filename buffer through `0x0041b9b0` with count `0x28`, probes `_wfopen_s(..., L"rb")`, breaks on missing stream, closes present streams with `fclose`, calls the `ForwardLoadDATFileIndex`-shaped wrapper `0x0049be70` on `g_pDATFileMgr`, and on manager failure builds a wide `L"File not found : %s"` message through `0x00583280/0x00584540` before calling UID0002VI at `0x00465cb0`.
  - UID0000YT `0x00466ca0`: current Hex-Rays returns `DWORD __usercall sub_466CA0(char a1@<dil>)`. It initializes two local-static tick states through `_Init_thread_header/_Init_thread_footer`, samples `timeGetTime`, `GetTickCount`, `_time64`, and `GetSystemTimeAsFileTime`, compares elapsed seconds against the timing-baseline cluster, formats `[Key:%08x]` / `unknown key` and the `"!! %s%s%s%s : %s, [%d,%d,%d,%d] OS:%s"` diagnostic string, calls crash diagnostic sender `0x004ab740`, latches `0x0067ab6c`, then constructs an 11-byte opcode `0x60` heartbeat packet from `GetTickCount`, two `rand()` calls, and `g_pUserPane + 0x1a0` before queueing through `0x00574bb0`.
- 2026-06-29 revision `decompile` proof for data consumers:
  - `Application::RunMessageLoop` at `0x00464cd0` increments `0x0067ab74`, sleeps and clears it after `> 10`, increments `0x0067ab70`, calls UID0000YT and clears it after `> 1000`, enters/leaves the critical-section storage at `0x0067a9a4`, and dispatches through the active message handler.
  - `Main_WndProc` at `0x00465f20` uses `0x0067ab78` as the `WM_MOUSEWHEEL` accumulator, accumulates `HIWORD(wParam)`, waits until `abs(accumulator) >= 120`, preserves the modulo remainder, and dispatches normalized wheel events.
- `get_bytes` current data proof:
  - `0x0066da94` bytes begin `00 04 01 01 00 03 00 00`, so `g_screenWidth` is two-byte `0x0400`/1024 and `g_screenHeight` is two-byte `0x0300`/768, with separate intervening byte globals.
  - `0x0061d140` starts the BaramApp/Nexus update string pool with UTF-16 `NexusTK`, `Nexon`, and update prompt text.
  - `0x0061d234` is callback/vtable data bytes.
  - `0x006125e0` starts Application RTTI/vtable-related data; `0x006125e4` contains function/data pointers including `0x00467230`, `0x004f4b10`, `0x0041b6c0`, `0x004639d0`, `0x00464a60`, `0x004669c0`, `0x00466a70`, etc.
  - `0x0061260c` is the shared wide path separator `5c 00 00 00`.
  - `0x00612980`, `0x00612b24`, and `0x00612e54` begin documented Application registry/startup/version string pools.
  - 2026-06-29 revision byte recheck corrected stale older `0xff` wording on several data pages. Current MCP `get_bytes` returned `0x00` for all bytes in `0x0067a938-0x0067a940`, `0x0067a980-0x0067a998`, `0x0067a998-0x0067a9c0`, `0x0067a9c0-0x0067ab18`, `0x0067ab5c-0x0067ab70`, and `0x0067ab70-0x0067ab7c`. The display startup pair at `0x0066d408` returned `00 04 00 00 01 00 00 00`.

## Current Empty-Marker Inventory

Every row below is currently present in `auto-generated/NexusTK/app/Application.cpp` under UID0000HG.

| # | UID | Path | Score | Final classification | Exact callback action |
| ---: | --- | --- | --- | --- | --- |
| 1 | 00000D | `by-class/Application.md` | 85/89 | broad class declaration marker | Insert exact formal no-code comment NC-00000D; no class body emitted. Recommend `87/90`. |
| 2 | 0002GY | `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md` | 89/92 | constructor no-code proof | Insert exact formal no-code comment NC-0002GY; metadata unchanged. |
| 3 | 0002GS | `by-memory/0x00465690-0x0046572d.ApplicationMapFromScreen.md` | 86/91 | first-draft method | Insert C++ FD-0002GS; recommend `88/93`. |
| 4 | 0002GT | `by-memory/0x00465730-0x004657cd.ApplicationMapToScreen.md` | 86/91 | first-draft method | Insert C++ FD-0002GT; recommend `88/93`. |
| 5 | 0002GW | `by-memory/0x00465bb0-0x00465bbd.ApplicationDestroyLoadingDialog.md` | 86/92 | first-draft method | Insert C++ FD-0002GW; recommend `88/94`. |
| 6 | 000323 | `by-memory/0x00467230-0x004672b7.ApplicationScalarDeletingDestructor.md` | 85/89 | compiler wrapper marker | Insert exact formal no-code comment NC-000323; recommend `87/91`. |
| 7 | 00000V | `by-class/BaramApp.md` | 86/90 | broad class declaration marker | Insert exact formal no-code comment NC-00000V; no score change. |
| 8 | 0003P3 | `by-memory/0x0061d140-0x0061d234.BaramAppStartupUpdateStrings.md` | 86/91 | string-pool marker | Insert exact formal no-code comment NC-0003P3; no score change. |
| 9 | 0003P4 | `by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md` | 86/91 | compiler vtable marker | Insert exact formal no-code comment NC-0003P4; no score change. |
| 10 | 0000T5 | `by-global/LoadIndexedDATSeries.md` | 88/92 | duplicate global index repair | Set `RECONSTRUCTABLE:FALSE`, keep `CANONICAL_OWNER:0000HG`, clear `EMITTER_UIDS`, clear `EMITTER_POSITION_OPTIONAL`, keep formal C++ blank, add body note that UID0000YX is the exact source-bearing page; no score change. |
| 11 | 0000ST | `by-global/g_screenHeight.md` | 88/91 | first-draft global | Insert C++ FD-0000ST; recommend `90/93`. |
| 12 | 0001OI | `by-memory/0x0066da98-0x0066da9a.g_screenHeight.md` | 86/91 | covered storage marker | Insert exact formal no-code comment NC-0001OI; no duplicate definition. |
| 13 | 0000SU | `by-global/g_screenWidth.md` | 88/91 | first-draft global | Insert C++ FD-0000SU; recommend `90/93`. |
| 14 | 0001OG | `by-memory/0x0066da94-0x0066da96.g_screenWidth.md` | 87/91 | covered storage marker | Insert exact formal no-code comment NC-0001OG; no duplicate definition. |
| 15 | 0000U8 | `by-item/CheckTimerSkewAndSendHeartbeat_466CA0.md` | 86/90 | duplicate item index repair | Set `RECONSTRUCTABLE:FALSE`, keep `CANONICAL_OWNER:0000HG`, clear `EMITTER_UIDS`, clear `EMITTER_POSITION_OPTIONAL`, keep formal C++ blank, add body note that UID0000YT is the exact source-bearing page; no score change. |
| 16 | 0000YQ | `by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md` | 86/91 | compiler/AUTOBUF cleanup marker | Insert exact formal no-code comment NC-0000YQ; no score change. |
| 17 | 0000YR | `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md` | 85/88 | aggregate marker | Insert exact formal no-code comment NC-0000YR; keep metadata `TRUE` because children route through it; no score change. |
| 18 | 0002JX | `by-memory/0x004651f0-0x004652dc.BuildExecutablePathForVersionInfo.md` | 86/88 | first-draft helper | Insert C++ FD-0002JX; recommend `88/91`. |
| 19 | 0002JZ | `by-memory/0x00465320-0x00465424.GetExecutableVersionLowWord.md` | 86/88 | first-draft helper | Insert C++ FD-0002JZ; recommend `88/91`. |
| 20 | 0002VI | `by-memory/0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak.md` | 87/90 | first-draft helper | Insert C++ FD-0002VI; recommend `89/92`. |
| 21 | 0000YT | `by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md` | 88/91 | rare no-improvement marker | Insert exact formal no-code comment NC-0000YT and add no-improvement proof; no score change. |
| 22 | 0000YV | `by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md` | 88/91 | first-draft helper | Insert C++ FD-0000YV; recommend `89/92`. |
| 23 | 0000YW | `by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md` | 88/91 | first-draft helper | Insert C++ FD-0000YW; recommend `89/92`. |
| 24 | 00032B | `by-memory/0x004673e0-0x004673e6.GetApplicationSingleton.md` | 85/88 | first-draft helper | Insert C++ FD-00032B; recommend `88/92`. |
| 25 | 0000YX | `by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md` | 90/94 | rare no-improvement marker | Insert exact formal no-code comment NC-0000YX and add no-improvement proof; no score change. |
| 26 | 00019H | `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md` | 86/90 | aggregate marker | Insert exact formal no-code comment NC-00019H; no score change. |
| 27 | 00047Y | `by-memory/0x006125e0-0x006125e4.ApplicationRttiLocatorPointer.md` | 86/91 | compiler RTTI marker | Insert exact formal no-code comment NC-00047Y; no score change. |
| 28 | 0003OD | `by-memory/0x006125e4-0x0061260c.ApplicationVtableData.md` | 86/91 | compiler vtable marker | Insert exact formal no-code comment NC-0003OD; no score change. |
| 29 | 00047Z | `by-memory/0x0061260c-0x00612610.SharedWidePathSeparatorLiteral.md` | 88/92 | pooled-literal marker | Insert exact formal no-code comment NC-00047Z; no score change. |
| 30 | 000484 | `by-memory/0x00612980-0x00612b24.ApplicationRegistryDisplayStringData.md` | 87/90 | string-pool marker | Insert exact formal no-code comment NC-000484; no score change. |
| 31 | 000485 | `by-memory/0x00612b24-0x00612e3c.ApplicationStartupResourceStringData.md` | 88/91 | string-pool marker | Insert exact formal no-code comment NC-000485; no score change. |
| 32 | 000487 | `by-memory/0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData.md` | 87/91 | string-pool marker | Insert exact formal no-code comment NC-000487; no score change. |
| 33 | 00035N | `by-memory/0x0066d408-0x0066d410.DisplayStartupPresentationGlobals.md` | 86/90 | first-draft global data | Insert C++ FD-00035N; recommend `88/92`. |
| 34 | 00028Z | `by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md` | 86/90 | first-draft global data | Insert C++ FD-00028Z using current zero bytes; recommend `88/92`. |
| 35 | 000291 | `by-memory/0x0067a980-0x0067a998.ApplicationTimingBaselines.md` | 87/91 | first-draft global data | Insert C++ FD-000291 using current zero bytes; recommend `89/92`. |
| 36 | 000292 | `by-memory/0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics.md` | 86/91 | combined static-storage no-improvement marker | Insert exact formal no-code comment NC-000292 and proof; no score change. |
| 37 | 000293 | `by-memory/0x0067a9c0-0x0067ab18.ApplicationOsVersionState.md` | 88/91 | combined OS-state no-improvement marker | Insert exact formal no-code comment NC-000293 and proof; no score change. |
| 38 | 0002VU | `by-memory/0x0067ab5c-0x0067ab70.ApplicationHeartbeatTimerSkewGlobals.md` | 88/91 | local-static/guard marker | Insert exact formal no-code comment NC-0002VU and proof; no score change. |
| 39 | 0002VX | `by-memory/0x0067ab70-0x0067ab7c.ApplicationMessageLoopInputCounters.md` | 87/90 | first-draft global data | Insert C++ FD-0002VX using current zero bytes; recommend `89/92`. |

## Heuristic / Inference Reanalysis And Validation

The file-level owner is stable. Current MCP, current docs, and generated output all point to `NexusTK/app/Application.cpp` as the Application shell source root. No evidence supports moving the family to `WinMain`, `MSGHandler`, `ScreenPane`, `DATFileMgr`, `ExceptionHandler`, `PasswordGuard`, `Error`, or a new single-purpose source file. Those modules own dependencies or consumers; Application owns the process shell, startup/fatal policy, default display dimensions, and the helper neighborhood.

The main correction is to reject the stale "blank until 95/95" policy where it is the only blocker. Current by-structure permits code below 95 when the route, behavior, dependencies, names, and source shape are good enough. The revision also rejects "names/source placement not final" as a final report disposition. Each such row is now either a formal first-draft body, an exact duplicate/index metadata repair, or an evidence-backed no-improvement marker with rejected alternatives.

- UID0002GS/UID0002GT: exact formulas, no callees, current xrefs, base display globals, and Application fields are known. The original pair type is not proven, so first-draft code should use an explicit `int *` two-slot pair signature instead of a misleading Win32 `POINT`.
- UID0002GW: full body is exactly `DestroyWindow(m_hLoadingDlg)`.
- UID00032B: full body is exactly `return g_pApplication;`.
- UID0002VI: full fatal body is exact and can call the source-ready `GetApplicationSingleton()` and `Application::GetMainWindowHandle()`.
- UID0000YV/UID0000YW: exact nullable singleton delete wrappers should emit source-level `delete` statements. `delete NULL` is source-equivalent to the observed null-check and must not add singleton clearing.
- UID0000SU/UID0000ST: current bytes and `movsx` uses support signed `short` definitions, not 32-bit `int` definitions.
- UID0002JX/UID0002JZ: current MCP decompilation resolves the exact command-line normalization/version-info helper bodies enough for first-draft helper C++. Cross-module consumers remain score caps, not C++ blockers, because UID0002H6 already calls `BuildExecutablePathForVersionInfo(executablePath)` in accepted formal C++ and the helper can carry a default `0x104` count in the generated source.
- UID00035N/UID00028Z/UID000291/UID0002VX: current MCP byte reads and consumer decompiles resolve these as simple Application-owned globals with role-based source names. Older `0xff` initialization wording on UID000291/UID0002VX is stale against the active `supervisor_resume_20260629` database, which reads zero bytes for those ranges.

The remaining blank markers are not safe for executable bodies in this report, but the reason is now exact per target. Broad class/aggregate parents receive covered-by-child comments; compiler wrappers, vtables, and RTTI receive compiler-generated markers; string pools receive source-use markers; UID0000T5 and UID0000U8 become non-emitting duplicate/index pages; UID0000YT and UID0000YX receive rare no-improvement proofs for source-authored helpers whose naive C++ would invent protocol/helper-source details; UID000292, UID000293, and UID0002VU receive data no-improvement markers because their current combined ranges include compiler/static support or grouped state that should not be emitted as guessed byte blobs or split declarations in this callback.

## Ranked Ownership Analysis

### 1. Existing Application file root [UID:0000HG] - selected

- Evidence for: generated source root is valid and current; Application file docs contain accepted current evidence for lifecycle, singleton, default screen dimensions, startup/shutdown, fatal helpers, and BaramApp shell; current MCP shows the selected helpers depend on Application fields, `g_pApplication`, Application main HWND, startup callers, or default screen globals.
- Evidence against: several helper/data pages are shared by diagnostics, startup parser, or patch/update code. These are consumer/source-use complications, not stronger source-owner evidence.
- Decision: keep `CANONICAL_OWNER:FILE`, path `NexusTK/app/`, and use Application as final generated root.

### 2. Application class [UID:00000D] as method owner - selected for method children

- Evidence for: coordinate helpers and loading-dialog destroyer are `this` methods over Application fields; scalar deleting destructor writes Application vtables; class docs already own relevant fields.
- Evidence against: broad class declaration still lacks full member/base layout.
- Decision: method children stay under UID00000D; class page receives only a formal comment marker, not a class declaration.

### 3. Narrow dependency owners - rejected as direct owners

- `DATFileMgr`, `ExceptionHandler`, `ScreenPane`, `RegistryConfig`, `Error`, `PasswordGuard`, image-library modules, and diagnostics modules either provide objects/APIs or consume helpers. Current MCP does not show they declare the Application source-family helpers.

### 4. New helper source file - rejected

- A new `ApplicationFatalCleanup.cpp`, `DisplayGlobals.cpp`, or `FatalError.cpp` would contain only tiny helpers/data already surrounded by Application startup/lifecycle evidence. That would be less source-plausible than the existing `Application.cpp` route.

## First-Draft C++ Recommendation

The following are exact formal `RECONSTRUCTION_CPP CODE` insertion texts recommended for immediate callback implementation. Names are source-quality first-draft names backed by current evidence; where original spelling is not proven, the score rationale caps confidence rather than withholding code.

### UID0002GS `ApplicationMapFromScreen`

```cpp
int *Application::MapFromScreen(int *mappedPair, const int *screenPair) const
{
    if (m_currentScreenWidth == g_screenWidth &&
        m_currentScreenHeight == g_screenHeight) {
        mappedPair[0] = screenPair[0];
        mappedPair[1] = screenPair[1];
        return mappedPair;
    }

    mappedPair[0] = static_cast<int>(
        static_cast<float>(screenPair[0] * g_screenHeight) /
        static_cast<float>(m_currentScreenHeight) + 0.5f);
    mappedPair[1] = static_cast<int>(
        static_cast<float>(screenPair[1] * g_screenWidth) /
        static_cast<float>(m_currentScreenWidth) + 0.5f);
    return mappedPair;
}
```

### UID0002GT `ApplicationMapToScreen`

```cpp
int *Application::MapToScreen(int *mappedPair, const int *clientPair) const
{
    if (m_currentScreenWidth == g_screenWidth &&
        m_currentScreenHeight == g_screenHeight) {
        mappedPair[0] = clientPair[0];
        mappedPair[1] = clientPair[1];
        return mappedPair;
    }

    mappedPair[0] = static_cast<int>(
        static_cast<float>(clientPair[0] * m_currentScreenHeight) /
        static_cast<float>(g_screenHeight) + 0.5f);
    mappedPair[1] = static_cast<int>(
        static_cast<float>(clientPair[1] * m_currentScreenWidth) /
        static_cast<float>(g_screenWidth) + 0.5f);
    return mappedPair;
}
```

### UID0002GW `ApplicationDestroyLoadingDialog`

```cpp
BOOL Application::DestroyLoadingDialog()
{
    return DestroyWindow(m_hLoadingDlg);
}
```

### UID0002JX `BuildExecutablePathForVersionInfo`

```cpp
errno_t __stdcall BuildExecutablePathForVersionInfo(wchar_t *destination,
                                                    rsize_t destinationCount = 0x104)
{
    wchar_t commandLine[0x104];
    wcscpy_s(commandLine, _countof(commandLine), GetCommandLineW());

    wchar_t delimiter = L' ';
    wchar_t *scan = commandLine;
    if (wcschr(commandLine, L'"') != NULL) {
        scan = commandLine + 1;
        delimiter = L'"';
    }

    wchar_t *terminator = wcschr(scan, delimiter);
    if (terminator != NULL) {
        *terminator = L'\0';
    }

    wchar_t *out = destination;
    for (wchar_t *cursor = commandLine; *cursor != L'\0'; ++cursor) {
        wchar_t ch = *cursor;
        if (ch == L'"') {
            do {
                ch = *++cursor;
            } while (ch == L'"');
        }
        *out++ = ch;
    }
    *out = L'\0';

    if (_wcsicmp(out - 4, L".exe") != 0) {
        return wcscat_s(destination, destinationCount, L".exe");
    }
    return 0;
}
```

### UID0002JZ `GetExecutableVersionLowWord`

```cpp
WORD GetExecutableVersionLowWord()
{
    wchar_t executablePath[0x104];
    DWORD versionHandle = 0;
    UINT fixedInfoLength = 0;
    VS_FIXEDFILEINFO *fixedInfo = NULL;

    BuildExecutablePathForVersionInfo(executablePath);

    const DWORD versionInfoSize =
        g_pfnGetFileVersionInfoSizeW(executablePath, &versionHandle);
    if (versionInfoSize == 0) {
        return 0;
    }

    void *versionInfo = AllocateBufferMemory(versionInfoSize);
    if (g_pfnGetFileVersionInfoW(executablePath, 0, versionInfoSize, versionInfo) &&
        g_pfnVerQueryValueW(versionInfo, L"\\",
                            reinterpret_cast<void **>(&fixedInfo),
                            &fixedInfoLength)) {
        const WORD lowWord = LOWORD(fixedInfo->dwFileVersionLS);
        FreeBufferMemory(versionInfo);
        return lowWord;
    }

    FreeBufferMemory(versionInfo);
    return 0;
}
```

### UID00032B `GetApplicationSingleton`

```cpp
Application *GetApplicationSingleton()
{
    return g_pApplication;
}
```

### UID0002VI `FatalErrorDialogAndBreak`

```cpp
static void FatalErrorDialogAndBreak(const wchar_t *message)
{
    Application *application = GetApplicationSingleton();
    MessageBoxW(application->GetMainWindowHandle(), message, L"Aborted", 0);
    PostQuitMessage(0);
    __loaddll(0);
    __debugbreak();
}
```

### UID0000YV `DestroyDATFileMgr`

```cpp
static void DestroyDATFileMgr()
{
    delete g_pDATFileMgr;
}
```

### UID0000YW `DestroyExceptionHandler`

```cpp
static void DestroyExceptionHandler()
{
    delete g_pCrashTarget;
}
```

### UID0000SU / UID0000ST display-size globals

```cpp
short g_screenWidth = 1024;
```

```cpp
short g_screenHeight = 768;
```

These two globals should remain separate by-global formal blocks. The exact by-memory storage children UID0001OG/UID0001OI should receive covered-by comments rather than duplicate definitions.

### UID00035N `DisplayStartupPresentationGlobals`

```cpp
int g_displayStartupWidth = 1024;
int g_displayStartupDrawType = 1;
```

### UID00028Z `ApplicationLifecycleFlags`

```cpp
int g_applicationPhaseState = 0;
int g_applicationActiveGate = 0;
```

### UID000291 `ApplicationTimingBaselines`

```cpp
DWORD g_timerSkewTimeGetTimeBaseline = 0;
DWORD g_timerSkewTickCountBaseline = 0;
__time64_t g_timerSkewTime64Baseline = 0;
DWORD g_timerSkewFileTimeSecondsBaseline = 0;
int g_timerSkewReportCount = 0;
```

### UID0002VX `ApplicationMessageLoopInputCounters`

```cpp
int g_applicationHeartbeatCheckCounter = 0;
int g_applicationMessageLoopThrottleCounter = 0;
int g_mouseWheelDeltaAccumulator = 0;
```

The four data declaration groups above are justified by current zero bytes and by current decompilation of `Application::Initialize`, `Application::RunMessageLoop`, `Main_WndProc`, and UID0000YT. UID000291 and UID0002VX must also replace stale older body text that described these ranges as initially `0xff`; current MCP reads them as zeroed storage.

## Exact No-Code / Comment Disposition

The following are exact formal `RECONSTRUCTION_CPP CODE` comment insertion texts for routed rows that should remain non-executable in this callback. These comments replace blank formal blocks and are expected to remove empty-emitter markers without inventing bodies.

| Marker ID | UID | Exact formal text |
| --- | --- | --- |
| NC-00000D | 00000D | `// Application class declaration is intentionally withheld here; exact method/global children emit through Application.cpp while full LObject, MSGHandler, StringBase, fixed-buffer, OS-version, and DAT-manager layout remains documented on by-class/Application.md.` |
| NC-0002GY | 0002GY | `// No standalone constructor body is emitted here; Application::Application is documented by UID0002GY, but full class layout, Application+0xa70 state, DAT manager construction, OS-version static grouping, and compiler unwind cleanup remain exact evidence rather than a guessed constructor body.` |
| NC-000323 | 000323 | `// Compiler-generated Application scalar deleting destructor; source-level destruction is represented by Application::~Application and compiler delete wrappers, so this range emits no hand-written body.` |
| NC-00000V | 00000V | `// BaramApp class declaration is intentionally withheld here; exact constructor, startup, callback, activation, shutdown, vtable, and compiler-wrapper children carry the Application.cpp source route.` |
| NC-0003P3 | 0003P3 | `// BaramApp startup/update string literals are emitted at their use sites; this pooled .rdata range emits no standalone static string declarations.` |
| NC-0003P4 | 0003P4 | `// Compiler-emitted PlainMemberFunctionObject0<BaramApp> callback vtable; rebuilt from the callback class/template declaration and UID0002Q0 use, not emitted as standalone data.` |
| NC-0001OI | 0001OI | `// Exact two-byte storage is emitted by UID0000ST g_screenHeight; this by-memory child records bytes/xrefs only and emits no duplicate definition.` |
| NC-0001OG | 0001OG | `// Exact two-byte storage is emitted by UID0000SU g_screenWidth; this by-memory child records bytes/xrefs only and emits no duplicate definition.` |
| NC-0000YQ | 0000YQ | `// Compiler-emitted _AUTOBUF<wchar_t>/LObject cleanup wrapper for Application error text; this deleting-destructor range emits no hand-written Application source body.` |
| NC-0000YR | 0000YR | `// Application lifecycle aggregate emits no standalone body; exact child pages in this range carry constructor, startup, cleanup, message-loop, helper, wrapper, and data reconstruction.` |
| NC-0000YT | 0000YT | `// No first-draft body is emitted for CheckTimerSkewAndSendHeartbeat; UID0000YT documents the 0x40d-byte timer-skew and heartbeat behavior, but current evidence does not safely collapse packet byte writing, function-local static guards, crash diagnostic sender ownership, and g_pUserPane session-byte use into one source-quality helper body.` |
| NC-0000YX | 0000YX | `// No first-draft body is emitted for LoadIndexedDATSeries; UID0000YX documents the verified DAT-series algorithm, but current evidence does not safely choose the formatter count/buffer source shape, DAT manager wrapper expression, and StringBase-to-fatal-dialog conversion needed for source-quality C++.` |
| NC-00019H | 00019H | `// BaramApp/Application startup aggregate emits no standalone body; exact child pages carry the raw BaramApp constructor, terminal callback, Application startup/shutdown, thunks, wrappers, and padding evidence.` |
| NC-00047Y | 00047Y | `// Compiler-emitted Application RTTI locator pointer; class RTTI is regenerated from class declarations and emits no standalone Application.cpp data definition here.` |
| NC-0003OD | 0003OD | `// Compiler-emitted Application vtable data; vtable entries are regenerated from Application virtual declarations and exact method children, not emitted as a standalone array.` |
| NC-00047Z | 00047Z | `// Shared pooled wide path-separator literal is emitted at source use sites such as version-resource root queries and path construction; no standalone data definition is emitted here.` |
| NC-000484 | 000484 | `// Application registry/display strings are pooled .rdata literals emitted at their documented source use sites; this range emits no standalone static string table.` |
| NC-000485 | 000485 | `// Application startup resource strings are pooled literals emitted by startup/DAT-loading use sites; this range emits no standalone static string table.` |
| NC-000487 | 000487 | `// Application patch, version, and error strings are pooled literals emitted at version/license/fatal/error use sites; this range emits no standalone static string table.` |
| NC-000292 | 000292 | `// Combined Application _AUTOBUF<wchar_t> error text and critical-section storage emits no standalone declaration from this range; source declarations require separate AUTOBUF and synchronization ownership, while this page preserves exact storage/use evidence.` |
| NC-000293 | 000293 | `// Combined Application OSVERSIONINFOW storage and formatted OS-label buffer emits no standalone declaration from this range; constructor-owned initialization and diagnostic-label use are documented here without guessing a byte blob or environment-state struct.` |
| NC-0002VU | 0002VU | `// Heartbeat/timer-skew function-local state and MSVC local-static guard dwords for UID0000YT emit no standalone definitions; guard storage is compiler-generated and source statics belong inside the helper body if that body is later emitted.` |

### Duplicate/Index Metadata Repairs

- UID0000T5 `by-global/LoadIndexedDATSeries.md`: exact callback repair is `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:0000HG` retained, `EMITTER_UIDS:` blank, `EMITTER_POSITION_OPTIONAL:` blank, and formal `RECONSTRUCTION_CPP CODE` blank. Add a body note: "This by-global page is the canonical symbol/index for LoadIndexedDATSeries; exact executable behavior and any formal source/no-code marker live on UID0000YX, so this page is intentionally non-emitting and must not duplicate the exact by-memory route."
- UID0000U8 `by-item/CheckTimerSkewAndSendHeartbeat_466CA0.md`: exact callback repair is `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:0000HG` retained, `EMITTER_UIDS:` blank, `EMITTER_POSITION_OPTIONAL:` blank, and formal `RECONSTRUCTION_CPP CODE` blank. Add a body note: "This by-item page is a search/index alias for the exact UID0000YT memory page; UID0000YT owns the source/no-code decision, so this item is intentionally non-emitting."

### Rare No-Improvement Proofs

UID0000YT no-improvement proof:
- Evidence tried: current MCP decompile, exact boundary/caller proof, callee set, string refs, data refs through UID000291/UID0002VU/UID0002VX, `Application::RunMessageLoop` caller decompile, crash diagnostic sender docs, packet sender docs, and `g_pUserPane`/`g_pCollectionData` docs.
- First-draft body alternative rejected: a monolithic helper body would require inventing packet-writer source abstractions for the repeated `0x00575380` byte appends, the meaning/name of `g_pUserPane + 0x1a0`, the function-local static declarations represented by MSVC guard dwords, and the exact diagnostic sender member/source file. Those are not cosmetic names; they change ownership across Application, Socket/packet queue, ExceptionHandler, and UserPane.
- Split alternative rejected for this callback: no internal function boundaries exist inside `0x00466ca0-0x004670ad`; splitting clock-skew and heartbeat code into child functions would invent source functions not present in current MCP.
- Score impact: keep UID0000YT at `88/91`. The page is behaviorally strong but a source body would be weaker than the evidence. The exact formal marker is an improvement over blank C++ and should remove the empty marker.

UID0000YX no-improvement proof:
- Evidence tried: current MCP decompile, 19 Application::Initialize call sites, current callee refs, UID0000T5 by-global symbol page, UID00012C DAT manager wrapper docs, fatal helper UID0002VI, startup archive resource docs, and generated Application.cpp state.
- First-draft body alternative rejected: source-quality C++ would have to choose between a local `wchar_t[64]` buffer and the observed formatter count `0x28`, model `0x00583280/0x00584540` as a specific StringBase/temporary-wide-string expression, and choose a DAT manager method expression for wrapper `0x0049be70`. A simplified `swprintf_s`/`g_pDATFileMgr->Load...` body would be readable but would erase the documented helper and temporary-string boundaries current MCP exposes.
- Duplicate alternative rejected: UID0000T5 must not also emit this body because it is a by-global symbol/index over the exact by-memory page.
- Score impact: keep UID0000YX at `90/94`. Behavior and ownership are high confidence; withholding source C++ is the only no-loss option under the current source-quality standard.

UID000292 no-improvement proof:
- Evidence tried: current zero bytes, field xrefs, startup initializer/cleanup thunk docs, `Application::RunMessageLoop` critical-section use, window-procedure error-text replacement path, B005 `_AUTOBUF<wchar_t>` RTTI/vtable resolution, and critical-section wrapper docs.
- Declaration alternative rejected: `static _AUTOBUF<wchar_t> s_applicationErrorText; static CRITICAL_SECTION s_messageHandlerCriticalSection;` is plausible but not exact for this combined page. The `0x0067a9a4-0x0067a9c0` synchronization storage is `0x1c` bytes in the modeled range while a plain Win32 `CRITICAL_SECTION` is not proven as the only source declaration shape, and emitting both declarations here would mix AUTOBUF and synchronization ownership without splitting the page.
- Split plan if future implementation wants code: split `0x0067a998-0x0067a9a4` as the AUTOBUF error text object and `0x0067a9a4-0x0067a9c0` as the Application message-handler critical-section/wrapper storage, then emit declarations on the exact children. This report does not request new files during the revision.
- Score impact: keep UID000292 at `86/91`; formal marker improves generated output without claiming final declaration grouping.

UID000293 no-improvement proof:
- Evidence tried: current zero bytes over `0x158`, constructor xrefs, OS label string refs, UID0002GY constructor docs, UID0000YT diagnostic-label use, ignored next ATL flag boundary, and per-object OS field docs.
- Declaration alternative rejected: a `OSVERSIONINFOW` plus `char[64]` declaration would not account for the four-byte interior gap and would choose a separate-global layout over the still-plausible environment-state struct. A raw `unsigned char[0x158]` initializer would preserve bytes but would be lower source quality than the documentation.
- Score impact: keep UID000293 at `88/91`; source-owned state is proven, but current evidence does not improve beyond a precise no-code marker.

UID0002VU no-improvement proof:
- Evidence tried: current zero bytes, UID0000YT decompile, guard calls to `_Init_thread_header/_Init_thread_footer`, per-slot refs, predecessor/successor boundaries, and `Application::RunMessageLoop`/UID0002VX separation.
- Declaration alternative rejected: source-visible definitions for the guard dwords would be wrong because they are compiler-generated local-static guards, while definitions for the tick/latch dwords belong inside UID0000YT if that helper body is later emitted. Emitting a mixed standalone data block would duplicate compiler support.
- Score impact: keep UID0002VU at `88/91`; the formal marker is the exact current improvement.

No third-party import directive is applicable.

## Recommended Target Doc Changes

### `by-file/Application.md`

- Update metadata `COMPLETION:86 -> 88`, `CONFIDENCE:90 -> 91`.
- Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/"`.
- Keep `CANONICAL_OWNER:FILE`.
- Add a 2026-06-29 B013 empty-emitter family recheck section at report-level detail:
  - current MCP session/database facts;
  - generated header `000000001256` / `2026-06-29T21:40:04-04:00`;
  - all 39 marker rows and their classification;
  - first-draft code subset, no-code/comment subset, and exact duplicate/index metadata repairs;
  - note that current MCP reads zero bytes for the Application writable state ranges where older child docs mention `0xff`;
  - rejected owner/source-file alternatives;
  - generated refresh expectation after validators.

### Support docs to update with first-draft code

- `by-memory/0x00465690-0x0046572d.ApplicationMapFromScreen.md`: update old code-gate text, add current MCP evidence, proposed `m_currentScreenHeight` / `m_currentScreenWidth` names, formal C++; recommended score `86/91 -> 88/93`.
- `by-memory/0x00465730-0x004657cd.ApplicationMapToScreen.md`: same paired update; recommended score `86/91 -> 88/93`.
- `by-memory/0x00465bb0-0x00465bbd.ApplicationDestroyLoadingDialog.md`: formal C++; recommended score `86/92 -> 88/94`.
- `by-memory/0x004651f0-0x004652dc.BuildExecutablePathForVersionInfo.md`: replace stale "do not emit until placement/name verified" text with current MCP decompile evidence, formal FD-0002JX C++, and score `86/88 -> 88/91`.
- `by-memory/0x00465320-0x00465424.GetExecutableVersionLowWord.md`: replace stale helper/source-placement blocker text with current MCP decompile evidence, formal FD-0002JZ C++, and score `86/88 -> 88/91`.
- `by-memory/0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak.md`: formal C++; recommended score `87/90 -> 89/92`.
- `by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md`: formal C++; recommended score `88/91 -> 89/92`.
- `by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md`: formal C++; recommended score `88/91 -> 89/92`.
- `by-memory/0x004673e0-0x004673e6.GetApplicationSingleton.md`: formal C++; recommended score `85/88 -> 88/92`.
- `by-global/g_screenWidth.md`: formal `short g_screenWidth = 1024;`; recommended score `88/91 -> 90/93`.
- `by-global/g_screenHeight.md`: formal `short g_screenHeight = 768;`; recommended score `88/91 -> 90/93`.
- `by-memory/0x0066d408-0x0066d410.DisplayStartupPresentationGlobals.md`: formal FD-00035N `g_displayStartupWidth` / `g_displayStartupDrawType`; current bytes `00 04 00 00 01 00 00 00`; recommended score `86/90 -> 88/92`.
- `by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md`: formal FD-00028Z `g_applicationPhaseState` / `g_applicationActiveGate`; current zero bytes; recommended score `86/90 -> 88/92`.
- `by-memory/0x0067a980-0x0067a998.ApplicationTimingBaselines.md`: formal FD-000291 zero-initialized baseline/counter declarations; explicitly supersede stale `0xff` byte wording with current MCP zero bytes; recommended score `87/91 -> 89/92`.
- `by-memory/0x0067ab70-0x0067ab7c.ApplicationMessageLoopInputCounters.md`: formal FD-0002VX zero-initialized counter/accumulator declarations; explicitly supersede stale `0xff` byte wording with current MCP zero bytes; recommended score `87/90 -> 89/92`.

### Support docs to update with no-code/comment markers

Update the formal block and body notes using the exact NC marker text above for: `by-class/Application.md`, `by-class/BaramApp.md`, UID0002GY, UID000323, UID0003P3, UID0003P4, UID0001OI, UID0001OG, UID0000YQ, UID0000YR, UID0000YT, UID0000YX, UID00019H, UID00047Y, UID0003OD, UID00047Z, UID000484, UID000485, UID000487, UID000292, UID000293, and UID0002VU.

### Duplicate/index route repair

- `by-item/CheckTimerSkewAndSendHeartbeat_466CA0.md`: set `RECONSTRUCTABLE:FALSE`, retain `CANONICAL_OWNER:0000HG`, clear `EMITTER_UIDS`, clear `EMITTER_POSITION_OPTIONAL`, keep formal C++ blank, and add the exact index note from the duplicate repair section. The exact source/no-code decision remains UID0000YT.
- `by-global/LoadIndexedDATSeries.md`: set `RECONSTRUCTABLE:FALSE`, retain `CANONICAL_OWNER:0000HG`, clear `EMITTER_UIDS`, clear `EMITTER_POSITION_OPTIONAL`, keep formal C++ blank, and add the exact index note from the duplicate repair section. The exact source/no-code decision remains UID0000YX.

## Score And Metadata Recommendation

- `by-file/Application.md`: `86/90 -> 88/91`.
  - Reason higher: current MCP verifies the generated empty state and this revised report gives implementation-ready actions for every marker, including first-draft C++ for the coordinate/loading/fatal/delete/version/singleton helpers, display globals, lifecycle/timing globals, and message-loop counters.
  - Reason not higher: broad Application/BaramApp class declarations, constructor, DAT/timer helpers, combined AUTOBUF/critical-section storage, combined OS-version state, local-static guard storage, string pools, vtables, RTTI, and compiler wrappers still correctly resolve as markers or non-emitting index pages rather than executable source bodies.
- Keep file owner/path unchanged.
- No split/rename/new source file recommended.
- No third-party import recommended.

## Negative Evidence Summary

- No evidence supports moving the file root away from `NexusTK/app/Application.cpp`.
- No evidence supports treating UID0002GS/UID0002GT as Win32 `POINT` methods; caller docs and current formulas still show vertical/height slot `0` and horizontal/width slot `1`.
- No evidence supports emitting the Application scalar deleting destructor as a normal C++ destructor body; it is compiler-wrapper shaped and duplicates/desynchronizes the ordinary destructor if hand-written.
- No evidence supports duplicate standalone function bodies on both by-global/by-item index pages and exact by-memory pages.
- No evidence supports standalone static string arrays for the pooled literal pages; those bytes are best represented by source-use expressions or compiler/linker pooling.
- No evidence supports broad executable bodies for `ApplicationLifecycle` or `BaramAppAndApplicationStartup`; exact children already carry the source bodies/markers.
- No current evidence supports source-quality executable bodies for UID0000YT or UID0000YX in this pass. UID0000YT would invent packet/protocol/local-static/diagnostic ownership details; UID0000YX would invent formatter/StringBase/DAT-manager expression details despite a verified high-level algorithm.
- No current evidence supports standalone declarations for UID000292, UID000293, or UID0002VU without splitting or inventing compiler/static support. Their exact marker text is a source-quality improvement over blank formal blocks.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | MCP is currently available as `supervisor_resume_20260629`, health ok, Hex-Rays ready, strings cache ready, worker PID `17592`, and the one wrapper `database is required` result was a local wrapper bug. | High | 2026-06-29 MCP `idb_list`, `server_health`, corrected decompile/get_bytes calls. | `by-file/Application.md` B013 revised MCP evidence. | incorporate | applied: `by-file/Application.md` section `2026-06-29 B013 Application Empty-Emitter Family Implementation`; validator `000000001326` exit `0`, `ok:1`. |
| C2 | Generated `auto-generated/NexusTK/app/Application.cpp` header is `validator-command-id:000000001256`, `validator-refreshed-at:2026-06-29T21:40:04-04:00`, and contains 39 UID0000HG empty markers. | High | Read-only generated file inspection. | `by-file/Application.md` generated-state section. | incorporate | applied and superseded by final generated check: `auto-generated/NexusTK/app/Application.cpp` now has `EMPTY/TODO/empty marker/RECONSTRUCTION_CPP` count `0`; validator refresh command `000000001373` exit `0`, `generated_refresh:completed`. |
| C3 | Application file root/path/owner remain correct; use metadata `COMPLETION:88`, `CONFIDENCE:91`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/app/"`, `CANONICAL_OWNER:FILE`. | High | Generated root, by-file docs, helper/data dependencies. | `by-file/Application.md` metadata and score rationale. | incorporate | applied: header is `COMPLETION:88`, `CONFIDENCE:91`, path/owner unchanged; validator `000000001326` exit `0`, `ok:1`. |
| C4 | UID0002GS and UID0002GT are first-draft code-ready as explicit two-`int` pair coordinate mappers, not Win32 `POINT`. | High | Current MCP formulas/xrefs and Application field/global evidence. | UID0002GS, UID0002GT, `by-class/Application.md`, `by-file/Application.md`. | insert FD-0002GS/FD-0002GT; score to `88/93` | applied: UID0002GS validator `000000001331`, UID0002GT validator `000000001332`, both exit `0`, `ok:1`; generated lines include both method bodies. |
| C5 | UID0002GW is first-draft code-ready as `DestroyWindow(m_hLoadingDlg)`. | High | Current MCP three-instruction body and startup xref. | UID0002GW; Application class/file docs. | insert FD-0002GW; score to `88/94` | applied: UID0002GW validator `000000001333` exit `0`, `ok:1`; generated line includes `Application::DestroyLoadingDialog()`. |
| C6 | UID0002JX and UID0002JZ are now first-draft code-ready; stale helper/source-placement blockers are superseded by current decompile and existing UID0002H6 helper use. | Medium-high | Current MCP decompiles, PlatformApi VERSION dispatch docs, UID0002H6 formal C++ call shape. | UID0002JX, UID0002JZ, lifecycle/file support docs. | insert FD-0002JX/FD-0002JZ; score to `88/91` each | applied: UID0002JX validator `000000001345`, UID0002JZ validator `000000001346`, both exit `0`, `ok:1`; generated `VerQueryValueW` root literal is `L"\\"`. |
| C7 | UID0002VI, UID0000YV, UID0000YW, and UID00032B are first-draft helper-ready and must not add global clearing beyond observed delete wrappers. | High | Current disasm/decompile/bytes/xrefs. | Four by-memory helper docs; file/class support. | insert FD-0002VI/FD-0000YV/FD-0000YW/FD-00032B; score as listed | applied: validators `000000001347`, `000000001349`, `000000001350`, `000000001351`, all exit `0`, `ok:1`. |
| C8 | UID0000SU and UID0000ST should emit signed `short` definitions; UID0001OG/UID0001OI should emit covered-by comments only. | High | Current bytes at `0x0066da94`, movsx use, global docs. | Two by-global docs and two by-memory storage docs. | insert FD-0000SU/FD-0000ST and NC-0001OG/NC-0001OI | applied: validators `000000001338`, `000000001339`, `000000001340`, `000000001341`, all exit `0`, `ok:1`; generated contains `short g_screenHeight` and `short g_screenWidth`. |
| C9 | UID00035N, UID00028Z, UID000291, and UID0002VX are first-draft global-data ready with role-based names; current MCP zero bytes supersede stale `0xff` wording for UID000291/UID0002VX. | Medium-high | Current MCP `get_bytes`, `Application::RunMessageLoop`, `Main_WndProc`, existing xref docs. | Four by-memory data docs; `by-file/Application.md`. | insert FD-00035N/FD-00028Z/FD-000291/FD-0002VX; scores as listed | applied: validators `000000001360`, `000000001361`, `000000001362`, `000000001366`, all exit `0`, `ok:1`; generated contains all four declaration groups. |
| C10 | UID00000D and UID00000V should use exact broad class no-code markers, not blank formal blocks or incomplete class declarations. | High | Current class docs, child inventories, generated markers. | `by-class/Application.md`, `by-class/BaramApp.md`. | insert NC-00000D/NC-00000V | applied with required `[[CHILDREN]]` insertion point: validators `000000001370`, `000000001371`, both exit `0`, `ok:1`. |
| C11 | UID0002GY, UID000323, and UID0000YQ should use exact constructor/compiler-wrapper/AUTOBUF cleanup markers. | High | Current constructor/destructor/error-state docs and MCP wrapper evidence. | Three by-memory docs. | insert NC-0002GY/NC-000323/NC-0000YQ | applied: validators `000000001330`, `000000001334`, `000000001343`, all exit `0`, `ok:1`. |
| C12 | UID0000YR and UID00019H are aggregate parents; exact children carry source and these pages should emit only aggregate markers. | High | Current aggregate docs and child lists. | Two aggregate by-memory docs; file support. | insert NC-0000YR/NC-00019H | applied: UID0000YR validator `000000001372` exit `0`, `ok:1` with `[[CHILDREN]]`; UID00019H validator `000000001353` exit `0`, `ok:1`. |
| C13 | UID0003P3, UID0003P4, UID00047Y, UID0003OD, UID00047Z, UID000484, UID000485, and UID000487 are string/vtable/RTTI/literal pools and need exact no-standalone markers. | High | Current bytes/docs for `.rdata`, callback table, RTTI/vtable, pooled literals. | Listed by-memory docs and file support. | insert listed NC markers | applied: validators `000000001335`, `000000001336`, `000000001354`, `000000001355`, `000000001356`, `000000001357`, `000000001358`, `000000001359`, all exit `0`, `ok:1`. |
| C14 | UID0000T5 is a duplicate by-global symbol/index over UID0000YX and must become non-emitting with exact metadata, not a second body or blank marker. | High | UID0000T5 and UID0000YX docs; generated duplicate marker. | `by-global/LoadIndexedDATSeries.md`. | set `RECONSTRUCTABLE:FALSE`, clear emitters/position/code, add index note | applied: validator `000000001337` exit `0`, `ok:1`; generated Application.cpp has no UID0000T5 row. |
| C15 | UID0000U8 is a duplicate by-item index over UID0000YT and must become non-emitting with exact metadata, not a second body or blank marker. | High | UID0000U8 and UID0000YT docs; generated duplicate marker. | `by-item/CheckTimerSkewAndSendHeartbeat_466CA0.md`. | set `RECONSTRUCTABLE:FALSE`, clear emitters/position/code, add index note | applied: validator `000000001342` exit `0`, `ok:1`; generated Application.cpp has no UID0000U8/by-item row. |
| C16 | UID0000YT should receive NC-0000YT plus the rare no-improvement proof; a monolithic body would invent packet/local-static/diagnostic/UserPane ownership details. | High | Current MCP decompile, caller/callee/data refs, supporting packet/diagnostic docs. | UID0000YT and `by-file/Application.md`. | insert marker/proof; no score change | applied: validator `000000001348` exit `0`, `ok:1`; generated contains accepted UID0000YT no-first-draft marker. |
| C17 | UID0000YX should receive NC-0000YX plus the rare no-improvement proof; behavior is verified but first-draft C++ would invent formatter/StringBase/DAT-manager expression details. | High | Current MCP decompile, UID0000T5, UID00012C, UID0002VI, startup archive docs. | UID0000YX and `by-file/Application.md`. | insert marker/proof; no score change | applied: validator `000000001352` exit `0`, `ok:1`; generated contains accepted UID0000YX no-first-draft marker. |
| C18 | UID000292 should receive NC-000292 plus no-improvement proof; combined AUTOBUF and critical-section storage should not emit guessed declarations from one page. | Medium-high | Current bytes/xrefs, AUTOBUF RTTI docs, critical-section consumer docs. | UID000292 and file support. | insert marker/proof; no score change | applied: validator `000000001363` exit `0`, `ok:1`; generated contains accepted UID000292 no-standalone declaration marker. |
| C19 | UID000293 should receive NC-000293 plus no-improvement proof; OSVERSIONINFOW/label state should not be emitted as guessed globals or byte blob. | Medium-high | Current zero bytes, constructor/diagnostic xrefs, boundary docs. | UID000293 and file support. | insert marker/proof; no score change | applied: validator `000000001364` exit `0`, `ok:1`; generated contains accepted UID000293 no-standalone declaration marker. |
| C20 | UID0002VU should receive NC-0002VU plus no-improvement proof; MSVC local-static guards are compiler support and source statics belong inside UID0000YT if later emitted. | High | Current zero bytes, UID0000YT decompile, `_Init_thread_header/footer` refs. | UID0002VU and UID0000YT support. | insert marker/proof; no score change | applied: validator `000000001365` exit `0`, `ok:1`; generated contains accepted UID0002VU guard-storage marker. |
| C21 | No third-party import, split, rename, new file, generated-file manual edit, coverage-report edit, or lease is required during report revision. | High | Assignment restrictions and current evidence. | Report checklist and final response. | already-followed in report-only mode | applied/excluded-with-reason: no third-party import/split/rename/new by-* files/manual generated edit; implementation used leases before editing, but release attempts returned `Rejected[No active lease]` for all 40 because no B013 leases remained in `current_leases.md`; validator `--wait-generated` refreshed generated outputs as part of the required generated freshness check. |

## Validator Results

All scoped validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation` with:

> Executable block R001 was removed from this report and preserved verbatim in [0000HG-Application-empty-emitter-family-source-quality-removed.md](0000HG-Application-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

The first by-file validator was `000000001326`; all 39 remaining initial scoped validators were `000000001328` through `000000001366`; after adding required `[[CHILDREN]]` insertion points, the affected docs were revalidated as `000000001370` through `000000001372`. Final generated refresh used:

> Executable block R002 was removed from this report and preserved verbatim in [0000HG-Application-empty-emitter-family-source-quality-removed.md](0000HG-Application-empty-emitter-family-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Final generated refresh result: command_id `000000001373`, command_timestamp `2026-06-29T22:40:00-04:00`, exit `0`, `ok:1`, `generated_refresh:completed`.

Scoped validator matrix:

| Path | command_id | command_timestamp | Exit | ok | generated_refresh |
| --- | --- | --- | ---: | ---: | --- |
| `by-file/Application.md` | `000000001326` | `2026-06-29T22:32:58-04:00` | 0 | 1 | deferred |
| `by-class/Application.md` | `000000001370` | `2026-06-29T22:39:43-04:00` | 0 | 1 | deferred |
| `by-class/BaramApp.md` | `000000001371` | `2026-06-29T22:39:50-04:00` | 0 | 1 | deferred |
| `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md` | `000000001330` | `2026-06-29T22:33:55-04:00` | 0 | 1 | deferred |
| `by-memory/0x00465690-0x0046572d.ApplicationMapFromScreen.md` | `000000001331` | `2026-06-29T22:33:57-04:00` | 0 | 1 | deferred |
| `by-memory/0x00465730-0x004657cd.ApplicationMapToScreen.md` | `000000001332` | `2026-06-29T22:33:59-04:00` | 0 | 1 | deferred |
| `by-memory/0x00465bb0-0x00465bbd.ApplicationDestroyLoadingDialog.md` | `000000001333` | `2026-06-29T22:34:00-04:00` | 0 | 1 | deferred |
| `by-memory/0x00467230-0x004672b7.ApplicationScalarDeletingDestructor.md` | `000000001334` | `2026-06-29T22:34:02-04:00` | 0 | 1 | deferred |
| `by-memory/0x0061d140-0x0061d234.BaramAppStartupUpdateStrings.md` | `000000001335` | `2026-06-29T22:34:04-04:00` | 0 | 1 | deferred |
| `by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md` | `000000001336` | `2026-06-29T22:34:06-04:00` | 0 | 1 | deferred |
| `by-global/LoadIndexedDATSeries.md` | `000000001337` | `2026-06-29T22:34:08-04:00` | 0 | 1 | deferred |
| `by-global/g_screenHeight.md` | `000000001338` | `2026-06-29T22:34:10-04:00` | 0 | 1 | deferred |
| `by-memory/0x0066da98-0x0066da9a.g_screenHeight.md` | `000000001339` | `2026-06-29T22:34:11-04:00` | 0 | 1 | deferred |
| `by-global/g_screenWidth.md` | `000000001340` | `2026-06-29T22:34:13-04:00` | 0 | 1 | deferred |
| `by-memory/0x0066da94-0x0066da96.g_screenWidth.md` | `000000001341` | `2026-06-29T22:34:15-04:00` | 0 | 1 | deferred |
| `by-item/CheckTimerSkewAndSendHeartbeat_466CA0.md` | `000000001342` | `2026-06-29T22:34:17-04:00` | 0 | 1 | deferred |
| `by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md` | `000000001343` | `2026-06-29T22:34:19-04:00` | 0 | 1 | deferred |
| `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md` | `000000001372` | `2026-06-29T22:39:52-04:00` | 0 | 1 | deferred |
| `by-memory/0x004651f0-0x004652dc.BuildExecutablePathForVersionInfo.md` | `000000001345` | `2026-06-29T22:34:22-04:00` | 0 | 1 | deferred |
| `by-memory/0x00465320-0x00465424.GetExecutableVersionLowWord.md` | `000000001346` | `2026-06-29T22:34:24-04:00` | 0 | 1 | deferred |
| `by-memory/0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak.md` | `000000001347` | `2026-06-29T22:34:26-04:00` | 0 | 1 | deferred |
| `by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md` | `000000001348` | `2026-06-29T22:34:28-04:00` | 0 | 1 | deferred |
| `by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md` | `000000001349` | `2026-06-29T22:34:30-04:00` | 0 | 1 | deferred |
| `by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md` | `000000001350` | `2026-06-29T22:34:32-04:00` | 0 | 1 | deferred |
| `by-memory/0x004673e0-0x004673e6.GetApplicationSingleton.md` | `000000001351` | `2026-06-29T22:34:33-04:00` | 0 | 1 | deferred |
| `by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md` | `000000001352` | `2026-06-29T22:34:35-04:00` | 0 | 1 | deferred |
| `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md` | `000000001353` | `2026-06-29T22:34:37-04:00` | 0 | 1 | deferred |
| `by-memory/0x006125e0-0x006125e4.ApplicationRttiLocatorPointer.md` | `000000001354` | `2026-06-29T22:34:39-04:00` | 0 | 1 | deferred |
| `by-memory/0x006125e4-0x0061260c.ApplicationVtableData.md` | `000000001355` | `2026-06-29T22:34:40-04:00` | 0 | 1 | deferred |
| `by-memory/0x0061260c-0x00612610.SharedWidePathSeparatorLiteral.md` | `000000001356` | `2026-06-29T22:34:42-04:00` | 0 | 1 | deferred |
| `by-memory/0x00612980-0x00612b24.ApplicationRegistryDisplayStringData.md` | `000000001357` | `2026-06-29T22:34:44-04:00` | 0 | 1 | deferred |
| `by-memory/0x00612b24-0x00612e3c.ApplicationStartupResourceStringData.md` | `000000001358` | `2026-06-29T22:34:46-04:00` | 0 | 1 | deferred |
| `by-memory/0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData.md` | `000000001359` | `2026-06-29T22:34:48-04:00` | 0 | 1 | deferred |
| `by-memory/0x0066d408-0x0066d410.DisplayStartupPresentationGlobals.md` | `000000001360` | `2026-06-29T22:34:49-04:00` | 0 | 1 | deferred |
| `by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md` | `000000001361` | `2026-06-29T22:34:51-04:00` | 0 | 1 | deferred |
| `by-memory/0x0067a980-0x0067a998.ApplicationTimingBaselines.md` | `000000001362` | `2026-06-29T22:34:53-04:00` | 0 | 1 | deferred |
| `by-memory/0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics.md` | `000000001363` | `2026-06-29T22:34:55-04:00` | 0 | 1 | deferred |
| `by-memory/0x0067a9c0-0x0067ab18.ApplicationOsVersionState.md` | `000000001364` | `2026-06-29T22:34:57-04:00` | 0 | 1 | deferred |
| `by-memory/0x0067ab5c-0x0067ab70.ApplicationHeartbeatTimerSkewGlobals.md` | `000000001365` | `2026-06-29T22:34:59-04:00` | 0 | 1 | deferred |
| `by-memory/0x0067ab70-0x0067ab7c.ApplicationMessageLoopInputCounters.md` | `000000001366` | `2026-06-29T22:35:01-04:00` | 0 | 1 | deferred |

Validator-output notes:
- Every scoped by-* validator exited `0` and reported `ok:1`.
- Revalidation commands `000000001370`, `000000001371`, and `000000001372` supersede the initial validators for `by-class/Application.md`, `by-class/BaramApp.md`, and `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md` because those three rows needed `[[CHILDREN]]` insertion points for accepted child emission.
- Final generated refresh command `000000001373` exited `0`, reported `ok:1`, and `generated_refresh:completed`.
- The final refresh output still reports project-wide pre-existing `autogen_children_marker_missing` warnings for unrelated emitters and for `UID0000ST`/`UID0000SU`; no warning remains for `UID00000D`, `UID00000V`, or `UID0000YR`.

Generated `Application.cpp` check:
- Path: `auto-generated/NexusTK/app/Application.cpp`.
- Final generated refresh command: `000000001373`, timestamp `2026-06-29T22:40:00-04:00`, `generated_refresh:completed`.
- File write time after refresh: `2026-06-29 22:40:23` local.
- File header still records `validator-command-id:000000001363`, `validator-refreshed-at:2026-06-29T22:34:55-04:00`, `validator-refresh-source:deferred-generated-refresh`; this header metadata did not advance to the final wait-generated command even though the file content and write time did.
- Required accepted rows are present in generated output: UID0002GS, UID0002GT, UID0002GW, UID0002JX, UID0002JZ, UID00035N, UID00028Z, UID000291, and UID0002VX.
- `EMPTY`, `TODO`, `empty marker`, and `RECONSTRUCTION_CPP CODE` counts are all `0`.
- `No first-draft body` count is `4`: accepted/existing markers for UID0002GZ, UID0002H0, UID0000YT, and UID0000YX.
- UID0000T5 and UID0000U8 do not appear in generated `Application.cpp`; the non-emitting duplicate/index repairs worked.

## Changed Files

Changed by-* docs:

- `by-file/Application.md`
- `by-class/Application.md`
- `by-class/BaramApp.md`
- `by-memory/0x00463310-0x0046396e.ApplicationConstructor.md`
- `by-memory/0x00465690-0x0046572d.ApplicationMapFromScreen.md`
- `by-memory/0x00465730-0x004657cd.ApplicationMapToScreen.md`
- `by-memory/0x00465bb0-0x00465bbd.ApplicationDestroyLoadingDialog.md`
- `by-memory/0x00467230-0x004672b7.ApplicationScalarDeletingDestructor.md`
- `by-memory/0x0061d140-0x0061d234.BaramAppStartupUpdateStrings.md`
- `by-memory/0x0061d234-0x0061d24c.BaramAppCallbackVtableData.md`
- `by-global/LoadIndexedDATSeries.md`
- `by-global/g_screenHeight.md`
- `by-memory/0x0066da98-0x0066da9a.g_screenHeight.md`
- `by-global/g_screenWidth.md`
- `by-memory/0x0066da94-0x0066da96.g_screenWidth.md`
- `by-item/CheckTimerSkewAndSendHeartbeat_466CA0.md`
- `by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md`
- `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`
- `by-memory/0x004651f0-0x004652dc.BuildExecutablePathForVersionInfo.md`
- `by-memory/0x00465320-0x00465424.GetExecutableVersionLowWord.md`
- `by-memory/0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak.md`
- `by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md`
- `by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md`
- `by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md`
- `by-memory/0x004673e0-0x004673e6.GetApplicationSingleton.md`
- `by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md`
- `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md`
- `by-memory/0x006125e0-0x006125e4.ApplicationRttiLocatorPointer.md`
- `by-memory/0x006125e4-0x0061260c.ApplicationVtableData.md`
- `by-memory/0x0061260c-0x00612610.SharedWidePathSeparatorLiteral.md`
- `by-memory/0x00612980-0x00612b24.ApplicationRegistryDisplayStringData.md`
- `by-memory/0x00612b24-0x00612e3c.ApplicationStartupResourceStringData.md`
- `by-memory/0x00612e54-0x00612f38.ApplicationPatchAndVersionStringData.md`
- `by-memory/0x0066d408-0x0066d410.DisplayStartupPresentationGlobals.md`
- `by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md`
- `by-memory/0x0067a980-0x0067a998.ApplicationTimingBaselines.md`
- `by-memory/0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics.md`
- `by-memory/0x0067a9c0-0x0067ab18.ApplicationOsVersionState.md`
- `by-memory/0x0067ab5c-0x0067ab70.ApplicationHeartbeatTimerSkewGlobals.md`
- `by-memory/0x0067ab70-0x0067ab7c.ApplicationMessageLoopInputCounters.md`

Agent/report artifacts:
- This report.
- Validation logs under `tools/leaser/Agents/Agent-B013/validation/0000HG-implementation-20260629/`.

Generated/tool-state note:
- No generated file was manually edited.
- Validator command `000000001373` performed the required generated refresh and reported `generated_metadata_refresh` rows for generated outputs and generated reports, plus validator/autogen backups. This was validator-generated output, not hand editing.

Lease facts:
- Leases were acquired successfully for all 40 changed by-* docs before editing.
- After the edit/validator/generated-refresh batch, `python .\tools\leaser\leaser.py B013 unlease <path>` returned `Rejected[No active lease]` for every one of the 40 paths.
- `tools/leaser/Agents/current_leases.md` then showed no B013 leases. Active leases visible at that time belonged to Agent-B004 and B002 only.

## Implementation Tracking Checklist

- [x] Supervisor accepted the revised report for implementation under the bounded callback.
- [x] Read updated Agent-B013 `goal.md` and the project `ntk-b-agent-workflow` skill before implementation.
- [x] Used current MCP session `supervisor_resume_20260629`; did not continue with fallback-only evidence.
- [x] Did not spawn subagents.
- [x] Leased the 40 accepted by-* docs immediately before editing. Release attempts after the edit/validator batch returned `Rejected[No active lease]` for all 40; `current_leases.md` confirmed no B013 leases remained.
- [x] Updated `by-file/Application.md`: metadata `88/91`, path and `CANONICAL_OWNER:FILE` preserved, B013 implementation section added with MCP state, generated initial/final state, code/no-code/index dispositions, no-improvement proofs, rejected alternatives, and score rationale. Validator `000000001326`, exit `0`, `ok:1`.
- [x] Inserted FD-0002GS in `by-memory/0x00465690-0x0046572d.ApplicationMapFromScreen.md`; score `88/93`; validator `000000001331`, exit `0`, `ok:1`.
- [x] Inserted FD-0002GT in `by-memory/0x00465730-0x004657cd.ApplicationMapToScreen.md`; score `88/93`; validator `000000001332`, exit `0`, `ok:1`.
- [x] Inserted FD-0002GW in `by-memory/0x00465bb0-0x00465bbd.ApplicationDestroyLoadingDialog.md`; score `88/94`; validator `000000001333`, exit `0`, `ok:1`.
- [x] Inserted FD-0002JX in `by-memory/0x004651f0-0x004652dc.BuildExecutablePathForVersionInfo.md`; stale source-placement blocker superseded; validator `000000001345`, exit `0`, `ok:1`.
- [x] Inserted FD-0002JZ in `by-memory/0x00465320-0x00465424.GetExecutableVersionLowWord.md`; stale source-placement blocker superseded and generated root literal is `L"\\"`; validator `000000001346`, exit `0`, `ok:1`.
- [x] Inserted FD-0002VI in `by-memory/0x00465cb0-0x00465ce0.FatalErrorDialogAndBreak.md`; validator `000000001347`, exit `0`, `ok:1`.
- [x] Inserted FD-0000YV in `by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md`; no-global-clear evidence preserved; validator `000000001349`, exit `0`, `ok:1`.
- [x] Inserted FD-0000YW in `by-memory/0x004673a0-0x004673b1.DestroyExceptionHandler.md`; no-global-clear evidence preserved; validator `000000001350`, exit `0`, `ok:1`.
- [x] Inserted FD-00032B in `by-memory/0x004673e0-0x004673e6.GetApplicationSingleton.md`; validator `000000001351`, exit `0`, `ok:1`.
- [x] Inserted FD-0000SU and FD-0000ST in `by-global/g_screenWidth.md` and `by-global/g_screenHeight.md`; scores `90/93`; validators `000000001340` and `000000001338`, both exit `0`, `ok:1`.
- [x] Inserted FD-00035N in `by-memory/0x0066d408-0x0066d410.DisplayStartupPresentationGlobals.md`; score `88/92`; validator `000000001360`, exit `0`, `ok:1`.
- [x] Inserted FD-00028Z in `by-memory/0x0067a938-0x0067a940.ApplicationLifecycleFlags.md`; score `88/92`; validator `000000001361`, exit `0`, `ok:1`.
- [x] Inserted FD-000291 in `by-memory/0x0067a980-0x0067a998.ApplicationTimingBaselines.md`; stale `0xff` wording superseded with current zero-byte evidence; validator `000000001362`, exit `0`, `ok:1`.
- [x] Inserted FD-0002VX in `by-memory/0x0067ab70-0x0067ab7c.ApplicationMessageLoopInputCounters.md`; stale `0xff` wording superseded with current zero-byte evidence; validator `000000001366`, exit `0`, `ok:1`.
- [x] Inserted exact NC markers and body notes for `by-class/Application.md`, `by-class/BaramApp.md`, UID0002GY, UID000323, and UID0000YQ. Validators: `000000001370`, `000000001371`, `000000001330`, `000000001334`, `000000001343`, all exit `0`, `ok:1`.
- [x] Inserted aggregate/comment markers for UID0000YR and UID00019H. Validators: `000000001372` and `000000001353`, both exit `0`, `ok:1`.
- [x] Inserted string/vtable/RTTI/literal markers for UID0003P3, UID0003P4, UID00047Y, UID0003OD, UID00047Z, UID000484, UID000485, and UID000487. Validators: `000000001335`, `000000001336`, `000000001354`, `000000001355`, `000000001356`, `000000001357`, `000000001358`, `000000001359`, all exit `0`, `ok:1`.
- [x] Inserted covered-storage markers for UID0001OI and UID0001OG. Validators: `000000001339` and `000000001341`, both exit `0`, `ok:1`.
- [x] Inserted NC-0000YT and rare no-improvement proof in `by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md`; score stayed `88/91`; validator `000000001348`, exit `0`, `ok:1`.
- [x] Inserted NC-0000YX and rare no-improvement proof in `by-memory/0x00467410-0x004674ed.LoadIndexedDATSeries.md`; score stayed `90/94`; validator `000000001352`, exit `0`, `ok:1`.
- [x] Inserted NC-000292 in `by-memory/0x0067a998-0x0067a9c0.ApplicationErrorAndCriticalSectionStatics.md`; current zero-byte evidence recorded; validator `000000001363`, exit `0`, `ok:1`.
- [x] Inserted NC-000293 in `by-memory/0x0067a9c0-0x0067ab18.ApplicationOsVersionState.md`; current zero-byte evidence recorded; validator `000000001364`, exit `0`, `ok:1`.
- [x] Inserted NC-0002VU in `by-memory/0x0067ab5c-0x0067ab70.ApplicationHeartbeatTimerSkewGlobals.md`; current zero-byte evidence recorded; validator `000000001365`, exit `0`, `ok:1`.
- [x] Repaired `by-global/LoadIndexedDATSeries.md` as non-emitting duplicate/index metadata over UID0000YX. Validator `000000001337`, exit `0`, `ok:1`.
- [x] Repaired `by-item/CheckTimerSkewAndSendHeartbeat_466CA0.md` as non-emitting duplicate/index metadata over UID0000YT. Validator `000000001342`, exit `0`, `ok:1`.
- [x] Updated support docs `by-class/Application.md`, `by-class/BaramApp.md`, `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`, and `by-memory/0x004f5f20-0x004f66fb.BaramAppAndApplicationStartup.md` at report-level detail. The first three also received `[[CHILDREN]]` insertion points to assemble accepted child output; revalidators `000000001370`-`000000001372` all passed.
- [x] Preserved rejected alternatives: moving helpers to ScreenPane/DATFileMgr/ExceptionHandler/Error/PasswordGuard/new helper file; using `POINT`; duplicating by-global/by-item bodies; hand-writing scalar deleting destructors; standalone pooled string arrays; monolithic UID0000YT; simplified UID0000YX; guessed UID000292/UID000293/UID0002VU declarations.
- [x] Did not create split/new child files; UID000292 split ranges remain future evidence only.
- [x] No third-party import directive required.
- [x] Ran scoped validators for every changed by-* doc and recorded command, command_id, command_timestamp, exit code, and ok count in the matrix above.
- [x] Inspected regenerated `auto-generated/NexusTK/app/Application.cpp`; final generated refresh command `000000001373`, generated refresh completed, accepted child bodies present, `EMPTY/TODO/empty marker/RECONSTRUCTION_CPP` counts `0`, and UID0000T5/UID0000U8 absent as non-emitting index rows.
- [x] Updated this report's Claim And Incorporation Ledger verification states from `proposed` to applied/already-present/excluded-with-reason.
- [x] Did not manually edit generated reports, generated C++, coverage files, validator state, IDA DB, executed archives, supervisor ledgers, or lock files. Validator `--wait-generated` necessarily refreshed generated outputs/reports as part of the required generated freshness check; those changes are validator-produced, not manual edits.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/0000HG-Application-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0000HG-Application-empty-emitter-family-source-quality.md","timestamp":"2026-06-29T22:48:18","uid":"0000HG"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000HG-Application-empty-emitter-family-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/0000HG-Application-empty-emitter-family-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000HG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
