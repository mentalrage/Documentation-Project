*** UID:0000G0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WearInputPane

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001MT][0x005b6560-0x005b6760.WearInputPane](by-memory/0x005b6560-0x005b6760.WearInputPane.md)
- Current recovered file: `source-3/simroot_v2/class_WearInputPane.cpp`

## Class Purpose

`WearInputPane` is the equipment-wear prompt. It accepts one inventory slot letter, validates the slot against the local inventory count, and sends the wear packet.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `WearInputPane` | `0x005b6560-0x005b6627` | Constructs the prompt with player name and installs vtables. |
| `OnKeyEvent` | `0x005b6630-0x005b669c` | Handles help-panel shortcut and delegates normal input. |
| `OnSubmitInput` | `0x005b66a0-0x005b6760` | Converts slot letter and sends wear opcode `0x1e`. |

## Evidence Notes

- Wave3 generated source shows packet opcode `0x1e`.
- IDA MCP confirms all three function starts.
- IDA MCP recheck on 2026-05-26 resolves neighboring real function `0x005b6500-0x005b6560` as [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md)'s packet helper. `WearInputPane` starts at `0x005b6560`.
- IDA MCP recheck on 2026-05-27 confirms the constructor uses prompt id `0x21`, calls `CharInputPane::CharInputPane`, gets the local player name from `dword_67A748`, formats the prompt, and installs vtables `0x00630534`, `0x00630584`, and `0x006305b4`.
- IDA decompilation of `0x005b66a0` confirms slot conversion: lowercase `a-z` becomes `1-26`, uppercase `A-Z` becomes `27-52`, and the accepted value must be between `1` and byte offset `+0x284` from [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md).
- The submit path sends opcode `0x1e`, selector byte, and length `2` through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). Current generated source has placeholder comments for the slot-index formulas; use the IDA formulas above for reconstruction.

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MT][0x005b6560-0x005b6760.WearInputPane](by-memory/0x005b6560-0x005b6760.WearInputPane.md)
- [UID:0000G4][WieldInputPane](by-class/WieldInputPane.md)
- [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:90`.
  - Summary/evidence: scored from the constructor/key/submit method map, IDA-confirmed prompt id, vtables, slot conversion bounds, opcode `0x1e` send path, and item-action input grouping.
