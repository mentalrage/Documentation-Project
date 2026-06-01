*** UID:00007X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MenuQuestionDialog

## Status

- Confidence: strong for ownership and boundaries; constructor logic still needs cleanup review.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Main address range: [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_MenuQuestionDialog.cpp`

## Class Purpose

`MenuQuestionDialog` is the normal-layout menu-question dialog. It parses a packet containing a menu category, context object, page/index state, optional description text, and a list of selectable item labels. It builds a scrollable `MenuQuestionItemList` and sends a selection packet when the user confirms.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0054e920-0x0054f8dd` | `MenuQuestionDialog::MenuQuestionDialog(uint8_t* packet, char hasDescriptionText)` | Packet parser, item-list builder, background/object/text/button layout builder. |
| `0x0054f8e0-0x0054fa10` | `OnButtonAction(int action, int unused)` | Sends selected item reply or previous/next/current dialog packets. |
| `0x0054fa20-0x0054fa5d` | `ValidateMenuSelection()` | Enables/disables the confirm button based on enabled list-entry count. |

## Evidence Notes

- Wave3 grades the class at effective `96.3` and marks all three methods attention-needed.
- IDA MCP confirms all three functions as exact starts.
- Generated source shows two layout branches controlled by `g_useHighResLayout`, but the current comments around low/high layout are internally suspect. Treat layout labels as provisional until the branch is reviewed against assets and dimensions.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md)
- [UID:00007Z][MenuQuestionItemList](by-class/MenuQuestionItemList.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `76/82`. Summary: the normal menu-question dialog has source ownership, packet role, method boundaries, list widget relationship, and layout caveats documented, but constructor internals and high/low layout labels still need cleanup review. Evidence: linked `NpcMessageAndMenuQuestionDialogs` range, IDA-confirmed starts, Wave3 attention-needed notes, and generated layout branch caveat.
