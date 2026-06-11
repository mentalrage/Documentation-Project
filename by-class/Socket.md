*** UID:0000DD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID:0000NS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# Socket

## Status

- Confidence: strong for class responsibility and owner file.
- Current Wave3 file: `class_Socket.cpp`
- Likely source module: [UID:0000NS][Socket](by-file/Socket.md)
- Current relevant ranges: `0x005747e0-0x00574ad8` and `0x00575d90-0x005796c7`; the `0x005967d0-0x005967e5` helper is now treated as inherited [UID:0000OR][Thread](by-file/Thread.md) infrastructure called by Socket setup.
- Evidence basis: `simroot_v2` generated source, Wave3 metadata/xrefs, and IDA MCP lookup/xref checks on 2026-05-23.

## Responsibility

`Socket` is the stateful client transport class. It wraps the thread/message command interface used by queued request senders, manages TCP and alternate serial/dispatch transports, parses incoming frames, transforms packet payloads, and performs final outbound framing and writes.

IDA MCP evidence from 2026-05-25 makes Socket the lifetime owner for [UID:0000Q5][g_packetSender](by-global/g_packetSender.md): the constructor writes the global, the normal destructor clears it, the constructor unwind helper [UID:0001I6][0x005794c0-0x005794cb.ClearPacketSenderGlobal](by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md) clears it on failure, and the scalar deleting destructor clears it from the vtable path. The final source-facing pointer type remains open because generated packet builders still call the broad queue/send path through a `CashShopRequest`-named method.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x005747e0` | `Socket` | Initializes `Thread`, handshake/key state, receive/frame buffers, mode defaults, `g_packetSender`, and optional mode-6 dispatch startup. |
| `0x005749e0` | `~Socket` | Closes Winsock/transport handles, sends mode-6 disconnect notifications, releases process argument/key buffer, and tears down base thread. |
| `0x00575d90` | `NoOpVirtualHook` | One-byte null virtual hook. |
| `0x00575da0` | `PollAndReceive` | Nonblocking `select` poll and transport-specific receive dispatch. |
| `0x00575e60` | `HandleSocketCommand` | Thread command dispatcher for connect, reset, receive, encoded send, raw send, transform-table setup, and handshake setup. |
| `0x00576290` | `InitializeTransport` | Selects TCP mode 5, mode 6 dispatch transport, or COM/serial transport. |
| `0x00576660` | `SendEncodedPacket` | Final packet framing/encoding path before Winsock, callback dispatch, or serial write. |
| `0x00576d90` | `SendPacket` | Sends an already formatted text packet/string through the active transport. |
| `0x00577140` | `ConnectEndpoint` | Winsock connection setup, async select, and fallback handling. |
| `0x00577b00` | `ProcessQueuedReceiveBlock` | Mode-6 receive-block path. |
| `0x00577f40` | `ProcessIncomingTransportData` | Non-TCP/non-mode-6 receive path. |
| `0x00578240` | `ReceiveNetworkData` | Winsock receive path. |
| `0x00578980` | `ParseFramePayload` | Decodes incoming frame payload bytes. |
| `0x00578b20` | `TransformFramePayload` | Applies packet transform table logic; see [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md). |
| `0x00578c40` | `BuildEncryptedPacket` | Builds encrypted/transformed outbound payloads; see [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md). |
| `0x005794c0` | `ClearPacketSenderGlobal` | Constructor-unwind cleanup helper that clears `g_packetSender`; not a public Socket API. |
| `0x005795a0` | `ScalarDeletingDestructor` | Vtable deleting destructor path that mirrors teardown and clears `g_packetSender`. |
| `0x005967d0` | inherited wait-handle helper call | Stale generated Socket-owned row; current IDA evidence says the helper itself is base `Thread` infrastructure, called from serial transport setup. |

## Transport Modes

Current generated source suggests:

- Mode `5`: Winsock/TCP path using configured server IP/port offsets and async select.
- Mode `6`: callback/dispatch transport using a configured callback target and message IDs such as `74`, `1052`, `1053`, `1985`, and `1986`.
- Other low modes: COM/serial transport using `CreateFileW`, `SetupComm`, `PurgeComm`, `SetCommTimeouts`, `ReadFile`, `WriteFile`, and overlapped events.

## Packet Encoding

`SendEncodedPacket` has two outbound formats:

- Binary frame format for `m_protocolModeFlag == 0`: optional transform/encryption, frame prefix `0xaa`, two-byte big-endian length, then payload.
- Text line format otherwise: optional transform/encryption, chunks encoded into `*`/`+` line records with sequence digits, comma continuation, and period final marker.

The packet buffer helper functions are separate utilities documented under [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md).

## Ownership Notes

- `Socket` should own transport handles, receive buffers, frame buffers, encryption/transform state, and transport callback state.
- `Socket` should own the lifetime of `g_packetSender`; current generated `CashShopRequest*` uses are queue/send call-site typing evidence, not global ownership evidence.
- `Socket` should not own high-level feature packet builders.
- `Socket` sequences packet transforms through helpers and state documented under [UID:0000M9][PacketTransform](by-file/PacketTransform.md) and [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md); the scalar big-endian helpers are better placed in `network/PacketBuffer.cpp`.

## Assignment Decision

`AUTOGEN_PARENT_UID` remains [UID:0000NS][Socket](by-file/Socket.md). The class is `86/85`, and the direct Socket file parent is now `88/85`, so both sides clear the corrected strict `85/85` gate. This only confirms source-root ownership; it does not finalize field names, helper splits, or C++ bodies.

## Score Rationale

- Completion `86`: class responsibility, likely source module, lifecycle/transport/send/receive/transform method families, transport modes, packet encoding, `g_packetSender` ownership, and exact memory references are documented.
- Confidence `85`: live IDA and existing memory pages strongly support the class identity and direct Socket file parent. Confidence remains below near-final because field layout, the final `g_packetSender` interface type, and packet-transform helper placement are still unresolved.

## Open Questions

- Review final field names once class layout inspection is reliable; targeted `inspect class-layout Socket --field-limit 80` timed out during this pass.
- Confirm the source-facing type of `g_packetSender` after reconciling Socket lifetime ownership with the generated `CashShopRequest::QueueAndSendPacket` call sites.
- Confirm whether packet transform helpers were separate original file-scope functions or private functions in the same socket translation unit.

## Cross-References

- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0001HS][0x005747e0-0x00574ad8.SocketLifecycle](by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md)
- [UID:0001I1][0x00575d90-0x005796c7.SocketTransportCore](by-memory/0x00575d90-0x005796c7.SocketTransportCore.md)
- [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md)
- [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md)
- [UID:0001I6][0x005794c0-0x005794cb.ClearPacketSenderGlobal](by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md)
- [UID:0001JZ][0x005967d0-0x005967e5.SocketThreadEvent](by-memory/0x005967d0-0x005967e5.SocketThreadEvent.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md)
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0000V3][PacketTransformHelpers](by-item/PacketTransformHelpers.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:00001H][CashShopRequest](by-class/CashShopRequest.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## Changes

- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and assigned parent `0000NS`.
  - Before: The stateful transport class remained unclassified in autogen coverage even though the class and parent file both met the 80/80 attach gate.
  - After: The class contributes to `Socket.cpp` as a reconstructable child without emitting final C++ yet.
  - Evidence: Live IDA MCP lookup confirms Socket lifecycle, command, transport, send/receive, transform, cleanup, and scalar-deleting starts from `0x005747e0` through `0x005795a0`; the inherited wait-handle helper at `0x005967d0` remains documented as base `Thread` infrastructure, not Socket-owned source.

- 2026-06-02 `0x005967d0` ownership update:
  - What existed before: the page listed `QueueThreadEvent` as a Socket method and left an open question about whether it was truly Socket-owned.
  - Changed to: the helper is described as inherited base `Thread` infrastructure called by Socket serial setup.
  - Summary/evidence: [UID:0001JZ][0x005967d0-0x005967e5.SocketThreadEvent](by-memory/0x005967d0-0x005967e5.SocketThreadEvent.md) now records IDA MCP lookup/decompile/disassembly/caller/callee/xref/raw-byte evidence for the Thread wait-handle append helper.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `82`.
- Evidence: the page documents responsibility, owner file, major transport ranges, important methods, transport modes, packet encoding, `g_packetSender` ownership, and subsystem cross-references; confidence remains capped by open field naming and helper/source split questions.
- 2026-06-10 A001 strict gate repair:
  - Changed confidence from `82` to `85`.
  - Summary/evidence: the Socket file parent now scores `88/85`, while this class page documents the transport responsibility, lifecycle, command/send/receive/transform method families, `g_packetSender` lifetime ownership, and inherited Thread helper exclusion. Final C++ remains blank because class fields, exact sender interface type, and packet-transform placement remain below final-source confidence.
