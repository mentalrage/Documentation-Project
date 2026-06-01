*** UID:000010 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BoardListPane

## Status

- Confidence: strong for behavior and board-dialog module placement.
- Likely source file: [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- Address range: [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_BoardListPane.cpp`

## Class Purpose

`BoardListPane` is the list-pane component used by `BoardListDialog`. It renders available board rows and forwards double-click activation into the owning board dialog/session flow.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `OnItemDoubleClick` | `0x00472b50-0x00472b62` | Activates the selected board item. |
| `DrawItem` | `0x00472b70-0x00472bf4` | Draws one board-list row. |

## Evidence Notes

- Wave3 summary identifies this as the pane displaying available message boards.
- IDA MCP confirms the compact pane methods at `0x00472b50` and `0x00472b70`.
- The class has no standalone source-module evidence; it should migrate with board dialogs unless later caller evidence proves a larger generic list-pane owner.

## Cross-References

- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)
- [UID:0001X4][BoardArticleDialogVtableFamily](by-type/by-vtable/BoardArticleDialogVtableFamily.md)
- [UID:0000ZK][0x00472070-0x00477790.BoardArticleDialogs](by-memory/0x00472070-0x00477790.BoardArticleDialogs.md)
- [UID:00000Z][BoardListDialog](by-class/BoardListDialog.md)

## Changes

- What existed before: the page identified the pane role, two compact methods, and board-dialog ownership, but metadata still read `0/0`.
- What it was changed to: scores were set to `70/84`.
- Summary and evidence: the compact method set and BoardDialogs references support high confidence for identity and placement; remaining completion work is mostly final layout/header detail and confirming there is no broader reusable list-pane owner.
