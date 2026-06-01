*** UID:0001QY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Static Embeds

This folder contains third-party source files that should be compiled into the rebuilt NexusTK executable when matching the observed binary. It intentionally excludes runtime DLL dependencies and tools/examples that should not become part of the EXE.

## Included Static Source Trees

| Folder | Source archive | Rebuild role |
| --- | --- | --- |
| `zlib-1.1.4/` | `../archives/zlib-1.1.4.tar.gz` | Confirmed static zlib 1.1.4 compression, checksum, deflate, and inflate support. `gzio.c`, examples, and test programs are excluded because current evidence maps only the core object-family into the EXE. |
| `libjpeg-6b/` | `../archives/jpegsrc.v6b.tar.gz` | IJG libjpeg 6b library source. This includes the library object set from `makefile.vc` plus the no-backing-store memory backend `jmemnobs.c`; sample applications, alternate memory backends, docs, and tests are excluded. `jconfig.h` is copied from upstream `jconfig.vc` for the Windows-style build configuration. |
| `lodepng-20160501/` | `../archives/lodepng-20160501-c6cf08b8910d91b0830666c07845116df1e9b6fc.zip` | Confirmed LodePNG 20160501 source: `lodepng.cpp` and `lodepng.h`. Examples, tests, utilities, and benchmark files are excluded. |
| `jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802/` | `../archives/jsoncpp-b299d3581f4dc670734f1fe1a34fce1282337802.candidate.zip` | Best current JsonCpp static-source candidate. Preserves the upstream `include/json/` plus `src/lib_json/` layout needed to compile the library into the EXE. |

On 2026-05-26, all four working embed trees under `source-3/third_party_embeds/` and the generated mirrors under `source-3/simroot_v2/third_party/` were checked against this folder and matched hash-for-hash: JsonCpp `16` files, libjpeg `57` files, LodePNG `2` files, and zlib `24` files.

## Excluded From Static Embeds

- `libcurl`: observed as dynamic `libcurl.dll`, so do not compile curl source into the NexusTK EXE.
- RAD Bink and RAD Miles: proprietary dynamic runtime files (`binkw32.dll`, `Mss32.dll`, `Mp3dec.asi`), not static source.
- AhnLab V3 DLLs: optional dynamic scanner integration, not present in the observed local client folder.
- Windows SDK, DirectX, WinSock, COM/OLE, and MSVC CRT/STL support: toolchain/system dependencies, not vendored project source.
- Third-party examples, tests, command-line tools, benchmark files, docs, generated build files, and alternate platform backends unless later binary evidence proves they were embedded.

## Notes

- `SHA256SUMS.txt` in this folder hashes the staged static source/header files.
- The parent `archives/` folder remains the source of record for full upstream packages and comparison candidates.
- If later IDA/source comparison proves an omitted source file is actually linked into the EXE, add it here and update this manifest.
