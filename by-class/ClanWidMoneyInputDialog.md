*** UID:00002O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanWidMoneyInputDialog

## Status

- Confidence: medium overall: strong for submit behavior and vtable identity; projected constructor start remains unresolved.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Current recovered file: `source-3/simroot_v2/class_ClanWidMoneyInputDialog.cpp`
- Vtable anchors: primary `0x00615a38`, secondary `0x00615a9c`, tertiary `0x00615acc`

## Class Purpose

`ClanWidMoneyInputDialog` is a `ClanNameInputDialog` variant that sends clan-bank withdrawal requests.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw/projected constructor | [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md) `0x00489070-0x004890a5` | Constructor-shaped bytes; IDA reports no function, inbound xrefs, or raw pointer hits at this start. |
| `OnSubmitText` | [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md) `0x004890b0-0x00489132` | Converts input amount and sends opcode `0x4b`, subtype `0x0b`, action `1`, amount. |

## Evidence Notes

- IDA confirms the submitter at `0x004890b0`.
- 2026-05-26 IDA MCP recheck reports `0x004890b0` as a real function of size `0x82` and xrefs to primary vtable `0x00615a38` at `0x00485398`, `0x004884d4`, and projected store `0x00489082`.
- Constructor-specific migration should wait for boundary cleanup.
- 2026-05-27 IDA MCP family pass found no inbound xrefs or raw dword pointer hits to `0x00489070`. Disassembly at the projected start still calls base `0x00488b40` and stores `0x00615a38` at `0x00489082` plus `0x00615a9c` at `0x0048908a`, so keep it as constructor-shaped bytes pending boundary cleanup.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:0002NT][0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor](by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md)
- [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md)
- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md)

## Changes

- What existed before: the page documented withdraw-money submit behavior, vtable identity, and projected constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were set to `68/76`.
- Summary and evidence: the submitter and vtable references are documented; projected constructor reachability and final layout/source placement remain unresolved.
- 2026-05-31: Replaced raw constructor/submitter addresses with exact child `by-memory` pages and corrected the submitter end to exclusive `0x00489132`. Evidence: IDA MCP `lookup_funcs`, vtable `xrefs_to`, disassembly, and byte audit confirm the raw constructor range `0x00489070-0x004890a5`, submitter range `0x004890b0-0x00489132`, and alignment padding around both.
