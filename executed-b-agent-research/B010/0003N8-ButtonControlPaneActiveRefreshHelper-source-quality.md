** TARGET-REPORT-UID:0003N8 **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Agent-B010 Source-Quality Report: [UID:0003N8] ButtonControlPaneActiveRefreshHelper

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003N8] as a reconstructable, ButtonControlPane-owned retained raw selected-frame draw helper at `0x00495010-0x0049503d`.
- Current disposition: target/support by-* docs now contain the accepted 87/88 owner, field, callee, no-route, and no-body details at same-or-greater factual detail. The implementation callback removed the target-body reference C++ snippet and preserved blank formal C++.
- Current metadata state: `COMPLETION:87`, `CONFIDENCE:88`, `CANONICAL_OWNER:00001E`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001E`, blank `EMITTER_POSITION_OPTIONAL`, and blank formal C++.
- Final no-code disposition: no standalone formal method body. The helper has live source-shaped bytes and a strong owner, but current IDA MCP plus local route evidence still finds no modeled function object, no start xrefs, no caller, no vtable/table pointer, no VA/RVA literal route, and no direct branch/call route to `0x00495010`.
- Required action after Gate 1: supervisor may verify already-present target/support incorporation claim by claim. Do not edit generated files, coverage reports, validator state, lifecycle files, or the validator-owned history footer.
- Confidence: high for bytes, boundaries, owner, field map, and no-route evidence; intentionally below 90 because helper reachability and exact original helper spelling remain unproven.

## Supporting Research

- This is a de-executed active research copy returned by validator command `000000006852` for report-text repair. The previous lifecycle status was historically `needs-revalidation`; the historical reason was `target_uid_unknown: 0003N8`.
- Per the supervisor narrow override for this active research copy, the old top-level status/reason header lines were removed. This report preserves the validator-owned `VALIDATOR-REPORT-HISTORY` footer unchanged.
- The target by-memory file now exists at `by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md` and its first header line is `*** UID:0003N8 | DO NOT MODIFY OR REMOVE!!! ***`, so the target UID is present in the current source doc.
- Read-only generated/tracker checks found no current `0003N8`, `0x00495010`, or `ButtonControlPaneActiveRefreshHelper` hit in `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-memory-coverage.md`, or `project-level/-auto-completion-stats.md`. Manual `by-memory/-coverage-report.md` still shows the broad [UID:000118] ButtonChoice aggregate row but no [UID:0003N8] child row.
- Read-only validator metadata cache still has the old executed-report entry at `executed-b-agent-research/B010/0003N8-ButtonControlPaneActiveRefreshHelper-source-quality.md` with the historical status/reason. The active research copy is not repaired through cache edits; registry/lifecycle state remains supervisor/validator-owned.
- Current IDA MCP evidence was reacquired through the active session `supervisor_recovery_20260705`: `idb_list` returned `count=1`, active worker `pid=19604`; `server_health` returned `status: ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, and `strings_cache_ready:true`.
- No target/support by-* docs, generated files, coverage reports, validator state, supervisor ledgers, lifecycle/archive files, or registry state were edited during this report-only repair.

## Target

- UID: `0003N8`
- Target doc: `source-3/project-documentation/by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/0003N8-ButtonControlPaneActiveRefreshHelper-source-quality.md`
- Current metadata: `COMPLETION:87`, `CONFIDENCE:88`, `CANONICAL_OWNER:00001E`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001E`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Historical pre-incorporation metadata: earlier report text and old generated-marker observations used `COMPLETION:85`, `CONFIDENCE:86`; that is not the current target state.
- Recommended metadata: no new score/owner/emitter change. Preserve `87/88`, `CANONICAL_OWNER:00001E`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001E`, blank optional position, and blank formal C++.

## Current Target State

- Existing target state: [UID:0003N8] is a `0x2d`-byte raw executable helper between `0x0049500d-0x00495010` and `0x0049503d-0x00495040` `0xcc` padding spans.
- Existing owner/emitter state: [UID:00001E] `ButtonControlPane` remains the canonical owner and emitter route through [UID:0000HY] `ButtonControlPane.cpp`.
- Existing C++/emitter state after callback: formal `RECONSTRUCTION_CPP` is blank. The former body-only "Reference only" C++ shape under target `## C++ Policy` was converted to prose no-code proof; no C++ body/example remains outside the formal block.
- Existing blocker: route/liveness is still not proven. The helper is source-shaped and strongly owned, but it has no IDA function object or start xrefs and no current direct route.
- Related support state: `by-class/ButtonControlPane.md`, `by-file/ButtonControlPane.md`, and `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md` already carry the later B010 details at same-or-greater specificity, including visible/selected field map, no-body policy, and ButtonControlPane source placement.
- Current artifact/lifecycle status: active repaired report in `tools/leaser/Agents/Agent-B010/research/`; not executed by B010. Historical de-execution/revalidation state is recorded only as lifecycle context above and in the unchanged footer.

## Executive Recommendation

[UID:0003N8] is a real, source-shaped, ButtonControlPane-owned raw helper, but current evidence still does not prove any caller, vtable slot, pointer table, or hidden branch route into `0x00495010`. Keep the owner/emitter route through [UID:00001E] `ButtonControlPane`, but do not emit a standalone C++ method body from this target.

Best current source-facing role/name:

- Preferred role: `ButtonControlPane` selected-frame draw/refresh helper gated by inherited visibility.
- Preferred source-name direction only if a future route is proven: `ButtonControlPane::DrawSelectedFrameIfVisible()`.
- IDA/local label direction while route is unproven: `raw_ButtonControlPane_DrawSelectedFrameIfVisible_00495010` or `ButtonControlPane_DrawSelectedFrameIfVisibleRaw`.

Current field/callee map to preserve:

- `this+0x101`: inherited `ControlPane` visible flag, set/cleared by [UID:0003N3] and [UID:0003N4], not a ButtonControlPane-specific active flag.
- `this+0x108`: ButtonControlPane selected flag, written by `SetControlSelected` at `0x00494f40`.
- `this+0x70`: inherited GrafPort draw/blit mode byte, cleared to mode `0` before drawing.
- `this+0x44`: inherited `RectBounds` / pane bounds passed to `GrafPort::DrawRectFrame`.
- `0x004b9660`: [UID:000162] `GrafPort::SetDrawColor` / active draw-fill color setter, value `1`, storing GrafPort draw color at `+0x74`.
- `0x004ba450`: [UID:000168] `GrafPort::DrawRectFrame(const RectBounds *rect)`.

## Heuristic / Inference Reanalysis And Validation

- Raw helper role: the bytes implement a conditional selected-frame draw path. The helper checks visibility and selected state, sets the draw color to `1`, clears draw/blit mode, and draws the current bounds rectangle. This is a behavioral inference validated against MCP bytes/listing, neighboring ButtonControlPane methods, and GrafPort callee docs.
- Field inference: `+0x101` is inherited visibility, not active/enabled. Validation came from [UID:0003N3], [UID:0003N4], [UID:0002PD], [UID:000038], and the contrast with [UID:0003N9], which checks both `+0x101` and active byte `+0x102`.
- Selected-state inference: `+0x108` is ButtonControlPane selected state because `SetControlSelected` compares/stores that byte and invalidates bounds `+0x44`; constructor evidence clears the byte.
- Callee inference: `sub_4B9660` and `sub_4BA450` are dependency calls into GrafPort draw state and frame drawing, not ButtonControlPane-owned methods. Generated names such as `FittingRoomListPane::SetTextColor` are rejected as caller-biased pollution.
- Ownership inference: ButtonControlPane is the narrow source owner because of address locality after `OnKeyPress`, use of the selected byte, and support-doc vtable/source placement. TextButton, TextButtonEx, SelectBox, GrafPort, and feature owners were rechecked and rejected.
- Route/liveness inference: source-shaped bytes are not enough to emit a callable body. MCP confirms no function object and no start xrefs. Local route scans found no direct call/jump or VA/RVA pointer route and rejected two constructor-displacement false positives. The no-code recommendation is therefore an exact no-route proof, not a placeholder.
- Score validation: current `87/88` is defensible because the stale field/callee/owner issues were resolved and incorporated, while unresolved reachability and exact original helper spelling keep confidence below 90.
- Wave2/Wave3 handling: old feature/decompiler owner pollution was treated only as search context and rejected in favor of current by-* docs, current MCP facts, and manual bytes/route evidence.

## Evidence Standards Used

- Direct IDA MCP evidence: session health, exact function lookup, xrefs to target and controls, exact bytes, bounded rendered listing searches, and unique range signature.
- Manual/local binary evidence: prior raw PE extraction, Capstone disassembly, section-mapped rel32 call/jump scans, absolute VA/RVA literal scans, and positive-control scans.
- Documentation evidence: current target/support by-* pages for ButtonControlPane, ButtonChoiceControlCore, ControlPane, GrafPort, TextButton, TextButtonEx, SelectBox, and related raw helper pages.
- Generated/tracker evidence: generated ButtonControlPane.cpp header, auto-generated coverage/tracker misses, manual coverage aggregate row, and validator metadata-cache historical entry were used as lifecycle/source-route context, not source-of-truth.
- Evidence strength: strong for bytes, fields, callees, owner, and no-start-xref; capped for final C++ because no current route proves that an original source body was reachable as a normal method.

## Evidence Checked

Documentation read/rechecked:

- Target [UID:0003N8] `by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md`.
- [UID:00001E] `by-class/ButtonControlPane.md`.
- [UID:0000HY] `by-file/ButtonControlPane.md`.
- [UID:000118] `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md`.
- [UID:0000EJ] `by-class/TextButtonControlPane.md`.
- [UID:0000EK] `by-class/TextButtonExControlPane.md`.
- [UID:000038] `by-class/ControlPane.md`.
- [UID:0002PD] `by-memory/0x00494b50-0x00494c80.ControlFamilyStateVirtualHelpers.md`.
- [UID:0003N9] `by-memory/0x00494c50-0x00494c80.ControlPaneDrawActiveFrameHelper.md`.
- [UID:000162] `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`.
- [UID:000168] `by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md`.
- [UID:00005V] `by-class/GrafPort.md`.
- `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp`.
- `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, and current stale `by-memory/-coverage-report.md` text around the ButtonChoice block.
- Prior B003 split report: `Agent-B003/research/executed/older/000118-ButtonChoiceControlCore-ownership-research.md`.
- Analogous B002 raw helper report: `Agent-B002/research/executed/older/0003N9-ControlPaneDrawActiveFrameHelper-current-goal2-pass.md`.

Tool/evidence checks performed in this pass:

- Raw PE byte extraction from read-only `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Capstone disassembly of `0x00494eb0-0x0049503d`, including ButtonControlPane constructor, `SetControlSelected`, `OnKeyPress`, and the raw target body.
- Section-mapped rel32 call/jump scan for `0x00495010`, target interiors, callees `0x004b9660`/`0x004ba450`, and positive controls `0x00495040`, `0x00494f70`, and `0x00494f40`.
- Absolute VA/RVA literal scan for target start/interiors and positive controls.
- Current IDA MCP session `supervisor_recovery_20260705`: `idb_list` count `1`; `server_health` OK; `lookup_funcs` for `0x00495010`, `0x00495040`, `0x00494f70`, `0x00494f40`, `0x004b9660`, and `0x004ba450`; `xrefs_to` for target start/interior addresses plus positive controls; `get_bytes` over `0x0049500d` size `0x33`; bounded `search_text` inside `0x00495010-0x0049503d`; and `make_signature_for_range 0x00495010-0x0049503d`.
- Read-only `rg` checks for `0003N8`, `0x00495010`, and `ButtonControlPaneActiveRefreshHelper` in generated research tracker, generated memory coverage, project-level completion stats, manual memory coverage, generated ButtonControlPane.cpp, validator metadata cache, and support docs.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| B010-0003N8-C001 | The active report copy must not carry top-level historical status/reason headers; prior status was historical lifecycle context only. | High | Goal override; existing footer command `000000006852`; current top-level repair. | This report `Supporting Research`; validator footer unchanged. | historicalize | applied |
| B010-0003N8-C002 | Target UID `0003N8` exists in the current by-memory header. | High | First line of target doc: `*** UID:0003N8 ... ***`. | Target `Header`; report `Current Target State`. | already-present | already-present |
| B010-0003N8-C003 | Current metadata is `COMPLETION:87`, `CONFIDENCE:88`, `CANONICAL_OWNER:00001E`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00001E`, blank formal C++. Historical `85/86` is pre-incorporation only. | High | Target metadata headers read from current by-memory doc. | Target metadata headers; report `Score And Metadata Recommendation`. | already-present | already-present |
| B010-0003N8-C004 | The helper is exactly `0x00495010-0x0049503d` / `0x2d` bytes with `cc cc cc` padding before and after. | High | MCP `get_bytes` over `0x0049500d` size `0x33`; prior PE/Capstone bytes. | Target `Covered Range`/`Raw Behavior`; aggregate child row. | already-present | already-present |
| B010-0003N8-C005 | IDA currently does not model `0x00495010` as a function. | High | MCP `lookup_funcs 0x00495010` -> `Not a function`; adjacent starts resolve normally. | Target `IDA MCP Evidence`/`Route And Liveness`; support aggregate boundary row. | already-present | already-present |
| B010-0003N8-C006 | There are zero start xrefs to `0x00495010`; interior xrefs are only internal flow/branches. | High | MCP `xrefs_to 0x00495010` `xref_count:0`; interiors show references from `0x495011`, `0x49501a`, `0x495023`, `0x49502f`. | Target no-route proof; report `Negative Evidence Summary`. | already-present | already-present |
| B010-0003N8-C007 | No direct call/jump or VA/RVA pointer route to target start/interiors was found; two rel32-looking hits are constructor-displacement false positives. | High | Prior B010 section-mapped route scans and false-positive analysis; positive controls found nearby routes. | Target route proof; support class/file/aggregate no-body notes. | already-present | already-present |
| B010-0003N8-C008 | `this+0x101` is inherited ControlPane visible flag, not active/enabled. | High | MCP listing at `0x495013`; ControlPane set/clear docs; contrast with active byte `+0x102`. | Target field map; ButtonControlPane class notes; aggregate child row. | already-present | already-present |
| B010-0003N8-C009 | `this+0x108` is ButtonControlPane selected state written by `SetControlSelected`. | High | MCP listing at `0x49501c`; `lookup_funcs 0x00494f40` size `0x24`; ButtonControlPane docs. | Target field map; ButtonControlPane class/file. | already-present | already-present |
| B010-0003N8-C010 | `this+0x70` is inherited GrafPort draw/blit mode; `this+0x44` is inherited bounds passed to frame draw. | High | MCP listing at `0x49502f` and `0x49502c`; GrafPort and support docs. | Target field map; support docs. | already-present | already-present |
| B010-0003N8-C011 | `0x004b9660` is GrafPort draw-color state and `0x004ba450` is `GrafPort::DrawRectFrame`. | High | MCP calls at `0x495027` and `0x495036`; callee lookup sizes; GrafPort target docs. | Target raw behavior/field map; support docs. | already-present | already-present |
| B010-0003N8-C012 | Best owner/source route remains ButtonControlPane through [UID:0000HY] `NexusTK/ui/controls/ButtonControlPane.cpp`; TextButton/TextButtonEx/SelectBox/GrafPort/feature owners are rejected. | High | Address locality, field use, support docs, current source route docs, negative owner evidence. | Target status; ButtonControlPane class/file; aggregate. | already-present | already-present |
| B010-0003N8-C013 | Formal C++ should remain blank and no standalone body should be emitted until a route or accepted retained-helper body policy is proven. | High | No IDA function/xref/route; generated file lacks UID marker; support no-body wording; target formal block remains blank after callback. | Target formal C++ block and `C++ Policy`; generated route notes. | incorporate | applied |
| B010-0003N8-C014 | Body-only illustrative C++ in the target body should be removed or converted to prose in any callback; this report intentionally omits sample code. | High | Current workflow first-draft C++ rule; target `## C++ Policy` previously contained a reference-only body snippet. | Target `C++ Policy`; report `First-Draft C++ Recommendation`. | incorporate | applied |
| B010-0003N8-C015 | Manual/generated coverage remains a supervisor/validator-owned follow-up; do not edit coverage manually in this B010 repair. | High | Generated tracker/coverage no matches; manual coverage broad UID000118 row only; workflow boundaries. | Report `Exact Manual Supervisor-Owned Coverage Or Tracker Text`; supervisor-owned coverage/tracker only. | not-applicable | excluded-with-reason |
| B010-0003N8-C016 | Optional GrafPort backlinks can be skipped because support docs already have same-or-greater dependency detail for `+0x70`, `+0x74`, and `DrawRectFrame`, and this callback scope did not require them. | Medium-high | `by-class/GrafPort.md` and GrafPort by-memory docs already document the dependency meanings; target/support pages link the exact callees. | Optional GrafPort support docs. | not-applicable | excluded-with-reason |

## Positive Evidence Summary

- Exact bytes and padding are stable: MCP `get_bytes` returns the three pre-padding bytes, the full `0x2d` helper body, and the three post-padding bytes exactly as prior local PE extraction recorded.
- Current MCP lookup resolves adjacent modeled functions (`0x00495040`, `0x00494f70`, `0x00494f40`, `0x004b9660`, `0x004ba450`) while rejecting `0x00495010` as not a function, matching the raw-helper classification.
- Bounded MCP listing searches confirm the key instructions: `cmp [esi+101h]`, `cmp [esi+108h]`, `call sub_4B9660`, `lea [esi+44h]`, `mov [esi+70h],0`, and `call sub_4BA450`.
- ButtonControlPane support docs already place this exact helper in the base button family and preserve the selected-frame draw role, no-route/no-body policy, and rejected owner alternatives.
- The support aggregate [UID:000118] already lists [UID:0003N8] as the exact raw child and keeps the broad aggregate non-emitting.

## Range / Split / Padding / Reclassification Analysis

Fresh MCP and prior PE bytes confirm the existing half-open range:

Fresh PE bytes confirm the existing half-open range:

```text
0x0049500d-0x00495010: cc cc cc
0x00495010-0x0049503d:
  56 8b f1
  80 be 01 01 00 00 00 74 1f
  80 be 08 01 00 00 00 74 16
  6a 01 e8 34 46 02 00
  8d 46 44
  c6 46 70 00
  50 8b ce e8 15 54 02 00
  5e c3
0x0049503d-0x00495040: cc cc cc
```

Capstone disassembly:

```text
00495010 push     esi
00495011 mov      esi, ecx
00495013 cmp      byte ptr [esi + 0x101], 0
0049501a je       0x49503b
0049501c cmp      byte ptr [esi + 0x108], 0
00495023 je       0x49503b
00495025 push     1
00495027 call     0x4b9660
0049502c lea      eax, [esi + 0x44]
0049502f mov      byte ptr [esi + 0x70], 0
00495033 push     eax
00495034 mov      ecx, esi
00495036 call     0x4ba450
0049503b pop      esi
0049503c ret
```

The helper is exactly `0x2d` bytes. The three `0xcc` bytes before it separate it from `ButtonControlPane::OnKeyPress` at `0x00494f70-0x0049500d`; the three `0xcc` bytes after it separate it from the `TextButtonControlPane` constructor at `0x00495040`.

No split, merge, file rename, or reclassification is recommended now. The page is already the exact source-bearing child inside non-emitting aggregate [UID:000118].

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x00495010-0x0049503d` | [UID:0003N8] `by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md` | Raw ButtonControlPane selected-frame draw helper | TRUE | [UID:00001E] `ButtonControlPane` | `87/88` | Exact child retained; no standalone C++ body. |
| `0x00494f70-0x0049500d` | [UID:00001E] class method band | ButtonControlPane key handler before the helper | TRUE | [UID:00001E] | support fact | Modeled IDA function `sub_494F70`, size `0x9d`, nine vtable/data xrefs. |
| `0x00495040+` | [UID:0000EJ] / TextButtonControlPane successor | TextButtonControlPane constructor after padding | TRUE | TextButtonControlPane family | support fact | Modeled IDA function `sub_495040`, size `0xef`, ten xrefs in bounded positive control. |
| `0x00494eb0-0x0049803a` | [UID:000118] aggregate | Mixed ButtonChoice control coverage index | FALSE | none | `86/90` | Non-emitting container; exact children carry source ownership. |

## Route And Liveness Scan

Fresh section-mapped scans found no usable entry route to `0x00495010`:

- No direct `E8`/`E9` call or jump to `0x00495010`.
- No absolute VA literal for `0x00495010`.
- No RVA literal for `0x00495010`.
- No absolute VA/RVA literal for plausible interior entry addresses `0x00495013`, `0x0049501c`, `0x00495025`, or `0x00495033`.
- No direct call/jump to those interior entries.
- Positive control: direct callers to `0x00495040` were found, proving the scan can find modeled constructor calls nearby.
- Positive control: vtable/data-style VA literals to `0x00494f70` were found, matching the documented ButtonControlPane key-handler vtable route.
- Positive control: direct callers to `0x00494f40` were found, matching ButtonControlPane selected-state setter use.

Two raw rel32-looking false positives must not be treated as routes:

- A computed rel32 hit to `0x00495010` comes from bytes at `0x00494f0a` inside the constructor store `mov byte ptr [esi+0x102], 0`; the preceding byte is ModRM `0x86`, not a call/jump opcode.
- A computed rel32 hit to `0x0049501c` comes from bytes at `0x00494f19` inside the constructor store `mov word ptr [esi+0xff], 0x101`; again it is data/displacement inside an instruction, not control flow.

Prior live IDA facts in the target and [UID:000118] docs remain consistent with this scan:

- `lookup_funcs` did not model a function at `0x00495010`.
- `xrefs_to 0x00495010` reported no cross-references.
- `make_signature_for_range 0x00495010-0x0049503d` reported a unique helper byte signature.

Conclusion: the helper is live-looking source-shaped code, but static route evidence remains unproven. This is the reason to keep formal C++ blank despite owner/emitter assignment.

## Negative Evidence Summary

- No IDA function object at `0x00495010`: MCP `lookup_funcs` returns `Not a function`.
- No start xrefs: MCP `xrefs_to 0x00495010` returns `xref_count:0`.
- Interior xrefs do not prove external reachability: they are internal control-flow edges from the preceding helper instructions.
- No direct local route: prior section-mapped scans found no direct `E8`/`E9` call/jump to `0x00495010` or plausible interior entries.
- No data route: prior VA/RVA literal scans found no pointer to the start or plausible interior entries.
- Constructor-displacement false positives at `0x00494f0a` and `0x00494f19` are rejected because the bytes are instruction encoding/displacement context, not call/jump opcodes.
- Adjacent modeled functions and positive-control xrefs do not route into this raw helper: `0x00494f70`, `0x00494f40`, and `0x00495040` resolve and have xrefs, which confirms the negative result is not simply a broken xref check.
- Generated output currently does not contain a [UID:0003N8] emitted marker/body in `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp`, so generated C++ should not be used to invent a public API body.

## Field And Callee Inference

### `this + 0x101`

Current target prose says "active/enabled byte"; that should be replaced.

Best inference: inherited `ControlPane` visible flag.

Evidence:

- [UID:0003N3] `ControlPaneSetVisibleFlag` sets byte `+0x101` and invalidates on transition from clear to set.
- [UID:0003N4] `ControlPaneClearVisibleFlag` clears byte `+0x101` and invalidates on transition from set to clear.
- [UID:0002PD], [UID:000038], and [UID:0000IG] consistently document `+0x101` as the visible flag.
- [UID:0003N9] `ControlPaneDrawActiveFrameHelper` checks `+0x101` plus active byte `+0x102`, which distinguishes visible from active. [UID:0003N8] checks `+0x101` but not `+0x102`.
- ButtonControlPane constructor clears `+0x102` and `+0x108`, then writes `0x0101` at `+0xff`; it does not establish `+0x101` as a ButtonControlPane-private flag.

Rejected names:

- `m_active`: rejected because `+0x102` is the documented base active flag.
- `m_enabled`: possible broad English role, but less supported than the existing `ControlPane` visible-set/clear helper evidence.
- Button-private pressed/armed state: rejected because the offset is inherited and governed by base ControlPane helpers.

### `this + 0x108`

Best inference: ButtonControlPane selected state (`m_selected` / `m_controlSelected`).

Evidence:

- `SetControlSelected` at `0x00494f40` compares its input byte with `[ecx+0x108]`, stores on change, and invalidates `this+0x44`.
- ButtonControlPane constructor clears `+0x108`.
- The target only draws the frame when this byte is nonzero.
- SelectBoxControlPane also uses `+0x108` as `m_selected`, but that is an independent class with a separate constructor/painter. The shared offset supports the generic selected-flag role but does not transfer ownership away from ButtonControlPane.

Rejected names:

- `m_pressed`: rejected because key activation visual states in `OnKeyPress` are driven by calls around `0x49dd20`/`0x49de00`, not by `+0x108`.
- `m_armed`: possible UI wording, but current source docs already use selected-state semantics for `SetControlSelected`.

### `this + 0x70`

Best inference: inherited GrafPort draw/blit mode byte (`m_drawMode` / `m_blitMode`).

Evidence:

- [UID:00005V] and [UID:00016A] document `+0x70` as GrafPort draw/blit mode used by tiled/sprite callbacks.
- [UID:0001GF] WaterFilterEffecter sets `+0x70` to mode `2` for caustic drawing and restores `0`.
- [UID:00011C] ProgressBarControlPaneDrawProgressBar clears `+0x70` before fill/frame drawing.
- This target clears `+0x70` immediately before `GrafPort::DrawRectFrame`.

Rejected names:

- Button-local dirty byte: rejected because GrafPort/render docs show cross-cutting draw-mode use.
- Text draw/background mode: rejected for this exact offset; text-specific mode is documented separately at GrafPort `+0x88`.

### `0x004b9660`

Best inference: shared GrafPort active draw/fill color setter, source-facing `SetDrawColor`.

Evidence:

- [UID:000162] identifies `0x004b9660-0x004b966c` as a leaf accessor that stores at GrafPort `+0x74`.
- B001 GrafPort text-helper correction names `+0x74` as active draw/fill color and distinguishes `+0x7c/+0x80` text/background colors.
- Caller fan-in is broad across drawing paths; generated names such as `FittingRoomListPane::SetTextColor` are caller-biased pollution.

For this target, value `1` is the frame color chosen before drawing selected button bounds.

### `0x004ba450`

Best inference: `GrafPort::DrawRectFrame(const RectBounds *rect)`.

Evidence:

- [UID:000168] is now populated with first-draft C++ and source-routed to [UID:00005V] `GrafPort`.
- It is a one-argument `__thiscall` method, receives the same `ecx` receiver, checks `m_drawEnabled` at `+0x71`, clips for visibility, and draws the original rectangle frame.
- It has broad direct call fan-in; the target call at `0x00495036` is one of the documented direct calls.

For this target, the argument is the inherited bounds rectangle at `this+0x44`.

## Relationship To ButtonControlPane And TextButton Controls

The helper belongs to ButtonControlPane, not TextButtonControlPane or TextButtonExControlPane.

Evidence for ButtonControlPane:

- It sits immediately after ButtonControlPane's modeled constructor, selected-state setter, and key handler block.
- It consumes ButtonControlPane-selected byte `+0x108`, documented by `SetControlSelected`.
- It consumes inherited ControlPane/GrafPort fields only: `+0x101`, `+0x44`, and `+0x70`.
- It does not access any TextButton text buffer, string, resource label, text-provider child, font, or label bounds field.
- [UID:00001E] records the ButtonControlPane vtable block around `0x00617bd4`, with the key handler at `0x00617c48 -> 0x00494f70`; no vtable or pointer data points to `0x00495010`.

Evidence against TextButtonControlPane:

- The TextButtonControlPane constructor starts at `0x00495040`, after three `0xcc` bytes.
- [UID:0000EJ] routes TextButtonControlPane through a separate file [UID:0000OK]; this raw helper ends before that constructor.
- No TextButton-only fields or callee patterns are present.

Evidence against TextButtonExControlPane:

- TextButtonExControlPane starts later at `0x00495450` and owns text-provider child state at `+0x10c`.
- The target has no `+0x10c` access and no label layout behavior.

The source placement should stay under `NexusTK/ui/controls/ButtonControlPane.cpp` through [UID:0000HY].

## Generated Output Pollution

Current generated output check:

- `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp` currently has `validator-command-id: 000000006798`.
- A current `rg` scan found no `0003N8`, `0x00495010`, `ButtonControlPaneActiveRefreshHelper`, `DrawSelectedFrame`, or empty-marker line for this target in that generated file.
- The old observed `Completion:85 | Confidence:86 | Empty Emitter Marker` line is historical generated-output state only. It is not the current target metadata and must not be repeated as current truth.

Do not synthesize a body using compiler/raw names.

Pollution to reject in implementation:

- Do not call `0x004b9660` `FittingRoomListPane::SetTextColor`; [UID:000162] documents it as GrafPort draw-state.
- Do not move this helper to TextButtonControlPane because of address adjacency to `0x00495040`.
- Do not move it to SelectBoxControlPane because SelectBox also has `m_selected` at `+0x108`.
- Do not move it to FittingRoom, RankingDialog, Collection, or TargetOption based on generated helper names around GrafPort accessors.
- Do not emit raw `sub_495010`, `FUN_00495010`, or `ButtonControlPaneActiveRefreshHelper` as a final public API name.

## Ranked Ownership Analysis

1. [UID:00001E] `ButtonControlPane` through [UID:0000HY] `ButtonControlPane.cpp`: best owner. It has the local method block, selected-state byte, and appropriate source file route.
2. [UID:000038] `ControlPane`: dependency/base owner only. `+0x101`, `+0x44`, and `+0x70` are inherited, but `+0x108` and address placement make ButtonControlPane narrower.
3. [UID:0000EJ] `TextButtonControlPane`: rejected. Successor constructor and no text fields.
4. [UID:0000EK] `TextButtonExControlPane`: rejected. Later class and no provider/label fields.
5. [UID:0000CQ] `SelectBoxControlPane`: rejected. Similar selected-field semantics but different address island, class, and paint body.
6. [UID:00005V] `GrafPort`: dependency owner only for callees and inherited fields, not the direct source owner.
7. `CANONICAL_OWNER:NONE`: rejected as final metadata. The exact helper is source-shaped and the direct ButtonControlPane owner is strong enough under current raw-helper policy, as with [UID:0003N9].

## Source Placement

- Recommended source placement: [UID:0000HY] `NexusTK/ui/controls/ButtonControlPane.cpp` through class owner [UID:00001E] `ButtonControlPane`.
- Why this placement fits: the helper sits immediately after the ButtonControlPane key handler, uses the base selected flag `+0x108`, and calls generic GrafPort dependencies to draw the current button bounds.
- Rejected placements: TextButtonControlPane and TextButtonExControlPane are successor/later text-control classes; SelectBoxControlPane has similar selected-state semantics but a different address island; GrafPort owns the drawing dependencies only; feature owners arise from polluted generated callee names.
- Remaining placement uncertainty: exact original private helper spelling is not symbol-proven, but source file/class ownership is strong enough to preserve current metadata.

## First-Draft C++ Recommendation

Formal C++ recommendation: keep `RECONSTRUCTION_CPP` blank in the target.

Reason: current route/liveness evidence is still unproven. There is no IDA function object, direct caller, vtable pointer, VA/RVA literal, or direct branch/call route to `0x00495010`. Emitting an ordinary private method would create a plausible but currently uncalled source body and can mislead generated output.

Exact no-code proof:

- MCP `lookup_funcs 0x00495010` returns `Not a function`.
- MCP `xrefs_to 0x00495010` returns zero start xrefs.
- MCP positive controls resolve `sub_494F70`, `sub_494F40`, `sub_495040`, `sub_4B9660`, and `sub_4BA450` normally.
- MCP bounded listing and bytes prove the raw helper body, but neither proves an external entry route.
- Local rel32 and VA/RVA scans found no direct route or pointer route and rejected constructor-displacement false positives.
- Current generated `ButtonControlPane.cpp` does not contain a UID0003N8 body or marker, so generated output is not evidence for emission.
- Therefore no C++ body is supplied in this report. Any later code, even illustrative code, must appear only as exact formal `RECONSTRUCTION_CPP CODE` insertion text after a route or retained-helper policy is accepted.

Callback result: the existing target-body reference-only C++ snippet under `## C++ Policy` was prose-converted, and the blank formal `RECONSTRUCTION_CPP` block was preserved.

## Final Recommendation

- Preserve target metadata at current `87/88`, owner/emitter [UID:00001E], reconstructable TRUE, and blank formal C++.
- Preserve target/support facts: exact bytes, padding, field map, GrafPort callees, no-route proof, ButtonControlPane source placement, and rejected alternatives.
- Do not change owner to TextButtonControlPane, TextButtonExControlPane, SelectBoxControlPane, GrafPort, a feature owner, or `NONE`.
- Do not emit a standalone source body until a caller/vtable/table route or accepted retained-helper body policy is proven.
- Callback implementation applied the no-code-proof cleanup: the body-only illustrative snippet was removed from the target body and the same behavior facts now remain as prose.
- Manual coverage/tracker disposition remains supervisor-owned because B010 may not edit generated or manual coverage files in this repair.

## Score And Metadata Recommendation

Current and recommended score: `87/88`.

Historical reason completion moved from `85` to `87`:

- The stale `+0x101` active/enabled wording is resolved to inherited visible flag.
- `+0x108` is tied directly to `SetControlSelected`.
- Raw callees now have source-facing dependency names.
- Boundary and route scans were freshly rechecked from the PE.
- The no-C++ decision is now a target-specific no-route/no-standalone-body proof, not a passive "naming pending" blocker.

Why confidence should be `88`, not `90+`:

- Exact bytes, fields, and owner are strong.
- No caller/vtable/table route has been found.
- Exact original source spelling remains inferred.
- Formal C++ should stay blank until route/source-representation evidence improves.

Metadata fields to preserve:

- `COMPLETION:87`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:00001E`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:00001E`
- blank `EMITTER_POSITION_OPTIONAL`
- blank formal `RECONSTRUCTION_CPP`

## Recommended Target Doc Changes

In `by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md`:

- Already present and should be preserved:
  - `COMPLETION:87`
  - `CONFIDENCE:88`
  - keep `CANONICAL_OWNER:00001E`
  - keep `RECONSTRUCTABLE:TRUE`
  - keep `EMITTER_UIDS:00001E`
  - keep formal C++ blank.
- Retitle/prose-role direction: `ButtonControlPane selected-frame draw helper` or `ButtonControlPane DrawSelectedFrameIfVisible raw helper`. Keep the existing filename unless supervisor explicitly wants a path rename.
- Replace "active/enabled byte at `this+0x101`" with "inherited ControlPane visible flag at `this+0x101`".
- Replace `selected/armed byte at this+0x108` with "ButtonControlPane selected flag at `this+0x108`, written by `SetControlSelected`".
- Replace raw `sub_4B9660(1)` with `GrafPort::SetDrawColor(1)` / active draw-fill color setter at [UID:000162].
- Replace "clears byte `this+0x70`" with "clears inherited GrafPort draw/blit mode byte `m_drawMode` / `m_blitMode` at `this+0x70` to mode `0`".
- Replace `sub_4BA450` with `GrafPort::DrawRectFrame(const RectBounds *rect)` at [UID:000168].
- State that the rectangle argument is the inherited `RectBounds` at `this+0x44`.
- Add fresh route proof: no IDA function object/xrefs per prior docs; current PE scan finds no direct call/jump or VA/RVA pointer to the start/interiors; two rel32-looking hits are instruction-displacement false positives inside the constructor.
- Add no-body policy: no standalone formal C++ until caller/vtable/table route or accepted retained-helper source policy is proven.
- Add rejected alternatives: TextButtonControlPane, TextButtonExControlPane, SelectBoxControlPane, GrafPort callee ownership, feature owner pollution from generated GrafPort accessor names, `CANONICAL_OWNER:NONE`, and full standalone body emission.
- Applied in this callback: the body-only reference C++ snippet under the target's `## C++ Policy` was prose-converted; formal C++ remains blank.

## Recommended Support Doc Changes

Support paths and current disposition:

- `by-class/ButtonControlPane.md`
  - Already present: method table row for the raw helper, inherited visible flag `+0x101`, selected byte `+0x108`, GrafPort draw color/frame calls, and no emitted callable method note.

- `by-file/ButtonControlPane.md`
  - Already present: proposed contents include the retained no-route selected-frame helper, source route `NexusTK/ui/controls/ButtonControlPane.cpp`, and rejected TextButton/TextButtonEx/GrafPort/feature owner pollution.

- `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md`
  - Already present: exact [UID:0003N8] child row calls it a visible/selected selected-frame draw helper, uses GrafPort dependency names, and preserves no-route/no-body policy.

Optional if implementation wants precise backlinks, but not required because the facts already exist:

- `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
  - Add [UID:0003N8] as another concrete caller/consumer of `0x004b9660`, setting draw color `1` before a selected button frame.
- `by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md`
  - Add [UID:0003N8] as a ButtonControlPane selected-frame caller.
- `by-class/GrafPort.md`
  - No necessary change; it already documents `+0x70`, `+0x74`, and `DrawRectFrame`.
  - Callback disposition: not edited; excluded with reason because the target and required support docs already link the GrafPort callees and the GrafPort support docs carry same-or-greater dependency detail.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Do not edit `by-memory/-coverage-report.md` in the B-agent report pass. The current manual file still has a stale broad [UID:000118] ButtonChoice row and lacks the [UID:0003N8] child row. Minimal target child row to insert under the ButtonChoiceControlCore block:

```markdown
        - [UID:0003N8][0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper](by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md) 0x00495010-0x0049503d | raw-helper | ButtonControlPane::DrawSelectedFrameIfVisible candidate : reconstructable : 87% : strong : B010 2026-06-19 source-quality pass keeps owner/emitter [UID:00001E][ButtonControlPane](by-class/ButtonControlPane.md) and resolves the helper as a retained raw selected-frame draw path, not TextButton or GrafPort-owned code. Exact PE bytes confirm the `0x2d`-byte body between three-byte `0xcc` padding spans; the helper checks inherited visible flag `this+0x101` and ButtonControlPane selected flag `this+0x108`, calls [UID:000162][GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md) / `GrafPort::SetDrawColor(1)`, clears inherited GrafPort draw/blit mode byte `this+0x70` to mode `0`, and calls [UID:000168][GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) / `GrafPort::DrawRectFrame(&m_bounds)` for `this+0x44`. Current route checks still find no IDA function object, no start xrefs, no direct call/jump, and no VA/RVA pointer route to `0x00495010` or plausible interiors, with constructor-displacement false positives rejected, so formal C++ remains blank until a caller/vtable/table route or retained-helper body policy is proven.
```

If supervisor refreshes the parent row at the same time, [UID:000118] should remain a non-emitting aggregate/index and [UID:0003N8] should be one of its exact source-bearing children.

## Validator Results

Callback validator run:

> Executable block R001 was removed from this report and preserved verbatim in [0003N8-ButtonControlPaneActiveRefreshHelper-source-quality-removed.md](0003N8-ButtonControlPaneActiveRefreshHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- `command_id`: `000000006863`
- `command_timestamp`: `2026-07-05T07:09:17-04:00`
- Exit code: `0`
- `ok`: `1`
- Warnings/diagnostics: `missing_ref_uid` for `0003N3`, `0003N4`, and `0003N9` in the target doc; these are validator registry/reference diagnostics and were not hand-edited.
- Validator-reported updates/side effects: `insert_header_blank:1`, `path_update:1`, `completion_update:1`, `confidence_update:1`, `canonical_owner_update:1`, `autogen_registry_update:5`, `reference_index_add:14`, `projected_stats_update:1`, `stats_incremental_noop:1`.
- Generated refresh: `generated_refresh: deferred`, `generated_refresh_command_id: 000000006863`, `generated_refresh_timestamp: 2026-07-05T07:09:17-04:00`; generated output was not manually edited and not relied on for this no-code cleanup.

Report-only repair validator state before callback: no scoped validators were run during the report-only repair because no by-* files were edited.

Additional scoped validators were not run because the support docs were verified as already-present and were not edited. If a later supervisor callback expands support-doc edits, run from `source-3/project-documentation`:

> Executable block R002 was removed from this report and preserved verbatim in [0003N8-ButtonControlPaneActiveRefreshHelper-source-quality-removed.md](0003N8-ButtonControlPaneActiveRefreshHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Only if optional GrafPort backlinks are edited:

> Executable block R003 was removed from this report and preserved verbatim in [0003N8-ButtonControlPaneActiveRefreshHelper-source-quality-removed.md](0003N8-ButtonControlPaneActiveRefreshHelper-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected result for any later touched file: `ok: 1`. Validator may update generated/state files such as `auto-generated/-ag-memory-coverage.md`, `project-level/-auto-completion-stats.md`, `tools/validator.ini`, and generated C++ marker files. The report-only repair did not run validators; the callback validator is recorded above.

## IDA Rename, Type, And Comment Recommendations

Do not force IDA to treat this as a final ordinary method until the team decides retained raw no-route helpers should be promoted. If a local analysis function is useful, use a raw-aware name:

- Function label: `raw_ButtonControlPane_DrawSelectedFrameIfVisible_00495010`.
- Candidate type, if created for analysis only: a raw-aware thiscall receiver type for `ButtonControlPane`; do not treat the analysis type as formal source C++.
- Comment at `0x00495013`: `ControlPane visible flag (+0x101), not active (+0x102).`
- Comment at `0x0049501c`: `ButtonControlPane selected flag (+0x108), written by SetControlSelected.`
- Comment at `0x00495025`: `GrafPort::SetDrawColor(1); sets active draw/fill color (+0x74).`
- Comment at `0x0049502f`: `Clear inherited GrafPort draw/blit mode byte (+0x70) before frame draw.`
- Comment at `0x00495036`: `GrafPort::DrawRectFrame(&this->m_bounds); bounds at +0x44.`
- Boundary comments:
  - `0x0049500d-0x00495010`: alignment after ButtonControlPane::OnKeyPress.
  - `0x0049503d-0x00495040`: alignment before TextButtonControlPane constructor.

## Open Questions With Attempted Resolution

- Exact original helper spelling: not symbol-proven. Best defensible source name is `DrawSelectedFrameIfVisible`; use `Raw` suffix in IDA/docs until route is proven.
- Whether the original source intentionally contained an out-of-line private helper: attempted through MCP function/xref checks, local call/jump scans, VA/RVA pointer scans, positive controls, and generated-output scan. No route is proven, so this remains unresolved and blocks standalone C++ emission.
- Whether `+0x70` should be called `m_drawMode` or `m_blitMode`: support docs prefer draw/blit mode. Use `m_drawMode` in prose and note `m_blitMode` as an alternate.
- Whether `+0x108` should be `m_selected` or `m_controlSelected`: `m_selected` is shortest and matches SelectBox terminology; `m_controlSelected` may be clearer inside ButtonControlPane. Either is acceptable if offset evidence remains in docs.
- Whether to rename the file/path: resolved as no. The target filename can remain stable; title/prose can describe the selected-frame draw role.
- Whether target UID is unknown: resolved for the source doc. The target header now contains UID `0003N8`; old unknown-UID status is historical/lifecycle state only.

## Changed Files

- Created: none.
- Modified by B010:
  - `by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md`
  - `tools/leaser/Agents/Agent-B010/research/0003N8-ButtonControlPaneActiveRefreshHelper-source-quality.md`
- Renamed: none.
- Leases: B010 leased `by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md`, validated it, and released it immediately; current lease report shows no active B010 lease for this target.
- Support docs verified but not edited: `by-class/ButtonControlPane.md`, `by-file/ButtonControlPane.md`, and `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md`.
- Generated, coverage, validator-state, lifecycle/archive, registry, or supervisor-ledger manual edits: none. Scoped validator side effects are recorded under `Validator Results`.
- Report execution: not run. B010 did not run `execute_report`, dry-run/probing variants, registry lifecycle commands, archive commands, or manual report moves.

## Implementation Tracking Checklist

- [x] Supervisor Gate 1 review passed for SHA256 `67587A25798DF0AF4DC99741E5F1C8ABFAE3613CDE69F64C33004BAA35148D71`; callback accepted UID0003N8 only.
- [x] Target doc `by-memory/0x00495010-0x0049503d.ButtonControlPaneActiveRefreshHelper.md`: verified current `87/88`, owner/emitter [UID:00001E], reconstructable TRUE, blank formal C++, exact bytes/padding, field map, GrafPort callee names, no-route proof, and rejected alternatives; prose-converted the body-only reference C++ snippet under `## C++ Policy`.
- [x] Support doc `by-class/ButtonControlPane.md`: already present at same-or-greater detail, including helper row, field map, ButtonControlPane source role, and no emitted callable method note; no edit made.
- [x] Support doc `by-file/ButtonControlPane.md`: already present at same-or-greater detail, including source route, selected-frame helper role, and no raw/public-body warning; no edit made.
- [x] Support doc `by-memory/0x00494eb0-0x0049803a.ButtonChoiceControlCore.md`: already present at same-or-greater detail, including exact child row, GrafPort dependency names, no-route/no-body policy, and non-emitting aggregate state; no edit made.
- [x] Optional GrafPort backlinks: excluded with reason because required support docs already link the exact GrafPort callees and GrafPort docs already document the dependency state; no optional edit was needed.
- [x] Claim ledger: updated accepted rows to callback `applied`, `already-present`, or `excluded-with-reason`.
- [x] Metadata/score: preserved `COMPLETION:87`, `CONFIDENCE:88`, owner/emitter, reconstructable TRUE, and blank formal C++; historical `85/86` remains labeled historical only.
- [x] First-draft C++/no-code proof: formal C++ remains blank; target/report callback text contains no body-only C++ example.
- [x] Historical/stale assumptions: preserved old `needs-revalidation` / `target_uid_unknown: 0003N8` only as historical lifecycle context; rejected active/enabled, raw callee names, TextButton/TextButtonEx/SelectBox/GrafPort/feature-owner, `CANONICAL_OWNER:NONE`, and standalone-body alternatives remain recorded.
- [x] Validator: scoped file validator for the edited target exited `0` with `ok:1`; command metadata, missing UID diagnostics, and generated-refresh side effects recorded above.
- [x] Generated output expectations: generated reports/source are validator-owned; scoped validator reported `generated_refresh: deferred`, and no generated output was manually edited or relied on.
- [x] Manual coverage/tracker disposition: supervisor-owned only; B010 did not edit `by-memory/-coverage-report.md`, generated coverage, auto trackers, validator cache/state manually, or supervisor ledgers.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003N8","source_path":"executed-b-agent-research/B010/0003N8-ButtonControlPaneActiveRefreshHelper-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- {"agent":"B010","command_id":"000000006852","destination_path":"tools/leaser/Agents/Agent-B010/research/0003N8-ButtonControlPaneActiveRefreshHelper-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B010/0003N8-ButtonControlPaneActiveRefreshHelper-source-quality.md","timestamp":"2026-07-05T06:52:26-04:00"} -->
<!-- {"agent":"B010","command_id":"000000006864","destination_path":"executed-b-agent-research/B010/0003N8-ButtonControlPaneActiveRefreshHelper-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0003N8-ButtonControlPaneActiveRefreshHelper-source-quality.md","timestamp":"2026-07-05T07:15:51-04:00","uid":"0003N8"} -->
<!-- {"agent":"B010","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0003N8-ButtonControlPaneActiveRefreshHelper-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B010/0003N8-ButtonControlPaneActiveRefreshHelper-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0003N8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
