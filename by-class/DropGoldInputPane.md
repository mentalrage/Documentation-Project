*** UID:000043 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DropGoldInputPane

## Status

- Confidence: strong for submit behavior, raw constructor bytes, and vtable identity; medium for raw-constructor reachability/modeling.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address ranges: raw constructor [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md), aggregate methods [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_DropGoldInputPane.cpp`

## Class Purpose

`DropGoldInputPane` is the numeric prompt used after the drop command selects gold. It parses a decimal amount and sends a five-byte drop-gold packet if the player is not in the cash-shop busy state.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `DropGoldInputPane` | `0x005b4b70-0x005b4bb0` | Raw constructor-shaped body; IDA does not recognize this as a function start. |
| `OnSubmitGoldAmount` | `0x005b4bb0-0x005b4c4a` | Reads numeric text, parses `%u`, gates on player/client-state busy byte `+0x3ec0`, writes opcode `0x24`, writes amount big-endian, and queues packet length 5. |

## Evidence Notes

- IDA MCP confirms `0x005b4bb0` but reports no function at `0x005b4b70`.
- 2026-05-27 raw IDA disassembly confirms the constructor-shaped bytes at `0x005b4b70-0x005b4bb0`: localized prompt id `7`, `NumberInputPane` base construction, and vtable stores to `0x0062fea4`, `0x0062fef4`, and `0x0062ff24`.
- 2026-05-27 IDA decompilation of `0x005b4bb0` confirms the packet path uses [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / `dword_67A748` byte `+0x3ec0` as a busy gate and queues `[0x24, amount:u32be]` through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- This class is created from [UID:000044][DropInputPane](by-class/DropInputPane.md).

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MH][0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor](by-memory/0x005b4b70-0x005b4bb0.DropGoldInputPaneRawConstructor.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:000044][DropInputPane](by-class/DropInputPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `72/78`.
  - Summary/evidence: numeric prompt role, raw constructor bytes, submit method, busy gate, packet encoding, vtable identity, and creator relationship are documented; confidence stays below the other drop panes because constructor reachability/modeling remains raw.
