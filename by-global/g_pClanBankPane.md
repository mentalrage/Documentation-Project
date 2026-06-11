*** UID:0002XJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pClanBankPane

## Status

- Address: `0x0067ade8`
- Storage page: [UID:0002XK][0x0067ade8-0x0067adec.g_pClanBankPane](by-memory/0x0067ade8-0x0067adec.g_pClanBankPane.md)
- Type hypothesis: `ClanBankPane *`
- Owner: [UID:0000I9][ClanBank](by-file/ClanBank.md)

## Evidence

The mixed-range audit records 7 xrefs for this slot. [UID:000026][ClanBankPane](by-class/ClanBankPane.md) documents the constructor store, destructor-family clears, and checks before opening/routing clan-bank UI actions.

## Assignment Gate

Assigned to [UID:0000I9][ClanBank](by-file/ClanBank.md), now `86/85`. The relationship is direct because this global stores the ClanBankPane singleton.

## Cross-References

- [UID:0000I9][ClanBank](by-file/ClanBank.md)
- [UID:000026][ClanBankPane](by-class/ClanBankPane.md)
- [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md)
- [UID:0002B5][0x0067adc4-0x0067adec.UiChatClanSingletonSlots](by-memory/0x0067adc4-0x0067adec.UiChatClanSingletonSlots.md)

## Changes

- 2026-06-07 A008 Batch 037 split: created as the canonical global page for the ClanBankPane singleton.
