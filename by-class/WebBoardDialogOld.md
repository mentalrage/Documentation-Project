*** UID:0000G3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WebBoardDialogOld

## Status

- Confidence: strong for class identity and core method boundaries; medium for final source-file placement.
- Likely source file: [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- Address ranges: [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md), [UID:0000ZA][0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh](by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md), [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md), [UID:0000ZB][0x0046e640-0x0046e8be.WebBoardDialogOldConstructor](by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md), [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md), [UID:000213][0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper](by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md), [UID:0000ZD][0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse](by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md), [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md)
- Current generated file: incorrectly emitted through `source-3/simroot_v2/class_RankingDialog.cpp`

## Class Purpose

`WebBoardDialogOld` is a legacy browser-backed web-board dialog. It derives from the same `BrowserPane` family as [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md), but wraps the browser control in fixed `WEBBOARD.EPD` / `WEBBOARD.PAD` art and a smaller `540x379` dialog layout.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw close/teardown-like helper | `0x0046e260-0x0046e293` | Unmodeled helper that shuts down the `BrowserControlPane` at offset `+0x26c`, clears it, calls virtual cleanup slots, and unregisters through `dword_67A74C`; final dispatch path is open. |
| `RefreshLayout` / layout helper | `0x0046e2a0-0x0046e4b5` | Rebuilds close button and browser control rectangles for modes `0`, `4`, and `6`; no current direct xrefs in IDA, so final name is open. |
| mode/control rect helper | `0x0046e4c0-0x0046e63c` | Raw helper that returns hard-coded rectangles for open modes `0`, `4`, and `6`, using a selector table for controls/slots; includes compiler-generated switch tables. |
| `WebBoardDialogOld` | `0x0046e640-0x0046e8bd` | Builds fixed-art web-board dialog, stores singleton `0x0067aba0`, creates `WEBBOARD.EPD` background, close button, browser control, and queues opcode `0x73` when no direct payload or URL is supplied. |
| destructor | `0x0046e8c0-0x0046e8e8` | Clears [UID:0000SR][g_pWebBoardDialogOld](by-global/g_pWebBoardDialogOld.md), restores `BrowserPane` vtables, and runs base teardown. |
| close/activation callback | `0x0046e8f0-0x0046e92a` | Vtable callback at `0x006136d4`; on state `1`, runs virtual close/deactivation slots, shuts down the embedded browser-control pointer at `+0x26c`, and unregisters the dialog from `dword_67a74c`. |
| browser reposition/input callback | `0x0046e930-0x0046e9f4` | Secondary-vtable callback at `0x00613704`; delegates to the generic browser pane input handler, then when moving/resizing updates the embedded browser HWND to the old dialog's fixed `30,30` inset and refreshes the screen pane. |
| packet forwarder | `0x0046ea00-0x0046ea22` | Vtable/event callback that checks packet/event byte `0x62` and forwards payload to `HandleWebBoardResponse`. |
| initial request helper | `0x0046ea30-0x0046ea98` | Raw helper that sends opcode `0x73` with zero payload through `dword_67a7ec` and starts timer `0x572` for `20000` ms; no IDA function object or direct xrefs currently exist. |
| `HandleWebBoardResponse` | `0x0046eaa0-0x0046ee79` | Cancels timer `0x572`, parses web-board payloads, sets `domain` and `boardinfo` cookies, and navigates the embedded browser pane. |
| old URL escape helper | `0x0046ee80-0x0046efd9` | Raw helper that initializes old escape table state at `0x0067acb0/0x0067acb8` and percent-encodes boardinfo/cookie bytes for the old response parser. |
| singleton clear thunk | `0x00470260-0x0047026a` | Exception-unwind/simple cleanup helper that clears `g_pWebBoardDialogOld`. |
| scalar deleting destructor | `0x004707f0-0x0047084e` | Destructor wrapper used from the vtable; optionally frees storage. |

## Evidence Notes

- IDA MCP on 2026-05-24 confirms `0x0046e640` installs `BrowserPane` vtables, then `WebBoardDialogOld` vtables, and writes singleton `0x0067aba0`.
- `0x0046e640` constructs `WEBBOARD.EPD` / `WEBBOARD.PAD` background art, an image-button close control id `30`, and a `BrowserControlPane` at `(30,30)-(510,334)`.
- `0x0046eaa0` is behaviorally the old-variant response parser: it cancels timer `0x572`, decodes URL/domain/boardinfo payload fields, initializes a URL-escape table at `0x0067acb0+`, sets cookies, and calls the browser navigate method.
- IDA MCP on 2026-05-27 confirms raw helper bytes at `0x0046e260-0x0046e294` inside [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md). The helper uses offset `+0x26c`, matching the old browser-control pointer, but has no current function object or direct xref in IDA.
- IDA MCP on 2026-05-27 confirms raw helper bytes and switch tables at [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md). The helper writes mode/control-specific rectangles for modes `0`, `4`, and `6`, but has no current function object or direct xref in IDA.
- IDA MCP on 2026-05-27 confirms [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md): destructor bytes clear singleton `0x0067aba0`; callback slots at `0x006136d4` and `0x00613704` own browser-control shutdown and browser HWND reposition behavior.
- IDA MCP on 2026-05-27 confirms [UID:000213][0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper](by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md): raw helper bytes build `0x73,0x00`, queue length `2`, and start timer `0x572` for `0x4e20`.
- IDA MCP on 2026-05-27 confirms [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md): raw helper bytes initialize `0x0067acb0/0x0067acb8` escape state and percent-encode old board info strings.
- `simroot_v2/class_RankingDialog.cpp` labels the constructor as `RankingDialog::WebBoardDialogOld_Constructor` and the response as `RankingDialog::HandleWebBoardResponse`. IDA vtable/singleton evidence shows these are not ranking methods.

## Open Questions

- Final original name may have been `WebBoardDialogOld`, `OldWebBoardDialog`, or a local compatibility class name; the vtable name currently supports `WebBoardDialogOld`.
- `0x0046e2a0` has no current IDA code xrefs. Treat it as an old web-board layout helper, but do not make it the constructor.
- Determine whether the active and old variants shared one `WebBoardDialog.cpp` source or whether the old fixed-art implementation lived beside browser legacy classes.

## Cross-References

- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md)
- [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md)
- [UID:0000ZA][0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh](by-memory/0x0046e2a0-0x0046e4b6.WebBoardDialogOldLayoutRefresh.md)
- [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md)
- [UID:0000ZB][0x0046e640-0x0046e8be.WebBoardDialogOldConstructor](by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md)
- [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md)
- [UID:0000ZC][0x0046ea00-0x0046ea23.WebBoardDialogOldPacketForwarder](by-memory/0x0046ea00-0x0046ea23.WebBoardDialogOldPacketForwarder.md)
- [UID:000213][0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper](by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md)
- [UID:0000ZD][0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse](by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md)
- [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md)
- [UID:0000SR][g_pWebBoardDialogOld](by-global/g_pWebBoardDialogOld.md)
- [UID:0001RT][webboard-dialog-resources](by-resource/webboard-dialog-resources.md)
- [UID:000019][BrowserPane](by-class/BrowserPane.md)
- [UID:000015][BrowserControlPane](by-class/BrowserControlPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:80`.
  - Summary/evidence: scored from the detailed legacy web-board constructor, layout, rect helper, callbacks, packet forwarder, request/response, URL escape, singleton/destructor, resource, and generated-owner-correction evidence; confidence remains capped by raw helper starts with no direct xrefs and unresolved final source-file placement.
