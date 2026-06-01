*** UID:0000C7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SayToUserNameInputPane

## Status

- Confidence: strong for behavior and IDA boundaries.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- Address range: [UID:0001MD][0x005b3cb0-0x005b4219.SayToUserNameInputPane](by-memory/0x005b3cb0-0x005b4219.SayToUserNameInputPane.md)
- Current recovered file: `source-3/simroot_v2/class_SayToUserNameInputPane.cpp`

## Class Purpose

`SayToUserNameInputPane` prompts for a direct-message recipient name. It preloads recent recipient history, sets the recipient prompt according to the modern/legacy whisper flow flag, and opens either `NewSayToUserMessageInputPane` or the legacy `SayToUserMessageInputPane` after confirmation.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SayToUserNameInputPane` | `0x005b3cb0-0x005b3e7f` | Initializes prompt, history indices, and prefilled recipient text. |
| `OnRecipientNameConfirmed` | `0x005b4080-0x005b4219` | Stores recipient history and opens modern or legacy message input. |

## Evidence Notes

- IDA MCP confirms both function starts.
- Constructor callers include `NewSayToUserMessageInputPane::HandleKeyInput` and the mode-opening flow.
- `OnRecipientNameConfirmed` is vtable-referenced at `0x0062fcbc`.

## Cross-References

- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0001MD][0x005b3cb0-0x005b4219.SayToUserNameInputPane](by-memory/0x005b3cb0-0x005b4219.SayToUserNameInputPane.md)
- [UID:0000C6][SayToUserMessageInputPane](by-class/SayToUserMessageInputPane.md)
- [UID:000099][NewSayToUserMessageInputPane](by-class/NewSayToUserMessageInputPane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `80/86`.
  - Before: The page was unevaluated despite documenting recipient prompt behavior, recent history preload, modern/legacy flow dispatch, and vtable/caller evidence.
  - After: Scored as high completion and strong confidence for the recipient-name input pane.
  - Evidence: Existing method notes, IDA MCP boundary evidence, constructor caller notes, vtable-reference note, and direct-message pane cross-references support the score.
