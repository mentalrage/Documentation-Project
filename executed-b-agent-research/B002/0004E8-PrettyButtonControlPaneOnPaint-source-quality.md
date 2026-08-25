** TARGET-REPORT-UID:0004E8 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# UID0004E8 PrettyButtonControlPane OnPaint Source-Quality Report


## Finalized Report / Current Recommendation

- Current recommendation: make [UID:0004E8] a source-emitting `PrettyButtonControlPane::OnPaint` child through direct class owner [UID:0000AR][PrettyButtonControlPane](by-class/PrettyButtonControlPane.md).
- Final disposition: the current blank emitter is no longer justified after this pass. Current MCP confirms the function body, vtable-only reachability, exact padding after the function, and the shared render helper route; current support docs resolve the raw helper names enough for source-facing first-draft C++.
- Required action after supervisor acceptance: update the target to `COMPLETION:88`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000AR`, keep `RECONSTRUCTABLE:TRUE`, set `EMITTER_UIDS:0000AR`, and insert the formal C++ block below. Add source-quality field/helper-name evidence to target/support docs.
- Confidence: high for behavior, range, owner, emitter route, and helper roles; medium-high for exact original member spellings because the field names are inferred from constructor/paint/setter behavior rather than recovered symbols.

## Supporting Research

- This is a report-only pass for assignment `B002-report-0004E8-PrettyButtonControlPaneOnPaint-20260702`.
- No by-* docs, generated files, project-level files, coverage reports, validator state, queues, archives, supervisor ledgers, or report lifecycle state were edited.
- No `execute_report`, execute-report dry-run/probing/status variant, registry lifecycle command, manual report move, or archive command was run.
- IDA MCP was available. Initial active session `b013_0001FN_20260702` disappeared between `idb_list` and bounded tool calls, producing `Session not found` for bounded calls only. A fresh `idb_list` returned active session `b011_0004EC_20260702`; the evidence pass below was redone against that current session.

## Target

- Target UID: `0004E8`
- Target path: `by-memory/0x0054b7c0-0x0054b879.PrettyButtonControlPaneOnPaint.md`
- Source queue/report row: `auto-generated/-ag-research-tracker.md` not-covered reconstructable by-memory row, assignment-time `84/88`, average `86.0`, reconstructable `true`, B reports `0`.
- Current supervisor classification: report-only source-quality/emitter/C++ readiness research.
- Current scores and parent state: target `84/88`, owner [UID:0000AR], reconstructable true, blank emitter. Direct class parent [UID:0000AR] is `87/89` and emits through [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md), which is `87/89` with path `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.

## Current Target State

- Existing metadata: `COMPLETION:84`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000AR`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`.
- Existing owner/emitter/reconstructable state: owner route is already correct; emitter is blank pending accepted frame/resource constants and member names.
- Existing C++/emitter state: formal `RECONSTRUCTION_CPP CODE` block is empty.
- Existing open questions/blockers: raw helper names, frame/resource field names, disabled overlay behavior, and whether `OnPaint` can emit through [UID:0000AR].
- Related docs checked: target page, parent split page [UID:0001F9], class/file pages [UID:0000AR]/[UID:0000MP], class2 comparison docs [UID:0000AS]/[UID:0004EF], vtable docs [UID:0002UW]/[UID:0002UX], helper docs [UID:0000XY], [UID:0002KP], [UID:0001OQ], [UID:000162], and [UID:0001PI].
- Current artifact/lifecycle status: this report is active in `tools/leaser/Agents/Agent-B002/research/` for supervisor Gate 1 review only.

## Executive Recommendation

The best direct owner is [UID:0000AR][PrettyButtonControlPane](by-class/PrettyButtonControlPane.md). The source file route remains [UID:0000MP][PrettyButtonControlPane](by-file/PrettyButtonControlPane.md) under `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.

The target should be rescored and changed from blank-emitter to emitting through [UID:0000AR]. No rename, split, merge, or child creation is needed. The current range is exact: IDA reports `sub_54B7C0` as `0x0054b7c0-0x0054b879`, followed by seven `0xcc` bytes at `0x0054b879-0x0054b880`.

## Supervisor Active Recheck

- Triggering instruction: new report-only Medium assignment for UID0004E8, with explicit focus on whether the blank emitter is still justified and whether first-draft formal C++ is safe.
- Split repair required: no. B011 already split the parent [UID:0001F9] into exact child pages [UID:0004E3]-[UID:0004EM].
- Source-bearing child in scope: [UID:0004E8] itself. The sibling [UID:0004EF] was used only as comparison evidence and does not need an edit for this target.

## Inference Research Guidance Check

The recommendation separates direct IDA fact, existing documentation, and source-shape inference:

- IDA fact: function body, size, callees, vtable data xref, byte range, padding, constructor field initialization, visual-state setter behavior, and no direct code callers.
- Documentation evidence: accepted helper docs name `g_pEPFLib`, `ResourceLayoutTable::LookupLayoutEntry`, `EPFTileContext`, `RenderTileFrame`, `GrafPort::SetDrawColor`, and Surface callback slot 7 as pane-region fill/refresh infrastructure.
- Inference: member names such as `m_normalFrameId`, `m_pressedFrameId`, `m_hoverFrameId`, `m_hoverFrameActive`, `m_state11VisualActive`, `m_enabled`, `m_epfResourceName`, and `m_paletteResourceName` are source-facing descriptive names, not recovered original symbols.
- Wave2/Wave3 artifacts were not treated as authority. Generated/coverage reports were used only as current state evidence that [UID:0004E8] is non-emitting and queued for research.

## Heuristic / Inference Reanalysis And Validation

- Raw helper names are no longer a target blocker. [UID:0000XY] documents `0x00457a60` as `EPFTileContext` initialization; [UID:0002KP] implements `ResourceLayoutTable::LookupLayoutEntry`; [UID:0001OQ] names `0x0067a744` as `g_pEPFLib`; [UID:000162] documents `0x004b9660` as `GrafPort::SetDrawColor`; [UID:0001PI] documents `0x0069b3fc` as Surface callback slot 7 for fill/invalidation/presentation; B010/B011 accepted paint reports use `RenderTileFrame` for `0x004b9980`.
- Member offsets are source-shape resolvable enough for a draft. Constructor `0x0054b5e0` writes frame ids at `+0x10c/+0x110/+0x114`, clears word `+0x118/+0x119`, constructs resource strings at `+0x11c/+0x120`, stores constructor flag at `+0xff`, clears `+0x100`, and clears callback pointer `+0x124`.
- Paint behavior uses those fields coherently: `+0x119` selects frame `+0x110`, `+0x118` selects frame `+0x114`, default selects `+0x10c`; resource string `+0x11c` is passed to `LookupLayoutEntry`, palette string `+0x120` is passed to `RenderTileFrame`, and byte `+0x101` gates disabled overlay handling.
- Setter validation: `0x0054b750` sets byte `+0x119` when state/event value `11` (`0x0b`, Verified with int_convert.py) is requested, starts a 150 ms (`0x96`, Verified with int_convert.py) timer on the secondary subobject at `this+0xa4`, and otherwise clears `+0x119` and stops the timer. `0x0054b700` writes byte `+0x118` and forwards through virtual slot `+0x20`.
- Disabled overlay: when `+0x101` is false, paint calls `GrafPort::SetDrawColor(143)` (`0x8f`, Verified with int_convert.py), writes draw/blit mode byte `+0x70 = 2`, and dispatches Surface callback slot 7 with `this` and bounds at `this+0x44`.
- Rejected alternatives: leaving `sub_4D02F0`, `sub_457A60`, `sub_4B9980`, `sub_4B9660`, `sub_584540`, or `unk_69B3FC` as final blockers is rejected because support docs now provide accepted role/source-facing names. Moving target ownership to [UID:0000MP] directly is weaker than class owner [UID:0000AR] because the vtable slot and method fields are class-local. Moving ownership to [UID:0000HY][ButtonControlPane](by-file/ButtonControlPane.md) is rejected because the base class is only a dependency.
- Remaining uncertainty: exact original member spellings and class header declarations are inferred. This caps score below final audit but does not justify blank emitter.

## Evidence Standards Used

- IDA MCP: current `idb_list`, `server_health`, `lookup_funcs`, `analyze_function`, `decompile`, bounded `disasm`, exact `xrefs_to`, `get_bytes`, and `callees`.
- Local docs: current by-* target/support docs, generated coverage as read-only state, old executed B-agent reports as leads, and helper pages with accepted source-facing names.
- Negative evidence: no direct code xrefs to `0x0054b7c0`; only data xref from vtable slot `0x0062231c`; no reason to route ownership to caller dialogs or base ButtonControlPane.
- Numeric conversion: `int_convert.py` verified `143 == 0x8f`, `150 == 0x96`, `11 == 0x0b`, and `185 == 0xb9`.

## Evidence Checked

- IDA MCP session evidence:
  - `idb_list`: active session `b011_0004EC_20260702`, `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
  - `server_health`: `status:ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, imagebase `0x400000`.
  - `lookup_funcs`: `0x0054b7c0` `sub_54B7C0` size `0xb9` (`185`, Verified with int_convert.py); helper starts `0x004d02f0`, `0x00457a60`, `0x004b9660`, `0x004b9980`, and `0x00584540` all resolve.
  - `analyze_function`/`decompile`: paint branches on `this+281`, `this+280`, and `this+257`, calls EPF/resource/draw helpers, and dispatches the disabled overlay through `0x0069b3fc`.
  - `disasm`: 61 instructions, exact branch sequence, frame id loads at `[esi+0x110]`, `[esi+0x114]`, `[esi+0x10c]`, resource-string loads from `[esi+0x11c]` and `[esi+0x120]`, draw bounds at `[esi+0x44]`, disabled flag `[esi+0x101]`, draw-mode byte `[esi+0x70]`.
  - `xrefs_to`: `0x0054b7c0` has one data xref from `0x0062231c`; no direct code callers. `0x0062231c` itself has no xrefs, consistent with vtable data slot storage.
  - `get_bytes`: `0x0054b7c0` exact `0xb9` body bytes; `0x0054b879-0x0054b880` seven `0xcc` bytes; `0x0062231c` stores little-endian pointer `c0 b7 54 00`.
  - `callees`: `0x00457a60`, `0x00584540`, `0x004d02f0`, `0x004b9980`, `0x004b9660`, external callback slot `0x0069b3fc`, and security-cookie check.
  - Constructor decompilation `0x0054b5e0`: confirms field initialization described in the heuristic section.
  - Visual-state decompilation `0x0054b750` and state forwarder `0x0054b700`: confirm `+0x119` and `+0x118` roles.
- by-* docs checked:
  - Target [UID:0004E8], parent [UID:0001F9], class [UID:0000AR], file [UID:0000MP], class2 [UID:0000AS], sibling paint [UID:0004EF], vtable docs [UID:0002UW]/[UID:0002UX].
  - Helper docs [UID:0000XY], [UID:0002KP], [UID:0001OQ], [UID:000162], [UID:0001PI].
- Generated/tracker docs checked:
  - `auto-generated/-ag-research-tracker.md`: row for [UID:0004E8] at `84/88`, reconstructable true, B reports 0.
  - `auto-generated/-ag-memory-coverage.md`: [UID:0004E8] is non-emitting with owner `0000AR` and no generated output path.
  - `auto-generated/-ag-coverage-report-by-memory.md`: [UID:0004E8] current summary says exact paint child, reconstructable, emits_code false.
- Old report search terms:
  - `0004E8`, `0x0054b7c0`, `0054b7c0`, `PrettyButtonControlPaneOnPaint`, `PrettyButtonControlPane`, `sub_54B7C0`, `sub_4D02F0`, `sub_457A60`, `sub_4B9660`, `sub_4B9980`, `sub_584540`, `EPF`, `disabled overlay`, `frame`.
  - Relevant match opened: executed [B011 UID0001F9 PrettyButtonControls] split report, which created this child and preserved source-quality blockers. Other matches were helper/source-family leads, not prior UID0004E8 reports.
- Failed/unavailable checks:
  - First MCP batch against `b013_0001FN_20260702` failed with `Session not found`; a new bounded pass was completed against `b011_0004EC_20260702`.
  - Local `simroot_v2` path search found no `source-3/simroot_v2` directory in this checkout; generated C++ under `auto-generated/` was used only as read-only state.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID0004E8 should emit through direct class owner [UID:0000AR], not remain blank-emitter. | High | Owner already [UID:0000AR], vtable slot `0x0062231c -> 0x0054b7c0`, class/file parents emit, helper names resolved. | Target metadata `EMITTER_UIDS:0000AR`, target C++ policy, class/file support notes, generated source line `PrettyButtonControlPane::OnPaint()` | incorporate | applied - target validator `000000004958`; generated C++ header `000000004976` |
| C2 | Current range `0x0054b7c0-0x0054b879` is exact; following `0x0054b879-0x0054b880` is padding. | High | MCP `lookup_funcs` size `0xb9`; `get_bytes` seven `0xcc` after end; refresh target evidence/range notes and parent split inventory only if synchronized. | Target evidence/range notes and parent split row | already-present | already-present - exact child/parent ranges already existed; target now adds `0xcc` proof |
| C3 | Paint frame selection uses `+0x119` -> frame `+0x110`, `+0x118` -> frame `+0x114`, else frame `+0x10c`. | High | MCP decompile/disasm of `0x0054b7c0`; constructor initializes frame fields at `+0x10c/+0x110/+0x114`; setter writes `+0x119`, forwarder writes `+0x118`. | Target behavior/field table, class/file notes, formal C++ | incorporate | applied - target/class/file docs and generated C++ include the frame-selection order |
| C4 | Resource strings are at `+0x11c` for EPF resource and `+0x120` for palette resource. | High | Constructor calls string constructor for `Src` at `+0x11c` and `a4` at `+0x120`; paint passes them through `sub_584540` to `LookupLayoutEntry` and `RenderTileFrame`. | Target/class layout notes and formal C++ | incorporate | applied - target/class/file docs and generated C++ use `m_epfResourceName` and `m_paletteResourceName` |
| C5 | Disabled overlay path is part of this method: if `+0x101` is false, set draw color `143` (`0x8f`) and mode byte `+0x70=2`, then dispatch Surface slot 7 over bounds `+0x44`. | High | MCP decompile/disasm; int_convert verified `143 == 0x8f`; helper docs [UID:000162] and [UID:0001PI]. | Target behavior, class/file support notes, and formal C++ | incorporate | applied - generated C++ includes `SetDrawColor(143)`, `m_drawMode = 2`, and `PreparePaneRegion(this, &m_bounds)` |
| C6 | Raw helper names should be replaced by accepted source-facing roles. | High | Current support docs for EPFTileContext, ResourceLayoutTable, g_pEPFLib, GrafPort, Surface callback table, and B010/B011 paint reports. | Target evidence and support docs | incorporate | applied - target/source-ready notes use helper roles; raw addresses preserved only as evidence |
| C7 | Recommended source-facing member names are inferred/descriptive, not original-symbol proof. | Medium-high | Cross-method field use; no recovered member symbols. | Target and class source-quality notes | incorporate | applied - target field table and class/file notes state inferred/descriptive caveat |
| C8 | Raise target from `84/88` to `88/90`; do not raise higher yet. | Medium-high | Evidence resolves emitter and behavior blockers; exact original member spellings/class declarations remain inferred. | Target score rationale | incorporate | applied - target validator `000000004958` recorded completion/confidence `88/90` |
| C9 | Parent [UID:0001F9] remains non-emitting split/index; no new split/child pages are needed. | High | B011 executed split report and current child page state. | Parent/support docs only if synchronization needed | already-present | already-present - parent metadata unchanged; only UID0004E8 row/evidence synchronized |
| C10 | Sibling [UID:0004EF] should remain comparison evidence only in this callback. | High | Class2 paint has parallel but distinct state/field layout and remains outside UID0004E8 scope. | Report/support recommendations | not-applicable | excluded-with-reason - no PrettyButtonControlPane2 or UID0004EF files edited |

## Positive Evidence Summary

- Direct facts supporting the recommendation: exact function body, vtable data slot, class owner, class/file emitter route, helper names, frame/resource field flow, and disabled overlay path are all current-session or current-doc backed.
- Corroborating documentation/generated-report evidence: target and auto-generated memory coverage already mark [UID:0004E8] as reconstructable and owned by `0000AR`; only the emitter is blank. Class/file pages already route `PrettyButtonControlPane` through `PrettyButtonControlPane.cpp`.
- Strongest inference chain: constructor initializes frame/string fields; paint consumes exactly those fields; state setter and forwarder update the branch bytes; helper docs provide source-facing render calls. That is enough for first-draft formal C++ with inferred member names.

## IDA MCP Facts

- Function/range facts: `lookup_funcs 0x0054b7c0` returns `sub_54B7C0`, size `0xb9` (`185`, Verified with int_convert.py), half-open `0x0054b7c0-0x0054b879`.
- Data/table/padding facts: `get_bytes 0x0062231c` returns `c0 b7 54 00`, the vtable slot pointer to this method. `get_bytes 0x0054b879 size 7` returns all `0xcc`.
- Xref facts: `xrefs_to 0x0054b7c0` reports only one data xref from `0x0062231c`; no direct code callers.
- Vtable/global/type facts: [UID:0002UW] documents slot `0x0062231c` as `PrettyButtonControlPane::OnPaint`-style draw slot. [UID:0001OQ] documents global `0x0067a744` as `g_pEPFLib`. [UID:0001PI] documents `0x0069b3fc` as Surface callback table slot 7.
- Negative IDA facts: no evidence of a separate free-function owner, caller-owned body, or base `ButtonControlPane` ownership for this exact paint method.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x0054b750-0x0054b7b2` | [UID:0004E7] `PrettyButtonControlPaneSetVisualState` | sets `+0x119` state-11 visual flag and schedules timer | true | [UID:0000AR] | `84/88` | support evidence |
| `0x0054b7b2-0x0054b7c0` | parent inventory only | padding | false | none | n/a | already documented |
| `0x0054b7c0-0x0054b879` | [UID:0004E8] target | class1 paint, EPF frame draw, disabled overlay | true | [UID:0000AR] | `84/88` current, `88/90` recommended | should emit |
| `0x0054b879-0x0054b880` | parent inventory only | padding | false | none | n/a | MCP refreshed |
| `0x0054b880-0x0054b8b9` | [UID:0004E9] `PrettyButtonControlPaneOnClick` | click/timer/callback | true | [UID:0000AR] | `84/88` | sibling evidence |
| `0x0054baa0-0x0054bb48` | [UID:0004EF] class2 paint | comparison paint path without class1 disabled overlay | true | [UID:0000AS] | `84/88` | out of scope |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0062231c` | data xref to `0x0054b7c0`; slot contains `c0 b7 54 00` | class1 vtable draw/paint slot |
| `0x0054b806` | calls `0x00457a60` | initializes local EPFTileContext |
| `0x0054b816` | calls `0x00584540` on `this+0x11c` | obtains EPF resource string data |
| `0x0054b81e` | calls `0x004d02f0` with `g_pEPFLib`, resource string, frame id, tile context | resource-layout lookup |
| `0x0054b82e` | calls `0x00584540` on `this+0x120` | obtains palette string data |
| `0x0054b841` | calls `0x004b9980` | renders frame into bounds `this+0x44` with palette |
| `0x0054b856` | calls `0x004b9660` with `143` (`0x8f`) | disabled overlay draw-color setup |
| `0x0054b862` | indirect call through `0x0069b3fc` with `this`, `this+0x44` | pane-region fill/refresh callback |

## Documentation Evidence And IDA Status

- Existing docs that support the conclusion: [UID:0000AR] lists `OnPaint` as `0x0054b7c0-0x0054b878` and source method child; [UID:0002UW] records vtable slot `0x0062231c`; [UID:0000MP] places the source in `NexusTK/ui/controls/PrettyButtonControlPane.cpp`; helper docs provide source-facing names for raw callees.
- Existing docs that are stale/incomplete: target currently says formal C++ remains blank pending accepted frame/resource constants and member names. This report resolves that as an implementation-ready source-quality plan with inferred names.
- Generated/coverage report state: generated memory coverage lists [UID:0004E8] as `non-emits` with owner `0000AR`; after callback it should become emitting through [UID:0000AR] and appear in `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp`.

## Ranked Ownership Analysis

### 1. [UID:0000AR] PrettyButtonControlPane

- Evidence for: direct class page owns method inventory; vtable slot [UID:0002UW] points at the target; constructor initializes fields consumed by paint; sibling class1 methods share the same class owner.
- Evidence against: exact member names are inferred, but that affects confidence/C++ polish, not ownership.
- Decision: best direct owner and recommended emitter.

### 2. [UID:0000MP] PrettyButtonControlPane source file

- Evidence for: file root emits both styled button classes; class parent emits through this file; source placement is already `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.
- Evidence against: by-structure direct-owner rule prefers class [UID:0000AR] for method body, with file root as source module rather than direct method owner.
- Decision: keep as source-file route, not direct child owner.

### 3. [UID:0000HY] ButtonControlPane / base control layer

- Evidence for: constructor calls shared base button-control constructor and paint uses inherited bounds/draw state.
- Evidence against: base calls are dependencies; vtables, constructor fields, and method slot belong to `PrettyButtonControlPane`.
- Decision: rejected as direct owner.

### 4. CreateUser dialog construction functions

- Evidence for: constructor fan-in from CreateUser dialog constructors.
- Evidence against: caller allocation sites consume the styled button control but do not own its vtable, paint, state, click, or destructor methods.
- Decision: rejected as owner; preserve as consumer context only.

### Proposed new file/grouping, if applicable

No new file or grouping is recommended. Use existing [UID:0000MP] `NexusTK/ui/controls/PrettyButtonControlPane.cpp`.

## Source Placement

- Recommended source file/class/global/module placement: `PrettyButtonControlPane::OnPaint` in `NexusTK/ui/controls/PrettyButtonControlPane.cpp`, routed through [UID:0000AR] and [UID:0000MP].
- Why this placement fits: the method is a class vtable paint slot, uses class-local frame/resource fields, and depends on generic render helpers in existing support docs.
- Rejected placements: `ButtonControlPane.cpp` is base/dependency only; CreateUser dialog files are consumer/allocation context only; Surface/EPFTileContext/ResourceLayout are helper owners, not this method owner.
- Remaining placement uncertainty: none material for this target.

## Range / Split / Padding / Reclassification Analysis

- Exact range/boundary facts: `0x0054b7c0-0x0054b879` function body, `0x0054b879-0x0054b880` `0xcc` padding.
- Children/subranges: no new child pages required; [UID:0004E8] is already exact.
- Padding/table/data/code distinctions: vtable pointer at `0x0062231c` belongs to [UID:0002UW] source-declared/generated-binary data; target is source-authored `.text`.
- Parent/container impact: [UID:0001F9] remains non-emitting split/index. It may need only a short synchronization note after target starts emitting; no reclassification.

## Negative Evidence Summary

- No direct code callers: target is vtable-only, so caller searches cannot name a dialog owner.
- No proof for `ButtonControlPane` ownership: inherited bounds and draw state are normal base fields used by derived paint methods.
- No reason to leave raw helper names as blockers: accepted support docs and recent B reports already document source-facing helper roles.
- No reason to create new split pages: target is already exact and adjacent padding is documented.
- No final-audit score: original member names and concrete class declarations remain inferred, so `95+` is not appropriate.

## IDA Rename / Type / Comment Recommendations

- Proposed source-facing names/types/comments for docs, not IDA DB edits:
  - `PrettyButtonControlPane::OnPaint` for `sub_54B7C0`.
  - `m_normalFrameId` at `+0x10c`, `m_pressedFrameId` at `+0x110`, `m_hoverFrameId` at `+0x114`.
  - `m_hoverFrameActive` at `+0x118`, `m_state11VisualActive` or `m_pressedVisualActive` at `+0x119`.
  - `m_enabled` at `+0x101`, `m_bounds` at `+0x44`, inherited draw/blit mode byte at `+0x70`.
  - `m_epfResourceName` at `+0x11c`, `m_paletteResourceName` at `+0x120`.
  - `kDisabledOverlayColor = 143` (`0x8f`, Verified with int_convert.py).
- Evidence: constructor/paint/setter decompilation and accepted helper pages.
- Items intentionally left unchanged: exact original public names for state byte `+0x119` and inherited mode byte `+0x70`; use descriptive names in target docs until broader class declaration work finalizes them.
- IDA DB edits: not requested in this report-only pass.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. [UID:0004E8] is reconstructable, has a confirmed owner/emitter route through [UID:0000AR] and [UID:0000MP], average score should exceed `85`, and source-quality blockers are resolved to implementation-ready inferred names.
- Recommended code: exact formal `RECONSTRUCTION_CPP CODE` insertion text for the target page:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
int PrettyButtonControlPane::OnPaint()
{
    int frameId = m_normalFrameId;

    if (m_state11VisualActive) {
        frameId = m_pressedFrameId;
    } else if (m_hoverFrameActive) {
        frameId = m_hoverFrameId;
    }

    EPFTileContext tileContext;
    tileContext.Init();

    g_pEPFLib->LookupLayoutEntry(m_epfResourceName.c_str(), frameId, &tileContext);

    FrameDrawRecord drawRecord;
    int result = RenderTileFrame(&tileContext,
                                 &drawRecord,
                                 &m_bounds,
                                 1,
                                 m_paletteResourceName.c_str(),
                                 0);

    if (!m_enabled) {
        SetDrawColor(143);
        m_drawMode = 2;
        return g_surfaceRenderCallbacks->PreparePaneRegion(this, &m_bounds);
    }

    return result;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Reason it preserves exact original behavior: the branch order, frame id selection, resource lookup, render call arguments, disabled draw-color value, mode-byte write, and callback dispatch match current MCP decompilation/disassembly.
- Reason it matches plausible original source shape: it uses class fields and shared render helpers rather than raw addresses/decompiler temporaries; it keeps method ownership in `PrettyButtonControlPane.cpp`.
- Inferred source-facing names/types/fields used instead of raw labels: listed in the IDA Rename / Type / Comment Recommendations section.
- Naming/coding style convention: existing accepted docs use `m_` member names, class methods, `g_p...` globals, and small source-level helper calls for UI/control paint paths.
- Reason code should remain blank, if applicable: not applicable. Remaining uncertainty should cap score, not block first-draft emission.
- Exact no-code proof, if not eligible: not applicable.

## Final Recommendation

- Exact changes recommended: update target metadata to `88/90`, set `EMITTER_UIDS:0000AR`, add current MCP evidence, add field/helper-name inference, insert formal C++ block.
- Exact parent assignments recommended: keep target owner [UID:0000AR]; keep class/file route through [UID:0000MP].
- Exact items left no-owner/non-emitting: none inside [UID:0004E8]. Parent [UID:0001F9] remains non-emitting split/index by existing accepted proof.
- Future work outside scope: class-wide final declaration polish for all `PrettyButtonControlPane` fields and sibling [UID:0004EF] paint emission.

## Recommended Target Doc Changes

- Target path: `by-memory/0x0054b7c0-0x0054b879.PrettyButtonControlPaneOnPaint.md`
- Exact report facts to incorporate:
  - Current MCP session `b011_0004EC_20260702`, health state, function size/range, vtable xref, bytes/padding, disassembly/decompile behavior, helper roles, constructor/setter support, rejected owner alternatives, and first-draft C++.
  - Raw helper aliases and source-facing names from support docs.
  - Inferred member field table for `+0x10c/+0x110/+0x114/+0x118/+0x119/+0x11c/+0x120/+0x101/+0x44/+0x70`.
- Metadata/score/owner/emitter/reconstructable/C++ changes:
  - `COMPLETION:84 -> 88`
  - `CONFIDENCE:88 -> 90`
  - `CANONICAL_OWNER:0000AR` unchanged
  - `RECONSTRUCTABLE:TRUE` unchanged
  - `EMITTER_UIDS:` blank -> `0000AR`
  - Insert formal C++ block above.
- Historical/stale assumptions to preserve:
  - Earlier blank C++ was due to unresolved frame/resource/member names; this report supersedes that blocker with inferred names and accepted helper names.
  - `ButtonControlPane` and CreateUser dialog ownership remain rejected.

## Recommended Support Doc Changes

- Support path: `by-class/PrettyButtonControlPane.md`
  - Add a concise method note under `OnPaint` that [UID:0004E8] is source-ready/first-draft-ready, uses frame ids at `+0x10c/+0x110/+0x114`, flags at `+0x118/+0x119`, strings at `+0x11c/+0x120`, disabled flag `+0x101`, bounds `+0x44`, and disabled overlay color `143` (`0x8f`, Verified with int_convert.py).
  - Consider score `87/89 -> 88/90` only if the class page incorporates this and no other class-wide blockers become newly exposed.
- Support path: `by-file/PrettyButtonControlPane.md`
  - Add [UID:0004E8] as the first method child in this family that should emit first-draft method C++ through [UID:0000AR], while parent [UID:0001F9] remains non-emitting.
  - Consider score `87/89 -> 88/90` only if source-ready child status and helper route are incorporated.
- Support path: `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md`
  - Optional sync only: update the [UID:0004E8] row from blank-C++/source-blocked wording to source-ready child wording. Do not change parent reconstructable/emitter state.
- Support path: `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md`
  - Optional sync only if not already detailed enough: slot `0x0062231c` points to source-ready/emitting [UID:0004E8]. No score/owner/emitter change required.
- Support path: `by-file/ButtonControlPane.md`
  - No edit recommended; base dependency rejection is already clear enough.
- Support path: `by-class/PrettyButtonControlPane2.md` and [UID:0004EF]
  - No edit recommended for this callback. Use as comparison evidence only.

## Score And Metadata Recommendation

- Current score/metadata: `84/88`, `CANONICAL_OWNER:0000AR`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++.
- Recommended score/metadata: `88/90`, `CANONICAL_OWNER:0000AR`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000AR`, formal C++ populated.
- Score rationale and reason not higher/lower:
  - Raise completion because the report resolves the named blockers: helper names, member/field roles, disabled overlay behavior, range/padding, vtable route, and C++ readiness.
  - Raise confidence because current MCP independently reconfirms behavior and support docs resolve raw helper roles.
  - Do not raise above `90` confidence because original member spellings and exact class declarations remain inferred, not recovered.
- Score-improvement attempt:
  - Raw helper names: resolved through existing accepted helper docs.
  - Frame/resource constants: resolved as constructor-provided frame ids/resource strings, not hard-coded literals.
  - Member names: resolved to descriptive inferred names with evidence and caveat.
  - Emitter route: resolved through [UID:0000AR] -> [UID:0000MP].
  - First-draft C++: supplied as formal insertion block.
- Metadata fields to change or leave unchanged: only `COMPLETION`, `CONFIDENCE`, `EMITTER_UIDS`, and C++ block should change.

## Open Questions With Attempted Resolution

- Whether blank emitter is still justified: resolved as no. Evidence checked: MCP decompile/disasm/bytes/xrefs, class/file/vtable docs, helper docs, and old B011 split report. Result: target can emit through [UID:0000AR].
- Whether frame/resource constants are hard-coded unknowns: resolved as no. The method uses constructor-provided frame ids and resource strings, so the C++ should use member fields rather than inventing literal resource names.
- Whether `+0x119` and `+0x118` names are proven: partially resolved. Their behavior is proven, exact original names are not. Use descriptive names and cap score.
- Whether `RenderTileFrame`/Surface slot names are final: resolved enough for target. Existing support docs and accepted reports use those source-facing roles; exact callback typedef polishing remains broader Surface work and does not block this method.
- Whether sibling [UID:0004EF] should also emit now: unresolved outside this assignment. It has parallel evidence but distinct class2 state layout and should receive its own report/callback.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Not applicable. No manual `-coverage-report.md` or supervisor tracker edit is recommended during this report-only pass. Validator-owned generated reports should refresh from target/support validators after an implementation callback.

## Follow-Up Actions

- Supervisor actions: Gate 1 review of this report; if accepted, send implementation callback for target/support doc edits listed above.
- A-agent actions: none.
- B002 future research actions: if assigned later, perform the parallel source-quality pass for [UID:0004EF] `PrettyButtonControlPane2::OnPaint`.

## Confidence

- Recommendation confidence: high.
- Score confidence: medium-high.
- Remaining uncertainty: exact original member spellings and class declaration placement for newly named fields; this affects final polish, not current emitter eligibility.

## Validator Results

- Commands run: none. This is a report-only pass.
- Results: not applicable.
- Any unresolved validator warnings/errors: none observed because no validator was run.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B002/research/0004E8-PrettyButtonControlPaneOnPaint-source-quality.md`
- Modified: none outside B002 research folder.
- Renamed: none.
- Leases: none used; no lease is required for report-only work in B002's own folder.
- Report execution: not run. B002 did not run `execute_report`, dry-run/probing variants, registry lifecycle commands, manual report moves, archive commands, or equivalents.

## Implementation Tracking Checklist

Implementation callback pass (2026-07-03):

- [x] Supervisor validation required before implementation. Proof: user/supervisor callback explicitly requested implementation of accepted UID0004E8 report.
- [x] Target doc updated: `by-memory/0x0054b7c0-0x0054b879.PrettyButtonControlPaneOnPaint.md`. Proof: metadata, evidence, field table, C++ policy, score rationale, and formal C++ were updated; validator `000000004958` at `2026-07-03T01:53:42-04:00` returned `ok: 1`.
- [x] Target metadata applied: `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000AR` unchanged, `RECONSTRUCTABLE:TRUE` unchanged, `EMITTER_UIDS:0000AR`. Proof: validator `000000004958` recorded completion/confidence/emitter registry updates.
- [x] Target formal C++ applied: exact `RECONSTRUCTION_CPP CODE` insertion block from `## First-Draft C++ Recommendation`. Proof: generated `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` includes UID0004E8 and `int PrettyButtonControlPane::OnPaint()`.
- [x] Target evidence incorporated: MCP session `b011_0004EC_20260702`, function size/range, vtable xref, no direct code callers, disassembly/decompilation behavior, bytes/padding, constructor/setter support, helper source-facing names, and rejected owners. Proof: target `## Evidence`, `## Source-Quality Field And Helper Names`, and `## Ownership And C++ Policy`.
- [x] Target source-quality names incorporated: frame id fields `+0x10c/+0x110/+0x114`, state flags `+0x118/+0x119`, resource strings `+0x11c/+0x120`, enabled flag `+0x101`, bounds `+0x44`, draw-mode byte `+0x70`, disabled color `143` (`0x8f`, Verified with int_convert.py). Proof: target field table, class method note, file split row, parent sync note, and generated C++.
- [x] Support doc updated: `by-class/PrettyButtonControlPane.md` with UID0004E8 source-ready method note and field/helper roles; applied `87/89 -> 88/90`. Proof: validator `000000004973` at `2026-07-03T01:59:46-04:00` returned `ok: 1`.
- [x] Support doc updated: `by-file/PrettyButtonControlPane.md` with UID0004E8 source-ready child/emitter route; applied `87/89 -> 88/90`. Proof: validator `000000004974` at `2026-07-03T01:59:48-04:00` returned `ok: 1`.
- [x] Optional support sync applied: `by-memory/0x0054b5e0-0x0054bcbd.PrettyButtonControls.md` [UID0004E8] row and evidence only; no parent owner/reconstructable/emitter change. Proof: validator `000000004975` at `2026-07-03T01:59:50-04:00` returned `ok: 1`.
- [x] Optional support sync applied: `by-memory/0x006222d4-0x00622378.PrettyButtonControlPaneVtableData.md` slot `0x0062231c`; no metadata change. Proof: validator `000000004976` at `2026-07-03T01:59:51-04:00` returned `ok: 1`.
- [x] Confirm no edits are needed for `by-class/PrettyButtonControlPane2.md`, [UID:0004EF], or `by-file/ButtonControlPane.md` unless supervisor expands scope. Proof: excluded as out-of-scope comparison/base dependency; no files edited.
- [x] Preserve historical/stale assumptions: old blank-C++ blocker was source-quality naming, now superseded; ButtonControlPane and CreateUser dialog ownership remain rejected; parent [UID0001F9] remains non-emitting split/index. Proof: target ownership policy, class/file support notes, and parent metadata unchanged.
- [x] Claim And Incorporation Ledger updated with applied/already-present/excluded proof during callback. Proof: ledger rows C1-C10 now show applied/already-present/excluded proof.
- [x] Scoped validators run after callback from `source-3/project-documentation`: every changed by-* file with `python .\tools\validator.py --mode file --file <path> --apply --queue-timeout 240`. Proof: commands `000000004958`, `000000004973`, `000000004974`, `000000004975`, and `000000004976` all returned `ok: 1`.
- [x] Generated refresh expectation verified: `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `auto-generated/-ag-research-tracker.md`, and `auto-generated/NexusTK/ui/controls/PrettyButtonControlPane.cpp` refreshed through validators and show [UID0004E8] emitting through [UID0000AR]/[UID0000MP]. Proof: queue status `000000004980` at `2026-07-03T02:00:38-04:00` reported zero queued/processing refresh jobs; generated headers show command `000000004976` at `2026-07-03T01:59:51-04:00`; `rg` found UID0004E8 as `coded` and generated `PrettyButtonControlPane::OnPaint()`.
- [x] B002 did not edit generated reports, generated C++, project-level generated reports, manual coverage reports, validator state, queues, archives, supervisor ledgers, or run report lifecycle/archive commands. Proof: generated files were validator-refreshed only; no `execute_report` or lifecycle/archive command was run.

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004997","destination_path":"executed-b-agent-research/B002/0004E8-PrettyButtonControlPaneOnPaint-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0004E8-PrettyButtonControlPaneOnPaint-source-quality.md","timestamp":"2026-07-03T02:26:08-04:00","uid":"0004E8"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
