*** UID:0000BJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# RainingLayerPane

## Status

- Confidence: very strong for behavior, constructor caller, vtable stores, and rain render table ownership.
- Likely source file: [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md), or part of [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- Main address range: [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md)
- Current recovered file: `source-3/simroot_v2/class_RainingLayerPane.cpp`

## Class Purpose

`RainingLayerPane` is a `WeatherLayerPane` derivative that renders animated rain over the map view. It uses global coordinate tables for 18 streaks, 7 small splashes, and 7 large splashes per rendered frame.
The exact table block is documented at [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md).

## Method Map

| Range | Method | Role |
| --- | --- | --- |
| `0x005c1410-0x005c1459` | constructor | Calls `WeatherLayerPane` and configures rain animation state. |
| `0x005c1460-0x005c180b` | `OnPaint` | Draws rain streaks and splash patterns on the pane using main-view tables at `0x00670528`, `0x006706d8`, and `0x00670730`. |
| `0x005c1810-0x005c1bc7` | `DrawRainOnTarget` | Draws the rain pattern onto a supplied target graphics port using alternate tables at `0x006702c8`, `0x00670478`, and `0x006704d0`. |

## Key Relationships

- Derived from [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md).
- Constructed by [UID:0000L3][MapPane](by-file/MapPane.md) weather setup.
- Neighboring concrete weather overlays are [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md) and [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md).
- Generated `g_pWeatherState` is a stale alias for [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md); rain rendering checks byte `+0x3f0` on that active map pane.
- 2026-05-24 recheck: IDA caller data ties the constructor call to `MapPane::SetMapState` at `0x0050dc3b`; vtable refs point at `OnPaint` (`0x00631264`) and `DrawRainOnTarget` (`0x00631230`). Current generated output still duplicates marker-only rows for every rain table and `g_pWeatherState`.

## 2026-06-10 Parent-Gate Evidence

B001-037 live IDA MCP reconfirmed the constructor `sub_5C1410` as `0x005c1410-0x005c145a`, `OnPaint` as `0x005c1460-0x005c180c`, and `DrawRainOnTarget` as `0x005c1810-0x005c1bc7`. The constructor is called from `MapPane::SetMapState` at `0x0050dc3b`, calls the base weather constructor at `0x005c141a`, and stores the rain vtable views at `0x00631220`, `0x00631274`, and `0x006312a4` from `0x005c1424`, `0x005c1433`, and `0x005c143d`. Vtable slots point to the rain render bodies at `0x00631264 -> 0x005c1460` and `0x00631230 -> 0x005c1810`.

This raises the class page above the strict `85/85` direct-parent gate for the exact `RainingLayerPane` vtable-data child. C++ remains blank because final source organization between a standalone `RainingLayerPane.cpp` and the broader weather source family is still open.

## Cross-References

- [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md)
- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md)
- [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md)

## Changes

- 2026-05-30: Changed completion/confidence from `0/0` to `82/86`.
  - Before: The page was unevaluated despite documenting constructor, two rain-rendering paths, coordinate tables, relationships, and stale alias caveats.
  - After: Scored as high completion and strong confidence for the rain weather overlay.
  - Evidence: Existing method map, key relationships, IDA caller/vtable notes, and rain-table cross-references document behavior and boundaries.
- 2026-06-02 reconstruction metadata:
  - Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), the current weather-layer source-family parent. C++ remains blank because this page is below the 95+ final-source threshold and final separate-file ownership is still being tracked.
- 2026-06-10 B001-037 parent-gate refresh:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`; parent unchanged.
  - Summary/evidence: live IDA MCP reconfirmed the constructor, paint, and target-draw ranges, `MapPane` weather-setup caller, base-constructor call, rain vtable stores, and rain render vtable slots. The class now clears the direct-parent gate for exact rain vtable data.
