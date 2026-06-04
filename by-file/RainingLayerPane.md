*** UID:0000MY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# RainingLayerPane

## Status

- Confidence: strong for class behavior, map/weather ownership, live function boundaries, vtable refs, and rain-table refs; medium-high for final separate-file versus weather-family split.
- Proposed module folder: `NexusTK/map/`
- Candidate file: `map/RainingLayerPane.cpp`, while [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) remains the weather-layer source-family parent until final split evidence is stronger.
- Main memory range: [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md)
- Evidence basis: live IDA MCP function, caller, vtable, disassembly, and data-ref checks through 2026-06-04.

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
| `0x005c1410-0x005c145a` | constructor | Calls `WeatherLayerPane`, installs rain vtables, sets 120 max frames, step `3`, and enabled flag. |
| `0x005c1460-0x005c180c` | `OnPaint` | Draws main-view rain streaks and splash dots using tables starting at `0x00670528`, `0x006706d8`, and `0x00670730`. |
| `0x005c1810-0x005c1bc7` | `DrawRainOnTarget` | Draws the same rain/splash pattern onto a supplied `GrafPort` using target/minimap tables at `0x006702c8`, `0x00670478`, and `0x006704d0`. |

## Ownership Notes

- `MapPane` weather setup at `0x0050db50-0x0050dcb3` allocates `0x10c` bytes and calls this constructor at `0x0050dc3b` when the weather type selects rain. The same setup function constructs sibling snow (`0x005c1bd0`) and swallow (`0x005c2230`) panes, keeping the family under map/weather ownership.
- The class shares the exact base object size with `WeatherLayerPane` in current metadata, suggesting no extra per-instance fields beyond base animation state.
- Live IDA reports `0x005c1410-0x005c145a`, `0x005c1460-0x005c180c`, and `0x005c1810-0x005c1bc7` as the exact rain constructor, main paint path, and target-port draw path.
- `RainingLayerPane` vtable data is anchored at `0x00631220`; constructor stores are at `0x005c1424` and `0x005c1433`. The target-port draw slot points to `0x005c1810` at `0x00631230`, and the paint slot points to `0x005c1460` at `0x00631264`.
- Main-view rain table refs are `0x00670528 -> 0x005c14d3`, `0x006706d8 -> 0x005c15ad/0x005c1617`, and `0x00670730 -> 0x005c168d/0x005c16f7/0x005c1761/0x005c17ce`.
- Target/minimap rain table refs are `0x006702c8 -> 0x005c1877`, `0x00670478 -> 0x005c1950/0x005c19bd`, and `0x006704d0 -> 0x005c1a3a/0x005c1aa5/0x005c1b10/0x005c1b7e`.
- Legacy alias metadata for `g_pWeatherState` refers to [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) at `0x0067a764`; rain drawing checks byte `+0x3f0` before drawing, with current refs at `0x005c1476` and `0x005c1814`.
- Project-structure guidance already places `RainingLayerPane.cpp` under `map/`, matching the live constructor ownership path through [UID:0000L3][MapPane](by-file/MapPane.md).

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
- Summary/evidence: the page documents rain overlay role, function map, coordinate globals, MapPane constructor evidence, legacy-alias caveats, and cross-references; completion remains moderate because final split from the weather-layer umbrella and raw coordinate table detail need more work.
- 2026-06-04 live IDA and source-path update:
  - What existed before: `COMPLETION:78`, `CONFIDENCE:76`, and a blank `PROPOSED_RECONSTRUCTION_PATH`, with older boundary rows and source-output caveats.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:84`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`.
  - Summary/evidence: live IDA confirms exact half-open method ranges, the sole rain constructor call from `MapPane` weather setup, `RainingLayerPane` vtable anchors and slots, main/target rain table refs, active-map-pane weather-state checks, and project-structure placement under `map/`. Final C++ remains blank because the standalone-file versus weather-family split is still below the `95/95` reconstruction bar.
