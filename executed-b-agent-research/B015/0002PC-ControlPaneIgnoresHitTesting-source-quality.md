** TARGET-REPORT-UID:0002PC **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0002PC ControlPaneIgnoresHitTesting Source-Quality Research

## Finalized Report / Current Recommendation

- Implemented recommendation: [UID:0002PC] `by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md` has been promoted from blank-C++ source-authored accessor to first-draft source-ready `ControlPane::IgnoresHitTesting`.
- Final disposition applied: direct owner and emitter route remain unchanged through [UID:000038] `ControlPane` and [UID:0000IG] `ControlPane.cpp`; the target formal C++ body now returns the supported `m_ignoreHitTesting` field.
- Callback action applied: target by-memory doc and support summaries in `by-class/ControlPane.md`, `by-file/ControlPane.md`, paired setter [UID:0003N5], and aggregate [UID:0002PD] were updated under short leases and scoped validators. Generated output and coverage reports were not hand-edited.
- Confidence: high for exact behavior, owner/emitter route, field role, and first-draft C++ readiness; exact original spelling and `const` qualification remain inferred, not PDB-proven.

## Supporting Research

- Current B015 assignment began as report-only research for Target UID `0002PC`. Supervisor Gate 1 passed on 2026-07-05 for this report at SHA256 `962EF92F2078971CE8991ED99D6D9291A4F41227D2D4FC94BD15A693516F9F2B`, and the implementation callback was then applied in this same report artifact without running report execution or archive/lifecycle commands.
- IDA MCP was available and responsive. The active session was `supervisor_recovery_20260705`, database `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready. This report is not fallback-only.
- The target is a two-instruction getter: `mov al, [ecx+104h]`; `retn`. Hex-Rays reports `return this[260]`; `260` is `0x104` (Verified with `int_convert.py`).
- The target has one direct code xref at `0x0049fb7f` inside `sub_49FB10`. The caller first checks point-in-rectangle through `sub_4B7E80`, then calls this accessor on the candidate control and accepts the candidate only when the accessor returns false.
- The paired setter [UID:0003N5] at `0x00494c00-0x00494c10` writes the same byte at `this+0x104`; current MCP decompilation reports `this[260] = a2`.
- The constructor [UID:0002PB] initializes the same byte through `mov word ptr [esi+103h], 0Ah`: byte `+0x103` becomes visual state `10`, byte `+0x104` becomes `0`. The accepted B007 constructor report and current generated `ControlPane.cpp` already use `m_ignoreHitTesting(false)`.
- Pre-callback generated output `auto-generated/NexusTK/ui/core/ControlPane.cpp` was refreshed by validator command `000000006798` at `2026-07-05T05:16:05-04:00`; it emitted the constructor with `m_ignoreHitTesting(false)` and still showed [UID:0002PC] as an empty emitter marker. Post-callback scoped validator refresh `000000006967` at `2026-07-05T10:49:28-04:00` now includes the UID0002PC getter.
- No active duplicate root report for `0002PC` was found. Prior executed reports that mention this target are B002 `0002PD` split repair, B003 `000114` source-routing cleanup, and B007 `0002PB` constructor source-quality work. They were used as leads and rechecked against current MCP where target behavior mattered.

## Target

- Target UID: `0002PC`.
- Target path: `by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md`.
- Source queue/report row before callback: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`; row showed `85/90`, average `87.5`, reconstructable, no emitted code. Post-callback target metadata and generated `ControlPane.cpp` are updated; final research-tracker execution/coverage state remains supervisor/validator-owned.
- Current supervisor classification: tiny ControlPane accessor with unresolved source-facing method/field naming and no standalone B report.
- Pre-callback scores and parent state: target `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000038`; parent [UID:000038] `ControlPane` was `86/88`, file route [UID:0000IG] `ControlPane` was `86/88`.
- Post-callback target state: target is `COMPLETION:88`, `CONFIDENCE:92`, owner/emitter/reconstructable unchanged, and formal C++ populated. Parent/file scores were not changed by B015.

## Current Target State

- Pre-callback metadata: `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000038`, blank optional emitter position.
- Current metadata after callback: `COMPLETION:88`, `CONFIDENCE:92`, `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000038`, blank optional emitter position.
- Owner/emitter/reconstructable state: correct and unchanged. The target is source-authored `ControlPane` behavior and routes through the `ControlPane` class to `NexusTK/ui/core/ControlPane.cpp`.
- C++/emitter state: pre-callback formal `RECONSTRUCTION_CPP CODE` block was blank and generated output had an empty emitter marker for [UID:0002PC]; post-callback target and generated `ControlPane.cpp` contain the first-draft getter.
- Open questions/blockers: exact original spelling and `const` remain inferred, but final-source blocker language about method/field names being too provisional is superseded. Current docs use `ControlPane::IgnoresHitTesting()` and field `m_ignoreHitTesting`.
- Related target/support docs checked: target page, [UID:0003N5] setter, [UID:0002PD] state-helper aggregate, [UID:0002PB] constructor, [UID:000038] class, [UID:0000IG] file, [UID:00011F] popup caller context, [UID:0003J9]/[UID:0003J8] vtable support, [UID:0001YC] vtable-family aggregate, `by-memory/-guidance.md`, and `by-structure.md`.
- Current artifact/lifecycle status: this is the active implemented report artifact at `tools/leaser/Agents/Agent-B015/research/0002PC-ControlPaneIgnoresHitTesting-source-quality.md`. Gate 1 passed before callback; accepted by-* edits, scoped validators, and checklist/ledger updates are now complete for supervisor Gate 2 review. No `execute_report`, dry-run/probing execute variant, registry lifecycle command, archive move, or manual report move has occurred for B015.

## Heuristic / Inference Reanalysis And Validation

The unresolved source-quality issue was not the binary behavior; it was whether the behavior and field names were strong enough for first-draft source. Current evidence supports resolving both.

| Issue | Best current disposition | Validation |
| --- | --- | --- |
| Method name | `ControlPane::IgnoresHitTesting()` | Existing target/class/file docs already use `IgnoresHitTesting`; B003 explicitly preferred this over `IsHitTestIgnored` because the paired setter page uses `SetIgnoreHitTesting`; current caller semantics are "skip this control during hit-test dispatch when true." |
| Return type | `bool` | Raw ABI returns `al`; field is a byte flag initialized to false and tested as a boolean predicate. Analogous project pages emit exact seven-byte byte-flag getters as `bool ...() const`; `char` would preserve ABI but is weaker source shape. |
| `const` qualifier | Include `const` in first-draft C++ | The target reads only `m_ignoreHitTesting`, has no callees, and changes no state. This is inferred source shape, not original-proof, but matches existing getter source style. |
| Field name | `m_ignoreHitTesting` | B007 constructor formal C++ already uses this name for the `+0x104` byte; current MCP confirms the getter reads it, the setter writes it, and the popup hit-test caller treats true as "ignore this candidate." |
| Owner/source route | Keep [UID:000038] `ControlPane`, emitted through [UID:0000IG] | The constructor initializes the field on base `ControlPane`, the setter is in the base vtable slot family, and derived controls only consume inherited behavior. |
| C++ readiness | Eligible and recommended | Target is reconstructable, has nonblank `EMITTER_UIDS`, routes to a valid file through [UID:000038]/[UID:0000IG], and current average score is already `87.5`, above the active `>85` code-entry gate. |
| Split/range | No split | MCP confirms exact `0x7` byte function bounded by `0xcc` padding; neighboring setter is already its own [UID:0003N5] child. |

Rejected alternatives:

- `IsHitTestIgnored`: plausible English but rejected for now because current docs and paired setter naming converge on `IgnoresHitTesting`.
- `m_hitTestingIgnored`: plausible but weaker than `m_ignoreHitTesting` because the constructor's accepted formal C++ already uses `m_ignoreHitTesting`.
- Direct ownership by `PopupMenuControlPane`: rejected because `sub_49FB10` is a consumer/caller over candidate controls, not the defining owner of the flag.
- Direct ownership by `RadioGroupControlPane`: stale Wave2-era wording found in old report text is superseded by current B002 vtable/source split. The setter belongs to base `ControlPane`.
- Keeping formal C++ blank: rejected because the named blocker is now resolved to first-draft source quality, not future-work uncertainty.

## Evidence Standards Used

- IDA MCP exact-address evidence: `lookup_funcs`, `get_bytes`, `xrefs_to`, `callees`, `disasm`, `decompile`, and `get_int` against session `supervisor_recovery_20260705`.
- Byte/boundary evidence: target bytes, pre/post `0xcc` padding, and setter bytes.
- Xref/caller evidence: one direct call at `0x0049fb7f` inside `sub_49FB10`; caller path checks rectangle hit first and uses the accessor as a skip gate.
- Paired-state evidence: constructor initializes `+0x104`, getter reads it, setter writes it.
- Documentation evidence: current by-* docs, executed B reports, generated `ControlPane.cpp`, and generated coverage/tracker rows.
- Negative evidence: no target callees, no additional target xrefs found by `xrefs_to(limit=20)`, no current source evidence for derived-class ownership, and no need to merge with the adjacent setter or aggregate page.

The evidence ladder is strong enough for first-draft source because every behavior claim is backed by current MCP and every naming claim has cross-document support. Exact original spelling is still not proven; that caps score below final audit but does not block source-quality C++.

## Evidence Checked

- MCP availability:
  - `initialize` succeeded.
  - `tools/list` succeeded and current schemas required `database`.
  - `idb_list` returned one active worker session: `supervisor_recovery_20260705`.
  - `server_health` returned `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`.
- MCP exact target calls:
  - `lookup_funcs(0x00494bf0, 0x0049fb10, 0x00494c00, 0x00494b50)`.
  - `get_bytes` for `0x00494bea`, `0x00494bf0`, `0x00494bf7`, and `0x00494c00`.
  - `xrefs_to(0x00494bf0, limit=20)`.
  - `callees(0x00494bf0, 0x0049fb10, 0x00494c00, limit=50)`.
  - `disasm`/`decompile` for `0x00494bf0`, `0x00494c00`, `0x0049fb10`, and `0x004949e0`.
  - `get_int` for `0x00617ad8`, `0x00617adc`, `0x00617ae0`, `0x00617ae4`, `0x00617ae8`, `0x00617aec`, and `0x00617af0`.
- Numeric conversion:
  - `python .\tools\int_convert.py` verified `260 == 0x104` and the decimal vtable-slot values returned by `get_int`.
- by-* docs checked:
  - `by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md`.
  - `by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md`.
  - `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`.
  - `by-memory/0x004949e0-0x00494a81.ControlPaneConstructor.md`.
  - `by-memory/0x00498040-0x00498599.PopupMenuControlPaneCore.md`.
  - `by-class/ControlPane.md`, `by-file/ControlPane.md`.
  - `by-type/by-vtable/ControlPaneVtables.md`, `by-memory/0x00617a8c-0x00617b30.ControlPaneVtableData.md`, and `by-type/by-vtable/PaneCoreVtableFamily.md`.
  - `by-memory/-guidance.md`, `by-structure.md`, `tools/int_convert_readme.md`.
- Generated/tracker evidence checked:
  - `auto-generated/-ag-research-tracker.md` target row.
  - `auto-generated/-ag-coverage-report-by-memory.md` and `auto-generated/-ag-memory-coverage.md` hits from `rg`.
  - `auto-generated/NexusTK/ui/core/ControlPane.cpp`.
- Existing report searches:
  - Search terms included `0002PC`, `00494bf0`, `494BF0`, `ControlPaneIgnoresHitTesting`, `IgnoresHitTesting`, `m_ignoreHitTesting`, `SetIgnoreHitTesting`, `0003N5`, `00494c00`, `ControlPane state virtual`, and `hit-test suppression`.
  - Opened directly relevant executed reports: B002 `0002PD-ControlFamilyStateVirtualHelpers-ownership-split-research.md`, B003 `000114-ControlPaneAndProgressBarPrelude-source-routing.md` matching sections, and B007 `0002PB-ControlPaneConstructor-source-quality.md`.
  - No active duplicate B report for [UID:0002PC] existed at the assigned B015 report path before this report was created.
- Failed, unavailable, or intentionally skipped checks:
  - No broad MCP list/search/callgraph/batch calls were used.
  - No IDA mutation, IDB save, rename, patch, type-apply, or process-management tool was used.
  - `source-3/simroot_v2` was not present at the searched path; current generated validator output was used as the generated source lead instead.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | [UID:0002PC] is exactly `0x00494bf0-0x00494bf7`, bytes `8a 81 04 01 00 00 c3`, bounded by `0xcc` padding. | High | Current MCP `lookup_funcs`, `get_bytes`, `disasm`. | Target `Boundary Evidence` / `IDA Evidence`. | incorporate | applied |
| C2 | The function reads byte `this+0x104` and returns it without callees. | High | Current MCP `disasm`, `decompile`, `callees`; `260 -> 0x104` verified with `int_convert.py`. | Target `Behavior`, field notes, and formal C++ block. | incorporate | applied |
| C3 | Sole caller `sub_49FB10` uses the result as a post-rectangle-test skip gate. | High | Current MCP `xrefs_to`, caller `disasm` and `decompile`. | Target `Behavior` / `IDA Evidence`; support class/file notes. | incorporate | applied |
| C4 | The field should be documented as `m_ignoreHitTesting`. | High | B007 constructor formal C++ and current MCP constructor/setter/getter evidence. | Target field notes; support class/file and setter page. | incorporate | applied |
| C5 | Best source-facing getter name is `ControlPane::IgnoresHitTesting()`. | Medium-high | Existing target/class/file docs, B003 name reanalysis, paired setter name, caller behavior. | Target status and formal C++ block; class/file support rows. | incorporate | applied |
| C6 | Target owner/emitter route through [UID:000038] and [UID:0000IG] should remain unchanged. | High | Current metadata, B002 split report, class/file docs, constructor/vtable context. | Target metadata and source placement. | already-present | already-present |
| C7 | Formal C++ should no longer stay blank. | High | Active by-structure code gate met; field/method blockers resolved to first-draft quality. | Target `RECONSTRUCTION_CPP CODE` block. | incorporate | applied |
| C8 | Recommended score should move from `85/90` to `88/92`. | Medium-high | Exact evidence, C++ readiness, remaining original-spelling caveat. | Target metadata and score rationale. | incorporate | applied |
| C9 | PopupMenu/RadioGroup/ProgressBar ownership alternatives are rejected. | High | Caller as consumer, stale Wave2 owner superseded, B002 split and ControlPane vtable/source context. | Target `Rejected Alternatives And Caveats`; support aggregate row keeps ControlPane source state. | incorporate | applied |
| C10 | Generated `ControlPane.cpp` previously had only an empty marker for [UID:0002PC] and should receive the getter after validation. | High | Pre-callback generated file command id `000000006798`; post-validator generated header command id `000000006967`, refreshed `2026-07-05T10:49:28-04:00`, now contains UID0002PC getter. | Target/support generated expectation and generated header check. | incorporate | applied |

## Positive Evidence Summary

- Direct facts supporting the recommendation:
  - `lookup_funcs` reports `sub_494BF0` at `0x494bf0`, size `0x7`.
  - `get_bytes` reports the target bytes as `0x8a 0x81 0x04 0x01 0x00 0x00 0xc3`, matching `mov al,[ecx+104h]` and `retn`.
  - `decompile` reports `return this[260]`; `260` is `0x104` (Verified with `int_convert.py`).
  - `xrefs_to` reports exactly one caller at `0x49fb7f` inside `sub_49FB10`.
  - The caller accepts a candidate only when point-in-rectangle is true and this accessor returns false.
- Corroborating documentation/generated-report evidence:
  - B002 split report already repaired [UID:0002PC] to [UID:000038] `ControlPane`.
  - B003 report explicitly preferred `ControlPane::IgnoresHitTesting()` over `IsHitTestIgnored()` and identified `+0x104` as `m_ignoreHitTesting` / hit-test suppression.
  - B007 constructor report and current generated `ControlPane.cpp` use `m_ignoreHitTesting(false)`.
  - The paired setter [UID:0003N5] writes the same byte and is already named `ControlPaneSetIgnoreHitTesting`.
- Strongest inference chain:
  - Constructor initializes `m_ignoreHitTesting` false, setter writes it, getter reads it, and caller suppresses hit-test selection when true. That complete read/write/use chain is stronger than the previous "provisional field name" blocker.

## Negative Evidence Summary

- No target callee exists, so the function is not a wrapper around another helper.
- The accessor's single caller is a consumer, not ownership proof for `PopupMenuControlPane`.
- Address adjacency to progress-bar helpers does not create progress ownership; B002 split evidence separated the mixed physical band into exact children.
- Stale Wave2-era `RadioGroupControlPane::SetIgnoreHitTesting` wording is rejected because current base ControlPane vtable/source docs supersede it.
- The setter's broad vtable/data fan-in does not make the getter virtual or multi-owner; it only proves the setter is inherited base state.
- Exact original spelling is not recovered from PDB/source symbols, so the score should not rise into final-audit `95+` territory.

## Ranked Ownership Analysis

### 1. [UID:000038] ControlPane class

- Evidence for: constructor initializes `+0x104`; paired setter is a base ControlPane state helper; class/file docs already route this target through ControlPane; target behavior is generic control hit-test state, not feature-specific popup behavior.
- Evidence against: method name and field name are inferred rather than original-symbol-proven.
- Decision: accepted. Keep `CANONICAL_OWNER:000038` and `EMITTER_UIDS:000038`.

### 2. [UID:0000IG] ControlPane source file

- Evidence for: source route is `NexusTK/ui/core/ControlPane.cpp`, parent file clears `86/88`, generated output already contains the constructor and empty marker for this target.
- Evidence against: by-structure direct-owner rule prefers the narrower class page when it clears the gate.
- Decision: accepted as emitter route through the class, rejected as direct canonical owner.

### 3. PopupMenuControlPane / caller owner

- Evidence for: sole direct caller is in the popup/menu hit-test region `sub_49FB10`.
- Evidence against: caller iterates candidate controls and consults inherited control state; it does not own the field or accessor. The accessor has generic ControlPane field semantics.
- Decision: rejected.

### 4. RadioGroupControlPane / stale setter owner

- Evidence for: stale Wave2 report text used a RadioGroup setter name.
- Evidence against: current B002 split and ControlPane vtable evidence supersede that route; [UID:0003N5] is now a base ControlPane setter.
- Decision: rejected as stale historical lead.

### 5. ProgressBar / physical neighbor

- Evidence for: target is physically near progress-bar helper code inside [UID:0002PD].
- Evidence against: exact children split the band; target field is initialized by base ControlPane constructor and used for generic hit-test suppression.
- Decision: rejected.

## Source Placement

- Recommended source file/class/module placement: `ControlPane::IgnoresHitTesting()` in [UID:000038] `ControlPane`, emitted through [UID:0000IG] `NexusTK/ui/core/ControlPane.cpp`.
- Why this placement fits source-tree and subsystem context: hit-test suppression is a base control-state byte initialized by `ControlPane::ControlPane`, written by the inherited setter, and read by generic hit-testing code over arbitrary candidate controls.
- Rejected placements and why:
  - `PopupMenuControls.cpp`: caller-only evidence.
  - `ProgressBarControlPane.cpp`: physical adjacency only.
  - `RadioGroupControlPane.cpp`: stale Wave2 owner, superseded by current docs.
  - Standalone helper/global: not needed for a single member-field accessor.
- Remaining placement uncertainty: exact original method spelling is not symbol-proven, but `IgnoresHitTesting` is the best current source-facing spelling and is sufficient for first-draft emitted C++.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is reconstructable, has nonblank `EMITTER_UIDS`, routes to a valid source file through [UID:000038]/[UID:0000IG], current average score is `87.5`, and the prior naming/field blocker is resolved to first-draft quality.
- Recommended code: replace the target's blank formal multiline block with this exact insertion text after supervisor acceptance:

```cpp
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ControlPane::IgnoresHitTesting() const
{
    return m_ignoreHitTesting;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive: not applicable; this is NexusTK UI-core source, not third-party embedded source.
- Reason it preserves exact original behavior: a `bool` getter returning a byte field compiles to an `al` return for the stored flag; the target body reads only `this+0x104` and returns immediately.
- Reason it matches plausible original mid-2000s source shape: base UI control code would naturally expose a small boolean accessor paired with a setter and backed by a named member field, not raw offset/decompiler labels.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `ControlPane`, `IgnoresHitTesting`, and `m_ignoreHitTesting` replace `sub_494BF0` and `this[260]`.
- Naming/coding style convention used and evidence for consistency: `m_` member naming follows accepted `ControlPane` constructor output; `bool ...() const` follows analogous emitted byte-flag getter style in the project, with `const` still inferred.
- Reason code should remain blank, if applicable: not applicable for [UID:0002PC] after this pass.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation

- Exact changes recommended:
  - Update [UID:0002PC] to source-ready first-draft state.
  - Insert the formal C++ getter shown above.
  - Replace "final C++ remains blank because names are provisional" language with a current caveat: exact original spelling and `const` are inferred, but first-draft source names are now defensible.
  - Move target score from `85/90` to `88/92`.
- Exact parent assignments recommended:
  - Keep `CANONICAL_OWNER:000038`.
  - Keep `RECONSTRUCTABLE:TRUE`.
  - Keep `EMITTER_UIDS:000038`.
  - Keep blank `EMITTER_POSITION_OPTIONAL`.
- Exact items left no-owner/non-emitting and why:
  - None for this target. The surrounding aggregate [UID:0002PD] remains non-reconstructable/non-emitting, but [UID:0002PC] is an exact source-bearing child.
- Exact future work outside this assignment scope:
  - The paired setter [UID:0003N5] can later receive its own formal C++ if assigned or accepted as support scope, likely as `ControlPane::SetIgnoreHitTesting(bool ignoreHitTesting)`. This is not a blocker for the getter.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md`.
- Exact report facts to incorporate:
  - Current MCP session `supervisor_recovery_20260705` confirms `sub_494BF0`, size `0x7`, exact bytes, no callees, one caller at `0x0049fb7f`, and the popup hit-test skip behavior.
  - `this[260]` is `this+0x104` (Verified with `int_convert.py`).
  - Field name should be `m_ignoreHitTesting`, backed by constructor initialization and paired setter write.
  - Source-facing method should be `bool ControlPane::IgnoresHitTesting() const`; `const` remains inferred.
  - Generated output currently has an empty emitter marker and should gain the formal C++ after validation.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:85` -> `COMPLETION:88`.
  - `CONFIDENCE:90` -> `CONFIDENCE:92`.
  - Keep owner/emitter/reconstructable unchanged.
  - Populate formal `RECONSTRUCTION_CPP CODE` with the getter block in this report.
  - Update `Item Summary` to remove "final C++ remains blank" and mention first-draft getter readiness.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve:
  - Preserve that exact original symbol spelling is not PDB-proven.
  - Preserve that PopupMenu is a caller/consumer only.
  - Preserve that physical adjacency to progress-bar helpers does not change ControlPane ownership.
  - Reject stale RadioGroup/Wave2 ownership wording as historical only.

## Recommended Support Doc Changes

- Support path: `by-class/ControlPane.md`.
  - Update the `IgnoresHitTesting` method row to say the target is now first-draft source-ready as `bool ControlPane::IgnoresHitTesting() const`, returning `m_ignoreHitTesting`.
  - Update evidence notes to cite B015 current MCP confirmation of exact getter bytes, sole caller, paired setter, and constructor field initialization.
  - No class score change recommended; broader class blockers remain fixed virtual name, destructor representation, and raw active-frame source representation.
- Support path: `by-file/ControlPane.md`.
  - Mirror the concise source-ready getter note in the proposed contents/evidence notes.
  - State that generated `ControlPane.cpp` should replace the [UID:0002PC] empty marker with the getter after scoped validator refresh.
  - No file score change recommended.
- Support path: `by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md`.
  - Optional support parity edit: update "field/method names provisional" wording to say the field name `m_ignoreHitTesting` is now supported by the constructor, getter, and setter. Keep setter formal C++ blank unless the supervisor explicitly accepts setter C++ as support scope or assigns a dedicated pass.
- Support path: `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`.
  - Optional summary parity edit only if touched for this callback: update the [UID:0002PC] child row to mention first-draft source-ready getter instead of blank-C++ status.
- Generated/project/coverage support:
  - Do not hand-edit `auto-generated/*`, generated `NexusTK/*`, project-level stats, or any `-coverage-report.md`.
  - No manual supervisor-owned coverage/tracker text is required for this report; scoped validators and supervisor execution should refresh generated reports.

## Score And Metadata Recommendation

- Current score/metadata:
  - `COMPLETION:85`, `CONFIDENCE:90`, `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000038`, blank formal C++.
- Recommended score/metadata:
  - `COMPLETION:88`, `CONFIDENCE:92`, owner/emitter/reconstructable unchanged, formal first-draft C++ populated.
- Score rationale and reason not higher/lower:
  - Completion rises because the previous named blocker, method/field source quality, is resolved to first-draft level and formal C++ can be emitted.
  - Confidence rises because current MCP confirms exact bytes, caller behavior, constructor initialization, and paired setter write.
  - Score stays below `95+` because exact original spelling, `const` qualification, and the full class declaration remain inferred rather than original-source proven.
- Score-improvement attempt:
  - Blocker: source-facing method name. Resolved by current docs, B003 name analysis, caller semantics, and paired setter naming.
  - Blocker: field name. Resolved by B007 constructor formal C++ plus current getter/setter/constructor MCP facts.
  - Blocker: C++ readiness. Resolved by active code-entry gate and exact source block.
  - Blocker: ownership/source route. Already resolved by B002 split and current parent/file scores; no metadata change needed.
- Metadata fields to change or leave unchanged:
  - Change only `COMPLETION`, `CONFIDENCE`, `Item Summary`, and formal C++ block.
  - Leave owner, emitter, reconstructable, and nested metadata unchanged.

## Open Questions With Attempted Resolution

- Exact original method spelling:
  - Evidence checked: current target/class/file docs, B003 report, caller semantics, paired setter name, stale old report text.
  - Best supported resolution: use `IgnoresHitTesting`.
  - Remaining uncertainty: original source may have used `IsHitTestIgnored` or similar, but current project evidence and pairing favor `IgnoresHitTesting`; this is not a C++ blocker.
- Exact original field spelling:
  - Evidence checked: B007 constructor formal C++, current generated constructor output, getter/setter/constructor MCP facts.
  - Best supported resolution: use `m_ignoreHitTesting`.
  - Remaining uncertainty: original source might have used a nearby synonym, but `m_ignoreHitTesting` is the accepted field name already emitted by constructor source.
- Whether getter should be `const`:
  - Evidence checked: target has no writes/callees and project has analogous source-ready byte getters emitted as `bool ...() const`.
  - Best supported resolution: include `const`, while documenting it as inferred.
  - Score/C++ impact: not a blocker; it is source-shape inference with no behavioral difference for this read-only method.
- Paired setter C++:
  - Evidence checked: setter body, vtable slot, support doc.
  - Best supported resolution: setter is likely source-ready too, but it is a separate target. Record field-name support parity only unless supervisor broadens scope.
  - Score/C++ impact: does not block the getter; the getter body only depends on the field name.

## Validator Results

- Scoped validators run from `source-3/project-documentation`; no `execute_report`, dry-run/probing execute variant, registry lifecycle command, archive command, manual report move, generated-file edit, coverage-report edit, validator-state edit, queue/lock edit, or supervisor-ledger edit was run by B015.
- Target validator:
  - Command: `python .\tools\validator.py --mode file --file by-memory\0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md --apply --queue-timeout 240`
  - `command_id`: `000000006962`; `command_timestamp`: `2026-07-05T10:48:57-04:00`; exit code `0`; `ok: 1`.
  - Output/side effects: `completion_update 88`, `confidence_update 92`, `autogen_registry_update` for UID0002PC hash and `blank -> block`, `uid_link_insert` for UID0002PB, `projected_stats_update`, `generated_refresh: deferred`.
  - Warnings: three `missing_ref_uid 0003N5` rows because the setter UID mapping was not yet present when the target validator ran.
- Class validator:
  - Command: `python .\tools\validator.py --mode file --file by-class\ControlPane.md --apply --queue-timeout 240`
  - `command_id`: `000000006965`; `command_timestamp`: `2026-07-05T10:49:05-04:00`; exit code `0`; `ok: 1`.
  - Output/side effects: `reference_index_add 0003N2`, `projected_stats_update`, `generated_refresh: deferred`.
  - Warnings: `missing_ref_uid: 32` for existing 0003* support/vtable UIDs, with 22 rows suppressed by validator output.
- File validator:
  - Command: `python .\tools\validator.py --mode file --file by-file\ControlPane.md --apply --queue-timeout 240`
  - `command_id`: `000000006966`; `command_timestamp`: `2026-07-05T10:49:20-04:00`; exit code `0`; `ok: 1`.
  - Output/side effects: three `uid_link_insert 0002PC` rows, `reference_index_add 0003N2`, `projected_stats_update`, `generated_refresh: deferred`.
  - Warnings: `missing_ref_uid: 32` for existing 0003* support/vtable UIDs, with 22 rows suppressed by validator output.
- Setter support validator:
  - Command: `python .\tools\validator.py --mode file --file by-memory\0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md --apply --queue-timeout 240`
  - `command_id`: `000000006967`; `command_timestamp`: `2026-07-05T10:49:28-04:00`; exit code `0`; `ok: 1`.
  - Output/side effects: inserted/registered UID0003N5 mapping, `completion_update 86`, `confidence_update 90`, `canonical_owner_update 000038`, autogen registry entries for reconstructable/emitter/blank code, reference-index adds for UIDs `000038`, `0000IG`, `0002PC`, and `0002PD`, `projected_stats_update`, `generated_refresh: deferred`.
  - Warnings: one `missing_ref_uid 0003J8`.
- Aggregate support validator:
  - Command: `python .\tools\validator.py --mode file --file by-memory\0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md --apply --queue-timeout 240`
  - `command_id`: `000000006968`; `command_timestamp`: `2026-07-05T10:49:35-04:00`; exit code `0`; `ok: 1`.
  - Output/side effects: `uid_link_insert 0002PC`, reference-index adds for UIDs `0003N2` and `0003N5`, `projected_stats_update`, `generated_refresh: deferred`.
  - Warnings: `missing_ref_uid: 23` for existing 0003* support UIDs, with 13 rows suppressed by validator output.
- Generated-refresh state:
  - `auto-generated/NexusTK/ui/core/ControlPane.cpp` was refreshed by validator command `000000006967` at `2026-07-05T10:49:28-04:00`.
  - Header `000000006967` is newer than the target/class/file validators (`000000006962`, `000000006965`, `000000006966`) and contains [UID:0002PC] with `Completion:88`, `Confidence:92`, `bool ControlPane::IgnoresHitTesting() const`, and `return m_ignoreHitTesting;`.
  - Header `000000006967` is older than the aggregate validator `000000006968`; that later support page is non-emitting and the generated getter is already present. Queue-status checks `000000006969`, `000000006971`, and `000000006974` showed no normal validator processing jobs, with generated-refresh work still rotating in the background.

## Changed Files

- Modified by B015 callback edits:
  - `by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md`
  - `by-class/ControlPane.md`
  - `by-file/ControlPane.md`
  - `by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md`
  - `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`
  - `tools/leaser/Agents/Agent-B015/research/0002PC-ControlPaneIgnoresHitTesting-source-quality.md`
- Validator side effects observed and not manually edited:
  - `auto-generated/NexusTK/ui/core/ControlPane.cpp` refreshed to include the UID0002PC getter.
  - `project-level/-auto-completion-stats.md` projected-path completion section updated by scoped validators.
  - `tools/validator.ini` updated by scoped validators for UID/autogen/reference registry state, including new UID0003N5 mapping.
- Created/renamed/moved:
  - No report moves, archive moves, file renames, or new child pages were performed in this callback. The setter page was already present in the workspace and was validated/registered by the scoped setter validator.
- Leases:
  - Lease acquire command succeeded for the five edited by-* docs: target, class, file, setter support, and aggregate support.
  - Release command returned exit code `1` with `Rejected[No active lease]` for all five paths because the short leases had already expired before cleanup.
  - Post-cleanup `tools/leaser/Agents/Agent-B015/current_leases.md` showed no active B015 leases; only stale expired Supervisor entries from 2026-06-18 remained.
- Report execution:
  - Not run. B015 did not run `execute_report`, dry-run/probing variants, registry lifecycle commands, archive commands, manual report moves, or any equivalent lifecycle action.

## Implementation Tracking Checklist

Callback implementation state:

- [x] Supervisor validation required before implementation. Proof: Supervisor reported `GATE1_PASSED` for this report at SHA256 `962EF92F2078971CE8991ED99D6D9291A4F41227D2D4FC94BD15A693516F9F2B` before the callback.
- [x] Target/support docs to update: `by-memory/0x00494bf0-0x00494bf7.ControlPaneIgnoresHitTesting.md`, `by-class/ControlPane.md`, `by-file/ControlPane.md`, `by-memory/0x00494c00-0x00494c10.ControlPaneSetIgnoreHitTesting.md`, and `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`. Proof: all five edited and scoped-validated.
- [x] Current target state and actual evidence checked recorded. Proof: target page now records current MCP session `supervisor_recovery_20260705`, exact bytes/range, no-callee proof, sole caller, setter, constructor field initialization, generated pre-callback empty marker, and rejected alternatives.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim. Proof: ledger rows C1-C10 now show `applied` or `already-present`.
- [x] Metadata/score changes to apply: target `85/90` -> `88/92`; owner/emitter/reconstructable unchanged. Proof: target header and validator `000000006962` show `completion_update 88`, `confidence_update 92`, `CANONICAL_OWNER:000038`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000038`, blank optional emitter position.
- [x] Score-limiting blockers researched to resolution. Proof: target and support docs now state method name, field name, owner/source route, C++ readiness, and split/range disposition; remaining exact spelling/`const` caveats are documented as nonblocking.
- [x] Owner/emitter/reconstructable changes to apply: no changes. Proof: target owner/emitter/reconstructable metadata preserved; C6 marked `already-present`.
- [x] Split/rename/new-child changes to apply: none. Proof: no files were renamed/moved and no new child pages were created.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable. Proof: no IDA DB changes requested or made; target remains exact child inside non-emitting [UID:0002PD] aggregate, and aggregate row was synchronized.
- [x] First-draft C++ or no-code proof to apply: insert exact formal getter block. Proof: target formal `RECONSTRUCTION_CPP CODE` block contains `bool ControlPane::IgnoresHitTesting() const` returning `m_ignoreHitTesting`; generated `ControlPane.cpp` header `000000006967` contains the same getter.
- [x] Third-party import directive to apply or confirm not applicable. Proof: not applicable; this is NexusTK UI-core source.
- [x] Exact target/support doc facts to incorporate at report-level detail. Proof: target/support pages record getter read, paired setter write, constructor false initialization, caller skip semantics, exact bytes/range, no-callee proof, and generated marker replacement.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve. Proof: target page preserves stale RadioGroup/Wave2 rejection, PopupMenu caller-only route, ProgressBar adjacency rejection, exact-original-spelling caveat, and `const` inference caveat.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale. Proof: target rejected-alternatives section marks stale RadioGroup/Wave2 ownership as historical and rejected.
- [x] Open questions to close or document as evidence-backed unresolved. Proof: target open questions now document exact original method spelling and `const` as inferred/nonblocking; setter C++ remains separate scope.
- [x] Validators to run after callback. Proof: target, class, file, setter support, and aggregate support scoped validators all exited `0` with `ok: 1`; command IDs/timestamps are recorded above.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply. Proof: generated `ControlPane.cpp` contains UID0002PC getter after validator refresh; no manual coverage/tracker text is required or supplied.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B015","command_id":"000000006985","destination_path":"executed-b-agent-research/B015/0002PC-ControlPaneIgnoresHitTesting-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B015/research/0002PC-ControlPaneIgnoresHitTesting-source-quality.md","timestamp":"2026-07-05T10:58:21-04:00","uid":"0002PC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
