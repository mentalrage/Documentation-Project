*** UID:0000LJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MonsterImageLib

## Status

- Confidence: strong for class role, resource ownership, singleton/vtable lifetime, and source parent placement; medium for final helper/file split.
- Proposed module: `render/MonsterImageLib.cpp`
- Autogen root: `auto-generated/NexusTK/render/MonsterImageLib.cpp`
- Main address ranges: `0x004dac40-0x004dc414` and `0x004e6750-0x004e685f`
- Primary global instance: [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md) at `0x0069b440`
- Primary vtable: [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md) at `0x0061b6e4`
- Object layout: [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 86 | Resource inputs, singleton/vtable/layout references, constructor/destructor/cache lifetime, render/bounds responsibilities, exact default-table storage, helper ownership, static-lifetime singleton helper provenance, and source placement are documented. |
| Confidence | 86 | Live IDA MCP on 2026-06-03 verifies the constructor caller, function inventory, vtable stores, singleton writes/clears/consumers, and archive/cache behavior; the Batch 042 fallback-record review adds the exact static default-table storage; Batch 121 reconfirms the file-local singleton-clear helper, cleanup-table reference, and 22 singleton xrefs. Final field names and some helper split details still keep this below final-source confidence. |

## File Role

`MonsterImageLib` is the monster sprite image library. It owns monster animation table parsing, monster DAT archive indexing, cached archive-bounds loading, render dispatch, palette/direct draw selection, projection/bounds calculations, singleton lifetime, and teardown.

This should remain a distinct render/image module. It is a DAT consumer, but it opens monster-specific `DATA/MON%d.DAT` archives and parses monster-specific `MONSTER.DNA`/`MONSTER.DND` data rather than owning the generic DAT archive format.

## Resource Inputs

| Resource | Role |
| --- | --- |
| `MONSTER.DNA` | Compact/new monster animation table when `g_usesCompactMonsterTable` is nonzero. |
| `MONSTER.DND` | Alternate/legacy monster animation table. |
| `DATA/MON%d.DAT` | Numbered monster image archives scanned by `LoadMonsterArchives` and lazy bounds loading. |

Monster ids are commonly rebased by `+32768` before table lookup, matching the `kMonsterEntryBase` constant in render methods.

[UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) is the exact table-loader range currently proving the 0x0c [UID:0001VC][MonsterImageEntry](by-type/by-struct/MonsterImageEntry.md) row layout and nested animation-table allocation flow.

The loader also owns the concrete monster default/fallback outer table storage at [UID:00029K][0x0069b424-0x0069b430.ImageLibraryFallbackRecord](by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md). That static 12-byte object is initialized by the shared table helper constructor, allocated with `0x15` default groups by `LoadMonsterTables`, seeded with one `0..30000` frame entry per group, and returned by the monster table lookup when an index is out of range. The helper type remains documented by [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md), so this page records concrete monster-image state rather than claiming exclusive helper implementation ownership.

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

The helper classes documented in [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) are shared by `MonsterImageLib::LoadMonsterTables` and `RidingImageLib::LoadRidingDefinitions`. They should be reviewed as common sprite animation table containers rather than monster-only inner classes.

[UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md) at `0x004dbe60` is disabled/excluded from active emission but remains owner-relevant. It lazily loads and caches per-archive [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md) records for `DATA/MON%d.DAT`; it should stay with `MonsterImageLib` during source-file migration.

[UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md) has only one IDA-observed caller, `MonsterImageLib::LoadMonsterArchives`, so it currently belongs with this module. The adjacent [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) helper is different: `MonsterImageLib` consumes it, but its callers span DAT manager, minimap, fitting-room, and monster-image code, so it should remain standalone.

`MonsterImageLib` also consumes shared [UID:0000KR][LinkedList](by-file/LinkedList.md) helpers for sentinel lists and two-word payload nodes. Keep those generic helpers under `util/LinkedList.cpp`; this module should own only monster-specific archive/table payload interpretation and render/cache policy.

## Cross-References

- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:00017C][0x004dac40-0x004e685f.MonsterImageLib](by-memory/0x004dac40-0x004e685f.MonsterImageLib.md)
- [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md)
- [UID:00029K][0x0069b424-0x0069b430.ImageLibraryFallbackRecord](by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md)
- [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md)
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
  - Summary/evidence: current IDA MCP verifies the function inventory, constructor caller, constructor-loaded table/archive helpers, vtable stores, singleton lifecycle writes/clears, archive/cache behavior, and monster resource strings. Final C++ remains absent because exact field names and helper split are still below the `95/95` gate.
- 2026-06-04 exact helper child update:
  - Added [UID:0002VF][0x004e5990-0x004e5a62.VectorGrowArchiveIndex](by-memory/0x004e5990-0x004e5a62.VectorGrowArchiveIndex.md) as the exact `LoadMonsterArchives` slow-path vector grow helper.
  - Evidence: live IDA MCP confirms a single caller at `0x004dbd8f` inside `LoadMonsterArchives`, exact `0x004e5990-0x004e5a62` boundary, immediate post-body alignment, and archive-index vector grow behavior.
- 2026-06-07 A002 Batch 042 fallback-record review:
  - Before: `COMPLETION:82` and `CONFIDENCE:82`.
  - After: `COMPLETION:84` and `CONFIDENCE:84`.
  - Evidence: added exact [UID:00029K][0x0069b424-0x0069b430.ImageLibraryFallbackRecord](by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md) storage to the monster table-loader evidence. The page remains below 85/85 because the concrete static storage could still be declared in the shared helper source rather than `MonsterImageLib.cpp`, and final field/helper names remain unresolved.
