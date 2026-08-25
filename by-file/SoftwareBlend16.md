*** UID:0000NT | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SoftwareBlend16

## Status

- Confidence: final-audit range for RGB565/RGB555 helper behavior, stateless render-math grouping, UID0003ZP linkage, and current source order; exact original filename/header split remains unavailable.
- Proposed module: `render/SoftwareBlend16.cpp`. `Blend16.cpp` or a broader Surface/GrafPort file remain historical alternatives rejected by the current ownership and generated-route evidence.
- Current recovered sources: `source-3/simroot_v2/recovered/*Blend*00460500..004C60D0.cpp`

## 2026-08-17 EPFTileContext Cross-Translation-Unit Dependency

[UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md) remains owned by this SoftwareBlend16 source family and now exposes the exact formal H declaration `void ConvertRgb565ToRgb555Pixels(unsigned short *pixels, int pixelCount);`. [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md) is the sole direct caller at `0x0045857c`, so external linkage is required and file-local `static` linkage is rejected. The body and its observed noncanonical `0x7ff0` green-LSB/blue-MSB OR fold remain unchanged.

## File Role

This module groups low-level 16-bit software blending helpers. They do not own pane, asset-library, or DirectDraw state. They implement pixel, packed-pair, span, and four-pixel-block blend math used by hotter drawing routines.

The dominant current render path is RGB565. `GrafPort::UpdateRenderRegion` creates RGB565 DirectDraw surfaces, PCX/DIB helpers emit RGB565 buffers, and these helpers provide the matching pixel math. The retained RGB555 helper island at [UID:0000YD][0x0045fa00-0x004604f4.Rgb555565BlitHelpers](by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md) is now a non-emitting container; its exact child helpers [UID:0004BB][0x0045fa00-0x0045faa0.BlitTransparentShadow555](by-memory/0x0045fa00-0x0045faa0.BlitTransparentShadow555.md) through [UID:0004BL][0x00460410-0x004604f4.ApplyAlphaMap565](by-memory/0x00460410-0x004604f4.ApplyAlphaMap565.md) and the single-pixel `BlendRgb555` helper support the compatibility/old-format software callback family.

The larger software-render callback families live nearby but are not owned here as simple math helpers: [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md) and [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md) are Surface/render-dispatch implementations that consume this file's pixel/span helpers.

## MMX Source-Form Policy

2026-06-17 B001 source-quality execution resolved [UID:000209][0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks](by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md), [UID:00020A][0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks](by-memory/0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md), and [UID:00020C][0x00460df0-0x00460e79.ByteSpanCopyRows](by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md)/[UID:00020D][0x00460e80-0x00460f09.ByteSpanAddRows](by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md)/[UID:00020E][0x00460f10-0x00460f99.ByteSpanSubtractRows](by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md) as SoftwareBlend16-owned helpers with defensible source-facing signatures. 2026-06-30 B013 implementation supersedes the old broad "leave formal C++ blank until a family-wide source-form pass" blocker: current accepted SoftwareBlend16 precedent permits behavior-preserving C++ loop source for simple MMX-range helpers, target-local inline assembly where needed, and covered-by comments for helper-owned data ranges.

Rule 26 incorporation for the same B001 report records the following family-level decisions here instead of leaving them only in the research archive:

- The RGB565 MMX helpers and byte-span row helpers are stateless render primitives. They belong in this file even when their only direct caller is a higher-level draw path such as [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md).
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md), `Surface`, `GrafPort`, and the software-render callback families are consumer/dispatch contexts for these helpers, not direct source owners for the primitive math.
- [UID:00028W][0x0067a7f0-0x0067a830.MmxBlendWeightScratchData](by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md) records binary writable scratch qwords, not standalone source data declarations. Its eight qwords are helper-local source/inverse MMX weight-vector materialization cells for the RGB555/RGB565 block helpers; final SoftwareBlend16 source should compute those weights as local qword/`__m64` temporaries or inline-assembly operands inside [UID:0004BG][0x0045fff0-0x00460111.BlendTransparentRgb555Blocks](by-memory/0x0045fff0-0x00460111.BlendTransparentRgb555Blocks.md), [UID:0004BH][0x00460120-0x0046022f.BlendRgb555Blocks](by-memory/0x00460120-0x0046022f.BlendRgb555Blocks.md), [UID:000209][0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks](by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md), and [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md) helper bodies while preserving the binary scratch facts in documentation.
- [UID:0002OO][0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants](by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md) owns the RGB565 qword masks used by the block family. Future source-facing names should distinguish red/blue masks, green masks, and alpha-map clamp masks rather than collapsing them into anonymous `qword_` labels.
- The remaining unresolved MMX block helper bodies should use one coherent source style when each is implemented; unpopulated formal C++ on those older sibling targets is a target-specific source-form state, not evidence against SoftwareBlend16 ownership.
- 2026-06-29 B002 implementation distinguishes [UID:0000YE][0x00460500-0x00460709.AlphaBlendSpan16](by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md) from the MMX block bodies: the `AlphaBlendSpan16` dispatcher/scalar-tail body can emit ordinary first-draft C++ with file-local prototypes for `AlphaBlendSpan16Blocks` and `HalfBlendSpan16Blocks`.
- 2026-06-29 B003 implementation resolves [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md) as the first populated MMX block body in this subgroup. Its formal C++ uses MSVC x86 inline assembly, local qword RGB565 masks for the binary constants at `0x00610ea8/0x00610eb0`, and local qword source/inverse weight vectors for the binary scratch cells at `0x0067a820/0x0067a828`. The binary shows `pushaw`/`popaw`; the first-draft source documents its intentional `pushad`/`popad` register-preservation approximation and keeps `emms`.
- 2026-06-29 B006 implementation resolves [UID:000208][0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks](by-memory/0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks.md) as an independently emitting MMX block body. It remains part of this SoftwareBlend16 helper family and now emits target-local MSVC x86 inline assembly with local qword constants for the RGB565 transparent-shadow mask `0xf7def7def7def7de` and sentinel-one comparator `0x0001000100010001`. This does not require waiting for [UID:000209][0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks](by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md), [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md), [UID:00020A][0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks](by-memory/0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md), or the byte-span block helpers because UID000208 has no writable scratch dependency and its caller/constant behavior is closed.
- 2026-06-29 B002 implementation resolves [UID:00016K][0x004c0710-0x004c076d.BlendRgb555](by-memory/0x004c0710-0x004c076d.BlendRgb555.md) as an ordinary scalar RGB555 pixel helper that can emit independently of the MMX source-form policy. Its first-draft C++ uses the inferred free helper `unsigned short __cdecl BlendRgb555(unsigned short firstPixel, unsigned short secondPixel, unsigned char firstWeight32)`, preserves the binary `0x03e0`/`0x7c1f` lane masks and `0..32` fixed-point weights, and keeps exact original symbol/header uncertainty as a score cap only.
- 2026-06-29 B001 implementation resolves the former broad [UID:0000YD][0x0045fa00-0x004604f4.Rgb555565BlitHelpers](by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md) row as a non-emitting container and moves emission to exact child pages [UID:0004BB][0x0045fa00-0x0045faa0.BlitTransparentShadow555](by-memory/0x0045fa00-0x0045faa0.BlitTransparentShadow555.md) through [UID:0004BL][0x00460410-0x004604f4.ApplyAlphaMap565](by-memory/0x00460410-0x004604f4.ApplyAlphaMap565.md). Wrappers/spans emit ordinary first-draft C++; RGB555 block helpers emit behavior-preserving four-pixel C++ with target-local masks and local source/inverse weight calculations, preserving the binary MMX facts without requiring standalone scratch globals.
- 2026-06-30 B013 implementation fills the remaining current SoftwareBlend16 empty-emitter family. The by-item mirrors [UID:0000TW][AlphaBlendSpan16Blocks_00460B00](by-item/AlphaBlendSpan16Blocks_00460B00.md), [UID:0000TV][AlphaBlendSpan16_00460500](by-item/AlphaBlendSpan16_00460500.md), [UID:0000TZ][BlendRgb555_004C0710](by-item/BlendRgb555_004C0710.md), [UID:0000U0][BlendRgb565Pair_004C60D0](by-item/BlendRgb565Pair_004C60D0.md), [UID:0000U1][BlendRgb565Pixel_004C6050](by-item/BlendRgb565Pixel_004C6050.md), and [UID:0000US][HalfBlendSpan16Blocks_00460C10](by-item/HalfBlendSpan16Blocks_00460C10.md) now emit target-specific covered-by comments rather than duplicate canonical by-memory bodies.
- The raw helper starts [UID:000206][0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw](by-memory/0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw.md), [UID:000207][0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw](by-memory/0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw.md), and [UID:00020B][0x00460d60-0x00460dee.ByteSpanFillRows](by-memory/0x00460d60-0x00460dee.ByteSpanFillRows.md) remain raw/no-IDA-function starts with no start xrefs, but B013 resolved that as a confidence cap rather than a no-code blocker because each has a prologue/return-bounded body, exact padding, and an internal call into the sibling block helper family.
- [UID:000209][0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks](by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md), [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md), [UID:00020A][0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks](by-memory/0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md), and [UID:00020F][0x00460fa0-0x00460ffe.ByteSpanFill8Blocks](by-memory/0x00460fa0-0x00460ffe.ByteSpanFill8Blocks.md)/[UID:00020G][0x00461000-0x0046104b.ByteSpanCopy8Blocks](by-memory/0x00461000-0x0046104b.ByteSpanCopy8Blocks.md)/[UID:00020H][0x00461050-0x0046109e.ByteSpanAdd8Blocks](by-memory/0x00461050-0x0046109e.ByteSpanAdd8Blocks.md)/[UID:00020I][0x004610a0-0x004610ee.ByteSpanSubtract8Blocks](by-memory/0x004610a0-0x004610ee.ByteSpanSubtract8Blocks.md) now emit behavior-preserving source-level block helper C++ that records the exact MMX semantics without requiring standalone scratch globals.
- [UID:00016M][0x004c6050-0x004c60c7.BlendRgb565Pixel](by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md) and [UID:00016N][0x004c60d0-0x004c6151.BlendRgb565Pair](by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md) now emit scalar RGB565 helper C++ following the accepted [UID:00016K][0x004c0710-0x004c076d.BlendRgb555](by-memory/0x004c0710-0x004c076d.BlendRgb555.md) precedent.
- [UID:0002OO][0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants](by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md) now emits a formal no-standalone-source comment. Current MCP xrefs show the qwords are consumed only by SoftwareBlend16 helper bodies, so final source carries them as helper-local constants or equivalent scalar immediates rather than a file-scope table declaration.

## 2026-06-30 Empty-Emitter Family Resolution

B013 rechecked the current generated file `auto-generated/NexusTK/render/SoftwareBlend16.cpp` at `validator-command-id: 000000001629`, `validator-refreshed-at: 2026-06-29T23:45:30-04:00`. At that point the file still contained 22 SoftwareBlend16 empty markers: six by-item duplicate aliases, thirteen span/MMX/byte helper rows, two scalar RGB565 helpers, and the read-only constants row. All 22 rows already had `CANONICAL_OWNER:0000NT`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NT`, and blank emitter position, so no owner/emitter metadata repair was needed.

Current MCP database `supervisor_resume_20260629` was available during the accepted report. `idb_list` showed the active `NexusTK.exe.i64` worker session with `is_analyzing:false`, and `server_health` reported `status:"ok"` with Hex-Rays and strings cache ready. Targeted `lookup_funcs`, `xrefs_to`, `callees`, `get_bytes`, `decompile`, and `disasm` calls established the following implementation facts:

- Modeled helper boundaries: `sub_4609E0` at `0x004609e0-0x00460af9`, `sub_460C10` at `0x00460c10-0x00460c8c`, `sub_460C90` at `0x00460c90-0x00460d51`, `sub_460DF0`/`sub_460E80`/`sub_460F10` at the byte row wrappers, `sub_460FA0`/`sub_461000`/`sub_461050`/`sub_4610A0` at the byte block helpers, and `sub_4C6050`/`sub_4C60D0` at the scalar RGB565 helpers.
- Raw helper boundaries: `0x00460710`, `0x004607e0`, and `0x00460d60` are not IDA functions and have no raw-start xrefs, but each is a real source-authored body with prologue/return, exact sibling calls, and `0xcc` boundary padding.
- Raw UID000206 calls UID0000YG at `0x0046073e`; raw UID000207 calls UID000209 at `0x00460818`; raw UID00020B calls UID00020F at `0x00460d8e`.
- The byte wrappers call their block helpers exactly once each: UID00020C -> UID00020G at `0x00460e1f`, UID00020D -> UID00020H at `0x00460eaf`, and UID00020E -> UID00020I at `0x00460f3f`.
- UID00016M has 17 RGB565 callback-family callers and UID00016N has 4 callers; both have no callees or global state.
- UID0002OO qwords have data xrefs only from SoftwareBlend16 helper bodies and do not prove an independent source-owned file-scope table.

B013 explicitly rejected keeping the remaining rows blank, duplicating by-item bodies, forcing every MMX range into inline assembly, emitting UID0002OO as a standalone table, or treating raw no-start-xref helpers as no-code. That pass established the historical `88/90` score after the empty-emitter family was resolved. The later UID0003ZP closure below raises the current file score to `90/92`; exact original helper spellings, declaration-header placement, and original file name remain reconstructed rather than symbol-proven.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `AlphaBlendSpan16` | [UID:0000YE][0x00460500-0x00460709.AlphaBlendSpan16](by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md) | Row/span RGB565 alpha blend dispatcher. |
| `Rgb565HalfBlendSpanRaw` | [UID:000206][0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw](by-memory/0x00460710-0x004607e0.Rgb565HalfBlendSpanRaw.md) | Raw RGB565 half-blend row/span helper that shares `HalfBlendSpan16Blocks`. |
| `Rgb565TransparentAlphaBlendSpanRaw` | [UID:000207][0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw](by-memory/0x004607e0-0x0046093c.Rgb565TransparentAlphaBlendSpanRaw.md) | Raw transparent weighted RGB565 row/span helper. |
| `BlitTransparentShadow565MmxBlocks` | [UID:000208][0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks](by-memory/0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks.md) | MMX RGB565 transparent-shadow block helper called by `BlitTransparentShadow565`. |
| `Rgb565TransparentAlphaBlendMmxBlocks` | [UID:000209][0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks](by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md) | MMX transparent weighted RGB565 block helper. |
| `AlphaBlendSpan16Blocks` | [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md) | Four-pixel weighted RGB565 block blender; first-draft body emits as MSVC x86 inline assembly with local qword masks/scratch. |
| `HalfBlendSpan16Blocks` | [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md) | Four-pixel 50 percent RGB565 block blender. |
| `BlitTransparentShadow555` | [UID:0004BB][0x0045fa00-0x0045faa0.BlitTransparentShadow555](by-memory/0x0045fa00-0x0045faa0.BlitTransparentShadow555.md) | RGB555 transparent copy/shadow wrapper and scalar tail with formal first-draft C++. |
| `ApplyAlphaMap555` | [UID:0004BC][0x0045faa0-0x0045fb74.ApplyAlphaMap555](by-memory/0x0045faa0-0x0045fb74.ApplyAlphaMap555.md) | RGB555 in-place alpha-byte map wrapper and scalar tail with formal first-draft C++. |
| `BlendRgb555Span` | [UID:0004BD][0x0045fb80-0x0045fd65.BlendRgb555Span](by-memory/0x0045fb80-0x0045fd65.BlendRgb555Span.md) | RGB555 weighted span wrapper with half-blend fast path and formal first-draft C++. |
| `BlendTransparentRgb555Span` | [UID:0004BE][0x0045fe40-0x0045ff5c.BlendTransparentRgb555Span](by-memory/0x0045fe40-0x0045ff5c.BlendTransparentRgb555Span.md) | RGB555 transparent weighted span wrapper and scalar tail with formal first-draft C++. |
| `BlitTransparentShadow555Blocks` | [UID:0004BF][0x0045ff60-0x0045ffe9.BlitTransparentShadow555Blocks](by-memory/0x0045ff60-0x0045ffe9.BlitTransparentShadow555Blocks.md) | Four-pixel RGB555 transparent-shadow block helper with formal source-level C++. |
| `BlendTransparentRgb555Blocks` | [UID:0004BG][0x0045fff0-0x00460111.BlendTransparentRgb555Blocks](by-memory/0x0045fff0-0x00460111.BlendTransparentRgb555Blocks.md) | Four-pixel transparent weighted RGB555 block helper using local source/inverse weights. |
| `BlendRgb555Blocks` | [UID:0004BH][0x00460120-0x0046022f.BlendRgb555Blocks](by-memory/0x00460120-0x0046022f.BlendRgb555Blocks.md) | Four-pixel weighted RGB555 block helper using local source/inverse weights. |
| `HalfBlendRgb555Blocks` | [UID:0004BI][0x00460230-0x004602a2.HalfBlendRgb555Blocks](by-memory/0x00460230-0x004602a2.HalfBlendRgb555Blocks.md) | Four-pixel 50 percent RGB555 block helper with average/carry masks. |
| `ApplyAlphaMap555Blocks` | [UID:0004BJ][0x004602b0-0x0046036b.ApplyAlphaMap555Blocks](by-memory/0x004602b0-0x0046036b.ApplyAlphaMap555Blocks.md) | Four-pixel RGB555 alpha-byte map helper with formal source-level C++. |
| `ConvertRgb565ToRgb555Pixels` | [UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md) | Shared external/free in-place 16-bit compatibility transform; the only caller is `EPFTileContext::NormalizePostDecodePixels`, and the exact `0x7ff0` mask OR-folds source green bit 5 with source blue bit 4 rather than performing a canonical repack. |
| `BlitTransparentShadow565` | [UID:0004BK][0x00460370-0x00460410.BlitTransparentShadow565](by-memory/0x00460370-0x00460410.BlitTransparentShadow565.md), [UID:000208][0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks](by-memory/0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks.md) | RGB565 transparent-shadow wrapper/scalar tail consumed by RGB565 callbacks; bulk block body remains UID000208. |
| `ApplyAlphaMap565` | [UID:0004BL][0x00460410-0x004604f4.ApplyAlphaMap565](by-memory/0x00460410-0x004604f4.ApplyAlphaMap565.md), [UID:00020A][0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks](by-memory/0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md) | RGB565 alpha-map wrapper/scalar tail consumed by RGB565 callbacks; bulk block body remains UID00020A. |
| `SoftwareBlend16ReadOnlyConstants` | [UID:0002OO][0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants](by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md) | RGB555/RGB565 qword mask constants used by the MMX/block helper paths. |
| `ByteSpanFillRows` / copy/add/subtract byte helpers | [UID:00020B][0x00460d60-0x00460dee.ByteSpanFillRows](by-memory/0x00460d60-0x00460dee.ByteSpanFillRows.md), [UID:00020C][0x00460df0-0x00460e79.ByteSpanCopyRows](by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md), [UID:00020D][0x00460e80-0x00460f09.ByteSpanAddRows](by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md), [UID:00020E][0x00460f10-0x00460f99.ByteSpanSubtractRows](by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md) | Byte alpha-mask/span helpers with scalar tails and eight-byte block helpers. |
| `ByteSpanFill8Blocks` / copy/add/subtract block helpers | [UID:00020F][0x00460fa0-0x00460ffe.ByteSpanFill8Blocks](by-memory/0x00460fa0-0x00460ffe.ByteSpanFill8Blocks.md), [UID:00020G][0x00461000-0x0046104b.ByteSpanCopy8Blocks](by-memory/0x00461000-0x0046104b.ByteSpanCopy8Blocks.md), [UID:00020H][0x00461050-0x0046109e.ByteSpanAdd8Blocks](by-memory/0x00461050-0x0046109e.ByteSpanAdd8Blocks.md), [UID:00020I][0x004610a0-0x004610ee.ByteSpanSubtract8Blocks](by-memory/0x004610a0-0x004610ee.ByteSpanSubtract8Blocks.md) | Eight-byte block helpers for byte-span fill/copy/add/subtract operations. |
| `BlendRgb555` | [UID:00016K][0x004c0710-0x004c076d.BlendRgb555](by-memory/0x004c0710-0x004c076d.BlendRgb555.md) | Single-pixel RGB555 weighted blend helper; emits ordinary scalar first-draft C++ independent of the MMX block-helper policy. |
| `BlendRgb565Pixel` | [UID:00016M][0x004c6050-0x004c60c7.BlendRgb565Pixel](by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md) | Single-pixel RGB565 weighted blend helper. |
| `BlendRgb565Pair_4C60D0` | [UID:00016N][0x004c60d0-0x004c6151.BlendRgb565Pair](by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md) | Packed two-pixel RGB565 weighted blend helper. |
| `MmxBlendWeightScratchData` | [UID:00028W][0x0067a7f0-0x0067a830.MmxBlendWeightScratchData](by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md) | Writable MMX source/inverse weight qwords used by the RGB555/RGB565 block helpers. |

## Ownership Decision

Keep these as free render helpers. Caller locality shows they are shared by drawing code in the `0x004bb...` and `0x004c...` render neighborhoods rather than belonging to any one pane or image library.

The `0x0045fa00-0x004604f4` helper island is a render-support cluster. UID0000YD is now only the non-emitting container for that island; exact children [UID:0004BB][0x0045fa00-0x0045faa0.BlitTransparentShadow555](by-memory/0x0045fa00-0x0045faa0.BlitTransparentShadow555.md) through [UID:0004BL][0x00460410-0x004604f4.ApplyAlphaMap565](by-memory/0x00460410-0x004604f4.ApplyAlphaMap565.md) are the SoftwareBlend16-owned emitters. The `0x00460500-0x004610ee` span/block family follows immediately after that island and contains both modeled and raw helpers. The `0x004c6050` pixel/pair helpers are adjacent to the `CachedHashTable` utility range but belong here by behavior and callback use. `BlendRgb555` at [UID:00016K][0x004c0710-0x004c076d.BlendRgb555](by-memory/0x004c0710-0x004c076d.BlendRgb555.md) is not adjacent to the RGB565 pixel/pair helpers, but caller evidence keeps it in the same 16-bit color math source group; its compatibility-render callers are consumers, not direct source owners.

[UID:0002OO][0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants](by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md) is attached here even though it is physically adjacent to Ranking and AboveFrame `.rdata`. Its qword masks are referenced by the RGB555/RGB565 block helpers owned by this file, while the neighboring [UID:00024R][0x006104f4-0x00610ed8.MiniMapRankingReadOnlyData](by-memory/0x006104f4-0x00610ed8.MiniMapRankingReadOnlyData.md) row is only the physical container.

[UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md) is physically in the GrafPort/text-support neighborhood, but its behavior and one-caller route make SoftwareBlend16 the better direct source owner. It is a leaf, no-global, pointer/count pixel transform, and its only caller [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md) gates the call on the Surface RGB565 flag. `Surface` owns the flag; `EPFTileContext` owns the receiver method; this file owns the stateless conversion math. Because the method caller is emitted through a separate EPFTileContext translation unit, UID0003ZP needs external/shared render-private linkage and a declaration visible to that source; `static` file linkage is rejected under the accepted route.

## UID0003ZP Source Closure

- Live MCP on evidence-time session `e98ecbb2` confirms UID0003ZP as one 49-byte, 21-instruction free `__cdecl` leaf at `[0x004bb0e0,0x004bb111)`, with one direct caller at `0x0045857c`, no callees, no strings, and no global, callback-table, data, receiver, or allocation route.
- The caller supplies `pixelData` and signed `(right-left)*(bottom-top)`. Valid image-loader geometry is nonnegative; zero returns before pointer use. The target intentionally tests nonzero, so malformed negative counts retain their observed 32-bit countdown behavior rather than being rewritten to a positive-only source loop.
- The exact body expression is `(pixel & 0x001f) | ((pixel >> 1) & 0x7ff0)`. Source green bit 5 and source blue bit 4 collide through OR at destination bit 4; a canonical `0x7fe0` rewrite is behaviorally different and is rejected.
- JPF, raw JPEG, and PNG producers pack exact RGB565 primary words before UID000200; PNG keeps alpha in a separate plane; ZPF/FPF copies the 16-bit source words. Surface D5 distinguishes RGB565-capable output, so the zero-flag call route establishes compatibility conversion direction.
- Generated SoftwareBlend16 order places the blank-position UID0003ZP definition exactly once after UID00020I and before UID00016K. The address distance from the main helper island does not outweigh this source route, while EPFTileContext, Surface, callback-table, GrafPort, DAT, and a new one-function file all remain weaker direct-owner alternatives.

## Corrected Assignment Gate

This page clears the corrected direct-parent gate for stateless 16-bit blend/math helpers only: current completion/confidence are `90/92`, the page has a valid `NexusTK/render/` reconstruction path, and the proposed contents inventory links exact by-memory helpers for RGB555/RGB565 span, block, pixel, byte-span, and compatibility-conversion primitives. Historical `86/88` and `88/90` states remain in dated change records rather than describing current metadata.

The gate support is strongest for [UID:00016M][0x004c6050-0x004c60c7.BlendRgb565Pixel](by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md) and [UID:00016N][0x004c60d0-0x004c6151.BlendRgb565Pair](by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md): both are pure no-global RGB565 arithmetic helpers, are adjacent, and are called by the RGB565 callback family as reusable math. This does not make `SoftwareBlend16` the direct parent for the broader software-render callback bodies, which remain Surface/render-dispatch ownership candidates until their own pages and parent candidates clear the gate.

## Evidence Notes

- 2026-06-16 Agent-B001 raw-helper audit: `0x00460710`, `0x004607e0`, and `0x00460d60` remain reconstructable SoftwareBlend16 helpers even though raw PE rel32/VA/RVA scans found no direct static references to their starts. 2026-06-30 B013 supersedes the old blank-C++ conclusion: the helpers are retained source-authored span/block support code, and the raw no-start-xref fact is now documented as a confidence cap while formal C++ is emitted on each exact row.
- Live IDA MCP on 2026-06-07 reconfirmed [UID:00016N][0x004c60d0-0x004c6151.BlendRgb565Pair](by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md) as `sub_4C60D0`, an exact `0x81`-byte no-callee/no-data-reference packed RGB565 helper with callers from the RGB565 line, sprite blit, and fill callbacks.
- The same check reconfirmed [UID:00016M][0x004c6050-0x004c60c7.BlendRgb565Pixel](by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md) as the adjacent single-pixel RGB565 helper with seventeen callback-family callers and no data references.
- Byte review on 2026-06-07 reconfirmed `0xcc` alignment around the pixel/pair helper island: `0x004c6044-0x004c6050`, `0x004c60c7-0x004c60d0`, and `0x004c6151-0x004c6160`.
- The by-memory pages now document complementary scalar and packed-pair 0..32 weighted blend formulas, so this source-root page is strong enough to serve as the direct parent for those helpers while staying conservative on final original file naming.
- 2026-07-14 B001 UID0003ZP reanalysis adds exact target bytes/hashes/CFG/ABI, decoder direction, Surface polarity, noncanonical mask semantics, signed-count contract, one-caller closure, and current generated source order. This closes the target-specific public/static and source-placement uncertainty to an external/shared render-private helper while preserving unavailable original lexical artifacts as the remaining score cap.

## UID0002V6 Negative-Owner And Source-Shape Contrast

[UID:0002V6][0x0061a920-0x0061aac0.SoftwareRenderMaskConstants](by-memory/0x0061a920-0x0061aac0.SoftwareRenderMaskConstants.md) is related arithmetic evidence but is not a SoftwareBlend16-owned source table. Its exact 416 bytes form 26 aligned splats for RGB555/RGB565 masks, fixed-point weights 16/32, and equal-channel fade deltas. All 142 references close inside five stateful Surface callbacks; no SoftwareBlend16 helper owns or indexes the pool, and the other 390 addresses have zero refs.

That topology differs from [UID:0002OO][0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants](by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md) and UID00028W, whose masks/scratch storage are directly used by this file's stateless helper family. UID0002V6 has no base address identity, lookup index, walker, writable alias, or reusable helper-global contract. Its blocks are compiler materialization of scalar expressions in UID0002TB, UID0002YF, UID0002YJ, UID0002TF, and UID0002YO. Source reconstruction therefore covers them through `Surface.cpp` callback bodies and emits no standalone vector table or header declaration from this file. SoftwareBlend16 remains semantic support for the arithmetic only; its existing `90/92` metadata and formals are unchanged.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `90` | Exact helper-family inventory, source-form policy, ownership boundaries, generated route, and UID0003ZP range/behavior/linkage/order are documented while all unrelated MMX/scalar history remains preserved. Exact original filename/header artifacts remain unavailable. |
| Confidence `92` | Current binary, caller, producer-format, Surface polarity, generated order, and established family semantics consistently support SoftwareBlend16 ownership. Original object/header names are inferred rather than symbol-proven. |

## Cross-References

- [UID:0000TV][AlphaBlendSpan16_00460500](by-item/AlphaBlendSpan16_00460500.md)
- [UID:0000YE][0x00460500-0x00460709.AlphaBlendSpan16](by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md)
- [UID:0000YD][0x0045fa00-0x004604f4.Rgb555565BlitHelpers](by-memory/0x0045fa00-0x004604f4.Rgb555565BlitHelpers.md)
- [UID:0004BB][0x0045fa00-0x0045faa0.BlitTransparentShadow555](by-memory/0x0045fa00-0x0045faa0.BlitTransparentShadow555.md)
- [UID:0004BC][0x0045faa0-0x0045fb74.ApplyAlphaMap555](by-memory/0x0045faa0-0x0045fb74.ApplyAlphaMap555.md)
- [UID:0004BD][0x0045fb80-0x0045fd65.BlendRgb555Span](by-memory/0x0045fb80-0x0045fd65.BlendRgb555Span.md)
- [UID:0004BE][0x0045fe40-0x0045ff5c.BlendTransparentRgb555Span](by-memory/0x0045fe40-0x0045ff5c.BlendTransparentRgb555Span.md)
- [UID:0004BF][0x0045ff60-0x0045ffe9.BlitTransparentShadow555Blocks](by-memory/0x0045ff60-0x0045ffe9.BlitTransparentShadow555Blocks.md)
- [UID:0004BG][0x0045fff0-0x00460111.BlendTransparentRgb555Blocks](by-memory/0x0045fff0-0x00460111.BlendTransparentRgb555Blocks.md)
- [UID:0004BH][0x00460120-0x0046022f.BlendRgb555Blocks](by-memory/0x00460120-0x0046022f.BlendRgb555Blocks.md)
- [UID:0004BI][0x00460230-0x004602a2.HalfBlendRgb555Blocks](by-memory/0x00460230-0x004602a2.HalfBlendRgb555Blocks.md)
- [UID:0004BJ][0x004602b0-0x0046036b.ApplyAlphaMap555Blocks](by-memory/0x004602b0-0x0046036b.ApplyAlphaMap555Blocks.md)
- [UID:0004BK][0x00460370-0x00460410.BlitTransparentShadow565](by-memory/0x00460370-0x00460410.BlitTransparentShadow565.md)
- [UID:0004BL][0x00460410-0x004604f4.ApplyAlphaMap565](by-memory/0x00460410-0x004604f4.ApplyAlphaMap565.md)
- [UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md)
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
- [UID:0002OO][0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants](by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md)
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

- 2026-07-24 B003 UID0002V6 support synchronization: preserved `90/92`, ownership, helper inventory, and all formals; added the exact negative-owner contrast between this file's stateless helper storage and Surface's 416-byte compiler literal pool, including the five-consumer/142-ref covered-by route.

- 2026-07-14 B001 UID0003ZP source-quality implementation callback:
  - Raised the file root from `88/90` to `90/92` while preserving `NexusTK/render/`, FILE ownership, all existing helper-family/MMX content, and historical records.
  - Added UID0003ZP's exact one-caller external linkage, blank-position generated order, signed-count contract, decoder/Surface conversion direction, and noncanonical `0x7ff0` green-LSB/blue-MSB OR-fold evidence.
  - Rejected file-local `static`, canonical-mask cleanup, EPFTileContext/Surface/callback/GrafPort/DAT ownership, and a new one-function source file without changing any unrelated helper route or formal body.

- Previous documentation treated the render helper sequence after `0x00460709` as undocumented coverage gaps. It now assigns exact raw/modelled helper pages through `0x004610ee` and records the intervening `0xcc` spans as alignment padding. Evidence: IDA MCP `py_eval` byte/function audit on 2026-05-27 for `0x00460709-0x004610f0`.
- 2026-05-30: Grading changed from unevaluated `0/0` to `82/86`.
  - Before: page described the source family and linked the helper inventory but had no completion/confidence score.
  - After: score reflects strong ownership and behavior evidence for the low-level 16-bit software blend helpers, with remaining work in final original filename, exact source split, and cleanup of broader generated render callback artifacts.
  - Evidence: the page links exact by-memory rows for RGB555/RGB565 span, block, pixel, and byte-span helpers; `simroot_v2/render/SoftwareBlend16.cpp` now exists as a generated active view with high but incomplete file/ownership scores and visible generated-code artifacts.
- 2026-06-07 A006 Batch005 direct-parent gate pass:
  - Changed completion/confidence from `82/86` to `86/88`.
  - Evidence: live IDA MCP reconfirmed the adjacent RGB565 pixel/pair helper island, [UID:00016M][0x004c6050-0x004c60c7.BlendRgb565Pixel](by-memory/0x004c6050-0x004c60c7.BlendRgb565Pixel.md) is already documented and parented at `90/92`, and [UID:00016N][0x004c60d0-0x004c6151.BlendRgb565Pair](by-memory/0x004c60d0-0x004c6151.BlendRgb565Pair.md) now documents exact boundaries, no callees, no data refs, caller sites, padding, and packed RGB565 blend math.
  - Assignment scope: parent is valid for stateless blend/math helpers such as `BlendRgb565Pair`; broader callback bodies remain under Surface/render-dispatch review and are not assigned here.
- 2026-06-07 A004 Batch010 parent sync:
  - Added [UID:0002OO][0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants](by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md) to the proposed contents and cross-references.
  - Evidence: the constants page records all RGB555/RGB565 qword masks and their render-helper data refs, and the direct parent gate is satisfied by child `86/90` plus this file root at `86/88`.
- 2026-06-17 B001 source-quality execution:
  - Added the SoftwareBlend16-wide MMX source-form policy after resolving signatures and ownership for [UID:000209][0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks](by-memory/0x004609e0-0x00460af9.Rgb565TransparentAlphaBlendMmxBlocks.md), [UID:00020A][0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks](by-memory/0x00460c90-0x00460d51.Rgb565AlphaMapMmxBlocks.md), [UID:00020C][0x00460df0-0x00460e79.ByteSpanCopyRows](by-memory/0x00460df0-0x00460e79.ByteSpanCopyRows.md), [UID:00020D][0x00460e80-0x00460f09.ByteSpanAddRows](by-memory/0x00460e80-0x00460f09.ByteSpanAddRows.md), and [UID:00020E][0x00460f10-0x00460f99.ByteSpanSubtractRows](by-memory/0x00460f10-0x00460f99.ByteSpanSubtractRows.md).
  - 2026-06-30 B013 supersedes the old blank-C++ family-pass blocker. The affected child pages are above the current numerical/emitter gate and now carry formal C++ or target-specific covered-by comments while preserving exact MMX/byte arithmetic evidence.
- 2026-06-19 B005 conversion-helper incorporation:
  - Added [UID:0003ZP][0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels](by-memory/0x004bb0e0-0x004bb111.ConvertRgb565ToRgb555Pixels.md) as a SoftwareBlend16-owned stateless RGB565/RGB555 helper.
  - Evidence: B005 confirmed exact `0x004bb0e0-0x004bb111` bytes, SHA1 `6b968b637368a4111005d0c0fee28cf2345cd216`, one caller [UID:000200][0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels](by-memory/0x00458560-0x00458585.EPFTileContextNormalizePostDecodePixels.md) at `0x0045857c`, no callees/data refs, and the in-place `(pixel & 0x001f) | ((pixel >> 1) & 0x7ff0)` formula. The helper is kept separate from Surface callback-table ownership because it is not a table target.
- 2026-06-29 B002 implementation callback:
  - Updated the MMX source-form policy so the old empty-generated-file wording no longer blocks [UID:0000YE][0x00460500-0x00460709.AlphaBlendSpan16](by-memory/0x00460500-0x00460709.AlphaBlendSpan16.md)'s dispatcher/scalar-tail C++.
  - At the time, [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md) and [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md) still required their own inline-assembly/intrinsic representation before body emission. The [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md) part of that historical note is superseded by the B003 callback below; [UID:0000YG][0x00460c10-0x00460c8c.HalfBlendSpan16Blocks](by-memory/0x00460c10-0x00460c8c.HalfBlendSpan16Blocks.md) remains outside this callback.
- 2026-06-29 B003 implementation callback:
  - Updated the MMX source-form policy for [UID:0000YF][0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks](by-memory/0x00460b00-0x00460c0a.AlphaBlendSpan16Blocks.md): the helper no longer remains a blank formal-body emitter and now uses first-draft MSVC x86 inline assembly in the target page.
  - Recorded the accepted local source policy for UID0000YF: qword RGB565 masks from [UID:0002OO][0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants](by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md) and weight scratch from [UID:00028W][0x0067a7f0-0x0067a830.MmxBlendWeightScratchData](by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md) are folded into local qword variables for this first-draft C++.
  - Parent metadata remains `86/88`; the callback changes the UID0000YF child emitter and policy detail, not the broader unresolved sibling-helper population.
- 2026-06-29 B006 implementation callback:
  - Updated the MMX source-form policy for [UID:000208][0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks](by-memory/0x00460940-0x004609d3.BlitTransparentShadow565MmxBlocks.md): the helper no longer remains a blank formal-body emitter and now uses first-draft MSVC x86 inline assembly in the target page.
  - Recorded the accepted local source policy for UID000208: the read-only qword constants from [UID:0002OO][0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants](by-memory/0x00610e38-0x00610ed8.SoftwareBlend16ReadOnlyConstants.md) at `0x00610e88` and `0x00610e90` are folded into local qword variables for this first-draft C++ while remaining documented as SoftwareBlend16-owned binary constants.
  - Parent metadata remains `86/88`; the callback changes the UID000208 child emitter and policy detail, not the broader unresolved sibling-helper population.
- 2026-06-29 B002 UID00016K implementation callback:
  - Added the scalar-helper note for [UID:00016K][0x004c0710-0x004c076d.BlendRgb555](by-memory/0x004c0710-0x004c076d.BlendRgb555.md): this RGB555 single-pixel helper now emits ordinary first-draft C++ and is not blocked by the SoftwareBlend16 MMX source-form policy.
  - Updated the proposed contents and ownership notes from the old `BlendRgb555_4C0710` label to the accepted source-facing `BlendRgb555` name while preserving that exact original symbol/header placement remains a score cap on the target, not a parent metadata change.
- 2026-06-29 B012 implementation callback:
  - Updated the whole-[UID:00028W][0x0067a7f0-0x0067a830.MmxBlendWeightScratchData](by-memory/0x0067a7f0-0x0067a830.MmxBlendWeightScratchData.md) scratch policy: the eight writable binary qwords remain documented as SoftwareBlend16 evidence, but they should not emit as standalone globals in generated source.
  - Accepted source-form rule: RGB555/RGB565 block helpers should compute the corresponding source/inverse weight vectors as local qword/`__m64` temporaries or inline-assembly operands inside their helper bodies.
  - Parent metadata remains `86/88`; the callback changes the UID00028W child emitter/source-disposition detail, not this file's broader ownership score.
- 2026-06-29 B001 UID0000YD implementation callback:
  - Replaced the broad UID0000YD proposed-contents rows with exact child helpers [UID:0004BB][0x0045fa00-0x0045faa0.BlitTransparentShadow555](by-memory/0x0045fa00-0x0045faa0.BlitTransparentShadow555.md) through [UID:0004BL][0x00460410-0x004604f4.ApplyAlphaMap565](by-memory/0x00460410-0x004604f4.ApplyAlphaMap565.md).
  - Recorded that UID0000YD is now a non-emitting container and the child pages are SoftwareBlend16-owned emitters with formal first-draft C++.
  - Preserved the local-mask/local-weight SoftwareBlend16 source policy: RGB555 block children use target-local masks and source/inverse weights instead of standalone scratch globals, while RGB565 wrapper children call the independently documented block helpers UID000208 and UID00020A.
  - Parent metadata remains `86/88`; this callback changes UID0000YD/child routing and generated output membership, not this source-root score.
