*** UID:00007N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MailTransferReplyAlert

## Status

- Confidence: strong for confirm behavior, vtable identity, and alert-family ownership; medium for constructor boundary and final source split.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), or a private section of [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).
- Current recovered file: `source-3/simroot_v2/class_MailTransferReplyAlert.cpp`
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- Mail cluster range: [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- Vtable/layout anchor: [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)

## Role

`MailTransferReplyAlert` is the mail-specific transfer-reply acknowledgement alert. Confirming it closes the alert, locates the previous mail dialog/list context, calls the mail navigation helper at `0x0047b080`, and optionally pops the active `BulletinSession` dialog.

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| `0x0047e040-0x0047e087` | constructor, Wave3/Wave2-projected bytes | Initializes `AlertPane`, stores `m_closeSessionOnConfirm`, and installs mail-transfer alert vtables. IDA does not currently define this start as a function. |
| `0x0047e090-0x0047e0fe` | `OnConfirm` | IDA confirms this function; it calls `0x0047b080` (`SendMailNavigatePacket`) with the selected sender/reply id and optionally pops the session. |

## Evidence Notes

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) has a valid `NexusTK/ui/dialogs/` reconstruction path and is the current source-owner bucket for the small board/mail reply alert wrappers.
- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md) records the IDA-confirmed `0x0047e090` function start and keeps `0x0047e040` as a projected constructor start.
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md) ties the mail-specific alert wrappers to the mail dialog cluster and records the same `0x0047e090-0x0047e0fe` confirm action.
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md) records the `MailTransferReplyAlert` primary, secondary, and tertiary table bases at `0x006144dc`, `0x00614544`, and `0x00614574`, with constructor/destructor store xrefs including `0x0047e067`.
- The current `simroot_v2` source map preserves the imported method children `0x0047e040-0x0047e087` and `0x0047e090-0x0047e0fe`, but the generated C++ remains below the project final-source threshold.

## Autogen Status

- Reconstructable: true for source ownership and future wrapper reconstruction.
- Parent: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), because the parent has a valid dialog-folder path and sufficient confidence for this helper bucket.
- Code: intentionally blank. The action behavior is clear, but final C++ is below the 95+ gate until the constructor bytes, exact declaration shape, and `BulletinReplyAlerts.cpp` versus private `MailDialogs.cpp` source split are audited.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 80 | The page now records owner bucket, companion ranges, action behavior, imported constructor range, vtable-family evidence, and autogen status. It stays below higher completion because the constructor lacks an exact raw-disassembly child page and final source placement remains open. |
| Confidence | 84 | IDA-backed written docs support the action function and vtable identity, and the mail/bulletin ownership split is explicitly documented. Confidence stays below final-source quality because the constructor start is still projected rather than an IDA function. |

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:000096][NewMailDialog](by-class/NewMailDialog.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `70/74`. Summary: the page documents the confirm behavior, mail-dialog context, companion range, and source-owner candidates, but remains below high completion because the constructor boundary is Wave3-projected rather than an IDA function. Evidence: `OnConfirm` IDA function at `0x0047e090-0x0047e0fe`, companion alert range, `MailDialogs`/`BulletinReplyAlerts` ownership candidates, and explicit constructor-boundary caveat.
- 2026-06-03 source-owner and score update:
  - What existed before: the page was scored `70/74`, had no reconstructable/autogen parent metadata, and recorded the constructor only as a single projected start.
  - Changed to: scores `80/84`; `RECONSTRUCTABLE:TRUE`; parent [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) at position `30`; constructor range recorded as imported `0x0047e040-0x0047e087`; C++ block remains empty.
  - Summary/evidence: parent source bucket, mail cluster, alert companion range, vtable-family table bases, and generated source-map method ranges now support a stronger class page. Final source C++ is still gated because the constructor is not an IDA-defined function and exact old-source split remains unresolved.
