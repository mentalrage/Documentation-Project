*** UID:000047 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EatInputPane

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- Reconstruction note: leave C++ blank until final helper/member names are 95/95; current evidence is sufficient for routing, not final source.

## Class Purpose

`EatInputPane` is the consumable/eat prompt. It accepts one inventory slot letter, validates it against the local inventory count, and sends the eat item packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `EatInputPane` | `0x005b5ec0-0x005b5f87` | Constructs the prompt with player name and installs vtables. |
| `OnKeyInput` | `0x005b5f90-0x005b5ffc` | Handles help-panel shortcut and delegates normal input. |
| `OnConfirmInput` | `0x005b6000-0x005b60c0` | Converts slot letter and sends opcode `0x1a`. |

## Evidence Notes

- IDA MCP live recheck on 2026-06-07 against `NexusTK.exe` (`md5 4247e04e20b65d6414c7238aa8ff5515`) confirms the modeled functions at `0x005b5ec0-0x005b5f87`, `0x005b5f90-0x005b5ffc`, and `0x005b6000-0x005b60c0`.
- IDA MCP recheck on 2026-05-27 confirms the constructor uses prompt id `0x0c`, calls `CharInputPane::CharInputPane`, gets the local player name from [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / historical IDA alias `dword_67A748`, formats the prompt, and installs vtables `0x00630390`, `0x006303e0`, and `0x00630410`.
- The 2026-06-07 recheck confirms xrefs to those vtable bases from the constructor stores plus the command dispatcher and command factory allocation path, matching the direct slash-command item prompt family.
- `OnKeyInput` implements the shared help shortcut path: it checks the keyboard event fields, opens the general-purpose/help UI with category/page `2`, calls the `0x198` help transition path, and otherwise delegates to the base input handler.
- IDA decompilation of `0x005b6000` confirms slot conversion: lowercase `a-z` becomes `1-26`, uppercase `A-Z` becomes `27-52`, and the accepted value is bounded by [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) offset `+0x284`.
- The packet is opcode `0x1a`, selected slot byte, length `2`, sent through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- This class is part of the same command prompt family as [UID:0000FG][UseInputPane](by-class/UseInputPane.md) and [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md).

## Assignment Gate

- Assignment decision: assigned to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
- Child gate: `86/88` after Batch 085; the class now has exact method boundaries, vtable evidence, prompt id, key path, slot conversion, packet behavior, and sibling-family evidence.
- Parent gate: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) is `90/85` after the same Batch 085 parent refresh.
- Ownership basis: the class is a direct command-input item prompt implemented in the same item-action pane cluster as `DropAllInputPane`, `DropInputPane`, `ThrowInputPane`, `UseInputPane`, `WieldInputPane`, and `WearInputPane`.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- [UID:0000FG][UseInputPane](by-class/UseInputPane.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000RC][g_pLanguageMan](by-global/g_pLanguageMan.md)

## Changes

- 2026-06-07 A004 Batch 085 class toss-up:
  - Before: `78/86`, `AUTOGEN_PARENT_UID` blank.
  - After: `86/88`, `AUTOGEN_PARENT_UID:0000KC`.
  - Evidence: live IDA MCP confirmed exact constructor/key/submit ranges, vtable triple and factory/dispatcher xrefs, prompt id `12`, help-key path, slot-letter conversion, inventory bound, and opcode `0x1a` packet send.
  - Assignment: direct parent [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md) also reached `90/85`, satisfying the corrected child-and-parent 85/85 gate.
- 2026-06-07 A008 alias cleanup:
  - Before: constructor evidence used bare `dword_67A748` wording for the local-player name source.
  - Changed to: canonical [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) wording while preserving `dword_67A748` as the historical IDA alias.
  - Evidence: the global page records `0x0067a748` as a broad player/client-state pointer, including item-command prompt views.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/86`.
  - Summary/evidence: item prompt role, constructor/key/confirm methods, slot conversion, packet opcode, vtable stores, global dependencies, and item-action family links are documented; remaining work is mostly final field/local naming.
- 2026-06-05: Marked reconstructable for autogen.
  - Before: `RECONSTRUCTABLE` was blank, leaving the class coverage row unclassified.
  - After at that time: `RECONSTRUCTABLE:TRUE`; `AUTOGEN_PARENT_UID` remained blank because the class completion score was below the old attachment gate. Superseded by the 2026-06-07 A004 Batch 085 assignment to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Evidence: live IDA MCP confirms modeled starts at `0x005b5ec0`, `0x005b5f90`, and `0x005b6000`; existing project docs place this direct item-action prompt in [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
