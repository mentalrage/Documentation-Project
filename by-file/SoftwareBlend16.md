*** UID:0000NT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SoftwareBlend16

## Status

- Confidence: strong for RGB565/RGB555 helper behavior, medium for final original filename.
- Proposed module: `render/SoftwareBlend16.cpp`, `render/Blend16.cpp`, or a local helper block in a broader surface/blitter file.
- Current recovered sources: `source-3/simroot_v2/recovered/*Blend*00460500..004C60D0.cpp`

## File Role

This module groups low-level 16-bit software blending helpers. They do not own pane, asset-library, or DirectDraw state. They implement pixel, packed-pair, span, and four-pixel-block blend math used by hotter drawing routines.

The dominant current render path is RGB565. `GrafPort::UpdateRenderRegion` creates RGB565 DirectDraw surfaces, PCX/DIB helpers emit RGB565 buffers, and these helpers provide the matching pixel math. The retained RGB555 helper island at [UID:0000YD][0x0045fa00-0x004604f4.Rgb555565BlitHelpers](by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md) and the single-pixel `BlendRgb555_4C0710` helper support the compatibility/old-format software callback family.

The larger software-render callback families live nearby but are not owned here as simple math helpers: [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md) and [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md) are Surface/render-dispatch implementations that consume this file's pixel/span helpers.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `AlphaBlendSpan16` | [UID:0000YE][0x00460500-0x00460709.AlphaBlendSpan16](by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md) | Row/span RGB565 alpha blend dispatcher. |
| `Rgb565HalfBlendSpanRaw` | [UID:000206][0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw](by-memory/0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw.md) | Raw RGB565 half-blend row/span helper that shares `HalfBlendSpan16Blocks`. |
| `Rgb565TransparentAlphaBlendSpanRaw` | [UID:000207][0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw](by-memory/0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw.md) | Raw transparent weighted RGB565 row/span helper. |
| `BlitTransparentShadow565MmxBlocks` | [UID:000208][0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks](by-memory/0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks.md) | MMX RGB565 transparent-shadow block helper called by `BlitTransparentShadow565`. |
| `Rgb565TransparentAlphaBlendMmxBlocks` | [UID:000209][0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks](by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md) | MMX transparent weighted RGB565 block helper. |
| `AlphaBlendSpan16Blocks` | [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md) | Four-pixel weighted RGB565 block blender. |
| `HalfBlendSpan16Blocks` | [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md) | Four-pixel 50 percent RGB565 block blender. |
| `BlitTransparentShadow555` / `ApplyAlphaMap555` / `BlendRgb555Span` | [UID:0000YD][0x0045fa00-0x004604f4.Rgb555565BlitHelpers](by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md) | RGB555 transparent copy, alpha-map, weighted blend, and transparent weighted-blend helpers. |
| `BlitTransparentShadow565` / `ApplyAlphaMap565` | [UID:0000YD][0x0045fa00-0x004604f4.Rgb555565BlitHelpers](by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md), [UID:00020A][0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks](by-memory/0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md) | RGB565 transparent-shadow and alpha-map helpers consumed by RGB565 callbacks. |
| `ByteSpanFillRows` / copy/add/subtract byte helpers | [UID:00020B][0x00460d60-0x00460dee.ByteSpanFillRows](by-memory/0x00460d60-0x00460dee.ByteSpanFillRows.md), [UID:00020C][0x00460df0-0x00460e79.ByteSpanCopyRows](by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md), [UID:00020D][0x00460e80-0x00460f09.ByteSpanAddRows](by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md), [UID:00020E][0x00460f10-0x00460f99.ByteSpanSubtractRows](by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md) | Byte alpha-mask/span helpers with scalar tails and eight-byte block helpers. |
| `ByteSpanFill8Blocks` / copy/add/subtract block helpers | [UID:00020F][0x00460fa0-0x00460ffe.ByteSpanFill8Blocks](by-memory/0x00460fa0-0x00460ffe.ByteSpanFill8Blocks.md), [UID:00020G][0x00461000-0x0046104b.ByteSpanCopy8Blocks](by-memory/0x00461000-0x0046104b.ByteSpanCopy8Blocks.md), [UID:00020H][0x00461050-0x0046109e.ByteSpanAdd8Blocks](by-memory/0x00461050-0x0046109e.ByteSpanAdd8Blocks.md), [UID:00020I][0x004610a0-0x004610ee.ByteSpanSubtract8Blocks](by-memory/0x004610a0-0x004610ee.ByteSpanSubtract8Blocks.md) | Eight-byte block helpers for byte-span fill/copy/add/subtract operations. |
| `BlendRgb555_4C0710` | [UID:00016K][0x004c0710-0x004c076d.BlendRgb555](by-memory/0x004c0710-0x004c076d.BlendRgb555.md) | Single-pixel RGB555 weighted blend helper. |
| `BlendRgb565Pixel` | [UID:00016M][0x004c6050-0x004c60c7.BlendRgb565Pixel](by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md) | Single-pixel RGB565 weighted blend helper. |
| `BlendRgb565Pair_4C60D0` | [UID:00016N][0x004c60d0-0x004c6151.BlendRgb565Pair](by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md) | Packed two-pixel RGB565 weighted blend helper. |
| `MmxBlendWeightScratchData` | [UID:00028W][0x0067a7f0-0x0067a830.MmxBlendWeightScratchData](by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md) | Writable MMX source/inverse weight qwords used by the RGB555/RGB565 block helpers. |

## Ownership Decision

Keep these as free render helpers. Caller locality shows they are shared by drawing code in the `0x004bb...` and `0x004c...` render neighborhoods rather than belonging to any one pane or image library.

The `0x0045fa00-0x004604f4` helper island is a render-support cluster even though current generated output does not emit standalone recovered files for it. The `0x00460500-0x004610ee` span/block family follows immediately after that island and contains both modeled and raw helpers. The `0x004c6050` pixel/pair helpers are adjacent to the `CachedHashTable` utility range but belong here by behavior and callback use. `BlendRgb555_4C0710` is not adjacent to the RGB565 pixel/pair helpers, but caller evidence keeps it in the same 16-bit color math source group.

## Cross-References

- [UID:0000TV][AlphaBlendSpan16_00460500](by-item/AlphaBlendSpan16_00460500.md)
- [UID:0000YE][0x00460500-0x00460709.AlphaBlendSpan16](by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md)
- [UID:0000YD][0x0045fa00-0x004604f4.Rgb555565BlitHelpers](by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md)
- [UID:000206][0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw](by-memory/0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw.md)
- [UID:000207][0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw](by-memory/0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw.md)
- [UID:000208][0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks](by-memory/0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks.md)
- [UID:000209][0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks](by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md)
- [UID:0000TW][AlphaBlendSpan16Blocks_00460B00](by-item/AlphaBlendSpan16Blocks_00460B00.md)
- [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md)
- [UID:0000US][HalfBlendSpan16Blocks_00460C10](by-item/HalfBlendSpan16Blocks_00460C10.md)
- [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md)
- [UID:00020A][0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks](by-memory/0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md)
- [UID:00020B][0x00460d60-0x00460dee.ByteSpanFillRows](by-memory/0x00460d60-0x00460dee.ByteSpanFillRows.md)
- [UID:00020C][0x00460df0-0x00460e79.ByteSpanCopyRows](by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md)
- [UID:00020D][0x00460e80-0x00460f09.ByteSpanAddRows](by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md)
- [UID:00020E][0x00460f10-0x00460f99.ByteSpanSubtractRows](by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md)
- [UID:00020F][0x00460fa0-0x00460ffe.ByteSpanFill8Blocks](by-memory/0x00460fa0-0x00460ffe.ByteSpanFill8Blocks.md)
- [UID:00020G][0x00461000-0x0046104b.ByteSpanCopy8Blocks](by-memory/0x00461000-0x0046104b.ByteSpanCopy8Blocks.md)
- [UID:00020H][0x00461050-0x0046109e.ByteSpanAdd8Blocks](by-memory/0x00461050-0x0046109e.ByteSpanAdd8Blocks.md)
- [UID:00020I][0x004610a0-0x004610ee.ByteSpanSubtract8Blocks](by-memory/0x004610a0-0x004610ee.ByteSpanSubtract8Blocks.md)
- [UID:0000TZ][BlendRgb555_004C0710](by-item/BlendRgb555_004C0710.md)
- [UID:00016K][0x004c0710-0x004c076d.BlendRgb555](by-memory/0x004c0710-0x004c076d.BlendRgb555.md)
- [UID:0000U1][BlendRgb565Pixel_004C6050](by-item/BlendRgb565Pixel_004C6050.md)
- [UID:00016M][0x004c6050-0x004c60c7.BlendRgb565Pixel](by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md)
- [UID:0000U0][BlendRgb565Pair_004C60D0](by-item/BlendRgb565Pair_004C60D0.md)
- [UID:00016N][0x004c60d0-0x004c6151.BlendRgb565Pair](by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md)
- [UID:00028W][0x0067a7f0-0x0067a830.MmxBlendWeightScratchData](by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md)
- [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md)
- [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:0001QJ][client_old_redering_mode](by-meta/client_old_redering_mode.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- Previous documentation treated the render helper sequence after `0x00460709` as undocumented coverage gaps. It now assigns exact raw/modelled helper pages through `0x004610ee` and records the intervening `0xcc` spans as alignment padding. Evidence: IDA MCP `py_eval` byte/function audit on 2026-05-27 for `0x00460709-0x004610f0`.
- 2026-05-30: Grading changed from unevaluated `0/0` to `82/86`.
  - Before: page described the source family and linked the helper inventory but had no completion/confidence score.
  - After: score reflects strong ownership and behavior evidence for the low-level 16-bit software blend helpers, with remaining work in final original filename, exact source split, and cleanup of broader generated render callback artifacts.
  - Evidence: the page links exact by-memory rows for RGB555/RGB565 span, block, pixel, and byte-span helpers; `simroot_v2/render/SoftwareBlend16.cpp` now exists as a generated active view with high but incomplete file/ownership scores and visible generated-code artifacts.
