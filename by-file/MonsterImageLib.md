*** UID:0000LJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# MonsterImageLib

## 2026-08-18 Complete CPP And H Route

- Current source pair is exactly NexusTK/render/MonsterImageLib.cpp and NexusTK/render/MonsterImageLib.h.
- H owns the complete [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) declaration, typed hash-map caches, known public/private API, singleton extern, and exact 0x5c size guard. CPP includes H, receives the one external singleton definition from [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md), and emits class children once.
- Known file-owned authored inventory is LoadMonsterTables, constructor, ordinary destructor, RenderMonster at 0x004db100-0x004db329, GetEntryByIndex, RenderMonsterImage, ComputeRenderBounds, BuildMergedRenderState, LoadMonsterArchives, GetArchiveBoundsBucket, ResolveMonsterArchiveBounds, raw local archive-bounds work, and ClearLoadedData. The scalar deleting destructor, static-lifetime helper, vtable/RTTI, folded hash-map helpers, and allocator/EH paths remain compiler or private-library output rather than handwritten duplicate source.
- Resource ownership remains MONSTER.DNA or MONSTER.DND and DATA/MON%d.DAT. ObjectImage is one UI preview consumer and does not own this render module.
- The exact two cache members are stdext::hash_map instances. DATIndexVector remains only a historical/non-emitting index for folded old-library lowering.
- Scores are now 91/92 after declaration/source/global closure. Remaining limitations are broader private-body reconstruction, exact original lexical spellings, and absent rebuilt-binary comparison.
- Historical note: earlier 89/89 and CPP-only/empty-H checkpoints described incomplete generated source. They remain dated evidence and are not current source authority.

## 2026-08-17 Standard-Container Dependency Correction

MonsterImageLib owns its archive/cache policy and payload types. Its two `0x20` indexes are source-facing `stdext::hash_map<int, DATFile *>` and `stdext::hash_map<int, MonsterArchiveBoundsBucket *>`; [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) is only a non-emitting index for their folded old-MSVC/Dinkumware implementation. No standalone DATIndexVector source or include is required.

## Status

- Confidence: strong for class role, resource ownership, singleton/vtable lifetime, source parent placement, current empty-emitter dispositions, and concrete default/singleton storage corrections; medium-high for final whole-class declaration and unreconstructed method bodies.
- Proposed module: `render/MonsterImageLib.cpp`
- Autogen root: `auto-generated/NexusTK/render/MonsterImageLib.cpp`
- Main address ranges: `0x004dac40-0x004dc420`, singleton clear helper `0x004e5bd0-0x004e5bdb`, vector helper `0x004e5990-0x004e5a62`, and scalar destructor `0x004e6750-0x004e6860`
- Primary global instance: [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md) at `0x0069b440`
- Primary vtable: [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md) at `0x0061b6e4`
- Object layout: [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 91 | The complete CPP/H source pair, 0x5c class declaration, known public/private API including RenderMonster, typed stdext::hash_map caches at +0x1c/+0x3c, one external singleton definition plus guarded extern, resource/archive ownership, constructor/destructor/cache lifetime, render/bounds responsibilities, exact default-table storage, helper ownership, and all compiler/no-code dispositions are documented. Broader private method bodies remain outside this whole-file closure and retain the score cap without making the declaration or route unresolved. |
| Confidence | 92 | Exact layout offsets, function/range evidence, singleton/vtable/default-table storage, all 22 singleton xrefs, external-linkage requirement, typed cache identities, RenderMonster's caller/ABI, and the ordered formal CPP/H route agree. Remaining limits are original member/method spellings, broader unreconstructed private bodies, and absent rebuilt-binary comparison; the former incomplete-declaration and 89/89 rationale is superseded. |

## File Role

`MonsterImageLib` is the monster sprite image library. It owns monster animation table parsing, monster DAT archive indexing, cached archive-bounds loading, render dispatch, palette/direct draw selection, projection/bounds calculations, singleton lifetime, and teardown.

This should remain a distinct render/image module. It is a DAT consumer, but it opens monster-specific `DATA/MON%d.DAT` archives and parses monster-specific `MONSTER.DNA`/`MONSTER.DND` data rather than owning the generic DAT archive format.

[UID:0000M3][ObjectImageControlPane](by-file/ObjectImageControlPane.md) is a concrete UI preview consumer of this module's monster path: the object-image control's status-kind `1` branch calls [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md), uses `0x004db5c0` as `ComputeRenderBounds`, and uses `0x004db3b0` as `RenderMonsterImage` with a preview/render-mode constant. This is consumer evidence only; it does not move monster image-library ownership into the UI control file.

## Resource Inputs

| Resource | Role |
| --- | --- |
| `MONSTER.DNA` | Compact/new monster animation table when `g_usesCompactMonsterTable` is nonzero. |
| `MONSTER.DND` | Alternate/legacy monster animation table. |
| `DATA/MON%d.DAT` | Numbered monster image archives scanned by `LoadMonsterArchives` and lazy bounds loading. |

Monster ids are commonly rebased by `+32768` before table lookup, matching the `kMonsterEntryBase` constant in render methods.

[UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) is the exact table-loader range currently proving the 0x0c [UID:0001VC][MonsterImageEntry](by-type/by-struct/MonsterImageEntry.md) row layout and nested animation-table allocation flow.

The loader also owns the concrete monster default/fallback outer table storage at [UID:00029K][0x0069b424-0x0069b430.ImageLibraryFallbackRecord](by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md). The accepted source-facing name for that static 12-byte object is `g_defaultMonsterAnimationTable`. It is initialized by the shared table helper constructor, allocated with `0x15` / 21 default groups (Verified with int_convert.py) by `LoadMonsterTables`, seeded with one frame entry per group (`frameOffset = 0`, `frameDuration = 30000`, `blendAlpha = 0`), and returned by the monster table lookup when an index is out of range. The helper type remains documented by [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md), so this page records concrete monster-image state rather than claiming exclusive helper implementation ownership.

## 2026-06-25 LoadMonsterTables Source Sync

The accepted B001 implementation moves [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) to the [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) class owner/emitter, while this file remains the final source root for the generated method.

File-level facts preserved here:

- The resource branch remains `MONSTER.DNA` when `g_usesCompactMonsterTable` is nonzero and `MONSTER.DND` otherwise.
- `LoadMonsterTables` reads a 32-bit row count, allocates 12-byte [UID:0001VC][MonsterImageEntry](by-type/by-struct/MonsterImageEntry.md) rows, stores row pointer/count in the `MonsterImageLib` object, and fills nested shared animation table records.
- The formal method C++ now uses inferred source-facing names `ImageAnimationGroup` and `ImageAnimationFrame` for the shared 8-byte group and 10-byte frame records. Raw helper labels remain evidence aliases only in support docs.
- The default table source-facing name is `g_defaultMonsterAnimationTable`; concrete storage is [UID:00029K][0x0069b424-0x0069b430.ImageLibraryFallbackRecord](by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md), and shared frame fallback data remains [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md).
- The accepted field correction supersedes old helper-family wording that described frame entry `+0x02` as `endFrame` or `+0x04` as `direction` for the shared type. Current monster evidence supports `frameDuration` and `blendAlpha`.

## 2026-06-25 Destructor Source Sync

The accepted B011 implementation moves [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md) to [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) as direct owner/emitter while this file remains the final generated source root.

File-level facts preserved here:

- [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md) now contributes formal `MonsterImageLib::~MonsterImageLib()` C++ to `auto-generated/NexusTK/render/MonsterImageLib.cpp` through the class route.
- The formal source body is `ClearLoadedData(); delete[] m_monsters;`. The target docs record why member destructors for `m_boundsBucketIndex`, `m_openArchiveIndex`, and `m_archiveOffsets`, the [UID:000370][0x004f4a90-0x004f4a97.LObjectDestructorBody](by-memory/0x004f4a90-0x004f4a97.LObjectDestructorBody.md) base cleanup, singleton clear, EH state, and allocator checks are compiler-lowered output rather than handwritten source statements.
- [UID:0003M1][0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor](by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md) remains blank source-declared/generated-binary scalar wrapper output. The ordinary destructor source body, plus the class declaration/vtable layout, should regenerate the wrapper and delete-flag logic.
- Old generated `76/86` rows and the empty emitter marker for [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md) were stale generated state at report time. They should refresh from source metadata through the scoped validator; do not hand-edit generated files or generated `-ag-*` reports.
- Direct file owner remains rejected as the semantic owner for the destructor body. This file is the source root reached through the class emitter, not the narrow method owner.

## 2026-06-27 GetArchiveBoundsBucket No-Code Sync

[UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md) is the exact class-owned lazy bounds-bucket loader for numbered `DATA/MON%d.DAT` archives. It now emits through [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) into this source root as an empty marker/no-code child, not as disabled or excluded code.

File-level facts preserved here:

- Live MCP session `80de0a67` reconfirmed the `0x004dbe60` function size `0x315`, callers from `ComputeRenderBounds` and `ResolveMonsterArchiveBounds`, UTF-16 `DATA/MON%d.DAT` string bytes at `0x0061c07c`, and the raw local call at `0x004dc279`.
- The method uses the `MonsterImageLib` layout caches `m_openArchiveIndex` at `+0x1c` and `m_boundsBucketIndex` at `+0x3c`; it opens a missing DAT reader, caches it, allocates/caches a 0x0c [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md), reads the 8-byte bucket header, allocates 0x18-byte [UID:0001VB][MonsterArchiveBoundsEntry](by-type/by-struct/MonsterArchiveBoundsEntry.md) rows plus a sentinel, and rebases payload pointers by the DAT payload base.
- The formal method body stays blank because complete DAT-reader ownership and broader MonsterImageLib class declarations remain incomplete. Typed standard-map `find`/`insert` vocabulary is resolved and does not require raw node/list internals.
- The IDA-undefined local helper/gap at `0x004dc240-0x004dc2db` remains outside [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md) and outside this file-level C++ body until a separate split/modeling pass creates an exact child.

## 2026-06-30 B011 Empty-Emitter Family Implementation

The accepted B011 report `tools/leaser/Agents/Agent-B011/research/0000LJ-MonsterImageLib-empty-emitter-family-source-quality.md` resolves the 15 empty markers that were present in `auto-generated/NexusTK/render/MonsterImageLib.cpp` after validator command `000000002929` (`refreshed: 2026-06-30T14:34:45-04:00`). This file remains the source root; implementation is distributed through the class, type, global, memory, vtable, and item pages listed below.

Current disposition by UID:

- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) now emits a source-owner marker plus `[[CHILDREN]]`. The class audit covers constructor/destructor route, vtable slots, method inventory, field offsets, base class evidence, and why a full class declaration is still unsafe.
- [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md) emits a target-specific no-code marker. The method is real and class-owned; its remaining blockers are DAT-reader ownership and complete class declarations, not the now-resolved typed standard-map API.
- [UID:0003M1][0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor](by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md) emits a compiler-generated scalar-deleting-destructor marker. The authored destructor source remains [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md).
- [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md), [UID:0001VB][MonsterArchiveBoundsEntry](by-type/by-struct/MonsterArchiveBoundsEntry.md), and [UID:0001VC][MonsterImageEntry](by-type/by-struct/MonsterImageEntry.md) now emit source-facing struct declarations through the class route.
- [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md) emits an evidence-only layout marker. It documents the actual `MonsterImageLib` object layout and must not become a duplicate ABI struct.
- [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md) and [UID:0002MM][0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData](by-memory/0x0061b6e0-0x0061b6f0.MonsterImageLibVtableData.md) emit compiler-generated vtable/data markers rather than handwritten vtable arrays.
- Historical B011 checkpoint: [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md) then emitted a file-local `static MonsterImageLib *g_pMonsterImageLib = NULL;`. The accepted 2026-08-18 closure supersedes that route with one external definition plus one guarded H extern because 22 cross-module references reject internal linkage.
- [UID:0001PN][0x0069b440-0x0069b444.g_pMonsterImageLib](by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md) now records the current MCP zero-filled storage correction and emits a covered-by marker instead of a second pointer definition.
- [UID:0000VK][VectorGrowArchiveIndex_004E5990](by-item/VectorGrowArchiveIndex_004E5990.md) is now a non-reconstructable item/index alias. Exact executable behavior is documented by [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md).
- [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md) emits a target-specific no-code marker for the compiler-lowered 4-byte archive-offset vector grow path inside `LoadMonsterArchives`.
- B011's accepted UID00022R split gives the storage replacement/free dependency an exact child, [UID:0004DM][0x004e6df0-0x004e6e49.VectorStorageReplaceForArchiveIndex](by-memory/0x004e6df0-0x004e6e49.VectorStorageReplaceForArchiveIndex.md). It has one observed caller, `0x004e5a4a` inside [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md), and follows this MonsterImageLib/UID0002VF source-disposition route rather than generic [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md).
- [UID:000181][0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper](by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md) now emits the file-local static cleanup helper `ClearMonsterImageLibSingleton`.
- [UID:00029K][0x0069b424-0x0069b430.ImageLibraryFallbackRecord](by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md) now emits `static ImageAnimationTable g_defaultMonsterAnimationTable;` and corrects the stale all-`0xff` storage assumption to current zero-filled storage.

The B011 MCP evidence that drives this sync used active session `supervisor_resume_20260629`. It reconfirmed function sizes for constructor `0x004daec0` (`0x14e`), `LoadMonsterTables` `0x004dac40` (`0x27d`), `LoadMonsterArchives` `0x004dbc60` (`0x19b`), `GetArchiveBoundsBucket` `0x004dbe60` (`0x315`), `VectorGrowArchiveIndex` `0x004e5990` (`0xd2`), singleton clear helper `0x004e5bd0` (`0x0b`), scalar deleting destructor `0x004e6750` (`0x110`), and no functions at `0x004e5a62`, `0x004e5bdb`, or `0x004e6860`. It also reconfirmed the `GetArchiveBoundsBucket` caller set at `0x004db647`, `0x004dc1b9`, and raw local call `0x004dc279`; the one `VectorGrowArchiveIndex` caller at `0x004dbd8f`; the vtable dwords `0x00648c14`, `0x004e6750`, `0x004f4b10`, `0x0041b6c0`; singleton storage `0x0069b440 == 0`; and default table storage `0x0069b424/0x0069b428/0x0069b42c == 0`.

Rejected alternatives preserved for future audits:

- Do not hand-emit the scalar deleting destructor or vtable bytes; they are generated from class/destructor shape.
- Do not emit a standalone vector-grow helper body for [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md); the source behavior belongs inside the eventual `LoadMonsterArchives` reconstruction.
- Do not move [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md) to generic `VectorHelpers` on current evidence; it has one observed MonsterImageLib caller.
- Do not emit a duplicate `MonsterImageLibLayout` ABI struct; the layout belongs to the actual class declaration once final.
- Do not treat stale `0xffffffff` text as authoritative for [UID:0001PN][0x0069b440-0x0069b444.g_pMonsterImageLib](by-memory/0x0069b440-0x0069b444.g_pMonsterImageLib.md) or [UID:00029K][0x0069b424-0x0069b430.ImageLibraryFallbackRecord](by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md); current MCP bytes and dwords are zero-filled.
- Do not treat [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) as a duplicate direct report for this file. It remains support for shared animation-table helper declarations and bodies.

## Live IDA Evidence

- `lookup_funcs` on 2026-06-03 verifies the source-owned island functions: table loader `0x004dac40` size `0x27d`, constructor `0x004daec0` size `0x14e`, destructor `0x004db010` size `0xe7`, render/bounds helpers through `0x004dc2e0`, singleton clear helper `0x004e5bd0` size `0x0b`, and scalar deleting destructor `0x004e6750` size `0x110`.
- `xrefs_to 0x004daec0` reports the startup caller at `0x004f60c7`; the constructor calls `LoadMonsterTables` at `0x004dafee` and `LoadMonsterArchives` at `0x004daff5`.
- `xrefs_to 0x0061b6e4` reports vtable stores/uses from the constructor, ordinary destructor, and scalar deleting destructor at `0x004daf16`, `0x004db036`, and `0x004e677d`.
- `xrefs_to 0x0069b440` reports singleton writes/clears in the constructor, ordinary destructor, singleton clear helper, scalar deleting destructor, shutdown path, cache clear caller, and render consumers.
- Decompilation confirms the constructor installs the vtable, initializes two embedded cache/list groups, stores the singleton, then loads monster tables and numbered archives. The destructor/scalar destructor both call `ClearLoadedData`, release table/cache storage, chain to the base object, and clear the singleton.
- Wide string bytes at `0x0061c07c`, `0x0061c09c`, and `0x0061c0b0` identify the resource patterns `DATA/MON%d.DAT`, `MON%d.EPF`, and `MONSTER.DNA`; adjacent bytes identify the `MONSTER.DND` fallback string.

## 2026-06-08 Static-Lifetime Helper Audit

- [UID:000181][0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper](by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md) is now assigned directly to this file page. It is a file-local/static-lifetime helper, not a class method.
- IDA decompiles the helper to `dword_69B440 = 0`, and disassembly is exactly `mov dword_69B440, 0; retn` over bytes `c7 05 40 b4 69 00 00 00 00 00 c3`.
- `xrefs_to 0x004e5bd0` reports one cleanup-table reference at `0x005ffd87` from constructor function `sub_4DAEC0`, tying the helper to the `MonsterImageLib` constructor's static cleanup registration.
- `xrefs_to 0x0069b440` reports 22 singleton references, including constructor writes, ordinary/scalar destructor clears, the helper clear, shutdown/cache-clear reads, and monster render/object consumers.
- Neighbor checks keep the helper separate from old-human, NewHuman, Riding, and StaticObj singleton-clear helpers in the adjacent island.

## Closely Coupled Helpers

The helper classes documented in [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) are shared by `MonsterImageLib::LoadMonsterTables` and `RidingImageLib::LoadRidingDefinitions`. They should be reviewed as common sprite animation table containers rather than monster-only inner classes. The accepted source-facing vocabulary for the loader is `ImageAnimationGroup` for the 8-byte child record and `ImageAnimationFrame` for the 10-byte frame entry; the current `MonsterImageLibTable_5289D0` / `MonsterImageLibTable_528BE0` page names remain address-derived evidence aliases until those support pages are renamed.

[UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md) at `0x004dbe60` is emitted through the class route as an empty marker/no-code child pending source-ready cache/DAT API declarations. It lazily loads and caches per-archive [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md) records for `DATA/MON%d.DAT`; it should stay with `MonsterImageLib` during source-file migration and should not be moved to the generic DAT subsystem.

[UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md) has only one IDA-observed caller, `MonsterImageLib::LoadMonsterArchives`, so it currently belongs with this module. [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) is different: it documents folded standard-container compiler output shared across DAT manager, minimap, fitting-room, and monster-image code and therefore has no standalone generated source.

`MonsterImageLib` also consumes shared [UID:0000KR][LinkedList](by-file/LinkedList.md) / `std::list` support helpers for sentinel lists and two-word payload nodes. Keep those generic helper bodies non-emitting; this module should own only monster-specific archive/table payload interpretation and render/cache policy.

## Cross-References

- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:00017C][0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster](by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md)
- [UID:0003M1][0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor](by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md)
- [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md)
- [UID:00029K][0x0069b424-0x0069b430.ImageLibraryFallbackRecord](by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md)
- [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md)
- [UID:0004DM][0x004e6df0-0x004e6e49.VectorStorageReplaceForArchiveIndex](by-memory/0x004e6df0-0x004e6e49.VectorStorageReplaceForArchiveIndex.md)
- [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md)
- [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md)
- [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)
- [UID:0001VC][MonsterImageEntry](by-type/by-struct/MonsterImageEntry.md)
- [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md)
- [UID:0000VK][VectorGrowArchiveIndex_004E5990](by-item/VectorGrowArchiveIndex_004E5990.md)
- [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md)
- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)

## Changes

- 2026-06-30 B011 empty-emitter family implementation callback:
  - Score changed from `86/86` to `89/89`.
  - Evidence: incorporated the accepted B011 report for all 15 empty emitters in `MonsterImageLib.cpp`. Added the per-UID disposition matrix, current MCP zero-fill corrections for `0x0069b424-0x0069b430` and `0x0069b440`, class/vtable/scalar/vector no-code routing, struct/global/helper declaration routing, duplicate by-item alias cleanup, rejected alternatives, and the reason the root stays below 90+ pending broader method/class reconstruction.
- 2026-06-27 B003 GetArchiveBoundsBucket implementation callback:
  - Score unchanged at `86/86`.
  - Evidence: replaced stale disabled/excluded wording for [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md) with the accepted class-routed empty-marker/no-code disposition. Preserved live MCP session `80de0a67` file-level facts: `DATA/MON%d.DAT`, `m_openArchiveIndex`/`m_boundsBucketIndex`, bucket/entry allocation, payload rebasing, raw helper-gap separation, and cache/DAT API no-code proof.
- 2026-06-25 B011 destructor implementation callback:
  - Score unchanged at `86/86`.
  - Evidence: synchronized the file route for [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md), which now emits through [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) and ultimately this source root. Added the formal destructor-body summary, scalar-wrapper distinction, generated-stale note, and rejected direct-file semantic-owner/manual-wrapper/manual-singleton-clear alternatives.
- 2026-06-25 B001 implementation callback:
  - Score unchanged at `86/86`.
  - Evidence: synchronized the file route for [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md), which now emits through [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md) and ultimately this source root. Added `g_defaultMonsterAnimationTable`, resource branch, shared `ImageAnimationGroup` / `ImageAnimationFrame` terminology, and the corrected `frameDuration` / `blendAlpha` shared frame-field wording.
- 2026-06-21 B008 ObjectImageControlPane support sync:
  - Score unchanged.
  - Evidence: recorded the object-image preview status-kind `1` consumer of this module's `ComputeRenderBounds` / `RenderMonsterImage` path.
- 2026-06-08 A001 Batch 121 parent refresh:
  - Before: completion/confidence were `84/84`, and the singleton-clear helper ownership was documented but still below the corrected parent-side gate.
  - Changed to: completion `86`, confidence `86`; [UID:000181][0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper](by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md) is now an eligible direct child parented to this file.
  - Summary/evidence: live IDA MCP reconfirmed the helper's exact bytes/body, decompile output, constructor-associated cleanup-table xref at `0x005ffd87`, 22 `g_pMonsterImageLib` xrefs, and neighboring singleton-helper boundaries. This resolves the parent-side assignment gate for the helper while leaving final field/helper names below final-source quality.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `82`, confidence `78`.
- Summary/evidence: the page documents resource inputs, singleton/vtable/layout references, closely coupled helper ownership, DAT/container dependencies, and cross-references; confidence remains medium-high because exact helper/file split and some disabled helper ownership still need final migration review.
- Reconstruction path update: existed before as blank `PROPOSED_RECONSTRUCTION_PATH`; changed to `NexusTK/render/`. Summary/evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) lists `render/MonsterImageLib.cpp` and the file role is a render/image module rather than generic DAT archive code.
- Exact child range update: added [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) as the exact table-loader evidence for `MONSTER.DNA`/`MONSTER.DND` parsing and `MonsterImageEntry` layout.
- 2026-06-03 live IDA parent-gate update:
  - What existed before: confidence was `78`, the page cited indirect evidence, and the strongest owner evidence was spread across child pages.
  - Changed to: confidence `82`, provenance now points to live IDA evidence and the autogen root, and the score rationale records why this file is a valid parent for MonsterImageLib class/memory children.
  - Summary/evidence: current IDA MCP verifies the function inventory, constructor caller, constructor-loaded table/archive helpers, vtable stores, singleton lifecycle writes/clears, archive/cache behavior, and monster resource strings. File-level C++ root emission is still assembled from child/class pages; [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) now contributes method-level C++ through [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md).
- 2026-06-04 exact helper child update:
  - Added [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md) as the exact `LoadMonsterArchives` slow-path vector grow helper.
  - Evidence: live IDA MCP confirms a single caller at `0x004dbd8f` inside `LoadMonsterArchives`, exact `0x004e5990-0x004e5a62` boundary, immediate post-body alignment, and archive-index vector grow behavior.
- 2026-06-07 A002 Batch 042 fallback-record review:
  - Before: `COMPLETION:82` and `CONFIDENCE:82`.
  - After: `COMPLETION:84` and `CONFIDENCE:84`.
  - Evidence: added exact [UID:00029K][0x0069b424-0x0069b430.ImageLibraryFallbackRecord](by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md) storage to the monster table-loader evidence. The page remains below 85/85 because the concrete static storage could still be declared in the shared helper source rather than `MonsterImageLib.cpp`, and final field/helper names remain unresolved.
- 2026-06-12 C001 ImageLib-family barrier repair:
  - Changed to: the broad MonsterImageLib memory aggregate is now [UID:00017C][0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster](by-memory/0x004dac40-0x004dc420.MonsterImageLibLocalMethodCluster.md), and the scalar deleting destructor now has [UID:0003M1][0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor](by-memory/0x004e6750-0x004e6860.MonsterImageLibScalarDeletingDestructor.md).
  - Evidence: live IDA `entity_query` on 2026-06-12 proved the old `0x004dac40-0x004e685f` aggregate crossed StaticObjImageLib and NewHumanImageLib sibling owners; IDA reports the scalar deleting destructor's correct exclusive end as `0x004e6860`.
