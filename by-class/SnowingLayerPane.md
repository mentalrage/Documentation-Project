*** UID:0000DC | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000P8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# SnowingLayerPane

## Status

- Confidence: strong for behavior, constructor/vtable evidence, snow static storage, and weather-layer source-family ownership; medium-high for final standalone versus umbrella source split.
- Likely source file: [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md), or part of [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- Address docs: [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md) and [UID:0001O0][0x005c1bd0-0x005c2a5a.SnowingLayerPane](by-memory/0x005c1bd0-0x005c2a5a.SnowingLayerPane.md)
- Current recovered file: `source-3/simroot_v2/class_SnowingLayerPane.cpp`

## Class Purpose

`SnowingLayerPane` is a weather layer pane for snow animation. It initializes a particle table, randomizes snow particle positions/types, performs thread-safe lookup-table initialization, and renders 200 snow particles through global render callbacks.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `SnowingLayerPane` | `0x005c1bd0-0x005c1c7d` | Initializes pane state and 200 particle rectangle entries. |
| `UpdateAndRenderSnowParticles` | `0x005c1c80-0x005c1f4b` | Updates weather state, randomizes particles, and renders snow. |
| `RandomizeSnowParticles` | `0x005c1f50-0x005c20d3` | Seeds visible particles using weighted snow-type tables. |
| `RenderSnowParticles` | `0x005c20e0-0x005c2227` | Initializes lookup tables and renders particle rectangles. |
| destructor thunks | `0x005c29ec-0x005c2a01` | Excluded compiler/vtable thunks that forward to the scalar deleting destructor. |
| `ScalarDeletingDestructor` | `0x005c2a20-0x005c2a5a` | Calls base destruction and optionally deletes storage. |

## Evidence Notes

- IDA MCP confirms the constructor, update/render methods, and scalar deleting destructor as real functions.
- IDA MCP also confirms excluded thunk starts at `0x005c29ec` and `0x005c29f7`.
- 2026-05-24 IDA recheck ties constructor call-in to `MapPane::SetMapState` at `0x0050dc17` and vtable refs to `0x006312f4`, `0x006312fc`, `0x006312c0`, and `0x006312b0`.
- Wave3 currently penalizes the class aggregate because those excluded thunks overflow the class ranges; see the Snowing/Swallow ownership entry in [wave3_data_issues](../wave3_data_issues.md).
- The broad legacy range crosses [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md) code beginning at `0x005c2230`; migrate from the shared island by per-method ownership.
- `MapPane::SetMapState` calls into weather-layer construction/destruction behavior when snow weather is selected.
- High-blast globals around `DAT_0067a764`, `DAT_0069b3e8`, and `DAT_0069b3fc` remain unresolved aliases in Wave3 and should be named with a broader render/global pass.
- Snow table addresses are now tracked in [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md): [UID:0001OO][0x00670784-0x006707d0.SnowPatternByteTables](by-memory/0x00670784-0x006707d0.SnowPatternByteTables.md), descriptor tables at `0x0069bf98` and `0x0069bff0`, and local static guards at `0x0069bfe8` and `0x0069c040` under [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md).
- The base and sibling weather layers are documented as [UID:0000G1][WeatherLayerPane](by-class/WeatherLayerPane.md), [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md), and [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md).
- Current generated source still contains provisional helper/base names including `InitializeSnowLookupDescriptor` and `TextButtonExControlPane::~TextButtonExControlPane`; keep ownership decisions anchored to IDA function ranges and weather-layer field behavior.

## Cross-References

- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md)
- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- [UID:0001O0][0x005c1bd0-0x005c2a5a.SnowingLayerPane](by-memory/0x005c1bd0-0x005c2a5a.SnowingLayerPane.md)
- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- [UID:0001OO][0x00670784-0x006707d0.SnowPatternByteTables](by-memory/0x00670784-0x006707d0.SnowPatternByteTables.md)
- [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md)
- [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md)

## Changes

- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Evidence: the page documents the weather-layer role, method ranges, constructor caller, vtable refs, sibling split, globals/table cross-references, and Wave3 ownership caveat; confidence remains capped by unresolved render/global aliases and final source-owner placement.
- 2026-06-02 IDA/source-family refresh:
  - Changed to: completion `86`, confidence `82`, `RECONSTRUCTABLE:TRUE`, and `AUTOGEN_PARENT_UID:0000P8`.
  - Evidence: refreshed IDA confirms constructor caller `0x0050dc17`, vtable refs, Snowing-exclusive method ends, destructor thunks, and table/descriptor storage references. C++ remains blank because the class is below the 95+ final-source threshold.
