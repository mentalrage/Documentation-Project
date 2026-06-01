*** UID:000023 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanAppearNameInputDialog

## Status

- Confidence: medium overall: strong for submit behavior and vtable identity; projected constructor start remains unresolved.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Current recovered file: `source-3/simroot_v2/class_ClanAppearNameInputDialog.cpp`
- Vtable anchors: primary `0x00615c18`, secondary `0x00615c7c`, tertiary `0x00615cac`

## Class Purpose

`ClanAppearNameInputDialog` sends a clan appearance-name request for the submitted name.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw/projected constructor | [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md) `0x004893a0-0x004893d5` | Constructor-shaped bytes; IDA reports no function, inbound xrefs, or raw pointer hits at this start. |
| `OnConfirmInput` | [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md) `0x004893e0-0x004894ce` | Converts the wide name and sends opcode `0x4b`, subtype `9`, action `1`, length-prefixed name. |

## Evidence Notes

- IDA confirms the submitter at `0x004893e0`.
- 2026-05-26 IDA MCP recheck reports `0x004893e0` as a real function of size `0xee` and xrefs to primary vtable `0x00615c18` at `0x00485284`, `0x0048833c`, and projected store `0x004893b2`.
- This class uses `g_pNetworkManager`/`SendPacket` in generated source while sibling submitters use the queue helper; review sender normalization later.
- 2026-05-27 IDA MCP family pass found no inbound xrefs or raw dword pointer hits to `0x004893a0`. Disassembly at the projected start still calls base `0x00488b40` and stores `0x00615c18` at `0x004893b2` plus `0x00615c7c` at `0x004893ba`, so keep it as constructor-shaped bytes pending boundary cleanup.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:0002NZ][0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor](by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md)
- [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md)
- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md)

## Changes

- What existed before: the page documented clan appearance-name submit behavior and projected constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were set to `68/76`.
- Summary and evidence: the submitter and vtable identity are documented; constructor reachability, sender normalization, and complete layout/header details remain unresolved.
- 2026-05-31: Replaced raw constructor/submitter addresses with exact child `by-memory` pages and corrected the submitter end to exclusive `0x004894ce`. Evidence: IDA MCP `lookup_funcs`, vtable `xrefs_to`, disassembly, and byte audit confirm the raw constructor range `0x004893a0-0x004893d5`, submitter range `0x004893e0-0x004894ce`, and alignment padding around both.
