** TARGET-REPORT-UID:00003X **
** AUTHOR-AGENT-ID:B004 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00003X DirectionButtonControlPane Class Source-Quality Report

## Finalized Report / Current Recommendation

- FINISHED.
- Target UID/path: [UID:00003X] `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\DirectionButtonControlPane.md`.
- Assignment: `B004-goal2-direction-button-control-pane-class-source-quality-00003X-20260619`, report-only under the temporary 10-B-agent cap.
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000NY`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NY`, blank `RECONSTRUCTION_CPP CODE`.
- Recommendation: keep `CANONICAL_OWNER:0000NY` and `EMITTER_UIDS:0000NY`; keep the direct source-family placement in [UID:0000NY] `by-file/SpecializedButtonPanes.md` / `NexusTK/ui/controls/` as the current provisional route; raise the class page to `COMPLETION:88`, `CONFIDENCE:89` after incorporating the reanalysis below.
- C++ recommendation: do not populate formal class-level C++ on [UID:00003X] yet. The class clears the minimum score/emitter gate, but class-file C++ would need the final class declaration, base inheritance, and field/header names; method bodies belong to exact `by-memory` children. The current method child [UID:00036V] is still a mixed Gender/Direction cluster, so method C++ should wait for exact method-child splits or an implementation decision to split that cluster. If exact Direction-only method children are created, the state and paint bodies are behavior-ready for first-draft source; the constructor and scalar deleting destructor should remain no-code/compiler/raw evidence.
- Scope note: no by-* documentation file and no `by-memory/-coverage-report.md` was edited during this report-only pass.

## Supporting Research

### Target And Current Coverage State

- Target class page: [UID:00003X] `by-class/DirectionButtonControlPane.md`.
- Current class coverage row at `by-class/-coverage-report.md:166` still says `80%`, even though the target page metadata is already `85/86`. Exact replacement text is provided below for supervisor-owned application.
- Current generated source route: `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp`, source by-file UID [UID:0000NY]. The generated file currently contains an empty marker for [UID:00003X] and empty markers for children [UID:00036W], [UID:0002OW], and [UID:00036V].
- Current route is valid but provisional: [UID:0000NY] is `86/88` and explicitly treats `SpecializedButtonPanes.cpp` as a current UI-controls bucket, not proof of a literal original filename. Proposed final split candidates remain `DirectionButtonControlPane.cpp`, `GenderButtonControlPane.cpp`, and `CheckBoxTextControlPane.cpp`.

### Evidence Checked

- Supervisor and B004 instructions: `tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, `tools/leaser/Agents/Agent-B004/goal.md`, and `Agent-B004/notes.md`.
- Source-quality rules: `by-structure.md` code-entry gate and source-quality guidance, plus `inference_research.md` routing guidance via B004 goal requirements.
- Target/support docs:
  - [UID:00003X] `by-class/DirectionButtonControlPane.md`.
  - [UID:0000NY] `by-file/SpecializedButtonPanes.md`.
  - [UID:00036V] `by-memory/0x00500640-0x005008c0.GenderDirectionButtonControlPaneMethods.md`.
  - [UID:00036W] `by-memory/0x005026a0-0x005026f5.DirectionButtonControlPaneScalarDeletingDestructor.md`.
  - [UID:0002OW] `by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md`.
  - [UID:0001W7] `by-type/by-struct/SpecializedButtonPaneLayouts.md`.
  - [UID:0001YW] `by-type/by-vtable/SpecializedButtonPaneVtables.md`.
  - [UID:00025Q] `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`.
  - [UID:0003N2] `by-memory/0x00494b80-0x00494bad.ControlPaneSetVisualState.md`.
  - [UID:0000QU] `by-global/g_pEPFLib.md`.
  - [UID:0002KP] `by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md`.
  - [UID:00005P] `by-class/GenderButtonControlPane.md`, for sibling naming consistency.
  - [UID:0000LX] `by-file/NewUserMiscDialogPane.md` and [UID:00009F] `by-class/NewUserMiscDialogPane.md`, for inline child-setup evidence.
- Generated/project-level reports:
  - `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp`.
  - `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-memory-coverage.md`.
  - `project-level/-auto-completion-stats.md`.
  - `project-level/-resolved.md`, `project-level/-resolved-multple-aliases.md`, and `project-level/-unresolved.md`.
- Local PE binary recheck:
  - Binary: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - Size: `2679296`.
  - MD5: `4247e04e20b65d6414c7238aa8ff5515`.
  - SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
  - Image base: `0x00400000`.
  - Sections: `.text 0x00401000-0x0060c4ac`, `.rdata 0x0060d000-0x0066c0be`, `.data 0x0066d000-0x0069ce24`, `.rsrc 0x0069d000-0x006b2c38`.
  - Scans performed for absolute VA pointers, RVA pointers, and direct `E8`/`E9` branches to `0x005007a0`, `0x005007f0`, `0x00500820`, `0x005026a0`, and vtable bases `0x0061dc34/0x0061dc9c/0x0061dccc`.

### Local PE Recheck Results

Pointer/branch scan facts:

| Target | Absolute VA hits | RVA hits | Direct `E8`/`E9` branches | Meaning |
| --- | ---: | ---: | --- | --- |
| `0x005007a0` | `0` | `0` | none | No direct executable/data route to the raw constructor-shaped body. |
| `0x005007f0` | `1` at `0x0061dc7c` | `0` | none | Vtable slot only; exact modeled state override. |
| `0x00500820` | `1` at `0x0061dc78` | `0` | none | Vtable slot only; exact modeled paint override. |
| `0x005026a0` | `1` at `0x0061dc34` | `0` | `0x00502490`, `0x0050249b` | Vtable destructor slot plus adjustor-thunk jumps. |
| `0x0061dc34` | `4` at `0x004fba6f`, `0x004fbaf5`, `0x005007bf`, `0x005026a8` | `0` | none | Primary vtable immediate stores in inline setup, raw constructor, and destructor reset. |
| `0x0061dc9c` | `4` at `0x004fba79`, `0x004fbaff`, `0x005007c9`, `0x005026b2` | `0` | none | Secondary vtable immediate stores. |
| `0x0061dccc` | `4` at `0x004fba83`, `0x004fbb09`, `0x005007d3`, `0x005026bc` | `0` | none | Tertiary vtable immediate stores. |

Resource literal scan:

- ASCII `DIREC.EPD`: no hits.
- UTF-16LE `DIREC.EPD`: one hit at `0x0061e540`, raw file offset `0x21cf40`.
- [UID:00025Q] also records `0x0061e540` label `aDirecEpd`, string `DIREC.EPD`, with representative xrefs `0x00500861`, `0x0052a8ad`, and `0x0052a956`.

Important disassembly facts:

- `0x005007a0-0x005007e5`: constructor-shaped `thiscall` body. It pushes the second stack argument into base constructor `0x00494eb0`, stores first stack argument at `this+0x10c`, writes vtables `0x0061dc34`, `0x0061dc9c`, `0x0061dccc`, clears `this+0x110`, returns `ret 8`, and is followed by eight `0xcc` bytes through `0x005007f0`.
- `0x005007f0-0x0050081b`: modeled state override. It reads current byte `this+0x103`, compares to incoming byte argument, sets `this+0x110 = (state == 0x0b)` only when the state changes, then calls `0x00494b80` with the same state byte and returns `ret 4`.
- `0x00500820-0x005008b8`: modeled paint override. It initializes a stack draw/tile context, copies the bounds/draw rect from `this+0x44`, computes `frame = this+0x110 + 2 * this+0x10c`, calls `ResourceLayoutTableLookupLayoutEntry` through `g_pEPFLib` with `L"DIREC.EPD"` and that frame, then draws through the `sub_4B9980`/surface-callback family. If byte `this+0x101` is zero, it applies disabled styling with color/state value `0x8f`, writes `this+0x70 = 2`, and calls the indirect callback at `0x0069b3fc` with `this+0x44`.
- `0x005026a0-0x005026f2`: scalar deleting destructor. It reinstalls the three Direction vtables, calls base teardown `0x00544580`, then if flag bit `1` is set it either calls delete helper `0x004f4ac0(this)` or the guarded helper `0x0041b6a0(this, 0x114)` when bit `4` is set.
- `NewUserMiscDialogPane` inline setup:
  - First setup at `0x004fba68-0x004fba91`: calls base constructor `0x00494eb0`, writes vtables, stores `this+0x10c = 0`, clears `this+0x110 = 0`.
  - Second setup at `0x004fbaee-0x004fbb17`: calls base constructor `0x00494eb0`, writes vtables, stores `this+0x10c = 1`, clears `this+0x110 = 0`.
  - Both allocations use size `0x114`.

## Exact Child Range Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Current Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| Class page | [UID:00003X] `by-class/DirectionButtonControlPane.md` | Direction arrow button control class | TRUE | [UID:0000NY] `SpecializedButtonPanes` | `85/86` | Recommend `88/89`; no formal C++ yet. |
| `0x005007a0-0x005007f0` | inside [UID:00036V] | Raw constructor-shaped body plus padding | TRUE as evidence | [UID:0000NY] currently via cluster | `86/88` cluster | No direct xref/pointer/branch route; do not emit constructor now. |
| `0x005007f0-0x0050081e` | inside [UID:00036V] | Direction visual state override | TRUE | [UID:0000NY] currently via cluster | `86/88` cluster | Behavior-ready; should become exact child before formal method C++. |
| `0x00500820-0x005008b9` | inside [UID:00036V] | Direction paint override | TRUE | [UID:0000NY] currently via cluster | `86/88` cluster | Behavior-ready but helper names still partly provisional; should become exact child before formal method C++. |
| `0x005008b9-0x005008c0` | [UID:0000VN] ignored padding | Alignment before BlueAlertPane | FALSE/ignored | none | `100` ignored | Keep ignored. |
| `0x0050248a-0x00502495` | [UID:0000VN] ignored thunk | Secondary adjustor thunk into destructor | FALSE/compiler | none | `100` ignored | Do not model as source method. |
| `0x00502495-0x005024a0` | [UID:0000VN] ignored thunk | Tertiary adjustor thunk into destructor | FALSE/compiler | none | `100` ignored | Do not model as source method. |
| `0x005026a0-0x005026f5` | [UID:00036W] `DirectionButtonControlPaneScalarDeletingDestructor` | MSVC scalar deleting destructor wrapper | TRUE as compiler/source destructor evidence | [UID:00003X] | `86/90` | Keep exact; no handwritten method C++. |
| `0x0061dc30-0x0061dcd4` | [UID:0002OW] `DirectionButtonControlPaneVtableData` | RTTI/vtable data for three views | TRUE as compiler-emitted data | [UID:00003X] | `86/91` | Reconstruct through class declaration/methods; do not hand-port dwords. |

## Heuristic / Inference Reanalysis And Validation

### Raw Constructor-Shaped Start `0x005007a0`

- Existing/generated name: `DirectionButtonControlPane::DirectionButtonControlPane`; raw bytes are constructor-shaped, but IDA does not model a function object.
- Best source-facing inference: `DirectionButtonControlPane::DirectionButtonControlPane(int directionIndex, const ControlPaneBoundsLike &bounds)` or equivalent mid-2000s two-argument constructor. The exact second type name is not safe; evidence only proves it is the argument passed directly to `ButtonControlPane`/base constructor `0x00494eb0`.
- Evidence: `ret 8`; first stack arg stored at `this+0x10c`; second stack arg forwarded to `0x00494eb0`; vtable stores and `this+0x110 = 0`; object size `0x114` from inline setup; no direct VA/RVA/branch refs to `0x005007a0`.
- Rejected alternative: "active constructor called by NewUserMiscDialogPane." NewUserMisc inlines equivalent setup twice instead of calling `0x005007a0`.
- Rejected alternative: "padding or accidental disassembly." The body has normal prologue, base constructor call, vtable installs, field initialization, `ret 8`, and exact vtable-store xrefs.
- Final policy: retain the raw body as source-shaped constructor evidence, but do not create constructor C++ or use it as proof of a live out-of-line route until a route is found or the project accepts no-route constructor artifacts as non-emitting evidence.

### Method Name `SetEnabled` Versus `SetState` / Visual State

- Existing target name: `SetEnabled`.
- Best source-facing recommendation: change target documentation to `SetState` or `SetVisualState` as the primary descriptive name, with `SetEnabled` recorded as an old/generated/historical alias. If the broader ControlPane/ButtonControlPane naming pass later proves `SetEnabled` was the original public name for this slot, it can be restored; current behavior does not support boolean-only enabled semantics.
- Evidence: `0x005007f0` accepts a one-byte state, compares it against inherited byte `this+0x103`, special-cases value `0x0b`, writes `this+0x110` as a frame offset, then delegates to [UID:0003N2] `ControlPaneSetVisualState` at `0x00494b80`. [UID:0003N2] explicitly says old reports call `0x00494b80` `SetEnabled`, but the behavior-backed role is a setter for byte state `+0x103`.
- Sibling validation: [UID:00005P] already names the analogous gender method `SetState`; [UID:0001W7] says safe IDA labels were applied for `DirectionButtonControlPaneSetState`.
- Rejected alternative: keep `SetEnabled` as final original name. Some control-family callers do use enabled/disabled semantics, but the special `0x0b` visual-state value and non-boolean byte argument make `SetEnabled` misleading as the only source-facing name here.
- Remaining uncertainty: exact original symbol spelling is unproven. This affects formal C++ naming but does not affect behavior, owner, or score below final-audit levels.

### `OnPaint` Name And Signature

- Best source-facing name/signature: `void DirectionButtonControlPane::OnPaint()` or project-local equivalent paint override.
- Evidence: primary vtable slot `0x0061dc78 -> 0x00500820`; no explicit stack parameters; uses `this`; copies bounds from `this+0x44`; loads `DIREC.EPD`; draws frame; applies disabled overlay when `this+0x101 == 0`.
- Rejected alternative: resource helper or generic draw function. It is class-vtable-bound and consumes class fields `+0x10c/+0x110`, so it is a real class override.
- Remaining uncertainty: exact paint helper names and local stack type names are not final, but the method role is strong.

### Fields At `+0x10c` And `+0x110`

- `+0x10c` best name: `m_directionIndex`.
  - Evidence: raw constructor stores first argument; inline setup writes `0` and `1`; paint computes `2 * directionIndex`; resource is `DIREC.EPD`.
  - Rejected names: `m_frameIndex` is too broad because `+0x110` contributes the state frame; `m_isLeft` is too narrow because the value is numeric and multiplied, not tested as a bool.
- `+0x110` best name: `m_stateFrameOffset` or `m_visualStateFrameOffset`. Prefer `m_stateFrameOffset` in source-facing snippets and explain it is the visual-state frame offset.
  - Evidence: inline setup clears it; state override writes `1` when state byte equals `0x0b` and `0` otherwise on state change; paint adds it to `2 * m_directionIndex`.
  - Rejected names: `m_enabled` is wrong because the field is an integer frame offset, not a boolean control-enabled flag; `m_pressed` is too specific without proving that state `0x0b` is pressed rather than highlighted/disabled/hover.
- Inherited fields:
  - `+0x44`: bounds/draw rect subobject; owned by ControlPane/ButtonControlPane layout, not Direction.
  - `+0x101`: visible/enabled draw-state byte tested by paint before disabled overlay; final inherited name belongs to ControlPane.
  - `+0x103`: base visual/control state byte; final inherited name belongs to ControlPane.
  - `+0x00/+0xa0/+0xa4`: primary/secondary/tertiary vptrs; should be named as vptr views, not source data members.

### Vtables And Compiler-Generated Glue

- `0x0061dc34`, `0x0061dc9c`, `0x0061dccc`: primary/secondary/tertiary `DirectionButtonControlPane` vtable views. They are compiler-emitted data regenerated from class declarations and virtual methods, not hand-written source objects.
- `0x0050248a` and `0x00502495`: adjustor thunks into the scalar deleting destructor. They are compiler-generated multiple-inheritance glue and belong in ignored/thunk documentation, not source method lists.
- `0x005026a0`: best name `DirectionButtonControlPane::scalar deleting destructor` as a compiler wrapper; source should model a normal destructor and class inheritance, not handwritten scalar-delete logic.
- Evidence: vtable child [UID:0002OW] records three table views, slot counts, key slots, COL pointers, store xrefs, and boundary before `BlueAlertPane`; PE scan found destructor branch refs only from adjustor thunks and primary vtable data.

### Resource, Helper, And Global Names In Paint

- `dword_67A744`: resolved to [UID:0000QU] `g_pEPFLib`. Use `g_pEPFLib` in target/support docs instead of `dword_67A744`.
- `sub_4D02F0`: [UID:0002KP] `ResourceLayoutTableLookupLayoutEntry`. In Direction paint, it resolves `DIREC.EPD` and frame index into an EPF/EPD tile context.
- `0x0061e540`: `aDirecEpd`, UTF-16 `DIREC.EPD`, inside [UID:00025Q] main-menu/new-user read-only data aggregate; not a Direction-owned standalone string page yet, but xref `0x00500861` binds it to this paint method.
- `sub_457A60`: stack tile/context initializer. Existing reports list it as a common paint helper; no final owner/name was proved in this pass. Keep descriptive until its exact by-memory owner is audited.
- `sub_4B9980`: high-probability EPF/tile blit helper. `project-level/-unresolved.md` still lists it unresolved; use descriptive wording like "tile blit/draw helper" rather than final source name.
- `sub_4B9660`: graphics draw-state/color helper used for disabled styling. It is referenced by ControlPane draw-state docs; exact final name remains outside this class target.
- `dword_69B3FC` / `unk_69B3FC`: indirect surface/render callback slot. Project-level unresolved still tracks it; use descriptive "surface invalidation/render callback" wording and do not finalize a global name here.
- `0x0061e40c`: paint passes this adjacent resource/palette/string pointer after lookup; this pass did not prove a Direction-specific source symbol. Treat it as resource-layout/render helper input, not class-owned state.

### Caller/Reachability And Inline Setup

- Active construction path observed: `NewUserMiscDialogPane` allocates two `0x114` Direction controls and performs the base constructor call, vtable stores, direction-index writes, and state-offset clear inline.
- Raw out-of-line constructor body: source-shaped but no direct route. The best inference is a retained or compiler-emitted out-of-line constructor copy that is not used by the observed NewUserMisc path, or a source constructor whose calls were optimized/inlined away in the observed construction sites.
- Rejected ownership: `NewUserMiscDialogPane` should not own `DirectionButtonControlPane` merely because it constructs two child controls. It is a consumer/inline setup site; vtables, class fields, and exact virtual methods prove a reusable control class.
- Rejected ownership: `MainMenuNewUserReadOnlyData` owns only a mixed `.rdata` aggregate; exact vtable/string children should route to direct class/resource owners.

### Source Placement And SpecializedButtonPanes

- Best current source placement: keep [UID:0000NY] `SpecializedButtonPanes` under `NexusTK/ui/controls/` as the direct route for [UID:00003X].
- Why not `NewUserMiscDialogPane`: inline construction is consumer evidence, not direct reusable-control ownership.
- Why not `ButtonControlPane`: the base class owns `0x00494eb0` and `0x00494b80`, but Direction's subclass vtables, fields, resource, paint, and destructor are specialized child behavior.
- Why not a new mandatory file now: final original-source filename is not proved; [UID:0000NY] already documents the likely future split. Creating a new by-file owner during this report-only pass would be premature.
- Later split direction: a final-source pass may split `SpecializedButtonPanes.cpp` into `DirectionButtonControlPane.cpp`, `GenderButtonControlPane.cpp`, and `CheckBoxTextControlPane.cpp`, but current autogen should keep the consolidated source-family route.

### Split/Range Decisions

- Current [UID:00036V] is exact as a physical front cluster but mixed as a source-emission unit: it contains Gender raw constructor/accessor/state/paint, padding, and Direction raw constructor/state/paint.
- Recommended implementation option if C++ method emission is accepted later: split [UID:00036V] into exact child pages for `DirectionButtonControlPaneRawConstructor` (`0x005007a0-0x005007f0`, no-code/no-route), `DirectionButtonControlPaneSetState` (`0x005007f0-0x0050081e`), and `DirectionButtonControlPaneOnPaint` (`0x00500820-0x005008b9`), with analogous Gender children if the cluster is fully repaired.
- Do not emit only Direction method C++ from the current mixed [UID:00036V] page; it would either omit sibling source in the same range or force unrelated Gender source into a Direction task.
- Vtable data [UID:0002OW] and destructor [UID:00036W] are already exact and should not be split further for this target.

## Ranked Ownership Analysis

### 1. Keep [UID:0000NY] SpecializedButtonPanes As Current Owner/Emitter

- Evidence for: [UID:0000NY] is `86/88`, has a valid `NexusTK/ui/controls/` route, lists Direction/Gender/CheckBox specialized controls, records raw constructor caveats, and explicitly names future split candidates. It owns the exact method cluster [UID:00036V] under the current source-family model and surfaces to `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp`.
- Evidence against: the filename is provisional and may not be the literal original source file; the method cluster remains mixed; exact Direction method pages do not yet exist.
- Decision: keep as current owner/emitter. This is the strongest safe route now.

### 2. Future `DirectionButtonControlPane.cpp` / New File Owner

- Evidence for: Direction has its own class, RTTI/vtable data, state/paint methods, destructor, and resource-specific behavior. A one-class source file would be a normal later split.
- Evidence against: current proposed-source-tree and by-file docs intentionally use `SpecializedButtonPanes.cpp` as a bucket; no original filename or compilation-unit evidence proves a separate file; sibling raw constructor and final source split issues remain.
- Decision: note as a future split candidate only. Do not create or route to it now.

### 3. NewUserMiscDialogPane

- Evidence for: it allocates and initializes the observed runtime Direction controls.
- Evidence against: it is a consumer; class vtables, virtual methods, destructor, and reusable control docs are outside the dialog's source ownership.
- Decision: reject as owner. Keep as call/inline setup evidence.

### 4. ButtonControlPane / ControlPane

- Evidence for: Direction constructor calls `0x00494eb0`; state override delegates to `0x00494b80`; inherited fields drive invalidation/draw state.
- Evidence against: those are base dependencies, not subclass owner evidence. Direction-specific fields, vtable slots, resource frame selection, and destructor resets are subclass-specific.
- Decision: reject as direct owner for [UID:00003X]; use as dependency docs.

### 5. MainMenu/NewUser Read-Only Data Aggregate

- Evidence for: contains Direction vtables and `DIREC.EPD`.
- Evidence against: [UID:00025Q] is a mixed non-emitting `.rdata` aggregate. Exact children carry direct ownership.
- Decision: reject as owner; cite only for string/vtable boundary evidence.

## First-Draft C++ Recommendation

Do not populate [UID:00003X]'s formal `RECONSTRUCTION_CPP CODE` block in the implementation callback unless the supervisor explicitly chooses a comment-only marker policy. Reason:

- [UID:00003X] is a class page. Per the current rules, class files should generally emit class-level declarations only; method bodies belong in exact by-memory children.
- A source-quality class declaration needs final base/inheritance spelling and header boundary. Direction's three-view vtable layout proves multiple inherited views but does not provide a final declaration shape safe enough for copy/paste source.
- The current executable method carrier [UID:00036V] is a mixed Gender/Direction physical cluster, not exact Direction-only method pages.
- The raw constructor `0x005007a0` has no route. Emitting a normal constructor body would risk making an inactive/no-route artifact look like a confirmed source call target.
- The scalar deleting destructor [UID:00036W] is compiler wrapper evidence; source C++ should not hand-write the wrapper.

Behavioral source shape for later exact method-child work, not for immediate insertion:

```cpp
void DirectionButtonControlPane::SetState(unsigned char state)
{
    if (m_visualState != state)
        m_stateFrameOffset = (state == 0x0b) ? 1 : 0;

    ControlPane::SetVisualState(state);
}

void DirectionButtonControlPane::OnPaint()
{
    // Behavioral sketch only: helper/type names still need final source-quality owners.
    const int frameIndex = m_stateFrameOffset + 2 * m_directionIndex;
    EPFTileContext tile;
    InitializeTileContext(tile);
    g_pEPFLib->LookupLayoutEntry(L"DIREC.EPD", frameIndex, &tile);
    DrawTileToRect(tile, m_bounds);

    if (!m_visibleOrEnabledByte)
        DrawDisabledStateOverBounds(m_bounds, 0x8f);
}
```

This is plausible mid-2000s C++ in structure: a small `ControlPane`/button subclass, byte state enum, direct resource literal, integer frame arithmetic, and simple render helper calls. It is not formal code because several names are still descriptive (`m_visualState`, `InitializeTileContext`, `DrawTileToRect`, disabled-state field), and exact Direction-only method children do not yet exist.

## Score / Metadata Recommendation

- [UID:00003X] `COMPLETION`: `85 -> 88`.
  - Rationale: the class page should incorporate exact PE scan results, disassembly-derived constructor/state/paint/destructor facts, improved field names, `SetEnabled` alias correction, helper/global naming, source-placement reasoning, and method-child split policy.
- [UID:00003X] `CONFIDENCE`: `86 -> 89`.
  - Rationale: positive evidence is now independent across target docs, exact child docs, vtable/type docs, project-level resolved names, and local PE scans. Confidence remains below `90+` because the constructor route and final class declaration/source filename are still not proven.
- [UID:00003X] `CANONICAL_OWNER`: keep `0000NY`.
- [UID:00003X] `RECONSTRUCTABLE`: keep `TRUE`.
- [UID:00003X] `EMITTER_UIDS`: keep `0000NY`.
- [UID:00003X] `RECONSTRUCTION_CPP CODE`: keep blank for actual source, unless the supervisor applies a comment-only marker convention separately. Do not insert method bodies in the class page.

## Target / Support Implementation Checklist

For the later implementation callback, incorporate these report details into by-* docs at report-level specificity:

1. Target [UID:00003X] `by-class/DirectionButtonControlPane.md`
   - Update scores to `88/89`.
   - Replace current `SetEnabled` as the primary method name with `SetState` or `SetVisualState`; retain `SetEnabled` as historical/generated alias and explain why the byte-state behavior rejects boolean-only enabled naming.
   - Add PE scan facts: binary path/hash, zero VA/RVA/rel32 route to `0x005007a0`, vtable-only refs for `0x005007f0` and `0x00500820`, destructor thunk branch refs to `0x005026a0`.
   - Add disassembly-derived summaries for raw constructor, state override, paint override, and scalar deleting destructor.
   - Rename field hypotheses to `m_directionIndex` at `+0x10c` and `m_stateFrameOffset` / `m_visualStateFrameOffset` at `+0x110`, with evidence and rejected alternatives.
   - Normalize `dword_67A744` to `g_pEPFLib`, `sub_4D02F0` to `ResourceLayoutTableLookupLayoutEntry`, and `0x0061e540` to UTF-16 `DIREC.EPD`; keep `sub_4B9980`, `sub_4B9660`, and `unk_69B3FC` descriptive/provisional.
   - Clarify that `NewUserMiscDialogPane` inline setup is consumer evidence, not ownership.
   - Add no-code proof for class-level C++ and method-child split recommendation.

2. Support [UID:00036V] `by-memory/0x00500640-0x005008c0.GenderDirectionButtonControlPaneMethods.md`
   - Add the 2026-06-19 PE scan details for `0x005007a0`, `0x005007f0`, and `0x00500820`.
   - Update Direction method naming from `state/update` / `SetEnabled` to `DirectionButtonControlPaneSetState` as the preferred descriptive name, while preserving old alias context.
   - Document that the current cluster should not emit partial Direction method C++ until exact method children are split or a full cluster-level source plan is accepted.
   - Consider later exact child split as described above; do not split during this report-only callback unless supervisor explicitly requests it.

3. Support [UID:00036W] `by-memory/0x005026a0-0x005026f5.DirectionButtonControlPaneScalarDeletingDestructor.md`
   - Add PE disassembly details for vtable resets, base teardown `0x00544580`, delete helper `0x004f4ac0`, guarded helper `0x0041b6a0`, and flags bit semantics.
   - Preserve no-code proof: compiler scalar deleting destructor wrapper, not handwritten source.

4. Support [UID:0002OW] `by-memory/0x0061dc30-0x0061dcd4.DirectionButtonControlPaneVtableData.md`
   - Add PE pointer-scan confirmation of vtable immediate stores and vtable-only method refs.
   - Preserve compiler-emitted vtable-data handling.

5. Support [UID:0001W7] `by-type/by-struct/SpecializedButtonPaneLayouts.md`
   - Synchronize Direction field names to `m_directionIndex` and `m_stateFrameOffset` / `m_visualStateFrameOffset`.
   - Keep inherited fields owned by ControlPane/ButtonControlPane.

6. Support [UID:0001YW] `by-type/by-vtable/SpecializedButtonPaneVtables.md`
   - No score change required; optionally add the local PE recheck as a current validation note for Direction vtable slots.

7. Support [UID:0000NY] `by-file/SpecializedButtonPanes.md`
   - Add a short source-quality note that Direction's class page now recommends `SetState` wording and class-level no-code, while exact method child splitting is the route to future method C++.
   - Preserve the provisional bucket/future split caveat.

8. Support [UID:00025Q] `by-memory/0x0061d264-0x0061e5b4.MainMenuNewUserReadOnlyData.md`
   - No required score/metadata change; optionally cross-link Direction report detail that `DIREC.EPD` is UTF-16 at `0x0061e540` with xref `0x00500861`.

9. Generated C++ route
   - Do not edit `auto-generated` by hand.
   - Keep [UID:00003X] formal C++ blank unless the supervisor explicitly wants a comment-only marker for non-emitting class pages. Do not insert method bodies into the class page.

10. Coverage/report updates
    - Replace the stale [UID:00003X] row in `by-class/-coverage-report.md` with the exact row below.
    - No `by-memory/-coverage-report.md` edit is required for this class-only report. If later exact method-child splits are accepted, new by-memory coverage rows must be produced by that split implementation and remain supervisor-owned if the ban is active.

## Exact Supervisor-Owned Coverage / Report Text

Replace the current [UID:00003X] row in `by-class/-coverage-report.md` with:

```markdown
- [UID:00003X][DirectionButtonControlPane](by-class/DirectionButtonControlPane.md) : reconstructable : 88% : strong : B004 2026-06-19 source-quality reanalysis keeps [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) as the current provisional `NexusTK/ui/controls/` owner/emitter and closes the major source-facing questions: `0x005007a0-0x005007f0` is a source-shaped but no-route constructor body with zero VA/RVA/rel32 refs, `0x005007f0-0x0050081e` is best documented as `SetState`/visual-state override rather than boolean `SetEnabled`, `0x00500820-0x005008b9` is the `DIREC.EPD` paint override using `g_pEPFLib`/`ResourceLayoutTableLookupLayoutEntry`, fields `+0x10c/+0x110` are `m_directionIndex` and `m_stateFrameOffset`, vtable child [UID:0002OW] and destructor child [UID:00036W] prove the class layout/compiler glue, and final C++ remains blank until exact Direction method children or a final class declaration route are accepted.
```

No replacement row for `by-memory/-coverage-report.md` is required by this report-only class assignment.

## Validator Baseline

Command:

> Executable block R001 was removed from this report and preserved verbatim in [00003X-DirectionButtonControlPane-class-source-quality-removed.md](00003X-DirectionButtonControlPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- Exit code: `0`.
- `ok: 1`.
- Key output: target UID header exists; generated registry rebuilt in dry-run mode; generated C++/report outputs unchanged/noop. The run produced normal broad autogen dry-run noise unrelated to the target.

## Changed Files

Created:

- `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\research\00003X-DirectionButtonControlPane-class-source-quality.md`

Modified:

- `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B004\notes.md` was updated with this report path, validator result, and pending by-class coverage row.

Not edited:

- No `by-*` documentation file was edited.
- `by-memory/-coverage-report.md` was not edited.
- `by-class/-coverage-report.md` was not edited; exact replacement row is report-only for supervisor/application callback.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B004","command_id":"000000004165","destination_path":"executed-b-agent-research/B004/00003X-DirectionButtonControlPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:29","uid":"00003X"} -->
<!-- {"agent":"B004","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00003X-DirectionButtonControlPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B004/00003X-DirectionButtonControlPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00003X"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
