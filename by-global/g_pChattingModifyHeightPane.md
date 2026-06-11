*** UID:0002X1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pChattingModifyHeightPane

## Status

- Address: `0x0067add4`
- Storage page: [UID:0002X2][0x0067add4-0x0067add8.g_pChattingModifyHeightPane](by-memory/0x0067add4-0x0067add8.g_pChattingModifyHeightPane.md)
- Type hypothesis: `ChattingModifyHeightPane *`
- Owner: [UID:0000I5][Chatting](by-file/Chatting.md)

## Evidence

The mixed-range audit records 7 xrefs for this slot. [UID:00001W][ChattingModifyHeightPane](by-class/ChattingModifyHeightPane.md) and the chat UI block document the constructor store, destructor/scalar clear paths, and reads from chat layout consumers.

## Assignment Gate

Assigned to [UID:0000I5][Chatting](by-file/Chatting.md), now `85/88`. The relationship is direct because this global stores the chat height/resize pane singleton.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:00001W][ChattingModifyHeightPane](by-class/ChattingModifyHeightPane.md)
- [UID:000104][0x0047efb0-0x00483ef7.ChattingUI](by-memory/0x0047efb0-0x00483ef7.ChattingUI.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-06-07 A008 Batch 037 split: created as the canonical global page for the chat height/resize pane singleton.
