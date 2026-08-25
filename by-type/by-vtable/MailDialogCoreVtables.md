*** UID:000321 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000KZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000KZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Compiler-generated MailDialogs vtables and RTTI are covered by the class declarations in [UID:00007L][MailListDialog](by-class/MailListDialog.md), [UID:00007M][MailListPane](by-class/MailListPane.md), [UID:00007K][MailDialog](by-class/MailDialog.md), and [UID:000096][NewMailDialog](by-class/NewMailDialog.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Mail Dialog Core Vtables

## Status

- Entity kind: owner-specific vtable child split from [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md).
- Source owner: [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).
- Covered classes: [UID:00007L][MailListDialog](by-class/MailListDialog.md), [UID:00007M][MailListPane](by-class/MailListPane.md), [UID:00007K][MailDialog](by-class/MailDialog.md), and [UID:000096][NewMailDialog](by-class/NewMailDialog.md).
- Reconstruction handling: source-declared/generated-binary vtable layouts required by the mail dialog class declarations.
- Confidence: very strong for decorated vtable symbols, complete-object-locator pointers, constructor stores, class-header consequences, exact compiler/source split, and direct `MailDialogs` source ownership.

## Binary Evidence

B001-009 live IDA MCP `py_eval` on 2026-06-10 used IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, input `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`.

| Class | Primary | Secondary | Tertiary | Store/xref evidence |
| --- | --- | --- | --- | --- |
| `MailListDialog` | `0x00614238` | `0x0061429c` | `0x006142cc` | Decorated `??_7MailListDialog@@6B@` bases with COLs `0x00643b98`, `0x00643c00`, `0x00643c14`; constructor stores at `0x0047916d`, `0x00479173`, `0x0047917d` inside `0x00479110-0x00479d2b`. |
| `MailListPane` | `0x006142d8` | `0x00614360` | `0x00614390` | Decorated `??_7MailListPane@@6B@` bases with COLs `0x00643c28`, `0x00643c8c`, `0x00643ca0`; constructor stores at `0x0047a8d1`, `0x0047a8d7`, `0x0047a8e1` inside `0x0047a8a0-0x0047a8f9`. |
| `MailDialog` | `0x0061439c` | `0x00614400` | `0x00614430` | Decorated `??_7MailDialog@@6B@` bases with COLs `0x00643cb4`, `0x00643d1c`, `0x00643d30`; constructor stores at `0x0047b287`, `0x0047b28d`, `0x0047b297` inside `0x0047b220-0x0047c405`. |
| `NewMailDialog` | `0x0061443c` | `0x006144a0` | `0x006144d0` | Decorated `??_7NewMailDialog@@6B@` bases with COLs `0x00643d44`, `0x00643dac`, `0x00643dc0`; constructor stores at `0x0047d0a1`, `0x0047d0a7`, `0x0047d0b1` inside `0x0047d050-0x0047d7c1`. |

B006's 2026-06-27 source-quality implementation adds the shared [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) command-`'1'` secondary bridge slot proof for the core mail dialog classes. These are consumer slots, not MailDialogs-owned method bodies:

| Class | Secondary table | Slot | Value | Disposition |
| --- | --- | --- | --- | --- |
| `MailListDialog` | `0x0061429c` | `+0x10` at `0x006142ac` | `0x00472040` | Consumes [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md); ownership remains the current BoardDialogs route. |
| `MailDialog` | `0x00614400` | `+0x10` at `0x00614410` | `0x00472040` | Consumes [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md); ownership remains the current BoardDialogs route. |
| `NewMailDialog` | `0x006144a0` | `+0x10` at `0x006144b0` | `0x00472040` | Consumes [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md); ownership remains the current BoardDialogs route. |

Boundary facts:

- The preceding named vtable is `??_7TransferReplyPredefinedAlert@@6B@_1` at `0x0061422c`.
- The successor after this child is `??_7MailTransferReplyAlert@@6B@` at `0x006144dc`, which belongs to the mail-alert companion split.
- The executable owner cluster is the mail dialog aggregate [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md), whose direct file parent is [UID:0000KZ][MailDialogs](by-file/MailDialogs.md).

## Ownership Inference

The direct source owner is [UID:0000KZ][MailDialogs](by-file/MailDialogs.md). Each vtable has exactly one constructor-store cluster in the mail list, mail list-pane, read/reply dialog, or compose dialog constructor. The four covered classes are already documented as mail UI classes, and the file parent clears the corrected `85/85` gate at `86/85`.

The shared alert wrapper parent [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) is rejected for this child because none of these four core mail dialog constructors are alert wrappers, and the vtable stores occur before the alert companion strip.

## MailListDialog Slot And Helper Notes

B007's 2026-06-20 MailListDialog source-quality pass keeps the `MailListDialog` vtable ownership unchanged while refining the source-facing helper names used by the class declaration and exact method child:

| Evidence | Source-facing role |
| --- | --- |
| Constructor stores at `0x0047916d`, `0x00479173`, and `0x0047917d` | Three compiler vtable view stores for `MailListDialog`; generate these from C++ class layout rather than writing manual stores. |
| `0x00479d30` | `MailListDialog::SendSelectedMailReadRequest`; replaces the stale generic `SendMailRequest` label. |
| `0x00479e20`, `0x00479f40`, `0x00479f90`, `0x0047a020`, `0x0047a1e0`, `0x0047a200`, `0x0047a280`, `0x0047a760` | Retained no-direct-route helper pockets for selected delete, row removal, initial page request, compose/reply wrappers, delete-confirm construction, and delete-reply alert display. These are exact [UID:0003PU][0x00479110-0x0047a894.MailListDialogCore](by-memory/0x00479110-0x0047a894.MailListDialogCore.md) method-body candidates, not separate vtable owner pages. |

The helper-pocket findings affect declarations and method-body placement only. Ownership remains [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), and vtable/data emission should still arise from normal C++ class declarations.

## MailListPane Slot Notes

B002's 2026-06-19 MailListPane source-quality pass refined the source-facing names for the key vtable-routed functions:

| Vtable reference | Target | Source-facing role |
| --- | --- | --- |
| `0x00614364` | `0x0047ad80` | `MailListPane::OnScrollChanged` / scroll-position changed override; secondary-view receiver adjusts back by `-0xa0`. |
| `0x00614368` | `0x0047ade0` | `MailListPane::OnItemSelected` / selection changed override; secondary-view receiver adjusts back by `-0xa0`. |
| `0x00614354` | `0x0047ae30` | `MailListPane::RequestSelectedMail` / `OpenSelectedMail`; reject pure `GetSelectedMailId` because the body tail-calls `MailListDialog::SendSelectedMailReadRequest` at `0x00479d30`. |
| `0x00614358` | `0x0047ae50` | `MailListPane::DrawEntry` / `DrawItem`; draws id, sender, date, and subject columns with selection/unread coloring. |

These slot notes affect source declarations only. Ownership remains with [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), and compiler vtable stores must still be generated from C++ class layout rather than emitted as manual source statements.

## MailDialog Slot Notes

B006's 2026-06-20 MailDialog source-quality pass refined the source-facing names for the key `MailDialog` vtable-routed functions:

| Vtable reference | Target | Source-facing role |
| --- | --- | --- |
| `0x006143e4` | `0x0047c500` | `MailDialog::OnCommand` / `HandleCommand`; command ids route close/list return, reply send, confirm delete, page-navigation packets, and forward/base behavior. |
| `0x00614408` | `0x0047c730` | `MailDialog::OnKeyInput` / `HandleKeyInput`; Ctrl+S calls [UID:0003PX][0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper](by-memory/0x0047cd80-0x0047d04a.MailDialogSaveMailToFileShortcutHelper.md) as `SaveCurrentMailToFile`, not as a send/reply shortcut. |
| `0x006143f8` | `0x0047c9f0` | `MailDialog::OnMailDeleteReply` / `HandleMailDeleteReply`; mail-delete callback updates current dialog/list state and coordinates `MailDeleteReplyAlert` use. |

The secondary/tertiary destructor paths and [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) remain compiler support. Represent them through C++ inheritance/destructor layout, not handwritten source functions.

## Assignment Gate

| Candidate | Decision | Reason |
| --- | --- | --- |
| [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) | selected | Direct source bucket for mail list, list-pane, read/reply, and compose dialog classes; parent clears `86/85`. |
| [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) | rejected | Owns or buckets reply/delete alert wrappers, not the four core mail dialog classes. |
| [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md) | rejected as parent | Mixed master inventory spanning this child and the mail-alert companion child. |
| [UID:00024W][0x00613ab0-0x00614cd0.BoardMailReadOnlyData](by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md) | rejected | Broader `.rdata` range crosses board, session, web-board, alert, mail, resource-string, and ChangeMan owners. |

`AUTOGEN_PARENT_UID` is set to `0000KZ` because this child and the direct file parent both clear `85/85`, and the binary evidence supports `MailDialogs` as the actual owner.

## Compiler-Covered Source Consequence

- The complete formal H declarations on [UID:00007L][MailListDialog](by-class/MailListDialog.md) `MailListDialog`, [UID:00007M][MailListPane](by-class/MailListPane.md) `MailListPane`, [UID:00007K][MailDialog](by-class/MailDialog.md) `MailDialog`, and [UID:000096][NewMailDialog](by-class/NewMailDialog.md) `NewMailDialog` are the handwritten source representation for all four vtable/COL families.
- The formal CPP channel contains only the exact compiler-covered explanatory comment; formal H remains physically blank because the four owning class pages provide the declarations. Emitting literal vtable arrays, COLs, constructor vptr stores, secondary/tertiary adjustment thunks, or scalar deleting wrappers would duplicate compiler output and produce reverse-engineered rather than developer-authored source.
- Exact protected binary evidence remains the four primary/secondary/tertiary table triads, their COL pointers, constructor store sites, inherited shared command slots, and the boundary from the preceding `TransferReplyPredefinedAlert` table to successor `MailTransferReplyAlert`.
- UID0000KZ whole-file review closes the previous empty-emitter ambiguity: this is reconstructable compiler-covered evidence with a nonblank owner/emitter route and a target-specific comment-only no-literal-table disposition. The generated binary structures must arise from the four class declarations.
- Historical assumptions that a wholly blank formal block was sufficient are superseded. The comment-only formal CPP records the covered-by relationship without pretending compiler data was handwritten source and prevents an empty-emitter marker.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `94` | All four vtable families, COLs, stores, inherited slots, source owner, compiler-generated exclusions, declaration routes, and boundary protections are documented. |
| Confidence `95` | Decorated RTTI/vtable identities and constructor stores directly prove the compiler consequence. Remaining uncertainty belongs to inferred class lexical details, not this data disposition. |

## Cross-References

- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:00007L][MailListDialog](by-class/MailListDialog.md)
- [UID:00007M][MailListPane](by-class/MailListPane.md)
- [UID:00007K][MailDialog](by-class/MailDialog.md)
- [UID:000096][NewMailDialog](by-class/NewMailDialog.md)
- [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md)
- [UID:00024W][0x00613ab0-0x00614cd0.BoardMailReadOnlyData](by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md)

## Changes

- 2026-08-11 Agent-B002 UID0000KZ whole-file implementation callback: raised `87/91` to `94/95`, documented the exact compiler-covered formal-H consequence and no-literal-code route, reconciled corrected child paths, and preserved all table/COL/store/thunk protections with both formal channels blank.

- 2026-06-27 B006 [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) support sync: added the MailListDialog, MailDialog, and NewMailDialog secondary `+0x10` consumer slots to the shared command-`'1'` bridge at `0x00472040`; score, owner, emitter, and blank C++ state unchanged.
- 2026-06-20 supervisor Rule 26 incorporation of B006 MailDialog report: added MailDialog vtable slot names for `OnCommand`, `OnKeyInput`, and `OnMailDeleteReply`, corrected the Ctrl+S target to `SaveCurrentMailToFile`, and restated that destructor adjustor paths are compiler support only.
- 2026-06-20 supervisor-worker Rule 26 incorporation of B007 `00007L-MailListDialog-class-source-quality.md`: added MailListDialog helper-name and no-direct-route method-body placement notes, and synced the MailListPane selected-mail slot prose to the refined `SendSelectedMailReadRequest` name.
- 2026-06-10 B001-009: Created as an exact owner-specific vtable child for the core `MailDialogs` class tables after live IDA MCP reconfirmed the decorated bases, COL pointers, constructor-store xrefs, and boundaries separating the mail-core tables from the mail alert companion and shared board alert tables.
- 2026-06-20 supervisor Rule 26 incorporation of B002 MailListPane report: added source-facing slot names for the four key `MailListPane` vtable targets and recorded the rejected `GetSelectedMailId` interpretation for `0x0047ae30`.
