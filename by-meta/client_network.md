*** UID:0001QH | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Client Network Notes

## Status

- Confidence: medium
- Scope: high-level network/protocol notes for source-layout work
- Evidence basis: current by-* research and live IDA MCP checks through 2026-07-26. Historical `simroot_v2`/Wave3 material is lead-only and not authority.

## Current Model

The client network layer currently splits into three practical reconstruction areas:

- [UID:0000NS][Socket](by-file/Socket.md): stateful transport owner for Winsock, serial/mode-6 dispatch, receive parsing, packet transform, and final outbound framing.
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md): shared C-style packet field read/write/append/string helpers.
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md): handshake/key-table builders, packet nonce alternate table setup, and the shared XOR primitive used by Socket encode/decode.
- [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md): address-backed protocol transform state, including the dword LUT at `0x0066fe58` and the `0x0069ba40+` handshake/nonce/sequence table block.
- [UID:0000L6][MD5](by-file/MD5.md): shared digest utility used by [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md) for packet trailer bytes, and by non-network startup/screenshot paths.
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md): cash-shop/auth/download-specific request helpers; stale generated Socket send-corridor references remain search/provenance links rather than final ownership evidence.
- [UID:0000JC][FileDownloader](by-file/FileDownloader.md): shared WinINet HTTP download dispatcher for minimap and cash-shop/fitting-room download messages.

The shared [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) storage is now Socket-lifetime state and is best treated as `Socket *` in current source-facing documentation: IDA MCP on 2026-05-25 and the B003 2026-06-17 lifecycle pass found five direct writes, all in the Socket constructor/destructor family, including the constructor unwind cleanup at [UID:0001I6][0x005794c0-0x005794cb.ClearPacketSenderGlobal](by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md). The generated `CashShopRequest*` type on many call sites remains useful search/provenance evidence, but it is not final global ownership or type evidence.

Feature packet builders remain with their feature files. Exhaustive [UID:0000MV][ProtocolSend](by-file/ProtocolSend.md) research accepts the non-emitting split: no original central `ProtocolSend.cpp` module, owner, emitter, type, global, or source island is supported, while the shared send corridor belongs to Socket. Reopen that decision only for materially new direct source provenance, not additional callers of the existing Socket funnel. [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md) tracks the map/game-world inbound opcode table owned by [UID:0000L3][MapPane](by-file/MapPane.md); keep opcode meanings there until payload structures are stable enough for per-packet docs.

Cash-shop/fitting-room HTTP downloads are separate from the game socket protocol. [UID:0000JC][FileDownloader](by-file/FileDownloader.md), [UID:0000I1][CashShopVersionRequest](by-file/CashShopVersionRequest.md), and [UID:0000JE][FittingRoom](by-file/FittingRoom.md) use WinINet helpers for item-shop version/catalog data, including `itemshop.json`, while [UID:0000NS][Socket](by-file/Socket.md) remains the encrypted game transport. A 2026-05-25 IDA MCP xref pass ties [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md) / `dword_67A738` lifetime writes to the FileDownloader constructor/destructor family, so generated `g_pCashShopRequest` call sites must be checked by address before treating them as cash-shop class evidence.

## Feature Packet Findings

- [UID:0000MO][PowerDialogPane](by-file/PowerDialogPane.md): inbound packet case `0x46` in [UID:0000L3][MapPane](by-file/MapPane.md) allocates the power dialog and passes the payload to `0x00549c20`; outbound opcode `0x4c` subcommand `1` applies four threshold values, and subcommand `2` applies one selected slot/list entry.
- [UID:0000P6][VoteMenuPane](by-file/VoteMenuPane.md): the separate outbound opcode `0x46` request is feature-owned by `VoteMenuPane.cpp`, not by MapPane's inbound opcode switch. [UID:0002LZ][0x00556100-0x00556211.VoteMenuPaneSubmitVote](by-memory/0x00556100-0x00556211.VoteMenuPaneSubmitVote.md) returns immediately for an empty target name, converts the nonempty UTF-16 target to CP_ACP bytes, and builds the raw packet as `{0x46, 0x00, uint8 targetLength, targetBytes[targetLength], uint8 promote}`. Promote row `0` supplies `true`/`1`; Demote row `1` supplies `false`/`0`. The explicit send length is `targetLength + 4`; a local zero byte is placed immediately after that range before [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) sends through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). Opcode reuse is directional: inbound MapPane `0x46` remains the PowerDialog route, while outbound VoteMenuPane `0x46` is the promote/demote request.
- [UID:0000YT][0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat](by-memory/0x00466ca0-0x004670ad.CheckTimerSkewAndSendHeartbeat.md): application message-loop timing helper that builds a heartbeat/status packet through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) and [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md). Keep ownership with application timing; the network layer supplies the outbound queue/send path.
- [UID:0000I9][ClanBank](by-file/ClanBank.md) / [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md): clan-bank opcode `0x36` packet builders stay feature-owned under `ClanBank.cpp`. The active [UID:00010R][0x0048b1c0-0x0048b7dc.ClanBankPane](by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md) action handler and the retained raw helper island both build submit/close packets through PacketBuffer writers and [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md). Submit uses subtype `0x0d` for constructor action `10` / mode `0` and subtype `0x0c` for action `16` / mode `1`, selected slot as zero-extended UInt16BE, multi-count flag, UInt32BE amount, and explicit length `9`; close is `{0x36,0x0b}` length `2`. B010's MCP/PE proof found no function, xref, data-flow, pointer, or direct rel32 route to the retained raw helper starts, so those helpers keep blank C++ and no central `ProtocolSend.cpp`, Socket, PacketBuffer, or `g_packetSender` ownership move is supported.
- [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md): feature-local BlockListen packet builders send opcode `0x0d` from `NexusTK/social/BlockListenInputPanes.cpp`, not from central `ProtocolSend.cpp`, Socket, PacketBuffer, or `g_packetSender` ownership. [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md) is the fixed no-payload subcommand `0x01` list/mode request, currently a raw no-function/no-route helper with blank formal C++. [UID:0002S0][0x005b7010-0x005b70f7.SendAddBlockListenPacket](by-memory/0x005b7010-0x005b70f7.SendAddBlockListenPacket.md) is the retained file-local add helper for subcommand `0x02`; [UID:0001N0][0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName](by-memory/0x005b6cc0-0x005b700e.AddToBlockListenInputPaneSubmitBlockedName.md) also sends that same add packet inline after validation/config persistence rather than calling the retained helper. [UID:0002RZ][0x005b7360-0x005b7447.SendDeleteBlockListenPacket](by-memory/0x005b7360-0x005b7447.SendDeleteBlockListenPacket.md) is now documented as the retained file-local `static void __stdcall SendDeleteBlockListenPacket(const wchar_t*)` helper for subcommand `0x03`; B005's 2026-06-23 IDA MCP session `b880584f` found `0x005b7360`/`0x005b7447` are not modeled as functions, have zero start/end xrefs, sit between twelve leading and nine trailing `0xcc` bytes, and have no targeted absolute-VA route. [UID:0001N2][0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm](by-memory/0x005b7140-0x005b7354.DeleteFromBlockListenInputPaneOnConfirm.md) therefore stays documented as the validated delete/erase/persist path that sends the same delete packet inline rather than as a caller. The add/delete name payloads use one converted ANSI string, a one-byte payload-length prefix, low-byte `WideCharToMultiByte` source length, local-only terminators outside the explicit send length, `PacketBufferWriteUInt8`, `memmove`, `0x100` converted-buffer and `0x400` packet-buffer range checks, and `QueueAndSendPacket(g_packetSender, packet, convertedLength + 3)`.
- [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md): feature-local password-change packet builders send opcode `0x26` from the dialog source family, not from Socket, PacketBuffer, `g_packetSender`, or a central `ProtocolSend.cpp` owner. [UID:0002QC][0x004fe9e0-0x004febe2.SendPasswordChangeRequest](by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md) is the active submit sender reached from [UID:0002QA][0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore](by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md) at `0x004fe778`; it sends three converted text fields from controls `3`, `4`, and `5`. [UID:0002QB][0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount](by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md) is a retained no-route/account-id numeric variant with formal B005 `SendPasswordChangeRequestWithAccountId` C++: three `WideCharToMultiByte` text fields, `0x100` rangechecks, one-byte length writes through [UID:0003YJ][0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers](by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md) / `PacketBufferWriteUInt8`, payload copies represented as `memmove(...)` through [UID:0001BH][0x00516220-0x00516238.MemmoveWrapper](by-memory/0x00516220-0x00516238.MemmoveWrapper.md), a fourth wide text argument parsed by `_wtol` and serialized with `PacketBufferWriteUInt32BE`, then `QueueAndSendPacket(g_packetSender, packet, packetLength)`. Socket owns [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) and queue/send lifetime, while PacketBuffer owns scalar writers only; B004's no-function/no-xref/no-pointer/no-active-route evidence for [UID:0002QB][0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount](by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md) remains a liveness/confidence cap rather than a network-layer ownership signal.
- [UID:0000ND][ScreenshotCapture](by-file/ScreenshotCapture.md): BMP/PNG screenshot hotkeys reopen the saved file, hash it through [UID:0000L6][MD5](by-file/MD5.md), and send opcode `0x83` screenshot proof through the Socket-owned `QueueAndSendPacket` path; image pixels are not sent by this helper.
- [UID:0000M7][OptionPane](by-file/OptionPane.md): old and new option UI paths send outbound opcode `0x011b`. The old pane has a local three-byte sender at [UID:0001DQ][0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B](by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md) and a five-byte `0x011b`/`0x63` sender at [UID:00023I][0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers](by-memory/0x0053e3d0-0x0053e520.OptionPaneServerOptionUpdateHelpers.md); the newer/shared [UID:0000TL][SendOptionPacket11B_540E50](by-global/SendOptionPacket11B_540E50.md) at [UID:0001DY][0x00540e50-0x00540e91.SendOptionPacket11B](by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md) is also called by the `SelfLookPane` neighborhood. Treat the similar sender bodies as distinct physical functions with shared naming patterns.
- [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md): builds an 8-byte position/status upload and dispatches request code `8`. IDA callers are [UID:0000N0][ReconnectDialog](by-file/ReconnectDialog.md) and the [UID:0000OI][TerminalPane](by-file/TerminalPane.md) stream parser, so this is reconnect/terminal session state rather than cash-shop UI.
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md): inbound [UID:0000L3][MapPane](by-file/MapPane.md) opcode `0x6a` reads a flag byte into [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md); when nonzero, it calls [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md), which builds outbound opcode `0x77` from the 20 config name slots also written by [UID:0000JN][FriendListDialog](by-file/FriendListDialog.md). Treat the generated inventory name and `g_isCashShopEnabled` alias as suspect; current evidence favors a friend/name-list upload.
- [UID:0000P9][WebBoardDialog](by-file/WebBoardDialog.md): active and old web-board dialogs send opcode `0x73` when opened without an immediate URL/payload, start timeout timer `0x572`, and parse byte-length-prefixed web-board responses into browser cookies (`domain`, `boardinfo`) before navigating the embedded browser pane.

## Packet Buffer Conventions

Confirmed helper behavior:

- Multi-byte numeric fields are stored big-endian.
- Several write helpers store a spare zero byte immediately after the written field. B001 2026-06-17 PacketBuffer reanalysis treats this as an out-of-band scratch terminator/safety byte, not independent protocol payload.
- Cursor-based helpers advance by the data length, not by the trailing zero.
- String helpers use one-byte or two-byte length prefixes before ANSI payload bytes.
- Wide-string packet writes convert to ANSI before serialization.
- The small hostname/address helper pair inside the PacketBuffer helper island is currently routed through `network/PacketBuffer.cpp` as a network utility bucket. It is not Socket transport state and should move only if later evidence proves a stronger `NetworkAddress`/`NetUtil` source.

The helper family is documented at [UID:0000V1][PacketBufferHelpers](by-item/PacketBufferHelpers.md).

## Send Path

Current evidence supports this outbound path:

1. Feature/UI code builds a packet with packet-buffer helpers.
2. Feature/UI code calls the Socket-owned `QueueAndSendPacket` wrapper through `g_packetSender`.
3. `QueueAndSendPacket` copies the bytes, appends a zero byte, and dispatches request code `8` to its worker queue.
4. `Socket::HandleSocketCommand` handles send command `8`, calls `Socket::SendEncodedPacket`, then frees the queued buffer.
5. `Socket::SendEncodedPacket` performs opcode pass-through/encryption decisions, frame formatting, and final transport write.

The removed `simroot_v2/class_Thread.cpp` companion historically emitted the queue post primitive at `0x00596960` as `Thread::DispatchRequest`, and IDA decompilation matches generic queue/semaphore behavior. Current documentation and validator-owned `NexusTK/util/Thread.cpp/.h` accept it as base-thread request infrastructure; the exact Socket-owned send wrapper is documented at [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md).

The historical generated `CashShopRequest::SendRawData` row at `0x00574d00` is a raw-boundary case: IDA has no function object or external xrefs, but the complete function-shaped body allocates/copies raw bytes and dispatches request `0x0e`. The accepted retained source is `Socket::QueueHandshakeBlock`; negative raw-start route evidence remains history rather than a blank-body requirement.

The adjacent `0x00574d40-0x00575377` helpers are real IDA-modeled Socket functions: `QueueClientVersionStatusPacket` is reached from reconnect/terminal code, `BuildAndSendFriendNameListSync` from map inbound case `0x6a` and friend-list code, and [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md) from map packet handlers.

## Source Layout Implication

Proposed files:

```text
network/
  Socket.cpp
  PacketBuffer.cpp
  PacketTransform.cpp
  FileDownloader.cpp      // owns dword_67A738 lifetime and downloader message dispatch
cashshop/
  CashShopRequest.cpp     // request payload/queue class; some downloader submission helpers are provisional
util/
  MD5.cpp
```

`Socket.cpp`, `PacketBuffer.cpp`, and `PacketTransform.cpp/.h` are the established shared network layers. `Socket.cpp` owns `g_packetSender` storage/lifetime as `Socket *` and the complete command/packet corridor. `PacketTransform.cpp/.h` owns free transform helpers, definitions, and declarations, while Socket owns stateful member consumers and lifecycle sequencing. `FileDownloader.cpp` owns `dword_67A738` / `g_pCashShopRequest` lifetime; `Thread.cpp` owns generic request-queue primitives. Exhaustive UID0000MV research rejects a central ProtocolSend source unit: feature builders remain in their feature modules, and no standalone ProtocolSend artifact, owner, emitter, type, global, string, RTTI, vtable, or generated route exists. `MD5.cpp` remains shared utility code.

The 2026-08-15 exhaustive [UID:0000NP][Session](by-file/Session.md) audit closes the earlier generic `Session.cpp`/`GameSession.cpp` planning placeholder as a reviewed no-source-root boundary. Whole-binary function/global/name/string/type/import searches, all 40 Session-named documentation paths, generated output, and the nonlexical login/transport/thread/game-dispatch candidates found no generic class, global, lifetime bridge, source island, header consumer, or emitted fragment. The removed `simroot_v2` snapshot likewise had no generic network `Session` source; that observation is dated corroborating history, not current generated authority. Its Session-named output was specialized UI/social-dialog code: `DialogSession`, `DialogInSession`, and `BulletinSession`, which remain under `ui/dialogs/`.

## Open Questions

- Generic `Session.cpp` is no longer an ordinary open question. Reopen [UID:0000NP][Session](by-file/Session.md) only for materially new direct evidence: an original PDB/linker map/source archive/build manifest or source path, a generic class/global/lifetime object bridging login and game state, or a coherent unowned cluster not already represented by the 39 specialized support pages. Additional callers of existing Socket, PacketBuffer, PacketTransform, Thread, or feature send helpers do not qualify.
- Current best source-facing type for [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) is `Socket *`; Socket owns lifetime and consumes the queued command helpers. A later recovered sender interface remains possible, but generated `CashShopRequest*` aliases are now stale search/provenance only.
- Final source-facing type/name for [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md). FileDownloader owns the observed `0x0067a738` lifetime, but generated metadata still types it as `CashShopRequest*` and sometimes reuses the name for packet-send paths that are actually [UID:0000Q5][g_packetSender](by-global/g_packetSender.md).
- Final owner for downloader request submission helpers `0x0041b180`, `0x0041b200`, and `0x0041b270`: current behavior is cash-shop/minimap payload setup, but live callers pass the FileDownloader-lifetime singleton.
- `XorTransformBuffer` is resolved as a `void` helper with source ABI `source, destination, length, keyData, keyWordCount`; `PacketTransform.h` carries the declaration.
- [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md) now supplies exact header declarations, including `unsigned int g_packetTransformLut[256]`; stale generated byte-array forms are rejected history.
- Mode `6` transport is now bounded to callback/window-message dispatch using configured message ids rather than the COM/serial branch; the exact original source-facing purpose/name, such as launcher/proxy versus another legacy dispatch channel, remains open.
- Whether `CashShopRequest` was the original class name or a recovered owner for a broader request dispatcher.
- `0x00596960` is accepted as `Thread::DispatchRequest`; current Socket and downloader/cash-shop consumers use the generic base-thread primitive. Reopen a distinct derived wrapper only for materially new direct source or symbol evidence.
- Opcode `0x77` is resolved as Socket's friend-name-list sync over Config's 20 friend slots.
- Packet transform free helpers/globals use the accepted distinct `PacketTransform.cpp/.h` reconstruction route.
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
- [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md)
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md)
- [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:00021Y][0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers](by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md)
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

## 2026-08-17 B003 UID0000MV Source-Topology Closure

The central network topology is final for this evidence set: Socket owns its 18-definition command/packet corridor and transport class; Thread owns generic queue/wait infrastructure; PacketBuffer owns scalar serialization; PacketTransform owns free transform globals/helpers and a complete header; feature builders remain with their feature modules; FileDownloader owns downloader lifetime. UID0000MV is a `96/97` reviewed negative source-unit page with no emitted ProtocolSend artifact. Reopening that conclusion requires materially new original source/linker evidence, not another caller of existing Socket or feature send helpers.
