*** UID:0001SL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# BrowserMessageId

## Status

- Confidence: strong for observed values, medium for final enum name.
- Current source evidence: IDA MCP decompilation of `BrowserControlPaneOld::HandleBrowserMessage` and `BrowserThread::RunMessageLoop`; generated source names are lead material only.
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md), likely `browser/Browser.h`.
- Reconstructable: yes, as source-level browser message constants. Attached to [UID:0000HV][Browser](by-file/Browser.md) because the owner is clear and both pages meet the `80/80` attachment gate. Leave C++ blank until the final browser header split and names are proven.

## Values

| Value | Name hypothesis | Meaning |
| --- | --- | --- |
| `15` | `kBrowserPaint` | Browser window paint/message bridge case. |
| `256` | `kBrowserKeyDown` | `WM_KEYDOWN`; forwarded for Tab/Escape handling. |
| `257` | `kBrowserKeyUp` | `WM_KEYUP`; handled by the legacy control message bridge. |
| `260` | `kBrowserSysKeyDown` | `WM_SYSKEYDOWN`; used with Alt/F4 style browser-thread handling. |
| `261` | `kBrowserSysKeyUp` | `WM_SYSKEYUP`; handled by the legacy control message bridge. |
| `1280` | `kBrowserThreadClose` / `kBrowserThreadCloseMessage` | Browser thread private message that exits the message loop. |
| `1281` | `kBrowserThreadRedraw` | Browser thread private message that redraws the hosted browser window. |

## Evidence

- IDA MCP decompilation of `0x0046f310` shows `BrowserControlPaneOld::HandleBrowserMessage` switching on the incoming message field and handling cases `15`, `256`, `257`, `260`, and `261`.
- The `15` path calls the pane/control virtual at slot `+32` on `this - 264`, matching a paint/redraw bridge.
- The key-message group `256`, `257`, `260`, and `261` reads the key code and forwards only Tab (`9`) and Escape (`27`) through the browser key callback path; other messages fall back to `0x00528de0`.
- IDA MCP decompilation of `0x0046f010` shows `BrowserThread::RunMessageLoop` breaks on private message `1280` and redraws the hosted browser HWND with `RedrawWindow(..., 0x181)` on private message `1281`.
- 2026-06-14 live IDA MCP in session `a001_goal2_class_batch` reports `0x0046f010` size `0x1b8` and `0x0046f310` size `0x68`; decompilation again shows `GetMessageA`, the `1280` break, the `1281` redraw branch, and the legacy control switch cases `15/256/257/260/261`.
- 2026-06-14 live decompilation of `0x0046f810` confirms browser script/event handling posts the close private message to `BrowserThread` with `PostThreadMessageA` at `0x0046f881` for `close()` and at `0x0046f8dc` for the `aRe` branch. A scoped `search_text` over `0x0046f000-0x004710c0` found no `501h` or `1281` literal, so the redraw private-message sender is still not identified in this browser OLE span.
- [UID:000331][0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable](by-memory/0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md) confirms [UID:000013][Browser](by-class/Browser.md) `Invoke` posts private message `0x500` for close/resource navigation handling from the old WebBrowser event-sink path.
- 2026-06-14 live `xrefs_to 0x0069bec4` shows wider PlatformApi/global dispatch references plus the two browser consumer calls at `0x0046f0e6` and `0x0046f34d`. This supports keeping callback storage ownership outside this enum while treating browser code as a consumer of the dispatch slot.

## Placement

Keep these constants in the browser module header or a browser-private enum. They are not packet opcodes and should not move to [UID:0001QH][client_network](by-meta/client_network.md) except as a browser/transport callback consumer.

## Declaration Boundary

The observed values are two related groups, not necessarily one original enum:

| Group | Values | Source-facing treatment |
| --- | --- | --- |
| Standard Win32 messages | `15`, `256`, `257`, `260`, `261` | Prefer standard `WM_PAINT`, `WM_KEYDOWN`, `WM_KEYUP`, `WM_SYSKEYDOWN`, and `WM_SYSKEYUP` names in final source unless decompilation later proves browser-local aliases. These values describe the legacy control bridge, not a browser-private protocol. |
| Browser thread private messages | `1280`, `1281` | Treat as browser-owned private `WM_USER`-range constants. Current names `kBrowserThreadClose` and `kBrowserThreadRedraw` are behavior-based and should remain provisional until post/send sites are fully audited. |

The keyboard forwarding path is consumer evidence, not storage ownership: [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) resolves the callback slot as PlatformApi `SendMessageW` dispatch storage. Browser code calls through it for Tab/Escape forwarding, but the dispatch table declaration belongs to PlatformApi.

## Consumer Split

| Consumer | Values used | Notes |
| --- | --- | --- |
| [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md) / `0x0046f310` | `15`, `256`, `257`, `260`, `261` | Handles paint/key bridge messages and forwards only Tab/Escape through the wide `SendMessageW` dispatch slot; other messages fall back to the legacy browser dispatch bridge at `0x00528de0`. |
| [UID:00001A][BrowserThread](by-class/BrowserThread.md) / `0x0046f010` | `1280`, `1281` | Runs the private browser-thread message loop, breaks on the close message, and redraws the hosted browser window on the redraw message. |

## Open Questions

- The Win32 values have standard meanings, but the final source may have used Win32 constants directly for `15`, `256`, `257`, `260`, and `261` instead of wrapping them in a browser enum.
- Private values `1280` and `1281` are likely browser-thread `WM_USER`-range constants. The close sender is now confirmed in `0x0046f810`; the redraw sender and final symbolic names remain provisional.

## Score Rationale

- Completion is raised from `80` to `85` because the page now records live IDA sizes/decompilation for both consumer functions, confirms the close-message `PostThreadMessageA` producer in `0x0046f810`, refreshes callback-storage xrefs, and narrows the remaining producer gap to the redraw private message and original symbolic names.
- Confidence is raised from `90` to `91` because live IDA agrees with the existing consumer split and adds source-side evidence for the close private message. It remains below final-audit levels because the Win32 values may have been direct constants, the redraw post/send site is not located here, and private-message names are still behavior-based.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md)
- [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- [UID:0000ZF][0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b8.BrowserOleLegacyAndHelpers.md)
- [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md)

## Changes

- 2026-06-07 A006 declaration-boundary pass:
  - Before: `COMPLETION:74`, `CONFIDENCE:88`, with observed values and high-level owner placement but no attachment or split between standard Win32 messages, browser-private thread messages, and PlatformApi callback storage.
  - Changed to: `COMPLETION:80`, `CONFIDENCE:90`, `AUTOGEN_PARENT_UID:0000HV`, with declaration-boundary and consumer-split sections.
  - Evidence: [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md) supplies the legacy control message cases, [UID:00001A][BrowserThread](by-class/BrowserThread.md) supplies the private thread-loop cases, [UID:0001Q1][0x0069bec4-0x0069bec8.g_browserControlKeyCallback](by-memory/0x0069bec4-0x0069bec8.g_browserControlKeyCallback.md) resolves the Tab/Escape forwarding callback as PlatformApi storage, and [UID:0000HV][Browser](by-file/Browser.md) owns the browser-private constants.
- 2026-06-14 A002 Goal2 score pass:
  - Before: `COMPLETION:80`, `CONFIDENCE:90`; private-message post/send sites were listed as unaudited.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:91`.
  - Summary/evidence: live IDA MCP rechecked `BrowserThread::RunMessageLoop` and `BrowserControlPaneOld::HandleBrowserMessage`, found the `0x0046f810` close-message `PostThreadMessageA` sites at `0x0046f881` and `0x0046f8dc`, and confirmed no redraw-message literal in the scoped browser OLE span. Final C++ remains blank because symbolic names and the redraw sender are not final-source quality.
- 2026-06-20 B007 Browser class sync:
  - Added explicit cross-reference that `Browser::Invoke` posts private message `0x500` for close/resource navigation handling from the old WebBrowser event-sink path.
- 2026-07-02 B007 UID000331 implementation callback:
  - Preserved the existing `kBrowserThreadClose` hypothesis and added the accepted first-draft alias `kBrowserThreadCloseMessage` used by [UID:000331][0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable](by-memory/0x0046f810-0x0046fb80.BrowserInvokeAndSwitchTable.md). The value remains `1280` / `0x500`; final original spelling remains provisional.
