*** UID:00000L | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ArticleListPane

## Status

- Confidence: strong for core board article-list behavior; shared list-helper ownership belongs to [UID:00007A][ListPane](by-class/ListPane.md).
- Likely source file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Address range: [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_ArticleListPane.cpp`

## Class Purpose

`ArticleListPane` renders and manages bulletin-board article rows. It stores article IDs, titles, dates, and author columns; inserts entries with duplicate detection and sorting behavior; finds selected entries; and paints list rows.

## Class Shape

- Base family: specialized [UID:00007A][ListPane](by-class/ListPane.md) renderer/selector for bulletin-board article rows.
- Row state: tracks article identifiers and display columns for title, date, author, and related status fields.
- Owner dependency: used by [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md) for selection, activation, and redraw behavior.
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
| `InsertOrReplaceEntryText` | `0x00488680-0x0048873d` | Distant helper for row text update. |
| `InsertItem` | `0x004f3c00-0x004f3c4a` | Shared [UID:00007A][ListPane](by-class/ListPane.md) insertion helper currently emitted under `ArticleListPane`. |
| `RemoveItems` | `0x004f3d60-0x004f3db6` | Shared [UID:00007A][ListPane](by-class/ListPane.md) removal helper currently emitted under `ArticleListPane`. |
| `SetSortEnabled` | `0x004f3dd0-0x004f3e1b` | Misnamed shared [UID:00007A][ListPane](by-class/ListPane.md) selection-mode helper; not article sort ownership. |
| `GetSelectedIndices` | `0x004f3e80-0x004f3ef6` | Shared [UID:00007A][ListPane](by-class/ListPane.md) selected-index helper currently emitted under `ArticleListPane`. |
| adjustor thunks | [UID:0000ZP][0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks](by-memory/0x0047e855-0x0047e947.DialogAndAlertDestructorAdjustorThunks.md) | Compiler-generated secondary/tertiary deleting-destructor thunks into the `0x0047e9d0` destructor target; ignore for handwritten source. |

## Evidence Notes

- Wave3 summary identifies article-list columns and descending-ID insertion behavior.
- IDA MCP confirms the core constructor, add-entry, paint, and `0x004f3c00+` helper boundaries.
- The `0x004f3c00+` helpers are now documented as shared [UID:00007A][ListPane](by-class/ListPane.md) infrastructure. IDA caller fanout spans board, clan, exchange, item/menu, spell, phone-book, and user-list code, so they should not move into board/article source files.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:00007A][ListPane](by-class/ListPane.md)
- [wave3_data_issues](../wave3_data_issues.md)
- [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md)

## Changes

- What existed before: the page documented article-list methods and the shared-helper caveat but remained scored as unevaluated.
- What it was changed to: scores were set to `72/84`, and class-shape notes were added for `ListPane` specialization, row state, owner dependency, and helper ownership.
- Summary and evidence: the core constructor/add/find/paint methods and board article memory cluster give strong behavioral confidence; completion stays moderate because final row structure fields and ownership of distant helpers need fuller reconstruction.
