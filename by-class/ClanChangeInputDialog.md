*** UID:000027 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanChangeInputDialog

## Status

- Confidence: strong for submit behavior, vtable identity, and exact child pages; raw constructor reachability remains unresolved.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Layout docs: [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- Current recovered file: `source-3/simroot_v2/class_ClanChangeInputDialog.cpp`

## Class Purpose

`ClanChangeInputDialog` is a derived `ClanAttrInputDialog` that submits multi-field clan attribute changes: clan name, description, flag/text field, and clan type.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw constructor | [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md) | Constructor-shaped bytes; IDA reports no function, inbound xrefs, or raw pointer hits at this start. |
| `SubmitClanChange` | [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange.md) | Reads stored fields from the base attribute dialog and calls helper [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md). |

## Evidence Notes

- IDA confirms `SubmitClanChange` at `0x0048a030`.
- IDA confirms helper `0x00486330` is called from `0x0048a053` and sends opcode `0x4b`, subtype `10`, action `2`, three strings, and a 16-bit value.
- 2026-05-26 IDA decompilation confirms the submitter passes `ClanAttrInputDialog` storage at `+0x26c`, `+0x46c`, `+0x66c`, and the 16-bit value at `+0x86c`.
- 2026-05-27 IDA MCP family pass found no inbound xrefs or raw dword pointer hits to `0x00489ff0`. Disassembly at the projected start still calls base `0x00489600` and stores `0x00615e98` at `0x0048a002` plus `0x00615efc` at `0x0048a00a`, so keep it as constructor-shaped bytes pending boundary cleanup.
- 2026-05-31 IDA MCP split the constructor-shaped body and submitter into exact child pages. `lookup_funcs` reports no function at `0x00489ff0` and `sub_48A030` size `0x29`; `xrefs_to(0x0048a030)` reports vtable slot `0x00615ef4`; `callees(0x0048a030)` reports `0x00486330`; decompilation confirms offsets `+0x26c`, `+0x46c`, `+0x66c`, and `+0x86c`; byte audit confirms padding around the child ranges.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md)
- [UID:00010M][0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters](by-memory/0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters.md)
- [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md)
- [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange.md)
- [UID:000024][ClanAttrInputDialog](by-class/ClanAttrInputDialog.md)
- [UID:000028][ClanChangeNameInputDialog](by-class/ClanChangeNameInputDialog.md)

## Changes

- What existed before: the page documented derived submit behavior, base field offsets, vtable anchors, and projected constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were initially set to `70/76`.
- Summary and evidence: submit behavior and helper linkage are clear, but the constructor remains raw/projected with no reachability and the derived class layout/header remains incomplete.
- 2026-05-31: Replaced raw address/projection entries with exact child pages and marked the class reconstructable but unassigned.
  - Before: the method table listed projected constructor `0x00489ff0` and submitter `0x0048a030-0x0048a058` without exact child-page links.
  - After: the page links [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md) and [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogSubmitClanChange.md), with scores raised to `76/84`.
  - Summary and evidence: IDA MCP `lookup_funcs`, `xrefs_to`, `callees`, decompilation, raw constructor disassembly, and byte audit confirm exact child boundaries, vtable ownership, base field offsets, and surrounding padding.
