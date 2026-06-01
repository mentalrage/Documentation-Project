*** UID:0000A0 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:72 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OverlayMovingImageEffecter

## Status

- Confidence: strong for role and ownership.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_OverlayMovingImageEffecter.cpp`
- Current memory range: [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Responsibility

`OverlayMovingImageEffecter` is a scrolling/repeating image overlay subclass of [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md). It stores image/palette names, movement ranges, direction mode, and saved clip/scroll state, then updates scroll offsets before drawing the overlay image.

## Method Notes

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055a990-0x0055aae2` | `UpdateAndRender` | IDA confirms the direction-mode switch that advances X/Y scroll and calls the overlay moving-image renderer. |
| `0x0055ab00-0x0055ac49` | constructor | Builds `OverlayEffecter`, installs subclass vtables, resolves/registers the moving image, and snapshots scroll/clip state. |
| `0x0055ac50-0x0055acf6` | destructor | Releases the moving image and tears down the overlay base. |
| `0x0055bef0-0x0055bfc2` | scalar deleting destructor | Calls the destructor and conditionally deletes storage. |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)

## Changes

- Before: completion/confidence metadata were `0/0` while the page already documented role, method ranges, ownership, and overlay-base relationships.
- Changed to: `COMPLETION:72` and `CONFIDENCE:82`.
- Evidence: update/render direction-mode behavior, constructor, destructor, scalar deleting destructor, source-family, and vtable family are documented; completion remains below high because exact fields, callers, and reconstructed C++ are not yet exhaustive.
