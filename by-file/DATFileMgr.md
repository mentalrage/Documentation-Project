*** UID:0000IO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/archive/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# DATFileMgr

## 2026-08-18 Whole-File Source Closure

`NexusTK/archive/DATFileMgr.cpp/.h` is the second and final authored archive source unit. It owns `DATEntryRecord`, `DATEntryLocation`, `DATFileContainer`, `_DATFileMgr`, public `DATFileMgr`, `g_pDATFileMgr`, the public wrapper methods, `HasDATEntry`, and exact authored constructor/destructor/load/find bodies. `_DATFileMgr` contains a typed `stdext::hash_map<StringBaseW, DATEntryLocation, DATEntryNameHashCompare>` and `std::vector<DATFileContainer *>`; node allocation, list/hash insertion, rehash, lookup, and teardown ranges are compiler/library lowering from those members rather than project helper APIs.

The CPP preamble includes both archive headers plus Error/File/PathUtil and period standard dependencies before any child definition. Mapped-container failures preserve direct `swprintf_s`, `MessageBoxW(..., L"오류", MB_ICONWARNING)`, and `throw new Win32Error()` behavior; prior `ShowDATFileError`/`ShowDATFileMapError` helpers were invented recovery scaffolding and are historicalized.

Generated acceptance requires source-closed DATFileMgr CPP/H with declarations before use, only authored project methods, and no synthetic `DATFileResolver`, node/hash helper, or unresolved dependency marker.

## 2026-08-17 Standard-Container Dependency Correction

DATFileMgr.cpp owns the public/private manager and resolver source. The shared ranges historically grouped as `DATIndexVector` are folded old-MSVC/Dinkumware hash-container lowering produced by consumer-owned typed containers, not a standalone archive/common/util source file. Their exact binary pages remain cross-referenced; no DATIndexVector CPP/H dependency is emitted.

## Status

- Confidence: very strong for manager/container ownership, exact public Singleton inheritance/lifecycle, deterministic declaration order, and direct archive-module placement; high for accepted private helper aliases and exact original header organization.
- Proposed module: `NexusTK/archive/DATFileMgr.cpp`
- Historical recovered files: `source-3/simroot_v2/class_DATFileMgr.cpp`, `class__DATFileMgr.cpp`, `class_DATFileContainer.cpp`, `class_DATFileResolver.cpp`, and `HasDATEntry_0049C700`; these staging partitions are not current source-owner evidence.
- Evidence basis: evidence-time IDA MCP database `bf5519ae`, exact RTTI/EH/layout/caller/vtable/global evidence, current exact child docs, and generated source-order inspection through 2026-07-12.

## 2026-07-01 B008 Generated Output Audit

Historical generated `auto-generated/NexusTK/archive/DATFileMgr.cpp` was audited at validator command `000000003756`, refreshed `2026-07-01T07:16:39-04:00`. The tracker row then reported `26` total emitters, `16` filled emitters, `10` empty emitters, `61.5%` filled, and reports `0`; those counts are evidence-time facts only, not current lifecycle assertions.

This audit preserves [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) as the `NexusTK/archive/DATFileMgr.cpp` source-file route. The public wrapper [UID:00003I][DATFileMgr](by-class/DATFileMgr.md), private implementation [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md), mapped container [UID:00003H][DATFileContainer](by-class/DATFileContainer.md), embedded resolver [UID:00003J][DATFileResolver](by-class/DATFileResolver.md), singleton [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md), exact helper bodies, and exact vtable/storage evidence remain in this source family. Do not split this family into standalone `_DATFileMgr.cpp`, `DATFileContainer.cpp`, or `DATFileResolver.cpp` files.

Accepted empty-marker dispositions from the B008 audit:

| Empty UID | Page | Accepted disposition |
| --- | --- | --- |
| [UID:00003H][DATFileContainer](by-class/DATFileContainer.md) | Class declaration/layout page | Emit the `DATFileContainer` declaration plus `[[CHILDREN]]`; constructor/destructor bodies remain on exact children. |
| [UID:00003I][DATFileMgr](by-class/DATFileMgr.md) | Public wrapper class page | Emit the `DATFileMgr` declaration plus `[[CHILDREN]]`; exact wrapper methods remain on [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md), [UID:000439][0x0049bd30-0x0049be41.DATFileMgrConstructor](by-memory/0x0049bd30-0x0049be41.DATFileMgrConstructor.md), [UID:00043A][0x0049be50-0x0049be6d.DATFileMgrDestructor](by-memory/0x0049be50-0x0049be6d.DATFileMgrDestructor.md), and [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md). |
| [UID:0002MA][0x00618910-0x00618918.DATFileMgrVtableData](by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md) | Exact public-wrapper vtable data | Emit only the no-hand-authored-vtable comment; the class declaration and virtual destructor route cause compiler emission. |
| [UID:00003J][DATFileResolver](by-class/DATFileResolver.md) | Internal resolver helper/member class page | Emit the resolver declaration plus `[[CHILDREN]]`; exact resolver method bodies remain on exact by-memory children. |
| [UID:0002MB][0x006189c8-0x006189d0._DATFileMgrVtableData](by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md) | Exact private-manager vtable data | Emit only the no-hand-authored-vtable comment; `0x006189d0` remains UTF-16 `"../"` data, not a slot. |
| [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) | Duplicate global symbol page | Reclassify as non-emitting duplicate/index for [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md). |
| [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) | Singleton global page | Emit `DATFileMgr *g_pDATFileMgr = 0;` plus `[[CHILDREN]]`; exact storage proof remains on [UID:0001P6][0x0067ab40-0x0067ab44.g_pDATFileMgr](by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md). |
| [UID:0001P6][0x0067ab40-0x0067ab44.g_pDATFileMgr](by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md) | Exact singleton storage child | Emit only the no-duplicate storage comment under [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md). |
| [UID:0000UT][HasDATEntry_0049C700](by-item/HasDATEntry_0049C700.md) | Duplicate by-item tracker page | Reclassify as non-emitting duplicate/index for [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md). |
| [UID:0001XB][DATManagerVtables](by-type/by-vtable/DATManagerVtables.md) | Broad vtable inventory page | Reclassify as non-emitting evidence/index; exact vtable data pages and class declarations carry source-declared/generated-binary handling. |

No-duplicate policy: class pages emit declarations and child markers, exact by-memory children emit method bodies, exact vtable/storage pages emit proof comments only, and duplicate alias/index pages do not emit bodies. Rejected owners remain `DATFile`, `DATArchive`, `DATIndexVector`, StringUtil/wide-string helpers, `File`, application cleanup, and higher-level resource/image/sound/UI consumers.

## 2026-07-12 B001 DATFileMgr Constructor Source-Shape Implementation

- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md) exactly derives from RTTI-proven `Singleton<DATFileMgr>` at non-virtual PMD `+0x04`. The empty base overlaps public `_DATFileMgr *m_impl` through MSVC EBO; Application allocation proves the public object remains 8 bytes.
- [UID:000439][0x0049bd30-0x0049be41.DATFileMgrConstructor](by-memory/0x0049bd30-0x0049be41.DATFileMgrConstructor.md) emits `Singleton<DATFileMgr>()` then direct `m_impl(new _DATFileMgr)`. Singleton publication, public/private vptr stores, 0x30-byte private allocation cleanup, resolver/list/bucket unwind, and return-this behavior are compiler lowering.
- [UID:00043A][0x0049be50-0x0049be6d.DATFileMgrDestructor](by-memory/0x0049be50-0x0049be6d.DATFileMgrDestructor.md) emits only `delete m_impl`; its observed later global clear is inlined Singleton base destruction. Historical manual-global/manual-clear source placement is superseded while exact raw behavior remains documented.
- `_DATFileMgr` construction initializes a 0x20-byte resolver at private `+0x04`, including a 20-byte circular sentinel, load factor `1.0f`, eight buckets, then zeroes archive vector storage `+0x24/+0x28/+0x2c`. Exact original private comparator/allocator typedefs remain inferred confidence caps.
- Root emitter positions are DATFileContainer `10`, DATFileResolver `20`, `_DATFileMgr` `30`, and DATFileMgr `40`. `_DATFileMgr` now has a post-class `[[CHILDREN]]` marker. This replaces the historical malformed generated order where public methods preceded complete `_DATFileMgr` and private children appeared before its closing brace.

## Proposed Contents

This file should own the global archive manager, mapped archive containers, the internal uppercase-name index, and global entry-existence checks.

| Entity | Range | Proposed placement | Notes |
| --- | --- | --- | --- |
| [UID:00003I][DATFileMgr](by-class/DATFileMgr.md) | `0x0049bd30-0x0049d38b` aggregate | `archive/DATFileMgr.cpp` | Public wrapper around an internal manager object. |
| [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md) | `0x0049c750-0x0049d6ed` aggregate | `archive/DATFileMgr.cpp` | Internal archive vector and typed `EntryMap m_entriesByName` manager; node/list/hash ranges are compiler lowering. |
| [UID:00003H][DATFileContainer](by-class/DATFileContainer.md) | `0x0049be80-0x0049d349` aggregate | `archive/DATFileMgr.cpp` | One memory-mapped DAT archive container. |
| [UID:00003J][DATFileResolver](by-class/DATFileResolver.md) | [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) | no source emission | Historical semantic overlay for compiler-generated `EntryMap` state and teardown. |
| [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md) | `0x0049bd20-0x0049bd2c` | `archive/DATFileMgr.cpp` | Public `DATFileMgr::FindEntryByName` wrapper; exact child now emits formal C++ through [UID:00003I][DATFileMgr](by-class/DATFileMgr.md), forwarding `m_impl` to `_DATFileMgr::FindEntryByName`. |
| [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md) | `0x0049be70-0x0049be7c` | `archive/DATFileMgr.cpp` | Public wrapper forwarding to `_DATFileMgr::LoadDATFileIndex`. |
| [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) | [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md) | `archive/DATFileMgr.cpp` | Global boolean probe against the archive manager. |
| [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) | [UID:0001P6][0x0067ab40-0x0067ab44.g_pDATFileMgr](by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md) | `archive/DATFileMgr.cpp` | Public manager singleton pointer used by `DATFile::Open`, `HasDATEntry`, startup, and shutdown. |
| [UID:0002MA][0x00618910-0x00618918.DATFileMgrVtableData](by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md) | `0x00618910-0x00618918` | compiler-emitted from `DATFileMgr` declaration | Exact public-wrapper RTTI pointer plus one scalar-deleting-destructor vtable slot. |
| [UID:0002MB][0x006189c8-0x006189d0._DATFileMgrVtableData](by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md) | `0x006189c8-0x006189d0` | compiler-emitted from `_DATFileMgr` declaration | Exact internal-manager RTTI pointer plus one scalar-deleting-destructor vtable slot. |

## Manager And Container Ranges

IDA MCP confirms these modeled function starts and raw-disassembly ranges:

| Range | Owner | Role |
| --- | --- | --- |
| [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md) | `DATFileMgr::FindEntryByName` | Public wrapper forwarding through `m_impl` to `_DATFileMgr::FindEntryByName`; formal child C++ is now present on [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md). |
| `0x0049bd30-0x0049be41` | `DATFileMgr` | Constructor for the public wrapper and internal manager pointer. |
| [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md) | `DATFileMgr::LoadDATFile` candidate | Public wrapper forwarding to `_DATFileMgr::LoadDATFileIndex`. |
| `0x0049d350-0x0049d38b` | `DATFileMgr` | Scalar deleting destructor. |
| `0x0049be80-0x0049c0c9` | `DATFileContainer` | Opens a DAT file, creates a read-only mapping, maps the view, and initializes entry table pointers. |
| `0x0049d2d0-0x0049d349` | `DATFileContainer` | Unmaps view, closes mapping/file handles, clears fields, and optionally deletes. |
| [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md) | `_DATFileMgr` | Raw ordinary destructor body; IDA has no function object at this start, but disassembly shows archive-vector teardown and resolver cleanup. |
| `0x0049c800-0x0049cac4` | `_DATFileMgr::LoadDATFileIndex` | Loads one archive container and indexes each non-empty uppercase entry name. |
| `0x0049cad0-0x0049cba5` | `_DATFileMgr::FindEntryByName` | Lookup target used by `DATFile::Open`. |
| `0x0049cbb0-0x0049cc39` | compiler list-node construction lowering | Implements internal `EntryMap` node construction; emits no project helper. |
| `0x0049ce50-0x0049d0c2` | compiler hash-map insertion/rehash lowering | Implements `m_entriesByName.insert`; emits no resolver method. |
| [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) | compiler hash-map member destruction | Automatic `EntryMap` teardown; emits no authored destructor. |
| `0x0049d3d0-0x0049d488` | `_DATFileMgr` compiler scalar deleting destructor | Vtable-route delete helper; final source should come from `virtual ~_DATFileMgr()` rather than a hand-authored ordinary destructor body. |
| `0x0049d490-0x0049d4bd` | compiler list-node allocation lowering | Allocates internal map/list storage; emits no project helper. |
| `0x0049d5e0-0x0049d6ed` | compiler hash-map find lowering | Implements `m_entriesByName.find`; emits no resolver method. |

## File-Level Rationale

- `DATFileMgr` and `_DATFileMgr` are a public/private manager pair; splitting them into separate recovered files is a Wave3 staging artifact.
- `DATFileMgr` derives from `Singleton<DATFileMgr>`. RTTI hierarchy `0x00646470`, base descriptor `0x006464a8`, constructor `this+4` adjustment, EH state-zero clear, and destructor order prove base-owned singleton lifetime.
- Their vtables are short one-slot tables: `DATFileMgr` at `0x00618914` and `_DATFileMgr` at `0x006189cc`. See [UID:0001XB][DATManagerVtables](by-type/by-vtable/DATManagerVtables.md) before adding any adjacent data as method slots.
- Exact by-memory vtable-data pages now split these records as [UID:0002MA][0x00618910-0x00618918.DATFileMgrVtableData](by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md) and [UID:0002MB][0x006189c8-0x006189d0._DATFileMgrVtableData](by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md). These are source-declared/generated-binary data, not hand-authored static arrays.
- [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md) should be reconstructed as `_DATFileMgr`'s ordinary/non-deleting destructor or equivalent cleanup body even though current IDA does not model it as a function and raw PE scans find no direct VA/RVA/rel32 route to the start. It mirrors `_DATFileMgr::DeletingDestructor` without the delete-flag object-free tail; the vtable slot at `0x006189cc` correctly points to the scalar deleting destructor at `0x0049d3d0`.
- [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md) is the same public/private forwarding pattern for `_DATFileMgr::FindEntryByName`; it appears immediately before the public wrapper constructor and now carries formal child C++ for `bool DATFileMgr::FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation)`.
- [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md) is a tiny public method wrapper over `_DATFileMgr::LoadDATFileIndex`. Its older `ForwardLoadDATFileIndex_49BE70` recovery alias should not make it a free global in the final source layout.
- `DATFileContainer` belongs in this file because `_DATFileMgr::LoadDATFileIndex` constructs containers while building the archive list and global name index.
- `DATFileResolver` is the resolver/hash-table subobject inside `_DATFileMgr`, not a standalone project feature. B005's 2026-06-18 source-quality reanalysis resolves the current reconstruction direction as a named internal helper/member type in `DATFileMgr.cpp`, with exact original header spelling still reviewable.
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) has 17 IDA-observed callers across PCX loading, image-frame loading, tile metadata, effect/table building, palette/resource checks, sound/resource paths, and other DAT consumers. The helper probes [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) and therefore belongs beside the manager rather than beside the per-entry stream reader.
- [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md) at `0x00467380-0x00467391` is not a direct `DATFileMgr.cpp` helper after the B001-012 owner audit. It deletes the active manager through [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md), but IDA shows it is called only from paired Application/startup fatal image/resource cleanup paths, so [UID:0000HG][Application](by-file/Application.md) owns the helper body while this file retains object/singleton ownership.
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) is a non-emitting compiler-family index. IDA MCP caller checks on 2026-05-24 show the folded resize/insert/find lowering is shared by DAT manager, minimap, fitting-room, and monster-image typed containers; `_DATFileMgr` owns its source declaration while the shared helper bodies have no standalone project module.
- 2026-05-31 IDA MCP recheck confirms the public wrapper constructor at `0x0049bd30`, the public load-index forwarder at `0x0049be70`, container construction at `0x0049be80`, `HasDATEntry` at `0x0049c700`, internal load/find helpers at `0x0049c800` and `0x0049cad0`, resolver cleanup at `0x0049d190`, and the internal deleting destructor at `0x0049d3d0`. The recheck also confirms that the public and internal vtable symbols sit adjacent to unrelated RTTI/vtable data, so slot interpretation must stay constrained to documented owner-specific entries.
- 2026-06-07 Batch 083 live IDA MCP recheck reconfirmed the direct parent gate for [UID:00003I][DATFileMgr](by-class/DATFileMgr.md): public wrapper constructor `0x0049bd30-0x0049be41`, public load-index wrapper `0x0049be70-0x0049be7c`, scalar deleting destructor `0x0049d350-0x0049d38b`, no modeled function at raw forwarder `0x0049bd20` or raw ordinary internal cleanup `0x0049c750`, and `_DATFileMgr` helper boundaries through `0x0049d6ed`. Vtable references at `0x00618914` and `0x006189cc` come from the public constructor/destructors and raw cleanup bytes, matching the documented one-source-module public/private manager relationship.
- 2026-06-19 B015 `_DATFileMgr` class reanalysis keeps the public/private manager pair in `NexusTK/archive/DATFileMgr.cpp` and treats `_DATFileMgr` as a private implementation class, not a separate recovered source file. The class declaration uses `DATFileResolver m_resolver` at `+0x04` and source member `std::vector<DATFileContainer *> m_archiveContainers`, whose MSVC physical begin/end/capacity pointers occupy `+0x24/+0x28/+0x2c`.
- B015 also tightens source-facing helper ownership: `0x0049ce50` and `0x0049d5e0` are `DATFileResolver` member helpers reached on `_DATFileMgr + 4`; `0x0049cbb0` and `0x0049d490` are file-local/static node helpers; and the scalar deleting destructor at `0x0049d3d0` is compiler-generated vtable-route code rather than the source-authored ordinary destructor body.

## 2026-06-26 B002 DAT Managers Source-Quality Implementation

B002 resolves [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md) as a non-emitting overlap/index page. This file remains the source route for manager-owned children only; the broad parent is not a source emitter. The current source-module decision is still `NexusTK/archive/DATFileMgr.cpp`, with `DATFileMgr`, `_DATFileMgr`, `DATFileContainer`, `DATFileResolver`, `HasDATEntry`, node allocation/creation, and resolver support helpers grouped together. Do not split the manager into standalone `_DATFileMgr.cpp`, `DATFileContainer.cpp`, or `DATFileResolver.cpp`.

Manager-owned child emission map:

| Range/page | Direct owner | File role |
| --- | --- | --- |
| [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md) | [UID:00003I][DATFileMgr](by-class/DATFileMgr.md) | Adjacent public `DATFileMgr::FindEntryByName` wrapper outside [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)'s half-open parent range; exact child emits formal C++ by forwarding `m_impl` to `_DATFileMgr::FindEntryByName`. |
| [UID:000439][0x0049bd30-0x0049be41.DATFileMgrConstructor](by-memory/0x0049bd30-0x0049be41.DATFileMgrConstructor.md) | [UID:00003I][DATFileMgr](by-class/DATFileMgr.md) | Public wrapper constructor; source initializes `Singleton<DATFileMgr>()` and `m_impl(new _DATFileMgr)`, while publication, vptr stores, nested resolver/vector setup, and EH are compiler lowering. |
| [UID:00043A][0x0049be50-0x0049be6d.DATFileMgrDestructor](by-memory/0x0049be50-0x0049be6d.DATFileMgrDestructor.md) | [UID:00003I][DATFileMgr](by-class/DATFileMgr.md) | Raw ordinary wrapper destructor; source deletes `m_impl`, Singleton base destruction clears the global, and scalar deleting wrapper remains compiler-generated. |
| [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md) | [UID:00003I][DATFileMgr](by-class/DATFileMgr.md) | Public `DATFileMgr::LoadDATFile` wrapper forwarding to `_DATFileMgr::LoadDATFileIndex`. |
| [UID:00043B][0x0049be80-0x0049c0c9.DATFileContainerConstructor](by-memory/0x0049be80-0x0049c0c9.DATFileContainerConstructor.md) | [UID:00003H][DATFileContainer](by-class/DATFileContainer.md) | Opens/maps one DAT archive, retries `"../"` path, and initializes entry-table fields. |
| [UID:00043C][0x0049c0d0-0x0049c130.DATFileContainerDestructor](by-memory/0x0049c0d0-0x0049c130.DATFileContainerDestructor.md) | [UID:00003H][DATFileContainer](by-class/DATFileContainer.md) | Raw ordinary container destructor; unmaps/closes handles and clears fields. |
| [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md) | [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) | File-scope/free `HasDATEntry` helper; broad resource/UI/audio callers are consumers, not owners. |
| [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md) | [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md) | Raw ordinary `_DATFileMgr` destructor; source iterates `m_archiveContainers` and deletes owned pointers, then automatic vector and resolver member destruction lowers to the observed storage free/clear and cleanup calls. |
| [UID:00043D][0x0049c800-0x0049cac4._DATFileMgrLoadDATFileIndex](by-memory/0x0049c800-0x0049cac4._DATFileMgrLoadDATFileIndex.md) | [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md) | Loads one archive, calls `m_archiveContainers.push_back(container)`, and indexes normalized DAT entry names; UID00050O records the compiler-covered growth lowering. |
| [UID:00043E][0x0049cad0-0x0049cba5._DATFileMgrFindEntryByName](by-memory/0x0049cad0-0x0049cba5._DATFileMgrFindEntryByName.md) | [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md) | Normalized name lookup with optional `DATEntryLocation` output. |
| [UID:00043F][0x0049cbb0-0x0049cc39.CreateDATEntryNode](by-memory/0x0049cbb0-0x0049cc39.CreateDATEntryNode.md) | [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) | File-local/static node creation helper; no `this` use. |
| [UID:00043G][0x0049ce50-0x0049d0c2.DATFileResolverInsertOrFindEntry](by-memory/0x0049ce50-0x0049d0c2.DATFileResolverInsertOrFindEntry.md) | [UID:00003J][DATFileResolver](by-class/DATFileResolver.md) | Resolver insert/find member on `_DATFileMgr + 4`, including duplicate-node free and rehash growth. |
| [UID:00043H][0x0049d490-0x0049d4bd.AllocateDATEntryNode](by-memory/0x0049d490-0x0049d4bd.AllocateDATEntryNode.md) | [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) | File-local/static node allocator for sentinel and entry nodes. |
| [UID:00043I][0x0049d5e0-0x0049d6ed.DATFileResolverFindNodeByKey](by-memory/0x0049d5e0-0x0049d6ed.DATFileResolverFindNodeByKey.md) | [UID:00003J][DATFileResolver](by-class/DATFileResolver.md) | Resolver key lookup member using the same `ch + 5*hash` scheme and bucket mask. |

Non-owner overlaps inside [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md) remain rejected from this file's ownership: [UID:00012D][0x0049c130-0x0049d2cc.DATFile](by-memory/0x0049c130-0x0049d2cc.DATFile.md) / [UID:0000IN][DATFile](by-file/DATFile.md) owns DATFile methods and scalar deleting destructor ranges, [UID:00012G][0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert](by-memory/0x0049cc40-0x0049ce48.SimpleUStringVectorGrowAndInsert.md) and neighboring wide-string helpers belong with StringUtil/vector support, and [UID:00012I][0x0049d390-0x0049d3cd.FileBaseDestructor](by-memory/0x0049d390-0x0049d3cd.FileBaseDestructor.md) belongs to `File`. The in-span cleanup/helper ranges `0x0049d0d0-0x0049d175`, `0x0049d180-0x0049d18b`, `0x0049d270-0x0049d275`, `0x0049d2d0-0x0049d349`, `0x0049d350-0x0049d38b`, `0x0049d3d0-0x0049d488`, `0x0049d4f0-0x0049d521`, and `0x0049d5a0-0x0049d5dc` should stay non-emitting evidence or compiler/EH output, not standalone source APIs.

Current source-facing aliases are `DATFileMgr::m_impl`; `_DATFileMgr::m_entriesByName` and `m_archiveContainers`; `DATFileContainer::m_fileHandle`, `m_mappingHandle`, `m_mappedView`, `m_finalPayloadOffset`, `m_entryCount`, and `m_entries`; `DATEntryRecord`; `DATEntryLocation`; `StringBaseA`; `StringBaseW`; and `DATEntryNameHashCompare`. Historical resolver/node/error-helper names and vector-triplet aliases are retained only as descriptions of physical lowering or rejected reconstruction scaffolding, never as source APIs.

Singleton storage evidence: historical session `80de0a67` read bytes `00 00 00 00`, `u32le=0`, and `get_global_value=0x0` at `0x0067ab40`; evidence-time database `bf5519ae` confirms 24 xrefs and the publish/clear lifecycle. Source storage remains `DATFileMgr *g_pDATFileMgr = 0`, while publication/clear source ownership is `Singleton<DATFileMgr>`. Older `ff ff ff ff` wording is historical/stale unless separately proven for a different image.

## Archive Container Vector Source Correction

The physical `_DATFileMgr +0x24/+0x28/+0x2c` triplet is the MSVC representation of one source member, `std::vector<DATFileContainer *> m_archiveContainers`. `LoadDATFileIndex` uses `m_archiveContainers.push_back(container)`. Its full-capacity call at `0x0049c8f0` reaches [UID:00050O][0x00437710-0x00437869.Vector4ByteGrowInsertCompilerSupport](by-memory/0x00437710-0x00437869.Vector4ByteGrowInsertCompilerSupport.md), a cross-module compiler specialization rather than `DATFileContainerVectorAppend` source.

`_DATFileMgr::~_DATFileMgr()` deletes each pointer stored in `m_archiveContainers`. The compiler then invokes the vector member destructor, producing the observed checked storage release and pointer clearing, followed by automatic destruction of `m_entriesByName` in reverse member order. The earlier resolver and manually named append/free models are preserved only as historical descriptions of the lowering.

This correction keeps the exact binary ownership and memory layout while making the reconstructed source look like ordinary mid-2000s C++ rather than a translation of vector internals.

## Container Layout

`DATFileContainer` should expose or encapsulate this mapped archive state:

| Offset | Interpreted field | Notes |
| --- | --- | --- |
| `0x00` | vtable | Virtual destructor support. |
| `0x04` | file handle | Win32 file handle from archive open. |
| `0x08` | mapping handle | Read-only file mapping handle. |
| `0x0c` | mapped view base | Base pointer used by `DATFile` payload reads. |
| `0x10` | final payload boundary | First dword of final 17-byte table row. |
| `0x14` | entry count | First mapped dword. |
| `0x18` | entry table pointer | Mapped view + 4. |

Entry records are 17 bytes: a 4-byte payload offset followed by a 13-byte ANSI entry name. `_DATFileMgr::LoadDATFileIndex` uppercases non-empty names before inserting into the resolver.

## Dependencies

- Provides lookup services consumed by [UID:0000IN][DATFile](by-file/DATFile.md).
- Uses Win32 file, mapping, and view APIs plus project allocator/string helpers.
- Feeds higher-level resource modules such as image libraries, sound, palette, map-name, and dialog loaders through `DATFile` and [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md).

## Historical Open Questions Resolved By Whole-File Closure

- `_DATFileMgr` spelling is resolved by exact RTTI descriptor `.?AV_DATFileMgr@@`; reject unsupported rename `DATFileMgrImpl`.
- `DATFileResolver` should remain a named internal helper/member type in `DATFileMgr.cpp` for reconstruction. Current evidence rejects a standalone `DATFileResolver.cpp`; exact original header spelling remains reviewable but no longer blocks the `_DATFileMgr` class declaration.
- The former DATIndexVector folder question is closed: no standalone source folder or file is emitted. Exact helper pages remain compiler/template-family evidence, while this manager owns only its typed resolver/container declarations and archive policy.

## Score Rationale

- Completion `92`: the file route now has exact public/private/container/resolver ownership, all child routes, Singleton constructor/destructor source shape, private initialization layout, compiler/EH boundaries, deterministic generated ordering, and no-duplicate policy.
- Confidence `92`: RTTI, EH, allocation/layout, caller, vtable/global, and destructor-family evidence independently support the module. Exact private template typedef/member and original header split remain inferred.

## Cross-References

- [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)
- [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md)
- [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md)
- [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md)
- [UID:00003I][DATFileMgr](by-class/DATFileMgr.md)
- [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md)
- [UID:0001XB][DATManagerVtables](by-type/by-vtable/DATManagerVtables.md)
- [UID:0002MA][0x00618910-0x00618918.DATFileMgrVtableData](by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md)
- [UID:0002MB][0x006189c8-0x006189d0._DATFileMgrVtableData](by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md)
- [UID:00003H][DATFileContainer](by-class/DATFileContainer.md)
- [UID:00003J][DATFileResolver](by-class/DATFileResolver.md)
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md)
- [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md)
- [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md)
- [UID:0001P6][0x0067ab40-0x0067ab44.g_pDATFileMgr](by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md)
- [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md)
- [UID:0000YV][0x00467380-0x00467391.DestroyDATFileMgr](by-memory/0x00467380-0x00467391.DestroyDATFileMgr.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- [UID:0000UC][DATEntryRecord](by-item/DATEntryRecord.md)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-08-17 B007 UID0000PA provider-header and WinMain-consumer closure:
  - `DATFileMgr.cpp` now includes `DATFileMgr.h` before exact children; the guarded header owns the complete `0x08` public wrapper declaration, Singleton base, internal-manager pointer, public find/load methods, global extern, and size check.
  - [UID:00019G][0x004f5c80-0x004f5f17.WinMain](by-memory/0x004f5c80-0x004f5f17.WinMain.md) conditionally deletes `g_pDATFileMgr` during updater/abort exit through this typed provider. That consumer does not move the public wrapper, global, internal manager, container, resolver, archive index, or name-lookup implementation out of this source family.
  - Forward declarations keep `_DATFileMgr` and DATEntryLocation implementation-private where a complete public definition is unnecessary; exact method bodies continue to emit from their owning children.

- 2026-08-13 UID0000P3 accepted implementation callback: changed the DAT manager source model from three archive-vector source fields plus manual append/free aliases to `std::vector<DATFileContainer *> m_archiveContainers`, `push_back`, typed destructor iteration, and automatic member teardown; linked the full-capacity call to non-emitting compiler child UID00050O and retained all physical offsets/behavior as historical lowering evidence.

- 2026-07-12 B001 UID000439 accepted implementation callback:
  - Raised score from `90/88` to `92/92` and preserved `NexusTK/archive/DATFileMgr.cpp`/`CANONICAL_OWNER:FILE`.
  - Added exact `Singleton<DATFileMgr>` RTTI/EBO/EH lifetime, public/private constructor/destructor source shape, resolver/vector defaults, root positions `10/20/30/40`, `_DATFileMgr` post-class child marker, historical generated-order defect, and bounded private typedef/header uncertainty.
  - Updated constructor/destructor child map rows and historicalized prior manual-global/manual-clear and evidence-time generated count wording.
- 2026-07-01 B008 DATFileMgr empty-emitter family implementation:
  - Updated score from `89/85` to `90/88`.
  - Added generated-output audit baseline for command `000000003756`, refreshed `2026-07-01T07:16:39-04:00`, with `26` total emitters, `16` filled, `10` empty, `61.5%`, reports `0`.
  - Added the ten-empty-marker disposition table and no-duplicate/source-route policy. Class pages now emit declarations, exact children retain method bodies, vtable/storage pages emit comments/proof only, and duplicate `HasDATEntry` aliases are non-emitting indexes for [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md).
- 2026-06-10 B001-012 DestroyDATFileMgr owner separation:
  - What existed before: the proposed contents table listed [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md) as cleanup glue with DAT object ownership here, leaving room to misread this file as the helper's direct source owner.
  - Changed to: removed the helper from the proposed contents table and clarified that [UID:0000HG][Application](by-file/Application.md) owns the fatal-load helper body while `DATFileMgr.cpp` owns [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) and the manager implementation.
  - Summary/evidence: B001-012 IDA MCP confirmed no DAT manager callers for `0x00467380`, 22 paired fatal resource-load cleanup callers, normal `g_pDATFileMgr` lifecycle writes/clears in the DAT manager cluster, and Application/startup neighboring helper context.

- Before: this file listed only the public wrapper load forwarder at `0x0049be70-0x0049be7c`.
- Changed to: include the adjacent public find-entry forwarder at `0x0049bd20-0x0049bd2c`.
- Summary/evidence: IDA/raw disassembly shows `mov ecx, [ecx+4]; jmp sub_49CAD0`, matching a public `DATFileMgr` wrapper around the internal `_DATFileMgr::FindEntryByName`.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:82`.
  - Summary/evidence: public/private manager ownership, container/resolver helpers, singleton/global helper ownership, exact manager ranges, container layout, dependencies, open helper-name questions, and forwarder corrections are documented; confidence is strong with remaining uncertainty around original internal helper class names.
- 2026-05-31 reconstruction path and IDA recheck:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, scores were `88/82`, and the module path used `archive/DATFileMgr.cpp` without an explicit generated root.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/archive/"`, scores `89/84`, and proposed module `NexusTK/archive/DATFileMgr.cpp`.
  - Summary/evidence: IDA MCP reconfirmed the public/private manager wrapper pattern, mapped-container construction, `HasDATEntry`, internal load/find helpers, resolver cleanup, singleton-facing ownership, and vtable adjacency caveat. No C++ reconstruction code is emitted yet because method-level source rewrites, helper class naming, and neighboring ranges remain below the `95+` final-code gate.
- 2026-05-31 exact vtable child pages:
  - What existed before: this file described the one-slot vtables through [UID:0001XB][DATManagerVtables](by-type/by-vtable/DATManagerVtables.md) only.
  - Changed to: added exact by-memory vtable-data children for `DATFileMgr` and `_DATFileMgr`.
  - Summary/evidence: IDA MCP `list_globals`, `xrefs_to`, and dword scan prove `0x00618910-0x00618918` and `0x006189c8-0x006189d0` as exact vtable-data records with non-slot boundaries immediately after each.
- 2026-06-07 A006 Batch 083:
  - Changed score from `89/84` to `89/85`.
  - Summary/evidence: live IDA MCP reconfirmed the public wrapper, internal manager, container, resolver, free helper, and vtable boundaries as one archive manager source module. Remaining confidence is capped by unresolved original private helper names, not by source-file ownership.
- 2026-06-18 B005 DAT resolver source-quality incorporation:
  - Changed the `DATFileResolver` row and open-question text to a resolved current source-shape decision.
  - Summary/evidence: raw export and local byte checks for [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) confirm the resolver cleanup is reached only through `_DATFileMgr` teardown, with field layout and helper roles resolved strongly enough for first-draft cleanup C++ on the child page. Keep the type as an internal helper/member in this source file, not as standalone `DATFileResolver.cpp`.
- 2026-06-19 B015 `_DATFileMgr` source-quality incorporation:
  - Updated the private implementation row, manager method map, file-level rationale, and open questions to reflect declaration-ready `_DATFileMgr` source shape.
  - Summary/evidence: the report incorporates current raw destructor, resolver cleanup, vtable, wrapper, singleton, and export evidence; `_DATFileMgr +0x04..+0x23` is now `DATFileResolver m_resolver`, `+0x24/+0x28/+0x2c` are the archive-container vector triplet, `InsertOrFindEntry`/`FindNodeByKey` belong to the resolver subobject, and node allocation/creation are file-local/static helpers.
- 2026-06-26 B001 [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md) source-quality implementation:
  - Updated the proposed contents row, manager range row, file-level rationale, and manager-owned child emission map for the public find-entry wrapper.
  - Summary/evidence: [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md) remains routed through `NexusTK/archive/DATFileMgr.cpp` and [UID:00003I][DATFileMgr](by-class/DATFileMgr.md), now with formal child C++ for `DATFileMgr::FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation)`; the wrapper's no-function/no-xref state stays documented on the child page as confidence-capping evidence, not a source-placement blocker.
