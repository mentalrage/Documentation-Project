*** UID:0001X4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

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
| [UID:000010][BoardListPane](by-class/BoardListPane.md) | `0x00613ce8` | `0x00613d70` | `0x00613da0` | Constructor/setup stores at `0x004721d4`, `0x004721da`, `0x004721e4`; reset/copy stores also appear at `0x00472566` and `0x00472a04`. |
| [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md) | `0x00613dac` | `0x00613e10` | `0x00613e40` | Constructor stores at `0x00472cfd`, `0x00472d03`, `0x00472d0d`; exact code child [UID:00030G][0x00472c00-0x004748ea.ArticleListDialogCore](by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md). |
| [UID:00000L][ArticleListPane](by-class/ArticleListPane.md) | `0x00613e4c` | `0x00613ed4` | `0x00613f04` | Constructor stores at `0x00474942`, `0x00474948`, `0x00474952`; exact code child [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md). |
| [UID:00000J][ArticleDialog](by-class/ArticleDialog.md) | `0x00613f10` | `0x00613f74` | `0x00613fa4` | Constructor stores at `0x0047544a`, `0x00475450`, `0x0047545a`; exact code child [UID:00030J][0x004753e0-0x00476c0a.ArticleDialogCore](by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md). |
| [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md) | `0x00613fb0` | `0x00614014` | `0x00614044` | Constructor stores at `0x00476c56`, `0x00476c5c`, `0x00476c66`; exact code child [UID:00030K][0x00476c10-0x00477790.NewArticleDialogCore](by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md). |
| [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md) | `0x00614050` | `0x006140b4` | `0x006140e4` | Constructor stores at `0x004777ee`, `0x004777f4`, `0x004777fe`. |

## Alert Companion Tables

| Class | Primary | Secondary `+0xa0` | Tertiary `+0xa4` | Store/xref evidence |
| --- | --- | --- | --- | --- |
| [UID:0000F5][TransferReplyAlert](by-class/TransferReplyAlert.md) | `0x006140f0` | `0x00614158` | `0x00614188` | Stores in projected/inline constructors at `0x0047729d`, `0x00477403`, `0x00477549`, and raw [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md) store `0x00478fb7`. |
| [UID:0000F6][TransferReplyPredefinedAlert](by-class/TransferReplyPredefinedAlert.md) | `0x00614194` | `0x006141fc` | `0x0061422c` | Stores in predefined-form alert setup at `0x0047832d`, `0x00478a53`, `0x00478b99`, and `0x00479077`. |
| [UID:000033][ConfirmDeleteAlert](by-class/ConfirmDeleteAlert.md) | `0x00614580` | `0x006145e8` | `0x00614618` | Stores from delete-confirm callsites and constructor at `0x00473ecc`, `0x00474134`, `0x004765b2`, `0x00476884`, and `0x0047e137`. |
| [UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md) | `0x00614624` | `0x0061468c` | `0x006146bc` | Stores from constructor/destructor helpers at `0x0047e310`, `0x0047e350`, and `0x0047eb36`. |

The nearby mail alert variants have their own table bases in the same `.rdata` neighborhood, including `MailTransferReplyAlert` at `0x006144dc`, `0x00614544`, `0x00614574` and `MailDeleteReplyAlert` at `0x0061476c`, `0x006147d4`, `0x00614804`. Keep them cross-referenced with [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) and [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md), not solely with board/article reconstruction.

## Shared Slot Notes

- [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) is referenced by multiple secondary tables in this family. Do not duplicate it into every class during source migration.
- Deleting-destructor adjustor thunks generally live in secondary and tertiary `+0x00` slots. The adjacent [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) should be represented by the C++ class layout/destructor, not handwritten as business logic.
- RTTI locator words immediately follow each primary/secondary/tertiary table slice. Do not read the next class's RTTI pointer as a virtual slot when walking these tables.

## Reconstruction Notes

Use this page as the class-layout anchor for the board/article dialog module. The table order supports a compact original source organization around `BulletinDialog`, board-list panes/dialogs, article-list panes/dialogs, article viewer/composer classes, predefined-form article dialogs, and small alert companions.

## Coverage And Split Notes

| Area | Current state | Next evidence needed |
| --- | --- | --- |
| `BulletinDialog` | Exact vtable data child exists at [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md). | Final inherited slot names and header declaration shape. |
| `BoardListDialog` | Exact vtable data child exists at [UID:0002VE][0x00613c44-0x00613ce4.BoardListDialogVtableData](by-memory/0x00613c44-0x00613ce4.BoardListDialogVtableData.md). | Final inherited slot names and header declaration shape. |
| Remaining board/article core dialogs | Primary, secondary, and tertiary table bases plus constructor stores are listed, and the article-list/viewer/compose code children are now exact. | Exact by-memory vtable-data child pages for each remaining class, matching the `BulletinDialog` and `BoardListDialog` split quality. |
| Reply/delete alert companions | Table bases and store xrefs are documented, with raw constructor evidence for `TransferReplyAlert`. | Raw constructor confirmation for the remaining projected alert starts and final placement between board/mail/shared alert source files. |
| Mail-adjacent tables | Neighboring mail tables are identified and intentionally cross-referenced rather than owned here. | Keep owner split synchronized with [UID:0001Y2][MailDialogVtableFamily](by-type/by-vtable/MailDialogVtableFamily.md). |

## Autogen Status

- Reconstructable: true, as compiler-emitted class-layout data.
- Parent: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- C++: intentionally blank; vtable bytes should emerge from the final C++ class hierarchy, and inherited slot names are not complete enough for declarations here.

## Score Rationale

Completion is raised to `80` for parent attachment, rebuild classification, explicit coverage gaps, and exact code-child links for the article-list, article-pane, article-viewer, and normal compose classes. Confidence rises to `89` because Batch 107 continuation rechecked the primary vtable store xrefs for those four article classes, but exact vtable-data child pages for most family members and several projected alert constructors still limit the score.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0001X5][BulletinDialogVtables](by-type/by-vtable/BulletinDialogVtables.md)
- [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md)
- [UID:0002VE][0x00613c44-0x00613ce4.BoardListDialogVtableData](by-memory/0x00613c44-0x00613ce4.BoardListDialogVtableData.md)
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

- 2026-05-31: Changed completion/confidence from `0/0` to `62/82` and marked the page reconstructable. Evidence: the page already had broad IDA-backed family inventory, and the `BulletinDialog` row now points to exact IDA-verified data child [UID:0002MI][0x00613ba4-0x00613c44.BulletinDialogVtableData](by-memory/0x00613ba4-0x00613c44.BulletinDialogVtableData.md). Completion remains moderate because most other vtable clusters in the family still need exact by-memory child splits.
- 2026-06-02: Raised completion/confidence to `70/84`, attached `AUTOGEN_PARENT_UID:0000HT`, and added rebuild handling, autogen status, and coverage/split notes. Evidence: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) is now staged under `NexusTK/ui/dialogs/`, has `85` confidence, and already identifies this vtable family as the class-layout anchor for board/article dialogs; alert companion ownership remains explicitly cross-referenced to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
- 2026-06-04: Raised completion/confidence to `76/88` and removed stale non-IDA metadata framing from the evidence basis. Evidence: live IDA MCP confirmed exact [UID:0002VE][0x00613c44-0x00613ce4.BoardListDialogVtableData](by-memory/0x00613c44-0x00613ce4.BoardListDialogVtableData.md) boundaries, three `BoardListDialog` vtable bases, constructor-store xrefs, and adjacent `BulletinDialog`/`BoardListPane` boundaries.
- 2026-05-27: The `TransferReplyAlert` vtable evidence previously listed `0x00478fb7` as part of a projected/inline constructor group. Updated it to cite raw constructor range [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md). Evidence: IDA raw disassembly confirms the three vtable stores at `0x00478fb7`, `0x00478fbd`, and `0x00478fc7`.
- 2026-06-08 A008 Batch 107 continuation:
  - Before: `COMPLETION:76`, `CONFIDENCE:88`, with the article core classes still listed only by vtable bases and constructor stores.
  - Changed to: `COMPLETION:80`, `CONFIDENCE:89`.
  - Summary/evidence: added exact code-child references for `ArticleListDialog`, `ArticleListPane`, `ArticleDialog`, and `NewArticleDialog`; live IDA `xrefs_to` rechecked their primary vtable-store sites at `0x00472cfd`, `0x00474942`, `0x0047544a`, and `0x00476c56`. This supports the direct class-parent assignments while leaving exact vtable-data child splits as the remaining completion gap.
