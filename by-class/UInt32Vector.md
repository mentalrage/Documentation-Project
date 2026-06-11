*** UID:0000FD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# UInt32Vector

## Status

- Confidence: strong for constructor behavior, shared vector-helper ownership, and the broad dword insert helper identity; medium-high for the final source artifact because the original template/header shape is not recovered.
- Likely source artifact: [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md)
- Current generated file: `source-3/simroot_v2/class_UInt32Vector.cpp`
- Main documented function: [UID:0001B2][0x00514a10-0x00514ab6.UInt32VectorConstructor](by-memory/0x00514a10-0x00514ab6.UInt32VectorConstructor.md)
- Autogen parent: intentionally blank under the strict 85/85 gate. [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) clears `86/86`, but this class remains `82/86`, so the source attachment is withheld until the class itself reaches the gate.

## Class Purpose

`UInt32Vector` is a vector-like helper over contiguous `uint32_t` storage. The active generated class emits a fill constructor that allocates `count` dwords, sets `begin/end/capacityEnd`, and fills every element from the supplied value pointer.

## Method Notes

| Address | Method | Role |
| --- | --- | --- |
| `0x00514a10` | fill constructor | Allocates `count` dwords and fills them with one `uint32_t` value. |
| `0x00420de0` | pointer-vector insert helper | Older reports classified this as a `UInt32Vector` insert helper; the newer fitting-room helper-island page shows it is 4-byte pointer-vector/template support with fitting-room and non-fitting-room callers. |
| `0x00421290` | pointer-vector copy helper | Older reports classified this as a `UInt32Vector` family helper; current evidence shows three-pointer vector-header copy/construct behavior with mixed callers. |
| `0x00437710-0x00437869` | dword insert/grow helper | 2026-06-10 IDA confirms a modeled 0x159-byte body that inserts one dword into a three-pointer vector, grows capacity by 1.5x, preserves prefix/suffix with `memmove`, handles 0x20-aligned large allocations, frees old storage, and returns the inserted element address. Callers span JsonCpp/readers, MiniMap, dialog, and MapPane paths, so this is shared vector/template support rather than a feature-local method. |

## Ownership Notes

IDA caller checks for the fill constructor show calls from `MapPane::HandleObjectCreatePacket` and `WorldMapPane::BuildReachabilityData`. Keep this as shared vector support; the feature files own the algorithms that consume the temporary bitsets.

[UID:0000P3][VectorHelpers](by-file/VectorHelpers.md) and [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) both model this as reusable `util/VectorHelpers.h`-style support rather than a feature-owned `MapPane` or `WorldMapPane` class. This page now attaches to `VectorHelpers` because the parent file has a validated `NexusTK/util/` projection and confidence above 80; final generated code remains blank.

The semantic owner remains [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md), but `AUTOGEN_PARENT_UID` is blank until this class reaches `85/85`. The exact constructor child is likewise below 85 completion and should stay parent-blank under the current gate.

## Evidence Notes

- [UID:0001B2][0x00514a10-0x00514ab6.UInt32VectorConstructor](by-memory/0x00514a10-0x00514ab6.UInt32VectorConstructor.md) records the exact `0xa7` byte constructor, caller xrefs from `0x00511db0` and `0x005c4bd0`, and the fill behavior over contiguous dword storage.
- [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md), and their memory pages all treat this as temporary dword-vector/bitset support consumed by map/world-map algorithms.
- [UID:0002DR][0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers](by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md) refines earlier `UInt32Vector` helper classifications: `0x00420de0` and `0x00421290` are shared 4-byte pointer-vector helpers in a mixed fitting-room/helper island, not proof of a clean standalone `UInt32Vector.cpp`.
- 2026-06-10 IDA MCP recheck:
  - `lookup_funcs` reports `sub_514A10` at `0x00514a10-0x00514ab7` and `sub_437710` at `0x00437710-0x00437869`.
  - `callers 0x00514a10` returns two call sites inside `sub_511DB0` at `0x00511f00` and `sub_5C4BD0` at `0x005c4df3`, matching map/world-map temporary vector consumers.
  - `decompile 0x00514a10` confirms the three-pointer vector header clear, overflow guard at `0x3fffffff`, small/large allocation split at 0x1000 bytes, 0x20-aligned large allocation with stored raw pointer, fill loop from `*a3`, and end/capacity pointer updates.
  - `callers 0x00437710` returns 16 call sites from `sub_428D70`, `sub_4523D0`, `sub_49C800`, and `sub_50B2B0`, proving the insert helper is shared across JsonCpp/MiniMap/dialog/map paths instead of being a clean `UInt32Vector`-only method.
  - `decompile 0x00437710` confirms a 4-byte-element vector insert/grow helper with 1.5x capacity growth, prefix/suffix `memmove`, old-storage free via `0x005c7526`, and the same large-allocation validation pattern as the fill constructor.

## Autogen Status

- Reconstructable: true for the constructor and generic vector-support role.
- Parent: blank in validator metadata until this class reaches the strict 85/85 gate; the intended semantic owner remains [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md).
- Code: intentionally blank. The constructor behavior is clear, but final source likely came from a template/header instantiation, and emitting handwritten C++ would overstate the recovered artifact.

## Score Rationale

- Completion is raised to 82 because exact constructor behavior, live caller/callee/decompile evidence, the broad dword insert helper, key consumers, source-structure placement, and mixed-helper boundaries are now documented.
- Confidence is raised to 86 for the class-level interpretation because the fill constructor, shared 4-byte insert helper, and utility ownership are corroborated across by-memory, by-file, by-meta, by-project-structure, and live IDA evidence.
- The score remains below the strict assignment gate and final-source quality because concrete template declarations, final source spelling, and the exact relationship between the generated `UInt32Vector` bucket and broader 4-byte vector helpers remain unresolved.

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
- 2026-06-10 strict-gate and helper recheck:
  - What existed before: the page was scored `76/82`, attached to [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md), and still treated `0x00437710` as an unresolved older helper classification.
  - Changed to: raised the page to `82/86`, cleared `AUTOGEN_PARENT_UID` under the strict 85/85 gate, and documented live IDA evidence for both `0x00514a10` and `0x00437710`.
  - Summary/evidence: IDA MCP confirms the fill constructor, two map/world-map constructor callers, the 16-call-site shared dword insert helper, allocation/free/growth behavior, and why `VectorHelpers` remains the intended semantic owner even though validator attachment is withheld.
