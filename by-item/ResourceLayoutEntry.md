*** UID:0000VB | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ResourceLayoutEntry

## Status

- Confidence: strong for in-memory field order, medium for original type name.
- Entity kind: EPF/EPD frame record used by `ResourceLayoutTable`.
- Likely source file: [UID:0000K2][ImageLib](by-file/ImageLib.md) or [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- Rebuild handling: `source-authored`/`source-declared` resource-layout data structure. The type needs to be reconstructed, but parent attachment and C++ declaration are blank until the surrounding resource table pages and naming are 95% audited.

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

Rechecked on 2026-05-31:

- `ResourceLayoutTable` loader neighborhood includes `sub_4D0120` at `0x004d0120-0x004d02e4` inclusive (IDA exclusive end `0x004d02e5`), plus table lookup/helper functions through `0x004d182e`.
- `sub_4D0120` allocates `24 * (entryCount + 1)` bytes, matching a 24-byte `ResourceLayoutEntry` row plus sentinel.
- `sub_4D0120` reads a raw record order consistent with 16-bit bounds and 32-bit payload/mask offsets, then stores converted fields into the allocated 24-byte rows.
- `sub_4D1600` maps a selected row into an output tile/frame context: it copies payload offset, computes stride from `right - left`, copies a 16-byte bounds block, copies encoded-mask offset, and derives encoded-mask size from the next row's pixel-data boundary. This directly confirms the next-row/sentinel boundary semantics.

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
