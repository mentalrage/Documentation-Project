*** UID:000027 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanChangeInputDialog

## Status

- Confidence: strong for submit behavior, vtable identity, and exact child pages; raw constructor reachability remains unresolved.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Layout docs: [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- Reconstruction parent: [UID:0000I8][Clan](by-file/Clan.md)

## Score Rationale

- Completion is `82` because the class now has exact raw-constructor and submitter child pages, linked base-dialog layout evidence, vtable data references, helper dependency evidence, and source-module parent routing.
- Confidence is `88` because live IDA confirms the raw constructor bytes, vtable stores, submitter slot, helper callee, and inherited field offsets; the remaining uncertainty is raw constructor reachability and final header/source spelling.

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
- 2026-05-31 IDA MCP split the constructor-shaped body and submitter into exact child pages. `lookup_funcs` reports no function at `0x00489ff0` and function `0x0048a030` size `0x29`; `xrefs_to(0x0048a030)` reports vtable slot `0x00615ef4`; `callees(0x0048a030)` reports `0x00486330`; decompilation confirms offsets `+0x26c`, `+0x46c`, `+0x66c`, and `+0x86c`; byte audit confirms padding around the child ranges.
- 2026-06-05 live IDA MCP recheck confirms no function/xrefs/pointer hits at `0x00489ff0`, exact constructor bytes through `retn 4`, eleven-byte padding before the submitter, `ClanChangeInputDialog` vtable setup stores at `0x004852ee`/`0x004852f6`/`0x00485300`, `0x004883ed`/`0x004883f3`/`0x004883fd`, and `0x0048a002`/`0x0048a00a`/`0x0048a014`, vtable-only submitter slot `0x00615ef4`, no direct submitter callers, and callee [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md).

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:0002MN][0x006158f4-0x00615fd8.ClanModalDialogVtableData](by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md)
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
- 2026-06-05: Raised class coverage and attached the class to the Clan source parent.
  - Before: metadata was `76/84`, the parent was blank, and stale source-lead wording remained in the status notes.
  - After: metadata is `82/88`, `AUTOGEN_PARENT_UID` is [UID:0000I8][Clan](by-file/Clan.md), and the stale source-lead wording has been removed.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, `callers`, `callees`, decompilation, byte reads, pointer search, immediate search, and data-reference search on the raw constructor and submitter confirmed the exact child boundaries, vtable identity, helper dependency, inherited field offsets, and remaining no-reachability caveat.
