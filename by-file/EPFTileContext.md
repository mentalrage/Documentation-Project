*** UID:0000J4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# EPFTileContext

## Status

- Confidence: strong for source-file ownership and method boundaries, medium for final field names.
- Proposed module: `render/EPFTileContext.cpp`
- Current recovered source: `source-3/simroot_v2/class_EPFTileContext.cpp`
- Evidence basis: Wave3 class summary and missing-ref check, generated `simroot_v2` source, existing memory docs, and IDA MCP boundary/caller checks on 2026-05-23.

## File Role

`EPFTileContext` is a small render/image support class that carries decoded EPF/EPD frame pixels, optional auxiliary pixels, bounds, row stride, and an encoded transparency mask. It sits below image-library and UI pane rendering code, but above raw DAT archive parsing.

This should be its own render support file rather than part of `DATFile.cpp`, `DATFileMgr.cpp`, or any one asset-specific image library. Callers across resource layout, controls, font rendering, and pane/effect paths use the same context shape.

## Proposed Contents

| Entity | Range | Proposed placement | Notes |
| --- | --- | --- | --- |
| [UID:00004I][EPFTileContext](by-class/EPFTileContext.md) | `0x00457a60-0x00458610` aggregate over child methods/helpers | `render/EPFTileContext.cpp` | Decoded frame context, RLE mask cache, post-decode pixel normalization, pixel range queries, and buffer lifecycle. |

## Methods

IDA MCP confirms these exact function starts and half-open ranges:

| Range | Method | Role |
| --- | --- | --- |
| `0x00457a60-0x00457aa4` | `InitTileContext` | Initializes 8-bit mode, null buffers, zero bounds, and no encoded mask. |
| `0x00457ab0-0x00457c53` | `BuildRleMask8` | Builds a row-wise transparency mask from 8-bit/indexed pixels. |
| `0x00457c60-0x00457df2` | `BuildRleMask16` | Builds the same transparency mask from 16-bit pixels. |
| `0x00457e00-0x00457f2b` | `CopyTo` | Releases the destination context and deep-copies pixel, auxiliary, and mask buffers. |
| `0x00458500-0x00458557` | `ReleaseBuffers` | Frees pixel, auxiliary, and encoded-mask buffers. |
| `0x00458560-0x00458585` | [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md) | Post-decode pixel-format normalization helper called by shared image loaders. |
| `0x00458590-0x00458610` | [UID:000201][0x00458590-0x00458610.EPFTileContextPixelRangeTest](by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md) | Byte-pixel range scan helper used by raw image-library/light-generation code. |

## Layout

Current generated code consistently uses a 0x28-byte layout:

```text
0x00  int pixelMode
0x04  void* pixelData
0x08  void* auxiliaryData
0x0c  int rowStride
0x10  int bounds.left
0x14  int bounds.top
0x18  int bounds.right
0x1c  int bounds.bottom
0x20  int encodedMaskSize
0x24  unsigned char* encodedMaskData
```

`pixelMode == 1` follows the 8-bit/indexed path. `pixelMode == 0` routes mask building to the 16-bit path.

## Evidence

- Wave3 `show class EPFTileContext --summary` reports manual grade `95.8`, auto grade `96.0`, five methods, no memory conflicts, and aggregate coverage; IDA adds two tail helpers that active generated output has not modeled yet.
- Wave3 `list missing-ref --class EPFTileContext --limit 25` returns zero entries.
- IDA MCP confirms all seven method/helper starts and ranges listed above.
- IDA MCP caller checks show `EPFTileContext::CopyTo` is called by `ResourceLayoutTable::CopyEntryTileContext` at `0x004d04d0` and pane/effect copy paths at `0x004ff040` and `0x004ff400`.
- IDA MCP caller checks show `ReleaseBuffers` has broad fan-in from controls, font/image loaders, render support, and pane/effect cleanup paths, supporting a shared render support owner.

## Dependencies

- Consumed by [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md), [UID:0000K2][ImageLib](by-file/ImageLib.md), [UID:0000JH][FontImageLib](by-file/FontImageLib.md), [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md), and several pane/effect rendering paths.
- Uses project memory allocation/free helpers for pixel and mask buffers.
- Receives frame bounds and payload pointers from EPF/EPD metadata loaders such as [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) and the `ResourceLayoutTable` registry.

## Open Questions

- Confirm the original names for `pixelMode`, `auxiliaryData`, and encoded-mask fields.
- Identify all producers of `auxiliaryData`; the copy/release logic treats it as pixel-buffer-sized data.
- Confirm which draw paths consume the encoded mask directly versus rebuilding it on demand.

## Cross-References

- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md)
- [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md)
- [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md)
- [UID:000201][0x00458590-0x00458610.EPFTileContextPixelRangeTest](by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

### 2026-06-02 - Projected render path

- Before: the page text proposed `render/EPFTileContext.cpp`, but `PROPOSED_RECONSTRUCTION_PATH` was blank.
- Changed to: set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.
- Summary/evidence: the file role and dependencies already place `EPFTileContext` as render/image support, downstream of EPF/EPD payload lookup and upstream of pane/image-library drawing.

### 2026-05-27 - Added EPFTileContext tail helpers

- Before: the proposed module listed the generated five-method EPFTileContext coverage and an aggregate ending before `0x00458610`.
- Changed to: expanded the aggregate to `0x00457a60-0x00458610` and added the post-decode normalization and pixel-range query helpers.
- Summary/evidence: IDA MCP confirms exact helper boundaries at `0x00458560-0x00458585` and `0x00458590-0x00458610`; callers tie the first to shared image decode wrappers and the second to raw image-library/light-generation code.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:84`.
  - Summary/evidence: render-support role, complete method table, compact layout, IDA evidence, dependencies, open field-name questions, tail helper corrections, and cross-references are documented; confidence is strong with only final field names and auxiliary-data producer coverage still open.
