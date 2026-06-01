*** UID:00000Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BoardListDialog

## Status

- Confidence: strong for behavior and board-dialog module placement.
- Likely source file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Address range: [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_BoardListDialog.cpp`

## Class Purpose

`BoardListDialog` presents selectable bulletin-board categories parsed from server packet data. It creates the board-list controls, tracks the selected board, sends the board-selection request, and updates button state when selection changes.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `BoardListDialog` | `0x00472070-0x00472868` | Parses board-list packet data and builds the category-selection dialog. |
| `OnButtonCommand` | `0x00472870-0x00472897` | Dispatches simple button commands. |
| `OnConfirmSelection` | `0x004728a0-0x00472998` | Sends or advances the selected board flow. |
| `UpdateButtonState` | `0x004729a0-0x004729dc` | Enables/disables command controls based on selection state. |
| `SetTitle` | `0x0049db30-0x0049db5c` | Small title helper attached to the board-list owner by Wave3. |

## Evidence Notes

- Wave3 summary identifies this as a dialog that presents selectable board categories parsed from packet data.
- IDA MCP confirms the constructor and selection-command boundaries at `0x00472070` and `0x004728a0`.
- The `SetTitle` helper is outside the compact board/article address neighborhood, so keep it under review before making file-layout decisions from that one method alone.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:000010][BoardListPane](by-class/BoardListPane.md)
- [UID:00000K][ArticleListDialog](by-class/ArticleListDialog.md)

## Changes

- What existed before: the page documented purpose, methods, placement, and references, but completion/confidence metadata was still `0/0`.
- What it was changed to: scores were set to `70/84`.
- Summary and evidence: the page has strong BoardDialogs placement, method boundaries, and by-memory references, but it is not 100% complete because class layout, final C++ declaration, and exact field names are not fully recovered here.
