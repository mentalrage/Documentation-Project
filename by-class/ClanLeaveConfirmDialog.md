*** UID:00002I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanLeaveConfirmDialog

## Status

- Confidence: strong for confirm/cancel behavior, vtable identity, and exact child pages; raw constructor reachability remains unresolved.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Reconstruction parent: [UID:0000I8][Clan](by-file/Clan.md)

## Score Rationale

- Completion is `82` because the class has exact child pages for the raw constructor-shaped body and both virtual callbacks, live packet-helper behavior, vtable slot evidence, and a source-module parent; it stays below final-source readiness because the constructor has no IDA function object or inbound reachability.
- Confidence is `88` because live IDA MCP confirms the callback functions, vtable slots, helper constants, packet bytes, and constructor byte stores; the remaining uncertainty is source spelling/layout around the raw constructor path.

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
- 2026-06-05 IDA MCP executable identity: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x00400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- 2026-06-05 IDA MCP recheck confirms [UID:00010D][0x00485700-0x00485778.SendClanLeaveResponse](by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md) sends exactly four bytes `{0x4b, 3, 1, response}` through the shared packet sender at `0x0067a7ec`; `OnConfirm` passes `1` and `OnCancel` passes `0`.
- 2026-06-05 IDA MCP lookup reports no function at `0x0048a060`, functions at `0x0048a0a0` and `0x0048a0b0` sized `0x0e`, [UID:00010D][0x00485700-0x00485778.SendClanLeaveResponse](by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md) size `0x79`, and the [UID:00000B][AlertPane](by-class/AlertPane.md) constructor at `0x0049feb0` size `0x6c5`.
- 2026-06-05 bounded disassembly reconfirms seven `0xcc` bytes before the constructor-shaped range, two `0xcc` bytes between each child range, and two `0xcc` bytes before the following `ClanItemDialog` body.
- 2026-06-05 IDA MCP xref search reports no inbound code/data refs and no raw pointer hits to `0x0048a060`; the constructor-shaped body still calls `0x0049feb0` and stores vtables `0x00615f38`, `0x00615fa0`, and `0x00615fd0` into the primary object and `+0xa0`/`+0xa4` subobjects.
- 2026-06-05 vtable evidence places confirm/cancel at slots `0x00615f94` and `0x00615f98`; those slots point to `0x0048a0a0` and `0x0048a0b0`, while vtable base refs come from clan status packet setup sites and the raw constructor stores.
- 2026-05-27 IDA MCP family pass found no inbound xrefs or raw dword pointer hits to `0x0048a060`. Disassembly at the projected start calls `AlertPane` constructor `0x0049feb0` and stores `0x00615f38` at `0x0048a07b`, `0x00615fa0` at `0x0048a083`, and `0x00615fd0` at `0x0048a08d`, so keep it as constructor-shaped bytes pending boundary cleanup.
- 2026-05-31 IDA MCP split the constructor-shaped body and callbacks into exact child pages. `lookup_funcs` reports no function at `0x0048a060`, callback functions at `0x0048a0a0` and `0x0048a0b0` sized `0x0e`, vtable data xrefs at `0x00615f94` and `0x00615f98`, both callbacks calling `0x00485700`, constants `1` and `0` in decompilation, and padding around the child ranges.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:00000B][AlertPane](by-class/AlertPane.md)
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
- 2026-06-05: Added exact leave-response packet evidence.
  - Before: the page recorded only that confirm/cancel call `SendClanLeaveResponse` with constants `1` and `0`.
  - After: the evidence notes record the helper's exact four-byte packet body and shared sender call.
  - Evidence: live IDA MCP decompilation of `0x00485700`, `0x0048a0a0`, and `0x0048a0b0`.
- 2026-06-05: Raised class coverage and attached the class to the Clan source parent.
  - Before: metadata was `74/84` with a blank parent and a stale source-lead path listed as if it were current recovery evidence.
  - After: metadata is `82/88`, `AUTOGEN_PARENT_UID` is [UID:0000I8][Clan](by-file/Clan.md), the stale source-lead path is removed, and the evidence now records executable identity, child sizes, vtable slots, constructor no-xref status, and packet bytes from live IDA MCP.
  - Evidence: IDA MCP `idb_meta`, `lookup_funcs`, `callers`, `callees`, `xrefs_to`, decompilation, and bounded disassembly/pointer search on `0x0048a059-0x0048a0c0`, `0x00485700`, and `0x0049feb0`.
