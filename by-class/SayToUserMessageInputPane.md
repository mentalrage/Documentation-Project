*** UID:0000C6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SayToUserMessageInputPane

## Status

- Confidence: strong for behavior, boundaries, vtables, caller flow, and legacy-vs-modern direct-message relationship.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- Address range: [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md)
- Autogen parent: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) as the shared social input-pane owner.

## Class Purpose

`SayToUserMessageInputPane` is the legacy direct-message input pane for a selected recipient. It stores the recipient name, formats a prompt like `-> name: `, validates/sanitizes entered text, converts recipient and message text to multibyte strings, and sends opcode `0x19`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SayToUserMessageInputPane` | `0x005b1570-0x005b1630` | Initializes line input, stores recipient name, and sets the prompt. |
| `OnSubmit` | `0x005b1640-0x005b1812` | Sends opcode `0x19` with recipient and message payload. |
| adjustor thunks | `0x005b7820`, `0x005b782b` | Secondary/tertiary interface destructor adjustors shared by the target-message input family. |
| scalar deleting destructor | `0x005b7af0-0x005b7b2b` | Destroys the base line input and conditionally frees storage. |

## Evidence Notes

- 2026-06-04 live IDA MCP identity: `NexusTK.exe` at base `0x400000`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Function lookup confirms exact starts and sizes for the constructor `0x005b1570` size `0xc1`, submit handler `0x005b1640` size `0x1d2`, adjustor thunks `0x005b7820` and `0x005b782b` size `0xb` each, and scalar deleting destructor `0x005b7af0` size `0x3b`; `0x005b1812` is not a function start.
- The constructor calls the base line-input initializer, writes `SayToUserMessageInputPane` vtables at offsets `0`, `0xa0`, and `0xa4`, copies the recipient into the `+0x108` buffer, and formats the prompt string `-> %s: `.
- The submit method checks for positive input length, fetches and sanitizes the wide message text, writes opcode `0x19`, converts the stored recipient and current message through `WideCharToMultiByte`, appends both length-prefixed fields, and sends through `dword_67A7EC`.
- Vtable data confirms primary table `??_7SayToUserMessageInputPane@@6B@` at `0x0062f6fc`, secondary table `0x0062f74c`, and tertiary table `0x0062f77c`; the submit override is the primary-table slot `0x0062f744 -> 0x005b1640`.
- Direct construction evidence includes a code caller at `0x0059edf7` in `sub_59ED60` and an inline legacy construction branch in `SayToUserNameInputPane::OnRecipientNameConfirmed` at `0x005b419b-0x005b41f9`; the latter runs only when the modern whisper-flow flag is false, while the modern branch calls [UID:000099][NewSayToUserMessageInputPane](by-class/NewSayToUserMessageInputPane.md) at `0x005b4128`.
- The legacy and modern direct-message panes share opcode `0x19`, packet-helper calls, two text conversions, and send path; their class distinction is the constructor/vtable/prompt/key-flow family, not a different network protocol.

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
- 2026-06-04:
  - Before: scored as `74/78`, with no reconstructable flag, no autogen parent, stale source-output wording, and only summarized start evidence.
  - After: scored as `84/88`, marked `RECONSTRUCTABLE:TRUE`, and parented to [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md).
  - Summary/evidence: live IDA MCP rechecked executable identity, exact constructor/submit/destructor-thunk boundaries, constructor body, prompt formatting, opcode `0x19` submit packet shape, packet helper callees, direct open caller, inline legacy construction branch from `SayToUserNameInputPane`, vtable/RTTI anchors, and modern-pane comparison; remaining uncertainty is source split and final private method names, so no final reconstruction C++ is emitted.
