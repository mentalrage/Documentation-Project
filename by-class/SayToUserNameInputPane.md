*** UID:0000C7 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SayToUserNameInputPane

## Status

- Confidence: strong for behavior and IDA boundaries.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- Address range: [UID:0001MD][0x005b3cb0-0x005b4219.SayToUserNameInputPane](by-memory/0x005b3cb0-0x005b4219.SayToUserNameInputPane.md)
- Autogen parent: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)

## Class Purpose

`SayToUserNameInputPane` prompts for a direct-message recipient name. It preloads recent recipient history, sets the recipient prompt according to the modern/legacy whisper flow flag, and opens either `NewSayToUserMessageInputPane` or the legacy `SayToUserMessageInputPane` after confirmation.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SayToUserNameInputPane` | `0x005b3cb0-0x005b3e7f` | Initializes prompt, history indices, and prefilled recipient text. |
| `HandleHistoryNavigation` | [UID:0001ME][0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation.md) | Secondary-vtable history-navigation handler; true range is `0x005b3e80-0x005b4072`, and the current filename is stale pending coordinated rename. |
| `OnRecipientNameConfirmed` | `0x005b4080-0x005b4219` | Stores recipient history and opens modern or legacy message input. |

## Evidence Notes

- IDA MCP confirms both function starts.
- Constructor callers include `NewSayToUserMessageInputPane::HandleKeyInput` and the mode-opening flow.
- `OnRecipientNameConfirmed` is vtable-referenced at `0x0062fcbc`.
- 2026-06-05 IDA MCP confirms the history-navigation handler at `0x005b3e80` has size `0x1f2`, ends at `0x005b4072`, has no direct code callers, and is referenced by `SayToUserNameInputPane` secondary vtable slot `0x0062fccc`.
- The history handler delegates unhandled keys to `LineInputPane::HandleKeyInput`, so `LineInputPane` is a dependency rather than the direct owner.

## Cross-References

- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0001MD][0x005b3cb0-0x005b4219.SayToUserNameInputPane](by-memory/0x005b3cb0-0x005b4219.SayToUserNameInputPane.md)
- [UID:0001ME][0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation.md)
- [UID:0000C6][SayToUserMessageInputPane](by-class/SayToUserMessageInputPane.md)
- [UID:000099][NewSayToUserMessageInputPane](by-class/NewSayToUserMessageInputPane.md)

## Changes

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and assigned parent `0000N9`.
  - Before: The direct-message recipient prompt remained unclassified in autogen coverage even though the class and parent file both met the 80/80 attach gate.
  - After: The class contributes to `SayInputPanes.cpp` as a reconstructable child without emitting final C++ yet.
  - Evidence: Live IDA MCP lookup confirms constructor `0x005b3cb0` and confirmation handler `0x005b4080`; parent [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) groups the legacy and modern direct-message input flow.

- 2026-06-05: Raised completion/confidence from `80/86` to `84/90` and corrected the history-navigation ownership.
  - Before: the class method map only listed the constructor and confirmation handler, while the `0x005b3e80` history-navigation handler was still documented as a `LineInputPane` non-contiguous helper.
  - After: the method map includes [UID:0001ME][0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation](by-memory/0x005b3e80-0x005b4071.LineInputPaneHistoryNavigation.md) as `SayToUserNameInputPane` code, with its true endpoint `0x005b4072` recorded pending file rename.
  - Evidence: live IDA MCP reports the sole function xref to `0x005b3e80` at `0x0062fccc`, the `SayToUserNameInputPane` secondary vtable slot; byte audit confirms `0x005b4071` is inside the function body and `0x005b4072-0x005b4080` is padding.

- 2026-05-30: Changed completion/confidence from `0/0` to `80/86`.
  - Before: The page was unevaluated despite documenting recipient prompt behavior, recent history preload, modern/legacy flow dispatch, and vtable/caller evidence.
  - After: Scored as high completion and strong confidence for the recipient-name input pane.
  - Evidence: Existing method notes, IDA MCP boundary evidence, constructor caller notes, vtable-reference note, and direct-message pane cross-references support the score.
