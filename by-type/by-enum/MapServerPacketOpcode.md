*** UID:0001SO | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MapServerPacketOpcode

## Opcode 0x1d Object-Status Route Closure - 2026-07-16

- Inbound opcode `0x1d` reaches dispatcher target `0x005083aa`, calls source-ready UID0003TT at `0x005083b1`, and directly returns the child's Boolean success.
- UID0003TT is `MapPane::HandleObjectStatusPacket(const unsigned char *packet)` at `92/94`. It reads a BE32 object id, selects full/partial ObjectStatusBlob parsing for selector `0/1`, consumes object-info type plus a counted ACP name, and performs exact living or high-id item refresh behavior with unconditional success.
- The case preserves trusted-buffer semantics, unsafe ObjectInfo ordering, missing-object refresh, effect/sound/timer/local-appearance/overlay behavior, and source-ready UID0003HS item-state dependency.
- This resolves opcode `0x1d` at the case-child level only. The working enum remains `88/90`, owner/emitter UID0000L3, blank formal, and complete unrelated opcode inventory because original enumerator spellings and unrelated payload contracts remain incomplete.

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

Outbound opcode note: `0x05` is sent by [UID:0002QM][0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition](by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md) as a 10-byte client map-position/update packet. It is not an inbound `MapPane::HandlePacket` switch value and should remain excluded from this server-opcode enum except as an outbound cross-reference.

Outbound opcode note: `0x0b` is sent by [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md) as a one-byte client exit/logout/menu notification when its boolean argument is true. It is outbound and should remain distinct from inbound `0x0b` accepted-no-op/ack in the `MapPane::HandlePacket` switch.

Outbound opcode note: `0x0c` is sent by [UID:000231][0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper](by-memory/0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper.md) as a five-byte client object-id refresh/missing-object request. It is outbound and should remain distinct from inbound `0x0c` object action/animation update, although inbound object-update routes call the outbound helper when an expected object id is missing.

## Observed Values

| Opcode | Working meaning | Evidence |
| --- | --- | --- |
| `0x03` | map transition / map packet handler | Dispatches to `0x0050feb0`. |
| `0x04` | tile-region update | Reads four coordinates, calls tile-range update/render helpers, and refreshes object state. |
| `0x06` | map info/update | Dispatches to [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md); B011 session `b001-0001I5` reconfirms dispatcher `jumptable` case `6` at `0x00507ff3 -> call 0x00507ffa`. |
| `0x07` | spawn/object placement | Dispatches to `0x00511440`. |
| `0x0b` | accepted no-op/ack | Returns success in dispatcher. |
| `0x0c` | object action/animation update | Reads object id and arguments, updates the object when found, otherwise requests a missing-object refresh. |
| `0x0d` | movement packet | Dispatches to `0x00511710`. |
| `0x0e` | object refresh/removal request | Reads object id and calls `0x005060f0` when the object/list state is active. |
| `0x11` | object state byte update | Reads object id and state byte, then calls a living/object state setter. |
| `0x12` | dialog/message branch | Subtype dispatch into alert/message/dialog paths. |
| `0x13` | action packet | Dispatches to `0x00512960`. |
| `0x15` | effect/map-state packet | The case at `0x00507f09` directly returns [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md). Payload is opcode, three big-endian map/dimension words, flags, transition byte, counted ANSI map name, packed day/night word, and final Config byte. |
| `0x16` | object update packet | Dispatches to `0x00512d60`. |
| `0x19` | animation packet | Dispatches to `0x00512f20`. |
| `0x1a` | object visual/status change | Reads object id, mode, amount, and extra visual mode, then calls a target object virtual. |
| `0x1b` | editable paper pane | Allocates [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md) with mode `0`. |
| `0x1d` | object-status packet | Direct bool dispatch to source-ready `MapPane::HandleObjectStatusPacket` at `0x00513310`; BE32 object id, full/partial ObjectStatusBlob, object-info byte, counted ACP name, living/item refresh, and unconditional success. |
| `0x1f` | map weather/state selector | Calls `SetMapState`/`0x0050db50` with payload state bytes. |
| `0x20` | day/night cycle | Inline dispatcher body at `0x00507e45-0x00507f04`: validates `packet[1]` as `dayNightHour < 24` and `packet[2]` as `minuteOfHour < 60`, stores the hour at `MapPane +0x40f`, computes a clamped brightness target from `s_dayNightBrightnessByHour[hour]`, `MapPane +0x3e4` scale, and `MapPane +0x3e8` bias, derives quadratic tint amount from `m_currentDayNightBrightness` plus `m_dayNightTintCurveScale/m_dayNightTintCurveBase`, and calls [UID:0004RC][0x0050a8b0-0x0050a932.MapPaneSetDayNightFadeTarget](by-memory/0x0050a8b0-0x0050a932.MapPaneSetDayNightFadeTarget.md) with target brightness and tint amount. Raw [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md) remains no-route duplicate evidence, not the source owner. |
| `0x21` | self-save OK message | Creates a small [UID:0000NN][SelfSaveOKPane](by-file/SelfSaveOKPane.md) alert and schedules timer cleanup. |
| `0x26` | accepted no-op/ack | Returns success in dispatcher. |
| `0x29` | object move packet | Dispatches to `0x00511c90`. |
| `0x2e` | object/world-map creation | Dispatches to `0x00511db0`; this path can create [UID:0000PB][WorldMapPane](by-file/WorldMapPane.md). |
| `0x2f` | merchant dialog | Creates a merchant dialog through dialog-creator storage. |
| `0x30` | pursuit message dialog | Creates a pursuit-message dialog through dialog-creator storage. |
| `0x31` | bulletin/session path | Creates a bulletin/session object when no active session exists. |
| `0x33` | object info / map-object packet | Dispatches to `0x0050fb00`; parses object coordinates/id/status blobs, creates or updates map object-info state, and refreshes object overlays. |
| `0x34` | switch side panel tab 1 | IDA disassembly routes through [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md) with tab `1`. |
| `0x35` | read-only paper pane | Allocates [UID:0000IX][EditablePaperPane](by-file/EditablePaperPane.md) with mode `1`. |
| `0x36` | user-list dialog packet | Server label table entry is `kServerUserList` at `0x00626a9c`; `MapPane` and `UserPane` dispatch paths lazily create `UserListDialogPane` with the packet payload when `g_pUserListDialogPane` is null. |
| `0x37` | UI state marker update | Parses a name/string block and updates three UI state bytes. |
| `0x38` | UI state reset | Clears the same UI state bytes when subtype is `1`. |
| `0x39` | switch side panel tab 0 | IDA disassembly routes through [UID:00015X][0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab](by-memory/0x004b8650-0x004b8822.GeneralPurposePanelSwitchActiveTab.md) with tab `0`. |
| `0x3b` | challenge/response checksum | Sends a small response packet with outbound opcode `0x45`. |
| `0x3d` | forced/inform dialog candidate | Conditionally allocates a 624-byte dialog through `0x0048b1c0`. |
| `0x42` | ExchangeDialog | MapPane case target `0x0050868d` allocates a `0x27c`-byte object and calls [UID:00049P][0x004ac8a0-0x004ad0aa.ExchangeDialogConstructor](by-memory/0x004ac8a0-0x004ad0aa.ExchangeDialogConstructor.md) at `0x005086c0`; the same constructor also has the independent exchange-packet caller `0x00513a77`. |
| `0x44` | accepted no-op/ack | Returns success in dispatcher. |
| `0x46` | power dialog | Allocates [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md). |
| `0x49` | object/map cleanup helper | Calls `0x005063e0`; final name open. |
| `0x4a` | system marker/shutdown path | Checks a magic dword, writes one byte to `Mscfg.dll`, truncates the file, then requests application exit. Needs security-focused review. |
| `0x4b` | state-change packet | Dispatches to `0x00513c90`. |
| `0x4f` | employee dialog packet | Validates then allocates/updates [UID:0000J0][EmployeeDialogPane](by-file/EmployeeDialogPane.md). |
| `0x59` | map companion update | Calls `0x00503d10` on a global map companion object. Final owner open. |
| `0x5a` | map photo snapshot / PhotoPane viewer packet | Parses `uint16 mapId`, a second `uint16` whose low byte is the avatar shape/body byte, `uint8 avatarDirection`, `uint8 avatarTileX`, and `uint8 avatarTileY`; both the live dispatcher path and no-direct-caller companion route allocate `0x198` bytes and call `PhotoPane::PhotoPane` at `0x00549620`. |
| `0x5b` | global string/config update | Parses a packet string and stores values in global client state. |
| `0x5e` | target/selection option path | Updates selected-pane timer state and may allocate a 256-byte option/status pane. |
| `0x5f` | object special action refresh | Looks up an object and either calls an object action helper or requests object refresh. |
| `0x62` | board/web-board dialog | Creates board/web-board dialog code tracked under [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md). |
| `0x66` | alert packet | Dispatches to `0x00513da0`. |
| `0x67` | timer pane | Creates/updates [UID:0000OU][TimerPane](by-file/TimerPane.md). |
| `0x68` | timestamp echo/challenge response | Reads a 64-bit timestamp and sends outbound opcode `0x75`. |
| `0x6a` | friend/name-list sync request flag | Reads one byte into [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md) / `g_friendNameListSyncEnabled`; when nonzero, calls [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md), which replies with outbound opcode `0x77`. See [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md). |

## Packet Name Table Cross-Check

[UID:00026H][0x00625008-0x0062ce50.ServerPacketNameTable](by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md) is Socket/protocol debug data rather than this enum's owner, but its fixed `256 * 0x7e` UTF-16 slot layout gives stable label evidence for several MapPane-dispatched byte values. Use these labels as a name-source cross-check, not as final enum spellings.

| Opcode | Server table label | Relationship to this page |
| --- | --- | --- |
| `0x04` | `kServerUserPosition` | Aligns with the tile-region / position-update route that refreshes map object state. |
| `0x07` | `kServerDrawObjects` | Aligns with the spawn/object-placement route that dispatches to `0x00511440`. |
| `0x12` | `kServerCollection` | Confirms this byte belongs to the broader server packet-name namespace; MapPane still owns only the local dialog/message dispatch behavior. |
| `0x1f` | `kServerChangeWeather` | Aligns with the map weather/state selector and the separate day/night raw-body caveat for neighboring opcode `0x20`. |
| `0x30` | `kServerPursuitMessage` | Aligns with the pursuit-message dialog creation route. |
| `0x3b` | `kServerRequestCRC` | Aligns with the challenge/response checksum path that sends outbound opcode `0x45`. |

Do not merge this enum page into the server packet name table. The table is broader Socket-owned logging/name data, while this page indexes the `MapPane::HandlePacket` switch subset and its feature routing.

## UID0003TK Opcode 0x15 Closure - 2026-07-15

- Dispatcher case `0x15` at `0x00507f09-0x00507f19` calls `0x005104d0` and returns the callee Boolean without postprocessing. UID0003TK is the ordinary source-authored `bool MapPane::HandleEffectMapStatePacket(const unsigned char *packet)` emitter at `92/94`; this enum page owns only the observed numeric protocol index.
- Exact payload offsets are opcode `+0`, big-endian map id/width/height words `+1/+3/+5`, flags `+7`, transition byte `+8`, counted ANSI name length `+9`, name bytes `+10`, packed day/night word after the name, and a final Config byte. The trusted minimum span is `13 + nameLength`; no length or bounds check exists, and the converted wide map name is unused.
- Flag `0x01` controls weather state, `0x02` controls movement gating, and `0x08` controls runtime mode. Flag `0x04` is not consumed. The handler rebuilds map/ObjectList state, computes day/night brightness and quadratic tint, performs auxiliary/layer cleanup, sets waiting state, processes two EPF dirty-state branches, stores the final Config byte, and returns true.
- The working name `effect/map-state packet` is descriptive and evidence-backed, but no original `MapServerPacketOpcode` enumerator spelling is recoverable from the binary or packet-name table. The managed enum formal therefore remains blank at `88/90`; emitting a one-value enum would overstate source evidence.

## Route Categories

| Category | Opcodes | Rebuild note |
| --- | --- | --- |
| Map/object core updates | `0x03`, `0x04`, `0x06`, `0x07`, `0x0c`, `0x0d`, `0x0e`, `0x11`, `0x13`, `0x15`, `0x16`, `0x19`, `0x1a`, `0x1d`, `0x29`, `0x2e`, `0x33`, `0x49`, `0x4b`, `0x59`, `0x5f` | Keep names provisional until object/status payload structs are named. |
| Map state, weather, and time | `0x1f`, `0x20`, `0x67`, `0x68` | Distinguish inline dispatcher behavior from raw duplicate bodies before final helper declarations. |
| UI/dialog creation | `0x12`, `0x1b`, `0x21`, `0x2f`, `0x30`, `0x31`, `0x35`, `0x36`, `0x3d`, `0x42`, `0x46`, `0x4f`, `0x5a`, `0x5e`, `0x62`, `0x66` | Dispatcher owns routing; instantiated panes/dialogs keep source ownership in their feature files. |
| UI state and side-panel control | `0x34`, `0x37`, `0x38`, `0x39`, `0x5b` | Treat as map/UI integration constants until side-panel state fields and payloads are named. |
| Protocol control / challenge / no-op | `0x0b`, `0x26`, `0x3b`, `0x44`, `0x4a`, `0x6a` | Security-sensitive or protocol-control paths need dedicated review before final names. |

## Switch Target Case-Group Plan

2026-07-06 B015 MCP session `7bfdc746` reconfirmed that [UID:00037T][0x00507c90-0x00508f60.MapPanePacketDispatcher](by-memory/0x00507c90-0x00508f60.MapPanePacketDispatcher.md) is the live dispatcher envelope: `sub_507C90` is size `0x1176`, the body ends at end-exclusive `0x00508e06`, `0x00508e06` is not a function, `0x00508f60` is the next modeled function, the prologue at `0x00507ccc-0x00507ce2` uses a first-byte normalized switch, and the `0x00508e06/0x00508e08` tail is attached align/jump/byte-table data. This enum page remains a working index. Formal source emission belongs in exact case-group children/audits or a later full dispatcher reconstruction, not in a hand-authored source dispatch table.

| Case target | Opcode(s) | Current audit role |
| --- | --- | --- |
| `0x00507d0c` | `0x03` | Map transition / map packet handler. |
| `0x00507f1a` | `0x04` | Tile-region update. |
| `0x00507ff3` | `0x06` | Map info/update route. |
| `0x00508004` | `0x07` | Spawn/object placement route. |
| `0x0050805e` | `0x0c` | Object action/animation update. |
| `0x00508015` | `0x0d` | Movement packet route. |
| `0x005082bb` | `0x0e` | Object refresh/removal request. |
| `0x0050814e` | `0x11` | Object state byte update. |
| `0x00508c65` | `0x12` | Dialog/message subtype branch. |
| `0x00508377` | `0x13` | Action packet route. |
| `0x00507f09` | `0x15` | Effect packet route. |
| `0x00508388` | `0x16` | Object update packet route. |
| `0x00508399` | `0x19` | Animation packet route. |
| `0x005081e3` | `0x1a` | Object visual/status change. |
| `0x00508311` | `0x1b` | EditablePaperPane mode 0 route. |
| `0x005083aa` | `0x1d` | Direct bool-return object-status route to source-ready UID0003TT at call `0x005083b1`. |
| `0x005084df` | `0x1f` | Map weather/state selector. |
| `0x00507e45` | `0x20` | Day/night cycle; live route owns source, raw `0x00510400` remains no-route duplicate evidence. |
| `0x00508511` | `0x21` | Self-save OK message; SelfSaveOKPane owns pane behavior. |
| `0x00507dca` | `0x0b,0x26,0x44` | Accepted no-op/ack return-success group. |
| `0x005082ef` | `0x29` | Object move packet route. |
| `0x00508300` | `0x2e` | Object/world-map creation route. |
| `0x00507dd1` | `0x2f` | Merchant dialog route. |
| `0x00507e0b` | `0x30` | Pursuit message dialog route. |
| `0x00508776` | `0x31` | Bulletin/session path. |
| `0x00508811` | `0x33` | Object info / map-object packet. |
| `0x00508026` | `0x34` | Side panel tab 1 switch. |
| `0x00508344` | `0x35` | EditablePaperPane mode 1 route. |
| `0x005087c2` | `0x36` | User-list dialog packet. |
| `0x005083bb` | `0x37` | UI state marker update. |
| `0x0050849c` | `0x38` | UI state reset. |
| `0x00508647` | `0x39` | Side panel tab 0 switch. |
| `0x005085f2` | `0x3b` | Challenge/CRC response. |
| `0x005086ce` | `0x3d` | Forced/inform dialog candidate. |
| `0x0050868d` | `0x42` | Exact ExchangeDialog route; allocates `0x27c` bytes and calls constructor `0x004ac8a0` at `0x005086c0`. |
| `0x00508745` | `0x46` | Power dialog route; PowerDialogPane owns constructor/body. |
| `0x005089dd` | `0x49` | Object/map cleanup helper. |
| `0x005089ef` | `0x4a` | System marker/shutdown path. |
| `0x00508800` | `0x4b` | State-change packet route. |
| `0x00508d1d` | `0x4f` | Employee dialog packet. |
| `0x00507ce9` | `0x59` | Map companion update. |
| `0x00508b20` | `0x5a` | PhotoPane map-photo snapshot route; PhotoPane owns pane body and accepted payload layout remains support evidence. |
| `0x00508bcd` | `0x5b` | Global string/config update. |
| `0x00507d1d` | `0x5e` | Target/selection option path. |
| `0x00508978` | `0x5f` | Object special action refresh. |
| `0x00508d5f` | `0x62` | Board/web-board dialog route. |
| `0x00508822` | `0x66` | Alert packet route. |
| `0x00508833` | `0x67` | Timer pane route. |
| `0x00508927` | `0x68` | Timestamp echo/challenge response. |
| `0x00508ae3` | `0x6a` | Friend/name-list sync flag; raw `0x00514380` remains no-route duplicate evidence. |
| `0x00508de6` | `0x05,0x08,0x09,0x0a,0x0f,0x10,0x14,0x17,0x18,0x1c,0x1e,0x22,0x23,0x24,0x25,0x27,0x28,0x2a,0x2b,0x2c,0x2d,0x32,0x3a,0x3c,0x3e,0x3f,0x40,0x41,0x43,0x45,0x47,0x48,0x4c,0x4d,0x4e,0x50,0x51,0x52,0x53,0x54,0x55,0x56,0x57,0x58,0x5c,0x5d,0x60,0x61,0x63,0x64,0x65,0x69` | Default/error return group. |

## Evidence Notes

- 2026-07-14 B001 UID0002F7 support recheck closes opcode `0x42`: current ExchangeDialog constructor/file documentation and live xrefs identify `0x004ac8a0` as `ExchangeDialog::ExchangeDialog`, with callers `0x005086c0` inside the MapPane `0x42` case and `0x00513a77` inside the separate exchange packet path. The MapPane case allocates exact `0x27c` bytes. This page remains a working switch index with blank formal C++; it does not invent an original protocol-enum constant spelling or move ExchangeDialog implementation ownership into MapPane.
- 2026-07-06 Agent-B011 MCP session `b001-0001I5` reconfirmed opcode `0x06` through dispatcher disassembly: `loc_507FF3` is case `6` and calls `sub_510960` / [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md) at `0x00507ffa`. No enum score or final C++ change is made for this support-only evidence note.
- IDA MCP confirms `MapPane::HandlePacket` at `0x00507c90-0x00508e06`.
- 2026-07-06 B015 MCP session `7bfdc746` reconfirmed the dispatcher as `sub_507C90`, size `0x1176`, with body through end-exclusive `0x00508e06`; `0x00508e06` is not a function and begins attached switch data, and `0x00508f60` is the next modeled function. The switch prologue at `0x00507ccc-0x00507ce2` reads the first packet byte, normalizes by subtracting `3`, bounds-checks `0x67`, loads `byte_508ED4`, and jumps through `jpt_507CE2`.
- The same B015 check verified `0x00508e06` as `align 4`, `0x00508e08` as jump-table dwords, 51 dword jump targets, 104 byte-index entries, representative routes for `0x03`, `0x20`, `0x46`, `0x5a`, `0x62`, `0x67`, `0x6a`, the `0x0b/0x26/0x44` accepted no-op group, and default/ignored target `0x00508de6`.
- B015 raw-route negative evidence: `0x00510400` and `0x00514380` are not functions and have zero direct xrefs; `0x00513800` has no route; feature constructors/helpers remain callee-owned. UID00037T therefore keeps a blank parent C++ block by target-specific no-code proof, not because ownership is uncertain.
- IDA MCP live recheck on 2026-05-26 reconfirms the dispatcher boundary at `0x00507c90-0x00508e06`.
- IDA MCP `callees` for `0x00507c90` includes packet scalar readers/writers, map handler functions, dialog constructors, `TimerPane` construction/update, and socket send helpers.
- The current active generated source is useful for the switch table but still has generic names and unresolved global fields. Treat this page as an opcode index, not a final packet specification.
- `0x00510400`, currently emitted as `HandleWeatherPacket`, has real function-shaped bytes in IDA disassembly but no IDA function object. Track this boundary issue in [wave3_data_issues](../../wave3_data_issues.md).
- 2026-05-24 generated-source recheck shows the dispatcher case `0x20` already contains the day/night blend body, while `0x00510400` remains unmodeled by IDA. Keep opcode `0x20` as the packet-level route, but do not treat `HandleWeatherPacket` as a settled function boundary.
- 2026-05-25 IDA MCP recheck shows `0x00510400` has no direct callers/xrefs, the raw body is `0x00510400-0x005104c7` end-exclusive, and the dispatcher inline duplicate calls `0x0050a8b0` at `0x00507efd`. Exact raw evidence is tracked in [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md).
- 2026-05-25 send-helper recheck identifies case `0x6a` as the [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md) trigger: IDA disassembly marks `0x00508ae3` as jumptable case `106`, reads a byte at `0x00508af5`, writes [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md) / `g_friendNameListSyncEnabled` at `0x00508aff`, and calls [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md) at `0x00508b14` when the byte is nonzero. A raw duplicate at [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md) performs the same sequence but has no current direct xrefs.
- 2026-05-31 IDA MCP recheck confirms `MapPane::HandlePacket` at `0x00507c90-0x00508e06`; IDA marks the dispatch as a switch over the first packet byte after subtracting `3`, with 104 switch-table cases and default handling for holes.
- The same IDA MCP raw disassembly recheck confirms representative documented case targets: `0x03` at `0x00507d0c`, `0x04` at `0x00507f1a`, `0x20` at `0x00507e45`, `0x31` at `0x00508776`, `0x4a` at `0x005089ef`, `0x62` at `0x00508d5f`, `0x67` at `0x00508833`, and `0x6a` at `0x00508ae3`. The accepted no-op cases `0x0b`, `0x26`, and `0x44` share the grouped return-success path.
- 2026-06-07 note: IDA MCP was unreachable in that session, so that pass used existing IDA-backed MapPane, memory, meta, and opcode docs and did not claim a fresh dispatcher pass.
- 2026-06-13 A002 live IDA MCP audit on session `a001_goal2_0002UM` removed the stale no-live-audit cap. `server_health` reported the NexusTK IDB ready, and `lookup_funcs` confirmed `sub_507C90` at `0x00507c90`, size `0x1176` / 4470 bytes, with `0x00508e06` not modeled as a function and the next modeled helper `sub_508F60` at `0x00508f60`.
- The 2026-06-13 dispatcher prologue recheck shows `0x00507ccf` subtracting `3`, comparing the normalized value against `0x67`, and IDA annotating `switch 104 cases`. Verified with `tools/int_convert.py`: `0x1176` / 4470 bytes, `0x68` / 104 cases, `0x6a` / decimal case `106`, `0x20` / decimal case `32`, `0x4a` / decimal case `74`, outbound `0x45` / 69, outbound `0x75` / 117, and outbound `0x77` / 119.
- The same live audit reconfirmed representative case bodies rather than only labels: case `0x03` at `0x00507d0c` calls `0x0050feb0`; case `0x20` at `0x00507e45` performs inline day/night reads, writes `MapPane + 0x40f`, loads `dword_66DD78`, and calls `0x0050a8b0`; grouped cases `0x0b`, `0x26`, and `0x44` return success at `0x00507dca`; case `0x3b` at `0x005085f2` builds the CRC/checksum response with outbound opcode `0x45`; case `0x4a` at `0x005089ef` validates magic `0x7D3AFF99`, formats `%s\\Mscfg.dll`, writes one byte, truncates with `SetFilePointer`/`SetEndOfFile`, and calls the exit/shutdown helper; case `0x62` at `0x00508d5f` allocates the board/web-board dialog paths; case `0x67` at `0x00508833` allocates or updates timer UI; case `0x68` at `0x00508927` reads a 64-bit timestamp and sends outbound opcode `0x75`; and case `0x6a` at `0x00508ae3` writes `byte_66DEE0` / `g_friendNameListSyncEnabled` before calling `0x00574e50` when the payload flag is nonzero.
- 2026-06-16 B001 continuation batch9 corrected opcode `0x33`: live decompilation of `MapPane::HandlePacket` shows case `0x33` at `0x00508818` calls `0x0050fb00` for object-info/map-object packet handling, while case `0x03` remains the transition handler at `0x0050feb0`.
- 2026-06-13 `xrefs_to` refresh preserves the raw-duplicate caveats: raw starts `0x00510400` and `0x00514380` still have zero direct xrefs, while the live dispatcher references `0x005104d0`, `0x0050a8b0`, `0x0066dd78`, `0x00574e50`, and `0x0066dee0` at the expected case-local addresses. This supports keeping the enum values on the live `MapPane::HandlePacket` switch and treating the raw bodies as corroborating evidence, not separate opcode owners.
- 2026-06-22 B014 PhotoPane source-quality incorporation updates opcode `0x5a` from the stale `head/select dialog candidate` label to a PhotoPane/map-photo snapshot route. The payload shape is `uint16 mapId`, `uint16`/low-byte avatar shape or body byte, `uint8 avatarDirection`, `uint8 avatarTileX`, and `uint8 avatarTileY`; both the primary dispatcher call at `0x00508bc1` and the companion helper call at `0x00514461` allocate `0x198` bytes and call [UID:0001F2][0x00549620-0x00549bc5.PhotoAndPicturePanes](by-memory/0x00549620-0x00549bc5.PhotoAndPicturePanes.md). MapPane owns routing only; [UID:0000MK][PhotoPane](by-file/PhotoPane.md) owns the instantiated pane.

## UID00037W Day/Night Tint Synchronization

- Opcode `0x20` is the live source-bearing day/night route inside `MapPane::HandlePacket`; UID0001AX remains a reconstructable but non-standalone raw duplicate with a covered-by formal marker.
- [UID:0004RB][0x0050a840-0x0050a8b0.MapPaneComputeDayNightBrightnessAndTintRaw](by-memory/0x0050a840-0x0050a8b0.MapPaneComputeDayNightBrightnessAndTintRaw.md) resolves the clamped hour-table mapper and quadratic tint output. [UID:0004RC][0x0050a8b0-0x0050a932.MapPaneSetDayNightFadeTarget](by-memory/0x0050a8b0-0x0050a932.MapPaneSetDayNightFadeTarget.md) resolves the exact void target/tint setter and changed-path palette/redraw/motion order.
- Riding and Monster scaled-RLE consumers prove `+0x3d0` is tint amount, `+0x3d4` the new-human vertical projection divisor, and `+0x3d8` horizontal projection shear. Therefore the quadratic output and setter's second argument are tint amount, not transition duration.
- Historical duration helper/field aliases remain useful for old searches but are superseded current terminology. The enum formal remains blank because original protocol constant spellings across the full switch are not proven; this correction does not invent a partial enum declaration.

## Declaration Readiness

- `AUTOGEN_PARENT_UID` is [UID:0000L3][MapPane](by-file/MapPane.md) because the dispatcher owner is clear and both parent/child are now at or above the `80/80` attachment gate.
- A final C++ declaration should likely use `uint8_t`-sized constants or an enum scoped to the MapPane packet dispatcher, but only after payload structures and feature-specific route names are stabilized.
- Do not merge this page with [UID:00026H][0x00625008-0x0062ce50.ServerPacketNameTable](by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md). That table is broader protocol/debug label data; this page indexes the MapPane switch subset.
- Keep accepted no-op/ack cases explicit in documentation even if final source shares one return-success branch, because they are distinct packet values in the switch table.
- 2026-06-18 B002 MapPane class pass: keep this enum as a working dispatcher/payload index rather than a final emitted protocol header. MapPane exact handler pages may use descriptive opcode names, but [UID:00007Q][MapPane](by-class/MapPane.md) should not emit a class-level C++ enum/declaration until payload structures and handler names are synchronized.
- 2026-07-06 B015: a source dispatch table is the wrong source shape because `0x00508e06-0x00508f60` is compiler output. Any future enum/source emission should follow the case-group plan above and only promote names whose packet payloads and feature ownership boundaries have been reconstructed.

## Score Rationale

- Completion is `88` because the page includes dispatcher scope boundaries, route categories, observed values, raw duplicate caveats, representative case-target evidence, packet-name-table cross-checks, source-owner separation, declaration guidance, exact dispatcher child support, and now complete opcode-`0x20` brightness/tint helper semantics and real child links. It remains capped because many unrelated payload structures and final route names are still open.
- Confidence is `90` because the dispatcher boundary, switch span, representative values, raw duplicate caveats, packet-name labels, MapPane parent, and opcode-`0x20` tint/target field consumers are IDA/current-doc backed. It remains below final-source quality because many unrelated opcode names remain working labels and payload structures are incomplete.

## Open Questions

- Final names and payload structures for each opcode remain open only at the case-group level; use the 51-target plan above as the exact audit checklist.
- Whether some dialog-related opcodes should move to feature-specific packet enum pages once ownership is proven remains case-specific. Current placement keeps this page as the MapPane dispatcher index while feature pane bodies stay on their own pages.
- The meaning and intended purpose of opcode `0x4a`'s `Mscfg.dll` write/truncate path.
- Parent UID00037T no-code disposition is closed for this pass: formal dispatcher source requires exact case-group children/audits or a full behavior-preserving dispatcher reconstruction, not a thin switch skeleton.

## Cross-References

- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:00007Q][MapPane](by-class/MapPane.md)
- [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md)
- [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md)
- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md)
- [UID:0003TX][0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket](by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md)
- [UID:0003TY][0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket](by-memory/0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md) / `g_friendNameListSyncEnabled`
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md)
- [UID:00026H][0x00625008-0x0062ce50.ServerPacketNameTable](by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)
- [UID:0001QK][client_opcodes](by-meta/client_opcodes.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## Changes

- 2026-07-16 Agent-B005 UID0003TT accepted support synchronization: preserved `88/90`, owner/emitter UID0000L3, blank managed enum formal, complete unrelated opcode inventory, and original-spelling caveat; replaced only opcode `0x1d` with the exact direct Boolean route, payload, living/item behavior, UID0003HS dependency, trusted-buffer semantics, and unconditional success.
- 2026-07-15 B005 UID0003TK accepted source-quality callback: preserved `88/90`, owner/emitter route, all other opcode evidence, and the blank managed enum formal; replaced the generic opcode-`0x15` label with its exact direct Boolean route, payload, flag, and map-state/day-night lifecycle evidence without inventing an original constant spelling.

- 2026-07-15 B002 UID00037W accepted callback: raised the working enum index to `88/90`; corrected opcode `0x20` from transition-duration wording to exact quadratic tint amount, linked UID0004RB/UID0004RC, preserved live dispatcher ownership and raw UID0001AX duplicate evidence, and retained the blank formal enum because original protocol spellings remain incomplete.
- 2026-07-14 B001 UID0002F7 support synchronization: changed only opcode `0x42` and its case-target description from open exception/dialog candidate to exact ExchangeDialog routing, with constructor `0x004ac8a0`, allocation `0x27c`, and callers `0x005086c0`/`0x00513a77`. Scores, metadata, working-index caveat, blank formal C++, all other opcodes, and feature-owner boundaries remain unchanged.
- 2026-07-06 Agent-B011 UID0003TL implementation callback: added current B011 MCP session `b001-0001I5` evidence for opcode `0x06`: dispatcher `loc_507FF3` / case `6` calls `sub_510960` at `0x00507ffa`. Enum score and formal C++ remain unchanged.
- 2026-07-06 Agent-B015 UID00037T support sync:
  - Added current MCP session `7bfdc746` dispatcher reconfirmation, switch prologue/table-tail facts, raw duplicate no-route evidence, representative route groups, and the 51-target case-group plan.
  - Preserved this page as a working opcode index with blank formal enum code; source emission requires exact case-group children/audits and must not model the compiler jump table as hand-authored source.
- 2026-06-18 B004 friend/name-list raw duplicate range recheck:
  - Updated the opcode `0x6a` raw duplicate link to [UID:0001AZ][0x00514380-0x005143ba.FriendNameListSyncRawHandler](by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md). The corrected 58-byte body includes `ret 4` at `0x005143b7-0x005143ba`; the raw duplicate remains corroborating evidence, not a separate enum/source route.
- 2026-06-18 B002 MapPane teardown/object-packet sync:
  - Added outbound `0x0b` exit/logout/menu notification and outbound `0x0c` object-id refresh/missing-object request notes, explicitly separating them from same-byte inbound dispatcher cases.
- 2026-06-18 B003 day/night opcode source-quality:
  - Updated opcode `0x20` with day/night payload byte roles, table/helper names, MapPane lighting fields, and the no-route duplicate status for [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md).
- 2026-06-16 B001 continuation batch9:
  - Score unchanged at `86/88`.
  - Corrected opcode `0x33` from a stale transition-handler alias to the object-info/map-object packet handler at `0x0050fb00`; opcode `0x03` remains the map transition handler at `0x0050feb0`. Evidence: B001 live IDA/decompiler pass over `MapPane::HandlePacket` and exact children [UID:0003TX][0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket](by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md) and [UID:0003TY][0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket](by-memory/0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket.md).
- 2026-06-13 A002 Goal 2 live dispatcher audit:
  - Before: `COMPLETION:80`, `CONFIDENCE:84`, with strong written evidence but an explicit current-session cap because no fresh live dispatcher pass had been performed.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:88`, keeping `AUTOGEN_PARENT_UID:0000L3` and blank C++ below the final-source gate.
  - Summary/evidence: live IDA MCP on session `a001_goal2_0002UM` confirmed `sub_507C90` size `0x1176`, the switch-normalization span of 104 cases from `0x03` through `0x6a`, selected live case bodies for day/night, no-op/ack, CRC response, shutdown marker, board/web-board, timer, timestamp echo, and friend/name-list sync, plus zero direct xrefs to raw duplicate starts `0x00510400` and `0x00514380`. Existing exact dispatcher child [UID:00037T][0x00507c90-0x00508f60.MapPanePacketDispatcher](by-memory/0x00507c90-0x00508f60.MapPanePacketDispatcher.md), packet handler aggregate [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md), day/night raw body [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md), friend-sync docs, and [UID:00026H][0x00625008-0x0062ce50.ServerPacketNameTable](by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md) support the raised score while preserving final-name and payload-structure caveats.
- 2026-06-07 A002 dispatcher-boundary pass:
  - Before: `COMPLETION:74`, with observed values and evidence notes documented but limited category/scope guidance for separating the MapPane switch subset from broader protocol tables and feature-owned dialog classes.
  - Changed to: `COMPLETION:76`, `CONFIDENCE:82`, with dispatcher scope, route categories, declaration-readiness notes, score rationale, and a current-session IDA availability caveat.
  - Summary/evidence: [UID:0000L3][MapPane](by-file/MapPane.md), [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md), [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md), [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md), and client network/opcode meta pages support the MapPane switch subset, raw duplicate caveat, and feature-route ownership split.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: opcode `0x6a` evidence referenced the friend-list upload flag only as historical `byte_66DEE0`.
  - After: the page records resolved name `g_friendNameListSyncEnabled` beside the historical label.
  - Evidence: generated resolved-name report maps `byte_66DEE0` to `g_friendNameListSyncEnabled`; existing IDA-backed evidence already ties the flag write at `0x00508aff` to inbound case `0x6a` before the opcode `0x77` friend-name-list upload helper.
- 2026-06-07 A006 packet-name-table cross-check:
  - Before: `COMPLETION:76`, `CONFIDENCE:82`, with the MapPane dispatcher values documented but selected Socket packet-name-table labels only available through the separate table page.
  - Changed to: `COMPLETION:80`, `CONFIDENCE:84`, `AUTOGEN_PARENT_UID:0000L3`, with a packet-name-table cross-check section and explicit Socket-table versus MapPane-dispatcher ownership boundary.
  - Evidence: [UID:00026H][0x00625008-0x0062ce50.ServerPacketNameTable](by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md) documents fixed-stride labels for opcodes `0x04`, `0x07`, `0x12`, `0x1f`, `0x30`, and `0x3b`; existing [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md) and [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) retain MapPane ownership and final-name caveats.
