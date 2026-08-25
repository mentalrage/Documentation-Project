** TARGET-REPORT-UID:0000VS **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
*** Assignment: B007-report-0000VS-libjpeg-compress-api-front-end-source-quality-20260626 ***
*** Target: [UID:0000VS] by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md ***
*** Mode: REPORT_ONLY ***

# [UID:0000VS] LibJpegCompressApiFrontEnd Source-Quality Report

## Report Status

Report-only research completed with current live IDA MCP evidence. I did not lease or edit target/support by-* docs, generated/project-level files, coverage reports, validator/tool state, or the IDA database.

Primary finding: [UID:0000VS] is correctly owned by [UID:0000KN] `LibJPEG`, but the current page is under-detailed and its endpoint is stale. It is a mixed third-party source-map page covering all retained `jcapimin.c`, `jdatadst.c`, and `jcparam.c`, plus only the `jcapistd.c` scanline front end before sibling [UID:0000VT] carries `jpeg_write_raw_data`. Because the current target is not an exact single source-file slice and because the `jcapistd.c` source file crosses the [UID:0000VS]/[UID:0000VT] boundary, formal C++ should remain blank under a target-specific no-code proof. Do not insert a static-embed marker or handwritten C/C++ into this by-memory page.

## Current Target State And Recommendation

Current live target metadata:

| Field | Current value |
| --- | --- |
| UID | `0000VS` |
| File | `by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md` |
| Completion / confidence | `86/89` |
| Canonical owner | `0000KN` |
| Reconstructable | `TRUE` |
| Emitter UIDs | `0000KN` |
| Formal C++ | blank |
| Item summary | `public API/source-file identity.` |
| Nested | `0` |

Recommended target metadata after accepted implementation:

| Field | Recommended value | Rationale |
| --- | --- | --- |
| `COMPLETION` | `89` | Full function/source-file mapping, raw/unmodeled helper evidence, caller/negative-xref evidence, endpoint proof, predecessor/successor boundaries, rejected alternatives, and no-code proof can be made durable. Completion stays below 90 because the page remains a mixed source-map/index rather than an exact source-file emitter. |
| `CONFIDENCE` | `92` | Live MCP, staged IJG libjpeg 6b source, source-line anchors, function inventory, decompilation/disassembly, xrefs, and product caller evidence agree. Confidence remains below final because no byte-for-byte rebuild comparison is recorded and some public APIs are retained without product xrefs. |
| `CANONICAL_OWNER` | `0000KN` | unchanged; this is statically embedded IJG libjpeg 6b code. |
| `RECONSTRUCTABLE` | `TRUE` | unchanged; third-party source should be vendored/rebuilt, but this by-memory page should not itself emit handwritten code. |
| `EMITTER_UIDS` | `0000KN` | unchanged as the third-party library owner, while formal C++ stays blank for this mixed page. |
| Formal C++ | blank | target-specific no-code proof below; no static-embed marker is range-safe for this mixed page. |

Recommended item summary:

`Mixed IJG libjpeg 6b compression source-map page: full jcapimin.c/jdatadst.c/jcparam.c plus jcapistd.c scanline prefix, with raw jcapimin.c public helpers and retained screenshot-writer caller evidence.`

Range recommendation:

- Current filename/title end `0x004048e2` is stale. Live MCP disassembly of `jpeg_write_scanlines` shows final `pop esi` at `0x004048e2`, final `retn` at `0x004048e3`, and NOP padding at `0x004048e4-0x004048f0` before sibling [UID:0000VT] starts at `0x004048f0`.
- Under the current half-open range convention used by the repaired [UID:0000VR] marker-reader page, the target should be renamed or otherwise path-repaired to `by-memory/0x00403920-0x004048e4.LibJpegCompressApiFrontEnd.md`.
- If the supervisor chooses not to perform a physical path rename in the callback, the target body still needs explicit proof that the actual body end is `0x004048e4` and that the current path suffix is a legacy/stale slug. The stronger recommendation is the validator-supported path repair.

## MCP Session And Tool Facts

IDA MCP was live and responsive during this pass. The evidence below is not fallback-only work.

| MCP fact | Evidence |
| --- | --- |
| Endpoint | `http://127.0.0.1:13337/mcp` |
| Initialize | JSON-RPC id `1` returned server `ida-pro-mcp`, version `1.0.0`, protocol `2025-06-18`. |
| Tool schema | JSON-RPC id `2` / id `9` `tools/list` confirmed read-only tools used here: `server_health`, `idb_list`, `entity_query`, `lookup_funcs`, `decompile`, `disasm`, `xrefs_to`, `callees`, and `get_bytes`. |
| Active IDB | JSON-RPC id `4` `idb_list` returned active session `80de0a67`, file `NexusTK.exe.i64`, IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, worker PID `26892`, `is_analyzing:false`, active/adopted/owned. |
| Health | JSON-RPC id `7` `server_health(database=80de0a67)` returned `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`. |
| Availability caveat | One `idb_list` probe used invalid empty-argument shape (`[]` instead of `{}`), and one helper wrapper accidentally omitted `database`. Those produced request-shape errors only; corrected calls immediately succeeded. MCP was not unavailable or busy. |

Important read-only MCP calls in this pass:

| JSON-RPC id(s) | Tool/call | Result |
| --- | --- | --- |
| `10` | `entity_query(kind=functions, min_addr=0x004038c0, max_addr=0x004049c0)` | Returned 26 modeled functions from `0x403920` through `0x4049c0`; 24 of them are in [UID:0000VS], then [UID:0000VT] at `0x4048f0`, then common API at `0x4049c0`. |
| `11` | `lookup_funcs` on target, raw starts, endpoint, and successors | Confirmed modeled starts, raw/non-function starts, `0x004048e2` and `0x004048e3` inside `sub_404820`, no function at `0x004048e4`, successor `sub_4048F0` at `0x004048f0`, and common API `sub_4049C0` at `0x004049c0`. |
| `12`-`15` | `disasm` on `0x00403a00`, `0x00403bf0`, `0x00403c70`, `0x00404820` | Confirmed raw `jcapimin.c` helper bodies, `jdatadst.c` callback install/body sequence, and `jpeg_write_scanlines` behavior/end. |
| `20`-`32` | `decompile` on `0x00403df0` through `0x00404730` | Mapped the complete `jcparam.c` family: quant-table helpers, quality scaling, defaults, color-space defaults, color-space selection, progressive scan script setup, and fill helpers. |
| `40` | `xrefs_to` on public/local API heads and product writer addresses | Confirmed product xrefs into used public APIs, internal callback/data refs, and zero-xref evidence for retained unused public APIs. |
| `41` | `callees` on `0x004efbc0` and representative libjpeg functions | Confirmed the screenshot writer's call sequence into libjpeg and representative internal callee links. |
| `42`-`45` | `lookup_funcs` / `disasm` / `decompile` on screenshot raw path and writer | Confirmed the single raw call at `0x005579d3` into `0x004efbc0` and the writer's libjpeg call sequence. |
| `46`-`49` | `disasm` / `get_bytes` around `0x004048e0-0x00404900` | Confirmed final `jpeg_write_scanlines` return at `0x004048e3`, NOP padding at `0x004048e4-0x004048f0`, and [UID:0000VT] start at `0x004048f0`. |

Local report write timestamp: `2026-06-26T20:39:32.5094148-04:00`.

## Source Inputs Checked

Current project docs checked:

- [UID:0000VS] `by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md`.
- [UID:0000VT] `by-memory/0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md`.
- [UID:0000VR] `by-memory/0x00401b00-0x0040391f.LibJpegMarkerReader.md`.
- [UID:0000VP] `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`.
- [UID:0000KN] `by-file/LibJPEG.md`.
- [UID:0001QE] `by-meta/client_libraries.md`.
- [UID:00018N] `by-memory/0x004efbc0-0x004efe94.JpegScreenshotWriter.md`.
- [UID:0001G8] `by-memory/0x00557840-0x00557a95.ScreenshotJpegCapturePath.md`.
- [UID:0000K4] `by-file/ImageWriters.md`.
- [UID:0000ND] `by-file/ScreenshotCapture.md`.
- `by-project-structure/proposed-source-tree.md` and `by-meta/obtained_thirdparty_files/README.md` for source-file list/provenance only; no implementation edit is required there unless a supervisor chooses a global link cleanup.

Staged third-party source checked:

- `source-3/third_party_embeds/libjpeg/jcapimin.c`
- `source-3/third_party_embeds/libjpeg/jdatadst.c`
- `source-3/third_party_embeds/libjpeg/jcparam.c`
- `source-3/third_party_embeds/libjpeg/jcapistd.c`

Relevant source anchors from simple line searches:

| Source file | Anchors checked |
| --- | --- |
| `jcapimin.c` | `jpeg_CreateCompress` line 30, `jpeg_destroy_compress` line 88, `jpeg_abort_compress` line 100, `jpeg_suppress_tables` line 119, `jpeg_finish_compress` line 147, `jpeg_write_marker` line 192, `jpeg_write_m_header` line 214, `jpeg_write_m_byte` line 226, `jpeg_write_tables` line 254. |
| `jdatadst.c` | `init_destination` line 43, `empty_output_buffer` line 81, `term_destination` line 106, `jpeg_stdio_dest` line 130, callback assignments lines 147-149. |
| `jcparam.c` | `jpeg_add_quant_table` line 23, `jpeg_set_linear_quality` line 64, `jpeg_quality_scaling` line 106, `jpeg_set_quality` line 132, `add_huff_table` line 152, `std_huff_tables` line 182, `jpeg_set_defaults` line 268, `jpeg_default_colorspace` line 359, `jpeg_set_colorspace` line 391, `fill_a_scan` line 475, `fill_scans` line 490, `fill_dc_scans` line 509, `jpeg_simple_progression` line 537. |
| `jcapistd.c` | `jpeg_start_compress` line 38, `jpeg_write_scanlines` line 77, `jpeg_write_raw_data` line 120. |

Older report/docs treatment:

- B001's [UID:0000VP] report and B010's [UID:0000VR] report were used only as leads. Their relevant predecessor-boundary facts were rechecked in this pass or already incorporated into current docs.
- Stale Wave2/Wave3 material was not used as evidence. Current by-* docs, live MCP, and staged source were used instead.

## Current Documentation Gaps

The target already has correct broad owner/source-file direction and the retained screenshot-writer caller sequence, but it is still incomplete for source-quality:

- The current function map omits raw `jcapimin.c` public bodies at `0x00403a00`, `0x00403bf0`, `0x00403c50`, and `0x00403c70`.
- The current map compresses `jcparam.c` to a single `jpeg_set_defaults` row and misses the full modeled sequence at `0x00403df0-0x00404791`.
- The current `jpeg_write_marker family candidate` row should be replaced with exact `jpeg_write_marker`, `jpeg_write_m_header`, `jpeg_write_m_byte`, and `jpeg_write_tables` facts.
- The current endpoint `0x004048e2` is neither a half-open end nor an inclusive final return byte. It is the final `pop esi` inside `jpeg_write_scanlines`; the final return is `0x004048e3`, and the exact half-open body end is `0x004048e4`.
- The current score rationale says source-quality declarations are intentionally not emitted, but it does not prove why no static-embed marker is safe for this mixed page.
- [UID:0000VP] still has a stale key-anchor row describing `0x00403ed0-0x00403f03` as an "IDCT setup helper"; live decompilation shows `0x00403ed0` is `jpeg_set_linear_quality`, the two-call wrapper around `jpeg_add_quant_table` and the standard quantization tables.

## Function Inventory And Source Mapping

Live `entity_query` over `0x004038c0-0x004049c0` returned this modeled sequence. [UID:0000VS] contains the entries through `0x00404820`; `0x004048f0` is sibling [UID:0000VT], and `0x004049c0` is sibling [UID:0000VU].

| Address/range | IDA status | Stock IJG identity | Source file | Evidence summary |
| --- | --- | --- | --- | --- |
| `0x00403920-0x004039e6` | `sub_403920`, size `0xc6` | `jpeg_CreateCompress` | `jcapimin.c` | Called by product writer at `0x004efc71`; checks version `62`, struct size `360`, clears `0x168` bytes, calls memory manager init `0x405060`, sets compression start state. |
| `0x004039f0-0x004039fc` | `sub_4039F0`, size `0xc` | `jpeg_destroy_compress` | `jcapimin.c` | Thin wrapper called at writer cleanup/error sites `0x004efc3a` and `0x004efdc7`. |
| `0x00403a00-0x00403a0c` | raw/no-function | `jpeg_abort_compress` | `jcapimin.c` | Disassembly pushes `cinfo`, calls common `jpeg_abort` at `0x4049c0`, returns at `0x403a0b`; zero xrefs in current IDB. |
| `0x00403a10-0x00403a5e` | `sub_403A10`, size `0x4e` | `jpeg_suppress_tables` | `jcapimin.c` | Walks quant/Huffman table pointers and sets `sent_table`; xref from `jpeg_start_compress` at `0x4047cf`. |
| `0x00403a60-0x00403b62` | `sub_403A60`, size `0x102` | `jpeg_finish_compress` | `jcapimin.c` | Called by product writer at `0x004efdbb`; drains passes and calls common abort/reset at `0x4049c0`. |
| `0x00403b70-0x00403bef` | `sub_403B70`, size `0x7f` | `jpeg_write_marker` | `jcapimin.c` | Retained public marker write helper; zero current product xrefs. |
| `0x00403bf0-0x00403c43` | raw/no-function | `jpeg_write_m_header` | `jcapimin.c` | State guard for compression states `0x65/0x66/0x67`, then calls marker writer callback at `[cinfo+0x14c]+0x14`; zero current xrefs. |
| `0x00403c50-0x00403c67` | raw/no-function | `jpeg_write_m_byte` | `jcapimin.c` | Calls marker byte callback at `[cinfo+0x14c]+0x18`; zero current xrefs. |
| `0x00403c70-0x00403cbd` | raw/no-function | `jpeg_write_tables` | `jcapimin.c` | Requires `CSTATE_START`, resets error manager, initializes destination, calls marker/table writer `0x4064a0`, terminates marker/destination callbacks; zero current xrefs. |
| `0x00403cc0-0x00403cfd` | `sub_403CC0`, size `0x3d` | `jpeg_stdio_dest` | `jdatadst.c` | Product writer xref at `0x004efc83`; allocates 28-byte destination manager and stores callback pointers to `0x403d00`, `0x403d30`, `0x403d80`. |
| `0x00403d00-0x00403d26` | `sub_403D00`, size `0x26` | `init_destination` | `jdatadst.c` | Data xref from `jpeg_stdio_dest` at `0x403ce4`; allocates 4096-byte output buffer and sets free count. |
| `0x00403d30-0x00403d79` | `sub_403D30`, size `0x49` | `empty_output_buffer` | `jdatadst.c` | Data xref from `0x403ceb`; calls `_fwrite` with count `0x1000`, resets buffer/free count. |
| `0x00403d80-0x00403de6` | `sub_403D80`, size `0x66` | `term_destination` | `jdatadst.c` | Data xref from `0x403cf2`; writes remaining buffer bytes and calls flush path. |
| `0x00403df0-0x00403eca` | `sub_403DF0`, size `0xda` | `jpeg_add_quant_table` | `jcparam.c` | Validates `CSTATE_START`, checks table index < 4, allocates quant table through `0x404a20`, applies scale/force-baseline clamp over 64 words. |
| `0x00403ed0-0x00403f04` | `sub_403ED0`, size `0x34` | `jpeg_set_linear_quality` | `jcparam.c` | Calls `jpeg_add_quant_table` twice with tables at `0x631854` and `0x631954`; not an IDCT helper. |
| `0x00403f10-0x00403f48` | `sub_403F10`, size `0x38` | `jpeg_quality_scaling` | `jcparam.c` | Implements IJG quality scaling: <=0 returns 5000, <50 returns `5000/quality`, >=50 returns `2*(100-quality)`, >100 clamps to 100. |
| `0x00403f50-0x00403f6e` | `sub_403F50`, size `0x1e` | `jpeg_set_quality` | `jcparam.c` | Calls `jpeg_quality_scaling`, then `jpeg_set_linear_quality`. |
| `0x00403f70-0x0040406b` | `sub_403F70`, size `0xfb` | `jpeg_set_defaults` | `jcparam.c` | Product writer xref at `0x004efcbb`; allocates component info, sets `data_precision=8`, default quality 75, standard Huffman tables, defaults, then `jpeg_default_colorspace`. |
| `0x00404070-0x004040ca` | `sub_404070`, size `0x5a` | `std_huff_tables` | `jcparam.c` | Calls `add_huff_table` four times with standard DC/AC luminance/chrominance tables. |
| `0x004040d0-0x0040416d` | `sub_4040D0`, size `0x9d` | `add_huff_table` | `jcparam.c` | Allocates Huffman table through `0x404a40`, copies bits/values, validates symbol count 1..256, clears `sent_table`. |
| `0x00404170-0x004041cf` | `sub_404170`, size `0x5f` | `jpeg_default_colorspace` | `jcparam.c` | Switches on input color space and calls `jpeg_set_colorspace` with grayscale/RGB/YCbCr/CMYK/YCCK/unknown defaults. |
| `0x004041f0-0x004044ca` | `sub_4041F0`, size `0x2da` | `jpeg_set_colorspace` | `jcparam.c` | Sets component counts, component ids, sampling, quant table selectors, and color-transform flags for the IJG color spaces. |
| `0x004044f0-0x004046a0` | `sub_4044F0`, size `0x1b0` | `jpeg_simple_progression` | `jcparam.c` | Allocates/sets progressive scan script; calls local fill helpers at `0x404730`, `0x4046a0`, and `0x4046e0`. Binary order places the public function before its local helper bodies. |
| `0x004046a0-0x004046d1` | `sub_4046A0`, size `0x31` | `fill_a_scan` | `jcparam.c` | Writes one `jpeg_scan_info` entry and advances pointer by 9 dwords. |
| `0x004046e0-0x0040472a` | `sub_4046E0`, size `0x4a` | `fill_scans` | `jcparam.c` | Loops components, writes one scan per component. |
| `0x00404730-0x00404791` | `sub_404730`, size `0x61` | `fill_dc_scans` | `jcparam.c` | Writes DC scans directly for <=4 components or delegates to `fill_scans` for larger component counts. |
| `0x004047a0-0x00404815` | `sub_4047A0`, size `0x75` | `jpeg_start_compress` | `jcapistd.c` | Product writer xref at `0x004efcc9`; validates start state, optionally suppresses tables via `0x403a10`, calls master startup `0x406d90`, and transitions to scanline state. |
| `0x00404820-0x004048e4` | `sub_404820`, size `0xc4` | `jpeg_write_scanlines` | `jcapistd.c` | Product writer xref at `0x004efd8e`; validates state `0x65`, updates progress monitor, runs pass startup if needed, clamps row count, calls main controller `process_data`, advances `next_scanline`, returns at `0x4048e3`. |
| `0x004048f0-0x004049bb` | sibling [UID:0000VT] | `jpeg_write_raw_data` | `jcapistd.c` | Same source file as the two [UID:0000VS] `jcapistd.c` functions, but documented in sibling page; zero current product xrefs. |
| `0x004049c0-0x00404a5c` | sibling [UID:0000VU] | common API | `jcomapi.c` | Called by `jpeg_abort_compress` and `jpeg_finish_compress`; outside [UID:0000VS]. |

Padding/boundary facts:

- `0x00403a0c-0x00403a10`, `0x00403c43-0x00403c50`, `0x00403c67-0x00403c70`, `0x00403cbd-0x00403cc0`, `0x00403cfd-0x00403d00`, `0x00403d26-0x00403d30`, `0x00403de6-0x00403df0`, `0x00404791-0x004047a0`, `0x00404815-0x00404820`, and `0x004048e4-0x004048f0` are alignment/padding between source-shaped bodies or source-file groups.
- `get_bytes 0x004048e0 size 32` returned bytes ending the previous instruction at `0x4048e0-0x4048e1`, `5e c3` at `0x4048e2-0x4048e3`, twelve `0x90` bytes at `0x4048e4-0x4048ef`, then `56 8b 74 24 08...` for sibling `jpeg_write_raw_data` at `0x4048f0`.

## Caller, Reachability, And Negative Evidence

Product caller route:

- `xrefs_to 0x004efbc0` reports one code xref at raw address `0x005579d3`.
- Disassembly around `0x005579d3` shows the raw JPG screenshot path pushes the active surface pixel pointer, screen width `word_66DA94`, screen height `word_66DA98`, pixel-format flag `byte_69B3D5`, and the open `FILE*`, then calls `sub_4EFBC0`.
- Decompilation of `0x004efbc0` shows the project-owned JPEG writer wrapper creates an IJG compressor with version `62` and struct size `360`, configures dimensions/components/color-space, expands 16-bit source pixels to temporary RGB rows, calls `jpeg_write_scanlines` once per row, then finishes and destroys the compressor.

MCP `callees 0x004efbc0` returned the expected libjpeg sequence:

- `0x00401000` `jpeg_std_error`-style error manager initializer.
- `0x00403920` `jpeg_CreateCompress`.
- `0x00403cc0` `jpeg_stdio_dest`.
- `0x00403f70` `jpeg_set_defaults`.
- `0x004047a0` `jpeg_start_compress`.
- `0x00404820` `jpeg_write_scanlines`.
- `0x00403a60` `jpeg_finish_compress`.
- `0x004039f0` `jpeg_destroy_compress`.

Direct xref facts for target APIs:

| Address | Xref result | Interpretation |
| --- | --- | --- |
| `0x00403920` | one product writer xref at `0x004efc71` | Retained and used by screenshot writer. |
| `0x004039f0` | writer xrefs at `0x004efc3a` and `0x004efdc7` | Error and normal destroy paths. |
| `0x00403a00` | zero xrefs | Retained public stock API, not product-used in current graph. |
| `0x00403a10` | internal xref from `0x4047cf` | Used by `jpeg_start_compress`. |
| `0x00403a60` | writer xref at `0x004efdbb` | Normal finish path. |
| `0x00403b70`, `0x00403bf0`, `0x00403c50`, `0x00403c70` | zero xrefs | Retained public marker/table write APIs with no current product caller. |
| `0x00403cc0` | writer xref at `0x004efc83` | Destination setup used by product wrapper. |
| `0x00403d00`, `0x00403d30`, `0x00403d80` | data refs only from `jpeg_stdio_dest` | Callback pointers, not product entry points. |
| `0x00403df0` through `0x004041f0` | internal refs inside `jcparam.c` | Parameter/default helper family. |
| `0x004044f0` | zero xrefs | Public `jpeg_simple_progression` retained but not currently called. |
| `0x004047a0` | writer xref at `0x004efcc9` | Start compression used by product wrapper. |
| `0x00404820` | writer xref at `0x004efd8e` | Scanline write used by product wrapper. |
| `0x004048f0` | zero xrefs | Sibling raw-data API retained but unused by current product writer. |

This evidence supports a product/library split:

- [UID:00018N] / [UID:0000K4] own the NexusTK RGB565/RGB555 conversion wrapper and writer-local error/destination callbacks.
- [UID:0001G8] / [UID:0000ND] own screenshot path policy, file naming, status, and proof-packet workflow.
- [UID:0000VS] remains third-party IJG libjpeg source, not product screenshot code.

## Predecessor And Successor Relationship

Predecessor:

- Current [UID:0000VR] already incorporates B010's repaired range: `0x00401b00-0x0040391f` is stock `jdmarker.c`, with raw `jpeg_set_marker_processor` at `0x004038d0-0x0040391e`.
- This pass rechecked the immediate boundary: `lookup_funcs` reports no function at `0x0040391e` and `0x0040391f`, and `0x00403920` is `sub_403920` size `0xc6`, matching `jpeg_CreateCompress`.
- [UID:0000VS] should preserve the predecessor note already present, but it should not treat the predecessor as part of its own source range.

Successor:

- [UID:0000VT] starts at `0x004048f0` with `sub_4048F0` size `0xcb`, matching `jpeg_write_raw_data` in `jcapistd.c`.
- `0x004048e4-0x004048f0` is NOP alignment after [UID:0000VS] `jpeg_write_scanlines`.
- [UID:0000VT] is the same upstream `jcapistd.c` source file as [UID:0000VS]'s `jpeg_start_compress` / `jpeg_write_scanlines` entries. That cross-page source-file split is the key reason a static-embed marker for `jcapistd.c` is not range-safe in [UID:0000VS].

## Heuristic / Inference Reanalysis And Rejected Alternatives

1. "Insert a static-embed marker for all four listed source files in [UID:0000VS]."
   - Rejected. [UID:0000VS] is not an exact source-file slice. It contains three complete source files or source-file clusters plus only the front part of `jcapistd.c`; the rest of `jcapistd.c` is sibling [UID:0000VT]. A formal block that names `jcapistd.c` would emit source outside the target range.

2. "Paste handwritten/decompiler-shaped C++ for the used screenshot API subset."
   - Rejected. The code is third-party IJG source and should come from staged `third_party_embeds/libjpeg`, not from a decompiler reconstruction. Handwritten wrapper-like C++ would misrepresent stock public APIs and local callback layouts.

3. "Move the used APIs into `ImageWriters.cpp` or `ScreenshotCapture.cpp` because the only product caller is the screenshot writer."
   - Rejected. The product wrapper calls standard libjpeg APIs; it does not own their bodies. Unused retained public APIs and internal `jcparam.c` helpers further prove this is a static library island.

4. "Treat zero-xref public APIs as dead padding and remove them from source mapping."
   - Rejected. `jpeg_abort_compress`, marker write APIs, `jpeg_write_tables`, and `jpeg_simple_progression` are source-identifiable retained IJG public APIs. Zero xrefs only mean they are unused by the current NexusTK caller graph.

5. "Leave the score unchanged because source-file children might be needed."
   - Rejected. The source-file split need is now resolved enough to document: the current page can improve as a mixed non-emitting source-map page, while exact source-file child pages would be a separate source-bearing split plan.

6. "Keep the endpoint `0x004048e2`."
   - Rejected. Live disassembly and bytes show `0x004048e2` is only `pop esi`, not the return byte or half-open end. The correct half-open code end is `0x004048e4`.

7. "Use B001/B010 old report text as authority."
   - Rejected as an evidence source. B001/B010 reports were useful leads; the mapping and endpoint conclusions above are based on current MCP/session `80de0a67` and current staged source.

## Formal C++ / No-Code Disposition

Recommended formal `RECONSTRUCTION_CPP CODE` content: keep empty between `BEGIN` and `END`.

Target-specific no-code proof:

- [UID:0000VS] is a mixed compression source-map page, not a single exact source file.
- It covers all retained `jcapimin.c`, all retained `jdatadst.c`, all retained `jcparam.c`, and only the `jcapistd.c` prefix through `jpeg_write_scanlines`.
- The same upstream `jcapistd.c` file continues in sibling [UID:0000VT] at `0x004048f0-0x004049bb` with `jpeg_write_raw_data`.
- Static-embed comments are safe only when the by-memory range represents the source file or when the report proves a target-specific embedding convention. That is not true for this mixed page.
- Handwritten C/C++ is the wrong source form because staged official IJG libjpeg 6b source is available and the code is stock third-party library code.

Exact source-file split plan if the supervisor later wants source-bearing static-embed pages:

| Exact source-bearing slice | Range | Formal source route |
| --- | --- | --- |
| `jcapimin.c` | `0x00403920-0x00403cbd` plus documented alignment to `0x00403cc0` | static embed of `third_party_embeds/libjpeg/jcapimin.c` in a dedicated exact child, not in [UID:0000VS]. |
| `jdatadst.c` | `0x00403cc0-0x00403de6` plus documented alignment to `0x00403df0` | static embed of `third_party_embeds/libjpeg/jdatadst.c` in a dedicated exact child. |
| `jcparam.c` | `0x00403df0-0x00404791` plus documented alignment to `0x004047a0` | static embed of `third_party_embeds/libjpeg/jcparam.c` in a dedicated exact child. |
| `jcapistd.c` | `0x004047a0-0x004049bb`, crossing [UID:0000VS] and [UID:0000VT] with padding at `0x004048e4-0x004048f0` | static embed of `third_party_embeds/libjpeg/jcapistd.c` only after a split/merge child covers the whole source file. |

This split plan is not required for the recommended [UID:0000VS] implementation callback. It is included so the current no-code decision is evidence-backed rather than a deferred unknown.

## Positive Evidence

- Current MCP function inventory, decompilation, and disassembly match IJG libjpeg 6b `jcapimin.c`, `jdatadst.c`, `jcparam.c`, and `jcapistd.c` source anchors.
- Product caller evidence is exact: the raw JPG path at `0x005579d3` calls the project JPEG writer, and the writer calls only the expected used libjpeg compression APIs.
- Negative xrefs to retained public APIs are consistent with static-library inclusion, not padding or product ownership.
- Predecessor [UID:0000VR] now ends immediately before `jpeg_CreateCompress` after covering raw `jdmarker.c` `jpeg_set_marker_processor`.
- Successor [UID:0000VT] starts at `0x004048f0` with `jpeg_write_raw_data`, proving the source-file split inside `jcapistd.c`.
- Local source provenance exists under `source-3/third_party_embeds/libjpeg`, and `by-meta/obtained_thirdparty_files/README.md` already records `jpegsrc.v6b.tar.gz` as the source archive.

## Negative / Counter Evidence

- No debug/PDB/source-path metadata proves original object order or exact compiler flags. Source-file identity is based on staged source comparison plus instruction/call/data-flow matches.
- `jpeg_abort_compress`, `jpeg_write_marker`, `jpeg_write_m_header`, `jpeg_write_m_byte`, `jpeg_write_tables`, `jpeg_simple_progression`, and `jpeg_write_raw_data` currently have no product xrefs. They remain retained third-party stock APIs, not current product wrappers.
- IDA does not model raw public bodies at `0x00403a00`, `0x00403bf0`, `0x00403c50`, or `0x00403c70` as functions. The target must preserve that raw/no-function evidence rather than silently presenting every source body as modeled.
- The current [UID:0000VS] formal block cannot safely use `jcapistd.c` because sibling [UID:0000VT] owns the source-file tail.
- Current [UID:0000VP] has at least one stale local label (`0x00403ed0` as an IDCT helper) that should be corrected if touched.

## Support Doc Update Plan

If the supervisor accepts this report, update these docs at report-level detail. Do not edit generated reports, `project-level` files, validator/tool state, IDA DB files, or any manual `-coverage-report.md`.

| Doc | Required action |
| --- | --- |
| [UID:0000VS] target | Apply metadata `89/92`, keep owner/emitter/reconstructable unchanged, keep formal C++ blank, update item summary, repair endpoint/path to `0x004048e4` if supervisor accepts path repair, replace function mapping with the complete modeled/raw table above, preserve predecessor/successor proof, product caller sequence, negative xrefs, rejected alternatives, and no-code proof. |
| [UID:0000KN] `by-file/LibJPEG.md` | Replace the short [UID:0000VS] source-match line with the full source-map decision: all `jcapimin.c`, all `jdatadst.c`, all `jcparam.c`, and `jcapistd.c` prefix through `jpeg_write_scanlines`; mention raw `jcapimin.c` public helpers and no static-embed marker because `jcapistd.c` crosses into [UID:0000VT]. Update link/range if target path is repaired. |
| [UID:0000VP] `LibJpeg6bCore` | Update the [UID:0000VS] row/range to `0x00403920-0x004048e4` if repaired, replace the generic compression-source sentence with the complete source-map summary, and correct the stale `0x00403ed0` row from "IDCT setup helper" to `jpeg_set_linear_quality` / `jcparam.c` quantization setup. |
| [UID:0000VT] `LibJpegCompressRawDataApi` | Add predecessor/source-file continuity proof: [UID:0000VS] ends at `0x004048e4`, `0x004048e4-0x004048f0` is padding, `0x004048f0` starts `jpeg_write_raw_data`, and a full `jcapistd.c` static embed would need an exact source-file child crossing both pages. Update link/range if target path is repaired. |
| [UID:0001QE] `client_libraries.md` | Strengthen the IJG libjpeg bullet/source anchor for [UID:0000VS] to include raw public `jcapimin.c` helpers, full `jcparam.c` default/progression sequence, and the mixed/no-code decision. Update link/range if target path is repaired. |
| [UID:00018N] `JpegScreenshotWriter` | No substantive source-quality edit needed: current page already has equal-or-greater product wrapper/callee detail. If [UID:0000VS] is renamed, perform link-only update to the new path. |
| [UID:0001G8] `ScreenshotJpegCapturePath` | No substantive source-quality edit needed: current page already has equal-or-greater raw call/path proof. If [UID:0000VS] is renamed, perform link-only update only if the old path appears there. |
| [UID:0000K4] `ImageWriters` | No substantive source-quality edit needed: current page already separates the project JPEG wrapper from IJG internals at equal detail. If [UID:0000VS] is renamed, perform link-only update only if needed. |
| [UID:0000ND] `ScreenshotCapture` | No substantive source-quality edit needed: current page already keeps screenshot policy/workflow separate from ImageWriters and LibJPEG. If [UID:0000VS] is renamed, no currently observed direct link update is required. |
| [UID:0000VR] `LibJpegMarkerReader` | No substantive edit needed: current page already records the predecessor raw `jpeg_set_marker_processor` and [UID:0000VS] successor at equal detail. If [UID:0000VS] is renamed, perform link-only update. |
| [UID:0000VU], [UID:0000VZ], [UID:0000W0], and other by-memory pages found by `rg` | No substantive edit needed unless the path repair is accepted. If [UID:0000VS] is renamed, update old-path cross-reference links in scoped by-* pages that currently point to `0x00403920-0x004048e2`. |
| `by-meta/obtained_thirdparty_files/README.md` | No edit needed; it already records `jpegsrc.v6b.tar.gz` and the relevant compression source-file names at sufficient detail. |
| `by-project-structure/proposed-source-tree.md` | No edit needed for this target; it already lists `jcapimin.c`, `jcapistd.c`, `jcparam.c`, and `jdatadst.c`. Do not edit during normal by-* implementation unless supervisor explicitly expands scope. |

## Validator Plan For Implementation Callback

No validators were run in report-only mode because no by-* docs were edited.

If accepted and implemented, run scoped validators from `source-3/project-documentation` for every changed by-* file. The expected core commands are:

> Executable block R001 was removed from this report and preserved verbatim in [0000VS-LibJpegCompressApiFrontEnd-source-quality-removed.md](0000VS-LibJpegCompressApiFrontEnd-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor accepts target path repair, also validate any by-* pages touched for link-only updates, including any changed [UID:00018N], [UID:0001G8], [UID:0000VR], [UID:0000VU], [UID:0000VZ], or [UID:0000W0] pages. Do not manually edit validator registry state; use validator-supported path/UID handling if a rename exposes stale registry diagnostics.

Current lease note for supervisor: during report-only research, `tools/leaser/Agents/current_leases.md` showed B010 temporarily leasing the old [UID:0000VS] path and related LibJPEG support docs until `2026-06-27T00:36:25Z` range. No B007 lease was taken or needed.

## Implementation Tracking Checklist

- [x] Do not edit generated reports, `project-level` generated files, manual `-coverage-report.md` files, validator/tool state, IDA DB files, or unrelated docs.
  - Proof: edited only the accepted by-* docs plus this active report checklist. Generated `auto-generated/-ag-coverage-report-by-memory.md` and `project-level/-auto-completion-stats.md` were validator side effects only; no manual edits were made.
- [x] Lease only the immediate accepted edit set during the implementation callback, then release leases immediately after the edit/validator batch.
  - Proof: B007 stale prior leases were already inactive (`B007: No active leases`). A fresh B007 lease on the five changed by-* docs was taken before the validator batch after waiting for B006's `LibJPEG.md` / `LibJpeg6bCore.md` lease to expire; `python .\tools\leaser\leaser.py B007 unlease` released all five paths successfully after validation, and `tools/leaser/Agents/current_leases.md` then reported no active leases.
- [x] If the supervisor accepts endpoint path repair, perform the validator-supported rename/update from `by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md` to `by-memory/0x00403920-0x004048e4.LibJpegCompressApiFrontEnd.md`; otherwise preserve the old path but record exact no-rename proof in the target body.
  - Proof: no physical rename was performed in this callback. [UID:0000VS] now explicitly states that `0x004048e2` is a legacy/stale filename slug while the proven half-open body end is `0x004048e4`, with final `pop esi` at `0x004048e2`, final `retn` at `0x004048e3`, and padding `0x004048e4-0x004048f0`.
- [x] Update [UID:0000VS] metadata to `COMPLETION:89`, `CONFIDENCE:92`, with `CANONICAL_OWNER:0000KN`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KN`, `EMITTER_POSITION_OPTIONAL:` unchanged, and `Nested:0` unchanged.
  - Proof: [UID:0000VS] header updated and validator command `000000003560` recorded `completion_update 0000VS ... 89` and `confidence_update 0000VS ... 92`.
- [x] Keep [UID:0000VS] formal `RECONSTRUCTION_CPP CODE` blank; do not insert a static-embed marker or handwritten C++.
  - Proof: [UID:0000VS] formal block remains empty between `BEGIN` and `END`; target `Formal C++ / No-Code Proof` explains why no static-embed marker or handwritten C++ is safe for the mixed page.
- [x] Update [UID:0000VS] item summary to the recommended mixed-source-map summary.
  - Proof: [UID:0000VS] `Item Summary` is now the accepted mixed-source-map text; generated by-memory auto coverage row refreshed at validator command `000000003563` shows the same summary and `89%`.
- [x] Replace [UID:0000VS] status/range-role text with current source-form decision: third-party IJG source-map page, not product ImageWriters/ScreenshotCapture code; no-code because the page is mixed and `jcapistd.c` crosses into [UID:0000VT].
  - Proof: [UID:0000VS] `Status`, `Range Role`, `Ownership Decision`, `Formal C++ / No-Code Proof`, and `Rejected Alternatives` sections now record this exact source-form decision.
- [x] Replace [UID:0000VS] function mapping with the full table from this report, including raw `jpeg_abort_compress`, raw `jpeg_write_m_header`, raw `jpeg_write_m_byte`, raw `jpeg_write_tables`, `jdatadst.c` callbacks, full `jcparam.c` sequence, and corrected `jpeg_write_scanlines` end at `0x004048e4`.
  - Proof: [UID:0000VS] `Function Mapping` now contains the complete modeled/raw table through `0x00404820-0x004048e4`, plus alignment/padding bytes.
- [x] Preserve [UID:0000VS] live MCP session facts: session `80de0a67`, server health, function inventory, lookup endpoint facts, disassembly/decompile/xref/callee evidence, and corrected request-shape caveats.
  - Proof: [UID:0000VS] `MCP Evidence Preserved` table records session/database `80de0a67`, active IDB, health, function inventory, endpoint lookup, disassembly/decompile, xref/callee evidence, and request-shape caveat. Callback MCP probe also confirmed `server_health(database=80de0a67)` returned `status:"ok"`.
- [x] Preserve [UID:0000VS] product caller proof from raw `0x005579d3` through [UID:00018N] to the used libjpeg API sequence.
  - Proof: [UID:0000VS] `Product Caller Evidence` records raw `0x005579d3`, [UID:00018N], pushed surface/size/format/file arguments, and the complete used libjpeg callee sequence.
- [x] Preserve [UID:0000VS] negative evidence for zero-xref retained public APIs and raw/no-function source-shaped bodies.
  - Proof: [UID:0000VS] `Function Mapping`, `Product Caller Evidence`, and `Rejected Alternatives` record zero-xref public APIs and raw/no-function retained source-shaped bodies as stock IJG APIs rather than padding or product wrappers.
- [x] Preserve [UID:0000VS] predecessor proof from [UID:0000VR] raw `jpeg_set_marker_processor` ending at `0x0040391e`, alignment at `0x0040391f`, and `jpeg_CreateCompress` at `0x00403920`.
  - Proof: [UID:0000VS] `Range Role` and `MCP Evidence Preserved` sections record the [UID:0000VR] predecessor boundary and `jpeg_CreateCompress` successor start.
- [x] Preserve [UID:0000VS] successor proof: `jpeg_write_scanlines` returns at `0x004048e3`, padding `0x004048e4-0x004048f0`, [UID:0000VT] `jpeg_write_raw_data` starts at `0x004048f0`.
  - Proof: [UID:0000VS] `Range Role`, `Function Mapping`, and `Rejected Alternatives` record the corrected end/padding/successor facts; [UID:0000VT] also records this predecessor/source-file continuity proof.
- [x] Preserve [UID:0000VS] rejected alternatives: static-embed marker in current mixed page, handwritten C++/Hex-Rays code, product ownership by ImageWriters/ScreenshotCapture, treating zero-xref APIs as padding/dead code, unchanged score because of split questions, and endpoint `0x004048e2`.
  - Proof: [UID:0000VS] `Rejected Alternatives` contains all six accepted rejections.
- [x] Update [UID:0000KN] `by-file/LibJPEG.md` with the full [UID:0000VS] source-map decision and path/range change if accepted.
  - Proof: `by-file/LibJPEG.md` now records [UID:0000VS] as legacy slug/proven body `0x00403920-0x004048e4`, full `jcapimin.c`/`jdatadst.c`/`jcparam.c` plus `jcapistd.c` prefix, raw helper retention, and no-static-embed reason. No physical path rename was accepted/performed.
- [x] Update [UID:0000VP] `LibJpeg6bCore` with the full [UID:0000VS] source-map decision, path/range change if accepted, and correction of the stale `0x00403ed0` "IDCT setup helper" wording to `jpeg_set_linear_quality` / `jcparam.c`.
  - Proof: `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md` now has a B007 MCP evidence row, corrected [UID:0000VS] child map row, corrected `0x004048e4-0x004048f0` boundary note, and a change entry stating `0x00403ed0` is `jpeg_set_linear_quality` / `jcparam.c` quantization setup, not IDCT setup.
- [x] Update [UID:0000VT] `LibJpegCompressRawDataApi` with predecessor padding/source-file continuity proof and path/range change if accepted.
  - Proof: [UID:0000VT] `Range Role` now records [UID:0000VS] returning at `0x004048e3`, body end `0x004048e4`, padding `0x004048e4-0x004048f0`, `jpeg_write_raw_data` start `0x004048f0`, and the full-`jcapistd.c` cross-page child requirement. No physical path rename was performed.
- [x] Update [UID:0001QE] `client_libraries.md` with the fuller [UID:0000VS] compression source-map and no-code/static-embed decision.
  - Proof: `by-meta/client_libraries.md` dependency table, IJG libjpeg evidence bullets, B007 callback paragraph, and source-structure decision now carry the full [UID:0000VS] source-map and blank/no-static-embed decision.
- [x] Record no-edit proof for [UID:00018N], [UID:0001G8], [UID:0000K4], [UID:0000ND], [UID:0000VR], `by-meta/obtained_thirdparty_files/README.md`, and `by-project-structure/proposed-source-tree.md` if they are not touched because current detail is equal-or-greater and no path rename/link update is needed.
  - Proof: read-only checks found [UID:00018N] already records the libjpeg callee sequence and wrapper/library split; [UID:0001G8], [UID:0000K4], and [UID:0000ND] already separate screenshot workflow/writer wrapper from IJG internals; [UID:0000VR] already records raw `jpeg_set_marker_processor` through `0x0040391e`, alignment `0x0040391f`, and [UID:0000VS] successor at `0x00403920`; `by-meta/obtained_thirdparty_files/README.md` already lists `jpegsrc.v6b.tar.gz` and the relevant source files; `by-project-structure/proposed-source-tree.md` already lists `jcapimin.c`, `jcapistd.c`, `jcparam.c`, and `jdatadst.c` under `third_party/libjpeg/`. No path rename/link update was needed.
- [x] If [UID:0000VS] is physically renamed, update old-path links in scoped non-generated by-* docs found by `rg`, including [UID:00018N], [UID:0000VR], [UID:0000VU], [UID:0000VZ], [UID:0000W0], and any other changed by-* pages.
  - Proof: no physical rename was performed, so link-only churn was explicitly excluded by the callback.
- [x] Run scoped validators for every changed by-* file from `source-3/project-documentation`; record command, working directory, exit code, `command_id`, `command_timestamp`, ok/error counts, and generated-refresh side effects.
  - Proof: validators run from `E:\NTK\GhidraBridge\source-3\project-documentation`:
    - `python .\tools\validator.py --mode file --file by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md --apply --queue-timeout 240`; exit `0`; `command_id: 000000003560`; `command_timestamp: 2026-06-26T22:20:53-04:00`; `ok: 1`; `completion_update: 1`; `confidence_update: 1`; `uid_link_insert: 3`; `generated_refresh: deferred`.
    - `python .\tools\validator.py --mode file --file by-file/LibJPEG.md --apply --queue-timeout 240`; exit `0`; `command_id: 000000003561`; `command_timestamp: 2026-06-26T22:21:00-04:00`; `ok: 1`; existing `missing_ref_uid 0003OI`; `generated_refresh: deferred`.
    - `python .\tools\validator.py --mode file --file by-memory/0x00401000-0x00414283.LibJpeg6bCore.md --apply --queue-timeout 240`; exit `0`; `command_id: 000000003562`; `command_timestamp: 2026-06-26T22:21:14-04:00`; `ok: 1`; existing `missing_ref_uid 0003OI`; `generated_refresh: deferred`.
    - `python .\tools\validator.py --mode file --file by-memory/0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md --apply --queue-timeout 240`; exit `0`; `command_id: 000000003563`; `command_timestamp: 2026-06-26T22:21:23-04:00`; `ok: 1`; `uid_link_insert: 3`; `generated_refresh: deferred`.
    - `python .\tools\validator.py --mode file --file by-meta/client_libraries.md --apply --queue-timeout 240`; exit `0`; `command_id: 000000003565`; `command_timestamp: 2026-06-26T22:21:31-04:00`; `ok: 1`; `uid_link_insert: 5`; existing support warnings `missing_ref_target: 4` and `missing_ref_uid: 9`; `generated_refresh: deferred`.
    - Read-only `python .\tools\validator.py --queue-status`; exit `0`; `command_id: 000000003567`; `command_timestamp: 2026-06-26T22:22:07-04:00`; queued jobs `0`; queued generated refresh jobs `0`.
    - `auto-generated/-ag-coverage-report-by-memory.md` header is `validator-command-id: 000000003563`, `validator-refreshed-at: 2026-06-26T22:21:23-04:00`, and the [UID:0000VS] row shows `89%` with the accepted item summary.
- [x] Update this report checklist with checkmarks and proof only during an implementation callback after the supervisor accepts the report.
  - Proof: this checklist was updated after the implementation callback edits and validators completed.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000VS-LibJpegCompressApiFrontEnd-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0000VS-LibJpegCompressApiFrontEnd-source-quality.md","timestamp":"2026-06-26T22:30:12","uid":"0000VS"} -->
<!-- {"agent":"B007","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000VS-LibJpegCompressApiFrontEnd-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B007/0000VS-LibJpegCompressApiFrontEnd-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000VS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
