*** UID:00001A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

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
| [UID:00032Q][0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop](by-memory/0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop.md) | `RunMessageLoop` | Initializes the browser host, runs the private `GetMessageA` loop, forwards Tab/Escape-style input, posts browser notifications, and tears down COM. |
| [UID:00032R][0x0046f1d0-0x0046f1db.BrowserThreadDeleteIfPresentWrapper](by-memory/0x0046f1d0-0x0046f1db.BrowserThreadDeleteIfPresentWrapper.md) | delete-if-present wrapper | Vtable-only non-emitting wrapper slot; source reconstruction should express the real destructor behavior rather than port this helper literally. |
| [UID:00032V][0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor](by-memory/0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor.md) | scalar deleting destructor | Repeats the BrowserThread singleton clear/base teardown path and applies delete flags. |
| [UID:00032W][0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost](by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md) | `InitializeBrowserHost` | Registers/creates the browser host window, bridges the pending host through `g_pCurrentBrowserHost`, initializes COM, creates the WebBrowser object, advises browser events, and handles cleanup. |

## Evidence

- Live IDA MCP recheck on 2026-06-04 used `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, image base `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.
- IDA confirms the ordinary destructor at `0x0046eff0-0x0046f005`; it refs BrowserThread vtable `0x00613744`, clears [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md) at `0x0046eff6`, and sits between `0xcc` padding at `0x0046efec-0x0046eff0` and `0x0046f005-0x0046f010`.
- IDA confirms `RunMessageLoop` at `0x0046f010-0x0046f1c8`, with the BrowserThread vtable slot at `0x00613760` and a direct call to `InitializeBrowserHost` at `0x0046f044`.
- The message loop calls `GetMessageA`, `GetAsyncKeyState`, `TranslateMessage`, `RedrawWindow`, `ShowWindow`, `SetFocus`, `CoUninitialize`, and [UID:000014][browser__Notification](by-class/browser__Notification.md) posting helper `0x00470f20` at `0x0046f15d`.
- The message loop reads the browser key callback/storage at `0x0069bec4` from `0x0046f0e6` and uses browser/window globals including `dword_67AB1C`, `dword_69BE90`, and `dword_69BE64`.
- IDA confirms vtable-only wrapper `0x0046f1d0-0x0046f1db` from slot `0x00613764`; it stays documented but is not source behavior to hand-port.
- IDA confirms scalar deleting destructor `0x004706f0-0x0047073b` from slot `0x00613744`; it refs BrowserThread vtable `0x00613744`, clears `g_pBrowserThread` at `0x004706fc`, calls the base-thread destructor path `0x00596400`, and applies delete flags.
- IDA confirms `InitializeBrowserHost` at `0x00470a00-0x00470dc9`, called only from `RunMessageLoop`; it writes/clears [UID:0000QO][g_pCurrentBrowserHost](by-global/g_pCurrentBrowserHost.md) at `0x00470b3c` and `0x00470be3`.
- Host initialization calls the browser/window helpers at `0x00465b70`, `0x00465b90`, `0x00471110`, and `0x004651c0`; Win32/OLE APIs include `GetStockObject`, `InvalidateRect`, `SetWindowLongA`, `CoInitialize`, `CoCreateInstance`, `SetRect`, `CoUninitialize`, and `DestroyWindow`.
- Host initialization refs browser COM GUID data at `0x006315a0`, `0x00631620`, `0x00631600`, `0x00631610`, and `0x006315d0`, calls `AdviseConnectionPoint` at `0x00470cc3`, calls `UnadviseConnectionPoint` at `0x00470d69`, and calls navigation/cleanup helper `0x00470dd0` at `0x00470d92`.
- `g_pBrowserThread` xrefs now map constructor storage from [UID:0002P3][0x0046ff50-0x00470159.BrowserControlPaneOldConstructor](by-memory/0x0046ff50-0x00470159.BrowserControlPaneOldConstructor.md) at `0x004700ef`/`0x004700f6`, destructor clears at `0x0046eff6` and `0x004706fc`, and legacy Browser/BrowserDialogOld reads around `0x004694c0-0x00469620` and `0x0046f810`.
- BrowserThread vtable `0x00613744` has direct refs from the ordinary destructor `0x0046eff0`, the old control-pane constructor `0x00470103`, and the scalar deleting destructor `0x004706f6`.
- 2026-06-10 B001-024 live IDA MCP rechecked the in-aggregate exact children while splitting [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md): `RunMessageLoop` `0x0046f010-0x0046f1c8` has vtable ref `0x00613760`, `DeleteIfPresent` wrapper `0x0046f1d0-0x0046f1db` has vtable ref `0x00613764`, scalar deleting destructor `0x004706f0-0x0047073b` has vtable ref `0x00613744` and clears `g_pBrowserThread`, and `InitializeBrowserHost` `0x00470a00-0x00470dc9` is called only from `RunMessageLoop`.

## Open Questions

- Final declarations for [UID:0000QO][g_pCurrentBrowserHost](by-global/g_pCurrentBrowserHost.md), [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md), and the browser key-callback consumer path.
- Finalize the `Thread` base-class layout, BrowserThread field names, and whether the original source split kept this code in `Browser.cpp` or a separate `BrowserThread.cpp`.
- Name the browser host/window helper calls around `0x00465b70`, `0x00465b90`, `0x00471110`, and `0x004651c0` before writing C++.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:00001B][BrowserWindow](by-class/BrowserWindow.md), [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md), [UID:000014][browser__Notification](by-class/browser__Notification.md)
- Globals/enums: [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md), [UID:0000QO][g_pCurrentBrowserHost](by-global/g_pCurrentBrowserHost.md), [UID:0000PT][g_browserControlKeyCallback](by-global/g_browserControlKeyCallback.md), [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md)
- Memory: [UID:000215][0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor](by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md), [UID:00032Q][0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop](by-memory/0x0046f010-0x0046f1c8.BrowserThreadRunMessageLoop.md), [UID:00032R][0x0046f1d0-0x0046f1db.BrowserThreadDeleteIfPresentWrapper](by-memory/0x0046f1d0-0x0046f1db.BrowserThreadDeleteIfPresentWrapper.md), [UID:00032V][0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor](by-memory/0x004706f0-0x0047073b.BrowserThreadScalarDeletingDestructor.md), [UID:00032W][0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost](by-memory/0x00470a00-0x00470dc9.BrowserThreadInitializeBrowserHost.md), [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md)

## Changes

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
