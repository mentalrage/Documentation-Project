*** UID:0000VB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000K2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ResourceLayoutEntry

## Status

- Confidence: strong for in-memory field order and lookup semantics, medium for original type name.
- Entity kind: EPF/EPD frame record used by `ResourceLayoutTable`.
- Autogen parent: [UID:0000K2][ImageLib](by-file/ImageLib.md). Live IDA evidence shows the `ResourceLayoutTable` method cluster is a non-virtual layout facet operating through the `ImageLib`/`g_pEPFLib` singleton and its `+0x0c` list.
- Related source file: [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) tracks the method-cluster facet, but `ImageLib` is the stronger autogen owner.
- Rebuild handling: `source-authored`/`source-declared` resource-layout data structure. The type needs to be reconstructed, but the C++ declaration remains blank until the surrounding resource table pages and final naming are 95% audited.

## In-Memory Layout

```text
ResourceLayoutEntry
  +0x00  int left
  +0x04  int top
  +0x08  int right
  +0x0c  int bottom
  +0x10  int pixelData
  +0x14  int encodedMaskData
```

`ResourceLayoutTable::LoadResourceIndex` allocates `entryCount + 1` rows. The extra row is a sentinel with zero bounds and both offset fields set to the resource's record-table boundary.

## Raw EPF/EPD Record Read

The raw table entry is read in this order:

```text
Raw resource-layout record
  +0x00  int16 top
  +0x02  int16 left
  +0x04  int16 bottom
  +0x06  int16 right
  +0x08  int32 pixelDataOffset
  +0x0c  int32 encodedMaskDataOffset
```

The loader converts the bounds to `left, top, right, bottom` and makes offsets absolute by adding `DATFile::GetDataBase() + 0xc`.

## Lookup Semantics

`ResourceLayoutTable::LookupLayoutEntry` maps a row into `EPFTileContext`:

```text
pixelData       = entry.pixelData
rowStride       = entry.right - entry.left
bounds          = entry bounds
encodedMaskData = entry.encodedMaskData
encodedMaskSize = nextEntry.pixelData - entry.encodedMaskData
```

The size calculation means the following row, including the sentinel, is a required boundary marker. This is similar to the DAT entry table's next-row boundary pattern, but it belongs to EPF/EPD frame metadata rather than DAT archive records.

## IDA MCP Evidence

Rechecked with live IDA MCP on 2026-06-03:

- Exact function boundaries: `sub_4D0120` is `0x004d0120-0x004d02e5`, `sub_4D02F0` is `0x004d02f0-0x004d039e`, `sub_4D04D0` is `0x004d04d0-0x004d0522`, `sub_4D0530` is `0x004d0530-0x004d059b`, and `sub_4D05A0` is `0x004d05a0-0x004d05e6`.
- `sub_4D0120` constructs and opens a `DATFile`, reads an 8-byte header and a dword record-table offset, seeks to that table, and allocates `24 * (entryCount + 1)` bytes.
- The loader reads each raw row as 16-bit `top`, `left`, `bottom`, `right`, then two dword offsets. It stores the bounds through `sub_4B7C50(row, left, top, right, bottom)`, so the in-memory row order is `left/top/right/bottom`.
- After seeking back to the archive base, `sub_4D0120` calls the data-base helper, adds `base + 0xc` to each row's payload and mask offsets, and appends a sentinel row with zero bounds and both offsets set to `base + 0xc + recordTableOffset`.
- `sub_4D02F0` finds or lazy-loads the resource bucket, validates the entry index, copies row payload data into an `EPFTileContext`-style output, computes `rowStride = right - left`, and computes `encodedMaskSize = nextEntry.pixelData - entry.encodedMaskData`.
- `sub_4D04D0` builds a temporary `EPFTileContext`, calls `sub_4D02F0`, and optionally copies the result through the tile-context copy helper.
- `sub_4D0530` finds or lazy-loads the same bucket and copies the selected row's first 16 bytes into a rectangle output; invalid indexes zero the rectangle through `sub_4B7C50`.
- `sub_4D05A0` is the raw-table rectangle helper: if the index is in range it copies the first 16 bytes from `recordBase + 24 * index`; otherwise it zeroes the rectangle.
- Parent evidence: `sub_4CFFB0` initializes the `ImageLib` singleton, writes `g_pEPFLib` at `0x0067a744`, allocates the `+0x0c` list, and the layout methods fetch buckets from that same list. The ResourceLayoutTable naming is therefore a non-virtual facet rather than a stronger autogen owner than `ImageLib`.

## Relation To ArchiveMetadataTable

`ResourceLayoutEntry` and [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md) describe closely related EPF/EPD record shapes. `ArchiveMetadataTable` is used by broader image-library helpers such as `LoadImageFrameTable_004D0F50`; `ResourceLayoutEntry` is the narrower table row stored in `ResourceLayoutTable`/`ImageLib` buckets behind `g_pEPFLib`.

## Cross-References

- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:000174][0x004d0120-0x004d182e.ResourceLayoutTable](by-memory/0x004d0120-0x004d182e.ResourceLayoutTable.md)
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)

## Changes

- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 confirmed the 24-byte row allocation, sentinel pattern, and lookup semantics through `sub_4D0120` and `sub_4D1600`. The score remains below 95 because final type name, owner file, and related table/entry pages still need a full audit.
- 2026-06-03 update: live IDA MCP rechecked the loader, lookup, copy, rectangle, raw-table helper, and `ImageLib` constructor/global evidence. Completion increased from 70 to 84 and confidence from 85 to 90 because the row layout, raw read order, absolute-offset rebasing, sentinel boundary, `EPFTileContext` mapping, helper copy semantics, and `ImageLib` parent assignment are now directly documented from current IDA output. The score remains below 95 because the exact original type name and final source declaration are still not proven.
