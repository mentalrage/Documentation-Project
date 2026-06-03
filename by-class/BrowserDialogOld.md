*** UID:000018 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BrowserDialogOld

## Summary

`BrowserDialogOld` is the legacy web browser dialog with navigation controls and a legacy `BrowserControlPaneOld` child. It handles keyboard close behavior, mouse bounds checks, navigation message posting, child rectangle layout, and dialog bounds state.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp`
- Confidence: strong for browser folder, medium for exact file split
- Autogen parent: [UID:0000HV][Browser](by-file/Browser.md). C++ is intentionally blank because the old-path source split, exact header placement, and legacy lifetime model are not final-source quality.

## Methods

- `0x00469290` constructor.
- `0x00469430` destructor.
- `0x00469530` `OnKeyEvent`.
- `0x004695b0` `OnMouseEvent`.
- `0x00469620` `OnNavigateAction`.
- `0x0046b4b0` `GetChildRect`.
- `0x004705e0` scalar deleting destructor.
- `0x0049dae0` `SetDialogBounds`.

## Evidence

- Wave3 reports 10 methods, 8 active and 2 adjustor thunks.
- IDA MCP confirms constructor at `0x00469290-0x00469426`.
- IDA MCP shows the constructor calls `BrowserControlPaneOld::BrowserControlPaneOld` at `0x0046ff50`.
- IDA MCP confirms the far `SetDialogBounds` helper at `0x0049dae0-0x0049db14`.
- Generated constructor/destructor evidence tracks [UID:0000QB][g_pBrowserDialogOld](by-global/g_pBrowserDialogOld.md) as the legacy browser dialog singleton.
- [UID:0000HV][Browser](by-file/Browser.md) is scored `84/88`, assigned to `NexusTK/browser/`, and groups `BrowserDialogOld`, `BrowserControlPaneOld`, `BrowserThread`, browser COM helpers, browser-specific globals, and the legacy/new browser control family under the browser module.
- [UID:0000Z3][0x00469290-0x0046963c.BrowserDialogOldCore](by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md) is scored `70/85` and records the corrected constructor/destructor/key/mouse/navigate boundaries, constructor call into `BrowserControlPaneOld`, singleton global, and browser-module ownership.
- [UID:0000QB][g_pBrowserDialogOld](by-global/g_pBrowserDialogOld.md) documents the legacy browser dialog singleton role and ownership hypothesis with this dialog/control path.

## Open Questions

- Decide whether "Old" browser classes were retained source files or dead legacy paths still linked into the client.
- Confirm non-dialog callers of [UID:0000QB][g_pBrowserDialogOld](by-global/g_pBrowserDialogOld.md), if any, before final header placement.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md), [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- Globals: [UID:0000QB][g_pBrowserDialogOld](by-global/g_pBrowserDialogOld.md)
- Memory: [UID:0000Z3][0x00469290-0x0046963c.BrowserDialogOldCore](by-memory/0x00469290-0x0046963c.BrowserDialogOldCore.md), [UID:00012S][0x0049dae0-0x0049dfc4.DialogControlPaneHelpers](by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md)

## Changes

- What existed before: the legacy dialog page documented role, methods, evidence, globals, and references, but completion/confidence metadata was `0/0`.
- What it was changed to: scores were set to `68/78`.
- Summary and evidence: constructor, old control-pane construction, singleton global, and bounds helper are covered; old-path reachability and final file/header placement remain unresolved.
- 2026-06-03 parent attachment pass:
  - What existed before: the page was reconstructable in substance but had blank autogen metadata and remained in the low-completion/low-both tables at `68/78`.
  - Changed to: `COMPLETION:72`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000HV][Browser](by-file/Browser.md).
  - Summary/evidence: the Browser file doc, exact old-dialog core memory page, `BrowserControlPaneOld` constructor linkage, and singleton global page support browser-module source ownership. C++ remains blank because old-path reachability, final file/header split, and legacy lifetime details are below the 95+ reconstruction gate.
