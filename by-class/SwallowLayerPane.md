*** UID:0000E9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SwallowLayerPane

## Status

- Confidence: strong for behavior and IDA boundaries; current generated output is incomplete.
- Likely source file: [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md), or part of [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- Main address docs: [UID:0001O2][0x005c2230-0x005c299e.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299e.SwallowLayerPaneCore.md), [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md), and [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- Current recovered file: `source-3/simroot_v2/class_SwallowLayerPane.cpp`

## Class Purpose

`SwallowLayerPane` is a `WeatherLayerPane` derivative that periodically moves a two-frame sprite across the map view. It uses two loaded `SWALLOW` frames, a current position, active flag, direction field, and timers for flight start and step behavior.

## Method Map

| Range | Method | Role |
| --- | --- | --- |
| `0x005c2230-0x005c233f` | constructor | Loads frames, initializes flight state, and schedules first start timer. |
| `0x005c2340-0x005c235e` | destructor | Non-deleting destructor currently emitted by active simroot output. |
| `0x005c2360-0x005c2422` | `OnPaint` | Clears/refreshes and paints active sprite. |
| `0x005c2430-0x005c24f9` | `MoveBy` | Invalidates old/new rectangles and changes position. |
| `0x005c2500-0x005c26a5` | `OnTimerEvent` | Starts and steps timed sprite flight. |
| `0x005c26b0-0x005c275b` | `DrawSwallow` | Draws the active sprite. |
| `0x005c2760-0x005c2835` | raw start-flight helper | Function-shaped code bytes with no IDA function object or xrefs; belongs with Swallow if retained. |
| `0x005c2840-0x005c292e` | raw step-flight helper | Function-shaped code bytes with no IDA function object or xrefs; calls `0x005c2930` from raw code. |
| `0x005c2930-0x005c299e` | current-rect invalidation helper | Real IDA function; current simroot emits it under `SwallowLayerPane`. |
| `0x005c2a02-0x005c2a17` | thunks | Adjustor thunk support. |
| `0x005c2a60-0x005c2ab5` | scalar deleting destructor | Deleting-destructor wrapper. |

## Data Caveats

Generated metadata includes a bad/excluded method row at `0x00570053`; IDA places that address inside `0x00570030`, not at a function start, and the decompiled behavior is not this class. Current simroot now emits real helpers at `0x005c2340` and `0x005c2930`, but `class_BackPane.cpp` still mis-owns the raw flight helpers at `0x005c2760` and `0x005c2840`. The destructor tail is interleaved with [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md), so use the shared island for per-method migration.

2026-05-24 recheck: MCP still reports `0x005c2760` and `0x005c2840` as `Not a function`, while modeled Swallow starts and vtable refs remain stable. Constructor call-in is from `MapPane::SetMapState` at `0x0050dbf3`; vtable data refs cover `OnPaint`, `MoveBy`, `OnTimerEvent`, `DrawSwallow`, and the scalar deleting destructor.

## Cross-References

- [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md)
- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- [UID:0001O2][0x005c2230-0x005c299e.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299e.SwallowLayerPaneCore.md)
- [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `80`.
- Evidence: the page documents the weather-layer behavior, method map, raw helper caveats, generated misownership, constructor call-in, vtable refs, and shared destructor island; confidence remains capped by raw flight helpers that IDA still does not model as functions.
- 2026-06-02 reconstruction metadata:
  - Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), the current weather-layer source-family parent. C++ remains blank because raw flight-helper ownership/liveness needs more work and the class is below the 95+ final-source threshold.
