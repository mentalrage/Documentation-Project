*** UID:000034 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:64 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ConfirmDeleteMailAlert

## Status

- Confidence: strong for delete-packet behavior; medium for constructor boundary.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), or a private section of [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).
- Current recovered file: `source-3/simroot_v2/class_ConfirmDeleteMailAlert.cpp`
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)

## Role

`ConfirmDeleteMailAlert` is the mail-specific delete confirmation alert. Its confirmed action serializes one or more opcode `0x3b`, subcommand `0x05` mail delete packets using ids from the active mail context.

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| `0x0047e4b0` | constructor, Wave3-projected | Builds the localized alert with a Cancel button and stores the selected mail/delete mode. IDA does not currently define this start as a function. |
| `0x0047e510-0x0047e693` | `SendDeleteRequest` | IDA confirms this function; it serializes single or multi-delete packets and updates the active player mail context before processing the bulletin queue. |

## Notes

- This is a mail-context sibling of [UID:000033][ConfirmDeleteAlert](by-class/ConfirmDeleteAlert.md). Keep it with mail/dialog alert code, not generic packet transport.

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- [UID:00007K][MailDialog](by-class/MailDialog.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `64/76`.
  - Summary/evidence: the mail delete-packet action behavior, companion memory range, file ownership candidates, and mail-dialog relationship are documented; remaining uncertainty is the constructor boundary and exact mail context layout.
