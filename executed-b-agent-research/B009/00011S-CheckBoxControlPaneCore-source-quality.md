** TARGET-REPORT-UID:00011S **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# 00011S CheckBoxControlPaneCore Source Quality Report

## Finalized Report / Current Recommendation

UID `00011S` should remain a reconstructable class-method cluster owned by [UID:000021] `CheckBoxControlPane`, emitted through the existing [UID:0000I7] `CheckBoxControlPane` file route into `NexusTK/ui/controls/CheckBoxControlPane.cpp`.

Accepted/applied target metadata:

| Field | Recommendation |
| --- | --- |
| `COMPLETION` | `89` |
| `CONFIDENCE` | `91` |
| `CANONICAL_OWNER` | keep `000021` |
| `RECONSTRUCTABLE` | keep `TRUE` |
| `EMITTER_UIDS` | keep `000021` |
| `EMITTER_POSITION_OPTIONAL` | keep blank |
| `RECONSTRUCTION_CPP` | first-draft C++ for the six in-range methods applied |

The old blockers are resolved enough for a first-draft source body:

- Exact source shape is six functions in the half-open range `0x00499d40-0x00499f0e`.
- The final implementation route should use `CheckBoxControlPane.cpp` for current validator output. The broader `ButtonControlPane.cpp` family remains a historical-source caveat, not a reason to move UID `00011S`.
- The source-authored `0x00499ec0` helper belongs with the checkbox class core and should be emitted by UID `00011S`; the standalone by-item page [UID:0000U7] should become a no-duplicate-code route/proof page.
- Compiler adjustor thunks at `0x0049af27` and `0x0049af32` and scalar deleting wrapper `0x0049b110` should not be hand-authored in this target. The outside type-id helper `0x0049b8d0-0x0049b8d5` is source-authored and should be split/routed as a separate exact CheckBoxControlPane child if implementation scope permits.

Two evidence-backed caps remain:

- Current live MCP session `supervisor_recovery_20260705` reports raw names (`sub_499D40`, `sub_499EC0`, etc.) for the six methods. C001 notes are useful historical label proposals, but target/support docs should not call those labels current in this IDB unless a later safe IDA-label pass reapplies them.
- The inherited virtual at vtable slot `+0x20` is proven as a refresh/invalidate route used with `0` or `this+0x44`; its final source-facing name is still provisional.

## Supporting Research

Current artifact state: this report is post-implementation for UID `00011S` and is awaiting supervisor Gate 2 / execute-readiness review. The supervisor accepted the pre-callback report at SHA `E5A6593556354A79844B3BDCBC5793749545CF408D4F30F0777B532CBE81FE9C`; after that callback, B009 edited the accepted target/support by-* docs, ran scoped file validators, inspected generated freshness read-only, and updated this report ledger/checklist. No `execute_report`, dry-run/probing execute, registry lifecycle, archive, manual report move, manual generated edit, manual coverage edit, validator-state edit, or supervisor-ledger edit has been performed.

Historical/pre-callback state: during the original report-only Gate 1 pass, no target/support by-* docs had been edited from this report, generated output still held empty markers, and validators had not yet been run. Any report-only wording below is retained only as historical context when explicitly labeled pre-callback/pre-implementation.

Workflow/template basis used:

- Project-level `ntk-b-agent-workflow` skill.
- Current B-agent research/report template requirements, including exact provenance headers, required research headings, claim ledger shape, target/support change plan, first-draft C++ decision, and implementation tracking checklist.
- Historical supervisor instruction for the original report-only pass: GPT 5.5 xHigh report-only pass for `[UID:00011S]` with mandatory MCP evidence and no by-* implementation edits before Gate 1. Current state is after supervisor Gate 1 acceptance and after the implementation callback.

Current MCP evidence basis:

- Live IDA MCP session: `supervisor_recovery_20260705`.
- Database: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- Health: `status: ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.
- MCP checks used as current evidence: `lookup_funcs`, `xrefs_to`, `get_bytes`, `entity_query`, `analyze_function`, `decompile`, `disasm`, `search_text`, and `int_convert` over the checkbox core, vtable data, constructor/getter/setter call sites, resource strings, adjustor thunks, scalar deleting wrapper, and type-id helper.

Current local evidence checked before writing the recommendation:

- Target doc: `by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md`.
- Required support docs: `by-class/CheckBoxControlPane.md`, `by-file/CheckBoxControlPane.md`, `by-file/ButtonControlPane.md`, `by-type/by-struct/CheckBoxControlPaneLayout.md`, `by-type/by-vtable/CheckBoxControlPaneVtables.md`, `by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md`, `by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md`, `by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md`, `by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md`, and `by-global/g_pEPFLib.md`.
- Related call-site docs/leads: `by-file/MiniMap.md`, `by-class/NewMailDialog.md`, `by-memory/0x00450ca0-0x0045381b.MiniMapDialog.md`, and `by-memory/0x0047d050-0x0047e033.NewMailDialogCore.md`.
- Generated/read-only state: pre-callback `auto-generated/NexusTK/ui/controls/CheckBoxControlPane.cpp` routed UID `00011S` into `CheckBoxControlPane.cpp` with empty emitter markers only. Post-callback validator refresh now emits the UID `00011S` first-draft method bodies there and leaves UID `0000U7` as a no-standalone marker only; tracker/coverage generated reports were checked read-only.

Prior-report and notes search:

- Searches covered `executed-b-agent-research` and `tools/leaser/Agents` for `UID:00011S`, `00011S`, `CheckBoxControlPaneCore`, `0x00499d40`, `0x00499ec0`, `CheckBoxControlPane_StateTypeHelper`, `CheckBoxControlPane.cpp`, `ButtonControlPane.cpp`, and `ChoiceControlPane`.
- No executed B-agent report directly covering UID `00011S` was found. Prior materials are treated as leads only, not direct UID `00011S` coverage.
- Opened/used leads: C001 notes for historical checkbox label/support-score context, B003 `000118-ButtonChoiceControlCore-ownership-research.md` for broad ButtonChoice aggregate/source-family context, B010 ButtonControlPane empty-emitter notes for family route caveats, and neighboring RectangleControlPane reports for predecessor padding/source-quality comparison.

Historical caveats framing the report:

- Historical C001 notes say source-quality labels such as `CheckBoxControlPane_StateTypeHelper` were saved, but current MCP session `supervisor_recovery_20260705` reports raw function names (`sub_499D40`, `sub_499EC0`, etc.). This report therefore preserves C001 label evidence as historical/proposed naming context and rejects treating those labels as current live-IDB facts.
- The current validator-managed source route is `CheckBoxControlPane.cpp`; the broader `ButtonControlPane.cpp` family remains a historical original-source-layout caveat rather than a current implementation route change.
- The standalone by-item page for `0x00499ec0` is useful evidence but would duplicate target source if it emitted a separate helper body; the report recommends preserving it as support/no-duplicate evidence while emitting the body once through UID `00011S`.

## Target

- Target UID: `00011S`
- Target path: `by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md`
- Report path: `tools/leaser/Agents/Agent-B009/research/00011S-CheckBoxControlPaneCore-source-quality.md`
- Assignment lifecycle: originally report-only until supervisor Gate 1 acceptance; currently post-implementation callback and awaiting supervisor Gate 2 / execute-readiness review. No generated edits, coverage edits, validator-state edits, supervisor-ledger edits, `execute_report`, dry-run/probing execute, lifecycle, archive, or manual-move commands were performed.

## Current Target State

Pre-callback target metadata was `COMPLETION:86`, `CONFIDENCE:89`, `CANONICAL_OWNER:000021`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000021`, blank emitter position, and blank formal C++. That historical state explains the original score/source-quality recommendation.

Current post-implementation target metadata is `COMPLETION:89`, `CONFIDENCE:91`, `CANONICAL_OWNER:000021`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000021`, blank emitter position, and formal first-draft C++ applied for the six in-range methods. The by-item helper [UID:0000U7] now has a no-standalone/covered-by-UID00011S marker rather than a duplicate helper body.

Pre-callback generated output `auto-generated/NexusTK/ui/controls/CheckBoxControlPane.cpp` had validator header `000000007382`, refreshed `2026-07-05T20:06:27-04:00`, and contained empty emitter markers for [UID:000021], [UID:00011S], [UID:0002M9], [UID:0001TX], [UID:0001X8], and [UID:0000U7]. Current post-validator generated output has header `validator-command-id: 000000007399`, `validator-refreshed-at: 2026-07-05T21:42:39-04:00`, emits the UID `00011S` first-draft method bodies in `CheckBoxControlPane.cpp`, and emits only the UID `0000U7` no-standalone marker for the by-item helper page.

Tracker state at assignment was `86/89`, combined `87.5`, reconstructable `true`, reports `0`. Post-callback target-file validation reported the updated `89/91` metadata; supervisor execution remains pending.

## Heuristic / Inference Reanalysis And Validation

The target clears the active source-ready threshold because it is reconstructable, has a direct class owner/emitter, and has exact live MCP support for all in-range bodies and padding. The prior blank-C++ rationale was reasonable when source split, field names, helper classification, and destructor/type-id routing were unresolved. Current evidence narrows each issue:

- `m_tileName`, `m_paletteName`, `m_checkedFrame`, `m_uncheckedFrame`, and `m_checked` are exact for the target-owned layout fields.
- The inherited state byte at `+0x103` is source-authored behavior but its final inherited field name is provisional.
- The secondary mouse-handler view uses a `this+0xa0` subobject in Hex-Rays, but the toggled byte is still complete-object offset `+0x14c`.
- The `+0x20` virtual is shared by the mouse handler and state helper as a refresh/invalidate route. Do not preserve the older over-specific "owner callback" wording as a final source name.
- `0x00499ec0` is source-authored checkbox virtual behavior and should be emitted once, through UID `00011S`.
- Destruction wrappers/thunks are compiler output; type id `20` at `0x0049b8d0` is source-authored but outside this target range.

## Evidence Standards Used

- Live IDA MCP `server_health`, `lookup_funcs`, `xrefs_to`, `get_bytes`, `entity_query`, `analyze_function`, `decompile`, `disasm`, `search_text`, and `int_convert`.
- Current support docs: target, class/file roots, layout/vtable/vtable-data pages, state-helper item page, adjustor thunk page, destructor aggregate, `g_pEPFLib`, MiniMap/NewMail call-site docs, project source-tree notes, and generated C++.
- Prior report search across `executed-b-agent-research` and `tools/leaser/Agents` for `UID:00011S`, `00011S`, `CheckBoxControlPaneCore`, `0x00499d40`, `0x00499ec0`, and `CheckBoxControlPane_StateTypeHelper`.
- Existing docs and prior notes were treated as leads only. Current live MCP evidence is the authority where it contradicts older label/current-state wording.

## Evidence Checked

Live MCP session:

- Session: `supervisor_recovery_20260705`
- IDB: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Image base: `0x400000`
- Health: `status: ok`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, `strings_cache_size:2067`

Function inventory from `lookup_funcs`:

| Address | Live name | Size | Disposition |
| --- | --- | ---: | --- |
| `0x00499d40` | `sub_499D40` | `0x79` | constructor |
| `0x00499dc0` | `sub_499DC0` | `0x10` | `SetChecked` |
| `0x00499dd0` | `sub_499DD0` | `0x07` | `GetChecked` |
| `0x00499de0` | `sub_499DE0` | `0x4d` | secondary-view mouse handler |
| `0x00499e30` | `sub_499E30` | `0x90` | paint handler |
| `0x00499ec0` | `sub_499EC0` | `0x4e` | state/type refresh helper |
| `0x00499f10` | `sub_499F10` | `0x41` | successor outside target |
| `0x0049af27` | `sub_49AF27` | `0x0b` | adjustor thunk |
| `0x0049af32` | `sub_49AF32` | `0x0b` | adjustor thunk |
| `0x0049b110` | `sub_49B110` | `0x55` | scalar deleting wrapper |
| `0x0049b8d0` | `sub_49B8D0` | `0x05` | type id helper, returns `20` |

Xrefs:

- Constructor `0x00499d40`: code xrefs at `0x00450f60`, `0x0045100d`, and `0x0047d3b4`.
- Setter `0x00499dc0`: code xrefs at `0x00450f7e` and `0x0045102b`.
- Getter `0x00499dd0`: one code xref at `0x0047dfd0`.
- Mouse `0x00499de0`: one data xref from `0x00618544`.
- Paint `0x00499e30`: one data xref from `0x0061851c`.
- State helper `0x00499ec0`: one data xref from `0x00618520`.
- Type id `0x0049b8d0`: one data xref from `0x00618538`.
- Scalar deleting wrapper `0x0049b110`: code xrefs from `0x0049af2d` and `0x0049af38`, plus vtable slot `0x006184d8`.
- Vtable bases `0x006184d8`, `0x00618540`, and `0x00618570`: constructor stores at `0x00499d5d`, `0x00499d66`, `0x00499d70`; destructor restores at `0x0049b116`, `0x0049b11c`, `0x0049b126`.

Bytes and names:

- Padding `0x00499db9-0x00499dc0`: seven `0xcc` bytes.
- Padding `0x00499dd7-0x00499de0`: nine `0xcc` bytes.
- Padding `0x00499e2d-0x00499e30`: three `0xcc` bytes.
- Post-helper `0x00499f0e`: `0xcc 0xcc`; next function starts at `0x00499f10`.
- Vtable/RTTI bytes from `0x006184d4` decode to the documented primary RTTI locator, primary table, secondary RTTI/table, and tertiary RTTI/table through the tertiary slots.
- `entity_query` reports decorated names for `??_7CheckBoxControlPane@@6B@`, `??_7CheckBoxControlPane@@6B@_0`, `??_7CheckBoxControlPane@@6B@_1`, and related RTTI names, but function names in `0x00499d40-0x00499f10` remain raw `sub_...` names in this current IDB.

Decompilation summary:

- Constructor calls `sub_4949E0(this, 7, params)`, installs three CheckBoxControlPane vtables, clears `this+0x14c`, copies two `wchar_t[16]` buffers to `+0x108` and `+0x128`, and stores 16-bit frame ids at `+0x148` and `+0x14a`.
- `SetChecked` writes `this+0x14c`; `GetChecked` reads the same byte.
- Mouse handler checks event button `3`, hit-tests through `sub_4B76D0`, toggles the complete-object checked byte through the secondary view, calls the `+0x20` refresh virtual with `0`, then forwards to inherited mouse handling `sub_544DB0`.
- Paint clears/prepares draw state, calls a render/client callback, reads `dword_67A744` (`g_pEPFLib`), selects checked or unchecked frame id, calls `sub_4D02F0` with the tile name and frame id, then draws through `sub_4B9980` with the palette name.
- State helper reads inherited byte `+0x103`, special-cases requested type `0x14`/`20`, calls virtual slot `+0x20` with `0`, writes the state byte if still different, then calls the same virtual with `this+0x44`.
- Scalar deleting wrapper restores three vtable bases and calls inherited teardown/deallocation. It is compiler wrapper code, not a target-owned handwritten destructor body.
- Type id helper at `0x0049b8d0` is `mov al, 14h; retn 8`, source-authored class virtual behavior outside UID `00011S`.

Call-site/resource evidence:

- `decompile 0x00450ca0` shows MiniMap calls `sub_499D40(..., aOn, aBu, 1, 0)` twice, followed by `sub_499DC0` at `0x00450f7e` and `0x0045102b`.
- `decompile 0x0047d050` shows NewMail constructor call `sub_499D40(..., aOn, aBu, 1, 0)` at `0x0047d3b4`.
- `decompile 0x0047dcb0` shows NewMail send path calls `sub_499DD0` at `0x0047dfd0`.
- `get_bytes 0x006105f4` decodes UTF-16LE `ONOFFBUT.EPF`; `get_bytes 0x0060ddf8` decodes UTF-16LE `BUTTON.PAL`.

Prior-report search summary:

- Search terms used: `UID:00011S`, `00011S`, `CheckBoxControlPaneCore`, `0x00499d40`, `0x00499ec0`, `CheckBoxControlPane_StateTypeHelper`, `CheckBoxControlPane.cpp`, `ButtonControlPane.cpp`, and `ChoiceControlPane`.
- No executed B-agent report for exact UID `00011S` was found.
- Relevant leads found: C001 notes for the 2026-06-16 IDA/name refresh and accepted support-score update; B003 `000118-ButtonChoiceControlCore-ownership-research.md` for broad ButtonChoice aggregate/source-family context; B010 ButtonControlPane empty-emitter family support notes; B001/B005 RectangleControlPane neighbor reports for predecessor padding context.
- Historical C001 notes say `CheckBoxControlPane_StateTypeHelper` and sibling labels were saved. Current live MCP session does not show those function names, so this report treats them as historical label proposals/evidence, not current live-IDB names.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C1 | UID `00011S` is exactly six functions from `0x00499d40` through `0x00499f0e`. | High | MCP `lookup_funcs`, `get_bytes`, successor `0x00499f10`. | Target status/range inventory. | incorporate | applied |
| C2 | Padding gaps are `0x00499db9-0x00499dc0`, `0x00499dd7-0x00499de0`, `0x00499e2d-0x00499e30`, and post-helper padding begins at `0x00499f0e`. | High | MCP `get_bytes`. | Target range/split/padding section. | incorporate | applied |
| C3 | Constructor initializes a `ControlPane` with type `7`, installs three vtable bases, clears checked state, copies tile/palette strings into 16-wide-char buffers, and stores two frame ids. | High | MCP `analyze_function 0x00499d40`, vtable xrefs, string-byte reads. | Target C++/layout evidence; layout support page. | incorporate | applied |
| C4 | `SetChecked` and `GetChecked` operate on byte `+0x14c`; callers are two MiniMap setter calls and one NewMail getter call. | High | MCP `analyze_function`, `xrefs_to`, `search_text`, `decompile` call sites. | Target behavior; call-site evidence. | incorporate | applied |
| C5 | The mouse handler is a secondary-view method that toggles complete-object checked state and calls inherited virtual slot `+0x20` with `0`; do not final-name it as a proven owner callback. | High for behavior, medium-high for final name | MCP `analyze_function 0x00499de0`; same slot pattern in state helper. | Target behavior and negative evidence. | incorporate plus reject-stale owner-callback over-name | applied |
| C6 | Paint uses `g_pEPFLib`/`dword_67A744`, tile name at `+0x108`, palette name at `+0x128`, and checked/unchecked frame ids at `+0x148/+0x14a`; global ownership remains ImageLib, not CheckBoxControlPane. | High | MCP `analyze_function 0x00499e30`; `g_pEPFLib` support doc. | Target C++; file boundary notes. | incorporate | applied |
| C7 | `0x00499ec0` is source-authored CheckBoxControlPane virtual/helper behavior and should be emitted once through UID `00011S`. | High | MCP `lookup_funcs`, `xrefs_to 0x00499ec0`, `analyze_function`; vtable slot `0x00618520`. | Target formal C++; by-item support route. | incorporate | applied |
| C8 | [UID:0000U7] should not emit duplicate source for `0x00499ec0`; it should preserve evidence with a no-standalone/covered-by-UID00011S marker. | High | Duplicate exact address/range with target; pre-callback generated file listed both pages as empty markers, while post-callback generated output emits UID `00011S` body and UID `0000U7` marker only. | `by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md`. | historicalize / no-duplicate-code | applied |
| C9 | Adjustor thunks `0x0049af27` and `0x0049af32` and scalar deleting wrapper `0x0049b110` are compiler-generated lifecycle glue, not hand-authored target code. | High | MCP `disasm`, `analyze_function`, vtable xrefs; exact thunk page. | Target negative evidence; thunk/destructor support docs. | incorporate / not-applicable for target C++ | applied |
| C10 | Type-id helper `0x0049b8d0-0x0049b8d5` returns `20`, is source-authored class behavior, and should become a separate exact class child or explicit aggregate-routing note because it is outside UID `00011S`. | High for behavior, medium for child-creation scope | MCP `lookup_funcs`, `disasm`, `xrefs_to`; class/vtable docs. | `by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md` and possible new exact child. | incorporate | applied: routed as future exact-child note; child creation excluded |
| C11 | Current implementation route should remain class [UID:000021] -> file [UID:0000I7] -> `NexusTK/ui/controls/CheckBoxControlPane.cpp`. | Medium-high | Current target metadata, generated file, class/file docs, source-tree split candidate. | Target metadata/source placement; file support doc. | already-present plus incorporate | applied |
| C12 | Direct assignment to [UID:0000HY] `ButtonControlPane` is not needed now; keep it as family/historical-source context only. | Medium-high | ButtonControlPane docs, B003 report, current generated CheckBox file route. | Ranked ownership/source placement. | reject-invalid for direct owner | applied |
| C13 | Current live MCP function names are raw `sub_...`; older C001 saved-label wording should be preserved as historical, not stated as current live-IDB state. | High | MCP `lookup_funcs` and `entity_query` names. | Target/support evidence notes. | historicalize / reject-stale current-label wording | applied |
| C14 | Target is first-draft C++ ready with provisional inherited refresh and constructor-parameter type names. | Medium-high | Six decompiled bodies, field offsets, caller/resource evidence, route cleared. | Target formal C++ block. | incorporate | applied |
| C15 | Generated output should be refreshed only by validators after implementation; do not manually edit generated `CheckBoxControlPane.cpp`. | High | Pre-callback generated file was validator-owned and empty-marker only; post-callback validator refresh `000000007399` emitted the target body and no-standalone helper marker. | Implementation checklist and generated caveat. | not-applicable for manual generated edit | applied: validator refreshed generated output; no manual edit |

## Positive Evidence Summary

- Exact live function inventory matches the target doc's six-function range and sizes.
- Constructor, setter, getter, mouse, paint, and state helper are coherent class behavior over the same `0x150`-byte layout.
- Vtable data is decorated for `CheckBoxControlPane`, and constructor/destructor store refs line up across all three views.
- The call-site pattern is cross-feature reuse: MiniMap constructs/seeds two checkboxes; NewMail constructs one and later reads its state.
- Resource bytes prove the copied strings are `ONOFFBUT.EPF` and `BUTTON.PAL`; the second string is a palette/resource name, not a visible label.
- The source route is already represented in generated output as `NexusTK/ui/controls/CheckBoxControlPane.cpp`.
- Current evidence supports a real source body for `0x00499ec0`, correcting the generated omission.

## Negative Evidence Summary

- No live evidence supports moving UID `00011S` directly to `ButtonControlPane.cpp`; that file remains source-family context and a historical split caveat.
- No live evidence supports treating `g_pEPFLib` as owned by CheckBoxControlPane; it is a consumed ImageLib/ResourceLayout singleton.
- No live evidence supports hand-authoring the adjustor thunks or scalar deleting wrapper in the target C++.
- Current live MCP does not show the C001 function names as current IDB names. Do not state that `CheckBoxControlPane_StateTypeHelper` is the current saved live label without a new IDA label pass.
- The state helper's inherited `+0x20` virtual name and inherited state byte name remain provisional. Use a conservative refresh/invalidate name in first-draft C++.
- The by-item helper page is a duplicate exact address route if it emits a body. It should not emit another implementation of `0x00499ec0`.

## Ranked Ownership Analysis

1. [UID:000021] `CheckBoxControlPane` class owner: accepted.
Evidence: exact constructor/method bodies, decorated vtables/RTTI, layout fields, consumer calls, and current target metadata all support the class owner.

2. [UID:0000I7] `CheckBoxControlPane.cpp` file route: accepted for current implementation.
Evidence: existing class route, generated `CheckBoxControlPane.cpp`, project source-tree listing of `CheckBoxControlPane.cpp`, and class-specific source body. The possible historical fold into `ButtonControlPane.cpp` remains a confidence cap.

3. [UID:0000HY] `ButtonControlPane.cpp` direct route: rejected for UID `00011S` implementation.
Evidence for: broad button/choice family docs include checkbox behavior. Evidence against: UID `00011S` already has a stronger direct class owner and active generated route through `CheckBoxControlPane.cpp`; moving it would conflict with current generated placement.

4. [UID:0000U7] standalone helper owner for `0x00499ec0`: rejected for duplicate code.
Evidence: same exact address/range is contained in UID `00011S`; vtable slot belongs to `CheckBoxControlPane`; target can emit the helper once.

5. Generated/decompiler owner names: rejected as authority.
Evidence: pre-callback generated output had empty markers only and omitted the state helper body. Post-callback generated output is a validator-produced result of the by-* formal blocks, not independent ownership authority. Use live MCP and by-* ownership chain for the source decision.

## Source Placement

Recommended source placement for target implementation:

`[UID:00011S]` -> `[UID:000021] CheckBoxControlPane` -> `[UID:0000I7] CheckBoxControlPane` -> `NexusTK/ui/controls/CheckBoxControlPane.cpp`

Support text should state this as the current validator/source reconstruction route while preserving the historical-source caveat:

- `CheckBoxControlPane.cpp` is the current implementation route.
- `ButtonControlPane.cpp` or a future `ChoiceControlPane.cpp` remains plausible as historical organization, but current evidence does not justify rerouting UID `00011S`.
- Pre-callback generated `CheckBoxControlPane.cpp` listed UID `00011S` and was expected to gain the body only after scoped implementation validators. Post-callback validator refresh has done that: UID `00011S` now emits the first-draft body in `CheckBoxControlPane.cpp`.

## Range / Split / Padding / Reclassification Analysis

| Range | Disposition | Evidence |
| --- | --- | --- |
| `0x00499d40-0x00499db9` | constructor | MCP `lookup_funcs` size `0x79`; constructor decompile |
| `0x00499db9-0x00499dc0` | padding | seven `0xcc` bytes |
| `0x00499dc0-0x00499dd0` | `SetChecked` | MCP size `0x10`; writes `+0x14c` |
| `0x00499dd0-0x00499dd7` | `GetChecked` | MCP size `0x07`; reads `+0x14c` |
| `0x00499dd7-0x00499de0` | padding | nine `0xcc` bytes |
| `0x00499de0-0x00499e2d` | secondary-view mouse handler | MCP size `0x4d`; vtable slot `0x00618544` |
| `0x00499e2d-0x00499e30` | padding | three `0xcc` bytes |
| `0x00499e30-0x00499ec0` | paint handler | MCP size `0x90`; vtable slot `0x0061851c` |
| `0x00499ec0-0x00499f0e` | source-authored state/type helper | MCP size `0x4e`; vtable slot `0x00618520` |
| `0x00499f0e-0x00499f10` | post-target padding | `0xcc 0xcc`; successor `sub_499F10` |
| `0x0049af27-0x0049af3d` | adjustor thunks outside target | compiler glue, no target code |
| `0x0049b110-0x0049b165` | scalar deleting wrapper outside target | compiler glue, no target code |
| `0x0049b8d0-0x0049b8d5` | source-authored type-id helper outside target | should be separate exact child/support route |

## First-Draft C++ Recommendation

Recommended target formal block for UID `00011S`:

```cpp
CheckBoxControlPane::CheckBoxControlPane(ControlPaneCreateParams *params,
                                         const wchar_t *tileName,
                                         const wchar_t *paletteName,
                                         short checkedFrame,
                                         short uncheckedFrame)
    : ControlPane(7, params)
{
    m_checked = false;
    wcscpy_s(m_tileName, 0x10, tileName);
    wcscpy_s(m_paletteName, 0x10, paletteName);
    m_checkedFrame = checkedFrame;
    m_uncheckedFrame = uncheckedFrame;
}

void CheckBoxControlPane::SetChecked(bool checked)
{
    m_checked = checked;
}

bool CheckBoxControlPane::GetChecked() const
{
    return m_checked;
}

bool CheckBoxControlPane::OnMouse(ControlMouseEvent *event)
{
    if (event->button == 3 && HitTest(event->x, event->y)) {
        m_checked = !m_checked;
        RefreshControl(0);
    }

    return EventHandler::OnMouse(event);
}

void CheckBoxControlPane::OnPaint()
{
    Rect sourceRect;
    Rect drawRect;

    ClearTextColor(0);
    PrepareClientDraw(&m_clientRect);

    if (g_pEPFLib == 0) {
        return;
    }

    const short frameId = m_checked ? m_checkedFrame : m_uncheckedFrame;
    g_pEPFLib->LookupLayoutEntry(m_tileName, frameId, &sourceRect);
    DrawResourceFrame(&sourceRect, &drawRect, &m_clientRect, 0, m_paletteName, 0);
}

int CheckBoxControlPane::StateTypeHelper(unsigned char requestedType)
{
    unsigned char currentType = m_controlStateType;

    if (currentType != requestedType && requestedType == 20) {
        RefreshControl(0);
        currentType = m_controlStateType;
    }

    if (currentType != requestedType) {
        m_controlStateType = requestedType;
        return RefreshControl(&m_clientRect);
    }

    return currentType;
}
```

Provisional source-facing names that should be documented as caps, not final facts:

- `ControlPaneCreateParams`
- `ControlMouseEvent`
- `RefreshControl`
- `PrepareClientDraw`
- `DrawResourceFrame`
- `m_controlStateType`

Recommended separate type-id child formal code if supervisor permits an exact child for `0x0049b8d0-0x0049b8d5`:

```cpp
int CheckBoxControlPane::GetControlTypeId()
{
    return 20;
}
```

No destructor/thunk source should be inserted for UID `00011S`.

## Final Recommendation

UID `00011S` should remain implemented as first-draft source through the existing class/file route, with support docs carrying the no-duplicate helper disposition and stale current-label caveat.

Do not edit generated output manually. Do not move the target to `ButtonControlPane.cpp`. Do not hand-author scalar deleting destructor or adjustor thunk bodies.

## Score And Metadata Recommendation

Recommended target score: `89/91`.

Rationale:

- Completion improves because current evidence resolves exact method inventory, padding, field-shape, resource-string roles, state-helper classification, destructor/type-id routing, source placement, generated-output caveat, and first-draft C++ readiness.
- Confidence improves because live MCP independently confirms current bodies, xrefs, vtables, bytes, call sites, and string bytes.
- Confidence stays below final-audit range because original historical file grouping, exact inherited virtual names, exact inherited state byte name, and current IDA raw-label state remain capped.

Recommended unchanged metadata:

- `CANONICAL_OWNER:000021`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000021`
- blank `EMITTER_POSITION_OPTIONAL`

## Recommended Target Doc Changes

Accepted target edits for `by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md`, now applied:

- Score changed to `COMPLETION:89`, `CONFIDENCE:91`.
- Owner/emitter/reconstructable fields remained unchanged.
- Pre-callback blank formal C++ was replaced with the first-draft target block above.
- Status records the current implementation route as [UID:000021] -> [UID:0000I7] -> `NexusTK/ui/controls/CheckBoxControlPane.cpp`.
- Current MCP session `supervisor_recovery_20260705` and the live raw-name caveat were recorded.
- C001 historical label notes were preserved as historical, not current live-IDB labels.
- Exact range/padding table and successor `0x00499f10` were added.
- Mouse/state helper wording was corrected so virtual slot `+0x20` is a refresh/invalidate route with final name provisional, not a proven owner callback name.
- `0x00499ec0` was recorded as target-emitted source-authored helper behavior.
- Destructor/thunk exclusion and type-id child routing were recorded.
- Rejected alternatives were preserved: direct ButtonControlPane ownership, standalone by-item helper body, generated-output omission as authority, `g_pEPFLib` local ownership, hand-authored vtable/destructor/thunk code, and feature call-site ownership.

## Recommended Support Doc Changes

Accepted support edits and callback disposition:

| Support doc | Recommended change |
| --- | --- |
| `by-class/CheckBoxControlPane.md` | Add route/support note that UID `00011S` is first-draft ready and emits through the class into [UID:0000I7]. Add or preserve a class route marker only if validator routing requires `[[CHILDREN]]`; no independent class-wide body is recommended. |
| `by-file/CheckBoxControlPane.md` | State that `CheckBoxControlPane.cpp` is the current implementation route; keep possible `ButtonControlPane.cpp` fold as a historical-source caveat, not an implementation blocker. Add current MCP raw-label caveat. |
| `by-file/ButtonControlPane.md` | No default edit required unless supervisor wants the broader family inventory to mention that UID `00011S` now emits through the split-candidate CheckBox file while `ButtonControlPane.cpp` remains family context. |
| `by-type/by-struct/CheckBoxControlPaneLayout.md` | Optional support text: accepted source-facing field names are `m_tileName`, `m_paletteName`, `m_checkedFrame`, `m_uncheckedFrame`, and `m_checked`; inherited `+0x103` name remains provisional. |
| `by-type/by-vtable/CheckBoxControlPaneVtables.md` | Optional support text: state helper slot is now target-emitted through UID `00011S`; inherited slot names remain provisional. |
| `by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md` | Optional support text: preserve slot table and record current raw function names if updating current-MCP evidence. No vtable C++ body. |
| `by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md` | Required support repair: do not emit duplicate helper code. Add a no-standalone marker/comment that source body is covered by UID `00011S`, and keep evidence/history. |
| `by-memory/0x0049af27-0x0049af3d.CheckBoxControlPaneAdjustorThunks.md` | No change required; existing compiler-glue proof remains valid. |
| `by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md` | Add exact routing note for CheckBox: adjustor thunks/scalar deleting wrapper remain compiler-generated; `0x0049b8d0-0x0049b8d5` type-id helper is source-authored and should be split to a class-owned exact child if allowed. |
| New optional exact child | If supervisor permits new by-memory doc creation, create `0x0049b8d0-0x0049b8d5.CheckBoxControlPaneGetControlTypeId.md` under [UID:000021], emitting `return 20;`. |
| `by-global/g_pEPFLib.md` | No edit required; current global ownership already rejects local CheckBox ownership. |

## Open Questions With Attempted Resolution

| Question | Resolution |
| --- | --- |
| Should final implementation route be `CheckBoxControlPane.cpp` or `ButtonControlPane.cpp`? | Use `CheckBoxControlPane.cpp` for current implementation because target/class/generated route already points there. Keep `ButtonControlPane.cpp` as historical-source caveat only. |
| Is `0x00499ec0` standalone helper code? | No. It is source-authored class virtual behavior contained in UID `00011S`; emit it once in target and convert [UID:0000U7] to no-duplicate support/proof. |
| What is virtual slot `+0x20`? | It is proven to be an inherited refresh/invalidate style virtual called with `0` or `this+0x44`; exact final name remains capped. First-draft C++ may use `RefreshControl` with a caveat. |
| Are C001 labels current? | Not in the live MCP session used for this report. Preserve as historical label proposals; current MCP reports raw `sub_...` function names. |
| Should destructor/thunks be hand-authored? | No. Adjustor thunks and scalar deleting wrapper are compiler glue. |
| What about `GetControlTypeId`? | It is source-authored but outside target range. Split or route as a separate exact CheckBoxControlPane child; do not insert into UID `00011S`. |
| Do generated files need manual repair? | No. Generated output is validator-owned. Pre-callback it was empty-marker only; post-callback scoped validators refreshed it from by-* docs, and current `CheckBoxControlPane.cpp` contains UID `00011S` method bodies plus the UID `0000U7` no-standalone marker. |

## Validator Results

Implementation callback validators were run from `source-3/project-documentation` after by-* edits. No `execute_report`, dry-run/probing execute, registry lifecycle, manual report move, archive move, or manual generated/coverage edit was run.

| File | Command | command_id | command_timestamp | Exit | ok | Generated state |
| --- | --- | --- | --- | ---: | ---: | --- |
| `by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md` | `python .\tools\validator.py --mode file --file by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md --apply --queue-timeout 240 --wait-generated` | `000000007393` | `2026-07-05T21:41:48-04:00` | 0 | 1 | `generated_refresh: completed`; `CheckBoxControlPane.cpp` updated by validator |
| `by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md` | `python .\tools\validator.py --mode file --file by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md --apply --queue-timeout 240` | `000000007394` | `2026-07-05T21:42:11-04:00` | 0 | 1 | `generated_refresh: deferred` |
| `by-class/CheckBoxControlPane.md` | `python .\tools\validator.py --mode file --file by-class/CheckBoxControlPane.md --apply --queue-timeout 240` | `000000007395` | `2026-07-05T21:42:13-04:00` | 0 | 1 | `generated_refresh: deferred` |
| `by-file/CheckBoxControlPane.md` | `python .\tools\validator.py --mode file --file by-file/CheckBoxControlPane.md --apply --queue-timeout 240` | `000000007396` | `2026-07-05T21:42:15-04:00` | 0 | 1 | `generated_refresh: deferred` |
| `by-type/by-struct/CheckBoxControlPaneLayout.md` | `python .\tools\validator.py --mode file --file by-type/by-struct/CheckBoxControlPaneLayout.md --apply --queue-timeout 240` | `000000007397` | `2026-07-05T21:42:23-04:00` | 0 | 1 | `generated_refresh: deferred` |
| `by-type/by-vtable/CheckBoxControlPaneVtables.md` | `python .\tools\validator.py --mode file --file by-type/by-vtable/CheckBoxControlPaneVtables.md --apply --queue-timeout 240` | `000000007398` | `2026-07-05T21:42:31-04:00` | 0 | 1 | `generated_refresh: deferred` |
| `by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md` | `python .\tools\validator.py --mode file --file by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md --apply --queue-timeout 240` | `000000007399` | `2026-07-05T21:42:39-04:00` | 0 | 1 | `generated_refresh: deferred`; generated `CheckBoxControlPane.cpp` header refreshed to this command |
| `by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md` | `python .\tools\validator.py --mode file --file by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md --apply --queue-timeout 240` | `000000007400` | `2026-07-05T21:42:47-04:00` | 0 | 1 | `generated_refresh: deferred`; no direct `CheckBoxControlPane.cpp` body change expected from aggregate |

Read-only queue/freshness check:

- `python .\tools\validator.py --queue-status`: command_id `000000007401`, timestamp `2026-07-05T21:43:32-04:00`, queued jobs `0`, processing jobs `0`, queued generated refresh jobs `0`, processing generated refresh jobs `0`.
- `auto-generated/NexusTK/ui/controls/CheckBoxControlPane.cpp` read-only inspection: header `validator-command-id: 000000007399`, `validator-refreshed-at: 2026-07-05T21:42:39-04:00`, `validator-refresh-source: deferred-generated-refresh`.
- Generated file contains the UID `00011S` first-draft method bodies and the UID `0000U7` no-standalone marker. UID `0000U7` does not emit a duplicate `StateTypeHelper` body.

## Changed Files

Manual/report edits by B009:

- `by-memory/0x00499d40-0x00499f0e.CheckBoxControlPaneCore.md`
- `by-item/CheckBoxControlPaneStateTypeHelper_00499EC0.md`
- `by-class/CheckBoxControlPane.md`
- `by-file/CheckBoxControlPane.md`
- `by-type/by-struct/CheckBoxControlPaneLayout.md`
- `by-type/by-vtable/CheckBoxControlPaneVtables.md`
- `by-memory/0x006184d8-0x00618578.CheckBoxControlPaneVtableData.md`
- `by-memory/0x0049af11-0x0049b8d5.ButtonChoiceControlDestructors.md`
- `tools/leaser/Agents/Agent-B009/research/00011S-CheckBoxControlPaneCore-source-quality.md`

Validator-owned generated outputs refreshed as side effects of scoped validators, including `auto-generated/NexusTK/ui/controls/CheckBoxControlPane.cpp` and generated reports/metadata. These were not manually edited.

No manual `-coverage-report.md` edits, supervisor-ledger edits, validator-state edits, lifecycle/archive moves, or `execute_report` commands were performed.

## Implementation Tracking Checklist

| Item | Required implementation state | Callback status | Verification/proof |
| --- | --- | --- | --- |
| Supervisor Gate 1 before implementation | Wait for supervisor acceptance before by-* edits. | Applied. | Supervisor supplied Gate 1 pass for SHA `E5A6593556354A79844B3BDCBC5793749545CF408D4F30F0777B532CBE81FE9C` before callback edits. |
| Target doc update | Update UID `00011S` score, evidence, C++ block, source-placement, range/split, and caveats. | Applied. | Target now `89/91`, contains first-draft formal C++, current MCP evidence, range/padding table, source route, raw-label caveat, helper disposition, destructor/thunk exclusion, and type-id routing note. Validator `000000007393` ok. |
| Support docs to update | Apply required by-item no-duplicate repair and destructor/type-id routing; apply class/file route notes as accepted. | Applied. | Edited by-item, class, file, layout, vtable, vtable-data, and destructor aggregate support docs. Validators `000000007394`-`000000007400` ok. |
| Claim-ledger updates | Every accepted/rejected material claim should be reflected in target/support docs and report ledger. | Applied. | Ledger C1-C15 now records callback verification states. |
| Metadata/score | Target `89/91`, owner/emitter/reconstructable unchanged. | Applied. | Target header updated; validator `000000007393` reports completion/confidence updates. |
| Owner/emitter/reconstructable fields | Keep `CANONICAL_OWNER:000021`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000021`, blank position. | Applied. | Target metadata inspected after edit; no owner/emitter/reconstructable changes made. |
| Split/range/source-placement/IDA decisions | Six-function target; padding/successor exact; route through CheckBoxControlPane.cpp; current IDA function labels raw. | Applied. | Target/support docs include route and current raw-label caveat; generated C++ routes through `auto-generated/NexusTK/ui/controls/CheckBoxControlPane.cpp`. |
| First-draft C++ marker/no-code proof | Insert first-draft C++ in target; no destructor/thunk code; by-item helper no duplicate body. | Applied. | Target formal block emits six methods; by-item formal block emits no-standalone marker. Generated output contains UID00011S body and UID0000U7 marker only. |
| Third-party import | Not applicable. | Excluded with reason. | No third-party source import requested or needed. |
| Historical/rejected evidence preservation | Preserve C001/B003 leads as leads; reject stale current-label and owner-callback over-name claims. | Applied. | Target/class/file/layout/vtable docs preserve historical label context and current raw-label caveat; `+0x20` documented as inherited refresh/invalidate route. |
| Open questions | Resolve implementation route/helper classification; cap inherited slot/name and historical split questions. | Applied. | Route/helper classification resolved; inherited slot/state-byte names and historical source grouping remain evidence-backed caps. |
| Validators | Run scoped file validators for every changed by-* file. | Applied. | Validators `000000007393` through `000000007400`, all exit 0, all `ok:1`. |
| Generated-output check | Inspect `CheckBoxControlPane.cpp` read-only after validator refresh. | Applied. | Header `000000007399` / `2026-07-05T21:42:39-04:00`; UID00011S body present; UID0000U7 no-standalone marker present; no duplicate helper body. Queue status `000000007401` shows zero queued/processing generated jobs. |
| No manual coverage/tracker text | Do not edit coverage/tracker/generated state manually. | Applied. | Only scoped validators refreshed generated reports/metadata; no manual generated/coverage/tracker edits. |
| Lease handling | Lease only edited by-* docs immediately before edit and release after validation. | Applied with cleanup note. | Lease command succeeded for eight by-* files before edits. After validators, `unlease` reported `Rejected[No active lease]` for each file; current lease report shows no active B009 leases, only unrelated stale Supervisor rows. |
| Optional type-id child | Create exact `0x0049b8d0-0x0049b8d5` child only if safely in scope. | Excluded with reason. | Child creation was not necessary for this callback and would expand registry/validator scope; accepted facts were incorporated as future exact-child/routing notes in target/support docs. |

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000007410","destination_path":"executed-b-agent-research/B009/00011S-CheckBoxControlPaneCore-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/00011S-CheckBoxControlPaneCore-source-quality.md","timestamp":"2026-07-05T22:02:32-04:00","uid":"00011S"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
