*** UID:0001SO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MapServerPacketOpcode

## Status

- Confidence: strong for observed opcode values in `MapPane::HandlePacket` and selected packet-name-table cross-checks, medium for many working names.
- Owner module: [UID:0000L3][MapPane](by-file/MapPane.md)
- Defining evidence: `MapPane::HandlePacket` at `0x00507c90`
- Entity kind: inbound map/server packet opcode enum candidate
- Reconstructable: yes, as source-level packet dispatcher constants. Do not emit final enum code yet: many names are still working labels and payload structures are not fully reconstructed.

## Declaration Hypothesis

The original client likely used byte constants, a `switch`, or an enum-like set of protocol IDs for map-scoped inbound server packets:

```cpp
enum MapServerPacketOpcode
{
    // Working names only; preserve numeric values until packet structures are named.
};
```

Do not migrate this as a final header enum yet. Use it as a documentation index for the map dispatcher and packet-structure research.

## Dispatcher Scope

| Scope | Included here | Excluded from this enum page |
| --- | --- | --- |
| Primary dispatcher | The first-byte switch in `MapPane::HandlePacket` at `0x00507c90-0x00508e06`, including accepted no-op cases and case-local inline bodies. | Outbound packet builders, feature-private dialog response opcodes, and the broader 256-entry server packet-name table. |
| Map-owned routes | Map transition, tile/object/state/weather/timer routes that call MapPane-owned or map-companion handlers. | Feature pages own the dialog/control classes allocated by packet cases after the dispatcher routes to them. |
| Cross-feature creation routes | Packet cases that instantiate `EditablePaperPane`, `SelfSaveOKPane`, `TimerPane`, board/web-board, merchant, power, transfer, or other dialogs. | Final payload structures and UI class reconstruction; those belong on the owning class/file/memory pages. |
| Raw duplicate caveats | Inline case bodies and raw/no-function duplicates such as the day/night body at `0x00510400`. | Treating raw duplicates as settled enum values or separate function boundaries. |

## Observed Values

| Opcode | Working meaning | Evidence |
| --- | --- | --- |
| `0x03` | map transition / map packet handler | Dispatches to `0x0050feb0`. |
| `0x04` | tile-region update | Reads four coordinates, calls tile-range update/render helpers, and refreshes object state. |
| `0x06` | map info/update | Dispatches to `0x00510960`. |
| `0x07` | spawn/object placement | Dispatches to `0x00511440`. |
| `0x0b` | accepted no-op/ack | Returns success in dispatcher. |
| `0x0c` | object action/animation update | Reads object id and arguments, updates the object when found, otherwise requests a missing-object refresh. |
| `0x0d` | movement packet | Dispatches to `0x00511710`. |
| `0x0e` | object refresh/removal request | Reads object id and calls `0x005060f0` when the object/list state is active. |
| `0x11` | object state byte update | Reads object id and state byte, then calls a living/object state setter. |
| `0x12` | dialog/message branch | Subtype dispatch into alert/message/dialog paths. |
| `0x13` | action packet | Dispatches to `0x00512960`. |
| `0x15` | effect packet | Dispatches to `0x005104d0`. |
| `0x16` | object update packet | Dispatches to `0x00512d60`. |
| `0x19` | animation packet | Dispatches to `0x00512f20`. |
| `0x1a` | object visual/status change | Reads object id, mode, amount, and extra visual mode, then calls a target object virtual. |
| `0x1b` | editable paper pane | Allocates [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md) with mode `0`. |
| `0x1d` | status packet | Dispatches to `0x00513310`. |
| `0x1f` | map weather/state selector | Calls `SetMapState`/`0x0050db50` with payload state bytes. |
| `0x20` | day/night cycle | Updates day/night mode and blend value from hour/minute-like payload bytes. The live dispatcher has the body inline at `0x00507e45-0x00507f04`; generated standalone `0x00510400-0x005104c7` is a raw duplicate/boundary caveat. |
| `0x21` | self-save OK message | Creates a small [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md) alert and schedules timer cleanup. |
| `0x26` | accepted no-op/ack | Returns success in dispatcher. |
| `0x29` | object move packet | Dispatches to `0x00511c90`. |
| `0x2e` | object/world-map creation | Dispatches to `0x00511db0`; this path can create [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md). |
| `0x2f` | merchant dialog | Creates a merchant dialog through dialog-creator storage. |
| `0x30` | pursuit message dialog | Creates a pursuit-message dialog through dialog-creator storage. |
| `0x31` | bulletin/session path | Creates a bulletin/session object when no active session exists. |
| `0x33` | map transition / map packet handler alias | Dispatches to `0x0050feb0`, same target as `0x03`. |
| `0x34` | switch side panel tab 1 | IDA disassembly routes through [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md) with tab `1`. |
| `0x35` | read-only paper pane | Allocates [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md) with mode `1`. |
| `0x36` | transfer/server dialog path | Allocates a dialog object through `0x0059bc90` when its singleton is clear. |
| `0x37` | UI state marker update | Parses a name/string block and updates three UI state bytes. |
| `0x38` | UI state reset | Clears the same UI state bytes when subtype is `1`. |
| `0x39` | switch side panel tab 0 | IDA disassembly routes through [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md) with tab `0`. |
| `0x3b` | challenge/response checksum | Sends a small response packet with outbound opcode `0x45`. |
| `0x3d` | forced/inform dialog candidate | Conditionally allocates a 624-byte dialog through `0x0048b1c0`. |
| `0x42` | exception/dialog path | Allocates a 636-byte object through `0x004ac8a0`; final owner/name open. |
| `0x44` | accepted no-op/ack | Returns success in dispatcher. |
| `0x46` | power dialog | Allocates [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md). |
| `0x49` | object/map cleanup helper | Calls `0x005063e0`; final name open. |
| `0x4a` | system marker/shutdown path | Checks a magic dword, writes one byte to `Mscfg.dll`, truncates the file, then requests application exit. Needs security-focused review. |
| `0x4b` | state-change packet | Dispatches to `0x00513c90`. |
| `0x4f` | employee dialog packet | Validates then allocates/updates [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md). |
| `0x59` | map companion update | Calls `0x00503d10` on a global map companion object. Final owner open. |
| `0x5a` | head/select dialog candidate | Parses packed fields and allocates a 408-byte object through `0x00549620`. |
| `0x5b` | global string/config update | Parses a packet string and stores values in global client state. |
| `0x5e` | target/selection option path | Updates selected-pane timer state and may allocate a 256-byte option/status pane. |
| `0x5f` | object special action refresh | Looks up an object and either calls an object action helper or requests object refresh. |
| `0x62` | board/web-board dialog | Creates board/web-board dialog code tracked under [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md). |
| `0x66` | alert packet | Dispatches to `0x00513da0`. |
| `0x67` | timer pane | Creates/updates [UID:0000OU][TimerPane](by-file/TimerPane.md). |
| `0x68` | timestamp echo/challenge response | Reads a 64-bit timestamp and sends outbound opcode `0x75`. |
| `0x6a` | friend/name-list sync request flag | Reads one byte into [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md) / `g_friendNameListSyncEnabled`; when nonzero, calls [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md), which replies with outbound opcode `0x77`. See [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md). |

## Packet Name Table Cross-Check

[UID:00026H][0x00625008-0x0062ce60.ServerPacketNameTable](by-memory/0x00625008-0x0062ce60.ServerPacketNameTable.md) is Socket/protocol debug data rather than this enum's owner, but its fixed `256 * 0x7e` UTF-16 slot layout gives stable label evidence for several MapPane-dispatched byte values. Use these labels as a name-source cross-check, not as final enum spellings.

| Opcode | Server table label | Relationship to this page |
| --- | --- | --- |
| `0x04` | `kServerUserPosition` | Aligns with the tile-region / position-update route that refreshes map object state. |
| `0x07` | `kServerDrawObjects` | Aligns with the spawn/object-placement route that dispatches to `0x00511440`. |
| `0x12` | `kServerCollection` | Confirms this byte belongs to the broader server packet-name namespace; MapPane still owns only the local dialog/message dispatch behavior. |
| `0x1f` | `kServerChangeWeather` | Aligns with the map weather/state selector and the separate day/night raw-body caveat for neighboring opcode `0x20`. |
| `0x30` | `kServerPursuitMessage` | Aligns with the pursuit-message dialog creation route. |
| `0x3b` | `kServerRequestCRC` | Aligns with the challenge/response checksum path that sends outbound opcode `0x45`. |

Do not merge this enum page into the server packet name table. The table is broader Socket-owned logging/name data, while this page indexes the `MapPane::HandlePacket` switch subset and its feature routing.

## Route Categories

| Category | Opcodes | Rebuild note |
| --- | --- | --- |
| Map/object core updates | `0x03`, `0x04`, `0x06`, `0x07`, `0x0c`, `0x0d`, `0x0e`, `0x11`, `0x13`, `0x15`, `0x16`, `0x19`, `0x1a`, `0x1d`, `0x29`, `0x2e`, `0x33`, `0x49`, `0x4b`, `0x59`, `0x5f` | Keep names provisional until object/status payload structs are named. |
| Map state, weather, and time | `0x1f`, `0x20`, `0x67`, `0x68` | Distinguish inline dispatcher behavior from raw duplicate bodies before final helper declarations. |
| UI/dialog creation | `0x12`, `0x1b`, `0x21`, `0x2f`, `0x30`, `0x31`, `0x35`, `0x36`, `0x3d`, `0x42`, `0x46`, `0x4f`, `0x5a`, `0x5e`, `0x62`, `0x66` | Dispatcher owns routing; instantiated panes/dialogs keep source ownership in their feature files. |
| UI state and side-panel control | `0x34`, `0x37`, `0x38`, `0x39`, `0x5b` | Treat as map/UI integration constants until side-panel state fields and payloads are named. |
| Protocol control / challenge / no-op | `0x0b`, `0x26`, `0x3b`, `0x44`, `0x4a`, `0x6a` | Security-sensitive or protocol-control paths need dedicated review before final names. |

## Evidence Notes

- IDA MCP confirms `MapPane::HandlePacket` at `0x00507c90-0x00508e06`.
- IDA MCP live recheck on 2026-05-26 reconfirms the dispatcher boundary at `0x00507c90-0x00508e06`.
- IDA MCP `callees` for `0x00507c90` includes packet scalar readers/writers, map handler functions, dialog constructors, `TimerPane` construction/update, and socket send helpers.
- The current active generated source is useful for the switch table but still has generic names and unresolved global fields. Treat this page as an opcode index, not a final packet specification.
- `0x00510400`, currently emitted as `HandleWeatherPacket`, has real function-shaped bytes in IDA disassembly but no IDA function object. Track this boundary issue in [wave3_data_issues](../../wave3_data_issues.md).
- 2026-05-24 generated-source recheck shows the dispatcher case `0x20` already contains the day/night blend body, while `0x00510400` remains unmodeled by IDA. Keep opcode `0x20` as the packet-level route, but do not treat `HandleWeatherPacket` as a settled function boundary.
- 2026-05-25 IDA MCP recheck shows `0x00510400` has no direct callers/xrefs, the raw body is `0x00510400-0x005104c7` end-exclusive, and the dispatcher inline duplicate calls `0x0050a8b0` at `0x00507efd`. Exact raw evidence is tracked in [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md).
- 2026-05-25 send-helper recheck identifies case `0x6a` as the [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md) trigger: IDA disassembly marks `0x00508ae3` as jumptable case `106`, reads a byte at `0x00508af5`, writes [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md) / `g_friendNameListSyncEnabled` at `0x00508aff`, and calls [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md) at `0x00508b14` when the byte is nonzero. A raw duplicate at [UID:0001AZ][0x00514380-0x005143b7.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143b7.FriendNameListSyncRawHandler.md) performs the same sequence but has no current direct xrefs.
- 2026-05-31 IDA MCP recheck confirms `MapPane::HandlePacket` at `0x00507c90-0x00508e06`; IDA marks the dispatch as a switch over the first packet byte after subtracting `3`, with 104 switch-table cases and default handling for holes.
- The same IDA MCP raw disassembly recheck confirms representative documented case targets: `0x03` at `0x00507d0c`, `0x04` at `0x00507f1a`, `0x20` at `0x00507e45`, `0x31` at `0x00508776`, `0x4a` at `0x005089ef`, `0x62` at `0x00508d5f`, `0x67` at `0x00508833`, and `0x6a` at `0x00508ae3`. The accepted no-op cases `0x0b`, `0x26`, and `0x44` share the grouped return-success path.
- Current-session note: IDA MCP was unreachable on 2026-06-07, so this pass uses existing IDA-backed MapPane, memory, meta, and opcode docs and does not claim a fresh dispatcher pass.

## Declaration Readiness

- `AUTOGEN_PARENT_UID` is [UID:0000L3][MapPane](by-file/MapPane.md) because the dispatcher owner is clear and both parent/child are now at or above the `80/80` attachment gate.
- A final C++ declaration should likely use `uint8_t`-sized constants or an enum scoped to the MapPane packet dispatcher, but only after payload structures and feature-specific route names are stabilized.
- Do not merge this page with [UID:00026H][0x00625008-0x0062ce60.ServerPacketNameTable](by-memory/0x00625008-0x0062ce60.ServerPacketNameTable.md). That table is broader protocol/debug label data; this page indexes the MapPane switch subset.
- Keep accepted no-op/ack cases explicit in documentation even if final source shares one return-success branch, because they are distinct packet values in the switch table.

## Score Rationale

- Completion is `80` because the page now includes dispatcher scope boundaries, route categories, observed values, raw duplicate caveats, representative case-target evidence, packet-name-table cross-checks, source-owner separation, parent attachment, and declaration-readiness guidance. It remains capped because many payload structures and final route names are still open.
- Confidence is `84` because the dispatcher boundary and representative case values are IDA-backed and selected names now cross-check against the fixed Socket packet-name table. It remains capped because current names are still working labels and this session did not perform a fresh live dispatcher audit.

## Open Questions

- Final names and payload structures for each opcode.
- Whether some dialog-related opcodes should move to feature-specific packet enum pages once ownership is proven.
- The meaning and intended purpose of opcode `0x4a`'s `Mscfg.dll` write/truncate path.
- A complete packet-structure audit is still required before this can become final source C++; this page is a dispatcher index, not a full protocol specification.

## Cross-References

- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md)
- [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md)
- [UID:0001AW][0x0050e4c0-0x00514e1b.MapPanePacketHandlersAndDelete](by-memory/0x0050e4c0-0x00514e1b.MapPanePacketHandlersAndDelete.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md) / `g_friendNameListSyncEnabled`
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md)
- [UID:00026H][0x00625008-0x0062ce60.ServerPacketNameTable](by-memory/0x00625008-0x0062ce60.ServerPacketNameTable.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)
- [UID:0001QK][client_opcodes](by-meta/client_opcodes.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## Changes

- 2026-06-07 A002 dispatcher-boundary pass:
  - Before: `COMPLETION:74`, with observed values and evidence notes documented but limited category/scope guidance for separating the MapPane switch subset from broader protocol tables and feature-owned dialog classes.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:82`, with dispatcher scope, route categories, declaration-readiness notes, score rationale, and a current-session IDA availability caveat.
  - Summary/evidence: [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md), [UID:0001AW][0x0050e4c0-0x00514e1b.MapPanePacketHandlersAndDelete](by-memory/0x0050e4c0-0x00514e1b.MapPanePacketHandlersAndDelete.md), [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md), and client network/opcode meta pages support the MapPane switch subset, raw duplicate caveat, and feature-route ownership split.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: opcode `0x6a` evidence referenced the friend-list upload flag only as historical `byte_66DEE0`.
  - After: the page records resolved name `g_friendNameListSyncEnabled` beside the historical label.
  - Evidence: generated resolved-name report maps `byte_66DEE0` to `g_friendNameListSyncEnabled`; existing IDA-backed evidence already ties the flag write at `0x00508aff` to inbound case `0x6a` before the opcode `0x77` friend-name-list upload helper.
- 2026-06-07 A006 packet-name-table cross-check:
  - Before: `COMPLETION:76`, `CONFIDENCE:82`, with the MapPane dispatcher values documented but selected Socket packet-name-table labels only available through the separate table page.
  - Changed to: `COMPLETION:80`, `CONFIDENCE:84`, `AUTOGEN_PARENT_UID:0000L3`, with a packet-name-table cross-check section and explicit Socket-table versus MapPane-dispatcher ownership boundary.
  - Evidence: [UID:00026H][0x00625008-0x0062ce60.ServerPacketNameTable](by-memory/0x00625008-0x0062ce60.ServerPacketNameTable.md) documents fixed-stride labels for opcodes `0x04`, `0x07`, `0x12`, `0x1f`, `0x30`, and `0x3b`; existing [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md) and [UID:0001AW][0x0050e4c0-0x00514e1b.MapPanePacketHandlersAndDelete](by-memory/0x0050e4c0-0x00514e1b.MapPanePacketHandlersAndDelete.md) retain MapPane ownership and final-name caveats.
