*** UID:000099 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewSayToUserMessageInputPane

## Status

- Confidence: strong for behavior; medium for exact relationship to legacy direct-message pane.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- Address range: [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_NewSayToUserMessageInputPane.cpp`

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

- IDA MCP confirms all listed function starts.
- The constructor is called by `SayToPlanMessageInputPane::OpenInputPaneForCurrentMode`, `SayToPlanMessageInputPane::OpenWhisperToLastRecipient`, `SayToUserNameInputPane::OnRecipientNameConfirmed`, and `HandleKeyInput` return-to-name flow.
- The class uses `g_pWhisperState` and `g_pWhisperHandler` when backing out of modern whisper mode.

## Cross-References

- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md)
- [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md)
- [UID:0000C6][SayToUserMessageInputPane](by-class/SayToUserMessageInputPane.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already documented class role, method boundaries, caller evidence, globals, and related panes.
- Changed to: `COMPLETION:74` and `CONFIDENCE:76`.
- Evidence: the page covers constructor, submit, key-input, destructor support, whisper globals, and caller flow; confidence remains medium because the exact relationship to the legacy direct-message pane still needs a comparison pass.
