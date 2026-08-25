*** UID:0000PV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_browserWindowClassName

## Status

- Confidence: strong for browser host window-class string role.
- IDA string candidate: `0x00613970` (`"Baram.Browser.Window"`)
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md)
- Owner/emitter route: [UID:0000HV][Browser](by-file/Browser.md)
- Rebuild handling: source-authored narrow browser window-class string literal; concrete address is binary layout, not source API.

## Observed Evidence

`BrowserThread::InitializeBrowserHost` and the browser host-window setup path create the browser host window with a browser-specific class name. IDA string search identifies `0x00613970` as `"Baram.Browser.Window"`, and xrefs show it is referenced by `BrowserWindow` construction at `0x0046972a`.

The same string neighborhood contains browser class/window-name data, including `%s.%s.Browser` at `0x00613954` and `Nexon.Baram.Browser` at `0x006139cc`.
IDA MCP recheck on 2026-06-14 confirmed a single direct xref to `0x00613970` from browser window construction at `0x0046972a` inside `sub_469640`.

Live IDA MCP decompilation of `0x00469640` shows the string passed to `sub_443A00(ClassName, 0x100, "Baram.Browser.Window", ...)`, then `ClassName` is assigned to `WNDCLASSA.lpszClassName`, passed to `RegisterClassA`, and reused as the `CreateWindowExA` class-name argument. The `CreateWindowExA` window-name/caption argument in that decompilation is a separate `Locale` symbol, so the previous `g_browserWindowCaption` identity is rejected.

`get_string 0x00613970` returns `"Baram.Browser.Window"`. `get_bytes 0x00613970 size 22` returns the 20-character ASCII string (`20 == 0x14`, verified with `int_convert.py`) followed by NUL bytes; `22 == 0x16` was also verified with `int_convert.py`. `analyze_function 0x00469640` reports size `0x3d7`, one caller (`sub_580870`), the string use, and Win32/OLE callees including `RegisterClassA`, `CreateWindowExA`, `SetWindowLongA`, `CoCreateInstance`, and `MultiByteToWideChar`.

[UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md) records this string inside the browser static data region:

| Address | String | Role |
| --- | --- | --- |
| `0x00613954` | `"%s.%s.Browser"` | Browser host window-class format string. |
| `0x00613970` | `"Baram.Browser.Window"` | Browser host window-class string documented here. |
| `0x00613988` | `"%s=%s"` | Browser formatting literal used by document-property helpers. |
| `0x006139cc` | `"Nexon.Baram.Browser"` | Browser control window-class string. |

[UID:0000Z4][0x00469640-0x0046a39c.BrowserWindowCore](by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md) covers the constructor/core range containing the `0x0046972a` xref. That page documents the constructor as creating the host window, creating the browser COM object, wiring connection helpers, storing the active browser-window global, converting the initial URL, and calling the navigation body.

[UID:0000HV][Browser](by-file/Browser.md) treats this as browser-owned static data alongside browser window/control/thread classes, COM helpers, browser-specific globals, and string literals. It is not a standalone process global in source; it should become a browser module literal or file-local constant.

## Ownership Hypothesis

This is browser module static string data. Keep it with the browser host/window creation code in `browser/Browser.cpp` or a future browser-window split file. Do not move it to generic platform/windowing code just because it is passed to `RegisterClassA` and `CreateWindowExA`.

## Score Rationale

- Completion `85`: the page now records the exact string address, byte/string decode, single constructor xref, decompiled class-registration use, neighboring browser strings, owner/emitter route, and rejected caption interpretation.
- Confidence `90`: live IDA MCP on 2026-06-14 corroborates the string bytes, xref site, BrowserWindow constructor size/callees, and class-name data flow. Confidence stays below final-audit because the exact source declaration style and Browser.cpp versus BrowserWindow.cpp split remain open.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- [UID:00001B][BrowserWindow](by-class/BrowserWindow.md)
- [UID:0000Z4][0x00469640-0x0046a39c.BrowserWindowCore](by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md)
- [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md)

## Changes

- 2026-06-14: Renamed `g_browserWindowCaption` to `g_browserWindowClassName` and raised completion/confidence from `84/88` to `85/90`.
  - Before: the page treated `0x00613970` as a browser window caption/title string.
  - After: live IDA MCP decompilation shows `"Baram.Browser.Window"` flows through `sub_443A00` into the local `ClassName` buffer, `WNDCLASSA.lpszClassName`, `RegisterClassA`, and the `CreateWindowExA` class-name parameter. The actual `CreateWindowExA` caption argument is a separate `Locale` symbol.
  - Evidence: `get_string` and `get_bytes` confirm the narrow string at `0x00613970`; `xrefs_to` confirms one xref at `0x0046972a` inside `sub_469640`; `analyze_function 0x00469640` confirms the browser constructor's Win32/OLE call set and string use. Final C++ remains blank because the page clears the minimum score/emitter gate but the exact source declaration style and browser source split are not source-quality yet.

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `76/84`. Summary/evidence: the page documents the browser string, string address, xref into browser window construction, neighboring browser strings, and ownership refs; the scope is narrow, so completion is capped below deeper subsystem pages.
- 2026-06-05: Marked reconstructable and attached to [UID:0000HV][Browser](by-file/Browser.md).
  - Reason: live IDA MCP recheck confirms this source-declared browser window string is referenced by browser window construction and belongs with the browser module.
- 2026-06-06: Raised completion/confidence to `84/88` from existing IDA-backed browser data pages.
  - What existed before: the page named the string and owner but did not tie it to the full browser static-data aggregate, exact constructor/core page, neighboring browser literals, or the source-rebuild disposition.
  - Changed to: added the browser string-neighborhood table, BrowserWindow core reference, source-authored literal handling, and explicit source-placement caveat.
  - Summary/evidence: [UID:0001OB][0x006131b4-0x006139df.BrowserVtablesAndStrings](by-memory/0x006131b4-0x006139df.BrowserVtablesAndStrings.md) records the surrounding browser string region, while [UID:0000Z4][0x00469640-0x0046a39c.BrowserWindowCore](by-memory/0x00469640-0x0046a39c.BrowserWindowCore.md) records the constructor/core range that contains the single direct xref. Live MCP was unavailable during this pass, so no score exceeds the conservative below-95 audit threshold and no C++ declaration was emitted.
