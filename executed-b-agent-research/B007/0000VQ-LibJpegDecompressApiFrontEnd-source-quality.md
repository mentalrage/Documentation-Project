** TARGET-REPORT-UID:0000VQ **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# B007 Source-Quality Report: [UID:0000VQ] LibJpegDecompressApiFrontEnd

Agent: B007  
Assignment: `B007-report-0000VQ-libjpeg-decompress-api-front-end-source-quality-20260626`  
Report timestamp: 2026-06-26 20:07:25 -04:00  
Target: `by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md`  
Mode: report-only research. No leases taken. No target/support by-* docs, generated files, project-level files, validator/tool state, IDA DB files, or coverage reports were edited.

## Current Target State

- Current by-memory header: `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000KN`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KN`, blank optional emitter metadata, blank formal C++ block, `Nested:4`.
- Current owner/emitter route remains correct: exact target -> [UID:0000KN] `LibJPEG` -> `NexusTK/third_party/libjpeg/`.
- Current prose correctly identifies IJG libjpeg 6b and the active product decode sequence, but it has three source-quality defects that are now resolvable:
  - the function table omits retained raw/unmodeled stock helpers inside the target at `0x004012a0`, `0x00401580`, and `0x004015d0`;
  - the target and support docs overstate the `0x004019e3-0x00401b00` gap as padding/no modeled function gap, while live listing shows raw `jdapistd.c` code at `0x004019f0` and `0x00401a60`;
  - the page is not safe for a static-embed formal block because it covers all of `jdapimin.c` but only a prefix of `jdapistd.c`, leaving the `jpeg_start_output`/`jpeg_finish_output` tail outside the target range.

## MCP Session And Tool Facts

IDA MCP was available and responsive. This report is not fallback-only.

- Endpoint: `http://127.0.0.1:13337/mcp`.
- `initialize` and `tools/list` succeeded.
- Active database: `80de0a67`.
- `idb_list`: one active worker session, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `pid 26892`, `is_active:true`, `is_analyzing:false`.
- `server_health(database=80de0a67)`: `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.
- `entity_query(functions, 0x004011b0-0x004019f0)` reports ten modeled functions inside [UID:0000VQ], from `sub_4011B0` through `sub_401930`.
- `lookup_funcs` confirms modeled functions at `0x004011b0`, `0x00401290`, `0x004012b0`, `0x00401320`, `0x004013e0`, `0x00401620`, `0x004016e0`, `0x004017c0`, `0x00401890`, and `0x00401930`; `0x004019e3` is not a function; `0x00401b00` is the modeled marker-reader start.
- `lookup_funcs` also confirms `0x004012a0`, `0x00401580`, `0x004015d0`, `0x004019f0`, and `0x00401a60` are not modeled function objects even though disassembly at those starts shows source-shaped code.
- `xrefs_to(addrs=[0x004012a0,0x00401580,0x004015d0,0x004019f0,0x00401a60])` reports zero direct cross-references to all five raw helper starts.
- One initial `xrefs_to` probe used the wrong `addr` schema and returned `missing required parameters: ['addrs']`; the corrected `addrs` call succeeded. This was a schema correction, not MCP unavailability.

Fresh MCP evidence used:

- `analyze_component` for the ten modeled functions in [UID:0000VQ].
- `analyze_function` for modeled public/local functions `0x004011b0`, `0x00401290`, `0x004012b0`, `0x00401320`, `0x004013e0`, `0x00401620`, `0x004016e0`, `0x004017c0`, `0x00401890`, and `0x00401930`.
- `analyze_function` for product callers `0x004d07b0`, `0x004d0a90`, and in-memory JPEG source setup `0x004e7030`.
- `disasm` for raw/unmodeled helpers at `0x004012a0`, `0x00401580`, `0x004015d0`, `0x004019f0`, and `0x00401a60`.
- `search_text` for `sub_4017C0` / `4017C0` over `0x004019e3-0x00401b00`, confirming a call at `0x00401a49`.

## Documents And Source Checked

- Target: `source-3/project-documentation/by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md`.
- Parent/support: `by-file/LibJPEG.md`, `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`, `by-memory/0x00401b00-0x004038c7.LibJpegMarkerReader.md`, `by-meta/client_libraries.md`.
- Product caller/support: `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md`, plus child caller pages for the JPF/raw JPEG wrappers as context.
- Staged source embeds: `source-3/third_party_embeds/libjpeg/jdapimin.c`, `jdapistd.c`, `jpeglib.h`, `jpegint.h`, `jmorecfg.h`, and `jerror.h`.
- Documentation mirror of obtained third-party files: `by-meta/obtained_thirdparty_files/static_embeds/libjpeg-6b/jdapimin.c`, `jdapistd.c`, `jpeglib.h`, `jpegint.h`, `jmorecfg.h`, and `jerror.h`.
- Tracker context read-only: `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` still show stale generated `80/85` for [UID:0000VQ]; target by-memory header is already `86/89`.

## Live Boundary And Range Findings

Modeled functions in [UID:0000VQ]:

| Address/range | IDA object | Stock source match | Notes |
| --- | --- | --- | --- |
| `0x004011b0-0x00401287` | `sub_4011B0`, size `0xd8` | `jpeg_CreateDecompress` in `jdapimin.c` | Checks caller version `62`, struct size `432`, clears `0x1b0` bytes, initializes memory manager, marker reader, input controller, and sets state `200` / `DSTATE_START`. |
| `0x00401290-0x0040129b` | `sub_401290`, size `0x0c` | `jpeg_destroy_decompress` in `jdapimin.c` | Thin wrapper over common `jpeg_destroy` / `0x00404a00`; called from both product JPEG wrappers. |
| `0x004012b0-0x0040131f` | `sub_4012B0`, size `0x70` | `jpeg_read_header` in `jdapimin.c` | Validates states `200/201`, calls `jpeg_consume_input`, returns reached-SOS/reached-EOI behavior, aborts tables-only EOI when required. |
| `0x00401320-0x004013bb` | `sub_401320`, size `0x9c` | `jpeg_consume_input` in `jdapimin.c` | State switch over `200-210`, invokes source `init_source`, input controller `consume_input`, and local default parameter helper on SOS. |
| `0x004013e0-0x00401576` | `sub_4013E0`, size `0x197` | `default_decompress_parms` in `jdapimin.c` | Local helper; source color/default selection, RGB component-id checks (`82/71/66`), JFIF/Adobe transform checks, and output defaults. |
| `0x00401620-0x004016da` | `sub_401620`, size `0xba` | `jpeg_finish_decompress` in `jdapimin.c` | Handles scanline completion, finish output pass, state `210`, drains input until EOI, calls source `term_source`, then common abort/reset. |
| `0x004016e0-0x004017be` | `sub_4016E0`, size `0xde` | `jpeg_start_decompress` in `jdapistd.c` | Starts master/output pipeline, handles buffered image state, preload loop, and calls local `output_pass_setup`. |
| `0x004017c0-0x00401882` | `sub_4017C0`, size `0xc2` | `output_pass_setup` in `jdapistd.c` | Local pass setup shared by `jpeg_start_decompress` and, outside this target, `jpeg_start_output`. |
| `0x00401890-0x00401927` | `sub_401890`, size `0x97` | `jpeg_read_scanlines` in `jdapistd.c` | Validates state `205`, progress hook, main controller `process_data`, increments output scanline, warns with message `123` on excess reads. |
| `0x00401930-0x004019e3` | `sub_401930`, size `0xb3` | `jpeg_read_raw_data` in `jdapistd.c` | Validates state `206`, progress hook, row-group size check, raw-data controller callback, increments output scanline by row-group size. |

Raw/unmodeled source-shaped helpers inside [UID:0000VQ]:

| Address/range | IDA status | Stock source match | Evidence |
| --- | --- | --- | --- |
| `0x004012a0-0x004012ab` | no function object, no direct xrefs | `jpeg_abort_decompress` in `jdapimin.c` | Disasm loads the `cinfo` argument, calls common `jpeg_abort` / `0x004049c0`, returns; staged source line `jdapimin.c:103` is the same common-abort wrapper. |
| `0x00401580-0x004015c4` | no function object, no direct xrefs | `jpeg_input_complete` in `jdapimin.c` | Disasm validates `global_state` in `200..210`, reports bad state `20` when invalid, returns input controller byte at `+0x11`; staged source line `jdapimin.c:334` returns `inputctl->eoi_reached`. |
| `0x004015d0-0x00401614` | no function object, no direct xrefs | `jpeg_has_multiple_scans` in `jdapimin.c` | Disasm validates `global_state` in `202..210`, reports bad state `20` when invalid, returns input controller byte at `+0x10`; staged source line `jdapimin.c:349` returns `inputctl->has_multiple_scans`. |

Raw/unmodeled `jdapistd.c` tail outside [UID:0000VQ] and before [UID:0000VR]:

| Address/range | IDA status | Stock source match | Evidence |
| --- | --- | --- | --- |
| `0x004019f0-0x00401a52` | no function object, no direct xrefs | `jpeg_start_output` in `jdapistd.c` | Disasm validates states `207` / `204`, clamps scan number, writes `output_scan_number`, and calls `0x004017c0`; staged source line `jdapistd.c:228` is guarded by `D_MULTISCAN_FILES_SUPPORTED`. |
| `0x00401a60-0x00401af2` | no function object, no direct xrefs | `jpeg_finish_output` in `jdapistd.c` | Disasm handles states `205/206/208`, calls master finish-output-pass, loops input controller consume until output scan catches up or EOI, then returns to state `207`; staged source line `jdapistd.c:253` is guarded by `D_MULTISCAN_FILES_SUPPORTED`. |

Boundary conclusion: `0x004019e3` is the correct half-open end for the current target page, but it is not an immediate source-module boundary to the marker reader. `0x004019e3-0x004019f0` is alignment, `0x004019f0-0x00401af2` is raw retained `jdapistd.c`, `0x00401af3-0x00401b00` is alignment, and [UID:0000VR] starts at `0x00401b00`.

## Source Comparison Findings

- `source-3/third_party_embeds/libjpeg/jpeglib.h:33` defines `JPEG_LIB_VERSION 62`, matching the live `jpeg_CreateDecompress` version check.
- `jdapimin.c:38-40` checks `SIZEOF(struct jpeg_decompress_struct)`; live code checks caller struct size `432` and clears `0x1b0` bytes.
- `jpegint.h:29-39` defines the decompression state numbers observed live: `DSTATE_START=200`, `DSTATE_INHEADER=201`, `DSTATE_READY=202`, `DSTATE_PRELOAD=203`, `DSTATE_PRESCAN=204`, `DSTATE_SCANNING=205`, `DSTATE_RAW_OK=206`, `DSTATE_BUFIMAGE=207`, `DSTATE_BUFPOST=208`, and `DSTATE_STOPPING=210`.
- `jmorecfg.h:286` enables `D_MULTISCAN_FILES_SUPPORTED`, explaining why the raw `jpeg_start_output` and `jpeg_finish_output` bodies are present even though the product wrappers do not call them.
- `jerror.h` message order matches live diagnostic codes used by this cluster: bad library version, bad struct size, bad state, buffer too small, too few scanlines, and too many scanlines.
- The staged source copy under `source-3/third_party_embeds/libjpeg/` and the documentation mirror under `by-meta/obtained_thirdparty_files/static_embeds/libjpeg-6b/` agree on the relevant file contents. No external/stale Wave2/Wave3 material was needed as evidence.

## Product Caller Evidence

The live product decode path still matches the current documentation, with the added negative evidence that several retained stock APIs are unused.

- `analyze_function(0x004d07b0)` confirms `DecodeJpfImageToTileContext` recognizes `JPF`, installs the IJG error manager at `0x00401000`, calls `jpeg_CreateDecompress` at `0x004011b0` with `(62, 432)`, installs the in-memory source helper at `0x004e7030`, calls read-header/start/read-scanlines/finish/destroy helpers at `0x004012b0`, `0x004016e0`, `0x00401890`, `0x00401620`, and `0x00401290`, converts RGB scanlines to RGB565, and is called by profile/look paths `0x005067f3` and `0x0059fff4`.
- `analyze_function(0x004d0a90)` confirms `DecodeJpegBufferToTileContext` uses the same IJG sequence for raw in-memory JPEG blobs and is called from the minimap path at `0x004544a8`.
- `analyze_function(0x004e7030)` confirms the NexusTK in-memory source manager stores the caller buffer pointer/size, callback slots including `sub_4E4E70`, `sub_4E4EB0`, and the marker-reader fill/read callback `0x00401b00`; this is local product glue, not stock `jdatasrc.c`.
- Modeled xrefs/callers show `jpeg_read_raw_data` at `0x00401930` has no direct callers in this binary. It is retained stock API code.
- Raw helper starts `0x004012a0`, `0x00401580`, `0x004015d0`, `0x004019f0`, and `0x00401a60` have zero direct xrefs. They should remain documented as retained IJG public helpers, not product code.

## Source-Form Decision

Keep [UID:0000VQ]'s formal `RECONSTRUCTION_CPP` block blank.

Target-specific no-code proof:

- The target is `RECONSTRUCTABLE:TRUE` and has a valid emitter route through [UID:0000KN], but the current by-memory range is not an exact source-file page.
- `0x004011b0-0x004016da` maps cleanly to full `jdapimin.c` content after the error-manager prelude, including raw `jpeg_abort_decompress`, `jpeg_input_complete`, and `jpeg_has_multiple_scans`.
- `0x004016e0-0x004019e3` maps only the prefix of `jdapistd.c`: `jpeg_start_decompress`, `output_pass_setup`, `jpeg_read_scanlines`, and `jpeg_read_raw_data`.
- The same `jdapistd.c` source file continues immediately after this target as raw code at `0x004019f0-0x00401af2` for `jpeg_start_output` and `jpeg_finish_output`.
- A static-embed marker for `jdapistd.c` would be range-unsafe in [UID:0000VQ] because it would claim source bytes outside the target range. A static-embed marker for only `jdapimin.c` would be incomplete because the target also contains `jdapistd.c` prefix bytes.
- Handwritten/decompiler-derived C++ is inappropriate for stock IJG code. The reconstruction source should come from the staged third-party files under `third_party_embeds/libjpeg`, with by-memory pages serving as source-map evidence.

Recommended disposition: [UID:0000VQ] should remain a non-emitting source-map/index page unless the supervisor creates/extends exact source-file children. The source-bearing future split would be one exact `jdapimin.c` slice and one exact `jdapistd.c` slice that includes the raw `0x004019f0-0x00401af2` tail. Until then, the formal target block should stay empty with this no-code proof.

## Rejected Alternatives

- Emit handwritten C++ for the libjpeg APIs: rejected. These are stock IJG library routines with staged source available; source-quality reconstruction should vendor the source, not restate decompiled bodies.
- Insert a static-embed marker for all of `jdapistd.c` into [UID:0000VQ]: rejected by range safety because `jpeg_start_output` and `jpeg_finish_output` live outside the target at `0x004019f0-0x00401af2`.
- Insert only a `jdapimin.c` static-embed marker into [UID:0000VQ]: rejected as incomplete target coverage because `0x004016e0-0x004019e3` is `jdapistd.c`.
- Treat `0x004019e3-0x00401b00` as padding: rejected. Live disassembly shows raw code bodies at `0x004019f0` and `0x00401a60`.
- Treat the raw/unmodeled helpers inside [UID:0000VQ] as padding or compiler noise: rejected. They match stock public IJG helper bodies and source-line anchors.
- Move this code to `ImageLoaders`: rejected. Product wrappers at `0x004d07b0` and `0x004d0a90` consume the library; the IJG internals remain third-party LibJPEG.
- Move the `0x004e7030` in-memory source manager into stock LibJPEG: rejected. It is NexusTK-local source-manager glue that installs callbacks and buffer pointers for product wrappers.
- Use `jdatasrc.c` as the active product source-manager path: rejected for the observed decode path. The product wrappers call `0x004e7030`, not stock file/stdin source setup.
- Lower `RECONSTRUCTABLE` to false: rejected. Static embedded third-party source is reconstructable through vendored source under [UID:0000KN], but this mixed range should not emit target-local code.
- Change owner/emitter away from [UID:0000KN]: rejected. All current source and live evidence points to the IJG LibJPEG third-party module.

## Ranked Ownership And Source Placement

1. [UID:0000KN] `LibJPEG`: accepted owner/emitter. The code is staged IJG libjpeg 6b source and belongs under `NexusTK/third_party/libjpeg/`.
2. [UID:0000VP] `LibJpeg6bCore`: accepted broad parent/index for the full static code island, but not the direct source file owner.
3. Future exact source-file children: recommended source-map improvement. A `jdapimin.c` source-bearing child should cover the full mapped decompression-min API slice; a `jdapistd.c` child should include the `0x004019f0-0x00401af2` tail.
4. [UID:0000K3] `ImageLoaders` / [UID:000175] `ImageDecodeWrappers`: rejected direct owner. These are product consumers/wrappers.
5. [UID:0000VR] `LibJpegMarkerReader`: rejected as successor owner for the gap. It starts at `0x00401b00`; the raw `jdapistd.c` tail before it is not marker-reader code.

## Recommended Metadata

Change only [UID:0000VQ] target metadata:

- `COMPLETION:86` -> `COMPLETION:88`
- `CONFIDENCE:89` -> `CONFIDENCE:91`
- Keep `CANONICAL_OWNER:0000KN`
- Keep `RECONSTRUCTABLE:TRUE`
- Keep `EMITTER_UIDS:0000KN`
- Keep `EMITTER_POSITION_OPTIONAL:` blank
- Keep `Nested:4`
- Keep formal `RECONSTRUCTION_CPP CODE` blank

Score rationale:

- Completion should rise because the implementation can repair the full target source map, add the missing raw `jdapimin.c` helpers, correct the false padding/successor statement, record exact live MCP session facts, and provide a target-specific no-code proof.
- Completion should remain below 90 because the target is a mixed/partial source-file slice and should not yet emit a formal static-embed marker.
- Confidence should rise because current live IDA MCP, staged IJG 6b source, and product caller analysis all agree on the owner, range contents, constants, and negative xref evidence.
- Confidence should remain below final because IDA does not model several retained stock starts as functions and because the future exact source-file split has not yet been created.

Recommended item summary:

`Current MCP/source comparison resolves the libjpeg decompression API slice: full jdapimin.c mapping including raw jpeg_abort_decompress/input_complete/has_multiple_scans helpers, jdapistd.c prefix through jpeg_read_raw_data, product JPF/raw JPEG caller sequence, local in-memory source-manager route, no direct xrefs to retained raw public helpers, and a range-safety proof for leaving formal C++ blank until exact source-file children cover the jdapistd.c tail at 0x004019f0-0x00401af2.`

## Recommended Target Doc Changes

For `by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md`:

- Update header metadata to `COMPLETION:88` and `CONFIDENCE:91`; leave owner/emitter/reconstructable/optional emitter/`Nested:4` unchanged.
- Keep the formal `RECONSTRUCTION_CPP` block blank and add the no-code proof from this report.
- Update the function mapping table to include raw/unmodeled `jpeg_abort_decompress` at `0x004012a0-0x004012ab`, `jpeg_input_complete` at `0x00401580-0x004015c4`, and `jpeg_has_multiple_scans` at `0x004015d0-0x00401614`.
- Refresh modeled function evidence for all ten modeled starts using current MCP session `80de0a67`.
- Correct the boundary section: `0x004019e3` is the current target half-open end, but `0x004019f0-0x00401af2` contains raw `jdapistd.c` `jpeg_start_output`/`jpeg_finish_output`, so [UID:0000VR] is not immediately after pure padding.
- Preserve product caller evidence for `0x004d07b0` and `0x004d0a90`, and add negative evidence that `jpeg_read_raw_data`, `jpeg_abort_decompress`, `jpeg_input_complete`, `jpeg_has_multiple_scans`, `jpeg_start_output`, and `jpeg_finish_output` have no direct product xrefs in the current IDB.
- Add source constants and source-file anchors: `JPEG_LIB_VERSION 62`, `SIZEOF(struct jpeg_decompress_struct)` / live `432`, state constants `200-210`, `D_MULTISCAN_FILES_SUPPORTED`, and the staged source file paths.
- Replace stale open questions with evidence-backed remaining issues: exact source-file child split for `jdapimin.c`/`jdapistd.c`, raw function object modeling, and static-embed marker placement.
- Add rejected alternatives and score rationale from this report.

## Recommended Support Doc Changes

For `by-file/LibJPEG.md`:

- Update the focused source-match notes for [UID:0000VQ] to say it maps full `jdapimin.c` plus the front part of `jdapistd.c`; add that `0x004019f0-0x00401af2` is raw `jdapistd.c` tail before marker reader.
- Update the boundary-check paragraph that lists modeled child heads so it does not imply `0x004019e3-0x00401b00` is only padding. Keep the modeled-child-head fact, but add the raw-code caveat.
- Keep metadata unchanged at `90/86`; this is a support correction, not a whole-file score change.

For `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`:

- Update the key-anchor/evidence text for the decompression API front end with the same raw `jdapimin.c` helper additions and `jdapistd.c` tail caveat.
- Add a concise open-question/follow-up note that the current broad island still lacks an exact source-file child for the full `jdapistd.c` range through `0x00401af2`.
- Keep metadata unchanged at `85/89`; broad core score remains capped by unmapped lower helper clusters.

For `by-memory/0x00401b00-0x004038c7.LibJpegMarkerReader.md`:

- Replace the statement that IDA has no modeled function in the padding gap after [UID:0000VQ] with the corrected fact: there is no modeled function object, but raw `jdapistd.c` code exists at `0x004019f0` and `0x00401a60`; [UID:0000VR] starts after that tail and alignment at `0x00401b00`.
- Keep metadata unchanged at `86/90`; marker-reader source ownership and body evidence are unaffected.

For `by-meta/client_libraries.md`:

- Add one support sentence to the IJG libjpeg section noting that [UID:0000VQ] is third-party source-map evidence for the product decode path, while retained unreferenced `jdapistd.c` buffered-image output APIs appear as raw static-library code before the marker reader. This prevents future product-source reassignment of the raw gap.
- Keep metadata unchanged (`-1/-1` index page).

No edit needed for [UID:000175] `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md` in this callback unless the supervisor wants current-session timestamp parity. No-edit proof: it already records the active product JPEG wrapper sequence through `0x00401000`, `0x004011b0`, `0x004e7030`, `0x004012b0`, `0x004016e0`, `0x00401890`, `0x00401620`, and `0x00401290`; it already states that IJG internals stay in LibJPEG and wrapper/tile conversion policy stays in ImageLoaders. Current MCP adds no contradiction to that page.

No edit needed for `by-memory/0x004d07b0-0x004d09a7.DecodeJpfImageToTileContext.md`, `by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md`, or `by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md` unless the implementation wants optional timestamp refresh. Their existing caller/callee and source-manager summaries already match current live facts at useful detail.

## Generated And Coverage Expectations

B007 must not edit generated files, project-level files, validator/tool state, IDA DB files, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`.

After supervisor acceptance and implementation, expected supervisor/validator-owned follow-up:

- Run scoped validators for every changed by-* file.
- Let validator-owned registry/generated refresh occur through the validator, not manual B007 edits.
- If the manual by-memory coverage row is refreshed by a supervisor-owned process, update the stale generated-style [UID:0000VQ] row to mention the corrected raw helper/source-split facts and blank-formal-code proof.

## Validator Results

Implementation callback validators were run from `source-3/project-documentation`.

- `000000003281` at `2026-06-26T20:19:09-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md --apply --no-generated-refresh --lock-timeout 240`; exit `0`, `ok: 1`, `completion_update 0000VQ 88`, `confidence_update 0000VQ 91`, generated refresh skipped.
- `000000003282` at `2026-06-26T20:19:32-04:00`: `python .\tools\validator.py --mode file --file by-file/LibJPEG.md --apply --no-generated-refresh --lock-timeout 240`; exit `0`, `ok: 1`, metadata unchanged at `90/86`, generated refresh skipped.
- `000000003283` at `2026-06-26T20:19:44-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x00401000-0x00414283.LibJpeg6bCore.md --apply --no-generated-refresh --lock-timeout 240`; exit `0`, `ok: 1`, metadata unchanged at `85/89`, generated refresh skipped.
- `000000003284` at `2026-06-26T20:19:51-04:00`: `python .\tools\validator.py --mode file --file by-memory/0x00401b00-0x004038c7.LibJpegMarkerReader.md --apply --no-generated-refresh --lock-timeout 240`; exit `0`, `ok: 1`, metadata unchanged at `86/90`, generated refresh skipped.
- `000000003285` at `2026-06-26T20:19:56-04:00`: `python .\tools\validator.py --mode file --file by-meta/client_libraries.md --apply --no-generated-refresh --lock-timeout 240`; exit `0`, `ok: 1`, generated refresh skipped. This exposed pre-existing registry/reference issues and attempted unrelated `uid_link_update` rewrites for `00041N`/`00041O`; B007 restored the correct Zlib links because the proposed targets were MidiPlayer pages.
- `000000003286` at `2026-06-26T20:20:33-04:00`: final `client_libraries.md` dry-run validator after restoring the Zlib links: `python .\tools\validator.py --mode file --file by-meta/client_libraries.md --no-generated-refresh --lock-timeout 240`; exit `0`, `ok: 1`, `apply: False`, generated refresh skipped. The remaining `missing_ref_uid`, `missing_ref_target`, and `uid_link_update` rows are pre-existing validator-registry/reference issues left unapplied.

## Changed Files

Implementation callback changed:

- `by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md`
- `by-file/LibJPEG.md`
- `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`
- `by-memory/0x00401b00-0x004038c7.LibJpegMarkerReader.md`
- `by-meta/client_libraries.md`
- `tools/leaser/Agents/Agent-B007/research/0000VQ-LibJpegDecompressApiFrontEnd-source-quality.md`

No target/support docs outside that accepted edit set were changed. No `by-memory/-coverage-report.md` or other `-coverage-report.md` files were edited. No IDA DB files were edited. Validators were run with `--no-generated-refresh`; B007 did not manually edit generated/project-level/tool-state files.

Lease proof:

- Lease command succeeded for the five immediate by-* edit files before edits.
- After the edit/validator batch, `python .\tools\leaser\leaser.py B007 unlease ...` returned `Rejected[No active lease]` for all five paths.
- `tools/leaser/Agents/current_leases.md` read after the unlease attempt contained no `B007` entries and no entries for the five implementation paths.

## Confidence

- Recommendation confidence: high for owner, source identity, product caller route, and blank formal C++ disposition.
- Score confidence: medium-high for `88/91`.
- Remaining uncertainty: exact source-file child creation policy is supervisor-owned. This report proves the source-map correction and range-safety issue, but it does not create or rename by-memory pages during report-only work.

## Implementation Tracking Checklist

- [x] Supervisor validation required before implementation. Proof: supervisor message accepted this report for implementation callback and updated `goal.md`.
- [x] Target doc to update: `by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md`. Proof: target edited with accepted source-map/no-code content and validated by command `000000003281`.
- [x] Target metadata to apply: `COMPLETION:88`, `CONFIDENCE:91`; keep `CANONICAL_OWNER:0000KN`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KN`, blank optional emitter, and `Nested:4`. Proof: target header now shows `88/91`; validator command `000000003281` reported `completion_update 0000VQ 88`, `confidence_update 0000VQ 91`, and `canonical_owner_update 0000VQ 0000KN`.
- [x] Keep the target formal `RECONSTRUCTION_CPP CODE` block blank; insert no static-embed marker or handwritten C++ in [UID:0000VQ]. Proof: final target still has immediate `RECONSTRUCTION_CPP CODE:BEGIN` then `END` with no intervening body.
- [x] Add the target-specific no-code proof: [UID:0000VQ] is a mixed source-map/index range covering full `jdapimin.c` plus only a prefix of `jdapistd.c`; full `jdapistd.c` continues at raw `0x004019f0-0x00401af2`. Proof: target `Source-Form Decision` section records this exact range-safety proof.
- [x] Add current MCP session facts: session `80de0a67`, health ok, ten modeled target functions, raw helper starts not modeled as functions, zero xrefs to raw helper/tail starts, product wrapper callers, and source-manager route. Proof: target `Live IDA Refresh` and `Product Caller Evidence` sections record these facts.
- [x] Expand target function mapping with raw `jpeg_abort_decompress`, `jpeg_input_complete`, and `jpeg_has_multiple_scans`. Proof: target function table has rows for `0x004012a0-0x004012ab`, `0x00401580-0x004015c4`, and `0x004015d0-0x00401614`.
- [x] Correct target boundary/successor prose to record raw `jpeg_start_output` and `jpeg_finish_output` before [UID:0000VR]. Proof: target `Range Role` and `Outside-Target Tail Before Marker Reader` sections document `0x004019f0-0x00401a52` and `0x00401a60-0x00401af2`.
- [x] Preserve source comparison facts: staged `third_party_embeds/libjpeg`, `JPEG_LIB_VERSION 62`, live struct size `432`, DSTATE constants `200-210`, `D_MULTISCAN_FILES_SUPPORTED`, and relevant IJG diagnostics. Proof: target `Source Comparison Facts` section records each item.
- [x] Preserve product caller and negative xref evidence: active RGB scanline wrappers use `0x004011b0`, `0x004012b0`, `0x004016e0`, `0x00401890`, `0x00401620`, `0x00401290`; retained raw/public helpers have no direct product xrefs. Proof: target `Product Caller Evidence` and `Live IDA Refresh` sections record the wrapper calls and zero-xref result.
- [x] Preserve rejected alternatives: handwritten C++, range-unsafe static-embed markers, padding-gap claim, ImageLoaders ownership, stock `jdatasrc.c` active-route claim, and [UID:0000VR] ownership of the raw gap. Proof: target `Rejected Alternatives` section covers each rejected path.
- [x] Support doc to update: `by-file/LibJPEG.md` with the [UID:0000VQ] mixed source-file and raw `jdapistd.c` tail caveat; keep score unchanged. Proof: `LibJPEG.md` focused source-match and boundary paragraphs updated; validator command `000000003282` passed with metadata still `90/86`.
- [x] Support doc to update: `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md` with the same corrected child/source-tail evidence; keep score unchanged. Proof: key-anchor, evidence, open-question, and changes sections updated; validator command `000000003283` passed with metadata still `85/89`.
- [x] Support doc to update: `by-memory/0x00401b00-0x004038c7.LibJpegMarkerReader.md` to correct the "padding gap/no modeled function" statement; keep score unchanged. Proof: range-role/evidence/changes sections now state the raw `jdapistd.c` tail before `0x00401b00`; validator command `000000003284` passed with metadata still `86/90`.
- [x] Support doc to update: `by-meta/client_libraries.md` with a concise third-party/static-library caveat for raw retained `jdapistd.c` tail code; keep score unchanged. Proof: support sentence added after the dependency table; final dry-run validator command `000000003286` passed with `ok:1` and pre-existing registry warnings left unapplied.
- [x] Record no-edit proof for `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md`: current page already has equal-or-greater product caller/library-boundary detail. Proof: current page records JPF/raw JPEG wrapper rows, the library boundary paragraph with `0x00401000`, `0x004011b0`, `0x004e7030`, `0x004012b0`, `0x004016e0`, `0x00401890`, `0x00401620`, and `0x00401290`, and the rule not to move IJG internals into `ImageLoaders.cpp`.
- [x] Record no-edit proof for optional child/support pages `DecodeJpfImageToTileContext`, `DecodeJpegBufferToTileContext`, and `ImageLibVectorSupportHelpers` if not edited. Proof: `DecodeJpfImageToTileContext` and `DecodeJpegBufferToTileContext` already record the IJG sequence, version `62`, struct size `432`, `0x004e7030`, RGB scanlines, finish/destroy, and ImageLoaders/LibJPEG boundary; `ImageLibVectorSupportHelpers` already records `0x004e7030` as `InitializeTileDecodeCallbackRecord` called by JPF/JPEG wrappers and writing callback pointers including `0x00401b00`.
- [x] Run scoped validator for the target by-memory file after implementation. Proof: command `000000003281`, timestamp `2026-06-26T20:19:09-04:00`, exit `0`, `ok:1`.
- [x] Run scoped validators for every edited support by-* file. Proof: commands `000000003282`, `000000003283`, `000000003284`, `000000003285`, and final `client_libraries.md` dry-run `000000003286` all exited `0` with `ok:1`.
- [x] Do not edit generated files, project-level files, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`; supervisor/validator owns generated/tracker/coverage refresh. Proof: B007 manually edited only the accepted by-* docs and this report; validators were invoked with `--no-generated-refresh`; no coverage report or IDA DB was edited.
- [x] Release any implementation leases immediately after the edit/validator batch. Proof: unlease command after validators reported no active B007 lease on all five implementation paths, and `tools/leaser/Agents/current_leases.md` had no B007 entries.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000VQ-LibJpegDecompressApiFrontEnd-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0000VQ-LibJpegDecompressApiFrontEnd-source-quality.md","timestamp":"2026-06-26T20:24:08","uid":"0000VQ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
