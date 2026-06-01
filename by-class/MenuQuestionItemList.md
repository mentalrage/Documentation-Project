*** UID:00007Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MenuQuestionItemList

## Status

- Confidence: strong for support-widget ownership; selection-confirm helper still needs naming review.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Main address range: [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_MenuQuestionItemList.cpp`

## Class Purpose

`MenuQuestionItemList` is a `ListPane`-derived widget used by `MenuQuestionDialog`. It stores the owner dialog pointer, displays selectable wide-string menu labels, and draws selected rows with highlight/background palette changes.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x00550d50-0x00550db4` | `MenuQuestionItemList::MenuQuestionItemList(unsigned int ownerPane)` | Constructs the list pane and installs `MenuQuestionItemList` vtables. |
| `0x00550e30-0x00550e3b` | `OnSelectionConfirmed()` | Small selection-confirm virtual helper; Wave3 still shows a decompiler-style signature. |
| `0x00550e40-0x00550ec1` | `OnPaintItem(...)` | Draws a row label from a record whose text begins at offset `+2`. |

## Evidence Notes

- Wave3 grades the class at effective `97.5`; `0x00550e30` is attention-needed with effective grade `82`.
- IDA MCP confirms all three methods as exact starts.
- Constructor xrefs are from `MenuQuestionDialog` constructors, supporting private support-widget ownership.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:00007X][MenuQuestionDialog](by-class/MenuQuestionDialog.md)
- [UID:000080][MenuQuestionItemListLarger](by-class/MenuQuestionItemListLarger.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `74/82`. Summary: the normal question-list widget has ownership, constructor, confirm helper, row drawing, and caller evidence documented, but selection-confirm naming and row record layout remain shallow. Evidence: linked message-dialog memory range, IDA-confirmed starts, constructor xrefs from `MenuQuestionDialog`, and noted decompiler-style signature caveat.
