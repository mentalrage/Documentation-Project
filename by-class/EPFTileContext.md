*** UID:00004I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EPFTileContext

## Status

- Confidence: strong for behavior and local layout, medium for final field names.
- Current Wave3 file: `class_EPFTileContext.cpp`
- Likely source module: [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md)
- Current relevant range: `0x00457a60-0x00458610`
- Main address doc: [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md)

## Responsibility

`EPFTileContext` is a decoded image/tile context used by rendering and UI code. It owns or references decoded pixel buffers, optional auxiliary pixel data, bounds, row stride, and a cached run-length mask used by drawing code.

## Inferred Layout

Wave3 has no formal fields for this class yet, but generated code consistently uses this layout:

```text
EPFTileContext
  +0x00  int pixelMode        // 1 = 8-bit/indexed path; 0 routes mask building to 16-bit path
  +0x04  void* pixelData
  +0x08  void* auxiliaryData
  +0x0c  int rowStride
  +0x10  int bounds.left
  +0x14  int bounds.top
  +0x18  int bounds.right
  +0x1c  int bounds.bottom
  +0x20  int encodedMaskSize
  +0x24  uint8_t* encodedMaskData
```

This implies a 0x28-byte context. Field names are working names until the class layout is formally imported.

## Methods

| Address | Name | Notes |
| --- | --- | --- |
| `0x00457a60` | `InitTileContext` | Initializes 8-bit mode, null buffers, zero bounds, and no mask. |
| `0x00457ab0` | `BuildRleMask8` | Builds a row-wise transparency mask from 8-bit pixels; nonzero runs are stored with the high bit set. |
| `0x00457c60` | `BuildRleMask16` | Same mask encoding for 16-bit pixels. |
| `0x00457e00` | `CopyTo` | Releases destination buffers, copies layout fields, and deep-copies pixel/aux/mask buffers. |
| `0x00458500` | `ReleaseBuffers` | Frees pixel, auxiliary, and encoded-mask buffers. |
| `0x00458560` | `NormalizePostDecodePixels` | Applies the compatibility pixel transform to decoded 16-bit buffers when the surface pixel-format flag requires it. |
| `0x00458590` | `HasPixelInRanges` | Scans byte pixels for any value inside caller-supplied inclusive byte ranges. |

## Ownership Notes

- This class should live with render/image support, not DAT parsing.
- EPF/EPD table loaders produce bounds and payload offsets; `EPFTileContext` holds decoded pixels and masks after payload interpretation.
- Consumers include frame, minimap, dialog, and image-control rendering paths.

## Open Questions

- Confirm whether `pixelMode == 0` always means 16-bit RGB565 and `pixelMode == 1` always means 8-bit indexed pixels.
- Identify which loader populates `auxiliaryData`; current mask helpers treat it like a second pixel-sized buffer.
- Confirm whether encoded masks are consumed by old rendering, new rendering, or both.

## Cross-References

- [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)
- [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md)
- [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md)
- [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md)
- [UID:000201][0x00458590-0x00458610.EPFTileContextPixelRangeTest](by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md)
- [UID:0000UN][EPFArchiveMetadataTable](by-item/EPFArchiveMetadataTable.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)

## Changes

- 2026-06-02:
  - Before: reconstructability and parent were blank despite `80/82` scoring and a high-confidence source-file page.
  - After: marked reconstructable and attached to [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md) with C++ blank.
  - Summary/evidence: existing docs establish the render-support file owner and seven-method context shape, but final field names and source-quality declarations remain below the C++ emission threshold.

### 2026-05-27 - Added IDA-confirmed tail helpers

- Before: the class page used the generated/Wave3 range `0x00457a60-0x00458556` and listed only five generated methods.
- Changed to: expanded the relevant range to `0x00457a60-0x00458610` and added the two exact tail helpers at `0x00458560` and `0x00458590`.
- Summary/evidence: IDA MCP confirms the first helper is called by image decode wrappers after filling decoded pixels, and the second scans decoded byte pixels from raw image-library/light-generation code before the RankingDialog start at `0x00458610`.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `80/82`.
  - Summary/evidence: decoded tile-context responsibility, inferred layout, mask/copy/release/normalize/range-test methods, ownership notes, open questions, and corrected tail helpers are documented; remaining uncertainty is final field names and some pixel-mode semantics.
