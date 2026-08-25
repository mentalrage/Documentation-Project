** TARGET-REPORT-UID:00004Y **
** AUTHOR-AGENT-ID:B013 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00004Y FilterEffecter Class Source-Quality Report

Target: [UID:00004Y] `by-class/FilterEffecter.md`  
Agent: B013  
Date: 2026-06-19  
Mode: report-only first pass; no `by-*` documentation edits and no coverage-report edits were made.

## Executive Recommendation

Raise the target to `COMPLETION:88`, `CONFIDENCE:90`, keep `CANONICAL_OWNER:0000IZ`, keep `RECONSTRUCTABLE:TRUE`, and keep `EMITTER_UIDS:0000IZ`.

The class is now best understood as the pane-backed filter base in `render/Effects.cpp`, not as a standalone generated source file and not as an owner of the shared UI layer slot. The strongest source model is:

```cpp
class FilterEffecter : public ScreenEffecter, public Pane
```

The binary layout supports a `ScreenEffecter` primary view at complete-object offset `+0x00` and an inherited `Pane`/`GrafPort` subobject at complete-object offset `+0x04`. The vtable stores at `0x0055ad41`, `0x0055ad4d`, `0x0055ad54`, and `0x0055ad5e` install the four FilterEffecter views at complete offsets `+0x00`, `+0x04`, `+0xa4`, and `+0xa8`. The `+0xa4` and `+0xa8` values are adjusted inherited Pane/EventHandler/Timer-style vptrs, not source data fields.

The stale global and field interpretations should be corrected:

- `dword_67A764` in the constructor should be treated as the active MapPane/bounds provider, already documented elsewhere as `g_activeMapPane`, not as `g_pParcelPane`.
- `word_66DA9C` and `word_66DAA0` should be named `g_mapTilePixelWidth` and `g_mapTilePixelHeight`.
- `dword_69B364` must not be called `g_pScreenEffecterList`; it is a Main UI layer/context slot used by effecters when attaching their inherited Pane to the UI layer. If the final per-slot name is not settled, keep `dword_69B364` with an explicit `MainUiLayerSlots` cross-reference, or use a descriptive provisional name such as `g_mainUiLayerContext0`.
- Complete-object `+0x94` is inherited `Pane`/`GrafPort` state at Pane-relative `+0x90`, most strongly the draw alpha field (`GrafPort::m_alpha`), not a FilterEffecter-private opacity field.
- Complete-object `+0xf9` is Pane-relative `+0xf5`, the inherited Pane flag byte. SolidColorFilterEffecter and WaterFilterEffecter set it to `1` before layer registration, so old wording such as "active byte" is descriptively understandable, but source-facing documentation should not promote it to a FilterEffecter-owned `m_filterActive` field.

The target should carry a class-level first-draft declaration only. Full constructor and destructor bodies should be deferred to exact method pages if the implementation pass creates them. Putting method bodies directly in the class page would mix class declaration evidence with exact function-range evidence and would blur the destructor/thunk strip.

## Baseline Validation

Run from:

```text
E:\NTK\GhidraBridge\source-3\project-documentation
```

Command:

> Executable block R001 was removed from this report and preserved verbatim in [00004Y-FilterEffecter-class-source-quality-removed.md](00004Y-FilterEffecter-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

```text
exit code: 0
target ok count: 1
key target line: ok 00004Y by-class/FilterEffecter.md UID header exists
```

The validator also emitted the usual dry-run/global autogen warnings unrelated to this target. No target failure was present.

## Evidence Reviewed

Primary target:

- `by-class/FilterEffecter.md` [UID:00004Y], currently `85/86`, source placement `render/Effects.cpp`, generated source `source-3/simroot_v2/class_FilterEffecter.cpp`, constructor range `0x0055ad00-0x0055adba`, destructor/reset strip starting at `0x0055ba22` with live extent through `0x0055bb84`.

Source/file owner:

- `by-file/Effects.md` [UID:0000IZ], owner for the Effects runtime cluster and the class-page emitter.
- `source-3/project-documentation/auto-generated/NexusTK/render/Effects.cpp`, currently containing only emitted code for `EffectObjectPane::IsLooping()` and `WaterFilterEffecter::OnPaint()` plus an empty FilterEffecter emitter marker.
- `source-3/simroot_v2/class_FilterEffecter.cpp`, useful as generated decompiler evidence but not authoritative source placement.

Vtable and runtime cluster:

- `by-type/by-vtable/ScreenEffecterVtableFamily.md` [UID:0001YO].
- `by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md` [UID:0002OR].
- `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md` [UID:0001GE].
- `by-memory/0x0055c1b0-0x0055c1c3.SharedBooleanVirtualStubs.md` [UID:0001GG].

Filter subclass support:

- `by-class/SolidColorFilterEffecter.md` [UID:0000DE].
- `by-class/CloudFilterEffecter.md` [UID:00002T].
- `by-class/StaticCloudFilterEffecter.md` [UID:0000E0].
- `by-memory/0x0055b090-0x0055b0c7.StaticCloudFilterEffecterRawConstructor.md` [UID:0003O9].
- `by-class/WaterFilterEffecter.md` [UID:0000FZ].
- `by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md` [UID:0001GF].

Base/layout support:

- `by-class/ScreenEffecter.md` [UID:0000C9].
- `by-class/PixelEffecter.md` [UID:0000AI].
- `by-class/OverlayEffecter.md` [UID:00009W].
- `by-class/Pane.md`.
- `by-memory/0x00544460-0x00545086.PaneCore.md`.
- `by-memory/0x006219e8-0x00621a6c.PaneVtableData.md`.
- `by-class/GrafPort.md`.

Globals and caller support:

- `by-global/g_pScreenEffecterList.md` [UID:0000S6], ignored stale alias page for `dword_69B364`.
- `by-global/MainUiLayerSlots.md` [UID:0000T6].
- `by-global/MapTilePixelDimensions.md` [UID:0000T7].
- `by-memory/0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md` [UID:0002I4].

## Source Placement And Split Within Effects

The best-supported source placement remains `render/Effects.cpp` with declarations in `render/Effects.h` or the same Effects compilation unit, depending on the project's final reconstruction style. The one-class generated file `source-3/simroot_v2/class_FilterEffecter.cpp` is a staging artifact and should not be treated as a real source split.

Evidence:

- `by-file/Effects.md` owns the effecter runtime cluster `0x0055a260-0x0055c1ff` and already groups `FilterEffecter`, `SolidColorFilterEffecter`, `CloudFilterEffecter`, `StaticCloudFilterEffecter`, and `WaterFilterEffecter` under Effects.
- `MapPaneConfigureEffectList` constructs `WaterFilterEffecter`, `XWaveEffecter`, and `SolidColorFilterEffecter` as part of the effect configuration path. It is a caller/allocator site, not the owner of FilterEffecter source.
- The subclass constructors are tightly adjacent to the FilterEffecter constructor in the Effects runtime cluster:
  - `0x0055ad00-0x0055adba`: FilterEffecter constructor.
  - `0x0055ae00-0x0055aec3`: SolidColorFilterEffecter constructor.
  - `0x0055b000-0x0055b037`: CloudFilterEffecter raw constructor.
  - `0x0055b090-0x0055b0c7`: StaticCloudFilterEffecter raw constructor.
  - `0x0055b6a0-0x0055b77d`: WaterFilterEffecter constructor.
- The shared boolean virtual stubs at `0x0055c1b0-0x0055c1c3` are physically in the same cluster but are compiler-folded support stubs, not independent source methods that should force a separate file.

Recommendation:

- Keep `by-class/FilterEffecter.md` owned/emitted by `by-file/Effects.md` [UID:0000IZ].
- Document the class as part of the Effects family, specifically the filter branch, not as a generated standalone file.
- Keep the open source split question at the file level only for header organization (`Effects.h` versus a later `render/effects/` split). For this target, the best current source placement is resolved enough: `render/Effects.cpp`.

## Class And Vtable Shape

The binary shape is best explained by multiple inheritance:

```cpp
class FilterEffecter : public ScreenEffecter, public Pane
```

Complete-object offsets:

- `+0x00`: `ScreenEffecter` primary vptr.
- `+0x04`: inherited `Pane`/`GrafPort` subobject start.
- `+0xa4`: adjusted Pane/EventHandler-style vptr inside the inherited Pane subobject.
- `+0xa8`: adjusted Pane timer/event-style vptr inside the inherited Pane subobject.

Vtable bases:

- `0x00623944`: primary FilterEffecter/ScreenEffecter view.
- `0x00623964`: adjusted `+0x04` Pane/GrafPort view.
- `0x006239b0`: adjusted `+0xa4` view.
- `0x006239e0`: adjusted `+0xa8` view.

Constructor store evidence:

- `0x0055ad41`: writes the primary vptr.
- `0x0055ad4d`: writes the `+0x04` adjusted Pane/GrafPort view vptr.
- `0x0055ad54`: writes the `+0xa4` adjusted view vptr.
- `0x0055ad5e`: writes the `+0xa8` adjusted view vptr.

This matches the broader ScreenEffecter vtable family: filter subclasses install the same four-view shape after calling the FilterEffecter base constructor. SolidColorFilterEffecter and WaterFilterEffecter then replace all four views with subclass-specific table bases. CloudFilterEffecter and StaticCloudFilterEffecter raw constructors do the same replacement but add little or no field initialization.

The class page should explicitly state that `+0xa4` and `+0xa8` are not member fields. They are inherited adjusted vptr locations from the Pane side of the object. Any field table that treats them as data members should be corrected.

## Embedded Pane And Field Reanalysis

The requested offsets `+0x94`, `+0xf9`, `+0xa4`, and `+0xa8` are all explained by the inherited Pane/GrafPort subobject.

### Complete +0x94

Complete-object `+0x94` is Pane-relative `+0x90`, because the Pane subobject starts at complete `+0x04`.

`by-class/GrafPort.md` and `WaterFilterEffecterUpdateCausticEffect` support `+0x90` as the draw alpha field for a GrafPort/Pane receiver. WaterFilterEffecter documentation already names the complete-object offset as `+0x94` and the adjusted-view offset as `+0x90`.

Best source-facing name:

```text
Pane/GrafPort::m_alpha
```

Rejected interpretation:

```text
FilterEffecter::m_opacity
```

Reason rejected: SolidColorFilterEffecter clamps and writes opacity at complete `+0x94`, but WaterFilterEffecter and its paint/update child use the same adjusted field as draw alpha. The shared offset sits inside the inherited Pane/GrafPort subobject, not in a SolidColor-only or FilterEffecter-only tail field. `m_opacity` is acceptable as a local constructor parameter or a SolidColor effect concept, but not as the field name at complete `+0x94`.

### Complete +0xf9

Complete-object `+0xf9` is Pane-relative `+0xf5`.

`Pane.md` places flag/mode bytes near this region. Since FilterEffecter inherits Pane at complete `+0x04`, writes to complete `+0xf9` are inherited Pane flag writes. SolidColorFilterEffecter and WaterFilterEffecter set this byte to `1` before registering/attaching the pane to the shared UI layer slot.

Best source-facing interpretation:

```text
Pane::m_flags or Pane::m_paneFlags, with the value 1 enabling/marking the pane for the effect registration path.
```

Rejected interpretation:

```text
FilterEffecter::m_filterActive or ScreenEffecter::m_isActive
```

Reason rejected: complete `+0xf9` is not after the Pane subobject; it is inside the Pane subobject. Existing "active byte" wording can remain as behavior language only if it clearly says the byte is inherited Pane state. It should not become a new FilterEffecter data member.

### Complete +0xa4 And +0xa8

Complete-object `+0xa4` and `+0xa8` are vptr slots for adjusted inherited Pane-side views. They correspond to Pane-relative `+0xa0` and `+0xa4`.

Best source-facing interpretation:

```text
compiler vptrs for inherited adjusted Pane/EventHandler/Timer facets
```

Rejected interpretation:

```text
FilterEffecter fields or helper pointers
```

Reason rejected: constructor stores vtable addresses there, and the ScreenEffecter vtable family documents these locations as table views across FilterEffecter and subclasses.

### Bounds And Tile Insets

The constructor initializes the inherited Pane/GrafPort bounds from the active MapPane and then insets the effect rectangle by one tile dimension on each side. The old generated draft says `g_pParcelPane`; that is stale. The support docs identify `dword_67A764` as the active MapPane/bounds provider, consistent with `OverlayEffecter`.

Best source-facing names:

- `g_activeMapPane` or equivalent final active MapPane pointer for `dword_67A764`.
- `g_mapTilePixelWidth` for `word_66DA9C`.
- `g_mapTilePixelHeight` for `word_66DAA0`.

The exact helper name used to copy active MapPane bounds into the inherited Pane/GrafPort bounds remains unresolved. A draft source body should use a descriptive method such as `GetBounds`, `GetVisibleBounds`, or `GetScreenBounds` only as provisional wording unless the exact MapPane helper has been separately named.

## Destructor And Thunk Declaration Shape

The current class doc points to a destructor/reset path beginning at `0x0055ba22` with live extent through `0x0055bb84`. The vtable evidence shows adjusted entries into this strip rather than a clean single source function body:

- The `+0x04` adjusted view for FilterEffecter points at the start of the strip.
- The `+0xa4` and `+0xa8` adjusted views use interior labels in the same destructor/reset region for this class family.
- The strip resets vtables and calls the Pane cleanup path, and scalar-deleting forms include the delete branch.

Best source-facing declaration:

```cpp
virtual ~FilterEffecter();
```

Best memory-facing naming:

```text
FilterEffecter destructor/reset strip
FilterEffecter scalar-deleting destructor and adjusted-thunk entries
```

Rejected source-facing spelling:

```cpp
FilterEffecter::ScalarDeletingDestructor(...)
```

Reason rejected: scalar-deleting destructors and adjusted-thunk entry labels are compiler artifacts. Source should declare an ordinary virtual destructor and let exact by-memory pages document wrapper entrypoints, vtable reset stores, and delete-flag behavior.

The destructor body should not be reconstructed in the class page. If an exact child page is created later, its source draft should probably be either empty/defaulted:

```cpp
FilterEffecter::~FilterEffecter() = default;
```

or an empty body:

```cpp
FilterEffecter::~FilterEffecter()
{
}
```

Any explicit calls to `Pane::~Pane`, vtable reset stores, or `operator delete` belong in the binary evidence notes, not in source C++.

## Subclass Relationships

FilterEffecter is the common base for filter-style screen effecters, not a final runtime object normally allocated by gameplay code.

Known direct subclass evidence:

- `SolidColorFilterEffecter` calls `FilterEffecter::FilterEffecter()` at `0x0055ae00`, installs four SolidColor vtables, writes the inherited alpha at complete `+0x94`, converts RGB through the palette/color conversion callback at `0x0069b404`, writes the inherited Pane flag byte at complete `+0xf9`, and registers the Pane through the shared UI layer slot.
- `CloudFilterEffecter` calls the FilterEffecter base constructor and installs four Cloud vtables. The current constructor is raw/no-xref evidence, so it should remain documented as a raw constructor until allocation/caller evidence appears.
- `StaticCloudFilterEffecter` exact raw constructor page `0x0055b090-0x0055b0c7` calls the base constructor at `0x0055b09a` and installs four StaticCloud vtables.
- `WaterFilterEffecter` calls the FilterEffecter base constructor, installs four Water vtables, loads `CAUST.EPF` and `CAUST.PAL`, initializes water-specific fields after the inherited Pane subobject, sets the inherited Pane flag byte at complete `+0xf9`, and registers with the shared UI layer slot.

The subclass constructors are strong evidence that FilterEffecter construction is a shared base operation and that layer attachment is intentionally deferred to concrete subclasses after they install their own vtables and effect-specific state. The FilterEffecter base constructor should therefore not be described as registering itself with the effect layer.

## Stale Globals And Aliases

### dword_69B364 / g_pScreenEffecterList

The old `g_pScreenEffecterList` name should remain rejected.

Evidence:

- `by-global/g_pScreenEffecterList.md` is an ignored stale alias page.
- `by-global/MainUiLayerSlots.md` documents startup initialization, shutdown cleanup, and broad UI ownership for the slot at `0x0069b364`.
- Effecter constructors consume the slot as a layer/context argument to the Pane attach helper. They do not own the global and do not manage it as an effecter list.

Best current documentation:

```text
dword_69B364 is a Main UI layer/context slot used by effecters during Pane registration; final per-slot source name unresolved.
```

Acceptable provisional names:

```text
g_mainUiLayerContext0
g_mainUiLayerSlots[0]
```

Rejected name:

```text
g_pScreenEffecterList
```

### dword_67A764 / g_activeMapPane

The constructor's bounds provider matches the active MapPane interpretation. `OverlayEffecter` has parallel evidence: it builds a Pane at `this+4`, reads from `dword_67A764`, applies map tile globals, and uses the shared UI layer slot. The FilterEffecter class page should follow that naming direction.

Best name:

```text
g_activeMapPane
```

Rejected name:

```text
g_pParcelPane
```

Reason rejected: the active MapPane/OverlayEffecter evidence is stronger and the old generated `g_pParcelPane` spelling is not supported by the cross-document source-quality pass.

## Heuristic / Inference Reanalysis And Validation

### Inference: FilterEffecter uses multiple inheritance, not composition

Evidence checked:

- Constructor calls the Pane constructor on `this+4`.
- Four vtable stores install FilterEffecter views at complete `+0x00`, `+0x04`, `+0xa4`, and `+0xa8`.
- Pane vtable data and PaneCore show normal Pane-side adjusted view offsets.
- Subclasses reinstall the same four-view pattern after the base constructor.

Rejected alternative:

```text
FilterEffecter contains a Pane member named m_pane.
```

Why rejected:

The generated constructor call shape could superficially look like composition, but the adjusted vtable views at complete `+0x04`, `+0xa4`, and `+0xa8` make the inherited-subobject interpretation stronger. A source member `Pane m_pane;` would not naturally explain virtual dispatch through adjusted FilterEffecter/Pane views as cleanly as `public Pane` or equivalent inheritance.

Confidence:

High. This inference should be applied to target and support docs.

### Inference: complete +0x94 is inherited alpha

Evidence checked:

- WaterFilterEffecter update page documents adjusted-view `+0x90` / complete `+0x94` as alpha/draw alpha.
- GrafPort page documents draw-mode and alpha fields in the same area.
- SolidColorFilterEffecter writes opacity into complete `+0x94`, but that is the same inherited draw-alpha storage used by the filter branch, not a SolidColor-only field.

Rejected alternatives:

- `FilterEffecter::m_opacity`
- `SolidColorFilterEffecter::m_opacity` as the field name for complete `+0x94`
- `GrafPort::m_usesSoftwareBuffer` using full-object GrafPort offset arithmetic

Why rejected:

The receiver is not a full object starting at the GrafPort subobject for complete-object arithmetic. FilterEffecter's Pane/GrafPort subobject begins at `+0x04`, so complete `+0x94` maps to adjusted Pane/GrafPort `+0x90`.

Confidence:

High. This should be applied across FilterEffecter, SolidColorFilterEffecter, and WaterFilterEffecter wording.

### Inference: complete +0xf9 is inherited Pane flag state

Evidence checked:

- Pane layout places flags near Pane-relative `+0xf5`.
- FilterEffecter's Pane subobject starts at complete `+0x04`.
- SolidColorFilterEffecter and WaterFilterEffecter set complete `+0xf9` immediately before layer registration.

Rejected alternatives:

- `FilterEffecter::m_filterActive`
- `ScreenEffecter::m_isActive`
- A Water/SolidColor-specific completion byte

Why rejected:

The offset falls inside the inherited Pane subobject. The behavior is activation-like, but the source member should remain a Pane flag until exact Pane bit semantics are resolved.

Confidence:

Medium-high. The offset arithmetic is strong; the exact flag name and bit meaning are not yet final.

### Inference: FilterEffecter constructor should not attach to the layer

Evidence checked:

- The generated FilterEffecter constructor draft initializes base Pane state and bounds.
- SolidColorFilterEffecter and WaterFilterEffecter perform concrete effect-specific initialization and then call the layer attach path.
- OverlayEffecter, which is a concrete overlay base-like object, does attach after setting its own state, but FilterEffecter is used as an abstract/shared base for concrete filter subclasses.

Rejected alternative:

```text
FilterEffecter::FilterEffecter registers itself with dword_69B364.
```

Why rejected:

The subclass constructors provide direct registration evidence after subclass vtable/state setup. The base constructor range does not carry the same final registration call pattern in the available docs.

Confidence:

High enough for class documentation. Exact constructor child C++ should still be checked against decompilation before emission.

### Inference: class page should not emit method bodies

Evidence checked:

- Supervisor guidance says class files that emit should generally emit class-level declarations, not detailed method bodies.
- The constructor and destructor/reset strip are exact by-memory concerns with concrete ranges and thunk details.
- The destructor/reset strip contains compiler artifacts that would be easy to overfit into false source code.

Rejected alternative:

```text
Put FilterEffecter::FilterEffecter() and destructor bodies directly in by-class/FilterEffecter.md.
```

Why rejected:

That would make the class page do method-page work and would risk emitting compiler-generated destructor scaffolding as source. A class declaration is eligible; method bodies should wait for exact child pages.

Confidence:

High.

## First-Draft C++ Recommendation

### Target class page

The target class page is eligible for class-level first-draft C++ only. Recommended formal C++ for `by-class/FilterEffecter.md`:

```cpp
class FilterEffecter : public ScreenEffecter, public Pane
{
public:
    FilterEffecter();
    virtual ~FilterEffecter();

    bool IsPixelEffecter() const override { return false; }
};
```

Notes for implementation:

- Do not add field declarations for `+0xa4` or `+0xa8`; they are adjusted vptr slots.
- Do not add a FilterEffecter-owned field for complete `+0x94`; it is inherited Pane/GrafPort alpha.
- Do not add a FilterEffecter-owned field for complete `+0xf9`; it is inherited Pane flag state.
- If the project's emitter cannot place class declarations in a header-like output yet, the implementation should keep the formal C++ block blank and document this as a generator placement limitation, not as a reconstruction limitation. The target remains reconstructable because the class shape is recoverable.

### Future exact constructor page

If implementation creates an exact child for `0x0055ad00-0x0055adba`, the first-draft constructor body should be carried there, not on the class page. A source-plausible draft is:

```cpp
FilterEffecter::FilterEffecter()
    : ScreenEffecter(),
      Pane(2)
{
    Rect bounds;

    g_activeMapPane->GetBounds(&bounds);
    bounds.left += g_mapTilePixelWidth;
    bounds.top += g_mapTilePixelHeight;
    bounds.right -= g_mapTilePixelWidth;
    bounds.bottom -= g_mapTilePixelHeight;

    SetBounds(bounds);
}
```

Draft caveats:

- `Pane(2)` should be renamed to a pane-mode enum when the source enum is known.
- `GetBounds` and `SetBounds` are descriptive placeholders. The exact MapPane and Pane/GrafPort helper names need method-page confirmation before final source emission.
- The draft intentionally omits any `dword_69B364` registration call; concrete subclasses perform the attachment after subclass state setup.
- The draft intentionally omits explicit vtable stores; those are compiler output.

### Future destructor/thunk page

If implementation creates an exact child for the destructor/reset strip, the page should not emit scalar-deleting destructor source code. The source-facing destructor recommendation is:

```cpp
FilterEffecter::~FilterEffecter() = default;
```

or, if local style avoids defaulted declarations:

```cpp
FilterEffecter::~FilterEffecter()
{
}
```

The exact page should document vtable reset stores, adjusted entry labels, Pane cleanup, and delete-flag behavior as compiler evidence, not as hand-authored source.

## Score Recommendation

Recommended target metadata:

```yaml
COMPLETION:88
CONFIDENCE:90
RECONSTRUCTABLE:TRUE
CANONICAL_OWNER:0000IZ
EMITTER_UIDS:0000IZ
```

Why completion should increase:

- Source placement is sufficiently resolved to `render/Effects.cpp` / Effects family ownership.
- Multiple-inheritance shape is now supported by constructor, vtable, Pane, and subclass evidence.
- The stale `g_pParcelPane` constructor name is superseded by `g_activeMapPane`.
- `word_66DA9C` and `word_66DAA0` have stable names.
- `dword_69B364` has a clear non-Effects-owner interpretation through `MainUiLayerSlots`; the stale `g_pScreenEffecterList` alias can be rejected.
- Requested field offsets have best-supported interpretations:
  - `+0x94`: inherited alpha.
  - `+0xf9`: inherited Pane flags.
  - `+0xa4/+0xa8`: adjusted vptrs.
- The class-level first-draft declaration is safe enough to recommend.

Why not above 90/90:

- The exact constructor helper names for bounds copy/set are still unresolved.
- The pane-mode enum name for constructor argument `2` remains unresolved.
- The exact flag semantics at Pane-relative `+0xf5` need a Pane-focused pass before naming the bit beyond `Pane::m_flags`.
- The destructor/reset strip still needs exact by-memory page treatment before final source C++ can be emitted for destructor behavior.
- The final source header split (`Effects.h` versus future `render/effects/` structure) remains a file-level open question, though it does not block the class source placement under Effects.

## Open Questions After Reanalysis

The following questions remain, but each now has a bounded impact:

- Exact pane mode name for constructor argument `2`: likely a filter/effect pane mode. Does not block class declaration; blocks polished constructor C++.
- Exact MapPane bounds helper name used by `0x0055ad00`: likely `GetBounds`, `GetVisibleBounds`, or equivalent. Does not block source placement; blocks final constructor body naming.
- Exact Pane flag bit at complete `+0xf9` / Pane `+0xf5`: likely activation/registration-visible state. It should remain an inherited Pane flag until Pane bit semantics are resolved.
- Exact destructor/reset sub-entry split across FilterEffecter and nearby filter-family adjusted thunks: blocks destructor child source emission; does not block class declaration.
- Exact final name for the `dword_69B364` Main UI layer/context slot: do not use stale `g_pScreenEffecterList`; keep `MainUiLayerSlots` cross-reference if no final slot name exists.

No open question requires keeping vague helper names or compiler placeholders in the target class narrative. The target can state best-supported names and explicitly reserve only the unresolved exact enum/helper/flag names.

## Implementation Checklist

Target doc `by-class/FilterEffecter.md`:

- Update metadata to `COMPLETION:88`, `CONFIDENCE:90`; retain owner/emitter [UID:0000IZ].
- Replace generated/stale source placement wording with `render/Effects.cpp` / Effects family ownership; mark `source-3/simroot_v2/class_FilterEffecter.cpp` as generated staging evidence only.
- State the source class shape as `FilterEffecter : public ScreenEffecter, public Pane`.
- Add or revise layout notes for complete offsets `+0x00`, `+0x04`, `+0x94`, `+0xa4`, `+0xa8`, and `+0xf9`.
- Replace `g_pParcelPane` with `g_activeMapPane` in constructor narrative.
- Replace raw tile globals with `g_mapTilePixelWidth` and `g_mapTilePixelHeight`.
- Reject `g_pScreenEffecterList` for `dword_69B364`; point to `MainUiLayerSlots`.
- Clarify that base constructor initializes Pane/GrafPort bounds but concrete subclasses perform layer registration.
- Clarify destructor declaration as source `virtual ~FilterEffecter()` and memory evidence as compiler destructor/reset/scalar-deleting thunk strip.
- Add target formal C++ only as a class declaration if the emitter supports class-level declarations. Do not put constructor/destructor bodies in the class page.

Support docs:

- `by-file/Effects.md`: update FilterEffecter method inventory/source-placement notes, reject one-class generated file split, clarify FilterEffecter base versus concrete subclass registration, and record that exact constructor/destructor child pages are the correct place for method bodies.
- `by-type/by-vtable/ScreenEffecterVtableFamily.md`: refine FilterEffecter row to say complete `+0x04` is inherited Pane view and `+0xa4/+0xa8` are inherited adjusted Pane views, not fields.
- `by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md`: update FilterEffecter table-slice notes with constructor store addresses and destructor/thunk wording.
- `by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md`: correct stale `g_pParcelPane`/`g_pScreenEffecterList` wording, note `+0x94`/`+0xf9` adjusted inherited-field interpretation, and preserve aggregate no-code behavior for broad runtime cluster.
- `by-class/SolidColorFilterEffecter.md`: change `+0x94` field language to inherited alpha, and `+0xf9` to inherited Pane flags; keep SolidColor color conversion/cache notes.
- `by-class/WaterFilterEffecter.md` and `by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md`: ensure complete/view offset wording stays explicit (`view +0x90 == complete +0x94`) and avoid treating `+0xf9` as a Water-owned field.
- `by-class/CloudFilterEffecter.md` and `by-class/StaticCloudFilterEffecter.md`: ensure base-constructor/vtable replacement notes reference the resolved FilterEffecter class shape and avoid invented source fields.
- `by-global/g_pScreenEffecterList.md` and/or `by-global/MainUiLayerSlots.md`: if touched, reinforce that `dword_69B364` is a Main UI layer/context slot consumed by effecter Pane registration, not a screen effecter list.
- `by-global/MapTilePixelDimensions.md`: no required content change if current names remain stable; cross-link from FilterEffecter if useful.
- `by-class/Pane.md`, `by-memory/0x00544460-0x00545086.PaneCore.md`, and `by-class/GrafPort.md`: no required changes unless implementation wants stronger cross-links for the adjusted inherited offsets. If edited, keep focus on offset arithmetic rather than FilterEffecter-specific behavior.
- Generated output: refresh or inspect `auto-generated/NexusTK/render/Effects.cpp` after implementation. Expect either a class declaration for FilterEffecter or a documented blank/no-code marker if the generator cannot place class declarations yet.

Exact child-page recommendation for a later implementation pass:

- Create `by-memory/0x0055ad00-0x0055adba.FilterEffecterConstructor.md` only if the implementation pass is allowed to add method pages. It should be [UID assigned by validator], owner/emitter [UID:0000IZ], reconstructable true, and should carry the constructor first-draft C++ after confirming helper names or documenting their provisional status.
- Do not automatically create a broad destructor source child unless the exact strip split is audited. If a destructor-strip child is created, classify it as compiler destructor/thunk evidence and keep formal C++ to source declaration/defaulted destructor only.

## Exact Coverage Text For Supervisor-Owned Updates

Recommended `by-class/-coverage-report.md` replacement row for [UID:00004Y]:

```text
- [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md) : reconstructable : 88% : very strong : Source-quality pass resolves FilterEffecter as the pane-backed filter base in `render/Effects.cpp`, best modeled as `class FilterEffecter : public ScreenEffecter, public Pane`; constructor `0x0055ad00-0x0055adba` builds the inherited Pane with mode 2, installs four vtable views at complete offsets +0/+4/+0xa4/+0xa8, reads bounds from `g_activeMapPane`, and insets them by `g_mapTilePixelWidth`/`g_mapTilePixelHeight`; complete +0x94 is inherited Pane/GrafPort alpha, complete +0xf9 is inherited Pane flag state, +0xa4/+0xa8 are adjusted vptrs, `dword_69B364`/old `g_pScreenEffecterList` is a Main UI layer/context slot, and method bodies should be emitted only on exact by-memory child pages while the class page emits at most a class-level declaration.
```

No `by-memory/-coverage-report.md` row should be changed for this report-only pass. If a later accepted implementation creates exact constructor/destructor method pages, validator-assigned UIDs must be used and the coverage rows should be written after those pages exist.

## Exact Validator Commands For Implementation

Run from:

```text
E:\NTK\GhidraBridge\source-3\project-documentation
```

Minimum target command:

> Executable block R002 was removed from this report and preserved verbatim in [00004Y-FilterEffecter-class-source-quality-removed.md](00004Y-FilterEffecter-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the implementation edits all recommended support docs, run these scoped validators:

> Executable block R003 was removed from this report and preserved verbatim in [00004Y-FilterEffecter-class-source-quality-removed.md](00004Y-FilterEffecter-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If new exact by-memory child pages are created, additionally validate each new page with:

> Executable block R004 was removed from this report and preserved verbatim in [00004Y-FilterEffecter-class-source-quality-removed.md](00004Y-FilterEffecter-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Final Status

This report is ready for supervisor review. No `by-*` docs were edited. No coverage report was edited. The implementation pass should apply the target/support changes above only after supervisor acceptance.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B013","command_id":"000000004165","destination_path":"executed-b-agent-research/B013/00004Y-FilterEffecter-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:35","uid":"00004Y"} -->
<!-- {"agent":"B013","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00004Y-FilterEffecter-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B013/00004Y-FilterEffecter-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00004Y"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
