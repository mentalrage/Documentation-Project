*** UID:00000L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID00000L ArticleListPane class-level source is covered by UID0000HT BoardDialogs and UID00030I ArticleListPaneCore. This page emits no standalone partial class declaration until ArticleListPane, ArticleListEntry, ListPane, render, and packet declarations are synchronized.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ArticleListPane

## Status

- Confidence: strong for board article-list pane ownership, constructor/vtable evidence, core row behavior, MCP-backed recovery of the raw helper bodies in [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md), `m_boardId`, and `m_pageRequestPending` polarity; shared list-helper ownership belongs to [UID:00007A][ListPane](by-class/ListPane.md).
- Likely source file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Address range: exact core child [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md)
- Autogen parent: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), position `50`.
- Current recovered file: `source-3/simroot_v2/class_ArticleListPane.cpp`

## Class Purpose

`ArticleListPane` renders and manages bulletin-board article rows. It stores article IDs, status/type bytes, month/day date columns, titles, and author columns; inserts entries with duplicate detection and sorted article-id behavior; finds selected entries; dispatches article activation to the owning dialog; and paints list rows.

## Class Shape

- Base family: specialized [UID:00007A][ListPane](by-class/ListPane.md) renderer/selector for bulletin-board article rows.
- Row state: tracks a `0x406`-byte `ArticleListEntry` record with article id, neutral status byte, month/day date bytes, reserved padding, title text, and author text.
- Pane fields: `this + 0x14c` is `m_boardId`, passed in from [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md) and serialized by selected read/subcmd7/delete/page-request helpers; `this + 0x14e` is best modeled as `m_pageRequestPending` / `m_nextPageRequestPending`, where `0` means no request pending and lazy page request is allowed, while `1` means an older-page request has been queued and further automatic page requests are suppressed until the parser/list refresh clears it.
- Owner dependency: used by [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md) for selection, activation, and redraw behavior.
- Vtable layout: [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) records primary table `0x00613e4c`, secondary table `0x00613ed4`, tertiary table `0x00613f04`, and constructor stores at `0x00474942`, `0x00474948`, and `0x00474952`.
- Ownership caveat: `0x004f3c00+` helpers are shared `ListPane` infrastructure and should not be treated as article-list-private source code.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ArticleListPane` | `0x004748f0-0x00474982` | Initializes article-list pane state from constructor parameter `boardId`; older `categoryId` wording is stale generated naming. |
| `AddArticleEntry` | `0x00474990-0x00474a6d` | Adds, replaces, and sorted-inserts `ArticleListEntry` rows using `statusByte`, `articleId`, `title`, `month`, `day`, and `author`. |
| `RequestSelectedArticleRead` / `SendSelectedArticleReadRequestFromPane` | `0x00474a70-0x00474b18` | Raw helper recovered by MCP `insn_query` in session `b880584f`; if a selected row exists, sends opcode `0x3b`, subcmd `3`, `m_boardId`, selected `articleId`, trailing `0`, length `7`. It is not only `MarkSelectedArticleRead` because it does not clear the row status byte. |
| `SendSelectedArticleSubcommand7Requests` | `0x00474b20-0x00474bf5` | Raw helper recovered by MCP `insn_query` in session `b880584f`; loops selected rows and sends opcode `0x3b`, subcmd `7`, `m_boardId`, `articleId`, length `6`. The packet behavior is known, but the source semantic for subcmd `7` remains unresolved. |
| `SendSelectedArticleDeleteRequests` | `0x00474c00-0x00474cd5` | Raw helper recovered by MCP `insn_query` in session `b880584f`; loops selected rows and sends opcode `0x3b`, subcmd `5`, `m_boardId`, `articleId`, length `6`. Confirm-delete flow supports delete semantics. |
| `RemoveArticleEntryById` | `0x00474ce0-0x00474d01` | Calls `FindArticleById(articleId)` and removes one row when found. |
| `RemoveSelectedArticleEntries` | `0x00474d10-0x00474d69` | Gets up to `0x100` selected indices and removes each selected row using `selectedIndex - removedCount`. |
| `RequestInitialArticlePage` / `RequestNewestArticlePage` | `0x00474d70-0x00474d96` | Requests initial/newest page through shared [UID:00030H][0x004751c0-0x004753df.ArticleNavigationHelpers](by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md) with `m_boardId`, request id `0x7fff`, and page-layout offset `-20` when `g_useEpfAssets == 1` else `-16` (values verified with `int_convert.py`). |
| `RequestOlderArticlesIfNeeded` / `RequestNextArticlePage` | `0x00474da0-0x00474df7` | End-of-list page helper; requests `lastArticleId - 1` when rows exist and the value is positive, uses `0x7fff` for an empty list, calls shared `0x004751c0`, then sets `m_pageRequestPending = 1`. |
| `SetPageRequestPending` | `0x00474e00-0x00474e0f` | Raw setter for `this + 0x14e`; supersedes older `m_pageRequestBlocked` / `m_nextPageRequestSuppressed` final-name candidates. |
| `FindArticleById` | `0x00474e10-0x00474e52` | Finds an existing article row by article ID. |
| `FindArticleInsertIndex` / `FindInsertionIndexForArticleId` | `0x00474e60-0x00474eb5` | Raw scan helper recovered by MCP `insn_query`; returns `-1` on duplicate article id, an insertion index for descending id order, or item count at end/empty. Generated `ChattingColorListPane` ownership is stale pollution. |
| `HandleInputEvent` / end-scroll request hook | `0x00474ec0-0x00474f14` | Handles pane-level selection/input event and calls `RequestOlderArticlesIfNeeded` only when `m_pageRequestPending == 0`. Exact ListPane virtual source name remains inferred. |
| `HandleKeyDown` / end-of-list key hook | `0x00474f20-0x00474f68` | Handles keyboard movement/activation and calls `RequestOlderArticlesIfNeeded` only when selected index reaches the last item and `m_pageRequestPending == 0`. Exact ListPane virtual source name remains inferred. |
| `OnArticleActivated` / `OnItemActivated` | `0x00474f70-0x00474f82` | Activation/read-selected callback that follows owner hops into [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md) read/open dispatch. The older `GetBulletinSession` label is rejected as a pure-getter interpretation. |
| `OnPaintItem` / `DrawArticleListItem` | `0x00474f90-0x004751b0` | Draws id with wide `%5d`, date with `%2d/%2d`, title at row `+0x006`, author at row `+0x206`, selection/background state, nonzero status color/background `0x0e`, and `...` truncation. |
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
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) is scored `86/87`, staged under `NexusTK/ui/dialogs/`, and lists `ArticleListPane` as part of the board/article dialog owner bucket.
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) ties the class to the board/article dialog family through the three vtable bases and constructor store xrefs.
- [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md) now records the exact constructor/helper/virtual-method cluster, raw row helper islands, constructor callers from [UID:00030G][0x00472c00-0x004748ea.ArticleListDialogCore](by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md), and the shared article-navigation helper caller.
- [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md) documents this pane as the article-list dialog's owned list control, and [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md) keeps the pane core immediately after the article-list dialog subrange.
- Batch 107 continuation rechecked live IDA ownership evidence: `callers 0x004748f0` returns `0x00472e04` and `0x00473410` inside `sub_472CA0`; `xrefs_to 0x00613e4c` returns the primary vtable store at `0x00474942` inside `sub_4748F0`; `callees 0x004748f0` stays limited to shared list-pane setup helpers `0x004f3a50` and `0x004f3dd0`.
- The `0x004f3c00+` helpers are now documented as shared [UID:00007A][ListPane](by-class/ListPane.md) infrastructure. IDA caller fanout spans board, clan, exchange, item/menu, spell, phone-book, and user-list code, so they should not move into board/article source files.
- 2026-06-10 A001 corrected the older generated-owner note for `0x00488680-0x0048873d`: live IDA MCP proves [UID:00035D][0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText](by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md) is called only from Clan packet handlers and operates on Clan child offsets `0x2514`/`0x2518`, so it is not an `ArticleListPane` method.
- 2026-06-22 B014 Rule 26 source-quality reanalysis keeps the direct class/source route unchanged and resolves several stale generated names: constructor field `categoryId` is best `m_boardId` at `+0x14c`; `0x00474f70` is an activation/read-selected callback, not a pure `GetBulletinSession`; generated disabled `ChattingColorListPane` attachments for raw helpers `0x00474a70` and `0x00474e60` are owner pollution; and the row layout is the `0x406`-byte `ArticleListEntry` detailed below.
- 2026-06-23 B001 MCP-backed source-quality implementation supersedes the earlier local PE/Capstone-only caveat. Active IDA MCP session `b880584f` confirms modeled functions at `0x004748f0`, `0x00474990`, `0x00474da0`, `0x00474e10`, `0x00474ec0`, `0x00474f20`, `0x00474f70`, and `0x00474f90`, and raw no-function helper starts at `0x00474a70`, `0x00474b20`, `0x00474c00`, `0x00474ce0`, `0x00474d10`, `0x00474d70`, `0x00474e00`, and `0x00474e60`.
- MCP `insn_query` in session `b880584f` recovers the selected read helper, selected subcmd7 helper, selected delete helper, remove-by-id helper, remove-selected helper, initial/newest page helper, pending setter, and insertion-index scan helper. MCP negative checks find zero direct `xrefs_to`, zero `code_ref`, zero `data_ref`, and zero `immediate` hits to those raw starts, preserving the no-direct-route caveat while closing the old body-recovery blocker.
- MCP `get_bytes` confirms exact `0xcc` padding at the class method island boundaries `0x004748ea-0x004748f0`, `0x00474983-0x00474990`, each raw/helper boundary inside `0x00474a6e-0x00474f90`, and `0x004751b1-0x004751c0` before shared [UID:00030H][0x004751c0-0x004753df.ArticleNavigationHelpers](by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md). The exact padding supports keeping this one `ArticleListPaneCore` child; optional raw-helper child splits are review granularity only, not a prerequisite for ownership/source placement.
- MCP route checks confirm constructor refs `0x00472e04` and `0x00473410`, add-entry refs `0x00472f96`, `0x004735a3`, and `0x00474666`, older-page refs `0x00474f08` and `0x00474f5c`, vtable entries `0x00613ec8 -> 0x00474f70`, `0x00613ecc -> 0x00474f90`, `0x00613ed8 -> 0x00474ec0`, and `0x00613edc -> 0x00474f20`, plus constructor stores for ArticleListPane vtable bases `0x00613e4c`, `0x00613ed4`, and `0x00613f04`.
- Corrected historical assumptions to preserve: `categoryId` is stale for `this + 0x14c`; `m_pageRequestBlocked` / `m_nextPageRequestSuppressed` are superseded by `m_pageRequestPending` because `0` is allowed and `1` is pending; `GetBulletinSession` is stale for `0x00474f70`; generated `ChattingColorListPane` attachments are owner pollution; generated shared `ListPane` helpers and Clan `InsertOrReplaceEntryText` are not pane-private ArticleListPane source.

## Article Row Layout

B001's 2026-06-23 accepted source-quality pass confirms each row as a `0x406`-byte `ArticleListEntry`. Decimal row size `1030` was checked as `0x406` (Verified with `int_convert.py`); the layout fits exactly with two 256-wide-character buffers after six header bytes:

| Offset | Field | Notes |
| --- | --- | --- |
| `+0x000` | `uint16 articleId` | Selected/read/navigation identifier. |
| `+0x002` | `uint8 statusByte` / `articleStatusByte` | Paint treats nonzero as color/background `0x0e`. Exact read/unread or type polarity is not proven. |
| `+0x003` | `uint8 month` | Producer-side generated `readStatus` naming is rejected because the pane paints this as a date column. |
| `+0x004` | `uint8 day` | Producer-side generated `replyFlag` naming is rejected because the pane paints this as a date column. |
| `+0x005` | `uint8 padOrReserved` | Reserved/padding byte needed for the total row size. |
| `+0x006` | `wchar_t title[256]` | Article title text. |
| `+0x206` | `wchar_t author[256]` | Author text; `author[257]` is rejected by the exact row size. |

The source-facing add-entry helper is best described as `AddArticleEntry(uint8 statusByte, uint16 articleId, const wchar_t *title, uint8 month, uint8 day, const wchar_t *author)`. The first byte should remain neutral until direct color/enum evidence recovers its polarity. `author[257]`, final `readStatus`/`isRead` polarity, and `replyFlag` for the date byte are rejected.

## Autogen Status

- Reconstructable: true, because this is NexusTK-owned source-authored board UI code that must exist in the rebuilt executable.
- Parent: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), position `50`, following the already-attached board-list dialog/pane entries while leaving room for [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md) to attach at position `40` after its own completion gate is met.
- C++: marker-only for this callback. The raw helper bodies are now recovered and future full aggregate C++ or optional exact helper splits are viable, but class/member/ListPane/render/packet declarations must be synchronized first. Partial helper-only C++ would create polluted pseudo-source by mixing recovered helper bodies with unresolved declarations and by implying the whole exact ArticleListPaneCore range is source-ready.

## DeleteReplyAlert Consumer Contracts

[UID:0004WF][0x0047e390-0x0047e4a6.DeleteReplyAlertOnPrimaryButton](by-memory/0x0047e390-0x0047e4a6.DeleteReplyAlertOnPrimaryButton.md) supplies exact, behavior-critical contracts for three ArticleListPane operations:

| Source-facing operation | Exact observed contract |
| --- | --- |
| `GetSelectedIndices(int *indices, int capacity)` | Called with a fixed local `int selectedIndices[256]` and capacity `256`; writes selected row indices and returns the selected count. |
| `RemoveItems(int index, int count)` | Called with count `1`. Multi mode passes `selectedIndices[i] - i`, compensating for each preceding removal; single mode passes the found row directly. |
| `FindArticleById(unsigned short articleId)` | Searches by the current article/reply ID and returns a row index or `-1`; removal occurs only when the result is not `-1`. |

The `- i` adjustment proves selected indices are reported in pre-removal list coordinates. It must not be optimized away or replaced with direct ascending removal. The single-ID branch refreshes its parent list dialog even when no row is found, so `FindArticleById` is a lookup rather than a mutating delete helper. These uses support realistic source names while preserving the existing ArticleListEntry layout, `m_boardId`, `m_pageRequestPending`, shared ListPane boundary, and raw-helper caveats.

## Score Rationale

- Completion rises to `88` because the page now records parent attachment, exact child coverage, vtable bases, constructor store xrefs, article-list dialog ownership, shared-helper exclusion, recovered raw helper roles, opcode `0x3b` packet behavior, `m_boardId`, `m_pageRequestPending` polarity, exact row layout, and stale generated-pollution rejections.
- Confidence rises to `88` because live IDA MCP caller-equivalent xref checks, the parent file, vtable-family page, memory aggregate, sibling dialog page, and MCP raw-body recovery agree on the `ArticleListPane` / `BoardDialogs` route and row/paging behavior.
- Confidence remains below final reconstruction quality because exact original source spellings remain inferred, opcode `0x3b` subcmd `7` semantics are not source-named, and ListPane/render/packet declarations are not yet synchronized for formal C++; MCP session `b880584f` did not provide PDB-level source names, custom type definitions, local variable names, or comments.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [wave3_data_issues](../wave3_data_issues.md)
- [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md)
- [UID:00035D][0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText](by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md)
- [UID:00030H][0x004751c0-0x004753df.ArticleNavigationHelpers](by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)

## Changes

- 2026-07-22 B005 UID0003Q0 callback: retained `88/88`; added exact `GetSelectedIndices(int *, int)` capacity/count, compaction-safe `RemoveItems(index, 1)`, and `FindArticleById(unsigned short)` row-or-`-1` consumer contracts from DeleteReplyAlert.
- What existed before: the page documented article-list methods and the shared-helper caveat but remained scored as unevaluated.
- What it was changed to: scores were set to `72/84`, and class-shape notes were added for `ListPane` specialization, row state, owner dependency, and helper ownership.
- Summary and evidence: the core constructor/add/find/paint methods and board article memory cluster give strong behavioral confidence; completion stays moderate because final row structure fields and ownership of distant helpers need fuller reconstruction.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` re-confirmed the article-list pane constructor/add-entry/paint starts at `0x004748f0`, `0x00474990`, and `0x00474f90`, and `callers` shows construction from `ArticleListDialog`. `AUTOGEN_PARENT_UID` remains blank despite the likely [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) owner because the class completion score is still below the 80+ attachment gate.
- 2026-06-06 parent/evidence update:
  - Before: the class was reconstructable but still unattached at `72/84`, even though its likely `BoardDialogs` owner and core behavior were documented.
  - Changed to: `82/86`, parent [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) at position `50`, with vtable-store, sibling-dialog, memory-aggregate, and shared-helper boundary evidence added.
  - Evidence: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) is `82/85` and stages board/article dialogs under `NexusTK/ui/dialogs/`; [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) records `ArticleListPane` vtables at `0x00613e4c`, `0x00613ed4`, and `0x00613f04` plus constructor stores at `0x00474942`, `0x00474948`, and `0x00474952`; [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md) and [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md) both keep the pane in the board article-list cluster. B009 later adds marker-only output while source body entry remains blocked by declaration synchronization.
- 2026-06-08 A008 Batch 107 continuation:
  - Before: `COMPLETION:82`, `CONFIDENCE:86`, and the page still treated the exact pane child split as incomplete.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`.
  - Summary/evidence: exact child [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md) now covers the constructor/helper/virtual-method cluster; live IDA rechecked constructor callers from `ArticleListDialog`, primary vtable-store xrefs, and the shared-list setup callees. This clears the direct class-parent side for the child while preserving row-layout and raw-helper caveats.
- 2026-06-10 A001 stale-owner correction:
  - What existed before: the method table listed `InsertOrReplaceEntryText` at `0x00488680-0x0048873d` as a distant article-list helper.
  - Changed to: removed that method row and linked [UID:00035D][0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText](by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md) as the corrected Clan owner.
  - Summary/evidence: live IDA callers for `0x00488680` are `0x00487b56` and `0x0048807b` inside Clan packet handlers, and no board/article callers were found.
- 2026-06-22 B014 Rule 26 source-quality incorporation:
  - Score and owner/emitter unchanged at `85/87`, [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), and `EMITTER_UIDS:0000HT`.
  - Added the exact `ArticleListEntry` row layout, `m_boardId`/`+0x14c`, `+0x14e` page-request guard note, corrected activation callback naming for `0x00474f70`, rejected generated `categoryId`/`GetBulletinSession`/date-byte labels, and preserved the raw-helper C++ blocker.
- 2026-06-23 B001 accepted MCP-backed implementation callback:
  - Before: `COMPLETION:85`, `CONFIDENCE:87`; owner/emitter [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md); formal source body blocked pending raw helper recovery.
  - After: `COMPLETION:88`, `CONFIDENCE:88`; owner/emitter unchanged; B009 later adds marker-only output by accepted no-partial-C++ proof.
  - Summary/evidence: synchronized this class page with [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md): active IDA MCP session `b880584f` recovered raw helper bodies, no-direct-route results for raw starts, exact padding support, `m_boardId`, `m_pageRequestPending` polarity, helper source-facing names, opcode `0x3b` selected read/subcmd7/delete/page-request behavior, activation/read-selected route, stale `categoryId`/`GetBulletinSession`/`ChattingColorListPane` rejections, optional split guidance, score rationale, and no-code rationale requiring synchronized declarations before any full aggregate or split child C++.
