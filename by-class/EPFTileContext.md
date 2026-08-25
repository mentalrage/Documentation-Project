*** UID:00004I | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000J4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000J4 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "EPFTileContext.h"
#include "Palette.h"
#include "SoftwareBlend16.h"
#include "Surface.h"
#include "../util/MemoryMan.h"

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../ui/core/RectBounds.h"

enum EPFTilePixelFormat
{
    kEPFTilePixelFormatRgb16 = 0,
    kEPFTilePixelFormatIndexed8 = 1
};

struct DLPalette;

struct EPFTileContext
{
    EPFTilePixelFormat pixelFormat;
    void *pixelData;
    unsigned short *alphaData;
    int rowStridePixels;
    RectBounds bounds;
    int encodedMaskByteCount;
    unsigned char *encodedMaskBytes;

    EPFTileContext();

    void ReleaseBuffers();
    void BuildEncodedMask();
    void CopyTo(EPFTileContext *destination) const;
    EPFTileContext *CreateHalfScaleCopy() const;
    void AllocateIndexed8Pixels(int width, int height);
    void AllocateRgb16Pixels(int width, int height);
    void AllocateRgb16PixelsWithAlpha(int width, int height);
    void NormalizePostDecodePixels();
    bool ContainsIndexedPixelInRanges(const DLPalette *palette) const;

private:
    void BuildEncodedMask16();
    void CopyRgb16To(EPFTileContext *destination) const;
    EPFTileContext *CreateHalfScaleRgb16Copy() const;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# EPFTileContext

## 2026-08-17 Complete Class And Header Contract

`EPFTileContext` is a non-polymorphic 0x28-byte render value type owned by [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md). Its exact seven fields are the four-byte `EPFTilePixelFormat`, pixel and optional 16-bit alpha pointers, signed row stride, by-value 16-byte `RectBounds`, encoded-mask byte count, and encoded-mask pointer. It has no vtable, RTTI, base class, static data, or authored destructor.

`0x00457a60` is the default constructor. It returns `this`, initializes every field, and has 337 construction xrefs spanning automatic objects, embedded members, arrays, and new-expression paths. The former public `Initialize()` declaration is removed; automatic default construction supplies the observed initialization. `ReleaseBuffers` stays explicit rather than becoming a destructor because borrowed resource contexts must not free their backing storage on ordinary scope exit.

The complete API consists of the constructor, `ReleaseBuffers`, `BuildEncodedMask`, `CopyTo`, `CreateHalfScaleCopy`, three allocation methods, `NormalizePostDecodePixels`, and `ContainsIndexedPixelInRanges`. Private source helpers are `BuildEncodedMask16`, `CopyRgb16To`, and `CreateHalfScaleRgb16Copy`. `DLPalette` remains forward-declared in H and complete only in CPP through `Palette.h`; the by-value bounds member requires `RectBounds.h` directly.

The CPP preamble includes `EPFTileContext.h`, `Palette.h`, `SoftwareBlend16.h`, `Surface.h`, and `../util/MemoryMan.h` before `[[CHILDREN]]`. Child order is aggregate `0`, normalization `10`, and range query `20`. The complete source family has thirteen authored bodies, twelve alignment gaps, and six compiler-only EH items. Completion/confidence are `94/94`; exact private lexical spellings remain the only non-behavioral uncertainty.

## 2026-08-14 B003 Header Route Closure

- CPP now includes `EPFTileContext.h` before its child marker; H is guarded and directly includes RectBounds while preserving the complete enum, DLPalette forward, storage, and method declarations.
- This gives DialogPane a complete by-value tile-context type and keeps UID00004I/UID0000J4 ownership and `88/90` metadata unchanged.

## Status

- Confidence: very strong for behavior, boundaries, local layout, method inventory, and direct file parent; strong for descriptive source-facing field/type names after B004's 2026-06-19 source-quality reanalysis.
- Likely source module: [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md)
- Current relevant range: `0x00457a60-0x00458610`
- Main address doc: [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md)
- Evidence basis: live IDA MCP and Hex-Rays review of the aggregate on 2026-06-04, B005 source-quality support for the post-decode normalization child on 2026-06-19, and B004's 2026-06-19 local PE/reference reanalysis.

## Responsibility

`EPFTileContext` is a decoded image/tile context used by rendering and UI code. It owns or references decoded primary pixel data, an optional PNG-produced 16-bit alpha plane, bounds, a logical-pixel row stride, and cached encoded transparency-mask rows consumed by sprite/tile and alpha-mask drawing code.

## Inferred Layout

Live EPFTileContext bodies consistently use this compact 0x28-byte layout:

```text
EPFTileContext
  +0x00  EPFTilePixelFormat pixelFormat  // 0 = 16-bit word/RGB16 path; 1 = 8-bit indexed/byte path
  +0x04  void* pixelData
  +0x08  unsigned short* alphaData        // optional 16-bit alpha plane; historical alias: auxiliaryData
  +0x0c  int rowStridePixels
  +0x10  int bounds.left
  +0x14  int bounds.top
  +0x18  int bounds.right
  +0x1c  int bounds.bottom
  +0x20  int encodedMaskByteCount
  +0x24  uint8_t* encodedMaskBytes        // historical alias: encodedMaskData
```

This implies a 0x28-byte context. `pixelData`, `bounds`, and `NormalizePostDecodePixels()` are already used by emitted child C++. B004's source-quality pass closes the old `pixelMode`, `auxiliaryData`, and encoded-mask questions to high-probability descriptive names, but exact original member spellings remain below final/perfect confidence.

## Methods

| Address | Name | Notes |
| --- | --- | --- |
| `0x00457a60` | `EPFTileContext::EPFTileContext` | Default constructor for automatic, embedded, array, and allocated instances; initializes `pixelFormat` to indexed8, clears buffers, clears bounds, and clears encoded-mask state. |
| `0x00457ab0` | `BuildEncodedMask` / `BuildTransparencyMask` | Public mask builder. Handles indexed byte pixels and dispatches to the 16-bit helper when `pixelFormat == kEPFTilePixelFormatRgb16`; the old `BuildRleMask8` suffix is only an implementation clue. |
| `0x00457c60` | `BuildEncodedMask16` / `BuildWordEncodedMask` | Private/helper word-pixel mask builder called by the public builder. |
| `0x00457e00` | `CopyTo` | Releases destination buffers, copies layout fields, and deep-copies primary pixels, optional alpha plane, and encoded-mask bytes. |
| `0x00457f30` | retained raw word-copy body | Source-shaped word-copy duplicate with no function object, no rel32 refs, and no absolute refs. Best label is `CopyWordPixelsToRetained`/`CopyWordContextTo`; keep non-emitting until retained-helper policy or reachability is accepted. |
| `0x00457ff0` | `CreateHalfScaleCopy` | Public generic half-scale clone; the zero direct-start xref is consistent with retained source plus inlining, and the body emits through UID0000XY. |
| `0x00458260` | `CreateHalfScaleRgb16Copy` | Private retained RGB16 half-scale specialization; its public branch counterpart proves liveness and UID0000XY emits it. |
| `0x004583d0` | `AllocateIndexed8Pixels` | Releases current buffers, sets `pixelFormat` to indexed8, and allocates a zero-origin byte-pixel primary buffer. |
| `0x00458430` | `AllocateRgb16Pixels` / `AllocateWordPixels` | Releases current buffers, sets `pixelFormat` to RGB16, and allocates a zero-origin 16-bit primary buffer. Avoid naming this strictly RGB565 because post-decode normalization may convert to RGB555. |
| `0x00458490` | `AllocateRgb16PixelsWithAlpha` / `AllocateWordPixelsWithAlpha` | Releases current buffers, sets `pixelFormat` to RGB16, and allocates separate 16-bit primary and alpha planes. |
| `0x00458500` | `ReleaseBuffers` | Frees pixel, auxiliary, and encoded-mask buffers. |
| `0x00458560` | `NormalizePostDecodePixels` | Applies [UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md) to decoded 16-bit buffers when `g_surfaceUsesRgb565Pixels` / raw `byte_69B3D5` shows the active Surface path is not RGB565-capable. |
| `0x00458590` | `ContainsIndexedPixelInRanges` | Scans indexed byte pixels for any value inside typed inclusive `DLPaletteRange` records from the `DLPalette *` returned by `PaletteLib::GetSlotPalette(10, itemInfo.paletteSlot, 0)`. `Palette.h` grants `friend struct EPFTileContext` for the direct private range/count reads; [UID:000201][0x00458590-0x00458610.EPFTileContextPixelRangeTest](by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md) emits the exact typed first-draft body. |

## Ownership Notes

- This class should live with render/image support, not DAT parsing.
- EPF/EPD table loaders produce bounds and payload offsets; `EPFTileContext` holds decoded pixels and masks after payload interpretation.
- Consumers include frame, minimap, dialog, and image-control rendering paths.
- [UID:0002HT][0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap](by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md) is a font-specific producer that writes the decoded pixel pointer at `+0x04`, row stride at `+0x0c`, bounds at `+0x10..+0x1c`, and clears mask fields at `+0x20/+0x24` after its caller releases prior buffers.
- [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md) validates `pixelData` at `+0x04` and `bounds.left/top/right/bottom` at `+0x10/+0x14/+0x18/+0x1c` for the post-decode normalization path. Its helper/global names are descriptive (`ConvertRgb565ToRgb555Pixels`, `g_surfaceUsesRgb565Pixels`) rather than proven original spellings, but the method is first-draft C++ ready.
- [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md) is a confirmed image-loader producer that now uses source-facing EPFTileContext method names in first-draft C++: `ReleaseBuffers`, `AllocateRgb16Pixels` / historical `AllocateWordPixels`, and `NormalizePostDecodePixels`. It writes 16-bit FPF payload pixels into `pixelData` and computes copy/finalizer extents from `bounds`.
- [UID:0002TM][0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext](by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md) is a confirmed image-loader producer for indexed byte pixels. It calls `AllocateIndexed8Pixels` at `0x004d0a16` after validating an 8-bit BMP; width becomes `rowStridePixels` and `bounds.right`, while `abs(signedHeight)` becomes `bounds.bottom`. The helper writes indexed byte pixels directly to `pixelData` and does not call `NormalizePostDecodePixels`.
- [UID:0001BU][0x00520540-0x00520816.ObjectImageControlPane](by-memory/0x00520540-0x00520816.ObjectImageControlPane.md) is a concrete UI consumer of automatic default construction and explicit `ReleaseBuffers`: `ObjectImageControlPane::OnPaint` default-constructs its stack `EPFTileContext` before status-kind dispatch, returns from the Human and Monster branches without releasing borrowed/unused context storage, and calls `ReleaseBuffers` only inside the Item branch after `DrawItemImage`. This is consumer evidence only; EPFTileContext ownership remains this shared render support class.
- [UID:00017R][0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster](by-memory/0x004dfd10-0x004e4d79.NewHumanImageLibLocalMethodCluster.md) records that `NewHumanImageLib::RenderComposition` invokes the same raw `0x00457a60` 40-byte initializer on its local before [UID:0000UX][LoadFrameDrawRecord_004D1600](by-item/LoadFrameDrawRecord_004D1600.md) populates that storage as a `FrameDrawRecord`. This proves ABI-compatible 0x28-byte initialization reuse, not source-type identity: `EPFTileContext` uses `encodedMaskByteCount` and `encodedMaskBytes` at `+0x20/+0x24`, while `FrameDrawRecord` uses `payloadSpan` and `payloadEnd` there. The distinct producer/consumer semantics reject collapsing the two declarations.

## 2026-06-19 Source-Quality Resolution

B004's local PE pass confirms this remains a shared `NexusTK/render/EPFTileContext.cpp` class, not an image-loader, resource-layout, font, Surface/GrafPort, DAT, or UI-feature source. Constructor address `0x00457a60`, historically labeled `InitTileContext` before the constructor reclassification, has 337 rel32 refs and `ReleaseBuffers` has 71 rel32 refs in the audited PE, which is incompatible with feature-local ownership. Format loaders produce or populate contexts, `ResourceLayoutTable` maps EPF/EPD rows into contexts, FontImageLib is a producer, and Surface/GrafPort callback code consumes contexts; none owns the shared class lifecycle, copy, allocation, mask, normalize, and range-query behavior.

Field/type decisions from the same pass:

- `+0x00` is `pixelFormat`: value `0` means 16-bit word/RGB16 pixels; value `1` means indexed8/byte pixels. `isRgb565`, `bitsPerPixel`, `hasAlpha`, and old/new-rendering names are rejected because allocator, mask-builder, and range-test behavior contradict those interpretations.
- `+0x04` remains `pixelData` / primary pixels. Use `void *` in the declaration and typed local casts in method bodies (`unsigned char *` for indexed pixels, `unsigned short *` for word pixels).
- `+0x08` is best modeled as optional `alphaData` / `alphaPlane`. PNG file/resource decode helpers allocate it through `AllocateRgb16PixelsWithAlpha`, store alpha-derived `32 - int(alpha / 255.0f * 32.0f)` 16-bit values, and `CopyTo`/`ReleaseBuffers` treat it as an owned second plane. Keep `auxiliaryData` as a raw-history alias only.
- `+0x0c` is `rowStridePixels`, a logical pixel count rather than a byte pitch.
- `+0x10..+0x1c` is a `RectBounds` value. Allocation helpers use zero-origin bounds; ResourceLayout and FontImageLib may use nonzero frame bounds.
- `+0x20/+0x24` are `encodedMaskByteCount` and `encodedMaskBytes`. `encodedMaskData` remains a historical/resource-row alias, but this is the context's RLE transparency mask stream, not the PNG alpha plane.
- Encoded masks are used by both render callback families. EPF/EPD resource rows can supply preencoded masks, `BuildEncodedMask` can produce them from decoded contexts, slot `dword_69B3E8` dispatches to both compat/RGB555 (`0x004bc090`) and RGB565 (`0x004c0f80`) sprite/tile blitters that handle masked/transparent spans, and [UID:0000UH][DrawEncodedAlphaFrame_00462F20](by-item/DrawEncodedAlphaFrame_00462F20.md) reads the same signed-run row stream through source field `a3[9]` / `+0x24`.
- [UID:0002TG][0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback](by-memory/0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md) is another exact consumer of `encodedMaskBytes` at `+0x24`. Its source contract takes `const EPFTileContext *`; zero terminates each row, negative tokens identify destination spans to transform, positive tokens skip spans, and `token & 0x7f` is the length. It does not read `pixelData` for source color/intensity and does not consult `encodedMaskByteCount`, preserving the observed unchecked stream traversal.
- `byte_69B3D5` is descriptive `g_surfaceUsesRgb565Pixels` in Surface context; [UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md) is a one-caller SoftwareBlend16 helper; `dword_69B3E8` is `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`; `g_uiTileRenderer` remains generated alias pollution rather than a source-level EPFTileContext owner.

No-route retained bodies remain documented but non-emitting: `0x00457f30`, `0x00457ff0`, and `0x00458260` all have normal source-shaped bodies but zero rel32 refs and zero absolute dword refs in the local PE scan. They are not padding or compiler thunks, and they should not be discarded; they should remain as retained helper evidence until a reachability/retained-source policy or exact child no-code split is accepted.

Class-level first-draft C++ is constrained to the enum/layout declaration and safe method prototypes above. Full aggregate method bodies stay on exact child pages or future exact method splits. [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md) emits `NormalizePostDecodePixels`; [UID:000201][0x00458590-0x00458610.EPFTileContextPixelRangeTest](by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md) emits `ContainsIndexedPixelInRanges(const DLPalette *palette) const` with typed `DLPaletteRange` reads. The EPFTileContext header still needs only `struct DLPalette;` because its declaration contains a pointer parameter, while the corresponding Palette header owns the complete `DLPaletteRange` declaration and grants `friend struct EPFTileContext`. Original spelling remains inferred. Retained no-route helpers should not be emitted from this class page.

## DLPalette Dependency And Friendship

- Palette storage, allocation, copy construction, and destruction remain owned by [UID:00003Z][DLPalette](by-class/DLPalette.md).
- The query directly reads `DLPalette::m_paletteRanges` and `m_paletteRangeCount`, then compares each `firstIndex`/`lastIndex` pair inclusively.
- `friend struct EPFTileContext` is declared inside `DLPalette`; it is not a reciprocal friend declaration inside this struct and does not make EPFTileContext a palette owner.
- `EPFTileContext.h` can retain a forward declaration of `DLPalette`; `EPFTileContext.cpp` obtains the complete type through `Palette.h` for the method body.
- Historical `ByteRangeSet`, `m_entryMoves`, and `m_entryMoveCount` vocabulary remains search/audit evidence only and must not reappear in emitted current source.

## Assignment Gate

- Current class score: `COMPLETION:94`, `CONFIDENCE:94`.
- Direct file parent: [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md), completed at `94/94`.
- Exact memory child: [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md), completed at `94/94`.
- Assignment basis: this class is the direct source/type parent for the aggregate because the memory page's 0x28-byte layout, buffer lifecycle, mask builders, copy/decimation/allocation helpers, post-decode normalization, and range scan all operate on the same EPFTileContext object shape documented here.
- Formal H contains the complete enum, fields, public API, and private helpers. Formal CPP owns the exact dependency preamble and routes the eleven-definition aggregate plus exact UID000200/UID000201 tail children. The former retained/no-route blocker is closed.

## Closed Questions And Remaining Limits

- Pixel selector: closed to high probability. `pixelFormat == 0` means 16-bit word/RGB16 pixels and `pixelFormat == 1` means indexed8/byte pixels. Do not call value `0` always RGB565 because `NormalizePostDecodePixels` can convert decoded values to RGB555 for compatibility output.
- Auxiliary plane: closed to high probability. PNG file/resource decode paths are source-quality producers of the optional 16-bit `alphaData` plane; no non-alpha producer is currently documented.
- Encoded-mask consumers: closed for class docs. ResourceLayout can supply preencoded mask data, `BuildEncodedMask` produces the same zero-terminated signed-run row format, slot-2 compat/RGB555 and RGB565 callback families consume masked/transparent spans, UID0002TG consumes the stream for scaled destination tinting without reading source pixels, and alpha-mask overlay code reads the same source-field stream.
- Source owner: closed. Keep `NexusTK/render/EPFTileContext.cpp`.
- Remaining limits: exact original field/member/method spellings, method-body splits for aggregate-only functions, and retained no-route helper emission policy. UID000201's caller-side object, record layout, and source-level access relationship are resolved, so they are no longer class C++ blockers.

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
- [UID:0002TG][0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback](by-memory/0x004c3a50-0x004c3ce1.SoftwareRenderRgb565ScaledRleTintCallback.md)

## 2026-07-29 UID0002MZ Header Dependency Reconciliation

- The exact `0x28` decoded tile-context value declaration now emits through formal H so [UID:00005A][FolderTreePane](by-class/FolderTreePane.md) can embed `EPFTileContext` by value without an incomplete type. Pixel format, pixel/alpha buffers, row stride, bounds, encoded-mask count/storage, lifecycle, allocation, copy, normalization, and palette-query declarations are preserved exactly.
- Method bodies remain routed through the existing EPFTileContext CPP children. Score, owner, emitter position, and reconstructability remain `88/90`, [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md), position `0`, and true.

## Historical Assumption Superseded By UID0002MZ

- The former CPP-only declaration and FolderTree forward-declaration shape were insufficient for a by-value class member. The accepted H migration supersedes only that source-placement assumption; all prior binary layout and method evidence remains current.

## Changes

### 2026-08-11 - B008 UID0002TG encoded-mask consumer synchronization

- Kept class metadata, owner/emitter route, position, layout, and formal H unchanged at `88/90`.
- Added the exact target use of `encodedMaskBytes`, signed zero-delimited row grammar, destination-only tint behavior, and negative evidence for source `pixelData` and `encodedMaskByteCount` reads.

### 2026-08-04 - B002 UID0004HV support synchronization

- Score, owner/emitter route, reconstructability, position, layout, and formal H declaration remain unchanged at `88/90`.
- Synchronized `ContainsIndexedPixelInRanges` to typed inclusive `DLPaletteRange` records and documented that `DLPalette` grants `friend struct EPFTileContext`; no reciprocal friendship, public fields, or invented accessor was added.
- Retained former ByteRangeSet/entry-move wording as historical evidence and preserved all unrelated retained-helper policy.

### 2026-07-13 - B002 UID0004DO consumer/type synchronization

- Score, metadata, owner/emitter route, layout, and formal declaration remain unchanged.
- Added the exact `RenderComposition` evidence that the shared raw 0x28 initializer is reused before `LoadFrameDrawRecord` populates a local frame record.
- Recorded the type boundary explicitly: equal size and initializer reuse establish ABI compatibility, while the distinct `+0x20/+0x24` meanings reject collapsing `EPFTileContext` and `FrameDrawRecord`.

### 2026-06-04 - Expanded live method inventory

- Before: the method table listed the initializer, two mask builders, copy, release, and two tail helpers only.
- Changed to: added the live middle bodies at `0x00457f30`, `0x00457ff0`, `0x00458260`, `0x004583d0`, `0x00458430`, and `0x00458490`, and replaced stale evidence wording with the live IDA/Hex-Rays basis.
- Summary/evidence: [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md) now records exact boundaries, padding, caller/callee evidence, and behavior for every body in the aggregate. Class metadata is unchanged because final field and method names remain provisional.

### 2026-06-08 - Batch 102 parent-gate refresh

- Before: `COMPLETION:80`, `CONFIDENCE:82`; the class carried the render file parent but was below the corrected child-and-parent `85/85` gate for assigning the full aggregate memory child.
- Changed to: `COMPLETION:85`, `CONFIDENCE:86`; parent remains [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md).
- Summary/evidence: the page now records the full aggregate inventory as class-owned behavior, direct file parent readiness at `89/86`, the exact memory child at `86/90`, FontImageLib producer evidence, shared image-loader allocation callers, and final field-name caveats. This supports routing [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md) to this class while leaving final C++ blank.

### 2026-06-19 - NormalizePostDecodePixels source-quality update

- Score unchanged.
- Summary/evidence: B005 resolved [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md) to first-draft C++ using `pixelData`, `bounds`, `g_surfaceUsesRgb565Pixels`, and [UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md). This narrows the class-level blocker to broader field/type names such as `pixelMode`, `auxiliaryData`, and encoded-mask fields rather than the post-decode normalization method itself.

### 2026-06-20 - B004 Rule 26 source-quality incorporation

- Before: `COMPLETION:85`, `CONFIDENCE:86`; `pixelMode`, `auxiliaryData`, encoded-mask consumers, and class C++ readiness were still open.
- Changed to: `COMPLETION:88`, `CONFIDENCE:90`; class-level enum/layout C++ is populated while full method bodies remain exact-child work.
- Summary/evidence: B004's report-level reanalysis was incorporated without a detail cap. The page records the audited PE identity, broad constructor-at-`0x00457a60`/`ReleaseBuffers` fan-in (the constructor retained `InitTileContext` only as a historical raw label), pixel-format enum semantics, PNG-produced `alphaData` plane, `rowStridePixels`, `encodedMaskByteCount`/`encodedMaskBytes`, both compat/RGB555 and RGB565 `dword_69B3E8` callback-family consumers, `DrawEncodedAlphaFrame` signed-run stream use, rejected source-owner and generated-alias alternatives, no-route retained helper status for `0x00457f30`/`0x00457ff0`/`0x00458260`, and the split C++ policy.

### 2026-06-21 - B006 image-loader producer sync

- Score unchanged.
- Summary/evidence: [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md) now emits first-draft ImageLoaders C++ that calls this class's release, RGB16/word allocation, and post-decode normalization methods. This is producer/caller evidence only and does not change EPFTileContext ownership.

### 2026-06-21 - B008 ObjectImageControlPane support sync

- Score unchanged.
- Historical note: this 2026-06-21 entry originally described `InitTileContext` and release on a default/item path. That wording is superseded: current accepted source uses automatic `EPFTileContext` construction and calls `ReleaseBuffers` only after the Item-branch draw; Human and Monster return without that call. Ownership remains shared render support.

### 2026-06-21 - B007 BMP indexed producer sync

- Score unchanged.
- Summary/evidence: [UID:0002TM][0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext](by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md) now emits first-draft ImageLoaders C++ that calls this class's release and indexed byte-pixel allocation methods. This adds the BMP caller at `0x004d0a16`, width/height-to-bounds behavior, and explicit no-`NormalizePostDecodePixels` indexed-output behavior as producer evidence only.

### 2026-07-09 - B005 UID000201 implementation sync

- Score unchanged.
- Summary/evidence: [UID:000201][0x00458590-0x00458610.EPFTileContextPixelRangeTest](by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md) now emits first-draft `EPFTileContext::ContainsIndexedPixelInRanges(const DLPalette *palette) const`. Current MCP confirmed the two raw ItemObj caller sites push the `DLPalette *` returned by `PaletteLib::GetSlotPalette(10, itemInfo.paletteSlot, 0)` and the method consumes `m_entryMoves`/`m_entryMoveCount` as inclusive indexed-pixel ranges. The class declaration now has a `DLPalette` forward declaration and the method prototype; the old `ByteRangeSet`/range-record blocker is historical only.

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
