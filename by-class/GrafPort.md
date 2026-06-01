*** UID:00005V | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000JR | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# GrafPort

## Status

- Confidence: strong for imported methods and state responsibilities.
- Likely source file: [UID:0000JR][GrafPort](by-file/GrafPort.md)
- Address range: [UID:000160][0x004b8bf0-0x004bb8c4.GrafPort](by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md)
- Current recovered file: `source-3/simroot_v2/class_GrafPort.cpp`

## Class Purpose

`GrafPort` is the core graphics-port base class. It gives panes and render objects a clipped region, dirty/exposed region state, default draw attributes, and backing storage. The backing storage can be a DirectDraw surface or an owned software buffer.

## Observed State

The generated source exposes a packed state block inside `m_stateBuffer`. Important fields include:

```text
0x00  cached handle/state token
0x08  bounds / clip rectangle
0x18  dirty Region subobject
0x30  anchor point
0x38  scale, alpha, color, enabled/default state
0x58  ownsSoftwareBuffer flag
0x5c  software buffer pointer
0x60  software stride
```

The outer object also owns an exposed `Region`, primary surface handle, lock-state fields, draw cursor/color/font fields, and view-origin/bounds helpers.

[UID:00022M][0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter](by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md) is a tiny adjacent setter that writes `1` to byte field `this + 0x94`. The final field name remains provisional, but the only current IDA xref is a `BalloonObjectPane` constructor path that allocates a `GrafPort` and immediately marks this flag before drawing.

[UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md) is a draw-state accessor cluster for cursor movement, font id, and color fields. Current generated ownership spreads these accessors across fitting-room, ranking, collection, and target-option classes, but IDA caller counts show broad UI/render use.

[UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md) is a nearby draw-state helper pair under review for this class or a closely related drawing context. The helpers read/write `this + 0x84`; current generated ownership under `UserHairColorSelectListPane` is not supported by the broader caller set.

[UID:000164][0x004b96c0-0x004b9767.GrafPortClipRectHelper](by-memory/0x004b96c0-0x004b9767.GrafPortClipRectHelper.md) computes the current clipped draw rectangle using Region helpers. Current generated ownership under `RankingEventListPane` is caller-biased.

[UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md) draws a clipped rectangle frame by saving/restoring GrafPort cursor fields and dispatching four line-delta callback calls. Current generated ownership under `RankingEventListPane` is caller-biased; IDA reports 47 direct callers across UI and render paths.

[UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md) is another nearby GrafPort/surface helper under review. Current generated ownership calls it `BowGaugeObjectPane::CompositePixels`, but IDA caller checks show TextEditPane draw and invalidation paths also call it.

[UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md) draws repeated tiled backgrounds by temporarily replacing GrafPort clip state, calculating row/column counts from visible bounds, and blitting through `dword_69B3E8`. Current generated ownership under `RankingEventListPane` is caller-biased.

[UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md) and [UID:00016I][0x004bb5e0-0x004bb7df.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7df.GrafPortDrawGlyph.md) are shared GrafPort text helpers under review. Current generated ownership spreads them across FittingRoom, Collection, and Ranking classes, but the bodies read GrafPort draw-state fields and call [UID:0000JH][FontImageLib](by-file/FontImageLib.md).

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `GrafPort::GrafPort` | `0x004b8bf0-0x004b8d17` | Initializes base state, regions, defaults, and null backing storage. |
| `UpdateRenderRegion` | `0x004b8e20-0x004b94e1` | Updates bounds/dirty state and creates or resizes DirectDraw/software backing storage. |
| `ScalarDeletingDestructor` | `0x004bb7e0-0x004bb8c4` | Releases software buffer and DirectDraw surface, destroys embedded regions, and conditionally deletes. |

## Evidence Notes

- Wave3 imports the class with three included methods and high grades.
- IDA MCP reports six constructor callers, with call sites in pane/render object constructors.
- IDA MCP reports fifteen direct callers of `UpdateRenderRegion`, spanning pane, screen, map, and render update code.
- `UpdateRenderRegion` reads `g_pDirectX` and calls the DirectDraw `CreateSurface` slot in the hardware-surface path.
- A 2026-05-26 IDA MCP recheck resolves the generated `g_maxSurfacePitch` reference in `UpdateRenderRegion` to `word_66DA94` / [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md), not to a separate GrafPort-owned pitch global.

## Cross-References

- [UID:0000JR][GrafPort](by-file/GrafPort.md)
- [UID:000160][0x004b8bf0-0x004bb8c4.GrafPort](by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md)
- [UID:00022M][0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter](by-memory/0x004b8be0-0x004b8be8.GrafPortDirtyFlagSetter.md)
- [UID:000162][0x004b95e0-0x004b969f.GrafPortDrawStateAccessors](by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md)
- [UID:000168][0x004ba450-0x004ba53b.GrafPortDrawRectFrame](by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md)
- [UID:000169][0x004ba540-0x004ba6ad.CompositePixels16](by-memory/0x004ba540-0x004ba6ad.CompositePixels16.md)
- [UID:00016A][0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground](by-memory/0x004ba6b0-0x004ba81d.GrafPortDrawTiledBackground.md)
- [UID:000163][0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers](by-memory/0x004b96a0-0x004b96bf.DrawContextBrushHandleHelpers.md)
- [UID:000164][0x004b96c0-0x004b9767.GrafPortClipRectHelper](by-memory/0x004b96c0-0x004b9767.GrafPortClipRectHelper.md)
- [UID:00016C][0x004ba9a0-0x004bad66.GrafPortTextRunHelpers](by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md)
- [UID:00016I][0x004bb5e0-0x004bb7df.GrafPortDrawGlyph](by-memory/0x004bb5e0-0x004bb7df.GrafPortDrawGlyph.md)
- [UID:00003Y][DirectX](by-class/DirectX.md)
- [UID:0000NT][SoftwareBlend16](by-file/SoftwareBlend16.md)
- [UID:0000SU][g_screenWidth](by-global/g_screenWidth.md)

## Changes

- Completion/confidence score update: existed before as `0/0`; changed to `84/86`. Summary: core graphics-port role, state block, backing storage, dirty/clip/draw helpers, text/glyph helper boundaries, constructor/update/destructor, caller counts, DirectDraw path, and global-name correction are documented in depth; remaining work is exact private field naming and final ownership for a few adjacent helper clusters. Evidence: `0x004b8bf0-0x004bb8c4` memory page, helper memory pages, `FontImageLib` text helper references, DirectX path notes, and `g_screenWidth` correction.
- 2026-06-01: Marked reconstructable and attached to [UID:0000JR][GrafPort](by-file/GrafPort.md).
  - Before: The page described a source-owned graphics-port class but left autogen metadata blank.
  - After: `RECONSTRUCTABLE:TRUE` and parent `0000JR`.
  - Evidence: IDA MCP rechecks on the draw-state and clip helper ranges confirm broad render/UI use through the GrafPort state block, while the proposed source tree places the owner in `render/GrafPort.cpp`.
