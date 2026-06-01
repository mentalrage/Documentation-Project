*** UID:0000L3 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/map/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# MapPane

## Status

- Confidence: strong for `map/MapPane.cpp` as a major original source module, medium for companion-class file split.
- Proposed module folder: `map/`
- Candidate file: `map/MapPane.cpp`
- Current generated sources: `class_MapPane.cpp`, `class_MapPaneSpatialIndex.cpp`, `class_ObjectList.cpp`, `class_ObjectStatusBlob.cpp`, `class_StaticObjectPane.cpp`, `class_LightingObjectPane.cpp`, `class_SoundObjectPane.cpp`, `class_AttachmentAnchorResolver.cpp`, `class_MapNamePane.cpp`, `class_MapRefreshDimmer.cpp`, `class_TimerPane.cpp`, `class_WeatherLayerPane.cpp`, `class_RainingLayerPane.cpp`, `class_SnowingLayerPane.cpp`, and `class_SwallowLayerPane.cpp`.
- Evidence basis: `simroot_v2` Wave3 metadata, targeted IDA MCP boundary checks on 2026-05-23 through 2026-05-25, and local project-structure comparison with [UID:0000LE][MiniMap](by-file/MiniMap.md).
- System overview: [UID:0001QG][client_map_system](by-meta/client_map_system.md)
- Key global: [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md), currently mislabeled by Wave3 as `g_activeGameServerConfig`.

## Hypothesis

`MapPane` was likely a large central source file in the original client. It owns the live game-world pane: map tile state, visible-object indexing, object pane creation/destruction, world-to-screen conversion, server packet dispatch for map/object/weather state, paint invalidation, transition effects, and links to minimap/world-map child UI.

The strongest original-source reconstruction is:

```text
map/MapPane.cpp
map/MapPane.h
```

with small private or nearby helpers:

```text
map/BackPane.cpp
map/ObjectStatusBlob.cpp
map/StaticObjectPane.cpp
map/LightingObjectPane.cpp
map/SoundObjectPane.cpp
map/AttachmentAnchorResolver.cpp
map/MapNamePane.cpp
map/MapRefreshDimmer.cpp
map/TimerPane.cpp
map/WeatherLayerPane.cpp
map/RainingLayerPane.cpp
map/SnowingLayerPane.cpp
map/SwallowLayerPane.cpp
```

Those helper splits are lower confidence. They may have been nested declarations, file-local classes, or separate `.cpp` files depending on the original UI coding style.

## Proposed Contents

| Entity | Current range | Current file | Proposed ownership |
| --- | --- | --- | --- |
| `MapPane` | `0x00503ef0-0x00514e1a` plus map-owned render/packet islands, including shared hit-test helper [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md) | `class_MapPane.cpp` plus generated BackPane owner caveat | Main `map/MapPane.cpp` owner. Consumes [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) for playfield sizing and coordinate scaling. Excludes shared render helpers such as `0x004ba250`. |
| `ObjectList` / `MapPaneSpatialIndex` alias | `0x00530d00-0x00532530`, `0x00532530-0x00532f67`, `0x00532f70-0x0053728e`, `0x00537290-0x005372c8` | `class_ObjectList.cpp`, `class_MapPaneSpatialIndex.cpp` | Separate map object-index companion; see [UID:0000M4][ObjectList](by-file/ObjectList.md). |
| `GameServerConfig` / nation table | `0x005039f0-0x00504521`, `0x00514d50-0x00514ddc` | `class_GameServerConfig.cpp` | Map/gameplay helper for object nation mapping and status nation-entry data; current `InitializeMapPane` attribution should be reviewed. |
| `MapNamePane` | `0x005031f0-0x0050349e`, `0x0050380b`, `0x00503816`, `0x00503840-0x005038fd` | `class_MapNamePane.cpp` | Small companion pane; see [UID:0000L2][MapNamePane](by-file/MapNamePane.md) and the shared [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md). |
| `MapRefreshDimmer` | `0x00514920-0x00514e5b` | `class_MapRefreshDimmer.cpp` | Transition/fade helper; see [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md). |
| `TimerPane` | `0x005986e0-0x00598cbe` | `class_TimerPane.cpp` | Server-controlled timer/countdown overlay; see [UID:0000OU][TimerPane](by-file/TimerPane.md). |
| `PhotoPane` / `PictureViewPane` | `0x00549620-0x00549bc5` | `class_PhotoPane.cpp`, `class_PictureViewPane.cpp` | Map snapshot/viewer pane created from map packet/UI paths; see [UID:0000MK][PhotoPane](by-file/PhotoPane.md). |
| map object companions | `0x004d1f30-0x004d2697`, `0x00537900-0x00537abf`, `0x0053c5e0-0x0053d7bd` | `class_ObjectStatusBlob.cpp`, `class_StaticObjectPane.cpp`, `class_LightingObjectPane.cpp`, `class_SoundObjectPane.cpp`, `class_AttachmentAnchorResolver.cpp` | Shared object status parser plus static, light, sound, and attachment-anchor object helpers; see [UID:0000M6][ObjectStatusBlob](by-file/ObjectStatusBlob.md), [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md), [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md), [UID:0000NW][SoundObjectPane](by-file/SoundObjectPane.md), and [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md). |
| weather layers | `0x005c12a0-0x005c2ab5` | `class_WeatherLayerPane.cpp`, `class_RainingLayerPane.cpp`, `class_SnowingLayerPane.cpp`, `class_SwallowLayerPane.cpp` | Map weather overlay base plus rain/snow/swallow effects; see [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md), [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md), [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md), and the shared [UID:0001O1][0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes](by-memory/0x005c1bd0-0x005c2ab5.SnowingAndSwallowLayerPanes.md). |

Current `simroot_v2/class_MapPane.cpp` also emits shared UI/render helpers at `0x004ba250`, `0x005446e0-0x00544b7d`, and root screen layer-list helpers at `0x00556ce0-0x00556d41`. Do not migrate those into `map/MapPane.cpp`: `0x004ba250` belongs with [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md), the `0x005446e0` group belongs with [UID:0000MC][Pane](by-file/Pane.md) dirty/motion infrastructure, and the `0x00556ce0` group belongs with [UID:0000NB][ScreenPane](by-file/ScreenPane.md) root layer management.

## MapPane Subsystems

| Area | Representative methods | Notes |
| --- | --- | --- |
| Weather and effects | `SetWeatherEffect`, `ClearEffects`, `SetMapState`, raw `0x00510400` day/night packet body, `HandleEffectPacket` | Creates rain, water filter, snow, and lighting/day-night state. Runtime effect classes belong in [UID:0000IZ][Effects](by-file/Effects.md). Treat the generated `HandleWeatherPacket` as a boundary duplicate until the dispatcher split is repaired. |
| Coordinate conversion | `WorldToScreenCoords`, `ScreenToMapCoords`, `GetVisibleTileBounds`, `GetExtendedMapBounds`, `MapCoordsToScreenRect`, [UID:0000VC][ScaleDirectionOffsetToPixels_00505100](by-item/ScaleDirectionOffsetToPixels_00505100.md) | Central conversion layer between tile coordinates, viewport origin, [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md), and pixel rectangles. |
| Object indexing | `AddObjectToMap`, `LookupObjectById`, `RefreshObjectBand`, `FindLivingObjectAtCoords`, `FindNearestObject` | Uses an owned [UID:0000M4][ObjectList](by-file/ObjectList.md) at `MapPane + 0x424` and row bucket tables. |
| Tile and cached surface rendering | `DrawTileRange`, `RenderMapView`, `DrawVisibleTiles`, `DrawTileAt`, `DrawGroundTiles`, `RenderTileWithEffects` | Renders tile layers, static/effect objects, and cached map surfaces. |
| Input and interaction | `OnCommand`, `OnMouseEvent`, `OnNotify`, `ProcessObjectInteraction` | Handles key shortcuts, click-to-move, hover, targeting, auto-attack, and timers. |
| Server packet ownership | `HandlePacket` and packet-specific handlers from `0x0050fb00` through `0x00513da0` | Map-scoped packet switch and object/map/weather/status/timer updates. Object appearance/status parsing uses [UID:0000M6][ObjectStatusBlob](by-file/ObjectStatusBlob.md). Opcode tracking lives in [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md); opcode `0x67` creates or updates [UID:0000OU][TimerPane](by-file/TimerPane.md). |
| Map persistence | `LoadMapFromFile`, `SaveMapToFile` | Reads and writes compressed `.cmp` map files under the user's `Documents/NexusTK/Maps` folder; the load path constructs a local [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md) at `0x00504d49` before decompressing tile data. |
| Map transitions/pathing | `ChangeMap`, `SetTileData`, `HandleMapTransition`, `MapRefreshDimmer`, [UID:000235][0x00514f70-0x005151a9.MapPathDequeSupport](by-memory/0x00514f70-0x005151a9.MapPathDequeSupport.md) | Rebuilds tile buffers/object grid, transition visuals, and path candidate queues. |

[UID:0000MK][PhotoPane](by-file/PhotoPane.md) is a map-feature consumer rather than a `MapPane` child class. `MapPane::HandlePacket` creates it from packet/UI data, while `PhotoPane` owns the off-screen map-photo composition and [UID:0000AH][PictureViewPane](by-class/PictureViewPane.md) close behavior.

[UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md) is another packet-driven UI consumer rather than a `MapPane` child class. `MapPane::HandlePacket` constructs it for opcode `0x1b` in editable mode and opcode `0x35` in read-only mode, while `EditablePaperPane` owns paper parsing, rendering, editor setup, and opcode `0x23` save serialization.

[UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md) is a packet-created alert/status consumer rather than a `MapPane` child class. `MapPane::HandlePacket` constructs it inline for opcode `0x21`, while the small text-box/timer behavior belongs with SelfSaveOKPane.

## IDA MCP Evidence

Targeted checks on 2026-05-23 confirmed the selected anchor functions are real IDA functions:

- `0x00504530-0x005046c6` destructor-like MapPane cleanup.
- `0x00504b90-0x00504df1` load `.cmp` map file path.
- `0x00504e00-0x00505075` save `.cmp` map file path.
- `0x005059d0-0x00505bf8` draw/scroll tile range path.
- `0x00507c90-0x00508e06` large map packet dispatcher with 196 callsites.
- `0x005094b0-0x0050a4fd` main render path.
- `0x0050a500-0x0050a837` paint path.
- `0x0050bbb0-0x0050bcd8` map change path.
- `0x0050d840-0x0050d8db`, `0x0050d8e0-0x0050d9eb`, and `0x0050db50-0x0050dcb3` tile/weather render helpers.

The same pass confirmed `MapPaneSpatialIndex` methods at `0x00532530`, `0x00532550`, and `0x005326d0` are real functions and are called from MapPane render/hit-test paths. A later 2026-05-24 IDA MCP pass tied the same offsets to [UID:00009Q][ObjectList](by-class/ObjectList.md) layout initialized by `ObjectList::ObjectList`, so `MapPaneSpatialIndex` should now be treated as a provisional alias over the object-list accessor surface.

A later 2026-05-24 IDA MCP pass confirmed `MapPane::HandlePacket` at `0x00507c90` as a real `0x1176` byte dispatcher and confirmed downstream packet handler/function starts including `0x0050fb00`, `0x00510960`, `0x00511440`, `0x00511db0`, `0x00512960`, `0x00512d60`, `0x00513da0`, and [UID:0000OU][TimerPane](by-file/TimerPane.md) construction at `0x005986e0`. IDA does not currently model `0x00510400` as a function even though disassembly shows function-shaped weather-handler bytes there; keep that as a boundary caveat.

2026-05-26 SelfSave recheck: packet case `0x21` allocates `372` bytes and performs the same [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md) construction sequence documented at [UID:0001B0][0x005147d0-0x00514914.SelfSaveOKPane](by-memory/0x005147d0-0x00514914.SelfSaveOKPane.md), writing vtables at `0x0061e7a4`, `0x0061e81c`, and `0x0061e84c`, setting localized string id `61`, attaching the pane, and scheduling a one-second timer. Keep that construction as SelfSaveOKPane source ownership, not MapPane child-class ownership.

2026-05-25 send-helper recheck: IDA MCP callers show `MapPane::HandlePacket` calls [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md), and both `MapPane::HandlePacket` and the `0x00511440` spawn/movement/chat handler call [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md). The upload caller is specifically inbound case `0x6a`: it reads one flag byte, writes [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md), and calls the outbound opcode `0x77` helper at `0x00508b14` only when the flag is nonzero. A raw duplicate handler at [UID:0001AZ][0x00514380-0x005143b7.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143b7.FriendNameListSyncRawHandler.md) has the same behavior but no current xrefs. See [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md). This ties the name-list upload/status getter into map packet flow without making those helpers `MapPane`-owned source.

The object/world-map creation path at `0x00511db0` calls [UID:0000FD][UInt32Vector](by-class/UInt32Vector.md) construction for temporary dword-vector/bitset state. Keep that helper under [UID:0000P3][VectorHelpers](by-file/VectorHelpers.md), not as a `MapPane` class.

2026-05-26 AUTOBUF recheck: `MapPane::LoadMapFromFile` calls the `_AUTOBUF<unsigned char>` constructor at `0x004f5640` from `0x00504d49`, reads the compressed payload into that local object, then decompresses into tile storage. Keep the constructor under [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md) template/type support rather than `MapPane` ownership.

2026-06-01 BackPane-owner recheck: generated `BackPane::HitTestMapPane` at [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md) is a MapPane-style point hit-test helper called by spell/item/object target-selection mouse handlers. Generated `BackPane::StartIdleTimer` at [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md) is called only from MapPane packet/object setup at `0x0050eb14`, but the caller constructs an `EffectObjectPane` immediately before the call, so the helper is now reowned to EffectObjectPane. Keep both out of `map/BackPane.cpp`.

2026-05-24 recheck: IDA MCP still reports `0x00510400` as `Not a function`, while `0x005104d0` is modeled as `sub_5104D0` size `0x488` and `0x0050db50` is modeled as `sub_50DB50` size `0x163`. Current `source-3/simroot_v2/class_MapPane.cpp` also contains the day/night packet body inline in `MapPane::HandlePacket` case `0x20`, while case `0x1f` calls `SetMapState`/`sub_50DB50`. Treat generated `MapPane::HandleWeatherPacket` as a raw/boundary duplicate candidate until the dispatch split is repaired.

2026-05-25 recheck: IDA MCP disassembly shows the raw `0x00510400-0x005104c7` body followed by alignment and the modeled `0x005104d0` function. `xrefs_to` and `callers` report no direct references to `0x00510400`; the live dispatcher duplicate at `0x00507e45-0x00507f04` remains the evidence-backed opcode `0x20` route. See [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md).

The active map-pane singleton is [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) at `0x0067a764`. It is set by the current `GameServerConfig::InitializeMapPane` body, cleared by `0x00504530`, and used by minimap, icon/input, targeting, spell-selection, and application cleanup paths.

The shared [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) at `0x0066da9c` / `0x0066daa0` are consumed by MapPane setup and coordinate helpers but are not MapPane instance fields. `InitializeMapPane` uses them to size the backing playfield from tile counts plus a two-tile border, while `ScaleDirectionOffsetToPixels` uses them for in-place tile-offset scaling.

## File-Split Guidance

Recommended initial source layout:

```text
map/BackPane.cpp
map/MapPane.cpp
  map/ObjectStatusBlob.cpp
  map/StaticObjectPane.cpp
  map/LightingObjectPane.cpp
  map/SoundObjectPane.cpp
  map/AttachmentAnchorResolver.cpp
  map/MapNamePane.cpp
  map/MapRefreshDimmer.cpp
  map/PhotoPane.cpp
  map/TimerPane.cpp
map/WeatherLayerPane.cpp
map/RainingLayerPane.cpp
map/SnowingLayerPane.cpp
map/SwallowLayerPane.cpp
```

If a smaller migration batch is needed, `MapPaneSpatialIndex` can stay in a temporary `map/MapPaneSpatialIndex.cpp`, but the final structure should treat it as part of [UID:0000M4][ObjectList](by-file/ObjectList.md) rather than a standalone feature.

Do not merge [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) into `MapPane.cpp`. `MapPane` creates or triggers it through world-map packets, but `WorldMapPane` owns a separate modal map/travel UI and has its own private vector/bitset helpers.

Do not merge [UID:0000HO][BackPane](by-file/BackPane.md) into `MapPane.cpp`. `BackPane` is the root backdrop/container pane constructed by `InitializeMainUiGraph`, while `MapPane` owns game-world map state, objects, packets, and rendering.

[UID:0000OU][TimerPane](by-file/TimerPane.md) may remain a separate `map/TimerPane.cpp` companion even though `MapPane::HandlePacket` creates and updates it. `MapPane` owns the packet dispatch, while `TimerPane` owns display state, timer callback behavior, digit resources, and singleton teardown.

[UID:00008B][MiniMapButtonPane](by-class/MiniMapButtonPane.md) starts at `0x00503580` inside the older MapName aggregate range. Keep the class with minimap/map UI code, but migrate it by the per-method ownership documented in [UID:0001AL][0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes](by-memory/0x005031f0-0x0050395f.MapNameAndMiniMapButtonPanes.md), not by the legacy `0x005031f0-0x005038fd` span.

## Open Questions

- Whether `MapNamePane` and `MapRefreshDimmer` were file-local helper classes in `MapPane.cpp` or separate map UI files.
- Whether Wave3 should fully merge `MapPaneSpatialIndex` into `ObjectList`, or keep it as a documented view over the same object-list layout.
- Whether the nation-entry helper currently named `GameServerConfig` was a separate `map/GameServerConfig.cpp` or private MapPane source-local helper.
- Whether the weather layer family should remain as separate `WeatherLayerPane`/`RainingLayerPane`/`SnowingLayerPane`/`SwallowLayerPane` sources, fold into one generic `WeatherLayerPane.cpp`, or move to a render-effects module.
- Final naming for [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) values and packet payload structures.
- Whether `TimerPane` was a standalone map UI source file or a private helper inside `MapPane.cpp`.
- Several `MapPane` methods currently live in scattered presentation ranges. The `0x005446e0-0x00544b7d` helpers are now tracked under [UID:0000MC][Pane](by-file/Pane.md), `0x00556ce0-0x00556d41` under [UID:0000NB][ScreenPane](by-file/ScreenPane.md), and [UID:0000OC][Surface](by-file/Surface.md) tracks the `0x00557140-0x00559aef` DirectDraw presentation neighborhood as a shared-source review bucket.
- The current MapPane class grade remains incomplete because many child methods still contain raw field/global names.

## Cross-References

- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000VC][ScaleDirectionOffsetToPixels_00505100](by-item/ScaleDirectionOffsetToPixels_00505100.md)
- [UID:0000M4][ObjectList](by-file/ObjectList.md)
- [UID:0000M6][ObjectStatusBlob](by-file/ObjectStatusBlob.md)
- [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md)
- [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md)
- [UID:0000NW][SoundObjectPane](by-file/SoundObjectPane.md)
- [UID:0000HL][AttachmentAnchorResolver](by-file/AttachmentAnchorResolver.md)
- [UID:0000HO][BackPane](by-file/BackPane.md)
- [UID:00007R][MapPaneSpatialIndex](by-class/MapPaneSpatialIndex.md)
- [UID:0000L2][MapNamePane](by-file/MapNamePane.md)
- [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md)
- [UID:0000OU][TimerPane](by-file/TimerPane.md)
- [UID:0000MK][PhotoPane](by-file/PhotoPane.md)
- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md)
- [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md)
- [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md)
- [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md)
- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md)
- [UID:0000LE][MiniMap](by-file/MiniMap.md)
- [UID:0000OC][Surface](by-file/Surface.md)
- [UID:000167][0x004ba250-0x004ba444.SurfaceSpriteBlitHelper](by-memory/0x004ba250-0x004ba444.SurfaceSpriteBlitHelper.md)
- [UID:0000HM][AUTOBUF](by-file/AUTOBUF.md)
- [UID:0000IZ][Effects](by-file/Effects.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md)
- [UID:0001AZ][0x00514380-0x005143b7.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143b7.FriendNameListSyncRawHandler.md)
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md)
- [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md)
- [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md)
- [UID:000231][0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper](by-memory/0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper.md)
- [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md)
- [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md)
- [UID:000235][0x00514f70-0x005151a9.MapPathDequeSupport](by-memory/0x00514f70-0x005151a9.MapPathDequeSupport.md)
- [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md)
- [UID:0001AW][0x0050e4c0-0x00514e1b.MapPanePacketHandlersAndDelete](by-memory/0x0050e4c0-0x00514e1b.MapPanePacketHandlersAndDelete.md)
- [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md)
- [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md)

## Changes

- 2026-05-28: Corrected the `PhotoAndPicturePanes` endpoint from `0x00549bc4` to `0x00549bc5`. Evidence: IDA MCP byte/function review shows `0x00549bc4` is the final operand byte of `PictureViewPane::ScalarDeletingDestructor`; `0x00549bc5-0x00549bd0` is alignment padding.
- 2026-05-28: Updated MapName/MiniMapButton shared memory-island references from `0x005031f0-0x0050395e` to `0x005031f0-0x0050395f`. Evidence: IDA MCP reports the interleaved `MiniMapButtonPane` destructor ending at `0x0050395f`; the previous boundary omitted the final `retn 4` immediate byte.
- 2026-05-28: Updated `MapPaneWeatherCoordinateObjectCore` from `0x00503ef0-0x00506379` to `0x00503ef0-0x0050637a` and added the adjacent `0x00506380-0x005063db` opcode `0x0c` packet helper. Evidence: IDA MCP reports `sub_5062f0` ending at `0x0050637a` and `sub_506380` called from MapPane packet/object paths.
- 2026-05-28: Added `0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch` to the MapPane file inventory. Evidence: IDA MCP reports `sub_50e320` as a real function called by MapPane spawn/object-create paths and active-map consumers, followed only by `0xcc` padding before `0x0050e4c0`.
- 2026-05-28: Corrected the `MapRefreshDimmer` endpoint from `0x00514e5a` to `0x00514e5b` and added [UID:000235][0x00514f70-0x005151a9.MapPathDequeSupport](by-memory/0x00514f70-0x005151a9.MapPathDequeSupport.md) as ignored path deque support. Evidence: IDA MCP reports the corrected dimmer destructor end and the deque-support functions used by MapPane path scanning.
- 2026-05-28: Expanded the ObjectList companion inventory from lifecycle/accessors only to include `0x00530d00-0x00532530` and `0x00532f70-0x0053728e`. Evidence: IDA MCP confirms the remove-by-id helper, categorize/lookup helper cluster, and extended type lookup helper family as ObjectList-shaped code used by MapPane object paths.
- 2026-05-28: Corrected the shared surface/presentation review bucket from `0x00557140-0x00559a0f` to `0x00557140-0x00559aef`. Evidence: IDA MCP split the prior UNKNOWN tail and identified `0x00559a10-0x00559aef` as a real DirectDraw helper under the Surface review bucket.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:88` and `CONFIDENCE:80`.
  - Summary/evidence: major map source ownership, companion classes, subsystem map, packet/render/object/weather evidence, split guidance, open questions, extensive by-memory refs, and multiple range corrections are documented; confidence is capped by unresolved companion-file splits, raw/duplicate handler boundaries, and many remaining generated field/global names.
