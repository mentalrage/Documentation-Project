*** UID:00000K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// UID00000K ArticleListDialog class-level source is covered by UID0000HT BoardDialogs and exact ArticleListDialog method/support pages. This page emits no standalone partial class declaration until packet/list-entry fields, raw helper policy, and the board/article dialog source split are source-quality.
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ArticleListDialog

## Status

- Confidence: strong for behavior and board-dialog module placement.
- Likely source file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Address range: exact core child [UID:00030G][0x00472c00-0x004748ea.ArticleListDialogCore](by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md), with non-emitting destructor companion [UID:00033O][0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor](by-memory/0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor.md)

## Autogen Status

- Parent file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- Reconstructable: true.
- Formal output is marker-only because the recovered raw helper roles still need synchronized class/control/packet declarations, subcommand `7` source semantics, and final `BoardDialogs.cpp` versus `ArticleDialogs.cpp` source placement before a safe aggregate body can be emitted.
- Recovered class-file names are only historical search leads on the file parent; this class page now uses by-file/by-memory/by-vtable evidence for ownership.

## Class Purpose

`ArticleListDialog` lists bulletin-board articles for the selected board. It sends read, page-navigation, delete, and write-new-article requests, owns article-list controls, and handles server article-list update or alert replies.

## Class Shape

- Base family: board/article `BulletinDialog` descendant in the `DialogInSession` stack.
- Owned controls: creates and coordinates [UID:00000L][ArticleListPane](by-class/ArticleListPane.md) plus paging/action buttons for article read, write, delete, and navigation commands.
- Network role: serializes selected article read/page/write/delete requests and consumes server list-update or alert replies.
- Source placement: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), tightly grouped with the article-list pane and article viewer in [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SendInitialArticlePageRequest` / `RequestNewestArticlePage` | `0x00472c00-0x00472c9c` | Raw retained helper with no modeled function metadata and no direct inbound xrefs in current MCP session `supervisor_resume_20260629`; sends opcode `0x3b`, subcommand `2`, current board id, selected/newest-page sentinel `0x7fff`, EPF/legacy offset, and packet length `7` for the initial/newest article-page request. |
| `ArticleListDialog` | `0x00472ca0-0x0047398c` | Builds article-list dialog and parses initial list packet. |
| `CopyArticleDialogText` / `SetArticleListDialogText` | `0x00473990-0x004739a9` | Raw retained local setter with no direct inbound xrefs; `_wcscpy_s` copies external dialog text into the class buffer at `this+0x276`, so this is class-local state recovery rather than a separate owner. |
| `SendReadArticlePacket` | `0x004739b0-0x00473a95` | Requests the selected article body. |
| `SendSelectedArticleSubcommand7Requests` | `0x00473aa0-0x00473bbb` | Raw retained selected-row loop that sends opcode `0x3b`, subcommand `7`, board id from `+0x14c`, selected article ids, and packet length `6`; current evidence proves packet shape and dispatch route but leaves the gameplay/source meaning of subcommand `7` unresolved, capping C++ readiness. |
| `SendSelectedArticleDeleteRequests` | `0x00473bc0-0x00473cdb` | Raw retained selected-row loop that sends opcode `0x3b`, subcommand `5`, board id from `+0x14c`, selected article ids, and packet length `6` for delete requests. |
| `RemoveArticleEntryById` | `0x00473ce0-0x00473d1f` | Raw retained pane mutation helper that removes a row by article id from the owned `ArticleListPane` and refreshes list/button state. |
| `RemoveSelectedArticleEntries` | `0x00473d30-0x00473db4` | Raw retained selected-row removal helper that removes selected entries from the owned pane and refreshes the dialog. |
| `SendNavigatePagePacket` | `0x00473dc0-0x00473dfb` | Sends page navigation request. |
| `OnControlCommand` | `0x00473e00-0x00473ff2` | Dispatches list activation, read/write/delete, paging, close, and pane/control commands through the owned jump table; case routing reaches the selected-read helper, subcommand-`7` helper, selected-delete helper, and pane page-navigation path. |
| `WriteNewArticle` | `0x00474020-0x004740c0` | Opens or initiates new article composition. |
| `UpdateButtonStates` | `0x00474170-0x0047422c` | Enables/disables article actions based on selection and page state. |
| `OnServerMessage` | `0x00474230-0x00474460` | Routes server board/article replies; current analysis ties subcommand `2` to list updates and subcommands `7`/`8` to alert/refresh handling while preserving unresolved source semantics for outbound subcommand `7`. |
| `HandleArticleListUpdate` | `0x00474470-0x004746ab` | Parses refreshed article-list entries; MCP `insn_query` in session `b880584f` confirms `0x004744f5` clears the pane's `m_pageRequestPending` byte at `ArticleListPane + 0x14e` to `0` before `0x00474666` calls [UID:00000L][ArticleListPane](by-class/ArticleListPane.md) row insertion with status/type byte, article id, title, month, day, and author fields. |
| `ShowAlertAndRefreshList` | `0x004746b0-0x004747ca` | Displays server alert text and refreshes list state. |
| adjustor thunks | [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | Compiler-generated secondary/tertiary deleting-destructor thunks; ignore for handwritten source. |
| `ScalarDeletingDestructor` | [UID:00033O][0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor](by-memory/0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor.md) | Non-emitting MSVC wrapper that runs [UID:00003S][DialogInSession](by-class/DialogInSession.md) base cleanup at `0x004a1450` and optionally frees storage. |

## Evidence Notes

- IDA MCP confirms the constructor, read request, command routing, server-message, list-update, and destructor boundaries.
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) is scored `86/87`, stages the board/article dialog bucket under `NexusTK/ui/dialogs/`, and lists `ArticleListDialog` as the article-entry list dialog handling read/write/delete/page requests plus list updates and alerts.
- [UID:00030G][0x00472c00-0x004748ea.ArticleListDialogCore](by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md) now records the exact article-list-dialog method/helper cluster, including raw helper islands, modeled function bounds, constructor callers from [UID:00001D][BulletinSession](by-class/BulletinSession.md), and the owned [UID:00000L][ArticleListPane](by-class/ArticleListPane.md) construction call sites.
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md) keeps the aggregate board/article range as a non-emitting split inventory, while [UID:00033O][0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor](by-memory/0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor.md) owns the exact scalar deleting destructor companion documentation.
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) records `ArticleListDialog` primary/secondary/tertiary vtable bases `0x00613dac`, `0x00613e10`, and `0x00613e40`, with constructor stores at `0x00472cfd`, `0x00472d03`, and `0x00472d0d`.
- B006's 2026-06-27 source-quality implementation records that this class consumes [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) through the secondary view at `0x00613e10 + 0x10`: slot `0x00613e20` stores `0x00472040`. This is one consumer slot of the shared command-`'1'` secondary bridge, not an ArticleListDialog-owned method body; class-level output is marker-only until the common secondary interface, event/action type, and primary `+0x5c` dispatch declaration are source-quality.
- Batch 107 continuation rechecked live IDA ownership evidence: `callers 0x00472ca0` returns `0x00471695` and `0x004719e1` from `BulletinSession`; `xrefs_to 0x00613dac` returns the primary vtable store at `0x00472cfd` inside `sub_472CA0`; `callees 0x00472ca0` includes the adjacent [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md) constructor.
- 2026-06-10 B001-025 created exact non-emitting destructor companion [UID:00033O][0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor](by-memory/0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor.md); IDA reports adjustor-thunk refs, `ArticleListDialog` vtable/data ref `0x00613dac`, the `DialogInSession` cleanup call, and scalar-delete conditional free.
- The destructor wrapper belongs to this class, but the non-deleting base cleanup target is shared [UID:00003S][DialogInSession](by-class/DialogInSession.md) code, not ArticleDialog-owned code.
- The article-list dialog and pane are tightly adjacent in memory, supporting a shared `BoardDialogs.cpp` or `ArticleDialogs.cpp` source file.
- 2026-06-22 B014 Rule 26 source-quality reanalysis of [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md) clarifies this dialog's producer-side row order: the parser supplies a neutral status/type byte, article id, title text, month byte, day byte, and author text to the pane. Generated names that label the month/day bytes as `readStatus`/`replyFlag` are stale because the pane paints those fields as date columns.
- 2026-06-23 B001 accepted MCP-backed source-quality implementation of [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md) adds the narrow producer-side pending-state cross-reference: MCP `insn_query` in session `b880584f` confirms this parser/list-update path clears `ArticleListPane + 0x14e` to `0`, while the pane older-page helper sets it to `1` after queueing a request. That supports the source-facing field name `m_pageRequestPending` with `0` allowed / not pending and `1` pending / suppress further automatic requests until refreshed.
- 2026-07-02 B003 current MCP implementation callback for [UID:00030G][0x00472c00-0x004748ea.ArticleListDialogCore](by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md) uses active session `supervisor_resume_20260629` against IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, with auto-analysis and Hex-Rays ready. `lookup_funcs` confirms modeled bodies at `0x00472ca0`, `0x004739b0`, `0x00473dc0`, `0x00473e00`, `0x00474020`, `0x00474170`, `0x00474230`, `0x00474470`, `0x004746b0`, and `0x004747d0`, while raw starts `0x00472c00`, `0x00473990`, `0x00473aa0`, `0x00473bc0`, `0x00473ce0`, and `0x00473d30` are not IDA functions and have zero direct inbound code/data/immediate refs. Raw disassembly still recovers their roles as article-page request, dialog-text copy, selected subcommand-`7` request loop, selected delete request loop, remove-by-id, and remove-selected helper bodies.
- The same B003 pass rechecked constructor and class evidence: `callers 0x00472ca0` returns `0x00471695` and `0x004719e1` from [UID:00001D][BulletinSession](by-class/BulletinSession.md), `xrefs_to 0x00613dac` identifies the primary vtable store at `0x00472cfd`, and constructor callees include the adjacent [UID:00000L][ArticleListPane](by-class/ArticleListPane.md) constructor. `analyze_function` on `0x00474230`, `0x00474470`, and `0x004746b0` confirms server-message routing, list parser fields, pending-byte clear, and alert-refresh flow; `xrefs_to 0x004751c0` still reports seven refs across article-list, normal new-article, predefined-form, and transfer-reply alert paths, so [UID:00030H][0x004751c0-0x004753df.ArticleNavigationHelpers](by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md) remains a shared file-level helper, not an `ArticleListDialog` child.

## Article Row Producer Notes

The list-update parser at `0x00474470` produces row data consumed by [UID:00000L][ArticleListPane](by-class/ArticleListPane.md). Keep ownership with this dialog for the packet parser and with the pane for row insertion/rendering:

- The first per-row byte remains `statusByte` / `articleStatusByte` until direct color/enum evidence proves read/unread or type polarity.
- The article id is a 16-bit row identifier used by selected-read/navigation paths.
- The two bytes passed after title text are best named `month` and `day`; `readStatus` and `replyFlag` are rejected generated names for those positions.
- The pane-side row record is `0x406` bytes: six header bytes followed by `wchar_t title[256]` and `wchar_t author[256]`.
- The board id passed into [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md) should be treated as `boardId`, not `categoryId`.
- MCP `insn_query` in session `b880584f` confirms the parser clears the pane's `m_pageRequestPending` byte at `+0x14e` before adding received rows; the pane sets the same byte to `1` after requesting an older page. This dialog-side write is producer evidence for the accepted polarity rather than a separate ownership claim.

## DeleteReplyAlert Consumer Contract

[UID:0004WF][0x0047e390-0x0047e4a6.DeleteReplyAlertOnPrimaryButton](by-memory/0x0047e390-0x0047e4a6.DeleteReplyAlertOnPrimaryButton.md) confirms two source-facing ArticleListDialog roles in both reply-deletion modes:

- `GetArticleListPane()` returns the owned [UID:00000L][ArticleListPane](by-class/ArticleListPane.md), consistent with the existing child-ID-7 lookup/construction evidence.
- `RefreshContents()` is the virtual `+0x4c` refresh operation invoked after selected-row or single-ID reconciliation.

Multi mode receives the current ArticleListDialog directly through `AlertPane::m_layoutReference`. Single mode resolves the preceding ArticleListDialog through `DialogSession::FindPreviousDialog(currentDialog)`. Both paths refresh after list mutation; single mode also refreshes when the ID was not found. These exact uses refine helper names without changing BoardDialogs ownership, existing pane layout, packet/list-entry evidence, or remaining class-level source caveats.

## Source-Quality Notes

- The old broad blocker that the raw helper islands were not understood is superseded for UID00030G: current raw disassembly and packet/control tracing recover the helper roles and packet shapes listed above.
- The no-direct-route evidence is still important but does not mean dead code. These are retained class-local helper islands adjacent to modeled `ArticleListDialog` bodies, reached through control/virtual/inline-shaped routing that IDA did not model as direct function calls.
- Ownership and split alternatives were rechecked and rejected for this pass: the helper island should not be split into `ArticleListPane`, [UID:00030H][0x004751c0-0x004753df.ArticleNavigationHelpers](by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md), or a new file because the constructor, vtable stores, board id state, selected-row requests, parser, alert refresh, and pane mutation all remain class-local to `ArticleListDialog`.
- Formal class output remains marker-only. A safe aggregate body still needs synchronized class fields, control ids, packet helpers, `ArticleListPane` member declarations, alert constructor declarations, and the source meaning of subcommand `7`. The unresolved subcommand `7` item is evidence-backed current-pass uncertainty with score and C++ impact, not a generic future-work note.

## Score Rationale

Completion remains `85` and confidence remains `88` for the class support page because B003 resolves the UID00030G raw helper roles and raises the exact child to `88/89`, but class-level declarations are still not source-complete enough for a formal aggregate body. The remaining cap is declaration/source-shape work across packet helpers, control ids, pane member declarations, alert constructors, final `BoardDialogs.cpp` versus `ArticleDialogs.cpp` placement, and unresolved subcommand `7` semantics; owner, emitter, and reconstructable status stay unchanged.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:00000L][ArticleListPane](by-class/ArticleListPane.md)
- [UID:00000J][ArticleDialog](by-class/ArticleDialog.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md)
- [UID:00033O][0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor](by-memory/0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor.md)

## Changes

- 2026-07-22 B005 UID0003Q0 callback: retained `85/88`; documented exact DeleteReplyAlert use of `GetArticleListPane()` and `RefreshContents()`, including direct-current versus previous-dialog contexts and unconditional single-mode refresh.
- 2026-07-02 B003 [UID:00030G][0x00472c00-0x004748ea.ArticleListDialogCore](by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md) implementation callback:
  - Score and owner/emitter unchanged at `85/88`, [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), and `EMITTER_UIDS:0000HT`.
  - Added current MCP session `supervisor_resume_20260629`, recovered raw helper roles, no-direct-route negative evidence, constructor/vtable/pane evidence, parser/dispatcher/alert facts, shared [UID:00030H][0x004751c0-0x004753df.ArticleNavigationHelpers](by-memory/0x004751c0-0x004753df.ArticleNavigationHelpers.md) separation, rejected split/source-placement alternatives, and the marker-only/no-partial-C++ proof. Preserved subcommand `7` as evidence-backed unresolved with score and C++ impact.
- 2026-06-27 B006 [UID:0000ZJ][0x00472040-0x00472069.BoardDialogCommandOneVirtual](by-memory/0x00472040-0x00472069.BoardDialogCommandOneVirtual.md) support sync:
  - Score and owner/emitter unchanged at `85/88`, [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), and `EMITTER_UIDS:0000HT`.
  - Added the secondary `0x00613e10 + 0x10 -> 0x00613e20 -> 0x00472040` consumer-slot note, preserving class-level C++ blankness and the shared-interface/source-split caveat.
- What existed before: the page documented methods and cross-references but still had unevaluated completion/confidence metadata.
- What it was changed to: scores were set to `76/88`, and class-shape notes were added for owned controls, packet role, and source placement.
- Summary and evidence: the board article memory cluster, BoardDialogs file page, and IDA-confirmed constructor/read-command/server-message/list-update boundaries make the class purpose and ownership strong; completion remains moderate because exact member offsets and final C++ bodies are not fully reconstructed.
- 2026-06-05: Reclassified autogen metadata from unclassified to `RECONSTRUCTABLE:TRUE`. Current IDA MCP `lookup_funcs` re-confirmed the constructor, read request, command router, server-message, and list-update starts at `0x00472ca0`, `0x004739b0`, `0x00473e00`, `0x00474230`, and `0x00474470`, and `callers` shows the constructor is reached by nearby board-session code. `AUTOGEN_PARENT_UID` remains blank despite the likely [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) owner because the class completion score is still below the 80+ attachment gate.
- 2026-06-07:
  - Before: score stayed at `76/88`, `AUTOGEN_PARENT_UID` was blank, and status still named the recovered class file as current context.
  - After: raised completion to `80`, attached parent [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), removed generated-source dependency, and added autogen-status/evidence/score-rationale sections.
  - Summary/evidence: the file parent, board/article aggregate, and board/article vtable-family page now provide durable ownership evidence while the article-list-dialog core still needs exact child splits and packet/list-entry field naming.
- 2026-06-08 A008 Batch 107 continuation:
  - Before: `COMPLETION:80`, `CONFIDENCE:88`, and the page still treated the exact child split as pending.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:88`.
  - Summary/evidence: exact child [UID:00030G][0x00472c00-0x004748ea.ArticleListDialogCore](by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md) now covers the method/helper cluster; live IDA rechecked `BulletinSession` constructor callers, the primary vtable store, and owned `ArticleListPane` construction call sites. This makes the class a valid direct parent for the child under the strict `85/85` gate while keeping final C++ blank.
- 2026-06-10 B001-025:
  - Changed: replaced the raw destructor range note with exact non-emitting companion [UID:00033O][0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor](by-memory/0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor.md).
  - Summary/evidence: IDA MCP confirms the wrapper's bounds, `DialogInSession` destructor call, scalar-delete free logic, adjustor-thunk refs, and `ArticleListDialog` vtable ref.
- 2026-06-22 B014 Rule 26 source-quality incorporation:
  - Score and owner/emitter unchanged at `85/88`, [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), and `EMITTER_UIDS:0000HT`.
  - Added producer-side article row field order and corrected the generated month/day naming that affected [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md).
- 2026-06-23 B001 accepted MCP-backed implementation callback:
  - Score and owner/emitter unchanged at `85/88`, [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), and `EMITTER_UIDS:0000HT`.
  - Added the narrow MCP `b880584f` cross-reference that `HandleArticleListUpdate` clears the pane `m_pageRequestPending` byte at `+0x14e`, supporting the accepted `0` allowed / `1` pending polarity documented on [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md).
