*** UID:00000J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ArticleDialog

## Status

- Confidence: strong for behavior and board-dialog module placement.
- Likely source file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Address range: [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md), with deleting-destructor companion at `0x0047e950-0x0047e98a`
- Current recovered file: `source-3/simroot_v2/class_ArticleDialog.cpp`

## Class Purpose

`ArticleDialog` displays a single bulletin-board article. It supports article navigation, reply/new-article flows, delete confirmation, report or submit actions, and server response handling for article operations.

## Class Shape

- Base family: `BulletinDialog` / `DialogInSession` article-viewer dialog.
- Session dependency: operates inside the bulletin session stack and shares base cleanup through [UID:00003S][DialogInSession](by-class/DialogInSession.md).
- Network role: handles board opcode `0x3b` article-view commands, submit/report/delete-style actions, and server reply text.
- Source placement: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md), likely in an article-specific board dialog source beside [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md) and [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `ArticleDialog` | `0x004753e0-0x00476314` | Parses article data and builds the viewer/action UI. |
| `OnDialogAction` | `0x00476410-0x004765fd` | Handles next/previous, reply, delete, close, and related action commands. |
| `SubmitAction` | `0x00476740-0x00476813` | Sends an article action packet. |
| `HandleServerResponse` | `0x004768c0-0x004769eb` | Handles server operation replies and alert text. |
| adjustor thunks | [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | Compiler-generated secondary/tertiary deleting-destructor thunks; ignore for handwritten source. |
| `ScalarDeletingDestructor` | `0x0047e950-0x0047e98a` | Runs [UID:00003S][DialogInSession](by-class/DialogInSession.md) base cleanup at `0x004a1450` and optionally frees storage. |

## Evidence Notes

- Wave3 notes identify bulletin opcode `0x3b`, with navigation and network reply subcommands.
- IDA MCP confirms constructor, action dispatch, submit, server-response, and destructor boundaries.
- `0x004a1450` is [UID:00003S][DialogInSession](by-class/DialogInSession.md)'s non-deleting destructor, not an ArticleDialog-owned helper. Several board/dialog deleting destructors call it.
- The class inherits through `BulletinDialog` and should stay in the board/article dialog family rather than generic networking.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:00001C][BulletinDialog](by-class/BulletinDialog.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md)
- [UID:00008Y][NewArticleDialog](by-class/NewArticleDialog.md)

## Changes

- What existed before: the page described the main methods and evidence but remained scored as unevaluated.
- What it was changed to: scores were set to `74/86`, and class-shape notes were added for inheritance/session ownership, network role, and source placement.
- Summary and evidence: the address range, by-memory board article cluster, BoardDialogs file page, and IDA-confirmed constructor/action/server-response boundaries support strong confidence; completion remains below 100 until field layout and converted C++ bodies are fully documented.
