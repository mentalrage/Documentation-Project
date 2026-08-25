*** UID:00008O | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MonsterImageLibTable_5289D0

## Status

- Confidence: very strong that this is a non-emitting address-derived evidence alias for UID0001CM's 12-byte `ImageAnimationTable`; the exact original lexical type name remains inferred.
- Likely source file: [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md), projected to `NexusTK/render/MonsterImageLibTables.cpp`
- Address ranges: [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md)
- 2026-06-29 B007 implementation: this remains an address-derived support alias. Source declarations and method bodies are now emitted by UID0001CM as `ImageAnimationTable`; this page should not duplicate helper C++.

## Class Purpose

`MonsterImageLibTable_5289D0` is the address-derived documentation page for the 12-byte outer animation table helper shape. The current source-facing interpretation is a table/default row object that owns a heap array of 8-byte `ImageAnimationGroup` records plus a low-byte group count.

The current page name is address-derived. Because both monster and riding parsers use it, final source should use neutral helper terminology. The 2026-06-25 B001 accepted target C++ uses `AllocateGroups` and `ImageAnimationGroup` instead of this address-derived name.

## Autogen Status

- Parent file: [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- Reconstructable: `FALSE` as a distinct source entity; the represented source is fully reconstructable once through UID0001CM.
- C++/H emission: intentionally blank. [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) is the sole declaration/method carrier; this page preserves evidence and searchability for the address-derived name without duplicating source.

The parent file, memory helper island, and this class page now agree that this is shared monster/riding table infrastructure rather than a monster-only class. The address-derived name remains a documentation placeholder.

## Layout And Method Map

Current evidence supports a 12-byte outer helper object with a group-count byte and a heap pointer to nested 8-byte `ImageAnimationGroup` records. The [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) page records the exact helper island; [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) owns the projected render helper source.

| Range | Role | Evidence state |
| --- | --- | --- |
| `0x00528930-0x00528947` | zero initializer | IDA xrefs tie it to direct setup calls and constructor-callback use by parser/allocation helpers. |
| `0x00528950-0x005289c6` | cleanup/destructor helper | Destroys nested inner table records and clears the outer table state. |
| `0x005289d0-0x00528a6e` | `ImageAnimationTable::AllocateGroups` helper | Allocates or resizes the heap array of 8-byte `ImageAnimationGroup` records. |
| `0x00528a70-0x00528ae6` | cleanup/unwind helper | Same cleanup shape as `0x00528950`; currently treated as duplicate cleanup/EH support. |
| `0x00528af0-0x00528b08` | `ImageAnimationTable::GetGroup` helper | Returns the in-range `ImageAnimationGroup` pointer or the base group pointer when out of range. |
| `0x00528b10-0x00528b44` | `ImageAnimationTable::GetFrame` helper | Selects a child table and returns a 10-byte frame record or the shared default frame record documented by [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md). |
| `0x00528b50-0x00528b5f` | `ImageAnimationGroup` initializer | Initializes an 8-byte group record with a null frame pointer and zero `frameCount`; passed as the constructor callback by `0x005289d0`. |

## Accepted Neutral Name Overlay

The accepted source-facing overlay for this page is:

- 12-byte outer table/default row shape: owns an `ImageAnimationGroup* groups` pointer at `+0x08` and a group count byte at `+0x04`.
- `ImageAnimationTable`: inferred source-facing declaration/body emitted by UID0001CM for this 12-byte outer table/default row shape.
- `AllocateGroups`, `GetGroup`, and `GetFrame`: source-facing behavior represented by `0x005289d0`, `0x00528af0`, and `0x00528b10`.
- `ImageAnimationGroup`: the 8-byte child record initialized by `0x00528b50`; fields are `frames`, `frameCount`, and `reserved`.

These names are inferred from loader/default-table behavior and shared monster/riding xrefs. They are strong enough for [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md) method C++ but are not claimed as recovered original symbols.

## Evidence Notes

- The memory helper island records thirteen helper bodies in `0x00528930-0x00528d51`; this outer helper owns the initializer, cleanup/allocation, group lookup, frame lookup, and nested group-record initializer portions.
- IDA MCP on 2026-05-22 reports four caller sites: two in `MonsterImageLib::LoadMonsterTables` and two in `RidingImageLib::LoadRidingDefinitions`.
- 2026-05-26 IDA `py_eval` recheck confirms modeled starts for this outer helper family at `0x00528950`, `0x005289d0`, `0x00528a70`, `0x00528af0`, and `0x00528b10`, plus inner cleanup helper `0x00528b60`. No IDA names contain `MonsterImageLibTable`, so the address-derived class name should remain provisional.
- 2026-05-28 IDA MCP recheck adds the outer-table zero initializer at `0x00528930`; xrefs show direct setup callers and constructor-callback use by parser/allocation helpers.
- 2026-06-06 memory-island refresh adds `0x00528b50-0x00528b5f` as the nested group-record initializer and records that it is referenced as the vector constructor callback from `0x005289d0`.
- 2026-06-14 C001 IDA MCP recheck confirms the current outer-helper inventory: initializer `0x00528930` size `0x17`, cleanup `0x00528950` size `0x76`, allocation `0x005289d0` size `0x9e`, unwind cleanup `0x00528a70` size `0x76`, group lookup `0x00528af0` size `0x18`, frame lookup `0x00528b10` size `0x34`, and nested group-record initializer `0x00528b50` size `0x0f`.
- The same live pass reconfirms four parser/allocation xrefs to `0x005289d0`, constructor-callback xref `0x005289d0 -> 0x00528b50`, destructor callback xrefs to `0x00528b60`, fallback record refs from `0x00528b10` to `0x0066deb0`, and `0xcc` internal alignment around `0x00528b44-0x00528b50` and `0x00528b5f-0x00528b60`.
- 2026-06-29 B007 implementation on current MCP session `b2ae72ec` normalizes half-open outer-helper endpoints to `0x005289d0-0x00528a6e`, `0x00528af0-0x00528b08`, and `0x00528b10-0x00528b44`. The same report confirms no recovered IDA name contains `MonsterImageLibTable`; `ImageAnimationTable` is the source-facing helper name emitted by UID0001CM.

## 2026-08-17 B008 Non-Emitting Alias Closure

This page does not describe a second C++ class. Its address-derived title groups the 12-byte outer-table evidence from the shared helper island: construction at `0x00528930`, authored destruction at `0x00528950`, group allocation at `0x005289d0`, group lookup at `0x00528af0`, frame lookup at `0x00528b10`, and the nested group constructor at `0x00528b50`. The zero-xref duplicate cleanup at `0x00528a70` is an EH clone rather than another source method.

The complete source-facing `ImageAnimationTable` declaration and method definitions are emitted exactly once by UID0001CM under `MonsterImageLibTables.h/.cpp`. This alias therefore has `RECONSTRUCTABLE:FALSE`, blank emitter routing and positions, and blank formal CPP/H. It retains owner UID0000LK because the evidence belongs to that compilation unit. No source declaration uses `MonsterImageLibTable_5289D0`.

The accepted layout is 12 bytes: `baseValue` at `+0x00`, low-byte `groupCount` at `+0x04`, inferred `flags` and `tableId` at `+0x05/+0x06`, and `ImageAnimationGroup *groups` at `+0x08`. Four parser callers shared between MonsterImageLib and RidingImageLib prove neutral ownership. In-range lookups use 8-byte group indexing; out-of-range group lookup preserves the observed base-pointer behavior, and out-of-range frame lookup returns `g_defaultImageAnimationFrame`.

Historical `TRUE`/emitting metadata is superseded because it would route a second empty emitter for source already carried by UID0001CM. Historical uncertainty about the exact original lexical type name remains evidence context but does not justify duplicate source.

## Score Rationale

Completion is `94` because the page fully records its non-emitting evidence-alias disposition, exact 12-byte layout, complete outer helper map, shared parser callers, callbacks, fallback behavior, compiler clone, source owner, and blank CPP/H handling.

Confidence is `94` because the class page, file page, memory island, loaders, fallback page, generated route, and live IDA evidence agree that UID0001CM owns the only concrete source. The residual reflects only the unrecovered original lexical type name.

## Cross-References

- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md)

## Changes

- 2026-06-29 B007 UID0001CM implementation callback:
  - Score unchanged at `86/86`.
  - Evidence: updated this address-derived class page as an alias covered by UID0001CM source declarations and method bodies. UID0001CM emits `ImageAnimationTable`; this page keeps evidence, layout, and xref context and does not duplicate helper C++.
  - Normalized half-open method-map endpoints for `0x005289d0`, `0x00528af0`, and `0x00528b10` from current session `b2ae72ec`.
- 2026-06-25 B001 implementation callback:
  - Score unchanged at `86/86`.
  - Evidence: aligned this address-derived helper page with accepted neutral names from [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md): `AllocateGroups` and `ImageAnimationGroup`. The page name remains an evidence alias; no standalone C++ declaration was added.
- Before: documented outer helper starts began at `0x00528950`.
- Changed to: include the `0x00528930` zero initializer in the outer helper family.
- Summary/evidence: 2026-05-28 IDA MCP xrefs tie `0x00528930` to direct setup calls and constructor-callback use from the same parser/allocation family.
- Completion/confidence score update: existed before as `0/0`; changed to `74/76`. Summary: the outer nested animation/image table helper has shared monster/riding caller evidence, method-start evidence, and initializer coverage, but its class name and final neutral struct/class model remain provisional. Evidence: linked `MonsterImageLibTables` range, IDA caller sites from `MonsterImageLib` and `RidingImageLib`, modeled start rechecks, no stable IDA names, and the 2026-05-28 zero-initializer xref update.
- 2026-06-03 source-owner consistency pass:
  - Changed to: `COMPLETION:78`, `CONFIDENCE:80`, `RECONSTRUCTABLE:TRUE`, and legacy parent metadata for [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md).
  - Summary/evidence: [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) now has a projected `NexusTK/render/MonsterImageLibTables.cpp` path, [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) documents the exact helper island and shared monster/riding caller family, and [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md) resolves the fallback frame-record ownership. Scores remained capped because the final neutral type name and complete field names still needed a dedicated layout pass; no C++ was added due source-shape uncertainty.
- 2026-06-07 class-page reconciliation:
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, added autogen-status and score-rationale sections, and added the `0x00528b50-0x00528b5f` nested group-record initializer.
  - Summary/evidence: [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) records thirteen helper bodies before `0x00528d60`; `0x00528b50` initializes 8-byte nested group records and is passed by `0x005289d0`; parent/file ownership remains [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md).
- 2026-06-14 C001 Goal 2 IDA refresh:
  - Before: `82/84`.
  - After: `86/86`, with live IDA 9.1 evidence for outer-helper function sizes, parser/allocation xrefs, constructor/destructor callback wiring, fallback-record use, and internal alignment bytes. Owner/emitter routing remains [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md); final C++ stays blank until a neutral type name and field names are source-quality.
