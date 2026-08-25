*** UID:0000P8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# WeatherLayerPane

## Status

- Confidence: very strong for base/weather-layer behavior, map construction path, exact rain and snow source declarations/boundaries, shared weather data, and the current one-file weather-family source placement.
- Proposed module folder: `map/`
- Current emitted files: one combined `map/WeatherLayerPane.cpp` and dependency-complete `map/WeatherLayerPane.h`.
- Historical source-layout candidates: dedicated `RainingLayerPane.cpp`, `SnowingLayerPane.cpp`, and `SwallowLayerPane.cpp` remain recorded as unproven physical-file hypotheses, not competing current emitters.
- Main memory docs: [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md), exact Weather/Rain children [UID:0003PG][0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor](by-memory/0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md), [UID:0003PH][0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer](by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md), [UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md), [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md), [UID:0003PK][0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget](by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md), [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md), [UID:0001O0][0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex](by-memory/0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex.md), [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md), [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md), and [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md)
- Shared globals/types: [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md) and [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md)

## File Role

The weather layer sources own map-overlay effects created by `MapPane` when server/weather state changes. `WeatherLayerPane` is the base pane that computes effect bounds and implements the shared `bool OnTimer(int,int,int)` animation callback. Timer ID `0` advances signed frame state, invalidates inherited visible bounds, calls the Weather-added `OnFrameChanged()` hook, and schedules the next frame. `RainingLayerPane`, `SnowingLayerPane`, and `SwallowLayerPane` provide concrete overlay behavior.

Current source placement selects one `WeatherLayerPane.cpp` compilation family. Three independent clusters agree: weather/rain/snow/swallow code is contiguous at `0x005c12a0-0x005c2ab5`, their RTTI/vtables are contiguous at `0x0063118c-0x006313cc`, and exact rain data ends where snow data begins at `0x00670784`. Current Raining, Snowing, Swallow, Weather, weather-global, and weather-layout routes also converge here. Historical Wave2 import provenance named separate layer files, but that material is non-authoritative and no PDB/source-path evidence proves the split; dedicated concrete files remain recorded as secondary historical hypotheses.

## 2026-08-16 Swallow Whole-File Closure

The combined source family now includes the complete Swallow slice rather than a sampled or marker-only subset. Exact source children are constructor [UID:00054K][0x005c2230-0x005c2340.SwallowLayerPaneConstructor](by-memory/0x005c2230-0x005c2340.SwallowLayerPaneConstructor.md), destructor [UID:00054L][0x005c2340-0x005c235f.SwallowLayerPaneDestructor](by-memory/0x005c2340-0x005c235f.SwallowLayerPaneDestructor.md), `OnPaint` [UID:00054M][0x005c2360-0x005c2423.SwallowLayerPaneOnPaint](by-memory/0x005c2360-0x005c2423.SwallowLayerPaneOnPaint.md), `MoveBy` [UID:00054N][0x005c2430-0x005c24fa.SwallowLayerPaneMoveBy](by-memory/0x005c2430-0x005c24fa.SwallowLayerPaneMoveBy.md), `OnTimer` [UID:00054O][0x005c2500-0x005c26a6.SwallowLayerPaneOnTimer](by-memory/0x005c2500-0x005c26a6.SwallowLayerPaneOnTimer.md), `DrawOnTarget` [UID:00054P][0x005c26b0-0x005c275c.SwallowLayerPaneDrawOnTarget](by-memory/0x005c26b0-0x005c275c.SwallowLayerPaneDrawOnTarget.md), retained `StartSwallowFlight` [UID:00054Q][0x005c2760-0x005c2835.SwallowLayerPaneStartSwallowFlight](by-memory/0x005c2760-0x005c2835.SwallowLayerPaneStartSwallowFlight.md), retained `StepSwallowFlight` [UID:00054R][0x005c2840-0x005c292e.SwallowLayerPaneStepSwallowFlight](by-memory/0x005c2840-0x005c292e.SwallowLayerPaneStepSwallowFlight.md), `InvalidateSwallowRect` [UID:00054S][0x005c2930-0x005c299f.SwallowLayerPaneInvalidateSwallowRect](by-memory/0x005c2930-0x005c299f.SwallowLayerPaneInvalidateSwallowRect.md), and retained `GetCurrentSwallowRect` [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md). They emit in positions 10 through 100 under [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md). The overlapping indexes [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md)/[UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md), compiler thunks [UID:00054T][0x005c2a02-0x005c2a18.SwallowLayerPaneDestructorAdjustorThunks](by-memory/0x005c2a02-0x005c2a18.SwallowLayerPaneDestructorAdjustorThunks.md), scalar deleting destructor [UID:00054U][0x005c2a60-0x005c2ab5.SwallowLayerPaneScalarDeletingDestructor](by-memory/0x005c2a60-0x005c2ab5.SwallowLayerPaneScalarDeletingDestructor.md), vtable/RTTI [UID:0002ZA][0x0063133c-0x006313cc.SwallowLayerPaneVtableData](by-memory/0x0063133c-0x006313cc.SwallowLayerPaneVtableData.md), constructor literals [UID:0002ZB][0x006313cc-0x006313fc.SwallowLayerResourceStrings](by-memory/0x006313cc-0x006313fc.SwallowLayerResourceStrings.md), and exact padding remain nonduplicating evidence.

The sibling header is assembled in dependency order through formal H fragments. [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md) opens the single guard, directly includes `Pane.h` and complete `EPFTileContext.h`, and declares `SnowParticleEntry`; [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md) emits the complete base; [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md), [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md), and [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md) follow in positions 20/30/40. UID0000E9 closes with exact `0x14`, `0x10c`, `0x10c`, `0x10ac`, and `0x16c` compile-time size checks and the one final guard terminator. This ordering gives the by-value `EPFTileContext[2]` and `SnowParticleEntry[200]` members complete types without reverse-engineered explicit padding or duplicate declarations.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `WeatherLayerPane` | [UID:0003PG][0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor](by-memory/0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md), [UID:0003PH][0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer](by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md) | Base map weather overlay pane, effect bounds, signed animation state, shared timer callback, inherited visible-bounds invalidation, and polymorphic frame-change hook. |
| `RainingLayerPane` | [UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md), [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md), [UID:0003PK][0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget](by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md); parent index [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md) | Exact source-backed 0x10c Rain object: constructor sets 120 ms, three frames, and inherited direct-target paint mode; virtual methods render the main-view and supplied-target streak/splash paths. |
| `SnowingLayerPane` | source-bearing constructor [UID:0003O0][0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor](by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md), exact method children through `0x005c2228`, plus compiler thunks/destructor at `0x005c29ec-0x005c2a5b`; randomize child [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md) | Exact `0x10ac` Snow object: `0x10c` Weather prefix plus inline `SnowParticleEntry[200]`; constructor sets inherited `4/5/200`, initializes every record to bounds `(0,800,8,808)` and type zero, then enables inherited direct-target drawing. Exact child pages own qualified bodies. |
| `SwallowLayerPane` | exact source children [UID:00054K][0x005c2230-0x005c2340.SwallowLayerPaneConstructor](by-memory/0x005c2230-0x005c2340.SwallowLayerPaneConstructor.md)-[UID:00054S][0x005c2930-0x005c299f.SwallowLayerPaneInvalidateSwallowRect](by-memory/0x005c2930-0x005c299f.SwallowLayerPaneInvalidateSwallowRect.md) and [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md), plus compiler/data support [UID:00054T][0x005c2a02-0x005c2a18.SwallowLayerPaneDestructorAdjustorThunks](by-memory/0x005c2a02-0x005c2a18.SwallowLayerPaneDestructorAdjustorThunks.md)/[UID:00054U][0x005c2a60-0x005c2ab5.SwallowLayerPaneScalarDeletingDestructor](by-memory/0x005c2a60-0x005c2ab5.SwallowLayerPaneScalarDeletingDestructor.md)/[UID:0002ZA][0x0063133c-0x006313cc.SwallowLayerPaneVtableData](by-memory/0x0063133c-0x006313cc.SwallowLayerPaneVtableData.md)/[UID:0002ZB][0x006313cc-0x006313fc.SwallowLayerResourceStrings](by-memory/0x006313cc-0x006313fc.SwallowLayerResourceStrings.md) | Complete timed sprite-flight overlay using constructor literals `SWALLOW.EPF`/`SWALLOW.EPD`, exact `0x16c` layout, and ten human-source methods. |
| weather static data | [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md), [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md), [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md) | UID0001ON emits exact writable rain types/arrays at source position 0. UID0001OO emits six exact writable unsigned snow arrays at position 1. Descriptor backing stays covered by the exact Snowing method children. |

## Ownership Notes

- 2026-07-22 B005 source-family closure routes [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md) directly through this file at emitter position 0. Its exact source contents are `RainStreak`, `RainSplash`, `s_targetRainStreaks`, `s_targetRainSmallSplashes`, `s_targetRainLargeSplashes`, `s_rainStreaks`, `s_rainSmallSplashes`, and `s_rainLargeSplashes`, with complete initializers, writable internal linkage, six distinct physical objects, and three compiler-alignment gaps.
- 2026-07-26 B002 source-family closure routes [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md) directly through this file at emitter position 1. Its exact source contents are `s_targetSnowTypeThresholds`, `s_targetSnowSizes`, `s_targetSnowPatterns`, `s_snowTypeThresholds`, `s_snowSizes`, and `s_snowPatterns`: six writable internal-linkage unsigned-byte arrays containing byte-identical but physically distinct 40-byte target/main families.
- The first three arrays serve the supplied target-port draw method, not a proven minimap-only path. The remaining three serve main-view `OnPaint`. Corresponding arrays are byte-identical but must not be deduplicated because each family has a distinct exclusive consumer and physical storage.
- The one-file decision does not transfer direct semantic method ownership from the concrete classes. [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md), [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md), and [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md) remain direct class owners; this page is their compilation/source-family route.
- `MapPane::SetWeatherEffect`/weather-state logic at `0x0050db50` allocates one of the weather layers and attaches it to the map pane. IDA confirms direct constructor calls to `RainingLayerPane`, `SnowingLayerPane`, and `SwallowLayerPane` from that function.
- 2026-06-02 IDA recheck confirmed `0x0050db50` as a modeled function start, the base constructor callers, and timer references at `0x00631218`, `0x006312a8`, and `0x00631338`. Historical `OnTimerEvent` wording is superseded by exact source contract `WeatherLayerPane::OnTimer` under UID0003PH.
- 2026-06-13 IDA MCP `lookup_funcs` reconfirmed the core weather-family modeled starts and sizes used by this page: base constructor `0x005c12a0` size `0x101`, base timer `0x005c13b0` size `0x58`, rain constructor `0x005c1410` size `0x4a`, snow constructor `0x005c1bd0` size `0xae`, snow update/render `0x005c1c80` size `0x2cc`, snow randomize `0x005c1f50` size `0x184`, snow render `0x005c20e0` size `0x148`, and snow scalar deleting destructor `0x005c2a20` size `0x3b`.
- Keep these classes under `map/`, not generic render, unless later evidence proves the original project grouped weather effects with render effects. The owning lifetime and construction path are map-state driven.
- [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md) already has a dedicated source candidate. Use this page as the broader source-family and base-class anchor.
- Historical generated output emitted the real `0x005c2340` destructor and `0x005c2930` invalidation helper but mis-owned `0x005c2760`/`0x005c2840` as BackPane methods. The 2026-08-16 whole-file closure replaces that malformed source route with exact Swallow children while retaining the historical defect and negative route evidence.
- Historical 2026-06-27 B011 evidence found no function object, xref, VA/RVA pointer route, Swallow vtable route, or confirmed direct-transfer entry for either raw start and therefore kept [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md) marker-only. Those checks remain valid; the complete body/field/inlining and retained-method reanalysis now resolves authored source as [UID:00054Q][0x005c2760-0x005c2835.SwallowLayerPaneStartSwallowFlight](by-memory/0x005c2760-0x005c2835.SwallowLayerPaneStartSwallowFlight.md)/[UID:00054R][0x005c2840-0x005c292e.SwallowLayerPaneStepSwallowFlight](by-memory/0x005c2840-0x005c292e.SwallowLayerPaneStepSwallowFlight.md), while UID0001O3 remains an unsplit non-emitting evidence index.
- 2026-06-17 B002 reanalysis corrected [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md)'s end to `0x005c299f` and added [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md) for the adjacent no-xref Swallow rect builder. The 2026-06-23 B002 MCP-backed accepted implementation corrected this raw helper from stale endpoint `0x005c29ea` to `0x005c29ec`; accepted MCP session `0b5e057e` reports no function at `0x005c29a0`, reports successor `sub_5C29EC` at `0x005c29ec`, and `get_bytes`/`disasm` shows `0x005c29e9: retn 4` consumes bytes through `0x005c29eb`, so there is no post-helper padding before the Snowing thunk at `0x005c29ec`. Both remain under the selected one-file weather-layer source-family route; a separate Swallow file is retained only as historical physical-file uncertainty.
- For [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md), direct semantic ownership remains [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md), not base WeatherLayerPane; this page is only the selected file route. B002 MCP session `0b5e057e` proved no function object, decompile failure, zero xrefs, no pointer/table/vtable route, unique bytes, and the Snowing-thunk meaning of `0x00631304 -> 0x005c29ec`. Those negative checks and rejected BackPane/Snowing/base-Weather/padding alternatives remain preserved. The current source reconstruction accepts `GetCurrentSwallowRect(RectBounds *) const` as the best-supported retained human method and emits it through UID0003YQ without claiming symbol-level spelling proof.
- Use the [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md) and [UID:0001O0][0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex](by-memory/0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex.md) for migration boundaries. The old Snowing aggregate crossed Swallow code beginning at `0x005c2230`; exact Snowing children now carry the real method ranges.
- Generated `g_pWeatherState` in rain/snow output is an alias for [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) at `0x0067a764`, not a separate weather singleton. Weather drawing checks byte `g_activeMapPane + 0x3f0` before rendering.
- Current `source-3/simroot_v2/class_WeatherLayerPane.cpp` still duplicates marker-only `global-data` rows for `g_tileColumns` and `g_tileRows`; treat those duplicate comments as generated-output noise, not as separate storage records.
- 2026-07-05 B004 UID0002Z7 generated-route sync: current generated coverage routes [UID:0002Z7][0x0063118c-0x0063121c.WeatherLayerPaneVtableData](by-memory/0x0063118c-0x0063121c.WeatherLayerPaneVtableData.md) as coded through [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md) to `auto-generated/NexusTK/map/WeatherLayerPane.cpp`, but the pre-callback generated source lacked the UID0002Z7 marker because the WeatherLayerPane class marker did not yet expose a `[[CHILDREN]]` insertion point. The accepted route repair is class-side only: the generated source should include UID0002Z7 as an intentional no-hand-authored-vtable marker through the class child route after validation, and it should not emit a raw C++ vtable array/body for the RTTI/vtable data page. Exact original one-file versus per-layer disk history remains unproven and caps confidence, while the current reconstruction route is the one-file family.

## 2026-07-24 UID0003O0 Snow Constructor Source Closure

- [UID:0003O0][0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor](by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md) now owns the sole qualified `SnowingLayerPane::SnowingLayerPane()` body under the selected `NexusTK/map/WeatherLayerPane.cpp` family. The exact 174-byte body has one MapPane weather-setup caller at `0x0050dc17`; that caller allocates `0x10ac` bytes and stores the resulting concrete weather pane.
- The source object is `WeatherLayerPane`'s exact `0x10c` prefix followed by `SnowParticleEntry m_snowParticles[200]` at `+0x10c`. Each `0x14`-byte entry is `RectBounds bounds`, one-byte `type`, and three bytes of natural tail padding; the `0xfa0`-byte inline array ends at exact complete-object size `0x10ac`.
- Source-visible constructor work is inherited `m_currentFrame = 4`, `m_frameCount = 5`, `m_timerInterval = 200`, a 200-entry loop calling `InitRectBounds(..., 0, 800, 8, 808)` and setting only `type = 0`, then inherited `m_drawOnTarget = true`. Tail padding is untouched. The Weather base call, three Snow vptr stores, EH/cookie state, cleanup funclet, and returned `this` are compiler lowering.
- Canonical declaration order is `RectBounds`/`InitRectBounds`, `SnowParticleEntry`, complete `WeatherLayerPane`, then `SnowingLayerPane`. This page is the current source/header placement route only; it does not duplicate UID0003O0's method body, a partial class definition, or hand-authored vtable data.
- Dedicated `SnowingLayerPane.cpp` remains a documented historical disk-layout candidate. No PDB/source-path evidence overrides the current one-file route, so that provenance uncertainty is not an active constructor, ownership, or emission blocker.

## Snowing Randomize Source-Family Note

2026-06-23 B003 accepted MCP-backed implementation for [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md) preserves this page as the current weather-layer source-family route, not as the direct canonical method owner. The final evidence pass used MCP session `b880584f`.

- Current generated memory/class route: [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md) emits through [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md) to this weather-layer source-family root and `auto-generated/NexusTK/map/WeatherLayerPane.cpp`.
- Dedicated candidate: [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md) remains a plausible historical concrete source-file candidate because the project may have split the weather layers. Current snow byte-table declarations no longer route through that page; UID0001OO now emits through this selected file root at position 1.
- Placement decision: keep [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md) in the selected one-file source family. The accepted earlier report found no source-path/PDB proof, and MCP `find_regex LayerPane\\.cpp` found no source filename string proving a dedicated `SnowingLayerPane.cpp`; that dedicated candidate remains historical only.
- Ownership decision: keep [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md) as canonical owner/emitter for the method. This page remains source-family/file context, while [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md) remains candidate/support context.
- B003 MCP evidence for the randomize method: `lookup_funcs 0x005c1f50` returns `sub_5C1F50` size `0x184`; `decompile`/`disasm` confirm exact range `0x005c1f50-0x005c20d4`; MCP `get_bytes` gives target SHA256 prefix `501c485e42127a02`, predecessor padding `0x005c1f4c-0x005c1f50` as four `0xcc` bytes with SHA256 prefix `8843b54d2df63ca2`, and successor padding `0x005c20d4-0x005c20e0` as twelve `0xcc` bytes with SHA256 prefix `a0d08a155aa4e9aa`; MCP `xrefs_to` confirms Snowing vtable route `0x006312fc -> 0x005c1f50`, sibling routes `0x006312f4 -> 0x005c1c80` and `0x006312c0 -> 0x005c20e0`, and MCP `func_profile` reports `caller_count:0` with no direct code caller/direct code xref.
- Method behavior relevant to file grouping: MCP disassembly shows `RandomizeSnowParticles` checks [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) byte `+0x3f0`, walks 200 records from `m_snowParticles` at `this+0x10c`, uses helper `0x004b7e10` as a rectangle dx/dy offset helper, gates rolling refresh on inherited signed `m_currentFrame` at `this+0xf8`, shifts 180 records with `memmove(this+0x29c, this+0x10c, 0xe10)` where `0xe10` is 3600 bytes (Verified with int_convert.py), and uses inherited `RectBounds m_weatherBounds` at `this+0xfc..+0x10b` while creating 20 leading records.
- Historical no-code policy: the earlier UID0003O2 pass treated object fields, file placement, and snow table declarations as blockers. UID0003O0/UID0003PG close the fields/current route and UID0001OO closes the exact target-family threshold/size declarations. UID0003O2 remains separately owned and its method body still requires its own exact callback; this data callback does not duplicate that body.

## 2026-07-26 UID0001OO Exact Snow Static Data Closure

- UID0001OO proves the source range is `[0x00670784,0x006707d4)`, not the historical 76-byte prefix. Bytes `0x006707d0-0x006707d3` complete `s_snowPatterns[1]`; libjpeg text starts exactly at `0x006707d4`.
- The target-port family is thresholds `{0,50,100,0}`, sizes `{4,3,0,0}`, and two fixed 16-byte patterns consumed by UID0003O2/UID0003O3. The main-view family is the byte-identical six-array counterpart consumed by UID0003O1.
- Each physical 40-byte family has SHA256 `4AD9D94FB72E08C575D44FC9CF0966944ABBD44377BDB5DB30BD6D1D1F73169E`; both remain distinct because they have distinct addresses and exclusive consumers.
- The arrays are mutable file-static data and therefore emit in `WeatherLayerPane.cpp`, not H, not a broad global page, not the Snowing class declaration, and not a new `WeatherTables.cpp`. UID0000TP and UID0001WJ remain non-duplicating support.
- Historical `g_snow...`, `Alt`, A/B/C/D names, the retired UID00028C four-byte padding classification, and current UID0000NR ownership are superseded but preserved as rejected provenance in UID0001OO.
- Rejected placements: `MapPane.cpp`, weather globals/table pages, render/GrafPort/CRT helper owners, aggregate indexes, and no-owner/non-emitting status do not own this class virtual method.

## 2026-07-01 B008 Empty-Emitter Family Audit

B008 implementation for [UID:0000P8] preserves this page as the weather-layer source-family/file route to generated `auto-generated/NexusTK/map/WeatherLayerPane.cpp`, while the direct class owners remain [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md), [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md), [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md), and [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md). The pre-callback generated-output audit baseline was validator command `000000003290`, refreshed `2026-07-01T04:46:53-04:00`, with source UID `0000P8`, `15` total emitters, `1` filled, `14` empty, `6.7%` filled, and `0` reports.

The fourteen-marker count is a historical 2026-07-01 baseline. Broad class/vtable/aggregate/global/type support remains comment-only to avoid duplicate source, while exact children emit exact bodies. UID0003O1 and UID0003O3 emit first-draft methods through UID0000DC; UID0001ON now emits exact rain data at position 0 and UID0001OO emits exact snow data at position 1. The data bodies are no longer empty or provisional blobs. Accepted helper mappings remain `BeginWeatherDraw -> 0x0069b3fc`, `RenderSnowParticle -> 0x0069b3e8`, `SetDrawColor -> 0x004b9660`, `OffsetRect -> 0x004b7e10`, and `SetRect -> 0x004b7c50`.

Rejected owners remain rejected: `MapPane`, `BackPane`, generic render/GrafPort helpers, weather global/type pages, vtable data pages, aggregate memory islands, and no-owner/non-emitting status do not own the exact weather-layer class virtual methods. [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md) is not changed by this callback and remains the previously accepted blank-C++ Snowing randomize scope.

## UID0002XW Weather/Rain Compiler Boundary

- Weather primary slot `0x00631190` and Rain primary slot `0x00631220` both point to [UID:0002XW][0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor](by-memory/0x0049b0d0-0x0049b10b.SelectBoxControlPaneScalarDeletingDestructor.md).
- Their four adjusted views at `0x006311e4`, `0x00631214`, `0x00631274`, and `0x006312a4` use the shared [UID:0002XV][0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks](by-memory/0x0049af11-0x0049af27.SelectBoxControlPaneAdjustorThunks.md). Button and Select supply the other equal primary/adjusted consumers.
- UID0002XW performs only Pane teardown, deleting-flags dispatch, optional operator delete, and a bit-4 call with `this`/`0x10c` to a one-byte no-op helper. It touches no weather/rain animation, bounds, frame, timer, render, or table state.
- Weather and Rain remain separate human class declarations under this selected source family, with likely implicit destructors. Do not add speculative explicit empty destructors or emit the shared hidden ABI wrapper/adjustors in `WeatherLayerPane.cpp`.
- One class-neutral entry shared by four named RTTI/vtable families is best explained by compiler COMDAT/identical-code folding. It does not confer Weather-family ownership over Button/Select compiler output or move either exact class's source-bearing methods.

## Cross-References

- [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md)
- [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md)
- [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md)
- [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md)
- [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md)
- [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md)
- [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md)
- [UID:0003PG][0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor](by-memory/0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md)
- [UID:0003PH][0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer](by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md)
- [UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md)
- [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md)
- [UID:0003PK][0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget](by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md)
- [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md)
- [UID:0003O1][0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles](by-memory/0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles.md)
- [UID:0003O3][0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles](by-memory/0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles.md)
- [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md)
- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md)

## 2026-07-23 UID0003PJ Current Source Closure

### Current Weather/Rain Source Shape

- Current canonical generated root is `NexusTK/map/WeatherLayerPane.cpp`. [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md) and [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md) are comment-plus-children source routers; exact child pages own qualified definitions.
- `WeatherLayerPane : public Pane` is exactly `0x10c` bytes:
  - signed-byte `m_currentFrame` at `+0xf8`;
  - signed-byte `m_frameCount` at `+0xf9`;
  - signed-short `m_timerInterval` at `+0xfa`;
  - `RectBounds m_weatherBounds` at `+0xfc`.
- `RainingLayerPane : public WeatherLayerPane` adds no storage and remains `0x10c`. Its exact source constructor sets `m_timerInterval = 120`, `m_frameCount = 3`, and inherited Pane `m_drawOnTarget = true`; primary/adjusted Rain vptr installation is compiler output. Historical 120-frame/frame-step-3, generic enabled, Pane-visibility, readiness, and raw `field_F6` wording is superseded.
- UID0001ON emits the exact private `RainStreak`/`RainSplash` types and six arrays once. Main-view arrays and target-port arrays are byte-identical pairs but remain separate source objects with their own alignment gaps and consumers.

### UID0003PJ Actual Method Source

- [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md) is now `92/94` with behavior-complete `void RainingLayerPane::OnPaint()` formal C++.
- Exact behavior is:
  1. `SetDrawColor(0)` and `g_pfnFillRect(this, &m_bounds)`;
  2. direct early return when `g_activeMapPane->m_waitingForLocalPlayerStatus` is nonzero, with no singleton null guard;
  3. draw color 143;
  4. 18 signed streak records using `MoveTo` and `g_pfnDrawLineDelta`;
  5. seven two-pixel small splashes and seven four-pixel large splashes through `g_pfnDrawPixel`.
- The formal preserves signed short/byte promotion, multiplication/division/truncation order, repeated `m_currentFrame` loads, and exact callback order. It adds no clipping, state restoration, table alias, or defensive behavior.
- Historical checkpoint: UID0003PK retained its own target-port tables and blank formal during the UID0003PJ pass because shared names/declarations alone did not prove the different body. The later UID0003PK pass independently reconstructed its bytes, ABI, virtual caller, clipping ownership, control flow, target-array loops, and negative behavior; it now emits its own behavior-complete `DrawOnTarget` definition.

### Final Header And Linkage Contracts

Human source reconstruction requires these canonical declarations in dependency order:

1. `Pane.h`: complete Pane/GrafPort/EventHandler/TimerHandler declarations, inherited `m_bounds`, `MoveTo`, `SetDrawColor`, virtual contracts, and exact `sizeof(Pane)==0xf8`.
2. `MapPane.h`: complete `MapPane` declaration of exact size `0x910`, public `m_waitingForLocalPlayerStatus` at `+0x3f0`, and `extern MapPane *g_activeMapPane`.
3. `Surface.h`: `SurfaceDrawPixelProc`, `SurfaceDrawLineDeltaProc`, and `SurfaceFillRectProc` typedefs plus extern declarations for `g_pfnDrawPixel`, `g_pfnDrawLineDelta`, and `g_pfnFillRect`. `Surface.cpp` owns exactly one definition of each through UID0000TN; UID0001PI remains blank.
4. `WeatherLayerPane.h`: complete `WeatherLayerPane`/`RainingLayerPane` hierarchy and field extents, the now-source-backed Weather constructor declaration, Weather OnTimer declaration, and Rain constructor/OnPaint/DrawOnTarget declarations.

The current validator emits these owners into `.cpp` files and does not materialize the four headers. Generated `WeatherLayerPane.cpp` is therefore evidence/output, not a standalone compile claim. Partial local class declarations, raw offset casts, fabricated accessors, and duplicate Surface storage are rejected because they would distort the original human source and/or object layout.

### Score And Boundary

- Score moves from `90/90` to `91/92` because exact Rain paint behavior, class extents, fields, callback ABI, source route, and final declaration contracts are resolved.
- The score remains below 95 because original private lexical spellings and historical one-file/per-layer disk split are inferred, current headers are not generated, and no final rebuild/codegen comparison exists.
- Existing Snow/Swallow family work, source-boundary history, helper inventories, and rejected alternatives remain unchanged. This callback does not claim whole-file completion or whole-Surface closure.

## 2026-07-24 UID0003PK DrawOnTarget Source Closure

### Exact Target Method Contract And Route

- [UID:0003PK][0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget](by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md) now emits behavior-complete `void RainingLayerPane::DrawOnTarget(GrafPort *target, const RectBounds *, const RectBounds *)` source through [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md) into this selected `NexusTK/map/WeatherLayerPane.cpp` family.
- Exact method evidence is one 951-byte body at `0x005c1810-0x005c1bc7`, SHA256 `13AF20BD86C583978C8B2EE099182C61F44C5783A14E8062A60E796558BFCE90`, reached only through Rain primary-vtable cell `0x00631230`. Four preceding and nine trailing `0xcc` bytes retain exact separation from OnPaint and SnowingLayerPane.
- The base `Pane::DrawOnTarget` declaration and `Layer::RenderRecursive` indirect call prove the supplied `GrafPort *` plus two `const RectBounds *` arguments. Layer configures target clipping before virtual dispatch, so Rain intentionally ignores both rectangle pointers and performs no local clip operation.

### Exact Runtime And Source Shape

- The method directly returns while `g_activeMapPane->m_waitingForLocalPlayerStatus` is nonzero, without adding a null guard. Otherwise it calls `target->SetDrawColor(143)` and renders 18 streaks, seven two-pixel small splashes, and seven four-pixel large splashes from the three target-port arrays, totaling 18 line-delta and 42 pixel callback calls.
- `RainStreak` and `RainSplash` remain signed-short records; all coordinate/frame loads remain signed. Target arrays remain physically distinct from byte-identical main-view arrays. Source preserves each multiplication/division/truncation step and repeated `m_currentFrame` load in observed order so negative-coordinate rounding and callback-visible state are not changed.
- Negative source contract is explicit: no rectangle read, fill, local clip, blend mutation, color/clip restoration, random call, frame advance, table write, object-state update, target/main-array alias, bounds check, or defensive singleton behavior may be introduced.
- The documentation filename's `DrawRainOnTarget` wording is retained for path stability only. Source, class declaration, vtable prose, and method definition use the base-contract spelling `DrawOnTarget`.
- Canonical WeatherLayerPane.h owns the class declaration and exact virtual prototype; the target child owns the qualified body. UID0000BJ remains a comment-plus-children router and UID0002Z8 remains compiler-generated marker support, so neither duplicates the body or hand-authors vtable data.

### Score And Generated Expectation

- File score moves `91/92 -> 92/93` because Rain constructor, OnPaint, and DrawOnTarget are now source-backed with exact layout, data, callback, clipping, and source-routing contracts. It remains below 95 because original private lexical spellings, exact historical disk split, complete generated header set, and rebuild/codegen identity remain unproved; incomplete Snow/Swallow children also prevent a whole-family final score.
- After scoped validation, generated `NexusTK/map/WeatherLayerPane.cpp` must contain exactly one UID0003PK qualified method body and zero UID0003PK empty-emitter markers. Generated output remains validator-owned and is inspected rather than edited.

## 2026-07-24 UID0003PG Constructor Source Closure

### Actual Weather Base Constructor

[UID:0003PG][0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor](by-memory/0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md) now emits the actual qualified `WeatherLayerPane::WeatherLayerPane()` definition through [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md) into this source-family root. Current live IDA session `supervisor_gate2b_0002OT_20260723` establishes exact range `[0x005c12a0,0x005c13a1)`, 257 bytes, target SHA256 `86BF00A162D9935D3FA52F922F1E862D93E040760746D83CC7C36CE5EB0B8E09`, a unique 16-byte prologue signature, and no VA/RVA target-start pointer. The only incoming code refs are Rain `0x005c141a`, Snow `0x005c1bfb`, and Swallow `0x005c225b` constructor calls.

Source behavior is complete:

1. construct the exact `0xf8` Pane base as `Pane(true)`;
2. let the compiler install Weather primary/EventHandler/TimerHandler vptr views at object `+0`, `+0xa0`, and `+0xa4`;
3. set `m_weatherBounds` to `(0,0,15*w,17*h)` for EPF assets or `(12,14,15*w+12,17*h+14)` for legacy assets;
4. set signed-byte `m_currentFrame`, signed-byte `m_frameCount`, and signed-short `m_timerInterval` to zero;
5. call inherited `ScheduleTimer(0, 0, 0, 0)` through the TimerHandler facet at `+0xa4`.

The source formal intentionally omits vptr writes, the returned `this`, MSVC exception-state/security-cookie scaffolding, the unwind cleanup funclet, raw offsets, and an explicit TimerHandler cast. It also avoids inventing a rectangle helper call not present in the body. The optimized dword zero at `+0xf8` remains represented by three source member assignments because UID0003PH and Rain consumers prove the byte/byte/short layout.

### File Route And Object Extent

Rain allocates exactly `0x10c` and adds no storage. Snow allocates `0x10ac` and Swallow `0x16c`; both start derived state at `+0x10c`. These facts independently confirm that the four Weather tail members end the complete object at `0x10c`. The constructor therefore belongs with the shared base class in the selected `NexusTK/map/WeatherLayerPane.cpp` family, not in a derived class or the non-emitting UID0001NZ migration index.

Historical separate `RainingLayerPane.cpp`, `SnowingLayerPane.cpp`, and `SwallowLayerPane.cpp` candidates remain preserved as physical-disk hypotheses because no PDB/source-path string proves the original split. They are not a current routing blocker: code, RTTI/vtables, rain/snow data, owner pages, and generated output converge on this file root. No UID0003PG source is duplicated in the class router, vtable page, aggregate, or support layouts.

### Generated And Header Contract

The pre-callback generated state contained one UID0003PG empty-emitter marker. After scoped validation, `NexusTK/map/WeatherLayerPane.cpp` must contain exactly one UID0003PG qualified constructor body and zero UID0003PG empty markers. Generated output remains validator-owned and must not be hand-edited.

Canonical `Pane.h` and `WeatherLayerPane.h` still supply complete declarations and inheritance. Their absence from current generated material is a project-header materialization dependency, not a reason to fabricate local class scaffolding or suppress exact method source. Historical UID0003PG state was `91/92`; later UID0003PK work raised the current page to `92/93`. UID0003PH keeps that current score unchanged. Original private spellings, physical disk split, missing generated headers, and absent rebuild/codegen comparison reserve final-audit score space without leaving a constructor or timer blocker.

## 2026-07-24 UID0003PH Shared Timer And Frame-Hook Source Closure

### Exact base callback source

[UID:0003PH][0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer](by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md) now emits exact `bool WeatherLayerPane::OnTimer(int timerId, int, int)` at source position `20`, after position-10 constructor UID0003PG. The 88-byte/SHA256-anchored body is entered through the inherited TimerHandler facet at complete object `+0xa4`; source remains class-owned and contains no explicit pointer adjustment.

Timer ID `0` performs signed `(m_currentFrame + 1) % m_frameCount`, calls `InvalidateRect(&m_visibleBounds)`, invokes inferred no-argument virtual `OnFrameChanged()`, and calls `ScheduleTimer(0, m_timerInterval, 0, 0)`. Every ID returns true; nonzero IDs do no state work and do not reschedule. The binary has no zero-count guard, so source must not add one.

The invalidated rectangle is inherited `m_visibleBounds` at complete `+0x44`, not Weather tail `m_weatherBounds` at `+0xfc`. Primary slot `+0x44` remains OnPaint; Weather adds frame hook `+0x4c`. Base/Rain/Swallow use the shared one-byte no-op, while Snow cell `0x006312fc` points to `0x005c1f50`. `OnFrameChanged` is the best source-facing name from this polymorphic role; exact original spelling/access remains a below-95 inference rather than an empty-source blocker.

### Concrete-family behavior

| Class | Timer route and state | Frame hook | File-level conclusion |
| --- | --- | --- | --- |
| Weather | `0x00631218 -> UID0003PH`; constructor queues ID 0 from temporary `0/0/0` base state | shared no-op | owns base callback/declaration |
| Rain | `0x006312a8 -> UID0003PH`; `0/3/120` | shared no-op | three-frame invalidation at 120 ms |
| Snow | `0x00631338 -> UID0003PH`; constructor tail `04 05 C8 00` means `4/5/200` | `0x006312fc -> UID0003O2` | frame transition drives 200-particle movement/refill |
| Swallow | `0x006313c8 -> 0x005c2500`; handles IDs `0x100/0x101` | shared no-op | replaces timer callback and never dispatches to UID0003PH |

The Weather constructor's zero-delay call queues rather than directly invokes ID 0. Concrete constructors install their vtables/state before dispatch; inherited TimerHandler teardown removes pending events. Compiler-generated deleting wrappers and adjustor thunks remain outside human source.

### Source route and history

Current operational route remains the one-file `NexusTK/map/WeatherLayerPane.cpp` family with canonical `WeatherLayerPane.h`; exact class pages retain direct semantic ownership. Independent contiguous code, RTTI/vtables, static weather data, and current emitter routing support that selection. Historical dedicated Rain/Snow/Swallow files remain recorded as physical-disk hypotheses because no PDB/source path proves the original split, but they are not active blockers and do not justify moving UID0003PH.

The Weather class page remains a comment-plus-children router. UID0003PG and UID0003PH own qualified definitions; UID0002Z7 and sibling vtable pages describe source-declared/generated-binary data without emitting hand-authored arrays. UID0003O2 remains a separate Snow method with blank formal until its own particle-body blockers close; this pass adds its exact `OnFrameChanged` virtual role/call origin without absorbing that body.

## 2026-07-24 UID0003PI Rain Constructor Source Closure

### Exact Child And Construction Route

- [UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md) now emits exact qualified `RainingLayerPane::RainingLayerPane()` source through [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md) into this canonical `NexusTK/map/WeatherLayerPane.cpp` family.
- The child is one unique 74-byte body at `[0x005c1410,0x005c145a)`, SHA256 `B302EDA90BEA72A3FA45D2C16C9C6059B3ECE41F29FAFA5024A85986D56BB29E`, PE RVA `0x001c1410`, and raw offset `0x001c0810`. Eight preceding and six trailing `0xcc` bytes preserve exact separation from the Weather timer and Rain OnPaint children.
- Its sole call at `0x0050dc3b` is inside MapPane weather setup. That caller allocates exactly `0x10c`, invokes Rain construction, stores the returned object at MapPane `+0x414`, and owns its EH cleanup. UID0003PI itself calls only `WeatherLayerPane::WeatherLayerPane` at `0x005c12a0` and adds no Rain-specific storage or target-local cleanup.

### Human Source And Compiler Boundary

- After implicit base construction, the human source body is exactly `m_timerInterval = 120`, `m_frameCount = 3`, and `m_drawOnTarget = true`. The accepted order follows the source-level field roles while preserving the observed resulting state; no raw offsets, manual returned `this`, EH scaffolding, or explicit base call is added.
- Stores to Rain primary/adjusted vtable views `0x00631220`, `0x00631274`, and `0x006312a4` are compiler-generated multiple-inheritance mechanics. They remain documented by [UID:0002Z8][0x0063121c-0x006312ac.RainingLayerPaneVtableData](by-memory/0x0063121c-0x006312ac.RainingLayerPaneVtableData.md), not handwritten in this file's constructor.
- Pane `+0xf6` is inherited direct-target paint mode. Rain writes it at `0x005c144e`, Snow at `0x005c1c63`, and Swallow at `0x005c2327`; `Layer_UpdateDirtyRegionsRecursive` reads it at `0x004f16b2`, dispatching primary virtual `OnPaint` when zero and bypassing generic paint when nonzero. Separate Pane visibility is at `+0xb4`.
- `m_drawOnTarget` is the preferred source-facing name and `m_usesDirectTargetDrawing` is a descriptive alias. Historical enabled/visibility/reserved/readiness, negative `m_skipOnPaint`, and raw `field_F6` names are preserved only as disproved or superseded assumptions.

### Route, Duplication, And Generated Expectation

- [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md) remains the semantic class owner and this page remains the selected file root. [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md) retains the historical dedicated-file hypothesis but does not emit a duplicate constructor. The aggregate, vtable, and layout pages record support evidence only.
- No split, merge, range, padding-owner, or source-family change is needed. Exact children remain ordered Weather constructor, Weather timer, Rain constructor, Rain OnPaint, and Rain DrawOnTarget.
- After scoped validation, validator-owned `NexusTK/map/WeatherLayerPane.cpp` is expected to contain exactly one UID0003PI qualified constructor body and no UID0003PI empty-emitter marker. Generated output is inspected, never edited directly.
- This historical UID0003PI callback kept the then-current `92/93`. UID0001OO subsequently closes the whole-family snow static declarations and raises the current file to `93/94`; original lexical spellings, historical disk split, canonical generated headers, and whole-program rebuild/codegen identity still reserve final-audit score space.

## Changes

- 2026-07-26 B002 UID0001OO source-family callback:
  - Raised `92/93` to `93/94`, retained `NexusTK/map/` and `CANONICAL_OWNER:FILE`, and installed UID0001OO as the exact position-1 snow data emitter after UID0001ON position 0.
  - Added all six writable snow declarations, exact 80-byte extent, target/main consumers, physical duplication/hashes, no-header/no-duplicate policy, and corrected the historical UID0000NR and false-padding routes.
  - Preserved concrete class ownership and the historical per-layer disk split; this change closes static-data source placement without moving or duplicating method bodies.
- 2026-07-24 Agent-B005 UID0003O0 source-family callback:
  - Kept `92/93`, `NexusTK/map/`, `CANONICAL_OWNER:FILE`, and the selected one-file source/header route.
  - Added the exact Snow constructor child, `0x10ac` object extent, `0x10c` Weather prefix, inline 200-record particle layout, inherited `4/5/200` and direct-target state, helper/padding/compiler boundary, dependency order, and no-duplicate-body policy.
  - Historicalized the dedicated Snow file and older unnamed-field/file-route blockers while preserving UID0003O2's separately owned formal and remaining method-specific questions.
- 2026-07-24 B003 UID0003PI implementation callback:
  - Kept current `92/93`, `NexusTK/map/`, `CANONICAL_OWNER:FILE`, and the selected one-file Weather source-family route.
  - Added the exact 74-byte Rain constructor identity and sole MapPane route, exact source assignments, inherited direct-target mode proof and naming, no-added-storage boundary, compiler-only vptr/EH separation, one-body/no-empty-marker expectation, and historical dedicated-file/no-duplicate handling.

- 2026-07-24 B002 UID0003PH source-quality callback:
  - Kept current `92/93`, `NexusTK/map/`, and `CANONICAL_OWNER:FILE` unchanged.
  - Added exact shared `OnTimer` source, adjusted TimerHandler ABI, signed fields, visible-bounds invalidation, inferred `OnFrameChanged` hook, Rain/Snow/Swallow dispatch matrix, timer lifecycle, position-10/20 order, and selected source/header route while preserving separate-body and historical split boundaries.
- 2026-07-24 B005 UID0003PK implementation callback:
  - Changed `91/92 -> 92/93`; retained `NexusTK/map/`, `CANONICAL_OWNER:FILE`, and the one-file Weather source-family route.
  - Replaced the stale UID0003PK blank-formal checkpoint with exact virtual contract, caller-managed clipping, 18/7/7 target-array rendering, signed/operation-order constraints, negative behavior, source/header placement, stable-path method-name history, and one-body/zero-empty generated expectation.
- 2026-07-24 B001 UID0003PG source-quality callback:
  - Score/path/owner route unchanged at `91/92`, `NexusTK/map/`, and `FILE`.
  - Added actual Weather base constructor source, exact bytes/hash/callers, Pane/vtable/timer behavior, EPF/legacy bounds, object-extent proof, source-shape exclusions, generated-output expectation, and complete header/file-route rationale.
  - Preserved historical physical split hypotheses and the no-duplicate-vtable/compiler-source policy while rejecting their use as a current empty-emitter blocker.

- 2026-07-23 B002 UID0002XW source-quality callback:
  - Score, source-family route, projected path, class/global/type inventory, and all existing method formals unchanged.
  - Added equal Weather/Rain compiler-consumer evidence, exact primary/adjusted cells, no-weather-state proof, bit-4 no-op correction, implicit-destructor source shape, and explicit exclusion of UID0002XW/UID0002XV from emitted Weather source.
- 2026-07-22 B005 RainCoordinateTables source-family callback:
  - Changed `88/86 -> 90/90`.
  - Selected the current one-file `WeatherLayerPane.cpp` family from independent code, RTTI/vtable, rain/snow data, and existing route clustering while preserving separate layer files as historical/secondary hypotheses rather than deleting them.
  - Added the exact UID0001ON signed-short types, six writable internal arrays, target-port/main-view consumer split, pairwise physical duplication, alignment-gap behavior, and position-0 route without changing the direct semantic owners of concrete class methods.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents the weather-layer source family, map ownership, class/memory/global/type refs, IDA checks, and generated-output caveats; final one-file versus split-file layout remains unresolved.
- 2026-06-02 source-path update: `PROPOSED_RECONSTRUCTION_PATH` set to `NexusTK/map/`, matching the proposed source tree and current ownership decision that weather overlays are map-state companions rather than generic render code.
- 2026-06-13 Agent-A001 Goal 2 refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:80`.
  - After: `COMPLETION:88`, `CONFIDENCE:86`.
  - Summary/evidence: incorporated current exact Snowing child/range repair, live IDA function-size refresh for the base/rain/snow starts, and clarified that the WeatherLayerPane file root is the source-family anchor while exact concrete-source migration remains split-file open.
- 2026-06-16 B001 child-split link update:
  - Metadata unchanged.
  - Summary/evidence: added exact Weather/Rain child pages [UID:0003PG][0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor](by-memory/0x005c12a0-0x005c13a1.WeatherLayerPaneConstructor.md), [UID:0003PH][0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer](by-memory/0x005c13b0-0x005c1408.WeatherLayerPaneOnTimer.md), [UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md), [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md), and [UID:0003PK][0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget](by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md) beside the [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md) migration index while preserving the one-file versus per-layer caveat.
- 2026-06-17 B002 Swallow support sync:
  - Metadata unchanged.
  - Summary/evidence: synced [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md)'s corrected `0x005c299f` end and added [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md) as the adjacent no-xref Swallow raw rect helper while preserving the weather-family source-placement caveat.
- 2026-06-23 B002 Swallow raw-rect MCP-backed endpoint correction:
  - Metadata unchanged.
  - Summary/evidence: corrected [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md) to `0x005c29a0-0x005c29ec` and preserved this page as the source-family route only. Accepted MCP session `0b5e057e` shows the stale `0x005c29ea` endpoint cut through the `retn 4` instruction, with Snowing thunk code starting at `0x005c29ec`; target decompile fails, no xref/pointer/vtable route reaches `0x005c29a0`, and `0x00631304 -> 0x005c29ec` is Snowing thunk data. The helper remains direct Swallow code, not base WeatherLayerPane; no first-draft C++ is emitted because caller/pointer/table/vtable/source route, exact type, and final file split are still unresolved.
- 2026-06-23 B003 Snowing randomize MCP-backed source-family sync:
  - Metadata unchanged.
  - Summary/evidence: recorded [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md)'s accepted MCP session `b880584f` evidence and accepted route through the WeatherLayerPane source family, while rejecting a forced dedicated SnowingLayerPane file move until source-path/file-split proof exists.
- 2026-06-27 B011 Swallow raw flight-helper marker sync:
  - Metadata unchanged.
  - Summary/evidence: synced [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md)'s accepted formal no-code marker and no-split disposition. The raw helper pair remains concrete Swallow-owned evidence under the weather-layer source family, not base WeatherLayerPane methods; live behavior is covered by [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md) `OnTimerEvent`, and no standalone `StartSwallowFlight`/`StepSwallowFlight` bodies are emitted without future route proof.
- 2026-07-01 B008 WeatherLayerPane empty-emitter family callback:
  - Metadata unchanged.
  - Summary/evidence: added the generated-output audit baseline for `auto-generated/NexusTK/map/WeatherLayerPane.cpp` command `000000003290` refreshed `2026-07-01T04:46:53-04:00` with `15` emitters, `1` filled, `14` empty, `6.7%` filled, and `0` reports; preserved this page as the source-file route while direct method owners remain the four weather-layer classes; recorded the accepted broad marker policy for class/vtable/aggregate/global/type support; and recorded that [UID:0003O1][0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles](by-memory/0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles.md) and [UID:0003O3][0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles](by-memory/0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles.md) now emit first-draft Snowing method bodies while [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md) remains excluded from this callback.
- 2026-07-05 B004 UID0002Z7 generated-state sync:
  - Metadata unchanged.
  - Summary/evidence: recorded that generated coverage routes UID0002Z7 as coded to `WeatherLayerPane.cpp`, while the pre-callback generated source lacked the UID0002Z7 marker until [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md)'s child-insertion route was repaired. The expected generated output after validation is a UID0002Z7 marker through the class child route and no raw C++ vtable array/body.
