*** UID:0000IO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/archive/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# DATFileMgr

## Status

- Confidence: strong for manager/container ownership and direct archive-module placement, medium-high for the original private helper class names.
- Proposed module: `NexusTK/archive/DATFileMgr.cpp`
- Current recovered files: `source-3/simroot_v2/class_DATFileMgr.cpp`, `class__DATFileMgr.cpp`, `class_DATFileContainer.cpp`, `class_DATFileResolver.cpp`, and `HasDATEntry_0049C700`.
- Evidence basis: Wave3 class summaries and missing-ref checks, generated class/layout notes, IDA MCP function boundary checks, raw disassembly, and caller/callee inspection through 2026-05-26.

## Proposed Contents

This file should own the global archive manager, mapped archive containers, the internal uppercase-name index, and global entry-existence checks.

| Entity | Range | Proposed placement | Notes |
| --- | --- | --- | --- |
| [UID:00003I][DATFileMgr](by-class/DATFileMgr.md) | `0x0049bd30-0x0049d38b` aggregate | `archive/DATFileMgr.cpp` | Public wrapper around an internal manager object. |
| [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md) | `0x0049c750-0x0049d6ed` aggregate | `archive/DATFileMgr.cpp` | Internal archive vector and name-index manager; includes raw ordinary destructor at `0x0049c750`. |
| [UID:00003H][DATFileContainer](by-class/DATFileContainer.md) | `0x0049be80-0x0049d349` aggregate | `archive/DATFileMgr.cpp` | One memory-mapped DAT archive container. |
| [UID:00003J][DATFileResolver](by-class/DATFileResolver.md) | [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) | `archive/DATFileMgr.cpp` internal helper/member | Resolver/hash-table cleanup; likely not a separate original source-level class. |
| [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md) | `0x0049bd20-0x0049bd2c` | `archive/DATFileMgr.cpp` | Public wrapper forwarding to `_DATFileMgr::FindEntryByName`. |
| [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md) | `0x0049be70-0x0049be7c` | `archive/DATFileMgr.cpp` | Public wrapper forwarding to `_DATFileMgr::LoadDATFileIndex`. |
| [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) | [UID:00012E][0x0049c700-0x0049c71d.HasDATEntry](by-memory/0x0049c700-0x0049c71d.HasDATEntry.md) | `archive/DATFileMgr.cpp` | Global boolean probe against the archive manager. |
| [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) | [UID:0001P6][0x0067ab40-0x0067ab44.g_pDATFileMgr](by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md) | `archive/DATFileMgr.cpp` | Public manager singleton pointer used by `DATFile::Open`, `HasDATEntry`, startup, and shutdown. |
| [UID:0002MA][0x00618910-0x00618918.DATFileMgrVtableData](by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md) | `0x00618910-0x00618918` | compiler-emitted from `DATFileMgr` declaration | Exact public-wrapper RTTI pointer plus one scalar-deleting-destructor vtable slot. |
| [UID:0002MB][0x006189c8-0x006189d0._DATFileMgrVtableData](by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md) | `0x006189c8-0x006189d0` | compiler-emitted from `_DATFileMgr` declaration | Exact internal-manager RTTI pointer plus one scalar-deleting-destructor vtable slot. |

## Manager And Container Ranges

IDA MCP confirms these modeled function starts and raw-disassembly ranges:

| Range | Owner | Role |
| --- | --- | --- |
| [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md) | `DATFileMgr::FindEntryByName` candidate | Public wrapper forwarding to `_DATFileMgr::FindEntryByName`. |
| `0x0049bd30-0x0049be41` | `DATFileMgr` | Constructor for the public wrapper and internal manager pointer. |
| [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md) | `DATFileMgr::LoadDATFile` candidate | Public wrapper forwarding to `_DATFileMgr::LoadDATFileIndex`. |
| `0x0049d350-0x0049d38b` | `DATFileMgr` | Scalar deleting destructor. |
| `0x0049be80-0x0049c0c9` | `DATFileContainer` | Opens a DAT file, creates a read-only mapping, maps the view, and initializes entry table pointers. |
| `0x0049d2d0-0x0049d349` | `DATFileContainer` | Unmaps view, closes mapping/file handles, clears fields, and optionally deletes. |
| [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md) | `_DATFileMgr` | Raw ordinary destructor body; IDA has no function object at this start, but disassembly shows archive-vector teardown and resolver cleanup. |
| `0x0049c800-0x0049cac4` | `_DATFileMgr::LoadDATFileIndex` | Loads one archive container and indexes each non-empty uppercase entry name. |
| `0x0049cad0-0x0049cba5` | `_DATFileMgr::FindEntryByName` | Lookup target used by `DATFile::Open`. |
| `0x0049cbb0-0x0049cc39` | `_DATFileMgr::CreateEntryNode` | Allocates/initializes a name-index node. |
| `0x0049ce50-0x0049d0c2` | `_DATFileMgr::InsertOrFindEntry` | Inserts or finds a normalized name in the resolver structure. |
| [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) | `DATFileResolver::Destroy` | Frees bucket vector, list sentinel, nodes, and key strings. |
| `0x0049d3d0-0x0049d488` | `_DATFileMgr::DeletingDestructor` | Releases resolver and archive-vector state, then optionally deletes. |
| `0x0049d490-0x0049d4bd` | `_DATFileMgr::AllocateNode` | Allocates index node storage. |
| `0x0049d5e0-0x0049d6ed` | `_DATFileMgr::FindNodeByKey` | Searches the uppercase-name index. |

## File-Level Rationale

- `DATFileMgr` and `_DATFileMgr` are a public/private manager pair; splitting them into separate recovered files is a Wave3 staging artifact.
- Their vtables are short one-slot tables: `DATFileMgr` at `0x00618914` and `_DATFileMgr` at `0x006189cc`. See [UID:0001XB][DATManagerVtables](by-type/by-vtable/DATManagerVtables.md) before adding any adjacent data as method slots.
- Exact by-memory vtable-data pages now split these records as [UID:0002MA][0x00618910-0x00618918.DATFileMgrVtableData](by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md) and [UID:0002MB][0x006189c8-0x006189d0._DATFileMgrVtableData](by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md). These are source-declared/generated-binary data, not hand-authored static arrays.
- [UID:00012F][0x0049c750-0x0049c7f6._DATFileMgrRawDestructor](by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md) should be reconstructed as `_DATFileMgr`'s ordinary destructor or equivalent cleanup body even though current IDA does not model it as a function. It mirrors the archive-vector/resolver teardown in `_DATFileMgr::DeletingDestructor` without the conditional object free.
- [UID:000227][0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder](by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md) is the same public/private forwarding pattern for `_DATFileMgr::FindEntryByName`; it appears immediately before the public wrapper constructor.
- [UID:00012C][0x0049be70-0x0049be7c.ForwardLoadDATFileIndex](by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md) is a tiny public method wrapper over `_DATFileMgr::LoadDATFileIndex`. Its older `ForwardLoadDATFileIndex_49BE70` recovery alias should not make it a free global in the final source layout.
- `DATFileContainer` belongs in this file because `_DATFileMgr::LoadDATFileIndex` constructs containers while building the archive list and global name index.
- `DATFileResolver` appears to be the resolver/hash-table subobject inside `_DATFileMgr`, not a standalone project feature.
- [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md) has 17 IDA-observed callers across PCX loading, image-frame loading, tile metadata, effect/table building, palette/resource checks, sound/resource paths, and other DAT consumers. The helper probes [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) and therefore belongs beside the manager rather than beside the per-entry stream reader.
- [UID:0000UF][DestroyDATFileMgr_467380](by-item/DestroyDATFileMgr_467380.md) at `0x00467380-0x00467391` is not a direct `DATFileMgr.cpp` helper after the B001-012 owner audit. It deletes the active manager through [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md), but IDA shows it is called only from paired Application/startup fatal image/resource cleanup paths, so [UID:0000HG][Application](by-file/Application.md) owns the helper body while this file retains object/singleton ownership.
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) is not manager-private. IDA MCP caller checks on 2026-05-24 show its resize/insert/find helpers are also used by minimap, fitting-room, and monster-image state, so it should remain a standalone helper module even though `_DATFileMgr` calls the same support routines.
- 2026-05-31 IDA MCP recheck confirms the public wrapper constructor at `0x0049bd30`, the public load-index forwarder at `0x0049be70`, container construction at `0x0049be80`, `HasDATEntry` at `0x0049c700`, internal load/find helpers at `0x0049c800` and `0x0049cad0`, resolver cleanup at `0x0049d190`, and the internal deleting destructor at `0x0049d3d0`. The recheck also confirms that the public and internal vtable symbols sit adjacent to unrelated RTTI/vtable data, so slot interpretation must stay constrained to documented owner-specific entries.
- 2026-06-07 Batch 083 live IDA MCP recheck reconfirmed the direct parent gate for [UID:00003I][DATFileMgr](by-class/DATFileMgr.md): public wrapper constructor `0x0049bd30-0x0049be41`, public load-index wrapper `0x0049be70-0x0049be7c`, scalar deleting destructor `0x0049d350-0x0049d38b`, no modeled function at raw forwarder `0x0049bd20` or raw ordinary internal cleanup `0x0049c750`, and `_DATFileMgr` helper boundaries through `0x0049d6ed`. Vtable references at `0x00618914` and `0x006189cc` come from the public constructor/destructors and raw cleanup bytes, matching the documented one-source-module public/private manager relationship.

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

## Open Questions

- Confirm the original name of `_DATFileMgr`; the leading underscore may be a decompiler/projected name for a private implementation class.
- Decide whether `DATFileResolver` should remain as a named class in source or become an internal struct/member in `_DATFileMgr`.
- Confirm whether `DATIndexVector`'s final folder should be `archive/` or a common/helper folder. Current evidence rules out folding it into this manager file.

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
