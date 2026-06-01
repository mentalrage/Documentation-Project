*** UID:0001SO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# MapServerPacketOpcode

## Status

- Confidence: strong for observed opcode values in `MapPane::HandlePacket`, medium for many working names.
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
| `0x6a` | friend/name-list sync request flag | Reads one byte into [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md); when nonzero, calls [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md), which replies with outbound opcode `0x77`. See [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md). |

## Evidence Notes

- IDA MCP confirms `MapPane::HandlePacket` at `0x00507c90-0x00508e06`.
- IDA MCP live recheck on 2026-05-26 reconfirms the dispatcher boundary at `0x00507c90-0x00508e06`.
- IDA MCP `callees` for `0x00507c90` includes packet scalar readers/writers, map handler functions, dialog constructors, `TimerPane` construction/update, and socket send helpers.
- The current active generated source is useful for the switch table but still has generic names and unresolved global fields. Treat this page as an opcode index, not a final packet specification.
- `0x00510400`, currently emitted as `HandleWeatherPacket`, has real function-shaped bytes in IDA disassembly but no IDA function object. Track this boundary issue in [wave3_data_issues](../../wave3_data_issues.md).
- 2026-05-24 generated-source recheck shows the dispatcher case `0x20` already contains the day/night blend body, while `0x00510400` remains unmodeled by IDA. Keep opcode `0x20` as the packet-level route, but do not treat `HandleWeatherPacket` as a settled function boundary.
- 2026-05-25 IDA MCP recheck shows `0x00510400` has no direct callers/xrefs, the raw body is `0x00510400-0x005104c7` end-exclusive, and the dispatcher inline duplicate calls `0x0050a8b0` at `0x00507efd`. Exact raw evidence is tracked in [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md).
- 2026-05-25 send-helper recheck identifies case `0x6a` as the [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md) trigger: IDA disassembly marks `0x00508ae3` as jumptable case `106`, reads a byte at `0x00508af5`, writes [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md) at `0x00508aff`, and calls [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md) at `0x00508b14` when the byte is nonzero. A raw duplicate at [UID:0001AZ][0x00514380-0x005143b7.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143b7.FriendNameListSyncRawHandler.md) performs the same sequence but has no current direct xrefs.
- 2026-05-31 IDA MCP recheck confirms `MapPane::HandlePacket` at `0x00507c90-0x00508e06`; IDA marks the dispatch as a switch over the first packet byte after subtracting `3`, with 104 switch-table cases and default handling for holes.
- The same IDA MCP raw disassembly recheck confirms representative documented case targets: `0x03` at `0x00507d0c`, `0x04` at `0x00507f1a`, `0x20` at `0x00507e45`, `0x31` at `0x00508776`, `0x4a` at `0x005089ef`, `0x62` at `0x00508d5f`, `0x67` at `0x00508833`, and `0x6a` at `0x00508ae3`. The accepted no-op cases `0x0b`, `0x26`, and `0x44` share the grouped return-success path.

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
- [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md)
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)
- [UID:0001QK][client_opcodes](by-meta/client_opcodes.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
