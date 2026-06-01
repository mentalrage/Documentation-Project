*** UID:00007Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MenuQuestionDialogLarger

## Status

- Confidence: strong for ownership and IDA boundaries; generated source is incomplete.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Main address range: [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_MenuQuestionDialogLarger.cpp`

## Class Purpose

`MenuQuestionDialogLarger` is the larger-layout variant of the menu-question dialog. It shares the same packet response model as `MenuQuestionDialog`, using action 1 for selection submission and actions 2-4 for previous/next/current navigation.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0054fb30-0x00550afb` | `MenuQuestionDialogLarger::MenuQuestionDialogLarger(...)` | Larger menu-question packet parser and control builder. Wave3 lists and grades the method, but current emitted source omits the body. |
| `0x00550b00-0x00550c30` | `OnButtonAction(int action)` | Serializes opcode `0x3a` selection replies or sends previous/next/current packets, then closes the dialog. |
| `0x00550c40-0x00550c7d` | `UpdateButtonState()` | Enables/disables confirm button based on the list pane's enabled-entry count. |

## Evidence Notes

- Wave3 grades the class at effective `98.3`.
- IDA MCP confirms all three functions as exact starts, including the missing constructor body at `0x0054fb30`.
- Constructor xrefs come from the same `0x0054c200` dialog-packet dispatch area as the other message/question dialog variants.
- The missing emitted constructor is tracked in [wave3_data_issues](../wave3_data_issues.md) and the shared [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md) note.
- 2026-05-25 IDA recheck: constructor callers are `0x0054c2fa`/`0x0054c339` in `HandleDialogPacket_54C200` plus wrapper paths at `0x0054c795` and `0x0054c855`.
- IDA decompilation shows the omitted constructor still follows the same packet header pattern as the smaller message/question dialogs: type at `packet[0]`, object id at `packet+1`, object descriptor at `packet+6`, two state words after the descriptor, item text copied through `MultiByteToWideChar`, allocation of `MenuQuestionItemListLarger`, and larger-layout backgrounds such as `DLGMSG4.EPD`, `DLGMSG3B.EPD`, and `DLGMSG31.EPD`.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:00007X][MenuQuestionDialog](by-class/MenuQuestionDialog.md)
- [UID:000080][MenuQuestionItemListLarger](by-class/MenuQuestionItemListLarger.md)
- [UID:0000VD][ScopedMarkerMissingMethodBodies](by-item/ScopedMarkerMissingMethodBodies.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the larger menu-question variant has strong boundary and packet/layout evidence, but completion is limited by the current emitted source omitting the constructor body. Evidence: IDA-confirmed constructor/action/update starts, constructor caller xrefs, decompiled packet/header/layout pattern, larger asset names, and linked missing-body tracking.
