** TARGET-REPORT-UID:0004C4 **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 0004C4 IMECompositionPaneOnKeyEvent Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: convert [UID:0004C4] `by-memory/0x004e7810-0x004e7838.IMECompositionPaneOnKeyEvent.md` from a blank split child into an emitting `IMECompositionPane::OnKeyEvent(const Event *event)` child.
- Final disposition: keep direct owner [UID:00006G] `IMECompositionPane`; route output through [UID:00006G] into [UID:0000K5] `IMEPanes`; set `EMITTER_UIDS:00006G`; populate the formal target C++ block below after supervisor validation.
- Required action: implementation callback should update the target page, synchronize the class/file/aggregate rows at report-level detail, run scoped validators with generated freshness for `auto-generated/NexusTK/input/IMEPanes.cpp`, and leave Event/InputMan support pages unchanged unless the callback re-read finds a contradiction.
- Confidence: high for exact range, vtable reachability, type-13 guard, payload fields, sole callee, owner/source route, and first-draft C++ readiness; capped below final-audit certainty because final Event union field spellings are inferred/descriptive.

## Target

- Target UID: `0004C4`.
- Target path: `by-memory/0x004e7810-0x004e7838.IMECompositionPaneOnKeyEvent.md`.
- Assignment: `B004-report-0004C4-IMECompositionPaneOnKeyEvent-by-memory-20260701`.
- Queue row: `auto-generated/-ag-research-tracker.md` lists [UID:0004C4] as `82/89`, combined `85.5`, reconstructable `true`, reports `0`.
- Current generated coverage: `auto-generated/-ag-coverage-report-by-memory.md` lists [UID:0004C4] with `emits_code:false`, `82%`, `strong`.

## Current Target State

- Current metadata: `COMPLETION:82`, `CONFIDENCE:89`, `CANONICAL_OWNER:00006G`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, blank formal C++.
- Current owner/source route: [UID:00006G] `IMECompositionPane` -> [UID:0000K5] `IMEPanes`; containing aggregate [UID:000189] `IMEPaneFamily`.
- Current behavior text: exact key-event split child; handles Event byte `13` and forwards text/length to [UID:00018A] `IMECompositionPane::SetCompositionString`.
- Current blocker: target says it is a strong future first-draft C++ candidate but leaves formal C++ blank because no child-specific body was accepted. Current MCP evidence resolves the body and Event-payload blocker.
- Related support state: [UID:00006G] already declares `virtual bool OnKeyEvent(const Event *event);` and has `[[CHILDREN]]`; [UID:00018A] already emits formal `SetCompositionString`; [UID:00014C]/[UID:0000J6] already document Event type `13` as composition result text.

## Supervisor Active Recheck

- Triggering instruction: report-only research for [UID:0004C4]; do not edit target/support by-* docs until supervisor validation and implementation callback.
- Split repair required: no new split is required. MCP confirms this is one exact 40-byte function with padding before and after.
- Source-bearing children in scope: only this exact by-memory child. Sibling composition children were read as source-route and field-layout context.

## Inference Research Guidance Check

- Evidence separation:
  - Direct IDA/MCP facts: function start/size, disassembly, decompilation, vtable xref, no direct code callers, bytes, callee, Event type-13 factory layout.
  - Documentation evidence: current target/support docs, executed B003/B008/B009/B010/B007 reports, Event/InputMan support docs, generated tracker/coverage state.
  - Inference: final source names `kEventImeCompositionResult`, `imeCompositionResultLength`, and `imeCompositionResultText` are source-facing Event union names inferred from current payload layout and Event factory docs.
- Wave2/Wave3 handling: stale historical owner/output wording was treated only as lead material. Current MCP, current by-* docs, and executed reports controlled this pass.

## Evidence Checked

- Required reading: B004 `goal.md`; `ntk-b-agent-workflow` skill; `b-agent-research-and-implementation-workflow.md`; `score-blocker-audit-standard.md`; `b-agent-report-template.md`; `by-structure.md` IDA MCP Output Discipline.
- Target/support docs read: target [UID:0004C4], [UID:00006G] `IMECompositionPane`, [UID:0000K5] `IMEPanes`, [UID:000189] `IMEPaneFamily`, [UID:00018A] `SetCompositionString`, [UID:00018E] `InputMan`, [UID:00014C] `EventManAndEventFactoryHelpers`, [UID:0000J6] `Event`.
- Generated/tracker docs checked read-only: `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and `auto-generated/NexusTK/input/IMEPanes.cpp`.
- Existing report search terms: `0004C4`, `0x004e7810`, `0x004e7838`, `IMECompositionPaneOnKeyEvent`, `SetCompositionString`, `IMECompositionPane`, `IMEPanes`.
- Relevant executed reports used as leads: B003 `00018A-ime-composition-set-composition-string-source-quality.md`; B008 `0000K5-IMEPanes-empty-emitter-family-source-quality.md`; B009 `0004C3-IMECompositionPaneOnMouseEvent-source-quality.md`; B008 `0004C5-IMECompositionPaneOnPaint-source-quality.md`; B008 `00014C-EventManAndEventFactoryHelpers-source-quality.md`; B001 `00018E-InputMan-source-quality.md`; B010 `0004CE-IMEPaneHandleIMEMessage-source-quality.md`.

## Current MCP Evidence

MCP was available; no fallback-only evidence was used.

| Call | Result |
| --- | --- |
| `initialize` | MCP server `ida-pro-mcp`, protocol `2025-06-18`. |
| `tools/list` | Current schema checked; inspection calls require `database`. |
| `idb_list` | Active worker session `supervisor_resume_20260629`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, pid/worker_pid `14860`. |
| `server_health` | `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, strings cache ready. |
| `lookup_funcs` | `0x004e7810` is `sub_4E7810`, size `0x28`; `0x004e7838` is not a function; previous padding start `0x004e7809` is not a function; next sibling `0x004e7840` is `sub_4E7840`, size `0xd2`; callee `0x004e7470` is `sub_4E7470`, size `0x1cc`; following accessor `0x004e7920` is size `0x7`. |
| `xrefs_to` | Target start has one data xref at `0x0061c444`; no direct code callers. `0x004e7470` has one code xref from this target at `0x004e782d`. |
| `get_int` | Secondary vtable cells: `0x0061c43c -> 0x004e7640` mouse handler, `0x0061c444 -> 0x004e7810` key handler, `0x0061c430 -> 0x004e7840` paint handler. |
| `entity_query names 0x0061c3ec-0x0061c480` | IMECompositionPane vtable symbols at `0x0061c3ec`, `0x0061c438`, and `0x0061c468`, followed by `IMECandidatePane` at `0x0061c474`. |
| `get_bytes` | `0x004e7809-0x004e7810` is seven `0xcc` bytes; target bytes at `0x004e7810` are the 40-byte function body; `0x004e7838-0x004e7840` is eight `0xcc` bytes; vtable cell `0x0061c444` bytes are `10 78 4e 00`. |
| `disasm 0x004e7810` | 15 instructions. The method checks `byte ptr [event+4] == 0x0d`, returns `0` if not, loads `event+9` as unsigned byte length, adjusts `ecx` by `0xffffff60` (`this-0xa0`), passes `event+0x0a` and length to `sub_4E7470`, returns `1`, and uses `retn 4`. |
| `decompile/analyze_function 0x004e7810` | `char __thiscall sub_4E7810(int *this, int event)`; if `*(BYTE *)(event+4) == 13`, calls `sub_4E7470(this - 40, (wchar_t *)(event + 10), *(unsigned __int8 *)(event + 9))` and returns `1`; otherwise returns `0`. Analyze reports one callee `sub_4E7470`, no callers, three basic blocks, complexity `2`. |
| `callees 0x004e7810` | Single internal callee: `0x004e7470` / `sub_4E7470`. |
| `lookup/decompile/disasm 0x004a9cb0` | Event type-13 factory `sub_4A9CB0`, size `0xfa`, sets Event type byte `13`, writes length byte at Event `+0x09`, copies UTF-16 text into the buffer starting at Event `+0x0a`, stores tick at `+0x10c`, and dispatches. Factory caps at `0x80` code units; target forwards the stored unsigned-byte count to `SetCompositionString`, whose own accepted body clamps to `255`. |

## Positive Evidence Summary

- The exact range is stable: MCP reports `sub_4E7810`, size `0x28`, with seven `0xcc` bytes before the entry and eight `0xcc` bytes after the half-open end.
- The inbound route is vtable-only: `0x0061c444` is the IMECompositionPane secondary vtable cell for this handler; no direct code caller exists.
- The owner is local and class-specific: the vtable row is in `IMECompositionPane`, the method normalizes a secondary EventHandler view back to the complete object with `this - 0xa0`, and the only callee is accepted [UID:00018A] `IMECompositionPane::SetCompositionString`.
- Event type and payload semantics are now target-specific: current Event docs and MCP on `0x004a9cb0` prove type `13` is composition result text, length is stored at Event `+0x09`, and UTF-16 text begins at Event `+0x0a`.
- The source body is simple and source-authored: return false unless the event is type `13`; otherwise forward text/length to `SetCompositionString` and return true.

## Negative Evidence Summary

- Not `InputMan`: InputMan produces the IME result event from `WM_IME_COMPOSITION` / `GCS_RESULTSTR`; this target consumes an already built Event record on the pane-side UI object.
- Not `Event`/`EventMan`: the Event factory owns creation of the type-13 record, but this target owns the pane-side virtual consumer and state update.
- Not `Pane`/generic EventHandler`: the vtable cell is under `IMECompositionPane`, and the only stateful callee is a composition-pane method. The `this-0xa0` adjustment is compiler secondary-view lowering, not a source owner.
- Not a no-code/wrapper case: IDA models a normal function object, it has a vtable data xref, and the body is an ordinary virtual event handler with visible source behavior.
- Not a merge with [UID:00018A] or sibling handlers: padding separates this function from both [UID:0004C3] and [UID:0004C5], and the target is its own vtable slot.

## Heuristic / Inference Reanalysis And Validation

The old blank-emitter state is no longer justified under the score-blocker standard.

- Event type name: Event support docs call type `13` `kEventImeCompositionResult` / composition result. MCP on the factory confirms the record type and payload layout. The target doc should stop describing this only as a generic "composition update" and should record the more precise result/commit path.
- Event field names: `imeCompositionResultLength` and `imeCompositionResultText` are inferred source-facing names for Event byte `+0x09` and the UTF-16 buffer at `+0x0a`. The layout is direct MCP fact; exact original field spellings remain unproven and cap confidence only.
- Method name/signature: the class shell already declares `virtual bool OnKeyEvent(const Event *event)`. The binary returns `AL`, uses `retn 4`, and matches the established pane virtual source shape.
- `this` adjustment: IDA decompiles `this - 40` because it treats `this` as `int *`; disassembly uses `add ecx, 0xffffff60`, i.e. `-0xa0` bytes. Source C++ should not expose that adjustment; it is the secondary EventHandler view normalized into `IMECompositionPane::OnKeyEvent`.
- Event type-13 factory cap: factory caps to `0x80` UTF-16 code units while [UID:00018A] also clamps to `255`. This is not contradictory. The handler simply forwards the Event's stored count to the accepted setter.
- Root IME dispatcher context: B010 UID0004CE proved the root `IMEPane::HandleIMEMessage` returns false for type `13`; this target is the composition-pane flow that consumes the result text. That separation supports class-local ownership rather than moving behavior to the root dispatcher.

## Ranked Ownership Analysis

### 1. [UID:00006G] `IMECompositionPane`

- Evidence for: target slot `0x0061c444` is in the IMECompositionPane secondary vtable; [UID:00006G] class shell declares `OnKeyEvent`; target calls `IMECompositionPane::SetCompositionString`; sibling mouse/paint/constructor/destructor children already emit through this class.
- Evidence against: the function consumes Event payload fields produced elsewhere, but that is dependency direction, not source ownership.
- Decision: keep direct canonical owner and make [UID:00006G] the emitter.

### 2. [UID:0000K5] `IMEPanes`

- Evidence for: correct source-file route for the class and generated `NexusTK/input/IMEPanes.cpp`.
- Evidence against: by-structure prefers the class page as direct owner/emitter when the class clears the gate.
- Decision: keep as source-file route through [UID:00006G], not direct target owner.

### 3. [UID:0000J6] `Event` / Event factory

- Evidence for: Event type `13` producer defines the payload this handler consumes.
- Evidence against: Event factory does not own the pane method or `SetCompositionString` call; its role ends after dispatching the Event record.
- Decision: reject as direct owner; cite as support evidence.

### 4. [UID:0000K6] `InputMan`

- Evidence for: InputMan extracts `GCS_RESULTSTR` and calls `DispatchCompositionResultEvent`.
- Evidence against: target has no Win32/IMM calls and is reached only by the composition pane vtable.
- Decision: reject as direct owner; producer-side dependency only.

### 5. `Pane` / generic EventHandler

- Evidence for: target is reached through a secondary event-handler view.
- Evidence against: the vtable belongs to `IMECompositionPane`, and the call target is a composition-pane method.
- Decision: reject as direct owner.

## Range / Split / Padding / Reclassification Analysis

- Keep target range `0x004e7810-0x004e7838`. MCP `lookup_funcs` size `0x28` makes the half-open end exactly `0x004e7838`.
- Predecessor padding: `0x004e7809-0x004e7810` is seven `0xcc` bytes after [UID:0004C3].
- Successor padding: `0x004e7838-0x004e7840` is eight `0xcc` bytes before [UID:0004C5].
- No internal split is needed. The whole body is one simple virtual event handler.
- Reclassification is not needed. This is reconstructable NexusTK source code, not compiler glue or runtime support.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x004e7640-0x004e7809` | [UID:0004C3] `IMECompositionPaneOnMouseEvent` | Drag/mode/root-anchor mouse handler. | TRUE | [UID:00006G] | `88/91` | Emitting sibling; validates adjacent vtable route. |
| `0x004e7810-0x004e7838` | [UID:0004C4] `IMECompositionPaneOnKeyEvent` | Composition result key/event handler; forwards result text to `SetCompositionString`. | TRUE | [UID:00006G] | recommended `88/91` | Primary target. |
| `0x004e7840-0x004e7912` | [UID:0004C5] `IMECompositionPaneOnPaint` | Paints background, frame, text, and caret. | TRUE | [UID:00006G] | `88/91` | Emitting sibling; validates class route. |
| `0x004e7470-0x004e763c` | [UID:00018A] `SetCompositionString` | Measures/clamps/copies composition text and invalidates. | TRUE | [UID:00006G] | `88/91` | Sole callee from target; formal C++ already populated. |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x0061c444 -> 0x004e7810` | Data xref to target start | IMECompositionPane secondary vtable slot for `OnKeyEvent`. |
| `0x004e782d -> 0x004e7470` | Target call to [UID:00018A] | Forwards Event text/length to `SetCompositionString`. |
| `0x004a9cb0` | Event factory for type `13` | Producer-side proof for Event length/text layout consumed by target. |

## Documentation Evidence And IDA Status

- Existing target doc already has correct range, owner, reconstructable flag, and callee relationship but leaves emitter/C++ blank.
- [UID:00006G] class doc already has `OnKeyEvent` in the class shell and [UID:00018A]/[UID:0004C3]/[UID:0004C5] sibling context.
- [UID:0000K5] file doc records [UID:0004C4] as the remaining composition-pane key handler row under IMEPanes.
- [UID:000189] aggregate doc lists [UID:0004C4] as Event byte `13`, calls [UID:00018A].
- [UID:00014C] and [UID:0000J6] now document type `13` as `kEventImeCompositionResult`.
- [UID:00018E] `InputMan` shows `GCS_RESULTSTR` producer path and `DispatchCompositionResultEvent(resultText, GetMessageTime())`.
- `auto-generated/NexusTK/input/IMEPanes.cpp` current header is `validator-command-id: 000000004078`, refreshed `2026-07-01T17:29:41-04:00`; read-only `rg` found no UID0004C4 marker or `IMECompositionPane::OnKeyEvent`, consistent with blank target emitter.

## First-Draft C++ Recommendation

- Eligible for draft C++: yes. The target is reconstructable, has a strong direct owner, has an exact vtable-reached function body, and the score recommendation clears the active code gate.
- Recommended code: exact formal target insertion text for supervisor-approved callback:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool IMECompositionPane::OnKeyEvent(const Event *event)
{
    if (event->type != kEventImeCompositionResult) {
        return false;
    }

    SetCompositionString(event->imeCompositionResultText,
                         event->imeCompositionResultLength);
    return true;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

- Third-party import directive: not applicable.
- Reason it preserves exact original behavior: the code returns false unless Event type is `13`; on type `13`, it forwards Event payload text at `+0x0a` and unsigned-byte length at `+0x09` to `SetCompositionString`, then returns true.
- Reason it matches plausible source shape: source C++ should name the virtual method and Event union fields, not expose `sub_4E7470`, `this-0xa0`, raw offsets, or decompiler temporaries.
- Naming caveat: if the project later standardizes Event union names differently, `imeCompositionResultText` and `imeCompositionResultLength` can be adjusted during callback, but the target doc must preserve the exact offset facts and type-13 result-text evidence.
- Exact no-code proof: not applicable; no-code is rejected.

## Score And Metadata Recommendation

- Current score/metadata: `82/89`, owner `00006G`, reconstructable `TRUE`, blank emitter, blank formal C++.
- Recommended score/metadata:

```text
COMPLETION:88
CONFIDENCE:91
CANONICAL_OWNER:00006G
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00006G
EMITTER_POSITION_OPTIONAL:
```

- Completion rationale: exact range/padding, vtable slot, no-direct-caller caveat, callee route, Event type/result payload fields, producer-side factory proof, source owner, rejected alternatives, and first-draft formal C++ are now documented.
- Confidence rationale: direct MCP proves the complete target body and vtable route; Event factory MCP plus current Event/InputMan docs prove the payload semantics. Confidence stays below final-audit range because Event field spellings remain inferred.
- Score-improvement attempt:
  - Blank-emitter blocker researched through target decompile/disasm and sibling class/file route; result: formal C++ is safe.
  - Event-byte uncertainty researched through current Event/InputMan docs and MCP decompile/disasm of `0x004a9cb0`; result: type `13` is composition result text with length byte plus UTF-16 payload.
  - Owner/emitter uncertainty researched through vtable cell, class/file docs, and [UID:00018A] callee route; result: [UID:00006G] owner/emitter is strong.
  - Split/range uncertainty researched through MCP lookup and bytes; result: no split.
- Metadata fields to leave unchanged: UID, canonical owner, reconstructable true, and blank optional position.

## Recommended Target Doc Changes

Target path: `by-memory/0x004e7810-0x004e7838.IMECompositionPaneOnKeyEvent.md`

Incorporate:

- Metadata change to `88/91`, `EMITTER_UIDS:00006G`, owner/reconstructable/blank optional position unchanged.
- Formal C++ block above.
- Behavior: `IMECompositionPane::OnKeyEvent` returns false for non-`kEventImeCompositionResult`; on type `13`, it passes Event result text and result length to `SetCompositionString`, then returns true.
- MCP facts: current session `supervisor_resume_20260629`; target `sub_4E7810` size `0x28`; predecessor/successor `0xcc` padding; vtable data xref `0x0061c444`; no direct code callers; single callee `0x004e7470`; `this-0xa0` secondary-view normalization.
- Event layout evidence: target reads `event+4` type, `event+9` unsigned-byte text length, and `event+0x0a` UTF-16 text; Event factory `0x004a9cb0` writes the same layout for type `13`.
- Rejected alternatives: InputMan producer ownership, Event factory ownership, generic Pane/EventHandler owner, no-code disposition, and sibling merge.
- Historical correction: current docs' "composition update" wording should be sharpened to "composition result/commit text" because type `13` is `DispatchCompositionResultEvent`; type `10` is the composition text/update helper.

## Recommended Support Doc Changes

`by-class/IMECompositionPane.md`

- Update the `OnKeyEvent` method row to link [UID:0004C4], score `88/91`, formal C++ populated, Event type `13` result-text guard, payload forwarding to [UID:00018A], and vtable slot `0x0061c444`.
- Add an evidence/change note that current MCP proves `sub_4E7810` size `0x28`, `this-0xa0` secondary-view normalization, one vtable data xref, and no direct code callers.
- No class score change is required because it is already `88/91`.

`by-file/IMEPanes.md`

- Update the `IMECompositionPane` proposed-contents/evidence note to say [UID:0004C4] now emits `IMECompositionPane::OnKeyEvent` through [UID:00006G] into this file.
- No score change required; this is one remaining child improvement inside an already high-scored source file.

`by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`

- Update the UID0004C4 covered-range/split-source row from "Event byte `13`, calls SetCompositionString" to include formal C++ populated, exact `0x28` function size, vtable cell `0x0061c444`, result-text length/text payload, and rejected no-code/sibling-merge alternatives.
- No aggregate score change required; it remains an aggregate/source-order page.

`by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md`

- Optional support only. Current content already records this target as the sole caller at `0x004e782d`, Event type `13`, payload at `+0x0a`, and length byte at `+0x09`. Mark already-present unless callback finds drift.

`by-memory/0x004a8ac0-0x004ab3eb.EventManAndEventFactoryHelpers.md`, `by-file/Event.md`, `by-memory/0x004e8af0-0x004e970d.InputMan.md`, and `by-file/InputMan.md`

- Already-present support. Current docs already prove `DispatchCompositionResultEvent`/type `13`, `GCS_RESULTSTR`, and producer-side ownership. Do not churn these files during UID0004C4 callback unless a fresh contradiction is found.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C001 | Current target state is `82/89`, owner `00006G`, reconstructable true, blank emitter/formal C++. | High | Target metadata and generated coverage read. | Target Status/Score/Changes | incorporate | applied: target now records `88/91`, owner `00006G`, reconstructable true, `EMITTER_UIDS:00006G`, and populated formal C++; validator `000000004097` confirms completion/confidence/registry updates. |
| C002 | MCP was available through `supervisor_resume_20260629`; no fallback-only evidence used. | High | `initialize`, `tools/list`, `idb_list`, `server_health`. | Target Evidence / report evidence note | incorporate | applied: target Evidence and Changes preserve MCP session `supervisor_resume_20260629` as source proof. |
| C003 | Target is exact `sub_4E7810`, size `0x28`, range `0x004e7810-0x004e7838`. | High | MCP `lookup_funcs`, `disasm`, `analyze_function`. | Target Evidence / Range notes; aggregate row | incorporate | applied: target Status/Evidence and aggregate covered/split rows record exact `0x28` half-open range. |
| C004 | Predecessor padding is seven `0xcc` bytes at `0x004e7809-0x004e7810`; successor padding is eight `0xcc` bytes at `0x004e7838-0x004e7840`. | High | MCP `get_bytes`. | Target Evidence; aggregate row | incorporate | applied: target Evidence records both padding spans; aggregate evidence/split rows preserve padding. |
| C005 | Target has one vtable data xref at `0x0061c444` and no direct code callers. | High | MCP `xrefs_to`, `get_int`, `entity_query`, `analyze_function`. | Target Evidence/Xrefs; class support | incorporate | applied: target Status/Evidence, class method/evidence, file evidence, and aggregate rows record `0x0061c444` and no direct callers. |
| C006 | Target belongs to `IMECompositionPane` and should emit through [UID:00006G], with [UID:0000K5] as source-file route. | High | Vtable slot in IMECompositionPane secondary table; class/file docs; [UID:00018A] callee route. | Target metadata; class/file support | incorporate | applied: target `EMITTER_UIDS:00006G`, class method row, file route row, and aggregate source-placement row all route UID0004C4 through [UID:00006G] into [UID:0000K5]. |
| C007 | Target returns false unless Event type byte at `+0x04` equals `13`. | High | MCP disasm/decompile. | Target Behavior/formal C++ | incorporate | applied: target Behavior and formal C++ implement the type-13 guard and false return. |
| C008 | On type `13`, target forwards Event text at `+0x0a` and unsigned-byte length at `+0x09` to [UID:00018A] at `0x004e7470`, then returns true. | High | MCP disasm/decompile; `xrefs_to 0x004e7470`; [UID:00018A]. | Target Behavior/formal C++; SetCompositionString already-present support | incorporate | applied: target Behavior/Evidence/formal C++, class method row, file evidence, and aggregate row record UID00018A call at `0x004e782d` plus offsets `+0x09/+0x0a`. |
| C009 | Event type `13` is composition result/commit text, not the type `10` composition text/update helper. | High | [UID:00014C], [UID:0000J6], [UID:00018E], MCP `decompile/disasm 0x004a9cb0`. | Target Behavior/Reconstruction Notes; optional class/file wording | incorporate | applied: target Behavior/Reconstruction Notes and support rows use result/commit wording and explicitly avoid type `10` generalization. |
| C010 | `this-0xa0` is compiler secondary-view normalization and should be represented as ordinary `IMECompositionPane::OnKeyEvent`. | High | MCP disasm `add ecx, 0xffffff60`; decompile `this - 40`; sibling vtable/class docs. | Target Reconstruction Notes/formal C++ | incorporate | applied: target Behavior/Reconstruction Notes, class evidence, file evidence, and aggregate evidence record `this-0xa0`; formal C++ remains ordinary `IMECompositionPane::OnKeyEvent`. |
| C011 | InputMan, Event, Pane/EventHandler, no-code, and sibling-merge alternatives are rejected. | High | Negative evidence from xrefs/callees and current support docs. | Target Reconstruction Notes; report ledger | incorporate | applied: target Reconstruction Notes and support Changes preserve rejected alternatives. |
| C012 | Target should move to `88/91`, `EMITTER_UIDS:00006G`, with formal first-draft C++. | High | Score blocker resolved by exact MCP body, Event factory evidence, valid owner/emitter route. | Target metadata/formal C++; generated refresh checkpoint | incorporate | applied: validator `000000004097` reported `completion_update 88`, `confidence_update 91`, registry emitter `00006G`, and blank-to-block formal C++ update. |
| C013 | Support docs should be synchronized only for class/file/aggregate rows; Event/InputMan/SetCompositionString evidence is already present. | Medium-high | Current docs read and searched; no contradiction found. | `by-class/IMECompositionPane.md`, `by-file/IMEPanes.md`, [UID:000189]; already-present support notes | incorporate / already-present | applied/already-present: class/file/aggregate docs synchronized; SetCompositionString/Event/InputMan docs were not edited because callback read found no contradiction and goal treated them as already-present. |
| C014 | Generated `IMEPanes.cpp` should refresh after validators and include UID0004C4 `IMECompositionPane::OnKeyEvent`; no generated/manual coverage files should be edited by hand. | High | by-structure generated-output rules; current generated file lacks UID0004C4 because target is blank-emitter. | Validator/generation checkpoint | incorporate | applied: generated header is validator-command `000000004100`, timestamp `2026-07-01T17:45:51-04:00`; UID0004C4 block contains `bool IMECompositionPane::OnKeyEvent(const Event *event)` and no empty/non-emitting marker was found; generated/coverage files were validator-owned only. |

## Open Questions With Attempted Resolution

- Exact original Event union field names are not proven. Resolution: use source-facing inferred names `imeCompositionResultLength` and `imeCompositionResultText`, and preserve exact offset facts. This caps confidence but does not block C++.
- Whether type `13` should be called "commit" or "result" in public-facing docs. Resolution: current Event/InputMan docs use `DispatchCompositionResultEvent` and `GCS_RESULTSTR`; target should use result/commit wording, with "result" as the primary name.
- Whether `SetCompositionString` should receive type `10` composition text as well. Current target does not: MCP proves this handler guards only type `13`; type `10` is a separate Event text/composition update helper. Do not generalize this target beyond type `13`.
- No target-blocking open question remains.

## Validator Results

- Report-only pass: no validators were run and no target/support by-* docs were edited.
- Implementation callback validators run from `source-3/project-documentation`; all exited `0` with `ok: 1` and `generated_refresh: completed`.

> Executable block R001 was removed from this report and preserved verbatim in [0004C4-IMECompositionPaneOnKeyEvent-by-memory-source-quality-removed.md](0004C4-IMECompositionPaneOnKeyEvent-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Validator warnings observed were existing project-wide generated-report findings such as `autogen_children_fallback_insert`, `autogen_children_marker_missing`, and `autogen_emitter_has_no_code`; none blocked the four scoped docs.
- Generated freshness proof: `auto-generated/NexusTK/input/IMEPanes.cpp` header now records `validator-command-id: 000000004100`, `validator-refreshed-at: 2026-07-01T17:45:51-04:00`, and source UID `0000K5`. The file timestamp was `2026-07-01 17:45:56 -04:00`, and the UID0004C4 block contains `bool IMECompositionPane::OnKeyEvent(const Event *event)` with no empty/non-emitting marker.

## Changed Files

- Created earlier by report-only pass: `tools/leaser/Agents/Agent-B004/research/0004C4-IMECompositionPaneOnKeyEvent-by-memory-source-quality.md`.
- Manually modified under accepted callback scope:
  - `by-memory/0x004e7810-0x004e7838.IMECompositionPaneOnKeyEvent.md`
  - `by-class/IMECompositionPane.md`
  - `by-file/IMEPanes.md`
  - `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`
  - `tools/leaser/Agents/Agent-B004/research/0004C4-IMECompositionPaneOnKeyEvent-by-memory-source-quality.md`
- Validator-owned generated refresh observed, not manually edited: `auto-generated/NexusTK/input/IMEPanes.cpp` and validator-generated metadata/coverage reports reported by the scoped validators.
- Not manually edited: generated C++, generated reports, manual `-coverage-report.md` files, validator/tool state, IDA DB, executed archives, supervisor ledgers, queue files, lock files, and unrelated docs.
- Leases: B004 leased the four accepted by-* docs immediately before edits; all four lease requests succeeded. B004 released the same four docs immediately after the edit/validator/generated-check batch; all four unlease requests succeeded. Current lease report after release shows no B004 active leases.
- Report execution: implementation callback completed; supervisor owns any separate `execute_report` archival/ledger action.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation; proof: user/supervisor accepted the report for implementation on 2026-07-01.
- [x] Update target `by-memory/0x004e7810-0x004e7838.IMECompositionPaneOnKeyEvent.md` metadata to `88/91`, keep owner/reconstructable, set `EMITTER_UIDS:00006G`, leave optional position blank, and insert the exact formal `IMECompositionPane::OnKeyEvent` C++ block from this report; proof: validator `000000004097`.
- [x] Target body notes must preserve MCP session `supervisor_resume_20260629`, range size `0x28`, padding bytes, vtable xref `0x0061c444`, no direct callers, single callee [UID:00018A], Event type `13`, payload length/text offsets `+0x09/+0x0a`, Event factory `0x004a9cb0` support, and `this-0xa0` secondary-view normalization; proof: target Evidence/Behavior/Reconstruction Notes.
- [x] Update `by-class/IMECompositionPane.md` `OnKeyEvent` method row/evidence with UID0004C4 `88/91`, formal C++ populated, vtable slot `0x0061c444`, and result-text forwarding behavior; no class score change required; proof: validator `000000004098`.
- [x] Update `by-file/IMEPanes.md` to record UID0004C4 as an emitting composition-pane child routed through [UID:00006G] into `NexusTK/input/IMEPanes.cpp`; no file score change required; proof: validator `000000004099`.
- [x] Update `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md` UID0004C4 row with formal C++ populated, exact `0x28` size, type-13 result-text payload, and rejected no-code/sibling-merge alternatives; no aggregate score change required; proof: validator `000000004100`.
- [x] Treat `by-memory/0x004e7470-0x004e763c.IMECompositionSetCompositionString.md` as already-present support unless callback re-read finds drift; it already records the sole caller and payload offsets; proof: not edited, no contradiction found.
- [x] Treat Event/InputMan support docs as already-present for `DispatchCompositionResultEvent`, `GCS_RESULTSTR`, Event type `13`, and producer-side ownership unless callback re-read finds a contradiction; proof: not edited, no contradiction found.
- [x] Preserve rejected alternatives: InputMan direct owner, Event factory owner, generic Pane/EventHandler owner, no-code marker, merge with [UID:00018A], and aggregate-body rewrite; proof: target Reconstruction Notes and support Changes.
- [x] Run scoped validators listed in `Validator Results` with `--apply --wait-generated --queue-timeout 240` where generated `IMEPanes.cpp` freshness matters; proof: command IDs `000000004097` through `000000004100`.
- [x] Inspect generated `auto-generated/NexusTK/input/IMEPanes.cpp` header after final validator and confirm it is equal/newer than the final relevant command metadata and contains UID0004C4 `IMECompositionPane::OnKeyEvent`; proof: header command `000000004100`, refreshed at `2026-07-01T17:45:51-04:00`, file timestamp `2026-07-01 17:45:56 -04:00`, UID0004C4 block present.
- [x] Update this report's Claim And Incorporation Ledger and checklist to callback `applied`, `already-present`, `excluded-with-reason`, or `blocked` states with proof during implementation callback; proof: this section.
- [x] Do not manually edit generated files, generated reports, manual `-coverage-report.md` files, validator/tool state, IDA DB, executed archives, supervisor ledgers, queue files, lock files, or unrelated docs; proof: manual edits limited to accepted by-* docs plus this report, generated files validator-owned only.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] All accepted target/support doc details incorporated at report-level detail or explicitly excluded with reason; proof: no excluded accepted item remains.
- [x] Claim And Incorporation Ledger updated with callback verification states and proof.
- [x] Validators run and recorded with command ids, timestamps, exit codes, ok counts, warnings, and generated-refresh state.
- [x] Leases, if any, used only for immediate edit/validator batches and released immediately; proof: all four B004 unlease results succeeded and current lease report shows no B004 active leases.

Unchecked blockers: none for implementation callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/0004C4-IMECompositionPaneOnKeyEvent-by-memory-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B004/research/0004C4-IMECompositionPaneOnKeyEvent-by-memory-source-quality.md","timestamp":"2026-07-01T17:51:01","uid":"0004C4"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0004C4-IMECompositionPaneOnKeyEvent-by-memory-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/0004C4-IMECompositionPaneOnKeyEvent-by-memory-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0004C4"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
