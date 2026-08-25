*** UID:00008P | DO NOT MODIFY OR REMOVE!!! ***
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

# MonsterImageLibTable_528BE0

## Status

- Confidence: very strong that this is a non-emitting address-derived evidence alias for UID0001CM's 8-byte `ImageAnimationGroup` and 10-byte `ImageAnimationFrame`; exact original lexical type names remain inferred.
- Likely source file: [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md), projected to `NexusTK/render/MonsterImageLibTables.cpp`
- Address ranges: [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md)
- 2026-06-29 B007 implementation: this remains an address-derived support alias. Source declarations and method bodies are now emitted by UID0001CM as `ImageAnimationGroup` / `ImageAnimationFrame`; this page should not duplicate helper C++.

## Class Purpose

`MonsterImageLibTable_528BE0` is the address-derived documentation page for the 8-byte group helper that owns 10-byte `ImageAnimationFrame` records plus a count word. It is part of the nested animation table infrastructure shared by monster and riding definition parsers.

The current page name is address-derived. Like `MonsterImageLibTable_5289D0`, it remains useful as an evidence/search alias, but final source should use neutral helper terminology. The 2026-06-25 B001 accepted target C++ uses `ImageAnimationGroup::AllocateFrames` and `ImageAnimationFrame` instead of this address-derived name.

## Autogen Status

- Parent file: [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- Reconstructable: `FALSE` as a distinct source entity; the represented source is fully reconstructable once through UID0001CM.
- C++/H emission: intentionally blank. [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) is the sole declaration/method carrier; this page preserves evidence and searchability for the address-derived name without duplicating source.

The parent file, memory helper island, and this class page now agree that this inner frame-record table belongs to shared monster/riding table infrastructure. The address-derived name remains provisional.

## Layout And Method Map

Current evidence supports an 8-byte `ImageAnimationGroup` helper object that owns a heap array of 10-byte `ImageAnimationFrame` records plus a count word. The shared default frame record is documented separately at [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md) and is attached to the same file owner.

| Range | Role | Evidence state |
| --- | --- | --- |
| `0x00528b60-0x00528bd9` | cleanup/destructor helper | Destroys the 10-byte frame-record vector and clears pointer/count state. |
| `0x00528be0-0x00528c7c` | `ImageAnimationGroup::AllocateFrames` helper | Allocates or resizes the `ImageAnimationFrame` array and uses the frame-record initializer callback. |
| `0x00528c80-0x00528cf9` | cleanup/unwind helper | Same cleanup shape as `0x00528b60`; currently treated as duplicate cleanup/EH support. |
| `0x00528d00-0x00528d28` | `ImageAnimationGroup::GetFrame` helper | Returns an in-range 10-byte `ImageAnimationFrame` or the shared default record at `0x0066deb0`. |
| `0x00528d30-0x00528d46` | `ImageAnimationFrame` initializer | Initializes normal records with frame offset/duration dword zero, byte `+0x04 = 0xff`, word `+0x06 = 0xffff`, and zero tail word. |
| `0x00528d50-0x00528d51` | no-op element destructor callback | Passed by allocation/cleanup helpers for records without nested destructible state. |

## Accepted Neutral Name Overlay

The accepted source-facing overlay for this page is:

- `ImageAnimationGroup`: 8-byte object with source fields `frames` and `frameCount`; the trailing word is implicit 32-bit tail padding. The current IDA analysis member remains protected but is not authored source.
- `AllocateFrames` and `GetFrame`: source-facing behavior represented by `0x00528be0` and `0x00528d00`, emitted by UID0001CM.
- `ImageAnimationFrame`: 10-byte record with `frameOffset`, `frameDuration`, `blendAlpha`, `reserved`, `auxFrameId`, `paletteIndex`, and `effectIndex`.

`frameOffset`, `frameDuration`, and monster-side `blendAlpha` are strong. `auxFrameId`, `paletteIndex`, and `effectIndex` remain inferred weaker names. The old `+0x02=endFrame` and `+0x04=direction` wording is superseded by the accepted B001 rework.

## Evidence Notes

- The memory helper island records thirteen helper bodies in `0x00528930-0x00528d51`; this inner helper owns the 10-byte frame-record cleanup/allocation, lookup, initializer, and no-op destructor callback portions.
- IDA MCP on 2026-05-22 reports four caller sites: two in `MonsterImageLib::LoadMonsterTables` and two in `RidingImageLib::LoadRidingDefinitions`.
- [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md) documents the shared fallback record returned by both frame-entry getters, so `unk_66DEB0` is no longer an unresolved class-local data ownership question.
- 2026-05-26 IDA `py_eval` recheck confirms modeled starts for this inner helper family at `0x00528b60`, `0x00528be0`, `0x00528c80`, and `0x00528d00`. `unk_66DEB0` has direct xrefs from both frame-entry getters, matching a shared default frame record rather than class-local arbitrary data.
- 2026-05-28 IDA MCP recheck adds the frame-record initializer at `0x00528d30` and no-op element destructor callback at `0x00528d50`; xrefs tie both to the inner helper allocation/cleanup callbacks.
- 2026-06-06 memory-island refresh confirms callback xrefs from `0x00528b60`, `0x00528be0`, and `0x00528c80` to `nullsub_13`/`0x00528d50`, plus fallback references from both frame-entry getters.
- 2026-06-14 C001 IDA MCP recheck confirms the current inner-helper inventory: cleanup `0x00528b60` size `0x79`, allocation `0x00528be0` size `0x9c`, unwind cleanup `0x00528c80` size `0x79`, frame lookup `0x00528d00` size `0x28`, frame-record initializer `0x00528d30` size `0x16`, and no-op destructor callback `0x00528d50` size `0x01`.
- The same live pass reconfirms four parser/allocation xrefs to `0x00528be0`, constructor-callback xref `0x00528be0 -> 0x00528d30`, no-op destructor callback xrefs from `0x00528b60`, `0x00528be0`, and `0x00528c80`, fallback record refs from `0x00528d00` to `0x0066deb0`, and `0xcc` padding at `0x00528d28-0x00528d30`, `0x00528d46-0x00528d50`, and `0x00528d51-0x00528d60`.
- 2026-06-29 B007 implementation on current MCP session `b2ae72ec` normalizes half-open inner-helper endpoints to `0x00528be0-0x00528c7c` and `0x00528d00-0x00528d28`. The same report confirms no recovered IDA name contains `MonsterImageLibTable`; `ImageAnimationGroup` and `ImageAnimationFrame` are the source-facing helper names emitted by UID0001CM.

## 2026-08-17 B008 Non-Emitting Alias Closure

This page does not describe a second C++ class. Its address-derived title groups the inner helper evidence from the shared island: group construction at `0x00528b50`, authored destruction at `0x00528b60`, frame allocation at `0x00528be0`, frame lookup at `0x00528d00`, and frame construction at `0x00528d30`. The zero-xref duplicate cleanup at `0x00528c80` is an EH clone, and the one-byte `retn` at `0x00528d50` is a compiler-generated trivial frame-destructor callback rather than source.

The complete source-facing `ImageAnimationGroup` and `ImageAnimationFrame` declarations and authored method definitions are emitted exactly once by UID0001CM under `MonsterImageLibTables.h/.cpp`. This alias therefore has `RECONSTRUCTABLE:FALSE`, blank emitter routing and positions, and blank formal CPP/H. It retains owner UID0000LK because the evidence belongs to that compilation unit. No source declaration uses `MonsterImageLibTable_528BE0`.

The group has source fields `ImageAnimationFrame *frames` at `+0x00` and unsigned 16-bit `frameCount` at `+0x04`; 32-bit alignment supplies the `+0x06` tail. The frame is exactly 10 bytes with signed `short frameDuration`; the constructor does not write the reserved byte. Frame allocation preserves low-byte count truncation, frame lookup uses a 10-byte stride, and out-of-range lookup returns the source-defined fallback object at `0x0066deb0`.

Historical `TRUE`/emitting metadata is superseded because it would route a second empty emitter for source already carried by UID0001CM. Historical uncertainty about exact original lexical names remains evidence context but does not justify duplicate source.

## Score Rationale

Completion is `94` because the page fully records its non-emitting evidence-alias disposition, exact 8-byte/10-byte layouts, complete inner helper map, shared parser callers, callbacks, fallback behavior, compiler clone/trivial-callback handling, source owner, and blank CPP/H route.

Confidence is `94` because the class page, file page, memory island, loaders, fallback page, generated route, and live IDA evidence agree that UID0001CM owns the only concrete source. The residual reflects only unrecovered lexical type/field spellings.

## Cross-References

- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md)

## Changes

- 2026-06-29 B007 UID0001CM implementation callback:
  - Score unchanged at `86/86`.
  - Evidence: updated this address-derived class page as an alias covered by UID0001CM source declarations and method bodies. UID0001CM emits `ImageAnimationGroup` and `ImageAnimationFrame`; this page keeps evidence, layout, fallback, and xref context and does not duplicate helper C++.
  - Normalized half-open method-map endpoints for `0x00528be0` and `0x00528d00` from current session `b2ae72ec`.
- 2026-06-25 B001 implementation callback:
  - Score unchanged at `86/86`.
  - Evidence: aligned this address-derived helper page with accepted neutral names from [UID:0002JN][0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables](by-memory/0x004dac40-0x004daebc.MonsterImageLibLoadMonsterTables.md): `ImageAnimationGroup::AllocateFrames` and `ImageAnimationFrame`. Preserved weaker caveats for `auxFrameId`, `paletteIndex`, and `effectIndex`; no standalone C++ declaration was added.
- Before: documented inner helper starts ended at `0x00528d00`.
- Changed to: include the frame-record initializer at `0x00528d30` and no-op element destructor callback at `0x00528d50`.
- Summary/evidence: 2026-05-28 IDA MCP xrefs show `0x00528d30` is passed as a constructor callback by `0x00528be0`, and `0x00528d50` is passed as a no-op destructor callback by the cleanup/allocation helpers.
- Completion/confidence score update: existed before as `0/0`; changed to `74/76`. Summary: the inner shared animation/image table helper has strong caller and helper-boundary evidence, but the address-derived class name, neutral final type name, and shared default-frame record ownership still need cleanup. Evidence: linked `MonsterImageLibTables` range, IDA callers from monster/riding parsers, `unk_66DEB0` xrefs, modeled starts, and 2026-05-28 callback xref updates.
- 2026-06-03 source-owner consistency pass:
  - Changed to: `COMPLETION:78`, `CONFIDENCE:80`, `RECONSTRUCTABLE:TRUE`, and legacy parent metadata for [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md).
  - Summary/evidence: [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) now has a projected `NexusTK/render/MonsterImageLibTables.cpp` path, [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) documents the exact inner helper method/callback island, and [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md) documents the shared fallback frame record this helper returns. Scores remained capped because the final neutral type name and field names still needed a dedicated layout pass; no C++ was added due source-shape uncertainty.
- 2026-06-07 class-page reconciliation:
  - Changed to: `COMPLETION:82`, `CONFIDENCE:84`, added autogen-status and score-rationale sections, and resolved the old `unk_66DEB0` ownership caveat to the documented shared fallback frame record.
  - Summary/evidence: [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) records the inner cleanup/allocation/callback helper family and fallback references; [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md) owns the fallback record; parent/file ownership remains [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md).
- 2026-06-14 C001 Goal 2 IDA refresh:
  - Before: `82/84`.
  - After: `86/86`, with live IDA 9.1 evidence for inner-helper function sizes, parser/allocation xrefs, constructor/no-op destructor callback wiring, fallback-record use, and internal alignment bytes. Owner/emitter routing remains [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md); final C++ stays blank until a neutral type name and field names are source-quality.
