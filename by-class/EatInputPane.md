*** UID:000047 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EatInputPane

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_EatInputPane.cpp`

## Class Purpose

`EatInputPane` is the consumable/eat prompt. It accepts one inventory slot letter, validates it against the local inventory count, and sends the eat item packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `EatInputPane` | `0x005b5ec0-0x005b5f87` | Constructs the prompt with player name and installs vtables. |
| `OnKeyInput` | `0x005b5f90-0x005b5ffc` | Handles help-panel shortcut and delegates normal input. |
| `OnConfirmInput` | `0x005b6000-0x005b60c0` | Converts slot letter and sends opcode `0x1a`. |

## Evidence Notes

- Wave3 generated source shows packet opcode `0x1a`.
- IDA MCP confirms all three function starts.
- IDA MCP recheck on 2026-05-27 confirms the constructor uses prompt id `0x0c`, calls `CharInputPane::CharInputPane`, gets the local player name from `dword_67A748`, formats the prompt, and installs vtables `0x00630390`, `0x006303e0`, and `0x00630410`.
- IDA decompilation of `0x005b6000` confirms slot conversion: lowercase `a-z` becomes `1-26`, uppercase `A-Z` becomes `27-52`, and the accepted value is bounded by [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md) offset `+0x284`.
- The packet is opcode `0x1a`, selected slot byte, length `2`, sent through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- This class is part of the same command prompt family as [UID:0000FG][UseInputPane](by-class/UseInputPane.md) and [UID:0000EY][ThrowInputPane](by-class/ThrowInputPane.md).

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001ML][0x005b5890-0x005b60c0.ThrowUseEatInputPanes](by-memory/0x005b5890-0x005b60c0.ThrowUseEatInputPanes.md)
- [UID:0000FG][UseInputPane](by-class/UseInputPane.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/86`.
  - Summary/evidence: item prompt role, constructor/key/confirm methods, slot conversion, packet opcode, vtable stores, global dependencies, and item-action family links are documented; remaining work is mostly final field/local naming.
