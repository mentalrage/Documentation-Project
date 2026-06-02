*** UID:0000C4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SayToGroupMessageInputPane

## Status

- Confidence: strong for behavior, vtable submit evidence, and packet layout; medium-high for final file placement.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md), cross-referenced from [UID:0000JS][Group](by-file/Group.md)
- Address range: [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md)
- Current recovered file: `source-3/simroot_v2/class_SayToGroupMessageInputPane.cpp`

## Class Purpose

`SayToGroupMessageInputPane` is the group-chat line input pane. It stores the destination group name, prompts with `Group => `, validates and sanitizes the wide input text, converts group name and message to multibyte strings, and sends an opcode `0x19` packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SayToGroupMessageInputPane` | `0x005b1ec0-0x005b1f7e` | Initializes line input, stores group name, installs primary/secondary/tertiary vtables, and sets prompt text. |
| `SendGroupMessage` | `0x005b1f80-0x005b2152` | Builds and sends length-prefixed group-name and message payload. |

## Evidence Notes

- IDA MCP confirms both function starts: constructor `0x005b1ec0-0x005b1f7e` and submit method `0x005b1f80-0x005b2152`.
- `SendGroupMessage` is referenced through the vtable data slot at `0x0062f85c`, not by an ordinary direct call xref.
- Constructor decompilation stores the class vtables at offsets `+0x00`, `+0xa0`, and `+0xa4`, copies the destination group name to `this+0x108`, and sets the `Group => ` prompt.
- Submit decompilation validates/filter-sanitizes the wide message, converts group name and message to multibyte strings, writes opcode `0x19`, length-prefixes both strings, and sends through `dword_67A7EC`.
- Behavior is group-specific, but address locality and shared target-message packet shape place it with the broader `Say*InputPane` family.

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
- 2026-06-02: Attached to `SayInputPanes` and refreshed score to `78/82`.
  - Before: reconstructable/autogen metadata was blank and confidence stayed below the parent-attachment threshold.
  - After: marked reconstructable, attached to [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md), and added vtable/packet/touched-state evidence from the exact memory page.
  - Evidence: [UID:0001LZ][0x005b1ec0-0x005b2152.SayToGroupMessageInputPane](by-memory/0x005b1ec0-0x005b2152.SayToGroupMessageInputPane.md) now records refreshed IDA MCP boundary, vtable, decompile, callee, and packet-layout evidence.
