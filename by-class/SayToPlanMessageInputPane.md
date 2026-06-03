*** UID:0000C5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SayToPlanMessageInputPane

## Status

- Confidence: strong for confirmed method boundaries, source-family ownership, and parent placement; medium for final class name semantics because generated source shows clan-style prompts.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- Address ranges: [UID:0001KO][0x005a4b60-0x005a5791.SayModeHelpers](by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md) and [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_SayToPlanMessageInputPane.cpp`
- Autogen parent: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md); C++ remains blank because the plan/clan final class name and source declaration are below the `95+` source gate.

## Class Purpose

`SayToPlanMessageInputPane` currently owns the central chat-mode opening helpers plus a target-message input pane. Despite the class name, generated source uses `Clan => ` in the target prompt and chat-mode `4` branch, so document it as a plan/clan-style message flow until naming is settled.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `UpdateRecentRecipientList` | `0x005a4b60-0x005a4c22` | Maintains a recent recipient list with a maximum of ten entries. |
| `ProcessDeferredSendState` | `0x005a5010-0x005a5090` | Requests nation entries or dispatches deferred payload state. |
| `OpenInputPaneForCurrentMode` | `0x005a5110-0x005a5336` | Dispatches current chat mode to default say, shout, whisper, group, or plan/clan input. |
| `OpenDefaultSayPane` | `0x005a53c0-0x005a544a` | Creates default `SayInputPane` and resets chat mode. |
| `OpenWhisperToLastRecipient` | `0x005a54b0-0x005a5562` | Opens modern direct-message input for the last recent recipient. |
| `SayToPlanMessageInputPane` | `0x005b22d0-0x005b238e` | Initializes target input and prompt text. |
| `OnSubmit` | `0x005b2390-0x005b2562` | Sends opcode `0x19` with target and message payload. |

## Evidence Notes

- IDA MCP confirms all listed function starts.
- `OpenInputPaneForCurrentMode` is called from chat variety selection, chat handle code, and other input-mode UI paths.
- The class references `SayInputPane`, `ShoutInputPane`, `NewSayToUserMessageInputPane`, `SayToGroupMessageInputPane`, and itself, making it the strongest current file-level anchor for `SayInputPanes.cpp`.
- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) is `87/84` with a validated `NexusTK/social/` reconstruction path and records this class as part of the shared social chat input family.
- [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md) is an exact `78/86` dispatcher child attached to [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md); it confirms callers from chat variety selection, chat handle code, icons/action dispatch, and `UserPane::OnKeyEvent`.
- [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md) is a `70/85` aggregate attached to [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md); it covers the target-message constructors and opcode `0x19` submit methods, including the `0x005b22d0-0x005b2562` plan/clan-style pane span.
- [wave3_data_issues](../wave3_data_issues.md) keeps the unresolved plan/clan naming question open, so this page should not be renamed or receive C++ until strings and caller context settle the final source-facing name.

## Cross-References

- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0001KO][0x005a4b60-0x005a5791.SayModeHelpers](by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md)
- [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md)
- [UID:0000C3][SayInputPane](by-class/SayInputPane.md)
- [UID:0000D5][ShoutInputPane](by-class/ShoutInputPane.md)
- [UID:0000C4][SayToGroupMessageInputPane](by-class/SayToGroupMessageInputPane.md)
- [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `78/74`.
  - Before: The page was unevaluated despite documenting the say-mode helper cluster, recent-recipient handling, target-message constructor, and submit payload.
  - After: Scored as moderate-high completion with medium confidence because the generated `Plan` name conflicts with clan-style prompts and chat-mode semantics.
  - Evidence: Existing method notes, IDA MCP start evidence, mode-opening caller notes, and related input-pane cross-references support behavior while preserving naming uncertainty.
- 2026-06-03 parent attachment pass:
  - Before: the page remained unparented at `78/74`, despite the parent source file and exact dispatcher/target-message memory docs having reached the 80+ confidence gate.
  - Changed to: completion/confidence `80/80`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000N9`.
  - Evidence: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) is `87/84` and has a validated `NexusTK/social/` path; [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md) is `78/86` and attached to that parent; [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md) is `70/85` and attached to the same parent. C++ remains blank because the plan/clan final name and declaration shape are not at the `95+` code-emission threshold.
