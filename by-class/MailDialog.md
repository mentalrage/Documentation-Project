*** UID:00007K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MailDialog

## Status

- Confidence: strong for behavior and mail-dialog module placement.
- Likely source file: [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- Address range: [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_MailDialog.cpp`

## Class Purpose

`MailDialog` is the mail read/reply dialog. It parses a mail packet into sender/date/subject/body fields, builds read and reply UI layouts, handles navigation and delete/forward/reply commands, and sends replies.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MailDialog` | `0x0047b220-0x0047c404` | Parses mail packet and builds read/reply layouts. |
| `OnCommand` | `0x0047c500-0x0047c710` | Handles close, reply, delete confirmation, paging, and forward commands. |
| `OnKeyInput` | `0x0047c730-0x0047c77f` | Handles Ctrl+S send/reply shortcut. |
| `SendReply` | `0x0047c8d0-0x0047c94a` | Extracts reply text, pops dialog, and sends reply. |
| `OnMailDeleteReply` | `0x0047c9f0-0x0047cb3d` | Displays a mail delete-reply alert from server response. |
| adjustor thunks | [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | Compiler-generated secondary/tertiary deleting-destructor thunks; ignore for handwritten source. |
| `ScalarDeletingDestructor` | `0x0047ebf0-0x0047ec2a` | Runs base destruction and optional free. |

## Evidence Notes

- IDA MCP confirms constructor, command, reply send, delete-reply, and destructor boundaries.
- The older report notes identify an unresolved helper near `0x0047cd80` for the Ctrl+S path; keep that as a later by-item target.

## Cross-References

- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:000096][NewMailDialog](by-class/NewMailDialog.md)
- [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md)
- [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `78/82`. Summary: the mail read/reply dialog has core parse/build, command, shortcut, reply send, delete-reply, destructor, and module-placement documentation, but unresolved helper cleanup keeps it below high completion. Evidence: linked mail dialog memory range, method address table, IDA-confirmed boundaries, and Ctrl+S helper caveat.
