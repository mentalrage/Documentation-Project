*** UID:000096 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewMailDialog

## Status

- Confidence: strong for behavior and mail-dialog module placement.
- Likely source file: [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) or `ui/dialogs/NewMailDialog.cpp`
- Address range: [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_NewMailDialog.cpp`

## Class Purpose

`NewMailDialog` is the compose-and-send mail dialog. It lays out recipient, subject, body, and copy option controls, preloads quoted content when replying, serializes outgoing mail fields, and handles transfer-reply alerts. In the EPF mail-skin path, IDA shows it builds a local [UID:00005C][FontStyle](by-class/FontStyle.md) for the "Keep a copy" static label.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewMailDialog` | `0x0047d050-0x0047d7c0` | Builds compose dialog layout and quoted content. |
| `HandleCommand` | `0x0047d820-0x0047d881` | Handles send and cancel commands. |
| `HandleSendFailure` | `0x0047d890-0x0047d942` | Displays transfer failure alert. |
| `SetDialogMode` | `0x0047d950-0x0047d958` | Forwards dialog mode changes to base implementation. |
| `AppendQuotedMessage` | `0x0047d960-0x0047da10` | Prefixes quoted body lines and appends them to the editor. |
| `HandleMailTransferReply` | `0x0047da20-0x0047db6a` | Parses transfer reply text and displays [UID:00007N][MailTransferReplyAlert](by-class/MailTransferReplyAlert.md). |
| `SendMail` | `0x0047dcb0-0x0047e032` | Converts fields and sends outgoing mail packet. |

## Evidence Notes

- IDA MCP confirms constructor, command, and send boundaries.
- IDA MCP confirms raw constructor calls to `FontStyle::FontStyle` at `0x0047d0d2` and `FontStyle::Configure(128, 128, 3, 0)` at `0x0047d3fa`, even though active generated source abstracts this as `BuildDialogTextStyle`.
- Outgoing mail conversion helpers are shared with other text-submit flows and should not be treated as mail-owned.

## Cross-References

- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:00007K][MailDialog](by-class/MailDialog.md)
- [UID:00007N][MailTransferReplyAlert](by-class/MailTransferReplyAlert.md)
- [UID:00005C][FontStyle](by-class/FontStyle.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already covered dialog role, send flow, command handling, transfer replies, and module placement.
- Changed to: `COMPLETION:74` and `CONFIDENCE:84`.
- Evidence: constructor, command, failure, quoted-message, transfer-reply, and send methods are documented with IDA-backed notes; remaining gaps are exact field layout and complete body-level converted C++.
