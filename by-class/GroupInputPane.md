*** UID:00005W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000ID | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GroupInputPane

## Status

- Confidence: strong for submit behavior, raw constructor bytes, vtable stores, and command-input placement; medium for direct constructor reachability because IDA does not model `0x005b5400` as a function.
- Likely source file: [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), with feature cross-reference to [UID:0000JS][Group](by-file/Group.md)
- Address range: [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md)
- Vtable family: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_GroupInputPane.cpp`

## Class Purpose

`GroupInputPane` is a line-input prompt for group-related commands. It reads wide text, clears the input buffer, converts the text to multibyte, and sends a length-prefixed group command packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GroupInputPane` | [UID:0002SB][0x005b5400-0x005b5440.GroupInputPaneRawConstructor](by-memory/0x005b5400-0x005b5440.GroupInputPaneRawConstructor.md) | Raw constructor body; initializes the localized prompt and stores the three vtable views. |
| `OnConfirmInput` | `0x005b5440-0x005b5547` | Sends opcode `0x2e` with a length-prefixed converted text payload. |

## Evidence Notes

- IDA MCP confirms `0x005b5440-0x005b5547` as the submit method and reports no modeled function at `0x005b5400`.
- IDA MCP disassembly confirms the raw constructor body at `0x005b5400-0x005b5440`: it requests prompt id `0x2f`, calls the line-input base constructor, stores vtables `0x006300d4`, `0x00630124`, and `0x00630154`, and returns `this`.
- IDA MCP decompilation confirms submit opcode `0x2e`, line-input length/read helpers, `WideCharToMultiByte`, length-prefixed payload assembly, and send through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- Final placement is likely command/social input code, not item dialogs.

## Cross-References

- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0000JS][Group](by-file/Group.md)
- [UID:0001MJ][0x005b5440-0x005b5547.GroupInputPane](by-memory/0x005b5440-0x005b5547.GroupInputPane.md)
- [UID:0002SB][0x005b5400-0x005b5440.GroupInputPaneRawConstructor](by-memory/0x005b5400-0x005b5440.GroupInputPaneRawConstructor.md)
- [UID:0000AO][PostInputPane](by-class/PostInputPane.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `68/76`. Summary: group command input behavior, submit packet format, constructor boundary caveat, vtable evidence, and source placement are documented, but constructor reachability remains medium-confidence. Evidence: `0x005b5440-0x005b5547` memory page, IDA no-function note at `0x005b5400`, vtable family documentation, and command/group cross-references.
- 2026-06-02 IDA MCP refresh:
  - Before: the class stayed at `68/76`, reconstructable metadata was blank, and the constructor was only a projected start caveat.
  - After: raised to `80/84`, marked reconstructable, attached to [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md), and linked the raw constructor child.
  - Evidence: refreshed memory docs now record the raw constructor bytes, vtable stores, submit method decompile, packet layout, and command-input ownership.
