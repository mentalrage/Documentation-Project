*** UID:000085 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MessageDialog

## Status

- Confidence: strong for ownership and boundaries; generated source is not migration-ready.
- Likely source file: [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- Main address range: [UID:0001FH][0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs](by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md)
- Current recovered file: `source-3/simroot_v2/class_MessageDialog.cpp`

## Class Purpose

`MessageDialog` is the normal NPC/system message dialog. It parses packet data for a message type, object descriptor, optional text body, layout flags, and navigation button state, then builds `DialogPane` controls for the background, object image, text, and previous/next/current buttons.

## Method Map

| Address | Method | Role |
| --- | --- | --- |
| `0x0054ce10-0x0054db3e` | `MessageDialog::MessageDialog(uint8_t* packet, char compactLayout)` | Packet parser and dialog/control builder. |
| `0x0054db40-0x0054db8b` | `OnDialogAction(int actionId)` | Sends previous, next, or current dialog packets and closes the dialog. |

## Evidence Notes

- Wave3 grades the class at effective `98.0`.
- IDA MCP confirms both functions as exact starts.
- Older Wave2 report notes direct callers from the packet-driven dialog dispatch path around `0x0054c200`.
- Current generated source contains placeholder `...` expressions for packet offsets/resource arguments; rely on IDA/Wave2/Wave3 metadata for boundaries and behavior until the emitted source is fixed.
- 2026-05-25 IDA decompilation resolves the key omitted packet offsets: the constructor reads message type from `packet[0]`, object id from `packet+1`, a display/object flag from `packet[5]`, parses the variable object descriptor at `packet+6`, then reads the two state words at `packet + descriptorLength + 10` and `packet + descriptorLength + 12`.
- In the text-bearing branch, IDA reads the text byte length at `packet + descriptorLength + 16`, copies bytes from `packet + descriptorLength + 18`, converts them through `MultiByteToWideChar`, and builds the text control. Current `simroot_v2/class_MessageDialog.cpp` still emits omitted placeholder comments for these offsets.

## Cross-References

- [UID:0000LA][MessageDialogs](by-file/MessageDialogs.md)
- [UID:000086][MessageDialogLarger](by-class/MessageDialogLarger.md)
- [UID:00007X][MenuQuestionDialog](by-class/MenuQuestionDialog.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `80/82`. Summary: the normal packet-driven message dialog has strong ownership, exact boundaries, constructor/action behavior, packet offset details, and generated-source caveats documented, but source migration remains blocked by placeholder expressions in current output. Evidence: linked NPC message/menu-question range, IDA-confirmed starts, packet dispatch callers, 2026-05-25 offset decompilation notes, and `simroot_v2` placeholder caveat.
