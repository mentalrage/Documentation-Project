** TARGET-REPORT-UID:0002PG **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002PG SoftwareRenderCompatLineCallback Source-Quality Research

## Finalized Report / Current Recommendation

- Archive-safe recommendation: keep the B002 target-only implementation for [UID:0002PG] `by-memory/0x004bb9b0-0x004bc08a.SoftwareRenderCompatLineCallback.md`; this report records the research evidence, applied callback details, and validator command `000000007444` proof for that implementation.
- Historical lifecycle note: the pre-callback Gate 1 artifact SHA256 was `7B5F82895456FE773B1ABF044D3F98AF746C76C496A470DEBA867BE98AE29470`; supervisor execution commands `000000007446` and `000000007452` plus invalidation commands `000000007448` and `000000007454` are lifecycle history only. Validator-owned archive path/history/footer is authoritative after supervisor execution.
- Target metadata after the B002 callback records `COMPLETION:88`, `CONFIDENCE:90`; `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, and blank `EMITTER_POSITION_OPTIONAL` were preserved.
- Preserve direct owner/emitter as [UID:0000OC][Surface](by-file/Surface.md) / `NexusTK/render/Surface.cpp`. The callback target is selected through slot `0x0069b3e4` / `dword_69B3E4` / `g_pfnDrawLineDelta`, not through Ranking UI source.
- Callback-time generated-output correction: after scoped validator command `000000007444`, UID0002PG appeared as an empty marker in `auto-generated/NexusTK/render/Surface.cpp`; B002 found no generated `class_RankingEventListPane.cpp` file in that inspection. The older `RankingEventListPane::DrawLine_555` wording should be historical generated pollution only.
- Resolve the practical callback ABI and receiver-field blockers at documentation level: receiver is `GrafPort *` in `ecx`; meaningful stack arguments are signed `deltaX` and `deltaY`; IDA's apparent `edx` parameter is unused; the function ends with `retn 8`.
- Do not populate formal C++ in the first implementation callback unless the callback author supplies an exact formal body preserving the target-specific return-value and axis/mode asymmetries. This report recommends a docs-and-score update plus a precise first-draft C++ readiness/no-code proof rather than a casual 618-instruction body transcription.
- Implementation callback disposition: formal C++ remains blank; the target carries the branch-level no-code proof and generated-output wording. Validator lifecycle history is authoritative after execution.

## Supporting Research

- Assignment mode: B002 report-only first pass for [UID:0002PG]. B002 did not edit by-* docs, generated files, coverage files, validator state, lifecycle state, or supervisor ledgers during this report pass.
- Implementation callback mode: B002 later edited only the authorized target page plus this B002 report, ran the scoped file validator, and did not edit optional support docs, generated files manually, manual coverage files, supervisor ledgers, lifecycle/archive state, or execute-report state.
- Report repair mode: after historical supervisor execution command `000000007446` and invalidation command `000000007448`, B002 repaired only this report text for archive-safe lifecycle/path wording. The validator-owned `VALIDATOR-REPORT-HISTORY` footer was not edited.
- MCP requirement: satisfied. Direct JSON-RPC `initialize` / `tools/list` succeeded against `http://127.0.0.1:13337/mcp`; active database was `supervisor_recovery_20260705`.
- MCP health: `B002-0002PG-MCP-006` at `2026-07-05T22:45:58-04:00` returned `status:"ok"`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
- Search-gated lead review used UID `0002PG`, range `0x004bb9b0-0x004bc08a`, `SoftwareRenderCompatLineCallback`, `sub_4BB9B0`, `dword_69B3E4`, `g_pfnDrawLineDelta`, `DrawLine_555`, `LineClipHelpers`, `BlendRgb555`, `GrafPortLineTo`, `GrafPortDrawRectFrame`, `SurfaceRenderCallbackTable`, and RGB565 peer terms.
- Existing aggregate/family docs were treated as leads only. B002 target-specific MCP checks were performed for bounds, xrefs, slot refs, byte patterns, callee/profile data, decompile behavior, caller wrappers, generated-output state, and score blockers.

## Target

- Target UID: `0002PG`
- Target path: `by-memory/0x004bb9b0-0x004bc08a.SoftwareRenderCompatLineCallback.md`
- During this repair cycle the editable repair path `tools/leaser/Agents/Agent-B002/research/0002PG-SoftwareRenderCompatLineCallback-source-quality.md` was used; executed copies use the validator-owned archive path/history/footer as authoritative, and prior execution command `000000007452` plus invalidation command `000000007454` are lifecycle history only.
- Pre-callback target state: `COMPLETION:86`, `CONFIDENCE:89`, owner/emitter [UID:0000OC], reconstructable true, formal C++ blank.
- Post-callback target state: `COMPLETION:88`, `CONFIDENCE:90`, owner/emitter [UID:0000OC], reconstructable true, formal C++ blank.
- Generated tracker after scoped validator command `000000007444`: `auto-generated/-ag-research-tracker.md` lists `88/90`, average `89.0`, reconstructable `true`, reports `0`.

## Current Target State

- Before callback, the target already documented the exact half-open range `0x004bb9b0-0x004bc08a`, `sub_4BB9B0` size `0x6da`, no direct callers, two target data refs, 26 slot refs, line clipper use, BlendRgb555 dependency, Surface assignment, and RGB565 peer relationship.
- The callback replaced the stale generated-owner statement. Read-only generated inspection after validator command `000000007444` found UID0002PG at `auto-generated/NexusTK/render/Surface.cpp:356` as `Completion:88 | Confidence:90 | Empty Emitter Marker`, with refreshed header timestamp `2026-07-05T23:00:41-04:00`.
- The callback replaced the stale blank-C++ rationale. Receiver fields, slot direction, endpoint/delta semantics, local endpoint structure direction, and source placement are now documented in the target; the remaining C++ blocker is exact, safe first-draft transcription of a large line rasterizer with nonuniform return and mode paths.
- Formal C++ remains blank by accepted callback disposition.

## Heuristic / Inference Reanalysis And Validation

- Callback typedef: `GrafPort::LineTo` decompiles to `g_pfnDrawLineDelta(this, x - m_currentX, y - m_currentY)`, and current disassembly shows it tail-jumps to slot `0x0069b3e4` with `ecx` preserved. Target disassembly shows `retn 8`, so the meaningful callback stack arguments are `deltaX` and `deltaY`. IDA's `int __fastcall(int, int, int, int)` is an ABI artifact caused by `ecx` receiver plus an unused `edx` register.
- Receiver fields: accepted GrafPort and UID0002PF docs support `m_currentY` at `+0x68`, `m_currentX` at `+0x6c`, `m_drawMode` at `+0x70`, `m_drawEnabled` at `+0x71`, draw color/index at `+0x74`, and `m_surfaceContext.pixelData` / `rowStride` / `bounds.left` / `bounds.top` at `+0x20/+0x28/+0x2c/+0x30`.
- Endpoint/signature names: the source-facing line callback should use signed deltas, not absolute endpoints. The local clipped endpoints should use the already accepted `LineClipPoint` shape from [UID:00016H], with fields ordered `y, x`.
- Body behavior: current decompile resolves the high-level line shape, but also exposes target-specific asymmetries. Axis-aligned paths contain draw-mode direct, color-index-gated, and `BlendRgb555(..., 0x10)` cases; the clipped/general Bresenham paths write the resolved RGB555 color directly across octant-specific loops. Early and axis paths return different values in some branches.
- Source placement: [UID:0000OC] remains the direct file owner for installed software-render callback targets. [UID:00005V][GrafPort](by-class/GrafPort.md) owns wrappers such as `LineTo` and `DrawRectFrame`; [UID:0000TN] owns table storage; [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md) owns reusable blend math, not this installed callback body.
- Score movement: current evidence justifies a modest target-doc improvement to `88/90`. It does not justify `95+` because exact original public typedef spelling, exact original function spelling, and a validated formal line-body draft remain unresolved.

## Evidence Standards Used

- Direct IDA/MCP evidence was treated as authority for function modeling, xrefs, direct caller absence, byte patterns, padding, callee/profile data, decompile behavior, and wrapper ABI.
- By-* docs current at the time of B002 research were treated as implemented documentation evidence, not substitutes for target-specific MCP checks.
- Generated output from the B002 inspection/validator pass was treated as validator-owned state evidence for emitter freshness and stale generated-owner wording, not as authority for source ownership.
- Executed B reports and aggregate/family docs were used only as leads unless corroborated by B002 target-specific evidence.
- Inference was used for source-facing names such as `SoftwareRenderCompatLineCallback`, `deltaX`, `deltaY`, and the callback typedef. Each inference was checked against `GrafPort::LineTo`, `DrawRectFrame`, `SurfaceRenderCallbackTable`, UID0002PF, LineClipHelpers, and B002 MCP facts.

## Evidence Checked

- Direct MCP commands used:
  - `B002-0002PG-MCP-001` initialize and `B002-0002PG-MCP-002` tools/list at `2026-07-05T22:45:02-04:00`.
  - `B002-0002PG-MCP-005` idb_list at `2026-07-05T22:45:30-04:00`: one active session, `supervisor_recovery_20260705`.
  - `B002-0002PG-MCP-006` server_health.
  - `B002-0002PG-MCP-007` lookup_funcs for target, end, successor, RGB565 peer, LineClipHelpers, BlendRgb555, GrafPortGetClipRect, rectangle helper, and surface initializer.
  - `B002-0002PG-MCP-015` xrefs_to for target start, exclusive end, successor, and slot storage.
  - `B002-0002PG-MCP-016` get_bytes for predecessor gap, target/successor gap, callback-table block, and target prologue bytes.
  - `B002-0002PG-MCP-017` find_bytes for VA/RVA start/end encodings and slot-storage byte pattern.
  - `B002-0002PG-MCP-018` xref_query for code/data xrefs to target and slot.
  - `B002-0002PG-MCP-010` callees and `B002-0002PG-MCP-013` func_profile for `0x004bb9b0`.
  - `B002-0002PG-MCP-019R` decompile for `0x004bb9b0`; `B002-0002PG-MCP-020` line-range decompile review.
  - `B002-0002PG-MCP-021` to `B002-0002PG-MCP-024` disasm/decompile for `GrafPort::LineTo` and `GrafPort::DrawRectFrame`.
  - `B002-0002PG-MCP-025` target tail disassembly confirming `retn 8` and common cursor update tail.
- Documentation and generated-state reads:
  - target page, compat aggregate, Surface file page, SurfaceRenderCallbackTable global/memory pages, UID0002PF pixel callback, UID0002PJ RGB565 line callback, UID00016H LineClipHelpers, GrafPort class/page evidence, RectBounds layout/geometry support, generated `Surface.cpp`, generated tracker, generated by-memory coverage, and manual by-memory coverage leads.
- Intentionally skipped in the report-only pass:
  - no validators, no execute_report, no lifecycle/archive commands, no leases, and no by-* or generated edits were performed.
- Implementation callback commands:
  - lease acquire: `python .\tools\leaser\leaser.py B002 lease by-memory\0x004bb9b0-0x004bc08a.SoftwareRenderCompatLineCallback.md`, result `Success`.
  - scoped validator: `python .\tools\validator.py --mode file --file by-memory/0x004bb9b0-0x004bc08a.SoftwareRenderCompatLineCallback.md --apply --queue-timeout 240 --wait-generated`, command_id `000000007444`, command_timestamp `2026-07-05T23:00:41-04:00`, exit code `0`, `ok: 1`.
  - lease release: `python .\tools\leaser\leaser.py B002 unlease by-memory\0x004bb9b0-0x004bc08a.SoftwareRenderCompatLineCallback.md`, result `Success`; current lease report then showed no active leases.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID0002PG should move from `86/89` to `88/90`. | High | B002 MCP range/xref/body checks, resolved ABI/field/source placement blockers, generated-output correction. | Target metadata and score rationale | incorporate | callback applied: target header and score rationale became `88/90`; validator command `000000007444` reported `completion_update 0002PG ... 88` and `confidence_update 0002PG ... 90`. |
| C2 | Owner/emitter/reconstructable metadata should remain [UID:0000OC] / true / [UID:0000OC]. | High | Target, Surface page, callback-table xrefs, generated `Surface.cpp` marker, no Ranking direct route. | Target metadata/status | already-present | callback already-present: metadata preserved as `CANONICAL_OWNER:0000OC`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000OC`, blank `EMITTER_POSITION_OPTIONAL`. |
| C3 | The generated-owner wording was stale; at B002 generated inspection UID0002PG appeared as a Surface empty marker, while RankingEventListPane was historical pollution. | High | Generated output after command `000000007444`: `auto-generated/NexusTK/render/Surface.cpp:356` shows UID0002PG `Completion:88 | Confidence:90 | Empty Emitter Marker`. | Target Status, Ownership Notes, Generated Output caveat | incorporate | callback applied: target Status, Ownership Notes, Changes, and score rationale record the command `000000007444` `Surface.cpp` empty marker and historical Ranking/`DrawLine_555` pollution. |
| C4 | Callback ABI semantics are receiver in `ecx`, signed `deltaX/deltaY` stack args, unused IDA `edx` artifact, and `retn 8`. | High | `GrafPort::LineTo` disasm/decompile; target tail disasm; func_profile prototype artifact. | Target IDA MCP Evidence, Touched State, Reconstruction Notes | incorporate | callback applied: target IDA MCP Evidence and Touched State record `GrafPort *` receiver in `ecx`, signed stack deltas, unused `edx`, and tail `retn 8`. |
| C5 | Receiver field names are strong enough for target docs. | High | UID0002PF formal body, GrafPort class docs, LineTo/DrawRectFrame docs, B002 target decompile offsets. | Target Touched State and Reconstruction Notes | incorporate | callback applied: target Touched State records `m_currentY` `+0x68`, `m_currentX` `+0x6c`, draw mode/enabled/color fields, surface-context fields, and `LineClipPoint` `y, x`. |
| C6 | Range/split remains exact: target start is a modeled function, end is not, successor `0x004bc090` is separate, and `0x004bc08a-0x004bc090` is six `0xcc`. | High | MCP lookup_funcs, xrefs_to, get_bytes. | Target Address Range, IDA MCP Evidence, Reconstruction Notes, Changes | incorporate | callback applied: target carries B002 `supervisor_recovery_20260705` range/successor/padding evidence and rejected predecessor/successor/RGB565 merge alternatives. |
| C7 | Direct caller route remains absent; runtime entry is through slot storage. | High | xref_query code refs to target total `0`; xrefs_to target has two data refs; slot has 26 data refs. | Target IDA MCP Evidence, Ownership Notes, Score Rationale | incorporate | callback applied: target records two setup data refs, zero code xrefs, zero end xrefs, 26 slot refs, byte-pattern results, and no direct UI/dispatcher route recovered. |
| C8 | Formal first-draft C++ should not be inserted casually; the precise blocker is body-transcription risk for return/mode/octant paths, not unknown fields/signature. | Medium-high | 444-line decompile, 618 instructions, axis/mode asymmetry, tail `retn 8`, blank C++ block. | Target Reconstruction Notes and blank `RECONSTRUCTION_CPP CODE` block | incorporate | callback applied: formal C++ remained blank and target Reconstruction Notes carry disabled/empty-clip, horizontal clipped-out, mode-specific axis, vertical mode-3, Bresenham, common-tail, and exact-behavior risk proof. |
| C9 | Support docs mostly align but have stale generated-owner phrasing for UID0002PG. | Medium-high | Surface row and compat aggregate still mention Ranking generated names; B002 generated inspection contradicted current-owner wording. | `by-file/Surface.md`, compat aggregate if callback scope expands | not-applicable | callback excluded-with-reason: supervisor authorized target-only implementation and explicitly excluded optional support docs. |
| C10 | Manual coverage/tracker text is supervisor-owned; the target score change required validator-owned generated refresh, not B002 manual coverage edits. | High | Validator command `000000007444` refreshed generated tracker/coverage; manual coverage remains supervisor-owned. | Generated tracker/coverage and manual coverage state | incorporate | callback applied for validator-owned generated refresh (`research_tracker_update`, `memory_auto_coverage_update`); manual `by-memory/-coverage-report.md` remained excluded-with-reason and was not edited by B002. |

## Positive Evidence Summary

- Exact modeled target: `lookup_funcs` confirms `sub_4BB9B0` at `0x004bb9b0`, size `0x6da` / 1754 bytes. Exclusive end `0x004bc08a` is not a function.
- Boundary: `get_bytes` confirms `0x004bc08a-0x004bc090` is six `0xcc`; successor `0x004bc090` is separate `sub_4BC090`, size `0x1358`.
- Dispatch facts: target has two data refs, `0x00558734` and `0x00558b8a`; target has zero code xrefs; slot `0x0069b3e4` has 26 refs, including `GrafPort::LineTo`, `GrafPort::DrawRectFrame`, setup refs, and later render consumers.
- Pointer-byte facts: little-endian VA pattern for target start (`B0 B9 4B 00`) appears only at `0x558737` and `0x558b90`, matching the known setup refs; RVA start pattern has zero hits. End address VA/RVA patterns have zero hits.
- Callee/profile facts: func_profile reports 618 instructions, 89 basic blocks, caller_count `0`, callee_count `8`, no string refs, prototype artifact `int __fastcall(int, int, int, int)`, and callees including `sub_4B96C0`, `sub_4B7EB0`, `sub_543D40`, `sub_542AC0`, `sub_4C0710`, `sub_4BB2E0`, and security cookie glue.
- ABI facts: `GrafPort::LineTo` subtracts `m_currentY` and `m_currentX` from caller absolute y/x, mutates its stack args to deltas, preserves `ecx`, and tail-jumps to `unk_69B3E4`; the callback ends in `retn 8`.
- Source-placement facts: Surface owns the installed callback targets; GrafPort owns callers/wrappers; SurfaceRenderCallbackTable owns storage; SoftwareBlend16 owns the blend helper.

## IDA MCP Facts

| Check | Current fact |
| --- | --- |
| MCP session | `supervisor_recovery_20260705`, health ok, Hex-Rays ready. |
| Target function | `sub_4BB9B0`, `0x004bb9b0`, size `0x6da`. |
| Target exclusive end | `0x004bc08a` is not a function and has zero xrefs. |
| Successor | `0x004bc090` is `sub_4BC090`, size `0x1358`, with separate setup refs `0x00558740` and `0x00558b94`. |
| Padding | `0x004bb9a5-0x004bb9b0` is eleven `0xcc` before target; `0x004bc08a-0x004bc090` is six `0xcc` after target. |
| Target xrefs | two data refs: `0x00558734`, `0x00558b8a`; zero code refs by xref_query. |
| Slot refs | 26 refs to `0x0069b3e4`, all reported as data refs to slot storage. |
| Profile | 618 instructions, 89 basic blocks, caller_count `0`, callee_count `8`, no string refs. |
| Signature artifact | IDA reports `int __fastcall(int, int, int, int)`, but wrapper/tail disassembly proves source semantics are `ecx` receiver plus two stack deltas. |
| Tail ABI | `add [esi+6Ch], eax`, `add [esi+68h], eax`, security-cookie check, `retn 8`. |

## Function / Child Inventory

| Item | Range | Role | Status |
| --- | --- | --- | --- |
| Predecessor pixel callback | `0x004bb8d0-0x004bb9a5` | UID0002PF compat pixel callback, now source-ready formal C++ | Separate child; eleven-byte padding before UID0002PG. |
| Target | `0x004bb9b0-0x004bc08a` | UID0002PG compat/RGB555 line-delta callback | Exact target; docs should improve to `88/90`. |
| Padding | `0x004bc08a-0x004bc090` | alignment bytes | Six `0xcc`; no merge. |
| Successor sprite callback | `0x004bc090-0x004bd3e8` | UID0002PH sprite/tile blit callback | Separate callback-table slot `dword_69B3E8`. |
| RGB565 peer | `0x004c0850-0x004c0f7a` | UID0002PJ RGB565 line callback | Same line-delta slot, separate RGB565 family. |
| Shared line clipper | `0x004bb2e0-0x004bb5a5` | UID00016H `ClipLineToRect` / `ClipLineParameter` | Source-ready Surface helper pair called only by compat/RGB565 line callbacks. |

## Direct Xref / Caller Inventory

| Address / Item | Current result | Meaning |
| --- | --- | --- |
| `0x004bb9b0` code xrefs | `0` | No direct code caller route recovered. |
| `0x004bb9b0` data xrefs | `0x00558734`, `0x00558b8a` | Setup/initializer function-pointer writes only. |
| `0x004bc08a` xrefs | `0` | End boundary is not an entry or referenced data item. |
| `0x004bc090` data xrefs | `0x00558740`, `0x00558b94` | Successor has its own slot setup refs. |
| `0x0069b3e4` slot refs | `26` | Runtime dispatch storage used by line/frame consumers and setup. |
| Representative slot consumers | `sub_4B98F0`, `sub_4BA450`, `sub_467B30`, `sub_4B5810`, `sub_53FF00`, `sub_5C1460`, `sub_5C1810` | Consumers call the slot, not the target by direct function address. |

## Documentation Evidence And IDA Status

- [UID:0004H4] `GrafPort::LineTo` now carries formal C++ and accepted `g_pfnDrawLineDelta` naming. It proves the line callback receives deltas derived from `m_currentX/m_currentY`.
- [UID:000168] `GrafPort::DrawRectFrame` proves slot 1 draws rectangle edges and relies on the callback target to advance live cursor fields.
- [UID:0002PF] compat pixel callback now formalizes accepted field names and mode behavior for the neighboring slot-0 callback under the same Surface route.
- [UID:00016H] LineClipHelpers now formalizes `LineClipPoint`, `ClipLineToRect`, and `ClipLineParameter`, giving a source-facing endpoint structure for UID0002PG's clipped general path.
- [UID:0002PJ] RGB565 line peer remains blank C++ and keeps similar blockers, but it independently corroborates slot, range, no direct callers, line clipper, and Surface ownership.
- B002 generated inspection contradicted "current RankingEventListPane owner" language. It supports "validator command `000000007444` Surface empty marker; historical Ranking generated pollution."

## Ranked Ownership Analysis

### 1. [UID:0000OC] Surface

- Evidence for: target is installed by Surface initializer/table refs; no direct feature-pane callers; generated output after command `000000007444` placed UID0002PG marker in `NexusTK/render/Surface.cpp`; sibling UID0002PF and UID00016H emit through the same Surface route.
- Evidence against: body receiver is a `GrafPort *`, but that is callback-visible draw state, not direct owner proof.
- Decision: keep canonical owner and emitter as [UID:0000OC].

### 2. [UID:00005V] GrafPort

- Evidence for: receiver fields and line caller wrappers are GrafPort-owned; `LineTo` and `DrawRectFrame` are GrafPort methods.
- Evidence against: target itself has no direct caller, no normal method xrefs, and is installed through Surface callback setup; GrafPort is the receiver/state type and caller owner, not the callback implementation owner.
- Decision: support/field owner only.

### 3. [UID:0000TN] SurfaceRenderCallbackTable

- Evidence for: slot storage `0x0069b3e4` has 26 refs and is the dispatch mechanism.
- Evidence against: storage docs do not own the executable callback body.
- Decision: table/storage support only.

### 4. [UID:0000BN] RankingEventListPane

- Evidence for: stale recovered/generated names historically used `DrawLine_555`.
- Evidence against: B002 found no generated Ranking file, no direct code refs to target, no Ranking-specific state in the callback body, and table refs prove shared render dispatch.
- Decision: reject as historical generated pollution.

### Proposed new file/grouping, if applicable

- None. Existing `NexusTK/render/Surface.cpp` route is best. No new file, class, global, or owner is recommended.

## Source Placement

- Recommended placement: `NexusTK/render/Surface.cpp` through [UID:0000OC][Surface](by-file/Surface.md).
- Direct reason: the function is one of the installed software-render callback targets selected by the Surface render setup, paired with RGB565 and sibling compat callbacks.
- Support placement: `GrafPort.cpp` should keep the high-level wrappers such as `LineTo` and `DrawRectFrame`; `RectBounds.cpp`/geometry docs keep rectangle and point helpers; `SoftwareBlend16` keeps reusable RGB555/RGB565 blend math.
- Rejected placement: Ranking UI, GrafPort normal method, SurfaceRenderCallbackTable body, no-owner raw helper, and SoftwareBlend16 callback-body ownership.

## Range / Split / Padding / Reclassification Analysis

- Keep exact range `0x004bb9b0-0x004bc08a`.
- Do not merge predecessor UID0002PF: `0x004bb9a5-0x004bb9b0` is eleven `0xcc`, and UID0002PF is now a separate source-ready pixel callback.
- Do not merge successor UID0002PH: `0x004bc08a-0x004bc090` is six `0xcc`; successor has distinct setup refs and slot `dword_69B3E8`.
- Do not split UID0002PG based on horizontal/vertical/diagonal body regions. The target is one modeled function with a common prologue/clip/color setup and common cursor-update tail.
- Do not reclassify as raw/no-owner. It is a modeled reconstructable callback function with a live slot route.

## Negative Evidence Summary

- No direct code xref to `0x004bb9b0` was found in current xref_query.
- No direct caller route was recovered; runtime goes through slot storage.
- No RVA pointer-byte pattern for the target start was found; the only VA byte-pattern hits match known setup refs.
- No xrefs to exclusive end `0x004bc08a` were found.
- B002 found no generated RankingEventListPane file or UID0002PG generated body.
- No proof was found for original public typedef spelling, original function spelling, or a final 95+ source score.
- No evidence supports merging with predecessor pixel callback, successor sprite callback, RGB565 peer, table storage page, or blend-helper owner.

## IDA Rename / Type / Comment Recommendations

- No IDA DB edits are requested for this report-only assignment.
- Documentation source-facing names should prefer `SoftwareRenderCompatLineCallback`, `GrafPort *port`, `deltaX`, `deltaY`, `m_currentX`, `m_currentY`, `m_drawMode`, `m_drawEnabled`, `m_drawColor`/`colorIndex`, and `m_surfaceContext`.
- The table alias `g_pfnDrawLineDelta` is now strong enough for docs because `GrafPort::LineTo` formal C++ and `SurfaceRenderCallbackTable` both use that accepted name.
- Keep exact original callback typedef spelling open. The report resolves semantics, not original symbol proof.

## First-Draft C++ Recommendation

- Eligibility decision: not ready for direct first-draft C++ insertion in this report-first lifecycle item. The target is reconstructable and emitted through Surface, but the formal body should remain blank unless an implementation callback explicitly supplies and validates a complete formal body.
- Target-specific no-code proof for this pass: current evidence resolves ownership, fields, callback direction, and major behavior, but a safe formal C++ body must preserve branch-level details that are easy to change accidentally:
  - `retn 8` thiscall-like callback shape with `ecx` receiver and two stack deltas, not IDA's unused `edx` pseudo-argument;
  - disabled or empty-clip path advances both cursor fields and returns the vertical delta;
  - horizontal clipped-out path may store the absolute final X and return that value, not just the delta;
  - horizontal and vertical axis paths have mode-specific direct, color-index-gated, and BlendRgb555 cases;
  - vertical mode-3 path checks destination nonzero before blending, while the horizontal blend path is shaped differently in current decompile;
  - general clipped Bresenham paths write the resolved RGB555 color directly through multiple octant-specific loops;
  - common tail advances `m_currentX` and `m_currentY` separately and returns the vertical delta.
- The implementation callback updated the target's blank-C++ rationale from "endpoint/rect structures, receiver fields, and callback signature unresolved" to this more precise branch-level formal-body blocker.
- If supervisor later requests C++ insertion, the formal body should be written only inside the target `RECONSTRUCTION_CPP CODE` block, should not use `sub_`, `dword_`, `unk_`, labels, or decompiler temporaries, and should be validated with scoped file validator plus generated refresh. This report intentionally does not include a body-only sample.

## Final Recommendation

- Target-only documentation update was applied during the B002 implementation callback and should be preserved.
- Target score metadata after callback is `COMPLETION:88`, `CONFIDENCE:90`.
- Owner/emitter/reconstructable metadata and blank optional emitter position remain preserved.
- Formal C++ remains blank, with stale blocker wording replaced by the exact no-code proof above.
- B002 MCP evidence and generated-output correction were added to the target page during callback.
- Preserve rejected alternatives: no Ranking owner, no GrafPort normal-method promotion, no callback-table body owner, no SoftwareBlend16 owner, no no-owner/raw reclassification, no predecessor/successor merge, no RGB565 merge, and no 95+ score.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004bb9b0-0x004bc08a.SoftwareRenderCompatLineCallback.md`
- Metadata changes:
  - `COMPLETION:88`
  - `CONFIDENCE:90`
  - keep `CANONICAL_OWNER:0000OC`
  - keep `RECONSTRUCTABLE:TRUE`
  - keep `EMITTER_UIDS:0000OC`
  - keep blank `EMITTER_POSITION_OPTIONAL`
- Status and generated-output changes:
  - Replace "Current generated owner: caller-biased RankingEventListPane" with wording that validator command `000000007444` generated output was a Surface empty marker and RankingEventListPane is historical generated pollution.
  - Note generated `Surface.cpp` had UID0002PG at line 356 as an empty marker after validator command `000000007444`.
- IDA evidence changes:
  - Add B002 MCP session `supervisor_recovery_20260705` facts for health, function size, end non-function, successor separation, two data refs, zero code xrefs, 26 slot refs, byte-pattern results, 618 instructions, 89 blocks, and `retn 8`.
  - Add `GrafPort::LineTo` proof for delta semantics and `g_pfnDrawLineDelta`.
  - Add `DrawRectFrame` proof for four line-delta edge dispatches.
- Reconstruction notes:
  - Replace stale "final endpoint/rect structures, receiver fields, and callback signature unresolved" with the branch-level first-draft C++ blocker from this report.
  - Document accepted source-facing field names and local `LineClipPoint` endpoint shape.
- Score rationale:
  - Completion rises because callback ABI, source placement, field names, generated-output status, and B002 MCP checks are stronger than the pre-callback target text.
  - Confidence rises one point because B002 MCP independently reconfirmed the prior range/xref/callee facts and resolved the receiver/delta shape.
  - Do not raise higher because exact original symbol spelling and validated formal line-body C++ remain unresolved.

## Recommended Support Doc Changes

- Required for target callback: none if supervisor scope is target-only.
- Optional support cleanup if callback scope permits:
  - `by-file/Surface.md`: update UID0002PG row from `RankingEventListPane::DrawLine_555` generated-output phrasing to historical generated pollution / validator command `000000007444` Surface empty-marker wording.
  - `by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md`: refine the UID0002PG row similarly and note that UID0002PF is source-ready while UID0002PG remains blank formal C++ for branch-level body reasons.
  - `by-global/SurfaceRenderCallbackTable.md`: no required change; `g_pfnDrawLineDelta` / `DrawLineDelta` wording was already aligned during B002 review.
- Manual and generated reports remain supervisor/validator-owned. B002 should not hand-edit `by-memory/-coverage-report.md`, `auto-generated/-ag-research-tracker.md`, or `auto-generated/-ag-coverage-report-by-memory.md`.

## Score And Metadata Recommendation

- Pre-callback score/metadata: `86/89`; [UID:0000OC] owner/emitter; reconstructable true; blank formal C++.
- Recommended score/metadata after target implementation callback: `88/90`; owner/emitter/reconstructable unchanged; formal C++ remains blank with a corrected no-code proof.
- Reason not lower: B002 MCP and support docs resolved callback ABI, field names, source placement, generated-output wording, and split/range proof at target-specific detail.
- Reason not higher: exact original symbol spelling and a validated branch-level formal body are still open. This report does not supply formal C++ insertion text.
- Validator disposition: B002 ran only the scoped file validator on the target with `--apply --wait-generated`; broad validators and lifecycle commands were not run by B002.

## Open Questions With Attempted Resolution

- Open question: what is the exact original callback typedef spelling?
  - Evidence checked: `GrafPort::LineTo`, `DrawRectFrame`, target disassembly, target func_profile, SurfaceRenderCallbackTable docs, UID0002PF precedent.
  - Best supported resolution: semantics are resolved as receiver plus two signed deltas; exact typedef spelling remains open and caps confidence.
- Open question: should formal C++ be inserted now?
  - Evidence checked: full decompile, disassembly tail, axis paths, general Bresenham paths, sibling pixel formal body.
  - Best supported resolution: not in this first report/callback unless a complete formal body is supplied. Update blank-C++ rationale to branch-level body proof.
- Open question: was RankingEventListPane still a generated owner during B002 inspection?
  - Evidence checked: generated `Surface.cpp`, generated Ranking file search, target/support docs.
  - Best supported resolution: no. B002 generated inspection found Surface empty marker state; Ranking phrasing is historical pollution.
- Open question: should UID0002PG be merged with UID0002PH or UID0002PJ?
  - Evidence checked: lookup_funcs, xrefs_to, get_bytes, peer docs.
  - Best supported resolution: no. UID0002PH is the separate successor slot target; UID0002PJ is the RGB565 peer.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

- Manual coverage/tracker edits were not authorized for B002 and were not performed by B002 during report, callback, or report-repair passes.
- Historical manual coverage suggestion from the report-only pass, if a supervisor-owned manual coverage update is ever required outside B002 scope:

```text
        - [UID:0002PG][0x004bb9b0-0x004bc08a.SoftwareRenderCompatLineCallback](by-memory/0x004bb9b0-0x004bc08a.SoftwareRenderCompatLineCallback.md) 0x004bb9b0-0x004bc08a | function | SoftwareRenderCompatLineCallback : reconstructable : 88% : strong : Compat/RGB555 slot `dword_69B3E4` line-delta callback assigned to [UID:0000OC][Surface](by-file/Surface.md); 2026-07-05 B002 MCP session `supervisor_recovery_20260705` reconfirmed exact `0x6da` function bounds, six-byte `0xcc` successor padding, zero code xrefs to the start, two setup data refs, 26 slot-storage refs, receiver-in-`ecx` delta callback ABI with `retn 8`, LineClipHelpers and BlendRgb555 dependencies, accepted GrafPort surface-context/current-cursor/draw-state fields, validator command `000000007444` Surface.cpp empty-marker generated state, and a remaining branch-level formal C++ blocker rather than unresolved ownership or field blockers.
```

- Generated tracker/coverage was refreshed by scoped validator command `000000007444`; future generated state is validator-owned.

## Follow-Up Actions

- For this repair cycle, B002 returned the repaired artifact from the editable repair path for supervisor Gate 1 re-review. Executed copies use the validator-owned archive path/history/footer as authoritative, and prior execution command `000000007452` plus invalidation command `000000007454` are lifecycle history only.
- Historical lifecycle note: supervisor execution command `000000007446` and invalidation command `000000007448` are recorded only as history for the repaired artifact, not as current accepted coverage.
- B002 role boundary: B002 did not run `execute_report`, dry-run/probing execute variants, lifecycle/archive commands, manual report moves, or archive moves during the report, callback, or report-repair passes.
- Optional support-doc cleanup remains excluded from the target-only callback by supervisor scope. No A-agent action is required for B002's target-only callback.

## Confidence

- Recommendation confidence: high for `88/90`, unchanged owner/emitter, generated-output correction, and target-specific MCP evidence.
- C++/no-code confidence: medium-high. The evidence is strong that blank-C++ rationale should change, but a formal body should not be inserted without a dedicated exact-body pass because the function is large and has nonuniform path semantics.
- Remaining uncertainty: exact original callback typedef/function spelling and final human-written line-rasterizer source shape.

## Validator Results

- Report-only pass: no validators were run by B002, as required.
- Implementation callback scoped validator:
  - Command: `python .\tools\validator.py --mode file --file by-memory/0x004bb9b0-0x004bc08a.SoftwareRenderCompatLineCallback.md --apply --queue-timeout 240 --wait-generated`
  - `command_id`: `000000007444`
  - `command_timestamp`: `2026-07-05T23:00:41-04:00`
  - Exit code: `0`
  - `ok`: `1`
  - Generated refresh: `completed`; `generated_refresh_command_id: 000000007444`; `generated_refresh_timestamp: 2026-07-05T23:00:41-04:00`
  - Relevant rows: `completion_update 0002PG ... 88`, `confidence_update 0002PG ... 90`, `autogen_cpp_update 0000OC auto-generated/NexusTK/render/Surface.cpp`, `research_tracker_update`, and `memory_auto_coverage_update`.
- Generated freshness proof from callback validation: `auto-generated/NexusTK/render/Surface.cpp` header had `validator-command-id: 000000007444` and `validator-refreshed-at: 2026-07-05T23:00:41-04:00`; UID0002PG line remained `Empty Emitter Marker` at `Completion:88 | Confidence:90`.

## Changed Files

- Manual B002 edits during the implementation callback:
  - `by-memory/0x004bb9b0-0x004bc08a.SoftwareRenderCompatLineCallback.md`
- Manual B002 edit during this report-text repair:
  - editable repair-path artifact `tools/leaser/Agents/Agent-B002/research/0002PG-SoftwareRenderCompatLineCallback-source-quality.md`; executed copies use validator-owned archive path/history as authoritative, and prior execution command `000000007452` plus invalidation command `000000007454` are lifecycle history only.
- Validator-owned side effects from command `000000007444`:
  - `auto-generated/NexusTK/render/Surface.cpp` refreshed; UID0002PG remains an empty marker at `88/90`.
  - `auto-generated/-ag-research-tracker.md` refreshed; UID0002PG row now `88/90`, average `89.0`.
  - `auto-generated/-ag-coverage-report-by-memory.md` refreshed; UID0002PG row now `88%`, `very-strong`, updated `2026-07-05 23:00:42`.
  - `project-level/-auto-completion-stats.md` projected stats updated.
  - `tools/validator.ini` registry rebuilt by validator.
  - `tools/validator_autogen_backup/20260705-230045`, `20260705-230049`, and `20260705-230051` created by validator backup flow.
- B002 did not hand-edit optional support docs, generated files, manual coverage files, validator state, executed archives, lifecycle state, supervisor ledgers, report registry files, or validator-owned lifecycle headers/footers.
- Existing unrelated dirty/generated workspace state was not reverted.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Use project-level `ntk-b-agent-workflow` and updated B002 goal.
- [x] Confirm target UID/path/report path.
- [x] Read target page and then-current support docs as leads.
- [x] Use B002 IDA MCP evidence; pause fallback-only path was not needed because MCP was available.
- [x] Check generated output read-only for UID0002PG freshness/staleness during the B002 evidence pass.
- [x] Research callback typedef, receiver fields, endpoint/delta semantics, source placement, owner/emitter route, split/range, table/no-direct-caller evidence, and first-draft C++ readiness.
- [x] Include required report sections and `Claim And Incorporation Ledger`.
- [x] Do not edit by-* docs, generated files, coverage files, validator state, or lifecycle state.
- [x] Do not run validators, execute_report, lifecycle/archive commands, manual report moves, or archive moves.

Implementation callback items applied after supervisor acceptance:
- [x] Lease `by-memory/0x004bb9b0-0x004bc08a.SoftwareRenderCompatLineCallback.md` only immediately before editing. Proof: lease command returned `Success`.
- [x] Apply target metadata recommendation: `COMPLETION:88`, `CONFIDENCE:90`; preserve owner/emitter/reconstructable/blank emitter position. Proof: target header and validator `completion_update` / `confidence_update`.
- [x] Add B002 MCP evidence at report-level detail, including command IDs or equivalent timestamped provenance. Proof: target `IDA MCP Evidence`, `Touched State`, and `Changes` sections carry `supervisor_recovery_20260705`, range/xref/byte/profile/ABI facts.
- [x] Replace stale generated-owner wording with validator command `000000007444` Surface empty-marker / historical Ranking pollution wording. Proof: target `Status`, `Ownership Notes`, `Changes`, and generated `Surface.cpp:356`.
- [x] Document callback ABI as `GrafPort *` receiver in `ecx`, signed `deltaX/deltaY` stack args, unused IDA `edx` artifact, and `retn 8`. Proof: target `IDA MCP Evidence` and `Touched State`.
- [x] Document accepted field names and LineClipPoint endpoint shape. Proof: target `Touched State` records current cursor, draw state, surface context, and `LineClipPoint` `y, x`.
- [x] Keep formal C++ blank unless supervisor explicitly requests a complete formal body; if blank, replace stale C++ blockers with the target-specific branch-level no-code proof. Proof: target C++ block remains blank; `Reconstruction Notes` carries branch-level proof.
- [x] Preserve range/split decisions and rejected alternatives. Proof: target `Address Range`, `IDA MCP Evidence`, `Ownership Notes`, `Reconstruction Notes`, and `Changes`.
- [x] Do not edit optional support docs unless supervisor explicitly expands callback scope. Proof: callback scope excluded support docs; no support doc edit was made by B002.
- [x] Run scoped file validator with `--apply --queue-timeout 240 --wait-generated`. Proof: command `000000007444`, timestamp `2026-07-05T23:00:41-04:00`, exit `0`, `ok: 1`, generated refresh completed.
- [x] Inspect generated output read-only for UID0002PG freshness if validator runs. Proof: `auto-generated/NexusTK/render/Surface.cpp` header command/timestamp equals validator command and UID0002PG remains an `Empty Emitter Marker` at `88/90`.
- [x] Release target lease after edit/validator batch. Proof: unlease command returned `Success`; current lease report showed no active leases.
- [x] Update this report's ledger/checklist with applied/already-present/excluded states during implementation callback. Proof: Claim And Incorporation Ledger and this checklist updated in the same report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000007446","destination_path":"executed-b-agent-research/B002/0002PG-SoftwareRenderCompatLineCallback-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002PG-SoftwareRenderCompatLineCallback-source-quality.md","timestamp":"2026-07-05T23:06:42-04:00","uid":"0002PG"} -->
<!-- {"agent":"B002","command_id":"000000007448","destination_path":"tools/leaser/Agents/Agent-B002/research/0002PG-SoftwareRenderCompatLineCallback-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B002/0002PG-SoftwareRenderCompatLineCallback-source-quality.md","timestamp":"2026-07-05T23:07:33-04:00","uid":"0002PG"} -->
<!-- {"agent":"B002","command_id":"000000007452","destination_path":"executed-b-agent-research/B002/0002PG-SoftwareRenderCompatLineCallback-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002PG-SoftwareRenderCompatLineCallback-source-quality.md","timestamp":"2026-07-05T23:15:25-04:00","uid":"0002PG"} -->
<!-- {"agent":"B002","command_id":"000000007454","destination_path":"tools/leaser/Agents/Agent-B002/research/0002PG-SoftwareRenderCompatLineCallback-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B002/0002PG-SoftwareRenderCompatLineCallback-source-quality.md","timestamp":"2026-07-05T23:15:51-04:00","uid":"0002PG"} -->
<!-- {"agent":"B002","command_id":"000000007466","destination_path":"executed-b-agent-research/B002/0002PG-SoftwareRenderCompatLineCallback-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0002PG-SoftwareRenderCompatLineCallback-source-quality.md","timestamp":"2026-07-05T23:35:21-04:00","uid":"0002PG"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
