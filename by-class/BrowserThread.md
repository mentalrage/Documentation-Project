*** UID:00001A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BrowserThread

## Summary

`BrowserThread` owns the dedicated thread path for the legacy embedded browser. It initializes COM, creates the browser host window and WebBrowser object, wires connection points, starts navigation, and runs a private message loop for browser shutdown/redraw/keyboard forwarding.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp` or `browser/BrowserThread.cpp`
- Confidence: strong for the browser module and parent attachment; medium-high for exact file split and final thread/base declarations

## Methods

| Range | Current interpretation | Notes |
| --- | --- | --- |
| `0x0046eff0-0x0046f005` | non-deleting destructor | Reinstalls the BrowserThread vtable, clears `g_pBrowserThread`, and delegates to the base `Thread` destructor. |
| [UID:00032Q][0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop](by-memory/0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop.md) | `RunMessageLoop` | Source-ready first-draft method: initializes the browser host once, runs the private `GetMessageA` loop, handles `0x500` close and `0x501` redraw messages, forwards Tab through PlatformApi `SendMessageW`, posts browser notifications, deletes the hosted Browser object, and tears down COM. |
| [UID:00032R][0x0046f1d0-0x0046f1db.BrowserThreadDeleteIfPresentWrapper](by-memory/0x0046f1d0-0x0046f1db.BrowserThreadDeleteIfPresentWrapper.md) | delete-if-present wrapper | Vtable-only non-emitting wrapper slot; source reconstruction should express the real destructor behavior rather than port this helper literally. |
| [UID:00032V][0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor](by-memory/0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor.md) | scalar deleting destructor | Repeats the BrowserThread singleton clear/base teardown path and applies delete flags. |
| [UID:00032W][0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost](by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md) | `InitializeBrowserHost` | First-draft source-ready method: registers/creates the wide browser host window, bridges the pending host through `g_pCurrentBrowserHost`, initializes COM, creates the WebBrowser object, advises browser events, navigates, and handles cleanup. |

## Constructor And Start Support

[UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) now uses this source-facing support shape:

```cpp
BrowserThread::BrowserThread(Browser *browser, const RectBounds &bounds);
void BrowserThread::StartThread(); // or inherited Thread start equivalent for 0x005965e0
```

The constructor support is implementation-ready for UID0002P3 even though the broader class-level declaration still has source-split caveats. Current MCP session `b010_00032w_20260703` confirms the old-pane constructor allocates `0x80` bytes, calls generic `Thread` construction with argument `1`, installs the BrowserThread vtable `0x00613744`, stores `browser` at `+0x68`, clears byte `+0x6c`, copies the 16-byte bounds record to `+0x70`, writes `g_pBrowserThread`, then calls `0x005965e0` to start/resume the thread.

Source-facing member support for that constructor is:

| Offset | Accepted support name | Evidence / use |
| ---: | --- | --- |
| `+0x68` | `Browser *m_browser` | UID0002P3 stores the Browser pointer here; `RunMessageLoop` and `InitializeBrowserHost` use the same field. |
| `+0x6c` | `m_hostInitialized` or exact equivalent host-init flag | UID0002P3 clears it; `RunMessageLoop` tests and sets it before calling `InitializeBrowserHost`. |
| `+0x70` | `RectBounds m_hostBounds` / `m_hostBounds` | UID0002P3 copies the incoming bounds record here; UID00032W host initialization uses the same rectangle as `m_hostBounds`. |

Keep `g_pBrowserThread` ownership under the Browser source root and [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md). Do not route this constructor support to the generic Thread file, and do not model the UID0002P3 body with raw offsets or manual vtable stores.

## Evidence

- Live IDA MCP recheck on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA confirms the ordinary destructor at `0x0046eff0-0x0046f005`; it refs BrowserThread vtable `0x00613744`, clears [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md) at `0x0046eff6`, and sits between `0xcc` padding at `0x0046efec-0x0046eff0` and `0x0046f005-0x0046f010`.
- IDA confirms `RunMessageLoop` at `0x0046f010-0x0046f1c8`, with the BrowserThread vtable slot at `0x00613760` and a direct call to `InitializeBrowserHost` at `0x0046f044`.
- B008 current MCP session `b010_00032w_20260703` confirms `RunMessageLoop` as a `0x1b8` byte source-ready method: the vtable bytes at `0x00613760` are `10 f0 46 00 d0 f1 46 00`, the exact body is padded by `0xcc` before `0x0046f010` and after `0x0046f1c8`, and the single direct target xref is the BrowserThread vtable data ref.
- The method gates [UID:00032W][0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost](by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md) behind the BrowserThread byte at `+0x6c`; the hosted Browser pointer is the `BrowserThread +0x68` field already used by host setup.
- The message loop calls `GetMessageA`, `GetAsyncKeyState`, `TranslateMessage`, `RedrawWindow`, `ShowWindow`, `SetFocus`, `CoUninitialize`, and [UID:000014][browser__Notification](by-class/browser__Notification.md) posting helper `0x00470f20` at `0x0046f15d`.
- The message loop uses PlatformApi dispatch slots [UID:0000TQ][WideApiDispatchTable](by-global/WideApiDispatchTable.md): `PostMessageW` at `0x0069be90` from `0x0046f0c3` for Alt+F4/`WM_QUIT` posting, `SendMessageW` at `0x0069bec4` from `0x0046f0e6` for Tab forwarding to the hosted Browser HWND, and `DispatchMessageW` at `0x0069be64` from `0x0046f10b` after `TranslateMessage`.
- IDA confirms vtable-only wrapper `0x0046f1d0-0x0046f1db` from slot `0x00613764`; it stays documented but is not source behavior to hand-port.
- IDA confirms scalar deleting destructor `0x004706f0-0x0047073b` from slot `0x00613744`; it refs BrowserThread vtable `0x00613744`, clears `g_pBrowserThread` at `0x004706fc`, calls the base-thread destructor path `0x00596400`, and applies delete flags.
- IDA confirms `InitializeBrowserHost` at `0x00470a00-0x00470dc9`, called only from `RunMessageLoop`; it writes/clears [UID:0000QO][g_pCurrentBrowserHost](by-global/g_pCurrentBrowserHost.md) at `0x00470b3c` and `0x00470be3`.
- Host initialization calls the browser/window helpers at `0x00465b70`, `0x00465b90`, `0x00471110`, and `0x004651c0`; Win32/OLE APIs include `GetStockObject`, `InvalidateRect`, `SetWindowLongA`, `CoInitialize`, `CoCreateInstance`, `SetRect`, `CoUninitialize`, and `DestroyWindow`.
- Host initialization refs browser COM GUID data at `0x006315a0`, `0x00631620`, `0x00631600`, `0x00631610`, and `0x006315d0`, calls `AdviseConnectionPoint` at `0x00470cc3`, calls `UnadviseConnectionPoint` at `0x00470d69`, and calls [UID:00033K][0x00470dd0-0x00470f10.BrowserNavigate](by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md) at `0x00470d92` on the Browser pointer stored at `BrowserThread +0x68`.
- B007 Rule 26 reanalysis keeps BrowserThread as the owner of COM/OLE initialization, host thread loop, browser host creation, connection-point setup/cleanup, and the `BrowserThread +0x68` Browser pointer handoff. It calls `Browser::Navigate` during host setup but does not own [UID:000013][Browser](by-class/Browser.md)'s COM client/event-sink methods.
- `g_pBrowserThread` xrefs now map constructor storage from [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) at `0x004700ef`/`0x004700f6`, destructor clears at `0x0046eff6` and `0x004706fc`, and legacy Browser/BrowserDialogOld reads around `0x004694c0-0x00469620` and `0x0046f810`.
- 2026-06-27 B010 accepted [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md) implementation resolves the BrowserThread host-global behavior/type question for this class: active MCP session `80de0a67` renders the storage labels as `unk_67AB88` and `unk_67AB8C`, but the source-facing declarations are first-draft ready as `static BrowserThread *g_pBrowserThread;` and `static Browser *g_pCurrentBrowserHost;`. The current-host bridge publishes the `BrowserThread +0x68` legacy Browser object at `0x00470b3c`, installs the same pointer into `GWL_USERDATA` at `0x00470bd5`, and clears the bridge at `0x00470be3`.
- 2026-07-03 B010 UID00032W implementation callback resolves the remaining host-init first-draft blockers for this class. Current MCP session `b010_00032w_20260703` proves `BrowserThread+0x68` is the legacy `Browser *` object, best first-draft member name `m_browser`, and `BrowserThread+0x70/+0x74/+0x78/+0x7c` is the host rectangle, best first-draft member name `m_hostBounds`. The same pass resolves the host-init wide API dispatch slots as `RegisterClassW`, `CreateWindowExW`, and `LoadCursorW`, the CRT helper `0x00471110` as `_snwprintf_s`-style wide formatting glue, and the final navigate call as `Browser::Navigate(const wchar_t *url)`.
- BrowserThread vtable `0x00613744` has direct refs from the ordinary destructor `0x0046eff0`, the old control-pane constructor `0x00470103`, and the scalar deleting destructor `0x004706f6`.
- 2026-06-10 B001-024 live IDA MCP rechecked the in-aggregate exact children while splitting [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md): `RunMessageLoop` `0x0046f010-0x0046f1c8` has vtable ref `0x00613760`, `DeleteIfPresent` wrapper `0x0046f1d0-0x0046f1db` has vtable ref `0x00613764`, scalar deleting destructor `0x004706f0-0x0047073b` has vtable ref `0x00613744` and clears `g_pBrowserThread`, and `InitializeBrowserHost` `0x00470a00-0x00470dc9` is called only from `RunMessageLoop`.

## Open Questions

- The [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md) storage pair is no longer a behavior/type/C++ blocker for this class. Its accepted first-draft declarations are `static BrowserThread *g_pBrowserThread;` and `static Browser *g_pCurrentBrowserHost;`, emitted by the Browser file root through [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md). The remaining global-declaration uncertainty is exact original linkage/source split only: true file-local `static` in `Browser.cpp` versus private Browser-module header declarations if legacy Browser, BrowserThread, BrowserDialogOld, or BrowserControlPaneOld are later split into separate source files.
- The former browser key-callback ambiguity for [UID:0000PT][g_browserControlKeyCallback](by-global/g_browserControlKeyCallback.md) no longer blocks `RunMessageLoop`; [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) resolves the storage as the PlatformApi `SendMessageW` slot. Remaining cleanup is final typedef/global spelling in the dispatch table, not BrowserThread ownership.
- Finalize the `Thread` base-class layout, exact BrowserThread member spelling beyond accepted first-draft `m_browser`, `m_hostBounds`, and inferred `+0x6c` host-initialized byte, and whether the original source split kept this code in `Browser.cpp` or a separate `BrowserThread.cpp`. These are class/source-split caveats, not blockers for UID00032Q or UID00032W first-draft method bodies.
- UID00032W's former helper blockers are closed for first draft: the Application copy/getter helpers, Browser COM connection helpers, `BrowserLegacyHostWndProc`, `g_pCurrentBrowserHost`, wide API dispatch slots, CRT format helper, and `Browser::Navigate(const wchar_t *)` call are documented on the exact child page.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:00001B][BrowserWindow](by-class/BrowserWindow.md), [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md), [UID:000014][browser__Notification](by-class/browser__Notification.md)
- Globals/enums: [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md), [UID:0000QO][g_pCurrentBrowserHost](by-global/g_pCurrentBrowserHost.md), [UID:0000PT][g_browserControlKeyCallback](by-global/g_browserControlKeyCallback.md), [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md)
- Memory: [UID:000215][0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor](by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md), [UID:00032Q][0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop](by-memory/0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop.md), [UID:00032R][0x0046f1d0-0x0046f1db.BrowserThreadDeleteIfPresentWrapper](by-memory/0x0046f1d0-0x0046f1db.BrowserThreadDeleteIfPresentWrapper.md), [UID:00032V][0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor](by-memory/0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor.md), [UID:00032W][0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost](by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md), [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md)

## Changes

- 2026-07-03 B008 UID00032Q implementation callback:
  - Summary/evidence: synchronized [UID:00032Q][0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop](by-memory/0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop.md) as a source-ready first-draft `int BrowserThread::RunMessageLoop()` child. Current MCP session `b010_00032w_20260703` confirms exact range `0x0046f010-0x0046f1c8`, size `0x1b8`, vtable bytes `10 f0 46 00 d0 f1 46 00` at `0x00613760`, `this+0x6c` host-init guard, `this+0x68` Browser pointer use, `0x500` close, `0x501` redraw, PlatformApi `PostMessageW`/`SendMessageW`/`DispatchMessageW` slot calls, notification post, Browser virtual teardown, `CoUninitialize`, and Win32Error throw path. The old class-level "write full BrowserThread method C++ later" wording is now narrowed to remaining declaration/source-split polish and the separate host-init child.
- 2026-06-04: Raised completion/confidence from `72/80` to `84/88`, marked reconstructable, and attached to [UID:0000HV][Browser](by-file/Browser.md).
  - Before: the page identified the core BrowserThread methods but relied on stale provenance wording, was not attached to the Browser parent, and did not record the live singleton/vtable/message-loop/host-initialization evidence needed to leave the low-score queue.
  - After: live IDA evidence records the binary identity, exact method ranges, vtable slots, padding, `g_pBrowserThread` writes/clears/reads, `g_pCurrentBrowserHost` bridge writes, message-loop callees, notification posting, COM host creation, connection-point setup/cleanup, and BrowserThread construction from the legacy control-pane constructor.
  - Reasoning: the class is clearly source-authored browser-module code and the parent file is already high-confidence enough for attachment. Final C++ remains blank because thread/base layout, host helper names, COM declarations, and the one-file versus split-file decision are still below the 95/95 reconstruction bar.
- What existed before: the page documented BrowserThread purpose, methods, evidence, and references, but metadata was still `0/0`.
- What it was changed to: scores were set to `72/80`.
- Summary and evidence: destructor, message loop, host initialization, COM setup, and browser notification links are covered; thread base layout and final file split still need reconstruction.
- 2026-06-10 B001-024 exact-child split:
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88` unchanged.
  - Summary/evidence: exact child pages now carry fresh IDA-backed evidence for `RunMessageLoop`, the non-emitting vtable delete wrapper, the scalar deleting destructor, and `InitializeBrowserHost`. The class clears the strict parent gate for those children because method ranges, vtable refs, singleton/global writes, host bridge, COM setup, notification posting, and constructor handoff are documented. Final C++ remains blank because base `Thread` layout and original one-file versus `BrowserThread.cpp` source split remain below the final-code gate.
- 2026-06-19 B013 support sync: changed the `0x00470dd0` navigation/cleanup helper route from stale BrowserWindow naming to [UID:00033K][0x00470dd0-0x00470f10.BrowserNavigate](by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md), preserving the BrowserThread `+0x68` Browser pointer evidence.
- 2026-06-20 B007 Browser class boundary sync: clarified that BrowserThread calls [UID:00033K][0x00470dd0-0x00470f10.BrowserNavigate](by-memory/0x00470dd0-0x00470f10.BrowserNavigate.md) from host setup but does not own [UID:000013][Browser](by-class/Browser.md)'s COM client/event-sink source.
- 2026-06-27 B010 BrowserThread host-global implementation sync:
  - Summary/evidence: incorporated accepted [UID:0002AD][0x0067ab88-0x0067ab90.BrowserThreadHostGlobals](by-memory/0x0067ab88-0x0067ab90.BrowserThreadHostGlobals.md) result. The two Browser module globals now have first-draft declaration readiness and active-label evidence: `unk_67AB88` / `g_pBrowserThread` as `BrowserThread *`, and `unk_67AB8C` / `g_pCurrentBrowserHost` as temporary `Browser *` bridge. The class open question is narrowed to exact source split/linkage; behavior/type/ownership for these globals is no longer a BrowserThread C++ blocker.
- 2026-07-03 B010 UID00032W implementation callback:
  - Summary/evidence: synchronized the first-draft-ready [UID:00032W][0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost](by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md) result. Current MCP session `b010_00032w_20260703` resolves `BrowserThread+0x68` as `Browser *m_browser`, `BrowserThread+0x70` as `RECT m_hostBounds`, wide dispatch slots as `RegisterClassW`/`CreateWindowExW`/`LoadCursorW`, the CRT format helper as `_snwprintf_s`-style glue, and `Browser::Navigate(const wchar_t *)` as a valid final call from host setup. UID00032W now carries formal first-draft C++; only final source-split/member-spelling polish remains open.
- 2026-07-03 B009 UID0002P3 constructor support sync:
  - Score unchanged at `85/88`.
  - Summary/evidence: added implementation-ready support for `BrowserThread::BrowserThread(Browser *browser, const RectBounds &bounds)` and `StartThread()`/the inherited Thread start equivalent consumed by [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md). Current MCP session `b010_00032w_20260703` confirms the old-pane constructor's `0x80` BrowserThread allocation, generic `Thread(true)` construction route, Browser pointer at `+0x68`, host-init byte clear at `+0x6c`, bounds copy to `+0x70`, `g_pBrowserThread` handoff, and `0x005965e0` start/resume call. Thread-file ownership, raw offset source, and handwritten vtable setup are rejected for UID0002P3.
