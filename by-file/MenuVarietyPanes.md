*** UID:0000L8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MenuVarietyPanes

## Status

- Confidence: strong for menu-variety pane/select-pane ownership; medium-high for final folder name.
- Proposed module folder: `ui/menu/`
- Candidate file: `ui/menu/MenuVarietyPanes.cpp`
- Evidence basis: live IDA MCP xrefs/decompilation for the two singleton slots and targeted IDA boundary checks for the pane bodies.

## Hypothesis

`MenuVarietyPane` is the in-game menu button. It opens `MenuVarietySelectPane`, which displays a SUBWIN-framed selector with Userlook, Board, Mail, UserList, Friends, Target, Hotkey, Profile, Ranking, and Quit actions.

Likely structure:

```text
ui/menu/MenuVarietyPanes.cpp
```

Possible placement:

```text
social/MenuVarietyPanes.cpp
```

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `MenuVarietyPane` | `0x005bc610-0x005bc88a` plus tail entries | `class_MenuVarietyPane.cpp` | Menu button pane that opens/closes the variety selector and draws `MENUVAR.EPF`. |
| `MenuVarietySelectPane` | `0x005bc970-0x005bd952`, [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md), plus tail entries | `class_MenuVarietySelectPane.cpp` | Selector pane that builds menu labels, handles action clicks, hit-tests ten rows, draws entries/frame/borders, and destroys label storage. |
| [UID:0000RI][g_pMenuVarietyPane](by-global/g_pMenuVarietyPane.md) | `0x0069b4e8` | global | Active menu button singleton. |
| [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md) | `0x0069bf78` | global | Active selector singleton. |

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed:

- `MenuVarietyPane`: `0x005bc610-0x005bc65f`, `0x005bc660-0x005bc688`, `0x005bc690-0x005bc7f9`, `0x005bc800-0x005bc874`, `0x005bc880-0x005bc88a`, `0x005bfc0b-0x005bfc16`, `0x005bfc16-0x005bfc21`, and `0x005bfc80-0x005bfcdf`.
- `MenuVarietySelectPane`: `0x005bc970-0x005bcf7a`, `0x005bcf80-0x005bcff7`, `0x005bd000-0x005bd372`, `0x005bd3a0-0x005bd3bf`, `0x005bd3c0-0x005bd5ac`, `0x005bd5b0-0x005bd621`, `0x005bd630-0x005bd952`, `0x005bfbd0-0x005bfbdb`, `0x005bfc21-0x005bfc2c`, `0x005bfc2c-0x005bfc37`, and `0x005bfce0-0x005bfd98`.

2026-06-07 A006 targeted recheck for the selector singleton parent gate confirmed:

- IDA MCP `xrefs_to 0x0069bf78` reports the complete seven-reference lifecycle for [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md): menu click/draw consumers, constructor publish/null-fallback, ordinary destructor clear, standalone clear helper, and scalar deleting destructor clear.
- IDA MCP `callers 0x005bc970` reports the selector constructor called from `0x005bc765` inside `MenuVarietyPane` click handling.
- IDA MCP `callees` for the selector constructor/destructor family confirms only pane/vector/string helpers in the menu selector lifecycle, while [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) remains a separate physical neighbor rather than a menu-owned child.

## Ownership Notes

- The constructor's vector helpers at `0x00455350` and `0x005bffe0` are reusable small-wide-string vector support; older notes already corrected those away from a menu-variety-specific owner.
- This should stay separate from `PopupMenuControls.cpp`. It is a concrete gameplay menu selector, not the reusable popup menu item framework.
- The Ranking selector entry opens [UID:0000MZ][RankingDialog](by-file/RankingDialog.md); ranking opcode `0x7d`, ranking board resources, reward info, and ranking row containers belong to that dialog source, not this menu source.
- The Quit selector entry opens [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md); quit confirmation implementation should live in that dialog source, not in the menu selector source.
- Source migration should use IDA-confirmed boundaries, including tiny helper/thunk bodies around the main pane clusters.
- The singleton at `0x0069bf78` was previously left unresolved in the shared destructor tail; refreshed IDA xrefs resolve it as [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md).
- IDA MCP on 2026-05-26 resolves `0x005bd9b0-0x005bda3b` as the `MenuVarietySelectPane` ten-row hit-test helper.
- [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) code sits between the menu body and the shared destructor tail in memory. Do not treat the broad `0x005bc610-0x005bfd98` span as one contiguous menu-owned source range.

## Assignment Gate

This file page now clears the corrected parent gate for [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md). Confidence is raised to `85` because the selector singleton storage, selector constructor caller, destructor/clear-helper tail, and old-status-pane boundary were rechecked directly; it remains below final-audit confidence because the exact final folder name and whether the tiny shared vector helpers were file-local or reusable library helpers remain unresolved.

## Cross-References

- [UID:000081][MenuVarietyPane](by-class/MenuVarietyPane.md)
- [UID:000082][MenuVarietySelectPane](by-class/MenuVarietySelectPane.md)
- [UID:0000RI][g_pMenuVarietyPane](by-global/g_pMenuVarietyPane.md)
- [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md)
- [UID:0001NQ][0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest](by-memory/0x005bd9b0-0x005bda3b.MenuVarietySelectPaneHitTest.md)
- [UID:0001NP][0x005bc610-0x005bfd98.MenuVarietyPanes](by-memory/0x005bc610-0x005bfd98.MenuVarietyPanes.md)
- [UID:0001NS][0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper](by-memory/0x005bfbd0-0x005c0034.UiPaneDestructorThunksAndVectorHelper.md)
- [UID:0000MN][PopupMenuControls](by-file/PopupMenuControls.md)
- [UID:0000N7][RightButtonMenuPane](by-file/RightButtonMenuPane.md)
- [UID:0000MZ][RankingDialog](by-file/RankingDialog.md)
- [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md)

## Changes

- 2026-06-07 A006 Batch 060 parent-gate refresh:
  - What existed before: `COMPLETION:86`, `CONFIDENCE:82`, with strong menu selector docs but below the corrected parent gate for [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md).
  - Changed to: confidence `85`; completion remains `86`.
  - Summary/evidence: live IDA MCP reconfirmed the selector singleton's full seven-xref lifecycle, the constructor caller from `MenuVarietyPane` click handling, selector destructor/clear-helper ownership, and the boundary excluding adjacent [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) code.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: menu button/select-pane ownership, proposed contents, IDA ranges, singleton globals, hit-test helper, old-user-status boundary, and ranking/quit/popup split are documented; confidence is capped by final folder name and compact-source uncertainty.

- 2026-06-05 projected path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file root remained an autogen file-path error.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/menu/"`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `MenuVarietyPanes.cpp` under `NexusTK/ui/menu/`, and live IDA MCP xrefs on `0x0069b4e8` / `0x0069bf78` confirm the menu button and selector singleton ownership for this file.
