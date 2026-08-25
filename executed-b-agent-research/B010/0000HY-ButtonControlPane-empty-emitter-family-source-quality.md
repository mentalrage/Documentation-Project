** TARGET-REPORT-UID:0000HY **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000HY] ButtonControlPane Empty-Emitter Family Source-Quality Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0000HY] `by-file/ButtonControlPane.md` as the current generated source root for `NexusTK/ui/controls/ButtonControlPane.cpp`, but replace all fifteen current empty emitters with implementation-ready formal blocks: class/type route markers with `[[CHILDREN]]`, first-draft method C++ where source bodies are proven, and exact no-code comments for compiler-generated wrappers or unreferenced raw helper islands.
- Final disposition: no owner/emitter/source-file split changes are required in this report-only pass. The direct class/file route is already correct; the defect is that several eligible pages still emit blank markers or use obsolete "below 95/95" gate rationale.
- Required action after supervisor validation: update only the listed target/support by-* docs, preserve this report's evidence at report-level detail, run scoped validators for every touched by-* file, and let validator-owned generated output refresh `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp`.
- Confidence: high for current MCP-backed boundaries, caller/xref status, source-family ownership, and compiler-glue classification; medium-high for final original class-declaration spellings in the broad class pages.

## Target

- Target UID: `0000HY`
- Target path: `by-file/ButtonControlPane.md`
- Queue row: `auto-generated/-ag-research-tracker.md` -> `## Files With Empty Emitters`, row `[UID:0000HY] ButtonControlPane`, `Total Emitters: 17`, `Filled: 2`, `Marked Empty: 15`, `Complete: 11.8%`, generated file `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp`.
- Current generated freshness checked: `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp`, validator command id `000000002912`, refreshed `2026-06-30T14:25:13-04:00`.
- Current target metadata: `COMPLETION:86`, `CONFIDENCE:88`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/"`, `CANONICAL_OWNER:FILE`.

## Current Target State

- Existing owner/emitter state: [UID:0000HY] is the by-file root. Empty emitters are routed through class/memory/type pages that already point back into this file route through class parents.
- Existing generated C++ state: only [UID:0000CQ] `SelectBoxControlPane` declaration and [UID:00019V] `SelectBoxControlPane` method bodies are filled. The following fifteen emitters are empty and are fully inventoried below: `00001E`, `00006D`, `0002XZ`, `0000BI`, `00011E`, `0002YC`, `0002XW`, `0000CR`, `00011D`, `0001SV`, `0000DB`, `0002Y3`, `000223`, `0000EK`, `0002Y7`.
- Main stale rationale found: several support docs still say C++ is blank because of the old `95/95` rule or because names are not final. Under the active rule, each eligible emitter needs formal C++ or a target-specific no-code proof.
- Related pages checked: all fifteen empty-emitter pages, [UID:0000HY], [UID:000118] `ButtonChoiceControlCore`, [UID:00011Y] `ButtonChoiceControlDestructors`, [UID:0000CQ] `SelectBoxControlPane`, current generated C++ output, tracker row, and relevant executed B reports.

## Evidence Checked

- IDA MCP session: `supervisor_resume_20260629`, active worker for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`.
- MCP availability: `idb_list` returned one active worker, `server_health` returned `status:"ok"`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`, module `NexusTK.exe`, imagebase `0x400000`.
- MCP tools used with database-scoped schema: `lookup_funcs`, `server_health`, `analyze_function`, `analyze_component`, `xrefs_to`, and `make_signature_for_range`.
- Current MCP lookup facts: `0x00494eb0 sub_494EB0 size 0x88`, `0x00495bf0 sub_495BF0 size 0xb5`, `0x0049b290 sub_49B290 size 0x55`, `0x00495f70 sub_495F70 size 0x52`, `0x004964a0 not a function`, `0x0049b420 sub_49B420 size 0x67`, `0x0049b0d0 sub_49B0D0 size 0x3b`, `0x00495cb0 sub_495CB0 size 0x19`, `0x00496630 sub_496630 size 0x181`, `0x0049b5b0 sub_49B5B0 size 0x3b`, `0x0049b930 sub_49B930 size 0x3b`, `0x00495450 sub_495450 size 0x18c`, `0x0049b860 sub_49B860 size 0x67`, `0x004fccf0 sub_4FCCF0 size 0x78`.
- Old-report search terms: `0000HY`, `ButtonControlPane`, all fifteen UIDs, `004964a0`, `0049b930`, `0049b860`, `00495cb0`, `ImageButtonControlPaneScalar`, `RadioGroupControlPane`, `SliderControlPane`, `TextButtonExControlPane`.
- Opened relevant executed reports: B001 `0002XV-0002Y6-ui-control-adjustor-thunk-source-quality.md`, B010 `0003N8-ButtonControlPaneActiveRefreshHelper-source-quality.md`, B007 `0003NC-TextButtonExControlPaneLabelBoundsRawHelpers-source-quality.md`, B002 `00019V-SelectBoxControlPane-source-quality.md`.
- Negative checks: current MCP `xrefs_to` still reports no xrefs to raw radio helper starts `0x004964a0`, `0x004964b0`, `0x004964c0`, or `0x004964e0`; only `0x00496620` jump table has a local data xref from `0x00496525`.

## Positive Evidence Summary

- [UID:0000HY] is the right current source route. The file page, proposed source tree, and exact class pages consistently place `ButtonControlPane`, `ImageButtonControlPane`, `RadioGroupControlPane`, `SliderControlPane`, `SelectionControlPane`, `TextButtonExControlPane`, and `SelectBoxControlPane` under the generic button/choice-control source family.
- Source-authored method bodies now safe to emit:
  - [UID:00011D] `0x00495cb0-0x00495cc9`: MCP decompiles a one-block setter that writes `this[67]`, offset `+0x10c`, and tail-calls vtable slot `+0x20` with argument `0`; sole caller is `sub_52A180`.
  - [UID:000223] `0x0049b930-0x0049ba2b`: MCP confirms four exact `0x3b` one-block slider offset helpers. Each manipulates `this+0xfa`/`this+0xfc`, has callers only from `SliderControlPane::OnKey` and `SliderControlPane::ProcessScrollInput`, then calls vtable slot `+0x20`.
- No-code/marker targets now have exact proof:
  - [UID:00011E] is source-authored raw radio helper code, but current MCP still finds no function objects or inbound xrefs to any helper start; the live `RadioGroupControlPane::OnPaint` body at `0x00496300` already has the vtable route and option-rendering loop.
  - Scalar deleting destructors [UID:0002XZ], [UID:0002YC], [UID:0002XW], [UID:0002Y3], and [UID:0002Y7] have only adjustor-thunk and vtable/data xrefs and are source-declared/generated-binary ABI wrappers, not handwritten source bodies.
  - Class/type pages are route/declaration pages. Where full declarations remain unsafe, their formal output must be a comment plus `[[CHILDREN]]`, so child emitters are not stranded and no decompiler-shaped broad class declaration is fabricated.

## Negative Evidence Summary

- No current evidence supports moving this family to NewUser, MusicControlDialog, FittingRoom, TextButton-only, GrafPort, or PopupMenu owners. Those are consumers, dependencies, or previously documented generated-owner pollution.
- No current evidence supports manually writing MSVC scalar deleting destructor wrapper bodies. The wrappers are reached from vtables/adjustor thunks and should be regenerated from class declarations/destructors.
- No current evidence supports emitting [UID:00011E] raw helper bodies as callable functions. The raw bytes are source-shaped, but no call/vtable/pointer route to the helper starts is recovered in current MCP.
- No current evidence supports a new source file or split during this report. A later `ChoiceControlPane.cpp`, `SliderControlPane.cpp`, or narrower text-button split remains plausible source-tree refinement, but it is not needed to resolve the current empty emitters.

## Heuristic / Inference Reanalysis And Validation

- Active code-entry rule applied: all fifteen pages clear or route through pages that clear `(completion + confidence) / 2 > 85`, so blank formal blocks need either source C++ or exact no-code proof. The old "below 95/95" rationale is stale.
- Broad class declarations: first-draft class declarations for `ImageButtonControlPane`, `RadioGroupControlPane`, `SliderControlPane`, and `TextButtonExControlPane` would require constructor signatures, full field maps, inherited subobject layout, and many method names that remain partly descriptive. Because their exact source-bearing method bodies are in class/memory children or unresolved broad bands, formal route comments plus `[[CHILDREN]]` are safer than inventing incomplete header declarations.
- Selection control: unlike broad class pages, [UID:0000CR] can receive a minimal declaration seed because [UID:00011D] and [UID:0001SV] prove exactly one field and one setter. The base class remains inferred, so the declaration must be explicitly first-draft and preserve offset evidence.
- Slider helpers: helper names remain inferred, but the bodies are small, fully modeled, directly called by slider methods, and can be expressed source-shaped without raw temporaries.
- Radio raw island: source-authored bytes alone are not enough. The absence of function objects and start xrefs after current MCP recheck is an exact blocker to formal body emission, so the implementation-ready disposition is a formal no-code comment that records the retained raw/no-route proof.

## Function / Child Inventory

| UID | Path | Current score | Role | Current owner/emitter | Recommendation |
| --- | --- | ---: | --- | --- | --- |
| `00001E` | `by-class/ButtonControlPane.md` | `85/88` | Base clickable button class | owner/emitter `0000HY` | Add formal class-route no-code comment; no owner change; recommend `87/89`. |
| `00006D` | `by-class/ImageButtonControlPane.md` | `85/88` | Generic image button class | owner/emitter `0000HY` | Add formal route comment plus `[[CHILDREN]]`; recommend `87/89`. |
| `0002XZ` | `by-memory/...ImageButtonControlPaneScalarDeletingDestructor.md` | `85/88` | MSVC scalar deleting wrapper | owner/emitter `00006D` | Add exact no-code compiler-wrapper comment; recommend `86/89`. |
| `0000BI` | `by-class/RadioGroupControlPane.md` | `85/87` | Radio option group class | owner/emitter `0000HY` | Add formal route comment plus `[[CHILDREN]]`; recommend `87/89`. |
| `00011E` | `by-memory/...RadioGroupControlPaneOptionHelpers.md` | `85/88` | Raw option helper island | owner/emitter `0000BI` | Add no-route no-code comment; recommend `86/89`. |
| `0002YC` | `by-memory/...RadioGroupControlPaneScalarDeletingDestructor.md` | `86/88` | MSVC scalar deleting wrapper | owner/emitter `0000BI` | Add exact no-code compiler-wrapper comment; recommend `87/89`. |
| `0002XW` | `by-memory/...SelectBoxControlPaneScalarDeletingDestructor.md` | `86/88` | Shared scalar deleting wrapper | owner/emitter `0000CQ` | Add exact shared-wrapper no-code comment; recommend `87/89`. |
| `0000CR` | `by-class/SelectionControlPane.md` | `85/87` | Tiny selection helper declaration | owner/emitter `0000HY` | Add minimal declaration plus `[[CHILDREN]]`; recommend `88/90`. |
| `00011D` | `by-memory/...SelectionControlPaneSetSelectionAndRefresh.md` | `85/90` | Proven setter body | owner/emitter `0000CR` | Add first-draft method C++; recommend `88/91`. |
| `0001SV` | `by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md` | `86/90` | Field evidence | owner/emitter `0000CR` | Add covered-by-class no-code comment; recommend `87/91`. |
| `0000DB` | `by-class/SliderControlPane.md` | `86/86` | SCRL001 slider class | owner/emitter `0000HY` | Add minimal declaration/route plus `[[CHILDREN]]`; recommend `88/89`. |
| `0002Y3` | `by-memory/...SliderControlPaneScalarDeletingDestructor.md` | `86/88` | MSVC scalar deleting wrapper | owner/emitter `0000DB` | Add exact no-code compiler-wrapper comment; recommend `87/89`. |
| `000223` | `by-memory/...SliderControlPaneScrollOffsetHelpers.md` | `85/88` | Four proven slider helper bodies | owner/emitter `0000DB` | Add first-draft method C++; recommend `88/90`. |
| `0000EK` | `by-class/TextButtonExControlPane.md` | `87/88` | Extended text button class | owner/emitter `0000HY` | Add formal route comment plus `[[CHILDREN]]`; recommend `88/89`. |
| `0002Y7` | `by-memory/...TextButtonExControlPaneScalarDeletingDestructor.md` | `86/88` | MSVC scalar deleting wrapper | owner/emitter `0000EK` | Add exact no-code compiler-wrapper comment; recommend `87/89`. |

## Ranked Ownership And Source Placement

### 1. Keep [UID:0000HY] `ButtonControlPane.cpp` As Current File Route

- Evidence for: target file page already documents the reusable button/choice-control family, exact child links, source projection `NexusTK/ui/controls/`, and exclusions. Current MCP rechecks agree with exact method/function boundaries in this family.
- Evidence against: original-source split may later become `ChoiceControlPane.cpp`, `SliderControlPane.cpp`, or narrower text-button files.
- Decision: keep current route. Later split remains out of scope and unsupported as a current owner/emitter change.

### 2. Direct Class Owners For Child Memory/Type Pages

- Evidence for: scalar destructors and helper bodies are class-specific or route through class pages; current metadata already reflects direct class owners.
- Evidence against: [UID:0002XW] is shared by several primary vtable cells, so its SelectBox title is narrow.
- Decision: keep current metadata for implementation stability, but document [UID:0002XW] as shared ButtonControlPane/SelectBox/Weather/Raining ABI glue and not exclusive SelectBox source.

### 3. New Source File Or Owner Split

- Evidence for: `SliderControlPane` and `SelectBoxControlPane` could plausibly have narrower original files.
- Evidence against: no current MCP or project-structure evidence requires a split, and splitting now would be unrelated to clearing empty emitters.
- Decision: reject for this callback.

## First-Draft C++ And Formal Marker Dispositions

All code below is exact formal `RECONSTRUCTION_CPP CODE` insertion text recommended for the named page if the report is accepted.

### [UID:00001E] `ButtonControlPane`

```cpp
// ButtonControlPane is the base button/choice-control declaration route for
// exact child methods in this source family. Do not emit a broad class
// declaration here until the inherited subobject layout and button-state field
// names are source-quality.
```

Rationale: current docs prove constructor/state/key/destructor behavior, but final class declaration and field names remain broader than this empty-emitter audit. This formal comment removes the empty marker without inventing a partial class body.

### [UID:00006D] `ImageButtonControlPane`

```cpp
// ImageButtonControlPane source is represented by exact method/destructor
// children until the constructor signature and image-button field names are
// source-quality enough for a class declaration.
[[CHILDREN]]
```

### [UID:0002XZ] `ImageButtonControlPaneScalarDeletingDestructor`

```cpp
// MSVC scalar deleting destructor wrapper for ImageButtonControlPane.
// Generated from the class destructor/vtable layout; do not hand-author this
// wrapper as source.
```

### [UID:0000BI] `RadioGroupControlPane`

```cpp
// RadioGroupControlPane class source routes through exact option, paint,
// helper, and destructor children. The full declaration is intentionally
// withheld until option-list field names and source split are final-source
// quality.
[[CHILDREN]]
```

### [UID:00011E] `RadioGroupControlPaneOptionHelpers`

```cpp
// Raw RadioGroupControlPane option-helper island at 0x004964a0-0x0049662f is
// source-authored but has no recovered call, vtable, or pointer route in the
// current IDB. The live RadioGroupControlPane::OnPaint body at 0x00496300 owns
// the reachable option-render loop; do not emit standalone helper bodies from
// this raw island until a route or retained-helper source policy is proven.
```

### [UID:0002YC] `RadioGroupControlPaneScalarDeletingDestructor`

```cpp
// MSVC scalar deleting destructor wrapper for RadioGroupControlPane.
// Generated from the class destructor/vtable layout; do not hand-author this
// wrapper as source.
```

### [UID:0002XW] `SelectBoxControlPaneScalarDeletingDestructor`

```cpp
// Shared MSVC scalar deleting destructor wrapper used by ButtonControlPane,
// SelectBoxControlPane, WeatherLayerPane, and RainingLayerPane compatible
// vtable layouts. Generated from class destructor declarations; do not
// hand-author this wrapper as SelectBoxControlPane source.
```

### [UID:0000CR] `SelectionControlPane`

```cpp
class SelectionControlPane : public ImageButtonControlPane
{
public:
    void SetSelectionAndRefresh(int selectedValue);

private:
    int m_selectedValue; // +0x10c, selected image/frame/value id
};

[[CHILDREN]]
```

Note: `ImageButtonControlPane` is the best current base inference from the local image-button/selection-control band and generic control usage. The implementation must keep the offset comment and evidence caveat because no constructor/vtable block for a standalone SelectionControlPane is proven.

### [UID:00011D] `SelectionControlPaneSetSelectionAndRefresh`

```cpp
void SelectionControlPane::SetSelectionAndRefresh(int selectedValue)
{
    m_selectedValue = selectedValue;
    InvalidateRect(NULL);
}
```

Behavior proof: current MCP decompile is `this[67] = a2; return (*(*this + 32))(this, 0);`; `this[67]` is offset `+0x10c` and slot `+0x20` is the invalidation/refresh virtual used by sibling controls.

### [UID:0001SV] `SelectionControlPaneSelectedValue_0x10c`

```cpp
// SelectionControlPane selected-value storage at +0x10c is declared by
// [UID:0000CR] SelectionControlPane and written by [UID:00011D]
// SetSelectionAndRefresh. This field-evidence page has no standalone source
// object to emit.
```

### [UID:0000DB] `SliderControlPane`

```cpp
class SliderControlPane : public ControlPane
{
private:
    short m_currentValue; // +0xfa
    short m_maximumValue; // +0xfc

    void ScrollLineBackward();
    void ScrollPageForward();
    void ScrollPageBackward();
    void ScrollLineForward();
};

[[CHILDREN]]
```

### [UID:0002Y3] `SliderControlPaneScalarDeletingDestructor`

```cpp
// MSVC scalar deleting destructor wrapper for SliderControlPane.
// Generated from the class destructor/vtable layout; do not hand-author this
// wrapper as source.
```

### [UID:000223] `SliderControlPaneScrollOffsetHelpers`

```cpp
void SliderControlPane::ScrollLineBackward()
{
    int nextValue = 0;
    if (m_currentValue >= 1)
        nextValue = m_currentValue - 1;
    if (nextValue > m_maximumValue)
        nextValue = m_maximumValue;

    m_currentValue = static_cast<short>(nextValue);
    InvalidateRect(NULL);
}

void SliderControlPane::ScrollPageForward()
{
    int nextValue = 0;
    if (m_currentValue >= -10)
        nextValue = m_currentValue + 10;
    if (nextValue > m_maximumValue)
        nextValue = m_maximumValue;

    m_currentValue = static_cast<short>(nextValue);
    InvalidateRect(NULL);
}

void SliderControlPane::ScrollPageBackward()
{
    int nextValue = 0;
    if (m_currentValue >= 10)
        nextValue = m_currentValue - 10;
    if (nextValue > m_maximumValue)
        nextValue = m_maximumValue;

    m_currentValue = static_cast<short>(nextValue);
    InvalidateRect(NULL);
}

void SliderControlPane::ScrollLineForward()
{
    int nextValue = 0;
    if (m_currentValue >= -1)
        nextValue = m_currentValue + 1;
    if (nextValue > m_maximumValue)
        nextValue = m_maximumValue;

    m_currentValue = static_cast<short>(nextValue);
    InvalidateRect(NULL);
}
```

Translation proof: MCP disassembly shows each function loads signed words at `+0xfa` and `+0xfc`, computes `-1`, `+10`, `-10`, or `+1` with a zero lower guard, clamps to the maximum via signed compare, stores the low word back to `+0xfa`, and calls vtable slot `+0x20` with argument `0`.

### [UID:0000EK] `TextButtonExControlPane`

```cpp
// TextButtonExControlPane class source routes through exact constructor,
// state/text, label-helper, teardown, and destructor children. The complete
// class declaration is intentionally withheld until the text-provider field
// and adjacent text-button source split are finalized.
[[CHILDREN]]
```

### [UID:0002Y7] `TextButtonExControlPaneScalarDeletingDestructor`

```cpp
// MSVC scalar deleting destructor wrapper for TextButtonExControlPane.
// Generated from the class destructor/vtable layout; do not hand-author this
// wrapper as source.
```

## Score And Metadata Recommendations

- [UID:0000HY] `ButtonControlPane.md`: `86/88 -> 88/89`. Rationale: the file page will have all current empty emitters dispositioned, current MCP-backed evidence recorded, and generated-output expectations made explicit. Do not raise higher because broad original source split and full class declarations remain partly provisional.
- [UID:00001E]: `85/88 -> 87/89`; keep owner/emitter/reconstructable. Rationale: formal no-code route proof replaces stale blank marker, but full class declaration still withheld.
- [UID:00006D]: `85/88 -> 87/89`; keep metadata. Rationale: route marker with child handling and scalar destructor proof.
- [UID:0002XZ]: `85/88 -> 86/89`; keep metadata. Rationale: exact wrapper xrefs and compiler-generated no-code treatment.
- [UID:0000BI]: `85/87 -> 87/89`; keep metadata. Rationale: route marker plus fresh radio raw-island disposition.
- [UID:00011E]: `85/88 -> 86/89`; keep metadata. Rationale: current MCP no-xref/no-function proof added; no body emitted.
- [UID:0002YC], [UID:0002XW], [UID:0002Y3], [UID:0002Y7]: each `86/88 -> 87/89`; keep metadata. Rationale: exact ABI-wrapper no-code proof and formal comments.
- [UID:0000CR]: `85/87 -> 88/90`; keep metadata. Rationale: minimal class declaration, field, setter body, and current MCP proof resolve the major no-code blocker.
- [UID:00011D]: `85/90 -> 88/91`; keep metadata. Rationale: exact one-block body, sole caller, field write, tail-call virtual, and formal method C++.
- [UID:0001SV]: `86/90 -> 87/91`; keep metadata. Rationale: field source placement resolved as class declaration coverage, not standalone output.
- [UID:0000DB]: `86/86 -> 88/89`; keep metadata. Rationale: slider field names for `+0xfa/+0xfc`, child route marker, and helper C++ resolve the empty family blockers.
- [UID:000223]: `85/88 -> 88/90`; keep metadata. Rationale: current MCP confirms exact helper bodies/callers and formal first-draft C++ is ready.
- [UID:0000EK]: `87/88 -> 88/89`; keep metadata. Rationale: route marker aligns with existing label-helper and scalar-destructor children.
- No `CANONICAL_OWNER`, `EMITTER_UIDS`, `RECONSTRUCTABLE`, filename, split, rename, or new file changes are recommended in this report.

## Claim And Incorporation Ledger

| Claim ID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- |
| C01 | [UID:0000HY] remains the current source route for the whole empty-emitter family. | High | Target doc, proposed source tree, generated output, current MCP boundaries | `by-file/ButtonControlPane.md` Status/File Role/Score | incorporate | applied: target file updated with source-route decision, no owner/emitter/split/new-file change, current MCP sizes/xrefs, and score `88/89`. |
| C02 | Generated `ButtonControlPane.cpp` was fresh at command `000000002912` and had 15 empty emitters. | High | Generated file header/read | `by-file/ButtonControlPane.md` Evidence/Generated Output | incorporate | applied: target file records the old generated header/fifteen-empty state and the expected cleanup; final generated inspection after command `000000002967` found the accepted UID blocks/bodies and no `EMPTY`/`[[[]]]` marker hits, although the generated header still reports older content command `000000002956`. |
| C03 | [UID:00011D] is eligible for method C++ and should emit `SetSelectionAndRefresh`. | High | MCP `analyze_function 0x00495cb0` | `by-memory/...SelectionControlPaneSetSelectionAndRefresh.md` | incorporate | applied: formal `SelectionControlPane::SetSelectionAndRefresh(int selectedValue)` body inserted and score raised to `88/91`. |
| C04 | [UID:0001SV] is field evidence covered by [UID:0000CR], not a standalone source object. | High | Field doc, MCP setter write | `by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md` | incorporate | applied: formal no-code field-evidence comment inserted and score raised to `87/91`; field declaration routes through [UID:0000CR]. |
| C05 | [UID:000223] four slider helpers are exact source-authored bodies called only by slider `OnKey`/`ProcessScrollInput`. | High | MCP `analyze_function` and `analyze_component` | `by-memory/...SliderControlPaneScrollOffsetHelpers.md` | incorporate | applied: four formal `SliderControlPane::Scroll*` bodies inserted and score raised to `88/90`. |
| C06 | [UID:00011E] is source-authored raw radio helper code, but current MCP still proves no function objects or inbound xrefs to helper starts. | High | MCP `lookup_funcs`, `xrefs_to`, `make_signature_for_range` | `by-memory/...RadioGroupControlPaneOptionHelpers.md` | incorporate | applied: formal raw-island no-route comment inserted, current no-function/no-xref proof recorded, and score raised to `86/89`. |
| C07 | Scalar deleting destructor pages are source-declared/generated-binary wrappers and should emit only formal no-code comments. | High | MCP `xrefs_to`, B001 report, destructor pages | five scalar destructor by-memory pages | incorporate | applied: formal wrapper no-code comments inserted for [UID:0002XZ], [UID:0002YC], [UID:0002XW], [UID:0002Y3], and [UID:0002Y7], with recommended score updates. |
| C08 | Class pages that still lack source-quality declarations should emit route comments plus `[[CHILDREN]]` rather than blank markers or speculative declarations. | Medium-high | Current class docs and active code-entry rule | class pages `00006D`, `0000BI`, `0000DB`, `0000EK` | incorporate | applied: [UID:00006D], [UID:0000BI], [UID:0000DB], and [UID:0000EK] now have formal route comments plus `[[CHILDREN]]`; [UID:0000CR] has the accepted minimal declaration plus `[[CHILDREN]]`. |
| C09 | [UID:0002XW] is a shared wrapper used by ButtonControlPane, SelectBox, WeatherLayer, and RainingLayer vtable layouts, not exclusive SelectBox source. | High | MCP `xrefs_to 0x0049b0d0`, B001 report | `by-memory/...SelectBoxControlPaneScalarDeletingDestructor.md` | incorporate | applied: [UID:0002XW] formal comment names the shared wrapper route and rejects hand-authored SelectBox-only source; score raised to `87/89`. |
| C10 | No owner/emitter/split/new-file change is required now. | High | All checked docs and MCP evidence | target/support status and score sections | incorporate | applied: no `CANONICAL_OWNER`, `EMITTER_UIDS`, `RECONSTRUCTABLE`, filename, split, rename, generated, or new-file edit was made. |
| C11 | Supervisor amendment for [UID:00001E]: either use `[[CHILDREN]]` if routed children exist, or document the exact generated-route reason it remains marker-only. | High | Generated-route audit, final generated output inspection | `by-class/ButtonControlPane.md`; `by-file/ButtonControlPane.md` | incorporate | applied: [UID:00001E] has a formal marker-only route comment and explicit proof that current generated output has no direct child emitters under [UID:00001E]; [UID:0003N8] is no-body/no-route and absent from the current 17-emitter generated route. |

## Recommended Target And Support Doc Changes

- `by-file/ButtonControlPane.md`: add this report's empty-emitter audit summary, current MCP session evidence, generated file freshness, no owner/split change decision, score rationale `88/89`, and generated refresh expectation.
- `by-class/ButtonControlPane.md`: add formal no-code route comment, explain why broad class declaration is still unsafe, update score to `87/89`.
- `by-class/ImageButtonControlPane.md`: add formal route comment plus `[[CHILDREN]]`, preserve constructor/method evidence, update score to `87/89`.
- `by-class/RadioGroupControlPane.md`: add formal route comment plus `[[CHILDREN]]`, preserve raw helper no-route caveat, update score to `87/89`.
- `by-class/SelectionControlPane.md`: add minimal declaration C++ plus `[[CHILDREN]]`, record base inference caveat, update score to `88/90`.
- `by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md`: insert method C++, replace stale blank-C++ rationale, update score to `88/91`.
- `by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md`: insert covered-by-class no-code comment, update score to `87/91`.
- `by-class/SliderControlPane.md`: add minimal field/helper declaration plus `[[CHILDREN]]`, update score to `88/89`.
- `by-memory/0x0049b930-0x0049ba2b.SliderControlPaneScrollOffsetHelpers.md`: insert four helper bodies, add current MCP evidence, update score to `88/90`.
- `by-class/TextButtonExControlPane.md`: add formal route comment plus `[[CHILDREN]]`, update score to `88/89`.
- Five scalar destructor pages: insert exact no-code comments, preserve xref/proof, update scores as recommended.
- [UID:00011E] radio raw helper page: insert no-route no-code comment, add current MCP session/xref proof, update score to `86/89`.
- Do not edit generated files, `-coverage-report.md`, tracker files, validator state, queue/lock files, IDA DB, or supervisor ledgers.

## Validator / Generated Freshness Expectations

- Report-only pass: no validators run and no leases taken.
- After accepted implementation, run scoped file validators for every by-* file touched. Use `--apply --queue-timeout 240`.
- Expected generated effect: `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp` should refresh newer than validator command ids and should no longer contain empty markers for the fifteen listed UIDs. Formal no-code comments and route markers are expected generated output for no-body pages.
- Supervisor-owned coverage/tracker: no manual text is required from this B-agent for generated tracker files. Validator refresh should update auto-generated tracker state after implementation and report execution.

## Validator Results

All validators were run from `E:\NTK\GhidraBridge\source-3\project-documentation`.

| File | Command | command_id | command_timestamp | Exit | ok | Warnings / notes |
| --- | --- | --- | --- | --- | --- | --- |
| `by-class/ButtonControlPane.md` | `python .\tools\validator.py --mode file --file by-class/ButtonControlPane.md --apply --queue-timeout 240` | `000000002951` | `2026-06-30T14:47:10-04:00` | 0 | 1 | `missing_ref_uid 0003N8` x4; known raw helper UID is absent from validator registry. |
| `by-class/ImageButtonControlPane.md` | `python .\tools\validator.py --mode file --file by-class/ImageButtonControlPane.md --apply --queue-timeout 240` | `000000002952` | `2026-06-30T14:47:12-04:00` | 0 | 1 | Inserted missing UID link to [UID:0002XZ]. |
| `by-memory/0x0049b290-0x0049b2e5.ImageButtonControlPaneScalarDeletingDestructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x0049b290-0x0049b2e5.ImageButtonControlPaneScalarDeletingDestructor.md --apply --queue-timeout 240` | `000000002953` | `2026-06-30T14:47:14-04:00` | 0 | 1 | No target warning. |
| `by-class/RadioGroupControlPane.md` | `python .\tools\validator.py --mode file --file by-class/RadioGroupControlPane.md --apply --queue-timeout 240` | `000000002954` | `2026-06-30T14:47:15-04:00` | 0 | 1 | `missing_ref_uid 0003N1`-`0003N7`; existing raw/child references absent from registry. |
| `by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md` | `python .\tools\validator.py --mode file --file by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md --apply --queue-timeout 240` | `000000002955` | `2026-06-30T14:47:17-04:00` | 0 | 1 | Inserted missing UID link to [UID:0000BI]. |
| `by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md --apply --queue-timeout 240` | `000000002956` | `2026-06-30T14:47:19-04:00` | 0 | 1 | No target warning. |
| `by-memory/0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor.md --apply --queue-timeout 240` | `000000002957` | `2026-06-30T14:47:21-04:00` | 0 | 1 | No target warning. |
| `by-class/SelectionControlPane.md` | `python .\tools\validator.py --mode file --file by-class/SelectionControlPane.md --apply --queue-timeout 240` | `000000002958` | `2026-06-30T14:47:23-04:00` | 0 | 1 | No target warning. |
| `by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md` | `python .\tools\validator.py --mode file --file by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md --apply --queue-timeout 240` | `000000002959` | `2026-06-30T14:47:25-04:00` | 0 | 1 | No target warning. |
| `by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md` | `python .\tools\validator.py --mode file --file by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md --apply --queue-timeout 240` | `000000002960` | `2026-06-30T14:47:26-04:00` | 0 | 1 | Inserted missing UID links to [UID:0000CR] and [UID:00011D]. |
| `by-class/SliderControlPane.md` | `python .\tools\validator.py --mode file --file by-class/SliderControlPane.md --apply --queue-timeout 240` | `000000002970` | `2026-06-30T14:49:37-04:00` | 0 | 1 | Clean recapture run; no target warning. |
| `by-memory/0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor.md --apply --queue-timeout 240` | `000000002971` | `2026-06-30T14:49:45-04:00` | 0 | 1 | Clean recapture run; no target warning. |
| `by-memory/0x0049b930-0x0049ba2b.SliderControlPaneScrollOffsetHelpers.md` | `python .\tools\validator.py --mode file --file by-memory/0x0049b930-0x0049ba2b.SliderControlPaneScrollOffsetHelpers.md --apply --queue-timeout 240` | `000000002972` | `2026-06-30T14:49:55-04:00` | 0 | 1 | Clean recapture run; no target warning. |
| `by-class/TextButtonExControlPane.md` | `python .\tools\validator.py --mode file --file by-class/TextButtonExControlPane.md --apply --queue-timeout 240` | `000000002973` | `2026-06-30T14:50:01-04:00` | 0 | 1 | `missing_ref_uid 0003NC` x6; known retained label-helper UID is absent from validator registry. |
| `by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md` | `python .\tools\validator.py --mode file --file by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md --apply --queue-timeout 240` | `000000002974` | `2026-06-30T14:50:11-04:00` | 0 | 1 | Clean recapture run; no target warning. |
| `by-file/ButtonControlPane.md` | `python .\tools\validator.py --mode file --file by-file/ButtonControlPane.md --apply --wait-generated --queue-timeout 240` | `000000002967` | `2026-06-30T14:48:27-04:00` | 0 | 1 | `missing_ref_uid 0003N8`/`0003NC` known registry warnings; broad autogen marker warnings were unrelated to this file. `generated_refresh: completed`. |

Generated inspection: final `--wait-generated` completed for command `000000002967`. `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp` contains the accepted formal comments and first-draft bodies for [UID:00001E], [UID:00006D], [UID:0002XZ], [UID:0000BI], [UID:00011E], [UID:0002YC], [UID:0002XW], [UID:0000CR], [UID:00011D], [UID:0001SV], [UID:0000DB], [UID:0002Y3], [UID:000223], [UID:0000EK], and [UID:0002Y7]. `rg` found no `EMPTY` or `[[[]]]` hits in the generated file. Header note: the generated file header still reports `validator-command-id: 000000002956` / `validator-refreshed-at: 2026-06-30T14:47:19-04:00`, older than final command `000000002967`, even though final validator output reported `generated_refresh: completed` and the body content contains the accepted cleanup.

## Changed Files

- Modified by-* docs: `by-file/ButtonControlPane.md`; `by-class/ButtonControlPane.md`; `by-class/ImageButtonControlPane.md`; `by-memory/0x0049b290-0x0049b2e5.ImageButtonControlPaneScalarDeletingDestructor.md`; `by-class/RadioGroupControlPane.md`; `by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md`; `by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md`; `by-memory/0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor.md`; `by-class/SelectionControlPane.md`; `by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md`; `by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md`; `by-class/SliderControlPane.md`; `by-memory/0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor.md`; `by-memory/0x0049b930-0x0049ba2b.SliderControlPaneScrollOffsetHelpers.md`; `by-class/TextButtonExControlPane.md`; `by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md`.
- Modified report: this report's Claim And Incorporation Ledger, Validator Results, Changed Files, Blockers, and Implementation Tracking Checklist.
- Generated/project state updated by validator only: `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, `project-level/-auto-completion-stats.md`, and validator-owned metadata/backups. No generated file, manual coverage report, validator state, queue/lock, supervisor ledger, or IDA DB was edited by hand.
- Leases: initial 16-file B010 lease batch was taken for the edit/validator batch and had expired by cleanup; no active lease remained. A second short B010 lease batch on the five recaptured validator files was released explicitly. `current_leases.md` shows no active leases.

## Blockers

- No implementation blocker: accepted by-* changes, formal C++/marker/no-code dispositions, score updates, report ledger/checklist updates, validators, and generated inspection are complete.
- Nonblocking generated-freshness caveat: final `--wait-generated` command `000000002967` reported completed refresh and the generated body contains all accepted cleanup with no empty markers, but the generated file header still reports older command `000000002956`. This appears to be validator-owned generated-header metadata behavior rather than missing cleanup; no manual generated edit was made.
- Known validator warnings: missing registry refs for historical/raw helper UIDs [UID:0003N8], [UID:0003NC], and [UID:0003N1]-[UID:0003N7]. These are pre-existing/support-reference warnings, not blockers for the accepted [UID:0000HY] cleanup.

## Implementation Tracking Checklist

Initial report-only pass:

- [x] Supervisor validation required before implementation. Proof: supervisor sent implementation callback accepting this report.
- [x] Update `by-file/ButtonControlPane.md` with current target state, empty-emitter inventory, current MCP evidence, score `88/89`, generated freshness expectation, and no owner/split change decision. Proof: target file updated and validator `000000002967` passed `ok:1`.
- [x] Update `by-class/ButtonControlPane.md` with [UID:00001E] formal no-code route comment and score `87/89`. Proof: updated; validator `000000002951` passed `ok:1`; supervisor amendment documented no direct generated children, so no `[[CHILDREN]]`.
- [x] Update `by-class/ImageButtonControlPane.md` with [UID:00006D] formal route comment plus `[[CHILDREN]]` and score `87/89`. Proof: updated; validator `000000002952` passed `ok:1`.
- [x] Update `by-memory/0x0049b290-0x0049b2e5.ImageButtonControlPaneScalarDeletingDestructor.md` with [UID:0002XZ] no-code wrapper comment and score `86/89`. Proof: updated; validator `000000002953` passed `ok:1`.
- [x] Update `by-class/RadioGroupControlPane.md` with [UID:0000BI] route comment plus `[[CHILDREN]]` and score `87/89`. Proof: updated; validator `000000002954` passed `ok:1`.
- [x] Update `by-memory/0x004964a0-0x0049662f.RadioGroupControlPaneOptionHelpers.md` with [UID:00011E] current MCP no-route no-code comment and score `86/89`. Proof: updated; validator `000000002955` passed `ok:1`.
- [x] Update `by-memory/0x0049b420-0x0049b487.RadioGroupControlPaneScalarDeletingDestructor.md` with [UID:0002YC] no-code wrapper comment and score `87/89`. Proof: updated; validator `000000002956` passed `ok:1`.
- [x] Update `by-memory/0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor.md` with [UID:0002XW] shared-wrapper no-code comment and score `87/89`. Proof: updated; validator `000000002957` passed `ok:1`.
- [x] Update `by-class/SelectionControlPane.md` with [UID:0000CR] minimal declaration plus `[[CHILDREN]]`, base-inference caveat, and score `88/90`. Proof: updated; validator `000000002958` passed `ok:1`.
- [x] Update `by-memory/0x00495cb0-0x00495cc9.SelectionControlPaneSetSelectionAndRefresh.md` with [UID:00011D] method C++ and score `88/91`. Proof: updated; validator `000000002959` passed `ok:1`.
- [x] Update `by-type/by-field/SelectionControlPaneSelectedValue_0x10c.md` with [UID:0001SV] covered-by-class no-code comment and score `87/91`. Proof: updated; validator `000000002960` passed `ok:1`.
- [x] Update `by-class/SliderControlPane.md` with [UID:0000DB] minimal field/helper declaration plus `[[CHILDREN]]` and score `88/89`. Proof: updated; recapture validator `000000002970` passed `ok:1`.
- [x] Update `by-memory/0x0049b5b0-0x0049b5eb.SliderControlPaneScalarDeletingDestructor.md` with [UID:0002Y3] no-code wrapper comment and score `87/89`. Proof: updated; recapture validator `000000002971` passed `ok:1`.
- [x] Update `by-memory/0x0049b930-0x0049ba2b.SliderControlPaneScrollOffsetHelpers.md` with [UID:000223] four helper bodies and score `88/90`. Proof: updated; recapture validator `000000002972` passed `ok:1`.
- [x] Update `by-class/TextButtonExControlPane.md` with [UID:0000EK] route comment plus `[[CHILDREN]]` and score `88/89`. Proof: updated; recapture validator `000000002973` passed `ok:1`.
- [x] Update `by-memory/0x0049b860-0x0049b8c7.TextButtonExControlPaneScalarDeletingDestructor.md` with [UID:0002Y7] no-code wrapper comment and score `87/89`. Proof: updated; recapture validator `000000002974` passed `ok:1`.
- [x] Preserve old-report provenance from B001/B002/B007/B010 where used as support, but record current MCP evidence as the deciding evidence for this assignment. Proof: target/support docs now record current MCP facts and no accepted old-report claim was removed.
- [x] Run scoped validators for every changed by-* file after supervisor callback; record command, command id, timestamp, exit code, and ok count. Proof: validator table above.
- [x] Check generated `auto-generated/NexusTK/ui/controls/ButtonControlPane.cpp` header after validators if generated output matters; it should be equal/newer than the implementation validator command and should not show the fifteen listed empty emitter markers. Proof: final `--wait-generated` `000000002967` completed and generated body contains accepted cleanup/no empty marker hits; header remains older (`000000002956`) and is recorded as a nonblocking generated-header caveat.
- [x] Do not edit generated reports/C++ manually, manual `-coverage-report.md`, queue/lock files, validator state, supervisor ledgers, or IDA DB. Proof: only by-* docs and this report were manually edited; generated/project state changed only via validator.

Implementation callback pass:

- [x] Report accepted by supervisor for implementation.
- [x] Leases taken only for immediate by-* edit/validator batches and released/expired after validators. Proof: no active leases in `tools/leaser/Agents/current_leases.md`; second recapture lease batch released explicitly.
- [x] Claim And Incorporation Ledger updated with `applied`, `already-present`, or `excluded-with-reason` for every accepted claim. Proof: C01-C11 all `applied`.
- [x] All accepted formal C++/marker/no-code blocks applied at report-level detail. Proof: by-* formal blocks and generated `ButtonControlPane.cpp` inspection show accepted comments/bodies.
- [x] Validators and generated freshness recorded in the report checklist before returning implementation result. Proof: validator table and generated inspection note above.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0000HY-ButtonControlPane-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B010/research/0000HY-ButtonControlPane-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T14:55:46","uid":"0000HY"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
