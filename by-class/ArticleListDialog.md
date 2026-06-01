*** UID:00000K | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ArticleListDialog

## Status

- Confidence: strong for behavior and board-dialog module placement.
- Likely source file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Address range: [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md), with destructor companion at `0x0047e990-0x0047e9ca`
- Current recovered file: `source-3/simroot_v2/class_ArticleListDialog.cpp`

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
| `ScalarDeletingDestructor` | `0x0047e990-0x0047e9ca` | Runs [UID:00003S][DialogInSession](by-class/DialogInSession.md) base cleanup at `0x004a1450` and optionally frees storage. |

## Evidence Notes

- Wave3 summary identifies this as the dialog for listing bulletin-board articles.
- IDA MCP confirms the constructor, read request, command routing, server-message, list-update, and destructor boundaries.
- The destructor wrapper belongs to this class, but the non-deleting base cleanup target is shared [UID:00003S][DialogInSession](by-class/DialogInSession.md) code, not ArticleDialog-owned code.
- The article-list dialog and pane are tightly adjacent in memory, supporting a shared `BoardDialogs.cpp` or `ArticleDialogs.cpp` source file.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:00000L][ArticleListPane](by-class/ArticleListPane.md)
- [UID:00000J][ArticleDialog](by-class/ArticleDialog.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md)

## Changes

- What existed before: the page documented methods and cross-references but still had unevaluated completion/confidence metadata.
- What it was changed to: scores were set to `76/88`, and class-shape notes were added for owned controls, packet role, and source placement.
- Summary and evidence: the board article memory cluster, BoardDialogs file page, and IDA-confirmed constructor/read-command/server-message/list-update boundaries make the class purpose and ownership strong; completion remains moderate because exact member offsets and final C++ bodies are not fully reconstructed.
