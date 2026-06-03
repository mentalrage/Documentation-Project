*** UID:00004Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FilterEffecter

## Status

- Confidence: strong for role, source-module ownership, and relationship to subclasses; medium-high for the exact class declaration and embedded pane layout.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_FilterEffecter.cpp`
- Current memory ranges: `0x0055ad00-0x0055adba`, `0x0055ba22-0x0055ba29`
- Runtime owner evidence: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) covers the filter constructor block, and [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) covers the matching read-only vtable data.

## Responsibility

`FilterEffecter` is the pane-backed base class for full-screen or map-view filters. It constructs a type-2 pane, installs multiple vtable slots, reads bounds from `g_pParcelPane`, and insets the effect rectangle by tile margins.

Known derived filters include [UID:0000DE][SolidColorFilterEffecter](by-class/SolidColorFilterEffecter.md), [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md), [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md), and [UID:0000FZ][WaterFilterEffecter](by-class/WaterFilterEffecter.md).

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055ad00-0x0055adba` | `FilterEffecter` | Base constructor for full-screen filter pane geometry. |
| `0x0055ba22-0x0055ba29` | `ScalarDeletingDestructor` | Pane-interface thunk/destructor path; Wave3 attributes a short range. |

## Vtable And Layout Evidence

| Evidence | Detail |
| --- | --- |
| Source owner | [UID:0000IZ][Effects](by-file/Effects.md) groups `FilterEffecter` into `render/Effects.cpp` with the adjacent screen, overlay, color, cloud, static-cloud, water, and displacement effecters. |
| Four-view shape | [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) records the filter-family object views at `+0x00`, `+0x04`, `+0xa4`, and `+0xa8`. |
| Vtable bases | Primary `0x00623944`, `+0x04` view `0x00623964`, `+0xa4` view `0x006239b0`, and `+0xa8` view `0x006239e0`. |
| Constructor stores | `0x0055ad41`, `0x0055ad4d`, `0x0055ad54`, and `0x0055ad5e` install the four views after the base pane construction. |
| Read-only data | [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md) lists `0x00623944-0x006239e0` as the exact `FilterEffecter` vtable-view span. |
| Runtime block | [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) places `0x0055ad00-0x0055afa4` in the filter/solid-color block and inventories `sub_55AD00`, `sub_55AE00`, `sub_55AED0`, and `sub_55AF60`. |

## Base Constructor Evidence

- [UID:0000IZ][Effects](by-file/Effects.md) and [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) both record the base constructor boundary as `0x0055ad00-0x0055adba`/`0x0055adbb`.
- The constructor builds the base pane/filter geometry, installs the four screen/pane interface vtable views, reads the parcel-pane bounds, and applies the tile-margin inset described in the generated class page.
- Derived constructors call this base before installing their own vtables: [UID:0000DE][SolidColorFilterEffecter](by-class/SolidColorFilterEffecter.md) at `0x0055ae00`, [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md) at `0x0055b000`, [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md) at `0x0055b090`, and [UID:0000FZ][WaterFilterEffecter](by-class/WaterFilterEffecter.md) at `0x0055b6a0`.

## Subclass Notes

- [UID:0000DE][SolidColorFilterEffecter](by-class/SolidColorFilterEffecter.md) fills a buffer with a 16-bit converted RGB color and uses the shared `dword_69B364` UI layer/context slot during pane setup; older generated data called this [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md).
- [UID:0000FZ][WaterFilterEffecter](by-class/WaterFilterEffecter.md) loads/advances a caustic palette frame and renders water filter frames.
- Cloud filter variants are currently constructor-only specializations that mainly install vtables.

## Reconstruction Notes

- `FilterEffecter` is marked reconstructable because source ownership under [UID:0000IZ][Effects](by-file/Effects.md), the base constructor range, and the four-view vtable identity are now documented with stable evidence.
- `RECONSTRUCTION_CPP CODE` remains blank. The final C++ needs a joint audit of the embedded pane/filter layout, field names around the `+0x94`, `+0xf9`, `+0xa4`, and `+0xa8` regions, destructor/thunk spelling, and the declaration relationship to the filter subclasses.
- Do not move the shared `dword_69B364` UI layer/context slot into this class or its solid-color subclass solely from constructor use. The stale [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md) alias is tracked separately from the effecter source module.

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

## Changes

- 2026-06-02: Raised `68/76` to `80/84`, marked reconstructable, and attached to [UID:0000IZ][Effects](by-file/Effects.md). Added four-view vtable/store evidence, runtime cluster links, derived-constructor call evidence, and reconstruction blockers. `RECONSTRUCTION_CPP CODE` remains blank because final field names, destructor/thunk spelling, and class declaration layout still need a source-quality audit. Evidence: [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md), [UID:0002OR][0x006235a0-0x00623d18.ScreenEffecterVtableData](by-memory/0x006235a0-0x00623d18.ScreenEffecterVtableData.md), [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md), and [UID:0000IZ][Effects](by-file/Effects.md).
- Completion/confidence score update: existed before as `0/0`; changed to `68/76`. Summary: base role, constructor/destructor ranges, and subclass relationships are documented, but exact original file split and complete method inventory remain only medium-confidence. Evidence: documented ranges `0x0055ad00-0x0055adba` and `0x0055ba22-0x0055ba29`, plus cross-references to the screen-effecter runtime cluster and derived filter pages.
