** TARGET-REPORT-UID:0004CC **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | Medium **
# 0004CC IMEPane::SetFocusPane Source-Quality Report


## Finalized Report / Current Recommendation

- Current recommendation: convert [UID:0004CC] `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md` from blank-emitter split child to an emitting [UID:00006H] `IMEPane` method routed through [UID:0000K5] `IMEPanes`.
- Final disposition: source-authored `IMEPane::SetFocusPane(Pane *pane, bool focused)` method that removes an existing focus-list entry and conditionally appends the pane as the last focused text-entry pane.
- Required action after supervisor validation: update UID0004CC metadata/body, synchronize the [UID:00006H] declaration and concise support rows, then run scoped validation with generated refresh.
- Confidence: high. Exact original parameter spelling is inferred, but the two-argument ABI, caller polarity, owner, range, list API slots, and source-level body are directly supported.

## Target

- Target UID: `0004CC`.
- Target path: `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`.
- Queue row: `auto-generated/-ag-research-tracker.md` lists score `82/89`, combined `85.5`, reconstructable `true`, reports `0`.
- Current metadata: `CANONICAL_OWNER:00006H`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++.
- Current owner route: [UID:00006H] `IMEPane` -> [UID:0000K5] `IMEPanes`.

## Current Target State

The target page already has the correct exact range, direct owner, aggregate route, `g_pIMEPane` support, and four caller addresses. Its blocker is stale: it says formal C++ remains blank because no child-specific body was accepted when the split page was created. Current MCP evidence resolves that blocker.

Related docs checked: target page, [UID:00006H] `by-class/IMEPane.md`, [UID:0000K5] `by-file/IMEPanes.md`, [UID:000189] aggregate, [UID:0001PS] `g_pIMEPane` memory slot, [UID:0000R7] `g_pIMEPane`, [UID:000079] `List`, `auto-generated/-ag-research-tracker.md`, and generated `auto-generated/NexusTK/input/IMEPanes.cpp`.

## Evidence Checked

- IDA MCP session: `supervisor_resume_20260629`, via JSON-RPC `initialize`, `tools/list`, and narrow `tools/call` requests.
- MCP `idb_list`: one active IDB, `NexusTK.exe.i64`, worker pid `14860`, not analyzing.
- MCP `lookup_funcs` on `0x004e80a0`, `0x004e810b`, and caller sites: `0x004e80a0` is `sub_4E80A0`, size `0x6b`; `0x004e810b` is not a function; callers are in `sub_58DCE0`, `sub_58E140`, `sub_58EA80`, and `sub_595390`.
- MCP `decompile`, `disasm`, `analyze_function`, `callees`, `xrefs_to`, and `get_bytes` for UID0004CC.
- MCP decompile checks for callers `0x0058dce0`, `0x0058e140`, `0x0058ea80`, and `0x00595390`.
- MCP `xrefs_to 0x0069b458`: 17 singleton xrefs, including caller loads at `0x58e0d0`, `0x58e1ff`, `0x58ead2`, and `0x59545a`.
- Existing reports searched with `0004CC`, `0x004e80a0`, `0x004e810b`, `IMEPaneSetFocusPane`, `IMEPane::SetFocusPane`, `IMEPane`, and `IMEPanes`. Matching benchmark reports in `tools/leaser/Agents/SpecialReports/` were treated as unexecuted leads only. Executed B008 `0000K5-IMEPanes-empty-emitter-family-source-quality.md` was used only as split-history context.
- Generated output checked: `auto-generated/NexusTK/input/IMEPanes.cpp` currently has validator command id `000000004180`, refreshed `2026-07-02T04:19:57-04:00`, includes only `void SetFocusPane(Pane *pane);`, and has no UID0004CC body marker.

No MCP failures or timeouts occurred.

## IDA MCP Facts

- Function/range: `sub_4E80A0` is a modeled `.text` function at `0x004e80a0`, size `0x6b`, exactly covering `0x004e80a0-0x004e810b`.
- Boundary bytes: `0x004e8098-0x004e80a0` and `0x004e810b-0x004e8110` are `0xcc` padding. The adjacent [UID:00031G] raw focus-caret helper remains separate.
- Prototype shape: `void __thiscall(_DWORD *this, int, char)`, stack `arg_0` is four bytes and `arg_4` is one byte, epilogue `retn 8`.
- Body: reads `focusPaneCount` at `this+0x110`, scans backward through `focusPaneList` at `this+0x104`, calls List slot `+0x10` (`GetElementAt`), compares the stored `Pane *`, removes one matching entry through slot `+0x1c` (`RemoveAt`), then if the flag and pane pointer are nonzero appends one pointer through slot `+0x18` (`Append`).
- Callees: no direct named callees; the only calls are virtual List operations through the embedded list vtable.
- Xrefs: exactly four code callers: `0x58e0d9`, `0x58e20c`, `0x58ead9`, and `0x595463`.
- Caller polarity: `TextEditPane` construction calls `sub_4E80A0(g_pIMEPane, this, 1)` after `sub_544EA0(this, 1)` when focus registration is enabled; `TextEditPane` destruction calls `sub_4E80A0(g_pIMEPane, this, 0)` under a singleton guard; the text-edit active/editable setter calls the method with `1` for active/focused and `0` for inactive/unregistered; `TextBoxPane` construction calls `sub_4E80A0(g_pIMEPane, this, 0)` after setting the editor flag.

## Positive Evidence Summary

- Direct binary facts prove a normal modeled function, not a raw orphan helper.
- Existing class/file docs already define `IMEPane::SetFocusPane`, `focusPaneList +0x104`, and `focusPaneCount +0x110`.
- [UID:000079] `List` documents the exact virtual API names matching the slots used here: `GetElementAt`, `Append`, and `RemoveAt`.
- `g_pIMEPane` docs and MCP xrefs show text-entry controls use the singleton to reach this method, while the method itself mutates only root IME pane focus-list state.
- The body is simple enough for human-written first-draft source without unresolved helper, protocol, allocation, string, or geometry dependencies.

## Negative Evidence Summary

- No evidence supports retaining no-code: unlike adjacent [UID:00031G], UID0004CC is an IDA-modeled function with four direct callers.
- No evidence supports direct `TextEditPane` or `TextBoxPane` ownership. They are callers that register/unregister themselves; they do not own the root focus list storage.
- No evidence supports `InputMan` ownership. InputMan owns Win32/IMM event production, while this method mutates pane-side focus state.
- No evidence supports aggregate-only emission. [UID:000189] is a `[[CHILDREN]]` source-order container; exact child method pages own method bodies.
- The one-argument class declaration `void SetFocusPane(Pane *pane);` is stale/incomplete because the binary consumes two explicit arguments.

## Heuristic / Inference Reanalysis And Validation

The best source-facing signature is `void IMEPane::SetFocusPane(Pane *pane, bool focused)`.

The `Pane *pane` argument is direct from caller setup: all four call paths pass `this` from text-entry pane objects. The `bool focused` spelling is inferred, not recovered from symbols, but caller polarity validates it: register/active paths pass `1`, teardown/inactive paths pass `0`. `makeActive` and `addToFocusList` were considered. `makeActive` overstates the method because it does not directly manipulate focus on the pane object; it only maintains the IME root's ordered focus list. `addToFocusList` is behaviorally accurate but less natural at the public method call sites. `focused` is the most source-like current name.

The source body should remove before append. That is not just deduplication polish; it is the observed binary order and preserves "last focused pane wins" behavior. Scanning backward is source-plausible because the list is small and ordered by focus recency. Appending `&pane` rather than `pane` matches the accepted `List::Append(int count, void *source)` API, which copies one fixed-width element from caller memory.

The current generated `IMEPanes.cpp` class shell has `List focusPaneList` and `int focusPaneCount`, but no method body. After callback validation the generated output should contain the UID0004CC body through [UID:00006H], and the class declaration should include the boolean argument.

No Wave2/Wave3 material was used as authority. Historical benchmark and generated text were leads only and were rechecked against current docs and MCP.

## Ranked Ownership Analysis

### 1. [UID:00006H] `IMEPane`

- Evidence for: method mutates `IMEPane` fields `focusPaneList +0x104` and `focusPaneCount +0x110`; existing class declaration names the method; `g_pIMEPane` callers pass the singleton as `this`; source file route [UID:00006H] -> [UID:0000K5] is already established.
- Evidence against: exact original parameter spelling is inferred.
- Decision: direct owner and direct emitter.

### 2. [UID:0000K5] `IMEPanes`

- Evidence for: owns the pane-side IME module and generated `NexusTK/input/IMEPanes.cpp`.
- Evidence against: file page is a source module route, not the method/class owner.
- Decision: keep as emitter route through [UID:00006H], not direct canonical owner.

### 3. `TextEditPane` / `TextBoxPane`

- Evidence for: all code callers are text-entry controls.
- Evidence against: they pass their own `this` as the pane argument and access the root singleton as callee object; storage mutated is inside `IMEPane`.
- Decision: caller families only; reject direct ownership.

### 4. `InputMan` or [UID:000189] aggregate

- Evidence for: same broad subsystem neighborhood.
- Evidence against: InputMan has no focus-list storage and owns event production, not pane-side focus registration; aggregate is a child container and should not absorb exact bodies.
- Decision: reject.

## Source Placement

Recommended placement: [UID:00006H] `IMEPane` method emitted through [UID:0000K5] `NexusTK/input/IMEPanes.cpp`. The target by-memory page should carry the formal method body. [UID:00006H] should update the declaration to `void SetFocusPane(Pane *pane, bool focused);`. [UID:000189] should remain a `[[CHILDREN]]` aggregate and mention UID0004CC as emitting once accepted.

## Range / Split / Padding / Reclassification Analysis

No split is required. UID0004CC is exactly `0x004e80a0-0x004e810b`; MCP confirms `0x004e810b` is not a function and the next bytes through `0x004e8110` are padding. Adjacent [UID:00031G] is a separate raw no-code focus-caret helper and must not be merged into this method.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0004CC is a modeled function at `0x004e80a0`, size `0x6b`, exact end `0x004e810b`. | High | MCP `lookup_funcs`, `disasm`, `get_bytes` | UID0004CC Status/Evidence | incorporate | applied - target Status/Evidence records modeled `0x6b` body and exact range. |
| C02 | The method has exactly four direct code callers from text edit/self-save/text-box focus paths. | High | MCP `xrefs_to 0x004e80a0`; caller decompiles | UID0004CC Evidence | incorporate | applied - target Evidence lists all four caller sites and caller families. |
| C03 | Signature should be `void IMEPane::SetFocusPane(Pane *pane, bool focused)`. | High | MCP prototype, `retn 8`, caller polarity | UID0004CC C++; [UID:00006H] declaration | incorporate | applied - target C++ and [UID:00006H] class shell use the two-argument signature. |
| C04 | The body removes any existing matching pane entry before optional append. | High | MCP decompile/disasm | UID0004CC Behavior/C++ | incorporate | applied - target Behavior and formal C++ preserve remove-before-append behavior. |
| C05 | The body uses `List::GetElementAt`, `List::RemoveAt`, and `List::Append` over `focusPaneList`. | High | MCP slot offsets; [UID:000079] List API | UID0004CC Reconstruction Notes/C++ | incorporate | applied - target Evidence/Reconstruction Notes and C++ use accepted List API names. |
| C06 | Direct owner is [UID:00006H] and file route is [UID:0000K5]. | High | Current docs; root field mutation; caller singleton route | UID0004CC metadata/support docs | incorporate | applied - target metadata sets `EMITTER_UIDS:00006H`; target/class/file/aggregate route through IMEPane into IMEPanes. |
| C07 | TextEditPane, TextBoxPane, InputMan, and aggregate-only ownership are rejected. | High | Caller/state direction; docs | UID0004CC Negative Evidence/Ownership | incorporate | applied - target Reconstruction Notes preserve rejected alternatives; support pages route only through IMEPane/IMEPanes. |
| C08 | Adjacent [UID:00031G] remains separate and no merge/split repair is needed. | High | Padding and not-a-function endpoint; existing raw-helper page | UID0004CC Range notes; aggregate row | incorporate | applied - target and aggregate preserve padding/UID00031G separation. |
| C09 | Score should move to `89/91`; not higher because parameter names and exact original helper spellings remain inferred. | Medium-high | Current MCP and support docs | UID0004CC Score Rationale | incorporate | applied - target metadata and Score Rationale updated; validator command `000000004186` confirmed completion/confidence updates. |
| C10 | Generated output should gain a UID0004CC body after validator refresh; generated files must not be edited manually. | High | Current generated absence; by-structure rules | Checklist/generated expectation | incorporate | applied - validator-owned generated refresh command `000000004190` updated `auto-generated/NexusTK/input/IMEPanes.cpp` with UID0004CC body and two-argument declaration. |

## First-Draft C++ Recommendation

Eligible for draft C++: yes. This is a source-authored, modeled `IMEPane` method with accepted owner, support fields, and List API names.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
void IMEPane::SetFocusPane(Pane *pane, bool focused)
{
    for (int index = focusPaneCount - 1; index >= 0; --index) {
        Pane **entry = static_cast<Pane **>(focusPaneList.GetElementAt(index));
        if (*entry == pane) {
            focusPaneList.RemoveAt(index, 1);
            break;
        }
    }

    if (focused && pane != NULL) {
        focusPaneList.Append(1, &pane);
    }
}
```

Reason it preserves behavior: it matches the binary's backward scan, one-entry removal, flag and non-null guard, and one-entry append from the stack argument.

Reason it matches plausible source: it uses the accepted `List` API and `IMEPane` fields rather than decompiler `_DWORD` indexing, vtable-slot calls, or raw addresses. The only inferred spelling is the boolean parameter name `focused`.

## Score And Metadata Recommendation

- Current: `COMPLETION:82`, `CONFIDENCE:89`, `CANONICAL_OWNER:00006H`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++.
- Recommended: `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:00006H`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006H`, blank/unchanged `EMITTER_POSITION_OPTIONAL`, formal C++ populated as above.
- Reason not lower: MCP resolves the method body, range, callers, argument polarity, List API, and owner route.
- Reason not higher: exact original parameter spelling and final class-wide source style remain inferred, and support generated output has not yet refreshed.

## Recommended Target Doc Changes

Target path: `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`.

Recommended changes after supervisor validation:

- Set metadata to `COMPLETION:89`, `CONFIDENCE:91`, `EMITTER_UIDS:00006H`.
- Replace blank formal C++ with the exact `IMEPane::SetFocusPane(Pane *pane, bool focused)` block above.
- Update Behavior/Evidence/Reconstruction Notes to preserve the MCP facts: range, padding, four callers, backward de-dup scan, List API slots, caller flag polarity, and rejected no-code/alternate-owner alternatives.
- Update Item Summary to mention formal C++ populated and remove stale "blank until child-specific C++ is accepted" wording.

## Recommended Support Doc Changes

- [UID:00006H] `by-class/IMEPane.md`: update declaration to `void SetFocusPane(Pane *pane, bool focused);`; update method row to link [UID:0004CC], score `89/91`, formal C++ populated, removes existing focus entry and conditionally appends the focused pane.
- [UID:0000K5] `by-file/IMEPanes.md`: update proposed contents/evidence/change notes to include UID0004CC as an emitting `IMEPane` method routed into `NexusTK/input/IMEPanes.cpp`.
- [UID:000189] aggregate: update covered-range/source-placement row to show UID0004CC `89/91`, formal C++ populated, and preserve aggregate `[[CHILDREN]]`.
- [UID:0001PS] and [UID:0000R7] already contain same-or-greater singleton/four-caller support. Optional concise note may record the second argument as `focused`; no metadata change required.
- [UID:000079] `List` already contains same-or-greater API evidence; no edit required.

## Open Questions With Attempted Resolution

- Exact original boolean parameter name: unresolved. Checked caller polarity, benchmark leads, class/file docs, and MCP; no symbol proof exists. `focused` is the best current inferred source-facing name and does not block first-draft C++.
- Exact `Pane *` subtype: resolved as source-level `Pane *`, not `TextEditPane *` or `TextBoxPane *`, because both text-edit and text-box families call the method and the root focus list stores generic pane pointers.
- Whether no-code remains correct: resolved no. The rare no-code exception fails because this is a modeled function with direct callers and a complete source-shaped body.

## Validator Results

Implementation callback validators:

> Executable block R001 was removed from this report and preserved verbatim in [0004CC-IMEPaneSetFocusPane-by-memory-source-quality-removed.md](0004CC-IMEPaneSetFocusPane-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Result: exit code `0`, `command_id: 000000004186`, `command_timestamp: 2026-07-02T04:28:26-04:00`, `ok: 1`, `generated_refresh: completed`.
- Target-specific updates reported: completion `89`, confidence `91`, emitter registry `00006H`, formal C++ block hash, target UID links/reference-index additions, generated `auto-generated/NexusTK/input/IMEPanes.cpp` update, generated by-memory coverage update, research tracker update, and projected stats update.

> Executable block R002 was removed from this report and preserved verbatim in [0004CC-IMEPaneSetFocusPane-by-memory-source-quality-removed.md](0004CC-IMEPaneSetFocusPane-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Result: exit code `0`, `command_id: 000000004187`, `command_timestamp: 2026-07-02T04:28:46-04:00`, `ok: 1`, `generated_refresh: deferred`.

> Executable block R003 was removed from this report and preserved verbatim in [0004CC-IMEPaneSetFocusPane-by-memory-source-quality-removed.md](0004CC-IMEPaneSetFocusPane-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Result: exit code `0`, `command_id: 000000004188`, `command_timestamp: 2026-07-02T04:28:51-04:00`, `ok: 1`, `generated_refresh: deferred`.

> Executable block R004 was removed from this report and preserved verbatim in [0004CC-IMEPaneSetFocusPane-by-memory-source-quality-removed.md](0004CC-IMEPaneSetFocusPane-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Result: exit code `0`, `command_id: 000000004189`, `command_timestamp: 2026-07-02T04:29:01-04:00`, `ok: 1`, `generated_refresh: deferred`.

> Executable block R005 was removed from this report and preserved verbatim in [0004CC-IMEPaneSetFocusPane-by-memory-source-quality-removed.md](0004CC-IMEPaneSetFocusPane-by-memory-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

- Result: exit code `0`, `command_id: 000000004190`, `command_timestamp: 2026-07-02T04:29:19-04:00`, `ok: 1`, `generated_refresh: completed`.
- Generated freshness: `auto-generated/NexusTK/input/IMEPanes.cpp` header now has `validator-command-id: 000000004190` and `validator-refreshed-at: 2026-07-02T04:29:19-04:00`, equal to the final wait-generated command. The file contains `void SetFocusPane(Pane *pane, bool focused);` and the UID0004CC formal method body.

## Changed Files

- Modified by B006 implementation callback:
  - `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`
  - `by-class/IMEPane.md`
  - `by-file/IMEPanes.md`
  - `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`
  - `tools/leaser/Agents/Agent-B006/research/0004CC-IMEPaneSetFocusPane-by-memory-source-quality.md`
- Validator-owned generated/tool-state side effects from scoped validation: generated `auto-generated/NexusTK/input/IMEPanes.cpp`, generated reports/tracker/projected stats, validator registry metadata, and autogen backups were updated by `tools/validator.py`; none were edited manually.
- Leases: B006 leased the four approved by-* docs at `2026-07-02T08:26:07Z`, validated while leases were active, then released all four leases immediately after validation. No lease was needed for this report.

## Implementation Tracking Checklist

Implementation callback pass:

- [x] Supervisor validation required before implementation. Applied after supervisor accepted this report for implementation callback.
- [x] Update target doc `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`. Target metadata/body/evidence/rejected alternatives updated.
- [x] Set UID0004CC metadata to `COMPLETION:89`, `CONFIDENCE:91`, `EMITTER_UIDS:00006H`, preserving owner `00006H` and reconstructable `TRUE`. Validator command `000000004186` confirmed completion/confidence and registry updates.
- [x] Insert exact formal `IMEPane::SetFocusPane(Pane *pane, bool focused)` C++ block from this report into the target formal C++ block. Applied exactly to target and visible in generated `IMEPanes.cpp`.
- [x] Incorporate target evidence for exact range, padding, four callers, caller polarity, List slot/API mapping, backward removal, optional append, and rejected alternatives. Applied in target Status/Behavior/Evidence/Reconstruction Notes/Score/Changes.
- [x] Update [UID:00006H] `IMEPane` declaration and method note for the two-argument signature and emitting child status. Applied in class shell, method row, Evidence Notes, and Changes.
- [x] Update [UID:0000K5] `IMEPanes` proposed contents/evidence/change note for UID0004CC as an emitting `IMEPane` child. Applied in Proposed Contents, Evidence Notes, and Changes.
- [x] Update [UID:000189] aggregate covered-range/source-placement row for UID0004CC `89/91` and formal C++ populated; preserve aggregate `[[CHILDREN]]`. Applied in Covered Ranges, Evidence Notes, split/source-placement row, and Changes; aggregate C++ marker unchanged.
- [x] Confirm [UID:0001PS], [UID:0000R7], and [UID:000079] are already present at same-or-greater detail or add only concise optional support note if supervisor wants synchronization. Confirmed already-present: singleton docs already contain four caller/singleton route evidence, and `List` already documents `GetElementAt`, `RemoveAt`, and `Append`; no extra edits needed.
- [x] Preserve rejected alternatives: no-code, TextEditPane/TextBoxPane/InputMan ownership, direct-file-only ownership, aggregate-only emission, and merge with [UID:00031G]. Applied to target and support notes.
- [x] Run scoped validator after accepted implementation with `--wait-generated`. Target validator `000000004186` and final file-route validator `000000004190` both completed with `generated_refresh: completed`.
- [x] Confirm generated `auto-generated/NexusTK/input/IMEPanes.cpp` refresh has UID0004CC body and updated declaration; do not edit generated files manually. Confirmed header `validator-command-id: 000000004190`, declaration line `void SetFocusPane(Pane *pane, bool focused);`, and UID0004CC method body present.
- [x] Claim And Incorporation Ledger updated with destination and verification state for every accepted claim during callback. Ledger rows C01-C10 updated to applied with proof.

Unapplied accepted items: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004194","destination_path":"executed-b-agent-research/B006/0004CC-IMEPaneSetFocusPane-by-memory-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0004CC-IMEPaneSetFocusPane-by-memory-source-quality.md","timestamp":"2026-07-02T04:31:55-04:00","uid":"0004CC"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0004CC-IMEPaneSetFocusPane-by-memory-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0004CC-IMEPaneSetFocusPane-by-memory-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0004CC"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
