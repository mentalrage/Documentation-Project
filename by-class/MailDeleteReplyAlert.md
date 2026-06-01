*** UID:00007J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MailDeleteReplyAlert

## Status

- Confidence: strong for reply-list deletion behavior; medium for constructor boundary.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), or a private section of [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).
- Current recovered file: `source-3/simroot_v2/class_MailDeleteReplyAlert.cpp`
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)

## Role

`MailDeleteReplyAlert` confirms local deletion of mail reply rows. It supports deleting all selected replies or deleting a single reply id, refreshes the mail dialog/list view, optionally pops the session dialog, and clears `g_pMailDeleteReplyAlert` during teardown.

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| `0x0047e6a0` | constructor, Wave3-projected | Initializes `AlertPane`, stores the delete-all flag, installs mail-delete reply vtables, and writes the singleton. IDA does not currently define this start as a function. |
| `0x0047e6f0-0x0047e718` | non-deleting destructor | Resets vtables, clears the singleton, and destroys base alert/dialog state. |
| `0x0047e720-0x0047e725` | singleton getter | Returns `g_pMailDeleteReplyAlert` (`dword_67ADBC`). |
| `0x0047e730-0x0047e835` | `OnConfirmDelete` | Removes selected or single reply rows from the mail list, refreshes the owning dialog, and pops back to the previous dialog for single-delete mode. |
| [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | adjustor thunks | Secondary/tertiary vtable thunks to scalar deleting destructor `0x0047eb90`. |
| `0x0047eb90-0x0047ebee` | scalar deleting destructor | Clears the singleton, destroys base state, and optionally frees memory. |

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- [UID:00007K][MailDialog](by-class/MailDialog.md)
- [UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/74`. Summary: reply-list deletion behavior, singleton handling, confirmation path, and destructor/adjustor coverage are documented, but the constructor boundary and final source split remain medium confidence. Evidence: companion memory range, delete-all/single-delete role, singleton getter/global behavior, `OnConfirmDelete`, and IDA constructor-boundary caveat.
