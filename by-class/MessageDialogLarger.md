*** UID:000086 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MessageDialogLarger

## Status

- Confidence: strong for class role and boundaries.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Main address range: [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_MessageDialogLarger.cpp`

## Class Purpose

`MessageDialogLarger` is the larger-layout variant of the packet-driven message dialog. It parses a message header and portrait/body data, builds backdrop/buttons/portrait/body controls, configures default actions, and closes after a command is handled.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0054db90-0x0054e8c7` | `MessageDialogLarger::MessageDialogLarger(unsigned char* packetData, char compactMode)` | Larger message packet parser and UI builder. |
| `0x0054e8d0-0x0054e91b` | `OnCommand(int commandId)` | Handles primary, secondary, or tertiary action and closes the dialog. |

## Evidence Notes

- Wave3 grades the class at effective `97.2`.
- IDA MCP confirms both functions as exact starts.
- Constructor xrefs come from the same packet dispatch area as `MessageDialog`, supporting same-source ownership.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:000085][MessageDialog](by-class/MessageDialog.md)
- [UID:00007Y][MenuQuestionDialogLarger](by-class/MenuQuestionDialogLarger.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `76/84`. Summary: the larger message-dialog variant has role, constructor/action boundaries, packet-layout role, and same-source ownership documented, but it lacks the deeper packet offset detail already present on the normal `MessageDialog` page. Evidence: linked NPC message/menu-question range, IDA-confirmed starts, Wave3 grade, and constructor xrefs from the shared packet dispatch area.
