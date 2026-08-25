*** UID:0001SJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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

# BrowserDispatchEventId

## Status

- Confidence: strong for observed DISPIDs, medium for final enum name.
- Current source evidence: IDA MCP decompilation of `BrowserControlPane::HandleBrowserDispatchEvent` and `BrowserWindow::Invoke`; generated source names are lead material only.
- Assigned owner: [UID:0000HV][Browser](by-file/Browser.md), likely `browser/Browser.h`.
- Reconstructable: yes, as browser COM event constants. Leave C++ blank until the browser header split and final enum spelling are proven.

## Assignment Gate

- Child score after Batch 097: `86/90`.
- Direct parent: [UID:0000HV][Browser](by-file/Browser.md), already `86/88`.
- Assignment decision: assign to [UID:0000HV][Browser](by-file/Browser.md). The constants are browser COM/WebBrowser event DISPIDs shared by the new `BrowserControlPane` dispatch handler and the older `BrowserWindow::Invoke` path, so they belong with browser event declarations rather than with generic UI events or network protocol constants.

## Values

| Value | Name hypothesis | Meaning |
| --- | --- | --- |
| `104` | `kDispIdDownloadComplete` / legacy visibility-complete style event | Accepted no-op event in the newer control pane dispatch handler; in legacy [UID:000013][Browser](by-class/Browser.md) `Invoke`, decrements `m_pendingDownloadCount` and may show/update the hosted browser window when `m_showBrowserAfterLoad` is set. |
| `106` | `kDispIdDownloadBegin` / pending-load increment style event | Confirmed in legacy `Browser::Invoke`; increments `m_pendingDownloadCount`. Not yet confirmed in the newer control-pane handler. |
| `250` | `kDispIdBeforeNavigate2` | `BeforeNavigate2` style event; checks close/resource URLs and allowed HTTP prefix. |
| `251` | `kDispIdNavigateComplete2` | Navigation-complete gate; may cancel when the browser is not in the allowed state. |
| `252` | `kDispIdNavigationCookie` | Captures the top-level navigation token/cookie. |
| `259` | `kDispIdDocumentComplete` | Document-complete event; clears navigation token and activates pane/browser state. |
| `263` | `kDispIdNewWindow2` | New-window/current-URL notification style event; cancels or redirects behavior through the browser pane callback path. |
| `270` | `kDispIdWindowClosing` | Window-closing event; sets cancel flag. |

## Evidence

- IDA MCP confirms `BrowserControlPane::HandleBrowserDispatchEvent` at `0x0046c960-0x0046caef` and decompiles `switch (a2)` with cases `104`, `250`, `251`, `252`, `259`, `263`, and `270`.
- IDA MCP confirms `BrowserWindow::Invoke` at `0x0046a250` handles the same `250`, `251`, `252`, `259`, `263`, and `270` browser-event family in the older host path.
- In `0x0046c960`, case `250` reads the navigation URL from the dispatch parameter block, rejects `javascript:`/close-style and `res:` prefixes, and enforces the allowed `http://` prefix gate when a host prefix is configured.
- In both paths, case `252` stores the navigation cookie/token at object offset `+548` when empty, and case `259` later compares and clears that token before activating the pane/browser state.
- Cases `263` and `270` write through the cancel pointer in the dispatch parameter block, matching new-window/window-closing cancellation semantics.
- [UID:000331][0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable](by-memory/0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md) documents the legacy [UID:000013][Browser](by-class/Browser.md) `Invoke` dispatch map. In that old event sink, `104` is a `DownloadComplete`/visibility-complete style event, `106` is a `DownloadBegin`/pending-count increment style event, `250` is a `BeforeNavigate2`-style route that can post private browser message `0x500`, `251` is a navigation-complete style guard, `263` is a new-window/current-URL notification style event, and `270` is a window-closing style event.

## Batch 097 IDA Recheck

- 2026-06-07 IDA MCP checked `NexusTK.exe` md5 `4247e04e20b65d6414c7238aa8ff5515`.
- Function lookup confirms `0x0046c960-0x0046caf0` for the newer control-pane event handler and `0x0046a250-0x0046a39c` for the older browser-window `Invoke` handler.
- The newer handler accepts case `104`, handles `250`, `251`, `252`, `259`, `263`, and `270`, and falls back to `DISP_E_MEMBERNOTFOUND` for unknown DISPIDs after clearing browser runtime state through the shared screen/browser callback path.
- Case `250` performs URL-prefix checks and cancel-pointer writes; cases `252` and `259` implement the navigation-token store/compare/clear flow; cases `263` and `270` control new-window/window-closing cancellation.
- The older handler overlaps on `250`, `251`, `252`, `259`, `263`, and `270`, confirming this is a browser-host event-id family and not an implementation-local switch.

## 2026-06-21 BrowserControlPane Invoke Refinement

B010 source-quality reanalysis of [UID:0000Z6][0x0046b520-0x0046cfe0.BrowserControlPaneCore](by-memory/0x0046b520-0x0046cfe0.BrowserControlPaneCore.md) resolves the newer `BrowserControlPane::Invoke` behavior more tightly:

| Value | Refined newer-control behavior |
| ---: | --- |
| `104` | Accepted no-op, returns `S_OK`. |
| `250` | `BeforeNavigate2`-style URL gate. Reads the URL string from the event argument VARIANT, closes/cancels for internal close/resource prefixes including `javascript:close();`, `res://`, and the adjacent wide close-script, and enforces `m_allowedUrlPrefix` when the URL starts with `http://`. Cancellation writes `1` through the event cancel pointer. |
| `251` | Navigate-complete-like gate. If `m_cancelNavigateComplete` is nonzero, returns without cancellation; otherwise falls through to the `270` cancel behavior. |
| `252` | Stores the first top-level navigation dispatch cookie/token into `m_topLevelNavigationDispatchCookie` if it is empty. |
| `259` | `DocumentComplete`-style path. Compares the event dispatch cookie with the stored cookie, clears it on match, notifies `g_activeBrowserPane` with command/tag `0x4243746f`, and if `m_deferShowUntilDocumentComplete` is set, clears it and calls `SetBrowserActiveState(m_browserActiveState)`. |
| `263` | New-window-like event. Writes cancel `0`, calls `sub_49df20(g_activeBrowserPane)`, and returns `S_OK`. |
| `270` | Window-closing-like event. Writes cancel `1`. |
| default | Writes `0` to `g_pScreenPane/dword_67A7CC + 0x5b2`, calls the screen-pane vtable slot `+0x20`, and returns `DISP_E_MEMBERNOTFOUND` (`0x80020003`). Generated `g_browserRuntime` remains an alias of [UID:0000S7][g_pScreenPane](by-global/g_pScreenPane.md), not a Browser-owned global. |

## Placement

These constants belong with the browser COM/event-sink declarations, not with generic UI event dispatch and not with socket protocol constants.

## Open Questions

- Final source spelling is not proven. The numeric DISPIDs and event behaviors are strong, but the original names may have matched Microsoft WebBrowser event names instead of the current `kDispId...` hypotheses.
- Case `106` remains confirmed in the legacy `Browser::Invoke` path, not the newer `BrowserControlPane::Invoke` handler.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)
- [UID:00001B][BrowserWindow](by-class/BrowserWindow.md)
- [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md)

## Changes

- 2026-06-07 A004 Batch 097:
  - Before: `COMPLETION:76`, `CONFIDENCE:90`, parent blank.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:90`, `AUTOGEN_PARENT_UID:0000HV`.
  - Summary/evidence: live IDA rechecked both browser dispatch handlers, exact function ranges, shared DISPIDs, URL/cancel/token behavior, and browser-specific fallback behavior. The strict gate is satisfied because the direct Browser file parent is already `86/88`; C++ remains blank because final symbolic names are still provisional.
- 2026-06-20 B007 Browser class sync:
  - Added the legacy `Browser::Invoke` event-style mapping for `104`, `106`, `250`, `251`, `263`, and `270`, including the adjusted old-Browser field behavior and private message `0x500` route.
- 2026-06-21 B010 BrowserControlPane Invoke sync:
  - Added the refined newer-control behavior for cases `104`, `250`, `251`, `252`, `259`, `263`, `270`, and default fallback, including allowed-prefix URL checks, top-level dispatch cookie handling, document-complete active-state restoration, and `g_pScreenPane` alias handling.
- 2026-07-02 B007 UID000331 implementation callback:
  - Synchronized the accepted legacy `Browser::Invoke` first-draft source names for the DWebBrowserEvents2 cases: `kDispIdBeforeNavigate2`, `kDispIdNavigateComplete2`, and `kDispIdNewWindow2`. Numeric values and behavior are unchanged; final original spelling remains provisional.
