*** UID:0000LK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MonsterImageLib Table Helpers

## Status

- Confidence: strong for shared helper behavior, medium for final original filename.
- Proposed module: `render/MonsterImageLibTables.cpp` or a shared sprite animation table helper inside `render/MonsterImageLib.cpp`.
- Current recovered sources:
  - `source-3/simroot_v2/class_MonsterImageLibTable_5289D0.cpp`
  - `source-3/simroot_v2/class_MonsterImageLibTable_528BE0.cpp`
- Main address range: `0x00528930-0x00528d51`

## File Role

These two small helper classes own heap arrays used by nested monster/riding animation table records. The current class names are address-derived and monster-biased, but IDA MCP shows the allocation helpers are called by both [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md) and [UID:0000N6][RidingImageLib](by-file/RidingImageLib.md):

- `0x005289d0` has callers from `MonsterImageLib::LoadMonsterTables` and `RidingImageLib::LoadRidingDefinitions`.
- `0x00528be0` has the same monster/riding parser caller family.

This argues for a shared sprite animation table helper source file or local helper structs included in both original modules.

IDA MCP on 2026-05-26 also ties the global default riding table at [UID:0001PL][0x0069b430-0x0069b43c.RidingDefinitionGlobalTable](by-memory/0x0069b430-0x0069b43c.RidingDefinitionGlobalTable.md) to the 12-byte `0x005289d0` helper shape. `RidingImageLib::LoadRidingDefinitions` seeds that global table with 21 default riding groups before loading per-riding definitions from `RIDINGS.DNA`.

## Helper Classes

| Class | Address ranges | Role |
| --- | --- | --- |
| `MonsterImageLibTable_5289D0` | `0x00528930-0x00528b43` | 12-byte owner for a heap array of 8-byte nested records plus low-byte child count, including initializer, allocation, cleanup, group lookup, and frame lookup helpers. |
| `MonsterImageLibTable_528BE0` | `0x00528b60-0x00528d51` | 8-byte owner for a heap array of 10-byte image table records plus count word, including allocation, cleanup, frame-record initializer, no-op element destructor callback, and default-frame fallback. |

## Ownership Decision

Do not hard-attach these helpers only to `MonsterImageLib` just because of the current names. They should be kept near the monster/riding animation parser family and reviewed for neutral names before final source migration.

2026-05-26 IDA `py_eval` recheck expands the reviewed range to `0x00528950-0x00528d28`, adding modeled cleanup/unwind helpers at `0x00528950`, `0x00528a70`, `0x00528b60`, and `0x00528c80`. No IDA names contain `MonsterImageLibTable`, so the current class names are placeholders until neutral helper names are selected.

2026-05-28 IDA MCP recheck expands the active range to `0x00528930-0x00528d51`, adding the outer-table zero initializer at `0x00528930`, the inner frame-record initializer at `0x00528d30`, and the no-op element destructor callback at `0x00528d50`.

## Cross-References

- [UID:00008O][MonsterImageLibTable_5289D0](by-class/MonsterImageLibTable_5289D0.md)
- [UID:00008P][MonsterImageLibTable_528BE0](by-class/MonsterImageLibTable_528BE0.md)
- [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md)
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
