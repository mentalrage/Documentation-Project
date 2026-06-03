*** UID:00008P | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000LK | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MonsterImageLibTable_528BE0

## Status

- Confidence: strong for behavior, source placement, shared caller evidence, and default-record ownership; medium for final neutral class/struct name.
- Likely source file: [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md), projected to `NexusTK/render/MonsterImageLibTables.cpp`
- Address ranges: [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md)
- Current recovered file: `source-3/simroot_v2/class_MonsterImageLibTable_528BE0.cpp`

## Class Purpose

`MonsterImageLibTable_528BE0` is a small owner for 10-byte image table records plus a count word. It is part of the nested animation table infrastructure shared by monster and riding definition parsers.

The current name is address-derived. Like `MonsterImageLibTable_5289D0`, it should be reviewed for a neutral helper name before final ownership migration.

## Layout And Method Map

Current evidence supports an 8-byte inner helper object that owns a heap array of 10-byte image/frame records plus a count word. The shared default frame record is documented separately at [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md) and is now attached to the same file owner.

| Range | Role | Evidence state |
| --- | --- | --- |
| `0x00528b60-0x00528bd9` | cleanup/destructor helper | Destroys the 10-byte frame-record vector and clears pointer/count state. |
| `0x00528be0-0x00528c7b` | allocation/resizing helper | Allocates or resizes the frame-record array and uses the frame-record initializer callback. |
| `0x00528c80-0x00528cf9` | cleanup/unwind helper | Same cleanup shape as `0x00528b60`; currently treated as duplicate cleanup/EH support. |
| `0x00528d00-0x00528d27` | frame lookup helper | Returns an in-range 10-byte record or the shared default record at `0x0066deb0`. |
| `0x00528d30-0x00528d46` | frame-record initializer | Initializes normal records with null pointer, byte/word invalid sentinels, and zero tail word. |
| `0x00528d50-0x00528d51` | no-op element destructor callback | Passed by allocation/cleanup helpers for records without nested destructible state. |

## Evidence Notes

- Wave3 class summary reports 2 methods, effective grade `96.8`.
- IDA MCP on 2026-05-22 reports four caller sites: two in `MonsterImageLib::LoadMonsterTables` and two in `RidingImageLib::LoadRidingDefinitions`.
- Current metadata also lists global data `unk_66DEB0`; ownership of that data should be checked before a file move.
- 2026-05-26 IDA `py_eval` recheck confirms modeled starts for this inner helper family at `0x00528b60`, `0x00528be0`, `0x00528c80`, and `0x00528d00`. `unk_66DEB0` has direct xrefs from both frame-entry getters, matching a shared default frame record rather than class-local arbitrary data.
- 2026-05-28 IDA MCP recheck adds the frame-record initializer at `0x00528d30` and no-op element destructor callback at `0x00528d50`; xrefs tie both to the inner helper allocation/cleanup callbacks.

## Cross-References

- [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md)
- [UID:00008N][MonsterImageLib](by-class/MonsterImageLib.md)
- [UID:0000BZ][RidingImageLib](by-class/RidingImageLib.md)

## Changes

- Before: documented inner helper starts ended at `0x00528d00`.
- Changed to: include the frame-record initializer at `0x00528d30` and no-op element destructor callback at `0x00528d50`.
- Summary/evidence: 2026-05-28 IDA MCP xrefs show `0x00528d30` is passed as a constructor callback by `0x00528be0`, and `0x00528d50` is passed as a no-op destructor callback by the cleanup/allocation helpers.
- Completion/confidence score update: existed before as `0/0`; changed to `74/76`. Summary: the inner shared animation/image table helper has strong caller and helper-boundary evidence, but the address-derived class name, neutral final type name, and shared default-frame record ownership still need cleanup. Evidence: linked `MonsterImageLibTables` range, IDA callers from monster/riding parsers, `unk_66DEB0` xrefs, modeled starts, and 2026-05-28 callback xref updates.
- 2026-06-03 source-owner consistency pass:
  - Changed to: `COMPLETION:78`, `CONFIDENCE:80`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000LK`.
  - Summary/evidence: [UID:0000LK][MonsterImageLibTables](by-file/MonsterImageLibTables.md) now has a projected `NexusTK/render/MonsterImageLibTables.cpp` path, [UID:0001CM][0x00528930-0x00528d51.MonsterImageLibTables](by-memory/0x00528930-0x00528d51.MonsterImageLibTables.md) documents the exact inner helper method/callback island, and [UID:00027U][0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord](by-memory/0x0066deb0-0x0066debc.MonsterImageLibDefaultFrameRecord.md) documents the shared fallback frame record this helper returns. Scores remain capped because the final neutral type name and field names still need a dedicated layout pass; no C++ was added under the 95+ gate.
