*** UID:0001VT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000BY | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ResourceLayoutNameRecord

## Status

- Entity kind: support struct
- Confidence: strong for row width, key fields, and direct ResourceLayoutTable class/facet ownership; medium-high for final source field names.
- Direct owner: [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md), with broader source ownership through [UID:0000K2][ImageLib](by-file/ImageLib.md).
- Evidence basis: IDA MCP decompilation of `ImageLib::ImageLib`, `ResourceLayoutTable::LoadResourceIndex`, `FindResourceIndex`, and `List` vtable calls.

## Layout

`ImageLib::ImageLib` constructs the registry as `List::List(44, 10)`, so each resource-layout list element is 44 bytes:

```text
ResourceLayoutNameRecord
  +0x00  wchar_t name[16]
  +0x20  uint16 entryCount
  +0x22  uint16 frameWidth
  +0x24  uint16 frameHeight
  +0x26  uint16 reservedHeaderWord
  +0x28  ResourceLayoutEntry* entries
```

`ResourceLayoutTable::LoadResourceIndex` reads the 8-byte EPF/EPD header into the four 16-bit fields at `+0x20` through `+0x26`, allocates `entryCount + 1` [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md) rows, stores that pointer at `+0x28`, copies the resource key into `name[16]`, and appends the whole 44-byte record to the [UID:000079][List](by-class/List.md).

`FindResourceIndex` obtains the first row with `List::GetElementAt(0)`, uses `List::count` as the loop bound, and advances by 44 bytes (`v5 += 22` wide characters) while comparing `name` with `wcscmp`.

## Assignment Gate

Batch143 recheck, 2026-06-08: this struct now clears the corrected child gate at `85/89`, and its actual direct parent [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) already clears the parent gate at `87/86`. The direct-owner choice is the class/facet page rather than the broader file because the type is the private 44-byte registry row consumed by `ResourceLayoutTable` lookup/accessor methods. [UID:0000K2][ImageLib](by-file/ImageLib.md) remains the broader source-file parent through the class/facet chain, but it is not the immediate type parent.

## Notes

- The earlier `name[0x16]` hypothesis was caused by treating the 44-byte stride as all wide characters. The first 32 bytes are the actual name buffer; the remaining 12 bytes are header metadata and the entry pointer.
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md) is now best treated as a semantic view of this same 44-byte record, not a separate heap object.
- `reservedHeaderWord` is read from the file header but no current accessor names it.

## Cross-References

- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)
- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)
- [UID:000079][List](by-class/List.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:000174][0x004d0120-0x004d182f.ResourceLayoutTable](by-memory/0x004d0120-0x004d182f.ResourceLayoutTable.md)

## Changes

- 2026-05-31: Scored and marked as a reconstructable source-level record.
  - Before: metadata was `0/0` with blank reconstruction state despite strong recorded layout evidence.
  - After: set completion/confidence to `82/88` and `RECONSTRUCTABLE:TRUE`; parent and C++ remain blank because the final source-file owner is still split between `ImageLib` and the `ResourceLayoutTable` helper/facet.
  - Evidence: IDA MCP decompilation on 2026-05-31 confirms the 44-byte `List` element size, 16-wide-character name buffer, header fields at `+0x20` through `+0x26`, entry pointer at `+0x28`, and 44-byte scan stride.
- 2026-06-08 A003 Batch143 direct-parent audit:
  - What existed before: `COMPLETION:82`, `CONFIDENCE:88`, and blank `AUTOGEN_PARENT_UID` because the older note treated the final owner as split between `ImageLib` and `ResourceLayoutTable`.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:89`, `AUTOGEN_PARENT_UID:0000BY`; C++ remains blank.
  - Evidence: the class/facet page [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) now documents the same 44-byte row shape, `List(44, 10)` registry ownership, lazy-load/accessor consumers, and parent chain to [UID:0000K2][ImageLib](by-file/ImageLib.md). The direct type parent clears `87/86`, the broader file clears `87/86`, and the row is a private ResourceLayoutTable registry element rather than an independent file-level helper type.
