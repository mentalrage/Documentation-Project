** TARGET-REPORT-UID:0004CW **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0004CW StartupNoticeResetButtonStates Source-Quality Research


## Finalized Report / Current Recommendation
- Current recommendation: implemented during the 2026-07-04 callback; [UID:0004CW] `by-memory/0x00581670-0x00581724.StartupNoticeResetButtonStates.md` now records `COMPLETION:89`, `CONFIDENCE:92`.
- Final disposition: keep `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`, and the existing source-like helper C++ unchanged.
- Required action: no remaining B003 implementation action. Supervisor Gate 2/execution remains supervisor-owned. B003 incorporated current MCP-backed function, caller, byte, padding, sibling, generated-output, and stale-report-count evidence at report-level detail without creating new children, moving owner/emitter routing, or replacing this helper with a no-code marker.
- Confidence: high for exact range, body behavior, two WndProc callers, boundary padding, source-file route, and generated output. Confidence remains capped below final because exact original helper spelling, `StartupNoticeButton`/member names, and the formal `void` declaration versus IDA's non-semantic `BOOL` guess are inferred source-facing names rather than symbol-proof.

## Supporting Research
- Lifecycle/status notes: initial report-only assignment for Agent-B003 / UID0004CW completed without by-* edits. After supervisor Gate 1 passed, B003 completed the implementation callback on 2026-07-04 by editing only the accepted target/support by-* docs under short leases, running scoped validators, releasing leases, and updating this report. No generated files, coverage reports, validator state, supervisor ledgers, lifecycle/archive files, report moves, or manual generated files were edited by hand. No `execute_report`, dry-run/probe, registry lifecycle, archive, or report-move command was run.
- Current MCP evidence uses session `nexustk_supervisor_20260704`. `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `callees`, `xrefs_to`, `xref_query`, `get_bytes`, `make_signature_for_range`, `search_text`, and `int_convert` were used in narrow bounded calls.
- Older reports were treated as leads and rechecked against current docs and MCP before this conclusion.

## Target
- Target UID: `0004CW`.
- Target path: `by-memory/0x00581670-0x00581724.StartupNoticeResetButtonStates.md`.
- Source queue/report row: assignment-time row in `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable` showed `86/88`, reconstructable true, reports column blank/zero for this UID-specific report path. B003 did not manually edit the generated tracker.
- Current supervisor classification: reconstructable by-memory source-bearing helper under `StartupWindow.cpp`.
- Current scores and parent state: target `89/92`; canonical owner/emitter [UID:0000O5] `by-file/StartupWindow.md`; parent [UID:0001IO] `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md` is a non-emitting split/index page that includes UID0004CW as an exact child.

## Current Target State
- Pre-callback metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`.
- Current metadata after callback: `COMPLETION:89`, `CONFIDENCE:92`; owner/emitter/reconstructable/optional-position/`Nested` fields unchanged.
- Owner/emitter/reconstructable state: correct. The helper belongs to the `StartupWindow.cpp` source route, not to the broad aggregate as a direct emitter.
- C++/emitter state: current formal C++ remains a good source-like helper:
  - iterates two notice buttons;
  - clears `button.state` only when positive;
  - invalidates the corresponding button rectangle with `FALSE` erase;
  - uses file-local `static void StartupNoticeResetButtonStates(StartupWindow *startupWindow)`.
- Pre-callback open questions/blockers: target prose was too thin for the source-quality queue because it lacked current MCP session evidence, exact xrefs/caller contexts, byte/signature/padding proof, field-offset proof, generated freshness, sibling comparison, and direct explanation that B008/B010 were family/parent reports rather than a UID0004CW-specific report. The callback added these facts to the target and stale support pages.
- Related target/support docs checked: `by-file/StartupWindow.md`, `by-class/StartupWindow.md`, `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`, `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md`, `by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md`, `by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md`, `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`, generated `auto-generated/NexusTK/app/StartupWindow.cpp`, generated research tracker, and matching B reports.
- Current artifact/lifecycle status: implementation-callback-updated artifact in `tools/leaser/Agents/Agent-B003/research/0004CW-StartupNoticeResetButtonStates-source-quality.md`; B003 stopped before supervisor-owned report execution.

## Executive Recommendation
- Best disposition: keep UID0004CW as a source-bearing file-local `StartupWindow.cpp` helper named `StartupNoticeResetButtonStates`.
- Metadata: raise target to `COMPLETION:89`, `CONFIDENCE:92`; keep owner/emitter/reconstructable fields unchanged.
- C++: keep or refresh the current formal C++ block exactly. Current MCP proves it matches the source behavior better than the IDA decompiler's `BOOL __thiscall` prototype because callers ignore the return value and the no-change path leaves no meaningful source return.
- Exact condition for higher confidence later: original symbols, source, or an accepted class-layout/type report would need to prove the exact original helper declaration spelling, `StartupNoticeButton` layout/member names, and `StartupWindow` field names. Current binary evidence is already sufficient for first-draft source C++ and a score increase.

## Supervisor Active Recheck
- The current assignment specifically asked why UID0004CW still has no direct B report despite already having `86/88`, owner/emitter [UID:0000O5] `StartupWindow`, and formal helper C++.
- Recheck result: no direct UID0004CW report artifact was found. Current B-agent research hits are sibling reports B012 UID0004CU and B013 UID0004CV. Executed report hits are B008 UID0000O5 family split and B010 UID0001IO parent aggregate split.
- Required split repair is already done from the B008 callback: UID0004CW exists as an exact child page and emits through UID0000O5. This report does not need to create, split, merge, or move ranges.

## Inference Research Guidance Check
- IDA facts are separated from documentation evidence and source-facing inference. Current MCP controls exact function, range, bytes, xrefs, and body behavior; existing docs and generated C++ are support evidence; names and field spellings remain inference.
- Existing documentation assumptions treated as uncertain: the target page's short evidence line was treated as insufficient, and the decompiler's `BOOL` return type was treated as a type guess rather than a source declaration.
- Wave2/Wave3 artifacts: no current Wave2/Wave3 source authority was used. Older StartupWindow split history was used only when corroborated by current docs/MCP.

## Heuristic / Inference Reanalysis And Validation
- Function/range: MCP `lookup_funcs` confirms `0x00581670` is `sub_581670`, size `0xb4` / 180 bytes, while `0x00581664`, `0x00581724`, `0x005815b0`, and `0x005817e0` are not function starts. The half-open target range remains exact.
- Body shape: MCP `disasm` shows a security-cookie frame, local `RECT`, two repeated button-state tests, SSE copies of `RECT` fields, two conditional calls to `InvalidateRect`, and a single `retn` at `0x00581723`.
- Field semantics: the function checks and clears state fields at `this+0x30` and `this+0x50`; copies rectangles from `this+0x20` and `this+0x40`; and passes the notice `HWND` at `this+0x0c` to `InvalidateRect`.
- Caller set: `xrefs_to` and `search_text` show exactly two code refs to the helper start, both in WndProc `sub_581100`: `0x005813c6` and `0x005814fd`.
- Caller contexts: MCP decompile of WndProc shows `0x005813c6` in `WM_MOUSEMOVE` after `StartupNoticeHitTestButton`; the helper resets states when the cursor is outside both buttons. It shows `0x005814fd` in `WM_LBUTTONUP` after optional `StartupNoticePostButtonResult`, resetting transient visual state before returning `1`.
- Return type: IDA currently decompiles the helper as `BOOL __thiscall sub_581670(int this)` because `InvalidateRect` returns `BOOL`. The call sites do not consume a return value, and paths with no dirty button do not produce a meaningful source result. The existing `static void` source declaration is therefore the safer source-facing reconstruction.
- Sibling comparison: UID0004CX `StartupNoticeSetButtonState` handles indexed one-button state assignment and invalidation; UID0004CY hit-tests; UID0004CW is the bulk reset helper. It should not be merged with either sibling.
- Generated state: before callback, `auto-generated/NexusTK/app/StartupWindow.cpp` emitted UID0004CW under validator command `000000006343`, refreshed `2026-07-04T13:36:35-04:00`. After scoped validation, read-only generated header inspection shows command `000000006394`, refreshed `2026-07-04T18:03:36-04:00`, and UID0004CW emitted at `89/92` with the same source-like helper body.
- Direct-report gap: B008 created/validated UID0004CW as part of the UID0000O5 family split, and B010 recommended it as a child of UID0001IO. Neither is a UID0004CW-targeted B report, so the tracker still has no direct UID0004CW report count.
- Rejected alternatives: no-code/padding treatment, raw `sub_581670` naming, broad parent aggregate emission, class-only emission through UID0000DZ, Browser/ImageLoaders/Win32 ownership, and merging with UID0004CX/UID0004CY are all contradicted by current MCP and current docs.

## Evidence Standards Used
- MCP evidence: session/health, exact function lookup, decompile/disassembly, xrefs, cross-reference query, callees, bytes, signature generation, text search, and integer conversion.
- Documentation evidence: target/support by-* docs, generated `StartupWindow.cpp`, generated research tracker, executed B008/B010 reports, and current sibling B012/B013 reports.
- Evidence ladder: current IDA MCP facts override older report text and generated output when there is conflict. Generated output is used as current emitter/freshness evidence, not as sole behavioral proof.
- Evidence strength: strong enough for exact range, source placement, generated route, caller set, C++ body, and score improvement. Remaining uncertainty is limited to original source spelling and formal local type/member names.

## Evidence Checked
- IDA MCP checks performed:
  - `idb_list`: one active worker session `nexustk_supervisor_20260704` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, worker PID `10024`.
  - `server_health`: `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
  - `lookup_funcs`: `0x00581670` -> `sub_581670`, size `0xb4`; successor `0x00581730` -> `sub_581730`, size `0x70`; WndProc `0x00581100` -> `sub_581100`, size `0x4aa`; `0x00581664`, `0x00581724`, `0x005815b0`, and `0x005817e0` are not functions.
  - `analyze_function 0x00581670`: size 180, decompiled helper body, callers `sub_581100`, callees `InvalidateRect` and `@__security_check_cookie@4`, five basic blocks, cyclomatic complexity `3`.
  - `disasm 0x00581670`: 51 instructions; function starts `push ebp` at `0x00581670` and ends `retn` at `0x00581723`.
  - `xrefs_to 0x00581670`: exactly `0x005813c6` and `0x005814fd`, both in `sub_581100`; `xrefs_to 0x00581724`: zero.
  - `get_bytes`: `0x00581664-0x00581670` twelve `0xcc` bytes; target starts `55 8B EC 83 EC 14 ...`; target tail includes `... 8B E5 5D C3`; `0x00581724-0x00581730` twelve `0xcc` bytes.
  - `make_signature_for_range 0x00581670-0x00581724`: exact signature generated and reported `unique:true`.
  - `search_text` within `0x00581100-0x005815aa`: two `call sub_581670` hits at `0x005813c6` and `0x005814fd`.
  - `int_convert`: `0xb4` = 180, `0x4aa` = 1194, `0xc` = 12, `0x20` = 32, `0x30` = 48, `0x40` = 64, `0x50` = 80.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - Target `by-memory/0x00581670-0x00581724.StartupNoticeResetButtonStates.md`.
  - `by-file/StartupWindow.md`, `by-class/StartupWindow.md`, [UID:0001IO] split index, WndProc child, sibling set/hit-test docs, raw-helper tracker.
  - `auto-generated/NexusTK/app/StartupWindow.cpp`, `auto-generated/-ag-research-tracker.md`.
  - Current B012/B013 sibling reports; executed B008 UID0000O5 family report; executed B010 UID0001IO aggregate report.
- Negative checks performed: direct report search for `0004CW`, `0x00581670`, `StartupNoticeResetButtonStates`, and `sub_581670`; no UID0004CW-specific report found. MCP found no xrefs to the end boundary and no functions at padding/sibling boundary addresses.
- Failed, unavailable, or intentionally skipped checks: no MCP endpoint failure occurred. A local PowerShell wrapper parameter-name collision occurred before useful MCP calls and was corrected; this was not an MCP failure. No validators were run during the initial report-only pass; callback scoped validators are recorded in `Validator Results`.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0004CW-001 | UID0004CW is an exact modeled function at `0x00581670-0x00581724`, size `0xb4` / 180 bytes. | High | MCP `lookup_funcs`, `analyze_function`, `disasm`, `int_convert`. | Target `Status` / `Evidence`. | incorporate | applied - target Evidence records exact range/size; validator `000000006387` exit `0`, `ok:1`. |
| C-0004CW-002 | Boundary padding is exact: twelve `0xcc` bytes before at `0x00581664-0x00581670` and twelve `0xcc` bytes after at `0x00581724-0x00581730`; `0x00581724` is not a function and has zero xrefs. | High | MCP `get_bytes`, `lookup_funcs`, `xrefs_to`, `xref_query`. | Target `Evidence`; parent split row. | incorporate | applied - target Evidence and parent covered row/evidence now carry padding/end-xref proof; validators `000000006387` and `000000006395` passed. |
| C-0004CW-003 | The body clears nonzero notice-button state fields at `this+0x30` and `this+0x50`, copies rects from `this+0x20` and `this+0x40`, and invalidates `this+0x0c` HWND. | High | MCP `decompile`/`disasm`; WndProc/generated context. | Target `Evidence`; optional support notes. | incorporate | applied - target, class, and parent evidence now record the two button rect/state roles and notice `HWND`; validators `000000006387`, `000000006394`, `000000006395` passed. |
| C-0004CW-004 | Direct caller set is exactly two calls from StartupWindow WndProc `sub_581100`: `0x005813c6` and `0x005814fd`. | High | MCP `xrefs_to`, `search_text`, WndProc `decompile`. | Target `Evidence`; WndProc support note. | incorporate | applied - target and WndProc support evidence record both exact call sites; validators `000000006387` and `000000006388` passed. |
| C-0004CW-005 | The two caller contexts are mouse-move reset on hit-test miss and mouse-button-up cleanup after optional result post. | High | MCP WndProc `decompile` around `WM_MOUSEMOVE`/`WM_LBUTTONUP`; generated C++. | Target `Evidence`; WndProc support note. | incorporate | applied - target and WndProc Evidence record the `WM_MOUSEMOVE` and `WM_LBUTTONUP` contexts; validators `000000006387` and `000000006388` passed. |
| C-0004CW-006 | Existing formal C++ is source-ready and should remain `static void StartupNoticeResetButtonStates(StartupWindow *startupWindow)` with the two-button loop. | High | MCP body behavior, ignored return at call sites, generated C++. | Target `RECONSTRUCTION_CPP CODE`. | keep/refresh | applied - target formal block was preserved exactly and validator `000000006387` passed. |
| C-0004CW-007 | Owner/emitter route through [UID:0000O5] `StartupWindow.cpp` is correct; broad parent [UID:0001IO] remains a non-emitting split/index. | High | by-file/class/parent docs, B008 executed report, generated output, current xrefs. | Target metadata; support docs if stale. | keep/incorporate | applied/already-present - target metadata preserved `0000O5`/`TRUE`/`0000O5`, class and parent refreshed, and by-file route was already present in exact child list. |
| C-0004CW-008 | B008 and B010 are valid leads but do not satisfy the direct UID0004CW report gap; tracker still lacks a UID0004CW-specific report artifact. | High | Report searches; B008/B010 opened; tracker row. | Target `Changes`/`Evidence`; report history note. | incorporate | applied - target Evidence/Changes now record B008/B010 as history/leads and B003 as the direct report gap closure; validator `000000006387` passed. |
| C-0004CW-009 | Rejected alternatives: padding/no-code, raw `sub_` naming, Browser/ImageLoaders/Win32 ownership, class-only routing, parent aggregate emission, and merge with UID0004CX/UID0004CY. | High | MCP range/callers/body; support docs; source-route docs. | Target negative evidence; support docs if stale. | incorporate | applied - target Evidence now preserves all rejected alternatives and class/parent support preserve exact-child route; validators passed. |
| C-0004CW-010 | Score should become `COMPLETION:89`, `CONFIDENCE:92`, not higher due inferred exact names/types/member spellings. | Medium-high | Current MCP facts plus source-name confidence caps. | Target metadata and score rationale. | incorporate | applied - target metadata set to `89/92`; validator `000000006387` reported `completion_update` and `confidence_update`. |
| C-0004CW-011 | Generated output currently emits the helper under `auto-generated/NexusTK/app/StartupWindow.cpp`, command `000000006343`, refreshed `2026-07-04T13:36:35-04:00`. | High | Read-only generated file inspection. | Target/support generated freshness note. | incorporate | applied - target records pre-callback freshness; post-validation generated header refreshed to command `000000006394`, `2026-07-04T18:03:36-04:00`. |
| C-0004CW-012 | No manual coverage/tracker edit is recommended; validator-owned generated tracker/report rows should refresh only through scoped validation after accepted by-* edits. | High | Workflow boundary and generated tracker role. | Report checklist / callback scope. | not-applicable | excluded-with-reason - no manual generated, coverage, tracker, lifecycle, or validator-state edits were made; only scoped file validators updated generated/projected stats as tool side effects. |

## Positive Evidence Summary
- Direct facts supporting recommendation:
  - Real modeled IDA function at the exact half-open range with unique byte signature.
  - Exact direct xrefs from WndProc only.
  - Body semantics match current formal source: two button records, clear positive state, invalidate changed rectangles.
  - Generated `StartupWindow.cpp` already emits the helper through UID0000O5.
- Corroborating documentation/generated-report evidence:
  - B008 executed report created/validated UID0004CW as one exact StartupWindow child.
  - B010 parent aggregate report independently identified this child range and WndProc rel32 refs.
  - Current by-file/class/parent docs all place UID0004CW in the StartupWindow notice helper family.
- Strongest inference chain: current MCP function facts plus two WndProc callers plus generated source route prove the target is not blocked for C++; remaining work is documentation specificity and score correction.

## IDA MCP Facts
- Function/range facts: `0x00581670` -> `sub_581670`, size `0xb4` / 180; instruction count `51`; basic blocks `5`; cyclomatic complexity `3`; return at `0x00581723`.
- Data/table/padding facts: `0x00581664-0x00581670` and `0x00581724-0x00581730` are `0xcc` padding; exact target signature is unique.
- Xref facts: two incoming code refs to function start from `sub_581100`; zero xrefs to `0x00581724`; outgoing refs are local flow plus external `InvalidateRect` and internal `@__security_check_cookie@4`.
- Vtable/global/type facts: no vtable slot is involved. The `StartupWindow` WndProc uses the singleton at `unk_69BAC8` to get the receiver and calls the helper with that receiver.
- Negative IDA facts: end/padding addresses are not functions; no separate xref route proves Browser/ImageLoaders/Win32/helper-class ownership; IDA's decompiler return type is not a reliable source declaration.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00581660-0x00581664` | UID0004CV `by-memory/0x00581660-0x00581664.StartupWindowGetInstanceHandle.md` | class accessor sibling | `TRUE` | `0000DZ` / emitter `0000O5` | `86/88` current | Current sibling report recommends evidence/score update. |
| `0x00581664-0x00581670` | ignored padding | alignment | no source | parent split [UID:0001IO] | n/a | Twelve `0xcc` bytes. |
| `0x00581670-0x00581724` | UID0004CW target | file-local button-state reset helper | `TRUE` | `0000O5` | `89/92` current | Source-ready C++ remains. |
| `0x00581724-0x00581730` | ignored padding | alignment | no source | parent split [UID:0001IO] | n/a | Twelve `0xcc` bytes; zero xrefs to start. |
| `0x00581730-0x005817a0` | UID0004CX `by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md` | one-button state setter sibling | `TRUE` | `0000O5` | `88/91` current | Separate indexed setter; do not merge into UID0004CW. |
| `0x005817a0-0x005817dd` | UID0004CY `by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md` | hit-test sibling | `TRUE` | `0000O5` | `86/88` current | WndProc hit-test feeder; do not merge into UID0004CW. |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x005813c6` | `call sub_581670` from `sub_581100` WndProc | `WM_MOUSEMOVE`: after hit-test, reset both button states when `button > 1` / miss. |
| `0x005814fd` | `call sub_581670` from `sub_581100` WndProc | `WM_LBUTTONUP`: after optional `StartupNoticePostButtonResult`, reset transient visual states. |
| `0x005816c6` | call `InvalidateRect` | Invalidate first/start button rect when state at `+0x30` was positive. |
| `0x0058170f` | call `InvalidateRect` | Invalidate second/exit button rect when state at `+0x50` was positive. |
| `0x0058171b` | call `@__security_check_cookie@4` | Compiler stack-cookie epilogue, not source helper logic. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - `by-file/StartupWindow.md` lists UID0004CW among exact source-bearing child pages emitted through `NexusTK/app/StartupWindow.cpp`.
  - `by-class/StartupWindow.md` describes the `0x00581670` notice button helper tie to WndProc.
  - [UID:0001IO] split/index row lists the exact range and says the helper clears nonzero start/exit visual-state slots and invalidates changed rectangles.
  - WndProc child source and generated `StartupWindow.cpp` both call `StartupNoticeResetButtonStates` in the same two contexts found by MCP.
- Existing docs that were stale, incomplete, or contradicted before callback:
  - Target evidence was accurate but too terse and lacked current session evidence, exact xrefs, boundary bytes, sibling distinction, and score rationale. The callback updated the target.
  - Class and parent split docs lacked direct UID0004CW current-session detail. The callback updated those support docs.
- Generated/coverage report state:
  - Generated `StartupWindow.cpp` header after callback: `validator-command-id: 000000006394`, `validator-refreshed-at: 2026-07-04T18:03:36-04:00`.
  - Generated source currently emits UID0004CW at `89/92` with the same helper body.
  - No manual coverage/tracker text was recommended or edited.

## Ranked Ownership Analysis

### 1. [UID:0000O5] `StartupWindow.cpp`
- Evidence for: generated source file route; WndProc caller; StartupWindow singleton receiver; sibling notice helpers; existing by-file and B008 family split.
- Evidence against: exact helper name and local struct/member spellings are inferred, not symbol-proof.
- Decision: keep as canonical owner and emitter route. This is the best and current accepted placement.

### 2. [UID:0000DZ] `StartupWindow` class
- Evidence for: helper uses `StartupWindow` instance fields and could have been a private static/member helper in source.
- Evidence against: existing project split treats file-local notice helpers as [UID:0000O5] and class methods/accessors as [UID:0000DZ]. The function has no vtable/class-method dispatch and is called as a file-local helper from WndProc.
- Decision: reject as canonical owner for UID0004CW; keep as contextual class/type support only.

### 3. [UID:0001IO] `StartupWindowUpdateCheck` aggregate
- Evidence for: physical parent range covers this child.
- Evidence against: it is a non-emitting split/index container over many child bodies, padding, raw helpers, callback/string helpers, and destructor variants. Broad aggregate emission would duplicate exact children.
- Decision: reject direct ownership/emission. It remains parent inventory support.

### 4. Browser, ImageLoaders, Win32/API, UID0004CX/UID0004CY, or no owner
- Evidence for: helper calls Win32 `InvalidateRect`; nearby StartupWindow code hosts Browser/image assets; sibling helpers share button-state fields.
- Evidence against: dependencies and siblings do not own the helper. Current direct callers are WndProc only; body state is StartupWindow notice button state; xrefs and generated route do not leave ownership unresolved.
- Decision: reject.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new source file. Existing `NexusTK/app/StartupWindow.cpp` is sufficient.
- Likely full contents: no change to source grouping; UID0004CW remains with the existing StartupWindow notice helper family.
- Candidate related items that belong: UID0004CU through UID0004D2 remain neighboring notice helper children.
- Candidate related items rejected: no separate `StartupNotice.cpp` split for this one helper; no merge with UID0004CX/UID0004CY; no broad parent body.
- Standalone, narrow, or broad source-file inference: narrow file-local helper inside existing StartupWindow source file.

## Source Placement
- Recommended source file/class/global/module placement: `NexusTK/app/StartupWindow.cpp`, file-local helper `static void StartupNoticeResetButtonStates(StartupWindow *startupWindow)`.
- Why this placement fits source-tree and subsystem context: WndProc and notice button helpers are file-local StartupWindow notice UI code; all data flow uses StartupWindow notice fields; the generated file already emits this helper under UID0000O5.
- Rejected placements and why: class-owned method lacks dispatch/declaration proof; [UID:0001IO] aggregate would duplicate exact children; Browser/ImageLoaders/Win32 are dependencies or hosted components; no-owner/non-emitting would discard a real modeled function with callers and source C++.
- Remaining placement uncertainty: exact original helper spelling and whether the original declaration returned `void` or an unused `BOOL` cannot be symbol-proven now. Current source convention favors `void`.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: target remains `0x00581670-0x00581724`, size `0xb4` / 180 bytes; predecessor padding is `0x00581664-0x00581670`; successor padding is `0x00581724-0x00581730`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: no new children; no merge. The existing child split is already correct.
- Padding/table/data/code distinctions: UID0004CW is code. The two adjacent twelve-byte `0xcc` spans are alignment padding and should stay in the parent split/index or ignored coverage, not in UID0004CW source.
- Parent/container impact: [UID:0001IO] remains a non-emitting split/index. Callback may update its UID0004CW row/evidence if current-session detail is absent, but should preserve parent non-emitting metadata and blank aggregate C++.

## Negative Evidence Summary
- `0x00581724` is not a function and has zero xrefs; do not extend the child into padding.
- `0x00581664` is not a function and has zero xrefs; do not merge predecessor padding or accessor boundary into UID0004CW.
- Raw `sub_581670` is an IDA name, not a source name.
- The helper is not padding/no-code because IDA models a function, the body has real callers, and generated output already emits it.
- The helper is not owned by Browser, ImageLoaders, Win32/API, or sibling button helper pages; those are dependencies, hosted components, or adjacent helpers.
- The helper should not be emitted from the broad [UID:0001IO] aggregate because exact child emission already exists and the parent is a split/index.
- The helper should not be folded into UID0004CX or UID0004CY because UID0004CW resets both states, UID0004CX sets one indexed state, and UID0004CY hit-tests.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments:
  - Keep `StartupNoticeResetButtonStates` as the source-facing helper name because direct WndProc contexts and body semantics reset notice button visual states.
  - Keep `StartupWindow *startupWindow` as the parameter because callers pass the StartupWindow singleton receiver from WndProc.
  - Keep `StartupNoticeButton`, `m_buttons`, `state`, `rect`, and `m_noticeWindow` in formal C++ as current project-stable source-facing layout names.
  - Add/keep prose comments only in docs, not source C++: "clears positive visual-state slots for both notice buttons and invalidates changed rectangles."
- Evidence for each proposed name/type/comment:
  - Offsets `+0x20/+0x30` and `+0x40/+0x50` prove two button records with rectangle plus state fields.
  - WndProc and generated source already use hit-test/set-state/reset helper naming consistently.
  - `InvalidateRect(HWND, RECT*, FALSE)` proves the `m_noticeWindow` and `rect` roles.
- Items intentionally left unchanged and why:
  - Do not rename IDA `sub_581670` in the IDB during this pass; DB edits are not requested.
  - Do not encode raw `_DWORD *`, `__m128i`, `this + 48`, `this + 80`, or `BOOL __thiscall` into formal source; those are decompiler artifacts or lower-level facts.
  - Do not invent original-proof names for `StartupNoticeButton` members beyond the current source-facing names.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested. Documentation/source-facing names are sufficient for this B-agent report.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. The existing formal helper C++ is source-ready and should be kept/refreshed exactly.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` header/block insertion text:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void StartupNoticeResetButtonStates(StartupWindow *startupWindow)
{
    for (int index = 0; index < 2; ++index) {
        StartupNoticeButton &button = startupWindow->m_buttons[index];
        if (button.state > 0) {
            button.state = 0;
            InvalidateRect(startupWindow->m_noticeWindow, &button.rect, FALSE);
        }
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior: the loop covers the two button records proven at offsets `+0x20/+0x30` and `+0x40/+0x50`; it only clears positive states; it invalidates the corresponding rectangle with `bErase` false; callers ignore any return value.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: a small file-local static helper avoids duplicating the reset logic in WndProc and matches the existing helper family naming style.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `StartupWindow`, `StartupNoticeButton`, `m_buttons`, `m_noticeWindow`, `state`, `rect`, and `index`.
- Naming/coding style convention used and evidence for consistency: matches current generated `StartupWindow.cpp` and neighboring helper names `StartupNoticeSetButtonState` and `StartupNoticeHitTestButton`.
- Reason code should remain blank, if applicable: not applicable.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation
- Exact changes recommended:
  - Target metadata: set `COMPLETION:89`, `CONFIDENCE:92`.
  - Target metadata unchanged: `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`.
  - Formal C++: keep/refresh exact block above.
  - Evidence: add current MCP session `nexustk_supervisor_20260704`, exact range/size, body semantics, caller set/context, byte/signature/padding proof, sibling distinction, generated freshness, and rejected alternatives.
- Exact parent assignments recommended: none.
- Exact items left no-owner/non-emitting and why: no change. Parent [UID:0001IO] and tracker [UID:0000VI] remain non-emitting containers/trackers because exact source-bearing child pages emit the code.
- Exact future work outside this assignment scope: a later type-layout/source-symbol pass could prove final original field/helper names, but no current evidence route blocks the recommended target update.

## Recommended Target Doc Changes
- Target path: `by-memory/0x00581670-0x00581724.StartupNoticeResetButtonStates.md`.
- Exact report facts to incorporate:
  - MCP session `nexustk_supervisor_20260704`, active IDB health and Hex-Rays readiness.
  - `lookup_funcs 0x00581670`: `sub_581670`, size `0xb4` / 180 bytes.
  - Exact function body facts: `+0x30` and `+0x50` states; `+0x20` and `+0x40` rectangles; `+0x0c` notice `HWND`; `InvalidateRect(..., FALSE)` calls; stack-cookie callee.
  - Exact xrefs/callers: `0x005813c6` and `0x005814fd`, both in WndProc `0x00581100`; describe mouse-move and mouse-button-up contexts.
  - Boundary bytes: twelve `0xcc` bytes before and after; no function/xrefs at `0x00581724`; successor UID0004CX at `0x00581730`.
  - Signature: full-range signature generated by MCP and reported unique.
  - Generated output: current generated `StartupWindow.cpp` command `000000006343`, refreshed `2026-07-04T13:36:35-04:00`, already emits helper body.
  - Direct-report gap: B008/B010 were family/parent leads, not a direct UID0004CW report.
  - Negative evidence and confidence caps.
- Metadata/score/owner/emitter/reconstructable/C++ changes: set `89/92`; keep owner/emitter/reconstructable/blank optional position; keep exact formal C++.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: B008 creation history, B010 parent split lead, no broad parent emission, no raw IDA names in source-facing prose, and no no-code/padding treatment.

## Recommended Support Doc Changes
- `by-class/StartupWindow.md`:
  - Update UID0004CW note/evidence if stale to include current MCP `0x00581670-0x00581724`, size `0xb4` / 180, two WndProc callers, state/rect offsets, and source-ready helper status.
  - Preserve class metadata unless the support doc itself has a stale score blocker; no score change is required by this report.
- `by-file/StartupWindow.md`:
  - Mark already-present if it already lists UID0004CW as an exact child emitting through `NexusTK/app/StartupWindow.cpp`.
  - Otherwise add/update source-output note that UID0004CW emits through UID0000O5 and is not owned/emitted by the broad parent.
- `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`:
  - Update the UID0004CW split/index row/evidence if stale with current session facts, exact xrefs, padding, and sibling separation.
  - Preserve parent `RECONSTRUCTABLE:FALSE`, blank emitter, and blank aggregate C++.
- `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md`:
  - Review only; edit if it lacks or contradicts the two reset-helper call contexts. Formal WndProc C++ already includes the calls.
- Sibling docs `by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md` and `by-memory/0x005817a0-0x005817dd.StartupNoticeHitTestButton.md`:
  - Review only if support prose is stale or merges roles with UID0004CW. Otherwise mark already-present/excluded-with-reason in the callback ledger.
- No manual `-coverage-report.md`, generated tracker, or generated source edits are recommended.

## Score And Metadata Recommendation
- Current score/metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank optional emitter position.
- Recommended score/metadata: `COMPLETION:89`, `CONFIDENCE:92`, owner/emitter/reconstructable unchanged.
- Score rationale and reason not higher/lower:
  - Raise completion because a UID-specific report now supplies current MCP evidence, caller contexts, byte/signature/padding proof, sibling distinction, generated freshness, and exact implementation guidance.
  - Raise confidence because IDA models the function, exact xrefs exist, signature is unique, and generated output already emits the correct helper.
  - Do not raise to final/near-final because original source names/types/member spellings remain inferred, and IDA's `BOOL` prototype must be documented as a decompiler artifact rather than source proof.
- Score-improvement attempt:
  - Modeled function/range boundary checked: resolved.
  - Caller set from WndProc checked: resolved.
  - Parent/family report gap checked: resolved as history/tracker artifact, not a blocker.
  - Button-state field semantics checked: resolved at offset level.
  - Invalidation behavior checked: resolved.
  - Helper naming/source shape checked: best current source-facing name retained with confidence cap.
  - Owner/emitter route checked: unchanged and supported.
  - Formal C++ disposition checked: keep existing source-ready block.
- Metadata fields to change or leave unchanged: change only completion/confidence.

## Open Questions With Attempted Resolution
- Exact original helper spelling:
  - Evidence checked: current docs, generated output, B008/B010, MCP names, caller contexts.
  - Best supported resolution: keep `StartupNoticeResetButtonStates` as project-stable source-facing name.
  - Remaining uncertainty: no PDB/source proof; caps confidence only.
- Exact formal return type:
  - Evidence checked: MCP decompile and disassembly, WndProc call sites, generated C++.
  - Best supported resolution: keep `void`; IDA's `BOOL` is an artifact of `InvalidateRect` returns and is not semantically consumed.
  - Remaining uncertainty: original source could have had an unused `BOOL`, but current source shape should not expose an unmeaningful return value.
- Exact field/member names:
  - Evidence checked: offset use, sibling helpers, generated `StartupWindow.cpp`.
  - Best supported resolution: keep `m_buttons`, `StartupNoticeButton`, `state`, `rect`, `m_noticeWindow`.
  - Remaining uncertainty: original spelling not proven; caps score only.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Not applicable. The relevant tracker is `auto-generated/-ag-research-tracker.md`, which must not be manually edited. After accepted by-* edits and scoped validation, generated reports should refresh through validator-owned paths only.

## Follow-Up Actions
- Supervisor actions: perform Gate 2 implementation verification; the supervisor owns any later report execution command after verification.
- A-agent actions: none.
- B003 callback status: accepted details were applied or marked already-present/excluded-with-reason; leases were released; B003 did not run report execution.

## Confidence
- Recommendation confidence: high.
- Score confidence: medium-high; `89/92` is justified by current evidence and capped by source-name/type uncertainty.
- Remaining uncertainty: original helper spelling, struct/member spellings, and exact original declaration return type.

## Validator Results
- Commands run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| File | Command | command_id / timestamp | Exit / ok | Notes |
| --- | --- | --- | --- | --- |
| `by-memory/0x00581670-0x00581724.StartupNoticeResetButtonStates.md` | `python .\tools\validator.py --mode file --file by-memory/0x00581670-0x00581724.StartupNoticeResetButtonStates.md --apply --queue-timeout 240` | `000000006387` / `2026-07-04T17:58:30-04:00` | exit `0`, `ok:1` | Reported `completion_update 0004CW 89`, `confidence_update 0004CW 92`, three `reference_index_add` rows, `projected_stats_update`, and `generated_refresh: deferred`. No warnings/errors. |
| `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md` | `python .\tools\validator.py --mode file --file by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md --apply --queue-timeout 240` | `000000006388` / `2026-07-04T17:58:36-04:00` | exit `0`, `ok:1` | Reported one `reference_index_add`, `projected_stats_update`, and `generated_refresh: deferred`. No warnings/errors. |
| `by-class/StartupWindow.md` | `python .\tools\validator.py --mode file --file by-class/StartupWindow.md --apply --queue-timeout 240` | `000000006394` / `2026-07-04T18:03:36-04:00` | exit `0`, `ok:1` | Reported one `reference_index_add`, `projected_stats_update`, and `generated_refresh: deferred`. No warnings/errors. |
| `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md` | `python .\tools\validator.py --mode file --file by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md --apply --queue-timeout 240` | `000000006395` / `2026-07-04T18:03:42-04:00` | exit `0`, `ok:1` | Reported `projected_stats_update` and `generated_refresh: deferred`. No warnings/errors. |

- Generated refresh/freshness: read-only generated header inspection after validators showed `auto-generated/NexusTK/app/StartupWindow.cpp` at `validator-command-id: 000000006394`, `validator-refreshed-at: 2026-07-04T18:03:36-04:00`, `validator-refresh-source: deferred-generated-refresh`. This is equal to the latest source-emitting class-page validator and newer than target/WndProc validators. It remained older than non-emitting parent validator `000000006395`; the parent split page has blank C++/emitter and did not produce a newer generated source header during the observed deferred refresh.
- Validator side effects: scoped validators updated `project-level/-auto-completion-stats.md` projected path completion sections and reference indexes through validator-owned paths. B003 did not manually edit generated files, project-level generated files, coverage reports, validator state, or generated C++.
- Lease history: first lease attempt succeeded for target and WndProc but found B010 active leases on `by-class/StartupWindow.md` and the parent split page until `2026-07-04T22:02:15Z`; B003 edited/validated target and WndProc, released those leases, waited for B010 leases to expire, then leased/edited/validated class and parent. Final `current_leases.md` check reported no active leases.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B003/research/0004CW-StartupNoticeResetButtonStates-source-quality.md`.
- Modified:
  - `by-memory/0x00581670-0x00581724.StartupNoticeResetButtonStates.md`
  - `by-memory/0x00581100-0x005815aa.StartupWindowUpdateCheckWindowProc.md`
  - `by-class/StartupWindow.md`
  - `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`
  - `tools/leaser/Agents/Agent-B003/research/0004CW-StartupNoticeResetButtonStates-source-quality.md`
- Renamed: none.
- Report execution: not run. B003 did not run `execute_report`, dry-run/probing variants, registry lifecycle commands, manual report moves, or archive commands.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation was required before implementation and was completed before this callback.
- [x] Target/support docs to update identified: target UID0004CW, plus StartupWindow class/file, UID0001IO parent split, WndProc support if stale, and siblings only if stale/contradictory.
- [x] Current target state and actual evidence checked recorded with MCP session `nexustk_supervisor_20260704`.
- [x] Claim And Incorporation Ledger populated with destination and report-only verification state for every accepted claim candidate.
- [x] Metadata/score changes to apply: target `86/88` -> `89/92`; owner/emitter/reconstructable unchanged.
- [x] Score-limiting blockers researched to resolution or confidence cap: direct report gap, range, callers, body, field offsets, invalidation, source placement, generated output, and formal C++ disposition.
- [x] Owner/emitter/reconstructable changes to apply: none; keep `0000O5`, `TRUE`, `0000O5`.
- [x] Split/rename/new-child changes to apply: none; existing split is correct.
- [x] Source-placement, range/split/padding/reclassification, and IDA rename/type/comment recommendations recorded.
- [x] First-draft C++ recommendation supplied as exact formal block; keep existing helper C++.
- [x] Third-party import directive confirmed not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail listed.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Wave2/Wave3 mentions or artifacts not used as current authority.
- [x] Open questions documented as evidence-backed confidence caps.
- [x] Validators to run after callback listed.
- [x] Generated report refresh expectation recorded; no manual supervisor-owned coverage/tracker text recommended.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation in chat; callback implemented from this report and its ledger.
- [x] Lease only files about to be edited and release immediately after edit/validator batch. Proof: target/WndProc leases acquired and released; class/parent leases acquired after B010 expiry and released; final lease report showed no active leases.
- [x] Target metadata set to `COMPLETION:89`, `CONFIDENCE:92`; owner/emitter/reconstructable/optional position preserved. Proof: target validator `000000006387` reported completion/confidence updates and exit `0`.
- [x] Target formal C++ block kept exactly as listed in `First-Draft C++ Recommendation`. Proof: target validator `000000006387` passed and generated source still emits the same helper body.
- [x] Target evidence updated with MCP session, exact range/size, disassembly/body offsets, xrefs/callers, WndProc contexts, bytes/signature/padding, generated freshness, B008/B010 direct-report gap explanation, confidence caps, and rejected alternatives.
- [x] `by-class/StartupWindow.md` updated with direct UID0004CW method/helper detail while preserving class score/route metadata; validator `000000006394` passed.
- [x] `by-file/StartupWindow.md` marked already-present: it already lists UID0004CW as an exact child emitting through [UID:0000O5] into `NexusTK/app/StartupWindow.cpp`; no stale support detail required an edit, and B010's temporary lease was not disturbed.
- [x] `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md` updated with UID0004CW split row/current evidence while preserving non-emitting parent metadata and blank aggregate C++; validator `000000006395` passed.
- [x] WndProc support doc updated with the two reset-helper call sites and contexts; validator `000000006388` passed.
- [x] Sibling support docs reviewed: [UID:0004CX] and [UID:0004CY] do not contradict or merge UID0004CW. UID0004CX was actively updated by B010 and already records separate one-button set-state behavior; UID0004CY remains a distinct hit-test helper. No B003 edit needed.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved in target/support docs: B008/B010 report-history context, no parent aggregate emission, no raw `sub_` source name, no Browser/ImageLoaders/Win32 ownership, no padding/no-code treatment, and inferred-name confidence caps.
- [x] Scoped validators run from `source-3/project-documentation` for every changed by-* file; command IDs/timestamps/exits/ok counts recorded above.
- [x] Generated report refresh checked through validator output and read-only generated header inspection; no manual generated/coverage edit.
- [x] Claim And Incorporation Ledger verification states updated from `proposed` to `applied`, `already-present`, or `excluded-with-reason`.
- [x] Remaining unapplied accepted items listed: none. By-file and siblings were reviewed and intentionally not edited because their accepted facts were already present or not stale.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000006397","destination_path":"executed-b-agent-research/B003/0004CW-StartupNoticeResetButtonStates-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0004CW-StartupNoticeResetButtonStates-source-quality.md","timestamp":"2026-07-04T18:12:34-04:00","uid":"0004CW"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
