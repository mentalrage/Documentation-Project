*** UID:0000TN | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SurfaceRenderCallbackTable

## Status

- Symbol kind: process-wide render callback table / global function-pointer block.
- Storage range: [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md)
- Likely source module: [UID:0000OC][Surface](by-file/Surface.md), with close ties to [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md).
- Current generated aliases include `dword_69B3E8`, `dword_69B3EC`, `dword_69B3FC`, `g_pfnBlitTileFrame`, `g_pfnBlitSprite`, `g_pfnBlitText`, `g_pfnLockSurface`, `g_preparedCompositionRenderer_69B3E8`, `g_targetCompositionRenderer_69B3EC`, and `g_uiTileRenderer`.
- Confidence: strong for shared callback-table storage and initialization, medium for final slot names.

## Role

`SurfaceRenderCallbackTable` is a provisional documentation name for the global software-render dispatch table installed by the surface initialization path at `0x00558840`. It selects one of two render-helper families based on the active DirectDraw surface description and color masks.

This table is render infrastructure. Callers across panes, EPF/image libraries, composition libraries, map drawing, and UI controls dispatch through these slots. The breadth of the caller set means generated callsite names should not be accepted as source ownership names.

## Callback Slots

IDA MCP decompilation of `0x00558840` shows the following assignments:

| Slot | Storage | Non-RGB565/compat target | RGB565-capable target | Current role evidence |
| --- | --- | --- | --- | --- |
| 0 | `0x0069b3e0` / `dword_69B3E0` | `0x004bb8d0` | `0x004c0770` | Low-level draw helper; exact signature open. |
| 1 | `0x0069b3e4` / `dword_69B3E4` | `0x004bb9b0` | `0x004c0850` | Low-level draw helper; exact signature open. |
| 2 | `0x0069b3e8` / `dword_69B3E8` | `0x004bc090` | `0x004c0f80` | Primary EPF/tile/frame blit callback used by `BlueAlertPane`, `MapTileImageLib`, `RenderTileFrame`, and image composition paths. |
| 3 | `0x0069b3ec` / `dword_69B3EC` | `0x004bd420` | `0x004c3190` | Alternate render callback used by target-composition and alternate content paths. |
| 4 | `0x0069b3f0` / `dword_69B3F0` | `0x004bdcc0` | `0x004c3a50` | Sprite/composition render callback used by human/monster image-library paths. |
| 5 | `0x0069b3f4` / `dword_69B3F4` | `0x004bdf40` | `0x004c3cf0` | Alpha/color-LUT style blit callback in the same render family. |
| 6 | `0x0069b3f8` / `dword_69B3F8` | `0x004be0e0` | `0x004c3ea0` | Related render callback; exact public role open. |
| 7 | `0x0069b3fc` / `dword_69B3FC` | `0x004be680` | `0x004c4380` | Broad invalidation/fill/presentation callback used by map-tile fallback, many pane paint paths, and the generated `g_pfnLockSurface` alias. |
| 8 | `0x0069b400` / `dword_69B400` | `0x004bed80` | `0x004c46d0` | Surface helper callback; exact role open. |
| 9 | `0x0069b404` / `dword_69B404` | `0x004bedb0` | `0x004c4700` | Surface helper callback; exact role open. |
| 10 | `0x0069b408` / `dword_69B408` | `0x004bede0` | `0x004c4730` | Surface helper callback; exact role open. |
| 11 | `0x0069b40c` / `dword_69B40C` | `0x004bee40` | `0x004c4790` | Block/surface transfer callback used by `DrawTileSurface`-style paths. |

The "RGB565-capable" path is selected when the surface description reports 32-bit mode or a 16-bit green mask of `0x07e0`. The other path is likely the retained RGB555/compatibility family, but the final product-level old/new rendering split still needs a broader pass.

## Evidence

- IDA MCP `xrefs_to` on 2026-05-24 showed `dword_69B3E8` has 114 direct xrefs, `dword_69B3EC` has 11, and `dword_69B3FC` has 206.
- IDA MCP decompilation of `0x00558840` shows the complete callback-table assignment block, plus construction of two alpha/scale lookup tables at nearby globals `dword_69B3D8` and `dword_69B3DC`.
- `FittingRoomDownloadControlPane::RenderTileFrame` at `0x004b9980` is only a small wrapper: it resolves a palette, then calls `dword_69B3E8`.
- [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md) border drawing at `0x00500e20` repeatedly resolves `BDFRAME.EPF` frames and calls `dword_69B3E8`.
- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md) `DrawTile` uses `dword_69B3FC` for fallback fill/invalidation and `dword_69B3E8` for actual tile drawing.
- [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md) `LoadAndRenderImage` calls `dword_69B3FC(this, this + 0x44)` before frame loading; current generated output labels this as `g_pfnLockSurface(drawSurface)`.
- [UID:000166][0x004b99f0-0x004b9a62.ForwardToTileFrameBlitHelper](by-memory/0x004b99f0-0x004b9a62.ForwardToTileFrameBlitHelper.md) builds an offset rectangle and forwards through `dword_69B3E8`.
- [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) uses `dword_69B3E8` in its software/composition path after updating both surface metadata blocks.
- [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) dispatches each clipped rectangle edge through `dword_69B3E4`.
- [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) repeatedly blits a tile through `dword_69B3E8` after installing a temporary GrafPort clip region.
- `NewHumanImageLib` generated source aliases the same storage as `g_preparedCompositionRenderer_69B3E8` and `g_targetCompositionRenderer_69B3EC`, showing why callsite-specific names are not stable.

## Ownership Decision

Keep this table with [UID:0000OC][Surface](by-file/Surface.md) or a neighboring `render/SurfaceBlitters.cpp` / `render/SoftwareRenderDispatch.cpp` source candidate. Do not move it into `AlertPanes`, fitting-room controls, map tiles, or a specific image library based only on a generated alias.

`SoftwareBlend16` owns reusable pixel/span math. This callback table owns runtime selection and dispatch to the larger 555/565 blit families that consume that math.

## Open Questions

- Final source names for each callback slot.
- Whether the original code exposed this as a struct/table, named globals, or a static dispatch object.
- How the RGB555/compatibility path maps to the client old-rendering-mode option.
- Whether the orphan writes around `0x0055874a` / `0x00558753` are real code in an unmodeled function gap or stale analysis artifacts.

## Cross-References

- [UID:0001PI][0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable](by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md)
- [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md)
- [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md)
- [UID:0000QW][g_pfnLockSurface](by-global/g_pfnLockSurface.md)
- [UID:000166][0x004b99f0-0x004b9a62.ForwardToTileFrameBlitHelper](by-memory/0x004b99f0-0x004b9a62.ForwardToTileFrameBlitHelper.md)
- [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md)
- [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md)
- [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md)
- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:00000Y][BlueAlertPane](by-class/BlueAlertPane.md)
- [UID:0000SV][g_uiTileRenderer](by-global/g_uiTileRenderer.md)
- [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/82`. Summary/evidence: the page documents the storage range, callback slots, initializer behavior, broad caller evidence, render ownership, generated-alias warnings, and open questions; exact slot names and old/new render-mode mapping remain unresolved.
