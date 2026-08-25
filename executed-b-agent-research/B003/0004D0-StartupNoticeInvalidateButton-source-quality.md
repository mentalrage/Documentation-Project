** TARGET-REPORT-UID:0004D0 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID0004D0 StartupNoticeInvalidateButton Source-Quality Report


## Finalized Report / Current Recommendation

- Implementation callback disposition: accepted UID0004D0 details were incorporated into the target/support by-* docs at report-level detail.
- Final target state after callback: `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank `EMITTER_POSITION_OPTIONAL`, and `Nested:0`.
- Formal C++ disposition: the exact `StartupNoticeInvalidateButton(StartupWindow *startupWindow, int buttonIndex)` helper body was preserved in the target formal block.
- Lifecycle boundary: B003 ran only scoped validators for changed by-* docs, released the edit leases, and did not run `execute_report`, lifecycle/archive commands, registry commands, manual report moves, or manual generated/coverage edits.
- Confidence: high for behavior, range, padding, owner/emitter route, and source-ready formal C++; capped by no IDA function object/direct start route and inferred private helper/member spelling.

## Supporting Research

This report explains why UID0004D0 still appears in `auto-generated/-ag-research-tracker.md` as zero direct reports despite already having a formal source body. The target was created by the B008 StartupWindow split implementation and is already emitted in generated output, but unlike nearby siblings UID0004CW, UID0004CX, UID0004CY, UID0004CZ, UID0004D1, and UID0004D2, it had no dedicated direct B report. The target page therefore has the correct basic metadata and C++ but only a short evidence note.

The current pass uses the restored IDA MCP session `ddf5b602`. A previous attempt on 2026-07-04 paused because the listener was up but `idb_list` returned zero sessions; that historical incident is not used as evidence for this final report. Current session-backed calls succeeded and are the evidence basis below.

Search terms used before finalizing: `0004D0`, `0x00581860`, `0x005818c3`, `StartupNoticeInvalidateButton`, `00581860`, `StartupNotice`, `StartupWindow`, `StartupNoticeInvalidateButtons`, and `StartupNoticeSetButtonState`.

## Target

- Target UID: `0004D0`.
- Target path: `by-memory/0x00581860-0x005818c3.StartupNoticeInvalidateButton.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` -> Not-Covered Files - Reconstructable, row `0004D0`, score `86/88`, reports `0`.
- Current supervisor classification: new report-only B-agent research for a reconstructable by-memory target.
- Current scores and parent state: target is `86/88`, parent/source file [UID:0000O5][StartupWindow](by-file/StartupWindow.md) is `89/88`, class [UID:0000DZ][StartupWindow](by-class/StartupWindow.md) is `88/89`, and parent split/index [UID:0001IO][0x005807d0-0x0058206e.StartupWindowUpdateCheck](by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md) is `88/90` and non-emitting.

## Current Target State

- Existing metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank optional emitter position, `Nested:0`.
- Existing owner/emitter/reconstructable state: direct StartupWindow source-file route through [UID:0000O5][StartupWindow](by-file/StartupWindow.md), with source output in `NexusTK/app/StartupWindow.cpp`.
- Existing C++/emitter state: the target already contains a formal file-local helper body:

```cpp
static void StartupNoticeInvalidateButton(StartupWindow *startupWindow, int buttonIndex)
{
    InvalidateRect(startupWindow->m_noticeWindow, &startupWindow->m_buttons[buttonIndex].rect, FALSE);
}
```

- Existing open questions/blockers: target-local evidence is short and inherited from B008/B010 split work; the page does not yet record current MCP session `ddf5b602`, exact bytes/instructions, unique signature, negative route checks, direct sibling comparison, generated-output status, or score rationale.
- Related docs checked: `by-file/StartupWindow.md`, `by-class/StartupWindow.md`, `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`, `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`, siblings UID0004CZ and UID0004CX, generated `auto-generated/NexusTK/app/StartupWindow.cpp`, `auto-generated/-ag-research-tracker.md`, and executed B reports for StartupWindow/sibling context.
- Current artifact/lifecycle status: this is a new B003 report-only artifact in `tools/leaser/Agents/Agent-B003/research/`; no by-* implementation has been done in this pass.

## Executive Recommendation

UID0004D0 should remain a source-bearing StartupWindow file-local helper emitted through `NexusTK/app/StartupWindow.cpp`. It does not need an ownership change, split, merge, or blank-emitter treatment. The needed repair is evidence depth and score movement: update the target to `88/91`, preserve the formal C++ block, and add current MCP-backed proof for the exact raw body and its negative route caveat.

## Supervisor Active Recheck

The supervisor assignment asks why this target still has no direct B report and what source-quality work is needed. The answer is that UID0004D0 was created by the broader B008 StartupWindow split and already emits formal C++, but it never received the direct per-target evidence refresh that adjacent helper pages now have. No split repair is needed: the accepted half-open range is exact, predecessor/successor padding is confirmed, and the body is independent from UID0004CZ and UID0004D1.

## Inference Research Guidance Check

The current inference discipline supports a best-source-shape recommendation instead of requiring recovered original private symbols. Direct IDA facts prove the raw body, boundaries, field offsets, and Win32 call. Documentation evidence proves the StartupWindow owner/emitter route. Inference supplies the source-facing names `StartupNoticeInvalidateButton`, `startupWindow`, `buttonIndex`, `m_noticeWindow`, and `m_buttons[index].rect`; those names are stable local project names, not recovered original symbols.

No Wave2/Wave3 material was used as authority. Generated output was read only as a freshness/source-route lead and was checked against current MCP bytes/instructions.

## Heuristic / Inference Reanalysis And Validation

The target is a one-button rectangle invalidation helper. Current MCP disassembly shows `ecx` as the receiver, `[ebp+8]` as the button index, `(buttonIndex + 1) << 5` as the selected button slot offset, `[ecx+0x0c]` as the notice HWND, and a copied local RECT passed to `InvalidateRect(..., FALSE)`. The `+1` before shifting is consistent with the documented layout where button zero's rectangle begins at `this+0x20` and button one's rectangle begins at `this+0x40`.

The sibling comparison resolves the source-quality blockers:

- UID0004CX `StartupNoticeSetButtonState` uses `this+0x30 + index*0x20` for state, `this+0x20 + index*0x20` for the rectangle, and `this+0x0c` for the HWND. UID0004D0 uses the same rectangle/HWND path but does not read or write state.
- UID0004CZ `StartupNoticeInvalidateButtons` starts at `this+0x20`, loops twice with `0x20` stride, and invalidates both button rectangles. UID0004D0 is the indexed single-rectangle version of that helper.
- The target's no-direct-start-route status remains real: no IDA function object, decompile failure, no xrefs, and zero code/data/immediate refs to the start or nearby boundary addresses. That caps confidence, but it does not make the code padding or no-owner, because the body has a full prologue/security-cookie frame, side-effecting Win32 call, unique signature, and exact source-route support.

Rejected alternatives: raw `sub_581860` naming, padding/no-code treatment, generic Win32 helper ownership, Browser/ImageLoaders/MiniMapVersionManager/MD5/Application/Config ownership, parent aggregate emission, by-item tracker emission, and merging into UID0004CZ or UID0004D1.

## Evidence Standards Used

Evidence types used:

- IDA MCP session and health proof.
- Exact `lookup_funcs` function/non-function facts.
- Exact raw bytes, bounded instruction query, unique range signature, and decompile/analyze failure.
- Xref and exact `find` negative route checks.
- Sibling helper instruction comparison for field offsets and source shape.
- Existing by-* target/support docs, generated output, generated research tracker, and executed B reports used as leads or documentation evidence.

The evidence is strong enough for source-ready output because the formal C++ already matches the exact side effects and the owner/emitter route is established by support docs and generated output. Confidence remains below final-audit levels because the raw start is not modeled as an IDA function, no direct binary caller/start route is known, and exact original source spelling for the helper and private members is inferred.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `idb_list`: session `ddf5b602`, active worker, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, not analyzing.
  - `server_health(database=ddf5b602)`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.
  - `lookup_funcs` for `0x00581860`, `0x005818c3`, `0x00581854`, `0x005818d0`, `0x005817e0`, `0x00581730`, and `0x00581100`.
  - `get_bytes` for `0x00581854` through the target and successor prologue, plus boundary padding ranges.
  - `insn_query` for `0x00581860-0x005818c3`, `0x00581730-0x005817a0`, and `0x005817e0-0x00581854`.
  - `xrefs_to`, `xref_query`, and exact `find` code/data/immediate checks for `0x00581860`, `0x005818c3`, `0x00581854`, and `0x005818d0`.
  - `decompile` and `analyze_function` at `0x00581860`.
  - `make_signature_for_range 0x00581860-0x005818c3`.
  - `type_query` for `StartupWindow` and `StartupNotice`.
  - `int_convert` for `0x63`, `0x20`, `0x0c`, `0x30`, and related values.
- by-* docs, support docs, old reports, generated reports, and trackers checked:
  - Target and support docs named above.
  - `auto-generated/NexusTK/app/StartupWindow.cpp`.
  - `auto-generated/-ag-research-tracker.md`.
  - `executed-b-agent-research/B008/0004CZ-StartupNoticeInvalidateButtons-source-quality.md`.
  - `executed-b-agent-research/B008/0000O5-StartupWindow-empty-emitter-family-source-quality.md`.
  - `executed-b-agent-research/B010/0001IO-StartupWindowUpdateCheck-source-quality.md`.
  - `executed-b-agent-research/B010/0004CX-StartupNoticeSetButtonState-source-quality.md`.
- Negative checks performed:
  - No function object at target start/end/boundary/successor raw starts.
  - No decompilation and no analyze-function body at target start.
  - No xrefs/code refs/data refs/immediates to target start or boundary addresses queried.
  - No local IDA `StartupWindow` or `StartupNotice` UDT recovered.
- Failed/unavailable/skipped checks:
  - No lifecycle or validator commands were run because this is report-only.
  - No broad full-image MCP searches were run. The exact `find` checks were address-targeted and capped.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-0004D0-001 | UID0004D0 should be rescored from `86/88` to `88/91`. | High | Current MCP session `ddf5b602` proves exact bytes, 30-instruction body, unique range signature, padding, sibling layout, and negative route checks; score remains capped by no function/direct start route. | Target metadata and Score Rationale | incorporate | applied: target metadata now `COMPLETION:88`, `CONFIDENCE:91`; validator `000000006454` confirmed `completion_update 0004D0 ... 88` and `confidence_update 0004D0 ... 91`. |
| C-0004D0-002 | Preserve `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank optional emitter position, and `Nested:0`. | High | by-file/class/parent docs route exact StartupWindow helper children through `StartupWindow.cpp`; generated output already emits UID0004D0 there. | Target metadata | incorporate | applied: target metadata was left unchanged except score; post-validator target still shows owner `0000O5`, reconstructable `TRUE`, emitter `0000O5`, blank optional position, and `Nested:0`. |
| C-0004D0-003 | Preserve the formal `StartupNoticeInvalidateButton(StartupWindow *startupWindow, int buttonIndex)` C++ block. | High | Target C++ matches MCP disassembly: index argument, selected button RECT, notice HWND, `InvalidateRect(..., FALSE)`, and `ret 4`. | Target `RECONSTRUCTION_CPP CODE` | incorporate | applied: target formal block still contains the exact helper body; generated `StartupWindow.cpp` lines for UID0004D0 show the same body with `Completion:88 | Confidence:91`. |
| C-0004D0-004 | Exact range is `0x00581860-0x005818c3`, size `0x63` / 99 bytes. | High | `lookup_funcs` non-function boundary facts, `get_bytes`, `insn_query`, and `int_convert` for `0x63`. | Target Evidence / Boundary And Padding | incorporate | applied: target MCP Evidence, Status, Item Summary, parent split row, file notes, class row, tracker row, and sibling support note now cite exact `0x00581860-0x005818c3` / `0x63` / 99-byte range. |
| C-0004D0-005 | The body has no IDA function object and no Hex-Rays decompilation at `0x00581860`. | High | `lookup_funcs` reports "Not a function"; `decompile` reports failure; `analyze_function` reports no function. | Target Evidence / Confidence cap | incorporate | applied: target MCP Evidence and Rejected Alternatives now record no IDA function object, decompile/analyze failure, and no-function confidence cap; support notes preserve the no-function route. |
| C-0004D0-006 | The target uses `this+0x0c` as notice HWND and `this+0x20 + buttonIndex*0x20` as the selected button RECT. | High | `insn_query`: `(buttonIndex + 1) << 5`, `movups [eax+ecx]`, `push [ecx+0Ch]`; sibling UID0004CX and UID0004CZ confirm offsets/stride. | Target Behavior / Touched State | incorporate | applied: target Behavior and support docs now cite `m_noticeWindow` at `this+0x0c` and indexed `m_buttons[buttonIndex].rect` at `this+0x20 + buttonIndex*0x20`. |
| C-0004D0-007 | The helper invalidates one selected rectangle and does not read or write button-state storage. | High | Target disassembly only copies the RECT and calls `InvalidateRect`; UID0004CX disassembly shows state at `+0x30 + index*0x20` for comparison. | Target Behavior / Sibling Comparison | incorporate | applied: target Behavior and Boundary/Sibling Proof state that UID0004D0 invalidates one selected rectangle and does not touch state storage; support rows preserve the UID0004CX state/UID0004CZ all-buttons distinction. |
| C-0004D0-008 | Boundary padding is `0x00581854-0x00581860` twelve `0xcc` bytes before the target and `0x005818c3-0x005818d0` thirteen `0xcc` bytes after it; successor UID0004D1 starts at `0x005818d0`. | High | `get_bytes` boundary calls and `lookup_funcs` non-function facts. | Target Boundary / Parent split row | incorporate | applied: target Boundary And Sibling Proof and parent covered row/evidence cite twelve-byte predecessor padding, thirteen-byte successor padding, and UID0004D1 successor start at `0x005818d0`. |
| C-0004D0-009 | The full-range signature is unique. | High | `make_signature_for_range` returned a unique IDA-format signature for `0x00581860-0x005818c3`. | Target Evidence / Score rationale | incorporate | applied: target MCP Evidence and Score Rationale cite the unique full-range signature as supporting boundary evidence. |
| C-0004D0-010 | No direct route to the raw start is currently known. | High | `xrefs_to`, `xref_query`, and exact `find` code_ref/data_ref/immediate checks returned zero to `0x00581860`; boundary addresses queried also returned zero. | Target Negative Evidence / Confidence cap | incorporate | applied: target MCP Evidence and Rejected Alternatives preserve zero xref/code/data/immediate direct-route checks and the confidence cap; file/class/parent/tracker support notes preserve no-direct-start wording. |
| C-0004D0-011 | Support docs should record UID0004D0 as source-ready at report-level detail while keeping parent/tracker pages non-emitting. | Medium-high | Support docs list UID0004D0 but lack current direct B003 evidence and score update; parent [UID:0001IO] is already a non-emitting split/index. | by-file, by-class, by-memory parent, by-item tracker | incorporate | applied: updated `by-file/StartupWindow.md`, `by-class/StartupWindow.md`, `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`, `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`; also updated reviewed sibling `by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md` with direct B003 support note. |
| C-0004D0-012 | Reject raw/decompiler naming, padding/no-code, no-owner, broad parent emission, tracker emission, and unrelated owner routes. | High | Direct body side effect plus StartupWindow support route; negative route checks cap confidence but do not refute source presence. | Target/support rejected alternatives | incorporate | applied: target Rejected Alternatives and support notes preserve no raw naming, no padding/no-code, no WndProc/browser/image-loader ownership, no parent/tracker emission, and no no-owner treatment. |

## Positive Evidence Summary

- Direct facts supporting the recommendation:
  - MCP session `ddf5b602` is healthy and IDB-backed.
  - The exact raw body is `0x00581860-0x005818c3`, size `0x63` / 99 bytes (Verified with int_convert.py).
  - The body has 30 bounded instructions, a security-cookie frame, a single `InvalidateRect` call, and final `retn 4`.
  - Predecessor and successor padding isolate the target from UID0004CZ and UID0004D1.
  - The full-range signature is unique.
- Corroborating documentation/generated-report evidence:
  - `by-file/StartupWindow.md` and `by-class/StartupWindow.md` route the StartupWindow helper family through UID0000O5.
  - Parent [UID:0001IO] and tracker [UID:0000VI] already list UID0004D0 as an exact child and keep broad pages non-emitting.
  - Generated `auto-generated/NexusTK/app/StartupWindow.cpp` already emits the UID0004D0 helper body, currently tagged `Completion:86 | Confidence:88`.
- Strongest inference chain:
  - Target disassembly proves the one-RECT invalidation behavior.
  - UID0004CX proves state/RECT/HWND offsets for indexed button slots.
  - UID0004CZ proves the all-buttons sibling uses the same first RECT and `0x20` stride.
  - StartupWindow support docs and generated output prove the owner/emitter route.

## IDA MCP Facts

- Session facts:
  - `idb_list`: `ddf5b602`, active worker, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`.
  - `server_health`: `status:"ok"`, `module:"NexusTK.exe"`, `imagebase:"0x400000"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- Function/range facts:
  - `lookup_funcs`: `0x00581860`, `0x005818c3`, `0x00581854`, `0x005818d0`, and `0x005817e0` are not functions.
  - `lookup_funcs`: sibling set helper `0x00581730` is `sub_581730`, size `0x70`; WndProc `0x00581100` is `sub_581100`, size `0x4aa`.
  - `analyze_function 0x00581860`: no function at `0x581860`.
  - `decompile 0x00581860`: decompilation failed at `0x581860`.
- Bytes and instruction facts:
  - Bytes from `0x00581854` show twelve `0xcc` bytes, target bytes, thirteen `0xcc` bytes, and successor prologue `55 8b ec 53` at `0x005818d0`.
  - Target instruction query returned 30 instructions, `truncated:false`.
  - Key target instructions: `[ebp+8]`, `inc eax`, `shl eax, 5`, `push 0`, `movups xmm1, [eax+ecx]`, `push [ecx+0Ch]`, `call ds:InvalidateRect`, `retn 4`.
- Xref facts:
  - `xrefs_to 0x00581860`: zero.
  - `find code_ref`, `find data_ref`, and `find immediate` for `0x00581860`, `0x005818c3`, `0x00581854`, and `0x005818d0`: zero matches.
  - `xref_query` to `InvalidateRect` in the local range identifies calls at `0x0058178a`, `0x00581835`, and `0x005818ad`, matching UID0004CX, UID0004CZ, and UID0004D0 respectively.
- Type facts:
  - `type_query` for `StartupWindow` and `StartupNotice` returned zero local IDA types. Field/member names remain documentation-level source names.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00581730-0x005817a0` | [UID:0004CX][0x00581730-0x005817a0.StartupNoticeSetButtonState](by-memory/0x00581730-0x005817a0.StartupNoticeSetButtonState.md) | Indexed state update plus changed-rect invalidation | TRUE | `0000O5` | `88/91` | Sibling support, executed direct report |
| `0x005817e0-0x00581854` | [UID:0004CZ][0x005817e0-0x00581854.StartupNoticeInvalidateButtons](by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md) | Invalidate both notice button rectangles | TRUE | `0000O5` | `88/91` | Sibling support, executed direct report |
| `0x00581854-0x00581860` | ignored padding | all-buttons-to-one-button padding | FALSE if materialized | N/A | N/A | Twelve `0xcc` bytes |
| `0x00581860-0x005818c3` | [UID:0004D0][0x00581860-0x005818c3.StartupNoticeInvalidateButton](by-memory/0x00581860-0x005818c3.StartupNoticeInvalidateButton.md) | Invalidate one indexed notice button rectangle | TRUE | `0000O5` | current `86/88`, recommend `88/91` | This report's target |
| `0x005818c3-0x005818d0` | ignored padding | one-button-to-assets padding | FALSE if materialized | N/A | N/A | Thirteen `0xcc` bytes |
| `0x005818d0-0x005819cc` | [UID:0004D1][0x005818d0-0x005819cc.StartupNoticeLoadAssets](by-memory/0x005818d0-0x005819cc.StartupNoticeLoadAssets.md) | Startup notice PCX asset/load-rect helper | TRUE | `0000O5` | `88/91` | Successor child |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00581860` | zero xrefs to start | Raw helper has no direct start route; confidence cap only |
| `0x005818ad` | call to `ds:InvalidateRect` | Target's one side effect |
| `0x0058178a` | call to `ds:InvalidateRect` in UID0004CX | State helper sibling invalidates changed indexed rect |
| `0x00581835` | call to `ds:InvalidateRect` in UID0004CZ | All-buttons sibling invalidates both rects |
| `0x005818c0` | `retn 4` | Confirms one stack argument, `buttonIndex` |
| `0x00581730` | `sub_581730`, size `0x70` | Modeled set-state sibling; verifies `+0x30` state slot and `+0x20` RECT slot |
| `0x00581100` | `sub_581100`, size `0x4aa` | Startup notice WndProc context for the surrounding helper family |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - Target already has correct owner/emitter and formal helper body.
  - `by-file/StartupWindow.md` lists UID0004D0 among exact child pages that emit through `StartupWindow.cpp`.
  - `by-class/StartupWindow.md` lists invalidation helper ranges and states exact helper bodies emit from by-memory children.
  - `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md` lists UID0004D0 as an exact raw helper child and keeps the parent non-emitting.
  - `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md` lists UID0004D0 as an exact child and keeps the tracker non-emitting.
  - `by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md` already records the sibling layout relationship.
- Existing docs that are stale, incomplete, or contradicted:
  - Target page is not wrong, but incomplete: it lacks current direct MCP evidence, exact bytes/instructions/signature, generated-output state, and a score rationale matching adjacent direct reports.
  - Support docs list the target but do not yet carry a direct UID0004D0 refresh note.
- Generated/coverage report state:
  - `auto-generated/-ag-research-tracker.md` shows UID0004D0 under Not-Covered Files - Reconstructable with reports `0`.
  - `auto-generated/NexusTK/app/StartupWindow.cpp` header shows validator command `000000006440`, refreshed `2026-07-04T18:28:15-04:00`, and emits UID0004D0 at `Completion:86 | Confidence:88`.

## Ranked Ownership Analysis

### 1. [UID:0000O5] StartupWindow file route

- Evidence for: file/class/parent docs route StartupWindow notice helper children through `StartupWindow.cpp`; generated output already emits UID0004D0 there; target uses StartupWindow notice HWND/button layout; siblings UID0004CX/UID0004CZ are StartupWindow children.
- Evidence against: no direct xrefs/callers to raw start and no recovered original private helper spelling.
- Decision: keep as direct owner/emitter. The negative route is a confidence cap, not ownership refutation.

### 2. [UID:0001IO] StartupWindowUpdateCheck parent split/index

- Evidence for: physical range contains UID0004D0 and surrounding StartupWindow helper family.
- Evidence against: current page is `RECONSTRUCTABLE:FALSE`, blank-emitting, and exists as a split/index so exact children carry source. It should not duplicate child C++.
- Decision: keep as non-emitting parent/support page only.

### 3. [UID:0000VI] StartupWindowUnmodeledNoticeHelpers tracker

- Evidence for: tracker covers the raw helper family and links UID0004D0.
- Evidence against: tracker is non-canonical, `RECONSTRUCTABLE:FALSE`, and exists to preserve raw-helper boundary/no-route history.
- Decision: no ownership/emission. It should only receive a support note if accepted.

### 4. Generic Win32, Browser, ImageLoaders, MiniMapVersionManager, MD5, Application, Config, no-owner

- Evidence for: StartupWindow depends on some of these systems elsewhere, and the target calls a Win32 API.
- Evidence against: the body uses StartupWindow instance layout and has no Browser/ImageLoaders/minimap/hash/application/config behavior. No-owner contradicts the established source route and emitted helper body.
- Decision: reject.

### Proposed new file/grouping, if applicable

No new source file or grouping is proposed. The correct source placement remains `NexusTK/app/StartupWindow.cpp`.

## Source Placement

- Recommended source file/class/global/module placement: file-local static helper in [UID:0000O5][StartupWindow](by-file/StartupWindow.md), generated under `NexusTK/app/StartupWindow.cpp`.
- Why this placement fits source-tree and subsystem context: the helper belongs to the startup notice window's private button UI helpers and shares layout/state with adjacent StartupWindow helper children.
- Rejected placements: parent aggregate [UID:0001IO], by-item tracker [UID:0000VI], generic Win32 helper, Browser, ImageLoaders, MiniMapVersionManager, MD5, Application, Config, and no-owner.
- Remaining placement uncertainty: exact original helper spelling and member names are inferred, but the file route is strong.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts:
  - Target is `0x00581860-0x005818c3`, half-open.
  - Size is `0x63` / 99 bytes (Verified with int_convert.py).
  - Predecessor padding `0x00581854-0x00581860`: twelve `0xcc` bytes.
  - Successor padding `0x005818c3-0x005818d0`: thirteen `0xcc` bytes.
  - Successor raw helper UID0004D1 begins with `55 8b ec 53` at `0x005818d0`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner:
  - No new split or merge is required.
  - Do not merge with UID0004CZ or UID0004D1.
  - Do not range-extend into padding.
- Padding/table/data/code distinctions:
  - Target is source-authored code.
  - Neighboring spans are alignment padding.
- Parent/container impact:
  - Parent [UID:0001IO] remains a non-emitting split/index.
  - by-item [UID:0000VI] remains a non-emitting raw-helper tracker.

## Negative Evidence Summary

- No IDA function object at `0x00581860`.
- No decompilation at `0x00581860`.
- No direct xrefs to `0x00581860`.
- No exact code/data/immediate refs to `0x00581860`, `0x005818c3`, `0x00581854`, or `0x005818d0` in current MCP `find` checks.
- No local `StartupWindow` or `StartupNotice` UDT was recovered.
- No evidence supports raw `sub_` naming, no-code/padding treatment, parent aggregate emission, by-item tracker emission, or unrelated module ownership.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments:
  - Keep `StartupNoticeInvalidateButton` as the source-facing helper name.
  - Keep `StartupWindow *startupWindow` for the explicit file-local helper receiver.
  - Keep `int buttonIndex` for the stack argument consumed by `ret 4`.
  - Keep `m_noticeWindow` for `this+0x0c`.
  - Keep `m_buttons[index].rect` for the `this+0x20 + index*0x20` RECT storage.
- Evidence for each:
  - Helper name is consistent with UID0004CZ `StartupNoticeInvalidateButtons` and generated `StartupWindow.cpp`.
  - Receiver and button index are directly observed in disassembly (`ecx`, `[ebp+8]`, `retn 4`).
  - HWND and RECT field names are supported by target disassembly and sibling UID0004CX/UID0004CZ behavior.
- Items intentionally left unchanged:
  - Do not use raw `sub_581860`, `_DWORD *`, `this[3]`, `dword`, or decompiler temporary names in source-facing prose or C++.
  - Do not create a local IDA `StartupWindow`/`StartupNotice` UDT from this tiny helper alone.
  - Do not rename IDA symbols or define a function during this B-agent report-only pass.
- IDA DB edits: not requested and not safe within this assignment. A future supervisor-authorized IDA cleanup may define the function, but documentation source output should remain the formal helper block.

## First-Draft C++ Recommendation

Eligible for draft C++: yes. The current formal body is already source-shaped and should be preserved/refreshed exactly.

Recommended formal insertion text:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
static void StartupNoticeInvalidateButton(StartupWindow *startupWindow, int buttonIndex)
{
    InvalidateRect(startupWindow->m_noticeWindow, &startupWindow->m_buttons[buttonIndex].rect, FALSE);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Reason it preserves exact behavior: the binary computes the indexed rectangle, passes the notice HWND at `this+0x0c`, passes `FALSE`, calls `InvalidateRect`, checks the security cookie, and returns with `ret 4`. The formal helper expresses exactly that visible source behavior without adding state mutation or a bounds guard not present in the target.

Reason it matches source shape: the surrounding StartupNotice helper family emits file-local helpers in `StartupWindow.cpp`. This target is a private helper, not a public method or a generic Win32 utility.

Inferred names used: `StartupWindow`, `StartupNoticeInvalidateButton`, `startupWindow`, `buttonIndex`, `m_noticeWindow`, `m_buttons`, and `rect`. These remain confidence caps for exact original spelling.

## Final Recommendation

- Recommended target changes: set `COMPLETION:88`, `CONFIDENCE:91`; keep owner/emitter/reconstructable metadata and formal C++; add current MCP session `ddf5b602` evidence at report-level detail.
- Recommended parent assignments: none changed. Keep [UID:0000O5] as owner/emitter, [UID:0001IO] as non-emitting split/index, and [UID:0000VI] as non-emitting tracker.
- Exact items left no-owner/non-emitting: no new no-owner items. Neighboring padding remains ignored/non-source; parent/tracker pages remain non-emitting.
- Future work outside this assignment: optional supervisor-authorized IDA function definition/rename could improve raw-function ergonomics, but it is not required for source output and is not requested here.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00581860-0x005818c3.StartupNoticeInvalidateButton.md`.
- Exact report facts to incorporate:
  - MCP session `ddf5b602`, active `NexusTK.exe.i64`, `server_health ok`.
  - Exact range `0x00581860-0x005818c3`, size `0x63` / 99 bytes (Verified with int_convert.py).
  - No IDA function at target start/end/boundaries; no decompile/analyze function at `0x00581860`.
  - Target bytes/instruction summary: 30 instructions, security-cookie frame, `[ebp+8]` index, `(buttonIndex + 1) << 5`, copied RECT, `this+0x0c` HWND, `InvalidateRect(..., FALSE)`, final `retn 4`.
  - Boundary proof: twelve `0xcc` bytes at `0x00581854-0x00581860`, thirteen `0xcc` bytes at `0x005818c3-0x005818d0`, successor UID0004D1 prologue at `0x005818d0`.
  - Unique full-range signature.
  - Negative route checks: zero xrefs, zero code/data/immediate refs to target start and queried boundary addresses, no local `StartupWindow` or `StartupNotice` type.
  - Sibling proof vs UID0004CX and UID0004CZ.
  - Generated output currently emits the helper through `StartupWindow.cpp`.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - Set `COMPLETION:88`.
  - Set `CONFIDENCE:91`.
  - Keep `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank optional position, and `Nested:0`.
  - Preserve exact formal `RECONSTRUCTION_CPP CODE` block shown above.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - Preserve raw no-function/no-direct-start-route confidence cap.
  - Reject padding/no-code/no-owner/parent-emitter/tracker-emitter/generic Win32/unrelated module ownership.

## Recommended Support Doc Changes

- `by-file/StartupWindow.md`:
  - Add or update a UID0004D0 source-output note matching sibling callback detail: current MCP session `ddf5b602`, exact range/size, 30-instruction raw helper, indexed `m_buttons[buttonIndex].rect`, `m_noticeWindow`, `InvalidateRect(..., FALSE)`, no direct start route, and score `88/91`.
  - Keep file metadata unchanged unless validator/support policy requires normalization.
- `by-class/StartupWindow.md`:
  - Update the `notice invalidation helpers` method row/evidence notes to state UID0004D0 is source-ready as the one-button invalidation helper, with exact range `0x00581860-0x005818c3`, size `0x63` / 99 bytes, sibling relationship to UID0004CZ and UID0004CX, and remaining private-name confidence caps.
- `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`:
  - Update the UID0004D0 covered row/evidence note to include direct B003 current MCP proof and score `88/91`, while preserving the parent as `RECONSTRUCTABLE:FALSE`, blank emitter, and blank formal C++.
- `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`:
  - Update the UID0004D0 split-status row or change note so the tracker says the exact child now has direct report evidence and should remain non-emitting.
- `by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md`:
  - Review-only. It already records the one-button sibling layout proof at same-or-greater detail; mark already-present unless a callback needs a narrow "B003 direct report exists" note.
- Generated `auto-generated/NexusTK/app/StartupWindow.cpp`:
  - Do not edit manually. Scoped validation during implementation should refresh the UID0004D0 annotation from `86/88` to `88/91`.

## Score And Metadata Recommendation

- Current score/metadata: `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000O5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000O5`, blank optional position, `Nested:0`.
- Recommended score/metadata: `COMPLETION:88`, `CONFIDENCE:91`, same owner/emitter/reconstructable/optional/Nested values.
- Score rationale and reason not higher/lower:
  - Higher than current because the report now supplies current MCP bytes, bounded instruction proof, signature uniqueness, boundary padding, negative route checks, generated-output evidence, and sibling comparison.
  - Not above `88` completion because no IDA function object/direct caller route or recovered original type/member/helper spelling exists.
  - Not above `91` confidence because no direct start route is known and local UDTs are absent.
  - Not lower because behavior, boundaries, owner/emitter, and formal source shape are fully supported by direct evidence.
- Score-improvement attempt:
  - Single-button invalidation helper: resolved with direct target disassembly.
  - Relationship to `StartupNoticeInvalidateButtons`: resolved as indexed one-button sibling using same HWND/RECT layout.
  - Relationship to `StartupNoticeSetButtonState`: resolved as direct invalidation only, no state read/write; set-state sibling owns state mutation.
  - Button-state storage: target does not touch `+0x30`; sibling verifies it.
  - HWND/rect flow: resolved as `this+0x0c` HWND and `this+0x20 + index*0x20` RECT.
  - Owner/emitter: remains StartupWindow through UID0000O5.
  - Source-facing helper name: keep existing project-stable `StartupNoticeInvalidateButton`; exact original spelling remains cap.
  - C++ path: preserve existing formal block.

## Open Questions With Attempted Resolution

| Open question | Evidence checked | Resolution | Score/C++ impact | Future evidence that could change it |
| --- | --- | --- | --- | --- |
| Was the original helper name exactly `StartupNoticeInvalidateButton`? | Current docs, generated output, sibling naming, no IDA type/symbol evidence. | Inferred source-facing name is stable and best-supported; exact original spelling not recovered. | Caps confidence, does not block formal C++. | Original source/header/PDB or accepted IDA symbol recovery. |
| Is there a direct caller/start route? | `xrefs_to`, `xref_query`, and `find` code/data/immediate for start/boundaries. | No current direct route found. | Caps confidence; does not refute source presence. | IDA function-definition cleanup, relocation/caller evidence, or source import. |
| Are field names original? | Target/sibling instruction offsets, type query for `StartupWindow`/`StartupNotice`. | Names are project-stable inferred layout names. | Formal C++ can keep them; confidence capped. | Accepted class layout/UDT reconstruction or source. |
| Should this be a class method instead of file-local helper? | ABI uses `ecx` receiver, but helper family/source route uses static file-local helpers. | Keep file-local helper with explicit `StartupWindow *`. | Preserves current generated source shape. | Stronger evidence of original member declaration. |

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. The tracker row is validator-owned/generated. Do not manually edit `auto-generated/-ag-research-tracker.md` or any `-coverage-report.md` file. If the report is accepted, scoped by-* validators and supervisor-owned report execution should refresh generated tracker/report state.

## Follow-Up Actions

- Supervisor action after Gate 1: if accepted, send an implementation callback for target/support by-* edits and scoped validators.
- B003 callback action if authorized: apply target/support changes above, update this report ledger/checklist, run scoped validators for changed by-* files, and stop for supervisor execution.
- Future optional action: supervisor-authorized IDA cleanup may define the raw function, but it is not required for documentation/source output.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `88/91`.
- Remaining uncertainty: exact original helper/member names and hidden direct route are unresolved but bounded by current negative evidence.

## Validator Results

- Scoped validators run from `E:\NTK\GhidraBridge\source-3\project-documentation` during the implementation callback:
  - `python .\tools\validator.py --mode file --file by-memory/0x00581860-0x005818c3.StartupNoticeInvalidateButton.md --apply --queue-timeout 240 --wait-generated`
    - `command_id: 000000006454`
    - `command_timestamp: 2026-07-04T19:04:25-04:00`
    - exit code `0`; `ok: 1`
    - relevant updates: `completion_update 0004D0 ... 88`, `confidence_update 0004D0 ... 91`, `reference_index_add` for UID0004CX/UID0004CZ/UID0004D1, `autogen_cpp_update 0000O5 auto-generated/NexusTK/app/StartupWindow.cpp`, `research_tracker_update`, `memory_auto_coverage_update`
    - generated refresh: `completed`; `generated_refresh_command_id: 000000006454`; `generated_refresh_timestamp: 2026-07-04T19:04:25-04:00`
    - warnings/notes: validator reported project-wide generated child-marker/emitter-no-code notices outside this UID; no UID0004D0 validation error.
  - `python .\tools\validator.py --mode file --file by-file/StartupWindow.md --apply --queue-timeout 240`
    - `command_id: 000000006455`
    - `command_timestamp: 2026-07-04T19:04:43-04:00`
    - exit code `0`; `ok: 1`
    - generated refresh: `deferred`; no warnings/errors for this file.
  - `python .\tools\validator.py --mode file --file by-class/StartupWindow.md --apply --queue-timeout 240`
    - `command_id: 000000006456`
    - `command_timestamp: 2026-07-04T19:04:49-04:00`
    - exit code `0`; `ok: 1`
    - relevant update: `reference_index_add 0004D0 by-class/StartupWindow.md`
    - generated refresh: `deferred`; no warnings/errors for this file.
  - `python .\tools\validator.py --mode file --file by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md --apply --queue-timeout 240`
    - `command_id: 000000006457`
    - `command_timestamp: 2026-07-04T19:04:57-04:00`
    - exit code `0`; `ok: 1`
    - generated refresh: `deferred`; no warnings/errors for this file.
  - `python .\tools\validator.py --mode file --file by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md --apply --queue-timeout 240`
    - `command_id: 000000006458`
    - `command_timestamp: 2026-07-04T19:05:07-04:00`
    - exit code `0`; `ok: 1`
    - relevant update: `stats_row_update 0000VI project-level/-auto-completion-stats.md by-item_Not_Reconstructable`
    - generated refresh: `deferred`; no warnings/errors for this file.
  - `python .\tools\validator.py --mode file --file by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md --apply --queue-timeout 240`
    - `command_id: 000000006459`
    - `command_timestamp: 2026-07-04T19:05:16-04:00`
    - exit code `0`; `ok: 1`
    - generated refresh: `deferred`; no warnings/errors for this file.
- Generated freshness observation: post-validator read of `auto-generated/NexusTK/app/StartupWindow.cpp` shows UID0004D0 header `Completion:88 | Confidence:91` and the unchanged helper body:
  - `static void StartupNoticeInvalidateButton(StartupWindow *startupWindow, int buttonIndex)`
  - `InvalidateRect(startupWindow->m_noticeWindow, &startupWindow->m_buttons[buttonIndex].rect, FALSE);`
- Manual generated/coverage edits: none. Generated and coverage updates listed above were validator-owned side effects.

## Changed Files

- Modified by B003 implementation callback:
  - `by-memory/0x00581860-0x005818c3.StartupNoticeInvalidateButton.md`
  - `by-file/StartupWindow.md`
  - `by-class/StartupWindow.md`
  - `by-memory/0x005807d0-0x0058206e.StartupWindowUpdateCheck.md`
  - `by-item/StartupWindowUnmodeledNoticeHelpers_5815b0_581b7f.md`
  - `by-memory/0x005817e0-0x00581854.StartupNoticeInvalidateButtons.md`
  - `tools/leaser/Agents/Agent-B003/research/0004D0-StartupNoticeInvalidateButton-source-quality.md`
- Validator-owned generated refresh/updates observed:
  - `auto-generated/NexusTK/app/StartupWindow.cpp`
  - generated metadata/research-tracker/coverage artifacts reported by validator command `000000006454`
- Renamed: none.
- Report execution: not run. B003 did not run `execute_report`, dry-run/probing variants, lifecycle/archive commands, registry commands, manual report moves, supervisor-ledger edits, or manual generated/coverage edits.
- Lease usage:
  - Acquired before edits with `python .\tools\leaser\leaser.py B003 lease ...` for the six changed by-* files; all six returned `Success`.
  - Released after validators with `python .\tools\leaser\leaser.py B003 unlease ...`; all six returned `Success`.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation: Gate 1 passed for SHA256 `9D710F77CA59FA95A12E8FD1EC1F72B72FECA353B153C9293F9BB28CE92F85F1`.
- [x] Target/support docs to update: target, by-file, by-class, parent aggregate, tracker, and reviewed sibling were updated as listed in Changed Files.
- [x] Current target state and actual evidence checked recorded: MCP session `ddf5b602`, health, lookup, bytes, instructions, xrefs, decompile/analyze failure, signature, type query, int conversions, generated output, tracker, and old reports remain recorded above and incorporated into by-* docs.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: rows C-0004D0-001 through C-0004D0-012 are now `applied` with proof.
- [x] Metadata/score changes to apply: target is now `COMPLETION:88`, `CONFIDENCE:91`; owner/emitter/reconstructable/optional/Nested values remain unchanged.
- [x] Score-limiting blockers researched: no-function/no-route/local-UDT/original-spelling caps are documented in target/support docs.
- [x] Owner/emitter/reconstructable changes to apply: none; `0000O5` owner/emitter and `RECONSTRUCTABLE:TRUE` were preserved.
- [x] Split/rename/new-child changes to apply: none; exact range and child split were preserved.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: StartupWindow file-local helper placement preserved; padding and negative route evidence incorporated; no IDA DB edits requested or performed.
- [x] First-draft C++ or no-code proof to apply: target formal C++ block preserved exactly.
- [x] Third-party import directive to apply or confirm not applicable: not applicable.
- [x] Exact target/support doc facts incorporated at report-level detail: current MCP session, range/size, bytes/instructions, fields, sibling comparison, padding, signature, generated output state, and rejected alternatives were added.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: raw no-route confidence cap and rejected padding/no-owner/parent-emitter/tracker-emitter/raw naming/unrelated owners remain documented.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: generated output was treated as validator-owned output, not manually edited source.
- [x] Open questions to close or document as evidence-backed unresolved: original spelling and direct start route remain evidence-backed confidence caps.
- [x] Validators to run: scoped file validators ran for all six changed by-* docs; results recorded above.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: validator command `000000006454` refreshed generated output; no manual generated/coverage edits were made.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator; post-validator read confirms UID0004D0 generated output is `Completion:88 | Confidence:91`.
- [x] Remaining unapplied accepted items listed with exact blocker: none.

Implementation callback stop condition: `READY_FOR_SUPERVISOR_EXECUTE`. B003 stopped before supervisor-owned execution/report lifecycle handling.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000006486","destination_path":"executed-b-agent-research/B003/0004D0-StartupNoticeInvalidateButton-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B003/research/0004D0-StartupNoticeInvalidateButton-source-quality.md","timestamp":"2026-07-04T19:16:29-04:00","uid":"0004D0"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
