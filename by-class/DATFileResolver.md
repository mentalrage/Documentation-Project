*** UID:00003J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DATFileResolver

## Status

- Confidence: medium for class identity, strong for destructor behavior.
- Likely source file: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- Address range: [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)
- Current recovered file: `source-3/simroot_v2/class_DATFileResolver.cpp`

## Class Purpose

`DATFileResolver` is the current documentation name for the DAT manager's internal resolver/hash-table state. It owns the bucket vector and list sentinel used to resolve uppercase entry names to archive container and entry-index pairs.

This may not have been a separate original source-level class. It is likely an embedded helper object or STL-like hash/list member inside `_DATFileMgr`.

## Layout Notes

Current reconstructed code uses this working shape:

| Field | Interpreted role |
| --- | --- |
| `m_maxLoadFactor` | Hash-table load factor. |
| `m_listSentinel` | Circular list sentinel for indexed entry nodes. |
| `m_entryCount` | Number of indexed entries. |
| `m_bucketsBegin` / `m_bucketsEnd` / `m_bucketsCapacity` | Bucket-record vector. |
| `m_bucketMask` / `m_bucketCount` | Hash lookup mask/count. |

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `Destroy` | [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) | Frees the bucket vector, walks entry nodes, releases shared wide-string keys, frees each node, and frees the sentinel. |

## Evidence Notes

- IDA MCP confirms `0x0049d190` as a real function with size `0xdc`.
- IDA MCP decompilation confirms bucket/vector cleanup, list reset, per-node key release, and sentinel free.
- IDA MCP reports no formal function at `0x0049c750`, but 2026-06-01 raw disassembly confirms [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md) is an ordinary `_DATFileMgr` destructor-shaped cleanup body.
- `xrefs_to 0x0049d190` shows the raw destructor's call instruction at `0x0049c7e8` plus the modeled `_DATFileMgr::DeletingDestructor` call at `0x0049d462`.
- The confirmed `_DATFileMgr::DeletingDestructor` at `0x0049d3d0` calls the resolver destruction path and is vtable-referenced at `0x006189cc`.

## Cross-References

- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)
- [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md)
- [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md)
- [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md)
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `70/74`.
  - Summary/evidence: resolver/hash-table purpose, working layout, destroy behavior, destructor callers, and manager ownership are documented; confidence remains capped because this may be an embedded helper/STL-like member instead of a separate original source-level class.
- 2026-06-01:
  - Before: the page still described the class name as generated-tool evidence and was not marked reconstructable.
  - After: marked `RECONSTRUCTABLE:TRUE`, attached it to [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md), raised to `76/82`, and made IDA MCP decompilation/disassembly the evidence basis.
  - Summary/evidence: IDA MCP confirms the exact cleanup function range, two destructor callers, bucket/vector free, circular-list reset, per-node string release, and sentinel free.
