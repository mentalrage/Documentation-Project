** TARGET-REPORT-UID:0002H0 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002H0-0002JV Application Lifecycle Source Quality Research

Agent: Agent-B002  
Assignment: B002-goal2-application-lifecycle-source-quality-0002H0-0002H1-0002H2-0002H3-0002H5-0002JV-20260616  
Date: 2026-06-16  
Scope: Report-only B-agent review for Application lifecycle source quality and final-C++ readiness.

## Finalized Report / Current Recommendation

All six assigned targets have enough current IDA-backed evidence to raise above the historical `82/88` plateau. The correct action is a score and evidence refresh, not a final C++ insertion yet.

Recommended target metadata:

| UID | Target | Completion | Confidence | Owner | Emitter | Final C++ |
| --- | --- | ---: | ---: | --- | --- | --- |
| 0002H0 | `ApplicationInitialize` | 85 | 89 | `00000D` | `00000D` | Keep blank |
| 0002H1 | `ApplicationCleanupResources` | 86 | 90 | `00000D` | `00000D` | Keep blank |
| 0002H2 | `ApplicationRunMessageLoop` | 86 | 90 | `00000D` | `00000D` | Keep blank |
| 0002H3 | `ApplicationRequestExit` | 87 | 90 | `00000D` | `00000D` | Keep blank |
| 0002H5 | `ApplicationDetectOS` | 87 | 90 | `00000D` | `00000D` | Keep blank |
| 0002JV | `ApplicationGetOsCode` | 86 | 90 | `00000D` | `00000D` | Keep blank |

These targets become metadata-eligible for code entry after the score refresh because each is `RECONSTRUCTABLE:TRUE`, has a valid emitter route through `Application` to `NexusTK/app/Application.cpp`, and has an average above 85. They should still not receive final C++ in this pass because the generated Application source does not yet contain these bodies and several source-level declarations and helper names remain unresolved.

## Target

Primary pages reviewed:

- [UID:0002H0] `by-memory/0x004639d0-0x00464a52.ApplicationInitialize.md`
- [UID:0002H1] `by-memory/0x00464a60-0x00464cc1.ApplicationCleanupResources.md`
- [UID:0002H2] `by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md`
- [UID:0002H3] `by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md`
- [UID:0002H5] `by-memory/0x00464f50-0x00465115.ApplicationDetectOS.md`
- [UID:0002JV] `by-memory/0x00465120-0x00465124.ApplicationGetOsCode.md`

Context pages and generated state checked:

- [UID:00000D] `by-class/Application.md`
- [UID:0000HG] `by-file/Application.md`
- [UID:0000YR] `by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md`
- [UID:0002GY] `ApplicationConstructor`
- [UID:0002GZ] `ApplicationDestructor`
- [UID:0002H4] `ApplicationIsExitRequested`
- [UID:0002H6] `ApplicationValidateLicense`
- [UID:0002H7] `ApplicationStartup`
- [UID:0002H8] `ApplicationShutdown`
- [UID:000293] `ApplicationOsVersionState`
- [UID:00029B] and split child pages for Application global state
- [UID:00024T] `ApplicationStartupReadOnlyData`
- [UID:0003OD] `ApplicationVtableData`
- [UID:0003OF] `PlainMemberFunctionObject0ApplicationVtableData`
- [UID:000324] `PlainMemberFunctionObject0ApplicationInvoke`
- generated source state at `auto-generated/NexusTK/app/Application.cpp`

## Evidence Base

IDA MCP session:

- Endpoint: `http://127.0.0.1:13337/mcp`
- Database id: `b002_ranking_0001ZC_20260616`
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Calls used: `tools/list`, `idb_list`, `lookup_funcs`, `analyze_component`, `decompile`, `get_bytes`

Local project checks:

- `rg`/`Get-Content` over assigned target docs, context docs, `by-memory/-coverage-report.md`, `by-memory/-ignored.md`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/NexusTK/app/Application.cpp`
- No by-* docs, generated reports, generated source, IDA database state, or coverage report files were edited.

Generated Application source state:

- `auto-generated/NexusTK/app/Application.cpp` currently contains only `Application::CopyWorldName` and `Application::CopyPlayerName`.
- `auto-generated/-ag-memory-coverage.md` routes all six assigned UIDs to `auto-generated/NexusTK/app/Application.cpp`, status `emits`, canonical owner `00000D`, emitter `00000D`, final C++ column `no`.
- Therefore the route is valid, but the source-bearing Application lifecycle methods are not yet emitted.

## Heuristic / Inference Reanalysis And Validation

### Best Defensible Names, Roles, And Placement

| Address / offset | Best defensible name or role | Evidence checked | Rejected alternatives | Placement impact |
| --- | --- | --- | --- | --- |
| `Application+0x10` | `m_osCode`, type `ApplicationOsCode` or equivalent internal OS/version code | `ApplicationDetectOS` writes this field; `ApplicationGetOsCode` returns `this[4]`; [UID:000293] tracks OS-version global/state context | Generic `m_version` is too vague; Win32 `OSVERSIONINFO` storage is wrong because the field is a compact application code | Application class field; not a global |
| `Application+0x18` | `m_isWow64`, byte/BOOL | `ApplicationDetectOS` clears it, dynamically calls `IsWow64Process`, and stores the BOOL | `m_is64BitOS` overstates the exact API result; the code stores WOW64 status, not native architecture | Application class field |
| `Application+0x828` | `m_hMainWnd` or `m_mainWindowHandle` | `ApplicationCleanupResources` calls `ShowWindow(*(HWND *)(this+0x828), 0)`; initialization/window docs place this handle in Application | Global window handle rejected because access is through `this` | Application class field |
| `Application+0x83a` | `m_exitRequested` | `ApplicationIsExitRequested` returns byte at this offset; `ApplicationRequestExit` and `0x00464e20` set it | Generic status flag rejected because all known accesses are exit/request lifecycle paths | Application class field |
| `Application+0x83c` | `m_hShutdownEvent` or `m_exitEvent` | `ApplicationRunMessageLoop` waits on `this+0x83c`; `ApplicationRequestExit` and `0x00464e20` call `SetEvent`; cleanup closes the handle | `m_threadHandle` rejected because it is waited as an event and signaled by exit paths | Application class field |
| `Application+0x844` | `m_activeMessageHandler`, `MSGHandler *`-like | `ApplicationRunMessageLoop` reads `*((_DWORD *)this + 529)` and invokes vtable slot `+4` with `MSG *` under lock | Window proc object rejected; the field receives translated queued messages after browser/input gates | Application class field, exact type still final-C++ blocker |
| `Application+0x854` | `m_osVersionLabel`, StringBase-style field | `ApplicationDetectOS` calls `sub_582D20(this+2132, label)` and `sub_584540(this+2132)` before suffix append | Raw C string rejected because StringBase helpers operate on the field | Application class field |
| `0x0067ab70` | `g_applicationHeartbeatCheckCounter` | `RunMessageLoop` increments and calls `sub_466CA0((char)TranslateMessage)` when above 1000 | Message count per frame rejected because reset is tied to periodic helper call, not per-message handling | Application global state, emitted by Application file |
| `0x0067ab74` | `g_applicationMessageLoopThrottleCounter` | `RunMessageLoop` increments, sleeps after ten iterations, then resets | Timer handle rejected; numeric loop counter behavior is direct | Application global state, emitted by Application file |
| `0x0067ab78` | `g_mouseWheelDeltaAccumulator` or documented mouse wheel accumulator | Existing [UID:0002VX]/[UID:00029B] split docs place it with message-loop input counters | Thread/input event object rejected; docs and neighboring state identify it as a counter | Application/window-proc global state, not a target method |
| `0x00464e20` | Private `ApplicationSignalExitEvent` / `Application::SignalExitRequested` helper | Decompile shows `SetEvent(*(HANDLE *)(this+2108)); *(BYTE *)(this+2106)=1`; `ApplicationRequestExit` stores this pointer in `PlainMemberFunctionObject0<Application>` | Public `RequestExit` rejected because the public method is `0x00464e40`; destructor/cleanup callback rejected because only exit event and flag are touched | Application private helper, source body can live in `Application.cpp` |
| `0x004671b0` | `StringBaseAppendWideLiteral` | Existing docs and IDA show Application only uses it to append `_64bit`/`_32bit` OS-label suffixes | Application-local append helper rejected; owner is StringBase-style utility | Do not move to Application |
| `0x004a7120`, `0x004a6c40` | Event-dispatcher/UI scheduler glue used by message loop | `RunMessageLoop` calls these around wait/idle phases with `unk_67AB30` | Application member methods rejected because calls use a global dispatcher-like object, not `this` | Application consumes these helpers; source placement remains outside direct target |

### Startup / Shutdown Phase Model

The best source-level model is an `Application` class that owns lifecycle sequencing while subsystem implementations remain in their own files. [UID:0000HG] already projects `Application.cpp`, [UID:00000D] owns the fields and methods, and [UID:0000YR] aggregates the lifecycle span. Current IDA recheck supports that model:

- `ApplicationInitialize` is the primary large startup method. It performs patch/single-instance/window/resource/license/global-manager startup orchestration and calls many subsystem constructors or initializers.
- `ApplicationCleanupResources` is the final teardown pass. It broadcasts a termination message, restores cursor/stdio/keyboard state, hides the main window, displays a deferred error message, closes the shutdown event, and tears down singleton globals in a fixed order.
- `ApplicationRunMessageLoop` owns the application wait/message pump, not the platform API implementation itself.
- `ApplicationRequestExit` coordinates pane/browser/minimap shutdown and either defers the exit signal through the screen pane callback path or directly sets the Application event/flag.
- `ApplicationDetectOS` and `ApplicationGetOsCode` own OS-code member state and string label setup.

Rejected placements:

- `BaramApp` or WinMain: those are callers/entry orchestration, not the method owners.
- `ApplicationLifecycle` aggregate: useful report/coverage parent, not a source-level class or emitter.
- `PlatformApi`: owns imported/indirect Win32 function slots, not Application lifecycle logic.
- `StringBase`: owns append/string helpers, but not OS detection policy.
- EventDispatcher/Input/BrowserControlPane/ScreenPane modules: Application calls them during loop/exit, but the member state and entry functions are Application-owned.

### OS / Version Fields

`ApplicationDetectOS` is now strong enough for a source-quality score raise. IDA decompilation confirms:

- dynamic `kernel32!IsWow64Process` lookup with `GetModuleHandleW` and `GetProcAddress`;
- current process architecture probe when the API is available;
- `GetVersionExA` with `dwOSVersionInfoSize = 148`;
- internal code write to `Application+0x10`;
- WOW64 byte write to `Application+0x18`;
- OS-label StringBase field at `Application+0x854`;
- Windows 95/98/NT/2000/XP/Vista/7/8/Unknown label tree;
- `_64bit` and `_32bit` suffix appends for the supported later-Windows cases.

The internal code names should be descriptive and clearly marked reconstructed. There is no evidence that the original source used an enum named exactly `ApplicationOsCode`, so the recommended support-doc language should say "suggested enum/source name" rather than claim original spelling.

### Message-Loop And Exit Control

`ApplicationRunMessageLoop` and `ApplicationRequestExit` are coupled through the event/flag fields:

- loop waits on `Application+0x83c` with `MsgWaitForMultipleObjects(1, &m_hShutdownEvent, FALSE, 5, 0x4ff)`;
- exit helper `0x00464e20` and direct fallback both set the event and byte flag;
- `ApplicationIsExitRequested` confirms the flag at `Application+0x83a`;
- callback path uses `PlainMemberFunctionObject0<void (__thiscall Application::*)(), Application>` vtable data at `0x00612e40` and helper pointer `0x00464e20`;
- direct `RequestExit` is delayed through `g_pScreenPane` when that pane is live, otherwise the method sets the event immediately.

This validates the existing exit-control model and raises source confidence. It does not make final C++ ready because the source-level names and signatures for the pane cleanup helpers and function-object enqueue API remain unresolved.

### Source Placement

The six assigned functions should stay under:

- owner: [UID:00000D] `Application`
- emitter: [UID:00000D] `Application`, via [UID:0000HG] `NexusTK/app/Application.cpp`
- aggregate parent: [UID:0000YR] `ApplicationLifecycle`

No target should be re-owned by generated helper classes, global-state pages, subsystem singleton pages, or PlatformApi. Application owns the orchestration; supporting modules own the callee implementations.

### Final-C++ Blockers

The blockers are source-quality blockers, not routing blockers:

- `ApplicationInitialize`: large branch/failure-path rewrite still needs final source declaration decisions for Application layout, singletons, API dispatch slots, DAT/resource startup phases, and error paths.
- `ApplicationCleanupResources`: indirect virtual destructor calls, `Message` wrapper spelling, `g_pConfig` final type, and the `dword_67A738` CashShop/FileDownloader request-dispatcher identity need final source-facing names.
- `ApplicationRunMessageLoop`: `PeekMessage` dispatch slot name, active browser-control global alias, message-handler field type, lock helper names, and scheduler helper ownership need final declaration cleanup.
- `ApplicationRequestExit`: pane/browser/map/minimap helper names and callback enqueue API need exact source-level declarations.
- `ApplicationDetectOS`: enum/member names are defensible but reconstructed; final header/source API should avoid claiming original enum spelling.
- `ApplicationGetOsCode`: exact body is known, but no direct xrefs were found, so header exposure/public interface intent remains unresolved.

## IDA MCP Facts Checked

`lookup_funcs`:

| Address | IDA name | Size / range | Role |
| --- | --- | --- | --- |
| `0x004639d0` | `sub_4639D0` | `0x1082`, `0x004639d0-0x00464a52` | `ApplicationInitialize` |
| `0x00464a60` | `sub_464A60` | `0x261`, `0x00464a60-0x00464cc1` | `ApplicationCleanupResources` |
| `0x00464cd0` | `sub_464CD0` | `0x14f`, `0x00464cd0-0x00464e1f` | `ApplicationRunMessageLoop` |
| `0x00464e20` | `sub_464E20` | `0x18`, `0x00464e20-0x00464e38` | private exit-signal helper |
| `0x00464e40` | `sub_464E40` | `0xf4`, `0x00464e40-0x00464f34` | `ApplicationRequestExit` |
| `0x00464f50` | `sub_464F50` | `0x1c5`, `0x00464f50-0x00465115` | `ApplicationDetectOS` |
| `0x00465120` | `sub_465120` | `0x4`, `0x00465120-0x00465124` | `ApplicationGetOsCode` |

`analyze_component`:

- `sub_4639D0`: 4226 bytes, 162 basic blocks, complexity 31. Strings include `Nexon.SingleInstance`, `Global\Nexon.SingleInstance`, `runas`, and `patcher.exe`. Callees include `WSAStartup`, `CreateMutexA`, `DirectDrawCreate`, `ApplicationValidateLicense`, exception-handler setup, ChangeMan, BlackHole, InputMan, ImageLib, MidiPlayer, MiscWorkThread, CheatDetector, FileDownloader, and other startup managers.
- `sub_464A60`: 609 bytes, 55 basic blocks, complexity 25. Callees include `ApplicationForwardMessage`, `KeySpeedMgr_RestoreSystemKeyboardSettings`, `ShowCursor`, `ShowWindow`, `MessageBoxW`, `CloseHandle`, `fclose`, and Message constructor/destructor helpers.
- `sub_464CD0`: 335 bytes, 20 basic blocks, complexity 13. Callees include `MsgWaitForMultipleObjects`, `Sleep`, `BrowserControlPaneTranslateAcceleratorMessage`, critical-section helper calls, `0x69be8c` PeekMessage dispatch slot, and dispatcher/scheduler helpers.
- `sub_464E20`: 24 bytes, one basic block, calls only `SetEvent`.
- `sub_464E40`: 244 bytes, 15 basic blocks, complexity 3. Callees include pane/map/minimap/screen callback helpers and `SetEvent`.
- `sub_464F50`: 453 bytes, 38 basic blocks, complexity 19. Callees include `GetModuleHandleW`, `GetProcAddress`, `GetCurrentProcess`, `GetVersionExA`, StringBase assignment/getter helpers, and `StringBaseAppendWideLiteral`.
- `sub_465120`: 4 bytes, one basic block, no callees.

`decompile` highlights:

- `0x00464cd0`: increments loop counters at `0x0067ab74` and `0x0067ab70`; waits on handle at `Application+0x83c`; drains queue through `0x0069be8c`; handles `WM_QUIT`; gates browser/input translation; dispatches queued `MSG` to field at `Application+0x844`; idles via dispatcher helper.
- `0x00464e20`: `SetEvent(*(HANDLE *)(this+2108)); *(BYTE *)(this+2106)=1;`.
- `0x00464e40`: checks active browser/map/minimap/screen pane state; constructs a `PlainMemberFunctionObject0<Application>` wrapper with target `0x00464e20`; otherwise directly sets `Application+0x83c` and `Application+0x83a`.
- `0x00464f50`: clears `Application+0x18`, probes `IsWow64Process`, calls `GetVersionExA`, writes `Application+0x10`, assigns label at `Application+0x854`, appends bitness suffixes.
- `0x00465120`: `return this[4];`.

`get_bytes` confirmed target-adjacent alignment pads are all `0xcc`:

- `0x004639c4-0x004639d0`
- `0x00464a52-0x00464a60`
- `0x00464cc1-0x00464cd0`
- `0x00464e1f-0x00464e20`
- `0x00464f34-0x00464f40`
- `0x00464f47-0x00464f50`
- `0x00465115-0x00465120`
- `0x00465124-0x00465130`

## Per-Target Score Decisions

### [UID:0002H0] ApplicationInitialize

Decision: raise to `85/89`, owner/emitter remain `00000D`, final C++ remains blank.

Evidence checked:

- exact IDA function range and size: `0x004639d0-0x00464a52`, `0x1082` bytes;
- component complexity and startup callee set;
- Application class/file/aggregate placement docs;
- startup/shutdown context pages and generated Application source state;
- adjacent padding before and after target range.

Why 85 is defensible:

- The method's identity, range, broad phase sequence, class ownership, and source placement are solid.
- The callee set and strings confirm startup orchestration rather than a helper or subsystem implementation.
- Existing docs already split constructor, destructor, OS/version, license, startup, shutdown, and global state enough to avoid a direct-owner ambiguity.

Why not higher / why no final C++:

- Branch-by-branch source body is still too large for a reliable final C++ body.
- Several local helpers, failure labels, global singleton source names, and startup phase boundaries need final declarations before emitting source.
- Current `Application.cpp` does not emit this method.

### [UID:0002H1] ApplicationCleanupResources

Decision: raise to `86/90`, owner/emitter remain `00000D`, final C++ remains blank.

Evidence checked:

- exact IDA range: `0x00464a60-0x00464cc1`;
- decompiled deletion and cleanup order;
- support pages for Application globals and startup/shutdown state;
- context pages for `ApplicationShutdown`, singleton/global state, and `ApplicationLifecycle`;
- adjacent padding after target range.

Why 85+ is defensible:

- The teardown role is exact and source placement is not ambiguous.
- The termination-message broadcast, cursor/stdio restoration, keyboard manager restore, deferred error message, shutdown handle close, and singleton teardown order are all visible.
- Most singleton identities are already backed by Application/global support docs.

Why no final C++:

- Several deletions are indirect virtual calls and require source-facing type declarations.
- `dword_67A738` remains ambiguous between CashShop/FileDownloader/request-dispatcher naming.
- The exact Message wrapper type and final global declarations are not source-ready.

### [UID:0002H2] ApplicationRunMessageLoop

Decision: raise to `86/90`, owner/emitter remain `00000D`, final C++ remains blank.

Evidence checked:

- exact IDA range: `0x00464cd0-0x00464e1f`;
- decompile of the full loop body;
- existing `ApplicationIsExitRequested`, global input-counter pages, and Application class field docs;
- caller/callee role in lifecycle aggregate;
- adjacent padding before private exit helper.

Why 85+ is defensible:

- The event wait, loop throttling, heartbeat helper, message drain, browser accelerator gate, input-mode gate, critical-section guarded handler dispatch, and idle scheduler call are all explicit.
- Coupling to `Application+0x83c`, `Application+0x844`, and Application global counters is documented and now revalidated.
- Source placement belongs to Application even though some called helpers live in event-dispatcher or platform modules.

Why no final C++:

- `0x0069be8c` needs a final PlatformApi/PeekMessage source name.
- The active browser-control global, message-handler type, lock helper names, and scheduler helper declarations need final source declarations.

### [UID:0002H3] ApplicationRequestExit

Decision: raise to `87/90`, owner/emitter remain `00000D`, final C++ remains blank.

Evidence checked:

- exact IDA range: `0x00464e40-0x00464f34`;
- decompile of direct and deferred exit paths;
- private helper `0x00464e20`;
- `PlainMemberFunctionObject0<Application>` vtable data at `0x00612e40`;
- `ApplicationIsExitRequested` field evidence;
- context docs for screen pane, minimap manager, and Application globals.

Why 85+ is defensible:

- The method's control flow is small and fully understood.
- The deferred callback path and direct fallback both converge on `m_hShutdownEvent` and `m_exitRequested`.
- The helper object/vtable identity is supported by dedicated function-object docs.

Why no final C++:

- Exact source names for browser/map/minimap/screen cleanup helpers are still reconstructed.
- The callback enqueue API and screen-pane type declarations must be settled before code emission.

### [UID:0002H5] ApplicationDetectOS

Decision: raise to `87/90`, owner/emitter remain `00000D`, final C++ remains blank.

Evidence checked:

- exact IDA range: `0x00464f50-0x00465115`;
- decompile of OS branch tree and helper calls;
- `ApplicationGetOsCode` writer/accessor relationship;
- OS/version global-state and startup read-only-data pages;
- `StringBaseAppendWideLiteral` owner page;
- adjacent padding after target range.

Why 85+ is defensible:

- The WOW64 probe, Win32 version call, internal code field, label field, and suffix appends are explicit.
- The target is a true Application method with a simple source role.
- The only uncertainty is source spelling and enum declaration, not behavior.

Why no final C++:

- The final enum name and constant names are reconstructed, not original.
- Header exposure and Application member declarations need a coordinated source update.

### [UID:0002JV] ApplicationGetOsCode

Decision: raise to `86/90`, owner/emitter remain `00000D`, final C++ remains blank.

Evidence checked:

- exact IDA range: `0x00465120-0x00465124`;
- decompile shows `return this[4];`;
- no callees and no direct xrefs found in IDA component check;
- `ApplicationDetectOS` writes the same field at `Application+0x10`;
- adjacent padding before and after accessor range.

Why 85+ is defensible:

- The body, member offset, owner, and relation to `ApplicationDetectOS` are exact.
- No competing owner or source placement exists.

Why no final C++:

- The method may be a public accessor, private helper, or dead out-of-line accessor. Without direct caller/header evidence, adding final C++ would be premature.

## Unresolved Issues And Impacts

| Issue | Exact evidence checked | Candidate interpretation | Rejected alternatives | Score impact | Source-placement impact | Final-C++ impact |
| --- | --- | --- | --- | --- | --- | --- |
| H0 branch/failure-path reconstruction | IDA `analyze_component` for 162 BBs/complexity 31, strings, callee list, class/file/aggregate docs | Main Application startup/orchestration method with many subsystem phases | Subsystem owner, WinMain wrapper, or generated helper | Keeps H0 at 85 rather than higher | No owner change; stays Application | Blocks final body until failure paths and declarations are reconciled |
| H1 indirect teardown names | IDA decompile of deletion order; Application global pages; cleanup/shutdown context | Final Application cleanup pass with fixed singleton teardown order | Generic destructor, Shutdown method, or subsystem cleanup owner | Allows 86, but not high 90s | No owner change | Blocks final body pending type/global names and vtable destructor wrappers |
| H2 platform/message dispatch names | IDA decompile of wait loop, `0x0069be8c`, browser/input gates, lock helpers | Application message loop using platform API slot and subsystem helpers | PlatformApi-owned loop, BrowserControlPane-owned loop, InputManager-owned loop | Allows 86 due exact behavior, prevents higher | Application owns loop; helpers stay external | Blocks final body pending dispatch slot and handler type declarations |
| H3 deferred exit callback API | IDA decompile of callback allocation, `0x00464e20`, vtable data `0x00612e40`, direct fallback | Application exit request that defers through screen pane when active | Plain immediate exit-only setter, ScreenPane-owned method | Allows 87, not higher | Application owns method and private helper | Blocks final body pending callback enqueue/source API names |
| H5 OS enum names | IDA decompile, OS label strings/support pages, field writes, `StringBaseAppendWideLiteral` | Reconstructed `ApplicationOsCode` enum and OS label field | Original enum spelling proven, global OS detector, or raw OSVERSIONINFO storage | Allows 87, not higher | Application owns policy; StringBase owns append helper | Blocks final C++ until enum/member declarations are chosen |
| JV accessor exposure | IDA decompile, no-callee/no-direct-xref check, DetectOS writer relation | Out-of-line Application accessor for `m_osCode` | Independent OS detector helper or global accessor | Allows 86 due exact body; no need to keep below 85 | Application owner remains exact | Blocks final C++ until header/interface intent is proven |
| Alignment padding under lifecycle span | IDA `get_bytes` for target-adjacent gaps; existing `by-memory/-ignored.md` row | Missing ignored ledger entries for `0xcc` pads between exact methods | Unclassified code/data or part of neighboring methods | No target score penalty after ignored row update | No owner change | Does not block final C++; affects coverage hygiene |
| Generated Application source absent | `auto-generated/NexusTK/app/Application.cpp`; `auto-generated/-ag-memory-coverage.md` | Route exists, but lifecycle methods are not emitted yet | Dead emitter or wrong output path | No score penalty after route validation | Confirms Application emitter route | Blocks treating pages as final-C++ complete |

## Recommended Metadata And Body Edits

### Target Page Metadata

Recommended front-matter updates:

| UID | Completion | Confidence | Owner | Reconstructable | Emitter | Final C++ |
| --- | ---: | ---: | --- | --- | --- | --- |
| `0002H0` | `85` | `89` | `00000D` | `TRUE` | `00000D` | blank |
| `0002H1` | `86` | `90` | `00000D` | `TRUE` | `00000D` | blank |
| `0002H2` | `86` | `90` | `00000D` | `TRUE` | `00000D` | blank |
| `0002H3` | `87` | `90` | `00000D` | `TRUE` | `00000D` | blank |
| `0002H5` | `87` | `90` | `00000D` | `TRUE` | `00000D` | blank |
| `0002JV` | `86` | `90` | `00000D` | `TRUE` | `00000D` | blank |

If the pages use `OWNER_UID` and `EMITTER_UIDS`, keep both as `00000D`. If they also contain child/aggregate linkage to [UID:0000YR], preserve that relationship.

### Target Page Body Text

Add or replace the current score rationale sections with these concise statements.

For [UID:0002H0]:

```text
2026-06-16 B002 recheck: IDA MCP session b002_ranking_0001ZC_20260616 confirms `sub_4639D0` is an exact 0x1082-byte `Application` startup/orchestration method with startup strings (`Nexon.SingleInstance`, `Global\Nexon.SingleInstance`, `runas`, `patcher.exe`) and broad lifecycle callee set including WSAStartup, single-instance/window/DAT/license/manager setup, and Application ValidateLicense. Raise to 85/89 because owner, emitter route, range, and phase role are strong; keep final C++ blank because branch-level failure-path reconstruction, final field/global/helper names, and generated source emission remain unresolved.
```

For [UID:0002H1]:

```text
2026-06-16 B002 recheck: IDA MCP decompilation of `sub_464A60` confirms final Application resource cleanup: termination-message broadcast, cursor/stdio restoration, keyboard-speed restore, main-window hide, deferred error message, singleton/global teardown order, shutdown-handle close at `Application+0x83c`, and Message destruction. Raise to 86/90. Final C++ remains blank pending exact source-facing global/type names, indirect virtual destructor wrappers, and the CashShop/FileDownloader request-dispatcher identity.
```

For [UID:0002H2]:

```text
2026-06-16 B002 recheck: IDA MCP decompilation of `sub_464CD0` confirms the Application message pump: throttle and heartbeat counters at `0x0067ab74`/`0x0067ab70`, wait on `Application+0x83c` via `MsgWaitForMultipleObjects`, `WM_QUIT` exit, PlatformApi `PeekMessage` dispatch slot, browser accelerator gate, input-mode translation gate, critical-section-guarded dispatch to `Application+0x844`, and dispatcher idle calls. Raise to 86/90. Final C++ remains blank pending final PlatformApi slot, message-handler type, lock-helper, and scheduler helper declarations.
```

For [UID:0002H3]:

```text
2026-06-16 B002 recheck: IDA MCP decompilation of `sub_464E40` confirms Application exit request control. The method coordinates active browser/map/minimap/screen state, builds a `PlainMemberFunctionObject0<Application>` callback to private helper `0x00464E20` when the screen pane is active, and otherwise directly sets `Application+0x83c` and `Application+0x83a`. Raise to 87/90. Final C++ remains blank pending exact pane cleanup helper and callback enqueue API names.
```

For [UID:0002H5]:

```text
2026-06-16 B002 recheck: IDA MCP decompilation of `sub_464F50` confirms Application OS detection: dynamic `IsWow64Process`, `GetVersionExA`, internal OS-code write at `Application+0x10`, WOW64 byte at `Application+0x18`, OS label StringBase field at `Application+0x854`, Windows 95/98/NT/2000/XP/Vista/7/8/Unknown labels, and `StringBaseAppendWideLiteral` suffix append for `_64bit`/`_32bit`. Raise to 87/90. Final C++ remains blank until the reconstructed enum/member names and header declarations are settled.
```

For [UID:0002JV]:

```text
2026-06-16 B002 recheck: IDA MCP decompilation of `sub_465120` confirms the exact accessor body `return this[4]`, meaning it returns the Application OS-code field at `Application+0x10`. `ApplicationDetectOS` is the corresponding writer. Raise to 86/90 because the body, range, owner, and field relationship are exact; keep final C++ blank because no direct xrefs/header exposure prove whether this accessor should be emitted as public, private, or unused source.
```

### Support-Doc Updates

Recommended [UID:00000D] `by-class/Application.md` updates:

- In the field/layout section, explicitly record these names as best reconstructed source names:
  - `Application+0x10`: `m_osCode` / reconstructed `ApplicationOsCode`
  - `Application+0x18`: `m_isWow64`
  - `Application+0x828`: `m_hMainWnd`
  - `Application+0x83a`: `m_exitRequested`
  - `Application+0x83c`: `m_hShutdownEvent`
  - `Application+0x844`: `m_activeMessageHandler` / `MSGHandler *`-like
  - `Application+0x854`: `m_osVersionLabel` / StringBase-style field
- Add private helper `0x00464e20` as `ApplicationSignalExitEvent` or `Application::SignalExitRequested`, with note that exact source spelling is reconstructed.
- Add note that `ApplicationGetOsCode` has exact body but unresolved header/public exposure.

Recommended [UID:0000HG] `by-file/Application.md` updates:

- Keep source path `NexusTK/app/Application.cpp`.
- Add a source-quality note that lifecycle methods now meet metadata code-entry thresholds but should remain final-C++ blank until Application field declarations, helper declarations, and generated source bodies are reconciled.
- Record that `auto-generated/NexusTK/app/Application.cpp` currently emits only `Application::CopyWorldName` and `Application::CopyPlayerName`, so lifecycle methods are route-valid but source-absent.

Recommended [UID:0000YR] `ApplicationLifecycle` aggregate updates:

- Update child target scores to match this report.
- Add target-adjacent padding spans verified by IDA `get_bytes`.
- Do not absorb `0x00464e20` into `ApplicationRequestExit`; keep it as an exact private helper child or document it as a callback helper in the aggregate.

Recommended [UID:000293] `ApplicationOsVersionState` or related OS support doc updates:

- Mark `ApplicationOsCode` as a reconstructed source name, not proven original spelling.
- Cross-reference `ApplicationDetectOS` as writer and `ApplicationGetOsCode` as accessor for `Application+0x10`.
- Cross-reference `Application+0x18` as WOW64 probe byte and `Application+0x854` as OS label storage.

Recommended [UID:00029B]/[UID:0002VX] Application global-state updates:

- Cross-reference `0x0067ab70` and `0x0067ab74` from `ApplicationRunMessageLoop`.
- Confirm `0x0067ab70` as periodic heartbeat/check counter and `0x0067ab74` as short throttle/sleep counter.

## Recommended Ignored-Row Changes

Do not edit directly from this report. Supervisor/A-agent should update `by-memory/-ignored.md`.

Existing Application local helper alignment row should be replaced/expanded to include the target-adjacent pads verified in this pass:

```markdown
- `0x0046396e-0x00463970`, `0x004639c4-0x004639d0`, `0x00464a52-0x00464a60`, `0x00464cc1-0x00464cd0`, `0x00464e1f-0x00464e20`, `0x00464f34-0x00464f40`, `0x00464f47-0x00464f50`, `0x00465115-0x00465120`, `0x00465124-0x00465130`, `0x004651b8-0x004651c0`, `0x004651c4-0x004651d0`, `0x004651d7-0x004651e0`, `0x004651e7-0x004651f0`, `0x004652dc-0x004652e0`, `0x004652fc-0x00465300`, `0x00465308-0x00465310`, `0x00465318-0x00465320`, and `0x00465424-0x00465430` - Application local helper/method alignment padding.
  - Evidence: IDA MCP `get_bytes` on 2026-05-31 confirmed the helper/accessor gaps around `0x00465115-0x00465430`; B002 2026-06-16 IDA MCP `get_bytes` in session `b002_ranking_0001ZC_20260616` confirmed target-adjacent gaps `0x004639c4-0x004639d0`, `0x00464a52-0x00464a60`, `0x00464cc1-0x00464cd0`, `0x00464e1f-0x00464e20`, `0x00464f34-0x00464f40`, `0x00464f47-0x00464f50`, `0x00465115-0x00465120`, and `0x00465124-0x00465130` are all `0xcc` bytes. Neighboring functions are documented as exact child pages under [UID:0000YR] `ApplicationLifecycle`.
```

## Supervisor-Owned Coverage Row Replacements

Do not edit `by-memory/-coverage-report.md` from this B-agent task. The following replacement rows are recommended for the supervisor-owned coverage report. Indentation should be adjusted to match the current tree under [UID:0000YR].

```markdown
    - [UID:0000YR][0x00463310-0x004674ed.ApplicationLifecycle](by-memory/0x00463310-0x004674ed.ApplicationLifecycle.md) 0x00463310-0x004674ed | class aggregate | ApplicationLifecycle : reconstructable : 85% : strong : Application lifecycle aggregate ending at LoadIndexedDATSeries; exact Application/BaramApp constructor, initialize/cleanup/message-loop/exit, OS/version/license, activation/deactivation, destructor support, fatal-load cleanup, and DAT-series helper children are split, with BackPane/runtime-wrapper crossing explicitly excluded and final aggregate C++ blank.
        - [UID:0002H0][0x004639d0-0x00464a52.ApplicationInitialize](by-memory/0x004639d0-0x00464a52.ApplicationInitialize.md) 0x004639d0-0x00464a52 | class method | ApplicationInitialize : reconstructable : 85% : strong : Exact main Application initialization method; current IDA confirms the 0x1082-byte body, startup/lifecycle source placement, patch/single-instance/window/DAT/license/manager startup phases, and broad callee set, while final C++ remains blank pending branch-level failure-path rewrite and final field/helper/global names.
        - [UID:0002H1][0x00464a60-0x00464cc1.ApplicationCleanupResources](by-memory/0x00464a60-0x00464cc1.ApplicationCleanupResources.md) 0x00464a60-0x00464cc1 | class method | ApplicationCleanupResources : reconstructable : 86% : strong : Exact final teardown method; current IDA decompilation confirms termination-message broadcast, cursor/stdio restoration, UID-backed singleton deletion order, error-message/window/shutdown-handle cleanup, and tail Message destruction, with final C++ blocked by indirect virtual deletes and a few source-facing global/type names.
        - [UID:0002H2][0x00464cd0-0x00464e1f.ApplicationRunMessageLoop](by-memory/0x00464cd0-0x00464e1f.ApplicationRunMessageLoop.md) 0x00464cd0-0x00464e1f | class method | ApplicationRunMessageLoop : reconstructable : 86% : strong : Exact Win32 message loop; current IDA decompilation confirms shutdown-event wait at `Application+0x83c`, throttle/heartbeat counters, `MsgWaitForMultipleObjects`, PlatformApi `PeekMessage`, browser/input translation gates, critical-section-guarded active `MSGHandler` dispatch, and idle scheduler calls.
        - [UID:0002H3][0x00464e40-0x00464f34.ApplicationRequestExit](by-memory/0x00464e40-0x00464f34.ApplicationRequestExit.md) 0x00464e40-0x00464f34 | class method | ApplicationRequestExit : reconstructable : 87% : strong : Exact shutdown request method; current IDA decompilation confirms active browser/map/minimap/screen coordination, deferred `PlainMemberFunctionObject0<Application>` callback to private `0x00464e20` signal helper, and direct fallback setting `Application+0x83c`/`Application+0x83a`.
        - [UID:0002H5][0x00464f50-0x00465115.ApplicationDetectOS](by-memory/0x00464f50-0x00465115.ApplicationDetectOS.md) 0x00464f50-0x00465115 | class method | ApplicationDetectOS : reconstructable : 87% : strong : OS/WOW64 detection method; current IDA decompilation confirms dynamic `IsWow64Process`, `GetVersionExA` branch tree, writes to `m_osCode`/`m_isWow64`/OS-label state, Windows 95/98/NT/2000/XP/Vista/7/8 labels, and `StringBaseAppendWideLiteral` use for 32/64-bit suffixes.
        - [UID:0002JV][0x00465120-0x00465124.ApplicationGetOsCode](by-memory/0x00465120-0x00465124.ApplicationGetOsCode.md) 0x00465120-0x00465124 | class method | ApplicationGetOsCode : reconstructable : 86% : strong : Exact two-instruction OS-code accessor; current IDA confirms `return this[4]` / `Application+0x10`, no callees, no direct xrefs, adjacent `0xcc` padding, and writer relationship to `ApplicationDetectOS`; final C++ remains blank until header exposure/interface intent is proven.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004639c4-0x004639d0,0x00464a52-0x00464a60,0x00464cc1-0x00464cd0,0x00464e1f-0x00464e20,0x00464f34-0x00464f40,0x00464f47-0x00464f50,0x00465115-0x00465120,0x00465124-0x00465130 | padding spans | Application lifecycle alignment pads : ignored : 100% : strong : B002 2026-06-16 IDA MCP `get_bytes` confirmed all listed target-adjacent gaps are `0xcc` alignment padding between exact Application lifecycle methods/helpers.
```

Notes:

- The current coverage row for [UID:0000YR] still reports stale range/score text and should be corrected to `0x00463310-0x004674ed` and current aggregate score.
- The current local ignored row around `0x00465115-0x00465430` is too broad for coverage display if it reads like one continuous padding span. It should name exact discontinuous padding intervals or defer to the expanded `by-memory/-ignored.md` row above.
- Nearby constructor/destructor rows are also stale in the coverage report, but this report only requires the assigned lifecycle-source-quality rows. If the supervisor edits the block, update [UID:0002GY] and [UID:0002GZ] to their current page scores in the same pass.

## Validation Commands And Order

Recommended validation after the supervisor/A-agent applies metadata/body/support/ignored/coverage edits:

> Executable block R001 was removed from this report and preserved verbatim in [0002H0-0002JV-application-lifecycle-source-quality-removed.md](0002H0-0002JV-application-lifecycle-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Validation performed in this B-agent pass:

- IDA MCP lookup/decompile/component/bytes checks listed above.
- Local project text checks for docs and generated Application source state.
- No project validator was run because this pass edited only the permitted B-agent research report and made no by-* or generated-report changes.

## Final Recommendation

Score/owner/emitter decisions:

- Raise all six assigned target pages to the recommended 85+ scores.
- Keep owner and emitter as `00000D` for all six.
- Keep [UID:0000HG] as the file-level emitter route to `NexusTK/app/Application.cpp`.
- Keep [UID:0000YR] as aggregate parent, not direct source owner.

Final C++ decision:

- Leave final C++ blank for all six in this pass.
- Treat them as metadata-eligible after score refresh but not source-ready.
- Source emission should wait until Application field declarations, helper prototypes, singleton/global source names, and callback/platform dispatch APIs are reconciled.

Source placement decision:

- Keep all assigned methods in Application source placement.
- Do not migrate target ownership to PlatformApi, EventDispatcher, BrowserControlPane, ScreenPane, StringBase, BaramApp, or subsystem singleton pages.

Ignored/coverage decision:

- Add target-adjacent `0xcc` gaps to `by-memory/-ignored.md`.
- Replace stale supervisor-owned coverage rows for assigned targets and the lifecycle aggregate with the rows above.

## Changed Files

Only this report was created:

- `tools/leaser/Agents/Agent-B002/research/0002H0-0002JV-application-lifecycle-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002H0-0002JV-application-lifecycle-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002H0"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002H0-0002JV-application-lifecycle-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/0002H0-0002JV-application-lifecycle-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002H0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
