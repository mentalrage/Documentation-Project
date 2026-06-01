*** UID:000004 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# _DATFileMgr

## Status

- Confidence: strong for behavior and archive-module placement, medium for field names.
- Likely source file: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- Address range: [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md), with a raw destructor body at [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md)
- Vtable: [UID:0001XB][DATManagerVtables](by-type/by-vtable/DATManagerVtables.md), `0x006189cc`; exact data page [UID:0002MB][0x006189c8-0x006189d0._DATFileMgrVtableData](by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md)
- Current recovered file: `source-3/simroot_v2/class__DATFileMgr.cpp`

## Class Purpose

`_DATFileMgr` is the internal DAT archive manager behind the public `DATFileMgr` wrapper. It loads DAT archive indexes, normalizes entry names, stores archive containers, maintains the name lookup structure, and resolves entry names for `DATFile::Open`.

## Layout Notes

Wave3 reports a 48-byte object with a vtable pointer, a 4-byte value at `0x04`, many unresolved bytes through `0x23`, and three dword members at `0x24`, `0x28`, and `0x2c`. Generated source overlays this as an embedded resolver/hash table plus an archive-container pointer vector:

| Offset | Interpreted role | Confidence |
| --- | --- | --- |
| `0x00` | vtable | strong |
| `0x04-0x23` | resolver/hash table state, including load factor, list sentinel, bucket vector, count, mask, and bucket count | medium |
| `0x24` | archive vector begin | medium |
| `0x28` | archive vector end | medium |
| `0x2c` | archive vector capacity | medium |

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `~_DATFileMgr` raw body | `0x0049c750-0x0049c7f6` | Non-deleting destructor-shaped body; tears down archive containers, frees archive-vector storage, and destroys embedded resolver state. IDA currently reports `Not a function` at the start. |
| `LoadDATFileIndex` | `0x0049c800-0x0049cac4` | Loads one DAT archive container and inserts each non-empty entry name into the name index. |
| `FindEntryByName` | `0x0049cad0-0x0049cba5` | Uppercases a lookup name, searches the resolver, and optionally returns archive/container plus entry index. |
| `CreateEntryNode` | `0x0049cbb0-0x0049cc39` | Allocates and initializes one list/index node. |
| `InsertOrFindEntry` | `0x0049ce50-0x0049d0c2` | Inserts or finds a key in the hash/index structure. |
| `DeletingDestructor` | `0x0049d3d0-0x0049d488` | Releases internal resolver/list data and optionally frees the manager. |
| `AllocateNode` | `0x0049d490-0x0049d4bd` | Allocates node storage for index/list entries. |
| `FindNodeByKey` | `0x0049d5e0-0x0049d6ed` | Searches the internal name index. |

## Evidence Notes

- Wave3 summary identifies this as the internal DAT file management utility.
- IDA MCP confirms the modeled method anchors listed above as real function starts, except the raw ordinary destructor at `0x0049c750`, which is currently a disassembly-only boundary.
- IDA MCP raw disassembly confirms `0x0049c750-0x0049c7f6` is a destructor-shaped `_DATFileMgr` cleanup body even though `lookup_funcs` reports `0x0049c750` as `Not a function`.
- `LoadDATFileIndex` reads 17-byte DAT entry records, converts entry names from ANSI to uppercase wide strings, skips empty names, and avoids duplicate insertions.
- `FindEntryByName` is the confirmed callee used by `DATFile::Open`.
- [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) appears to describe an embedded resolver/hash-table subobject rather than a separate source-level archive feature.
- `_DATFileMgr::InsertOrFindEntry` calls `DATIndexVector`-family storage helpers, but [UID:00003K][DATIndexVector](by-class/DATIndexVector.md) is shared outside the DAT manager and should stay standalone.

## Cross-References

- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)
- [UID:0001XB][DATManagerVtables](by-type/by-vtable/DATManagerVtables.md)
- [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md)
- [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md)
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md)
- [UID:00003H][DATFileContainer](by-class/DATFileContainer.md)
- [UID:00003J][DATFileResolver](by-class/DATFileResolver.md)
- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md)
- [UID:0002MB][0x006189c8-0x006189d0._DATFileMgrVtableData](by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: scored from the internal DAT manager responsibility, layout notes, destructor/load/find/insert/node method map, vtable/memory/type cross-references, DAT entry behavior, and raw destructor/field-name caveats.
- 2026-05-31 vtable-data evidence:
  - What existed before: the class linked only the generic `DATManagerVtables` type page and did not mark `RECONSTRUCTABLE`.
  - Changed to: marked `RECONSTRUCTABLE:TRUE`, raised confidence to `84`, and linked the exact `0x006189c8-0x006189d0` vtable-data page.
  - Summary/evidence: IDA MCP `list_globals`, `xrefs_to`, and dword scan prove the one-slot internal-manager vtable and the `"../"` string boundary at `0x006189d0`.
