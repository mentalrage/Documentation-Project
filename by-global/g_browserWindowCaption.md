*** UID:0000PV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_browserWindowCaption

## Status

- Confidence: strong for browser window-title/string role.
- Current Wave3 kind: `global-data`
- Current generated owner file: `class_BrowserThread.cpp`
- IDA string candidate: `0x00613970` (`"Baram.Browser.Window"`)
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md)

## Observed Evidence

`BrowserThread::InitializeBrowserHost` creates the browser host window with a browser-specific caption string. IDA string search identifies `0x00613970` as `"Baram.Browser.Window"`, and xrefs show it is referenced by `BrowserWindow` construction at `0x0046972a`.

The same string neighborhood contains browser class/window-name data, including `%s.%s.Browser` at `0x00613954` and `Nexon.Baram.Browser` at `0x006139cc`.

## Ownership Hypothesis

This is browser module static string data. Keep it with the browser host/window creation code.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- [UID:00001B][BrowserWindow](by-class/BrowserWindow.md)
- [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `76/84`. Summary/evidence: the page documents the browser caption string, string address, xref into browser window construction, neighboring browser strings, and ownership refs; the scope is narrow, so completion is capped below deeper subsystem pages.
