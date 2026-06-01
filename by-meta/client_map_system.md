*** UID:0001QG | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Map System

## Scope

This page tracks the live game-world map system: map files, map packet dispatch, object indexing, weather/day-night effects, map companion panes, and source-file placement. Exact address evidence belongs in `by-memory`; original source ownership belongs in `by-file`.

## Source Modules

- [UID:0000L3][MapPane](by-file/MapPane.md) is the central live-world pane and likely original `map/MapPane.cpp`. It owns map tile buffers, map file load/save, coordinate conversion, object lookup, input, rendering, weather state, and the main map packet dispatcher.
- [UID:0000M4][ObjectList](by-file/ObjectList.md) is the map-specific object index used by `MapPane`. It is not a generic utility container even though it internally uses [UID:0000KS][List](by-file/List.md); its complete method surface includes [UID:00023D][0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper](by-memory/0x00530d00-0x00530ed9.ObjectListRemoveByObjectIdHelper.md), [UID:0001D1][0x00530ee0-0x00531473.ObjectListLifecycle](by-memory/0x00530ee0-0x00531473.ObjectListLifecycle.md), [UID:00023E][0x00531480-0x00532530.ObjectListCategorizeLookupHelpers](by-memory/0x00531480-0x00532530.ObjectListCategorizeLookupHelpers.md), [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md), and [UID:00023F][0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers](by-memory/0x00532f70-0x0053728e.ObjectListExtendedTypeLookupHelpers.md).
- [UID:0000M5][ObjectPane](by-file/ObjectPane.md), [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md), [UID:0000KG][ItemObjectPane](by-file/ItemObjectPane.md), [UID:0000O6][StaticObjectPane](by-file/StaticObjectPane.md), [UID:0000KO][LightingObjectPane](by-file/LightingObjectPane.md), [UID:0000NW][SoundObjectPane](by-file/SoundObjectPane.md), and [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) are companion modules for world objects and overlays.
- [UID:0000M6][ObjectStatusBlob](by-file/ObjectStatusBlob.md) parses packed object status/appearance data consumed by map object creation/update handlers.
- [UID:0000L2][MapNamePane](by-file/MapNamePane.md), [UID:0000L4][MapRefreshDimmer](by-file/MapRefreshDimmer.md), [UID:0000OU][TimerPane](by-file/TimerPane.md), [UID:0000MK][PhotoPane](by-file/PhotoPane.md), [UID:0000JA][FieldMapPane](by-file/FieldMapPane.md), and [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md) are map UI companions rather than generic UI controls.
- [UID:0000P8][WeatherLayerPane](by-file/WeatherLayerPane.md), [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md), [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md), and [UID:0000OD][SwallowLayerPane](by-file/SwallowLayerPane.md) are map-screen weather overlays. Final migration may keep separate files or fold them into one weather-layer module.
- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md) tracks rain coordinate tables, snow particle/pattern tables, render callbacks, and the current `g_pWeatherState` alias warning.
- [UID:0000LE][MiniMap](by-file/MiniMap.md) and [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md) are related systems but not owned by `MapPane.cpp`: minimap owns its own UI/cache flow, while [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md) owns terrain-tile asset loading, `TILE.TBL` / `TILE.TBD`, `TILE%d.EPF`, and the [UID:0001V3][MapTileRecord](by-type/by-struct/MapTileRecord.md) table.
- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md) is the current nation-table/map-initializer owner. It should remain under `map/` unless later evidence proves the nation-entry table was a private `MapPane` helper.
- [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) is the live map-pane singleton at `0x0067a764`; Wave3 currently aliases it as `g_activeGameServerConfig`.
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) are the shared `48x48` tile-pixel globals at `0x0066da9c` / `0x0066daa0`, consumed by map setup, coordinate scaling, and item/effect centering.

## Runtime Flow

1. Application/UI startup creates the root map/backdrop pane stack through the main UI graph.
2. `MapPane` loads or receives map state, builds tile buffers, applies the shared [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md), and creates the [UID:0000M4][ObjectList](by-file/ObjectList.md) index.
3. `MapPane::HandlePacket` at `0x00507c90` dispatches map-scoped server packets by first payload byte.
4. Packet-specific handlers update map metadata, tile regions, object status, movement, weather, dialogs, and companion panes.
5. Rendering uses `MapPane` coordinate conversion and object-row buckets to draw visible tiles/objects, while companion panes render names, weather, timers, and transition overlays.

## Packet Dispatch

The current dispatcher table is tracked as [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md). Treat names as working labels until packet structures are named.

Known high-confidence routes include:

- opcode `0x03` / `0x33`: map transition path through `0x0050feb0`;
- opcode `0x04`: tile-region update path through `0x005059d0` and object-list refresh;
- opcode `0x06`: map info path through `0x00510960`;
- opcode `0x07`: spawn path through `0x00511440`;
- opcode `0x15`: effect/weather-adjacent path through `0x005104d0`;
- opcode `0x1f`: map weather/state selector through `0x0050db50`;
- opcode `0x20`: day/night cycle body inline in the dispatcher at `0x00507e45-0x00507f04`; generated `0x00510400-0x005104c7` is a raw duplicate/boundary caveat;
- opcode `0x16`: object update path through `0x00512d60`;
- opcode `0x1b` / `0x35`: editable/read-only [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md) creation;
- opcode `0x2e`: object/world-map creation path through `0x00511db0`, which can construct [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md);
- opcode `0x46`: [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md) creation;
- opcode `0x4f`: [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md) packet/dialog path;
- opcode `0x62`: web-board or board dialog path depending client mode, including active [UID:0000G2][WebBoardDialog](by-class/WebBoardDialog.md) and legacy [UID:0000G3][WebBoardDialogOld](by-class/WebBoardDialogOld.md) open paths;
- opcode `0x67`: [UID:0000OU][TimerPane](by-file/TimerPane.md) creation/update.

## Map Storage

- `MapPane::LoadMapFromFile` at `0x00504b90` and `MapPane::SaveMapToFile` at `0x00504e00` use compressed `.cmp` files below the user's `Documents/NexusTK/Maps` path.
- Tile buffer allocation and update helpers are in the `0x0050bce0-0x0050e320` range.
- [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md) is parsed both by [UID:0000O7][StaticObjImageLib](by-file/StaticObjImageLib.md) for full static-object render metadata and by `MapPane` initialization for [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md) plus [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md), a compact object-to-nation/classification cache. The render view stores [UID:0001W8][StaticObjEntry](by-type/by-struct/StaticObjEntry.md) records behind [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md).
- [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md) stores the runtime [UID:0001UP][GameServerNationEntry](by-type/by-struct/GameServerNationEntry.md) table used by map/status/user presentation paths.
- The DAT/archive and image libraries own asset storage and decoding. `MapPane` consumes those assets to build live map views; terrain tiles specifically go through [UID:0000L5][MapTileImageLib](by-file/MapTileImageLib.md), whose IDA-confirmed singleton storage is [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md). Runtime effect-object panes consume [UID:0000IY][EffectObjImageLib](by-file/EffectObjImageLib.md) through [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md) for effect bounds, descriptors, and sprite-frame rendering.

## Evidence

- IDA MCP confirms `MapPane::HandlePacket` at `0x00507c90` as a real `0x1176` byte function with callees into packet readers, map handlers, dialog constructors, `TimerPane`, and object/living-object methods.
- IDA MCP confirms downstream packet handler starts such as `0x0050fb00`, `0x00510960`, `0x00511440`, `0x00511db0`, `0x00512960`, `0x00512d60`, `0x00513da0`, and `0x005986e0`.
- IDA currently does not model `0x00510400` as a function, but disassembly shows real function-shaped bytes beginning there. Treat the current `HandleWeatherPacket` boundary as a Wave3/IDA boundary caveat.
- 2026-05-24 recheck still has `0x00510400` unmodeled, with neighboring `0x005104d0` and `0x0050db50` modeled. Current generated `MapPane::HandlePacket` includes the day/night blend body inline under opcode/case `0x20`, so the standalone generated `HandleWeatherPacket` row is not a final source boundary.
- 2026-05-25 recheck confirms the raw body covers `0x00510400-0x005104c7`, has no direct IDA callers/xrefs, and duplicates the dispatcher case `0x20` body at `0x00507e45-0x00507f04`. See [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md).
- 2026-05-25 recheck confirms `ObjectList` lifecycle and helper-island ownership: constructor callers are only map-change/effect replacement paths, while `0x00532530-0x00532f67` serves MapPane render, scroll, hit-test, object cleanup, and FpsPane diagnostic consumers.
- 2026-05-25 recheck resolves part of the generated MapPane presentation pollution: `0x005446e0-0x00544b7d` belongs to [UID:0000MC][Pane](by-file/Pane.md) dirty/motion infrastructure, and `0x00556ce0-0x00556d41` belongs to [UID:0000NB][ScreenPane](by-file/ScreenPane.md) root layer-list infrastructure.
- Existing memory pages split the core map range into weather/coordinate/object core, input/packet/render core, and packet-handler ranges.

## Open Questions

- Final packet names and payload structures for every `MapPane::HandlePacket` opcode.
- Whether the weather layer classes were separate `.cpp` files or private classes in a combined weather/map source.
- Whether `GameServerConfig` nation-entry helpers belong in `map/GameServerConfig.cpp` or inside `MapPane.cpp`.
- Whether the first `SOBJ.TBL` static-object record is a true record or an implicit/sentinel slot for the `g_objectNationMap` loader.
- Which remaining helpers in the `0x00557140-0x00559aef` presentation neighborhood are true map/screen orchestration versus shared render/surface code.

## Cross-References

- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md)
- [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md)
- [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md)
- [UID:0001AW][0x0050e4c0-0x00514e1b.MapPanePacketHandlersAndDelete](by-memory/0x0050e4c0-0x00514e1b.MapPanePacketHandlersAndDelete.md)
- [UID:0000M4][ObjectList](by-file/ObjectList.md)
- [UID:0001D3][0x00532530-0x00532f67.ObjectListAccessorsAndSweeps](by-memory/0x00532530-0x00532f67.ObjectListAccessorsAndSweeps.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)
- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md)
- [UID:0000RG][g_pMapTileImageLib](by-global/g_pMapTileImageLib.md)
- [UID:0000SD][g_pStaticObjImageLib](by-global/g_pStaticObjImageLib.md)
- [UID:0000QT][g_pEffectObjImageLib](by-global/g_pEffectObjImageLib.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- [UID:0001RL][sobj-tbl](by-resource/sobj-tbl.md)
- [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md)
- [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md)
- [UID:0001QK][client_opcodes](by-meta/client_opcodes.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001QQ][client_s5-ui-and-gameworld-rendering](by-meta/client_s5-ui-and-gameworld-rendering.md)
