*** UID:00003I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:40 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "DATFileMgr.h"
#include "DATFile.h"
#include "../util/Error.h"
#include "../util/File.h"
#include "../util/PathUtil.h"
#include <hash_map>
#include <stdio.h>
#include <vector>
#include <wchar.h>

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_ARCHIVE_DATFILEMGR_H
#define NEXUSTK_ARCHIVE_DATFILEMGR_H

#include "../util/Singleton.h"

class _DATFileMgr;
struct DATEntryLocation;

class DATFileMgr : public Singleton<DATFileMgr>
{
public:
    DATFileMgr();
    virtual ~DATFileMgr();

    bool LoadDATFile(const wchar_t *archivePath);
    bool FindEntryByName(const wchar_t *entryName,
                         DATEntryLocation *outLocation);

private:
    _DATFileMgr *m_impl;
};

extern DATFileMgr *g_pDATFileMgr;

typedef char DATFileMgrSizeMustBe0x08[
    sizeof(DATFileMgr) == 0x08 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DATFileMgr

## 2026-08-18 Dependency And Source Closure

The public wrapper remains an exact 0x08 `Singleton<DATFileMgr>`-derived object with `_DATFileMgr *m_impl` at `+0x04`. `DATEntryLocation` is the complete eight-byte archive/index record declared with DATFileContainer in `DATFileMgr.h`. The CPP channel now places every required include before child definitions; node/hash compiler internals are not public/private helper declarations.

## 2026-08-17 Standard-Container Lowering Correction

The shared ranges formerly labeled `DATIndexVector` are folded old-MSVC/Dinkumware hash-container implementation, not a standalone helper class or source dependency. DATFileMgr and its private resolver own their typed key/value containers; constructor, insert/find, growth, unwind, and destruction calls into the shared family are compiler/private-library lowering generated from those consumer declarations. Existing `DATFileResolver` ownership, methods, layouts, and source route remain unchanged.

## Status

- Confidence: very strong for public wrapper identity, exact `Singleton<DATFileMgr>` inheritance, 8-byte layout, lifecycle, and direct module placement; high for accepted private helper aliases and field names.
- Historical recovered files: `class_DATFileMgr.cpp`, `class__DATFileMgr.cpp`, `class_DATFileContainer.cpp`, `class_DATFileResolver.cpp`; these Wave3 staging splits do not override the single accepted source module.
- Likely source module: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- Current relevant ranges: adjacent public find wrapper [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md) plus the `0x0049bd30-0x0049d6ed` aggregate and exact child ranges in [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)
- Vtable: [UID:0001XB][DATManagerVtables](by-type/by-vtable/DATManagerVtables.md), `0x00618914`; exact data page [UID:0002MA][0x00618910-0x00618918.DATFileMgrVtableData](by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md)
- Evidence basis: evidence-time IDA MCP database `bf5519ae`, exact RTTI hierarchy/base descriptors, constructor EH metadata, caller/callee and vtable/global xrefs, raw disassembly, and current exact child docs through 2026-07-12.

## Responsibility

`DATFileMgr` is the public DAT manager wrapper and exactly derives from `Singleton<DATFileMgr>`. It is an 8-byte object with a primary vtable pointer at `+0x00` and `_DATFileMgr *m_impl` at `+0x04`. RTTI places the empty singleton base at displacement `+0x04`; MSVC empty-base optimization overlaps that empty base address with the first member location without increasing object size. The internal manager owns archive indexing and name lookup. `DATFileContainer` owns mapped archive storage used by the manager.

The exact method bodies emit from child by-memory pages; this class page keeps class-level ownership/layout only. Constructor source explicitly initializes `Singleton<DATFileMgr>()` then `m_impl(new _DATFileMgr)`. Ordinary destructor source deletes `m_impl`; the later global clear is inlined singleton-base destruction. Public/private vptr stores, EH funclets, and scalar deleting wrappers remain compiler output.

## Related Classes

| Class | Range | Role |
| --- | --- | --- |
| `DATFileMgr` | `0x0049bd30-0x0049d38b` | Public wrapper deriving from RTTI-proven `Singleton<DATFileMgr>` at PMD `+0x04`; singleton storage is [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) at `0x0067ab40`. |
| [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md) | `0x0049c750-0x0049d6ed` | Internal manager, name index, archive vector, archive entry lookup, and raw ordinary destructor body. |
| [UID:00003H][DATFileContainer](by-class/DATFileContainer.md) | `0x0049be80-0x0049d349` | One mapped DAT archive container. |
| [UID:00003J][DATFileResolver](by-class/DATFileResolver.md) | [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) | Embedded resolver/hash-table member at `_DATFileMgr +0x04`; source-facing helper/member type in `DATFileMgr.cpp`, not standalone `DATFileResolver.cpp`. |

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
| `0x0049bd20-0x0049bd2c` | `DATFileMgr` | `FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation)` | Raw no-function public wrapper; [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md) now emits formal C++ as `bool DATFileMgr::FindEntryByName(...)` by forwarding through `m_impl` to `_DATFileMgr::FindEntryByName`. |
| `0x0049bd30` | `DATFileMgr` | constructor | Exact child [UID:000439][0x0049bd30-0x0049be41.DATFileMgrConstructor](by-memory/0x0049bd30-0x0049be41.DATFileMgrConstructor.md) emits `Singleton<DATFileMgr>()` plus direct `m_impl(new _DATFileMgr)`; outer wrapper is 8 bytes. |
| `0x0049be50-0x0049be6d` | `DATFileMgr` | ordinary destructor raw body | Raw no-function destructor; source body deletes `m_impl`, while public vptr restoration and later `g_pDATFileMgr` clear are compiler/base-destructor lowering. |
| `0x0049be70` | `DATFileMgr` | `LoadDATFile` candidate | Public wrapper forwarding to `_DATFileMgr::LoadDATFileIndex`; recovery alias `ForwardLoadDATFileIndex_49BE70`. |
| `0x0049d350` | `DATFileMgr` | scalar deleting destructor | Delete wrapper around manager destruction. |
| `0x0049be80` | `DATFileContainer` | constructor | Creates mapped archive container; IDA MCP shows Win32 file mapping APIs and error handling. |
| `0x0049d2d0` | `DATFileContainer` | scalar deleting destructor | Releases mapped-file/container state. |
| `0x0049c750` | `_DATFileMgr` | raw ordinary destructor | Not an IDA-modeled function; disassembly tears down archive containers, frees archive-vector storage, and calls resolver destroy at `0x0049c7e8`. |
| `0x0049c800` | `_DATFileMgr` | `LoadDATFileIndex` | Loads one DAT archive and populates the internal name index. |
| `0x0049cad0` | `_DATFileMgr` | `FindEntryByName` | Lookup target used by `DATFile::Open`. |
| `0x0049cbb0` | `DATFileMgr.cpp` file-local/static helper | `CreateDATEntryNode` | Builds entry/index node structures; no `this` use, so this is not an instance method. |
| `0x0049ce50` | `DATFileResolver` | `InsertOrFindEntry` | Inserts or finds name-index entries on the embedded resolver at `_DATFileMgr + 4`. |
| `0x0049d490` | `DATFileMgr.cpp` file-local/static helper | `AllocateDATEntryNode` | Allocates manager/index node storage; no `this` use supports local helper ownership. |
| `0x0049d5e0` | `DATFileResolver` | `FindNodeByKey` | Key/name lookup helper on the embedded resolver at `_DATFileMgr + 4`. |
| `0x0049d190` | `DATFileResolver` | `Destroy` | [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md). |

## Related Cleanup Helper

[UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md) at `0x00467380-0x00467391` checks [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) and calls the manager's deleting destructor with flag `1`. It is called from resource/image load failure paths and paired with [UID:0000UG][DestroyExceptionHandler_4673A0](by-item/DestroyExceptionHandler_4673A0.md), so it should be treated as fatal cleanup glue rather than a public DAT API method.

## Ownership Notes

- The outer and inner manager should be documented and migrated together even though Wave3 currently emits separate class files.
- Evidence-time RTTI complete-object locator `0x0064645c` and hierarchy `0x00646470` contain exactly `DATFileMgr` and `Singleton<DATFileMgr>`; the singleton base descriptor at `0x006464a8` has PMD `mdisp=4`, `pdisp=-1`, `vdisp=0`.
- Constructor pointer adjustment `this+4` then subtract four, EH state-zero clear through `0x005fd230 -> 0x0049d180`, and destructor-family clear order prove singleton-base lifetime. Historical manual `g_pDATFileMgr = this` constructor wording and manual destructor clear placement are superseded.
- [UID:000439][0x0049bd30-0x0049be41.DATFileMgrConstructor](by-memory/0x0049bd30-0x0049be41.DATFileMgrConstructor.md) records the 0x111-byte/102-instruction extent, sole Application caller, 8-byte public and 0x30-byte private allocations, inlined resolver/vector defaults, four unwind states, and exact pre/post padding.
- `DATFileMgr::LoadDATFile` at `0x0049be70-0x0049be7c` is the public archive-load wrapper used by `Application::Initialize` and [UID:0000T5][LoadIndexedDATSeries](by-global/LoadIndexedDATSeries.md). Keep it as a method on this class, not as a free helper.
- `DATFileContainer` belongs with this manager layer because `_DATFileMgr::LoadDATFileIndex` constructs containers while building the archive index.
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) is a free helper in this same module. It probes [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) without returning an entry location.
- `_DATFileMgr::FindEntryByName` normalizes lookup names to uppercase wide strings before hashing/comparison, matching the load-time uppercase conversion of DAT entry names.
- Manager construction and `_DATFileMgr::InsertOrFindEntry` reach the same folded standard hash-container lowering used by minimap, fitting-room, and monster-image consumers. [UID:00003K][DATIndexVector](by-class/DATIndexVector.md) is now a non-emitting compiler-layout overlay, not a standalone module or private manager member file.
- 2026-06-07 Batch 083 live IDA MCP `py_eval` recheck reconfirmed the class/file boundary: public wrapper constructor `0x0049bd30-0x0049be41`, public load-index wrapper `0x0049be70-0x0049be7c`, scalar deleting destructor `0x0049d350-0x0049d38b`, and no modeled function at the raw find forwarder `0x0049bd20` or ordinary internal cleanup start `0x0049c750`. The same check still places `_DATFileMgr` load/find/create/insert/node helpers and the resolver cleanup inside the `DATFileMgr.cpp` source family, while `HasDATEntry` remains a free helper beside the manager.
- The same recheck found `??_7DATFileMgr@@6B@` at `0x00618914` referenced by the public constructor/destructor and `??_7_DATFileMgr@@6B@` at `0x006189cc` referenced by the public constructor, internal deleting destructor, and raw ordinary cleanup bytes. This supports one direct source module for the public wrapper and its private implementation rather than a separate generated class-file split.
- 2026-06-19 B015 `_DATFileMgr` reanalysis removes the stale field-layout blocker for the public wrapper relationship. The public `DATFileMgr` still stores the inner manager pointer at `+0x04`; the inner manager has `DATFileResolver m_resolver` at `+0x04` and source member `std::vector<DATFileContainer *> m_archiveContainers`, physically represented by begin/end/capacity pointers at `+0x24/+0x28/+0x2c`. Exact original private class spelling and final wide-string typedef names remain review items, not blockers for the declaration.
- 2026-06-26 B002 implementation resolves the stale broad-parent C++ blocker by moving method bodies to exact child emitters. `DATFileMgr::DATFileMgr` emits through [UID:000439][0x0049bd30-0x0049be41.DATFileMgrConstructor](by-memory/0x0049bd30-0x0049be41.DATFileMgrConstructor.md), raw ordinary `DATFileMgr::~DATFileMgr` emits through [UID:00043A][0x0049be50-0x0049be6d.DATFileMgrDestructor](by-memory/0x0049be50-0x0049be6d.DATFileMgrDestructor.md), and public `DATFileMgr::LoadDATFile` emits through [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md). The scalar deleting destructor at `0x0049d350-0x0049d38b` remains compiler-generated from the virtual destructor and should not be hand-authored as a standalone source body.
- 2026-06-26 B001 [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md) implementation resolves the public find-wrapper source-quality blocker. `DATFileMgr::FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation)` is inferred but implementation-ready; the exact child page now emits the formal wrapper body like [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md), using source-facing `m_impl` at offset `+0x04` and forwarding to `_DATFileMgr::FindEntryByName`. The no-function/no-xref wrapper-entry evidence remains documented on the child page and caps child confidence rather than blocking C++.

## Private Archive Vector Source Consequence

[UID:000004][_DATFileMgr](by-class/_DATFileMgr.md) now models the archive-container triplet as one typed source member, `std::vector<DATFileContainer *> m_archiveContainers`. [UID:00043D][0x0049c800-0x0049cac4._DATFileMgrLoadDATFileIndex](by-memory/0x0049c800-0x0049cac4._DATFileMgrLoadDATFileIndex.md) appends with `push_back`; its call at `0x0049c8f0` into [UID:00050O][0x00437710-0x00437869.Vector4ByteGrowInsertCompilerSupport](by-memory/0x00437710-0x00437869.Vector4ByteGrowInsertCompilerSupport.md) is compiler-covered support rather than a manager helper API.

The ordinary private destructor deletes each stored container pointer and then relies on automatic vector/resolver member destruction. Historical names for separate begin/end/capacity fields and `DATFileContainerVectorAppend`/`DATFileContainerVectorFree` remain physical-lowering descriptions only. This correction affects private implementation source shape and does not change the public wrapper's 8-byte layout, singleton inheritance, methods, or owner/emitter route.

## Assignment Decision

Current `CANONICAL_OWNER` and `EMITTER_UIDS` remain [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md). This class page is `91/94`, and the accepted direct file parent is `92/92`. The by-file page owns the public wrapper, `_DATFileMgr` implementation, mapped archive container, resolver subobject, manager singleton, and local free helpers; assigning this class to any narrower class or global page would hide the public/private manager relationship.

This class page emits only the public wrapper declaration and post-class `[[CHILDREN]]`. Exact wrapper method bodies remain on [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md), [UID:000439][0x0049bd30-0x0049be41.DATFileMgrConstructor](by-memory/0x0049bd30-0x0049be41.DATFileMgrConstructor.md), [UID:00043A][0x0049be50-0x0049be6d.DATFileMgrDestructor](by-memory/0x0049be50-0x0049be6d.DATFileMgrDestructor.md), and [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md). Root position `40` places this complete public declaration and its children after positioned DATFileContainer `10`, DATFileResolver `20`, and `_DATFileMgr` `30`; do not duplicate child bodies here.

## Score Rationale

- Completion `91`: public responsibility, exact Singleton inheritance, EBO/public layout, complete method inventory, constructor/destructor source split, inner layout relationship, owner/emitter/source route, deterministic emission order, and exact child routing are documented.
- Confidence `94`: RTTI hierarchy/PMD, constructor adjustment/EH, Application allocation, field accesses, vtable/global xrefs, and destructor order independently support the class shape. Exact private container typedef/member and original header spellings remain inferred and cap a final score.

## Historical Data Issues Resolved Or Bounded

- `_DATFileMgr` is exact RTTI spelling; `m_archiveContainers` is the accepted typed vector-member name, while exact original typedef/header spellings remain inferred review items rather than constructor or class-declaration blockers.
- `DATFileContainer` field names are mostly understood, but the exact original name for the final-row offset at `0x10` still needs confirmation.
- `DATFileResolver` may be a small helper object rather than a full original source-level class.
- `0x0049c750` is a raw IDA-boundary gap rather than nonexistent code; keep it with `_DATFileMgr` and do not promote it to a separate helper file.
- The old "final source method spelling not proven" blocker is no longer a reason to leave child C++ blank. Method child pages use inferred source-facing names documented as inferred but implementation-ready: `DATFileMgr::FindEntryByName`, `DATFileMgr::DATFileMgr`, `DATFileMgr::~DATFileMgr`, and `DATFileMgr::LoadDATFile`.

## Cross-References

- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md)
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

- 2026-08-17 B007 UID0000PA provider-header closure:
  - Moved the exact `DATFileMgr : public Singleton<DATFileMgr>` declaration, `_DATFileMgr`/DATEntryLocation forward declarations, public wrappers, `m_impl`, global extern, and `0x08` size assertion into guarded `DATFileMgr.h`.
  - The CPP class channel now includes its header before exact constructor/destructor/wrapper/global children. WinMain's typed `delete g_pDATFileMgr` therefore uses the owning provider instead of an incomplete or duplicated class fragment.
  - Internal manager/container/resolver implementation remains in DATFileMgr.cpp and exact children; the header does not expose those private implementation bodies or move ownership into WinMain.

- 2026-08-13 UID0000P3 accepted implementation callback: synchronized the public wrapper documentation with `_DATFileMgr`'s typed `std::vector<DATFileContainer *> m_archiveContainers`, `push_back`, automatic vector teardown, and compiler-covered UID00050O growth path; public metadata and formal declaration remain unchanged.

- 2026-07-12 B001 UID000439 accepted implementation callback:
  - Raised score from `88/90` to `91/94`, set root emitter position `40`, and added exact `public Singleton<DATFileMgr>` inheritance while preserving owner/emitter UID0000IO and all method children.
  - Added RTTI hierarchy/base PMD, 8-byte EBO layout, constructor/EH/destructor lifetime proof, corrected source/compiler split, deterministic DATFileContainer/resolver/private/public ordering, confidence caps, and historicalized manual-global/manual-clear wording.
- 2026-07-01 B008 DATFileMgr empty-emitter family implementation:
  - Raised score from `86/86` to `88/90`.
  - Added formal public wrapper declaration C++ with `_DATFileMgr *m_impl`, `LoadDATFile`, `FindEntryByName`, virtual destructor, and `[[CHILDREN]]`.
  - Preserved exact child method emitters [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md), [UID:000439][0x0049bd30-0x0049be41.DATFileMgrConstructor](by-memory/0x0049bd30-0x0049be41.DATFileMgrConstructor.md), [UID:00043A][0x0049be50-0x0049be6d.DATFileMgrDestructor](by-memory/0x0049be50-0x0049be6d.DATFileMgrDestructor.md), and [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md); no child method body was duplicated on this class page.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `78/82`.
  - Summary/evidence: public/internal manager split, related classes, methods, mapped container layout, cleanup helper, global singleton, vtable docs, and unresolved data issues are documented; remaining uncertainty is exact public/private source split and unresolved internal field names.
- 2026-05-31 vtable-data evidence:
  - What existed before: the class linked only the generic `DATManagerVtables` type page and did not mark `RECONSTRUCTABLE`.
  - Changed to: marked `RECONSTRUCTABLE:TRUE`, raised confidence to `84`, and linked the exact `0x00618910-0x00618918` vtable-data page.
  - Summary/evidence: IDA MCP `list_globals`, `xrefs_to`, and dword scan prove the one-slot public-wrapper vtable and the `DATFileContainer` RTTI boundary at `0x00618918`.
- 2026-06-07 A006 Batch 083:
  - Changed score from `78/84` to `86/86` and set `AUTOGEN_PARENT_UID:0000IO`.
  - Summary/evidence: live IDA MCP reconfirmed public wrapper method boundaries, the raw find-forwarder and raw ordinary-destructor starts, internal manager helper boundaries, resolver cleanup calls, and both public/internal vtable reference sets. The direct by-file parent also clears the corrected `85/85` gate.
- 2026-06-19 B015 `_DATFileMgr` support incorporation:
  - Score and owner/emitter metadata unchanged.
  - Summary/evidence: synced the public wrapper page with the B015 private implementation class analysis. The stale unknown-field issue is replaced by the resolved embedded resolver/vector layout, resolver helper ownership, file-local/static node helper ownership, and first-draft readiness of the `_DATFileMgr` class declaration.
- 2026-06-26 B001 [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md) source-quality implementation:
  - Score and owner/emitter metadata unchanged.
  - Summary/evidence: added the public `DATFileMgr::FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation)` method row, linked the exact child page, and recorded that [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md) now carries formal C++ using inferred but implementation-ready source-facing names/types.
