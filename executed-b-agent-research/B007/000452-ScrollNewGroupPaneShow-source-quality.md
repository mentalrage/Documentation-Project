** TARGET-REPORT-UID:000452 **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 000452 ScrollNewGroupPaneShow Source-Quality Research


## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:000452] as `ScrollNewGroupPane::Show()` with the existing formal C++ body, direct owner [UID:0000CL] `ScrollNewGroupPane`, emitter [UID:0000CL], and emitter position `45`.
- Final disposition: target body and polarity are correct, but the target/support docs should be repaired because current live MCP proves the documented successor gap `0x00560aba-0x00560b00` is not pure alignment. It contains two raw ScrollNewGroupPane helper bodies at `0x00560ac0-0x00560ada` and `0x00560ae0-0x00560afa`.
- Implementation status: supervisor accepted the report; target evidence/boundary and split-support docs were updated, and exact raw child pages were created for the inverse hide/disable helper and enabled-plus-range predicate.
- Confidence: high for target behavior and route; medium-high for inferred original source names because no PDB/source symbol proves `Show`, `Hide`, or `CanAdjust`.

## Supporting Research

- Current assignment: implementation callback for accepted [UID:000452] `by-memory/0x00560aa0-0x00560aba.ScrollNewGroupPaneShow.md`.
- Historical context: B005 created this child from [UID:0001GP] and B002 later synchronized `Group.cpp` empty emitters. Those reports were treated as leads and rechecked against live MCP.
- Current report path: `tools/leaser/Agents/Agent-B007/research/000452-ScrollNewGroupPaneShow-source-quality.md`.
- Lifecycle/status notes: this report began as a report-only artifact after a prior `PAUSED_MCP_UNAVAILABLE` checkpoint. MCP evidence was collected from session `b001-0001I5`; supervisor Gate 1 passed and the implementation callback has now been applied.

## Target

- Target UID: `000452`.
- Target path: `by-memory/0x00560aa0-0x00560aba.ScrollNewGroupPaneShow.md`.
- Source queue/report row: `auto-generated/-ag-research-tracker.md` by-memory reconstructable row, current `86/89`, direct reports `0`.
- Current supervisor classification: accepted source-quality report with implementation callback applied.
- Post-implementation scores and parent state: target `89/91`, owner/emitter [UID:0000CL], reconstructable true, generated through `auto-generated/NexusTK/social/Group.cpp`; parent split index [UID:0001GP] remains non-emitting `88/90`.

## Current Target State

- Pre-implementation metadata: `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, `EMITTER_POSITION_OPTIONAL:45`.
- Post-implementation metadata: `COMPLETION:89`, `CONFIDENCE:91`, with `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, and `EMITTER_POSITION_OPTIONAL:45` unchanged.
- Owner/emitter/reconstructable state: correct under by-structure. The method belongs to `ScrollNewGroupPane` and emits through the class route into [UID:0000JS] `Group`.
- C++/emitter state: `void ScrollNewGroupPane::Show()` remains exactly as the target formal block; no target C++ change was made.
- Pre-implementation stale assumption: target and support docs said `0x00560aba-0x00560b00` was alignment before `HandleMouseEvent`. Live MCP proved only the three subranges `0x00560aba-0x00560ac0`, `0x00560ada-0x00560ae0`, and `0x00560afa-0x00560b00` are padding; the rest is raw code and has now been split into child docs.
- Related target/support docs checked: target page, [UID:0001GP] core split index, [UID:0000CL] class page, [UID:0000JS] file page, [UID:000453] successor page, [UID:0001YR]/[UID:0002OS] vtable support, generated `Group.cpp`, generated tracker/coverage rows, B005 and B002 executed reports, and ScrollVolumePane raw-helper precedent [UID:00031O].
- Current artifact/lifecycle status: implementation-applied B007 report in Agent-B007 research folder; not executed and not archived.

## Heuristic / Inference Reanalysis And Validation

- Target polarity: live disassembly at `0x00560aa0` checks byte `+0x102` for zero, returns if already nonzero, writes `1`, and invalidates `this+0x44` through vtable slot `+0x20`. The current `Show()` C++ preserves this exactly.
- Target return type: Hex-Rays prints `int __thiscall` with an undefined early-return value, but the caller ignores the return and the source-shaped side effect is a void transition helper. Keep `void`.
- Constructor call context: `NewGroupPane::NewGroupPane` constructs the child at `0x0056caae`, stores it at `NewGroupPane+0x100`, then calls `0x00560aa0` at `0x0056cac3`. Constructor disassembly writes `word ptr [esi+102h], 0FF01h`, so `m_scrollEnabled` starts true and the immediate `Show()` call is idempotent. That does not refute the method body; it supports a harmless source-level "ensure shown" call.
- Naming: keep `Show()` for UID000452 because that name is already accepted and matches the caller's source shape. Treat `Enable` as a behavior alias only. The newly found inverse raw body should be named `Hide` or `HideRaw` in the child filename/prose to preserve the accepted show/hide pair; `Disable` is a weaker but acceptable behavior alias.
- Predicate raw helper: `0x00560ae0-0x00560afa` implements `m_scrollEnabled && m_scrollRange > 0`. The strongest precedent is [UID:00031O] `ScrollVolumePane::CanAdjust() const`, which emits the same predicate pattern for a sibling scrollbar/slider class. Recommend `ScrollNewGroupPane::CanAdjust() const` as the least-colliding source-facing name because `CanScroll(int)` is already used for the false secondary-vtable method at [UID:000454].
- Rejected alternatives:
  - Treat the whole successor gap as padding: rejected by live `insn_query` and `get_bytes`.
  - Merge raw helpers into UID000452: rejected because there are `0xcc` padding gaps and each helper has its own return.
  - Rename UID000452 to `Enable`: rejected for this pass because current class/file/generated route already uses `Show`, the direct caller shape is an idempotent show call, and broader show/hide naming should be handled with the new inverse child.
  - Leave raw helpers undocumented as "no current route": rejected because [UID:00031O] establishes that this exact raw predicate family can be source-ready with no static route when owner, field roles, and source shape are strong.

## Evidence Standards Used

- Evidence types used: live IDA MCP `idb_list`, `server_health`, `lookup_funcs`, `disasm`, `decompile`, `insn_query`, `get_bytes`, `make_signature_for_range`, `find_bytes`, `xrefs_to`, `xref_query`, `callees`, `entity_query`, constructor/caller disassembly, generated output rows, accepted by-* docs, and executed B reports.
- Evidence ladder: live MCP facts first; current by-* docs and generated output second; executed B reports and sibling ScrollVolumePane precedent third; source-shape inference only after direct bytes and ownership were established.
- Strength and limits: target range/body/caller are directly proven. Original source symbol spelling and live static routes to the raw helper starts are not proven, so scores should stay below final-audit range.

## Evidence Checked

- IDA MCP/manual-disassembly/raw-byte checks performed:
  - `idb_list` showed session `b001-0001I5` for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active worker PID `15332`.
  - `server_health` returned `status:ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready.
  - `lookup_funcs` for `0x00560900`, `0x00560a10`, `0x00560a70`, `0x00560a97`, `0x00560aa0`, `0x00560aba`, `0x00560b00`, `0x0056caae`, `0x0056cac3`, and vtable bases.
  - `disasm` and `decompile` for `0x00560aa0`, `0x0056ca20`, and `0x00560900`.
  - `insn_query` over `0x00560aa0-0x00560aba` and `0x00560aba-0x00560b00`.
  - `get_bytes` for target, predecessor padding, successor gap, and `SetScrollPosition` control range.
  - `make_signature_for_range` for target and raw helper ranges.
  - `find_bytes` for target/show, hide, and predicate exact byte patterns plus VA/RVA pointer patterns for `0x00560ac0` and `0x00560ae0`.
  - `xrefs_to` for target, successor boundary, `0x00560b00`, constructor, vtable bases, and raw starts.
- by-* docs, support docs, old reports, generated reports, and trackers checked: target; [UID:0001GP], [UID:0000CL], [UID:0000JS], [UID:000453], [UID:0001YR], [UID:0002OS], [UID:00031O], `TextEditPaneScrollbarVariants`, generated `Group.cpp`, generated tracker/memory coverage/by-memory coverage rows, B005 `0001GP` report, and B002 `0000JS` report.
- Negative checks performed: no xrefs to `0x00560ac0` or `0x00560ae0`; no VA/RVA pointer-byte hits for `C0 0A 56 00`, `C0 0A 16 00`, `E0 0A 56 00`, or `E0 0A 16 00`; `lookup_funcs` reports no function at raw starts or raw ends.
- Failed, unavailable, or intentionally skipped checks and why: a first local `int_convert.py` multi-value invocation used the wrong CLI shape and returned one invalid-number error; values were rerun one-by-one. No MCP evidence call failed after the session was restored.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C-000452-001 | UID000452 is exactly `0x00560aa0-0x00560aba`, modeled `sub_560AA0`, size `0x1a` / 26 bytes (Verified with tools/int_convert.py). | High | `lookup_funcs`, `disasm`, `insn_query`, `get_bytes`. | Target `Address Range And Boundary`; [UID:0001GP] table. | incorporate | applied |
| C-000452-002 | Current `Show()` formal C++ is behavior-preserving and should remain unchanged. | High | Target decompile/disasm writes `+0x102 = 1` and invalidates `this+0x44`. | Target formal C++ and reconstruction notes. | already-present | already-present; preserved unchanged |
| C-000452-003 | Direct owner/emitter route remains [UID:0000CL] -> [UID:0000JS]. | High | constructor/caller route, vtables, class/file docs. | Target status; class/file pages. | already-present | already-present; preserved unchanged |
| C-000452-004 | Current successor-boundary prose is stale: `0x00560aba-0x00560b00` contains two raw helper bodies, not only alignment. | High | `insn_query`, `get_bytes`, `lookup_funcs` no-function checks. | Target, [UID:0001GP], [UID:000453], class/file support. | incorporate | applied |
| C-000452-005 | Create exact raw child `0x00560ac0-0x00560ada` as the inverse hide/disable helper. | Medium-high | raw bytes, no-xref/no-pointer checks, target `Show()` inverse pattern, sibling byte-pattern matches. | New [UID:0004I3] child; [UID:0001GP]; [UID:0000CL]; [UID:0000JS]. | incorporate | applied |
| C-000452-006 | Create exact raw child `0x00560ae0-0x00560afa` as `CanAdjust() const`, returning `m_scrollEnabled && m_scrollRange > 0`. | Medium-high | exact bytes; no-route checks; [UID:00031O] same predicate precedent. | New [UID:0004I5] child; [UID:0001GP]; [UID:0000CL]; [UID:0000JS]. | incorporate | applied |
| C-000452-007 | Target score can move from `86/89` to `89/91` after live evidence and boundary repair. | Medium-high | direct function/caller proof plus raw-gap correction; remaining original-name and class-declaration caps. | Target metadata and score rationale. | incorporate | applied |
| C-000452-008 | Raw helper starts have no direct xrefs or VA/RVA pointer-byte route in current MCP checks. | High | `xrefs_to`, `find_bytes` pointer-pattern checks. | New child evidence; parent no-route notes. | incorporate | applied |
| C-000452-009 | Exact target/show pattern is common across scrollbar/display controls, not unique to this class. | Medium-high | `find_bytes` exact target pattern found nine matches. | Target naming rationale; negative evidence. | incorporate | applied |

## Positive Evidence Summary

- Direct facts supporting the chosen recommendation:
  - UID000452 is an IDA-modeled function with eight instructions and a clean `retn` at `0x00560ab9`.
  - The body reads `m_scrollEnabled` at `+0x102`, writes it true on transition, and invalidates `m_bounds` at `+0x44` through inherited vtable slot `+0x20`.
  - `xrefs_to 0x00560aa0` reports the direct call from `NewGroupPane::NewGroupPane` at `0x0056cac3`.
  - Constructor/caller decompile confirms `NewGroupPane+0x100` receives the constructed `ScrollNewGroupPane` child before the `Show()` call.
- Corroborating documentation/generated-report evidence:
  - [UID:0000CL] and [UID:0000JS] already route ScrollNewGroupPane children through `Group.cpp`.
  - Generated `Group.cpp` contains the same `Show()` body, proving current emitted source matches the target formal block.
  - [UID:00031O] provides a source-ready precedent for the same raw enabled-and-range predicate pattern.
- Strongest inference chain and why it is sufficient: binary target bytes prove `Show()` behavior; constructor/caller route proves class ownership; support docs prove field names; raw sibling evidence proves the successor-boundary repair needed around the target.

## IDA MCP Facts

- Function/range facts:
  - `0x00560aa0`: `sub_560AA0`, size `0x1a` / 26 bytes (Verified with tools/int_convert.py).
  - `0x00560aba`: not a function.
  - `0x00560b00`: `sub_560B00`, size `0x1e1`.
  - `0x00560ac0`, `0x00560ada`, `0x00560ae0`, and `0x00560afa`: not functions.
- Data/table/padding facts:
  - `0x00560a97-0x00560aa0` is nine `0xcc` bytes before the target.
  - `0x00560aba-0x00560ac0`, `0x00560ada-0x00560ae0`, and `0x00560afa-0x00560b00` are six-byte `0xcc` alignment spans; `0x6` is 6 bytes (Verified with tools/int_convert.py).
  - `0x00560ac0-0x00560ada` clears byte `+0x102` and invalidates `+0x44`.
  - `0x00560ae0-0x00560afa` returns true only when byte `+0x102` is set and word `+0x100` is greater than zero.
- Xref facts:
  - `0x00560aa0` has one code xref from `0x0056cac3`.
  - `0x00560ac0` and `0x00560ae0` have zero xrefs.
  - `0x00560b00` has one data xref from secondary vtable slot `0x00623f6c`.
- Vtable/global/type facts:
  - Constructor stores `??_7ScrollNewGroupPane@@6B@` at `0x00560951`, secondary table at `0x00560957`, and tertiary table at `0x00560961`.
  - `entity_query` finds ScrollNewGroupPane vtable/RTTI names but no recovered source method names for `Show`, `Hide`, or `CanAdjust`.
- Negative IDA facts:
  - Target/show exact byte pattern is not unique; `find_bytes` found matches at `0x41d810`, `0x459a00`, `0x494c30`, `0x55c3a0`, `0x55f5f0`, `0x560aa0`, `0x561f50`, `0x563400`, and `0x5648b0`.
  - Hide exact pattern is likewise repeated, including `0x560ac0`.
  - Predicate exact pattern is repeated, including `0x560ae0` and the documented ScrollVolumePane match at `0x5648f0`.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00560aa0-0x00560aba` | [UID:000452] `by-memory/0x00560aa0-0x00560aba.ScrollNewGroupPaneShow.md` | modeled `Show()` transition helper | TRUE | `0000CL` | recommend `89/91` | keep and update evidence/boundary |
| `0x00560aba-0x00560ac0` | no child | padding | FALSE | none | n/a | replace broad padding row with exact padding subrow |
| `0x00560ac0-0x00560ada` | new [UID:0004I3] `by-memory/0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md` | raw inverse hide/disable helper | TRUE | `0000CL` | applied `86/89` initial | created |
| `0x00560ada-0x00560ae0` | no child | padding | FALSE | none | n/a | exact padding subrow |
| `0x00560ae0-0x00560afa` | new [UID:0004I5] `by-memory/0x00560ae0-0x00560afa.ScrollNewGroupPaneCanAdjustRaw.md` | raw enabled/range predicate | TRUE | `0000CL` | applied `88/90` initial | created |
| `0x00560afa-0x00560b00` | no child | padding | FALSE | none | n/a | exact padding subrow before `HandleMouseEvent` |
| `0x00560b00-0x00560ce1` | [UID:000453] `by-memory/0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md` | secondary-vtable mouse method | TRUE | `0000CL` | current `89/90` | update predecessor-boundary prose only |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00560900` | code xref `0x0056caae` | `NewGroupPane` constructs the scroll child. |
| `0x00560aa0` | code xref `0x0056cac3` | `NewGroupPane` invokes `Show()` after storing the child pointer. |
| `0x00560ac0` | zero xrefs, zero VA/RVA pointer-pattern hits | raw inverse helper is source-shaped but has no recovered static route. |
| `0x00560ae0` | zero xrefs, zero VA/RVA pointer-pattern hits | raw predicate is source-shaped but has no recovered static route. |
| `0x00560b00` | data xref `0x00623f6c` | secondary vtable mouse/input method follows the raw gap. |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion:
  - [UID:000452] already records the correct owner/emitter route and formal C++.
  - [UID:0000CL] documents `+0x102` as `m_scrollEnabled`, `+0x100` as `m_scrollRange`, and inherited `+0x44` as `m_bounds`.
  - [UID:0000JS] routes ScrollNewGroupPane children into `NexusTK/social/Group.cpp`.
  - `TextEditPaneScrollbarVariants` already lists `0x00560ac0` and `0x00560ae0` among raw/non-modeled helper starts that should be split when promoted.
- Existing docs that are stale, incomplete, or contradicted:
  - [UID:000452], [UID:000453], and [UID:0001GP] incorrectly describe the whole `0x00560aba-0x00560b00` span as alignment.
  - [UID:0000CL] method inventory skips the inverse and predicate raw helpers between `Show` and `HandleMouseEvent`.
  - [UID:0000JS] B005 core split summary says exact children run from `Show` directly to `HandleMouseEvent`, omitting the two raw starts.
- Generated/coverage report state:
  - `auto-generated/NexusTK/social/Group.cpp` currently emits UID000452 at `86/89`.
  - `auto-generated/-ag-memory-coverage.md` row lists UID000452 as coded, owner/emitter `0000CL`, position `45`.
  - Generated files were read only and not edited.

## Ranked Ownership Analysis

### 1. [UID:0000CL] `ScrollNewGroupPane`

- Evidence for: target receiver uses `ECX` as ScrollNewGroupPane object; constructor installs ScrollNewGroupPane vtables; `NewGroupPane` constructs and stores the child; fields `+0x100/+0x102/+0x44` are documented on the class; adjacent mouse/paint/update helpers are class-owned.
- Evidence against: exact original symbol spelling is not recovered, and raw helper starts have no direct static route.
- Decision: keep as direct owner and emitter for UID000452; use the same owner for the two implemented raw children.

### 2. [UID:0000JS] `Group`

- Evidence for: `NewGroupPane` is in the group feature file and directly constructs/calls this scrollbar; current generated route emits into `NexusTK/social/Group.cpp`.
- Evidence against: by-structure says a direct class owner should not be bypassed for file ownership when class ownership is clear.
- Decision: keep as final file route only through [UID:0000CL], not as canonical owner for UID000452.

### 3. Generic scrollbar / ScrollVolumePane / TextEditPane candidates

- Evidence for: exact target/hide/predicate byte patterns repeat across scrollbar-like controls; [UID:00031O] provides strong naming precedent.
- Evidence against: receiver vtables, constructor caller, owner callback, and class docs are ScrollNewGroupPane-specific; stale TextEditPane ownership is contradicted by current xrefs and support docs.
- Decision: use as source-shape precedent only; reject as owner/emitter.

### Proposed new file/grouping, if applicable

- Proposed owner/name/path: no new by-file. New exact raw child pages should route through [UID:0000CL] and [UID:0000JS].
- Likely full contents: no new source module; the helper bodies are part of `ScrollNewGroupPane` within `Group.cpp`.
- Candidate related items that belong: exact raw helpers at `0x00560ac0-0x00560ada` and `0x00560ae0-0x00560afa`.
- Candidate related items rejected: broad `TextEditPaneScrollbarVariants` aggregate ownership and generic scrollbar owner.
- Standalone, narrow, or broad source-file inference: narrow class-method children inside existing source file route.

## Source Placement

- Recommended source file/class/global/module placement: `ScrollNewGroupPane` class, emitted through `NexusTK/social/Group.cpp`.
- Why this placement fits source-tree and subsystem context: `NewGroupPane` owns the user-facing group pane and constructs the custom scrollbar; the class page already routes all ScrollNewGroupPane exact children through the Group file.
- Rejected placements and why: generic scrollbar rejected because the class-specific vtables and callback route dominate; file-only Group owner rejected because class owner clears the gate; TextEditPane rejected as stale/generated-owner pollution.
- Remaining placement uncertainty, if any: exact original source spelling for the new raw helper names is not proven.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts:
  - UID000452 remains exact half-open `0x00560aa0-0x00560aba`.
  - The successor span should be reclassified into padding/code/padding/code/padding, not a single padding row.
- Children/subranges to create, repair, merge, leave ignored, or leave no-owner:
  - Create `by-memory/0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md`.
  - Create `by-memory/0x00560ae0-0x00560afa.ScrollNewGroupPaneCanAdjustRaw.md`.
  - Do not merge either raw child into UID000452 or UID000453.
- Padding/table/data/code distinctions:
  - `0x00560aba-0x00560ac0`, `0x00560ada-0x00560ae0`, and `0x00560afa-0x00560b00` are `0xcc` alignment.
  - `0x00560ac0-0x00560ada` and `0x00560ae0-0x00560afa` are executable code with returns.
- Parent/container impact:
  - [UID:0001GP] should remain non-emitting but its covered-range inventory must list the two raw child pages.
  - [UID:000453] predecessor-boundary text should stop saying the whole preceding gap is alignment.

## Negative Evidence Summary

- `lookup_funcs` reports no IDA function at `0x00560ac0` or `0x00560ae0`.
- `xrefs_to` reports zero direct xrefs to both raw starts.
- `find_bytes` reports zero VA/RVA pointer-pattern hits for both raw starts.
- Exact byte patterns for `Show`, hide/disable, and the predicate recur in other controls, so byte uniqueness alone does not prove original method names.
- Constructor initializes `m_scrollEnabled` to true; the immediate `Show()` call is idempotent and should not be overclaimed as proving a visible state transition in that constructor path.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments:
  - Keep `ScrollNewGroupPane::Show()` for UID000452.
  - Use `ScrollNewGroupPane::Hide()` for `0x00560ac0-0x00560ada`, with `Disable` recorded as a behavior alias.
  - Use `bool ScrollNewGroupPane::CanAdjust() const` for `0x00560ae0-0x00560afa`.
  - Keep field names `m_scrollEnabled` at `+0x102`, `m_scrollRange` at `+0x100`, and `m_bounds` at `+0x44`.
- Evidence for each accepted/implemented name/type/comment:
  - `Show()` is accepted and directly called from `NewGroupPane`.
  - `Hide()` is the exact inverse of `Show()` over the same field/invalidation path.
  - `CanAdjust() const` follows the accepted [UID:00031O] precedent and avoids collision with the existing false virtual `CanScroll(int)`.
- Items intentionally left unchanged and why:
  - Do not rename UID000452 to `Enable` in this callback; broader class naming consistency should be handled when the new inverse child is created.
  - Do not claim original symbol proof for `Hide` or `CanAdjust`.
- Whether IDA DB edits are safe, unsafe, or not requested: no IDA DB edits requested or performed.

## First-Draft C++ Recommendation

- Eligible for draft C++: UID000452 is already eligible and populated. The two implemented raw children are source-shaped and now carry first-draft C++.
- Accepted code: exact formal `RECONSTRUCTION_CPP CODE` header/block insertion text only.

For existing [UID:000452] target, keep:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScrollNewGroupPane::Show()
{
    if (m_scrollEnabled) {
        return;
    }

    m_scrollEnabled = true;
    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

For proposed `by-memory/0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void ScrollNewGroupPane::Hide()
{
    if (!m_scrollEnabled) {
        return;
    }

    m_scrollEnabled = false;
    InvalidateRect(&m_bounds);
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

For proposed `by-memory/0x00560ae0-0x00560afa.ScrollNewGroupPaneCanAdjustRaw.md`:

```cpp
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool ScrollNewGroupPane::CanAdjust() const
{
    return m_scrollEnabled && m_scrollRange > 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive, when applicable: not applicable.
- Reason it preserves exact original behavior: each body matches direct byte-level side effects: guarded byte write plus invalidation for show/hide, and enabled/range read-only predicate for `CanAdjust`.
- Reason it matches the most plausible original precompiled mid-2000s developer source shape: small private member helpers with ordinary field names and early returns match existing ScrollNewGroupPane and ScrollVolumePane child style.
- Inferred source-facing names/types/fields used instead of IDA/decompiler labels: `m_scrollEnabled`, `m_scrollRange`, `m_bounds`, `InvalidateRect`.
- Naming/coding style convention used and evidence for consistency: current generated `Group.cpp` uses `m_` fields, early returns, and child methods under `ScrollNewGroupPane`; [UID:00031O] uses `CanAdjust() const` for the same predicate.
- Reason code should remain blank, if applicable: not applicable for UID000452; if supervisor rejects raw child creation, the child C++ blocks should not be applied.
- Exact no-code proof, if not eligible: not applicable for UID000452.

## Final Recommendation

- Exact changes applied or recommended: implementation callback applied the accepted target evidence/score update, support boundary repair, and creation of two exact raw helper children.
- Exact parent assignments applied or recommended: UID000452 owner/emitter remains [UID:0000CL]; new [UID:0004I3] and [UID:0004I5] children are assigned to [UID:0000CL] with emitters [UID:0000CL].
- Exact items left no-owner/non-emitting and why: only alignment subranges remain no-child/padding; no source-bearing item remains in the old successor gap.
- Exact future work, if any, outside this assignment scope: a later whole-class naming pass can decide whether to normalize `Show/Hide` versus `Enable/Disable` across all scrollbar controls and whether to renumber emitter positions for strict source-order output.

## Recommended Target Doc Changes

- Target path: `by-memory/0x00560aa0-0x00560aba.ScrollNewGroupPaneShow.md`.
- Exact report facts to incorporate:
  - Add live MCP session `b001-0001I5` evidence for function size, disassembly, decompile, direct caller, bytes, and constructor idempotence.
  - Replace successor-boundary prose with exact wording: `0x00560aba-0x00560ac0` is padding, followed by raw inverse helper `0x00560ac0-0x00560ada`, padding `0x00560ada-0x00560ae0`, raw predicate `0x00560ae0-0x00560afa`, and padding `0x00560afa-0x00560b00` before `HandleMouseEvent`.
  - Record that target exact C++ remains unchanged.
- Metadata/score/owner/emitter/reconstructable/C++ changes: update `86/89` to `89/91`; keep `CANONICAL_OWNER:0000CL`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000CL`, position `45`, and formal C++ unchanged.
- Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: preserve that original symbol spelling remains inferred; record that the old broad successor-padding statement is stale; record no xrefs/pointer hits for raw helper starts.

## Recommended Support Doc Changes

- Support path: `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md`.
- Exact report facts to incorporate: split the current `0x00560aba-0x00560b00` padding row into the five subranges listed in this report, add links to the two new raw child pages after validator UID assignment, and update IDA evidence to include raw starts `0x00560ac0` and `0x00560ae0`.
- Metadata/link/score/coverage/source-placement changes: keep parent non-emitting. Consider raising parent from `88/90` to `89/91` only if the child pages are created and validator links are clean.

- Support path: `by-class/ScrollNewGroupPane.md`.
- Exact report facts to incorporate: add method rows for `Hide` / `0x00560ac0-0x00560ada` and `CanAdjust() const` / `0x00560ae0-0x00560afa`; add evidence note that these raw starts are no-function/no-xref/no-pointer but byte-identical to accepted scrollbar-family helpers.
- Metadata/link/score/coverage/source-placement changes: no required class score change; optional modest class confidence increase only after the support inventory is synchronized.

- Support path: `by-file/Group.md`.
- Exact report facts to incorporate: update ScrollNewGroupPane proposed-content/core split summary so the exact children no longer jump from UID000452 directly to UID000453; include the two new raw child pages after UID assignment.
- Metadata/link/score/coverage/source-placement changes: no required file score change.

- Support path: `by-memory/0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md`.
- Exact report facts to incorporate: correct predecessor-boundary prose to say the immediate `0x00560afa-0x00560b00` span is alignment after the raw predicate, not that `0x00560aba-0x00560b00` is all alignment after Show.
- Metadata/link/score/coverage/source-placement changes: no required metadata change.

- Support path: new `by-memory/0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md`.
- Exact report facts to incorporate: exact bytes, no-function status, zero xrefs/pointer hits, inverse relation to UID000452, owner/emitter [UID:0000CL], formal `Hide()` C++.
- Metadata/link/score/coverage/source-placement changes: validator assigns UID; recommend initial `86/89`, reconstructable true, owner/emitter [UID:0000CL], emitter position between 45 and 46 if the project permits fractional/renumbered positions, otherwise leave blank and document ordering in support.

- Support path: new `by-memory/0x00560ae0-0x00560afa.ScrollNewGroupPaneCanAdjustRaw.md`.
- Exact report facts to incorporate: exact bytes, no-function status, zero xrefs/pointer hits, predicate behavior, [UID:00031O] precedent, owner/emitter [UID:0000CL], formal `CanAdjust() const` C++.
- Metadata/link/score/coverage/source-placement changes: validator assigns UID; recommend initial `88/90`, reconstructable true, owner/emitter [UID:0000CL], emitter position between hide and `HandleMouseEvent` if possible, otherwise leave blank and document ordering in support.

## Score And Metadata Recommendation

- Pre-implementation score/metadata: UID000452 was `86/89`, owner/emitter [UID:0000CL], reconstructable true, position `45`, formal C++ populated.
- Recommended score/metadata: `89/91`; owner/emitter/reconstructable/position unchanged; formal C++ unchanged.
- Score rationale and reason not higher/lower:
  - Raise completion because live MCP evidence now proves exact bytes, disassembly, decompile, caller, constructor context, repeated byte-pattern caveat, and corrected successor split.
  - Raise confidence because the C++ is directly byte-backed and the owner route is strongly corroborated.
  - Do not exceed `91` because exact original symbol spelling is unrecovered, target byte pattern is not unique, the new raw sibling children still have no static route/original symbols, and the class declaration/source header remains below final audit quality.
- Score-improvement attempt:
  - Original-name blocker: investigated with `entity_query`, caller context, sibling docs, and byte-pattern matches; resolved to keep accepted `Show()` as inferred, not original-proof.
  - Successor-boundary blocker: live `get_bytes`/`insn_query` resolved it; recommend child creation.
  - C++ readiness blocker: decompile/disassembly verified existing formal C++; no change needed.
  - Owner/emitter blocker: constructor/caller/vtable support confirms existing route; no change needed.
- Metadata fields to change or leave unchanged: change only completion/confidence; leave owner/emitter/reconstructable/position/C++ unchanged.

## Open Questions With Attempted Resolution

- Open question: is `Show` the exact original name or should it be `Enable`?
  - Evidence checked: direct caller, current support docs, generated output, sibling ScrollVolumePane `Enable/Disable`, and raw inverse body.
  - Best supported resolution: keep `Show` now because it is already accepted and pairs naturally with proposed `Hide`; document `Enable` as behavior alias only.
  - Remaining unresolved impact: exact original spelling is unknown; caps confidence below final-audit range but does not block C++.
- Open question: should the raw inverse and predicate helpers emit C++ despite no xrefs?
  - Evidence checked: raw bytes, pointer patterns, xrefs, sibling ScrollVolumePane precedent, field roles, and class support.
  - Best supported resolution: yes, if child pages are created. No-route remains a liveness/confidence cap, not a C++ blocker.
- Open question: why does `NewGroupPane` call `Show()` after the constructor initializes `m_scrollEnabled` true?
  - Evidence checked: constructor disassembly/decompile and caller disassembly/decompile.
  - Best supported resolution: source likely used an idempotent ensure-visible call after construction; binary behavior is still exactly the transition-only helper.
- Questions remaining unresolved: exact original names for `Hide` and `CanAdjust` remain unproven because no PDB/source symbols or static raw-start routes exist. The recommended names are inferred from local and sibling source shape.

## Validator Results

- Initial UID assignment:
  - `python .\tools\validator.py --mode file --file by-memory\0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md --apply --queue-timeout 240`
    - command_id `000000007658`, timestamp `2026-07-06T18:59:29-04:00`, exit `0`, inserted UID `0004I3`, generated_refresh `deferred`.
  - `python .\tools\validator.py --mode file --file by-memory\0x00560ae0-0x00560afa.ScrollNewGroupPaneCanAdjustRaw.md --apply --queue-timeout 240`
    - command_id `000000007660`, timestamp `2026-07-06T18:59:36-04:00`, exit `0`, inserted UID `0004I5`, generated_refresh `deferred`.
- Final scoped validators:
  - UID000452 target: command_id `000000007702`, timestamp `2026-07-06T19:08:44-04:00`, exit `0`, `ok: 1`, score update registered; rerun after repeated-pattern note command_id `000000007709`, timestamp `2026-07-06T19:10:21-04:00`, exit `0`, `ok: 1`.
  - [UID:0001GP] parent split index: command_id `000000007703`, timestamp `2026-07-06T19:09:00-04:00`, exit `0`, `ok: 1`.
  - [UID:0000CL] class support: command_id `000000007704`, timestamp `2026-07-06T19:09:05-04:00`, exit `0`, `ok: 1`.
  - [UID:0000JS] file support: command_id `000000007705`, timestamp `2026-07-06T19:09:16-04:00`, exit `0`, `ok: 1`; warning `missing_ref_uid 0003XA` was pre-existing/unrelated and left untouched.
  - [UID:000453] successor: command_id `000000007706`, timestamp `2026-07-06T19:09:27-04:00`, exit `0`, `ok: 1`.
  - [UID:0004I3] new HideRaw child: command_id `000000007707`, timestamp `2026-07-06T19:09:35-04:00`, exit `0`, `ok: 1`.
  - [UID:0004I5] new CanAdjustRaw child: command_id `000000007708`, timestamp `2026-07-06T19:09:46-04:00`, exit `0`, `ok: 1`.
- Generated/coverage/manual edits: no manual generated-file, coverage-report, validator-state, supervisor-ledger, lifecycle, archive, or execute-report edits were made. Validator file-mode runs reported `generated_refresh: deferred` as their normal scoped side effect.

## Leases

- Lease acquisition command: `python .\tools\leaser\leaser.py B007 lease by-memory\0x00560aa0-0x00560aba.ScrollNewGroupPaneShow.md by-memory\0x00560900-0x0056141f.ScrollNewGroupPaneCore.md by-class\ScrollNewGroupPane.md by-file\Group.md by-memory\0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md`
  - Result: exit `0`; all five existing target/support by-* docs returned `Success`.
- New child files were created before UID assignment and were not pre-leased because they did not yet exist.
- Release check: `tools/leaser/Agents/current_leases.md` reported `No active leases`.
- Release command: `python .\tools\leaser\leaser.py B007 unlease by-memory\0x00560aa0-0x00560aba.ScrollNewGroupPaneShow.md by-memory\0x00560900-0x0056141f.ScrollNewGroupPaneCore.md by-class\ScrollNewGroupPane.md by-file\Group.md by-memory\0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md`
  - Result: exit `1`; each path returned `Rejected[No active lease]`, matching the central report's no-active-lease state.

## Changed Files

- Created:
  - `by-memory/0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw.md`
  - `by-memory/0x00560ae0-0x00560afa.ScrollNewGroupPaneCanAdjustRaw.md`
- Modified target/support by-* docs:
  - `by-memory/0x00560aa0-0x00560aba.ScrollNewGroupPaneShow.md`
  - `by-memory/0x00560900-0x0056141f.ScrollNewGroupPaneCore.md`
  - `by-class/ScrollNewGroupPane.md`
  - `by-file/Group.md`
  - `by-memory/0x00560b00-0x00560ce1.ScrollNewGroupPaneHandleMouseEvent.md`
- Modified report:
  - `tools/leaser/Agents/Agent-B007/research/000452-ScrollNewGroupPaneShow-source-quality.md`
- Renamed: none.
- Report execution: not run. `execute_report`, dry-run execute variants, registry lifecycle commands, manual report moves, archive moves, and equivalent lifecycle/archive commands were not run.

## Implementation Tracking Checklist

Initial report-only pass:
- [x] Supervisor validation required before implementation: Gate 1 passed and supervisor sent implementation callback.
- [x] Target/support docs to update: target UID000452; parent [UID:0001GP]; class [UID:0000CL]; file [UID:0000JS]; successor [UID:000453]; create two new raw child pages.
- [x] Current target state and actual evidence checked recorded: live MCP session `b001-0001I5`, target disasm/decompile/bytes/xrefs, constructor/caller evidence, generated rows, old reports, and sibling raw predicate precedent are recorded above.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim: ledger rows C-000452-001 through C-000452-009 are now applied or already-present.
- [x] Metadata/score changes to apply: UID000452 `86/89` -> `89/91`; no owner/emitter/reconstructable/position/C++ change.
- [x] Score-limiting blockers researched to resolution, implementation-ready repair/split recommendation, or rare exact evidence-backed no-improvement proof after all reasonable current routes were exhausted: original-name uncertainty remains confidence cap; stale boundary converted into implemented child split; no-route raw helpers converted into child docs.
- [x] Owner/emitter/reconstructable changes to apply: none for UID000452; new raw children use owner/emitter [UID:0000CL], reconstructable true.
- [x] Split/rename/new-child changes to apply: created `0x00560ac0-0x00560ada.ScrollNewGroupPaneHideRaw` and `0x00560ae0-0x00560afa.ScrollNewGroupPaneCanAdjustRaw`; UID000452 was not renamed.
- [x] Source-placement, range/split/padding/reclassification, or IDA rename/type/comment changes to apply or confirm not applicable: reclassified `0x00560aba-0x00560b00` into exact padding/raw/padding/raw/padding subranges in support docs; no IDA DB changes.
- [x] First-draft C++ or no-code proof to apply: kept UID000452 formal C++; inserted accepted formal C++ for [UID:0004I3] and [UID:0004I5].
- [x] Third-party import directive to apply or confirm not applicable, including exact `third_party_embeds/...` paths and confirmation that the multiline C++ block remains blank: not applicable.
- [x] Exact target/support doc facts to incorporate at report-level detail: live MCP facts, byte patterns, no-route checks, constructor idempotence, field roles, and sibling precedent incorporated.
- [x] Historical/stale assumptions, rejected alternatives, and negative evidence to preserve: old broad-padding statement recorded as stale, `Enable` rename rejected for this pass, no raw-start xrefs/pointers and repeated byte-pattern matches recorded.
- [x] Wave2/Wave3 mentions or artifacts encountered and ignored/rejected as stale, if applicable: current class docs note stale generated/TextEditPane owner pollution; this report rejects it for UID000452 and raw children.
- [x] Open questions to close or document as evidence-backed unresolved: exact original helper names remain unproven and cap score only.
- [x] Validators to run: scoped file validators ran for the two new child pages, UID000452 target, [UID:0001GP], [UID:000453], [UID:0000CL], and [UID:0000JS]. `execute_report` was not run.
- [x] Generated report refresh expected or explicit manual supervisor-owned coverage/tracker text to apply: no manual generated/coverage/tracker edits; validator-owned generated refresh was reported as deferred by scoped validators.

Implementation callback pass:
- [x] Existing leases acquired before editing target/support by-* docs; central lease report showed no active leases at release time and explicit unlease returned `Rejected[No active lease]` for the same paths.
- [x] New child pages created without guessed UIDs, then validated so the validator assigned [UID:0004I3] and [UID:0004I5].
- [x] Accepted report details applied to target and support by-* docs only.
- [x] Report ledger and checklist updated after implementation.
- [x] Scoped validators run and recorded with command metadata.
- [x] Lifecycle/archive/execute commands avoided.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000007724","destination_path":"executed-b-agent-research/B007/000452-ScrollNewGroupPaneShow-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/000452-ScrollNewGroupPaneShow-source-quality.md","timestamp":"2026-07-06T19:24:07-04:00","uid":"000452"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
