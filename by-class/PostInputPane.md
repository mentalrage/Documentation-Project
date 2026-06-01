*** UID:0000AO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# PostInputPane

## Status

- Confidence: strong for behavior and command-input module placement.
- Likely source file: [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- Address range: [UID:0001MK][0x005b5630-0x005b5830.PostInputPane](by-memory/0x005b5630-0x005b5830.PostInputPane.md)
- Vtable family: [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- Current recovered file: `source-3/simroot_v2/class_PostInputPane.cpp`

## Class Purpose

`PostInputPane` is a single-letter post selection prompt. It formats a prompt with the player name, accepts a letter mapped to a post index, validates it against the local player limit, and sends a post command packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `PostInputPane` | `0x005b5630-0x005b56f7` | Constructs prompt with player name and installs vtables. |
| `OnKeyInput` | `0x005b5700-0x005b576c` | Handles help-panel shortcut. |
| `OnConfirmInput` | `0x005b5770-0x005b5830` | Converts letter to post index and sends opcode `0x34`. |

## Evidence Notes

- IDA MCP confirms all three function starts.
- IDA MCP confirms three `PostInputPane` vtable views at `0x00630160`, `0x006301b0`, and `0x006301e0`, with stores from the command dispatcher/open helper and the constructor.
- Wave3 generated source shows the same slot-letter pattern used by item action panes, but the packet domain is post/message command routing.

## Cross-References

- [UID:0000ID][CommandInputPanes](by-file/CommandInputPanes.md)
- [UID:0001XA][CommandInputPaneVtableFamily](by-type/by-vtable/CommandInputPaneVtableFamily.md)
- [UID:0001MK][0x005b5630-0x005b5830.PostInputPane](by-memory/0x005b5630-0x005b5830.PostInputPane.md)
- [UID:00005W][GroupInputPane](by-class/GroupInputPane.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already documented class purpose, three method starts, vtable views, packet opcode, and command-input placement.
- Changed to: `COMPLETION:72` and `CONFIDENCE:84`.
- Evidence: constructor, help shortcut, confirm/post packet behavior, vtable family, and command-input module ownership are documented; remaining gaps are detailed local field layout and reconstructed C++.
