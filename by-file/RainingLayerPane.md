*** UID:0000MY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:76 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# RainingLayerPane

## Status

- Confidence: strong for class behavior and boundaries, medium for final file split.
- Proposed module: `map/RainingLayerPane.cpp` or part of [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- Current recovered source: `source-3/simroot_v2/class_RainingLayerPane.cpp`
- Main memory range: [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md)

## File Role

`RainingLayerPane` is the rain weather overlay for the map pane. It derives from `WeatherLayerPane`, configures a 120-frame rain animation, and draws rain streaks plus small/large splash marks from precomputed coordinate tables. It also supports drawing the same rain pattern onto a supplied `GrafPort`, likely for secondary map/minimap-style targets.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `RainingLayerPane` | `0x005c1410-0x005c1bc7` | Rain constructor, map overlay paint, and target-port rain draw. |
| rain coordinate globals | [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md) | Rain streak, small splash, large splash, and target/minimap variants; see [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md). |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x005c1410-0x005c1459` | constructor | Calls `WeatherLayerPane`, installs rain vtables, sets 120 max frames, step `3`, and enabled flag. |
| `0x005c1460-0x005c180b` | `OnPaint` | Draws main-view rain streaks and splash dots using tables starting at `0x00670528`, `0x006706d8`, and `0x00670730`. |
| `0x005c1810-0x005c1bc7` | `DrawRainOnTarget` | Draws the same rain/splash pattern onto a supplied `GrafPort` using target/minimap tables at `0x006702c8`, `0x00670478`, and `0x006704d0`. |

## Ownership Notes

- `MapPane` weather setup allocates 268 bytes and calls this constructor when the weather type selects rain.
- The class shares the exact base object size with `WeatherLayerPane` in current metadata, suggesting no extra per-instance fields beyond base animation state.
- Current metadata reports a stored method-name control-character artifact for the constructor. Treat that as a data cleanup issue, not a source-layout signal.
- Current generated `g_pWeatherState` is a misleading alias for [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) at `0x0067a764`; rain drawing checks byte `+0x3f0` before drawing.
- 2026-05-24 IDA recheck: `0x005c1410` is called by `MapPane::SetMapState` at `0x0050dc3b`; `0x005c1460` is referenced from vtable data at `0x00631264`; `0x005c1810` is referenced from vtable data at `0x00631230`.
- Current `source-3/simroot_v2/class_RainingLayerPane.cpp` still duplicates marker-only `global-data` rows for all rain coordinate tables and for `g_pWeatherState`. Do not interpret duplicate marker comments as multiple globals.

## Cross-References

- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md)
- [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md)
- [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `78`, confidence `76`.
- Summary/evidence: the page documents rain overlay role, function map, coordinate globals, MapPane constructor evidence, generated-alias caveats, and cross-references; completion remains moderate because final split from the weather-layer umbrella and raw coordinate table detail need more work.
