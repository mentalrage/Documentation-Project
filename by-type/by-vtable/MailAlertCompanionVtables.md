*** UID:000322 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Mail Alert Companion Vtables

## Status

- Entity kind: owner-specific vtable child split from [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md).
- Source owner: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
- Covered classes: [UID:00007N][MailTransferReplyAlert](by-class/MailTransferReplyAlert.md), [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md), and [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md).
- Reconstruction handling: source-declared/generated-binary vtable layouts required by the mail-specific reply/delete alert wrapper declarations.
- Confidence: strong for decorated vtable symbols, complete-object-locator pointers, store refs, and separation from the core mail dialog vtables; medium-high for final original source split because these mail-only wrappers may eventually fold into [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).

## Binary Evidence

B001-009 live IDA MCP `py_eval` on 2026-06-10 used IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.

| Class | Primary | Secondary | Tertiary | Store/xref evidence |
| --- | --- | --- | --- | --- |
| `MailTransferReplyAlert` | `0x006144dc` | `0x00614544` | `0x00614574` | Decorated `??_7MailTransferReplyAlert@@6B@` bases with COLs `0x00643dd4`, `0x00643e38`, `0x00643e4c`; stores in mail compose/transfer paths at `0x0047d90d/0x0047d913/0x0047d91d`, `0x0047db2b/0x0047db31/0x0047db3b`, `0x0047dc61/0x0047dc67/0x0047dc71`, plus raw constructor-shaped stores at `0x0047e067/0x0047e06d/0x0047e077`. |
| `ConfirmDeleteMailAlert` | `0x006146c8` | `0x00614730` | `0x00614760` | Decorated `??_7ConfirmDeleteMailAlert@@6B@` bases with COLs `0x00643f78`, `0x00643fdc`, `0x00643ff0`; stores in mail list/read delete-confirm paths at `0x0047a17b/0x0047a181/0x0047a18b`, `0x0047a2e4/0x0047a2ea/0x0047a2f4`, `0x0047c6c5/0x0047c6cb/0x0047c6d5`, `0x0047c9b4/0x0047c9ba/0x0047c9c4`, plus raw constructor-shaped stores at `0x0047e4e7/0x0047e4ed/0x0047e4f7`. |
| `MailDeleteReplyAlert` | `0x0061476c` | `0x006147d4` | `0x00614804` | Decorated `??_7MailDeleteReplyAlert@@6B@` bases with COLs `0x00644004`, `0x00644068`, `0x0064407c`; stores in mail list/read reply-delete paths at `0x0047a4bf/0x0047a4c5/0x0047a4cf`, `0x0047a84d/0x0047a853/0x0047a85d`, `0x0047caf7/0x0047cafd/0x0047cb07`, `0x0047cc2d/0x0047cc33/0x0047cc3d`, raw constructor stores at `0x0047e6c7/0x0047e6cd/0x0047e6d7`, non-deleting destructor stores at `0x0047e6f0/0x0047e6f6/0x0047e700`, and scalar-destructor stores at `0x0047eb96/0x0047eb9c/0x0047eba6`. |

Boundary facts:

- This child starts at `0x006144dc`, immediately after [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md) and its `NewMailDialog` tertiary view at `0x006144d0`.
- The `MailTransferReplyAlert` tertiary table at `0x00614574` ends before shared `ConfirmDeleteAlert` vtables beginning at `0x00614580`.
- The shared `ConfirmDeleteAlert` and `DeleteReplyAlert` tables occupy the gap `0x00614580-0x006146c4` and are intentionally excluded from this mail-specific child.
- `ConfirmDeleteMailAlert` resumes at `0x006146c8`; `MailDeleteReplyAlert` ends at `0x0061480c`.
- `0x0061480c` begins UTF-16 resource/string data (`dword_61480C`, `aGbbs01Pal` at `0x00614818`), not another vtable.

## Ownership Inference

The selected owner for this child is [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), the current shared source bucket for board/mail reply and delete alert wrappers. That file parent already clears `85/86` and explicitly lists `MailTransferReplyAlert`, `ConfirmDeleteMailAlert`, `MailDeleteReplyAlert`, their singleton state, and related exact memory children as part of the wrapper family.

IDA evidence also supports [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) as a serious alternate candidate: many vtable stores occur inside mail list/read/compose functions, and every class in this child is mail-specific. That evidence is best interpreted as construction/use sites and possible inline constructor expansion in mail code. It does not by itself outweigh the existing exact wrapper-family source bucket, the shared `ConfirmDeleteAlert`/`DeleteReplyAlert` interleave, the common `AlertPane` wrapper shape, and current class/global routing through [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).

Therefore this child is assigned to `BulletinReplyAlerts` as the best current direct owner, with an explicit caveat: final source reconstruction may later decide to fold the mail-only alert wrappers into `MailDialogs.cpp` if constructor/source-file evidence becomes stronger than the shared-wrapper grouping.

## Assignment Gate

| Candidate | Decision | Reason |
| --- | --- | --- |
| [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) | selected | Direct shared wrapper bucket for mail/board transfer, confirm-delete, and reply-delete alert subclasses; parent clears `85/86` and already owns related mail alert class/global children. |
| [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) | rejected as current parent | Strong consumer/construction evidence, but using it here would contradict the existing shared-alert wrapper grouping and absorb classes currently modeled with board/mail alert siblings. Keep as the best forced alternate if later source-split evidence changes. |
| [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md) | rejected as parent | Mixed master inventory spanning `MailDialogs` core tables and this alert companion child. |
| [UID:00024W][0x00613ab0-0x00614cd0.BoardMailReadOnlyData](by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md) | rejected | Broader `.rdata` range crosses board, session, web-board, alert, mail, resource-string, and ChangeMan owners. |

`AUTOGEN_PARENT_UID` is set to `0000HW` because this child and the direct shared-alert file parent both clear `85/85`, and by-structure permits by-file ownership for a source-owned vtable subfamily covering several small private alert classes.

## Cross-References

- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:00007N][MailTransferReplyAlert](by-class/MailTransferReplyAlert.md)
- [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md)
- [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md)
- [UID:0002T7][0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor](by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md)
- [UID:0002T8][0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter](by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md)
- [UID:0002T9][0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete](by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md)
- [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md)
- [UID:00024W][0x00613ab0-0x00614cd0.BoardMailReadOnlyData](by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md)

## Changes

- 2026-06-10 B001-009: Created as an exact owner-specific vtable child for the mail-specific alert companion tables after live IDA MCP reconfirmed the decorated bases, COL pointers, store xrefs, the gap occupied by shared `ConfirmDeleteAlert`/`DeleteReplyAlert` vtables, and the `0x0061480c` resource-string boundary.
