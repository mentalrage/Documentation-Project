*** UID:0000TO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# VectorGrowMotion

## Status

- Symbol kind: global/helper function.
- Address range: [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md)
- Proposed owner module: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- Confidence: strong for owner and role.

## Role

`VectorGrowMotion` grows and inserts records in the `Motion.tbl` entry vector used by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). It manipulates fixed-size `0x42` byte motion records and follows MSVC vector growth/allocation behavior.

This helper is not a [UID:00008R][Motion](by-class/Motion.md) class method. The name refers to `Motion.tbl` data records in the new human image library.

## Evidence

- IDA MCP callers on 2026-05-24 show the only executable caller is `NewHumanImageLib::LoadMotionTable` at `0x004e0e20`.
- Older Wave2 notes restored this as an imported global after retiring a stale `NewHumanImageLibTable_4E5240` missing-class projection.
- `source-3/simroot_v2/recovered/VectorGrowMotion_004E5240.cpp` models `MotionEntry` as a packed 0x42-byte record and a three-pointer vector.

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:00017T][0x004e5240-0x004e5415.VectorGrowMotion](by-memory/0x004e5240-0x004e5415.VectorGrowMotion.md)
- [UID:0001RI][new-human-motion-tables](by-resource/new-human-motion-tables.md)
- [UID:0000LL][Motion](by-file/Motion.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `82/84`. Summary/evidence: the page documents the helper range, owner, role, IDA caller evidence, stale-name correction, and resource/file refs; the page is short because the helper itself is narrow.
