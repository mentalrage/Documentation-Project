*** UID:0000C3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SayInputPane

## Status

- Confidence: strong for confirmed submit/history behavior; medium for default constructor boundary.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- Address range: [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md)
- Current recovered file: `source-3/simroot_v2/class_SayInputPane.cpp`

## Class Purpose

`SayInputPane` is the default local chat/say input pane. It owns chat history navigation for up/down keys and sends opcode `0x0e`, subtype `0`, after normalizing text and saving it to user chat history.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SayInputPane` | `0x005b3490` | Wave3 projected default constructor; IDA reports this is not a function. |
| `SayInputPane(const wchar_t*)` | `0x005b34d0-0x005b356b` | Constructs a prompt-backed line input and initializes vtables/history index. |
| `HandleKeyInput` | `0x005b3570-0x005b366f` | Handles previous/next chat history navigation before delegating other keys to base line input. |
| `OnSubmitChat` | `0x005b3670-0x005b37ea` | Builds and sends opcode `0x0e`, subtype `0` say chat packet. |
| scalar deleting destructor | `0x005b7b80-0x005b7bba` | Destroys base line input and conditionally frees memory. |

## Evidence Notes

- IDA MCP confirms `0x005b34d0`, `0x005b3570`, `0x005b3670`, and `0x005b7b80`.
- IDA MCP reports no function at `0x005b3490`.
- The submit function mirrors [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md) behavior but uses the default say subtype rather than chat-input history object state.

## Cross-References

- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md)
- [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md)
- [UID:0000D5][ShoutInputPane](by-class/ShoutInputPane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `78/78`.
  - Before: The page was unevaluated despite documenting local chat behavior, history navigation, submit packet shape, and the default-constructor caveat.
  - After: Scored as moderate-high completion and confidence because submit/history behavior is confirmed while the projected default constructor remains unresolved.
  - Evidence: Existing method notes, IDA MCP evidence notes, opcode/subtype behavior, and chat/shout cross-references support the score.
