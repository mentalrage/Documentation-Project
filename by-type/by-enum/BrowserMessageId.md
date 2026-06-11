*** UID:0001SL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

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
| `1280` | `kBrowserThreadClose` | Browser thread private message that exits the message loop. |
| `1281` | `kBrowserThreadRedraw` | Browser thread private message that redraws the hosted browser window. |

## Evidence

- IDA MCP decompilation of `0x0046f310` shows `BrowserControlPaneOld::HandleBrowserMessage` switching on the incoming message field and handling cases `15`, `256`, `257`, `260`, and `261`.
- The `15` path calls the pane/control virtual at slot `+32` on `this - 264`, matching a paint/redraw bridge.
- The key-message group `256`, `257`, `260`, and `261` reads the key code and forwards only Tab (`9`) and Escape (`27`) through the browser key callback path; other messages fall back to `0x00528de0`.
- IDA MCP decompilation of `0x0046f010` shows `BrowserThread::RunMessageLoop` breaks on private message `1280` and redraws the hosted browser HWND with `RedrawWindow(..., 0x181)` on private message `1281`.

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
- Private values `1280` and `1281` are likely browser-thread `WM_USER`-range constants, but final names remain provisional until the post/send call sites are fully audited.

## Score Rationale

- Completion is `80` because the page now records observed values, legacy-control and thread-loop consumers, Win32-versus-private declaration boundaries, PlatformApi dispatch-slot ownership separation, owner attachment, and final-code caveats.
- Confidence is `90` because value use is IDA-backed through BrowserControlPaneOld and BrowserThread docs, and the keyboard callback storage has a separate high-confidence PlatformApi owner. Confidence remains below final-audit levels because the original symbolic names and post/send private-message call sites are not fully audited here.

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
