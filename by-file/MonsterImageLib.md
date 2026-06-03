*** UID:0000LJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
| Completion | 82 | Resource inputs, singleton/vtable/layout references, constructor/destructor/cache lifetime, render/bounds responsibilities, helper ownership, and source placement are documented. |
| Confidence | 82 | Live IDA MCP on 2026-06-03 verifies the constructor caller, function inventory, vtable stores, singleton writes/clears/consumers, and archive/cache behavior. Final field names and helper/file split still keep this below final-source confidence. |

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

## Live IDA Evidence

- `lookup_funcs` on 2026-06-03 verifies the source-owned island functions: table loader `0x004dac40` size `0x27d`, constructor `0x004daec0` size `0x14e`, destructor `0x004db010` size `0xe7`, render/bounds helpers through `0x004dc2e0`, singleton clear helper `0x004e5bd0` size `0x0b`, and scalar deleting destructor `0x004e6750` size `0x110`.
- `xrefs_to 0x004daec0` reports the startup caller at `0x004f60c7`; the constructor calls `LoadMonsterTables` at `0x004dafee` and `LoadMonsterArchives` at `0x004daff5`.
- `xrefs_to 0x0061b6e4` reports vtable stores/uses from the constructor, ordinary destructor, and scalar deleting destructor at `0x004daf16`, `0x004db036`, and `0x004e677d`.
- `xrefs_to 0x0069b440` reports singleton writes/clears in the constructor, ordinary destructor, singleton clear helper, scalar deleting destructor, shutdown path, cache clear caller, and render consumers.
- Decompilation confirms the constructor installs the vtable, initializes two embedded cache/list groups, stores the singleton, then loads monster tables and numbered archives. The destructor/scalar destructor both call `ClearLoadedData`, release table/cache storage, chain to the base object, and clear the singleton.
- Wide string bytes at `0x0061c07c`, `0x0061c09c`, and `0x0061c0b0` identify the resource patterns `DATA/MON%d.DAT`, `MON%d.EPF`, and `MONSTER.DNA`; adjacent bytes identify the `MONSTER.DND` fallback string.

## Closely Coupled Helpers

The helper classes documented in [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) are shared by `MonsterImageLib::LoadMonsterTables` and `RidingImageLib::LoadRidingDefinitions`. They should be reviewed as common sprite animation table containers rather than monster-only inner classes.

[UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md) at `0x004dbe60` is disabled/excluded from active emission but remains owner-relevant. It lazily loads and caches per-archive [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md) records for `DATA/MON%d.DAT`; it should stay with `MonsterImageLib` during source-file migration.

`VectorGrowArchiveIndex_004E5990` has only one IDA-observed caller, `MonsterImageLib::LoadMonsterArchives`, so it currently belongs with this module. The adjacent [UID:0000IP][DATIndexVector](by-file/DATIndexVector.md) helper is different: `MonsterImageLib` consumes it, but its callers span DAT manager, minimap, fitting-room, and monster-image code, so it should remain standalone.

`MonsterImageLib` also consumes shared [UID:0000KR][LinkedList](by-file/LinkedList.md) helpers for sentinel lists and two-word payload nodes. Keep those generic helpers under `util/LinkedList.cpp`; this module should own only monster-specific archive/table payload interpretation and render/cache policy.

## Cross-References

- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:00017C][0x004dac40-0x004e685f.MonsterImageLib](by-memory/0x004dac40-0x004e685f.MonsterImageLib.md)
- [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md)
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

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `82`, confidence `78`.
- Summary/evidence: the page documents resource inputs, singleton/vtable/layout references, closely coupled helper ownership, DAT/container dependencies, and cross-references; confidence remains medium-high because exact helper/file split and some disabled helper ownership still need final migration review.
- Reconstruction path update: existed before as blank `PROPOSED_RECONSTRUCTION_PATH`; changed to `NexusTK/render/`. Summary/evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) lists `render/MonsterImageLib.cpp` and the file role is a render/image module rather than generic DAT archive code.
- Exact child range update: added [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) as the exact table-loader evidence for `MONSTER.DNA`/`MONSTER.DND` parsing and `MonsterImageEntry` layout.
- 2026-06-03 live IDA parent-gate update:
  - What existed before: confidence was `78`, the page cited indirect evidence, and the strongest owner evidence was spread across child pages.
  - Changed to: confidence `82`, provenance now points to live IDA evidence and the autogen root, and the score rationale records why this file is a valid parent for MonsterImageLib class/memory children.
  - Summary/evidence: current IDA MCP verifies the function inventory, constructor caller, constructor-loaded table/archive helpers, vtable stores, singleton lifecycle writes/clears, archive/cache behavior, and monster resource strings. Final C++ remains absent because exact field names and helper split are still below the `95/95` gate.
