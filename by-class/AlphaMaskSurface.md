*** UID:00000C | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# AlphaMaskSurface

## Status

- Confidence: strong for imported methods, layout, adjacent alpha view helper boundaries, and raw-byte evidence; medium-high for raw default-constructor callability and final `IntAlphaSurface` split.
- Likely source file: [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- Address range: [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md), plus raw default-constructor-shaped range [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md)
- Current recovered file: `source-3/simroot_v2/class_AlphaMaskSurface.cpp`
- Layout docs: [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md), [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md)

## Class Purpose

`AlphaMaskSurface` owns a temporary byte alpha-mask buffer. It is used to build procedural light masks, overlay masks, and clipped byte-mask views that are later consumed by render blitters.

## Observed State

```text
0x00  vtable
0x04  Rect bounds
0x14  uint8_t* pixels
0x18  int width
0x1c  int height
0x20  int stride
0x24  bool ownsBuffer
```

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `AlphaMaskSurface::AlphaMaskSurface` default/raw | `0x00462120-0x00462161` | Raw constructor-shaped bytes initialize an empty owning surface; IDA reports no function or xrefs at the start. |
| `AlphaMaskSurface::AlphaMaskSurface` | `0x00462170` | Initializes bounds and allocates `width * height` byte pixels. |
| `IntAlphaSurface` unwind cleanup | [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md) | Compiler-generated EH cleanup target; not a handwritten method. |
| `IntAlphaSurface::ReleaseOwnedPixels` provisional | [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md) | Vtable slot helper that frees owned pixel storage for the sibling/view surface layout. |
| `GetCenterPoint` | `0x004622d0` | Writes half-height and half-width into a caller-provided pair. |
| `GetBufferInfo` | `0x00462300` | Copies `{pixels,width,height,stride,ownsBuffer}` into an output view. |
| `BuildClippedAlphaSurfaceView` provisional | [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md) | Builds a non-owning clipped view over the current pixel buffer. |
| `InitAlphaSurfaceView` provisional | [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md) | Initializes an `off_6112EC` full or clipped view object. |
| `ApplyRectAlpha` | `0x00462520` | Fills/adds/subtracts a clipped rectangle with a byte alpha value. |
| `FillRadialGradient` | `0x00462680` | Rasterizes circular alpha falloff using replace/add/subtract behavior. |
| `FillEllipticGradient` | `0x00462870` | Rasterizes elliptical alpha falloff with an inner flat-alpha radius. |

## Evidence Notes

- Wave3 metadata says this was restored from a missing-ref class around constructor `0x00462170`.
- IDA MCP reports constructor callers in `LightObjImageLib`, `UserPane`, and `GameServerConfig`-adjacent paths.
- IDA MCP reports `DrawFrameWithBlendMode` callers from the two `LightObjImageLib` draw modes, supporting this class as shared render infrastructure.
- Adjacent functions at `0x00462260`, `0x00462320`, `0x004623c0`, and `0x00462f20` operate on the same `{bounds,pixels,width,height,stride,ownsBuffer}` layout but are not all assigned to the class by Wave3 yet.
- 2026-05-26 IDA MCP caller/xref recheck maps `DrawEncodedAlphaFrame` modeled callers to [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md), [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md), [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md), and [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md) overlay paths. The remaining raw xrefs at `0x004d5ea6`, `0x004d6b16`, and `0x004dcca5` still need function-boundary recovery.
- IDA MCP recheck on 2026-05-25 confirms `0x00462320` has a live `StaticObjImageLib` caller, while `0x004623c0` and `0x00462260` are vtable/layout helpers without direct code callers in the current IDA database.
- 2026-05-26 IDA MCP recheck confirms the object offsets and view record layout: vtable at `+0x00`, bounds at `+0x04`, pixels at `+0x14`, width/height/stride at `+0x18/+0x1c/+0x20`, and ownership flag at `+0x24`.
- 2026-05-26 IDA MCP raw-disassembly recheck found constructor-shaped bytes at `0x00462120-0x00462161` that initialize the same layout with zero bounds and no pixels, but `lookup_funcs` and `xrefs_to` do not prove a callable function boundary.
- 2026-05-26 IDA MCP raw-disassembly/xref recheck found `0x00462230-0x00462258` as an EH-only cleanup target reached from `0x005fa593`; it writes the same `off_6112EC` vtable and releases owned pixels, but should be ignored for handwritten source reconstruction.
- Current `class_AlphaMaskSurface.meta_wave3` reports `vtable_count: 0` and active methods only at `0x00462170`, `0x004622d0`, `0x00462300`, `0x00462520`, `0x00462680`, and `0x00462870`; the raw default constructor, release/view helpers, and encoded-alpha blitter remain outside the active class output.
- Nearby `0x004632c0` is not part of this class family; it uses vtable `0x00612574` and belongs to application error-state cleanup.
- 2026-05-30 IDA MCP recheck confirms the raw default constructor range still has no IDA function object or xrefs, but its raw bytes initialize the same vtable/layout and terminate at `0x00462160` before `0x00462161-0x00462170` alignment.
- 2026-05-30 IDA MCP recheck confirms `BuildClippedAlphaSurfaceView` writes a concrete 0x14-byte output view with pointer, dimensions, stride, and non-owning flag, strengthening the layout and helper documentation.
- 2026-05-30 IDA MCP recheck confirms `DrawEncodedAlphaFrame` is a shared encoded-row alpha blitter over this surface layout, with six modeled image-library callers and three raw image-library xrefs still requiring function-boundary recovery.

## Cross-References

- [UID:0000HF][AlphaMaskSurface](by-file/AlphaMaskSurface.md)
- [UID:0000YL][0x00462170-0x00462e03.AlphaMaskSurface](by-memory/0x00462170-0x00462e03.AlphaMaskSurface.md)
- [UID:0000YK][0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor](by-memory/0x00462120-0x00462161.AlphaMaskSurfaceRawDefaultConstructor.md)
- [UID:0000YM][0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup](by-memory/0x00462230-0x00462258.IntAlphaSurfaceUnwindCleanup.md)
- [UID:0001TP][AlphaMaskSurfaceLayout](by-type/by-struct/AlphaMaskSurfaceLayout.md)
- [UID:0001TQ][AlphaSurfaceBufferView](by-type/by-struct/AlphaSurfaceBufferView.md)
- [UID:0001XT][IntAlphaSurfaceVtable](by-type/by-vtable/IntAlphaSurfaceVtable.md)
- [UID:0000TX][AlphaSurfaceReleaseOwnedPixels_00462260](by-item/AlphaSurfaceReleaseOwnedPixels_00462260.md)
- [UID:0000U3][BuildClippedAlphaSurfaceView_00462320](by-item/BuildClippedAlphaSurfaceView_00462320.md)
- [UID:0000UU][InitAlphaSurfaceView_004623C0](by-item/InitAlphaSurfaceView_004623C0.md)
- [UID:0000UI][DrawFrameWithBlendMode_00462E10](by-item/DrawFrameWithBlendMode_00462E10.md)
- [UID:0000UH][DrawEncodedAlphaFrame_00462F20](by-item/DrawEncodedAlphaFrame_00462F20.md)
- [UID:0000LJ][MonsterImageLib](by-file/MonsterImageLib.md)
- [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:0000KH][ItemObjImageLib](by-file/ItemObjImageLib.md)
- [UID:0000LR][NewHumanImageLib](by-file/NewHumanImageLib.md)
- [UID:0000YQ][0x004632c0-0x0046330b.ApplicationErrorStateCleanup](by-memory/0x004632c0-0x0046330b.ApplicationErrorStateCleanup.md)

## Changes

- What existed before: the page had detailed render-surface layout, method, raw-boundary, and cross-reference evidence but still had unevaluated `0/0` metadata.
- What it was changed to: scores were set to `78/84`; no class/file ownership change was made.
- Summary and evidence: completion remains below high because the raw default constructor, `IntAlphaSurface` split, view helpers, and encoded-alpha blitter ownership still need a final source-level split.
- 2026-05-30: Raised completion/confidence from `78/84` to `82/88`. Added current IDA MCP evidence for the raw default-constructor-shaped range and clipped-view output fields; the `IntAlphaSurface` split and some helper names remain provisional.
- 2026-05-30: Raised completion/confidence from `82/88` to `84/89` after current IDA MCP verification of `DrawEncodedAlphaFrame`; remaining class-level gaps are the final frame-source type, three raw image-library xrefs, and the `IntAlphaSurface` split.
