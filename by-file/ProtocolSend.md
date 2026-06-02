*** UID:0000MV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ProtocolSend

## Status

- Confidence: strong for the current non-promotion decision, low for existence as a proven original file.
- Proposed module: `network/ProtocolSend.cpp` only if later cross-feature send-helper clustering supports it.
- Current recovered source: none as a clean source unit; `simroot_v2` has no `ProtocolSend` generated file.
- Primary notes: [UID:0001QH][client_network](by-meta/client_network.md)

## File Role

`ProtocolSend.cpp` is reserved as a possible future owner for cross-feature outbound packet builders. Current evidence is not strong enough to create a real migration target: most packet builders still belong with their feature modules, [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) owns scalar serialization helpers, [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) currently owns the broad queue/send funnel, and [UID:0000NS][Socket](by-file/Socket.md) owns final transport framing plus [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) lifetime.

The strongest current evidence is negative: `simroot_v2` has no recovered `ProtocolSend` file, and the documented outbound path is already explained by feature-local packet construction followed by the current `CashShopRequest::QueueAndSendPacket` name, the generic `Thread::DispatchRequest` queue primitive at `0x00596960`, and `Socket::SendEncodedPacket`. A future `ProtocolSend.cpp` should only be created when multiple free helpers form a cohesive protocol API that is not feature-local, not base-thread queue infrastructure, and not the socket transport.

## Current Evidence

- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) and [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md) keep the send wrapper under `CashShopRequest` for now, even though it has hundreds of cross-feature callers.
- The exact helpers at [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md), [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md), and [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md) show why this placeholder remains open: they are not cash-shop-specific by caller evidence, but they still live in the same request-sender cluster rather than a proven `ProtocolSend.cpp` island. [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md) now records the `MapPane` inbound `0x6a` to outbound `0x77` case without promoting it to this placeholder.
- Current `simroot_v2/class_Thread.cpp` emits `0x00596960` as `Thread::DispatchRequest`; do not create `ProtocolSend.cpp` merely to own this generic queue post helper.
- IDA MCP `py_eval` on 2026-05-25 found all direct writes to `0x0067a7ec` in the Socket constructor/destructor family, so `g_packetSender` storage/lifetime should not be moved into `ProtocolSend.cpp`.
- [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md) are shared scalar/string serialization utilities, not protocol-send wrappers.
- [UID:0001I1][0x00575d90-0x005796c7.SocketTransportCore](by-memory/0x00575d90-0x005796c7.SocketTransportCore.md) owns final encoded packet writes through `Socket::SendEncodedPacket` at `0x00576660-0x00576c75`.
- `simroot_v2` searches show many feature methods calling `QueueAndSendPacket`, but no clean `ProtocolSend` owner file or generic free-function island named that way.

## Boundary Rules

- Do not move `Socket`, packet transform, MD5, or packet-buffer helpers here.
- Do not move `g_packetSender` storage here; its observed lifetime owner is Socket.
- Do not move feature-owned packet builders here solely because they call the shared send funnel.
- Do not move `CashShopRequest::QueueAndSendPacket` here until class/interface cleanup proves it was not originally part of the request queue class.
- Do not move `Thread::DispatchRequest` here; base-thread queueing belongs with [UID:0000OR][Thread](by-file/Thread.md).
- Use this page only when a future caller/resource/name pass proves a real family of shared protocol send wrappers.

## Promotion Criteria

Promote this placeholder to a real source module only if a future pass finds at least one of:

- a cluster of non-class, non-feature packet send wrappers with shared naming and adjacent addresses;
- several generated feature files whose only unique code is thin packet-send forwarding that should clearly be centralized;
- import/source provenance or historical project evidence naming a protocol send source/header;
- an interface/base-class cleanup that moves `QueueAndSendPacket` and related dispatch helpers out of [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md).

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `80` | The page records current negative evidence, network placement if promotion happens, boundary rules, promotion criteria, and cross-references to the send queue, socket transport, packet buffer, packet transform, and `g_packetSender` lifetime owner. Completion remains capped because no real source unit or shared protocol-send API has been proven. |
| Confidence `80` | The documented decision to keep this as a placeholder is well supported by existing Socket, PacketBuffer, PacketTransform, CashShopRequest, and client-network pages. Confidence is not higher because the existence of an original `ProtocolSend.cpp` remains unproven and future helper clustering could change the owner model. |

## Cross-References

- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:0000NP][Session](by-file/Session.md)
- [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md)
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendInventoryData](by-memory/0x00574e50-0x0057536b.BuildAndSendInventoryData.md)
- [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0001I1][0x00575d90-0x005796c7.SocketTransportCore](by-memory/0x00575d90-0x005796c7.SocketTransportCore.md)

## Changes

- 2026-06-02: Raised completion/confidence from `76/62` to `80/80` and filled the candidate projected path as `NexusTK/network/`. This does not promote `ProtocolSend.cpp` to a proven source unit; it records that the current documented non-promotion decision is well supported while preserving the network placement to use only if future evidence proves a shared protocol-send module.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `76`, confidence `62`.
- Summary/evidence: the page clearly records negative evidence, boundary rules, promotion criteria, and cross-references for a possible future protocol-send owner; confidence remains low because the page itself states no clean original source unit is currently proven.
