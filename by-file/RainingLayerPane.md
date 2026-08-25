*** UID:0000MY | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# RainingLayerPane

## Status

- Confidence: strong for class behavior, map/weather ownership, live function boundaries, vtable refs, exact rain-table consumers, and the current WeatherLayerPane source-family route.
- Proposed module folder: `NexusTK/map/`
- Historical candidate file: `map/RainingLayerPane.cpp`. Current reconstruction routes the rain declarations and class family through [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md); a dedicated physical file remains a secondary historical hypothesis absent PDB/source-path proof.
- Main memory range: exact rain children [UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md), [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md), and [UID:0003PK][0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget](by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md), with [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md) retained as the non-emitting Weather/Rain migration index.
- Evidence basis: live IDA MCP function, caller, vtable, disassembly, and data-ref checks through 2026-06-04.

## File Role

`RainingLayerPane` is the rain weather overlay for the map pane. It derives from `WeatherLayerPane`, configures a three-frame rain animation with a 120-millisecond timer interval, and draws rain streaks plus small/large splash marks from precomputed coordinate tables. It also supports drawing the same rain pattern onto a supplied `GrafPort` target; current evidence does not prove minimap-specific ownership.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `RainingLayerPane` | [UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md), [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md), [UID:0003PK][0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget](by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md) | Rain constructor, map overlay paint, and target-port rain draw. |
| rain coordinate arrays | [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md) | Exact writable file-static `RainStreak`/`RainSplash` arrays for main-view and target-port drawing; emitted through UID0000P8 rather than this dedicated-file candidate. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x005c1410-0x005c145a` | [UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md) | Source-ready no-argument constructor: implicit Weather base construction/compiler vptr transitions, then inherited `m_timerInterval = 120`, `m_frameCount = 3`, and `m_drawOnTarget = true`. |
| `0x005c1460-0x005c180c` | [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md) | Draws main-view rain streaks and splash dots using tables starting at `0x00670528`, `0x006706d8`, and `0x00670730`. |
| `0x005c1810-0x005c1bc7` | [UID:0003PK][0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget](by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md) | Behavior-complete `DrawOnTarget`: Layer supplies a clipped `GrafPort` and two intentionally unused bounds pointers; Rain renders exact 18/7/7 signed target-array loops. |

## Ownership Notes

- 2026-07-22 B005 source-quality closure moves [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md) from this dedicated-file candidate to the stronger contiguous [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) source family. This page remains the detailed class/file candidate and method inventory, but it is not the rain-data emitter.
- Exact rain source declarations are `RainStreak`, `RainSplash`, three `s_targetRain*` arrays, and three `s_rain*` arrays. All are writable, internal-linkage, dimensioned `3x24` or `3x7`, and physically duplicated even where bytes match.
- The first physical family is target-port data because its sole consumer receives a supplied graphics target. Earlier minimap wording is preserved only as a superseded possibility; no caller, string, field, or independent route proves minimap specificity.
- 2026-06-14 A002 live IDA refresh against session `a001_goal2_class_batch`: `server_health` reported `NexusTK.exe` ready at image base `0x400000`; `lookup_funcs` reconfirmed the weather-family starts `0x005c12a0` size `0x101`, `0x005c13b0` size `0x58`, rain constructor `0x005c1410` size `0x4a` / 74 bytes, rain `OnPaint` `0x005c1460` size `0x3ac` / 940 bytes, target-port draw `0x005c1810` size `0x3b7` / 951 bytes, and `MapPane` weather setup `0x0050db50` size `0x163` (Verified with int_convert.py for the noted sizes).
- 2026-06-14 `analyze_component` over `0x005c12a0`, `0x005c13b0`, `0x005c1410`, `0x005c1460`, `0x005c1810`, and `0x0050db50` found the expected internal call graph: rain constructor `0x005c1410 -> 0x005c12a0`, and `MapPane` weather setup `0x0050db50 -> 0x005c1410`. The same component reports `0x0067a764` / [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) shared only by the two rain draw paths, while `word_66DA9C` and `word_66DAA0` are shared by base weather construction and MapPane setup.
- 2026-06-14 `xrefs_to` reconfirmed the six rain table anchors and their exclusive users: target-port tables `0x006702c8`, `0x00670478`, and `0x006704d0` are referenced only from `0x005c1810`, while main-view tables `0x00670528`, `0x006706d8`, and `0x00670730` are referenced only from `0x005c1460`.
- 2026-06-14 `xrefs_to 0x00631220` found the primary rain vtable store at `0x005c1424`; the slot addresses `0x00631264` and `0x00631230` are table cells rather than code-referenced addresses, matching the existing vtable-slot documentation rather than separate data xref roots.
- Numeric evidence used here was verified with IDA `int_convert`: weather-state byte offset `+0x3f0` / 1008, rain constructor size `0x4a` / 74, `OnPaint` size `0x3ac` / 940, target draw size `0x3b7` / 951, frame count `3`, and constructor timer interval `120` / `0x78`.
- `MapPane` weather setup at `0x0050db50-0x0050dcb3` allocates `0x10c` bytes and calls this constructor at `0x0050dc3b` when the weather type selects rain. The same setup function constructs sibling snow (`0x005c1bd0`) and swallow (`0x005c2230`) panes, keeping the family under map/weather ownership.
- The class shares the exact base object size with `WeatherLayerPane` in current metadata, suggesting no extra per-instance fields beyond base animation state.
- Live IDA reports `0x005c1410-0x005c145a`, `0x005c1460-0x005c180c`, and `0x005c1810-0x005c1bc7` as the exact rain constructor, main paint path, and target-port draw path.
- `RainingLayerPane` vtable data is anchored at `0x00631220`; constructor stores are at `0x005c1424` and `0x005c1433`. The target-port draw slot points to `0x005c1810` at `0x00631230`, and the paint slot points to `0x005c1460` at `0x00631264`.
- Main-view rain table refs are `0x00670528 -> 0x005c14d3`, `0x006706d8 -> 0x005c15ad/0x005c1617`, and `0x00670730 -> 0x005c168d/0x005c16f7/0x005c1761/0x005c17ce`.
- Target-port rain table refs are `0x006702c8 -> 0x005c1877`, `0x00670478 -> 0x005c1950/0x005c19bd`, and `0x006704d0 -> 0x005c1a3a/0x005c1aa5/0x005c1b10/0x005c1b7e`.
- Legacy alias metadata for `g_pWeatherState` refers to [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) at `0x0067a764`; rain drawing checks byte `+0x3f0` before drawing, with current refs at `0x005c1476` and `0x005c1814`.
- Project-structure guidance already places `RainingLayerPane.cpp` under `map/`, matching the live constructor ownership path through [UID:0000L3][MapPane](by-file/MapPane.md).

## Cross-References

- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md)
- [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md)
- [UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md)
- [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md)
- [UID:0003PK][0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget](by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md)
- [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)
- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- [UID:0001WJ][WeatherLayerDataLayouts](by-type/by-struct/WeatherLayerDataLayouts.md)
- [UID:0001ON][0x006702c8-0x00670784.RainCoordinateTables](by-memory/0x006702c8-0x00670784.RainCoordinateTables.md)

## Score Rationale

- Completion is `89` because the page records the live weather-family function map, MapPane constructor path, base-constructor relationship, rain vtable/table anchors, exact table-user split, behavior-complete `OnPaint` and `DrawOnTarget` contracts, and the selected cross-page source route.
- Confidence is `91` because live IDA, exact method pages, the class page, rain coordinate table page, and WeatherLayerPane family page agree on behavior and `NexusTK/map/` placement. It remains below final-audit confidence because this page is a secondary dedicated-file hypothesis rather than the current emitter, original physical disk split and lexical spellings remain unproved, canonical headers are not generated, and no rebuild/codegen comparison exists.

## 2026-07-23 UID0003PJ Source-Family Closure

- The dedicated `map/RainingLayerPane.cpp` hypothesis remains historical/secondary. Current canonical emission continues through [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) into `NexusTK/map/WeatherLayerPane.cpp`; no PDB or source-path fact proves a separate original disk file.
- Rain class/source facts are now exact enough for human reconstruction:
  - `RainingLayerPane : public WeatherLayerPane`;
  - exact extent `0x10c`, no Rain-added storage;
  - inherited signed animation fields at `+0xf8/+0xf9/+0xfa`;
  - constructor initializes three frames and a 120 ms interval;
  - declared methods include constructor, `void OnPaint()`, and `void DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *)`.
- [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md) now owns actual behavior-complete C++:
  - fill inherited bounds before gating;
  - direct `g_activeMapPane->m_waitingForLocalPlayerStatus` early return without a null check;
  - color 143 and exact 18/7/7 main-view rain loops;
  - signed `RainStreak`/`RainSplash` fields, exact transform/truncation order, and repeated frame loads;
  - Surface slot-7/1/0 dispatch through `g_pfnFillRect`, `g_pfnDrawLineDelta`, and `g_pfnDrawPixel`.
- Main-view UID0001ON arrays and target-port UID0003PK arrays remain distinct. The target body neither aliases nor merges them.
- Final source requires canonical Pane.h, MapPane.h, Surface.h, and WeatherLayerPane.h. Current generated output lacks those headers, so no standalone compile claim is made and no fake local declarations or offset casts are introduced.
- Score moves from `86/87` to `89/91` for exact Rain behavior, layout, method contracts, and source-family decision. The page remains a historical file hypothesis rather than a physical emitter; actual routing stays with UID0000P8.

## 2026-07-24 UID0003PK Target-Method Closure

- The dedicated `map/RainingLayerPane.cpp` hypothesis remains historical/secondary. Current emission continues through [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) into `NexusTK/map/WeatherLayerPane.cpp`; no PDB, source-path string, or binary boundary proves a separate original disk file.
- [UID:0003PK][0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget](by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md) now owns actual behavior-complete `void RainingLayerPane::DrawOnTarget(GrafPort *, const RectBounds *, const RectBounds *)` source. The stable by-memory filename retains the earlier `DrawRainOnTarget` description, but Pane/Layer virtual-contract evidence proves `DrawOnTarget` as the source-facing method name.
- Exact body evidence is `0x005c1810-0x005c1bc7`, 951 bytes, SHA256 `13AF20BD86C583978C8B2EE099182C61F44C5783A14E8062A60E796558BFCE90`, with sole incoming route through primary Rain vtable cell `0x00631230`. Four preceding and nine trailing `0xcc` bytes preserve exact family boundaries.
- `Layer::RenderRecursive` configures clipping and dispatches the supplied `GrafPort *` plus two `const RectBounds *` through Pane primary slot `+0x10`. Rain intentionally ignores both bounds pointers and does not perform local clipping.
- Runtime behavior is exact: return on nonzero `g_activeMapPane->m_waitingForLocalPlayerStatus` without a null guard; set color 143; draw 18 target streaks, seven two-pixel small splashes, and seven four-pixel large splashes, totaling 18 line-delta and 42 pixel calls.
- Target tables remain physically distinct from byte-identical main-view tables. Signed-short fields, signed frame loads, multiplication/division/truncation order, and repeated `m_currentFrame` reads are preserved. No fill, clip, blend change, restoration, random/frame update, table/object write, alias, bounds check, or defensive behavior is added.
- The exact method page owns the qualified body. This historical file-candidate page does not emit source, duplicate method code, create local support declarations, or hand-author vtable data.
- Metadata remains `89/91`. Target closure removes the last current behavior gap, but this page's historical/noncanonical physical-file status, inferred lexical spellings, missing generated headers, and absent rebuild/codegen identity continue to cap it.

## 2026-07-24 UID0003PI Constructor Source Closure

- [UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md) is now source-ready at `92/94`. Its exact 74-byte body SHA256 is `B302EDA90BEA72A3FA45D2C16C9C6059B3ECE41F29FAFA5024A85986D56BB29E`, with one MapPane call after a `0x10c` allocation, one Weather base-constructor callee, no target-local cleanup, and six-byte successor alignment.
- The three Rain vptr stores are compiler-generated dynamic-type transitions. The human source body contains only inherited `m_timerInterval = 120`, `m_frameCount = 3`, and `m_drawOnTarget = true`; EAX `this` return and the base call remain implicit C++ ABI behavior.
- `Pane+0xf6` is not generic enable/visibility state. Pane clears it; Rain/Snow/Swallow set it; `Layer_UpdateDirtyRegionsRecursive` dispatches virtual `OnPaint` only when it is zero. The preferred positive source spelling is `m_drawOnTarget`, distinct from Pane visibility at `+0xb4`.
- `RainingLayerPane` remains exactly `0x10c` with no added fields. The first two assignments target the inherited Weather tail at `+0xfa/+0xf9`; the third targets the inherited Pane prefix at `+0xf6`.
- The exact constructor body emits through [UID:0000BJ][RainingLayerPane](by-class/RainingLayerPane.md) into canonical [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md). This page continues to preserve `map/RainingLayerPane.cpp` as a historical physical-file hypothesis only and does not duplicate the method formal.
- Historical blank-C++, enabled-state, and unresolved one-file/per-layer conclusions remain provenance from earlier evidence stages. They no longer block UID0003PI source, but this secondary file-candidate page remains `89/91` because its own physical-file identity is not proven.

## Changes

- 2026-07-24 Agent-B003 UID0003PI support sync:
  - Replaced the constructor's generic enabled-flag description with exact source-ready inherited assignments and added body hash, caller/base/ABI, compiler-vptr, direct-target mode, no-added-storage, source-route, and historical-disposition detail.
  - Preserved `89/91`, the historical dedicated-file hypothesis, canonical UID0000P8 route, all OnPaint/DrawOnTarget research, and the no-duplicate-source policy.
- 2026-07-24 B005 UID0003PK implementation callback:
  - Metadata remains `89/91`; historical dedicated-file status and UID0000P8 current route remain unchanged.
  - Corrected the stale score rationale and added exact `DrawOnTarget` name/signature, hash/range/route, caller-managed clipping, 18/7/7 signed target-array behavior, operation-order and negative constraints, and no-duplicate-source disposition.
- 2026-07-22 B005 RainCoordinateTables source-quality callback:
  - Metadata remains `86/87`.
  - Historicalized standalone `RainingLayerPane.cpp` as the secondary physical-file hypothesis and recorded UID0000P8 as the current data/source-family route.
  - Replaced current minimap assertions with target-port semantics and added exact `RainStreak`/`RainSplash`, six-array, dimension, linkage, duplication, and emitter facts while preserving all constructor/method/vtable evidence.
- 2026-06-14 A002 Goal2 by-file refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:84`; the page had the earlier live range/xref pass but did not reflect the newer WeatherLayerPane family refresh or current component-level verification.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:87`, with fresh live IDA function, component, xref, and conversion evidence while preserving the split-file caveat.
  - Evidence: IDA MCP session `a001_goal2_class_batch` reconfirmed weather base/rain/MapPane function sizes, the internal `MapPane -> RainingLayerPane -> WeatherLayerPane` call path, `g_activeMapPane + 0x3f0` weather-state use, six rain-table anchors and exclusive consumers, and the rain vtable store at `0x005c1424`.
- 2026-06-16 B001 child-split link update:
  - Metadata unchanged.
  - Summary/evidence: replaced the broad main memory reference with exact rain child links [UID:0003PI][0x005c1410-0x005c145a.RainingLayerPaneConstructor](by-memory/0x005c1410-0x005c145a.RainingLayerPaneConstructor.md), [UID:0003PJ][0x005c1460-0x005c180c.RainingLayerPaneOnPaint](by-memory/0x005c1460-0x005c180c.RainingLayerPaneOnPaint.md), and [UID:0003PK][0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget](by-memory/0x005c1810-0x005c1bc7.RainingLayerPaneDrawRainOnTarget.md) plus the retained [UID:0001NZ][0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes](by-memory/0x005c12a0-0x005c1bc7.WeatherAndRainingLayerPanes.md) migration-index link.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `78`, confidence `76`.
- Summary/evidence: the page documents rain overlay role, function map, coordinate globals, MapPane constructor evidence, legacy-alias caveats, and cross-references; completion remains moderate because final split from the weather-layer umbrella and raw coordinate table detail need more work.
- 2026-06-04 live IDA and source-path update:
  - What existed before: `COMPLETION:78`, `CONFIDENCE:76`, and a blank `PROPOSED_RECONSTRUCTION_PATH`, with older boundary rows and source-output caveats.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:84`, and `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/"`.
  - Summary/evidence: live IDA confirms exact half-open method ranges, the sole rain constructor call from `MapPane` weather setup, `RainingLayerPane` vtable anchors and slots, main/target rain table refs, active-map-pane weather-state checks, and project-structure placement under `map/`. Final C++ remains blank because the standalone-file versus weather-family split is still below the `95/95` reconstruction bar.
