*** UID:0000P3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# VectorHelpers

## Status

- Confidence: strong for utility-folder ownership and generated-helper interpretation; medium-high for exact original header/source split.
- Proposed source artifact: `NexusTK/util/VectorHelpers.h` or compiler-emitted template support folded into owner modules.
- Covered generated classes: [UID:0000FD][UInt32Vector](by-class/UInt32Vector.md), [UID:0000BS][RecordVector_4E57C0](by-class/RecordVector_4E57C0.md)

## File Role

This page groups vector-like helper artifacts that are source-structure relevant but do not look like feature classes. `UInt32Vector` is a dynamic `uint32_t` vector/fill helper used by map and world-map code. `RecordVector_4E57C0` is a fixed `0x28`-byte record vector insert helper used inside `NewHumanImageLib::RenderComposition`.

The generated class names are conservative helper buckets. Final source may keep these as utility template helpers, inline compiler output, or owner-local `std::vector` support rather than hand-written `UInt32Vector.cpp` and `RecordVector_4E57C0.cpp` files.

The validator projection is `NexusTK/util/`, matching [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md). The proposed tree names `VectorHelpers.h` rather than a guaranteed standalone `.cpp`; keep the generated `VectorHelpers.cpp` placeholder empty until final source shape proves a real implementation file.

## Covered Helpers

| Helper | Address evidence | Current owner evidence |
| --- | --- | --- |
| `UInt32Vector` fill constructor | `0x00514a10-0x00514ab6` | Called by `MapPane::HandleObjectCreatePacket` and `WorldMapPane::BuildReachabilityData`. |
| `UInt32Vector` insert/copy helpers | `0x00420de0`, `0x00421290`, `0x00437710` | Broad render/map/minimap callers in by-memory report; still helper-level. |
| `RecordVector_4E57C0::Insert` | `0x004e57c0-0x004e5989` | Only direct caller found at `0x004e4c14` inside `NewHumanImageLib::RenderComposition`. |
| `ImageLibVectorSupportHelpers` | [UID:00022R][0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers](by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md) | Image-library/vector helper island called from HumanImageLib, NewHumanImageLib, record-vector, and image decode wrapper paths. |

## Source-Structure Decision

Do not promote the generated names directly into feature folders. Use this page to keep vector helper evidence visible while owner files such as [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md), [UID:0000L3][MapPane](by-file/MapPane.md), and [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) document why they consume the helpers.

## Evidence Notes

- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) places `VectorHelpers.h` under `util/` with the other reusable container/template helpers and explicitly lists `UInt32Vector` plus `RecordVector_4E57C0`.
- [UID:0001QA][client_containers](by-meta/client_containers.md) tracks `VectorHelpers` as reusable collection/allocation support rather than feature code.
- [UID:0000FD][UInt32Vector](by-class/UInt32Vector.md) documents the dword-vector constructor, map/world-map callers, and why it should stay shared utility support.
- [UID:0000BS][RecordVector_4E57C0](by-class/RecordVector_4E57C0.md) documents the fixed-record insert helper and its single `NewHumanImageLib::RenderComposition` caller.
- [UID:00022R][0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers](by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md) records adjacent image-library vector helper code and cautions against using generated output as final ownership proof.

## Reconstruction Notes

- Rebuild handling: source-declared template/header support plus source-authored emitted helper bodies for concrete instantiations that the compiler does not reproduce automatically from the recovered declarations.
- Child classes may attach here once their own confidence is above 80, but generated C++ should stay blank until the final template/header shape and concrete record names are near-final.
- Final source may remain primarily header-driven. The validator-created `.cpp` placeholder is a staging artifact, not proof that the original project had a standalone `VectorHelpers.cpp`.

## Cross-References

- [UID:0000FD][UInt32Vector](by-class/UInt32Vector.md)
- [UID:0000BS][RecordVector_4E57C0](by-class/RecordVector_4E57C0.md)
- [UID:0001B2][0x00514a10-0x00514ab6.UInt32VectorConstructor](by-memory/0x00514a10-0x00514ab6.UInt32VectorConstructor.md)
- [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md)
- [UID:00022R][0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers](by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/74`. Summary/evidence: the page identifies the vector-helper source-structure role, class/global refs, and likely ownership boundaries, but these are template/compiler-support artifacts and not a clean original standalone source module.
- 2026-06-02: Changed `PROPOSED_RECONSTRUCTION_PATH` from blank to `NexusTK/util/` and raised completion/confidence from `78/74` to `82/82`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already places `VectorHelpers.h` under `util/`; [UID:0001QA][client_containers](by-meta/client_containers.md) models it as reusable container support; [UID:0000FD][UInt32Vector](by-class/UInt32Vector.md), [UID:0000BS][RecordVector_4E57C0](by-class/RecordVector_4E57C0.md), and [UID:00022R][0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers](by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md) document concrete helper evidence and unresolved final-source caveats.
