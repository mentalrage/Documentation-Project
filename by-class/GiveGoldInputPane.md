*** UID:00005T | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000KC | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GiveGoldInputPane

## Status

- Confidence: strong for submit behavior, raw constructor bytes, vtable identity, packet behavior, and item-action module placement; medium for raw-constructor reachability/modeling.
- Likely source file: [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- Address ranges: raw constructor [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md), aggregate methods [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- Current recovered file: `source-3/simroot_v2/class_GiveGoldInputPane.cpp`

## Class Purpose

`GiveGoldInputPane` is the numeric prompt used when the give command selects gold. It parses a decimal amount and sends a five-byte give-gold packet if the player is not in the cash-shop busy state.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GiveGoldInputPane` | `0x005b52b0-0x005b52f0` | Raw constructor-shaped body; IDA does not recognize this as a function start. |
| `OnSubmit` | `0x005b52f0-0x005b538a` | Reads numeric text, parses `%u`, gates on player/client-state busy byte `+0x3ec0`, writes opcode `0x2a`, writes amount big-endian, and queues packet length 5. |

## Evidence Notes

- IDA MCP confirms `0x005b52f0` but reports no function at `0x005b52b0`.
- 2026-05-27 raw IDA disassembly confirms the constructor-shaped bytes at `0x005b52b0-0x005b52f0`: localized prompt id `0x2b` / `43`, `NumberInputPane` base construction, and vtable stores to `0x00630048`, `0x00630098`, and `0x006300c8`.
- 2026-05-27 IDA decompilation of `0x005b52f0` confirms the packet path uses [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / `dword_67A748` byte `+0x3ec0` as a busy gate and queues `[0x2a, amount:u32be]` through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- This class is created from [UID:00005U][GiveInputPane](by-class/GiveInputPane.md).

## Cross-References

- [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md)
- [UID:0001XU][ItemActionInputPaneVtableFamily](by-type/by-vtable/ItemActionInputPaneVtableFamily.md)
- [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md)
- [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md)
- [UID:00005U][GiveInputPane](by-class/GiveInputPane.md)
- [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `72/78`. Summary: numeric give-gold behavior, packet format, busy gate, raw constructor bytes, vtable identity, and creation path are documented; confidence remains capped by raw-constructor reachability/modeling. Evidence: raw constructor page `0x005b52b0-0x005b52f0`, aggregate Drop/Give input page, IDA decompilation of `0x005b52f0`, and `g_pCollectionData`/`g_packetSender` cross-references.
- 2026-06-02 metadata/evidence refresh:
  - Before: page metadata left `RECONSTRUCTABLE` and `AUTOGEN_PARENT_UID` blank.
  - After: raised to `80/84`, marked reconstructable, and attached to [UID:0000KC][ItemActionInputPanes](by-file/ItemActionInputPanes.md).
  - Evidence: [UID:0001MI][0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor](by-memory/0x005b52b0-0x005b52f0.GiveGoldInputPaneRawConstructor.md) and [UID:0001MG][0x005b44b0-0x005b538a.DropGiveInputPanes](by-memory/0x005b44b0-0x005b538a.DropGiveInputPanes.md) now record refreshed constructor, submit, vtable, packet, and item-action ownership evidence.
