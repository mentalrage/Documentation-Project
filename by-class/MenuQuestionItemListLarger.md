*** UID:000080 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MenuQuestionItemListLarger

## Status

- Confidence: strong for support-widget ownership.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Main address range: [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_MenuQuestionItemListLarger.cpp`

## Class Purpose

`MenuQuestionItemListLarger` is the larger-layout list widget used by `MenuQuestionDialogLarger`. It wraps a `ListPane`, delegates current-item selection to its paired question list, and draws selected entries with the same highlight/background palette pattern as the normal list.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00550ed0-0x00550f1f` | `MenuQuestionItemListLarger::MenuQuestionItemListLarger(int32_t questionItemList)` | Constructs the list pane and stores the paired list pointer. |
| `0x00550f90-0x00550f9b` | `SelectCurrentItem()` | Delegates selection confirmation to the inner question item list. |
| `0x00550fa0-0x00551021` | `DrawEntry(...)` | Draws a row label from the wide string at item-data offset `+2`. |

## Evidence Notes

- Wave3 grades the class at effective `97.5`.
- IDA MCP confirms all three functions as exact starts.
- Constructor xrefs are from the larger menu-question constructor at `0x0054fb30`.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md)
- [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the larger question-list widget has clear ownership, constructor, delegated selection, row drawing, and constructor-caller evidence, but row data layout and final source-level details are not exhaustive. Evidence: linked message-dialog memory range, IDA-confirmed method starts, constructor xref from `MenuQuestionDialogLarger`, and paired-list relationship.
