** TARGET-REPORT-UID:0000NY **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0000NY SpecializedButtonPanes Empty-Emitter Family Source-Quality Report

## Finalized Report / Current Recommendation

- Assignment: report-only research for [UID:0000NY] `by-file/SpecializedButtonPanes.md` and the nine current empty emitters in `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp`.
- Current recommendation: keep the provisional source-family route [UID:0000NY] `NexusTK/ui/controls/SpecializedButtonPanes.cpp` for `GenderButtonControlPane`, `DirectionButtonControlPane`, and `CheckBoxTextControlPane`; preserve the object-image exclusion to [UID:0000M3][ObjectImageControlPane](../../../by-file/ObjectImageControlPane.md); insert formal C++ only for [UID:0002DZ] `CheckBoxTextControlPane::GetControlType()`.
- Metadata recommendation:
  - [UID:0000NY] file page: `86/88 -> 87/89`, path and `CANONICAL_OWNER:FILE` unchanged.
  - [UID:000022] `CheckBoxTextControlPane`: `85/87 -> 86/88`, owner/emitter unchanged, class formal C++ still blank.
  - [UID:0002DZ] `GetControlType`: `88/92 -> 91/94`, owner/emitter unchanged, formal C++ inserted.
  - [UID:00003X], [UID:00005P], [UID:0001W7], [UID:0001YW], [UID:0002OV], [UID:0002OW], and [UID:0002OX]: scores can remain unchanged; update wording/no-code proof only where stale.
- Generated state before callback edits: `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp`, header `validator-command-id: 000000001210`, `validator-refreshed-at: 2026-06-29T20:28:39-04:00`, listed nine empty markers. Callback validation produced header `validator-command-id: 000000001222`, `validator-refreshed-at: 2026-06-29T21:20:32-04:00`; UID0002DZ now emits `CheckBoxTextControlPane::GetControlType()`, and eight intentional class/vtable/layout empty markers remain.
- MCP session used for the original report evidence: `3fa0535f`, active IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`; `server_health` status `ok`, auto-analysis ready, Hex-Rays ready, strings cache ready. Implementation callback rechecked live MCP session `B005_00049P_20260629` for the same IDB and used that current session for the final UID0002DZ/body/resource proof.

## Target

- Primary target UID: `0000NY`
- Primary target path: `by-file/SpecializedButtonPanes.md`
- Generated file: `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp`
- Generated empty emitters in scope:

| UID | Path | Current score | Current generated marker disposition | Report recommendation |
| --- | --- | ---: | --- | --- |
| `000022` | `by-class/CheckBoxTextControlPane.md` | `85/87` | Empty class marker | Keep class C++ blank; update to `86/88` and sync that exact child UID0002DZ now emits. |
| `0002DZ` | `by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md` | `88/92` | Empty method marker | Insert formal C++; raise to `91/94`. |
| `0002OX` | `by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md` | `86/92` | Empty vtable-data marker | Keep blank with compiler-emitted no-code proof; fix stale Item Summary gate wording. |
| `00003X` | `by-class/DirectionButtonControlPane.md` | `88/89` | Empty class marker | Keep blank; exact Direction method children/splits required before method C++. |
| `0002OW` | `by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md` | `86/91` | Empty vtable-data marker | Keep blank with compiler-emitted no-code proof; fix stale Item Summary gate wording. |
| `00005P` | `by-class/GenderButtonControlPane.md` | `88/89` | Empty class marker | Keep blank; exact Gender method children/splits required before method C++. |
| `0002OV` | `by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md` | `86/91` | Empty vtable-data marker | Keep blank with compiler-emitted no-code proof; fix stale Item Summary gate wording. |
| `0001W7` | `by-type/by-struct/SpecializedButtonPaneLayouts.md` | `86/88` | Empty layout marker | Keep blank; layout names are evidence for member declarations, not safe standalone source yet. |
| `0001YW` | `by-type/by-vtable/SpecializedButtonPaneVtables.md` | `86/91` | Empty vtable-family marker | Keep blank; compiler regenerates vtables from final class declarations. |

## Current Target State

[UID:0000NY] is already the best current source-family route for the reusable specialized button controls. Its current docs correctly preserve three core decisions:

- `GenderButtonControlPane`, `DirectionButtonControlPane`, and `CheckBoxTextControlPane` remain under the provisional `NexusTK/ui/controls/SpecializedButtonPanes.cpp` bucket unless a later final source split creates `GenderButtonControlPane.cpp`, `DirectionButtonControlPane.cpp`, or `CheckBoxTextControlPane.cpp`.
- `ObjectImageButtonPane` is not part of this source family. Current docs and executed ObjectImage reports place it with [UID:0000M3][ObjectImageControlPane](../../../by-file/ObjectImageControlPane.md).
- The raw constructor-shaped starts `0x00500640`, `0x005007a0`, and `0x0059ded0` remain no-route/raw starts. They are useful source evidence, but not safe standalone formal code targets in the current class/type pages.

The family-level source-quality gap is narrower than the generated output suggests. Most empty markers are correct no-code markers for class declarations, vtable data, or layout support. One current marker, [UID:0002DZ], is a tiny exact source method with enough evidence for formal C++ now.

## Evidence Checked

Read gates and current files:

- `tools/leaser/Agents/Agent-B002/goal.md`.
- Project skill `ntk-b-agent-workflow` and `references/b-agent-research-and-implementation-workflow.md`.
- `references/score-blocker-audit-standard.md`.
- `by-structure.md` source-quality and C++ insertion rules, especially combined score/emitter gate and by-memory range-local C++ rule.
- Primary target [UID:0000NY] `by-file/SpecializedButtonPanes.md`.
- Current generated file `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp`.
- Current tracker rows in `auto-generated/-ag-research-tracker.md` and score context in `project-level/-auto-completion-stats.md`.

In-scope current empty-emitter docs:

- [UID:000022] `by-class/CheckBoxTextControlPane.md`.
- [UID:0002DZ] `by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md`.
- [UID:0002OX] `by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md`.
- [UID:00003X] `by-class/DirectionButtonControlPane.md`.
- [UID:0002OW] `by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md`.
- [UID:00005P] `by-class/GenderButtonControlPane.md`.
- [UID:0002OV] `by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md`.
- [UID:0001W7] `by-type/by-struct/SpecializedButtonPaneLayouts.md`.
- [UID:0001YW] `by-type/by-vtable/SpecializedButtonPaneVtables.md`.

Related support docs checked:

- [UID:00036V] `by-memory/0x00500640-0x005008c0.GenderDirectionButtonControlPaneMethods.md`.
- [UID:0003FH] `by-memory/0x0059e0b0-0x0059e0c0.CheckBoxTextControlPaneSetCheckedRaw.md`.
- [UID:0003FI] `by-memory/0x0059e0c0-0x0059e0c7.CheckBoxTextControlPaneGetChecked.md`.

Old report searches:

- Search terms used: `0000NY`, `SpecializedButtonPanes`, `CheckBoxTextControlPane`, `DirectionButtonControlPane`, `GenderButtonControlPane`, `ObjectImageButtonPane`, `0x004214c0`, `0x0062e998`, `0x0061dc30`, `0x0061db8c`, `0x00500640`, `0x005007a0`, `0x0059ded0`, `DIREC.EPD`, `GENDER.EPF`, `SetChecked`, and object-image ownership terms.
- Relevant reports opened/used as leads:
  - `executed-b-agent-research/B002/00005P-GenderButtonControlPane-class-source-quality.md`.
  - `executed-b-agent-research/B004/00003X-DirectionButtonControlPane-class-source-quality.md`.
  - `executed-b-agent-research/B009/0003FH-CheckBoxTextControlPaneSetCheckedRaw-source-quality.md`.
  - `executed-b-agent-research/B008/0001BU-ObjectImageControlPane-source-quality.md`.
  - `executed-b-agent-research/B015/0003M9-ObjectImageButtonPaneDestructorThunks-source-routing.md`.
  - `executed-b-agent-research/B002/0003MA-ObjectImageButtonPaneScalarDeletingDestructor-source-routing.md`.

MCP calls:

- `initialize`, `tools/list`, `idb_list`, `server_health`.
- `lookup_funcs` for `0x004214c0`, `0x004214c5`, `0x00500640`, `0x00500690`, `0x005006d0`, `0x00500700`, `0x005007a0`, `0x005007f0`, `0x00500820`, `0x005026a0`, `0x00502700`, `0x0059ded0`, `0x0059df30`, `0x0059df50`, `0x0059e0b0`, `0x0059e0c0`, `0x0059f050`, `0x0061db90`, `0x0061dc34`, and `0x0062e99c`.
- `decompile` / `analyze_function` for `0x004214c0`.
- `decompile` for `0x005006d0`, `0x00500700`, `0x005007f0`, `0x00500820`, and `0x0059e0c0`.
- `xrefs_to` for raw starts, modeled methods, vtable bases, resource strings, and key vtable slots.
- `get_bytes` for `0x004214bb`, `0x00500640`, `0x005007a0`, `0x0059ded0`, `0x0059e0b0`, `0x0061e528`, and `0x0061e540`.
- `get_string` for `0x0061e528` and `0x0061e540`. The `0x0061e528` string result returned only `"G"` due UTF-16 handling, so the direct byte decode is used for the full `GENDER.EPF` evidence.

## MCP Evidence Summary

Historical note: this section records the accepted report-only MCP evidence from session `3fa0535f`. The implementation callback did not use that stale session; it rechecked live MCP session `B005_00049P_20260629` and records that current proof in the callback ledger/checklist sections.

MCP session state:

- `idb_list`: active session `3fa0535f`, IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, `is_active:true`, `is_analyzing:false`, worker pid `16844`.
- `server_health`: status `ok`, module `NexusTK.exe`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready.

Function boundary facts:

| Address | MCP result | Meaning |
| --- | --- | --- |
| `0x004214c0` | `sub_4214C0`, size `0x5` | Exact control-type helper; code-ready. |
| `0x004214c5` | not a function | Exclusive end for UID0002DZ. |
| `0x00500640` | not a function | Gender raw constructor-shaped start remains no-route. |
| `0x00500690` | `sub_500690`, size `0x7` | Gender default-selected byte accessor, no xrefs. |
| `0x005006d0` | `sub_5006D0`, size `0x2f` | Gender state/visual-state override. |
| `0x00500700` | `sub_500700`, size `0x97` | Gender paint override. |
| `0x005007a0` | not a function | Direction raw constructor-shaped start remains no-route. |
| `0x005007f0` | `sub_5007F0`, size `0x2e` | Direction state/visual-state override. |
| `0x00500820` | `sub_500820`, size `0x99` | Direction paint override. |
| `0x0059ded0` | not a function | CheckBoxText raw constructor-shaped start remains raw. |
| `0x0059e0b0` | not a function | Raw setter start already accepted as source-ready UID0003FH, not one of the nine current markers. |
| `0x0059e0c0` | `sub_59E0C0`, size `0x7` | CheckBoxText checked getter, a future code candidate outside the nine current generated markers. |

UID0002DZ exact code facts:

- `decompile 0x004214c0` returns `char __stdcall sub_4214C0(int a1, int a2) { return 22; }`.
- `analyze_function 0x004214c0` reports no callees, no callers, and 12 data xrefs to vtable slots; one is `0x0062e9fc`, the `CheckBoxTextControlPane` primary control-type slot.
- `get_bytes 0x004214bb` shows `cc cc cc cc cc b0 16 c2 08 00 cc...`, proving five bytes of body after padding and before following padding.
- The source-facing return type should be `int` because the by-* docs model this as a control type virtual returning constant `0x16`; the decompiler's `char` return is an ABI-size artifact and does not change the semantic constant.

Gender/direction no-code and split facts:

- `xrefs_to 0x00500640`, `0x00500690`, and `0x005007a0` all return zero refs; current IDB still provides no live route to the raw constructor/accessor starts.
- `xrefs_to 0x005006d0`, `0x00500700`, `0x005007f0`, and `0x00500820` each return one data xref from the appropriate primary vtable slot:
  - `0x0061dbd8 -> 0x005006d0`
  - `0x0061dbd4 -> 0x00500700`
  - `0x0061dc7c -> 0x005007f0`
  - `0x0061dc78 -> 0x00500820`
- `decompile 0x005006d0`: compares inherited state byte `this+0x103`, writes `this+0x110 = 1` only for incoming state `0x0b`, then delegates to `0x00494b80`.
- `decompile 0x005007f0`: writes `this+0x110 = (state == 0x0b)` on state change, then delegates to `0x00494b80`.
- `decompile 0x00500700`: computes gender frame from `this+0x110 + 3 * this+0x10c`, uses resource pointer `0x0061e528`, and handles disabled overlay through shared render helpers.
- `decompile 0x00500820`: computes direction frame from `this+0x110 + 2 * this+0x10c`, uses `L"DIREC.EPD"` at `0x0061e540`, and handles disabled overlay through shared render helpers.
- `get_bytes 0x0061e528` decodes UTF-16LE `GENDER.EPF`; `get_bytes 0x0061e540` decodes UTF-16LE `DIREC.EPD`.
- `xrefs_to 0x0061e528` reports `0x00500741` inside gender paint plus four create-user related refs; `xrefs_to 0x0061e540` reports `0x00500861` inside direction paint plus two sibling create-user refs.

Vtable no-code facts:

- `xrefs_to 0x0061db90` returns four gender primary vtable store/reset refs: two `NewUserMiscDialogPane` inline setup refs, one raw constructor-shaped ref at `0x0050066f`, and one destructor reset at `0x00502706`.
- `xrefs_to 0x0061dc34` returns four direction primary vtable store/reset refs: two `NewUserMiscDialogPane` inline setup refs, one raw constructor-shaped ref at `0x005007bd`, and one destructor reset at `0x005026a6`.
- `xrefs_to 0x0062e99c` returns six checkbox primary vtable store/reset refs from user-list setup, raw constructor-shaped bytes, teardown helper, PartySearch inline setup, and scalar deleting destructor reset.
- These refs are class-layout evidence. They do not justify handwritten vtable dwords in formal C++.

Checkbox support facts:

- `decompile 0x0059e0c0` returns `this[264]`, i.e. `m_checked` at `+0x108`.
- `get_bytes 0x0059e0b0` returns the accepted setter body `55 8b ec 8a 45 08 88 81 08 01 00 00 5d c2 04 00`.
- [UID:0003FH] already emits `void CheckBoxTextControlPane::SetChecked(bool checked) { m_checked = checked; }`.
- [UID:0003FI] is a future exact getter code candidate, but it is not one of the nine current empty markers in `SpecializedButtonPanes.cpp`; do not silently expand this report's implementation scope to it unless the supervisor explicitly accepts that extra item.

## Positive Evidence

- [UID:0002DZ] has every source-entry prerequisite: `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000022`, valid route through [UID:000022] to [UID:0000NY], combined score `(88+92)/2 = 90`, exact five-byte body, no callees, vtable-only refs, and a current formal source name already documented by class/vtable pages.
- The `GetControlType` body is range-local and has no outside dependencies. Formal C++ would not include sibling method bodies, vtable data, raw constructor bytes, or class declarations.
- Gender and direction state/paint behaviors are real and well named, but they are not current generated empty markers as exact method children. They currently live inside [UID:00036V], a mixed Gender/Direction cluster, so the implementation-ready direction is exact child splitting before method C++.
- The three exact vtable-data pages [UID:0002OV], [UID:0002OW], and [UID:0002OX] are strong compiler-emitted evidence but should stay C++-blank.
- The type/layout pages [UID:0001W7] and [UID:0001YW] are useful support for field names, object sizes, and vtable slots, but their formal C++ should wait for final class/base declarations and accepted source split decisions.

## Negative Evidence

- No MCP xrefs exist to raw constructor starts `0x00500640`, `0x005007a0`, or `0x0059ded0`; treating class pages as ready for formal constructor declarations would overstate the route evidence.
- No ordinary code callers exist for [UID:0002DZ]; its xrefs are vtable data refs. That is normal for a virtual control-type helper and does not block a tiny method body, but it does mean the target doc should explain that this is a vtable-slot method, not a direct-call helper.
- `0x004fb630` remains `NewUserMiscDialogPane` construction/inline setup, not a Gender/Direction source owner.
- `GENDERBT.EPF` is stale for the checked binary. Current bytes and xrefs support `GENDER.EPF`.
- `ObjectImageButtonPane` has stronger source-family evidence under `ObjectImageControlPane`; no current evidence pulls it back into `SpecializedButtonPanes`.
- Vtable and RTTI-adjacent dwords are compiler-generated binary data. Hand-authoring them in `RECONSTRUCTION_CPP CODE` would violate the source-shape rule and duplicate what class declarations should regenerate.

## Ranked Ownership Analysis

### 1. Keep [UID:0000NY] SpecializedButtonPanes as provisional source-family root

- Evidence for: generated route exists; file page clears `86/88`; class pages [UID:000022], [UID:00003X], and [UID:00005P] already use [UID:0000NY] as owner/emitter; current generated file is exactly `NexusTK/ui/controls/SpecializedButtonPanes.cpp`.
- Evidence against: original source may have had separate files for each class.
- Decision: keep. The route is provisional but currently strongest and valid for the exact method child UID0002DZ.

### 2. Future split into per-class files

- Evidence for: class names are independent and source declarations may naturally live in `CheckBoxTextControlPane.cpp`, `DirectionButtonControlPane.cpp`, and `GenderButtonControlPane.cpp`.
- Evidence against: no original filename/source breadcrumb requires the split now; generated/project route already uses the family bucket.
- Decision: retain as a future option, not a current metadata change.

### 3. NewUserMiscDialogPane ownership for Gender/Direction

- Evidence for: inline setup writes Gender and Direction vtables/fields inside `NewUserMiscDialogPane`.
- Evidence against: those writes are consumer-side child construction/setup. The class methods and vtable data are reusable controls, and object allocations are for child controls.
- Decision: reject as source owner; preserve only as caller/setup evidence.

### 4. ObjectImageButtonPane inside SpecializedButtonPanes

- Evidence for: older generated output historically grouped object-image button under specialized button panes.
- Evidence against: current ObjectImage reports prove inheritance/calls through `ObjectImageControlPane`, with object-image descriptor rendering and sibling class ownership under [UID:0000M3].
- Decision: reject. Keep object-image code under `ObjectImageControlPane`.

### 5. No-owner/non-emitting family

- Evidence for: several class/type pages are still blank in generated output.
- Evidence against: parent route is already valid and one exact method child is code-ready; the blank markers are mostly due correct no-code/declaration-deferred pages, not lack of owner.
- Decision: reject for UID0000NY family as a whole.

## Source Placement

Keep source placement at `NexusTK/ui/controls/` through [UID:0000NY]. The exact generated filename `SpecializedButtonPanes.cpp` should continue to be described as a provisional bucket. Do not move gender/direction/checkbox source evidence into dialog files, generic `ControlPane`, `ButtonControlPane`, read-only-data aggregates, or object-image controls.

## Range / Split / Padding / Reclassification Analysis

No split is required for UID0002DZ. It is an exact five-byte function:

- `0x004214bb-0x004214c0`: `0xcc` padding.
- `0x004214c0-0x004214c5`: `b0 16 c2 08 00`, return `0x16`.
- `0x004214c5+`: padding before the next function island.

Split is required before gender/direction method C++ is inserted:

- [UID:00036V] currently spans `0x00500640-0x005008c0` and mixes Gender and Direction methods plus padding.
- Recommended exact future children if method code is accepted:
  - `0x00500640-0x00500690` `GenderButtonControlPaneConstructorRaw`, no-code/no-route constructor evidence unless route policy changes.
  - `0x00500690-0x00500697` `GenderButtonControlPaneIsDefaultSelected`, no-route accessor candidate.
  - `0x005006d0-0x005006ff` `GenderButtonControlPaneSetState`.
  - `0x00500700-0x00500797` `GenderButtonControlPaneOnPaint`.
  - `0x005007a0-0x005007f0` `DirectionButtonControlPaneConstructorRaw`, no-code/no-route constructor evidence unless route policy changes.
  - `0x005007f0-0x0050081e` `DirectionButtonControlPaneSetState`.
  - `0x00500820-0x005008b9` `DirectionButtonControlPaneOnPaint`.

No split is recommended for the vtable-data pages; they already have exact `.rdata` ranges.

## First-Draft C++ Recommendation / No-Code Proofs

### UID0002DZ Formal C++ Recommendation

Insert this exact formal `RECONSTRUCTION_CPP CODE` block into [UID:0002DZ]:

```cpp
int CheckBoxTextControlPane::GetControlType()
{
    return 0x16;
}
```

Reasoning:

- The raw body returns immediate `0x16` and performs no reads, writes, or calls.
- `int` is the best source-facing return type for a control-type virtual in the control-pane family; the decompiler's `char` return is ABI-sized output from a tiny function.
- The target's range is exact and does not include padding or sibling helpers.
- The method name is already the accepted class/vtable role and is clearly not the checked-state getter.

### UID000022 No-Code Proof

Keep class C++ blank. The class page is a declaration/support page whose method bodies belong in exact child pages. UID0003FH already emits `SetChecked`; UID0002DZ should emit `GetControlType`; constructor, paint, getter, teardown, and destructor children need separate exact source decisions. A class-level declaration is still blocked by raw constructor reachability, final base declaration quality, and final source split uncertainty.

### UID00003X No-Code Proof

Keep class C++ blank. Direction state and paint methods are behavior-ready, but they sit inside mixed [UID:00036V] rather than exact Direction-only children. The raw constructor at `0x005007a0` remains no-route. Do not paste method bodies or guessed class declarations into the class page.

### UID00005P No-Code Proof

Keep class C++ blank. Gender state and paint methods are behavior-ready, but they sit inside mixed [UID:00036V]. The raw constructor at `0x00500640` and accessor at `0x00500690` remain no-route, and the `ButtonControlPane` base declaration is not final enough for a class declaration block.

### UID0002OV / UID0002OW / UID0002OX No-Code Proof

Keep all three vtable-data pages blank. They document RTTI-adjacent and vtable dwords that must be regenerated from class declarations, virtual methods, destructors, and compiler ABI behavior. The implementation callback should update their stale summaries where they still say assignment was withheld due old parent-gate failures, but should not insert C++.

### UID0001W7 No-Code Proof

Keep layout C++ blank. The page records source-facing field names and offsets, but final declarations depend on inherited `ControlPane`/`ButtonControlPane` layout, per-class source split, and constructor/source declaration policy. Use it as support evidence for later class/method code.

### UID0001YW No-Code Proof

Keep vtable-family C++ blank. The page records slot targets and adjustor thunks; source should model class inheritance and virtual functions, not hard-code vtable arrays or thunk dwords.

### Out-Of-Scope Current Code Candidate

[UID:0003FI] `CheckBoxTextControlPaneGetChecked` is likely a future exact C++ candidate:

```cpp
bool CheckBoxTextControlPane::GetChecked() const
{
    return m_checked;
}
```

This is not recommended for this implementation callback unless the supervisor explicitly expands scope, because UID0003FI is not one of the nine current empty markers in `SpecializedButtonPanes.cpp`.

## Score And Metadata Recommendation

| UID | Recommended metadata | Rationale |
| --- | --- | --- |
| `0000NY` | `86/88 -> 87/89`; path and owner unchanged | Current MCP reconfirmed the family source route, exact empty-emitter inventory, object-image exclusion, no-route constructor starts, and one code-ready child. |
| `000022` | `85/87 -> 86/88`; owner/emitter unchanged; C++ blank | Class evidence improves after UID0002DZ source-ready decision and existing UID0003FH setter code; raw constructor/source split still caps score. |
| `0002DZ` | `88/92 -> 91/94`; owner/emitter unchanged; insert C++ | Empty-emitter blocker resolved with exact five-byte method body and vtable-slot role. |
| `0002OX` | unchanged `86/92`; C++ blank | Exact compiler-emitted vtable-data page; update stale Item Summary/gate wording only. |
| `00003X` | unchanged `88/89`; C++ blank | Prior B004 findings remain current; exact child split required before method code. |
| `0002OW` | unchanged `86/91`; C++ blank | Exact compiler-emitted vtable-data page; update stale Item Summary/gate wording only. |
| `00005P` | unchanged `88/89`; C++ blank | Prior B002 findings remain current; exact child split required before method code. |
| `0002OV` | unchanged `86/91`; C++ blank | Exact compiler-emitted vtable-data page; update stale Item Summary/gate wording only. |
| `0001W7` | unchanged `86/88`; C++ blank | Layout support is strong but not a safe formal declaration target. |
| `0001YW` | unchanged `86/91`; C++ blank | Vtable-family support is strong but no handwritten vtable code should be emitted. |

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | The family route [UID:0000NY] -> `NexusTK/ui/controls/SpecializedButtonPanes.cpp` remains the best current source route for Gender, Direction, and CheckBoxText controls. | High | Current file doc; generated file; original report session `3fa0535f`; callback session `B005_00049P_20260629`; class owners/emitters. | UID0000NY Status/File Role/Score Rationale | incorporate | applied |
| C02 | ObjectImageButtonPane must remain with ObjectImageControlPane, not SpecializedButtonPanes. | High | Current UID0000NY docs; executed B008/B015/B002 object-image reports. | UID0000NY Source Placement / Negative Evidence | already-present | already-present |
| C03 | UID0002DZ is source-ready and should emit `int CheckBoxTextControlPane::GetControlType(){ return 0x16; }`. | High | MCP decompile/bytes/xrefs; current target candidate; class/vtable docs. | UID0002DZ formal C++ and score | incorporate | applied |
| C04 | UID0002DZ is a control-type helper, not a checked-state accessor. | High | MCP return constant `22`; class docs; checked field at `+0x108` handled by UID0003FH/UID0003FI. | UID0002DZ Behavior; UID000022 notes | incorporate | applied |
| C05 | UID000022 class page should stay C++ blank even after UID0002DZ emits because class declarations and other method bodies belong to exact children or later source split. | Medium-high | Current class docs; raw constructor `NOFUNC`; by-structure range-local rule. | UID000022 Rebuild/C++ handling | incorporate | applied |
| C06 | UID00003X and UID00005P class pages should stay C++ blank until exact Gender/Direction method children or final class/base declarations are accepted. | High | Current class docs; MCP no-route raw constructors; [UID00036V] mixed cluster. | UID00003X/UID00005P C++ handling | already-present | already-present |
| C07 | Gender paint uses UTF-16 `GENDER.EPF`, not stale `GENDERBT.EPF`. | High | MCP bytes at `0x0061e528`; xrefs from `0x00500700`; B002 report. | UID0000NY/UID00005P/UID00036V/UID0001W7 sync | already-present plus sync | applied |
| C08 | Direction paint uses UTF-16 `DIREC.EPD`. | High | MCP bytes at `0x0061e540`; xrefs from `0x00500820`; B004 report. | UID0000NY/UID00003X/UID00036V/UID0001W7 sync | already-present plus sync | applied |
| C09 | Gender fields are `m_genderIndex`, `m_stateFrameOffset`, and inferred `m_defaultSelected`; Direction fields are `m_directionIndex` and `m_stateFrameOffset`; CheckBox fields are `m_checked` and `m_label[0x100]`. | Medium-high | Layout docs; MCP decompiles/bytes; executed B002/B004/B009. | UID0001W7 and class support | already-present plus sync | applied |
| C10 | UID0002OV/UID0002OW/UID0002OX are compiler-emitted vtable data and should not receive formal C++. | High | Current vtable-data docs; MCP xrefs to vtable bases; by-structure source-shape rule. | Three vtable-data docs Reconstruction Notes / Item Summary | incorporate | applied |
| C11 | UID0001YW should stay C++ blank because it is a vtable-family evidence page, not handwritten source. | High | Current vtable doc; exact vtable-data children; compiler-generated rule. | UID0001YW Reconstruction Notes | already-present | already-present |
| C12 | UID0001W7 should stay C++ blank because final class/base declarations and source split are still not accepted. | Medium-high | Current layout doc; MCP raw-start no-route checks; inherited field ownership caveats. | UID0001W7 Assignment Gate / Reconstruction Notes | already-present | already-present |
| C13 | [UID00036V] must be split before formal Gender/Direction method C++ is inserted. | High | Current mixed child doc; MCP modeled functions; raw constructor no-route starts; by-structure range-local C++ rule. | UID00036V support / UID0000NY split notes | already-present | already-present |
| C14 | Generated output after implementation should have UID0002DZ body and still-empty class/vtable/layout markers. | High | Current generated file and recommended C++/no-code split. | Generated freshness expectation | incorporate | applied |
| C15 | Current report-only pass took no leases, edited no by-* docs, and ran no validators. | High | Assignment mode and tool actions. | Report Validator/Changed Files sections | historicalize | applied |

## Callback Incorporation Proof

- C01 applied in [UID:0000NY] `by-file/SpecializedButtonPanes.md`: metadata now `87/89`, `Status` records live MCP session `B005_00049P_20260629`, the pre-edit nine-marker generated state, and the post-callback expectation that only UID0002DZ should emit.
- C02 already present at equal detail in [UID:0000NY] `Source Placement Decision`, `Proposed Contents`, `Evidence Notes`, and `Cross-References`, which keep `ObjectImageButtonPane` under [UID:0000M3] `ObjectImageControlPane`; no edit or validator needed for this claim beyond preserving it.
- C03 applied in [UID:0002DZ] `RECONSTRUCTION_CPP CODE`, metadata `91/94`, `Item Summary`, `Raw Code Evidence`, and `Changes`; validator `000000001219` updated generated output.
- C04 applied in [UID:0002DZ] `Behavior` / `Raw Code Evidence` and [UID:000022] `Class Purpose` / `Method Notes`; both distinguish control type `0x16` from `m_checked` getter/setter behavior.
- C05 applied in [UID:000022] `Rebuild handling`, `Method Notes`, `Evidence Notes`, `Score Rationale`, and `Changes`; the class formal C++ block remains blank and exact child pages carry method bodies.
- C06 already present at equal or greater detail in [UID:00003X] `Rebuild Handling` and `2026-06-20 B004 Source-Quality Reanalysis`, and [UID:00005P] `Rebuild Handling` / `Reconstruction Notes`; no edits or validators were run for those already-present rows.
- C07 applied/synced in [UID:0000NY] `Evidence Notes` using current `B005_00049P_20260629` bytes for UTF-16 `GENDER.EPF`; it was already present in [UID:00005P], [UID:00036V], and [UID:0001W7].
- C08 applied/synced in [UID:0000NY] `Evidence Notes` using current `B005_00049P_20260629` bytes for UTF-16 `DIREC.EPD`; it was already present in [UID:00003X], [UID:00036V], and [UID:0001W7].
- C09 applied/synced in [UID:0000NY] and [UID:000022]; the field names were already present at full detail in [UID:0001W7], [UID:00003X], [UID:00005P], and [UID:00036V].
- C10 applied in [UID:0002OV], [UID:0002OW], and [UID:0002OX] `Item Summary` lines; stale parent-gate/unassigned wording was removed and each summary now states compiler-emitted vtable data with blank formal C++.
- C11 already present in [UID:0001YW] `Reconstruction Notes`, `Evidence`, and `Score Rationale`: vtable data and adjustor thunks should be regenerated from class declarations, not hand-authored. No edit or validator needed.
- C12 already present in [UID:0001W7] `Assignment Gate`, `Score Rationale`, and layout evidence: fields support future declarations but inherited names, constructor reachability, and final source split still block standalone formal type C++. No edit or validator needed.
- C13 already present in [UID:00036V] `Covered Ranges`, `Assignment Gate`, and `Changes`: exact future child split ranges are recorded, and the mixed cluster remains non-emitting until split or a complete cluster-level plan is accepted. No edit or validator needed.
- C14 applied by validator-generated output: `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp` now has `validator-command-id: 000000001222`, `validator-refreshed-at: 2026-06-29T21:20:32-04:00`; UID0002DZ emits `CheckBoxTextControlPane::GetControlType()` and eight empty markers remain by design.
- C15 historicalized in this report: the report-only pass facts are retained as original state; callback sections below record the actual B002 leases, edits, validators, generated refresh, and side effects.

## Recommended Target And Support Doc Changes

Primary target [UID:0000NY] `by-file/SpecializedButtonPanes.md`:

- Raise `COMPLETION:86` to `87` and `CONFIDENCE:88` to `89`.
- Add a source-quality sync note that UID0002DZ is now ready to emit formal `CheckBoxTextControlPane::GetControlType()` while the other eight current generated markers are intentional no-code or declaration-deferred pages.
- Add current MCP session proof for UID0002DZ, raw constructor no-route starts, current `GENDER.EPF` / `DIREC.EPD` resources, vtable store refs, and object-image exclusion. Callback implementation used live session `B005_00049P_20260629`; the original accepted report's `3fa0535f` session is retained only as historical report provenance.
- Preserve the provisional bucket and future split caveats.

[UID:0002DZ] `by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md`:

- Raise `COMPLETION:88` to `91` and `CONFIDENCE:92` to `94`.
- Insert exact formal C++ from this report.
- Update Item Summary/Status to say the empty marker is repaired.
- Preserve owner [UID:000022], `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:000022`.

[UID:000022] `by-class/CheckBoxTextControlPane.md`:

- Raise `85/87` to `86/88`.
- Add source-quality sync: UID0002DZ emits `GetControlType`, UID0003FH already emits `SetChecked`, class C++ remains blank due raw constructor/final declaration/source split.

[UID:0002OX], [UID:0002OW], [UID:0002OV]:

- Fix stale Item Summary wording that still says assignment was withheld due parent-gate failure. Current pages are assigned to their class parents.
- Add or sharpen no-code proof: compiler-emitted `.rdata` regenerated from declarations, not hand-authored source.
- Keep scores and formal C++ blank.

[UID:00003X] and [UID:00005P]:

- Already present at same-or-greater detail: keep scores, owner/emitter, and formal C++ unchanged.
- Exact split policy before method C++ is already documented in the class pages and [UID00036V].

[UID:0001W7] and [UID:0001YW]:

- Already present at same-or-greater detail: layout/vtable docs support source declarations but should not emit standalone C++ now.
- Keep scores and formal C++ unchanged.

## Validator Results

Report-only pass: no validators run, no leases taken, no by-* docs edited.

Implementation callback validators from `E:\NTK\GhidraBridge\source-3\project-documentation`:

| Command | command_id | command_timestamp | Exit | ok | Notes |
| --- | --- | --- | ---: | ---: | --- |
| `python .\tools\validator.py --mode file --file by-file\SpecializedButtonPanes.md --apply --queue-timeout 240` | `000000001217` | `2026-06-29T21:20:10-04:00` | 0 | 1 | Applied UID0000NY completion/confidence updates; reported existing missing-ref UID diagnostics for stale/unregistered support UIDs; generated refresh deferred. |
| `python .\tools\validator.py --mode file --file by-class\CheckBoxTextControlPane.md --apply --queue-timeout 240` | `000000001218` | `2026-06-29T21:20:12-04:00` | 0 | 1 | Applied UID000022 completion/confidence updates; reported existing missing-ref UID diagnostics for support UIDs; generated refresh deferred. |
| `python .\tools\validator.py --mode file --file by-memory\0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md --apply --queue-timeout 240 --wait-generated` | `000000001219` | `2026-06-29T21:20:13-04:00` | 0 | 1 | Applied UID0002DZ `91/94` and C++ block; generated refresh completed; updated autogen registry hash/state from blank to block. |
| `python .\tools\validator.py --mode file --file by-memory\0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md --apply --queue-timeout 240` | `000000001220` | `2026-06-29T21:20:24-04:00` | 0 | 1 | Validator inserted generated UID link annotation for UID0002DZ in the `Item Summary`; generated refresh deferred. |
| `python .\tools\validator.py --mode file --file by-memory\0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md --apply --queue-timeout 240` | `000000001221` | `2026-06-29T21:20:26-04:00` | 0 | 1 | Stale Item Summary repaired; reported existing missing-ref UID diagnostics for UID00036W; generated refresh deferred. |
| `python .\tools\validator.py --mode file --file by-memory\0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md --apply --queue-timeout 240` | `000000001222` | `2026-06-29T21:20:32-04:00` | 0 | 1 | Stale Item Summary repaired; reported existing missing-ref UID diagnostics for UID00036X; generated refresh deferred. |

Generated/validator-owned side effects:

- `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp` updated by validator autogen, not by hand.
- `auto-generated/-ag-research-tracker.md` and `auto-generated/-ag-coverage-report-by-memory.md` were refreshed by validator-owned generated steps during command `000000001219`.
- `project-level/-auto-completion-stats.md` projected-path/stat sections were updated by validator commands.
- `tools/validator.ini` autogen registry was rebuilt/updated by command `000000001219`; this was a validator-owned side effect, not a manual edit.
- Validator backups were created under `tools/validator_autogen_backup/` by generated refresh.

Generated freshness result: `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp` now has `validator-command-id: 000000001222`, `validator-refreshed-at: 2026-06-29T21:20:32-04:00`, which is newer than UID0002DZ command `000000001219`. UID0002DZ no longer appears as an `Empty Emitter Marker` and emits `int CheckBoxTextControlPane::GetControlType() { return 0x16; }`. Remaining empty markers by design: UID000022, UID0002OX, UID00003X, UID0002OW, UID00005P, UID0002OV, UID0001W7, and UID0001YW.

## Changed Files

Callback-edited by-* docs:

- `by-file/SpecializedButtonPanes.md`
- `by-class/CheckBoxTextControlPane.md`
- `by-memory/0x004214c0-0x004214c5.CheckBoxTextControlPaneGetControlType.md`
- `by-memory/0x0062e998-0x0062ea3c.CheckBoxTextControlPaneVtableData.md`
- `by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md`
- `by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md`

Report/checklist updated:

- `tools/leaser/Agents/Agent-B002/research/0000NY-SpecializedButtonPanes-empty-emitter-family-source-quality.md`

Validator-owned generated side effects:

- `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`
- `project-level/-auto-completion-stats.md`
- `tools/validator.ini`
- `tools/validator_autogen_backup/...`

Already-present support docs not edited or validated in this callback: [UID00003X], [UID00005P], [UID0001W7], [UID0001YW], and [UID00036V]. Report execution: not performed. Supervisor should run the execute-report lifecycle only after verification.

## Implementation Tracking Checklist

Callback status:

- [x] Supervisor validation required before implementation. Proof: callback goal accepted this report and assigned implementation mode.
- [x] Target/support docs updated or marked already-present. Proof: edited UID0000NY, UID0002DZ, UID000022, UID0002OX, UID0002OW, and UID0002OV; UID00003X, UID00005P, UID0001W7, UID0001YW, and UID00036V were already present at same-or-greater detail as recorded in `Callback Incorporation Proof`.
- [x] Current generated state recorded. Proof: pre-edit generated header was `000000001210` / `2026-06-29T20:28:39-04:00` with nine empty markers; post-validator generated header is `000000001222` / `2026-06-29T21:20:32-04:00` with UID0002DZ emitted and eight empty markers remaining.
- [x] MCP evidence recorded. Proof: original report provenance retains session `3fa0535f`; implementation callback used live session `B005_00049P_20260629` (`server_health` ok, Hex-Rays ready, strings cache ready) and current `lookup_funcs`, `get_bytes`, and `analyze_function` proof for UID0002DZ, raw constructor starts, and `GENDER.EPF`/`DIREC.EPD`.
- [x] Claim And Incorporation Ledger updated. Proof: C01-C15 verification states are now `applied` or `already-present` with per-claim proof in `Callback Incorporation Proof`.
- [x] Metadata changes applied. Proof: UID0000NY `87/89` via validator `000000001217`; UID000022 `86/88` via validator `000000001218`; UID0002DZ `91/94` via validator `000000001219`; owner/emitter/reconstructable metadata unchanged.
- [x] First-draft C++ applied. Proof: UID0002DZ formal `RECONSTRUCTION_CPP CODE` now contains exact `int CheckBoxTextControlPane::GetControlType() { return 0x16; }`; generated output also emits it.
- [x] Target-specific no-code proofs applied/preserved. Proof: UID000022 edited to state class C++ remains blank for raw-constructor/declaration/source-split reasons; UID0002OV/UID0002OW/UID0002OX summaries now state compiler-emitted vtable data should be regenerated from declarations; UID00003X, UID00005P, UID0001W7, UID0001YW, and UID00036V already contain equal-or-greater no-code/split proof.
- [x] Stale vtable-data summaries corrected. Proof: UID0002OV/UID0002OW/UID0002OX `Item Summary` lines no longer say assignment is withheld due parent-gate failure and now point to their class parents/no-code rationale.
- [x] Object-image exclusion preserved. Proof: [UID0000NY] still routes `ObjectImageButtonPane` to [UID:0000M3] `ObjectImageControlPane`; no object-image code was added to this family.
- [x] Gender/Direction split policy preserved. Proof: [UID00036V] already records exact child ranges and no-partial-C++ policy; [UID00003X]/[UID00005P] already retain blank class C++ until exact children/final declarations are accepted.
- [x] Resource/name sync preserved. Proof: [UID0000NY] now records current `B005_00049P_20260629` bytes for UTF-16 `GENDER.EPF` and `DIREC.EPD`; class/layout pages already record `m_genderIndex`, `m_directionIndex`, `m_stateFrameOffset`, `m_defaultSelected`, `m_checked`, and `m_label[0x100]`.
- [x] UID0003FI out-of-scope note preserved. Proof: [UID000022] callback note states UID0003FI `GetChecked` remains outside this callback's code scope; no code was added for it.
- [x] Validators run. Proof: commands `000000001217` through `000000001222` all exited `0` with `ok: 1`; UID0002DZ used `--wait-generated`.
- [x] Generated output checked. Proof: `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp` has UID0002DZ body, no UID0002DZ empty marker, and eight remaining empty markers by design.
- [x] Manual edit exclusions honored. Proof: no generated files, generated reports, manual coverage reports, validator/tool state, lock files, IDA DB, executed archives, supervisor ledgers, or by-project-structure files were manually edited. Validator-owned generated/tool-state side effects are listed under `Validator Results`.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0000NY-SpecializedButtonPanes-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B002/research/0000NY-SpecializedButtonPanes-empty-emitter-family-source-quality.md","timestamp":"2026-06-29T21:26:42","uid":"0000NY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
