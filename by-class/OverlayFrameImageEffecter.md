*** UID:00009X | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OverlayFrameImageEffecter

## Status

- Confidence: strong for role and ownership.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_OverlayFrameImageEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`OverlayFrameImageEffecter` is the frame-indexed overlay subclass of [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md). It resolves a frame image by index, tracks palette/image names, and renders the selected frame through the shared overlay-frame renderer.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055a5e0-0x0055a61a` | `UpdateFrameAndRender` | IDA confirms a small virtual body that resolves a frame by index and renders it against the pane clip rect. |
| `0x0055a620-0x0055a6e9` | constructor | Builds `OverlayEffecter`, installs subclass vtables, initializes palette/image handles, and marks the pane visible. |
| `0x0055a6f0-0x0055a796` | destructor | Releases the frame image handle and tears down the overlay base. |
| `0x0055bc90-0x0055bd62` | scalar deleting destructor | Calls the destructor and conditionally deletes storage. |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Changes

- Before: completion/confidence metadata were `0/0` while the page already contained role, owner, method ranges, and overlay-base relationships.
- Changed to: `COMPLETION:72` and `CONFIDENCE:82`.
- Evidence: frame update/render, constructor, destructor, scalar deleting destructor, source-family, vtable family, and base class relationships are documented; completion remains below high because field names, callers, and reconstructed C++ are not fully covered.
