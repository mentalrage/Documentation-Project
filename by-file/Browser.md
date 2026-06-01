*** UID:0000HV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/browser/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Browser

## Status

- Confidence: strong
- Proposed module: `browser/Browser.cpp` with declarations in `browser/Browser.h`
- Current state: split across many generated Wave3 files in `simroot_v2`
- Evidence basis: local Wave2 class/global JSON, `simroot_v2` `.meta_wave3` files, Wave3 catalog search output, generated source snippets, and follow-up IDA MCP function-boundary checks.

## Hypothesis

The browser subsystem was likely one cohesive source module, or at most a small `browser` folder, rather than the current one-class-per-file layout. The class names, memory locality, shared COM helper functions, browser-specific globals, browser-specific enums, and `browser::Notification` payload all point to one embedded Internet Explorer ActiveX/browser feature.

Process-wide OLE lifetime support is documented separately under [UID:0000HN][AutoInit](by-file/AutoInit.md) and [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md). Browser code is the largest visible COM consumer, but the `0x00419ee0` initializer is a startup-table entry and should not be migrated as browser instance code solely because this module hosts the WebBrowser ActiveX control.

## Current Generated Containers

- `browser/Browser.cpp`
- `class_Browser.cpp`
- `class_BrowserControlPane.cpp`
- `class_BrowserControlPaneOld.cpp`
- `class_BrowserDialog.cpp`
- `class_BrowserDialogOld.cpp`
- `class_BrowserThread.cpp`
- `class_BrowserWindow.cpp`
- `class_browser__Notification.cpp`
- `BrowserVariantFromString_00470170.cpp`
- `AdviseConnectionPoint_004708D0.cpp`
- `UnadviseConnectionPoint_00470980.cpp`
- `PostBrowserNotification_00470F20.cpp`

## Classes

| Class | Current file | Memory range | Notes |
| --- | --- | --- | --- |
| `BrowserWindow` | `browser/Browser.cpp` | `0x00469640-0x004710b7` | Embedded WebBrowser ActiveX host implementing COM client-site/dispatch methods, DocHost UI-handler stubs, accelerator translation, and host WndProc helpers. |
| `BrowserPane` | `browser/Browser.cpp` | `0x0046a860-0x0049dfc3` | UI pane for rendering browser content; notes mention `BCdp`, `BCfl`, and `BCto` command codes. |
| `BrowserDialog` | `class_BrowserDialog.cpp` | `0x0046a8c0-0x0046b51d` | Singleton URL browser dialog opened from keyboard shortcuts and map alert packets; owns BrowserControlPane child creation, close/teardown, and EPF frame helpers. |
| `BrowserDialogOld` | `class_BrowserDialogOld.cpp` | `0x00469290-0x0049db13` | Legacy browser dialog with navigation controls. |
| `BrowserControlPane` | `class_BrowserControlPane.cpp` | `0x0046b520-0x0047108f` | ControlPane wrapper around IE/COM browser window with navigation, event handling, bounds sync, backdrop drawing. |
| `BrowserControlPaneOld` | `class_BrowserControlPaneOld.cpp` | `0x0046f220-0x00528deb` | Legacy control pane wrapping a COM-style `Browser` object and spawning `BrowserThread`. |
| `BrowserThread` | `class_BrowserThread.cpp` | `0x0046eff0-0x00470dc8` | Dedicated thread destructor, COM initialization, private message loop, browser host creation. |
| `Browser` | `class_Browser.cpp` | `0x0046f480-0x00471067` | COM object/event sink implementing IUnknown/client-site/UI-handler/dispatch style slots. |
| `browser__Notification` | `class_browser__Notification.cpp` | `0x00470740-0x00470781` | Browser notification payload destructor/handler. |

## Free Helpers That Should Move Into This Module

| Function | Range | Current file | Reason |
| --- | --- | --- | --- |
| `BrowserVariantFromString` | `0x00470170-0x004701c9` | `BrowserVariantFromString_00470170.cpp` | Shared by `BrowserControlPane::NavigateBrowser` and `BrowserWindow::NavigateBrowser`; constructs a `VT_BSTR` `VARIANT`. |
| `AdviseConnectionPoint` | `0x004708d0-0x00470953` | `AdviseConnectionPoint_004708D0.cpp` | Shared COM connection-point helper used by browser host/control/thread setup. |
| `UnadviseConnectionPoint` | `0x00470980-0x00470a00` | `UnadviseConnectionPoint_00470980.cpp` | Shared cleanup counterpart used by Browser, BrowserWindow, BrowserControlPane, and BrowserThread cleanup. |
| `PostBrowserNotification` | `0x00470f20-0x00470fb9` | `PostBrowserNotification_00470F20.cpp` | Allocates `browser::Notification` and posts on the `'Bros'` notification channel. |
| [UID:000218][0x004710e0-0x0047110e.BrowserGuidCompareHelper](by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md) | `0x004710e0-0x0047110e` | unresolved `sub_4710E0` in active browser output | Shared 16-byte COM GUID/IID equality helper used by BrowserWindow, BrowserControlPane, and Browser `QueryInterface`. |

## Browser-Owned Or Browser-Coupled Data

The browser module has enough data evidence to group the main classes and helper functions, but not every generated browser global is safe to migrate as browser-owned storage. Use the linked pages below as the current ownership authority.

### Browser-Owned Or Strong Browser Candidates

| Entity | Current evidence | Disposition |
| --- | --- | --- |
| [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md) | Win32/private browser messages in `BrowserControlPaneOld` and `BrowserThread`. | Browser enum/private constants. |
| [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md) | Browser COM event DISPIDs in `BrowserControlPane` and `BrowserWindow`. | Browser COM/event constants. |
| [UID:0001SK][BrowserInitFlags](by-type/by-enum/BrowserInitFlags.md) | Legacy `Browser` flag word initialized by `BrowserControlPaneOld`. | Browser-private state constants, final bitmask still open. |
| [UID:0001SM][BrowserOverlayStyle](by-type/by-enum/BrowserOverlayStyle.md) | Status overlay string id/style in `BrowserControlPaneOld`. | Browser UI constants. |
| [UID:0000T2][IID_BrowserEventSink](by-global/IID_BrowserEventSink.md) | Browser COM connection-point/query-interface IID at `0x00631610`. | Browser COM data, neighboring GUIDs still unnamed. |
| [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md) | Legacy browser thread singleton at `0x0067ab88`. | Browser-owned singleton. |
| [UID:0000QO][g_pCurrentBrowserHost](by-global/g_pCurrentBrowserHost.md) | Temporary browser host creation bridge at `0x0067ab8c`. | Browser-owned construction bridge. |
| [UID:0000QB][g_pBrowserDialogOld](by-global/g_pBrowserDialogOld.md) | Legacy browser dialog singleton at `0x0067ab90`. | Browser-owned singleton. |
| [UID:0000Q6][g_pActiveBrowserWindow](by-global/g_pActiveBrowserWindow.md) | Active browser host window pointer, likely `0x0067ab94`. | Browser-owned singleton candidate. |
| [UID:0000PP][g_activeBrowserPane](by-global/g_activeBrowserPane.md) | Browser pane/control callback target at [UID:0001P9][0x0067ab84-0x0067ab88.g_activeBrowserPane](by-memory/0x0067ab84-0x0067ab88.g_activeBrowserPane.md). | Browser candidate, type still under review. |
| [UID:0000PV][g_browserWindowCaption](by-global/g_browserWindowCaption.md) | Browser host/window class string data around `0x00613954-0x006139cc`. | Browser static string data. |
| [UID:0000QC][g_pBrowserFileLoadText](by-global/g_pBrowserFileLoadText.md) | `BrowserPane::OnCommand` file-load/navigation failure alert text at [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md). | Generated alias for browser string literal, not confirmed pointer storage. |
| [UID:0000QF][g_pBrowserTimeoutText](by-global/g_pBrowserTimeoutText.md) | `BrowserPane::OnCommand` timeout alert text at [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md). | Generated alias for browser string literal, not confirmed pointer storage. |
| [UID:0000QD][g_pBrowserOverlayLayer](by-global/g_pBrowserOverlayLayer.md) | Browser control-pane layout/screen mapping alias over [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md). | Browser consumer only; storage is shared UI layout context. |

### Browser-Coupled But Not Safe To Own Yet

| Entity | Current evidence | Disposition |
| --- | --- | --- |
| [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md) / [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) | Derived from `BrowserPane` and construct `BrowserControlPane`, but own board opcode `0x73`, board cookies, and web-board resources. | Browser dependency only; source owner is [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md). |
| [UID:0000SQ][g_pWebBoardDialog](by-global/g_pWebBoardDialog.md) / [UID:0000SR][g_pWebBoardDialogOld](by-global/g_pWebBoardDialogOld.md) | Singleton pointers at `0x0067ab9c` and `0x0067aba0` are browser-control users, but lifetimes are controlled by web-board dialogs. | Keep with web-board source, not generic browser state. |
| [UID:0000PO][g_activeBrowserControlPane](by-global/g_activeBrowserControlPane.md) | [UID:0001P3][0x0067ab28-0x0067ab2c.g_activeBrowserControlPane](by-memory/0x0067ab28-0x0067ab2c.g_activeBrowserControlPane.md) is set/cleared by `BrowserControlPane`; application and presentation paths use it for accelerator handling, active-surface sync, and hosted-window redraw. | Browser-owned active pointer, exposed to cross-module consumers. |
| [UID:0000PT][g_browserControlKeyCallback](by-global/g_browserControlKeyCallback.md) | Browser forwards Tab/Escape through [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md), but IDA shows the storage is called mostly from Socket/transport paths and is written by startup/raw setup code. | Browser consumer only; likely app/transport callback. |
| [UID:0000PU][g_browserRuntime](by-global/g_browserRuntime.md) | Browser dispatch fallback uses [UID:0001OX][0x0067a7cc-0x0067a7d0.g_pScreenPane](by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md) through a generated alias. | Browser consumer only; do not declare as browser-owned storage. |
| `g_browserStatusTextPane` | Appears in generated browser data naming, but current evidence overlaps broad runtime/cursor/status aliases. | Record as data cleanup, not a browser declaration. |
| `dword_67A7CC` alias family | Named as cursor/runtime/status/browser state depending on generated context. | Needs global-data reconciliation before source migration. |

## Why This Should Be Grouped

- The browser classes occupy a dense code neighborhood around `0x00469290-0x004710b7`, with a few older/shared methods elsewhere.
- The COM helper globals are not generic application helpers; their notes explicitly identify browser host/source interfaces and browser event sinks.
- `BrowserThread::InitializeBrowserHost` uses browser-specific globals, browser window class registration, COM initialization, `CLSID_WebBrowser`, browser event connection points, and navigation startup in one flow.
- [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md) is related process-wide OLE support, but its startup-table xref places it outside this browser-owned method cluster.
- `PostBrowserNotification` and `browser__Notification` use a browser-specific notification channel and payload type.
- Current generated filenames are Wave3 default owner containers, not strong original-file evidence.
- IDA MCP confirms the helper boundaries for `BrowserVariantFromString`, `AdviseConnectionPoint`, `UnadviseConnectionPoint`, and `PostBrowserNotification`, and confirms browser callers for each.
- IDA MCP confirms [UID:000215][0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor](by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md) immediately before `RunMessageLoop`; it clears [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md) and delegates to `Thread::~Thread`.
- IDA MCP confirms [UID:000216][0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks](by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md), [UID:000217][0x004710d0-0x004710df.BrowserPanePlaySound](by-memory/0x004710d0-0x004710df.BrowserPanePlaySound.md), and [UID:000218][0x004710e0-0x0047110e.BrowserGuidCompareHelper](by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md) after the original `0x004710b7` aggregate endpoint.
- IDA MCP confirms the `BrowserWindow` post-Invoke neighborhood as browser-owned or browser-adjacent code: DocHost UI-handler vtable stubs at [UID:00020T][0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs](by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md), the active-browser accelerator helper at [UID:00020U][0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage](by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md), and host WndProc code at [UID:00020V][0x0046a630-0x0046a6ea.BrowserWindowHostWndProc](by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md).
- IDA MCP confirms the `BrowserDialog` post-constructor virtual cluster at [UID:00020X][0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals](by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md), including destructor, close/teardown, resized input, frame drawing, and child-rect helpers.
- IDA MCP confirms `BrowserPane::OnCommand` uses direct UTF-16 alert strings at [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md); generated `g_pBrowserFileLoadText` / `g_pBrowserTimeoutText` names are aliases over string literals, not separate recovered pointer globals.
- 2026-05-25 current-state recheck: active `BrowserPane` and `BrowserWindow` output is now in `simroot_v2/browser/Browser.cpp`, and the alert-text aliases appear only as unresolved source identifiers/source-map previews there. No active `global-data` row for `g_pBrowserFileLoadText` or `g_pBrowserTimeoutText` was found in current `simroot_v2`.
- IDA MCP resolves generated `g_pBrowserOverlayLayer` to [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md), which has browser and non-browser UI layout xrefs. Treat it as shared layout context storage, not a browser-owned global.

## Open Questions

- Whether the original project used one `Browser.cpp` file or split into `BrowserWindow.cpp`, `BrowserControlPane.cpp`, and `BrowserDialog.cpp` inside a browser/UI folder.
- Whether `BrowserDialogOld` and `BrowserControlPaneOld` were legacy source kept in the same module or separate compatibility files.
- Whether [UID:0000HN][AutoInit](by-file/AutoInit.md) / [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md) was compiled in a generic platform/OLE source or a browser support source. Runtime evidence only proves process-wide OLE lifetime, not browser ownership.
- Exact declarations for COM interfaces, IID constants, and browser-coupled globals still need type cleanup; `g_activeBrowserControlPane` is a browser-owned active pointer but needs an exported declaration/accessor for application and surface consumers, while `g_browserRuntime` is now treated as a [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md) alias rather than browser-owned storage.

## Proposed Wave3 Migration Batch

Do not run these until reviewed:

```powershell
python E:\NTK\GhidraBridge\source-3\wave3.py create file Browser.cpp --kind source --simpath browser
python E:\NTK\GhidraBridge\source-3\wave3.py attach class BrowserWindow --to-file Browser.cpp
python E:\NTK\GhidraBridge\source-3\wave3.py attach class BrowserPane --to-file Browser.cpp
python E:\NTK\GhidraBridge\source-3\wave3.py attach class BrowserDialog --to-file Browser.cpp
python E:\NTK\GhidraBridge\source-3\wave3.py attach class BrowserControlPane --to-file Browser.cpp
python E:\NTK\GhidraBridge\source-3\wave3.py attach class BrowserThread --to-file Browser.cpp
python E:\NTK\GhidraBridge\source-3\wave3.py attach class Browser --to-file Browser.cpp
python E:\NTK\GhidraBridge\source-3\wave3.py attach class browser__Notification --to-file Browser.cpp
```

Free helper migration needs a reviewed Wave3 global ownership path before applying.

## Cross-References

- [UID:000013][Browser](by-class/Browser.md)
- [UID:00001B][BrowserWindow](by-class/BrowserWindow.md), [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md), [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md), [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- [UID:000215][0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor](by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md), [UID:0000ZF][0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers.md)
- [UID:000216][0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks](by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md), [UID:000217][0x004710d0-0x004710df.BrowserPanePlaySound](by-memory/0x004710d0-0x004710df.BrowserPanePlaySound.md), [UID:000218][0x004710e0-0x0047110e.BrowserGuidCompareHelper](by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md)
- [UID:00020T][0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs](by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md), [UID:00020U][0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage](by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md), [UID:00020V][0x0046a630-0x0046a6ea.BrowserWindowHostWndProc](by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md), [UID:00020W][0x0046a760-0x0046a855.BrowserRawWindowProcClone](by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md)
- [UID:00020X][0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals](by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md)
- [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md)
- [UID:0001OD][0x00613a20-0x00613ab0.BrowserAlertStrings](by-memory/0x00613a20-0x00613ab0.BrowserAlertStrings.md)
- [UID:0001PG][0x0069b374-0x0069b378.g_layoutContext_69B374](by-memory/0x0069b374-0x0069b378.g_layoutContext_69B374.md)
- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- [UID:0000HN][AutoInit](by-file/AutoInit.md)
- [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank even though the page and proposed source tree identify `browser/Browser.cpp` as the current browser subsystem source root.
- What it was changed to: `PROPOSED_RECONSTRUCTION_PATH` is now `NexusTK/browser/`.
- Summary and evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) has a dedicated `browser/Browser.cpp` section, and this page groups the dense browser/OLE class, helper, and global cluster under that same source module. This only stages the `.cpp` root; it does not emit final C++ bodies.

- What existed before: the page had extensive browser subsystem grouping, COM helper, global ownership, and migration evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `84/88`.
- Summary and evidence: class locality, helper boundaries, COM/browser data, and IDA-confirmed neighborhoods make the module highly actionable; remaining work is mostly source split, COM declarations, and browser-coupled global cleanup.
- 2026-05-27: BrowserThread range start.
  - What existed before: The class table treated `BrowserThread` as starting at `0x0046f010`, matching the active generated `RunMessageLoop` entry.
  - What changed: The documented BrowserThread memory range now starts at `0x0046eff0`.
  - Summary/evidence: IDA MCP confirms `sub_46EFF0` at `0x0046eff0-0x0046f005` is the ordinary `BrowserThread` destructor body: it reinstalls the BrowserThread vtable, clears `dword_67AB88` / [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md), and tail-calls `Thread::~Thread`. The scalar deleting destructor at `0x004706f0` repeats the same teardown before applying delete flags.
