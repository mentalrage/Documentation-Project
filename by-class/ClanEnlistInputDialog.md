*** UID:00002B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ClanEnlistInputDialog

## Status

- Confidence: strong for packet parsing/submit behavior, vtable identity, and exact child memory pages; constructor-shaped bytes are bounded but still lack an IDA function object or inbound xrefs.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Reconstruction parent: [UID:0000I8][Clan](by-file/Clan.md)

## Score Rationale

- Completion is `82` because the class now has exact raw-constructor and submitter child pages, linked base-dialog layout evidence, vtable data references, packet-handler context, and source-module parent routing.
- Confidence is `88` because live IDA confirms the raw constructor bytes, vtable stores, submitter slot, helper callee, and inherited field offsets; the remaining uncertainty is raw constructor reachability and final header/source spelling.

## Class Purpose

`ClanEnlistInputDialog` handles the clan enlistment modal flow. It owns the raw derived constructor-shaped body and the submitter that sends three text fields plus a 16-bit attribute through the shared Clan attribute packet helper; related clan status packet parsing is coordinated through `ClanStatusPane`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `HandleEnlistRequestPacket` | [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md) subrange `0x004877d0-0x004879d7` | Decodes clan name and request text, fills a text control, and switches dialog state. |
| `HandleEnlistListPacket` | [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md) subrange `0x004879e0-0x00487c36` | Parses list packet and inserts clan names into a list control. |
| `HandleMemberListOrCreatePacket` | [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md) subrange `0x00487ea0-0x00488166` | Parses member/list or create-result packet data and updates dialog state. |
| raw constructor | [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md) | Constructor-shaped bytes; IDA reports no function, inbound xrefs, or raw pointer hits at this start. |
| `SubmitEnlistment` | [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md) | Calls `SendClanAttributePacket` for enlistment submission. |

## Evidence Notes

- IDA confirms `0x004877d0`, `0x004879e0`, `0x00487ea0`, and `0x00489fc0`.
- IDA reports no function at raw constructor start `0x00489f80`.
- 2026-06-05 IDA MCP correction: [UID:00010B][0x004842b0-0x00484a50.ClanAttributePacketParser](by-memory/0x004842b0-0x00484a50.ClanAttributePacketParser.md) is not a `ClanEnlistInputDialog` receiver. The `ClanStatusPane` dispatcher passes `this - 0xa0`, and the parser body calls [UID:00021O][0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes](by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md) and writes `ClanStatusPane` state/text storage.
- The submitter shares the same storage model as `ClanAttrInputDialog` and `ClanChangeInputDialog`, so the enlistment modal still belongs in the Clan feature module.
- 2026-05-27 IDA MCP boundary pass bounded the constructor-shaped bytes as [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md). The body calls base [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md), stores `0x00615df8`, `0x00615e5c`, and `0x00615e8c`, then returns at `0x00489fb5`; IDA still reports no function object or inbound xrefs at the start.
- 2026-05-31 IDA MCP split the submitter into [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md). Evidence: `lookup_funcs` reports function `0x00489fc0` size `0x29`, vtable data xref `0x00615e54`, no direct callers, callee `0x00485ac0`, and decompilation passes offsets `+0x26c`, `+0x46c`, `+0x66c`, and `+0x86c`.
- 2026-05-27 IDA MCP correction: earlier ownership notes modeled `0x00487370` as `ClanEnlistInputDialog::HideAllControls`. IDA callers and child-pane offsets show that function is [UID:00021O][0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes](by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md), not a `ClanEnlistInputDialog` method.
- 2026-06-05 live IDA MCP recheck confirms no function/xrefs/pointer hits at `0x00489f80`, exact constructor bytes through `retn 4`, eleven-byte padding before the submitter, `ClanEnlistInputDialog` vtable setup stores at `0x00487f34`/`0x00487f3a`/`0x00487f44` and `0x00489f92`/`0x00489f9a`/`0x00489fa4`, vtable-only submitter slot `0x00615e54`, no direct submitter callers, and callee [UID:00010E][0x00485ac0-0x00485cbd.SendClanAttributePacket](by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md).

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:0002MN][0x006158f4-0x00615fd8.ClanModalDialogVtableData](by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md)
- [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md)
- [UID:00010E][0x00485ac0-0x00485cbd.SendClanAttributePacket](by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md)
- [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md)
- [UID:00010M][0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters](by-memory/0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters.md)
- [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md)
- [UID:00021O][0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes](by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md)
- [UID:000024][ClanAttrInputDialog](by-class/ClanAttrInputDialog.md)
- [UID:000027][ClanChangeInputDialog](by-class/ClanChangeInputDialog.md)

## Changes

- 2026-05-27: Removed `0x00487370-0x004873b5` as `ClanEnlistInputDialog::HideAllControls`. Changed it to [UID:00021O][0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes](by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md), owned by `ClanStatusPane`. Evidence: IDA callers are in [UID:00010B][0x004842b0-0x00484a50.ClanAttributePacketParser](by-memory/0x004842b0-0x00484a50.ClanAttributePacketParser.md) and [UID:00010C][0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput](by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md), the function touches `ClanStatusPane` child offsets `+0x2510/+0x2514/+0x2518`, and IDA vtable scans found no `0x00487370` entry in `ClanEnlistInputDialog` vtables.
- 2026-05-27: Changed the constructor note from unbounded projected start `0x00489f80` to bounded raw constructor [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md). Evidence: IDA MCP byte audit shows constructor prologue at `0x00489f80`, base call to `0x00489600`, `ClanEnlistInputDialog` vtable stores at `0x00489f92`, `0x00489f9a`, and `0x00489fa4`, then `retn 4` ending at `0x00489fb5`.
- What existed before: the page documented packet parsing, submit behavior, constructor bounding, and a wrong-owner correction, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were initially set to `74/80`.
- Summary and evidence: parser/handler/submission behavior and vtable identity are documented; raw constructor reachability and final layout/header details remain open.
- 2026-05-31: Replaced the submitter raw address with the exact [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogSubmitEnlistment.md) child page and marked the class reconstructable but unassigned.
  - Before: the method table and cross-reference list pointed at aggregate [UID:00010M][0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters](by-memory/0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters.md) or raw address `0x00489fc0`.
  - After: the page links the exact submitter range, records the vtable/callee/field-offset evidence, and raises scores to `76/84`.
  - Summary and evidence: IDA MCP `lookup_funcs`, `xrefs_to`, `callers`, `callees`, and decompilation confirm the exact `0x00489fc0-0x00489fe9` range and `SendClanAttributePacket` field arguments.
- 2026-06-05: Removed `0x004842b0-0x00484a50` from the `ClanEnlistInputDialog` method list.
  - Before: this class page treated [UID:00010B][0x004842b0-0x00484a50.ClanAttributePacketParser](by-memory/0x004842b0-0x00484a50.ClanAttributePacketParser.md) as `ClanEnlistInputDialog::ParseClanAttributePacket`.
  - After: the page leaves the parser with `ClanStatusPane` and keeps this class focused on the raw derived constructor, enlistment submitter, and remaining packet-handler caveats.
  - Summary and evidence: live IDA MCP shows dispatcher case `0` passes the adjusted `ClanStatusPane` pointer (`this - 0xa0`), and the parser body calls `ClanStatusPaneRefreshChildPanes` and writes status-pane storage.
- 2026-06-05: Raised class coverage and attached the class to the Clan source parent.
  - Before: metadata was `76/84`, the parent was blank, and stale source-lead wording remained in the status/evidence notes.
  - After: metadata is `82/88`, `AUTOGEN_PARENT_UID` is [UID:0000I8][Clan](by-file/Clan.md), and the stale source-lead wording has been removed.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, `callers`, `callees`, decompilation, byte reads, pointer search, immediate search, and data-reference search on the raw constructor and submitter confirmed the exact child boundaries, vtable identity, helper dependency, inherited field offsets, and remaining no-reachability caveat.
