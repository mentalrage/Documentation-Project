*** UID:0001UT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ItemInfo

## Status

- Confidence: strong for size, owner, constructor read order, fallback initialization, and draw-method consumption; medium-high overall because final source-facing field names remain provisional.
- Owner file: [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md).
- Source resources: `ITEM.TBL` / `ITEM.TBD`.
- Size: `0x14` bytes.
- Primary IDA evidence: 2026-05-31 decompilation of `ItemObjImageLib::ItemObjImageLib` and draw methods at `0x004dee50`, `0x004defc0`, `0x004df1e0`, and `0x004df2c0`.

## Scope Caveat

This page documents the render image-table `ItemInfo` used by [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md) and `ProtectedArray<ItemInfo>`. It is not necessarily the broader gameplay item database record returned by item/inventory systems.

## Layout

```text
ItemInfo
  +0x00  int resourceKeyOrId
  +0x04  int paletteSlot
  +0x08  float alpha
  +0x0c  int frameOrRenderFlags
  +0x10  uint8 allowPaletteFilter
  +0x11  uint8[3] padding
```

## Notes

- The constructor reads five fields per row: int, int, float, int, int. The final int is collapsed to a boolean byte at offset `+0x10`.
- `DrawItemImage` and sibling draw methods use `+0x04` as the palette slot for palette category `10`, `+0x08` as the alpha/tint mode selector, and `+0x10` as the palette-filter allow flag.
- Current draw methods do not visibly consume every field in IDA pseudocode; final semantic names for `+0x00` and `+0x0c` remain provisional.
- The fallback row embedded in [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md) is initialized to `-1`, `-1`, `0.0`, `-1`, `0`.

## IDA Evidence

- `ItemObjImageLib::ItemObjImageLib` at `0x004dec30-0x004dee1b` reads each table row with four integer reads and one float read: offsets `+0x00`, `+0x04`, `+0x08`, `+0x0c`, and a final integer collapsed to byte `+0x10`.
- The constructor writes each row as a 16-byte copy plus a dword at `+0x10`, confirming the `0x14` stride.
- Draw paths load records as `*(_OWORD*)record` plus `*(record+16)`, confirm fallback at object offset `+0x14`, use `+0x04` as the palette slot input to `PaletteLib` category `10`, branch on float `+0x08`, and test the byte form of `+0x10` when palette filtering is active.
- 2026-05-31 IDA vtable/global xrefs tie the consumer methods back to [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md), not to the broader gameplay item database.

## Cross-References

- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:00006W][ItemObjImageLib](by-class/ItemObjImageLib.md)
- [UID:0001UU][ItemObjImageLibLayout](by-type/by-struct/ItemObjImageLibLayout.md)
- [UID:00017N][0x004dec30-0x004e65dc.ItemObjImageLib](by-memory/0x004dec30-0x004e65dc.ItemObjImageLib.md)
- [UID:00017O][0x004dee20-0x004dee4d.ItemObjImageLibDestructor](by-memory/0x004dee20-0x004dee4d.ItemObjImageLibDestructor.md)

## Changes

- 2026-05-31 IDA-backed scoring update:
  - What existed before: `COMPLETION:0`, `CONFIDENCE:0`, and `RECONSTRUCTABLE:` blank despite a usable layout sketch.
  - Changed to: `COMPLETION:82`, `CONFIDENCE:86`, and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA constructor decompilation proves the 20-byte row stride and row read order, draw methods prove palette/alpha/filter field usage, and `ItemObjImageLib` vtable/global xrefs prove this is the render image-table row rather than a gameplay inventory item record. Scores remain below final level because the original field names for `+0x00` and `+0x0c` remain provisional.
