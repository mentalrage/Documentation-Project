*** UID:00001W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChattingModifyHeightPane

## Status

- Confidence: strong
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md)
- Address range: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- Current recovered file: `source-3/simroot_v2/class_ChattingModifyHeightPane.cpp`

## Class Purpose

`ChattingModifyHeightPane` is the draggable chat-height handle. It lets the user change the number of visible chat rows, updates the scroll viewport/display pane, repositions the handle, and stores the line count in config.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ChattingModifyHeightPane` | [UID:0002F4][0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor](by-memory/0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor.md) | Constructs the handle pane and initializes its fixed rectangle. |
| `~ChattingModifyHeightPane` body | [UID:0002F5][0x00480860-0x00480889.ChattingModifyHeightPaneDestructor](by-memory/0x00480860-0x00480889.ChattingModifyHeightPaneDestructor.md) | Clears the handle singleton/global and tail-calls base pane teardown. |
| `OnMouseEvent` | [UID:0002F6][0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent](by-memory/0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent.md) | Handles drag start, drag preview, and drag release line-count calculation. |
| cancel input helper | [UID:0002F7][0x00480a80-0x00480ac5.ChattingModifyHeightPaneCancelHotkeys](by-memory/0x00480a80-0x00480ac5.ChattingModifyHeightPaneCancelHotkeys.md) | Cancels an active drag and restores the stored handle rectangle for selected key bytes. |
| viewport/layout helper | [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md) | Called from `OnMouseEvent` at `0x0048093e`; recomputes the chat scroll viewport from current BackPane/root bounds and the selected visible-line count. |
| `SetLineCount` | [UID:0002F8][0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount](by-memory/0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount.md) | Clamps the visible line count, resizes the chat viewport/display pane, and positions the handle. |
| `OnPaint` | [UID:0002F9][0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint](by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md) | Draws the `CHATSC.EPF` handle while expanded, using `invenbut.pal`. |
| `ScalarDeletingDestructor` | `0x00483c00` | Clears `g_pChattingModifyHeightPane`. |

## Evidence Notes

- IDA MCP confirms exact functions and `0xcc` padding across `0x004807b0-0x00480c50`.
- IDA MCP recheck on 2026-05-26 confirms generated `BackPane::SetScrollViewport` at `0x004806d0` has exactly one direct caller, `ChattingModifyHeightPane::OnMouseEvent` at `0x0048093e`; treat it as chat viewport layout support despite the current generated owner.
- 2026-05-31 IDA MCP decompilation confirms drag line-count formula `(710 - clampedY) / 13`, clamps visible lines to at least `4`, and stores the resulting count at `dword_67A7C8 + 2678392`.
- 2026-05-31 IDA MCP render evidence confirms the paint method uses `CHATSC.EPF` and `invenbut.pal`.
- The generated destructor uses a polluted `TextButtonExControlPane` name for base teardown; treat that base-helper name as provisional.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:00001X][ChattingPane](by-class/ChattingPane.md)
- [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md)
- [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md)
- [UID:0002F4][0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor](by-memory/0x004807b0-0x0048085e.ChattingModifyHeightPaneConstructor.md)
- [UID:0002F5][0x00480860-0x00480889.ChattingModifyHeightPaneDestructor](by-memory/0x00480860-0x00480889.ChattingModifyHeightPaneDestructor.md)
- [UID:0002F6][0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent](by-memory/0x00480890-0x00480a7b.ChattingModifyHeightPaneOnMouseEvent.md)
- [UID:0002F7][0x00480a80-0x00480ac5.ChattingModifyHeightPaneCancelHotkeys](by-memory/0x00480a80-0x00480ac5.ChattingModifyHeightPaneCancelHotkeys.md)
- [UID:0002F8][0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount](by-memory/0x00480ad0-0x00480ba3.ChattingModifyHeightPaneSetLineCount.md)
- [UID:0002F9][0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint](by-memory/0x00480bb0-0x00480c45.ChattingModifyHeightPaneOnPaint.md)

## Changes

- What existed before: the page documented drag/line-count behavior and helper ownership, but metadata was still `0/0`.
- What it was changed to: scores were set to `76/86`.
- Summary and evidence: constructor, mouse handling, viewport helper, line count, paint, and destructor are covered; detailed fields and final layout remain incomplete.
- 2026-05-31: Updated completion/confidence from `76/86` to `82/90` after adding exact by-memory pages for every function in the `0x004807b0-0x00480c50` cluster and replacing raw address rows with UID references. Evidence: IDA MCP function iteration, decompilation, xrefs, vtable data xrefs, render strings, and padding audit.
