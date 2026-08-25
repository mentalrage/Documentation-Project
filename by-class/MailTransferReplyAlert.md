*** UID:00007N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HW | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
/*
[UID:00007N] No standalone class-level C++ is emitted from this class page.
MailTransferReplyAlert has exact raw-constructor and action evidence, but final class/source output is blocked by unresolved base/helper/resource names, source split between BulletinReplyAlerts and MailDialogs, and owner/session declarations.
*/
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MailTransferReplyAlert

## Status

- Confidence: strong for confirm behavior, raw constructor boundary, vtable identity, and alert-family ownership; medium-high for final source split.
- Likely source file: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), or a private section of [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).
- Exact constructor child: [UID:0003O8][0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor](by-memory/0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor.md)
- Companion memory range: [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- Mail cluster range: [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- Vtable/layout anchor: [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)

## Role

`MailTransferReplyAlert` is the mail-specific transfer-reply acknowledgement alert. Confirming it closes the alert, locates the previous mail dialog/list context, calls the mail navigation helper at `0x0047b080`, and optionally pops the active `BulletinSession` dialog.

## Methods

| Range | Method | Notes |
| --- | --- | --- |
| [UID:0003O8][0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor](by-memory/0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor.md) | raw constructor | Raw constructor-shaped bytes call the shared alert/base initializer, store the close-session flag at `this + 0x270`, and install the three `MailTransferReplyAlert` vtable views. IDA does not model this start as a function. |
| `0x0047e090-0x0047e0ff` | `OnConfirm` | IDA confirms this function; it closes the alert, resolves the prior mail context, calls `0x0047b080` (`SendMailNavigatePacket`) with the selected sender/reply id, and optionally pops the session. |

## Evidence Notes

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) has a valid `NexusTK/ui/dialogs/` reconstruction path and is the current source-owner bucket for the small board/mail reply alert wrappers.
- [UID:0003O8][0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor](by-memory/0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor.md) records the 2026-06-14 live IDA MCP raw disassembly, no-function status, `retn 0Ch`, alignment at `0x0047e088`, and vtable stores at `0x0047e067/0x0047e06d/0x0047e077`.
- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md) records the IDA-confirmed `0x0047e090` function start and now links the exact raw constructor child.
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md) ties the mail-specific alert wrappers to the mail dialog cluster and records the same `0x0047e090-0x0047e0ff` confirm action.
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md) records the `MailTransferReplyAlert` primary, secondary, and tertiary table bases at `0x006144dc`, `0x00614544`, and `0x00614574`, with constructor/destructor store xrefs including `0x0047e067`.
- 2026-06-14 live IDA MCP decompiles `0x0047e090` as a vtable callback with callees `sub_4A1250`, `sub_47B080`, and `sub_4A10E0`; it reads `this[155]` / `this+0x26c`, sends the mail navigation packet using child slot `7`, and pops the session only when the constructor-stored byte at `this+0x270` equals `1`.

## Autogen Status

- Reconstructable: true for source ownership and future wrapper reconstruction.
- Parent: [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md), because the parent has a valid dialog-folder path and sufficient confidence for this helper bucket.
- Code: intentionally blank. The constructor/action behavior is clear, but final C++ is below the active `90/90+` gate until the exact declaration shape, helper/resource names, and `BulletinReplyAlerts.cpp` versus private `MailDialogs.cpp` source split are audited.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | The page now records owner bucket, companion ranges, exact raw constructor child, action behavior, vtable-family evidence, direct parent routing, score rationale, and active final-C++ blockers. |
| Confidence | 88 | Live IDA confirms the raw constructor span, vtable stores, action decompilation, and caller/callee behavior. Confidence remains below final-source quality because IDA still does not model the raw start as a function and the original shared-alert versus mail-private source split is not proven. |

## Cross-References

- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:0003O8][0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor](by-memory/0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor.md)
- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:000096][NewMailDialog](by-class/NewMailDialog.md)

## B006 2026-06-29 Implementation Callback

- Accepted C12: this class page clears its marker with a no-code/index comment. The mail transfer evidence remains outside the narrowed accepted callback and should not be summarized into class-level source here.

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `70/74`. Summary: the page documents the confirm behavior, mail-dialog context, companion range, and source-owner candidates, but remained below high completion because the constructor boundary was not yet an exact raw child. Evidence: `OnConfirm` IDA function at `0x0047e090-0x0047e0ff`, companion alert range, `MailDialogs`/`BulletinReplyAlerts` ownership candidates, and explicit constructor-boundary caveat.
- 2026-06-03 source-owner and score update:
  - What existed before: the page was scored `70/74`, had no reconstructable/autogen parent metadata, and recorded the constructor only as a single projected start.
  - Changed to: scores `80/84`; `RECONSTRUCTABLE:TRUE`; parent [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) at position `30`; constructor range recorded as raw/projected `0x0047e040-0x0047e088`; C++ block remains empty.
  - Summary/evidence: parent source bucket, mail cluster, alert companion range, vtable-family table bases, and generated source-map method ranges now support a stronger class page. Final source C++ is still gated because the constructor is not an IDA-defined function and exact old-source split remains unresolved.
- 2026-06-14 Agent-A001 Goal 2 low-score repair:
  - Changed scores from `80/84` to `86/88`.
  - Added exact raw constructor child [UID:0003O8][0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor](by-memory/0x0047e040-0x0047e088.MailTransferReplyAlertRawConstructor.md), refreshed `OnConfirm` evidence from live IDA MCP, and replaced old projected-constructor/final-gate wording.
  - C++ remains blank below the active `90/90+` final-source gate.
