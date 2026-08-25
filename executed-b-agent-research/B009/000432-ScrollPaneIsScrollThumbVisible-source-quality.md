** TARGET-REPORT-UID:000432 **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 000432 ScrollPaneIsScrollThumbVisible Source-Quality Research


## Finalized Report / Current Recommendation
- Current recommendation: keep UID000432 as `ScrollPane::IsScrollThumbVisible()` owned and emitted by [UID:0000CM][ScrollPane](../../../../by-class/ScrollPane.md), with source-file ancestor [UID:0000NF][ScrollBar](../../../../by-file/ScrollBar.md).
- Final disposition: no ownership, emitter, split, range, or C++ body change is needed; update the target page with fresh current MCP evidence and raise the target from `85/88` to `89/91`.
- Required action: implementation callback should edit only `by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md`, preserving the existing formal C++ body and adding the current MCP session facts, exact caller list, byte/padding proof, pointer-route negative check, and score rationale below.
- Confidence: high for exact behavior, range, caller set, owner/emitter route, and field roles; below final-audit `95+` because exact original member spellings and the complete hand-authored class declaration remain inferred from current documentation rather than recovered symbols.

## Supporting Research
- Lifecycle/status notes: Gate 1 passed and the supervisor issued an implementation callback for UID000432. B009 applied the accepted target-only update, ran the required scoped validator, released the target lease, and updated this report ledger/checklist for Gate 2 review.
- Prior lead report: executed B004 report `executed-b-agent-research/B004/0001GH-ScrollPaneInputCore-source-quality.md` created this child during the input-core split and supplied the current formal block `CXX-08`.
- Support leads: executed B010 `0001GI-ScrollPaneOnDraw-source-quality.md` and executed B009 `0001GK-ScrollPaneGetScrollPartRect-empty-emitter-source-quality.md` consume `IsScrollThumbVisible()` in first-draft draw and geometry code.
- Current MCP session used here: `31debdf2`, active IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, image base `0x400000`, server health `ok`, auto-analysis ready, Hex-Rays ready, strings cache ready.

## Target
- Target UID: `000432`.
- Target path: `by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md`.
- Source queue/report row: by-memory not-covered reconstructable row in `auto-generated/-ag-research-tracker.md`, score `85/88`, combined `86.5`, reports `0` at assignment.
- Current supervisor classification: report-only source-quality research; MCP evidence mandatory; no by-* edits or lifecycle commands allowed in this pass.
- Current scores and parent state: target `85/88`; direct class parent [UID:0000CM] `87/88`; source-file ancestor [UID:0000NF] `90/87`; split parent [UID:0001GH] `88/90`, non-emitting.

## Current Target State
- Existing metadata: `COMPLETION:85`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000CM`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CM`, `Nested:0`.
- Existing owner/emitter/reconstructable state: direct `ScrollPane` owner/emitter is correct; source-file route is `ScrollBar.cpp` through [UID:0000NF].
- Existing C++/emitter state: the target page already has a nonblank formal `RECONSTRUCTION_CPP CODE` block for `ScrollPane::IsScrollThumbVisible`, and this report recommends leaving that existing target formal block unchanged. This report intentionally does not restate the body as a standalone report-only C++ snippet.

- Existing open questions, blockers, placeholder names, stale assumptions, or contradictory claims: no active behavior blocker remains. Score is artificially low for the amount of current evidence because the page still cites older B004 evidence but lacks this fresh MCP session, the exact current xref list, and the negative pointer-route check.
- Related target/support docs checked: target page, [UID:0000CM] `ScrollPane`, [UID:0000NF] `ScrollBar`, [UID:0001GH] `ScrollPaneInputCore`, [UID:0001GI] `ScrollPaneOnDraw`, [UID:0001GK] `ScrollPaneGetScrollPartRect`, `by-memory/-ignored.md`, generated `auto-generated/NexusTK/ui/core/ScrollBar.cpp`, `auto-generated/-ag-memory-coverage.md`, and `auto-generated/-ag-research-tracker.md`.
- Current artifact/lifecycle status: this report is active under `tools/leaser/Agents/Agent-B009/research/`; no report execution/archive/lifecycle command has been run.

## Executive Recommendation
- Best direct owner: [UID:0000CM][ScrollPane](../../../../by-class/ScrollPane.md). The method reads only `ScrollPane` state at `+0x102` and `+0x100`, has no callees, and is called only by `ScrollPane` draw/geometry methods.
- Target disposition: keep assigned, reconstructable, and emitted through `ScrollPane`; keep path/name `ScrollPaneIsScrollThumbVisible`; keep existing formal C++ unchanged.
- Score disposition: raise to `89/91` after incorporating the current MCP evidence. Do not raise to `95+` because original symbol names for `m_enabled` and `m_scrollRange` remain inferred source-facing names, and final class declaration/source-header shape is not audited here.
- Remaining blocked assignment condition: none for this target. Higher final-audit confidence would require a broader class declaration/name audit outside this report's narrow target scope.

## Supervisor Active Recheck
- Triggering instruction: the supervisor assigned Agent-B009 to produce a new report-only source-quality report for UID000432 and explicitly prohibited by-* edits, generated-file edits, project-level generated edits, lifecycle commands, archives, coverage-report edits, and supervisor-ledger edits.
- Split repair requirement: no new split repair is needed. UID000432 is already an exact child of the mixed [UID:0001GH] input-core corridor, and MCP reconfirms the function is bounded by padding and the successor `0x0055c400` function.
- Source-bearing children in scope: only UID000432 is in scope; surrounding siblings were used as support evidence and do not need edits for this recommendation.

## Inference Research Guidance Check
- `by-structure.md` and the B-agent workflow require exact-address MCP evidence, separation of facts from inference, and no reliance on generated output as authority. This report uses generated `ScrollBar.cpp` only as a freshness/emitter-output lead.
- Existing assumptions treated as uncertain until rechecked: the `0x1a` range, ten direct xrefs, field offsets, post/pre padding, and whether any data pointer route exists.
- Direct IDA fact: current MCP proves function size, bytes, branch logic, no callees, xrefs, and padding.
- Documentation evidence: current by-* docs already map `+0x100` to `m_scrollRange`, `+0x102` to `m_enabled`, and route the method through `ScrollPane`/`ScrollBar.cpp`.
- Inference: `IsScrollThumbVisible`, `m_enabled`, and `m_scrollRange` are source-facing names inferred from behavior and support docs, not recovered PDB symbols. They are strong enough for formal C++ because the body is tiny and source-shaped.
- Wave2/Wave3 status: no current Wave2/Wave3 instruction was used as evidence. `simroot_v2` is not needed for this target.

## Heuristic / Inference Reanalysis And Validation
- Field-role validation: MCP decompile and assembly both show `*(byte *)(this + 0x102)` gated before a signed positive test of `*(__int16 *)(this + 0x100)`. Support docs identify `+0x102` as enabled state and `+0x100` as scroll range. The existing names `m_enabled` and `m_scrollRange` remain the best source-facing names.
- Method-name validation: the method does not compute geometry or draw; it returns a boolean visibility predicate used by draw and rectangle geometry. `IsScrollThumbVisible()` is better than generic names like `CanScroll`, `HasRange`, or `IsEnabled` because both enabled state and positive range are required.
- Ownership validation: direct callers are `ScrollPane::OnDraw` and `ScrollPane::GetScrollPartRect`; there are no non-ScrollPane callers, callees, vtable slots, or data-pointer routes. This is a small ordinary `ScrollPane` method.
- Range validation: current MCP `lookup_funcs` reports `0x0055c3e0` as `sub_55C3E0`, size `0x1a`; `0x0055c3da` and `0x0055c3fa` are not functions; `0x0055c400` is successor `sub_55C400`, size `0x1ff`. Current `get_bytes` proves six `0xcc` bytes before and after the body.
- Rejected alternative `ScrollWidget` ownership: `ScrollWidget` siblings use nearby enabled/current/target fields, but this exact function is called by `ScrollPane` draw/geometry and is documented as using `ScrollPane` range/enable state. No `ScrollWidget` caller or route appears in current xrefs.
- Rejected alternative file-level-only ownership: [UID:0000NF] is the correct source-file ancestor but too broad as direct owner; class docs and direct callers support `ScrollPane`.
- Rejected no-code proof: existing formal C++ is exact, source-shaped, and emitted in generated `ScrollBar.cpp`; keeping the body blank would lose behavior that is fully modeled.
- Unresolved issues: exact original spellings of the fields and method are not proven by symbols. This caps score below final audit but does not block the current owner/emitter/C++ recommendation.

## Evidence Standards Used
- Evidence types used: current IDA MCP health, exact `lookup_funcs`, targeted `analyze_function`, targeted `decompile`, targeted `disasm`, bounded `xrefs_to`, targeted `callees`, small `get_bytes` windows, bounded `find_bytes` pointer searches, current by-* docs, generated coverage/output leads, and old executed reports as leads.
- Evidence strength: high because independent MCP calls agree on the exact range and predicate, direct xrefs identify only `ScrollPane` callers, and support docs already resolve field roles.
- Evidence limitations: MCP does not recover original member names; generated output is validator output, not proof; broader class declaration/source-header finalization remains outside this target pass.

## Evidence Checked
- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `server_health` on database `31debdf2`: `ok`, auto-analysis ready, Hex-Rays ready.
  - `lookup_funcs` for `0x0055c3e0`, `0x0055c3da`, `0x0055c3fa`, and `0x0055c400`.
  - `analyze_function include_asm=true` for `0x0055c3e0`.
  - `decompile include_addresses=false` for `0x0055c3e0`.
  - `disasm max_instructions=40 include_total=true` for `0x0055c3e0`.
  - `xrefs_to 0x0055c3e0 limit=30`.
  - `callees 0x0055c3e0 limit=20`.
  - `get_bytes` for `0x0055c3da` size `6`, `0x0055c3e0` size `26`, and `0x0055c3fa` size `6`.
  - `find_bytes` for `E0 C3 55 00` and `E0 C3 15 00`, limit `30`.
- by-* docs, support docs, old reports, generated reports, and trackers checked: target page, `ScrollPane.md`, `ScrollBar.md`, `ScrollPaneInputCore.md`, `ScrollPaneOnDraw.md`, `ScrollPaneGetScrollPartRect.md`, `by-memory/-ignored.md`, executed B004 input-core report, executed B010 draw report, executed B009 geometry report, generated `ScrollBar.cpp`, generated memory coverage, and research tracker.
- Negative checks performed: `callees` returned none; `find_bytes` found zero VA/RVA pointer matches; xrefs came only from `sub_55C650` and `sub_55D9E0`; padding bytes before/after are all `0xcc`; `0x0055c3da` and `0x0055c3fa` are not function starts.
- Failed, unavailable, or intentionally skipped checks and why: no broad list/search/callgraph/type/batch-analysis calls were used because exact-address MCP evidence was sufficient and the assignment required narrow MCP discipline.

## Claim And Incorporation Ledger
| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | UID000432 is exact function `sub_55C3E0`, range `0x0055c3e0-0x0055c3fa`, size `0x1a` / 26 bytes. | High | MCP `lookup_funcs`, `analyze_function`, `disasm`, `get_bytes` | Target Status / Behavior And Evidence | incorporate | applied: target Status and Behavior sections now record current MCP session `31debdf2`, exact range, function size, successor lookup, and byte evidence |
| C002 | The behavior returns true only when the enabled byte is set and the signed scroll-range word is positive. | High | MCP decompile and assembly; support docs field map | Target Behavior And Evidence / C++ | already-present | already-present: formal C++ block was preserved unchanged; target Behavior section now restates the byte `+0x102` and signed word `+0x100` MCP predicate evidence |
| C003 | There are ten direct code xrefs: eight from `sub_55C650` (`ScrollPane::OnDraw`) and two from `sub_55D9E0` (`ScrollPane::GetScrollPartRect`). | High | MCP `xrefs_to 0x0055c3e0 limit=30` | Target Behavior And Evidence / Cross-References | incorporate | applied: target Behavior section now has the full ten-row xref inventory with addresses and caller functions |
| C004 | The function has no callees and no VA/RVA pointer-byte route found for `0x0055c3e0`. | High | MCP `callees`; bounded `find_bytes` | Target Negative Evidence / Score Rationale | incorporate | applied: target Behavior section now records empty `callees` and zero matches for `E0 C3 55 00` / `E0 C3 15 00` |
| C005 | Pre-body `0x0055c3da-0x0055c3e0` and post-body `0x0055c3fa-0x0055c400` are six-byte `0xcc` alignment rows. | High | MCP `get_bytes`; `by-memory/-ignored.md` | Target Behavior And Evidence / Cross-References | incorporate | applied: target Behavior section now records both six-byte `0xcc` padding windows and the rejected merge/split alternatives |
| C006 | Owner/emitter should remain `0000CM`; reconstructable remains `TRUE`; formal C++ remains unchanged. | High | Current docs, direct caller set, generated `ScrollBar.cpp`, MCP behavior | Target metadata / C++ | already-present | already-present: target metadata still has `CANONICAL_OWNER:0000CM`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CM`, `Nested:0`; formal `RECONSTRUCTION_CPP CODE` block unchanged |
| C007 | Score should move from `85/88` to `89/91`. | Medium-high | Fresh current MCP evidence and no unresolved target-local blocker; exact names remain inferred | Target metadata / Score Rationale | incorporate | applied: target header now `COMPLETION:89` and `CONFIDENCE:91`; validator `000000005273` confirmed both updates |

## Positive Evidence Summary
- Direct facts supporting the chosen recommendation: MCP reconfirms the exact 26-byte function and simple predicate over offsets `+0x102` and `+0x100`; the body has no callees and direct caller set is limited to `ScrollPane` draw/geometry.
- Corroborating documentation/generated-report evidence: `ScrollPane.md` documents these fields and the child route; `ScrollBar.md` records UID000432 as a filled `ScrollPane` emitter; generated `ScrollBar.cpp` emits the same source-shaped C++.
- Strongest inference chain and why it is sufficient: enabled byte plus positive range determines whether a scrollbar thumb should exist; the predicate is consumed by drawing and geometry in exactly that role; therefore `ScrollPane::IsScrollThumbVisible()` with `m_enabled`/`m_scrollRange` is source-shaped and behavior-preserving.

## IDA MCP Facts
- Function/range facts: `lookup_funcs` reports `0x0055c3e0 -> sub_55C3E0`, size `0x1a`; `0x0055c400 -> sub_55C400`, size `0x1ff`; `0x0055c3da` and `0x0055c3fa` are not functions.
- Data/table/padding facts: `get_bytes` returns six `0xcc` bytes at both `0x0055c3da-0x0055c3e0` and `0x0055c3fa-0x0055c400`; the function bytes are `80 b9 02 01 00 00 00 74 0e 33 c0 66 3b 81 00 01 00 00 7d 03 b0 01 c3 32 c0 c3`.
- Xref facts: `xrefs_to` reports ten direct code xrefs with `more:false`: `0x55c71a`, `0x55c776`, `0x55cad3`, `0x55cb32`, `0x55d162`, `0x55d1be`, `0x55d41a`, and `0x55d475` in `sub_55C650`; `0x55da9c` and `0x55dba0` in `sub_55D9E0`.
- Vtable/global/type facts: no vtable slot or global pointer route was found for UID000432. It is called as a helper from source-authored `ScrollPane` methods.
- Negative IDA facts: `callees` returns an empty set; bounded `find_bytes` finds zero matches for `E0 C3 55 00` and `E0 C3 15 00`.

## Function / Child Inventory
| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0055c3e0-0x0055c3fa` | [UID:000432](../../../../by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md) | `ScrollPane` thumb-visibility predicate | TRUE | [UID:0000CM] `ScrollPane` | current `85/88`; recommended `89/91` | source-authored, formal C++ already present |
| `0x0055c3da-0x0055c3e0` | [UID:0000VN] `-ignored` | pre-body alignment | FALSE | none | n/a | all `0xcc` |
| `0x0055c3fa-0x0055c400` | [UID:0000VN] `-ignored` | post-body alignment before mouse handler | FALSE | none | n/a | all `0xcc` |

## Direct Xref / Caller Inventory
| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x55c71a` | call from `sub_55C650` | draw path tests whether to draw thumb/page pieces |
| `0x55c776` | call from `sub_55C650` | draw path repeat consumer |
| `0x55cad3` | call from `sub_55C650` | draw path repeat consumer |
| `0x55cb32` | call from `sub_55C650` | draw path repeat consumer |
| `0x55d162` | call from `sub_55C650` | draw path repeat consumer |
| `0x55d1be` | call from `sub_55C650` | draw path repeat consumer |
| `0x55d41a` | call from `sub_55C650` | draw path repeat consumer |
| `0x55d475` | call from `sub_55C650` | draw path repeat consumer |
| `0x55da9c` | call from `sub_55D9E0` | geometry path computes thumb/page rectangles only when visible |
| `0x55dba0` | call from `sub_55D9E0` | geometry path repeat consumer |

## Documentation Evidence And IDA Status
- Existing docs that support the conclusion: target page already states the predicate and ten code xrefs; `ScrollPane.md` maps fields and child route; `ScrollBar.md` records UID000432 as a filled `ScrollPane` emitter; parent [UID:0001GH] records the exact split.
- Existing docs that are stale, incomplete, or contradicted: no contradiction found. The target page is under-scored and should record this current MCP session and negative pointer-route proof.
- Generated/coverage report state: generated `auto-generated/NexusTK/ui/core/ScrollBar.cpp` has validator command `000000005245`, refreshed `2026-07-03T08:43:32-04:00`, and emits UID000432 as the `ScrollPane` thumb-visible predicate. Generated memory coverage marks UID000432 `coded`. Research tracker still shows reports `0`, as expected before this report is executed by a supervisor.

## Ranked Ownership Analysis

### 1. ScrollPane class [UID:0000CM]
- Evidence for: direct `ScrollPane` draw/geometry callers; support field map for `m_enabled` and `m_scrollRange`; current generated output emits as `ScrollPane::IsScrollThumbVisible()`; parent split assigns this exact child to `ScrollPane`.
- Evidence against: exact original symbol spelling is inferred, not recovered.
- Decision: accepted direct owner/emitter; keep `CANONICAL_OWNER:0000CM` and `EMITTER_UIDS:0000CM`.

### 2. ScrollBar source-file ancestor [UID:0000NF]
- Evidence for: `ScrollBar.cpp` is the source file for `ScrollPane`, `ScrollWidget`, and `ScrollablePane`; generated output places this method in `auto-generated/NexusTK/ui/core/ScrollBar.cpp`.
- Evidence against: source-file owner is too broad for direct ownership; the method is a class member with clear `ScrollPane` state and callers.
- Decision: keep as source-file ancestor only.

### 3. ScrollWidget class [UID:0000CP]
- Evidence for: nearby input-core siblings use similar offsets and enabled/current/target semantics.
- Evidence against: no direct xrefs from `ScrollWidget` methods; the method is called by `ScrollPane::OnDraw` and `ScrollPane::GetScrollPartRect`; support docs separate `ScrollWidget` children from this `ScrollPane` child.
- Decision: rejected.

### Proposed new file/grouping, if applicable
- Proposed owner/name/path: not applicable; no new file or grouping is recommended.
- Likely full contents: not applicable.
- Candidate related items that belong: current route already groups this with `ScrollPane` methods under `ScrollBar.cpp`.
- Candidate related items rejected: no unrelated items should be merged into this target.
- Standalone, narrow, or broad source-file inference: narrow class method inside existing broad `ScrollBar.cpp` source file.

## Source Placement
- Recommended source file/class/global/module placement: `NexusTK/ui/core/ScrollBar.cpp`, class `ScrollPane`.
- Why this placement fits source-tree and subsystem context: the method is consumed by the ScrollPane draw and geometry bodies in the same source-file route and uses class-local scroll state.
- Rejected placements and why: `ScrollWidget` is rejected due no caller/owner evidence; `TextEditPane` is rejected because it is only an indirect consumer through geometry paths, not owner; file-level-only direct ownership is too broad.
- Remaining placement uncertainty, if any: exact original header/class declaration placement is not finalized, but source-file/class route is strong.

## Range / Split / Padding / Reclassification Analysis
- Exact range/boundary facts: UID000432 remains exact half-open range `0x0055c3e0-0x0055c3fa`; IDA function size is `0x1a`.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner: no new child or merge. Keep adjacent `0xcc` ignored rows at `0x0055c3da-0x0055c3e0` and `0x0055c3fa-0x0055c400`.
- Padding/table/data/code distinctions: current MCP byte reads prove both adjacent six-byte windows are `0xcc` alignment padding, not source code.
- Parent/container impact: [UID:0001GH] remains a non-emitting split index; no parent metadata change required.

## Negative Evidence Summary
- No callees: the function is a pure predicate over two fields.
- No data/pointer route: bounded searches for VA and RVA pointer encodings found zero matches, so this is not a vtable/data-export target.
- No non-ScrollPane callers: xrefs are only from `ScrollPane::OnDraw` and `ScrollPane::GetScrollPartRect`.
- No split defect: pre/post bytes are padding, and successor `0x0055c400` is a separate `ScrollPane` mouse handler.
- No support-doc contradiction: current class/file/parent docs already agree with the route.

## IDA Rename / Type / Comment Recommendations
- Proposed source-facing names/types/comments: keep `ScrollPane::IsScrollThumbVisible()`, `m_enabled`, and `m_scrollRange`.
- Evidence for each proposed name/type/comment: predicate reads enabled byte and signed positive range; callers use it to decide thumb drawing and geometry; support docs already use those aliases consistently.
- Items intentionally left unchanged and why: do not rename IDA `sub_55C3E0` or apply IDA-side type/comment changes during this B-agent report-only pass.
- Whether IDA DB edits are safe, unsafe, or not requested: not requested; assignment is documentation research only.

## First-Draft C++ Recommendation
- Eligible for draft C++: yes; the target already clears the combined-score/emitter gate and already has formal C++.
- Recommended code: keep the existing target formal `RECONSTRUCTION_CPP CODE` block unchanged. This report does not supply replacement insertion text because no C++ change is recommended, and it intentionally omits any standalone report-only C++ snippet.

- Third-party import directive, when applicable: not applicable.
- Reason it preserves exact original behavior: MCP assembly returns false if byte `+0x102` is zero; otherwise it returns true only if signed word `+0x100` is greater than zero.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: a tiny `bool` class predicate with source-facing member names is more plausible than decompiler-style offset code or an artificial helper.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `m_enabled` for byte `+0x102`; `m_scrollRange` for signed word `+0x100`.
- Naming/coding style convention used and evidence for consistency: existing `ScrollPane` generated and by-* docs use `m_` member names and method names like `SetSkinIndex`, `OnDraw`, `GetScrollPartRect`, and `OnMouseEvent`.
- Reason code should remain blank, if applicable: not applicable.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation
- Exact changes applied or recommended: target-doc evidence/score refresh was applied during the implementation callback.
- Exact parent assignments applied or recommended: keep direct owner/emitter [UID:0000CM] and source-file ancestor [UID:0000NF].
- Exact items left no-owner/non-emitting and why: none for UID000432.
- Exact future work, if any, outside this assignment scope: a later broad `ScrollPane` class declaration final-audit could attempt to move class/member names toward `95+`; it is not needed before accepting this target update.

## Recommended Target Doc Changes
- Target path: `by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md`.
- Exact report facts to incorporate:
  - Record current MCP session `31debdf2`, health `ok`, active IDB path, and exact calls listed in `Evidence Checked`.
  - Add `lookup_funcs` facts for `0x0055c3e0`, `0x0055c3da`, `0x0055c3fa`, and `0x0055c400`.
  - Add decompile/assembly predicate over byte `+0x102` and signed word `+0x100`.
  - Add full xref inventory: eight xrefs from `sub_55C650` and two from `sub_55D9E0`.
  - Add `callees` empty result and zero VA/RVA pointer-byte matches.
  - Add pre/post padding bytes.
- Metadata/score/owner/emitter/reconstructable/C++ changes: change `COMPLETION:85` to `89`, change `CONFIDENCE:88` to `91`, keep `CANONICAL_OWNER:0000CM`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CM`, `Nested:0`, and the existing formal C++ block.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: preserve B004 as historical creation/source for `CXX-08`; preserve rejection of padding/merged-parent treatment; preserve no non-ScrollPane owner evidence.

## Recommended Support Doc Changes
- Support path: not applicable for this implementation callback.
- Exact report facts to incorporate: no support-doc edit is required. `ScrollPane.md`, `ScrollBar.md`, `ScrollPaneInputCore.md`, `ScrollPaneOnDraw.md`, and `ScrollPaneGetScrollPartRect.md` already contain the necessary route, field, and dependency facts at sufficient detail.
- Metadata/link/score/coverage/source-placement changes: none recommended for support docs.

## Score And Metadata Recommendation
- Current score/metadata: `85/88`, owner/emitter `0000CM`, reconstructable `TRUE`, formal C++ present.
- Recommended score/metadata: `89/91`, owner/emitter/reconstructable/C++ unchanged.
- Score rationale and reason not higher/lower: the target now has fresh current MCP proof for exact bytes, range, decompile, assembly, xrefs, no callees, no pointer route, and padding; support docs and generated output agree. The score should not remain `85/88` because no target-local evidence blocker remains. It should not exceed low 90s because original symbol spellings and complete source declaration shape remain inferred.
- Score-improvement attempt:
  - Range blocker: resolved by `lookup_funcs`, `disasm`, and `get_bytes`.
  - Ownership blocker: resolved by xrefs limited to `ScrollPane` draw/geometry and support docs.
  - Field-name blocker: reduced but not eliminated; names remain inferred, so cap below `95+`.
  - C++ blocker: resolved; existing formal block exactly matches current MCP behavior.
  - Pointer/vtable ambiguity blocker: resolved negatively by empty `callees` and zero pointer-byte matches.
- Metadata fields to change or leave unchanged: change only completion/confidence; leave all owner/emitter/reconstructable/nested/C++ metadata unchanged.

## Open Questions With Attempted Resolution
- Open questions found: whether UID000432 should emit as a `ScrollPane` method; whether `m_enabled`/`m_scrollRange` and thumb-visible semantics are source-quality; whether parent/support docs need follow-up; whether score can improve.
- Evidence checked for each: MCP exact-address facts, current support docs, old reports, generated output, and tracker/coverage rows.
- Best supported resolution or inference:
  - It should emit as `ScrollPane::IsScrollThumbVisible()`.
  - Existing field names and semantics are source-quality enough for formal C++.
  - No support-doc follow-up is needed.
  - Score should improve to `89/91`.
- Questions remaining unresolved: exact original symbol spellings and full class declaration remain unavailable in current evidence. This affects final-audit score only; it does not affect behavior, ownership, emitter route, or current formal C++ readiness.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text
- Applicable only when an explicit manual `-coverage-report.md` or supervisor-owned tracker row needs a change.
- File/placement: not applicable.
- Exact replacement/insert/delete text: none.
- Reason B agent must not apply it directly: no manual tracker/coverage edit is needed; validator-owned generated tracker rows refresh through supervisor lifecycle/validator commands.

## Follow-Up Actions
- Supervisor actions: Gate 2 review the applied target page, this updated report ledger/checklist, lease release, and scoped validator result; if accepted, supervisor owns report execution.
- A-agent actions: none.
- B009 future research actions: none for UID000432 unless supervisor requests implementation callback.

## Confidence
- Recommendation confidence: high.
- Score confidence: medium-high for `89/91`; the exact numeric score is a documentation-quality judgment, but the direction and owner/emitter/C++ decisions are well supported.
- Remaining uncertainty: exact original source spellings and complete class declaration shape.

## Validator Results
- Commands run: `python .\tools\validator.py --mode file --file by-memory\0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md --apply --queue-timeout 240`.
- Results: command id `000000005273`, timestamp `2026-07-03T09:31:44-04:00`, exit code `0`, `ok: 1`.
- Validator side effects reported: `completion_update 000432 ... 89`, `confidence_update 000432 ... 91`, `reference_index_add 0000CP ...`, `stats_incremental_noop`, `projected_stats_update`, and `generated_refresh: deferred` with generated refresh command id `000000005273` / timestamp `2026-07-03T09:31:44-04:00`.
- Any unresolved validator warnings/errors: none reported for the scoped target validation.

## Changed Files
- Created: `tools/leaser/Agents/Agent-B009/research/000432-ScrollPaneIsScrollThumbVisible-source-quality.md`.
- Modified by B009 implementation callback: `by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md` and this report.
- Validator-reported generated/project side effects: `project-level/-auto-completion-stats.md` projected path completion section update and deferred generated refresh under command `000000005273`; no generated or project-level files were edited by hand.
- Renamed: none.
- Report execution: not run. No `execute_report`, dry-run execution, archive move, lifecycle repair, registry command, or manual report move was run.

## Implementation Tracking Checklist
- [x] Supervisor validation required before implementation. Proof: supervisor reported this repaired report passed Gate 1 and issued the UID000432 implementation callback.
- [x] Target/support docs to update: updated only `by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md`; no support-doc edits were needed.
- [x] Current target state and actual evidence checked recorded: target now records current MCP session `31debdf2`, health/IDB state, lookup/decompile/disasm/xref/callee/bytes/find-bytes results.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: C001-C007 now record `applied` or `already-present` with target-specific proof.
- [x] Metadata/score changes to apply: target header now has `COMPLETION:89`, `CONFIDENCE:91`; validator `000000005273` confirmed both updates.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof after all reasonable current routes were exhausted: target Score Rationale now records range, ownership, caller, C++, padding, and pointer-route resolution; original spelling remains final-audit cap only.
- [x] Owner/emitter/reconstructable changes to apply: no changes applied; target still has `CANONICAL_OWNER:0000CM`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CM`, and `Nested:0`.
- [x] Split/rename/new-child changes to apply: none; target records rejected merge/split alternatives and preserved adjacent ignored padding rows.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: target preserves range and source placement; no IDA rename/type/comment requested.
- [x] First-draft C++ or no-code proof to apply: existing target formal `RECONSTRUCTION_CPP CODE` block was left unchanged; no replacement C++ insertion text was supplied or applied.
- [x] Third-party import directive to apply or confirm not applicable, including exact `third_party_embeds/...` paths and confirmation that the multiline C++ block remains blank: not applicable; this is not a third-party import target.
- [x] Exact target/support doc facts to incorporate at report-level detail: target now includes current MCP facts, full xref list, negative pointer/callee checks, padding proof, rejected alternatives, and score rationale; support docs were already sufficient and unchanged.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: target preserves B004 creation/CXX-08 history and adds rejected `ScrollWidget`/file-only/no-code/merge alternatives plus no pointer route and no non-ScrollPane callers.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: no Wave2/Wave3 evidence used; no edit needed.
- [x] Open questions to close or document as evidence-backed unresolved: target-local owner/emitter/C++ questions are closed; target score rationale documents original spelling/class declaration as final-audit cap only.
- [x] Validators to run: ran `python .\tools\validator.py --mode file --file by-memory\0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md --apply --queue-timeout 240`, command id `000000005273`, timestamp `2026-07-03T09:31:44-04:00`, exit `0`, `ok:1`.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: validator reported `generated_refresh: deferred`; no manual coverage/tracker text recommended or applied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000005280","destination_path":"executed-b-agent-research/B009/000432-ScrollPaneIsScrollThumbVisible-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/000432-ScrollPaneIsScrollThumbVisible-source-quality.md","timestamp":"2026-07-03T09:39:27-04:00","uid":"000432"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
