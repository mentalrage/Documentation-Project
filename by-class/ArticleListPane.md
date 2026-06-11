*** UID:00000L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL:50 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ArticleListPane

## Status

- Confidence: strong for board article-list pane ownership, constructor/vtable evidence, and core row behavior; shared list-helper ownership belongs to [UID:00007A][ListPane](by-class/ListPane.md).
- Likely source file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Address range: exact core child [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md)
- Autogen parent: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), position `50`.
- Current recovered file: `source-3/simroot_v2/class_ArticleListPane.cpp`

## Class Purpose

`ArticleListPane` renders and manages bulletin-board article rows. It stores article IDs, titles, dates, and author columns; inserts entries with duplicate detection and sorting behavior; finds selected entries; and paints list rows.

## Class Shape

- Base family: specialized [UID:00007A][ListPane](by-class/ListPane.md) renderer/selector for bulletin-board article rows.
- Row state: tracks article identifiers and display columns for title, date, author, and related status fields.
- Owner dependency: used by [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md) for selection, activation, and redraw behavior.
- Vtable layout: [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) records primary table `0x00613e4c`, secondary table `0x00613ed4`, tertiary table `0x00613f04`, and constructor stores at `0x00474942`, `0x00474948`, and `0x00474952`.
- Ownership caveat: `0x004f3c00+` helpers are shared `ListPane` infrastructure and should not be treated as article-list-private source code.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ArticleListPane` | `0x004748f0-0x00474982` | Initializes article-list pane state. |
| `AddArticleEntry` | `0x00474990-0x00474a6d` | Adds or inserts an article row. |
| `FindArticleById` | `0x00474e10-0x00474e52` | Finds an existing article row by article ID. |
| `HandleInputEvent` | `0x00474ec0-0x00474f14` | Handles pane-level selection/input event. |
| `HandleKeyDown` | `0x00474f20-0x00474f68` | Handles keyboard movement/activation. |
| `GetBulletinSession` | `0x00474f70-0x00474f82` | Returns the owning bulletin session pointer. |
| `OnPaintItem` | `0x00474f90-0x004751b0` | Draws article-list row text and selection state. |
| `AddArticleEntryAlt` | `0x0047a900-0x0047a9dd` | Alternate add-entry helper currently attached to this pane. |
| `FindReplyById` | `0x0047acd0-0x0047ad12` | Finds a related reply/article entry by ID. |
| `InsertItem` | `0x004f3c00-0x004f3c4a` | Shared [UID:00007A][ListPane](by-class/ListPane.md) insertion helper currently emitted under `ArticleListPane`. |
| `RemoveItems` | `0x004f3d60-0x004f3db6` | Shared [UID:00007A][ListPane](by-class/ListPane.md) removal helper currently emitted under `ArticleListPane`. |
| `SetSortEnabled` | `0x004f3dd0-0x004f3e1b` | Misnamed shared [UID:00007A][ListPane](by-class/ListPane.md) selection-mode helper; not article sort ownership. |
| `GetSelectedIndices` | `0x004f3e80-0x004f3ef6` | Shared [UID:00007A][ListPane](by-class/ListPane.md) selected-index helper currently emitted under `ArticleListPane`. |
| adjustor thunks | [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | Compiler-generated secondary/tertiary deleting-destructor thunks into the `0x0047e9d0` destructor target; ignore for handwritten source. |

## Evidence Notes

- Wave3 summary identifies article-list columns and descending-ID insertion behavior.
- IDA MCP confirms the core constructor, add-entry, paint, and `0x004f3c00+` helper boundaries.
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) is scored `85/86`, staged under `NexusTK/ui/dialogs/`, and lists `ArticleListPane` as part of the board/article dialog owner bucket.
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) ties the class to the board/article dialog family through the three vtable bases and constructor store xrefs.
- [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md) now records the exact constructor/helper/virtual-method cluster, raw row helper islands, constructor callers from [UID:00030G][0x00472c00-0x004748ea.ArticleListDialogCore](by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md), and the shared article-navigation helper caller.
- [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md) documents this pane as the article-list dialog's owned list control, and [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md) keeps the pane core immediately after the article-list dialog subrange.
- Batch 107 continuation rechecked live IDA ownership evidence: `callers 0x004748f0` returns `0x00472e04` and `0x00473410` inside `sub_472CA0`; `xrefs_to 0x00613e4c` returns the primary vtable store at `0x00474942` inside `sub_4748F0`; `callees 0x004748f0` stays limited to shared list-pane setup helpers `0x004f3a50` and `0x004f3dd0`.
- The `0x004f3c00+` helpers are now documented as shared [UID:00007A][ListPane](by-class/ListPane.md) infrastructure. IDA caller fanout spans board, clan, exchange, item/menu, spell, phone-book, and user-list code, so they should not move into board/article source files.
- 2026-06-10 A001 corrected the older generated-owner note for `0x00488680-0x0048873d`: live IDA MCP proves [UID:00035D][0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText](by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md) is called only from Clan packet handlers and operates on Clan child offsets `0x2514`/`0x2518`, so it is not an `ArticleListPane` method.

## Autogen Status

- Reconstructable: true, because this is NexusTK-owned source-authored board UI code that must exist in the rebuilt executable.
- Parent: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), position `50`, following the already-attached board-list dialog/pane entries while leaving room for [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md) to attach at position `40` after its own completion gate is met.
- C++: intentionally blank. The class is below the `95/95` final-source gate, exact row/member layout is not complete, and raw row helper reachability still needs stronger recovery before source-quality output.

## Score Rationale

- Completion rises to `85` because the page now records parent attachment, exact child coverage, vtable bases, constructor store xrefs, article-list dialog ownership, and the shared-helper exclusion boundary.
- Confidence rises modestly because live IDA caller/xref checks, the parent file, vtable-family page, memory aggregate, and sibling dialog page all agree on the `BoardDialogs` owner bucket.
- Confidence remains below final reconstruction quality because the exact row structure fields, final inherited slot names, and raw helper reachability are still incomplete.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [wave3_data_issues](../wave3_data_issues.md)
- [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md)
- [UID:00035D][0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText](by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md)

## Changes

- What existed before: the page documented article-list methods and the shared-helper caveat but remained scored as unevaluated.
- What it was changed to: scores were set to `72/84`, and class-shape notes were added for `ListPane` specialization, row state, owner dependency, and helper ownership.
- Summary and evidence: the core constructor/add/find/paint methods and board article memory cluster give strong behavioral confidence; completion stays moderate because final row structure fields and ownership of distant helpers need fuller reconstruction.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` re-confirmed the article-list pane constructor/add-entry/paint starts at `0x004748f0`, `0x00474990`, and `0x00474f90`, and `callers` shows construction from `ArticleListDialog`. `AUTOGEN_PARENT_UID` remains blank despite the likely [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) owner because the class completion score is still below the 80+ attachment gate.
- 2026-06-06 parent/evidence update:
  - Before: the class was reconstructable but still unattached at `72/84`, even though its likely `BoardDialogs` owner and core behavior were documented.
  - Changed to: `82/86`, parent [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) at position `50`, with vtable-store, sibling-dialog, memory-aggregate, and shared-helper boundary evidence added.
  - Evidence: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) is `82/85` and stages board/article dialogs under `NexusTK/ui/dialogs/`; [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) records `ArticleListPane` vtables at `0x00613e4c`, `0x00613ed4`, and `0x00613f04` plus constructor stores at `0x00474942`, `0x00474948`, and `0x00474952`; [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md) and [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md) both keep the pane in the board article-list cluster. C++ remains blank under the `95/95` gate.
- 2026-06-08 A008 Batch 107 continuation:
  - Before: `COMPLETION:82`, `CONFIDENCE:86`, and the page still treated the exact pane child split as incomplete.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`.
  - Summary/evidence: exact child [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md) now covers the constructor/helper/virtual-method cluster; live IDA rechecked constructor callers from `ArticleListDialog`, primary vtable-store xrefs, and the shared-list setup callees. This clears the direct class-parent side for the child while preserving row-layout and raw-helper caveats.
- 2026-06-10 A001 stale-owner correction:
  - What existed before: the method table listed `InsertOrReplaceEntryText` at `0x00488680-0x0048873d` as a distant article-list helper.
  - Changed to: removed that method row and linked [UID:00035D][0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText](by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md) as the corrected Clan owner.
  - Summary/evidence: live IDA callers for `0x00488680` are `0x00487b56` and `0x0048807b` inside Clan packet handlers, and no board/article callers were found.
