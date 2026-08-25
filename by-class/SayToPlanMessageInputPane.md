*** UID:0000C5 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000N9 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class SayToClanMessageInputPane : public LineInputPane
{
public:
    explicit SayToClanMessageInputPane(const wchar_t *clanName);

protected:
    virtual void OnSubmitInput();

private:
    wchar_t m_clanName[128]; // +0x108
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

## UID0000N9 Whole-File Topology Synchronization - 2026-08-25

- Deterministic emitter position is `40`. The stable page/path title remains historical UID continuity; active source is `SayToClanMessageInputPane`, proved by mode `4`, prefix `L"!"`, prompt `L"Clan => "`, and UID000406 constructor/submit behavior.
- Formal CPP remains `[[CHILDREN]]`; formal H retains the complete source-facing Clan declaration and omits an explicit derived destructor.

# SayToPlanMessageInputPane

## Status

- Confidence: strong for confirmed method boundaries, source-family ownership, parent placement, shared target-message packet behavior, and clan-facing semantic direction. The current page name remains a historical/generated documentation label until a controlled rename/migration is authorized.
- Likely source file: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- Address ranges: [UID:0001KO][0x005a4b60-0x005a5791.SayModeHelpers](by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md) and [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md)
- Historical generated/recovered file: `source-3/simroot_v2/class_SayToPlanMessageInputPane.cpp`; current source placement is shared `NexusTK/social/SayInputPanes.cpp/.h`, with source-facing Clan naming.
- Autogen parent: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md); formal H now emits the complete `SayToClanMessageInputPane` declaration after `SayToGroupMessageInputPane` and before UID0000C6, while formal CPP expands exact child UID000406 at namespace scope. The inherited virtual destructor is intentionally implicit.
- 2026-06-14 live IDA MCP refresh on database `b001_0003gy` reconfirmed the dispatcher mode-4 allocation, `!` prefix, `Clan => ` prompt, constructor, submit handler, opcode `0x19` packet body, and vtable slot refs. B001's 2026-06-19 PE/Capstone reanalysis upgrades the naming conclusion: `SayToClanMessageInputPane` is the best source-facing direction, while `SayToPlanMessageInputPane` is retained only for filename/UID continuity.

## Class Purpose

`SayToPlanMessageInputPane` is the current stable documentation UID/name for the chat-mode 4 target-message pane. The best source-facing semantic direction is now `SayToClanMessageInputPane`: the mode branch copies `!`, the prompt is `Clan => `, and the submit body sends the same opcode `0x19` target-message packet family as the user/group branches. Keep the current filename/UID until a controlled rename/migration is authorized.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `UpdateRecentRecipientList` | `0x005a4b60-0x005a4c22` | Maintains a recent recipient list with a maximum of ten entries. |
| `ProcessDeferredSendState` | `0x005a5010-0x005a5090` | Requests nation entries or dispatches deferred payload state. |
| `OpenInputPaneForCurrentMode` | `0x005a5110-0x005a5336` | Dispatches current chat mode to default say, shout, whisper, group, or clan input; mode `4` constructs the source-facing `SayToClanMessageInputPane` route with `L"!"` and `L"Clan => "`. |
| `UserPane::OpenDefaultSayInputPane` | `0x005a53c0-0x005a544b` | UserPane-owned sibling opener; creates default `SayInputPane` and resets chat mode. |
| `OpenWhisperToLastRecipient` | `0x005a54b0-0x005a5562` | Opens modern direct-message input for the last recent recipient. |
| `SayToClanMessageInputPane` / current-doc `SayToPlanMessageInputPane` | `0x005b22d0-0x005b238e` | Initializes clan target input, copies `m_clanName[128]` at `+0x108`, and applies `Clan => ` prompt text. |
| `OnSubmitInput` / current-doc `OnSubmit` | `0x005b2390-0x005b2562` | Sends opcode `0x19` with clan target and message payload. |

## Evidence Notes

- IDA MCP confirms all listed function starts.
- `OpenInputPaneForCurrentMode` is called from chat variety selection, chat handle code, and other input-mode UI paths.
- The class references `SayInputPane`, `ShoutInputPane`, `NewSayToUserMessageInputPane`, `SayToGroupMessageInputPane`, and itself, making it the strongest current file-level anchor for `SayInputPanes.cpp`.
- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) is `88/87` with a validated `NexusTK/social/` reconstruction path and records this class as part of the shared social chat input family.
- [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md) is an exact `90/92` dispatcher child attached to [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md). It now carries first-draft formal C++ and confirms callers from chat variety selection, chat handle code, icons/action dispatch, raw switch-case route `0x004cf937`, and `UserPane::OnKeyEvent`; mode `4` constructs the source-facing `SayToClanMessageInputPane` path inline using `L"!"` and `L"Clan => "`.
- [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md) is now an `88/91` non-emitting split/index; exact child [UID:000406][0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods](by-memory/0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods.md) carries this class's constructor, padding, submit span, and first-draft source-facing method C++ under the clan alias.
- [wave3_data_issues](../wave3_data_issues.md) retains historical plan/clan naming context, but the current ranked conclusion is no longer open-ended: `SayToClanMessageInputPane` is highest probability, neutral target-message naming is lower, and `SayToPlanMessageInputPane` is retained for filename/UID continuity only.
- 2026-06-14 live IDA MCP `lookup_funcs` reports `0x005a5110` size `0x227`, `0x005a5570` size `0xca`, `0x005a5640` size `0xca`, `0x005b22d0` size `0xbe`, and `0x005b2390` size `0x1d2`.
- 2026-06-14 live IDA MCP `decompile 0x005a5110` confirms mode `3` opens the group branch with `!!` and `Group => `, while mode `4` allocates the plan/clan class, stores `!` at the destination field, and formats the `Clan => ` prompt.
- 2026-06-14 live IDA MCP `decompile 0x005b22d0` confirms the constructor stores the three `SayToPlanMessageInputPane` vtables, copies the target string to `this+0x108`, and applies the `Clan => ` prompt.
- 2026-06-14 live IDA MCP `decompile 0x005b2390` confirms a non-empty input path that cleans text, length-prefixes target and message strings, writes opcode `0x19`, and sends through the packet sender.
- 2026-06-14 live IDA MCP `xrefs_to 0x00630a58` reports refs from `0x005a5110`, `0x005a5640`, and the constructor at `0x005b22d0`; `get_string 0x00630a58` returns `Clan => `.

## Plan/Clan Naming Decision

| Evidence | Interpretation |
| --- | --- |
| Current class page UID/name | Keep `SayToPlanMessageInputPane` as the documentation filename until a controlled rename/migration is authorized; UID references are already stable across class, file, and memory docs. |
| Generated-source prompt lead | `Clan => ` is a high-confidence semantic indicator when combined with the mode-4 branch and `!` prefix. |
| Mode dispatcher evidence | Chat mode `4` opens this pane from the shared say-mode dispatcher, copies `!`, and formats `Clan => `, making clan the best source-facing direction. |
| Target-message aggregate | The pane belongs with the same opcode `0x19` target/message packet family as user, modern-user, and group message panes. |
| Current source placement | Keep parent [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) and cross-reference clan/group docs only as supporting context until exact source split is settled. |
| Ranked conclusion | `SayToClanMessageInputPane` highest probability; neutral `SayTargetMessageInputPane` lower; `SayToPlanMessageInputPane` retained only for historical/generated filename continuity. |

## Boundary Evidence Matrix

| Range | Role | Evidence status |
| --- | --- | --- |
| `0x005a4b60-0x005a5791` | Recent-recipient, deferred-send, and current-mode helper neighborhood | Covered by [UID:0001KO][0x005a4b60-0x005a5791.SayModeHelpers](by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md); mixed neighborhood includes non-say helper exclusions, so this class should not claim the whole range as class-exclusive. |
| `0x005a5110-0x005a5337` | Current-mode dispatcher child | Covered by [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md); confirms this pane is opened from the shared say/shout/whisper/group/clan mode switch, with mode `4` using the clan prefix/prompt and accepted source-facing `SayToClanMessageInputPane` name. |
| [UID:000406][0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods](by-memory/0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods.md) | Constructor, two-byte padding, and submit handler | Exact child created by the 2026-06-20 Rule 26 incorporation. It records constructor `0x005b22d0-0x005b238e`, padding `0x005b238e-0x005b2390`, submit `0x005b2390-0x005b2562`, vtable slot `0x0062f8e8`, `m_clanName[128]`, `!`/`Clan => ` evidence, and first-draft method C++. |

## Cross-References

- [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md)
- [UID:0001KO][0x005a4b60-0x005a5791.SayModeHelpers](by-memory/0x005a4b60-0x005a5791.SayModeHelpers.md)
- [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md)
- [UID:000406][0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods](by-memory/0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods.md)
- [UID:0000C3][SayInputPane](by-class/SayInputPane.md)
- [UID:0000D5][ShoutInputPane](by-class/ShoutInputPane.md)
- [UID:0000C4][SayToGroupMessageInputPane](by-class/SayToGroupMessageInputPane.md)
- [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md)

## Changes

- 2026-08-17 B001 UID0000MG/SayInputPanes implementation: raised `87/90 -> 93/94`; moved the complete class from CPP to formal H, removed the stale explicit derived destructor, made formal CPP exactly `[[CHILDREN]]`, and preserved plan/clan history, `m_clanName[128]` at `+0x108`, prompt/prefix evidence, opcode `0x19`, and UID000406 ownership.

- 2026-05-30: Changed completion/confidence from `0/0` to `78/74`.
  - Before: The page was unevaluated despite documenting the say-mode helper cluster, recent-recipient handling, target-message constructor, and submit payload.
  - After: Scored as moderate-high completion with medium confidence because the generated `Plan` name conflicts with clan-style prompts and chat-mode semantics.
  - Evidence: Existing method notes, IDA MCP start evidence, mode-opening caller notes, and related input-pane cross-references support behavior while preserving naming uncertainty.
- 2026-06-03 parent attachment pass:
  - Before: the page remained unparented at `78/74`, despite the parent source file and exact dispatcher/target-message memory docs having reached the 80+ confidence gate.
  - Changed to: completion/confidence `80/80`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000N9`.
  - Evidence: [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) is `87/84` and has a validated `NexusTK/social/` path; [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md) is `78/86` and attached to that parent; [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md) is `70/85` and attached to the same parent. C++ remains blank because the plan/clan final name and declaration shape are not at the `95+` code-emission threshold.
- 2026-06-06 A009 continuation:
  - Before: the page was `80/80` and referenced the target-message aggregate before its child boundary matrix was refreshed.
  - Changed to: completion/confidence `82/82`, with a plan/clan naming-decision table and a boundary evidence matrix.
  - Evidence: [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md) now records this class's `0x005b22d0-0x005b238e` constructor and `0x005b2390-0x005b2562` submit span inside the shared opcode `0x19` target-message family. Confidence is still capped because live IDA MCP was unavailable during the A009 pass and the final plan/clan source-facing name remains unresolved.
- 2026-06-14 A001 Goal 2 refresh:
  - Before: `82/82`; live IDA had been unavailable during the previous pass and the exact plan/clan subrange was documented mostly through aggregate evidence.
  - Changed to: `85/86`; parent [UID:0000N9][SayInputPanes](by-file/SayInputPanes.md) and aggregate [UID:0001LY][0x005b1570-0x005b2562.SayTargetMessageInputPanes](by-memory/0x005b1570-0x005b2562.SayTargetMessageInputPanes.md) now both clear `85/85+`.
  - Evidence: live IDA MCP database `b001_0003gy` reconfirmed dispatcher mode-4 construction, `Clan => ` string refs, constructor size/body, submit size/body, vtable-slot ref, opcode `0x19` packet shape, and exact constructor/submit padding.
- 2026-06-20 supervisor Rule 26 incorporation of B001 `0001LY-SayTargetMessageInputPanes-source-quality.md`:
  - Before: `85/86`, no formal class C++, and plan/clan naming was still open-ended.
  - After: `87/90`, declaration-only class C++ under the source-facing `SayToClanMessageInputPane` alias, exact child [UID:000406][0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods](by-memory/0x005b22d0-0x005b2562.SayToClanMessageInputPaneMethods.md) with first-draft constructor/submit C++, `m_clanName[128]` at `+0x108`, and a ranked naming conclusion.
  - Evidence: B001 PE/Capstone route and boundary pass confirmed `!` prefix refs, `Clan => ` prompt refs, constructor/submit boundaries, vtable slot `0x0062f8e8`, opcode `0x19` packet shape, neighboring helper/padding split, and clan as the highest-probability source-facing direction.
- 2026-06-26 B009 source-quality implementation:
  - Kept the class score unchanged at `87/90`.
  - Updated the current-mode dispatcher notes to reflect [UID:0002RX][0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode](by-memory/0x005a5110-0x005a5337.OpenInputPaneForCurrentSayMode.md)'s new `90/92` status and formal C++ block, including mode `4` inline construction of the source-facing `SayToClanMessageInputPane` branch.
  - Evidence: accepted B009 report and live MCP session `80de0a67` reconfirmed dispatcher size, callers/callees, no-function exclusive end, raw switch-case route, and group/clan literal behavior.
