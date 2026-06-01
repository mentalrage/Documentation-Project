*** UID:00001R | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ChattingBackPane

## Status

- Confidence: strong
- Likely source file: [UID:0000I5][Chatting](by-file/Chatting.md)
- Address range: [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- Current recovered file: `source-3/simroot_v2/class_ChattingBackPane.cpp`

## Class Purpose

`ChattingBackPane` is the translucent background behind the chat display. It follows `ChattingHandlePane` mode/expanded state and adjusts visibility, alpha, and text color.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ChattingBackPane` | [UID:0002F1][0x00480640-0x00480694.ChattingBackPaneConstructor](by-memory/0x00480640-0x00480694.ChattingBackPaneConstructor.md) | Constructs a `Pane`, sets `g_pChattingBackPane`, installs vtables, and initializes background alpha to `0.6f`. |
| `~ChattingBackPane` body | [UID:0002F2][0x004806a0-0x004806c9.ChattingBackPaneDestructor](by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md) | Clears `g_pChattingBackPane` and tail-calls base pane teardown. |
| `UpdateVisibility` | [UID:0002F3][0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility](by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md) | Reads chat handle state and updates visibility/alpha/text color before refreshing the pane rectangle. |
| `ScalarDeletingDestructor` | `0x00483aa0` | Clears `g_pChattingBackPane` and destroys the base pane. |

## Evidence Notes

- IDA MCP confirms exact ranges for the constructor, destructor body, viewport helper, and update virtual in the `0x00480640-0x004807aa` cluster.
- `xrefs_to 0x00480740` reports a vtable data xref at `0x00614dd4`, supporting the update method as a `ChattingBackPane` virtual.
- The update method reads chat handle/global state at `dword_67ADE0 + 0x114/+0x118`, supporting placement with the chat module while leaving final field names open.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:0002F1][0x00480640-0x00480694.ChattingBackPaneConstructor](by-memory/0x00480640-0x00480694.ChattingBackPaneConstructor.md)
- [UID:0002F2][0x004806a0-0x004806c9.ChattingBackPaneDestructor](by-memory/0x004806a0-0x004806c9.ChattingBackPaneDestructor.md)
- [UID:000105][0x004806d0-0x00480739.BackPaneViewportRectHelper](by-memory/0x004806d0-0x00480739.BackPaneViewportRectHelper.md)
- [UID:0002F3][0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility](by-memory/0x00480740-0x004807aa.ChattingBackPaneUpdateVisibility.md)
- [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md)

## Changes

- What existed before: the page documented purpose, methods, and chat-module ownership, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `70/86`.
- Summary and evidence: constructor, update, destructor, and chat globals are clear; detailed fields and final header/code form are still light.
- 2026-05-31: Updated completion/confidence from `70/86` to `76/88` after creating exact by-memory pages for the constructor, destructor body, and update virtual and linking the existing viewport helper. Evidence: IDA MCP function iteration, decompilation, xrefs, vtable data audit, and raw byte audit.
