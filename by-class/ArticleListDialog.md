*** UID:00000K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000HT | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ArticleListDialog

## Status

- Confidence: strong for behavior and board-dialog module placement.
- Likely source file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Address range: exact core child [UID:00030G][0x00472c00-0x004748ea.ArticleListDialogCore](by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md), with non-emitting destructor companion [UID:00033O][0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor](by-memory/0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor.md)

## Autogen Status

- Parent file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md).
- Reconstructable: true.
- Final C++ remains blank because packet/list-entry field names, raw-helper reachability, and final `BoardDialogs.cpp` versus `ArticleDialogs.cpp` source placement are not source-final.
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
| `ArticleListDialog` | `0x00472ca0-0x0047398c` | Builds article-list dialog and parses initial list packet. |
| `SendReadArticlePacket` | `0x004739b0-0x00473a95` | Requests the selected article body. |
| `SendNavigatePagePacket` | `0x00473dc0-0x00473dfb` | Sends page navigation request. |
| `OnControlCommand` | `0x00473e00-0x00473ff2` | Dispatches list, button, paging, and close commands. |
| `WriteNewArticle` | `0x00474020-0x004740c0` | Opens or initiates new article composition. |
| `UpdateButtonStates` | `0x00474170-0x0047422c` | Enables/disables article actions based on selection and page state. |
| `OnServerMessage` | `0x00474230-0x00474460` | Routes server board/article replies. |
| `HandleArticleListUpdate` | `0x00474470-0x004746ab` | Parses refreshed article list entries and repopulates the list pane. |
| `ShowAlertAndRefreshList` | `0x004746b0-0x004747ca` | Displays server alert text and refreshes list state. |
| adjustor thunks | [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | Compiler-generated secondary/tertiary deleting-destructor thunks; ignore for handwritten source. |
| `ScalarDeletingDestructor` | [UID:00033O][0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor](by-memory/0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor.md) | Non-emitting MSVC wrapper that runs [UID:00003S][DialogInSession](by-class/DialogInSession.md) base cleanup at `0x004a1450` and optionally frees storage. |

## Evidence Notes

- IDA MCP confirms the constructor, read request, command routing, server-message, list-update, and destructor boundaries.
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md) is scored `85/86`, stages the board/article dialog bucket under `NexusTK/ui/dialogs/`, and lists `ArticleListDialog` as the article-entry list dialog handling read/write/delete/page requests plus list updates and alerts.
- [UID:00030G][0x00472c00-0x004748ea.ArticleListDialogCore](by-memory/0x00472c00-0x004748ea.ArticleListDialogCore.md) now records the exact article-list-dialog method/helper cluster, including raw helper islands, modeled function bounds, constructor callers from [UID:00001D][BulletinSession](by-class/BulletinSession.md), and the owned [UID:00000L][ArticleListPane](by-class/ArticleListPane.md) construction call sites.
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md) keeps the aggregate board/article range as a non-emitting split inventory, while [UID:00033O][0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor](by-memory/0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor.md) owns the exact scalar deleting destructor companion documentation.
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md) records `ArticleListDialog` primary/secondary/tertiary vtable bases `0x00613dac`, `0x00613e10`, and `0x00613e40`, with constructor stores at `0x00472cfd`, `0x00472d03`, and `0x00472d0d`.
- Batch 107 continuation rechecked live IDA ownership evidence: `callers 0x00472ca0` returns `0x00471695` and `0x004719e1` from `BulletinSession`; `xrefs_to 0x00613dac` returns the primary vtable store at `0x00472cfd` inside `sub_472CA0`; `callees 0x00472ca0` includes the adjacent [UID:00030I][0x004748f0-0x004751b1.ArticleListPaneCore](by-memory/0x004748f0-0x004751b1.ArticleListPaneCore.md) constructor.
- 2026-06-10 B001-025 created exact non-emitting destructor companion [UID:00033O][0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor](by-memory/0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor.md); IDA reports adjustor-thunk refs, `ArticleListDialog` vtable/data ref `0x00613dac`, the `DialogInSession` cleanup call, and scalar-delete conditional free.
- The destructor wrapper belongs to this class, but the non-deleting base cleanup target is shared [UID:00003S][DialogInSession](by-class/DialogInSession.md) code, not ArticleDialog-owned code.
- The article-list dialog and pane are tightly adjacent in memory, supporting a shared `BoardDialogs.cpp` or `ArticleDialogs.cpp` source file.

## Score Rationale

Completion is raised to `85` because the class now has a stable parent file bucket, an exact core child page, confirmed method inventory, article-list pane/control relationship, destructor companion ownership, board/article aggregate context, and vtable-family evidence. Confidence stays `88` because identity and behavior are strongly supported, but final C++ remains gated on packet/list-entry field names, raw helper reachability, and the final article-source split.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:00000L][ArticleListPane](by-class/ArticleListPane.md)
- [UID:00000J][ArticleDialog](by-class/ArticleDialog.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md)
- [UID:00033O][0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor](by-memory/0x0047e990-0x0047e9cb.ArticleListDialogScalarDeletingDestructor.md)

## Changes

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
