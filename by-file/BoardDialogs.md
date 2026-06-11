*** UID:0000HT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# BoardDialogs

## Status

- Confidence: strong for board/article dialog module ownership, exact child split coverage, and the shared article-navigation helper assignment; medium for web-board split and final `BoardDialogs.cpp` versus `ArticleDialogs.cpp` partitioning.
- Proposed module folder: `ui/dialogs/`
- Candidate files: `ui/dialogs/BoardDialogs.cpp`, `ui/dialogs/ArticleDialogs.cpp`, `ui/dialogs/BulletinSession.cpp`, `ui/dialogs/WebBoardDialog.cpp`, `ui/dialogs/NewPredefinedFormArticleDialog.cpp`, and shared alert helpers in [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md).
- Recovered source leads: `class_BulletinDialog.cpp`, `class_BoardListDialog.cpp`, `class_BoardListPane.cpp`, `class_ArticleListDialog.cpp`, `class_ArticleListPane.cpp`, `class_ArticleDialog.cpp`, `class_NewArticleDialog.cpp`, `class_NewPredefinedFormArticleDialog.cpp`, `recovered/DeserializePredefinedFormArticleEntries_00478650.cpp`, `class_WebBoardDialog.cpp`, `class_TransferReplyAlert.cpp`, `class_TransferReplyPredefinedAlert.cpp`, `class_ConfirmDeleteAlert.cpp`, and `class_DeleteReplyAlert.cpp`.
- Documentation basis: IDA-confirmed ranges, raw constructor bytes, vtable-family pages, linked by-memory reports, and source-split notes recorded in the by-* pages.

## Hypothesis

The board/article UI is a coherent bulletin-session feature. It owns board category selection, article lists, article viewing, article posting, delete/transfer reply handling, and a browser-backed web board variant. It is coordinated by [UID:0000HX][BulletinSession](by-file/BulletinSession.md). It should not be represented as one recovered class-file bucket per dialog class in the final source tree.

Likely structure:

```text
ui/dialogs/BoardDialogs.cpp
ui/dialogs/ArticleDialogs.cpp
ui/dialogs/BulletinSession.cpp
ui/dialogs/NewPredefinedFormArticleDialog.cpp
ui/dialogs/WebBoardDialog.cpp
```

Possible compact legacy structure:

```text
ui/dialogs/BulletinDialogs.cpp
```

## Reconstruction Handling

- The assigned reconstruction folder is `NexusTK/ui/dialogs/`, staging this page as the current `BoardDialogs.cpp` owner bucket.
- Treat this as a practical parent for board/article dialog class-layout and vtable documentation while the final split between `BoardDialogs.cpp`, `ArticleDialogs.cpp`, `BulletinDialogs.cpp`, and companion alert files remains open.
- Do not emit final C++ from this page yet. It is an ownership and grouping anchor for child documentation, not proof that every listed helper belongs in one original source file.

## Proposed Contents

| Entity | Range evidence | Recovered/source lead | Role |
| --- | --- | --- | --- |
| `BulletinSession` | `0x00471150-0x00471ff1`, stack helpers `0x004a0f40-0x004a14a7` | `class_BulletinSession.cpp` | Session coordinator, packet/dialog dispatcher, and shared board/mail dialog stack owner. |
| `BulletinDialog` | raw constructor [UID:0000ZI][0x00472000-0x0047203a.BulletinDialogRawConstructor](by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md), shared virtual [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md), shared non-emitting destructor [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md) | `class_BulletinDialog.cpp` | Common bulletin dialog base over `DialogInSession`; constructor bytes are confirmed but the start is not an IDA function object. |
| `BoardListDialog` | [UID:0002EJ][0x00472070-0x004729dd.BoardListDialogCore](by-memory/0x00472070-0x004729dd.BoardListDialogCore.md), title helper `0x0049db30-0x0049db5c`, shared destructor [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md) | `class_BoardListDialog.cpp` | Parses board-list packets, displays board categories, sends board selection packets. |
| `BoardListPane` | [UID:0002V9][0x004729e0-0x00472bf5.BoardListPaneCore](by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md), shared list-pane destructor [UID:0000ZR][0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor](by-memory/0x0047ea50-0x0047ea8b.SharedListPaneScalarDeletingDestructor.md) | `class_BoardListPane.cpp` | Draws board rows and handles double-click activation. |
| `ArticleListDialog` | [UID:00030G][0x00472c00-0x004748ea.ArticleListDialogCore](by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md), non-emitting destructor [UID:00033O][0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor](by-memory/0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor.md) | `class_ArticleListDialog.cpp` | Lists article entries, sends read/write/delete/page requests, handles list updates and server alerts, and owns local raw helper islands. |
| `ArticleListPane` | [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md), shared helpers excluded to [UID:0000KT][ListPane](by-file/ListPane.md) | `class_ArticleListPane.cpp` | Board article list row renderer, sorted insert/lookup, input, painting, and raw row helper islands. |
| Article navigation helpers | [UID:00030H][0x004751c0-0x004753df.ArticleNavigationHelpers](by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md) | article/list helper island | Shared article-navigation packet helper island assigned to this file-level bucket because callers span article-list, normal new-article, predefined-form, and transfer-reply alert paths. |
| `ArticleDialog` | [UID:00030J][0x004753e0-0x00476c0a.ArticleDialogCore](by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md), non-emitting destructor [UID:00033N][0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor](by-memory/0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor.md) | `class_ArticleDialog.cpp` | Article viewer with navigation, reply/submit/delete/report actions, server-response handling, and adjacent raw helper islands. |
| `NewArticleDialog` | [UID:00030K][0x00476c10-0x00477790.NewArticleDialogCore](by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md), shared destructor [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md) | `class_NewArticleDialog.cpp` | Compose dialog for new board articles, command/error/reply handling, and post packet serialization. |
| `NewPredefinedFormArticleDialog` | `0x004777a0-0x00478f8d` | `class_NewPredefinedFormArticleDialog.cpp` | Template/form article compose dialog with dynamic fields and predefined post serialization. |
| `DeserializePredefinedFormArticleEntries_478650` | `0x00478650-0x00478932` | `recovered/DeserializePredefinedFormArticleEntries_00478650.cpp` | Parser for serialized predefined-form article rows. |
| `TransferReplyAlert` | constructor [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md); action `0x00478fe0-0x0047904e` | `class_TransferReplyAlert.cpp` | Article/bulletin transfer-reply acknowledgement alert. |
| `TransferReplyPredefinedAlert` | projected constructor `0x00479050`; action [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md) | `class_TransferReplyPredefinedAlert.cpp` | Predefined-form article transfer-reply acknowledgement alert; recovered body is suspect. |
| `ConfirmDeleteAlert` | constructor [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md); action [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md) | `class_ConfirmDeleteAlert.cpp` | Board/article delete confirmation packet sender. |
| `DeleteReplyAlert` | `0x0047e2f0-0x0047e4a5`, plus destructor companions | `class_DeleteReplyAlert.cpp` | Local reply-list delete confirmation and singleton cleanup. |
| `WebBoardDialog` | `0x0046d050-0x0046e25b` | `class_WebBoardDialog.cpp` plus un-emitted IDA-only methods | Browser-backed live web-board dialog; interacts with browser controls, opcode `0x73`, cookies, board response loader, URL escaping, and render/layout helpers. |
| `WebBoardDialogOld` | `0x0046e260-0x0046efda` | recovered output placed it through `class_RankingDialog.cpp` plus raw helpers at `0x0046e260`, `0x0046e4c0`, `0x0046ea30`, and `0x0046ee80` | Fixed-art `WEBBOARD.EPD` legacy web-board dialog using the same browser-control response/cookie flow, raw browser-control teardown-like helper, raw mode/control rectangle helper, raw initial request helper, raw old URL escape helper, destructor, and old browser-control close/reposition callbacks. |

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed:

- `0x00472070-0x00472869`, `0x004728a0-0x00472999`, `0x00472b50-0x00472b63`, and `0x00472b70-0x00472bf5` for board list UI.
- `0x00472ca0-0x0047398d`, `0x004739b0-0x00473a96`, `0x00473e00-0x00473ff3`, `0x00474230-0x00474461`, and `0x00474470-0x004746ac` for article-list dialog flow.
- `0x004748f0-0x00474983`, `0x00474990-0x00474a6e`, and `0x00474f90-0x004751b1` for article-list pane behavior.
- `0x004753e0-0x00476315`, `0x00476410-0x004765fe`, `0x00476740-0x00476814`, and `0x004768c0-0x004769ec` for article viewing/action flow.
- `0x00476c10-0x00477151`, `0x004771b0-0x00477212`, and `0x00477590-0x00477790` for new article composition.
- `0x004777a0-0x004781e5`, `0x00478650-0x00478933`, `0x00478940-0x00478a93`, and `0x00478be0-0x00478f8e` for predefined-form article composition, form parsing, reply alerts, and post serialization.
- `0x00478f90-0x00478fd8` for the raw `TransferReplyAlert` constructor, with IDA-confirmed vtable stores despite missing function metadata.
- `0x0047e100-0x0047e158` for the raw `ConfirmDeleteAlert` constructor, with IDA-confirmed delete-mode field and vtable stores despite missing function metadata.
- `0x00478fe0`, `0x004790a0`, `0x0047e160-0x0047e2e4`, `0x0047e2f0`, `0x0047e350`, `0x0047e380`, `0x0047e390`, `0x0047e8ef`, `0x0047e8fa`, and `0x0047eb30` for board/article alert companions.
- `0x0046d050-0x0046d324` for the active web board dialog constructor.
- `0x0046d480`, `0x0046d580`, `0x0046da70`, `0x0046dbd0`, `0x0046dd00`, `0x0046dea0`, `0x0046e260`, `0x0046e2a0`, `0x0046e4c0`, `0x0046e640`, `0x0046ea00`, and `0x0046eaa0` for active/old web-board packet forwarding, URL escaping, render/layout helpers, constructors, and response parsing.

IDA reports no function at the recovered `BulletinDialog` constructor start `0x00472000`, but raw disassembly confirms constructor-shaped code through `0x0047203a` that calls `0x004a1400` and stores `BulletinDialog` vtables. IDA also confirms a real vtable callback at `0x00472040-0x00472069`; both issues are tracked in [wave3_data_issues](../wave3_data_issues.md).

## Ownership Notes

- `WebBoardDialog` is browser-backed and can either live in `ui/dialogs/WebBoardDialog.cpp` with board dialogs or in the browser module with a board-specific wrapper. Because its behavior is a board flow, keep it cross-referenced here.
- `WebBoardDialogOld` was recovered through `RankingDialog`, but IDA confirms it has `WebBoardDialogOld` vtables, singleton `0x0067aba0`, `WEBBOARD.EPD` resources, and the web-board opcode/cookie flow. Exclude it from ranking migrations.
- `BulletinSession` should be a sibling session source, not folded into every board/mail dialog file. Its dialog-stack helpers are shared by board and mail action/alert flows.
- `BulletinDialog` owns vtable bases `0x00613ba8`, `0x00613c0c`, and `0x00613c3c`; stored recovered metadata omitted them with `vtable_count: 0`. Keep [UID:0001X5][BulletinDialogVtables](by-type/by-vtable/BulletinDialogVtables.md) as the class-layout anchor.
- The broader [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) confirms three-view vtable layouts for `BoardListDialog`, `BoardListPane`, `ArticleListDialog`, `ArticleListPane`, `ArticleDialog`, `NewArticleDialog`, `NewPredefinedFormArticleDialog`, and the small reply/delete alert companions. The checked metadata files omitted these vtable counts.
- The `0x004f3c00+` methods recovered under `ArticleListPane` are now documented as shared [UID:0000KT][ListPane](by-file/ListPane.md) helpers, not board-dialog-private code. Keep board/article source ownership focused on article rows, packets, dialogs, and board-specific actions.
- `NewPredefinedFormArticleDialog` is now documented as a likely separate source candidate because its constructor/parser are large, template-specific, and include the file-local parser helper at `0x00478650`.
- Batch 107 split the formerly broad article-list/viewer/compose portion of [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md) into exact children [UID:00030G][0x00472c00-0x004748ea.ArticleListDialogCore](by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md), [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md), [UID:00030H][0x004751c0-0x004753df.ArticleNavigationHelpers](by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md), [UID:00030J][0x004753e0-0x00476c0a.ArticleDialogCore](by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md), and [UID:00030K][0x00476c10-0x00477790.NewArticleDialogCore](by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md). These children close the largest source-bucket evidence gap while preserving raw-helper caveats.
- Batch 107 continuation assigned the four class-owned exact children to their direct class parents after the class pages cleared `85/85`: [UID:00030G][0x00472c00-0x004748ea.ArticleListDialogCore](by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md) -> [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md), [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md) -> [UID:00000L][ArticleListPane](by-class/ArticleListPane.md), [UID:00030J][0x004753e0-0x00476c0a.ArticleDialogCore](by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md) -> [UID:00000J][ArticleDialog](by-class/ArticleDialog.md), and [UID:00030K][0x00476c10-0x00477790.NewArticleDialogCore](by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md) -> [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md).
- B001-025 assigns [UID:00030H][0x004751c0-0x004753df.ArticleNavigationHelpers](by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md) to this file-level bucket after live IDA `xrefs_to 0x004751c0` proved shared use from article-list, normal new-article, predefined-form, and transfer-reply alert paths. A class parent would be false; `BoardDialogs` is the correct direct owner at the current documentation granularity.
- B001-025 also repairs the earlier BoardList gates: [UID:0002EJ][0x00472070-0x004729dd.BoardListDialogCore](by-memory/0x00472070-0x004729dd.BoardListDialogCore.md) and [UID:0002V9][0x004729e0-0x00472bf5.BoardListPaneCore](by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md) are both now `85/88`, and their class parents [UID:00000Z][BoardListDialog](by-class/BoardListDialog.md) and [UID:000010][BoardListPane](by-class/BoardListPane.md) are both now `85/88`.
- The deleting-destructor wrappers for `ArticleDialog`, `ArticleListDialog`, `BulletinDialog`/shared board/article dialogs, and `NewPredefinedFormArticleDialog` share [UID:00003S][DialogInSession](by-class/DialogInSession.md) non-deleting base cleanup at `0x004a1450`; recovered labels that call it `ArticleDialog::~ArticleDialog` are owner pollution. B001-025 exact non-emitting companion pages now cover [UID:00033N][0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor](by-memory/0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor.md), [UID:00033O][0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor](by-memory/0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor.md), and [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md).
- The small transfer/delete alert wrappers can stay private to board/article dialog sources or move to [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md). Do not trust the active `TransferReplyPredefinedAlert` body without IDA verification.
- The 2026-05-26 IDA recheck gives [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md) the same callee set as `TransferReplyAlert::OnConfirm`, so model it as article-navigation acknowledgement unless a later IDA-backed pass proves otherwise.

## Score Rationale

Completion remains `85` because this file page now has exact child coverage for the board-list dialog/pane, article-list dialog/pane, shared article-navigation helper island, article viewer, normal new-article composer, predefined-form article module, alert companions, vtable families, destructor companions, and web-board cross-references. Confidence remains `86` because the child pages are live IDA-backed and the source bucket has a valid `NexusTK/ui/dialogs/` path. The score remains below final because the exact original split between `BoardDialogs.cpp`, `ArticleDialogs.cpp`, `BulletinDialogs.cpp`, and web-board/alert companion files is still unresolved, and several raw helper bodies still have no direct xrefs.

## Cross-References

- [UID:00001C][BulletinDialog](by-class/BulletinDialog.md)
- [UID:0000ZI][0x00472000-0x0047203a.BulletinDialogRawConstructor](by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md)
- [UID:0001X5][BulletinDialogVtables](by-type/by-vtable/BulletinDialogVtables.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md)
- [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md)
- [UID:00001D][BulletinSession](by-class/BulletinSession.md)
- [UID:0000HX][BulletinSession](by-file/BulletinSession.md)
- [UID:00000Z][BoardListDialog](by-class/BoardListDialog.md)
- [UID:000010][BoardListPane](by-class/BoardListPane.md)
- [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md)
- [UID:00000L][ArticleListPane](by-class/ArticleListPane.md)
- [UID:0000KT][ListPane](by-file/ListPane.md)
- [UID:00000J][ArticleDialog](by-class/ArticleDialog.md)
- [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md)
- [UID:000098][NewPredefinedFormArticleDialog](by-class/NewPredefinedFormArticleDialog.md)
- [UID:0000F5][TransferReplyAlert](by-class/TransferReplyAlert.md)
- [UID:0000F6][TransferReplyPredefinedAlert](by-class/TransferReplyPredefinedAlert.md)
- [UID:0000ZN][0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction](by-memory/0x004790a0-0x0047910f.TransferReplyPredefinedAlertOnAlertAction.md)
- [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md)
- [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md)
- [UID:000033][ConfirmDeleteAlert](by-class/ConfirmDeleteAlert.md)
- [UID:00003O][DeleteReplyAlert](by-class/DeleteReplyAlert.md)
- [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md)
- [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md)
- [UID:0000HW][BulletinReplyAlerts](by-file/BulletinReplyAlerts.md)
- [UID:0000ZH][0x00471150-0x00471ff1.BulletinSessionCore](by-memory/0x00471150-0x00471ff1.BulletinSessionCore.md)
- [UID:000132][0x004a0f40-0x004a14a7.BulletinSessionDialogStack](by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:0002EJ][0x00472070-0x004729dd.BoardListDialogCore](by-memory/0x00472070-0x004729dd.BoardListDialogCore.md)
- [UID:0002V9][0x004729e0-0x00472bf5.BoardListPaneCore](by-memory/0x004729e0-0x00472bf5.BoardListPaneCore.md)
- [UID:00030G][0x00472c00-0x004748ea.ArticleListDialogCore](by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md)
- [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md)
- [UID:00030H][0x004751c0-0x004753df.ArticleNavigationHelpers](by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md)
- [UID:00030J][0x004753e0-0x00476c0a.ArticleDialogCore](by-memory/0x004753e0-0x00476c0a.ArticleDialogCore.md)
- [UID:00030K][0x00476c10-0x00477790.NewArticleDialogCore](by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md)
- [UID:00033N][0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor](by-memory/0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor.md)
- [UID:00033O][0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor](by-memory/0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor.md)
- [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md)
- [UID:0000ZL][0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog](by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md)
- [UID:0000ZM][0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions](by-memory/0x00478fe0-0x0047ec6b.BulletinMailAlertCompanions.md)
- [UID:0000Z7][0x0046d050-0x0046d324.WebBoardDialog](by-memory/0x0046d050-0x0046d324.WebBoardDialog.md)
- [UID:0000Z9][0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse](by-memory/0x0046d580-0x0046da63.WebBoardDialogHandleBoardResponse.md)
- [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md)
- [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md)
- [UID:0000ZB][0x0046e640-0x0046e8be.WebBoardDialogOldConstructor](by-memory/0x0046e640-0x0046e8be.WebBoardDialogOldConstructor.md)
- [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md)
- [UID:000213][0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper](by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md)
- [UID:0000ZD][0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse](by-memory/0x0046eaa0-0x0046ee7a.WebBoardDialogOldHandleBoardResponse.md)
- [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md)
- [UID:0001RT][webboard-dialog-resources](by-resource/webboard-dialog-resources.md)
- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md)

## Changes

- What existed before: the page had extensive board/article/web-board module evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `80/84`.
- Summary and evidence: board/article dialog ownership is strongly supported by many IDA-confirmed ranges, vtables, and source grouping notes; confidence remains below 100 because the web-board split, raw constructor starts, and alert companion placement still need final migration decisions.
- 2026-06-02: Assigned projected reconstruction path `NexusTK/ui/dialogs/` and raised scores to `82/85`. This lets confirmed board/article child layout pages attach to a stable file-owner bucket while preserving the documented caveat that the exact original file split remains unresolved.
- 2026-05-27: The web-board rows previously summarized active `WebBoardDialog` as `0x0046d050-0x0046da63` and `WebBoardDialogOld` as `0x0046e2a0-0x0046ee7a`. Updated them to include the newly documented helper coverage: active URL escape/render helpers through `0x0046e25b`, and the raw old-dialog teardown-like helper at `0x0046e260-0x0046e294`. Evidence is in [UID:000210][0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers](by-memory/0x0046da70-0x0046e294.WebBoardDialogRenderEscapeAndOldTeardownHelpers.md).
- 2026-05-27: The `WebBoardDialogOld` row previously omitted raw helper `0x0046e4c0-0x0046e63c`. Added it after IDA MCP confirmed it as a mode/control rectangle helper with switch-table bytes before the old constructor; evidence is in [UID:000211][0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper](by-memory/0x0046e4c0-0x0046e63c.WebBoardDialogOldModeRectHelper.md).
- 2026-05-27: The `WebBoardDialogOld` row previously left destructor/callback coverage between the old constructor and packet forwarder implicit. Added `0x0046e8c0-0x0046e9f5` after IDA MCP confirmed the destructor and old browser-control close/reposition callbacks; evidence is in [UID:000212][0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks](by-memory/0x0046e8c0-0x0046e9f5.WebBoardDialogOldDestructionAndMouseCallbacks.md).
- 2026-05-27: The `WebBoardDialogOld` row previously left the packet-forwarder/response gap undocumented. Added raw helper `0x0046ea30-0x0046ea99` after IDA MCP confirmed it sends the initial opcode `0x73` request and starts timer `0x572`; evidence is in [UID:000213][0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper](by-memory/0x0046ea30-0x0046ea99.WebBoardDialogOldInitialRequestHelper.md).
- 2026-05-27: The `WebBoardDialogOld` row previously left `0x0046ee7a-0x0046efe0` undocumented. Added raw helper `0x0046ee80-0x0046efda` after IDA MCP confirmed it initializes the old URL escape table and percent-encodes old board-info/cookie data; evidence is in [UID:000214][0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper](by-memory/0x0046ee80-0x0046efda.WebBoardDialogOldUrlEscapeHelper.md).
- 2026-05-27: The `TransferReplyAlert` row previously listed only projected constructor start `0x00478f90`. Updated it to raw constructor range [UID:00021A][0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor](by-memory/0x00478f90-0x00478fd8.TransferReplyAlertRawConstructor.md). Evidence: IDA raw disassembly confirms constructor-shaped code, `0x0049feb0` helper call, optional-pop flag store, and three `TransferReplyAlert` vtable stores.
- 2026-06-03: Updated the `ConfirmDeleteAlert` row from the old projected-constructor/action-endpoint wording to exact constructor child [UID:0002US][0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor](by-memory/0x0047e100-0x0047e158.ConfirmDeleteAlertRawConstructor.md) and exact action child [UID:0002SE][0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest](by-memory/0x0047e160-0x0047e2e4.ConfirmDeleteAlertSendDeleteRequest.md). Evidence: restarted IDA MCP raw-disassembly pass on 2026-06-03.
- 2026-06-06 provenance/report sync:
  - Before: the status and ownership notes still described recovered/staged output as authoritative evidence, and the by-file coverage row still reported `80%` despite this page's `82/85` header.
  - Changed to: IDA/by-* documentation basis, recovered-output caveat wording, and a matching `82%` coverage row.
  - Evidence: the same linked vtable-family, by-memory range, and alert-helper pages support the owner bucket; no scores, path, ownership, or final C++ were changed.
- 2026-06-08 A008 Batch 107:
  - Before: `COMPLETION:82`, `CONFIDENCE:85`, with the article-list/viewer/compose half of [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md) still represented mostly by class-level summaries.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:86`.
  - Summary/evidence: exact child pages now cover ArticleListDialog, ArticleListPane, article-navigation helpers, ArticleDialog, and NewArticleDialog, with live IDA-modeled bounds, raw helper spans, callers/callees, and padding evidence. This also makes the direct file parent gate valid for [UID:00001C][BulletinDialog](by-class/BulletinDialog.md) and [UID:0000ZI][0x00472000-0x0047203a.BulletinDialogRawConstructor](by-memory/0x00472000-0x0047203a.BulletinDialogRawConstructor.md).
- 2026-06-08 A008 Batch 107 continuation:
  - Before: the file page recorded the exact child split but not the follow-up direct class assignment decisions.
  - Changed to: added ownership-note routing for the four assigned class-owned children and the shared [UID:00030H][0x004751c0-0x004753df.ArticleNavigationHelpers](by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md) no-assignment decision.
  - Summary/evidence: live IDA rechecked constructor caller and vtable-store evidence for the four class-owned children, while `xrefs_to 0x004751c0` proved the navigation helper is shared across article-list, normal new-article, predefined-form, and transfer-reply alert paths.
- 2026-06-10 B001-025:
  - Before: the file page still treated [UID:00030H][0x004751c0-0x004753df.ArticleNavigationHelpers](by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md) as unassigned, and the BoardListDialog/BoardListPane direct parent gates were still `78/88`.
  - Changed to: documented [UID:00030H][0x004751c0-0x004753df.ArticleNavigationHelpers](by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md) as a file-level shared helper child, raised the board-list class/child gates to `85/88`, and linked exact non-emitting destructor companions [UID:00033N][0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor](by-memory/0x0047e950-0x0047e98b.ArticleDialogScalarDeletingDestructor.md), [UID:00033O][0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor](by-memory/0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor.md), and [UID:00033P][0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor](by-memory/0x0047ea10-0x0047ea4b.BulletinDialogSharedScalarDeletingDestructor.md).
  - Summary/evidence: B001 IDA MCP re-audit confirmed `0x004751c0` cross-owner callers, raw helper packet subcommands, exact board-list child boundaries, and destructor wrapper xrefs/behavior. Scores remain `85/86` because final original file partitioning is still unresolved.
