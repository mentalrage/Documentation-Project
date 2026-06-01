*** UID:0001Y2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Mail Dialog Vtable Family

## Status

- Entity kind: vtable family inventory.
- Covered module: [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) and the mail-specific side of [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
- Confidence: strong for table bases and constructor/store xrefs; medium for final source split between `MailDialogs.cpp` and shared alert helpers.
- Evidence basis: IDA MCP `list_globals`, vtable xref checks, and current `simroot_v2` metadata checks on 2026-05-26.

## Current IDA Recheck

IDA MCP `py_eval` on 2026-06-01 rechecked the vtable bases directly from the current IDB. Every table listed below has a decorated MSVC vtable global at the documented base, a complete-object-locator pointer at `base - 4`, and direct data xrefs from constructor/destructor paths that store the primary, secondary, and tertiary views.

The recheck confirmed the core dialog view sizes and store sites:

| Class | View sizes | Current xref/store sites |
| --- | --- | --- |
| `MailListDialog` | primary 24 slots, secondary 11 slots, tertiary 2 slots | `0x0047916d`, `0x00479173`, `0x0047917d` in `0x00479110`. |
| `MailListPane` | primary 33 slots, secondary 11 slots, tertiary 2 slots | `0x0047a8d1`, `0x0047a8d7`, `0x0047a8e1` in `0x0047a8a0`. |
| `MailDialog` | primary 24 slots, secondary 11 slots, tertiary 2 slots | `0x0047b287`, `0x0047b28d`, `0x0047b297` in `0x0047b220`. |
| `NewMailDialog` | primary 24 slots, secondary 11 slots, tertiary 2 slots | `0x0047d0a1`, `0x0047d0a7`, `0x0047d0b1` in `0x0047d050`. |

The alert companion views are also current IDA-backed:

| Class | View sizes | Current xref/store sites |
| --- | --- | --- |
| `MailTransferReplyAlert` | primary 25 slots, secondary 11 slots, tertiary 2 slots | `0x0047d90d`, `0x0047db2b`, `0x0047dc61`, `0x0047e067`, plus matching secondary/tertiary stores at neighboring offsets. |
| `ConfirmDeleteMailAlert` | primary 25 slots, secondary 11 slots, tertiary 2 slots | `0x0047a17b`, `0x0047a2e4`, `0x0047c6c5`, `0x0047c9b4`, `0x0047e4e7`, plus matching secondary/tertiary stores at neighboring offsets. |
| `MailDeleteReplyAlert` | primary 25 slots, secondary 11 slots, tertiary 2 slots | `0x0047a4bf`, `0x0047a84d`, `0x0047caf7`, `0x0047cc2d`, `0x0047e6c7`, plus matching secondary/tertiary stores at neighboring offsets. |

Important boundary note: the `MailTransferReplyAlert` tertiary table at `0x00614574` is only the two-slot tertiary view ending at `0x0061457c`. The following named vtables at `0x00614580`, `0x006145e8`, `0x00614618`, `0x00614624`, `0x0061468c`, and `0x006146bc` are the shared `ConfirmDeleteAlert` and `DeleteReplyAlert` family, not extra `MailTransferReplyAlert` slots. `ConfirmDeleteMailAlert` begins at `0x006146c8`; `MailDeleteReplyAlert` ends at `0x0061480c`, and the next named items at `0x00614818`, `0x00614830`, and `0x00614834` are mail/board resource strings.

## Core Dialog Tables

| Class | Primary | Secondary `+0xa0` | Tertiary `+0xa4` | Store/xref evidence |
| --- | --- | --- | --- | --- |
| [UID:00007L][MailListDialog](by-class/MailListDialog.md) | `0x00614238` | `0x0061429c` | `0x006142cc` | Constructor stores at `0x0047916d`, `0x00479173`, and `0x0047917d`. |
| [UID:00007M][MailListPane](by-class/MailListPane.md) | `0x006142d8` | `0x00614360` | `0x00614390` | Constructor stores at `0x0047a8d1`, `0x0047a8d7`, and `0x0047a8e1`. |
| [UID:00007K][MailDialog](by-class/MailDialog.md) | `0x0061439c` | `0x00614400` | `0x00614430` | Constructor stores at `0x0047b287`, `0x0047b28d`, and `0x0047b297`. |
| [UID:000096][NewMailDialog](by-class/NewMailDialog.md) | `0x0061443c` | `0x006144a0` | `0x006144d0` | Constructor stores at `0x0047d0a1`, `0x0047d0a7`, and `0x0047d0b1`. |

## Alert Companion Tables

| Class | Primary | Secondary `+0xa0` | Tertiary `+0xa4` | Store/xref evidence |
| --- | --- | --- | --- | --- |
| [UID:00007N][MailTransferReplyAlert](by-class/MailTransferReplyAlert.md) | `0x006144dc` | `0x00614544` | `0x00614574` | Stores/xrefs at `0x0047d90d`, `0x0047db2b`, `0x0047dc61`, `0x0047e067`, plus matching secondary/tertiary stores at the neighboring offsets. |
| [UID:000034][ConfirmDeleteMailAlert](by-class/ConfirmDeleteMailAlert.md) | `0x006146c8` | `0x00614730` | `0x00614760` | Stores/xrefs at `0x0047a17b`, `0x0047a2e4`, `0x0047c6c5`, `0x0047c9b4`, `0x0047e4e7`, plus matching secondary/tertiary stores at the neighboring offsets. |
| [UID:00007J][MailDeleteReplyAlert](by-class/MailDeleteReplyAlert.md) | `0x0061476c` | `0x006147d4` | `0x00614804` | Stores/xrefs at `0x0047a4bf`, `0x0047a84d`, `0x0047caf7`, `0x0047cc2d`, `0x0047e6c7`, `0x0047e6f0`, `0x0047eb96`, plus matching secondary/tertiary stores at the neighboring offsets. |

The mail alert tables are interleaved with board/article alert tables in `.rdata`. Keep class ownership tied to packet/context behavior: mail transfer/delete helpers stay with mail dialog reconstruction even though their base alert mechanics are shared with [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md).

## Shared Slot Notes

- The secondary and tertiary views line up with the same `+0xa0` and `+0xa4` base-subobject offsets used by the board/article dialog family.
- [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) cover the compiler-generated destructor thunks for `MailDeleteReplyAlert` and `MailDialog`. Represent these through C++ inheritance/destructor layout, not handwritten source functions.
- RTTI locator records follow the table slices. Do not treat the next RTTI word or the next class table as another virtual method slot.

## Wave3 Data Issue

Current `simroot_v2` metadata reports `vtable_count: 0` for each checked mail family class even though IDA confirms the bases listed above:

`MailListDialog`, `MailListPane`, `MailDialog`, `NewMailDialog`, `MailTransferReplyAlert`, `ConfirmDeleteMailAlert`, and `MailDeleteReplyAlert`.

## Reconstruction Notes

Use this page as the class-layout anchor for the mail dialog source file pass. The table order supports a compact original module around mail list/view/compose dialogs plus small mail-specific alert companions. The alert companions may have been private classes in `MailDialogs.cpp` or part of a nearby shared reply-alert source, but the vtable and caller evidence does not support treating them as unrelated standalone modules.

## Cross-References

- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- [UID:00024W][0x00613ab0-0x00614cd0.BoardMailReadOnlyData](by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md)
- [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-06-01: The page previously had unevaluated validator scores (`COMPLETION:0`, `CONFIDENCE:0`) and a blank reconstructability flag. It is now marked `RECONSTRUCTABLE:TRUE` with `COMPLETION:82` and `CONFIDENCE:86` after IDA MCP rechecked the decorated vtable symbols, RTTI locator placement, slot counts, constructor/destructor store xrefs, and the shared-alert interleave boundaries. The score remains below the 95+ final-audit gate because final source split decisions and complete source declarations for all participating classes are not closed.
