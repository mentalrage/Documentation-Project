*** UID:00002D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanExpelNameInputDialog

## Status

- Confidence: medium overall: strong for submit behavior and vtable identity; projected constructor start remains unresolved.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Current recovered file: `source-3/simroot_v2/class_ClanExpelNameInputDialog.cpp`
- Vtable anchors: primary `0x00615ad8`, secondary `0x00615b3c`, tertiary `0x00615b6c`

## Class Purpose

`ClanExpelNameInputDialog` sends a clan expel request for the submitted player name.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw/projected constructor | [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md) `0x00489140-0x00489175` | Constructor-shaped bytes; IDA reports no function, inbound xrefs, or raw pointer hits at this start. |
| `SendExpelPacket` | [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md) `0x00489180-0x0048926e` | Converts the wide name to multibyte and sends opcode `0x4b`, subtype `7`, action `1`, length-prefixed name. |

## Evidence Notes

- IDA confirms the submitter at `0x00489180`.
- 2026-05-26 IDA MCP recheck reports `0x00489180` as a real function of size `0xee` and xrefs to primary vtable `0x00615ad8` at `0x004851cb`, `0x004881e4`, and projected store `0x00489152`.
- The generated constructor only describes vtable installation over `ClanNameInputDialog`; do not use `0x00489140` as an IDA-backed anchor.
- 2026-05-27 IDA MCP family pass found no inbound xrefs or raw dword pointer hits to `0x00489140`. Disassembly at the projected start still calls base `0x00488b40` and stores `0x00615ad8` at `0x00489152` plus `0x00615b3c` at `0x0048915a`, so keep it as constructor-shaped bytes pending boundary cleanup.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:0002NV][0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor](by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md)
- [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md)
- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md)

## Changes

- What existed before: the page documented expel submit behavior, vtable identity, and projected constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were set to `68/76`.
- Summary and evidence: the submitter and vtable references are strong; projected constructor reachability and full class layout/source form remain unresolved.
- 2026-05-31: Replaced raw constructor/submitter addresses with exact child `by-memory` pages and corrected the submitter end to exclusive `0x0048926e`. Evidence: IDA MCP `lookup_funcs`, vtable `xrefs_to`, disassembly, and byte audit confirm the raw constructor range `0x00489140-0x00489175`, submitter range `0x00489180-0x0048926e`, and alignment padding around both.
