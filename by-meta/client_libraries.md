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
| zlib | Statically embedded source | IDA strings identify `deflate 1.1.4` and `inflate 1.1.4`; core island `0x004142c0-0x00419e56` | Vendor zlib 1.1.4 from the official zlib fossils archive under `third_party/zlib/`. |
| LodePNG | Statically embedded source | IDA strings include `LodePNG`, `20160501`, `LodePNGEncoderSettings.filter_strategy`, and `LodePNGState` RTTI-ish names; helper island `0x00443a60-0x00450c9f`; public functions at `0x00443c80`, `0x00443db0`, and `0x00443e40` match upstream `20160501` `lodepng_encode_memory`, `lodepng_encode_file`, and `lodepng_encode32_file` | Vendor `lodepng.cpp`/`lodepng.h` from upstream commit `c6cf08b8910d91b0830666c07845116df1e9b6fc` matching version `20160501`. Treat the PNG file helpers as stock LodePNG APIs, not NexusTK-local `ImageWriters.cpp` code. |
| IJG libjpeg | Statically embedded source | IDA strings include `6b  27-Mar-1998`, `Copyright (C) 1998, Thomas G. Lane`, `Wrong JPEG library version`, and many IJG JPEG diagnostics; code island candidate `0x00401000-0x00414283`; source comparison maps decompression API, marker reader, common API, input controller, decompression master, compression API, marker writer, compress master init, `jutils.c`, `jmemmgr.c`, and `jmemnobs.c` anchors | Vendor IJG `jpegsrc.v6b` under `third_party/libjpeg/`; use `jmemnobs.c` for the first Windows rebuild attempt; keep NexusTK wrapper functions in image loader/writer modules. |
| JsonCpp | Statically embedded source | IDA strings/RTTI include `Json::Value`, `collectComments`, `allowDroppedNullPlaceholders`, `rejectDupKeys`, `allowSpecialFloats`, `CharReaderBuilder`, `StreamWriterBuilder`, `OurCharReader`, and `BuiltStyledStreamWriter`; no explicit executable version string found; `Unable to parse token length` is present and `reader error` is absent; `Value::nullSingleton()` and reader/value constructor checks currently favor official upstream commit `b299d3581f4dc670734f1fe1a34fce1282337802` over release tags | Use the staged official `jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802.candidate.zip` archive as the current best source snapshot. Preserve its upstream `include/json/` plus `src/lib_json/` layout for the first rebuild attempt. |
| AhnLab V3 scanner DLLs | Dynamic optional `LoadLibraryA` dependencies | IDA strings `V3PRO32E.DLL`, `V3PCTRL.DLL`, `AhnExCheckFile`, `AhnExGetVirusName`, `V3PCtrl_EnumProcesses`, `V3PCtrl_EnumModules`; DLLs are not present in the observed shipped folder | Treat as optional scanner integration. Obtain only from the original client/security package or official AhnLab distribution, or stub/disable gracefully for rebuilds. |
| Windows SDK/system APIs | OS/import-library dependencies | Imports include `DDRAW`, `WINMM`, `WSOCK32`, `VERSION`, `IMM32`, `WININET`, `KERNEL32`, `USER32`, `GDI32`, `ADVAPI32`, `SHELL32`, `ole32`, `OLEAUT32`, and `IPHLPAPI` | Link Windows SDK import libraries. Do not vendor or reconstruct these APIs. |
| MSVC CRT/STL/Dinkumware support | Statically linked compiler/runtime support | No `MSVCRT`/`MSVCP` import module is present; exception, RTTI, iostream/string, locale, allocator, map/set, numeric conversion, and template support are embedded in the EXE; [UID:0001ZT][0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport](by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md), [UID:0001ZV][0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport](by-memory/0x00439ee0-0x0043e0a3.MsvcStlIostreamNumericSupport.md), [UID:0001ZW][0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport](by-memory/0x0043e250-0x004417dd.MsvcStlJsonCppStringSupport.md), [UID:0001ZX][0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport](by-memory/0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport.md), [UID:00024B][0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport](by-memory/0x005c5c87-0x005cea43.MsvcRuntimeImportAndStlSupport.md), [UID:00024C][0x005cea6d-0x005f66f7.MsvcAcrtStdioLocaleMathSupport](by-memory/0x005cea6d-0x005f66f7.MsvcAcrtStdioLocaleMathSupport.md), and [UID:00024D][0x005f66f7-0x0060c0a0.MsvcSehFuncletIsland](by-memory/0x005f66f7-0x0060c0a0.MsvcSehFuncletIsland.md) are confirmed support islands | Rebuild requires a compatible MSVC-era toolchain/runtime model. Do not document static CRT helpers as NexusTK product files unless they contain project glue. |

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
- `VideoPlayerPane::OnIdle` calls `BinkWait`, `BinkService`, `BinkDoFrame`, `BinkCopyToBuffer`, and `BinkNextFrame`.
- `OpenBinkVideo` calls `BinkSetSoundSystem(BinkOpenDirectSound, SoundManager::GetDirectSound(...))`, closes any old handle, registers the `term` app notification, and calls `BinkOpen` with flags `67633152` / `0x04080000`.
- IDA caller evidence shows the first `BinkOpen` argument is a pointer into the `LogoPlayerPane` AUTOBUF payload. A public Bink flag reference identifies `0x04000000` as `BINKFROMMEMORY` and `0x00080000` as `BINKNOSKIP`, confirming memory-backed no-skip playback for the startup segments.
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

- Confirm whether `OpenBinkVideo` is best modeled as `LogoPlayerPane` or protected `VideoPlayerPane` logic.
- Explain why both `LogoPlayerPane` callers pass a segment size/remaining-size parameter to `0x005c0110` when the recovered helper body does not consume that argument.

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

- [UID:0000PC][Zlib](by-file/Zlib.md) owns the third-party support-family hypothesis for `0x004142c0-0x00419e56`.
- IDA strings identify `deflate 1.1.4` and `inflate 1.1.4` copyright/version text.
- [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md) records `Uncompress`, `Crc32`, `Adler32`, inflate blocks/codes/fast helpers, and deflate setup/reset helpers in one contiguous support-library island.
- [UID:0000W2][0x004142c0-0x00414565.ZlibPublicCompressChecksum](by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md) maps the public `compress2`, `compress`, `uncompress`, and `crc32` front end to `compress.c`, `uncompr.c`, and `crc32.c`.
- [UID:0000W4][0x00414820-0x00417b97.ZlibDeflateAndTrees](by-memory/0x00414820-0x00417b97.ZlibDeflateAndTrees.md) maps the previously anonymous deflate worker range and corrects `0x00416010-0x00417b97` as deflate `trees.c`-style bit/Huffman output code rather than inflate code.
- [UID:0000W5][0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler](by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md) maps the public inflate API to `inflate.c`, default callbacks to `zutil.c`, and Adler-32 to `adler32.c`.
- [UID:0000W6][0x00417ba0-0x00419e56.ZlibInflateInternals](by-memory/0x00417ba0-0x00419e56.ZlibInflateInternals.md) maps block, code, tree, flush, and fast-inflate internals to `infblock.c`, `infcodes.c`, `inftrees.c`, `infutil.c`, and `inffast.c`.
- [UID:000089][MetaTable](by-class/MetaTable.md) consumes `Uncompress` and `Crc32` in `DecompressAndValidateData`; the metadata subsystem does not own those helpers.
- DAT-backed image, palette, startup-logo, and resource paths also consume decompression output through the public zlib wrapper.

Source-structure decision:

- Keep zlib under `third_party/zlib/` or an equivalent support-library folder.
- Do not migrate `Crc32`, `Adler32`, `InflateFast`, or inflate/deflate internals into `DATArchive`, `MetaTable`, palette, startup-logo, or image-library modules.

Rebuild/procurement decision:

- Use the official zlib fossils archive for `zlib-1.1.4.tar.gz` or equivalent exact source package.
- Prefer preserving stock zlib source-file boundaries (`compress.c`, `uncompr.c`, `crc32.c`, `deflate.c`, `inflate.c`, `zutil.c`, `adler32.c`, `trees.c`, `infblock.c`, `infcodes.c`, `inftrees.c`, `infutil.c`, `inffast.c`) unless later binary comparison shows the client used a flattened or patched copy.

## LodePNG

The screenshot PNG writer uses a bundled LodePNG encoder backend.

Evidence:

- [UID:0000KW][LodePNG](by-file/LodePNG.md) owns the third-party codec hypothesis for the encode front end and state class.
- [UID:0000XE][0x00443a60-0x00450c9f.LodePngHelperIslandInventory](by-memory/0x00443a60-0x00450c9f.LodePngHelperIslandInventory.md) records the current IDA-modeled helper inventory, direct encode-root callgraph, and raw `0x00444740-0x00444be0` boundary caveat.
- [UID:0000XF][0x00443c80-0x00443e5d.LodePngEncodeFrontEnd](by-memory/0x00443c80-0x00443e5d.LodePngEncodeFrontEnd.md) records the public encode/write chain from `lodepng_encode_memory` at `0x00443c80` through `lodepng_encode32_file` at `0x00443e40`.
- [UID:0000XG][0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers](by-memory/0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers.md) maps the raw unmodeled helper block to `lodepng_error_text`, settings initialization, color-mode initialization, and palette cleanup patterns.
- [UID:0000XH][0x004460f0-0x004461f6.LodePngStateInit](by-memory/0x004460f0-0x004461f6.LodePngStateInit.md) maps `0x004460f0` to the upstream state/default initializer.
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
- [UID:0000VR][0x00401b00-0x004038c7.LibJpegMarkerReader](by-memory/0x00401b00-0x004038c7.LibJpegMarkerReader.md) maps the decompression marker parser to `jdmarker.c`.
- [UID:0000VS][0x00403920-0x004048e2.LibJpegCompressApiFrontEnd](by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md) maps the retained JPEG screenshot writer path to `jcapimin.c`/`jcapistd.c`/`jcparam.c`/`jdatadst.c`.
- [UID:0000VT][0x004048f0-0x004049bb.LibJpegCompressRawDataApi](by-memory/0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md) maps stock `jpeg_write_raw_data` to `jcapistd.c`.
- [UID:0000VU][0x004049c0-0x00404a5c.LibJpegCommonApi](by-memory/0x004049c0-0x00404a5c.LibJpegCommonApi.md) maps `jcomapi.c`.
- [UID:0000VV][0x00404a60-0x0040505b.LibJpegInputController](by-memory/0x00404a60-0x0040505b.LibJpegInputController.md) maps `jdinput.c`.
- [UID:0000VW][0x00405060-0x00405c77.LibJpegMemoryManager](by-memory/0x00405060-0x00405c77.LibJpegMemoryManager.md) maps `jmemmgr.c`.
- [UID:0000VX][0x00405c80-0x004063c8.LibJpegDecompressMaster](by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md) maps `jdmaster.c`.
- [UID:0000VY][0x004063d0-0x0040649b.LibJpegUtilityHelpers](by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md) maps `jutils.c`.
- [UID:0000VZ][0x004064a0-0x00406d8c.LibJpegMarkerWriter](by-memory/0x004064a0-0x00406d8c.LibJpegMarkerWriter.md) maps `jcmarker.c`.
- [UID:0000W0][0x00406d90-0x00406e46.LibJpegCompressMasterInit](by-memory/0x00406d90-0x00406e46.LibJpegCompressMasterInit.md) maps `jcinit.c`.
- [UID:0000W1][0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend](by-memory/0x00406e50-0x00406ed1.LibJpegNoBackingStoreMemoryBackend.md) maps `jmemnobs.c`, not a temp-file backing-store backend.
- [UID:000175][0x004d05f0-0x004d0f4a.ImageDecodeWrappers](by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md) identify two product-owned libjpeg decode callers: `DecodeJpfImageToTileContext` at `0x004d07b0` for profile/look `JPF` portraits and `DecodeJpegBufferToTileContext` at `0x004d0a90` for minimap tile blobs.
- [UID:00018N][0x004efbc0-0x004efe94.JpegScreenshotWriter](by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md) identifies a product-owned compression wrapper used by a raw/retained `.jpg` screenshot path at `0x00557840-0x00557a95`.
- IDA data inspection finds the 121-entry JPEG message pointer table at `0x00631660-0x00631840`.
- IDA rejects the previous provisional `0x00469640-0x00470dc9` neighborhood for LibJPEG: `0x00469640` and `0x00470a00` decompile as BrowserWindow/WebBrowser COM code.
- `0x00414290-0x004142b5` is excluded as Miles `_AIL_shutdown@0` thunk/atexit glue, and [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md) starts at `0x004142c0`.

Source-structure decision:

- Add a `third_party/libjpeg/` reconstruction target.
- Keep product-facing JPEG load/use wrappers with render/image modules, but keep IJG internals under the third-party folder. Current wrapper owners are [UID:0000K3][ImageLoaders](by-file/ImageLoaders.md) for decode and [UID:0000K4][ImageWriters](by-file/ImageWriters.md) for output.
- Do not assign IJG allocator, marker, Huffman, color conversion, or error-manager helpers to NexusTK feature files just because image libraries call them.
- Current source-file anchors strongly include `jerror.c`, `jdapimin.c`, `jdapistd.c`, `jdmarker.c`, `jcapimin.c`, `jcapistd.c`, `jcparam.c`, `jdatadst.c`, `jcomapi.c`, `jdinput.c`, `jmemmgr.c`, `jdmaster.c`, `jutils.c`, `jcmarker.c`, `jcinit.c`, and `jmemnobs.c`. Stock `jdatasrc.c` is not yet proven in the active product decode path because NexusTK uses a local in-memory source helper at `0x004e7030`.

Rebuild/procurement decision:

- Use the official IJG source archive `jpegsrc.v6b.tar.gz`.
- Compare stock libjpeg 6b strings/control flow against `0x00401000-0x00414283` before replacing generated helper files. Local compile options or trimmed encoder/decoder subsets may affect which source files are present.
- Use `jmemnobs.c` as `SYSDEPMEM` for the first reconstruction attempt; `jpeg-6b/makefile.vc` recommends `jmemnobs.obj` for Windows NT/95 style builds.

External source references:

- <https://ijg.org/files/>

## JsonCpp

The executable contains statically linked JsonCpp code used by JSON-facing features such as cash-shop/item-shop metadata.

Evidence:

- IDA strings include JsonCpp parser/settings names such as `collectComments`, `allowComments`, `strictRoot`, `allowDroppedNullPlaceholders`, `allowNumericKeys`, `allowSingleQuotes`, `stackLimit`, `failIfExtra`, `rejectDupKeys`, `allowSpecialFloats`, and many `Json::Value` diagnostics.
- IDA RTTI-ish strings include `.?AVCharReaderBuilder@Json@@`, `.?AVStreamWriterBuilder@Json@@`, `.?AVOurCharReader@Json@@`, and `.?AUBuiltStyledStreamWriter@Json@@`, which points to a JsonCpp API family with builder-based reader/writer classes.
- IDA xrefs to parser diagnostics show two reader-family implementations documented as [UID:0000X2][0x0042ae90-0x0042edeb.JsonCppReaderBuilderIsland](by-memory/0x0042ae90-0x0042edeb.JsonCppReaderBuilderIsland.md) and [UID:0000X8][0x00432e10-0x004345ee.JsonCppSecondParserIsland](by-memory/0x00432e10-0x004345ee.JsonCppSecondParserIsland.md); [UID:0000X7][0x00431d50-0x00431f1c.JsonCppOurReaderParse](by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md) carries the fail-if-extra version discriminator, [UID:0001ZR][0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers](by-memory/0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers.md) fills the second `OurReader` error/token helper gap, [UID:0000X9][0x004345f0-0x00434887.JsonCppNumberTokenParseHelper](by-memory/0x004345f0-0x00434887.JsonCppNumberTokenParseHelper.md) immediately follows the second parser island and carries the `Unable to parse token length` discriminator, and [UID:0001ZS][0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter](by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md) maps the next unicode/comment and `BuiltStyledStreamWriter` helper slice; builder/settings strings are referenced from helpers including `0x0042d380`, `0x0042db90`, `0x0042def0`, [UID:0000XC][0x004417e0-0x00441d24.JsonCppValidReaderKeys](by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md), [UID:0000XD][0x00441d30-0x00442084.JsonCppValidWriterKeys](by-memory/0x00441d30-0x00442084.JsonCppValidWriterKeys.md), and [UID:0000X3][0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland](by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md).
- [UID:0000X1][0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers](by-memory/0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers.md) maps the raw/unmodeled span before the first reader/builder island to legacy `Json::Reader` comment, string, and number scanner helpers.
- [UID:0000X4][0x0042f3f0-0x00430040.JsonCppLegacyWriterCore](by-memory/0x0042f3f0-0x00430040.JsonCppLegacyWriterCore.md) maps the retained `Writer`/`FastWriter`/`StyledWriter` implementation family, [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md) maps the following `StyledWriter::pushValue`-style helper, and [UID:0000X6][0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude](by-memory/0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude.md) maps the remaining writer tail plus `OurReader` constructor prelude.
- [UID:0000WZ][0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport](by-memory/0x00428b4b-0x004298f0.JsonCppValuePathIteratorAndCrtNumericSupport.md) covers the bridge between the value core and document parse front ends, including `__crt_strtox::big_integer`, `Json::Value::setComment()`, path syntax handling, and iterator diagnostics.
- The fitting-room item-shop cache loader uses JsonCpp as a consumer dependency: [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md) calls [UID:0000X0][0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds](by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md) at `0x004298f0` and `0x00429b30`, then reads `version` and category arrays through [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md).
- Existing file docs show JSON-facing product behavior, including [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md) downloading `https://secure.kru.com/itemshop/data/itemshop.json`.
- No explicit JsonCpp version string has been found yet in the binary. Searches for `0.10.6`, `1.7.2`, `JSONCPP_VERSION_STRING`, `JsonCpp`, and `jsoncpp` did not produce executable-string evidence.
- [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md) contains official candidate archives for JsonCpp `0.10.6`, `1.7.0-1.7.7`, and upstream commit `b299d3581f4dc670734f1fe1a34fce1282337802`. `0.10.6` lacks the observed `Unable to parse token length` string and contains the unfound `reader error` string. Release tags `1.7.0-1.7.4` do not fully match the observed static-object `Value::nullSingleton()` implementation, while `1.7.5+` has later reader changes not present in the binary. Current evidence favors the official `b299d358` snapshot between `1.7.4` and `1.7.5`.
- Current static embed state on 2026-05-25: `source-3/third_party_embeds/jsoncpp`, `source-3/simroot_v2/third_party/jsoncpp`, and `obtained_thirdparty_files/static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802` contain the same 16 source/header files hash-for-hash.

Source-structure decision:

- Add a `third_party/jsoncpp/` reconstruction target once the exact version is matched.
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
- [UID:0000W5][0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler](by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md)
- [UID:0000W6][0x00417ba0-0x00419e56.ZlibInflateInternals](by-memory/0x00417ba0-0x00419e56.ZlibInflateInternals.md)
- [UID:0000KW][LodePNG](by-file/LodePNG.md)
- [UID:0000XE][0x00443a60-0x00450c9f.LodePngHelperIslandInventory](by-memory/0x00443a60-0x00450c9f.LodePngHelperIslandInventory.md)
- [UID:0000XF][0x00443c80-0x00443e5d.LodePngEncodeFrontEnd](by-memory/0x00443c80-0x00443e5d.LodePngEncodeFrontEnd.md)
- [UID:0000XG][0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers](by-memory/0x00444740-0x00444be0.LodePngRawErrorAndSettingsHelpers.md)
- [UID:0000XH][0x004460f0-0x004461f6.LodePngStateInit](by-memory/0x004460f0-0x004461f6.LodePngStateInit.md)
- [UID:0000KN][LibJPEG](by-file/LibJPEG.md)
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
- [UID:0000KI][JsonCpp](by-file/JsonCpp.md)
- [UID:0000WY][0x00424630-0x00428b4b.JsonCppValueCore](by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md)
- [UID:0000X0][0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds](by-memory/0x004298f0-0x0042acdf.JsonCppDocumentParseFrontEnds.md)
- [UID:0000X1][0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers](by-memory/0x0042acdf-0x0042ae90.JsonCppLegacyReaderRawLexicalHelpers.md)
- [UID:0000X7][0x00431d50-0x00431f1c.JsonCppOurReaderParse](by-memory/0x00431d50-0x00431f1c.JsonCppOurReaderParse.md)
- [UID:0001ZR][0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers](by-memory/0x00431f20-0x00432e10.JsonCppOurReaderErrorTokenHelpers.md)
- [UID:0000X2][0x0042ae90-0x0042edeb.JsonCppReaderBuilderIsland](by-memory/0x0042ae90-0x0042edeb.JsonCppReaderBuilderIsland.md)
- [UID:0000X8][0x00432e10-0x004345ee.JsonCppSecondParserIsland](by-memory/0x00432e10-0x004345ee.JsonCppSecondParserIsland.md)
- [UID:0000X9][0x004345f0-0x00434887.JsonCppNumberTokenParseHelper](by-memory/0x004345f0-0x00434887.JsonCppNumberTokenParseHelper.md)
- [UID:0001ZS][0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter](by-memory/0x00434890-0x004361ae.JsonCppOurReaderUnicodeAndBuiltStyledStreamWriter.md)
- [UID:0001ZT][0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport](by-memory/0x004361b0-0x00439df9.MsvcStlIostreamTemplateSupport.md)
- [UID:0000X3][0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland](by-memory/0x0042e850-0x0042f3f0.JsonCppStreamWriterBuilderIsland.md)
- [UID:0000X4][0x0042f3f0-0x00430040.JsonCppLegacyWriterCore](by-memory/0x0042f3f0-0x00430040.JsonCppLegacyWriterCore.md)
- [UID:0000X5][0x00430040-0x00430092.GenericStringAppendHelper](by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md)
- [UID:0000X6][0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude](by-memory/0x00430092-0x00431d50.JsonCppWriterTailAndOurReaderPrelude.md)
- [UID:0000XC][0x004417e0-0x00441d24.JsonCppValidReaderKeys](by-memory/0x004417e0-0x00441d24.JsonCppValidReaderKeys.md)
- [UID:0000XD][0x00441d30-0x00442084.JsonCppValidWriterKeys](by-memory/0x00441d30-0x00442084.JsonCppValidWriterKeys.md)
- [UID:0000WU][0x00421a40-0x00422e91.FittingRoomItemShopCatalogState](by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md)
- [UID:0000K4][ImageWriters](by-file/ImageWriters.md)
- [UID:0000T3][InitializeOleSupport](by-global/InitializeOleSupport.md)
- [UID:0000HN][AutoInit](by-file/AutoInit.md)
- [UID:0000HV][Browser](by-file/Browser.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0000P5][VirusChecker](by-file/VirusChecker.md)
