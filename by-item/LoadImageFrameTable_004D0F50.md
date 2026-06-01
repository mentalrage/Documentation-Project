*** UID:0000UY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LoadImageFrameTable 0x004D0F50

## Status

- Confidence: strong for behavior, medium for exact original function/type names.
- Entity kind: shared global helper.
- Current Wave3 owner file: `LoadImageFrameTable_004D0F50.cpp`
- Likely source module: [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- Exact range: `0x004d0f50-0x004d15c5`
- Canonical memory page: [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md)

## Behavior

`LoadImageFrameTable_4D0F50` loads frame metadata from a DAT-backed EPF/EPD resource. It supports two modes:

- `mergeMode == 0`: open the supplied resource path as one `DATFile` entry.
- `mergeMode != 0`: map the mode to a fixed archive prefix and merge numbered shards such as `HEAD0.EPF`, `HEAD1.EPF`, and so on until [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) fails.

Observed merge prefixes include `HEAD`, `HEADSP`, `BODY`, `SWORD`, `SPEAR`, `BOW`, `FAN`, `SHIELD`, `ARROW`, `FACE`, `HAIR`, `ACE1`, `ACE2`, `HELMET`, `MANTLE`, `NECLACE`, `SHOES`, and `COAT`.

For each source archive, the helper reads an 8-byte table header, reads a 4-byte record-table offset, gets the mapped payload base through `DATFile::GetDataPointer`, seeks to the record table, and reads 16-byte raw records into 24-byte in-memory records with absolute payload offsets. It appends a terminal zero-bounds sentinel.

## Call Evidence

Wave3 xrefs report 25 total call sites, grouped into eight caller functions/classes:

- [UID:0000JY][HumanImageLib](by-file/HumanImageLib.md) repeatedly calls this helper for old body/equipment part tables such as `HEAD`, `BODY`, `SWORD`, `FACE`, `HAIR`, `HELMET`, `MANTLE`, `SHOES`, and `COAT`.
- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md) calls it for `RIDINGS.EPF` mount/riding sprites.
- `StaticObjImageLib` calls it for static-object frame data.
- `ScrolledPictureControlPane`, `OverlayFrameImageEffecter`, `OverlayImageOnPointEffecter`, `OverlayMovingImageEffecter`, and `WaterFilterEffecter` use it for UI/effect image resources.

IDA/Wave3 callees include `DATFile`, `DATFile::Open`, `DATFile::Read`, `DATFile::Seek`, `DATFile::Close`, `DATFile::GetDataPointer`, and [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md).

IDA MCP on 2026-05-23 confirmed eight caller functions and the exact `0x004d0f50-0x004d15c5` range. The companion [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md) helper has ten caller functions across map tile, static/effect/item/new-human, and UI/effect draw paths, which supports a shared `render/ImageFrameTable.cpp` source owner.

IDA MCP recheck on 2026-05-31 confirms `sub_4D0F50` starts at `0x004d0f50`, ends half-open at `0x004d15c5`, has 25 direct call sites grouped around image/effect/resource consumers, and calls DATFile lifecycle helpers, [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), allocation/free helpers, and rectangle/metadata helpers.

## Ownership Decision

This helper should be grouped with [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md), not with the raw DAT archive module. The current one-function file is a Wave3 staging file.

## Cross-References

- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:000176][0x004d0f50-0x004d165d.ImageFrameTable](by-memory/0x004d0f50-0x004d165d.ImageFrameTable.md)
- [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md)
- [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md)

## Changes

- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `50/65` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented frame-table loading behavior, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now tracks it as rebuild-relevant code while staying conservative because record/type names and final source shape remain incomplete.
  - Evidence: IDA MCP confirms the exact function range, 25 direct call sites, and DATFile/HasDATEntry/allocation/rectangle helper callees.

- 2026-06-01: Completion/confidence changed from `50/65` to `70/82`.
  - Before: the page relied on the broad aggregate memory range for canonical details.
  - After: the page points to exact memory documentation for `0x004d0f50-0x004d15c5`.
  - Evidence: [UID:0002P4][0x004d0f50-0x004d15c5.LoadImageFrameTable](by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md) records IDA MCP function boundary, caller/callee inventory, direct and merge mode behavior, table layout observations, and remaining type-name questions.
