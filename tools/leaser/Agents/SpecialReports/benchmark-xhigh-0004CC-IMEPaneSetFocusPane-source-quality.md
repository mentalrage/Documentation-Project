** TARGET-REPORT-UID:0004CC **
** AUTHOR-AGENT-ID:BENCH-XHIGH **
** BENCHMARK-REASONING:xhigh **

# UID0004CC IMEPane::SetFocusPane Source-Quality Report

## Final Recommendation

[UID:0004CC] `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md` should no longer remain a blank non-emitting child. Current IDA MCP proves this is a modeled source-authored `IMEPane` method with four direct text-entry callers, a stable exact range, no outside callee dependencies, and a simple source-level body over the already accepted `List` API and `IMEPane` focus-list fields.

Recommended implementation:

- Change `COMPLETION:82` to `COMPLETION:89`.
- Change `CONFIDENCE:89` to `CONFIDENCE:91`.
- Keep `CANONICAL_OWNER:00006H`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Set `EMITTER_UIDS:00006H`.
- Keep `EMITTER_POSITION_OPTIONAL:` blank.
- Populate formal `RECONSTRUCTION_CPP CODE` with `void IMEPane::SetFocusPane(Pane *pane, bool focused)`.
- Update [UID:00006H] `IMEPane` class shell from `void SetFocusPane(Pane *pane);` to `void SetFocusPane(Pane *pane, bool focused);`.

This is not a no-code case. The rare no-code proof used for adjacent [UID:00031G] does not apply: `0x004e80a0` is a real IDA function start, has four direct code xrefs, and has a complete source-shaped body.

## Current Target State

- Target path: `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`.
- Current metadata: `COMPLETION:82`, `CONFIDENCE:89`, `CANONICAL_OWNER:00006H`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank formal C++.
- Current summary: exact `IMEPane::SetFocusPane` split child maintaining `focusPaneList` / `focusPaneCount` for text controls and self-save/text-box focus registration.
- Current queue source: `auto-generated/-ag-research-tracker.md` -> `## by-memory` -> `### Not-Covered Files - Reconstructable`.
- Current queue row: [UID:0004CC] score `82/89`, combined `85.5`, reconstructable `true`, reports `0`, path `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`.
- Generated coverage row: `auto-generated/-ag-coverage-report-by-memory.md` currently reports `emits_code:false` for UID0004CC.
- Direct owner: [UID:00006H] `by-class/IMEPane.md`, currently `88/91`, emits through [UID:0000K5] `by-file/IMEPanes.md`.
- Source file route: [UID:00006H] `IMEPane` -> [UID:0000K5] `IMEPanes` / `NexusTK/input/IMEPanes.cpp`.
- Containing aggregate: [UID:000189] `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`, currently `87/90` with aggregate `[[CHILDREN]]`.

## Evidence Checked

### Current Docs And Generated Lead Material

- Read assigned target [UID:0004CC] `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`.
- Read [UID:00006H] `by-class/IMEPane.md`; it already documents `focusPaneList +0x104`, `focusPaneCount +0x110`, `focusCaretAnchorY +0x118`, `focusCaretAnchorX +0x11c`, and the source route through [UID:0000K5].
- Read [UID:0000K5] `by-file/IMEPanes.md`; it identifies `IMEPane::SetFocusPane` as an `IMEPane` root method in `IMEPanes.cpp`.
- Read [UID:000189] aggregate `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`; it lists UID0004CC as exact child route [UID:00006H] -> [UID:0000K5].
- Read [UID:00031G] `IMEPaneFocusCaretAnchorHelper` to compare the adjacent no-code raw-helper case.
- Read [UID:0001PS] `0x0069b458-0x0069b45c.g_pIMEPane.md`; it records the four direct UID0004CC callers and the IME singleton route.
- Read [UID:0002ZY] `TextEditPaneConstructor`, [UID:0002ZZ] `TextEditPaneDestructor`, and [UID:0002RV] `TextBoxPaneConstructor` as caller/support evidence.
- Read [UID:00018A] `IMECompositionPane::SetCompositionString` as field-name support for `focusPaneList`, `focusPaneCount`, and root focus-caret fields.
- Read [UID:000079] `List` and [UID:0000KS] `List` to verify accepted source-facing container method names: `GetElementAt`, `Append`, and `RemoveAt`.
- Read `by-structure.md` reconstruction metadata and C++ emitter gate sections. UID0004CC already has combined score over 85; with emitter route [UID:00006H] and source-quality body proof, it is eligible for formal C++.
- Read `auto-generated/-ag-research-tracker.md` target row and `auto-generated/-ag-coverage-report-by-memory.md` generated coverage row as read-only state.

### Existing Report Search

Search terms used: `0004CC`, `0x004e80a0`, `0x004e810b`, `IMEPaneSetFocusPane`, `SetFocusPane`, `IMEPane`, `IMEPanes`, `focusPaneList`, and `focusPaneCount`.

Relevant matching report leads opened:

- `executed-b-agent-research/B008/0000K5-IMEPanes-empty-emitter-family-source-quality.md`: created UID0004CC as an exact split child but intentionally left child-specific C++ to a later pass.
- `executed-b-agent-research/B003/00018A-ime-composition-set-composition-string-source-quality.md`: resolved root `IMEPane` focus-list/count and focus-caret fields and used the same accepted field names in formal C++.
- `executed-b-agent-research/B008/0002RV-TextBoxPaneConstructor-source-quality.md`: records `g_pIMEPane->SetFocusPane(this, false)` in accepted TextBox constructor C++.
- `executed-b-agent-research/B004/0001JO-TextBoxPane-source-quality.md`: supports TextBox focus-registration use.
- `executed-b-agent-research/B010/0004CE-IMEPaneHandleIMEMessage-source-quality.md`: confirms [UID:00006H] is an emitting IMEPane class route through [UID:0000K5].

No target-specific executed report for UID0004CC was found. The current report is the child-specific source-quality pass that B008 deferred.

### IDA MCP Session And Provenance

MCP endpoint used: `http://127.0.0.1:13337/mcp`.

- JSON-RPC `initialize` request id `1`: returned `ida-pro-mcp`, protocol `2025-06-18`.
- `tools/list` request ids `2` through `4`: current schemas checked before using `tools/call`.
- `idb_list` request id `5`: one active session, `session_id:"supervisor_resume_20260629"`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_analyzing:false`, worker pid `14860`, active/adopted/owned.
- `server_health` request id `6`: `status:"ok"`, module `NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, strings cache size `2067`.

Focused MCP calls:

| Request | Tool | Result |
| --- | --- | --- |
| `7` | `lookup_funcs` on `0x004e8098`, `0x004e80a0`, `0x004e810b`, `0x004e8110`, `0x004e8192`, `0x004e81a0` | `0x004e80a0` is `sub_4E80A0`, size `0x6b`; predecessor/end/adjacent raw helper boundaries are not function starts; `0x004e81a0` is `sub_4E81A0`, size `0x5`. |
| `8` | `xrefs_to 0x004e80a0` | Four code xrefs: `0x58e0d9` in `sub_58DCE0`, `0x58e20c` in `sub_58E140`, `0x58ead9` in `sub_58EA80`, and `0x595463` in `sub_595390`; no more xrefs. |
| `9` | `callees 0x004e80a0` | No direct named callees; list operations are virtual calls through the embedded `List` vtable. |
| `10` | `analyze_function 0x004e80a0` | Prototype `void __thiscall(_DWORD *this, int, char)`, size `107`, 11 basic blocks, cyclomatic complexity `6`, callers `sub_58DCE0`, `sub_58E140`, `sub_58EA80`, `sub_595390`. Decompile scans `this[68] - 1`, uses List slot `+0x10` to fetch entries, List slot `+0x1c` to remove one entry, then conditionally uses List slot `+0x18` to append one pointer when the third argument is nonzero and the pane pointer is non-null. |
| `26` | `decompile 0x0058dce0` excerpt | TextEdit constructor path calls `sub_544EA0(this, 1)` then `sub_4E80A0(g_pIMEPane, this, 1)` when focus registration is enabled. |
| `27` | `decompile 0x0058e140` excerpt | TextEdit destructor calls `sub_4E80A0(g_pIMEPane, this, 0)` when `g_pIMEPane` exists. |
| `28` | `decompile 0x0058ea80` excerpt | TextEdit focus toggle calls `sub_4E80A0(..., this, 0)` in the unregister path and `sub_4E80A0(..., this, 1)` in the register/focused path. |
| `29` | `decompile 0x00595390` excerpt | TextBox constructor calls `sub_544EA0(this, 0)` and `sub_4E80A0(g_pIMEPane, this, 0)` after setting the text-editor flag. |
| `30` | `disasm 0x004e80a0` | 39 instructions. Reads `[ebx+0x110]`, scans backwards, calls `[focusPaneList vtable +0x10]`, compares the stored `Pane *`, calls `[+0x1c]` with `(index,1)` to remove, then if `arg_4` and `arg_0` are nonzero calls `[+0x18]` with `(1,&arg_0)` to append one pointer. Stack frame has `arg_0` 4 bytes and `arg_4` 1 byte; function returns `retn 8`. |
| `31`/`33` | `get_bytes` around boundaries | `0x004e8098` has eight `0xcc` bytes before the function; `0x004e810b` has five `0xcc` bytes before the raw focus-anchor helper. |
| `32` | `xrefs_to 0x0069b458` | 17 singleton data xrefs, including caller loads at `0x58e0d0`, `0x58e1ff`, `0x58ead2`, and `0x59545a`, matching the four UID0004CC call sites. |

No MCP requests failed. No fallback-only evidence was used. No IDA-mutating tools were called.

## Positive Evidence

- Direct IDA fact: `0x004e80a0` is a modeled function start with size `0x6b`; it exactly matches the target half-open range `0x004e80a0-0x004e810b`.
- Direct IDA fact: the function has four code xrefs from text-entry construction/destruction/focus-toggle/TextBox construction paths. This proves live reachability and rejects a no-code/unused-helper disposition.
- Direct IDA fact: the function takes two stack arguments after `this`, not one: a pane pointer and a one-byte boolean flag. The current [UID:00006H] declaration is therefore incomplete.
- Direct IDA fact: the function's body uses only the embedded focus list at complete `IMEPane +0x104` and count at `+0x110`; there are no external callee blockers.
- Documentation evidence: [UID:00006H], [UID:00018A], and [UID:00031G] already resolve `focusPaneList`, `focusPaneCount`, `focusCaretAnchorY`, and `focusCaretAnchorX`.
- Documentation evidence: [UID:000079] `List` provides accepted source-facing methods matching the target vtable slots: `GetElementAt` (`+0x10`), `Append` (`+0x18`), and `RemoveAt` (`+0x1c`).
- Source-shape inference: the body first removes any existing instance of `pane` to avoid duplicates, then appends the pane only when `focused` is true. This exactly matches caller polarity: construction/focus registration passes `1`; destructor/unregister paths pass `0`.
- Source route evidence: [UID:00006H] already emits through [UID:0000K5] and sibling UID0004CE uses the same `EMITTER_UIDS:00006H` route for formal `IMEPane` method C++.

## Negative Evidence

- No evidence supports leaving `EMITTER_UIDS` blank. The direct class owner [UID:00006H] and source file [UID:0000K5] both clear the gate, the target's combined score is already over 85, and the body has a stable source route.
- No evidence supports no-code. Unlike [UID:00031G], UID0004CC is an IDA-modeled function and has four direct xrefs.
- No evidence supports `TextEditPane` or `TextBoxPane` as direct owner. Those classes call the method to register/unregister themselves; the state mutated is root `IMEPane` state.
- No evidence supports `InputMan` ownership. `InputMan` produces IME events, while this method manages the pane-side focus list used by composition/candidate placement.
- No evidence supports direct by-file ownership [UID:0000K5] over class ownership. The function uses `this` as an `IMEPane` object and mutates IMEPane fields; [UID:0000K5] is only the final source-file route.
- No evidence supports merging UID0004CC into the aggregate [UID:000189]. The aggregate uses `[[CHILDREN]]`; exact method children own their bodies.
- No target-specific blocker remains for helper/list method names. The shared `List` class now has accepted names and formal method declarations.

## Heuristic / Inference Reanalysis And Validation

The old blank-emitter state was justified when UID0004CC had only just been created as a split child and no child-specific body report had been accepted. It is no longer justified after current MCP and support-doc reanalysis.

Key source-quality decisions:

- Method signature: `void IMEPane::SetFocusPane(Pane *pane, bool focused)`. IDA proves a `Pane *`-like pointer argument plus a one-byte flag. `focused` is the best current source-facing name because callers pass `1` on focus registration and `0` on destructor/unregister paths. `addToFocusList` is also behaviorally accurate but less source-like for the public method call sites.
- De-duplication behavior: the backward scan over `focusPaneCount - 1` down to zero removes the first matching stored `Pane *`. This preserves list uniqueness and lets a later focused append move the pane to the end of the list.
- List API names: use `List::GetElementAt`, `List::RemoveAt`, and `List::Append`, not raw vtable-slot labels or stale `GetAt` wording. These names are current accepted source API on [UID:000079].
- Count access: use `focusPaneCount` because [UID:00006H], [UID:00018A], and [UID:00031G] already document `IMEPane +0x110` with that source-facing role. The binary reads it directly as the list count.
- Formal body readiness: no string, packet, external helper, virtual dispatch target, or unresolved class hierarchy question remains inside this body. The only inferred names are already project-accepted `Pane`, `List`, `focusPaneList`, `focusPaneCount`, and `focused`.

Rejected alternatives:

- `void SetFocusPane(Pane *pane)` is rejected because all current callers and the target stack frame prove a second argument.
- `void SetFocusPane(Pane *pane, int mode)` is weaker than `bool focused`; the only observed values are `0` and `1`, and the branch treats it as boolean.
- `RegisterFocusPane` / `UnregisterFocusPane` split functions are rejected because one binary function handles both by boolean flag.
- Emitting raw `sub_4E80A0` or decompiler-shaped list vtable calls is rejected because [UID:000079] supplies source-facing `List` methods.
- Keeping no-code until exact original spellings are proven is rejected by the score-blocker standard. The remaining names are behaviorally validated and consistent with accepted adjacent C++.

## Ranked Owner / Source Placement Disposition

1. [UID:00006H] `IMEPane` -> [UID:0000K5] `IMEPanes`: selected.
   - Evidence for: `this` is the root `IMEPane`; the body mutates `focusPaneList +0x104` and `focusPaneCount +0x110`; callers pass text-entry panes into the singleton root; [UID:00006H] already emits through [UID:0000K5].
   - Evidence against: exact original parameter spelling is not symbol-proven. This is only a confidence cap, not an ownership blocker.
   - Decision: direct owner and emitter should be [UID:00006H].

2. [UID:0000K5] `IMEPanes` direct file owner: rejected as too broad.
   - Evidence for: final source file route is `NexusTK/input/IMEPanes.cpp`.
   - Evidence against: the method is class-owned and uses `IMEPane` object state.
   - Decision: keep as source route only through class emitter.

3. [UID:0000ON] `TextEditPane` / [UID:0000OJ] `TextBoxPane`: rejected caller ownership.
   - Evidence for: all direct code callers are text-entry paths.
   - Evidence against: they are consumers that register/unregister themselves; they do not own the root focus-list storage.
   - Decision: support/caller docs only.

4. [UID:0000K6] `InputMan`: rejected dependency/subsystem producer ownership.
   - Evidence for: IME events originate from input handling elsewhere.
   - Evidence against: UID0004CC contains no IMM/Event producer logic and mutates pane-side UI state.
   - Decision: not owner or emitter.

5. No-code/no-owner/non-emitting: rejected.
   - Evidence against: modeled function, four xrefs, exact body, class route, and formal C++ readiness.

## Score And Metadata Disposition

Current metadata:

```text
COMPLETION:82
CONFIDENCE:89
CANONICAL_OWNER:00006H
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:
EMITTER_POSITION_OPTIONAL:
formal C++ blank
```

Recommended metadata:

```text
COMPLETION:89
CONFIDENCE:91
CANONICAL_OWNER:00006H
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:00006H
EMITTER_POSITION_OPTIONAL:
formal C++ populated
```

Rationale:

- Completion can rise to `89` because exact range, padding, xrefs, caller polarity, body semantics, source owner, emitter route, formal C++ body, support-field names, and rejected alternatives are now documented.
- Confidence can rise to `91` because current MCP directly proves the boundary, signature shape, four callers, no external callees, instruction-level list operations, and boundary padding. It should stay below final-audit range because exact original parameter spelling and public API naming remain inferred/descriptive rather than symbol-proven.
- `EMITTER_UIDS:00006H` is now safe because [UID:00006H] emits to [UID:0000K5], sibling UID0004CE already uses that route, and the class/page scores clear the current by-structure gate.

## First-Draft C++ Recommendation

Eligible for draft C++: yes.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for [UID:0004CC]:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void IMEPane::SetFocusPane(Pane *pane, bool focused)
{
    for (int index = focusPaneCount - 1; index >= 0; --index) {
        Pane *registeredPane =
            *static_cast<Pane **>(focusPaneList.GetElementAt(index));
        if (registeredPane == pane) {
            focusPaneList.RemoveAt(index, 1);
            break;
        }
    }

    if (focused && pane != NULL) {
        focusPaneList.Append(1, &pane);
    }
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Why this preserves behavior:

- `focusPaneCount - 1` and backward loop match `mov esi, [ebx+110h]` / `sub esi, 1` / decrement loop.
- `focusPaneList.GetElementAt(index)` matches List vtable slot `+0x10` followed by dereferencing the stored pointer.
- `RemoveAt(index, 1)` matches List vtable slot `+0x1c` with pushes `1` and `index`.
- `focused && pane != NULL` matches the checks at `0x004e80e4` and `0x004e80ea`.
- `Append(1, &pane)` matches List vtable slot `+0x18` with count `1` and address of the stack pointer argument.

No-code proof: not applicable. The no-code branch is explicitly rejected above.

## Implementation-Ready Target / Support Doc Changes

### Target [UID:0004CC]

Path: `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`

Required changes:

- Set metadata to `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:00006H`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006H`, blank `EMITTER_POSITION_OPTIONAL`.
- Insert the exact formal C++ block above.
- Update Status to say formal C++ is populated and emits through [UID:00006H] into [UID:0000K5].
- Update Behavior to record the two-argument method shape: removes any existing `pane`, then appends it only when `focused` is true and `pane` is non-null.
- Add Evidence rows for MCP request ids `7` through `10`, `26` through `33`.
- Add caller polarity table:
  - `0x0058e0d9`: TextEdit constructor/register path passes `1`.
  - `0x0058e20c`: TextEdit destructor/unregister path passes `0`.
  - `0x0058eac5` / `0x0058ead9`: TextEdit focus toggle passes `1` or `0` by state.
  - `0x00595463`: TextBox constructor passes `0`.
- Add negative evidence rejecting no-code, TextEdit/TextBox/InputMan/direct-file/aggregate-only ownership, and the stale one-argument declaration.

Suggested Item Summary replacement:

```text
Exact IMEPane::SetFocusPane child with current MCP proof for the 0x6b body, four direct text-entry callers, backward focus-list de-duplication through List::GetElementAt/RemoveAt, conditional Append when focused is true, owner/emitter route through IMEPane, and formal C++ populated.
```

### Support [UID:00006H] `by-class/IMEPane.md`

Required changes:

- Change class shell prototype from `void SetFocusPane(Pane *pane);` to `void SetFocusPane(Pane *pane, bool focused);`.
- Update Method Notes row for `SetFocusPane` to show [UID:0004CC] `89/91`, formal C++ populated.
- Add Evidence Note that current MCP proves `SetFocusPane` as `void __thiscall(_DWORD *this, int, char)`, with caller polarity proving `focused`.
- Add Changes note for UID0004CC implementation callback, if accepted.

### Support [UID:0000K5] `by-file/IMEPanes.md`

Required changes:

- Update [UID:00006H] proposed contents row to include exact emitting UID0004CC `IMEPane::SetFocusPane`.
- Add Evidence/Changes note that UID0004CC now emits through [UID:00006H] into `NexusTK/input/IMEPanes.cpp`.
- No score change required for [UID:0000K5]; it is already `90/88` and the change is a child-body improvement.

### Support [UID:000189] `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`

Required changes:

- Update the UID0004CC covered-range/source-placement row to `89/91`; formal `IMEPane::SetFocusPane(Pane *pane, bool focused)` C++ populated.
- Preserve aggregate `[[CHILDREN]]`; do not paste UID0004CC body into the aggregate.
- Add a Changes note for the accepted child-specific pass.

### Optional Support Notes

- [UID:0001PS] `g_pIMEPane` already records the four call sites; no required metadata or score change. It may optionally mention that UID0004CC's second argument is now resolved as `focused`.
- [UID:0002RV] `TextBoxPaneConstructor` already emits `g_pIMEPane->SetFocusPane(this, false)` and needs no change.
- [UID:00018A] already uses `focusPaneList` / `focusPaneCount`; no required change.

### Validator / Generated Expectations For Callback Only

Do not run validators during this report-only benchmark. If accepted in a normal callback, run scoped validators from `source-3/project-documentation` on:

- `by-memory/0x004e80a0-0x004e810b.IMEPaneSetFocusPane.md`
- `by-class/IMEPane.md`
- `by-file/IMEPanes.md`
- `by-memory/0x004e70f0-0x004e8433.IMEPaneFamily.md`

Use `--wait-generated` on the final file/root validation when checking generated output. Expected generated result: `auto-generated/NexusTK/input/IMEPanes.cpp` contains a UID0004CC marker and the formal `IMEPane::SetFocusPane(Pane *pane, bool focused)` body through [UID:00006H], and no UID0004CC empty marker.

No manual `-coverage-report.md` or `auto-generated/-ag-*` edits are required. Validator refresh should update generated coverage/tracker state.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | UID0004CC is a real modeled function at `0x004e80a0`, size `0x6b`, exact range ending `0x004e810b`. | High | MCP request `7`; target filename/range. | UID0004CC Status/Evidence | incorporate | proposed |
| C02 | UID0004CC has four direct code callers and is not a no-code raw helper. | High | MCP request `8`; caller docs. | UID0004CC Evidence/Negative Evidence | incorporate | proposed |
| C03 | The method takes `Pane *pane` plus a boolean flag; [UID:00006H] one-argument declaration is stale/incomplete. | High | MCP requests `10`, `26`-`29`, `30`. | UID0004CC C++; [UID:00006H] class shell | incorporate | proposed |
| C04 | The body removes any existing matching focus-list entry before optional append. | High | MCP request `30` disassembly and request `10` decompile. | UID0004CC Behavior/C++ | incorporate | proposed |
| C05 | Caller polarity supports naming the flag `focused`: register paths pass `1`, unregister/removal paths pass `0`. | High | MCP requests `26`-`29`. | UID0004CC Behavior/C++; [UID:00006H] signature | incorporate | proposed |
| C06 | Source code should use accepted `List::GetElementAt`, `List::RemoveAt`, and `List::Append`. | High | [UID:000079] `List`; MCP slot use in request `30`. | UID0004CC C++/Reconstruction Notes | incorporate | proposed |
| C07 | Direct owner and emitter should be [UID:00006H] `IMEPane`, route [UID:0000K5] `IMEPanes`. | High | Current docs [UID:00006H], [UID:0000K5], [UID:000189], MCP state mutation. | UID0004CC metadata; support docs | incorporate | proposed |
| C08 | TextEditPane/TextBoxPane/InputMan/direct-file/aggregate-only ownership alternatives are rejected. | High | Caller xrefs plus state ownership docs. | UID0004CC Negative Evidence/Ranked Ownership | incorporate | proposed |
| C09 | Score should move to `89/91`; higher final-audit score is capped by inferred parameter spelling. | Medium-high | Current MCP and support docs. | UID0004CC Score Rationale | incorporate | proposed |
| C10 | Generated output should contain UID0004CC body after callback validation; no manual generated edits. | High | by-structure emitter rules; route through [UID:00006H]. | Checklist / Generated expectations | incorporate | proposed |

## Open Questions With Attempted Resolution

- Exact original parameter spelling: unresolved, but no longer a blocker. Evidence checked: caller polarity, method behavior, existing `SetFocusRegistration` caller context, target decompile/disassembly. Best current source-facing name is `focused`; confidence cap only.
- Exact original `List` API spelling: resolved to current project-accepted `GetElementAt`, `RemoveAt`, and `Append` from [UID:000079]. No blocker remains.
- Whether `focusPaneCount` should be treated as a `List` internal count or separate class field: current project docs consistently expose it as `IMEPane::focusPaneCount` at `+0x110`, and accepted IME C++ already uses that spelling. No target-blocking layout change is recommended in this pass.

## Validator Results

No validators were run. The assignment explicitly forbids validator commands because they can write generated/state files.

## Changed Files

Created:

- `tools/leaser/Agents/Agent-B015/research/benchmark-xhigh-0004CC-IMEPaneSetFocusPane-source-quality.md`

Modified:

- None besides this report file.

Renamed/moved/deleted:

- None.

Leases:

- None used. No leases were needed or allowed for this report-only benchmark.

Confirmation:

- Only this report file was written by this benchmark pass.

token usage: unavailable

## Unchecked Implementation Tracking Checklist

- [ ] Supervisor validation required before any implementation.
- [ ] Update [UID:0004CC] target metadata to `89/91`, owner `00006H`, reconstructable true, emitter `00006H`, blank emitter position.
- [ ] Insert the exact formal `IMEPane::SetFocusPane(Pane *pane, bool focused)` C++ block into UID0004CC.
- [ ] Update UID0004CC behavior/evidence/negative-evidence/score sections with MCP request ids `7`-`10` and `26`-`33`.
- [ ] Update [UID:00006H] `IMEPane` class shell prototype to `void SetFocusPane(Pane *pane, bool focused);`.
- [ ] Update [UID:00006H] method/evidence/change notes for UID0004CC formal emission.
- [ ] Update [UID:0000K5] `IMEPanes` proposed contents/evidence/change notes for UID0004CC emission through [UID:00006H].
- [ ] Update [UID:000189] aggregate covered-range/source-placement row for UID0004CC to `89/91`, formal populated, while preserving aggregate `[[CHILDREN]]`.
- [ ] Preserve rejected alternatives: no-code, TextEditPane/TextBoxPane/InputMan/direct-file/aggregate-only ownership, stale one-argument signature, raw list-vtable pseudocode.
- [ ] Run only callback-approved scoped validators, not during this benchmark report pass.
- [ ] After callback validation with generated refresh, confirm generated `auto-generated/NexusTK/input/IMEPanes.cpp` contains UID0004CC formal body and no UID0004CC empty marker.
- [ ] Do not manually edit generated reports, generated C++, manual coverage reports, validator/tool state, supervisor ledgers, lock files, goal/notes, or IDA DB.
