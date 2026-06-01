*** UID:0001QX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Obtained Third-Party Files

## Status

- Created: 2026-05-25
- Scope: source archives and local runtime DLL/ASI files for the third-party dependencies documented in [UID:0001QE][client_libraries](by-meta/client_libraries.md).
- Evidence basis: official source/vendor locations, local shipped-client files from `C:\Users\admin\Desktop\Clone\NexusTK`, and prior IDA MCP version evidence. `wave3.py` was not executed for this acquisition pass.
- Acquisition rule: use official open-source archives for statically linked libraries, copy proprietary runtime redistributables only from the observed local client or a licensed vendor package, and do not use generic DLL mirror downloads.

## Layout

```text
obtained_thirdparty_files/
  archives/
    curl-7.48.0.zip
    jpegsrc.v6b.tar.gz
    jsoncpp-0.10.6.candidate.zip
    jsoncpp-1.7.0.candidate.zip
    jsoncpp-1.7.1.candidate.zip
    jsoncpp-1.7.2.candidate.zip
    jsoncpp-1.7.3.candidate.zip
    jsoncpp-1.7.4.candidate.zip
    jsoncpp-1.7.5.candidate.zip
    jsoncpp-1.7.6.candidate.zip
    jsoncpp-1.7.7.candidate.zip
    jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802.candidate.zip
    lodepng-20160501-c6cf08b8910d91b0830666c07845116df1e9b6fc.zip
    zlib-1.1.4.tar.gz
  static_embeds/
    jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/
    libjpeg-6b/
    lodepng-20160501/
    zlib-1.1.4/
  runtime_from_local_client/
    binkw32.dll
    libcurl.dll
    Mp3dec.asi
    Mss32.dll
```

## Validation

- Validated locally on 2026-05-25.
- `static_embeds/` contains only the staged source/header files currently believed to be compiled into the rebuilt EXE: zlib 1.1.4, IJG libjpeg 6b, LodePNG 20160501, and the best JsonCpp `b299d358` snapshot. Dynamic dependencies such as libcurl, Bink, Miles, and AhnLab are intentionally excluded from this static-source folder.
- 2026-05-25 14:08 PDT user-requested acquisition pass: re-downloaded every official open-source archive URL listed below into a temporary verification folder. All downloaded files matched the staged archives byte-for-byte, so no replacement was needed.
- 2026-05-25 13:44 PDT acquisition recheck: all official upstream downloads matched the staged archive SHA-256 hashes, and the copied Bink/Miles/libcurl runtime files matched the observed local client files byte-for-byte. No file replacement was needed.
- 2026-05-25 13:25 PDT acquisition recheck: the official upstream URLs for zlib 1.1.4, IJG jpeg 6b, curl 7.48.0, LodePNG commit `c6cf08b8910d91b0830666c07845116df1e9b6fc`, JsonCpp tags `0.10.6` and `1.7.0-1.7.7`, and JsonCpp commit `b299d3581f4dc670734f1fe1a34fce1282337802` were re-downloaded into a temporary verification folder and matched the staged archives byte-for-byte. No archive replacement was needed.
- The local runtime copy check matched `binkw32.dll`, `Mss32.dll`, `Mp3dec.asi`, and `libcurl.dll`; optional `V3PRO32E.DLL` and `V3PCTRL.DLL` were still absent from the observed local client folder.
- Historical note from the first acquisition pass: the LodePNG GitHub auto-generated ZIP initially had different container bytes from an earlier staged ZIP. The current staged replacement expands to commit `c6cf08b8910d91b0830666c07845116df1e9b6fc`, and both `lodepng.cpp` and `lodepng.h` contain `LodePNG version 20160501`.
- `archives/zlib-1.1.4.tar.gz` lists the expected `zlib-1.1.4/` source tree. Follow-up IDA/source comparison maps the observed public wrappers, allocator callbacks, checksums, deflate workers, tree helpers, and inflate internals to the stock source-file family.
- `archives/jpegsrc.v6b.tar.gz` lists the expected `jpeg-6b/` source tree. Follow-up IDA/source comparison maps the observed public decompression API to `jdapimin.c`/`jdapistd.c`, marker reader to `jdmarker.c`, common API to `jcomapi.c`, decompression input/master control to `jdinput.c`/`jdmaster.c`, utility helpers to `jutils.c`, the screenshot compression path to `jcapimin.c`/`jcapistd.c`/`jcparam.c`/`jdatadst.c`, marker writer/compress master setup to `jcmarker.c`/`jcinit.c`, and the memory manager/backend to `jmemmgr.c` plus `jmemnobs.c`.
- `archives/curl-7.48.0.zip` opens as a ZIP with 3109 entries under `curl-7.48.0/`.
- JsonCpp candidate ZIPs open under their expected `jsoncpp-*` source-tree roots. The official commit archive `jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802.candidate.zip` opens with 250 entries under `jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/`. The extracted best candidate contains `include/json/*.h` and `src/lib_json/json_reader.cpp`, `json_value.cpp`, and `json_writer.cpp`, but no generated `dist/jsoncpp.cpp` amalgamation directory.
- `archives/lodepng-20160501-c6cf08b8910d91b0830666c07845116df1e9b6fc.zip` opens as a ZIP with 25 entries and contains `lodepng.cpp` with `LodePNG version 20160501`.
- Extracted LodePNG source fingerprints from the staged archive: `lodepng.cpp` SHA256 `71F9A45829F9AF7A6675200153DAAB5D791846A7EC4C5385241AC6F1E35B629A`; `lodepng.h` SHA256 `9B330CA0224E85EB8937DC83627BDFA0285C6CC6691223D3FD51D8987A2D284B`.
- `SHA256SUMS.txt` records hashes for every obtained source archive and copied runtime file.
- 2026-05-26 static-embed mirror check: `source-3/third_party_embeds` and `source-3/simroot_v2/third_party` match `static_embeds` hash-for-hash for JsonCpp `16` files, libjpeg `57` files, LodePNG `2` files, and zlib `24` files.
- 2026-05-25 static-embed check: `source-3/third_party_embeds/jsoncpp` and `source-3/simroot_v2/third_party/jsoncpp` match `static_embeds/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802` hash-for-hash.

## Exact Open-Source Archives

| File | Status | Source |
| --- | --- | --- |
| `archives/zlib-1.1.4.tar.gz` | Exact source version for statically embedded zlib 1.1.4. Current source-file anchors cover `compress.c`, `uncompr.c`, `crc32.c`, `deflate.c`, `inflate.c`, `zutil.c`, `adler32.c`, `trees.c`, `infblock.c`, `infcodes.c`, `inftrees.c`, `infutil.c`, and `inffast.c`. | `https://zlib.net/fossils/zlib-1.1.4.tar.gz` |
| `archives/curl-7.48.0.zip` | Exact source version matching shipped `libcurl.dll` version 7.48.0; runtime build still needs Schannel/WinSSL options | `https://curl.se/download/curl-7.48.0.zip` |
| `archives/jpegsrc.v6b.tar.gz` | Exact source version for IJG libjpeg 6b. Source comparison now confirms public API, marker reader/writer, common API, input/master controllers, utility, memory-manager, and no-backing-store backend anchors. | `https://ijg.org/files/jpegsrc.v6b.tar.gz` |
| `archives/lodepng-20160501-c6cf08b8910d91b0830666c07845116df1e9b6fc.zip` | Exact LodePNG version-string candidate. The upstream repo has no tag named `20160501`; `git log -S 20160501` resolves the matching source snapshot to commit `c6cf08b8910d91b0830666c07845116df1e9b6fc`. IDA/source comparison now also matches the public encode/file helpers at `0x00443c80`, `0x00443db0`, and `0x00443e40` to this source. | `https://github.com/lvandeve/lodepng/archive/c6cf08b8910d91b0830666c07845116df1e9b6fc.zip` |

## JsonCpp Candidates

JsonCpp is confirmed as statically embedded. The observed binary strings include `CharReaderBuilder`, `StreamWriterBuilder`, `collectComments`, `allowComments`, `allowSpecialFloats`, `Error from reader: %s`, and `Json::Value` diagnostics.

2026-05-25 follow-up: IDA/source comparison now rejects `0.10.6` as an equal candidate and narrows the best match to official JsonCpp source after commit `b299d3581f4dc670734f1fe1a34fce1282337802` and before the later `1.7.5` reader changes. The executable contains `Unable to parse token length` at `0x0060e730` and does not contain `reader error`, matching the `1.7.x` reader family rather than `0.10.6`. The value core contains the `Value::nullSingleton()` static-object behavior introduced by upstream commit `b299d358` (`Allow dtor for nullSingleton`). The same value constructor still initializes `stringValue` with a null pointer, so it predates upstream commit `7e0571b` (`Avoid null for stringValue`). The `OurReader::parse` fail-if-extra branch at `0x00431d50` lacks the `strictRoot` term added by upstream commit `126bdc2`, and `0x004345f0` lacks the `fixNumericLocaleInput()` call added by `094a7d8`; this rejects official tag `1.7.5` and newer for the observed binary.

| File | Status | Source |
| --- | --- | --- |
| `archives/jsoncpp-0.10.6.candidate.zip` | Retained for comparison, but no longer favored by the current IDA/source discriminator. | `https://github.com/open-source-parsers/jsoncpp/archive/refs/tags/0.10.6.zip` |
| `archives/jsoncpp-1.7.0.candidate.zip` | Retained release-tag comparison. It has the observed reader string family, but lacks the later static-object `nullSingleton()` evidence. | `https://github.com/open-source-parsers/jsoncpp/archive/refs/tags/1.7.0.zip` |
| `archives/jsoncpp-1.7.1.candidate.zip` | Retained release-tag comparison. It has the observed reader string family, but lacks the later static-object `nullSingleton()` evidence. | `https://github.com/open-source-parsers/jsoncpp/archive/refs/tags/1.7.1.zip` |
| `archives/jsoncpp-1.7.2.candidate.zip` | Retained release-tag comparison. It has the observed reader string family, but lacks the later static-object `nullSingleton()` evidence. | `https://github.com/open-source-parsers/jsoncpp/archive/refs/tags/1.7.2.zip` |
| `archives/jsoncpp-1.7.3.candidate.zip` | Retained release-tag comparison. It introduces `nullSingleton()`, but uses the heap-pointer singleton form rather than the binary's static-object form. | `https://github.com/open-source-parsers/jsoncpp/archive/refs/tags/1.7.3.zip` |
| `archives/jsoncpp-1.7.4.candidate.zip` | Retained release-tag comparison. It still uses the heap-pointer singleton form rather than the binary's static-object form. | `https://github.com/open-source-parsers/jsoncpp/archive/refs/tags/1.7.4.zip` |
| `archives/jsoncpp-1.7.5.candidate.zip` | Retained negative comparison. It has the static-object singleton but also has later reader changes not present in the binary. | `https://github.com/open-source-parsers/jsoncpp/archive/refs/tags/1.7.5.zip` |
| `archives/jsoncpp-1.7.6.candidate.zip` | Retained negative comparison; inherits the rejected `1.7.5` reader behavior. | `https://github.com/open-source-parsers/jsoncpp/archive/refs/tags/1.7.6.zip` |
| `archives/jsoncpp-1.7.7.candidate.zip` | Retained negative comparison; inherits the rejected `1.7.5` reader behavior. | `https://github.com/open-source-parsers/jsoncpp/archive/refs/tags/1.7.7.zip` |
| `archives/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802.candidate.zip` | Best current source snapshot candidate. It is the official upstream commit that matches the observed static-object `nullSingleton()` while preceding the later string-constructor and reader changes rejected by IDA. The archive's generated `version.h` still reports `JSONCPP_VERSION_STRING "1.7.4"`, so identify this dependency by commit hash rather than by release tag. | `https://github.com/open-source-parsers/jsoncpp/archive/b299d3581f4dc670734f1fe1a34fce1282337802.zip` |

## Proprietary Runtime Files

These were copied from the local shipped client folder, not downloaded from unofficial DLL sites.

| File | Local source | Version evidence |
| --- | --- | --- |
| `runtime_from_local_client/binkw32.dll` | `C:\Users\admin\Desktop\Clone\NexusTK\binkw32.dll` | Bink `1.0s` |
| `runtime_from_local_client/Mss32.dll` | `C:\Users\admin\Desktop\Clone\NexusTK\Mss32.dll` | Miles Sound System `6.1c` |
| `runtime_from_local_client/Mp3dec.asi` | `C:\Users\admin\Desktop\Clone\NexusTK\Mp3dec.asi` | Miles Sound System `6.1c` |
| `runtime_from_local_client/libcurl.dll` | `C:\Users\admin\Desktop\Clone\NexusTK\libcurl.dll` | libcurl `7.48.0`, WinSSL/Schannel strings |

Do not fetch RAD Bink, RAD Miles, or AhnLab DLLs from generic DLL download sites. A 2026-05-25 web recheck found official RAD/Epic product/history pages for Bink and Miles, but no official public archive for historical Bink `1.0s` or Miles `6.1c` SDK/runtime packages. Bink/Miles should come from the original client redistributables already copied here or from a licensed RAD/Epic Game Tools SDK/runtime. Official references checked:

- RAD/Epic Bink development history: `https://www.radgametools.com/bnkhist.htm`
- RAD/Epic Miles product page: `https://www.radgametools.com/miles.htm`
- RAD/Epic Miles development history: `https://www.radgametools.com/msshist.htm`

Not obtained:

| Dependency | Reason |
| --- | --- |
| RAD Bink SDK/import library for Bink `1.0s` | Proprietary middleware; no official public historical SDK/runtime download was found. Use the copied `binkw32.dll` or a licensed RAD/Epic package. |
| RAD Miles SDK/import library for Miles `6.1c` | Proprietary middleware; no official public historical SDK/runtime download was found. Use the copied `Mss32.dll`/`Mp3dec.asi` or a licensed RAD/Epic package. |
| `V3PRO32E.DLL` / `V3PCTRL.DLL` | Optional AhnLab V3 scanner DLLs were not present in the observed local client folder, and no exact official redistributable matching this old integration was located. |
| Windows SDK, DirectX, MSVC CRT/STL support | System/toolchain dependencies, not project-owned third-party source to archive here. |

## Next Matching Work

- Continue lower-helper matching for `lodepng-20160501` against the full `0x00443a60-0x00450c9f` helper island; public wrappers and state init now match.
- Continue mapping remaining IJG libjpeg internal helper clusters, especially Huffman helpers, coefficient controllers, color conversion, sampling, quantizers, and DCT/IDCT modules. Marker reader/writer, common API, input/master controllers, utility helpers, and memory-manager/backend anchors are now mapped.
- Continue lower-helper JsonCpp object-layout/control-flow mapping against the `b299d3581f4dc670734f1fe1a34fce1282337802` commit archive; the source-version and first rebuild folder layout are now strong enough to use `include/json/` plus `src/lib_json/` as the working `third_party/jsoncpp/` target.
- For libcurl rebuilds, reproduce a Windows Schannel/WinSSL build rather than assuming OpenSSL.
