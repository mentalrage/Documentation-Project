*** UID:0000G2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WebBoardDialog

## Status

- Confidence: strong for behavior, singleton, and core method boundaries; medium for final source-file placement.
- Likely source file: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md), with board references from [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) and browser infrastructure from [UID:0000HV][Browser](by-file/Browser.md)
- Address ranges: [UID:0000Z7][0x0046d050-0x0046d324.WebBoardDialog](by-memory/0x0046d050-0x0046d324.WebBoardDialog.md), [UID:0000Z9][0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse](by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md), [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md)
- Current recovered file: `source-3/simroot_v2/class_WebBoardDialog.cpp`

## Class Purpose

`WebBoardDialog` is a browser-backed in-game board dialog. It derives from the browser pane/dialog family, creates an embedded `BrowserControlPane`, and routes packet-driven or direct-URL startup into the board response/browser loader.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `WebBoardDialog` | `0x0046d050-0x0046d324` | Builds the browser-backed board dialog and initializes URL/packet response loading. |
| destructor | `0x0046d330-0x0046d359` | Clears [UID:0000SQ][g_pWebBoardDialog](by-global/g_pWebBoardDialog.md), restores `BrowserPane` vtables, and runs base teardown. |
| close/teardown virtual | `0x0046d360-0x0046d3a5` | Shuts down the embedded `BrowserControlPane`, clears the child pointer, runs cleanup virtuals, and unregisters from the child registry when closing. |
| reposition/input override | `0x0046d3b0-0x0046d475` | DialogPane-style input override that repositions the embedded browser HWND and refreshes the active screen pane. |
| packet forwarder | `0x0046d480-0x0046d4a3` | Vtable/event callback that checks packet/event byte `0x62` and forwards payload to `HandleBoardResponse`. |
| key/input override | `0x0046d4b0-0x0046d50e` | Handles a board/browser key case and otherwise falls back to shared DialogPane key handling. |
| initial board request helper | `0x0046d510-0x0046d57b` | Raw helper that queues opcode `0x73` with a caller byte and starts timer `0x572`. |
| `HandleBoardResponse` | `0x0046d580-0x0046da62` | Cancels timer `0x572`, parses web-board payloads, sets browser cookies, and navigates the embedded browser pane. |
| URL escape helper | `0x0046da70-0x0046dbca` | Raw helper that initializes the active URL escape table and copies or `%XX`-escapes response URL bytes into a bounded buffer. |
| control/layout refresh vtable helper | `0x0046dbd0-0x0046dcf3` | Vtable-backed helper at slot `0x00613620`; clears pending browser state and adjusts selected child/control rect drawing around resource ids `0x84`/`0x86`. |
| background tile render helper | `0x0046dd00-0x0046de96` | Vtable-backed helper at slot `0x0061362c`; tiles the web-board interior/background resource across the inset dialog rect. |
| frame tile render helper | `0x0046dea0-0x0046e25b` | Vtable-backed helper at slot `0x00613630`; draws web-board frame/corner/edge tiles when the embedded browser-control state is clear. |
| singleton clear thunk | `0x00470250-0x0047025a` | Exception-unwind/simple cleanup helper that clears `g_pWebBoardDialog`. |
| scalar deleting destructor | `0x00470790-0x004707ee` | Destructor wrapper used from the vtable; optionally frees storage. |

## Evidence Notes

- Wave3 summary identifies the class as a `BrowserPane`-derived modal board flow.
- IDA MCP confirms `0x0046d050` as a real function with size `0x2d4`.
- IDA MCP on 2026-05-24 confirms `0x0046d480` size `0x23`, `0x0046d580` size `0x4e3`, `0x0046d330` size `0x29`, and `0x00470790` size `0x5f`.
- IDA MCP on 2026-05-27 confirms the virtual companion cluster at [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md), with vtable slots at `0x00613624`, `0x00613654`, and the adjacent packet slot at `0x00613660`.
- IDA MCP on 2026-05-27 confirms [UID:00020Z][0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers](by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md), including vtable-backed `0x0046d4b0` at slot `0x00613658` and raw non-modeled helper `0x0046d510-0x0046d57b`.
- IDA MCP on 2026-05-27 confirms [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md), including active WebBoardDialog vtable slots `0x00613620`, `0x0061362c`, and `0x00613630`, plus raw non-modeled helpers at `0x0046da70` and `0x0046e260`.
- `0x0046d050` stores singleton `0x0067ab9c`; destructor paths clear the same global.
- The active constructor callers are browser/menu/map-adjacent open paths at `0x00508da0`, `0x005145db`, `0x00554d76`, and `0x005bd0cf`.
- Source placement is split-confidence: behavior is board-specific, but base implementation and control dependencies are in the browser module. Keep the source candidate under [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md) until import-source evidence proves otherwise.

## Related Variant

[UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) is a separate legacy fixed-art variant. Do not merge its generated `class_RankingDialog.cpp` body into `RankingDialog`; keep it with this web-board family.

## Cross-References

- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0000Z7][0x0046d050-0x0046d324.WebBoardDialog](by-memory/0x0046d050-0x0046d324.WebBoardDialog.md)
- [UID:00020Y][0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions](by-memory/0x0046d330-0x0046d475.WebBoardDialogVirtualCompanions.md)
- [UID:0000Z8][0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder](by-memory/0x0046d480-0x0046d4a3.WebBoardDialogPacketForwarder.md)
- [UID:00020Z][0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers](by-memory/0x0046d4b0-0x0046d57b.WebBoardDialogInputAndRequestHelpers.md)
- [UID:0000Z9][0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse](by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md)
- [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md)
- [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md)
- [UID:0000SQ][g_pWebBoardDialog](by-global/g_pWebBoardDialog.md)
- [UID:000013][Browser](by-class/Browser.md)
- [UID:000019][BrowserPane](by-class/BrowserPane.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)

## Changes

- 2026-05-27: The constructor method row previously ended at `0x0046d323`; changed it to exclusive end `0x0046d324`. IDA MCP reports `sub_46D050` size `0x2d4`, and the matching by-memory page uses `0x0046d050-0x0046d324`.
- 2026-05-27: The destructor method row previously ended at `0x0046d358`; changed it to exclusive end `0x0046d359`. IDA MCP reports `sub_46D330` size `0x29`, and the new virtual-companion memory page records the exact function span.
- 2026-05-27: The packet forwarder method row previously ended at `0x0046d4a2`; changed it to exclusive end `0x0046d4a3`. IDA MCP reports `sub_46D480` size `0x23`, and the matching by-memory page uses `0x0046d480-0x0046d4a3`.
- 2026-05-30: Grading changed from unevaluated `0/0` to `82/86`.
  - Before: class page had detailed active-method coverage but no score.
  - After: score reflects the documented constructor/destructor/input/packet/response/render/url-escape method family and singleton/browser-control ownership.
  - Evidence: linked by-memory pages cover the active class core through `0x0046e25b`, while the generated `simroot_v2/ui/dialogs/WebBoardDialog.cpp` still contains unresolved symbols and synthetic layout artifacts, keeping completion below fully reconstructed class pages.
