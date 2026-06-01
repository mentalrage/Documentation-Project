*** UID:0000L8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MenuVarietyPanes

## Status

- Confidence: strong for menu-variety pane/select-pane ownership; medium for final folder name.
- Proposed module folder: `ui/menu/`
- Candidate file: `ui/menu/MenuVarietyPanes.cpp`
- Current generated sources: `class_MenuVarietyPane.cpp` and `class_MenuVarietySelectPane.cpp`.
- Evidence basis: Wave3 class inspection, generated source, older Wave2 notes for menu-variety helper cleanup, and targeted IDA MCP boundary checks on 2026-05-23.

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

## Ownership Notes

- The constructor's vector helpers at `0x00455350` and `0x005bffe0` are reusable small-wide-string vector support; older notes already corrected those away from a menu-variety-specific owner.
- This should stay separate from `PopupMenuControls.cpp`. It is a concrete gameplay menu selector, not the reusable popup menu item framework.
- The Ranking selector entry opens [UID:0000MZ][RankingDialog](by-file/RankingDialog.md); ranking opcode `0x7d`, ranking board resources, reward info, and ranking row containers belong to that dialog source, not this menu source.
- The Quit selector entry opens [UID:0000MX][QuitDialogs](by-file/QuitDialogs.md); quit confirmation implementation should live in that dialog source, not in the menu selector source.
- Current emitted source omits some tiny helper/thunk bodies for `MenuVarietyPane` and `MenuVarietySelectPane`; source migration should use IDA-confirmed boundaries.
- The singleton at `0x0069bf78` was previously left unresolved in the shared destructor tail; IDA xrefs and active simroot names resolve it as [UID:0000RJ][g_pMenuVarietySelectPane](by-global/g_pMenuVarietySelectPane.md).
- IDA MCP on 2026-05-26 resolves `0x005bd9b0-0x005bda3b` as the `MenuVarietySelectPane` ten-row hit-test helper. Keep it here despite the current generated `BulletinSession::GetMenuIndexFromPoint` owner name.
- [UID:00009U][OldUserStatusPane](by-class/OldUserStatusPane.md) code sits between the menu body and the shared destructor tail in memory. Do not treat the broad `0x005bc610-0x005bfd98` span as one contiguous menu-owned source range.

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

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: menu button/select-pane ownership, proposed contents, IDA ranges, singleton globals, hit-test helper, old-user-status boundary, and ranking/quit/popup split are documented; confidence is capped by final folder name and compact-source uncertainty.
