*** UID:0000C9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# ScreenEffecter

## Status

- Confidence: strong for role, medium for final header split.
- Proposed source: `render/Effects.cpp`
- Proposed header: `render/Effects.h`
- Current recovered source: `source-3/simroot_v2/class_ScreenEffecter.cpp`
- Current memory ranges: `0x0055bfd0-0x0055bff3`, `0x0055c1d0-0x0055c1fe`
- Wave3 summary: base visual effect controller for screen-wide effects.

## Responsibility

`ScreenEffecter` is the base virtual interface for runtime screen effects. It provides scalar deleting cleanup and a completion predicate that checks three virtual effect-state slots.

The class is the common root for pixel, overlay, and filter effecters documented in [UID:0000IZ][Effects](by-file/Effects.md). Several subclasses only install a vtable and store effect parameters, which supports treating them as one source-module family rather than independent original files.

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055bfd0-0x0055bff3` | `ScalarDeletingDestructor` | Resets base vtable and optionally deletes `this`. |
| `0x0055c1d0-0x0055c1fe` | `AreAllEffectsComplete` | Calls three virtual state checks and returns true only when all are inactive. |

## Derived Runtime Families

- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md): base for map/pixel effects such as [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md), [UID:0000GC][XWaveEffecter](by-class/XWaveEffecter.md), [UID:0000GD][YFlipEffecter](by-class/YFlipEffecter.md), and [UID:000070][LakeEffecter](by-class/LakeEffecter.md).
- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md): base for pane-backed overlay images and moving/frame overlay effects.
- [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md): base for full-screen filters such as color, cloud, static cloud, and water filters.

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md)
- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md)
- [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `72/76`.
  - Before: The page was unevaluated despite documenting the base effecter responsibility, two method bodies, and derived runtime families.
  - After: Scored as moderate-high completion and confidence because the base role is clear but final header split and deeper virtual-state semantics remain open.
  - Evidence: Existing responsibility notes, method table, derived-family map, vtable family reference, runtime-cluster reference, and global list cross-reference support the score.
