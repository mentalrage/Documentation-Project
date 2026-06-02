*** UID:0000C3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SayInputPane

## Status

- Confidence: strong for confirmed submit/history behavior, vtable identity, constructor bytes, and social-source placement; medium-high for exact source-level helper names.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- Address range: [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md)
- Current recovered file: `source-3/simroot_v2/class_SayInputPane.cpp`

## Class Purpose

`SayInputPane` is the default local chat/say input pane. It owns chat history navigation for up/down keys and sends opcode `0x0e`, subtype `0`, after normalizing text and saving it to user chat history.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SayInputPane` | [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md) | Raw default constructor-shaped body; IDA reports this is not a function. |
| `SayInputPane(const wchar_t*)` | `0x005b34d0-0x005b356c` | Constructs a prompt-backed line input, initializes vtables/history index, and inserts the supplied initial text. |
| `HandleKeyInput` | `0x005b3570-0x005b3670` | Handles previous/next chat history navigation before delegating other keys to base line input. |
| `OnSubmitChat` | `0x005b3670-0x005b37ea` | Builds and sends opcode `0x0e`, subtype `0` say chat packet. |
| scalar deleting destructor | `0x005b7b80-0x005b7bba` | Destroys base line input and conditionally frees memory. |

## Evidence Notes

- 2026-06-02 IDA MCP confirms `0x005b34d0-0x005b356c`, `0x005b3570-0x005b3670`, `0x005b3670-0x005b37ea`, and `0x005b7b80-0x005b7bbb`.
- 2026-06-02 IDA MCP reports no function at `0x005b3490`, but raw disassembly proves [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md) as the default constructor body.
- 2026-06-02 IDA vtable/data-ref evidence places key input at `0x0062fbb4 -> 0x005b3570`, submit at `0x0062fba4 -> 0x005b3670`, and destructor slot refs to `0x005b7b80`.
- The constructors write primary `0x0062fb5c`, secondary `0x0062fbac`, and tertiary `0x0062fbdc` vtable views and initialize the history cursor sentinel at `this+0x108`.
- The submit function mirrors [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md) behavior but uses default say subtype `0`.

## Reconstruction Notes

This class is reconstructable and attached to [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md). Leave C++ blank until the edit-control field names, history helper names, and final source split with adjacent chat input code are final-source quality.

## Cross-References

- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md)
- [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md)
- [UID:00001Q][ChatInputPane](by-class/ChatInputPane.md)
- [UID:0000D5][ShoutInputPane](by-class/ShoutInputPane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `78/78`.
  - Before: The page was unevaluated despite documenting local chat behavior, history navigation, submit packet shape, and the default-constructor caveat.
  - After: Scored as moderate-high completion and confidence because submit/history behavior is confirmed while the projected default constructor remains unresolved.
  - Evidence: Existing method notes, IDA MCP evidence notes, opcode/subtype behavior, and chat/shout cross-references support the score.
- 2026-06-02 raw-constructor and parent update:
  - Before: the class was not reconstructable/attached and still treated the default constructor as an unresolved projected start.
  - After: raised to `82/84`, marked reconstructable, attached to [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md), and linked the exact raw constructor child [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md).
  - Evidence: current IDA function-boundary, raw constructor, vtable/data-ref, and callee checks for the constructor/key/submit/destructor family.
