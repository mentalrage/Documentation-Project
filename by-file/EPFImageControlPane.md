*** UID:0000J2 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# EPFImageControlPane

## Status

- Confidence: strong for class behavior, medium for exact original filename.
- Proposed module: `ui/controls/EPFImageControlPane.cpp`
- Current recovered source: `source-3/simroot_v2/class_EPFImageControlPane.cpp`
- Main address range: `0x004991f0-0x0049b24f`

## File Role

`EPFImageControlPane` is a UI control for displaying a single EPF/EPD frame with a palette. It should live with UI controls, not with the EPF registry itself.

The likely original file contained:

- `EPFImageControlPane`
- references to `g_pEPFLib`
- references to `g_pPaletteLib`
- draw-surface/blit function pointer declarations used by the control

The class consumes the [UID:0000K2][ImageLib](by-file/ImageLib.md) / [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md) singleton through `g_pEPFLib`, then uses palette and blit services to draw the decoded frame into the pane surface. The generated `g_pfnLockSurface` callback name is now tracked as [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) slot `dword_69B3FC` rather than owned by this control.

## Behavior

- Constructor chains to `ControlPane`, stores a 16-wchar EPF file name, stores the frame index, applies a flip flag, and defaults the palette name to `BARAM.PAL` when no palette is supplied.
- Destructor releases the cached image and chains to the parent pane destructor.
- `LoadAndRenderImage` prepares the pane draw surface through `dword_69B3FC`, asks `g_pEPFLib` for the selected frame, fetches a palette from `g_pPaletteLib`, blits the image when pixel data is present, and encodes the rendered result into the control's cache. IDA shows the prepare call as `dword_69B3FC(this, this + 0x44)`, while active `simroot_v2` simplifies it to `g_pfnLockSurface(drawSurface)`.

## Ownership Decision

Keep this as a consumer in `ui/controls/EPFImageControlPane.cpp`. It is useful evidence for the registry API, but it should not own `ResourceLayoutTable`, `ResourceLayoutEntry`, palette classes, or generic blit helpers.

## Cross-References

- [UID:00004G][EPFImageControlPane](by-class/EPFImageControlPane.md)
- [UID:00011J][0x004991f0-0x0049b24f.EPFImageControlPane](by-memory/0x004991f0-0x0049b24f.EPFImageControlPane.md)
- [UID:0000K2][ImageLib](by-file/ImageLib.md)
- [UID:0000N5][ResourceLayoutTable](by-file/ResourceLayoutTable.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000QW][g_pfnLockSurface](by-global/g_pfnLockSurface.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:78` and `CONFIDENCE:78`.
  - Summary/evidence: UI control role, constructor/load-render behavior, `g_pEPFLib`/palette/surface callback dependencies, and non-ownership decisions are documented; completion is lower than larger pages because detailed vtable/layout and caller coverage are still sparse.
