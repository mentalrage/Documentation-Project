*** UID:00007J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MailDeleteReplyAlert

## Status

- Confidence: strong for reply-list deletion behavior, singleton handling, vtable ownership, and destructor/action ranges; medium for final source split and the raw constructor boundary.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), with possible private placement inside [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).
- Parent attachment: attached to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), whose current confidence is `82` and projected path is `NexusTK/ui/dialogs/`.
- Current recovered file: `source-3/simroot_v2/class_MailDeleteReplyAlert.cpp`
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- Exact memory children: [UID:0002T7][0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor](by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md), [UID:0002T8][0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter](by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md), [UID:0002T9][0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete](by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md), and [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md).
- Reconstruction note: C++ intentionally left blank until the final class layout, base names, list helper names, and source split are near-final.

## Role

`MailDeleteReplyAlert` confirms local deletion of mail reply rows. It supports deleting all selected replies or deleting a single reply id, refreshes the mail dialog/list view, optionally pops the session dialog, and clears `g_pMailDeleteReplyAlert` during teardown.

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| [UID:0002T7][0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor](by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md) | raw constructor-shaped bytes | Initializes `AlertPane`, stores the delete-all flag, installs mail-delete reply vtables, and writes the singleton. IDA does not currently define this start as a function. |
| [UID:0002T8][0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter](by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md) | non-deleting destructor and singleton getter | Resets vtables, clears/returns `g_pMailDeleteReplyAlert` (`dword_67ADBC`), and destroys base alert/dialog state. |
| [UID:0002T9][0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete](by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md) | `OnConfirmDelete` | Removes selected or single reply rows from the mail list, refreshes the owning dialog, and pops back to the previous dialog for single-delete mode. |
| [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | adjustor thunks | Secondary/tertiary vtable thunks to scalar deleting destructor `0x0047eb90`. |
| [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md) | scalar deleting destructor | Clears the singleton, destroys base state, and optionally frees memory. |

## Evidence Notes

- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md) records IDA-confirmed starts for `0x0047e6f0`, `0x0047e720`, `0x0047e730`, and `0x0047eb90`, while keeping `0x0047e6a0` as a projected raw constructor start.
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md) records the `MailDeleteReplyAlert` primary/secondary/tertiary vtable bases and current IDA-backed constructor/destructor store sites.
- [UID:0002AI][0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons](by-memory/0x0067adb8-0x0067adc0.BoardMailDeleteReplyAlertSingletons.md) records `dword_67ADBC` as `MailDeleteReplyAlert *g_pMailDeleteReplyAlert` and cites xrefs from this class neighborhood.
- Current `simroot_v2/class_MailDeleteReplyAlert.cpp` remains a lead for branch shape and helper calls only; final helper/type names are not source-quality.

## Autogen Status

- Marked reconstructable and attached to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) after exact child pages and vtable/singleton evidence raised this class above the `80` confidence attachment gate.
- Parent position `70` follows the sibling order in [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md): article transfer, predefined transfer, mail transfer, board delete-confirm, board reply-delete, mail delete-confirm, then mail reply-delete.
- Keep the C++ block empty until the final class declaration, source split, field layout, and list/session helper names are near-final.

## Score Rationale

- Completion increased because the class now has exact child memory pages for constructor-shaped bytes, destructor/getter support, confirm action, and scalar deleting destructor.
- Confidence increased because existing IDA-backed vtable, function-start, thunk, and singleton evidence consistently tie the class to mail delete-reply alert behavior.
- Confidence remains below final-source level because the constructor is still raw/projected in written IDA evidence and the original source split between shared alert helpers and `MailDialogs.cpp` remains open.

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
- [UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/74`. Summary: reply-list deletion behavior, singleton handling, confirmation path, and destructor/adjustor coverage are documented, but the constructor boundary and final source split remain medium confidence. Evidence: companion memory range, delete-all/single-delete role, singleton getter/global behavior, `OnConfirmDelete`, and IDA constructor-boundary caveat.
- 2026-06-02: Raised from `72/74` to `82/82`, marked reconstructable, and attached to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
  - Before: the page had only coarse method ranges and no exact child pages.
  - After: the page links exact child memory pages [UID:0002T7][0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor](by-memory/0x0047e6a0-0x0047e6ee.MailDeleteReplyAlertRawConstructor.md), [UID:0002T8][0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter](by-memory/0x0047e6f0-0x0047e726.MailDeleteReplyAlertDestructorAndSingletonGetter.md), [UID:0002T9][0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete](by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md), and [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md).
  - Evidence: existing IDA-recorded function starts, vtable-family store evidence, singleton xref documentation, and companion aggregate ownership notes.
- 2026-06-07 A004: Set `AUTOGEN_PARENT_POSITION_OPTIONAL` to `70` to match the established [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) sibling order; no score change because this is an autogen ordering sync, not new behavioral evidence.
