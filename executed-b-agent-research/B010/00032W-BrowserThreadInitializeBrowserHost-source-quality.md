** TARGET-REPORT-UID:00032W **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID00032W BrowserThreadInitializeBrowserHost Source Quality


## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:00032W] as `BrowserThread::InitializeBrowserHost`, owned/emitted by [UID:00001A] `BrowserThread`, with source rooted through [UID:0000HV] `Browser`.
- Final disposition: source-bearing BrowserThread method, not a free helper, not a Browser/BrowserWindow method, and not a broad aggregate child that should be merged back into [UID:0000ZF].
- Required action: post-callback supervisor review of the applied target/support updates, including current MCP session evidence, resolved helper names/types, failure-cleanup details, bridge lifecycle, BrowserThread field-offset names, rejected alternatives, and formal first-draft C++.
- Confidence: high for behavior, owner, bridge type, method role, and first-draft source shape; medium-high for exact original local/member spellings and final one-file versus split-file Browser source layout.

## Supporting Research
- This report began as a report-only pass for active assignment UID00032W. Gate 1 passed after the same-file repair, and the supervisor approved the implementation callback on 2026-07-03.
- Historical repair note: the first Gate 1 review failed because this report named several directly blocking dependencies without investigating them. The repaired revision investigated those dependencies and replaced the old blank-C++ recommendation with first-draft C++; this implementation callback applied those accepted details.
- Mandatory MCP evidence was collected from existing/restored session `b010_00032w_20260703` against `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`. The session health check reported `status:"ok"`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, and module `NexusTK.exe`.
- Target/support docs incorporated during the approved callback: target [UID:00032W], support [UID:00001A] `BrowserThread`, and support [UID:0000HV] `Browser`. Optional [UID:00033K] `BrowserNavigate` was checked and left unchanged because it already documents the narrow signature needed by UID00032W.
- Generated context after callback: validator command `000000005599` refreshed `auto-generated/NexusTK/browser/Browser.cpp` at `2026-07-03T16:15:41-04:00`; UID00032W now emits `void BrowserThread::InitializeBrowserHost()` at `Completion:90 | Confidence:92`. UID00033K remains a separate expected Empty Emitter Marker.
- Historical reports/leads used only as leads and rechecked against current by-* docs and MCP evidence: B001 [UID:0000ZF], B010 [UID:000333] and [UID:0002AD], B002 Browser empty-emitter batch, B013 BrowserNavigate correction, B004 ApplicationGetInstanceHandle, and B006 ApplicationGetMainWindowHandle.
- Target/support by-* docs were edited only after the approved implementation callback. No generated files, coverage reports, validator state, report lifecycle state, archives, or supervisor ledgers were edited by hand; validator-owned generated/project-state side effects are recorded under `Validator Results`.
- Forbidden commands not run: `execute_report`, dry-run execute variants, lifecycle/archive commands, generated manual edits, manual coverage-report edits, validator-state edits, report moves, and supervisor-ledger edits.

## Target
- Target UID: `00032W`
- Target path: `by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md`
- Assignment source: `auto-generated/-ag-research-tracker.md` -> `by-memory` -> `Not-Covered Files - Reconstructable`; assignment-time row was `85/89`, combined `87.0`, reconstructable `true`, reports `0`.
- Current supervisor classification: post-callback B-report implementation artifact awaiting supervisor Gate 1/Gate 2 recheck and later supervisor-only execution if accepted.
- Current metadata and parent state: target is now `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:00001A`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001A`; parent inventory [UID:0000ZF] remains a non-emitting split map at `91/92`.
- Current lifecycle state: report remains active at `tools/leaser/Agents/Agent-B010/research/00032W-BrowserThreadInitializeBrowserHost-source-quality.md`; I did not run `execute_report`, dry-run execute variants, lifecycle/archive commands, or move the report.

## Current Target State
- Current metadata: exact half-open range `0x00470a00-0x00470dc9`, `COMPLETION:90`, `CONFIDENCE:92`, BrowserThread owner/emitter, reconstructable true, and formal C++ populated with first-draft `BrowserThread::InitializeBrowserHost()`.
- Current owner/emitter/reconstructable state: BrowserThread method under the Browser source root; direct owner/emitter remain [UID:00001A], with [UID:0000HV] Browser as the source root.
- Current C++/emitter state: target formal C++ is populated and generated `auto-generated/NexusTK/browser/Browser.cpp` now emits UID00032W as `void BrowserThread::InitializeBrowserHost()` at `Completion:90 | Confidence:92` after validator command `000000005599`.
- Current support state: `by-class/BrowserThread.md` documents `BrowserThread+0x68` as `Browser *m_browser`, `BrowserThread+0x70` as `RECT m_hostBounds`, and records that UID00032W's wide API dispatch, CRT format helper, and BrowserNavigate call are no longer first-draft blockers. `by-file/Browser.md` records UID00032W as first-draft ready under the Browser source root. `BrowserNavigate.md` remains unchanged because it already supports `Browser::Navigate(const wchar_t *url)` for this caller.
- Current open questions/confidence caps: exact original BrowserThread member spellings, COM typedef/smart-pointer style, and one-file `Browser.cpp` versus split `BrowserThread.cpp`/legacy source layout remain finalization caps only; no named Gate 1 blocker remains a first-draft C++ blocker.
- Related target/support docs checked: [UID:00001A], [UID:0000HV], [UID:0000ZF], [UID:00032Q], [UID:000333], [UID:0000QO], [UID:0002AD], [UID:00033H], [UID:00033J], [UID:00033K], [UID:000272], [UID:000013], [UID:0002GU], [UID:0002GV], [UID:0002GM], [UID:0002GN], and generated Browser.cpp.
- Current artifact/lifecycle status: implementation callback complete; this report remains at `tools/leaser/Agents/Agent-B010/research/00032W-BrowserThreadInitializeBrowserHost-source-quality.md` awaiting supervisor Gate 1 recheck, Gate 2 review, and later supervisor-only execution if accepted. It has not been executed or moved.

## Executive Recommendation
- Keep the target attached to [UID:00001A] `BrowserThread`; do not move it to [UID:000013] `Browser`, [UID:0000HV] `Browser` file as a free helper, or [UID:00001B] `BrowserWindow`.
- Applied score update from assignment-time `85/89` to current `90/92`. The target now carries current MCP confirmation, exact decompile/disassembly facts, source-facing wide User32 dispatch names, BrowserThread field names, BrowserNavigate call readiness, and a formal first-draft method body. Keep below final-audit quality because exact original local/member spelling and one-file versus split-file Browser source layout remain inferred.
- Formal first-draft `RECONSTRUCTION_CPP CODE` is now present on the target. It deliberately uses source-facing Win32/OLE APIs and inferred Browser/BrowerThread field names instead of `sub_*`/`unk_*` labels.
- Exact condition before final/high-90s code: final project-wide Browser headers should settle exact BrowserThread member spellings, COM smart/raw pointer declarations, and source split. Those are finalization caps, not blockers to first-draft C++.

## Supervisor Active Recheck
- Supervisor instruction: after Gate 1 repair and approval, implement the accepted UID00032W callback, then repair this same report for the post-callback Gate 1/Gate 2 lifecycle without running supervisor-only lifecycle commands.
- Split repair before final master report: not required. The parent [UID:0000ZF] already records UID00032W as an exact child in the final split map.
- Every source-bearing child in this target's immediate dependency path was checked: connection helpers and globals are source-ready; WndProc has formal C++; `Browser::Navigate` remains blank but its signature and call behavior are documented enough for this caller; the named wide API dispatch slots and CRT formatting wrapper are resolved.

## Inference Research Guidance Check
- `by-structure.md` code-entry rules were applied: reconstructable items with valid emitter route and combined score above 85 may receive first-draft C++ only when the emitted code is source-shaped and behavior/dependency names are documented well enough.
- Existing docs were treated as leads. Live MCP rechecked the target function, caller, xrefs, callees, bridge storage, GUID refs, bytes, decompile, and disassembly.
- IDA fact: exact function size, sole caller, data refs, COM GUID refs, global bridge lifecycle, callee list, and decompile field offsets.
- Documentation evidence: support pages now name several Application accessors and Browser fields. Inference remains for final helper names, exact original member spelling, and original Browser source split.
- Wave2/Wave3/generated material was not used as authority. Generated Browser.cpp is used only for post-validator generated freshness/current emitter state, not as primary evidence.

## Heuristic / Inference Reanalysis And Validation
- Method name: `BrowserThread::InitializeBrowserHost` remains the best source-facing name. It is the only callee from `BrowserThread::RunMessageLoop` and owns host window setup, COM initialization, WebBrowser creation, event advise, in-place activation, initial navigation, and failure cleanup.
- Caller/reachability: MCP `xrefs_to 0x00470a00` returns one code xref at `0x0046f044` inside `sub_46F010` / [UID:00032Q]. This supports a private/protected BrowserThread method rather than a shared free helper.
- Browser pointer at `BrowserThread +0x68`: MCP decompile repeatedly reads `*(this+0x68)` and support docs identify it as the legacy [UID:000013] `Browser` object. It is stored into `g_pCurrentBrowserHost`, into HWND `GWL_USERDATA`, and passed to `Browser::Navigate`.
- Window-class name formation: target calls [UID:0002GU] `Application::CopyWorldName`, [UID:0002GV] `Application::CopyPlayerName`, and a wide-format helper at `0x00471110` to build `L"%s.%s.Browser"` into a 256-wide buffer. The two Application copy helpers are resolved; the formatting helper is still wrapper/runtime-like and not target-owned.
- Window registration/create helpers: the restored MCP session resolves the prior `unk_*` blocker. `disasm 0x0041a280` shows `0x0041a311` loads `ds:RegisterClassW` and `0x0041a316` stores it to `unk_69BE40`; `0x0041a31b` loads `ds:CreateWindowExW` and `0x0041a320` stores it to `unk_69BE44`; `0x0041a3bb` loads `ds:LoadCursorW` and `0x0041a3c0` stores it to `unk_69BE84`. `xrefs_to` ties those slots to the target at `0x00470b26`, `0x00470bb0`, and `0x00470aef`. Current support docs [UID:0000TQ] and [UID:0000WD] record the same wide dispatch table. The earlier `RegisterClassA`/`CreateWindowExA` reading is rejected for UID00032W because the class-name buffer is wide, the empty title literal is `word_60DB20`, and the dispatch initializer explicitly installs `*W` APIs.
- COM setup: MCP decompile confirms `CoInitialize(NULL)`, `CoCreateInstance(CLSID_WebBrowser, NULL, CLSCTX_INPROC_SERVER, IID_IOleObject, &ppv)`, `SetClientSite(browser)`, `DoVerb(OLEIVERB_INPLACEACTIVATE, ..., browser->m_hWnd, &rect)`, `QueryInterface(IID_IWebBrowser2, &browser->m_webBrowser)`, `AdviseConnectionPoint(browser->m_webBrowser, DIID_DWebBrowserEvents2, browser, &browser->m_adviseCookie)`, `QueryInterface(IID_IOleInPlaceObject)`, and `IOleInPlaceObject::SetObjectRects(&rect, &rect)` through vtable slot `+0x1c`.
- Browser fields: current Browser docs support `m_hWnd` at `+0x14`, `m_webBrowser` at `+0x18`, `m_adviseCookie` at `+0x1c`, `m_showBrowserAfterLoad` at `+0x222`, `m_pendingDownloadCount` at `+0x224`, and URL pointer/storage at `+0x228`.
- Success path initialization: after COM/activation succeeds, live disassembly writes `Browser+0x20 = 0`, `Browser+0x22 = 0`, `Browser+0x222 = 1`, and `Browser+0x224 = 0`, then calls `Browser::Navigate` with `[Browser+0x228]`.
- Failure path: on any setup failure after COM object creation, the function calls `UnadviseConnectionPoint` when a Browser object exists, releases the Browser object through vtable slot `+0x08`, calls `CoUninitialize`, destroys `browser->m_hWnd`, still reaches the `Browser::Navigate(browser, browser->m_navigationBuffer)` call site, and releases the temporary `ppv` COM pointer if non-null. This cleanup needs careful target-page wording because decompiler shape can look odd; it is current MCP fact.
- Rejected alternatives: Browser ownership rejected because the method receives BrowserThread `this` and uses Browser as a held object. BrowserWindow rejected because all current evidence points to legacy `Browser`, not BrowserWindow. Broad aggregate ownership rejected because [UID:0000ZF] crosses many owners and is non-emitting.
- `0x00471110` formatting helper: current support [UID:000219] and target MCP decompile identify the callee as CRT `__stdio_common_vsnwprintf_s` glue with signature shape `int(wchar_t *Buffer, size_t BufferCount, size_t MaxCount, wchar_t *Format, ...)`. The product source should not call `sub_471110`; use `_snwprintf_s(className, 256, 255, L"%s.%s.Browser", worldName, playerName)` or equivalent secure wide formatting.
- [UID:00033K] `Browser::Navigate`: current support and MCP decompile of `0x00470dd0` support `void Browser::Navigate(const wchar_t *url)`. The method checks `this+0x18` / `m_webBrowser`, allocates a URL BSTR, builds VARIANT/SafeArray navigation arguments, calls the WebBrowser navigation slot, and clears all temporary COM state. Its blank formal C++ is not a hard blocker for UID00032W because this caller only needs the source-shaped call `browser->Navigate(browser->m_navigationBuffer)`.
- BrowserThread fields: support [UID:0002AD], [UID:0000QO], and current target MCP agree that `BrowserThread+0x68` is the legacy `Browser *` object, best first-draft name `m_browser`. The rectangle copied from `BrowserThread+0x70/+0x74/+0x78/+0x7c` is a bounds rectangle used for the host window, best first-draft name `m_hostBounds`. `+0x60` remains the inherited/base thread id used by sibling message-posting code and is not directly consumed by UID00032W.
- Remaining unresolved issue: exact original field spellings and source split are still inferred, but no named blocker from the failed Gate 1 review remains unresolved enough to prevent first-draft C++.

## Evidence Standards Used
- IDA MCP exact-address evidence: `server_health`, `lookup_funcs`, `xrefs_to`, `callees`, `get_bytes`, `decompile`, and paged `disasm` on session `b010_00032w_20260703`.
- by-* support evidence: current target/support docs and generated Browser.cpp post-validator emitter state.
- Executed report leads: B001 [UID:0000ZF], B010 [UID:000333] and [UID:0002AD], B002 Browser empty-emitter batch, B013 BrowserNavigate correction, B004 ApplicationGetInstanceHandle, B006 ApplicationGetMainWindowHandle.
- Negative evidence: no extra caller to `0x00470a00`, no extra xrefs to `0x0067ab8c`, no BrowserWindow object route for UID00032W, and no MCP/support evidence supports the earlier `*A` API interpretation for the three wide dispatch slots.
- Evidence is strong enough for owner, bridge, behavior, score improvement, and a first-draft C++ body. It is not final-audit proof of exact original local/member spelling.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `server_health(database=b010_00032w_20260703)` returned healthy IDB/Hex-Rays/string caches.
  - `lookup_funcs` on `0x00470a00`, `0x0046f010`, `0x0046fcb0`, `0x004708d0`, `0x00470980`, and `0x00470dd0` returned exact functions and current `sub_*` names.
  - `xrefs_to` checked `0x00470a00`, `0x0046fcb0`, `0x0067ab8c`, and COM GUID refs `0x006315a0`, `0x00631620`, `0x00631600`, `0x00631610`, `0x006315d0`.
  - `callees(0x00470a00, limit=80)` recorded the exact static callee/import list.
  - `get_bytes` checked zeroed `0x0067ab88-0x0067ab90`, function entry bytes at `0x00470a00`, and end/padding bytes at `0x00470dc0`.
  - `decompile(0x00470a00, include_addresses=true)` captured field offsets, call order, success/failure branches, and references.
  - Paged `disasm(0x00470a00)` confirmed write sites, call sites, success/failure writes, and final navigate/release sequence.
  - `xrefs_to` on `0x0069be40`, `0x0069be44`, `0x0069be84`, and `0x0069be50` tied the wide API dispatch slots to `0x0041a280` initialization and to UID00032W call sites.
  - `disasm(0x0041a280, max_instructions=120)` confirmed `RegisterClassW -> 0x0069be40`, `CreateWindowExW -> 0x0069be44`, `DefWindowProcW -> 0x0069be50`, and `LoadCursorW -> 0x0069be84`.
  - `imports_query` for RegisterClass/CreateWindowEx/LoadCursor/DefWindowProc confirmed the relevant imports are the wide `*W` APIs in the dispatch table.
  - `decompile(0x00470dd0)` confirmed `Browser::Navigate` checks `m_webBrowser`, builds BSTR/VARIANT/SafeArray navigation arguments, calls the WebBrowser navigation slot, and clears temporaries.
- by-* docs, support docs, old reports, generated reports, and trackers checked: target page, BrowserThread, Browser file, Browser OLE parent, RunMessageLoop, BrowserLegacyHostWndProc, g_pCurrentBrowserHost, BrowserThreadHostGlobals, AdviseConnectionPoint, UnadviseConnectionPoint, BrowserNavigate, Browser COM GUID map, Browser class, g_pBrowserThread, BrowserInitFlags, Application copy/accessor helper pages, generated Browser.cpp, and matching executed B reports.
- Negative checks performed: old BrowserWindow navigation wording was rechecked and remains superseded; no extra caller to target found; no persistent BrowserWindow type evidence for `g_pCurrentBrowserHost`; `RegisterClassA`/`CreateWindowExA`/`LoadCursorA` were rejected for this target because the live initializer installs wide dispatch slots and the target passes wide buffers/literals.
- Failed, unavailable, or intentionally skipped checks and why: no broad MCP searches or callgraphs were run under the IDA MCP Output Discipline; no `idb_open` was called after supervisor restored/assigned the usable session; no `execute_report`/lifecycle commands were run.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID00032W remains `BrowserThread::InitializeBrowserHost` with sole caller from `RunMessageLoop`. | High | MCP `lookup_funcs` and `xrefs_to 0x00470a00` -> one caller `0x0046f044` in `sub_46F010`. | Target Scope/IDA Evidence/Reconstruction Notes | incorporate | applied |
| C2 | `g_pCurrentBrowserHost` is a temporary `Browser *` bridge written at `0x00470b3c`, read by WndProc at `0x0046fcee`, and cleared at `0x00470be3`. | High | MCP `xrefs_to 0x0067ab8c` exactly three refs; support [UID:0002AD]/[UID:0000QO]. | Target IDA Evidence/Reconstruction Notes | incorporate | applied |
| C3 | The registered WndProc pointer is `0x0046fcb0` / `BrowserLegacyHostWndProc`, assigned at `0x00470ab5`. | High | MCP `xrefs_to 0x0046fcb0` one data ref from target; [UID:000333] formal C++. | Target IDA Evidence/Cross-References | incorporate | applied |
| C4 | Application helper names are no longer open for the two name-copy calls and two Application handle getters. | High | Support pages [UID:0002GU], [UID:0002GV], [UID:0002GM], [UID:0002GN]. | Target Reconstruction Notes / Recommended Target Doc Changes | incorporate | applied |
| C5 | COM connection helpers are source-ready as `AdviseConnectionPoint` and `UnadviseConnectionPoint`. | High | Support pages [UID:00033H], [UID:00033J]; MCP callees at `0x4708d0` and `0x470980`. | Target Reconstruction Notes / Cross-References | incorporate | applied |
| C6 | UID00032W received a formal first-draft C++ body using `RegisterClassW`, `CreateWindowExW`, `LoadCursorW`, `_snwprintf_s`, `m_browser`, `m_hostBounds`, and `browser->Navigate(...)` rather than raw `unk_*`/`sub_*` labels. | Medium-high | Current MCP dispatch initializer, target decompile/disassembly, [UID:000219], [UID:00033K], [UID:0002AD], [UID:0000TQ]. | Target C++ block / Reconstruction Notes | incorporate | applied |
| C7 | Current target score after incorporation is `90/92`, metadata unchanged. | Medium-high | Current MCP recheck plus resolved support dependencies and first-draft code readiness; exact original spellings remain inferred. | Target metadata and Score Rationale | incorporate | applied |

## Positive Evidence Summary
- Direct facts supporting the chosen recommendation: the exact function is `0x00470a00-0x00470dc9`; it has one caller from `BrowserThread::RunMessageLoop`; it uses BrowserThread `this`, especially `+0x68`; it creates/initializes a legacy Browser host HWND and WebBrowser COM object.
- Corroborating documentation/generated-report evidence: [UID:00001A], [UID:0000HV], [UID:0000ZF], [UID:000333], [UID:0002AD], [UID:00033H], and [UID:00033J] agree on the BrowserThread/Browser source root and dependency routes.
- Strongest inference chain and why it is sufficient: sole BrowserThread caller plus BrowserThread field use plus Browser object handoff and Browser source-root ownership prove method placement, while Browser object field/support docs prove the bridge and COM event setup roles.

## IDA MCP Facts
- Function/range facts: `lookup_funcs 0x00470a00` -> `sub_470A00`, size `0x3c9`; bytes at entry begin `55 8b ec 6a ff ...`; bytes at `0x00470dc0` end with security-cookie call, epilogue, `c3`, and `0xcc` padding.
- Data/table/padding facts: `0x0067ab88-0x0067ab90` is eight zero bytes; `0x0067ab8c` is the current-host bridge slot.
- Xref facts: target has one caller at `0x0046f044`; WndProc `0x0046fcb0` has one data ref from target at `0x00470ab5`; `0x0067ab8c` has exactly three refs.
- Vtable/global/type facts: target refs `IID_IOleObject` at `0x006315a0`, `CLSID_WebBrowser` at `0x00631620`, `IID_IWebBrowser2` at `0x00631600`, `DIID_DWebBrowserEvents2` at `0x00631610`, and `IID_IOleInPlaceObject` at `0x006315d0`.
- Negative IDA facts: no additional callers to `0x00470a00` were returned; no additional refs to `0x0067ab8c` were returned; the active IDB labels for some dispatch slots remain `unk_*`, but MCP initializer evidence resolves their source-facing identities for this report.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0046f010-0x0046f1c8` | [UID:00032Q] `BrowserThreadRunMessageLoop` | sole caller and thread loop | true | [UID:00001A] | `85/89` | support checked |
| `0x0046fcb0-0x0046ff50` | [UID:000333] `BrowserLegacyHostWndProc` | registered host WndProc | true | [UID:0000HV] | `88/91` | source-ready formal C++ exists |
| `0x004708d0-0x00470953` | [UID:00033H] `AdviseConnectionPoint` | event connection helper | true | [UID:0000HV] | `88/91` | source-ready formal C++ exists |
| `0x00470980-0x00470a00` | [UID:00033J] `UnadviseConnectionPoint` | cleanup helper | true | [UID:0000HV] | `88/91` | source-ready formal C++ exists |
| `0x00470a00-0x00470dc9` | [UID:00032W] target | BrowserThread host initialization | true | [UID:00001A] | current `90/92` | first-draft C++ applied |
| `0x00470dd0-0x00470f10` | [UID:00033K] `BrowserNavigate` | final navigation call | true | [UID:000013] | `86/90` | behavior/signature documented enough for UID00032W call; body remains separately blank |
| `0x0067ab88-0x0067ab90` | [UID:0002AD] `BrowserThreadHostGlobals` | thread/current-host globals | true | [UID:0000HV] | `90/92` | source-ready declarations exist |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0046f044` | call to `0x00470a00` | sole caller from `BrowserThread::RunMessageLoop` |
| `0x00470ab5` | data ref to `0x0046fcb0` | WNDCLASS `lpfnWndProc = BrowserLegacyHostWndProc` |
| `0x00470b3c` | write to `0x0067ab8c` | publish `BrowserThread +0x68` Browser pointer |
| `0x00470bd5` | `SetWindowLongA(hwnd, GWL_USERDATA, browser)` | installs same Browser pointer on HWND |
| `0x00470be3` | clear `0x0067ab8c` | bridge no longer needed after user-data install |
| `0x00470cc3` | call `0x004708d0` | advise `DIID_DWebBrowserEvents2` |
| `0x00470d69` | call `0x00470980` | unadvise on failure cleanup |
| `0x00470d92` | call `0x00470dd0` | navigate using Browser pointer and URL at `+0x228` |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: BrowserThread class, Browser file, Browser OLE parent, g_pCurrentBrowserHost, BrowserThreadHostGlobals, Browser class, BrowserLegacyHostWndProc, Advise/Unadvise helpers, and BrowserNavigate.
- Existing docs that are stale, incomplete, or contradicted: the target's broad statement that helper calls and COM wrappers remain open should be narrowed. The Gate 1 named blockers are now resolved for first-draft purposes: wide User32 dispatch slots are named, the CRT formatting wrapper is non-product glue, BrowserNavigate has a usable call signature, and BrowserThread field roles are source-shaped.
- Generated/coverage report state: generated Browser.cpp refreshed by validator command `000000005599` emits UID00032W as `void BrowserThread::InitializeBrowserHost()` at `90/92`; [UID:00033K] remains a separate expected Empty Emitter Marker.

## Ranked Ownership Analysis

### 1. [UID:00001A] BrowserThread
- Evidence for: sole caller from BrowserThread message loop; target receives BrowserThread `this`; method uses `BrowserThread +0x68` Browser pointer and `BrowserThread +0x70` rectangle/bounds vector; BrowserThread class page already owns this method.
- Evidence against: source declaration likely lives under Browser file root rather than a standalone proven `BrowserThread.cpp`; method heavily manipulates Browser and browser module globals.
- Decision: direct canonical owner remains [UID:00001A]; source root remains [UID:0000HV].

### 2. [UID:0000HV] Browser file root
- Evidence for: file root owns BrowserThread, Browser, WndProc helper, connection helpers, browser globals, and COM GUID consumers.
- Evidence against: too broad to be the direct method owner; the method is a BrowserThread class member.
- Decision: retain as source/emitter route through BrowserThread, not canonical owner for this exact method.

### 3. [UID:000013] Browser
- Evidence for: target publishes and initializes a Browser object and calls `Browser::Navigate`.
- Evidence against: target does not receive Browser `this`; Browser is a field/member object at BrowserThread `+0x68`; setup is owned by the thread.
- Decision: reject as direct owner; Browser is the hosted object dependency.

### 4. [UID:00001B] BrowserWindow
- Evidence for: old docs once confused navigation/helper routes with BrowserWindow.
- Evidence against: current docs and MCP prove the target passes legacy Browser, not BrowserWindow; BrowserWindow has a separate navigation helper and WndProc family.
- Decision: reject.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new file required. Continue using [UID:0000HV] Browser source root, with future source-tree split possibly `browser/BrowserThread.cpp` or `browser/BrowserLegacy.cpp`.
- Likely full contents: BrowserThread methods, Browser object, legacy WndProc, COM helpers, browser globals, and old-control helpers remain part of the broader Browser source root until stronger split evidence appears.
- Candidate related items that belong: [UID:00032Q], [UID:00032W], BrowserThread destructors, [UID:000333], [UID:00033H], [UID:00033J], [UID:0002AD].
- Candidate related items rejected: Application accessors/copy helpers remain Application-owned consumers/dependencies; COM GUID mixed map aggregate remains non-emitting with exact children.
- Standalone, narrow, or broad source-file inference: broad Browser source root is strongest; exact BrowserThread source file split is plausible but unproven.

## Source Placement
- Recommended source file/class/global/module placement: `BrowserThread::InitializeBrowserHost` under BrowserThread class, emitted through Browser source root [UID:0000HV].
- Why this placement fits source-tree and subsystem context: BrowserThread is part of the embedded browser subsystem and its host initialization naturally uses shared Browser module helpers/globals.
- Rejected placements and why: Browser method rejected by caller/receiver; BrowserWindow rejected by object type; Application rejected because it only provides helper/accessor dependencies; PlatformApi rejected because dispatch wrappers are dependencies.
- Remaining placement uncertainty, if any: final one-file `Browser.cpp` versus split legacy/browser-thread source remains open but does not affect current owner metadata.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: MCP confirms `sub_470A00` starts at `0x00470a00`, size `0x3c9`, ending at `0x00470dc9`; bytes after epilogue are `0xcc` padding.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: none. UID00032W is already an exact child.
- Padding/table/data/code distinctions: no target-internal split recommended; local stack `WNDCLASSA`, buffers, and COM temporaries are method-local implementation details.
- Parent/container impact: [UID:0000ZF] remains non-emitting split inventory; no parent metadata change needed.

## Negative Evidence Summary
- No extra callers to the target were found; this argues against a general helper.
- No persistent/current BrowserWindow bridge refs were found for `0x0067ab8c`; only WndProc fallback plus target write/clear exist.
- The Application accessors and name-copy helpers are called by the target, but their support docs prove Application ownership, not BrowserThread ownership.
- `Browser::Navigate` is now correctly Browser-owned, so the final navigate call does not make UID00032W a Browser method.
- Raw active IDB names for the wide dispatch slots remain unsuitable for source, but current MCP/support evidence resolves them to `RegisterClassW`, `CreateWindowExW`, and `LoadCursorW`; using the raw `unk_*` labels in formal C++ is rejected.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments:
  - Use `BrowserThread::InitializeBrowserHost`.
  - Use `Browser *browser = m_browser` or equivalent for `BrowserThread +0x68` in prose; exact member name remains inferred.
  - Use `RECT m_hostBounds` or equivalent for `BrowserThread +0x70/+0x74/+0x78/+0x7c`; this is the host window rectangle copied into the `CreateWindowExW` coordinates and the OLE client rect.
  - Use `BrowserLegacyHostWndProc` for `0x0046fcb0` in documentation.
  - Use `g_pCurrentBrowserHost` as source-facing name for `unk_67AB8C`.
  - Use `RegisterClassW`, `CreateWindowExW`, and `LoadCursorW` for `unk_69BE40`, `unk_69BE44`, and `unk_69BE84`; reject `*A` names for UID00032W.
  - Use `_snwprintf_s` / secure wide-format source for `0x00471110`; do not port the CRT wrapper.
  - Use `Application::CopyWorldName`, `Application::CopyPlayerName`, `Application::GetInstanceHandle`, and `Application::GetMainWindowHandle` for resolved Application dependencies.
  - Use `AdviseConnectionPoint` / `UnadviseConnectionPoint` and standard GUID names `CLSID_WebBrowser`, `IID_IOleObject`, `IID_IWebBrowser2`, `DIID_DWebBrowserEvents2`, and `IID_IOleInPlaceObject`.
- Evidence for each proposed name/type/comment: current support docs and live MCP call/ref sites listed above.
- Items intentionally left unchanged and why: no IDA database rename is requested. The implementation used source-facing names in documentation/C++ only.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested. No IDA rename/type/comment writes were performed.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. The failed Gate 1 named blockers have now been investigated with current MCP/support evidence and are resolved enough for a first-draft source-shaped method body.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` header/block insertion text for supervisor-approved target update:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void BrowserThread::InitializeBrowserHost()
{
    wchar_t worldName[100];
    wchar_t playerName[100];
    wchar_t className[256];
    WNDCLASSW wndClass;
    RECT rect;
    Browser *browser;
    IOleObject *oleObject;
    IOleInPlaceObject *inPlaceObject;
    HRESULT hr;

    g_pApplication->CopyWorldName(worldName, 100);
    g_pApplication->CopyPlayerName(playerName, 100);
    _snwprintf_s(className, 256, 255, L"%s.%s.Browser", worldName, playerName);

    memset(&wndClass, 0, sizeof(wndClass));
    wndClass.style = 0x3028;
    wndClass.lpfnWndProc = BrowserLegacyHostWndProc;
    wndClass.hInstance = g_pApplication->GetInstanceHandle();
    wndClass.hCursor = LoadCursorW(NULL, IDC_ARROW);
    wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndClass.lpszClassName = className;
    RegisterClassW(&wndClass);

    browser = m_browser;
    g_pCurrentBrowserHost = browser;
    browser->m_hWnd = CreateWindowExW(0,
                                      className,
                                      L"",
                                      WS_CHILD | WS_CLIPSIBLINGS,
                                      m_hostBounds.left,
                                      m_hostBounds.top,
                                      m_hostBounds.right - m_hostBounds.left,
                                      m_hostBounds.bottom - m_hostBounds.top,
                                      g_pApplication->GetMainWindowHandle(),
                                      NULL,
                                      g_pApplication->GetInstanceHandle(),
                                      NULL);
    InvalidateRect(browser->m_hWnd, NULL, TRUE);
    SetWindowLongA(browser->m_hWnd, GWL_USERDATA, (LONG)browser);
    g_pCurrentBrowserHost = NULL;

    oleObject = NULL;
    CoInitialize(NULL);
    hr = CoCreateInstance(CLSID_WebBrowser,
                          NULL,
                          CLSCTX_INPROC_SERVER,
                          IID_IOleObject,
                          (void **)&oleObject);
    if (SUCCEEDED(hr)) {
        hr = oleObject->SetClientSite(browser);
    }
    if (SUCCEEDED(hr)) {
        SetRect(&rect,
                0,
                0,
                m_hostBounds.right - m_hostBounds.left,
                m_hostBounds.bottom - m_hostBounds.top);
        hr = oleObject->DoVerb(OLEIVERB_INPLACEACTIVATE,
                               NULL,
                               browser,
                               0,
                               browser->m_hWnd,
                               &rect);
    }
    if (SUCCEEDED(hr)) {
        IWebBrowser2 *webBrowser;

        webBrowser = NULL;
        if (SUCCEEDED(oleObject->QueryInterface(IID_IWebBrowser2, (void **)&webBrowser))) {
            if (browser->m_webBrowser != NULL) {
                browser->m_webBrowser->Release();
            }
            browser->m_webBrowser = webBrowser;
        } else {
            browser->m_webBrowser = NULL;
        }

        AdviseConnectionPoint(browser->m_webBrowser,
                              DIID_DWebBrowserEvents2,
                              browser,
                              &browser->m_adviseCookie);

        inPlaceObject = NULL;
        if (SUCCEEDED(oleObject->QueryInterface(IID_IOleInPlaceObject,
                                                (void **)&inPlaceObject))) {
            inPlaceObject->SetObjectRects(&rect, &rect);
            inPlaceObject->Release();
        }

        browser->m_allowedUrlPrefix[0] = L'\0';
        browser->m_showBrowserAfterLoad = true;
        browser->m_pendingDownloadCount = 0;
    } else if (browser != NULL) {
        UnadviseConnectionPoint(browser->m_webBrowser,
                                DIID_DWebBrowserEvents2,
                                browser->m_adviseCookie);
        browser->Release();
        CoUninitialize();
        DestroyWindow(browser->m_hWnd);
    }

    browser->Navigate(browser->m_navigationBuffer);

    if (oleObject != NULL) {
        oleObject->Release();
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive, when applicable: not applicable.
- Reason it preserves exact original behavior: the draft preserves the wide class-name formatting bound (`256`, `255`), `WNDCLASS` fields including style `0x3028`, `RegisterClassW` / `CreateWindowExW` / `LoadCursorW`, `g_pCurrentBrowserHost` publish/install/clear, COM initialization and WebBrowser activation order, connection-point advise/unadvise, success writes, failure cleanup, final `Browser::Navigate`, and final temporary `IOleObject` release. The `else if` cleanup shape intentionally mirrors the binary's failure-only `CoUninitialize` / `DestroyWindow` path.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: the body is an ordinary Windows/OLE BrowserThread method using direct Win32/OLE APIs, global `g_pApplication`, Browser fields, and helper methods, not a decompiler temporary or raw dispatch-table call body.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `m_browser` for `BrowserThread+0x68`, `m_hostBounds` for `BrowserThread+0x70`, `g_pCurrentBrowserHost` for `unk_67AB8C`, `BrowserLegacyHostWndProc` for `0x0046fcb0`, `_snwprintf_s` for `0x00471110`, and wide User32 APIs for `unk_69BE40/44/84`.
- Naming/coding style convention used and evidence for consistency: use existing Browser module style from accepted first-draft docs (`Browser`, `BrowserThread`, `m_webBrowser`, `m_hWnd`, `m_adviseCookie`, `g_pCurrentBrowserHost`).
- Reason code should remain blank, if applicable: not applicable after this repair.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation
- Exact changes applied or recommended: accepted target/support doc changes were applied during the implementation callback; target now includes first-draft C++.
- Exact parent assignments applied or recommended: keep `CANONICAL_OWNER:00001A`, `EMITTER_UIDS:00001A`, `RECONSTRUCTABLE:TRUE`, parent inventory [UID:0000ZF].
- Exact items left no-owner/non-emitting and why: none for this target. The method remains reconstructable and first-draft C++ ready.
- Exact future work, if any, outside this assignment scope: final-source polish can later settle exact original BrowserThread member spellings, COM pointer declaration style, and Browser source split. No named blocker from this Gate 1 repair remains deferred as a hard UID00032W first-draft blocker.

## Recommended Target Doc Changes
- Target path: `by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md`
- Exact report facts to incorporate:
  - Add MCP session `b010_00032w_20260703` health and exact `lookup_funcs` result: `sub_470A00`, size `0x3c9`.
  - Record current `xrefs_to`: one caller at `0x0046f044`; one WndProc pointer ref at `0x00470ab5`; exactly three `g_pCurrentBrowserHost` refs.
  - Replace broad "helper calls remain open" with resolved dependency table: `Application::CopyWorldName`, `Application::CopyPlayerName`, `Application::GetInstanceHandle`, `Application::GetMainWindowHandle`, `AdviseConnectionPoint`, `UnadviseConnectionPoint`, `BrowserLegacyHostWndProc`, `g_pCurrentBrowserHost`, Browser fields, `RegisterClassW`, `CreateWindowExW`, `LoadCursorW`, `_snwprintf_s`-style formatting, and `Browser::Navigate(const wchar_t *)` are now documented enough for first-draft C++.
  - Add negative evidence rejecting `RegisterClassA` / `CreateWindowExA` / `LoadCursorA` for UID00032W because the wide dispatch initializer installs `*W` slots and the target uses wide class-name/title data.
  - Add detailed COM setup/failure cleanup sequence from current decompile.
  - Add success writes to Browser fields `+0x20`, `+0x22`, `+0x222`, `+0x224`, and final call to `Browser::Navigate` with URL pointer at `+0x228`.
  - Add the formal first-draft C++ block from this report.
- Metadata/score/owner/emitter/reconstructable/C++ changes: recommend `COMPLETION:90`, `CONFIDENCE:92`; keep owner/emitter/reconstructable unchanged; insert first-draft formal C++.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: preserve rejection of BrowserWindow navigation/host type, rejection of BrowserThread class ownership for `g_pCurrentBrowserHost` storage, and rejection of broad aggregate ownership.

## Recommended Support Doc Changes
- Support path: `by-class/BrowserThread.md`
- Exact report facts to incorporate: narrow the old open question. `BrowserThread+0x68` should be documented as `Browser *m_browser`; `BrowserThread+0x70` should be documented as `RECT m_hostBounds`; UID00032W's wide API dispatch, CRT format helper, and BrowserNavigate call are no longer hard first-draft blockers.
- Metadata/link/score/coverage/source-placement changes: no score change required.

- Support path: `by-file/Browser.md`
- Exact report facts to incorporate: note UID00032W as first-draft ready after resolving wide API dispatch slots, CRT wide-format wrapper disposition, BrowserThread field names, and BrowserNavigate call readiness.
- Metadata/link/score/coverage/source-placement changes: no score change required.

- Support path: `by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md`
- Exact report facts to incorporate: no immediate score/body change required, but if touched, add that UID00032W may call the documented `Browser::Navigate(const wchar_t *url)` signature even while BrowserNavigate's own formal body remains a separate reconstruction target.
- Metadata/link/score/coverage/source-placement changes: no score change recommended here.

## Score And Metadata Recommendation
- Current score/metadata: `90/92`, owner/emitter [UID:00001A], reconstructable true, formal C++ populated.
- Recommended score/metadata: `90/92`, owner/emitter/reconstructable unchanged, formal first-draft C++ inserted.
- Score rationale and reason not higher/lower: raise completion for current MCP evidence, resolved Application helper names, source-ready connection helpers, resolved wide User32 dispatch slots, resolved CRT formatting disposition, BrowserThread field names, BrowserNavigate call readiness, and first-draft code. Do not raise above low 90s because exact original local/member spellings, COM declaration style, and one-file versus split-file Browser source layout remain inferred.
- Score-improvement attempt:
  - Caller/owner blocker: resolved by live MCP sole-caller check.
  - Bridge type blocker: resolved by live MCP xrefs plus [UID:0002AD]/[UID:0000QO].
  - Connection helper blocker: resolved by [UID:00033H]/[UID:00033J] formal C++ docs.
  - Application helper blocker: resolved for copy/accessor helpers via [UID:0002GU]/[UID:0002GV]/[UID:0002GM]/[UID:0002GN].
  - `unk_69BE40`/`unk_69BE44`/`unk_69BE84` blocker: resolved by current MCP `0x0041a280` disassembly and [UID:0000TQ]/[UID:0000WD] as `RegisterClassW`, `CreateWindowExW`, and `LoadCursorW`; `*A` alternatives rejected.
  - `0x00471110` blocker: resolved by [UID:000219] as CRT secure wide-format glue; product source should use `_snwprintf_s` / `swprintf_s`-style formatting.
  - [UID:00033K] blocker: resolved for UID00032W caller purposes by current docs/MCP signature `Browser::Navigate(const wchar_t *url)`.
  - BrowserThread field blocker: resolved for first draft as `m_browser` at `+0x68` and `m_hostBounds` at `+0x70`.
  - Method C++ blocker: resolved to first-draft code; remaining uncertainty is finalization-level naming/source split, not a first-draft blocker.
- Metadata fields to change or leave unchanged: change only completion/confidence and formal C++ if accepted; leave owner/emitter/reconstructable unchanged.

## Open Questions With Attempted Resolution
- Open question: can formal UID00032W C++ now be inserted?
  - Evidence checked: current target decompile/disassembly, support docs, generated Browser.cpp, connection/global/Application helper pages, Browser class, BrowserNavigate.
  - Resolution: yes for first draft. Wide User32 dispatch slots, CRT wide-format wrapper disposition, BrowserThread fields, and BrowserNavigate call identity are now resolved enough to avoid raw `sub_`/`unk_` labels.
- Open question: should `g_pCurrentBrowserHost` be `Browser *`, `BrowserWindow *`, or raw pointer?
  - Evidence checked: MCP xrefs, [UID:0002AD], [UID:0000QO], [UID:000333].
  - Resolution: `Browser *` for documentation/source-facing type.
- Open question: should owner/emitter change to Browser file root?
  - Evidence checked: sole caller, receiver offsets, Browser file/class docs.
  - Resolution: no. Browser file root remains source route; direct owner remains BrowserThread.
- Questions remaining unresolved: exact original spelling of local/member names, COM pointer typedef style, and Browser source split. These cap final confidence only; they do not block the recommended first-draft C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. No manual `-coverage-report.md` or supervisor-owned tracker row should be edited. Validator-owned generated reports refreshed through scoped validator commands during the approved implementation callback.

## Follow-Up Actions
- Supervisor actions: Gate 1 review this report; if accepted, send implementation callback to update target/support docs only, then run scoped validators after edits.
- A-agent actions: none.
- B010 future research actions: if supervisor wants code readiness next, target [UID:00033K] `BrowserNavigate` and the Browser/platform window dispatch wrapper family before UID00032W formal C++.

## Confidence
- Recommendation confidence: high for metadata/owner/source-placement and first-draft C++ recommendation.
- Score confidence: medium-high for `90/92`; exact final score is supervisor policy-sensitive, but target clearly has more current evidence and code readiness than `85/89`.
- Remaining uncertainty: exact original source spelling/linkage, COM declaration style, and final Browser source split.

## Validator Results
- Commands run:
  - `python .\tools\validator.py --mode file --file by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md --apply --queue-timeout 240`
    - `command_id: 000000005597`
    - `command_timestamp: 2026-07-03T16:15:34-04:00`
    - Exit code: `0`
    - `ok: 1`
  - `python .\tools\validator.py --mode file --file by-class/BrowserThread.md --apply --queue-timeout 240`
    - `command_id: 000000005598`
    - `command_timestamp: 2026-07-03T16:15:41-04:00`
    - Exit code: `0`
    - `ok: 1`
  - `python .\tools\validator.py --mode file --file by-file/Browser.md --apply --queue-timeout 240`
    - `command_id: 000000005599`
    - `command_timestamp: 2026-07-03T16:15:41-04:00`
    - Exit code: `0`
    - `ok: 1`
  - Generated refresh status check: `python .\tools\validator.py --queue-status`
    - Final status command `000000005601` at `2026-07-03T16:16:06-04:00`
    - Worker running, no queued jobs, no processing jobs, no queued/processing generated-refresh jobs.
- Results:
  - Target validator updated UID00032W to `COMPLETION:90`, `CONFIDENCE:92`, changed the autogen registry from blank to block, inserted/updated UID links, updated projected stats, and reported `generated_refresh: deferred`.
  - `BrowserThread.md` validator passed with projected stats updates.
  - `Browser.md` validator passed with UID link normalization and projected stats update; generated refresh completed through command `000000005599`.
  - Generated Browser output freshness checked: `auto-generated/NexusTK/browser/Browser.cpp` header shows `validator-command-id: 000000005599` and `validator-refreshed-at: 2026-07-03T16:15:41-04:00`; UID00032W now emits `void BrowserThread::InitializeBrowserHost()` at `Completion:90 | Confidence:92`. UID00033K remains an expected separate Empty Emitter Marker.
- Any unresolved validator warnings/errors: `Browser.md` validator reported pre-existing `missing_ref_uid` warnings for several unrelated UIDs such as `000408`, `00040B`, `0003OH`, `000407`, `000409`, `00040A`, and `00040C`; exit code remained `0` and `ok: 1`.

## Changed Files
- Created: none.
- Modified by B010:
  - `by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md`
  - `by-class/BrowserThread.md`
  - `by-file/Browser.md`
  - `tools/leaser/Agents/Agent-B010/research/00032W-BrowserThreadInitializeBrowserHost-source-quality.md`
- Validator-owned side effects observed/reported:
  - `auto-generated/NexusTK/browser/Browser.cpp` refreshed to command `000000005599`.
  - `project-level/-auto-completion-stats.md` projected stats updated by scoped validators.
  - `tools/validator.ini` autogen registry updated for UID00032W by validator command `000000005597`.
- Renamed: none.
- Report execution: not run. B agents must not run `execute_report`, dry-run variants, registry lifecycle commands, manual report moves, or archive commands.

## Implementation Tracking Checklist
- [x] Supervisor validation required before implementation: Gate 1 passed; implementation callback approved by supervisor.
- [x] Target/support docs to update: target `by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md`, support `by-class/BrowserThread.md`, and support `by-file/Browser.md` updated. Optional BrowserNavigate edit excluded as already sufficient for the narrow dependency note.
- [x] Current target state and actual evidence checked recorded: incorporated MCP session `b010_00032w_20260703`, exact function/caller/xref/callee/decompile/disassembly facts, COM GUID refs, success/failure cleanup, and generated post-refresh emitter state.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: ledger C1-C7 marked `applied`.
- [x] Metadata/score changes applied: target updated to `COMPLETION:90`, `CONFIDENCE:92`; owner/emitter/reconstructable unchanged.
- [x] Score-limiting blockers researched and applied: `unk_69BE40`/`unk_69BE44`/`unk_69BE84`, `0x00471110`, [UID:00033K] `Browser::Navigate`, and BrowserThread `+0x68/+0x70` fields resolved for first-draft C++ and documented.
- [x] Owner/emitter/reconstructable changes to apply: none; unchanged as accepted.
- [x] Split/rename/new-child changes to apply: none.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: no split/reclass and no IDA DB edits; source-facing names documented.
- [x] First-draft C++ or no-code proof to apply: formal first-draft C++ inserted into target.
- [x] Third-party import directive to apply or confirm not applicable, including exact `third_party_embeds/...` paths and confirmation that the multiline C++ block remains blank: not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: sole caller, WndProc registration, current-host bridge, COM setup, success/failure cleanup, resolved wide API dispatch names, CRT helper disposition, BrowserNavigate call readiness, BrowserThread field names, and rejected `*A`/BrowserWindow alternatives.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: BrowserWindow ownership/type, Browser direct ownership for the method, broad aggregate ownership, raw helper names as final source, and `*A` API alternatives rejected.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: generated Browser.cpp used only for generated freshness/current emitter state, not as proof.
- [x] Open questions closed or documented as evidence-backed unresolved: formal first-draft C++ no longer blocked; finalization uncertainty limited to exact original spellings/source split.
- [x] Validators run: scoped target/support validators recorded above.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: generated Browser.cpp refreshed to validator command `000000005599`; no manual coverage text recommended.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000005627","destination_path":"executed-b-agent-research/B010/00032W-BrowserThreadInitializeBrowserHost-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/00032W-BrowserThreadInitializeBrowserHost-source-quality.md","timestamp":"2026-07-03T16:40:56-04:00","uid":"00032W"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
