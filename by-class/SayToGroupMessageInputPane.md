*** UID:0000C4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SayToGroupMessageInputPane

## Status

- Confidence: strong for behavior; medium for final file placement.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) or [UID:0000JS][Group](by-file/Group.md)
- Address range: [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md)
- Current recovered file: `source-3/simroot_v2/class_SayToGroupMessageInputPane.cpp`

## Class Purpose

`SayToGroupMessageInputPane` is the group-chat line input pane. It stores the destination group name, prompts with `Group => `, validates and sanitizes the wide input text, converts group name and message to multibyte strings, and sends an opcode `0x19` packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SayToGroupMessageInputPane` | `0x005b1ec0-0x005b1f7d` | Initializes line input, stores group name, and sets prompt text. |
| `SendGroupMessage` | `0x005b1f80-0x005b2152` | Builds and sends length-prefixed group-name and message payload. |

## Evidence Notes

- IDA MCP confirms both function starts.
- `SendGroupMessage` is referenced through a vtable data offset, not by a direct call xref.
- Behavior is group-specific, but address locality places it with the broader `Say*InputPane` family.

## Cross-References

- [UID:0000JS][Group](by-file/Group.md)
- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md)
- [UID:00005W][GroupInputPane](by-class/GroupInputPane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `74/78`.
  - Before: The page was unevaluated despite documenting constructor behavior, message payload construction, and file-placement ambiguity.
  - After: Scored as moderate-high completion and confidence because group-message behavior is strong while final source grouping remains open.
  - Evidence: Existing method notes, IDA MCP function-start evidence, vtable-reference note, and group/say input cross-references support the score.
