** TARGET-REPORT-UID:0004C6 **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0004C6 IMECompositionPaneGetCompositionWidth Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: promote [UID:0004C6] `by-memory/0x004e7920-0x004e7927.IMECompositionPaneGetCompositionWidth.md` from a documented-but-non-emitting split child into an emitting `IMECompositionPane::GetCompositionWidth() const` method under [UID:00006G] `IMECompositionPane`.
- Final disposition: keep direct owner [UID:00006G], keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:00006G`, raise the target from `82/89` to `88/91`, and insert the exact formal accessor body listed below.
- Required action after supervisor acceptance: update the target page and small support rows in [UID:00006G] `IMECompositionPane`, [UID:0000K5] `IMEPanes`, and [UID:000189] `IMEPaneFamily`; run scoped validators with generated freshness for `auto-generated/NexusTK/input/IMEPanes.cpp`.
- Confidence: high for exact bytes, behavior, owner/source route, and field semantics; capped below final-audit range because the out-of-line accessor has no current code/data xrefs and `compositionCursorX` remains an inferred source-facing field spelling rather than original-symbol proof.

## Target

- Target UID: `0004C6`.
- Target path: `by-memory/0x004e7920-0x004e7927.IMECompositionPaneGetCompositionWidth.md`.
- Assignment: `B005-report-0004C6-IMECompositionPaneGetCompositionWidth-by-memory-20260701`.
- Queue row: `auto-generated/-ag-research-tracker.md` lists [UID:0004C6] as `82/89`, combined `85.5`, reconstructable `true`, reports `0`.
- Generated coverage row: `auto-generated/-ag-coverage-report-by-memory.md` lists `emits_code:false` and the summary "Exact IMECompositionPane width accessor split child; tiny method returns cached compositionCursorX/composition width state."

## Current Target State

- Existing metadata: `COMPLETION:82`, `CONFIDENCE:89`, `CANONICAL_OWNER:00006G`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Existing owner/source route: current target, class, file, and aggregate docs all place the range under [UID:00006G] `IMECompositionPane` with source route [UID:00006G] -> [UID:0000K5] `IMEPanes`.
- Existing blocker: the target is an exact split child but has no child-specific accepted C++, so generated output does not contain a [UID:0004C6] body. That is now resolved by direct MCP proof.
- Related docs checked: target page, [UID:00006G] `IMECompositionPane`, [UID:0000K5] `IMEPanes`, [UID:000189] `IMEPaneFamily`, [UID:00018A] `IMECompositionSetCompositionString`, [UID:0004C5] `IMECompositionPaneOnPaint`, [UID:0004C7] `IMECandidatePaneConstructor`, generated tracker/coverage, generated `auto-generated/NexusTK/input/IMEPanes.cpp`, and matching executed B-agent reports.

## Executive Recommendation

- Best direct owner: [UID:00006G] `IMECompositionPane`.
- Source placement: emit through [UID:00006G] into [UID:0000K5] `IMEPanes`, matching the existing class shell `[[CHILDREN]]` route.
- Target disposition: keep the exact half-open range `0x004e7920-0x004e7927`; do not split, merge into `OnPaint`, reroute to `IMECandidatePane`, or leave the formal C++ blank.
- Score/metadata: recommend `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:00006G`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006G`, blank optional position.

## Supervisor Active Recheck

- Triggering instruction: report-only research for [UID:0004C6], with no target/support by-* edits until a supervisor implementation callback.
- Split repair required: no. MCP confirms a standalone modeled function at `0x004e7920`, no function at `0x004e7927`, and padding before/after.
- Source-bearing children in scope: only this exact accessor. Sibling composition/candidate children were used for field and caller/source-route evidence.

## Inference Research Guidance Check

- `by-structure.md` separates canonical ownership from output routing. The target already has the narrow semantic owner [UID:00006G]; the missing piece is the emitter route through the class shell.
- `by-structure.md` permits first-draft C++ when a reconstructable page has a confirmed emitter route and combined score above `85`. The recommended `88/91` and [UID:00006G] route clear that gate.
- Evidence separation:
  - IDA fact: function start/size, two instructions, bytes, padding, no xrefs, no callees/callers, and unique byte-pattern occurrence.
  - Documentation evidence: current class/file/aggregate pages, accepted sibling reports, and generated source state.
  - Inference: `GetCompositionWidth() const` and `compositionCursorX` are source-facing names inferred from accepted support docs and behavior, not original-symbol proof.
- Wave2/Wave3 handling: historical owner-pollution notes in IME docs were treated as stale context only. Current by-* docs and live MCP control the recommendation.

## Heuristic / Inference Reanalysis And Validation

- Accessor body: MCP decompile and disassembly prove the function returns the dword at `this + 0xf8`, with no side effects. Hex-Rays renders this as `return this[62];`; `0xf8` is decimal `248` (Verified with int_convert.py), and dword index `62` is the same byte offset under the decompiler's `_DWORD *this` type.
- Field semantics: [UID:00018A] proves `SetCompositionString` stores `MeasureTextWidth(compositionText, GetCompositionCursorPosition()) + 3` into `compositionCursorX`; [UID:0004C5] proves `OnPaint` consumes that same value for the one-pixel caret rectangle; [UID:0004C7] generated/source report uses `compositionPane->GetCompositionWidth()` to express a raw active-child `+0xf8` read in the candidate anchor formula.
- Source name: `GetCompositionWidth() const` is already declared in [UID:00006G]'s emitted class shell and used in generated `IMEPanes.cpp`. It is the best project-wide source-facing name because the candidate constructor wants the composition popup's measured width/cursor advance, while support docs preserve that the stored value is actually the caret/cursor x coordinate.
- Owner route: [UID:00006G] is the narrow owner because the body reads an `IMECompositionPane` field and belongs beside constructor, setter, mouse, key, paint, and destructor siblings. [UID:0000K5] remains the file route only.
- Xref caveat: MCP `xrefs_to 0x004e7920` and bounded pointer-byte search for `20 79 4E 00` found no current references or vtable cell. That is not a no-code proof because IDA models a real source-authored function with unique bytes, and accepted generated source already needs the accessor declaration/source expression for candidate anchoring even where the original optimized caller reads the field directly.
- Score blocker resolution: the current blank-emitter state is no longer justified. The body is exact, the field/source route is already documented by accepted sibling work, and the formal C++ is behavior-preserving.

## Evidence Standards Used

- Evidence types used: IDA MCP `initialize`, `tools/list`, `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, `disasm`, `get_bytes`, `xrefs_to`, `find_bytes`; `tools/int_convert.py`; current by-* docs; generated tracker/coverage/source; matching executed B-agent reports.
- Strength: high. The body is two instructions with exact padding on both sides, no callees, no data dependencies beyond the single class field, and accepted source route/class shell support.
- Limitation: no current xref to the out-of-line function exists, so confidence should not enter final-audit range. The source method can still be emitted to reproduce the original function bytes and to satisfy source-level calls in reconstructed code.

## Evidence Checked

- MCP availability and schema:
  - `initialize` returned `ida-pro-mcp`, protocol `2025-06-18`.
  - `tools/list` was checked; inspection calls used schema-current `database` arguments.
  - `idb_list` found one active session `supervisor_resume_20260629`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, not analyzing.
  - `server_health` returned `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready.
- IDA MCP function/range checks:
  - `lookup_funcs 0x004e7920` -> `sub_4E7920`, size `0x7`.
  - `lookup_funcs 0x004e7912` -> not a function.
  - `lookup_funcs 0x004e7927` -> not a function.
  - `lookup_funcs 0x004e7930` -> `sub_4E7930`, size `0x23c`.
- IDA MCP body checks:
  - `analyze_function 0x004e7920`: prototype `int __thiscall(_DWORD *this)`, size `7`, one basic block, no strings/constants/callees/callers, decompiled `return this[62];`.
  - `decompile 0x004e7920`: same `return this[62];` at `0x004e7926`.
  - `disasm 0x004e7920`: `mov eax, [ecx+0F8h]`; `retn`.
- IDA MCP byte checks:
  - `get_bytes 0x004e7912 size 14` -> fourteen `0xcc` bytes after [UID:0004C5] and before this target.
  - `get_bytes 0x004e7920 size 7` -> `8b 81 f8 00 00 00 c3`.
  - `get_bytes 0x004e7927 size 9` -> nine `0xcc` bytes before [UID:00018B]/`0x004e7930`.
- IDA MCP xref/negative checks:
  - `xrefs_to 0x004e7920` -> zero xrefs.
  - `find_bytes "20 79 4E 00"` -> zero matches; no little-endian function pointer to `0x004e7920` was found by this bounded exact-pattern search.
  - `find_bytes "8B 81 F8 00 00 00 C3"` -> one match at `0x004e7920`; no duplicate same-byte accessor was found.
  - `get_bytes 0x0061c420 size 64` showed neighboring vtable data contains `0x004e7840`, `0x004e7640`, `0x004e7810`, and other entries, but not `0x004e7920`.
- Candidate constructor optimized-use check:
  - `decompile/disasm 0x004e7b70` shows `IMECandidatePane` construction reads `g_pIMEPane->activeChildPane`, calls the active child's bounds vslot, then reads `[esi+0F8h]` at `0x004e7c60` and adds it to `activeChildBounds.left` before writing candidate anchor X.
  - Current generated `auto-generated/NexusTK/input/IMEPanes.cpp` expresses that source-level dependency as `compositionPane->GetCompositionWidth()`.
- Conversion check:
  - `python .\tools\int_convert.py` on `248` and `0xf8` confirms decimal `248` equals hexadecimal `0xf8` (Verified with int_convert.py).
- Existing reports searched/opened:
  - Search terms: `0004C6`, `0x004e7920`, `0x004e7927`, `IMECompositionPaneGetCompositionWidth`, `GetCompositionWidth`, `compositionCursorX`, `IMECompositionPane`, `IMEPanes`.
  - Relevant matching reports opened as leads: `executed-b-agent-research/B008/0000K5-IMEPanes-empty-emitter-family-source-quality.md`, `executed-b-agent-research/B003/00018A-ime-composition-set-composition-string-source-quality.md`, `executed-b-agent-research/B008/0004C5-IMECompositionPaneOnPaint-source-quality.md`, `executed-b-agent-research/B009/0004C3-IMECompositionPaneOnMouseEvent-source-quality.md`, `executed-b-agent-research/B009/0004C7-IMECandidatePaneConstructor-source-quality.md`, and `executed-b-agent-research/B007/0004C1-IMECompositionPaneConstructor-source-quality.md` via exact-term matches.
  - No prior UID0004C6-specific completed report was found.
- Failed/unavailable/skipped checks: none. MCP was available and responsive. Validators were intentionally not run because this is report-only and no by-* files were edited.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | [UID:0004C6] is exact function `sub_4E7920`, half-open range `0x004e7920-0x004e7927`, size `0x7`. | High | MCP `lookup_funcs`, `analyze_function`, `disasm`. | Target Status/Evidence/Score Rationale. | incorporate | applied: target Evidence/Score Rationale updated; validator `000000004112` ok. |
| C2 | The exact bytes are `8b 81 f8 00 00 00 c3`, disassembling to `mov eax, [ecx+0F8h]; retn`. | High | MCP `get_bytes`, `disasm`. | Target Evidence/Behavior. | incorporate | applied: target Behavior/Evidence and support rows updated; generated body refreshed by `000000004115`. |
| C3 | Padding separates this accessor from [UID:0004C5] and [UID:00018B]: fourteen `0xcc` bytes before start and nine `0xcc` bytes after end in the checked windows. | High | MCP `get_bytes 0x004e7912 size 14`, `get_bytes 0x004e7927 size 9`, `lookup_funcs 0x004e7930`. | Target Evidence; aggregate split row. | incorporate | applied: target Evidence and aggregate covered/split rows updated; validator `000000004115` ok. |
| C4 | The function returns `compositionCursorX` at `IMECompositionPane +0xf8`; `0xf8` is decimal `248` (Verified with int_convert.py). | High | MCP decompile/disasm; `tools/int_convert.py`; [UID:00018A], [UID:0004C5], [UID:00006G]. | Target Behavior; class observed-state/method row. | incorporate | applied: target Behavior, class method row, file/aggregate support, and generated C++ return `compositionCursorX`. |
| C5 | Direct owner remains [UID:00006G] `IMECompositionPane`; source file route remains [UID:00006G] -> [UID:0000K5] `IMEPanes`. | High | Current target/class/file/aggregate docs; sibling reports; field use. | Target metadata/status; class/file/aggregate support. | already-present for owner, incorporate emitter. | applied: owner unchanged, target emitter set to `00006G`, support docs route through [UID:00006G] -> [UID:0000K5]. |
| C6 | `EMITTER_UIDS` should be `00006G`, not blank and not direct [UID:0000K5]. | High | [UID:00006G] class shell has `[[CHILDREN]]`; [UID:0000K5] is the source root; by-structure emitter routing. | Target metadata. | incorporate | applied: target metadata `EMITTER_UIDS:00006G`; validator `000000004112` registry update blank -> `00006G`. |
| C7 | First-draft formal C++ should be `int IMECompositionPane::GetCompositionWidth() const { return compositionCursorX; }`. | High | Two-instruction body; accepted field name; existing class declaration; no callees/side effects. | Target `RECONSTRUCTION_CPP CODE`. | incorporate | applied: target C++ block populated; generated `IMEPanes.cpp` contains UID0004C6 body after `000000004115`. |
| C8 | Zero xrefs and no pointer-byte match to `0x004e7920` are caveats, not no-code proof. | Medium-high | MCP `xrefs_to`, `find_bytes`; modeled function with unique bytes; generated candidate constructor source already calls accessor. | Target Reconstruction Notes/Negative Evidence. | incorporate | applied: target Reconstruction Notes and class/file/aggregate support preserve the caveat and reject no-code. |
| C9 | Candidate constructor source use is legitimate support evidence: raw binary reads active child `+0xf8`, while generated source expresses it as `compositionPane->GetCompositionWidth()`. | High | MCP `decompile/disasm 0x004e7b70`; generated `IMEPanes.cpp`; B009 UID0004C7 report. | Target Evidence; optional class/file support note. | incorporate | applied: target Evidence plus class/file/aggregate support note source-use by UID0004C7. |
| C10 | Recommended score is `88/91`: exact body/source route/formal C++ resolved, but no xrefs and inferred field spelling cap final-audit confidence. | Medium-high | Current MCP evidence, current docs, score gate rules, sibling score precedents. | Target metadata/Score Rationale; generated tracker after validator. | incorporate | applied: target metadata and score rationale updated; validator `000000004112` reported `completion_update 88` and `confidence_update 91`. |
| C11 | No target-specific split, rename, owner change, or support-doc score change is required. | High | Exact function boundary and already-correct class/file route. | Target/support docs and implementation checklist. | not-applicable | applied/not-applicable: no split, rename, owner change, support score change, or UID0004C7 edit was made. |

## Positive Evidence Summary

- Exact function proof: MCP identifies `sub_4E7920` at `0x004e7920`, size `0x7`, with only `mov eax, [ecx+0F8h]` and `retn`.
- Field proof: accepted sibling documentation proves `+0xf8` is `compositionCursorX`, written by `SetCompositionString`, cleared by the constructor, painted as the caret x coordinate, and used by candidate anchoring.
- Source-route proof: [UID:00006G] already declares `int GetCompositionWidth() const;` and emits through [UID:0000K5]. The only missing implementation detail is this target's body/emitter metadata.
- Generated-source proof: current generated `IMEPanes.cpp` has the class declaration and candidate constructor call to `GetCompositionWidth()`, but lacks a [UID:0004C6] body because the target remains blank-emitter.

## IDA MCP Facts

- Function/range facts:
  - `0x004e7920`: `sub_4E7920`, size `0x7`.
  - `0x004e7927`: not a function.
  - `0x004e7930`: `sub_4E7930`, size `0x23c`.
- Data/table/padding facts:
  - `0x004e7912-0x004e791f`: fourteen `0xcc` bytes.
  - `0x004e7920-0x004e7926`: `8b 81 f8 00 00 00 c3`.
  - `0x004e7927-0x004e792f`: nine `0xcc` bytes.
  - `0x0061c420` vtable sample does not include `0x004e7920`.
- Xref facts:
  - `xrefs_to 0x004e7920`: zero.
  - `find_bytes 20 79 4E 00`: zero.
  - `find_bytes 8B 81 F8 00 00 00 C3`: one match at `0x004e7920`.
- Callee facts: no callees.
- Negative IDA facts: no direct callers, no data xrefs, no strings, no constants, no function at the end address, no internal branches.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004e7840-0x004e7912` | [UID:0004C5] `IMECompositionPaneOnPaint` | Paints composition text and one-pixel caret from `compositionCursorX`. | TRUE | [UID:00006G] | `88/91` | Populated formal C++; context sibling. |
| `0x004e7920-0x004e7927` | [UID:0004C6] `IMECompositionPaneGetCompositionWidth` | Returns cached `compositionCursorX`. | TRUE | [UID:00006G] | recommended `88/91` | Primary target; should emit first-draft C++. |
| `0x004e7930-0x004e7b6c` | [UID:00018B] `IMECandidateShowCandidateList` | Candidate list method following post-accessor padding. | TRUE | [UID:00006F] | `89/91` in current generated output | Neighbor only; no merge. |
| `0x004e7b70-0x004e7cae` | [UID:0004C7] `IMECandidatePaneConstructor` | Source uses `compositionPane->GetCompositionWidth()` for active-child candidate anchor. | TRUE | [UID:00006F] | `88/91` | Support evidence for source-level accessor use. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x004e7920` | no current xrefs | Out-of-line source method exists but has no current direct or data references in IDA. |
| `0x004e7c60` | reads `[esi+0F8h]` inside [UID:0004C7] | Optimized candidate-constructor use of the same value exposed in source as `GetCompositionWidth()`. |
| `0x004e78c8-0x004e78fc` | [UID:0004C5] caret rectangle reads `compositionCursorX` | Corroborates the field as cursor x / measured width, not string length. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - [UID:0004C6] target already identifies the exact owner/source route and cached-width behavior.
  - [UID:00006G] declares `GetCompositionWidth() const` and documents `compositionCursorX +0xf8`.
  - [UID:000189] lists `0x004e7920-0x004e7927` as `IMECompositionPane::GetCompositionWidth`.
  - [UID:00018A] and [UID:0004C5] prove the write/paint relationship for the same field.
  - [UID:0004C7] report/generated C++ uses `GetCompositionWidth()` to represent the candidate anchor read.
- Existing docs that are incomplete:
  - [UID:0004C6] still has blank `EMITTER_UIDS` and blank formal C++ despite now having enough evidence for a formal accessor body.
  - [UID:00006G] method row still lists the address only and does not record the child as emitting.
  - [UID:0000K5] and [UID:000189] still describe this child generically rather than as a populated formal accessor.
- Generated/coverage state:
  - Generated `auto-generated/NexusTK/input/IMEPanes.cpp` currently includes the class prototype and candidate constructor call, but has no [UID:0004C6] marker/body.

## Ranked Ownership Analysis

### 1. [UID:00006G] `IMECompositionPane`

- Evidence for: the body reads a field accepted as `IMECompositionPane +0xf8`; [UID:00006G] declares the method; constructor, setter, paint, mouse, destructor, and aggregate docs all place neighboring composition methods under this class.
- Evidence against: zero direct xrefs to the out-of-line function, but that is a reachability caveat rather than contrary owner evidence.
- Decision: keep canonical owner and set emitter to [UID:00006G].

### 2. [UID:0000K5] `IMEPanes`

- Evidence for: this is the correct source file root and final generated route.
- Evidence against: by-structure requires the narrow class owner/emitter for class methods when the class page clears the gate; [UID:0000K5] is too broad as direct metadata owner.
- Decision: keep as transitive file route through [UID:00006G], not direct target emitter.

### 3. [UID:00006F] `IMECandidatePane`

- Evidence for: accepted candidate constructor source calls `IMECompositionPane::GetCompositionWidth()` to place candidate popups.
- Evidence against: that is a consumer/use site. The field and function belong to `IMECompositionPane`, not `IMECandidatePane`.
- Decision: reject as owner; cite as caller/source-use support only.

### 4. No-code / no-owner / aggregate-only

- Evidence for: no direct xrefs, no vtable pointer, and no data pointer found.
- Evidence against: IDA models a real function with unique code bytes; current docs already establish exact class/source route; generated source already has a source-level need for the accessor declaration and call.
- Decision: reject. The correct disposition is emitting through [UID:00006G] with a no-xref caveat.

## Source Placement

- Recommended placement: `int IMECompositionPane::GetCompositionWidth() const` under [UID:00006G] `IMECompositionPane`, emitted through [UID:0000K5] `NexusTK/input/IMEPanes.cpp`.
- Why it fits: the class shell already declares the method; sibling methods in the same contiguous composition-pane range already emit through the class/file route; the target returns class state with no external dependencies.
- Rejected placements: direct file emission, candidate-pane ownership, aggregate-only body, or no-code marker.
- Remaining placement uncertainty: none that blocks implementation. Exact original spelling remains inferred but already accepted in support docs.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: keep `0x004e7920-0x004e7927`. MCP reports size `0x7`, with no function at `0x004e7927`.
- Predecessor padding: `0x004e7912-0x004e791f` is fourteen `0xcc` bytes after [UID:0004C5].
- Successor padding: `0x004e7927-0x004e792f` is nine `0xcc` bytes before [UID:00018B] starts at `0x004e7930`.
- No split/merge: the target is a two-instruction method and should not be merged into `OnPaint`, the aggregate, or candidate pages.
- Reclassification: keep `RECONSTRUCTABLE:TRUE`; this is custom source code, not padding or compiler wrapper.

## Negative Evidence Summary

- No direct code caller or data xref to `0x004e7920` was found.
- No little-endian pointer bytes `20 79 4E 00` were found by exact-pattern search.
- No vtable sample around `0x0061c420` contains this function pointer, unlike neighboring virtual `OnPaint`, `OnMouseEvent`, and `OnKeyEvent` entries.
- These negatives cap confidence but do not justify no-code: the function is modeled, unique, source-authored, and has a clear class owner and formal source expression.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types:
  - `int IMECompositionPane::GetCompositionWidth() const`.
  - `int compositionCursorX` for `this+0xf8`.
- Evidence: MCP body, [UID:00006G] class shell, [UID:00018A] setter, [UID:0004C5] paint consumer, [UID:0004C7] source call.
- Items intentionally left unchanged: no IDA DB renames, types, or comments are requested in this report-only pass.
- IDA DB edits: not requested.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes, after accepted implementation sets `EMITTER_UIDS:00006G` and raises metadata to `88/91`. The target is `RECONSTRUCTABLE:TRUE`, has a confirmed class/file route, exact body, no dependencies, and combined score above the code gate.
- Recommended code: exact formal target insertion text for [UID:0004C6]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int IMECompositionPane::GetCompositionWidth() const
{
    return compositionCursorX;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive: not applicable.
- Reason it preserves exact behavior: the binary returns the 32-bit value at `this + 0xf8` directly and performs no calls, branches, writes, or conversions.
- Reason it matches plausible source shape: a tiny const accessor for a private composition-pane field is the natural source form and is already declared by the class shell.
- Inferred names used instead of IDA labels: `IMECompositionPane`, `GetCompositionWidth`, and `compositionCursorX`.
- Reason code should not remain blank: the current blank-emitter state is only a missing child-specific implementation pass; the body is exact and source-authored.
- Exact no-code proof, if not eligible: not applicable. No-code was considered and rejected because IDA models a real function with unique bytes and accepted class/source route evidence.

## Final Recommendation

- Recommended target changes:
  - `COMPLETION:88`
  - `CONFIDENCE:91`
  - `CANONICAL_OWNER:00006G` unchanged
  - `RECONSTRUCTABLE:TRUE` unchanged
  - `EMITTER_UIDS:00006G`
  - `EMITTER_POSITION_OPTIONAL:` blank
  - insert the formal C++ block above
  - update behavior/evidence/reconstruction notes/score rationale to preserve exact body, padding, no-xref caveat, field semantics, optimized-use site, and rejected alternatives.
- Recommended support changes:
  - [UID:00006G] `IMECompositionPane`: update method row/evidence to state [UID:0004C6] is `88/91`, emits formal `GetCompositionWidth() const`, and returns `compositionCursorX`.
  - [UID:0000K5] `IMEPanes`: update IMECompositionPane contents/evidence to include [UID:0004C6] as an emitting accessor child through [UID:00006G].
  - [UID:000189] `IMEPaneFamily`: update the covered-range/split row for `0x004e7920-0x004e7927` to record the exact `88/91` emitting accessor and no-xref caveat.
  - [UID:0004C7] `IMECandidatePaneConstructor`: no required edit; it already contains same-or-better source-use detail in formal C++ and report support. Optional cross-reference only if supervisor wants more linkage.
- Items left no-owner/non-emitting: none for this target after accepted callback.
- Future work outside scope: [UID:0004C4] `IMECompositionPaneOnKeyEvent` remains a separate blank-emitter sibling and should be handled by its own child-specific pass.

## Recommended Target Doc Changes

- Target path: `by-memory/0x004e7920-0x004e7927.IMECompositionPaneGetCompositionWidth.md`.
- Exact report facts to incorporate:
  - MCP session `supervisor_resume_20260629` confirms `sub_4E7920`, size `0x7`, body `mov eax, [ecx+0F8h]; retn`, bytes `8b 81 f8 00 00 00 c3`.
  - Padding: `0x004e7912-0x004e791f` and `0x004e7927-0x004e792f` are `0xcc` in the checked windows.
  - No direct xrefs or function-pointer byte match were found; preserve this as a caveat, not a no-code proof.
  - Behavior: return `compositionCursorX`, the cached composition cursor x / measured composition width field at `+0xf8`.
  - Candidate constructor optimized-use support: raw binary reads active child `+0xf8`; generated source calls `compositionPane->GetCompositionWidth()`.
- Metadata/score/owner/emitter/C++ changes: apply the values and formal block from Final Recommendation.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: blank-emitter/no-code state is superseded; direct file/candidate/aggregate-only routes are rejected.

## Recommended Support Doc Changes

- Support path: `by-class/IMECompositionPane.md`.
  - Incorporate: method row should say `GetCompositionWidth` [UID:0004C6] is `88/91`, formal C++ populated, and returns `compositionCursorX +0xf8`.
  - Optional evidence note: the candidate constructor uses the accessor as the source form for an optimized active-child `+0xf8` read.
  - Metadata/score change: none required; class is already `88/91`.
- Support path: `by-file/IMEPanes.md`.
  - Incorporate: IMECompositionPane source contents include emitted accessor [UID:0004C6], routed through [UID:00006G] into generated `NexusTK/input/IMEPanes.cpp`.
  - Metadata/score change: none required; file is already `90/88`.
- Support path: `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`.
  - Incorporate: split/covered range row should record [UID:0004C6] as `88/91`, formal `GetCompositionWidth() const` populated, exact two-instruction accessor, no direct xrefs, and source use by [UID:0004C7].
  - Metadata/score change: none required; aggregate remains a source-order/container page with `[[CHILDREN]]`.
- Support path: `by-memory/0x004e7b70-0x004e7cae.IMECandidatePaneConstructor.md`.
  - No mandatory edit. Existing target formal C++ and report already call `compositionPane->GetCompositionWidth()` and document the raw `+0xf8` read.

## Score And Metadata Recommendation

- Current score/metadata: `82/89`, owner `00006G`, reconstructable true, blank emitter/formal C++.
- Recommended score/metadata: `88/91`, owner `00006G`, reconstructable true, emitter `00006G`, blank position, formal C++ populated.
- Score rationale:
  - Completion `88`: exact range, body bytes, behavior, field semantics, class/file route, generated-source impact, first-draft C++, and rejected alternatives are resolved. It stays below low/mid-90s because the target currently has no xrefs and the support field name remains inferred rather than original-symbol proof.
  - Confidence `91`: exact two-instruction behavior and current support docs are strong. It is not higher because no direct or vtable reference was found for the out-of-line function.
- Score-improvement attempt:
  - Blank-emitter blocker researched through target/class/file/aggregate docs, generated `IMEPanes.cpp`, and accepted sibling reports; result: set emitter `00006G` and populate C++.
  - Field-name blocker researched through [UID:00018A], [UID:0004C5], [UID:0004C7], class shell, and MCP body; result: `compositionCursorX` is safe.
  - Reachability/xref blocker researched through `xrefs_to`, pointer-byte search, vtable sample, and candidate constructor optimized-use check; result: no xrefs remain a caveat, not a no-code blocker.
- Metadata fields to leave unchanged: UID, canonical owner, reconstructable true, blank optional position.

## Open Questions With Attempted Resolution

- Why does the original binary have no xrefs to the out-of-line accessor?
  - Evidence checked: `xrefs_to 0x004e7920`, pointer-byte search, vtable sample, candidate constructor disassembly, generated source.
  - Best supported resolution: this is an out-of-line source member whose known source-level use can be optimized into a raw field read at at least one call/use site. No current evidence proves virtual dispatch or direct calls.
  - Impact: confidence cap only; not a blocker for emitting the original function body.
- Is `compositionCursorX` exactly the original field name?
  - Evidence checked: accepted class shell, SetCompositionString, OnPaint, candidate constructor report, target body.
  - Best supported resolution: keep `compositionCursorX` as the current source-facing field name. It accurately describes the caret/cursor x coordinate, while target method name preserves the width/accessor role.
  - Impact: confidence cap only; source code remains ready.
- Should the target emit through direct file [UID:0000K5]?
  - Evidence checked: by-structure emitter rules, class shell route, current docs.
  - Resolution: no. Emit through [UID:00006G] so class method output is assembled under the class/file route.

## Follow-Up Actions

- Supervisor action: validate this report/checklist, then send an implementation callback if accepted.
- B005 callback action, if accepted: edit only the listed target/support docs under leases, apply report facts at report-level detail, run scoped validators, and update this checklist.
- Other future work: separate child-specific report for [UID:0004C4] `IMECompositionPaneOnKeyEvent`.

## Validator Results

- `python .\tools\validator.py --mode file --file by-memory/0x004e7920-0x004e7927.IMECompositionPaneGetCompositionWidth.md --apply --wait-generated --queue-timeout 240`
  - Start/end UTC: `2026-07-01T21:51:24.9281907Z` / `2026-07-01T21:51:36.5294767Z`.
  - `command_id: 000000004112`, `command_timestamp: 2026-07-01T17:51:25-04:00`, exit `0`, `ok: 1`.
  - Proof: reported `completion_update 0004C6 ... 88`, `confidence_update 0004C6 ... 91`, `autogen_registry_update 0004C6 ... -> 00006G`, and generated refresh completed.
- `python .\tools\validator.py --mode file --file by-class/IMECompositionPane.md --apply --wait-generated --queue-timeout 240`
  - Start/end UTC: `2026-07-01T21:51:41.6495619Z` / `2026-07-01T21:51:52.7395984Z`.
  - `command_id: 000000004113`, `command_timestamp: 2026-07-01T17:51:41-04:00`, exit `0`, `ok: 1`.
  - Proof: reported UID link inserts for [UID:0004C5]/[UID:00018B], `reference_index_add 0004C6 by-class/IMECompositionPane.md`, and generated refresh completed.
- `python .\tools\validator.py --mode file --file by-file/IMEPanes.md --apply --wait-generated --queue-timeout 240`
  - Start/end UTC: `2026-07-01T21:51:58.0212260Z` / `2026-07-01T21:52:08.6167424Z`.
  - `command_id: 000000004114`, `command_timestamp: 2026-07-01T17:51:58-04:00`, exit `0`, `ok: 1`.
  - Proof: reported UID link inserts for [UID:0004C5]/[UID:00018B], `reference_index_add 0004C6 by-file/IMEPanes.md`, and generated refresh completed.
- `python .\tools\validator.py --mode file --file by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md --apply --wait-generated --queue-timeout 240`
  - Start/end UTC: `2026-07-01T21:52:14.3226958Z` / `2026-07-01T21:52:25.9307818Z`.
  - `command_id: 000000004115`, `command_timestamp: 2026-07-01T17:52:14-04:00`, exit `0`, `ok: 1`.
  - Proof: reported UID link inserts for [UID:0004C5]/[UID:00018B], `memory_auto_coverage_update`, and generated refresh completed.
- Generated freshness proof: `auto-generated/NexusTK/input/IMEPanes.cpp` header now shows `validator-command-id: 000000004115`, `validator-refreshed-at: 2026-07-01T17:52:14-04:00`, and `validator-refresh-source: foreground-generated-refresh`. Lines around UID0004C6 contain `// UID:0004C6 ... Completion:88 | Confidence:91`, `int IMECompositionPane::GetCompositionWidth() const`, and `return compositionCursorX;`. Search found no UID0004C6 empty/non-emitting marker.

## Changed Files

- Created in report-only pass: `tools/leaser/Agents/Agent-B005/research/0004C6-IMECompositionPaneGetCompositionWidth-by-memory-source-quality.md`.
- Modified by B005 manual implementation edits: `by-memory/0x004e7920-0x004e7927.IMECompositionPaneGetCompositionWidth.md`, `by-class/IMECompositionPane.md`, `by-file/IMEPanes.md`, `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`, and this report ledger/checklist.
- Validator-owned updates observed: generated metadata/coverage/source files including `auto-generated/NexusTK/input/IMEPanes.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, coverage metadata, reference index/registry, and validator backups.
- Renamed: none.
- Exclusions: no manual edit was made to `by-memory/0x004e7b70-0x004e7cae.IMECandidatePaneConstructor.md`; its existing source-use evidence already matched the accepted report.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation: accepted for implementation on 2026-07-01.
- [x] Target/support docs to update: [UID:0004C6] target, [UID:00006G] `IMECompositionPane`, [UID:0000K5] `IMEPanes`, and [UID:000189] `IMEPaneFamily`; [UID:0004C7] excluded because no contradiction blocked implementation.
- [x] Current target state and actual evidence checked recorded: `82/89`, owner [UID:00006G], reconstructable true, blank emitter/formal C++; MCP session `supervisor_resume_20260629` proves exact body/range/no-xref caveat.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: rows C1-C11 now applied or applied/not-applicable with proof.
- [x] Metadata/score changes applied: target `88/91`, owner/reconstructable unchanged, `EMITTER_UIDS:00006G`, blank optional position.
- [x] Score-limiting blockers researched to resolution: blank emitter resolved; field semantics resolved; no-xref caveat researched and preserved as confidence cap only.
- [x] Owner/emitter/reconstructable changes applied: owner unchanged, reconstructable unchanged, emitter `00006G`.
- [x] Split/rename/new-child changes applied: none required.
- [x] Source-placement/range/split/padding/reclassification/IDA changes applied or excluded: exact range kept; padding recorded; no IDA DB edits.
- [x] First-draft C++ applied: exact `int IMECompositionPane::GetCompositionWidth() const { return compositionCursorX; }`; no-code rejected.
- [x] Third-party import directive applied or excluded: not applicable.
- [x] Exact target/support doc facts incorporated: body bytes/instructions, padding, field semantics, no xrefs/pointer search, optimized-use site in [UID:0004C7], generated-source expectation.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved: blank-emitter state superseded; direct file/candidate/aggregate/no-code routes rejected; no-xref caveat retained.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale: historical Wave3 owner wording in IME aggregate/class docs was not used as proof.
- [x] Open questions documented with evidence-backed unresolved rationale: zero-xref reason and exact original field spelling remain confidence caps only.
- [x] Validators run: scoped file validators for target, class, file, and aggregate with `--wait-generated`; all exit `0`/`ok: 1`.
- [x] Generated report refresh completed by validator: `IMEPanes.cpp` refreshed at command `000000004115`.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim.
- [x] Metadata/score/owner/emitter/split/rename/C++ changes applied or explicitly not applied with reason.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence preserved.
- [x] Open questions resolved or documented with evidence-backed unresolved rationale.
- [x] Validators run and results recorded.
- [x] Generated report refresh completed by validator; no manual coverage/tracker text was supplied.
- [x] Remaining unapplied accepted items: none. Explicit exclusion: UID0004C7 support page was not edited because accepted callback made it optional and existing evidence already supported source use.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0004C6-IMECompositionPaneGetCompositionWidth-by-memory-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B005/research/0004C6-IMECompositionPaneGetCompositionWidth-by-memory-source-quality.md","timestamp":"2026-07-01T17:58:29","uid":"0004C6"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
