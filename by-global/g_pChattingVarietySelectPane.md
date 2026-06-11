*** UID:0002XA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pChattingVarietySelectPane

## Status

- Address: `0x0067addc`
- Storage page: [UID:0002XB][0x0067addc-0x0067ade0.g_pChattingVarietySelectPane](by-memory/0x0067addc-0x0067ade0.g_pChattingVarietySelectPane.md)
- Type hypothesis: `ChattingVarietySelectPane *`
- Owner: [UID:0000I5][Chatting](by-file/Chatting.md)

## Evidence

The mixed-range audit records 7 xrefs for this slot. [UID:00001Z][ChattingVarietySelectPane](by-class/ChattingVarietySelectPane.md) and the chat UI block document the selector allocation/check, store, clear paths, and selector lifecycle.

## Assignment Gate

Assigned to [UID:0000I5][Chatting](by-file/Chatting.md), now `85/88`. The relationship is direct because this global stores the chat mode selector popup singleton.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:00001Z][ChattingVarietySelectPane](by-class/ChattingVarietySelectPane.md)
- [UID:000106][0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest](by-memory/0x00481ad0-0x00481b5b.ChattingVarietySelectPaneHitTest.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-06-07 A008 Batch 037 split: created as the canonical global page for the chat mode selector popup singleton.
