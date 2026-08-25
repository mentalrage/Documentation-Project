*** UID:0001Y2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Mail Dialog Vtable Family

## Status

- Entity kind: reviewed non-emitting vtable-family index. Exact owner-specific children carry the source-emitting vtable declarations.
- Covered module: [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) plus the mail-specific side of [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
- Current classification: `reviewed-non-emitting-ownership-split`.
- Exact owner-specific children:
  - [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md), assigned to [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) at `87/91`.
  - [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md), assigned to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) at `86/89`.
- Parent routing: intentionally blank. This master page clears `90/93` as an index, but no single direct parent owns the full family after the exact child split.
- Evidence basis: IDA MCP vtable/global/xref checks from 2026-05-26, 2026-06-01, 2026-06-08, B001-009 live IDA MCP `py_eval` on 2026-06-10 against IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, and A004 live IDA MCP `entity_query`, `lookup_funcs`, `trace_data_flow`, and `make_signature_for_range` on 2026-06-12 against session `b001_nexustk` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64`.

## B001-009 Split Result

| Child | Covered vtables | Direct owner | Score | Rationale |
| --- | --- | --- | --- | --- |
| [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md) | `MailListDialog`, `MailListPane`, `MailDialog`, `NewMailDialog` | [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) | `87/91` | Decorated vtable bases, COL pointers, and constructor stores all belong to the core mail list/read/compose dialog constructors. Parent clears `86/85`. |
| [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md) | `MailTransferReplyAlert`, `ConfirmDeleteMailAlert`, `MailDeleteReplyAlert` | [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) | `86/89` | Decorated vtable bases, COL pointers, and store refs identify mail-specific alert wrappers that are currently part of the shared board/mail reply-delete alert source bucket. Parent clears `85/86`. |

This master page remains useful as the complete mail vtable inventory and as the boundary record for the `.rdata` span. It is not a direct source-owned type page after the child split and is not a separate source-emitting artifact.

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

2026-06-08 Batch 136 live IDA MCP recheck reconfirmed the direct store/xref split that controls assignment:

- `MailDialog` primary/secondary/tertiary bases `0x0061439c`, `0x00614400`, and `0x00614430` have COL pointers at `0x00643cb4`, `0x00643d1c`, and `0x00643d30`, and are written only by the constructor at `0x0047b287`, `0x0047b28d`, and `0x0047b297`.
- `NewMailDialog` bases `0x0061443c`, `0x006144a0`, and `0x006144d0` remain tied to constructor stores at `0x0047d0a1`, `0x0047d0a7`, and `0x0047d0b1`.
- `MailTransferReplyAlert` bases `0x006144dc`, `0x00614544`, and `0x00614574` are written from transfer-reply setup paths at `0x0047d90d`, `0x0047db2b`, `0x0047dc61`, and raw/projected setup near `0x0047e067`.
- `ConfirmDeleteMailAlert` bases `0x006146c8`, `0x00614730`, and `0x00614760` have stores from mail-list and mail-dialog delete-confirm paths, including `0x0047c6c5/0x0047c6cb/0x0047c6d5` in `MailDialog::OnCommand` and `0x0047c9b4/0x0047c9ba/0x0047c9c4` in the local confirm-delete helper.
- `MailDeleteReplyAlert` bases `0x0061476c`, `0x006147d4`, and `0x00614804` are stored by mail-list packet handlers, `MailDialog` delete-reply helpers at `0x0047caf7/0x0047cafd/0x0047cb07` and `0x0047cc2d/0x0047cc33/0x0047cc3d`, the raw constructor near `0x0047e6c7`, destructor/getter support at `0x0047e6f0`, and scalar destructor support at `0x0047eb96`.

2026-06-12 A004 live IDA MCP split refresh used session `b001_nexustk` for `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe.i64` and reconfirmed the non-emitting master decision:

- `server_health` reported `NexusTK.exe`, imagebase `0x400000`, Hex-Rays ready, and strings cache ready.
- `entity_query 0x00614220-0x00614840` reports the core mail-dialog vtable strip from `0x00614238` through `0x006144d0`, the mail-alert companion tables at `0x006144dc`, `0x006146c8`, and `0x0061476c`, the shared `ConfirmDeleteAlert`/`DeleteReplyAlert` interleave at `0x00614580-0x006146bc`, and successor strings `aGbbs01Pal` at `0x00614818` and `aGbbs01Epf` at `0x00614834`.
- `lookup_funcs` reconfirmed function boundaries for the core constructors at `0x00479110` (`0xc1b` bytes), `0x0047a8a0` (`0x59` bytes), `0x0047b220` (`0x11e5` bytes), and `0x0047d050` (`0x771` bytes), plus alert action/destructor anchors `0x0047e090`, `0x0047e510`, `0x0047e6f0`, and `0x0047eb90`; projected `0x0047e6a0` remains not an IDA function.
- `trace_data_flow backward` reconfirmed primary vptr stores for `MailListDialog`, `MailListPane`, `MailDialog`, `NewMailDialog`, `MailTransferReplyAlert`, `ConfirmDeleteMailAlert`, and `MailDeleteReplyAlert`, including the representative store sites already listed below.
- `trace_data_flow backward 0x00614580` confirmed the shared `ConfirmDeleteAlert` successor gap is a separate board/article alert strip, and `trace_data_flow backward 0x00614818` confirmed the successor after `MailDeleteReplyAlert` is UTF-16 resource string data.
- `make_signature_for_range` returned unique signatures for the core mail-dialog strip `0x00614234-0x006144dc` and for the alert-companion/interleaved strip `0x006144dc-0x0061480c`.
- `int_convert.py` verified `0xa0` as 160 and `0xa4` as 164 for the secondary and tertiary base offsets; it also verified representative byte spans `0x24` as 36, `0x30` as 48, `0x68` as 104, `0x0c` as 12, and `0x14` as 20.

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

The mail alert tables are interleaved with board/article alert tables in `.rdata`. Keep mail packet/context evidence visible, but route the current vtable ownership through [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md) and [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) unless later source-split evidence proves these mail-only wrappers were private to `MailDialogs.cpp`.

B009 2026-06-19 MailDeleteReplyAlert reanalysis adds the important slot-specific route: the primary `MailDeleteReplyAlert` slot at `0x0061476c` dispatches the compiler-generated scalar deleting destructor [UID:0002TA][0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb90-0x0047ebef.MailDeleteReplyAlertScalarDeletingDestructor.md), and action slot `0x006147c8` dispatches [UID:0002T9][0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete](by-memory/0x0047e730-0x0047e836.MailDeleteReplyAlertOnConfirmDelete.md). The raw constructor at `0x0047e6a0` remains constructor-shaped but no-route; inline table stores at `0x0047a4bf`, `0x0047a84d`, `0x0047caf7`, and `0x0047cc2d` are corroborating construction/use evidence, not a reason to move this master index to a single owner.

## Shared Slot Notes

- The secondary and tertiary views line up with the same `+0xa0` and `+0xa4` base-subobject offsets used by the board/article dialog family.
- B006's 2026-06-27 source-quality implementation adds the shared [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) mail-side consumer proof: MailListDialog secondary `0x0061429c + 0x10` gives slot `0x006142ac`, MailDialog secondary `0x00614400 + 0x10` gives slot `0x00614410`, and NewMailDialog secondary `0x006144a0 + 0x10` gives slot `0x006144b0`; all three slots store `0x00472040`. These are consumer slots of the shared command-`'1'` secondary bridge and do not move [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) ownership to MailDialogs or change this master page's non-emitting split-index classification.
- For [UID:00007M][MailListPane](by-class/MailListPane.md), the B002 2026-06-19 source-quality reanalysis names the key slots as `OnScrollChanged` at `0x0047ad80`, `OnItemSelected` at `0x0047ade0`, `RequestSelectedMail` / `OpenSelectedMail` at `0x0047ae30`, and `DrawEntry` / `DrawItem` at `0x0047ae50`. `0x0047ae30` is not a pure selected-id accessor because it tail-calls the [UID:00007L][MailListDialog](by-class/MailListDialog.md) request helper.
- [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) cover the compiler-generated destructor thunks for `MailDeleteReplyAlert` and `MailDialog`. Represent these through C++ inheritance/destructor layout, not handwritten source functions.
- RTTI locator records follow the table slices. Do not treat the next RTTI word or the next class table as another virtual method slot.

## Wave3 Data Issue

Current `simroot_v2` metadata reports `vtable_count: 0` for each checked mail family class even though IDA confirms the bases listed above:

`MailListDialog`, `MailListPane`, `MailDialog`, `NewMailDialog`, `MailTransferReplyAlert`, `ConfirmDeleteMailAlert`, and `MailDeleteReplyAlert`.

## Reconstruction Notes

Use this page as the class-layout inventory for the mail dialog and mail-alert vtable pass. Emit source-owned declarations through the exact child pages:

- [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md) for `MailDialogs.cpp`.
- [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md) for `BulletinReplyAlerts.cpp` unless later source-split evidence proves the mail-only wrappers were private to `MailDialogs.cpp`.

The table order supports a compact original mail-dialog neighborhood, but the shared `ConfirmDeleteAlert`/`DeleteReplyAlert` gap and current alert-wrapper ownership model prevent this master page from being assigned to one direct source owner. `RECONSTRUCTABLE` is therefore `FALSE` for this index; the required source-level vtable declarations remain reconstructable through [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md) and [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md).

## Assignment Gate

This page is `reviewed-non-emitting-ownership-split`. The master inventory clears the evidence gate at `90/93`, and both direct source candidates also clear the parent score gate: [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) is `86/85`, and [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) is `85/86`. However, neither candidate is the actual direct parent for the whole type page. `MailDialogs` directly owns the core list/read/compose dialog tables, while `BulletinReplyAlerts` directly owns or remains the current shared-owner bucket for the mail-transfer/delete alert companion tables. Because this page intentionally spans both sides, `AUTOGEN_PARENT_UID` remains blank and the master index is not reconstructable.

Candidate ranking:

| Candidate | Decision | Evidence and rejection/selection reason |
| --- | --- | --- |
| Split into [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md) and [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md) | selected | Matches IDA-backed vtable/store clusters and the two direct file-owner buckets that clear `85/85`. |
| Assign whole family to [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) | rejected for master | Best forced single-owner alternate because all target classes are mail-context classes and many alert stores occur in mail paths. It would still absorb the shared alert wrapper bucket and conflict with the `ConfirmDeleteAlert`/`DeleteReplyAlert` interleave between mail-specific alert tables. |
| Assign whole family to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) | rejected for master | Correct for the alert child but not for the four core mail dialog/list/compose classes. |
| Assign whole family to [UID:00024W][0x00613ab0-0x00614cd0.BoardMailReadOnlyData](by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md) | rejected | Broader `.rdata` aggregate crosses board, session, web-board, alert, mail, resource-string, and `ChangeMan` owners. |
| Create a new `MailAndReplyAlerts.cpp` owner | rejected for current reconstruction | Would duplicate the already gate-cleared [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) and [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) buckets. The needed scope is narrower child split, not a new source owner. |

Score rationale: completion is raised because the page now records the live A004 IDA recheck, unique strip signatures, exact successor boundaries, and the explicit non-emitting index classification. Confidence is raised because the 2026-06-12 evidence agrees with the earlier B001 split and the child/direct-parent gates, while still preserving the final-source caveat for the mail-specific alert wrapper placement.

## Cross-References

- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md)
- [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md)
- [UID:0000ZO][0x00479110-0x0047ec2b.MailDialogs](by-memory/0x00479110-0x0047ec2b.MailDialogs.md)
- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- [UID:00024W][0x00613ab0-0x00614cd0.BoardMailReadOnlyData](by-memory/0x00613ab0-0x00614cd0.BoardMailReadOnlyData.md)
- [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md)
- [Wave3 data issues](../../wave3_data_issues.md)

## Changes

- 2026-06-27 B006 [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) support sync: added mail-side secondary `+0x10` consumer slot proof for MailListDialog, MailDialog, and NewMailDialog, each storing `0x00472040`, while preserving this page as a non-emitting split index and preserving [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) ownership through the current BoardDialogs route.
- 2026-06-12 A004 Batch 327:
  - Changed score from `88/91` to `90/93`.
  - Changed `RECONSTRUCTABLE:TRUE` to `RECONSTRUCTABLE:FALSE`.
  - Reclassified the master from a reconstructable ownership-split inventory to a non-emitting mixed-owner index because [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md) and [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md) already carry the reconstructable source declarations and no single direct parent owns both children plus the shared alert gap.
  - A004 live IDA MCP reconfirmed the decorated bases, constructor/action/destructor vptr stores, shared `ConfirmDeleteAlert`/`DeleteReplyAlert` interleave, `0x00614818` resource-string successor, and unique signatures for the two main strips.
- 2026-06-20 supervisor Rule 26 incorporation of B002 MailListPane report: mirrored source-facing slot names for the core `MailListPane` secondary/primary vtable targets while leaving this master family as a non-emitting split index.
- 2026-06-21 B009 Rule 26 support incorporation: no score change. Mirrored MailDeleteReplyAlert slot-level action/destructor evidence from [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md) while keeping this master page non-emitting.
- 2026-06-10 B001-009:
  - Changed score from `85/88` to `88/91`.
  - Created exact owner-specific children [UID:000321][MailDialogCoreVtables](by-type/by-vtable/MailDialogCoreVtables.md) and [UID:000322][MailAlertCompanionVtables](by-type/by-vtable/MailAlertCompanionVtables.md).
  - Reclassified this page from the prior ownership-unknown status to `reviewed-85-ownership-split`; exact children now carry the direct ownership decisions.
  - B001-009 live IDA MCP reconfirmed the decorated bases, COL pointers, constructor/action/destructor store refs, the shared `ConfirmDeleteAlert`/`DeleteReplyAlert` gap, and the `0x0061480c` resource-string boundary.
- 2026-06-08 A009 Batch 136:
  - Changed score from `82/86` to `85/88`.
  - Added a current IDA MCP recheck of `MailDialog`, `NewMailDialog`, `MailTransferReplyAlert`, `ConfirmDeleteMailAlert`, and `MailDeleteReplyAlert` table bases, COL pointers, constructor/action/destructor store xrefs, and the source-owner split.
  - Left `AUTOGEN_PARENT_UID` blank because the core dialog tables pointed to [UID:0000KZ][MailDialogs](by-file/MailDialogs.md), the alert companion tables pointed to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) or shared alert ownership, and no single direct parent owned the full vtable-family inventory before the B001-009 child split.
- 2026-06-01: The page previously had unevaluated validator scores (`COMPLETION:0`, `CONFIDENCE:0`) and a blank reconstructability flag. It is now marked `RECONSTRUCTABLE:TRUE` with `COMPLETION:82` and `CONFIDENCE:86` after IDA MCP rechecked the decorated vtable symbols, RTTI locator placement, slot counts, constructor/destructor store xrefs, and the shared-alert interleave boundaries. The score remains below the 95+ final-audit gate because final source split decisions and complete source declarations for all participating classes are not closed.
