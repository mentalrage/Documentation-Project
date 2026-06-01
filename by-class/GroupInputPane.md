*** UID:00005W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GroupInputPane

## Status

- Confidence: strong for submit behavior; medium for constructor boundary.
- Likely source file: [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), with feature cross-reference to [UID:0000JS][Group](by-file/Group.md)
- Address range: [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md)
- Vtable family: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_GroupInputPane.cpp`

## Class Purpose

`GroupInputPane` is a line-input prompt for group-related commands. It reads wide text, clears the input buffer, converts the text to multibyte, and sends a length-prefixed group command packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GroupInputPane` | `0x005b5400` | Wave3 projected constructor; IDA does not recognize this as a function start. |
| `OnConfirmInput` | `0x005b5440-0x005b5547` | Sends opcode `0x2e` with a length-prefixed converted text payload. |

## Evidence Notes

- IDA MCP confirms `0x005b5440` and reports no function at `0x005b5400`.
- IDA MCP confirms three `GroupInputPane` vtable views at `0x006300d4`, `0x00630124`, and `0x00630154`, with stores from the command dispatcher/open helper and raw constructor-shaped bytes.
- Wave3 generated source shows use of `LineInputPane`, `InputBuffer::Clear`, `WideCharToMultiByte`, and `g_packetSender`.
- Final placement is likely command/social input code, not item dialogs.

## Cross-References

- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0000JS][Group](by-file/Group.md)
- [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md)
- [UID:0000AO][PostInputPane](by-class/PostInputPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `68/76`. Summary: group command input behavior, submit packet format, constructor boundary caveat, vtable evidence, and source placement are documented, but constructor reachability remains medium-confidence. Evidence: `0x005b5440-0x005b5547` memory page, IDA no-function note at `0x005b5400`, vtable family documentation, and command/group cross-references.
