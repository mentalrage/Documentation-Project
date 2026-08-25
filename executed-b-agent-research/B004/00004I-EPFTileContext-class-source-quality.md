** TARGET-REPORT-UID:00004I **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
FINISHED

# 00004I EPFTileContext Class Source-Quality Report

Assignment: `B004-goal2-epf-tile-context-class-source-quality-00004I-20260619`

Target: [UID:00004I] `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\EPFTileContext.md`

Expected report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\00004I-EPFTileContext-class-source-quality.md`

Report-only status: no `by-*` documentation file, generated source file, or coverage report was edited by this pass. The only intended writable outputs are this report and `tools/leaser/Agents/Agent-B004/notes.md`.

## Recommendation Summary

Keep [UID:00004I][EPFTileContext](../../../../by-class/EPFTileContext.md) owned and emitted through [UID:0000J4][EPFTileContext](../../../../by-file/EPFTileContext.md), with source placement `NexusTK/render/EPFTileContext.cpp`.

Recommended score: raise `COMPLETION:85` / `CONFIDENCE:86` to `COMPLETION:88` / `CONFIDENCE:90`.

The prior class-level blockers can be substantially closed:

- `+0x00` is best modeled as a pixel-format selector, not a generic mode flag. Value `0` means 16-bit word pixels; value `1` means 8-bit indexed/byte pixels.
- `+0x04` remains the primary decoded pixel buffer.
- `+0x08` is best modeled as an optional 16-bit alpha/mask plane, produced by the PNG decode wrappers. The historical `auxiliaryData` label is too vague for final prose, but it should remain as an alias where support docs still use it.
- `+0x0c` is a row stride in logical pixels, not bytes.
- `+0x10..+0x1c` is a `RectBounds`/frame bounds value.
- `+0x20` and `+0x24` should be documented as `encodedMaskByteCount` and `encodedMaskBytes`/`encodedMaskData`.
- Encoded masks are not old-rendering-only. They feed shared sprite/tile blit paths selected through `dword_69B3E8`; the docs prove both the compat/RGB555 and RGB565 callback families consume masked/transparent spans. The alpha-mask overlay helper also consumes the same signed-run row stream from source field `+0x24`/`a3[9]`.
- The class is ready for a constrained first-draft source declaration: enum plus 0x28-byte field layout and safe method prototypes. The full aggregate method bodies should not be emitted from the class page yet; body emission should stay on exact child pages or later exact method splits.
- Raw/no-route bodies `0x00457f30`, `0x00457ff0`, and `0x00458260` remain real source-shaped retained helpers but should stay non-emitting until reachability or intended inline/retained status is accepted.

## Evidence Checked

Governing/process files:

- `tools/leaser/Agents/Supervisor.md`, including Rule 26/B-agent source-quality requirements, report-only workflow, and coverage-report edit ban.
- `.codex/AGENTS.md`, including the same fixed B-agent inference standard and no-detail-cap incorporation rule.
- `tools/leaser/Agents/Agent-B004/goal.md`, including report-only output policy and code-entry gate notes.
- `tools/leaser/Agents/Agent-B004/notes.md`, for current B004 standing policy and pending handoff format.

Target and direct support pages:

- [UID:00004I] `by-class/EPFTileContext.md`.
- [UID:0000J4] `by-file/EPFTileContext.md`.
- [UID:0000XY] `by-memory/0x00457a60-0x00458610.EPFTileContext.md`.
- [UID:000200] `by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md`.
- [UID:000201] `by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md`.
- [UID:0003ZP] `by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md`.

Producer and resource-layout evidence:

- [UID:000175] `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md`.
- [UID:0002TK] `by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md`.
- [UID:0002TM] `by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md`.
- [UID:00032P] `by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md`.
- [UID:00032O] `by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md`.
- [UID:0002KP] `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md`.
- [UID:0002KR] `by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md`.
- [UID:0000VB] `by-item/ResourceLayoutEntry.md`.
- [UID:0002HT] `by-memory/0x004b61e0-0x004b6341.FontImageLibDecodeGlyphBitmap.md`.
- [UID:0000JH] `by-file/FontImageLib.md`.

Consumer/render-path evidence:

- [UID:0000TN] `by-global/SurfaceRenderCallbackTable.md`.
- [UID:0000SV] `by-global/g_uiTileRenderer.md`.
- [UID:000167] `by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md`.
- [UID:000166] `by-memory/0x004b99f0-0x004b9a63.ForwardToTileFrameBlitHelper.md`.
- [UID:00016A] `by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md`.
- [UID:00016J] `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md`.
- [UID:00016L] `by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md`.
- [UID:0002PH] `by-memory/0x004bc090-0x004bd3e8.SoftwareRenderCompatSpriteBlitCallback.md`.
- [UID:0002PK] `by-memory/0x004c0f80-0x004c3123.SoftwareRenderRgb565SpriteBlitCallback.md`.
- [UID:0002TB] `by-memory/0x004bd420-0x004bdca9.SoftwareRenderCompatRleFillCallback.md`.
- [UID:0002TF] `by-memory/0x004c3190-0x004c3a40.SoftwareRenderRgb565RleFillCallback.md`.
- [UID:0000UH] `by-item/DrawEncodedAlphaFrame_00462F20.md`.
- [UID:0000YO] `by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md`.

Generated/source-output evidence checked as leads only, not authority:

- `auto-generated/NexusTK/render/EPFTileContext.cpp`.
- `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-file-coverage.md`, and `auto-generated/-ag-memory-coverage.md`.
- `../simroot_v2/class_EPFTileContext.cpp`.
- Generated and simroot cross-references to `EPFTileContext`, `pixelData`, `auxiliaryData`, `encodedMaskData`, and `SurfaceSpriteBlitProc`.

Coverage/report evidence:

- Current target row in `by-class/-coverage-report.md`.
- Current direct file row in `by-file/-coverage-report.md`.
- Current memory aggregate/tail rows in `by-memory/-coverage-report.md`.

Fresh local PE evidence:

- Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Size: `2679296`.
- MD5: `4247e04e20b65d6414c7238aa8ff5515`.
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Image base: `0x00400000`.
- Sections checked:
  - `.text` `0x00401000-0x0060c600`, raw `0x400+0x20b600`.
  - `.rdata` `0x0060d000-0x0066c200`, raw `0x20ba00+0x5f200`.
  - `.data` `0x0066d000-0x0069ce24`, raw `0x26ac00+0xd800`.
  - `.rsrc` `0x0069d000-0x006b2e00`, raw `0x278400+0x15e00`.

Fresh PE rel32/reference scan results:

| Target | Result |
| --- | --- |
| `0x00457a60 InitTileContext` | 337 rel32 refs. First examples: `0x0041baf8`, `0x0041bb03`, `0x0041bb0e`, `0x0041bc51`, `0x00451291`, `0x0046758b`, `0x004678a9`, and many UI/render callers. No absolute dword refs to the start. |
| `0x00457ab0 BuildRleMask8` | 6 rel32 refs: `jmp@0x004562f3`, calls at `0x00499390`, `0x004f4e12`, `0x004f5207`, `0x004ff22d`, `0x004ff5ed`. No absolute dword refs. |
| `0x00457c60 BuildRleMask16` | 1 rel32 ref: call from `0x00457ade` inside the 8-bit/public builder's zero-mode dispatch. No absolute dword refs. |
| `0x00457e00 CopyTo` | 3 rel32 refs: `0x004d050a`, `0x004ff226`, `0x004ff5e6`. No absolute dword refs. |
| `0x00457f30 raw word-copy body` | 0 rel32 refs and 0 absolute dword refs. |
| `0x00457ff0 CreateHalfScaleCopy` | 0 rel32 refs and 0 absolute dword refs. |
| `0x00458260 CreateHalfScaleWordCopy` | 0 rel32 refs and 0 absolute dword refs. |
| `0x004583d0 AllocateBytePixels` | 1 rel32 ref: `0x004d0a16`. No absolute dword refs. |
| `0x00458430 AllocateWordPixels` | 4 rel32 refs: `0x004d06c8`, `0x004d076d`, `0x004d08ad`, `0x004d0b65`. No absolute dword refs. |
| `0x00458490 AllocateWordPixelsWithAux` | 2 rel32 refs: `0x004d0c9e`, `0x004d0e34`. No absolute dword refs. |
| `0x00458500 ReleaseBuffers` | 71 rel32 refs. Examples include internal calls at `0x00457e27`, `0x00457e8e`, `0x00457f48`, allocation helpers at `0x004583d8`, `0x00458438`, `0x0045849c`, FontImageLib `0x004b608f`, image decoders `0x004d061d`, `0x004d073a`, `0x004d09bc`, and many cleanup paths. No absolute dword refs. |
| `0x00458560 NormalizePostDecodePixels` | 6 rel32 refs: `0x004d06f2`, tail `jmp@0x004d079a`, `0x004d0991`, `0x004d0c42`, `0x004d0d7d`, `0x004d0f29`. No absolute dword refs. |
| `0x00458590 HasPixelInRanges` | 2 rel32 refs: `0x004df70c`, `0x004df7aa`. No absolute dword refs. |

Fresh PE span hashes:

- Aggregate `0x00457a60-0x00458610`, raw `0x56e60`, length `0xbb0`, SHA1 `6302d408053ddb7106fd01825574a1009d8f10d7`.
- Raw word-copy body `0x00457f30-0x00457fe9`, raw `0x57330`, length `0xb9`, SHA1 `5adebc29bf89952b0f6690027422f60a9881af25`.
- `CreateHalfScaleCopy` `0x00457ff0-0x00458253`, raw `0x573f0`, length `0x263`, SHA1 `3d14a03e79cde58a1e09b17163c95ae7d9b61e9d`.
- `CreateHalfScaleWordCopy` `0x00458260-0x004583c8`, raw `0x57660`, length `0x168`, SHA1 `e0feac97f70ad6633c41f713eeccbe7c9a3f42f8`.

## Heuristic / Inference Reanalysis And Validation

### Class Identity And Source Placement

Best-supported source placement remains `NexusTK/render/EPFTileContext.cpp`.

Evidence:

- The target is a compact 0x28-byte object used across resource layout, image loaders, font rendering, GrafPort/surface blitters, pane painting, startup logos, and image-library code.
- `InitTileContext` has 337 direct rel32 call sites and `ReleaseBuffers` has 71 direct rel32 call sites in the local PE scan. That fan-in is incompatible with feature-local ownership.
- Resource layout code populates the object from EPF/EPD row metadata, but does not own buffer lifecycle, RLE construction, pixel normalization, range tests, or allocation helpers.
- Image loader wrappers produce decoded pixels and optional alpha planes, but the class methods are shared by ZPF/FPF/JPF/BMP/JPEG/PNG paths.
- FontImageLib writes the context shape for glyph output, but only as a producer/consumer of the layout.
- Surface/GrafPort callback docs consume the object for drawing, but the object lifecycle and decode-normalization helpers do not belong to Surface.

Rejected placements:

- `ImageLoaders.cpp`: owns format-specific conversion into the context; does not own shared context allocation/copy/release/mask methods.
- `ResourceLayoutTable.cpp`: owns EPF/EPD frame row lookup; it can map row pointers into a context but does not own the context class.
- `FontImageLib.cpp`: owns glyph decode into the context shape; only a single producer.
- `Surface.cpp`/`GrafPort.cpp`: owns blitters and callback dispatch; those are downstream consumers.
- Any UI feature source: caller fan-in is far too broad.

### Pixel-Mode Semantics

Best-supported source-facing field: `pixelFormat` / `m_pixelFormat`.

Best-supported enum:

```cpp
enum EPFTilePixelFormat {
    kEPFTilePixelFormatRgb16 = 0,
    kEPFTilePixelFormatIndexed8 = 1
};
```

Evidence:

- `InitTileContext` initializes the first dword to `1`.
- `AllocateBytePixels` at `0x004583d0` sets the first dword to `1`, allocates `width * height` bytes, and is called from `Decode8BitBmpToTileContext`.
- `AllocateWordPixels` at `0x00458430` sets the first dword to `0`, allocates `2 * width * height` bytes, and is called by 16-bit image decode paths.
- `AllocateWordPixelsWithAux` at `0x00458490` also sets the first dword to `0`, allocates `2 * width * height` primary and auxiliary planes, and is called by PNG decode wrappers.
- `BuildRleMask8` dispatches to `BuildRleMask16` when the first dword is zero. Otherwise it scans byte pixels.
- `EPFTileContextPixelRangeTest` returns false when the first dword is zero and scans only byte pixels when nonzero.
- `NormalizePostDecodePixels` runs only over the primary 16-bit pixel buffer produced by word decoders; it does not test the field because all documented callers are 16-bit decode paths.

Rejected names:

- `isRgb565`: too narrow. The field distinguishes 16-bit word pixels from 8-bit indexed pixels. The 16-bit plane may be RGB565 before normalization or RGB555 after `NormalizePostDecodePixels`.
- `isIndexed8`: directionally true for value `1`, but it hides value `0` and is awkward for method dispatch.
- `bitsPerPixel`: values are `0` and `1`, not `8` and `16`.
- `hasAlpha`: false because both `AllocateWordPixels` and `AllocateWordPixelsWithAux` set zero; alpha-plane presence is instead pointer `+0x08`.
- `legacyMode` or `newRenderingMode`: rejected by the allocator and pixel-range behavior; render mode is a separate Surface/global concern.

Source-ready phrasing:

- In prose: "`pixelFormat == 1` means indexed/byte pixels; `pixelFormat == 0` means 16-bit word pixels."
- In C++: prefer an enum with `kEPFTilePixelFormatRgb16 = 0` and `kEPFTilePixelFormatIndexed8 = 1`.
- Avoid calling value `0` "RGB565" unconditionally. The decode path writes RGB565-like pixels, then `NormalizePostDecodePixels` converts them to RGB555 when `g_surfaceUsesRgb565Pixels` is false.

### Primary Pixel Buffer

Best-supported source-facing name: `pixelData` or `pixels`.

Type recommendation:

- Use `void *pixelData` in a first declaration if source compatibility with existing generated children matters.
- Use typed local casts in method bodies:
  - `unsigned char *` / `const unsigned char *` for indexed/byte pixels.
  - `unsigned short *` / `const unsigned short *` for 16-bit word pixels.

Evidence:

- `ResourceLayoutTableLookupLayoutEntry` writes row field `entry + 0x10` into context `+0x04`.
- `Decode8BitBmpToTileContext` fills the byte pixel plane after `AllocateBytePixels`.
- 16-bit decode wrappers fill the word pixel plane after `AllocateWordPixels`.
- PNG wrappers fill the word pixel plane after `AllocateWordPixelsWithAux`.
- `FontImageLibDecodeGlyphBitmap` stores its scratch pixel buffer at context `+0x04`.
- `NormalizePostDecodePixels` reads only `+0x04` and bounds to transform the primary 16-bit buffer.
- `GrafPort` generated and support docs use `m_surfaceContext.pixelData` for embedded surface-paint contexts.

Rejected names:

- `imageData`: too broad but acceptable as prose; existing docs and generated output already converge on `pixelData`.
- `payloadData`: would confuse decoded pixels with raw DAT/EPF payload offsets.
- `frameData`: too tied to ResourceLayoutEntry and would not fit fonts/PNG/BMP/surface contexts.

### Auxiliary Buffer At +0x08

Best-supported source-facing name: `alphaData` / `alphaPlane`, with `auxiliaryData` retained as a raw-history alias.

Type recommendation: `unsigned short *alphaData` or `void *auxiliaryData` in an early declaration with comments. Behavior supports a 16-bit plane.

Evidence:

- `AllocateWordPixelsWithAux` allocates two buffers of `2 * width * height`: the primary plane at `+0x04` and a second plane at `+0x08`.
- `DecodePngFileToTileContext` and `DecodePngResourceToTileContext` call `0x00458490`, convert decoded RGBA into RGB565 primary pixels, and convert alpha as `32 - int(alpha / 255.0f * 32.0f)` into the second plane.
- `CopyTo` deep-copies `+0x08` when present using the same pixel-buffer size calculation as the primary plane.
- `ReleaseBuffers` frees `+0x08` independently and clears it.
- No other support doc showed a non-alpha producer for `+0x08`.

Rejected names:

- `auxiliaryData`: accurate as a conservative raw label but too vague for source-quality output.
- `secondaryPixels`: plausible but weaker than alpha-plane evidence from PNG wrappers.
- `maskData`: ambiguous with encoded RLE mask fields at `+0x20/+0x24`.
- `encodedMaskData`: wrong field; encoded masks are byte streams at `+0x24`.
- `paletteData`: rejected by allocation size and PNG alpha conversion.
- `scratchData`: rejected by ownership and copy/release semantics.

Open residual:

- The exact original member spelling is not proven. `alphaData`/`alphaPlane` is the best descriptive source-facing name from current producer evidence. If a later callback-body signature pass proves the plane is a 0..32 "shadow", "opacity", or "inverse alpha" value, docs can refine the name without reopening ownership.

### Bounds And Row Stride

Best-supported fields:

```text
+0x0c  int rowStridePixels
+0x10  int bounds.left
+0x14  int bounds.top
+0x18  int bounds.right
+0x1c  int bounds.bottom
```

Evidence:

- `ResourceLayoutTableLookupLayoutEntry` computes `rowStride = right - left`.
- Allocation helpers set zero-origin bounds with right/width and bottom/height.
- `FontImageLibDecodeGlyphBitmap` writes glyph bounds and stride `right - left`.
- `NormalizePostDecodePixels` computes pixel count as `(right - left) * (bottom - top)`.
- `EPFTileContextPixelRangeTest` uses `rowStride` as the number of byte pixels scanned per row and `bottom - top` as row count.
- GrafPort support docs identify embedded `m_surfaceContext.rowStride` and `bounds` fields.

Rejected names:

- `byteStride`: wrong for 16-bit contexts. The value is a logical pixel count.
- `pitchBytes`: wrong for the same reason.
- `width`: not always the same semantic as frame bounds in resource-layout use, although zero-origin allocations set it equal to width.

### Encoded Mask Fields

Best-supported source-facing names:

```text
+0x20  int encodedMaskByteCount
+0x24  unsigned char *encodedMaskBytes
```

`encodedMaskData` remains acceptable as an alias because ResourceLayoutEntry currently uses that name for its row field.

Evidence:

- `ResourceLayoutEntry` raw row has pixel data offset at `+0x08` and encoded-mask offset at `+0x0c`. The in-memory row maps payload pointer at `+0x10` and encoded-mask pointer at `+0x14`.
- `ResourceLayoutTableLookupLayoutEntry` maps row data into `EPFTileContext`: `pixelData = entry.pixelData`, `rowStride = right - left`, bounds copied, `encodedMaskData = entry.encodedMaskData`, and `encodedMaskSize = nextEntry.pixelData - entry.encodedMaskData`.
- The sentinel row installed by the ResourceLayout loader makes the byte-count calculation valid for the final frame.
- `BuildRleMask8` and `BuildRleMask16` free any existing encoded mask, encode row runs into a 100000-byte stack scratch buffer, allocate the exact byte count, and copy to `+0x24`.
- Both builders emit zero-terminated rows. Tokens use the low seven bits for length and set bit `0x80` on nonzero/opaque runs. Runs are capped at 127.
- `LogoPane` support docs use `encodedMaskByteCount` and `encodedMaskBytes` wording for `this + 0x118` and `this + 0x11c` inside an embedded `EPFTileContext`.
- `DrawEncodedAlphaFrame` reads encoded source rows from `a3[9]`, which corresponds to source record field `+0x24`, and walks signed run tokens where high-bit runs are drawn and low seven bits are length.

Rejected names:

- `alphaData`: wrong field. The alpha plane is `+0x08`.
- `rleData`: directionally true but too generic. The field is specifically a transparency/run mask.
- `compressedPixels`: wrong because the mask stream describes transparency/coverage, not pixel colors.
- `oldRenderMask`: wrong because both active callback families handle masked/transparent spans.

### Encoded-Mask Consumers: Old, New, Or Both

Best-supported answer: both rendering families consume the encoded mask semantics. The mask is not limited to old/compat rendering.

Evidence:

- `SurfaceRenderCallbackTable` slot `dword_69B3E8` is the primary EPF/tile/frame/sprite blit callback.
- Slot `dword_69B3E8` has a compat/RGB555 target `0x004bc090` and an RGB565-capable target `0x004c0f80`.
- `SurfaceSpriteBlitHelper`, `ForwardToTileFrameBlitHelper`, and `GrafPortDrawTiledBackground` all dispatch through `dword_69B3E8` with an `EPFTileContext`/frame-record style source descriptor, source rect, destination rect, mode, palette, and flags/options.
- `SoftwareRenderCompatSpriteBlitCallback` handles clipped source/destination rectangles, straight copies, masked/transparent spans, and RGB555 transform/blend paths.
- `SoftwareRenderRgb565SpriteBlitCallback` handles the same broad role for RGB565, including clipped source/destination rectangles, row copies, masked/transparent spans, and RGB565 blend/helper paths.
- `DrawEncodedAlphaFrame` separately proves the row-token format is consumed in alpha-mask overlay paths, reading encoded rows from source field `a3[9]`/`+0x24` and using high-bit signed runs.
- `g_uiTileRenderer` was checked and is a generated alias over `g_pEPFLib` lookups plus callback slots, not a source-level owner or separate renderer abstraction.

Residual precision limit:

- The large sprite callback child pages summarize masked/transparent span behavior but do not yet expose every source-descriptor field read in source-quality names. Even with that limitation, the table assignment plus sibling callback behavior is enough to reject an old-rendering-only claim.

### Method Name Recommendations

These names are source-facing recommendations, not proven original symbols.

| Address | Current label | Recommended source-facing name/policy |
| --- | --- | --- |
| `0x00457a60` | `InitTileContext` | `EPFTileContext::Initialize()` or existing `InitTileContext()`. Do not model as a compiler constructor; callers explicitly initialize stack/embedded storage. |
| `0x00457ab0` | `BuildRleMask8` | Public `BuildEncodedMask()` / `BuildTransparencyMask()`. It handles indexed pixels and dispatches to the word helper when `pixelFormat == 0`, so an `8` suffix is only an implementation detail. |
| `0x00457c60` | `BuildRleMask16` | Private/helper `BuildEncodedMask16()` / `BuildWordEncodedMask()`. Only called by the public builder. |
| `0x00457e00` | `CopyTo` | `CopyTo(EPFTileContext *destination) const` remains well-supported. It releases the destination, copies header fields, and deep-copies primary, alpha, and encoded-mask buffers. |
| `0x00457f30` | raw 16-bit copy body | Retained/no-route word-copy duplicate. Best label `CopyWordPixelsToRetained` or `CopyWordContextTo`; no emitted C++ until route or duplicate policy is accepted. |
| `0x00457ff0` | `CreateHalfScaleCopy` | Retained/no-direct-caller half-scale clone. Best label `CreateHalfScaleCopy`; do not emit body yet. |
| `0x00458260` | `CreateHalfScaleWordCopy` | Retained/no-direct-caller word half-scale clone. Best label `CreateHalfScaleWordCopy`; do not emit body yet. |
| `0x004583d0` | `AllocateBytePixels` | `AllocateIndexed8Pixels(int width, int height)`. |
| `0x00458430` | `AllocateWordPixels` | `AllocateRgb16Pixels(int width, int height)` or `AllocateWordPixels`. Avoid hard-coding RGB565 in the name because post-decode normalization may convert to RGB555. |
| `0x00458490` | `AllocateWordPixelsWithAux` | `AllocateRgb16PixelsWithAlpha(int width, int height)` / `AllocateWordPixelsWithAlpha`. |
| `0x00458500` | `ReleaseBuffers` | `ReleaseBuffers()` remains source-quality. `Clear()` is possible but less precise because it frees owned buffers. |
| `0x00458560` | `NormalizePostDecodePixels` | Accepted and already first-draft-emitted. |
| `0x00458590` | `HasPixelInRanges` | `ContainsIndexedPixelInRanges(const ByteRangeSet *) const` is best descriptive naming. Keep C++ blank until the range-record type is settled. |

### Raw/Generated Names And Helper/Global Meanings

`byte_69B3D5`:

- Best source-facing name is `g_surfaceUsesRgb565Pixels`.
- This was resolved by the accepted [UID:000200] and [UID:0003ZP] support passes.
- It belongs to Surface/pixel-format context, not EPFTileContext ownership.

`sub_4BB0E0`:

- Best source-facing name is `ConvertRgb565ToRgb555Pixels(unsigned short *pixels, int pixelCount)`.
- It is a one-caller stateless helper owned by [UID:0000NT][SoftwareBlend16](../../../../by-file/SoftwareBlend16.md), not an EPFTileContext method.

`dword_69B3E8`:

- Best source-facing name is `g_pfnBlitSprite` / `SurfaceSpriteBlitProc`.
- It is a Surface render callback-table slot. It is not a `g_uiTileRenderer` singleton.

`g_uiTileRenderer`:

- Rejected as generated alias pollution. The global page records no backing global storage. Real paths use `g_pEPFLib`/ResourceLayout lookup plus Surface callback slots.

`dword_67A7E0`:

- Palette/color context used by software callbacks. It is a downstream Surface/GrafPort callback dependency, not an EPFTileContext member.

Memory allocation helpers:

- Allocation/copy/free helpers are project MemoryMan support. They do not change EPFTileContext source ownership.

### Caller/Reachability Conclusions

Live/direct users:

- `InitTileContext` and `ReleaseBuffers` are broad shared APIs.
- `BuildRleMask8` has six live refs including logo/static image/control paths and one internal/raw jump path.
- `CopyTo` has three live refs, including `ResourceLayoutTableCopyEntryTileContext`.
- `AllocateBytePixels`, `AllocateWordPixels`, and `AllocateWordPixelsWithAux` are called by image decode wrappers.
- `NormalizePostDecodePixels` is called by six 16-bit image decode/finalizer paths.
- `HasPixelInRanges` has two raw image-library call sites.

No-route/retained bodies:

- `0x00457f30`, `0x00457ff0`, and `0x00458260` have zero rel32 refs and zero absolute dword refs in the local PE scan.
- Existing docs also report no direct live callers for `CreateHalfScaleCopy` and `CreateHalfScaleWordCopy`, despite the bodies being source-shaped and bounded by alignment.
- These are not compiler thunks or padding. They have normal prologues, calls, and source-like control flow. They should remain documented as retained/unreferenced helpers, not ignored.

## First-Draft C++ Readiness

Recommendation: emit constrained class/layout C++ when accepted. Do not emit the full aggregate method bodies from the class page.

Rationale:

- The class target is reconstructable and already has an emitter route through [UID:0000J4].
- The combined score gate is satisfied now and improves with this pass.
- The class field layout is source-quality enough for a declaration and will reduce generated-source pollution where other pages assume `EPFTileContext` exists.
- The raw/no-route helpers and the large callback-consumer paths are not blockers for a declaration. They are blockers for complete method-body reconstruction from the aggregate.
- Existing child [UID:000200] already emits `NormalizePostDecodePixels`.
- [UID:000201] and the aggregate can remain blank until the `ByteRangeSet` type and retained helper policies are resolved.

Suggested class-level first-draft C++:

```cpp
enum EPFTilePixelFormat {
    kEPFTilePixelFormatRgb16 = 0,
    kEPFTilePixelFormatIndexed8 = 1
};

struct EPFTileContext {
    EPFTilePixelFormat pixelFormat;
    void *pixelData;
    unsigned short *alphaData;
    int rowStridePixels;
    RectBounds bounds;
    int encodedMaskByteCount;
    unsigned char *encodedMaskBytes;

    void Initialize();
    void ReleaseBuffers();
    void BuildEncodedMask();
    void CopyTo(EPFTileContext *destination) const;
    void AllocateIndexed8Pixels(int width, int height);
    void AllocateRgb16Pixels(int width, int height);
    void AllocateRgb16PixelsWithAlpha(int width, int height);
    void NormalizePostDecodePixels();
};
```

Notes for implementation:

- If the current autogen convention expects member names used by existing emitted child C++ (`pixelData`, `bounds.right`, etc.), either keep those aliases or update the emitted [UID:000200] method in the same implementation callback.
- If `RectBounds` is not yet declared in the generated route, use the accepted rectangle layout/type from [UID:00015S]/[UID:0001VP] support docs or include a forward declaration strategy consistent with surrounding generated render files.
- Do not add a compiler constructor/destructor pair from this declaration. The binary uses explicit initialization and release helpers.
- The optional alpha plane field can be temporarily declared as `void *auxiliaryData` if the generated C++ route cannot yet absorb the refined `unsigned short *alphaData` name, but target/support prose should explain the high-probability alpha-plane role.

Target-specific no-code proof for full method bodies:

- The aggregate includes source-like retained bodies with zero rel32/absolute refs. Emitting all bodies from the class page would incorrectly make no-route helpers look live or final.
- `BuildEncodedMask`, allocation helpers, copy helpers, and half-scale helpers still need exact child pages or accepted aggregate-body policy before method-body C++ should be generated.
- `HasPixelInRanges` depends on a caller-side range-record declaration that is still provisional.

## Split And Range Decisions

Keep the class and aggregate range as `0x00457a60-0x00458610`.

No immediate range change is recommended. The current aggregate includes every source-like body and padding span through the tail helper before RankingDialog. The target class page should not split itself.

Future support split recommendations:

- If method-body emission is accepted later, create exact child pages for currently aggregate-only methods rather than emitting a monolithic aggregate body.
- High-value exact child candidates:
  - `0x00457a60-0x00457aa4 Initialize`.
  - `0x00457ab0-0x00457c53 BuildEncodedMask`.
  - `0x00457c60-0x00457df2 BuildEncodedMask16`.
  - `0x00457e00-0x00457f2b CopyTo`.
  - `0x004583d0-0x00458423 AllocateIndexed8Pixels`.
  - `0x00458430-0x00458485 AllocateRgb16Pixels`.
  - `0x00458490-0x004584fa AllocateRgb16PixelsWithAlpha`.
  - `0x00458500-0x00458557 ReleaseBuffers`.
- Retained/no-route helper candidates should be split only if the supervisor wants explicit no-code children:
  - `0x00457f30-0x00457fe9`.
  - `0x00457ff0-0x00458253`.
  - `0x00458260-0x004583c8`.

Do not merge EPFTileContext into the software-render callback aggregates or ImageLoaders. Those ranges are downstream consumers or producers, not the object owner.

## Open-Question Closure

Open question: confirm `pixelMode == 0` and `pixelMode == 1`.

- Closed to high probability. Value `0` is 16-bit word pixels; value `1` is 8-bit indexed/byte pixels. Use `pixelFormat`/enum naming. Do not call value `0` always RGB565, because normalization can convert to RGB555.

Open question: identify `auxiliaryData` producers and final meaning.

- Closed to high probability. The known source-quality producer is PNG decode via `AllocateWordPixelsWithAux`, which writes an alpha-derived 16-bit plane. Best name is `alphaData`/`alphaPlane`; `auxiliaryData` should be kept as a raw alias until original spelling is known.

Open question: confirm encoded-mask consumers.

- Closed enough for class docs. ResourceLayout provides preencoded masks; BuildEncodedMask creates masks for decoded/palette/logo-like contexts; shared slot `dword_69B3E8` sprite/tile blitters have compat and RGB565 targets that handle masked/transparent spans; `DrawEncodedAlphaFrame` consumes the same signed-run stream at source `+0x24`. The mask is consumed by both old/compat and RGB565 render paths.

Open question: source owner.

- Closed. Direct source owner remains `NexusTK/render/EPFTileContext.cpp`, not image-loader, resource-layout, font, surface, GrafPort, or feature UI source.

Open question: C++ readiness.

- Closed with a split answer. Class declaration/field-layout C++ is ready; complete aggregate method-body C++ is not ready.

Open question: generated aliases.

- `g_uiTileRenderer` is rejected as generated alias pollution.
- Raw `byte_69B3D5` and `sub_4BB0E0` are resolved in support pages as descriptive names.

## Score And Metadata Recommendation

Target [UID:00004I] metadata:

```text
COMPLETION:88
CONFIDENCE:90
CANONICAL_OWNER:0000J4
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000J4
```

Justification:

- Completion improves because the target's major open field/type questions now have high-probability source-facing answers with direct producer/consumer evidence.
- Confidence improves because the direct PE scan reconfirmed callsites, no-route bodies, no absolute pointer refs, and exact binary identity, while support docs independently align across ResourceLayout, ImageLoaders, FontImageLib, Surface callbacks, and alpha-mask helpers.
- Scores should remain below final/perfect because original spellings are not proven, exact method-body child pages do not exist for most methods, and the retained no-route bodies still need a policy decision before code emission.

Direct file [UID:0000J4]:

- Keep owner/path unchanged.
- Score change optional. I recommend no mandatory score change for the file root in this implementation callback; the file page can incorporate the resolved field names and close stale open questions while staying `89/86`. If the supervisor wants to raise confidence, `89/88` is defensible, but the target assignment only requires the class row update.

Memory aggregate [UID:0000XY]:

- Text update recommended to incorporate resolved field names and consumer conclusions.
- Score change optional. `88/91` is defensible if the aggregate is updated with the fresh PE ref scan and resolved field/consumer policy, but the class target can be accepted without changing the memory aggregate score.

## Implementation Checklist For Later Callback

Target doc update:

- Edit `by-class/EPFTileContext.md`.
- Raise score to `88/90`.
- Add or update a dedicated source-quality/heurstic section with:
  - `pixelFormat` enum direction: `0` = 16-bit word/RGB16; `1` = indexed8.
  - `+0x08` alpha-plane inference from PNG decode helpers.
  - `encodedMaskByteCount` / `encodedMaskBytes` naming.
  - both-render-family encoded-mask consumer conclusion.
  - no-route status for `0x00457f30`, `0x00457ff0`, and `0x00458260`.
  - first-draft class declaration recommendation.
- Replace stale open questions with closure statements instead of generic future-work bullets.
- Populate class-level `RECONSTRUCTION_CPP` with the constrained enum/layout declaration if the supervisor accepts first-draft class C++.

Direct support docs to synchronize:

- `by-file/EPFTileContext.md`:
  - Replace old open questions about `pixelMode`, `auxiliaryData`, and encoded-mask consumers with the resolved inferences.
  - Keep source placement under `render/EPFTileContext.cpp`.
  - Mention that class-level declaration is now ready while full aggregate method bodies remain exact-child work.
- `by-memory/0x00457a60-0x00458610.EPFTileContext.md`:
  - Add the fresh PE ref scan results and span hashes if desired.
  - Replace "mode/control dword" with source-facing pixel-format wording.
  - Refine `auxiliaryData` to optional alpha plane, with raw alias.
  - Document encoded-mask consumers across `dword_69B3E8` compat/RGB565 and alpha-mask overlay helpers.
  - Preserve no-route evidence for raw/decimation helpers.
- `by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md`:
  - No required change; it already emits first-draft C++ and supports the pixel-format conclusion.
- `by-memory/0x00458590-0x00458610.EPFTileContextPixelRangeTest.md`:
  - Optional wording update: byte-mode query should reference `pixelFormat == kEPFTilePixelFormatIndexed8`.
- `by-item/ResourceLayoutEntry.md`:
  - Optional wording update: distinguish resource row `encodedMaskData` from context `encodedMaskBytes`.
- `by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md` and `by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md`:
  - Optional support update: explicitly tie their second plane to `EPFTileContext::alphaData`/`alphaPlane`.
- `by-global/SurfaceRenderCallbackTable.md`, `by-memory/0x004bc090-0x004bd3e8.SoftwareRenderCompatSpriteBlitCallback.md`, and `by-memory/0x004c0f80-0x004c3123.SoftwareRenderRgb565SpriteBlitCallback.md`:
  - Optional support update: cross-link EPFTileContext encoded-mask field names if callback signature docs are being refined.

Generated C++ route:

- If accepted, `auto-generated/NexusTK/render/EPFTileContext.cpp` should retain the existing [UID:000200] method C++ and gain a class/layout declaration from [UID:00004I].
- If the declaration renames `pixelData` or `bounds`, update [UID:000200] emitted method in the same accepted callback so generated output remains internally consistent.
- Do not emit raw no-route helper bodies from the class page.

Coverage updates:

- Supervisor-owned `by-class/-coverage-report.md` replacement row is required if target score changes.
- Supervisor-owned `by-memory/-coverage-report.md` row is optional only if [UID:0000XY] score/text is changed during implementation. Do not edit coverage from a B-agent report pass.

Validation:

- Re-run scoped target validator after implementation:
  - `python .\tools\validator.py --mode file --file .\by-class\EPFTileContext.md --queue-timeout 240`
- If support docs are touched, run file-mode validators for those exact support docs.

## Exact Supervisor-Owned Coverage Row Text

Replace the current [UID:00004I] row in `by-class/-coverage-report.md` with:

```markdown
- [UID:00004I][EPFTileContext](by-class/EPFTileContext.md) : reconstructable : 88% : strong : B004 2026-06-19 source-quality reanalysis keeps [UID:0000J4][EPFTileContext](by-file/EPFTileContext.md) as the `NexusTK/render/EPFTileContext.cpp` owner/emitter, resolves the first dword as a pixel-format selector (`0` 16-bit word/RGB16 pixels, `1` 8-bit indexed pixels), identifies `+0x08` as the optional 16-bit alpha plane produced by PNG decode helpers, names `+0x20/+0x24` as `encodedMaskByteCount`/`encodedMaskBytes`, confirms encoded masks are produced from EPF/EPD resource rows or `BuildEncodedMask` and consumed by both compat/RGB555 and RGB565 sprite/tile blit callback families through `dword_69B3E8` plus alpha-mask overlays, preserves no-route raw `0x00457f30`/`0x00457ff0`/`0x00458260` bodies as retained helpers with no rel32/absolute refs, and recommends constrained class-layout/enum first-draft C++ while full method bodies remain exact-child work.
```

Optional support row only if the supervisor changes [UID:0000XY] score in `by-memory/-coverage-report.md`:

```markdown
    - [UID:0000XY][0x00457a60-0x00458610.EPFTileContext](by-memory/0x00457a60-0x00458610.EPFTileContext.md) 0x00457a60-0x00458610 | class aggregate | EPFTileContext : reconstructable : 88% : very strong : B004 2026-06-19 source-quality reanalysis reconfirms the full EPFTileContext aggregate under [UID:00004I][EPFTileContext](by-class/EPFTileContext.md) with PE identity `4247e04e20b65d6414c7238aa8ff5515`, 337 init refs, 71 release refs, live allocation/finalizer/range-test callers, zero rel32/absolute refs for retained raw `0x00457f30`/`0x00457ff0`/`0x00458260`, `pixelFormat` semantics (`0` 16-bit word/RGB16, `1` indexed8), optional PNG-produced alpha plane at `+0x08`, encoded-mask fields `+0x20/+0x24` as byte count/data, and both compat/RGB555 and RGB565 `dword_69B3E8` callback-family consumers; C++ for the aggregate remains constrained to class/layout declaration and exact child methods until retained helper policy and method-body splits are accepted.
```

No `by-memory/-coverage-report.md` row is required if [UID:0000XY] score is not changed.

## Scoped Validator Baseline

Command run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00004I-EPFTileContext-class-source-quality-removed.md](00004I-EPFTileContext-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Exit code: `0`.

Target ok count: `ok: 1`.

Relevant output:

```text
mode: file
scanned markdown files: 1
ok: 1
ok           00004I by-class/EPFTileContext.md UID header exists
dry run only; pass --apply to write changes
```

The validator dry-run also listed unrelated autogen dry-run updates/noops across the documentation tree. No validator `--apply` was run by this pass.

## Report-Only Edit Confirmation

This pass did not edit any `by-*` documentation file.

This pass did not edit `by-memory/-coverage-report.md`.

This pass did not edit generated C++ or generated coverage reports.

The workspace showed existing dirty `by-*` and generated files during status inspection; those were treated as pre-existing or other-agent changes and were not reverted.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00004I-EPFTileContext-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"00004I"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00004I-EPFTileContext-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/00004I-EPFTileContext-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00004I"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
