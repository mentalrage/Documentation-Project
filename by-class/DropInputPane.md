*** UID:000044 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DropInputPane

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- Reconstruction note: leave C++ blank until final helper/member names are 95/95; current evidence is sufficient for routing, not final source.

## Class Purpose

`DropInputPane` is the standard item-drop prompt. It accepts a single inventory slot letter, routes gold selection into `DropGoldInputPane`, and sends or confirms the item-drop action for normal inventory slots.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DropInputPane` | `0x005b47e0-0x005b48a7` | Constructs the prompt with player name and installs vtables. |
| `OnKeyEvent` | `0x005b48b0-0x005b491c` | Handles help-panel shortcut and delegates normal input. |
| `OnSubmit` | `0x005b4920-0x005b4ae4` | Converts input to a slot, creates `DropGoldInputPane` for gold, or sends/confirm drop item opcode `0x08`. |

## Evidence Notes

- IDA MCP live recheck on 2026-06-07 against `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirms the modeled functions at `0x005b47e0-0x005b48a7`, `0x005b48b0-0x005b491c`, and `0x005b4920-0x005b4ae4`.
- The constructor calls the `CharInputPane` path, reads the local player/client state through [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical IDA alias `dword_67A748`, fetches localized prompt id `6` from [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), formats the player-specific prompt, and installs vtables `0x0062fe18`, `0x0062fe68`, and `0x0062fe98`.
- IDA xrefs to those vtable bases come from the constructor stores plus the command dispatcher and command factory allocation path, matching the direct slash-command item prompt family.
- `OnKeyEvent` implements the same help shortcut path as `DropAllInputPane`: it checks the keyboard event fields, opens the general-purpose/help UI with category/page `2`, calls the `0x198` help transition path, and otherwise delegates to the base input handler.
- `OnSubmit` requires one typed character. The gold shortcut characters backslash (`0x5c`), slash (`0x2f`), and dollar (`0x24`) allocate a `DropGoldInputPane`, request localized prompt id `7`, and install the DropGold vtables `0x0062fea4`, `0x0062fef4`, and `0x0062ff24`.
- For non-gold input, `OnSubmit` converts the slot character, bounds it against [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) offset `+0x284`, and uses [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) historical offset `+0x3ec0` as the busy gate before direct packet send.
- Lower inventory slots send a three-byte [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) packet: opcode `0x08`, selected slot, mode byte `0`. Higher slot selections allocate a confirmation pane with the same selected slot and mode byte `0`.
- The class belongs with the direct item action panes because it owns command-input translation and packet dispatch rather than inventory rendering.

## Assignment Gate

- Assignment decision: assigned to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
- Child gate: `86/88` after Batch 085; the class now has exact method boundaries, vtable evidence, prompt id, key path, gold branch, slot conversion, packet behavior, and confirmation branch evidence.
- Parent gate: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) is `90/85` after the same Batch 085 parent refresh.
- Ownership basis: the class is a direct command-input item prompt implemented in the same item-action pane cluster as `DropAllInputPane`, `GiveInputPane`, `ThrowInputPane`, `UseInputPane`, `EatInputPane`, `WieldInputPane`, and `WearInputPane`.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md)
- [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md)

## Changes

- 2026-06-07 A004 Batch 085 class toss-up:
  - Before: `76/84`, `AUTOGEN_PARENT_UID` blank.
  - After: `86/88`, `AUTOGEN_PARENT_UID:0000KC`.
  - Evidence: live IDA MCP confirmed exact constructor/key/submit ranges, vtable triple and factory/dispatcher xrefs, prompt id `6`, help-key path, gold shortcut branch, slot-letter conversion, inventory bound, busy gate, opcode `0x08` drop mode byte `0`, and confirmation branch.
  - Assignment: direct parent [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) also reached `90/85`, satisfying the corrected child-and-parent 85/85 gate.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/84`.
  - Summary/evidence: standard drop prompt role, constructor/key/submit methods, gold branch, opcode behavior, item-action module ownership, and sibling pane links are documented; remaining work is detailed field naming and final reconstructed C++ polish.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After at that time: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remained blank because the class completion score was below the old attachment gate. Superseded by the 2026-06-07 A004 Batch 085 assignment to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Evidence: live IDA MCP confirms modeled starts at `0x005b47e0`, `0x005b48b0`, and `0x005b4920`; existing project docs place this direct item-action prompt in [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
