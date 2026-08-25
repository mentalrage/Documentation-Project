** TARGET-REPORT-UID:0000VT **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000VT] LibJpegCompressRawDataApi Source-Quality Report

Agent: Agent-B009
Assignment: `B009-report-0000VT-libjpeg-compress-raw-data-api-source-quality-20260626`
Target: [UID:0000VT] `by-memory/0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md`
Mode: report-only research; no by-* edits, generated/project-level edits, coverage-report edits, validator/tool-state edits, IDA DB edits, or leases.

## Executive Summary

[UID:0000VT] is correctly owned by [UID:0000KN] `LibJPEG` and remains a reconstructable static third-party source range. Current IDA MCP and staged-source evidence identify the exact function as IJG libjpeg 6b `jpeg_write_raw_data` from `jcapistd.c`, with no direct product caller. The current target page is implementation-ready except for stale source-quality wording: it still leaves the formal C++ block blank because earlier text treated third-party static-library code as non-emitting until 95/95. Current project policy for static embedded third-party source says source-bearing pages should emit a static-embed marker instead of pasted upstream source.

Recommendation: keep `CANONICAL_OWNER:0000KN`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KN`, and blank emitter position; raise the target to `COMPLETION:90`, `CONFIDENCE:92`; insert the exact formal block content `// Static embed: third_party_embeds/libjpeg/jcapistd.c`; and refresh target/support prose to preserve the current MCP boundary/body/caller evidence and the rejected product-wrapper alternatives.

## Target Inventory

Current target header at report time:

- `COMPLETION:86`
- `CONFIDENCE:90`
- `CANONICAL_OWNER:0000KN`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KN`
- blank `EMITTER_POSITION_OPTIONAL`
- blank `RECONSTRUCTION_CPP`
- Item Summary: ``jpeg-6b/jcapistd.c` source-file ownership.`

Current target text already documents the broad decision correctly: IJG libjpeg 6b code, not NexusTK screenshot writer source, with stock `jpeg_write_raw_data` behavior. The source-quality gap is that it says final C++ remains blank and references the old below-95/95 emission reason.

## IDA MCP Evidence

MCP was available and used. Evidence session:

- `b009-0000vt-idb-list-20260626T0003`: active session `80de0a67`, `NexusTK.exe.i64`, backend worker PID `26892`, `is_analyzing:false`.
- `b009-0000vt-health-20260626T0010`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready with 2067 strings.
- `b009-0000vt-lookup-20260626T0012`: `0x004048f0` is `sub_4048F0`, size `0xcb`; `0x004049bb` is not a function; successor `0x004049c0` is `sub_4049C0`, size `0x38`; predecessor scanline API function at `0x00404820` is `sub_404820`, size `0xc4`; symbol names `jpeg_write_raw_data`, `jpeg_write_scanlines`, and `jpeg_finish_compress` are not present in IDA.
- `b009-0000vt-int-convert-20260626T0019`: `0xcb` converts to decimal `203`; `0x66` converts to decimal `102`; structure offsets used by the decompiler include `0xd0` decimal `208`, `0xdc` decimal `220`, `0x13c` decimal `316`, and `0x148` decimal `328`.
- `b009-0000vt-analyze-20260626T0013` and `b009-0000vt-decompile-20260626T0014`: decompiler prototype is `unsigned int __cdecl(_DWORD *, int, unsigned int)` and the body checks state `102`, handles too-much-data by warning and returning zero, updates the progress monitor, calls pass startup when the master flag is set, computes one iMCU-row line count as `8 * a1[55]`, checks the caller's row count, invokes the raw-data compressor callback through the coefficient controller, increments `next_scanline`, and returns either zero or the iMCU-row line count.
- `b009-0000vt-disasm-20260626T0015`: 77 instructions, final return at `0x4049ba`; body uses only indirect calls through IJG callback tables, consistent with stock libjpeg API dispatch.
- `b009-0000vt-xrefs-20260626T0016`: no code xrefs to `0x004048f0`; by contrast, the adjacent scanline API at `0x00404820` has a direct product-side caller at `0x4efd8e` inside `sub_4EFBC0`, and the common API successor has libjpeg-internal xrefs. This supports "retained raw API, not product screenshot route".
- `b009-0000vt-callees-20260626T0017`: no direct callees because all calls in the target are indirect through IJG tables.
- `b009-0000vt-bytes-boundaries-20260626T0018`: NOP padding precedes `0x004048f0`; the target ends after the return at `0x4049ba`, with NOP padding through `0x4049bf`, then successor code starts at `0x004049c0`.

## Local Source and Documentation Evidence

Staged source evidence:

- `source-3/third_party_embeds/libjpeg/jcapistd.c` contains `jpeg_write_raw_data` at lines 119-161.
- `source-3/project-documentation/by-meta/obtained_thirdparty_files/static_embeds/libjpeg-6b/jcapistd.c` contains the same function at the same lines.
- Both staged copies hash to SHA256 `371517D8285CA47D286BE53A6C1BF8F1A0372E12E6E7F7C84B324D7F441B6581`.
- The source function's behavior matches MCP: raw-compress state check, end-of-image warning path, progress monitor update, pass-startup callback, iMCU-row line calculation, buffer-size guard, coefficient-controller `compress_data`, and `next_scanline` advance.

Support-doc evidence:

- [UID:0000KN] `by-file/LibJPEG.md` already classifies IJG libjpeg as statically embedded source under `third_party/libjpeg/`, maps [UID:0000VT] to `jcapistd.c`, and keeps product wrappers in image modules.
- [UID:0000VP] `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md` already lists [UID:0000VT] as the `0x004048f0-0x004049bb` `jpeg_write_raw_data` child.
- [UID:0000VS] `by-memory/0x00403920-0x004048e2.LibJpegCompressApiFrontEnd.md` maps the product screenshot writer path to `jpeg_write_scanlines`; current MCP confirms that is the directly called compression API, not [UID:0000VT].
- [UID:0000VU] `by-memory/0x004049c0-0x00404a5c.LibJpegCommonApi.md` is the successor common-API child.
- [UID:0001QE] `by-meta/client_libraries.md` records IJG libjpeg 6b strings/version, the static third-party route, and [UID:0000VT] as stock `jpeg_write_raw_data`.
- [UID:0001QY] `by-meta/obtained_thirdparty_files/static_embeds/README.md` already records `libjpeg-6b/` as sourced from `jpegsrc.v6b.tar.gz` and included in the static embed set.

Generated-state observation, read-only:

- `auto-generated/-ag-coverage-report-by-memory.md` still shows [UID:0000VT] as `emits_code:false` and stale `80%`.
- `auto-generated/-ag-research-tracker.md` still shows [UID:0000VT] as `80/85`.
- `auto-generated/NexusTK/third_party/libjpeg/LibJPEG.cpp` line 112 still has an empty emitter marker for [UID:0000VT].
- These generated files should not be manually edited. They should refresh through the normal validator/report execution lifecycle after accepted implementation.

## Source-Quality Assessment

The target is a source-bearing static third-party child, not an aggregate and not a product wrapper. The range is an exact single IDA-modeled function with stable padding boundaries and a direct staged-source match. Current blockers are resolved as follows:

- Source route: `third_party_embeds/libjpeg/jcapistd.c`, not a handwritten NexusTK source file.
- Formal C++ route: static-embed marker only; do not paste upstream `jcapistd.c` function text into the by-memory page.
- Product-caller route: no direct xrefs to `0x004048f0`; product screenshot writing uses the adjacent scanline API path through [UID:0000VS] and [UID:00018N].
- Split route: no child split is needed. `0x004048f0-0x004049bb` is the complete modeled function body; padding separates it from both neighbors.
- Name route: source-facing function is `jpeg_write_raw_data`; IDA's `sub_4048F0` is only the local unsymbolized function name.

## Ownership Decision

Keep:

- `CANONICAL_OWNER:0000KN`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:0000KN`
- blank `EMITTER_POSITION_OPTIONAL`

Rationale: the range is stock IJG libjpeg 6b code and belongs under [UID:0000KN] `LibJPEG`. It must not be reassigned to [UID:00018N] `JpegScreenshotWriter`, [UID:0000K4] `ImageWriters`, or any NexusTK product module just because the adjacent scanline API is used by screenshot output.

## Split and Range Decision

Keep target range `0x004048f0-0x004049bb`.

Current MCP supports the exact split:

- The predecessor scanline API function starts at `0x00404820`; NOP padding precedes `0x004048f0`.
- The target starts at `0x004048f0`, has IDA size `0xcb` / 203 bytes, and returns at `0x4049ba`.
- The endpoint `0x004049bb` is not a function head; bytes after the return are padding through `0x004049bf`.
- The successor common API starts at `0x004049c0`.

No new child page is warranted, and no merge into [UID:0000VS], [UID:0000VU], or broad [UID:0000VP] would improve source fidelity.

## Formal C++ Recommendation

Insert this exact content inside the target's formal `RECONSTRUCTION_CPP CODE` block:

```cpp
// Static embed: third_party_embeds/libjpeg/jcapistd.c
```

Do not paste the upstream function body into the by-memory page. The staged source file is the authoritative source body for rebuilds.

## Score Recommendation

Recommended target metadata:

- `COMPLETION:90`
- `CONFIDENCE:92`

Rationale:

- Completion improves because the target has current MCP proof, exact staged-source route, resolved formal-block policy, caller separation, and no unresolved split/source-placement blocker.
- Confidence improves because IDA behavior, boundaries, staged-source hash, and support-doc provenance agree. It remains below final because the whole libjpeg rebuild still depends on compatible IJG 6b build configuration, headers, and toolchain options, and IDA has no original symbol names.

Recommended item summary:

`Static IJG libjpeg 6b jpeg_write_raw_data from staged third_party_embeds/libjpeg/jcapistd.c.`

## Rejected Alternatives

- Reject blank formal C++ as the final state. The project now has a static-embed route for source-bearing third-party ranges, and [UID:0000VT] has exact source-file provenance.
- Reject pasting the full IJG `jpeg_write_raw_data` body into the formal block. That would duplicate staged third-party source and contradict the static-embed policy.
- Reject reassignment to product screenshot code. MCP found no direct xrefs to `0x004048f0`; the product route calls the adjacent scanline API, not the raw-data API.
- Reject merging into [UID:0000VS] or [UID:0000VU]. The target is a complete standalone public IJG API function with padding-separated neighbors.
- Reject treating the missing IDA symbol name as a source-name blocker. The staged IJG source and decompiler behavior provide stronger source-facing evidence than IDA's unsymbolized `sub_4048F0`.

## Recommended Target Changes

In [UID:0000VT] `by-memory/0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md`:

- Change `COMPLETION:86` to `COMPLETION:90`.
- Change `CONFIDENCE:90` to `CONFIDENCE:92`.
- Keep owner/reconstructable/emitter metadata unchanged.
- Insert the static-embed marker in the formal C++ block.
- Update the item summary to the recommended concise summary above.
- Refresh Status, Range Role, Function Mapping, Live IDA Refresh, Score Rationale, and Changes with the current 2026-06-26 MCP call IDs, static-source hash, no-direct-caller evidence, padding/successor boundary, and static-embed marker rationale.
- Replace stale "final C++ remains blank" and "below 95/95" wording with the static-embed source route.

## Recommended Support Changes

Support docs should preserve report-level detail without broad refactors:

- [UID:0000KN] `by-file/LibJPEG.md`: add a compact 2026-06-26 note that [UID:0000VT] is confirmed as `jpeg_write_raw_data` from staged `third_party_embeds/libjpeg/jcapistd.c`, with no direct product caller and a static-embed formal route.
- [UID:0000VP] `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`: update the [UID:0000VT] child row or evidence notes with the current MCP boundary/body/caller proof and static-embed marker status.
- [UID:0001QE] `by-meta/client_libraries.md`: update the IJG libjpeg evidence/source-structure bullets to mention [UID:0000VT]'s static-embed route and retained-but-unreferenced raw-data API status.
- [UID:0001QY] `by-meta/obtained_thirdparty_files/static_embeds/README.md`: no required edit unless the implementer wants to add the specific `jcapistd.c` hash; the existing libjpeg-6b static-embed manifest already supports this report.
- Generated `auto-generated/-ag-*` and generated C++ files: no manual edits. Expect normal validator/report execution to refresh stale [UID:0000VT] generated rows after implementation.

## Validator Plan for Implementation Callback

After accepted implementation edits, run scoped file validators from `source-3/project-documentation` for each changed by-* or by-meta file, for example:

- `python .\tools\validator.py --mode file --file by-memory\0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-file\LibJPEG.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-memory\0x00401000-0x00414283.LibJpeg6bCore.md --apply --queue-timeout 240`
- `python .\tools\validator.py --mode file --file by-meta\client_libraries.md --apply --queue-timeout 240`
- If [UID:0001QY] is edited, also validate `by-meta\obtained_thirdparty_files\static_embeds\README.md`.

Implementation closeout should report command IDs, timestamps, exits, `ok` counts, leases used/released, generated refresh state, and any unchecked blockers.

## Open Questions

None blocking implementation. The only remaining non-blocking risk is whole-library rebuild fidelity for IJG 6b compile configuration, which belongs to [UID:0000KN]/[UID:0000VP] and does not prevent [UID:0000VT] from using the staged source marker.

## Implementation Tracking Checklist

- [x] Lease each required target/support file only immediately before editing it; if a required file is actively leased by another agent, wait/recheck or return `PAUSED_LEASE_CONFLICT`.
  - Proof: initial lease attempt succeeded for [UID:0000VT] and this report but hit active support-doc leases, so B009 released those two leases immediately. Brief retry then leased [UID:0000KN] `by-file/LibJPEG.md`, [UID:0000VP] `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md`, [UID:0001QE] `by-meta/client_libraries.md`, then leased [UID:0000VT] and this report before editing. No B001/other-agent lease was edited through.
- [x] Update [UID:0000VT] metadata to `COMPLETION:90`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000KN`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000KN`, blank emitter position.
  - Proof: `by-memory/0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md` header now has `COMPLETION:90`, `CONFIDENCE:92`, unchanged owner/reconstructable/emitter values, and blank emitter position.
- [x] Insert exactly `// Static embed: third_party_embeds/libjpeg/jcapistd.c` inside [UID:0000VT]'s formal `RECONSTRUCTION_CPP CODE` block.
  - Proof: target formal block contains that one marker line between `RECONSTRUCTION_CPP CODE:BEGIN/END`; the prose section avoids an extra fenced C++ copy.
- [x] Update [UID:0000VT] prose with current MCP evidence IDs `b009-0000vt-idb-list-20260626T0003`, `b009-0000vt-health-20260626T0010`, `b009-0000vt-lookup-20260626T0012`, `b009-0000vt-analyze-20260626T0013`, `b009-0000vt-decompile-20260626T0014`, `b009-0000vt-disasm-20260626T0015`, `b009-0000vt-xrefs-20260626T0016`, `b009-0000vt-callees-20260626T0017`, `b009-0000vt-bytes-boundaries-20260626T0018`, and `b009-0000vt-int-convert-20260626T0019`.
  - Proof: target `Live IDA Refresh` section records the accepted MCP session, health, lookup, decompile/analyze/disasm, xref, callee, boundary-byte, and int-convert evidence.
- [x] Update [UID:0000VT] source provenance with staged `jcapistd.c` line range `119-161` and SHA256 `371517D8285CA47D286BE53A6C1BF8F1A0372E12E6E7F7C84B324D7F441B6581`.
  - Proof: target `Function Mapping` and `Staged Source Provenance` sections include `jcapistd.c:119-161` and the staged-source SHA256.
- [x] Update [UID:0000VT] rejected alternatives: no blank final C++, no pasted upstream body, no product screenshot ownership, no merge/split with neighboring libjpeg pages.
  - Proof: target `Rejected Alternatives` section records all four rejected routes plus the rejected unsymbolized-IDA-name blocker.
- [x] Update [UID:0000KN] `by-file/LibJPEG.md` with a compact [UID:0000VT] 2026-06-26 static-embed/current-MCP note.
  - Proof: `by-file/LibJPEG.md` `Range Notes`, source-file coverage map row, and `Changes` now record B009's current MCP no-caller/boundary proof and static-embed route for [UID:0000VT].
- [x] Update [UID:0000VP] `by-memory/0x00401000-0x00414283.LibJpeg6bCore.md` with [UID:0000VT]'s refreshed boundary/body/caller proof and static-embed marker status.
  - Proof: [UID:0000VP] MCP table, source-file child map row, boundary/padding notes, and `Changes` now include the B009 [UID:0000VT] refresh.
- [x] Update [UID:0001QE] `by-meta/client_libraries.md` with [UID:0000VT]'s static-embed route and retained-but-unreferenced raw-data API status.
  - Proof: `by-meta/client_libraries.md` IJG dependency table, [UID:0000VT] evidence bullet, and B009 libjpeg status paragraph now mention the retained raw-data API, no-direct-product-caller proof, and `jcapistd.c` static-embed route.
- [x] Confirm [UID:0001QY] `by-meta/obtained_thirdparty_files/static_embeds/README.md` needed no edit.
  - Proof: current read shows the README already records `libjpeg-6b/` from `jpegsrc.v6b.tar.gz`, included static source role, `jmemnobs.c`, and the hash-for-hash static embed state; accepted callback said no edit was required unless provenance was weaker.
- [x] Do not manually edit generated files, project-level generated reports, validator/tool state, IDA DB, `by-memory/-coverage-report.md`, or any other `-coverage-report.md`.
  - Proof: manual edits were limited to the target/support docs and this report checklist. Validator side effects are recorded separately below.
- [x] Run scoped validators for every changed by-* or by-meta file with `python .\tools\validator.py --mode file --file <relative-path> --apply --queue-timeout 240` and record command IDs/timestamps/exits/ok counts.
  - Proof: `by-memory\0x004048f0-0x004049bb.LibJpegCompressRawDataApi.md` command `000000003471`, timestamp `2026-06-26T20:52:17-04:00`, exit `0`, `ok:1`; `by-file\LibJPEG.md` command `000000003472`, timestamp `2026-06-26T20:52:24-04:00`, exit `0`, `ok:1`; `by-memory\0x00401000-0x00414283.LibJpeg6bCore.md` command `000000003473`, timestamp `2026-06-26T20:52:35-04:00`, exit `0`, `ok:1`; `by-meta\client_libraries.md` command `000000003474`, timestamp `2026-06-26T20:52:47-04:00`, exit `0`, `ok:1`.
- [x] Confirm leases are released after the edit/validator batch.
  - Proof: post-validator unlease command for [UID:0000VT], [UID:0000KN], [UID:0000VP], [UID:0001QE], and this report returned `Rejected[No active lease]` for each path, confirming no B009 edit-batch lease remained active. B009 then briefly leased this report only to record this proof line.
- [x] Report generated refresh state as validator-owned/stale/refreshed; do not hand-edit generated rows.
  - Proof: all four validators returned `generated_refresh: deferred` with command IDs `000000003471`-`000000003474`. Validator-driven side effects included projected stats updates and, for [UID:0000VT], autogen registry/reference updates; no generated rows were hand-edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0000VT-LibJpegCompressRawDataApi-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0000VT-LibJpegCompressRawDataApi-source-quality.md","timestamp":"2026-06-26T20:56:22","uid":"0000VT"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
