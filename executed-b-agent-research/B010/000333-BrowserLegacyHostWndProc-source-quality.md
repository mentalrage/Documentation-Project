** TARGET-REPORT-UID:000333 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000333 BrowserLegacyHostWndProc Source-Quality Research

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:000333] `by-memory/0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md` as a Browser file-level/static WndProc helper, keep `CANONICAL_OWNER:0000HV`, keep `EMITTER_UIDS:0000HV`, and treat the source-facing name `BrowserLegacyHostWndProc` as the best descriptive name for now.
- Final disposition: [UID:000333] is the registered legacy Browser host window procedure used by `BrowserThread::InitializeBrowserHost`, not a BrowserWindow callback clone, not a BrowserThread method, not a Browser class vtable method, and not a broad aggregate. The range should remain `0x0046fcb0-0x0046ff50` because the function body and its compiler switch tables/padding are a single exact source item.
- Required action: report-only pass. Supervisor or same-agent implementation callback should incorporate the target/support details below, replace the supervisor-owned coverage row, and populate first-draft C++ if the recommendation is accepted.
- Confidence: high for owner/source placement and reachability (`91/100`), high for switch/case behavior and local table mapping (`91/100`), medium-high for exact final original source name and Browser field names (`86-88/100`).

## Supporting Research

## Target

- Target UID: `000333`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md`
- Source assignment: `B010-goal2-browser-legacy-host-wndproc-source-quality-000333-20260619`
- Current supervisor classification: report-only B-agent source-quality and heuristic/inference pass. Do not edit by-* docs and do not edit `by-memory/-coverage-report.md`.
- Current target state:
  - `COMPLETION:85`
  - `CONFIDENCE:87`
  - `CANONICAL_OWNER:0000HV`
  - `RECONSTRUCTABLE:TRUE`
  - `EMITTER_UIDS:0000HV`
  - formal C++ block blank
- Current generated state:
  - `auto-generated/-ag-memory-coverage.md` line for [UID:000333] routes to `auto-generated/NexusTK/browser/Browser.cpp` and reports `emits` through owner/emitter `0000HV`.
  - `auto-generated/NexusTK/browser/Browser.cpp` currently contains only an `Empty Emitter Marker` for [UID:000333].
- Current supervisor-owned coverage row:
  - `by-memory/-coverage-report.md` currently lists the row as `85% : strong` with only `GetWindowLongA(hwnd, -21)` and `dword_67AB8C` evidence.

## Executive Recommendation

[UID:000333] should be documented as a file-static Browser source helper:

```cpp
static LRESULT CALLBACK BrowserLegacyHostWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
```

This name is inferred/descriptive, not original-symbol proof. It is still better than `sub_46FCB0` or a generic `WndProc` because the Browser module now has multiple WndProc-shaped helpers:

- [UID:00020V] `BrowserWindowHostWndProc` at `0x0046a630`, the registered BrowserWindow host WndProc.
- [UID:00020W] `BrowserRawWindowProcClone` at `0x0046a760`, a retained raw WndProc-shaped body with no proven registration.
- [UID:000333] `BrowserLegacyHostWndProc` at `0x0046fcb0`, the registered legacy Browser host WndProc created by `BrowserThread::InitializeBrowserHost`.

The report recommends a target score change from `85/87` to `88/91` after implementation because the remaining shallow points can be resolved:

- `sub_46FCB0` can be replaced in prose with `BrowserLegacyHostWndProc`.
- `dword_69BE50` can be resolved as the PlatformApi `g_pfnDefWindowProcW` dispatch slot.
- The host pointer type can be tightened to `Browser *` for this callback path, because local PE disassembly confirms `BrowserThread +0x68` is published through `g_pCurrentBrowserHost`, stored into `GWL_USERDATA`, and then used as a Browser object with fields `+0x14` and `+0x18`.
- The message switch table can be mapped exactly: `WM_PAINT`, `WM_KEYDOWN`, `WM_KEYUP`, `WM_SYSKEYDOWN`, `WM_SYSKEYUP`, and default.
- The keyboard behavior can be documented in source terms: query `IID_IOleInPlaceActiveObject`, `VK_TAB` activation through `IID_IOleObject::DoVerb(OLEIVERB_UIACTIVATE)`, `VK_ESCAPE` and `VK_F4` consume-and-release, and all other key messages call `IOleInPlaceActiveObject::TranslateAccelerator`.

## Supervisor Active Recheck

- The supervisor assigned a specific target, so normal B010 target selection and the stale ChangeMan note are superseded for this turn.
- This assignment is report-only. I did not edit the target by-memory page, support by-* pages, generated reports, project-level reports, or `by-memory/-coverage-report.md`.
- The target does not require split repair before reporting. The range already starts at the WndProc function and ends at the next exact child, [UID:0002P3] `BrowserControlPaneOldConstructor` at `0x0046ff50`.
- No new child pages are recommended. The bytes after the function body are local compiler switch data and padding that belong with this WndProc item, not separate source-owned memory pages.

## Inference Research Guidance Check

`by-structure.md` and `inference_research.md` affect this recommendation in these ways:

- The direct semantic owner must be the narrowest true owner that clears the score gate. The callback has a Win32 `WNDPROC` entry signature and no `thiscall`/vtable method shape, so assigning it to `BrowserThread` or `Browser` as a class method would be too narrow. The Browser by-file page is the correct source root.
- Existing documentation was treated as a lead. It already identified the row as a Browser legacy host WndProc, but left `dword_69BE50`, exact case table, host pointer type, source C++ readiness, and final source naming insufficiently resolved.
- Address adjacency alone was not used as ownership proof. The callback is accepted because `BrowserThread::InitializeBrowserHost` registers it, the Browser file owns the legacy Browser/BrowserThread/COM helper source root, and the function body uses the Browser object layout and Browser COM GUIDs.
- Local PE disassembly was used only as read-only binary evidence because live IDA MCP was unavailable in this session. Stored IDA-backed docs remain the primary documentation evidence, and the local PE MD5 matches the already documented IDA target: `4247e04e20b65d6414c7238aa8ff5515`.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best inference / decision | Rejected alternatives and impact |
| --- | --- | --- | --- |
| `sub_46FCB0` generated function name | Target page, B001 split report, local PE disassembly of `0x0046fcb0-0x0046fe47`, pointer hit at `0x00470abb`, initializer instruction at `0x00470ab5`. | Use descriptive source-facing name `BrowserLegacyHostWndProc`. The name is inferred, not original-symbol proof. | Reject leaving `sub_46FCB0` because source quality is otherwise strong. Reject generic `WndProc` because Browser has multiple WndProc-like helpers. Reject `BrowserWindowHostWndProc` because [UID:00020V] already owns that active BrowserWindow callback. |
| Callback registration/reachability | Stored docs record the direct xref from `0x00470ab5`. Local PE disassembly shows `mov [ebp-0x3e8], 0x46fcb0` in the WNDCLASS setup and a loaded-file pointer/immediate hit at VA `0x00470abb`. | This is registered by `BrowserThread::InitializeBrowserHost` as `WNDCLASSA.lpfnWndProc`. It is live/reachable through the legacy Browser host window class. | Reject retained-raw/no-route treatment. Unlike [UID:00020W], this target has a proven registration pointer. |
| Host pointer type | Target/support docs say `GetWindowLongA(hwnd, -21)` and `g_pCurrentBrowserHost`; `g_pCurrentBrowserHost` docs still leave the final type open. Local PE disassembly of `0x00470b33-0x00470be3` shows `[BrowserThread + 0x68]` written to `0x0067ab8c`, stored by `SetWindowLongA(hwnd, GWL_USERDATA, value)`, then cleared. [UID:00033K] confirms `BrowserThread +0x68` is a `Browser` object. | For this WndProc, the retrieved pointer should be typed as `Browser *` or a source-local legacy Browser host object pointer whose concrete layout is the `Browser` object. It uses Browser fields `+0x14` (`HWND`) and `+0x18` (hosted OLE/WebBrowser object). | Reject `BrowserWindow *` for this target. BrowserWindow has a separate host WndProc at `0x0046a630`; this body uses the legacy `Browser` object stored by BrowserThread. Keep exact field names provisional until Browser class layout is finalized. |
| `dword_67AB8C` generated global | `g_pCurrentBrowserHost.md`, `0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md`, local PE setup/clear sequence. | Use `g_pCurrentBrowserHost` in target prose and first-draft code. It is a temporary construction bridge used before the HWND user data is installed. | Reject treating it as a long-lived active browser singleton. The producer clears it after `SetWindowLongA`. |
| `dword_69BE50` generated global | `WideApiDispatchTable.md`, `WideApiDispatchInit.md`, InputMan support sync, unresolved report entry for `dword_69BE50`, local PE WndProc fallback call through `[0x0069be50]`. | Resolve as PlatformApi `g_pfnDefWindowProcW`. In target prose and C++ draft, call `g_pfnDefWindowProcW(hwnd, message, wParam, lParam)` or the accepted final PlatformApi dispatch-table spelling. | Reject Browser ownership for `dword_69BE50`; it is a platform wide API dispatch slot. Reject `DefWindowProcA` for this target despite the `WNDCLASSA` setup, because the binary calls the wide dispatch slot. |
| Message switch cases | Local PE disassembly of `0x0046fcf5-0x0046fd0a` and selector table at `0x0046fe54`. | The switch indexes `message - WM_PAINT` for values through `0x105`. Selector entries map `0x0f` to paint, `0x100/0x101/0x104/0x105` to keyboard/accelerator handling, and all other in-table values to default. Out-of-range messages also default. | Reject vague "keyboard messages" wording as incomplete. Reject creating a separate table owner; these are local compiler switch bytes. |
| Local switch table names | Local PE table decode: NOP at `0x0046fe47`, three jump dwords at `0x0046fe48`, byte selector table at `0x0046fe54-0x0046ff4b`, `0xcc` padding at `0x0046ff4b-0x0046ff50`. | Document as compiler-generated switch table/padding owned by [UID:000333]. | Reject by-global/by-type pages for `jpt`/`byte` labels. Reject splitting the table into ignored padding because it is necessary for the function's switch. |
| Paint case | Local PE calls `BeginPaint` at `0x0046fd16` and `EndPaint` at `0x0046fd21`, returns `0`. | Source case is standard `WM_PAINT` validation. | No alternate owner or helper. |
| Accelerator COM query | Local PE queries `[browser + 0x18]` with GUID `0x006315c0`, documented as `IID_IOleInPlaceActiveObject`. Calls vtable `+0x14`, matching `IOleInPlaceActiveObject::TranslateAccelerator(MSG *)`, then vtable `+0x08` release. | Source behavior: query the active object interface and translate eligible keyboard messages through it. | Reject an event/packet interpretation. This is COM/OLE accelerator handling. |
| `VK_TAB` branch | Local PE checks `wParam == 9`, queries `IID_IOleObject` at `0x006315a0`, calls `GetClientRect(browser->hwnd)`, then vtable `+0x2c` with verb `-4`, `pActiveSite = browser`, parent HWND and rect. | Source behavior: on Tab, activate the OLE object with `IOleObject::DoVerb(OLEIVERB_UIACTIVATE, NULL, browser, 0, browser->m_hostWindow, &rect)`, then continue to `TranslateAccelerator`. | Reject treating Tab as a simple SendMessage callback; that belongs to nearby BrowserControlPaneOld message handling, not this WndProc. |
| Escape/F4 branch | Local PE checks `wParam == 0x1b` and `wParam == 0x73`; both release active object and return `0`. | Source behavior: consume Escape and F4-style key messages after releasing the queried active object. `0x73` is `VK_F4`; when the message is `WM_SYSKEYDOWN`, this covers Alt+F4 style input. | Reject older vague "F4-style" wording without the exact `VK_F4` value. |
| MSG construction for TranslateAccelerator | Local PE writes only `message`, `wParam`, and `lParam` into the local MSG-shaped block before passing it to `TranslateAccelerator`; no store to `hwnd`, `time`, or `pt` is visible in the function body. | First-draft C++ should record this caveat. A source-quality draft can use `MSG accelerator = {}; accelerator.hwnd = hwnd; ...` only if the implementation accepts a cleaner Win32 source spelling over exact store fidelity; the binary only proves the three message fields. | Do not claim exact original source used full `MSG msg = { hwnd, message, wParam, lParam }`. This uncertainty caps final-audit confidence but does not block a draft. |
| Direct owner/source placement | Browser by-file page groups Browser, BrowserThread, BrowserWindow, BrowserControlPaneOld, COM helpers, browser GUIDs, and browser globals. Target callback is registered by BrowserThread but is a C callback operating on Browser state. | Keep direct owner/emitter [UID:0000HV] Browser file. Model as file-static helper in `NexusTK/browser/Browser.cpp` unless a future split creates a narrower `BrowserThread.cpp` or legacy-browser source file. | Reject direct class owner `BrowserThread`: it registers but does not own the callback body as a method. Reject direct class owner `Browser`: callback shape is not a method. Reject BrowserWindow: separate active WndProc exists. |
| C++ readiness | Target is reconstructable, has nonblank emitter to a valid Browser file root, and average score is already `86`. Local PE reanalysis resolves the main source-quality blockers. | Populate first-draft C++ after target/support text is updated, using source-facing names and explicit unresolved field/type notes. | Do not leave formal C++ blank solely because the original PDB name is missing. Do not emit decompiler-shaped casts to raw offsets in final source. |

Unresolved issues that remain after this pass:

- Exact original symbol name is not proven. `BrowserLegacyHostWndProc` is descriptive.
- Exact Browser class field names for offsets `+0x14` and `+0x18` should be finalized in a Browser layout pass. Current source-facing names `m_hostWindow` and `m_oleObject` are inferred from use.
- Exact original source split is still likely `browser/Browser.cpp`, but `BrowserThread.cpp` or a legacy browser helper source file remains possible. This does not block the current by-file owner because [UID:0000HV] is the current browser source root.
- The original source's `MSG` initialization style is not fully recoverable from current static evidence; binary stores only `message`, `wParam`, and `lParam`.

## Evidence Standards Used

- Stored IDA-backed documentation: target page, Browser file/class pages, BrowserThread pages, BrowserThread host-global pages, Browser COM GUID pages, Browser OLE split report, PlatformApi dispatch pages, and sibling WndProc reports.
- Local binary read-only evidence: Capstone disassembly of `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, MD5 `4247E04E20B65D6414C7238AA8FF5515`.
- Generated report evidence: `auto-generated/-ag-memory-coverage.md`, `auto-generated/NexusTK/browser/Browser.cpp`, `project-level/-auto-completion-stats.md`, and `project-level/-unresolved.md`.
- Negative evidence: no need to split the switch table, no class method/vtable signature, no BrowserWindow registration route for this address, and PlatformApi ownership for `dword_69BE50`.
- Live IDA MCP status: attempted `tools/list` against `http://127.0.0.1:13337/mcp`; PowerShell returned `Unable to connect to the remote server`. Therefore this pass does not claim fresh live IDA MCP observations.

## Stored IDA Facts And Local PE Recheck

### Stored IDA / Documentation Facts

- Target page reports `sub_46FCB0` at `0x0046fcb0-0x0046fe47`; following bytes through `0x0046ff50` are switch/table data and padding.
- Target page reports the only direct xref as setup from `BrowserThread` host initialization at `0x00470ab5`.
- [UID:0000QO] `g_pCurrentBrowserHost` reports three bridge xrefs: WndProc fallback read at `0x0046fcee`, publish at `0x00470b3c`, clear at `0x00470be3`.
- [UID:0002AD] `BrowserThreadHostGlobals` reports `lookup_funcs 0x0046fcb0` size `0x197` / 407 bytes and `analyze_function 0x0046fcb0` showing the `GetWindowLongA(hwnd, -21)` then `0x0067ab8c` fallback.
- [UID:00032W] `BrowserThreadInitializeBrowserHost` reports sole caller from `RunMessageLoop`, WNDCLASS/host setup, `g_pCurrentBrowserHost` write/clear, `SetWindowLongA`, COM initialization, browser COM GUID references, connection-point setup, and navigation handoff.
- [UID:0003OH] `BrowserComGuidConstants` identifies:
  - `0x006315a0` as `IID_IOleObject`.
  - `0x006315c0` as `IID_IOleInPlaceActiveObject`.
  - `0x00631600` as `IID_IWebBrowser2`.
  - `0x00631610` as `DIID_DWebBrowserEvents2`.
  - `0x00631620` as `CLSID_WebBrowser`.
- [UID:0000TQ] `WideApiDispatchTable` identifies `0x0069be50` as `g_pfnDefWindowProcW`, installed by [UID:0000WD] `WideApiDispatchInit`.

### Local PE Disassembly Facts

Local read-only disassembly of `0x0046fcb0-0x0046fe47` confirms:

- Function prologue uses SEH/security-cookie scaffolding. This is compiler-generated support around the source body, not source-level logic.
- `0x0046fce1` calls `USER32.dll!GetWindowLongA` with `-0x15` (`GWL_USERDATA`).
- `0x0046fcee` conditionally moves `0x0067ab8c` into the local host pointer when the HWND user data is null.
- `0x0046fd03` indexes the byte selector table at `0x0046fe54`; `0x0046fd0a` dispatches through the dword jump table at `0x0046fe48`.
- `0x0046fd11` is the `WM_PAINT` target and calls `BeginPaint`/`EndPaint`.
- `0x0046fd2e` is the keyboard/accelerator target.
- `0x0046fe1b` calls through `[0x0069be50]`, the PlatformApi `g_pfnDefWindowProcW` slot.
- `0x0046fd40` pushes `0x006315c0` (`IID_IOleInPlaceActiveObject`) for `QueryInterface`.
- `0x0046fd78` pushes `0x006315a0` (`IID_IOleObject`) for the Tab activation path.
- `0x0046fd98` calls `GetClientRect` on `[browser + 0x14]`.
- `0x0046fdb2` calls vtable `+0x2c`, matching `IOleObject::DoVerb`, with verb `-4`.
- `0x0046fe00` calls vtable `+0x14`, matching `IOleInPlaceActiveObject::TranslateAccelerator`.
- `0x0046fddd`, `0x0046fdc3`, and `0x0046fe14` release COM interfaces through vtable `+0x08`.

Local read-only disassembly of `0x00470a00-0x00470dc9` confirms the registration and bridge:

- `0x00470ab5`: writes `0x0046fcb0` into the local WNDCLASS structure's `lpfnWndProc` field.
- `0x00470b33`: loads `[BrowserThread + 0x68]`.
- `0x00470b3c`: writes that Browser object pointer to `g_pCurrentBrowserHost`.
- `0x00470bb0`: calls the wide CreateWindowEx dispatch slot.
- `0x00470bc3`: stores the created HWND at `[Browser + 0x14]`.
- `0x00470bd5`: calls `SetWindowLongA(hwnd, GWL_USERDATA, browser)`.
- `0x00470be3`: clears `g_pCurrentBrowserHost`.

The local loaded-file scan found one little-endian pointer/immediate hit for `0x0046fcb0`: file offset `0x6febb`, VA `0x00470abb`, inside the `mov [ebp-0x3e8], 0x46fcb0` instruction. This matches the stored IDA xref.

## Function / Range Inventory

| Range / Item | Role | Ownership / handling | Status |
| --- | --- | --- | --- |
| `0x0046fcb0-0x0046fe47` | WndProc function body | Browser file-level helper | Reconstructable; recommend first-draft C++ |
| `0x0046fe47-0x0046fe48` | Single `0x90` byte | Alignment before switch table | Keep inside [UID:000333] range |
| `0x0046fe48-0x0046fe54` | Three-entry dword jump table | Local compiler switch table | Keep inside [UID:000333] range |
| `0x0046fe54-0x0046ff4b` | 247-byte selector table for `message - 0x0f` | Local compiler switch table | Keep inside [UID:000333] range |
| `0x0046ff4b-0x0046ff50` | Five `0xcc` bytes | Padding before [UID:0002P3] | Keep inside [UID:000333] range |
| `0x0046ff50` | Start of `BrowserControlPaneOldConstructor` | Next exact child | Do not extend [UID:000333] past this point |

No split is recommended. The range is exact and well bounded.

## Message / Switch Case Inventory

The switch subtracts `0x0f` from the message and accepts indices through `0xf6`, covering message values `0x0f` through `0x105`. The default path is used for out-of-range messages and for all in-range selector entries with value `2`.

| Message | Selector | Target | Source interpretation |
| --- | ---: | --- | --- |
| `0x000f` | `0` | `0x0046fd11` | `WM_PAINT`: `BeginPaint`/`EndPaint`, return `0`. |
| `0x0100` | `1` | `0x0046fd2e` | `WM_KEYDOWN`: COM accelerator path. |
| `0x0101` | `1` | `0x0046fd2e` | `WM_KEYUP`: COM accelerator path. |
| `0x0104` | `1` | `0x0046fd2e` | `WM_SYSKEYDOWN`: COM accelerator path, including Alt+F4 style `VK_F4`. |
| `0x0105` | `1` | `0x0046fd2e` | `WM_SYSKEYUP`: COM accelerator path. |
| all others | `2` or out-of-range | `0x0046fe1b` | `g_pfnDefWindowProcW(hwnd, message, wParam, lParam)`. |

Keyboard subcases:

| `wParam` | Value | Behavior |
| --- | ---: | --- |
| `VK_TAB` | `0x09` | Query `IID_IOleObject`, call `DoVerb(OLEIVERB_UIACTIVATE, NULL, browser, 0, browser->hwnd, &clientRect)`, release the `IOleObject`, then continue to `IOleInPlaceActiveObject::TranslateAccelerator`. |
| `VK_ESCAPE` | `0x1b` | Release queried active object and return `0` without translating. |
| `VK_F4` | `0x73` | Same consume/release path as Escape. |
| other keys | variable | Build a local MSG-shaped block from `message`, `wParam`, and `lParam`, call `TranslateAccelerator`, release active object, return `0`. |

## Direct Xref / Caller / Reachability Inventory

| Address / Item | Evidence | Meaning |
| --- | --- | --- |
| `0x00470ab5` | Stored docs and local PE disassembly show immediate `0x0046fcb0` stored into WNDCLASS data. | Registered callback pointer for the legacy browser host HWND. |
| `0x00470abb` | Local loaded-file scan hit for little-endian `0x0046fcb0`. | Confirms the pointer/immediate location inside the registration instruction. |
| `0x00470b3c` | Writes `[BrowserThread + 0x68]` to `g_pCurrentBrowserHost`. | Temporary publish before window creation/user-data association. |
| `0x00470bd5` | Calls `SetWindowLongA(hwnd, GWL_USERDATA, browser)`. | Normal WndProc lookup path after creation. |
| `0x00470be3` | Clears `g_pCurrentBrowserHost`. | Proves the global is a setup bridge, not a persistent active-browser pointer. |
| `0x0046fcee` | Reads `g_pCurrentBrowserHost` only if `GetWindowLongA` returns null. | Early message fallback while the HWND is being connected. |

## Documentation Evidence And Current Status

Existing docs that support the conclusion:

- [UID:0000HV] `Browser` groups the legacy Browser, BrowserThread, BrowserControlPaneOld, BrowserWindow, COM helper, GUID, and browser global family under `NexusTK/browser/Browser.cpp`.
- [UID:0000ZF] `BrowserOleLegacyAndHelpers` already lists [UID:000333] as an exact Browser file helper child and rejects the broad aggregate as a single owner.
- [UID:00001A] `BrowserThread` and [UID:00032W] `BrowserThreadInitializeBrowserHost` document the host creation flow and the bridge/global lifecycle.
- [UID:0000QO] `g_pCurrentBrowserHost` and [UID:0002AD] `BrowserThreadHostGlobals` document the storage, exact xrefs, and temporary publish/read/clear pattern.
- [UID:0003OH] `BrowserComGuidConstants` identifies the GUIDs used by this body.
- [UID:0000TQ] `WideApiDispatchTable` resolves `0x0069be50` as the PlatformApi `DefWindowProcW` dispatch entry.

Existing docs that are stale, incomplete, or should be updated during implementation:

- Target page still says the fallback is through `dword_69BE50`; this should be replaced with `g_pfnDefWindowProcW` and a PlatformApi dispatch-table cross-reference.
- Target page says final callback name and exact key constants remain provisional; the report resolves the source-facing name enough for a draft and identifies `VK_TAB`, `VK_ESCAPE`, and `VK_F4`.
- Target page lacks the exact local switch-table breakdown.
- Target/support pages should tighten the bridge pointer type for this path to `Browser *` or "legacy Browser object pointer" rather than leaving `BrowserWindow *` as a peer type candidate.
- `project-level/-unresolved.md` still lists `sub_46FCB0` and `dword_69BE50` because the target text still contains those names. This should disappear after the target wording is updated and unresolved reports are refreshed by the appropriate tool workflow.

## Ranked Ownership Analysis

### 1. [UID:0000HV] Browser file source root

- Evidence for: `BrowserThread::InitializeBrowserHost` registers the callback while constructing the legacy Browser host; the body operates on Browser object fields and Browser COM GUIDs; the Browser file page owns Browser, BrowserThread, BrowserControlPaneOld, browser COM helper data, `g_pCurrentBrowserHost`, and related source helpers; direct file root clears the score gate at `86/88`.
- Evidence against: exact original source could have used a narrower `BrowserThread.cpp` or legacy-browser source file inside the browser folder.
- Decision: accepted. Current direct owner/emitter remains [UID:0000HV] because no narrower by-file page exists and class ownership would be structurally wrong for a C callback.

### 2. [UID:00001A] BrowserThread class

- Evidence for: `BrowserThread::InitializeBrowserHost` is the only proven registration route; `BrowserThread +0x68` supplies the Browser object.
- Evidence against: callback signature is Win32 `WNDPROC`, not a `BrowserThread` method. The body does not use `BrowserThread this`; it retrieves a Browser object from HWND user data/global bridge and uses Browser COM fields.
- Decision: rejected as canonical owner. BrowserThread is the producer/registrar and should be a cross-reference, not the direct owner.

### 3. [UID:000013] Browser class

- Evidence for: the callback's object pointer is the Browser object, and the body reads Browser fields at `+0x14` and `+0x18`.
- Evidence against: entry signature is not a Browser method; no `thiscall` shape; callback must be addressable as a free/static function in WNDCLASS registration.
- Decision: rejected as canonical owner. Browser class should be documented as the state object used by the WndProc, not as the direct owner.

### 4. [UID:00001B] BrowserWindow / active BrowserWindow WndProc family

- Evidence for: same subsystem and WndProc shape.
- Evidence against: [UID:00020V] owns the registered BrowserWindow host callback at `0x0046a630`; [UID:00020W] is the separate raw clone; this target is registered by BrowserThread at `0x00470ab5` and uses legacy Browser fields, not BrowserWindow state.
- Decision: rejected.

### 5. [UID:0000ML] PlatformApi / WideApiDispatchTable

- Evidence for: default fallback calls through `0x0069be50`.
- Evidence against: PlatformApi owns only the dispatch pointer, not this Browser callback. The callback behavior, registration, GUIDs, and object state are browser-specific.
- Decision: rejected as target owner; keep only as support owner for `g_pfnDefWindowProcW`.

### 6. [UID:0000ZF] Browser OLE Legacy And Helpers aggregate

- Evidence for: parent inventory contains the range.
- Evidence against: aggregate is intentionally non-emitting and mixed-owner. Exact child [UID:000333] already exists.
- Decision: rejected as direct source owner; keep as parent inventory/cross-reference.

## Negative Evidence Summary

- Consumer use of PlatformApi `g_pfnDefWindowProcW` does not imply PlatformApi owns the WndProc.
- Registration by BrowserThread does not imply the callback is a BrowserThread method; the callback has no BrowserThread object input after the HWND is created.
- Browser object field use does not imply direct Browser class ownership because Win32 callback registration requires a free/static entry point.
- BrowserWindow WndProc precedent does not merge this target with [UID:00020V] or [UID:00020W]. Those are a separate host class and raw clone family around `0x0046a630-0x0046a855`.
- Local switch table labels are compiler artifacts. No by-global/by-type pages should be created for `0x0046fe48` or `0x0046fe54`.
- The broad `0x0046f010-0x004710b8` aggregate should remain non-emitting; [UID:000333] is the exact source-bearing item.

## First-Draft C++ Recommendation

Populate [UID:000333] with first-draft C++ if the implementation callback accepts this report. This draft intentionally uses source-facing names rather than raw offsets. It assumes the Browser layout pass will provide `Browser::m_hostWindow` for offset `+0x14`, `Browser::m_oleObject` for offset `+0x18`, and a PlatformApi declaration for `g_pfnDefWindowProcW`.

```cpp
static LRESULT CALLBACK BrowserLegacyHostWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    Browser *browser = reinterpret_cast<Browser *>(GetWindowLongA(hwnd, GWL_USERDATA));
    if (browser == NULL) {
        browser = g_pCurrentBrowserHost;
    }

    switch (message) {
    case WM_PAINT:
    {
        PAINTSTRUCT paint;
        BeginPaint(hwnd, &paint);
        EndPaint(hwnd, &paint);
        return 0;
    }

    case WM_KEYDOWN:
    case WM_KEYUP:
    case WM_SYSKEYDOWN:
    case WM_SYSKEYUP:
    {
        IOleInPlaceActiveObject *activeObject = NULL;
        if (browser->m_oleObject != NULL) {
            if (FAILED(browser->m_oleObject->QueryInterface(IID_IOleInPlaceActiveObject,
                                                            reinterpret_cast<void **>(&activeObject)))) {
                activeObject = NULL;
            }
        }

        if (wParam == VK_TAB) {
            IOleObject *oleObject = NULL;
            if (browser->m_oleObject != NULL) {
                if (FAILED(browser->m_oleObject->QueryInterface(IID_IOleObject,
                                                                reinterpret_cast<void **>(&oleObject)))) {
                    oleObject = NULL;
                }
            }

            RECT clientRect;
            GetClientRect(browser->m_hostWindow, &clientRect);
            oleObject->DoVerb(OLEIVERB_UIACTIVATE,
                              NULL,
                              browser,
                              0,
                              browser->m_hostWindow,
                              &clientRect);

            if (oleObject != NULL) {
                oleObject->Release();
            }
        } else if (wParam == VK_ESCAPE || wParam == VK_F4) {
            if (activeObject != NULL) {
                activeObject->Release();
            }
            return 0;
        }

        MSG acceleratorMessage;
        acceleratorMessage.message = message;
        acceleratorMessage.wParam = wParam;
        acceleratorMessage.lParam = lParam;
        activeObject->TranslateAccelerator(&acceleratorMessage);

        if (activeObject != NULL) {
            activeObject->Release();
        }
        return 0;
    }

    default:
        break;
    }

    return g_pfnDefWindowProcW(hwnd, message, wParam, lParam);
}
```

Implementation caveats for the draft:

- The binary does not show stores to `MSG.hwnd`, `MSG.time`, or `MSG.pt` before `TranslateAccelerator`; the draft leaves the local `MSG` partially assigned to preserve that source shape. If a future style pass chooses `MSG acceleratorMessage = {}; acceleratorMessage.hwnd = hwnd;`, document that as a source cleanup rather than exact store evidence.
- The draft checks `FAILED(QueryInterface(...))` because that matches the binary's signed HRESULT test. The subsequent `oleObject->DoVerb` and `activeObject->TranslateAccelerator` calls are still written as direct calls because the binary dereferences those locals without a final null guard on the non-Escape paths.
- The final implementation may need to use the project's accepted PlatformApi dispatch name instead of `g_pfnDefWindowProcW`.
- The final implementation may need a cast or interface base for the `browser` argument passed to `IOleObject::DoVerb`; the binary passes the Browser object pointer as the active client site.

## Exact Supervisor-Owned Coverage Row Text

Placement context: replace the existing [UID:000333] child row in `by-memory/-coverage-report.md` under the [UID:0000ZF] Browser OLE legacy/helper split block. Agents must not edit this shared coverage file while the supervisor-owned ban remains active.

Current exact row:

```text
      - [UID:000333][0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc](by-memory/0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md) 0x0046fcb0-0x0046ff50 | file helper | BrowserLegacyHostWndProc : reconstructable : 85% : strong : Browser file-level host window procedure assigned to [UID:0000HV][Browser](by-file/Browser.md); IDA behavior includes hosted-window lookup through `GetWindowLongA(hwnd, -21)` and `dword_67AB8C`.
```

Recommended replacement row after implementation:

```text
      - [UID:000333][0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc](by-memory/0x0046fcb0-0x0046ff50.BrowserLegacyHostWndProc.md) 0x0046fcb0-0x0046ff50 | file helper | BrowserLegacyHostWndProc : reconstructable : 88% : very-strong : B010 source-quality reanalysis confirms this as the registered legacy Browser host WndProc for BrowserThread host creation: `0x00470ab5` writes `0x0046fcb0` into `WNDCLASSA.lpfnWndProc`, `0x00470b3c` publishes the `BrowserThread+0x68` Browser object through `g_pCurrentBrowserHost`, `0x00470bd5` stores the same Browser pointer with `SetWindowLongA(hwnd, GWL_USERDATA, browser)`, and `0x00470be3` clears the construction bridge. The body retrieves `Browser*` from `GetWindowLongA(hwnd, -21)` with `g_pCurrentBrowserHost` fallback, handles `WM_PAINT`, handles `WM_KEYDOWN`/`WM_KEYUP`/`WM_SYSKEYDOWN`/`WM_SYSKEYUP` through `IID_IOleInPlaceActiveObject::TranslateAccelerator`, uses `VK_TAB` for `IID_IOleObject::DoVerb(OLEIVERB_UIACTIVATE)` client-rect activation, consumes `VK_ESCAPE`/`VK_F4`, resolves fallback `dword_69BE50` as PlatformApi `g_pfnDefWindowProcW`, maps compiler switch data at `0x0046fe48-0x0046ff4b` plus padding to `0x0046ff50`, keeps owner/emitter [UID:0000HV][Browser](by-file/Browser.md), and recommends first-draft file-static C++ under `NexusTK/browser/Browser.cpp`.
```

No manual change is recommended for `auto-generated/-ag-memory-coverage.md`. It should refresh through validator/autogen after target implementation.

## Target / Support Implementation Checklist

Use this as the exact implementation callback checklist if the supervisor accepts the report.

### Target [UID:000333]

- Metadata:
  - Change `COMPLETION:85` to `COMPLETION:88`.
  - Change `CONFIDENCE:87` to `CONFIDENCE:91`.
  - Keep `CANONICAL_OWNER:0000HV`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - Keep `EMITTER_UIDS:0000HV`.
  - Populate the formal C++ block with the accepted first-draft `static LRESULT CALLBACK BrowserLegacyHostWndProc(...)` body above, unless the supervisor explicitly decides the unresolved Browser layout should keep C++ blank. If kept blank, the target must document this report's no-code reason.
- Add source-quality sections/facts:
  - Registration: `0x00470ab5` WNDCLASS `lpfnWndProc` assignment; local pointer hit at `0x00470abb`.
  - Bridge lifecycle: `0x00470b3c` publish, `0x00470bd5` `SetWindowLongA`, `0x00470be3` clear.
  - Host pointer type: best-supported type is `Browser *` / legacy Browser object pointer, because setup uses `BrowserThread +0x68` and body reads Browser fields `+0x14` and `+0x18`.
  - Message table: NOP at `0x0046fe47`; dword jump table `0x0046fe48-0x0046fe54`; selector table `0x0046fe54-0x0046ff4b`; `0xcc` padding `0x0046ff4b-0x0046ff50`.
  - Message cases: `WM_PAINT`; `WM_KEYDOWN`; `WM_KEYUP`; `WM_SYSKEYDOWN`; `WM_SYSKEYUP`; default.
  - Key subcases: `VK_TAB`, `VK_ESCAPE`, `VK_F4`.
  - COM interfaces: `IID_IOleInPlaceActiveObject` for `TranslateAccelerator`; `IID_IOleObject` for `DoVerb(OLEIVERB_UIACTIVATE)`.
  - PlatformApi fallback: replace `dword_69BE50` with `g_pfnDefWindowProcW` and link support page [UID:0000TQ] / [UID:0000WD].
  - Add a "B010 2026-06-19 Source-Quality Reanalysis" section preserving rejected alternatives: BrowserThread method, Browser class method, BrowserWindow WndProc, raw clone/no-route treatment, PlatformApi owner, and switch-table split.

### Support Docs

- [UID:0000QO] `by-global/g_pCurrentBrowserHost.md`
  - Add the sharper type inference for this callback path: the bridge publishes `[BrowserThread + 0x68]`, which [UID:00033K] and local PE evidence identify as the legacy `Browser` object. The final declaration may still use the project-approved Browser/host type name, but `BrowserWindow *` should no longer be presented as an equally likely type for UID 000333.
  - Preserve the temporary bridge lifecycle and exact three xrefs.
- [UID:0002AD] `by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md`
  - Add the `SetWindowLongA(hwnd, GWL_USERDATA, browser)` local PE confirmation if support text is updated.
  - Keep owner/emitter [UID:0000HV].
- [UID:00032W] `by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md`
  - Add the source-quality callback registration line: `0x00470ab5` stores `BrowserLegacyHostWndProc` into WNDCLASS; `0x00470bd5` stores the same Browser pointer into window user data.
  - No score change is required unless the support page receives enough detail to justify a small completion bump.
- [UID:0000HV] `by-file/Browser.md`
  - Add a short routing note distinguishing [UID:000333] from [UID:00020V] and [UID:00020W].
  - State that [UID:000333] is the registered legacy Browser host WndProc and is eligible for first-draft C++ once target implementation is applied.
- `by-memory/-coverage-report.md`
  - Do not edit directly as B010. Supervisor should replace only the exact row listed above after target/support implementation is verified.
- `project-level/-unresolved.md`
  - Do not edit manually. After target/support docs remove `sub_46FCB0` and `dword_69BE50`, refresh the unresolved report through the normal project workflow if requested.

### Validation Commands Expected During Implementation

Run scoped validators after editing target/support docs, one file at a time:

> Executable block R001 was removed from this report and preserved verbatim in [000333-BrowserLegacyHostWndProc-source-quality-removed.md](000333-BrowserLegacyHostWndProc-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If only the target page is edited, run only the target validator first. If support docs are left unchanged because their current detail is deemed sufficient, record that reason in the implementation report.

## Final Recommendation

- Exact changes recommended:
  - Improve [UID:000333] from `85/87` to `88/91`.
  - Keep Browser owner/emitter `0000HV`.
  - Populate first-draft C++ for [UID:000333].
  - Replace `sub_46FCB0` source-facing prose with `BrowserLegacyHostWndProc`.
  - Replace `dword_69BE50` target prose with PlatformApi `g_pfnDefWindowProcW`.
  - Document exact switch table and keyboard/COM behavior.
  - Tighten `g_pCurrentBrowserHost` type inference to Browser object pointer for this path.
- Exact parent assignments recommended:
  - No owner/emitter change. [UID:000333] remains under [UID:0000HV] Browser.
- Exact items left no-owner/non-emitting:
  - None in this target.
  - The switch table remains inside [UID:000333], not a separate ownerless item.
- Exact future work outside assignment:
  - Final Browser class layout and field names.
  - Final one-file versus split-file browser source layout.
  - Final PlatformApi dispatch-table typedef/name style.

## Follow-Up Actions

- Supervisor actions:
  - Review this report.
  - If accepted, send same-agent implementation callback using the checklist above.
  - After implementation, apply the supervisor-owned `by-memory/-coverage-report.md` row replacement if still current.
- A-agent actions:
  - None required before B010 implementation. A future Browser layout pass can improve field names around Browser offsets `+0x14` and `+0x18`.
- B010 future actions:
  - Apply target/support docs if supervisor sends implementation callback.
  - Preserve all positive and negative evidence from this report during implementation.

## Confidence

- Recommendation confidence: `91/100` for Browser file-level ownership/source placement.
- Score confidence after implementation: `88/91` is justified. Completion should not exceed low 90s until Browser field names, exact original source split, and full final C++ dependencies are settled.
- Remaining uncertainty:
  - Original symbol name is inferred.
  - Browser field names are inferred.
  - Original source file split is inferred.
  - MSG local initialization style is partially inferred from binary stores.

## Validator Results

- No by-* validators were run for this report-only pass because no by-* files were edited.
- IDA MCP check attempted and failed due local endpoint being unavailable:
  - Command shape: PowerShell JSON-RPC `tools/list` to `http://127.0.0.1:13337/mcp`.
  - Result: `Unable to connect to the remote server`.
- Local PE read-only disassembly was performed against:
  - `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
  - MD5 `4247E04E20B65D6414C7238AA8FF5515`
  - Capstone version available in Python: `5.0.7`

## Changed Files

- Created:
  - `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B010\research\000333-BrowserLegacyHostWndProc-source-quality.md`
- Modified:
  - None outside the new research report.
- Renamed:
  - None.
- Moved to executed:
  - None.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/000333-BrowserLegacyHostWndProc-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"000333"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000333-BrowserLegacyHostWndProc-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/000333-BrowserLegacyHostWndProc-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000333"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
