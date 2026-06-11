*** UID:0000U6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000O7 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BuildTilecArchiveTable 0x004dda60

## Status

- Confidence: strong for behavior and owner.
- Likely owner file: [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- Autogen parent: [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- Memory range: `0x004dda60-0x004dde01`

## Function Role

`BuildTilecArchiveTable` scans numbered `TILEC%d.EPF` archives, merges their frame records into an `ArchiveMetadataTable`, converts payload offsets to DAT-backed absolute pointers, and appends a terminal sentinel record. IDA decompilation matches the `LoadTileEpfMetadata` pattern: probe up to 100 shards, allocate temporary DAT readers/headers, accumulate total entries and max metrics, then emit one contiguous merged metadata table.

IDA xrefs show one caller: `StaticObjImageLib::StaticObjImageLib`.

## Ownership Decision

Keep this with `render/StaticObjImageLib.cpp` unless the shared EPF archive-table loaders are later consolidated into `render/ImageFrameTable.cpp`.

## Cross-References

- [UID:0000E2][StaticObjImageLib](by-class/StaticObjImageLib.md)
- [UID:0001W9][StaticObjImageLibLayout](by-type/by-struct/StaticObjImageLibLayout.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-06-05: Reconstructable metadata changed from blank to `TRUE`, attached to [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md), and stale generated-source wording was removed.
  - Before: the TILEC archive-table builder was documented but unclassified in autogen coverage.
  - After: it is marked as NexusTK-owned source under the validated StaticObjImageLib file root; C++ remains blank because table field names and final helper signature are not at the 95/95 final-code bar.
  - Evidence: live IDA MCP confirms `sub_4DDA60` at `0x004dda60`, size `0x3a2`, one direct caller in `sub_4DCF60`, and the same EPF archive-table loader shape as the already assigned tile/effect table builders.

- 2026-05-30: Grading changed from `0/0` to `78/86`.
  - Before: page documented TILEC archive-table behavior, one caller, and owner decision but remained unevaluated.
  - After: score reflects documented shard scan, metadata merge/rebase/sentinel behavior, and `StaticObjImageLib` ownership, with room left for deeper field-level/raw-code detail.
  - Evidence: IDA xrefs show one caller from `StaticObjImageLib::StaticObjImageLib`; decompilation matches the shared EPF archive-table pattern.
