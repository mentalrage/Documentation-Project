*** UID:00009W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:70 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# OverlayEffecter

## Status

- Confidence: strong for role and relationship to subclasses, medium for exact original file split.
- Proposed source: `render/Effects.cpp`
- Current recovered source: `source-3/simroot_v2/class_OverlayEffecter.cpp`
- Current memory ranges: `0x0055a2e0-0x0055a3c9`, `0x0055a560-0x0055a5d4`, `0x0055bbf0-0x0055bc8c`

## Responsibility

`OverlayEffecter` is the pane-backed base class for runtime image overlays. Its constructor builds a `Pane`, installs multiple vtable slots, reads parcel bounds, insets those bounds by tile margins, stores overlay coordinates, and attaches the pane to the render layer.

The subclasses specialize how the overlay image is resolved and updated:

- [UID:00009Y][OverlayImageEffecter](by-class/OverlayImageEffecter.md): static overlay image/name lookup.
- [UID:00009X][OverlayFrameImageEffecter](by-class/OverlayFrameImageEffecter.md): indexed frame overlay.
- [UID:00009Z][OverlayImageOnPointEffecter](by-class/OverlayImageOnPointEffecter.md): overlay image drawn at a fixed point.
- [UID:0000A0][OverlayMovingImageEffecter](by-class/OverlayMovingImageEffecter.md): scrolling/repeating overlay image.

## Methods

| Address | Method | Notes |
| --- | --- | --- |
| `0x0055a2e0-0x0055a3c9` | `OverlayEffecter` | Constructs pane-backed overlay bounds from `g_pParcelPane`, tile margins, and `g_pRenderLayer1`. |
| `0x0055a560-0x0055a5d4` | `~OverlayEffecter` | Cleans pane bounds and resets to `ScreenEffecter` base vtable. |
| `0x0055bbf0-0x0055bc8c` | `ScalarDeletingDestructor` | Calls destructor and optionally deletes. |

## Cross-References

- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0000C9][ScreenEffecter](by-class/ScreenEffecter.md)
- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md)
- [UID:00009Y][OverlayImageEffecter](by-class/OverlayImageEffecter.md)
- [UID:00009X][OverlayFrameImageEffecter](by-class/OverlayFrameImageEffecter.md)
- [UID:00009Z][OverlayImageOnPointEffecter](by-class/OverlayImageOnPointEffecter.md)
- [UID:0000A0][OverlayMovingImageEffecter](by-class/OverlayMovingImageEffecter.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0000OC][Surface](by-file/Surface.md)

## Changes

- Before: completion/confidence metadata were `0/0` even though the page already documented base-class responsibility, subclass relationships, method ranges, and render-layer construction behavior.
- Changed to: `COMPLETION:70` and `CONFIDENCE:76`.
- Evidence: constructor/destructor/deleting-destructor roles and the overlay subclass family are documented; completion stays moderate because exact field layout, detailed render-layer data flow, caller inventory, and original file split remain incomplete.
