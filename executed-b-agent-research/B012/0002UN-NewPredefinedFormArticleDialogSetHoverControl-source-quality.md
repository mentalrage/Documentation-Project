** TARGET-REPORT-UID:0002UN **
** AUTHOR-AGENT-ID:B012 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002UN NewPredefinedFormArticleDialogSetHoverControl Source-Quality Research


## Finalized Report / Current Recommendation
- Current recommendation: implemented after supervisor `GATE1_PASSED`; UID0002UN is now source-ready as the exact `NewPredefinedFormArticleDialog::SetHoverControl(int controlId)` forwarding child.
- Final disposition: kept owner/emitter route through [UID:000098] `NewPredefinedFormArticleDialog`; inserted exact formal C++ for the child; updated target evidence and score from `85/90` to `90/92`.
- Required action: supervisor Gate 2 verification and later supervisor-only `execute_report`. B012 edited only the accepted target/support/report files, ran scoped file validators, released leases, and did not run any report execution/lifecycle/archive command.
- Confidence: high. The body, size, xrefs, padding, sibling precedent, and inherited helper behavior are all supported by live IDA MCP evidence plus current by-* support docs. The method and parameter names remain source-facing inferred names rather than original symbol-proof names.

## Supporting Research
- Lifecycle/status notes: report-only research completed first, then supervisor returned `GATE1_PASSED` and authorized this implementation callback. The earlier MCP outage/pause is historical; accepted evidence was collected from active session `supervisor_recovery_20260705`.
- Current supervisor instruction: implement the accepted UID0002UN disposition, edit the exact target plus narrow support docs, run scoped validators, update this report checklist/ledger, release leases, and stop at `READY_FOR_SUPERVISOR_EXECUTE`. B011 owns aggregate UID0000ZL, so B012 did not edit the aggregate.
- Prior report search terms used before drafting: `0002UN`, `0x00478370`, `00478370`, `0x00478379`, `00478379`, `NewPredefinedFormArticleDialogSetHoverControl`, `SetHoverControl`, `sub_478370`, `sub_49FC00`, `0x006140a8`, `006140a8`.
- Matching prior/support reports checked:
  - `executed-b-agent-research/B005/00030K-NewArticleDialogCore-source-quality.md`: source-ready sibling `0x004772e0-0x004772e9` emits `NewArticleDialog::SetHoverControl(int controlId)` forwarding to `DialogPane::SetHoverControl(controlId)`.
  - `executed-b-agent-research/B002/0002QD-HandlePasswordChangeReply-empty-emitter-source-quality.md`: identifies `0x0049fc00` as the inherited `DialogPane::SetHoverControl(int controlId)` / active hover-control id helper and rejects focus/select-control names.
  - `executed-b-agent-research/B008/0001J7-ForcedInformMessageDialogCore-source-quality.md`: records `sub_49FC00` as `DialogPane::SetHoverControl(int controlId)` and notes the accepted declaration support in `by-class/DialogPane.md`.

## Target
- Target UID: `0002UN`
- Target path: `source-3/project-documentation/by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` lists UID0002UN at `85/90`, average `87.5`, reconstructable true, code count `0`.
- Current supervisor classification: report-only B-agent source-quality research for the exact hover-control child.
- Current scores and parent state: target currently `COMPLETION:85`, `CONFIDENCE:90`, `RECONSTRUCTABLE:TRUE`, `CANONICAL_OWNER:000098`, `EMITTER_UIDS:000098`; parent class [UID:000098] routes to file [UID:0000LT] `NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp`.

## Current Target State
- Existing metadata: UID0002UN is a tiny exact by-memory child at `0x00478370-0x00478379`, current summary says it is a vtable-referenced hover-control forwarder that tail-jumps to `sub_49FC00`.
- Existing owner/emitter/reconstructable state: owner and emitter are already [UID:000098] `NewPredefinedFormArticleDialog`; reconstructable is already true.
- Existing C++/emitter state: formal C++ block is blank. Generated output currently has an empty emitter marker for UID0002UN in `auto-generated/NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp`.
- Existing blockers or stale assumptions: target text says final C++ stayed blank because the virtual name and shared helper declaration were blockers. Current support docs and live MCP evidence now resolve those blockers enough for first-draft formal C++.
- Related target/support docs checked: `by-class/NewPredefinedFormArticleDialog.md`, `by-file/NewPredefinedFormArticleDialog.md`, `by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`, `by-class/DialogPane.md`, `by-type/by-struct/DialogPaneLayout.md`, `by-type/by-vtable/BoardArticleDialogVtableFamily.md`, `by-memory/0x0049d8a0-0x0049feae.DialogPane.md`, `by-memory/0x0049dae0-0x0049dfc4.DialogControlPaneHelpers.md`, and `by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md`.
- Current artifact/lifecycle status: this report is a report-only artifact in B012 research. No implementation, validator, coverage, generated, or lifecycle command was run.

## Executive Recommendation
- Best direct owner: [UID:000098] `NewPredefinedFormArticleDialog`.
- Source method: `void NewPredefinedFormArticleDialog::SetHoverControl(int controlId)`.
- Source body: exact one-statement forwarding wrapper to inherited `DialogPane::SetHoverControl(controlId)`.
- Assignment/split disposition: no split, merge, no-owner, or reclassification is needed. The exact 9-byte child should stay within the existing class/file route and become a nonblank emitter child.
- Remaining condition before implementation: supervisor approval of this report and normal implementation callback; B012 is not authorized to edit target/support files during this pass.

## Supervisor Active Recheck
- Supervisor instruction rechecked: use active MCP session `supervisor_recovery_20260705`; IDA MCP evidence is mandatory; stop if MCP becomes unavailable; do not edit by-* docs/generated/coverage/validator state; do not run validators or lifecycle/report execution commands.
- Split repair requirement: no split repair is required. The assigned range is already exact at 9 bytes with padding after the function and no extra code in the child range.
- Source-bearing children in scope: only UID0002UN is in B012 scope. The aggregate UID0000ZL is assigned to B011 and should only receive coordinated support-row synchronization if the supervisor later chooses to apply this child report.

## Inference Research Guidance Check
- IDA facts were kept separate from documentation evidence and source-facing inference. IDA proves range, body, xref, padding, helper bytes/decompile, and sibling code shape. Existing docs provide class/file route and accepted source-facing names.
- Existing assumptions treated as uncertain until checked: target's blank-C++ blocker, the helper name behind `sub_49FC00`, the lack of ordinary callers, and whether the one-call wrapper is truly bounded to 9 bytes.
- Wave2/Wave3 artifacts: no current Wave2/Wave3 artifact was encountered in the target-specific searches, and none was used.
- IDA endpoint note: an initial local HTTP probe to `127.0.0.1:17007/mcp` failed because it was not the project MCP endpoint. The workflow reference identifies `http://127.0.0.1:13337/mcp`; that endpoint succeeded and supplied all accepted MCP evidence below.

## Heuristic / Inference Reanalysis And Validation
- Generated function name: `sub_478370` is a compiler/IDA placeholder and should not appear as source-facing C++.
  - Best inference: class method `NewPredefinedFormArticleDialog::SetHoverControl`.
  - Evidence: data xref from the NewPredefined vtable slot `0x006140a8`, parent class method row, sibling `NewArticleDialog::SetHoverControl`, and accepted `DialogPane::SetHoverControl` support.
  - Status: source-facing inferred/project-supported, not original symbol-proof.
- Helper name: `sub_49FC00` should be modeled as `DialogPane::SetHoverControl(int controlId)`.
  - Evidence: live MCP helper disassembly reads `this+0x214`, uses manager at `this+0x1fc`, deactivates the prior child through virtual slot `+0x58`, activates the new child through virtual slot `+0x5c`, and writes `this+0x214 = controlId`; `by-class/DialogPane.md` already declares `void SetHoverControl(int controlId);`.
  - Status: source-facing inferred/project-supported and behavior-backed.
- Parameter name: `controlId` is preferred over `a2`/`param_1`.
  - Evidence: helper behavior uses an integer child/control id, support docs name the field `m_activeControlId`, and sibling formal C++ uses `controlId`.
  - Status: inferred descriptive source name.
- Return type: `void`, not `return sub_49FC00(...)`.
  - Evidence: live MCP decompile of `sub_478370` is `void __thiscall sub_478370(int this, int a2) { sub_49FC00(this, a2); }`; helper returns with `retn 4` and no value-producing path.
  - Status: IDA/decompiler fact for this target.
- Caller/reachability: absence of ordinary code callers is expected and not a no-owner signal.
  - Evidence: `xrefs_to 0x00478370` returns exactly one data xref at `0x006140a8`; vtable support docs place this slot in the NewPredefined vtable family.
  - Status: direct IDA fact plus support-doc route.
- Rejected alternatives:
  - `SelectControlById` / focus/current-control setter: rejected because helper toggles hover/active child visual state and updates the `+0x214` active hover-control id, not the focused/current control route.
  - Place this code on `DialogPane`: rejected because `0x00478370` is a NewPredefined vtable wrapper; only the shared helper body lives on `DialogPane`.
  - Keep formal C++ blank: rejected because the previously named blockers are now resolved by live helper evidence and existing support declarations.

## Evidence Standards Used
- IDA MCP evidence used: `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `disasm`, `decompile`, `xrefs_to`, `callees`, and `get_bytes` against `supervisor_recovery_20260705`.
- Binary evidence used: exact function size, assembly, decompile, raw bytes before/inside/after the function, vtable slot bytes, data xref, sibling wrapper shape, and helper implementation.
- Documentation evidence used: current by-memory target, class/file owner docs, DialogPane declaration/layout docs, vtable-family doc, sibling NewArticle source report/doc, generated tracker/coverage/source state, and prior executed B-agent support reports.
- Strength of evidence: strong enough for first-draft C++ because the target is only a tail-forwarder and the inherited helper has a current accepted source-facing declaration. Confidence remains below near-perfect because names are project-source-facing inferred names, not recovered original PDB/symbol names.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `idb_list`: count `1`; active session `supervisor_recovery_20260705`, backend worker, `pid=19604`, `worker_pid=19604`.
  - `server_health`: status `ok`, auto-analysis ready, Hex-Rays ready, strings cache ready.
  - `lookup_funcs`: `0x00478370 -> sub_478370 size 0x9`; `0x00478379 -> Not a function`; `0x0049fc00 -> sub_49FC00 size 0x4c`.
  - `disasm/decompile`: target, sibling `0x004772e0`, and helper `0x0049fc00`.
  - `xrefs_to`: target `0x00478370`, sibling `0x004772e0`, and capped helper sample.
  - `get_bytes`: target context `0x00478363` size `0x1d` and vtable slot `0x006140a8` size `4`.
- by-* docs, support docs, old reports, generated reports, and trackers checked: files listed in `Current Target State` plus `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-memory-coverage.md`, and generated `NewPredefinedFormArticleDialog.cpp`.
- Negative checks performed: no ordinary code xrefs to the target; no function at `0x00478379`; generated output has no nonblank UID0002UN code; old `DialogPane` aggregate wording that labels `0x0049fc00` as a rect/position writer is stale relative to current helper evidence.
- Failed, unavailable, or intentionally skipped checks and why: the initial `127.0.0.1:17007/mcp` probe failed because it was the wrong endpoint; the correct project endpoint `127.0.0.1:13337/mcp` succeeded. Validators, report execution, lifecycle commands, target/support edits, generated edits, coverage edits, and registry commands were intentionally skipped by supervisor instruction.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID0002UN is exactly `0x00478370-0x00478379`, function `sub_478370`, size `0x9`. | High | MCP `lookup_funcs`; `0x00478379` not a function; raw bytes show `cc` padding after. | Target Address Range / Evidence | Implemented in target. | Verified in changed target; validator `000000006732` ok. |
| C2 | Body is a four-instruction wrapper ending in `jmp sub_49FC00`. | High | MCP `disasm`: `push ebp; mov ebp, esp; pop ebp; jmp sub_49FC00`. | Target Behavior / Evidence | Implemented in target. | Verified in changed target; validator `000000006732` ok. |
| C3 | Decompiled behavior is `sub_49FC00(this, a2);` with `void` return. | High | MCP `decompile` target. | Target Behavior / C++ rationale | Implemented in target. | Verified in changed target; validator `000000006732` ok. |
| C4 | The only direct xref to the target is data slot `0x006140a8`. | High | MCP `xrefs_to 0x00478370` returns one data xref, no more. | Target Evidence; class/file support route notes | Implemented in target and support docs. | Verified in changed target/class/file; validators `000000006732`-`000000006734` ok. |
| C5 | Vtable slot `0x006140a8` stores `0x00478370`. | High | MCP `get_bytes 0x006140a8` returns `70 83 47 00`. | Target Evidence; class/file boundary route notes | Implemented in target and support docs. | Verified in changed target/class/file; validators `000000006732`-`000000006734` ok. |
| C6 | `sub_49FC00` is the inherited active/hover control-id helper. | High | MCP helper disasm/decompile: reads/writes `+0x214`, uses manager at `+0x1fc`, calls virtual slots `+0x58` and `+0x5c`; DialogPane support docs. | Target helper rationale; DialogPane support row | Implemented in target and DialogPane support. | Verified in changed target/DialogPane; validators `000000006732` and `000000006736` ok. |
| C7 | Source-facing call should be `DialogPane::SetHoverControl(controlId)`. | High | Current `by-class/DialogPane.md` declaration; sibling NewArticle formal C++; helper behavior. | Target formal C++; class/file route notes | Implemented in formal C++ and support docs. | Verified in target/generated source; validators `000000006732`-`000000006734` ok; generated source header `000000006734` emits UID0002UN. |
| C8 | Owner/emitter should remain [UID:000098]. | High | Current target metadata; class/file docs; vtable-family docs; data xref slot in NewPredefined table. | Target metadata | Already present and preserved. | Verified unchanged in target; validator `000000006732` ok. |
| C9 | Score should improve to `90/92`. | Medium-high | Blockers resolved; exact body/range/vtable/helper evidence; remaining name originality uncertainty. | Target score metadata | Implemented. | Validator `000000006732` reports `completion_update 90` and `confidence_update 92`; generated coverage reflects `90% : very-strong`. |
| C10 | Aggregate UID0000ZL support sync should be coordinated with B011. | High | Supervisor explicitly assigned B011 to aggregate UID0000ZL and callback excluded aggregate edits. | Support docs/follow-up | Not applied by scope; recommendation remains for supervisor/B011 coordination. | Verified no aggregate edit performed in this callback. |

## Positive Evidence Summary
- Direct facts supporting the recommendation:
  - MCP confirms exact 9-byte target and four-instruction wrapper.
  - MCP confirms vtable-only data xref at `0x006140a8`.
  - MCP confirms helper behavior as active/hover control-id update through `this+0x214`.
  - MCP confirms sibling `0x004772e0` has the identical four-instruction wrapper shape and its source report already emits `NewArticleDialog::SetHoverControl(int controlId)`.
- Corroborating documentation/generated evidence:
  - `by-class/DialogPane.md` already declares `void SetHoverControl(int controlId);`.
  - `by-type/by-struct/DialogPaneLayout.md` names `+0x214` as `m_activeControlId`.
  - `by-class/NewPredefinedFormArticleDialog.md` already lists the UID0002UN child as `SetHoverControl`.
  - `by-file/NewPredefinedFormArticleDialog.md` provides the correct source file route.
- Strongest inference chain: vtable slot `0x006140a8 -> sub_478370`; `sub_478370` tail-jumps to `sub_49FC00`; `sub_49FC00` is the accepted `DialogPane::SetHoverControl(int)` helper; the sibling NewArticle wrapper is already emitted with the same method name. That is sufficient for the NewPredefined child's exact forwarding C++.

## IDA MCP Facts
- Function/range facts:
  - `lookup_funcs 0x00478370`: `sub_478370`, size `0x9`.
  - `lookup_funcs 0x00478379`: not a function.
  - Target disassembly:
    - `478370 push ebp`
    - `478371 mov ebp, esp`
    - `478373 pop ebp`
    - `478374 jmp sub_49FC00`
  - Target decompile: `void __thiscall sub_478370(int this, int a2) { sub_49FC00(this, a2); }`
- Data/table/padding facts:
  - Raw bytes from `0x00478363`: thirteen `0xcc` bytes before target, then `55 8b ec 5d e9 87 78 02 00`, then seven `0xcc` bytes after target.
  - Raw bytes at `0x006140a8`: `70 83 47 00`, little-endian `0x00478370`.
- Xref facts:
  - `xrefs_to 0x00478370`: one xref, data at `0x006140a8`, `more=false`, `xref_count=1`.
  - Target `callees` returns an empty list because the relationship is a tail jump, but the disassembly/decompile refs identify `sub_49FC00`.
  - Helper xref sample includes `0x00478374` from `sub_478370` and sibling `0x004772e4` from `sub_4772E0`.
- Helper facts:
  - `lookup_funcs 0x0049fc00`: `sub_49FC00`, size `0x4c`.
  - Helper disassembly reads `[esi+214h]`, fetches controls through `[esi+1FCh]`, invokes virtual slots `[eax+58h]` and `[eax+5Ch]`, writes `[esi+214h] = edi`, and returns with `retn 4`.
  - Helper decompile uses decimal offsets `508` and `532`, matching `+0x1fc` and `+0x214`.
- Sibling facts:
  - `0x004772e0` size `0x9`, same body shape, vtable data xref at `0x00614008`, and decompile `sub_49FC00(this, a2);`.
- Negative IDA facts:
  - No ordinary code xrefs to target.
  - No function starts at the end address `0x00478379`.
  - No additional code exists inside the child range beyond the four instructions.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00478370-0x00478379` | UID0002UN / target path | NewPredefined hover-control vtable wrapper | True | [UID:000098] | Current `85/90`; recommend `90/92` | Source-ready after report approval. |
| `0x0049fc00-0x0049fc4c` | DialogPane helper support | Inherited helper called by target | Support helper | DialogPane | N/A in this report | Name/behavior sufficient: `DialogPane::SetHoverControl(int)`. |
| `0x004772e0-0x004772e9` | NewArticle sibling support | Identical sibling wrapper | True in sibling report | NewArticleDialog | N/A in this report | Corroborates method name/body style. |
| `0x004777a0-0x00478f8e` | UID0000ZL aggregate | NewPredefined aggregate container | True aggregate | [UID:000098] | Current aggregate scope | B011-owned; only support-row sync recommended. |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x006140a8` | data xref to `0x00478370` | UID0002UN is vtable-referenced, not ordinary code-called. |
| `0x00478374` | tail `jmp sub_49FC00` | Exact body forwards to inherited DialogPane helper. |
| `0x0049fc00` helper xref sample | includes `0x00478374` and sibling `0x004772e4` | Target and sibling share the same helper route. |
| `0x00614008` | data xref to sibling `0x004772e0` | Sibling vtable wrapper corroborates shape/name. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - Target page already has exact range, owner/emitter [UID:000098], reconstructable true, vtable-only xref, and tail-jump body.
  - `by-class/NewPredefinedFormArticleDialog.md` lists UID0002UN as `SetHoverControl` and routes through the NewPredefined class.
  - `by-file/NewPredefinedFormArticleDialog.md` routes the class to `NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp`.
  - `by-class/DialogPane.md` declares `void SetHoverControl(int controlId);`.
  - `by-type/by-struct/DialogPaneLayout.md` defines `m_activeControlId` at `+0x214`.
  - `by-memory/0x00476c10-0x00477790.NewArticleDialogCore.md` and B005 report provide formal sibling C++ using `DialogPane::SetHoverControl(controlId)`.
- Existing docs that are stale, incomplete, or contradicted:
  - Target's final-C++ blocker is stale because the source-facing virtual/helper names now have support evidence.
  - `by-memory/0x0049d8a0-0x0049feae.DialogPane.md` has older wording around `0x0049fc00` as a rect/position writer; current MCP and support reports supersede that for this helper.
  - Generated output still has an empty emitter marker for UID0002UN and should refresh after implementation.
- Generated/coverage report state:
  - `auto-generated/-ag-research-tracker.md`: `85/90`, average `87.5`, code count `0`.
  - `auto-generated/-ag-coverage-report-by-memory.md`: reconstructable, emits_code false/current summary.
  - `auto-generated/-ag-memory-coverage.md`: marks route to generated NewPredefined file but generated code is currently empty for this UID.

## Ranked Ownership Analysis

### 1. [UID:000098] NewPredefinedFormArticleDialog
- Evidence for: current target metadata; class method table row; by-file route; vtable data xref; vtable-family support; adjacent aggregate coverage; source sibling shape.
- Evidence against: no ordinary code callers, but that is expected for a vtable child and not ownership-negative.
- Decision: keep as owner/emitter and add exact child method C++.

### 2. DialogPane
- Evidence for: `sub_49FC00` is a DialogPane helper and the actual behavior lives in inherited state.
- Evidence against: target address `0x00478370` is a class-specific vtable wrapper at NewPredefined's table slot; putting the wrapper body on DialogPane would lose the override/slot evidence.
- Decision: use `DialogPane::SetHoverControl(controlId)` only as the called inherited helper; do not reassign UID0002UN to DialogPane.

### 3. UID0000ZL aggregate / vtable-family docs
- Evidence for: aggregate and vtable docs contain the broader table/range context.
- Evidence against: B011 owns aggregate UID0000ZL, and UID0002UN is already an exact child with a valid class/file route.
- Decision: do not move or broaden this report. Recommend only coordinated aggregate support-row synchronization after supervisor approval.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: no new file or grouping. Use existing `NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp`.
- Likely full contents: one method in the existing class implementation file.
- Candidate related items rejected: shared helper body `0x0049fc00` belongs to DialogPane support, not this file; aggregate UID0000ZL remains B011 scope.
- Standalone, narrow, or broad source-file inference: narrow class-method emission in the existing source root.

## Source Placement
- Recommended source file/class/global/module placement: `NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp`, method `NewPredefinedFormArticleDialog::SetHoverControl`.
- Why this placement fits source-tree and subsystem context: the target is a NewPredefined vtable slot, parent class [UID:000098] routes to file [UID:0000LT], and the source body only forwards to an inherited DialogPane method.
- Rejected placements and why:
  - `DialogPane.cpp`: rejected because this exact address is a NewPredefined wrapper, not the shared helper body.
  - Vtable-family/type docs only: rejected because the body is reconstructable C++ and the class/file route exists.
  - Aggregate UID0000ZL only: rejected because an exact child target exists and B011 owns aggregate synchronization.
- Remaining placement uncertainty: none that blocks first-draft C++; only original symbol-name proof remains unavailable.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: `0x00478370` starts the function, `0x00478379` is not a function, and raw bytes show `0xcc` padding before and after the 9-byte wrapper.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: none.
- Padding/table/data/code distinctions: code range is exactly `55 8b ec 5d e9 87 78 02 00`; vtable data slot `0x006140a8` contains the little-endian pointer to the code.
- Parent/container impact: aggregate/class docs should mark this child as source-ready when implementation is approved, but no range split is needed.

## Negative Evidence Summary
- No ordinary code callers were found for `0x00478370`; this supports vtable-only method status rather than non-live code.
- `callees` returns no modeled callees for target because the transfer is a tail jump; this does not contradict disassembly/decompile refs to `sub_49FC00`.
- `0x00478379` is not a function and the following bytes are `0xcc`, so there is no hidden second body or fallthrough work.
- `sub_49FC00` should not be renamed as a rect/position writer for this use. Live helper evidence shows active/hover control-id update.
- The lack of PDB/original symbol proof prevents a near-perfect name score, but the project-supported source-facing name is strong enough for C++.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments: use source docs/C++ names `NewPredefinedFormArticleDialog::SetHoverControl(int controlId)` and `DialogPane::SetHoverControl(int controlId)`.
- Evidence for each proposed name/type/comment: vtable child route, current DialogPane declaration, sibling formal C++, and helper offset/virtual-call behavior.
- Items intentionally left unchanged and why: no IDA DB rename/type/comment edit is requested in this report-only pass.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes. The target is `RECONSTRUCTABLE:TRUE`, has nonblank emitter [UID:000098], current average score is above 85, source route is valid, and direct helper/name evidence is now sufficient.
- Recommended code:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void NewPredefinedFormArticleDialog::SetHoverControl(int controlId)
{
    DialogPane::SetHoverControl(controlId);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive, when applicable: not applicable.
- Reason it preserves exact original behavior: the compiled wrapper only passes `this` and the single int argument to `sub_49FC00`; the proposed code calls the accepted inherited `DialogPane::SetHoverControl(int)` with the same argument and no extra logic.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: the method is a virtual/override forwarding shim in a derived dialog class, matching the already accepted NewArticle sibling wrapper.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `NewPredefinedFormArticleDialog`, `DialogPane`, `SetHoverControl`, and `controlId` replace `sub_478370`, `sub_49FC00`, and `a2`.
- Naming/coding style convention used and evidence for consistency: class-method style matches existing project by-file output and sibling `NewArticleDialog::SetHoverControl`.
- Reason code should remain blank, if applicable: not applicable; previous blank-code blocker is resolved.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation
- Exact changes applied or recommended: implemented target formal C++ block, MCP evidence notes, helper/source-name rationale, sibling precedent, negative evidence, historicalized blank-C++ blocker, and target score `90/92`.
- Exact parent assignments applied or recommended: preserved `CANONICAL_OWNER:000098` and `EMITTER_UIDS:000098`.
- Exact items left no-owner/non-emitting and why: none for UID0002UN. DialogPane aggregate remains blank/non-duplicate aggregate C++; only its stale `0x0049fc00` helper wording was corrected.
- Exact future work outside this assignment scope: aggregate UID0000ZL synchronization remains supervisor/B011 scope and was not edited in this callback.

## Recommended Target Doc Changes
- Target path: `source-3/project-documentation/by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md`
- Exact report facts to incorporate:
  - MCP session `supervisor_recovery_20260705` confirms `sub_478370` size `0x9`, exact disassembly, one data xref at `0x006140a8`, and no function at `0x00478379`.
  - Raw slot bytes `70 83 47 00` at `0x006140a8` point to `0x00478370`.
  - Helper `sub_49FC00` is `DialogPane::SetHoverControl(int controlId)` by live behavior and current DialogPane support docs.
  - Sibling `0x004772e0` has identical wrapper shape and source precedent.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - Change `COMPLETION` from `85` to `90`.
  - Change `CONFIDENCE` from `90` to `92`.
  - Leave `RECONSTRUCTABLE:TRUE`.
  - Leave `CANONICAL_OWNER:000098`.
  - Leave `EMITTER_UIDS:000098`.
  - Insert the formal C++ block from `First-Draft C++ Recommendation`.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - Preserve vtable-only/no ordinary callers as expected behavior.
  - Replace old "virtual name/shared helper declaration blockers" with a historical note that they are now resolved.
  - Preserve that the source-facing name is inferred/project-supported rather than original symbol-proof.

## Recommended Support Doc Changes
- Support path: `source-3/project-documentation/by-class/NewPredefinedFormArticleDialog.md`
  - Exact report facts to incorporate: UID0002UN `SetHoverControl` is source-ready and emits `void NewPredefinedFormArticleDialog::SetHoverControl(int controlId)` forwarding to `DialogPane::SetHoverControl(controlId)`.
  - Metadata/link/score/coverage/source-placement changes: keep class/file route; update method row/status only as needed.
- Support path: `source-3/project-documentation/by-file/NewPredefinedFormArticleDialog.md`
  - Exact report facts to incorporate: include UID0002UN among the source-ready class children in the NewPredefined dialog source root.
  - Metadata/link/score/coverage/source-placement changes: no file path change.
- Support path: `source-3/project-documentation/by-memory/0x004777a0-0x00478f8e.NewPredefinedFormArticleDialog.md`
  - Exact report facts to incorporate: child row for UID0002UN can reflect source-ready exact child status after supervisor approval.
  - Metadata/link/score/coverage/source-placement changes: coordinate with B011 because the aggregate is separately assigned.
- Support path: `source-3/project-documentation/by-memory/0x0049d8a0-0x0049feae.DialogPane.md`
  - Exact report facts to incorporate: stale `0x0049fc00` helper wording should be corrected or superseded to `DialogPane::SetHoverControl(int controlId)` / active hover-control id updater, using `+0x1fc` manager and `+0x214` active-control slot evidence.
  - Metadata/link/score/coverage/source-placement changes: optional support sync only; not required to add UID0002UN code.
- Support paths with no required edit: `by-class/DialogPane.md` and `by-type/by-struct/DialogPaneLayout.md` already carry the support declaration/field naming required by this report.

## Score And Metadata Recommendation
- Current score/metadata: `85/90`; `RECONSTRUCTABLE:TRUE`; `CANONICAL_OWNER:000098`; `EMITTER_UIDS:000098`; formal C++ blank.
- Recommended score/metadata: `90/92`; leave reconstructable/owner/emitter unchanged; add formal C++.
- Score rationale and reason not higher/lower:
  - Higher than current because the exact body, padding, vtable slot, helper behavior, and sibling source precedent now remove the prior blank-code blocker.
  - Not higher than `90/92` because the source-facing method and parameter names are inferred from project support evidence rather than recovered original symbols.
  - Not lower because this is a tiny exact wrapper with one argument and no control-flow ambiguity.
- Score-improvement attempt:
  - Virtual/helper name blocker: checked DialogPane support docs, sibling report, and live helper decompile; resolved.
  - Caller/vtable blocker: checked target xrefs and vtable slot bytes; resolved as vtable-only.
  - Range/padding blocker: checked lookup at end address and raw bytes; resolved.
  - Source placement blocker: checked class/file docs and aggregate scope; resolved with B011 coordination note.
- Metadata fields to change or leave unchanged: change only score fields and formal C++ block; leave UID, range, owner, emitter, reconstructable, and source file route unchanged.

## Open Questions With Attempted Resolution
- Open question: is `SetHoverControl` the original method name?
  - Evidence checked: current `DialogPane` declaration, sibling formal C++, helper behavior, class method rows, and prior executed support reports.
  - Best supported resolution: use `SetHoverControl` as the project source-facing name. Original symbol proof is unavailable, so confidence remains below near-perfect.
- Open question: does the helper operate on focus/current-control state instead?
  - Evidence checked: helper disassembly/decompile, layout docs for `m_activeControlId`, and support report rejections.
  - Best supported resolution: no. It updates active/hover control id and toggles child state through virtual slots; focus/select-control names are rejected.
- Open question: should B012 update aggregate UID0000ZL?
  - Evidence checked: supervisor instruction says B011 owns aggregate UID0000ZL.
  - Best supported resolution: B012 should not edit the aggregate in report-only mode; only recommend a coordinated support sync.
- Questions remaining unresolved: no unresolved issue blocks first-draft C++. The only residual uncertainty is original symbol-name proof, which affects score but not body correctness.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Applicable: not required for this B012 report.
- File/placement: none.
- Exact replacement/insert/delete text: none. Validator-owned `auto-generated/-ag-*` reports should refresh from target/support metadata after supervisor-approved implementation; B012 must not write manual coverage or generated rows.
- Reason B agent must not apply it directly: supervisor explicitly prohibited coverage/generated edits and validator/lifecycle commands in this report-only pass.

## Follow-Up Actions
- Supervisor actions: perform Gate 2 claim-by-claim verification and then run supervisor-only report execution if accepted.
- A-agent actions: none requested by B012.
- B012 future research actions: none unless supervisor asks for repair. Do not expand into B011's aggregate assignment without explicit instruction.

## Confidence
- Recommendation confidence: high.
- Score confidence: medium-high for `90/92`.
- Remaining uncertainty: original symbol provenance for `SetHoverControl`/`controlId`; no body/range/source-route uncertainty remains.

## Validator Results
- Commands run from `source-3/project-documentation`:
  - `python .\tools\validator.py --mode file --file by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md --apply --queue-timeout 240`
    - command_id: `000000006732`
    - command_timestamp: `2026-07-05T03:51:08-04:00`
    - exit: `0`
    - ok: `1`
    - target updates: `completion_update 90`, `confidence_update 92`, `autogen_registry_update`, `reference_index_add` for `00003T`, `0001U4`, and `00030K`; generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-class/NewPredefinedFormArticleDialog.md --apply --queue-timeout 240`
    - command_id: `000000006733`
    - command_timestamp: `2026-07-05T03:51:10-04:00`
    - exit: `0`
    - ok: `1`
    - side effects: projected stats update and stats row updates for UID000098; generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-file/NewPredefinedFormArticleDialog.md --apply --queue-timeout 240`
    - command_id: `000000006734`
    - command_timestamp: `2026-07-05T03:51:12-04:00`
    - exit: `0`
    - ok: `1`
    - side effects: reference index add for UID0002UN, stats row update for UID0000LT, projected stats update; generated refresh deferred.
  - `python .\tools\validator.py --mode file --file by-memory/0x0049d8a0-0x0049feae.DialogPane.md --apply --queue-timeout 240`
    - command_id: `000000006736`
    - command_timestamp: `2026-07-05T03:51:24-04:00`
    - exit: `0`
    - ok: `1`
    - warnings: nine existing `missing_ref_uid` diagnostics for unrelated `0003KD`/`0003KF`/`0003KO`/`0003KP` references in the broad DialogPane aggregate; validator still returned `ok:1`.
- Generated refresh status:
  - Queue status `000000006740` at `2026-07-05T03:52:02-04:00` showed two queued and one processing generated-refresh jobs.
  - Queue status `000000006743` at `2026-07-05T03:52:24-04:00` showed one processing generated-refresh job.
  - Queue status `000000006745` at `2026-07-05T03:52:45-04:00` showed zero queued/processing generated-refresh jobs.
  - Read-only check: `auto-generated/NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp` header is `validator-command-id: 000000006734`, `validator-refreshed-at: 2026-07-05T03:51:12-04:00`, and now emits UID0002UN `NewPredefinedFormArticleDialog::SetHoverControl(int controlId)`.
  - Read-only check: `auto-generated/-ag-coverage-report-by-memory.md` marks UID0002UN `emits_code:true`, `90%`, `very-strong`; `auto-generated/-ag-research-tracker.md` shows `90/92`.
- Forbidden commands not run: no `execute_report`, no report execution dry-run/probe/status, no registry lifecycle command, no manual generated edit, no manual coverage edit, and no manual report move.

## Changed Files
- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/0002UN-NewPredefinedFormArticleDialogSetHoverControl-source-quality.md`
- Modified:
  - `source-3/project-documentation/by-memory/0x00478370-0x00478379.NewPredefinedFormArticleDialogSetHoverControl.md`
  - `source-3/project-documentation/by-class/NewPredefinedFormArticleDialog.md`
  - `source-3/project-documentation/by-file/NewPredefinedFormArticleDialog.md`
  - `source-3/project-documentation/by-memory/0x0049d8a0-0x0049feae.DialogPane.md`
  - `source-3/project-documentation/tools/leaser/Agents/Agent-B012/research/0002UN-NewPredefinedFormArticleDialogSetHoverControl-source-quality.md`
- Validator-owned side effects observed in validator output/read-only checks:
  - `auto-generated/NexusTK/ui/dialogs/NewPredefinedFormArticleDialog.cpp` refreshed by validator and now emits UID0002UN.
  - Validator reported `projected_stats_update`, stats/autogen registry updates, and generated coverage/tracker refresh. These were tool side effects, not manual edits.
- Renamed: none.
- Report execution: not run.
- Leases: B012 leased the four changed by-* files for the edit/validator batch; explicit unlease succeeded for all four, and final `python leaser.py B012 unlease` reported `B012: No active leases`.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation: completed by supervisor `GATE1_PASSED` callback.
- [x] Target/support docs to update: implemented target UID0002UN, class/file support rows, and DialogPane helper wording; aggregate UID0000ZL not applied by explicit B011 scope.
- [x] Current target state and actual evidence checked recorded: MCP target/helper/sibling facts, docs, generated reports, and negative checks are recorded in this report and incorporated into target/support docs.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: ledger updated with implemented/already-present/not-applied states.
- [x] Metadata/score changes to apply: target score `90/92` and formal C++ nonblank implemented; owner/emitter/reconstructable unchanged.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof after all reasonable current routes were exhausted: virtual/helper name, caller/vtable, range/padding, and source-placement blockers resolved; original symbol proof remains score cap only.
- [x] Owner/emitter/reconstructable changes to apply: none; [UID:000098] owner/emitter and reconstructable true preserved.
- [x] Split/rename/new-child changes to apply: none.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: source placement confirmed; no split/reclassification/IDA DB edit.
- [x] First-draft C++ or no-code proof to apply: exact formal C++ block applied to target.
- [x] Third-party import directive to apply or confirm not applicable, including exact `third_party_embeds/...` paths and confirmation that the multiline C++ block remains blank: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail: implemented in target, class, file, and DialogPane support docs.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: prior blank-C++ blocker historicalized/resolved; stale DialogPane helper wording corrected; focus/select-control/rect-writer alternatives rejected.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: none encountered in target-specific checks.
- [x] Open questions to close or document as evidence-backed unresolved: original symbol-name proof remains nonblocking and score-limiting only.
- [x] Validators to run: scoped validators `000000006732`, `000000006733`, `000000006734`, and `000000006736` ran with exit `0`, `ok:1`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: generated refresh queue settled by status `000000006745`; generated source emits UID0002UN; no manual supervisor-owned coverage text required.

Implementation callback pass:
- [x] Report accepted by supervisor for implementation: `GATE1_PASSED` callback received.
- [x] All accepted target/support doc details incorporated at report-level detail: target, class, file, and DialogPane support updates completed; aggregate excluded by supervisor scope.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason: target `90/92`, formal C++ applied, owner/emitter/reconstructable preserved, no split/rename; aggregate sync not applied because B011 owns UID0000ZL.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: vtable-only/no ordinary callers preserved; old blank-C++ blocker resolved; stale `0x0049fc00` rect/position wording corrected; focus/select-control alternatives rejected.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale: only original symbol spelling remains as score cap.
- [x] Validators run and results recorded: four scoped validators plus queue-status generated refresh checks recorded above.
- [x] Generated report refresh completed by validator or explicit manual supervisor-owned coverage/tracker text supplied/confirmed unchanged: queue empty at status `000000006745`; generated NewPredefined source header `000000006734` emits UID0002UN; generated coverage/tracker refreshed.
- [x] Remaining unapplied accepted items listed with exact blocker: only aggregate UID0000ZL support sync remains not applied by explicit supervisor/B011 scope.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B012","command_id":"000000006751","destination_path":"executed-b-agent-research/B012/0002UN-NewPredefinedFormArticleDialogSetHoverControl-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B012/research/0002UN-NewPredefinedFormArticleDialogSetHoverControl-source-quality.md","timestamp":"2026-07-05T03:58:36-04:00","uid":"0002UN"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
