*** UID:0002XE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pChattingHandlePane

## Status

- Address: `0x0067ade0`
- Storage page: [UID:0002XF][0x0067ade0-0x0067ade4.g_pChattingHandlePane](by-memory/0x0067ade0-0x0067ade4.g_pChattingHandlePane.md)
- Type hypothesis: `ChattingHandlePane *`
- Owner: [UID:0000I5][Chatting](by-file/Chatting.md)

## Evidence

The mixed-range audit records 15 xrefs for this slot. [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md) documents the constructor store, destructor and scalar-deleting destructor clear paths, persisted config state, and reads from chat/map UI consumers.

## Assignment Gate

Assigned to [UID:0000I5][Chatting](by-file/Chatting.md), now `85/88`. The relationship is direct because this global stores the chat handle pane singleton.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:00001V][ChattingHandlePane](by-class/ChattingHandlePane.md)
- [UID:0002FR][0x00481c10-0x00481d2a.ChattingHandlePaneConstructor](by-memory/0x00481c10-0x00481d2a.ChattingHandlePaneConstructor.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-06-07 A008 Batch 037 split: created as the canonical global page for the chat handle pane singleton.
