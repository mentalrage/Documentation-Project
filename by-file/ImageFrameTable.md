*** UID:0000K1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ImageFrameTable

## Status

- Confidence: strong for the shared `LoadImageFrameTable` owner, medium for the final filename and helper type names.
- Proposed module: `render/ImageFrameTable.cpp`
- Current recovered sources: `source-3/simroot_v2/recovered/LoadImageFrameTable_004D0F50.cpp` and `LoadFrameDrawRecord_004D1600.cpp`
- Evidence basis: Wave3 global/file summaries, generated recovered source, existing EPF resource docs, and targeted IDA MCP boundary/caller/callee checks on 2026-05-23.

## File Role

This file should own the generic frame-table helper used by old human/equipment, riding, static object, UI/effect, and related image resources. It converts DAT-backed EPF/EPD table records into in-memory frame metadata and exposes a small helper for extracting one draw record.

It should not own raw DAT archive indexing. `DATFile` and [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) are dependencies from the archive layer. Asset-specific one-caller table builders such as `LoadTileEpfMetadata`, `BuildTilecArchiveTable`, and `BuildEffectArchiveTable` should remain with their owning image-library files unless later evidence proves a common original source file for all EPF table builders.

## Proposed Contents

| Entity | Range | Proposed placement | Notes |
| --- | --- | --- | --- |
| [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md) / [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md) | `0x004d0f50-0x004d15c5` | `render/ImageFrameTable.cpp` | Loads one EPF/EPD frame table or merges numbered archive shards. |
| [UID:0002P5][0x004d15d0-0x004d15fc.DestroyOwnedImageBlock](by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md) | `0x004d15d0-0x004d15fc` | under review | Shared nested-payload cleanup helper adjacent to the frame-table helpers; final source-file parent remains open. |
| [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md) / [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md) | `0x004d1600-0x004d165d` | `render/ImageFrameTable.cpp` | Extracts one draw/metrics record from a frame metadata table. |
| [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md) | structure documentation | `render/ImageFrameTable.h` or private structs | Shared table/record shape used by several EPF/EPD loaders. |

## Exact Ranges

IDA MCP confirms:

- `0x004d0f50-0x004d15c5` for `LoadImageFrameTable_4D0F50`.
- `0x004d15d0-0x004d15fc` for `DestroyOwnedImageBlock_4D15D0`; this is adjacent helper cleanup code, but final source-file parent remains open.
- `0x004d1600-0x004d165d` for `LoadFrameDrawRecord_4D1600`.

The helper file is non-contiguous in the binary because other `ResourceLayoutTable` and image-library functions live between or around these ranges.

## Evidence

- Wave3 `show global 0x004d0f50 --summary` reports signature `FrameRecordTable_4D1600* __stdcall LoadImageFrameTable_4D0F50(const wchar_t* resourcePath, int mergeMode)` and summary "Loads a FrameRecordTable from one DAT/EPF archive or merges numbered archive shards into one shared frame table."
- Wave3 `show global 0x004d1600 --summary` identifies `LoadFrameDrawRecord_4D1600` as a recovered global with signature `void __stdcall LoadFrameDrawRecord_4D1600(const FrameRecordTable_4D1600* table, int frameIndex, FrameDrawRecord_4D1600* outRecord)`.
- IDA MCP caller checks find eight caller functions for `LoadImageFrameTable_4D0F50`, including `HumanImageLib`, `RidingImageLib`, `StaticObjImageLib`, and UI/effect frame users.
- IDA MCP caller checks find ten caller functions for `LoadFrameDrawRecord_4D1600`, spanning map tile draw, static/effect/item/new-human draw paths, and UI/effect frame users.
- IDA MCP callee checks show `LoadImageFrameTable_4D0F50` calls `DATFile` constructor/open/read/seek/close/destructor, `DATFile::GetDataPointer`, [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), allocation/free helpers, and rect initialization.
- `LoadFrameDrawRecord_4D1600` has no project callees; it is a pure table extraction helper over already-loaded frame records.

## Ownership Decision

Group `LoadImageFrameTable_4D0F50`, `LoadFrameDrawRecord_4D1600`, and the shared frame-table structure notes together as `render/ImageFrameTable.cpp`. The current one-global recovered files are Wave3 staging containers.

Keep these related helpers outside this file for now:

- [UID:0000V0][LoadTileEpfMetadata_004D1B80](by-item/LoadTileEpfMetadata_004D1B80.md), owned by [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md).
- [UID:0000U6][BuildTilecArchiveTable_004DDA60](by-item/BuildTilecArchiveTable_004DDA60.md), owned by [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) unless shared-table consolidation is later proven.
- [UID:0000U4][BuildEffectArchiveTable_004DE420](by-item/BuildEffectArchiveTable_004DE420.md), owned by [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) unless shared-table consolidation is later proven.
- [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md), owned by [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md).

## Open Questions

- Confirm the original name of the table type currently recovered as `FrameRecordTable_4D1600`.
- Confirm whether `LoadFrameDrawRecord_4D1600` was a private static helper in the same file or a small exported utility used by multiple render modules.
- Review `LoadImageFrameTable_4D0F50` in a rewrite pass to replace synthetic `reserved` fields and generic allocator/free names with source-level names.

## Cross-References

- [UID:000176][0x004d0f50-0x004d165d.ImageFrameTable](by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md)
- [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md)
- [UID:0002P5][0x004d15d0-0x004d15fc.DestroyOwnedImageBlock](by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md)
- [UID:0002P6][0x004d1600-0x004d165d.LoadFrameDrawRecord](by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md)
- [UID:0000UY][LoadImageFrameTable_004D0F50](by-item/LoadImageFrameTable_004D0F50.md)
- [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md)
- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:82`.
  - Summary/evidence: shared frame-table helper ownership, exact ranges, caller/callee evidence, DAT/resource dependencies, excluded adjacent helpers, open questions, and cross-references are documented; confidence is capped by final filename and unresolved table/helper type names.

- 2026-06-01 reconstruction path and adjacent cleanup helper update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, and the `0x004d15d0-0x004d15fc` helper between the two frame-table functions was not listed in this page.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`, and [UID:0002P5][0x004d15d0-0x004d15fc.DestroyOwnedImageBlock](by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md) is recorded as an adjacent source-authored cleanup helper under source-placement review.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` already lists `render/ImageFrameTable.cpp`; IDA MCP `lookup_funcs` and decompilation on 2026-06-01 confirm `0x004d15d0-0x004d15fc` is a real nested-payload cleanup function between the two frame-table helpers.
