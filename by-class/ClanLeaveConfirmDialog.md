*** UID:00002I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanLeaveConfirmDialog

## Status

- Confidence: strong for confirm/cancel behavior, vtable identity, and exact child pages; raw constructor reachability remains unresolved.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Current recovered file: `source-3/simroot_v2/class_ClanLeaveConfirmDialog.cpp`

## Class Purpose

`ClanLeaveConfirmDialog` is an `AlertPane`-derived confirmation dialog for leaving a clan. Its confirm and cancel callbacks send the corresponding accept/cancel byte through `SendClanLeaveResponse`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw constructor | [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md) | Constructor-shaped bytes; IDA reports no function, inbound xrefs, or raw pointer hits at this start. |
| `OnConfirm` | [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md) | Calls [UID:00010D][0x00485700-0x00485778.SendClanLeaveResponse](by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md) with `1`. |
| `OnCancel` | [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md) | Calls [UID:00010D][0x00485700-0x00485778.SendClanLeaveResponse](by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md) with `0`. |

## Evidence Notes

- IDA confirms `OnConfirm` and `OnCancel`.
- IDA confirms `SendClanLeaveResponse` at `0x00485700`, with callers from both callbacks.
- 2026-05-27 IDA MCP family pass found no inbound xrefs or raw dword pointer hits to `0x0048a060`. Disassembly at the projected start calls `AlertPane` constructor `0x0049feb0` and stores `0x00615f38` at `0x0048a07b`, `0x00615fa0` at `0x0048a083`, and `0x00615fd0` at `0x0048a08d`, so keep it as constructor-shaped bytes pending boundary cleanup.
- 2026-05-31 IDA MCP split the constructor-shaped body and callbacks into exact child pages. `lookup_funcs` reports no function at `0x0048a060`, `sub_48A0A0` size `0x0e`, and `sub_48A0B0` size `0x0e`; vtable data xrefs are `0x00615f94` and `0x00615f98`; both callbacks call `0x00485700`; decompilation shows constants `1` and `0`; byte audit confirms padding around the child ranges.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:00010D][0x00485700-0x00485778.SendClanLeaveResponse](by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md)
- [UID:00010M][0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters](by-memory/0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters.md)
- [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md)
- [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md)
- [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md)

## Changes

- What existed before: the page documented confirm/cancel behavior, leave-response helper linkage, and projected constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were initially set to `66/76`.
- Summary and evidence: confirm/cancel callbacks and vtable identity are clear; constructor reachability, full alert layout, and final source form remain unresolved.
- 2026-05-31: Replaced raw address/projection entries with exact child pages and marked the class reconstructable but unassigned.
  - Before: the method table listed projected constructor `0x0048a060`, confirm `0x0048a0a0-0x0048a0ad`, and cancel `0x0048a0b0-0x0048a0bd` without exact child-page links.
  - After: the page links [UID:0002O6][0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor](by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md), [UID:0002O7][0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm](by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md), and [UID:0002O8][0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel](by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md), with scores raised to `74/84`.
  - Summary and evidence: IDA MCP `lookup_funcs`, `xrefs_to`, `callees`, decompilation, raw constructor disassembly, and byte audit confirm exact child boundaries, vtable ownership, leave-response constants, and surrounding padding.
