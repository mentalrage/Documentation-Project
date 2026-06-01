*** UID:0001VG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ObjectListLayout

## Status

- Entity kind: class layout support struct
- Confidence: strong for offsets, allocation/cleanup agreement, and ObjectList ownership; medium for final source-facing tier/list names.
- Proposed owner: [UID:0000M4][ObjectList](by-file/ObjectList.md)
- Evidence basis: IDA MCP decompilation of `ObjectList` lifecycle/accessor methods and generated `class_ObjectList.cpp` / `class_MapPaneSpatialIndex.cpp`.

## Layout

```text
ObjectListLayout
  +0x00  void* vtable
  +0x04  int minX
  +0x08  int minY
  +0x0c  int gridWidth
  +0x10  int gridHeight
  +0x14  List* primaryCellList
  +0x18  List* secondaryCellList
  +0x1c  List** primaryRowLists
  +0x20  List** secondaryRowLists
  +0x24  List** tertiaryRowLists
  +0x28  List** extendedRowLists
  +0x2c  List* primaryGlobalList
  +0x30  List* secondaryGlobalList
  +0x34  List* alternateGlobalList
  +0x38  List* tertiaryGlobalList
  +0x3c  List* quaternaryGlobalList
  +0x40  List* quinaryGlobalList
```

Observed object size is `0x44` bytes. The constructor is called after allocating 68 bytes.

## Allocation Rules

- `primaryCellList` and `secondaryCellList` use capacity `(gridWidth + 4) * (gridHeight + 4) * 100`.
- `primaryRowLists`, `secondaryRowLists`, and `tertiaryRowLists` each have `gridHeight + 4` entries.
- `extendedRowLists` has `gridHeight + 12` entries.
- Row-list capacity is `(gridWidth + 4) * 10`.
- The alternate global list at `+0x34` is only allocated when the client variant flag at `0x0066da97` is set to `1`.

## IDA Verification

- [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md) stores the sentinel origin fields, grid dimensions, all row-list arrays, and global list tiers at the offsets listed above.
- [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md) destroys the same fields in the matching cleanup order, including conditional cleanup of `+0x34` when `byte_66DA97 == 1`.
- IDA MCP reports the constructor as `0x00530ee0-0x0053125d` and the ordinary destructor as `0x00531260-0x00531473`; the bytes between them are three `0xcc` alignment bytes.
- Constructor callers are in `MapPane::ChangeMap` and `MapPane::HandleEffectPacket`, confirming this layout belongs to the map object-index owner rather than a generic list container.

## Naming Notes

The `primary/secondary/tertiary` names are structural placeholders. Existing `MapPaneSpatialIndex` docs name the same fields as render layers and row buckets. Keep both naming surfaces linked until render-layer callers define final source names.

## Cross-References

- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:0000M4][ObjectList](by-file/ObjectList.md)
- [UID:0001D1][0x00530ee0-0x00531473.ObjectListLifecycle](by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md)
- [UID:0002JS][0x00530ee0-0x0053125d.ObjectListConstructor](by-memory/0x00530ee0-0x0053125d.ObjectListConstructor.md)
- [UID:0002JT][0x00531260-0x00531473.ObjectListDestructor](by-memory/0x00531260-0x00531473.ObjectListDestructor.md)
- [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md)
- [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md)
- [UID:000079][List](by-class/List.md)

## Changes

### 2026-05-31 - Verified Constructor/Destructor Layout Agreement

- What existed before: the layout page listed ObjectList offsets and allocation rules but did not link to exact child lifecycle pages or record the constructor/destructor boundary evidence.
- What changed: the page now links the exact constructor and destructor pages, records the IDA-confirmed ranges, and ties allocation/cleanup behavior directly to the field offsets.
- Why: IDA MCP decompilation and byte checks show the constructor populates each listed field, the destructor cleans up the same layout, and the `0x0053125d-0x00531260` gap is padding rather than source-authored code.
