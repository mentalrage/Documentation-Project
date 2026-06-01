*** UID:0000OC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Surface

## Status

- Confidence: medium for `render/Surface.cpp` as a shared surface/presentation helper bucket; strong that this code should not be owned by DAT/image-library parsing.
- Proposed module: `render/Surface.cpp`
- Current recovered owners are scattered: `class_GrafPort.cpp`, `class_FolderTreePane.cpp`, `class_MapPane.cpp`, `class_RankingUserListPane.cpp`, `class_FittingRoomDownloadControlPane.cpp`, `class_EPFImageControlPane.cpp`, plus the alpha-surface files.
- Main evidence ranges: `0x004b9820-0x004ba81d`, `0x00557140-0x00559aef`, and the already split alpha-surface ranges around `0x00462170-0x004632b1`.

## File Role

`Surface.cpp` is a provisional source-structure anchor for generic drawing-surface helpers that do not yet have a clean recovered class owner. It sits between `GrafPort` and higher-level render callers:

- `GrafPort` owns the per-pane backing store, dirty/exposed regions, DirectDraw surface creation, and software-buffer fallback.
- `Surface.cpp` likely owns small paint lifecycle, surface metadata, blit/presentation, line/sprite/tile draw wrappers, and shared function-pointer/global state used across panes.
- `AlphaMaskSurface.cpp` and `IntAlphaSurface.cpp` own specialized alpha-mask and integer-alpha surface objects and should remain nearby, not inside asset libraries.

Current Wave3 ownership names are not reliable enough to be final source filenames for this cluster. Several helpers are attached to `FolderTreePane`, `MapPane`, `RankingUserListPane`, or `FittingRoomDownloadControlPane`, but IDA caller evidence shows broad drawing/surface use rather than feature-specific ownership.

## Proposed Contents

| Entity | Address | Current Wave3 owner | Role |
| --- | --- | --- | --- |
| [UID:00022M][0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter](by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md) | `0x004b8be0-0x004b8be8` | `FolderTreePane` pollution path | Tiny GrafPort/surface setup flag setter called by `BalloonObjectPane` after allocating a `GrafPort`; keep with GrafPort/surface review, not FolderTreePane. |
| `UpdateSurfaceInfo` | `0x004b9820-0x004b98b8` | `FolderTreePane` | Updates surface pitch/height metadata from cached fields or a DirectDraw surface descriptor; IDA reports 28 direct callers across pane/render code. |
| `EndPaint` | `0x004b98c0-0x004b98ee` | `FolderTreePane` | Unlocks a DirectDraw surface after drawing. |
| `LineTo` | `0x004b98f0-0x004b990c` | `RankingUserListPane` | Draws from current pen position through a global line-delta callback. |
| `DrawSprite` | `0x004b9910-0x004b997e` | `MapPane` | Applies zoom state and dispatches through a shared sprite-render callback. |
| `RenderTileFrame` | `0x004b9980-0x004b99b1` | `FittingRoomDownloadControlPane` | Resolves a palette by name and calls a tile-frame render function. |
| [UID:000166][0x004b99f0-0x004b9a62.ForwardToTileFrameBlitHelper](by-memory/0x004b99f0-0x004b9a62.ForwardToTileFrameBlitHelper.md) | `0x004b99f0-0x004b9a62` | none active | Shared draw wrapper that builds an offset rectangle and forwards through callback slot `dword_69B3E8`; direct call sites are `0x004b5917`, `0x005c3b60`, and `0x005c3db0`. |
| `ScrollPixelBuffer` | `0x004b9a70-0x004ba24a` | `FolderTreePane` | Scrolls/copies pixel rows and computes dirty regions. |
| [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md) | `0x004ba250-0x004ba444` | `MapPane` | Shared surface blit/composition helper that chooses DirectDraw blit or callback-based composition through `dword_69B3E8`; IDA reports eight direct callers across render/UI paths. |
| [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) | `0x004ba450-0x004ba53b` | `RankingEventListPane` | Shared rectangle-frame helper that clips through GrafPort state and draws four line segments through callback slot `dword_69B3E4`. |
| [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) | `0x004ba540-0x004ba6ad` | `BowGaugeObjectPane` | Shared 16-bit pixel compositor that fills zero pixels with a palette color and inverts nonzero pixels; IDA callers include BowGauge and TextEditPane drawing paths. |
| [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) | `0x004ba6b0-0x004ba81d` | `RankingEventListPane` | Shared tiled-background helper that temporarily applies a clip region and repeats a source tile through callback slot `dword_69B3E8`; IDA reports 26 direct callers. |
| `RenderPresentation` | `0x00557140-0x00557377` | `MapPane` | Presents rendered frames through region animation or direct blit. |
| [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md) | `0x005051c0-0x00505228` | `ParcelPane` in active generated output | Shared visible-tile redraw helper called by screen/presentation paths; current ParcelPane ownership is false. |
| `FlipSurfaces` | `0x00557470-0x0055769d` | `MapPane` | Sets DirectDraw cooperative/display state and locks the active render surface. |
| `DrawTileSurface` | `0x005583a0-0x0055867a` | `MapPane` | Drives frame rendering with shake/direct-blit presentation modes. |
| `RenderMinimap` | `0x00558840-0x00558f63` | `MapPane` | Creates minimap DirectDraw surfaces, selects color-depth render functions, and builds alpha lookup tables. |
| `BlitSurfaceToDisplay` | `0x005595d0-0x00559a0f` | `FolderTreePane` | Presents a DirectDraw source surface to the display, including fullscreen/windowed paths and RGB565-to-XRGB8888 conversion. |
| [UID:0000QW][g_pfnLockSurface](by-global/g_pfnLockSurface.md) | `0x0069b3fc` / `dword_69B3FC` | `EPFImageControlPane` reference owner | Generated alias for callback-table slot 7; IDA shows the EPF call as `dword_69B3FC(this, this + 0x44)`, so the current one-argument generated signature is suspect. |
| [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) | `0x0069b3e0-0x0069b410` | many generated aliases | Process-wide render callback table selected by the surface initializer at `0x00558840`; includes `dword_69B3E8`, `dword_69B3EC`, `dword_69B3FC`, and neighboring 555/565 dispatch slots. |
| [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md) | `0x004bb2e0-0x004bb5a5` | `RankingEventListPane` / recovered global | Shared line-segment clipping helper pair called only by the software line callbacks at `0x004bb9b0` and `0x004c0850`. |
| [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md) | `0x004bb8d0-0x004c069e` | `RankingEventListPane` for active emitted markers | Compatibility/RGB555-family callback targets assigned into the surface render callback table. |
| [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md) | `0x004c0770-0x004c5fde` | `RankingEventListPane` for active emitted markers | RGB565-family callback targets assigned into the surface render callback table. |
| [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) | `0x0066da94` | external Application/display config | External screen-width global used by `GrafPort::UpdateRenderRegion`; current generated `g_maxSurfacePitch` metadata is a stale alias over this storage. |

## Related Surface Files

| File | Role |
| --- | --- |
| [UID:0000IW][DirectX](by-file/DirectX.md) | Process-wide DirectDraw interface lifetime. |
| [UID:0000JR][GrafPort](by-file/GrafPort.md) | Per-pane backing storage, dirty/clip regions, DirectDraw/software surface allocation. |
| [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md) | User screenshot capture, BMP/PNG export, and screenshot proof submission over the active surface. |
| [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md) | Stateless RGB565/RGB555 blend math and pixel/span helpers. |
| [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md) | Byte alpha-mask surfaces and encoded frame mask blitters. |
| [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md) | Provisional integer/per-pixel alpha surface destructor and vtable anchor. |

## Ownership Decision

Use `render/Surface.cpp` as a migration review bucket, not as proof that all listed helpers were originally in one file. The common thread is source ownership: these are generic surface/presentation helpers and should not be migrated into chat, ranking, fitting-room, or DAT/resource files solely because Wave3 currently attaches them to those owners.

For now:

- Keep `GrafPort` as the owner of concrete backing-store allocation.
- Keep `ScreenPane` and `MapPane` as owners for high-level frame orchestration when behavior is map/screen-specific.
- Keep the helpers above under `Surface.cpp` review until IDA/class-layout work proves a better original class or file.

## Evidence Notes

- IDA MCP reports exact functions in the `0x004b9820-0x004ba24a` paint/helper range and the `0x00557140-0x00559aef` presentation range.
- IDA MCP reports `UpdateSurfaceInfo` has 28 direct callers, including balloon, GrafPort-region, text, pane, and UI paths; that breadth argues against a feature-specific owner.
- IDA MCP caller checks for `0x004ba540` report callers from BowGauge painting and TextEditPane draw/invalidation paths, so its current BowGauge owner should be treated as caller-biased.
- Wave3 summaries for `FlipSurfaces`, `DrawTileSurface`, `RenderMinimap`, and `BlitSurfaceToDisplay` all describe DirectDraw surface/presentation behavior, even though current owners are `MapPane` or `FolderTreePane`.
- 2026-05-25 IDA caller checks show `0x00559410` invokes [UID:0000MC][Pane](by-file/Pane.md) dirty/motion helpers at `0x005446e0` and `0x00544980`, which supports treating the `0x00559410` neighborhood as shared presentation traversal rather than as map gameplay code.
- `0x004b99f0` is a real 0x73-byte IDA function. A 2026-05-25 recheck shows it builds an offset rectangle and forwards through `dword_69B3E8`, with direct callers at `0x004b5917`, `0x005c3b60`, and `0x005c3db0`.
- `0x004ba250` is a real 0x1f4-byte IDA function. A 2026-05-25 recheck shows it calls `UpdateSurfaceInfo`, `EndPaint`, and callback slot `dword_69B3E8`, with eight direct callers. Current `MapPane::DrawSpriteAtPosition` ownership is callsite-biased.
- `0x004ba450` is a real 0xeb-byte IDA function. A 2026-05-25 recheck shows 47 direct callers and a GrafPort clip/cursor/line-delta body. Current `RankingEventListPane::DrawRectFrame` ownership is callsite-biased.
- `0x004ba6b0` is a real 0x16d-byte IDA function. A 2026-05-25 recheck shows 26 direct callers and a tiled-background body using temporary GrafPort clip state, palette lookup, and `dword_69B3E8`. Current `RankingEventListPane::DrawTiledBackground` ownership is callsite-biased.
- `g_pfnLockSurface` is a generated alias for `dword_69B3FC` at `0x0069b3fc`. A 2026-05-25 IDA MCP recheck of `0x00499310` shows `dword_69B3FC(this, this + 68)`, not the simplified one-argument call emitted by `simroot_v2`.
- `g_maxSurfacePitch` is not currently supported as a real global. A 2026-05-26 IDA MCP recheck of `GrafPort::UpdateRenderRegion` shows the generated reference is `word_66DA94` / [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md), a 16-bit screen-width global initialized to `1024`.
- `0x005051c0` is currently emitted as `ParcelPane::DrawParcelSlot`, but IDA shows it paints visible tiles from `this + 0x428` and callers are screen/presentation paths. Keep it in shared render review, not parcel notification source.
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) documents the `0x0069b3e0-0x0069b410` callback block. Current generated aliases include names such as `g_uiTileRenderer`, `g_pfnBlitTileFrame`, `g_pfnBlitSprite`, and `g_preparedCompositionRenderer_69B3E8`; those names are callsite-biased projections over shared callback storage.
- [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md) are currently emitted under `RankingEventListPane`, but IDA callers are limited to the software line callbacks in the two callback families. Keep the helper in shared render/geometry review.
- The callback target families at `0x004bb8d0-0x004c069e` and `0x004c0770-0x004c5fde` are currently emitted mostly under `RankingEventListPane`, but IDA xrefs show representative targets are assigned by the surface initializer at `0x00558840`. Treat these as shared render dispatch implementations, not ranking source.

## Cross-References

- [UID:000165][0x004b9820-0x004ba24a.SurfacePaintHelpers](by-memory/0x004b9820-0x004ba24a.SurfacePaintHelpers.md)
- [UID:00022M][0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter](by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md)
- [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md)
- [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md)
- [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md)
- [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md)
- [UID:000166][0x004b99f0-0x004b9a62.ForwardToTileFrameBlitHelper](by-memory/0x004b99f0-0x004b9a62.ForwardToTileFrameBlitHelper.md)
- [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md)
- [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md)
- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- [UID:0001G9][0x00557aa0-0x00558391.ScreenshotCaptureAndProof](by-memory/0x00557aa0-0x00558391.ScreenshotCaptureAndProof.md)
- [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md)
- [UID:00016H][0x004bb2e0-0x004bb5a5.LineClipHelpers](by-memory/0x004bb2e0-0x004bb5a5.LineClipHelpers.md)
- [UID:00016J][0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks](by-memory/0x004bb8d0-0x004c069e.SoftwareRenderCompatCallbacks.md)
- [UID:00016L][0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks](by-memory/0x004c0770-0x004c5fde.SoftwareRenderRgb565Callbacks.md)
- [UID:0000QW][g_pfnLockSurface](by-global/g_pfnLockSurface.md)
- [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md)
- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:0000IW][DirectX](by-file/DirectX.md)
- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000NB][ScreenPane](by-file/ScreenPane.md)
- [UID:0000J2][EPFImageControlPane](by-file/EPFImageControlPane.md)
- [UID:0000SV][g_uiTileRenderer](by-global/g_uiTileRenderer.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- 2026-05-28:
  - Before: the surface/presentation neighborhood was cited as `0x00557140-0x00559a0f`.
  - After: corrected it to `0x00557140-0x00559aef` and split out [UID:00023S][0x00559a10-0x00559aef.SurfaceDirectDrawCopyHelper](by-memory/0x00559a10-0x00559aef.SurfaceDirectDrawCopyHelper.md).
  - Evidence: IDA MCP disassembly shows `0x00559a0f` is one byte of alignment and `0x00559a10-0x00559aef` is a real DirectDraw/surface helper before the fixed wide-text formatter.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `88` and confidence to `76`.
  - Evidence: document has a broad helper inventory, current generated-owner pollution notes, related surface-file split, ownership decision, IDA caller/boundary evidence, callback/global references, range correction, and cross-references; confidence remains medium-high because `Surface.cpp` is still a provisional migration-review bucket rather than a proven original source unit.
- 2026-06-01: Changed proposed reconstruction path from blank to `NexusTK/render/`.
  - Before: The page proposed `render/Surface.cpp` but left validator path metadata blank.
  - After: Validator metadata now stages `Surface.cpp` under `NexusTK/render/`.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `render/Surface.cpp`, and IDA MCP rechecks for the `0x004b9820-0x004ba24a` helper cluster confirm shared surface/presentation behavior rather than feature-file ownership.
