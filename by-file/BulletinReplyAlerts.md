*** UID:0000HW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# BulletinReplyAlerts

## Status

- Confidence: strong that these are shared bulletin/mail alert wrappers; medium for whether the original project used a separate source file.
- Proposed module folder: `ui/dialogs/`
- Proposed source file: `ui/dialogs/BulletinReplyAlerts.cpp`
- Alternate placement: private classes in [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), and [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md).
- Current generated sources: `class_TransferReplyAlert.cpp`, `class_TransferReplyPredefinedAlert.cpp`, `class_MailTransferReplyAlert.cpp`, `class_ConfirmDeleteAlert.cpp`, `class_DeleteReplyAlert.cpp`, `class_ConfirmDeleteMailAlert.cpp`, and `class_MailDeleteReplyAlert.cpp`.
- Evidence basis: `simroot_v2`, `.meta_wave3`, older Wave2 report notes, IDA MCP checks on 2026-05-24 through 2026-06-06, and B001-009 owner-specific mail-alert vtable split on 2026-06-10.

## Hypothesis

The reply/delete alert classes are small `AlertPane` subclasses compiled in the same board/mail neighborhood as the bulletin dialogs. They bridge server reply packets, local list mutation, and dialog-session navigation. In a reconstructed source tree they can either be a small shared alert source file or private helper classes split between the board/article and mail dialog files.

Likely structure:

```text
ui/dialogs/BulletinReplyAlerts.cpp
```

Possible compact legacy structure:

```text
ui/dialogs/BulletinDialogs.cpp
```

## Reconstruction Handling

- The assigned reconstruction path is `NexusTK/ui/dialogs/BulletinReplyAlerts.cpp`.
- Treat this file page as the source-owner bucket for confirmed small reply/delete alert wrappers until individual original file names are proven.
- Do not emit final reconstructed C++ from this file yet. The wrapper grouping is useful for autogen ownership, but several constructors remain projected or raw-disassembly-only and the original source split is still not final-source quality.

## Source Ownership Matrix

| Group | Strong source-owner evidence | Remaining caveat |
| --- | --- | --- |
| Article transfer reply alerts | [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md), [UID:0002EL][0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm](by-memory/0x00478fe0-0x0047904f.TransferReplyAlertOnConfirm.md), and the related board/article vtable family tie constructor, action, vtables, and article-navigation behavior together. | Could still be private to [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) rather than a separate source root. |
| Predefined-form transfer reply alerts | [UID:0002EM][0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor](by-memory/0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor.md) and [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md) show the same article-navigation packet pattern as the regular transfer alert and correct the active generated body. | Final placement may be private to [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md). |
| Board/article delete confirmations | [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md) and [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md) give exact constructor and delete-packet children. | Final row/list field names and the surrounding `DeleteReplyAlert` helper split remain incomplete. |
| Mail delete reply alerts | [UID:0002T7][0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor](by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md), [UID:0002T8][0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter](by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md), [UID:0002T9][0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete](by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md), and [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md) now make the mail-delete side a split exact child family, not only a projected row. | Mail-transfer and confirm-delete-mail constructor starts still need exact raw pages before the whole file can be treated as near-final. |
| Mail alert companion vtables | [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md) records the `MailTransferReplyAlert`, `ConfirmDeleteMailAlert`, and `MailDeleteReplyAlert` decorated vtable bases, COL pointers, store xrefs, and shared `ConfirmDeleteAlert`/`DeleteReplyAlert` gap exclusion. | The mail-specific alert wrappers remain a strong alternate fit for [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), but current direct-owner routing keeps them with this shared board/mail alert wrapper bucket. |
| Reply-delete alert singleton storage | [UID:0002AI][0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons](by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md) records `g_pDeleteReplyAlert` and `g_pMailDeleteReplyAlert` as the adjacent source-declared singleton pointers for the board/article and mail reply-delete alert wrappers. | The two slots are adjacent declarations, not one runtime aggregate; keep the declarations with this shared alert wrapper bucket unless later source-split evidence moves the mail-only alert back into `MailDialogs.cpp`. |
| Destructor and adjustor strip | [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md), [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md), and [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md) keep compiler-generated thunks/destructor wrappers out of handwritten source decisions. | Locality alone should not move every scalar deleting destructor into this source file. |

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| [UID:0000F5][TransferReplyAlert](by-class/TransferReplyAlert.md) | constructor [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md); action `0x00478fe0-0x0047904e`; destructor companions `0x0047e8d9-0x0047eb2a` | `class_TransferReplyAlert.cpp` | Article/bulletin transfer reply acknowledgement; sends article navigation packet and optionally pops the session dialog. |
| [UID:0000F6][TransferReplyPredefinedAlert](by-class/TransferReplyPredefinedAlert.md) | raw constructor [UID:0002EM][0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor](by-memory/0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor.md); action [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md) | `class_TransferReplyPredefinedAlert.cpp` | Predefined-form article transfer reply acknowledgement. Active Wave3 body is suspect; IDA shows the same navigation-packet pattern as `TransferReplyAlert`, and the raw constructor now has corrected vtable target `0x00614194`. |
| [UID:00007N][MailTransferReplyAlert](by-class/MailTransferReplyAlert.md) | projected constructor `0x0047e040`; action `0x0047e090-0x0047e0ff` | `class_MailTransferReplyAlert.cpp` | Mail transfer reply acknowledgement; sends mail navigation packet and optionally pops the session dialog. |
| [UID:000033][ConfirmDeleteAlert](by-class/ConfirmDeleteAlert.md) | constructor [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md); action [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md) | `class_ConfirmDeleteAlert.cpp` | Board/article delete confirmation that sends one or more opcode `0x3b`, subcommand `0x05` delete packets. |
| [UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md) | `0x0047e2f0-0x0047e4a5`; destructor companions `0x0047e8ef-0x0047eb8e` | `class_DeleteReplyAlert.cpp` | Local reply-list deletion confirmation for bulletin/article replies. |
| [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md) | projected constructor `0x0047e4b0`; action [UID:0002SF][0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest](by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md) | `class_ConfirmDeleteMailAlert.cpp` | Mail delete confirmation that sends one or more opcode `0x3b`, subcommand `0x05` mail delete packets. |
| [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md) | raw constructor [UID:0002T7][0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor](by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md); destructor/getter [UID:0002T8][0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter](by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md); action [UID:0002T9][0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete](by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md); scalar destructor [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md) | `class_MailDeleteReplyAlert.cpp` | Local reply-list deletion confirmation for mail replies. |

## Boundary Notes

- IDA confirms `0x00478fe0`, `0x004790a0`, `0x0047e090`, `0x0047e160`, `0x0047e2f0`, `0x0047e390`, `0x0047e510`, `0x0047e730`, `0x0047eb30`, and `0x0047eb90` as function starts.
- IDA does not currently define Wave3-projected constructors at `0x00478f90`, `0x00479050`, `0x0047e040`, `0x0047e100`, `0x0047e4b0`, or `0x0047e6a0` as functions. Raw disassembly now confirms `0x00478f90-0x00478fd8` as [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md), `0x00479050-0x00479098` as [UID:0002EM][0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor](by-memory/0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor.md), and `0x0047e100-0x0047e158` as [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md); treat the other starts as Wave3-projected boundaries until raw disassembly or function creation confirms them.
- 2026-06-06 recheck: [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md) and [UID:0002EM][0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor](by-memory/0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor.md) both have exact body bytes, adjacent padding bytes, no modeled IDA function object at the raw start, shared alert table pointer `0x00613a18`, shared helper call `0x0049feb0`, flag store at `this+0x270`, and paired action functions immediately after the alignment gap.
- IDA decompilation of `0x004790a0` sends the same article navigation packet shape as `TransferReplyAlert::OnConfirm`. The active `class_TransferReplyPredefinedAlert.cpp` body instead describes text-editor/predefined-reply submission behavior, so that active body is logged as a Wave3 data issue.
- 2026-05-26 recheck: `callees 0x004790a0` and `callees 0x00478fe0` match exactly (`0x004a1250`, `0x004751c0`, `0x004a10e0`), and `xrefs_to 0x004790a0` reports a vtable/data reference at `0x006141f0`. See [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md).
- The `0x0047e8d9-0x0047e91a` strip is mostly compiler-generated this-adjustor thunks for secondary/tertiary `AlertPane` vtables.
- `0x0047e950-0x0047ec6a` is a dense scalar-deleting-destructor strip shared by article, bulletin, mail, predefined article, and related dialog classes. Do not use destructor locality alone as file-ownership proof.

## Cross-References

- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md)
- [UID:0002AI][0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons](by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md)
- [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md)
- [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md)
- [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000LT][NewPredefinedFormArticleDialog](by-file/NewPredefinedFormArticleDialog.md)

## Score Rationale

- Completion is raised to `85` because the file page now records a valid proposed path, the grouped wrapper hypothesis, exact constructor/action/delete children for the article/predefined/board-delete paths, the exact MailDeleteReplyAlert child family, the adjacent reply-delete singleton storage pair, and the destructor/thunk exclusions needed to prevent compiler-generated locality from driving source ownership.
- Confidence remains `86` because the evidence is strong for this as a stable owner bucket, but the original project may still have kept some wrappers private to `BoardDialogs.cpp`, `MailDialogs.cpp`, or `NewPredefinedFormArticleDialog.cpp`; mail-transfer and confirm-delete-mail constructor starts also remain projected rather than exact child pages.
- This page now passes the 80/80 parent-side attachment threshold, but child attachment should still be done only in focused passes that confirm each child page's own owner, position, and reconstruction-code gate.

## Changes

- 2026-06-10 B001-009: Added exact owner-specific vtable child [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md) as the current direct vtable child for the mail-specific alert companions after live IDA MCP reconfirmed decorated bases, COL pointers, store xrefs, and the shared alert gap.
- What existed before: the page documented shared board/mail alert wrappers and constructor/action caveats but remained scored as unevaluated.
- What it was changed to: scores were set to `74/82`.
- Summary and evidence: alert behavior and shared wrapper role are well supported, while separate source-file existence and several projected constructors remain medium-confidence.
- 2026-05-27: `TransferReplyAlert` constructor ownership previously remained a projected `0x00478f90` start. Updated it to raw constructor range [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md). Evidence: IDA raw disassembly confirms constructor-shaped code and vtable stores; IDA still does not promote the start to a function object.
- 2026-06-02: Assigned projected reconstruction path `NexusTK/ui/dialogs/` so confirmed child items can attach to a stable file-owner bucket. This is a path/ownership aid only; source-file split remains medium-confidence and no final C++ should be generated from this page yet.
- 2026-06-02: Linked exact delete-confirm action children [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md) and [UID:0002SF][0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest](by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md).
- 2026-06-03: Updated [UID:0002SF][0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest](by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md) to the live IDA-confirmed half-open range and action evidence.
- 2026-06-03: Completion/confidence changed from `74/82` to `76/84` after restarted IDA MCP confirmed [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md) as a raw constructor body with exact padding before [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md). Remaining projected constructors keep this as an ownership bucket, not final C++.
- 2026-06-06 A007: Completion/confidence changed from `76/84` to `78/86` after live IDA rechecked [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md) and [UID:0002EM][0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor](by-memory/0x00479050-0x00479098.TransferReplyPredefinedAlertRawConstructor.md), corrected the predefined primary vtable target to `0x00614194`, and replaced the stale projected-constructor row with the exact constructor UID. Remaining raw/projected mail/delete constructors keep this below the 80/80 child-attachment gate.
- 2026-06-07 A004: Completion changed from `78` to `82`; confidence remains `86`.
  - Summary/evidence: added a source-ownership matrix tying article transfer, predefined transfer, board delete, mail delete, and destructor/thunk groups to exact child pages; updated MailDeleteReplyAlert from projected row text to exact constructor/destructor/action/scalar-destructor children; added score rationale and parent-gate note. Remaining projected mail-transfer and confirm-delete-mail constructor starts plus the unresolved original source split keep confidence unchanged and final C++ blank.
- 2026-06-07 A008 Batch 037 parent-gate refresh:
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`.
  - Summary/evidence: added the exact adjacent reply-delete singleton storage pair [UID:0002AI][0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons](by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md) as source-declared state for the already documented `DeleteReplyAlert` and `MailDeleteReplyAlert` wrapper families. The remaining source-split caveat stays documented, but this parent now clears the corrected `85/85` gate for the exact storage pair.
