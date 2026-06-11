*** UID:0002WZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pChattingBackPane

## Status

- Address: `0x0067add0`
- Storage page: [UID:0002X0][0x0067add0-0x0067add4.g_pChattingBackPane](by-memory/0x0067add0-0x0067add4.g_pChattingBackPane.md)
- Type hypothesis: `ChattingBackPane *`
- Owner: [UID:0000I5][Chatting](by-file/Chatting.md)

## Evidence

The mixed-range audit records 8 xrefs for this slot. [UID:00001R][ChattingBackPane](by-class/ChattingBackPane.md) documents the constructor store, destructor clear, scalar-deleting destructor clear, and visibility reads tied to chat handle state.

## Assignment Gate

Assigned to [UID:0000I5][Chatting](by-file/Chatting.md), now `85/88`. The relationship is direct because this global stores the chat background pane singleton.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:00001R][ChattingBackPane](by-class/ChattingBackPane.md)
- [UID:0002F1][0x00480640-0x00480694.ChattingBackPaneConstructor](by-memory/0x00480640-0x00480694.ChattingBackPaneConstructor.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-06-07 A008 Batch 037 split: created as the canonical global page for the chat background pane singleton.
