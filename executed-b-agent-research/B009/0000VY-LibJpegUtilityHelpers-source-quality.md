** TARGET-REPORT-UID:0000VY **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000VY] LibJpegUtilityHelpers Source-Quality Report

Report-only assignment: `B009-rework-0000VY-libjpeg-utility-helpers-source-quality-20260626`

Agent: B009

Target: `by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md`

Target owner: [UID:0000KN] `by-file/LibJPEG.md`

Research timestamp: 2026-06-27 01:35 -04:00

## Executive Recommendation

[UID:0000VY] is correctly classified as IJG libjpeg 6b utility helper code from `jutils.c`. Current IDA MCP evidence, staged-source comparison, boundaries, caller fanout, and helper semantics all support keeping:

- `CANONICAL_OWNER:0000KN`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KN`
- blank `EMITTER_POSITION_OPTIONAL`

Recommended target score after implementation is `COMPLETION:90` and `CONFIDENCE:92`.

Do not insert a formal `RECONSTRUCTION_CPP CODE` marker in [UID:0000VY]. The page is an exact code-helper slice, while the same upstream source file also emits `jpeg_natural_order` at `0x00631c14-0x00631d54` in `.rdata`. Under the page-local memory-range rule, a full-source `// Static embed: third_party_embeds/libjpeg/jutils.c` marker on the code-only page would still overclaim bytes outside the target range. The correct [UID:0000VY] implementation is a no-code proof with the owner/emitter kept on [UID:0000KN].

The rejected current-scope blocker is now resolved in this report. The current [UID:0003OJ] range must be split/reclassified as:

- New libjpeg-owned data child: `0x00631850-0x0063211c`, suggested path `by-memory/0x00631850-0x0063211c.LibJpeg6bReadOnlyTables.md`, owner/emitter [UID:0000KN].
- Existing [UID:0003OJ] zlib child after rename/rerange: `0x0063211c-0x00632560`, suggested path `by-memory/0x0063211c-0x00632560.Zlib114CrcAndDeflateString.md`, owner/emitter [UID:0000PC].

The boundary is exact: `0x00631d54+` adjacent data remains libjpeg through the DCT floating constant pool ending at `0x0063211c`; zlib begins at the CRC table at `0x0063211c`. No target/support by-* docs were edited during this report-only rework.

## Current State

Live target header state:

- `UID:0000VY`
- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000KN`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KN`
- `EMITTER_POSITION_OPTIONAL:` blank
- `RECONSTRUCTION_CPP CODE:` blank
- `Nested:0`

Generated state is stale and must not be edited manually:

- `auto-generated/-ag-coverage-report-by-memory.md` still lists [UID:0000VY] as `80%`/`strong`, `emits_code:false`, updated `2026-06-23 21:41:13`.
- `auto-generated/-ag-research-tracker.md` still lists [UID:0000VY] as `80/85`.
- `auto-generated/NexusTK/third_party/libjpeg/LibJPEG.cpp` still contains an empty emitter marker for [UID:0000VY].

These generated files should refresh through validator/report execution after implementation. They are not implementation inputs for this report-only pass.

## Evidence Checked

Primary target and owner documents:

- `by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md`
- `by-file/LibJPEG.md`
- `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`

Neighbor and comparator documents:

- `by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md`
- `by-memory/0x004064a0-0x00406d8c.LibJpegMarkerWriter.md`
- `by-memory/0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md`
- `by-memory/0x004049c0-0x00404a5c.LibJpegCommonApi.md`

Support and meta documents:

- `by-meta/client_libraries.md`
- `by-project-structure/proposed-source-tree.md`
- `by-meta/obtained_thirdparty_files/static_embeds/README.md`
- `by-memory/0x00631660-0x00631850.LibJpeg6bMessagePointerTable.md`
- `by-memory/0x00631850-0x00632560.Zlib114ReadOnlyConstantsAndStrings.md`

Executed reports checked as precedent:

- `executed-b-agent-research/B009/0000VT-LibJpegCompressRawDataApi-source-quality.md`
- `executed-b-agent-research/B007/0000VQ-LibJpegDecompressApiFrontEnd-source-quality.md`

Staged source checked:

- `third_party_embeds/libjpeg/jutils.c`
- `third_party_embeds/libjpeg/jcparam.c`
- `third_party_embeds/libjpeg/jmemmgr.c`
- `third_party_embeds/libjpeg/jdhuff.c`
- `third_party_embeds/libjpeg/jdphuff.c`
- `third_party_embeds/libjpeg/jddctmgr.c`
- `third_party_embeds/libjpeg/jcdctmgr.c`
- `third_party_embeds/libjpeg/jquant1.c`
- `third_party_embeds/libjpeg/jfdctflt.c`
- `third_party_embeds/libjpeg/jidctflt.c`
- `by-meta/obtained_thirdparty_files/static_embeds/libjpeg-6b/jutils.c`
- `third_party_embeds/libjpeg/jpeglib.h`
- `third_party_embeds/libjpeg/jpegint.h`
- `third_party_embeds/zlib/crc32.c`
- `third_party_embeds/zlib/deflate.c`

## MCP Session Facts

IDA MCP was available. No fallback-only work was finalized.

Read-only availability and session facts:

- TCP listener check at `2026-06-26T22:08:36-04:00`: `127.0.0.1:13337` was reachable.
- `initialize` id `b009-0000vy-init-20260626T2209`: server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- `idb_list` id `b009-0000vy-idb-list-20260626T2210`: active session `80de0a67`, `NexusTK.exe.i64`, `is_analyzing:false`, worker PID `26892`.
- `server_health` id `b009-0000vy-health-20260626T2211`: ok, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`.
- Rework `initialize` id `b009-0000vy-rework-init-20260627T0001`: server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`.
- Rework `idb_list` id `b009-0000vy-rework-idblist-20260627T0001`: same active session `80de0a67`, `NexusTK.exe.i64`, `is_analyzing:false`.
- Rework `server_health` id `b009-0000vy-rework-health-db-20260627T0004`: ok, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, string cache ready.

Tool schema note:

- Current `tools/list` id `b009-0000vy-tools-20260626T2209` shows most tools require `database`.
- `decompile` accepts single `addr`.
- `lookup_funcs` uses `queries`.
- `xrefs_to` and `callees` use `addrs`.
- `get_bytes` uses `regions`.

Broad source-comment text searches for `jpeg_natural_order`/`jZAG` timed out:

- `b009-0000vy-search-natural-sourcecomments-20260626T2228`
- `b009-0000vy-search-zag-20260626T2229`

Those were broad-search timeouts, not MCP unavailability. `server_health` id `b009-0000vy-health-after-search-timeout-20260626T2232` immediately returned ok with Hex-Rays and the string cache ready.

## Function Inventory

Current IDA function inventory in `0x004063c0-0x004064b0` contains the five [UID:0000VY] functions and the successor marker-writer function:

| Address | IDA name | Size | Source mapping | Source line |
| --- | --- | ---: | --- | ---: |
| `0x004063d0` | `sub_4063D0` | `0x10` / 16 | `jdiv_round_up` | `jutils.c:72` |
| `0x004063e0` | `sub_4063E0` | `0x18` / 24 | `jround_up` | `jutils.c:81` |
| `0x00406400` | `sub_406400` | `0x46` / 70 | `jcopy_sample_rows` | `jutils.c:111` |
| `0x00406450` | `sub_406450` | `0x22` / 34 | `jcopy_block_row` | `jutils.c:145` |
| `0x00406480` | `sub_406480` | `0x1b` / 27 | `jzero_far` | `jutils.c:165` |
| `0x004064a0` | `sub_4064A0` | `0x51` | successor `jcmarker.c` code | outside target |

MCP facts:

- `lookup_funcs` id `b009-0000vy-lookup-20260626T2213` confirms `0x004063c8` and `0x0040649b` are not function starts.
- Source names `jdiv_round_up`, `jround_up`, `jcopy_sample_rows`, `jcopy_block_row`, and `jzero_far` are not present as IDA symbol names. The mapping is from source/body equivalence, not from preserved names.
- `entity_query` id `b009-0000vy-entity-functions-20260626T2214` confirms all five target functions are in `.text` and have types.
- `int_convert` id `b009-0000vy-int-convert2-20260626T2221` verifies `0xcb` = 203, the exact half-open target length from `0x004063d0` to `0x0040649b`.

## Function Semantics

MCP `analyze_function` evidence:

- `b009-0000vy-analyze-63d0-20260626T2220`: `0x004063d0` returns `(a1 + a2 - 1) / a2` using `cdq`/`idiv`. This matches IJG `jdiv_round_up(long a, long b)`.
- `b009-0000vy-analyze-63e0-20260626T2220`: `0x004063e0` returns `a + b - 1 - ((a + b - 1) % b)`. This matches IJG `jround_up(long a, long b)`.
- `b009-0000vy-analyze-6400-20260626T2220`: `0x00406400` computes input/output sample-row pointers and copies `num_cols` bytes per row with inline `movsd`/`movsb`, matching `jcopy_sample_rows`.
- `b009-0000vy-analyze-6450-20260626T2220`: `0x00406450` shifts `num_blocks` by 7 and copies that many bytes with inline `movsd`/`movsb`, matching `jcopy_block_row` where `DCTSIZE2 * sizeof(JCOEF) = 64 * 2 = 128`.
- `b009-0000vy-analyze-6480-20260626T2220`: `0x00406480` zero-fills with `stosd`/`stosb`, matching `jzero_far`.

Negative callee evidence:

- `callees` id `b009-0000vy-callees-20260626T2216` reports no modeled direct callees for the five target helpers.
- The copy/zero helpers compile as inline `rep movs*`/`stos*` sequences instead of calls to `memcpy`/`memset`.

## Caller Evidence

MCP `xrefs_to` id `b009-0000vy-xrefs-20260626T2215` reports the following target call fanout:

| Target | Code xrefs | Calling functions |
| --- | ---: | --- |
| `0x004063d0` / `jdiv_round_up` | 22 | `sub_404AF0`, `sub_404E30`, `sub_405C80`, `sub_411A20`, `sub_412240` |
| `0x004063e0` / `jround_up` | 6 | `sub_4075C0`, `sub_40A0D0`, `sub_40A440`, `sub_40DA00` |
| `0x00406400` / `jcopy_sample_rows` | 7 | `sub_40A780`, `sub_40A900`, `sub_40B010`, `sub_40B3A0`, `sub_410470`, `sub_4104B0`, `sub_410B60` |
| `0x00406450` / `jcopy_block_row` | 1 | `sub_407EF0` |
| `0x00406480` / `jzero_far` | 12 | `sub_405760`, `sub_405950`, `sub_4077A0`, `sub_40B9F0`, `sub_40D0D0`, `sub_40D410`, `sub_40D670`, `sub_40DBD0`, `sub_40DE30` |

This fanout matches IJG utility helpers shared across compression, decompression, entropy, memory, and coefficient paths. No evidence supports product-specific ownership.

## Boundary Evidence

MCP `get_bytes` id `b009-0000vy-bytes-boundaries-20260626T2217` verifies exact target boundaries:

- Previous function tail ends with `5e c3` at `0x004063c7`.
- `0x004063c8-0x004063cf` is NOP padding before [UID:0000VY].
- `0x004063d0-0x004063df` is `jdiv_round_up`.
- `0x004063e0-0x004063f7` is `jround_up`.
- `0x004063f8-0x004063ff` is NOP padding.
- `0x00406400-0x00406445` is `jcopy_sample_rows`.
- `0x00406446-0x0040644f` is NOP padding.
- `0x00406450-0x00406471` is `jcopy_block_row`.
- `0x00406472-0x0040647f` is NOP padding.
- `0x00406480-0x0040649a` is `jzero_far`.
- `0x0040649b-0x0040649f` is NOP padding.
- `0x004064a0` starts successor `sub_4064A0`, documented by neighbor [UID:0000VZ].

The current half-open target range `0x004063d0-0x0040649b` includes the five functions and excludes the terminal alignment padding. That is consistent with the existing by-memory page and the parent [UID:0000VP] child map.

## Staged Source Provenance

The staged source files are present and byte-identical across the project embed and obtained-source mirror:

- `third_party_embeds/libjpeg/jutils.c`
- `by-meta/obtained_thirdparty_files/static_embeds/libjpeg-6b/jutils.c`

SHA256 for both copies:

```text
2CAB735C6EA1BCA55F4C94A72C73035A0A161378403A6BD849B350DF71DB92D6
```

Relevant source anchors:

- `jutils.c:40` and `jutils.c:53`: `jpeg_natural_order` comment/table.
- `jutils.c:72`: `jdiv_round_up`.
- `jutils.c:81`: `jround_up`.
- `jutils.c:111`: `jcopy_sample_rows`.
- `jutils.c:145`: `jcopy_block_row`.
- `jutils.c:165`: `jzero_far`.
- `jpeglib.h`: `DCTSIZE2` is 64.
- `jpegint.h`: maps `jpeg_natural_order` to `jZAGTable` in this source snapshot.

The code-helper evidence is exact stock IJG libjpeg 6b source, not a decompiler-derived reconstruction.

## Reworked Read-Only Data Audit

`jutils.c` is not represented only by the five helper functions in [UID:0000VY]. It also contains the compiled `jpeg_natural_order[DCTSIZE2 + 16]` table. The supervisor's named blocker was whether `0x00631d54+` is also libjpeg or whether [UID:0003OJ] can remain zlib from that point onward. Live IDA MCP evidence says the adjacent data remains libjpeg until `0x0063211c`.

The exact split for current [UID:0003OJ] is:

| Range | Correct owner | Contents |
| --- | --- | --- |
| `0x00631850-0x0063211c` | [UID:0000KN] LibJPEG | IJG libjpeg 6b read-only table/constant island. |
| `0x0063211c-0x00632560` | [UID:0000PC] Zlib | zlib 1.1.4 CRC table, deflate copyright string, and local alignment. |

Detailed libjpeg map for `0x00631850-0x0063211c`:

| Range | Source | Contents and evidence |
| --- | --- | --- |
| `0x00631850-0x00631854` | linker alignment | Four zero bytes immediately after [UID:0003OI]; no xrefs. Keep with the libjpeg table island. |
| `0x00631854-0x00631954` | `jcparam.c:76` | `std_luminance_quant_tbl[64]`; xref from `sub_403ED0` at `0x403ee1`. |
| `0x00631954-0x00631a54` | `jcparam.c:86` | `std_chrominance_quant_tbl[64]`; xref from `sub_403ED0` at `0x403ef0`. |
| `0x00631a54-0x00631c04` | `jcparam.c:186-223` | Standard DC/AC Huffman bits/value arrays for luminance and chrominance; xrefs from `sub_404070` to `0x00631a54`, `0x00631a68`, `0x00631a94`, `0x00631aa8`, `0x00631a74`, `0x00631a88`, `0x00631b4c`, and `0x00631b60`. |
| `0x00631c04-0x00631c14` | `jmemmgr.c:241` and `jmemmgr.c:247` | `first_pool_slop[2] = {1600, 16000}` and `extra_pool_slop[2] = {0, 5000}`; xrefs from `sub_4051A0`. |
| `0x00631c14-0x00631d54` | `jutils.c:53` | `jpeg_natural_order[DCTSIZE2+16]`; 80 int32 values, length `0x140`, xrefs from libjpeg entropy/marker/DCT paths. |
| `0x00631d54-0x00631dd4` | `jdhuff.c:449` and `jdhuff.c:453` | Baseline Huffman `extend_test[16]` and `extend_offset[16]`; xrefs from `sub_408BF0`. |
| `0x00631dd4-0x00631e54` | `jdphuff.c:209` and `jdphuff.c:213` | Progressive Huffman `extend_test[16]` and `extend_offset[16]`; xrefs from `sub_4093A0` and `sub_409660`. |
| `0x00631e54-0x00631e58` | linker alignment | Four zero bytes before the DCT-manager tables. |
| `0x00631e58-0x00631ed8` | `jddctmgr.c:185` | Inverse-DCT `aanscales[DCTSIZE2]`; xref from `sub_409E90` at `0x40a02a`. |
| `0x00631ed8-0x00631f18` | `jddctmgr.c:217` | Inverse-DCT `aanscalefactor[DCTSIZE]`; xrefs and end compare in `sub_409E90`. |
| `0x00631f18-0x00632018` | `jquant1.c:79` | `base_dither_matrix[16][16]`; xref from `sub_40D220` at `0x40d247`, end compare to `0x00632018`. |
| `0x00632018-0x00632024` | `jquant1.c:196` | `RGB_order[3] = { RGB_GREEN, RGB_RED, RGB_BLUE }`; xref from `sub_40CE20` at `0x40ce9b`; also the end sentinel for the dither matrix in `sub_40D220`. |
| `0x00632024-0x00632028` | linker alignment | Four zero bytes before the compression DCT-manager tables. |
| `0x00632028-0x006320a8` | `jcdctmgr.c:99` | Compression-DCT `aanscales[DCTSIZE2]`; xref from `sub_40FCC0` at `0x40fdf1`. |
| `0x006320a8-0x006320e8` | `jcdctmgr.c:140` | Compression-DCT `aanscalefactor[DCTSIZE]`; xrefs and end compare in `sub_40FCC0`. |
| `0x006320e8-0x0063211c` | `jcdctmgr.c`, `jfdctflt.c`, `jidctflt.c` | Pooled floating DCT constants: `1.0`, `8.0`, `16384.5`, `1.082392200`, `2.613125930`, `1.847759065`, `1.414213562`, `1.306562965`, `0.541196100`, `0.382683433`, and `0.707106781`; xrefs from libjpeg `sub_40FCC0`, `sub_412F70`, and `sub_414020`. |

Detailed zlib map for the retained [UID:0003OJ] range after rerange:

| Range | Source | Contents and evidence |
| --- | --- | --- |
| `0x0063211c-0x0063251c` | `crc32.c:68` | zlib `crc_table[256]`; nine xrefs from `sub_414430`, the documented zlib CRC helper. |
| `0x0063251c-0x00632520` | linker alignment | Four zero bytes before the deflate copyright string. |
| `0x00632520-0x00632558` | `deflate.c:55` | ` deflate 1.1.4 Copyright 1995-2002 Jean-loup Gailly `; xref from `sub_414C30`. |
| `0x00632558-0x00632560` | linker alignment | Eight zero bytes before [UID:00041O] `configuration_table[10]` at `0x00632560`. |

MCP rework evidence for the split:

- `xrefs_to` id `b009-0000vy-rework-xrefs-front-libjpeg-20260627T0013` proves the front of the contested range is `jcparam.c` and `jmemmgr.c`, not zlib.
- `decompile` evidence for `sub_403ED0`, `sub_404070`, and `sub_4051A0` shows those code paths use the standard quantization, Huffman, and pool-slop arrays listed above.
- `xrefs_to` id `b009-0000vy-rework-xrefs-candidates-20260627T0008` proves `0x00631c14`, `0x00631d54`, `0x00631d94`, `0x00631dd4`, and `0x00631e14` are libjpeg entropy table consumers.
- `decompile` evidence for `sub_408BF0` and `sub_409660` matches `jdhuff.c`/`jdphuff.c` `HUFF_EXTEND` and `jpeg_natural_order` use.
- `xrefs_to` ids `b009-0000vy-rework-xrefs-dct-quant-20260627T0030`, `b009-0000vy-rework-xrefs-corrected-mid-20260627T0037`, and `b009-0000vy-rework-xrefs-tail-batch-20260627T0105` prove the DCT/quantizer ranges through `0x00632118` are libjpeg consumers.
- `decompile` id `b009-0000vy-rework-decomp-40fcc0-20260627T0118` proves `0x00632028-0x006320e8` are `jcdctmgr.c` AAN tables/factors and `0x006320e8-0x006320f8` includes the `1.0`/`8.0` constants used in the float divisor formula.
- `decompile` id `b009-0000vy-rework-decomp-412f70-20260627T0118` proves the pooled inverse-DCT float constants at `0x00632104+` are libjpeg `jidctflt.c` consumers.
- `decompile` id `b009-0000vy-rework-decomp-414020-20260627T0105` proves `0x00632114-0x0063211c` are still libjpeg forward-DCT float constants, not zlib.
- `decompile` id `b009-0000vy-rework-decomp-414430-20260627T0105` proves zlib CRC table access starts at `dword_63211C`.
- `xrefs_to` id `b009-0000vy-rework-xrefs-tail-batch-20260627T0105` reports `0x0063211c` has nine xrefs from `sub_414430`, while `0x00632118` has xrefs only from libjpeg `sub_414020`.

Conclusion: [UID:0003OJ]'s current statement that `0x00631850-0x0063211c` is zlib deflate/tree numeric constants is wrong. Only `0x0063211c-0x00632560` is zlib in this page's current address span.

## Positive Evidence

- The five target functions exactly match the IJG libjpeg 6b `jutils.c` helper implementations.
- The staged source has an exact hash match between `third_party_embeds/libjpeg` and the obtained-source mirror.
- The target range starts after previous-function alignment and ends before successor alignment.
- Current caller fanout is broad libjpeg internal utility use.
- The helpers have no product-specific strings, imports, virtual dispatch, Browser/OLE ties, or NexusTK product call pattern.
- Parent [UID:0000VP] is already a non-emitting libjpeg split/index page, and [UID:0000KN] is already the libjpeg file owner/emitter.
- Existing LibJPEG source-bearing comparator pages use the same static-embed source-root model.
- The previously un-audited `0x00631d54+` adjacent data is now proved libjpeg through `0x0063211c`, which gives an exact [UID:0003OJ] split boundary.

## Negative Evidence

- IDA does not preserve source function names for these helpers.
- The formal target `RECONSTRUCTION_CPP CODE` block is blank.
- Generated reports still show stale `80/85`-era state.
- The full upstream `jutils.c` source file includes `jpeg_natural_order`, which is outside the target helper-code range and should be represented in the separate libjpeg `.rdata` table child.
- Current [UID:0003OJ] documentation is overbroad: it assigns `0x00631850-0x0063211c` to zlib even though that interval is libjpeg.

None of the negative evidence weakens the helper-code mapping. It blocks only a too-broad full-source-file marker on the current target page and requires the [UID:0003OJ] support split described above.

## Inference

The correct interpretation is:

- [UID:0000VY] owns the contiguous `.text` helper-code slice of IJG `jutils.c`.
- [UID:0000KN] remains the canonical source owner and emitter for bundled libjpeg.
- The parent libjpeg page [UID:0000VP] remains non-emitting.
- A separate libjpeg read-only data child should own `0x00631850-0x0063211c`, including the `jutils.c` table and the adjacent libjpeg tables/constants.
- Existing [UID:0003OJ] should be reranged/renamed to zlib-only `0x0063211c-0x00632560`.

The page is source-quality strong enough for a score bump, but still not safe for a full `jutils.c` static-embed marker in the page-local C++ block because the page's own address range is code-only.

## Ranked Ownership And Source Placement

1. [UID:0000KN] `LibJPEG` owner/emitter for IJG libjpeg 6b static embed.
   - This is the correct owner. The helper bodies, staged source, source-root policy, and caller graph all match bundled libjpeg.

2. [UID:0000VP] `LibJpeg6bCore` parent split/index.
   - Correct parent context, but not an emitting owner. It should continue to summarize and link child source slices.

3. New libjpeg read-only data child for `0x00631850-0x0063211c`.
   - Needed to fix [UID:0003OJ]'s overbroad zlib claim and to represent the full libjpeg `.rdata` table/constant island adjacent to [UID:0003OI].
   - Suggested path: `by-memory/0x00631850-0x0063211c.LibJpeg6bReadOnlyTables.md`.
   - Suggested metadata: new UID, `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000KN`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KN`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.

4. [UID:0003OJ] reranged zlib read-only child for `0x0063211c-0x00632560`.
   - Correct for the CRC table, deflate string, and alignment only after the libjpeg child is carved out.
   - Suggested path: `by-memory/0x0063211c-0x00632560.Zlib114CrcAndDeflateString.md`.
   - Suggested metadata: keep UID `0003OJ`, `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000PC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000PC`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.

5. NexusTK product code, Browser/OLE data, MSVC runtime, or no-owner placement.
   - Rejected. No live bytes, xrefs, source, or local documentation support these alternatives for the five helpers or the contested read-only table span.

## C++ Readiness And No-Code Proof

[UID:0000VY] remains reconstructable and emitter-owned by [UID:0000KN], but the formal C++ block should stay blank during immediate implementation.

Reason:

- The project policy favors static-embed marker comments for exact stock third-party source-file slices.
- The helper-code range is exact for the five `jutils.c` functions, but it is not the complete compiled footprint of `jutils.c`.
- The same source file also emits `jpeg_natural_order` at `0x00631c14-0x00631d54`, outside this target range.
- The support split now has an exact repair plan, but the page-local range rule still means [UID:0000VY] should not carry a full-source marker that implies ownership of out-of-range `.rdata`.

No decompiler C++ should be pasted. No copied upstream C body should be pasted. The staged source is already available and should remain the authoritative source.

Recommended formal C++ disposition by page:

- [UID:0000VY] `0x004063d0-0x0040649b`: blank formal C++ with no-code proof; code-only helper slice.
- New `0x00631850-0x0063211c.LibJpeg6bReadOnlyTables.md`: blank formal C++ with no-code proof; mixed libjpeg source files plus alignment and compiler pooled constants.
- Reranged [UID:0003OJ] `0x0063211c-0x00632560.Zlib114CrcAndDeflateString.md`: blank formal C++ with no-code proof; mixed zlib `crc32.c` table and `deflate.c` string.

If a future supervisor-level policy creates a source-unit carrier for complete `jutils.c`, the marker text would be `// Static embed: third_party_embeds/libjpeg/jutils.c`, but that carrier should not be this page unless the range rule is explicitly overridden.

## Score And Metadata Recommendation

Recommended target metadata:

- `COMPLETION:90`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000KN`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KN`
- `EMITTER_POSITION_OPTIONAL:` blank
- `RECONSTRUCTION_CPP CODE:` blank

Recommended item summary:

```text
IJG libjpeg 6b jutils.c helper-code slice; MCP/source evidence proves helper semantics, caller fanout, boundaries, and separate libjpeg .rdata placement for jpeg_natural_order.
```

Why `90/92` now:

- The helper-code evidence is exact and unchanged from the accepted portions of the first report.
- The prior named blocker is resolved: [UID:0003OJ]'s mixed range now has exact libjpeg/zlib split boundaries and implementation-ready metadata.
- The score remains below `95/95` because no formal source-file marker belongs in the page-local C++ block.

## Target Documentation Changes To Make After Approval

In `by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md`:

- Update score to `90/92`.
- Keep owner/reconstructable/emitter fields unchanged.
- Keep formal C++ blank.
- Replace stale "below full rebuild quality / below 95/95" wording with the current static-embed/no-code proof.
- Add a current MCP evidence subsection naming:
  - function inventory ids `b009-0000vy-lookup-20260626T2213` and `b009-0000vy-entity-functions-20260626T2214`
  - `analyze_function` ids for all five helpers
  - `xrefs_to` id `b009-0000vy-xrefs-20260626T2215`
  - `callees` id `b009-0000vy-callees-20260626T2216`
  - boundary bytes id `b009-0000vy-bytes-boundaries-20260626T2217`
  - int conversion id `b009-0000vy-int-convert2-20260626T2221`
- Add a source provenance subsection with the `jutils.c` SHA256 hash.
- Add a source-placement note that `jpeg_natural_order` is at `0x00631c14-0x00631d54` and belongs to the new libjpeg read-only table child, not to [UID:0003OJ] after the split.
- Add explicit no-code disposition: formal C++ remains blank because the page covers code helpers only and the full source file has material out-of-range `.rdata`.

## Support Documentation Changes To Make After Approval

In `by-file/LibJPEG.md`:

- Update the [UID:0000VY] source-file coverage row to distinguish the helper-code slice from the separate libjpeg `.rdata` table child.
- Record `jutils.c` staged hash `2CAB735C6EA1BCA55F4C94A72C73035A0A161378403A6BD849B350DF71DB92D6`.
- Add a note that `0x00631850-0x0063211c` is the libjpeg read-only table/constant island and contains `0x00631c14-0x00631d54` `jpeg_natural_order`.
- Link the new `by-memory/0x00631850-0x0063211c.LibJpeg6bReadOnlyTables.md` child after implementation.

In `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`:

- Update the child map entry for [UID:0000VY] to mention current B009 evidence and the separate `.rdata` table child.
- Add the new `0x00631850-0x0063211c` libjpeg read-only table child to the support/related map, if the parent tracks data-side libjpeg children.
- Keep [UID:0000VP] non-emitting.
- Do not add C++ to the parent.

In `by-meta/client_libraries.md`:

- Update the IJG libjpeg section with the [UID:0000VY] source-quality result.
- Mention that the helper-code range is confirmed and that the previous zlib constants range is split at `0x0063211c`.

Create `by-memory/0x00631850-0x0063211c.LibJpeg6bReadOnlyTables.md`:

- Suggested metadata: new UID assigned by normal process; `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000KN`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KN`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Suggested item summary:

```text
IJG libjpeg 6b read-only table and DCT constant island: jcparam standard quant/Huffman tables, jmemmgr pool slop, jutils natural-order table, jdhuff/jdphuff extend tables, DCT scale tables, ordered-dither/RGB-order data, and DCT floating constants.
```

Rename/rerange existing [UID:0003OJ] from `by-memory/0x00631850-0x00632560.Zlib114ReadOnlyConstantsAndStrings.md` to `by-memory/0x0063211c-0x00632560.Zlib114CrcAndDeflateString.md`:

- Keep UID `0003OJ`.
- Suggested metadata: `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000PC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000PC`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Replace the incorrect `0x00631850-0x0063211c` zlib deflate/tree claim with the zlib-only map:
  - `0x0063211c-0x0063251c`: `crc32.c` `crc_table[256]`.
  - `0x0063251c-0x00632520`: alignment.
  - `0x00632520-0x00632558`: `deflate.c` copyright/version string.
  - `0x00632558-0x00632560`: alignment before [UID:00041O].
- Suggested item summary:

```text
zlib 1.1.4 read-only CRC table and deflate copyright string; begins after the libjpeg table island at 0x0063211c and ends before configuration_table[10].
```

In `by-memory/0x00631660-0x00631850.LibJpeg6bMessagePointerTable.md`:

- Update any successor wording that says the next range is zlib constants. It now ends before the libjpeg read-only table/constant island at `0x00631850`.

In `by-file/Zlib.md` and `by-memory/0x004142c0-0x00419e56.ZlibCore.md`:

- Update the zlib read-only data link/range to [UID:0003OJ] `0x0063211c-0x00632560`.
- Do not keep the `0x00631850-0x0063211c` deflate/tree-constants claim.

In `by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md`:

- Update predecessor text/link if it still references [UID:0003OJ] as `0x00631850-0x00632560`.

In broad/adjacent support pages, if present:

- `by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md`: update child/subrange narrative so it does not treat the contested span as Browser/OLE or zlib-only.
- `by-memory/0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail.md`: update predecessor note only if it names the old [UID:0003OJ] path/range.

In `by-project-structure/proposed-source-tree.md`:

- No mandatory edit is required if the current `third_party/libjpeg/` and `third_party/zlib/` static-embed policy remains sufficient.

Generated files:

- Do not manually edit `auto-generated/-ag-coverage-report-by-memory.md`.
- Do not manually edit `auto-generated/-ag-research-tracker.md`.
- Do not manually edit `auto-generated/NexusTK/third_party/libjpeg/LibJPEG.cpp`.
- Refresh generated outputs only through the normal validator/report execution path.

## Validator Plan For Implementation Callback

No validators were run in this report-only pass because no by-* files were edited.

After approved implementation, run focused validators on changed files from the project-documentation root. Use the current validator shape:

> Executable block R001 was removed from this report and preserved verbatim in [0000VY-LibJpegUtilityHelpers-source-quality-removed.md](0000VY-LibJpegUtilityHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If broad predecessor/successor pages are edited, also validate them with the same command shape, for example:

> Executable block R002 was removed from this report and preserved verbatim in [0000VY-LibJpegUtilityHelpers-source-quality-removed.md](0000VY-LibJpegUtilityHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If generated freshness is required after accepted implementation, use the project's normal validator/report execution flow rather than manual generated edits.

## Implementation Tracking Checklist

Report rework completion:

- [x] Re-read updated `Agent-B009/goal.md` and applicable B-agent/Rule 26 workflow instructions.
- [x] Verified live IDA MCP availability on session `80de0a67`; no fallback-only work used.
- [x] Preserved valid [UID:0000VY] helper-code evidence from the original report.
- [x] Re-audited `0x00631d54+` adjacent data with live MCP xrefs/decompilation.
- [x] Determined exact split boundary: libjpeg `0x00631850-0x0063211c`, zlib `0x0063211c-0x00632560`.
- [x] Replaced stale validator plan with current `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240` commands.
- [x] Left target/support by-* docs, generated reports, and coverage reports unedited during this report-only rework.

Implementation callback checklist:

- [x] Updated [UID:0000VY] metadata to `90/92`, preserving [UID:0000KN] owner/emitter, `RECONSTRUCTABLE:TRUE`, blank emitter position, and blank formal C++. Proof: `by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md`; validator `000000003661`, `2026-06-26T23:19:46-04:00`, exit `0`, `ok: 1`.
- [x] Replaced stale [UID:0000VY] "below rebuild quality / below 95/95" wording with current MCP/source evidence. Proof: [UID:0000VY] now records MCP session/database `80de0a67`, five-helper map, caller fanout, boundary evidence, staged `jutils.c` hash, and rejected alternatives.
- [x] Added [UID:0000VY] no-code proof. Proof: [UID:0000VY] explains the formal C++ block remains blank because the page covers only helper code while the same `jutils.c` source also emits `jpeg_natural_order` at `0x00631c14-0x00631d54` in [UID:000489].
- [x] Added [UID:0000VY] function inventory, caller, callee-negative, boundary, staged-source hash, and data-placement evidence from this report. Proof: [UID:0000VY] includes the five helper ranges, representative callers `0x00404af0`, `0x00404e30`, `0x00405c80`, `0x00411a20`, `0x00412240`, no modeled IJG callee note, `0x004063c8/0x0040649b` boundaries, and SHA256 `2CAB735C6EA1BCA55F4C94A72C73035A0A161378403A6BD849B350DF71DB92D6`.
- [x] Created `by-memory/0x00631850-0x0063211c.LibJpeg6bReadOnlyTables.md` as a new [UID:0000KN]-owned libjpeg data child with blank formal C++. Proof: validator assigned [UID:000489] with command `000000003622`; final validation command `000000003671`, `2026-06-26T23:23:39-04:00`, exit `0`, `ok: 1`.
- [x] Renamed/reranged existing [UID:0003OJ] to `by-memory/0x0063211c-0x00632560.Zlib114CrcAndDeflateString.md`, preserving UID `0003OJ` and zlib owner/emitter [UID:0000PC]. Proof: final [UID:0003OJ] validation command `000000003639`, `2026-06-26T23:14:15-04:00`, exit `0`, `ok: 1`.
- [x] Removed the incorrect [UID:0003OJ] `0x00631850-0x0063211c` zlib deflate/tree claim and replaced it with the CRC/string-only zlib map. Proof: [UID:0003OJ] now lists `0x0063211c-0x0063251c` CRC table, `0x0063251c-0x00632520` alignment, `0x00632520-0x00632558` deflate copyright string, and `0x00632558-0x00632560` alignment.
- [x] Updated `by-file/LibJPEG.md` with the [UID:0000VY] helper-code result, `jutils.c` hash, and the new `0x00631850-0x0063211c` libjpeg table child. Proof: validator `000000003663`, `2026-06-26T23:19:48-04:00`, exit `0`, `ok: 1`.
- [x] Updated `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md` child-map/support notes for [UID:0000VY] and the libjpeg data child. Proof: validator `000000003664`, `2026-06-26T23:19:50-04:00`, exit `0`, `ok: 1`.
- [x] Updated `by-memory/0x00631660-0x00631850.LibJpeg6bMessagePointerTable.md` successor wording from zlib constants to the libjpeg table island. Proof: validator `000000003626`, `2026-06-26T23:12:04-04:00`, exit `0`, `ok: 1`.
- [x] Updated `by-file/Zlib.md` and `by-memory/0x004142c0-0x00419e56.ZlibCore.md` to use [UID:0003OJ]'s corrected `0x0063211c-0x00632560` range. Proof: `by-file/Zlib.md` final validator `000000003685`, `2026-06-26T23:26:58-04:00`, exit `0`, `ok: 1`; `ZlibCore` final validator `000000003687`, `2026-06-26T23:27:36-04:00`, exit `0`, `ok: 1`.
- [x] Updated `by-memory/0x00632560-0x006325d8.ZlibDeflateConfigurationTable.md` predecessor reference from [UID:0003OJ]'s old path/range to the new zlib CRC/string path. Proof: validator `000000003628`, `2026-06-26T23:12:10-04:00`, exit `0`, `ok: 1`; validator reported pre-existing `duplicate_path_conflict` for UID `00041O` in `validator.ini`, so related docs use plain `UID 00041O` text where needed to avoid validator rewriting links to the MidiPlayer path.
- [x] Updated `by-meta/client_libraries.md` with the libjpeg/zlib split and [UID:0000VY] source-quality result. Proof: final validator `000000003690`, `2026-06-26T23:31:29-04:00`, exit `0`, `ok: 1`.
- [x] Updated broad predecessor/successor support pages with stale text present. Proof: `by-memory/0x00631570-0x00632560.BrowserComGuidReadOnlyData.md` final validator `000000003640`, `2026-06-26T23:14:20-04:00`, exit `0`, `ok: 1`; `by-memory/0x00632560-0x0066d000.MsvcRuntimeReadOnlyDataTail.md` was not edited because the accepted old [UID:0003OJ] path/range was not present; extra direct stale [UID:0003P7] link was updated in `by-memory/0x00633050-0x00633080.ZlibInflateVersionString.md`, validator `000000003670`, `2026-06-26T23:22:59-04:00`, exit `0`, `ok: 1`.
- [x] Updated directly stale checksum/support reference in `by-memory/0x004142c0-0x00414565.ZlibPublicCompressChecksum.md`. Proof: validator `000000003629`, `2026-06-26T23:12:12-04:00`, exit `0`, `ok: 1`.
- [x] Do not paste decompiler C++ or upstream C bodies into [UID:0000VY], the new libjpeg data child, or the reranged zlib child. Proof: all three formal `RECONSTRUCTION_CPP` blocks remain blank and contain prose no-code proofs.
- [x] Do not manually edit generated reports, generated C++ output, project-level files, by-project-structure, tool state, or any `-coverage-report.md` file. Proof: only by-* docs and this report were manually edited; validator side effects updated `tools/validator.ini`, `project-level/-auto-completion-stats.md`, and generated refresh queues as part of required scoped validation.
- [x] Run focused validators on all changed by-* and support docs with the command shape listed above. Proof: final/accepted command IDs are `000000003661`, `000000003671`, `000000003639`, `000000003663`, `000000003664`, `000000003626`, `000000003685`, `000000003687`, `000000003628`, `000000003690`, `000000003640`, `000000003629`, and `000000003670`; all exited `0` with `ok: 1`.
- [x] Refresh generated outputs only through the normal validator/report execution path if implementation changes require it. Proof: validator output reported `generated_refresh: deferred` for scoped file validations; no manual generated refresh/edit was performed.
- [x] Release leases after edit/validator batches. Proof: final `tools/leaser/Agents/current_leases.md` check showed no active B009 leases; only unrelated B001 leases remained.

Known validator warnings during implementation:

- UID registry conflict: validator currently maps UID `00041N`/`00041O` to MidiPlayer paths in some contexts. Where this affected changed zlib docs, the implementation uses plain `UID 00041N`/`UID 00041O` text with correct backtick path references to avoid validator-inserted wrong MidiPlayer links. The exact zlib config-table page validation (`000000003628`) still reports `duplicate_path_conflict 00041O`.
- Existing stale reference diagnostics remain outside this callback's accepted edits, including `missing_ref_target 0000W4` for the old `ZlibDeflateAndTrees` path in zlib docs and `missing_ref_uid` entries such as `0003OG`/`0003OH` in Browser aggregate validation. These did not block scoped validators; all changed files exited `0`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0000VY-LibJpegUtilityHelpers-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0000VY-LibJpegUtilityHelpers-source-quality.md","timestamp":"2026-06-27T02:32:02","uid":"0000VY"} -->
<!-- {"agent":"B009","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000VY-LibJpegUtilityHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B009/0000VY-LibJpegUtilityHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000VY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
