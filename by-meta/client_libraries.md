*** UID:0001QE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Libraries

## Status

- Confidence: medium; this page is a working index and should be expanded as source modules are reviewed.
- Scope: third-party libraries, Windows APIs, and runtime support visible from the recovered client.
- Evidence basis: existing documentation, `source-3/simroot_v2`, local shipped-client DLL metadata from `C:\Users\admin\Desktop\Clone\NexusTK`, official vendor/source pages, and read-only IDA MCP checks on 2026-05-25. `wave3.py` was not executed for this pass.
- Obtained files: [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md) contains official open-source archives, JsonCpp candidate archives, local copied runtime DLL/ASI files, SHA-256 hashes, and [UID:0001QY][README](by-meta/obtained_thirdparty_files/static_embeds/README.md) for source/header files that should be compiled into the rebuilt EXE.

## Separate Dependency Procurement

This section tracks libraries that should be obtained separately instead of reconstructed as NexusTK-owned source. Static third-party code should be vendored from the closest matching upstream source and then compared against the binary. Proprietary middleware should come from the original client distribution or a proper vendor/license path, not random DLL mirrors. Windows system APIs should be linked from the Windows SDK/import libraries.

Confirmed third-party/runtime memory spans are also recorded in [UID:0000VN][-ignored](by-memory/-ignored.md) so future reconstruction passes do not repeatedly assign those bytes to NexusTK product files.

| Dependency | Link/runtime model | Version evidence | Rebuild action |
| --- | --- | --- | --- |
| RAD Bink Video | Dynamic `binkw32.dll` import | Shipped DLL version `1.0s`; IDA imports 18 `_Bink*` APIs; string `binkw32.dll` at `0x0066b848`; SHA256 `65358B3CDE7281DF10CB68AC8E1C9F8705893A47DF33F87BB882073FD0955C90` | Obtain the original redistributable DLL from the client set or a licensed RAD/Epic Game Tools SDK/runtime. Keep local code as Bink wrapper/playback glue. |
| RAD Miles Sound System | Dynamic `Mss32.dll` import plus `Mp3dec.asi` plugin | Shipped `Mss32.dll` and `Mp3dec.asi` versions `6.1c`; IDA imports 37 `_AIL_*` APIs; string `mss32.dll` at `0x0066bc20` | Obtain original redistributables or licensed Miles SDK/runtime. Link against the import library and ship the DLL/plugin. |
| libcurl | Dynamic `libcurl.dll` import | Shipped DLL version `7.48.0`; embedded strings include `libcurl/7.48.0`, `WinSSL`, and Schannel diagnostics; SHA256 `00C75BAB56F50D9DC8EAAA37A2C9C4B9A40B41236FB59E8BAD143EDBC7E1B7B1` | Use curl 7.48.0 source/archive or a matching Windows Schannel build. The observed client does not require separate OpenSSL DLLs. |
| zlib | Statically embedded source | IDA strings identify `deflate 1.1.4` and `inflate 1.1.4`; [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md) is the non-emitting code-island parent/index; B009 split proves zlib read-only data starts at [UID:0003OJ][0x0063211c-0x00632560.Zlib114CrcAndDeflateString](by-memory/0x0063211c-0x00632560.Zlib114CrcAndDeflateString.md) after the libjpeg table island | Vendor zlib 1.1.4 from the official zlib fossils archive under `third_party/zlib/`. |
| LodePNG | Statically embedded source | IDA strings include `LodePNG`, `20160501`, `LodePNGEncoderSettings.filter_strategy`, and `LodePNGState` RTTI-ish names; helper island `0x00443a60-0x00450c9f`; public functions at `0x00443c80`, `0x00443db0`, and `0x00443e40` match upstream `20160501` `lodepng_encode_memory`, `lodepng_encode_file`, and `lodepng_encode32_file` | Vendor `lodepng.cpp`/`lodepng.h` from upstream commit `c6cf08b8910d91b0830666c07845116df1e9b6fc` matching version `20160501`. Treat the PNG file helpers as stock LodePNG APIs, not NexusTK-local `ImageWriters.cpp` code. |
| IJG libjpeg | Statically embedded source | IDA strings include `6b  27-Mar-1998`, `Copyright (C) 1998, Thomas G. Lane`, `Wrong JPEG library version`, and many IJG JPEG diagnostics; code island candidate `0x00401000-0x00414283`; [UID:0000VP][0x00401000-0x00414283.LibJpeg6bCore](by-memory/0x00401000-0x00414283.LibJpeg6bCore.md) is now a non-emitting split/index with exact source-file children for public API, marker, memory, entropy, coefficient, color, sample, quantizer, DCT/IDCT, and controller source files; [UID:0000VS][0x00403920-0x004048e2.LibJpegCompressApiFrontEnd](by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md) is a mixed non-emitting compression source-map page for full `jcapimin.c`/`jdatadst.c`/`jcparam.c` plus the `jcapistd.c` scanline prefix through corrected body end `0x004048e4`; [UID:0000VW][0x00405060-0x00405c77.LibJpegMemoryManager](by-memory/0x00405060-0x00405c77.LibJpegMemoryManager.md) is confirmed as full `jmemmgr.c` with `JPEGMEM` parsing, no `MEM_STATS` strings, backend links to [UID:0000W1][0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend](by-memory/0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend.md), and staged SHA256 `2B57E48BB6DD369C2D46E5827CD1E2553D50E02B062D94C2C17725CA26B642E3`; [UID:0000VX][0x00405c80-0x004063c8.LibJpegDecompressMaster](by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md) is confirmed as full `jdmaster.c`; [UID:0000VY][0x004063d0-0x0040649b.LibJpegUtilityHelpers](by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md) is now the 90/92 `jutils.c` helper-code slice; [UID:000489][0x00631850-0x0063211c.LibJpeg6bReadOnlyTables](by-memory/0x00631850-0x0063211c.LibJpeg6bReadOnlyTables.md) carries the separate libjpeg read-only table island through `0x0063211c` | Vendor IJG `jpegsrc.v6b` under `third_party/libjpeg/`; use `jmemnobs.c` for the first Windows rebuild attempt; exact source-bearing stock pages use formal validator inline import directives rooted at `third_party_embeds/libjpeg/` with blank multiline blocks, while [UID:0000VY][0x004063d0-0x0040649b.LibJpegUtilityHelpers](by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md) keeps blank formal C++ because `jutils.c` also contributes `jpeg_natural_order` data in [UID:000489][0x00631850-0x0063211c.LibJpeg6bReadOnlyTables](by-memory/0x00631850-0x0063211c.LibJpeg6bReadOnlyTables.md). |
| JsonCpp | Statically embedded source | IDA strings/RTTI include `Json::Value`, `collectComments`, `allowDroppedNullPlaceholders`, `rejectDupKeys`, `allowSpecialFloats`, `CharReaderBuilder`, `StreamWriterBuilder`, `OurCharReader`, and `BuiltStyledStreamWriter`; no explicit executable version string found; `Unable to parse token length` is present and `reader error` is absent; `Value::nullSingleton()` and reader/value constructor checks currently favor official upstream commit `b299d3581f4dc670734f1fe1a34fce1282337802` over release tags | Use the staged official `jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802.candidate.zip` archive as the current best source snapshot. Preserve its upstream `include/json/` plus `src/lib_json/` layout for the first rebuild attempt. |
| AhnLab V3 scanner DLLs | Dynamic optional `LoadLibraryA` dependencies | IDA strings `V3PRO32E.DLL`, `V3PCTRL.DLL`, `AhnExCheckFile`, `AhnExGetVirusName`, `V3PCtrl_EnumProcesses`, `V3PCtrl_EnumModules`; DLLs are not present in the observed shipped folder | Treat as optional scanner integration. Obtain only from the original client/security package or official AhnLab distribution, or stub/disable gracefully for rebuilds. |
| Windows SDK/system APIs | OS/import-library dependencies | Imports include `DDRAW`, `WINMM`, `WSOCK32`, `VERSION`, `IMM32`, `WININET`, `KERNEL32`, `USER32`, `GDI32`, `ADVAPI32`, `SHELL32`, `ole32`, `OLEAUT32`, and `IPHLPAPI` | Link Windows SDK import libraries. Do not vendor or reconstruct these APIs. |
| MSVC CRT/STL/Dinkumware support | Statically linked compiler/runtime support | No `MSVCRT`/`MSVCP` import module is present; exception, RTTI, iostream/string, locale, allocator, map/set, numeric conversion, and template support are embedded in the EXE. Confirmed support islands include early SSO-15 byte-string helpers [UID:0003GZ][0x0041b300-0x0041b34a.SmallStringStorageReset](by-memory/0x0041b300-0x0041b34a.SmallStringStorageReset.md), [UID:0000WN][0x0041b6d0-0x0041b9a0.MsvcStringSupportHelpers](by-memory/0x0041b6d0-0x0041b9a0.MsvcStringSupportHelpers.md), [UID:0002CZ][0x0041d3b0-0x0041d431.SmallStringStorageAssign](by-memory/0x0041d3b0-0x0041d431.SmallStringStorageAssign.md), and [UID:0002UG][0x00423960-0x00423a57.SmallString24AssignCopyHelper](by-memory/0x00423960-0x00423a57.SmallString24AssignCopyHelper.md), plus [UID:0001ZT][0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport](by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md), [UID:0001ZV][0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport](by-memory/0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md), [UID:0001ZW][0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport](by-memory/0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport.md), [UID:0001ZX][0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport](by-memory/0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport.md), [UID:00024B][0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport](by-memory/0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport.md), [UID:00024C][0x005cea6d-0x005f66f7.MsvcAcrtStdioLocaleMathSupport](by-memory/0x005cea6d-0x005f66f7.MsvcAcrtStdioLocaleMathSupport.md), and [UID:00024D][0x005f66f7-0x0060c0a0.MsvcSehFuncletIsland](by-memory/0x005f66f7-0x0060c0a0.MsvcSehFuncletIsland.md). B005/B010 rechecks confirm JsonCpp-heavy and FittingRoom-adjacent helpers are not authored by those modules: standard diagnostics, exact padding/boundary evidence, SSO-15 layout, runtime allocation/copy callees, and caller spread show compiler/runtime support consumed by JsonCpp, FittingRoom, later runtime islands, and product/library code. | Rebuild requires a compatible MSVC-era toolchain/runtime model. Do not document static CRT/STL helpers as NexusTK product files unless they contain project glue; source modules should use normal `std::` and vendored JsonCpp code and let the compiler/runtime provide equivalent helper bodies. |

B007's 2026-06-26 IJG libjpeg refresh records [UID:0000VQ][0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd](by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md) as third-party source-map evidence for the product JPEG decode path, while retained unreferenced `jdapistd.c` buffered-image output APIs appear as raw static-library code at `0x004019f0-0x00401af2` before the marker reader.

B010's 2026-06-26 accepted marker-reader callback repairs [UID:0000VR][0x00401b00-0x0040391f.LibJpegMarkerReader](by-memory/0x00401b00-0x0040391f.LibJpegMarkerReader.md) to the full retained `jdmarker.c` span, including raw `jpeg_save_markers` at `0x00403560-0x00403633` and raw `jpeg_set_marker_processor` at `0x004038d0-0x0040391e`; the formal route is `// Static embed: third_party_embeds/libjpeg/jdmarker.c`.

B007's 2026-06-26 compression front-end callback upgrades [UID:0000VS][0x00403920-0x004048e2.LibJpegCompressApiFrontEnd](by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md) to the full mixed source-map decision: full retained `jcapimin.c` with raw/no-function public helpers (`jpeg_abort_compress`, `jpeg_write_m_header`, `jpeg_write_m_byte`, and `jpeg_write_tables`), full `jdatadst.c` destination-manager callbacks, full `jcparam.c` default/quality/colorspace/progression sequence including `0x00403ed0` as `jpeg_set_linear_quality`, and the `jcapistd.c` prefix through `jpeg_start_compress` and `jpeg_write_scanlines`. MCP session `80de0a67` proves `jpeg_write_scanlines` returns at `0x004048e3`, the correct half-open body end is `0x004048e4`, `0x004048e4-0x004048f0` is padding, and [UID:0000VT][0x004048f0-0x004049bb.LibJpegCompressRawDataApi](by-memory/0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md) starts `jpeg_write_raw_data`. [UID:0000VS][0x00403920-0x004048e2.LibJpegCompressApiFrontEnd](by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md) intentionally keeps a blank formal reconstruction block: no handwritten C++ and no static-embed marker are safe in that mixed page because full `jcapistd.c` crosses into [UID:0000VT][0x004048f0-0x004049bb.LibJpegCompressRawDataApi](by-memory/0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md).

B001's 2026-06-26 implementation converts [UID:0000VP][0x00401000-0x00414283.LibJpeg6bCore](by-memory/0x00401000-0x00414283.LibJpeg6bCore.md) to a non-emitting third-party split/index. The source-bearing stock children [UID:00045M][0x00401000-0x004011a1.LibJpegErrorManager](by-memory/0x00401000-0x004011a1.LibJpegErrorManager.md)-[UID:00046D][0x00414020-0x00414283.LibJpegFloatForwardDct](by-memory/0x00414020-0x00414283.LibJpegFloatForwardDct.md) cover `jerror.c`, the remaining decompression/compression controller families, entropy, color, sampling, quantizers, and DCT/IDCT source files. Their current reconstruction route is formal validator inline import directives rooted at `third_party_embeds/libjpeg/` with blank multiline blocks; the earlier static-embed marker-comment form is historical.

B009's 2026-06-26 raw-data API callback updates [UID:0000VT][0x004048f0-0x004049bb.LibJpegCompressRawDataApi](by-memory/0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md) as a retained-but-unreferenced public IJG compression API: MCP session `80de0a67` confirms the `0xcb` byte `jpeg_write_raw_data` body, no function at `0x004049bb`, successor `0x004049c0`, no direct xrefs to `0x004048f0`, product screenshot use of the adjacent scanline API instead, and the staged `jcapistd.c:119-161` static-embed route.

B008's 2026-06-26 decompression master callback confirms [UID:0000VX][0x00405c80-0x004063c8.LibJpegDecompressMaster](by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md) as stock `jdmaster.c` routed through `// Static embed: third_party_embeds/libjpeg/jdmaster.c`. MCP session `80de0a67` confirms the eight-function inventory from `jpeg_calc_output_dimensions` through `finish_output_pass`, callback installs from `jinit_master_decompress`, master-selection fanout into decompression initializers, retained no-xref `jpeg_new_colormap`, predecessor padding after `0x00405c77`, exact range `0x00405c80-0x004063c8`, padding to `0x004063d0`, and [UID:0000VY][0x004063d0-0x0040649b.LibJpegUtilityHelpers](by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md) / `jutils.c` successor. The staged source hash is `C9F18A007511047A50DB0B14C54E4D88C279571EC36824B70C3C20232EF7A8FE`. Product wrapper boundaries remain unchanged: image decode and screenshot code call public libjpeg APIs, but `jdmaster.c` stays in the third-party library folder.

B009's 2026-06-27 utility-helper/data split callback raises [UID:0000VY][0x004063d0-0x0040649b.LibJpegUtilityHelpers](by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md) to `90/92` as the `jutils.c` helper-code slice and creates [UID:000489][0x00631850-0x0063211c.LibJpeg6bReadOnlyTables](by-memory/0x00631850-0x0063211c.LibJpeg6bReadOnlyTables.md) for the separate libjpeg `.rdata` table island. MCP session/database `80de0a67` proves the five helper bodies, IJG caller fanout, no modeled IJG callees, padding boundaries, staged `jutils.c` SHA256 `2CAB735C6EA1BCA55F4C94A72C73035A0A161378403A6BD849B350DF71DB92D6`, and `jpeg_natural_order` at `0x00631c14-0x00631d54`. The split corrects the old broad zlib read-only-data start: zlib begins at `0x0063211c`.

B010's 2026-06-26 memory-manager callback confirms [UID:0000VW][0x00405060-0x00405c77.LibJpegMemoryManager](by-memory/0x00405060-0x00405c77.LibJpegMemoryManager.md) as stock `jmemmgr.c`. Its current reconstruction route is the formal validator inline import directive rooted at `third_party_embeds/libjpeg/` in the page's `RECONSTRUCTION_CPP CODE` header, with blank multiline CPP/H blocks. The earlier `// Static embed: third_party_embeds/libjpeg/jmemmgr.c` wording is explicitly superseded historical marker syntax and is not current reconstruction authority. MCP session `80de0a67` confirms the 15-function inventory from `jinit_memory_mgr` through `self_destruct`, public create-path callers, callback-table installation, `JPEGMEM` at `0x00671a64`, `%ld%c` at `0x00671a6c`, predecessor padding at `0x0040505b-0x0040505f`, successor padding at `0x00405c77-0x00405c7f`, and [UID:0000VX][0x00405c80-0x004063c8.LibJpegDecompressMaster](by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md) / `jdmaster.c` successor. The staged source hash is `2B57E48BB6DD369C2D46E5827CD1E2553D50E02B062D94C2C17725CA26B642E3`; `NO_GETENV` was not active because the binary includes the `JPEGMEM` parser path; `MEM_STATS` was not compiled because optional stats strings are absent. The memory manager remains paired with [UID:0000W1][0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend](by-memory/0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend.md) / `jmemnobs.c`, and product wrapper boundaries remain unchanged.

B009's 2026-06-21 Rule 26 pass adds [UID:0002AJ][0x0069c044-0x0069d000.MsvcRuntimeMutableDataTail](by-memory/0x0069c044-0x0069d000.MsvcRuntimeMutableDataTail.md) as the final mutable `.data` zero-fill runtime tail in this dependency family, alongside [UID:00028F][0x00672eb4-0x006738c0.MsvcDinkumwareRuntimeMutableData](by-memory/0x00672eb4-0x006738c0.MsvcDinkumwareRuntimeMutableData.md), [UID:000273][0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail](by-memory/0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail.md), [UID:00024B][0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport](by-memory/0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport.md), and [UID:00024C][0x005cea6d-0x005f66f7.MsvcAcrtStdioLocaleMathSupport](by-memory/0x005cea6d-0x005f66f7.MsvcAcrtStdioLocaleMathSupport.md). The page records `_Init_locks`, Dinkumware locale/facet/ios state, encoded OS API-pointer cache, GS failure context, SCRT startup/TLS/static-guard state, ACRT lowio/stdio/file table storage, timezone, file, locale, and multibyte runtime state; it remains `RECONSTRUCTABLE:FALSE` with no NexusTK owner or emitted C++.

B002's 2026-06-24 [UID:00030X][0x00421260-0x00421290.WideFormatWrapper128](by-memory/0x00421260-0x00421290.WideFormatWrapper128.md) callback adds a confirmed fixed-buffer secure wide-format support item to this MSVC CRT/UCRT family. Current MCP session `80de0a67` and local UCRT header evidence classify it as non-emitting runtime/header support: it calls [UID:0000WO][0x0041b9a0-0x0041b9de.CrtStdioCommonSprintfGlue](by-memory/0x0041b9a0-0x0041b9de.CrtStdioCommonSprintfGlue.md) and `___stdio_common_vswprintf_s`, passes a null locale and fixed count `0x80`, normalizes negative results to `-1`, has exactly one `FittingRoomListPane::OnPaint` caller for caller-local `wchar_t Src[128]`, and has no pointer/data/immediate route. Rebuild source should express caller-level secure formatting or compatible CRT/header use rather than emit a NexusTK-owned `StringUtil` helper.

B005's 2026-06-24 [UID:0002UA][0x004236e0-0x00423710.WideFormatWrapper](by-memory/0x004236e0-0x00423710.WideFormatWrapper.md) callback adds the fixed-260 sibling to this MSVC CRT/UCRT support family. Current MCP session `80de0a67`, server health, and PE SHA-256 `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632` prove exact `sub_4236E0` size `0x30`, the unique 48-byte body, nine-byte predecessor padding, and [UID:0002UB][0x00423710-0x00423777.FittingRoomStorageDestructorFreeHelper](by-memory/0x00423710-0x00423777.FittingRoomStorageDestructorFreeHelper.md) successor boundary. The body is the same local stdio-options plus `___stdio_common_vswprintf_s` secure wide-format shape as [UID:00030V][0x00421230-0x0042125d.WideFormatWrapper32](by-memory/0x00421230-0x0042125d.WideFormatWrapper32.md) and [UID:00030X][0x00421260-0x00421290.WideFormatWrapper128](by-memory/0x00421260-0x00421290.WideFormatWrapper128.md), with null locale, fixed count `0x104`, `va_list` forwarding, and negative-result normalization to `-1`. It has 48 code xrefs across fitting-room, map/minimap, profile/settings, and screenshot path-formatting callers, zero data xrefs, no VA/RVA pointer-byte route, and representative caller-local 260-wide stack buffers. Rebuild source should keep the formatting expressions in the caller methods and rely on compatible CRT/header/toolchain support; do not add a standalone NexusTK `StringUtil`, fitting-room, aggregate, or helper-file source item for this range.

## IDA Import Table Summary

[UID:0001Z6][0x0060d000-0x0060d670.ImportDataSection](by-memory/0x0060d000-0x0060d670.ImportDataSection.md) is the section-level import-table map. IDA MCP `imports offset=0 count=0` on 2026-05-27 reports 395 import-address-table entries across 17 modules:

| Dependency family | Modules | Count | Rebuild action |
| --- | --- | ---: | --- |
| Windows SDK/system APIs | `ADVAPI32`, `DDRAW`, `GDI32`, `IMM32`, `IPHLPAPI`, `KERNEL32`, `OLEAUT32`, `SHELL32`, `USER32`, `VERSION`, `WININET`, `WINMM`, `WSOCK32`, `ole32` | 334 | Link the corresponding Windows SDK import libraries; keep product source in the callers/wrappers. |
| Proprietary middleware runtimes | `binkw32`, `mss32` | 55 | Obtain original redistributables or licensed SDK/import libraries; do not reconstruct the runtime internals. |
| Open-source dynamic runtime | `libcurl` | 6 | Use a matching libcurl 7.48.0 Windows Schannel build or rebuild from source; keep it as a DLL/import-library dependency. |

The import section itself is `compiler/linker-generated`. It should not become a handwritten source file, but its module/function list is authoritative evidence for which libraries the rebuilt project must link or ship.

## Bink Video

The client uses RAD Game Tools Bink for startup/intro video playback.

Evidence:

- [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md) owns the generic Bink playback pane at `0x005c0040-0x005c045b`.
- [UID:00007H][LogoPlayerPane](by-class/LogoPlayerPane.md) opens startup Bink segments through `0x005c0110`.
- `VideoPlayerPane::OnPaint` owns frame servicing and presentation. It calls `BinkWait`, optionally `BinkService`, then `BinkDoFrame`, `BinkCopyToBuffer`, and `BinkNextFrame`; it preserves the original quirk that `BinkDoFrame` is skipped only when both `BinkWait` and `BinkService` report no work.
- The inherited `TimerHandler` facet dispatches playback completion through `VideoPlayerPane::OnTimer(int timerId, int arg0, int arg1)`. Exact timer id `'ViSD'` (`0x56695344`) invokes virtual `OnClose`; other timer ids delegate to `Pane::OnTimer`.
- `OpenBinkVideo` calls `BinkSetSoundSystem(BinkOpenDirectSound, SoundManager::GetDirectSound(...))`, closes any old handle, registers the `term` app notification, and calls `BinkOpen` with flags `67633152` / `0x04080000`.
- `VideoPlayerPane` is NexusTK-authored wrapper code. Its source declaration and methods regenerate the primary/EventHandler/TimerHandler vtables, RTTI, adjustor thunks, and deleting-destructor wrapper; those compiler artifacts are not Bink runtime source and must not be emitted as literal tables or handwritten thunks.
- Three private wrapper bodies for closing the current Bink handle, enabling/disabling Bink sound, and seeking a Bink frame have no current xrefs or encoded pointer routes. Their exact source-shaped bodies and exclusive use of `VideoPlayerPane` state support retaining them as class helpers; the negative reachability evidence is a liveness caveat, not a reason to move them into proprietary middleware or drop them.
- IDA caller evidence shows the first `BinkOpen` argument is a pointer into the `LogoPlayerPane` AUTOBUF payload. A public Bink flag reference identifies `0x04000000` as `BINKFROMMEMORY` and `0x00080000` as `BINKNOSKIP`, confirming memory-backed no-skip playback for the startup segments.
- 2026-06-20 B003 reanalysis resolves the local source direction for `0x005c0110`: model it as protected `VideoPlayerPane::OpenBinkVideo(const void *segmentData, unsigned int segmentSize)`. Both current direct callers are `LogoPlayerPane`, but they pass memory-backed slices from the segmented startup payload into a helper that operates on `VideoPlayerPane::m_binkHandle`, registers `term`, configures DirectSound, and lives inside the base video-pane helper island. The size argument remains source-visible because both callers pass it even though the recovered helper body does not consume it.
- External flag reference: [Unity Bink player, BINK_OPEN_FLAGS list](https://nickdu.com/?p=842).

Runtime/version evidence:

- Local shipped file: `C:\Users\admin\Desktop\Clone\NexusTK\binkw32.dll`.
- Version info: `FileVersion=1.0s`, `ProductName=Bink`, `CompanyName=RAD Game Tools, Inc.`, `FileDescription=Bink Video`.
- Hash: SHA256 `65358B3CDE7281DF10CB68AC8E1C9F8705893A47DF33F87BB882073FD0955C90`.
- Official source/vendor reference: RAD/Epic Game Tools Bink page and Bink history. The official history contains `Changes from 1.0r to 1.0s (08-08-2000)` and `Changes from 1.0s to 1.0t (09-09-2000)`, matching the observed `1.0s` runtime version window.

Rebuild/procurement decision:

- Treat Bink as proprietary middleware. The rebuild should use the original redistributable `binkw32.dll` from the client set or a licensed RAD/Epic Game Tools SDK/runtime.
- Do not reconstruct Bink decoder code from decompiler output. Reconstruct only NexusTK wrapper code such as `VideoPlayerPane`, `LogoPlayerPane`, and Bink sound binding.

Open questions:

- Find exact original source/header spelling for `OpenBinkVideo`, the BINK frame fields, and the memory-open flag names if a matching Bink SDK/header set becomes available.
- Explain why both `LogoPlayerPane` callers pass a segment size/remaining-size parameter to `0x005c0110` when the recovered helper body does not consume that argument; retain the parameter in source-facing docs until original evidence proves it should be dropped.

## Miles / DirectSound Bridge

The Bink path depends on the client sound manager to provide DirectSound.

Evidence:

- `SoundManager::GetDirectSound` is called only by the Bink open helper in current evidence.
- Prior Wave2 notes identify this bridge as the corrected owner for the old fake `LogoPlayerPaneHelper_57A7E0` projection.
- IDA imports 37 Miles `_AIL_*` APIs from `mss32.dll`, including sample, stream, redbook, DirectSound, callback, and startup/shutdown functions.
- Local shipped files:
  - `C:\Users\admin\Desktop\Clone\NexusTK\Mss32.dll`, version `6.1c`, SHA256 `2A515199CC7A2E1CCD8D756EFDAAB07CEDD5C3052309EF1C7499C2560E2097BD`.
  - `C:\Users\admin\Desktop\Clone\NexusTK\Mp3dec.asi`, version `6.1c`, SHA256 `0A6DB88A5FAD28168C1DAC700473C5709B17802C33E36B2668C3300C1E580FAD`.
- Official source/vendor reference: RAD/Epic Game Tools Miles page and Miles history. The official history contains `Changes from 6.1b to 6.1c (10-15-2001)`, matching the observed `6.1c` runtime.

Rebuild/procurement decision:

- Treat Miles as proprietary middleware. The rebuild should link against the matching import library and ship `Mss32.dll` plus `Mp3dec.asi` from the original client set or a licensed Miles SDK/runtime.
- Do not migrate `_AIL_*` behavior into NexusTK source. Keep project-owned sound code in [UID:0000NV][SoundManager](by-file/SoundManager.md), [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md), and local Bink/Miles bridge glue.

## zlib 1.1.4

The client contains bundled zlib 1.1.4 compression/decompression support.

Evidence:

- [UID:0000PC][Zlib](by-file/Zlib.md) owns the third-party support-family hypothesis for `0x004142c0-0x00419e56` and projects source under `NexusTK/third_party/zlib/`.
- IDA strings identify `deflate 1.1.4` and `inflate 1.1.4` copyright/version text.
- [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md) is the non-emitting parent/index for the full code island: public wrappers/checksums, parent-only `deflate.c` setup/reset notes, `deflate.c` workers, inflate API/allocator/Adler, `trees.c` output helpers, and inflate internals.
- [UID:0000W2][0x004142c0-0x00414565.ZlibPublicCompressChecksum](by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md) maps the public `compress2`, `compress`, `uncompress`, and `crc32` front end to `compress.c`, `uncompr.c`, and `crc32.c`.
- [UID:0000W4][0x00414820-0x004158aa.ZlibDeflateWorkers](by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md) maps the narrowed `deflate.c` worker/API-tail cluster: `deflate`, `putShortMSB`, `flush_pending`, `deflateEnd`, `lm_init`, `deflate_stored`, `fill_window`, `read_buf`, `deflate_fast`, `longest_match`, and `deflate_slow`.
- [UID:0000W5][0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler](by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md) remains the separate public inflate API, default callback, and Adler-32 sibling between `deflate.c` workers and `trees.c`.
- [UID:0004IK][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md) maps stock zlib `trees.c` deflate output helpers from `_tr_init` through `copy_block`, including optimized `tr_static_init`, tree builders/scanners/senders, block compression, and bit-output helpers.
- [UID:0000W6][0x00417ba0-0x00419e56.ZlibInflateInternals](by-memory/0x00417ba0-0x00419e56.ZlibInflateInternals.md) maps block, code, tree, flush, and fast-inflate internals to `infblock.c`, `infcodes.c`, `inftrees.c`, `infutil.c`, and `inffast.c`.
- [UID:0003OJ][0x0063211c-0x00632560.Zlib114CrcAndDeflateString](by-memory/0x0063211c-0x00632560.Zlib114CrcAndDeflateString.md) covers only zlib `crc_table[256]`, alignment, the `deflate.c` copyright/version string, and alignment before the configuration table. B009 proves `0x00631850-0x0063211c` is libjpeg, so zlib read-only data starts at `0x0063211c`.
- [UID:0004IL][0x00632560-0x006325d8.ZlibDeflateConfigurationTable](by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md) corrects the former runtime-tail assumption at `0x00632560`: B002 MCP bytes/xrefs identify zlib `deflate.c` `configuration_table[10]`, referenced from `deflate` at `0x004149b4`. Its source declaration is emitted once by UID0000W4's stock `deflate.c` import.
- [UID:0003P7][0x00633050-0x00633080.ZlibInflateVersionString](by-memory/0x00633050-0x00633080.ZlibInflateVersionString.md) maps the retained zlib inflate copyright string inside the broad runtime-tail parent.
- [UID:000089][MetaTable](by-class/MetaTable.md) consumes `Uncompress` and `Crc32` in `DecompressAndValidateData`; the metadata subsystem does not own those helpers.
- DAT-backed image, palette, startup-logo, and resource paths also consume decompression output through the public zlib wrapper.

Source-structure decision:

- Keep zlib under `third_party/zlib/` or an equivalent support-library folder.
- Preserve stock zlib source-file boundaries (`compress.c`, `uncompr.c`, `crc32.c`, `deflate.c`, `inflate.c`, `zutil.c`, `adler32.c`, `trees.c`, `infblock.c`, `infcodes.c`, `inftrees.c`, `infutil.c`, `inffast.c`) unless later binary comparison proves the client used a flattened or patched copy.
- Structural UID correction: canonical UID00041N/UID00041O remain MIDI pages. Fresh exact Zlib UIDs 0004IK/0004IL replace the historical duplicate-header misroutes; UID0004IK imports `trees.c`, while UID0004IL uses a formal covered-by-UID0000W4 block and does not duplicate `deflate.c`.
- Treat generated `auto-generated/NexusTK/third_party/zlib/Zlib.cpp` as an empty-marker generator artifact, not the preferred source layout.
- Do not migrate `Crc32`, `Adler32`, `InflateFast`, or inflate/deflate internals into `DATArchive`, `MetaTable`, palette, startup-logo, or image-library modules.

Rebuild/procurement decision:

- Use the official zlib fossils archive for `zlib-1.1.4.tar.gz` or equivalent exact source package.
- Use the staged `source-3/third_party_embeds/zlib` tree as the working source embed and let compilation regenerate code/data tables. Do not paste decompiler-derived zlib bodies into by-memory pages.

## LodePNG

### 2026-08-24 Complete Source And Route Authority

- Exact upstream authority is commit `c6cf08b8910d91b0830666c07845116df1e9b6fc`, LodePNG version `20160501`. Staged `third_party_embeds/lodepng/lodepng.cpp` is SHA256 `71F9A45829F9AF7A6675200153DAAB5D791846A7EC4C5385241AC6F1E35B629A`, 220,220 bytes and 6,223 LF; `third_party_embeds/lodepng/lodepng.h` is SHA256 `9B330CA0224E85EB8937DC83627BDFA0285C6CC6691223D3FD51D8987A2D284B`, 82,029 bytes and 1,759 LF.
- The default feature set is the complete source configuration represented by 228 physical definitions and 226 default-active definitions: built-in zlib compression/decompression is active, while the two custom-zlib fallback definitions are mutually exclusive. The imported header provides 12 public types and the implementation owns seven internal types plus 16 named source data definitions.
- [UID:00007E][LodePNGState](by-class/LodePNGState.md) is the sole formal validator route for the exact CPP/header pair. UID0000XH, UID0000XI, UID0000XJ, UID000274, UID0003AP, UID00057C, UID00057D, and UID00057E emit compiler-covered comments; UID0000XE, UID0000XF, UID0000XG, and UID00024Q remain non-emitting indexes. Semantic compilation-unit ownership remains [UID:0000KW][LodePNG](by-file/LodePNG.md).
- Exact binary membership is the helper island `0x00443a60-0x00450c9f`, [UID:00057C][0x0060f200-0x0060f4c0.LodePngConstantTables](by-memory/0x0060f200-0x0060f4c0.LodePngConstantTables.md) at `0x0060f200-0x0060f4c0`, [UID:0003AP][0x0060f4c0-0x006104ac.LodePngStaticReadOnlyData](by-memory/0x0060f4c0-0x006104ac.LodePngStaticReadOnlyData.md) at `0x0060f4c0-0x006104ac`, [UID:00057D][0x0064170c-0x006417a0.LodePngStateRttiDescriptors](by-memory/0x0064170c-0x006417a0.LodePngStateRttiDescriptors.md) at `0x0064170c-0x006417a0`, mutable version/CRC data `0x0066d000-0x0066d408`, and [UID:00057E][0x00674240-0x00674278.LodePngStateTypeDescriptors](by-memory/0x00674240-0x00674278.LodePngStateTypeDescriptors.md) at `0x00674240-0x00674278`. The respective successors are excluded.

The screenshot PNG writer uses a bundled LodePNG encoder backend.

Evidence:

- [UID:0000KW][LodePNG](by-file/LodePNG.md) owns the third-party codec hypothesis for the encode front end and state class.
- [UID:0000XE][0x00443a60-0x00450c9f.LodePngHelperIslandInventory](by-memory/0x00443a60-0x00450c9f.LodePngHelperIslandInventory.md) records the current IDA-modeled helper inventory, direct encode-root callgraph, and raw `0x00444740-0x00444be0` boundary caveat.
- [UID:0000XF][0x00443c80-0x00443e5d.LodePngEncodeFrontEnd](by-memory/0x00443c80-0x00443e5d.LodePngEncodeFrontEnd.md) records the public encode/write chain from `lodepng_encode_memory` at `0x00443c80` through `lodepng_encode32_file` at `0x00443e40`.
- [UID:0000XG][0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers](by-memory/0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers.md) maps the raw unmodeled helper block to `lodepng_error_text`, settings initialization, color-mode initialization, and palette cleanup patterns.
- [UID:0000XH][0x004460f0-0x004461f6.LodePngStateInit](by-memory/0x004460f0-0x004461f6.LodePngStateInit.md) maps `0x004460f0` to the upstream state/default initializer.
- [UID:00057C][0x0060f200-0x0060f4c0.LodePngConstantTables](by-memory/0x0060f200-0x0060f4c0.LodePngConstantTables.md) records exact default-compression, DEFLATE, and Adam7 values, bytes, and LodePNG-local xrefs.
- [UID:00057D][0x0064170c-0x006417a0.LodePngStateRttiDescriptors](by-memory/0x0064170c-0x006417a0.LodePngStateRttiDescriptors.md) and [UID:00057E][0x00674240-0x00674278.LodePngStateTypeDescriptors](by-memory/0x00674240-0x00674278.LodePngStateTypeDescriptors.md) record the complete compiler-generated state RTTI graph and its two decorated type names.
- IDA strings include `LodePNG`, `.?AULodePNGState@@`, `.?AVState@lodepng@@`, PNG error text, and `LodePNGEncoderSettings.filter_strategy`.
- IDA string `20160501` at `0x0060f4c0` is strong version evidence for the upstream LodePNG revision used by this binary.
- Local source comparison against the obtained `20160501` archive maps `0x00443c80` to `lodepng_encode_memory`, `0x00443db0` to `lodepng_encode_file`, and `0x00443e40` to `lodepng_encode32_file`. These are stock public LodePNG APIs, not NexusTK-local [UID:0000K4][ImageWriters](by-file/ImageWriters.md) functions.
- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) owns when screenshots are captured and written.

Source-structure decision:

- Keep the encoder implementation under `third_party/lodepng.cpp` or equivalent bundled-code placement.
- For rebuilds, vendor upstream `lodepng.cpp`/`lodepng.h` from the LodePNG `20160501` revision. Call stock public APIs such as `lodepng_encode32_file` from screenshot code unless later source evidence proves an additional NexusTK-local wrapper existed.
- Do not migrate `LodePNGState`, `0x00443c80`, or the anonymous encoder helper cluster into screenshot capture, DAT/resource, or generic render modules.
- Treat `0x00443a60-0x00450c9f` as the current LodePNG helper-island candidate. The old `0x00450ca0-0x00456031` tail is now excluded because it overlaps [UID:0000XK][0x00450ca0-0x0045381b.MiniMapDialog](by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md), [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md), and shared product support helpers.

External source references:

- <https://lodev.org/lodepng/>
- <https://github.com/lvandeve/lodepng>

## IJG libjpeg 6b

The executable contains statically linked Independent JPEG Group library code.

Evidence:

- IDA strings identify IJG libjpeg directly: `Copyright (C) 1998, Thomas G. Lane` at `0x00671268` and version string `6b  27-Mar-1998` at `0x0067128c`.
- IDA strings include canonical IJG diagnostics such as `Wrong JPEG library version: library is %d, caller expects %d`, `JPEG parameter struct mismatch`, `Not a JPEG file: starts with 0x%02x 0x%02x`, `Invalid JPEG file structure`, `Premature end of JPEG file`, and `JPEGMEM`.
- [UID:0000VP][0x00401000-0x00414283.LibJpeg6bCore](by-memory/0x00401000-0x00414283.LibJpeg6bCore.md) bounds the current code-island candidate at `0x00401000-0x00414283`.
- [UID:0000VQ][0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd](by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md) maps the product decode path to `jdapimin.c`/`jdapistd.c`.
- [UID:0000VR][0x00401b00-0x0040391f.LibJpegMarkerReader](by-memory/0x00401b00-0x0040391f.LibJpegMarkerReader.md) maps the decompression marker parser to `jdmarker.c`, including 18 modeled marker helpers, raw public `jpeg_save_markers` / `jpeg_set_marker_processor`, and the static-embed target `third_party_embeds/libjpeg/jdmarker.c`.
- [UID:0000VS][0x00403920-0x004048e2.LibJpegCompressApiFrontEnd](by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md) maps the retained JPEG screenshot writer path to a mixed non-emitting compression source-map page: full `jcapimin.c` with raw public helper bodies, full `jdatadst.c`, full `jcparam.c`, and `jcapistd.c` through `jpeg_write_scanlines`; the filename slug is legacy, while the proven half-open body end is `0x004048e4`.
- [UID:0000VT][0x004048f0-0x004049bb.LibJpegCompressRawDataApi](by-memory/0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md) maps stock `jpeg_write_raw_data` to staged `third_party_embeds/libjpeg/jcapistd.c`; B009's 2026-06-26 MCP refresh found no direct product caller to this retained raw-data API and routes formal reconstruction through `// Static embed: third_party_embeds/libjpeg/jcapistd.c`.
- [UID:0000VU][0x004049c0-0x00404a5c.LibJpegCommonApi](by-memory/0x004049c0-0x00404a5c.LibJpegCommonApi.md) maps `jcomapi.c`.
- [UID:0000VV][0x00404a60-0x0040505b.LibJpegInputController](by-memory/0x00404a60-0x0040505b.LibJpegInputController.md) is the complete retained IJG libjpeg 6b `jdinput.c` unit at `94/95`. B004 MCP database `545b4991` and B010's fresh read-only sessions against current database `5a570ede` proved all eight identities: `jinit_input_controller` `0x00404a60`, `start_input_pass` `0x00404ab0`, `per_scan_setup` `0x00404af0`, `latch_quant_tables` `0x00404ca0`, `finish_input_pass` `0x00404d50`, `consume_markers` `0x00404d70`, `initial_setup` `0x00404e30`, and `reset_input_controller` `0x00405020`. This corrects the old swapped/vague start/finish mapping.
- UID0000VV is one source-file range rather than a split: four NOPs at `0x00404a5c-0x00404a60`, five at `0x0040505b-0x00405060`, and seven internal NOP spans separate the eight bodies without omitted code or embedded data. `jcomapi.c` precedes it and `jmemmgr.c` follows it.
- The controller dependency graph remains library-internal: `jpeg_CreateDecompress` is the one external direct caller of the GLOBAL initializer; callback data xrefs keep the METHODDEF start/finish/consume/reset routines live; LOCAL setup/latch helpers have internal direct callers; consume/reset use [UID:0000VR][0x00401b00-0x0040391f.LibJpegMarkerReader](by-memory/0x00401b00-0x0040391f.LibJpegMarkerReader.md); init/latch allocate through [UID:0000VW][0x00405060-0x00405c77.LibJpegMemoryManager](by-memory/0x00405060-0x00405c77.LibJpegMemoryManager.md); first-pass control comes from [UID:0000VX][0x00405c80-0x004063c8.LibJpegDecompressMaster](by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md); and setup uses [UID:0000VY][0x004063d0-0x0040649b.LibJpegUtilityHelpers](by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md) `jdiv_round_up`.
- Windows `jconfig.h` unsigned-char `boolean` plus four 32-bit callbacks and public/private state produces the observed 24-byte controller; `JQUANT_TBL` is the observed 130 bytes. Binary behavior matches 8-bit samples, ten components, maximum dimension 65500, four scan components, sampling factor four, DCT size eight, ten MCU blocks, and permanent/image pools 0/1.
- Staged `jdinput.c` SHA256 is `F1F6B042AA907FE622AA7C94B21D71E61F7F306E10988148C42CC7D50F667E76`. Header hashes are `jinclude.h` `A6433E5EA0030F4BFFD41BCC2F064008AFD79DE4270CF28494BD43D2FBC5DA06`, `jpeglib.h` `B34B3D9897820302CC23BA60217157F75E03DB8C537A7D4703FF0BC8C9FC048B`, `jconfig.h` `1D0894775067D15163181F26D3039E24B34501CA7E5380DD2DDB8526DD05B250`, `jmorecfg.h` `262138C3433E81E84E9F6811B38B5DC63E6F161E9B952AFB0FF61B4A39B697A9`, `jpegint.h` `F2FBBF47DA9FE7CC9E4813235D71E1252EC4662E3ECB8823BD4D499492125153`, and `jerror.h` `324F058E0DC17408EA83A8D47D0A7A1F6BA7553D653F709A9BE275971F539FEC`.
- UID0000VV formally imports `third_party_embeds/libjpeg/jdinput.c` plus those six headers through the validator inline directive; its managed CPP/H bodies remain blank. Product image-loader/writer ownership, broad-parent emission, per-helper splitting, blank/no-code treatment, pasted/decompiler-shaped source, and legacy `// Static embed:` comments are rejected. Whole-library compiler flags, object ordering, and rebuilt-binary equivalence remain a broader final-audit cap, not a child import blocker.
- Supervisor Gate 2B session/database `d4f56e9b-487d-4a54-bdf8-f5ba5d42b260` / `5a570ede` closed the UID0000VV IDA source-quality handoff: incomplete `jpeg_decompress_struct` ordinal `936`, four-byte `j_decompress_ptr` ordinal `937`, and all eight exact upstream names/prototypes plus regular/repeatable function comments were applied and read back. Ranges, first items, frames, blank address comments, seven `void` no-value-return bodies, and `consume_markers` integer status returns were preserved. The saved IDB is SHA256 `8E1AB47A7FDE155EFAADCFFC7EBB431B6C7DC8B85D1DC45A24174182B1D7FAA7`; catalog entry `0345` records closure. B010 made no IDA mutation, and no speculative full JPEG structure was introduced.
- [UID:0000VW][0x00405060-0x00405c77.LibJpegMemoryManager](by-memory/0x00405060-0x00405c77.LibJpegMemoryManager.md) maps `jmemmgr.c`.
- [UID:0000VX][0x00405c80-0x004063c8.LibJpegDecompressMaster](by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md) maps stock `jdmaster.c`; B008 confirms MCP session `80de0a67`, exact range `0x00405c80-0x004063c8`, predecessor padding after `0x00405c77`, padding to [UID:0000VY][0x004063d0-0x0040649b.LibJpegUtilityHelpers](by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md) / `jutils.c`, staged SHA256 `C9F18A007511047A50DB0B14C54E4D88C279571EC36824B70C3C20232EF7A8FE`, and the formal static-embed route `// Static embed: third_party_embeds/libjpeg/jdmaster.c`.
- [UID:0000VY][0x004063d0-0x0040649b.LibJpegUtilityHelpers](by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md) maps the `jutils.c` helper-code slice; B009 confirms five helpers, caller fanout, no modeled IJG callees, staged SHA256 `2CAB735C6EA1BCA55F4C94A72C73035A0A161378403A6BD849B350DF71DB92D6`, and blank formal C++ because `jpeg_natural_order` is data-side.
- [UID:000489][0x00631850-0x0063211c.LibJpeg6bReadOnlyTables](by-memory/0x00631850-0x0063211c.LibJpeg6bReadOnlyTables.md) maps the libjpeg read-only table island, including `jutils.c` `jpeg_natural_order` at `0x00631c14-0x00631d54`, and establishes the `0x0063211c` libjpeg/zlib split.
- [UID:0000VZ][0x004064a0-0x00406d90.LibJpegMarkerWriter](by-memory/0x004064a0-0x00406d90.LibJpegMarkerWriter.md) maps `jcmarker.c` and emits `// Static embed: third_party_embeds/libjpeg/jcmarker.c`.
- [UID:0000W0][0x00406d90-0x00406e46.LibJpegCompressMasterInit](by-memory/0x00406d90-0x00406e46.LibJpegCompressMasterInit.md) maps `jcinit.c`.
- [UID:0000W1][0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend](by-memory/0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend.md) maps `jmemnobs.c`, not a temp-file backing-store backend.
- B001 resolved the remaining source-file child map:
  - [UID:00045M][0x00401000-0x004011a1.LibJpegErrorManager](by-memory/0x00401000-0x004011a1.LibJpegErrorManager.md) maps `jerror.c`.
  - [UID:00045N][0x00406ee0-0x004075b7.LibJpegDecompressCoefficientController](by-memory/0x00406ee0-0x004075b7.LibJpegDecompressCoefficientController.md) maps `jdcoefct.c`.
  - [UID:00045O][0x004075c0-0x00408a58.LibJpegDecompressMainController](by-memory/0x004075c0-0x00408a58.LibJpegDecompressMainController.md) maps `jdmainct.c`.
  - [UID:00045P][0x00408a60-0x004090b0.LibJpegHuffmanDecoder](by-memory/0x00408a60-0x004090b0.LibJpegHuffmanDecoder.md) maps `jdhuff.c`.
  - [UID:00045Q][0x004090b0-0x00409e0f.LibJpegProgressiveHuffmanDecoder](by-memory/0x004090b0-0x00409e0f.LibJpegProgressiveHuffmanDecoder.md) maps `jdphuff.c`.
  - [UID:00045R][0x00409e10-0x0040a0a5.LibJpegInverseDctManager](by-memory/0x00409e10-0x0040a0a5.LibJpegInverseDctManager.md) maps `jddctmgr.c`.
  - [UID:00045S][0x0040a0d0-0x0040a436.LibJpegDecompressPostController](by-memory/0x0040a0d0-0x0040a436.LibJpegDecompressPostController.md) maps `jdpostct.c`.
  - [UID:00045T][0x0040a440-0x0040abb2.LibJpegUpsampler](by-memory/0x0040a440-0x0040abb2.LibJpegUpsampler.md) maps `jdsample.c`.
  - [UID:00045U][0x0040abc0-0x0040b221.LibJpegColorDeconverter](by-memory/0x0040abc0-0x0040b221.LibJpegColorDeconverter.md) maps `jdcolor.c`.
  - [UID:00045V][0x0040b230-0x0040b820.LibJpegMergedUpsampler](by-memory/0x0040b230-0x0040b820.LibJpegMergedUpsampler.md) maps `jdmerge.c`.
  - [UID:00045W][0x0040b820-0x0040cc1f.LibJpegOnePassColorQuantizer](by-memory/0x0040b820-0x0040cc1f.LibJpegOnePassColorQuantizer.md) maps `jquant1.c`.
  - [UID:00045X][0x0040cc20-0x0040d864.LibJpegTwoPassColorQuantizer](by-memory/0x0040cc20-0x0040d864.LibJpegTwoPassColorQuantizer.md) maps `jquant2.c`.
  - [UID:00045Y][0x0040d870-0x0040d9f9.LibJpegCompressMainController](by-memory/0x0040d870-0x0040d9f9.LibJpegCompressMainController.md) maps `jcmainct.c`.
  - [UID:00045Z][0x0040da00-0x0040e6ab.LibJpegCompressCoefficientController](by-memory/0x0040da00-0x0040e6ab.LibJpegCompressCoefficientController.md) maps `jccoefct.c`.
  - [UID:000460][0x0040e6b0-0x0040f007.LibJpegHuffmanEncoder](by-memory/0x0040e6b0-0x0040f007.LibJpegHuffmanEncoder.md) maps `jchuff.c`.
  - [UID:000461][0x0040f010-0x0040fc15.LibJpegProgressiveHuffmanEncoder](by-memory/0x0040f010-0x0040fc15.LibJpegProgressiveHuffmanEncoder.md) maps `jcphuff.c`.
  - [UID:000462][0x0040fc20-0x004101e9.LibJpegForwardDctManager](by-memory/0x0040fc20-0x004101e9.LibJpegForwardDctManager.md) maps `jcdctmgr.c`.
  - [UID:000463][0x004101f0-0x004107a4.LibJpegCompressPrepController](by-memory/0x004101f0-0x004107a4.LibJpegCompressPrepController.md) maps `jcprepct.c`.
  - [UID:000464][0x004107b0-0x004111cf.LibJpegDownsampler](by-memory/0x004107b0-0x004111cf.LibJpegDownsampler.md) maps `jcsample.c`.
  - [UID:000465][0x004111d0-0x00411951.LibJpegColorConverter](by-memory/0x004111d0-0x00411951.LibJpegColorConverter.md) maps `jccolor.c`.
  - [UID:000466][0x00411960-0x004124b8.LibJpegCompressMasterController](by-memory/0x00411960-0x004124b8.LibJpegCompressMasterController.md) maps `jcmaster.c`.
  - [UID:000467][0x004124c0-0x00412aaf.LibJpegIntegerInverseDct](by-memory/0x004124c0-0x00412aaf.LibJpegIntegerInverseDct.md) maps `jidctint.c`.
  - [UID:000468][0x00412ab0-0x00412f62.LibJpegFastIntegerInverseDct](by-memory/0x00412ab0-0x00412f62.LibJpegFastIntegerInverseDct.md) maps `jidctfst.c`.
  - [UID:000469][0x00412f70-0x004133a4.LibJpegFloatInverseDct](by-memory/0x00412f70-0x004133a4.LibJpegFloatInverseDct.md) maps `jidctflt.c`.
  - [UID:00046A][0x004133b0-0x004139ce.LibJpegReducedInverseDct](by-memory/0x004133b0-0x004139ce.LibJpegReducedInverseDct.md) maps `jidctred.c`.
  - [UID:00046B][0x004139d0-0x00413dc8.LibJpegIntegerForwardDct](by-memory/0x004139d0-0x00413dc8.LibJpegIntegerForwardDct.md) maps `jfdctint.c`.
  - [UID:00046C][0x00413dd0-0x00414011.LibJpegFastIntegerForwardDct](by-memory/0x00413dd0-0x00414011.LibJpegFastIntegerForwardDct.md) maps `jfdctfst.c`.
  - [UID:00046D][0x00414020-0x00414283.LibJpegFloatForwardDct](by-memory/0x00414020-0x00414283.LibJpegFloatForwardDct.md) maps `jfdctflt.c`.
- [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md) identify two product-owned libjpeg decode callers: `DecodeJpfImageToTileContext` at `0x004d07b0` for profile/look `JPF` portraits and `DecodeJpegBufferToTileContext` at `0x004d0a90` for minimap tile blobs.
- [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md) identifies a product-owned compression wrapper used by a raw/retained `.jpg` screenshot path at `0x00557840-0x00557a95`.
- Complete IDA/PE/source inspection finds the 124-entry JPEG message pointer table over `[0x00631660,0x00631850)`. Its indices are `0..123`; all pointers are non-null, unique, and source ordered, and all pointed diagnostics match the 124 expanded IJG 6b `jerror.h` messages byte-for-byte. The adjacent [UID:00028D][0x006707d4-0x00671a74.LibJpeg6bDataMessagesAndMemoryStrings](by-memory/0x006707d4-0x00671a74.LibJpeg6bDataMessagesAndMemoryStrings.md) island also contains `jerror.c` `%s\n` and `jmemmgr.c` `JPEGMEM`/`%ld%c`, each with exactly one expected consumer xref.
- Historical correction: the former 121-entry/`0x00631840` statement omitted the final three four-byte slots. The initializer value `last_jpeg_message = 123` is the final valid index, not the message count.
- IDA rejects the previous provisional `0x00469640-0x00470dc9` neighborhood for LibJPEG: `0x00469640` and `0x00470a00` decompile as BrowserWindow/WebBrowser COM code.
- `0x00414290-0x004142b5` is excluded as Miles `_AIL_shutdown@0` thunk/atexit glue, and [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md) starts at `0x004142c0`.

Source-structure decision:

- Add a `third_party/libjpeg/` reconstruction target.
- Keep product-facing JPEG load/use wrappers with render/image modules, but keep IJG internals under the third-party folder. Current wrapper owners are [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) for decode and [UID:0000K4][ImageWriters](by-file/ImageWriters.md) for output.
- Do not assign IJG allocator, marker, Huffman, color conversion, or error-manager helpers to NexusTK feature files just because image libraries call them.
- Current source-file anchors include the public API, marker, memory, controller, entropy, coefficient, sample, color, quantizer, DCT, and IDCT files listed above: `jerror.c`, `jdapimin.c`, `jdapistd.c`, `jdmarker.c`, `jcapimin.c`, `jcapistd.c`, `jcparam.c`, `jdatadst.c`, `jcomapi.c`, `jdinput.c`, `jmemmgr.c`, `jdmaster.c`, `jutils.c`, `jcmarker.c`, `jcinit.c`, `jmemnobs.c`, `jdcoefct.c`, `jdmainct.c`, `jdhuff.c`, `jdphuff.c`, `jddctmgr.c`, `jdpostct.c`, `jdsample.c`, `jdcolor.c`, `jdmerge.c`, `jquant1.c`, `jquant2.c`, `jcmainct.c`, `jccoefct.c`, `jchuff.c`, `jcphuff.c`, `jcdctmgr.c`, `jcprepct.c`, `jcsample.c`, `jccolor.c`, `jcmaster.c`, `jidctint.c`, `jidctfst.c`, `jidctflt.c`, `jidctred.c`, `jfdctint.c`, `jfdctfst.c`, and `jfdctflt.c`. Stock `jdatasrc.c` is not yet proven in the active product decode path because NexusTK uses a local in-memory source helper at `0x004e7030`, which writes `0x00401b00` as the IJG `jpeg_resync_to_restart` callback pointer into its source-manager record. Source-bearing statically embedded children should be exact source-file pages using validator inline import directives with blank multiline bodies; mixed [UID:0000VS][0x00403920-0x004048e2.LibJpegCompressApiFrontEnd](by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md) stays blank/no-code until dedicated `jcapimin.c`, `jdatadst.c`, `jcparam.c`, and full cross-page `jcapistd.c` slices exist.

Rebuild/procurement decision:

- Use the official IJG source archive `jpegsrc.v6b.tar.gz`.
- Use [UID:0000VP][0x00401000-0x00414283.LibJpeg6bCore](by-memory/0x00401000-0x00414283.LibJpeg6bCore.md) as the non-emitting split/index and compile the staged stock source files instead of replacing them with generated helper files. Local compile options or trimmed encoder/decoder subsets may still affect byte-for-byte comparison.
- Use `jmemnobs.c` as `SYSDEPMEM` for the first reconstruction attempt; `jpeg-6b/makefile.vc` recommends `jmemnobs.obj` for Windows NT/95 style builds.

External source references:

- <https://ijg.org/files/>

## JsonCpp

The executable contains statically linked JsonCpp code used by JSON-facing features such as cash-shop/item-shop metadata.

Evidence:

- IDA strings include JsonCpp parser/settings names such as `collectComments`, `allowComments`, `strictRoot`, `allowDroppedNullPlaceholders`, `allowNumericKeys`, `allowSingleQuotes`, `stackLimit`, `failIfExtra`, `rejectDupKeys`, `allowSpecialFloats`, and many `Json::Value` diagnostics.
- IDA RTTI-ish strings include `.?AVCharReaderBuilder@Json@@`, `.?AVStreamWriterBuilder@Json@@`, `.?AVOurCharReader@Json@@`, and `.?AUBuiltStyledStreamWriter@Json@@`, which points to a JsonCpp API family with builder-based reader/writer classes.
- IDA xrefs to parser diagnostics show two reader-family implementations documented as [UID:0000X2][0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland](by-memory/0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland.md) and [UID:0000X8][0x00432e10-0x004345ee.JsonCppSecondParserIsland](by-memory/0x00432e10-0x004345ee.JsonCppSecondParserIsland.md); [UID:0000X7][0x00431d50-0x00431f1c.JsonCppOurReaderParse](by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md) carries the fail-if-extra version discriminator, [UID:0001ZR][0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers](by-memory/0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers.md) fills the second `OurReader` error/token helper gap, and [UID:0000X9][0x004345f0-0x00434887.JsonCppNumberTokenParseHelper](by-memory/0x004345f0-0x00434887.JsonCppNumberTokenParseHelper.md) immediately follows the second parser island and carries the `Unable to parse token length` discriminator. [UID:0001ZS][0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter](by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md) is now a non-emitting split index: reader child [UID:00048B][0x00434890-0x004353c0.JsonCppOurReaderUnicodeCommentHelpers](by-memory/0x00434890-0x004353c0.JsonCppOurReaderUnicodeCommentHelpers.md) covers the following unicode/comment helper slice and writer child [UID:00048C][0x004353c0-0x004361ae.JsonCppBuiltStyledStreamWriterHelpers](by-memory/0x004353c0-0x004361ae.JsonCppBuiltStyledStreamWriterHelpers.md) covers the `BuiltStyledStreamWriter` helper slice through raw `hasCommentForValue`; builder/settings strings are referenced from helpers including `0x0042d380`, `0x0042db90`, `0x0042def0`, [UID:0000XC][0x004417e0-0x00441d24.JsonCppValidReaderKeys](by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md), [UID:0000XD][0x00441d30-0x00442084.JsonCppValidWriterKeys](by-memory/0x00441d30-0x00442084.JsonCppValidWriterKeys.md), and [UID:0000X3][0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland](by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md).
- 2026-06-24 B005 current MCP session `80de0a67` upgrades [UID:0000X7][0x00431d50-0x00431f1c.JsonCppOurReaderParse](by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md) from a generic fail-if-extra lead to a source-matched import-directive method. MCP reports `sub_431D50` size `0x1cc`, exclusive end `0x00431f1c`, predecessor padding `0x00431d4d-0x00431d50`, successor padding `0x00431f1c-0x00431f20`, the sole direct caller `0x0044270c` inside `OurCharReader::parse` at `0x004426e0`, and the `OurCharReader` vtable cells at `0x0060e754` (`0x0043b430`, `0x004426e0`) with builder xref `0x0042d5b4`. The target calls `0x00432f10` for `OurReader::readValue()` and `0x00435040` for comment-token skipping in [UID:00048B][0x00434890-0x004353c0.JsonCppOurReaderUnicodeCommentHelpers](by-memory/0x00434890-0x004353c0.JsonCppOurReaderUnicodeCommentHelpers.md), checks trailing-token types `tokenError=16` and `tokenEndOfStream=0`, and enforces strict-root array/object values `6/7`. This preserves the pre-`126bdc2` reader-source discriminator while [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md) keeps the `b299d3581f4dc670734f1fe1a34fce1282337802` `nullSingleton()` anchor. The formal reconstruction route is a JsonCpp validator inline import directive to staged `src/lib_json/json_reader.cpp`; do not create a NexusTK handwritten parser helper or reassign this code to product JSON consumers.
- [UID:0000X1][0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers](by-memory/0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers.md) maps the raw/unmodeled span before the first reader/builder island to legacy `Json::Reader` comment, string, and number scanner helpers.
- [UID:0000X4][0x0042f3f0-0x00430040.JsonCppLegacyWriterCore](by-memory/0x0042f3f0-0x00430040.JsonCppLegacyWriterCore.md) maps the retained `Writer`/`FastWriter`/`StyledWriter` implementation family, [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md) maps the following source-bearing `Json::StyledWriter::pushValue(JSONCPP_STRING const&)` helper, and [UID:0000X6][0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude](by-memory/0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude.md) is now a non-emitting split index. UID0000X5 now uses the same formal validator inline import route as UID0000X4 and [UID:00037Z][0x00430092-0x00431c00.JsonCppWriterTailAndScalarHelpers](by-memory/0x00430092-0x00431c00.JsonCppWriterTailAndScalarHelpers.md): staged `third_party_embeds/jsoncpp/src/lib_json/json_writer.cpp`, `json_tool.h`, and public JsonCpp headers, with a blank multiline block. B012 current MCP session `b5326241-58b0-4365-95aa-2284b04eb3cb` confirmed UID0000X5 as one `0x52`-byte function at `0x00430040-0x00430092`, false internal starts at `0x00430041`/`0x00430058`, no function at `0x00430092`, five `sub_42F870` callsites, callees `0x0041d3b0`, `0x00437470`, and `0x0043f3f0`, and staged `json_writer.cpp` line 539 as the source identity; it remains third-party JsonCpp and not NexusTK product source. The source-bearing writer child [UID:00037Z][0x00430092-0x00431c00.JsonCppWriterTailAndScalarHelpers](by-memory/0x00430092-0x00431c00.JsonCppWriterTailAndScalarHelpers.md) covers the remaining `json_writer.cpp` writer/scalar/string/table/stream-insertion bytes through the exact `0x00431c00` boundary, and the reader child [UID:000380][0x00431c00-0x00431d50.JsonCppOurReaderPrelude](by-memory/0x00431c00-0x00431d50.JsonCppOurReaderPrelude.md) covers `json_reader.cpp` `OurFeatures::all()` and `OurReader::OurReader` before [UID:0000X7][0x00431d50-0x00431f1c.JsonCppOurReaderParse](by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md). These JsonCpp writer children emit through validator inline import directives; the source snapshot and `third_party/jsoncpp/` path are unchanged.
- [UID:0000WZ][0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport](by-memory/0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport.md) is now a reviewed non-emitting split index between the value core and document parse front ends. The B002/supervisor source pass found additional raw JsonCpp starts and reclassified the apparent CRT `__crt_strtox::big_integer` pair as folded `Json::Value::CommentInfo` ctor/dtor aliases based on local JsonCpp xrefs.
- [UID:0003WI][0x00428b50-0x00428c53.JsonCppCommentInfoSetCommentAndFoldedCtorDtor](by-memory/0x00428b50-0x00428c53.JsonCppCommentInfoSetCommentAndFoldedCtorDtor.md), [UID:0003WJ][0x00428c60-0x00429473.JsonCppPathArgumentAndPath](by-memory/0x00428c60-0x00429473.JsonCppPathArgumentAndPath.md), and [UID:0003WK][0x00429480-0x004298e6.JsonCppValueIteratorSupport](by-memory/0x00429480-0x004298e6.JsonCppValueIteratorSupport.md) are the source-bearing children for `json_value.cpp` `CommentInfo`/`PathArgument`/`Path` and `json_valueiterator.inl` iterator support.
- The fitting-room item-shop cache loader uses JsonCpp as a consumer dependency: [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md) calls [UID:0000X0][0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds](by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md) at `0x004298f0` and `0x00429b30`, then reads `version` and category arrays through [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md).
- Existing file docs show JSON-facing product behavior, including [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md) downloading `https://secure.kru.com/itemshop/data/itemshop.json`.
- No explicit JsonCpp version string has been found yet in the binary. Searches for `0.10.6`, `1.7.2`, `JSONCPP_VERSION_STRING`, `JsonCpp`, and `jsoncpp` did not produce executable-string evidence.
- [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md) contains official candidate archives for JsonCpp `0.10.6`, `1.7.0-1.7.7`, and upstream commit `b299d3581f4dc670734f1fe1a34fce1282337802`. `0.10.6` lacks the observed `Unable to parse token length` string and contains the unfound `reader error` string. Release tags `1.7.0-1.7.4` do not fully match the observed static-object `Value::nullSingleton()` implementation, while `1.7.5+` has later reader changes not present in the binary. Current evidence favors the official `b299d358` snapshot between `1.7.4` and `1.7.5`.
- Current static embed state on 2026-05-25: `source-3/third_party_embeds/jsoncpp`, `source-3/simroot_v2/third_party/jsoncpp`, and `obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802` contain the same 16 source/header files hash-for-hash.
- Current JsonCpp source-bearing by-memory pages that can be represented by staged `.cpp`/`.h` paths use validator inline `RECONSTRUCTION_CPP CODE` import directives with blank multiline blocks. Legacy `// Static embed:` wording is superseded for those pages; `.inl`-dependent `json_value.cpp` pages remain blocked or split until validator support exists.
- The reviewed read-only-data family is now bounded exactly as predecessor [UID:00024N][0x0060e174-0x0060e2ac.MsvcStlLocaleIostreamRdata](by-memory/0x0060e174-0x0060e2ac.MsvcStlLocaleIostreamRdata.md), static-data index [UID:00024O][0x0060e2ac-0x0060f034.JsonCppReadOnlyData](by-memory/0x0060e2ac-0x0060f034.JsonCppReadOnlyData.md), and successor [UID:00024P][0x0060f034-0x0060f200.MsvcStlNumericRdata](by-memory/0x0060f034-0x0060f200.MsvcStlNumericRdata.md). UID00024O has 341 unique physical item heads, 142 named heads, 80 exact strings, 268 indexed-name xrefs, and zero code items. It is a false/non-emitting index: source-bearing JsonCpp children regenerate authored semantics, while compatible MSVC STL regenerates compiler data.
- The exact nested runtime children are [UID:0003AN][0x0060e48c-0x0060e528.JsonCppMsvcIstreamRuntimeVtables](by-memory/0x0060e48c-0x0060e528.JsonCppMsvcIstreamRuntimeVtables.md), containing the `basic_istringstream<char>` vftable and `{0,0x60}` virtual-base table, and [UID:0003AO][0x0060e810-0x0060e824.JsonCppMsvcOstreamRuntimeVtables](by-memory/0x0060e810-0x0060e824.JsonCppMsvcOstreamRuntimeVtables.md), containing the `basic_ostringstream<char>` vftable and `{0,0x50}` virtual-base table. These pages remain no-owner, false, and non-emitting; copying their bytes into JsonCpp source would misclassify compiler/runtime artifacts.

Active staged source closure for the reviewed binary semantics:

| Active staged source | SHA256 |
| --- | --- |
| `third_party_embeds/jsoncpp/src/lib_json/json_reader.cpp` | `89074ED5550883E9EA7D300ED24292BB3238A18F76103C1219ADB4D08F8899D2` |
| `third_party_embeds/jsoncpp/src/lib_json/json_value.cpp` | `F2C47295CC3FD59AA2D725074958E8F7A21EACB7E0A9889AB2B1B7DB7D11980E` |
| `third_party_embeds/jsoncpp/src/lib_json/json_writer.cpp` | `C197234A6B01D18355990168A0096BAF25AD3AF2381A38B39AAB62C97A41E609` |
| `third_party_embeds/jsoncpp/src/lib_json/json_tool.h` | `771D37DA2CCE1BE90BB62A1C35C65FA05149ABA386BEBD36FF6359D7A74F6F88` |
| `third_party_embeds/jsoncpp/src/lib_json/json_valueiterator.inl` | `0ECA25ECA79C61C64ABFFC93DA36644ED1553DAD0639397F8A20D998E9106D46` |
| `third_party_embeds/jsoncpp/include/json/assertions.h` | `2F2646718286632A45A45540AAC0F8240D3713945690530AC253C34D98C90151` |
| `third_party_embeds/jsoncpp/include/json/config.h` | `4A1B4EBF8DCE646091A42C9CCEE12476024FE8B69045972BA05AAC33F054CE7D` |
| `third_party_embeds/jsoncpp/include/json/version.h` | `3D995A29400D0EF889026D279EBA66CA8172086709E4842F86D12F84A3717F1F` |
| `third_party_embeds/jsoncpp/include/json/reader.h` | `4A707D6B3C9D0CA16A57BA20AE114C28E184F588C083D870765B9FBC4C9D1DC3` |
| `third_party_embeds/jsoncpp/include/json/features.h` | `29468BE6ED917D8889493E93A0142430AA560170D41DE56182D35F37B1D355C7` |
| `third_party_embeds/jsoncpp/include/json/forwards.h` | `46FA7154AB8E1FDF3C79B8D00751BF022F4F377B7F1A6BABE2B8076464F140C6` |
| `third_party_embeds/jsoncpp/include/json/value.h` | `361960D4C8401FF995D3CA6F2DCAF912FBD1401D46413C04AAF2ABB2F0585274` |
| `third_party_embeds/jsoncpp/include/json/writer.h` | `689FDD001A939D262457629FF69E12454DE4215483690441C9B2358179FF1369` |

This 13-file active closure is narrower than the 16-file staged tree: `allocator.h` is inactive under `JSONCPP_USING_SECURE_MEMORY=0`, `autolink.h` is build-link convenience, and umbrella `json.h` adds no target semantics beyond the listed recursive headers. The closure identifies official commit `b299d3581f4dc670734f1fe1a34fce1282337802` as the best source snapshot after 1.7.4 and before 1.7.5, not as an exact release tag merely because `version.h` still says `1.7.4`. No standalone `JsonCppReadOnlyData.cpp` or direct index import is justified.

Source-structure decision:

- Use the staged `third_party/jsoncpp/` reconstruction target at the best-supported commit snapshot; keep the release-tag distinction explicit unless stronger evidence appears.
- Keep JsonCpp internals separate from cash-shop/fitting-room/download code. Product modules should own request flow, URLs, and catalog interpretation; JsonCpp owns parse/serialize support.
- Current `simroot_v2` now materializes JsonCpp under `third_party/jsoncpp`; treat that tree as a static third-party source embed while keeping exact binary address-to-source function names under review.

Rebuild/procurement decision:

- Use the official JsonCpp repository and compare the staged `b299d3581f4dc670734f1fe1a34fce1282337802` snapshot against the observed `CharReaderBuilder`/`StreamWriterBuilder`/`OurCharReader`/`BuiltStyledStreamWriter`/`FastWriter`/`StyledWriter` strings and writer-builder object/control flow.
- Prefer the upstream multi-file layout from the staged commit archive (`include/json/*.h` plus `src/lib_json/json_reader.cpp`, `json_value.cpp`, `json_writer.cpp`, `json_tool.h`, and `json_valueiterator.inl`). The extracted best candidate does not contain a generated `dist/jsoncpp.cpp` amalgamation directory.
- Use `source-3/third_party_embeds/jsoncpp` as the working read-only source embed. The generated mirror under `source-3/simroot_v2/third_party/jsoncpp` should not be edited by hand.

External source references:

- <https://github.com/open-source-parsers/jsoncpp>

## OLE / COM / WebBrowser

The client initializes OLE at process startup and uses COM heavily for the embedded Internet Explorer WebBrowser feature.

Evidence:

- [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md) at `0x00419ee0` calls `OleInitialize(0)` and registers the `0x0060c0f0` shutdown thunk with `atexit`.
- [UID:0000HN][AutoInit](by-file/AutoInit.md) documents the paired OLE shutdown behavior, including the ordinary destructor at `0x0046efe0`, scalar deleting destructor at `0x00470300`, one-slot [UID:0001X0][AutoInitVtable](by-type/by-vtable/AutoInitVtable.md) at `0x0061373c`, and static shutdown thunk at `0x0060c0f0`.
- [UID:0000HV][Browser](by-file/Browser.md) owns the WebBrowser/ActiveX host classes, COM event sink, connection-point helpers, and browser notification path.

Source-structure decision:

- Keep OLE startup/shutdown in a platform/OLE support file such as `AutoInit.cpp`, `OleSupport.cpp`, or `PlatformApi.cpp` unless original-source evidence proves browser placement.
- Keep browser-specific COM helpers such as `AdviseConnectionPoint`, `UnadviseConnectionPoint`, and `BrowserVariantFromString` with [UID:0000HV][Browser](by-file/Browser.md).
- Do not use browser COM usage alone to classify [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md) as browser-owned runtime code.

## libcurl

The pre-game update notice uses libcurl to fetch version and minimap metadata before entering the normal game startup flow.

Evidence:

- [UID:0000O5][StartupWindow](by-file/StartupWindow.md) calls `curl_global_init`, `curl_version_info`, `curl_easy_init`, `curl_easy_setopt`, `curl_easy_perform`, and `curl_easy_cleanup` from `StartupWindow::RunUpdateCheck` at `0x00580870`.
- The update metadata URL is `https://s3.amazonaws.com/kru-downloads/tk/update/nexustk.ver`.
- The minimap hash-list URL is `https://s3.amazonaws.com/kru-downloads/tk/minimaps/HashList.txt`.
- The [UID:0001IP][0x00581b80-0x00581ce6.CurlWriteCallback](by-memory/0x00581b80-0x00581ce6.CurlWriteCallback.md) appends text response data into an SSO-like ANSI string buffer at `0x00581b80`.
- IDA imports `curl_easy_setopt`, `curl_easy_init`, `curl_version_info`, `curl_easy_perform`, `curl_easy_cleanup`, and `curl_global_init` from dynamic import module `libcurl`.
- Local shipped file: `C:\Users\admin\Desktop\Clone\NexusTK\libcurl.dll`.
- Version info: `FileVersion=7.48.0`, `ProductName=The cURL library`, `FileDescription=libcurl Shared Library`.
- Hash: SHA256 `00C75BAB56F50D9DC8EAAA37A2C9C4B9A40B41236FB59E8BAD143EDBC7E1B7B1`.
- Binary strings in the shipped DLL include `libcurl/7.48.0`, `WinSSL`, Schannel diagnostics, and `Microsoft Unified Security Protocol Provider`, which indicates a Windows Schannel/WinSSL build rather than an OpenSSL DLL bundle.
- 2026-05-26 IDA MCP recheck reconfirmed the project-owned write callback at `0x00581b80` is referenced only by two `StartupWindow::RunUpdateCheck` callback setup sites, while libcurl itself remains a dynamic DLL dependency.

Source-structure decision:

- Keep `0x00581b80` with [UID:0000O5][StartupWindow](by-file/StartupWindow.md) as project-owned callback glue. Do not place it under a libcurl source module.
- The callback body measures the incoming chunk with `strlen`, so document it as a text metadata sink for the observed URLs rather than a binary-safe generic curl callback.

Rebuild/procurement decision:

- Use curl 7.48.0 from the official curl archive or a matching Windows Schannel build.
- Keep libcurl as a runtime DLL dependency. Current evidence does not require separate OpenSSL DLL procurement.
- Product-owned code remains in [UID:0000O5][StartupWindow](by-file/StartupWindow.md), [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md), and the curl callback memory doc.

## AhnLab V3 Scanner DLLs

The retained [UID:0000P5][VirusChecker](by-file/VirusChecker.md) module dynamically loads AhnLab V3 scanner/control DLLs and uses them to scan process/module image paths.

Evidence:

- `0x005c05a0` calls `LoadLibraryA("V3PRO32E.DLL")`, resolves `AhnExCheckFile` and `AhnExGetVirusName`, then calls `LoadLibraryA("V3PCTRL.DLL")`.
- The same load helper resolves `V3PCtrl_EnumProcesses` and `V3PCtrl_EnumModules`.
- `0x005c07b0` calls the process enumerator, collects module paths through the module callback, scans each collected path with `AhnExCheckFile`, formats a virus-name message on detection, and follows an application close/termination path.
- The observed local shipped folder contains `binkw32.dll`, `Mss32.dll`, `Mp3dec.asi`, and `libcurl.dll`, but does not contain `V3PRO32E.DLL` or `V3PCTRL.DLL`.
- B004's 2026-06-29 current MCP session `86fb854e` cleanup keeps this as optional retained scanner integration: the V3 handles/function pointers are zero-filled module-static globals owned by [UID:0000P5][VirusChecker](by-file/VirusChecker.md), no normal constructor/load/scan activation route or external `g_pVirusChecker` consumer was found, and the wrapper source remains project-owned rather than AhnLab-owned.

Rebuild/procurement decision:

- Treat this as optional runtime security integration, not a guaranteed bundled dependency.
- If the original client installer shipped these DLLs separately, keep them as original redistribution artifacts. If not, keep [UID:0000P5][VirusChecker](by-file/VirusChecker.md) dynamically loaded and fail closed or disabled when the DLLs are absent.
- Do not source these DLLs from unofficial DLL-download sites. The exact version remains unknown.

Open questions:

- Find a live caller for the scanner constructor/load/scan sequence; current IDA xrefs do not prove the scanner is activated.
- Identify bundled or expected AhnLab DLL versions if the original client distribution includes them.

## Cross-References

- [UID:0001Z6][0x0060d000-0x0060d670.ImportDataSection](by-memory/0x0060d000-0x0060d670.ImportDataSection.md)
- [UID:0000P4][VideoPlayerPane](by-file/VideoPlayerPane.md)
- [UID:0000O4][StartupLogoPanes](by-file/StartupLogoPanes.md)
- [UID:0001RN][startup-logo-media](by-resource/startup-logo-media.md)
- [UID:0000O5][StartupWindow](by-file/StartupWindow.md)
- [UID:0001RO][startup-update-notice-resources](by-resource/startup-update-notice-resources.md)
- [UID:0000PC][Zlib](by-file/Zlib.md)
- [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md)
- [UID:0000W2][0x004142c0-0x00414565.ZlibPublicCompressChecksum](by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md)
- [UID:0000W4][0x00414820-0x004158aa.ZlibDeflateWorkers](by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md)
- [UID:0000W5][0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler](by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md)
- [UID:0003OJ][0x0063211c-0x00632560.Zlib114CrcAndDeflateString](by-memory/0x0063211c-0x00632560.Zlib114CrcAndDeflateString.md)
- [UID:0004IK][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md)
- [UID:0000W6][0x00417ba0-0x00419e56.ZlibInflateInternals](by-memory/0x00417ba0-0x00419e56.ZlibInflateInternals.md)
- [UID:0000KW][LodePNG](by-file/LodePNG.md)
- [UID:0000XE][0x00443a60-0x00450c9f.LodePngHelperIslandInventory](by-memory/0x00443a60-0x00450c9f.LodePngHelperIslandInventory.md)
- [UID:0000XF][0x00443c80-0x00443e5d.LodePngEncodeFrontEnd](by-memory/0x00443c80-0x00443e5d.LodePngEncodeFrontEnd.md)
- [UID:0000XG][0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers](by-memory/0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers.md)
- [UID:0000XH][0x004460f0-0x004461f6.LodePngStateInit](by-memory/0x004460f0-0x004461f6.LodePngStateInit.md)
- [UID:00057C][0x0060f200-0x0060f4c0.LodePngConstantTables](by-memory/0x0060f200-0x0060f4c0.LodePngConstantTables.md)
- [UID:00057D][0x0064170c-0x006417a0.LodePngStateRttiDescriptors](by-memory/0x0064170c-0x006417a0.LodePngStateRttiDescriptors.md)
- [UID:00057E][0x00674240-0x00674278.LodePngStateTypeDescriptors](by-memory/0x00674240-0x00674278.LodePngStateTypeDescriptors.md)
- [UID:0000KN][LibJPEG](by-file/LibJPEG.md)
- [UID:0000VP][0x00401000-0x00414283.LibJpeg6bCore](by-memory/0x00401000-0x00414283.LibJpeg6bCore.md)
- [UID:0000VQ][0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd](by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md)
- [UID:0000VR][0x00401b00-0x0040391f.LibJpegMarkerReader](by-memory/0x00401b00-0x0040391f.LibJpegMarkerReader.md)
- [UID:0000VS][0x00403920-0x004048e2.LibJpegCompressApiFrontEnd](by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md)
- [UID:0000VT][0x004048f0-0x004049bb.LibJpegCompressRawDataApi](by-memory/0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md)
- [UID:0000VU][0x004049c0-0x00404a5c.LibJpegCommonApi](by-memory/0x004049c0-0x00404a5c.LibJpegCommonApi.md)
- [UID:0000VV][0x00404a60-0x0040505b.LibJpegInputController](by-memory/0x00404a60-0x0040505b.LibJpegInputController.md)
- [UID:0000VW][0x00405060-0x00405c77.LibJpegMemoryManager](by-memory/0x00405060-0x00405c77.LibJpegMemoryManager.md)
- [UID:0000VX][0x00405c80-0x004063c8.LibJpegDecompressMaster](by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md)
- [UID:0000VY][0x004063d0-0x0040649b.LibJpegUtilityHelpers](by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md)
- [UID:000489][0x00631850-0x0063211c.LibJpeg6bReadOnlyTables](by-memory/0x00631850-0x0063211c.LibJpeg6bReadOnlyTables.md)
- [UID:0000VZ][0x004064a0-0x00406d90.LibJpegMarkerWriter](by-memory/0x004064a0-0x00406d90.LibJpegMarkerWriter.md)
- [UID:0000W0][0x00406d90-0x00406e46.LibJpegCompressMasterInit](by-memory/0x00406d90-0x00406e46.LibJpegCompressMasterInit.md)
- [UID:0000W1][0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend](by-memory/0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend.md)
- [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md)
- [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md)
- [UID:0000KI][JsonCpp](by-file/JsonCpp.md)
- [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md)
- [UID:0000X0][0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds](by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md)
- [UID:0003WI][0x00428b50-0x00428c53.JsonCppCommentInfoSetCommentAndFoldedCtorDtor](by-memory/0x00428b50-0x00428c53.JsonCppCommentInfoSetCommentAndFoldedCtorDtor.md)
- [UID:0003WJ][0x00428c60-0x00429473.JsonCppPathArgumentAndPath](by-memory/0x00428c60-0x00429473.JsonCppPathArgumentAndPath.md)
- [UID:0003WK][0x00429480-0x004298e6.JsonCppValueIteratorSupport](by-memory/0x00429480-0x004298e6.JsonCppValueIteratorSupport.md)
- [UID:0000X1][0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers](by-memory/0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers.md)
- [UID:0000X7][0x00431d50-0x00431f1c.JsonCppOurReaderParse](by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md)
- [UID:0001ZR][0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers](by-memory/0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers.md)
- [UID:0000X2][0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland](by-memory/0x0042ae90-0x0042e850.JsonCppReaderAndBuilderPreludeIsland.md)
- [UID:0000X8][0x00432e10-0x004345ee.JsonCppSecondParserIsland](by-memory/0x00432e10-0x004345ee.JsonCppSecondParserIsland.md)
- [UID:0000X9][0x004345f0-0x00434887.JsonCppNumberTokenParseHelper](by-memory/0x004345f0-0x00434887.JsonCppNumberTokenParseHelper.md)
- [UID:0001ZS][0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter](by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md)
- [UID:00048B][0x00434890-0x004353c0.JsonCppOurReaderUnicodeCommentHelpers](by-memory/0x00434890-0x004353c0.JsonCppOurReaderUnicodeCommentHelpers.md)
- [UID:00048C][0x004353c0-0x004361ae.JsonCppBuiltStyledStreamWriterHelpers](by-memory/0x004353c0-0x004361ae.JsonCppBuiltStyledStreamWriterHelpers.md)
- [UID:0001ZT][0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport](by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md)
- [UID:0000X3][0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland](by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md)
- [UID:0000X4][0x0042f3f0-0x00430040.JsonCppLegacyWriterCore](by-memory/0x0042f3f0-0x00430040.JsonCppLegacyWriterCore.md)
- [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md)
- [UID:0000X6][0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude](by-memory/0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude.md)
- [UID:00037Z][0x00430092-0x00431c00.JsonCppWriterTailAndScalarHelpers](by-memory/0x00430092-0x00431c00.JsonCppWriterTailAndScalarHelpers.md)
- [UID:000380][0x00431c00-0x00431d50.JsonCppOurReaderPrelude](by-memory/0x00431c00-0x00431d50.JsonCppOurReaderPrelude.md)
- [UID:0000XC][0x004417e0-0x00441d24.JsonCppValidReaderKeys](by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md)
- [UID:0000XD][0x00441d30-0x00442084.JsonCppValidWriterKeys](by-memory/0x00441d30-0x00442084.JsonCppValidWriterKeys.md)
- [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md)
- [UID:0000K4][ImageWriters](by-file/ImageWriters.md)
- [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md)
- [UID:0000HN][AutoInit](by-file/AutoInit.md)
- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0000P5][VirusChecker](by-file/VirusChecker.md)
