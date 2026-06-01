*** UID:00007N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MailTransferReplyAlert

## Status

- Confidence: strong for confirm behavior; medium for constructor boundary.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), or a private section of [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).
- Current recovered file: `source-3/simroot_v2/class_MailTransferReplyAlert.cpp`
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)

## Role

`MailTransferReplyAlert` is the mail-specific transfer-reply acknowledgement alert. Confirming it closes the alert, locates the previous mail dialog/list context, calls the mail navigation helper at `0x0047b080`, and optionally pops the active `BulletinSession` dialog.

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| `0x0047e040` | constructor, Wave3-projected | Initializes `AlertPane`, stores `m_closeSessionOnConfirm`, and installs mail-transfer alert vtables. IDA does not currently define this start as a function. |
| `0x0047e090-0x0047e0fe` | `OnConfirm` | IDA confirms this function; it calls `0x0047b080` (`SendMailNavigatePacket`) with the selected sender/reply id and optionally pops the session. |

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- [UID:000096][NewMailDialog](by-class/NewMailDialog.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `70/74`. Summary: the page documents the confirm behavior, mail-dialog context, companion range, and source-owner candidates, but remains below high completion because the constructor boundary is Wave3-projected rather than an IDA function. Evidence: `OnConfirm` IDA function at `0x0047e090-0x0047e0fe`, companion alert range, `MailDialogs`/`BulletinReplyAlerts` ownership candidates, and explicit constructor-boundary caveat.
