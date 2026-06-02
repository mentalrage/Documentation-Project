*** UID:0000P8 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# WeatherLayerPane

## Status

- Confidence: strong for base/weather-layer behavior, medium for final file split.
- Proposed module folder: `map/`
- Candidate files: `map/WeatherLayerPane.cpp`, `map/RainingLayerPane.cpp`, `map/SnowingLayerPane.cpp`, and `map/SwallowLayerPane.cpp`
- Current recovered sources: `class_WeatherLayerPane.cpp`, `class_RainingLayerPane.cpp`, `class_SnowingLayerPane.cpp`, and `class_SwallowLayerPane.cpp`
- Main memory docs: [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md), [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md), [UID:0001O0][0x005c1bd0-0x005c2a5a.SnowingLayerPane](by-memory/0x005c1bd0-0x005c2a5a.SnowingLayerPane.md), and [UID:0001O2][0x005c2230-0x005c299e.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299e.SwallowLayerPaneCore.md)
- Shared globals/types: [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md) and [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md)

## File Role

The weather layer sources own map-overlay effects created by `MapPane` when the server/weather state changes. `WeatherLayerPane` is the base pane that computes effect bounds and advances an animation timer. `RainingLayerPane`, `SnowingLayerPane`, and `SwallowLayerPane` provide concrete overlay drawing.

The original project may have used one source per concrete layer because Wave2 import provenance names separate `WeatherLayerPane.cpp`, `RainingLayerPane.cpp`, `SnowingLayerPane.cpp`, and `SwallowLayerPane.cpp`. A compact source layout could also have kept the base plus effects in one `WeatherLayerPane.cpp`. Treat the current docs as a weather-layer source family until final migration decides the split.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `WeatherLayerPane` | `0x005c12a0-0x005c1407` | Base map weather overlay pane, effect dimensions, animation timer advance. |
| `RainingLayerPane` | `0x005c1410-0x005c1bc7` | Rain streak/splash overlay and secondary target draw path. |
| `SnowingLayerPane` | `0x005c1bd0-0x005c2227`, plus thunks/destructor at `0x005c29ec-0x005c2a5a` | Snow particle overlay, lookup initialization, randomization, and particle rendering. |
| `SwallowLayerPane` | `0x005c2230-0x005c299e`, plus destructor support at `0x005c2a02-0x005c2ab5` | Timed sprite flight overlay using `SWALLOW.EPF`/`SWALLOW.EPD`. |
| weather static data | [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md), [UID:0001OO][0x00670784-0x006707d0.SnowPatternByteTables](by-memory/0x00670784-0x006707d0.SnowPatternByteTables.md), [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md) | Static coordinate, particle, descriptor, and callback dependencies used by the weather-layer family. |

## Ownership Notes

- `MapPane::SetWeatherEffect`/weather-state logic at `0x0050db50` allocates one of the weather layers and attaches it to the map pane. IDA confirms direct constructor calls to `RainingLayerPane`, `SnowingLayerPane`, and `SwallowLayerPane` from that function.
- 2026-06-02 IDA recheck confirms `0x0050db50` as a modeled function start, confirms `WeatherLayerPane::WeatherLayerPane` at `0x005c12a0` is called by the rain/snow/swallow constructors, and shows `WeatherLayerPane::OnTimerEvent` at `0x005c13b0` referenced from the rain/snow/swallow vtables at `0x00631218`, `0x006312a8`, and `0x00631338`.
- Keep these classes under `map/`, not generic render, unless later evidence proves the original project grouped weather effects with render effects. The owning lifetime and construction path are map-state driven.
- [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md) already has a dedicated source candidate. Use this page as the broader source-family and base-class anchor.
- `SwallowLayerPane` current generated output now emits the real `0x005c2340` destructor and `0x005c2930` invalidation helper, but [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md) at `0x005c2760` and `0x005c2840` are still mis-owned by generated `BackPane` output and have no IDA function objects/xrefs.
- Use the [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md) for migration boundaries. The older Snowing aggregate filename crosses Swallow code beginning at `0x005c2230`.
- Generated `g_pWeatherState` in rain/snow output is an alias for [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) at `0x0067a764`, not a separate weather singleton. Weather drawing checks byte `g_activeMapPane + 0x3f0` before rendering.
- Current `source-3/simroot_v2/class_WeatherLayerPane.cpp` still duplicates marker-only `global-data` rows for `g_tileColumns` and `g_tileRows`; treat those duplicate comments as generated-output noise, not as separate storage records.

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
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- [UID:0001O2][0x005c2230-0x005c299e.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299e.SwallowLayerPaneCore.md)
- [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md)
- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `86/80`. Summary/evidence: the page documents the weather-layer source family, map ownership, class/memory/global/type refs, IDA checks, and generated-output caveats; final one-file versus split-file layout remains unresolved.
- 2026-06-02 source-path update: `PROPOSED_RECONSTRUCTION_PATH` set to `NexusTK/map/`, matching the proposed source tree and current ownership decision that weather overlays are map-state companions rather than generic render code.
