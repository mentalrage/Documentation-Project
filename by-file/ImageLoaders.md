*** UID:0000K3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ImageLoaders

## Status

- Confidence: strong for PCX/JPF/BMP/JPEG/PNG wrapper behavior, the JPEG decode callback marker, and the current generated-emitter route; medium-high for final split from `DIBitmap.cpp`, a narrower PCX helper file, or a broader `ImageDecode.cpp`.
- Proposed module: `render/ImageLoaders.cpp`
- Current recovered sources: `source-3/simroot_v2/recovered/LoadPcxImage_004A17B0.cpp`, `CreateDIBitmapFromPcxBuffer_004A18B0.cpp`, `DecodePcxToRgb565Buffer_00549410.cpp`, plus generated feature-call references to `0x004d07b0` and `0x004d0a90`.
- Evidence basis: current by-* docs, generated `ImageLoaders.cpp`, accepted B006/B007/B015 child-wrapper incorporations, and B009 live MCP boundary/decompile/xref/callee/byte checks on 2026-07-01. Older Wave3/global summaries are historical leads only and do not override current source-quality evidence.

## File Role

`ImageLoaders.cpp` should own project-facing image decode/load wrappers:

1. Resolve a DAT-backed or file-buffer PCX asset by name.
2. Decode 8-bit RLE PCX pixels and palette data into RGB565.
3. Construct a [UID:0000IV][DIBitmap](by-file/DIBitmap.md) and copy decoded rows into its DIB section.
4. Convert legacy resource/profile image wrappers such as `ZPF`/`FPF`, `JPF`, 8-bit `BM`, raw JPEG buffers, and PNG file/resource payloads into the shared tile-context shape used by UI/render callers.

PCX/DIB compatibility detail: `DecodePcxToRgb565Buffer` genuinely packs RGB565 words, but `DIBitmap` creates a one-plane 16-bpp `BI_RGB` DIB with no bitfield masks. The factory copies the 16-bit words unchanged. RGB565 names the decoder data; it must not be used to claim that the DIB header declares RGB565, and no hidden `BI_BITFIELDS` masks should be added.

The `DIBitmap` wrapper class itself remains best documented as `render/DIBitmap.cpp`. The two PCX helper functions at `0x004a17b0` and `0x004a18b0` are interleaved between the `DIBitmap` constructor and destructor in the final binary, so a compact original source file may have combined them. The proposed tree keeps `ImageLoaders.cpp` separate because the actual loader/codec logic is free-helper code and the PCX decoder is linked far from the DIB wrapper cluster.

## Proposed Contents

| Entity | Range | Proposed placement | Notes |
| --- | --- | --- | --- |
| [UID:000314][0x004a17b0-0x004a18a8.LoadPcxImage](by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md) | `0x004a17b0-0x004a18a8` | `render/ImageLoaders.cpp` | First-draft C++ ready: converts an ANSI asset name to a wide path, checks availability, opens a DAT/file-buffer object, forwards raw PCX bytes/size/transparent index to the PCX-to-DIB factory, and returns the `DIBitmap*`. `NtkString`, `NtkWideString`, and `DATFileBuffer` are descriptive current names. |
| [UID:000315][0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer](by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md) | `0x004a18b0-0x004a1b0c` | `render/ImageLoaders.cpp` | First-draft C++ ready: calls the PCX decoder, validates dimensions/pixels, source-calls `new DIBitmap`, guards the DIB bits pointer, copies RGB565 words using four-pixel-aligned DIB stride, frees temporary pixels, and returns/null-cleans the bitmap. The binary allocates literal 60 bytes and inlines UID000313, proving exact DIBitmap size `0x3c` / 60 (Verified with `int_convert.py`). |
| [UID:0000UD][DecodePcxToRgb565Buffer_00549410](by-item/DecodePcxToRgb565Buffer_00549410.md) / [UID:0001F1][0x00549410-0x00549616.DecodePcxToRgb565Buffer](by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md) | `0x00549410-0x00549616` | `render/ImageLoaders.cpp` or `render/PcxDecode.cpp` | Exact by-memory child is first-draft C++ ready: standalone 8-bit PCX/RLE/palette decoder with one confirmed caller, palette marker at `fileSize - 769`, 8-bit header guard, optional remap table, transparent-index zeroing, RGB565 packing, and odd-width source padding skip. The by-item page emits a covered-by comment. |
| [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md) | `0x004d05f0-0x004d0723` | `render/ImageLoaders.cpp` | First-draft C++ ready retained compressed image wrapper. Source shape is `DecodeZpfFpfToTileContext(const unsigned char *zpfBuffer, unsigned int zpfBufferSize, EPFTileContext *destination)`; the second byte-count argument is present for wrapper-family convention but unused in this optimized body. Uses zlib `Uncompress` and a stack `_AUTOBUF<unsigned char>` temporary, then validates/copies inner `FPF` 16-bit pixels. |
| [UID:0002TK][0x004d0730-0x004d07a3.DecodeFpfToTileContext](by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md) | `0x004d0730-0x004d07a3` | `render/ImageLoaders.cpp` | First-draft C++ ready IDA-unmodeled direct `FPF` decoder: `DecodeFpfToTileContext(const unsigned char *fpfBuffer, EPFTileContext *destination)` releases the destination, validates version/signature, allocates 16-bit pixels, copies from the header-indicated body offset with bounds-derived byte count, and normalizes. B015 raw PE recheck found no direct rel32 or pointer route to the helper start, so reachability remains a caveat rather than an ownership/C++ blocker. |
| [UID:0002TL][0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext](by-memory/0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext.md) | `0x004d07b0-0x004d09a7` | `render/ImageLoaders.cpp` | First-draft C++ ready profile/look portrait wrapper: validates `JPF`, passes `jpfData + 4` with the observed full size argument to the shared JPEG memory helper, decodes through [UID:0000KN][LibJPEG](by-file/LibJPEG.md), converts RGB scanlines to RGB565, and normalizes. |
| [UID:0002TM][0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext](by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md) | `0x004d09b0-0x004d0a8a` | `render/ImageLoaders.cpp` | `Decode8BitBmpToTileContext(const unsigned char *bmpData, int bmpDataSize, EPFTileContext *destination, DLPalette *palette)`; 8-bit paletted BMP file decoder used by [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) for `LEVEL.BMP`. The byte-count argument is passed by the `_AUTOBUF<unsigned char>` caller but is not read in the optimized body. |
| [UID:0002TN][0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext](by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md) | `0x004d0a90-0x004d0c58` | `render/ImageLoaders.cpp` | First-draft C++ ready raw in-memory JPEG decoder used by [UID:0000LE][MiniMap](by-file/MiniMap.md) `.mnm` tile blobs; reuses the shared JPEG memory helper emitted by the JPF child. |
| [UID:00032P][0x004d0c60-0x004d0d89.DecodePngFileToTileContext](by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md) | `0x004d0c60-0x004d0d89` | `render/ImageLoaders.cpp` | First-draft C++ ready raw/IDA-unmodeled PNG-file wrapper over [UID:0000KW][LodePNG](by-file/LodePNG.md), converting RGBA8 to `EPFTileContext` RGB565 plus `alphaData`; no direct xrefs and no IDA function object remain reachability/status caveats, not C++ blockers. |
| [UID:00032O][0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext](by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md) | `0x004d0d90-0x004d0f4a` | `render/ImageLoaders.cpp` | First-draft C++ ready DAT/file-buffer PNG wrapper over [UID:0000KW][LodePNG](by-file/LodePNG.md), converting RGBA8 to `EPFTileContext` RGB565 plus `alphaData`; `DATFileBuffer`, `NtkAlloc`, and `NtkFree` are descriptive current names. |
| [UID:0002ZF][ImageDecodeJpegEoiMarker](by-global/ImageDecodeJpegEoiMarker.md) | `0x0066db3c-0x0066db40` | `render/ImageLoaders.cpp` | Emits one mutable file-static `FF D9` fallback marker declaration returned by the image-decode source-manager callback. |
| [UID:00027L][0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot](by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md) | `0x0066db3c-0x0066db40` | `render/ImageLoaders.cpp` | Exact initialized storage for the decode fallback marker; emits only a covered-by comment because [UID:0002ZF][ImageDecodeJpegEoiMarker](by-global/ImageDecodeJpegEoiMarker.md) owns the source declaration. |

## Evidence

- Wave3 `show global` summaries report manual grade `96` for all three helpers and no memory conflicts.
- IDA MCP confirms exact ranges:
  - `0x004a17b0-0x004a18a8` for `LoadPcxImage`.
  - `0x004a18b0-0x004a1b0c` for `CreateDIBitmapFromPcxBuffer`.
  - `0x00549410-0x00549616` for `DecodePcxToRgb565Buffer`.
- 2026-06-08 Batch 116 split work created exact by-memory children for the PCX path loader and PCX-to-DIB factory. Current IDA MCP decompilation confirms the path conversion, DAT/file-buffer open/data/close path, call from `0x004a17b0` into `0x004a18b0`, PCX decoder call at `0x004a18f5`, DIBitmap construction, DIB row-copy loop, and cleanup behavior.
- IDA MCP callee checks show `LoadPcxImage` calls string conversion helpers, [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), `DATFile` construction/data access, and `CreateDIBitmapFromPcxBuffer`.
- IDA MCP caller checks show `CreateDIBitmapFromPcxBuffer` has one direct caller: `LoadPcxImage` at `0x004a1876`.
- IDA MCP caller checks show `DecodePcxToRgb565Buffer` has one direct caller: `CreateDIBitmapFromPcxBuffer` at `0x004a18f5`.
- Wave3 xrefs show `LoadPcxImage` used by `StartupWindow` update/notice UI paths for six startup PCX assets.
- IDA MCP decompilation on 2026-05-25 and B001-023 follow-up on 2026-06-10 confirm [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md) for `ZPF`/`FPF`, `JPF`, 8-bit `BM`, raw JPEG, and PNG file/resource wrappers.
- B006's 2026-06-21 source-quality pass makes [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md) first-draft C++ ready and keeps it here: exported data shows three formals, sibling wrappers preserve the `(buffer, size, destination)` convention, support docs resolve `Uncompress`, `_AUTOBUF<unsigned char>`, and EPFTileContext callee names, and PE scans found no direct VA/RVA pointer table that would move ownership to a feature.
- B007's 2026-06-21 source-quality pass makes [UID:0002TM][0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext](by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md) first-draft C++ ready and keeps it here: the sole MainMenuPane caller passes `(buffer, byteCount, this + 0x1fc, this + 0x224)`, resolving the output objects as `EPFTileContext*` and `DLPalette*`; the body validates a full `BM` BMP file with `biBitCount == 8`, loads the embedded RGBQUAD table through `DLPalette::LoadFromRawRGBA`, and copies byte pixels without BMP row-stride alignment.
- B015's 2026-06-19/2026-06-22 raw FPF pass makes [UID:0002TK][0x004d0730-0x004d07a3.DecodeFpfToTileContext](by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md) first-draft C++ ready and keeps it here: the helper is the direct sibling of the ZPF/FPF wrapper, uses the same `FPF` literal and EPFTileContext 16-bit copy/finalizer policy, has exact raw offset/hash/padding evidence, and has no rel32 or absolute-pointer route that would move it to a feature or dispatch owner.
- IDA MCP lookup/disassembly/byte audit on 2026-06-03 corrects the wrapper family to five child ranges, including the previously omitted IDA-unmodeled raw `FPF` helper at `0x004d0730-0x004d07a3` and the raw JPEG half-open end at `0x004d0c58`.
- IDA callers tie `DecodeJpfImageToTileContext` to [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md) and [UID:0000P0][UserLookPane](by-file/UserLookPane.md), `DecodeJpegBufferToTileContext` to [UID:0000LE][MiniMap](by-file/MiniMap.md), and `Decode8BitBmpToTileContext` to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md).
- IDA MCP post-restart clean disassembly and xref/string sweep on 2026-06-03 maps the raw `FPF` helper signature to `(const unsigned char* fpfBuffer, EPFTileContext* destination)`, shows its decode body mirrors the ZPF wrapper's inner `FPF` branch, and confirms the `FPF` literal is referenced only by those two bodies.
- 2026-06-10 B001-023 IDA MCP maps [UID:00032P][0x004d0c60-0x004d0d89.DecodePngFileToTileContext](by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md) and [UID:00032O][0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext](by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md) to LodePNG RGBA8 file/memory front ends at `0x00443c40` and `0x00443b40`, `EPFTileContext` allocation/finalizer calls, RGBA-to-RGB565 conversion, alpha-plane conversion, and no direct caller/xref evidence.
- 2026-06-08 A007 IDA MCP reconfirms the image-decode JPEG EOI marker bytes `ff d9 00 00` at `0x0066db3c-0x0066db40`, one marker xref at `0x004e4e92` in callback `0x004e4e70-0x004e4ea5`, and callback-record setup xref `0x004e7075 -> 0x004e4e70` in `0x004e7030`.
- B011's accepted UID00022R split creates exact child [UID:0004DP][0x004e7030-0x004e7094.InitializeJpegSourceManagerRecord](by-memory/0x004e7030-0x004e7094.InitializeJpegSourceManagerRecord.md) for that callback-record setup helper. It is owned/emitted through this ImageLoaders route, has JPF/raw JPEG wrapper callsites `0x004d0869` and `0x004d0b21`, writes callbacks `0x004e4e60`, `0x004e4e70`, `0x004e4eb0`, `0x00401b00`, and `0x004e4ed0`, and keeps [UID:0000VR][0x00401b00-0x0040391f.LibJpegMarkerReader](by-memory/0x00401b00-0x0040391f.LibJpegMarkerReader.md) as the IJG `jpeg_resync_to_restart` dependency rather than the owner.
- Decompilation of `0x004e4e70` shows product source-manager behavior: return the caller's buffer on the first fill, then write `&unk_66DB3C` and length `2` into the output record after the source state is exhausted.
- Neighbor xref checks keep this marker out of [UID:0000K4][ImageWriters](by-file/ImageWriters.md) and startup-logo ownership: `0x0066db40` is used by screenshot writer callback code, while `0x0066db42` is used by startup-logo Bink restart code.
- B009's 2026-07-01 implementation callback cleared the 13 current empty emitters in generated `ImageLoaders.cpp`: [UID:0002ZF][ImageDecodeJpegEoiMarker](by-global/ImageDecodeJpegEoiMarker.md) now emits one mutable marker declaration; by-item aliases [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md), [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md), and [UID:0000UD][DecodePcxToRgb565Buffer_00549410](by-item/DecodePcxToRgb565Buffer_00549410.md) emit covered-by comments; exact PCX children [UID:000314][0x004a17b0-0x004a18a8.LoadPcxImage](by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md), [UID:000315][0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer](by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md), and [UID:0001F1][0x00549410-0x00549616.DecodePcxToRgb565Buffer](by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md) emit first-draft PCX loader/factory/decoder C++; aggregate [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md) emits a covered-by-children comment; JPEG children [UID:0002TL][0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext](by-memory/0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext.md) and [UID:0002TN][0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext](by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md) emit JPF/raw JPEG wrapper C++; PNG children [UID:00032P][0x004d0c60-0x004d0d89.DecodePngFileToTileContext](by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md) and [UID:00032O][0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext](by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md) emit PNG file/resource wrapper C++; and [UID:00027L][0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot](by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md) emits a covered-by storage comment.
- The B009 live MCP pass reconfirmed `lookup_funcs` sizes for callable children, `xrefs_to` counts including 12 `LoadPcxImage` refs, one DIB factory ref, one PCX decoder ref, two JPF refs, one raw JPEG ref, zero aggregate/PNG refs, one JPEG EOI data ref, and bounded `insn_query` proof that `0x004d0c60-0x004d0d89` is a complete raw helper despite `lookup_funcs` reporting no function object.

## Ownership Decision

Use `render/ImageLoaders.cpp` for the PCX pipeline helpers and the shared legacy image decode wrappers, including the PNG file/resource wrappers, and `render/DIBitmap.cpp` for the DIB wrapper class. Keep a cross-link between both file docs because `CreateDIBitmapFromPcxBuffer` constructs `DIBitmap` directly and the local binary layout places the startup PCX helpers inside the DIB constructor/destructor neighborhood.

Do not put these helpers in the DAT archive module. They consume the archive/file-buffer API but own image decoding and GDI bitmap construction policy.

Do not put IJG or LodePNG internals in this module. The `JPF`, raw JPEG, PNG-file, and PNG-resource wrappers belong here, while the statically linked IJG implementation remains [UID:0000KN][LibJPEG](by-file/LibJPEG.md) and the LodePNG implementation remains [UID:0000KW][LodePNG](by-file/LodePNG.md). The image-decode EOI fallback marker is also application-side callback support and belongs here, not in `LibJPEG`.

The PCX loader/factory children clear the strict assignment gate for this file: [UID:000314][0x004a17b0-0x004a18a8.LoadPcxImage](by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md) `LoadPcxImage` is `88/90`, [UID:000315][0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer](by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md) is `91/93`, this parent remains `93/90`, and the direct source owner is the image-loader module rather than the neighboring DIBitmap class. [UID:0001F1][0x00549410-0x00549616.DecodePcxToRgb565Buffer](by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md) carries the far PCX/RLE decoder at `89/91`. The broader [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md) remains `NONE`/blank/FALSE because it mixes DIBitmap methods with these free helpers.

## Open Questions

- The original project may have had a separate `PcxDecode.cpp`, but current reconstruction keeps the PCX loader/factory/decoder in this [UID:0000K3] route because the by-file emitter path is valid and no stronger source route is documented.
- `LoadPcxImage` has six modeled startup/update refs and six raw `0x005818d0` notice-helper refs. IDA still reports no function at `0x005818d0`, so treat that raw caller as reachability evidence and source-placement caveat rather than a reason to move ownership.
- For retained ZPF/FPF/direct FPF, a computed/data-driven legacy dispatch remains possible, but B006/B015 found no direct or function-pointer caller for `0x004d05f0` or `0x004d0730`; this remains a reachability caveat rather than an ImageLoaders ownership blocker.
- For PNG file/resource wrappers, zero direct xrefs remain documented. [UID:00032P][0x004d0c60-0x004d0d89.DecodePngFileToTileContext](by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md) is raw and IDA-unmodeled, but B009 bounded instruction evidence proves a complete source-shaped helper body. The PNG wrappers remain project code over LodePNG, not third-party import targets.
- Third-party import directives are not applicable on this page. IJG/LibJPEG and LodePNG internals stay with [UID:0000KN][LibJPEG](by-file/LibJPEG.md) and [UID:0000KW][LodePNG](by-file/LodePNG.md); ImageLoaders owns only the project-facing wrapper and tile-conversion policy.

## Cross-References

- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:00003V][DIBitmap](by-class/DIBitmap.md)
- [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- [UID:000314][0x004a17b0-0x004a18a8.LoadPcxImage](by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md)
- [UID:000315][0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer](by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md)
- [UID:0001F1][0x00549410-0x00549616.DecodePcxToRgb565Buffer](by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md)
- [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md)
- [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md)
- [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md)
- [UID:0000UD][DecodePcxToRgb565Buffer_00549410](by-item/DecodePcxToRgb565Buffer_00549410.md)
- [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md)
- [UID:0002TK][0x004d0730-0x004d07a3.DecodeFpfToTileContext](by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md)
- [UID:0002TL][0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext](by-memory/0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext.md)
- [UID:0002TM][0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext](by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md)
- [UID:0002TN][0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext](by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md)
- [UID:00032P][0x004d0c60-0x004d0d89.DecodePngFileToTileContext](by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md)
- [UID:00032O][0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext](by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md)
- [UID:0002ZF][ImageDecodeJpegEoiMarker](by-global/ImageDecodeJpegEoiMarker.md)
- [UID:0004DP][0x004e7030-0x004e7094.InitializeJpegSourceManagerRecord](by-memory/0x004e7030-0x004e7094.InitializeJpegSourceManagerRecord.md)
- [UID:00027L][0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot](by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md)
- StartupWindow update/notice UI paths (`0x00581100` and projected `0x005818d0`)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000KN][LibJPEG](by-file/LibJPEG.md)

## Changes

- 2026-07-12 B002 target-specific DIB support synchronization:
  - Score `93/90`, path, file ownership, and all unrelated image-wrapper content remain unchanged.
  - Updated only the PCX factory relationship: exact `0x3c` DIBitmap allocation/inlining, factory-owned null-bits cleanup, four-pixel-aligned stride, and RGB565-word versus 16-bpp-BI_RGB/no-mask caveat.

- 2026-07-01 B009 ImageLoaders empty-emitter implementation:
  - Changed score from `91/87` to `93/90`.
  - Summary/evidence: accepted B009 report incorporated all 13 current empty emitters in `auto-generated/NexusTK/render/ImageLoaders.cpp`. Formal C++ or covered-by comments now exist for [UID:0002ZF][ImageDecodeJpegEoiMarker](by-global/ImageDecodeJpegEoiMarker.md), [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md), [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md), [UID:0000UD][DecodePcxToRgb565Buffer_00549410](by-item/DecodePcxToRgb565Buffer_00549410.md), [UID:000314][0x004a17b0-0x004a18a8.LoadPcxImage](by-memory/0x004a17b0-0x004a18a8.LoadPcxImage.md), [UID:000315][0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer](by-memory/0x004a18b0-0x004a1b0c.CreateDIBitmapFromPcxBuffer.md), [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md), [UID:0002TL][0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext](by-memory/0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext.md), [UID:0002TN][0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext](by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md), [UID:00032P][0x004d0c60-0x004d0d89.DecodePngFileToTileContext](by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md), [UID:00032O][0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext](by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md), [UID:0001F1][0x00549410-0x00549616.DecodePcxToRgb565Buffer](by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md), and [UID:00027L][0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot](by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md). The file-level docs now preserve the accepted B009 live MCP facts: exact callable sizes, xrefs/callees, marker bytes `ff d9 00 00`, raw PNG-file bounded instruction evidence, zero-xref caveats for aggregate/PNG helpers, source-placement decisions, no third-party import directive for wrapper code, descriptive PCX/DAT/JPEG/PNG helper names, and remaining inferred-name score limits.

- 2026-06-21 B006 ZPF wrapper Rule 26 incorporation:
  - Score unchanged.
  - Summary/evidence: [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md) now records a first-draft `DecodeZpfFpfToTileContext` implementation under this file. The file-level row now preserves the three-argument signature, unused size formal, zlib `Uncompress` dependency, stack `_AUTOBUF<unsigned char>` temporary, inner `FPF` copy/finalizer behavior, and no-caller/no-pointer scan result.

- 2026-06-21 B007 BMP wrapper Rule 26 incorporation:
  - Score unchanged.
  - Summary/evidence: [UID:0002TM][0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext](by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md) now records a first-draft `Decode8BitBmpToTileContext` implementation under this file. The file-level row now preserves the four-argument signature, unused byte-count formal, `EPFTileContext*`/`DLPalette*` caller offsets from `MainMenuPane`, `DLPalette::FreePaletteData` and `DLPalette::LoadFromRawRGBA`, BMP file/DIB header map, and exact row-copy behavior.

- 2026-06-22 B015 direct FPF wrapper Rule 26 incorporation:
  - Score unchanged.
  - Summary/evidence: [UID:0002TK][0x004d0730-0x004d07a3.DecodeFpfToTileContext](by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md) now records a first-draft `DecodeFpfToTileContext` implementation under this file. The file-level row now preserves the two-argument signature, exact raw `0x73`-byte body at PE raw offset `0x000cfb30`, `FPF` version/signature validation, header field offsets, EPFTileContext release/allocation/pixel-data/bounds/finalizer naming, no-caller/no-pointer scans, and the retained legacy/direct-FPF reachability caveat.

- 2026-06-10 B001-023 PNG wrapper split:
  - Changed score from `90/86` to `91/87`.
  - Summary/evidence: live IDA MCP expanded [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md) through the PNG wrappers, creating/assigning [UID:00032P][0x004d0c60-0x004d0d89.DecodePngFileToTileContext](by-memory/0x004d0c60-0x004d0d89.DecodePngFileToTileContext.md) and [UID:00032O][0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext](by-memory/0x004d0d90-0x004d0f4a.DecodePngResourceToTileContext.md). Both wrappers use LodePNG front ends plus project `EPFTileContext` conversion policy, so they belong here rather than in ResourceLayout, ImageFrameTable, DATFile, or LodePNG internals.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:82`.
  - Summary/evidence: PCX pipeline, JPF/BMP/raw JPEG wrappers, exact ranges, caller/callee evidence, DAT/DIB/LibJPEG boundaries, ownership decision, and open questions are documented; confidence is capped by final split between `DIBitmap.cpp`, `ImageLoaders.cpp`, and possible `PcxDecode.cpp`.

- 2026-06-03 image decode child split:
  - What existed before: the wrapper inventory listed four unlinked rows with return-address-style ends and omitted the raw direct `FPF` helper.
  - Changed to: replaced the wrapper rows with exact child UID links for `ZPF`/`FPF`, raw `FPF`, `JPF`, 8-bit BMP, and raw JPEG; kept the file score unchanged because this pass refines existing ownership rather than resolving the remaining source-file split questions.
  - Summary/evidence: IDA MCP `lookup_funcs`, `py_eval`, `disasm`, `decompile`, caller/callee checks, and byte audit on 2026-06-03.

- 2026-06-03 raw FPF parent attachment:
  - What existed before: the raw `FPF` child and aggregate wrapper page were linked but not attached to the file parent.
  - Changed to: attached [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md) and [UID:0002TK][0x004d0730-0x004d07a3.DecodeFpfToTileContext](by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md) to this file, with C++ still blank.
  - Summary/evidence: IDA MCP clean disassembly confirms the raw helper stack map and ZPF-inner-branch equivalence, while non-flow xrefs still show no direct caller or function object for the raw helper.

- 2026-06-08 A007 Batch 116 PCX child split:
  - Changed score from `88/82` to `89/85`.
  - Summary/evidence: exact by-memory pages now document `LoadPcxImage` and `CreateDIBitmapFromPcxBuffer`; current IDA MCP decompilation confirms DAT/file-buffer access, the path-loader-to-factory call, the PCX decoder call, DIBitmap construction, row-copy behavior, and cleanup. This resolves the parent gate for the two PCX children while preserving the broader DIBitmap/PCX aggregate as unassigned mixed ownership.
- 2026-06-08 A007 Batch 130 JPEG fallback marker ownership:
  - Changed score from `89/85` to `90/86`.
  - Summary/evidence: current IDA MCP ties [UID:0002ZF][ImageDecodeJpegEoiMarker](by-global/ImageDecodeJpegEoiMarker.md) and [UID:00027L][0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot](by-memory/0x0066db3c-0x0066db40.ImageDecodeJpegEoiMarkerSlot.md) to the product image-decode source-manager callback at `0x004e4e70` and callback-record initializer at `0x004e7030`. This gives the marker a direct `ImageLoaders.cpp` parent while preserving the separate LibJPEG/ImageWriters/startup-logo boundaries.
