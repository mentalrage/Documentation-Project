*** UID:00001B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BrowserWindow

## Summary

`BrowserWindow` is an embedded Internet Explorer ActiveX host. It implements COM client-site and dispatch-style interfaces, creates and manages the hosted browser object, handles reference counting and interface queries, navigates to URLs, and releases the browser object during shutdown.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp` or `browser/BrowserWindow.cpp`
- Confidence: strong for browser folder, medium for exact file split

## Methods

- `0x00469640` constructor - creates and wires the embedded browser control.
- `0x00469a20` destructor.
- `0x00469a90` `ShutdownBrowserWindow`.
- `0x00469b60` `SetBrowserActiveState`.
- `0x00469ca0` `NavigateBrowser`.
- `0x00469f60` `QueryInterface`.
- `0x0046a0b0` `AddRef`.
- `0x0046a0c0` `Release`.
- `0x0046a0d0-0x0046a120` IOleClientSite stubs.
- `0x0046a220-0x0046a39c` IDispatch stubs and Invoke behavior.
- `0x0046a3d0-0x0046a505` DocHost UI-handler and related browser-host callback stubs.
- `0x0046a510-0x0046a617` active browser accelerator translation helper, owner/name still provisional.
- `0x0046a630-0x0046a6ea` browser host window procedure.
- `0x00470dd0` `Navigate`.
- `0x0047102c-0x004710cc` COM interface adjustor thunks, including release-adjustor tail thunks at `0x004710b8` and `0x004710c2`.

## Evidence

- Wave3 reports 25 methods, 22 active and 3 disabled.
- IDA MCP confirms the constructor at `0x00469640-0x00469a17`, with calls to the browser connection-point helpers and navigation setup.
- IDA MCP confirms `Navigate` at `0x00470dd0-0x00470f10` and shows callers from browser setup paths.
- IDA MCP shows `BrowserVariantFromString`, `AdviseConnectionPoint`, and `UnadviseConnectionPoint` are called from this class.
- IDA MCP confirms the BrowserWindow release-adjustor tail thunks at `0x004710b8-0x004710cc`; their vtable refs are `0x006132dc` and `0x00613290`, and both tail-jump to `BrowserWindow::Release`.
- Generated constructor/destructor evidence tracks [UID:0000Q6][g_pActiveBrowserWindow](by-global/g_pActiveBrowserWindow.md), while `Invoke` shares the browser COM event id family with [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md).

## Open Questions

- Finalize COM interface layout and exact vtable offsets before header reconstruction.
- Decide whether `BrowserWindow` was separated from the other browser classes or kept in a single `Browser.cpp`.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md), [UID:00001A][BrowserThread](by-class/BrowserThread.md), [UID:000013][Browser](by-class/Browser.md)
- Globals/enums: [UID:0000Q6][g_pActiveBrowserWindow](by-global/g_pActiveBrowserWindow.md), [UID:0000PV][g_browserWindowCaption](by-global/g_browserWindowCaption.md), [UID:0000T2][IID_BrowserEventSink](by-global/IID_BrowserEventSink.md), [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md)
- Memory: [UID:0000Z4][0x00469640-0x0046a39c.BrowserWindowCore](by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md), [UID:00020T][0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs](by-memory/0x0046a3d0-0x0046a505.BrowserWindowDocHostUiHandlerStubs.md), [UID:00020U][0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage](by-memory/0x0046a510-0x0046a617.BrowserWindowAcceleratorTranslateMessage.md), [UID:00020V][0x0046a630-0x0046a6ea.BrowserWindowHostWndProc](by-memory/0x0046a630-0x0046a6ea.BrowserWindowHostWndProc.md), [UID:00020W][0x0046a760-0x0046a855.BrowserRawWindowProcClone](by-memory/0x0046a760-0x0046a855.BrowserRawWindowProcClone.md), [UID:0000ZF][0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers.md), [UID:000216][0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks](by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md), [UID:000218][0x004710e0-0x0047110e.BrowserGuidCompareHelper](by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md)

## Changes

- Before: the memory cross-reference pointed to `0x00469640-0x0046a39b.BrowserWindowCore`, and the method list stopped the IDispatch/Invoke area at the start of `0x0046a250`.
- Changed to: the memory cross-reference now points to `0x00469640-0x0046a39c.BrowserWindowCore`, and the newly documented `0x0046a3d0-0x0046a855` browser-adjacent method/table cluster is linked from this class page.
- Summary/evidence: IDA MCP confirms `sub_46A250` ends at `0x0046a39c`, `0x0046a3d0-0x0046a505` is referenced by BrowserWindow vtable slices, `0x0046a630` is referenced from the BrowserWindow constructor, and `0x0046a760-0x0046a855` is a raw WndProc-like browser-adjacent body with no current IDA function record.

- Before: the COM adjustor-thunk list stopped at `0x004710ae`, matching the earlier browser/OLE aggregate endpoint.
- Changed to: the adjustor-thunk list now includes `0x004710b8` and `0x004710c2` through [UID:000216][0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks](by-memory/0x004710b8-0x004710cc.BrowserWindowReleaseAdjustorTailThunks.md).
- Summary/evidence: IDA MCP confirms both thunks are vtable-referenced BrowserWindow interface slices that subtract `0x10` or `0x0c` from the interface pointer and tail-jump to `BrowserWindow::Release` at `0x0046a0c0`.

- What existed before: the page had detailed browser-host evidence and previous range/thunk changes, but metadata still read `0/0`.
- What it was changed to: scores were set to `78/82`.
- Summary and evidence: constructor/destructor, browser object creation, COM interface methods, navigation, host window procedure, adjustor thunks, globals, and memory references are documented; exact COM layout and final source split remain open.
