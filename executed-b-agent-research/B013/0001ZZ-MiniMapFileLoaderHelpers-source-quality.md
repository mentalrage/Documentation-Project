** TARGET-REPORT-UID:0001ZZ **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# UID0001ZZ MiniMapFileLoaderHelpers Source-Quality Research


## Finalized Report / Current Recommendation

Keep `[UID:0001ZZ] by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md` as a MiniMap-owned helper-island marker for this pass. The page should not emit a monolithic aggregate body. The existing page is still the right place to hold the source-family index and exact child split plan, while exact modeled child bodies should wait for accepted `MiniMapFileLoader` field names and `.mnm` record/header names.

This report does recommend targeted source-quality corrections for the later Gate 1 callback:

- Correct the loader field interpretation: the `this + 0x00` small-wide-string is a decode key initialized from the default string at `0x0061093c`, not the caller file path. The caller path is passed as the `sub_457850` argument from `MiniMapRenderer +0x02` and is not stored into `this + 0x00` by the loader functions checked here.
- Keep `this + 0x18` as the expected `.mnm` version/header string initialized from `0x00610968` (`MNM_Ver0.0`).
- Clarify that the decoded payload is later consumed by `BuildSymbolViews`; the image route is `[UID:0002TN] DecodeJpegBufferToTileContext` at `0x004d0a90`, called from `0x004544a8`, not `[UID:0002TM] Decode8BitBmpToTileContext`.
- Preserve the raw helper ranges `0x00457760-0x00457780` and `0x00457780-0x00457842` as no-route raw bodies unless a later split callback explicitly authorizes raw no-code child pages.
- Recommend target score update from `86/89` to `88/91` after implementation, with `CANONICAL_OWNER:0000LE`, `EMITTER_UIDS:0000LE`, and `RECONSTRUCTABLE:TRUE` unchanged.

No target/support by-* files, generated files, tracker files, supervisor ledgers, lifecycle/archive files, or report execution files were edited in this report-only pass.

## Supporting Research

This repaired report preserves the existing MCP-backed research and normalizes the required Gate 1 sections so the artifact can be audited from its own text. The report remains report-only: no by-* docs, generated files, coverage reports, validator state, supervisor ledgers, lifecycle/archive files, or report execution files were edited.

The supporting research is organized under the exact top-level headings required for supervisor Gate 1. Historical old-report material is treated as lead evidence only; current live MCP and current by-* docs remain the controlling evidence.

## Target

- Target UID: `0001ZZ`
- Target path: `by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md`
- Assigned report path: `tools/leaser/Agents/Agent-B013/research/0001ZZ-MiniMapFileLoaderHelpers-source-quality.md`
- Current canonical owner: `[UID:0000LE] by-file/MiniMap.md`
- Current generated source route: `auto-generated/NexusTK/map/MiniMap.cpp`
- Current tracker state at assignment: `COMPLETION:86`, `CONFIDENCE:89`, combined `87.5`, `RECONSTRUCTABLE:true`, reports `0`

## Current Target State

The current target is already a marker-only source-family page for MiniMap file-loader helpers. It documents these ranges:

| Range | Current role | Live MCP result |
| --- | --- | --- |
| `0x00457620-0x004576a6` | Loader constructor | IDA function `sub_457620`, size `0x86` |
| `0x004576a6-0x004576b0` | Padding | Ten `0xcc` bytes |
| `0x004576b0-0x00457757` | Loader destructor | IDA function `sub_4576B0`, size `0xa7` |
| `0x00457757-0x00457760` | Padding | Nine `0xcc` bytes |
| `0x00457760-0x00457780` | Raw string-reset helper | Not an IDA function |
| `0x00457780-0x00457842` | Raw transform/write helper | Not an IDA function |
| `0x00457842-0x00457850` | Padding | Fourteen `0xcc` bytes |
| `0x00457850-0x00457953` | Loader load method | IDA function `sub_457850`, size `0x103` |
| `0x00457953-0x00457960` | Padding | Thirteen `0xcc` bytes |
| `0x00457960-0x00457a5d` | Payload decode method | IDA function `sub_457960`, size `0xfd` |
| `0x00457a5d-0x00457a60` | Padding before successor | Three `0xcc` bytes |

The current marker-only reconstruction block is structurally correct, but the prose should be updated to avoid implying that `this + 0x00` is the MiniMap file path. The loader path is an argument to the load/write helpers; the field at `this + 0x00` is the XOR decode key.

## Heuristic / Inference Reanalysis And Validation

This target is not an empty-emitter or no-owner case. It is already owned by the MiniMap source-family root and has direct live evidence from IDA MCP for every modeled function range. The remaining quality issues are source-naming and child-placement issues:

- The aggregate page should remain the formal marker because it spans multiple methods plus two raw no-function bodies.
- The modeled constructor, destructor, load, and decode functions are recoverable, but exact C++ would currently force guessed names for loader fields and `.mnm` payload records.
- The raw bodies have no IDA function objects, no direct xrefs to their starts, and no observed absolute/RVA pointer references to their starts. They should not be promoted as normal source-emitting children without a stronger route.
- A stale MiniMap image-route claim exists in old support research: live MCP shows JPEG decode at `[UID:0002TN]`, not BMP decode at `[UID:0002TM]`.

## Evidence Standards Used

- Live IDA MCP was required and was available.
- Each behavior claim below is tied to one of: live decompile/disassembly, live xref/callee lookup, live byte/string checks, current by-* docs, or old-report search results.
- Inferential names are separated from proven field offsets.
- No fallback-only report was produced.
- No by-* implementation was performed in this report-only pass.

## Evidence Checked

Live MCP checks used the active IDB session:

- Session: `supervisor_recovery_20260705`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Active input: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- Image base: `0x400000`
- Server status: `ok`
- Auto-analysis: ready
- Hex-Rays: ready
- Strings cache: ready, size `2067`

Read-only project files checked:

- `by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md`
- `by-file/MiniMap.md`
- `by-class/MiniMapRenderer.md`
- `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md`
- `by-memory/0x00457580-0x00457613.DATIndexVectorFindNodeByKey.md`
- `by-memory/0x00457a60-0x00458610.EPFTileContext.md`
- `by-memory/0x004d05f0-0x004d0f4a.ImageDecodeWrappers.md`
- `by-memory/0x004d0a90-0x004d0c58.DecodeJpegBufferToTileContext.md`
- `by-memory/0x004d09b0-0x004d0a8a.Decode8BitBmpToTileContext.md`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/NexusTK/map/MiniMap.cpp`
- `executed-b-agent-research/B010/0000LE-MiniMap-empty-emitter-family-source-quality.md`
- `executed-b-agent-research/B007/0000XO-MiniMapRendererAndControls-source-quality.md`
- Adjacent incidental old reports that matched helper/string addresses but did not cover UID0001ZZ directly.

Old-report search terms used:

```text
TARGET-REPORT-UID:0001ZZ
UID:0001ZZ
0x00457620
0x00457a5d
MiniMapFileLoaderHelpers
MiniMapFileLoader
MiniMap empty
MiniMap source-family
TARGET-REPORT-UID:0000XO
BuildSymbolViews
Decode8BitBmp
DecodeJpegBuffer
```

Old-report results:

- No direct historical `TARGET-REPORT-UID:0001ZZ` report was found.
- `executed-b-agent-research/B010/0000LE-MiniMap-empty-emitter-family-source-quality.md` is a relevant parent/source-family report. It recommends UID0001ZZ as a marker-only helper island with the same broad child plan and excludes body promotion until field and `.mnm` names are accepted.
- `executed-b-agent-research/B007/0000XO-MiniMapRendererAndControls-source-quality.md` is a relevant support report for `BuildSymbolViews`. It correctly routes UID0001ZZ through the MiniMap family, but its MiniMap image decode claim is stale: it names `[UID:0002TM] Decode8BitBmpToTileContext`, while current MCP and current image-decode docs show `[UID:0002TN] DecodeJpegBufferToTileContext`.
- `executed-b-agent-research/B007/0000XX-DATIndexVectorFindNodeByKey-source-quality.md` only matched the adjacent boundary before `0x00457620`; it is boundary evidence, not UID0001ZZ coverage.
- `executed-b-agent-research/B005/0002DV-SimpleUStringClear-source-quality.md` and `executed-b-agent-research/B003/0002E3-SimpleUStringAssignWideCount-source-quality.md` only matched SimpleUString helper references from UID0001ZZ functions; they are not UID0001ZZ source-quality reports.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-001 | UID0001ZZ remains MiniMap-owned. | High | Current target owner/emitter `0000LE`; `BuildSymbolViews` calls constructor/load/destructor; MiniMap file root owns `auto-generated/NexusTK/map/MiniMap.cpp`. | Target metadata; `by-file/MiniMap.md` source-family disposition. | already-present | already-present: target metadata still has `CANONICAL_OWNER:0000LE` and `EMITTER_UIDS:0000LE`; `by-file/MiniMap.md` was not edited because its UID0001ZZ source-family disposition already owns the helper island. |
| C-002 | UID0001ZZ remains a marker-only aggregate, not a monolithic emitting body. | High | Target spans four modeled functions and two raw no-function bodies; exact loader fields and `.mnm` record names remain inferred. | Target `RECONSTRUCTION_CPP CODE`; target final recommendation. | incorporate | applied: target C++ block now explicitly says no monolithic aggregate body and raw ranges remain no-code/no-route without later split/liveness approval. |
| C-003 | Recommended target score is `COMPLETION:88`, `CONFIDENCE:91`; owner/emitter/reconstructable remain unchanged. | Medium-high | Live MCP resolves field/key route, JPEG route, raw helper status, padding, and xrefs, but exact source names and child pages remain blocked. | Target metadata; score/metadata section. | incorporate | applied: target metadata set to `88/91`; validator `000000007387` confirmed completion/confidence updates. |
| C-004 | `this + 0x00` is a decode key, not the caller file path. | High | Constructor initializes from `0x0061093c`; decode uses `this + 0x00` as XOR key; load receives the path as an argument and does not store it there. | Target field table/behavior; UID0000XO support prose. | incorporate | applied: target Behavior and Field And Format Evidence now reject path-field wording; UID0000XO support notes the path comes from `MiniMapRenderer+0x02`. |
| C-005 | `this + 0x18` is the expected `.mnm` version/header string. | High | Constructor initializes from `0x00610968`; load reads/compares it; raw write helper writes it before transformed payload. | Target field table; load/write behavior notes. | incorporate | applied: target Field And Format Evidence and Behavior document expected version/header semantics and raw write use. |
| C-006 | `this + 0x30/+0x34` are payload data pointer and payload length/body size. | High | Constructor clears both; destructor frees `+0x30`; load allocates/fills `+0x30` and tracks remaining body size in `+0x34`. | Target field table; load/destructor behavior. | incorporate | applied: target Behavior, Field And Format Evidence, and Evidence sections document payload pointer/length roles. |
| C-007 | Default loader strings are `0x0061093c` and `0x00610968` with direct byte-decoded contents. | Medium-high | Direct UTF-16LE byte decode: `0x0061093c` begins `MNMEncodeDecodeBy` plus `U+D6C8 U+AC74 U+AE40`; `0x00610968` is `MNM_Ver0.0`. | Target evidence/default-field notes. | incorporate | applied: target Field And Format Evidence and Evidence sections carry both default string byte interpretations. |
| C-008 | Loader read starts from observed file offset `0x42` and reads the expected-version string before the remaining body. | High | `sub_457850` performs `fseek(file, 66, SEEK_END)`, `ftell`, `fseek(file, 66, SEEK_SET)`, reads `(expectedVersion.length + 1)` wide characters, and subtracts those bytes from payload length. | Target load method behavior; `.mnm` format caveat. | incorporate | applied: target Behavior, Field And Format Evidence, and Evidence sections document the `0x42` offset and expected-version read. |
| C-009 | Payload decode XORs no more than the first 200 payload bytes using forward and reversed key bytes. | High | `sub_457960` allocates forward/reversed key buffers and loops while index is below payload length and below `200`. | Target decode method behavior; no-code/C++ rationale. | incorporate | applied: target Covered Functions, Behavior, Field And Format Evidence, and Evidence sections document decode-key XOR and 200-byte cap. |
| C-010 | `BuildSymbolViews` passes `MiniMapRenderer +0x02` as loader path and consumes decoded loader payload. | High | `0x00454450` pushes `[edi+2]`; `0x00454457` calls `sub_457850`; subsequent instructions copy decoded payload fields into renderer fields. | Target caller notes; UID0000XO `BuildSymbolViews` support section. | incorporate | applied: target Behavior/Evidence and UID0000XO support-helper text document path argument, decoded header copy, payload length, and image byte offsets. |
| C-011 | `BuildSymbolViews` image route is JPEG via `[UID:0002TN] DecodeJpegBufferToTileContext`, not BMP via `[UID:0002TM]`. | High | Live call at `0x004544a8` targets `sub_4D0A90`; current UID0002TN doc records the MiniMap caller; old B007 report names BMP and is contradicted. | Target caller notes; UID0000XO support text; UID0008F optional support note. | reject-stale | applied: target and UID0000XO explicitly route `0x004544a8` to UID0002TN and reject UID0002TM for this `.mnm` path; UID0008F was not edited because target/UID0000XO now carry the correction. |
| C-012 | Raw reset helper `0x00457760-0x00457780` is no-route and should not emit normal source C++. | High | `lookup_funcs` reports no function; `xref_query` reports no xrefs; byte-pattern scans found no absolute/RVA pointer references; disassembly only resets both strings. | Target split/no-code proof; range analysis. | incorporate | applied: target Covered Functions, split plan, Evidence, and Current-Pass Format sections include no-function/no-xref/no-pointer/no-code disposition. |
| C-013 | Raw transform/write helper `0x00457780-0x00457842` is no-route and should not emit normal source C++. | High | `lookup_funcs` reports no function; `xref_query` reports no xrefs; byte-pattern scans found no absolute/RVA pointer references; disassembly reads, transforms, writes header/body. | Target split/no-code proof; range analysis. | incorporate | applied: target Covered Functions, split plan, Evidence, and Current-Pass Format sections include no-function/no-xref/no-pointer/no-code disposition and write behavior. |
| C-014 | Existing split plan and padding boundaries are valid and should remain exact. | High | Modeled function sizes, raw ranges, and `0xcc` padding around each boundary were checked live; adjacent UID0000XX and UID0000XY boundaries are clean. | Target range/split/padding section. | incorporate | applied: target Exact Child Split Plan and Evidence sections preserve exact ranges and padding. |
| C-015 | No child pages should be created during this report-only pass. | High | Supervisor assignment forbids target/support by-* edits and this pass is Gate 1 research only. | Report checklist; later callback instructions. | not-applicable | excluded-with-reason: callback explicitly forbade split child creation; no child pages were created. |
| C-016 | UID0000XO support text must be corrected where it still links the `.mnm` image path to BMP. | High | Old B007 support report and current support prose use stale BMP route; live MCP proves JPEG route. | `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md`, `BuildSymbolViews` and support-helper sections. | incorporate | applied: UID0000XO support text and Changes section now route `.mnm` payload image to UID0002TN and reject UID0002TM for this path. |
| C-017 | UID00008F should remain semantic support and not become canonical owner. | High | Class page describes renderer storage and tile context; ownership route still passes through MiniMap file family and generated MiniMap output. | `by-class/MiniMapRenderer.md`, support/caveat section. | already-present | already-present: `by-class/MiniMapRenderer.md` already treats UID0001ZZ as semantic renderer-local support while routing ownership through MiniMap; not edited. |
| C-018 | UID0000LE needs no structural ownership change, but may carry the decode-key/JPEG correction if edited. | High | MiniMap file root already owns UID0001ZZ and records marker-only disposition; correction is factual, not structural. | `by-file/MiniMap.md`, UID0001ZZ source-disposition row if touched. | already-present | already-present: `by-file/MiniMap.md` already records UID0001ZZ as MiniMap helper-island marker; not edited because target/UID0000XO carry the accepted correction. |
| C-019 | UID0002TN already matches the live JPEG route; UID0002TM should not be linked to this MiniMap route. | High | Current image decode docs and live MCP show `0x004544a8 -> sub_4D0A90`; BMP wrapper caller evidence is for other routes. | UID0002TN/UID0002TM support docs; target rejected alternatives. | already-present | already-present: UID0002TN already documents MiniMap caller `0x004544a8`; UID0002TM documents the `LEVEL.BMP`/MainMenu route; image decode pages were not edited. |
| C-020 | Adjacent UID0000XX and UID0000XY require no ownership/range changes for this target. | High | Padding before `0x00457620` and after `0x00457a5d` is clean; adjacent docs own unrelated DAT vector and EPFTileContext behavior. | Adjacent docs; target range/padding notes. | already-present | already-present: target Evidence preserves adjacent padding/boundary facts; adjacent pages were not edited. |
| C-021 | Negative type/name evidence must be preserved as a score limiter. | Medium-high | `type_inspect` did not find `MiniMapFileLoader`, `MNMHeader`, or `MiniMapRenderer`; entity/name search did not find accepted MiniMap loader/MNM names. | Target open questions; score rationale; C++ no-code rationale. | incorporate | applied: target Status, Score Rationale, Evidence, and Current-Pass Format sections preserve type/name limits and score/C++ impact. |
| C-022 | Scoped validators should run only after supervisor-authorized by-* implementation callback. | High | Report-only scope forbids by-* edits now; validators are useful only after target/support docs change. | Validator Results; implementation checklist. | incorporate | applied: scoped validators ran after callback for target (`000000007387`) and UID0000XO (`000000007388`), both exit 0 and `ok: 1`. |
| C-023 | Generated reports, coverage files, validator state, supervisor ledgers, lifecycle/archive files, and report execution commands are out of scope for B013. | High | User assignment explicitly forbids those edits/commands. | Changed Files; implementation checklist; final response. | not-applicable | excluded-with-reason: no manual generated/coverage/validator-state/supervisor-ledger/lifecycle/archive edits and no `execute_report`; validator-owned generated refresh was deferred and is reported below. |

## Positive Evidence Summary

- Current MCP confirms all modeled function boundaries and the two raw no-function bodies.
- Current MCP confirms the constructor initializes the two small-wide-string fields and clears payload state.
- Current MCP confirms load/decode/destructor behavior sufficiently for a future child-page split.
- Current MCP confirms `BuildSymbolViews` creates the loader, calls load, consumes decoded payload header/image bytes, and calls the JPEG tile-context decoder.
- Current docs already route ownership to the MiniMap source-family root, which remains the best source placement.
- Current adjacent docs support clean range boundaries: `UID0000XX` ends before `0x00457620`, and `UID0000XY` begins at `0x00457a60`.

## Negative Evidence Summary

- No direct old report for `TARGET-REPORT-UID:0001ZZ` was found.
- No IDA type named `MiniMapFileLoader`, `MNMHeader`, or `MiniMapRenderer` was found during `type_inspect` checks.
- No accepted symbol names for `MiniMapFileLoader`, `MNM`, or `.mnm` loader records were found by entity/name checks in the relevant ranges.
- IDA string lookup did not provide clean typed strings for the default wide strings; bytes had to be decoded directly.
- No direct xrefs exist to the raw starts `0x00457760` or `0x00457780`.
- No absolute/RVA byte-pattern references to the raw starts `0x00457760` or `0x00457780` were found.
- Old support research includes a stale BMP route for the `BuildSymbolViews` image decode. Live MCP contradicts it.

## Ranked Ownership Analysis

1. `[UID:0000LE] by-file/MiniMap.md` remains the correct canonical owner.
   - It owns the generated output route `NexusTK/map/MiniMap.cpp`.
   - `BuildSymbolViews` is the direct caller for the modeled loader constructor/load/destructor route.
   - The `.mnm` payload is consumed in the MiniMap renderer/control workflow documented under the MiniMap file family.

2. `[UID:00008F] by-class/MiniMapRenderer.md` is semantic support, not the canonical owner.
   - `BuildSymbolViews` uses renderer fields and tile context storage.
   - The class page is still a declaration/aggregate support page and should not own the file-loader helper island.

3. `[UID:0000XO] MiniMapRendererAndControls` is the direct modeled caller support page.
   - It should receive the stale route correction from BMP to JPEG after Gate 1 approval.
   - It should not absorb UID0001ZZ; the loader methods remain a separate helper-island marker owned by the MiniMap file family.

4. Image decode wrappers are callees, not owners.
   - `[UID:0002TN] DecodeJpegBufferToTileContext` is the live route from `BuildSymbolViews`.
   - `[UID:0002TM] Decode8BitBmpToTileContext` is rejected for this target route.

5. Adjacent memory pages are boundary evidence only.
   - `[UID:0000XX] DATIndexVectorFindNodeByKey` ends before the target and owns unrelated DAT index-vector behavior.
   - `[UID:0000XY] EPFTileContext` begins after the target and owns tile-context behavior, not the loader island.

## Source Placement

Keep source placement under the current MiniMap file root:

- `PROPOSED_RECONSTRUCTION_PATH`: inherited from `[UID:0000LE] by-file/MiniMap.md`, `NexusTK/map/`
- Generated output route: `auto-generated/NexusTK/map/MiniMap.cpp`
- UID0001ZZ source role: helper-island marker and split-plan index
- UID0001ZZ emitted body status: marker-only until accepted child pages and field/record names exist

No new file root is justified for this target. No class page should become the owner. No image-decode page should become the owner.

## Range / Split / Padding / Reclassification Analysis

Recommended split inventory for a later implementation callback:

| Candidate child | Range | Status | Recommendation |
| --- | --- | --- | --- |
| Loader constructor | `0x00457620-0x004576a6` | IDA function | Modeled child candidate after field names are accepted |
| Loader destructor | `0x004576b0-0x00457757` | IDA function | Modeled child candidate after field names are accepted |
| Raw string reset | `0x00457760-0x00457780` | No IDA function, no direct xrefs | Raw no-code/no-route child only if a split is authorized |
| Raw transform/write | `0x00457780-0x00457842` | No IDA function, no direct xrefs | Raw no-code/no-route child only if a split is authorized |
| Loader load | `0x00457850-0x00457953` | IDA function | Modeled child candidate after `.mnm` names are accepted |
| Payload decode | `0x00457960-0x00457a5d` | IDA function | Modeled child candidate after key/payload names are accepted |

Padding is clean and supports the existing range:

- `0x00457613-0x00457620`: thirteen `0xcc` bytes after the preceding UID0000XX function.
- `0x004576a6-0x004576b0`: ten `0xcc` bytes.
- `0x00457757-0x00457760`: nine `0xcc` bytes.
- `0x00457842-0x00457850`: fourteen `0xcc` bytes.
- `0x00457953-0x00457960`: thirteen `0xcc` bytes.
- `0x00457a5d-0x00457a60`: three `0xcc` bytes before successor UID0000XY.

Reclassification result:

- Do not collapse the target into `[UID:0000XO]`.
- Do not promote raw bodies as normal source-emitting functions.
- Do not emit a full aggregate body from UID0001ZZ.
- Keep a marker-only aggregate page and document exact future split points.

## Function / Child Inventory

### `sub_457620` Constructor, `0x00457620-0x004576a6`

Observed behavior:

- Initializes a small-wide-string object at `this + 0x00`.
- Initializes a small-wide-string object at `this + 0x18`.
- Clears `this + 0x30` and `this + 0x34`.
- Calls the wide-string assign helper with `0x0061093c`, count `0x14`, for the first field.
- Calls the wide-string assign helper with `0x00610968`, count `0x0a`, for the second field.

Default bytes:

- `0x0061093c`: UTF-16LE string beginning `MNMEncodeDecodeBy`, followed by codepoints `U+D6C8 U+AC74 U+AE40`, then NUL.
- `0x00610968`: UTF-16LE string `MNM_Ver0.0`, then NUL.

### `sub_4576B0` Destructor, `0x004576b0-0x00457757`

Observed behavior:

- Frees payload pointer at `this + 0x30` when non-null.
- Tears down the large-string storage for the `this + 0x18` field if needed.
- Tears down the large-string storage for the `this + 0x00` field if needed.
- Resets the small-string metadata to length `0`, capacity `7`, and first wchar `0`.

### Raw Reset Helper, `0x00457760-0x00457780`

Observed behavior:

- Calls the same wide-string assign helper for `0x0061093c`, count `0x14`, into `this + 0x00`.
- Calls the same wide-string assign helper for `0x00610968`, count `0x0a`, into `this + 0x18`.
- Does not touch payload pointer or payload size in the checked instructions.

Status:

- Not an IDA function.
- No direct xrefs to the start.
- No observed absolute/RVA byte-pattern pointer references to the start.

### Raw Transform/Write Helper, `0x00457780-0x00457842`

Observed behavior:

- Opens the caller path argument for read.
- Reads the full file into a buffer.
- Calls `sub_457960(this, buffer, fileLength)` to transform the buffer in place.
- Reopens the caller path for output using the mode string at `0x0060df28` as rendered by IDA.
- Writes the expected version string from `this + 0x18` as `(length + 1)` wide characters.
- Writes the transformed buffer.
- Closes streams and frees the buffer.

Status:

- Not an IDA function.
- No direct xrefs to the start.
- No observed absolute/RVA byte-pattern pointer references to the start.
- The read/write behavior is documented as observed, but the exact source-level name and liveness are not established.

### `sub_457850` Load Method, `0x00457850-0x00457953`

Observed behavior:

- Opens the caller path argument in read-binary mode.
- Seeks to `0x42` from end, gets body length with `ftell`, then seeks to `0x42` from start.
- Allocates and reads `(expectedVersion.length + 1)` wide characters.
- Subtracts the version read byte count from body length.
- Compares the read version/header string with the expected version field at `this + 0x18`.
- If the header matches and `this + 0x30` is null, allocates the remaining payload length into `this + 0x30`, reads it, and calls `sub_457960(this, payload, payloadLength)`.
- Closes the file and frees the temporary version string.

### `sub_457960` Payload Decode Method, `0x00457960-0x00457a5d`

Observed behavior:

- Allocates two temporary wide buffers derived from the decode-key length at `this + 0x10`.
- Copies the key string from `this + 0x00`.
- Builds a reversed copy of the key.
- For each payload byte while both `index < payloadLength` and `index < 200`, XORs the byte with the low byte of the forward key and then the low byte of the reversed key.
- Frees both temporary buffers.

This proves `this + 0x00` acts as the decode key for this helper island. It does not prove the key's source-level name.

## First-Draft C++ Recommendation

Do not emit first-draft C++ for UID0001ZZ as a single aggregate body.

For the existing aggregate page, keep marker-only code similar to the current marker and improve the surrounding prose. A later callback may split modeled children and draft exact functions only after accepted names exist for:

- Loader type name
- Decode key field at `+0x00`
- Expected version/header field at `+0x18`
- Payload data pointer and size fields at `+0x30/+0x34`
- `.mnm` payload header records copied into renderer fields

Suggested neutral future names, if the supervisor accepts inferred names in child pages:

- `m_decodeKey` for `this + 0x00`
- `m_expectedVersion` for `this + 0x18`
- `m_payloadData` for `this + 0x30`
- `m_payloadSize` for `this + 0x34`

Raw helpers should remain no-code/no-route unless a later owner decision requires raw child pages:

- `0x00457760-0x00457780`: reset decode key and expected version only.
- `0x00457780-0x00457842`: transform/write path with no direct current caller evidence.

## Final Recommendation

Proceed to Gate 1 with a report-only recommendation:

1. Accept UID0001ZZ as a MiniMap-owned helper-island marker.
2. Update target prose and metadata after supervisor approval.
3. Correct the stale MiniMap image-decode route to JPEG support.
4. Do not create split child pages in this first report-only pass.
5. Do not emit aggregate C++ from UID0001ZZ.
6. Preserve raw no-route helper status unless a later implementation callback explicitly requests raw child pages.

## Recommended Target Doc Changes

For `by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md` after Gate 1 approval:

- Update `COMPLETION` to `88`.
- Update `CONFIDENCE` to `91`.
- Keep `CANONICAL_OWNER:0000LE`.
- Keep `EMITTER_UIDS:0000LE`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Keep marker-only C++.
- Replace descriptions that call `this + 0x00` the map path/file path with a neutral decode-key description.
- Add the decoded default string evidence:
  - `0x0061093c`: `MNMEncodeDecodeBy` plus codepoints `U+D6C8 U+AC74 U+AE40`.
  - `0x00610968`: `MNM_Ver0.0`.
- Clarify load method path handling: `BuildSymbolViews` passes `MiniMapRenderer +0x02` as the file path argument; the loader does not store it into `this + 0x00` in the checked function.
- Add exact `.mnm` read facts: seek offset `0x42`, version/header read count `(expectedVersion.length + 1)` wide characters, remaining body stored at `+0x30/+0x34`.
- Add exact payload-consumption facts from `BuildSymbolViews`: decoded payload header fields are copied into renderer fields starting at `+0x218`; image length is read from payload offset `+0x1c`; image bytes begin at payload offset `+0x20`.
- Correct image decode route to `[UID:0002TN] DecodeJpegBufferToTileContext`.
- Preserve child split inventory and raw no-route explanation.

## Recommended Support Doc Changes

For `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md` after Gate 1 approval:

- Replace stale statements that route the MiniMap `.mnm` image through `[UID:0002TM] Decode8BitBmpToTileContext`.
- State the live route as `[UID:0002TN] DecodeJpegBufferToTileContext`, called from `0x004544a8` inside `BuildSymbolViews`.
- Add that the call uses decoded loader payload bytes at `payload + 0x20` and length from `payload + 0x1c`.
- Keep UID0001ZZ as support/helper-island, not absorbed into UID0000XO.

For `by-class/MiniMapRenderer.md` after Gate 1 approval:

- Add or confirm a short support note that `.mnm` loader payload image data is routed to the JPEG tile-context decoder.
- Do not make the class page the canonical owner of UID0001ZZ.

For `by-file/MiniMap.md` after Gate 1 approval:

- No structural ownership change is required.
- Optionally update the UID0001ZZ source-disposition row to include the corrected decode-key field and JPEG route if the supervisor wants the file root to carry the same correction.

For image decode support pages:

- `[UID:0002TN] DecodeJpegBufferToTileContext` already matches the live caller route and does not require a UID0001ZZ-driven change.
- `[UID:0002TM] Decode8BitBmpToTileContext` should not be linked as the MiniMap `.mnm` image route unless separate evidence is found.
- `[UID:000175] ImageDecodeWrappers` does not require structural change for this target.

For adjacent boundary pages:

- `[UID:0000XX] DATIndexVectorFindNodeByKey` needs no ownership or range change.
- `[UID:0000XY] EPFTileContext` needs no ownership or range change.

## Score And Metadata Recommendation

Recommended target metadata after implementation:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:0000LE
EMITTER_UIDS:0000LE
RECONSTRUCTABLE:TRUE
```

Rationale:

- Completion rises because current MCP resolves exact modeled/raw range status, decode-key interpretation, payload route, image decoder route, and raw no-route evidence.
- Confidence rises because live decompile/disassembly/xrefs support the corrected field and caller-route claims.
- Completion remains below final-ready levels because exact source field names, `.mnm` header/record names, raw helper liveness, and split child pages are still unresolved.

No support page score changes are required solely from this report. If UID0000XO is edited to correct the stale BMP route, a small confidence increase may be considered by the implementing agent, but this report does not require it.

## Open Questions With Attempted Resolution

### Loader field names

Attempted resolution:

- `this + 0x00` is not the caller path in the checked functions. It is initialized from the default decode string and used by the decode loop.
- `this + 0x18` is the expected version/header string.
- `this + 0x30/+0x34` are payload data/length.

Remaining limitation:

- Source-original names are not proven by IDA types or symbols. Use neutral field names unless the supervisor accepts inferred names.

### `.mnm` format and header names

Attempted resolution:

- Load starts at offset `0x42`.
- The expected version string is read after that offset.
- The remaining decoded body contains at least a `0x20`-byte prefix consumed by `BuildSymbolViews`, with image length at payload offset `+0x1c` and image bytes at `+0x20`.

Remaining limitation:

- Exact source names for the outer `.mnm` file header and decoded payload header are not proven.

### Modeled vs raw helper bodies

Attempted resolution:

- Four modeled IDA functions are recoverable.
- Two raw helpers have no function objects and no direct route evidence.

Remaining limitation:

- Raw helpers could be retained internal/legacy entrypoints, but this pass did not prove a live source route to them.

### BuildSymbolViews caller route

Attempted resolution:

- `0x00454441` calls constructor.
- `0x00454457` calls load with renderer path at `MiniMapRenderer +0x02`.
- `0x004544a8` calls JPEG decode wrapper `[UID:0002TN]`.
- `0x00454b5a` calls destructor; an additional destructor xref at `0x005f9e61` is consistent with cleanup/unwind metadata for the same caller context.

Remaining limitation:

- Full source-level exception cleanup naming is not needed for this target.

### False or legacy assumptions

Attempted resolution:

- The old BMP image route is rejected for UID0001ZZ/`BuildSymbolViews`.
- The `this + 0x00` path-field interpretation is rejected for this helper island.

Remaining limitation:

- Support docs must be updated during a later implementation callback to remove stale wording.

## Validator Results

Scoped validators were run only after the supervisor Gate 1 implementation callback and only for the by-* docs edited by B013.

Command 1:

> Executable block R001 was removed from this report and preserved verbatim in [0001ZZ-MiniMapFileLoaderHelpers-source-quality-removed.md](0001ZZ-MiniMapFileLoaderHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- `command_id`: `000000007387`
- `command_timestamp`: `2026-07-05T20:11:22-04:00`
- Exit code: `0`
- `ok`: `1`
- Target-specific updates: `completion_update 0001ZZ ... 88`, `confidence_update 0001ZZ ... 91`, `autogen_registry_update 0001ZZ ...`, `reference_index_add 0002TM`, `reference_index_add 0002TN`
- Warnings/errors: none reported for the target file
- Generated/project side effects: `projected_stats_update` for `project-level/-auto-completion-stats.md`; `generated_refresh: deferred`, `generated_refresh_command_id: 000000007387`, `generated_refresh_timestamp: 2026-07-05T20:11:22-04:00`

Command 2:

> Executable block R002 was removed from this report and preserved verbatim in [0001ZZ-MiniMapFileLoaderHelpers-source-quality-removed.md](0001ZZ-MiniMapFileLoaderHelpers-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- `command_id`: `000000007388`
- `command_timestamp`: `2026-07-05T20:11:31-04:00`
- Exit code: `0`
- `ok`: `1`
- Target-specific updates: `reference_index_add 0002TM`, `reference_index_add 0002TN`
- Warning: `missing_ref_uid 0003FY ... UID reference is not present in validator.ini`; this is unrelated to UID0001ZZ and was already present in UID0000XO support text.
- Generated/project side effects: `projected_stats_update` for `project-level/-auto-completion-stats.md`; `generated_refresh: deferred`, `generated_refresh_command_id: 000000007388`, `generated_refresh_timestamp: 2026-07-05T20:11:31-04:00`

Post-validator generated freshness check:

- `auto-generated/-ag-research-tracker.md` header now shows `validator-command-id: 000000007388` and `validator-refreshed-at: 2026-07-05T20:11:31-04:00`; UID0001ZZ row is `88/91`, combined `89.5`, reconstructable `true`.
- `auto-generated/-ag-memory-coverage.md` header now shows `validator-command-id: 000000007388` and `validator-refreshed-at: 2026-07-05T20:11:31-04:00`; UID0001ZZ remains coded with owner/emitter `0000LE`.
- `auto-generated/NexusTK/map/MiniMap.cpp` header now shows `validator-command-id: 000000007388` and `validator-refreshed-at: 2026-07-05T20:11:31-04:00`; UID0001ZZ generated marker row is `Completion:88 | Confidence:91`.

No validators were run for `by-class/MiniMapRenderer.md`, `by-file/MiniMap.md`, or image decode support pages because B013 did not edit them in this callback and the current docs already carried the necessary ownership/JPEG/BMP separation at same-or-greater detail.

## Changed Files

Edited by B013 in this implementation callback:

- `by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md`
- `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md`
- `tools/leaser/Agents/Agent-B013/research/0001ZZ-MiniMapFileLoaderHelpers-source-quality.md`

Validator-owned side effects were reported under `Validator Results`. B013 did not manually edit generated files, coverage reports, project-level generated reports, validator state, supervisor ledgers, lifecycle/archive files, or report execution files.

## Implementation Tracking Checklist

- [x] Gate 1 callback precondition: supervisor passed the repaired report at SHA256 `2CBF00BE6C6384C900B228FDF4F4EC15D066A0FF6C2C0DEB835E7C5B18CE3D01` before implementation. Covers C-015, C-022, C-023.
- [x] Lease discipline: B013 leased only `by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md` and `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md`; both leases were released successfully, and `current_leases.md` showed no active leases afterward. Covers C-022, C-023.
- [x] Ledger callback bookkeeping: every Claim And Incorporation Ledger row C-001 through C-023 now records `applied`, `already-present`, or `excluded-with-reason` with destination/proof. Covers C-001 through C-023.

Target document checks for `by-memory/0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md`:

- [x] Metadata set to `COMPLETION:88` and `CONFIDENCE:91`; `CANONICAL_OWNER:0000LE`, `EMITTER_UIDS:0000LE`, and `RECONSTRUCTABLE:TRUE` remain unchanged. Validator `000000007387` confirmed completion/confidence updates. Covers C-001, C-003.
- [x] MiniMap file-family ownership is preserved in metadata, Assignment Decision, and Cross-References; class/image-decode ownership is rejected for this helper island. Covers C-001, C-017, C-018, C-019.
- [x] Marker-only C++ disposition is preserved and expanded: no monolithic aggregate body, no raw-helper source-body promotion, modeled child C++ blocked until accepted field/type/record names exist. Covers C-002, C-012, C-013, C-021.
- [x] `this+0x00` path/file-path wording was replaced with decode-key wording; target Behavior and Field And Format Evidence state the `.mnm` path is the argument from `MiniMapRenderer+0x02`. Covers C-004, C-010.
- [x] `this+0x18` expected `.mnm` version/header string, `this+0x30/+0x34` payload pointer/length, default strings `0x0061093c` and `0x00610968`, observed `0x42` load offset, version read, payload allocation/read, and 200-byte XOR decode cap are documented in target Behavior, Field And Format Evidence, and Evidence sections. Covers C-005 through C-009.
- [x] `BuildSymbolViews` constructor/load/destructor route, decoded payload header copy, image length at payload `+0x1c`, image bytes at payload `+0x20`, and JPEG decode route `[UID:0002TN]` at `0x004544a8` are documented in target Behavior/Evidence/Cross-References/Changes. Covers C-010, C-011.
- [x] Old BMP route through `[UID:0002TM]`, path-field interpretation for `this+0x00`, class/image-decode canonical ownership, and source-emitting raw helper alternatives are rejected in target Behavior, Current-Pass Format And Helper Exclusions, Cross-References, and Changes. Covers C-011, C-017, C-019.
- [x] Raw helper no-route proof is incorporated for `0x00457760` and `0x00457780`: no IDA function object, no direct xrefs, no absolute/RVA pointer hits, observed reset/write behavior, and no normal source C++ emission. Covers C-012, C-013.
- [x] Exact split plan and padding/boundary evidence were preserved and updated, including no child page creation in this callback. Covers C-014, C-015, C-020.
- [x] Negative type/name evidence and open source-name blockers are preserved in Status, Score Rationale, Evidence, Current-Pass Format And Helper Exclusions, and first-draft C++ rationale. Covers C-002, C-003, C-021.

Support document checks:

- [x] `by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md` now records UID0001ZZ path/decode-key correction, decoded payload field flow, image length at `+0x1c`, image bytes at `+0x20`, and `[UID:0002TN]` JPEG route at `0x004544a8`. Covers C-010, C-011, C-016.
- [x] UID0000XO now explicitly rejects `[UID:0002TM] Decode8BitBmpToTileContext` for the `.mnm` payload path and keeps UID0001ZZ as a support/helper-island dependency rather than absorbing ownership. Covers C-001, C-011, C-016.
- [x] `by-class/MiniMapRenderer.md` was not edited: it already keeps UID0001ZZ as semantic renderer-local support while routing ownership through MiniMap. Covers C-017.
- [x] `by-file/MiniMap.md` was not edited: it already records UID0001ZZ as a MiniMap helper-island marker with no structural ownership change required. Covers C-001, C-018.
- [x] Image decode support pages were not edited: UID0002TN already records the MiniMap caller at `0x004544a8`, UID0002TM records the `LEVEL.BMP`/MainMenu route, and UID000175 already separates JPEG and BMP child routes. Covers C-019.
- [x] Adjacent UID0000XX and UID0000XY were not edited; target boundary/padding evidence preserves their no-change status. Covers C-020.

Stale assumption and negative evidence preservation:

- [x] Old-report search results remain in Evidence Checked: no direct `TARGET-REPORT-UID:0001ZZ`; B010 is parent/source-family marker lead; B007 is support lead with stale BMP route rejected; incidental adjacent/String helper reports are non-coverage leads. Covers C-001, C-002, C-011, C-016.
- [x] Raw helper negative route evidence and type/name negative evidence are incorporated into target and preserved in the report ledger. Covers C-012, C-013, C-021.

Validation and generated-refresh checks:

- [x] Target validator ran: `python .\tools\validator.py --mode file --file by-memory\0x00457620-0x00457a5d.MiniMapFileLoaderHelpers.md --apply --queue-timeout 240`; command `000000007387`, timestamp `2026-07-05T20:11:22-04:00`, exit `0`, `ok: 1`; validator initially reported generated refresh deferred. Covers C-022.
- [x] UID0000XO validator ran: `python .\tools\validator.py --mode file --file by-memory\0x00453df0-0x004563b5.MiniMapRendererAndControls.md --apply --queue-timeout 240`; command `000000007388`, timestamp `2026-07-05T20:11:31-04:00`, exit `0`, `ok: 1`; validator initially reported generated refresh deferred. Covers C-022.
- [x] Validator warning recorded: UID0000XO reported `missing_ref_uid 0003FY`, unrelated to UID0001ZZ. Covers C-022.
- [x] Generated/manual scope respected: no manual edits to generated tracker/coverage/C++ output, project-level generated reports, validator state, supervisor ledgers, lifecycle/archive files, or report execution files; validator-owned `projected_stats_update` is recorded, and read-only generated header checks show tracker/coverage/MiniMap.cpp caught up to command `000000007388`. Covers C-023.
- [x] No `execute_report`, dry-run/probing execute variants, registry lifecycle commands, manual report moves, or archive moves were run. Covers C-023.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000007392","destination_path":"executed-b-agent-research/B013/0001ZZ-MiniMapFileLoaderHelpers-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B013/research/0001ZZ-MiniMapFileLoaderHelpers-source-quality.md","timestamp":"2026-07-05T20:21:19-04:00","uid":"0001ZZ"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001ZZ-MiniMapFileLoaderHelpers-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/0001ZZ-MiniMapFileLoaderHelpers-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001ZZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
