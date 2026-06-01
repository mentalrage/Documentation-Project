*** UID:0000NR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SnowingLayerPane

## Status

- Confidence: strong for class behavior and anchors; medium for final file split.
- Proposed module: `map/SnowingLayerPane.cpp` or part of [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- Current generated source: `class_SnowingLayerPane.cpp`
- Primary class doc: [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md)
- Main address docs: [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md) and [UID:0001O0][0x005c1bd0-0x005c2a5a.SnowingLayerPane](by-memory/0x005c1bd0-0x005c2a5a.SnowingLayerPane.md)

## File Role

`SnowingLayerPane` is the snow weather layer used by the map view. It initializes a 200-particle table, updates snow state, randomizes particle positions/types, lazily initializes lookup tables, and renders snow particles through global render callbacks.

This is map weather rendering support. It should live under `map/` unless later render-effect evidence proves that the original source used a broader weather/effects module.

The base and sibling weather layers are now documented in [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md), and [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md). `MapPane` weather setup allocates the concrete weather pane based on weather type.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `SnowingLayerPane` | `0x005c1bd0-0x005c2227`, destructor wrapper at `0x005c2a20` | Snow weather pane lifecycle, particle update/randomization, lookup initialization, and rendering. |
| destructor adjustor thunks | `0x005c29ec-0x005c2a01` | Excluded compiler/vtable thunks that forward to the scalar deleting destructor. |
| snow lookup/global tables | [UID:0001OO][0x00670784-0x006707d0.SnowPatternByteTables](by-memory/0x00670784-0x006707d0.SnowPatternByteTables.md), [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md) | Pattern, threshold, type-size, descriptor, guard, render-state, and callback tables; see [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md). |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Construction | `0x005c1bd0` | Initializes pane state and 200 snow particle rectangles. |
| Update/render loop | `0x005c1c80` | Updates weather state, randomizes particles, and triggers render. |
| Randomization | `0x005c1f50` | Seeds visible particle entries from weighted snow-type tables. |
| Drawing | `0x005c20e0` | Performs guarded lookup-table setup and renders particles through callbacks. |
| Destruction | `0x005c29ec`, `0x005c29f7`, `0x005c2a20` | Two excluded thunk starts forward into the scalar deleting destructor. |

## Boundary Notes

- IDA confirms all listed method and thunk starts as exact functions.
- 2026-05-24 IDA recheck: the constructor `0x005c1bd0` is called by `MapPane::SetMapState` at `0x0050dc17`; vtable refs point at `UpdateAndRenderSnowParticles` (`0x006312f4`), `RandomizeSnowParticles` (`0x006312fc`), `RenderSnowParticles` (`0x006312c0`), and the scalar deleting destructor (`0x006312b0`).
- Wave3 lists no missing refs for the class, but `show grade class SnowingLayerPane` currently fails completion because excluded thunk children at `0x005c29ec` and `0x005c29f7` overflow the class aggregate ranges. The ownership/range issue is tracked in [wave3_data_issues](../wave3_data_issues.md).
- The legacy `0x005c1bd0-0x005c2a5a` aggregate crosses [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md) code beginning at `0x005c2230`; use the shared island doc for per-method migration.
- The global names in current generated source are useful but provisional; broad render/global naming should review `g_snow*` and callback aliases before final migration. [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md) records the current table addresses, exact range docs, and the render callback dependency caveat.
- Current `source-3/simroot_v2/class_SnowingLayerPane.cpp` still contains generated helper placeholders such as `InitializeSnowLookupDescriptor` and base/destructor name pollution such as `TextButtonExControlPane::~TextButtonExControlPane`; do not use those names as source-ownership evidence.

## Cross-References

- [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md)
- [UID:0001O0][0x005c1bd0-0x005c2a5a.SnowingLayerPane](by-memory/0x005c1bd0-0x005c2a5a.SnowingLayerPane.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md)
- [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- [UID:0001OO][0x00670784-0x006707d0.SnowPatternByteTables](by-memory/0x00670784-0x006707d0.SnowPatternByteTables.md)
- [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md)
- [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `80`.
  - Evidence: document captures weather-layer role, proposed contents, method families, constructor/vtable evidence, global table refs, boundary notes, Wave3 issue caveat, and cross-references; confidence remains capped by final split between a standalone snow file and shared `WeatherLayerPane`.
