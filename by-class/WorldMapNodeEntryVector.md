*** UID:0000G8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WorldMapNodeEntryVector

## Status

- Confidence: strong for helper behavior, medium for final original name.
- Likely source file: [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- Address range: [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md)
- Current recovered file: `source-3/simroot_v2/class_WorldMapNodeEntryVector.cpp`

## Class Purpose

`WorldMapNodeEntryVector` is private storage for 0x94-byte world-map node records copied from the world-map packet. It owns a dynamically allocated buffer and preserves the binary's aligned large-allocation behavior.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `~WorldMapNodeEntryVector` | `0x005c5510-0x005c5579` | Releases the node-entry buffer and clears vector state. |
| `Assign` | `0x005c58c0-0x005c5a8e` | Assigns repeated node-entry values across the vector, growing storage when needed. |

## Evidence Notes

- IDA MCP confirms `0x005c5510-0x005c557a` and shows callers from `WorldMapPane::~WorldMapPane` and constructor cleanup paths.
- Wave3 notes identify the entry size as 148 bytes (`0x94`).
- Treat the class name as descriptive until original type names are recovered.

## Cross-References

- [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md)
- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- [UID:0001O4][0x005c2ac0-0x005c5c87.WorldMapPane](by-memory/0x005c2ac0-0x005c5c87.WorldMapPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:74` and `CONFIDENCE:76`.
  - Summary/evidence: scored from the private vector purpose, destructor/assign method mapping, 0x94 entry-size evidence, caller evidence from `WorldMapPane`, and final-name caveat.
