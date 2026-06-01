*** UID:0000HF | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# AlphaMaskSurface And Mask Blitters

## Status

- Confidence: strong for imported `AlphaMaskSurface` methods, `DrawFrameWithBlendMode`, adjacent alpha view/helper boundaries, and shared layout; medium-high for raw default-constructor callability and final `IntAlphaSurface` source split.
- Proposed module: `NexusTK/render/AlphaMaskSurface.cpp`, with the broader `Surface.cpp` and provisional `IntAlphaSurface.cpp` split kept visible until constructor/source ownership is fully resolved.
- Current recovered sources: `source-3/simroot_v2/class_AlphaMaskSurface.cpp`, `recovered/DrawFrameWithBlendMode_00462E10.cpp`, and related provisional `class_IntAlphaSurface.cpp`
- Main address ranges: [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md), [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md), [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md), and related [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md).

## File Role

This cluster owns byte alpha-mask surfaces and helper blitters used by light rendering, overlay shading, and sprite-frame masking. `AlphaMaskSurface` allocates a byte buffer, exposes clipped buffer views, fills rectangles, and rasterizes circular/elliptical gradients. `DrawFrameWithBlendMode` copies/adds/subtracts byte mask frames into an `AlphaMaskSurface`.

The observed object and view layouts are now tracked separately as [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md) and [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md). The current vtable anchor is [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md); the final class split remains provisional because IDA shows the same vtable written by the `AlphaMaskSurface` constructor/helper region.

The raw `0x00462120-0x00462161` body initializes an empty owning surface with the same vtable/layout as the confirmed width/height constructor, but IDA does not currently model it as a function and no xrefs target its start. Keep it as default-constructor-shaped evidence, not a clean source-map boundary.

The `0x00462230-0x00462258` body is now documented as an [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md). It restores `off_6112EC` and releases owned pixels, but its only observed caller is a C++ EH funclet at `0x005fa593`; do not migrate it as a handwritten source method.

The adjacent `0x00462320` and `0x004623c0` helpers are real IDA functions that build non-owning clipped/full buffer views over the same `{pixels,width,height,stride,ownsBuffer}` layout. `0x00462320` has a live caller in `StaticObjImageLib`; `0x004623c0` has no direct code callers in the current IDA database but writes the `IntAlphaSurface` vtable and belongs with the same surface-view family.

The adjacent `0x00462f20` helper is not currently imported as a Wave3 file, but IDA shows it rasterizes encoded frame rows into an alpha surface with replace/add/subtract modes and a vertical alpha ramp. IDA MCP reports nine code xrefs. Six modeled callers are established image-library render methods: `MonsterImageLib::RenderMonsterImage`, `StaticObjImageLib::RenderStaticObject`, `EffectObjImageLib::RenderEffectFrame`, `ItemObjImageLib::DrawItemImage`, `ItemObjImageLib::DrawItemImageIn43x43Slot`, and `NewHumanImageLib::RenderPreparedComposition`. The three remaining raw call sites at `0x004d5ea6`, `0x004d6b16`, and `0x004dcca5` still look like image-library overlay paths but need function-boundary recovery.

2026-05-30 IDA MCP recheck preserves the same nine xrefs and confirms `DrawEncodedAlphaFrame` reads encoded row data from the source payload, computes a vertical alpha ramp from the caller's row/alpha endpoints, and writes through the `AlphaMaskSurface` pixel/stride fields. This strengthens the shared render-helper placement while keeping the frame-source type provisional.

2026-05-31 IDA MCP placement recheck reconfirmed the key boundaries used for the source-file decision: `0x00462120` is still raw constructor-shaped code with no IDA function object, `sub_462170` is `0x00462170-0x00462227`, `sub_462320` is `0x00462320-0x004623b5`, `sub_4623C0` is `0x004623c0-0x00462514`, `sub_462E10` is `0x00462e10-0x00462f1e`, `sub_462F20` is `0x00462f20-0x00463252`, and `sub_463270` is `0x00463270-0x004632b1`. `xrefs_to 0x00462f20` still reports nine code xrefs, `xrefs_to 0x00462e10` reports the two LightObjImageLib-style callers, and `xrefs_to 0x006112ec` ties the `IntAlphaSurface` vtable writes back to the adjacent alpha-surface constructor/helper/destructor region. `xrefs_to 0x004632c0` remains vtable-only through `0x00612574`, preserving the exclusion of the following application error-state cleanup.

`IntAlphaSurface` currently has only a scalar deleting destructor recovered at `0x00463270`, plus vtable evidence for the buffer-release slot at `0x00462260`. It now has its own provisional by-file anchor, but keep it near this module until its constructor and full owner family are identified. IDA vtable refs tie `off_6112EC` back into the adjacent `AlphaMaskSurface` constructor/helper region.

## Proposed Contents

| Entity | Address | Role |
| --- | --- | --- |
| `AlphaMaskSurface` raw/default constructor | `0x00462120-0x00462161` | Raw constructor-shaped empty-surface initializer; IDA has no function object or xrefs at the start. |
| `AlphaMaskSurface` | `0x00462170-0x00462e03` | Temporary byte mask buffer, clipped view, rect fill, radial/elliptic alpha gradients. |
| `AlphaMaskSurfaceLayout` | object offsets `0x00-0x24` | Shared alpha-surface object layout: vtable, bounds, pixels, width, height, stride, ownership flag. |
| `AlphaSurfaceBufferView` | 0x14-byte POD record | Clipped/non-owning buffer view returned by `GetBufferInfo` and `BuildClippedAlphaSurfaceView`. |
| `IntAlphaSurface` unwind cleanup | [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md) | Compiler-generated EH cleanup target; restores the vtable and frees owned pixels during partial construction/unwind. |
| `IntAlphaSurface::ReleaseOwnedPixels` provisional | [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md) | Vtable slot helper that frees owned pixel storage and clears the pointer. |
| `BuildClippedAlphaSurfaceView` provisional | [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md) | Builds a non-owning clipped pixel-buffer view for render/image-library callers. |
| `InitAlphaSurfaceView` provisional | [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md) | Initializes a full or clipped `IntAlphaSurface`-style view object and assigns `off_6112EC`. |
| `DrawFrameWithBlendMode` | `0x00462e10-0x00462f1e` | Blits byte frame surfaces into an alpha-mask target using replace/add/subtract modes. |
| `DrawEncodedAlphaFrame` provisional | `0x00462f20-0x00463252` | Decodes signed run rows from a frame/source object and applies a vertical alpha ramp to a mask. |
| `IntAlphaSurface` provisional | `0x00463270-0x004632b1` | Integer/per-pixel alpha surface destructor and vtable evidence; exact class boundary still open. |

## Ownership Decision

Keep this code under render surface/blitter support. `LightObjImageLib` and other asset libraries consume these helpers, but the surface buffers and blend loops are shared infrastructure. Do not fold them into `LightObjImageLib` just because the light constructor is a prominent caller.

Do not keep `0x004632c0` in this alpha-surface family. A 2026-05-25 IDA MCP recheck ties it to vtable `0x00612574`, static initializer `0x00419e80`, atexit cleanup `0x0060c0b0`, and application error-state globals around `0x0067a998-0x0067a9a0`.

For the broader generic surface helper bucket, see [UID:0000OC][Surface](by-file/Surface.md). This file remains the specialized byte-mask/alpha-frame side of the same render layer.

## Cross-References

- [UID:00000C][AlphaMaskSurface](by-class/AlphaMaskSurface.md)
- [UID:0000K8][IntAlphaSurface](by-file/IntAlphaSurface.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:00006K][IntAlphaSurface](by-class/IntAlphaSurface.md)
- [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md)
- [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md)
- [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md)
- [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md)
- [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md)
- [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md)
- [UID:0000YN][0x00462e10-0x00462f1e.DrawFrameWithBlendMode](by-memory/0x00462e10-0x00462f1e.DrawFrameWithBlendMode.md)
- [UID:0000YO][0x00462f20-0x00463252.DrawEncodedAlphaFrame](by-memory/0x00462f20-0x00463252.DrawEncodedAlphaFrame.md)
- [UID:0000YP][0x00463270-0x004632b1.IntAlphaSurface](by-memory/0x00463270-0x004632b1.IntAlphaSurface.md)
- [UID:0000YQ][0x004632c0-0x0046330b.ApplicationErrorStateCleanup](by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md)
- [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md)
- [UID:0000UH][DrawEncodedAlphaFrame_00462F20](by-item/DrawEncodedAlphaFrame_00462F20.md)
- [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md)
- [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md)
- [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md)
- [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md)
- [UID:0000KP][LightObjImageLib](by-file/LightObjImageLib.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- What existed before: the page documented the alpha-mask surface/blitter cluster, helper boundaries, and split caveats but had unevaluated scores.
- What it was changed to: scores were set to `72/82`.
- Summary and evidence: imported methods, buffer-view helpers, and image-library call sites make the module role strong; completion/confidence stay below higher levels because the raw default constructor and `IntAlphaSurface` split remain provisional.
- 2026-05-30: Raised completion/confidence from `72/82` to `76/86` and replaced stale range-end text with canonical by-memory UID links. Added current evidence from the raw default-constructor and clipped-view verification; source split versus `IntAlphaSurface` and encoded-alpha helper ownership remains provisional.
- 2026-05-30: Raised completion/confidence from `76/86` to `80/88` after current IDA MCP verification of `DrawEncodedAlphaFrame` behavior and caller set. The file/module split remains below high completion because the frame-source type, three raw image-library xrefs, and `IntAlphaSurface` relationship are still open.
- 2026-05-31: Filled validator projected path and refreshed placement evidence.
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, and the status line kept `render/AlphaMaskSurface.cpp` as one of several possible placements.
  - Changed to: projected path `NexusTK/render/`, proposed module `NexusTK/render/AlphaMaskSurface.cpp`, and scores `82/89`.
  - Summary/evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already lists `render/AlphaMaskSurface.cpp`, and the 2026-05-31 IDA MCP recheck reconfirmed the alpha-surface function boundaries, caller set, vtable-write neighborhood, and `0x004632c0` exclusion. The score increase is intentionally small because the raw default constructor, frame-source type, and final `IntAlphaSurface` split remain open.
- 2026-05-31: Promoted `InitAlphaSurfaceView` from by-item-only tracking to exact by-memory tracking.
  - What existed before: the file page linked [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md) as the only durable page for the `0x004623c0` helper.
  - Changed to: the contents table and cross-references now point to [UID:0002NM][0x004623c0-0x00462514.InitAlphaSurfaceView](by-memory/0x004623c0-0x00462514.InitAlphaSurfaceView.md), with the old item retained as an index.
  - Summary/evidence: IDA MCP confirms `0x004623c0-0x00462514` as an exact modeled function; `by-memory` is the canonical home for full function/range documentation.
