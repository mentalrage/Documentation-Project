*** UID:0000BS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RecordVector_4E57C0

## Status

- Confidence: strong for helper behavior, medium for final source artifact.
- Likely source artifact: [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md), consumed by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- Current generated file: `source-3/simroot_v2/class_RecordVector_4E57C0.cpp`
- Main documented function: [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md)

## Class Purpose

`RecordVector_4E57C0` is a generated helper owner for a vector insert primitive over fixed `0x28`-byte records. It performs the normal vector growth/relocation sequence: check maximum size, grow capacity by roughly 1.5x, allocate aligned storage for large blocks, copy ranges around the insertion point, free old storage, and update begin/end/capacity pointers.

## Method

| Address | Method | Role |
| --- | --- | --- |
| `0x004e57c0` | `Insert(position, value)` | Inserts one `0x28`-byte record into a vector triplet. |

## Ownership Notes

IDA caller checks show one direct call from `0x004e4c14` inside `NewHumanImageLib::RenderComposition`. Treat this as compiler/vector support for new-human composition records rather than a separately designed project class.

## Cross-References

- [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md)
- [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `68/76`.
  - Before: The page was unevaluated despite identifying the fixed-record vector insert helper, record size, growth behavior, and only known caller.
  - After: Scored as moderate completion with medium-high confidence because the helper behavior is understood but the final source artifact remains compiler/vector support rather than a true product class.
  - Evidence: Existing purpose, method, ownership notes, and memory/file cross-references establish helper behavior and migration ownership caveats.
