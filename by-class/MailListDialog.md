*** UID:00007L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MailListDialog

## Status

- Confidence: strong for behavior and mail-dialog module placement.
- Likely source file: [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- Address range: [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_MailListDialog.cpp`

## Class Purpose

`MailListDialog` is the received-mail listing dialog. It parses server packet data into mail list entries, owns the mail action buttons, sends read-mail requests, and handles list update and delete/reply confirmation packets.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MailListDialog` | `0x00479110-0x00479d2a` | Parses mail-list packet and creates controls/list layout. |
| `SendMailRequest` | `0x00479d30-0x00479e1d` | Sends a read-mail request for the selected mail entry. |
| `OnAction` | `0x0047a060-0x0047a1b8` | Dispatches read, compose, reply, delete, close, and scroll actions. |
| `UpdateButtonStates` | `0x0047a320-0x0047a3ab` | Enables/disables mail action buttons based on list selection. |
| `OnServerPacket` | `0x0047a3b0-0x0047a512` | Handles mail list update and delete/reply confirmation packets. |
| `UpdateMailList` | `0x0047a520-0x0047a753` | Parses list update packet and repopulates entries. |

## Evidence Notes

- IDA MCP confirms constructor, request, action, server packet, and list update boundaries.
- This dialog owns mail UI flow and packet dispatch decisions, not the generic packet serializer.

## Cross-References

- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:00007M][MailListPane](by-class/MailListPane.md)
- [UID:00007K][MailDialog](by-class/MailDialog.md)

## Changes

- 2026-06-05: Marked reconstructable and attached to [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) because the class is `80/84` and the parent is `86/82`, satisfying the 80/80 parent gate. Live IDA MCP evidence: `lookup_funcs` confirms exact starts at `0x00479110`, `0x00479d30`, `0x0047a060`, `0x0047a320`, `0x0047a3b0`, and `0x0047a520`; `callers` confirms the constructor is reached from `0x0047173f` and `0x00471e51` in the mail/bulletin dialog flow.
- Completion/confidence score update: existed before as `0/0`; changed to `80/84`. Summary: the received-mail listing dialog has constructor, packet parsing, read request, actions, button state, server packet, update flow, and module ownership documented. Evidence: linked mail-dialog range, IDA-confirmed method boundaries, mail-list pane relationship, and packet dispatch notes.
