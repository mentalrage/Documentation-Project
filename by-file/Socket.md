*** UID:0000NS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:82 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# Socket

## Status

- Confidence: strong for class ownership and source module, medium for exact original folder name.
- Proposed module: `network/Socket.cpp`
- Current Wave3 file: `class_Socket.cpp`
- Main class: [UID:0000DD][Socket](by-class/Socket.md)
- Main address docs: [UID:0001HS][0x005747e0-0x00574ad8.SocketLifecycle](by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md), [UID:0001I1][0x00575d90-0x005796c7.SocketTransportCore](by-memory/0x00575d90-0x005796c7.SocketTransportCore.md), [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md), [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md), and [UID:0001JZ][0x005967d0-0x005967e5.SocketThreadEvent](by-memory/0x005967d0-0x005967e5.SocketThreadEvent.md)
- Evidence basis: `simroot_v2` generated source, Wave3 metadata, Wave3 xrefs, and IDA MCP lookup/xref checks on 2026-05-23.

## Hypothesis

The original client likely had a dedicated socket/transport source file for the `Socket` class. It should not be folded into feature protocol senders, UI dialogs, packet buffer helpers, or free packet transform helpers. `Socket` owns connection lifecycle, TCP/serial transport selection, receive framing, transform sequencing, final outbound packet encoding, and the lifetime of the shared packet-sender global.

The folder name is probably `network/` or `net/`; the source file itself was likely close to `Socket.cpp`.

## Contents

Likely source-level contents:

- `Socket` class implementation.
- TCP mode 5 connection setup through Winsock.
- Mode 6 dispatch transport setup through the configured callback target.
- COM/serial transport open/configure/close and overlapped reads.
- Binary and line-based outbound framing in `SendEncodedPacket`.
- Incoming byte/line/frame parsing and calls into packet transform helpers.
- Socket-owned globals such as [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), plus lifecycle/reset work for shared [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md) such as the packet sequence byte and process argument/key material.
- Current `simroot_v2/class_Socket.cpp` emits `WAVE3 OMITTED METHOD BODY` markers before [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md) and [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md), but generated bodies follow those markers. Treat the marker/body mismatch and `XorTransformBuffer` prototype drift as data-generation caveats before migration.

## File Split

Keep these nearby functions out of `Socket.cpp` unless later evidence proves otherwise:

- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md): scalar read/write/append helpers in the `0x00575380-0x00575abb` cluster. These are C-style packet utilities with hundreds of callers and no `Socket` instance dependency.
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md): handshake/nonce table builders and the shared XOR primitive used by Socket's encode/decode methods.
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md): request queue and send funnel. It calls into the transport path, but current evidence says `g_packetSender` lifetime is Socket-owned; [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) may still be a generated-name artifact or shared request-interface boundary. Current `simroot_v2` emits the companion queue primitive `0x00596960` as [UID:0000OR][Thread](by-file/Thread.md) infrastructure.
- Feature protocol send helpers such as clan, mail, board, map, item, and chat packet builders. Those should stay in their feature modules or a later `ProtocolSend.cpp` split.

## Evidence

- Wave3 reports `Socket` as the only class attached to `class_Socket.cpp`, with 26 included methods and owner file `class_Socket.cpp`.
- IDA MCP confirms key function boundaries: constructor `0x005747e0-0x005749d9`, destructor `0x005749e0-0x00574ad8`, `SendEncodedPacket` `0x00576660-0x00576c75`, `BuildEncryptedPacket` `0x00578c40-0x00578df1`, and `QueueThreadEvent` `0x005967d0-0x005967e5`.
- Wave3 and IDA both report three direct code refs to `SendEncodedPacket` from the destructor/scalar destructor and command dispatcher.
- IDA MCP `py_eval` on 2026-05-25 reports 489 xrefs and five direct writes to `0x0067a7ec`; the writer set is entirely the Socket constructor/destructor family, including [UID:0001I6][0x005794c0-0x005794cb.ClearPacketSenderGlobal](by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md) and scalar deleting destructor `0x005795a0`.
- The constructor seeds the handshake/key path, allocates packet buffers, initializes receive/frame state, sets `g_packetSender`, and optionally dispatches mode-6 startup messages.
- `HandleSocketCommand` maps queued request codes into transport initialization, reconnect/reset, receive dispatch, encoded sends, raw text sends, single-byte sends, transform table initialization, and handshake-block setup.
- `SendEncodedPacket` is the final outbound packet encoder: it chooses pass-through or encrypted opcode paths, builds binary `0xaa` frames or text line frames, and writes to Winsock, mode-6 callback dispatch, or serial `WriteFile`.

## Proposed Placement

```text
network/
  Socket.h
  Socket.cpp
```

Expected dependencies include `Thread`, `Application`/window access, configuration, memory allocation helpers, Winsock, Win32 serial APIs, and [UID:0000M9][PacketTransform](by-file/PacketTransform.md) helpers/tables. Feature packet construction should depend on this module through the recovered `QueueAndSendPacket`/request-send API or direct transport sends, not own the socket implementation.

## Open Questions

- Whether the original folder was named `network`, `net`, or a flatter top-level source file group.
- Whether [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) should be typed as `Socket*` or a base request/thread interface after reconciling the current `CashShopRequest::QueueAndSendPacket` generated owner.
- Whether mode 6 was an internal serial/debug transport, a launcher/proxy transport, or a legacy communications mode.
- Whether the packet transform helpers were compiled in a separate source file or as a private section of `Socket.cpp`.

## Cross-References

- [UID:0000DD][Socket](by-class/Socket.md)
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
- [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:00001H][CashShopRequest](by-class/CashShopRequest.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `88` and confidence to `82`.
  - Evidence: document covers transport hypothesis, source contents, file split exclusions, IDA/Wave3 evidence, packet sender ownership, proposed placement, open questions, and network cross-references; confidence is capped by exact original folder name and unresolved packet-transform/source split boundaries.
- 2026-05-31: Projected reconstruction path changed from blank to `NexusTK/network/`.
  - Before: validator reported the by-file root as missing `PROPOSED_RECONSTRUCTION_PATH`.
  - After: the page stages as `auto-generated/NexusTK/network/Socket.cpp`.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `network/Socket.cpp`, and this page's placement hypothesis uses `network/Socket.cpp` for the stateful transport class and `g_packetSender` lifetime.
