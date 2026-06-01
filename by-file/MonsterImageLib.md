*** UID:0000LJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MonsterImageLib

## Status

- Confidence: strong for class role and resource ownership, medium for exact helper/file split.
- Proposed module: `render/MonsterImageLib.cpp`
- Current recovered source: `source-3/simroot_v2/class_MonsterImageLib.cpp`
- Main address ranges: `0x004dac40-0x004dc414` and `0x004e6750-0x004e685f`
- Primary global instance: [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md) at `0x0069b440`
- Primary vtable: [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md) at `0x0061b6e4`
- Object layout: [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)

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
