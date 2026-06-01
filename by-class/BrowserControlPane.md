*** UID:000015 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BrowserControlPane

## Summary

`BrowserControlPane` is the newer embedded browser control pane. It wraps an IE/COM browser window, synchronizes browser window bounds with pane layout, draws browser content/backdrop, handles browser dispatch events, and implements COM interface entry points.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp` or `browser/BrowserControlPane.cpp`
- Confidence: strong for browser folder, medium for exact file split

## Methods

- `0x0046b520` constructor.
- `0x0046b990` destructor.
- `0x0046ba90` `ShutdownBrowserWindow`.
- `0x0046bba0` `SetBrowserActiveState`.
- `0x0046bd30` `NavigateBrowser`.
- `0x0046c0e0` `BlitBrowserWindowToPane`.
- `0x0046c390` `UpdateBrowserBackdrop`.
- `0x0046c4b0` `SyncBrowserWindowBounds`.
- `0x0046c670` `QueryInterface`.
- `0x0046c930-0x0046c950` unsupported interface stubs.
- `0x0046c960` `HandleBrowserDispatchEvent`.
- `0x0046ced0` `HandleBrowserWindowMessage`.
- `0x00470410` scalar deleting destructor.
- `0x00471004-0x00471086` adjustor thunks.

## Evidence

- Wave3 reports 23 methods, 21 active and 2 disabled adjustor thunks.
- IDA MCP confirms constructor at `0x0046b520-0x0046b98e` with callers from `BrowserDialog` and other browser setup paths.
- IDA MCP confirms the constructor calls `AdviseConnectionPoint` and `UnadviseConnectionPoint` helpers.
- IDA MCP confirms `BrowserVariantFromString` is called from the navigation method at `0x0046bdb6`.
- IDA MCP confirms `HandleBrowserDispatchEvent` at `0x0046c960-0x0046caef`; that method owns the strongest evidence for [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md), [UID:0000PP][g_activeBrowserPane](by-global/g_activeBrowserPane.md), and [UID:0000PU][g_browserRuntime](by-global/g_browserRuntime.md) as a browser consumer.
- IDA MCP confirms the constructor writes [UID:0000PO][g_activeBrowserControlPane](by-global/g_activeBrowserControlPane.md) at `0x0067ab28` and destructor/unwind paths clear it. Application and surface/presentation code read the same storage to route browser accelerators and synchronize/redraw the hosted browser HWND.
- IDA MCP shows `QueryInterface` uses [UID:000218][0x004710e0-0x0047110e.BrowserGuidCompareHelper](by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md) for 16-byte COM GUID/IID comparisons.

## Open Questions

- Resolve exact COM interface slots and the `kSlot*InterfaceId` globals before final header work.
- Review whether the old and new control panes were separate original files or one browser source module.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:000017][BrowserDialog](by-class/BrowserDialog.md), [UID:00001B][BrowserWindow](by-class/BrowserWindow.md)
- Globals/enums: [UID:0000T2][IID_BrowserEventSink](by-global/IID_BrowserEventSink.md), [UID:0000PP][g_activeBrowserPane](by-global/g_activeBrowserPane.md), [UID:0000PO][g_activeBrowserControlPane](by-global/g_activeBrowserControlPane.md), [UID:0000QD][g_pBrowserOverlayLayer](by-global/g_pBrowserOverlayLayer.md), [UID:0000PU][g_browserRuntime](by-global/g_browserRuntime.md), [UID:0001SJ][BrowserDispatchEventId](by-type/by-enum/BrowserDispatchEventId.md)
- Memory: [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md), [UID:0000ZF][0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers.md), [UID:000218][0x004710e0-0x0047110e.BrowserGuidCompareHelper](by-memory/0x004710e0-0x0047110e.BrowserGuidCompareHelper.md)

## Changes

- What existed before: the page documented the newer browser control pane, method list, evidence, and references, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `76/82`.
- Summary and evidence: constructor/destructor, COM QueryInterface, dispatch event handling, browser-window synchronization, and active-global usage are documented; exact COM slot typing and final source-file split remain incomplete.
