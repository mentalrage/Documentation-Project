*** UID:0001UU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ItemObjImageLib Layout

## Status

- Confidence: strong for field offsets, `ProtectedArray<ItemInfo>` shape, fallback row placement, singleton/vtable anchors, and destructor cleanup; medium-high overall because final source-facing names remain provisional.
- Owner class: [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md).
- Evidence: IDA constructor/destructor/draw decompilation, vtable xrefs, singleton xrefs, and byte-boundary checks through 2026-05-31.

## Layout

```text
ItemObjImageLib
  +0x00  LObject/vtable
  +0x04  ProtectedArray<ItemInfo> itemInfoArray
  +0x14  ItemInfo fallbackItemInfo
```

Expanded view:

```text
  +0x04  void* protectedArrayVtable
  +0x08  int itemInfoCountOrCapacity
  +0x0c  ItemInfo* itemInfoEntries
  +0x10  int initialOrGrowCapacity
  +0x14  ItemInfo fallbackItemInfo
```

## Notes

- The constructor writes [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md), stores the [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md), initializes the protected array with capacity `10`, and seeds the fallback [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md) with `-1`, `-1`, `0.0`, `-1`, `0`.
- The constructor opens `ITEM.TBL` in the current/extended item-table path and `ITEM.TBD` in the alternate legacy path, then reads `0x14`-byte [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md) records.
- Draw methods index the array by an item entry id derived from `itemId + 0x4000`, falling back to the record at `+0x14` when out of range.
- The ordinary and scalar deleting destructors free the entry buffer at `+0x0c` and clear [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md).

2026-05-31 IDA recheck confirms the exact constructor end at `0x004dee1b`, scalar deleting destructor range `0x004e6580-0x004e65dc`, vtable at `0x0061b73c`, and singleton writes/clears at `0x004dec7b`, `0x004dec82`, `0x004dee3b`, `0x004e5ba0`, and `0x004e659e`.

## Cross-References

- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md)
- [UID:0001XW][ItemObjImageLibVtable](by-type/by-vtable/ItemObjImageLibVtable.md)
- [UID:0001UT][ItemInfo](by-type/by-struct/ItemInfo.md)
- [UID:0000RA][g_pItemObjImageLib](by-global/g_pItemObjImageLib.md)
- [UID:00017N][0x004dec30-0x004e65dc.ItemObjImageLib](by-memory/0x004dec30-0x004e65dc.ItemObjImageLib.md)
- [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md)

## Changes

- 2026-05-31 IDA-backed scoring update:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: constructor, draw, ordinary destructor, scalar deleting destructor, vtable xrefs, singleton xrefs, and boundary bytes confirm the object layout, embedded fallback item info, and `ProtectedArray<ItemInfo>` storage. Scores remain below `95` because final field names and exact original header shape remain open.
