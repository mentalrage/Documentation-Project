*** UID:00007K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Parent routing: assigned to [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) under the corrected `85/85` gate after Batch 136; this class is `85/86` and the direct file parent is `86/85`.

## Class Purpose

`MailDialog` is the mail read/reply dialog. It parses a mail packet into sender/date/subject/body fields, builds read and reply UI layouts, handles navigation and delete/forward/reply commands, and sends replies.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `MailDialog` | `0x0047b220-0x0047c404` | Parses mail packet and builds read/reply layouts. |
| `RefreshSelectedMailInList` | `0x0047c4b0-0x0047c4ff` | Finds this dialog's mail id in the list pane and reselects it before returning to the list view. |
| `OnCommand` | `0x0047c500-0x0047c710` | Handles close, send reply, confirm delete, list return, page navigation packets, and forward/base commands. |
| `OnKeyInput` | `0x0047c730-0x0047c77f` | Handles Ctrl+S send/reply shortcut. |
| `SendReply` | `0x0047c8d0-0x0047c94a` | Extracts reply text, pops dialog, and sends reply. |
| `CreateConfirmDeleteAlert` | `0x0047c950-0x0047c9e5` | Allocates and initializes a `ConfirmDeleteMailAlert` for this read dialog. |
| `OnMailDeleteReply` | `0x0047c9f0-0x0047cb3d` | Displays a mail delete-reply alert from server response. |
| `ShowDeleteReplyAlert` | `0x0047cb40-0x0047cc73` | Converts a packet payload to wide text and publishes the `MailDeleteReplyAlert` singleton. |
| adjustor thunks | [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | Compiler-generated secondary/tertiary deleting-destructor thunks; ignore for handwritten source. |
| `ScalarDeletingDestructor` | `0x0047ebf0-0x0047ec2a` | Runs base destruction and optional free. |

## Evidence Notes

- IDA MCP on 2026-06-08 confirms the compact `MailDialog` function set inside `0x0047b220-0x0047cc74`: `0x0047b220`, `0x0047c4b0`, `0x0047c500`, `0x0047c730`, `0x0047c8d0`, `0x0047c950`, `0x0047c9f0`, and `0x0047cb40`.
- Constructor callers are still the BulletinSession mail-open paths at `0x004717f6` and `0x00471f71`, tying the class to the mail-dialog flow rather than a generic alert or session helper.
- The constructor writes all three `MailDialog` vtable views: primary `0x0061439c` at `0x0047b287`, secondary `0x00614400` at `0x0047b28d`, and tertiary `0x00614430` at `0x0047b297`.
- `OnCommand` switch case evidence ties command `2` to `SendReply` at `0x0047c67e`, command `3` to `ConfirmDeleteMailAlert` vtable stores at `0x0047c6c5/0x0047c6cb/0x0047c6d5`, and commands `5`/`7` to opcode `0x3b` page-navigation packet construction.
- `OnKeyInput` handles Ctrl+S by calling `0x0047cd80-0x0047d04a`; that helper starts in the following compose/send helper island and remains a later exact by-item/source-split target, not a reason to keep this class unassigned.
- `OnMailDeleteReply` and `ShowDeleteReplyAlert` both convert packet payloads into wide text, install `MailDeleteReplyAlert` vtables at `0x0061476c/0x006147d4/0x00614804`, and publish singleton slot `0x0067adbc`.
- Boundary samples show `0xcc` padding at `0x0047c405-0x0047c4b0`, `0x0047c94b-0x0047c950`, `0x0047c9e6-0x0047c9f0`, `0x0047cb3e-0x0047cb40`, and `0x0047cc74` before the following `0x0047cd80` helper.

## Assignment Gate

Direct parent assignment is justified. The child page now reaches `85/86` after live IDA method, caller, vtable-store, command-handler, alert-construction, and boundary evidence was added. The direct file parent [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) is already `86/85` and documents the same mail read/reply dialog family, BulletinSession call-in surface, and [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md) aggregate. `AUTOGEN_PARENT_UID` is therefore set to `0000KZ`.

## Cross-References

- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:000096][NewMailDialog](by-class/NewMailDialog.md)
- [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md)
- [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)

## Changes

- 2026-06-08 A009 Batch 136:
  - Changed score from `78/82` to `85/86`.
  - Set `AUTOGEN_PARENT_UID:0000KZ` because this page and the direct [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) parent now both satisfy the corrected `85/85` gate.
  - Added live IDA MCP evidence for all eight `MailDialog` core functions in `0x0047b220-0x0047cc74`, constructor callers, three vtable stores, command-handler packet/delete/reply cases, `ConfirmDeleteMailAlert` and `MailDeleteReplyAlert` vtable stores, singleton publication, padding boundaries, and the `0x0047cd80` Ctrl+S helper split caveat.
  - Final C++ remains blank because source-quality field names, complete control/member declarations, and the helper split around `0x0047cd80` are still below the `95/95` emission bar.
- 2026-06-05: Marked reconstructable because live IDA MCP confirms the mail read/reply dialog constructor, command, shortcut, reply-send, delete-reply, and destructor functions are NexusTK-owned UI/mail behavior. Kept `AUTOGEN_PARENT_UID` blank because this class is `78/82`, below the 80/80 parent-attachment gate, even though [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) is the likely owner. Live IDA MCP evidence: `lookup_funcs` confirms starts at `0x0047b220`, `0x0047c500`, `0x0047c730`, `0x0047c8d0`, `0x0047c9f0`, and `0x0047ebf0`; `callers` confirms constructor calls from `0x004717f6` and `0x00471f71`, and `SendReply` called from `0x0047c67e` inside `sub_47C500`.
- Completion/confidence score update: existed before as `0/0`; changed to `78/82`. Summary: the mail read/reply dialog has core parse/build, command, shortcut, reply send, delete-reply, destructor, and module-placement documentation, but unresolved helper cleanup keeps it below high completion. Evidence: linked mail dialog memory range, method address table, IDA-confirmed boundaries, and Ctrl+S helper caveat.
