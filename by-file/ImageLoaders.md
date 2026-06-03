*** UID:0000K3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ImageLoaders

## Status

- Confidence: strong for PCX/JPF/BMP/JPEG wrapper behavior, medium for final split from `DIBitmap.cpp` or a broader `ImageDecode.cpp`.
- Proposed module: `render/ImageLoaders.cpp`
- Current recovered sources: `source-3/simroot_v2/recovered/LoadPcxImage_004A17B0.cpp`, `CreateDIBitmapFromPcxBuffer_004A18B0.cpp`, `DecodePcxToRgb565Buffer_00549410.cpp`, plus generated feature-call references to `0x004d07b0` and `0x004d0a90`.
- Evidence basis: Wave3 global summaries/xrefs, generated recovered source, existing memory docs, and IDA MCP boundary/caller/callee checks on 2026-05-23 and 2026-05-25.

## File Role

`ImageLoaders.cpp` should own project-facing image decode/load wrappers:

1. Resolve a DAT-backed or file-buffer PCX asset by name.
2. Decode 8-bit RLE PCX pixels and palette data into RGB565.
3. Construct a [UID:0000IV][DIBitmap](by-file/DIBitmap.md) and copy decoded rows into its DIB section.
4. Convert legacy resource/profile image wrappers such as `ZPF`/`FPF`, `JPF`, 8-bit `BM`, and raw JPEG buffers into the shared tile-context shape used by UI/render callers.

The `DIBitmap` wrapper class itself remains best documented as `render/DIBitmap.cpp`. The two PCX helper functions at `0x004a17b0` and `0x004a18b0` are interleaved between the `DIBitmap` constructor and destructor in the final binary, so a compact original source file may have combined them. The proposed tree keeps `ImageLoaders.cpp` separate because the actual loader/codec logic is free-helper code and the PCX decoder is linked far from the DIB wrapper cluster.

## Proposed Contents

| Entity | Range | Proposed placement | Notes |
| --- | --- | --- | --- |
| [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md) | `0x004a17b0-0x004a18a8` | `render/ImageLoaders.cpp` | Converts an ANSI asset name to wide path, checks availability, opens file/DAT buffer, and calls the PCX-to-DIB factory. |
| [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md) | `0x004a18b0-0x004a1b0c` | `render/ImageLoaders.cpp` | Calls the PCX decoder, constructs `DIBitmap`, copies RGB565 rows, and frees temporary pixels. |
| [UID:0000UD][DecodePcxToRgb565Buffer_00549410](by-item/DecodePcxToRgb565Buffer_00549410.md) | `0x00549410-0x00549616` | `render/ImageLoaders.cpp` or `render/PcxDecode.cpp` | Standalone 8-bit PCX/RLE/palette decoder with one confirmed caller. |
| [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md) | `0x004d05f0-0x004d0723` | `render/ImageLoaders.cpp` | Retained legacy compressed image wrapper: `ZPF` outer data inflates to `FPF` and is copied as 16-bit pixels. |
| [UID:0002TK][0x004d0730-0x004d07a3.DecodeFpfToTileContext](by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md) | `0x004d0730-0x004d07a3` | `render/ImageLoaders.cpp` | IDA-unmodeled direct `FPF` decoder with no known direct xrefs; signature/source-family evidence is strong enough to attach, while reachability remains open. |
| [UID:0002TL][0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext](by-memory/0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext.md) | `0x004d07b0-0x004d09a7` | `render/ImageLoaders.cpp` | Profile/look portrait wrapper: `JPF` header plus embedded JPEG decoded through [UID:0000KN][LibJPEG](by-file/LibJPEG.md), converted to RGB565. |
| [UID:0002TM][0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext](by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md) | `0x004d09b0-0x004d0a8a` | `render/ImageLoaders.cpp` | 8-bit BMP plus palette loader used by [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) for `LEVEL.BMP`. |
| [UID:0002TN][0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext](by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md) | `0x004d0a90-0x004d0c58` | `render/ImageLoaders.cpp` | Raw in-memory JPEG decoder used by [UID:0000LE][MiniMap](by-file/MiniMap.md) `.mnm` tile blobs. |

## Evidence

- Wave3 `show global` summaries report manual grade `96` for all three helpers and no memory conflicts.
- IDA MCP confirms exact ranges:
  - `0x004a17b0-0x004a18a8` for `LoadPcxImage`.
  - `0x004a18b0-0x004a1b0c` for `CreateDIBitmapFromPcxBuffer`.
  - `0x00549410-0x00549616` for `DecodePcxToRgb565Buffer`.
- IDA MCP callee checks show `LoadPcxImage` calls string conversion helpers, [UID:0000T0][HasDATEntry_49C700](by-global/HasDATEntry_49C700.md), `DATFile` construction/data access, and `CreateDIBitmapFromPcxBuffer`.
- IDA MCP caller checks show `CreateDIBitmapFromPcxBuffer` has one direct caller: `LoadPcxImage` at `0x004a1876`.
- IDA MCP caller checks show `DecodePcxToRgb565Buffer` has one direct caller: `CreateDIBitmapFromPcxBuffer` at `0x004a18f5`.
- Wave3 xrefs show `LoadPcxImage` used by `StartupWindow` update/notice UI paths for six startup PCX assets.
- IDA MCP decompilation on 2026-05-25 confirms [UID:000175][0x004d05f0-0x004d0c58.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0c58.ImageDecodeWrappers.md) for `ZPF`/`FPF`, `JPF`, 8-bit `BM`, and raw JPEG.
- IDA MCP lookup/disassembly/byte audit on 2026-06-03 corrects the wrapper family to five child ranges, including the previously omitted IDA-unmodeled raw `FPF` helper at `0x004d0730-0x004d07a3` and the raw JPEG half-open end at `0x004d0c58`.
- IDA callers tie `DecodeJpfImageToTileContext` to [UID:0000MS][ProfileStorage](by-file/ProfileStorage.md) and [UID:0000P0][UserLookPane](by-file/UserLookPane.md), `DecodeJpegBufferToTileContext` to [UID:0000LE][MiniMap](by-file/MiniMap.md), and `Decode8BitBmpToTileContext` to [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md).
- IDA MCP post-restart clean disassembly and xref/string sweep on 2026-06-03 maps the raw `FPF` helper signature to `(const unsigned char* fpfBuffer, EPFTileContext* destination)`, shows its decode body mirrors the ZPF wrapper's inner `FPF` branch, and confirms the `FPF` literal is referenced only by those two bodies.

## Ownership Decision

Use `render/ImageLoaders.cpp` for the PCX pipeline helpers and the shared legacy image decode wrappers, and `render/DIBitmap.cpp` for the DIB wrapper class. Keep a cross-link between both file docs because `CreateDIBitmapFromPcxBuffer` constructs `DIBitmap` directly and the local binary layout places the startup PCX helpers inside the DIB constructor/destructor neighborhood.

Do not put these helpers in the DAT archive module. They consume the archive/file-buffer API but own image decoding and GDI bitmap construction policy.

Do not put IJG internals in this module. The `JPF` and raw JPEG wrappers belong here, while the statically linked IJG implementation remains [UID:0000KN][LibJPEG](by-file/LibJPEG.md).

## Open Questions

- Confirm whether the original project had a separate `PcxDecode.cpp` or kept the PCX decoder in a broader `ImageLoaders.cpp`.
- Confirm whether `LoadPcxImage` was only startup/update UI or whether additional PCX callers were removed/inlined.
- Review the `0x005818d0` Wave3/Ghidra caller attribution before using it as startup-window source coverage; IDA reports no function at that address.

## Cross-References

- [UID:0000IV][DIBitmap](by-file/DIBitmap.md)
- [UID:00003V][DIBitmap](by-class/DIBitmap.md)
- [UID:000135][0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders](by-memory/0x004a1600-0x004a1b5e.DIBitmapAndPcxLoaders.md)
- [UID:0001F1][0x00549410-0x00549616.DecodePcxToRgb565Buffer](by-memory/0x00549410-0x00549616.DecodePcxToRgb565Buffer.md)
- [UID:000175][0x004d05f0-0x004d0c58.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0c58.ImageDecodeWrappers.md)
- [UID:0000UZ][LoadPcxImage_004A17B0](by-item/LoadPcxImage_004A17B0.md)
- [UID:0000U9][CreateDIBitmapFromPcxBuffer_004A18B0](by-item/CreateDIBitmapFromPcxBuffer_004A18B0.md)
- [UID:0000UD][DecodePcxToRgb565Buffer_00549410](by-item/DecodePcxToRgb565Buffer_00549410.md)
- [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md)
- [UID:0002TK][0x004d0730-0x004d07a3.DecodeFpfToTileContext](by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md)
- [UID:0002TL][0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext](by-memory/0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext.md)
- [UID:0002TM][0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext](by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md)
- [UID:0002TN][0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext](by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md)
- StartupWindow update/notice UI paths (`0x00581100` and projected `0x005818d0`)
- [UID:0000IN][DATFile](by-file/DATFile.md)
- [UID:0000IO][DATFileMgr](by-file/DATFileMgr.md)
- [UID:0000KN][LibJPEG](by-file/LibJPEG.md)

## Changes

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
  - Changed to: attached [UID:000175][0x004d05f0-0x004d0c58.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0c58.ImageDecodeWrappers.md) and [UID:0002TK][0x004d0730-0x004d07a3.DecodeFpfToTileContext](by-memory/0x004d0730-0x004d07a3.DecodeFpfToTileContext.md) to this file, with C++ still blank.
  - Summary/evidence: IDA MCP clean disassembly confirms the raw helper stack map and ZPF-inner-branch equivalence, while non-flow xrefs still show no direct caller or function object for the raw helper.
