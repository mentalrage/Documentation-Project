*** UID:0000V0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# LoadTileEpfMetadata 0x004d1b80

## Status

- Confidence: strong for behavior and owner.
- Likely owner file: [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- Memory range: `0x004d1b80-0x004d1f21`
- Current recovered file: `source-3/simroot_v2/recovered/LoadTileEpfMetadata_004D1B80.cpp`

## Function Role

`LoadTileEpfMetadata` scans numbered `TILE%d.EPF` archives, opens each present archive through `DATFile`, reads the shared EPF archive metadata header and record table, and merges all records into one `ArchiveMetadataTable` with a terminal sentinel.

Wave3/IDA xrefs show one caller: `MapTileImageLib::MapTileImageLib`.

IDA decompilation shows the helper probes up to 100 numbered archive shards by formatting `TILE%d.EPF` and checking [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md). It then allocates the merged metadata header, opens each present archive through `DATFile`, converts raw EPF record bounds into the shared packed in-memory table, and releases temporary per-archive `DATFile` objects.

IDA MCP recheck on 2026-05-31 confirms `sub_4D1B80` starts at `0x004d1b80`, ends half-open at `0x004d1f22`, has one direct caller at `0x004d18d1` inside `sub_4D1860`, and calls [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), DATFile helpers, allocation/free helpers, and rectangle/table helpers.

## Ownership Decision

Keep this with `render/MapTileImageLib.cpp` unless a later migration creates a shared `render/ImageFrameTable.cpp` for all EPF archive-table builders.

## Cross-References

- [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md)
- [UID:0001V2][MapTileImageLibLayout](by-type/by-struct/MapTileImageLibLayout.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-05-31: Grading and reconstruction status changed from unevaluated/blank to `70/85` and `RECONSTRUCTABLE:TRUE`.
  - Before: the page body documented the tile EPF metadata loader, but the validator metadata still showed `0/0` and no reconstruction status.
  - After: the metadata now reflects the IDA-verified tile metadata loader. Parent UID and C++ remain blank because final source attachment still needs the surrounding MapTileImageLib and EPF table code to reach the final-code gate.
  - Evidence: IDA MCP confirms the exact function range, single `MapTileImageLib` constructor-family caller, and DATFile/HasDATEntry/allocation/table helper callees.
