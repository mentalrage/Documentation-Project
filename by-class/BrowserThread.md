*** UID:00001A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Confidence: strong for browser folder, medium for exact file split

## Methods

- `0x0046eff0` non-deleting destructor.
- `0x0046f010` `RunMessageLoop`.
- `0x0046f1d0` delete-if-present wrapper, currently excluded.
- `0x004706f0` scalar deleting destructor.
- `0x00470a00` `InitializeBrowserHost`.

## Evidence

- Wave3 reports four methods, three active and one excluded vtable-only wrapper.
- IDA MCP confirms the ordinary non-deleting destructor at `0x0046eff0-0x0046f005`; it reinstalls the BrowserThread vtable, clears [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md), and tail-calls `Thread::~Thread`.
- IDA MCP confirms `RunMessageLoop` at `0x0046f010-0x0046f1c8`.
- IDA MCP confirms `InitializeBrowserHost` at `0x00470a00-0x00470dc9`, called from `RunMessageLoop` at `0x0046f044`.
- Generated source and IDA callees show COM/browser setup, `AdviseConnectionPoint`, `UnadviseConnectionPoint`, `PostBrowserNotification`, and navigation through `BrowserWindow`.

## Open Questions

- Final type declarations for [UID:0000QO][g_pCurrentBrowserHost](by-global/g_pCurrentBrowserHost.md), [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md), and [UID:0000PT][g_browserControlKeyCallback](by-global/g_browserControlKeyCallback.md).
- Confirm thread base-class layout and whether the browser thread code should be split from browser UI classes.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:00001B][BrowserWindow](by-class/BrowserWindow.md), [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md), [UID:000014][browser__Notification](by-class/browser__Notification.md)
- Globals/enums: [UID:0000QE][g_pBrowserThread](by-global/g_pBrowserThread.md), [UID:0000QO][g_pCurrentBrowserHost](by-global/g_pCurrentBrowserHost.md), [UID:0000PT][g_browserControlKeyCallback](by-global/g_browserControlKeyCallback.md), [UID:0001SL][BrowserMessageId](by-type/by-enum/BrowserMessageId.md)
- Memory: [UID:000215][0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor](by-memory/0x0046eff0-0x0046f005.BrowserThreadNonDeletingDestructor.md), [UID:0000ZF][0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers.md)

## Changes

- What existed before: the page documented BrowserThread purpose, methods, evidence, and references, but metadata was still `0/0`.
- What it was changed to: scores were set to `72/80`.
- Summary and evidence: destructor, message loop, host initialization, COM setup, and browser notification links are covered; thread base layout and final file split still need reconstruction.
