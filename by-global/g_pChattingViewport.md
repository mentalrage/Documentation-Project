*** UID:0002WV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000OE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pChattingViewport

## Status

- Address: `0x0067adc4`
- Storage page: [UID:0002WW][0x0067adc4-0x0067adc8.g_pChattingViewport](by-memory/0x0067adc4-0x0067adc8.g_pChattingViewport.md)
- Type hypothesis: `SystemMessagePane *` / chat viewport pane pointer.
- Owner: [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)

## Evidence

This is the first dword split from [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md). The mixed-range audit records a static image value of `0xffffffff`, 16 xrefs, constructor/clear writes in the `SystemMessagePane` family, and reads from system-message/UI helper paths.

## Assignment Gate

Assigned to [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md), now `88/85`. The relationship is direct because this global is the system-message viewport singleton; neighboring TextFilter, chat, and clan dwords are split into separate globals.

## Cross-References

- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:0001J6][0x00584ea0-0x0058af3b.SystemMessagePanes](by-memory/0x00584ea0-0x0058af3b.SystemMessagePanes.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-06-07 A008 Batch 037 split: created as the canonical global page for the `0x0067adc4` system-message/chat viewport singleton.
