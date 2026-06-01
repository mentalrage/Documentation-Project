*** UID:0000PK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DestroyMotionVector

## Status

- Symbol kind: global/helper function.
- Address range: [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md)
- Proposed owner module: [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- Confidence: strong for owner and role.

## Role

`DestroyMotionVector` releases the `Motion.tbl` entry vector used by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md). It handles small allocations directly and large aligned allocations through the stored allocation base pointer.

This helper is not a [UID:00008R][Motion](by-class/Motion.md) class method. The name refers to the new-human motion table vector.

## Evidence

- IDA MCP callers on 2026-05-24 show the only executable caller is the `NewHumanImageLib` cleanup/destructor path at `0x004e0250`.
- Older Wave2 notes restored this as an imported global helper with signature `DestroyMotionVector(MotionEntryVector* self)`.
- `source-3/simroot_v2/recovered/DestroyMotionVector_004E5DD0.cpp` clears begin/end/capacity after freeing storage.

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md)
- [UID:0001RI][new-human-motion-tables](by-resource/new-human-motion-tables.md)
- [UID:0000LL][Motion](by-file/Motion.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `78/84`.
  - Before: page documented helper role, owner, caller evidence, and vector-free behavior but remained unevaluated.
  - After: score reflects documented new-human motion-vector cleanup behavior and owner assignment, with remaining completion limited by compact type/layout detail.
  - Evidence: IDA caller notes tie the helper to `NewHumanImageLib` cleanup/destructor and generated source confirms free/reset semantics for begin/end/capacity storage.
