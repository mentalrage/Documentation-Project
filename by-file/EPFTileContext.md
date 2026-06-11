*** UID:0000J4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# EPFTileContext

## Status

- Confidence: strong for source-file ownership, method boundaries, caller/callee evidence, and direct class parent routing; medium-high for final field names.
- Proposed module: `render/EPFTileContext.cpp`
- Evidence basis: live IDA MCP and Hex-Rays review of EPFTileContext boundaries, bodies, callers, and callees through 2026-06-04.

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
| `0x00457a60-0x00457aa4` | `InitTileContext` | Initializes the context header, null buffers, zero bounds, and no encoded mask. |
| `0x00457ab0-0x00457c53` | `BuildRleMask8` | Builds a row-wise transparency mask from byte pixels. |
| `0x00457c60-0x00457df2` | `BuildRleMask16` | Builds the same transparency mask from word pixels. |
| `0x00457e00-0x00457f2b` | `CopyTo` | Releases the destination context and deep-copies pixel, auxiliary, and mask buffers. |
| `0x00457f30-0x00457fe9` | raw 16-bit copy body | IDA-typed code without a function object or direct start xrefs; releases the destination argument and deep-copies word-sized buffers. |
| `0x00457ff0-0x00458253` | `CreateHalfScaleCopy` | Allocates a new context and samples every other source pixel/row into a half-size output. |
| `0x00458260-0x004583c8` | `CreateHalfScaleWordCopy` | Similar word-pixel half-size copy helper; no direct live callers. |
| `0x004583d0-0x00458423` | `AllocateBytePixels` | Releases existing buffers and allocates a zero-origin byte-pixel primary buffer. |
| `0x00458430-0x00458485` | `AllocateWordPixels` | Releases existing buffers and allocates a zero-origin word-pixel primary buffer. |
| `0x00458490-0x004584fa` | `AllocateWordPixelsWithAux` | Releases existing buffers and allocates zero-origin primary and auxiliary word-pixel buffers. |
| `0x00458500-0x00458557` | `ReleaseBuffers` | Frees pixel, auxiliary, and encoded-mask buffers. |
| `0x00458560-0x00458585` | [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md) | Post-decode pixel-format normalization helper called by shared image loaders. |
| `0x00458590-0x00458610` | [UID:000201][0x00458590-0x00458610.EPFTileContextPixelRangeTest](by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md) | Byte-pixel range scan helper used by raw image-library/light-generation code. |

## Layout

Live body access consistently uses a 0x28-byte layout:

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

- Live IDA MCP confirms the exact input identity recorded in [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md), the aggregate start at `0x00457a60`, and the half-open end at `0x00458610`.
- Live function inventory confirms all defined starts and ranges listed above, plus the code-typed raw body at `0x00457f30-0x00457fe9`.
- Live boundary bytes confirm `0xcc` alignment between all neighboring function/body ranges.
- Live caller checks show `CopyTo` is called by [UID:0002KR][0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext](by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md) at `0x004d050a` and pane/effect copy paths at `0x004ff226` and `0x004ff5e6`.
- Live caller checks show the allocation helpers are used by shared image decode wrappers: `0x004d0a16` for byte pixels, `0x004d06c8`/`0x004d076d`/`0x004d08ad`/`0x004d0b65` for word pixels, and `0x004d0c9e`/`0x004d0e34` for word-plus-auxiliary buffers.
- Live caller checks show `ReleaseBuffers` has 71 direct call sites across controls, image loaders, render support, copy helpers, and cleanup paths, supporting a shared render support owner.

## Dependencies

- Consumed by [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md), [UID:0000K2][ImageLib](by-file/ImageLib.md), [UID:0000JH][FontImageLib](by-file/FontImageLib.md), [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md), and several pane/effect rendering paths.
- Uses project memory allocation/free helpers for pixel and mask buffers.
- Receives frame bounds and payload pointers from EPF/EPD metadata loaders such as [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) and the `ResourceLayoutTable` registry.

## Open Questions

- Confirm the original names for `pixelMode`, `auxiliaryData`, and encoded-mask fields.
- Identify all producers of `auxiliaryData`; the copy/release logic treats it as pixel-buffer-sized data.
- Confirm which draw paths consume the encoded mask directly versus rebuilding it on demand.

## Corrected Parent Gate Audit

- Current file-root score after Batch 102: `COMPLETION:89`, `CONFIDENCE:86`.
- Direct child now eligible: [UID:00004I][EPFTileContext](by-class/EPFTileContext.md), refreshed to `85/86`.
- Assignment basis: `render/EPFTileContext.cpp` is the direct source root for the decoded tile/image context because the aggregate owns buffer lifecycle, RLE mask construction, deep copy, half-scale helpers, allocation/reset helpers, post-decode normalization, and pixel-range tests consumed by resource layout, image loaders, controls, font rendering, and pane/effect paths.
- Remaining caveat: field names such as `pixelMode`, `auxiliaryData`, and encoded-mask fields are still working names, so no final C++ is emitted.

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

### 2026-06-04 - Live aggregate inventory correction

- Before: the file page listed seven EPFTileContext methods and did not account for the middle copy, decimation, and allocation helpers inside `0x00457f30-0x004584fa`.
- Changed to: replaced the stale evidence basis with live IDA/Hex-Rays evidence and expanded the method table to include the raw copy body, two decimation helpers, and three allocation/reset helpers.
- Summary/evidence: [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md) records the exact function/body inventory, padding, caller/callee evidence, and behavior. File metadata is unchanged because this page already had high file-level completion and final names remain provisional.

### 2026-06-08 - Batch 102 parent-gate refresh

- Before: `COMPLETION:88`, `CONFIDENCE:84`; the file page had the full aggregate inventory but was just below the corrected `85` confidence gate for retaining class routing under the stricter rule.
- Changed to: `COMPLETION:89`, `CONFIDENCE:86`.
- Summary/evidence: the page now explicitly records the parent-gate basis for [UID:00004I][EPFTileContext](by-class/EPFTileContext.md), tying the full method/body inventory, broad caller/callee evidence, render-support ownership, and dependency boundaries to `NexusTK/render/EPFTileContext.cpp` while retaining final field-name caveats and blank C++.

### 2026-06-02 - Projected render path

- Before: the page text proposed `render/EPFTileContext.cpp`, but `PROPOSED_RECONSTRUCTION_PATH` was blank.
- Changed to: set `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.
- Summary/evidence: the file role and dependencies already place `EPFTileContext` as render/image support, downstream of EPF/EPD payload lookup and upstream of pane/image-library drawing.

### 2026-05-27 - Added EPFTileContext tail helpers

- Before: the proposed module listed a five-method EPFTileContext coverage shape and an aggregate ending before `0x00458610`.
- Changed to: expanded the aggregate to `0x00457a60-0x00458610` and added the post-decode normalization and pixel-range query helpers.
- Summary/evidence: IDA MCP confirms exact helper boundaries at `0x00458560-0x00458585` and `0x00458590-0x00458610`; callers tie the first to shared image decode wrappers and the second to raw image-library/light-generation code.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:84`.
  - Summary/evidence: render-support role, complete method table, compact layout, IDA evidence, dependencies, open field-name questions, tail helper corrections, and cross-references are documented; confidence is strong with only final field names and auxiliary-data producer coverage still open.
