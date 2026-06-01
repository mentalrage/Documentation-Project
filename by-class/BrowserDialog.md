*** UID:000017 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BrowserDialog

## Summary

`BrowserDialog` is the singleton URL browser dialog used by the newer browser-control path. It owns a title area and an embedded `BrowserControlPane`, and forwards URL navigation into an already-open browser pane.

## Likely Original Placement

- Source: [UID:0000HV][Browser](by-file/Browser.md)
- Proposed path: `browser/Browser.cpp` or `browser/BrowserDialog.cpp`
- Confidence: strong for browser folder, medium for exact file split

## Methods

- `0x0046a8c0` `NavigateToUrl` - forwards a URL into the embedded control pane if the dialog is open.
- `0x0046aa40-0x0046ad0a` constructor - creates the singleton dialog, title pane, and embedded browser pane.
- `0x0046ad10-0x0046b51d` destructor and virtual helpers - clears the singleton, handles close/teardown, resized input, EPF frame/chrome drawing, and child control rectangles.

## Evidence

- Wave3 records this as restored from a stale `UserPaneTable_46AA40` projection, with singleton global `0x0067AB98`.
- IDA MCP confirms `NavigateToUrl` at `0x0046a8c0-0x0046a8d7`.
- IDA MCP confirms constructor at `0x0046aa40-0x0046ad0a`, with callers at `0x00513ebe` and `0x005a7079`.
- IDA MCP shows the constructor calls `BrowserControlPane::BrowserControlPane` at `0x0046b520`.
- IDA MCP confirms the adjacent `0x0046ad10-0x0046b51d` virtual-method cluster is tied to BrowserDialog vtable entries around `0x006133e0-0x00613414`.

## Open Questions

- Type the singleton global currently named `dword_67AB98`.
- Determine whether the stale class projection has left any wrong source-line ownership in Wave3.

## Cross-References

- File: [UID:0000HV][Browser](by-file/Browser.md)
- Related classes: [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md), [UID:000019][BrowserPane](by-class/BrowserPane.md)
- Memory: [UID:0000Z5][0x0046a860-0x0046ad0a.BrowserPaneAndDialog](by-memory/0x0046a860-0x0046ad0a.BrowserPaneAndDialog.md), [UID:00020X][0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals](by-memory/0x0046ad10-0x0046b51d.BrowserDialogPaneVirtuals.md)

## Changes

- Before: this page only listed `NavigateToUrl` and the constructor, and its memory reference pointed at a range ending in `0x0046ad09`.
- Changed to: the constructor endpoint is now `0x0046ad0a`, and the adjacent destructor/virtual helper cluster at `0x0046ad10-0x0046b51d` is included.
- Summary/evidence: IDA MCP reports `sub_46AA40` ends at `0x0046ad0a`, and vtable xrefs place `sub_46AD40`, `sub_46AD80`, `sub_46AEB0`, `sub_46B030`, and `sub_46B0D0` in the BrowserDialog vtable region.

- What existed before: the page had browser-dialog evidence and prior range corrections, but completion/confidence metadata still read `0/0`.
- What it was changed to: scores were set to `72/80`.
- Summary and evidence: constructor, singleton behavior, BrowserControlPane ownership, and vtable-neighboring virtuals are documented; singleton typing and final source split remain open.
