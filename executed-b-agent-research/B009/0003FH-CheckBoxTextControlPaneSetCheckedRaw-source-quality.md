** TARGET-REPORT-UID:0003FH **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0003FH CheckBoxTextControlPaneSetCheckedRaw Source-Quality Report

Date: 2026-06-19

Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/0003FH-CheckBoxTextControlPaneSetCheckedRaw-source-quality.md`

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003FH][0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw](../../../../../by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md) as source-authored `CheckBoxTextControlPane::SetChecked(bool)`, owned/emitted by [UID:000022][CheckBoxTextControlPane](../../../../../by-class/CheckBoxTextControlPane.md), with generated route through [UID:0000NY][SpecializedButtonPanes](../../../../../by-file/SpecializedButtonPanes.md).
- Final disposition: no split, no merge, no no-code/compiler-glue demotion. The raw/no-direct-xref status remains a confidence cap, not a blocker to the already-populated formal C++.
- Current target state after supervisor validator command `000000006874`: `COMPLETION:87`, `CONFIDENCE:88`, `CANONICAL_OWNER:000022`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000022`, blank `EMITTER_POSITION_OPTIONAL`, and formal `CheckBoxTextControlPane::SetChecked(bool)` C++ populated.
- This repair removes only the active-copy top-level revalidation status/reason lines, historicalizes the `target_uid_unknown: 0003FH` lifecycle reason in the report body, replaces stale MCP-unavailable language with current MCP-backed evidence, and records validator command `000000006874`.
- Report-only repair did not edit target/support by-* docs. This callback edited only the target by-memory page to remove stale MCP-unavailable score-rationale wording and add current MCP provenance; no support docs, generated files, coverage reports, validator state, lifecycle/archive files, supervisor ledgers, or validator history footer were edited.
- Confidence: high for byte behavior, field identity, class owner, and source shape; medium-high for liveness because current IDA MCP still does not model the raw setter start and reports no direct xrefs or pointer hits for `0x0059e0b0`.

## Target

- Target UID: `0003FH`
- Target path: `source-3/project-documentation/by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md`
- Current metadata: `COMPLETION:87`, `CONFIDENCE:88`, `CANONICAL_OWNER:000022`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000022`, blank `EMITTER_POSITION_OPTIONAL`, formal C++ populated.
- Current generated route: `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp`.
- Current validator state incorporated here: supervisor scoped file validator command `000000006874`, timestamp `2026-07-05T07:27:59-04:00`, exit code `0`, ok count `1`, effects `path_update`, `completion_update 87`, `confidence_update 88`, `canonical_owner_update 000022`, `insert_header_blank`, registry/projected-stat updates, and `generated_refresh: deferred`.
- Current warning state: validator command `000000006874` still reported sibling `missing_ref_uid` warnings for `0003FI` and `0003FG`. Those are sibling registry warnings, not direct UID0003FH target-body mismatches.

## Supporting Research

This active copy was returned from executed archive by validator command `000000006871` with top-level status `needs-revalidation` and reason `target_uid_unknown: 0003FH`. For this repair copy only, the top-level validator status/reason header lines were removed as directed. The lifecycle reason is retained here as historical prose and the validator-owned `VALIDATOR-REPORT-HISTORY` footer is preserved unchanged.

The original report correctly identified that the target does not require split repair. `0x0059e0b0-0x0059e0c0` is an exact 16-byte raw method child between [UID:0003FG][CheckBoxTextControlPaneOnPaint](../../../../../by-memory/0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md) and [UID:0003FI][CheckBoxTextControlPaneGetChecked](../../../../../by-memory/0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked.md). The stale split/coverage issue was historical project state; the current target page now carries UID0003FH and the source-shaped setter detail.

## Current Target State

- Target page now contains `UID:0003FH`, `COMPLETION:87`, `CONFIDENCE:88`, `CANONICAL_OWNER:000022`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000022`, and blank `EMITTER_POSITION_OPTIONAL`.
- Formal target C++ is populated as `void CheckBoxTextControlPane::SetChecked(bool checked) { m_checked = checked; }`.
- The target prose records the raw setter body, the no-direct-xref/no-pointer-hit liveness cap, constructor/paint/getter/PartySearch field corroboration, and the `m_checked` field at `this+0x108`.
- The active MCP session confirms the current IDB still does not model `0x0059e0b0` as a function and does model the adjacent getter at `0x0059e0c0` as `sub_59E0C0`, size `0x7`.
- No by-* target or support docs were edited during the Gate 1 report-only repair. During this callback, only the target by-memory page was edited to correct stale MCP availability wording; support docs stayed already-present/no-edit.

## Evidence Standards Used

- Current MCP evidence is mandatory for this revalidation repair. The stale MCP-unavailable finding in the old report is superseded by current schema-current MCP calls against active session `supervisor_recovery_20260705`.
- MCP calls were narrow and address-bounded: `idb_list`, database-scoped `server_health`, exact-address `lookup_funcs`, bounded `xrefs_to`, bounded `get_bytes`, single-function `decompile`, bounded `disasm`, exact-pattern `find_bytes`, and `int_convert`.
- Direct by-* documentation checks were limited to the UID0003FH target and named support docs. No broad report moves, lifecycle/archive commands, generated edits, coverage edits, validator-state edits, or by-* edits were performed.
- Existing local PE/exported evidence from the original report remains useful corroboration but is no longer a substitute for MCP evidence.

## Evidence Checked

Governance and workflow:

- `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/SKILL.md`
- `E:/NTK/GhidraBridge/.codex/skills/ntk-b-agent-workflow/references/b-agent-research-and-implementation-workflow.md`
- `source-3/project-documentation/tools/leaser/Agents/Agent-B009/goal.md`
- `source-3/project-documentation/by-structure.md`

Target and direct support docs:

- `by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md`
- `by-class/CheckBoxTextControlPane.md`
- `by-file/SpecializedButtonPanes.md`
- `by-memory/0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw.md`
- `by-memory/0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md`
- `by-memory/0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked.md`
- `by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md`
- `by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md`
- `by-type/by-struct/SpecializedButtonPaneLayouts.md`
- `by-type/by-vtable/SpecializedButtonPaneVtables.md`
- `by-class/PartySearchEditPane.md`

Current MCP evidence:

- `idb_list`: one active adopted backend worker session, `supervisor_recovery_20260705`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, filename `NexusTK.exe.i64`, `count=1`, `owned/adopted=true`, worker PID `19604`.
- `server_health(database='supervisor_recovery_20260705')`: status `ok`, IDB path above, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready with size `2067`.
- `lookup_funcs`: `0x0059e0ac` not a function; `0x0059e0b0` not a function; `0x0059e0c0` is `sub_59E0C0`, size `0x7`; `0x0059e0c7` not a function; `0x0059e0d0` is `sub_59E0D0`, size `0x2c3`; `0x0059df50` is `sub_59DF50`, size `0x15c`.
- `xrefs_to` for `0x0059e0b0` and `0x0059e0c0`, limit `20`: zero cross-references for both addresses.
- `get_bytes(0x0059e0ac, 36)`: four prepad `0xcc` bytes, target body `55 8b ec 8a 45 08 88 81 08 01 00 00 5d c2 04 00`, getter bytes `8a 81 08 01 00 00 c3`, then nine `0xcc` bytes.
- `decompile(0x0059e0b0)`: failed because the raw setter start is not an IDA function.
- `decompile(0x0059e0c0)`: `char __thiscall sub_59E0C0(_BYTE *this) { return this[264]; }`.
- `disasm(0x0059e0b0, max=12)`: raw setter instructions through `retn 4`, followed by getter `mov al, [ecx+108h]`, `retn`, alignment to `0x0059e0d0`.
- `find_bytes`: no VA, RVA, or raw-offset pointer hits for `0x0059e0b0` using patterns `b0 e0 59 00`, `b0 e0 19 00`, and `b0 d4 19 00`.
- `int_convert`: `0x108` = decimal `264`; `0x0059e0b0` = decimal `5890224`; `0x0059e0c0` = decimal `5890240`.

Supervisor validator evidence incorporated:

- Command `000000006874`: `python .\tools\validator.py --mode file --file by-memory\0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md --apply --queue-timeout 240`
- Timestamp `2026-07-05T07:27:59-04:00`, exit code `0`, ok count `1`.
- Effects: `path_update`, `completion_update 87`, `confidence_update 88`, `canonical_owner_update 000022`, `insert_header_blank`, registry/projected-stat updates, and generated refresh deferred.
- Remaining warnings: sibling `missing_ref_uid` warnings for `0003FI` and `0003FG`, treated as sibling registry warnings outside this UID0003FH report-only repair scope.

## Claim And Incorporation Ledger

| Claim | Accepted fact | Callback verification state |
|---|---|---|
| 3FH-C01 | Active-copy top-level `REPORT-VALIDATION-STATUS` and `REPORT-REVALIDATION-REASON` lines were removed while footer history stayed validator-owned. | `applied`; verified in report header/footer; historical reason retained under Supporting Research. |
| 3FH-C02 | Validator command `000000006874` established current target UID/path/metadata state and left sibling warnings for `0003FI`/`0003FG`. | `applied`; report records `000000006874`; callback validator `000000006880` revalidated the target with ok `1` and the same sibling warning class. |
| 3FH-C03 | Current MCP is available through session `supervisor_recovery_20260705`; stale MCP-unavailable evidence is superseded. | `applied`; target drift corrected to record current MCP revalidation and remove stale live-IDA-unavailable confidence wording. |
| 3FH-C04 | UID0003FH target currently owns source-shaped `CheckBoxTextControlPane::SetChecked(bool)` at `0x0059e0b0-0x0059e0c0`. | `already-present`; target header/body contain formal C++ and matching prose. |
| 3FH-C05 | Raw body writes the byte argument from `[ebp+8]` into `this+0x108` and returns with `retn 4`. | `already-present`; target, class, layout, constructor, paint, and getter docs carry same behavior. |
| 3FH-C06 | Boundary evidence is four prepad `0xcc` bytes before the raw setter and adjacent getter bytes at `0x0059e0c0`, followed by alignment padding. | `already-present`; target, paint, getter, and executable-map docs carry the same boundary. |
| 3FH-C07 | No direct xrefs and no VA/RVA/raw pointer hits were found for `0x0059e0b0`; this remains a confidence cap. | `applied`; target already had no-route facts and now has current MCP provenance plus corrected score rationale. |
| 3FH-C08 | Field identity is `m_checked` at offset `0x108`/decimal `264`, corroborated by constructor, paint, getter, layout, and PartySearch use. | `already-present`; all listed support docs checked at same-or-greater detail. |
| 3FH-C09 | Ownership remains [UID:000022] `CheckBoxTextControlPane`; source route remains [UID:0000NY] `SpecializedButtonPanes`. | `already-present`; target, class, file, layout, vtable, and executable-map docs align. |
| 3FH-C10 | B009 must not edit generated/coverage/validator-state/lifecycle files or run execute/lifecycle commands. | `applied`; only target by-memory page and this report were edited; scoped validator run; lease released; no forbidden commands. |

## Positive Evidence Summary

- Exact bytes implement a minimal `__thiscall` setter taking one stack byte parameter and storing it into the same `this+0x108` field read by the adjacent getter.
- Current MCP validates the raw-boundary state rather than relying only on exported data.
- The target page and support docs already identify the class owner, field offset, source route, and no-repaint/no-invalidation caveat.
- The absence of direct call/pointer evidence is explicitly represented as a confidence cap, not as a no-code proof.

## Raw Bytes / Boundary / Padding

Local PE section mapping:

- Section: `.text`
- Target VA: `0x0059e0b0`
- Target raw offset: `0x0019d4b0`
- Function-sized body: 16 bytes, `0x0059e0b0-0x0059e0c0`

Contiguous bytes around the target:

```text
0x0059e0ac-0x0059e0b0 prepad: cc cc cc cc
0x0059e0b0-0x0059e0c0 body:   55 8b ec 8a 45 08 88 81 08 01 00 00 5d c2 04 00
0x0059e0c0-0x0059e0c7 getter: 8a 81 08 01 00 00 c3
0x0059e0c7-0x0059e0d0 postpad: cc cc cc cc cc cc cc cc cc
```

Capstone disassembly of the target:

```asm
0059E0B0  push    ebp
0059E0B1  mov     ebp, esp
0059E0B3  mov     al, byte ptr [ebp + 8]
0059E0B6  mov     byte ptr [ecx + 0x108], al
0059E0BC  pop     ebp
0059E0BD  ret     4
```

Boundary conclusion:

- The predecessor [UID:0003FG] paint method ends at `0x0059e0ac`.
- `0x0059e0ac-0x0059e0b0` is exactly four `0xcc` alignment bytes.
- The old broad page/coverage statement that treated `0x0059e0ac-0x0059e0c0` as padding was wrong; `0x0059e0b0-0x0059e0c0` is real setter code.
- The successor [UID:0003FI] getter begins exactly at `0x0059e0c0` and returns the same byte field.
- `0x0059e0c7-0x0059e0d0` is nine `0xcc` alignment bytes before [UID:0000A7] `PartySearchEditPane` constructor code.

## Xref / Liveness Evidence

Negative direct-route evidence:

- `resources/exported_data/functions/0x0059e0b0.json` records the Ghidra function with size `16`, zero callers, zero callees, and no data refs.
- IDA does not model `0x0059e0b0` as a function in current docs/exports; IDA `xrefs_to` is null/none for this raw start.
- Local PE absolute dword scan found:
  - zero VA dword hits for `0x0059e0b0`
  - zero RVA dword hits for `0x0019e0b0`
  - zero raw-offset dword hits for `0x0019d4b0`
  - zero `.text` `rel32` call/jmp hits targeting `0x0059e0b0`

Positive liveness/source-shape evidence:

- The bytes form a complete `__thiscall` method with a normal stack frame and `ret 4`, not padding, not a thunk, and not an embedded data island.
- The method is physically between the class paint virtual and the class checked-state getter, both exact source-owned children.
- The field written at `+0x108` is initialized by the raw constructor, read by paint, returned by the getter, inlined/toggled by `PartySearchEditPane::OnAction`, and documented in the layout/type page.
- The generated autogen route treats `0003FH` as emitting through `CheckBoxTextControlPane` into `NexusTK/ui/controls/SpecializedButtonPanes.cpp`; after validator command `000000006874`, the target formal C++ is populated and generated refresh is deferred to validator/supervisor execution.
- Source-level class APIs commonly compile unused setters/getters even when call sites are inlined or no direct binary call survives. This binary has several raw constructor/accessor starts in this source family that are not IDA-modeled but are still real source-shaped class methods.

Conclusion: no-direct-xref remains an explicit confidence cap and should stay in target docs, but it is not a no-code proof and should not block the existing formal setter C++.

## Field / Type Resolution

Best current field model for this target:

| Offset | Source-facing name | Type | Confidence | Evidence |
| --- | --- | --- | --- | --- |
| `+0x108` | `m_checked` / `m_isChecked` | `bool` stored as byte | High | Constructor stores initial checked byte; setter writes argument byte; getter returns byte; paint selects on/off checkbox tile; PartySearch reads/toggles it. |
| `+0x10a` | `m_label` | `wchar_t[0x100]` | High | Constructor copies label with count `0x100`; paint scans/draws label twice; PartySearch inline setup copies `Put me on the hunters list`. |

Recommended field name: `m_checked`. `m_isChecked` is also acceptable, but `m_checked` pairs cleanly with `SetChecked(bool checked)` and `GetChecked()` without making the getter name awkward.

Recommended setter signature is the existing formal target member `CheckBoxTextControlPane::SetChecked(bool)`.

Rationale:

- The raw body takes one byte-sized argument at `[ebp+8]` and writes it to a byte field.
- Existing target name and sibling getter already use `Checked`, not `Selected`, `Enabled`, or `Visible`.
- The field is semantic checked state, not PartySearch-only hunters-list state; PartySearch uses this generic checkbox to represent hunters-list membership.
- The method has no invalidation side effect. `PartySearchEditPane::OnAction` directly toggles the byte and then calls the child control's invalidation/refresh virtual slot separately. Do not make `SetChecked` call repaint/invalidate unless future evidence shows a different method body.

Recommended getter counterpart for support docs is `CheckBoxTextControlPane::GetChecked() const`.

`IsChecked()` is plausible as a higher-level C++ name, but the existing sibling page, generated route, and paired setter naming all point to `GetChecked`/`SetChecked` as the least disruptive first-draft source-facing names.

## Related Field Users

### Constructor [UID:0003FE]

The raw constructor-shaped body at `0x0059ded0-0x0059df27`:

- calls the base control constructor with argument `8`;
- installs the three `CheckBoxTextControlPane` vtables;
- stores the incoming checked byte at `+0x108`;
- copies the input wide label into `+0x10a` with a `0x100` wide-character capacity.

This supports a constructor with a checked-state argument, label argument, and bounds/base argument, but exact inherited/base argument type remains outside this target's scope.

### Paint [UID:0003FG]

The paint method at `0x0059df50-0x0059e0ac`:

- reads `+0x108` twice;
- selects the checked/on or unchecked/off resource/tile state;
- reads/scans `+0x10a` for shadow and foreground label drawing.

This proves the setter writes visible UI state and not a hidden PartySearch-only flag.

### Getter [UID:0003FI]

The getter at `0x0059e0c0-0x0059e0c7` is IDA-modeled; current MCP decompilation returns the byte at `this[264]`, matching `this+0x108`.

This is the exact read counterpart to the setter. It has no direct refs either, so the setter's no-xref status is consistent with this small accessor pair rather than suspicious by itself.

### PartySearchEditPane [UID:0000A7]

`PartySearchEditPane` is a consumer, not owner:

- Constructor `0x0059e0d0-0x0059e393` allocates a `0x30c` byte checkbox control, inlines equivalent setup, writes the three `CheckBoxTextControlPane` vtables, stores `g_pPlayerData+0x3cb1` into child `+0x108`, and copies label `Put me on the hunters list`.
- `OnAction` at `0x0059e3d0-0x0059e707` reads child control index `2` and writes `g_pPlayerData+0x3cb1` from `child+0x108` on action `1`.
- On action `2`, it toggles the same byte directly and then calls the child refresh/invalidation virtual path; the old report's decompiler snippet is summarized here instead of retained as side C-like code.

This direct toggling is likely source-local dialog code optimizing/inline-accessing the child field or using a known control pointer. It does not make the setter dead/non-source; it only explains why no call to `SetChecked` appears in this dialog's compiled body.

## Heuristic / Inference Reanalysis And Validation

### 1. Raw Start / No IDA Function

- Evidence checked: target doc, exported Ghidra function record, local PE bytes/disassembly, local PE pointer and rel32 scans, supporting layout/class docs.
- Best conclusion: real source-authored method bytes that IDA failed to promote to a function.
- Rejected alternatives:
  - Padding: impossible; the bytes decode to a coherent method and write a live field.
  - Data island: rejected by instruction shape and placement between source methods.
  - Compiler thunk: rejected because it does not adjust `this`, jump to another body, or call deleting destructor; it performs a source-level assignment.
  - Dead garbage: weak; the method has a generated emission route and exact class API pairing with getter/constructor/paint.
- Remaining caveat: no direct xrefs/pointer hits. This caps confidence and should remain visible.

### 2. Source-Facing Method Name

- Evidence checked: existing target name, getter page, constructor/paint field usage, PartySearch usage.
- Best name: `CheckBoxTextControlPane::SetChecked`.
- Rejected alternatives:
  - `SetValue`: too generic; all supporting docs call the field checked state.
  - `SetSelected`: wrong UI state; paint selects on/off checkbox tile, and PartySearch label maps it to membership.
  - `ToggleChecked`: wrong behavior; the method stores caller-supplied byte, it does not toggle.
  - `SetHuntersList`: wrong ownership; PartySearch uses the checkbox for hunters-list membership but the reusable control is generic.
  - `Check`/`Uncheck`: wrong signature; one byte argument chooses state.
- Confidence: high for descriptive/source-facing name; exact original capitalization/spelling cannot be proven.

### 3. Field Name / Type

- Evidence checked: constructor store, setter store, getter return, paint branch, PartySearch read/toggle, layout type doc.
- Best name/type: `bool m_checked`.
- Rejected alternatives:
  - `char m_checked`: binary storage is byte, but source intent is boolean.
  - `m_state`: too vague and overlaps inherited control state fields.
  - `m_huntersListFlag`: PartySearch-specific, not class-generic.
  - `m_selected`: not supported by source class name or paint resource semantics.
- Confidence: high for role and type; medium-high for exact field spelling.

### 4. Liveness / Emission Policy

- Evidence checked: generated `-ag-memory-coverage`, generated `SpecializedButtonPanes.cpp`, class/file parents, xref negatives.
- Best conclusion: emit first-draft source for the setter. This is a reconstructable source method whose compiled bytes exist in the original binary. It should not be removed merely because no surviving direct call exists.
- Rejected alternatives:
  - No-code proof: rejected because the body is not generated wrapper glue and not a compiler artifact.
  - Leave formal C++ blank: old caution was reasonable before raw-entry audit, but current gate clears and the source shape is exact.
  - Attach only to sparse map: rejected because exact target already has a direct class owner and valid emitter route.

### 5. Owner / Source Placement

- Evidence checked: class page, file page, executable map, vtable data, layout/vtable type docs, PartySearch class docs.
- Best direct owner: [UID:000022] `CheckBoxTextControlPane`.
- Best source route: [UID:0000NY] `SpecializedButtonPanes`, generated at `NexusTK/ui/controls/SpecializedButtonPanes.cpp`.
- Future source split: `ui/controls/CheckBoxTextControlPane.cpp` remains plausible, but current project route is the validated source-family bucket. Do not move this target in the implementation callback unless the source root is split deliberately.
- Rejected alternatives:
  - [UID:0000A7] `PartySearchEditPane`: consumer and inline setup site only.
  - [UID:0000OZ] `UserListDialogPane`: physical neighborhood/source consumer only; reusable checkbox control would be misrouted.
  - [UID:0001KJ] sparse map: non-emitting map over mixed ownership, not a source owner.
  - `CANONICAL_OWNER:NONE`: too weak; class parent and emitter route both clear the current gate.

## Ranked Ownership Analysis

### 1. `CheckBoxTextControlPane` [UID:000022] - Accepted

Evidence for:

- The setter writes the class checked field at `+0x108`.
- Constructor, paint, getter, destructor/vtable data, and layout docs all identify the same class.
- The generated route already emits through this class into the reusable controls source file.
- Direct class parent is currently `85/87`, clearing the strict parent gate.

Evidence against:

- IDA does not model this exact start and no direct refs were found.

Decision: accepted. The no-xref caveat caps confidence but does not defeat the class owner.

### 2. `SpecializedButtonPanes` [UID:0000NY] - Accepted As Source Route

Evidence for:

- File page is the validated provisional `NexusTK/ui/controls/` root.
- Generated output path exists and currently carries the empty `0003FH` marker.
- Related class/file docs keep `CheckBoxTextControlPane` in this reusable UI-control bucket while allowing a future split.

Evidence against:

- Final original filename may have been `CheckBoxTextControlPane.cpp` rather than literal `SpecializedButtonPanes.cpp`.

Decision: keep as current emitter route; do not split in this report-only pass.

### 3. `PartySearchEditPane` / `UserListDialogPane` - Rejected As Owner

Evidence for:

- PartySearch constructs and toggles one checkbox instance.
- Physical code neighborhood is inside the user-list/party-search aggregate.

Evidence against:

- PartySearch code writes class vtables and fields for a child control, not ownership of the reusable control class.
- The same checkbox class has independent constructor, paint, getter, setter, vtable data, and destructor docs.
- The sparse map explicitly crosses reusable-control and social dialog ownership.

Decision: consumer only.

### 4. No-Code / Compiler-Generated Artifact - Rejected

Evidence for:

- No direct callers and IDA did not promote a function.

Evidence against:

- The body is a plain source-level assignment method, not an adjustor thunk, scalar deleting destructor, EH helper, or padding.
- It has a valid class owner and generated output route.

Decision: reject no-code. Emit first-draft setter source.

## Source Placement

Current source route:

- Direct canonical owner/emitter: [UID:000022] `CheckBoxTextControlPane`.
- File route: [UID:0000NY] `SpecializedButtonPanes`, currently projected to `NexusTK/ui/controls/SpecializedButtonPanes.cpp`.
- Target doc route: `by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md`.

Rejected placements:

- `PartySearchEditPane` is rejected because it is only a consumer that directly toggles the child control field and separately invalidates the child.
- The broad executable map is rejected as an emitter because it crosses reusable-control and social-dialog ownership; it is a sparse map/coordination artifact.
- A no-owner/no-code placement is rejected because the bytes are a real assignment method with class-family field corroboration.

Remaining uncertainty:

- The final original source filename and exact spelling of the source method are inferred from current class/file organization and sibling naming. `SpecializedButtonPanes.cpp` and `SetChecked(bool)` remain the least-disruptive current source route, but the raw/no-direct-route evidence keeps confidence below final-audit level.

## Negative Evidence Summary

- No direct IDA xrefs to `0x0059e0b0` are known.
- No Ghidra callers are known.
- Local PE scan found no absolute VA/RVA/raw-offset pointer hits for `0x0059e0b0`.
- Local PE scan found no `.text` `rel32` call/jmp hits to `0x0059e0b0`.
- The method is not in the known vtable slots; the vtable points to paint, control-type helper, destructor, and adjustor thunks, not the setter/getter.
- PartySearch toggles `+0x108` directly instead of calling this setter.

These negatives should stay in target/support docs. They explain why confidence should not jump to final-audit levels, but they do not support deleting or no-coding the target.

## First-Draft C++ Recommendation

Current target formal C++ is already populated and should be preserved. Exact formal `RECONSTRUCTION_CPP CODE` header/block text for the target:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
void CheckBoxTextControlPane::SetChecked(bool checked)
{
    m_checked = checked;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Do not add an invalidation/repaint call to this method. The binary body is only a byte store and `ret 4`; `PartySearchEditPane::OnAction` performs invalidation/refresh separately after directly toggling the byte.

Nearby class declaration guidance is intentionally prose-only in this repaired report. A broader class implementation callback would need to accept constructor/base-layout names before any class declaration is entered.

## Score And Metadata Recommendation

Target metadata:

```text
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:000022 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:000022 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale:

- Current target score is already `COMPLETION:87` and `CONFIDENCE:88` after supervisor validator command `000000006874`; this report-only repair proposes no further score change.
- Completion `87` is appropriate because the target now records exact bytes, raw boundary/padding, current MCP function-model state, no-xref/no-pointer negative evidence, field users, source-facing name/signature, and formal setter C++.
- Confidence `88` is appropriate because byte behavior and ownership are strongly corroborated by constructor/paint/getter/PartySearch/layout docs and current MCP checks. Confidence remains capped because IDA still does not model the raw setter start, there are no direct xrefs/pointer refs, and exact original source spelling/source-file split remain inferred.
- Do not raise to `95+`: raw/no-xref liveness, final original method spelling, inherited class declaration, and final source-file split are still not final-audit quality.

## Recommended Target Doc Changes

For `by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md`:

Callback verification found the accepted target details already present except one stale score-rationale phrase saying live IDA was unavailable to B009. B009 leased the target, added current `supervisor_recovery_20260705` MCP provenance to the IDA evidence section, removed the stale unavailability rationale, validated the target with command `000000006880`, and released the lease.

Implementation-callback verification checklist, if supervisor later asks for it:

- Verified metadata remains `COMPLETION:87`, `CONFIDENCE:88`, `CANONICAL_OWNER:000022`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000022`, and blank `EMITTER_POSITION_OPTIONAL`.
- Verified formal C++ remains the exact setter shown in `First-Draft C++ Recommendation`.
- Verified target prose retains raw evidence: `.text` raw offset `0x0019d4b0`, four `0xcc` prepad bytes, body bytes `55 8b ec 8a 45 08 88 81 08 01 00 00 5d c2 04 00`, adjacent getter bytes at `0x0059e0c0-0x0059e0c7`, and nine `0xcc` postpad bytes.
- Verified and updated target prose for negative liveness evidence: IDA/MCP has no modeled function at `0x0059e0b0`, no direct xrefs, no VA/RVA/raw pointer hits, and no `.text` direct-route hits.
- Verified target prose retains field/user evidence: constructor initializes `+0x108`, paint reads `+0x108`, getter returns `+0x108`, layout docs name the field, and PartySearch toggles the field directly.
- Verified rejected alternatives remain explicit: not padding, not compiler thunk/no-code wrapper, not PartySearch-owned, not `ToggleChecked`, and no invalidation side effect.

## Recommended Support Doc Changes

No support by-* doc edit was needed during callback verification. Checked support docs already carry the UID0003FH source-family evidence at same-or-greater detail, or the remaining issue is a sibling registry warning outside direct UID0003FH support-doc scope.

Verification state by support doc:

- `by-class/CheckBoxTextControlPane.md`: callback `already-present`. The class page records `m_checked` at `+0x108`, `m_label` at `+0x10a`, [UID:0003FH] `SetChecked(bool)` as a source-ready raw setter, the no-direct-ref caveat, and the PartySearch direct-toggle/no-invalidation interpretation.
- `by-file/SpecializedButtonPanes.md`: callback `already-present`. The file page lists UID0003FH under the `CheckBoxTextControlPane` source bucket and records the no-direct-route confidence cap.
- `by-memory/0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked.md`: callback `already-present`. The getter page is the read counterpart to UID0003FH and returns the same `m_checked` byte at `+0x108`.
- `by-memory/0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md`: callback `already-present`. The paint page records reads from `+0x108` and ties that field to the constructor, setter, getter, layout docs, and PartySearch.
- `by-memory/0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw.md`: callback `already-present`. Constructor field initialization is already represented in target/class support evidence.
- `by-class/PartySearchEditPane.md`: callback `already-present`. PartySearch uses a child checkbox and toggles the byte directly rather than owning UID0003FH.
- `by-type/by-struct/SpecializedButtonPaneLayouts.md`: callback `already-present`. The layout evidence supports `m_checked` at `+0x108`.
- `by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md`, `by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md`, and `by-type/by-vtable/SpecializedButtonPaneVtables.md`: callback `already-present`; they corroborate sparse-map boundaries, class vtable ownership, and the reusable-control route without needing support edits.

Historical support-text proposals from the original report are retained below as implementation guidance only; do not apply them unless a later supervisor callback finds a concrete mismatch.

For `by-class/CheckBoxTextControlPane.md`:

- Update the setter method note:

```text
`SetChecked` at [UID:0003FH] is source-ready despite the raw/no-direct-xref caveat. It stores the caller-supplied byte/bool into `m_checked` at `+0x108` and performs no invalidation. No direct caller is currently known; PartySearch toggles the field directly and then invalidates the child control separately.
```

- Add/clarify field names:

```text
`+0x108` is best modeled as `bool m_checked`; `+0x10a` is `wchar_t m_label[0x100]`.
```

For `by-memory/0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked.md`:

- If touched, update naming consistency:

```text
The getter is the read counterpart to [UID:0003FH] `SetChecked(bool)` and should keep the source-facing `GetChecked` name unless a broader naming pass chooses `IsChecked()`.
```

For `by-memory/0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md`:

- No score change needed; if touched, add that the `+0x108` reads are `m_checked`, the field written by [UID:0003FH].

For `by-memory/0x0059ded0-0x0059df27.CheckBoxTextControlPaneConstructorRaw.md`:

- No score change needed; if touched, add that constructor's checked-byte argument initializes `m_checked`, the field later written by [UID:0003FH].

For `by-class/PartySearchEditPane.md`:

- No score change needed; if touched, clarify consumer relationship:

```text
PartySearch uses a `CheckBoxTextControlPane` child for the hunters-list setting. Its action handler toggles the child `m_checked` byte directly and invalidates the child control; this is consumer/inline-access evidence, not ownership of the generic checkbox setter.
```

For `by-file/SpecializedButtonPanes.md`:

- Optional note:

```text
B009 2026-06-19 rechecked [UID:0003FH] as source-ready `CheckBoxTextControlPane::SetChecked(bool)`. The raw/no-xref start remains a confidence cap, but the exact bytes, field users, generated route, and class owner support emitting the setter in the current provisional controls source bucket.
```

For `by-type/by-struct/SpecializedButtonPaneLayouts.md`:

- Optional field-name refinement:

```text
`0x108` is `m_checked`, a bool/byte checked-state field. It is initialized by the constructor, written by `SetChecked(bool)`, read by `GetChecked()` and paint, and toggled directly by `PartySearchEditPane`.
```

## Supervisor-Owned Generated/Coverage Notes

Do not edit `by-memory/-coverage-report.md`, generated files, project-level generated reports, validator state, lifecycle records, or supervisor ledgers directly.

Current state incorporated from supervisor validator command `000000006874`:

- The target page was repaired by validator/supervisor flow with path, score, owner, header, registry, and projected-stat effects.
- Generated refresh is deferred to validator/supervisor execution.
- Remaining warnings are sibling `missing_ref_uid` warnings for `0003FI` and `0003FG`; they are not direct UID0003FH target-body defects.

The historical manual coverage text below is retained only as lifecycle context from the original report. It is not a B009 repair instruction for this active report-only pass.

Historical coverage issue from the original report: the report then observed only this stale broad row:

```text
    - [UID:0001KJ][0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap](by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md) 0x0059ded0-0x0059f0a4 | class-methods | CheckBoxTextControlPane : reconstructable : 78% : strong : Constructor-shaped bytes, paint, teardown, destructor, checked-byte/label-buffer evidence, cross-linked exact control-type helper, and vtable-data support; A002 cleared stale class-parent metadata because this child is `78/82` and must not attach to direct class parent [UID:000022][CheckBoxTextControlPane](by-class/CheckBoxTextControlPane.md) until the child side clears `85/85`.
```

Historical recommended replacement parent row:

```text
    - [UID:0001KJ][0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap](by-memory/0x0059ded0-0x0059f0a5.CheckBoxTextControlPaneExecutableMap.md) 0x0059ded0-0x0059f0a5 | sparse executable map | CheckBoxTextControlPaneExecutableMap : ignored : 88% : strong : Non-emitting sparse map over exact CheckBoxTextControlPane children, padding, compiler adjustor thunks, and foreign PartySearch/UserList code; exact source-bearing checkbox children carry class ownership under [UID:000022], while this broad map stays parentless/non-emitting because it crosses reusable-control and social-dialog ownership.
```

Historical exact target child row proposed under that map after the paint child row and before the getter child row:

```text
        - [UID:0003FH][0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw](by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md) 0x0059e0b0-0x0059e0c0 | raw method | CheckBoxTextControlPaneSetCheckedRaw : reconstructable : 87% : strong : Raw source-shaped `CheckBoxTextControlPane::SetChecked(bool)` setter; IDA does not model the start and PE/Ghidra scans find no direct callers or pointer hits, but local bytes decode to a 16-byte `this+0x108 = checked` method between paint and getter, with constructor, paint, getter, layout docs, and PartySearch direct toggling all corroborating `+0x108` as `m_checked`.
```

If supervisor handles full child nesting later, surrounding target placement was proposed as:

```text
        - [UID:0003FG][0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint](by-memory/0x0059df50-0x0059e0ac.CheckBoxTextControlPaneOnPaint.md) 0x0059df50-0x0059e0ac | virtual paint method | CheckBoxTextControlPaneOnPaint : reconstructable : 87% : strong : ...
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x0059e0ac-0x0059e0b0 | padding | CheckBoxTextControlPane paint/setter alignment : ignored : 100% : strong : Four `0xcc` alignment bytes before the raw checked setter.
        - [UID:0003FH][0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw](by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md) 0x0059e0b0-0x0059e0c0 | raw method | CheckBoxTextControlPaneSetCheckedRaw : reconstructable : 87% : strong : Raw source-shaped `CheckBoxTextControlPane::SetChecked(bool)` setter; IDA does not model the start and PE/Ghidra scans find no direct callers or pointer hits, but local bytes decode to a 16-byte `this+0x108 = checked` method between paint and getter, with constructor, paint, getter, layout docs, and PartySearch direct toggling all corroborating `+0x108` as `m_checked`.
        - [UID:0003FI][0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked](by-memory/0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked.md) 0x0059e0c0-0x0059e0c7 | method | CheckBoxTextControlPaneGetChecked : reconstructable : 86% : strong : ...
```

## IDA Rename / Type / Comment Recommendations

These are recommendations only; this report did not modify IDA.

| Address / item | Recommendation | Confidence | Reason |
| --- | --- | --- | --- |
| `0x0059e0b0` | Create/label as `CheckBoxTextControlPane::SetChecked` only if IDA-side function creation is allowed in a future IDA pass | Medium-high | Raw bytes are a complete method but current IDA does not model a function. |
| `0x0059e0c0` | Rename `sub_59E0C0` to `CheckBoxTextControlPane::GetChecked` | High | IDA-modeled getter returns byte `+0x108`. |
| `CheckBoxTextControlPane +0x108` | `bool m_checked` | High | Constructor/setter/getter/paint/PartySearch all agree. |
| `CheckBoxTextControlPane +0x10a` | `wchar_t m_label[0x100]` | High | Constructor/PartySearch copy label; paint scans/draws it. |
| `0x0059e0ac-0x0059e0b0` | Comment as alignment padding, not padding through `0x0059e0c0` | High | Four `0xcc`; setter starts at `0x0059e0b0`. |
| `PartySearchEditPane::OnAction` direct `+0x108` toggle | Comment as direct child checkbox `m_checked` toggle plus separate invalidation | High | Prevents misrouting setter ownership to PartySearch. |

## Validator Results

Report-only repair validator state incorporated:

- Command ID: `000000006874`.
- Command timestamp: `2026-07-05T07:27:59-04:00`.
- Command: `python .\tools\validator.py --mode file --file by-memory\0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md --apply --queue-timeout 240`.
- Exit code: `0`.
- Ok count: `1`.
- Effects recorded: `path_update`, `completion_update 87`, `confidence_update 88`, `canonical_owner_update 000022`, `insert_header_blank`, registry/projected-stat updates, and `generated_refresh: deferred`.
- Remaining warnings: sibling `missing_ref_uid` warnings for `0003FI` and `0003FG`. These remain outside direct UID0003FH report-only repair scope unless supervisor assigns a sibling repair.

Callback validator run after the target drift fix:

- Command ID: `000000006880`.
- Command timestamp: `2026-07-05T07:51:11-04:00`.
- Command: `python .\tools\validator.py --mode file --file by-memory\0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md --apply --queue-timeout 240`.
- Exit code: `0`.
- Ok count: `1`.
- Warnings: `missing_ref_uid` repeated for sibling UID `0003FI` and once for sibling UID `0003FG`, same current sibling registry warning class; `stats_incremental_noop` for UID0003FH because the stats file is not present in generated stats lists.
- Side effects: `projected_stats_update: 1`, `stats_incremental_noop: 1`, and `generated_refresh: deferred` with `generated_refresh_command_id: 000000006880`.

B009 did not run `execute_report`, dry-run/probing execute variants, registry lifecycle commands, archive commands, report moves, or manual generated/coverage edits.

## Open Questions With Attempted Resolution

- MCP availability: resolved. Current MCP evidence is available in session `supervisor_recovery_20260705`; the old MCP-unavailable statement is superseded.
- Target UID unknown: resolved for the active copy. The historical `target_uid_unknown: 0003FH` reason is retained under Supporting Research, while current target page and validator command `000000006874` carry UID0003FH.
- Direct binary liveness: not fully resolved. Current MCP reports zero xrefs and no pointer hits for `0x0059e0b0`; this remains a confidence cap, not a no-code proof.
- Exact original source spelling/source file: partially resolved. `SetChecked(bool)` and `SpecializedButtonPanes.cpp` are the current supported route from target/support docs; final original spelling remains below final-audit certainty.
- Sibling warnings: unresolved outside scope. Validator command `000000006874` reported sibling `missing_ref_uid` warnings for `0003FI` and `0003FG`; no B009 manual state or sibling by-* edit is authorized in this report-only repair.

## Final Recommendation

Keep UID0003FH as a source-authored `CheckBoxTextControlPane::SetChecked(bool)` raw setter with current metadata `87/88`, owner/emitter [UID:000022], and generated route through [UID:0000NY] `SpecializedButtonPanes`. Callback verification found support docs already present at same-or-greater detail and corrected the target's stale MCP-unavailable rationale with current MCP provenance; the target validated under command `000000006880`.

## Implementation Tracking Checklist

Completed report-only repair checklist for this active Gate 1 repair:

- [x] Removed the active-copy top-level `REPORT-VALIDATION-STATUS: needs-revalidation` line.
- [x] Removed the active-copy top-level `REPORT-REVALIDATION-REASON: target_uid_unknown: 0003FH` line.
- [x] Preserved the validator-owned `VALIDATOR-REPORT-HISTORY` footer unchanged.
- [x] Historicalized the prior `target_uid_unknown: 0003FH` lifecycle reason under `## Supporting Research`.
- [x] Replaced stale MCP-unavailable language with current MCP-backed evidence from session `supervisor_recovery_20260705`.
- [x] Incorporated supervisor validator command `000000006874`, timestamp `2026-07-05T07:27:59-04:00`, exit code `0`, ok count `1`, generated refresh deferred, and sibling `missing_ref_uid` warnings for `0003FI`/`0003FG`.
- [x] Recorded current target metadata as `COMPLETION:87`, `CONFIDENCE:88`, `CANONICAL_OWNER:000022`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000022`, blank optional emitter position, and populated formal setter C++.
- [x] Updated `## Claim And Incorporation Ledger` with report-only states for status repair, MCP evidence, validator evidence, target facts, support-doc status, and no-edit boundaries.
- [x] Repaired `## First-Draft C++ Recommendation` to use exact formal `RECONSTRUCTION_CPP CODE` header/block text rather than a bare C++ snippet.
- [x] Made no target/support by-* doc edits during Gate 1 report-only repair.
- [x] Made no manual generated-file, project-level, coverage-report, validator-state, lifecycle/archive, executed-report, supervisor-ledger, or manual-report-move edits during Gate 1 report-only repair.
- [x] Ran no validators and no `execute_report`, dry-run/probing execute variant, registry lifecycle command, archive command, or report move.

Completed implementation callback / already-present verification checklist:

- [x] Re-read `## Claim And Incorporation Ledger`, `## Recommended Target Doc Changes`, `## Recommended Support Doc Changes`, and this checklist before by-* verification.
- [x] Verified target doc `by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md` contains UID0003FH, metadata `87/88`, owner/emitter `000022`, blank optional emitter position, and formal `SetChecked(bool)` C++.
- [x] Verified target raw facts remain present: exact bytes, four-byte prepad, adjacent getter at `0x0059e0c0`, nine-byte postpad, `this+0x108` store, `retn 4`, and no invalidation side effect.
- [x] Found and corrected one target drift item: stale score-rationale wording that live IDA was unavailable to B009. The target now records current `supervisor_recovery_20260705` MCP revalidation and keeps the no-function/no-xref/no-pointer-hit facts as confidence caps.
- [x] Verified support docs are already present at same-or-greater detail: `by-class/CheckBoxTextControlPane.md`, `by-file/SpecializedButtonPanes.md`, getter, paint, constructor, PartySearch, layout, executable map, vtable data, and vtable/type support.
- [x] Leased only `by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md` for the immediate target edit/validator batch.
- [x] Ran scoped target validator command `000000006880`; exit code `0`, ok count `1`, known sibling `missing_ref_uid` warnings for `0003FI`/`0003FG`, projected stats update, generated refresh deferred.
- [x] Released the B009 target lease immediately after validation.
- [x] Made no support by-* edits because all accepted support facts were already present.
- [x] Made no manual generated-file, project-level, coverage-report, validator-state, lifecycle/archive, executed-report, supervisor-ledger, or manual-report-move edits. Validator command `000000006880` updated projected stats as a tool side effect.
- [x] Ran no `execute_report`, dry-run/probing execute variant, registry lifecycle command, archive command, or report move.

## Changed Files

Modified by B009 in this repair/callback:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B009/research/0003FH-CheckBoxTextControlPaneSetCheckedRaw-source-quality.md`
- `source-3/project-documentation/by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md`

Validator side effect:

- `source-3/project-documentation/project-level/-auto-completion-stats.md` (`projected_stats_update: 1` from command `000000006880`; no manual edit).

Not modified by B009 in this callback:

- Support by-* docs.
- Generated files, coverage reports, validator state, lifecycle/archive files, executed-report records, supervisor ledgers, and validator-owned history/footer content.

Leases:

- Leased and released `by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003FH","source_path":"executed-b-agent-research/B009/0003FH-CheckBoxTextControlPaneSetCheckedRaw-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- {"agent":"B009","command_id":"000000006871","destination_path":"tools/leaser/Agents/Agent-B009/research/0003FH-CheckBoxTextControlPaneSetCheckedRaw-source-quality.md","details":"report returned to active agent research for rework","event":"de-executed-for-rework","source_path":"executed-b-agent-research/B009/0003FH-CheckBoxTextControlPaneSetCheckedRaw-source-quality.md","timestamp":"2026-07-05T07:27:09-04:00"} -->
<!-- {"agent":"B009","command_id":"000000006888","destination_path":"executed-b-agent-research/B009/0003FH-CheckBoxTextControlPaneSetCheckedRaw-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0003FH-CheckBoxTextControlPaneSetCheckedRaw-source-quality.md","timestamp":"2026-07-05T08:04:52-04:00","uid":"0003FH"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
