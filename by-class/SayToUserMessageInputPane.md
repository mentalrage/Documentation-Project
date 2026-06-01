*** UID:0000C6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SayToUserMessageInputPane

## Status

- Confidence: strong for behavior; medium for legacy-vs-modern final placement.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- Address range: [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_SayToUserMessageInputPane.cpp`

## Class Purpose

`SayToUserMessageInputPane` is the legacy direct-message input pane for a selected recipient. It stores the recipient name, formats a prompt like `-> name: `, validates/sanitizes entered text, converts recipient and message text to multibyte strings, and sends opcode `0x19`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SayToUserMessageInputPane` | `0x005b1570-0x005b1630` | Initializes line input, stores recipient name, and sets the prompt. |
| `OnSubmit` | `0x005b1640-0x005b1812` | Sends opcode `0x19` with recipient and message payload. |

## Evidence Notes

- IDA MCP confirms both function starts.
- `SayToUserNameInputPane::OnRecipientNameConfirmed` opens this class only when `g_useModernWhisperFlow` is false.
- Modern flow uses [UID:000099][NewSayToUserMessageInputPane](by-class/NewSayToUserMessageInputPane.md).

## Cross-References

- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md)
- [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md)
- [UID:000099][NewSayToUserMessageInputPane](by-class/NewSayToUserMessageInputPane.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `74/78`.
  - Before: The page was unevaluated despite documenting legacy direct-message construction, prompt behavior, and opcode `0x19` payload.
  - After: Scored as moderate-high completion and confidence because behavior is clear while legacy-vs-modern placement remains a source-layout caveat.
  - Evidence: Existing method notes, IDA MCP start evidence, modern/legacy flow note, and cross-references to recipient-name and modern direct-message panes support the score.
