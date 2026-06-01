*** UID:0000JR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# GrafPort

## Status

- Confidence: strong for class responsibility, medium-strong for final folder.
- Proposed module: `render/GrafPort.cpp`.
- Current recovered source: `source-3/simroot_v2/class_GrafPort.cpp`
- Main address range: `0x004b8bf0-0x004bb8c4`

## File Role

`GrafPort` is the base drawing surface/port used by panes and render code. It owns region state, dirty/exposed region tracking, clip/default draw settings, and either a DirectDraw surface or an owned software buffer. The class is where UI layout bounds become an actual renderable backing store.

The active placement is `render/GrafPort.cpp` because `UpdateRenderRegion` creates RGB565 DirectDraw surfaces and manages pixel buffers, and `by-project-structure/proposed-source-tree.md` lists `GrafPort.cpp` in `render/`. The alternative `ui/core/GrafPort.cpp` remains a historical caveat because constructors across panes and UI controls inherit or embed this state heavily.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `GrafPort` | `0x004b8bf0-0x004bb8c4` | Base graphics port with region state and surface/buffer ownership. |
| [UID:00022M][0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter](by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md) | `0x004b8be0-0x004b8be8` | Adjacent tiny state setter that writes `1` to GrafPort byte field `this + 0x94`; final field name remains provisional. |
| [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md) | `0x0066da94` | External screen-width global read by `UpdateRenderRegion`; current generated `g_maxSurfacePitch` is a bad alias over this storage, not a separate GrafPort global. |
| DirectDraw surface descriptor helpers | local to `UpdateRenderRegion` | RGB565 `CreateSurface` setup and overlap preservation logic. |
| Draw-state accessors | `0x004b95e0-0x004b9767` | Cursor, font id, color, brush, and clip helpers currently emitted under caller-biased feature classes. |
| [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) | `0x004ba450-0x004ba53b` | Shared rectangle-frame helper that saves/restores GrafPort cursor state and draws four clipped line segments. |
| [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) | `0x004ba6b0-0x004ba81d` | Shared tiled-background helper that temporarily swaps GrafPort clip state and repeats a source tile through render callback slot `dword_69B3E8`. |
| Text measurement/drawing helpers | `0x004ba820-0x004bad66`, `0x004bb5e0-0x004bb7df` | Shared UTF-16 fit/suffix, width, line-height, run drawing, outline drawing, and per-glyph blit helpers currently emitted under caller-biased UI classes. |

## Behavior Summary

`UpdateRenderRegion` compares the requested rectangle with the current bounds, updates exposed/dirty regions, and then synchronizes backing storage. In the DirectDraw path it creates an offscreen surface with RGB565 masks (`0xf800`, `0x07e0`, `0x001f`) and copies the overlapping old surface contents into the new surface. In the software-buffer path it allocates a heap buffer with two bytes per pixel plus small row padding and preserves overlapping contents with `memmove`.

IDA MCP recheck on 2026-05-26 shows the generated `g_maxSurfacePitch` operand in this function is actually `word_66DA94` / [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md). The relevant DirectDraw packing branch compares `4 * requestedWidth` against the global screen width after checking for a large aligned pitch. Treat `g_maxSurfacePitch` as a Wave3 data issue, not a source-level symbol.

## Ownership Decision

Keep `GrafPort` close to DirectDraw/surface support, but do not merge it into `DirectX.cpp`. `DirectX` owns device lifetime; `GrafPort` owns per-pane/per-render-target storage and dirty-region state.

Also keep low-level RGB blend helpers in a separate helper module such as [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md). `GrafPort` establishes RGB565 backing storage; the blend helpers implement per-pixel and per-span math used by drawing routines.

Use [UID:0000OC][Surface](by-file/Surface.md) as the review bucket for nearby generic paint lifecycle, scroll-buffer, presentation, and callback helpers that Wave3 currently attaches to caller classes such as `FolderTreePane` and `MapPane`.

Keep [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md), [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md), and [UID:000164][0x004b96c0-0x004b9767.GrafPortClipRectHelper](by-memory/0x004b96c0-0x004b9767.GrafPortClipRectHelper.md) under GrafPort/draw-state review. Current generated owners include fitting-room, ranking, collection, target-option, and user-create classes, but the helper bodies are small GrafPort state accessors with broad paint-path fan-in.

Keep [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) in the same draw-state review family. Current generated ownership under `RankingEventListPane` is not supported by IDA caller breadth: the helper is called by ranking UI, progress bars, buttons/controls, dialog panes, field-map rendering, and other draw paths.

Keep [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) under GrafPort/surface review. It is emitted under `RankingEventListPane`, but IDA reports 26 direct callers and the body only manipulates GrafPort clip/visible state before dispatching repeated tile blits through [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md).

Keep [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) under GrafPort/surface review as well. It is currently emitted as `BowGaugeObjectPane::CompositePixels`, but IDA callers include both bow-gauge painting and [UID:0000ON][TextEditPane](by-file/TextEditPane.md) drawing/invalidation paths, and the body operates on GrafPort-like buffer, origin, stride, visible, clip, and palette fields.

Keep [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md), [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md), and [UID:00016I][0x004bb5e0-0x004bb7df.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7df.GrafPortDrawGlyph.md) under GrafPort/text-drawing review. Current generated owners include `ClanItemListPane`, `FittingRoomDownloadControlPane`, `CollectionEntryControlPane`, and `RankingEventListPane`, but the helpers have broad caller fan-in and operate on GrafPort draw state while delegating glyph metrics/decode to [UID:0000JH][FontImageLib](by-file/FontImageLib.md).

## Cross-References

- [UID:00005V][GrafPort](by-class/GrafPort.md)
- [UID:000160][0x004b8bf0-0x004bb8c4.GrafPort](by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md)
- [UID:00022M][0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter](by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md)
- [UID:0000IW][DirectX](by-file/DirectX.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md)
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)
- [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md)
- [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md)
- [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md)
- [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md)
- [UID:000164][0x004b96c0-0x004b9767.GrafPortClipRectHelper](by-memory/0x004b96c0-0x004b9767.GrafPortClipRectHelper.md)
- [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)
- [UID:00016I][0x004bb5e0-0x004bb7df.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7df.GrafPortDrawGlyph.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:80`.
  - Summary/evidence: render-port role, dirty region/surface/buffer behavior, DirectDraw/software paths, draw-state/text/tile helper ownership, and global operand correction are documented; confidence is capped by unresolved exact render/ui source split and several broad-fan-in helper ownership decisions.
- 2026-06-01: Changed proposed reconstruction path from blank to `NexusTK/render/`.
  - Before: The page named `render/GrafPort.cpp` as the strongest placement but left validator path metadata blank.
  - After: Validator metadata now stages `GrafPort.cpp` under `NexusTK/render/`.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `render/GrafPort.cpp`, and IDA MCP rechecks tie the low-level draw-state, clip, DirectDraw, and buffer helpers to render-port state rather than a feature UI module.
