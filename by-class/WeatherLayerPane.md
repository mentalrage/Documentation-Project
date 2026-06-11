*** UID:0000G1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WeatherLayerPane

## Status

- Confidence: very strong for base behavior, constructor/timer boundaries, vtable stores, and derived-constructor ownership.
- Likely source file: [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- Main address range: [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md)
- Current recovered file: `source-3/simroot_v2/class_WeatherLayerPane.cpp`

## Class Purpose

`WeatherLayerPane` is the base `Pane` subclass for map weather overlays. It computes the overlay pixel dimensions from map tile rows/columns, stores animation state, and advances the current animation frame through a timer callback.

## Method Map

| Range | Method | Role |
| --- | --- | --- |
| `0x005c12a0-0x005c13a0` | constructor | Initializes pane/vtables, map-dependent effect bounds, and base animation state. |
| `0x005c13b0-0x005c1407` | `OnTimerEvent` | Advances animation frame modulo max frame count, invalidates/repaints parent, and schedules the next timer. |

## Key Relationships

- Base class for [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md), [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md), and [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md).
- Constructed indirectly through `MapPane` weather setup before concrete derived weather panes install their own vtables.
- Uses tile count/global asset-mode fields currently named `g_useEpfAssets`, `g_tileColumns`, and `g_tileRows`.
- Concrete rain/snow tables and render callback dependencies are tracked in [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md).

## Data Caveats

Current metadata reports a stored method-name control-character artifact for the constructor. The active source also contains base/helper labels inherited from generated decompilation history; use IDA boundaries and behavior for migration decisions.

2026-05-24 recheck: active `source-3/simroot_v2/class_WeatherLayerPane.cpp` duplicates marker-only `global-data` rows for `g_tileColumns` and `g_tileRows`. IDA confirms `0x005c12a0` and `0x005c13b0` as real function starts, and `0x005c13b0` is referenced from the rain/snow/swallow vtables at `0x00631218`, `0x006312a8`, and `0x00631338`.

## 2026-06-10 Parent-Gate Evidence

B001-037 live IDA MCP reconfirmed `sub_5C12A0` as `0x005c12a0-0x005c13a1` and `sub_5C13B0` as `0x005c13b0-0x005c1408`. The base constructor has direct code xrefs from the `RainingLayerPane`, `SnowingLayerPane`, and `SwallowLayerPane` constructors at `0x005c141a`, `0x005c1bfb`, and `0x005c225b`. It stores the three `WeatherLayerPane` vtable views at `0x00631190`, `0x006311e4`, and `0x00631214` from `0x005c12d0`, `0x005c12d6`, and `0x005c12e0`, and the shared timer handler is present in the derived weather vtables at `0x00631218`, `0x006312a8`, and `0x00631338`.

This raises the class page above the strict `85/85` direct-parent gate for the exact `WeatherLayerPane` vtable-data child. C++ remains blank because final field names and the final one-file versus per-derived-file source split are still below final-source confidence.

## Cross-References

- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md)

## Changes

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:80` and `CONFIDENCE:84`.
  - Summary/evidence: scored from the base weather-pane constructor/timer behavior, derived-pane relationships, map/tile/global dependencies, IDA boundary confirmation, and generated metadata caveats.
- 2026-06-02 reconstruction metadata:
  - Marked `RECONSTRUCTABLE:TRUE` and attached to [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md). C++ remains blank because this page is below the 95+ final-source threshold.
- 2026-06-10 B001-037 parent-gate refresh:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`; parent unchanged.
  - Summary/evidence: live IDA MCP reconfirmed the exact constructor/timer ranges, derived constructor callers, three base vtable stores, and shared timer-handler vtable slots. The class now clears the direct-parent gate for exact base weather vtable data while retaining source-split and final-field-name caveats.
