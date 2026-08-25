*** UID:00003O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class DeleteReplyAlert : public AlertPane
{
public:
    DeleteReplyAlert(bool deleteSucceeded,
                     const wchar_t *messageText,
                     Pane *layoutReference,
                     bool multiDelete);
    virtual ~DeleteReplyAlert();

    static DeleteReplyAlert *GetSingleton();

protected:
    virtual void OnPrimaryButton();

private:
    bool m_multiDelete;
    bool m_deleteSucceeded;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DeleteReplyAlert

## Status

- Confidence: very strong for reply-list deletion behavior, singleton lifecycle, exact class surface, and source-child split.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), or a private section of [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- Historical generated source lead: `source-3/simroot_v2/class_DeleteReplyAlert.cpp` (context only; current score relies on IDA-backed documentation).
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- Parent attachment: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md). The callback raises that source root to `90/92`; this class emits its declaration there and its four exact method children fill `[[CHILDREN]]` once.

## Role

`DeleteReplyAlert` reconciles local bulletin/article reply entries only after the server reports deletion success. It supports deleting selected replies or deleting a single reply by id, refreshes the owning dialog, and clears `g_pDeleteReplyAlert` during teardown.

B009 2026-06-19 MailDeleteReplyAlert comparison caveat remains important: do not copy this class's stored `+0x271` field into [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md). B005 2026-07-22 resolves the shared source signature instead: both constructors accept a first delete-result parameter and fourth all-versus-single parameter, but only `DeleteReplyAlert` stores the first result at `+0x271`; `MailDeleteReplyAlert` intentionally leaves that parameter unused and proves only `+0x270` as `m_deleteAllReplies`.

## Constructor Contract And Action Gates

Live IDA MCP session `9b0396a3` models constructor `0x0047e2f0` with four explicit parameters after `this`. The source-facing contract is:

```text
DeleteReplyAlert(bool deleteSucceeded,
                 const wchar_t *messageText,
                 Pane *layoutReference,
                 bool multiDelete)
```

- `deleteSucceeded` is a packet-derived result/local-removal gate. The constructor normalizes it into byte `this+0x271`.
- `messageText` and `layoutReference` are the alert text and owning layout/dialog reference forwarded through the base-construction shape.
- `multiDelete` is stored separately at `this+0x270` and selects selected-row versus single-reply deletion. Historical `deleteAllReplies` wording is rejected because the true branch removes only selected rows.
- Action `0x0047e390` checks `+0x271` first. It mutates the local reply list only when the delete result permits local removal, then checks `+0x270` to choose selected-row or one-reply-id behavior.

The four direct constructor calls preserve both gates: callsites `0x0047442f` and `0x004748c5` pass packet-derived result bytes with mode `1`; callsites `0x004769c7` and `0x00476add` pass packet-derived result bytes with mode `0`. This is the decisive modeled sibling evidence for UID0002T7's retained four-parameter mail constructor, while the storage difference explains why the mail variant has no `+0x271` field.

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| [UID:0004WC][0x0047e2f0-0x0047e34b.DeleteReplyAlertConstructor](by-memory/0x0047e2f0-0x0047e34b.DeleteReplyAlertConstructor.md) | `DeleteReplyAlert(bool deleteSucceeded, const wchar_t *messageText, Pane *layoutReference, bool multiDelete)` | Exact source child: initializes `AlertPane`, stores the two tail bytes, and publishes the singleton; vtable stores are compiler consequences. |
| [UID:0004WD][0x0047e350-0x0047e379.DeleteReplyAlertDestructor](by-memory/0x0047e350-0x0047e379.DeleteReplyAlertDestructor.md) | `~DeleteReplyAlert()` | Exact source child: clears the singleton; base/vtable teardown is compiler-generated. |
| [UID:0004WE][0x0047e380-0x0047e386.DeleteReplyAlertGetSingleton](by-memory/0x0047e380-0x0047e386.DeleteReplyAlertGetSingleton.md) | static `GetSingleton()` | Exact six-byte source accessor returning `g_pDeleteReplyAlert`. |
| [UID:0004WF][0x0047e390-0x0047e4a6.DeleteReplyAlertOnPrimaryButton](by-memory/0x0047e390-0x0047e4a6.DeleteReplyAlertOnPrimaryButton.md) | `OnPrimaryButton()` | Exact virtual source child: success gate, selected-row reconciliation, or single-ID reconciliation with refresh/pop. |
| [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | adjustor thunks | Secondary/tertiary vtable thunks to scalar deleting destructor `0x0047eb30`. |
| [UID:0003Q6][0x0047eb30-0x0047eb8f.DeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb30-0x0047eb8f.DeleteReplyAlertScalarDeletingDestructor.md) | scalar deleting destructor | Compiler ABI wrapper generated from the ordinary virtual destructor; documentary, non-reconstructable, and non-emitting. |

## Evidence Map

| Evidence | Impact |
| --- | --- |
| [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md) | Records the modeled constructor/destructor/getter/action starts, the destructor wrapper strip, and the source-neighborhood relationship to the other bulletin/mail alert classes. |
| [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) | Provides the shared source-owner bucket for reply/delete alert wrappers; now `89/91`, so the parent gate passes. |
| [UID:0003Q0][0x0047e2f0-0x0047e4a6.DeleteReplyAlertMethods](by-memory/0x0047e2f0-0x0047e4a6.DeleteReplyAlertMethods.md) | Exact grouped constructor/destructor/getter/action child with the modeled four-parameter prototype, caller modes, separate `+0x271`/`+0x270` gates, and action consumption order. |
| [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) | Anchors the board/article alert vtable family and supports keeping this class with the bulletin alert wrappers instead of generic dialog/session code. |
| [UID:000033][ConfirmDeleteAlert](by-class/ConfirmDeleteAlert.md) | Sibling delete-confirm class now documents exact constructor/action children and the shared board/article delete-alert context. |

2026-06-14 C001 IDA MCP recheck on `a001_goal2_class_batch` confirms function starts at `0x0047e2f0`, `0x0047e350`, `0x0047e380`, `0x0047e390`, and `0x0047eb30`; constructor callers remain `0x0047442f`, `0x004748c5`, `0x004769c7`, and `0x00476add`. The constructor stores the three DeleteReplyAlert vtable pointers at `this+0x00`, `this+0xa0`, and `this+0xa4`, stores mode bytes at `this+0x270` and `this+0x271`, and writes `g_pDeleteReplyAlert` (`0x0067adb8`). Vtable refs still tie primary `0x00614624`, secondary `0x0061468c`, and tertiary `0x006146bc` to the constructor, non-deleting destructor, and scalar deleting destructor.

The same pass confirms the confirm handler at `0x0047e390-0x0047e4a6` is vtable-only at slot data `0x00614680`, branches on the constructor mode byte, deletes selected reply rows through the local list-removal helper path, handles a single reply id through `sub_474E10`, refreshes the owner dialog through its virtual `+0x4c`, and calls `sub_4A10E0(0)` on the single-reply branch. Hex-Rays reports a bad stack-value warning for this handler, so the behavior is documented at control-flow/API level rather than as final C++.

B005 2026-07-22 reanalysis refines “branches on the constructor mode byte” into two ordered decisions: action `0x0047e390` first checks the packet-result/local-removal gate stored at `+0x271`, and only then checks all-versus-single mode at `+0x270`. The constructor's direct caller pairs are mode `1` at `0x0047442f`/`0x004748c5` and mode `0` at `0x004769c7`/`0x00476add`, each with a packet-derived first argument.

## Current Source Closure

- Object tail: inherited [UID:0001TO][AlertPaneLayout](by-type/by-struct/AlertPaneLayout.md) ends at `+0x270`; `m_multiDelete` occupies `+0x270` and `m_deleteSucceeded` occupies `+0x271`.
- Declaration shape: ordinary constructor/destructor, static singleton getter, protected primary-button override, and two private bool fields. This is realistic mid-2000s C++ source and contains no address-derived names.
- Emission shape: this page emits only R1 plus `[[CHILDREN]]`; UID0004WC/WD/WE/WF emit R2-R5. Parent UID0003Q0 is a non-emitting split index, UID0003Q6 is compiler-only ABI glue, and UID0002W4 is data-only storage.
- Action helpers: selected mode uses `GetArticleListPane`, `GetSelectedIndices`, `RemoveItems`, and `RefreshContents`; single mode uses `GetDialogSession`, `FindPreviousDialog`, `GetCurrentArticleId`, `FindArticleById`, `RefreshContents`, and `PopCurrentDialog(false)`.
- Source root: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) remains the strongest current bucket. `BoardDialogs` remains a historical file-split alternative, not a second emitter.

Historical no-code text reflected the then-unsplit aggregate and unresolved helper/field names. The UID0003Q0 source-closure pass resolves those blockers and supersedes that disposition. Historical `OnConfirm` and `deleteAllReplies` labels remain evidence history only; the current source-facing names are `OnPrimaryButton` and `m_multiDelete`.

## Autogen And Score Rationale

- Reconstructable: true for the source-owned alert wrapper class.
- Parent: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
- Code: exact R1 declaration plus `[[CHILDREN]]`; the four exact by-memory children emit R2-R5 and no aggregate/scalar/storage body duplicates them.
- Completion is `92` because the page records the complete modeled surface, exact split, class declaration, two field roles, helper contracts, singleton lifecycle, source root, generated composition, historical corrections, and compiler-wrapper exclusion.
- Confidence is `94` because function boundaries, callers, field stores/reads, vtables, singleton refs, branch semantics, and helper contracts are binary-backed. Only original source spellings and final historical physical-file split remain inferred.

## Cross-References

- [UID:0003Q0][0x0047e2f0-0x0047e4a6.DeleteReplyAlertMethods](by-memory/0x0047e2f0-0x0047e4a6.DeleteReplyAlertMethods.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:000033][ConfirmDeleteAlert](by-class/ConfirmDeleteAlert.md)

## B006 2026-06-29 Implementation Callback

- Historical C06 disposition: the earlier narrowed callback left this class as an index/no-code page because it did not investigate the board-side child island. The later UID0003Q0 source-closure callback supersedes that state with exact R1-R5 class/child emission and explicit aggregate/scalar exclusions.

## Changes

- 2026-07-22 B005 accepted UID0003Q0 implementation callback:
  - Raised `86/89` to `92/94` and replaced the historical no-code marker with the exact AlertPane-derived class declaration and `[[CHILDREN]]`.
  - Added exact UID0004WC/WD/WE/WF source children, corrected `deleteAllReplies`/`OnConfirm` to `m_multiDelete`/`OnPrimaryButton`, documented `m_deleteSucceeded`, and separated source methods from parent/index, storage, padding, and scalar ABI glue.
- 2026-07-22 B005 accepted UID0002T7 support sync: metadata and formal C++ unchanged at `86/89`. Added the exact modeled four-parameter constructor contract, direct caller modes, `+0x271` delete-result/local-removal gate, `+0x270` all-versus-single mode, action consumption order, and the precise comparison with MailDeleteReplyAlert's intentionally unused first parameter. Also corrected stale parent-score and missing-child prose.
- 2026-06-21 supervisor-worker Rule 26 incorporation of B009 `00007J-MailDeleteReplyAlert-class-source-quality.md`: no score change. Added a comparison caveat that DeleteReplyAlert's extra mode bytes should not be copied into MailDeleteReplyAlert; the mail sibling only proves `+0x270` as `m_deleteAllReplies`.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/86`.
  - Summary/evidence: constructor, non-deleting destructor, singleton getter, confirm behavior, adjustors, scalar deleting destructor, and bulletin-alert ownership are documented; remaining work is detailed owner-dialog field naming.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After: `RECONSTRUCTABLE:TRUE`; owner/emitter routing was still left blank at that time because the class completion score was below the then-active attachment gate.
  - Evidence: live IDA MCP confirms modeled starts at `0x0047e2f0`, `0x0047e350`, `0x0047e380`, `0x0047e390`, and `0x0047eb30`, with constructor callers from board/reply paths at `0x0047442f`, `0x004748c5`, `0x004769c7`, and `0x00476add`.
- 2026-06-07 A004:
  - Before: page was reconstructable but unattached at `78/86` because it missed the completion side of the parent gate.
  - After: completion raised to `80`, attached to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md); confidence remains `86`.
  - Summary/evidence: existing IDA-backed method starts, singleton lifecycle, confirm/delete behavior, [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md), refreshed `BulletinReplyAlerts` parent score `82/86`, and sibling [UID:000033][ConfirmDeleteAlert](by-class/ConfirmDeleteAlert.md) support attachment. C++ remains blank because exact child pages and final owner-dialog field names remain open.
- 2026-06-14 C001 Goal 2 refresh:
  - Before: score was `80/86` and parent-score/gate wording was stale.
  - After: score is `85/88`; owner/emitter routing remains [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), and C++ remains blank.
  - Summary/evidence: current IDA MCP confirms the modeled method starts, four constructor callers, singleton refs, three vtable pointer refs, scalar destructor refs through adjustor thunks, and confirm-handler control flow. Exact per-method by-memory children and final owner-dialog/list field names remain open.
