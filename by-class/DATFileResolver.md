*** UID:00003J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:97 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DATFileResolver

## 2026-08-18 Historical Semantic Overlay Disposition

`DATFileResolver` is not an authored project class. It is the historical analysis name for `_DATFileMgr`'s 0x20 old-MSVC/Dinkumware `stdext::hash_map<StringBaseW, DATEntryLocation, DATEntryNameHashCompare>` member. Sentinel/list state, load factor, eight initial buckets, hash/ordering, insert/find/rehash, allocation, and destruction behavior remain valuable binary evidence, but typed owner-local standard-container source generates every observed helper range. This page therefore has no source path, owner, emitter, CPP, or H code.

## Status

- Confidence: very high that the physical state is old-MSVC/Dinkumware `stdext::hash_map` lowering; the former project-class interpretation is rejected.
- Source path: none. [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md) owns the typed `EntryMap` member whose compiler output this page indexes.
- Address range: [UID:00012B][0x0049bd30-0x0049d6ed.DATManagers](by-memory/0x0049bd30-0x0049d6ed.DATManagers.md)
- Source-facing placement: non-emitting historical semantic overlay for the typed map embedded in [UID:000004][_DATFileMgr](by-class/_DATFileMgr.md).
- Reconstructable: false; owner/emitter and formal CPP/H are blank. Exact cleanup/insert/find/node pages are compiler/template evidence, not authored project APIs.
- Root emitter position: none.

## Historical Class-Purpose Hypothesis

`DATFileResolver` is the current documentation name for the DAT manager's internal resolver/hash-table state. It owns the bucket vector and list sentinel used to resolve uppercase entry names to archive container and entry-index pairs.

This was an embedded STL-like hash/list member inside `_DATFileMgr`. The current accepted source model rejects `DATFileResolver` as a source-facing type and emits `EntryMap m_entriesByName` instead.

## Historical Layout Alias Evidence

The superseded resolver model described this physical shape; the offsets remain valid evidence for the current typed `EntryMap` member:

| Resolver offset | Interpreted role | `_DATFileMgr` offset |
| --- | --- | --- |
| `+0x00` | load factor / first resolver word | `+0x04` |
| `+0x04` | circular list sentinel pointer | `+0x08` |
| `+0x08` | indexed entry count | `+0x0c` |
| `+0x0c` | bucket/vector begin | `+0x10` |
| `+0x10` | bucket/vector end | `+0x14` |
| `+0x14` | bucket/vector capacity | `+0x18` |
| `+0x18` | bucket mask used by `FindNodeByKey` and `InsertOrFindEntry` | `+0x1c` |
| `+0x1c` | bucket count / max bucket index used by load-factor rehash | `+0x20` |

Generated and aggregate manager notes also describe hash mask/count state in the wider resolver area. B002 historically used aliases `m_maxLoadFactor`, `m_entryListSentinel`, `m_entryCount`, `m_bucketsBegin`, `m_bucketsEnd`, `m_bucketsCapacity`, `m_bucketMask`, and `m_bucketCount`. These names are inferred physical aliases, not recovered original symbols and not source declarations.

Associated inferred helper/type names were historical reverse-engineering scaffolding. Their ranges are retained as compiler/template evidence and emit no child C++.

Evidence-time UID000439 constructor analysis confirms the complete default state: zero initial list/count/bucket storage, a 20-byte circular sentinel allocated with null next/previous inputs, max load factor `1.0f`, and eight initial buckets before `_DATFileMgr` archive-vector construction. The 0x20-byte layout and helper behavior are strongly compatible with period MSVC/Dinkumware hash-map/list/bucket lowering. `DATFileResolver` remains the accepted human reconstruction alias because no surviving symbol proves exact comparator, allocator, or container typedef spelling; this confidence cap does not block source ordering or public constructor C++.

## Historical Method Labels And Current Compiler Disposition

| Method | Address | Role |
| --- | --- | --- |
| `InsertOrFindEntry` | `0x0049ce50-0x0049d0c2` | Inserts or finds a normalized uppercase DAT entry key in the resolver/hash-table structure reached as `_DATFileMgr + 4`; source-facing ownership is this resolver subobject, not the outer manager instance. |
| `~DATFileResolver` / `Destroy` | [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) | Destructor-style cleanup called from both `_DATFileMgr` teardown bodies; frees bucket storage, walks entry nodes, releases wide-string keys, frees nodes, and frees the sentinel. |
| `FindNodeByKey` | `0x0049d5e0-0x0049d6ed` | Searches the resolver's uppercase-name index; called through the same `_DATFileMgr + 4` subobject route. |

B002 historically routed resolver member C++ to these exact child pages. Current source closure keeps all four linked ranges plus UID00012H as non-emitting compiler/template evidence generated by `EntryMap m_entriesByName`; none is an authored helper or method. Ranges `0x0049d0d0-0x0049d175`, `0x0049d4f0-0x0049d521`, and `0x0049d5a0-0x0049d5dc` likewise remain cleanup/EH/compiler evidence rather than public APIs.

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
- 2026-06-15 live IDA MCP recheck on session `a003_objectlist_dispatch_20260615` reconfirms `sub_49D190` size `0xdc`, raw `_DATFileMgr` ordinary destructor start `0x0049c750` as `Not a function`, `_DATFileMgr::DeletingDestructor` `sub_49D3D0` size `0xb8`, and resolver-user context functions `sub_49C800` size `0x2c4`, `sub_49CAD0` size `0xd5`, `sub_49CE50` size `0x272`, and `sub_49D5E0` size `0x10d`.
- Current `xrefs_to(0x0049d190)` still returns exactly the raw ordinary destructor call at `0x0049c7e8` plus deleting-destructor call `0x0049d462`. `xrefs_to(0x006189cc)` returns the public wrapper constructor store `0x0049bda1`, raw cleanup store `0x0049c755`, and deleting destructor store `0x0049d3dd`, matching the embedded `_DATFileMgr` resolver lifecycle.
- `analyze_component` over the resolver context reports internal edges `0x0049c800 -> 0x0049ce50`, `0x0049c800 -> 0x0049cad0`, recursive `0x0049ce50`, `0x0049cad0 -> 0x0049d5e0`, and `0x0049d3d0 -> 0x0049d190`; this ties cleanup to the same load/find/insert resolver family without making the resolver a proven standalone class. `make_signature_for_range(0x0049d190,0x0049d26c)` returns a unique wildcarded signature for the destroy method.
- 2026-06-18 B005 local raw-export and byte-scan reanalysis confirms the resolver field map through `+0x1c`: constructor `0x0049bd30` writes max load factor `1.0f`, allocates the 0x14-byte sentinel, sizes the initial bucket vector, and clears archive-vector fields; sibling load/find/insert helpers prove the bucket mask/count fields; the cleanup child frees vector storage with MSVC large-allocation validation and then releases each wide-string key/node before freeing the sentinel.
- 2026-06-19 B015 `_DATFileMgr` class reanalysis confirms that resolver behavior is broader than the cleanup child: `0x0049ce50` is best named `DATFileResolver::InsertOrFindEntry`, `0x0049d5e0` is best named `DATFileResolver::FindNodeByKey`, and `0x0049d190-0x0049d26c` remains `DATFileResolver::~DATFileResolver()` / cleanup. The type is an internal member/helper in `DATFileMgr.cpp`, not a standalone source file.
- 2026-06-26 B002 implementation adds formal child C++ routes for `InsertOrFindEntry` and `FindNodeByKey`, plus file-local node allocation/creation helpers. The resolver hash is represented as `hash = ch + 5 * hash`, bucket selection uses `hash & m_bucketMask`, duplicate insertions unlink/free the newly created node and return `(existingNode, inserted=false)`, and bucket growth is `*8` below `0x200` buckets and `*2` above that. These facts belong on resolver child pages and should not be compressed to generic "hash-table helper" wording.

## Score Rationale

- Completion is `88` because the class now links the source parent, embedded `_DATFileMgr` layout through `+0x1c`, exact cleanup child, two destructor callers, vtable-backed deleting destructor, archive-manager ownership boundary, current resolver context call graph, vtable-store xrefs, a unique destroy-method signature, and an implementation-ready internal resolver declaration.
- Confidence is `91` because the executable cleanup behavior, offsets, callers, vtable stores, context functions, parent source owner, and child method routes are strongly documented; it remains capped because exact original type/header spelling and final public API exposure are still not proven.

## 2026-07-01 B008 Empty-Emitter Repair

This class now emits only the internal `DATFileResolver` declaration and `[[CHILDREN]]` marker. Exact method bodies remain on [UID:00043G][0x0049ce50-0x0049d0c2.DATFileResolverInsertOrFindEntry](by-memory/0x0049ce50-0x0049d0c2.DATFileResolverInsertOrFindEntry.md), [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md), and [UID:00043I][0x0049d5e0-0x0049d6ed.DATFileResolverFindNodeByKey](by-memory/0x0049d5e0-0x0049d6ed.DATFileResolverFindNodeByKey.md). The source route remains embedded `_DATFileMgr + 4` state inside [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md), not a standalone `DATFileResolver.cpp`.

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

- 2026-07-12 B001 UID000439 accepted implementation callback:
  - Set root emitter position `20` while preserving score `88/91`, owner/emitter UID0000IO, formal class payload, and all resolver children.
  - Added constructor-proven sentinel/load-factor/eight-bucket default state, period MSVC container compatibility, complete-type ordering, and exact original typedef confidence cap.
- 2026-07-01 B008 DATFileMgr empty-emitter family implementation:
  - Raised score from `86/89` to `88/91`.
  - Added formal internal resolver declaration C++ with bucket/list fields, resolver methods, and `[[CHILDREN]]`.
  - Preserved embedded `_DATFileMgr + 4` source-shape proof and exact child method body ownership.
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
- 2026-06-15 A002 Goal 2 by-class refresh: raised from `82/86` to `85/88` with no owner/emitter changes. Live IDA reconfirmed the cleanup method size, raw destructor non-function state, exact cleanup callers, `_DATFileMgr` vtable-store xrefs, resolver load/find/insert context call graph, and unique destroy-method signature. C++ remains blank because standalone class status and final source-level field names are still unresolved.
- 2026-06-18 B005 source-quality reanalysis: raised from `85/88` to `86/89`. Raw export, local byte scans, constructor context, find/insert helpers, and target destructor behavior resolve the field map through `+0x1c` and the source-shape question: keep `DATFileResolver` as an internal `_DATFileMgr` helper/member type in `DATFileMgr.cpp`, not as a standalone file. The exact cleanup child [UID:00012H][0x0049d190-0x0049d26c.DATFileResolverDestroy](by-memory/0x0049d190-0x0049d26c.DATFileResolverDestroy.md) is first-draft C++ ready; the broader class page remains below final-source C++ because exact original type/header spelling is still not proven.
- 2026-06-19 B015 `_DATFileMgr` support incorporation: score and owner/emitter metadata unchanged. The method inventory now includes `DATFileResolver::InsertOrFindEntry` and `DATFileResolver::FindNodeByKey`, both reached through `_DATFileMgr + 4`, so generated/raw helper names no longer leak into the source-routing policy.
