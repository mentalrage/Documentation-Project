*** UID:0001VS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ResourceLayoutBucket

## Status

- Entity kind: semantic view over [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md)
- Confidence: strong that there is no separate bucket allocation in the reviewed path; medium for final field names.
- Proposed owner: [UID:0000K2][ImageLib](by-file/ImageLib.md) / [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- Evidence basis: IDA MCP decompilation of `ImageLib::ImageLib`, `ResourceLayoutTable` methods, and `List` vtable calls.

## Current Interpretation

The earlier `ResourceLayoutBucket` model described a separate object reached through a custom store. IDA now shows the registry is a generic [UID:000079][List](by-class/List.md) of 44-byte [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) elements. The "bucket" read by lookup/count/size methods is the same list element:

```text
ResourceLayoutNameRecord / bucket view
  +0x00  wchar_t name[16]
  +0x20  uint16 entryCount
  +0x22  uint16 frameWidth
  +0x24  uint16 frameHeight
  +0x26  uint16 reservedHeaderWord
  +0x28  ResourceLayoutEntry* entries
```

Confirmed reads:

- `LookupLayoutEntry`: uses `entryCount` and `entries`.
- `GetEntryRect`: uses `entryCount` and `entries`.
- `GetFrameSize`: uses `frameWidth` / `frameHeight`.
- `GetEntryCount`: uses `entryCount`.

## Open Questions

- Whether to keep a named `ResourceLayoutBucket` typedef in docs/source for readability, or collapse all references to `ResourceLayoutNameRecord`.
- Whether `frameWidth` and `frameHeight` are maximum dimensions, sheet dimensions, or source frame metrics for the bucket.
- Exact meaning of the fourth 16-bit header word at `+0x26`.

## Cross-References

- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md)
- [UID:0000VB][ResourceLayoutEntry](by-item/ResourceLayoutEntry.md)
- [UID:000079][List](by-class/List.md)
- [UID:000174][0x004d0120-0x004d182e.ResourceLayoutTable](by-memory/0x004d0120-0x004d182e.ResourceLayoutTable.md)

## Changes

- 2026-05-31: Scored and marked as not a standalone reconstructable type.
  - Before: metadata was `0/0` with blank reconstruction state even though the page already documented that the bucket is the same 44-byte record as `ResourceLayoutNameRecord`.
  - After: set completion/confidence to `78/86` and `RECONSTRUCTABLE:FALSE` for standalone autogen purposes.
  - Evidence: IDA MCP decompilation on 2026-05-31 confirms `ImageLib::ImageLib` constructs a generic `List(44, 10)`, `FindResourceIndex` advances by 44-byte rows, and accessors read the same row fields; no separate bucket allocation or vtable is visible.
