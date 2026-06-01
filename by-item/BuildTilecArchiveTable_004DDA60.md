*** UID:0000U6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BuildTilecArchiveTable 0x004dda60

## Status

- Confidence: strong for behavior and owner.
- Likely owner file: [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- Memory range: `0x004dda60-0x004dde01`
- Current recovered file: `source-3/simroot_v2/recovered/BuildTilecArchiveTable_004DDA60.cpp`

## Function Role

`BuildTilecArchiveTable` scans numbered `TILEC%d.EPF` archives, merges their frame records into an `ArchiveMetadataTable`, converts payload offsets to DAT-backed absolute pointers, and appends a terminal sentinel record. IDA decompilation matches the `LoadTileEpfMetadata` pattern: probe up to 100 shards, allocate temporary DAT readers/headers, accumulate total entries and max metrics, then emit one contiguous merged metadata table.

Wave3/IDA xrefs show one caller: `StaticObjImageLib::StaticObjImageLib`.

## Ownership Decision

Keep this with `render/StaticObjImageLib.cpp` unless the shared EPF archive-table loaders are later consolidated into `render/ImageFrameTable.cpp`.

## Cross-References

- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `78/86`.
  - Before: page documented TILEC archive-table behavior, one caller, and owner decision but remained unevaluated.
  - After: score reflects documented shard scan, metadata merge/rebase/sentinel behavior, and `StaticObjImageLib` ownership, with room left for deeper field-level/raw-code detail.
  - Evidence: Wave3/IDA xrefs show one caller from `StaticObjImageLib::StaticObjImageLib`; decompilation matches the shared EPF archive-table pattern.
