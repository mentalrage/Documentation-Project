*** UID:0000UL | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// [UID:0000UL] no standalone packet/record helper-family body.
// Exact modeled helper children and raw-island marker pages own output; do not emit duplicate raw helper C++ from this grouping page.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0

## Status

- Confidence: strong for exact child pages covering `0x004a23d0`, `0x004a2450`, `0x004a2f60`, `0x004a34d0`, `0x004a3a90`, and `0x004a3e10`; medium-high for the raw helper islands at `0x004a3650-0x004a3a90` and `0x004a3be0-0x004a3e10`.
- IDA caveat: `0x004a3650` and `0x004a3be0` islands contain coherent function-shaped bodies, but IDA has no function objects or direct xrefs to those starts. UID0003L0 and UID0003L2 now have exact raw-island boundaries and formal no-code markers; original callable entries and source-facing helper names remain unproved.
- Proposed owner file: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- Exact memory range: [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- Rebuild handling: marked reconstructable and attached to [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md); this grouping page keeps blank C++ because exact children own emission. UID0003L0 uses a formal covered-by/no-code marker and UID0003L2 uses a formal no-body marker; raw helper bodies remain rejected because original callable entries and source-facing helper names are unproved.

## Helper Summary

| Address range | Proposed name | Behavior |
| --- | --- | --- |
| [UID:0003KS][0x004a23d0-0x004a23ef.EmployeeDialogPacketLoadPredicate](by-memory/0x004a23d0-0x004a23ef.EmployeeDialogPacketLoadPredicate.md) | `IsEmployeeDialogLoadPacket` | File-local predicate for inbound employee response packets: byte `0x4f`, subcommand `1`, and zero at packet offset `6`. |
| [UID:0003KT][0x004a2450-0x004a2531.EmployeeInventoryItemCommandHelper](by-memory/0x004a2450-0x004a2531.EmployeeInventoryItemCommandHelper.md) | `HandleEmployeeInventoryItem` | Looks up selected item metadata through [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical `dword_67A748`, clears `this[264]`, opens [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md) when the item requires a count, or sends employee command `5` directly. |
| [UID:0003KX][0x004a2f60-0x004a322c.EmployeeDialogPanePacketDispatcher](by-memory/0x004a2f60-0x004a322c.EmployeeDialogPanePacketDispatcher.md) | `HandleEmployeeDialogPacket` | Handles employee response packet `0x4f/0x01`, validates the employee entity id at `this+0x7a8`, dispatches cases `0..4`, and repaints after record/status mutations. |
| [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md) | `DeserializeEmployeeRecord` | Parses one variable-length employee record into a `0x41c` `EmployeeRecord`, converts the name to wide text, appends percent text when the packet percent byte is not `0xff`, and returns bytes consumed. |
| [UID:0003L0][0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers](by-memory/0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers.md) | raw packet helper island | Record-field parser plus raw opcode `0x54` command writers for command kinds `0..5`; no IDA function objects/direct xrefs at the helper starts. B005 added a formal covered-by/no-code marker, not raw helper bodies. |
| [UID:0003L1][0x004a3a90-0x004a3bdf.EmployeeDialogPaneLoadEmployeeData](by-memory/0x004a3a90-0x004a3bdf.EmployeeDialogPaneLoadEmployeeData.md) | `LoadEmployeeData` | Parses the full employee-list packet, allocates the `0x41c * count` record array, calls the parser for each record, and rebuilds the visible slot list. |
| [UID:0003L2][0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers](by-memory/0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers.md) | raw record mutation island | First raw body upserts a parsed record; second raw body at `0x004a3ca0` removes/marks a record, rebuilds visible slots, and repaints. B006 2026-06-29 moved the exact target to `88/90` with a formal no-body marker, not raw helper C++. |
| [UID:0003L3][0x004a3e10-0x004a4057.EmployeeDialogPaneUpdateEmployeeFields](by-memory/0x004a3e10-0x004a4057.EmployeeDialogPaneUpdateEmployeeFields.md) | `UpdateEmployeeFields` | Applies name/status/field updates to one existing record and rebuilds the visible slot list. |

## IDA MCP Evidence

Checked on 2026-06-03 after IDA MCP restart:

- `lookup_funcs` reports real functions for `0x004a2450` (`sub_4A2450`, size `0xe1`), `0x004a2f60` (`sub_4A2F60`, size `0x2cc`), `0x004a34d0` (`sub_4A34D0`, size `0x174`), `0x004a3a90` (`sub_4A3A90`, size `0x14f`), and `0x004a3e10` (`sub_4A3E10`, size `0x247`); `0x004a3be0` and `0x004a4ae0` still report `Not a function`.
- `xrefs_to 0x004a2450` is empty; `xrefs_to 0x004a2f60` is the employee-dialog vtable/data slot at `0x00618f70`; `xrefs_to 0x004a34d0` are `0x004a300d`, `0x004a3bb1`, and raw `0x004a3c05`; `xrefs_to 0x004a3be0` is empty.
- `xrefs_to 0x004a4770` confirms quantity-dialog construction from `0x004a24f2` in `sub_4A2450`, `0x004a32b6` in `sub_4A3240`, and `0x004a4c5e` in `sub_4A4B20`.
- `callees 0x004a2450` includes item metadata lookup `0x005a3870`, object allocation `0x004f4aa0`, quantity dialog constructor `0x004a4770`, and employee command sender `0x005975e0`.
- `callees 0x004a2f60` includes `0x004a34d0`, `0x004a3a90`, `0x004a3e10`, `0x004a33e0`, string/buffer helpers, and `MultiByteToWideChar`.
- Live decompilation of `0x004a2450` still matches the selected-inventory-item helper: it clears `this[264]`, checks item metadata byte `+492`, opens a quantity prompt with localized string id `247` when needed, or sends command `5` directly with the selected item slot and metadata dword `+488`.
- Live decompilation of `0x004a2f60` still matches the employee response dispatcher: it checks packet bytes `0x4f` and `0x01`, validates the employee entity id at `this+0x7a8`, then handles cases `0..4` for full load, upsert, remove, field update, and status text.
- Raw disassembly at `0x004a3be0-0x004a3c9d` still shows a complete helper-shaped body: stack frame `0x420`, call to `sub_4A34D0` at `0x004a3c05`, record count at `this+0x538`, record array at `this+0x84c`, stride `0x41c`, `rep movsd` with `0x107` dwords, selection-list rebuild through `0x004a33e0`, and repaint through vtable slot `+0x20`.
- 2026-06-12 A004 follow-up split exact child pages for every modeled helper in this family and added raw-island children for `0x004a3650-0x004a3a90` and `0x004a3be0-0x004a3e10`. Live disassembly confirmed the second raw record-removal body starts at `0x004a3ca0` and returns at `0x004a3e09`, with `align 10h` before `sub_4A3E10`.
- 2026-06-14 A001 live IDA MCP session `a001_goal2_class_batch` reconfirmed active `NexusTK.exe.i64`, modeled helper sizes `0xe1` / 225, `0x2cc` / 716, `0x174` / 372, `0x14f` / 335, and `0x247` / 583 bytes; no function objects at `0x004a3650`, `0x004a3be0`, or `0x004a3ca0`; parser xrefs at `0x004a300d`, `0x004a3bb1`, and raw `0x004a3c05`; quantity-dialog constructor refs at `0x004a24f2`, `0x004a32b6`, and `0x004a4c5e`; and unchanged raw-island caveats.
- 2026-06-16 A001 live IDA MCP session `b001_selflookpane_0001H7_20260616` reconfirmed active `NexusTK.exe.i64`, modeled helper sizes `0xe1`, `0x2cc`, `0x174`, `0x14f`, and `0x247`; no IDA function objects at raw starts `0x004a3650`, `0x004a37a0`, `0x004a3830`, `0x004a38d0`, `0x004a3960`, `0x004a39d0`, `0x004a3a30`, `0x004a3be0`, or `0x004a3ca0`; and the same vtable/data xref for the dispatcher at `0x00618f70`.
- 2026-06-16 compact analysis reconfirmed `0x004a2450` has no callers or xrefs, calls item metadata/dialog/command helpers, and carries constants `0x274` / 628 and command `5`; `0x004a2f60` is vtable-referenced and calls the parser, list rebuild, full-load, and field-update helpers; `0x004a34d0` is called from `0x004a300d`, `0x004a3bb1`, and raw `0x004a3c05`; `0x004a3a90` is called from the constructor and dispatcher; and `0x004a3e10` is called from dispatcher `0x004a313e`.
- A 2026-06-16 PE byte scan found no absolute VA/RVA pointer hits and no rel32 branches to the raw starts `0x004a3650`, `0x004a37a0`, `0x004a3830`, `0x004a38d0`, `0x004a3960`, `0x004a39d0`, `0x004a3a30`, `0x004a3be0`, or `0x004a3ca0`. It found the expected modeled-helper reachability: `0x004a34d0` called from `0x004a300d`, `0x004a3bb1`, and raw `0x004a3c05`; `0x004a3a90` called from `0x004a1ff4` and `0x004a2fe0`; `0x004a3e10` called from `0x004a313e`; and `0x004a2f60` stored at vtable/data address `0x00618f70`.
- 2026-06-16 byte reads confirm function-shaped raw prologues at `0x004a3650`, `0x004a37a0`, `0x004a3830`, `0x004a38d0`, `0x004a3960`, `0x004a3be0`, and `0x004a3ca0`; lightweight no-frame command-writer prologues at `0x004a39d0` and `0x004a3a30`; twelve `0xcc` bytes between `sub_4A34D0` and raw `0x004a3650`; and four `0xcc` bytes between the raw `0x004a3ca0` body tail and `sub_4A3E10`.

Checked on 2026-05-30:

- `ida_funcs.get_func` reports `sub_4A2450` as `0x004a2450-0x004a2531` size `225`, `sub_4A2F60` as `0x004a2f60-0x004a322c` size `716`, and `sub_4A34D0` as `0x004a34d0-0x004a3644` size `372`.
- `0x004a2450` has no direct xrefs. Hex-Rays shows it reading the selected item id from the packet byte, using [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) item metadata, opening quantity dialog object id `628` for count-required items, otherwise sending command `5` with item slot/count data.
- `0x004a2f60` has a data/vtable xref at `0x00618f70` and no direct code callers. Hex-Rays shows packet-byte gates `0x4f` then `0x01`, entity-id validation against `this+0x7a8`, and a five-case subcommand switch.
- `0x004a2f60` case `0` loads the full list through `sub_4A3A90`; case `1` upserts a parsed record and repaints; case `2` marks a matching record removed by clearing id and setting state word `1`; case `3` delegates to `sub_4A3E10`; case `4` copies a multibyte status string into a wide buffer at `this+0x4a8` and repaints.
- `0x004a34d0` is called from `0x004a300d` in `sub_4A2F60`, `0x004a3bb1` in `sub_4A3A90`, and raw code at `0x004a3c05`. Hex-Rays shows it writing id, state, flag, wide name, display percent suffix, and trailing DWORD fields at `0x40c`, `0x410`, and `0x414`.
- `ida_funcs.get_func(0x004a3be0)` returns no function and xrefs to that start are empty. Disassembly still shows a full prologue/body: stack allocation `0x420`, call to `sub_4A34D0`, scan of `[this+0x538]` records at `[this+0x84c]` with stride `0x41c`, record copy via `rep movsd`/`0x107` dwords, call to `sub_4A33E0`, and a repaint/invalidate virtual call through vtable offset `+0x20`.

## Ownership Decision

These helpers belong with `EmployeeDialogPane.cpp`. They should not be folded into generic packet infrastructure or `ItemDialogs.cpp`: every data path references the employee dialog entity id, employee record array, selected-slot state, or employee command interface.

The grouping page intentionally stays blank. Source-bearing code is carried by exact modeled children such as [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md) and [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md), while UID0003L0 and UID0003L2 carry only formal no-code markers for raw islands. Per-start raw helper splits, raw byte islands, and invented helper bodies remain rejected.

The page is attached directly to [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) because that parent has a validated `NexusTK/ui/dialogs/` path at `90/88`, and the live helper evidence is confined to employee-dialog state. This by-item page keeps C++ blank, but UID0003L0 no longer remains a blank/unresolved emitter: it now carries a formal covered-by marker until a real callable route and source-facing helper identity are proven.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page links exact children for the packet predicate, inventory helper, dispatcher, parser, raw packet helper island, full load, raw record mutation island, and update-fields helper, and now records current raw-start no-function/no-pointer/no-branch evidence plus UID0003L0/UID0003L2 formal marker disposition. It remains below final-audit range because two islands are still raw code rather than IDA functions. |
| Confidence | 89 | Live IDA and PE scans reconfirm real function objects, employee-dialog vtable slots, modeled helper callers, parser callers including raw `0x004a3c05`, raw packet-command bodies, and the corrected raw record-mutation extent through `0x004a3e10`. Confidence is capped by unproved original callable entries and exact original helper names, not by unresolved raw-island boundaries. |
| Reconstructable | true | These are source-owned employee-dialog helpers. This by-item C++ remains intentionally blank because it is a grouping page, while UID0003L0 uses a formal covered-by/no-code marker and UID0003L2 uses a formal no-body marker instead of raw helper bodies. |

## Cross-References

- [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md)
- [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md)
- [UID:000138][0x004a1d70-0x004a4e6b.EmployeeDialogPanes](by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md)
- [UID:0003KS][0x004a23d0-0x004a23ef.EmployeeDialogPacketLoadPredicate](by-memory/0x004a23d0-0x004a23ef.EmployeeDialogPacketLoadPredicate.md)
- [UID:0003KT][0x004a2450-0x004a2531.EmployeeInventoryItemCommandHelper](by-memory/0x004a2450-0x004a2531.EmployeeInventoryItemCommandHelper.md)
- [UID:0003KX][0x004a2f60-0x004a322c.EmployeeDialogPanePacketDispatcher](by-memory/0x004a2f60-0x004a322c.EmployeeDialogPanePacketDispatcher.md)
- [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md)
- [UID:0003L0][0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers](by-memory/0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers.md)
- [UID:0003L1][0x004a3a90-0x004a3bdf.EmployeeDialogPaneLoadEmployeeData](by-memory/0x004a3a90-0x004a3bdf.EmployeeDialogPaneLoadEmployeeData.md)
- [UID:0003L2][0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers](by-memory/0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers.md)
- [UID:0003L3][0x004a3e10-0x004a4057.EmployeeDialogPaneUpdateEmployeeFields](by-memory/0x004a3e10-0x004a4057.EmployeeDialogPaneUpdateEmployeeFields.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0001UD][EmployeeRecord](by-type/by-struct/EmployeeRecord.md)
- [UID:0001XH][EmployeeDialogPaneVtables](by-type/by-vtable/EmployeeDialogPaneVtables.md)

## Changes

- 2026-06-29 B006 raw record mutation marker sync:
  - Score unchanged at `86/89`; owner/emitter remain [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), and this grouping page keeps blank C++.
  - Summary/evidence: updated the UID0003L2 row and ownership/reconstructable wording to reflect the accepted formal no-body marker in [UID:0003L2][0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers](by-memory/0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers.md). Current MCP session `967f0703` reconfirmed zero raw-start function/xref/pointer routes, exact two-body boundaries, `0x41c` stride, and `0x107` copy. UID0003L2 is now `88/90`; raw helper bodies and per-body splits remain rejected because original callable entries/source-facing helper names remain unproved.
- 2026-06-29 B005 raw packet helper marker sync:
  - Score unchanged at `86/89`; owner/emitter remain [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), and this grouping page keeps blank C++.
  - Summary/evidence: updated the UID0003L0 row and ownership/reconstructable wording to reflect the accepted formal covered-by/no-code marker in [UID:0003L0][0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers](by-memory/0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers.md). Current MCP session `967f0703` reconfirmed zero raw-start function/xref/pointer routes; source-bearing behavior stays covered by [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md) and [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md), so full raw helper bodies and per-start splits remain rejected.
- 2026-06-14 A001 Goal 2 by-item score pass:
  - Score remains `85/88`; owner/emitter remain [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md).
  - Summary/evidence: live IDA MCP reconfirmed current modeled helper sizes, vtable/caller refs, parser caller set, quantity-dialog constructor refs, and the absence of IDA function objects for raw helper starts `0x004a3650`, `0x004a3be0`, and `0x004a3ca0`. Completion is not raised because the raw helper entry boundaries and final helper names remain unresolved; the by-item coverage row was stale and now needs the existing `85%` row.
- 2026-06-16 A001 Goal 2 by-item evidence refresh:
  - Before: score `85/88`; owner/emitter remained [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md), and final C++ was blank for raw-boundary/source-name blockers.
  - Changed to: score `86/89`; owner/emitter and blank final C++ unchanged.
  - Evidence: live IDA MCP reconfirmed modeled helper sizes and xrefs, no IDA functions at all raw packet/record helper starts, parser/list/update reachability, and dispatcher vtable storage. PE scanning found no VA/RVA pointer hits or rel32 branches to the raw starts while confirming the expected modeled-helper calls. Byte reads reconfirmed raw prologues and alignment around the raw islands.
- 2026-06-12 A004 Goal 2 helper split:
  - Before: score `78/86`, the helper summary still used broad/raw address rows, and raw `0x004a3be0` was underbounded to the first body.
  - After: score `85/88`; helper rows link exact child pages and raw record mutation coverage extends through the second raw body at `0x004a3ca0-0x004a3e10`.
  - Evidence: live IDA confirmed modeled helper sizes, vtable/caller refs, raw packet helper body starts, raw record mutation tail, opcode constants, and the `0x41c` record stride.
- 2026-06-07: Replaced the raw selected-item metadata global with canonical [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) wording.
  - Before: `HandleEmployeeInventoryItem` described selected inventory metadata through historical `dword_67A748` only.
  - After: the helper summary and IDA evidence link the resolved collection-data global while keeping the old name as traceability in the table.
  - Evidence: the generated resolved-name report maps `dword_67A748` to `g_pCollectionData`, and the existing IDA evidence shows `0x004a2450` using that metadata path for count-required employee inventory items.

- 2026-06-03 live IDA refresh:
  - Changed to: `COMPLETION:78`, `CONFIDENCE:86`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000J0`.
  - Reason: the page now has current live IDA verification for function bounds, xrefs, callees, decompiled helper behavior, raw `0x004a3be0` instructions, owner attachment, and final-C++ caveats.
  - Evidence: IDA MCP reports real functions at `0x004a2450`, `0x004a2f60`, `0x004a34d0`, `0x004a3a90`, and `0x004a3e10`; no function/xrefs for `0x004a3be0`; parser callers at `0x004a300d`, `0x004a3bb1`, and raw `0x004a3c05`; and raw `0x004a3be0-0x004a3c9d` instructions matching parse, search/upsert, `0x41c` record copy, rebuild, and repaint behavior.
- Before: the page had `COMPLETION:0` and `CONFIDENCE:0`, used older 2026-05-24/25 evidence, and described `0x004a3be0` with less precise raw-code wording.
- Changed to: `COMPLETION:70` and `CONFIDENCE:82`, with current IDA-backed function bounds, xrefs, dispatcher cases, and raw-code caveat for `0x004a3be0`.
- Summary/evidence: IDA MCP on 2026-05-30 confirmed real function objects for `0x004a2450`, `0x004a2f60`, and `0x004a34d0`, confirmed only a data/vtable xref for `0x004a2f60`, confirmed `0x004a34d0` callers including raw `0x004a3c05`, and confirmed no function object/xrefs for `0x004a3be0` despite coherent update-record instructions.
