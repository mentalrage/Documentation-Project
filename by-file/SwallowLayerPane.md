*** UID:0000OD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SwallowLayerPane

## Status

- Confidence: strong for map-weather overlay behavior, medium for current generated data completeness.
- Proposed module: `map/SwallowLayerPane.cpp` or part of [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- Current recovered source: `source-3/simroot_v2/class_SwallowLayerPane.cpp`
- Main memory docs: [UID:0001O2][0x005c2230-0x005c299e.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299e.SwallowLayerPaneCore.md), [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md), and [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)

## File Role

`SwallowLayerPane` is a timed map-weather overlay that loads two `SWALLOW` frames and periodically moves a sprite across the map view. It derives from `WeatherLayerPane`, stores active flight state, direction, position, and two `EPFImage` frame records, and uses timer messages `0x100` and `0x101` to start and step flights.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `SwallowLayerPane` | `0x005c2230-0x005c299e`, `0x005c2a02-0x005c2ab5` | Constructor, paint/move/timer/draw helpers, raw orphan flight helpers, invalidation helper, destructor/thunk support. |
| `SWALLOW.EPF` / `SWALLOW.EPD` resources | constructor strings and `g_useEpfAssets` branch | Right/left sprite frames for the overlay. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x005c2230-0x005c233f` | constructor | Calls `WeatherLayerPane`, initializes flight state, loads two `SWALLOW` frames, and schedules the first start timer. |
| `0x005c2340-0x005c235e` | non-deleting destructor | IDA-confirmed real function; current simroot emits it under `SwallowLayerPane`. |
| `0x005c2360-0x005c2422` | `OnPaint` | Clears/refreshes the pane region and draws the current sprite when active. |
| `0x005c2430-0x005c24f9` | `MoveBy` | Invalidates old and new sprite rectangles while adjusting position. |
| `0x005c2500-0x005c26a5` | `OnTimerEvent` | Starts a flight, steps position by 10 pixels, and schedules the next step or random restart delay. |
| `0x005c26b0-0x005c275b` | `DrawSwallow` | Draws the active sprite without the full paint clear path. |
| `0x005c2760-0x005c2835` | raw start-flight helper | IDA has code bytes but no function object and no xrefs; generated BackPane ownership is wrong. |
| `0x005c2840-0x005c292e` | raw step-flight helper | IDA has code bytes but no function object and no xrefs; calls `0x005c2930` from raw code at `0x005c291d`. |
| `0x005c2930-0x005c299e` | current-rect invalidation helper | IDA-confirmed helper; current simroot emits it under `SwallowLayerPane`. |
| `0x005c2a02-0x005c2a17` | adjustor thunks | Real thunk starts; `0x005c2a0d` is missing from disabled generated output. |
| `0x005c2a60-0x005c2ab5` | scalar deleting destructor | Resets vtables, tears down base pane state, and conditionally deletes storage. |

## Current Data Caveats

- Current `source-3/simroot_v2/class_SwallowLayerPane.cpp` now emits the real non-deleting destructor at `0x005c2340` and helper at `0x005c2930`; older notes that called those omitted are stale.
- Active `source-3/simroot_v2/class_BackPane.cpp` still emits `0x005c2760` and `0x005c2840` as BackPane scroll-animation methods. IDA raw disassembly and field usage tie them to `SwallowLayerPane`, not `BackPane`.
- 2026-05-24 MCP recheck still reports `0x005c2760` and `0x005c2840` as `Not a function`. Keep them as raw/orphan Swallow helper bodies unless later boundary recovery creates function objects or xrefs.
- 2026-05-24 IDA recheck ties `SwallowLayerPane` construction to `MapPane::SetMapState` at `0x0050dbf3`; vtable refs point at `OnPaint` (`0x00631384`), `MoveBy` (`0x00631388`), `OnTimerEvent` (`0x006313c8`), `DrawSwallow` (`0x00631350`), and the scalar deleting destructor (`0x00631340`).
- The adjacent destructor tail is interleaved with [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md): Snowing owns `0x005c29ec`, `0x005c29f7`, and `0x005c2a20`, while Swallow owns `0x005c2a02`, `0x005c2a0d`, and `0x005c2a60`.
- The generated method row at `0x00570053` is not an IDA function start. IDA resolves that address inside `0x00570030`, whose decompilation is unrelated `SelfLookPane2`-style destructor code.
- Disabled generated output marks `0x005c2a0d` as missing code even though IDA confirms it is a real `0xb` thunk.

## Cross-References

- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md)
- [UID:0001O2][0x005c2230-0x005c299e.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299e.SwallowLayerPaneCore.md)
- [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000J3][EPFImageResources](by-file/EPFImageResources.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `78`.
  - Evidence: document captures weather-overlay role, proposed contents, function map, raw helper caveats, construction/vtable evidence, Snowing/Swallow destructor boundary, and cross-references; confidence is capped by generated data completeness and final standalone-vs-weather source split.
- 2026-06-02 source-path update:
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`.
  - Evidence: current project-structure guidance groups `WeatherLayerPane`, `RainingLayerPane`, `SnowingLayerPane`, and `SwallowLayerPane` as map UI/weather companions under `map/`; the Swallow constructor is reached from `MapPane` weather setup and owns map overlay sprite/timer behavior.
