** TARGET-REPORT-UID:0003N9 **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003N9 **
# 0003N9 ControlPaneDrawActiveFrameHelper Ownership / Split Research

## Finalized Report / Current Recommendation
- Current recommendation: keep [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](../../../../../by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) as `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and `RECONSTRUCTABLE:TRUE`.
- Final disposition: no split, rename, reclassification, parent repair, canonical owner, or emitter route is justified now. The best forced source candidate is [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) / [UID:0000IG][ControlPane](../../../../../by-file/ControlPane.md), but the assignment remains below gate because live IDA evidence still shows no function object, no xref to the helper start, no vtable slot, no raw pointer to the helper start, and no caller/entry mechanism.
- Required action: supervisor may replace the current manual `by-memory/-coverage-report.md` row with the B003 evidence-refresh row in this report. Target metadata should remain `COMPLETION:82`, `CONFIDENCE:84`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, and blank `EMITTER_UIDS`.
- Confidence: high that this exact 0x30-byte body is source-shaped ControlPane-like drawing code; high that no current owner/emitter route clears the strict gate; medium that the original source intent was a private `ControlPane` helper, because that is inferred from fields and adjacency rather than proven by an entrypoint.

## Supporting Research

## Target
- Target UID: `0003N9`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`
- Source queue/report rows: `auto-generated/-ag-memory-coverage.md` lists `0003N9` as `no-owner`; `tools/leaser/Agents/no_owner_b-agent-tracker.md` row `0003N9` assigns this B003 follow-up after the B002 `0002PD` split.
- Current supervisor classification: reconstructable `no-owner` / no-emitter below gate at about `82/84`.
- Current scores and parent state: target page is `COMPLETION:82`, `CONFIDENCE:84`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`. Candidate parent [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) and file [UID:0000IG][ControlPane](../../../../../by-file/ControlPane.md) are both documented above gate, but the child itself lacks entrypoint evidence.

## Executive Recommendation
- Keep `0003N9` as an exact source-shaped raw helper page, not a container and not ignored padding.
- Do not assign [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) yet. Its field/layout evidence is the strongest semantic match, but there is still no vtable slot, direct caller, function object, or raw pointer proving this helper is part of a reachable ControlPane method set.
- Do not add `EMITTER_UIDS:000038`. An emitter would mean the reconstructed `ControlPane` source must emit this source item; without a proven source-use or declaration context, that would be an owner assignment by another name.
- Do not create another split. IDA bytes and adjacent modeled functions confirm this is already an exact half-open child range: padding ends at `0x00494c50`, the helper returns at `0x00494c7f`, and [UID:000119][ProgressBarControlPaneConstructor](../../../../../by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md) begins at `0x00494c80`.
- The exact condition required to clear the remaining blocker is a real entry mechanism: code/data xref to `0x00494c50`, a vtable/table slot to `0x00494c50`, a raw function pointer to `0x00494c50`, a recovered caller/indirect-call target, or source-level evidence that the original `ControlPane` source intentionally retained an unreferenced private helper that must still be emitted.

## Supervisor Active Recheck
- Supervisor instruction: research UID `0003N9`, use IDA MCP/current documentation rather than only the B002 split report, determine whether it can clear `85/85` and route, or document exact blockers.
- Split requirement: no new split is required. This child was created by the B002 `0002PD` split, and B003 rechecked its boundaries rather than deferring the work.
- Source-bearing child coverage: the only in-scope source-bearing range is `0x00494c50-0x00494c80`. It is already exact and remains below gate with an evidence-backed blocker.

## Inference Research Guidance Check
- `inference_research.md` says source/file ownership should be treated probabilistically when no debug/source metadata exists, and weak adjacency must be combined with xrefs, initialization, table layout, and negative evidence.
- `by-structure.md` owner/emitter rules require a defensible direct parent and enough evidence for the child and direct parent to clear the `85/85` gate. A reconstructable no-owner item can have emitters only when source-use contexts are proven, such as pooled/shared literals or constants.
- Existing documentation assumptions treated as uncertain: the target page's `ControlPane` candidate owner, the B002 split report's raw-helper classification, and the proposed source-tree placement under `ui/core/ControlPane.cpp`. IDA facts confirm the field behavior and exact range, but not the entrypoint.
- Fact/inference split: exact bytes, function absence, xrefs, vtable absence, and raw pointer search are facts; `ControlPane` private-helper intent is inference; ButtonChoice/ProgressBar rejection is based on IDA/doc contradiction with their boundaries and vtables.

## Evidence Standards Used
- IDA MCP evidence used: `lookup_funcs`, `disasm`, `get_bytes`, `xrefs_to`, `callees`, `make_signature_for_range`, and vtable byte/range inspection already captured during this assignment.
- Documentation evidence used: target page `0003N9`, parent/container `0002PD`, ControlPane class/file docs, ControlPane vtable docs, neighboring `ControlPaneActivate` and `ControlPaneDeactivate` child pages, ProgressBar vtable/constructor docs, ButtonControl/ButtonChoice boundary docs, generated coverage, manual coverage, tracker row, and proposed source tree.
- Additional negative evidence: raw PE byte search for little-endian pointer value `0x00494c50` (`50 4c 49 00`) returned `count=0`.
- Evidence strength: strong for exact behavior and non-reachability in the current IDB; not strong enough for source ownership because the missing entrypoint prevents distinguishing an intentionally retained private helper from dead/orphaned source-shaped code.

## IDA MCP Facts
- Function/range facts:
  - `lookup_funcs` reports no IDA function object at `0x00494c50`.
  - `lookup_funcs` reports neighboring `sub_494C30` at `0x00494c30-0x00494c4a` and `sub_494C80` at `0x00494c80-0x00494daa`.
  - `disasm 0x00494c50` shows a complete body: `push esi`, save `ecx` as `this`, test bytes `this+0x101` and `this+0x102`, call `0x004b9660`, pass `this+0x44` to `0x004ba450`, then `pop esi; retn`.
- Data/table/padding facts:
  - `get_bytes` around `0x00494c40` shows `sub_494C30` returns at `0x00494c49`, six `0xcc` bytes occupy `0x00494c4a-0x00494c50`, the raw helper occupies `0x00494c50-0x00494c80`, and the ProgressBar constructor prolog begins at `0x00494c80`.
  - `make_signature_for_range 0x00494c50-0x00494c80` produced a unique signature for this raw helper body.
- Xref facts:
  - `xrefs_to 0x00494c50` returns no cross-references to the helper start.
  - Interior xrefs are internal branch/call-flow artifacts only; they do not prove an external caller or table entry.
  - `callees 0x00494c50` reports no function found because IDA has not modeled the helper as a function.
- Vtable/global/type facts:
  - ControlPane vtable docs [UID:0003J8](../../../../../by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md) and [UID:0003J9](../../../../../by-type/by-vtable/ControlPaneVtables.md) enumerate ControlPane vtable bases and slots, with no slot to `0x00494c50`.
  - ProgressBar vtable docs show inherited ControlPane slots and ProgressBar local slots, with no slot to `0x00494c50`.
- Negative IDA facts:
  - No IDA function object at the start.
  - No code/data xref to the start.
  - No vtable/table slot found in the documented ControlPane/ProgressBar vtables.
  - No raw little-endian pointer to `0x00494c50` found in the executable file bytes.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00494c4a-0x00494c50` | [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md) | Six `0xcc` bytes before helper | FALSE | none | `100/strong` | Already ignored padding; no change. |
| `0x00494c50-0x00494c80` | [UID:0003N9][ControlPaneDrawActiveFrameHelper](../../../../../by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) | Raw ControlPane-like active-frame helper | TRUE | none | `82/84` before, `82/84` after | Keep no-owner/no-emitter below gate. |
| `0x00494c80-0x00494daa` | [UID:000119][ProgressBarControlPaneConstructor](../../../../../by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md) | ProgressBarControlPane constructor | TRUE | ProgressBarControlPane candidate | `84/strong` documented | Successor boundary; does not absorb `0003N9`. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00494c50` | `xrefs_to`: none | No external code/data entrypoint to the helper start. |
| `0x00494c6a` | raw call to `0x004b9660` | Uses GrafPort draw-state/color helper; behavior evidence, not ownership proof. |
| `0x00494c79` | raw call to `0x004ba450` | Draws a rectangle frame for `this+0x44`; behavior evidence, not ownership proof. |
| ControlPane vtables `0x00617a8c-0x00617b30` | documented slots include neighboring ControlPane state helpers, not `0x00494c50` | Rejects a normal virtual-slot route. |
| ProgressBar vtable data `0x00617b30-0x00617bd4` | inherited ControlPane state helpers and ProgressBar local methods, not `0x00494c50` | Rejects ProgressBar virtual ownership. |
| Raw PE pointer search | `50 4c 49 00 count=0` | No obvious stored function pointer to the helper start anywhere in the executable image. |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion:
  - [UID:0003N9][target page](../../../../../by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) already records the exact raw helper body, ControlPane candidate, no function object, no xrefs, and below-gate score.
  - [UID:0002PD][ControlFamilyStateVirtualHelpers](../../../../../by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md) identifies this as the only unresolved source-shaped child after the split.
  - [UID:0003N6][ControlPaneDeactivate](../../../../../by-memory/0x00494c10-0x00494c2a.ControlPaneDeactivate.md) and [UID:0003N7][ControlPaneActivate](../../../../../by-memory/0x00494c30-0x00494c4a.ControlPaneActivate.md) prove that `this+0x102` is a neighboring ControlPane active/focus-like state byte controlled by modeled functions.
  - [UID:0003J8][ControlPaneVtableData](../../../../../by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md) and [UID:0003J9][ControlPaneVtables](../../../../../by-type/by-vtable/ControlPaneVtables.md) show ControlPane is above gate but do not route this helper.
- Existing docs that are stale, incomplete, or contradicted:
  - No current by-* page proves an entrypoint to `0x00494c50`.
  - Earlier broad ButtonChoice/ButtonControl language around this address neighborhood is contradicted by the repaired boundaries: ButtonChoice/ButtonControl raw helper families start later, and ProgressBar begins at `0x00494c80`.
- Generated/coverage report state:
  - `auto-generated/-ag-memory-coverage.md` lists `0003N9` as `no-owner`.
  - `by-memory/-coverage-report.md` currently has the B002 row that keeps `CANONICAL_OWNER:NONE` and blank emitters until stronger entrypoint evidence appears.

## Ranked Ownership Analysis

### 1. `CANONICAL_OWNER:NONE`, blank emitters, reconstructable raw helper
- Evidence for: direct IDA evidence lacks a function object, start xref, vtable slot, raw pointer, or caller; this is not a pooled literal/shared constant where source-use emitters can be proven without a canonical owner; the target is exact and source-shaped, so it should remain visible but unassigned.
- Evidence against: the body strongly resembles a `ControlPane` private drawing helper because it consumes `this+0x101`, `this+0x102`, `this+0x44`, and `this+0x70`, and it sits directly after ControlPane state helpers.
- Decision: accepted. This is the only route that satisfies the owner/emitter model without overclaiming.

### 2. [UID:000038][ControlPane](../../../../../by-class/ControlPane.md) / [UID:0000IG][ControlPane](../../../../../by-file/ControlPane.md)
- Evidence for: strongest semantic match; fields `+0x101` and `+0x102` are ControlPane-family state bytes; `this+0x44` is the inherited rectangle; neighboring exact children `0003N2-0003N7` route to ControlPane; the proposed source tree places `ControlPane.cpp` under reusable UI core.
- Evidence against: no IDA function object, no xref to `0x00494c50`, no ControlPane vtable slot, no raw pointer, and no caller. There is no source-use context proving the reconstructed `ControlPane` source must emit this helper.
- Decision: best forced candidate, but rejected for assignment until entrypoint evidence appears.

### 3. ButtonControlPane / ButtonChoice / related button-control family
- Evidence for: neighboring UI-control family area and later button/choice controls use similar active/visible state checks and GrafPort drawing helpers.
- Evidence against: repaired boundary work places ButtonChoice/ButtonControl source-bearing raw children later, starting after the ProgressBar constructor/draw area; this helper is before ProgressBar and immediately after base ControlPane state slots; Button docs reject this band as button ownership pollution.
- Decision: rejected.

### 4. [UID:0000AW][ProgressBarControlPane](../../../../../by-class/ProgressBarControlPane.md) / [UID:0000MT][ProgressBarControlPane](../../../../../by-file/ProgressBarControlPane.md)
- Evidence for: physical adjacency; ProgressBar constructor starts immediately after at `0x00494c80`.
- Evidence against: `0x00494c80` is a clean constructor boundary; ProgressBar vtables do not point to `0x00494c50`; ProgressBar-specific current/range fields are not used; the helper uses base ControlPane state and rectangle drawing instead.
- Decision: rejected.

### 5. New source file/grouping
- Proposed owner/name/path: none recommended. If forced, a speculative grouping would be a private ControlPane drawing-helper fragment inside `ui/core/ControlPane.cpp`, not a standalone source file.
- Likely full contents: no additional contents can be justified beyond this exact 0x30-byte raw helper.
- Candidate related items that belong: none newly recommended; neighboring modeled ControlPane state helpers already have exact pages and route to ControlPane.
- Candidate related items rejected: ProgressBar constructor/draw helpers, ButtonChoice/ButtonControl raw helpers, and later specialized control children have their own documented owners or candidate owners.
- Standalone, narrow, or broad source-file inference: a standalone file is not plausible; the only plausible source home is narrow/private ControlPane support, but it lacks an entrypoint.
- Decision: rejected as an actionable new owner.

## Negative Evidence Summary
- Checked start xrefs: none.
- Checked IDA function object: none.
- Checked raw helper bytes and boundaries: exact helper body, not padding and not part of ProgressBar constructor.
- Checked ControlPane vtable records: no slot to `0x00494c50`.
- Checked ProgressBar vtable records: no slot to `0x00494c50`.
- Checked raw executable bytes for a little-endian pointer to `0x00494c50`: none.
- Checked existing docs around ControlPane/ButtonChoice/ProgressBar boundary: current repaired docs support ControlPane semantics but not assignment.
- Consumer/callee evidence does not prove ownership: calls to GrafPort drawing helpers identify what the body does, but they are shared drawing services and not source owners of this raw helper.

## Final Recommendation
- Exact changes applied or recommended:
  - Applied: created this final B003 research report only.
  - Recommended target metadata: no change.
  - Recommended manual coverage row evidence refresh: replace the existing `0003N9` nested row under `0002PD` with the row below if the supervisor wants the B003 negative-evidence check recorded in `by-memory/-coverage-report.md`.
- Exact parent assignments applied or recommended:
  - No canonical owner assignment.
  - No emitter assignment.
- Exact items left no-owner/non-emitting and why:
  - `0003N9` remains no-owner/non-emitting because no source-use entrypoint is proven. `EMITTER_UIDS` are not justified under the owner/emitter model.
- Exact future work outside this assignment scope:
  - If a later IDA pass promotes `0x00494c50` to a function, recovers an indirect call, finds a table slot, or finds source/debug evidence tying this helper to `ControlPane`, reopen the assignment and raise/re-route then.

## Pending Coverage-Report Row For Supervisor Application

Placement context: in `by-memory/-coverage-report.md`, replace the existing `0003N9` row nested under [UID:0002PD][0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers], immediately after the ignored padding row for `0x00494c4a-0x00494c50` and before the next top-level `000118` row.

```markdown
        - [UID:0003N9][0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper](by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md) 0x00494c50-0x00494c80 | raw-helper | ControlPaneDrawActiveFrameHelper : reconstructable/no-owner : 82% : medium-strong : B003 recheck keeps this exact raw helper below gate: source-shaped ControlPane-like drawing body checks `this+0x101` and `this+0x102`, selects color `0x80`, clears `this+0x70`, and calls the GrafPort frame drawer for `this+0x44`, but live IDA reports no function object, zero xrefs to `0x00494c50`, no ControlPane/ProgressBar vtable slot to `0x00494c50`, no executable raw pointer to the start, and no caller/entry mechanism. Keep `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and `RECONSTRUCTABLE:TRUE`.
```

## Follow-Up Actions
- Supervisor actions:
  - Update tracker row `0003N9` as B003 complete, recommendation `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, `RECONSTRUCTABLE:TRUE`, below gate `82/84`.
  - Optionally apply the coverage-report replacement row above. Do not change `auto-generated/-ag-memory-coverage.md` directly.
- A-agent actions:
  - No immediate A-agent documentation edit is required unless the supervisor wants the target page to mirror the raw-pointer/vtable negative-evidence expansion.
- B003 future research actions:
  - None for this target unless new xref/table/source evidence appears.

## Confidence
- Recommendation confidence: high.
- Score confidence: keep `82/84`. The recheck strengthens negative evidence but does not raise the page above the strict assignment gate.
- Remaining uncertainty: original source intent likely points to a private ControlPane helper, but the binary currently provides no entrypoint proof.

## Validator Results
- Commands run: none.
- Results: no validator run was required because no by-* target, child, parent, generated, project-level, or coverage-report file was edited.
- Any unresolved validator warnings/errors: none observed.
- Not used: no dry-run validator mode and no memory-range validator mode.

## Changed Files
- Created:
  - `tools/leaser/Agents/Agent-B003/research/0003N9-ControlPaneDrawActiveFrameHelper.md`
- Modified:
  - none outside the B003 research report.
- Renamed:
  - none.
- Moved to executed:
  - none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003N9","source_path":"executed-b-agent-research/B003/0003N9-ControlPaneDrawActiveFrameHelper.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
