*** UID:00002A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanDepMoneyInputDialog

## Status

- Confidence: medium overall: strong for submit behavior and vtable identity; constructor-shaped bytes are documented but still lack IDA function/xref reachability.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Current recovered file: `source-3/simroot_v2/class_ClanDepMoneyInputDialog.cpp`
- Vtable anchors: primary `0x00615998`, secondary `0x006159fc`, tertiary `0x00615a2c`

## Class Purpose

`ClanDepMoneyInputDialog` is a `ClanNameInputDialog` variant that sends clan-bank deposit money requests.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw/projected constructor | [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md) `0x00488fa0-0x00488fd5` | Constructor-shaped bytes; IDA reports no function, inbound xrefs, or raw pointer hits at this start. |
| `SendDepositMoneyRequest` | [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md) `0x00488fe0-0x00489062` | Converts input value and sends opcode `0x4b`, subtype `4`, action `1`, amount. |

## Evidence Notes

- IDA confirms the submitter at `0x00488fe0`.
- 2026-05-26 IDA MCP recheck reports `0x00488fe0` as a real function of size `0x82` and xrefs to primary vtable `0x00615998` at `0x00485120`, `0x00487de4`, and projected store `0x00488fb2`.
- The raw/projected constructor installs derived vtables over the shared `ClanNameInputDialog` shell but is not an IDA function start.
- 2026-05-27 IDA MCP family pass found no inbound xrefs or raw dword pointer hits to `0x00488fa0`. Disassembly at the projected start still calls base `0x00488b40` and stores `0x00615998` at `0x00488fb2` plus `0x006159fc` at `0x00488fba`, so keep it as constructor-shaped bytes pending boundary cleanup.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md)
- [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md)
- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md)

## Changes

- 2026-05-27: The constructor row previously referenced only raw `0x00488fa0`. Replaced it with [UID:00021V][0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor](by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md), the focused `0x00488fa0-0x00488fd5` raw-constructor page, and clarified that constructor shape is strong while reachability remains unresolved. Evidence: IDA MCP raw-head audit confirms the base-constructor call and vtable stores, with no function object or inbound xrefs at `0x00488fa0`.
- 2026-05-31: The submitter row previously used the raw inclusive-looking range `0x00488fe0-0x00489061`. Replaced it with exact child page [UID:0002NS][0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney](by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md). Evidence: IDA MCP `lookup_funcs` reports `sub_488FE0` size `0x82`, vtable xref `0x006159f4`, and padding beginning at `0x00489062`.
- What existed before: the page documented deposit-money submit behavior, raw constructor page linkage, vtable anchors, and reachability caveats, but metadata still read `0/0`.
- What it was changed to: scores were set to `68/76`.
- Summary and evidence: submitter behavior and raw constructor shape are documented; no-xref constructor reachability and final layout/header detail remain unresolved.
