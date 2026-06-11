*** UID:0000PR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# g_activeMapPane

## Status

- Confidence: strong for storage address and `MapPane*` role, medium for final source-level name.
- Current alias: `g_activeGameServerConfig`.
- IDA storage: `0x0067a764` (`dword_67A764` / `DAT_0067a764`).
- Memory doc: [UID:0001OW][0x0067a764-0x0067a768.ActiveMapPaneSingleton](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md)
- Proposed owner: [UID:0000L3][MapPane](by-file/MapPane.md).

## Role

`g_activeMapPane` is the process-wide pointer to the live map pane. One current alias exposes it through the misleading `g_activeGameServerConfig` name because the `0x00504110` map-pane initializer is attributed to `GameServerConfig`.

Likely declaration during reconstruction:

```cpp
static MapPane* g_activeMapPane;
```

## Lifecycle

- `0x00504110` constructs the live map pane, installs `MapPane` vtables, and stores `this` into `dword_67A764`.
- `0x00504530` tears down map-pane state and clears `dword_67A764` before destroying the base `Pane`.
- Application shutdown/transition code around `0x00464e40` checks the pointer and calls a `MapPane` cleanup/close helper when it is non-null.

## Access Patterns

IDA xrefs are high-volume because many UI and render paths need the active map pane. Representative uses:

- `MiniMapDialog` construction at `0x00450ca0` calls a map-id helper through `dword_67A764`.
- `IconsPane` click handling checks the input-lock byte at `dword_67A764 + 1008`.
- Weather layer drawing in [UID:0000MY][RainingLayerPane](by-file/RainingLayerPane.md) and [UID:0000NR][SnowingLayerPane](by-file/SnowingLayerPane.md) also checks byte `dword_67A764 + 1008`; one current alias names this same storage `g_pWeatherState`.
- menu/browser/application paths query or clean up the active map pane during mode changes.
- several targeting and spell-selection helpers find map objects through `MapPane` lookup methods using `dword_67A764`.

2026-05-24 recheck found 360 IDA data refs to `0x0067a764`, consistent with a broad active-map singleton. Weather refs include the rain draw checks at the generated `g_pWeatherState->m_renderDisabled` sites; this supports treating `g_pWeatherState` as an alias for this storage, not as a separate weather-owned global.

2026-05-25 recheck again found `0x00504110` writing this storage immediately before installing `MapPane` vtables, confirming the generated `g_activeGameServerConfig` name is caller/owner pollution from the mis-attributed map initializer.
2026-06-05 IDA MCP recheck confirmed very broad xrefs to `0x0067a764`, including map-pane construction/lifecycle, minimap construction, application transition code, and map/render consumers.

## Naming Guidance

Do not propagate `g_activeGameServerConfig` into reconstructed source as the final name. The storage is broader active-map state, not general server configuration. `g_activeMapPane`, `g_pMapPane`, or `g_pActiveMapPane` are better candidates, depending on the surrounding naming style selected for other singletons.

## Cross-References

- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)
- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- [UID:0001OW][0x0067a764-0x0067a768.ActiveMapPaneSingleton](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md)
- [UID:0001AO][0x005039f0-0x00504521.GameServerNationAndMapInit](by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md)

## Changes

- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/82`. Summary/evidence: the page documents storage, active `MapPane*` role, lifecycle writes/clears, high-fanout access patterns, alias correction away from `g_activeGameServerConfig`, and map/weather refs; final source-level name remains provisional.
- 2026-06-05: Marked reconstructable and attached to [UID:0000L3][MapPane](by-file/MapPane.md).
  - Reason: live IDA MCP recheck confirms this source-declared singleton is the active `MapPane*`, with lifecycle and consumer evidence centered on the MapPane source root.
