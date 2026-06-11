*** UID:0001VF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:000092 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# NewHumanImageLib Layout

## Status

- Confidence: strong for observed offsets and constructor/destructor agreement, medium for final field names and exact original nested row type names.
- Owner class: [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md).
- Autogen parent: attached to [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md); the class scores `82/82` and this layout scores `80/86`, so both sides satisfy the 80/80 parent gate.
- Evidence: IDA constructor/destructor decompilation on 2026-05-26 and constructor/function-boundary recheck on 2026-05-31.

## Layout

```text
NewHumanImageLib
  +0x00  LObject/vtable
  +0x04  NewHumanPartEntry* partEntriesBegin
  +0x08  NewHumanPartEntry* partEntriesEnd
  +0x0c  NewHumanPartEntry* partEntriesCapacity
  +0x10  NewHumanLayerEntry* layerEntriesBegin
  +0x14  NewHumanLayerEntry* layerEntriesEnd
  +0x18  NewHumanLayerEntry* layerEntriesCapacity
  +0x1c  NewHumanMotionEntry* motionEntriesBegin
  +0x20  NewHumanMotionEntry* motionEntriesEnd
  +0x24  NewHumanMotionEntry* motionEntriesCapacity
  +0x28  void* auxiliaryEntriesBegin
  +0x2c  void* auxiliaryEntriesEnd
  +0x30  void* auxiliaryEntriesCapacity
  +0x34  list/sentinel state begin
  +0x38  list/sentinel state
  +0x3c  list/sentinel state
  +0x40  list/sentinel state
  +0x44  list/sentinel state end
  +0x48  Acc2DrwEntry* acc2drwEntriesBegin
  +0x4c  Acc2DrwEntry* acc2drwEntriesEnd
  +0x50  Acc2DrwEntry* acc2drwEntriesCapacity
  +0x54  int* hairColorEntriesBegin
  +0x58  int* hairColorEntriesEnd
  +0x5c  int* hairColorEntriesCapacity
```

## Notes

- The exact constructor page is [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md). It writes [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md), constructs the `LObject` base, stores the [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md), zeros all vector triplets, allocates an 8-byte sentinel/list node for the `+0x34` state, then loads `Motion.tbl`, `Layer.tbl`, `Part.tbl`, per-part descriptors, `acc2drw.tbl`, and `HAIRCOL.TBL`.
- `Part.tbl` rows are 0x44-byte records in the `+0x04` vector. The constructor converts the 20-byte ANSI part name to wide characters and stores the resolved part EPF path at row offset `+0x40`.
- `Layer.tbl` rows are 0x20-byte records in the `+0x10` vector. Rows can own a child-index array at row offset `+0x1c`.
- `Motion.tbl` rows are 0x42-byte records in the `+0x1c` vector. [UID:000185][0x004e5dd0-0x004e5e39.DestroyMotionVector](by-memory/0x004e5dd0-0x004e5e39.DestroyMotionVector.md) frees their dynamic blocks during destruction.
- `acc2drw.tbl` entries live in the `+0x48` vector, and `HAIRCOL.TBL` integer palette indices live in the `+0x54` vector.
- Current generated source emits several shared render globals in `class_NewHumanImageLib.cpp`; that does not make them fields of this object. This layout should be used for object reconstruction.

## IDA Verification Notes

- `lookup_funcs 0x004dfd10` reports `sub_4DFD10`, size `0x53a`, exact range `0x004dfd10-0x004e024a`.
- `lookup_funcs 0x004e0250` reports the ordinary destructor body at `0x004e0250-0x004e05c4` exclusive; the existing destructor page uses `0x004e05c3` as the last observed byte.
- IDA decompilation shows constructor writes to object words `a1[1]` through `a1[23]`, matching fields through `+0x5c`.
- IDA UTF-16 reads confirm the constructor resource strings `Layer.tbl`, `Part.tbl`, `acc2drw.tbl`, `.DSC`, and `HAIRCOL.TBL`.
- Destructor cleanup agrees with the constructor layout: it walks 0x44-byte part rows from `+0x04`, 0x20-byte layer rows from `+0x10`, 0x42-byte motion rows from `+0x1c`, and then frees the `+0x54` hair-color vector plus `+0x48`, `+0x34`, `+0x28`, `+0x1c`, `+0x10`, and `+0x04` storage in reverse-style cleanup order.

## Cross-References

- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md)
- [UID:0002JR][0x004dfd10-0x004e024a.NewHumanImageLibConstructor](by-memory/0x004dfd10-0x004e024a.NewHumanImageLibConstructor.md)
- [UID:0001Y9][NewHumanImageLibVtable](by-type/by-vtable/NewHumanImageLibVtable.md)
- [UID:0000RT][g_pNewHumanImageLib](by-global/g_pNewHumanImageLib.md)
- [UID:00017S][0x004e0250-0x004e05c4.NewHumanImageLibDestructor](by-memory/0x004e0250-0x004e05c4.NewHumanImageLibDestructor.md)
- [UID:0001RI][new-human-motion-tables](by-resource/new-human-motion-tables.md)
- [UID:0000VA][ResolveSpritePartPath_004E19D0](by-item/ResolveSpritePartPath_004E19D0.md)

## Changes

- 2026-06-06: Attached the object layout to [UID:000092][NewHumanImageLib](by-class/NewHumanImageLib.md). Scores remain `80/86`; this pass only records the direct class parent for the already documented constructor/destructor layout.
- Before: metadata was `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` even though the page contained substantial layout evidence.
- Changed to: `COMPLETION:80`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE`.
- Summary/evidence: IDA MCP rechecked the constructor range, resource strings, constructor field writes, and destructor cleanup agreement on 2026-05-31. The score remains below final-audit status because final original field names and nested row type names are still not fully proven.
