*** UID:0001SL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BrowserMessageId

## Status

- Confidence: strong for observed values, medium for final enum name.
- Current source evidence: IDA MCP decompilation of `BrowserControlPaneOld::HandleBrowserMessage` and `BrowserThread::RunMessageLoop`; generated source names are lead material only.
- Proposed owner: [UID:0000HV][Browser](by-file/Browser.md), likely `browser/Browser.h`.
- Reconstructable: yes, as source-level browser message constants. Leave autogen parent/code blank until the final browser header split and names are proven.

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

## Open Questions

- The Win32 values have standard meanings, but the final source may have used Win32 constants directly for `15`, `256`, `257`, `260`, and `261` instead of wrapping them in a browser enum.
- Private values `1280` and `1281` are likely browser-thread `WM_USER`-range constants, but final names remain provisional until the post/send call sites are fully audited.

## Cross-References

- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:000016][BrowserControlPaneOld](by-class/BrowserControlPaneOld.md)
- [UID:00001A][BrowserThread](by-class/BrowserThread.md)
- [UID:0000ZF][0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers](by-memory/0x0046f010-0x004710b7.BrowserOleLegacyAndHelpers.md)
