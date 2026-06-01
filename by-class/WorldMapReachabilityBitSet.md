*** UID:0000GA | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WorldMapReachabilityBitSet

## Status

- Confidence: strong for helper behavior, medium for final original name.
- Likely source file: [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- Address range: [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md)
- Current recovered file: `source-3/simroot_v2/class_WorldMapReachabilityBitSet.cpp`

## Class Purpose

`WorldMapReachabilityBitSet` is a private dynamic bitset used by `WorldMapPane::BuildReachabilityData`. It stores reachability flags while scanning the world-map graph from the current node.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `InsertBits` | `0x005c56a0-0x005c584a` | Inserts a run of bits and returns the iterator just past the inserted range. |
| `MoveBitRange` | `0x005c5b20-0x005c5c87` | Compacts a source bit range onto a destination range and shrinks the bitset to the copied tail. |

## Evidence Notes

- IDA MCP confirms `0x005c56a0-0x005c584b` and shows `BuildReachabilityData` calling it.
- Wave3 notes describe a 16-byte storage object with begin/end/capacity pointers plus a bit-count field.
- This is private world-map route-state infrastructure and should migrate with [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md).

## Cross-References

- [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md)
- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:74` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the private reachability-bitset purpose, insert/move helper mapping, `BuildReachabilityData` caller evidence, storage-layout note, and final-name caveat.
