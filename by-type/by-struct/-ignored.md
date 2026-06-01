*** UID:0001TM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Ignored Struct Records

Use this file to list struct candidates that should not be reconstructed as NexusTK-owned structs.

Add entries for CRT/STL/compiler structs, Windows SDK structs, third-party-library structs, stale generated synthetic overlays, or structs superseded by better class/global docs. Include name/size/address evidence, reason, and replacement link.

## Ignored Entries

- `ResourceLayoutStore` ([UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)): stale generated standalone struct/class overlay.
  - Reason: current IDA evidence shows the registry field is a generic [UID:000079][List](by-class/List.md), not a custom store object.
  - Evidence: `ImageLib::ImageLib` decompiles to `List::List(elementSize = 44, pageSize = 10)`, ResourceLayout accessors call the generic list vtable, and xrefs to `0x0061ce2c` resolve to generic `List` methods.
  - Replacement owner: [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md) as the list element record, stored in [UID:000079][List](by-class/List.md).
- `ResourceLayoutBucket` as a standalone allocation ([UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)): semantic alias over the same 44-byte [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md).
  - Reason: no separate bucket allocation, vtable, or independent object was found in the reviewed ResourceLayout path.
  - Evidence: `FindResourceIndex` advances by 44-byte rows, lookup/count/size accessors read fields from the same row, and `LoadResourceIndex` appends one 44-byte record to the generic list.
  - Replacement owner: [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md); keep the bucket page only as a search-friendly semantic alias.
