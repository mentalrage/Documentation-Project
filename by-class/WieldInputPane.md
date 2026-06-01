*** UID:0000G4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WieldInputPane

## Status

- Confidence: strong for behavior and item-action input module placement.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address range: [UID:0001MR][0x005b62d0-0x005b64fa.WieldInputPane](by-memory/0x005b62d0-0x005b64fa.WieldInputPane.md), helper [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md)
- Current recovered file: `source-3/simroot_v2/class_WieldInputPane.cpp`

## Class Purpose

`WieldInputPane` is the weapon-wield prompt. It accepts one inventory slot letter and sends the wield packet for the selected item slot. The `-` input is a confirmed zero-slot path that sends opcode `0x12` with selector `0`.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `WieldInputPane` | `0x005b62d0-0x005b6397` | Constructs the prompt with player name and installs vtables. |
| `OnCharInput` | `0x005b63a0-0x005b640c` | Handles help-panel shortcut and delegates normal input. |
| `OnSubmitInput` | `0x005b6410-0x005b64fa` | Converts slot letter and sends wield opcode `0x12`. |
| `SendWieldPacket` | `0x005b6500-0x005b6560` | Private helper called by `OnSubmitInput` after normal slot validation; writes opcode `0x12` and the selected slot byte. |

## Evidence Notes

- Wave3 generated source shows packet opcode `0x12`.
- IDA MCP confirms all three function starts.
- IDA MCP recheck on 2026-05-26 confirms `0x005b6500-0x005b6560` has a single caller inside `WieldInputPane::OnSubmitInput`, so it belongs with this class/module rather than [UID:0000G0][WearInputPane](by-class/WearInputPane.md).
- IDA MCP recheck on 2026-05-27 confirms the constructor uses prompt id `0x0d`, calls `CharInputPane::CharInputPane`, gets the local player name from `dword_67A748`, formats the prompt, and installs vtables `0x006304a8`, `0x006304f8`, and `0x00630528`.
- IDA decompilation of `0x005b6410` confirms slot conversion: lowercase `a-z` becomes `1-26`, uppercase `A-Z` becomes `27-52`, and the accepted value must be between `1` and byte offset `+0x284` from [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md).
- The normal validated slot path calls [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md); the `-` path sends opcode `0x12`, selector `0`, and length `2` inline through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MR][0x005b62d0-0x005b64fa.WieldInputPane](by-memory/0x005b62d0-0x005b64fa.WieldInputPane.md)
- [UID:0001MS][0x005b6500-0x005b6560.SendWieldPacket](by-memory/0x005b6500-0x005b6560.SendWieldPacket.md)
- [UID:0000PS][g_activeUserStatusPane](by-global/g_activeUserStatusPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000G0][WearInputPane](by-class/WearInputPane.md)
- [UID:0000EC][TakeOffInputPane](by-class/TakeOffInputPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:90`.
  - Summary/evidence: scored from the constructor/input/submit/private packet-helper method map, IDA-confirmed prompt id, vtables, slot conversion bounds, zero-slot `-` path, opcode `0x12` send behavior, and helper ownership evidence.
