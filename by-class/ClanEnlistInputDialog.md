*** UID:00002B | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class ClanEnlistInputDialog : public ClanAttrInputDialog
{
public:
    explicit ClanEnlistInputDialog(const unsigned char *packet);

protected:
    virtual int OnSubmit();
};

*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanEnlistInputDialog

## Status

- Confidence: very strong for submit behavior, vtable identity, exact child memory pages, current MCP/local constructor evidence, direct class ownership of the submitter, the accepted emitted constructor body, and Clan source placement; the absent IDA function object, inbound xrefs, pointer route, and direct PE branch/call route remain bounded entry-route caveats only.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Reconstruction parent: [UID:0000I8][Clan](by-file/Clan.md)
- Formal C++ state: formal H emits the complete derived declaration; formal CPP contains only `[[CHILDREN]]`. UID00021W emits the exact packet-forwarding constructor definition and UID0002O3 emits `OnSubmit()`.

## 2026-08-14 Callback Resolution

- Metadata is `92/93`; owner/emitter remain UID0000I8.
- The declaration moved from CPP to H. The explicit `const unsigned char *packet` constructor remains declared and its 53-byte retained body is emitted by UID00021W despite the raw start's absent inbound route.
- The no-function/no-xref/no-pointer result is preserved as an entry-route confidence caveat. It no longer suppresses the out-of-line constructor definition proven by the base call, three vtable stores, return-this behavior, and `retn 4`.

## Score Rationale

- Completion is `92` because the class now has the complete formal H declaration, exact raw-constructor and `OnSubmit` child definitions, linked base-dialog layout evidence, vtable data references, packet-handler context, current MCP no-route proof, local PE no-reference scans, and a verified Clan source/emitter route.
- Confidence is `93` because current IDA-backed evidence, the exhaustive DLGCLAN2 table comparison, and local PE evidence agree on the constructor/submitter boundaries, class identity, and common `+0x5c` override contract. Remaining uncertainty is limited to raw constructor entry reachability and inferred original lexical spelling; it no longer blocks the accepted declaration or constructor emission.

## Class Purpose

`ClanEnlistInputDialog` handles the clan enlistment modal flow. It owns the raw derived constructor-shaped body and the common-slot `OnSubmit()` override that sends three submitted text fields plus a 16-bit attribute/type value through the shared Clan attribute packet helper; related clan status packet parsing is coordinated through `ClanStatusPane`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw constructor | [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md) | Emits the exact packet-forwarding constructor definition. Current MCP no-function/decompile/xref and VA/RVA-route negatives remain confidence evidence; live handler action `1` corroborates the same base construction and vtable stores. |
| `OnSubmit` | [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit.md) | Primary vtable slot `+0x5c` submit override; forwards inherited DLGCLAN2 submitted fields `+0x26c/+0x46c/+0x66c/+0x86c` to `SendClanAttributePacket` for enlistment submission. The old `OnSubmitEnlistment` label was descriptive, not a distinct virtual contract. |

## Evidence Notes

- IDA confirms related clan packet handler starts `0x004877d0`, `0x004879e0`, and `0x00487ea0`, plus this class's submitter at `0x00489fc0`.
- IDA reports no function at raw constructor start `0x00489f80`.
- [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md) subranges `0x004877d0`, `0x004879e0`, and `0x00487ea0` are related clan status packet handlers, not direct `ClanEnlistInputDialog` methods. Dispatcher and field-offset evidence shows they receive the adjusted `ClanStatusPane` object and mutate `m_currentClanStatusView`, `m_statusHeaderText`, `m_infoListPane`, `m_joinListPane`, and `m_enlistListPane`. `0x00487ea0` action `1` constructs `ClanEnlistInputDialog`, so this class remains a callee/constructed dialog in that flow.
- 2026-06-20 B002 reanalysis keeps that route: [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md) should split future live children as `ClanStatusPane::HandleClanEnlistRequestPacket`, `ClanStatusPane::HandleClanJoinListPacket`, and `ClanStatusPane::HandleClanEnlistPacket`; the nine no-xref opener siblings are retained `social/Clan.cpp` helpers. None of those packet-handler bodies should be promoted to this dialog class merely because action `1` constructs `ClanEnlistInputDialog`.
- 2026-06-05 IDA MCP correction: [UID:00010B][0x004842b0-0x00484a50.ClanAttributePacketParser](by-memory/0x004842b0-0x00484a50.ClanAttributePacketParser.md) is not a `ClanEnlistInputDialog` receiver. The `ClanStatusPane` dispatcher passes `this - 0xa0`, and the parser body calls [UID:00021O][0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes](by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md) and writes `ClanStatusPane` state/text storage.
- The submitter shares the same storage model as `ClanAttrInputDialog` and `ClanChangeInputDialog`, so the enlistment modal still belongs in the Clan feature module.
- 2026-05-27 IDA MCP boundary pass bounded the constructor-shaped bytes as [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md). The body calls base [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md), stores `0x00615df8`, `0x00615e5c`, and `0x00615e8c`, then returns at `0x00489fb5`; IDA still reports no function object or inbound xrefs at the start.
- 2026-05-31 IDA MCP split the submitter into [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit.md). Evidence: `lookup_funcs` reports function `0x00489fc0` size `0x29`, vtable data xref `0x00615e54`, no direct callers, callee `0x00485ac0`, and decompilation passes offsets `+0x26c`, `+0x46c`, `+0x66c`, and `+0x86c`.
- 2026-06-20 B003 source-quality incorporation reclassifies [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit.md) as the class-owned/emitted `ClanEnlistInputDialog::OnSubmitEnlistment()` body. Local PE scanning reconfirmed no direct branch callers, the sole `.rdata` pointer at primary vtable slot `0x00615e54` / `+0x5c`, the sole direct call to [UID:00010E][0x00485ac0-0x00485cbd.SendClanAttributePacket](by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md), and the `g_pClanStatusPane`/`ecx` setup before the helper call.
- 2026-05-27 IDA MCP correction: earlier ownership notes modeled `0x00487370` as `ClanEnlistInputDialog::HideAllControls`. IDA callers and child-pane offsets show that function is [UID:00021O][0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes](by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md), not a `ClanEnlistInputDialog` method.
- 2026-06-05 live IDA MCP recheck confirms no function/xrefs/pointer hits at `0x00489f80`, exact constructor bytes through `retn 4`, eleven-byte padding before the submitter, `ClanEnlistInputDialog` vtable setup stores at `0x00487f34`/`0x00487f3a`/`0x00487f44` and `0x00489f92`/`0x00489f9a`/`0x00489fa4`, vtable-only submitter slot `0x00615e54`, no direct submitter callers, and callee [UID:00010E][0x00485ac0-0x00485cbd.SendClanAttributePacket](by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md).
- 2026-06-15 A002 refresh: Wave2 `method/decomp/xrefs` reports an included zero-caller `ClanEnlistInputDialog::ClanEnlistInputDialog(int dialogType)` record at `0x00489f80`, size `53`, with one callee `0x00489600` and grade `95.5`; Wave2 `filter --class ClanEnlistInputDialog --all-methods` also lists `SubmitEnlistment` at `0x00489fc0`.
- The same Wave2 filter still lists stale `ParseClanAttributePacket` and `HideAllControls` ownership for `0x004842b0` and `0x00487370`. Current IDA-backed documentation keeps those with the ClanStatusPane/dispatcher context, so Wave2 is used here only for constructor/submitter corroboration.
- 2026-06-15 live IDA reconfirmed no function at `0x00489f80`/`0x00489fb5`, no raw-start xrefs, submitter vtable cell `0x00615e54`, exact constructor bytes, and vtable-store refs. Local PE scans found no VA/RVA pointer bytes or relative branch/call targets to `0x00489f80`.
- 2026-07-05 B010 historical MCP refresh for [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md): session `supervisor_recovery_20260705` was healthy when queried; `lookup_funcs` found no function at `0x00489f80` or `0x00489fb5` and successor `sub_489FC0` at `0x00489fc0` size `0x29`; `decompile 0x00489f80` failed because the raw start is not a function; xrefs and exact VA/RVA pointer searches to the raw start/end were zero; bytes/instructions show a 53-byte base-call/vtable-store body followed by eleven `0xcc` padding bytes; vtable refs pair raw stores `0x00489f92/0x00489f9a/0x00489fa4` with live inline stores `0x00487f34/0x00487f3a/0x00487f44`; and local PE scanning found no direct branch/call route to `0x00489f80`. Its then-current marker-only conclusion is superseded by the 2026-08-14 accepted exact constructor definition; the negative route facts remain confidence evidence. [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit.md) continues to emit the resolved `OnSubmit()` override.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:0002MN][0x006158f4-0x00615fd8.ClanModalDialogVtableData](by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md)
- [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md)
- [UID:00010E][0x00485ac0-0x00485cbd.SendClanAttributePacket](by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md)
- [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md)
- [UID:00010M][0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters](by-memory/0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters.md)
- [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit.md)
- [UID:00021O][0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes](by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md)
- [UID:000024][ClanAttrInputDialog](by-class/ClanAttrInputDialog.md)
- [UID:000027][ClanChangeInputDialog](by-class/ClanChangeInputDialog.md)

## Changes

The entries below are dated historical changes. Older scores, blank-C++ statements, and marker-only/no-body conclusions are superseded by the current `92/93` metadata and the 2026-08-14 formal H/CPP route above.

- 2026-07-13 B004 UID0004HI contract implementation:
  - Changed the declaration and current method inventory from the historical descriptive `OnSubmitEnlistment` label to the common primary-vtable `OnSubmit()` override, and synchronized the renamed UID0002O3 child link.
  - Raised metadata from `85/89` to `87/91` for the complete class contract while preserving owner/emitter [UID:0000I8][Clan](by-file/Clan.md), raw-constructor no-route evidence, packet payload, source route, and all ClanStatusPane ownership corrections.
  - The exact original lexical spelling and `int` return remain inference-backed confidence caps; the exhaustive `+0x5c` topology proves that the Enlist and Change bodies override the same base pure-virtual slot.

- 2026-07-05 B010 UID00021W implementation sync:
  - Added current `supervisor_recovery_20260705` MCP/no-route evidence for [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md), including no function/decompile/xrefs, zero raw-start/end pointer routes, exact 53-byte body, eleven-byte padding, vtable store pairs, live inline construction in [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md) action `1`, and no direct PE branch/call route.
  - Historical callback state (superseded 2026-08-14): preserved the class declaration, Clan source route, and UID0002O3 submit body while leaving UID00021W marker-only. The accepted callback now emits UID00021W's exact constructor without changing those class/submit routes.
- 2026-06-20 B003 Rule 26 source-quality incorporation:
  - Synced the class page with [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit.md)'s class-owned first-draft `OnSubmitEnlistment()` body.
  - Added the submitter's primary vtable slot `+0x5c`, inherited submitted-field forwarding at `+0x26c/+0x46c/+0x66c/+0x86c`, `SendClanAttributePacket` relationship, and `g_pClanStatusPane` context-load caveat. Scores remain `85/89` because the raw constructor reachability and final declaration spelling remain class-level caveats.
- 2026-06-19 B013 source-quality implementation:
  - Removed the three [UID:00021S][0x004877d0-0x00488594.ClanStatusPacketDialogHandlers](by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md) method rows from this class table.
  - Added the accepted evidence note that `0x004877d0`, `0x004879e0`, and `0x00487ea0` are `ClanStatusPane` packet handlers, while `0x00487ea0` action `1` constructs `ClanEnlistInputDialog`.
  - Scores remain `85/89`; this support edit corrects ownership wording without changing the class's raw constructor or submitter evidence.
- 2026-06-20 B002 Rule 26 support sync: reconfirmed `00021S` as ClanStatusPane/Clan helper-island ownership and kept this class as constructed dialog/submission owner only. Scores remain `85/89`.
- 2026-06-15 A002 parent-gate refresh:
  - What existed before: metadata was `82/88`; the class already had exact child pages but lacked current Wave2/local no-reference evidence.
  - Changed to: metadata is `85/89`; owner/emitter remain [UID:0000I8][Clan](by-file/Clan.md); final C++ remains blank.
  - Summary/evidence: added Wave2 included zero-caller constructor support, documented the stale Wave2 ownership caveat for status-pane helpers, and tied the class to the refreshed [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md) IDA/local PE no-reference pass. The class now clears the direct-parent gate for the raw constructor, but final source declaration/code remains blocked by constructor reachability and source-name quality.
- 2026-05-27: Removed `0x00487370-0x004873b5` as `ClanEnlistInputDialog::HideAllControls`. Changed it to [UID:00021O][0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes](by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md), owned by `ClanStatusPane`. Evidence: IDA callers are in [UID:00010B][0x004842b0-0x00484a50.ClanAttributePacketParser](by-memory/0x004842b0-0x00484a50.ClanAttributePacketParser.md) and [UID:00010C][0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput](by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md), the function touches `ClanStatusPane` child offsets `+0x2510/+0x2514/+0x2518`, and IDA vtable scans found no `0x00487370` entry in `ClanEnlistInputDialog` vtables.
- 2026-05-27: Changed the constructor note from unbounded projected start `0x00489f80` to bounded raw constructor [UID:00021W][0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor](by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md). Evidence: IDA MCP byte audit shows constructor prologue at `0x00489f80`, base call to `0x00489600`, `ClanEnlistInputDialog` vtable stores at `0x00489f92`, `0x00489f9a`, and `0x00489fa4`, then `retn 4` ending at `0x00489fb5`.
- What existed before: the page documented packet parsing, submit behavior, constructor bounding, and a wrong-owner correction, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were initially set to `74/80`.
- Summary and evidence: parser/handler/submission behavior and vtable identity are documented; raw constructor reachability and final layout/header details remain open.
- 2026-05-31: Replaced the submitter raw address with the exact [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit.md) child page and marked the class reconstructable but unassigned.
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
