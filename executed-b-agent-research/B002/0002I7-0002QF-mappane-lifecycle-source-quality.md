** TARGET-REPORT-UID:0002I7 **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002I7 / 0002QF MapPane Lifecycle Source-Quality Research

Assignment: `B002-goal2-mappane-lifecycle-source-quality-0002I7-0002QF-20260617`

Report-only target file requested by the supervisor run:
`source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/0002I7-0002QF-mappane-lifecycle-source-quality.md`

## Finalized Report / Current Recommendation

This pass should treat both targets as source-reconstructable `MapPane` lifecycle methods:

| UID | Range | Current name | Recommended source placement | Current score | Recommended score |
| --- | --- | --- | --- | ---: | ---: |
| `0002I7` | `0x00504110-0x00504521` | `MapPaneInitialize` | ordinary `MapPane::MapPane(int visibleTileColumns, int visibleTileRows)` body in [UID:0000L3] `by-file/MapPane.md` / [UID:00007Q] `by-class/MapPane.md` | `84/88` | `88/89` |
| `0002QF` | `0x00504530-0x005046c6` | `MapPaneCleanup` | ordinary non-deleting `MapPane::~MapPane()` body in [UID:0000L3] / [UID:00007Q] | `84/88` | `88/90` |

Metadata should remain:

| UID | `CANONICAL_OWNER` | `RECONSTRUCTABLE` | `EMITTER_UIDS` | C++ gate status |
| --- | --- | --- | --- | --- |
| `0002I7` | `00007Q` | `TRUE` | `00007Q` | Eligible under the active gate: avg `(88+89)/2 = 88.5`, valid MapPane file route. |
| `0002QF` | `00007Q` | `TRUE` | `00007Q` | Eligible under the active gate: avg `(88+90)/2 = 89`, valid MapPane file route. |

The old target-page language that leaves first-draft C++ blank because the rows were below an older `95/95` threshold is stale under the active supervisor policy. Both rows now meet the active C++ gate. The supervisor can populate source-level first-draft C++ after accepting the field names and artifact split below.

## Supporting Research

I read and applied:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B002/goal.md`
- `source-3/project-documentation/tools/leaser/Agents/Supervisor.md`
- `source-3/project-documentation/inference_research.md`
- `source-3/project-documentation/by-structure.md`

Primary and support documentation checked:

- [UID:0002I7] `by-memory/0x00504110-0x00504521.MapPaneInitialize.md`
- [UID:0002QF] `by-memory/0x00504530-0x005046c6.MapPaneCleanup.md`
- [UID:00007Q] `by-class/MapPane.md`
- [UID:0000L3] `by-file/MapPane.md`
- [UID:0001AP] `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
- [UID:0001AW] `by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md`
- [UID:0001AO] `by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md`
- [UID:0002I6] `by-memory/0x005040a0-0x00504102.MapPaneClearEffectList.md`
- [UID:0002QK] `by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md`
- [UID:0002SQ] `by-memory/0x0061e71c-0x0061e7a0.MapPaneVtableData.md`
- [UID:0003M4] `by-memory/0x00514de0-0x00514e1b.MapPaneScalarDeletingDestructor.md`
- [UID:0003M3] `by-memory/0x00514d1e-0x00514d34.MapPaneDestructorAdjustorThunks.md`
- [UID:000160] `by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md`
- [UID:000161] `by-memory/0x004ab580-0x004ab5a8.BackPaneGetBounds.md`
- [UID:00009Q] `by-class/ObjectList.md`
- [UID:0000M4] `by-file/ObjectList.md`
- [UID:0001D1] `by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md`
- [UID:0002JT] `by-memory/0x00531260-0x00531473.ObjectListDestructor.md`
- [UID:0001D3] `by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md`
- [UID:0000PR] `by-global/g_activeMapPane.md`
- [UID:0000Q3] `by-global/g_objectNationMap.md`
- [UID:0000Q4] `by-global/g_objectRecordCount.md`
- [UID:0000Q1] `by-global/g_gameServerNationTable.md`
- [UID:0000T7] `by-global/MapTilePixelDimensions.md`
- [UID:0000JP] `by-file/GameServerConfig.md`
- [UID:00005O] `by-class/GameServerConfig.md`
- [UID:0001RL] `by-resource/sobj-tbl.md`
- [UID:0001IB] `by-memory/0x0057b020-0x0057b48a.SoundManagerRedbookPlayback.md`
- [UID:00028R] `by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md`
- [UID:0001OX] `by-memory/0x0067a7cc-0x0067a7d0.g_pScreenPane.md`
- generated `auto-generated/NexusTK/map/MapPane.cpp`
- current `by-memory/-coverage-report.md` target rows through text search
- related B002 executed reports, especially `0002I2-mappane-find-active-effect-source-quality.md`

## Target

Primary target [UID:0002I7] covers `0x00504110-0x00504521`. The current page calls it `MapPaneInitialize`, scores it `84/88`, attaches it to [UID:00007Q] `MapPane`, marks it reconstructable, and leaves C++ blank. The documented behavior is a constructor-shaped body: it calls the pane/base constructor path, writes `g_activeMapPane`, installs MapPane primary and adjusted vtables, constructs an inline 32-entry member array at `this+0x118`, constructs an embedded `GrafPort`-style subobject at `this+0x428`, clears viewport/object/effect state, sizes backing map bounds from tile globals, loads the compact `SOBJ.TBL` object-nation map, registers with the root/back pane using tag `1735356263`, allocates the overlay surface, allocates the game-server nation table object, and clears later state flags.

Primary target [UID:0002QF] covers `0x00504530-0x005046c6`. The current page calls it `MapPaneCleanup`, scores it `84/88`, attaches it to [UID:00007Q], marks it reconstructable, and leaves C++ blank. The documented behavior is a non-deleting destructor body plus compiler-emitted teardown: it reseats MapPane vtables, clears effecters through [UID:0002I6], unregisters the listener tag, saves the compressed map via [UID:0002QK], tears down optional child/list/layer state, frees the compact `SOBJ.TBL` cache, deletes overlay and nation-table globals, calls the sound Redbook close helper, destroys embedded/member subobjects, clears `g_activeMapPane`, and falls through base pane cleanup.

## Executive Recommendation

1. Rename or describe `0002I7` as `MapPane::MapPane` rather than a generic initializer or `GameServerConfig` helper. The best defensible signature is:

   ```cpp
   MapPane::MapPane(int visibleTileColumns, int visibleTileRows);
   ```

   Evidence: the function has constructor-only artifacts (base construction, vtable stores, member constructors), publishes `g_activeMapPane`, and stores the two incoming visible tile dimensions into the `this+0x404` / `this+0x408` family. Existing docs record callers from two `InitializeMainUiGraph` construction sites. Prior by-memory report evidence says `+0x404` is visible tile width and `+0x408` is visible tile height in the constructor's height/width buffer convention.

2. Rename or describe `0002QF` as `MapPane::~MapPane`, not a free cleanup helper. The best defensible source signature is:

   ```cpp
   MapPane::~MapPane();
   ```

   Evidence: the only direct caller is [UID:0003M4] `MapPaneScalarDeletingDestructor` at `0x00514de0-0x00514e1b`, and [UID:0002SQ] records MapPane vtable destructor slots pointing through that scalar deleting destructor and adjusted destructor thunks. The body contains normal destructor vtable reseating, source-authored resource cleanup, member destructor calls, and final base cleanup.

3. Keep both targets owned by [UID:00007Q] / [UID:0000L3]. Do not migrate either target to `GameServerConfig`. The constructor allocates and seeds a `GameServerConfig`/nation-table helper, but its dominant source body is MapPane lifecycle and map-state initialization.

4. Update first-draft C++ in both target pages. The active gate is no longer the old `95/95` standard. Both targets are reconstructable, have nonblank emitters, route to `NexusTK/map/MapPane.cpp`, and average above 85 after this pass.

5. Keep mixed aggregate pages as support indices. [UID:0001AO] should remain `RECONSTRUCTABLE:FALSE` because it spans GameServerConfig methods plus MapPane lifecycle/effect helpers. [UID:0001AP] can continue to aggregate MapPane weather/coordinate/object core, but its target rows should no longer cite unresolved source placement for the constructor/destructor.

## Supervisor Active Recheck

Active C++ gate from `by-structure.md` is:

- `RECONSTRUCTABLE:TRUE`
- nonblank `EMITTER_UIDS`
- valid file-route chain
- average `(COMPLETION + CONFIDENCE) / 2 > 85`

The two target rows already had reconstructable `TRUE`, `EMITTER_UIDS:00007Q`, and a valid route through [UID:00007Q] `MapPane` to [UID:0000L3] `MapPane.cpp`. This pass raises the evidence recommendation rather than changing ownership.

| UID | Recommended completion | Recommended confidence | Average | Gate result |
| --- | ---: | ---: | ---: | --- |
| `0002I7` | `88` | `89` | `88.5` | clears |
| `0002QF` | `88` | `90` | `89` | clears |

## Inference Research Guidance Check

Rule 26 requires more than "enough detail." I did not stop at source-placement summary. The reanalysis below separately addresses constructor/destructor identity, compiler artifacts, fields, globals, `SOBJ.TBL`, `GameServerConfig`, optional teardown roles, ObjectList naming, helper `0x0057b160`, mixed aggregate staleness, C++ emission, score changes, and coverage-row text.

No live IDA MCP was available in this session. A direct local MCP probe to `http://127.0.0.1:13337/mcp` failed with "Unable to connect to the remote server", and MCP resource/template listings were empty. The report therefore relies on existing live-IDA-backed documentation and generated cross-reference docs. This lowers confidence ceiling slightly; I am not recommending final-audit-level scores.

## Heuristic / Inference Reanalysis And Validation

### Constructor Or Lifecycle Helper

Best inference: [UID:0002I7] is the ordinary `MapPane` constructor body.

Evidence accepted:

- The body calls the pane/base constructor path at entry.
- It writes `this` to `g_activeMapPane` at the constructor-publish site documented by [UID:0000PR].
- [UID:0002SQ] records MapPane vtable stores in this target at `0x0050418b`, `0x00504191`, and `0x0050419b`.
- It constructs member subobjects: a fixed 32-entry `0x14`-byte array at `this+0x118` and an embedded `GrafPort`-style object at `this+0x428`.
- It initializes many `this` fields to first-use values and allocates owned `MapPane` resources.
- It has only construction-site callers from `InitializeMainUiGraph`, matching the creation of the live gameplay pane.

Rejected alternatives:

- `GameServerConfig::InitializeMapPane`: rejected. The function allocates `g_gameServerNationTable`, but the object under construction is a `MapPane`, not a `GameServerConfig`. Vtables, `g_activeMapPane`, viewport fields, overlay allocation, and effecter-list state are MapPane-local.
- Free function `InitializeMapPane(MapPane*)`: possible as a decompiler surface name, but lower probability than constructor because base/member construction and vtable writes are compiler constructor artifacts.
- A "lifecycle helper" called after construction: rejected because of explicit base/member construction and primary/adjusted vtable installation.

Recommended signature:

```cpp
MapPane::MapPane(int visibleTileColumns, int visibleTileRows);
```

The parameter names are inferred. Existing docs prove two tile-count-like inputs and record storage into `this+0x404` / `this+0x408`; they do not prove the original names. Use these source names unless a later MainUiGraph source-quality pass proves a different convention.

### Destructor Or Cleanup Helper

Best inference: [UID:0002QF] is the ordinary non-deleting `MapPane` destructor body.

Evidence accepted:

- [UID:0003M4] `MapPaneScalarDeletingDestructor` has the only direct call to `0x00504530` and then conditionally deletes storage.
- [UID:0002SQ] records destructor vtable data and adjusted destructor thunks for secondary views.
- The target body reseats MapPane vtables before cleanup, which is standard MSVC destructor codegen.
- The body executes source-authored resource cleanup, then compiler-emitted member/base teardown.
- It clears `g_activeMapPane` after owned resource cleanup, matching singleton lifetime.

Rejected alternatives:

- Free `MapPaneCleanup(MapPane*)`: rejected as the primary source shape because scalar deleting destructor and vtable rows prove destructor dispatch.
- Helper called by a destructor body: possible only as a compiler/decompiler factoring, but unsupported by the documented direct xrefs. The body itself contains destructor artifacts and should be modeled as the destructor.

Recommended signature:

```cpp
MapPane::~MapPane();
```

### Compiler Artifacts Versus Source-Owned Work

These should be represented by C++ declarations/initializer lists/destructor semantics, not by explicit source statements:

| Binary behavior | Source interpretation | Emit in source body? |
| --- | --- | --- |
| Constructor MapPane vtable stores | compiler artifact from constructing `MapPane` with primary and adjusted bases/interfaces | no |
| Destructor MapPane vtable reseats | compiler artifact from entering `MapPane::~MapPane` | no |
| Base pane constructor call | `MapPane` derives from the pane/base class | initializer list or class declaration, not manual call |
| Final base pane cleanup in destructor | implicit base destructor | no explicit call |
| `this+0x118` vector/array construction and destruction | fixed member array declaration | prefer member declaration and initializer; do not manually loop destructors in formal destructor body |
| `this+0x428` `GrafPort` construction/destruction | embedded `GrafPort` member | prefer member declaration and initializer; do not manually call `~GrafPort()` in formal destructor body |
| Scalar deleting destructor wrapper | compiler-generated deleting destructor thunk | separate [UID:0003M4], not part of source destructor body |
| Adjustor thunks | compiler-generated secondary-base/interface destructor thunks | separate [UID:0003M3], not source-authored |

Source-authored constructor work should still initialize and allocate MapPane state: singleton publish, viewport/tile fields, compact SOBJ cache, root registration, overlay allocation, nation-table allocation, and effecter-list clears. Source-authored destructor work should clear effecters, unregister, save map cache, tear down optional child/layer/list/global resources, close Redbook music through `SoundManager`, delete globals, and clear `g_activeMapPane`.

### Field And State Inferences

Recommended field names or source roles:

| Offset/family | Recommended source name | Confidence | Evidence and impact |
| --- | --- | --- | --- |
| `this+0xf8` | `m_screenEffecterCount` | high | [UID:0002I2] and [UID:0002I6] B002 evidence. Count used to scan/clear `ScreenEffecter*` entries. |
| `this+0xfc` | `m_screenEffecterCapacity` | high | [UID:0002I6] clears capacity with count and pointer after deleting effecters. |
| `this+0x100` | `m_screenEffecters` | high | [UID:0002I2] emitted C++ already uses `ScreenEffecter **` semantics. |
| `this+0x118` array of 32 entries, entry size `0x14` | `m_layerStates` or `m_mapLayerStates` | medium-low | Constructor/destructor prove a fixed source-owned member array. Exact original element type/name is not defensibly recoverable from the checked docs alone. It is not an ObjectList and not the `ScreenEffecter*` list. Recommend descriptive field declaration until render-layer docs can name it. This residual uncertainty is why `0002I7` / `0002QF` should not jump above `90` completion. |
| `this+0x3e0` | `m_selectionOverlay` | medium-high | Constructor allocates `0x28` AlphaMaskSurface-style overlay from root/back-pane bounds; destructor deletes it. Existing pages call it selection/overlay. |
| `this+0x3f2` | `m_mapId` | high | [UID:0002QK] uses it for `TK%06d.cmp`. |
| `this+0x3f4` | `m_mapWidth` | medium-high | [UID:0002QK] compressed map save uses width/height family. |
| `this+0x3f6` | `m_mapHeight` | medium-high | Same as above. |
| `this+0x3f8` | `m_tileBuffer` or `m_uncompressedTileBuffer` | high | [UID:0002QK] saves compressed local map cache from this owned buffer. |
| `this+0x404` | `m_visibleTileColumns` | medium-high | Target and old report evidence record constructor input storage; old evidence says `+0x404` is visible tile width. |
| `this+0x408` | `m_visibleTileRows` | medium-high | Target and old report evidence record constructor input storage; old evidence says `+0x408` is visible tile height. |
| `this+0x40e` family | `m_movementGate` / `m_viewportMoveGate` | medium-low | Coordinate/movement docs mention a movement gate byte. Exact source name remains unproven; keep descriptive and local. |
| `this+0x418` | `m_objectListDetachPreserve` | low-medium | Target cleanup and ObjectList docs mention companion list state passed through ObjectList detach/access cleanup. Best source role is a preserved/current object-list node or pane used during teardown. Exact name should remain marked provisional. |
| `this+0x41c` | `m_auxiliaryPane` | medium-low | Destructor destroys an optional child pane/object. No checked support doc proves the original UI role. |
| `this+0x420` | `m_activeScreenLayer` | medium | Destructor removes it from `ScreenPane` layer state before virtual cleanup. Weather-layer docs make a weather/overlay role plausible, but exact source name is not proven. |
| `this+0x424` | `m_objectList` | high | [UID:00009Q], [UID:0000M4], [UID:0001D1], [UID:0001D3], and target cleanup all support `ObjectList*`. |
| `this+0x428` | `m_viewportGrafPort` | medium-high | Embedded `GrafPort` member constructed/destructed by lifecycle targets; implementation belongs to [UID:000160]. |
| `this+0x4c8` family | `m_mapRuntimeState` / map-light/weather/fog state | medium-low | Constructor clears later map-state fields; packet/weather docs own detailed semantics. Not a source-placement blocker for constructor/destructor. |
| `this+0x90c` / `this+0x90e` bytes | `m_runtimeFlags` members | medium-low | Constructor clears byte flags; no checked support page proves exact names. Treat as MapPane-owned runtime flags, not globals. |

Field unresolved-status audit:

- No compiler/generated name remains uninvestigated: vtable, scalar deleting destructor, adjustor thunks, base destructor, and member destructors are identified as compiler artifacts.
- No helper remains uninvestigated: `0x0057b160` is resolved below as `SoundManager::CloseRedbookDevice`.
- No type/field blocker prevents first-draft C++: the only low-confidence field names are local member names, not ownership or behavior blockers. They should be documented as descriptive names, not emitted as raw `field_` names.

### SOBJ.TBL Compact Map Semantics

Best inference: `MapPane` owns a compact static-object classification cache derived from `SOBJ.TBL`.

Evidence accepted:

- [UID:0000Q3] documents `g_objectNationMap` as a lazily allocated byte array attached to [UID:0000L3] `MapPane`.
- [UID:0000Q4] documents `g_objectRecordCount` as a `std::uint32_t` count attached to the same MapPane file root.
- [UID:0001RL] documents the `SOBJ.TBL` resource format and confirms two parser views:
  - `StaticObjImageLib` consumes the full static-object table.
  - `MapPane` consumes a compact per-record byte classification map.
- Constructor parsing reads a 4-byte count, reads a 2-byte header, allocates `count+1` bytes, seeds slot `0` to `0`, and loops records starting at index `1` while `< g_objectRecordCount`.
- Each record has a 4-byte object id, two one-byte classification fields, a one-byte word-count, and `count*2` bytes of trailing `uint16_t` payload. `MapPane` stores the second one-byte classification field into `g_objectNationMap[index]`.
- Current package evidence: `SOBJ.TBL` entry size `276147`, count `19551`, header `0x0001`, first 485 object ids are `0xffffffff`, first non-sentinel record starts at index 485, and observed word-count range is `0..12`.

Recommended source names:

```cpp
static std::uint32_t g_objectRecordCount;
static std::uint8_t *g_objectNationMap;
```

Recommended record-local names:

```cpp
std::uint32_t objectId;
std::uint8_t sourceNationOrClass;
std::uint8_t objectNation;
std::uint8_t extraWordCount;
```

`objectNation` is more useful in MapPane source than `mappedNation` because consumers use it as the compact object/nation classification byte. The exact original field names are not proven, so target docs should mark record-local names as inferred.

Rejected alternatives:

- `g_objectNationMap` belongs to `GameServerConfig`: rejected. It is loaded inside MapPane construction, freed by MapPane destruction, and consumed by MapPane collision/movement/object helpers. `GameServerConfig` owns `g_gameServerNationTable`, not this compact cache.
- `SOBJ.TBL` compact parser is the same as `StaticObjImageLib`: rejected. The resource is shared, but the compact MapPane cache only stores one byte per object record and skips the rest.
- The leading sentinel block makes the table invalid: rejected. Existing resource docs confirm the full parse consumes the file and that leading `0xffffffff` records are a valid observed payload feature, even if exact source meaning remains unresolved.

### GameServerConfig Allocation And Source Split

Best inference: `MapPane` constructor allocates a separate `GameServerConfig`/nation-table helper object and stores it in `g_gameServerNationTable`; the helper class/file remains [UID:00005O] / [UID:0000JP].

Evidence accepted:

- [UID:0000Q1] documents `g_gameServerNationTable` as storage owned by GameServerConfig source placement.
- [UID:0000JP] says the conservative layout is a separate `map/GameServerConfig.cpp` beside `MapPane.cpp`, while noting that the constructor currently attributed as `InitializeMapPane` is likely MapPane lifecycle code.
- [UID:0001AO] is a mixed aggregate index that spans GameServerConfig and MapPane functions and is explicitly non-reconstructable.
- [UID:0002I7] allocates an 88-byte object and stores `g_gameServerNationTable`; [UID:0002QF] deletes it.

Recommended split:

- Keep `g_gameServerNationTable` declaration and GameServerConfig methods in [UID:0000JP].
- Keep the allocation/deletion call sites in `MapPane::MapPane` and `MapPane::~MapPane`.
- Update [UID:00005O] / [UID:0000JP] wording that describes `InitializeMapPane` as a GameServerConfig method. The better wording is: "MapPane constructor allocates and seeds the GameServerConfig nation table."

### Optional Child/List/Layer Cleanup Roles

Best inference for [UID:0002QF] source cleanup order:

1. Clear the runtime `ScreenEffecter*` list through [UID:0002I6].
2. Unregister the MapPane listener/change tag `1735356263` (`0x676f6f67`).
3. Save the compressed local map cache through [UID:0002QK].
4. Destroy optional child pane at `this+0x41c` if present.
5. Remove and destroy optional screen layer at `this+0x420` through `g_pScreenPane` / `ScreenPane::RemoveLayer` semantics.
6. Detach/sweep `ObjectList` contents through [UID:0001D3] and destroy/delete the `ObjectList` at `this+0x424`.
7. Free `g_objectNationMap`.
8. Delete the overlay at `this+0x3e0`.
9. Delete `g_gameServerNationTable`.
10. Close Redbook music through `g_pSoundManager->CloseRedbookDevice()`.
11. Clear `g_activeMapPane`.
12. Let compiler-generated member/base destructor code run.

ObjectList naming:

- `this+0x424` should be `m_objectList`.
- `ObjectList::DetachAll` is the best current source name for `0x00532b80-0x00532e11` based on [UID:0001D3].
- `ObjectList::GetInternalList` or a narrower `GetGlobalListTail` remains the best current source name for the `+0x40` accessor documented in [UID:0001D3].
- `this+0x418` should not be named with a raw generated field. The best descriptive role is `m_objectListDetachPreserve` or `m_preservedObjectPaneForDetach`; confidence is lower because the checked docs prove its use in teardown but not the original name.

### Helper `0x0057b160`

Best inference: `0x0057b160` is `SoundManager::CloseRedbookDevice`.

Evidence accepted:

- [UID:0001IB] `SoundManagerRedbookPlayback` records `0x0057b160-0x0057b1b0` as `SoundManager::CloseRedbookDevice`.
- It stops Redbook playback, cancels timer event `0x504e4354`, closes the Miles Redbook handle, clears four Redbook state dwords, and cancels the same event again.
- Direct callers include `0x0050467e` in MapPane cleanup and `0x0057b3b3` / `0x0057b3cc` inside `SoundManager::RestartMusic`.
- Callees include `AIL_redbook_stop`, `AIL_redbook_close`, and timer cancel helper `0x00597610`.
- [UID:00028R] documents `g_pSoundManager` at `0x0067a7d0` as the active SoundManager singleton. It specifically lists map teardown at `0x00504678` as a representative consumer.

Recommended target-doc update:

- Replace any unresolved "helper `0x0057b160` with global context `0x0067a7d0`" wording with "calls `SoundManager::CloseRedbookDevice` on `g_pSoundManager`."
- Do not move SoundManager code to MapPane. This is an external dependency call from the destructor.

### Mixed Aggregates And Stale Support Pages

Support docs that should be updated or left alone:

| UID | Current role | Recommended action |
| --- | --- | --- |
| `0001AO` | Mixed GameServerConfig/MapPane aggregate | Keep non-reconstructable. Add/retain wording that exact children own reconstruction; `0x00504110` is a MapPane constructor body, not the aggregate's C++ target. |
| `0001AP` | MapPane weather/coordinate/object aggregate | No owner change. Remove any implication that constructor/destructor source placement is unresolved after this pass; keep broader aggregate C++ blank because packet/weather fields remain open. |
| `0001AW` | MapPane packet handlers aggregate | No score or owner change. It supports the MapPane file route but does not own lifecycle. |
| `0000JP` / `00005O` | GameServerConfig file/class | Update stale `InitializeMapPane` ownership language. Keep `GameServerConfig` nation-table class and `g_gameServerNationTable` declaration there. |
| `0000L3` / `00007Q` | MapPane file/class | Add lifecycle note with constructor/destructor source names, `m_screenEffecter*` list, `m_objectList`, `m_selectionOverlay`, SOBJ compact cache, and SoundManager cleanup dependency. |
| `0002SQ` / `0003M4` / `0003M3` | vtable/destructor glue | No change required except cross-reference from lifecycle pages. |
| `000160` | GrafPort split index | No ownership change. `MapPane+0x428` should be documented as an embedded member whose implementation remains GrafPort-owned. |
| `00009Q` / `0000M4` / `0001D3` | ObjectList | No owner change. Target docs should use `ObjectList` names rather than generic list/raw cleanup wording. |

## Evidence Standards Used

I accepted an inference when at least two independent support surfaces agreed, or when one target page contained hard compiler-structure evidence and a support page confirmed ownership. I rejected candidate names when they depended only on local adjacency or raw decompiler style.

I treated the following as high-confidence evidence:

- vtable stores and destructor thunk topology
- direct caller identity, especially scalar deleting destructor caller for `0002QF`
- documented global owner pages with exact storage and constructor/destructor refs
- existing live-IDA-backed docs for resource parsing, globals, and helper calls
- generated output route through `MapPane.cpp`

I treated the following as lower-confidence evidence:

- exact original local field names for `this+0x118`, `this+0x418`, `this+0x41c`, `this+0x420`, and later flag bytes
- exact `SOBJ.TBL` record-local field names
- null-check style around global singleton calls where source may have relied on construction order

## IDA MCP Facts

Live IDA MCP was not available during this report run. A direct connection probe failed, so I did not perform new live decompilation or xref queries.

Existing docs used for IDA evidence already record:

- `0002I7` exact function boundary, callers, MapPane vtable stores, global writes, and SOBJ loader behavior.
- `0002QF` exact function boundary, only scalar deleting destructor caller, teardown order, and callee set.
- `0002SQ` vtable store xrefs from constructor/destructor and scalar deleting destructor slot topology.
- `0003M4` scalar deleting destructor call to `0x00504530`.
- `0001IB` modeled `0x0057b160-0x0057b1b0` as `SoundManager::CloseRedbookDevice`.
- `00028R` exact `g_pSoundManager` storage at `0x0067a7d0` and map teardown consumer at `0x00504678`.

This evidence is enough for source-quality recommendations, but the no-live-MCP limitation is why I recommend `88/89` and `88/90`, not final-audit-level scores.

## Function / Child Inventory

Relevant exact child rows:

| UID | Range | Role for this assignment |
| --- | --- | --- |
| `0002I7` | `0x00504110-0x00504521` | MapPane constructor body; target. |
| `0002QF` | `0x00504530-0x005046c6` | MapPane non-deleting destructor body; target. |
| `0002I6` | `0x005040a0-0x00504102` | `MapPane::ClearScreenEffecterList`-style helper clearing `m_screenEffecters`. |
| `0002QK` | `0x00504e00-0x00505075` | `MapPane::SaveCompressedMapFile`. Destructor calls this before object/list/layer teardown. |
| `0002SQ` | `0x0061e71c-0x0061e7a0` | MapPane vtable data proving constructor/destructor vtable sites. |
| `0003M4` | `0x00514de0-0x00514e1b` | scalar deleting destructor wrapper for `MapPane::~MapPane`. |
| `0003M3` | `0x00514d1e-0x00514d34` | destructor adjustor thunks; compiler artifacts. |
| `0001D3` | `0x00532530-0x00532f67` | ObjectList accessors/sweeps used by MapPane cleanup. |
| `0001IB` | `0x0057b020-0x0057b48a` | SoundManager Redbook helpers; resolves `0x0057b160`. |

## Direct Xref / Caller Inventory

Known target caller evidence from existing docs:

- `0002I7` has two direct callers in `InitializeMainUiGraph`: `0x004f7dfa` and `0x004f85ef`. These are construction sites for the live map pane in the main UI graph. This supports constructor placement and explains why `MapTilePixelDimensions` are also consumed during bootstrap.
- `0002QF` has only the scalar deleting destructor caller at `0x00514de6` from [UID:0003M4]. That proves non-deleting destructor identity.
- `0x0057b160` has callers from MapPane cleanup at `0x0050467e` and SoundManager restart paths at `0x0057b3b3` / `0x0057b3cc`.

## Documentation Evidence And IDA Status

Existing generated C++ currently contains only [UID:0002I2] `MapPane::FindActivePixelEffecter()` in `auto-generated/NexusTK/map/MapPane.cpp`. That output confirms the file route and field names for the effecter list but does not yet include the lifecycle bodies.

Current target-page stale wording to fix:

- [UID:0002I7] says C++ remains blank because the score is under an old `95/95` final-code gate. That should be replaced by active-gate language and a first-draft constructor block.
- [UID:0002QF] says C++ remains blank because of old gate and unresolved helper/member names. `0x0057b160` is now resolved, `m_screenEffecter*` fields are resolved, `m_objectList` is resolved, and the remaining low-confidence local fields do not block a source-level first draft.

## Ranked Ownership Analysis

1. [UID:0000L3] `MapPane.cpp` / [UID:00007Q] `MapPane`: strongest owner. Constructor/destructor artifacts, active singleton, vtables, viewport fields, object list, effecter list, map cache, SOBJ compact cache, overlay, and packet/render support all route here.
2. [UID:0000JP] / [UID:00005O] `GameServerConfig`: owns the nation-table helper class and `g_gameServerNationTable`, but not the MapPane constructor/destructor bodies.
3. [UID:0000M4] / [UID:00009Q] `ObjectList`: owns list implementation and sweeps. MapPane owns the instance pointer and calls into it.
4. [UID:0000NV] / [UID:0000DG] `SoundManager`: owns `CloseRedbookDevice` and `g_pSoundManager`. MapPane only calls it during teardown.
5. [UID:000160] `GrafPort`: owns embedded port implementation. MapPane only declares/constructs a member subobject.
6. [UID:0001AO] mixed aggregate: not an owner for reconstruction.

## Negative Evidence Summary

- No evidence supports moving `0002I7` to `GameServerConfig`; that attribution came from the embedded nation-table allocation and the broad aggregate name.
- No evidence supports a standalone `MapPaneLifecycle.cpp` split; [UID:0000L3] already groups MapPane coordinate/object/render/packet and lifecycle code under `NexusTK/map/MapPane.cpp`.
- No evidence supports emitting explicit vtable assignments, scalar deleting destructor calls, base destructors, or member destructor loops as source statements.
- No evidence supports treating `g_objectNationMap` as the same storage or owner as `g_gameServerNationTable`.
- No evidence supports keeping `0x0057b160` as an unresolved raw helper in the target cleanup page.
- No evidence supports naming `this+0x424` as a generic list; ObjectList pages support `m_objectList`.

## First-Draft C++ Recommendation

These are source-level drafts, not decompiler traces. Compiler-emitted vtable writes, scalar deleting destructor glue, member destructor calls, and base destructor calls are intentionally represented by source declarations/initializer lists and omitted from the body.

### UID 0002I7 Draft

Recommended field declarations or equivalent class members before using this draft:

```cpp
static const unsigned int kMapPaneChangeTag = 0x676f6f67; // 1735356263

ScreenEffecter **m_screenEffecters;
int m_screenEffecterCount;
int m_screenEffecterCapacity;
MapPaneLayerState m_layerStates[32];
AlphaMaskSurface *m_selectionOverlay;
unsigned short m_mapId;
short m_mapWidth;
short m_mapHeight;
std::uint16_t *m_tileBuffer;
int m_visibleTileColumns;
int m_visibleTileRows;
ObjectPane *m_objectListDetachPreserve;
Pane *m_auxiliaryPane;
Pane *m_activeScreenLayer;
ObjectList *m_objectList;
GrafPort m_viewportGrafPort;
```

Draft formal C++:

```cpp
MapPane::MapPane(int visibleTileColumns, int visibleTileRows)
    : Pane(0),
      m_layerStates(),
      m_viewportGrafPort(),
      m_screenEffecters(NULL),
      m_screenEffecterCount(0),
      m_screenEffecterCapacity(0),
      m_selectionOverlay(NULL),
      m_tileBuffer(NULL),
      m_visibleTileColumns(visibleTileColumns),
      m_visibleTileRows(visibleTileRows),
      m_objectListDetachPreserve(NULL),
      m_auxiliaryPane(NULL),
      m_activeScreenLayer(NULL),
      m_objectList(NULL)
{
    g_activeMapPane = this;

    m_mapId = 0;
    m_mapWidth = 0;
    m_mapHeight = 0;
    m_mapRuntimeState.Clear();
    m_runtimeFlags = 0;
    m_movementGate = 0;

    Rect mapBounds;
    mapBounds.left = 0;
    mapBounds.top = 0;
    mapBounds.right = g_mapTilePixelWidth * (visibleTileColumns + 2);
    mapBounds.bottom = g_mapTilePixelHeight * (visibleTileRows + 2);
    SetBounds(mapBounds);

    if (g_objectNationMap == NULL) {
        DataFile objectTable;
        if (objectTable.Open("SOBJ.TBL")) {
            std::uint16_t tableHeader = 0;

            objectTable.Read(&g_objectRecordCount, sizeof(g_objectRecordCount));
            objectTable.Read(&tableHeader, sizeof(tableHeader));

            g_objectNationMap = new std::uint8_t[g_objectRecordCount + 1];
            g_objectNationMap[0] = 0;

            for (std::uint32_t index = 1; index < g_objectRecordCount; ++index) {
                std::uint32_t objectId = 0;
                std::uint8_t sourceNationOrClass = 0;
                std::uint8_t objectNation = 0;
                std::uint8_t extraWordCount = 0;

                objectTable.Read(&objectId, sizeof(objectId));
                objectTable.Read(&sourceNationOrClass, sizeof(sourceNationOrClass));
                objectTable.Read(&objectNation, sizeof(objectNation));
                objectTable.Read(&extraWordCount, sizeof(extraWordCount));

                g_objectNationMap[index] = objectNation;

                for (std::uint8_t extraIndex = 0; extraIndex < extraWordCount; ++extraIndex) {
                    std::uint16_t ignoredWord = 0;
                    objectTable.Read(&ignoredWord, sizeof(ignoredWord));
                }
            }
        }
    }

    BackPane *backPane = BackPane::GetActive();
    if (backPane != NULL) {
        Rect backBounds;
        backPane->GetBounds(&backBounds);
        RegisterChangeListener(backPane, kMapPaneChangeTag);
        m_selectionOverlay = new AlphaMaskSurface(backBounds);
    }

    if (g_gameServerNationTable == NULL) {
        g_gameServerNationTable = new GameServerConfig;
    }

    m_screenEffecterCount = 0;
    m_screenEffecterCapacity = 0;
    m_screenEffecters = NULL;
}
```

Notes for the supervisor:

- `DataFile`, `BackPane::GetActive`, `RegisterChangeListener`, `AlphaMaskSurface`, and `MapPaneLayerState` names are source-level recommendations. Replace with existing local project types if the source tree has established names.
- The formal target page can include this as a first draft even if exact local helper class names are later refined. The body should not include vtable stores or manual member construction loops.
- If the supervisor prefers not to invent `MapPaneLayerState`, use a neutral documented type name such as `MapPaneLayerEntry` rather than `field_118`.

### UID 0002QF Draft

Draft formal C++:

```cpp
MapPane::~MapPane()
{
    ClearScreenEffecterList();
    UnregisterChangeListener(kMapPaneChangeTag);
    SaveCompressedMapFile();

    if (m_auxiliaryPane != NULL) {
        delete m_auxiliaryPane;
        m_auxiliaryPane = NULL;
    }

    if (m_activeScreenLayer != NULL) {
        if (g_pScreenPane != NULL) {
            g_pScreenPane->RemoveLayer(m_activeScreenLayer);
        }
        delete m_activeScreenLayer;
        m_activeScreenLayer = NULL;
    }

    if (m_objectList != NULL) {
        m_objectList->DetachAll(m_objectListDetachPreserve);
        m_objectList->DestroyOwnedObjects();
        delete m_objectList;
        m_objectList = NULL;
        m_objectListDetachPreserve = NULL;
    }

    delete[] g_objectNationMap;
    g_objectNationMap = NULL;
    g_objectRecordCount = 0;

    delete m_selectionOverlay;
    m_selectionOverlay = NULL;

    delete g_gameServerNationTable;
    g_gameServerNationTable = NULL;

    if (g_pSoundManager != NULL) {
        g_pSoundManager->CloseRedbookDevice();
    }

    if (g_activeMapPane == this) {
        g_activeMapPane = NULL;
    }
}
```

Notes for the supervisor:

- If binary evidence proves a project allocator is used for `g_objectNationMap`, replace `delete[]` with that allocator's matching free routine. The target doc currently says "free" rather than proving standard `delete[]`.
- `DestroyOwnedObjects()` is a source-level name for the documented ObjectList detach/access/virtual cleanup sweep. If the ObjectList page later emits exact names, use those.
- The destructor source body should not manually call `m_viewportGrafPort.~GrafPort()`, destruct `m_layerStates`, call the base pane destructor, write MapPane vtables, or conditionally delete `this`; those are member/base/compiler-deleting-destructor artifacts.

## Coverage Row Recommendations

Agents must not edit `by-memory/-coverage-report.md`. If the supervisor accepts this report, replace the existing rows for `0002I7` and `0002QF` with the following text at their current address-order positions.

Placement context for `0002I7`: replace the row for `[UID:0002I7][0x00504110-0x00504521.MapPaneInitialize]` in `by-memory/-coverage-report.md`.

```md
        - [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](by-memory/0x00504110-0x00504521.MapPaneInitialize.md) 0x00504110-0x00504521 | constructor | MapPane::MapPane : reconstructable : 88% : strong : B002 2026-06-17 source-quality pass recommends treating this as the ordinary `MapPane` constructor body, not a `GameServerConfig` lifecycle helper; existing IDA-backed docs confirm two `InitializeMainUiGraph` callers, MapPane vtable/active-singleton writes, source-authored viewport/tile/object-list/overlay/global setup, `SOBJ.TBL` compact object-nation cache loading through `g_objectRecordCount`/`g_objectNationMap`, embedded `GameServerConfig` nation-table allocation, and final `m_screenEffecter*` clears; compiler vtable/base/member construction remains source-declared/generated-binary.
```

Placement context for `0002QF`: replace the row for `[UID:0002QF][0x00504530-0x005046c6.MapPaneCleanup]` in `by-memory/-coverage-report.md`.

```md
        - [UID:0002QF][0x00504530-0x005046c6.MapPaneCleanup](by-memory/0x00504530-0x005046c6.MapPaneCleanup.md) 0x00504530-0x005046c6 | destructor | MapPane::~MapPane : reconstructable : 88% : strong : B002 2026-06-17 source-quality pass recommends treating this as the ordinary non-deleting `MapPane` destructor body reached by scalar deleting destructor [UID:0003M4]; existing IDA-backed docs confirm effect-list clear, listener unregister, compressed-map save, optional child/layer/object-list teardown, `g_objectNationMap` free, overlay and `g_gameServerNationTable` cleanup, `SoundManager::CloseRedbookDevice` call through `g_pSoundManager`, `g_activeMapPane` clear, and compiler-generated member/base teardown; formal C++ should omit explicit vtable/member/base-destructor artifacts.
```

## Target Metadata / Support-Doc Update Recommendations

Recommended [UID:0002I7] changes:

- Change completion/confidence to `88/89`.
- Keep `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`.
- Update entity kind to `MapPane constructor` or `ordinary MapPane constructor body`.
- Replace stale old-gate C++-blank note with active gate note and draft source-level C++.
- Add field-name table for `m_screenEffecterCount`, `m_screenEffecterCapacity`, `m_screenEffecters`, `m_selectionOverlay`, `m_visibleTileColumns`, `m_visibleTileRows`, `m_objectList`, `m_viewportGrafPort`, and compact object-nation globals.
- Clarify that vtable/base/member construction is compiler artifact.
- Clarify `SOBJ.TBL` compact parser semantics and that `g_objectNationMap` belongs to MapPane, while `g_gameServerNationTable` belongs to GameServerConfig but is allocated here.

Recommended [UID:0002QF] changes:

- Change completion/confidence to `88/90`.
- Keep `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`.
- Update entity kind to `MapPane destructor` or `ordinary non-deleting MapPane destructor body`.
- Replace unresolved helper `0x0057b160` text with `SoundManager::CloseRedbookDevice` through `g_pSoundManager`.
- Use `m_objectList` / `ObjectList::DetachAll` / `ObjectList::GetInternalList` naming for ObjectList teardown where appropriate.
- Clarify that `GrafPort` and fixed-array destruction plus base pane cleanup are compiler-emitted member/base destructors, not explicit source body calls.
- Add draft source-level destructor C++.

Recommended [UID:00007Q] / [UID:0000L3] support updates:

- Add a lifecycle note: `0x00504110` is `MapPane::MapPane(int visibleTileColumns, int visibleTileRows)` and `0x00504530` is `MapPane::~MapPane()`.
- Add field glossary entries for `m_screenEffecter*`, `m_objectList`, `m_selectionOverlay`, `m_viewportGrafPort`, visible tile counts, `m_tileBuffer`, and the compact SOBJ globals.
- Keep broader class/file score unchanged unless the supervisor wants a separate class-file update. This pass resolves lifecycle source quality but not all broader MapPane weather/packet/member names.

Recommended [UID:0000JP] / [UID:00005O] support updates:

- Reword `InitializeMapPane` as a historical or decompiler label, not a GameServerConfig method.
- Keep GameServerConfig ownership for the nation-table class and global `g_gameServerNationTable`.
- Note that MapPane constructor allocates the `GameServerConfig` object as embedded lifecycle policy.

Recommended [UID:0001AO] / [UID:0001AP] support updates:

- [UID:0001AO] remains a non-reconstructable mixed aggregate.
- [UID:0001AP] remains a broad MapPane aggregate. It may cite this report to remove constructor/destructor source-placement uncertainty but should keep aggregate C++ blank until remaining packet/weather fields are solved.

## Final Recommendation

The supervisor can safely implement the target-page source-quality updates directly:

- `0002I7`: ordinary `MapPane` constructor, `88/89`, source draft recommended.
- `0002QF`: ordinary non-deleting `MapPane` destructor, `88/90`, source draft recommended.
- Coverage rows: replace the two current rows with the exact replacement text above.
- No ownership split, no target reassignment, no by-memory aggregate promotion.

The only residual source-quality limitations are exact local names for the fixed `this+0x118` 32-entry array, the `this+0x418` companion ObjectList teardown field, the optional child/layer fields at `this+0x41c` / `this+0x420`, and some later runtime flag bytes. These are local field-name limitations, not ownership or C++-eligibility blockers. The draft avoids raw compiler/generated names and documents the uncertainty explicitly.

## Follow-Up Actions

1. Supervisor or a later agent with live IDA MCP should validate the exact constructor parameters from the two `InitializeMainUiGraph` call sites and settle whether source order was `(visibleTileColumns, visibleTileRows)` or a height/width local wrapper.
2. Validate the allocator/deallocator pair for `g_objectNationMap`; use project allocator names if standard `delete[]` is wrong.
3. Name `this+0x118` from render/layer call sites if a later focused assignment covers map layer state.
4. Name `this+0x418`, `this+0x41c`, and `this+0x420` from object-list and screen-layer call sites if a later assignment covers layer ownership.
5. Once target docs are updated, regenerate autogen and confirm `auto-generated/NexusTK/map/MapPane.cpp` includes the lifecycle drafts alongside `FindActivePixelEffecter`.

## Confidence

Overall confidence: strong for source placement, constructor/destructor identity, global split, SOBJ compact-map semantics, effecter-list names, ObjectList ownership, SoundManager helper identity, and C++ eligibility.

Residual confidence limits:

- No live IDA MCP was reachable during this run.
- Some MapPane local member names remain descriptive rather than source-proven.
- The C++ drafts use source-level helper/type names that should be aligned with existing project naming before formal final-audit emission.

## Validator Results

No by-* validator was run because this is a report-only assignment and no documentation targets were modified. I verified the report path via filesystem operations only.

## Changed Files

Created:

- `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/0002I7-0002QF-mappane-lifecycle-source-quality.md`

Modified:

- None.

Generated, by-* docs, coverage reports, source files, IDA database, and `by-memory/-coverage-report.md` were not edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/0002I7-0002QF-mappane-lifecycle-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:25","uid":"0002I7"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
