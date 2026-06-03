*** UID:000034 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:60 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ConfirmDeleteMailAlert

## Status

- Confidence: strong for delete-packet behavior and confirmed action ownership; medium for constructor boundary and exact mail context layout.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), or a private section of [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).
- Current recovered file: `source-3/simroot_v2/class_ConfirmDeleteMailAlert.cpp`
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- Current evidence status: live IDA MCP decompile, function-boundary, call-graph, and vtable-slot checks for the action were refreshed on 2026-06-03.

## Role

`ConfirmDeleteMailAlert` is the mail-specific delete confirmation alert. Its confirmed action serializes one or more opcode `0x3b`, subcommand `0x05` mail delete packets using ids from the active mail context.

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| `0x0047e4b0` | constructor, Wave3-projected | Builds the localized alert with a Cancel button and stores the selected mail/delete mode. IDA does not currently define this start as a function. |
| [UID:0002SF][0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest](by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md) | `SendDeleteRequest` | IDA confirms this function; it serializes single or multi-delete packets and updates the active player mail context before processing the bulletin queue. |

## Evidence Map

| Evidence | Impact |
| --- | --- |
| [UID:0002SF][0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest](by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md) | Exact action child page records opcode `0x3b`, subcommand `0x05`, the `0x0047e510-0x0047e694` IDA boundary, packet/layout offsets, vtable slot `0x00614724`, and live IDA MCP decompile evidence. |
| [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) | Places this class in the shared bulletin/mail alert wrapper family. |
| [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md) | Provides vtable-store and class-family evidence for the mail alert class. |

## Reconstruction Notes

- Reconstructable: true as an owning class shell plus confirmed action child.
- Parent: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) until a more exact original file split is proven.
- C++: intentionally blank. The confirmed action is not enough for final-source output because the constructor start is still projected and mail context field names remain unresolved.

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
- 2026-06-02:
  - Before: class had only aggregate range references for the confirmed action.
  - After: scored as `70/80`, marked reconstructable, and attached under [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
  - Summary/evidence: exact action child [UID:0002SF][0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest](by-memory/0x0047e510-0x0047e694.ConfirmDeleteMailAlertSendDeleteRequest.md) now captures packet behavior and prior IDA evidence; C++ remains blank pending field/layout recovery.
- 2026-06-03:
  - Before: class score still relied on prior aggregate/action-start evidence and the action page used an off-by-one half-open range.
  - After: scored as `76/84` after live IDA MCP confirmed the action boundary, vtable action slot, call graph, single/multi delete packet paths, and mail-context offsets.
  - C++ remains blank because the constructor boundary is still projected and the recovered field/helper names are not source-quality.
