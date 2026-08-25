*** UID:0000TP | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Exact rain declarations emit from [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md), and exact snow declarations emit from [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md); this broad support page does not duplicate either body.
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# WeatherLayerGlobals

## Status

- Confidence: very strong for observed rain declarations, table starts, descriptor storage, weather-layer use, saved weather method labels, and the current source-family route; shared render callback names remain less certain.
- Likely owner: [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) source family.
- Autogen parent: [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), the weather-layer source-family parent that clears the parent gate and lists these static rain/snow data ranges.
- Current generated owners: mostly `class_RainingLayerPane.cpp` and `class_SnowingLayerPane.cpp`, with unresolved `global-data` rows.
- Type/layout notes: [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md)
- Exact memory docs: [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md), [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md), [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md), and [UID:0001OW][0x0067a764-0x0067a768.ActiveMapPaneSingleton](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md)
- Reconstruction status: exact rain types/arrays emit once through UID0001ON at source position 0, and exact mutable snow arrays emit once through UID0001OO at source position 1. This broad page remains a non-duplicating support marker; only shared callback ownership stays separate.

## Role

These globals are static data and render callback pointers used by the map weather overlays. They should be kept with the weather-layer source family or a nearby render-effects support file, not emitted as unrelated standalone globals.

## Rain Coordinate Tables

| Proposed name | Address | Used by | Layout note |
| --- | --- | --- | --- |
| `s_targetRainStreaks` | `0x006702c8` | `RainingLayerPane::DrawRainOnTarget` at `0x005c1810` | Writable internal-linkage `RainStreak[3][24]`; each signed-short record is x/y/length, with 18 drawn plus six zero records per frame. |
| `s_targetRainSmallSplashes` | `0x00670478` | `RainingLayerPane::DrawRainOnTarget` | Writable internal-linkage `RainSplash[3][7]`; signed-short x/y records draw two-pixel marks. |
| `s_targetRainLargeSplashes` | `0x006704d0` | `RainingLayerPane::DrawRainOnTarget` | Writable internal-linkage `RainSplash[3][7]`; draws four-pixel diamond marks. |
| `s_rainStreaks` | `0x00670528` | `RainingLayerPane::OnPaint` at `0x005c1460` | Main-view `RainStreak[3][24]`, byte-identical to the target-port streak object but physically distinct. |
| `s_rainSmallSplashes` | `0x006706d8` | `RainingLayerPane::OnPaint` | Main-view `RainSplash[3][7]`, byte-identical to the target-port small-splash object but physically distinct. |
| `s_rainLargeSplashes` | `0x00670730` | `RainingLayerPane::OnPaint` | Main-view `RainSplash[3][7]`, byte-identical to the target-port large-splash object but physically distinct. |

The rain code indexes streak arrays with `3 * (i + 24 * frame)` and splash arrays with `2 * (i + 7 * frame)`. The loops draw 18 streaks and 7 small/large splashes per rendered frame; the remaining six streak records in each 24-entry frame are explicit zero initializers, not inter-object padding. Three separate four-byte zero spans at `0x006704cc`, `0x00670524`, and `0x0067072c` are symbol-free compiler alignment before eight-byte-aligned array starts.

The first family is target-port data, not proven minimap data. Both consumers use signed-extension word loads, fixing `RainStreak` as three signed shorts and `RainSplash` as two signed shorts. Corresponding target/main arrays are byte-identical but cannot be collapsed because the executable preserves six distinct physical objects with exclusive consumers. [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md) owns their complete source initializers and exact whole/segment hashes.

## Snow Tables

| Source declaration | Exact range | Used by | Layout note |
| --- | --- | --- | --- |
| `s_targetSnowTypeThresholds[4]` | `0x00670784-0x00670788` | `SnowingLayerPane::OnFrameChanged` at `0x005c1f50` | Unsigned `{0,50,100,0}`; the xref lands at element 1 and element 0 is the lower sentinel. |
| `s_targetSnowSizes[4]` | `0x00670788-0x0067078c` | `SnowingLayerPane::OnFrameChanged` | Unsigned `{4,3,0,0}`; `movzx` size forms particle right/bottom. |
| `s_targetSnowPatterns[2][16]` | `0x0067078c-0x006707ac` | `SnowingLayerPane::RenderSnowParticles` at `0x005c20e0` | Target-port 4x4 and 3x3 patterns in two fixed 16-byte slots. |
| `s_snowTypeThresholds[4]` | `0x006707ac-0x006707b0` | `SnowingLayerPane::UpdateAndRenderSnowParticles` at `0x005c1c80` | Main-view unsigned `{0,50,100,0}`; xref lands at element 1. |
| `s_snowSizes[4]` | `0x006707b0-0x006707b4` | `SnowingLayerPane::UpdateAndRenderSnowParticles` | Main-view unsigned `{4,3,0,0}`. |
| `s_snowPatterns[2][16]` | `0x006707b4-0x006707d4` | `SnowingLayerPane::UpdateAndRenderSnowParticles` | Main-view 4x4 and 3x3 patterns; the second slot includes former false-padding bytes `0x006707d0-0x006707d3`. |

The target and main families are byte-identical but physically distinct 40-byte objects with exclusive consumers. Each family has SHA256 `4AD9D94FB72E08C575D44FC9CF0966944ABBD44377BDB5DB30BD6D1D1F73169E`; the full 80 bytes have SHA256 `2E9032C5A4CD7ED60F52C87263E091B59932A0B848BF69350DE157207FE565F4`. The arrays remain writable, file-static, and non-`const`; UID0001OO owns their complete initializers. Historical `g_snow...`, `Alt`, and A/B/C/D spellings remain rejected search aliases rather than emitted source.

The descriptor/guard storage is separate and remains method-covered. [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md) confirms zero-filled local-static backing. UID0003O3 covers `0x0069bf98-0x0069bfec` with `s_targetSnowPatterns[0/1]`; UID0003O1 covers `0x0069bff0-0x0069c044` with `s_snowPatterns[0/1]`. Its `g_snowLookupTables`-style names remain documentation aliases and must not emit as independent globals.

## Render Callback Dependencies

| Address | Current IDA name | Observed use |
| --- | --- | --- |
| `0x0069b3e0` | `dword_69B3E0` | Draws rain pixels. |
| `0x0069b3e4` | `dword_69B3E4` | Draws rain streak lines. |
| `0x0069b3e8` | `dword_69B3E8` | Draws snow particles through prepared descriptors. |
| `0x0069b3fc` | `dword_69B3FC` | Begins or prepares the weather draw pass. |

These callback pointers look like shared render/GrafPort hooks rather than weather-owned storage. Weather code depends on them, but final ownership should be reviewed with the broader render callback/global pass.

2026-06-16 C001 rechecked the callback slots while reviewing the rain/snow users. They remain unsafe to attach or rename as weather-owned data: `RainingLayerPane_OnPaint`, `RainingLayerPane_DrawRainOnTarget`, `SnowingLayerPane_UpdateAndRenderSnowParticles`, and `SnowingLayerPane_RenderSnowParticles` call or depend on `unk_69B3E0`, `unk_69B3E4`, `unk_69B3E8`, and `unk_69B3FC`, but the slots look like shared surface/GrafPort callback state. The dry-run `unk_69B3E0 -> g_pfnDrawWeatherPixel` succeeded technically and was intentionally skipped because it would assert weather ownership over a shared render dependency.

## Current Recheck Notes

- 2026-05-24 IDA recheck: rain table refs remain confined to `RainingLayerPane::OnPaint` at `0x005c1460` and `RainingLayerPane::DrawRainOnTarget` at `0x005c1810`. The exact refs are `0x00670528 -> 0x005c14d3`, `0x006706d8 -> 0x005c15ad/0x005c1617`, `0x00670730 -> 0x005c168d/0x005c16f7/0x005c1761/0x005c17ce`, `0x006702c8 -> 0x005c1877`, `0x00670478 -> 0x005c1950/0x005c19bd`, and `0x006704d0 -> 0x005c1a3a/0x005c1aa5/0x005c1b10/0x005c1b7e`.
- 2026-05-24 IDA recheck: snow threshold/pattern/table refs remain under `SnowingLayerPane` at `0x005c1c80`, `0x005c1f50`, and `0x005c20e0`, with descriptor/guard storage at `0x0069bf98`, `0x0069bfe8`, `0x0069bff0`, and `0x0069c040`.
- Historical 2026-05-25/2026-05-31 checks established the correct consumers but used the then-current `0x006707d0` endpoint. UID0001OO now supersedes only that endpoint: the snow data is `[0x00670784,0x006707d4)`, with the final four zeros completing the second fixed pattern slot.
- Historical 2026-06-16 C001 refresh saved the five weather consumer labels and intentionally skipped provisional rain/snow data names. UID0001ON and UID0001OO later resolved the exact source-facing declarations; the shared callback slots remain independently unresolved.
- Historical `source-3/simroot_v2/class_RainingLayerPane.cpp` emitted duplicate marker-only `global-data` rows for every rain table and for `g_pWeatherState`, while historical `class_WeatherLayerPane.cpp` duplicated `g_tileColumns` and `g_tileRows` marker rows. That stale generated behavior is non-authoritative; current validator-owned output and exact by-* declarations control reconstruction, and Wave2/Wave3 material is ignored.

## Alias Warning

Current generated `class_RainingLayerPane.cpp` emits `g_pWeatherState` as if it were a separate global. IDA decompilation shows the storage is `dword_67A764`, the same address documented as [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md). Weather drawing checks byte `g_activeMapPane + 0x3f0` (`+1008`) before rendering. Do not create a separate `g_pWeatherState` singleton without proving a distinct storage address.

The 2026-06-16 decompilation recheck again shows both rain paths and both snow render paths testing `dword_67A764 + 1008` before drawing. No separate weather-state storage was found in the table/callback refresh.

## Parent Attachment Guidance

Use [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) as the autogen parent for this grouped static data. Current reconstruction selects the one-file WeatherLayerPane source family from contiguous code, RTTI/vtables, adjacent rain/snow data, and convergent class/global/type routes; separate Raining/Snowing/Swallow files remain historical physical-file hypotheses. The rain coordinate tables, snow byte tables, snow descriptor storage, weather-layer data layouts, and active-map alias caveat are all documented from that family root. Do not attach the shared render callback slots here; they remain dependencies pending the broader render callback/global pass.

## Cross-References

- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md)
- [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md)
- [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md)
- [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md)
- [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md)
- [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md)
- [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md)
- [UID:0001OW][0x0067a764-0x0067a768.ActiveMapPaneSingleton](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md)
- [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)

## 2026-07-23 UID0003PJ Render And Gate Dependency Closure

- [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md) resolves the three shared Surface dispatch dependencies used by main-view rain:
  - `SurfaceFillRectProc g_pfnFillRect` at `0x0069b3fc`;
  - `SurfaceDrawLineDeltaProc g_pfnDrawLineDelta` at `0x0069b3e4`;
  - `SurfaceDrawPixelProc g_pfnDrawPixel` at `0x0069b3e0`.
- Semantic [UID:0000TN][SurfaceRenderCallbackTable](by-global/SurfaceRenderCallbackTable.md) owns the one typedef/definition set in `NexusTK/render/Surface.cpp`; physical UID0001PI remains blank. Final canonical Surface.h supplies matching typedefs and `extern` declarations to Weather code. The current generator does not emit that header, so this page does not claim current standalone cross-TU compilation.
- The weather gate is not a separate `g_pWeatherState` object. It is the existing `g_activeMapPane` singleton plus public MapPane byte `m_waitingForLocalPlayerStatus` at `+0x3f0`. UID0003PJ directly dereferences it after filling its bounds; no null guard exists.
- Exact rain records and arrays remain emitted only by UID0001ON: three main-view frames and three physically separate target-port frames. This page neither duplicates array definitions nor merges the two families.
- Other callback-table slots, Snow globals/layouts, and broader source names keep their prior uncertainty. In particular, this bounded closure does not promote the body-empty compat/RGB565 line callback functions or declare all Surface callback interfaces final.
- Score moves from `92/90` to `93/92` because the Rain-used slots, MapPane gate, one-definition route, and final header linkage obligations are resolved. Existing ownership/emitter UID0000P8 and the exact UID0001ON emission route remain unchanged.

## Changes

- 2026-07-26 B002 UID0001OO snow-table source callback:
  - Raised `93/92` to `94/94`, kept UID0000P8 ownership/emission, and changed the formal marker to route exact rain through UID0001ON and exact snow through UID0001OO without duplicate bodies.
  - Replaced eight provisional snow aliases with six exact writable arrays, exact ranges, unsigned types, target/main roles, two fixed pattern slots per family, physical hashes, and corrected the false-padding tail through `0x006707d4`.
  - Preserved descriptor-storage aliases and shared callback uncertainty separately; only the source-ready snow declaration blocker was closed.
- 2026-07-22 B005 RainCoordinateTables source-quality callback:
  - Changed `91/87 -> 92/90` and applied the non-duplicating R3 formal marker.
  - Replaced provisional `g_minimap*`/`g_rain*` rain rows with exact source-facing `s_targetRain*`/`s_rain*` names, signed-short record types, `3x24`/`3x7` dimensions, physical duplication, exclusive consumers, and three compiler-alignment gaps.
  - Recorded UID0001ON as the sole complete-initializer emitter and selected UID0000P8's one-file family while preserving snow/global/callback/alias evidence and historical split-file assumptions.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `90/82`. Summary/evidence: the page documents rain/snow table ranges, descriptor storage, callback dependencies, IDA rechecks, alias warnings, and weather-layer ownership; final source-level names remain medium-confidence.
- 2026-05-31 reconstructable flag and confidence update:
  - What existed before: `CONFIDENCE:82` and blank `RECONSTRUCTABLE`.
  - Changed to: `CONFIDENCE:84` and `RECONSTRUCTABLE:TRUE`.
  - Summary/evidence: IDA MCP reverified rain/snow static data users, table starts, descriptor/guard refs, byte-table boundary, and active-map aliasing. The global/table data is source-authored or source-declared weather-layer data that must be reconstructed, but parent attachment and C++ emission remain deferred below the final-source gate.
- 2026-06-07 A007 parent attachment:
  - Before: `AUTOGEN_PARENT_UID` was blank even though [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) already documents this static data as part of the weather-layer source family.
  - After: set `AUTOGEN_PARENT_UID:0000P8`, added explicit autogen-parent/reconstruction status bullets, and recorded parent attachment guidance.
  - Evidence: [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md), [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md), [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md), [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md), and [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md) support the family parent. Scores and final C++ remain unchanged because final source split and render callback ownership remain open.
- 2026-06-16 C001 global/IDA refresh:
  - Changed from `90/84` to `91/87`.
  - Summary/evidence: live IDA reconfirmed rain/snow table xrefs, descriptor/guard storage, zero-filled descriptor bytes, `g_activeMapPane + 0x3f0` aliasing, saved the five weather method labels, and explicitly skipped weather table/callback data renames whose original table names or shared callback ownership remain provisional.
- 2026-06-28 B009 SnowLookupDescriptorStorage empty-emitter sync:
  - Metadata unchanged.
  - Summary/evidence: clarified that `g_snowLookupTables`-style names are documentation/search aliases for SnowingLayerPane local-static descriptor storage, not final standalone globals. Accepted MCP session `b009_0001Q4_20260628` proves zero-filled backing storage, two guarded descriptor families, method-owned pattern/frame/rectangle assignments through [UID:0003O1][0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles](by-memory/0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles.md) and [UID:0003O3][0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles](by-memory/0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles.md), and no split or successor extension for [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md).
- 2026-07-01 B008 WeatherLayerPane empty-emitter family callback:
  - Metadata unchanged.
  - Summary/evidence: inserted the formal no-duplicate-global-block marker. [UID:0003O1][0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles](by-memory/0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles.md) and [UID:0003O3][0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles](by-memory/0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles.md) now provide first-draft method C++ using descriptive callback names, while this global page remains comment-only support for rain/snow tables, descriptor storage, and shared callback/global evidence rather than owning standalone global/callback source.
