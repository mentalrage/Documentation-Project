*** UID:0000PR | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MapPane *g_activeMapPane = NULL;
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class MapPane;

extern MapPane *g_activeMapPane;

#endif // NEXUSTK_MAP_MAPPANE_H
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_activeMapPane
## UID0000LU Header Route Synchronization - 2026-08-15

The existing singleton definition `MapPane *g_activeMapPane = NULL;` is preserved, and the H channel now exposes one forward-declared extern through `MapPane.h`. NewSpellInventoryPane reads existing public selection fields and creates no duplicate storage or selected-target wrapper.

## Status

- Confidence: strong for storage address, `MapPane*` role, MapPane lifecycle ownership, and broad active-map consumer pattern; medium-high for final source-level name.
- Historical generated aliases: `g_activeGameServerConfig`, `g_pMapPane`, and `g_pActiveMapPane`; the accepted source-facing name is `g_activeMapPane`.
- IDA storage: `0x0067a764` (`dword_67A764` / `DAT_0067a764`).
- Memory doc: [UID:0001OW][0x0067a764-0x0067a768.ActiveMapPaneSingleton](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md)
- Proposed owner: [UID:0000L3][MapPane](by-file/MapPane.md).

## Role

`g_activeMapPane` is the process-wide pointer to the live map pane. One current alias exposes it through the misleading `g_activeGameServerConfig` name because the `0x00504110` map-pane initializer is attributed to `GameServerConfig`.

Accepted source definition:

```cpp
MapPane *g_activeMapPane = NULL;
```

The definition has external linkage because UserPane source emits `extern MapPane *g_activeMapPane;` and both UID0003H5 and other cross-translation-unit consumers read the same storage. The former file-local `static` declaration is retained only as a superseded reconstruction assumption.

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
- [UID:0003A2][0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw](by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md) reads `g_activeMapPane` at `0x005593cc`, checks it with `Pane::IsAttachedToLayer` at `0x00544c50`, calls [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md) `MapPane::RedrawVisibleTiles()`, then invalidates/refreshes the active pane through the inherited pane virtual slot `+0x20` with argument `0`.
- [UID:0002EZ][0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket](by-memory/0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket.md) reads the active/local object pointer at `g_activeMapPane + 0x418`, then checks object byte `+0x134101` as an active-local chat/session/display state gate for packet type `13` subtypes. B001 2026-06-17 reanalysis keeps this as a consumer of the broad active-map singleton; the adjacent object byte `+0x134102` chat-send gate is supporting context, not the exact byte read by the type-13 display handler.
- B001 2026-06-18 confirms `UserPane` constructor arms at `0x005a2785` and `0x005a2a8f` read this singleton, copy it into `UserPane::m_mapPane` at `this+0x1340f8`, and write the inverse `MapPane+0x418 = this` local-player/active-object pointer.
- [UID:0003H5][0x005acb20-0x005acc23.UserPaneSendAutoFaceDirectionPacket](by-memory/0x005acb20-0x005acc23.UserPaneSendAutoFaceDirectionPacket.md) reads this global before its action-mode gate and resolves `s_selectObjectTargetId` through `MapPane::FindObjectPaneById`; [UID:0003UZ][0x005acc30-0x005acd85.UserPaneSendActionPacketWithAutoFace](by-memory/0x005acc30-0x005acd85.UserPaneSendActionPacketWithAutoFace.md) reaches the same lookup through the accepted source-level helper call.
- [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md) consumes this singleton in `ApplyEffect`: after accepting a new random shake sample it calls the active MapPane primary vtable slot `+0x20` with argument `0` as a map-view redraw/reset/invalidation action, then passes `g_activeMapPane` as the source GrafPort-like object to `GrafPort::BlitSurface` for the shifted map image. The exact source name for vslot `+0x20` remains unresolved; do not replace this with generated `g_pMapPane`/`g_pParcelPane` ownership.

2026-05-24 recheck found 360 IDA data refs to `0x0067a764`, consistent with a broad active-map singleton. Weather refs include the rain draw checks at the generated `g_pWeatherState->m_renderDisabled` sites; this supports treating `g_pWeatherState` as an alias for this storage, not as a separate weather-owned global.

2026-05-25 recheck again found `0x00504110` writing this storage immediately before installing `MapPane` vtables, confirming the generated `g_activeGameServerConfig` name is caller/owner pollution from the mis-attributed map initializer.
2026-06-05 IDA MCP recheck confirmed very broad xrefs to `0x0067a764`, including map-pane construction/lifecycle, minimap construction, application transition code, and map/render consumers.

2026-06-14 C001 live IDA MCP recheck used active `NexusTK.exe.i64` with auto-analysis and Hex-Rays ready. `lookup_funcs` reconfirmed `0x0067a764` is not a function, `0x00504110` is the MapPane constructor/init body, `0x00504530` is the matching teardown body, `0x00514ac0` is a tiny clear helper, `0x00464e40` is an application transition/cleanup path, and `0x005047f0` is the MapPane cleanup/close helper reached from that transition. Paged `xrefs_to 0x0067a764` returned the first 100 refs with additional pages available; the page included constructor write/guard-clear refs at `0x00504161` / `0x00504168`, teardown clear at `0x005046a5`, application transition read at `0x00464e7b`, minimap construction read at `0x00450e43`, and clear helper ref at `0x00514ac0`.

`analyze_component` reconfirmed that `0x00504110` and `0x00504530` share the three `MapPane` vtable globals, that the application transition calls `0x005047f0`, and that `dword_67A764` is shared by the constructor, teardown, transition, and clear helper. The weather/input-lock field offset should be recorded as `0x3f0` = decimal 1008 (Verified with int_convert.py), avoiding unverified decimal-only offset claims.

## ProfileDialog Refresh Forwarding Route - 2026-07-28

- [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) is an exact retained ProfileDialog.cpp file-local helper that loads this pointer into `ECX` and tail-forwards to [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) as `MapPane::RefreshSelectedProfileData()`. The direct ProfileDialog action path independently loads the same global before calling the same member.
- This route corroborates the established `MapPane *g_activeMapPane` identity and external source definition; it does not add a second global, change lifecycle ownership, or move the callee into ProfileDialog/ProfileStorage. UID0001DU owns only the forwarding helper, and UID0001AS remains the MapPane member definition.
- Metadata and formal code remain unchanged at `91/92`, owner/emitter UID0000L3, with the single definition already emitted here. Exact target no-route evidence, helper retention, and callee ownership are documented on their own pages rather than duplicated into this global's score.

## Naming Guidance

Do not propagate `g_activeGameServerConfig`, `g_pMapPane`, or `g_pActiveMapPane` into reconstructed source as the final name. The accepted spelling is `g_activeMapPane`: the storage is broad active-map state, not general server configuration, and this spelling matches the MapPane definition and UserPane external declaration.

## Score Rationale

Completion is `91` because the page records IDA-backed storage status, lifecycle write/clear paths, broad active-map consumers, alias correction, MapPane vtable/source ownership, the verified `+0x3f0` field offset, UID0003H5/UID0003UZ lookup use, and the accepted external-linkage definition. Confidence is `92` because MapPane ownership, singleton role, source spelling, and cross-file linkage are mutually consistent; unresolved names for unrelated consumer fields cap the score.

## Cross-References

- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0000JP][GameServerConfig](by-file/GameServerConfig.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)
- [UID:0000TP][WeatherLayerGlobals](by-global/WeatherLayerGlobals.md)
- [UID:0001OW][0x0067a764-0x0067a768.ActiveMapPaneSingleton](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md)
- [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md)
- [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md)
- [UID:0001AO][0x005039f0-0x00504521.GameServerNationAndMapInit](by-memory/0x005039f0-0x00504521.GameServerNationAndMapInit.md)
- [UID:0002EZ][0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket](by-memory/0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket.md)
- [UID:000046][EarthquakeEffecter](by-class/EarthquakeEffecter.md)

## Changes

- 2026-07-15 B002 UID0003H5 source-quality callback:
  - Raised the score to `91/92`, replaced the superseded file-local `static` definition with exact external-linkage `MapPane *g_activeMapPane = NULL;`, and recorded the UID0003H5/UID0003UZ selected-target lookup route.
  - Historical aliases and the old static declaration remain documented as rejected provenance rather than current source recommendations.
- 2026-06-29 Agent-B004 MapPane empty-emitter callback:
  - Raised score to `90/88` and inserted `static MapPane *g_activeMapPane = NULL;`.
  - Evidence: current MCP `244-246` reconfirmed the zero-initialized pointer at `0x0067a764` and broad constructor/teardown/minimap/input/targeting/weather xrefs; [UID:0001OW][0x0067a764-0x0067a768.ActiveMapPaneSingleton](by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md) now carries the covered-by marker.
- 2026-06-19 B007 EarthquakeEffecter support sync:
  - Added Earthquake `ApplyEffect` as an active-map consumer for the new-sample vslot `+0x20` redraw/reset/invalidation call and shifted-map `GrafPort::BlitSurface` source object.
- 2026-06-21 B007 ScreenPane palette-helper support sync:
  - Added [UID:0003A2][0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw](by-memory/0x005593b0-0x0055940c.ScreenPanePaletteVisibleTilesRedrawRaw.md) as an active-map consumer that validates the pane with `Pane::IsAttachedToLayer`, calls `MapPane::RedrawVisibleTiles()`, and dispatches the inherited pane refresh/invalidate slot.
- 2026-06-17 B001 Chatting packet support update:
  - Added [UID:0002EZ][0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket](by-memory/0x0047fd70-0x0047ff80.ChattingPaneHandleServerSayPacket.md) as a consumer that uses `g_activeMapPane + 0x418` to reach the active/local object and byte `+0x134101` for packet type-13 display gating. No score or routing change; this supports the existing broad active-map singleton role.
- 2026-06-18 B001 UserPane accessor support update:
  - Added [UID:00024A][0x005b83a0-0x005b83a7.UserPaneGetMapPane](by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md) as the tiny `UserPane` virtual that returns the cached `MapPane *` copied from this singleton.
  - No score or routing change; this strengthens the existing active-map singleton role and the `MapPane+0x418` back-pointer model.
- 2026-06-14 C001 low-confidence global refresh:
  - Changed score from `88/82` to `89/86`.
  - Summary/evidence: current IDA MCP reconfirmed active IDB health, storage/non-function status, constructor/teardown/clear helper/application transition refs, MapPane vtable sharing, paged high-fanout xrefs with more pages available, and `0x3f0` = decimal 1008 (Verified with int_convert.py). Owner/emitter remain [UID:0000L3][MapPane](by-file/MapPane.md); no C++ or IDA database edits were made because final source spelling remains open.
- Completion/confidence scoring: existed before as ungraded `0/0`; changed to `88/82`. Summary/evidence: the page documents storage, active `MapPane*` role, lifecycle writes/clears, high-fanout access patterns, alias correction away from `g_activeGameServerConfig`, and map/weather refs; final source-level name remains provisional.
- 2026-06-05: Marked reconstructable and attached to [UID:0000L3][MapPane](by-file/MapPane.md).
  - Reason: live IDA MCP recheck confirms this source-declared singleton is the active `MapPane*`, with lifecycle and consumer evidence centered on the MapPane source root.
