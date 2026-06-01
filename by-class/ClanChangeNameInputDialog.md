*** UID:000028 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanChangeNameInputDialog

## Status

- Confidence: medium overall: strong for submit behavior and vtable identity; projected constructor start remains unresolved.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Current recovered file: `source-3/simroot_v2/class_ClanChangeNameInputDialog.cpp`
- Vtable anchors: primary `0x00615cb8`, secondary `0x00615d1c`, tertiary `0x00615d4c`

## Class Purpose

`ClanChangeNameInputDialog` sends a clan rename packet for the submitted clan name.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw/projected constructor | [UID:0002O1][0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor](by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md) `0x004894d0-0x00489505` | Constructor-shaped bytes; IDA reports no function, inbound xrefs, or raw pointer hits at this start. |
| `OnSubmitText` | [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md) `0x00489510-0x004895fe` | Converts the new name and sends opcode `0x4b`, subtype `10`, action `1`, length-prefixed name. |

## Evidence Notes

- IDA confirms the submitter at `0x00489510`.
- 2026-05-26 IDA MCP recheck reports `0x00489510` as a real function of size `0xee`; decompilation writes opcode `75` (`0x4b`), subtype `10`, action `1`, then a length-prefixed multibyte name. IDA xrefs primary vtable `0x00615cb8` at `0x00485337`, `0x0048842e`, and projected store `0x004894e2`.
- This class is separate from `ClanChangeInputDialog`, which submits the multi-field attribute-change packet through helper `0x00486330`.
- 2026-05-27 IDA MCP family pass found no inbound xrefs or raw dword pointer hits to `0x004894d0`. Disassembly at the projected start still calls base `0x00488b40` and stores `0x00615cb8` at `0x004894e2` plus `0x00615d1c` at `0x004894ea`, so keep it as constructor-shaped bytes pending boundary cleanup.

## Changes

- 2026-05-27: Corrected `OnSubmitText` range from `0x00489510-0x004895fd` to the exclusive range `0x00489510-0x004895fe`. Evidence: IDA MCP reports `sub_489510` size `0xee` and two `0xcc` alignment bytes at `0x004895fe-0x00489600`.
- What existed before: the page documented rename submit behavior, vtable identity, range correction, and projected constructor caveat, but metadata was still `0/0`.
- What it was changed to: scores were set to `68/76`.
- Summary and evidence: the submitter and vtable references are documented; constructor reachability and full class/source layout remain unresolved.
- 2026-05-31: Replaced raw constructor/submitter addresses with exact child `by-memory` pages. Evidence: IDA MCP `lookup_funcs`, vtable `xrefs_to`, disassembly, and byte audit confirm the raw constructor range `0x004894d0-0x00489505`, submitter range `0x00489510-0x004895fe`, and alignment padding around both.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:00010K][0x00488fe0-0x004895fe.ClanNameDialogSubmitters](by-memory/0x00488fe0-0x004895fe.ClanNameDialogSubmitters.md)
- [UID:0002O1][0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor](by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md)
- [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md)
- [UID:00002J][ClanNameInputDialog](by-class/ClanNameInputDialog.md)
- [UID:000027][ClanChangeInputDialog](by-class/ClanChangeInputDialog.md)
