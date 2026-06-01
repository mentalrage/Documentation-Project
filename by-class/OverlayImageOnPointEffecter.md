*** UID:00009Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OverlayImageOnPointEffecter

## Status

- Confidence: strong for role and ownership; medium for generated field layout names.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_OverlayImageOnPointEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`OverlayImageOnPointEffecter` is an [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md) subclass that draws an overlay image at a fixed pane point. It stores primary/secondary resource names, an overlay resource id, a render handle, and point coordinates.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055a7a0-0x0055a7c5` | `RenderOverlayImageAtPoint` | IDA confirms a compact virtual renderer that passes resource id, scratch state, point, flags, and text to the draw helper. |
| `0x0055a7d0-0x0055a8d9` | constructor | Builds `OverlayEffecter`, initializes render handle/resource id, copies names, loads the overlay resource, and stores point/lifetime state. |
| `0x0055a8e0-0x0055a986` | destructor | Releases the overlay resource and tears down visual/pane state. |
| `0x0055be10-0x0055bee2` | scalar deleting destructor | Calls the destructor and conditionally deletes storage. |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already documented responsibility, method boundaries, owner, and generated field-layout caveats.
- Changed to: `COMPLETION:72` and `CONFIDENCE:78`.
- Evidence: fixed-point overlay rendering, constructor, destructor, scalar deleting destructor, base relationship, and vtable family are documented; confidence remains medium-high because final generated field names and reconstructed C++ are incomplete.
