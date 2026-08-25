*** UID:0000VB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K2 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// ResourceLayoutEntry is declared once in ImageLib.h; no separate CPP definition.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# ResourceLayoutEntry

## Status

- Confidence: strong for in-memory field order, lookup semantics, and owner route; medium-high for final source declaration/type spelling.
- Entity kind: EPF/EPD frame record used by `ResourceLayoutTable`.
- Autogen parent: [UID:0000K2][ImageLib](by-file/ImageLib.md). Live IDA evidence shows the `ResourceLayoutTable` method cluster is a non-virtual layout facet operating through the `ImageLib`/`g_pEPFLib` singleton and its `+0x0c` list.
- Related source file: [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) tracks the method-cluster facet, but `ImageLib` is the stronger autogen owner.
- Rebuild handling: `source-authored`/`source-declared` resource-layout data structure. B011's accepted ImageLib empty-emitter implementation now emits a first-draft `ResourceLayoutEntry` declaration through [UID:0000K2][ImageLib](by-file/ImageLib.md), with the class-backed ResourceLayoutTable methods using it through their [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md) facet route.

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

The owning registry row is [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md), a 44-byte `List` element with a `ResourceLayoutEntry*` at `+0x28`. [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md) is now documented as a non-emitting alias over that same row, not a separate heap object or declaration owner.

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
context.pixelData             = entry.pixelData
context.rowStridePixels       = entry.right - entry.left
context.bounds                = entry bounds
context.encodedMaskBytes      = entry.encodedMaskData
context.encodedMaskByteCount  = nextEntry.pixelData - entry.encodedMaskData
```

The size calculation means the following row, including the sentinel, is a required boundary marker. This is similar to the DAT entry table's next-row boundary pattern, but it belongs to EPF/EPD frame metadata rather than DAT archive records.

B004's EPFTileContext source-quality pass keeps `encodedMaskData` as the resource-row field name/alias but refines the destination context vocabulary to `encodedMaskBytes` at `EPFTileContext+0x24` and `encodedMaskByteCount` at `+0x20`. These fields are the preencoded transparency/run-mask byte stream and byte count, not the PNG alpha plane at `EPFTileContext+0x08`.

## IDA MCP Evidence

Rechecked with live IDA MCP on 2026-06-03:

- Exact function boundaries: `sub_4D0120` is `0x004d0120-0x004d02e5`, `sub_4D02F0` is `0x004d02f0-0x004d039e`, `sub_4D04D0` is `0x004d04d0-0x004d0522`, `sub_4D0530` is `0x004d0530-0x004d059b`, and `sub_4D05A0` is `0x004d05a0-0x004d05e6`.
- `sub_4D0120` constructs and opens a `DATFile`, reads an 8-byte header and a dword record-table offset, seeks to that table, and allocates `24 * (entryCount + 1)` bytes.
- The loader reads each raw row as 16-bit `top`, `left`, `bottom`, `right`, then two dword offsets. It stores the bounds through `sub_4B7C50(row, left, top, right, bottom)`, so the in-memory row order is `left/top/right/bottom`.
- After seeking back to the archive base, `sub_4D0120` calls the data-base helper, adds `base + 0xc` to each row's payload and mask offsets, and appends a sentinel row with zero bounds and both offsets set to `base + 0xc + recordTableOffset`.
- `sub_4D02F0` finds or lazy-loads the resource bucket, validates the entry index, copies row payload data into an `EPFTileContext`-style output, computes `rowStridePixels = right - left`, and computes `encodedMaskByteCount = nextEntry.pixelData - entry.encodedMaskData`.
- `sub_4D04D0` builds a temporary `EPFTileContext`, calls `sub_4D02F0`, and optionally copies the result through the tile-context copy helper.
- `sub_4D0530` finds or lazy-loads the same bucket and copies the selected row's first 16 bytes into a rectangle output; invalid indexes zero the rectangle through `sub_4B7C50`.
- `sub_4D05A0` is the raw-table rectangle helper: if the index is in range it copies the first 16 bytes from `recordBase + 24 * index`; otherwise it zeroes the rectangle.
- Parent evidence: `sub_4CFFB0` initializes the `ImageLib` singleton, writes `g_pEPFLib` at `0x0067a744`, allocates the `+0x0c` list, and the layout methods fetch buckets from that same list. The ResourceLayoutTable naming is therefore a non-virtual facet rather than a stronger autogen owner than `ImageLib`.

2026-06-16 A001 refresh:

- Live IDA MCP `lookup_funcs` reconfirmed the local method/helper starts and sizes: `sub_4D0120` `0x1c5`, `sub_4D02F0` `0xae`, `sub_4D03A0` `0x130`, `sub_4D04D0` `0x52`, `sub_4D0530` `0x6b`, and `sub_4D05A0` `0x46`.
- Live `analyze_component` reconfirmed that `LoadResourceIndex`, `LookupLayoutEntry`, `CopyEntryTileContext`, and `GetEntryRect` form the class/facet path, while `sub_4D03A0` and `sub_4D05A0` are `__stdcall` raw helpers without a `this` receiver.
- Live decompilation of `0x004d0120` reconfirmed the 8-byte header read, 4-byte record-table offset, `24 * (entryCount + 1)` allocation, raw `top/left/bottom/right` plus pixel/mask offset reads, `InitRectBounds`-style rectangle writes through `0x004b7c50`, offset rebasing by `DATFile::GetDataBase() + 0x0c`, sentinel row, 16-wchar key copy, and `List` append.
- Live decompilation of `0x004d02f0` reconfirmed the output mapping: payload pointer from row `+0x10`, row stride `right - left`, copied bounds, encoded-mask byte count as `nextEntry.pixelData - currentEntry.encodedMaskData`, and mask pointer from row `+0x14`. B004 later names the destination context fields as `rowStridePixels`, `encodedMaskByteCount`, and `encodedMaskBytes`.
- Live disassembly/decompilation of `0x004d05a0` reconfirmed a no-callee three-argument helper that reads a 16-bit count, uses a 24-byte stride, copies the first 16 bytes with `movups`, or zeroes the output rectangle. This supports [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) as the raw-helper owner rather than the class-method path.
- Existing resolved-name evidence maps `sub_4B7C50` to `InitRectBounds`, [UID:0002KR][0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext](by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md) to the copy helper, and [UID:0002KT][0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect](by-memory/0x004d05a0-0x004d05e6.ResourceLayoutRawRecordGetEntryRect.md) to the raw record rectangle helper.

## 2026-06-30 Source Declaration

B011's accepted implementation emits this as a 24-byte source-facing frame row:

```cpp
struct ResourceLayoutEntry {
    int left;
    int top;
    int right;
    int bottom;
    unsigned char *pixelData;
    unsigned char *encodedMaskData;
};
```

This declaration is intentionally narrower than the raw EPF/EPD on-disk record. The loader reads raw `top, left, bottom, right, pixelDataOffset, encodedMaskDataOffset`, normalizes the rectangle to `left/top/right/bottom`, and rebases the two offsets to absolute pointers. The sentinel row added by `LoadResourceIndex` uses the same structure and is required by `LookupLayoutEntry` when calculating `encodedMaskByteCount`.

## Source-Quality Checks

- Final type/source declaration: checked the current `ResourceLayoutNameRecord`, `ResourceLayoutBucket`, `ResourceLayoutTable` class/file, `ImageLib`, and exact child memory pages. The `ResourceLayoutEntry` name and field names are descriptive but now source-quality for first-draft code because the row is consistently consumed by the seven emitted ResourceLayoutTable method children.
- Source placement: class-backed methods route through the `ImageLib` singleton/facet, while raw helpers route to the file-level `ResourceLayoutTable` helper grouping. The declaration emits under [UID:0000K2][ImageLib](by-file/ImageLib.md) so the method bodies can share the same row type without claiming a separate `ResourceLayoutTable.cpp` declaration owner.
- Non-emitting aliases: [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md) remains an alias/view over [UID:0001VT][ResourceLayoutNameRecord](by-type/by-struct/ResourceLayoutNameRecord.md), not a duplicate struct declaration.

## 2026-08-16 Declaration Ownership Closure

The exact 24-byte declaration now emits once, before class use, from the formal H channel of [UID:00006E][ImageLib](by-class/ImageLib.md). This item's formal CPP and H channels are intentionally blank so `ImageLib.cpp` cannot acquire a late duplicate definition. The centralized declaration remains four 32-bit bounds scalars followed by `unsigned char *pixelData` and `unsigned char *encodedMaskData`; no `.rect` member exists.

This source-placement change preserves every binary fact: KO normalizes the raw `top/left/bottom/right` order and rebases both offsets; KP and KQ consume the pointers and leading bounds; KT relies only on the compatible raw-record prefix; the sentinel remains one extra 24-byte row; and private [UID:00054V][0x004d1830-0x004d1860.ResourceLayoutTableGetEntry](by-memory/0x004d1830-0x004d1860.ResourceLayoutTableGetEntry.md) indexes the same rows. The historical late CPP declaration is rejected only as a duplicate emission route, not as a layout error.

## Relation To ArchiveMetadataTable

`ResourceLayoutEntry` and [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md) describe closely related EPF/EPD record shapes. `ArchiveMetadataTable` is used by broader image-library helpers such as `LoadImageFrameTable_004D0F50`; `ResourceLayoutEntry` is the narrower table row stored in `ResourceLayoutTable`/`ImageLib` buckets behind `g_pEPFLib`.

## Cross-References

- [UID:00006E][ImageLib](by-class/ImageLib.md)
- [UID:0000BY][ResourceLayoutTable](by-class/ResourceLayoutTable.md)
- [UID:000174][0x004d0120-0x004d1860.ResourceLayoutTable](by-memory/0x004d0120-0x004d1860.ResourceLayoutTable.md)
- [UID:0001VS][ResourceLayoutBucket](by-type/by-struct/ResourceLayoutBucket.md)
- [UID:0001VU][ResourceLayoutStore](by-type/by-struct/ResourceLayoutStore.md)
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)

## Changes

- 2026-08-16 B001 ResourceLayoutTable whole-file implementation: raised `90/92` to `92/94`, moved the sole exact declaration from this item's late CPP channel into UID00006E formal H before class use, and left both local formal channels blank. Preserved all 24-byte layout, raw-read, rebasing, sentinel, lookup, context-mapping, and owner evidence while recording that `ResourceLayoutEntry` has no `.rect` field and must not be emitted twice.

- 2026-06-30 B011 ImageLib empty-emitter implementation:
  - Changed to: `COMPLETION:90`, `CONFIDENCE:92`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:0000K2`, `EMITTER_UIDS:0000K2`.
  - Implemented accepted first-draft `struct ResourceLayoutEntry`, preserving the 24-byte row, normalized `left/top/right/bottom` order, absolute `pixelData` and `encodedMaskData` pointers, loader sentinel behavior, `LookupLayoutEntry` EPFTileContext mapping, and raw-helper compatibility split.
  - The declaration emits under ImageLib as shared support for the ImageLib-owned ResourceLayoutTable class/facet. It does not create a duplicate `ResourceLayoutBucket` declaration.
- What existed before: the page was unevaluated (`COMPLETION:0`, `CONFIDENCE:0`) and had no reconstructable classification.
- What it was changed to: the page is now marked reconstructable with moderate completion and strong confidence, while parent attachment and C++ remain blank.
- Summary and evidence: IDA MCP verification on 2026-05-31 confirmed the 24-byte row allocation, sentinel pattern, and lookup semantics through `sub_4D0120` and `sub_4D1600`. The score remains below 95 because final type name, owner file, and related table/entry pages still need a full audit.
- 2026-06-03 update: live IDA MCP rechecked the loader, lookup, copy, rectangle, raw-table helper, and `ImageLib` constructor/global evidence. Completion increased from 70 to 84 and confidence from 85 to 90 because the row layout, raw read order, absolute-offset rebasing, sentinel boundary, `EPFTileContext` mapping, helper copy semantics, and `ImageLib` parent assignment are now directly documented from current IDA output. The score remains below 95 because the exact original type name and final source declaration are still not proven.
- 2026-06-16 A001 Goal 2 refresh: completion raised from `84` to `86`; confidence stays `90`. Live IDA MCP reconfirmed method/helper boundaries, loader/lookup/raw-helper behavior, and calling-convention split, and support docs now prove `ResourceLayoutNameRecord` as the owning row while treating `ResourceLayoutBucket` as a non-emitting alias. C++ remains blank because final declaration spelling and source-placement policy are still not source-quality.
- 2026-06-20 B004 EPFTileContext support sync: score unchanged. Clarified that row `encodedMaskData` maps to context `encodedMaskBytes` and `encodedMaskByteCount`, while the context's optional `alphaData` plane is produced by PNG decoders and is not this resource-layout row field.
