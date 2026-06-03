*** UID:00009W | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000IZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
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
- Autogen parent: [UID:0000IZ][Effects](by-file/Effects.md). C++ is intentionally blank because class fields, source-level method names, and the exact final file/header split are not final-source quality.

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

## Evidence Notes

- [UID:0000IZ][Effects](by-file/Effects.md) is scored `88/80`, assigned to `NexusTK/render/`, and groups the runtime effecter hierarchy under `render/Effects.cpp`.
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md) is scored `78/82`, reconstructable, and attached to [UID:0000IZ][Effects](by-file/Effects.md); it records IDA-backed overlay constructor/deconstructor boundaries, vtable-store evidence, representative decompilation for `0x0055a2e0`, and the stale `g_pScreenEffecterList` alias caveat.
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) anchors the four OverlayEffecter vtable views at object offsets `+0x00`, `+0x04`, `+0xa4`, and `+0xa8`.
- The subclass pages and the runtime cluster agree that `OverlayEffecter` is the shared pane-backed base for the static-image, frame-image, point-image, and moving-image overlay specializations.

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
- 2026-06-03 parent attachment pass:
  - What existed before: the page had strong role/subclass evidence but remained unattached and below the parent-attachment confidence gate.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:82`, `RECONSTRUCTABLE:TRUE`, and parent [UID:0000IZ][Effects](by-file/Effects.md).
  - Summary/evidence: the Effects file doc, runtime effecter aggregate, vtable-family doc, and subclass pages all support `render/Effects.cpp` ownership. C++ remains blank because exact fields, final source split, and final method names remain below the 95+ reconstruction gate.
