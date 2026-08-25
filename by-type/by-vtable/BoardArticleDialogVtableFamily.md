*** UID:0001X4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID0001X4 BoardArticleDialogVtableFamily is layout support for the board/article dialog class family under UID0000HT BoardDialogs. It emits no raw vtable source because the documented table bytes should be regenerated from final class declarations and inheritance layout.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Board Article Dialog Vtable Family

## Status

- Entity kind: vtable family inventory.
- Covered module: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) and [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
- Confidence: strong for table bases and constructor/store xrefs; medium for final class splits in small alert helpers.
- Evidence basis: IDA MCP `list_globals`, `py_eval` xref dumps, vtable-base xrefs, raw constructor stores, and exact child-range checks.
- Rebuild handling: these tables should be emitted from class declarations and inheritance layout, not hand-authored as raw address tables.
- Autogen parent: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) as the current board/article dialog owner bucket. Alert companion rows remain cross-referenced to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).

## Core Dialog Tables

| Class | Primary | Secondary `+0xa0` | Tertiary `+0xa4` | Store/xref evidence |
| --- | --- | --- | --- | --- |
| [UID:00001C][BulletinDialog](by-class/BulletinDialog.md) | `0x00613ba8` | `0x00613c0c` | `0x00613c3c` | Raw constructor stores at `0x00472017`, `0x0047201f`, `0x00472029`; exact data child [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md). |
| [UID:00000Z][BoardListDialog](by-class/BoardListDialog.md) | `0x00613c48` | `0x00613cac` | `0x00613cdc` | Constructor stores at `0x004720cd`, `0x004720d3`, `0x004720dd`; exact data child [UID:0002VE][0x00613c44-0x00613ce4.BoardListDialogVtableData](by-memory/0x00613c44-0x00613ce4.BoardListDialogVtableData.md). |
| [UID:000010][BoardListPane](by-class/BoardListPane.md) | `0x00613ce8` | `0x00613d70` | `0x00613da0` | Constructor/setup stores at `0x004721d4`, `0x004721da`, `0x004721e4`; reset/copy stores also appear at `0x00472566` and `0x00472a04`. B002 UID0002V9 source-quality sync names primary slots `0x00613d64 -> BoardListPane::OnItemDoubleClick` and `0x00613d68 -> BoardListPane::DrawItem`; raw helper starts remain no-direct-route BoardListPane bodies on [UID:0002V9][0x004729e0-0x00472bf5.BoardListPaneCore](by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md). |
| [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md) | `0x00613dac` | `0x00613e10` | `0x00613e40` | Constructor stores at `0x00472cfd`, `0x00472d03`, `0x00472d0d`; exact code child [UID:00030G][0x00472c00-0x004748ea.ArticleListDialogCore](by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md). |
| [UID:00000L][ArticleListPane](by-class/ArticleListPane.md) | `0x00613e4c` | `0x00613ed4` | `0x00613f04` | Constructor stores at `0x00474942`, `0x00474948`, `0x00474952`; exact code child [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md). |
| [UID:00000J][ArticleDialog](by-class/ArticleDialog.md) | `0x00613f10` | `0x00613f74` | `0x00613fa4` | Constructor stores at `0x0047544a`, `0x00475450`, `0x0047545a`; exact code child [UID:00030J][0x004753e0-0x00476c0a.ArticleDialogCore](by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md). |
| [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md) | `0x00613fb0` | `0x00614014` | `0x00614044` | Constructor stores at `0x00476c56`, `0x00476c5c`, `0x00476c66`; exact code child [UID:00030K][0x00476c10-0x00477790.NewArticleDialogCore](by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md). |
| [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md) | `0x00614050` | `0x006140b4` | `0x006140e4` | Constructor stores at `0x004777ee`, `0x004777f4`, `0x004777fe`; exact data child [UID:00050Q][0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData](by-memory/0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData.md). |

For [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md), the exact data child [UID:00050Q][0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData](by-memory/0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData.md) closes the whole `[0x0061404c,0x006140ec)` band. Primary slot `0x00614050 -> 0x0047ec30` reaches [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md), while secondary slot `0x006140b4 -> 0x0047e931` and tertiary slot `0x006140e4 -> 0x0047e93c` reach [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md). Those entries are compiler destructor glue. Source-routed slots are `0x00614094 -> 0x00478380` for [UID:0002UO][0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint](by-memory/0x00478380-0x0047864c.NewPredefinedFormArticleDialogOnPaint.md) `void OnPaint()`, `0x00614098 -> 0x00478240` for [UID:0002UK][0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick](by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md) `OnCommand`, `0x006140a8 -> 0x00478370` for [UID:0002UN][0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl](by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md) `SetHoverControl`, `0x006140ac -> 0x00478940` for [UID:0002UQ][0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert](by-memory/0x00478940-0x00478a93.NewPredefinedFormArticleDialogHandleTransferReplyPredefinedAlert.md) transfer-reply handling, and tertiary `0x006140e8 -> 0x004782b0` for [UID:0002UM][0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer](by-memory/0x004782b0-0x00478363.NewPredefinedFormArticleDialogOnTimer.md) `TimerHandler::OnTimer`. The OnTimer slot supersedes the historical generic `HandleEvent` identity. All concrete table/destructor/adjustor bytes should be regenerated from class declarations, not hand-authored as source.

## Alert Companion Tables

| Class | Primary | Secondary `+0xa0` | Tertiary `+0xa4` | Store/xref evidence |
| --- | --- | --- | --- | --- |
| [UID:0000F5][TransferReplyAlert](by-class/TransferReplyAlert.md) | `0x006140f0` | `0x00614158` | `0x00614188` | Stores in projected/inline constructors at `0x0047729d`, `0x00477403`, `0x00477549`, and raw [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md) store `0x00478fb7`. |
| [UID:0000F6][TransferReplyPredefinedAlert](by-class/TransferReplyPredefinedAlert.md) | `0x00614194` | `0x006141fc` | `0x0061422c` | Stores in predefined-form alert setup at `0x0047832d`, `0x00478a53`, `0x00478b99`, and `0x00479077`. |
| [UID:000033][ConfirmDeleteAlert](by-class/ConfirmDeleteAlert.md) | `0x00614580` | `0x006145e8` | `0x00614618` | Stores from delete-confirm callsites and constructor at `0x00473ecc`, `0x00474134`, `0x004765b2`, `0x00476884`, and `0x0047e137`. |
| [UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md) | `0x00614624` | `0x0061468c` | `0x006146bc` | Stores from constructor/destructor helpers at `0x0047e310`, `0x0047e350`, and `0x0047eb36`. |

### DeleteReplyAlert Source Routing

- Primary slot address `0x00614680` (primary-table offset `+0x5c`) contains `0x0047e390`, now exact source child [UID:0004WF][0x0047e390-0x0047e4a6.DeleteReplyAlertOnPrimaryButton](by-memory/0x0047e390-0x0047e4a6.DeleteReplyAlertOnPrimaryButton.md). The inherited [UID:00000B][AlertPane](by-class/AlertPane.md) declaration names this slot `OnPrimaryButton`, superseding historical `OnConfirm` behavior prose.
- [UID:0004WC][0x0047e2f0-0x0047e34b.DeleteReplyAlertConstructor](by-memory/0x0047e2f0-0x0047e34b.DeleteReplyAlertConstructor.md) installs all three views as a compiler construction consequence and initializes the class-specific tail fields.
- [UID:0004WD][0x0047e350-0x0047e379.DeleteReplyAlertDestructor](by-memory/0x0047e350-0x0047e379.DeleteReplyAlertDestructor.md) is the sole source ordinary virtual destructor. Its source body clears the singleton; vtable restoration and base teardown are compiler consequences.
- [UID:0004WE][0x0047e380-0x0047e386.DeleteReplyAlertGetSingleton](by-memory/0x0047e380-0x0047e386.DeleteReplyAlertGetSingleton.md) is a static source accessor associated with the class, not a virtual slot.
- Primary scalar slot and secondary/tertiary adjustor routes into [UID:0003Q6][0x0047eb30-0x0047eb8f.DeleteReplyAlertScalarDeletingDestructor](by-memory/0x0047eb30-0x0047eb8f.DeleteReplyAlertScalarDeletingDestructor.md) are compiler ABI products generated from the ordinary virtual destructor. They must not be emitted as source methods or raw tables.

The nearby mail alert variants have their own table bases in the same `.rdata` neighborhood, including `MailTransferReplyAlert` at `0x006144dc`, `0x00614544`, `0x00614574` and `MailDeleteReplyAlert` at `0x0061476c`, `0x006147d4`, `0x00614804`. Keep them cross-referenced with [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) and [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md), not solely with board/article reconstruction.

## Shared Slot Notes

- [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) is referenced by multiple secondary tables in this family. B006 session `80de0a67` verifies six board/article/predefined consumer slots in this family: `0x00613c1c`, `0x00613cbc`, `0x00613e20`, `0x00613f84`, `0x00614024`, and `0x006140c4`, each storing `0x00472040` at secondary `+0x10`. Do not duplicate it into every class during source migration.
- The [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) body is not pure compiler-only adjustor glue: it reads an event/action object, checks the command string at `event+0x0c` for ASCII `'1'`, returns false on mismatch, adjusts secondary `this` by `-0xa0`, and tail-jumps through primary slot `+0x5c`. Its formal C++ block now emits only a marker comment until the shared secondary interface/event/slot declarations are source-quality.
- Deleting-destructor adjustor thunks generally live in secondary and tertiary `+0x00` slots. The adjacent [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) should be represented by the C++ class layout/destructor, not handwritten as business logic.
- RTTI locator words immediately follow each primary/secondary/tertiary table slice. Do not read the next class's RTTI pointer as a virtual slot when walking these tables.

## 2026-06-14 Live IDA Refresh

- IDA MCP session `a001_goal2_class_batch` refreshed `xrefs_to` for all 24 core dialog table bases listed above. Every listed primary, secondary, and tertiary base still resolves to the expected constructor/setup store sites, including raw `BulletinDialog` stores at `0x00472017/0x0047201f/0x00472029`, modeled board-list stores under `0x00472070`, article-list/viewer/compose stores under `0x00472ca0`, `0x004748f0`, `0x004753e0`, `0x00476c10`, and predefined-form stores under `0x004777a0`.
- The same refresh checked all 12 alert companion bases. `TransferReplyAlert` and `TransferReplyPredefinedAlert` each have four store groups including their raw constructor stores (`0x00478fb7/0x00478fbd/0x00478fc7` and `0x00479077/0x0047907d/0x00479087`); `ConfirmDeleteAlert` has five store groups including raw constructor stores `0x0047e137/0x0047e13d/0x0047e147`; `DeleteReplyAlert` has stores in `0x0047e2f0`, `0x0047e350`, and scalar destructor support `0x0047eb30`.
- Live `lookup_funcs` confirms the intentional raw/model split: `0x00472000`, `0x00478f90`, `0x00479050`, and `0x0047e100` are still not IDA-modeled function starts, while `0x00472070`, `0x004748f0`, `0x004753e0`, `0x00476c10`, `0x004777a0`, and `0x0047e2f0` are modeled functions with current sizes. This supports the existing exact child pages and keeps raw constructor evidence tied to by-memory children rather than invented function metadata.
- Current parent evidence remains split by source semantics: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) is the board/article source bucket at `85/86`, while [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) is the shared alert wrapper bucket at `86/87`. The neighboring mail-specific alert tables remain excluded through [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md).

## Reconstruction Notes

Use this page as the class-layout anchor for the board/article dialog module. The table order supports a compact original source organization around `BulletinDialog`, board-list panes/dialogs, article-list panes/dialogs, article viewer/composer classes, predefined-form article dialogs, and small alert companions.

## Coverage And Split Notes

| Area | Current state | Next evidence needed |
| --- | --- | --- |
| `BulletinDialog` | Exact vtable data child exists at [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md). | Final inherited slot names and header declaration shape. |
| `BoardListDialog` | Exact vtable data child exists at [UID:0002VE][0x00613c44-0x00613ce4.BoardListDialogVtableData](by-memory/0x00613c44-0x00613ce4.BoardListDialogVtableData.md). | Final inherited slot names and header declaration shape. |
| `NewPredefinedFormArticleDialog` | Exact vtable data child exists at [UID:00050Q][0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData](by-memory/0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData.md), with all three COLs, 24/11/2 slots, constructor stores, source routes, and the TimerHandler OnTimer correction. | Final compiler comparison after the accepted class H is generated. |
| Remaining board/article core dialogs | Primary, secondary, and tertiary table bases plus constructor stores are listed, and the article-list/viewer/compose code children are now exact. | Exact by-memory vtable-data child pages for each remaining class, matching the `BulletinDialog`, `BoardListDialog`, and `NewPredefinedFormArticleDialog` split quality. |
| Reply/delete alert companions | Table bases and store xrefs are documented. DeleteReplyAlert now has exact constructor/destructor/getter/OnPrimaryButton source children, exact primary slot `0x00614680`, and compiler-scalar exclusion; raw constructor evidence remains documented for the other alert classes. | Final placement between board/mail/shared alert source files and exact vtable-data children for the remaining alert tables. |
| Mail-adjacent tables | Neighboring mail tables are identified and intentionally cross-referenced rather than owned here. | Keep owner split synchronized with [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md). |

## Autogen Status

- Reconstructable: true, as compiler-emitted class-layout data.
- Parent: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- C++: marker-only; vtable bytes should emerge from the final C++ class hierarchy, and inherited slot names are not complete enough for declarations here.

## Score Rationale

Completion is `88` after adding exact child [UID:00050Q][0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData](by-memory/0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData.md) for the complete NewPredefinedFormArticleDialog band, correcting the TimerHandler slot to `OnTimer`, and preserving all existing family tables and split work. Confidence is `93` because the child records all 40 dwords, three constructor stores, three COLs, 24/11/2 slot counts, source-method routes, compiler destructor routes, and the next-class boundary. The family remains below final-audit levels because other listed classes still lack exact data children and final inherited slot declarations.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0001X5][BulletinDialogVtables](by-type/by-vtable/BulletinDialogVtables.md)
- [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md)
- [UID:0002VE][0x00613c44-0x00613ce4.BoardListDialogVtableData](by-memory/0x00613c44-0x00613ce4.BoardListDialogVtableData.md)
- [UID:00050Q][0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData](by-memory/0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData.md)
- [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md)
- [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:00030G][0x00472c00-0x004748ea.ArticleListDialogCore](by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md)
- [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md)
- [UID:00030J][0x004753e0-0x00476c0a.ArticleDialogCore](by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md)
- [UID:00030K][0x00476c10-0x00477790.NewArticleDialogCore](by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md)
- [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md)
- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)

## Changes

- 2026-08-14 B004 UID0000LT implementation callback: raised `85/91` to `88/93`, linked exact data child [UID:00050Q][0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData](by-memory/0x0061404c-0x006140ec.NewPredefinedFormArticleDialogVtableData.md), recorded the full three-view `[0x0061404c,0x006140ec)` split, and corrected tertiary slot `0x006140e8 -> 0x004782b0` from generic `HandleEvent` to `TimerHandler::OnTimer`. Existing broad family evidence and compiler-generated table disposition remain intact.

- 2026-07-22 B005 UID0003Q0 callback: retained `85/91`; added DeleteReplyAlert primary slot `0x00614680 -> OnPrimaryButton`, exact ordinary destructor/static accessor/source-child relationships, and scalar deleting wrapper/adjustor no-source disposition.
- 2026-07-02 B002 UID0002V9 support sync: added BoardListPane primary slot names `0x00613d64 -> BoardListPane::OnItemDoubleClick` and `0x00613d68 -> BoardListPane::DrawItem`, plus the no-direct-route raw helper caveat for [UID:0002V9][0x004729e0-0x00472bf5.BoardListPaneCore](by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md). Score unchanged.
- 2026-06-26 B002 support sync: added the [UID:0002UK][0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick](by-memory/0x00478240-0x004782a2.NewPredefinedFormArticleDialogHandleButtonClick.md) primary command-handler slot `0x00614098 -> 0x00478240` to the NewPredefinedFormArticleDialog slot notes, with neighboring controls `0x00614094 -> 0x00478380`, `0x006140ac -> 0x00478940`, and `0x006140e8 -> 0x004782b0`. Score unchanged at `85/91`.
- 2026-06-27 B006 command-bridge support sync: added current-session proof for [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) as the shared secondary `+0x10` command-`'1'` bridge consumed by BulletinDialog, BoardListDialog, ArticleListDialog, ArticleDialog, NewArticleDialog, and NewPredefinedFormArticleDialog; score unchanged.
- 2026-06-19 B012 scalar-wrapper sync: added the [UID:0000ZS][0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor](by-memory/0x0047ec30-0x0047ec6b.NewPredefinedFormArticleDialogScalarDeletingDestructor.md) primary-slot no-code decision to the NewPredefinedFormArticleDialog destructor-slot map. Score unchanged.
- 2026-06-21 B011 support sync: added the exact `NewPredefinedFormArticleDialog` destructor-slot mapping for primary `0x00614050`, secondary `0x006140b4`, and tertiary `0x006140e4`, and clarified that [UID:0000ZQ][0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks](by-memory/0x0047e931-0x0047e947.NewPredefinedFormArticleDialogAdjustorThunks.md) is compiler-generated secondary/tertiary destructor adjustor glue, while `0x006140e8 -> 0x004782b0` is source-routed virtual behavior. Score unchanged.
- 2026-05-31: Changed completion/confidence from `0/0` to `62/82` and marked the page reconstructable. Evidence: the page already had broad IDA-backed family inventory, and the `BulletinDialog` row now points to exact IDA-verified data child [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md). Completion remains moderate because most other vtable clusters in the family still need exact by-memory child splits.
- 2026-06-02: Raised completion/confidence to `70/84`, attached `AUTOGEN_PARENT_UID:0000HT`, and added rebuild handling, autogen status, and coverage/split notes. Evidence: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) is now staged under `NexusTK/ui/dialogs/`, has `85` confidence, and already identifies this vtable family as the class-layout anchor for board/article dialogs; alert companion ownership remains explicitly cross-referenced to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
- 2026-06-04: Raised completion/confidence to `76/88` and removed stale non-IDA metadata framing from the evidence basis. Evidence: live IDA MCP confirmed exact [UID:0002VE][0x00613c44-0x00613ce4.BoardListDialogVtableData](by-memory/0x00613c44-0x00613ce4.BoardListDialogVtableData.md) boundaries, three `BoardListDialog` vtable bases, constructor-store xrefs, and adjacent `BulletinDialog`/`BoardListPane` boundaries.
- 2026-05-27: The `TransferReplyAlert` vtable evidence previously listed `0x00478fb7` as part of a projected/inline constructor group. Updated it to cite raw constructor range [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md). Evidence: IDA raw disassembly confirms the three vtable stores at `0x00478fb7`, `0x00478fbd`, and `0x00478fc7`.
- 2026-06-08 A008 Batch 107 continuation:
  - Before: `COMPLETION:76`, `CONFIDENCE:88`, with the article core classes still listed only by vtable bases and constructor stores.
  - Changed to: `COMPLETION:80`, `CONFIDENCE:89`.
  - Summary/evidence: added exact code-child references for `ArticleListDialog`, `ArticleListPane`, `ArticleDialog`, and `NewArticleDialog`; live IDA `xrefs_to` rechecked their primary vtable-store sites at `0x00472cfd`, `0x00474942`, `0x0047544a`, and `0x00476c56`. This supports the direct class-parent assignments while leaving exact vtable-data child splits as the remaining completion gap.
- 2026-06-14 A002 Goal2 score pass:
  - Before: `COMPLETION:80`, `CONFIDENCE:89`; only a subset of article primary stores had a current-session recheck.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:91`.
  - Summary/evidence: live IDA MCP refreshed `xrefs_to` for all 24 core table bases and all 12 alert companion bases, confirmed raw constructor starts that remain non-functions, checked modeled function starts for the major source bodies, and synchronized the alert companion coverage note with current [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md) evidence. Exact vtable-data child pages remain the main below-gate work item.
