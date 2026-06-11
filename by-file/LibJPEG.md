*** UID:0000KN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/third_party/libjpeg/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# LibJPEG

## Status

- Confidence: strong for IJG libjpeg identity/version and many source-file clusters; medium for remaining entropy/DCT/color/quantizer lower-helper split.
- Proposed module: `third_party/libjpeg/`
- Main address doc: [UID:0000VP][0x00401000-0x00414283.LibJpeg6bCore](by-memory/0x00401000-0x00414283.LibJpeg6bCore.md)
- Focused source-match docs: [UID:0000VQ][0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd](by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md), [UID:0000VR][0x00401b00-0x004038c7.LibJpegMarkerReader](by-memory/0x00401b00-0x004038c7.LibJpegMarkerReader.md), [UID:0000VS][0x00403920-0x004048e2.LibJpegCompressApiFrontEnd](by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md), [UID:0000VT][0x004048f0-0x004049bb.LibJpegCompressRawDataApi](by-memory/0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md), [UID:0000VU][0x004049c0-0x00404a5c.LibJpegCommonApi](by-memory/0x004049c0-0x00404a5c.LibJpegCommonApi.md), [UID:0000VV][0x00404a60-0x0040505b.LibJpegInputController](by-memory/0x00404a60-0x0040505b.LibJpegInputController.md), [UID:0000VW][0x00405060-0x00405c77.LibJpegMemoryManager](by-memory/0x00405060-0x00405c77.LibJpegMemoryManager.md), [UID:0000VX][0x00405c80-0x004063c8.LibJpegDecompressMaster](by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md), [UID:0000VY][0x004063d0-0x0040649b.LibJpegUtilityHelpers](by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md), [UID:0000VZ][0x004064a0-0x00406d8c.LibJpegMarkerWriter](by-memory/0x004064a0-0x00406d8c.LibJpegMarkerWriter.md), [UID:0000W0][0x00406d90-0x00406e46.LibJpegCompressMasterInit](by-memory/0x00406d90-0x00406e46.LibJpegCompressMasterInit.md), and [UID:0000W1][0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend](by-memory/0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend.md).
- Evidence basis: Wave3 read-only prewave range scan, read-only IDA MCP string/xref/decompile/disassembly checks on 2026-05-25, and existing render/image-loader documentation.

## File Role

This is statically linked Independent JPEG Group support code, not NexusTK product code. It should provide JPEG decode/codec internals that project image/resource modules call through local wrappers.

The current source reconstruction should treat IJG code like zlib and LodePNG: vendor the matching upstream source first, then map NexusTK-owned call sites around it.

## Version Evidence

- IDA string `0x00671268`: `Copyright (C) 1998, Thomas G. Lane`.
- IDA string `0x0067128c`: `6b  27-Mar-1998`.
- IDA strings include canonical IJG diagnostics: `Wrong JPEG library version: library is %d, caller expects %d`, `JPEG parameter struct mismatch`, `Not a JPEG file: starts with 0x%02x 0x%02x`, `Invalid JPEG file structure`, `Premature end of JPEG file`, and `JPEGMEM`.
- The official IJG archive lists `jpegsrc.v6b.tar.gz`, which is the source package to compare against this binary.

## Range Notes

Current evidence bounds the main IJG libjpeg 6b code-island candidate as [UID:0000VP][0x00401000-0x00414283.LibJpeg6bCore](by-memory/0x00401000-0x00414283.LibJpeg6bCore.md). This range begins with a `jpeg_std_error`-style error-manager initializer and ends at the last modeled DCT/IDCT-style helper before non-JPEG glue.

The static JPEG message table starts at `0x00631660`; IDA data inspection finds 121 pointer entries through `0x00631840`. Version/copyright anchors include `0x00671268` and `0x0067128c`, and the memory-manager environment variable `JPEGMEM` is at `0x00671a64`.

Exclude `0x00414290-0x004142b5` from LibJPEG ownership: IDA identifies it as a Miles `_AIL_shutdown@0` thunk plus `atexit` wrapper. [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md) starts immediately afterward at `0x004142c0`.

The earlier provisional neighborhood `0x00469640-0x00470dc9` is rejected for LibJPEG. IDA decompiles `0x00469640` and `0x00470a00` as BrowserWindow/WebBrowser COM code, not JPEG code.

Focused source-file anchors now identified inside the library island:

- [UID:0000VQ][0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd](by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md) maps `jpeg_CreateDecompress`, `jpeg_read_header`, `jpeg_start_decompress`, `jpeg_read_scanlines`, `jpeg_finish_decompress`, and `jpeg_destroy_decompress` to `jdapimin.c`/`jdapistd.c`.
- [UID:0000VR][0x00401b00-0x004038c7.LibJpegMarkerReader](by-memory/0x00401b00-0x004038c7.LibJpegMarkerReader.md) maps the decompression marker parser to `jdmarker.c`, including `jpeg_resync_to_restart`, `read_markers`, `jinit_marker_reader`, SOF/SOS/DHT/DQT parsing, and APP/COM marker handling.
- [UID:0000VS][0x00403920-0x004048e2.LibJpegCompressApiFrontEnd](by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md) maps `jpeg_CreateCompress`, `jpeg_stdio_dest`, `jpeg_set_defaults`, `jpeg_start_compress`, `jpeg_write_scanlines`, `jpeg_finish_compress`, and `jpeg_destroy_compress` to `jcapimin.c`/`jcapistd.c`/`jcparam.c`/`jdatadst.c`.
- [UID:0000VT][0x004048f0-0x004049bb.LibJpegCompressRawDataApi](by-memory/0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md) maps adjacent stock `jpeg_write_raw_data` to `jcapistd.c`.
- [UID:0000VU][0x004049c0-0x00404a5c.LibJpegCommonApi](by-memory/0x004049c0-0x00404a5c.LibJpegCommonApi.md) maps `jpeg_abort`, `jpeg_destroy`, `jpeg_alloc_quant_table`, and `jpeg_alloc_huff_table` to `jcomapi.c`.
- [UID:0000VV][0x00404a60-0x0040505b.LibJpegInputController](by-memory/0x00404a60-0x0040505b.LibJpegInputController.md) maps decompression input setup and marker/scan state control to `jdinput.c`.
- [UID:0000VW][0x00405060-0x00405c77.LibJpegMemoryManager](by-memory/0x00405060-0x00405c77.LibJpegMemoryManager.md) maps `jmemmgr.c`.
- [UID:0000VX][0x00405c80-0x004063c8.LibJpegDecompressMaster](by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md) maps output-dimension calculation, range-limit table setup, module selection, and output-pass orchestration to `jdmaster.c`.
- [UID:0000VY][0x004063d0-0x0040649b.LibJpegUtilityHelpers](by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md) maps `jdiv_round_up`, `jround_up`, row-copy helpers, and `jzero_far` to `jutils.c`.
- [UID:0000VZ][0x004064a0-0x00406d8c.LibJpegMarkerWriter](by-memory/0x004064a0-0x00406d8c.LibJpegMarkerWriter.md) maps compression-side marker/table emission to `jcmarker.c`.
- [UID:0000W0][0x00406d90-0x00406e46.LibJpegCompressMasterInit](by-memory/0x00406d90-0x00406e46.LibJpegCompressMasterInit.md) maps `jinit_compress_master` to `jcinit.c`.
- [UID:0000W1][0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend](by-memory/0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend.md) maps `jmemnobs.c`; this is the backend selected by the observed binary, not a file-backed temp-store backend.

Product-owned wrapper functions are identified outside the library island:

- [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md) call IJG decompression for `JPF` profile/look portraits at `0x004d07b0` and raw minimap JPEG blobs at `0x004d0a90`.
- [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md) calls IJG compression for a retained/unmodeled screenshot `.jpg` path.

## Source-Structure Decision

Use a third-party folder such as:

```text
third_party/
  libjpeg/
    jconfig.h
    jmorecfg.h
    jpeglib.h
    jpegint.h
    jerror.h
    jcapimin.c
    jcapistd.c
    jcinit.c
    jcmarker.c
    jcparam.c
    jcomapi.c
    jdatadst.c
    jdapimin.c
    jdapistd.c
    jdinput.c
    jdmarker.c
    jdmaster.c
    jerror.c
    jutils.c
    jmemmgr.c
    jmemnobs.c
    ...
```

The exact remaining subset should follow source comparison. Current evidence strongly includes the compression/decompression public API, common API, marker reader/writer, input controller, decompression master, utility helpers, `jdatadst.c`, `jmemmgr.c`, and `jmemnobs.c`. Stock `jdatasrc.c` has not been proven as an active caller path; the product uses a local in-memory source setup helper at `0x004e7030` for buffer-backed JPEG decoding.

Product-facing JPEG load/use wrappers should remain with render/image modules such as [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) and [UID:0000K4][ImageWriters](by-file/ImageWriters.md), not inside the third-party library folder.

## Rebuild Strategy

1. Obtain `jpegsrc.v6b.tar.gz` from the official IJG archive.
2. Build a VC6-era compatible static library or add the source files under `third_party/libjpeg/`.
3. Compare remaining stock entropy, coefficient, DCT/IDCT, color, sampling, and quantizer helpers against the binary before replacing generated helpers.
4. Use [UID:0000VP][0x00401000-0x00414283.LibJpeg6bCore](by-memory/0x00401000-0x00414283.LibJpeg6bCore.md) as the first comparison island, excluding the Miles thunk at `0x00414290`.
5. Use the no-backing-store memory backend (`jmemnobs.c`) for the first reconstruction attempt; `jpeg-6b/makefile.vc` also names `jmemnobs.obj` as the suggested Windows `SYSDEPMEM`.
6. Resolve whether the raw JPG screenshot path at `0x00557840-0x00557a95` is reachable through an indirect callback or is retained legacy code.

## Cross-References

- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
- [UID:0000VP][0x00401000-0x00414283.LibJpeg6bCore](by-memory/0x00401000-0x00414283.LibJpeg6bCore.md)
- [UID:0000VQ][0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd](by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md)
- [UID:0000VR][0x00401b00-0x004038c7.LibJpegMarkerReader](by-memory/0x00401b00-0x004038c7.LibJpegMarkerReader.md)
- [UID:0000VS][0x00403920-0x004048e2.LibJpegCompressApiFrontEnd](by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md)
- [UID:0000VT][0x004048f0-0x004049bb.LibJpegCompressRawDataApi](by-memory/0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md)
- [UID:0000VU][0x004049c0-0x00404a5c.LibJpegCommonApi](by-memory/0x004049c0-0x00404a5c.LibJpegCommonApi.md)
- [UID:0000VV][0x00404a60-0x0040505b.LibJpegInputController](by-memory/0x00404a60-0x0040505b.LibJpegInputController.md)
- [UID:0000VW][0x00405060-0x00405c77.LibJpegMemoryManager](by-memory/0x00405060-0x00405c77.LibJpegMemoryManager.md)
- [UID:0000VX][0x00405c80-0x004063c8.LibJpegDecompressMaster](by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md)
- [UID:0000VY][0x004063d0-0x0040649b.LibJpegUtilityHelpers](by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md)
- [UID:0000VZ][0x004064a0-0x00406d8c.LibJpegMarkerWriter](by-memory/0x004064a0-0x00406d8c.LibJpegMarkerWriter.md)
- [UID:0000W0][0x00406d90-0x00406e46.LibJpegCompressMasterInit](by-memory/0x00406d90-0x00406e46.LibJpegCompressMasterInit.md)
- [UID:0000W1][0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend](by-memory/0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend.md)
- [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md)
- [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md)
- [UID:0000K4][ImageWriters](by-file/ImageWriters.md)

## Changes

- 2026-06-05 projected-path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - Changed to: `NexusTK/third_party/libjpeg/`.
  - Summary/evidence: live IDA MCP lookup confirms the documented IJG island anchor at `0x00401000`; the source-structure decision keeps the JPEG internals in a vendored `third_party/libjpeg/` folder while product-facing wrappers stay with render/image modules.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:90` and `CONFIDENCE:84`.
  - Summary/evidence: IJG libjpeg 6b identity/version, source-file clusters, main range, exclusion boundary, product wrapper handoffs, source-structure decision, rebuild strategy, and many exact memory refs are documented; confidence is capped by remaining entropy/DCT/color/quantizer lower-helper split and unresolved raw JPG screenshot reachability.
