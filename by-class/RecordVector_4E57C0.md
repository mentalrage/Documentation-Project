*** UID:0000BS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RecordVector_4E57C0

## Status

- Confidence: strong for helper behavior and utility-parent placement, medium-high for final template/header source shape.
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

[UID:0000P3][VectorHelpers](by-file/VectorHelpers.md), [UID:0001QA][client_containers](by-meta/client_containers.md), and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) all classify this as reusable `util/VectorHelpers.h`-style support. [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) keeps the composition-record behavior local to the render module while this helper page covers the generic insert primitive.

## Evidence Notes

- [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md) records the exact function range, `0x28`-byte element size, vector-growth behavior, and single caller at `0x004e4c14`.
- [UID:00017R][0x004dfd10-0x004e68a7.NewHumanImageLib](by-memory/0x004dfd10-0x004e68a7.NewHumanImageLib.md) and [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) identify the caller as `RenderComposition`, not a standalone feature class.
- [UID:00022R][0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers](by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md) records `CopyRecordVector40Range` at `0x004e6ff0-0x004e7026`, called twice by this insert helper.
- The older by-memory report records a 2026-03-22 Wave2/IDA recheck for the single executable caller and the fixed-record insert behavior; treat it as supporting history, with current durable docs carrying the actionable evidence.

## Reconstruction Notes

- Marked reconstructable and attached to [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) because both the helper class and parent file now have confidence above 80.
- Rebuild handling is source-declared/helper-template support. This is not a product-domain class and should not be promoted to a feature source module.
- `RECONSTRUCTION_CPP CODE` stays blank because final names for the `0x28`-byte composition record, vector template shape, allocation helpers, and source header/implementation split are not at the 95+ code gate.

## Cross-References

- [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md)
- [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:00017R][0x004dfd10-0x004e68a7.NewHumanImageLib](by-memory/0x004dfd10-0x004e68a7.NewHumanImageLib.md)
- [UID:00022R][0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers](by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `68/76`.
  - Before: The page was unevaluated despite identifying the fixed-record vector insert helper, record size, growth behavior, and only known caller.
  - After: Scored as moderate completion with medium-high confidence because the helper behavior is understood but the final source artifact remains compiler/vector support rather than a true product class.
  - Evidence: Existing purpose, method, ownership notes, and memory/file cross-references establish helper behavior and migration ownership caveats.
- 2026-06-02: Raised to `80/84`, set `RECONSTRUCTABLE:TRUE`, and attached parent [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md).
  - Evidence: the parent file now has `82` confidence and a `NexusTK/util/` projection; exact memory docs identify the single `RenderComposition` caller, fixed `0x28` record insert behavior, and copy helper dependencies. C++ remains blank because the final record/type names and template/header split are unresolved.
