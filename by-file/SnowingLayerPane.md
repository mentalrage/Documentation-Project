*** UID:0000NR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SnowingLayerPane

## Status

- Confidence: very strong for class behavior, exact child boundaries, source-ready constructor/object layout, vtable evidence, and static table anchors; medium-high only for historical standalone-versus-weather-family disk provenance.
- Current module route: part of [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) in `map/WeatherLayerPane.cpp`/`.h`. `map/SnowingLayerPane.cpp` is retained as a historical candidate, not the current constructor emitter.
- Documentation basis: IDA-confirmed SnowingLayerPane ranges plus the by-* memory/table docs below.
- Primary class doc: [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md)
- Main address docs: [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md) and [UID:0001O0][0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex](by-memory/0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex.md)

## File Role

`SnowingLayerPane` is the snow weather layer used by the map view. It initializes a 200-particle table, updates snow state, randomizes particle positions/types, lazily initializes lookup tables, and renders snow particles through global render callbacks.

This is map weather rendering support. It should live under `map/` unless later render-effect evidence proves that the original source used a broader weather/effects module.

The base and sibling weather layers are now documented in [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md), and [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md). `MapPane` weather setup allocates the concrete weather pane based on weather type.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `SnowingLayerPane` | source-ready constructor [UID:0003O0][0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor](by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md), exact children through `0x005c2228`, scalar deleting destructor `0x005c2a20-0x005c2a5b` | Exact `0x10ac` Snow object with `0x10c` Weather prefix and inline `SnowParticleEntry[200]`; Snow weather lifecycle, update/randomization, lookup initialization, rendering, and destructor wrapper. |
| destructor adjustor thunks | `0x005c29ec-0x005c2a01` | Excluded compiler/vtable thunks that forward to the scalar deleting destructor. |
| snow lookup/global tables | [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md), [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md) | UID0001OO owns six exact writable target/main arrays through current UID0000P8 at position 1. UID0001Q4 remains local-static descriptor backing covered by the exact method pages rather than standalone arrays. |

## Method Families

| Area | Representative anchors | Notes |
| --- | --- | --- |
| Construction | `0x005c1bd0-0x005c1c7e` | Initializes pane state and 200 snow particle rectangles; exact child [UID:0003O0][0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor](by-memory/0x005c1bd0-0x005c1c7e.SnowingLayerPaneConstructor.md). |
| Update/render loop | `0x005c1c80-0x005c1f4c` | Updates weather state, randomizes particles, and triggers render; exact child [UID:0003O1][0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles](by-memory/0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles.md). |
| Randomization | `0x005c1f50-0x005c20d4` | Applies the 200-entry particle pass, rolling 180-record shift, and 20-entry leading refresh from the first snow threshold/size tables; exact child [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md). |
| Drawing | `0x005c20e0-0x005c2228` | Performs guarded lookup-table setup and renders particles through callbacks; exact child [UID:0003O3][0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles](by-memory/0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles.md). |
| Destruction | `0x005c29ec`, `0x005c29f7`, `0x005c2a20-0x005c2a5b` | Two excluded thunk starts forward into the scalar deleting destructor; exact source-bearing child [UID:0003O4][0x005c2a20-0x005c2a5b.SnowingLayerPaneScalarDeletingDestructor](by-memory/0x005c2a20-0x005c2a5b.SnowingLayerPaneScalarDeletingDestructor.md). |

## Boundary Notes

- IDA confirms all listed method and thunk starts as exact functions.
- 2026-06-13 IDA MCP `lookup_funcs` reconfirmed the modeled Snowing starts and sizes: constructor `0x005c1bd0` size `0xae`, update/render `0x005c1c80` size `0x2cc`, randomize `0x005c1f50` size `0x184`, render `0x005c20e0` size `0x148`, and scalar deleting destructor `0x005c2a20` size `0x3b`.
- 2026-05-24 IDA recheck: the constructor `0x005c1bd0` is called by `MapPane::SetMapState` at `0x0050dc17`; vtable refs point at `UpdateAndRenderSnowParticles` (`0x006312f4`), `RandomizeSnowParticles` (`0x006312fc`), `RenderSnowParticles` (`0x006312c0`), and the scalar deleting destructor (`0x006312b0`).
- The excluded thunk starts at `0x005c29ec` and `0x005c29f7` are class-family artifacts, but they should stay documented as thunk/ownership caveats rather than used to widen the Snowing method aggregate.
- The legacy `0x005c1bd0-0x005c2a5a` aggregate was corrected to the [UID:0001O0][0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex](by-memory/0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex.md) after IDA confirmed the destructor exclusive end. It crosses [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md) code beginning at `0x005c2230`; use exact children for source migration.
- UID0001OO closes the table names as `s_targetSnowTypeThresholds`, `s_targetSnowSizes`, `s_targetSnowPatterns`, `s_snowTypeThresholds`, `s_snowSizes`, and `s_snowPatterns`. Only shared render callback and local-static descriptor aliases remain provisional; [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md) separates those caveats from the exact array declarations.
- Provisional helper/base aliases such as `InitializeSnowLookupDescriptor` and `TextButtonExControlPane::~TextButtonExControlPane` should not be used as source-ownership evidence.

## 2026-07-24 UID0003O0 Constructor And Historical-File Disposition

- UID0003O0 is the exact source-bearing `SnowingLayerPane::SnowingLayerPane()` child at `[0x005c1bd0,0x005c1c7e)`. Its sole MapPane caller at `0x0050dc17` allocates exactly `0x10ac` bytes; no aggregate, vtable-data page, or this historical file page owns a duplicate body.
- The exact complete object is a `0x10c`-byte `WeatherLayerPane` prefix followed by `SnowParticleEntry m_snowParticles[200]` at `+0x10c`. Each `0x14`-byte entry is `RectBounds bounds`, one-byte `type`, and three bytes of natural tail padding, so the inline `0xfa0`-byte array ends at `0x10ac`.
- Source-visible constructor state is inherited `m_currentFrame = 4`, `m_frameCount = 5`, `m_timerInterval = 200`, 200 calls to `InitRectBounds(...,0,800,8,808)` plus `type = 0`, and inherited `m_drawOnTarget = true`. Padding remains untouched; base construction, vptr stores, ABI return, EH/cookie state, and cleanup are compiler output.
- The current canonical source/header route is UID0000P8 `WeatherLayerPane.cpp`/`.h`. This page records a possible original dedicated `SnowingLayerPane.cpp` only as historical provenance because no PDB/source-path evidence proves that split. No current constructor emitter, class owner, or method child moves here.

## RandomizeSnowParticles Candidate-File Notes

This page remains the dedicated `SnowingLayerPane.cpp` candidate, but [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md) is not forcibly moved here as a method emitter in the 2026-06-23 B003 MCP-backed callback. Current generated memory/class routing still places the method through [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), while this page owns or candidates the snow-specific file/table context.

Accepted target facts preserved for this file-level page:

- Exact method range: MCP session `b880584f` `lookup_funcs 0x005c1f50` returns `sub_5C1F50` size `0x184`; `decompile`/`disasm` confirm `0x005c1f50-0x005c20d4`; MCP `get_bytes` SHA256 prefix is `501c485e42127a02`.
- Adjacent padding: MCP `get_bytes` confirms `0x005c1f4c-0x005c1f50` is four `0xcc` bytes before the method, SHA256 prefix `8843b54d2df63ca2`, and `0x005c20d4-0x005c20e0` is twelve `0xcc` bytes before the render method, SHA256 prefix `a0d08a155aa4e9aa`.
- Route: MCP `xrefs_to 0x005c1f50` confirms Snowing vtable data xref `0x006312fc -> 0x005c1f50`. Sibling Snowing cells `0x006312f4 -> 0x005c1c80` and `0x006312c0 -> 0x005c20e0` keep the method grouped with update/render and render. MCP `func_profile` reports `caller_count:0`, so no direct code caller/direct code xref to `0x005c1f50` was found.
- Active-map gate: the method checks [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) byte `+0x3f0`; generated `g_pWeatherState` remains a stale alias and should not drive source placement.
- Particle flow: MCP disassembly shows the first pass walks `0xc8` records / 200 records (Verified with int_convert.py) from `m_snowParticles` at `this+0x10c`, stride `0x14` / 20 bytes (Verified with int_convert.py), and calls helper `0x004b7e10` with `_rand`-derived values. MCP helper disassembly/decompilation proves the helper offsets `RectBounds` by dx/dy. Inherited signed `m_currentFrame` at `this+0xf8` gates the rolling refresh, and inherited `RectBounds m_weatherBounds` occupies `this+0xfc..+0x10b`.
- Rolling refresh: `memmove(this+0x29c, this+0x10c, 0xe10)` shifts 180 records into entries 20..199 because `0xe10` is 3600 bytes (Verified with int_convert.py) and `this+0x29c` is entry 20. The method then generates 20 leading records.
- Data layout: `SnowParticleEntry` is a 20-byte record with rectangle dwords at `+0x00/+0x04/+0x08/+0x0c`, type byte at `+0x10`, and three trailing pad/unused bytes.
- Table role: MCP `xrefs_to` confirms this method uses [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md)'s first threshold pointer `0x00670785` and first size table `0x00670788`; it does not use the alternate threshold/size group for its 20-entry leading refresh because `0x006707ad` and `0x006707b0` xref sibling `sub_5C1C80`.
- Historical no-code checkpoint: the earlier UID0003O2 pass treated helper naming, inherited fields, table grouping, and physical file placement as unresolved. UID0003O0/UID0003PG close `m_currentFrame`, `m_weatherBounds`, and the current Weather route; UID0001OO closes the exact target threshold/size arrays. UID0003O2 remains blank and separately owned only for its own operation-order/body callback, not for table declaration uncertainty.

Placement and ownership decisions:

- Accepted canonical method owner remains [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md).
- Accepted current source-family route remains [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md).
- This page remains a historical dedicated source-file candidate and descriptor-storage context. UID0001OO no longer routes here: exact snow arrays now emit through current UID0000P8 at position 1. UID0001Q4 retains its covered-by historical file context, while its executable setup stays on UID0003O1/UID0003O3.
- Rejected alternatives for [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md) ownership are globals/tables, MapPane, helper owners, aggregate indexes, and no-owner/non-emitting status.

## Snow Lookup Descriptor Storage Disposition

2026-06-28 B009 accepted the empty-emitter implementation for [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md). Keep [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md) routed through this `SnowingLayerPane` file page at `86/90`, but do not emit standalone descriptor-array C++ from the storage page. The formal C++ body is intentionally only:

```cpp
// Emitted code for this local-static descriptor storage is covered by [UID:0003O1] and [UID:0003O3].
```

B009 MCP session `b009_0001Q4_20260628` confirms the storage range is all-zero virtual `.data` backing for two guarded local-static descriptor families, not authored nonzero table bytes. The executable setup belongs to the consuming methods: [UID:0003O3][0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles](by-memory/0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles.md) covers the `0x0069bf98-0x0069bfec` family, and [UID:0003O1][0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles](by-memory/0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles.md) covers the `0x0069bff0-0x0069c044` family. The `g_snowLookupTables` aliases remain documentation/search names, not final standalone globals. This disposition is compatible with this page remaining a dedicated Snowing source-file candidate while [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) remains the broader weather-layer source-family route.

## 2026-07-26 Exact Snow Table And Historical-File Closure

- UID0001OO widens exact snow bytes from the old 76-byte prefix to `[0x00670784,0x006707d4)`. The former four-byte padding page is disproved: those zeros complete the second 16-byte main-view pattern slot immediately before libjpeg text.
- The target-port arrays are unsigned thresholds `{0,50,100,0}`, unsigned sizes `{4,3,0,0}`, and two 16-byte patterns used by UID0003O2/UID0003O3. The byte-identical main-view arrays are used by UID0003O1.
- Both 40-byte families remain distinct physical objects. Their exact duplication and exclusive consumers support the target/main names and reject deduplication, `g_` exports, A/B/C/D globals, or a raw 80-byte blob.
- Current placement is `WeatherLayerPane.cpp` under UID0000P8 at position 1, after exact rain data at position 0. This historical file page records possible original disk partition only and owns no duplicate snow declaration or method body.
- The score rises to `90/89` because the exact table inventory, source declarations, range, and current route are closed. Historical file provenance and shared render/descriptor lexical names remain the bounded confidence cap.

## Cross-References

- [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md)
- [UID:0001O0][0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex](by-memory/0x005c1bd0-0x005c2a5b.SnowingLayerPaneMethodIndex.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md)
- [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- [UID:0001OO][0x00670784-0x006707d4.SnowPatternByteTables](by-memory/0x00670784-0x006707d4.SnowPatternByteTables.md)
- [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md)
- [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md)

## Changes

- 2026-07-26 B002 UID0001OO historical-file callback:
  - Raised `88/86` to `90/89`, retained `NexusTK/map/` and `CANONICAL_OWNER:FILE`, and corrected the current route so UID0001OO emits through UID0000P8 rather than this historical candidate.
  - Added the six exact target/main array names/shapes, 80-byte boundary correction, consumer split, physical-duplication rule, and the resolved UID0003O2 table dependency.
  - Preserved the dedicated Snowing file hypothesis and descriptor-storage evidence as historical/support context without duplicating current source.
- 2026-07-24 Agent-B005 UID0003O0 historical-file callback:
  - Kept metadata `88/86`, projected `NexusTK/map/` path, and `CANONICAL_OWNER:FILE` unchanged.
  - Added exact constructor/object/particle/state/helper/padding/compiler facts while keeping the actual body on UID0003O0 through the current UID0000P8 route.
  - Reclassified this dedicated file as historical provenance, closed stale inherited-field/current-route blockers, and preserved the separately owned UID0003O2 body and remaining method-specific questions.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `86` and confidence to `80`.
- Evidence: document captures weather-layer role, proposed contents, method families, constructor/vtable evidence, global table refs, boundary notes, thunk ownership caveats, and cross-references; confidence remains capped by final split between a standalone snow file and shared `WeatherLayerPane`.
- 2026-06-02 source-path update: `PROPOSED_RECONSTRUCTION_PATH` set to `NexusTK/map/`, matching current proposed source tree placement for map weather companion modules.
- 2026-06-06 provenance cleanup: removed stale generated-output framing and kept scores unchanged. The page now anchors ownership cautions to IDA/by-* evidence, the shared Snowing/Swallow island, and provisional alias status while final file split remains unresolved.
- 2026-06-13 Agent-A001 Goal 2 refresh:
  - Before: `COMPLETION:86`, `CONFIDENCE:80`.
  - After: `COMPLETION:88`, `CONFIDENCE:86`.
  - Summary/evidence: added exact split-child links, corrected destructor endpoint evidence, current IDA `lookup_funcs` sizes, and clarified that the old broad Snowing range is a non-contiguous method index crossing Swallow code. Confidence remains below final-audit quality because the final standalone `SnowingLayerPane.cpp` versus shared weather-family split and several render/global aliases are still open.
- 2026-06-23 B003 randomize MCP-backed source-quality sync:
  - Metadata unchanged.
  - Summary/evidence: added report-level [UID:0003O2][0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles](by-memory/0x005c1f50-0x005c20d4.SnowingLayerPaneRandomizeSnowParticles.md) facts from accepted MCP session `b880584f` while preserving this page as a dedicated candidate rather than a forced method route.
- 2026-06-28 B009 SnowLookupDescriptorStorage empty-emitter sync:
  - Metadata unchanged.
  - Summary/evidence: added accepted [UID:0001Q4][0x0069bf98-0x0069c044.SnowLookupDescriptorStorage](by-memory/0x0069bf98-0x0069c044.SnowLookupDescriptorStorage.md) covered-by/no-standalone-emitter disposition from MCP session `b009_0001Q4_20260628`. The descriptor storage stays routed through this Snowing file page, but executable setup belongs to [UID:0003O1][0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles](by-memory/0x005c1c80-0x005c1f4c.SnowingLayerPaneUpdateAndRenderSnowParticles.md) and [UID:0003O3][0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles](by-memory/0x005c20e0-0x005c2228.SnowingLayerPaneRenderSnowParticles.md), and table aliases are not final standalone global declarations.
