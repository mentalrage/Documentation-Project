*** UID:00004Y | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# FilterEffecter

## Status

- Confidence: strong for role and relationship to subclasses, medium for exact original file split.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_FilterEffecter.cpp`
- Current memory ranges: `0x0055ad00-0x0055adba`, `0x0055ba22-0x0055ba29`

## Responsibility

`FilterEffecter` is the pane-backed base class for full-screen or map-view filters. It constructs a type-2 pane, installs multiple vtable slots, reads bounds from `g_pParcelPane`, and insets the effect rectangle by tile margins.

Known derived filters include [UID:0000DE][SolidColorFilterEffecter](by-class/SolidColorFilterEffecter.md), [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md), [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md), and [UID:0000FZ][WaterFilterEffecter](by-class/WaterFilterEffecter.md).

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055ad00-0x0055adba` | `FilterEffecter` | Base constructor for full-screen filter pane geometry. |
| `0x0055ba22-0x0055ba29` | `ScalarDeletingDestructor` | Pane-interface thunk/destructor path; Wave3 attributes a short range. |

## Subclass Notes

- [UID:0000DE][SolidColorFilterEffecter](by-class/SolidColorFilterEffecter.md) fills a buffer with a 16-bit converted RGB color and uses the shared `dword_69B364` UI layer/context slot during pane setup; older generated data called this [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md).
- [UID:0000FZ][WaterFilterEffecter](by-class/WaterFilterEffecter.md) loads/advances a caustic palette frame and renders water filter frames.
- Cloud filter variants are currently constructor-only specializations that mainly install vtables.

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
- [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `68/76`. Summary: base role, constructor/destructor ranges, and subclass relationships are documented, but exact original file split and complete method inventory remain only medium-confidence. Evidence: documented ranges `0x0055ad00-0x0055adba` and `0x0055ba22-0x0055ba29`, plus cross-references to the screen-effecter runtime cluster and derived filter pages.
