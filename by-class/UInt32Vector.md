*** UID:0000FD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UInt32Vector

## Status

- Confidence: strong for constructor behavior, medium for final source artifact.
- Likely source artifact: [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md)
- Current generated file: `source-3/simroot_v2/class_UInt32Vector.cpp`
- Main documented function: [UID:0001B2][0x00514a10-0x00514ab6.UInt32VectorConstructor](by-memory/0x00514a10-0x00514ab6.UInt32VectorConstructor.md)

## Class Purpose

`UInt32Vector` is a vector-like helper over contiguous `uint32_t` storage. The active generated class emits a fill constructor that allocates `count` dwords, sets `begin/end/capacityEnd`, and fills every element from the supplied value pointer.

## Method Notes

| Address | Method | Role |
| --- | --- | --- |
| `0x00514a10` | fill constructor | Allocates `count` dwords and fills them with one `uint32_t` value. |
| `0x00420de0` | insert helper | Earlier by-memory report classifies this as a `UInt32Vector` insert helper. |
| `0x00421290` | range/copy helper | Earlier by-memory report classifies this as a `UInt32Vector` family helper. |
| `0x00437710` | insert helper | Broad caller helper used by render/minimap/map paths. |

## Ownership Notes

IDA caller checks for the fill constructor show calls from `MapPane::HandleObjectCreatePacket` and `WorldMapPane::BuildReachabilityData`. Keep this as shared vector support; the feature files own the algorithms that consume the temporary bitsets.

## Cross-References

- [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md)
- [UID:0001B2][0x00514a10-0x00514ab6.UInt32VectorConstructor](by-memory/0x00514a10-0x00514ab6.UInt32VectorConstructor.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:70` and `CONFIDENCE:72`.
  - Summary/evidence: scored from the fill-constructor behavior, documented helper addresses, caller checks, and shared vector-support placement; score remains limited because only the constructor is strongly detailed here while the helper family still relies on earlier by-memory classification.
