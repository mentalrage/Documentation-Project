** TARGET-REPORT-UID:0000VX **
** AUTHOR-AGENT-ID:B008 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0000VX] LibJpegDecompressMaster Source-Quality Report

Agent: Agent-B008
Assignment: `B008-report-0000VX-libjpeg-decompress-master-source-quality-20260626`
Target: [UID:0000VX] `by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md`
Mode: report-only research. No by-* docs, generated files, coverage reports, validator state, tool state, IDA DB, or leases were edited.

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000VX] owned and emitted by [UID:0000KN] `LibJPEG`, keep it reconstructable, and replace the blank formal C++ block with the exact static-embed marker for staged `third_party_embeds/libjpeg/jdmaster.c`.
- Final disposition: exact source-file child for stock IJG libjpeg 6b `jdmaster.c`; not NexusTK product wrapper code; no split or merge needed.
- Required action after supervisor acceptance: update [UID:0000VX] target prose/metadata/formal block and compactly refresh [UID:0000KN], [UID:0000VP], and [UID:0001QE] support docs with the current MCP/source-provenance facts.
- Confidence: strong. Current MCP session `80de0a67`, staged-source hashes, source line anchors, range boundaries, xrefs, and support docs agree.

## Target

- Target UID: `0000VX`
- Target path: `by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md`
- Required report path: `tools/leaser/Agents/Agent-B008/research/0000VX-LibJpegDecompressMaster-source-quality.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md`, `## by-memory` -> `### Not-Covered Files - Reconstructable`; read-only row still shows stale `80/85` for [UID:0000VX].
- Current supervisor classification: source-quality report-only research for reconstructable not-covered by-memory target.
- Current target header at report time: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000KN`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KN`, blank `EMITTER_POSITION_OPTIONAL`, blank formal `RECONSTRUCTION_CPP CODE`, `Nested:0`.
- Current generated state observed read-only: `auto-generated/-ag-memory-coverage.md` shows [UID:0000VX] as `emits` but `coded:no`; `auto-generated/-ag-coverage-report-by-memory.md` shows `emits_code:false` and stale `80%`; generated `auto-generated/NexusTK/third_party/libjpeg/LibJPEG.cpp` command `000000003537` still emits an empty marker for [UID:0000VX].

## Current Target State

[UID:0000VX] already correctly identifies the range as IJG libjpeg decompression master controller code from `jpeg-6b/jdmaster.c`. It lists the eight stock functions in the range and keeps ownership/emission routed through [UID:0000KN] `LibJPEG`.

The remaining source-quality gap is the formal code route. The page still has a blank formal C++ block and old wording that final source emission remains blank because this is third-party code and source-quality declaration details are not final. Current project policy and neighboring accepted libjpeg reports now use one-line static-embed marker comments for exact source-bearing third-party children. [UID:0000VX] has the same source-file certainty and emitter route, so keeping the formal block blank is stale.

No target open question requires a split. Current live MCP checks confirm `0x00405c80-0x004063c8` contains exactly the modeled `jdmaster.c` function bodies, padding, and the `jutils.c` successor at `0x004063d0`.

Related docs checked:

- [UID:0000KN] `by-file/LibJPEG.md`
- [UID:0000VP] `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`
- [UID:0000VV] `by-memory/0x00404a60-0x0040505b.LibJpegInputController.md`
- [UID:0000VW] `by-memory/0x00405060-0x00405c77.LibJpegMemoryManager.md`
- [UID:0000VY] `by-memory/0x004063d0-0x0040649b.LibJpegUtilityHelpers.md`
- [UID:0001QE] `by-meta/client_libraries.md`
- [UID:0001QY] `by-meta/obtained_thirdparty_files/static_embeds/README.md`
- `source-3/third_party_embeds/libjpeg/jdmaster.c`
- `by-meta/obtained_thirdparty_files/static_embeds/libjpeg-6b/jdmaster.c`

## Executive Recommendation

Keep [UID:0000VX] as an exact source-bearing third-party child:

- `COMPLETION:90`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000KN`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KN`
- blank `EMITTER_POSITION_OPTIONAL`
- formal block content exactly:

```cpp
// Static embed: third_party_embeds/libjpeg/jdmaster.c
```

Recommended item summary:

`Static IJG libjpeg 6b jdmaster.c decompression master controller from staged third_party_embeds/libjpeg/jdmaster.c.`

Do not paste upstream `jdmaster.c` into the by-memory page. The staged source file is the source body for rebuilds; the by-memory formal block should only route the static embed.

## Supervisor Active Recheck

- Supervisor instruction required report-only research first and explicitly forbade by-* edits, generated/report edits, coverage-report edits, tool-state edits, IDA DB edits, and leases.
- Split execution was not permitted by the assignment, so this report supplies implementation-ready changes rather than applying them.
- Split repair is not required: live MCP function inventory and boundary lookups support the existing exact source-file child. No mixed product/library ownership was found inside the target range.

## IDA MCP Session And Tool Facts

MCP was available and used. This report is not fallback-only.

- Listener check: `127.0.0.1:13337` was listening, owning process `13684`.
- `initialize` / `tools/list`: server `ida-pro-mcp` version `1.0.0`; tools included read-only analysis tools plus write tools that were not used.
- `idb_list`: active session `80de0a67`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, backend `worker`, PID `26892`, `is_analyzing:false`, `is_active:true`.
- `b008-0000VX-health-20260626T2215`: `server_health(database=80de0a67)` returned `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready with `2067` strings.

Read-only MCP calls used for target evidence:

- `b008-0000VX-function-range-20260626T2216`: `entity_query(kind=functions, min_addr=0x00405c70, max_addr=0x004063e0)`
- `b008-0000VX-lookup-boundaries-20260626T2217`: `lookup_funcs` on function heads and boundary endpoints
- `b008-0000VX-bytes-boundaries-20260626T2218`: `get_bytes` around `0x00405c70` and `0x00406390`
- `b008-0000VX-analyze-compact-*-20260626T2235`: `analyze_function` for all eight target function heads
- `b008-0000VX-xrefs-heads-20260626T2228`: `xrefs_to` for all eight target function heads
- `b008-0000VX-callees-master-selection-20260626T2229`: `callees` for `0x00405fe0`, `0x00406240`, `0x00405c80`, and `0x00405fa0`

## Evidence Checked

IDA MCP/manual-disassembly/raw-byte checks:

- Function inventory from `0x00405c70-0x004063e0`.
- Boundary lookups for `0x00405c77`, `0x00405c80`, every target function head, target end `0x004063c8`, and successor `0x004063d0`.
- Boundary bytes before `0x00405c80` and across `0x00406390-0x004063df`.
- Per-function `analyze_function` summaries, callers, callees, complexity, and filtered decompiler evidence.
- Xrefs to each target function head.
- Callees from `master_selection`, `jpeg_calc_output_dimensions`, and `jinit_master_decompress`.

Local source and documentation checks:

- `source-3/third_party_embeds/libjpeg/jdmaster.c`
- `by-meta/obtained_thirdparty_files/static_embeds/libjpeg-6b/jdmaster.c`
- `by-meta/obtained_thirdparty_files/static_embeds/SHA256SUMS.txt`
- `by-meta/obtained_thirdparty_files/SHA256SUMS.txt`
- `by-meta/obtained_thirdparty_files/static_embeds/README.md`
- `by-meta/obtained_thirdparty_files/README.md`
- `auto-generated/NexusTK/third_party/libjpeg/LibJPEG.cpp`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- Neighbor/support pages listed in Current Target State.

Negative checks performed:

- `lookup_funcs` returned `Not a function` for the exclusive target end `0x004063c8`; successor `0x004063d0` is a separate `jutils.c` function head.
- `lookup_funcs` returned `Not a function` for predecessor end `0x00405c77`; the next head is `0x00405c80`.
- `xrefs_to` found no current code/data xrefs to `0x00405f30` (`jpeg_new_colormap`), which is expected for a retained public buffered-image API not used by product wrappers.
- Product-owned JPEG decode/write wrappers were checked through support docs and remain outside this target. No evidence supports assigning this range to `ImageLoaders`, `ImageWriters`, screenshots, render, DAT, Browser, zlib, or Miles.

Failed/unavailable checks:

- None. MCP remained available for this pass. No write tools were used.

## IDA MCP Facts

Function/range facts from `b008-0000VX-function-range-20260626T2216`:

| Address | IDA name | Size | Source-facing function |
| --- | --- | --- | --- |
| `0x00405c80` | `sub_405C80` | `0x20c` | `jpeg_calc_output_dimensions` |
| `0x00405ea0` | `sub_405EA0` | `0x83` | `use_merged_upsample` |
| `0x00405f30` | `sub_405F30` | `0x6f` | `jpeg_new_colormap` |
| `0x00405fa0` | `sub_405FA0` | `0x31` | `jinit_master_decompress` |
| `0x00405fe0` | `sub_405FE0` | `0x1dc` | `master_selection` |
| `0x004061c0` | `sub_4061C0` | `0x79` | `prepare_range_limit_table` |
| `0x00406240` | `sub_406240` | `0x153` | `prepare_for_output_pass` |
| `0x004063a0` | `sub_4063A0` | `0x28` | `finish_output_pass` |
| `0x004063d0` | `sub_4063D0` | `0x10` | `jdiv_round_up`, successor in [UID:0000VY] |
| `0x004063e0` | `sub_4063E0` | `0x18` | `jround_up`, successor in [UID:0000VY] |

Boundary facts:

- `0x00405c77` is not a function; bytes at `0x00405c77-0x00405c7f` are NOP padding before the `0x00405c80` function prologue.
- `0x00406390-0x00406393` ends `prepare_for_output_pass`, followed by NOP padding through `0x0040639f`.
- `0x004063a0-0x004063c7` is `finish_output_pass`.
- `0x004063c8-0x004063cf` is padding.
- `0x004063d0` starts `jdiv_round_up` in [UID:0000VY] `LibJpegUtilityHelpers`.

Xref facts from `b008-0000VX-xrefs-heads-20260626T2228`:

| Target | Xrefs |
| --- | --- |
| `0x00405c80` | code xref at `0x00405fee` inside `master_selection` |
| `0x00405ea0` | code xrefs at `0x00405e6e` inside `jpeg_calc_output_dimensions` and `0x00405fff` inside `master_selection` |
| `0x00405f30` | no xrefs |
| `0x00405fa0` | code xref at `0x004016ef` inside `0x004016e0` (`jpeg_start_decompress` source-family page [UID:0000VQ]) |
| `0x00405fe0` | code xref at `0x00405fc7` inside `jinit_master_decompress` |
| `0x004061c0` | code xref at `0x00405ff4` inside `master_selection` |
| `0x00406240` | data xref at `0x00405fb6` inside `jinit_master_decompress` callback installation |
| `0x004063a0` | data xref at `0x00405fbc` inside `jinit_master_decompress` callback installation |

Callee facts from `b008-0000VX-callees-master-selection-20260626T2229`:

- `master_selection` calls `0x00405c80` (`jpeg_calc_output_dimensions`), `0x004061c0` (`prepare_range_limit_table`), `0x00405ea0` (`use_merged_upsample`), and the decompression pipeline initializers at `0x0040cc20`, `0x0040b820`, `0x0040b230`, `0x0040abc0`, `0x0040a440`, `0x0040a0d0`, `0x00409e10`, `0x004090b0`, `0x00408a60`, `0x004075c0`, and `0x00406ee0`.
- `jpeg_calc_output_dimensions` calls `0x004063d0` (`jdiv_round_up`) and `0x00405ea0` (`use_merged_upsample`).
- `jinit_master_decompress` calls `0x00405fe0` (`master_selection`).
- `prepare_for_output_pass` has no direct callees in the MCP callee listing because it dispatches through IJG callback tables.

Behavior facts from `analyze_function`:

- `0x00405c80` checks decompressor state value `202`, computes scaled output width/height through `jdiv_round_up`, assigns component `DCT_scaled_size` values, recomputes component downsampled dimensions, chooses output color component count, and sets `rec_outbuf_height` based on `use_merged_upsample`.
- `0x00405ea0` rejects merged upsample when fancy upsampling or CCIR601 sampling is enabled, when input/output color/component state is not YCbCr-to-RGB with three components, when sampling ratios are unsupported, or when DCT scaled sizes differ from the minimum.
- `0x00405f30` checks state value `207`, verifies quantize/external colormap state, selects the two-pass quantizer, calls the quantizer `new_color_map` callback indirectly, clears the dummy-pass flag, or raises mode-change errors.
- `0x00405fa0` allocates `28` bytes through the IJG memory manager, stores callback pointers `0x00406240` and `0x004063a0`, clears the dummy-pass byte, and calls `master_selection`.
- `0x00405fe0` performs output-dimension setup, prepares the range-limit table, validates output row width, selects quantizers, chooses merged upsampler versus color converter plus upsampler, initializes post, IDCT, entropy, coefficient, and main controllers, realizes virtual arrays, starts the input pass, and updates progress-monitor pass accounting.
- `0x004061c0` allocates the range-limit table, zero-fills the low clamp region, fills the identity region, fills the high clamp region with `0xff`, zeroes the second-half clamp region, and copies the center sample window.
- `0x00406240` selects dummy versus real output pass behavior, swaps quantizers when needed, starts IDCT/coefficient/color/upsample/quantizer/post/main passes through callback tables, and updates progress monitor pass counts.
- `0x004063a0` conditionally calls the color quantizer `finish_pass` callback when quantization is active and advances the master pass counter.

## Local Source Provenance

`source-3/third_party_embeds/libjpeg/jdmaster.c` and `by-meta/obtained_thirdparty_files/static_embeds/libjpeg-6b/jdmaster.c` both hash to:

`C9F18A007511047A50DB0B14C54E4D88C279571EC36824B70C3C20232EF7A8FE`

The obtained source archive `by-meta/obtained_thirdparty_files/archives/jpegsrc.v6b.tar.gz` hashes to:

`75C3EC241E9996504FE02A9ED4D12F16B74ADE713972F3DB9E65CE95CD27E35D`

`by-meta/obtained_thirdparty_files/static_embeds/SHA256SUMS.txt` records the same `jdmaster.c` file hash for `libjpeg-6b/jdmaster.c`. The static embeds README records `libjpeg-6b/` as sourced from `jpegsrc.v6b.tar.gz`, using the library object set from `makefile.vc`, `jmemnobs.c`, and `jconfig.h` copied from upstream `jconfig.vc` for a Windows-style build.

Relevant source line anchors from staged `jdmaster.c`:

| Source line | Function |
| ---: | --- |
| 44 | `use_merged_upsample` |
| 84 | `jpeg_calc_output_dimensions` |
| 248 | `prepare_range_limit_table` |
| 288 | `master_selection` |
| 438 | `prepare_for_output_pass` |
| 498 | `finish_output_pass` |
| 515 | `jpeg_new_colormap` |
| 543 | `jinit_master_decompress` |

This is stock IJG third-party code. The function names above are source-proven from the staged library source and should be used as source-facing names in documentation. IDA's `sub_405C80` style names should remain search aliases/evidence only.

## Heuristic / Inference Reanalysis And Validation

Issue: blank formal C++ block for an exact static third-party source child.

- Best inference/decision: [UID:0000VX] should emit the static-embed marker `// Static embed: third_party_embeds/libjpeg/jdmaster.c`.
- Evidence: target is `RECONSTRUCTABLE:TRUE`, has `EMITTER_UIDS:0000KN`, parent [UID:0000KN] is a valid source-root for `NexusTK/third_party/libjpeg/`, staged source exists and hash-matches the obtained static embed, current MCP confirms the exact source-file range, and neighboring accepted libjpeg children already use static-embed markers.
- Rejected alternative: keep formal C++ blank because the old page was below 95/95. Current by-structure policy no longer requires 95/95 for code entry, and static third-party source should use marker comments rather than empty emitters when the source file is exact.
- Rejected alternative: paste upstream `jdmaster.c` or decompiler-shaped C++. This would duplicate vendored source and pollute docs with third-party bodies; static-embed policy explicitly prefers marker comments.

Issue: source-file mapping and source-facing names.

- Best inference/decision: [UID:0000VX] is exact `jdmaster.c` and should use the source names `jpeg_calc_output_dimensions`, `use_merged_upsample`, `jpeg_new_colormap`, `jinit_master_decompress`, `master_selection`, `prepare_range_limit_table`, `prepare_for_output_pass`, and `finish_output_pass`.
- Evidence: staged source line anchors, current MCP function body/caller/callee behavior, callback installation at `0x00405fa0`, master-selection initializer fanout, and range-limit table construction all match the source file.
- Rejected alternative: keep IDA names as final source names. `sub_405C80` and related labels are only unsymbolized IDA names.

Issue: split/range repair.

- Best inference/decision: no split or merge is needed.
- Evidence: all eight modeled functions are from one IJG source file and bounded by padding before `jutils.c`. The public `jpeg_new_colormap` has no xrefs, but it is a normal retained public API in the same source file and should not be split into product-owned or ignored code.
- Rejected alternative: split `jpeg_new_colormap` because it has no xrefs. It is source-authored third-party API code retained by the linked library, not dead padding or product wrapper logic.
- Rejected alternative: merge into [UID:0000VY] `jutils.c` because `jpeg_calc_output_dimensions` calls `jdiv_round_up`. The call is a normal IJG utility dependency; source files remain distinct and the boundary at `0x004063d0` is clear.

Issue: product ownership.

- Best inference/decision: product wrappers call public libjpeg APIs, but [UID:0000VX] itself remains third-party IJG code.
- Evidence: support docs place product-facing decode wrappers in [UID:000175] and [UID:0000K3]; [UID:0000KN]/[UID:0000VP] own libjpeg internals; current xrefs show `jinit_master_decompress` is reached from the libjpeg decompression API family at `0x004016e0`.
- Rejected alternative: assign to image loaders, screenshot, render, DAT, Browser, zlib, or Miles. No current xref/behavior/source evidence supports those as direct owners.

Issue: score blockers.

- Resolved blocker: exact source-file path and function mapping are verified through current MCP and staged source.
- Resolved blocker: raw/unmodeled helper liveness does not apply inside the target range; all eight functions are modeled. The no-xref public API `jpeg_new_colormap` remains live as retained library source, not as an unmodeled helper.
- Resolved blocker: final C++ route is not blocked; it should be a static-embed marker.
- Remaining non-blocking uncertainty: whole-library rebuild fidelity still depends on compatible IJG 6b headers, `jconfig.h`, `jmorecfg.h` feature macros, and VC-era compile options. This is a [UID:0000KN]/[UID:0000VP] library-level caveat, not a blocker for [UID:0000VX]'s marker.

No Wave2/Wave3 source data was used as authority. Existing generated/autogen rows were used only as read-only stale-state observations.

## Inference Claim Ledger

| Claim | Confidence | Evidence | Counter-evidence checked | Next verification / remaining uncertainty |
| --- | --- | --- | --- | --- |
| [UID:0000VX] is stock IJG libjpeg 6b `jdmaster.c` | Strong | Staged `jdmaster.c` line anchors, SHA-256 match to obtained static embed, current MCP body/caller/callee/boundary checks | Product wrapper docs, generated empty-emitter state, predecessor/successor pages, and no-xref API branch checked | No target-local blocker; library-level compile config remains broader work |
| Existing range `0x00405c80-0x004063c8` is correct | Strong | MCP function inventory, boundary lookup, `0x004063c8` not a function, successor `0x004063d0`, NOP padding bytes | Merge with `jutils.c`, split no-xref public API, and predecessor memory-manager inclusion rejected | None for report implementation |
| Owner/emitter [UID:0000KN] remains correct | Strong | [UID:0000KN] source-root, [UID:0000VP] child map, `third_party/libjpeg/` source placement, public wrapper boundary docs | Image loader/writer/screenshot/render/zlib/Miles alternatives checked and rejected | None for target; parent compile options remain below 95 |
| Formal block should contain the static-embed marker | Strong | Current by-structure static embed rule, valid emitter route, staged source present, generated output currently empty | Blank block, pasted upstream C, and decompiler C++ alternatives rejected | Validator refresh after implementation should convert generated empty marker to static embed marker |
| `jpeg_new_colormap` no-xref state does not make the range non-reconstructable | Strong | Source file includes public API, MCP body matches stock behavior, no xrefs explicitly observed, range is source-authored third-party library code | Splitting/ignoring the no-xref function rejected | None for target; reachability is compile/link retention, not product call evidence |

## Positive Evidence Summary

- Current MCP confirms all modeled functions expected for `jdmaster.c` in the exact target range.
- `jinit_master_decompress` installs `prepare_for_output_pass` and `finish_output_pass` callbacks and calls `master_selection`, exactly matching the source file's controller initialization.
- `master_selection` calls output-dimension/range-limit helpers and the decompression pipeline initializers for quantizers, merged/color conversion, upsampling, post controller, IDCT, entropy, coefficient, and main controllers.
- `prepare_range_limit_table` allocates and fills the IJG sample clamp table, matching the source's table shape.
- The current source file exists in both the staged embed tree and obtained static embed tree with identical SHA-256.
- [UID:0000KN] already states source-bearing children should use static-embed marker comments only.
- [UID:0000VP] already lists [UID:0000VX] as `jdmaster.c` and treats the broad parent as a non-emitting split/index.

## Negative Evidence Summary

- No evidence supports assigning this range to product image loaders/writers or screenshot modules. Those are consumers/wrappers, not the source owner of IJG internals.
- No evidence supports leaving the formal C++ block empty after acceptance. The only reason it is empty is stale policy/generator state; target metadata already makes it eligible for a marker.
- No evidence supports a target split. `jpeg_new_colormap` has no xrefs, but it is a retained public source function in `jdmaster.c`, not padding or a different source owner.
- No evidence supports merging the successor `0x004063d0` helper family into [UID:0000VX]. It is `jutils.c`; bytes and function heads confirm a separate successor child.
- No evidence supports using IDA `sub_` names as final source-facing names. The staged source provides the proper IJG names.

## Ranked Ownership Analysis

### 1. [UID:0000KN] `LibJPEG`

- Evidence for: source-root page for IJG libjpeg 6b; target source file listed in [UID:0000KN] and [UID:0000VP]; staged source and current MCP agree; emitter route generates under `NexusTK/third_party/libjpeg/`.
- Evidence against: none target-specific. Broader compile configuration remains non-final, but it does not challenge ownership.
- Decision: accepted. Keep canonical owner and emitter `0000KN`.

### 2. [UID:0000VP] `LibJpeg6bCore`

- Evidence for: broad parent contains the whole libjpeg island and indexes [UID:0000VX].
- Evidence against: current parent is explicitly a non-emitting split/index with `RECONSTRUCTABLE:FALSE`; it is not a source root or direct emitter.
- Decision: support/index doc only, not direct owner/emitter replacement.

### 3. Product image loader/writer/screenshot modules

- Evidence for: product decode/write wrappers call libjpeg public APIs.
- Evidence against: [UID:0000VX] is internal IJG decompression master logic; no target body uses NexusTK product policy, resources, tile contexts, screenshot surfaces, or application callbacks; support docs keep wrappers outside libjpeg internals.
- Decision: rejected.

### 4. No-owner/non-emitting

- Evidence for: generated output currently shows empty emitter marker.
- Evidence against: target already has confirmed owner/emitter metadata, source file, staged source, and valid source root.
- Decision: rejected. The empty generated state is a stale formal-block issue, not an ownership blocker.

## Source Placement

Recommended source placement: `NexusTK/third_party/libjpeg/`, via [UID:0000KN] `LibJPEG` and staged `source-3/third_party_embeds/libjpeg/jdmaster.c`.

This placement fits the source-tree context because the code is unchanged IJG libjpeg 6b decompression master logic. Product-facing decode wrappers remain in image-loader/writer modules and should call the library rather than absorb internal controller code.

Rejected placements:

- `render/ImageLoaders.cpp` or product image decode wrappers: rejected because this target is not wrapper/conversion policy.
- `ImageWriters.cpp` or screenshot modules: rejected because this is decompression-side library code and not the JPEG writer path.
- Broad parent [UID:0000VP] emitted source: rejected because parent is a non-emitting split/index.
- A new source file: rejected because the source file is already known as `jdmaster.c`.

Remaining placement uncertainty: none for target ownership. Whole-library compile flags and headers remain library-level fidelity issues.

## Range / Split / Padding / Reclassification Analysis

Keep target range `0x00405c80-0x004063c8`.

Exact boundary facts:

- Predecessor [UID:0000VW] `jmemmgr.c` ends at `0x00405c77`; `0x00405c77-0x00405c7f` is padding; [UID:0000VX] starts at `0x00405c80`.
- `0x00406390-0x00406393` is the tail of `prepare_for_output_pass`; `0x00406394-0x0040639f` is padding.
- `0x004063a0-0x004063c7` is `finish_output_pass`.
- `0x004063c8-0x004063cf` is padding.
- [UID:0000VY] `jutils.c` starts at `0x004063d0`.

Children/subranges:

- Do not create child pages for the eight functions. They are all part of one exact source-file child and splitting them would make the static embed route ambiguous.
- Do not create padding pages for the small alignment spans around this target.

Reclassification:

- Keep `RECONSTRUCTABLE:TRUE`. This is source-authored third-party code that must be present in the rebuilt executable through the static embed.

## IDA Rename / Type / Comment Recommendations

No IDA DB edits are requested during this report-only pass.

Source-facing documentation names to use:

- `sub_405C80` -> `jpeg_calc_output_dimensions`
- `sub_405EA0` -> `use_merged_upsample`
- `sub_405F30` -> `jpeg_new_colormap`
- `sub_405FA0` -> `jinit_master_decompress`
- `sub_405FE0` -> `master_selection`
- `sub_4061C0` -> `prepare_range_limit_table`
- `sub_406240` -> `prepare_for_output_pass`
- `sub_4063A0` -> `finish_output_pass`

These names are source-proven from staged IJG `jdmaster.c`, not merely inferred from behavior. IDA renames would be safe if a supervisor later authorizes IDA DB source-quality changes, but the current assignment forbids IDA DB edits.

## First-Draft C++ Recommendation

Eligible for draft/formal source route: yes. [UID:0000VX] is `RECONSTRUCTABLE:TRUE`, has confirmed `EMITTER_UIDS:0000KN`, average score is above the current code-entry gate, and the source file is exact.

Recommended exact formal `RECONSTRUCTION_CPP CODE` block content:

```cpp
// Static embed: third_party_embeds/libjpeg/jdmaster.c
```

Reason it preserves behavior: the actual source body comes from the staged IJG libjpeg 6b `jdmaster.c`, hash-matched to the obtained static embed. The marker avoids decompiler-shaped rewrites and preserves the vendor source route.

Reason it matches plausible original source shape: NexusTK appears to have statically linked IJG libjpeg 6b. A third-party `third_party/libjpeg/jdmaster.c` source file is more plausible and maintainable than hand-written product C++ or copied Hex-Rays output.

No-code proof for a blank block is rejected. The target is not an aggregate, has a valid emitter route, and has exact static source provenance.

## Score And Metadata Recommendation

Current metadata:

- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000KN`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KN`
- blank `EMITTER_POSITION_OPTIONAL`
- blank formal C++ block

Recommended metadata:

- `COMPLETION:90`
- `CONFIDENCE:92`
- `CANONICAL_OWNER:0000KN`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KN`
- blank `EMITTER_POSITION_OPTIONAL`
- formal C++ block: `// Static embed: third_party_embeds/libjpeg/jdmaster.c`

Score rationale:

- Completion should rise because current MCP verifies the exact functions, boundaries, xrefs, and behavior; staged-source provenance is hash-backed; the static-embed route resolves the blank formal-block blocker; and no split/ownership blocker remains.
- Confidence should rise because current MCP, source file, support docs, and generated-output interpretation all agree.
- Do not raise either score to 95+. Whole-library compiler/build options, exact feature macro assumptions, and final audit of the entire libjpeg library remain broader [UID:0000KN]/[UID:0000VP] issues. [UID:0000VX] is implementation-ready, not final-audit complete.

Score-limiting blockers actively checked:

- Raw/no-function helper starts: checked through `entity_query` and `lookup_funcs`; not present inside the target range.
- Missing xrefs: checked through `xrefs_to`; only `jpeg_new_colormap` has no xrefs, and source/library context resolves that as retained public API, not a blocker.
- Missing exact by-memory page: checked; exact page exists and is correctly bounded.
- Source-placement uncertainty: checked against [UID:0000KN], [UID:0000VP], staged source, and support docs; resolved to `third_party/libjpeg/jdmaster.c`.
- Aggregate-C++ risk: checked; target is exact source-file child, not broad aggregate. Static-embed marker is safe.

## Open Questions With Attempted Resolution

Open question: should the formal block stay blank because this is third-party code?

- Evidence checked: current by-structure static-embed policy, [UID:0000KN] file role, [UID:0000VP] parent no-code/static-embed proof, generated `LibJPEG.cpp`, and B009/B010 accepted neighboring static-embed pattern.
- Resolution: no. Use a one-line static-embed marker, not a blank block and not pasted source.
- Score/C++ impact: resolves the main C++ blocker and supports `90/92`.

Open question: should no-xref `jpeg_new_colormap` be split, ignored, or left blank?

- Evidence checked: MCP xrefs, source `jdmaster.c`, target function mapping, and support docs.
- Resolution: keep it inside [UID:0000VX]. It is a stock public API guarded by `D_MULTISCAN_FILES_SUPPORTED`; no product xref is expected or required for static library source retention.
- Score/C++ impact: no split blocker remains.

Open question: do predecessor/successor boundaries need repair?

- Evidence checked: predecessor/successor pages, MCP function lookup, and boundary bytes.
- Resolution: no repair needed. The current range is correct.
- Score/C++ impact: supports marker insertion and score increase.

Remaining unresolved issue:

- Whole-library exact build configuration and final binary equivalence remain broader library-level work. This does not block [UID:0000VX]'s static-embed marker or ownership.

## Recommended Target Doc Changes

Target path: `by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md`

Apply these changes after supervisor acceptance:

- Set `COMPLETION:90`.
- Set `CONFIDENCE:92`.
- Keep `CANONICAL_OWNER:0000KN`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KN`, blank optional emitter, and `Nested:0`.
- Insert exactly `// Static embed: third_party_embeds/libjpeg/jdmaster.c` inside the formal `RECONSTRUCTION_CPP CODE` block.
- Update item summary to: `Static IJG libjpeg 6b jdmaster.c decompression master controller from staged third_party_embeds/libjpeg/jdmaster.c.`
- Add a `Live IDA Refresh` or equivalent evidence section preserving MCP session `80de0a67`, listener/session facts, command IDs listed in this report, exact function inventory, boundary/padding facts, xrefs, and master-selection callee fanout.
- Add staged-source provenance: `source-3/third_party_embeds/libjpeg/jdmaster.c` and `by-meta/obtained_thirdparty_files/static_embeds/libjpeg-6b/jdmaster.c` both hash to `C9F18A007511047A50DB0B14C54E4D88C279571EC36824B70C3C20232EF7A8FE`.
- Replace stale "final C++ remains blank because this is third-party code/below old finalization bar" wording with the static-embed marker rationale.
- Preserve rejected alternatives: no product wrapper ownership, no split for no-xref `jpeg_new_colormap`, no merge into `jutils.c`, no pasted upstream C, no decompiler C++.
- Update score rationale and Changes with a 2026-06-26 B008 report-only recommendation note.

## Recommended Support Doc Changes

Support path: `by-file/LibJPEG.md`

- Update the [UID:0000VX] source-file coverage row/note to say current B008 MCP/source pass confirms `jdmaster.c`, staged hash `C9F18A007511047A50DB0B14C54E4D88C279571EC36824B70C3C20232EF7A8FE`, exact range `0x00405c80-0x004063c8`, `jutils.c` successor `0x004063d0`, and formal static-embed route `// Static embed: third_party_embeds/libjpeg/jdmaster.c`.
- Add a compact Changes note that [UID:0000VX] now follows the source-bearing child static-embed policy rather than an empty emitter marker.

Support path: `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`

- Update the [UID:0000VX] child map row to mention the static-embed marker status and current boundary/function evidence.
- Update boundary/padding notes if useful: `0x00405c77-0x00405c80` padding before `jdmaster.c`, `0x004063c8-0x004063d0` padding before `jutils.c`.
- Add B008 MCP command IDs to the parent evidence table or child row at compact detail.

Support path: `by-meta/client_libraries.md`

- Update the [UID:0000VX] libjpeg bullet to mention current B008 confirmation of the `jdmaster.c` static-embed route, instead of only saying it maps `jdmaster.c`.
- Keep product wrapper boundaries unchanged.

Support path: `by-meta/obtained_thirdparty_files/static_embeds/README.md`

- No edit required. Existing README already records `libjpeg-6b/` from `jpegsrc.v6b.tar.gz`, the included static source role, `jmemnobs.c`, `jconfig.h`, and hash-for-hash mirror checks.

Generated files:

- Do not manually edit `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, or `auto-generated/NexusTK/third_party/libjpeg/LibJPEG.cpp`.
- Expect normal validator/report execution to refresh stale [UID:0000VX] generated rows and replace the generated empty emitter marker after accepted implementation.

Manual coverage text:

- None. No manual `-coverage-report.md` update is requested or permitted for this report-only assignment.

## Validator Plan For Implementation Callback

After accepted implementation edits, run scoped validators from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0000VX-LibJpegDecompressMaster-source-quality-removed.md](0000VX-LibJpegDecompressMaster-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Implementation closeout should report command IDs, timestamps, exit codes, `ok` counts, generated refresh state, leases used/released, and any generated output freshness check if the supervisor needs current `auto-generated/NexusTK/third_party/libjpeg/LibJPEG.cpp`.

## Confidence

- Recommendation confidence: strong.
- Score confidence: strong for `90/92`, intentionally below final-audit `95+`.
- Remaining uncertainty: library-level compile flags/header configuration and whole-libjpeg binary equivalence remain broader [UID:0000KN]/[UID:0000VP] issues. No target-local blocker remains.

## Validator Results

Implementation callback validators were run from `source-3/project-documentation` with `--apply`. The required four scoped validators passed, then `by-meta/client_libraries.md` was rerun after the lower [UID:0000VX] bullet was expanded:

| Wrapper command id | Validator command id | Command timestamp | Exit | ok | generated refresh |
| --- | --- | --- | ---: | ---: | --- |
| `b008-validator-0000VX-target-20260626T0008` | `000000003569` | `2026-06-26T22:30:09-04:00` | 0 | 1 | `deferred`; refresh command id `000000003569` |
| `b008-validator-libjpeg-20260626T0009` | `000000003571` | `2026-06-26T22:30:20-04:00` | 0 | 1 | `deferred`; refresh command id `000000003571` |
| `b008-validator-libjpeg-core-20260626T0010` | `000000003573` | `2026-06-26T22:30:36-04:00` | 0 | 1 | `deferred`; refresh command id `000000003573` |
| `b008-validator-client-libraries-20260626T0011` | `000000003574` | `2026-06-26T22:30:44-04:00` | 0 | 1 | `deferred`; refresh command id `000000003574` |
| `b008-validator-client-libraries-rerun-20260626T0012` | `000000003576` | `2026-06-26T22:34:05-04:00` | 0 | 1 | `deferred`; refresh command id `000000003576` |

Validator notes:

- Target validator applied expected metadata/autogen registry updates for [UID:0000VX], changed the generated registry state from blank to block, and normalized two UID links plus header spacing.
- `by-file/LibJPEG.md` and [UID:0000VP][0x00401000-0x00414283.LibJpeg6bCore](by-memory/0x00401000-0x00414283.LibJpeg6bCore.md) each retained the existing `0003OI` missing-ref-UID warning but passed.
- `by-meta/client_libraries.md` retained existing unrelated missing-ref warnings for `0003GZ`, `0003OJ`, `0003P7`, `0003WI`, `0003WJ`, `0003WK`, and stale target paths for `0000W4` / `0000X2`, but passed on both the required run and the final rerun.
- No generated report, `-coverage-report.md`, tool-state, or IDA DB file was manually edited. Generated refresh state is validator-deferred for the scoped runs and final client-libraries rerun.

## Changed Files

- Modified: `by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md`
- Modified: `by-file/LibJPEG.md`
- Modified: `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`
- Modified: `by-meta/client_libraries.md`
- Modified: `tools/leaser/Agents/Agent-B008/research/0000VX-LibJpegDecompressMaster-source-quality.md`
- Renamed: none.
- Generated validator side effects: scoped validators and the client-libraries rerun reported `generated_refresh: deferred` and projected-stats updates; no generated or project-level file was manually edited by B008.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Accepted by supervisor in the implementation callback message.
- [x] Target doc to update: `by-memory/0x00405c80-0x004063c8.LibJpegDecompressMaster.md`.
- [x] Support docs to update: `by-file/LibJPEG.md`, `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`, and `by-meta/client_libraries.md`.
- [x] No edit required for `by-meta/obtained_thirdparty_files/static_embeds/README.md`; existing libjpeg-6b provenance remained sufficient and the file was not edited.
- [x] Current target state and actual evidence preserved: prior header `86/90`, owner/emitter `0000KN`, blank formal block, stale generated rows, MCP session `80de0a67`, listener/session facts, command IDs, function inventory, xrefs, boundary bytes, staged-source hashes, and source line anchors were incorporated or superseded.
- [x] Metadata changes applied: target `COMPLETION:90`, `CONFIDENCE:92`; `CANONICAL_OWNER:0000KN`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KN`, blank optional emitter, and `Nested:0` preserved.
- [x] Item summary applied: `Static IJG libjpeg 6b jdmaster.c decompression master controller from staged third_party_embeds/libjpeg/jdmaster.c.`
- [x] Owner/emitter/reconstructable changes applied: none beyond preserving current `0000KN` owner/emitter and `TRUE` reconstructable state.
- [x] Split/rename/new-child changes applied: none; exact range `0x00405c80-0x004063c8` preserved.
- [x] Source-placement changes applied: `third_party/libjpeg/` source placement and staged source `third_party_embeds/libjpeg/jdmaster.c` documented.
- [x] Range/boundary facts incorporated: predecessor padding after `0x00405c77`, target start `0x00405c80`, target end `0x004063c8`, padding to `0x004063d0`, and successor [UID:0000VY] `jutils.c`.
- [x] IDA source-facing name facts incorporated: `sub_405C80`, `sub_405EA0`, `sub_405F30`, `sub_405FA0`, `sub_405FE0`, `sub_4061C0`, `sub_406240`, and `sub_4063A0` mapped to the source names listed in this report.
- [x] Score-limiting blockers researched/resolved: formal-block blocker resolved with static-embed marker; no-xref `jpeg_new_colormap` retained as source API; split/range blocker resolved as no split; product-wrapper ownership rejected.
- [x] First-draft C++/static embed applied in target formal block: `// Static embed: third_party_embeds/libjpeg/jdmaster.c`.
- [x] Exact target/support doc facts incorporated at report-level detail: MCP health/session facts, function inventory, xrefs, callee fanout, behavior summaries, staged-source hash, source line anchors, static-embed policy, rejected alternatives, and score rationale.
- [x] Historical/stale assumptions and negative evidence preserved or replaced: old blank-block/below-95 rationale is replaced by static-embed route; generated rows treated as validator state; no product wrapper ownership; no merge with `jutils.c`; no pasted upstream C or Hex-Rays C++.
- [x] Wave2/Wave3 mentions/artifacts encountered: none used as authority; generated/autogen state was read-only stale-state evidence.
- [x] Open questions closed: formal C++ blank route, no-xref `jpeg_new_colormap`, and boundary/split question closed; broader libjpeg compile configuration remains non-blocking [UID:0000KN]/[UID:0000VP] uncertainty.
- [x] Validators run after implementation: the four scoped validator commands listed in `Validator Plan For Implementation Callback` completed with exit 0 and `ok: 1`; `client_libraries` was rerun after the final lower-bullet edit and also completed with exit 0 and `ok: 1`.
- [x] Generated report refresh state recorded: all scoped validator runs and the final client-libraries rerun reported `generated_refresh: deferred`; no manual generated or coverage edits.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] Lease each editable target/support file only for the edit/validator batch. Initial partial lease conflict was handled by releasing B008's partial leases, waiting for B007's support-doc leases to expire, then acquiring the full batch at `2026-06-27T02:26:03Z`.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Metadata/score/owner/emitter/static-embed changes applied.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded with command IDs, timestamps, exit codes, `ok` counts, and generated refresh state.
- [x] Generated refresh state reported as validator-deferred; no generated-header freshness check was run beyond the scoped validator outputs.
- [x] Remaining unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B008","command_id":"000000004165","destination_path":"executed-b-agent-research/B008/0000VX-LibJpegDecompressMaster-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B008/research/0000VX-LibJpegDecompressMaster-source-quality.md","timestamp":"2026-06-26T22:37:04","uid":"0000VX"} -->
<!-- {"agent":"B008","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000VX-LibJpegDecompressMaster-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B008/0000VX-LibJpegDecompressMaster-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000VX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
