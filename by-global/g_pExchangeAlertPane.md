*** UID:0000QV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_pExchangeAlertPane

## Status

- Address: `0x0069b330` (`dword_69B330` in IDA)
- Symbol kind: process-wide singleton pointer
- Likely owner file: [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- Confidence: strong.

## Purpose

`g_pExchangeAlertPane` guards the active exchange alert dialog. `ExchangeAlertPane` stores itself during construction, clears the pointer during destruction, and exchange packet handlers close the active alert before creating a replacement.

## Evidence

- IDA xrefs to `0x0069b330` include `ExchangeAlertPane` constructor storage at `0x004b04ff`/`0x004b0506`, destructor cleanup at `0x004b09d6`, singleton-clear helper `0x004b0860`, and close-active helper `0x004b0b20`.
- Exchange packet helpers reference the pointer at `0x004ad611`, `0x004ad739`, `0x004addd3`, and `0x004adf51` before showing cancel/ready alert messages.
- Adjacent globals are separate: `dword_69B328` is the item picker singleton and `dword_69B32C` is the mix dialog singleton.

## Cross-References

- [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md)
- [UID:00004Q][ExchangeAlertPane](by-class/ExchangeAlertPane.md)
- [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/84`. Summary/evidence: the page documents address, owner, singleton purpose, constructor/destructor/clear/close helper xrefs, packet-handler uses, adjacent singleton distinction, and class/file/memory refs.
- 2026-06-05: Marked reconstructable under [UID:0000J9][ExchangeDialog](by-file/ExchangeDialog.md). Evidence: live IDA MCP reports nine xrefs to `0x0069b330`, including exchange packet handlers at `0x004ad611`, `0x004ad739`, `0x004addd3`, and `0x004adf51`, plus constructor/destructor/clear/close helpers at `0x004b0490`, `0x004b0860`, `0x004b09d0`, and `0x004b0b20`.
