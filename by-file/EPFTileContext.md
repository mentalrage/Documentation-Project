*** UID:0000J4 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# EPFTileContext

## 2026-08-17 Whole-File Source Completion

This file is the sole source root for the complete `NexusTK/render/EPFTileContext.cpp` compilation unit and its required sibling header. [UID:00004I][EPFTileContext](by-class/EPFTileContext.md) remains the class owner/emitter, [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md) emits the eleven leading definitions at position `0`, and exact tail children [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md) and [UID:000201][0x00458590-0x00458610.EPFTileContextPixelRangeTest](by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md) emit at positions `10` and `20`.

The exact authored inventory is thirteen bodies in `[0x00457a60,0x00458610)`: default constructor, indexed and RGB16 encoded-mask builders, generic and retained RGB16 deep-copy methods, generic and retained RGB16 half-scale methods, three allocation methods, explicit `ReleaseBuffers`, post-decode normalization, and the indexed-palette range query. Twelve internal intervals are all-`0xcc` alignment. Two associated EH code chunks and four EH data records are compiler-covered and emit no authored source. The predecessor ending at `0x00457a5d`, its three-byte alignment, and RankingDialog successor beginning at `0x00458610` are excluded.

`0x00457a60` is `EPFTileContext::EPFTileContext()`, not an ordinary `Initialize()` method. It initializes all seven fields and returns `this`; 337 construction xrefs include automatic, member, array, and new-expression sites. No authored destructor exists. `ReleaseBuffers` remains explicit because many borrowed/local contexts leave scope without freeing resource-owned pixel storage; inventing a destructor would change ownership behavior.

The retained zero-xref bodies are authored specializations preserved after compiler inlining: `0x00457f30` mirrors the RGB16 branch of `CopyTo`, while `0x00458260` mirrors the RGB16 branch of `CreateHalfScaleCopy`. The RGB16 half-scale path intentionally leaves the new object's constructor-default `Indexed8` format unchanged. Mask source preserves the fixed 100000-byte stack scratch, 127-byte run cap, high-bit draw-run flag, row terminators, exact signed dimension arithmetic, and absence of added guards.

Required header dependencies are `RectBounds.h`, `Palette.h`, `SoftwareBlend16.h`, `Surface.h`, and `MemoryMan.h`. [UID:00015T][0x004b7ca0-0x004b7cb6.RectArea](by-memory/0x004b7ca0-0x004b7cb6.RectArea.md), [UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md), and [UID:00029U][0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags](by-memory/0x0069b3d4-0x0069b3d8.SurfacePixelFormatFlags.md) provide the missing declarations. No file-owned globals, statics, constants, strings, tables, vtables, RTTI, resources, imports, or third-party source are present.

The prior twelve-body count, ordinary-`Initialize` identity, blank aggregate, and retained/no-route blockers are superseded by this completed inventory and formal source. Completion/confidence are `94/94`: behavior, boundaries, ownership, source order, declarations, and generated topology are complete; only unrecoverable original private-helper spellings remain descriptive.

## UID0000KA Render-Context Consumer - 2026-08-15

Legacy and Pane2 paint methods allocate local `EPFTileContext` objects whose default constructor initializes them, receive image entries through `ImageLib::CopyEntryTileContext`, and pass the contexts and their exact bounds to inherited `RenderTileFrame`. This file retains the complete type declaration and layout; InventoryPane defines no EpfFrame proxy, loader wrapper, or context storage.

## 2026-08-14 B003 ChangePassword Dependency Incorporation

- UID00004I now emits a guarded H with RectBounds, enum, struct, storage, and method declarations, and its CPP begins with `#include "EPFTileContext.h"` before children.
- DialogPane requires the complete by-value type; ChangePasswordDialogPane consumes that base transitively. Ownership, body routing, and file scores remain with EPFTileContext rather than the password-dialog unit.

## Status

- Confidence: strong for source-file ownership, method boundaries, caller/callee evidence, direct class parent routing, and source-facing field roles; medium-high for exact original spellings and retained helper policy.
- Proposed module: `render/EPFTileContext.cpp`
- Evidence basis: live IDA MCP and Hex-Rays review of EPFTileContext boundaries, bodies, callers, and callees through 2026-06-04.

## File Role

`EPFTileContext` is a small render/image support class that carries decoded EPF/EPD frame pixels, an optional PNG-produced alpha plane, bounds, logical row stride, and an encoded transparency mask. Its indexed-pixel range query consumes typed inclusive `DLPaletteRange` records from `DLPalette` through the narrow friendship declared in `Palette.h`. It sits below image-library and UI pane rendering code, but above raw DAT archive parsing; palette storage remains Palette-owned.

This should be its own render support file rather than part of `DATFile.cpp`, `DATFileMgr.cpp`, or any one asset-specific image library. Callers across resource layout, controls, font rendering, and pane/effect paths use the same context shape.

## Proposed Contents

| Entity | Range | Proposed placement | Notes |
| --- | --- | --- | --- |
| [UID:00004I][EPFTileContext](by-class/EPFTileContext.md) | `0x00457a60-0x00458610` aggregate over child methods/helpers | `render/EPFTileContext.cpp` | Decoded frame context, encoded-mask cache, post-decode pixel normalization, pixel range queries, and buffer lifecycle. Declaration-level enum/layout C++ is ready on the class page; full method bodies remain exact-child work. |

## Methods

IDA MCP confirms these exact function starts and half-open ranges:

| Range | Method | Role |
| --- | --- | --- |
| `0x00457a60-0x00457aa4` | `EPFTileContext::EPFTileContext` | Default constructor initializes the context header, null buffers, zero bounds, and no encoded mask. |
| `0x00457ab0-0x00457c53` | `BuildEncodedMask` / `BuildRleMask8` | Builds a row-wise transparency mask from indexed/byte pixels and dispatches to the word helper when `pixelFormat == kEPFTilePixelFormatRgb16`. |
| `0x00457c60-0x00457df2` | `BuildEncodedMask16` / `BuildRleMask16` | Builds the same transparency mask from word pixels. |
| `0x00457e00-0x00457f2b` | `CopyTo` | Releases the destination context and deep-copies pixel, auxiliary, and mask buffers. |
| `0x00457f30-0x00457fe9` | raw 16-bit copy body | IDA-typed code without a function object or direct start xrefs; releases the destination argument and deep-copies word-sized buffers. |
| `0x00457ff0-0x00458253` | `CreateHalfScaleCopy` | Allocates a new context and samples every other source pixel/row into a half-size output. |
| `0x00458260-0x004583c8` | `CreateHalfScaleWordCopy` | Similar word-pixel half-size copy helper; no direct live callers. |
| `0x004583d0-0x00458423` | `AllocateIndexed8Pixels` / `AllocateBytePixels` | Releases existing buffers, sets `pixelFormat` to indexed8, and allocates a zero-origin byte-pixel primary buffer. |
| `0x00458430-0x00458485` | `AllocateRgb16Pixels` / `AllocateWordPixels` | Releases existing buffers, sets `pixelFormat` to RGB16/word pixels, and allocates a zero-origin word-pixel primary buffer. |
| `0x00458490-0x004584fa` | `AllocateRgb16PixelsWithAlpha` / `AllocateWordPixelsWithAux` | Releases existing buffers, sets `pixelFormat` to RGB16/word pixels, and allocates zero-origin primary and alpha word-pixel planes. |
| `0x00458500-0x00458557` | `ReleaseBuffers` | Frees pixel, auxiliary, and encoded-mask buffers. |
| `0x00458560-0x00458585` | [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md) | First-draft-ready post-decode pixel-format normalization method; gates [UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md) on `g_surfaceUsesRgb565Pixels` / raw `byte_69B3D5`. |
| `0x00458590-0x00458610` | [UID:000201][0x00458590-0x00458610.EPFTileContextPixelRangeTest](by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md) | `ContainsIndexedPixelInRanges(const DLPalette *palette) const`; first-draft-ready byte-pixel scan over typed inclusive `DLPaletteRange` records, used by raw ItemObjImageLib code after `PaletteLib::GetSlotPalette(10, itemInfo.paletteSlot, 0)`. |

## Layout

Live body access consistently uses a 0x28-byte layout:

```text
0x00  EPFTilePixelFormat pixelFormat   // 0 = 16-bit word/RGB16 pixels; 1 = indexed8 pixels
0x04  void* pixelData
0x08  unsigned short* alphaData        // raw-history alias: auxiliaryData
0x0c  int rowStridePixels
0x10  int bounds.left
0x14  int bounds.top
0x18  int bounds.right
0x1c  int bounds.bottom
0x20  int encodedMaskByteCount
0x24  unsigned char* encodedMaskBytes  // raw resource-row alias: encodedMaskData
```

`pixelFormat == kEPFTilePixelFormatIndexed8` follows the byte/indexed path. `pixelFormat == kEPFTilePixelFormatRgb16` follows the 16-bit word path; do not name that value `RGB565` unconditionally because post-decode normalization may convert decoded RGB565-like pixels to RGB555 for the compat Surface family.

## Source-Quality Resolution

B004's 2026-06-19 Rule 26 pass keeps this source root unchanged at `NexusTK/render/EPFTileContext.cpp` and closes the prior field-name questions for file-level routing:

- `pixelFormat` is the preferred field name over `pixelMode`: allocator helpers, mask builders, and [UID:000201][0x00458590-0x00458610.EPFTileContextPixelRangeTest](by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md) prove a two-state pixel-storage selector rather than a render-mode flag.
- `alphaData` is the preferred source-facing name for `+0x08`. [UID:00032P][0x004d0c60-0x004d0d89.DecodePngFileToTileContext](by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md) and [UID:00032O][0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext](by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md) allocate it with `AllocateRgb16PixelsWithAlpha` and store alpha-derived 16-bit values there. Keep `auxiliaryData` only as a raw alias in older support docs.
- `encodedMaskByteCount` and `encodedMaskBytes` are the preferred context field names. ResourceLayout rows still speak in terms of `encodedMaskData`, but the context owns a byte-count plus byte-stream cache.
- Encoded masks are shared render data, not old-rendering-only data. ResourceLayout can supply preencoded row masks, `BuildEncodedMask` can create them from decoded pixels, [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot `dword_69B3E8` routes both compat/RGB555 and RGB565 callback targets that handle masked/transparent spans, and [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md) consumes the same signed-run stream from source field `+0x24`.
- [UID:0002TG][0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback](by-memory/0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md) is an exact scaled-tint consumer of `encodedMaskBytes` at `+0x24`. It interprets the bytes as signed zero-delimited rows: zero ends a row, negative tokens identify destination spans to transform, positive tokens skip spans, and `token & 0x7f` supplies the length. It does not read `pixelData` for source color/intensity and does not consult `encodedMaskByteCount`; those negative facts are part of the exact callback behavior, not evidence that the context fields are unused.
- The class page emits the complete enum/layout/API declaration and exact include preamble with `[[CHILDREN]]`. UID0000XY emits all eleven leading definitions, including the retained RGB16 helpers; UID000200 and UID000201 emit the two accepted exact tail methods.
- `EPFTileContext.cpp` includes or otherwise receives the complete Palette declaration through `Palette.h` for UID000201's body. `EPFTileContext.h` needs only `struct DLPalette;` because the public method accepts a pointer. The complete `DLPaletteRange` record and `friend struct EPFTileContext` declaration belong in `Palette.h`, avoiding public palette fields, invented accessors, or duplicate range types.

## Evidence

- Live IDA MCP confirms the exact input identity recorded in [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md), the aggregate start at `0x00457a60`, and the half-open end at `0x00458610`.
- Live function inventory confirms all defined starts and ranges listed above, plus the code-typed raw body at `0x00457f30-0x00457fe9`.
- Live boundary bytes confirm `0xcc` alignment between all neighboring function/body ranges.
- Live caller checks show `CopyTo` is called by [UID:0002KR][0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext](by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md) at `0x004d050a` and pane/effect copy paths at `0x004ff226` and `0x004ff5e6`.
- Live caller checks show the allocation helpers are used by shared image decode wrappers: `0x004d0a16` for byte/indexed pixels in [UID:0002TM][0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext](by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md), `0x004d06c8`/`0x004d076d`/`0x004d08ad`/`0x004d0b65` for word pixels, and `0x004d0c9e`/`0x004d0e34` for word-plus-auxiliary buffers.
- The BMP producer path validates `BM` plus `biBitCount == 8`, maps width to `rowStridePixels`/`bounds.right`, maps `abs(signedHeight)` to `bounds.bottom`, writes indexed byte pixels directly to `pixelData`, and does not call `NormalizePostDecodePixels`.
- Live caller checks show `ReleaseBuffers` has 71 direct call sites across controls, image loaders, render support, copy helpers, and cleanup paths, supporting a shared render support owner.
- B005 2026-06-19 source-quality pass confirms [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md) has exact raw bytes at `0x00458560-0x00458585`, six direct image decode call/tail-call sites, field use limited to `pixelData` and bounds, and first-draft C++ readiness. The only remaining uncertainty for that method is exact original spelling of the Surface flag and conversion helper.
- [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) is a concrete UI consumer of automatic default construction and explicit `ReleaseBuffers` in `ObjectImageControlPane::OnPaint`; the target default-constructs its stack context before status-kind dispatch, returns from the Human and Monster branches without release, and calls `ReleaseBuffers` only inside the Item branch after `DrawItemImage`. This is consumer evidence only and does not change the EPFTileContext source owner.

## Dependencies

- Consumed by [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md), [UID:0000K2][ImageLib](by-file/ImageLib.md), [UID:0000JH][FontImageLib](by-file/FontImageLib.md), [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md), and several pane/effect rendering paths.
- Uses project memory allocation/free helpers for pixel and mask buffers.
- Receives frame bounds and payload pointers from EPF/EPD metadata loaders such as [UID:0000K1][ImageFrameTable](by-file/ImageFrameTable.md) and the `ResourceLayoutTable` registry.
- Depends on [UID:0000MA][Palette](by-file/Palette.md) / `Palette.h` only for read-only access to `DLPalette::m_paletteRanges` and `m_paletteRangeCount` in UID000201. Loader, copy constructor, application method, allocation, and destruction remain Palette/DLPalette behavior, not EPFTileContext source.

## Open Questions

- Exact original spellings for `pixelFormat`, `alphaData`, `encodedMaskByteCount`, and `encodedMaskBytes` remain inferred.
- The former retained/no-route question is closed: all three source-shaped bodies are authored source, with the zero-xref specializations retained because their live public branches contain exact inlined counterparts.
- [UID:000201][0x00458590-0x00458610.EPFTileContextPixelRangeTest](by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md) has its caller-side object, typed two-byte record layout, inclusive endpoint semantics, and friendship mechanism resolved. Only exact original lexical spellings remain a confidence cap.

## Corrected Parent Gate Audit

- Current file-root score: `COMPLETION:94`, `CONFIDENCE:94`.
- Direct child: [UID:00004I][EPFTileContext](by-class/EPFTileContext.md), completed at `94/94` with the exact class CPP/H topology.
- Assignment basis: `render/EPFTileContext.cpp` is the direct source root for the decoded tile/image context because the aggregate owns buffer lifecycle, RLE mask construction, deep copy, half-scale helpers, allocation/reset helpers, post-decode normalization, and pixel-range tests consumed by resource layout, image loaders, controls, font rendering, and pane/effect paths.
- Remaining caveat: declaration-level class C++ is now ready through [UID:00004I][EPFTileContext](by-class/EPFTileContext.md), but complete method-body C++ is not emitted from this file root until exact child pages or retained-helper policy cover the aggregate-only methods.

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

### 2026-08-11 - B008 UID0002TG encoded-mask consumer synchronization

- Kept file metadata, owner/emitter route, path, and formal output unchanged at `89/86`.
- Added the exact UID0002TG use of `encodedMaskBytes`, signed zero-delimited span grammar, destination-only tint behavior, and absence of source `pixelData`/`encodedMaskByteCount` reads.

### 2026-08-04 - B002 UID0004HV Palette dependency synchronization

- Score, path, source-file ownership, method ranges, and retained-helper policy remain unchanged at `89/86`.
- Updated UID000201 and dependencies to typed inclusive `DLPaletteRange` records, documented the `Palette.h` complete-type/friend relationship, and preserved DLPalette ownership of storage/copy/load/application behavior.
- Historical ByteRangeSet and entry-move wording remains in dated evidence only; no duplicate range declaration or standalone palette helper was added here.

### 2026-06-04 - Live aggregate inventory correction

- Before: the file page listed seven EPFTileContext methods and did not account for the middle copy, decimation, and allocation helpers inside `0x00457f30-0x004584fa`.
- Changed to: replaced the stale evidence basis with live IDA/Hex-Rays evidence and expanded the method table to include the raw copy body, two decimation helpers, and three allocation/reset helpers.
- Summary/evidence: [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md) records the exact function/body inventory, padding, caller/callee evidence, and behavior. File metadata is unchanged because this page already had high file-level completion and final names remain provisional.

### 2026-06-08 - Batch 102 parent-gate refresh

- Before: `COMPLETION:88`, `CONFIDENCE:84`; the file page had the full aggregate inventory but was just below the corrected `85` confidence gate for retaining class routing under the stricter rule.
- Changed to: `COMPLETION:89`, `CONFIDENCE:86`.
- Summary/evidence: the page now explicitly records the parent-gate basis for [UID:00004I][EPFTileContext](by-class/EPFTileContext.md), tying the full method/body inventory, broad caller/callee evidence, render-support ownership, and dependency boundaries to `NexusTK/render/EPFTileContext.cpp` while retaining final field-name caveats and blank C++.

### 2026-06-19 - NormalizePostDecodePixels source-quality update

- Score unchanged.
- Summary/evidence: [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md) now emits first-draft C++ in this file's route using [UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md) and descriptive `g_surfaceUsesRgb565Pixels`. Broader file-level C++ remains incomplete because other EPFTileContext methods still need final field/source-name passes.

### 2026-06-20 - B004 Rule 26 source-quality sync

- Score unchanged.
- Summary/evidence: B004 reanalysis keeps `NexusTK/render/EPFTileContext.cpp` as the owner/emitter, rejects ImageLoaders/ResourceLayoutTable/FontImageLib/Surface/GrafPort/UI feature ownership, resolves `pixelFormat`, `alphaData`, `rowStridePixels`, `encodedMaskByteCount`, and `encodedMaskBytes` as source-facing field names, and closes the encoded-mask consumer question across ResourceLayout, Surface callback slot `dword_69B3E8`, compat/RGB555 and RGB565 sprite callbacks, and alpha-mask overlays. Declaration C++ now lives on [UID:00004I][EPFTileContext](by-class/EPFTileContext.md); aggregate method bodies remain child/split work.

### 2026-06-21 - B007 BMP indexed producer sync

- Score unchanged.
- Summary/evidence: [UID:0002TM][0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext](by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md) now provides first-draft C++ and support evidence for the indexed byte-pixel allocation caller at `0x004d0a16`. This file now records the BMP width/height-to-layout behavior and the no-normalization distinction from 16-bit decode wrappers.

### 2026-06-21 - B008 ObjectImageControlPane support sync

- Score unchanged.
- Historical note: this entry originally used the raw `InitTileContext` label and did not distinguish branch-local release. The accepted source supersedes that wording with automatic default construction and Item-only `ReleaseBuffers`, while preserving EPFTileContext ownership under render support.

### 2026-07-09 - B005 UID000201 implementation sync

- Score unchanged.
- Summary/evidence: [UID:000201][0x00458590-0x00458610.EPFTileContextPixelRangeTest](by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md) now emits `EPFTileContext::ContainsIndexedPixelInRanges(const DLPalette *palette) const` through this file route. Current MCP resolved the old byte-range-record blocker to `DLPalette *` from `PaletteLib::GetSlotPalette(10, itemInfo.paletteSlot, 0)`, with `m_entryMoves`/`m_entryMoveCount` consumed as inclusive indexed-pixel ranges. File-level open questions now keep only exact original spelling and retained/no-route helper policy as blockers.

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
