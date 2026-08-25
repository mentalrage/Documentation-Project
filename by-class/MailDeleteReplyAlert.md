*** UID:00007J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MailDeleteReplyAlert : public AlertPane
{
public:
    MailDeleteReplyAlert(bool deleteSucceeded,
                         const wchar_t *messageText,
                         Pane *layoutReference,
                         bool deleteAllReplies);
    virtual ~MailDeleteReplyAlert();

protected:
    virtual void OnPrimaryButton();

private:
    bool m_deleteAllReplies;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MailDeleteReplyAlert

## Status

- Confidence: very strong for reply-list deletion behavior, singleton handling, vtable ownership, exact child coverage, destructor/action ranges, the four-parameter constructor contract, and the inherited primary-button override name; strong for the selected shared-alert source placement.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), with [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) retained as the strongest alternate private placement. The current owner stays `BulletinReplyAlerts` because the mail alert vtables, singleton/global route, constructor-shaped companion bodies, and sibling alert wrappers are interleaved in the shared mail/bulletin alert route rather than isolated in the `MailDialogs` method range.
- Parent attachment: attached to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), whose current score is `88/90` and projected path is `NexusTK/ui/dialogs/`.
- Current recovered file: `source-3/simroot_v2/class_MailDeleteReplyAlert.cpp`
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- Exact memory children: [UID:0002T7][0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor](by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md), [UID:0002T8][0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter](by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md), [UID:0002T9][0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete](by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md), and [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md).
- B005 2026-07-22 source-quality status: live sibling and caller analysis resolves the raw constructor as a retained source-authored `MailDeleteReplyAlert(bool deleteSucceeded, const wchar_t *messageText, Pane *layoutReference, bool deleteAllReplies)` body. The first parameter is an intentionally unused result gate at this constructor layer; the four optimized construction mirrors evaluate and discard the corresponding packet result immediately before reproducing the constructor body. The class remains under [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), and `this+0x270` remains the derived tail byte `m_deleteAllReplies`.
- Reconstruction note: this class hub emits the source-facing declaration and `[[CHILDREN]]` insertion point. Exact method bodies remain owned by child pages: [UID:0002T7][0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor](by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md) emits the constructor, [UID:0002T8][0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter](by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md) emits destructor/getter source, [UID:0002T9][0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete](by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md) emits the inherited primary-button override, and [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md) remains compiler-generated scalar-deleting-destructor support.

## Role

`MailDeleteReplyAlert` confirms local deletion of mail reply rows. It supports deleting all selected replies or deleting a single reply id, refreshes the mail dialog/list view, optionally pops the session dialog, and clears `g_pMailDeleteReplyAlert` during teardown.

## Layout And Field Roles

| Storage | Best source-facing role | Evidence and caveat |
| --- | --- | --- |
| inherited `AlertPane+0x26c` | `AlertPane::m_layoutReference`, locally used as `MailDialog *ownerDialog` / `currentDialog` | [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md) owns the inherited field. This class consumes it as the current mail dialog in [UID:0002T9][0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete](by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md). Do not add a second derived field at `+0x26c` without a class-layout proof. |
| derived `this+0x270` | `m_deleteAllReplies` | Written by the constructor and inline construction sites, then read by the primary-button override `OnPrimaryButton` (historically described as `OnConfirmDelete`). `true` selects bulk deletion of selected reply rows in the current reply list; `false` selects one reply id in the previous mail dialog and pops the current dialog. `m_deleteSelectedReplies` is an acceptable prose alias; rejected names include `m_isMailDelete`, `m_deleteAllMail`, `m_replyMode`, and generic `m_flag270`. |
| allocation/deleting-destructor size `0x274` | object size / tail padding after `m_deleteAllReplies` | Size is proven by the scalar deleting destructor. Only byte `+0x270` is class-specific evidence here; do not infer additional `+0x271` fields just because the object rounds up to `0x274`. |

Related mail-dialog fields used by this class:

- `MailDialog+0x270` is the dialog-session/context pointer used with `DialogSession::FindPreviousDialog` and `DialogSession::PopCurrentDialog`; preferred prose name is `m_dialogSession`.
- `MailDialog+0x274` is the 16-bit current/target reply id used by the single-reply deletion branch; preferred prose name is `m_currentReplyId` or `m_selectedReplyId`, with `m_currentReplyId` preferred for this read/reply dialog context.
- `DialogPane/MailDialog+0x1fc` is the inherited control manager/list. This alert requests child/control id `7`, best documented as `kReplyListControlId`.
- The child object returned from the control manager exposes the reply-list pane through `+0x108`.

## Constructor Contract

The retained constructor and modeled [UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md) sibling establish the same four source parameters after `this`:

| Stack/source parameter | Best source-facing declaration | Role |
| --- | --- | --- |
| `[ebp+0x08]` | `bool deleteSucceeded` | Result/status gate supplied by the caller family. This class constructor intentionally does not store or branch on it; the optimized inline mirrors evaluate and discard the corresponding packet result before reproducing the body. |
| `[ebp+0x0c]` | `const wchar_t *messageText` | Alert message forwarded to `AlertPane`. |
| `[ebp+0x10]` | `Pane *layoutReference` | Dialog/layout context forwarded to `AlertPane` and later consumed through inherited `m_layoutReference`. |
| `[ebp+0x14]` | `bool deleteAllReplies` | Stored in derived byte `m_deleteAllReplies` at `+0x270`. |

The exact `ret 0x10` ABI proves four callee-cleaned arguments. The body initializes `AlertPane(messageText, layoutReference, L"OK", 0)`, installs the class's three vtables, stores `deleteAllReplies`, and publishes `g_pMailDeleteReplyAlert`. The unused `deleteSucceeded` parameter is retained because the modeled sibling signature and all four caller mirrors preserve that source-level contract even though optimization removes its use here.

## Primary-Button Confirm Behavior

The behavior historically labeled `OnConfirmDelete` is the inherited `AlertPane` primary-button virtual and therefore emits as `MailDeleteReplyAlert::OnPrimaryButton`. It is reached through class vtable slot `0x006147c8`, corresponding to the base primary-button slot at `+0x5c`, not through a direct helper call. The handler allocates a `0x40c` stack frame, installs a stack cookie from `0x00672f24`, reads the current dialog from inherited `m_layoutReference`, then branches on `m_deleteAllReplies`.

Bulk selected-reply mode (`m_deleteAllReplies != 0`):

- Uses the current mail dialog's control manager at `+0x1fc` to request child/control id `7`.
- Reads the reply-list object through the child object's `+0x108` field.
- Calls [UID:0003U0][0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers](by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md) helper `ListPane::GetSelectedIndices(int *outIndices, int maxCount)` at `0x004f3e80` with a stack buffer at `[ebp-0x404]` and maximum `0x100` entries.
- Removes each selected row with `ListPane::RemoveItems(index - alreadyRemovedCount, 1)` at `0x004f3d60` so later selected indexes stay valid after earlier removals.
- Calls the current mail dialog refresh virtual at vtable slot `+0x4c`; exact source spelling is unrecovered, so use a role name such as `RefreshContents()` only in draft prose.
- Returns without popping the dialog/session stack.

Single-reply mode (`m_deleteAllReplies == 0`):

- Reads `MailDialog::m_dialogSession` from the current dialog at `+0x270`.
- Calls [UID:000132][0x004a0f40-0x004a14a7.BulletinSessionDialogStack](by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md) helper `DialogSession::FindPreviousDialog` at `0x004a1250`, passing the current dialog as the search marker.
- Reads the target reply id word from current dialog `+0x274`.
- Requests child/control id `7` from the previous dialog, reads its reply-list object through `+0x108`, and calls `MailListPane::FindMailIdIndex` at `0x0047acd0`. In this callsite the searched id is a reply id; keep the global helper name mail-id oriented because the same helper also serves mail-list semantics.
- Removes one row with `ListPane::RemoveItems(row, 1)` when the lookup does not return `-1`.
- Calls the previous dialog refresh virtual at vtable slot `+0x4c`.
- Calls `DialogSession::PopCurrentDialog(false)` at `0x004a10e0` through `m_dialogSession`, closing the transient current reply dialog/session view.

## Names And Source Policy

- Singleton storage `0x0067adbc` is best named [UID:0002W5][g_pMailDeleteReplyAlert](by-global/g_pMailDeleteReplyAlert.md) with type `MailDeleteReplyAlert *`. B009's PE scan found direct refs around `0x0047a483`, `0x0047a4e2`, `0x0047a811`, `0x0047a870`, `0x0047cb1a`, `0x0047cc50`, `0x0047e6e3`, `0x0047e70c`, `0x0047e721`, and `0x0047ebb2`.
- The raw constructor passes `0x00613a18` as the shared alert OK/primary-button resource pointer into [UID:00012W][0x0049feb0-0x004a0686.AlertPaneCore](by-memory/0x0049feb0-0x004a0686.AlertPaneCore.md). Existing names such as `g_alertPaneButtonLayout` are descriptive only until the resource/string data is verified.
- `ListPane::GetSelectedIndices`, `ListPane::RemoveItems`, `MailListPane::FindMailIdIndex`, `DialogSession::FindPreviousDialog`, and `DialogSession::PopCurrentDialog` are the best current helper names for this target's behavior. The mail dialog refresh virtual at slot `+0x4c` remains role-named only.
- `OnPrimaryButton` is the emitted C++ name for the action at `0x0047e730` because it occupies inherited `AlertPane` slot `+0x5c`. `OnConfirmDelete` remains useful only as a descriptive behavior alias and historical document title; emitting a differently named virtual would break the source inheritance contract.
- `MailDialogs` is a consumer/source context: mail-list and mail-dialog paths inline-construct or reuse this alert, but current implementation ownership remains [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| [UID:0002T7][0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor](by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md) | `MailDeleteReplyAlert(bool deleteSucceeded, const wchar_t *messageText, Pane *layoutReference, bool deleteAllReplies)` | Source-authored retained constructor body. Initializes `AlertPane`, stores `m_deleteAllReplies`, installs mail-delete reply vtables, and writes the singleton; the modeled sibling and four optimized mirrors resolve its source signature despite the absent direct entry xref. |
| [UID:0002T8][0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter](by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md) | non-deleting destructor and singleton getter | Resets vtables, clears/returns `g_pMailDeleteReplyAlert`, and destroys base alert/dialog state. |
| [UID:0002T9][0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete](by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md) | `OnPrimaryButton` (`OnConfirmDelete` behavior alias) | Overrides the inherited primary-button virtual, removes selected or single reply rows from the mail list, refreshes the owning dialog, and pops back to the previous dialog for single-delete mode. |
| [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | adjustor thunks | Secondary/tertiary vtable thunks to scalar deleting destructor `0x0047eb90`. |
| [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md) | scalar deleting destructor | Clears the singleton, destroys base state, and optionally frees memory. |

## Evidence Notes

- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md) records IDA-confirmed starts for `0x0047e6f0`, `0x0047e720`, `0x0047e730`, and `0x0047eb90`, while keeping `0x0047e6a0` as a projected raw constructor start.
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md) records the `MailDeleteReplyAlert` primary/secondary/tertiary vtable bases and current IDA-backed constructor/destructor store sites.
- [UID:0002AI][0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons](by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md) records former `dword_67ADBC` as `MailDeleteReplyAlert *g_pMailDeleteReplyAlert` and cites xrefs from this class neighborhood.
- Current `simroot_v2/class_MailDeleteReplyAlert.cpp` remains a lead for branch shape and helper calls only; final helper/type names are not source-quality.
- B009 2026-06-19 local PE/Capstone scan against `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` found no direct route to raw constructor start `0x0047e6a0` by `E8/E9 rel32`, absolute VA dword, vtable slot, jump table, or interior entry. This closes the raw-constructor question as a retained constructor-shaped body, not padding and not a confirmed live-called entry.
- B009 reconfirmed inline constructor sequences that corroborate the raw constructor body: `0x0047a4bf/0x0047a4c5/0x0047a4cf` and `0x0047a84d/0x0047a853/0x0047a85d` set `this+0x270 = 1` in mail-list delete-reply paths, while `0x0047caf7/0x0047cafd/0x0047cb07` and `0x0047cc2d/0x0047cc33/0x0047cc3d` set `this+0x270 = 0` in `MailDialog` delete-reply paths.
- B005 2026-07-22 live IDA MCP session `9b0396a3` reanalyzed the retained constructor, the modeled `DeleteReplyAlert` sibling at `0x0047e2f0`, the sibling action at `0x0047e390`, and all four optimized mirrors. The sibling prototype exposes four parameters after `this`; its constructor stores the first result gate at `+0x271` and the fourth all-versus-single mode at `+0x270`, while its action consumes both. In each MailDelete mirror, the corresponding packet result is evaluated and discarded immediately before the body: `0x0047a42b` and `0x0047a7b9` precede mode `1` constructions, while `0x0047ca63` and `0x0047cb99` precede mode `0` constructions. This resolves the old absent-entry observation as optimized retained/source-authored constructor evidence rather than a no-code disposition.
- The same vtable comparison places `0x0047e730` in inherited `AlertPane` primary-button slot `+0x5c`; `OnPrimaryButton` is therefore the source-compatible override name, while `OnConfirmDelete` is retained only as a behavior-oriented historical alias.
- 2026-06-14 live IDA MCP `lookup_funcs` reconfirmed the expected class support shape: raw constructor start `0x0047e6a0` is still not an IDA function, non-deleting destructor `0x0047e6f0` is size `0x29`, singleton getter `0x0047e720` is size `0x6`, confirm action `0x0047e730` is size `0x106`, scalar deleting destructor `0x0047eb90` is size `0x5f`, and neighboring functions at `0x0047e840`, `0x0047eb30`, and `0x0047ebf0` remain modeled boundaries.
- 2026-06-14 `xrefs_to` reconfirmed the confirm action's vtable data ref at `0x006147c8`, scalar-destructor refs from adjustor thunks `0x0047e90b`/`0x0047e916` plus vtable slot `0x0061476c`, and `g_pMailDeleteReplyAlert` refs at constructor write `0x0047e6e1`, destructor clear `0x0047e70a`, getter read `0x0047e720`, scalar-destructor clear `0x0047ebb0`, and six mail/list/read construction or use sites.
- [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md) now carries owner-specific mail-alert vtable evidence at `86/89`, and [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) clears the current direct-parent gate at `85/86`.
- B006 2026-06-20 MailDialog reanalysis keeps [UID:00007K][MailDialog](by-class/MailDialog.md) as an inline construction/use site for mail delete-reply alerts, not as the current source owner of this alert implementation. This class remains routed through [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) unless later source-split evidence proves mail-private placement in [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).
- B007 2026-06-20 MailListDialog reanalysis adds [UID:00007L][MailListDialog](by-class/MailListDialog.md) as another concrete consumer: incoming mail-list packet `packet[1] == 7` and helper pocket `0x0047a760` convert packet text, create or reuse this alert, and write the `g_pMailDeleteReplyAlert` singleton/global alert state. This is caller/context evidence only; it does not move this class out of [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).

## Autogen Status

- Marked reconstructable and attached to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) after exact child pages and vtable/singleton evidence raised this class above the `80` confidence attachment gate.
- Parent position `70` follows the sibling order in [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md): article transfer, predefined transfer, mail transfer, board delete-confirm, board reply-delete, mail delete-confirm, then mail reply-delete.
- The class page now emits the source-facing declaration and `[[CHILDREN]]` insertion point. Exact child pages still own method bodies, so the class declaration does not duplicate child coverage; the scalar deleting destructor remains generated support and is not declared separately.

## Score Rationale

- Completion reaches `91` because the class now has exact child memory pages, a source-emitting four-parameter constructor, destructor/getter support, an inherited-primary-button override, scalar deleting destructor support, singleton storage, owner-specific vtables, field/role naming, helper routes, optimized caller-mirror reconciliation, and rejected source-placement alternatives.
- Confidence reaches `93` because the retained constructor's `ret 0x10`, modeled sibling prototype and field stores, four caller-result evaluations, mode-specific mirrors, and vtable-slot inheritance jointly resolve the prior entry-route and `OnConfirmDelete` naming questions. The delete-all versus single-reply behavior is branch-proven, `m_deleteAllReplies` at `+0x270` is strongly supported, and source ownership has a documented selected owner plus rejected `MailDialogs` alternate.
- Confidence remains below final-source level because exact source spellings for the alert OK resource at `0x00613a18`, the mail-dialog refresh virtual at slot `+0x4c`, and several inherited dialog/control helper names are not recovered.

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- [UID:0002T7][0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor](by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md)
- [UID:0002T8][0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter](by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md)
- [UID:0002T9][0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete](by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md)
- [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md)
- [UID:0002AI][0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons](by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md)
- [UID:00007K][MailDialog](by-class/MailDialog.md)
- [UID:00007L][MailListDialog](by-class/MailListDialog.md)
- [UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md)

## Historical B006 2026-06-29 Implementation Callback

- Accepted C07 originally kept this class page as an index/no-code row with `[[CHILDREN]]`. Its correction of the older broad "child bodies blank" treatment remains historically valid, but the constructor no-code disposition is superseded by B005's 2026-07-22 sibling/caller reconciliation. The class page now emits the declaration; [UID:0002T7][0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor](by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md), [UID:0002T8][0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter](by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md), and [UID:0002T9][0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete](by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md) own emitted method source, while [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md) remains compiler support.

## Changes

- 2026-07-22 B005 accepted UID0002T7 implementation callback:
  - Changed completion/confidence from `89/91` to `91/93`; owner/emitter remain [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
  - Added the formal class declaration, exact four-parameter constructor contract, intentionally unused `deleteSucceeded` parameter, `m_deleteAllReplies` field, and inherited `OnPrimaryButton` override name.
  - Incorporated live sibling/caller evidence, four discarded packet-result evaluations, mode `1` versus mode `0` construction mirrors, primary-button vtable-slot evidence, and the distinction between emitted `OnPrimaryButton` and historical behavior alias `OnConfirmDelete`.
  - Historicalized the superseded raw-constructor no-code and class-empty assumptions while preserving their valid no-direct-xref evidence and the existing behavior/source-placement record.
- 2026-06-21 supervisor-worker Rule 26 incorporation of B009 `00007J-MailDeleteReplyAlert-class-source-quality.md`:
  - Changed score from `85/86` to `88/90`; owner/emitter remain [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
  - Incorporated raw-constructor no-route proof, inline construction sites, `m_deleteAllReplies` at `+0x270`, inherited `AlertPane::m_layoutReference` use as `MailDialog *`, delete-all versus single-reply behavior, helper/global/vtable names, rejected `MailDialogs` ownership move, rejected field/name alternatives, and exact class-page no-code proof.
  - Formal class C++ remains blank because child by-memory pages own exact method bodies and the class hub would overclaim final helper/control-manager names.
- 2026-06-20 supervisor-worker Rule 26 incorporation of B007 `00007L-MailListDialog-class-source-quality.md`: added MailListDialog packet `7` / helper `0x0047a760` as a concrete create/reuse context while preserving current shared alert ownership.
- 2026-06-20 supervisor Rule 26 incorporation of B006 MailDialog source-quality report: fixed the stale parent-score note for [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) and recorded that MailDialog is currently an inline consumer/use site, not this alert class's owner.
- 2026-06-14 A001 Goal 2 low-confidence refresh:
  - Changed completion/confidence from `82/82` to `85/86`.
  - Evidence: live IDA MCP session `b001_0003gy` reconfirmed the raw constructor caveat, modeled destructor/getter/action/scalar-destructor function sizes, confirm-action vtable data ref, scalar-destructor adjustor/vtable refs, and all ten `g_pMailDeleteReplyAlert` xrefs. The class also now points to the owner-specific [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md) evidence and a direct file parent [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) that clears `85/85`.
  - Final C++ remains blank under the active 90/90+ source-entry gate because constructor reachability, final field names, and shared-alert-versus-mail-private source split remain open.
- Completion/confidence score update: existed before as `0/0`; changed to `72/74`. Summary: reply-list deletion behavior, singleton handling, confirmation path, and destructor/adjustor coverage are documented, but the constructor boundary and final source split remain medium confidence. Evidence: companion memory range, delete-all/single-delete role, singleton getter/global behavior, `OnConfirmDelete`, and IDA constructor-boundary caveat.
- 2026-06-02: Raised from `72/74` to `82/82`, marked reconstructable, and attached to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
  - Before: the page had only coarse method ranges and no exact child pages.
  - After: the page links exact child memory pages [UID:0002T7][0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor](by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md), [UID:0002T8][0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter](by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md), [UID:0002T9][0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete](by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md), and [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md).
  - Evidence: existing IDA-recorded function starts, vtable-family store evidence, singleton xref documentation, and companion aggregate ownership notes.
- 2026-06-07 A004: Set `AUTOGEN_PARENT_POSITION_OPTIONAL` to `70` to match the established [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) sibling order; no score change because this is an autogen ordering sync, not new behavioral evidence.
