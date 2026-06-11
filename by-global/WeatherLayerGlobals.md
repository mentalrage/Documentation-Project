*** UID:0000TP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# WeatherLayerGlobals

## Status

- Confidence: strong for observed table starts and weather-layer use; medium for final source-level names.
- Likely owner: [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) source family.
- Autogen parent: [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), the weather-layer source-family parent that clears the parent gate and lists these static rain/snow data ranges.
- Current generated owners: mostly `class_RainingLayerPane.cpp` and `class_SnowingLayerPane.cpp`, with unresolved `global-data` rows.
- Type/layout notes: [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md)
- Exact memory docs: [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md), [UID:0001OO][0x00670784-0x006707d0.SnowPatternByteTables](by-memory/0x00670784-0x006707d0.SnowPatternByteTables.md), [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md), and [UID:0001OW][0x0067a764-0x0067a768.ActiveMapPaneSingleton](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md)
- Reconstruction status: attach as source-declared weather-layer static data; keep final C++ blank until final names, render-callback ownership, and the one-file versus per-layer split are settled.

## Role

These globals are static data and render callback pointers used by the map weather overlays. They should be kept with the weather-layer source family or a nearby render-effects support file, not emitted as unrelated standalone globals.

## Rain Coordinate Tables

| Proposed name | Address | Used by | Layout note |
| --- | --- | --- | --- |
| `g_minimapRainStreaks` | `0x006702c8` | `RainingLayerPane::DrawRainOnTarget` at `0x005c1810` | Streak entries are three 16-bit values: x, y, and length. |
| `g_minimapRainSplashSmall` | `0x00670478` | `RainingLayerPane::DrawRainOnTarget` | Splash entries are 16-bit x/y pairs; draw path emits two pixels. |
| `g_minimapRainSplashLarge` | `0x006704d0` | `RainingLayerPane::DrawRainOnTarget` | Splash entries are 16-bit x/y pairs; draw path emits a four-pixel diamond. |
| `g_rainStreakCoords` | `0x00670528` | `RainingLayerPane::OnPaint` at `0x005c1460` | Main-view streak entries are three 16-bit values: x, y, and length. |
| `g_rainSplashSmall` | `0x006706d8` | `RainingLayerPane::OnPaint` | Main-view two-pixel splash coordinates. |
| `g_rainSplashLarge` | `0x00670730` | `RainingLayerPane::OnPaint` | Main-view four-pixel splash coordinates. |

The rain code indexes streak tables with `3 * (i + 24 * frame)` and splash tables with `2 * (i + 7 * frame)`. The loops draw 18 streaks and 7 small/large splashes per rendered frame; the 24-slot stride suggests padding or unused slots in the streak tables.

## Snow Tables

| Proposed name | Address | Used by | Layout note |
| --- | --- | --- | --- |
| `g_snowTypeThresholds` | `0x00670785` | `SnowingLayerPane::RandomizeSnowParticles` at `0x005c1f50` | Two-type weighted threshold table; byte `0x00670784` is the lower-bound sentinel. |
| `g_snowTypeSizeOffsets` | `0x00670788` | `SnowingLayerPane::RandomizeSnowParticles` | Particle size lookup indexed by selected snow type. |
| `g_snowPatternA` | `0x0067078c` | `SnowingLayerPane::RenderSnowParticles` at `0x005c20e0` | First bitmap/pattern source for descriptor set A. |
| `g_snowPatternB` | `0x0067079c` | `SnowingLayerPane::RenderSnowParticles` | Second bitmap/pattern source for descriptor set A. |
| `g_snowTypeThresholdsAlt` | `0x006707ad` | `SnowingLayerPane::UpdateAndRenderSnowParticles` at `0x005c1c80` | Alternate threshold table used by the combined update/render path. |
| `g_snowTypeSizeOffsetsAlt` | `0x006707b0` | `SnowingLayerPane::UpdateAndRenderSnowParticles` | Alternate particle size lookup. |
| `g_snowPatternC` | `0x006707b4` | `SnowingLayerPane::UpdateAndRenderSnowParticles` | First bitmap/pattern source for descriptor set B. |
| `g_snowPatternD` | `0x006707c4` | `SnowingLayerPane::UpdateAndRenderSnowParticles` | Second bitmap/pattern source for descriptor set B. |
| `g_snowLookupTables` | `0x0069bf98` | `SnowingLayerPane::RenderSnowParticles` | Two 40-byte descriptor records initialized through the local static guard. |
| `g_snowInitGuard` | `0x0069bfe8` | `SnowingLayerPane::RenderSnowParticles` | `_Init_thread_header` guard for `g_snowLookupTables`. |
| `g_snowLookupTablesAlt` | `0x0069bff0` | `SnowingLayerPane::UpdateAndRenderSnowParticles` | Two 40-byte descriptor records initialized through the alternate local static guard. |
| `g_snowLookupInitGuard` | `0x0069c040` | `SnowingLayerPane::UpdateAndRenderSnowParticles` | `_Init_thread_header` guard for `g_snowLookupTablesAlt`. |

## Render Callback Dependencies

| Address | Current IDA name | Observed use |
| --- | --- | --- |
| `0x0069b3e0` | `dword_69B3E0` | Draws rain pixels. |
| `0x0069b3e4` | `dword_69B3E4` | Draws rain streak lines. |
| `0x0069b3e8` | `dword_69B3E8` | Draws snow particles through prepared descriptors. |
| `0x0069b3fc` | `dword_69B3FC` | Begins or prepares the weather draw pass. |

These callback pointers look like shared render/GrafPort hooks rather than weather-owned storage. Weather code depends on them, but final ownership should be reviewed with the broader render callback/global pass.

## Current Recheck Notes

- 2026-05-24 IDA recheck: rain table refs remain confined to `RainingLayerPane::OnPaint` at `0x005c1460` and `RainingLayerPane::DrawRainOnTarget` at `0x005c1810`. The exact refs are `0x00670528 -> 0x005c14d3`, `0x006706d8 -> 0x005c15ad/0x005c1617`, `0x00670730 -> 0x005c168d/0x005c16f7/0x005c1761/0x005c17ce`, `0x006702c8 -> 0x005c1877`, `0x00670478 -> 0x005c1950/0x005c19bd`, and `0x006704d0 -> 0x005c1a3a/0x005c1aa5/0x005c1b10/0x005c1b7e`.
- 2026-05-24 IDA recheck: snow threshold/pattern/table refs remain under `SnowingLayerPane` at `0x005c1c80`, `0x005c1f50`, and `0x005c20e0`, with descriptor/guard storage at `0x0069bf98`, `0x0069bfe8`, `0x0069bff0`, and `0x0069c040`.
- 2026-05-25 IDA MCP `py_eval` confirms the range-level table split now documented in `by-memory`: rain coordinate tables at `0x006702c8-0x00670784`, snow byte/pattern data at `0x00670784-0x006707d0`, snow descriptor/guard storage at `0x0069bf98-0x0069c044`, and active map-pane singleton storage at `0x0067a764-0x0067a768`.
- 2026-05-31 IDA MCP recheck confirms the same rain/snow users and table starts through `lookup_funcs`, `xrefs_to`, and `decompile`; `get_bytes` confirms the snow byte-table boundary at `0x006707d0` and the descriptor storage initial bytes at `0x0069bf98-0x0069c044`.
- Current `source-3/simroot_v2/class_RainingLayerPane.cpp` still emits duplicate marker-only `global-data` rows for every rain table and for `g_pWeatherState`; current `class_WeatherLayerPane.cpp` duplicates `g_tileColumns` and `g_tileRows` marker rows. That duplicate marker behavior is a generator-output issue; the hand-maintained docs now carry exact range evidence until Wave3 materializes equivalent real ranges.

## Alias Warning

Current generated `class_RainingLayerPane.cpp` emits `g_pWeatherState` as if it were a separate global. IDA decompilation shows the storage is `dword_67A764`, the same address documented as [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md). Weather drawing checks byte `g_activeMapPane + 0x3f0` (`+1008`) before rendering. Do not create a separate `g_pWeatherState` singleton without proving a distinct storage address.

## Parent Attachment Guidance

Use [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) as the autogen parent for this grouped static data. The parent file intentionally represents the weather-layer source family while final migration decides whether the original source used one `WeatherLayerPane.cpp` file or separate `RainingLayerPane.cpp`, `SnowingLayerPane.cpp`, and `SwallowLayerPane.cpp` files. The rain coordinate tables, snow byte tables, snow descriptor storage, weather-layer data layouts, and active-map alias caveat are all documented from that family root. Do not attach the shared render callback slots here; they remain dependencies pending the broader render callback/global pass.

## Cross-References

- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md)
- [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md)
- [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md)
- [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md)
- [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md)
- [UID:0001OO][0x00670784-0x006707d0.SnowPatternByteTables](by-memory/0x00670784-0x006707d0.SnowPatternByteTables.md)
- [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md)
- [UID:0001OW][0x0067a764-0x0067a768.ActiveMapPaneSingleton](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md)
- [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `90/82`. Summary/evidence: the page documents rain/snow table ranges, descriptor storage, callback dependencies, IDA rechecks, alias warnings, and weather-layer ownership; final source-level names remain medium-confidence.
- 2026-05-31 reconstructable flag and confidence update:
  - What existed before: `CONFIDENCE:82` and blank `RECONSTRUCTABLE`.
  - Changed to: `CONFIDENCE:84` and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP reverified rain/snow static data users, table starts, descriptor/guard refs, byte-table boundary, and active-map aliasing. The global/table data is source-authored or source-declared weather-layer data that must be reconstructed, but parent attachment and C++ emission remain deferred below the final-source gate.
- 2026-06-07 A007 parent attachment:
  - Before: `AUTOGEN_PARENT_UID` was blank even though [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) already documents this static data as part of the weather-layer source family.
  - After: set `AUTOGEN_PARENT_UID:0000P8`, added explicit autogen-parent/reconstruction status bullets, and recorded parent attachment guidance.
  - Evidence: [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md), [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md), [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md), [UID:0001OO][0x00670784-0x006707d0.SnowPatternByteTables](by-memory/0x00670784-0x006707d0.SnowPatternByteTables.md), and [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md) support the family parent. Scores and final C++ remain unchanged because final source split and render callback ownership remain open.
