*** UID:00004Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class FilterEffecter : public ScreenEffecter, public Pane
{
public:
    FilterEffecter();
    virtual ~FilterEffecter();

    bool IsPixelEffecter() const override { return false; }
};
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# FilterEffecter

## Status

- Confidence: very strong for role, `render/Effects.cpp` ownership, vtable identity, multiple-inheritance shape, and subclass base-constructor evidence; medium-high for exact constructor helper names and exact Pane flag bit semantics.
- Proposed source: [UID:0000IZ][Effects](by-file/Effects.md) / `render/Effects.cpp`, with declarations likely in `render/Effects.h` or the same Effects compilation unit depending on the final header split.
- Generated-source caveat: `source-3/simroot_v2/class_FilterEffecter.cpp` is staging evidence only. Do not treat the one-class recovered file as an original source split.
- Current memory ranges: constructor `0x0055ad00-0x0055adba`; destructor/reset strip begins at `0x0055ba22` with live extent through the filter-family destructor/thunk area.
- Runtime owner evidence: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) covers the filter constructor/destructor block, and [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) covers the matching read-only vtable data.
- Source C++ policy: this class page emits the class-level declaration only. Constructor/destructor bodies belong on exact by-memory method pages if those pages are created later.

## Responsibility

`FilterEffecter` is the pane-backed base class for full-screen or map-view filters. The best source-facing class shape is:

```cpp
class FilterEffecter : public ScreenEffecter, public Pane
```

The constructor builds the inherited `Pane`/`GrafPort` side with mode `2`, installs four FilterEffecter vtable views, reads bounds from the active MapPane bounds provider (`dword_67A764`, best documented as `g_activeMapPane`), and insets the effect rectangle by the tile-margin globals [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md): `g_mapTilePixelWidth` and `g_mapTilePixelHeight`.

Rejected stale wording:

- `g_pParcelPane` is a generated/stale constructor name for the active MapPane bounds provider. The OverlayEffecter/FilterEffecter constructor pattern and map-layout support docs favor `g_activeMapPane` or an equivalent active MapPane pointer name.
- `g_pScreenEffecterList` is not an Effects-owned list. The backing storage `dword_69B364` is a Main UI layer/context slot documented by [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md), with [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md) retained only as an ignored generated alias.
- `+0xa4` and `+0xa8` are not data members. They are adjusted inherited Pane-side vptr slots.
- Complete `+0x94` is inherited Pane/GrafPort alpha state, not a FilterEffecter-private opacity member.
- Complete `+0xf9` is inherited Pane flag state, not a FilterEffecter-owned active byte.

Known derived filters include [UID:0000DE][SolidColorFilterEffecter](by-class/SolidColorFilterEffecter.md), [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md), [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md), and [UID:0000FZ][WaterFilterEffecter](by-class/WaterFilterEffecter.md).

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055ad00-0x0055adba` | `FilterEffecter::FilterEffecter` | Base constructor for inherited Pane/GrafPort filter geometry. Exact method-body C++ should be emitted only by a future exact constructor page. |
| `0x0055ba22-0x0055bb84` | destructor/reset strip | Live IDA models a larger vtable-reset and pane teardown strip with adjusted entries. Source declaration is ordinary `virtual ~FilterEffecter()`, while scalar-deleting destructor flags, adjusted labels, vtable stores, Pane cleanup, and `operator delete` are compiler evidence for exact method pages. |

## Vtable And Layout Evidence

| Evidence | Detail |
| --- | --- |
| Source owner | [UID:0000IZ][Effects](by-file/Effects.md) groups `FilterEffecter` into `render/Effects.cpp` with the adjacent screen, overlay, color, cloud, static-cloud, water, and displacement effecters. |
| Source split | The one-class generated `class_FilterEffecter.cpp` is a staging artifact. The runtime cluster, vtable order, sibling constructors, and shared globals support the Effects-family source route instead. |
| Source declaration | `FilterEffecter : public ScreenEffecter, public Pane`. The `Pane` subobject starts at complete-object `+0x04`, which explains the inherited view offsets and inherited Pane/GrafPort fields. |
| Four-view shape | [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) records the filter-family object views at complete offsets `+0x00`, `+0x04`, `+0xa4`, and `+0xa8`. The latter three are inherited adjusted Pane-side views, not fields. |
| Vtable bases | Primary `0x00623944`, `+0x04` view `0x00623964`, `+0xa4` view `0x006239b0`, and `+0xa8` view `0x006239e0`. |
| Constructor stores | `0x0055ad41`, `0x0055ad4d`, `0x0055ad54`, and `0x0055ad5e` install the four views after the base pane construction. |
| Read-only data | [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) lists `0x00623944-0x006239e0` as the exact `FilterEffecter` vtable-view span. |
| Runtime block | [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) places `0x0055ad00-0x0055afa4` in the filter/solid-color block and inventories `sub_55AD00`, `sub_55AE00`, `sub_55AED0`, and `sub_55AF60`. |

## Embedded Pane And Offset Interpretation

The requested offset issues are resolved by treating the object as `ScreenEffecter` plus an inherited `Pane`/`GrafPort` subobject at complete `+0x04`.

| Complete offset | Source-facing interpretation | Evidence and rejected alternative |
| --- | --- | --- |
| `+0x00` | `ScreenEffecter` primary vptr | Primary FilterEffecter vtable base `0x00623944` stored at `0x0055ad41`. |
| `+0x04` | inherited `Pane`/`GrafPort` subobject start | Constructor calls the Pane initializer `sub_544460(this + 4, 2)` before installing the adjusted FilterEffecter Pane/GrafPort view at `0x00623964`. This favors inheritance over a `Pane m_pane` composition member because the object has adjusted virtual views. |
| `+0x94` | inherited Pane/GrafPort `m_alpha` / draw alpha (`Pane`/view-relative `+0x90`) | [UID:0000FZ][WaterFilterEffecter](by-class/WaterFilterEffecter.md), [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md), and [UID:00005V][GrafPort](by-class/GrafPort.md) use view `+0x90` as alpha. Reject `FilterEffecter::m_opacity`; opacity is a SolidColor constructor concept stored in inherited alpha state. |
| `+0xa4` | adjusted inherited Pane/EventHandler-style vptr | Constructor store at `0x0055ad54` writes vtable base `0x006239b0`. Reject data-member/helper-pointer interpretations. |
| `+0xa8` | adjusted inherited Pane timer/event-style vptr | Constructor store at `0x0055ad5e` writes vtable base `0x006239e0`. Reject data-member/helper-pointer interpretations. |
| `+0xf9` | inherited Pane flag byte (`Pane`-relative `+0xf5`) | [UID:0001VH][PaneLayout](by-type/by-struct/PaneLayout.md) and [UID:0000A2][Pane](by-class/Pane.md) place flags near Pane `+0xf5`; SolidColor and Water set complete `+0xf9` before layer registration. Keep behavior language such as active/registration-visible only as a description, not as `FilterEffecter::m_filterActive`. |

2026-06-14 live IDA MCP evidence:

- `analyze_function 0x0055ad00` reports a `0xbb`-byte base constructor that writes the `ScreenEffecter` vtable, calls the pane/base initializer `sub_544460(this + 4, 2)`, installs all four `FilterEffecter` vtable views, reads bounds through `dword_67A764` / `g_activeMapPane`, and applies the tile-margin insets from `g_mapTilePixelWidth` / `g_mapTilePixelHeight`.
- `analyze_component` confirms `SolidColorFilterEffecter` at `0x0055ae00` and `WaterFilterEffecter` at `0x0055b6a0` call `0x0055ad00`; direct xrefs also include the raw cloud/static-cloud constructor starts at `0x0055b00a` and `0x0055b09a`.
- Backward data-flow from vtables `0x00623944`, `0x00623964`, `0x006239b0`, and `0x006239e0` reconfirms constructor stores at `0x0055ad41`, `0x0055ad4d`, `0x0055ad54`, and `0x0055ad5e`, plus destructor/subclass reset stores at solid-color, cloud/static-cloud raw starts, water destructor/reset, and final filter teardown paths.
- `analyze_function 0x0055ba22` confirms the reset/destructor path restores all four `FilterEffecter` views, calls the Pane cleanup path (`sub_544580` family), restores the `ScreenEffecter` base vtable, and conditionally deletes through the LObject/delete helper. These are compiler/destructor-strip facts; source should declare `virtual ~FilterEffecter()` rather than a scalar-deleting destructor method.

## Base Constructor Evidence

- [UID:0000IZ][Effects](by-file/Effects.md) and [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) both record the base constructor boundary as `0x0055ad00-0x0055adba`/`0x0055adbb`.
- The constructor builds the base pane/filter geometry, installs the four screen/pane interface vtable views, reads bounds from the active MapPane bounds provider, and applies the `g_mapTilePixelWidth` / `g_mapTilePixelHeight` inset.
- Derived constructors call this base before installing their own vtables: [UID:0000DE][SolidColorFilterEffecter](by-class/SolidColorFilterEffecter.md) at `0x0055ae00`, [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md) at `0x0055b000`, [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md) at `0x0055b090`, and [UID:0000FZ][WaterFilterEffecter](by-class/WaterFilterEffecter.md) at `0x0055b6a0`.

## Subclass Notes

- [UID:0000DE][SolidColorFilterEffecter](by-class/SolidColorFilterEffecter.md) calls `FilterEffecter::FilterEffecter()`, installs four SolidColor views, writes the inherited alpha at complete `+0x94`, converts RGB through `dword_69B404`, sets the inherited Pane flag byte at complete `+0xf9`, and registers the inherited Pane through `dword_69B364` / [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md).
- [UID:0000FZ][WaterFilterEffecter](by-class/WaterFilterEffecter.md) calls `FilterEffecter::FilterEffecter()`, installs four Water views, loads `CAUST.EPF` and `CAUST.PAL`, initializes water-specific fields after the inherited Pane subobject, sets the inherited Pane flag byte at complete `+0xf9`, and registers through the same Main UI layer/context slot.
- [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md) and [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md) are raw constructor-only specializations that call the FilterEffecter base and replace all four views, but no caller/xref recovery currently proves normal construction routes.

Subclass evidence is important for source semantics: concrete subclasses attach/register the inherited Pane after installing subclass vtables and effect-specific state. The FilterEffecter base constructor initializes bounds and inherited Pane state; it should not be described as registering itself with the UI layer.

## Destructor And Thunk Shape

The memory region beginning at `0x0055ba22` is best documented as a destructor/reset strip with adjusted entries:

- the `+0x04` adjusted view points at the strip start;
- the `+0xa4` and `+0xa8` adjusted views use interior labels in the same strip;
- the strip resets vtables, runs Pane cleanup, restores ScreenEffecter base state, and scalar-deleting forms conditionally release storage.

Source-facing declaration:

```cpp
virtual ~FilterEffecter();
```

Rejected source-facing spelling:

```cpp
FilterEffecter::ScalarDeletingDestructor(...)
```

Scalar deleting destructor flags, adjusted entry labels, explicit vtable stores, and `operator delete` calls are compiler output. If a future exact destructor page is created, the first-draft source should be an empty/defaulted destructor, while the binary page documents the thunk/delete details.

## Reconstruction Notes

- `FilterEffecter` is marked reconstructable because source ownership under [UID:0000IZ][Effects](by-file/Effects.md), the base constructor range, the four-view vtable identity, the subclass constructor call pattern, and inherited Pane/GrafPort offset arithmetic are now documented with stable evidence.
- `RECONSTRUCTION_CPP CODE` contains a class-level declaration only. Constructor and destructor bodies are deliberately not emitted here because those need exact by-memory method ranges and helper-name validation.
- Do not move the shared `dword_69B364` UI layer/context slot into this class or its solid-color subclass solely from constructor use. [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md) is an ignored generated alias, and [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) owns the slot family.
- Do not add FilterEffecter data fields for complete `+0x94`, `+0xf9`, `+0xa4`, or `+0xa8`. The first two are inherited Pane/GrafPort state and the last two are adjusted vptr slots.

## Remaining Open Questions

- Exact pane mode name for constructor argument `2`: likely a filter/effect pane mode. This does not block the class declaration, but it blocks polished constructor C++.
- Exact MapPane bounds helper called by the constructor: likely `GetBounds`, `GetVisibleBounds`, or equivalent. Keep helper names descriptive until an exact constructor page audits call sites and signatures.
- Exact Pane flag bit at complete `+0xf9` / Pane `+0xf5`: behavior is activation/registration-visible, but the source member should remain inherited Pane flag state until the Pane bitfield is named.
- Exact final name for `dword_69B364`: use Main UI layer/context wording or a `MainUiLayerSlots` cross-reference; do not revive `g_pScreenEffecterList`.
- Exact original header split: this class belongs to `render/Effects.cpp`/Effects family, but whether declarations lived in `Effects.h` or a smaller private effects header remains file-level.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `88` | The page now records the live constructor body, exact four-view vtable stores, destructor/reset-strip behavior, subclass base-call xrefs, runtime/read-only-data support, source-owner route through [UID:0000IZ][Effects](by-file/Effects.md), the `ScreenEffecter, Pane` declaration shape, inherited Pane/GrafPort offset meanings, corrected globals, and stale-name rejections. Completion remains below 90 because the exact constructor helper names, pane-mode enum, and destructor-strip split still need exact method pages. |
| Confidence `90` | Confidence is very strong for `render/Effects.cpp` ownership, `FilterEffecter` identity, vtable layout, and inherited Pane/GrafPort field interpretation. It is not higher because cloud/static-cloud constructor starts are still raw byte boundaries, the exact `+0xf9` flag name is unresolved, and the final header/source split for the effecter family remains open. |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0000C9][ScreenEffecter](by-class/ScreenEffecter.md)
- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md)
- [UID:0000DE][SolidColorFilterEffecter](by-class/SolidColorFilterEffecter.md)
- [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md)
- [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md)
- [UID:0000FZ][WaterFilterEffecter](by-class/WaterFilterEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md)
- [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md)
- [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:00005V][GrafPort](by-class/GrafPort.md)

## Changes

- 2026-06-19 B013 accepted source-quality implementation:
  - Before: scored `85/86`, retained generated `g_pParcelPane` wording, left `+0x94/+0xf9/+0xa4/+0xa8` as open layout blockers, and kept class-level C++ blank.
  - After: scored `88/90`, retained owner/emitter [UID:0000IZ][Effects](by-file/Effects.md), populated a class-level declaration for `FilterEffecter : public ScreenEffecter, public Pane`, and documented that method bodies belong only on future exact by-memory method pages.
  - Evidence: the accepted B013 report ties constructor stores `0x0055ad41/0x0055ad4d/0x0055ad54/0x0055ad5e`, vtable bases `0x00623944/0x00623964/0x006239b0/0x006239e0`, inherited Pane construction at `this+4`, active MapPane/tile-dimension bounds insets, subclass base-constructor calls, Water/SolidColor inherited alpha and Pane flag usage, [UID:0000T6][MainUiLayerSlots](by-global/MainUiLayerSlots.md) for `dword_69B364`, and destructor/reset-strip evidence. Rejected stale interpretations are preserved: `g_pParcelPane`, `g_pScreenEffecterList`, FilterEffecter-owned `+0x94/+0xf9` fields, and data fields at `+0xa4/+0xa8`.
- 2026-06-14 A001 Goal 2 refresh:
  - Before: scored `80/84`.
  - After: scored `85/86`; owner/emitter remains [UID:0000IZ][Effects](by-file/Effects.md); final C++ remains blank below the active `90/90+` code-entry gate.
  - Evidence: live IDA MCP `analyze_function` and `trace_data_flow` reconfirmed the `0x0055ad00` constructor size/body, four constructor vtable stores, destructor/reset path at `0x0055ba22`, subclass calls from solid-color/water plus raw cloud/static-cloud xrefs, and exact vtable-backref fanout through the ScreenEffecter runtime/read-only-data support pages.
- 2026-06-02: Raised `68/76` to `80/84`, marked reconstructable, and attached to [UID:0000IZ][Effects](by-file/Effects.md). Added four-view vtable/store evidence, runtime cluster links, derived-constructor call evidence, and reconstruction blockers. `RECONSTRUCTION_CPP CODE` remains blank because final field names, destructor/thunk spelling, and class declaration layout still need a source-quality audit. Evidence: [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md), [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md), [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md), and [UID:0000IZ][Effects](by-file/Effects.md).
- Completion/confidence score update: existed before as `0/0`; changed to `68/76`. Summary: base role, constructor/destructor ranges, and subclass relationships were documented, but exact original file split and complete method inventory remained only medium-confidence. Evidence: documented ranges `0x0055ad00-0x0055adba` and the destructor/reset start at `0x0055ba22`, plus cross-references to the screen-effecter runtime cluster and derived filter pages.
