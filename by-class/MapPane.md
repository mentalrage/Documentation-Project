*** UID:00007Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:78 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MapPane

## Status

- Confidence: strong for class responsibility, medium for final source split.
- Likely source file: [UID:0000L3][MapPane](by-file/MapPane.md)
- Current recovered file: `source-3/simroot_v2/class_MapPane.cpp`
- Current coverage: 124 active methods over many aggregate ranges.
- Evidence basis: Wave3 metadata and targeted IDA MCP checks on 2026-05-23 through 2026-05-25.
- Key global: [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md).

## Class Purpose

`MapPane` is the live game-world pane. It bridges server-driven map/object packets to the rendered world view, owns tile buffers and object indexes, converts between tile and screen coordinates, processes movement and targeting input, manages weather/day-night effects, and triggers map/minimap/world-map transitions.

## Major Method Families

| Family | Representative addresses | Role |
| --- | --- | --- |
| Lifecycle and message routing | `0x00504530`, `0x005046d0`, `0x005047f0`, `0x00504b70` | Cleanup, queued map messages, logout/menu transition, and integration messages. |
| Map persistence | `0x00504b90`, `0x00504e00` | Load/save compressed `.cmp` map files below the user's `Documents/NexusTK/Maps` folder. |
| Coordinates and visible bounds | `0x00505080-0x0050571d` | Tile offsets, world/screen conversion, visible bounds, and map-edge clipping. |
| Object ownership and indexing | `0x00505940-0x0050637a`, `0x00506970-0x00506cdc` | Adds, finds, updates, and removes tracked living/static/item object panes. |
| Input and timers | `0x00506df0`, [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md), `0x00507150`, `0x00509030`, [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md) | Keyboard commands, mouse hover/click/drag interactions, target-selection hit testing, movement/object timers, effect-object idle timer setup, and auto-attack polling. |
| Packet dispatch | `0x00507c90`, `0x0050fb00-0x00513da0` | Main map packet switch and packet-specific object/weather/status/action handlers. |
| Rendering | `0x005094b0`, `0x0050a500`, `0x0050d840`, `0x0050d8e0`, `0x0050dd60` | Render map view, paint dirty areas, draw cached tiles, and render map objects. |
| Weather and lighting | `0x00503ef0`, `0x005040a0`, `0x0050a8b0`, `0x0050db50`, raw `0x00510400` | Weather layers, day-night state, lighting effects, and weather packets. The generated `0x00510400` method is raw duplicate evidence for opcode `0x20`, not yet a settled method boundary. |
| Map transition and world-map creation | `0x0050bbb0`, `0x0050feb0`, `0x00511db0` | Map changes, server transfer, and construction of world-map UI from object-create packet data. |

## Key Relationships

- Owns an [UID:00009Q][ObjectList](by-class/ObjectList.md) at the `MapPane + 0x424` family for row-bucket, visible-object, render-layer, and cleanup lookups. [UID:00007R][MapPaneSpatialIndex](by-class/MapPaneSpatialIndex.md) is a provisional generated alias for part of this accessor surface.
- Consumes [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) for map-pane setup and coordinate scaling. These are globals at `0x0066da9c` / `0x0066daa0`, not MapPane fields.
- `g_activeMapPane` at `0x0067a764` points to the live instance and is used by minimap, icon/input, targeting, spell-selection, and application cleanup paths.
- Dispatches map-scoped inbound opcodes tracked in [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md).
- Creates or configures [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md) through weather state.
- Works with [UID:00007P][MapNamePane](by-class/MapNamePane.md) and [UID:00007S][MapRefreshDimmer](by-class/MapRefreshDimmer.md) as small map UI companions.
- Creates or routes to [UID:0000AG][PhotoPane](by-class/PhotoPane.md) for map-photo/viewer snapshots; `PhotoPane` owns the cached map/avatar image composition.
- Triggers [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md) creation from map/world-map packet handling.
- Consumes render asset libraries such as map tile, static object, effect object, item object, human, monster, and palette libraries; it should not own those render libraries.

## IDA MCP Evidence

IDA confirmed selected anchor ranges:

- `0x00504530-0x005046c6`: destructor-like cleanup.
- `0x00504b90-0x00504df1`: map file load path.
- `0x00504e00-0x00505075`: map file save path.
- `0x00507c90-0x00508e06`: large map packet dispatcher.
- `0x005094b0-0x0050a4fd`: render map view.
- `0x0050a500-0x0050a837`: paint handler.
- `0x0050bbb0-0x0050bcd8`: map change.
- `0x0050db50-0x0050dcb3`: weather/map state setter.
- `0x00507c90-0x00508e06`: IDA-confirmed `0x1176` byte packet dispatcher with callees into packet readers, dialog constructors, map object handlers, [UID:0000F3][TimerPane](by-class/TimerPane.md), and socket send helpers.
- 2026-05-25 send-helper recheck: IDA MCP callers show `MapPane::HandlePacket` calls [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md) from inbound case `0x6a` at `0x00508b14` after writing [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md); the same dispatcher also calls [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md), and the `0x00511440` spawn/movement/chat handler also calls `GetConnectionStatus`.
- `0x00510400`: raw function-shaped weather-handler bytes, but not currently an IDA function object.
- 2026-05-24 recheck: `0x00510400` is still `Not a function` in IDA, while `0x005104d0` and `0x0050db50` are modeled function starts. Current generated `MapPane::HandlePacket` already inlines the day/night blend body under case `0x20`, so the standalone `HandleWeatherPacket` row should be treated as a boundary/raw duplicate caveat until packet dispatch is reconciled.
- 2026-05-25 recheck: `0x00510400-0x005104c7` disassembles as a normal raw body but has no direct IDA callers or xrefs; `MapPane::HandlePacket` contains the same body inline at `0x00507e45-0x00507f04`.
- 2026-05-26 recheck: generated BackPane helpers at `0x00506ce0` and `0x005388a0` are MapPane/target-selection related by caller evidence. `0x00506ce0` is called from spell/item/select/target mouse-selection paths; `0x005388a0` is called only from MapPane packet/object setup at `0x0050eb14`.
- 2026-05-28 recheck: [UID:000231][0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper](by-memory/0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper.md) is a small MapPane packet helper called from `MapPane::HandlePacket` and object/status update paths when an expected object target is missing.
- 2026-05-28 recheck: [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) is a MapPane object/effect descriptor helper called from spawn/object-create paths and active-map consumers.

## Ownership Notes

`MapPane` is too broad to reduce to a generic UI control. It is the main gameplay world-view module.

Current `simroot_v2/class_MapPane.cpp` also contains generated-owner pollution from shared UI/render code:

- `0x005446e0-0x00544b7d` is [UID:0000MC][Pane](by-file/Pane.md) dirty/motion paint infrastructure used by layer traversal.
- `0x00556ce0-0x00556d41` is [UID:0000NB][ScreenPane](by-file/ScreenPane.md) root layer-list infrastructure used by startup/shutdown and map/world-map layer changes.
- `0x00557140-0x00559aef` remains tracked under [UID:0000OC][Surface](by-file/Surface.md) as a shared DirectDraw presentation review bucket.

## Open Questions

- Resolve the final file placement for weather and the remaining `0x00557140-0x00559aef` surface presentation helpers.
- Review low-grade child methods before using them for rename-heavy migrations.
- Split packet-handler documentation by opcode family after the packet structures are named.
- Review the `0x00510400` weather-handler function boundary before migrating that method from generated output.

## Cross-References

- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0000VC][ScaleDirectionOffsetToPixels_00505100](by-item/ScaleDirectionOffsetToPixels_00505100.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md)
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
- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md)
- [UID:0000AG][PhotoPane](by-class/PhotoPane.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)

## Changes

- 2026-05-28: Updated the object/indexing family end from `0x00506379` to `0x0050637a` and added the adjacent opcode `0x0c` object-id packet helper. Evidence: IDA MCP reports `sub_5062f0` ending at `0x0050637a`, then a separate `sub_506380` helper at `0x00506380-0x005063db` called from MapPane packet/object paths.
- 2026-05-28: Added `0x0050e320-0x0050e4b6` as `MapPaneObjectEffectDescriptorDispatch` instead of leaving it in the UNKNOWN gap. Evidence: IDA MCP reports `sub_50e320` as a real function called from MapPane spawn/object-create paths and active-map consumers, with only alignment padding before `0x0050e4c0`.
- 2026-05-28: Added [UID:000235][0x00514f70-0x005151a9.MapPathDequeSupport](by-memory/0x00514f70-0x005151a9.MapPathDequeSupport.md) to MapPane cross-references as ignored compiler/STL support for path scanning. Evidence: IDA MCP xrefs to `0x00515110` come from MapPane path/cell scanning functions at `0x0050c790` and `0x0050d010`.
- 2026-05-28: Corrected the shared surface/presentation review bucket from `0x00557140-0x00559a0f` to `0x00557140-0x00559aef`. Evidence: IDA MCP identified `0x00559a10-0x00559aef` as real DirectDraw helper code belonging to the Surface review bucket, not MapPane ownership.
- Completion/confidence score update: existed before as `0/0`; changed to `84/78`. Summary: the live game-world pane is broadly and deeply documented across responsibility, method families, globals, packet/render/weather/map-transition dependencies, IDA anchors, ownership pollution, and open questions, but confidence stays medium because packet opcode splits, weather boundary duplication, source split, and several low-grade child methods remain unresolved. Evidence: linked MapPane memory ranges, IDA-confirmed anchor ranges, `g_activeMapPane`, `ObjectList`, packet opcode/type references, generated BackPane helper rechecks, and explicit ownership-pollution exclusions.
