*** UID:0000PC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Zlib

## Status

- Confidence: strong for bundled-library identity and zlib 1.1.4 stock source-file split.
- Proposed module: `third_party/zlib/` or a flattened `third_party/zlib.cpp` reconstruction bundle.
- Current Wave3 files: many one-global recovered files under `source-3/simroot_v2/recovered`, including `Uncompress_00414390.cpp`, `Crc32_00414430.cpp`, `Adler32_00415EE0.cpp`, and `Inflate*.cpp`.
- Main address docs: [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md), [UID:0000W2][0x004142c0-0x00414565.ZlibPublicCompressChecksum](by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md), [UID:0000W4][0x00414820-0x00417b97.ZlibDeflateAndTrees](by-memory/0x00414820-0x00417b97.ZlibDeflateAndTrees.md), [UID:0000W5][0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler](by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md), and [UID:0000W6][0x00417ba0-0x00419e56.ZlibInflateInternals](by-memory/0x00417ba0-0x00419e56.ZlibInflateInternals.md)
- Evidence basis: recovered files, `by-memory/-report.md`, official `zlib-1.1.4.tar.gz` source staged under [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md), and read-only IDA MCP lookup, caller/callee, function-list, string, and decompile checks through 2026-05-25. `wave3.py` was not executed for this pass.

## File Role

This is bundled zlib 1.1.4 support code. It supplies compression/decompression, inflate/deflate internals, CRC-32, Adler-32, and default allocator/free callbacks used by resource and metadata systems.

Treat the current one-function recovered files as staging containers. A faithful source layout should group them as a zlib support library, not as NexusTK-owned classes or as private methods of `MetaMan`, `DATFile`, palette, image, or startup code.

## Proposed Contents

| Entity | Range | Role |
| --- | --- | --- |
| `Compress2` / `Compress` wrappers | `0x004142c0-0x0041438f` | zlib compression front end; `0x00414370` wraps `0x004142c0` with default level `-1`. |
| `Uncompress` | `0x00414390-0x0041442c` | zlib `uncompress` wrapper using version string `1.1.4`, `InflateInit`, `Inflate`, and `InflateEnd`. |
| `Crc32` | `0x00414430-0x00414565` | Table-driven CRC-32 helper over `dword_63211C[256]`. |
| `DeflateInit`, `DeflateInit2`, `DeflateReset` | `0x00414570-0x00414813` | Public deflate setup/reset wrappers and direct deflate-state setup path. |
| `deflate.c` internals | `0x00414820-0x004158aa` | `deflate`, `deflateEnd`, stored/fast/slow compression, fill-window, read-buffer, and longest-match helpers. |
| `InflateReset`, `InflateEnd`, `InflateInit2`, `InflateInit`, `Inflate`, `ZlibAlloc`, `ZlibFree`, `Adler32` | `0x004158b0-0x0041600e` | Public inflate wrapper/state lifecycle, default allocator/free callbacks, and Adler-32 helper. |
| `trees.c` deflate helpers | `0x00416010-0x00417b97` | Deflate Huffman tree construction, block flushing, bit output, stored-block copy, and static-tree setup. |
| Inflate internals | `0x00417ba0-0x00419e56` | zlib inflate block, code, Huffman tree, flush, and fast-inflate helpers. |

## Source Split Hypothesis

If the final tree preserves the stock zlib source shape, the likely split is:

| Proposed file | Covered binary ranges |
| --- | --- |
| `compress.c` | `0x004142c0-0x0041438f` |
| `uncompr.c` | `0x00414390-0x0041442c` |
| `crc32.c` | `0x00414430-0x00414565` plus `dword_63211C` |
| `deflate.c` | `0x00414570-0x004158aa` |
| `inflate.c` | `0x004158b0-0x00415e77` |
| `zutil.c` | `0x00415eb0-0x00415edc` default `zcalloc`/`zcfree` callbacks |
| `adler32.c` | `0x00415ee0-0x0041600e` |
| `trees.c` | `0x00416010-0x00417b97` |
| `infblock.c` | `0x00417ba0-0x004189d0` |
| `infcodes.c` | `0x00418a10-0x00419214` |
| `inftrees.c` | `0x00419220-0x0041994e` |
| `infutil.c` / `inffast.c` | `0x00419950-0x00419e56` |

This split now matches the staged official zlib 1.1.4 source order and IDA callgraph. A single flattened `third_party/zlib.cpp` would still be preferable to assigning helpers to product modules, but the stock multi-file layout is the better first rebuild target.

## Evidence

- IDA strings include ` deflate 1.1.4 Copyright 1995-2002 Jean-loup Gailly ` and ` inflate 1.1.4 Copyright 1995-2002 Mark Adler `.
- IDA strings include zlib diagnostics such as `incorrect header check`, `invalid distance code`, and `insufficient memory`.
- Generated `Uncompress_00414390.cpp` uses version string `1.1.4`, constructs a zlib-style stream layout, calls `InflateInit`, runs `Inflate(..., 4)`, and tears down with `InflateEnd`.
- Generated `Crc32_00414430.cpp` is a standard CRC-32 update routine over a 256-entry table.
- Generated `Adler32_00415EE0.cpp` is a standard chunked Adler-32 routine using modulo `0xfff1` and max chunk `0x15b0`.
- IDA decompilation maps `0x00414820-0x004158aa` to the normal zlib deflate worker family and `0x00416010-0x00417b97` to deflate `trees.c` bit/Huffman helpers.
- IDA decompilation maps `0x00417c20`, `0x00418a10`, `0x00419220`, `0x004192d0`, `0x00419790`, and `0x00419920` to inflate block allocation, codes allocation, dynamic tree construction, Huffman table build, and fixed tree access helpers.
- Source comparison against staged `zlib-1.1.4` maps `0x004142c0-0x00414565` to `compress.c`, `uncompr.c`, and `crc32.c`; `0x004158b0-0x0041600e` to `inflate.c`, `zutil.c`, and `adler32.c`; and `0x00417ba0-0x00419e56` to `infblock.c`, `infcodes.c`, `inftrees.c`, `infutil.c`, and `inffast.c`.
- IDA callers show `Uncompress` is called by resource consumers including image/resource layout, startup logo, app startup, screen/palette paths, and `MetaTable::DecompressAndValidateData`.
- IDA callers show `Crc32` is called by the same `MetaTable` decode/validate method that calls `Uncompress`.

## Ownership Decision

Keep the zlib family as third-party support code. `MetaTable`, palette, image, startup, and other resource modules consume `Uncompress`, `Crc32`, or `Adler32`; they do not own those helpers.

Do not split `Crc32`, `Adler32`, `InflateFast`, and the inflate/deflate state machine across caller modules during source reconstruction. The current recovered one-global files are useful for review but not a plausible original project structure.

## Open Questions

- Whether the final reconstructed tree should preserve zlib's original multi-file layout or use a single flattened support file. Current evidence favors the original multi-file layout.
- Exact names for some compiler-local static helpers can still drift because optimization changes boundaries, but the owning stock zlib source files are now strong.
- Whether any local compile-time zlib options changed behavior from stock zlib 1.1.4.

## Cross-References

- [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md)
- [UID:0000W2][0x004142c0-0x00414565.ZlibPublicCompressChecksum](by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md)
- [UID:0000W4][0x00414820-0x00417b97.ZlibDeflateAndTrees](by-memory/0x00414820-0x00417b97.ZlibDeflateAndTrees.md)
- [UID:0000W5][0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler](by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md)
- [UID:0000W6][0x00417ba0-0x00419e56.ZlibInflateInternals](by-memory/0x00417ba0-0x00419e56.ZlibInflateInternals.md)
- [UID:0000IM][DATArchive](by-file/DATArchive.md)
- [UID:0000LC][MetaMan](by-file/MetaMan.md)
- [UID:000089][MetaTable](by-class/MetaTable.md)
- [UID:0001QC][client_dat_specifications](by-meta/client_dat_specifications.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
- [UID:0000KW][LodePNG](by-file/LodePNG.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `92/90`. Summary/evidence: the page documents third-party zlib 1.1.4 identity, stock source split, covered ranges, IDA/string/source-comparison evidence, and ownership boundaries; only minor compile-option/helper-boundary questions remain.
