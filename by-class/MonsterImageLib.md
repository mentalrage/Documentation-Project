*** UID:00008N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MonsterImageLib

## Status

- Confidence: strong for method roles, medium for final field/type names.
- Likely source file: [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- Address ranges: [UID:00017C][0x004dac40-0x004e685f.MonsterImageLib](by-memory/0x004dac40-0x004e685f.MonsterImageLib.md)
- Current recovered file: `source-3/simroot_v2/class_MonsterImageLib.cpp`
- Singleton: [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md) at `0x0069b440`
- Vtable: [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md) at `0x0061b6e4`
- Layout: [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)

## Class Purpose

`MonsterImageLib` is the singleton-backed monster image/rendering library behind [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md). It loads monster animation tables, builds an index over numbered monster DAT archives, renders monster frames with palette/direct renderer callbacks, computes projected bounds, and frees cached archive data.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `LoadMonsterTables` | `0x004dac40` | [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) parses `MONSTER.DNA` or `MONSTER.DND`, allocates monster table entries, initializes 21 monster group buckets, and fills nested palette/frame records. |
| `MonsterImageLib::MonsterImageLib` | `0x004daec0` | Initializes singleton, table/vector/list state, then calls `LoadMonsterTables` and `LoadMonsterArchives`. |
| `~MonsterImageLib` | `0x004db010` | [UID:00017D][0x004db010-0x004db0f7.MonsterImageLibDestructor](by-memory/0x004db010-0x004db0f7.MonsterImageLibDestructor.md) that clears cached data, destroys table entries and state tables, frees archive index, and clears the singleton. |
| `RenderMonster` | `0x004db100` | High-level projected monster draw path. |
| `GetEntryByIndex` | `0x004db330` | Bounds-checked lookup with fallback missing entry. |
| `RenderMonsterImage` | `0x004db3b0` | Palette/direct monster image draw path with optional overlay pass. |
| `ComputeRenderBounds` | `0x004db5c0` | Computes monster bounds/projection using archive bounds buckets. |
| `LoadMonsterArchives` | `0x004dbc60` | Scans `DATA/MON%d.DAT`, opens each DAT container, and builds archive index records. |
| `ClearLoadedData` | `0x004dc2e0` | Frees cached loaded archive/bounds data and state nodes. |
| `ScalarDeletingDestructor` | `0x004e6750` | Destructor thunk with optional delete; first [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md) slot. |

Singleton/static-lifetime support:

| Function | Address | Role |
| --- | --- | --- |
| `MonsterImageLibSingletonClearHelper` | `0x004e5bd0` | [UID:000181][0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper](by-memory/0x004e5bd0-0x004e5bdb.MonsterImageLibSingletonClearHelper.md) that clears `g_pMonsterImageLib` / `dword_69B440`. |

Disabled/excluded but still owner-relevant:

| Method | Address | Role |
| --- | --- | --- |
| `GetArchiveBoundsBucket` | `0x004dbe60` | [UID:00017E][0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket](by-memory/0x004dbe60-0x004dc174.MonsterImageLibGetArchiveBoundsBucket.md) per-archive [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md). |

## DATIndexVector Relationship

IDA MCP caller checks on 2026-05-24 show `MonsterImageLib` uses [UID:00003K][DATIndexVector](by-class/DATIndexVector.md) for archive-bounds cache lookup/insert paths: `GetArchiveBoundsBucket` calls `FindNodeByKey` and `InsertNode`, while construction/cleanup paths call `ResizeAndFill` and the `DATIndexVector` destructor. `VectorGrowArchiveIndex_004E5990` remains separate and is only observed from `LoadMonsterArchives`.

IDA MCP checks on 2026-05-25 also show `MonsterImageLib` using shared [UID:0000KR][LinkedList](by-file/LinkedList.md) helpers for sentinel-node setup, two-word payload-node allocation, and list-state cleanup. Those helpers are generic utility code and should not be migrated into `MonsterImageLib.cpp`.

IDA MCP checks on 2026-05-31 reverified the constructor (`0x004daec0`), ordinary destructor (`0x004db010`), lazy bounds loader (`0x004dbe60`), and clear-loaded-data helper (`0x004dc2e0`). These checks confirm the singleton, vtable, archive-offset vector, two embedded DATIndexVector-style indexes at `+0x1c` and `+0x3c`, and ownership of the archive-bounds cache structures. The class is reconstructable, but autogen parent/code metadata remains blank because complete final-source C++ for the whole class is not yet at the `95+` gate.

## Shared Table Helper Relationship

`LoadMonsterTables` and [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md) both call the two helper classes documented in [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md). Their current names are monster-biased because they were restored from monster/riding caller evidence, but their source placement may be a common animation-table helper rather than strictly inside `MonsterImageLib`.

## Cross-References

- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:0000RR][g_pMonsterImageLib](by-global/g_pMonsterImageLib.md)
- [UID:0001Y7][MonsterImageLibVtable](by-type/by-vtable/MonsterImageLibVtable.md)
- [UID:0001VD][MonsterImageLibLayout](by-type/by-struct/MonsterImageLibLayout.md)
- [UID:0001VC][MonsterImageEntry](by-type/by-struct/MonsterImageEntry.md)
- [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md)
- [UID:0001VA][MonsterArchiveBoundsBucket](by-type/by-struct/MonsterArchiveBoundsBucket.md)
- [UID:00003K][DATIndexVector](by-class/DATIndexVector.md)
- [UID:0000KR][LinkedList](by-file/LinkedList.md)
- [UID:0000VK][VectorGrowArchiveIndex_004E5990](by-item/VectorGrowArchiveIndex_004E5990.md)
- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `84/78`. Summary: the singleton monster image library has detailed method, singleton, vtable, layout, DAT archive, cache, render, bounds, table-helper, DATIndexVector, and LinkedList dependency documentation, but final field/type names remain medium confidence. Evidence: linked `MonsterImageLib` range, destructor/get-bounds/singleton-clear pages, `g_pMonsterImageLib`, vtable/layout/type docs, IDA caller checks, and shared monster/riding table-helper notes.
- Reconstructability/confidence update: existed before as `RECONSTRUCTABLE` blank and confidence `78`; changed to `RECONSTRUCTABLE:TRUE` and confidence `82`. Summary: 2026-05-31 IDA MCP rechecked constructor/destructor/cache-loader/cleanup evidence and confirms this class is NexusTK-owned source that must be rebuilt. Autogen parent and C++ remain blank because final whole-class source is not at the `95+` evidence gate.
- Method inventory update: `LoadMonsterTables` existed before as an unlinked method row; changed to link the exact [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) child page. Evidence: 2026-05-31 IDA MCP verified `0x004dac40` size `0x27d` and the monster table parse/allocation flow.
