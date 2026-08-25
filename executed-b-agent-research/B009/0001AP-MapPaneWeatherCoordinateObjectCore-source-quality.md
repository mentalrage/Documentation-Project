** TARGET-REPORT-UID:0001AP **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001AP MapPane Weather/Coordinate/Object Core Source-Quality Research

Agent: Agent-B009  
Assignment: B009-report-0001AP-map-pane-weather-coordinate-object-core-20260625  
Target: [UID:0001AP] `by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`  
Mode: report-only, no leases, no by-* edits, no generated or coverage edits  
IDA MCP endpoint used: `http://127.0.0.1:13337/mcp`

## Current recommendation

Keep `[UID:0001AP]` as a `MapPane` aggregate owned by `[UID:00007Q]` and sourced through `[UID:0000L3] map/MapPane.cpp`. The assignment does not need a canonical-owner repair, and the overlap with `[UID:0001AO] GameServerNationAndMapInit` should remain documented as intentional non-emitting index overlap rather than treated as a range error.

Current emitting-aggregate correction: do not leave this emitting aggregate with a blank formal C++ block. Keep `RECONSTRUCTABLE:TRUE` and `EMITTER_UIDS:00007Q`, but insert the formal aggregate marker block supplied below. Exact child pages, not this aggregate, own the method/helper bodies; the aggregate marker exists only to make the emitting split/index route explicit in generated source.

The aggregate is not final-audit complete, but the current refill pass resolves the modeled-child C++ blockers that were previously deferred. The implementation callback should split the remaining modeled and raw helper ranges into exact child pages, update the parent inventory and MapPane support pages, insert formal C++ for every modeled child marked below, and keep only the raw no-route helpers non-emitting.

- Several non-CC gap ranges are source-shaped raw helpers that IDA does not model as functions. They are not padding and need exact documentation, even where no route/xref is currently known.
- Two switch/jump-table data islands belong to helper children and should be attached to those children rather than ignored as padding.

## Source queue and target state

Queue row from assignment:

- Queue: Not-Covered Files - Reconstructable
- Target header at assignment start: `COMPLETION: 86`, `CONFIDENCE: 89`
- `CANONICAL_OWNER: 00007Q`
- `RECONSTRUCTABLE: TRUE`
- `EMITTER_UIDS: 00007Q`
- C++ block: currently blank; corrected recommendation is the formal aggregate marker block in this report.

Current target document already correctly records many exact child pages, including the weather/effect children, map cache children, draw helper `[UID:0001AR]`, scroll/recenter children `[UID:0002QL]` and `[UID:0002QM]`, and the existing file-level scale helper `[UID:0001AQ]`. Its remaining backlog is specifically the interior helper inventory from `0x00505080` through `0x00505de0` plus raw function-shaped gap bodies.

Generated report state was read-only. `auto-generated/-ag-coverage-report-by-memory.md` still renders a stale aggregate score row for `[UID:0001AP]`, while `auto-generated/-ag-memory-coverage.md` records the aggregate as an emitter rooted at `auto-generated/NexusTK/map/MapPane.cpp`. Do not manually edit either generated file.

## MCP availability and session facts

The supervisor-required endpoint was available.

- `Test-NetConnection 127.0.0.1 -Port 13337` succeeded.
- MCP `initialize` succeeded against server `ida-pro-mcp`, protocol `2025-06-18`.
- `idb_list` returned one active IDA session:
  - session id: `80de0a67`
  - database path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
  - active: `true`
  - backend: `worker`
- `server_health` for `80de0a67` returned healthy:
  - module: `NexusTK.exe`
  - input path: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
  - imagebase: `0x400000`
  - `auto_analysis_ready: true`
  - `hexrays_ready: true`
  - `strings_cache_ready: true`

No IDA DB edits, renames, comments, types, or function creation were made.

## Evidence checked

Primary documents:

- `[UID:0001AP] by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md`
- `[UID:00007Q] by-class/MapPane.md`
- `[UID:0000L3] by-file/MapPane.md`
- `[UID:00007R] by-class/MapPaneSpatialIndex.md`
- Existing child pages `[UID:0001AQ]`, `[UID:0001AR]`, `[UID:0002QL]`, `[UID:0002QM]`, and related aggregate coverage rows
- `project-level/-resolved.md`, `project-level/-unresolved.md`, and generated coverage summaries in read-only mode
- Executed B-agent reports for prior MapPane class, nation-map, movement/status gate, and coordinate helper leads

Negative evidence was also checked:

- Raw gap starts `0x005053f0`, `0x00505750`, `0x005057d0`, `0x00505c00`, `0x00505d00`, `0x00505da0`, and `0x005061e0` are not modeled IDA functions.
- 2026-06-25 correction retry `lookup_funcs` still reports those seven raw starts as `Not a function`.
- 2026-06-25 correction retry `xrefs_to(addrs=[...])` returns zero incoming refs for each of those seven raw starts.
- 2026-06-25 refill `find_bytes` searches for little-endian absolute pointer patterns `f0 53 50 00`, `50 57 50 00`, `d0 57 50 00`, `00 5c 50 00`, `00 5d 50 00`, `a0 5d 50 00`, and `e0 61 50 00` returned zero matches.
- Those raw ranges are therefore not currently routed through a direct modeled call or table reference, but several are source-shaped MapPane helpers with clear field use and should not be collapsed into padding.

The 2026-06-25 refill also rechecked modeled C++ blockers with current MCP `analyze_component` and `xrefs_to`. `analyze_component` confirmed prototypes/callees for the formal-C++ children, including `0x00505080` as `_DWORD *__stdcall(_DWORD *, char)` with callee `sub_4B7C30`, `0x00505430` with callees `sub_533090`, `sub_4B7C50`, `sub_505080`, `__wcsicmp`, `sub_4B7E80`, and `sub_50C120`, `0x00505650` with callees `sub_4B7CC0`, `sub_4B7C50`, `sub_505290`, and `sub_50C040`, and timer/object helpers `0x00505940`, `0x00505cc0`, and `0x00505de0` with the expected ObjectList and TimerHandler callees. Shared global evidence from that pass still ties `word_66DA9C` and `word_66DAA0` to `0x00505130`, `0x00505170`, and `0x005055e0`.

## IDA function inventory

`entity_query(kind=functions, min_addr=0x00503ef0, max_addr=0x00506380)` returned 35 modeled functions inside the aggregate and one successor at `0x00506380`.

| Start | IDA name | Size | Current disposition |
| --- | --- | ---: | --- |
| `0x00503ef0` | `sub_503EF0` | `0x19d` | Existing exact child coverage |
| `0x00504090` | `nullsub_40` | `0x3` | Existing exact child coverage |
| `0x005040a0` | `sub_5040A0` | `0x62` | Existing exact child coverage |
| `0x00504110` | `sub_504110` | `0x411` | Existing exact child coverage |
| `0x00504530` | `sub_504530` | `0x196` | Existing exact child coverage |
| `0x005046d0` | `sub_5046D0` | `0x118` | Existing exact child coverage |
| `0x005047f0` | `sub_5047F0` | `0x37b` | Existing exact child coverage |
| `0x00504b70` | `sub_504B70` | `0x1f` | Existing exact child coverage |
| `0x00504b90` | `sub_504B90` | `0x261` | Existing exact child coverage |
| `0x00504e00` | `sub_504E00` | `0x275` | Existing exact child coverage |
| `0x00505080` | `sub_505080` | `0x6b` | Planned exact child, include switch table through `0x00505100` |
| `0x00505100` | `sub_505100` | `0x24` | Existing `[UID:0001AQ]` file-level helper |
| `0x00505130` | `sub_505130` | `0x3a` | Planned exact child |
| `0x00505170` | `sub_505170` | `0x4b` | Planned exact child |
| `0x005051c0` | `sub_5051C0` | `0x68` | Existing `[UID:0001AR]` |
| `0x00505230` | `sub_505230` | `0x51` | Planned exact child |
| `0x00505290` | `sub_505290` | `0x74` | Planned exact child |
| `0x00505310` | `sub_505310` | `0x3d` | Planned exact child |
| `0x00505350` | `sub_505350` | `0x1b` | Planned exact child |
| `0x00505370` | `sub_505370` | `0x74` | Planned exact child |
| `0x00505430` | `sub_505430` | `0x19a` | Planned exact child |
| `0x005055d0` | `sub_5055D0` | `0xb` | Planned exact child |
| `0x005055e0` | `sub_5055E0` | `0x65` | Planned exact child |
| `0x00505650` | `sub_505650` | `0xce` | Planned exact child, include jump table through `0x00505730` |
| `0x00505730` | `nullsub_12` | `0x1` | Planned exact no-op callback child |
| `0x00505740` | `nullsub_41` | `0x3` | Planned exact no-op callback child |
| `0x005058b0` | `sub_5058B0` | `0x8e` | Existing `[UID:0002QL]` |
| `0x00505940` | `sub_505940` | `0x8b` | Planned exact child |
| `0x005059d0` | `sub_5059D0` | `0x228` | Existing `[UID:0002QM]` |
| `0x00505cc0` | `sub_505CC0` | `0x39` | Planned exact child |
| `0x00505de0` | `sub_505DE0` | `0x1e` | Planned exact child |
| `0x00505e00` | `sub_505E00` | `0x2e3` | Existing exact child coverage |
| `0x005060f0` | `sub_5060F0` | `0x79` | Existing exact child coverage |
| `0x00506170` | `sub_506170` | `0x63` | Existing exact child coverage |
| `0x005062f0` | `sub_5062F0` | `0x8a` | Existing exact child coverage |

Successor outside target: `0x00506380 sub_506380`, size `0x5b`.

## Remaining modeled helper findings

These findings are implementation-ready. Names are source-facing documentation recommendations only; do not edit the IDA DB during the callback unless a supervisor separately authorizes it.

| Range | Recommended child | Owner route | Evidence and proposed role |
| --- | --- | --- | --- |
| `0x00505080-0x00505100` | `MapPaneDirectionToTileOffset` | `[UID:0000L3]` file helper | `_DWORD *__stdcall(_DWORD *, char)`. Direction mapping is `0 -> {-1,0}`, `1 -> {0,1}`, `2 -> {1,0}`, `3 -> {0,-1}`, default `{0,0}`. Called broadly by MapPane, Living/ObjectPane, sound/effect, and movement helpers. Include switch table bytes at `0x005050eb-0x00505100`. |
| `0x00505130-0x0050516a` | `MapPaneMapToScreenCoords` | `[UID:00007Q]` | In-place map-tile to screen-pixel conversion using `+0x3fc/+0x400` tile origin and global tile dimensions `word_66DAA0/word_66DA9C`. Xrefs include MapPane input and object-pane drawing/update code. |
| `0x00505170-0x005051bb` | `MapPaneScreenToMapCoords` | `[UID:00007Q]` | Inverse in-place screen-pixel to map-tile conversion using tile dimensions and tile origin. Direct modeled xref from `0x00507150`. |
| `0x00505230-0x00505281` | `MapPaneValidateMapAndViewportCoords` | `[UID:00007Q]` | Boolean checks map coordinates against map width/height at `+0x3f4/+0x3f6` and viewport coordinates against visible extents `+0x404/+0x408`. |
| `0x00505290-0x00505304` | `MapPaneGetClampedVisibleTileBounds` | `[UID:00007Q]` | Builds expanded visible bounds from origin and extents, clamped to map dimensions. Called by draw, recenter, object update, and raw object refresh helpers. |
| `0x00505310-0x0050534d` | `MapPaneGetVisibleTileBounds` | `[UID:00007Q]` | Builds the visible bounds without dimension clamping. Single modeled xref from object update code at `0x005a2e00`. |
| `0x00505350-0x0050536b` | `MapPaneGetVisibleTileSpan` | `[UID:00007Q]` | Writes viewport span from `+0x404/+0x408`. Two modeled xrefs from `0x005a2530`. Insert the formal C++ block below using the row/column output convention from current coordinate support docs. |
| `0x00505370-0x005053e4` | `MapPaneGetExtendedVisibleTileBounds` | `[UID:00007Q]` | Clamped extended visible/object bounds, including a larger vertical margin. Called by recenter/object update and by a raw no-function body at `0x00505750`. |
| `0x00505430-0x005055ca` | `MapPaneCheckMovementCollision` | `[UID:00007Q]` | Directional movement/collision/nation-mask helper. Calls `DirectionToTileOffset`, object-list lookup, tile-layer helpers, `_wcsicmp(L"GM")`, and checks `g_objectNationMap`/direction mask globals. Returns allow/block/blocked-state values. |
| `0x005055d0-0x005055db` | `MapPaneAllowsMovementStatusTag` | `[UID:00007Q]` | Returns `this[0x40e] == 0`. Prior B reports tie the caller use to movement/status-history high-bit tagging, not day/night. Record `IsMovementGateClear` as a search alias, but do not use generated `IsDayMode`. |
| `0x005055e0-0x00505645` | `MapPaneApplyMovementSubstepScroll` | `[UID:00007Q]` | Uses `DirectionToTileOffset`, `byte_66DA96`, global tile dimensions, pixel origin fields `+0xac/+0xb0`, and invalidates the shifted viewport area through `sub_5549D0`. |
| `0x00505650-0x00505730` | `MapPaneGetAdjacentVisibleTileBounds` | `[UID:00007Q]` | Starts with clamped visible bounds, adjusts by movement direction, intersects with full map rect, optionally copies output, and calls `sub_50C040`. Include jump table data at `0x0050571e-0x00505730`. |
| `0x00505730-0x00505731` | `MapPaneAfterLocalPlayerWarp` | `[UID:00007Q]` | `nullsub_12`, one-byte `ret`. Called after user/local-player warp/correction flows, including modeled caller `0x005a76c0`. Source-authored no-op callback candidate. |
| `0x00505740-0x00505743` | `MapPaneObjectCallbackNoOp` | `[UID:00007Q]` | `nullsub_41`, `retn 4`. Raw caller at `0x0053c370` loads `g_activeMapPane`, calls `sub_506980`, then invokes this no-op with the same argument. Source role is a MapPane callback hook; keep original `nullsub_41` alias in notes. |
| `0x00505940-0x005059cb` | `MapPaneReindexObjectPanePosition` | `[UID:00007Q]` | Temporarily rewrites object-pane map coordinates, removes/readds the pane in `m_objectList`, then restores prior coordinates. Xrefs come from object and attachment movement/update flows. |
| `0x00505cc0-0x00505cf9` | `MapPaneClearQueuedMovementRefresh` | `[UID:00007Q]` | Clears byte `+0x39d`, invalidates timer ids `6` and `8` via `sub_597610(this+0xa4, id)`, and refreshes through `sub_5449F0`. |
| `0x00505de0-0x00505dfe` | `MapPaneClearPendingActionPoll` | `[UID:00007Q]` | Clears byte `+0x39e` and invalidates timer id `7` through `sub_597610(this+0xa4, 7)`. |

## Raw no-function helper findings

These ranges are the important new result from this pass. They are not IDA functions, not directly xrefed, and not referenced by pointer searches, but they are not padding. Each one should be made visible in the aggregate documentation so the source reconstruction preserves those code bytes.

| Range | Recommended child | Owner route | Evidence and disposition |
| --- | --- | --- | --- |
| `0x005053f0-0x0050542d` | `MapPaneGetUnclampedExtendedVisibleTileBounds` | `[UID:00007Q]` | Raw prologue/body reads `+0x3fc/+0x400/+0x404/+0x408`, writes an output rect with origin minus one and extended visible limits. Sibling to modeled `0x00505370`, but unclamped. No direct route found. Document as source-shaped MapPane helper with blank C++ under the no-route proof below. |
| `0x00505750-0x005057c8` | `MapPaneRawDirectionBoundsScratch` | `[UID:00007Q]` | Raw prologue/security-cookie body calls `0x00505370`, has direction switch table at `0x005057b8-0x005057c8`, but currently has no external effect beyond local stack state. No xrefs/pointers. Document as no-route scratch/helper body; no C++. |
| `0x005057d0-0x005058ac` | `MapPaneRawObjectCleanupSweep` | `[UID:00007Q]` | Raw body initializes a zero rect, so the visible loop is currently unreachable, but the latent path iterates object-list rows, gets object bounds, calls MapPane/object virtuals, removes list entries, performs cleanup, and returns at `0x005058ab`. No route found. Document as no-route object cleanup/sweep candidate; no C++. |
| `0x00505c00-0x00505cb1` | `MapPaneQueueMovementRefreshTimer6` | `[UID:00007Q]` | Raw body checks `byte_66DA97`, config byte `g_pConfig+0x28de5b`, stores pixel args to `+0x8ec/+0x8f0`, converts to tile coords, sleeps 100 ms, then if `+0x39d` and global busy state are clear schedules timer id `6`, sets `+0x39d`, refreshes, and returns at `0x00505cae`. No route found. |
| `0x00505d00-0x00505d9a` | `MapPaneQueueMovementRefreshTimer8` | `[UID:00007Q]` | Similar to the prior raw helper, but schedules timer id `8`, lacks the config-byte guard, and returns at `0x00505d97`. No route found. |
| `0x00505da0-0x00505dd2` | `MapPaneQueueActionPollTimer` | `[UID:00007Q]` | Raw body checks `+0x39e` and local-player/global state, sets `+0x39e`, schedules timer id `7` through `sub_5975E0(this+0xa4, 7, 0, 0, 0)`, and returns at `0x00505dd1`. No route found. |
| `0x005061e0-0x005062e5` | `MapPaneRefreshNearbyObjectRows` | `[UID:00007Q]` | Raw body uses `m_objectList`, byte `+0x3f0`, vtable rect getters, `GetClampedVisibleTileBounds`, object-list row iteration, object positions, visible-overlap refresh methods, and returns at `0x005062e2`. No route found. Document as no-route object-row refresh helper; no C++. |

## Gap and padding analysis

The parent range must not call every gap padding. The exact split should separate code, jump tables, and CC alignment.

| Gap | Finding |
| --- | --- |
| `0x005050eb-0x00505100` | Switch table for `DirectionToTileOffset`; attach to `0x00505080-0x00505100`, not padding. |
| `0x00505124-0x00505130` | Pure `0xcc` alignment. |
| `0x0050516a-0x00505170` | Pure `0xcc` alignment. |
| `0x005051bb-0x005051c0` | Pure `0xcc` alignment. |
| `0x00505228-0x00505230` | Pure `0xcc` alignment. |
| `0x00505281-0x00505290` | Pure `0xcc` alignment. |
| `0x00505304-0x00505310` | Pure `0xcc` alignment. |
| `0x0050534d-0x00505350` | Pure `0xcc` alignment. |
| `0x0050536b-0x00505370` | Pure `0xcc` alignment. |
| `0x005053e4-0x00505430` | `0x005053e4-0x005053f0` CC alignment, raw helper `0x005053f0-0x0050542d`, then CC alignment to `0x00505430`. |
| `0x005055ca-0x005055d0` | Pure `0xcc` alignment. |
| `0x005055db-0x005055e0` | Pure `0xcc` alignment. |
| `0x00505645-0x00505650` | Pure `0xcc` alignment. |
| `0x0050571e-0x00505730` | Jump table/data for `0x00505650`; attach to adjacent-bounds child. |
| `0x00505731-0x00505740` | Pure `0xcc` alignment after `nullsub_12`. |
| `0x00505743-0x005058b0` | `0x00505743-0x00505750` CC alignment, raw helper `0x00505750-0x005057c8` including switch table, `0x005057c8-0x005057d0` CC alignment, raw helper `0x005057d0-0x005058ac`, then `0x005058ac-0x005058b0` CC alignment. |
| `0x0050593e-0x00505940` | Pure `0xcc` alignment. |
| `0x005059cb-0x005059d0` | Pure `0xcc` alignment. |
| `0x00505bf8-0x00505cc0` | `0x00505bf8-0x00505c00` CC alignment, raw helper `0x00505c00-0x00505cb1`, then `0x00505cb1-0x00505cc0` CC alignment. |
| `0x00505cf9-0x00505de0` | `0x00505cf9-0x00505d00` CC alignment, raw helper `0x00505d00-0x00505d9a`, `0x00505d9a-0x00505da0` CC alignment, raw helper `0x00505da0-0x00505dd2`, then `0x00505dd2-0x00505de0` CC alignment. |
| `0x00505dfe-0x00505e00` | Pure `0xcc` alignment. |
| `0x005060e3-0x005060f0` | Pure `0xcc` alignment. |
| `0x00506169-0x00506170` | Pure `0xcc` alignment. |
| `0x005061d3-0x005062f0` | `0x005061d3-0x005061e0` CC alignment, raw helper `0x005061e0-0x005062e5`, then `0x005062e5-0x005062f0` CC alignment. |
| `0x0050637a-0x00506380` | Pure `0xcc` alignment before successor `0x00506380`. |

`by-memory/-ignored.md` already lists the modeled-function alignment spans through `0x00506169-0x00506170` plus `0x0050637a-0x00506380`. The implementation callback should add only these raw-helper-adjacent CC spans if the supervisor accepts the split: `0x005053e4-0x005053f0`, `0x0050542d-0x00505430`, `0x00505743-0x00505750`, `0x005057c8-0x005057d0`, `0x005058ac-0x005058b0`, `0x00505bf8-0x00505c00`, `0x00505cb1-0x00505cc0`, `0x00505cf9-0x00505d00`, `0x00505d9a-0x00505da0`, `0x00505dd2-0x00505de0`, `0x005061d3-0x005061e0`, and `0x005062e5-0x005062f0`. Current MCP `get_bytes` confirmed each of those spans is all `0xcc`; do not add jump tables or raw helper bodies as ignored padding.

## Caller/data-flow highlights

The caller graph supports the MapPane/file-level placement:

- `DirectionToTileOffset` has 32 code xrefs and is a file-level map-direction utility used by MapPane and several object/movement/effect systems. It should sit under `map/MapPane.cpp` as a helper, not as an ObjectPane owner.
- `MapPaneMapToScreenCoords` and `MapPaneScreenToMapCoords` bridge MapPane input and object rendering/update code. They operate on `this` MapPane layout fields and should be class methods.
- The bounds helpers are used by `[UID:0001AR] DrawVisibleTilesHelper`, `[UID:0002QM] RecenterAndSendPosition`, object pane update code, and raw object refresh bodies. They are MapPane viewport helpers.
- `MapPaneCheckMovementCollision` calls ObjectList and nation-map/tile-layer helpers, but the receiver object and field layout are MapPane. ObjectList and nation-map are dependencies, not owners.
- `MapPaneAllowsMovementStatusTag` is used by movement/status-history packet handlers and local-object flows. Its only local behavior is checking MapPane byte `+0x40e`.
- `MapPaneClearQueuedMovementRefresh` and `MapPaneClearPendingActionPoll` are paired with raw timer-queue helpers around `0x00505c00`, `0x00505d00`, and `0x00505da0`; the timer state bytes are MapPane fields.

## Ranked ownership

1. `[UID:00007Q] MapPane` is the canonical owner for the aggregate and for almost all remaining helper children. The receiver layout, viewport/tile fields, object-list field, event/timer state bytes, and caller context all match MapPane.
2. `[UID:0000L3] map/MapPane.cpp` is the best route for file-level helper `DirectionToTileOffset` because it has no `this` receiver and is called outside MapPane. This matches existing `[UID:0001AQ] ScaleDirectionOffsetToPixels`, which is already file-owned/emitted by the file root.
3. `[UID:00007R] MapPaneSpatialIndex`/ObjectList is a dependency only. It should not take ownership of `MapPaneReindexObjectPanePosition` or the object-row raw helper because those functions are MapPane methods operating on `this+0x424`.
4. LivingObjectPane/UserPane/Sound/Attachment callers are consumers only. Their xrefs explain why some helper names should avoid narrow camera-only or day/night-only terminology.
5. No-owner/non-emitting placement is rejected for the modeled helper functions. For raw no-route helpers, owner should still be documented as MapPane, while child C++ emission stays blank under the current no-function/no-xref/no-pointer proof.

## Source placement

Recommended source placement:

- Aggregate `[UID:0001AP]`: remains a MapPane by-memory aggregate and high-level coverage/index page.
- Class child methods: `NexusTK/map/MapPane.cpp`, class `[UID:00007Q] MapPane`.
- File-static/free helper: `DirectionToTileOffset` under `[UID:0000L3] map/MapPane.cpp`, sibling to `[UID:0001AQ]`.
- Raw no-route helpers: document as MapPane/source-shaped children with blank C++ and explicit no-route evidence.

The existing source path `auto-generated/NexusTK/map/MapPane.cpp` should remain the generated route. No new file root is required.

## Naming and type recommendations

Use the source-facing names below in documentation and only use generated C++ where this report supplies exact formal insertion text. Do not rename in IDA during this report-only assignment.

Recommended stable names:

- `DirectionToTileOffset` for `0x00505080`. Avoid `CameraDirection*`; the caller set is wider than camera scrolling.
- `MapPaneMapToScreenCoords` and `MapPaneScreenToMapCoords` for `0x00505130` and `0x00505170`.
- `MapPaneGetClampedVisibleTileBounds`, `MapPaneGetVisibleTileBounds`, `MapPaneGetVisibleTileSpan`, `MapPaneGetExtendedVisibleTileBounds`, and `MapPaneGetUnclampedExtendedVisibleTileBounds` for the bounds family.
- `MapPaneCheckMovementCollision` for `0x00505430`; record that it returns allow/block/blocked-state values and is not a pure bool.
- `MapPaneAllowsMovementStatusTag` for `0x005055d0`; record aliases `IsMovementStatusTagAllowed` and `IsMovementGateClear`, and reject `IsDayMode`.
- `MapPaneApplyMovementSubstepScroll` for `0x005055e0`.
- `MapPaneGetAdjacentVisibleTileBounds` for `0x00505650`.
- `MapPaneReindexObjectPanePosition` for `0x00505940`.
- `MapPaneQueueMovementRefreshTimer6`, `MapPaneQueueMovementRefreshTimer8`, `MapPaneQueueActionPollTimer`, `MapPaneClearQueuedMovementRefresh`, and `MapPaneClearPendingActionPoll` for the timer group.
- `MapPaneRefreshNearbyObjectRows` for raw `0x005061e0`.

Field/type names to update or cross-reference in `[UID:00007Q] by-class/MapPane.md`:

- `+0x39d`: queued movement/map-state refresh flag, paired with timer ids `6` and `8`.
- `+0x39e`: pending action poll flag, paired with timer id `7`.
- `+0x3fc/+0x400`: tile origin fields used by coordinate conversion and bounds helpers.
- `+0x404/+0x408`: visible tile span/extents.
- `+0x40e`: movement/status tag gate, not day/night.
- `+0x424`: `m_objectList`.
- `+0x8ec/+0x8f0`: temporary queued movement/event pixel or converted tile coordinate storage used by raw timer-queue helpers.

## Heuristic / Inference Reanalysis And Validation

This 2026-06-25 rework resolves the supervisor rejection note in `SupervisorAssignments.md`: the split plan no longer defers child-level C++ disposition. Every proposed child now has either formal `RECONSTRUCTION_CPP CODE` insertion text or a target-specific blank-C++/no-code proof.

- Generated labels: keep `sub_505080`, `sub_505130`, `sub_505170`, `sub_505230`, `sub_505290`, `sub_505310`, `sub_505350`, `sub_505370`, `sub_505430`, `sub_5055D0`, `sub_5055E0`, `sub_505650`, `sub_505940`, `sub_505CC0`, and `sub_505DE0` only as search aliases. The recommended source-facing names are role names backed by current MCP component/xref evidence, disassembly where needed, and MapPane field access.
- Raw helper liveness: `lookup_funcs` reports `Not a function` for `0x005053f0`, `0x00505750`, `0x005057d0`, `0x00505c00`, `0x00505d00`, `0x00505da0`, and `0x005061e0`. Current `xrefs_to` returns zero incoming refs for each start and little-endian pointer-pattern searches return zero matches, but `insn_query` over each range shows real prologue/body instructions, MapPane field reads/writes, calls, switch tables, object-list/timer behavior, or security-cookie patterns. Therefore these are source-shaped MapPane bodies with no current entry route, not padding.
- Jump-table/data distinction: `0x005050eb-0x00505100` belongs to `DirectionToTileOffset`; `0x0050571e-0x00505730` belongs to `MapPaneGetAdjacentVisibleTileBounds`; `0x005057b8-0x005057c8` belongs to raw `MapPaneRawDirectionBoundsScratch`. Do not record those spans as ignored padding.
- Owner/source route: [UID:00007Q] `MapPane` remains the direct semantic owner for the aggregate and most children because the receiver fields are MapPane layout fields. [UID:0000L3] `MapPane.cpp` remains the file root and direct owner/emitter for the no-`this` file helper `DirectionToTileOffset`, matching [UID:0001AQ] `ScaleDirectionOffsetToPixels`.
- Rejected alternatives: `MapPaneSpatialIndex`/ObjectList is a dependency for object-list calls, not the owner of MapPane receiver methods; LivingObjectPane/UserPane/Sound/Attachment callers are consumers; no-owner/non-emitting is rejected for modeled functions with clear MapPane receiver evidence; raw no-route helpers are owner-documented with blank C++ under the current no-function/no-xref/no-pointer proof.
- Stale material: no current Wave2/Wave3 instruction overrides this analysis. Existing generated names and old raw labels were treated as leads only and rejected when current MCP/body evidence supported better source-facing roles.

## First-draft C++ gate

Do not add a monolithic aggregate method body for `[UID:0001AP]`. Do add a formal marker/comment block because the aggregate remains `RECONSTRUCTABLE:TRUE` and emits through `[UID:00007Q]`.

Formal aggregate `RECONSTRUCTION_CPP CODE` insertion text:

```cpp
// Emitted code for this aggregate is covered by exact child pages nested under [UID:0001AP].
// [UID:0001AP] is a MapPane source-range aggregate/index, not a monolithic source function.
// Exact child pages own the MapPane.cpp method/helper bodies, jump tables, raw no-route evidence, and alignment classification.
```

Marker proof:

- The target spans many independent functions, exact child pages, raw no-function bodies, jump tables, and alignment.
- Several child pages already own exact method/helper bodies and emit through `[UID:00007Q]` or `[UID:0000L3]`.
- A single aggregate function body would conflate child ownership and duplicate emitted child code.
- The marker satisfies the current emitting-aggregate rule without pretending the aggregate itself is one source function.

Child-level C++ disposition for the implementation callback:

| Proposed child | Initial C++ disposition | Reason |
| --- | --- | --- |
| `0x00505080-0x00505100.MapPaneDirectionToTileOffset` | Insert formal C++ below. | Stable file helper, broad caller set, no `this`, exact switch mapping, switch table attached to child. |
| `0x00505130-0x0050516a.MapPaneMapToScreenCoords` | Insert formal C++ below. | Current MCP component/xref evidence plus [UID:0000T7] and [UID:0003XP] resolve the storage convention: pair element 0 is row/Y-like and element 1 is column/X-like. Use row/column source names to preserve the observed order. |
| `0x00505170-0x005051bb.MapPaneScreenToMapCoords` | Insert formal C++ below. | Inverse arithmetic is exact under the same row/column convention; no current blocker remains after checking the coordinate support pages. |
| `0x00505230-0x00505281.MapPaneValidateMapAndViewportCoords` | Insert formal C++ below. | Stable boolean bounds helper over map dimensions and visible extents. |
| `0x00505290-0x00505304.MapPaneGetClampedVisibleTileBounds` | Insert formal C++ below. | Stable `MapRect` builder used by existing [UID:0001AR] first-draft C++; helper name and fields are already accepted in support docs. |
| `0x00505310-0x0050534d.MapPaneGetVisibleTileBounds` | Insert formal C++ below. | Same rectangle layout as clamped helper, without map-dimension clipping. |
| `0x00505350-0x0050536b.MapPaneGetVisibleTileSpan` | Insert formal C++ below. | Current MapPane field glossary names `+0x404/+0x408` as visible tile columns/rows. The row/column output convention preserves the decompiled store order. |
| `0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds` | Insert formal C++ below. | Stable clamped rectangle builder with larger bottom reach; current callers and raw sibling use this exact helper. |
| `0x005053f0-0x0050542d.MapPaneGetUnclampedExtendedVisibleTileBounds` | Blank C++; initial recommended score `85/85`, blank `EMITTER_UIDS`. | Raw source-shaped MapPane helper with no IDA function, no xrefs, and no pointer route. Document body and owner; current evidence does not support formal emitted C++. |
| `0x00505430-0x005055ca.MapPaneCheckMovementCollision` | Insert formal C++ below. | Current MCP component/callee evidence, existing `0x0050c120` docs, and direction-mask/global pages support the inferred helper/type names. Preserve the observed `-1/0/1` int return. |
| `0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag` | Insert formal C++ below. | Stable one-byte gate over `+0x40e`; prior reports reject day/night naming. |
| `0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll` | Insert formal C++ below. | Current MCP component evidence confirms the `DirectionToTileOffset` and shifted-region invalidation callees plus shared tile width/height globals. Use inferred `InvalidateShiftedMapArea` name. |
| `0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds` | Insert formal C++ below. | Current MCP component evidence and existing callee docs support the switch-table semantics, `SetRect`, `IntersectRect`, and tile-checksum helper names. |
| `0x00505730-0x00505731.MapPaneAfterLocalPlayerWarp` | Insert formal empty C++ below. | One-byte `ret` plus current caller notes support a no-argument MapPane callback after local-player warp/correction. |
| `0x00505740-0x00505743.MapPaneObjectCallbackNoOp` | Insert formal empty C++ below. | `retn 4` proves a one-argument MapPane callback/stub; current caller evidence is enough to emit the empty callback with an inferred argument name. |
| `0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch` | Blank C++; initial recommended score `85/85`, blank `EMITTER_UIDS`. | Raw no-function helper, no direct xrefs/pointers, and current instruction scan shows no committed external side effect beyond local scratch state. |
| `0x005057d0-0x005058ac.MapPaneRawObjectCleanupSweep` | Blank C++; initial recommended score `85/85`, blank `EMITTER_UIDS`. | Raw no-function body has object-list cleanup semantics, ends with `retn` at `0x005058ab`, but has no route and a currently zero-initialized rectangle path; C++ would invent reachability. |
| `0x00505940-0x005059cb.MapPaneReindexObjectPanePosition` | Insert formal C++ below. | Current MCP plus [UID:0001VG] and [UID:0003XP] resolve ObjectPane row/column storage and ObjectList remove/add helper roles enough for source-shaped code. |
| `0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6` | Blank C++; initial recommended score `85/85`, blank `EMITTER_UIDS`. | Raw no-function timer queue helper ending with `retn 8` at `0x00505cae`; document field writes, config guard, sleep, timer id `6`, and no-route proof. |
| `0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh` | Insert formal C++ below. | Current notify/timer children already emit `m_timerHandler.CancelTimer` and `RefreshQueuedMapState`; this helper is the exact reusable clearer for ids `6` and `8`. |
| `0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8` | Blank C++; initial recommended score `85/85`, blank `EMITTER_UIDS`. | Raw no-function timer queue helper ending with `retn 8` at `0x00505d97`; document timer id `8` behavior and no-route proof. |
| `0x00505da0-0x00505dd2.MapPaneQueueActionPollTimer` | Blank C++; initial recommended score `85/85`, blank `EMITTER_UIDS`. | Raw no-function action-poll timer helper ending with `retn` at `0x00505dd1`; document timer id `7` scheduling and no-route proof. |
| `0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll` | Insert formal C++ below. | Current timer child already emits `ClearPendingActionPoll` and `CancelTimer(7)`; no current blocker remains. |
| `0x005061e0-0x005062e5.MapPaneRefreshNearbyObjectRows` | Blank C++; initial recommended score `85/85`, blank `EMITTER_UIDS`. | Raw no-function object-row refresh helper ending with `retn 8` at `0x005062e2`; clear MapPane field use exists, but no xref/pointer route exists, so C++ would invent call reachability. |

Exact child metadata ledger:

| Proposed child | Completion | Confidence | CANONICAL_OWNER | RECONSTRUCTABLE | EMITTER_UIDS | EMITTER_POSITION_OPTIONAL | Formal C++ disposition |
| --- | ---: | ---: | --- | --- | --- | --- | --- |
| `0x00505080-0x00505100.MapPaneDirectionToTileOffset` | 88 | 91 | `0000L3` | `TRUE` | `0000L3` | blank | formal C++ |
| `0x00505130-0x0050516a.MapPaneMapToScreenCoords` | 86 | 88 | `00007Q` | `TRUE` | `00007Q` | blank | formal C++ |
| `0x00505170-0x005051bb.MapPaneScreenToMapCoords` | 86 | 88 | `00007Q` | `TRUE` | `00007Q` | blank | formal C++ |
| `0x00505230-0x00505281.MapPaneValidateMapAndViewportCoords` | 87 | 90 | `00007Q` | `TRUE` | `00007Q` | blank | formal C++ |
| `0x00505290-0x00505304.MapPaneGetClampedVisibleTileBounds` | 88 | 90 | `00007Q` | `TRUE` | `00007Q` | blank | formal C++ |
| `0x00505310-0x0050534d.MapPaneGetVisibleTileBounds` | 87 | 89 | `00007Q` | `TRUE` | `00007Q` | blank | formal C++ |
| `0x00505350-0x0050536b.MapPaneGetVisibleTileSpan` | 86 | 88 | `00007Q` | `TRUE` | `00007Q` | blank | formal C++ |
| `0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds` | 88 | 90 | `00007Q` | `TRUE` | `00007Q` | blank | formal C++ |
| `0x005053f0-0x0050542d.MapPaneGetUnclampedExtendedVisibleTileBounds` | 85 | 85 | `00007Q` | `TRUE` | blank | blank | blank C++; raw no-route |
| `0x00505430-0x005055ca.MapPaneCheckMovementCollision` | 86 | 87 | `00007Q` | `TRUE` | `00007Q` | blank | formal C++ |
| `0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag` | 87 | 90 | `00007Q` | `TRUE` | `00007Q` | blank | formal C++ |
| `0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll` | 86 | 88 | `00007Q` | `TRUE` | `00007Q` | blank | formal C++ |
| `0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds` | 86 | 88 | `00007Q` | `TRUE` | `00007Q` | blank | formal C++ |
| `0x00505730-0x00505731.MapPaneAfterLocalPlayerWarp` | 86 | 88 | `00007Q` | `TRUE` | `00007Q` | blank | formal C++ empty callback |
| `0x00505740-0x00505743.MapPaneObjectCallbackNoOp` | 86 | 87 | `00007Q` | `TRUE` | `00007Q` | blank | formal C++ empty callback |
| `0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch` | 85 | 85 | `00007Q` | `TRUE` | blank | blank | blank C++; raw no-route |
| `0x005057d0-0x005058ac.MapPaneRawObjectCleanupSweep` | 85 | 85 | `00007Q` | `TRUE` | blank | blank | blank C++; raw no-route |
| `0x00505940-0x005059cb.MapPaneReindexObjectPanePosition` | 86 | 88 | `00007Q` | `TRUE` | `00007Q` | blank | formal C++ |
| `0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6` | 85 | 85 | `00007Q` | `TRUE` | blank | blank | blank C++; raw no-route |
| `0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh` | 87 | 89 | `00007Q` | `TRUE` | `00007Q` | blank | formal C++ |
| `0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8` | 85 | 85 | `00007Q` | `TRUE` | blank | blank | blank C++; raw no-route |
| `0x00505da0-0x00505dd2.MapPaneQueueActionPollTimer` | 85 | 85 | `00007Q` | `TRUE` | blank | blank | blank C++; raw no-route |
| `0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll` | 87 | 89 | `00007Q` | `TRUE` | `00007Q` | blank | formal C++ |
| `0x005061e0-0x005062e5.MapPaneRefreshNearbyObjectRows` | 85 | 85 | `00007Q` | `TRUE` | blank | blank | blank C++; raw no-route |

Formal C++ insertion text for the children marked above:

`0x00505080-0x00505100.MapPaneDirectionToTileOffset`

```cpp
static MapPoint *DirectionToTileOffset(MapPoint *outOffset, unsigned char direction)
{
    switch (direction)
    {
    case 0:
        SetPoint(outOffset, -1, 0);
        break;
    case 1:
        SetPoint(outOffset, 0, 1);
        break;
    case 2:
        SetPoint(outOffset, 1, 0);
        break;
    case 3:
        SetPoint(outOffset, 0, -1);
        break;
    default:
        SetPoint(outOffset, 0, 0);
        break;
    }

    return outOffset;
}
```

`0x00505130-0x0050516a.MapPaneMapToScreenCoords`

```cpp
void MapPane::MapToScreenCoords(MapPoint *point) const
{
    const int row = point->row - m_tileOriginY + 1;

    point->column = (point->column - m_tileOriginX + 1) * g_mapTilePixelWidth;
    point->row = row * g_mapTilePixelHeight;
}
```

`0x00505170-0x005051bb.MapPaneScreenToMapCoords`

```cpp
void MapPane::ScreenToMapCoords(MapPoint *point) const
{
    const int row = point->row / g_mapTilePixelHeight;

    point->column = point->column / g_mapTilePixelWidth + m_tileOriginX - 1;
    point->row = row + m_tileOriginY - 1;
}
```

`0x00505230-0x00505281.MapPaneValidateMapAndViewportCoords`

```cpp
bool MapPane::ValidateMapAndViewportCoords(int mapColumn,
                                           int mapRow,
                                           int viewportColumn,
                                           int viewportRow) const
{
    return mapColumn >= 0 &&
           mapColumn < m_mapWidth &&
           mapRow >= 0 &&
           mapRow < m_mapHeight &&
           viewportColumn >= 0 &&
           viewportColumn < m_visibleTileColumns &&
           viewportRow >= 0 &&
           viewportRow < m_visibleTileRows;
}
```

`0x00505290-0x00505304.MapPaneGetClampedVisibleTileBounds`

```cpp
void MapPane::GetClampedVisibleTileBounds(MapRect *outBounds) const
{
    outBounds->top = m_tileOriginY - 1;
    outBounds->left = m_tileOriginX - 1;
    outBounds->bottom = outBounds->top + m_visibleTileRows + 2;
    outBounds->right = outBounds->left + m_visibleTileColumns + 2;

    if (outBounds->top < 0)
        outBounds->top = 0;
    if (outBounds->left < 0)
        outBounds->left = 0;
    if (outBounds->bottom > m_mapHeight)
        outBounds->bottom = m_mapHeight;
    if (outBounds->right > m_mapWidth)
        outBounds->right = m_mapWidth;
}
```

`0x00505310-0x0050534d.MapPaneGetVisibleTileBounds`

```cpp
void MapPane::GetVisibleTileBounds(MapRect *outBounds) const
{
    outBounds->top = m_tileOriginY - 1;
    outBounds->left = m_tileOriginX - 1;
    outBounds->bottom = outBounds->top + m_visibleTileRows + 2;
    outBounds->right = outBounds->left + m_visibleTileColumns + 2;
}
```

`0x00505350-0x0050536b.MapPaneGetVisibleTileSpan`

```cpp
MapPoint *MapPane::GetVisibleTileSpan(MapPoint *outSpan) const
{
    outSpan->row = m_visibleTileRows;
    outSpan->column = m_visibleTileColumns;
    return outSpan;
}
```

`0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds`

```cpp
void MapPane::GetExtendedVisibleTileBounds(MapRect *outBounds) const
{
    outBounds->top = m_tileOriginY - 1;
    outBounds->left = m_tileOriginX - 1;
    outBounds->bottom = outBounds->top + m_visibleTileRows + 10;
    outBounds->right = outBounds->left + m_visibleTileColumns + 2;

    if (outBounds->top < 0)
        outBounds->top = 0;
    if (outBounds->left < 0)
        outBounds->left = 0;
    if (outBounds->bottom > m_mapHeight)
        outBounds->bottom = m_mapHeight;
    if (outBounds->right > m_mapWidth)
        outBounds->right = m_mapWidth;
}
```

`0x00505430-0x005055ca.MapPaneCheckMovementCollision`

```cpp
int MapPane::CheckMovementCollision(int mapColumn, int mapRow, unsigned char direction)
{
    MapPoint offset;
    DirectionToTileOffset(&offset, direction);

    const int nextColumn = mapColumn + offset.column;
    const int nextRow = mapRow + offset.row;

    MapRect mapBounds;
    SetRect(&mapBounds, 0, 0, m_mapWidth, m_mapHeight);
    if (!PointInRect(nextRow, nextColumn, &mapBounds))
        return -1;

    if (m_activeObjectPane != NULL && m_activeObjectPane->AllowsMovementCollisionBypass())
        return 1;

    ObjectPane *blockingObject = m_objectList->FindObjectAtMapPoint(nextColumn, nextRow);
    if (blockingObject != NULL)
    {
        if (_wcsicmp(blockingObject->GetObjectName(), L"GM") != 0 &&
            !blockingObject->IsMovementPassable())
        {
            return 0;
        }
    }

    MapTileLayerIds currentTile;
    MapTileLayerIds nextTile;
    GetLegacyAwareMapTileLayerIds(&currentTile, mapColumn, mapRow);
    GetLegacyAwareMapTileLayerIds(&nextTile, nextColumn, nextRow);

    if ((g_objectRecordCount >= currentTile.objectNation ||
         g_objectRecordCount >= nextTile.objectNation) &&
        (g_objectNationMap[currentTile.objectNation] & s_objectDirectionMasks[direction]) == 0 &&
        (g_objectNationMap[nextTile.objectNation] & s_objectReverseDirectionMasks[direction]) == 0 &&
        nextTile.groundTileId != 0 &&
        (nextTile.flags & 0x10000) == 0)
    {
        return 1;
    }

    return -1;
}
```

`0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag`

```cpp
bool MapPane::AllowsMovementStatusTag() const
{
    return m_movementGate == 0;
}
```

`0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll`

```cpp
bool MapPane::ApplyMovementSubstepScroll(unsigned char direction)
{
    MapPoint offset;
    DirectionToTileOffset(&offset, direction);

    const int substepDivisor = 4 * g_movementSubstepScale;
    const int deltaX = offset.column * g_mapTilePixelWidth / substepDivisor;
    const int deltaY = offset.row * g_mapTilePixelHeight / substepDivisor;

    m_viewportPixelX += deltaX;
    m_viewportPixelY += deltaY;

    return InvalidateShiftedMapArea(-deltaX, -deltaY);
}
```

`0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds`

```cpp
unsigned short MapPane::GetAdjacentVisibleTileBounds(unsigned char direction,
                                                     MapRect *outBounds) const
{
    MapRect bounds;
    GetClampedVisibleTileBounds(&bounds);

    switch (direction)
    {
    case 0:
        bounds.bottom = bounds.top;
        --bounds.top;
        break;

    case 1:
        bounds.left = bounds.right;
        ++bounds.right;
        break;

    case 2:
        bounds.top = bounds.bottom;
        ++bounds.bottom;
        break;

    case 3:
        bounds.right = bounds.left;
        --bounds.left;
        break;

    default:
        SetRect(&bounds, 0, 0, 0, 0);
        break;
    }

    MapRect mapBounds;
    SetRect(&mapBounds, 0, 0, m_mapWidth, m_mapHeight);
    IntersectRect(&bounds, &mapBounds, &bounds);

    if (outBounds != NULL)
        *outBounds = bounds;

    return ComputeTileRectChecksum(&bounds);
}
```

`0x00505730-0x00505731.MapPaneAfterLocalPlayerWarp`

```cpp
void MapPane::AfterLocalPlayerWarp()
{
}
```

`0x00505740-0x00505743.MapPaneObjectCallbackNoOp`

```cpp
void MapPane::ObjectCallbackNoOp(ObjectPane *)
{
}
```

`0x00505940-0x005059cb.MapPaneReindexObjectPanePosition`

```cpp
void MapPane::ReindexObjectPanePosition(ObjectPane *objectPane,
                                        int removeRow,
                                        int removeColumn,
                                        int addRow,
                                        int addColumn)
{
    if (m_objectList == NULL)
        return;

    if (!m_objectList->HasValidGridOrigin())
        return;

    MapPoint savedPosition;
    objectPane->GetMapPosition(&savedPosition);

    objectPane->m_mapColumn = removeColumn;
    objectPane->m_mapRow = removeRow;
    m_objectList->RemoveObjectPane(objectPane);

    objectPane->m_mapColumn = addColumn;
    objectPane->m_mapRow = addRow;
    m_objectList->AddObjectPane(objectPane);

    objectPane->m_mapColumn = savedPosition.column;
    objectPane->m_mapRow = savedPosition.row;
}
```

`0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh`

```cpp
void MapPane::ClearQueuedMapStateRefresh()
{
    if (m_queuedMapStateRefresh)
    {
        m_queuedMapStateRefresh = false;
        m_timerHandler.CancelTimer(6);
        m_timerHandler.CancelTimer(8);
        RefreshQueuedMapState();
    }
}
```

`0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll`

```cpp
void MapPane::ClearPendingActionPoll()
{
    if (m_pendingActionPoll)
    {
        m_pendingActionPoll = false;
        m_timerHandler.CancelTimer(7);
    }
}
```

Blank-C++ children after this correction are only the raw no-route helpers. Their current proof is target-specific: current MCP `lookup_funcs` says each raw start is not a function, current `xrefs_to` reports zero incoming refs to each start, current `find_bytes` pointer-pattern searches found no pointer-table routes, and instruction scans show source-shaped MapPane bodies whose entry/reachability cannot be represented as emitted C++ without inventing call routes. Their child pages should document the body bytes and owner evidence, leave `EMITTER_UIDS` blank, and keep formal C++ blank.

## Score and metadata recommendation

During report-only work, keep the target header unchanged in the repository.

Recommended post-implementation aggregate metadata, after the exact child split and support-doc synchronization:

- `CANONICAL_OWNER: 00007Q` unchanged
- `RECONSTRUCTABLE: TRUE` unchanged
- `EMITTER_UIDS: 00007Q` unchanged for the aggregate marker/MapPane route
- `EMITTER_POSITION_OPTIONAL:` blank
- `RECONSTRUCTION_CPP CODE`: insert the formal aggregate marker block supplied in this report
- `COMPLETION: 90`
- `CONFIDENCE: 91`

Rationale for not recommending a higher score yet:

- Exact child pages for remaining helpers do not exist yet.
- Raw no-function helpers have no direct route/xref evidence, even though their MapPane field use is clear.
- The only blank child C++ cases after correction are raw no-route helpers with current no-function/no-xref/no-pointer proof.
- Some formal child C++ uses best-supported source-facing inferred names for helper/type fields, especially `MapPoint` row/column, `MapTileLayerIds`, ObjectList helper roles, and the timer refresh facade.
- The aggregate is still a split/index range; the marker is formal emitted documentation, not a monolithic MapPane method.

If an implementation callback only updates the parent narrative without creating child pages, keep the score near the current `86/89` or at most `88/90`; the split is the meaningful source-quality improvement.

## Required target and support-document updates

Update `[UID:0001AP]`:

- Add the 2026-06-25 IDA MCP session evidence and note that MCP was available.
- Replace the remaining unsplit modeled-helper notes with exact child-page references once UIDs are assigned.
- Add a raw no-function helper table for `0x005053f0`, `0x00505750`, `0x005057d0`, `0x00505c00`, `0x00505d00`, `0x00505da0`, and `0x005061e0`.
- Add the gap/padding table, explicitly distinguishing CC alignment, jump-table data, and raw helpers.
- Insert the formal aggregate marker block in `RECONSTRUCTION_CPP CODE`; do not leave the emitting aggregate with a blank C++ section.
- Add or mirror the exact child metadata ledger values from this report when creating child pages.
- Update score rationale to explain why child split and raw-helper documentation are the next gate.

Update `[UID:00007Q] by-class/MapPane.md`:

- Replace the current prioritized backlog entry for coordinate/object interior helpers with the exact helper names and child links.
- Add or refine field glossary entries for `+0x39d`, `+0x39e`, `+0x40e`, `+0x8ec`, and `+0x8f0`.
- Record the no-op callback roles and raw no-route helper evidence.
- Keep class-level C++ blank unless a separate class-layout callback stabilizes the full structure and method declarations.

Update `[UID:0000L3] by-file/MapPane.md`:

- Add `DirectionToTileOffset` as a file-level helper sibling of `[UID:0001AQ] ScaleDirectionOffsetToPixels`.
- Record that the remaining coordinate/bounds/object/timer helpers source to `map/MapPane.cpp`.
- Note that raw no-route helpers are documented but not emitted as C++ yet.

Update existing exact child pages:

- `[UID:0001AQ] ScaleDirectionOffsetToPixels`: cross-reference `DirectionToTileOffset` as the direction-vector producer once the new child UID exists.
- `[UID:0001AR] DrawVisibleTilesHelper`: link its clamped-bounds callee to `MapPaneGetClampedVisibleTileBounds`.
- `[UID:0002QL] MapPaneScrollViewportByDirection`: link `DirectionToTileOffset` and `MapPaneGetAdjacentVisibleTileBounds` once created.
- `[UID:0002QM] MapPaneRecenterAndSendPosition`: replace the current "next function-shaped body" note after `0x00505bf8` with a link to raw helper `MapPaneQueueMovementRefreshTimer6`.
- Notify/timer-related MapPane pages should link the `+0x39d/+0x39e` clearers and queue helpers where they already discuss timer ids `6`, `7`, and `8`.

Update `[UID:0000VN] by-memory/-ignored.md`:

- Add only the exact raw-helper-adjacent pure `0xcc` spans listed in this report: `0x005053e4-0x005053f0`, `0x0050542d-0x00505430`, `0x00505743-0x00505750`, `0x005057c8-0x005057d0`, `0x005058ac-0x005058b0`, `0x00505bf8-0x00505c00`, `0x00505cb1-0x00505cc0`, `0x00505cf9-0x00505d00`, `0x00505d9a-0x00505da0`, `0x00505dd2-0x00505de0`, `0x005061d3-0x005061e0`, and `0x005062e5-0x005062f0`.
- Preserve the existing ledger entry for modeled-function alignment spans; do not add jump tables or raw helper bodies as ignored padding.

Do not manually edit:

- Any `*-coverage-report.md`
- `auto-generated/*`
- validator cache/state
- IDA database files

## Open questions and resolutions

- Are the raw no-function bodies padding? No. Byte/disassembly checks show source-shaped code, switch tables, calls, field reads/writes, and timer/object-list behavior.
- Do raw helpers have direct route evidence? No. `xrefs_to` and pointer searches were negative. The implementation should document them as no-route children and leave C++ blank.
- Is `[UID:0001AP]` a wrong owner because `DirectionToTileOffset` is file-level? No. The aggregate can remain MapPane-owned while that specific child routes to `[UID:0000L3]`.
- Is `0x005055d0` a day/night helper? No. Current evidence and prior B reports tie it to movement/status tag gating through MapPane byte `+0x40e`.
- Does the aggregate need a monolithic C++ block? No. It is an index/aggregate; insert the marker block above while exact children own code.

## Validation notes

No validators were run in this report-only assignment because no by-* or generated documentation files were edited.

Expected validation after implementation:

- Run file-level validators on every new exact child page and each modified support page, including `by-memory/-ignored.md` if the accepted callback updates that ledger.
- Run the validator for `[UID:0001AP]` after child UIDs/references are inserted.
- Regenerate derived coverage only through approved validator flow, never by manual coverage-report edits.
- Review unresolved raw `sub_` labels for the aggregate after child creation to confirm the modeled helper backlog shrank and only raw no-route helpers remain non-emitting.

## Files changed by this report-only assignment

- `tools/leaser/Agents/Agent-B009/research/0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md`

No leases were taken. No by-* docs, generated/project-level files, validator state/cache, IDA DB, or coverage reports were edited.

## Implementation tracking checklist

- [x] Insert the `[UID:0001AP]` aggregate marker C++ block supplied in this report; keep `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, and blank `EMITTER_POSITION_OPTIONAL`.
- [x] Create exact child page `by-memory/0x00505080-0x00505100.MapPaneDirectionToTileOffset.md` with `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000L3`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000L3`, blank `EMITTER_POSITION_OPTIONAL`, switch table `0x005050eb-0x00505100`, and formal C++.
- [x] Create exact child page `by-memory/0x00505130-0x0050516a.MapPaneMapToScreenCoords.md` with `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, and formal C++.
- [x] Create exact child page `by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md` with `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, and formal C++.
- [x] Create exact child page `by-memory/0x00505230-0x00505281.MapPaneValidateMapAndViewportCoords.md` with `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, and formal C++.
- [x] Create exact child page `by-memory/0x00505290-0x00505304.MapPaneGetClampedVisibleTileBounds.md` with `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, and formal C++.
- [x] Create exact child page `by-memory/0x00505310-0x0050534d.MapPaneGetVisibleTileBounds.md` with `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, and formal C++.
- [x] Create exact child page `by-memory/0x00505350-0x0050536b.MapPaneGetVisibleTileSpan.md` with `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, and formal C++.
- [x] Create exact child page `by-memory/0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds.md` with `COMPLETION:88`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, and formal C++.
- [x] Create raw no-route child page `by-memory/0x005053f0-0x0050542d.MapPaneGetUnclampedExtendedVisibleTileBounds.md` with `COMPLETION:85`, `CONFIDENCE:85`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank C++ with current no-function/no-xref/no-pointer proof.
- [x] Create exact child page `by-memory/0x00505430-0x005055ca.MapPaneCheckMovementCollision.md` with `COMPLETION:86`, `CONFIDENCE:87`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, and formal C++ preserving the observed `-1/0/1` return.
- [x] Create exact child page `by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md` with `COMPLETION:87`, `CONFIDENCE:90`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, and formal C++; avoid `IsDayMode`.
- [x] Create exact child page `by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md` with `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, and formal C++.
- [x] Create exact child page `by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md` with `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, jump table `0x0050571e-0x00505730`, and formal C++.
- [x] Create exact no-op child page `by-memory/0x00505730-0x00505731.MapPaneAfterLocalPlayerWarp.md` with `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, and formal empty C++.
- [x] Create exact no-op child page `by-memory/0x00505740-0x00505743.MapPaneObjectCallbackNoOp.md` with `COMPLETION:86`, `CONFIDENCE:87`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, raw caller `0x0053c370` evidence, and formal empty C++.
- [x] Create raw no-route child page `by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md` with `COMPLETION:85`, `CONFIDENCE:85`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank C++ with current no-function/no-xref/no-pointer proof.
- [x] Create raw no-route child page `by-memory/0x005057d0-0x005058ac.MapPaneRawObjectCleanupSweep.md` with `COMPLETION:85`, `CONFIDENCE:85`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank C++ with current no-function/no-xref/no-pointer proof; include the `0x005058ab` `retn` byte in the child range.
- [x] Create exact child page `by-memory/0x00505940-0x005059cb.MapPaneReindexObjectPanePosition.md` with `COMPLETION:86`, `CONFIDENCE:88`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, and formal C++.
- [x] Create raw no-route child page `by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md` with `COMPLETION:85`, `CONFIDENCE:85`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank C++ with current no-function/no-xref/no-pointer proof; include the `0x00505cae` `retn 8` bytes in the child range.
- [x] Create exact child page `by-memory/0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh.md` with `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, and formal C++.
- [x] Create raw no-route child page `by-memory/0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8.md` with `COMPLETION:85`, `CONFIDENCE:85`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank C++ with current no-function/no-xref/no-pointer proof; include the `0x00505d97` `retn 8` bytes in the child range.
- [x] Create raw no-route child page `by-memory/0x00505da0-0x00505dd2.MapPaneQueueActionPollTimer.md` with `COMPLETION:85`, `CONFIDENCE:85`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank C++ with current no-function/no-xref/no-pointer proof; include the `0x00505dd1` `retn` byte in the child range.
- [x] Create exact child page `by-memory/0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll.md` with `COMPLETION:87`, `CONFIDENCE:89`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, blank `EMITTER_POSITION_OPTIONAL`, and formal C++.
- [x] Create raw no-route child page `by-memory/0x005061e0-0x005062e5.MapPaneRefreshNearbyObjectRows.md` with `COMPLETION:85`, `CONFIDENCE:85`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, blank `EMITTER_UIDS`, blank `EMITTER_POSITION_OPTIONAL`, and blank C++ with current no-function/no-xref/no-pointer proof; include the `0x005062e2` `retn 8` bytes in the child range.
- [x] Update `[UID:0001AP]` with the new child links, raw helper table, gap/padding table, MCP evidence, aggregate marker block, child C++/no-code disposition ledger, and score rationale.
- [x] Update `[UID:00007Q] by-class/MapPane.md` field glossary and method/backlog notes with the exact helper names and no-route raw helper evidence.
- [x] Update `[UID:0000L3] by-file/MapPane.md` with `DirectionToTileOffset` and the MapPane helper split summary.
- [x] Update existing child pages `[UID:0001AQ]`, `[UID:0001AR]`, `[UID:0002QL]`, `[UID:0002QM]`, and related timer/notify pages with the new child links where they currently name raw callees or helper roles.
- [x] Update `by-memory/-ignored.md` with the exact raw-helper-adjacent pure `0xcc` spans verified in this report: `0x005053e4-0x005053f0`, `0x0050542d-0x00505430`, `0x00505743-0x00505750`, `0x005057c8-0x005057d0`, `0x005058ac-0x005058b0`, `0x00505bf8-0x00505c00`, `0x00505cb1-0x00505cc0`, `0x00505cf9-0x00505d00`, `0x00505d9a-0x00505da0`, `0x00505dd2-0x00505de0`, `0x005061d3-0x005061e0`, and `0x005062e5-0x005062f0`; do not ignore jump tables or raw helper bodies.
- [x] For new child pages, insert formal C++ for every modeled/reached child listed as formal in the ledger and keep C++ blank only for raw no-route children with their listed proof.
- [x] Run validators for each created/modified by-memory and support page through approved validator tooling; do not manually edit coverage reports or generated files.
- [x] Confirm the generated unresolved/raw `sub_` backlog for `[UID:0001AP]` shrinks after the callback and validator refresh, with only documented raw no-route children remaining non-emitting.

Implementation proof, 2026-06-25:

- `[UID:0001AP]` now has the accepted aggregate marker C++ block, metadata `COMPLETION:90`, `CONFIDENCE:91`, `CANONICAL_OWNER:00007Q`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00007Q`, and blank `EMITTER_POSITION_OPTIONAL`; validator command `000000001961` accepted the target and inserted/updated the new child links, and generated-freshness command `000000001996` completed with `generated_refresh: completed`.
- Exact modeled/formal children were created and validated: `00041W` command `000000001965`, `00041X` `000000001966`, `00041Y` `000000001967`, `00041Z` `000000001968`, `000420` `000000001969`, `000421` `000000001970`, `000422` `000000001971`, `000423` `000000001972`, `000425` `000000001974`, `000426` `000000001975`, `000427` `000000001976`, `000428` `000000001977`, `000429` `000000001978`, `00042A` `000000001979`, `00042D` `000000001982`, `00042F` `000000001984`, and `00042I` `000000001987`.
- Raw no-route no-code children were created with blank formal C++ and target-specific no-function/no-xref/no-pointer proof, then validated: `000424` command `000000001973`, `00042B` `000000001980`, `00042C` `000000001981`, `00042E` `000000001983`, `00042G` `000000001985`, `00042H` `000000001986`, and `00042J` `000000001988`.
- Support docs were updated and validated: `by-class/MapPane.md` command `000000001962`, `by-file/MapPane.md` `000000001963`, `by-type/by-struct/MapPaneLayout.md` `000000001964`, `[UID:0001AQ]` `000000001989`, `[UID:0001AR]` `000000001990`, `[UID:0002QL]` `000000001991`, `[UID:0002QM]` `000000001992`, `[UID:0003ZT]` `000000001993`, `[UID:0003ZS]` `000000001994`, and `[UID:00037U]` `000000001958` plus final dependency-clean rerun `000000001995`.
- `by-memory/-ignored.md` was updated only with the accepted raw-helper-adjacent pure `0xcc` spans and validated by command `000000001959`; jump tables and raw helper bodies were not added as ignored padding.
- Normal file validation registered preexisting dependency `[UID:0003EE] g_pInputBlockerPane` via command `000000001960`, resolving the new notify/timer reference route without a child UID lifecycle pause.
- Generated freshness was checked after the implementation: `auto-generated/-ag-coverage-report-by-memory.md` now lists `[UID:0001AP]` at `90/91`, includes the new child UIDs, and shows only the accepted raw no-route children as `emits_code:false`; `auto-generated/-ag-memory-coverage.md` routes the aggregate marker and formal children to `auto-generated/NexusTK/map/MapPane.cpp` while raw no-route children remain `non-emits`.
- Validator diagnostics remaining in scoped support files are preexisting stale target/UID references outside the accepted 0001AP split, such as `00027I`, broader MapPane packet split UIDs, `0001KM`, `0003UV`, and `0003A2`; no new child UID/registry lifecycle issue remained after normal file validation.
- Lease cleanup proof: all edit/validator batches were released with `leaser.py Agent-B009 unlease`, and `tools/leaser/Agents/current_leases.md` reported `No active leases` before the checklist proof update.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000004165","destination_path":"executed-b-agent-research/B009/0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0001AP-MapPaneWeatherCoordinateObjectCore-source-quality.md","timestamp":"2026-06-26T00:13:45","uid":"0001AP"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
