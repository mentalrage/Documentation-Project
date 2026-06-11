*** UID:00003J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Source-facing placement: internal helper/member of [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md), not proven as a standalone original `DATFileResolver.cpp`.
- Reconstructable: true as DAT manager project code; final C++ remains blank until the embedded resolver fields and source-level spelling are audit-ready.

## Class Purpose

`DATFileResolver` is the current documentation name for the DAT manager's internal resolver/hash-table state. It owns the bucket vector and list sentinel used to resolve uppercase entry names to archive container and entry-index pairs.

This may not have been a separate original source-level class. It is likely an embedded helper object or STL-like hash/list member inside `_DATFileMgr`.

## Layout Notes

Current reconstructed code uses this working shape:

| Resolver offset | Interpreted role | `_DATFileMgr` offset |
| --- | --- | --- |
| `+0x00` | load factor / first resolver word | `+0x04` |
| `+0x04` | circular list sentinel pointer | `+0x08` |
| `+0x08` | indexed entry count | `+0x0c` |
| `+0x0c` | bucket/vector begin | `+0x10` |
| `+0x10` | bucket/vector end | `+0x14` |
| `+0x14` | bucket/vector capacity | `+0x18` |

Generated and aggregate manager notes also describe hash mask/count state in the wider resolver area. The exact field names remain provisional because this page currently has only the cleanup method, not a complete constructor/find/insert implementation split for a standalone resolver type.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `Destroy` | [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) | Frees the bucket vector, walks entry nodes, releases shared wide-string keys, frees each node, and frees the sentinel. |

## Lifecycle And Callers

| Site | Evidence |
| --- | --- |
| `_DATFileMgr` embedding | [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md) treats offsets `0x04-0x23` as resolver/hash-table state before the archive-container vector at `0x24`. |
| Raw ordinary destructor | [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md) calls resolver cleanup at `0x0049c7e8` on `this + 4` after archive-vector teardown. |
| Modeled deleting destructor | `_DATFileMgr::DeletingDestructor` at `0x0049d3d0-0x0049d488` calls the same cleanup path at `0x0049d462`; its one-slot vtable entry is documented in [UID:0002MB][0x006189c8-0x006189d0._DATFileMgrVtableData](by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md). |
| Manager source owner | [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) places the resolver as `archive/DATFileMgr.cpp` internal helper/member alongside `DATFileMgr`, `_DATFileMgr`, `DATFileContainer`, `HasDATEntry`, and `g_pDATFileMgr`. |

## Evidence Notes

- IDA MCP confirms `0x0049d190` as a real function with size `0xdc`.
- IDA MCP decompilation confirms bucket/vector cleanup, circular-list reset, indexed-entry count clear, per-node shared wide-string release, node free, and sentinel free.
- The resolver cleanup method is documented at `84/88`, and the raw `_DATFileMgr` destructor that calls it is documented at `82/88`.
- IDA MCP reports no formal function at `0x0049c750`, but 2026-06-01 raw disassembly confirms [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md) is an ordinary `_DATFileMgr` destructor-shaped cleanup body.
- `xrefs_to 0x0049d190` shows the raw destructor's call instruction at `0x0049c7e8` plus the modeled `_DATFileMgr::DeletingDestructor` call at `0x0049d462`.
- The confirmed `_DATFileMgr::DeletingDestructor` at `0x0049d3d0` calls the resolver destruction path and is vtable-referenced at `0x006189cc`.
- Keep this class as a documentation convenience for the embedded subobject unless later source-layout evidence proves a separately declared original class.

## Score Rationale

- Completion is `82` because the class now links the source parent, embedded `_DATFileMgr` layout, exact cleanup child, two destructor callers, vtable-backed deleting destructor, and archive-manager ownership boundary.
- Confidence is `86` because the executable cleanup behavior, offsets, callers, and parent source owner are strongly documented; it is capped below high confidence because final source-level spelling, constructor ownership, and standalone-class status remain unresolved.

## Cross-References

- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)
- [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md)
- [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md)
- [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md)
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md)
- [UID:0002MB][0x006189c8-0x006189d0._DATFileMgrVtableData](by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `70/74`.
  - Summary/evidence: resolver/hash-table purpose, working layout, destroy behavior, destructor callers, and manager ownership are documented; confidence remains capped because this may be an embedded helper/STL-like member instead of a separate original source-level class.
- 2026-06-01:
  - Before: the page still described the class name as generated-tool evidence and was not marked reconstructable.
  - After: marked `RECONSTRUCTABLE:TRUE`, attached it to [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md), raised to `76/82`, and made IDA MCP decompilation/disassembly the evidence basis.
  - Summary/evidence: IDA MCP confirms the exact cleanup function range, two destructor callers, bucket/vector free, circular-list reset, per-node string release, and sentinel free.
- 2026-06-07 A001 embedded resolver refresh:
  - Before: the page summarized cleanup behavior but still carried stale generated-file wording and did not align with the stronger child memory evidence.
  - After: raised to `82/86`, replaced generated-file wording with source-facing placement notes, expanded the resolver layout, caller/lifecycle evidence, source-owner boundary, and score rationale.
  - Summary/evidence: [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md), [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md), [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md), and [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) now agree that this is reconstructable DAT manager code but likely an embedded resolver/hash-table subobject rather than a standalone original class file.
