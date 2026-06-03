*** UID:00001V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChattingHandlePane

## Status

- Confidence: strong
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md)
- Address range: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- Current recovered file: `source-3/simroot_v2/class_ChattingHandlePane.cpp`

## Class Purpose

`ChattingHandlePane` owns the chat handle controls. It tracks hover/toggle state for the handle buttons, persists chat-related display options to config, enables/disables the secondary chat scroll widget, and paints `CHATBUTT.EPF` frames.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ChattingHandlePane` | [UID:0002FR][0x00481c10-0x00481d2a.ChattingHandlePaneConstructor](by-memory/0x00481c10-0x00481d2a.ChattingHandlePaneConstructor.md) | Constructs the handle pane, reads persisted config, updates the secondary chat scroll widget, and sets `g_pChattingHandlePane`. |
| destructor body | [UID:0002FS][0x00481d30-0x00481d59.ChattingHandlePaneDestructor](by-memory/0x00481d30-0x00481d59.ChattingHandlePaneDestructor.md) | Clears `g_pChattingHandlePane` and calls base teardown. |
| `OnMouseEvent` | [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md) | Handles hover, mouse-down hit-test, mouse-up toggles, config writes, and invalidation. |
| `OnPaint` | [UID:0002FU][0x00482150-0x004822f6.ChattingHandlePaneOnPaint](by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md) | Draws the three visible handle button regions from `CHATBUTT.EPF`. |
| virtual forwarder | [UID:0002FV][0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder](by-memory/0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder.md) | Compiler-generated secondary-subobject forwarder retained as vtable/layout evidence, not handwritten source. |
| rectangle helper | [UID:0002FW][0x00482310-0x00482400.ChatButtonRectHelperRaw](by-memory/0x00482310-0x00482400.ChatButtonRectHelperRaw.md) | Raw IDA-unmodeled helper that writes chat handle button rectangles. |
| [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md) | `0x00482400-0x004824e0` | File-local helper for hit-testing chat handle regions; includes its switch jump table tail and takes mouse coordinates, not the pane/event object. |
| `ScalarDeletingDestructor` | `0x00483ba0` | Clears `g_pChattingHandlePane`. |

## Evidence Notes

- IDA MCP confirms exact boundaries for the constructor, destructor body, mouse handler, paint handler, tiny forwarder, raw rectangle helper, and hit-test helper.
- The recovered helper [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md) hit-tests four hardcoded regions: left button, middle strip, middle-right button, and right button.
- 2026-05-26 IDA recheck confirms the recovered helper signature is correct: the two call sites at `0x00481dca` and `0x00481ec9` pass `eventData + 0x08` and `eventData + 0x0c` coordinate fields. Current `simroot_v2/class_ChattingHandlePane.cpp` incorrectly emits `GetChatButtonAtPoint(this, eventData)`.
- 2026-05-31 IDA raw head review confirms `0x00482310-0x00482400` is a real rectangle-writing helper with switch table `jpt_482321`; no direct xrefs are currently exposed.
- 2026-05-31 IDA raw head review confirms `GetChatButtonAtPoint` has a switch jump table tail at `0x004824cc-0x004824e0`, so the by-memory page was renamed from the shorter `0x00482400-0x004824c8` range.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:0002FR][0x00481c10-0x00481d2a.ChattingHandlePaneConstructor](by-memory/0x00481c10-0x00481d2a.ChattingHandlePaneConstructor.md)
- [UID:0002FS][0x00481d30-0x00481d59.ChattingHandlePaneDestructor](by-memory/0x00481d30-0x00481d59.ChattingHandlePaneDestructor.md)
- [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md)
- [UID:0002FU][0x00482150-0x004822f6.ChattingHandlePaneOnPaint](by-memory/0x00482150-0x004822f6.ChattingHandlePaneOnPaint.md)
- [UID:0002FV][0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder](by-memory/0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder.md)
- [UID:0002FW][0x00482310-0x00482400.ChatButtonRectHelperRaw](by-memory/0x00482310-0x00482400.ChatButtonRectHelperRaw.md)
- [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md)
- [UID:00001R][ChattingBackPane](by-class/ChattingBackPane.md)
- [UID:00001W][ChattingModifyHeightPane](by-class/ChattingModifyHeightPane.md)

## Changes

- What existed before: the page documented handle behavior, methods, helper signature correction, and references, but metadata was still `0/0`.
- What it was changed to: scores were set to `78/86`.
- Summary and evidence: mouse, paint, config, helper, destructor, and generated-signature caveat are covered; field layout and final header form remain incomplete.
- 2026-05-31: Updated completion/confidence from `78/86` to `86/90` after splitting the exact handle cluster through `0x004824e0`, including constructor, destructor body, mouse, paint, forwarder, raw rectangle helper, and hit-test helper switch table tail. Evidence: IDA MCP function iteration, decompilation, vtable xrefs, raw head review, and padding audit.
- 2026-06-03: Reclassified the `0x00482300` secondary forwarder as compiler-generated layout/vtable glue rather than handwritten source. Evidence: [UID:0002FV][0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder](by-memory/0x00482300-0x0048230a.ChattingHandlePaneRefreshForwarder.md) records the IDA boundary, slot dispatch body, Wave2/Wave3 exclusion metadata, and disabled generated overlay.
