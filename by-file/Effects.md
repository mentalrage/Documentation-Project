*** UID:0000IZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Effects

## Status

- Confidence: strong for a shared runtime effects module, medium for exact original filename.
- Proposed module: `render/Effects.cpp`
- Proposed header: `render/Effects.h`
- Current recovered sources: one-class Wave3 staging files such as `class_ScreenEffecter.cpp`, `class_OverlayEffecter.cpp`, `class_FilterEffecter.cpp`, and specific effecter subclasses.
- Main runtime cluster: `0x0055a260-0x0055c1ff`
- Vtable/layout anchor: [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- Related effect object pane cluster: `0x005387b0-0x00538baa`, plus destructor at `0x0053d100-0x0053d196`

## File Role

`Effects.cpp` should hold runtime screen effects, overlay effects, pixel displacement effects, and filter effects. This is separate from [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md), which loads `EFFECT.TBL`, `EFFECT.FRM`, and effect EPF/EPD image data. The runtime effecters consume map, pane, palette, image, and timer services to draw or animate effects on top of the game view.

Keep [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md) separate from this module for now. `ScreenDimmer` and `ScreenFadeOut` are adjacent generic UI overlay panes at `0x00559b90-0x0055a252`, while this file owns the later `ScreenEffecter` runtime hierarchy beginning at `0x0055a260`.

The generated one-class split appears to be a Wave3 staging artifact. The effecter methods are tightly clustered in memory, share base classes and pane/vtable setup patterns, and use the same screen/map globals.

## Proposed Contents

| Class | Current file | Key ranges | Role |
| --- | --- | --- | --- |
| `ScreenEffecter` | `class_ScreenEffecter.cpp` | `0x0055bfd0-0x0055bff3`, `0x0055c1d0-0x0055c1fe` | Base virtual effect interface and completion test. |
| `PixelEffecter` | `class_PixelEffecter.cpp` | `0x0055a2a0-0x0055a2b3` | Minimal base for per-pixel/map postprocessing effects. |
| `OverlayEffecter` | `class_OverlayEffecter.cpp` | `0x0055a2e0-0x0055a3c9`, `0x0055a560-0x0055a5d4`, `0x0055bbf0-0x0055bc8c` | Base pane-backed overlay effect using parcel bounds and render layer globals. |
| `OverlayImageEffecter` | `class_OverlayImageEffecter.cpp` | `0x0055a440-0x0055a55d`, `0x0055bd70-0x0055be0c` | Static fitting-room/download overlay by image and overlay name. |
| `OverlayFrameImageEffecter` | `class_OverlayFrameImageEffecter.cpp` | `0x0055a5e0-0x0055a796`, `0x0055bc90-0x0055bd62` | Frame-indexed overlay image effect. |
| `OverlayImageOnPointEffecter` | `class_OverlayImageOnPointEffecter.cpp` | `0x0055a7a0-0x0055a986`, `0x0055be10-0x0055bee2` | Overlay image drawn at a specific pane point. |
| `OverlayMovingImageEffecter` | `class_OverlayMovingImageEffecter.cpp` | `0x0055a990-0x0055acf6`, `0x0055bef0-0x0055bfc2` | Scrolling/repeating overlay image effect. |
| `FilterEffecter` | `class_FilterEffecter.cpp` | `0x0055ad00-0x0055adba`, `0x0055ba22-0x0055ba29` | Base pane-backed full-screen filter effect. |
| `SolidColorFilterEffecter` | `class_SolidColorFilterEffecter.cpp` | `0x0055ae00-0x0055afa4`, `0x0055c000-0x0055c0bd` | Color-fill filter with RGB-to-16-bit conversion and alpha/opacity state. |
| `CloudFilterEffecter` | `class_CloudFilterEffecter.cpp` | `0x0055b000-0x0055b037` | Cloud filter specialization over `FilterEffecter`. |
| `StaticCloudFilterEffecter` | `class_StaticCloudFilterEffecter.cpp` | `0x0055b090-0x0055b0c7` | Static cloud variant. |
| `WaterFilterEffecter` | `class_WaterFilterEffecter.cpp` | `0x0055b5d0-0x0055b80e`, `0x0055c0c0-0x0055c17d` | Water/caustic filter; advances palette frame using render tick and `CAUST.PAL` timing. Exact update body: [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md). |
| `EarthquakeEffecter` | `class_EarthquakeEffecter.cpp` | `0x0055b110-0x0055b292`, `0x0055bb90-0x0055bbb3` | Camera shake effect using timer/random offsets and map pane blits. |
| `XWaveEffecter` | `class_XWaveEffecter.cpp` | `0x0055b2a0-0x0055b49a`, `0x0055c180-0x0055c1a3` | Horizontal sine-wave scanline displacement. |
| `YFlipEffecter` | `class_YFlipEffecter.cpp` | `0x0055b4a0-0x0055b5c2` | Vertical scanline flip. |
| `LakeEffecter` | `class_LakeEffecter.cpp` | `0x0055b810-0x0055b851`, `0x0055b870-0x0055ba21`, `0x0055bbc0-0x0055bbe3` | Waterline/reflection render effect. |
| `EffectObjectPane` | `class_EffectObjectPane.cpp` | `0x005387b0-0x00538baa`, `0x0053d100-0x0053d196` | Game object pane for animated effect sprites, sounds, optional lighting changes, and its embedded idle timer helper. |

## Evidence

Wave3 `search symbol Effecter --limit 80 --include-fields` finds the effecter class family, the stale `g_pScreenEffecterList` global-data alias, and the generated one-class source files. `list next-method --class ...` shows the runtime effecter methods are small, high-grade class methods. IDA-backed memory ranges place the core effecter family in a close `0x0055a260-0x0055c1ff` neighborhood.

IDA MCP checks on 2026-05-23 confirmed function boundaries for representative larger methods including `0x0055a2e0-0x0055a3ca`, `0x0055a440-0x0055a499`, `0x0055a990-0x0055aae3`, `0x0055ad00-0x0055adbb`, `0x0055ae00-0x0055aec3`, `0x0055b2a0-0x0055b2cf`, `0x0055b5d0-0x0055b698`, `0x0055bfd0-0x0055bff4`, and `0x0055c1d0-0x0055c1ff`. IDA also confirmed the `EffectObjectPane` core methods at `0x005387b0`, `0x005388c0`, `0x00538960`, `0x005389d0`, `0x00538af0`, and `0x0053d100`. A 2026-05-26 recheck ties `EffectObjectPane::RenderEffect` at `0x00538af0` to [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md) at call site `0x00538ba0`.

2026-06-01 IDA MCP recheck fills the two small functions inside the `EffectObjectPane` core aggregate: [UID:0002QV][0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor](by-memory/0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor.md) and [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md). The latter had been generated as `BackPane::StartIdleTimer`, but the only caller constructs an `EffectObjectPane` and then starts the timer on the same object pointer.

IDA MCP checks on 2026-05-26 confirmed the effecter vtable family from `0x006235a4` through `0x00623cf8`. Overlay and filter effecters use four vtable views at object offsets `+0x00`, `+0x04`, `+0xa4`, and `+0xa8`; pixel-only effecters use one primary view. Current `simroot_v2` metadata reports `vtable_count: 0` for the checked classes, so use [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md) as the layout anchor until generated metadata catches up.

The same 2026-05-26 pass also rechecked the tiny constructor starts that IDA does not model as functions. Raw disassembly confirms constructor-shaped bytes and vtable stores for `PixelEffecter`, `CloudFilterEffecter`, `StaticCloudFilterEffecter`, `EarthquakeEffecter`, `YFlipEffecter`, and `LakeEffecter`; see [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md). This is enough to keep them in `render/Effects.cpp`, with the caveat that the starts are raw code boundaries rather than IDA function records.

2026-05-25 recheck: `0x0055b5d0` remains `WaterFilterEffecter::UpdateCausticEffect`, not a `DrawPictureObjectPane` method. The body advances the caustic frame, calls `LoadFrameDrawRecord_004D1600`, and renders through the shared tiled-background helper.

2026-05-26 IDA static-pool review identifies an [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md) [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md) at `0x0069b90c`, constructed by `0x0041a080` and destroyed by `0x0060c340`.

## Ownership Guidance

Use `render/Effects.cpp` as the initial grouping for the runtime effecter classes. Keep the effect sprite asset loader in [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md). Keep map packet creation/teardown orchestration in [UID:0000L3][MapPane](by-file/MapPane.md); `MapPane` should create/clear effects, but the effect classes themselves belong in render/effects code.

`g_pScreenEffecterList` should not be treated as an `Effects.cpp` global. 2026-05-26 IDA/simroot review resolves it as a stale alias for `dword_69B364`, a broadly used UI layer/context slot initialized and released with the main UI graph. `SolidColorFilterEffecter` is only one pane setup consumer. See [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md).

[UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md) should remain a map-object module even though [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md) calls `LightingObjectPane::SetIntensity` during animation updates. The effect object owns animation timing; the light object owns the live light-source interface and intensity rebinding.

## Open Questions

- Whether the original source used one `Effects.cpp` or a small `render/effects/` folder split.
- Whether the generic screen dim/fade overlays were in `ui/core/ScreenDimmer.cpp`, a paired `ScreenFadeOut.cpp`, or an older generic transition module. Current evidence favors keeping them out of this runtime effecter module.
- Whether `EffectObjectPane` was in this runtime module, in an object-pane module, or next to [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md). Current evidence favors a runtime/game-object pane neighbor rather than an asset-library file.
- The exact final source name for the `dword_69B364` UI layer/context slot that old generated data called `g_pScreenEffecterList`; this should be solved with [UID:0000L1][MainUiGraph](by-file/MainUiGraph.md), not by creating a screen-effecter list type.
- Whether cloud, water, lake, earthquake, wave, and overlay effect classes were declared in one header or split into private headers.

## Cross-References

- [UID:0000C9][ScreenEffecter](by-class/ScreenEffecter.md)
- [UID:0000AI][PixelEffecter](by-class/PixelEffecter.md)
- [UID:00009W][OverlayEffecter](by-class/OverlayEffecter.md)
- [UID:00009Y][OverlayImageEffecter](by-class/OverlayImageEffecter.md)
- [UID:00009X][OverlayFrameImageEffecter](by-class/OverlayFrameImageEffecter.md)
- [UID:00009Z][OverlayImageOnPointEffecter](by-class/OverlayImageOnPointEffecter.md)
- [UID:0000A0][OverlayMovingImageEffecter](by-class/OverlayMovingImageEffecter.md)
- [UID:00004Y][FilterEffecter](by-class/FilterEffecter.md)
- [UID:0000DE][SolidColorFilterEffecter](by-class/SolidColorFilterEffecter.md)
- [UID:00002T][CloudFilterEffecter](by-class/CloudFilterEffecter.md)
- [UID:0000E0][StaticCloudFilterEffecter](by-class/StaticCloudFilterEffecter.md)
- [UID:0000FZ][WaterFilterEffecter](by-class/WaterFilterEffecter.md)
- [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md)
- [UID:0000GC][XWaveEffecter](by-class/XWaveEffecter.md)
- [UID:0000GD][YFlipEffecter](by-class/YFlipEffecter.md)
- [UID:000070][LakeEffecter](by-class/LakeEffecter.md)
- [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md)
- [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md)
- [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md)
- [UID:0001GA][0x00559b90-0x0055a252.ScreenDimmerAndFadeOut](by-memory/0x00559b90-0x0055a252.ScreenDimmerAndFadeOut.md)
- [UID:0001GE][0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster](by-memory/0x0055a260-0x0055c1ff.ScreenEffecterRuntimeCluster.md)
- [UID:0000VE][ScreenEffecterSmallConstructorBoundaries](by-item/ScreenEffecterSmallConstructorBoundaries.md)
- [UID:0001YO][ScreenEffecterVtableFamily](by-type/by-vtable/ScreenEffecterVtableFamily.md)
- [UID:0001GF][0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect](by-memory/0x0055b5d0-0x0055b698.WaterFilterEffecterUpdateCausticEffect.md)
- [UID:0001D9][0x005387b0-0x00538baa.EffectObjectPaneCore](by-memory/0x005387b0-0x00538baa.EffectObjectPaneCore.md)
- [UID:0002QV][0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor](by-memory/0x00538880-0x0053889f.EffectObjectPaneNonDeletingDestructor.md)
- [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md)
- [UID:0000S6][g_pScreenEffecterList](by-global/g_pScreenEffecterList.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md)
- [UID:00017M][0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame](by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:0001QI][client_new_rendering_mode](by-meta/client_new_rendering_mode.md)
- [UID:0000TI][PoolAllocatorStaticInstances](by-global/PoolAllocatorStaticInstances.md)

## Changes

- 2026-05-28: Changed the runtime cluster start from `0x0055a2a0` to `0x0055a260`.
  - Before: the file doc treated the runtime effecter module as beginning at `PixelEffecter`.
  - After: the file doc includes the earlier `ScreenEffecter` tiny vtable/default stubs at `0x0055a260-0x0055a297`.
  - Evidence: IDA MCP reports real code heads at `0x0055a260`, `0x0055a270`, `0x0055a280`, and `0x0055a290`, followed by the existing `PixelEffecter` constructor at `0x0055a2a0`.
- 2026-05-28: Corrected the `EffectObjectPane` core endpoint.
  - What existed before: the `EffectObjectPane` core range was listed as `0x005387b0-0x00538ba9`.
  - Changed to: the range is now `0x005387b0-0x00538baa`.
  - Summary/evidence: IDA MCP function review shows `EffectObjectPane::RenderEffect` ending at exclusive address `0x00538baa`; byte `0x00538ba9` is part of that function body.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:80`.
  - Summary/evidence: runtime effecter grouping, class inventory, vtable family, small-constructor caveats, EffectObjectPane relationship, asset-library separation, global alias correction, open split questions, and endpoint/range changes are documented; confidence remains at 80 because exact original file/folder split and several raw constructor boundaries remain open.
- 2026-06-01 EffectObjectPane child fill:
  - What existed before: the `EffectObjectPane` core aggregate omitted `0x00538880`, and `0x005388a0` was tracked as a generated BackPane caveat.
  - Changed to: both child bodies are tracked under `EffectObjectPane`, and this file now has `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/render/"`.
  - Summary/evidence: IDA MCP function/decompile/caller evidence shows `0x005388a0` is called on the same object pointer constructed by `0x005387b0`, while `0x00538880` resets EffectObjectPane vtables before inherited cleanup.
