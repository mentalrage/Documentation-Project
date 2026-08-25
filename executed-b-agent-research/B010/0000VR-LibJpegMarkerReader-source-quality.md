** TARGET-REPORT-UID:0000VR **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B010 Research Report - [UID:0000VR] LibJpegMarkerReader

## Report Scope

- Assignment: `B010-report-0000VR-libjpeg-marker-reader-source-quality-20260626`.
- Target: [UID:0000VR] `by-memory/0x00401b00-0x004038c7.LibJpegMarkerReader.md`.
- Required output: report-only source-quality research for the IJG libjpeg marker reader.
- Mode constraints observed: no by-* edits, no generated/project-level/manual coverage/tool-state/IDA DB edits, no leases, and no subagents.
- Evidence standard: IDA MCP was mandatory and was used successfully. This is not a fallback-only report.

## Current Target State

Current target metadata:

| Field | Current value |
| --- | --- |
| UID | `0000VR` |
| File | `by-memory/0x00401b00-0x004038c7.LibJpegMarkerReader.md` |
| Completion / confidence | `86/90` |
| Canonical owner | `0000KN` |
| Reconstructable | `TRUE` |
| Emitter UIDs | `0000KN` |
| Formal C++ | blank |
| Summary | `` `jpeg-6b/jdmarker.c` source-file ownership. `` |
| Nested | `0` |

The current ownership is correct, but the current range and source-quality notes are incomplete:

- `0x00401b00-0x004038c7` covers the modeled marker-reader bodies and the no-function `jpeg_save_markers` raw body at `0x00403560-0x00403633`.
- It does not cover the trailing raw `jpeg_set_marker_processor` body at `0x004038d0-0x0040391e`.
- The current prose says the decompression API predecessor gap is only "no modeled function" padding. Live disassembly shows raw `jdapistd.c` code at `0x004019f0-0x00401af2` before alignment into `0x00401b00`.

## MCP Session And Health

IDA MCP was live and responsive during this pass.

| MCP fact | Evidence |
| --- | --- |
| MCP server | `initialize` returned server `ida-pro-mcp` version `1.0.0`, protocol `2025-06-18`. |
| Session | `idb_list` returned active session `80de0a67`, file `NexusTK.exe.i64`, worker PID `26892`, active/adopted/owned. |
| Health | `server_health` returned `status: ok`, imagebase `0x400000`, `auto_analysis_ready: true`, `hexrays_ready: true`, `strings_cache_ready: true`, strings cache size `2067`. |
| Input | IDB path `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`. |
| Availability note | Initial plain HTTP probes to `/mcp` printed no payload because the streamable transport was being read incorrectly. A streaming JSON-RPC client immediately returned `initialize`, `idb_list`, `server_health`, and subsequent tool results. MCP was not unavailable. |

## Source Inputs

Current project docs checked:

- [UID:0000VR] target page.
- [UID:0000KN] `by-file/LibJPEG.md`.
- [UID:0000VP] `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`.
- [UID:0000VQ] `by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md`.
- [UID:0000VS] `by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md`.
- [UID:0000VV] `by-memory/0x00404a60-0x0040505b.LibJpegInputController.md`.
- [UID:000175] `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md`.
- [UID:00022R] `by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md`.
- [UID:0001QE] `by-meta/client_libraries.md`.

Staged third-party source checked:

- `third_party_embeds/libjpeg/jdmarker.c`
- `third_party_embeds/libjpeg/jpegint.h`
- `third_party_embeds/libjpeg/jpeglib.h`

Relevant staged source anchors:

| Source anchor | Line evidence |
| --- | --- |
| `get_soi` | `jdmarker.c:197` |
| `get_sof` | `jdmarker.c:237` |
| `get_sos` | `jdmarker.c:301` |
| `get_dht` | `jdmarker.c:419` |
| `get_dqt` | `jdmarker.c:490` |
| `get_dri` | `jdmarker.c:548` |
| `examine_app0` | `jdmarker.c:584` |
| `examine_app14` | `jdmarker.c:660` |
| `get_interesting_appn` | `jdmarker.c:691` |
| `save_marker` | `jdmarker.c:739` |
| `skip_variable` | `jdmarker.c:845` |
| `next_marker` | `jdmarker.c:874` |
| `first_marker` | `jdmarker.c:921` |
| `read_markers` | `jdmarker.c:952` |
| `read_restart_marker` | `jdmarker.c:1113` |
| `jpeg_resync_to_restart` | `jdmarker.c:1192` |
| `reset_marker_reader` | `jdmarker.c:1242` |
| `jinit_marker_reader` | `jdmarker.c:1262` |
| `jpeg_save_markers` | `jdmarker.c:1300`, under `SAVE_MARKERS_SUPPORTED` |
| `jpeg_set_marker_processor` | `jdmarker.c:1349` |

## MCP Function Inventory

`entity_query` over `0x00401b00-0x004038d0` returned 18 modeled functions:

| Address | IDA name | Size | Proposed IJG source identity |
| --- | --- | ---: | --- |
| `0x00401b00` | `sub_401B00` | `0xf6` | `jpeg_resync_to_restart` |
| `0x00401c00` | `sub_401C00` | `0x10c` | `next_marker` |
| `0x00401d10` | `sub_401D10` | `0x6e` | `jinit_marker_reader` |
| `0x00401d80` | `sub_401D80` | `0x138` | `get_interesting_appn` |
| `0x00401ec0` | `sub_401EC0` | `0x28b` | `examine_app0` |
| `0x00402150` | `sub_402150` | `0xde` | `examine_app14` |
| `0x00402230` | `sub_402230` | `0x9e` | `skip_variable` |
| `0x004022d0` | `sub_4022D0` | `0x203` | `read_markers` |
| `0x00402620` | `sub_402620` | `0xb1` | `get_soi` |
| `0x004026e0` | `sub_4026E0` | `0x31e` | `get_sof` |
| `0x00402a00` | `sub_402A00` | `0x30f` | `get_sos` |
| `0x00402d10` | `sub_402D10` | `0x362` | `get_dht` |
| `0x00403080` | `sub_403080` | `0x285` | `get_dqt` |
| `0x00403310` | `sub_403310` | `0xed` | `get_dri` |
| `0x00403400` | `sub_403400` | `0x9b` | `first_marker` |
| `0x004034a0` | `sub_4034A0` | `0x88` | `read_restart_marker` |
| `0x00403530` | `sub_403530` | `0x2b` | `reset_marker_reader` |
| `0x00403640` | `sub_403640` | `0x287` | `save_marker` |

`lookup_funcs` also reported:

- `0x004038c7`: not a function.
- `0x004038d0`: not a function.
- `0x00403920`: `sub_403920`, size `0xc6`, the compression API successor `jpeg_CreateCompress`.

## MCP Call And Callback Evidence

`func_profile` and `callees` prove a single local marker-reader family:

- `0x00401d10` is called by `0x004011b0` (`jpeg_CreateDecompress` front end) and writes callback constants `0x403530`, `0x4022d0`, `0x4034a0`, `0x402230`, and `0x401d80`.
- Decompilation of `0x00401d10` allocates `168` bytes, stores it at `cinfo + 404`, writes the public `reset_marker_reader`, `read_markers`, and `read_restart_marker` methods, assigns default COM/APPn processors, assigns APP0 and APP14 to `get_interesting_appn`, and calls `reset_marker_reader`.
- `0x004022d0` dispatches marker constants `SOF0/SOF1/SOF2/SOF9/SOF10`, `DHT`, `SOS`, `DQT`, `DRI`, `APP0-APP15`, and `COM`. It returns `0` on suspension, `1` at SOS, and `2` at EOI, matching `read_markers`.
- `0x00401b00` uses warning/message constants `121` and `97`, compares restart marker values `0xd0-0xd7`, calls `next_marker`, and clears `unread_marker` for action 1, matching `jpeg_resync_to_restart`.
- `0x00403640` saves COM/APP marker payloads into a marker list, resumes suspended reads from marker-reader state, and calls `examine_app0` or `examine_app14` for APP0/APP14 markers.

Product handoff evidence:

- `xrefs_to 0x00401b00` reports a data xref at `0x004e7083` inside `sub_4E7030`.
- `get_bytes 0x004e7030` shows the product in-memory source initializer writes callback pointers `0x004e4e60`, `0x004e4e70`, `0x004e4eb0`, `0x00401b00`, and `0x004e4ed0` into a 0x28-byte callback record.
- [UID:00022R] already documents `0x004e7030` as `InitializeTileDecodeCallbackRecord`, called by [UID:000175] JPF/JPEG decode wrappers.
- This is a product-to-library source-manager hook. It does not move marker parsing or restart resynchronization into `ImageLoaders` or `VectorHelpers`.

## Raw / No-Function Evidence

This pass found three raw/no-function facts that the accepted implementation must preserve.

1. Predecessor raw decompression tail:

- `lookup_funcs` reports no modeled function at `0x004019e3`, `0x004019f0`, `0x00401a60`, `0x00401af2`, or `0x00401af3`.
- `disasm 0x004019f0` shows raw code at `0x004019f0-0x00401a52` and `0x00401a60-0x00401af2`, followed by alignment at `0x00401af3` and the marker-reader start at `0x00401b00`.
- The first raw body checks states `0xcf` and `0xcc`, sets output scanline state, and calls `0x004017c0`; the second checks states `0xcd`, `0xce`, and `0xd0`.
- This matches the retained `jdapistd.c` output-mode tail (`jpeg_start_output` / `jpeg_finish_output` family), not `jdmarker.c`. [UID:0000VR] starts after this raw predecessor tail and alignment.

2. In-range raw `jpeg_save_markers`:

- `lookup_funcs` reports `0x00403560`, `0x004035a0`, `0x00403630`, and `0x00403636` are not functions.
- `disasm 0x00403560` starts a no-function body that clamps `length_limit` against `mem->max_alloc_chunk - 0x14`, selects `save_marker`, `skip_variable`, or `get_interesting_appn`, stores APPn/COM process pointers and length limits, and raises error `0x44` for invalid marker codes.
- `xrefs_to 0x00403640`, `0x00402230`, and `0x00401d80` include data xrefs from the no-function body at `0x00403587`, `0x004035d4`, and `0x004035e7`.
- This is `jpeg_save_markers` from `jdmarker.c:1300`. It is currently inside [UID:0000VR]'s range, but the target does not call out that it is raw/unmodeled.

3. Trailing raw `jpeg_set_marker_processor`:

- `lookup_funcs` reports `0x004038d0`, `0x00403900`, `0x0040391e`, and `0x0040391f` are not functions.
- `disasm 0x004038d0` starts a no-function body that accepts `(cinfo, marker_code, routine)`, writes the routine to `process_COM` when marker `0xfe`, writes APPn processor table slots for marker `0xe0-0xef`, and raises error `0x44` otherwise.
- The body returns at `0x0040391e`; `0x0040391f` is alignment; `0x00403920` is `jpeg_CreateCompress`.
- This is `jpeg_set_marker_processor` from `jdmarker.c:1349`. It is not covered by the current [UID:0000VR] range ending at `0x004038c7`.

## Source Mapping Conclusion

The source-file mapping is stronger than the current page states:

- `0x00401b00-0x0040391f` is the proper half-open `jdmarker.c` documentation span for this libjpeg child if the project wants one source-file item.
- `0x004038c7` is only the exclusive end of the modeled `save_marker` function, not the end of the retained marker-reader source file.
- `0x004038c7-0x004038d0` is alignment between two `jdmarker.c` bodies.
- `0x004038d0-0x0040391f` is live retained `jpeg_set_marker_processor` code.
- `0x0040391f-0x00403920` is one-byte alignment before [UID:0000VS] starts at `0x00403920`.

The current target should not be split into many child pages. All modeled functions and both raw public bodies belong to the same IJG source file, share `my_marker_reader`, and route through [UID:0000KN] `LibJPEG`. Splitting would create artificial fragments of one statically embedded third-party file and would make the formal static-embed pointer ambiguous.

## Positive Evidence

- The staged source file `third_party_embeds/libjpeg/jdmarker.c` is present and matches the observed function family, marker constants, callback layout, public APIs, and APP/JFIF/Adobe marker handling.
- `jinit_marker_reader` writes the same public callback table named in `jpegint.h`: `reset_marker_reader`, `read_markers`, and `read_restart_marker`.
- The source's private `my_marker_reader` fields explain the binary offsets used for `process_COM`, `process_APPn[16]`, `length_limit_COM`, `length_limit_APPn[16]`, `cur_marker`, and `bytes_read`.
- The binary has the expected `M_APP0`/`M_APP14` routing and special JFIF/Adobe examination path.
- Product code only supplies a memory source manager and resync callback route; it does not implement marker parsing.
- Compression API successor `0x00403920` is a separate `jcapimin.c` cluster and is reached by the product screenshot writer, not by the decode marker reader.

## Negative / Counter Evidence

- IDA does not model `jpeg_save_markers` or `jpeg_set_marker_processor` as functions. This is a confidence cap and must stay visible in the target docs.
- `0x004038d0` has no direct xrefs. That is not dead code proof; the code is present in the static library island and matches an unconditional public IJG API in `jdmarker.c`.
- The current target range excludes `0x004038d0-0x0040391e`, so a formal static-embed pointer to the whole `jdmarker.c` file is range-unsafe until the target range is repaired.
- The predecessor gap between [UID:0000VQ] and [UID:0000VR] is not pure padding. It contains raw `jdapistd.c` code, so [UID:0000VR] must not claim ownership of that gap and must not repeat the old "padding gap" wording.
- The target is third-party library code, not NexusTK ImageLoaders or VectorHelpers code, even though the product decode wrappers call through it.

## Heuristic / Inference Reanalysis

Rejected weaker interpretations:

1. "Keep the current range and emit `jdmarker.c` anyway."
   - Rejected because by-memory formal C++ must represent the page's own range. The current range omits `jpeg_set_marker_processor`, while the staged source file includes it.

2. "Leave C++ blank permanently because IDA has raw no-function code."
   - Rejected as too conservative after the current static-embed rule. The raw bodies are source-identifiable IJG public APIs, and the staged source file is available. The right fix is range repair plus a static-embed marker, not hand-written C++ or permanent blank code.

3. "Create a tiny child page for `0x004038d0-0x0040391f`."
   - Rejected because it would split one stock source file across documentation items and still leave the source-file-level formal embed unclear.

4. "Move the resync callback to ImageLoaders."
   - Rejected because `0x004e7030` only writes a callback pointer into the product memory-source manager. The callback target itself is IJG `jpeg_resync_to_restart`.

5. "Treat the predecessor raw `0x004019f0-0x00401af2` as marker-reader code."
   - Rejected because its state checks and control flow match `jdapistd.c` output-mode public APIs before the marker-reader alignment.

## Ownership, Emitter, And Split Recommendation

Recommended target repair:

- Keep UID `0000VR`.
- Keep canonical owner `0000KN`.
- Keep emitter UID `0000KN`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep `Nested:0`.
- Rename/expand the target page to `by-memory/0x00401b00-0x0040391f.LibJpegMarkerReader.md`, or otherwise perform the validator-supported equivalent UID/path update, so the page covers all retained `jdmarker.c` code before [UID:0000VS].
- Do not create child pages for the 18 modeled functions or the two raw public bodies.

Recommended metadata after the range repair and report incorporation:

| Field | Recommended value | Rationale |
| --- | --- | --- |
| Completion | `90` | The repaired page will have current MCP function inventory, raw/no-function public API evidence, predecessor/successor boundary proof, source-file anchors, callback structure details, product handoff route, and formal static-embed disposition. |
| Confidence | `92` | Source identity is strong and live MCP supports the mapping, but confidence remains below final because the raw no-function bodies are not IDA function objects and no byte-for-byte rebuild comparison has been done. |

Recommended item summary:

`IJG libjpeg 6b jdmarker.c static-embed marker reader, including modeled marker switch/callback helpers plus raw jpeg_save_markers and jpeg_set_marker_processor public bodies.`

## Formal C++ Disposition

Current file/range disposition:

- Keep formal C++ blank if [UID:0000VR] remains at `0x00401b00-0x004038c7`.
- Reason: the current range excludes `jpeg_set_marker_processor` at `0x004038d0-0x0040391e`; pointing to full `jdmarker.c` would include source outside the page's range.

Recommended disposition after the range is repaired to `0x00401b00-0x0040391f`:

- Insert this exact formal `RECONSTRUCTION_CPP CODE` content:

```cpp
// Static embed: third_party_embeds/libjpeg/jdmarker.c
```

Do not paste a hand-written C or C++ reconstruction of `jdmarker.c` into the page. The staged third-party source is the correct payload.

## Support Doc Update Plan

If the supervisor accepts this report, update these docs at report-level detail:

| Doc | Required update |
| --- | --- |
| [UID:0000VR] target | Apply range repair to `0x00401b00-0x0040391f`; update metadata to `90/92`; replace the status/range/function-map/evidence sections with the current MCP facts; record raw `jpeg_save_markers` and `jpeg_set_marker_processor`; correct predecessor gap wording; add exact static-embed formal code only after range repair. |
| [UID:0000KN] `by-file/LibJPEG.md` | Update the focused source-match row for [UID:0000VR] to the repaired range, mention `jpeg_save_markers` and `jpeg_set_marker_processor` raw no-function bodies, and note the static-embed target `third_party_embeds/libjpeg/jdmarker.c`. |
| [UID:0000VP] `LibJpeg6bCore` | Update the child row and evidence notes from `0x00401b00-0x004038c7` to `0x00401b00-0x0040391f`; preserve the confidence cap from raw no-function public bodies and note the compression API successor at `0x00403920`. |
| [UID:0000VQ] `LibJpegDecompressApiFrontEnd` | Correct successor-boundary prose to say raw `jdapistd.c` code exists at `0x004019f0-0x00401af2`, then alignment before [UID:0000VR] starts at `0x00401b00`. Do not assign that raw predecessor tail to [UID:0000VR]. |
| [UID:0000VS] `LibJpegCompressApiFrontEnd` | Add predecessor-boundary note: `0x004038d0-0x0040391e` is raw `jdmarker.c` `jpeg_set_marker_processor`, `0x0040391f` is alignment, and `0x00403920` remains `jpeg_CreateCompress`. |
| [UID:0000VV] `LibJpegInputController` | Strengthen marker-consumption cross-reference to the repaired [UID:0000VR] range and its `read_markers` callback. |
| [UID:000175] `ImageDecodeWrappers` | Preserve the product/library split and add the live MCP callback-route fact: both JPF/raw JPEG wrappers call `0x004e7030`, which writes `0x00401b00` as the IJG source-manager `resync_to_restart` callback. |
| [UID:00022R] `ImageLibVectorSupportHelpers` | Expand the `0x004e7030` row/evidence to identify `0x00401b00` specifically as IJG `jpeg_resync_to_restart`, while keeping `0x004e7030` itself product/shared helper code. |
| [UID:0001QE] `client_libraries.md` | Update the IJG libjpeg bullet/source anchor list to use the repaired marker-reader span and mention the static-embed `jdmarker.c` disposition plus raw public marker API bodies. |
| `by-project-structure/proposed-source-tree.md` | If the target file is renamed, update the [UID:0000VR] link/range so project structure does not point at the stale path. This is a support-doc link update only; do not edit generated or `project-level` files. |

Do not manually edit `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `tools/validator.ini`, validator cache/state, or any manual `-coverage-report.md`.

## Validator And Generated-State Notes For Callback

Implementation should lease only the files being edited immediately. After edits, run scoped validators for every changed by-* doc. If the target is renamed, use the validator-supported path/UID update flow rather than hand-editing validator state; if no supported flow is available, pause for supervisor direction rather than editing `tools/validator.ini`.

Expected scoped validator commands after accepted edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000VR-LibJpegMarkerReader-source-quality-removed.md](0000VR-LibJpegMarkerReader-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If `by-project-structure/proposed-source-tree.md` is changed, run the matching scoped file validator for that doc as well. If generated output currency matters after inserting the static-embed comment, compare generated headers against the returned validator command IDs/timestamps or use `--wait-generated` as directed by the supervisor.

## Implementation Tracking Checklist

- [x] Lease only the immediate edit set for the accepted implementation callback, then release leases immediately after the edit/validator batch.
  - Proof: edit leases were taken before the rename/support edits. After a later B001 conflict window cleared, B010 took a fresh validator-only lease set at `2026-06-27T00:43Z`, ran the final scoped validator batch, and released all B010 leases immediately afterward. `current_leases.md` after release had no B010 rows.
- [x] Perform the accepted range repair for [UID:0000VR], preferably renaming `by-memory/0x00401b00-0x004038c7.LibJpegMarkerReader.md` to `by-memory/0x00401b00-0x0040391f.LibJpegMarkerReader.md` through a validator-supported path/UID flow rather than hand-editing validator state.
  - Proof: filesystem rename completed; final target path exists and old target path does not. Validator command `000000003444` scanned `by-memory/0x00401b00-0x0040391f.LibJpegMarkerReader.md` with exit `0`, `ok:1`, timestamp `2026-06-26T20:45:06-04:00`.
- [x] Update [UID:0000VR] metadata to `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000KN`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KN`, `Nested:0`, and the recommended item summary.
  - Proof: [UID:0000VR] header now has `90/92`, owner/emitter `0000KN`, `RECONSTRUCTABLE:TRUE`, `Nested:0`, and the accepted `IJG libjpeg 6b jdmarker.c static-embed marker reader...` summary; validator command `000000003444` passed.
- [x] Replace the target range/status/function-map/evidence text with current MCP facts for the 18 modeled functions, raw `jpeg_save_markers` at `0x00403560-0x00403633`, raw `jpeg_set_marker_processor` at `0x004038d0-0x0040391e`, predecessor raw `jdapistd.c` tail, and compression API successor `0x00403920`.
  - Proof: [UID:0000VR] now has separate Function Mapping, Raw Public Bodies, Boundary And Source Evidence, Callback And Product Handoff Evidence, Ownership Decision, and Rejected Alternatives sections carrying those facts; validator command `000000003444` passed.
- [x] Insert the exact formal static-embed code comment `// Static embed: third_party_embeds/libjpeg/jdmarker.c` only after [UID:0000VR] covers `0x00401b00-0x0040391f`; otherwise leave formal C++ blank with the range-safety proof.
  - Proof: [UID:0000VR] formal block contains exactly `// Static embed: third_party_embeds/libjpeg/jdmarker.c`; target validator command `000000003444` used `--wait-generated`, returned exit `0`, `ok:1`, `generated_refresh:completed`, `generated_refresh_command_id:000000003444`, and `autogen_cpp_update:4`.
- [x] Update [UID:0000KN] `by-file/LibJPEG.md` with the repaired `jdmarker.c` range, raw public body evidence, and static-embed route.
  - Proof: `by-file/LibJPEG.md` focused source-file anchor and Changes section now record `0x00401b00-0x0040391f`, raw `jpeg_save_markers`, raw `jpeg_set_marker_processor`, and `third_party_embeds/libjpeg/jdmarker.c`; validator command `000000003446`, timestamp `2026-06-26T20:45:29-04:00`, exit `0`, `ok:1`.
- [x] Update [UID:0000VP] `LibJpeg6bCore` with the repaired child range and boundary/raw-body evidence.
  - Proof: `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md` child row, evidence notes, and Changes section now use the repaired [UID:0000VR] range, raw/no-function confidence cap, and `0x00403920` successor; validator command `000000003448`, timestamp `2026-06-26T20:45:31-04:00`, exit `0`, `ok:1`.
- [x] Update [UID:0000VQ] `LibJpegDecompressApiFrontEnd` to correct the predecessor raw `jdapistd.c` tail before [UID:0000VR].
  - Proof: `by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md` links the repaired [UID:0000VR] path and keeps the raw `0x004019f0-0x00401af2` `jdapistd.c` tail outside [UID:0000VR]; validator command `000000003450`, timestamp `2026-06-26T20:45:33-04:00`, exit `0`, `ok:1`.
- [x] Update [UID:0000VS] `LibJpegCompressApiFrontEnd` to record raw `jpeg_set_marker_processor` before `jpeg_CreateCompress`.
  - Proof: `by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md` now records `0x004038d0-0x0040391e` as raw `jdmarker.c` `jpeg_set_marker_processor`, `0x0040391f` as alignment, and `0x00403920` as `jpeg_CreateCompress`; validator command `000000003452`, timestamp `2026-06-26T20:45:35-04:00`, exit `0`, `ok:1`.
- [x] Update [UID:0000VV] `LibJpegInputController` with the repaired marker-reader callback reference.
  - Proof: `by-memory/0x00404a60-0x0040505b.LibJpegInputController.md` now links `consume_markers` to repaired [UID:0000VR] `read_markers` and records the `jdinput.c` / `jdmarker.c` split; validator command `000000003454`, timestamp `2026-06-26T20:45:36-04:00`, exit `0`, `ok:1`.
- [x] Update [UID:000175] `ImageDecodeWrappers` with the product memory-source route to IJG `jpeg_resync_to_restart`.
  - Proof: `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md` now records both JPF/raw JPEG wrappers calling `0x004e7030`, which writes `0x00401b00` as IJG [UID:0000VR] `jpeg_resync_to_restart`; validator command `000000003455`, timestamp `2026-06-26T20:45:38-04:00`, exit `0`, `ok:1`.
- [x] Update [UID:00022R] `ImageLibVectorSupportHelpers` to name the `0x00401b00` callback pointer as IJG `jpeg_resync_to_restart`.
  - Proof: `by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md` row/evidence now identifies `0x00401b00` as [UID:0000VR] `jpeg_resync_to_restart` and keeps `0x004e7030` as product/shared callback-record initialization; validator command `000000003456`, timestamp `2026-06-26T20:45:49-04:00`, exit `0`, `ok:1`.
- [x] Update [UID:0001QE] `client_libraries.md` with the repaired `jdmarker.c` source anchor and static-embed disposition.
  - Proof: `by-meta/client_libraries.md` dependency row and IJG libjpeg section now record repaired [UID:0000VR], raw public marker APIs, and `third_party_embeds/libjpeg/jdmarker.c`; validator command `000000003457`, timestamp `2026-06-26T20:46:01-04:00`, exit `0`, `ok:1`. Pre-existing unrelated validator counts remained `missing_ref_target:4`, `missing_ref_uid:9`.
- [x] If the target is renamed, update any non-generated support link that points to the stale `0x00401b00-0x004038c7` filename, including `by-project-structure/proposed-source-tree.md` if supervisor permits that support-doc edit.
  - Proof: stale non-generated support links were updated in the listed support docs, `by-project-structure/proposed-source-tree.md`, and link-only [UID:0001Z5] `by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md`. Project-structure validator command `000000003458` passed with exit `0`, `ok:1`; MasterCodeTextSection validator command `000000003459` passed with exit `0`, `ok:1`.
- [x] Run scoped validators for each changed by-* file and record command, exit code, `command_id`, `command_timestamp`, and ok/error counts.
  - Proof: final compact validator batch:
    - `python .\tools\validator.py --mode file --file by-memory/0x00401b00-0x0040391f.LibJpegMarkerReader.md --apply --queue-timeout 240 --wait-generated` -> `000000003444`, `2026-06-26T20:45:06-04:00`, exit `0`, `ok:1`, `generated_refresh:completed`.
    - `python .\tools\validator.py --mode file --file by-file/LibJPEG.md --apply --queue-timeout 240` -> `000000003446`, `2026-06-26T20:45:29-04:00`, exit `0`, `ok:1`.
    - `python .\tools\validator.py --mode file --file by-memory/0x00401000-0x00414283.LibJpeg6bCore.md --apply --queue-timeout 240` -> `000000003448`, `2026-06-26T20:45:31-04:00`, exit `0`, `ok:1`.
    - `python .\tools\validator.py --mode file --file by-memory/0x004011b0-0x004019e3.LibJpegDecompressApiFrontEnd.md --apply --queue-timeout 240` -> `000000003450`, `2026-06-26T20:45:33-04:00`, exit `0`, `ok:1`.
    - `python .\tools\validator.py --mode file --file by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md --apply --queue-timeout 240` -> `000000003452`, `2026-06-26T20:45:35-04:00`, exit `0`, `ok:1`.
    - `python .\tools\validator.py --mode file --file by-memory/0x00404a60-0x0040505b.LibJpegInputController.md --apply --queue-timeout 240` -> `000000003454`, `2026-06-26T20:45:36-04:00`, exit `0`, `ok:1`.
    - `python .\tools\validator.py --mode file --file by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md --apply --queue-timeout 240` -> `000000003455`, `2026-06-26T20:45:38-04:00`, exit `0`, `ok:1`.
    - `python .\tools\validator.py --mode file --file by-memory/0x004e6ae0-0x004e70e9.ImageLibVectorSupportHelpers.md --apply --queue-timeout 240` -> `000000003456`, `2026-06-26T20:45:49-04:00`, exit `0`, `ok:1`.
    - `python .\tools\validator.py --mode file --file by-meta/client_libraries.md --apply --queue-timeout 240` -> `000000003457`, `2026-06-26T20:46:01-04:00`, exit `0`, `ok:1`, pre-existing `missing_ref_target:4`, `missing_ref_uid:9`.
    - `python .\tools\validator.py --mode file --file by-project-structure/proposed-source-tree.md --apply --queue-timeout 240` -> `000000003458`, `2026-06-26T20:46:12-04:00`, exit `0`, `ok:1`, pre-existing `missing_ref_target:10`, `missing_ref_uid:7`.
    - `python .\tools\validator.py --mode file --file by-memory/0x00401000-0x0060d000.MasterCodeTextSection.md --apply --queue-timeout 240` -> `000000003459`, `2026-06-26T20:46:24-04:00`, exit `0`, `ok:1`, pre-existing `missing_ref_target:1`.
- [x] Do not edit generated reports, manual `-coverage-report.md` files, validator/tool state, project-level files, or the IDA DB.
  - Proof: no manual edits were made to generated reports, manual coverage reports, validator/tool state, project-level generated files, or IDA DB files. Validator-managed refresh/path updates occurred only through scoped validator commands.
- [x] Confirm no leases remain held by Agent-B010 after validators.
  - Proof: `python .\tools\leaser\leaser.py B010 unlease` released all B010 paths after the validator batch. The subsequent `current_leases.md` read listed no B010 rows.
- [x] Update this checklist with implementation proof during the callback phase before returning `FINISHED_IMPLEMENTATION`.
  - Proof: this checklist was updated after validators and lease cleanup.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0000VR-LibJpegMarkerReader-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0000VR-LibJpegMarkerReader-source-quality.md","timestamp":"2026-06-26T20:51:13","uid":"0000VR"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000VR-LibJpegMarkerReader-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/0000VR-LibJpegMarkerReader-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000VR"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
