*** UID:0000P3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/util/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# VectorHelpers

## Status

- Confidence: strong for utility-folder ownership, reusable container-helper grouping, and direct static helper children including the exact pointer-vector helpers split from `0x00420de0-0x00421301`; medium-high for exact original header/source split.
- Proposed source artifact: `NexusTK/util/VectorHelpers.h` or compiler-emitted template support folded into owner modules.
- Covered generated classes: [UID:0000FD][UInt32Vector](by-class/UInt32Vector.md), [UID:0000BS][RecordVector_4E57C0](by-class/RecordVector_4E57C0.md)
- Parent gate: this page now clears the corrected 85/85 gate for exact helper children such as [UID:0002UD][0x00423810-0x00423860.VectorStorageFreeHelper](by-memory/0x00423810-0x00423860.VectorStorageFreeHelper.md).

## File Role

This page groups vector-like helper artifacts that are source-structure relevant but do not look like feature classes. `UInt32Vector` is a dynamic `uint32_t` vector/fill helper used by map and world-map code. `RecordVector_4E57C0` is a fixed `0x28`-byte record vector insert helper used inside `NewHumanImageLib::RenderComposition`.

The generated class names are conservative helper buckets. Final source may keep these as utility template helpers, inline compiler output, or owner-local `std::vector` support rather than hand-written `UInt32Vector.cpp` and `RecordVector_4E57C0.cpp` files.

The validator projection is `NexusTK/util/`, matching [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md). The proposed tree names `VectorHelpers.h` rather than a guaranteed standalone `.cpp`; keep the generated `VectorHelpers.cpp` placeholder empty until final source shape proves a real implementation file.

## Covered Helpers

| Helper | Address evidence | Current owner evidence |
| --- | --- | --- |
| `UInt32Vector` fill constructor | `0x00514a10-0x00514ab6` | Called by `MapPane::HandleObjectCreatePacket` and `WorldMapPane::BuildReachabilityData`. |
| pointer-vector insert/copy helpers | [UID:00030Q][0x00420de0-0x00420eea.PointerVectorGrowInsert](by-memory/0x00420de0-0x00420eea.PointerVectorGrowInsert.md), [UID:00030Z][0x00421290-0x00421301.PointerVectorCopyConstruct](by-memory/0x00421290-0x00421301.PointerVectorCopyConstruct.md), `0x00437710` | Exact split children show 4-byte pointer-vector grow/copy behavior with fitting-room and non-fitting-room callers; still helper-level utility/template support rather than caller-owned feature code. |
| `VectorStorageFreeHelper` | [UID:0002UD][0x00423810-0x00423860.VectorStorageFreeHelper](by-memory/0x00423810-0x00423860.VectorStorageFreeHelper.md) | Shared vector-like storage cleanup; ordinary source calls are in `ItemCatalog::GetItemByIndex`, with broader handler/unwind metadata fan-in. |
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
- [UID:0002UD][0x00423810-0x00423860.VectorStorageFreeHelper](by-memory/0x00423810-0x00423860.VectorStorageFreeHelper.md) is attached here as reusable vector-storage cleanup support. Live IDA confirms direct calls from [UID:0000WV][0x00422690-0x0042273e.ItemCatalogLookup](by-memory/0x00422690-0x0042273e.ItemCatalogLookup.md), while existing docs record broader handler/unwind metadata fan-in that argues against a fitting-room-private parent.
- 2026-06-08 A002 Batch101 parent-source follow-up checked this page as the direct owner for [UID:00030Q][0x00420de0-0x00420eea.PointerVectorGrowInsert](by-memory/0x00420de0-0x00420eea.PointerVectorGrowInsert.md) and [UID:00030Z][0x00421290-0x00421301.PointerVectorCopyConstruct](by-memory/0x00421290-0x00421301.PointerVectorCopyConstruct.md). Both exact children clear `85/85` and both have non-fitting-room callers in addition to fitting-room uses, so this shared utility parent is more direct than [UID:0000JE][FittingRoom](by-file/FittingRoom.md) or [UID:000053][FittingRoomListPane](by-class/FittingRoomListPane.md). The mixed aggregate [UID:0002DR][0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers](by-memory/0x00420de0-0x00421301.FittingRoomSelectionVectorHelpers.md) remains unassigned because only these pointer-vector children route here.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `86` | The page now covers the utility role, proposed `NexusTK/util/` placement, existing vector classes, record-vector insert helper, image-library vector helper island, the exact `VectorStorageFreeHelper` child, the exact `00030Q`/`00030Z` pointer-vector children, and the reason the generated `.cpp` remains a placeholder for likely header/template support. Completion remains below final because concrete template declarations and final helper signatures are not yet source-quality. |
| Confidence `86` | Existing documentation and exact helper pages support this as the best shared container parent: `UInt32Vector` and `RecordVector_4E57C0` already route here, `VectorStorageFreeHelper` has ordinary ItemCatalog call sites plus broad unwind/handler fan-in, `00030Q`/`00030Z` have non-fitting-room caller evidence, and project structure places the utility under `NexusTK/util/`. Confidence stays capped by uncertainty about whether final source is header-only or a small helper implementation file. |

## Reconstruction Notes

- Rebuild handling: source-declared template/header support plus source-authored emitted helper bodies for concrete instantiations that the compiler does not reproduce automatically from the recovered declarations.
- Child classes and exact helper bodies may attach here once both child and parent clear the corrected 85/85 gate, but generated C++ should stay blank until the final template/header shape and concrete record names are near-final.
- Final source may remain primarily header-driven. The validator-created `.cpp` placeholder is a staging artifact, not proof that the original project had a standalone `VectorHelpers.cpp`.

## Cross-References

- [UID:0000FD][UInt32Vector](by-class/UInt32Vector.md)
- [UID:0000BS][RecordVector_4E57C0](by-class/RecordVector_4E57C0.md)
- [UID:0001B2][0x00514a10-0x00514ab6.UInt32VectorConstructor](by-memory/0x00514a10-0x00514ab6.UInt32VectorConstructor.md)
- [UID:00030Q][0x00420de0-0x00420eea.PointerVectorGrowInsert](by-memory/0x00420de0-0x00420eea.PointerVectorGrowInsert.md)
- [UID:00030Z][0x00421290-0x00421301.PointerVectorCopyConstruct](by-memory/0x00421290-0x00421301.PointerVectorCopyConstruct.md)
- [UID:0002UD][0x00423810-0x00423860.VectorStorageFreeHelper](by-memory/0x00423810-0x00423860.VectorStorageFreeHelper.md)
- [UID:00017U][0x004e57c0-0x004e5989.RecordVectorInsert](by-memory/0x004e57c0-0x004e5989.RecordVectorInsert.md)
- [UID:00022R][0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers](by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md)
- [UID:0001QA][client_containers](by-meta/client_containers.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-06-08 A002 Batch101 parent-source follow-up: Raised completion/confidence from `85/85` to `86/86` after adding exact pointer-vector child evidence for [UID:00030Q][0x00420de0-0x00420eea.PointerVectorGrowInsert](by-memory/0x00420de0-0x00420eea.PointerVectorGrowInsert.md) and [UID:00030Z][0x00421290-0x00421301.PointerVectorCopyConstruct](by-memory/0x00421290-0x00421301.PointerVectorCopyConstruct.md). Both children are `85/87`, both have fitting-room plus non-fitting-room callers, and both are better modeled as shared vector/template helper support than as direct fitting-room source. The score remains below final because the original header/source split is unresolved.
- 2026-06-07 Batch 067 parent-gate refresh:
  - Before: `COMPLETION:82`, `CONFIDENCE:82`, below the corrected direct-parent gate for [UID:0002UD][0x00423810-0x00423860.VectorStorageFreeHelper](by-memory/0x00423810-0x00423860.VectorStorageFreeHelper.md).
  - After: `COMPLETION:85`, `CONFIDENCE:85`.
  - Evidence: consolidated the exact VectorStorageFreeHelper child evidence, existing `UInt32Vector` and `RecordVector_4E57C0` child routes, image-library helper island, `client_containers` utility grouping, and `NexusTK/util/` projected placement. The page remains below final-source scoring because the utility may be primarily header/template support.
- 2026-06-07: Added [UID:0002UD][0x00423810-0x00423860.VectorStorageFreeHelper](by-memory/0x00423810-0x00423860.VectorStorageFreeHelper.md) as shared vector-storage cleanup support and accepted it as a child of this utility container parent. Evidence: live IDA `callers` finds ordinary `ItemCatalogLookup` call sites at `0x00422720` and `0x00422731`, while the target page records broad handler/unwind fan-in, so `VectorHelpers` is a better parent than fitting-room aggregate containment.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `78/74`. Summary/evidence: the page identifies the vector-helper source-structure role, class/global refs, and likely ownership boundaries, but these are template/compiler-support artifacts and not a clean original standalone source module.
- 2026-06-02: Changed `PROPOSED_RECONSTRUCTION_PATH` from blank to `NexusTK/util/` and raised completion/confidence from `78/74` to `82/82`.
  - Evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already places `VectorHelpers.h` under `util/`; [UID:0001QA][client_containers](by-meta/client_containers.md) models it as reusable container support; [UID:0000FD][UInt32Vector](by-class/UInt32Vector.md), [UID:0000BS][RecordVector_4E57C0](by-class/RecordVector_4E57C0.md), and [UID:00022R][0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers](by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md) document concrete helper evidence and unresolved final-source caveats.
