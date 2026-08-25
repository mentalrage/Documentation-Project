** TARGET-REPORT-UID:0002H2 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002H2 ApplicationRunMessageLoop Empty-Emitter Source-Quality Report

Agent: Agent-B007  
Assignment: B007-empty-emitter-report-0002H2-ApplicationRunMessageLoop-20260629  
Mode: implementation callback completed after supervisor acceptance; report was originally created as report-only research  
Target: [UID:0002H2] `by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md`  
Report path: `tools/leaser/Agents/Agent-B007/research/0002H2-ApplicationRunMessageLoop-empty-emitter-source-quality.md`  
MCP endpoint used: `http://127.0.0.1:13337/mcp`  
Active IDB session used: `b6b3c97e`

## Finalized Report / Current Recommendation

[UID:0002H2] should be promoted from an empty-emitter metadata-only method to a first-draft source method on the exact target page. Keep direct owner and emitter as [UID:00000D] `Application`, keep source route through [UID:0000HG] `NexusTK/app/Application.cpp`, and add a formal `void Application::RunMessageLoop()` reconstruction block to the target only.

Recommended target metadata after implementation:

| Field | Current | Recommended |
| --- | ---: | ---: |
| `COMPLETION` | `86` | `89` |
| `CONFIDENCE` | `90` | `92` |
| `CANONICAL_OWNER` | `00000D` | `00000D` |
| `RECONSTRUCTABLE` | `TRUE` | `TRUE` |
| `EMITTER_UIDS` | `00000D` | `00000D` |
| Formal C++ | blank | populate exact first-draft method body |

The old B002 no-code decision should be historicalized, not discarded. It was correct on 2026-06-16 when the active handler type, critical-section source name, PlatformApi slot naming, and helper declarations were less settled. Current docs and generated output now resolve enough of those blockers for a first-draft loop body: `Application+0x844` is `m_activeMessageHandler`, `0x0067a9a4` is `s_messageHandlerCriticalSection`, `MSGHandler::DispatchMessage(MSG*)` is documented, `Application::ExchangeMSGHandler` already emits C++ using those names, `0x0069be8c` is the PlatformApi `PeekMessageW` dispatch slot, and the EventDispatcher idle helper roles are documented.

Do not move the method to PlatformApi, BrowserControlPane, InputMan, EventDispatcher, MSGHandler, WinMain, or the aggregate ApplicationLifecycle page. Those are dependencies, callers, or support owners only.

## Current Target State

- Target page: `by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md`.
- After the implementation callback, the target page says `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:00000D`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00000D`.
- Formal `RECONSTRUCTION_CPP` block is populated with the accepted `void Application::RunMessageLoop()` first-draft body.
- The target records the high-level loop shape, the B002 2026-06-16 evidence pass, the current B007 MCP session `b6b3c97e` evidence, the two message-loop counters, `Application+0x83c`, `Application+0x844`, the PlatformApi `PeekMessageW` slot, browser/input gates, lock/unlock/snapshot behavior, no-null-check proof, and idle scheduler calls.
- Generated `auto-generated/NexusTK/app/Application.cpp` was refreshed by validator command id `000000000503` at `2026-06-29T09:43:05-04:00`. Read-only inspection found line `82` as `// UID:0002H2 | by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md | Completion:89 | Confidence:92`, line `83` as `void Application::RunMessageLoop()`, line `114` as the `g_pfnPeekMessage(&message, NULL, 0, 0, PM_REMOVE)` drain, and line `132` as `handler = m_activeMessageHandler`.
- The generated UID0002H2 empty-emitter marker is gone. Other unrelated Application.cpp empty markers remain for other UIDs.
- Generated `auto-generated/NexusTK/app/WinMain.cpp` calls `app.RunMessageLoop();` between `app.Startup();` and `app.Shutdown();`, supporting `void Application::RunMessageLoop()` as the source-facing signature even though Hex-Rays reports an incidental `DWORD` return register.

## Evidence Checked

### Local Documentation And Generated State

- Read target `by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md`.
- Read [UID:00000D] `by-class/Application.md`, [UID:0000HG] `by-file/Application.md`, and [UID:0000YR] `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`.
- Read counter support pages [UID:00029B] `by-memory/0x0067ab54-0x0067ab84.ApplicationDialogTimerAndBackgroundGlobals.md` and [UID:0002VX] `by-memory/0x0067ab70-0x0067ab7c.ApplicationMessageLoopInputCounters.md`.
- Read helper/support pages for [UID:0000YT] `CheckTimerSkewAndSendHeartbeat`, [UID:000143] `ApplicationIdleTickBaseline`, [UID:000142] `ApplicationIdleWorkScheduler`, [UID:0002GR] `ApplicationExchangeMSGHandler`, [UID:000292] `ApplicationErrorAndCriticalSectionStatics`, [UID:0001CN] `MSGHandler`, [UID:0001P3] `g_activeBrowserControlPane`, [UID:0000Z6] `BrowserControlPaneCore`, [UID:000299] `g_pInputMan`, [UID:00018E] `InputMan`, [UID:0000ML] `PlatformApi`, [UID:0000TQ] `WideApiDispatchTable`, and [UID:0002AS] `WideApiDispatchPointerTable`.
- Inspected generated `auto-generated/NexusTK/app/Application.cpp` and `auto-generated/NexusTK/app/WinMain.cpp` read-only.
- Searched prior reports by UID/name/address. Prior B002 report is at `executed-b-agent-research/B002/0002H0-0002JV-application-lifecycle-source-quality.md`; it recommended `86/90`, kept UID0002H2 blank, and explained the old blockers.

### MCP Health And Session State

- `idb_list` returned active session `b6b3c97e`, filename `NexusTK.exe.i64`, input path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, worker pid `15332`.
- `server_health` on `b6b3c97e` returned `status:"ok"`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.

### MCP Target Evidence

- `lookup_funcs`:
  - `0x00464cd0` -> `sub_464CD0`, size `0x14f`.
  - `0x00464e1f` -> not a function; confirms exclusive end before padding/successor.
  - `0x00464cc1` -> not a function; predecessor end/padding side, not target body.
  - `0x00464e20` -> `sub_464E20`, size `0x18`, the private exit-signal helper after the one-byte `0xcc` pad.
  - `0x004a7120` -> `sub_4A7120`, size `0x0c`.
  - `0x004a6c40` -> `sub_4A6C40`, size `0x9b`.
  - `0x00466ca0` -> `sub_466CA0`, size `0x40d`.
  - `0x0046c550` -> `sub_46C550`, size `0x10a`.
  - `0x004e9430` -> `sub_4E9430`, size `0x04`.
  - `0x00465650` -> `sub_465650`, size `0x36`.
- `analyze_function 0x00464cd0` returned prototype `DWORD __thiscall(const HANDLE *this)`, size `335`, 20 basic blocks, cyclomatic complexity `13`, callees `sub_46C550`, `sub_466CA0`, `unk_69BE8C`, `sub_4A7120`, `sub_49BD10`, `sub_4A6C40`, `sub_4E9430`, `MsgWaitForMultipleObjects`, `Sleep`, and `sub_49BCF0`, and caller `_WinMain@16`.
- `decompile 0x00464cd0` confirms:
  - `sub_4A7120(unk_67AB30)` at `0x00464ce1` before the main loop.
  - throttle counter `0x0067ab74` increment at `0x00464cf8`, `Sleep(1)` at `0x00464d04` when the counter exceeds `10`, and reset at `0x00464d0a`.
  - heartbeat counter `0x0067ab70` increment at `0x00464d1a`, `sub_466CA0()` call at `0x00464d26` when the counter exceeds `1000`, and reset at `0x00464d2b`.
  - wait call `MsgWaitForMultipleObjects(1, this+0x83c, FALSE, 5, 0x4ff)` at `0x00464d41`.
  - return on wait result `0`, queue branch on wait result `1`, idle branch on wait result `0x102`, and return on any other wait result.
  - `unk_69BE8C(&Msg, 0, 0, 0, 1)` at `0x00464d63` and `0x00464de1`, matching PlatformApi `PeekMessageW(..., PM_REMOVE)`.
  - `WM_QUIT` check against message `0x12` at `0x00464d71-0x00464d75`.
  - browser gate: if `g_activeBrowserControlPane` is non-null, call `sub_46C550(&Msg)` at `0x00464d88`; a zero return skips normal translation/dispatch and drains the next queued message.
  - input gate: `sub_4E9430(g_pInputMan)` at `0x00464d9a`; only modes `2` and `1` call imported `TranslateMessage`.
  - critical-section guard: construct/enter at `0x00464db7`, read `m_activeMessageHandler` from `Application+0x844` at `0x00464dbc`, leave/destroy at `0x00464dc5`, then call active handler vtable slot `+4` with `&Msg` at `0x00464dd2`.
  - idle work call `sub_4A6C40(unk_67AB30)` at `0x00464df7` after queue drain and at `0x00464e0e` after timeout/no-queue.
- `get_bytes`:
  - `0x00464cc0` window starts with predecessor `ret` at `0x00464cc0` followed by `0xcc` alignment through `0x00464ccf`.
  - `0x00464cd0` body is exactly 335 bytes (`0x14f`) and ends at byte `0x00464e1e`.
  - `0x00464e1f` is `0xcc`; successor bytes begin `0x56 0x8b 0xf1 ...` at `0x00464e20`.
- `int_convert` confirms `0x14f == 335`, `0x4ff == 1279`, `0x102 == 258`, `1000 == 0x3e8`, and `10 == 0x0a`.

### MCP Xref Evidence

- `xrefs_to 0x00464cd0`: exactly one code xref, `_WinMain@16` at `0x004f5e83`.
- `xrefs_to 0x004a7120`: exactly one code xref, UID0002H2 at `0x00464ce1`.
- `xrefs_to 0x004a6c40`: exactly two code xrefs, UID0002H2 at `0x00464df7` and `0x00464e0e`.
- `xrefs_to 0x00466ca0`: exactly one code xref, UID0002H2 at `0x00464d26`.
- `xrefs_to 0x0046c550`: exactly one code xref, UID0002H2 at `0x00464d88`.
- `xrefs_to 0x004e9430`: two code xrefs, UID0002H2 at `0x00464d9a` and `Main_WndProc`/`sub_465F20` at `0x004661cd`.
- `xrefs_to 0x0067ab28`: 24 direct refs; UID0002H2 reads it at `0x00464d7b`, while Browser constructors/destructors own writes/clears and presentation code consumes it.
- `xrefs_to 0x0067ab44`: 18 direct refs; UID0002H2 reads it at `0x00464d94`, while InputMan construction/destruction owns writes/clears.
- `xrefs_to 0x0067ab70`: 3 refs, all in UID0002H2 at `0x00464d14`, `0x00464d1a`, and `0x00464d2b`.
- `xrefs_to 0x0067ab74`: 3 refs, all in UID0002H2 at `0x00464cf2`, `0x00464cf8`, and `0x00464d0a`.
- `xrefs_to 0x0067a9a4`: 4 refs; startup init `0x00419ec0`, UID0002H2 `0x00464daf`, Application exchange helper `0x0046565b`, and static cleanup `0x0060c0e0`.
- `xrefs_to 0x0069be8c`: 8 refs; initializer write `0x0041a3d4`, UID0002H2 reads/calls at `0x00464d63` and `0x00464de1`, plus other message-loop or generated/projection users.

### MCP Support-Function Checks

- `analyze_function 0x0046c550`: `sub_46C550`, `int __cdecl(int)`, size `266`, 23 blocks, complexity `9`, caller `sub_464CD0`. It reads `g_activeBrowserControlPane`, dereferences object offset `+0x120`, queries `IID_IOleInPlaceActiveObject` at `0x006315c0`, handles key messages `0x100`, `0x101`, `0x104`, and `0x105`, bypasses Ctrl+N without Alt, calls `sub_49DF20(g_activeBrowserPane)` on Escape and returns `0`, otherwise forwards through vtable slot `+0x14` and releases through slot `+0x08`.
- `analyze_function 0x004e9430`: `sub_4E9430`, `int __thiscall(_DWORD *this)`, size `4`, returns `this[6]`, matching `InputMan::GetInputMode()` / offset `+0x18`.
- `analyze_function 0x004a7120`: `sub_4A7120`, size `12`, reads `g_pTimerMgr+0x18`, writes `EventDispatcher+0x2c`, returns the copied tick; the sole caller is UID0002H2.
- `analyze_function 0x004a6c40`: `sub_4A6C40`, size `155`, caller UID0002H2, calls cleanup queue, timer-period/dispatch, traversal rebuild, timer tick, and frame scheduler helpers; uses EventDispatcher state offsets `+0x2c` and `+0x30`.
- `analyze_function 0x00465650`: `sub_465650`, size `54`, calls `sub_49BCF0` / `sub_49BD10`, reads/writes `this[529]` (`Application+0x844`) under `0x0067a9a4`; generated Application.cpp already emits this as `Application::ExchangeMSGHandler(MSGHandler*)`.

## Positive Evidence

- The function is a real source-authored Application method: it has one direct source-level caller from `_WinMain@16`, is called between `Startup()` and `Shutdown()` in generated WinMain, and controls the top-level wait/message pump around the Application shutdown event.
- The half-open range is exact: MCP reports `sub_464CD0` size `0x14f` from `0x00464cd0`, `0x00464e1f` is padding, and successor `0x00464e20` is a separate exit-signal helper.
- Source-facing `void Application::RunMessageLoop()` is better than the decompiler's `DWORD` prototype. Generated WinMain ignores any return value, old by-memory report data names the integrated source signature as `void Application::RunMessageLoop()`, and the observed returns only leave incidental wait/peek values in `eax`.
- The old active-handler blocker is now resolved enough for first-draft C++: Application class docs name `m_activeMessageHandler`, MSGHandler docs name `DispatchMessage(MSG*)`, ApplicationExchangeMSGHandler emits C++ using `m_activeMessageHandler` and `s_messageHandlerCriticalSection`, and MCP confirms UID0002H2 uses the same field and lock.
- The old PlatformApi slot blocker is resolved enough for first-draft C++: WideApiDispatchTable identifies `0x0069be8c` as `PeekMessageW`, PlatformApi/UniAPIInit documentation supports grouped `g_pfn*` dispatch globals, and MCP shows UID0002H2 calls the slot exactly twice with `PM_REMOVE`.
- The old counter-name blocker is resolved: exact child [UID:0002VX] names `0x0067ab70` as `g_applicationHeartbeatCheckCounter` and `0x0067ab74` as `g_applicationMessageLoopThrottleCounter`; current MCP xrefs confirm both are touched only by UID0002H2 in the checked xref set.
- The browser accelerator dependency is well enough named for a source call: BrowserControlPaneCore documents `0x0046c550-0x0046c65a` as `BrowserControlPaneTranslateAcceleratorMessage(MSG *message)`, and current MCP reconfirms it has exactly one caller from UID0002H2.
- The EventDispatcher helper dependency is not Application-owned, but source roles are documented: `CaptureIdleTickBaseline()` for `0x004a7120` and `ProcessIdleWork()` for `0x004a6c40` are the current source-facing roles; UID0002H2 calls them through `g_pEventDispatcher`.

## Negative Evidence And Rejected Alternatives

- Do not keep the final C++ blank solely because B002 did so. B002's evidence remains valid, but later accepted docs resolved the specific names and helper relationships that made blank C++ the conservative choice in that pass.
- Do not emit this body on the Application class page or ApplicationLifecycle aggregate. The exact method page owns the source body; the class and aggregate should remain support/summary pages.
- Do not move the method to PlatformApi. PlatformApi owns `g_pfnPeekMessage`/`PeekMessageW` and other dispatch slots; UID0002H2 is a consumer.
- Do not move the method to BrowserControlPane. BrowserControlPane owns the accelerator helper and active browser globals; UID0002H2 only checks/calls that helper before normal message translation.
- Do not move the method to InputMan. InputMan owns `GetInputMode()` and `g_pInputMan`; UID0002H2 only reads input mode to decide whether to call `TranslateMessage`.
- Do not move idle helper bodies into this Application method. `0x004a7120` and `0x004a6c40` operate on EventDispatcher/timer/frame state through `g_pEventDispatcher` and remain EventDispatcher/UI scheduler dependencies.
- Do not add an active-handler null check in the first-draft body. The binary reads `m_activeMessageHandler` and calls vtable slot `+4` unconditionally after the critical-section snapshot. Constructor evidence initializes the field to the embedded/default MSGHandler, and MSGHandler exchange paths preserve a previous handler chain.
- Do not hold the critical-section lock across `MSGHandler::DispatchMessage(&message)`. The binary enters the lock, snapshots `Application+0x844`, leaves the lock, then calls virtual slot `+4`.
- Do not reinterpret `0x0067ab70` as a per-frame message count, timer handle, or input-event object. Reset is tied to `CheckTimerSkewAndSendHeartbeat()`.
- Do not reinterpret `0x0067ab74` as a timer handle. It is a numeric loop throttle counter because it directly gates `Sleep(1)` and resets to zero.
- Do not merge the successor `0x00464e20` helper into this method. `0x00464e1f` is padding and `lookup_funcs 0x00464e20` returns a separate `0x18`-byte function.

## Heuristic / Inference Reanalysis And Validation

### Owner / Emitter Ranking

| Rank | Candidate | Decision |
| ---: | --- | --- |
| 1 | [UID:00000D] `Application` / [UID:0000HG] `Application.cpp` | Keep. This method is called by `_WinMain@16`, waits on Application field `+0x83c`, reads Application field `+0x844`, updates Application loop globals, and belongs in the application lifecycle sequence. |
| 2 | [UID:0000YR] `ApplicationLifecycle` aggregate | Support only. It groups lifecycle children but should not emit exact child method source. |
| 3 | [UID:0000ML] `PlatformApi` | Reject as owner. It supplies the `PeekMessageW` dispatch slot only. |
| 4 | [UID:0000HV] `Browser` / `BrowserControlPane` | Reject as owner. It supplies active browser state and `BrowserControlPaneTranslateAcceleratorMessage`. |
| 5 | [UID:0000K6] `InputMan` | Reject as owner. It supplies `g_pInputMan` and `GetInputMode()`. |
| 6 | [UID:0000J7] `EventDispatcher` | Reject as owner. It supplies idle baseline/work helpers. |
| 7 | [UID:00008S] `MSGHandler` | Reject as owner. It owns the dispatch interface and previous-handler chain, not the Application pump. |

### Source Placement

Route the target through [UID:0000HG] `NexusTK/app/Application.cpp` with the exact child method body on [UID:0002H2]. Support docs should describe dependencies:

- `PlatformApi` owns `g_pfnPeekMessage` / `0x0069be8c` (`PeekMessageW`).
- `BrowserControlPane` owns `BrowserControlPaneTranslateAcceleratorMessage(MSG*)` and `g_activeBrowserControlPane`.
- `InputMan` owns `g_pInputMan` and `InputMan::GetInputMode()`.
- `EventDispatcher` owns `CaptureIdleTickBaseline()` and `ProcessIdleWork()`.
- `MSGHandler` owns `DispatchMessage(MSG*)`.
- `Monitor` / `CriticalSectionLock` owns the RAII lock helper, while Application owns the concrete static `s_messageHandlerCriticalSection`.

### Range / Split / Padding

- Keep target range `0x00464cd0-0x00464e1f`.
- Do not include predecessor padding `0x00464cc1-0x00464cd0`.
- Do not include successor padding byte `0x00464e1f`.
- Do not include successor helper `0x00464e20-0x00464e38`.
- Current MCP bytes show the function ends with `pop edi; pop esi; pop ebx; mov esp, ebp; pop ebp; retn` at `0x00464e18-0x00464e1e`.

### Empty-Emitter Root Cause

The current empty marker is not caused by a bad owner/emitter route. The route is valid and `Application.cpp` already emits sibling Application methods. UID0002H2 stayed empty because the earlier report intentionally deferred formal C++ while source-facing names and helper declarations were unsettled. Current support docs now resolve enough of those dependencies to add a first-draft body without inventing new ownership.

## First-Draft C++ Recommendation

Insert only this function body into the target's existing formal `RECONSTRUCTION_CPP CODE:BEGIN` / `END` block if the supervisor accepts the report:

```cpp
void Application::RunMessageLoop()
{
    MSG message;

    g_pEventDispatcher->CaptureIdleTickBaseline();

    for (;;) {
        if (++g_applicationMessageLoopThrottleCounter > 10) {
            Sleep(1);
            g_applicationMessageLoopThrottleCounter = 0;
        }

        if (++g_applicationHeartbeatCheckCounter > 1000) {
            CheckTimerSkewAndSendHeartbeat();
            g_applicationHeartbeatCheckCounter = 0;
        }

        DWORD waitResult = MsgWaitForMultipleObjects(1, &m_hShutdownEvent, FALSE, 5, QS_ALLINPUT);
        if (waitResult == WAIT_OBJECT_0) {
            return;
        }

        if (waitResult == WAIT_TIMEOUT) {
            g_pEventDispatcher->ProcessIdleWork();
            continue;
        }

        if (waitResult != WAIT_OBJECT_0 + 1) {
            return;
        }

        while (g_pfnPeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
            if (message.message == WM_QUIT) {
                return;
            }

            if (g_activeBrowserControlPane != NULL &&
                BrowserControlPaneTranslateAcceleratorMessage(&message) == 0) {
                continue;
            }

            int inputMode = g_pInputMan->GetInputMode();
            if (inputMode == 2 || inputMode == 1) {
                TranslateMessage(&message);
            }

            MSGHandler *handler;
            {
                CriticalSectionLock lock(&s_messageHandlerCriticalSection);
                handler = m_activeMessageHandler;
            }

            handler->DispatchMessage(&message);
        }

        g_pEventDispatcher->ProcessIdleWork();
    }
}
```

Notes for implementation:

- `g_pfnPeekMessage` is the PlatformApi source-facing grouped dispatch variable currently initialized to `PeekMessageW` at `0x0069be8c`. If implementation chooses the longer name `g_pfnPeekMessageW`, update PlatformApi/WideApi support text consistently; do not leave raw `unk_69BE8C` / `dword_69BE8C` in source-facing docs.
- `QS_ALLINPUT` is used for the exact `0x4ff` wake mask.
- `WAIT_OBJECT_0 + 1` is the message-queue branch for one wait handle; `WAIT_TIMEOUT` is `0x102`.
- The lock scope intentionally ends before `handler->DispatchMessage(&message)`, matching the binary.
- No null check is added for `handler`, matching the binary and constructor/exchange-handler state.
- The source-facing helper names `CaptureIdleTickBaseline`, `ProcessIdleWork`, and `BrowserControlPaneTranslateAcceleratorMessage` are current best names; exact original linkage remains a support-doc caveat, not a reason to keep UID0002H2 empty.

## Recommended Documentation Changes If Accepted

### Target Page: UID0002H2

- Raise `COMPLETION` from `86` to `89`.
- Raise `CONFIDENCE` from `90` to `92`.
- Keep owner/emitter/reconstructable fields unchanged.
- Replace C++ status wording with source-ready first-draft status.
- Populate the formal C++ block with the method above.
- Add current MCP session `b6b3c97e` evidence: server health, lookup size `0x14f`, caller `_WinMain@16`, 20 blocks, complexity `13`, xrefs to key helpers/globals, exact wait branch behavior, and boundary bytes.
- Add a new Changes entry explaining that B002's blank-C++ recommendation is now historical because later support docs resolved active-handler, lock, PlatformApi, MSGHandler, and helper naming blockers.

### Application Class Page

- Update the UID0002H2 method-list bullet to state that it is now source-ready and emits first-draft `void Application::RunMessageLoop()` on the exact child page.
- Preserve broad class C++ blank rationale; the exact child page emits the body, not the class page.
- Add current details to the field table for `m_hShutdownEvent`, `m_activeMessageHandler`, `g_applicationHeartbeatCheckCounter`, and `g_applicationMessageLoopThrottleCounter`, including the lock-scope detail and the no-null-check behavior.
- Historicalize the older "handler type remains blocker" wording wherever present; the field/source name is still not final-95, but it no longer blocks this first-draft method body.

### Application File Page

- Update Application.cpp likely-contents/source-quality text to say UID0002H2 is now source-ready and should be emitted by the exact by-memory page.
- Record dependency declarations: PlatformApi `g_pfnPeekMessage`, BrowserControlPane accelerator helper, InputMan `GetInputMode`, EventDispatcher idle helpers, MSGHandler dispatch, `CriticalSectionLock`, and `CheckTimerSkewAndSendHeartbeat`.
- Preserve source-placement rejections for PlatformApi, BrowserControlPane, InputMan, EventDispatcher, MSGHandler, and WinMain.
- Record generated-state expectation: after validator refresh, `auto-generated/NexusTK/app/Application.cpp` should no longer show UID0002H2 as an empty marker and should contain `Application::RunMessageLoop()`.

### ApplicationLifecycle Aggregate

- Update the child entry for UID0002H2 from metadata-only/blank to source-ready exact child method.
- Keep the aggregate itself as assigned/no-code; no aggregate C++ block should be emitted.
- Preserve sibling relationship to Initialize/CleanupResources/RequestExit/Startup/Shutdown and the exclusion of mixed PasswordGuard/BackPane ranges.

### Support Pages

- Update [UID:0002VX] `ApplicationMessageLoopInputCounters` only if current wording lacks the fresh MCP xref counts: 3 refs to `0x0067ab70`, 3 refs to `0x0067ab74`, all in UID0002H2.
- Update [UID:0000TQ] `WideApiDispatchTable` / [UID:0002AS] `WideApiDispatchPointerTable` only if desired to add UID0002H2 as a concrete `0x0069be8c` `PeekMessageW` consumer at `0x00464d63` and `0x00464de1`; the slot identity is already present.
- BrowserControlPane, InputMan, MSGHandler, ApplicationExchangeMSGHandler, and idle helper pages already contain equal-or-greater support detail for their dependency roles. If edited during implementation, mark those facts as already-present rather than rewriting them.

## Claim And Incorporation Ledger

| ID | Claim / fact to preserve | Action | Destination / proof target | Verification state |
| --- | --- | --- | --- | --- |
| C01 | UID0002H2 is `Application::RunMessageLoop`, range `0x00464cd0-0x00464e1f`, `sub_464CD0`, size `0x14f` / 335 bytes. | incorporate | Target Scope/IDA Evidence/Changes record `lookup_funcs 0x00464cd0 -> sub_464CD0 size 0x14f` and `analyze_function` size 335; lifecycle/class/file support also cite size. | applied |
| C02 | Active MCP session `b6b3c97e` is healthy for `NexusTK.exe.i64`, imagebase `0x400000`, Hex-Rays and strings cache ready. | incorporate | Target IDA Evidence records `server_health` status ok, imagebase `0x400000`, auto-analysis/Hex-Rays/strings ready, strings cache size `2067`; class/file/lifecycle Changes cite session `b6b3c97e`. | applied |
| C03 | The only direct caller is `_WinMain@16` at `0x004f5e83`; generated WinMain calls `app.RunMessageLoop();` between startup and shutdown. | incorporate | Target IDA Evidence and Changes record one `_WinMain@16` caller at `0x004f5e83`; Current Target State records generated WinMain call. | applied |
| C04 | Source-facing signature should be `void Application::RunMessageLoop()`, not decompiler `DWORD`, because caller ignores return and old source report names void. | incorporate | Target C++ block and Reconstruction Notes use `void Application::RunMessageLoop()`; Current Target State records generated Application.cpp line `83`. | applied |
| C05 | Predecessor `0x00464cc1-0x00464cd0` and successor byte `0x00464e1f` are `0xcc` alignment; `0x00464e20` is a separate helper. | incorporate | Target IDA Evidence and Changes record predecessor padding, `0x00464e1f` `0xcc`, and `0x00464e20 -> sub_464E20 size 0x18`. | applied |
| C06 | Loop calls `g_pEventDispatcher->CaptureIdleTickBaseline()` once before the wait loop, from call `0x00464ce1` to `0x004a7120`. | incorporate | Target Behavior/C++ and IDA Evidence record the pre-loop call; Application file change entry records the helper call. | applied |
| C07 | `0x004a7120` belongs to EventDispatcher idle baseline support, not Application ownership. | already-present | UID000143 already states EventDispatcher ownership; target Evidence Map cross-references it as a helper that should stay separate; no support edit needed. | already-present |
| C08 | `g_applicationMessageLoopThrottleCounter` at `0x0067ab74` increments each iteration, sleeps `1` ms after `>10`, then resets. | incorporate | Target Behavior/C++ and Application class field map row record increment, `Sleep(1)`, reset, and three current xrefs all in UID0002H2. | applied |
| C09 | `g_applicationHeartbeatCheckCounter` at `0x0067ab70` increments each iteration, calls `CheckTimerSkewAndSendHeartbeat()` after `>1000`, then resets. | incorporate | Target Behavior/C++ and Application class field map row record increment, helper call, reset, and three current xrefs all in UID0002H2. | applied |
| C10 | `CheckTimerSkewAndSendHeartbeat` at `0x00466ca0` has exactly one current direct caller from UID0002H2 at `0x00464d26`. | incorporate | Target IDA Evidence and Application file/class/lifecycle support cite the `0x00464d26` call. | applied |
| C11 | Wait call is `MsgWaitForMultipleObjects(1, &m_hShutdownEvent, FALSE, 5, 0x4ff/QS_ALLINPUT)`. | incorporate | Target C++/Behavior and Application class/file support include the exact wait call and `QS_ALLINPUT`. | applied |
| C12 | `Application+0x83c` is `m_hShutdownEvent`; return on `WAIT_OBJECT_0`. | incorporate | Target Behavior/C++ and Application class field notes/table record `m_hShutdownEvent`, wait ownership, signal/close roles, and return on `WAIT_OBJECT_0`. | applied |
| C13 | `WAIT_OBJECT_0 + 1` is the message-queue branch and `WAIT_TIMEOUT` / `0x102` runs idle work. | incorporate | Target Behavior/C++ and Reconstruction Notes record queue branch and timeout idle branch. | applied |
| C14 | Any unexpected wait result returns from the loop. | incorporate | Target Behavior and C++ `if (waitResult != WAIT_OBJECT_0 + 1) return;` preserve this. | applied |
| C15 | Queue branch calls PlatformApi slot `0x0069be8c` / `PeekMessageW` twice with `PM_REMOVE`. | incorporate | Target IDA Evidence records call sites `0x00464d63` and `0x00464de1`; WideApiDispatchTable and WideApiDispatchPointerTable now list UID0002H2 as a concrete consumer. | applied |
| C16 | Source-facing dispatch variable should be `g_pfnPeekMessage` unless implementation standardizes a `W` suffix consistently; raw `unk_69BE8C` is rejected. | incorporate | Target C++/Reconstruction Notes use `g_pfnPeekMessage`; Application file and WideApi support use `g_pfnPeekMessage` / `PeekMessageW`, rejecting raw-only names. | applied |
| C17 | `WM_QUIT` (`0x12`) returns from the loop before browser/input/handler dispatch. | incorporate | Target Behavior and C++ record the early `WM_QUIT` return. | applied |
| C18 | Browser gate reads `g_activeBrowserControlPane` and calls `BrowserControlPaneTranslateAcceleratorMessage(&message)` only when non-null. | incorporate | Target Behavior/C++ and Application file support record the non-null browser gate. | applied |
| C19 | `BrowserControlPaneTranslateAcceleratorMessage` returning `0` means consumed; normal translate/dispatch is skipped for that message. | incorporate | Target Behavior and C++ `continue` path preserve consumed-message semantics. | applied |
| C20 | BrowserControlPane owns `0x0046c550`; Application is a caller/consumer only. | already-present | BrowserControlPane class/core support already states file-static Application message-loop bridge and caller role; target/file notes reject BrowserControlPane ownership for the loop. | already-present |
| C21 | Input gate calls `g_pInputMan->GetInputMode()` / `0x004e9430`; only modes `1` and `2` call `TranslateMessage`. | incorporate | Target Behavior/C++ and Application file support record `GetInputMode()` modes `1`/`2`. | applied |
| C22 | InputMan owns `g_pInputMan` and `GetInputMode`; Application is a consumer only. | already-present | InputMan class/file/global support already records `GetInputMode`; Application file migration note rejects moving InputMan into Application.cpp. | already-present |
| C23 | Critical-section guard uses Application static `s_messageHandlerCriticalSection` at `0x0067a9a4`. | incorporate | Target C++/Behavior and Application class field notes/table record `s_messageHandlerCriticalSection`; ApplicationExchangeMSGHandler already uses same name. | applied |
| C24 | Binary snapshots `m_activeMessageHandler` under the lock and releases the lock before `handler->DispatchMessage(&message)`. | incorporate | Target C++ block scope, Target Reconstruction Notes, Application class table, and Application file notes all record lock release before dispatch. | applied |
| C25 | No `m_activeMessageHandler` null check should be added. | incorporate | Target C++ has no null check; Target Behavior/Reconstruction Notes and Application class/file changes explicitly reject adding one. | applied |
| C26 | `Application+0x844` is `m_activeMessageHandler`, and `MSGHandler` virtual slot `+4` is `DispatchMessage(MSG*)`. | incorporate | Target Behavior, Evidence Map, Application class notes/table, and Application file support record both names and roles. | applied |
| C27 | ApplicationExchangeMSGHandler already emits C++ using `m_activeMessageHandler`, `CriticalSectionLock`, and `s_messageHandlerCriticalSection`; this removes a prior blocker. | incorporate | Target Reconstruction Notes/Changes historicalize the blocker; Application class/file support cite the exchange helper and same names. | applied |
| C28 | Idle scheduler call `0x004a6c40` runs after queue drain and after timeout/no queue. | incorporate | Target Behavior/C++ and IDA Evidence record both idle scheduler call sites `0x00464df7` and `0x00464e0e`. | applied |
| C29 | `0x004a6c40` belongs to EventDispatcher/UI scheduler support and should not be moved into Application. | already-present | UID000142 already states EventDispatcher/UI scheduler ownership; target/file migration notes reject moving idle helper bodies into Application.cpp. | already-present |
| C30 | Owner/emitter remain [UID:00000D] `Application`; source route remains [UID:0000HG] `NexusTK/app/Application.cpp`. | incorporate | Target header remains owner/emitter `00000D`; Application class/file/lifecycle Changes preserve exact-child emission through `NexusTK/app/Application.cpp`. | applied |
| C31 | B002 2026-06-16 blank-C++ recommendation is historical: valid then, superseded now by resolved dependency names. | historicalize | Target Reconstruction Notes/Changes, Application file B007 supersession bullet, Application class Changes, and lifecycle Changes record H2 superseding B002 while preserving B002 evidence. | applied |
| C32 | Generated Application.cpp currently has UID0002H2 empty marker with stale `82/88` metadata under validator command id `000000000481`. | historicalize | Current Target State now records this as pre-implementation stale state and gives the replacement generated proof from command `000000000503`; no generated file was manually edited. | applied |
| C33 | After accepted implementation and validator refresh, generated `Application.cpp` should contain real UID0002H2 code and no empty marker. | incorporate | Generated check after validator `000000000503` found UID0002H2 real code at Application.cpp lines 82-135 and no UID0002H2 empty marker. | applied |
| C34 | Do not edit generated files, coverage reports, validator/tool state, or IDA DB for this report. | not-applicable | Manual edits were limited to target/support by-* docs and this report; generated output/validator-owned files changed only through required scoped validator runs; no IDA DB edits were made. | already-present |

## Implementation Tracking Checklist

- [x] Target doc updated: `by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md` metadata raised to `89/92`, owner/emitter preserved, and C++ status changed from blank to first-draft source-ready. Proof: validator `000000000503` exit `0`, `ok: 1`, completion/confidence updates `89/92`.
- [x] Target formal `RECONSTRUCTION_CPP` block populated with only the accepted `void Application::RunMessageLoop()` method body. Proof: generated `Application.cpp` line `83` emits the accepted signature and body after command `000000000503`.
- [x] Target Behavior / IDA Evidence updated with MCP session `b6b3c97e`, health proof, function size `0x14f`, caller `_WinMain@16`, block/complexity metrics, wait branch behavior, key xrefs, and boundary bytes. Proof: target IDA Evidence and Changes sections now include those details.
- [x] Target Reconstruction Notes historicalize B002's blank-C++ decision and explain which blockers are now resolved. Proof: target Reconstruction Notes/Changes explicitly mark B002 historical and list resolved PlatformApi/handler/lock/helper blockers.
- [x] [UID:00000D] `by-class/Application.md` updated at report-level detail for source-ready UID0002H2, `m_hShutdownEvent`, `m_activeMessageHandler`, loop counters, lock-scope behavior, and broad class C++ remaining blank. Proof: validator `000000000514` exit `0`, `ok: 1`.
- [x] [UID:0000HG] `by-file/Application.md` updated at report-level detail for UID0002H2 source route, dependencies, generated-refresh expectation, and rejected owner routes. Proof: validator `000000000520` exit `0`, `ok: 1`, with two `missing_ref_uid 0003OY` warnings unrelated to UID0002H2.
- [x] [UID:0000YR] `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md` updated to show UID0002H2 as a source-ready exact child while preserving aggregate no-code status. Proof: validator `000000000506` exit `0`, `ok: 1`.
- [x] [UID:0002VX] `by-memory/0x0067ab70-0x0067ab7c.ApplicationMessageLoopInputCounters.md` refreshed only if needed with the current MCP xref counts for `0x0067ab70` and `0x0067ab74`; otherwise mark already-present. Proof: no edit needed; existing page already records both slots as 3-xref loop counters, UID0002H2 increment/reset sites, and rejected timer/per-frame alternatives.
- [x] [UID:0000TQ] `WideApiDispatchTable` / [UID:0002AS] `WideApiDispatchPointerTable` refreshed only if needed with UID0002H2 as a `0x0069be8c` `PeekMessageW` consumer; otherwise mark already-present. Proof: both support docs updated; validators `000000000504` and `000000000505` exit `0`, `ok: 1`.
- [x] BrowserControlPane, InputMan, MSGHandler, ApplicationExchangeMSGHandler, CriticalSectionLock, and EventDispatcher helper facts checked against the ledger and marked already-present unless an accepted item is missing. Proof: checked support pages already contain equal-or-greater detail for ownership/caller/helper roles; no edits required.
- [x] Claim And Incorporation Ledger updated during callback: each row set to `applied`, `already-present`, or `excluded-with-reason` with concrete destination/proof. Proof: C01-C34 rows above are all resolved.
- [x] Scoped validators run from `source-3/project-documentation` for each edited by-* doc with command id/timestamp/exit code/`ok` count recorded in this report. Proof: Validators section below lists commands `000000000503`, `000000000504`, `000000000505`, `000000000506`, `000000000514`, and `000000000520`.
- [x] Generated refresh inspected read-only after validators: `auto-generated/NexusTK/app/Application.cpp` has UID0002H2 real code, no empty marker for UID0002H2, and the method appears in the Application source route. Proof: line `82` UID comment `Completion:89 | Confidence:92`, line `83` `void Application::RunMessageLoop()`, line `114` `g_pfnPeekMessage`, line `132` `m_activeMessageHandler`.
- [x] No generated reports, generated C++ files, project-level generated files, manual `-coverage-report.md` files, validator/tool state, lock files, or IDA DB were manually edited. Proof: manual edits were by-* docs plus this report; generated output/validator-owned files changed only through required scoped validator runs.
- [x] Leases, if required during implementation callback for by-* edits, were acquired only immediately before the edit/validator batch and released immediately after; final proof records no active B007 leases. Proof: first target/WideApi batch released, lifecycle released, class released, file released; final `tools/leaser/Agents/current_leases.md` check after all releases contains no `Agent-B007` rows.

## Validators

Validators were run from `source-3/project-documentation` after the implementation edits:

| Command | Timestamp | File | Exit | Result | Generated refresh / warnings |
| --- | --- | --- | ---: | --- | --- |
| `python .\tools\validator.py --mode file --file by-memory\0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md --apply --wait-generated` | `2026-06-29T09:43:05-04:00` | UID0002H2 target | `0` | `ok: 1`; completion/confidence/header/autogen registry updated | `generated_refresh: completed`, `generated_refresh_command_id: 000000000503`; validator reported broad existing `autogen_registry_stale` / missing-file metadata warnings during refresh, not UID0002H2 failures. |
| `python .\tools\validator.py --mode file --file by-global\WideApiDispatchTable.md --apply` | `2026-06-29T09:43:22-04:00` | WideApiDispatchTable | `0` | `ok: 1`; `reference_index_add 0002H2` | `generated_refresh: deferred`, command id `000000000504`. |
| `python .\tools\validator.py --mode file --file by-memory\0x0069be14-0x0069bec4.WideApiDispatchPointerTable.md --apply` | `2026-06-29T09:43:28-04:00` | WideApiDispatchPointerTable | `0` | `ok: 1`; `reference_index_add 0002H2` | `generated_refresh: deferred`, command id `000000000505`. |
| `python .\tools\validator.py --mode file --file by-memory\0x00463310-0x004674ed.ApplicationLifecycle.md --apply` | `2026-06-29T09:45:26-04:00` | ApplicationLifecycle | `0` | `ok: 1` | `generated_refresh: deferred`, command id `000000000506`. |
| `python .\tools\validator.py --mode file --file by-class\Application.md --apply` | `2026-06-29T09:48:02-04:00` | Application class | `0` | `ok: 1` | `generated_refresh: deferred`, command id `000000000514`. |
| `python .\tools\validator.py --mode file --file by-file\Application.md --apply` | `2026-06-29T09:57:21-04:00` | Application file | `0` | `ok: 1`; `reference_index_add 000197`, `0002GZ`, `0002Q2` from existing file content | `generated_refresh: deferred`, command id `000000000520`; warnings: `missing_ref_uid: 2` for `0003OY` in `by-file/Application.md`, unrelated to UID0002H2. |

Generated `auto-generated/NexusTK/app/Application.cpp` read-only proof after validator `000000000503`:

- Line `82`: `// UID:0002H2 | by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md | Completion:89 | Confidence:92`.
- Line `83`: `void Application::RunMessageLoop()`.
- Line `114`: `while (g_pfnPeekMessage(&message, NULL, 0, 0, PM_REMOVE))`.
- Line `132`: `handler = m_activeMessageHandler;`.
- No UID0002H2 `Empty Emitter Marker` remains. Other unrelated Application.cpp empty markers for other UIDs were not touched.

## Implementation Callback Constraints Observed

- Edited only the accepted target/support by-* docs and this live report; no generated C++ files, generated reports, project-level generated files, manual `-coverage-report.md` files, validator/tool state, lock files, executed archives, or IDA DB were manually edited.
- Required scoped validators were run from `source-3/project-documentation`; generated Application.cpp was refreshed/inspected through validator command `000000000503`, not by manual edit.
- Leases were short and edit-scoped: first target/WideApi batch, then lifecycle, then class, then file. Each batch was released immediately after its edit/validator step.
- Final lease report check: `tools/leaser/Agents/current_leases.md` contains no `Agent-B007` rows after the final release.
- Did not spawn subagents.
- Did not start, stop, restart, or manage IDA/MCP.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0002H2-ApplicationRunMessageLoop-empty-emitter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0002H2-ApplicationRunMessageLoop-empty-emitter-source-quality.md","timestamp":"2026-06-29T10:03:32","uid":"0002H2"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
