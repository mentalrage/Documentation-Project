*** UID:000024 | DO NOT MODIFY OR REMOVE!!! ***
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
class ClanAttrInputDialog : public DialogPane
{
public:
    explicit ClanAttrInputDialog(const unsigned char *packet);

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void ValidateInputFields();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual int OnSubmit() = 0;

    wchar_t m_submittedClanName[256];
    wchar_t m_submittedDescriptionText[256];
    wchar_t m_submittedAttributeText[256];
    unsigned short m_submittedAttributeType;
};

*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ClanAttrInputDialog

## Status

- Confidence: strong.
- Likely source file: [UID:0000I8][Clan](by-file/Clan.md)
- Layout docs: [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- Current recovered file: `source-3/simroot_v2/class_ClanAttrInputDialog.cpp`
- Formal C++ state: formal H emits the complete declaration shell, four persistent submitted fields, pure virtual `OnSubmit`, and mutable `Event *` handler. Formal CPP contains only `[[CHILDREN]]`. The DLGCLAN2 constructor emits through [UID:0004HH][0x00489600-0x00489de1.ClanAttrInputDialogConstructor](by-memory/0x00489600-0x00489de1.ClanAttrInputDialogConstructor.md); command/validation/event bodies emit through UID0004HI/UID0004HJ/UID0004HK; and the two concrete `OnSubmit` overrides emit through UID0002O3/UID0002O5.

## Class Purpose

`ClanAttrInputDialog` is the `DLGCLAN2.EPF` multi-field clan attribute dialog. It creates five labels, three required edit controls, OK/Cancel buttons, stores submitted text/value fields, validates that required inputs are populated, and delegates final confirmation to a derived virtual.

The persistent submitted-field storage is declared as three 256-wide-character arrays at `+0x26c`, `+0x46c`, and `+0x66c`, followed by a 16-bit field at `+0x86c`; modeled Enlist/Change allocations are `0x870` bytes. The constructor decodes the first packet string directly into `m_submittedClanName`. `OnControlCommand` fills `m_submittedDescriptionText`, `m_submittedAttributeText`, and `m_submittedAttributeType` from controls `8`, `9`, and `10`, calls `OnSubmit()`, then closes. `ClanEnlistInputDialog::OnSubmit()` passes those fields to opcode `0x4b`, subtype `6`, action `2`, while `ClanChangeInputDialog::OnSubmit()` passes the same layout to the opcode `0x4b`, subtype `10` helper.

Those field names and `OnSubmit` remain accepted source-facing inferences rather than recovered original symbols. The common hook contract is nevertheless source-complete: the base `+0x5c` cell is `__purecall`, the Enlist/Change tables replace the same slot with no-argument integer-returning bodies, and C++ override consistency rejects the two former specialized method names as simultaneous current declarations.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ClanAttrInputDialog` | [UID:0004HH][0x00489600-0x00489de1.ClanAttrInputDialogConstructor](by-memory/0x00489600-0x00489de1.ClanAttrInputDialogConstructor.md) `0x00489600-0x00489de1` | Formal first-draft constructor decodes six counted packet strings beginning at `packet+3`, stores the first in `m_submittedClanName`, creates the eleven-control `DLGCLAN2.EPF` layout, attaches through the overlay layer relative to `g_pBackPane`, and slides open horizontally. |
| `OnControlCommand` | [UID:0004HI][0x00489df0-0x00489eb7.ClanAttrInputDialogOnControlCommand](by-memory/0x00489df0-0x00489eb7.ClanAttrInputDialogOnControlCommand.md) `0x00489df0-0x00489eb7` | Inherited primary `+0x48` override. Index `1` reads controls `8/9/10`, stores fields at `+0x46c/+0x66c/+0x86c`, calls `OnSubmit`, then closes; index `2` closes; other values return. |
| `OnSubmit` | primary slot `+0x5c` | Pure virtual `int OnSubmit() = 0`; base cell `0x00615db4` is `__purecall`, Enlist cell `0x00615e54` routes to UID0002O3, and Change cell `0x00615ef4` routes to UID0002O5. |
| `ValidateInputFields` | [UID:0004HJ][0x00489ec0-0x00489f46.ClanAttrInputDialogValidateInputFields](by-memory/0x00489ec0-0x00489f46.ClanAttrInputDialogValidateInputFields.md) `0x00489ec0-0x00489f46` | Enables/disables OK based on required edit fields and now carries the formal child C++ body. |
| `HandlePointerOrMouseEvent` | [UID:0004HK][0x00489f50-0x00489f80.ClanAttrInputDialogOnInputEvent](by-memory/0x00489f50-0x00489f80.ClanAttrInputDialogOnInputEvent.md) `0x00489f50-0x00489f80` | Accepts mutable `Event *`; for type `3`, forwards the same pointer through `g_pClanStatusPane` secondary EventHandler view and then calls the base handler. |

## 2026-08-14 Callback Resolution

- Metadata is `92/93` after exact method, vtable, layout, event ABI, owner, and formal-channel reconciliation.
- The declaration moved from CPP to H; CPP now contains only `[[CHILDREN]]` so source definitions stay on exact by-memory children.
- `HandlePointerOrMouseEvent(Event *event)` supersedes historical `OnInputEvent(const InputEvent &event)`. No `InputEvent` UDT exists, `Event` is `0x110` bytes, and the body reads and forwards the same mutable event pointer.
- UID0000IA is a non-emitting index. UID0000I8 and `NexusTK/social/Clan.cpp` / `Clan.h` remain the source route.
- The Enlist and Change raw successor ranges are explicit source-emitting delegating constructor definitions. Their absent modeled-function/inbound-start routes remain confidence evidence only and do not authorize marker-only/no-body treatment. The `0x0048c291`/`0x0048c29c` adjustors and `0x0048c390-0x0048c3cb` scalar-deleting wrapper remain compiler-generated support rather than handwritten class methods.
| destructor/thunks | `0x0048c291`, `0x0048c29c`, `0x0048c390-0x0048c3cb` | Generated secondary/tertiary adjustor thunks and scalar deleting destructor wrapper. |

## Evidence Notes

- IDA confirms all four core function starts and the destructor.
- `ClanChangeInputDialog` derives from this dialog and sends the final multi-field attribute change through helper `0x00486330`.
- 2026-05-26 IDA decompilation confirms the method now source-facing as `OnControlCommand` reads controls `8`, `9`, and `10`, copies the two text fields into `+0x46c` and `+0x66c`, parses the numeric value into `+0x86c`, and dispatches the confirmation virtual.
- 2026-07-13 B004 live-MCP report pass exhaustively compared all 24 entries in primary tables `0x00615d58`, `0x00615df8`, and `0x00615e98`: all entries through `+0x58` are equal, all three `+0x48` cells point to UID0004HI, and only `+0x5c` differs as base `__purecall`, Enlist UID0002O3, and Change UID0002O5. This resolves the common no-argument hook as inferred `int OnSubmit()` and the inherited handler as `OnControlCommand(int,int)`.
- UID0004HI's exact body preserves control index `1/2/other` behavior, interleaved typed control reads with capacity `255`, `_wtol` low-16-bit storage, submit-before-close ordering, ignored helper results, literal horizontal direction `0`, and absence of null/read/parse/submit-result checks. Cookie/vptr/list-slot lowering is not handwritten source.
- The former `OnDialogAction`, `OnSubmitEnlistment`, and method `SubmitClanChange` identities remain historical descriptive aliases only. `OnConfirm` is rejected because it belongs to a distinct AlertPane-derived family; one-off `ClanDialogs.cpp` migration remains rejected without coordinated family evidence.
- 2026-06-20 B003 source-quality incorporation for [UID:0002O3][0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit](by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit.md) applies descriptive inherited member names to this storage: `m_submittedClanName` at `+0x26c`, `m_submittedDescriptionText` at `+0x46c`, `m_submittedAttributeText` at `+0x66c`, and `m_submittedAttributeType` at `+0x86c`. Exact original UI labels remain unrecovered, so those names are source-facing inferences rather than symbol proof.
- 2026-05-27 IDA boundary check reports historical raw label `OnInputEvent` (`sub_489F50`) at `0x00489f50-0x00489f80`; byte `0x00489f7f` is the last byte of `retn 4`. Current source-facing identity is `HandlePointerOrMouseEvent(Event *event)`.
- 2026-06-16 A001 live IDA reconfirmed constructor/action/validation/input-event sizes, three modeled constructor callers plus two raw derived-constructor calls, vtable-only action/validation/input-event slots, six packet-string decodes, required controls `8`/`9`/`10`, field storage `+0x26c/+0x46c/+0x66c/+0x86c`, `g_pClanStatusPane` event forwarding, and both subtype `6` and subtype `10` three-string packet helper shapes. A corrected PE scan matched the five direct constructor branches and the sole direct helper branches at `0x00489fe3` and `0x0048a053`.
- 2026-07-05 B010 source-quality sync preserves the declaration-shell/`[[CHILDREN]]` class page state and clarifies that [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit.md) plus [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md) are current source-emitting child/helper bodies. The submitted-field names remain descriptive source-facing names, not original symbol proof.
- 2026-07-05 B009 split sync: MCP session `supervisor_recovery_20260705` reconfirmed the four DLGCLAN2 method ranges as `0x00489600-0x00489de1`, `0x00489df0-0x00489eb7`, `0x00489ec0-0x00489f46`, and `0x00489f50-0x00489f80`, with internal `0xcc` padding, constructor string/resource behavior, OK/action field writes, validation required-field checks, and event type `3` forwarding through `g_pClanStatusPane` followed by `DialogPane::HandlePointerOrMouseEvent(Event *)`. The former parent [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md) is now a non-emitting split index; the exact method dispositions live on the four child pages.
- 2026-06-22 B014 destructor-band recheck corrects the scalar-deleting destructor wrapper endpoint to `0x0048c390-0x0048c3cb` and keeps the `0x0048c291`/`0x0048c29c` thunks as generated multiple-inheritance destructor adjustors, not handwritten source.
- 2026-07-12 B003 current MCP session `359c7886` reconfirmed constructor size `0x7e1`, six sequential counted CP_ACP strings, object allocation size `0x870`, the eleven-control insertion order, overlay-layer/`g_pBackPane` setup, three modeled inline derived construction sites, and two separate raw derived constructor calls. The raw Enlist/Change constructor starts retain their no-route evidence; the source-visible base constructor remains required by derived construction.
- The constructor does not read or write `g_pClanStatusPane` or a dedicated dialog singleton. That global remains a later `HandlePointerOrMouseEvent(Event *)`/submit dependency. A one-off move to [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) remains rejected; current owner/emitter [UID:0000I8][Clan](by-file/Clan.md) and `NexusTK/social/Clan.cpp` remain unchanged.

## Score Rationale

- Completion is `92` because the H channel carries the complete class declaration, mutable event contract, pure virtual `OnSubmit`, and four persistent fields; CPP is exactly `[[CHILDREN]]`; UID0004HH/HI/HJ/HK emit all four source bodies; Enlist/Change constructor and submit children are routed; and layout, vtable, packet, control/field, compiler-support, rejected-alternative, and source-placement evidence are synchronized.
- Confidence is `93` because current MCP, PE evidence, exhaustive primary-table topology, generated Clan CPP/H, and support pages agree on the `0x870` layout, exact method ranges, constructor/handler/validation/submit flow, and fixed Clan source route. It remains below final-source confidence only because `OnSubmit`, member/local spellings, five packet-provided label roles, and the exact historical source filename are inferred rather than original-symbol proven; `ClanDialogs.cpp` is not an active or future emitter alternative.

## Cross-References

- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md)
- [UID:0004HH][0x00489600-0x00489de1.ClanAttrInputDialogConstructor](by-memory/0x00489600-0x00489de1.ClanAttrInputDialogConstructor.md)
- [UID:0004HI][0x00489df0-0x00489eb7.ClanAttrInputDialogOnControlCommand](by-memory/0x00489df0-0x00489eb7.ClanAttrInputDialogOnControlCommand.md)
- [UID:0004HJ][0x00489ec0-0x00489f46.ClanAttrInputDialogValidateInputFields](by-memory/0x00489ec0-0x00489f46.ClanAttrInputDialogValidateInputFields.md)
- [UID:0004HK][0x00489f50-0x00489f80.ClanAttrInputDialogOnInputEvent](by-memory/0x00489f50-0x00489f80.ClanAttrInputDialogOnInputEvent.md)
- [UID:00010T][0x0048c260-0x0048c63f.ClanDestructorBand](by-memory/0x0048c260-0x0048c63f.ClanDestructorBand.md)
- [UID:000027][ClanChangeInputDialog](by-class/ClanChangeInputDialog.md)

## Changes

The dated entries below preserve the investigation history. Any older `90/92`, `OnInputEvent`, `InputEvent`, future `ClanDialogs.cpp` split, declaration-in-CPP, or constructor no-code statement is superseded by `2026-08-14 Callback Resolution` and the current `92/93` formal state above.

- 2026-07-13 B004 accepted UID0004HI support callback:
  - Raised `88/90` to `90/92` and applied the complete accepted class block with `OnControlCommand(int,int)`, pure virtual `int OnSubmit() = 0`, all existing fields, constructor, sibling methods, and `[[CHILDREN]]` preserved.
  - Synchronized UID0004HI/UID0002O3/UID0002O5 current identities, exhaustive `+0x48/+0x5c` topology, complete handler behavior, compiler-lowering exclusions, lexical/type confidence caps, rejected alternatives, and the unchanged [UID:0000I8][Clan](by-file/Clan.md) route. Owner/emitter and all unrelated destructor/constructor/layout content remain unchanged.
- 2026-07-12 B003 accepted UID0004HH support callback:
  - Raised `86/89` to `88/90`, added the protected submitted-field declarations at `+0x26c/+0x46c/+0x66c/+0x86c`, and synchronized the constructor row/formal state with the source-emitting UID0004HH child.
  - Preserved owner/emitter [UID:0000I8][Clan](by-file/Clan.md), descriptive-name caveats, `0x870` derived object size, raw derived constructor no-route evidence, generated destructor/thunk exclusions, and rejection of a one-off ClanDialogs move.
- 2026-07-05 B009 split implementation:
  - Added the exact DLGCLAN2 method child pages, corrected method-note ranges to current half-open ends, replaced stale `OnInputEvent` validation-refresh wording with event type `3` forwarding through `g_pClanStatusPane` plus base handler, and preserved the declaration-shell/`[[CHILDREN]]` class emission route.
  - [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md) is now the non-emitting split index; constructor/action children carry no-code proofs and validation/input-event children carry formal C++.
- 2026-07-05 B010 support sync: no metadata change. Replaced stale class-level blank-C++ wording with declaration-shell/child-body wording for the retained raw helper family; retained `m_submittedClanName`, `m_submittedDescriptionText`, `m_submittedAttributeText`, and `m_submittedAttributeType` as source-facing inferences rather than original symbol proof.
- 2026-06-20 B003 Rule 26 support sync:
  - Added the `ClanEnlistInputDialog::OnSubmitEnlistment()` use of the shared DLGCLAN2 submitted fields and the current descriptive member-name direction (`m_submittedClanName`, `m_submittedDescriptionText`, `m_submittedAttributeText`, `m_submittedAttributeType`).
  - Scores remain `86/89`; this support edit refines field semantics and derived submitter coverage without changing the base class range or source route.
- 2026-05-27: Corrected `OnInputEvent` from `0x00489f50-0x00489f7f` to exclusive end `0x00489f80`. Evidence: IDA MCP reports `sub_489F50` at `0x00489f50-0x00489f80`, with `retn 4` occupying bytes `0x00489f7d-0x00489f7f`.
- What existed before: the page documented the multi-field clan attribute dialog, core method boundaries, submitted-field storage, layout docs, and IDA-backed range correction, but metadata was still `0/0`.
- What it was changed to: scores were set to `82/88`.
- Summary and evidence: constructor, action, validation, input refresh, destructor/thunk family, field offsets, derived submit use, and layout references are covered; exact final source/header form and some widget field names remain below exhaustive.
- 2026-06-05: Marked reconstructable and attached to [UID:0000I8][Clan](by-file/Clan.md) because the class is `82/88` and the parent is `90/82`, satisfying the 80/80 parent gate. Live IDA MCP `lookup_funcs` confirms exact starts at `0x00489600`, `0x00489df0`, `0x00489ec0`, `0x00489f50`, `0x0048c291`, `0x0048c29c`, and `0x0048c390`; current `callers` confirms constructor references from the clan packet/dialog flow at `0x004852e9`, `0x00487f2f`, and `0x004883e8`.
- 2026-06-16 A001 class-completion refresh: raised `82/88` to `86/89` after refreshing [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md), [UID:0002O5][0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit](by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit.md), [UID:00010F][0x00486330-0x0048652d.SubmitClanChangeHelper](by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md), and [UID:00010E][0x00485ac0-0x00485cbd.SendClanAttributePacket](by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md) to 85 completion. Owner/emitter stay [UID:0000I8][Clan](by-file/Clan.md); class-level formal C++ remains a declaration shell while child pages carry the body emission. Final control/member names and the source/header split remain confidence caps.
- 2026-06-22 B014 Rule 26 support sync: corrected the destructor wrapper half-open range to `0x0048c390-0x0048c3cb`; scores and owner/emitter are unchanged.
