** TARGET-REPORT-UID:0004CY **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0004CY StartupNoticeHitTestButton Source-Quality Research


## Finalized Report / Current Recommendation
- Current recommendation: UID0004CY has been implemented as a source-ready, emitting StartupWindow file-local helper through [UID:0000O5][StartupWindow](by-file/StartupWindow.md), with the target documentation now at `88/92` after incorporating the current MCP-backed evidence.
- Final disposition: source-authored helper; not padding, not a compiler artifact, not a broad aggregate body, and not a no-owner/non-emitting target.
- Applied action: updated the target evidence and metadata, preserved the existing formal `StartupNoticeHitTestButton` C++ body exactly, and refreshed stale parent/source support wording without duplicating the body in support docs.
- Confidence: high for behavior, range, callers, source route, generated output, and final formal code. The cap below 95 is only for exact original source spelling of the helper, `StartupNoticeButton`, field names, and whether the original code spelled the point predicate as a Win32-style `PtInRect` call or a local rectangle helper.

## Supporting Research
- Assignment source: `tools/leaser/Agents/Agent-B007/goal.md`, target UID0004CY, path `by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md`, report path `tools/leaser/Agents/Agent-B007/research/0004CY-StartupNoticeHitTestButton-source-quality.md`.
- Supervisor MCP resume instruction: use restored live MCP, with supervisor-reported active NexusTK session `13191102`; do not produce fallback-only work.
- Current read-only MCP recheck performed by B007: JSON-RPC `initialize` id `1`, `idb_list` id `2`, `server_health` id `3`, `lookup_funcs` id `4`, `analyze_function` id `5`, `decompile` id `6`, `disasm` id `7`, `xrefs_to` id `8`, `callees` id `9`, `get_bytes` id `10`, and helper/WndProc checks ids `11` through `13`.
- Current MCP session details: `idb_list` returned active session `13191102`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_active:true`; `server_health` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.
- Prior reports used as leads only: B008 `0000O5-StartupWindow-empty-emitter-family-source-quality.md` created UID0004CY and inserted the existing helper body; B010 `0001IO-StartupWindowUpdateCheck-source-quality.md` previously identified `0x005817a0-0x005817dd` as the modeled hit-test helper. Current session `13191102` reconfirms the target-specific claims.
- Report lifecycle history: the original report-only pass edited only this report. After supervisor Gate 1 acceptance, B007 applied the authorized implementation callback to the target/support by-* docs, ran only scoped file validators, and did not run `execute_report`, dry-run/probing variants, lifecycle/archive commands, registry commands, manual report moves, generated-file edits, coverage-report edits, validator-state edits, or supervisor-ledger edits. Generated file changes noted below are validator-owned refresh side effects only.

## Target
- Target UID: `0004CY`.
- Target path: `by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md`.
- Source queue/report row observed during callback validation: `auto-generated/-ag-research-tracker.md` row for UID0004CY showed `88/92`, average `90.0`, reconstructable `true`, and report count `0`; report execution/count lifecycle is supervisor-owned state outside this artifact.
- Implementation callback state recorded by this artifact: Gate 1-accepted B-agent implementation callback applied; supervisor execution/lifecycle state is external to this report text.
- Current scores and parent state: target is `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank `EMITTER_POSITION_OPTIONAL`; direct source file [UID:0000O5] is `89/88`, class route [UID:0000DZ] is `88/89`, and parent split/index [UID:0001IO] is non-emitting `88/90`.

## Current Target State
- Existing metadata after callback: `COMPLETION:88`, `CONFIDENCE:92`, owner `0000O5`, reconstructable true, emitter `0000O5`, blank optional emitter position.
- Existing owner/emitter/reconstructable state: correct and preserved. The helper belongs to `StartupWindow.cpp` as a private startup notice UI helper and emits through the file root.
- Existing C++/emitter state after callback: formal C++ is present and preserved exactly. At B007's final generated-output check, `auto-generated/NexusTK/app/StartupWindow.cpp` contained UID0004CY at `Completion:88 | Confidence:92` with the helper body, not an Empty Emitter Marker. B007's initial scoped target validator was command `000000006399`; after repairing one target generated-freshness sentence, B007's final scoped target validator/generated-header observation was command `000000006415`, `validator-refreshed-at: 2026-07-04T18:21:32-04:00`.
- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: no implementation blocker remains. Exact original source spelling for helper/field names and the `PtInRect` source spelling remains inferred and score-capping only.
- Related target/support docs checked: target page, `by-file/StartupWindow.md`, `by-class/StartupWindow.md`, `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`, `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md`, sibling `by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md`, sibling `by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md`, `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`, generated `auto-generated/NexusTK/app/StartupWindow.cpp`, generated memory coverage/tracker rows, and matching B reports.
- Current artifact/lifecycle status: this report records the applied implementation callback and scoped validation results; supervisor execution/archive state is tracked externally by validator history and supervisor audit logs.

## Executive Recommendation
- Best direct owner: [UID:0000O5][StartupWindow](by-file/StartupWindow.md), with [UID:0000DZ][StartupWindow](by-class/StartupWindow.md) as the class route and [UID:0001IO][StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) as the non-emitting executable split/index parent.
- Implemented state: UID0004CY remains assigned, reconstructable, and emitting; metadata is `COMPLETION:88`, `CONFIDENCE:92`; `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, and blank optional emitter position were preserved.
- C++ recommendation: keep the existing formal source body exactly. The body is small, source-like, and matches current MCP behavior: construct a `POINT`, scan two button rectangles, return the first matching index, otherwise return `-1`.
- Condition for remaining uncertainty: only original source/PDB or a project-wide accepted rectangle helper naming policy could raise confidence above the current cap. No current evidence route blocks source emission.

## Supervisor Active Recheck
- The supervisor assigned UID0004CY and later confirmed MCP was restored with active NexusTK session `13191102`; B007 rechecked `idb_list` and `server_health` and used the active session read-only.
- The assigned item did not require split repair before this report. UID0004CY already exists as an exact B008 child and current MCP confirms the range is a real IDA function.
- Every source-bearing item in scope is accounted for: UID0004CY remains the exact source-bearing child for the hit-test helper; WndProc and sibling helpers remain separate children; parent UID0001IO remains a non-emitting split/index.

## Inference Research Guidance Check
- `by-structure.md` IDA MCP Output Discipline was followed: exact-address `lookup_funcs`, targeted `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `callees`, and capped `get_bytes` were used. No broad list/search/callgraph/type/batch-analysis calls were used.
- Existing documentation was treated as a lead. B008/B010 reports and generated C++ predicted the body, but the final recommendation is based on the current session `13191102` binary evidence.
- Direct IDA facts: function start/size/prototype, disassembly, decompile, xrefs, callee, bytes, padding, and helper predicate semantics.
- Documentation evidence: current target/support docs, generated output, coverage/tracker rows, and matching executed B reports.
- Inference: source-facing helper and field names (`StartupNoticeHitTestButton`, `StartupNoticeButton`, `m_buttons`, `rect`, parameter names `x`/`y`) are accepted source-quality names inferred from surrounding StartupWindow source, not recovered original symbols.
- No Wave2/Wave3 material was used as authority. Old reports mentioning earlier sessions are historical leads only.

## Heuristic / Inference Reanalysis And Validation
- Range/source-shape issue: current MCP confirms `sub_5817A0` is a real IDA function at `0x005817a0`, size `0x3d` / 61 bytes, ending in two `retn 8` exits inside the half-open range. It is not padding and not part of adjacent UID0004CX or UID0004CZ.
- Caller/reachability issue: `xrefs_to 0x005817a0` reports exactly three code xrefs, all from WndProc `sub_581100`: `0x0058138c`, `0x00581465`, and `0x00581533`. The WndProc decompile uses the helper for `WM_MOUSEMOVE`, `WM_LBUTTONUP`, and `WM_LBUTTONDOWN` with `LOWORD(lParam)`/`HIWORD(lParam)`.
- Behavior issue: target decompile shows `this`, two explicit integer args, `v3 = 0`, rectangle pointer initialized at `this + 0x20`, loop incrementing by `0x20`, two iterations, and miss return `-1`. Disassembly confirms `lea edi,[ecx+20h]`, `add edi,20h`, `cmp esi,2`, `or eax,0FFFFFFFFh`, and hit return `mov eax,esi`.
- Point predicate issue: the helper calls `sub_4B7E80` once per iteration. Current MCP `analyze_function 0x004b7e80` decompiles it as `left <= x && x < right && top <= y && y < bottom` over the passed rectangle. In the target, the pushed order is y, x, rect, matching the WndProc decompile and the source `POINT`/`PtInRect` shape.
- Field/layout issue: `this+0x20` and `this+0x40` are the two button rectangles. Sibling UID0004CX uses the same `0x20` stride for button state/invalidation, and WndProc draws `startupWindow->m_buttons[index]`, so `m_buttons[index].rect` is a defensible source-facing field name.
- C++ readiness issue: existing formal C++ is source-like and not decompiler-shaped. It uses StartupWindow-local names already accepted by the file/class route and generated source. No unresolved behavior remains that would require leaving the body blank.
- Rejected alternatives: no-code/padding, raw `sub_5817A0` naming, merge into WndProc, merge with UID0004CX/UID0004CW/UID0004CZ, Browser/ImageLoaders/Win32 ownership, RectBounds-helper ownership, class-only emission through UID0000DZ, broad parent UID0001IO emission, and no-owner/non-emitting treatment.
- Remaining caps: exact original symbol spelling for the helper and button fields is inferred; exact original source spelling for the point predicate is inferred from the existing generated/source style; there is no PDB or original source.

## Evidence Standards Used
- IDA MCP evidence used: active IDB/session proof, health state, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `xrefs_to`, `callees`, `get_bytes`, helper predicate analysis, and WndProc decompile snippets.
- Documentation/generated evidence used: current target/support by-* docs, generated `StartupWindow.cpp`, generated memory coverage/tracker rows, and matching executed/active B reports.
- Evidence is strong enough because the target is a short modeled function with exact caller inventory, direct behavior from disassembly/decompile, exact byte/padding boundaries, and an already-emitting formal body whose generated output is current.
- Confidence is capped only by source spelling/type-layout inference, not by behavior, ownership, route, or C++ eligibility.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `idb_list` returned session `13191102` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
  - `server_health` returned `status:ok`, imagebase `0x400000`, Hex-Rays ready, auto-analysis ready, strings cache ready.
  - `lookup_funcs` checked `0x00581724`, `0x00581730`, `0x005817a0`, `0x005817dd`, and `0x005817e0`: UID0004CY is `sub_5817A0`, size `0x3d`; predecessor sibling `0x00581730` is size `0x70`; `0x00581724`, `0x005817dd`, and `0x005817e0` are not function starts.
  - `analyze_function 0x005817a0`: prototype `int __thiscall(_DWORD *this, int, int)`, size `61`, callee `sub_4B7E80`, caller `sub_581100`, three xrefs, five basic blocks, complexity `2`.
  - `decompile 0x005817a0`: loop over `this + 8` DWORDs (byte offset `+0x20`) with `i += 8` DWORDs (byte stride `0x20`), test through `sub_4B7E80(a3, a2, i)`, return index or `-1`.
  - `disasm 0x005817a0`: 32 instructions, `lea edi,[ecx+20h]`, `push edi`, `push ebx`, `push [ebp+arg_4]`, call `sub_4B7E80`, `add edi,20h`, compare index against `2`, miss return `or eax,0FFFFFFFFh`, hit return `mov eax,esi`, both exits `retn 8`.
  - `xrefs_to 0x005817a0`: exactly `0x0058138c`, `0x00581465`, and `0x00581533`, all in `sub_581100`.
  - `callees 0x005817a0`: one internal callee, `sub_4B7E80`.
  - `get_bytes 0x00581724 size 188`: twelve `0xcc` bytes before UID0004CX, UID0004CX bytes through `retn 8`, UID0004CY bytes, then three `0xcc` bytes after UID0004CY before the raw invalidate-all helper.
  - `analyze_function 0x004b7e80`: size `0x27`, bool cdecl point-in-rect predicate over `[left, top, right, bottom)` bounds.
  - `decompile 0x00581100`: WndProc calls UID0004CY in mouse move/up/down paths with `LOWORD(lParam)` and `HIWORD(lParam)`.
- by-* docs, support docs, old reports, generated reports, and trackers checked: target page, `by-file/StartupWindow.md`, `by-class/StartupWindow.md`, parent `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`, WndProc page, sibling helper pages, by-item raw-helper tracker, generated `StartupWindow.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, B008 `0000O5`, B010 `0001IO`, B010 active UID0004CX report, B003 UID0004CW report, and B012 UID0004CU report.
- Negative checks performed: no function at `0x005817dd`, no alternate xrefs outside WndProc for the target start, no target-generated Empty Emitter Marker, and no evidence that Browser/ImageLoaders/Win32/RectBounds helper pages own this helper.
- Failed, unavailable, or intentionally skipped checks and why: no MCP process-management or IDA session-management commands were run. No broad unbounded search/callgraph/type scan was used because exact-address evidence was sufficient. After supervisor Gate 1 acceptance, B007 ran only scoped file validators for the changed by-* docs; results are recorded below.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0004CY-01 | Current MCP evidence uses supervisor-restored active NexusTK session `13191102` with server health `status:ok`, Hex-Rays ready, imagebase `0x400000`, and strings cache ready. | High | MCP ids `2` and `3`. | Target `Evidence`; parent/file/class change notes. | incorporate | applied - target evidence and all edited support notes cite session `13191102` and health/provenance where relevant. |
| C-0004CY-02 | UID0004CY is a real IDA function `sub_5817A0` at `0x005817a0`, size `0x3d` / 61 bytes, with half-open range `0x005817a0-0x005817dd`. | High | `lookup_funcs`, `analyze_function`, `disasm`, target bytes. | Target `Status` / `Evidence`; parent covered row. | incorporate | applied - target status/evidence and parent UID0004CY row now record the exact range and size. |
| C-0004CY-03 | Boundary bytes prove twelve `0xcc` bytes before sibling UID0004CX and three `0xcc` bytes after UID0004CY before UID0004CZ/raw invalidate helper; target is not padding. | High | `get_bytes 0x00581724 size 188`; `lookup_funcs 0x005817dd` not function. | Target `Boundary` / `Evidence`; parent split row. | incorporate | applied - target evidence records begin/end bytes and post-padding; parent support row preserves split/padding context. |
| C-0004CY-04 | The helper scans exactly two button rectangles at `this + 0x20` and `this + 0x40`, using `0x20` stride, returning index `0`/`1` on hit and `-1` on miss. | High | Decompile/disasm of `0x005817a0`; sibling UID0004CX stride evidence; WndProc generated source. | Target `Evidence`; target formal C++ block; support notes. | incorporate | applied - target evidence and support docs record the two `0x20`-stride button rectangles and return behavior; formal C++ was preserved exactly. |
| C-0004CY-05 | The caller inventory is exactly three WndProc code refs at `0x0058138c`, `0x00581465`, and `0x00581533`; they correspond to mouse move, button up, and button down paths passing `LOWORD(lParam)`/`HIWORD(lParam)`. | High | `xrefs_to 0x005817a0`; WndProc decompile snippets; generated WndProc output. | Target `Evidence`; parent/file/class notes; WndProc doc review. | incorporate | applied - target and edited support docs record all three callers and LOWORD/HIWORD argument order; WndProc doc already had matching calls and was not edited. |
| C-0004CY-06 | The only target callee is shared point-in-rect helper `sub_4B7E80`; current MCP confirms half-open rectangle semantics and supports source `PtInRect(&rect, point)` behavior. | High for behavior; medium-high for exact source spelling | `callees 0x005817a0`; `analyze_function 0x004b7e80`; generated source convention. | Target `Evidence`; C++ rationale; open questions. | incorporate | applied - target evidence records sole callee and half-open semantics; C++ rationale preserves `PtInRect` as accepted source spelling with confidence cap. |
| C-0004CY-07 | Owner/emitter remain `StartupWindow.cpp` [UID:0000O5]; class [UID:0000DZ] is a route marker and parent [UID:0001IO] is a non-emitting split/index. | High | Target metadata; by-file/class/parent docs; generated output. | Target metadata; support docs. | preserve/sync | applied - target owner/emitter/reconstructable fields were preserved; parent/file/class support docs were synced while parent metadata stayed non-emitting. |
| C-0004CY-08 | Existing formal C++ body is source-ready and should be preserved exactly; it is not a decompiler-shaped `sub_5817A0` body. | High | Formal target block; MCP decompile/disasm; generated output lines 345-354 after refresh. | Target `RECONSTRUCTION_CPP CODE`. | preserve | applied - target formal block was left unchanged and generated output still contains the helper body. |
| C-0004CY-09 | Generated `StartupWindow.cpp` contains UID0004CY body and no Empty Emitter Marker; after callback its UID line reflects `88/92`. Callback-time tracker observation showed report count `0`, with execution/count lifecycle external to this artifact. | High | B007 target validators `000000006399`, `000000006413`, and final `000000006415`; B007 final generated-header observation `000000006415` / `2026-07-04T18:21:32-04:00`; generated rows. | Target generated-state note; validation results. | incorporate | applied - generated file showed UID0004CY `Completion:88 | Confidence:92` and the body remained present at B007's final check. |
| C-0004CY-10 | Reject no-code/padding, raw-helper no-route, Browser/ImageLoaders/Win32/helper ownership, class-only emission, broad parent emission, and sibling merge alternatives. | High | Current MCP range/callers/callee/body; support docs; generated route. | Target negative evidence; support notes. | incorporate | applied - target negative evidence and support docs preserve the rejected alternatives. |
| C-0004CY-11 | Implemented metadata after callback is `COMPLETION:88`, `CONFIDENCE:92`, with owner/emitter/reconstructable unchanged. | High | Full evidence pass, score cap analysis, target validator `000000006399`. | Target metadata; generated UID line after validation. | incorporate | applied - target metadata and generated UID line now show `88/92`; owner/emitter/reconstructable/optional position are unchanged. |

## Positive Evidence Summary
- Direct facts supporting the chosen recommendation: real IDA function at target start, exact 61-byte range, three direct WndProc callers, one point-in-rect callee, exact two-button loop, clear return semantics, and generated output already containing the helper.
- Corroborating documentation/generated-report evidence: B008 created UID0004CY as a source-bearing child; B010 identified the same modeled hit-test helper; parent/file/class docs route exact children through StartupWindow; generated `StartupWindow.cpp` contains UID0004CY code at lines 344-354.
- Strongest inference chain: WndProc obtains mouse coordinates from `lParam`, calls UID0004CY, branches on hit/miss for cursor, press, release, and state-reset behavior; UID0004CY scans the same two `m_buttons` entries used by draw/set/invalidate helpers; therefore the source-facing helper body is safe and should remain in StartupWindow.cpp.

## IDA MCP Facts
- Function/range facts: `sub_5817A0`, start `0x005817a0`, size `0x3d`, prototype `int __thiscall(_DWORD *this, int, int)`, five basic blocks, complexity `2`.
- Data/table/padding facts: target begins with `55 8b ec 53 8b 5d 08 56 57 33 f6 8d 79 20`; it ends with `5f 8b c6 5e 5b 5d c2 08 00`; post-target bytes `0x005817dd-0x005817e0` are `cc cc cc`.
- Xref facts: `xrefs_to 0x005817a0` returned `0x0058138c`, `0x00581465`, `0x00581533`, all code refs inside WndProc `sub_581100`.
- Vtable/global/type facts: no vtable or global ownership evidence is needed for this helper; ownership is from file/class route and WndProc callers. `sub_4B7E80` is a shared rectangle predicate, not a target owner.
- Negative IDA facts: no function at `0x005817dd`; no extra xrefs outside WndProc; no evidence for padding/no-code or no-owner treatment.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00581724-0x00581730` | ignored padding | reset-to-set alignment | false | [UID:0001IO] | not scored here | Twelve `0xcc` bytes before UID0004CX. |
| `0x00581730-0x005817a0` | [UID:0004CX](by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md) | Set one button state and invalidate changed rectangle | TRUE | [UID:0000O5] | current `86/88` | Separate sibling; do not merge into UID0004CY. |
| `0x005817a0-0x005817dd` | [UID:0004CY](by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md) | Hit-test two notice button rectangles | TRUE | [UID:0000O5] | current `88/92` | Assigned target; formal C++ already present and source-ready. |
| `0x005817dd-0x005817e0` | ignored padding | hit-test-to-invalidate alignment | false | [UID:0001IO] | not scored here | Three `0xcc` bytes; no child required. |
| `0x005817e0-0x00581854` | [UID:0004CZ](by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md) | Invalidate both notice buttons | TRUE | [UID:0000O5] | current `86/88` | Separate raw child; no merge with hit-test. |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0058138c -> 0x005817a0` | WndProc `WM_MOUSEMOVE` path | Hit-tests mouse point, then resets states, sets pressed/hover state, and updates cursor/link behavior. |
| `0x00581465 -> 0x005817a0` | WndProc `WM_LBUTTONDOWN` path | Hit-tests mouse point; if button is hit, sets pressed state before checking top link rectangle. |
| `0x00581533 -> 0x005817a0` | WndProc `WM_LBUTTONUP` path | Hit-tests release point; if hit, posts update/close result, then resets button states. |
| `0x005817b5 -> 0x004b7e80` | Target callee | Shared point-in-rect predicate over the current button rectangle. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: target already says source-authored hit-test helper; by-file and by-class StartupWindow docs route exact helper children through UID0000O5; parent UID0001IO row says UID0004CY scans two button rectangles and returns index or `-1`; WndProc formal C++ already calls `StartupNoticeHitTestButton` in three mouse paths.
- Existing docs that are stale, incomplete, or contradicted: the accepted target/support staleness was repaired during callback. No current core ownership contradiction remains. WndProc support already contained the matching calls and was not edited.
- Generated/coverage report state observed during callback validation: `auto-generated/-ag-memory-coverage.md` listed UID0004CY as `coded`, owner/emitter `0000O5`, output `auto-generated/NexusTK/app/StartupWindow.cpp`; research tracker showed `88/92`, average `90.0`, reconstructable `true`, and report count `0`. Supervisor execution/count lifecycle is external to this callback artifact.

## Ranked Ownership Analysis

### 1. StartupWindow.cpp [UID:0000O5]
- Evidence for: direct WndProc callers; source-file route already owns StartupWindow constructor, WndProc, button helpers, notice asset helpers, and generated output; helper operates on `StartupWindow *` state and the same two notice button entries used by sibling helpers.
- Evidence against: exact original helper and field names are inferred rather than symbol-proven.
- Decision: keep as canonical owner and emitter. This is the only strong source placement.

### 2. StartupWindow class route [UID:0000DZ]
- Evidence for: helper takes the StartupWindow receiver in `ecx`, and class docs own the instance layout/state summary.
- Evidence against: current project route uses class page as a marker plus `[[CHILDREN]]`; exact helper bodies emit from by-memory children through the file root, not duplicated on the class page.
- Decision: support/index only, not a separate emitter or replacement owner.

### 3. Parent split/index [UID:0001IO]
- Evidence for: physical containing executable neighborhood and canonical range inventory.
- Evidence against: parent is deliberately non-emitting after exact child split; emitting a broad aggregate would duplicate child bodies.
- Decision: support parent only; keep UID0001IO non-emitting.

### 4. Browser, ImageLoaders, Win32/API, RectBounds helper, sibling helper, or no-owner alternatives
- Evidence for: Browser/ImageLoaders/Win32/rectangle helpers are dependencies/consumers in the notice UI path; UID0004CY calls a rectangle predicate.
- Evidence against: none owns the StartupWindow receiver or button array. Sibling helpers have separate ranges and call roles. No-owner/non-emitting contradicts direct callers, generated code, and owner route.
- Decision: reject.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new file. Continue using `NexusTK/app/StartupWindow.cpp`.
- Likely full contents: already represented by StartupWindow file/class/child pages.
- Candidate related items that belong: exact StartupWindow helper children remain in UID0000O5 route.
- Candidate related items rejected: no standalone `StartupNotice.cpp` split for this one helper and no merge into a generic geometry helper source.
- Standalone, narrow, or broad source-file inference: narrow file-local helper under existing StartupWindow module.

## Source Placement
- Recommended source file/class/global/module placement: file-local static helper in `NexusTK/app/StartupWindow.cpp`.
- Why this placement fits source-tree and subsystem context: the helper is private to the startup notice WndProc and operates on StartupWindow notice button state. The generated file already places the WndProc and helper bodies together, which is plausible mid-2000s Win32 UI source shape.
- Rejected placements and why: not Browser because it only hosts news content; not ImageLoaders because it only supplies PCX loading; not Win32/API because APIs are callees/dependencies; not class-page-only because project route emits exact bodies through the file; not parent aggregate because UID0001IO is a split/index.
- Remaining placement uncertainty: exact original static/helper spelling remains inferred, but it does not affect owner/emitter placement.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: `lookup_funcs` reports `sub_5817A0` at `0x005817a0`, size `0x3d`; disasm has two `retn 8` exits at `0x005817d1` and `0x005817da`; the final ret operand bytes are inside the function; `0x005817dd-0x005817e0` is three `0xcc` bytes.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: no new child needed. Keep UID0004CY exact. Keep `0x005817dd-0x005817e0` ignored/padding. Do not merge UID0004CX, UID0004CY, or UID0004CZ.
- Padding/table/data/code distinctions: target bytes are executable code; post-target bytes are alignment. No table/data subrange is present.
- Parent/container impact: UID0001IO remains a non-emitting split/index; only its child row/evidence may need support sync after target score/evidence update.

## Negative Evidence Summary
- No-code/padding rejected: target has IDA function object, decompiles cleanly, has WndProc xrefs, and generated source output.
- Raw no-route rejected: unlike nearby raw helpers, UID0004CY has three direct WndProc callers.
- Browser/ImageLoaders ownership rejected: they are dependencies/adjacent subsystems, not callers/owners of the StartupWindow button array.
- Win32/API or RectBounds-helper ownership rejected: the target consumes point-in-rect logic but owns StartupWindow button iteration. The shared helper `sub_4B7E80` has many callers and is not specific to this UI helper.
- Broad parent emission rejected: parent UID0001IO intentionally stays non-emitting after exact child creation.
- Sibling merge rejected: UID0004CX mutates state, UID0004CW resets states, UID0004CZ invalidates buttons, while UID0004CY only tests rectangles and returns an index.
- Raw/decompiler naming rejected: source should not expose `sub_5817A0`, `_DWORD *this`, or decompiler locals.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments: no IDA DB edits requested. For documentation/source output, keep `StartupNoticeHitTestButton`, `StartupWindow *startupWindow`, `int x`, `int y`, `StartupNoticeButton`, `m_buttons`, and `rect` as accepted source-facing names.
- Evidence for each proposed name/type/comment: WndProc caller use, sibling helper names, B008 accepted source route, current generated code, and current MCP layout/stride proof.
- Items intentionally left unchanged and why: leave IDA name `sub_5817A0` untouched; B agents do not rename IDA functions in this workflow, and documentation/generator names are sufficient.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. The target already has formal C++ and current MCP confirms it is source-ready.
- Preserved code: this exact formal target block text is present in the target. It is formal `RECONSTRUCTION_CPP CODE` insertion text, not a report-only body snippet.

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static int StartupNoticeHitTestButton(StartupWindow *startupWindow, int x, int y)
{
    POINT point = { x, y };
    for (int index = 0; index < 2; ++index) {
        if (PtInRect(&startupWindow->m_buttons[index].rect, point)) {
            return index;
        }
    }
    return -1;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior: it tests the two rectangles in order, uses lower-inclusive/upper-exclusive point-in-rect semantics through the accepted source predicate, returns the hit index immediately, and returns `-1` after two misses.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: a file-local `static int` helper beside a Win32 WndProc is natural for this small startup notice UI path; it avoids decompiler labels and exposes readable button/point logic.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `StartupNoticeHitTestButton` for `sub_5817A0`; `StartupWindow *startupWindow` for `ecx`; `x`/`y` for explicit args; `m_buttons[index].rect` for `this+0x20 + index*0x20`.
- Naming/coding style convention used and evidence for consistency: matches current `StartupWindow.cpp` generated output and neighboring helpers `StartupNoticeSetButtonState`, `StartupNoticeResetButtonStates`, and `StartupNoticeInvalidateButtons`.
- Reason code should remain blank, if applicable: not applicable.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation
- Exact changes applied: updated target UID0004CY metadata to `COMPLETION:88`, `CONFIDENCE:92`; kept owner, reconstructable state, emitter, and optional emitter position as-is; incorporated current MCP session `13191102` facts, exact bytes/padding, caller/callee inventory, generated output state, and rejected alternatives.
- Exact parent assignments applied: kept [UID:0000O5] as canonical owner/emitter; kept [UID:0000DZ] as class route/support; kept [UID:0001IO] as non-emitting split/index parent.
- Exact items left no-owner/non-emitting and why: none for UID0004CY. Adjacent ignored padding `0x005817dd-0x005817e0` remains non-reconstructable alignment; parent UID0001IO remains non-emitting to avoid broad duplicate source.
- Exact future work, if any, outside this assignment scope: no required target blocker remains. Original-source/PDB recovery or a project-wide geometry-helper naming pass could further refine exact names, but did not block this target's metadata/evidence upgrade.

## Recommended Target Doc Changes
- Target path: `by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md`.
- Exact report facts incorporated: current MCP session `13191102` health/provenance; `sub_5817A0` size `0x3d`; exact `0x005817a0-0x005817dd` range; target bytes beginning `55 8b ec 53 8b 5d 08 56 57 33 f6 8d 79 20` and ending `5f 8b c6 5e 5b 5d c2 08 00`; three `0xcc` post-padding bytes; WndProc callers `0x0058138c`, `0x00581465`, `0x00581533`; callee `sub_4B7E80`; two `0x20`-stride button rectangles at `this+0x20` and `this+0x40`; WndProc `LOWORD/HIWORD(lParam)` argument order; generated output header and UID body presence.
- Metadata/score/owner/emitter/reconstructable/C++ changes applied: set `COMPLETION:88`, `CONFIDENCE:92`; kept `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, and blank `EMITTER_POSITION_OPTIONAL`; preserved exact formal C++ block.
- Historical/stale assumptions, rejected alternatives, and negative evidence preserved: B008/B010 historical reports are leads; current evidence is session `13191102`; rejected no-code/padding, raw no-route, generic `sub_5817A0`, Browser/ImageLoaders/Win32/helper ownership, class-only route, broad parent emission, and sibling merge.

## Recommended Support Doc Changes
- Support path: `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`.
- Exact report facts incorporated: UID0004CY child row/support text records current `13191102` evidence, `0x3d` size, three WndProc callers, `sub_4B7E80` predicate, two `0x20`-stride button rectangles, and source-ready `88/92` status; parent metadata and non-emitting split/index status remained unchanged.
- Metadata/link/score/coverage/source-placement changes: no parent metadata change applied.

- Support path: `by-file/StartupWindow.md`.
- Exact report facts incorporated: added a UID0004CY source-quality note that the hit-test child is a source-ready `StartupWindow.cpp` emitter with current `13191102` evidence and generated output presence. File metadata remained unchanged.
- Metadata/link/score/coverage/source-placement changes: no file score/path/owner change applied.

- Support path: `by-class/StartupWindow.md`.
- Exact report facts incorporated: clarified that the state access/helper span includes UID0004CY as an exact source-ready hit-test child; class route marker policy was preserved and no duplicate method body was added.
- Metadata/link/score/coverage/source-placement changes: no class metadata change applied.

- Support path: `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md`.
- Exact report facts incorporated: no edit needed. Current WndProc formal C++ and evidence already call UID0004CY in the three mouse paths; this item is `already-present`.
- Metadata/link/score/coverage/source-placement changes: none applied.

## Score And Metadata Recommendation
- Historical pre-callback score/metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank optional emitter position.
- Implemented score/metadata: `COMPLETION:88`, `CONFIDENCE:92`; owner/reconstructable/emitter/optional position unchanged.
- Score rationale and reason not higher/lower: completion rises because current target-level evidence now covers range, bytes, padding, callers, callee semantics, generated state, ownership alternatives, and formal C++ readiness. Confidence rises because behavior and route are fully MCP-backed. Completion stays below 90 because the exact original source names for helper/button fields and project geometry helper spelling remain inferred rather than symbol-proven. Confidence stays below 95 for the same source-spelling/type-layout caveat.
- Score-improvement attempt: each blocker was researched. Range/padding was resolved by lookup/disasm/bytes. Caller route was resolved by xrefs and WndProc decompile. C++ body was rechecked against decompile/disasm and generated output. Ownership alternatives were rejected from caller/state route. The only remaining caps require unavailable original symbols/source or a separate project-wide naming policy, not target-specific investigation.
- Metadata fields changed or left unchanged: changed only completion/confidence. Left owner/emitter/reconstructable/optional position unchanged.

## Open Questions With Attempted Resolution
- Open question: is `StartupNoticeHitTestButton` the original helper name? Evidence checked: B008 accepted source family, generated output, sibling helper names, WndProc source shape, and current MCP. Resolution: keep the name as best source-facing inferred name; original spelling unproven and caps score only.
- Open question: are `m_buttons` and `rect` exact original field names? Evidence checked: target `this+0x20`/`0x40` use, sibling set/invalidate/draw helper docs, generated output. Resolution: keep accepted descriptive names; exact original spelling unproven and caps score only.
- Open question: should source call `PtInRect` or an internal `PointInRect` wrapper? Evidence checked: binary callee `sub_4B7E80`, generated StartupWindow source, WndProc link-rectangle code using `PtInRect`, and helper decompile. Resolution: preserve existing formal `PtInRect` source shape as accepted project/source style; document that binary semantics are the shared half-open point predicate.
- Open question: should the helper be absorbed into WndProc for source style? Evidence checked: three direct calls and separate IDA function object. Resolution: no; keep file-local helper.
- Questions remaining unresolved: only exact original-source spelling. It does not block metadata upgrade or formal C++.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. No manual generated tracker or coverage report edit was performed. Scoped validators refreshed generated coverage/tracker state from by-* metadata; supervisor execution remains an external lifecycle action.

## Follow-Up Actions
- Supervisor actions: supervisor owns any final execution/archive lifecycle action for this implemented report artifact.
- A-agent actions: none.
- B007 future research actions: none for UID0004CY unless supervisor asks for a callback or a later geometry-helper naming pass.

## Confidence
- Recommendation confidence: high.
- Score confidence: high for `88/92`.
- Remaining uncertainty: exact original helper/field/source predicate spelling only; behavior, route, range, and emitted code are stable.

## Validator Results
- Command: `python .\tools\validator.py --mode file --file by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md --apply --queue-timeout 240 --wait-generated`.
- Result: command_id `000000006399`, command_timestamp `2026-07-04T18:13:16-04:00`, exit code `0`, `ok: 1`. Side effects included `completion_update 0004CY ... 88`, `confidence_update 0004CY ... 92`, target link-label refreshes, validator-owned generated C++ refresh for by-file UID0000O5, research tracker update, memory coverage update, projected stats update, registry rebuild, and validator backups. Warnings were existing project-wide autogen children/emitter diagnostics; no target-specific error remained. `generated_refresh: completed`.
- Command: `python .\tools\validator.py --mode file --file by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md --apply --queue-timeout 240`.
- Result: command_id `000000006400`, command_timestamp `2026-07-04T18:13:34-04:00`, exit code `0`, `ok: 1`; projected stats update, `stats_incremental_noop 0001IO`; `generated_refresh: deferred`; no target-specific errors.
- Command: `python .\tools\validator.py --mode file --file by-file/StartupWindow.md --apply --queue-timeout 240`.
- Result: command_id `000000006401`, command_timestamp `2026-07-04T18:13:40-04:00`, exit code `0`, `ok: 1`; projected stats update, `stats_incremental_noop 0000O5`; `generated_refresh: deferred`; no target-specific errors.
- Command: `python .\tools\validator.py --mode file --file by-class/StartupWindow.md --apply --queue-timeout 240`.
- Result: command_id `000000006402`, command_timestamp `2026-07-04T18:13:50-04:00`, exit code `0`, `ok: 1`; `reference_index_add 0004CY by-class/StartupWindow.md by-class/StartupWindow.md`, projected stats update, `stats_incremental_noop 0000DZ`; `generated_refresh: deferred`; no target-specific errors.
- Command: `python .\tools\validator.py --mode file --file by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md --apply --queue-timeout 240 --wait-generated`.
- Result: command_id `000000006413`, command_timestamp `2026-07-04T18:20:56-04:00`, exit code `0`, `ok: 1`; final target generated-freshness repair check. Warnings were existing project-wide autogen children/emitter diagnostics; no target-specific error remained. `generated_refresh: completed`.
- Command: `python .\tools\validator.py --mode file --file by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md --apply --queue-timeout 240 --wait-generated`.
- Result: command_id `000000006415`, command_timestamp `2026-07-04T18:21:32-04:00`, exit code `0`, `ok: 1`; final target validator after removing future-stale exact generated-header wording from target evidence. Warnings were existing project-wide autogen children/emitter diagnostics; no target-specific error remained. `generated_refresh: completed`.
- Generated freshness observation: B007's final scoped validator was command `000000006415`. At B007's final check, `auto-generated/NexusTK/app/StartupWindow.cpp` header recorded `validator-command-id: 000000006415`, `validator-refreshed-at: 2026-07-04T18:21:32-04:00`, `validator-refresh-source: foreground-generated-refresh`; UID0004CY was present at `Completion:88 | Confidence:92` with the helper body and no Empty Emitter Marker.
- Lease status: B007 leased the target, parent, file, and class docs immediately before editing and released all four after initial validation; B007 leased the target once more for the generated-freshness wording repair and released it after command `000000006415`. `tools/leaser/Agents/current_leases.md` currently shows no B007 leases.

## Changed Files
- Created during initial report-only pass: `tools/leaser/Agents/Agent-B007/research/0004CY-StartupNoticeHitTestButton-source-quality.md`.
- Modified by B007 during implementation callback: `by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md`, `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`, `by-file/StartupWindow.md`, `by-class/StartupWindow.md`, and this report.
- Inspected but not edited: `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md`; it already contained the matching UID0004CY calls and had no direct contradiction.
- Validator-owned generated/derived side effects observed: `auto-generated/NexusTK/app/StartupWindow.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, projected stats, reference index, and validator backups/registry rebuilds were refreshed by scoped validators. B007 did not manually edit generated files, project-level generated files, coverage reports, validator state, lifecycle/archive files, or supervisor ledgers.
- Renamed: none.
- Report execution: not run. B007 did not run `execute_report`, dry-run/probing variants, lifecycle/archive commands, registry commands, manual report moves, generated-file edits, coverage-report edits, validator-state edits, or supervisor-ledger edits.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation: Gate 1 passed for SHA256 `3843BB1EE70DC979CD8C1C8A10DA6D6E0EEE45DE0C2781DE8911751CB3F9CC00`, enabling this callback.
- [x] Target/support docs to update: target, parent, by-file, and by-class docs were edited; WndProc doc was inspected and marked already-present.
- [x] Current target state and actual evidence checked recorded: session `13191102`, server health, range/size/prototype, bytes/padding, callers, callee, generated output, and tracker rows are recorded.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: rows C-0004CY-01 through C-0004CY-11 now end as `applied`.
- [x] Metadata/score changes to apply: target set to `COMPLETION:88`, `CONFIDENCE:92`; no support metadata change applied.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof: all target blockers resolved; exact original spelling/type caps remain documented and non-blocking.
- [x] Owner/emitter/reconstructable changes to apply: no change; preserved `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank `EMITTER_POSITION_OPTIONAL`.
- [x] Split/rename/new-child changes to apply: none; UID0004CY exact child remains; adjacent padding ignored and parent UID0001IO non-emitting.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: range/padding evidence incorporated; no IDA DB rename/type/comment edits requested.
- [x] First-draft C++ or no-code proof to apply: exact formal `StartupNoticeHitTestButton` C++ block was preserved in the target.
- [x] Third-party import directive to apply or confirm not applicable: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail: session `13191102`; `sub_5817A0` size `0x3d`; callers `0x0058138c`, `0x00581465`, `0x00581533`; `sub_4B7E80` point predicate; two `0x20`-stride rectangles; bytes/padding; generated output state.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: B008/B010 historical evidence retained as lead material; no-code/padding, raw/no-route, Browser/ImageLoaders/Win32/helper ownership, class-only route, broad parent emission, and sibling merge rejected.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: no Wave2/Wave3 evidence used.
- [x] Open questions to close or document as evidence-backed unresolved: exact original helper/field/source predicate spelling remains inferred and score-capping only.
- [x] Validators to run: scoped file validators completed for all four changed by-* docs.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: validator-owned generated refresh now shows UID0004CY score line `88/92` and the same body; no manual tracker text was edited.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator; B007 final generated-header observation `000000006415` contained UID0004CY `88/92` body.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000006430","destination_path":"executed-b-agent-research/B007/0004CY-StartupNoticeHitTestButton-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0004CY-StartupNoticeHitTestButton-source-quality.md","timestamp":"2026-07-04T18:26:02-04:00","uid":"0004CY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
