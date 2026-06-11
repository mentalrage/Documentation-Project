*** UID:000042 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DropAllInputPane

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- Reconstruction note: leave C++ blank until final helper/member names are 95/95; current evidence is sufficient for routing, not final source.

## Class Purpose

`DropAllInputPane` is a single-character inventory prompt for dropping all items in a selected slot. It formats a player-specific prompt, accepts a slot letter, validates it against the local inventory limit, and either sends the drop-all packet path or opens a confirmation callback.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DropAllInputPane` | `0x005b44b0-0x005b4577` | Constructs the `CharInputPane` prompt and installs vtables. |
| `OnKeyInput` | `0x005b4580-0x005b45ec` | Opens the help/general-purpose panel for the shortcut key and otherwise delegates input. |
| `OnConfirmInput` | `0x005b45f0-0x005b475c` | Converts slot letters, validates inventory range, and sends or confirms the drop-all action. |

## Evidence Notes

- IDA MCP live recheck on 2026-06-07 against `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirms the modeled functions at `0x005b44b0-0x005b4577`, `0x005b4580-0x005b45ec`, and `0x005b45f0-0x005b475c`.
- The constructor calls the `CharInputPane` path, reads the local player/client state through [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical IDA alias `dword_67A748`, fetches localized prompt id `8` from [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md), formats the player-specific prompt, and installs vtables `0x0062fd8c`, `0x0062fddc`, and `0x0062fe0c`.
- IDA xrefs to those vtable bases come from the constructor stores plus the command dispatcher and command factory allocation path, matching the direct slash-command item prompt family.
- `OnKeyInput` implements the shared help shortcut path: it checks the keyboard event fields, opens the general-purpose/help UI with category/page `2`, calls the `0x198` help transition path, and otherwise delegates to the base input handler.
- `OnConfirmInput` requires one typed character, converts lowercase `a-z` to slots `1-26` and uppercase `A-Z` to slots `27-52`, and bounds the converted value against [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) offset `+0x284`.
- For lower inventory slots, `OnConfirmInput` also checks the [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) busy byte at historical offset `+0x3ec0` before sending a three-byte [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) packet: opcode `0x08`, selected slot, mode byte `1`.
- For higher slot selections, the method allocates a confirmation pane and passes the selected slot plus drop-all mode byte `1` with the text `Are you sure you want to drop this item? (Y/N)`.
- This class is part of the direct item action prompt family, not the item selection dialog family.

## Assignment Gate

- Assignment decision: assigned to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
- Child gate: `86/88` after Batch 085; the class now has exact method boundaries, vtable evidence, prompt id, key path, slot conversion, packet behavior, and confirmation branch evidence.
- Parent gate: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) is `90/85` after the same Batch 085 parent refresh.
- Ownership basis: the class is a direct command-input item prompt implemented in the same item-action pane cluster as `DropInputPane`, `GiveInputPane`, `ThrowInputPane`, `UseInputPane`, `EatInputPane`, `WieldInputPane`, and `WearInputPane`.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:000044][DropInputPane](by-class/DropInputPane.md)
- [UID:000043][DropGoldInputPane](by-class/DropGoldInputPane.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md)

## Changes

- 2026-06-07 A004 Batch 085 class toss-up:
  - Before: `76/84`, `AUTOGEN_PARENT_UID` blank.
  - After: `86/88`, `AUTOGEN_PARENT_UID:0000KC`.
  - Evidence: live IDA MCP confirmed exact constructor/key/submit ranges, vtable triple and factory/dispatcher xrefs, prompt id `8`, help-key path, slot-letter conversion, inventory bound, busy gate, opcode `0x08` drop-all mode byte `1`, and confirmation branch.
  - Assignment: direct parent [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) also reached `90/85`, satisfying the corrected child-and-parent 85/85 gate.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/84`.
  - Summary/evidence: prompt role, constructor/key/confirm methods, item-action module ownership, packet/action behavior, IDA-confirmed starts, and sibling pane references are documented; remaining work is fuller internal field naming and final C++ reconstruction.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After at that time: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remained blank because the class completion score was below the old attachment gate. Superseded by the 2026-06-07 A004 Batch 085 assignment to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Evidence: live IDA MCP confirms modeled starts at `0x005b44b0`, `0x005b4580`, and `0x005b45f0`; existing project docs place this direct item-action prompt in [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
