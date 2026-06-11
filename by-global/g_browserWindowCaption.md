*** UID:0000PV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_browserWindowCaption

## Status

- Confidence: strong for browser window-title/string role.
- IDA string candidate: `0x00613970` (`"Baram.Browser.Window"`)
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md)
- Rebuild handling: source-authored browser string literal; concrete address is binary layout, not source API.

## Observed Evidence

`BrowserThread::InitializeBrowserHost` and the browser host-window setup path create the browser host window with a browser-specific caption string. IDA string search identifies `0x00613970` as `"Baram.Browser.Window"`, and xrefs show it is referenced by `BrowserWindow` construction at `0x0046972a`.

The same string neighborhood contains browser class/window-name data, including `%s.%s.Browser` at `0x00613954` and `Nexon.Baram.Browser` at `0x006139cc`.
IDA MCP recheck on 2026-06-05 confirmed a single direct xref to `0x00613970` from browser window construction at `0x0046972a` inside `sub_469640`.

[UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md) records this string inside the browser static data region:

| Address | String | Role |
| --- | --- | --- |
| `0x00613954` | `"%s.%s.Browser"` | Browser host window-class format string. |
| `0x00613970` | `"Baram.Browser.Window"` | Browser host/window caption string documented here. |
| `0x00613988` | `"%s=%s"` | Browser formatting literal used by document-property helpers. |
| `0x006139cc` | `"Nexon.Baram.Browser"` | Browser control window-class string. |

[UID:0000Z4][0x00469640-0x0046a39c.BrowserWindowCore](by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md) covers the constructor/core range containing the `0x0046972a` xref. That page documents the constructor as creating the host window, creating the browser COM object, wiring connection helpers, storing the active browser-window global, converting the initial URL, and calling the navigation body.

[UID:0000HV][Browser](by-file/Browser.md) treats this as browser-owned static data alongside browser window/control/thread classes, COM helpers, browser-specific globals, and string literals. It is not a standalone process global in source; it should become a browser module literal or file-local constant.

## Ownership Hypothesis

This is browser module static string data. Keep it with the browser host/window creation code in `browser/Browser.cpp` or a future browser-window split file. Do not move it to generic platform/windowing code just because it is passed to a Win32 window-creation API.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- [UID:00001B][BrowserWindow](by-class/BrowserWindow.md)
- [UID:0000Z4][0x00469640-0x0046a39c.BrowserWindowCore](by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md)
- [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `76/84`. Summary/evidence: the page documents the browser caption string, string address, xref into browser window construction, neighboring browser strings, and ownership refs; the scope is narrow, so completion is capped below deeper subsystem pages.
- 2026-06-05: Marked reconstructable and attached to [UID:0000HV][Browser](by-file/Browser.md).
  - Reason: live IDA MCP recheck confirms this source-declared browser window caption string is referenced by browser window construction and belongs with the browser module.
- 2026-06-06: Raised completion/confidence to `84/88` from existing IDA-backed browser data pages.
  - What existed before: the page named the string and owner but did not tie it to the full browser static-data aggregate, exact constructor/core page, neighboring browser literals, or the source-rebuild disposition.
  - Changed to: added the browser string-neighborhood table, BrowserWindow core reference, source-authored literal handling, and explicit source-placement caveat.
  - Summary/evidence: [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md) records the surrounding browser string region, while [UID:0000Z4][0x00469640-0x0046a39c.BrowserWindowCore](by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md) records the constructor/core range that contains the single direct xref. Live MCP was unavailable during this pass, so no score exceeds the conservative below-95 audit threshold and no C++ declaration was emitted.
