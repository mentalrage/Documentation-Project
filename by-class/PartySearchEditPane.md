*** UID:0000A7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class PartySearchEditPane : public DialogPane
{
public:
    PartySearchEditPane();
    virtual ~PartySearchEditPane() {}

    virtual void OnPaint();
    virtual void OnControlCommand(int controlIndex, int notifyCode);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# PartySearchEditPane

## Status

- Confidence: very strong for behavior, exact boundaries, user-list caller ownership, zero-member inheritance/layout, vtable slots, complete source surface, state access, and opcode `0x84` submit path. Exact original method/local spellings remain the bounded cap below 95.
- Likely source file: [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- Address range: [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)

## Class Purpose

`PartySearchEditPane` is the zero-data-member `DialogPane` derivative opened from the users dialog for party-search/hunters-list settings. It shows a `DLGSETUP.EPF` dialog with a checkbox labeled `Put me on the hunters list`, a text edit control backed by current UserPane party-search state, and an OK button that persists and conditionally submits opcode `0x84`.

The sole caller allocates `0x26c` bytes, exactly the complete current `DialogPane` size. Construction stores no derived state beyond compiler vptr views, and all controls are inserted into the inherited control manager. The class therefore adds no data members; its complete human source surface is the constructor, inline empty virtual destructor, empty `OnPaint`, and two-argument `OnControlCommand` declaration above.

## Method Notes

| Method or helper | Address | Role |
| --- | --- | --- |
| `PartySearchEditPane()` | `0x0059e0d0-0x0059e393` | Initializes `DialogPane(L"",3,1)`, plays sound `0x198`, creates the exact DLGSETUP image/button/checkbox/text controls, configures focus/background/layer attachment, shows the pane, and starts vertical opening. |
| vtable reset helper | `0x0059e3a0-0x0059e3bf` | Restores the three `PartySearchEditPane` vtables before forwarding to the base cleanup path. |
| `OnPaint()` | `0x0059e3c0-0x0059e3c1` | Exact empty source override at primary vtable slot `+0x44`; the stale `OnDestroyChildControls`/nullsub-only interpretation is superseded. |
| `OnControlCommand(int,int)` | `0x0059e3d0-0x0059e707` | Control `2` toggles/invalidate the checkbox; control `1` closes, persists validated/sanitized UserPane state, mirrors the local packed row, conditionally sends opcode `0x84`, and queues deferred deletion. |
| adjustor thunks | `0x0059f001-0x0059f017` | Destructor adjustors for subobjects. |
| inline virtual destructor / compiler support | `0x0059e3a0-0x0059e3bf`, `0x0059efeb-0x0059f043`, `0x0059f0b0-0x0059f105` | An inline empty virtual destructor is the human source cause; vtable reset, adjustor, scalar-delete flag, base teardown, and conditional free remain compiler-generated. |

## Exact Child Pages

B002 split implementation added exact child pages for the `PartySearchEditPane` portion of [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md):

- [UID:00047D][0x0059e0d0-0x0059e393.PartySearchEditPaneConstructor](by-memory/0x0059e0d0-0x0059e393.PartySearchEditPaneConstructor.md) emits the complete dialog construction source using B003's typed `g_pUserPane` accessors. The historical `g_pUserListDialogPane` initial-state claim and blank child-control/member-layout blocker are superseded.
- [UID:00047F][0x0059e3c0-0x0059e3c1.PartySearchEditPaneOnDestroyChildControlsNoop](by-memory/0x0059e3c0-0x0059e3c1.PartySearchEditPaneOnDestroyChildControlsNoop.md) retains its physical UID/path but emits the exact empty `PartySearchEditPane::OnPaint()` source virtual.
- [UID:00047G][0x0059e3d0-0x0059e707.PartySearchEditPaneOnAction](by-memory/0x0059e3d0-0x0059e707.PartySearchEditPaneOnAction.md) emits the complete two-argument `OnControlCommand` source, including exact UserPane accessors, packed-record mirror, opcode `0x84` payload, send, and cleanup behavior.
- [UID:00047E][0x0059e3a0-0x0059e3bf.PartySearchEditPaneCleanupHelper](by-memory/0x0059e3a0-0x0059e3bf.PartySearchEditPaneCleanupHelper.md), [UID:00047T][0x0059efeb-0x0059f043.UserListFeatureAdjustorThunks](by-memory/0x0059efeb-0x0059f043.UserListFeatureAdjustorThunks.md), and [UID:00047U][0x0059f0b0-0x0059f105.PartySearchEditPaneScalarDeletingDestructor](by-memory/0x0059f0b0-0x0059f105.PartySearchEditPaneScalarDeletingDestructor.md) remain compiler cleanup/thunk/deleting-wrapper artifacts with blank formal C++.

## Layout, Vtable, And Source-Shape Closure

- The primary/secondary/tertiary vtable bases are `0x0062ea40`, `0x0062eaa0`, and `0x0062ead0`. Primary slot `+0x44` points to `0x0059e3c0`; DialogPane slot parity identifies `OnPaint`. Primary slot `+0x48` points to `0x0059e3d0`; two stack arguments and DialogPane parity identify `OnControlCommand(int,int)`.
- The class has no derived fields. UserPane owns `m_huntersListFlag` at complete-object `+0x3cb1`, `m_partySearchSourceText[256]` at `+0x3cb2`, and the following two residual bytes. PartySearch uses B003's already-current public inline getters/setters; no UserPane friend, public raw field, raw offset, or synthetic accessor is required.
- `UserListDialogPane` privately owns `m_allUserRecords`. PartySearch receives only the bounded friendship on that class so its submit path can scan and update the local `UserListRecord` without changing packed row layout.
- `UserListRecord` stays packed size `0x414`; the action compares and updates `huntersListFlag` at `+0x20e`, `hasSourceText` at `+0x20f`, and `sourceText[256]` at `+0x210` only when current local state differs.
- The destructor declaration is intentionally inline and empty. It allows the compiler to emit the observed three-view vptr resets, base teardown, adjustor thunks, and scalar-deleting wrapper without handwritten ABI mechanics.

## Constructor, Action, And Packet Contract

- Constructor order is exact: `DialogPane(L"",3,1)`, sound `0x198`/100, DLGSETUP EPF/PAL image, button resource `14`, hunters-list checkbox, 256-wide text source, mode/length/line limits, hover/focus/pending indices, background, create/show, and vertical slide-open.
- The action method tests control `2` and toggles/invalidate the checkbox; all other non-`1` control ids return. Control `1` closes first, persists checkbox/text state, validates password disclosure before sanitization, copies the sanitized 256-wide text, then conditionally mirrors/sends and finally queues deferred deletion.
- When `g_pUserListDialogPane` is active, the method scans the private all-record list for the local name. The binary dereferences the resulting row without a null guard; source preserves that invariant rather than adding behavior.
- The outbound packet is opcode byte `0x84`, hunters-list flag byte, and only when the flag equals `1`, one-byte MBCS length plus exactly that many converted bytes. PacketBuffer uses value-first writes; `g_packetSender->QueueAndSendPacket` sends 2 bytes or `encodedLength+3`. No NUL byte is part of the protocol payload.
- Fixed local buffers and source subscripts explain compiler range checks. Source retains normal arrays/indexing but does not emit explicit range-check failure, SEH, cookie, vptr, scalar-delete, or return-this machinery.

## Negative And Historical Evidence

- Rejected current identities: `OnDestroyChildControls` for `0x0059e3c0` and one-argument `OnAction` for `0x0059e3d0`. They remain only as superseded physical slugs/generated history.
- Rejected ownership/source shapes: constructor state on `g_pUserListDialogPane`, PartySearch-owned child pointers, UserPane source ownership, generic checkbox ownership transfer, a free constructor helper, a new source file, raw offset/reinterpret access, and handwritten vtable/RTTI/delete mechanics.
- The historical `g_pPlayerData`, opaque `m_preCollectionState[0x203]`, `m_partySearchListed`, and `m_partySearchText` names remain useful semantic lineage but are superseded by the current typed UserPane union.
- Exact original private/local spellings and source formatting are not recovered. This lexical uncertainty limits confidence to 93 without weakening the complete behavioral/source-ready declaration.

## Score Rationale

- `85/89 -> 92/93`: the class now has a complete compile-legal declaration, exact zero-member size relation, resolved virtual slots/signatures, constructor/action bodies, typed cross-source state access, source placement, destructor cause, and compiler exclusions.
- The score is not higher only because exact original lexical spellings and file formatting are inferred; no source, layout, ownership, or behavior blocker remains.

## Evidence Notes

- Live IDA MCP on 2026-06-04 confirms the current executable as `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` / SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- IDA function boundaries are exact for the constructor `0x0059e0d0-0x0059e393`, vtable reset helper `0x0059e3a0-0x0059e3bf`, no-op override `0x0059e3c0-0x0059e3c1`, action handler `0x0059e3d0-0x0059e707`, adjustor thunks `0x0059f001-0x0059f00c` and `0x0059f00c-0x0059f017`, and scalar deleting destructor `0x0059f0b0-0x0059f105`.
- `CodeRefsTo(0x0059e0d0)` reports only `0x0059db82`, inside `sub_59DA90` (`UserListDialogPane::OnControlCommand`), matching the user-list command `20` ownership path.
- The constructor installs the three `PartySearchEditPane` vtables at `0x0062ea40`, `0x0062eaa0`, and `0x0062ead0`, plays sound id `0x198`, loads `DLGSETUP.PAL` / `DLGSETUP.EPF`, inlines checkbox/text setup with label `Put me on the hunters list`, and stores the initial `CheckBoxTextControlPane::m_checked` byte into the child control at `+0x108`.
- The action handler is vtable-referenced at `0x0062ea88`. Action `2` reads and toggles the child `CheckBoxTextControlPane::m_checked` byte at `+0x108` and invalidates through the child vtable; action `1` stores the checked state through source-facing `g_pUserPane->SetHuntersListFlag(...)`, sanitizes/copies the text through `g_pUserPane->GetPartySearchSourceText()`, pushes opcode `0x84` at `0x0059e607`, appends the payload through packet helpers, and sends through `dword_67A7EC`. These inline accessors preserve the observed direct accesses at complete-object `+0x3cb1/+0x3cb2` and introduce no new binary entry.
- B009 2026-06-21 CheckBox setter support note: PartySearch is a consumer, not the owner of [UID:0003FH][0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw](by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md). Its constructor inlines setup for one reusable checkbox child, and its action handler directly toggles the child `m_checked` byte before invalidating the child control. That direct access explains why no call to the raw setter appears here; it does not demote the generic setter to dead code or move ownership into the social user-list module.
- The destructor path resets the same three vtables before base cleanup, and the two adjustor thunks at `0x0059f001` and `0x0059f00c` forward into the scalar deleting destructor.
- Exact vtable child [UID:0003E7][0x0062ea3c-0x0062eadc.PartySearchEditPaneVtableData](by-memory/0x0062ea3c-0x0062eadc.PartySearchEditPaneVtableData.md) records the three `.rdata` table bases, store/reset xrefs, and boundary between the checkbox-control child and `UserListPane`.
- 2026-06-18 B001 source-quality support note: the `"Put me on the hunters list"` label is direct evidence that the user-list row byte at `UserListRecord+0x20e` is `huntersListFlag` / `partySearchListed`, not hidden-user state. Current typed source uses `m_huntersListFlag` and `m_partySearchSourceText[256]`; historical `g_pPlayerData+0x3cb1/+0x3cb2` and opaque pre-collection bytes name the same UserPane storage. UID000477 mirrors incoming opcode `0x83` into the matching row, while PartySearch emits outbound `0x84`.

## Cross-References

- [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md)
- [UID:0000FN][UserListDialogPane](by-class/UserListDialogPane.md)
- [UID:0001KI][0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane](by-memory/0x0059bc90-0x0059f25b.UserListDialogPaneAndUserListPane.md)
- [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md)
- [UID:0002ZX][g_bShowHuntersListOnly](by-global/g_bShowHuntersListOnly.md)

## Changes

- 2026-07-19 B005 UID00047D accepted implementation callback: raised `85/89 -> 92/93`, installed the complete four-method zero-data-member class declaration, corrected primary slots to `OnPaint` and `OnControlCommand(int,int)`, and incorporated exact layout, constructor, state, packed-row, packet, teardown, source-placement, negative, rejected, and historical evidence. `[[CHILDREN]]` remains after the class-closing brace.
- 2026-07-19 B003 UID000477 support synchronization: scores, blank formal, owner/emitter route, and independent incomplete class/body debt remain unchanged. Added the exact `m_huntersListFlag` / `m_partySearchSourceText[256]` field and inline-accessor model used by constructor/action paths, preserving checkbox direct-toggle/invalidation, outbound opcode `0x84`, all control/vtable/layout facts, and historical aliases.

- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` and assigned parent `0000OZ`.
  - Before: reconstruction autogen classification and parent were blank despite IDA-backed documentation for a user-list dialog child class.
  - After: classified as reconstructable source attached to [UID:0000OZ][UserListDialogPane](by-file/UserListDialogPane.md).
  - Evidence: live IDA MCP `lookup_funcs` confirms the constructor/helper/no-op/action/destructor-thunk/deleting-destructor starts at `0x0059e0d0`, `0x0059e3a0`, `0x0059e3c0`, `0x0059e3d0`, `0x0059f001`, `0x0059f00c`, and `0x0059f0b0`; the class page documents the single constructor caller from the user-list command path and opcode `0x84` submission. The class score is `84/88` and parent file score is `86/82`, satisfying the 80/80 attach gate.

- Before: completion/confidence metadata were `0/0` even though the page already documented class behavior, constructor/action methods, caller evidence, and file-name uncertainty.
- Changed to: `COMPLETION:74` and `CONFIDENCE:76`.
- Evidence: dialog construction, checkbox/text edit behavior, opcode `0x84` submission, action handling, destructor support, caller path from `UserListDialogPane`, and provisional player-data offsets are documented; confidence remains medium because final file split and field names are still open.
- 2026-06-04: Raised completion from `74` to `84` and confidence from `76` to `88` after live IDA MCP verification of the party-search dialog class.
  - Before: the page had a stale naming caveat and treated the final user-list source placement as medium confidence.
  - After: the page records exact constructor/helper/action/destructor boundaries, the single constructor caller from `UserListDialogPane::OnControlCommand`, vtable addresses/refs, resource strings, checked-state storage, opcode `0x84` submit path, and destructor/adjustor relationship.
  - Evidence: live disassembly confirms `sub_59E0D0`, `sub_59E3A0`, `nullsub_62`, `sub_59E3D0`, `sub_59F001`, `sub_59F00C`, and `sub_59F0B0`; `CodeRefsTo(0x0059e0d0)` contains only `0x0059db82`; the constructor writes vtables `0x0062ea40/0x0062eaa0/0x0062ead0`; and `OnAction` uses child `+0x108`, player-data `+0x3cb1`, opcode `0x84`, and `dword_67A7EC`.
- 2026-06-11 A002 Batch227 strict-gate repair: Raised from `84/88` to `85/89` after splitting exact child [UID:0003E7][0x0062ea3c-0x0062eadc.PartySearchEditPaneVtableData](by-memory/0x0062ea3c-0x0062eadc.PartySearchEditPaneVtableData.md). Live IDA MCP reconfirmed the primary/secondary/tertiary table bases, destructor/adjustor first slots, constructor/helper/destructor store xrefs, backing function boundaries, and `UserListPane` successor boundary. C++ remains blank because final control/field names are still below final-source quality.
- 2026-06-18 B001 support incorporation: Added the hunters-list/party-search evidence tying the checkbox label, `g_pUserPane + 0x3cb1` / historical `g_pPlayerData+0x3cb1`, opcode `0x84`, opcode `0x83` row sync, `UserListRecord+0x20e`, and [UID:0002ZX][g_bShowHuntersListOnly](by-global/g_bShowHuntersListOnly.md) together. Score remains `85/89` because this was support evidence for the user-list dialog source-quality pass, not a full C++ pass for this class.
- 2026-06-22 Rule 26 support sync from B001 [UID:0001OR][0x0067a748-0x0067a74c.g_pCollectionData](by-memory/0x0067a748-0x0067a74c.g_pCollectionData.md):
  - Updated the party-search state write to source-facing `g_pUserPane + 0x3cb1`; `g_pPlayerData` is retained only as the historical local-player typed-view alias.
- 2026-06-21 Rule 26 B009 support incorporation: Kept score at `85/89` and clarified that PartySearch's checkbox setup/toggle is consumer evidence for `CheckBoxTextControlPane::m_checked` and separate invalidation, not ownership of the generic [UID:0003FH][0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw](by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md) method.
- 2026-06-26 B002 split implementation support sync: Added exact child UID links for constructor/action/cleanup/no-op/adjustor/scalar-deleting-destructor coverage. Outbound opcode `0x84`, checkbox consumer evidence, and user-list source-file ownership are preserved; formal C++ remains blank for complex PartySearch bodies until support declarations are complete.
