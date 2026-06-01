*** UID:00002M | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanSummonNameInputDialog

## Status

- Confidence: medium overall: strong for submit behavior and vtable identity; projected constructor start remains unresolved.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Current recovered file: `source-3/simroot_v2/class_ClanSummonNameInputDialog.cpp`
- Vtable anchors: primary `0x00615b78`, secondary `0x00615bdc`, tertiary `0x00615c0c`

## Class Purpose

`ClanSummonNameInputDialog` sends a clan summon request for the submitted name.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw/projected constructor | [UID:0002NX][0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor](by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md) `0x00489270-0x004892a5` | Constructor-shaped bytes; IDA reports no function, inbound xrefs, or raw pointer hits at this start. |
| `OnSubmitName` | [UID:0002NY][0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName](by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md) `0x004892b0-0x0048939e` | Converts the wide name and sends opcode `0x4b`, subtype `8`, action `1`, length-prefixed name. |

## Evidence Notes

- IDA confirms the submitter at `0x004892b0`.
- 2026-05-26 IDA MCP recheck reports `0x004892b0` as a real function of size `0xee`; decompilation writes opcode `75` (`0x4b`), subtype `8`, action `1`, then a length-prefixed multibyte name. IDA xrefs primary vtable `0x00615b78` at `0x0048522c`, `0x00488294`, and projected store `0x00489282`.
- Constructor-specific migration should wait for boundary cleanup.
- 2026-05-27 IDA MCP family pass found no inbound xrefs or raw dword pointer hits to `0x00489270`. Disassembly at the projected start still calls base `0x00488b40` and stores `0x00615b78` at `0x00489282` plus `0x00615bdc` at `0x0048928a`, so keep it as constructor-shaped bytes pending boundary cleanup.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:0002NX][0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor](by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md)
- [UID:0002NY][0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName](by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md)
- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md)

## Changes

- What existed before: the page documented summon submit behavior, vtable identity, and projected constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were set to `68/76`.
- Summary and evidence: submitter behavior is IDA-backed and vtable-linked; projected constructor reachability and full class layout remain unresolved.
- 2026-05-31: Replaced raw constructor/submitter addresses with exact child `by-memory` pages and corrected the submitter end to exclusive `0x0048939e`. Evidence: IDA MCP `lookup_funcs`, vtable `xrefs_to`, disassembly, and byte audit confirm the raw constructor range `0x00489270-0x004892a5`, submitter range `0x004892b0-0x0048939e`, and alignment padding around both.
