*** UID:0000OD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SwallowLayerPane

## Status

- Confidence: very strong for the complete Swallow inventory, exact ranges and padding, `0x16c` class layout, all ten retained human-source methods, compiler-only destructor/vtable support, constructor-owned resources, and canonical combined source routing. Original private spellings and the historical one-file-versus-per-layer disk split remain inferred.
- Current reconstruction route: this page is a reviewed, non-emitting historical dedicated-file candidate. The sole current source root is [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), which emits the combined `map/WeatherLayerPane.cpp/.h` family without a duplicate `SwallowLayerPane.cpp`.
- Evidence policy: generated output is a validation target, while current by-memory pages and dated live IDA evidence below remain the behavioral and boundary authority.
- Main memory docs: [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md), [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md), [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md), and [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md)

## File Role

`SwallowLayerPane` is a timed map-weather overlay that loads two `SWALLOW` frames and periodically moves a sprite across the map view. It derives from `WeatherLayerPane`, stores active flight state, direction, position, and two `EPFTileContext` frame records, and uses timer messages `0x100` and `0x101` to start and step flights.

## 2026-08-16 Whole-File Source Closure

This page now preserves the complete inferred Swallow compilation-unit research without acting as a second emitter. Independent code contiguity (`0x005c2230-0x005c2ab5`), vtable/RTTI contiguity (`0x0063133c-0x006313cc`), constructor-only resource literals (`0x006313cc-0x006313fc`), and the existing Weather/Rain/Snow route select the combined [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) family as the narrowest nonduplicating current source root. The dedicated `SwallowLayerPane.cpp` spelling remains a plausible historical physical-file split, but there is no PDB/source-path evidence that justifies emitting it beside the combined file.

The source-bearing method map is exact and complete: constructor [UID:00054K][0x005c2230-0x005c2340.SwallowLayerPaneConstructor](by-memory/0x005c2230-0x005c2340.SwallowLayerPaneConstructor.md), ordinary destructor [UID:00054L][0x005c2340-0x005c235f.SwallowLayerPaneDestructor](by-memory/0x005c2340-0x005c235f.SwallowLayerPaneDestructor.md), `OnPaint` [UID:00054M][0x005c2360-0x005c2423.SwallowLayerPaneOnPaint](by-memory/0x005c2360-0x005c2423.SwallowLayerPaneOnPaint.md), `MoveBy` [UID:00054N][0x005c2430-0x005c24fa.SwallowLayerPaneMoveBy](by-memory/0x005c2430-0x005c24fa.SwallowLayerPaneMoveBy.md), `OnTimer` [UID:00054O][0x005c2500-0x005c26a6.SwallowLayerPaneOnTimer](by-memory/0x005c2500-0x005c26a6.SwallowLayerPaneOnTimer.md), `DrawOnTarget` [UID:00054P][0x005c26b0-0x005c275c.SwallowLayerPaneDrawOnTarget](by-memory/0x005c26b0-0x005c275c.SwallowLayerPaneDrawOnTarget.md), retained `StartSwallowFlight` [UID:00054Q][0x005c2760-0x005c2835.SwallowLayerPaneStartSwallowFlight](by-memory/0x005c2760-0x005c2835.SwallowLayerPaneStartSwallowFlight.md), retained `StepSwallowFlight` [UID:00054R][0x005c2840-0x005c292e.SwallowLayerPaneStepSwallowFlight](by-memory/0x005c2840-0x005c292e.SwallowLayerPaneStepSwallowFlight.md), `InvalidateSwallowRect` [UID:00054S][0x005c2930-0x005c299f.SwallowLayerPaneInvalidateSwallowRect](by-memory/0x005c2930-0x005c299f.SwallowLayerPaneInvalidateSwallowRect.md), and retained `GetCurrentSwallowRect` [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md). The raw starts remain negative route evidence because IDA has no function object/xrefs/pointers for them; that absence does not erase complete retained source bodies whose behavior, field family, local inlining, and neighboring compiler-output pattern are coherent. Exact formal definitions therefore live on the source children and route through [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md) into [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md).

Compiler-only support is intentionally not handwritten: [UID:00054T][0x005c2a02-0x005c2a18.SwallowLayerPaneDestructorAdjustorThunks](by-memory/0x005c2a02-0x005c2a18.SwallowLayerPaneDestructorAdjustorThunks.md) records the two deleting-destructor adjustor thunks, [UID:00054U][0x005c2a60-0x005c2ab5.SwallowLayerPaneScalarDeletingDestructor](by-memory/0x005c2a60-0x005c2ab5.SwallowLayerPaneScalarDeletingDestructor.md) records the scalar deleting destructor, [UID:0002ZA][0x0063133c-0x006313cc.SwallowLayerPaneVtableData](by-memory/0x0063133c-0x006313cc.SwallowLayerPaneVtableData.md) records three vtable views plus RTTI, and [UID:0002ZB][0x006313cc-0x006313fc.SwallowLayerResourceStrings](by-memory/0x006313cc-0x006313fc.SwallowLayerResourceStrings.md) records constructor-covered `L"SWALLOW.EPF"`/`L"SWALLOW.EPD"` literals. The eleven exact `0xcc` gaps are compiler alignment recorded in [UID:0000VN][-ignored](by-memory/-ignored.md). The overlapping indexes [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md) and [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md) preserve range/history/evidence but emit no duplicate source.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `SwallowLayerPane` | `0x005c2230-0x005c299f`, `0x005c29a0-0x005c29ec`, `0x005c2a02-0x005c2ab5` | Ten human-source methods plus compiler-only thunk/scalar-destructor support, split across exact children and routed through the combined Weather source family. |
| `SWALLOW.EPF` / `SWALLOW.EPD` resources | constructor strings and `g_useEpfAssets` branch | Right/left sprite frames for the overlay. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x005c2230-0x005c2340` | constructor | Calls `WeatherLayerPane`, initializes flight state, loads two `SWALLOW` frames, and schedules the first start timer. |
| `0x005c2340-0x005c235f` | non-deleting destructor | IDA-confirmed real function; current simroot emits it under `SwallowLayerPane`. |
| `0x005c2360-0x005c2423` | `OnPaint` | Clears/refreshes the pane region and draws the current sprite when active. |
| `0x005c2430-0x005c24fa` | `MoveBy` | Invalidates old and new sprite rectangles while adjusting position. |
| `0x005c2500-0x005c26a6` | `OnTimer` | Dispatches timer IDs `0x100`/`0x101` to start/step behavior and returns true for every timer ID. |
| `0x005c26b0-0x005c275c` | `DrawOnTarget` | Draws the active direction-selected sprite to the supplied port and intentionally does not use the two bounds arguments. |
| `0x005c2760-0x005c2835` | `StartSwallowFlight` | Retained private source body: activates flight, chooses direction, seeds the matching horizontal edge and random Y, invalidates, and schedules timer `0x101` after 10 ms. Its no-function/no-route evidence remains documented. |
| `0x005c2840-0x005c292e` | `StepSwallowFlight` | Retained private source body: invalidates, advances by `10 * direction`, stops beyond the relevant bound with randomized `10000..49999` ms restart, or invalidates and rearms the 10 ms step timer. |
| `0x005c2930-0x005c299f` | `InvalidateSwallowRect` | IDA-confirmed helper with modeled/raw callers; builds the current frame rectangle and invokes virtual invalidation. |
| `0x005c29a0-0x005c29ec` | `GetCurrentSwallowRect` | Retained private source body that copies the direction-selected frame bounds and offsets by current X/Y. MCP session `0b5e057e` proves the exact endpoint and negative route evidence; current source reconstruction uses the best-supported `RectBounds *` contract. |
| `0x005c2a02-0x005c2a17` | adjustor thunks | Real thunk starts; `0x005c2a0d` is missing from disabled generated output. |
| `0x005c2a60-0x005c2ab5` | scalar deleting destructor | Resets vtables, tears down base pane state, and conditionally deletes storage. |

## Live IDA Evidence

2026-06-06 MCP checks confirm the modeled Swallow method island remains stable:

- `lookup_funcs` reports exact functions at `0x005c2230` (`0x110` bytes), `0x005c2340` (`0x1f`), `0x005c2360` (`0xc3`), `0x005c2430` (`0xca`), `0x005c2500` (`0x1a6`), `0x005c26b0` (`0xac`), `0x005c2930` (`0x6f`), thunks `0x005c2a02`/`0x005c2a0d` (`0xb` each), and scalar deleting destructor `0x005c2a60` (`0x55`).
- `lookup_funcs` still reports `0x005c2760` and `0x005c2840` as `Not a function`, and `xrefs_to` reports no references to either raw helper start.
- The constructor has a single direct caller at `0x0050dbf3` inside the map-state setup function and calls the base weather-layer constructor at `0x005c12a0`, timer scheduler `0x005975e0`, frame initializer `0x00457a60`, and resource-layout lookup `0x004d02f0`.
- Constructor decompilation installs three Swallow vtable pointers, initializes active/position/direction fields at `+0x10c/+0x110/+0x114/+0x118`, initializes two frame records at `+0x11c/+0x144`, chooses the `SWALLOW` resource table through `g_useEpfAssets`, and schedules timer id `0x100`.
- `OnTimer` handles ids `0x100` and `0x101`, chooses direction with `rand()`, uses inherited [UID:000161][0x004b8e00-0x004b8e11.GrafPortGetBounds](by-memory/0x004b8e00-0x004b8e11.GrafPortGetBounds.md) for bounds, translates/invalidate rectangles through `0x004b78f0` plus virtual slot `+0x20`, advances X by `direction * 10`, schedules 10 ms step ticks, and schedules restart delay `10000 + rand() % 40000` after leaving bounds. Historical BackPane ownership of the shared accessor is superseded; this remains a SwallowLayerPane consumer.
- `xrefs_to 0x005c2930` reports the modeled timer caller at `0x005c25e2` and a raw-code caller at `0x005c291d`; the helper decompilation computes the active frame rectangle from direction/position and invalidates it.
- Vtable data xrefs point to `OnPaint` (`0x00631384`), `MoveBy` (`0x00631388`), `OnTimer` (`0x006313c8`), `DrawOnTarget` (`0x00631350`), adjustor thunks (`0x00631394`/`0x006313c4`), and scalar deleting destructor (`0x00631340`). The thunks at `0x005c2a02` and `0x005c2a0d` both forward to `0x005c2a60`.
- Scalar deleting destructor decompilation reinstalls the three Swallow vtable pointers, calls the base cleanup at `0x00544580`, and conditionally frees storage through `0x004f4ac0`.
- 2026-06-16 A001 active-IDB refresh on `b001_mappane_0001AW_20260616` reconfirmed the same modeled starts and sizes, including constructor `0x005c2230` size `0x110`, timer handler `0x005c2500` size `0x1a6`, current-rect helper `0x005c2930` size `0x6f`, thunks `0x005c2a02`/`0x005c2a0d` size `0xb`, and scalar deleting destructor `0x005c2a60` size `0x55`.
- The same pass still reports `0x005c2760` and `0x005c2840` as not functions with zero `xrefs_to` results; `0x005c2930` has exactly two refs, the modeled timer caller at `0x005c25e2` and the raw-code caller at `0x005c291d`.
- Historical 2026-06-16 A001 pointer-byte scans for absolute VA encodings `60 27 5C 00` and `40 28 5C 00` returned zero matches, matching [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md)'s source-placement/liveness review. That pass treated absent caller/pointer routes as a final-C++ blocker. The 2026-08-16 whole-file audit supersedes that source-output conclusion: the negative route evidence remains valid, but complete source-shaped bodies, exact Swallow field use, local inlining, and the neighboring retained-method pattern support `StartSwallowFlight` and `StepSwallowFlight` as emitted exact children.
- Constructor-only `SWALLOW.EPF` and `SWALLOW.EPD` literal refs at `0x006313cc`/`0x006313e4`, vtable store refs at `0x00631340`/`0x00631394`/`0x006313c4`, and the single constructor caller from `0x0050dbf3` keep the source root under the map weather family. [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md) remains the family anchor; the separate `map/SwallowLayerPane.cpp` projected path stays plausible but not final-audit proven.
- 2026-06-17 B002 source-quality reanalysis corrected [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md)'s half-open end to `0x005c299f` and split the adjacent raw rectangle-builder evidence into [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md). The 2026-06-23 B002 MCP-backed accepted implementation corrected that child from stale endpoint `0x005c29ea` to `0x005c29ec`: MCP session `0b5e057e` `lookup_funcs` reports no function at the raw start and successor `sub_5C29EC` at `0x005c29ec`; `get_bytes`/`disasm` shows `0x005c29e9: retn 4` consumes bytes through `0x005c29eb`, so `0x005c29ea-0x005c29ec` is not padding. The accepted current source names are `InvalidateSwallowRect` and `GetCurrentSwallowRect`; both exact children emit their retained source while preserving the original no-route evidence.
- Historical 2026-06-27 B011 source-quality implementation for [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md) raised that child to `87/90` and replaced plain blank C++ with a formal no-standalone-emission marker covered by [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md). MCP session `b001_000241_20260627` reported no function objects or xrefs at `0x005c2760`/`0x005c2840`, exact alignment at `0x005c2835` and `0x005c292e`, decompile failure at both raw starts, no VA/RVA pointer route, no Swallow vtable slot, no confirmed external direct-transfer route, and unique body prefixes. The 2026-08-16 whole-file audit supersedes only that no-emission conclusion: `OnTimer` contains the inlined live path, while exact children UID00054Q and UID00054R retain complete `StartSwallowFlight` and `StepSwallowFlight` source bodies.

## Historical Data Caveats Superseded By 2026-08-16

- Current generated output now emits the real non-deleting destructor at `0x005c2340` and helper at `0x005c2930`; older notes that called those omitted are stale.
- Active generated BackPane output still emits `0x005c2760` and `0x005c2840` as BackPane scroll-animation methods. IDA raw disassembly and field usage tie them to `SwallowLayerPane`, not `BackPane`.
- The 2026-06-27 B011 disposition intentionally kept [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md) unsplit and marker-only because both raw bodies shared no-route evidence. The 2026-08-16 whole-file audit supersedes only that source-output decision: exact children [UID:00054Q][0x005c2760-0x005c2835.SwallowLayerPaneStartSwallowFlight](by-memory/0x005c2760-0x005c2835.SwallowLayerPaneStartSwallowFlight.md) and [UID:00054R][0x005c2840-0x005c292e.SwallowLayerPaneStepSwallowFlight](by-memory/0x005c2840-0x005c292e.SwallowLayerPaneStepSwallowFlight.md) now emit the retained source while UID0001O3 remains a non-emitting evidence index.
- The adjacent raw `0x005c29a0-0x005c29ec` helper uses Swallow direction/position/frame-rect state: it reads direction `+0x118`, selects frame-rect fields at `+0x12c` or `+0x154`, copies the 16-byte rect to the caller output pointer, and offsets it through `0x004b78f0` using current X/Y at `+0x110/+0x114`. MCP `decompile 0x005c2930` and `decompile 0x005c2500` corroborate the same Swallow field family in modeled live code. The old ownership-but-no-emission conclusion is superseded by exact source child [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md).
- 2026-05-24 MCP recheck still reports `0x005c2760` and `0x005c2840` as `Not a function`. Keep them as raw/orphan Swallow helper bodies unless later boundary recovery creates function objects or xrefs.
- 2026-05-24 IDA recheck ties `SwallowLayerPane` construction to `MapPane::SetMapState` at `0x0050dbf3`; vtable refs point at `OnPaint` (`0x00631384`), `MoveBy` (`0x00631388`), `OnTimerEvent` (`0x006313c8`), `DrawSwallow` (`0x00631350`), and the scalar deleting destructor (`0x00631340`).
- The adjacent destructor tail is interleaved with [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md): Snowing owns `0x005c29ec`, `0x005c29f7`, and `0x005c2a20`, while Swallow owns `0x005c2a02`, `0x005c2a0d`, and `0x005c2a60`.
- The `0x005c29ec` Snowing ownership starts exactly after the raw rect helper. B002 found the nearby pointer to `0x005c29ec` is Snowing thunk data, not a pointer route to the Swallow raw helper.
- For [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md), B002 MCP session `0b5e057e` found no IDA function object, target decompile failure, `callees 0x005c29a0` returning `No function found`, zero xrefs, no pointer/table/vtable route, and a unique body prefix. That remains important negative evidence. BackPane, Snowing, base Weather direct-method, padding/ignored, and compiler-artifact alternatives remain rejected; the later retained-source decision does not erase those checks.
- `GetCurrentSwallowRect` remains an inferred source-facing name rather than symbol proof. `RectBounds *` is selected because the exact project-local bounds operations and surrounding methods use that type; the confidence score preserves the remaining original-spelling uncertainty.
- The generated method row at `0x00570053` is not an IDA function start. IDA resolves that address inside `0x00570030`, whose decompilation is unrelated `SelfLookPane2`-style destructor code.
- Disabled generated output marks `0x005c2a0d` as missing code even though IDA confirms it is a real `0xb` thunk.

## Cross-References

- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- [UID:0000E9][SwallowLayerPane](by-class/SwallowLayerPane.md)
- [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md)
- [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md)
- [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md)
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
- 2026-06-06 A006 live-IDA evidence refresh:
  - Changed to: completion `87`, confidence `84`.
  - Evidence: live MCP `lookup_funcs`, `callers`, `callees`, `xrefs_to`, and decompilation checks confirmed the modeled function sizes, single constructor call-in, timer/resource/helper callees, vtable refs, raw-helper non-function status, `0x005c2930` modeled/raw callers, and scalar-deleting destructor behavior. Confidence remains below final-audit level because the raw helper liveness and final standalone-vs-weather-family source split are still open.
- 2026-06-16 A001 Goal 2 file-confidence refresh:
  - Changed to: completion `88`, confidence `86`.
  - Evidence: active IDB `lookup_funcs`/`xrefs_to` reconfirmed all modeled Swallow starts, raw-helper non-function and no-xref status, `0x005c2930` modeled/raw callers, vtable/resource refs, and the single MapPane weather setup constructor caller. A001 absolute pointer scans found no VA pointers to `0x005c2760` or `0x005c2840`. Scores remain below final-source quality because raw-helper liveness and the final separate-file versus weather-family split are still real blockers.
- 2026-06-17 B002 source-quality sync:
  - Metadata unchanged.
  - Summary/evidence: synced the corrected [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md) half-open end `0x005c299f`, added [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md) for the adjacent no-xref raw rect helper, documented source-facing helper/field names, and preserved the final file-family caveat.
- 2026-06-23 B002 MCP-backed raw-rect endpoint correction:
  - Metadata unchanged.
  - Summary/evidence: corrected [UID:0003YQ][0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper](by-memory/0x005c29a0-0x005c29ec.SwallowLayerPaneRawRectHelper.md) from stale `0x005c29a0-0x005c29ea` to `0x005c29a0-0x005c29ec` using accepted MCP session `0b5e057e`; `lookup_funcs` reports no function at the raw start and `sub_5C29EC` at successor `0x005c29ec`, while `get_bytes`/`disasm` shows the `retn 4` at `0x005c29e9` consumes bytes through `0x005c29eb`, with the Snowing thunk starting at `0x005c29ec`. Preserved Swallow ownership, weather-family source-placement caveat, no-code proof, target decompile failure, no xrefs/raw-start pointer/vtable route, pointer-to-`0x005c29ec` Snowing-thunk caveat, BackPane/Snowing/base Weather rejection, padding/ignored and forced-C++ rejection, and `RectBounds`/`RECT` type uncertainty.
- 2026-06-27 B011 raw flight-helper marker sync:
  - Metadata unchanged.
  - Summary/evidence: synced [UID:0001O3][0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers](by-memory/0x005c2760-0x005c292e.SwallowLayerPaneRawFlightHelpers.md)'s accepted no-split/no-standalone-emission disposition. Current MCP session `b001_000241_20260627` confirms no function/xref/pointer/vtable/direct-transfer route for the raw start and step helpers, exact padding at the subrange boundaries, raw call into `0x005c2930`, and modeled [UID:0001O2][0x005c2230-0x005c299f.SwallowLayerPaneCore](by-memory/0x005c2230-0x005c299f.SwallowLayerPaneCore.md) `OnTimerEvent` coverage for the live timer behavior. Preserved generated BackPane pollution rejection and inferred-only `StartSwallowFlight`/`StepSwallowFlight` names.
