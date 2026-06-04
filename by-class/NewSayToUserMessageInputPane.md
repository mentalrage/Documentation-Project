*** UID:000099 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewSayToUserMessageInputPane

## Status

- Confidence: strong for behavior, boundaries, vtables, caller flow, and modern-vs-legacy direct-message relationship.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- Address range: [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md)

## Class Purpose

`NewSayToUserMessageInputPane` is the modern direct-message/whisper input pane. It stores a recipient name, prompts with `To <name> : `, sends opcode `0x19`, and lets backspace on an empty field return to `SayToUserNameInputPane`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewSayToUserMessageInputPane` | `0x005b1990-0x005b1a50` | Initializes line input, vtables, recipient buffer, and prompt. |
| `OnSubmitInput` | `0x005b1a60-0x005b1c32` | Sends opcode `0x19` with recipient and message payload. |
| `HandleKeyInput` | `0x005b1c40-0x005b1d42` | Handles empty-backspace return to recipient name entry; otherwise delegates to base input. |
| adjustor thunks | `0x005b7820`, `0x005b782b` | Destructor/vtable adjustor thunks. |
| scalar deleting destructor | `0x005b7af0-0x005b7b2b` | Destroys base line input and conditionally frees memory. |

## Evidence Notes

- Live IDA MCP on 2026-06-04 confirms the current executable as `NexusTK.exe` MD5 `4247e04e20b65d6414c7238aa8ff5515` / SHA-256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- IDA function boundaries are exact for the constructor `0x005b1990-0x005b1a51`, submit handler `0x005b1a60-0x005b1c32`, key handler `0x005b1c40-0x005b1d42`, adjustor thunks `0x005b7820-0x005b782b` and `0x005b782b-0x005b7836`, and scalar deleting destructor `0x005b7af0-0x005b7b2b`.
- `CodeRefsTo(0x005b1990)` reports constructor callers at `0x00554e0a`, `0x0059edc6`, `0x005a51e9`, `0x005a5544`, and `0x005b4128`; the last call is the return-to-name flow from [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md).
- The constructor installs three `NewSayToUserMessageInputPane` vtables at `0x0062f788`, `0x0062f7d8`, and `0x0062f808`, copies the recipient into the `+0x108` buffer, and uses prompt string `To %s : ` at `0x00630a30`.
- `OnSubmitInput` is vtable-referenced at `0x0062f7d0`; it pushes opcode `0x19` at `0x005b1b27`, converts the recipient and message through two `WideCharToMultiByte` calls, appends both length-prefixed fields through the packet helpers, and sends through `dword_67A7EC`.
- The legacy [UID:0000C6][SayToUserMessageInputPane](by-class/SayToUserMessageInputPane.md) submit path at `0x005b1640` has the same opcode `0x19`, packet-helper call set, two `WideCharToMultiByte` conversions, and `dword_67A7EC` send path; the class distinction is the separate constructor/vtable/prompt family, not a different packet protocol.
- `HandleKeyInput` is vtable-referenced at `0x0062f7e0`; its direct calls include `sub_5B3CB0` at `0x005b1d0b` for recipient-name pane construction and `sub_4F25A0` at `0x005b1d29` for base key handling. It also reads whisper-mode globals `dword_67ADE0` and `dword_67ADD8` during the empty-backspace return path.

## Cross-References

- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md)
- [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md)
- [UID:0000C6][SayToUserMessageInputPane](by-class/SayToUserMessageInputPane.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already documented class role, method boundaries, caller evidence, globals, and related panes.
- Changed to: `COMPLETION:74` and `CONFIDENCE:76`.
- Evidence: the page covers constructor, submit, key-input, destructor support, whisper globals, and caller flow; confidence remains medium because the exact relationship to the legacy direct-message pane still needs a comparison pass.
- 2026-06-04: Raised completion from `74` to `84` and confidence from `76` to `88` after live IDA MCP comparison against the legacy direct-message pane.
  - Before: the page had only summarized start evidence and left the modern-vs-legacy relationship as medium confidence.
  - After: the page records exact function boundaries, constructor callers, vtable refs, prompt string, submit opcode/callee set, modern key-handler return-to-name path, and the specific equivalence/difference between modern and legacy direct-message submit behavior.
  - Evidence: live disassembly confirms `sub_5B1990`, `sub_5B1A60`, `sub_5B1C40`, `sub_5B7820`, `sub_5B782B`, and `sub_5B7AF0`; `CodeRefsTo(0x005b1990)` has five constructor callers; `0x0062f7d0` and `0x0062f7e0` reference the submit/key vtable slots; modern and legacy submit both push opcode `0x19` and share the packet-helper/WideCharToMultiByte/send path while using separate constructors, prompts, and vtables.
