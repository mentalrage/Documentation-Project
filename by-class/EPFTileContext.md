*** UID:00004I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000J4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# EPFTileContext

## Status

- Confidence: strong for behavior, boundaries, local layout, method inventory, and direct file parent; medium-high for final field names.
- Likely source module: [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md)
- Current relevant range: `0x00457a60-0x00458610`
- Main address doc: [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md)
- Evidence basis: live IDA MCP and Hex-Rays review of the aggregate on 2026-06-04.

## Responsibility

`EPFTileContext` is a decoded image/tile context used by rendering and UI code. It owns or references decoded pixel buffers, optional auxiliary pixel data, bounds, row stride, and a cached run-length mask used by drawing code.

## Inferred Layout

Live EPFTileContext bodies consistently use this compact 0x28-byte layout:

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
| `0x00457a60` | `InitTileContext` | Initializes the context header, zero rectangle, and empty buffers. |
| `0x00457ab0` | `BuildRleMask8` | Builds a row-wise transparency mask from byte pixels; nonzero runs are stored with the high bit set. |
| `0x00457c60` | `BuildRleMask16` | Same mask encoding for word pixels. |
| `0x00457e00` | `CopyTo` | Releases destination buffers, copies layout fields, and deep-copies pixel/aux/mask buffers. |
| `0x00457f30` | raw 16-bit copy body | IDA-typed code with no function object or direct start xrefs; releases the destination argument and deep-copies word-sized buffers. |
| `0x00457ff0` | `CreateHalfScaleCopy` | Allocates a new context and samples every other source pixel/row into a half-size output. |
| `0x00458260` | `CreateHalfScaleWordCopy` | Similar word-pixel half-size copy helper; no direct live callers. |
| `0x004583d0` | `AllocateBytePixels` | Releases current buffers and allocates a zero-origin byte-pixel primary buffer. |
| `0x00458430` | `AllocateWordPixels` | Releases current buffers and allocates a zero-origin word-pixel primary buffer. |
| `0x00458490` | `AllocateWordPixelsWithAux` | Releases current buffers and allocates separate zero-origin primary and auxiliary word-pixel buffers. |
| `0x00458500` | `ReleaseBuffers` | Frees pixel, auxiliary, and encoded-mask buffers. |
| `0x00458560` | `NormalizePostDecodePixels` | Applies the compatibility pixel transform to decoded 16-bit buffers when the surface pixel-format flag requires it. |
| `0x00458590` | `HasPixelInRanges` | Scans byte pixels for any value inside caller-supplied inclusive byte ranges. |

## Ownership Notes

- This class should live with render/image support, not DAT parsing.
- EPF/EPD table loaders produce bounds and payload offsets; `EPFTileContext` holds decoded pixels and masks after payload interpretation.
- Consumers include frame, minimap, dialog, and image-control rendering paths.
- [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md) is a font-specific producer that writes the decoded pixel pointer at `+0x04`, row stride at `+0x0c`, bounds at `+0x10..+0x1c`, and clears mask fields at `+0x20/+0x24` after its caller releases prior buffers.

## Assignment Gate

- Current class score after Batch 102: `COMPLETION:85`, `CONFIDENCE:86`.
- Direct file parent: [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md), refreshed to `89/86`.
- Exact memory child now eligible: [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md), already `86/90`.
- Assignment basis: this class is the direct source/type parent for the aggregate because the memory page's 0x28-byte layout, buffer lifecycle, mask builders, copy/decimation/allocation helpers, post-decode normalization, and range scan all operate on the same EPFTileContext object shape documented here.
- Final C++ remains blank until `pixelMode`, `auxiliaryData`, encoded-mask naming, and any source-level declaration details are final-source quality.

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
- [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md)

## Changes

### 2026-06-04 - Expanded live method inventory

- Before: the method table listed the initializer, two mask builders, copy, release, and two tail helpers only.
- Changed to: added the live middle bodies at `0x00457f30`, `0x00457ff0`, `0x00458260`, `0x004583d0`, `0x00458430`, and `0x00458490`, and replaced stale evidence wording with the live IDA/Hex-Rays basis.
- Summary/evidence: [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md) now records exact boundaries, padding, caller/callee evidence, and behavior for every body in the aggregate. Class metadata is unchanged because final field and method names remain provisional.

### 2026-06-08 - Batch 102 parent-gate refresh

- Before: `COMPLETION:80`, `CONFIDENCE:82`; the class carried the render file parent but was below the corrected child-and-parent `85/85` gate for assigning the full aggregate memory child.
- Changed to: `COMPLETION:85`, `CONFIDENCE:86`; parent remains [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md).
- Summary/evidence: the page now records the full aggregate inventory as class-owned behavior, direct file parent readiness at `89/86`, the exact memory child at `86/90`, FontImageLib producer evidence, shared image-loader allocation callers, and final field-name caveats. This supports routing [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md) to this class while leaving final C++ blank.

- 2026-06-02:
  - Before: reconstructability and parent were blank despite `80/82` scoring and a high-confidence source-file page.
  - After: marked reconstructable and attached to [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md) with C++ blank.
  - Summary/evidence: existing docs establish the render-support file owner and context shape, but final field names and source-quality declarations remain below the C++ emission threshold.

### 2026-05-27 - Added IDA-confirmed tail helpers

- Before: the class page used the older range `0x00457a60-0x00458556` and listed only five modeled methods.
- Changed to: expanded the relevant range to `0x00457a60-0x00458610` and added the two exact tail helpers at `0x00458560` and `0x00458590`.
- Summary/evidence: IDA MCP confirms the first helper is called by image decode wrappers after filling decoded pixels, and the second scans decoded byte pixels from raw image-library/light-generation code before the RankingDialog start at `0x00458610`.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `80/82`.
  - Summary/evidence: decoded tile-context responsibility, inferred layout, mask/copy/release/normalize/range-test methods, ownership notes, open questions, and corrected tail helpers are documented; remaining uncertainty is final field names and some pixel-mode semantics.
- 2026-06-06: Added FontImageLib decode producer evidence.
  - Before: FontImageLib was listed only indirectly through consumers/dependencies.
  - After: ownership notes explicitly record that [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md) writes the pixel pointer, stride, bounds, and mask fields in the same layout.
  - Summary/evidence: live IDA disassembly at `0x004b6290`, `0x004b6296`, `0x004b6299`, and `0x004b62a0`.
