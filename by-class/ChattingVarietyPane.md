*** UID:00001Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChattingVarietyPane

## Status

- Confidence: strong
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md)
- Address range: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- Current recovered file: `source-3/simroot_v2/class_ChattingVarietyPane.cpp`
- Autogen handling: attached to [UID:0000I5][Chatting](by-file/Chatting.md) as source-owned class code; reconstructed C++ stays blank below the final-source gate.

## Class Purpose

`ChattingVarietyPane` is the compact chat-mode button. It displays the current chat mode label and opens or dismisses `ChattingVarietySelectPane` when clicked.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ChattingVarietyPane` | [UID:0002FA][0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor](by-memory/0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor.md) | Constructs the pane and sets `g_pChattingVarietyPane`. |
| destructor body | [UID:0002FB][0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor](by-memory/0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor.md) | Clears `g_pChattingVarietyPane` and tail-calls base teardown. |
| `OnMouseEvent` | [UID:0002FC][0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent](by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md) | Handles click/toggle behavior for the mode selector popup, including inline popup construction. |
| `OnPaint` | [UID:0002FD][0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint](by-memory/0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md) | Draws `CHATVAR.EPF`/`CHATVAR.PAL` and the current mode label. |
| secondary forwarder | [UID:0002FE][0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder](by-memory/0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder.md) | Small real IDA function; likely current-rectangle refresh/invalidating virtual forwarder. |
| compact button rectangle helper | [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md) | Raw helper that writes the compact `(0,0,62,24)` chat-mode button rectangle or an empty rectangle. |
| compact button hit-test helper | [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md) | Raw helper that tests a point against the compact chat-mode button rectangle and returns row `0` or `-1`. |
| `SetDisplayMode` | `0x004b9670` | Later helper used during paint/init. |
| `ScalarDeletingDestructor` | `0x00483d50` | Clears `g_pChattingVarietyPane`. |

## Evidence Notes

- IDA MCP confirms exact local constructor, destructor body, mouse handler, paint method, and small `0x00481000` helper.
- IDA MCP vtable data xrefs tie `0x00480cd0`, `0x00480e80`, and `0x00481000` to the `ChattingVarietyPane` vtable area.
- IDA decompilation uses labels `Shout`, `Whisper`, `Group`, and `Clan`, with the default label likely `Talk`, directly tying the class to chat/social mode selection.
- 2026-06-03 review keeps the unmodeled `0x00481010` and `0x00481060` helpers with this compact pane because both use the same `(0,0,62,24)` button rectangle as `OnMouseEvent`; the popup selector's six-row geometry is handled by [UID:0002FM][0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect](by-memory/0x00481a80-0x00481acd.ChattingVarietySelectPaneGetItemRect.md) and [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md).

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:00001Z][ChattingVarietySelectPane](by-class/ChattingVarietySelectPane.md)
- [UID:0002FA][0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor](by-memory/0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor.md)
- [UID:0002FB][0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor](by-memory/0x00480ca0-0x00480cc9.ChattingVarietyPaneDestructor.md)
- [UID:0002FC][0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent](by-memory/0x00480cd0-0x00480e80.ChattingVarietyPaneOnMouseEvent.md)
- [UID:0002FD][0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint](by-memory/0x00480e80-0x00480ff1.ChattingVarietyPaneOnPaint.md)
- [UID:0002FE][0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder](by-memory/0x00481000-0x0048100a.ChattingVarietyPaneRefreshForwarder.md)
- [UID:0002FF][0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper](by-memory/0x00481010-0x00481056.ChattingVarietySelectPaneRowRectHelper.md)
- [UID:0002FG][0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest](by-memory/0x00481060-0x004810ea.ChattingVarietySelectPaneInitialHitTest.md)

## Changes

- What existed before: the page documented mode-button behavior and method anchors, but metadata was still `0/0`.
- What it was changed to: scores were set to `72/86`.
- Summary and evidence: constructor, toggle behavior, paint/init, mode labels, and destructor are covered; field layout and final method names remain light.
- 2026-05-31: Updated completion/confidence from `72/86` to `82/90` after adding exact by-memory pages for the constructor, destructor body, mouse handler, paint method, and tiny refresh forwarder. Evidence: IDA MCP function boundaries, decompilation, xrefs, vtable data audit, render strings, mode labels, and padding audit.
- 2026-06-03: Marked the class source-owned reconstructable, attached it to [UID:0000I5][Chatting](by-file/Chatting.md), and added the raw compact-button rectangle and initial hit-test helpers at `0x00481010` and `0x00481060` to the method list. Evidence: both helpers are source-owned raw bodies between compact-pane padding and the selector constructor, and their geometry matches the compact button rather than the popup list.
