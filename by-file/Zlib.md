*** UID:0000PC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/third_party/zlib/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Zlib

## Status

- Confidence: strong for bundled-library identity, zlib 1.1.4 stock source-file split, and W3 non-emitting parent/index routing.
- Proposed module: `third_party/zlib/` with stock multi-file zlib source layout.
- Generated caveat: `auto-generated/NexusTK/third_party/zlib/Zlib.cpp` is validator-assembled from routed by-memory source imports and support markers. It must not override the stock zlib multi-file placement recorded here.
- Main address docs: [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md), [UID:0000W2][0x004142c0-0x00414565.ZlibPublicCompressChecksum](by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md), [UID:0000W4][0x00414820-0x004158aa.ZlibDeflateWorkers](by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md), [UID:0000W5][0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler](by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md), [UID:0004IK][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md), and non-emitting inflate index [UID:0000W6][0x00417ba0-0x00419e56.ZlibInflateInternals](by-memory/0x00417ba0-0x00419e56.ZlibInflateInternals.md) with exact source children [UID:0004IF][0x00417ba0-0x00418a09.ZlibInfBlock](by-memory/0x00417ba0-0x00418a09.ZlibInfBlock.md), [UID:0004IG][0x00418a10-0x00419214.ZlibInfCodes](by-memory/0x00418a10-0x00419214.ZlibInfCodes.md), [UID:0004IH][0x00419220-0x0041994e.ZlibInfTrees](by-memory/0x00419220-0x0041994e.ZlibInfTrees.md), [UID:0004II][0x00419950-0x00419a82.ZlibInfUtilFlush](by-memory/0x00419950-0x00419a82.ZlibInfUtilFlush.md), and [UID:0004IJ][0x00419a90-0x00419e56.ZlibInfFast](by-memory/0x00419a90-0x00419e56.ZlibInfFast.md).
- Evidence basis: staged official `zlib-1.1.4` source under `source-3/third_party_embeds/zlib`, [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md), B008 live MCP session `80de0a67`, current B002 split evidence, and existing zlib code/data pages.

## File Role

This is bundled zlib 1.1.4 support code. It supplies compression/decompression, inflate/deflate internals, CRC-32, Adler-32, and default allocator/free callbacks used by resource and metadata systems.

Treat one-function recovered/generated files as staging artifacts. A faithful source layout should group this code as vendored zlib under `NexusTK/third_party/zlib/`, not as NexusTK-owned classes and not as private methods of `MetaMan`, `DATFile`, palette, image, startup, or render modules.

[UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md) is the non-emitting parent/index for the executable zlib island. It records the source-file families and child split, while stock source files under `NexusTK/third_party/zlib/` remain the source of record.

## Proposed Contents

| Entity | Range | Role |
| --- | --- | --- |
| `compress2` / `compress` wrappers | `0x004142c0-0x0041438f` | zlib compression front end; `0x00414370` wraps `0x004142c0` with default level `-1`. |
| `uncompress` | `0x00414390-0x0041442c` | zlib `uncompress` wrapper using version string `1.1.4`, inflate init/run/end. |
| `crc32` | `0x00414430-0x00414565` | Table-driven CRC-32 helper over `crc_table[256]` at `0x0063211c`. |
| `deflateInit_`, `deflateInit2_`, `deflateReset` | `0x00414570-0x00414813` | Public deflate setup/reset wrappers and deflate-state setup path. |
| `deflate.c` workers | [UID:0000W4][0x00414820-0x004158aa.ZlibDeflateWorkers](by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md) | `deflate`, `deflateEnd`, stored/fast/slow compression, fill-window, read-buffer, longest-match, and `configuration_table` dispatch. |
| `inflateReset`, `inflateEnd`, `inflateInit2_`, `inflateInit_`, `inflate`, `zcalloc`, `zcfree`, `adler32` | `0x004158b0-0x0041600e` | Public inflate wrapper/state lifecycle, `inflate` switch jump table at `0x00415e78-0x00415eb0`, default zlib callbacks, and Adler-32 helper. |
| `trees.c` deflate output helpers | [UID:0004IK][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md) | Deflate Huffman tree construction, block flushing, bit output, stored-block copy, and static-tree setup; sole stock `trees.c` importer. |
| Inflate internals | [UID:0000W6][0x00417ba0-0x00419e56.ZlibInflateInternals](by-memory/0x00417ba0-0x00419e56.ZlibInflateInternals.md) `0x00417ba0-0x00419e56` | Non-emitting index over exact stock-source emitters [UID:0004IF][0x00417ba0-0x00418a09.ZlibInfBlock](by-memory/0x00417ba0-0x00418a09.ZlibInfBlock.md) `infblock.c`, [UID:0004IG][0x00418a10-0x00419214.ZlibInfCodes](by-memory/0x00418a10-0x00419214.ZlibInfCodes.md) `infcodes.c`, [UID:0004IH][0x00419220-0x0041994e.ZlibInfTrees](by-memory/0x00419220-0x0041994e.ZlibInfTrees.md) `inftrees.c`, [UID:0004II][0x00419950-0x00419a82.ZlibInfUtilFlush](by-memory/0x00419950-0x00419a82.ZlibInfUtilFlush.md) `infutil.c`, and [UID:0004IJ][0x00419a90-0x00419e56.ZlibInfFast](by-memory/0x00419a90-0x00419e56.ZlibInfFast.md) `inffast.c`. |
| CRC table and deflate copyright string | [UID:0003OJ][0x0063211c-0x00632560.Zlib114CrcAndDeflateString](by-memory/0x0063211c-0x00632560.Zlib114CrcAndDeflateString.md) | zlib `crc_table[256]`, alignment, the `deflate.c` copyright/version string, and alignment before `configuration_table[10]`; B009 proves the earlier `0x00631850-0x0063211c` interval is libjpeg, not zlib. |
| `configuration_table[10]` | [UID:0004IL][0x00632560-0x006325d8.ZlibDeflateConfigurationTable](by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md) | zlib deflate compression-level table referenced from `0x004149b4`; exact data page is covered by UID0000W4's sole `deflate.c` import. |
| `border[19]` | `0x00633004-0x00633050` | Exact `infblock.c` file-local dynamic-tree code-length permutation, read by `inflate_blocks` at `0x004180b5` and `0x004180ea`; source-covered once by UID0004IF's stock import. |
| Inflate copyright string | [UID:0003P7][0x00633050-0x00633080.ZlibInflateVersionString](by-memory/0x00633050-0x00633080.ZlibInflateVersionString.md) | External `inftrees.c` `inflate_copyright[]`: 46 characters, required NUL, and one linker-alignment byte; source-covered once by UID0004IH. |
| `cplens[31]`, `cplext[31]`, `cpdist[30]`, `cpdext[30]` | `0x00633080-0x00633268` | Exact file-local `inftrees.c` base/extra tables in source order; `cplens` is read at `0x004197e5` by `inflate_trees_dynamic`; source-covered once by UID0004IH. |
| Runtime/compiler read-only continuation | `0x00633268+` | Runtime-owned data resumes after the exact zlib arrays; standard `bad allocation` begins at `0x00633274`. |

## Source Split

The current best source split preserves the stock zlib 1.1.4 layout:

| Proposed file | Covered binary ranges / data |
| --- | --- |
| `compress.c` | `0x004142c0-0x0041438f` |
| `uncompr.c` | `0x00414390-0x0041442c` |
| `crc32.c` | `0x00414430-0x00414565` plus `crc_table[256]` at `0x0063211c-0x0063251c` in [UID:0003OJ][0x0063211c-0x00632560.Zlib114CrcAndDeflateString](by-memory/0x0063211c-0x00632560.Zlib114CrcAndDeflateString.md) |
| `deflate.c` | `0x00414570-0x004158aa`, plus exact data child [UID:0004IL][0x00632560-0x006325d8.ZlibDeflateConfigurationTable](by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md); UID0000W4 is the sole full-file importer and UID0004IL emits a covered-by comment only |
| `inflate.c` | `0x004158b0-0x00415eb0`, including `inflateReset`, `inflateEnd`, `inflateInit2_`, `inflateInit_`, `inflate`, the one-byte `0x00415e77-0x00415e78` alignment, and the `0x00415e78-0x00415eb0` compiler jump table for the public `inflate` state switch |
| `zutil.c` | `0x00415eb0-0x00415edc` default `zcalloc`/`zcfree` callbacks |
| `adler32.c` | `0x00415ee0-0x0041600e` |
| `trees.c` | [UID:0004IK][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md) `0x00416010-0x00417b97` |
| `infblock.c` | [UID:0004IF][0x00417ba0-0x00418a09.ZlibInfBlock](by-memory/0x00417ba0-0x00418a09.ZlibInfBlock.md) `0x00417ba0-0x00418a09`, including `inflate_blocks_free` at `0x004189d0-0x00418a09`, plus file-local `border[19]` at `0x00633004-0x00633050`; the historical endpoint at `0x004189d0` was the function start and is superseded |
| `infcodes.c` | [UID:0004IG][0x00418a10-0x00419214.ZlibInfCodes](by-memory/0x00418a10-0x00419214.ZlibInfCodes.md) `0x00418a10-0x00419214`, including `inflate_codes_free` at `0x00419200-0x00419214` |
| `inftrees.c` | [UID:0004IH][0x00419220-0x0041994e.ZlibInfTrees](by-memory/0x00419220-0x0041994e.ZlibInfTrees.md) `0x00419220-0x0041994e`, plus [UID:0003P7][0x00633050-0x00633080.ZlibInflateVersionString](by-memory/0x00633050-0x00633080.ZlibInflateVersionString.md) external `inflate_copyright[]`/NUL/alignment, local `cplens[31]` at `0x00633080-0x006330fc`, `cplext[31]` at `0x006330fc-0x00633178`, `cpdist[30]` at `0x00633178-0x006331f0`, `cpdext[30]` at `0x006331f0-0x00633268`, and compiled fixed descriptors/tables in [UID:00028E][0x00671a74-0x00672eb4.Zlib114DataMessagesAndTables](by-memory/0x00671a74-0x00672eb4.Zlib114DataMessagesAndTables.md); UID0004IH is the sole importer |
| `infutil.c` | [UID:0004II][0x00419950-0x00419a82.ZlibInfUtilFlush](by-memory/0x00419950-0x00419a82.ZlibInfUtilFlush.md) `0x00419950-0x00419a82` plus `inflate_mask[17]` in [UID:00028E][0x00671a74-0x00672eb4.Zlib114DataMessagesAndTables](by-memory/0x00671a74-0x00672eb4.Zlib114DataMessagesAndTables.md) |
| `inffast.c` | [UID:0004IJ][0x00419a90-0x00419e56.ZlibInfFast](by-memory/0x00419a90-0x00419e56.ZlibInfFast.md) `0x00419a90-0x00419e56`, consuming `inflate_mask[17]` |

A single flattened `third_party/zlib.cpp` would still be preferable to assigning helpers to product modules, but it is inferior to the stock multi-file layout now that the official source is staged and the split is supported by current MCP evidence.

[UID:0000W5][0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler](by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md) remains a mixed source-map child even though the source split above records exact subranges: it contains `inflate.c` code and compiler table data, `zutil.c` default callbacks, and `adler32.c`. Its formal by-memory C++ block stays blank unless exact source-file children are split.

## Evidence

- IDA strings include ` deflate 1.1.4 Copyright 1995-2002 Jean-loup Gailly ` and ` inflate 1.1.4 Copyright 1995-2002 Mark Adler `.
- IDA strings include zlib diagnostics such as `incorrect header check`, `invalid distance code`, and `insufficient memory`.
- B008 live MCP session `80de0a67` confirmed [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md) as a non-emitting parent/index with 59 in-range functions, parent-only `deflate.c` setup/reset at `0x00414570-0x00414813`, padding through the `0x00419e56` endpoint, and excluded static-initializer successor thunks at `0x00419e60` and `0x00419e70`.
- B002 evidence-time MCP session `80de0a67` confirmed [UID:0000W4][0x00414820-0x004158aa.ZlibDeflateWorkers](by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md), [UID:0000W5][0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler](by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md), and the new `trees.c` child are separate source-bearing siblings divided by alignment padding.
- `0x004149b4` inside `deflate` references `0x00632560`, now corrected as zlib `deflate.c` `configuration_table[10]`.
- Source comparison against staged `zlib-1.1.4` maps code and data to the stock source files above.
- B002 UID0003P7 mandatory MCP session `9b0396a3` and exact staged-source comparison proved the early read-only sequence: the preceding `trees.h` tail dword at `0x00633000`; `infblock.c` `border[19]` through `0x00633050`; `inftrees.c` copyright/NUL/alignment through `0x00633080`; four local `inftrees.c` arrays through `0x00633268`; then runtime/compiler data. The live `border` and `cplens` xrefs agree with the stock functions and source order.
- B003 mandatory MCP database `545b4991` and exact staged source comparison resolved every W6 function/prototype/linkage and created five validator-assigned emitters. Child-owned compiler artifacts include the blocks/codes switch tables and same-source alignment; W6 alone records inter-file NOP spans `0x00418a09-0x00418a10`, `0x00419214-0x00419220`, `0x0041994e-0x00419950`, and `0x00419a82-0x00419a90`.
- Build evidence: `SLOW`, `PKZIP_BUG_WORKAROUND`, `BUILDFIXED`, and `DEBUG` were not defined; the compiled `inffixed.h` branch supports `STDC`. Optimized `inflate_trees_fixed` still has the stock five-argument prototype even though its unused stream argument is not read.
- Stock `infblock.c` functions `inflate_set_dictionary` and `inflate_blocks_sync_point` were not emitted, consistent with unreferenced-function elimination. Exact compiler/linker switch spelling is not claimed.
- Source SHA256s: `infblock.c` `282797DEE3077D40CBE492428C2EAB75B04B496B854B180B3E85140F8AD58394`; `infcodes.c` `524E1F47AD64638CD2FD6DD163A8290B313F4D65968E20BD4E05860E1C4D0A4B`; `inftrees.c` `43AC236F9A64E933EC06E5BDE627E9BB2BDA553F6DB4B605ECFF6862347CBF84`; `infutil.c` `A098F985BDAADDFB9AEE665F2DCEB1CD6BB07CE997C19908F96B9D13984EEB29`; `inffast.c` `1043E4300E9A81E7897EBAC507F4CBD75BDCDABD0A77410538404D5076F151F9`.
- B009's 2026-06-27 libjpeg/zlib split reclassifies the old `0x00631850-0x0063211c` zlib claim as IJG libjpeg data in [UID:000489][0x00631850-0x0063211c.LibJpeg6bReadOnlyTables](by-memory/0x00631850-0x0063211c.LibJpeg6bReadOnlyTables.md). zlib read-only data begins at `0x0063211c` with `crc32.c` `crc_table[256]`.
- IDA callers show `Uncompress` and `Crc32` are consumed by metadata/resource/image paths, including [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md); those are product callers, not owners.

## Ownership Decision

Keep the zlib family as third-party support code. `MetaTable`, palette, image, startup-logo, DAT, screenshot, and render modules consume `Uncompress`, `Crc32`, or `Adler32`; they do not own these helpers.

Do not split `Crc32`, `Adler32`, `InflateFast`, and the inflate/deflate state machines across caller modules during reconstruction. Do not use decompiler-generated one-function files as final source shape.

## Reconstruction / C++ Policy

The by-file root emits under `NexusTK/third_party/zlib/`. [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md) and [UID:0000W6][0x00417ba0-0x00419e56.ZlibInflateInternals](by-memory/0x00417ba0-0x00419e56.ZlibInflateInternals.md) are `RECONSTRUCTABLE:FALSE` non-emitting indexes with blank formal blocks. Mixed pages such as [UID:0000W2][0x004142c0-0x00414565.ZlibPublicCompressChecksum](by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md) and [UID:0000W5][0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler](by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md) remain blank until exact source-file splits exist. Exact source children [UID:0000W4][0x00414820-0x004158aa.ZlibDeflateWorkers](by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md), [UID:0004IK][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md), and UID0004IF-UID0004IJ use validator inline imports with required `third_party_embeds/zlib/...` paths. Exact data child [UID:0004IL][0x00632560-0x006325d8.ZlibDeflateConfigurationTable](by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md) is reconstructable and routed but uses the formal `// Emitted source for this range is covered by [UID:0000W4][0x00414820-0x004158aa.ZlibDeflateWorkers](by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md).` block, preventing a duplicate `deflate.c` import. UID0003P7 follows the same pattern with a covered-by-UID0004IH marker, so the sole `inftrees.c` import supplies its external copyright object and all four local tables exactly once. Never flatten mixed ranges, duplicate a stock translation-unit import, add by-file reconstruction metadata, or paste decompiler-derived source.

## Open Questions

- Exact command-line compiler/linker options remain unproven, but source-affecting macro evidence now establishes non-`SLOW`, non-`PKZIP_BUG_WORKAROUND`, non-`BUILDFIXED`, non-`DEBUG`, and supports `STDC`.
- Original symbol names are unavailable; helper names are inferred from stock zlib source and current binary behavior.
- No current evidence requires a flattened or patched copy. Prefer stock multi-file zlib unless later binary comparison contradicts it.

## Related Documentation

- [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md)
- [UID:0000W2][0x004142c0-0x00414565.ZlibPublicCompressChecksum](by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md)
- [UID:0000W4][0x00414820-0x004158aa.ZlibDeflateWorkers](by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md)
- [UID:0000W5][0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler](by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md)
- [UID:0004IK][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md)
- [UID:0000W6][0x00417ba0-0x00419e56.ZlibInflateInternals](by-memory/0x00417ba0-0x00419e56.ZlibInflateInternals.md)
- [UID:0003OJ][0x0063211c-0x00632560.Zlib114CrcAndDeflateString](by-memory/0x0063211c-0x00632560.Zlib114CrcAndDeflateString.md)
- [UID:0004IL][0x00632560-0x006325d8.ZlibDeflateConfigurationTable](by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md)
- [UID:0003P7][0x00633050-0x00633080.ZlibInflateVersionString](by-memory/0x00633050-0x00633080.ZlibInflateVersionString.md)
- [UID:0001QE][client_libraries](by-meta/client_libraries.md)
- [UID:0001QX][README](by-meta/obtained_thirdparty_files/README.md)
- [UID:0004IF][0x00417ba0-0x00418a09.ZlibInfBlock](by-memory/0x00417ba0-0x00418a09.ZlibInfBlock.md)
- [UID:0004IG][0x00418a10-0x00419214.ZlibInfCodes](by-memory/0x00418a10-0x00419214.ZlibInfCodes.md)
- [UID:0004IH][0x00419220-0x0041994e.ZlibInfTrees](by-memory/0x00419220-0x0041994e.ZlibInfTrees.md)
- [UID:0004II][0x00419950-0x00419a82.ZlibInfUtilFlush](by-memory/0x00419950-0x00419a82.ZlibInfUtilFlush.md)
- [UID:0004IJ][0x00419a90-0x00419e56.ZlibInfFast](by-memory/0x00419a90-0x00419e56.ZlibInfFast.md)
- [UID:00028E][0x00671a74-0x00672eb4.Zlib114DataMessagesAndTables](by-memory/0x00671a74-0x00672eb4.Zlib114DataMessagesAndTables.md)

## Changes

- 2026-07-20 B002 UID0003P7 callback:
  - Preserved `92/90`, file ownership, `NexusTK/third_party/zlib/`, all unrelated source splits, and the by-file prose-only contract.
  - Added the exact `border[19]`, `inflate_copyright[]`, NUL/alignment, four `inftrees.c` arrays, live reads, runtime-resume boundary, and covered-by/sole-import source route.

- 2026-07-12 B003 duplicate-UID/source-emission repair:
  - Score, canonical owner, and proposed output path unchanged.
  - Summary/evidence: canonical MIDI UIDs 00041N/00041O remain on their MIDI pages. Fresh [UID:0004IK][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md) now owns the exact Zlib `trees.c` path/import; fresh [UID:0004IL][0x00632560-0x006325d8.ZlibDeflateConfigurationTable](by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md) owns the exact `configuration_table[10]` data range and uses a covered-by-UID0000W4 formal block. Updated source/content/reconstruction tables so generated Zlib output has one `trees.c` import and one `deflate.c` import, with no MIDI-path source associations.

- 2026-07-12 B003 UID0000W6 five-source import split:
  - Score, canonical file owner, and proposed reconstruction path unchanged at `92/90`, `FILE`, and `NexusTK/third_party/zlib/`.
  - Summary/evidence: replaced stale aggregate/mixed W6 source-state wording with exact child emitters [UID:0004IF][0x00417ba0-0x00418a09.ZlibInfBlock](by-memory/0x00417ba0-0x00418a09.ZlibInfBlock.md) through [UID:0004IJ][0x00419a90-0x00419e56.ZlibInfFast](by-memory/0x00419a90-0x00419e56.ZlibInfFast.md). Corrected `infblock.c` through `inflate_blocks_free` at `0x00418a09`, retained `infcodes.c` through `inflate_codes_free` at `0x00419214`, separated `inftrees.c`, `infutil.c`, and `inffast.c`, and recorded child-owned switch tables, parent-only inter-file pads, prototypes/linkage, macro findings, optimized fixed tables, discarded-function evidence, hashes, and managed-import policy.

- 2026-06-27 B009 libjpeg/zlib read-only split:
  - Score unchanged.
  - Summary/evidence: [UID:0003OJ][0x0063211c-0x00632560.Zlib114CrcAndDeflateString](by-memory/0x0063211c-0x00632560.Zlib114CrcAndDeflateString.md) is now zlib-only CRC/string data. The previous `0x00631850-0x0063211c` zlib deflate/tree constants claim is superseded by [UID:000489][0x00631850-0x0063211c.LibJpeg6bReadOnlyTables](by-memory/0x00631850-0x0063211c.LibJpeg6bReadOnlyTables.md), so zlib starts at `0x0063211c`.

- 2026-06-27 B001 third-party import-directive callback:
  - Score unchanged.
  - Historical summary/evidence: converted exact source-bearing zlib pages UID0000W4, the page now registered as [UID:0004IK][0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers](by-memory/0x00416010-0x00417b97.ZlibDeflateTreeOutputHelpers.md), and the page now registered as [UID:0004IL][0x00632560-0x006325d8.ZlibDeflateConfigurationTable](by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md) from legacy marker/no-code wording to formal validator directives. The UID0004IL full `deflate.c` import was later superseded by the 2026-07-12 covered-by-UID0000W4 repair because UID0000W4 already imports that translation unit.

- 2026-06-26 B008 implementation callback:
  - Score unchanged.
  - Summary/evidence: synced owner-page policy with accepted [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md) classification as a non-emitting parent/index. Stock source files under `NexusTK/third_party/zlib/` remain the source of record; W3 and mixed child pages stay blank, while exact source-file children now use validator inline import directives when converted.
- 2026-06-26 B011 [UID:0000W5][0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler](by-memory/0x004158b0-0x0041600e.ZlibInflateApiAllocatorAndAdler.md) support sync:
  - Score unchanged.
  - Summary/evidence: recorded that W5 is a mixed page covering `inflate.c` reset/init/run code and the `0x00415e78-0x00415eb0` `inflate` switch jump table, `zutil.c` default allocator/free callbacks, and `adler32.c`; W5 therefore keeps a blank formal C++ block unless exact source-file children are split.
- 2026-06-26 B007 [UID:0000W2][0x004142c0-0x00414565.ZlibPublicCompressChecksum](by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md) support sync:
  - Score unchanged.
  - Summary/evidence: added the mixed-page versus exact-child policy for broad or mixed zlib by-memory pages. [UID:0000W2][0x004142c0-0x00414565.ZlibPublicCompressChecksum](by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md) and [UID:0000W3][0x004142c0-0x00419e56.ZlibCore](by-memory/0x004142c0-0x00419e56.ZlibCore.md) stay blank, while exact source-file children may use validator inline import directives after a clean split.
- 2026-06-23 B002 Rule 26 implementation:
  - Updated source split after [0x00414820-0x004158aa.ZlibDeflateWorkers](by-memory/0x00414820-0x004158aa.ZlibDeflateWorkers.md) was narrowed to `0x00414820-0x004158aa.ZlibDeflateWorkers` and a separate `trees.c` child was created at `0x00416010-0x00417b97`.
  - Added generated `Zlib.cpp` caveat: generated empty-marker output is not the preferred source layout.
  - Added `configuration_table[10]` carve-out at `0x00632560-0x006325d8`.
- 2026-06-21 B006 ImageLoaders `Uncompress` consumer:
  - Score unchanged.
  - Summary/evidence: added [UID:0002TJ][0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext](by-memory/0x004d05f0-0x004d0723.DecodeZpfFpfToTileContext.md) as a concrete product consumer of public zlib `Uncompress`. The consumer remains `ImageLoaders.cpp`; this page only records the third-party library boundary and exact call context.
