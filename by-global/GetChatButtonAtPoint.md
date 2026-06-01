*** UID:0000SX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GetChatButtonAtPoint

## Status

- Confidence: strong for behavior, switch-table tail, signature, and chat ownership.
- Address range: [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md)
- Symbol kind: recovered free helper, likely original file-local/static helper.
- Likely owner file: [UID:0000I5][Chatting](by-file/Chatting.md)

## Role

`GetChatButtonAtPoint` maps a mouse coordinate to one of the fixed [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md) hit regions. It is used only by `ChattingHandlePane::OnMouseEvent`.

The memory page now covers `0x00482400-0x004824e0` because IDA raw head review shows the switch jump table at `0x004824cc-0x004824e0` belongs to this helper. The rectangle set matches [UID:0002FW][0x00482310-0x00482400.ChatButtonRectHelperRaw](by-memory/0x00482310-0x00482400.ChatButtonRectHelperRaw.md).

## Current Data Caveat

Current `simroot_v2/recovered/GetChatButtonAtPoint_00482400.cpp` has the correct coordinate-style signature. Current `simroot_v2/class_ChattingHandlePane.cpp` emits the call as if the helper receives `this` and the event object. IDA disassembly contradicts that generated call-site form: the binary pushes the event coordinate fields directly.

## Source Placement

Treat this as a private helper in `social/Chatting.cpp`, or as a private/static helper beside `ChattingHandlePane` if the chat-handle code is split out. Do not infer an original `GetChatButtonAtPoint.cpp` from the generated recovered file.

## Cross-References

- [UID:000107][0x00482400-0x004824e0.GetChatButtonAtPoint](by-memory/0x00482400-0x004824e0.GetChatButtonAtPoint.md)
- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md)
- [UID:0002FT][0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent](by-memory/0x00481d60-0x0048214f.ChattingHandlePaneOnMouseEvent.md)
- [UID:0002FW][0x00482310-0x00482400.ChatButtonRectHelperRaw](by-memory/0x00482310-0x00482400.ChatButtonRectHelperRaw.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [wave3 data issues](../wave3_data_issues.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `80/86`.
  - Before: page documented coordinate hit-test behavior, chat ownership, generated call-site mismatch, and source placement but remained unevaluated.
  - After: score reflects documented role, exact memory anchor, private chat-helper placement, and Wave3 data caveat.
  - Evidence: the linked memory/chat pages record that the helper maps event coordinates to `ChattingHandlePane` button regions and that IDA pushes coordinate fields directly.
- 2026-05-31: Grading changed from `80/86` to `84/90`.
  - Before: page referenced the helper but did not account for the switch-table tail or companion rectangle helper.
  - After: page records the corrected `0x00482400-0x004824e0` by-memory range and cross-references the raw rectangle helper.
  - Evidence: IDA MCP raw head review confirms `jpt_482421` at `0x004824cc-0x004824e0`, and the companion helper at `0x00482310` writes the same four rectangles.
