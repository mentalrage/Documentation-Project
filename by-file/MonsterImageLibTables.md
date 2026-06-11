*** UID:0000LK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MonsterImageLib Table Helpers

## Status

- Confidence: strong for shared helper behavior, medium for final original filename.
- Proposed module: `render/MonsterImageLibTables.cpp` or a shared sprite animation table helper inside `render/MonsterImageLib.cpp`.
- Current recovered sources:
  - `source-3/simroot_v2/class_MonsterImageLibTable_5289D0.cpp`
  - `source-3/simroot_v2/class_MonsterImageLibTable_528BE0.cpp`
- Main address range: `0x00528930-0x00528d51`

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The page now records the full helper island, both placeholder helper classes, shared monster/riding parser callers, riding global-table use, monster default-table storage, fallback frame-record ownership, callback wiring, and source-placement caveats. |
| Confidence | 85 | Parent, class, memory, global, and data pages agree that this is shared monster/riding table infrastructure. Confidence remains below final because neutral source names, field names, and whether this was a standalone `.cpp` or private helper section are still unresolved. |

## File Role

These two small helper classes own heap arrays used by nested monster/riding animation table records. The current class names are address-derived and monster-biased, but IDA MCP shows the allocation helpers are called by both [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) and [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md):

- `0x005289d0` has callers from `MonsterImageLib::LoadMonsterTables` and `RidingImageLib::LoadRidingDefinitions`.
- `0x00528be0` has the same monster/riding parser caller family.

This argues for a shared sprite animation table helper source file or local helper structs included in both original modules.

IDA MCP on 2026-05-26 also ties the global default riding table at [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md) to the 12-byte `0x005289d0` helper shape. `RidingImageLib::LoadRidingDefinitions` seeds that global table with 21 default riding groups before loading per-riding definitions from `RIDINGS.DNA`.

The adjacent monster default table storage at [UID:00029K][0x0069b424-0x0069b430.ImageLibraryFallbackRecord](by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md) uses the same 12-byte outer helper shape. It is initialized by the shared helper constructor, cleaned up by the shared helper destructor, allocated with 21 default groups by `MonsterImageLib::LoadMonsterTables`, and returned by the monster table lookup when an index is out of range. That storage is concrete monster image state, while this page owns the shared helper behavior and type-shape evidence.

The shared fallback frame record at [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md) belongs with this helper file as well. Both lookup helpers return that record when a requested group or frame is out of range, and the record bytes match the normal 10-byte frame-record initializer.

## Helper Classes

| Class | Address ranges | Role |
| --- | --- | --- |
| `MonsterImageLibTable_5289D0` | `0x00528930-0x00528b43` | 12-byte owner for a heap array of 8-byte nested records plus low-byte child count, including initializer, allocation, cleanup, group lookup, and frame lookup helpers. |
| `MonsterImageLibTable_528BE0` | `0x00528b60-0x00528d51` | 8-byte owner for a heap array of 10-byte image table records plus count word, including allocation, cleanup, frame-record initializer, no-op element destructor callback, and default-frame fallback. |

## Helper Island Details

[UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) currently records thirteen helper bodies before the next function at `0x00528d60`. The outer helper includes the zero initializer at `0x00528930`, cleanup/allocation helpers, group and frame lookup helpers, and the `0x00528b50` nested group-record initializer. The inner helper includes the `0x00528b60` cleanup helper, `0x00528be0` allocator, `0x00528c80` cleanup/unwind duplicate, `0x00528d00` lookup helper, `0x00528d30` frame-record initializer, and the `0x00528d50` no-op element destructor callback.

The `0x00528b50` initializer is part of the outer helper family, not a standalone class. It zeroes each 8-byte nested group record and is passed as the constructor callback from `0x005289d0`. The `0x00528d30` initializer and `0x00528d50` no-op callback serve the inner 10-byte frame-record vector. Padding between these helpers is `0xcc` alignment and should not be promoted into source methods.

## Ownership Decision

Do not hard-attach these helpers only to `MonsterImageLib` just because of the current names. They should be kept near the monster/riding animation parser family and reviewed for neutral names before final source migration.

2026-05-26 IDA `py_eval` recheck expands the reviewed range to `0x00528950-0x00528d28`, adding modeled cleanup/unwind helpers at `0x00528950`, `0x00528a70`, `0x00528b60`, and `0x00528c80`. No IDA names contain `MonsterImageLibTable`, so the current class names are placeholders until neutral helper names are selected.

2026-05-28 IDA MCP recheck expands the active range to `0x00528930-0x00528d51`, adding the outer-table zero initializer at `0x00528930`, the inner frame-record initializer at `0x00528d30`, and the no-op element destructor callback at `0x00528d50`.

## Cross-References

- [UID:00008O][MonsterImageLibTable_5289D0](by-class/MonsterImageLibTable_5289D0.md)
- [UID:00008P][MonsterImageLibTable_528BE0](by-class/MonsterImageLibTable_528BE0.md)
- [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md)
- [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md)
- [UID:0000TJ][RidingDefinitionGlobalTable](by-global/RidingDefinitionGlobalTable.md)

## Changes

- Before: the file-level helper range was `0x00528950-0x00528d28`.
- Changed to: range is `0x00528930-0x00528d51`, including initializer/callback helpers that were previously hidden in UNKNOWN gaps.
- Summary/evidence: 2026-05-28 IDA MCP xrefs tie `0x00528930`, `0x00528d30`, and `0x00528d50` to the same monster/riding table allocation and cleanup helper family.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `82`, confidence `80`.
- Summary/evidence: the page documents both helper classes, shared monster/riding caller evidence, global table tie-in, active range corrections, and cross-references; confidence remains below high because neutral final helper names and original filename are still provisional.

- 2026-06-03 path consistency pass:
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.
  - Summary/evidence: this page already proposes `render/MonsterImageLibTables.cpp`, [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) ties the helper bodies to monster/riding render table parsing, and `by-project-structure/proposed-source-tree.md` already lists `MonsterImageLibTables.cpp` under `NexusTK/render/`. The final helper type names remain provisional, so no reconstructed C++ was added.

- 2026-06-07 A001 helper-island reconciliation:
  - Changed to: completion `84`, confidence `84`; added score rationale, the shared fallback frame-record owner, the `0x00528b50` nested group initializer, and the thirteen-helper island breakdown.
  - Summary/evidence: [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md), [UID:00008O][MonsterImageLibTable_5289D0](by-class/MonsterImageLibTable_5289D0.md), [UID:00008P][MonsterImageLibTable_528BE0](by-class/MonsterImageLibTable_528BE0.md), [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md), and [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md) now agree on shared monster/riding helper ownership, callback wiring, fallback-record behavior, and the remaining neutral-name/source-split caveat.
- 2026-06-07 A002 Batch 042 fallback-table refresh:
  - Before: `COMPLETION:84` and `CONFIDENCE:84`.
  - After: `COMPLETION:85` and `CONFIDENCE:85`.
  - Summary/evidence: added the exact monster default-table storage [UID:00029K][0x0069b424-0x0069b430.ImageLibraryFallbackRecord](by-memory/0x0069b424-0x0069b430.ImageLibraryFallbackRecord.md) to the helper-family evidence, tying it to shared constructor/destructor helpers, `MonsterImageLib::LoadMonsterTables` allocation/seeding, and out-of-range fallback behavior. Scores remain capped because neutral helper names and standalone-vs-private source placement are still unresolved.
