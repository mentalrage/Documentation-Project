** TARGET-REPORT-UID:0000VV **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **
# 0000VV LibJpegInputController Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: preserve the completed UID0000VV implementation: exact validator inline import of staged IJG libjpeg 6b `jdinput.c` and six required headers, full source-quality evidence, and score `90/92`.
- Final disposition: source-bearing static third-party code from IJG libjpeg 6b, canonically owned and emitted by [UID:0000KN] `by-file/LibJPEG.md`; it is not NexusTK product image-loader or screenshot-writer source.
- Implementation result: C01-C18 are applied at report-level detail across the target and three accepted support docs; the managed multiline C++ body remains blank; all four scoped validators passed and completed generated refresh.
- Current score/metadata: target `90/92`; owner/emitter UID0000KN, reconstructable true, blank position, range, nesting, and source placement remain unchanged. Support scores and UID0000VP's non-emitting state remain unchanged.
- Confidence: high for source identity, function inventory, boundaries, callback behavior, ABI configuration, import route, and ownership; medium-high for the exact score because whole-library build equivalence remains a broader LibJPEG audit.

## Supporting Research

- B004 first performed an independent report-only pass under `ntk-b-agent-workflow`; supervisor Gate 1 accepted exact report SHA256 `6E19D2CA967C480B5976559A4780B3856B5D8077F1D3F0FEE825A9F3BE6B6518`, then authorized this implementation callback.
- Callback implementation changed only the four accepted by-* docs and this report. Validator-owned generated/tracker/coverage/state files refreshed through scoped validators; B004 did not edit those files manually or mutate the IDB.
- MCP evidence was collected from supervisor-specified database `545b4991`. At evidence time, `idb_list` returned one adopted active worker session for `NexusTK.exe.i64`, and `server_health` returned `status:"ok"`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and string cache ready with 2067 entries.
- A separate report for the same UID existed at `tools/leaser/Agents/Agent-B010/research/0000VV-LibJpegInputController-source-quality.md`. It was the report active when searched and was treated only as a lead. B004 independently checked the target, source, headers, hashes, import syntax, MCP function behavior, xrefs, and boundaries.
- Lifecycle wording is intentionally archive-neutral: B004 itself ran no report execution, move, archive, registry, or lifecycle command. Supervisor-owned lifecycle state must be read from validator headers/history and the artifact's actual path.

## Target

- Target UID: `0000VV`.
- Target path: `by-memory/0x00404a60-0x0040505b.LibJpegInputController.md`.
- Assigned report path: `tools/leaser/Agents/Agent-B004/research/0000VV-LibJpegInputController-source-quality.md`.
- Queue source at assignment time: `auto-generated/-ag-research-tracker.md` -> `by-memory` -> `Not-Covered Files - Reconstructable`.
- Pre-callback target snapshot: `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000KN`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KN`, blank optional position, blank `RECONSTRUCTION_CPP CODE` value.
- Parent snapshot: [UID:0000KN] `by-file/LibJPEG.md` is `92/92`, source root `NexusTK/third_party/libjpeg/`, canonical owner `FILE`.

## Current Target State

- Current target metadata is `90/92`, canonical owner/emitter UID0000KN, reconstructable true, blank optional position, `Nested:0`, and the original half-open range.
- The formal reconstruction value now contains the exact seven-path import directive; BEGIN/END remain blank. Generated `auto-generated/NexusTK/third_party/libjpeg/LibJPEG.cpp` contains imported-source separators/content for UID0000VV's seven files and no UID0000VV empty marker.
- The function table now correctly identifies `0x00404ab0` as `start_input_pass` and `0x00404d50` as `finish_input_pass`, while preserving the other six source identities, visibility classes, source anchors, and all external/internal NOP spans.
- Target-level declaration/helper-name, Windows ABI, callbacks, boundaries, source provenance/hash, ownership, and formal import blockers are resolved and documented. Whole-library rebuild equivalence remains only the explicit broader score cap.
- [UID:0000KN], [UID:0000VP], and `by-meta/client_libraries.md` now carry synchronized UID0000VV function/boundary/import/dependency/ABI/hash/rejection detail without support score changes or support C++ inflation.
- Historical SpecialReport `000TP` records `jdinput.c` as importable yet also excludes UID0000VV as empty/support-only. That contradiction is a non-authoritative historical lead; direct MCP/source evidence rejects the exclusion.

## Executive Recommendation

- Keep [UID:0000KN] LibJPEG as canonical owner/emitter and keep the reconstruction placement `NexusTK/third_party/libjpeg/`.
- Keep UID0000VV as one exact source-file page. It contains all eight retained `jdinput.c` functions and only alignment padding between them; no mixed source, data island, or product wrapper requires a split.
- The exact formal import block in `First-Draft C++ Recommendation` is applied, using paths rooted at `third_party_embeds/` and a blank multiline body.
- The two swapped/vague callback identities are corrected; all source anchors, boundary padding, callbacks, caller/callee relationships, rejected alternatives, and negative evidence are preserved; target is `90/92`.
- [UID:0000KN], [UID:0000VP], and `by-meta/client_libraries.md` are synchronized without score changes or unrelated C++.

## Supervisor Active Recheck

- Triggering instruction: independent B004 report-only source-quality research for UID0000VV using supervisor-specified MCP database `545b4991` at evidence time and direct comparison against `source-3/third_party_embeds/libjpeg/jdinput.c`.
- Split-first recheck: no split repair is required. Eight modeled bodies and their NOP gaps form one coherent `jdinput.c` source unit between `jcomapi.c` and `jmemmgr.c`.
- Source-bearing child coverage: UID0000VV itself is the complete source-bearing child in scope. No new by-memory child is needed.
- Gate/callback boundary: no target/support edit or validator occurred before Gate 1. After exact-artifact acceptance, B004 completed only the authorized four-file callback and scoped validators.

## Inference Research Guidance Check

- `by-structure.md` and `tools/validator_README.txt` require a vetted static third-party source page to use an inline `<import-from-start>...<import-from-end>` directive, with every path beginning `third_party_embeds/`, and to leave the multiline C++ body blank.
- Existing documentation assumptions treated as uncertain were the swapped `start_input_pass`/`finish_input_pass` mapping, unresolved declaration/local names, the empty-emitter exclusion, legacy static-embed wording, and possible product-wrapper ownership.
- Direct IDA facts are reported separately from source/documentation evidence and source-shape inference. Upstream names are source-proven by the hash-matched staged file, not guessed from `sub_*` labels.
- Generated C++ and old reports were used as leads only. The pre-callback empty marker was a historical emission deficiency, not source-identity proof; callback-generated content now confirms the accepted import was emitted.
- No Wave2/Wave3 material was used. The target's historical note that `wave3.py` was not run is not evidence and should not be carried forward as a current research basis.

## Heuristic / Inference Reanalysis And Validation

- Source identity blocker: resolved. The binary's eight-function behavior matches the complete IJG 6b `jdinput.c`; binary version strings report `6b  27-Mar-1998`; staged `jdinput.c` matches the obtained official archive copy byte-for-byte.
- Function-name blocker: resolved. Address `0x00404ab0` performs `per_scan_setup`, `latch_quant_tables`, entropy `start_pass`, coefficient `start_input_pass`, and consume callback replacement, proving `start_input_pass`. Address `0x00404d50` restores `consume_markers`, proving `finish_input_pass`.
- Local/public visibility blocker: resolved by source macros. `initial_setup`, `per_scan_setup`, and `latch_quant_tables` are `LOCAL` static functions; `start_input_pass`, `finish_input_pass`, `consume_markers`, and `reset_input_controller` are `METHODDEF` static callback functions; only `jinit_input_controller` is `GLOBAL` external library initialization.
- ABI/build blocker: resolved for this target. Windows `jconfig.h` defines `boolean` as `unsigned char`; on the observed 32-bit build the four callback pointers occupy offsets 0, 4, 8, and 12, booleans occupy offsets 16 and 17, and private `inheaders` is at offset 20 after alignment. MCP observed a 24-byte permanent controller allocation, exactly matching `my_input_controller`.
- Quant-table layout blocker: resolved. `JQUANT_TBL` is 64 unsigned-short values plus one unsigned-char `sent_table`, padded to 130 bytes; MCP observed `alloc_small(..., JPOOL_IMAGE, 130)` and a 130-byte copy.
- Compile constants blocker: resolved for target behavior: 8-bit samples, maximum 10 components, maximum dimension 65500, four scan components, sampling factor maximum four, DCT size eight, and ten decompressor MCU blocks match staged headers and observed branches/literals.
- Range blocker: resolved. The half-open page range remains `0x00404a60-0x0040505b`; predecessor `jcomapi.c` ends at `0x00404a5c`; four NOPs precede target start; five NOPs follow target body end before `jmemmgr.c` starts at `0x00405060`.
- Internal padding blocker: resolved. The gaps `0x00404aa1-0x00404ab0`, `0x00404ae9-0x00404af0`, `0x00404c95-0x00404ca0`, `0x00404d4c-0x00404d50`, `0x00404d61-0x00404d70`, `0x00404e2e-0x00404e30`, and `0x0040501c-0x00405020` are NOP alignment, not missing functions or data.
- Callback-liveness blocker: resolved. Static helpers with no external direct code xrefs remain live through method pointers installed by `jinit_input_controller` and through internal calls. Absence of a direct xref is not dead-code evidence here.
- Source placement blocker: resolved. Internal decompressor controller behavior belongs in IJG `jdinput.c`; product code consumes public JPEG APIs and does not own this cluster.
- Formal source blocker: resolved as an import directive. Pasted upstream code, handwritten decompiler-shaped C++, a legacy marker comment, and a blank/no-code disposition are all rejected.
- Remaining uncertainty: a whole-library compiler/options/rebuild-equivalence audit is outside this target. It prevents a final-audit score but does not block exact `jdinput.c` import or source names.

## Evidence Standards Used

- Direct evidence: schema-refreshed IDA MCP `idb_list`, health, function lookup/inventory, function analyses/decompilation, xrefs, callees, raw bytes, string reads, and negative endpoint/type checks.
- Source evidence: staged IJG `jdinput.c`, `jinclude.h`, `jpeglib.h`, `jconfig.h`, `jmorecfg.h`, `jpegint.h`, and `jerror.h`; official-archive provenance and hash manifest.
- Documentation evidence: target, direct owner, broad core index, marker-reader, memory-manager, decompression-master, utility-helper, client-library, by-structure, validator import rules, generated C++, tracker/coverage rows, and matching reports searched by UID/address/name/source family.
- Evidence ladder: binary behavior and bytes establish what exists; hash-matched source establishes exact source-facing names and declarations; project rules establish the emission form; documentation/generator state establishes required synchronization.
- Tool limitation: IDB `type_query` returned no usable JPEG types. This does not reduce the source conclusion because the staged header layouts are independently corroborated by binary field offsets and allocation sizes.

## Evidence Checked

- MCP transport: initialized `ida-pro-mcp 1.0.0` over `http://127.0.0.1:13337/mcp`; refreshed a 65-tool `tools/list` schema; all successful IDB calls carried `database:'545b4991'`.
- Evidence-time MCP state: JSON-RPC `61006` `idb_list` returned session `545b4991`, worker PID 9344, `is_active:true`; `61007` `server_health` returned `status:"ok"`, image base `0x400000`, analysis/Hex-Rays/string cache ready.
- Boundary recheck: JSON-RPC `61008` `lookup_funcs` found `sub_404A40` size `0x1c`, no function at `0x00404a5c`, `sub_404A60` size `0x41`, no function at `0x0040505b`, and `sub_405060` size `0x13b`.
- Mandatory MCP pass from the same database also checked all eight target starts, `analyze_function` behavior, xrefs, callees, bytes for every gap/boundary, version strings at `0x00671268` and `0x0067128c`, and negative type availability.
- Source/hash checks: staged `jdinput.c` SHA256 `F1F6B042AA907FE622AA7C94B21D71E61F7F306E10988148C42CC7D50F667E76`, identical to the obtained `libjpeg-6b/jdinput.c` archive copy and manifest.
- Header hashes checked: `jinclude.h` `A6433E5EA0030F4BFFD41BCC2F064008AFD79DE4270CF28494BD43D2FBC5DA06`; `jpeglib.h` `B34B3D9897820302CC23BA60217157F75E03DB8C537A7D4703FF0BC8C9FC048B`; `jconfig.h` `1D0894775067D15163181F26D3039E24B34501CA7E5380DD2DDB8526DD05B250`; `jmorecfg.h` `262138C3433E81E84E9F6811B38B5DC63E6F161E9B952AFB0FF61B4A39B697A9`; `jpegint.h` `F2FBBF47DA9FE7CC9E4813235D71E1252EC4662E3ECB8823BD4D499492125153`; `jerror.h` `324F058E0DC17408EA83A8D47D0A7A1F6BA7553D653F709A9BE275971F539FEC`.
- Provenance checked: static-embed README identifies `jpegsrc.v6b.tar.gz`, `makefile.vc` library objects, `jmemnobs.c`, and upstream `jconfig.vc`; staged and obtained libjpeg trees were documented hash-for-hash.
- Search-gated report terms: `0000VV`, `LibJpegInputController`, `0x00404a60`, `0x0040505b`, `jdinput.c`, `jinit_input_controller`, `start_input_pass`, `F1F6B042`, `LibJPEG`. Matching B010 and historical LibJPEG reports were leads only.
- Negative checks: no function at either boundary marker; no data island in range; no IDB JPEG type records; no product-owned logic; no need for per-helper split; no valid reason to retain blank C++.
- Report-only phase intentionally skipped validators. Callback phase ran only the four scoped validators recorded below; no IDB mutation, execute/lifecycle/move/archive command, or MCP process management occurred.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0000VV is the complete retained IJG libjpeg 6b `jdinput.c` input-controller source unit. | High | Eight-function MCP match, version strings, hash-matched source. | Target `Status`, `Range Role`, `Ownership Decision`; LibJPEG child map. | incorporate | applied |
| C02 | Keep half-open range `0x00404a60-0x0040505b`; predecessor and successor boundaries are padding-separated. | High | MCP lookup and raw bytes. | Target `Range Role`, `Evidence Notes`; core index. | incorporate | applied |
| C03 | The exact function mapping is jinit, start, per-scan, latch, finish, consume, initial, reset at the eight observed starts. | High | MCP analyses plus source lines 38-381. | Target `Function Mapping`. | incorporate | applied |
| C04 | All seven internal gaps and both external boundary gaps are NOP alignment, not omitted code/data. | High | MCP `get_bytes`. | Target `Range Role`/`Evidence Notes`; core index support. | incorporate | applied |
| C05 | `jinit_input_controller` allocates a 24-byte permanent controller and installs four callbacks plus three state booleans. | High | MCP analysis, `jdinput.c`, `jpegint.h`, `jconfig.h`. | Target `Evidence Notes`. | incorporate | applied |
| C06 | `start_input_pass` performs per-scan/quant setup, starts entropy and coefficient input, then switches consume input to coefficient data. | High | MCP analysis/xrefs/callees; source lines 253-261. | Target `Function Mapping`/`Evidence Notes`. | incorporate | applied |
| C07 | `finish_input_pass` at `0x00404d50` restores `consume_markers`; the old vague label is stale. | High | MCP behavior; source lines 270-274. | Target `Function Mapping`. | historicalize | applied |
| C08 | `consume_markers` links this controller to `jdmarker.c`, performs first/later SOS and EOI transitions, and calls `start_input_pass` for later scans. | High | MCP analysis/xrefs; source lines 287-331. | Target `Evidence Notes`/cross-references. | incorporate | applied |
| C09 | `reset_input_controller` restores marker consumption, clears state, resets error/marker modules, and clears `coef_bits`. | High | MCP analysis; source lines 338-352. | Target `Function Mapping`/`Evidence Notes`. | incorporate | applied |
| C10 | Windows unsigned-char `boolean`, 32-bit pointer layout, and observed allocations resolve controller and quant-table ABI details. | High | Headers plus MCP offsets/sizes. | Target `ABI / Build Configuration` detail. | incorporate | applied |
| C11 | Static/public identities are source-proven: three LOCAL helpers, four METHODDEF callbacks, one GLOBAL initializer. | High | `jmorecfg.h`, `jdinput.c`, xref shape. | Target `Function Mapping`/source-quality notes. | incorporate | applied |
| C12 | The exact formal reconstruction is the seven-path `third_party_embeds/libjpeg/...` import directive with a blank multiline block. | High | Validator README, by-structure, staged files. | Target managed C++ header/block. | incorporate | applied |
| C13 | Keep owner/emitter [UID:0000KN], reconstructable true, position blank, and placement `NexusTK/third_party/libjpeg/`. | High | Source identity, parent structure, product-wrapper rejection. | Target metadata; LibJPEG support. | already-present | already-present |
| C14 | Raise target scores `86/90 -> 90/92`, but do not inflate support-page scores. | Medium-high | Resolved source/import/name/ABI blockers; broader audit remains. | Target metadata/score rationale. | incorporate | applied |
| C15 | [UID:0000KN] records UID0000VV as a converted formal `jdinput.c` import child, resolving the pre-callback contradiction. | High | Parent status/child row versus historical generated empty marker. | `by-file/LibJPEG.md`. | incorporate | applied |
| C16 | [UID:0000VP] carries exact UID0000VV function/boundary/import facts while remaining non-emitting and score-neutral. | Medium-high | Broad index role and adjacent detailed rows. | `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`. | incorporate | applied |
| C17 | `by-meta/client_libraries.md` replaces the bare UID0000VV mapping with formal import-route wording and rejects legacy marker terminology for this child. | Medium-high | Meta row and validator policy. | `by-meta/client_libraries.md`. | incorporate | applied |
| C18 | Historical SpecialReport exclusion, product ownership, per-helper split, pasted code, and blank/no-code alternatives remain rejected evidence, not implementation routes. | High | Direct evidence and project rules. | Target evidence/change history and support notes. | reject-stale | applied |

## Positive Evidence Summary

- The exact eight binary routines reproduce every source-level `jdinput.c` role, including the callback transitions that distinguish the previously swapped names.
- `jinit_input_controller` has the only external direct code caller, from `jpeg_CreateDecompress` at `0x004011b0`; the remaining static routines are reached internally or through installed method pointers, matching upstream visibility.
- `start_input_pass` directly calls `per_scan_setup` and `latch_quant_tables`; `consume_markers` directly calls `initial_setup` and `start_input_pass`; `initial_setup` and `per_scan_setup` call `jdiv_round_up` at `0x004063d0`.
- The staged source's constants, allocation sizes, structure offsets, error branches, and callback ordering agree with the recorded MCP decompilation.
- Binary version strings, source archive provenance, and the identical `jdinput.c` hash establish IJG 6b rather than a merely similar JPEG implementation.
- Existing LibJPEG ownership and neighboring `jcomapi.c`, `jmemmgr.c`, and `jdmaster.c` source-file pages establish the correct source-root and formal-import convention.

## IDA MCP Facts

- `0x00404a60-0x00404aa1`, `sub_404A60`, size `0x41`: `jinit_input_controller`; allocates 24 bytes from pool 0, stores `cinfo->inputctl` at decompressor offset 400, installs callbacks at offsets 0/4/8/12, initializes bytes 16/17 and private byte 20.
- `0x00404ab0-0x00404ae9`, `sub_404AB0`, size `0x39`: `start_input_pass`; calls `0x00404af0` and `0x00404ca0`, invokes entropy and coefficient start callbacks, then assigns coefficient `consume_data`.
- `0x00404af0-0x00404c95`, `sub_404AF0`, size `0x1a5`: `per_scan_setup`; handles one-component and interleaved scans, computes MCU dimensions/membership, calls `jdiv_round_up`, enforces component count 1..4 and ten blocks per MCU.
- `0x00404ca0-0x00404d4c`, `sub_404CA0`, size `0xac`: `latch_quant_tables`; validates table index 0..3/presence, allocates from image pool 1, and copies 130 bytes once per component.
- `0x00404d50-0x00404d61`, `sub_404D50`, size `0x11`: `finish_input_pass`; restores the consume callback to `consume_markers`.
- `0x00404d70-0x00404e2e`, `sub_404D70`, size `0xbe`: `consume_markers`; invokes marker `read_markers`, returns EOI immediately after latch, performs first-SOS initial setup, later-SOS validation/start, and EOI scan-number correction.
- `0x00404e30-0x0040501c`, `sub_404E30`, size `0x1ec`: `initial_setup`; checks dimensions 65500, precision 8, component count 10, sampling factor 1..4, computes block/sample dimensions and total iMCU rows, initializes per-component state, and determines multiple scans.
- `0x00405020-0x0040505b`, `sub_405020`, size `0x3b`: `reset_input_controller`; restores marker consumption, clears public flags, sets `inheaders`, invokes error and marker reset callbacks, and clears `coef_bits`.
- Xrefs: jinit has one code caller at `0x00401276` inside `jpeg_CreateDecompress`; start has direct use from consume plus callback data xref; finish/reset/consume have callback data xrefs; per-scan/latch/initial have the exact internal direct callers expected by source.
- Boundary negatives: `0x00404a5c` and `0x0040505b` are not functions; `0x00405060` starts `jinit_memory_mgr`; no unexpected function start exists in any NOP gap.
- Type negative: no JPEG type records were returned by the IDB type query; source names and layouts therefore come from the staged headers corroborated by binary behavior.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00404a60-0x00404aa1` | UID0000VV | `jinit_input_controller` GLOBAL initializer | yes | UID0000KN | target `90/92` applied | exact source match |
| `0x00404ab0-0x00404ae9` | UID0000VV | `start_input_pass` METHODDEF callback | yes | UID0000KN | included | old target label corrected |
| `0x00404af0-0x00404c95` | UID0000VV | `per_scan_setup` LOCAL helper | yes | UID0000KN | included | exact source match |
| `0x00404ca0-0x00404d4c` | UID0000VV | `latch_quant_tables` LOCAL helper | yes | UID0000KN | included | exact source match |
| `0x00404d50-0x00404d61` | UID0000VV | `finish_input_pass` METHODDEF callback | yes | UID0000KN | included | vague old label corrected |
| `0x00404d70-0x00404e2e` | UID0000VV | `consume_markers` METHODDEF callback | yes | UID0000KN | included | exact source match |
| `0x00404e30-0x0040501c` | UID0000VV | `initial_setup` LOCAL helper | yes | UID0000KN | included | exact source match |
| `0x00405020-0x0040505b` | UID0000VV | `reset_input_controller` METHODDEF callback | yes | UID0000KN | included | exact source match |
| NOP gaps | UID0000VV boundary/support | compiler alignment only | no independent child | UID0000VP index | no score | preserve as padding facts |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00404a60` | code caller `0x00401276` in `jpeg_CreateDecompress` | stock one-time decompression object initialization |
| `0x00404ab0` | direct caller in `consume_markers`; data xref from jinit callback table | first pass called by `jdmaster.c` through callback; later passes called internally |
| `0x00404af0` | direct caller `start_input_pass` | per-scan setup is module-local and live |
| `0x00404ca0` | direct caller `start_input_pass` | quant-table latch is module-local and live |
| `0x00404d50` | data xref from jinit callback table | coefficient controller calls through `finish_input_pass` method pointer |
| `0x00404d70` | data xrefs from jinit, finish, and reset assignments | marker consumption is a state-dependent callback |
| `0x00404e30` | direct caller `consume_markers` | first-SOS-only initial setup |
| `0x00405020` | data xref from jinit callback table | reset callback installed at controller creation |
| `start_input_pass` | entropy `start_pass`, coefficient `start_input_pass`, coefficient `consume_data` | handoff from marker parsing to entropy/coefficient scan data |
| `consume_markers` / reset | marker `read_markers` / `reset_marker_reader` | direct module relationship to UID0000VR `jdmarker.c` |
| init/latch | memory `alloc_small`, pools 0 and 1 | relationship to UID0000VW `jmemmgr.c` |
| initial/per-scan | `jdiv_round_up` at `0x004063d0` | relationship to UID0000VY `jutils.c` |

## Documentation Evidence And IDA Status

- Historical pre-callback target state: strong `jdinput.c` ownership coexisted with stale start/finish names, an obsolete unresolved-source score rationale, and blank formal reconstruction content. The callback corrected all three conditions.
- [UID:0000KN] correctly owns the static IJG library. Its UID0000VV detail now matches the all-exact-children-converted statement and formal source-import policy.
- [UID:0000VP] remains a broad `90/92` non-emitting index; its UID0000VV evidence/child/padding rows now carry the accepted score-neutral support detail.
- Marker reader UID0000VR, memory manager UID0000VW, decompression master UID0000VX, and utility helpers UID0000VY corroborate the controller's dependency edges and source-file separation.
- At evidence time, MCP database `545b4991` was healthy and returned real function/boundary results. The report does not assert indefinite session availability.
- Historical report-only generated snapshot: UID0000VV was an empty emitter marker. Current callback-generated `LibJPEG.cpp` imports all seven accepted files and has no UID0000VV empty marker; the generated file remained validator-owned and was inspected read-only.

## Ranked Ownership Analysis

### 1. [UID:0000KN] LibJPEG / `third_party/libjpeg/jdinput.c`

- Evidence for: exact eight-function behavior, official IJG 6b source/hash/version, existing owner/emitter metadata, coherent source-file boundaries, and current static-third-party import policy.
- Evidence against: none material. Broader build-equivalence uncertainty does not alter source ownership.
- Decision: retain canonical owner/emitter and import exact staged source.

### 2. NexusTK product image-loader or screenshot-writer source

- Evidence for: product code eventually calls public JPEG decompression/compression APIs.
- Evidence against: no product-specific behavior or direct ownership edge exists here; the cluster is internal IJG decompressor state control and matches upstream source exactly.
- Decision: reject as owner, emitter, or source placement.

### 3. [UID:0000VP] broad LibJpeg6bCore page

- Evidence for: UID0000VV lies within its broad code island.
- Evidence against: UID0000VP is a non-emitting split/index; exact source-file children carry source imports through UID0000KN.
- Decision: keep as support/index only.

### Proposed new file/grouping, if applicable

- No new documentation owner or source grouping is required.
- Full source contents belong to the existing `jdinput.c` unit: its private controller type, three LOCAL helpers, four METHODDEF callbacks, and one GLOBAL initializer.
- `jdmarker.c`, `jmemmgr.c`, `jdmaster.c`, `jutils.c`, entropy/coefficient controllers, and product wrappers remain separate source/documentation units.

## Source Placement

- Recommended placement: [UID:0000KN] `NexusTK/third_party/libjpeg/`, importing `third_party_embeds/libjpeg/jdinput.c` and the required IJG headers.
- This fits the static library's exact upstream source shape and preserves product/library separation.
- Rejected placements: product `ImageLoaders`, `ImageWriters`, broad UID0000VP emission, and one helper page/file per local function.
- Remaining placement uncertainty: none for this target.

## Range / Split / Padding / Reclassification Analysis

- Keep the documented half-open range `0x00404a60-0x0040505b`.
- Predecessor `sub_404A40` ends at `0x00404a5c`; `0x00404a5c-0x00404a60` is four NOPs.
- Target body/gaps: eight function bodies with seven NOP alignment spans; no embedded data or foreign-source routine.
- `0x0040505b-0x00405060` is five NOPs; `sub_405060` begins `jmemmgr.c`.
- No children should be created, merged, reclassified, ignored, or left no-owner. UID0000VP remains a score-neutral non-emitting parent index.

## Negative Evidence Summary

- No binary/source evidence supports product ownership; consumer calls to public JPEG APIs are not ownership proof for internal controller code.
- No mixed-source or data island supports a blank aggregate/no-code disposition.
- No absent direct xref makes the static callback routines dead; callback data xrefs and state transitions prove liveness.
- No IDB type information independently names the source structures, but observed 24-byte/130-byte allocations and field offsets corroborate the staged headers.
- No reason exists to split upstream `jdinput.c` into per-helper pages or paste its source into Markdown.
- Legacy `// Static embed:` text and the historical empty/support-only exclusion are rejected as stale implementation forms.
- The absence of a whole-library rebuild audit limits the score only; it does not create target-level declaration, helper-name, ABI, source-placement, or import uncertainty.

## IDA Rename / Type / Comment Recommendations

- Source-facing names to document: `jinit_input_controller`, `start_input_pass`, `per_scan_setup`, `latch_quant_tables`, `finish_input_pass`, `consume_markers`, `initial_setup`, `reset_input_controller`, `my_input_controller`, and `my_inputctl_ptr`.
- Source-facing types/fields come from staged IJG headers and are corroborated by binary offsets and sizes.
- The target's function table is corrected; the IDB was not mutated in this assignment.
- IDA renames/types/comments are not requested and no IDB edit is required for formal source import.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes, as vetted static third-party C source. The correct formal source representation is an import directive, not handwritten C++.
- Exact managed insertion text:

```md
*** RECONSTRUCTION_CPP CODE:[[[<import-from-start>"third_party_embeds/libjpeg/jdinput.c","third_party_embeds/libjpeg/jinclude.h","third_party_embeds/libjpeg/jpeglib.h","third_party_embeds/libjpeg/jconfig.h","third_party_embeds/libjpeg/jmorecfg.h","third_party_embeds/libjpeg/jpegint.h","third_party_embeds/libjpeg/jerror.h"</import-from-end>]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Every path begins exactly `third_party_embeds/`, uses forward slashes, ends in `.c` or `.h`, and resolves beneath `source-3/third_party_embeds/`.
- Smallest correct closure: `jdinput.c` directly includes `jinclude.h` and `jpeglib.h`; those headers and `JPEG_INTERNALS` expose the staged Windows configuration, common types, internal controller structures, and error macros through `jconfig.h`, `jmorecfg.h`, `jpegint.h`, and `jerror.h`. This matches accepted neighboring LibJPEG import style without importing unrelated source files.
- The multiline block must remain blank because the directive supplies the exact source. No source body or legacy marker comment should be added.
- This preserves original behavior and plausible precompiled source shape by using the official IJG 6b C source whose constants, callbacks, allocations, and branches match the binary.
- Exact no-code proof: not applicable; a source-bearing import is available and required.
- Callback state: this exact managed insertion is applied to UID0000VV, and generated `LibJPEG.cpp` proves all seven imports were emitted with the multiline body blank.

## Final Recommendation

- C01-C18 are applied without reducing their evidence detail.
- Target: function names/roles, full MCP/source/ABI/padding/caller-callee evidence, exact managed import directive, blank multiline body, and `90/92` are applied.
- Metadata: UID, canonical owner UID0000KN, emitter UID0000KN, reconstructable true, blank emitter position, range, summary intent, and nested count are preserved.
- Parent/support: LibJPEG, LibJpeg6bCore, and client_libraries are synchronized at score-neutral support detail; no C++ was added to support pages.
- Leave no item inside the range no-owner/non-emitting; only alignment bytes remain non-source padding.
- Future work: whole-library compiler/options and rebuilt-binary equivalence can be audited separately and is not a blocker to this exact source import.

## Recommended Target Doc Changes

- Path: `by-memory/0x00404a60-0x0040505b.LibJpegInputController.md`.
- Applied `COMPLETION:86 -> 90` and `CONFIDENCE:90 -> 92`.
- Applied the exact managed seven-path import block from `First-Draft C++ Recommendation`; BEGIN/END remain blank.
- Corrected the stale mapping so `0x00404ab0` is `start_input_pass` and `0x00404d50` is `finish_input_pass`.
- Added the complete function inventory, all internal/external padding spans, exact callbacks, source anchors, visibility classes, ABI/build constants, controller/quant-table allocation sizes, xrefs/callees, version strings, staged hashes, source provenance, and dependency relationships.
- Replaced the obsolete unresolved-declarations score rationale with the resolved import/source/ABI rationale and broader whole-library reason for staying below final.
- Preserved owner/emitter/source placement, product-owner rejection, split rejection, static-callback liveness, historical SpecialReport contradiction, and generated-empty-marker pre-callback fact as explicitly historical evidence.

## Recommended Support Doc Changes

- `by-file/LibJPEG.md`: applied exact function/range, padding, source/header hash, callback/dependency, ABI/build, formal import, rejection, and broader-cap detail; retained `92/92` and source root.
- `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`: applied exact MCP evidence, child-map, and internal/external padding detail; retained `90/92`, reconstructable false, blank emitter/C++, and non-emitting index state.
- `by-meta/client_libraries.md`: replaced the bare mapping with full formal import, function/boundary, callback/dependency, ABI/build, source/header hash, rejected-alternative, and broader-cap detail; no metadata/score changed.
- Generated `LibJPEG.cpp`, tracker, and coverage reports were not edited manually. Scoped validators refreshed them.
- SpecialReport `000TP`: do not edit under this assignment. Preserve its contradiction only as historical rejected evidence.

## Score And Metadata Recommendation

- Historical pre-callback snapshot: `86/90`, owner/emitter UID0000KN, reconstructable true, blank position, blank reconstruction value.
- Current callback state: `90/92`, same owner/emitter/reconstructable/position, exact import directive.
- Completion movement: formal source disposition, exact helper/callback names, complete function and padding inventory, ABI/build constants, source provenance, and support synchronization were made implementation-ready and applied.
- Confidence movement: current MCP confirmed real boundary/function/behavior/xref/string facts against hash-matched IJG 6b source.
- Reason not lower: no target-level blocker remains for source identity, visibility, callbacks, ABI, range, owner, or import syntax.
- Reason not higher: this pass did not prove whole-library compiler flags, object ordering, or full rebuilt-binary equivalence; those are broader parent/library final-audit concerns.
- Metadata unchanged: UID, canonical owner, emitter, reconstructable, optional position, range, and nested count.
- Support scores are unchanged; support edits synchronize facts without unrelated score/C++ inflation.

## Open Questions With Attempted Resolution

- Which address is `start_input_pass` versus `finish_input_pass`? Resolved by direct behavior and source: `0x00404ab0` is start; `0x00404d50` is finish.
- Are declaration/helper names still uncertain? Resolved by exact staged source/hash and visibility macros; no target-level name blocker remains.
- Does Windows ABI alter controller/quant-table layout? Resolved by `jconfig.h` unsigned-char boolean plus observed 24-byte controller and 130-byte quant table allocations.
- Is this only a support/empty marker? Rejected by exact source-file range, valid owner/emitter, staged source, and import policy.
- Should it split or move to product code? Rejected by coherent upstream source and internal IJG call/callback graph.
- Which files belong in the import closure? Resolved as `jdinput.c` plus the six staged common/internal headers in the exact directive.
- Remaining unresolved question: exact whole-library compiler/options/rebuild equivalence. Evidence checked includes local Windows configuration, source archive provenance, binary constants/layout, and neighboring pages. It has no target C++ or owner impact and only caps score below final; a separate complete-library rebuild comparison would be required to close it.

## Follow-Up Actions

- Supervisor: independently verify this completed implementation and use validator-owned lifecycle state/path/history for any subsequent supervisor action.
- A-agent: no action required.
- B004: no implementation item remains. B004 ran no execute, lifecycle, move, or archive command.

## Confidence

- Recommendation confidence: high.
- Source/import confidence: high.
- Score confidence: medium-high for `90/92`.
- Remaining uncertainty: broad LibJPEG rebuild equivalence only; no target-blocking uncertainty remains.

## Validator Results

- `python .\tools\validator.py --mode file --file by-memory/0x00404a60-0x0040505b.LibJpegInputController.md --apply --wait-generated --queue-timeout 240`: command `000000008414`, timestamp `2026-07-12T18:24:31-04:00`, exit 0, `ok:1`, generated refresh completed; recorded `86/90 -> 90/92`, blank-to-import registry transition, and `LibJPEG.cpp` update.
- `python .\tools\validator.py --mode file --file by-file/LibJPEG.md --apply --wait-generated --queue-timeout 240`: command `000000008416`, timestamp `2026-07-12T18:25:45-04:00`, exit 0, `ok:1`, generated refresh completed; support metadata unchanged.
- `python .\tools\validator.py --mode file --file by-memory/0x00401000-0x00414283.LibJpeg6bCore.md --apply --wait-generated --queue-timeout 240`: command `000000008417`, timestamp `2026-07-12T18:26:56-04:00`, exit 0, `ok:1`, generated refresh completed; parent metadata/non-emitting state unchanged.
- `python .\tools\validator.py --mode file --file by-meta/client_libraries.md --apply --wait-generated --queue-timeout 240`: command `000000008418`, timestamp `2026-07-12T18:27:59-04:00`, exit 0, `ok:1`, generated refresh completed. Seven pre-existing missing-reference warnings (`0003GZ`, `0003WI`, `0003WJ`, `0003WK`) are unrelated to UID0000VV and were not manually repaired.
- Generated freshness proof: read-only `auto-generated/NexusTK/third_party/libjpeg/LibJPEG.cpp` header is `validator-command-id: 000000008418` and `validator-refreshed-at: 2026-07-12T18:27:59-04:00`, equal to the latest scoped validator. UID0000VV begins at line 11192 with `Completion:90 | Confidence:92`; lines 11193 onward contain imported-source separators/content for `jdinput.c`, `jinclude.h`, `jpeglib.h`, `jconfig.h`, `jmorecfg.h`, `jpegint.h`, and `jerror.h`. No UID0000VV `Empty Emitter Marker` exists.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B004/research/0000VV-LibJpegInputController-source-quality.md` during the initial report-only pass.
- Modified by callback: `by-memory/0x00404a60-0x0040505b.LibJpegInputController.md`, `by-file/LibJPEG.md`, `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`, `by-meta/client_libraries.md`, and this same report.
- Validator-owned side effects, not manually edited: generated `LibJPEG.cpp`, generated coverage/tracker reports, projected stats, and validator registry/reference metadata reported by the scoped commands.
- Renamed: none.
- Leases: each of the four by-* files was leased separately immediately before its edit/validator batch and released successfully immediately after that validator. The post-release lease check showed no active B004 lease. No lease was needed for this own-folder report.
- Report execution/lifecycle: B004 ran no execute, lifecycle, move, archive, registry, or equivalent command. Supervisor-owned lifecycle state is external to this research content.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor Gate 1 accepted exact artifact SHA256 `6E19D2CA967C480B5976559A4780B3856B5D8077F1D3F0FEE825A9F3BE6B6518` before implementation.
- [x] Target `by-memory/0x00404a60-0x0040505b.LibJpegInputController.md` contains all C01-C14 and C18 evidence at report-level detail.
- [x] Support `by-file/LibJPEG.md` contains C01-C06, C08-C12, C14-C15, and C18 without score change.
- [x] Support `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md` contains C01-C04, C08-C12, C14, C16, and C18; remains `90/92`, reconstructable false, blank emitter/C++.
- [x] Support `by-meta/client_libraries.md` contains C01, C12-C14, C17-C18 without metadata/score inflation.
- [x] Historical pre-callback target snapshot, MCP database `545b4991` evidence-time health, JSON-RPC evidence, source/header hashes, provenance, generated empty-marker snapshot, and old-report lead treatment are recorded.
- [x] Claim And Incorporation Ledger records callback verification state for every accepted C01-C18 claim.
- [x] Target score is `90/92`; support scores are unchanged.
- [x] Owner/emitter UID0000KN, reconstructable true, blank position, range, nesting, and source placement remain unchanged.
- [x] `0x00404ab0` is `start_input_pass`, `0x00404d50` is `finish_input_pass`, and all six other exact identities remain.
- [x] All external/internal NOP padding and no-split/no-data-island analysis are preserved.
- [x] Callback, ABI, build-constant, caller/callee, marker/memory/master/utility relationships are applied at full report detail.
- [x] Exact seven-path formal import directive is applied; managed multiline block remains blank.
- [x] Product-owner, per-helper split, blank/no-code, pasted-source, and legacy-marker rejections, static-callback liveness, and historical SpecialReport contradiction are preserved.
- [x] No Wave2/Wave3 evidence is incorporated.
- [x] Broader whole-library rebuild-equivalence uncertainty and score-only impact are documented.
- [x] One immediate lease was acquired/released per changed by-* edit/validator batch; generated/report files were not leased.
- [x] One scoped `--wait-generated` validator per changed by-* file passed; commands `8414`, `8416`, `8417`, `8418` and exact metadata/results are recorded.
- [x] Generated `LibJPEG.cpp`, tracker, coverage, supervisor, registry, and lifecycle state were not manually edited.

Implementation callback pass:
- [x] Exact Gate 1 report artifact was accepted by supervisor for implementation.
- [x] C01-C18 are incorporated/applied or confirmed already present claim by claim; no claim is blocked.
- [x] All accepted target/support facts are retained at report-level detail.
- [x] Metadata/score/owner/emitter/range/source-placement/C++ states are applied exactly.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence are preserved.
- [x] Open questions are closed or retained with evidence-backed score/C++ impact.
- [x] Scoped validator and generated freshness proof are recorded exactly.
- [x] Every lease was released immediately after its scoped edit/validator batch; final lease report was empty.
- [x] No accepted implementation item remains unapplied or blocked.
- [x] B004 performed no report execution/lifecycle/move/archive command; supervisor-owned lifecycle state remains external.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000008445","destination_path":"executed-b-agent-research/B004/0000VV-LibJpegInputController-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0000VV-LibJpegInputController-source-quality.md","timestamp":"2026-07-12T18:37:39-04:00","uid":"0000VV"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
