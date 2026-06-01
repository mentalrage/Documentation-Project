*** UID:0001SJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BrowserDispatchEventId

## Status

- Confidence: strong for observed DISPIDs, medium for final enum name.
- Current source evidence: IDA MCP decompilation of `BrowserControlPane::HandleBrowserDispatchEvent` and `BrowserWindow::Invoke`; generated source names are lead material only.
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md), likely `browser/Browser.h`.
- Reconstructable: yes, as browser COM event constants. Leave autogen parent/code blank until the browser header split and final enum spelling are proven.

## Values

| Value | Name hypothesis | Meaning |
| --- | --- | --- |
| `104` | `kDispIdNoOp` | Accepted no-op event in the newer control pane dispatch handler. |
| `250` | `kDispIdBeforeNavigate` | `BeforeNavigate2` style event; checks close/resource URLs and allowed HTTP prefix. |
| `251` | `kDispIdNavigateComplete` | Navigation-complete gate; may cancel when the browser is not in the allowed state. |
| `252` | `kDispIdNavigationCookie` | Captures the top-level navigation token/cookie. |
| `259` | `kDispIdDocumentComplete` | Document-complete event; clears navigation token and activates pane/browser state. |
| `263` | `kDispIdNewWindow` | New-window event; cancels or redirects behavior through the browser pane callback path. |
| `270` | `kDispIdWindowClosing` | Window-closing event; sets cancel flag. |

## Evidence

- IDA MCP confirms `BrowserControlPane::HandleBrowserDispatchEvent` at `0x0046c960-0x0046caef` and decompiles `switch (a2)` with cases `104`, `250`, `251`, `252`, `259`, `263`, and `270`.
- IDA MCP confirms `BrowserWindow::Invoke` at `0x0046a250` handles the same `250`, `251`, `252`, `259`, `263`, and `270` browser-event family in the older host path.
- In `0x0046c960`, case `250` reads the navigation URL from the dispatch parameter block, rejects `javascript:`/close-style and `res:` prefixes, and enforces the allowed `http://` prefix gate when a host prefix is configured.
- In both paths, case `252` stores the navigation cookie/token at object offset `+548` when empty, and case `259` later compares and clears that token before activating the pane/browser state.
- Cases `263` and `270` write through the cancel pointer in the dispatch parameter block, matching new-window/window-closing cancellation semantics.

## Placement

These constants belong with the browser COM/event-sink declarations, not with generic UI event dispatch and not with socket protocol constants.

## Open Questions

- Final source spelling is not proven. The numeric DISPIDs are strong, but the original names may have matched Microsoft WebBrowser event names instead of the current `kDispId...` hypotheses.
- The old and new browser hosts share most values, but case `104` is only confirmed in the newer `BrowserControlPane` handler in the current checks.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)
- [UID:00001B][BrowserWindow](by-class/BrowserWindow.md)
- [UID:0000ZF][0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers.md)
