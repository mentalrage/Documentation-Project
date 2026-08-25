** TARGET-REPORT-UID:0000VZ **
** AUTHOR-AGENT-ID:B014 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
*** Assignment: B014-report-0000VZ-libjpeg-marker-writer-source-quality-20260626 ***
*** Target: [UID:0000VZ] by-memory/0x004064a0-0x00406d8c.LibJpegMarkerWriter.md ***
*** Mode: REPORT_ONLY ***

# [UID:0000VZ] LibJpegMarkerWriter Source-Quality Report

## Status

Report-only research completed with current live IDA MCP evidence. I did not lease files and did not edit target/support by-* docs, generated/project-level files, manual coverage reports, validator/tool state, or the IDA database.

Primary finding: [UID:0000VZ] is correctly owned by [UID:0000KN] LibJPEG and maps to stock IJG libjpeg 6b `jcmarker.c`, but the current by-memory path/range uses `0x00406d8c` as the end even though live IDA shows the final `write_tables_only` function runs through `0x00406d8f` and the successor begins at `0x00406d90`. The accepted implementation should rename the page to the half-open range `0x004064a0-0x00406d90`, correct support-doc rows that currently treat `0x00406d8c-0x00406d90` as padding, and insert the formal static-embed marker for `third_party_embeds/libjpeg/jcmarker.c`.

Recommended target metadata after implementation:

| Field | Current live target | Recommended |
| --- | --- | --- |
| Path/range | `by-memory/0x004064a0-0x00406d8c.LibJpegMarkerWriter.md` | rename to `by-memory/0x004064a0-0x00406d90.LibJpegMarkerWriter.md` |
| `COMPLETION` | `86` | `90` |
| `CONFIDENCE` | `90` | `92` |
| `CANONICAL_OWNER` | `0000KN` | unchanged |
| `RECONSTRUCTABLE` | `TRUE` | unchanged |
| `EMITTER_UIDS` | `0000KN` | unchanged |
| `EMITTER_POSITION_OPTIONAL` | blank | unchanged |
| formal `RECONSTRUCTION_CPP CODE` | blank | `// Static embed: third_party_embeds/libjpeg/jcmarker.c` |
| `Nested` | `0` | unchanged |

The generated research tracker row read during this pass still shows the older `80/85` score for [UID:0000VZ]. The live by-memory header is `86/90`; the source page header and current MCP evidence should be treated as live state, and generated tracker/coverage refresh should happen through the validator after accepted implementation.

## Current Target State

Current target file: `by-memory/0x004064a0-0x00406d8c.LibJpegMarkerWriter.md`

Current header:

- `UID:0000VZ`
- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000KN`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KN`
- blank `EMITTER_POSITION_OPTIONAL`
- blank formal reconstruction block
- `Item Summary` currently says "`jpeg-6b/jcmarker.c` source-file ownership."
- `Nested:0`

Current body evidence is directionally correct for third-party IJG marker-writer ownership, but it is too coarse for the final source-quality state:

- It groups `0x00406500-0x00406bcc` as marker/table helpers without the complete source-function map.
- It describes `0x00406d10-0x00406d8c` as "`write_file_header` / table emission path"; live MCP and staged source show this function is `write_tables_only`, while `write_file_header` is `0x004065f0`.
- It says the next function is `0x00406d90`, but the filename and support rows use `0x00406d8c` as the apparent end. Live bytes show `0x00406d8c-0x00406d8f` is the epilogue/return of `write_tables_only`, not alignment.
- It leaves the formal code block blank even though [UID:0000KN] and [UID:0000VP] now document a static-embed marker policy for source-bearing stock libjpeg children.

## Actual Evidence Checked

Current local docs/source checked:

- `tools/leaser/Agents/Agent-B014/goal.md`
- `by-structure.md`
- `by-memory/-guidance.md`
- `by-memory/0x004064a0-0x00406d8c.LibJpegMarkerWriter.md`
- `by-file/LibJPEG.md`
- `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`
- `by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md`
- `by-memory/0x00406d90-0x00406e46.LibJpegCompressMasterInit.md`
- `by-memory/0x00401b00-0x0040391f.LibJpegMarkerReader.md`
- `by-meta/obtained_thirdparty_files/static_embeds/README.md`
- `by-meta/client_libraries.md`
- `by-project-structure/proposed-source-tree.md` as read-only source-tree context
- `auto-generated/-ag-research-tracker.md` as generated queue context only
- central executed reports:
  - `executed-b-agent-research/B001/0000VP-LibJpeg6bCore-source-quality.md`
  - `executed-b-agent-research/B007/0000VQ-LibJpegDecompressApiFrontEnd-source-quality.md`
  - `executed-b-agent-research/B009/0000VT-LibJpegCompressRawDataApi-source-quality.md`
  - `executed-b-agent-research/B010/0000VR-LibJpegMarkerReader-source-quality.md`
- staged upstream source: `source-3/third_party_embeds/libjpeg/jcmarker.c`
- static-embed provenance: `by-meta/obtained_thirdparty_files/static_embeds/README.md`

Searches used:

- `rg -n "0000VZ|LibJpegMarkerWriter|marker writer|jmarker|jwrite|libjpeg|jpeg" .`
- `rg -n "0000VZ|LibJpegMarkerWriter|jcmarker\.c|jinit_marker_writer|write_file_header|write_scan_header|Static embed: third_party_embeds/libjpeg/jcmarker\.c" executed-b-agent-research tools/leaser/Agents archived`
- `rg --files executed-b-agent-research | rg '0000VP|0000VZ|LibJpeg'`
- `rg -n "631C14|0x00631c14|jpeg_natural_order|natural_order" project-documentation`

Staged source facts:

- `source-3/third_party_embeds/libjpeg/jcmarker.c` exists, length `17245`, timestamp `1998-02-21 16:54:00`.
- SHA256: `C4EADB83AEAA63DF9A17364FBDDB1DF1B96FB1281F2D395DFF6EC8371373CFCC`.
- `Select-String` source anchors:
  - `emit_byte` line 108
  - `emit_marker` line 122
  - `emit_2bytes` line 131
  - `emit_dqt` line 144
  - `emit_dht` line 184
  - `emit_dac` line 222
  - `emit_dri` line 265
  - `emit_sof` line 277
  - `emit_sos` line 308
  - `emit_jfif_app0` line 349
  - `emit_adobe_app14` line 384
  - `write_marker_header` line 438
  - `write_marker_byte` line 450
  - `write_file_header` line 469
  - `write_frame_header` line 494
  - `write_scan_header` line 551
  - `write_file_trailer` line 602
  - `write_tables_only` line 616
  - `jinit_marker_writer` line 645

Numeric marker cross-check:

- `python .\tools\int_convert.py` was used on a stdin JSON batch for marker constants `216`, `217`, `218`, `219`, `224`, `238`, `192`, `193`, `194`, `201`, `196`, `221`, `0xFFFD`, and `32`.
- Relevant conversions used below are therefore verified with `int_convert.py`: `216 = 0xd8`, `217 = 0xd9`, `218 = 0xda`, `219 = 0xdb`, `224 = 0xe0`, `238 = 0xee`, `192 = 0xc0`, `193 = 0xc1`, `194 = 0xc2`, `201 = 0xc9`, `196 = 0xc4`, `221 = 0xdd`, `0xFFFD = 65533`, and `32 = 0x20`.

## MCP Session And Tool Facts

Endpoint: `http://127.0.0.1:13337/mcp`

Read-only availability checks:

- `Test-NetConnection 127.0.0.1 -Port 13337` returned `TcpTestSucceeded: True`.
- JSON-RPC `initialize`, command id `b014-0000vz-init`, returned HTTP `200`, server `ida-pro-mcp`, protocol `2025-06-18`.
- JSON-RPC `tools/list`, command id `b014-0000vz-tools-list`, returned HTTP `200`; active schemas require the `database` argument for IDB-backed tools.
- `idb_list`, command id `b014-0000vz-idb-list`, returned active session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, PID/worker PID `26892`, `is_analyzing:false`.
- `server_health`, command id `b014-0000vz-health`, returned `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.

Read-only MCP evidence calls used:

| Command id | Tool | Evidence |
| --- | --- | --- |
| `b014-0000vz-function-range` | `entity_query(functions, 0x00406480-0x00406e60)` | Returned target-adjacent function inventory from prior `sub_406480` through successor `sub_406E60`. Target source-file functions are `0x004064a0` through `0x00406d10`; `0x00406d90` is the next source file. |
| `b014-0000vz-lookup-boundaries` | `lookup_funcs` | `0x0040649b` is not a function, `0x004064a0` is `sub_4064A0` size `0x51`, `0x00406d8c` is inside `sub_406D10` size `0x80`, and `0x00406d90` is `sub_406D90` size `0xb6`. |
| `b014-0000vz-bytes-boundaries` | `get_bytes` | `0x00406490` shows return bytes from `jzero_far` then five `0x90` bytes before `0x004064a0`; `0x00406d8c` begins `5f 5e 5b c3`, the epilogue/return for `sub_406D10`; `0x00406d90` begins the successor prologue. |
| `b014-0000vz-analyze-component` | `analyze_component` | The cluster has one interface function, `0x004064a0`; the other target functions are internal-only. The internal call graph matches the `jcmarker.c` private marker emit helpers and public marker-writer callbacks. |
| `b014-0000vz-callees-key` | `callees` | `0x00406d90` calls compression initializers and then `0x004064a0`; `0x004047a0` calls `0x00406d90`; `0x00406c10` and `0x00406d10` call only local marker helpers. |
| `b014-0000vz-xrefs-key` | `xrefs_to` | `0x004064a0` has code xrefs at `0x00403ca2` and `0x00406e2c`; callback functions have data xrefs from `0x004064a0` setup; `0x00406d90` has code xref from `0x004047e5`. |
| `b014-0000vz-analyze-64a0` | `analyze_function(0x004064a0)` | Allocates `32` bytes with pool `1`, stores marker writer at compressor offset `332`, installs seven callback pointers, and zeroes the private restart-interval field. |
| `b014-0000vz-analyze-*` / `b014-0000vz-detail-*` | `analyze_function` | Decompiled all target functions enough to map marker bytes, callbacks, table writers, SOF/SOS/SOI/EOI behavior, and the no-op arithmetic DAC stub to staged `jcmarker.c`. |
| `b014-0000vz-analyze-start-compress` | `analyze_function(0x004047a0)` | `jpeg_start_compress`-style function is called by product screenshot writer `sub_4EFBC0`, calls `0x00406d90`, then invokes the marker writer callback at compressor offset `316`. |
| `b014-0000vz-compress-api-functions` | `entity_query(functions, 0x00403920-0x004048f0)` | Confirms the compression API front-end neighborhood that bridges the product screenshot wrapper to IJG compression functions. |
| `b014-0000vz-xrefs-natural-order` | `xrefs_to(0x00631c14, 0x00631d14)` | `0x00406890` uses the shared IJG `jpeg_natural_order` table and limit/end address, alongside reader/entropy family references. |
| `b014-0000vz-bytes-natural-order` | `get_bytes(0x00631c14, 0x00631d14)` | `0x00631c14` starts with the canonical natural-order sequence `0, 1, 8, 16, 9, 2...`; `0x00631d14` begins repeated `63` sentinel entries. |

No MCP timeout or unavailability occurred in this pass. No fallback-only evidence is used.

## Range And Boundary Analysis

The correct source-bearing range is `0x004064a0-0x00406d90` half-open.

Evidence:

- Predecessor [UID:0000VY] `jutils.c` ends with `jzero_far` at `0x00406480`, size `0x1b`, ending at `0x0040649b`.
- `get_bytes(0x00406490, 32)` shows the `jzero_far` tail and return, then five `0x90` bytes at `0x0040649b-0x004064a0`, then the `0x004064a0` function prologue.
- `entity_query` lists `0x004064a0` as the first target function and `0x00406d90` as the next source-file successor after `0x00406d10`.
- `lookup_funcs(0x00406d8c)` returns containing function `sub_406D10`, size `0x80`; this function starts at `0x00406d10` and ends at `0x00406d90`.
- `get_bytes(0x00406d8c, 16)` returns `5f 5e 5b c3 56 8b 74 24 08 6a 00 56 e8 c3 ab 00`. The first four bytes are the `sub_406D10` epilogue/return, and the next byte `0x56` at `0x00406d90` starts `sub_406D90`.
- [UID:0000W0] `jcinit.c` starts at `0x00406d90`; there is no padding gap between `jcmarker.c` and `jcinit.c`.

Current support docs that say `0x00406d8c-0x00406d90` is alignment are therefore stale. That span is source code belonging to `jcmarker.c` `write_tables_only`.

## Function Mapping And Behavior Evidence

Live IDA names remain generated, but current MCP decompilation and the staged source map the functions cleanly:

| Binary range | IDA name | IJG `jcmarker.c` function | Evidence |
| --- | --- | --- | --- |
| `0x004064a0-0x004064f1` | `sub_4064A0` | `jinit_marker_writer` | Allocates `32` bytes, stores marker writer at compressor offset `332`, installs callback pointers, and zeroes private state. Source anchor line 645. |
| `0x00406500-0x0040653e` | `sub_406500` | `write_marker_header` | Checks `datalen > 65533`, raises error code `11`, emits marker and length `datalen + 2`. Source anchor line 438. |
| `0x00406540-0x00406560` | `sub_406540` | `emit_marker` | Emits prefix byte `255` then marker value through `emit_byte`. Source anchor line 122. |
| `0x00406560-0x0040659c` | `sub_406560` | `emit_byte` | Writes to destination `next_output_byte`, decrements `free_in_buffer`, calls `empty_output_buffer`, raises error code `24` if suspension would be needed. Source anchor line 108. |
| `0x004065a0-0x004065c8` | `sub_4065A0` | `emit_2bytes` | Emits high byte then low byte. Source anchor line 131. |
| `0x004065d0-0x004065e3` | `sub_4065D0` | `write_marker_byte` | Public callback wrapper around `emit_byte`. Source anchor line 450. |
| `0x004065f0-0x0040663a` | `sub_4065F0` | `write_file_header` | Emits SOI (`216 = 0xd8`, verified with `int_convert.py`), clears `last_restart_interval`, optionally emits JFIF and Adobe markers. Source anchor line 469. |
| `0x00406640-0x004066e5` | `sub_406640` | `emit_jfif_app0` | Emits APP0 (`224 = 0xe0`), length `16`, literal bytes for `JFIF`, version/density fields, and zero thumbnail size. Source anchor line 349. |
| `0x004066f0-0x00406782` | `sub_4066F0` | `emit_adobe_app14` | Emits APP14 (`238 = 0xee`), length `14`, literal bytes for `Adobe`, version `100`, zero flags, color transform `1`/`2`/`0` by JPEG color space. Source anchor line 384. |
| `0x00406790-0x00406887` | `sub_406790` | `write_frame_header` | Emits DQT tables, detects baseline/progressive/arithmetic mode, and chooses SOF marker `0xc9`, `0xc2`, `0xc0`, or `0xc1`. Source anchor line 494. |
| `0x00406890-0x00406963` | `sub_406890` | `emit_dqt` | Validates quant table, detects 8-bit versus 16-bit precision, emits DQT (`219 = 0xdb`), walks `jpeg_natural_order`, and sets table-sent byte. Source anchor line 144. |
| `0x00406970-0x00406a28` | `sub_406970` | `emit_sof` | Emits SOF marker, checks width/height against `65535`, writes data precision, dimensions, component count, component ids, sampling, and quant table selectors. Source anchor line 277. |
| `0x00406a30-0x00406b08` | `sub_406A30` | `write_scan_header` | Emits DAC or DHTs, emits DRI only if restart interval changed, updates `last_restart_interval`, then emits SOS. Source anchor line 551. |
| `0x00406b10-0x00406bcc` | `sub_406B10` | `emit_dht` | Selects DC/AC Huffman table, raises error code `50` for missing table, emits DHT (`196 = 0xc4`), writes bits and huffval arrays, and sets sent flag. Source anchor line 184. |
| `0x00406bd0-0x00406bd1` | `nullsub_1` | `emit_dac` no-op | One-byte no-op body is consistent with `emit_dac` compiled with `C_ARITH_CODING_SUPPORTED` disabled; source anchor line 222. |
| `0x00406be0-0x00406c0a` | `sub_406BE0` | `emit_dri` | Emits DRI (`221 = 0xdd`), fixed length `4`, and restart interval. Source anchor line 265. |
| `0x00406c10-0x00406ced` | `sub_406C10` | `emit_sos` | Emits SOS (`218 = 0xda`), length `2 * comps_in_scan + 6`, component selectors, table selectors, and progressive spectral/refinement fields. Source anchor line 308. |
| `0x00406cf0-0x00406d03` | `sub_406CF0` | `write_file_trailer` | Emits EOI (`217 = 0xd9`). Source anchor line 602. |
| `0x00406d10-0x00406d90` | `sub_406D10` | `write_tables_only` | Emits SOI, all unsent DQT tables, all unsent DHT tables when not arithmetic-coded, then EOI at `0x00406d8c`; source anchor line 616. |

Important correction to current docs: `0x00406d10` is `write_tables_only`, not `write_file_header`. `write_file_header` is `0x004065f0`.

## Caller, Callee, And Reachability Evidence

The marker writer is reached through stock IJG compression setup:

- `xrefs_to(0x004064a0)` reports code xrefs from `0x00403ca2` and `0x00406e2c`.
- `callees(0x00406d90)` reports the compression-module initializer sequence ending with `0x004064a0`.
- `xrefs_to(0x00406d90)` reports code xref from `0x004047e5` inside `0x004047a0`.
- `analyze_function(0x004047a0)` shows a `jpeg_start_compress`-style state check, optional `sub_403A10`, virtual `cconvert`/destination prep calls, then `sub_406D90`, then a marker callback through compressor offset `316`. Its only reported caller is product wrapper `sub_4EFBC0`.
- [UID:00018N] `JpegScreenshotWriter` is therefore a product wrapper using public IJG compression APIs. It is not an owner for the marker-writer internals.

Within the marker-writer cluster:

- `analyze_component` reports `0x004064a0` as the only interface function and the remaining target functions as internal-only.
- Callback setup in `0x004064a0` installs:
  - `0x004065f0` as `write_file_header`
  - `0x00406790` as `write_frame_header`
  - `0x00406a30` as `write_scan_header`
  - `0x00406cf0` as `write_file_trailer`
  - `0x00406d10` as `write_tables_only`
  - `0x00406500` as `write_marker_header`
  - `0x004065d0` as `write_marker_byte`
- The local call graph contains only marker emit helpers and table emit helpers, with no product/UI/resource imports or NexusTK-specific state.

## Touched State And Data Dependencies

The target is stock third-party library code operating on IJG compressor structures:

- `0x004064a0` stores the allocated marker writer pointer at compressor offset `332` and zeroes its private restart-interval field.
- `emit_byte` uses the destination manager pointer at compressor slot `a1[6]`, writing `next_output_byte`, decrementing `free_in_buffer`, and invoking `empty_output_buffer`.
- `emit_dqt` reads quant table pointers, the sent-table flag at table offset `128`, and the shared `jpeg_natural_order` table.
- `xrefs_to(0x00631c14)` reports the `emit_dqt` xref at `0x00406912` plus related libjpeg reader/entropy references.
- `get_bytes(0x00631c14)` shows the canonical natural-order integer sequence, and `0x00631d14` begins repeated `63` sentinel entries. This is stock IJG `jutils.c` const data, not NexusTK product global state.
- `write_scan_header` uses scan component pointers, Huffman table fields, progressive parameters, arithmetic-mode flags, restart interval, and the marker writer private last-restart state.

No strings are used in this target; literal emitted bytes are JPEG marker bytes and APP marker identifiers from stock `jcmarker.c`.

## Positive Evidence Summary

- Current MCP was live and healthy for this evidence pass; session `80de0a67` served IDB-backed function, xref, byte, and decompiler requests.
- Staged source `source-3/third_party_embeds/libjpeg/jcmarker.c` is present, sourced from the project-approved IJG libjpeg 6b static embed, and its function bodies align with every target function.
- `jinit_marker_writer` callback installation exactly matches IJG `struct jpeg_marker_writer`.
- Boundary bytes prove the current end should be `0x00406d90` half-open, not `0x00406d8c`.
- Product use routes through `jpeg_start_compress` and [UID:00018N] screenshot wrapper; that is consumer evidence, not product ownership.
- Existing [UID:0000KN] and [UID:0000VP] docs already establish the third-party `third_party/libjpeg/` source root and static-embed marker policy.

## Negative Evidence And Rejected Alternatives

- NexusTK product owner rejected: no UI/render/DAT/resource strings, product globals, game protocol state, or product-specific callers exist inside this range. Product code reaches it through public libjpeg compression APIs.
- [UID:00018N] ImageWriters ownership rejected: the screenshot writer consumes libjpeg through public APIs; it should not own IJG marker internals.
- [UID:0000VP] broad parent as emitter rejected: [UID:0000VP] is now a non-emitting split/index. The source-bearing child [UID:0000VZ] should emit the static-embed marker through [UID:0000KN].
- Function-level child splitting rejected for this pass: the entire range is one stock source file, `jcmarker.c`. Splitting each static helper into by-memory children would fragment a verified third-party source unit and create unnecessary `[[CHILDREN]]` routing when the correct rebuild unit is the upstream file.
- Pasting upstream C or Hex-Rays C++ rejected: project policy for stock static embeds is a one-line formal marker that points to staged source. Pasting the full upstream file into the by-memory page would duplicate third-party source and risk drift.
- Current `0x00406d8c-0x00406d90` padding claim rejected: those bytes are `pop edi; pop esi; pop ebx; ret`, the epilogue of `write_tables_only`.

## Heuristic / Inference Reanalysis And Validation

Source placement:

- Confirmed/very strong: `third_party/libjpeg/jcmarker.c`.
- Evidence: live function inventory, callback layout, marker semantics, staged IJG source anchors, LibJPEG source-root docs, and neighboring `jutils.c`/`jcinit.c` boundaries.
- Remaining uncertainty: exact compiler options, object order decisions, and disabled feature macros are not byte-for-byte rebuilt yet. This caps the target below `95`, but it does not block the ownership/range/source decision.

Range repair:

- Confirmed: target should be represented as `0x004064a0-0x00406d90`.
- Evidence: `lookup_funcs(0x00406d8c)` returns `sub_406D10`; function size `0x80`; bytes at `0x00406d8c` are the function epilogue; successor prologue begins at `0x00406d90`.
- Rejected alternative: keep filename `0x004064a0-0x00406d8c` and explain that `0x00406d8c` is an observed tail address. This conflicts with current half-open filename practice used by adjacent files and makes support docs record a false padding gap.

Placeholder names:

- IDA labels `sub_4064A0` through `sub_406D10`, `nullsub_1`, and `dword_631C14` should not become final source-facing names.
- Best source names are the stock IJG names listed in the function map. `nullsub_1` is specifically `emit_dac` compiled to a no-op when arithmetic coding support is absent.
- `dword_631C14` is `jpeg_natural_order`; do not document it as a NexusTK global.

Formal C++ readiness:

- Ready for a static-embed marker, not a pasted source body.
- [UID:0000VZ] is `RECONSTRUCTABLE:TRUE`, has emitter [UID:0000KN], and already clears the combined-score C++ gate. Once the range is corrected and the function map is documented, a one-line formal marker is the best source form.

## Ranked Ownership And Source-Placement Decision

1. [UID:0000KN] `LibJPEG`, `third_party/libjpeg/jcmarker.c` - accepted. This is stock IJG libjpeg 6b marker-writer code and should rebuild from the staged static embed.
2. [UID:0000VP] `LibJpeg6bCore` - rejected as direct emitter/owner for this source body. It is useful as the non-emitting library index and source-file map, not as a generated C++ source unit.
3. [UID:0000K4] `ImageWriters` / [UID:00018N] `JpegScreenshotWriter` - rejected. They are product consumers of public compression APIs.
4. Standalone new by-file or by-memory helper page - rejected. The current [UID:0000KN] source root and [UID:0000VZ] source-file child are sufficient; only a range rename and evidence/code update are needed.

## Score And Metadata Recommendation

Recommended after implementation:

- Rename path/title/range to `0x004064a0-0x00406d90.LibJpegMarkerWriter`.
- `COMPLETION:90`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000KN`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KN`
- blank `EMITTER_POSITION_OPTIONAL`
- `Nested:0`
- update item summary to a concise source/evidence summary, for example:

```text
IJG libjpeg 6b `jcmarker.c` static-embed marker writer; live MCP confirms callback setup, marker/table emitters, SOI/SOS/EOI/table-only paths, `jpeg_natural_order` use, and corrected half-open end `0x00406d90`.
```

Score rationale:

- Completion `90`: the accepted implementation would document exact function map, corrected range, predecessor/successor boundaries, callback layout, marker/table semantics, data dependencies, owner/source route, rejected alternatives, and formal static-embed marker. It stays below `95` because no byte-for-byte rebuild/object comparison or final compiler-option audit is complete.
- Confidence `92`: source identity, range, and ownership are strongly supported by live MCP and staged IJG source. It stays below `95` because local build flags and exact original object packaging remain inferred from stock libjpeg 6b rather than proven by original build metadata.

## Formal Reconstruction C++ Recommendation

Use exact formal `RECONSTRUCTION_CPP CODE` content:

```cpp
// Static embed: third_party_embeds/libjpeg/jcmarker.c
```

Do not paste the upstream C body or decompiler-shaped C++ into this page. The static embed file is the source of record.

## Recommended Target And Support Doc Changes

Target doc:

- Rename `by-memory/0x004064a0-0x00406d8c.LibJpegMarkerWriter.md` to `by-memory/0x004064a0-0x00406d90.LibJpegMarkerWriter.md` without changing UID.
- Update title, range role, function mapping, evidence notes, boundary notes, score rationale, item summary, and change log to the current evidence above.
- Replace the stale `0x00406d10-0x00406d8c` "`write_file_header` / table emission path" row with `0x00406d10-0x00406d90` `write_tables_only`.
- Add exact formal static-embed marker.

Support docs that should be updated if the report is accepted:

- `by-file/LibJPEG.md`
  - Update the [UID:0000VZ] source-file coverage row to `0x004064a0-0x00406d90`.
  - Note that [UID:0000VZ] now uses the formal marker `// Static embed: third_party_embeds/libjpeg/jcmarker.c`.
- `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`
  - Update the child map row for [UID:0000VZ] to `0x004064a0-0x00406d90`.
  - Correct boundary notes: `0x00406d8c-0x00406d90` is not alignment; there is no gap between [UID:0000VZ] and [UID:0000W0].
  - Add/retain static-embed policy for this existing source-bearing child.
- `by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md`
  - Update cross-reference target annotation/path/range for [UID:0000VZ] after the rename.
  - Keep its own range unchanged.
- `by-memory/0x00406d90-0x00406e46.LibJpegCompressMasterInit.md`
  - Update cross-reference target annotation/path/range for [UID:0000VZ] after the rename.
  - Keep its own range unchanged.
- `by-meta/client_libraries.md`
  - Update IJG libjpeg section references from `0x004064a0-0x00406d8c` to `0x004064a0-0x00406d90` and mention the `jcmarker.c` static-embed marker if the section lists marker routes.
- `by-project-structure/proposed-source-tree.md`
  - Read-only by default for B agents unless the supervisor explicitly includes it in the implementation callback. If included, update the [UID:0000VZ] path/range mention in the `third_party/libjpeg/` rationale.

Generated/manual coverage:

- Do not edit `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `project-level/*`, or any manual `-coverage-report.md` during normal B-agent implementation.
- The legacy manual `by-memory/-coverage-report.md` row for [UID:0000VZ] is stale, but no manual row text is requested here. Validator-owned generated reports should refresh from source docs after validation/execution.

## Expected Validators After Accepted Implementation

Run from `source-3/project-documentation` after edits, one scoped command at a time:

> Executable block R001 was removed from this report and preserved verbatim in [0000VZ-LibJpegMarkerWriter-source-quality-removed.md](0000VZ-LibJpegMarkerWriter-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If `by-project-structure/proposed-source-tree.md` is explicitly included by the supervisor callback, validate that file using the appropriate scoped validator pattern requested by the supervisor.

If validator reports a stale old path after the rename, use documented validator lifecycle commands rather than editing `tools/validator.ini` or generated state by hand.

Report each validator command, `command_id`, `command_timestamp`, exit code, `ok` count, generated-refresh status, and any generated-header freshness checks that matter to the supervisor.

## Remaining Open Questions

No target-scope blocker remains for source placement, owner/emitter, range repair, or static-embed C++ marker insertion.

Non-blocking caveats that cap scores below final audit:

- No exact original compiler-option or object-file ordering proof was found beyond the stock IJG source map and live binary shape.
- No byte-for-byte rebuild comparison of `jcmarker.c` has been performed.
- Existing broad generated tracker rows are stale relative to the target header and should be refreshed through validator/report execution.

These caveats do not justify leaving the range uncorrected or the formal static-embed marker blank.

## Implementation Tracking Checklist

- [x] Lease only the immediate files approved by the supervisor callback when ready to edit.
  - Proof: B014 leased the renamed target/support set through `tools/leaser/leaser.py`; after validators, `python .\leaser.py B014 unlease` released `by-file/LibJPEG.md`, [UID:0000VP], [UID:0000VY], [UID:0000VZ], [UID:0000W0], and `by-meta/client_libraries.md`. Final `current_leases.md` read after release contained no B014 entries.
- [x] Rename target file from `by-memory/0x004064a0-0x00406d8c.LibJpegMarkerWriter.md` to `by-memory/0x004064a0-0x00406d90.LibJpegMarkerWriter.md`, preserving [UID:0000VZ].
  - Proof: `Test-Path` returned `False` for the old path and `True` for the new path; validator command `000000003625` recorded `path_update ... was by-memory/0x004064a0-0x00406d8c.LibJpegMarkerWriter.md`.
- [x] Update [UID:0000VZ] metadata to `COMPLETION:90`, `CONFIDENCE:92`, unchanged `CANONICAL_OWNER:0000KN`, unchanged `RECONSTRUCTABLE:TRUE`, unchanged `EMITTER_UIDS:0000KN`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
  - Proof: target header now contains those values; validator `000000003625` recorded `completion_update 90`, `confidence_update 92`, `canonical_owner_update 0000KN`, and autogen registry updates for [UID:0000VZ].
- [x] Update [UID:0000VZ] item summary to mention IJG `jcmarker.c`, live callback/table/SOI/SOS/EOI evidence, and corrected half-open end `0x00406d90`.
  - Proof: target `Item Summary` now names IJG libjpeg 6b `jcmarker.c`, callback setup, marker/table emitters, SOI/SOS/EOI/table-only paths, `jpeg_natural_order`, and corrected half-open end.
- [x] Insert exact formal reconstruction code in [UID:0000VZ]:
  ```cpp
  // Static embed: third_party_embeds/libjpeg/jcmarker.c
  ```
  - Proof: the formal `RECONSTRUCTION_CPP CODE` block contains exactly that marker; validator `000000003625` recorded the target code state changing from blank to block.
- [x] Replace [UID:0000VZ] function map with the detailed current mapping for `jinit_marker_writer`, `write_marker_header`, `emit_marker`, `emit_byte`, `emit_2bytes`, `write_marker_byte`, `write_file_header`, `emit_jfif_app0`, `emit_adobe_app14`, `write_frame_header`, `emit_dqt`, `emit_sof`, `write_scan_header`, `emit_dht`, `emit_dac` no-op, `emit_dri`, `emit_sos`, `write_file_trailer`, and `write_tables_only`.
  - Proof: target `Function Mapping` table now lists all accepted binary ranges, IDA labels, IJG names, and source anchors.
- [x] Correct [UID:0000VZ] boundary evidence: `0x0040649b-0x004064a0` is NOP padding before the target; `0x00406d8c-0x00406d8f` is target epilogue/return; `0x00406d90` is the [UID:0000W0] successor.
  - Proof: target `Range Role`, `MCP And Source Evidence`, and `Changes` sections record these boundary facts; [UID:0000VP] and [UID:0000W0] support docs also record the no-gap correction.
- [x] Preserve positive evidence, negative evidence, rejected alternatives, `jpeg_natural_order` data dependency, screenshot-wrapper consumer route, and no-product-owner reasoning in [UID:0000VZ] at report-level detail.
  - Proof: target now has `MCP And Source Evidence`, `Call Flow And Touched State`, `Ownership Decision`, and `Negative Evidence And Rejected Alternatives` sections covering those report facts.
- [x] Update `by-file/LibJPEG.md` [UID:0000VZ] row/path/range to `0x004064a0-0x00406d90` and record the static-embed marker status.
  - Proof: [UID:0000VZ] source-file coverage row now points to `by-memory/0x004064a0-0x00406d90.LibJpegMarkerWriter.md`, range `0x004064a0-0x00406d90`, and notes the formal `jcmarker.c` static-embed route.
- [x] Update `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md` child row/path/range for [UID:0000VZ] and remove/correct the stale `0x00406d8c-0x00406d90` alignment note.
  - Proof: child row now uses the corrected path/range; boundary row no longer lists `0x00406d8c-0x00406d90` as an alignment span and instead states those bytes are `write_tables_only` epilogue/return.
- [x] Update `by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md` cross-reference annotation/path/range for [UID:0000VZ] after rename.
  - Proof: cross-reference now points to `0x004064a0-0x00406d90.LibJpegMarkerWriter`, with a B014 successor note preserving the `0x0040649b-0x004064a0` padding fact.
- [x] Update `by-memory/0x00406d90-0x00406e46.LibJpegCompressMasterInit.md` cross-reference annotation/path/range for [UID:0000VZ] after rename.
  - Proof: predecessor reference now points to `0x004064a0-0x00406d90.LibJpegMarkerWriter`; range role and change note state that [UID:0000W0] starts at `0x00406d90` after [UID:0000VZ]'s epilogue.
- [x] Update `by-meta/client_libraries.md` IJG libjpeg section references for [UID:0000VZ] to the corrected `0x004064a0-0x00406d90` path/range and static-embed marker if the section lists source-bearing child routes.
  - Proof: IJG libjpeg source-file bullet and cross-reference now use the corrected path/range and name `// Static embed: third_party_embeds/libjpeg/jcmarker.c`; the dependency table static-embed examples include B014's `jcmarker.c` child.
- [x] If and only if the supervisor explicitly includes `by-project-structure/proposed-source-tree.md`, update its [UID:0000VZ] path/range mention to `0x004064a0-0x00406d90`.
  - Proof: no exact stale [UID:0000VZ] path/range mention was found in `by-project-structure/proposed-source-tree.md` during the scoped `rg`; the file was not edited.
- [x] Do not edit generated reports, project-level generated files, validator/tool state, or any manual `-coverage-report.md` file. Let generated state refresh through validator/report execution.
  - Proof: no manual edits were made to generated/project-level/coverage/tool-state files. Validator commands reported their normal generated/projected-stat/reference side effects, including deferred generated refresh and UID-link propagation; those were tool-driven, not hand edits.
- [x] Run scoped validators listed in `Expected Validators After Accepted Implementation` and record command, `command_id`, `command_timestamp`, exit code, `ok` count, and generated-refresh state.
  - Proof:
    - `python .\tools\validator.py --mode file --file by-memory/0x004064a0-0x00406d90.LibJpegMarkerWriter.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000003625`, `command_timestamp: 2026-06-26T23:12:04-04:00`, `ok: 1`, `generated_refresh: deferred`.
    - `python .\tools\validator.py --mode file --file by-file/LibJPEG.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000003630`, `command_timestamp: 2026-06-26T23:12:23-04:00`, `ok: 1`, `generated_refresh: deferred`.
    - `python .\tools\validator.py --mode file --file by-memory/0x00401000-0x00414283.LibJpeg6bCore.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000003631`, `command_timestamp: 2026-06-26T23:12:32-04:00`, `ok: 1`, `generated_refresh: deferred`.
    - `python .\tools\validator.py --mode file --file by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000003632`, `command_timestamp: 2026-06-26T23:12:47-04:00`, `ok: 1`, `generated_refresh: deferred`.
    - `python .\tools\validator.py --mode file --file by-memory/0x00406d90-0x00406e46.LibJpegCompressMasterInit.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000003633`, `command_timestamp: 2026-06-26T23:13:06-04:00`, `ok: 1`, `generated_refresh: deferred`.
    - `python .\tools\validator.py --mode file --file by-meta/client_libraries.md --apply --queue-timeout 240` -> exit `0`, `command_id: 000000003637`, `command_timestamp: 2026-06-26T23:13:26-04:00`, `ok: 1`, `generated_refresh: deferred`.
- [x] If validator reports stale old path/UID registry state after the rename, use documented lifecycle commands; do not hand-edit `tools/validator.ini`, queue files, lock files, or generated Markdown.
  - Proof: validator `000000003625` handled the rename with `path_update`; no manual validator state edit and no lifecycle cleanup command were needed.
- [x] Report execution and archival remain supervisor-owned; executable lifecycle syntax is intentionally omitted from the research report.
  - Proof: the validator-owned report history below records the completed supervisor lifecycle action.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B014","command_id":"000000004165","destination_path":"executed-b-agent-research/B014/0000VZ-LibJpegMarkerWriter-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B014/research/0000VZ-LibJpegMarkerWriter-source-quality.md","timestamp":"2026-06-26T23:17:31","uid":"0000VZ"} -->
<!-- {"agent":"B014","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000VZ-LibJpegMarkerWriter-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B014/0000VZ-LibJpegMarkerWriter-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000VZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
