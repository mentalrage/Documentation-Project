*** UID:0002X5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I5 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pChattingVarietyPane

## Status

- Address: `0x0067add8`
- Storage page: [UID:0002X6][0x0067add8-0x0067addc.g_pChattingVarietyPane](by-memory/0x0067add8-0x0067addc.g_pChattingVarietyPane.md)
- Type hypothesis: `ChattingVarietyPane *`
- Owner: [UID:0000I5][Chatting](by-file/Chatting.md)

## Evidence

The mixed-range audit records 18 xrefs for this slot. [UID:00001Y][ChattingVarietyPane](by-class/ChattingVarietyPane.md) documents the constructor store, destructor clear, scalar-deleting destructor clear, selector-opening behavior, and multiple chat/map UI reads.

## Assignment Gate

Assigned to [UID:0000I5][Chatting](by-file/Chatting.md), now `85/88`. The relationship is direct because this global stores the chat mode variety pane singleton.

## Cross-References

- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:00001Y][ChattingVarietyPane](by-class/ChattingVarietyPane.md)
- [UID:0002FA][0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor](by-memory/0x00480c50-0x00480c9f.ChattingVarietyPaneConstructor.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-06-07 A008 Batch 037 split: created as the canonical global page for the chat mode variety pane singleton.
