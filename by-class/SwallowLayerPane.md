*** UID:0000E9 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SwallowLayerPane

## Status

- Confidence: very strong for modeled behavior, IDA boundaries, vtable/resource evidence, and Swallow class ownership; raw helper liveness remains incomplete.
- Likely source file: [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md), or part of [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- Main address docs: [UID:0001O2][0x005c2230-0x005c299e.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299e.SwallowLayerPaneCore.md), [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md), and [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- Documentation basis: IDA-confirmed modeled methods, raw flight-helper byte reviews, vtable references, constructor caller evidence, and linked by-memory weather-layer pages.

## Class Purpose

`SwallowLayerPane` is a `WeatherLayerPane` derivative that periodically moves a two-frame sprite across the map view. It uses two loaded `SWALLOW` frames, a current position, active flag, direction field, and timers for flight start and step behavior.

## Method Map

| Range | Method | Role |
| --- | --- | --- |
| `0x005c2230-0x005c233f` | constructor | Loads frames, initializes flight state, and schedules first start timer. |
| `0x005c2340-0x005c235e` | destructor | Non-deleting destructor documented with the class core. |
| `0x005c2360-0x005c2422` | `OnPaint` | Clears/refreshes and paints active sprite. |
| `0x005c2430-0x005c24f9` | `MoveBy` | Invalidates old/new rectangles and changes position. |
| `0x005c2500-0x005c26a5` | `OnTimerEvent` | Starts and steps timed sprite flight. |
| `0x005c26b0-0x005c275b` | `DrawSwallow` | Draws the active sprite. |
| `0x005c2760-0x005c2835` | raw start-flight helper | Function-shaped code bytes with no IDA function object or xrefs; belongs with Swallow if retained. |
| `0x005c2840-0x005c292e` | raw step-flight helper | Function-shaped code bytes with no IDA function object or xrefs; calls `0x005c2930` from raw code. |
| `0x005c2930-0x005c299e` | current-rect invalidation helper | Real IDA function owned by the Swallow class core. |
| `0x005c2a02-0x005c2a17` | thunks | Adjustor thunk support. |
| `0x005c2a60-0x005c2ab5` | scalar deleting destructor | Deleting-destructor wrapper. |

## Data Caveats

Recovered metadata includes a bad/excluded method row at `0x00570053`; IDA places that address inside `0x00570030`, not at a function start, and the decompiled behavior is not this class. Recovered class output includes real helpers at `0x005c2340` and `0x005c2930`, but a recovered `class_BackPane.cpp` owner still misplaces the raw flight helpers at `0x005c2760` and `0x005c2840`. The destructor tail is interleaved with [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md), so use the shared island for per-method migration.

2026-05-24 recheck: MCP still reports `0x005c2760` and `0x005c2840` as `Not a function`, while modeled Swallow starts and vtable refs remain stable. Constructor call-in is from `MapPane::SetMapState` at `0x0050dbf3`; vtable data refs cover `OnPaint`, `MoveBy`, `OnTimerEvent`, `DrawSwallow`, and the scalar deleting destructor.

## 2026-06-10 Parent-Gate Evidence

B001-037 live IDA MCP reconfirmed the modeled Swallow constructor/destructor and virtual method ranges: `0x005c2230-0x005c2340`, `0x005c2340-0x005c235f`, `0x005c2360-0x005c2423`, `0x005c2430-0x005c24fa`, `0x005c2500-0x005c26a6`, `0x005c26b0-0x005c275c`, `0x005c2930-0x005c299f`, thunks at `0x005c2a02-0x005c2a0d` and `0x005c2a0d-0x005c2a18`, and scalar deleting destructor `0x005c2a60-0x005c2ab5`. The constructor is called from `MapPane::SetMapState` at `0x0050dbf3`, calls the base weather constructor at `0x005c225b`, and stores the Swallow vtable views at `0x00631340`, `0x00631394`, and `0x006313c4` from constructor/destructor/deleting-destructor family addresses. Vtable slots point to `DrawSwallow`, `OnPaint`, `MoveBy`, `OnTimerEvent`, adjustor thunks, and the scalar deleting destructor. The UTF-16 `SWALLOW.EPF` and `SWALLOW.EPD` literals at `0x006313cc` and `0x006313e4` have only constructor xrefs from `0x005c22d6`/`0x005c22e9` and `0x005c22f0`/`0x005c2303`.

This raises the class page above the strict `85/85` direct-parent gate for exact Swallow vtable and resource-string children. C++ remains blank because the raw flight helpers at `0x005c2760` and `0x005c2840` are still unmodeled/no-xref code starts and final source placement is below final-source confidence.

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
- Evidence: the page documents the weather-layer behavior, method map, raw helper caveats, recovered-owner misplacement, constructor call-in, vtable refs, and shared destructor island; confidence remains capped by raw flight helpers that IDA still does not model as functions.
- 2026-06-02 reconstruction metadata:
  - Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), the current weather-layer source-family parent. C++ remains blank because raw flight-helper ownership/liveness needs more work and the class is below the 95+ final-source threshold.
- 2026-06-06 provenance cleanup:
  - Before: the status, method map, data caveats, and coverage row still described the class through output-provenance wording.
  - After: replaced those phrases with IDA/by-memory evidence basis and recovered-owner caveat wording; scores, parent attachment, and blank final C++ were unchanged.
  - Evidence: [UID:0001O2][0x005c2230-0x005c299e.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299e.SwallowLayerPaneCore.md), [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md), and the shared weather-layer aggregate already carry the exact boundaries and caveats.
- 2026-06-10 B001-037 parent-gate refresh:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`; parent unchanged.
  - Summary/evidence: live IDA MCP reconfirmed modeled Swallow ranges, constructor caller, base-constructor call, vtable stores, method/thunk/deleting-destructor slots, and `SWALLOW.EPF`/`SWALLOW.EPD` constructor xrefs. The class now clears the direct-parent gate for exact Swallow vtable and resource-string children while raw helper liveness still blocks final C++.
