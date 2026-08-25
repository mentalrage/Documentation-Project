*** UID:000027 | DO NOT MODIFY OR REMOVE!!! ***
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
class ClanChangeInputDialog : public ClanAttrInputDialog
{
public:
    explicit ClanChangeInputDialog(const unsigned char *packet);

protected:
    virtual int OnSubmit();
};

*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanChangeInputDialog

## Status

- Confidence: very strong for submit behavior, vtable identity, exact child pages, current MCP/local constructor evidence, the accepted emitted constructor body, and Clan source placement; absent raw-entry reachability remains a bounded confidence caveat only.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Layout docs: [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- Reconstruction parent: [UID:0000I8][Clan](by-file/Clan.md)
- Formal C++ state: formal H emits the complete derived declaration; formal CPP contains only `[[CHILDREN]]`. UID0002O4 emits the packet-forwarding constructor, UID0002O5 emits `OnSubmit()`, and UID00010F retains the packet helper body.

## 2026-08-14 Callback Resolution

- Metadata is `92/93`; owner/emitter remain UID0000I8.
- The declaration moved from CPP to H. The explicit packet constructor is a real out-of-line definition owned by UID0002O4, not a marker-only/no-code range.
- The retained start's absent IDA function/xref/pointer route remains a confidence caveat and protected IDA state; exact base call, vtable stores, return-this behavior, and `retn 4` require the constructor CPP definition.

## Score Rationale

- Completion is `92` because the class now has the complete formal H declaration, exact raw-constructor and `OnSubmit` child definitions, linked base-dialog layout evidence, vtable data references, helper dependency evidence, local PE no-reference scans, and a verified Clan source/emitter route.
- Confidence is `93` because current IDA-backed evidence, the exhaustive DLGCLAN2 table comparison, and local PE evidence agree on the constructor/submitter boundaries, inherited field offsets, class identity, and common `+0x5c` override contract. Remaining uncertainty is limited to raw constructor entry reachability and inferred original lexical spelling; it no longer blocks the accepted declaration or constructor emission.

## Class Purpose

`ClanChangeInputDialog` is a derived `ClanAttrInputDialog` that submits multi-field clan attribute changes: clan name, description, flag/text field, and clan type.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| raw constructor | [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md) | Constructor-shaped bytes; IDA reports no function, inbound xrefs, or raw pointer hits at this start. |
| `OnSubmit` | [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit.md) | Common primary-vtable slot `+0x5c` override; reads stored fields from the base attribute dialog and calls helper [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md). The old `SubmitClanChange` method label was descriptive, not a distinct virtual contract. |

## Evidence Notes

- IDA confirms the body now documented as `OnSubmit` at `0x0048a030`; historical tools labeled it `SubmitClanChange`.
- IDA confirms helper `0x00486330` is called from `0x0048a053` and sends opcode `0x4b`, subtype `10`, action `2`, three strings, and a 16-bit value.
- 2026-05-26 IDA decompilation confirms the submitter passes `ClanAttrInputDialog` storage at `+0x26c`, `+0x46c`, `+0x66c`, and the 16-bit value at `+0x86c`.
- 2026-05-27 IDA MCP family pass found no inbound xrefs or raw dword pointer hits to `0x00489ff0`. Disassembly at the projected start still calls base `0x00489600` and stores `0x00615e98` at `0x0048a002` plus `0x00615efc` at `0x0048a00a`, so keep it as constructor-shaped bytes pending boundary cleanup.
- 2026-05-31 IDA MCP split the constructor-shaped body and submitter into exact child pages. `lookup_funcs` reports no function at `0x00489ff0` and function `0x0048a030` size `0x29`; `xrefs_to(0x0048a030)` reports vtable slot `0x00615ef4`; `callees(0x0048a030)` reports `0x00486330`; decompilation confirms offsets `+0x26c`, `+0x46c`, `+0x66c`, and `+0x86c`; byte audit confirms padding around the child ranges.
- 2026-06-05 live IDA MCP recheck confirms no function/xrefs/pointer hits at `0x00489ff0`, exact constructor bytes through `retn 4`, eleven-byte padding before the submitter, `ClanChangeInputDialog` vtable setup stores at `0x004852ee`/`0x004852f6`/`0x00485300`, `0x004883ed`/`0x004883f3`/`0x004883fd`, and `0x0048a002`/`0x0048a00a`/`0x0048a014`, vtable-only submitter slot `0x00615ef4`, no direct submitter callers, and callee [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md).
- 2026-06-15 A002 refresh: Wave2 `method/decomp/xrefs` reports an included zero-caller `ClanChangeInputDialog::ClanChangeInputDialog(int dialogType)` record at `0x00489ff0`, size `53`, with one callee `0x00489600`, no data refs, and grade `100`.
- Wave2 `filter --class ClanChangeInputDialog --all-methods` lists only the submitter at `0x0048a030` and the constructor at `0x00489ff0`; Wave2 `struct ClanChangeInputDialog` shows only a `ClanAttrInputDialog` base at offset `0`.
- 2026-06-15 live IDA reconfirmed no function at `0x00489ff0`/`0x0048a025`, no raw-start xrefs, submitter vtable cell `0x00615ef4`, exact constructor bytes, and vtable-store refs. Local PE scans found no VA/RVA pointer bytes or relative branch/call targets to `0x00489ff0`.
- 2026-07-05 B010 historical source-quality sync kept the class page as a declaration shell with `[[CHILDREN]]`, while [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit.md) then used the descriptive `SubmitClanChange()` label and [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md) emitted the corrected helper body. The current contract resolves the method as `OnSubmit()` while preserving the raw-constructor caveat for [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md).

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:0002MN][0x006158f4-0x00615fd8.ClanModalDialogVtableData](by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md)
- [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md)
- [UID:00010M][0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters](by-memory/0x00489fc0-0x0048a0be.ClanEnlistChangeLeaveSubmitters.md)
- [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md)
- [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit.md)
- [UID:000024][ClanAttrInputDialog](by-class/ClanAttrInputDialog.md)
- [UID:000028][ClanChangeNameInputDialog](by-class/ClanChangeNameInputDialog.md)

## Changes

The entries below are dated historical changes. Older scores, blank-C++ statements, and marker-only/no-body conclusions are superseded by the current `92/93` metadata and the 2026-08-14 formal H/CPP route above.

- 2026-07-13 B004 UID0004HI contract implementation:
  - Changed the declaration and current method inventory from the historical descriptive `SubmitClanChange` method label to the common primary-vtable `OnSubmit()` override, without renaming or altering `SubmitClanChangeHelper`.
  - Raised metadata from `85/89` to `87/91` for the complete class contract while preserving owner/emitter [UID:0000I8][Clan](by-file/Clan.md), raw-constructor no-route evidence, exact helper payload and ECX nuance, source route, and unrelated content.
  - The exact original lexical spelling and `int` return remain inference-backed confidence caps; the exhaustive `+0x5c` topology proves that the Enlist and Change bodies override the same base pure-virtual slot.

- 2026-07-05 B010 support sync: no metadata change. Clarified that this page emits the class declaration shell/`[[CHILDREN]]`, while [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit.md) and [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md) carry the submitter/helper body emission; [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md) remains the raw constructor caveat.
- 2026-06-15 A002 parent-gate refresh:
  - What existed before: metadata was `82/88`; the class already had exact child pages but lacked current Wave2/local no-reference evidence.
  - Changed to: metadata is `85/89`; owner/emitter remain [UID:0000I8][Clan](by-file/Clan.md); class-level formal C++ remains a declaration shell with child body emission.
  - Summary/evidence: added Wave2 included zero-caller constructor support, Wave2 class-filter/base-layout confirmation, and the refreshed [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md) IDA/local PE no-reference pass. The class now clears the direct-parent gate for the raw constructor, but full constructor-body source remains blocked by constructor reachability and source-name quality.
- What existed before: the page documented derived submit behavior, base field offsets, vtable anchors, and projected constructor caveats, but metadata was still `0/0`.
- What it was changed to: scores were initially set to `70/76`.
- Summary and evidence: submit behavior and helper linkage are clear, but the constructor remains raw/projected with no reachability and the derived class layout/header remains incomplete.
- 2026-05-31: Replaced raw address/projection entries with exact child pages and marked the class reconstructable but unassigned.
  - Before: the method table listed projected constructor `0x00489ff0` and submitter `0x0048a030-0x0048a058` without exact child-page links.
  - After: the page links [UID:0002O4][0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor](by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md) and [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit.md), with scores raised to `76/84`.
  - Summary and evidence: IDA MCP `lookup_funcs`, `xrefs_to`, `callees`, decompilation, raw constructor disassembly, and byte audit confirm exact child boundaries, vtable ownership, base field offsets, and surrounding padding.
- 2026-06-05: Raised class coverage and attached the class to the Clan source parent.
  - Before: metadata was `76/84`, the parent was blank, and stale source-lead wording remained in the status notes.
  - After: metadata is `82/88`, `AUTOGEN_PARENT_UID` is [UID:0000I8][Clan](by-file/Clan.md), and the stale source-lead wording has been removed.
  - Evidence: live IDA MCP `lookup_funcs`, `xrefs_to`, `callers`, `callees`, decompilation, byte reads, pointer search, immediate search, and data-reference search on the raw constructor and submitter confirmed the exact child boundaries, vtable identity, helper dependency, inherited field offsets, and remaining no-reachability caveat.
