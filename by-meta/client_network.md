*** UID:0001QH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Network Notes

## Status

- Confidence: medium
- Scope: high-level network/protocol notes for source-layout work
- Evidence basis: `simroot_v2`, Wave3 metadata/xrefs, and IDA MCP checks through 2026-05-25.

## Current Model

The client network layer currently splits into three practical reconstruction areas:

- [UID:0000NS][Socket](by-file/Socket.md): stateful transport owner for Winsock, serial/mode-6 dispatch, receive parsing, packet transform, and final outbound framing.
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md): shared C-style packet field read/write/append/string helpers.
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md): handshake/key-table builders, packet nonce alternate table setup, and the shared XOR primitive used by Socket encode/decode.
- [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md): address-backed protocol transform state, including the dword LUT at `0x0066fe58` and the `0x0069ba40+` handshake/nonce/sequence table block.
- [UID:0000L6][MD5](by-file/MD5.md): shared digest utility used by [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md) for packet trailer bytes, and by non-network startup/screenshot paths.
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md): threaded request queue and broad `QueueAndSendPacket` funnel, with cash-shop/auth/download-specific request helpers.
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md): shared WinINet HTTP download dispatcher for minimap and cash-shop/fitting-room download messages.

The shared [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) storage is now Socket-lifetime state: IDA MCP on 2026-05-25 found five direct writes, all in the Socket constructor/destructor family, including the constructor unwind cleanup at [UID:0001I6][0x005794c0-0x005794cb.ClearPacketSenderGlobal](by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md). The generated `CashShopRequest*` type on many call sites remains useful queue/send evidence, but it is not final global ownership evidence.

Feature packet builders should remain with their feature files unless later evidence proves an original central `ProtocolSend.cpp` module for those helpers. [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) tracks the map/game-world inbound opcode table owned by [UID:0000L3][MapPane](by-file/MapPane.md); keep opcode meanings there until payload structures are stable enough for per-packet docs.

Cash-shop/fitting-room HTTP downloads are separate from the game socket protocol. [UID:0000JC][FileDownloader](by-file/FileDownloader.md), [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md), and [UID:0000JE][FittingRoom](by-file/FittingRoom.md) use WinINet helpers for item-shop version/catalog data, including `itemshop.json`, while [UID:0000NS][Socket](by-file/Socket.md) remains the encrypted game transport. A 2026-05-25 IDA MCP xref pass ties [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `dword_67A738` lifetime writes to the FileDownloader constructor/destructor family, so generated `g_pCashShopRequest` call sites must be checked by address before treating them as cash-shop class evidence.

## Feature Packet Findings

- [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md): inbound packet case `0x46` in [UID:0000L3][MapPane](by-file/MapPane.md) allocates the power dialog and passes the payload to `0x00549c20`; outbound opcode `0x4c` subcommand `1` applies four threshold values, and subcommand `2` applies one selected slot/list entry.
- [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md): application message-loop timing helper that builds a heartbeat/status packet through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) and [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md). Keep ownership with application timing; the network layer supplies the outbound queue/send path.
- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md): add/delete handlers update the local block-list config vector and send opcode `0x0d`; subcommand `0x02` adds a name and subcommand `0x03` deletes a name. Both convert a wide name to ANSI with a one-byte length prefix before calling the broad send funnel at `0x00574bb0`.
- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md): BMP/PNG screenshot hotkeys reopen the saved file, hash it through [UID:0000L6][MD5](by-file/MD5.md), and send opcode `0x83` screenshot proof through `CashShopRequest::QueueAndSendPacket`; image pixels are not sent by this helper.
- [UID:0000M7][OptionPane](by-file/OptionPane.md): old and new option UI paths send outbound opcode `0x011b`. The old pane has a local three-byte sender at [UID:0001DQ][0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B](by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md) and a five-byte `0x011b`/`0x63` sender at [UID:00023I][0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers](by-memory/0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers.md); the newer/shared [UID:0000TL][SendOptionPacket11B_540E50](by-global/SendOptionPacket11B_540E50.md) at [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md) is also called by the `SelfLookPane` neighborhood. Treat the similar sender bodies as distinct physical functions with shared naming patterns.
- [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md): builds an 8-byte position/status upload and dispatches request code `8`. IDA callers are [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) and the [UID:0000OI][TerminalPane](by-file/TerminalPane.md) stream parser, so this is reconnect/terminal session state rather than cash-shop UI.
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md): inbound [UID:0000L3][MapPane](by-file/MapPane.md) opcode `0x6a` reads a flag byte into [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md); when nonzero, it calls [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md), which builds outbound opcode `0x77` from the 20 config name slots also written by [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md). Treat the generated inventory name and `g_isCashShopEnabled` alias as suspect; current evidence favors a friend/name-list upload.
- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md): active and old web-board dialogs send opcode `0x73` when opened without an immediate URL/payload, start timeout timer `0x572`, and parse byte-length-prefixed web-board responses into browser cookies (`domain`, `boardinfo`) before navigating the embedded browser pane.

## Packet Buffer Conventions

Confirmed helper behavior:

- Multi-byte numeric fields are stored big-endian.
- Several write helpers append a zero byte immediately after the written field.
- Cursor-based helpers advance by the data length, not by the trailing zero.
- String helpers use one-byte length prefixes before ANSI payload bytes.
- Wide-string packet writes convert to ANSI before serialization.

The helper family is documented at [UID:0000V1][PacketBufferHelpers](by-item/PacketBufferHelpers.md).

## Send Path

Current evidence supports this outbound path:

1. Feature/UI code builds a packet with packet-buffer helpers.
2. Feature/UI code calls the currently generated `CashShopRequest::QueueAndSendPacket` wrapper, usually through `g_packetSender`.
3. `QueueAndSendPacket` copies the bytes, appends a zero byte, and dispatches request code `8` to its worker queue.
4. `Socket::HandleSocketCommand` handles send command `8`, calls `Socket::SendEncodedPacket`, then frees the queued buffer.
5. `Socket::SendEncodedPacket` performs opcode pass-through/encryption decisions, frame formatting, and final transport write.

Current `simroot_v2/class_Thread.cpp` emits the queue post primitive at `0x00596960` as `Thread::DispatchRequest`, and IDA decompilation matches generic queue/semaphore behavior. Treat this as base-thread request infrastructure in source-layout planning unless a later class-layout pass proves a more specific derived owner. The exact send wrapper is documented at [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md).

The generated `CashShopRequest::SendRawData` row at `0x00574d00` is a raw-boundary case: IDA has no function object and no external xrefs to that start, but disassembly shows a complete function-shaped body through `0x00574d3f` that allocates/copies raw bytes and dispatches request code `0x0e`. A 2026-05-27 raw-pointer scan also found no loaded dword equal to the raw start. Keep this as a provisional request-queue helper, not final socket transport code.

The adjacent `0x00574d40-0x00575377` helpers are real IDA-modeled functions, but they are not cash-shop-specific by caller evidence: `SendPositionUpdate` is reached from reconnect/terminal code, `BuildAndSendInventoryData` is reached from map inbound case `0x6a` and friend-list code, and [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md) is reached from map packet handlers.

## Source Layout Implication

Proposed files:

```text
network/
  Socket.cpp
  PacketBuffer.cpp
  PacketTransform.cpp
  FileDownloader.cpp      // owns dword_67A738 lifetime and downloader message dispatch
  ProtocolSend.cpp      // only if later feature helper clustering supports it
cashshop/
  CashShopRequest.cpp     // request payload/queue class; some downloader submission helpers are provisional
util/
  MD5.cpp
```

`Socket.cpp`, `PacketBuffer.cpp`, and `PacketTransform.cpp` are now stronger than the earlier generic `Session.cpp`/`ProtocolSend.cpp` placeholders. `Socket.cpp` should own `g_packetSender` storage/lifetime unless later source evidence moves the declaration to a shared network header. `PacketTransform.cpp` should own the transform helper globals documented in [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md), while Socket owns lifecycle/reset sequencing for the process/key pointer and packet sequence byte. `FileDownloader.cpp` should own `dword_67A738` / `g_pCashShopRequest` lifetime, while the exact source-facing type/name and the `0x0041b180`/`0x0041b200`/`0x0041b270` submission-helper owner remain open. `Thread.cpp` owns the generic `0x00596960` request queue post primitive unless later evidence proves otherwise. `ProtocolSend.cpp` remains a placeholder for cross-feature free send helpers and for a possible request-sender interface split, not for `Socket`, `PacketBuffer`, base-thread queue primitives, packet transform/key-table helpers, or the HTTP downloader by default. `MD5.cpp` is listed under `util/` because the digest island is shared by socket packet encoding, startup/minimap update handling, and screenshot proof submission.

`simroot_v2` currently has no generated `ProtocolSend` or generic network `Session` source. The `Session` names it does emit are UI/social-dialog modules: `DialogSession`, `DialogInSession`, and `BulletinSession`. Keep those under `ui/dialogs/` unless a later pass finds a distinct game-session owner.

## Open Questions

- Final source-facing type for [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). Socket owns its lifetime, but current generated code still inconsistently treats the pointed-to object like `CashShopRequest*`, `Socket*`, or a generic send object.
- Final source-facing type/name for [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md). FileDownloader owns the observed `0x0067a738` lifetime, but generated metadata still types it as `CashShopRequest*` and sometimes reuses the name for packet-send paths that are actually [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- Final owner for downloader request submission helpers `0x0041b180`, `0x0041b200`, and `0x0041b270`: current behavior is cash-shop/minimap payload setup, but live callers pass the FileDownloader-lifetime singleton.
- Final source-facing prototype for `XorTransformBuffer`; current generated `class_Socket.cpp` and recovered helper output still disagree on return type and pointer types, and the exact Socket sequencing pages for [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md) / [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md) retain the migration caveat.
- Final source-facing declarations for [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md), especially `g_packetTransformLut`: generated output treats it as a byte array, while IDA shows 256 dword writes and dword key consumption.
- Whether mode 6 transport is a launcher/proxy channel, serial/debug mode, or another legacy transport.
- Whether `CashShopRequest` was the original class name or a recovered owner for a broader request dispatcher.
- Whether `0x00596960` should be modeled only as `Thread::DispatchRequest`, with `CashShopRequest` inheriting/using it, or whether there was a derived wrapper not yet recovered.
- Final source-facing name and feature owner for opcode `0x77`; current caller/config-slot evidence favors friend/name-list upload semantics over item inventory state.
- Whether packet transform helpers were a distinct packet encryption/protocol helper file or a private helper section inside `Socket.cpp`.
- Whether the original MD5 file was `MD5.cpp`, `md5.c`, or part of a broader utility/hash source file.

## Cross-References

- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000DD][Socket](by-class/Socket.md)
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0000V3][PacketTransformHelpers](by-item/PacketTransformHelpers.md)
- [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md)
- [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md)
- [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md)
- [UID:0000L6][MD5](by-file/MD5.md)
- [UID:0000V2][PacketDigest_00515380](by-item/PacketDigest_00515380.md)
- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md)
- [UID:0000VF][ScreenshotProofPacket_00558240](by-item/ScreenshotProofPacket_00558240.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0000V1][PacketBufferHelpers](by-item/PacketBufferHelpers.md)
- [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:00001H][CashShopRequest](by-class/CashShopRequest.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0000TL][SendOptionPacket11B_540E50](by-global/SendOptionPacket11B_540E50.md)
- [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md)
- [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0000PG][byte_66DEE0](by-global/byte_66DEE0.md)
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md)
- [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md)
- [UID:0001OP][0x0067a738-0x0067a73c.g_pCashShopRequest](by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md)
- [UID:0001I6][0x005794c0-0x005794cb.ClearPacketSenderGlobal](by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md)
- [UID:0000MV][ProtocolSend](by-file/ProtocolSend.md)
- [UID:0000NP][Session](by-file/Session.md)
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md)
- [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md)
- [UID:0000JE][FittingRoom](by-file/FittingRoom.md)
- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md)
- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
