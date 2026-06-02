*** UID:0000N9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SayInputPanes

## Status

- Confidence: strong for the confirmed input pane behaviors and `social/` placement; medium-high for exact split between say/chat/group/clan files.
- Proposed module folder: `NexusTK/social/`
- Proposed source file: `NexusTK/social/SayInputPanes.cpp`
- Possible split files: `social/WhisperInputPanes.cpp`, `social/ChatInputPane.cpp`, [UID:0000JS][Group](by-file/Group.md), and [UID:0000I5][Chatting](by-file/Chatting.md)
- Evidence basis: current IDA MCP function-boundary/xref checks, existing class/memory docs, and cross-references from chat selector/handle code. Generated Wave3/simroot names are treated as provisional leads only.

## Hypothesis

The `Say*` and `ShoutInputPane` classes form a social chat input family. The code provides default say chat, shout chat, direct whisper/user message flows, group message input, and a plan/clan-style target message input. The mode-opening helpers around `0x005a4b60-0x005a5791` are the strongest evidence for one feature-level source file because `OpenInputPaneForCurrentMode` chooses between default say, shout, whisper, group, and clan-style modes.

`ChatInputPane` remains documented with [UID:0000I5][Chatting](by-file/Chatting.md), but it is physically adjacent to `SayInputPane` and should be cross-referenced when deciding final source layout.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `SayToPlanMessageInputPane` mode helpers | `0x005a4b60-0x005a5791` | `class_SayToPlanMessageInputPane.cpp`, `class_ShoutInputPane.cpp` | Recent-recipient management, deferred send state, mode dispatch, default say open, last-recipient whisper open, and shout-pane creation. |
| [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md) | `0x005a5110-0x005a5337` | exact child memory page | Central current-mode dispatcher for default say, shout, whisper, group, and plan/clan input panes. |
| `SayToUserMessageInputPane` | `0x005b1570-0x005b1812` | `class_SayToUserMessageInputPane.cpp` | Legacy direct-message input pane for a named recipient. |
| `NewSayToUserMessageInputPane` | `0x005b1990-0x005b1d42`, thunks/destructor at `0x005b7820+`, `0x005b7af0` | `class_NewSayToUserMessageInputPane.cpp` | Modern direct-message input pane with backspace return to name-entry flow. |
| `SayToGroupMessageInputPane` | `0x005b1ec0-0x005b2152` | `class_SayToGroupMessageInputPane.cpp` | Group message input; sends opcode `0x19` with group name and message payload. |
| `SayToPlanMessageInputPane` | `0x005b22d0-0x005b2562` plus helpers above | `class_SayToPlanMessageInputPane.cpp` | Plan/clan-style message input; generated source uses `Clan => ` prompt and opcode `0x19`. |
| `SayInputPane` | raw constructor [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md), confirmed cluster [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md), destructor `0x005b7b80` | `class_SayInputPane.cpp` | Default say input with history navigation and opcode `0x0e`, subtype `0`. |
| `SayToUserNameInputPane` | `0x005b3cb0-0x005b4219` | `class_SayToUserNameInputPane.cpp` | Recipient-name prompt; opens legacy or modern direct-message input based on `g_useModernWhisperFlow`. |
| `ShoutInputPane` | creator `0x005a5710`, raw constructor [UID:0002SA][0x005b4220-0x005b4255.ShoutInputPaneRawConstructor](by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md), confirmed submit [UID:0001MF][0x005b4260-0x005b43bc.ShoutInputPane](by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md) | `class_ShoutInputPane.cpp` | Shout input with `L"! "` prompt, opcode `0x0e`, subtype `1`, and shout packet send. |
| `UserListPane::OpenSayToUserMessageInputPane` | `0x0059ed60-0x0059ee0c` | `class_UserListPane.cpp` | User-list bridge that opens a direct-message input for the selected user. |

## Boundary And Data Notes

- Current IDA MCP confirms mode/helper starts at `0x0059ed60`, `0x005a4b60`, `0x005a5010`, `0x005a5110`, `0x005a53c0`, `0x005a54b0`, and `0x005a5710`.
- Current IDA MCP on 2026-06-02 confirms `0x005a5110` size `0x227`, callers from chat variety selection `0x0048126b`, chat handle code `0x00481ef6`, icons/action dispatch `0x004cf704`, and `UserPane::OnKeyEvent` at `0x005a6351`, plus callees into recent-recipient update, default say open, shout creation, and modern direct-message input.
- Current IDA MCP `py_eval` on 2026-06-02 shows the broader `0x005a4b60-0x005a5791` neighborhood also contains small `IconsPane` action helpers at `0x005a4db0`, `0x005a4e40`, `0x005a4e70`, `0x005a4f40`, and related action bodies; keep the broad aggregate as mixed-neighborhood evidence rather than a single-file source owner.
- IDA MCP confirms target-message pane starts at `0x005b1570`, `0x005b1640`, `0x005b1990`, `0x005b1a60`, `0x005b1c40`, `0x005b1ec0`, `0x005b1f80`, `0x005b22d0`, and `0x005b2390`.
- IDA MCP confirms default/recipient/shout starts at `0x005b34d0`, `0x005b3570`, `0x005b3670`, `0x005b3cb0`, `0x005b4080`, and `0x005b4260`.
- IDA reports no function at the recovered `SayInputPane::SayInputPane` projected start `0x005b3490`; 2026-06-02 raw byte/disassembly review confirms [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md) as a constructor-shaped body and confirms the constructor-like overload at `0x005b34d0`.
- IDA reports no function at Wave3's `ShoutInputPane::ShoutInputPane` projected start `0x005b4220`, but 2026-06-02 raw byte/disassembly review confirms [UID:0002SA][0x005b4220-0x005b4255.ShoutInputPaneRawConstructor](by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md) as the constructor-shaped body and confirms the submit function begins at `0x005b4260`.
- `SayToPlanMessageInputPane` naming is ambiguous: generated source uses `Clan => ` for the prompt and mode dispatch treats it as the chat-mode `4` clan branch. Keep the current Wave3 name but cross-reference it as plan/clan-style input.

## Migration Notes

Do not run ownership migrations until the two projected constructor starts are resolved or clearly marked projected/non-IDA in Wave3.

```powershell
python source-3\wave3.py create file SayInputPanes.cpp --kind source --simpath social/SayInputPanes.cpp --dry-run
python source-3\wave3.py attach class SayInputPane --to-file SayInputPanes.cpp
python source-3\wave3.py attach class SayToUserNameInputPane --to-file SayInputPanes.cpp
python source-3\wave3.py attach class SayToUserMessageInputPane --to-file SayInputPanes.cpp
python source-3\wave3.py attach class NewSayToUserMessageInputPane --to-file SayInputPanes.cpp
python source-3\wave3.py attach class SayToGroupMessageInputPane --to-file SayInputPanes.cpp
python source-3\wave3.py attach class SayToPlanMessageInputPane --to-file SayInputPanes.cpp
python source-3\wave3.py attach class ShoutInputPane --to-file SayInputPanes.cpp
```

Consider leaving `SayToGroupMessageInputPane` attached to [UID:0000JS][Group](by-file/Group.md) if the final source layout prefers feature-specific files over one social input file.

## Cross-References

- [UID:0000C3][SayInputPane](by-class/SayInputPane.md)
- [UID:0000C6][SayToUserMessageInputPane](by-class/SayToUserMessageInputPane.md)
- [UID:000099][NewSayToUserMessageInputPane](by-class/NewSayToUserMessageInputPane.md)
- [UID:0000C4][SayToGroupMessageInputPane](by-class/SayToGroupMessageInputPane.md)
- [UID:0000C5][SayToPlanMessageInputPane](by-class/SayToPlanMessageInputPane.md)
- [UID:0000C7][SayToUserNameInputPane](by-class/SayToUserNameInputPane.md)
- [UID:0000D5][ShoutInputPane](by-class/ShoutInputPane.md)
- [UID:0001KO][0x005a4b60-0x005a5791.SayModeHelpers](by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md)
- [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md)
- [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md)
- [UID:0001MB][0x005b34d0-0x005b37ea.SayInputPane](by-memory/0x005b34d0-0x005b37ea.SayInputPane.md)
- [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md)
- [UID:0001MD][0x005b3cb0-0x005b4219.SayToUserNameInputPane](by-memory/0x005b3cb0-0x005b4219.SayToUserNameInputPane.md)
- [UID:0002SA][0x005b4220-0x005b4255.ShoutInputPaneRawConstructor](by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md)
- [UID:0001MF][0x005b4260-0x005b43bc.ShoutInputPane](by-memory/0x005b4260-0x005b43bc.ShoutInputPane.md)
- [UID:0000I5][Chatting](by-file/Chatting.md)
- [UID:0000JS][Group](by-file/Group.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `78`.
  - Evidence: document covers the social input family, proposed contents, confirmed address starts, ownership/split caveats, migration notes, and cross-references; confidence remains limited by unresolved constructor starts and the still-open split between say, chat, group, and clan/plan modules.
- 2026-06-02 path and confidence update:
  - Before: `PROPOSED_RECONSTRUCTION_PATH` was blank and confidence was below the parent-attachment threshold at `78`.
  - After: set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/social/"`, scores `86/82`, and added current IDA evidence for the exact current-mode dispatcher child.
  - Evidence: current IDA MCP confirms the mode dispatcher boundary/callers/callees, while `by-project-structure/proposed-source-tree.md` places `SayInputPanes.cpp` under `social/`.
- 2026-06-02 `SayInputPane` constructor split:
  - Before: the proposed contents only described `0x005b3490` as a projected constructor start.
  - After: linked exact raw constructor child [UID:0002S7][0x005b3490-0x005b34d0.SayInputPaneRawConstructor](by-memory/0x005b3490-0x005b34d0.SayInputPaneRawConstructor.md) and refreshed the `SayInputPane` row to reference both constructor and confirmed method-cluster pages.
  - Evidence: IDA raw bytes and vtable stores confirm the constructor-shaped body despite no IDA function object.
- 2026-06-02 `ShoutInputPane` constructor split:
  - Before: the proposed contents only described `0x005b4220` as a projected constructor start.
  - After: linked exact raw constructor child [UID:0002SA][0x005b4220-0x005b4255.ShoutInputPaneRawConstructor](by-memory/0x005b4220-0x005b4255.ShoutInputPaneRawConstructor.md) and refreshed the `ShoutInputPane` row to reference both constructor and confirmed submit pages.
  - Evidence: IDA raw bytes, prompt string, vtable stores, creator xrefs, and submit vtable slot confirm the constructor-shaped body despite no IDA function object.
