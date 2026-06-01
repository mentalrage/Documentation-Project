*** UID:0000U4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# BuildEffectArchiveTable 0x004de420

## Status

- Confidence: strong for behavior and owner.
- Likely owner file: [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- Memory range: `0x004de420-0x004de7c1`
- Current recovered file: `source-3/simroot_v2/recovered/BuildEffectArchiveTable_004DE420.cpp`

## Function Role

`BuildEffectArchiveTable` scans numbered `EFFECT%d.EPF` archives, merges their frame records into an `ArchiveMetadataTable`, converts payload offsets to DAT-backed absolute pointers, and appends a terminal sentinel record.

IDA xrefs show one caller: `EffectObjImageLib::EffectObjImageLib` at `0x004de007`.

The body follows the same per-asset archive-table pattern as the tile and static-object builders: probe up to the numbered archive series, accumulate total frame count and max metrics, allocate one contiguous record table plus a sentinel, and rebase each record's payload offsets by the owning `DATFile` payload pointer.

## Ownership Decision

Keep this with `render/EffectObjImageLib.cpp` unless the shared EPF archive-table loaders are later consolidated into `render/ImageFrameTable.cpp`.

## Cross-References

- [UID:00004A][EffectObjImageLib](by-class/EffectObjImageLib.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:0001U9][EffectObjImageLibLayout](by-type/by-struct/EffectObjImageLibLayout.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `78/86`.
  - Before: page documented effect archive table behavior, one caller, shared EPF pattern, and owner decision but remained unevaluated.
  - After: score reflects documented scan/merge/rebase/sentinel behavior and strong `EffectObjImageLib` ownership, with room left for deeper field-level/raw-code detail.
  - Evidence: xrefs show the sole caller from `EffectObjImageLib::EffectObjImageLib`; behavior matches the linked EPF archive metadata table/resource docs.
