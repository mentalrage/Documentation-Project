*** UID:0000FD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
| `0x00420de0` | pointer-vector insert helper | Older reports classified this as a `UInt32Vector` insert helper; the newer fitting-room helper-island page shows it is 4-byte pointer-vector/template support with fitting-room and non-fitting-room callers. |
| `0x00421290` | pointer-vector copy helper | Older reports classified this as a `UInt32Vector` family helper; current evidence shows three-pointer vector-header copy/construct behavior with mixed callers. |
| `0x00437710` | insert helper | Broad caller helper used by render/minimap/map paths. |

## Ownership Notes

IDA caller checks for the fill constructor show calls from `MapPane::HandleObjectCreatePacket` and `WorldMapPane::BuildReachabilityData`. Keep this as shared vector support; the feature files own the algorithms that consume the temporary bitsets.

[UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) both model this as reusable `util/VectorHelpers.h`-style support rather than a feature-owned `MapPane` or `WorldMapPane` class. This page now attaches to `VectorHelpers` because the parent file has a validated `NexusTK/util/` projection and confidence above 80; final generated code remains blank.

## Evidence Notes

- [UID:0001B2][0x00514a10-0x00514ab6.UInt32VectorConstructor](by-memory/0x00514a10-0x00514ab6.UInt32VectorConstructor.md) records the exact `0xa7` byte constructor, caller xrefs from `0x00511db0` and `0x005c4bd0`, and the fill behavior over contiguous dword storage.
- [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md), and their memory pages all treat this as temporary dword-vector/bitset support consumed by map/world-map algorithms.
- [UID:0002DR][0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers](by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md) refines earlier `UInt32Vector` helper classifications: `0x00420de0` and `0x00421290` are shared 4-byte pointer-vector helpers in a mixed fitting-room/helper island, not proof of a clean standalone `UInt32Vector.cpp`.
- The older by-memory report still records `0x00437710` as a broad `UInt32Vector`-style insert helper, but this page should not treat that as final source ownership until a focused helper pass verifies callers and element type.

## Autogen Status

- Reconstructable: true for the constructor and generic vector-support role.
- Parent: [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md), now above the documented child-attachment threshold.
- Code: intentionally blank. The constructor behavior is clear, but final source likely came from a template/header instantiation, and emitting handwritten C++ would overstate the recovered artifact.

## Score Rationale

- Completion is raised to 76 because exact constructor behavior, key consumers, source-structure placement, and mixed-helper boundaries are now documented.
- Confidence is raised to 82 for the class-level interpretation because the fill constructor and utility ownership are corroborated across by-memory, by-file, by-meta, and by-project-structure pages.
- The score remains below final-source quality because helper names at `0x00437710` and the exact original template/header placement remain unresolved.

## Cross-References

- [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md)
- [UID:0001B2][0x00514a10-0x00514ab6.UInt32VectorConstructor](by-memory/0x00514a10-0x00514ab6.UInt32VectorConstructor.md)
- [UID:0002DR][0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers](by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:70` and `CONFIDENCE:72`.
  - Summary/evidence: scored from the fill-constructor behavior, documented helper addresses, caller checks, and shared vector-support placement; score remains limited because only the constructor is strongly detailed here while the helper family still relies on earlier by-memory classification.
- 2026-06-02: Raised to `76/82`, marked reconstructable, and added source-structure, helper-island, and scoring rationale evidence. Parent remains blank because `VectorHelpers` is still provisional and below the child-attachment confidence threshold.
- 2026-06-02: Attached parent [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) after that file reached `82` confidence and a valid `NexusTK/util/` projection. C++ remains blank because final template/header shape is unresolved.
