*** UID:00008O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MonsterImageLibTable_5289D0

## Status

- Confidence: strong for behavior, source placement, and shared caller evidence; medium for final neutral class/struct name.
- Likely source file: [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md), projected to `NexusTK/render/MonsterImageLibTables.cpp`
- Address ranges: [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md)

## Class Purpose

`MonsterImageLibTable_5289D0` is a small owner for nested animation/image table records. The current project documentation describes it as a 12-byte helper that owns a heap array of 8-byte nested group records plus a low-byte child count.

The current name is address-derived. Because both monster and riding parsers use it, a future rename should probably be neutral, such as an animation bucket/table helper, after field layout is reviewed.

## Autogen Status

- Parent file: [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- Reconstructable: `TRUE`
- C++ emission: intentionally blank until neutral helper names and declarations are settled.

The parent file, memory helper island, and this class page now agree that this is shared monster/riding table infrastructure rather than a monster-only class. The address-derived name remains a documentation placeholder.

## Layout And Method Map

Current evidence supports a 12-byte outer helper object with a child-count byte and a heap pointer to nested 8-byte records. The [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) page records the exact helper island; [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) now owns the projected render helper source.

| Range | Role | Evidence state |
| --- | --- | --- |
| `0x00528930-0x00528947` | zero initializer | IDA xrefs tie it to direct setup calls and constructor-callback use by parser/allocation helpers. |
| `0x00528950-0x005289c6` | cleanup/destructor helper | Destroys nested inner table records and clears the outer table state. |
| `0x005289d0-0x00528a6d` | allocation/resizing helper | Allocates or resizes the heap array of 8-byte nested records. |
| `0x00528a70-0x00528ae6` | cleanup/unwind helper | Same cleanup shape as `0x00528950`; currently treated as duplicate cleanup/EH support. |
| `0x00528af0-0x00528b07` | small outer helper | Semantic name remains open. |
| `0x00528b10-0x00528b43` | frame lookup helper | Selects a child table and returns a 10-byte frame record or the shared default frame record documented by [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md). |
| `0x00528b50-0x00528b5f` | nested group-record initializer | Initializes an 8-byte nested group record with a null frame-record pointer and zero count; passed as the constructor callback by `0x005289d0`. |

## Evidence Notes

- The memory helper island records thirteen helper bodies in `0x00528930-0x00528d51`; this outer helper owns the initializer, cleanup/allocation, group lookup, frame lookup, and nested group-record initializer portions.
- IDA MCP on 2026-05-22 reports four caller sites: two in `MonsterImageLib::LoadMonsterTables` and two in `RidingImageLib::LoadRidingDefinitions`.
- 2026-05-26 IDA `py_eval` recheck confirms modeled starts for this outer helper family at `0x00528950`, `0x005289d0`, `0x00528a70`, `0x00528af0`, and `0x00528b10`, plus inner cleanup helper `0x00528b60`. No IDA names contain `MonsterImageLibTable`, so the address-derived class name should remain provisional.
- 2026-05-28 IDA MCP recheck adds the outer-table zero initializer at `0x00528930`; xrefs show direct setup callers and constructor-callback use by parser/allocation helpers.
- 2026-06-06 memory-island refresh adds `0x00528b50-0x00528b5f` as the nested group-record initializer and records that it is referenced as the vector constructor callback from `0x005289d0`.

## Score Rationale

Completion is now `82` because the page covers the parent file assignment, 12-byte outer layout, full outer helper map, shared monster/riding parser callers, fallback frame-record path, and the newly documented nested group-record initializer. Remaining work is a neutral source-level type name, field names, and source-quality declarations.

Confidence is now `84` because the class page, file page, and memory helper island agree on ownership and helper boundaries, including the `0x00528b50` constructor callback. Confidence remains below final because IDA names are still address-derived/placeholders and the public/private source model is unresolved.

## Cross-References

- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md)

## Changes

- Before: documented outer helper starts began at `0x00528950`.
- Changed to: include the `0x00528930` zero initializer in the outer helper family.
- Summary/evidence: 2026-05-28 IDA MCP xrefs tie `0x00528930` to direct setup calls and constructor-callback use from the same parser/allocation family.
- Completion/confidence score update: existed before as `0/0`; changed to `74/76`. Summary: the outer nested animation/image table helper has shared monster/riding caller evidence, method-start evidence, and initializer coverage, but its class name and final neutral struct/class model remain provisional. Evidence: linked `MonsterImageLibTables` range, IDA caller sites from `MonsterImageLib` and `RidingImageLib`, modeled start rechecks, no stable IDA names, and the 2026-05-28 zero-initializer xref update.
- 2026-06-03 source-owner consistency pass:
  - Changed to: `COMPLETION:78`, `CONFIDENCE:80`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000LK`.
  - Summary/evidence: [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) now has a projected `NexusTK/render/MonsterImageLibTables.cpp` path, [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) documents the exact helper island and shared monster/riding caller family, and [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md) resolves the fallback frame-record ownership. Scores remain capped because the final neutral type name and complete field names still need a dedicated layout pass; no C++ was added under the 95+ gate.
- 2026-06-07 class-page reconciliation:
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, added autogen-status and score-rationale sections, and added the `0x00528b50-0x00528b5f` nested group-record initializer.
  - Summary/evidence: [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) records thirteen helper bodies before `0x00528d60`; `0x00528b50` initializes 8-byte nested group records and is passed by `0x005289d0`; parent/file ownership remains [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md).
