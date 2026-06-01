*** UID:00003I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# DATFileMgr

## Status

- Confidence: strong for module ownership, medium for exact public/private split.
- Current files: `class_DATFileMgr.cpp`, `class__DATFileMgr.cpp`, `class_DATFileContainer.cpp`, `class_DATFileResolver.cpp`
- Likely source module: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- Current relevant ranges: `0x0049bd30-0x0049d6ed` aggregate, with exact child ranges in [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)
- Vtable: [UID:0001XB][DATManagerVtables](by-type/by-vtable/DATManagerVtables.md), `0x00618914`; exact data page [UID:0002MA][0x00618910-0x00618918.DATFileMgrVtableData](by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md)
- Evidence basis: Wave3 class/layout inspection, generated notes, IDA MCP caller/callee checks, and raw disassembly through 2026-05-26.

## Responsibility

`DATFileMgr` is the public DAT manager wrapper. It appears to be an 8-byte object with a vtable pointer and a pointer to an internal `_DATFileMgr` object. The internal manager owns archive indexing and name lookup. `DATFileContainer` owns mapped archive storage used by the manager.

## Related Classes

| Class | Range | Role |
| --- | --- | --- |
| `DATFileMgr` | `0x0049bd30-0x0049d38b` | Public wrapper; singleton [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) at `0x0067ab40`. |
| [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md) | `0x0049c750-0x0049d6ed` | Internal manager, name index, archive vector, archive entry lookup, and raw ordinary destructor body. |
| [UID:00003H][DATFileContainer](by-class/DATFileContainer.md) | `0x0049be80-0x0049d349` | One mapped DAT archive container. |
| [UID:00003J][DATFileResolver](by-class/DATFileResolver.md) | [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) | Embedded resolver/hash-table cleanup helper; exact source-level identity still open. |

## DATFileContainer Layout

Observed layout from generated source and Wave3 class layout:

| Offset | Current/interpreted field | Notes |
| --- | --- | --- |
| `0x00` | vftable | Virtual destructor support. |
| `0x04` | file handle | `CreateFile` result. |
| `0x08` | mapping handle | `CreateFileMapping` result. |
| `0x0c` | mapped view base | Also used as archive data base for `DATFile::Read`. |
| `0x10` | last entry offset | First dword of final 17-byte table row; likely final-payload boundary/sentinel offset. |
| `0x14` | entry count | First dword of mapped file. |
| `0x18` | entry table pointer | Points at mapped view + 4. |

The mapped entry table uses 17-byte records. `_DATFileMgr::LoadDATFileIndex` treats bytes `+0x04..+0x10` of each record as the ANSI entry name. IDA MCP decompilation of `DATFileContainer::DATFileContainer` shows `m_lastEntryOffset = *(uint32*)(entryTable + (entryCount - 1) * 17)`, which supports the final-row sentinel/final-boundary interpretation.

## Methods

| Address | Owner | Method | Notes |
| --- | --- | --- | --- |
| `0x0049bd30` | `DATFileMgr` | constructor | Allocates/initializes internal `_DATFileMgr`; outer wrapper is 8 bytes. |
| `0x0049be70` | `DATFileMgr` | `LoadDATFile` candidate | Public wrapper forwarding to `_DATFileMgr::LoadDATFileIndex`; recovery alias `ForwardLoadDATFileIndex_49BE70`. |
| `0x0049d350` | `DATFileMgr` | scalar deleting destructor | Delete wrapper around manager destruction. |
| `0x0049be80` | `DATFileContainer` | constructor | Creates mapped archive container; IDA MCP shows Win32 file mapping APIs and error handling. |
| `0x0049d2d0` | `DATFileContainer` | scalar deleting destructor | Releases mapped-file/container state. |
| `0x0049c750` | `_DATFileMgr` | raw ordinary destructor | Not an IDA-modeled function; disassembly tears down archive containers, frees archive-vector storage, and calls resolver destroy at `0x0049c7e8`. |
| `0x0049c800` | `_DATFileMgr` | `LoadDATFileIndex` | Loads one DAT archive and populates the internal name index. |
| `0x0049cad0` | `_DATFileMgr` | `FindEntryByName` | Lookup target used by `DATFile::Open`. |
| `0x0049cbb0` | `_DATFileMgr` | `CreateEntryNode` | Builds entry/index node structures. |
| `0x0049ce50` | `_DATFileMgr` | `InsertOrFindEntry` | Inserts or finds name-index entries. |
| `0x0049d490` | `_DATFileMgr` | `AllocateNode` | Allocates manager/index node storage. |
| `0x0049d5e0` | `_DATFileMgr` | `FindNodeByKey` | Key/name lookup helper. |
| `0x0049d190` | `DATFileResolver` | `Destroy` | [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md). |

## Related Cleanup Helper

[UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md) at `0x00467380-0x00467391` checks [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) and calls the manager's deleting destructor with flag `1`. It is called from resource/image load failure paths and paired with [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md), so it should be treated as fatal cleanup glue rather than a public DAT API method.

## Ownership Notes

- The outer and inner manager should be documented and migrated together even though Wave3 currently emits separate class files.
- `DATFileMgr::LoadDATFile` at `0x0049be70-0x0049be7c` is the public archive-load wrapper used by `Application::Initialize` and [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md). Keep it as a method on this class, not as a free helper.
- `DATFileContainer` belongs with this manager layer because `_DATFileMgr::LoadDATFileIndex` constructs containers while building the archive index.
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) is a free helper in this same module. It probes [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) without returning an entry location.
- `_DATFileMgr::FindEntryByName` normalizes lookup names to uppercase wide strings before hashing/comparison, matching the load-time uppercase conversion of DAT entry names.
- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md) helpers are called by manager construction and `_DATFileMgr::InsertOrFindEntry`, but 2026-05-24 IDA caller checks show broader minimap, fitting-room, and monster-image users. Treat it as a standalone helper module, not a private manager member file.

## Data Issues To Track Later

- `_DATFileMgr` currently has many unknown byte fields from `0x8` through `0x23` and dword fields at `0x24`, `0x28`, and `0x2c`. The class should be field-reviewed after `LoadDATFileIndex`, `FindEntryByName`, and `InsertOrFindEntry` are deep-reviewed.
- `DATFileContainer` field names are mostly understood, but the exact original name for the final-row offset at `0x10` still needs confirmation.
- `DATFileResolver` may be a small helper object rather than a full original source-level class.
- `0x0049c750` is a raw IDA-boundary gap rather than nonexistent code; keep it with `_DATFileMgr` and do not promote it to a separate helper file.

## Cross-References

- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md)
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md)
- [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md)
- [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md)
- [UID:0001P6][0x0067ab40-0x0067ab44.g_pDATFileMgr](by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md)
- [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md)
- [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md)
- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)
- [UID:0001XB][DATManagerVtables](by-type/by-vtable/DATManagerVtables.md)
- [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md)
- [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md)
- [UID:0002MA][0x00618910-0x00618918.DATFileMgrVtableData](by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md)
- [UID:00003G][DATFile](by-class/DATFile.md)
- [UID:00003H][DATFileContainer](by-class/DATFileContainer.md)
- [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md)
- [UID:00003J][DATFileResolver](by-class/DATFileResolver.md)

## Changes

- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/82`.
  - Summary/evidence: public/internal manager split, related classes, methods, mapped container layout, cleanup helper, global singleton, vtable docs, and unresolved data issues are documented; remaining uncertainty is exact public/private source split and unresolved internal field names.
- 2026-05-31 vtable-data evidence:
  - What existed before: the class linked only the generic `DATManagerVtables` type page and did not mark `RECONSTRUCTABLE`.
  - Changed to: marked `RECONSTRUCTABLE:TRUE`, raised confidence to `84`, and linked the exact `0x00618910-0x00618918` vtable-data page.
  - Summary/evidence: IDA MCP `list_globals`, `xrefs_to`, and dword scan prove the one-slot public-wrapper vtable and the `DATFileContainer` RTTI boundary at `0x00618918`.
