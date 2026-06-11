*** UID:000321 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Mail Dialog Core Vtables

## Status

- Entity kind: owner-specific vtable child split from [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md).
- Source owner: [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).
- Covered classes: [UID:00007L][MailListDialog](by-class/MailListDialog.md), [UID:00007M][MailListPane](by-class/MailListPane.md), [UID:00007K][MailDialog](by-class/MailDialog.md), and [UID:000096][NewMailDialog](by-class/NewMailDialog.md).
- Reconstruction handling: source-declared/generated-binary vtable layouts required by the mail dialog class declarations.
- Confidence: strong for decorated vtable symbols, complete-object-locator pointers, constructor stores, and direct `MailDialogs` source ownership.

## Binary Evidence

B001-009 live IDA MCP `py_eval` on 2026-06-10 used IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.

| Class | Primary | Secondary | Tertiary | Store/xref evidence |
| --- | --- | --- | --- | --- |
| `MailListDialog` | `0x00614238` | `0x0061429c` | `0x006142cc` | Decorated `??_7MailListDialog@@6B@` bases with COLs `0x00643b98`, `0x00643c00`, `0x00643c14`; constructor stores at `0x0047916d`, `0x00479173`, `0x0047917d` inside `0x00479110-0x00479d2b`. |
| `MailListPane` | `0x006142d8` | `0x00614360` | `0x00614390` | Decorated `??_7MailListPane@@6B@` bases with COLs `0x00643c28`, `0x00643c8c`, `0x00643ca0`; constructor stores at `0x0047a8d1`, `0x0047a8d7`, `0x0047a8e1` inside `0x0047a8a0-0x0047a8f9`. |
| `MailDialog` | `0x0061439c` | `0x00614400` | `0x00614430` | Decorated `??_7MailDialog@@6B@` bases with COLs `0x00643cb4`, `0x00643d1c`, `0x00643d30`; constructor stores at `0x0047b287`, `0x0047b28d`, `0x0047b297` inside `0x0047b220-0x0047c405`. |
| `NewMailDialog` | `0x0061443c` | `0x006144a0` | `0x006144d0` | Decorated `??_7NewMailDialog@@6B@` bases with COLs `0x00643d44`, `0x00643dac`, `0x00643dc0`; constructor stores at `0x0047d0a1`, `0x0047d0a7`, `0x0047d0b1` inside `0x0047d050-0x0047d7c1`. |

Boundary facts:

- The preceding named vtable is `??_7TransferReplyPredefinedAlert@@6B@_1` at `0x0061422c`.
- The successor after this child is `??_7MailTransferReplyAlert@@6B@` at `0x006144dc`, which belongs to the mail-alert companion split.
- The executable owner cluster is the mail dialog aggregate [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md), whose direct file parent is [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).

## Ownership Inference

The direct source owner is [UID:0000KZ][MailDialogs](by-file/MailDialogs.md). Each vtable has exactly one constructor-store cluster in the mail list, mail list-pane, read/reply dialog, or compose dialog constructor. The four covered classes are already documented as mail UI classes, and the file parent clears the corrected `85/85` gate at `86/85`.

The shared alert wrapper parent [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) is rejected for this child because none of these four core mail dialog constructors are alert wrappers, and the vtable stores occur before the alert companion strip.

## Assignment Gate

| Candidate | Decision | Reason |
| --- | --- | --- |
| [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) | selected | Direct source bucket for mail list, list-pane, read/reply, and compose dialog classes; parent clears `86/85`. |
| [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) | rejected | Owns or buckets reply/delete alert wrappers, not the four core mail dialog classes. |
| [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md) | rejected as parent | Mixed master inventory spanning this child and the mail-alert companion child. |
| [UID:00024W][0x00613ab0-0x00614cd0.BoardMailReadOnlyData](by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md) | rejected | Broader `.rdata` range crosses board, session, web-board, alert, mail, resource-string, and ChangeMan owners. |

`AUTOGEN_PARENT_UID` is set to `0000KZ` because this child and the direct file parent both clear `85/85`, and the binary evidence supports `MailDialogs` as the actual owner.

## Cross-References

- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:00007L][MailListDialog](by-class/MailListDialog.md)
- [UID:00007M][MailListPane](by-class/MailListPane.md)
- [UID:00007K][MailDialog](by-class/MailDialog.md)
- [UID:000096][NewMailDialog](by-class/NewMailDialog.md)
- [UID:00024W][0x00613ab0-0x00614cd0.BoardMailReadOnlyData](by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md)

## Changes

- 2026-06-10 B001-009: Created as an exact owner-specific vtable child for the core `MailDialogs` class tables after live IDA MCP reconfirmed the decorated bases, COL pointers, constructor-store xrefs, and boundaries separating the mail-core tables from the mail alert companion and shared board alert tables.
