*** UID:00008E | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MiniMapImageControlPane

## Status

- Confidence: strong for class behavior and method starts; medium for final source split.
- Likely source file: [UID:0000LE][MiniMap](by-file/MiniMap.md), probably beside [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md).
- Current recovered file: `source-3/simroot_v2/class_MiniMapImageControlPane.cpp`
- Main memory doc: [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)

## Class Purpose

`MiniMapImageControlPane` is the image pane used by `MiniMapDialog` when rendering the main minimap image surface. It is a small `ControlPane`-derived widget with an image handle and paint path for the loaded minimap image.

## Methods

| Address | Method | Role |
| --- | --- | --- |
| `0x00453df0-0x00453e87` | constructor | Builds the control, initializes image state, and stores the image handle. |
| `0x00453eb0-0x00453ecf` | `OnPaint` | Paints/blits the minimap image through the current render callback path. |
| `0x00453ed0-0x00453ee6` | adjustor thunks | Compiler-generated destructor adjustors currently disabled in active output. |
| `0x00453ef0-0x00453f45` | scalar deleting destructor | Runs shared pane cleanup and optional delete. |

## Boundary Caveats

- The generated source references fitting-room image-control helper labels for initialization. Treat those labels as shared control/image helper pollution, not evidence that this minimap control belongs to cash-shop or fitting-room source.
- Keep the class with minimap UI unless later caller evidence proves it is a generic reusable image control. Current IDA caller evidence ties construction to [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md) at `0x004523d0`.

## Cross-References

- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md)
- [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md)

## Changes

- 2026-05-30: Grading changed from `0/0` to `82/86`.
  - Before: page documented the class purpose, method ranges, and minimap caller ownership but was still unevaluated.
  - After: score reflects the small, well-bounded image-control class, including constructor, paint path, destructor glue, and fitting-room helper pollution caveat.
  - Evidence: linked memory page [UID:0000XO][0x00453df0-0x004563b5.MiniMapRendererAndControls](by-memory/0x00453df0-0x004563b5.MiniMapRendererAndControls.md) records IDA-confirmed method starts and construction from [UID:00008C][MiniMapDialog](by-class/MiniMapDialog.md).
