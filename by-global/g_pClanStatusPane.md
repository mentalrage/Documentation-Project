*** UID:0002XG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pClanStatusPane

## Status

- Address: `0x0067ade4`
- Storage page: [UID:0002XH][0x0067ade4-0x0067ade8.g_pClanStatusPane](by-memory/0x0067ade4-0x0067ade8.g_pClanStatusPane.md)
- Type hypothesis: `ClanStatusPane *`
- Owner: [UID:0000I8][Clan](by-file/Clan.md)

## Evidence

The mixed-range audit records 15 xrefs for this slot. [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md) documents the constructor store, cleanup/destructor clears, and clan status helper reads for row actions, list dialogs, and packet routing.

## Assignment Gate

Assigned to [UID:0000I8][Clan](by-file/Clan.md), now `90/85`. The relationship is direct because this global stores the ClanStatusPane singleton.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:00002K][ClanStatusPane](by-class/ClanStatusPane.md)
- [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-06-07 A008 Batch 037 split: created as the canonical global page for the ClanStatusPane singleton.
