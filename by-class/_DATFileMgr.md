*** UID:000004 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
namespace
{
struct DATEntryNameHashCompare
{
    enum { bucket_size = 4, min_buckets = 8 };

    size_t operator()(const StringBaseW &name) const
    {
        size_t hash = 0;
        const wchar_t *current = name.c_str();
        while (*current != L'\0') hash = *current++ + 5 * hash;
        return hash;
    }

    bool operator()(const StringBaseW &left, const StringBaseW &right) const
    {
        return mystr::WideRangeCompare(
            left.c_str(), left.c_str() + left.length(),
            right.c_str(), right.c_str() + right.length()) < 0;
    }
};
}

class _DATFileMgr {
public:
    virtual ~_DATFileMgr();

    bool LoadDATFileIndex(const wchar_t *archivePath);
    bool FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation);

private:
    typedef stdext::hash_map<StringBaseW, DATEntryLocation,
                             DATEntryNameHashCompare> EntryMap;
    EntryMap m_entriesByName;
    std::vector<DATFileContainer *> m_archiveContainers;
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# _DATFileMgr

## 2026-08-18 Typed Standard-Container Source Closure

The former `DATFileResolver` member is the physical 0x20 old-MSVC `stdext::hash_map` subobject at `+0x04`, now expressed as typed human source. Its default sentinel, `1.0f` load factor, eight buckets, `ch + 5 * hash` loop, wide-range ordering, insertion/rehash, lookup, and destruction are library/compiler consequences. The only authored children are `_DATFileMgr` destruction, archive loading/indexing, and name lookup; the node/hash ranges emit no source.

## Status

- Confidence: very strong for exact RTTI-backed `_DATFileMgr` identity, 48-byte size, constructor/destructor behavior, archive-module placement, direct [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) ownership, embedded resolver layout, and archive-container vector shape; high for final string/helper typedef names.
- Likely source file: [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- Address range: [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md), with a raw destructor body at [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md)
- Vtable: [UID:0001XB][DATManagerVtables](by-type/by-vtable/DATManagerVtables.md), `0x006189cc`; exact data page [UID:0002MB][0x006189c8-0x006189d0._DATFileMgrVtableData](by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md)
- Historical recovered file `source-3/simroot_v2/class__DATFileMgr.cpp` is a Wave3 staging artifact. The source route is the private implementation class inside `NexusTK/archive/DATFileMgr.cpp`.

## Class Purpose

`_DATFileMgr` is the exact RTTI-backed internal DAT archive manager behind the public `DATFileMgr` wrapper. It loads DAT archive indexes, normalizes entry names, stores archive containers, maintains the name lookup structure, and resolves entry names for `DATFile::Open`. [UID:000439][0x0049bd30-0x0049be41.DATFileMgrConstructor](by-memory/0x0049bd30-0x0049be41.DATFileMgrConstructor.md) allocates and inlines construction of this object through public member initializer `m_impl(new _DATFileMgr)`.

## Layout Notes

Evidence-time database `bf5519ae` confirms constructor allocation size `0x30` / 48 bytes. Current source reconstruction resolves the physical shape as a vtable pointer, the 0x20-byte old-MSVC implementation of typed source member `EntryMap m_entriesByName` at `_DATFileMgr +0x04`, and the three-pointer implementation of source member `std::vector<DATFileContainer *> m_archiveContainers` at `+0x24/+0x28/+0x2c`:

| Offset | Interpreted role | Confidence |
| --- | --- | --- |
| `0x00` | vtable | strong |
| `0x04-0x23` | physical old-MSVC/Dinkumware `EntryMap m_entriesByName`; historical resolver aliases describe its load factor, sentinel, size, bucket-vector triplet, mask, and count | strong |
| `0x24` | physical `m_archiveContainers` begin pointer for loaded `DATFileContainer *` entries | strong |
| `0x28` | physical `m_archiveContainers` end pointer | strong |
| `0x2c` | physical `m_archiveContainers` capacity-end pointer used by MSVC vector allocation/deallocation guards | strong |

`m_entriesByName` and `m_archiveContainers` are stored by value. Constructor lowering zeroes the initial list/bucket state, allocates its 20-byte circular sentinel, sets max load factor `1.0f`, initializes eight buckets, then default-constructs the archive vector as a zeroed three-pointer header. The formal C++ block represents the `_DATFileMgr` declaration shape and places `[[CHILDREN]]` after the closing brace. Root position `30` follows the DAT entry/container declarations and precedes public DATFileMgr position `40`, so generated private method children are outside the class and public `new _DATFileMgr` sees a complete type.

## Archive Container Vector Source Shape

The source-facing member is `std::vector<DATFileContainer *> m_archiveContainers`, not three manually declared pointer fields. The descriptive names `m_archiveContainersBegin`, `m_archiveContainersEnd`, and `m_archiveContainersCapacity` remain useful only when explaining physical offsets and decompiler output. They are historical lowering aliases and must not appear as separate source members.

[UID:00043D][0x0049c800-0x0049cac4._DATFileMgrLoadDATFileIndex](by-memory/0x0049c800-0x0049cac4._DATFileMgrLoadDATFileIndex.md) appends with `m_archiveContainers.push_back(container)`. The full-capacity call at `0x0049c8f0` into [UID:00050O][0x00437710-0x00437869.Vector4ByteGrowInsertCompilerSupport](by-memory/0x00437710-0x00437869.Vector4ByteGrowInsertCompilerSupport.md) is the compiler-generated four-byte pointer-slot growth path, not a source helper named `DATFileContainerVectorAppend`.

Both ordinary destructor evidence and the scalar-deleting wrapper iterate through `m_archiveContainers`, delete each owned `DATFileContainer *`, then rely on automatic `std::vector` member destruction to release storage before the embedded resolver is destroyed in reverse member order. This source shape preserves the observed `+0x24/+0x28/+0x2c` ABI while remaining plausible human-authored mid-2000s C++.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `~_DATFileMgr` raw body | `0x0049c750-0x0049c7f6` | Ordinary/non-deleting source destructor semantics; tears down archive containers, frees archive-vector storage, and destroys embedded resolver state. IDA currently reports `Not a function` at the start, and the vtable route uses the scalar deleting destructor child. |
| `_DATFileMgr::LoadDATFileIndex(const wchar_t *archivePath)` | `0x0049c800-0x0049cac4` | Loads one DAT archive container and inserts each non-empty entry name into the name index. |
| `_DATFileMgr::FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation)` | `0x0049cad0-0x0049cba5` | Uppercases a lookup name, searches the resolver, and optionally returns archive/container plus entry index. |
| compiler list-node construction lowering | `0x0049cbb0-0x0049cc39` | Allocates and initializes one internal `EntryMap` list/index node; not an authored project helper. |
| compiler hash-map insert/rehash lowering | `0x0049ce50-0x0049d0c2` | Implements `m_entriesByName.insert` on the typed map at `_DATFileMgr + 4`; not an authored resolver method. |
| compiler scalar deleting destructor | `0x0049d3d0-0x0049d488` | Vtable-slot delete helper for `_DATFileMgr`; final source should declare `virtual ~_DATFileMgr()` and not hand-port this wrapper as the ordinary destructor body. |
| compiler list-node allocation lowering | `0x0049d490-0x0049d4bd` | Allocates internal map/list node storage; not an authored project helper. |
| compiler hash-map find lowering | `0x0049d5e0-0x0049d6ed` | Implements `m_entriesByName.find` on the typed map at `_DATFileMgr + 4`; not an authored resolver method. |

Authored `_DATFileMgr` method bodies route only through raw ordinary `~_DATFileMgr` [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md), `LoadDATFileIndex` [UID:00043D][0x0049c800-0x0049cac4._DATFileMgrLoadDATFileIndex](by-memory/0x0049c800-0x0049cac4._DATFileMgrLoadDATFileIndex.md), and `FindEntryByName` [UID:00043E][0x0049cad0-0x0049cba5._DATFileMgrFindEntryByName](by-memory/0x0049cad0-0x0049cba5._DATFileMgrFindEntryByName.md). UIDs 00043F, 00043G, 00012H, 00043H, and 00043I retain exact binary evidence but emit no source because the typed `EntryMap` declaration generates those node/list/hash operations.

## Evidence Notes

- Wave3 summary identifies this as the internal DAT file management utility.
- IDA MCP confirms the modeled method anchors listed above as real function starts, except the raw ordinary destructor at `0x0049c750`, which is currently a disassembly-only boundary.
- IDA MCP raw disassembly confirms `0x0049c750-0x0049c7f6` is a destructor-shaped `_DATFileMgr` cleanup body even though `lookup_funcs` reports `0x0049c750` as `Not a function`.
- `LoadDATFileIndex` reads 17-byte DAT entry records, converts entry names from ANSI to uppercase wide strings, skips empty names, and avoids duplicate insertions.
- `FindEntryByName` is the confirmed callee used by `DATFile::Open`.
- [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) appears to describe an embedded resolver/hash-table subobject rather than a separate source-level archive feature.
- `_DATFileMgr::InsertOrFindEntry` calls `DATIndexVector`-family storage helpers, but [UID:00003K][DATIndexVector](by-class/DATIndexVector.md) is shared outside the DAT manager and should stay standalone.
- 2026-06-08 A005 Batch 110 IDA MCP refresh reconfirmed the internal-manager method boundaries: `0x0049c800-0x0049cac4` load/index, `0x0049cad0-0x0049cba5` lookup, `0x0049ce50-0x0049d0c2` insert/find, `0x0049d3d0-0x0049d488` scalar deleting destructor, and `0x0049d5e0-0x0049d6ed` node search. `0x0049c750` still has no modeled function, but raw bytes restore `_DATFileMgr`'s vtable, delete the archive-container vector, clear vector pointers at `+0x24/+0x28/+0x2c`, and call the resolver cleanup at `this+0x04`.
- The same refresh reports three refs to the `_DATFileMgr` vtable at `0x006189cc`: public wrapper construction at `0x0049bda1`, raw ordinary cleanup at `0x0049c755`, and scalar deleting destructor setup at `0x0049d3dd`. This supports treating `_DATFileMgr` as an internal class owned directly by [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md), not as a standalone source module.
- 2026-06-16 B002 source-quality recheck of [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md) reconfirmed the raw ordinary destructor at `0x0049c750-0x0049c7f6` as source-authored `_DATFileMgr` cleanup semantics with no surviving direct VA/RVA/rel32 route to the start. The body restores vtable `0x006189cc`, deletes archive-container pointers from offsets `+0x24/+0x28`, frees and clears archive-vector storage at `+0x24/+0x28/+0x2c`, and calls resolver cleanup at `0x0049c7e8` on `this + 4`. That pass called the three physical words `m_archiveContainersBegin`, `m_archiveContainersEnd`, and `m_archiveContainersCapacity`; the accepted 2026-08-13 source-shape correction below supersedes those as source fields and retains them only as physical aliases for `std::vector<DATFileContainer *> m_archiveContainers`.
- 2026-06-18 B005 reanalysis of [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) resolves the embedded resolver field map and source shape. The resolver subobject begins at `_DATFileMgr + 4`; constructor `0x0049bd30` initializes a 0x14-byte sentinel, max load factor `1.0f`, and an initial 8-bucket vector, while load/find/insert helpers prove bucket mask/count at resolver `+0x18/+0x1c`. Treat the cleanup body at `0x0049d190` as the internal `DATFileResolver` destructor/member cleanup, not standalone `DATFileResolver.cpp`.
- 2026-06-19 B015 source-quality reanalysis raises the class to a declaration-ready state. The public wrapper constructor at `0x0049bd30` allocates `0x30` bytes for this implementation object, installs the `_DATFileMgr` vtable at `0x006189cc`, initializes resolver state, clears archive-container vector fields, and stores the implementation pointer at `DATFileMgr +0x04`; [UID:0001P6][0x0067ab40-0x0067ab44.g_pDATFileMgr](by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md) points to the public wrapper, not this inner object.
- B015 confirms the vtable route: [UID:0002MB][0x006189c8-0x006189d0._DATFileMgrVtableData](by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md) contains RTTI/pre-vtable dword `0x006189c8` and one slot `0x006189cc -> 0x0049d3d0`; the adjacent dword `0x006189d0` begins UTF-16 `"../"` data used by `LoadDATFileIndex`, not a second virtual slot.
- B015 resolved the archive-container storage physically as begin/end/capacity at `+0x24/+0x28/+0x2c`. The accepted 2026-08-13 correction interprets that exact triplet as the MSVC representation of source member `std::vector<DATFileContainer *> m_archiveContainers`; `LoadDATFileIndex` appends `DATFileContainer *` entries through that member, and both destructor bodies expose its compiler-generated iteration/deallocation lowering with MSVC large-allocation checks.
- B015 source-routing rejects standalone `_DATFileMgr.cpp`, standalone `DATFileResolver.cpp`, `DATArchive` ownership, and `DATIndexVector` folding. `DATArchive` is only a subsystem grouping, `DATIndexVector` remains shared outside this manager, and the current recovered `class__DATFileMgr.cpp` / `class_DATFileResolver.cpp` split is a staging artifact.
- 2026-06-26 B002 implementation confirms the child method/helper C++ routes above. The class declaration remains source-facing and keeps `_DATFileMgr` spelling; `DATFileMgrImpl` is rejected as unsupported churn. Method bodies belong only on exact by-memory child pages, not in this class-level declaration page.
- 2026-07-12 UID000439 evidence-time reanalysis confirms exact `_DATFileMgr` RTTI/type descriptor spelling, 0x30-byte allocation, private vtable store `0x006189cc`, full resolver/vector initialization, and unwind cleanup. Exact comparator/allocator typedefs and private field spellings remain inferred confidence caps; they do not block this class declaration or public constructor.
- Historical generated output inserted child method definitions before this class's closing brace because the class block lacked `[[CHILDREN]]`. The accepted marker/position repair supersedes that malformed order without changing any child payload.

## Source Shape And Rejected Alternatives

- Keep `_DATFileMgr` as the source-facing private implementation class name. Exact RTTI descriptor `.?AV_DATFileMgr@@` proves this spelling; `DATFileMgrImpl` is rejected as unsupported churn.
- Keep the class in [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md). The public wrapper, inner implementation, mapped container, resolver subobject, singleton, and local node helpers form one archive manager source family.
- Declare `virtual ~_DATFileMgr();` in source. The raw ordinary body at `0x0049c750` represents destructor semantics, while the vtable slot at `0x006189cc` points to the compiler-generated scalar deleting destructor at `0x0049d3d0`.
- Do not hand-author vtable bytes, RTTI, or scalar deleting destructor wrapper code. [UID:0002MB][0x006189c8-0x006189d0._DATFileMgrVtableData](by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md) should be regenerated from the class declaration and virtual destructor shape.
- Keep method bodies on exact child pages. The class page emits declaration-level C++ followed by post-class `[[CHILDREN]]`; existing `LoadDATFileIndex`, `FindEntryByName`, resolver insert/find/destroy, node helper, destructor, and vtable-comment child payloads are preserved outside the class.

## Score And Assignment Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 90 | Purpose, exact RTTI name, 48-byte construction/destruction layout, methods, resolver/vector ownership, vtable child, DAT behavior, source route, post-class child placement, root order, and rejected alternatives are documented. Exact private container typedef/header names remain bounded. |
| Confidence | 92 | Current constructor evidence plus B002/B005/B015 support strongly confirms allocation size, vtable stores, raw cleanup, wrapper relation, resolver fields, archive vector fields, and module placement. Exact comparator/allocator and helper/entry-record typedef names remain inferred. |
| Assignment | [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) | The child is `90/92`, direct file parent is `92/92`, and root position `30` preserves complete-type ordering. |

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

- 2026-08-13 UID0000P3 accepted implementation callback: replaced the three physical archive-vector pointer fields in formal class source with `std::vector<DATFileContainer *> m_archiveContainers`; retained begin/end/capacity offsets as physical layout evidence; linked `push_back` to compiler-covered UID00050O; and documented automatic vector storage cleanup plus reverse member destruction order.

- 2026-07-12 B001 UID000439 accepted implementation callback:
  - Raised score from `89/88` to `90/92`, set root emitter position `30`, and added the missing post-class `[[CHILDREN]]` marker without changing any existing child payload.
  - Added exact RTTI name/0x30-byte allocation proof, full constructor initialization order, complete-type dependency, generated-order correction, and bounded private typedef/header uncertainty.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:86` and `CONFIDENCE:82`.
  - Summary/evidence: scored from the internal DAT manager responsibility, layout notes, destructor/load/find/insert/node method map, vtable/memory/type cross-references, DAT entry behavior, and raw destructor/field-name caveats.
- 2026-05-31 vtable-data evidence:
  - What existed before: the class linked only the generic `DATManagerVtables` type page and did not mark `RECONSTRUCTABLE`.
  - Changed to: marked `RECONSTRUCTABLE:TRUE`, raised confidence to `84`, and linked the exact `0x006189c8-0x006189d0` vtable-data page.
  - Summary/evidence: IDA MCP `list_globals`, `xrefs_to`, and dword scan prove the one-slot internal-manager vtable and the `"../"` string boundary at `0x006189d0`.
- 2026-06-08 A005 Batch 110:
  - Before: score `86/84`, `AUTOGEN_PARENT_UID:` blank; child confidence was below the corrected `85/85` assignment gate.
  - Changed to: score `87/85`, `AUTOGEN_PARENT_UID:0000IO`.
  - Summary/evidence: live IDA MCP reconfirmed internal-manager method ranges, the raw ordinary destructor byte sequence and no-function status at `0x0049c750`, and the three `_DATFileMgr` vtable refs from wrapper construction, raw cleanup, and deleting destructor. Direct parent [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) is already `89/85`, so both sides now clear the corrected gate.
- 2026-06-19 B015 source-quality incorporation:
  - Before: score `87/85`; field-name and original private spelling caveats still blocked formal C++ and left helper ownership too broadly under `_DATFileMgr`.
  - Changed to: score `89/88`; formal C++ now contains declaration-level `_DATFileMgr` source shape with `DATFileResolver m_resolver` and archive-container vector fields, while method bodies remain child-page work.
  - Summary/evidence: B015 consolidated current [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md), [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md), vtable, wrapper, and singleton evidence. The pass resolved `_DATFileMgr +0x04..+0x23` as embedded resolver state, `+0x24/+0x28/+0x2c` as archive-container vector fields, `0x0049ce50`/`0x0049d5e0` as resolver member helpers, and `0x0049cbb0`/`0x0049d490` as file-local/static node helpers; it rejects standalone `_DATFileMgr.cpp`, standalone `DATFileResolver.cpp`, `DATArchive` ownership, `DATIndexVector` ownership, and hand-authored vtable/scalar-deleting-destructor code.
