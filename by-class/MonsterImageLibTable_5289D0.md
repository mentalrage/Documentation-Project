*** UID:00008O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MonsterImageLibTable_5289D0

## Status

- Confidence: strong for behavior and shared caller evidence, medium for final neutral class/struct name.
- Likely source file: [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- Address ranges: [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md)
- Current recovered file: `source-3/simroot_v2/class_MonsterImageLibTable_5289D0.cpp`

## Class Purpose

`MonsterImageLibTable_5289D0` is a small owner for nested animation/image table records. Wave3 describes it as a 12-byte helper that owns a heap array of 8-byte nested records plus a low-byte child count.

The current name is address-derived. Because both monster and riding parsers use it, a future rename should probably be neutral, such as an animation bucket/table helper, after field layout is reviewed.

## Evidence Notes

- Wave3 class summary reports 3 methods, effective grade `95.3`.
- IDA MCP on 2026-05-22 reports four caller sites: two in `MonsterImageLib::LoadMonsterTables` and two in `RidingImageLib::LoadRidingDefinitions`.
- 2026-05-26 IDA `py_eval` recheck confirms modeled starts for this outer helper family at `0x00528950`, `0x005289d0`, `0x00528a70`, `0x00528af0`, and `0x00528b10`, plus inner cleanup helper `0x00528b60`. No IDA names contain `MonsterImageLibTable`, so the address-derived class name should remain provisional.
- 2026-05-28 IDA MCP recheck adds the outer-table zero initializer at `0x00528930`; xrefs show direct setup callers and constructor-callback use by parser/allocation helpers.

## Cross-References

- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md)

## Changes

- Before: documented outer helper starts began at `0x00528950`.
- Changed to: include the `0x00528930` zero initializer in the outer helper family.
- Summary/evidence: 2026-05-28 IDA MCP xrefs tie `0x00528930` to direct setup calls and constructor-callback use from the same parser/allocation family.
- Completion/confidence score update: existed before as `0/0`; changed to `74/76`. Summary: the outer nested animation/image table helper has shared monster/riding caller evidence, method-start evidence, and initializer coverage, but its class name and final neutral struct/class model remain provisional. Evidence: linked `MonsterImageLibTables` range, IDA caller sites from `MonsterImageLib` and `RidingImageLib`, modeled start rechecks, no stable IDA names, and the 2026-05-28 zero-initializer xref update.
