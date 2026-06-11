*** UID:0000MV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# ProtocolSend

## Status

- Confidence: strong for the current non-promotion decision, low for existence as a proven original file.
- Proposed module: `network/ProtocolSend.cpp` only if later cross-feature send-helper clustering supports it.
- Projected path status: `NONE`. Keep this page out of generated source roots until the promotion criteria below are met.
- Current recovered source: none as a clean source unit; `simroot_v2` has no `ProtocolSend` generated file.
- Primary notes: [UID:0001QH][client_network](by-meta/client_network.md)

## File Role

`ProtocolSend.cpp` is reserved as a possible future owner for cross-feature outbound packet builders, but it is not a current migration target. Current evidence is not strong enough to create a real source root: most packet builders still belong with their feature modules, [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) owns scalar serialization helpers, [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) currently owns the broad queue/send funnel, and [UID:0000NS][Socket](by-file/Socket.md) owns final transport framing plus [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) lifetime.

The strongest current evidence is negative: `simroot_v2` has no recovered `ProtocolSend` file, and the documented outbound path is already explained by feature-local packet construction followed by the current `CashShopRequest::QueueAndSendPacket` name, the generic `Thread::DispatchRequest` queue primitive at `0x00596960`, and `Socket::SendEncodedPacket`. A future `ProtocolSend.cpp` should only be created when multiple free helpers form a cohesive protocol API that is not feature-local, not base-thread queue infrastructure, and not the socket transport.

This is the same non-promotion pattern used by [UID:0000NP][Session](by-file/Session.md): keep the planning page for source-boundary hygiene, but use `PROPOSED_RECONSTRUCTION_PATH:"NONE"` until a distinct original source unit is proven.

## Current Evidence

- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) and [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md) keep the send wrapper under `CashShopRequest` for now, even though it has hundreds of cross-feature callers.
- The exact helpers at [UID:0001HW][0x00574d40-0x00574e44.SendPositionUpdate](by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md), [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md), and [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md) show why this placeholder remains open: they are not cash-shop-specific by caller evidence, but they still live in the same request-sender cluster rather than a proven `ProtocolSend.cpp` island. [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md) now records the `MapPane` inbound `0x6a` to outbound `0x77` case without promoting it to this placeholder.
- The currently documented `0x00574bb0` wrapper is not a transport writer: it checks a send-disabled byte, allocates a copied packet plus trailing zero, and posts request code `8` through the shared thread dispatch primitive. That behavior supports a generic sender-interface hypothesis, but it does not by itself prove an original standalone protocol-send source file.
- The non-cash-shop helpers inside the same cluster also fail the promotion test on their own. `SendPositionUpdate` has reconnect and terminal/parser callers, while `BuildAndSendFriendNameListSync` has map/friend-list evidence; both are feature-facing packet builders that happen to reuse the shared queue object rather than an observed central protocol API.
- Current `simroot_v2/class_Thread.cpp` emits `0x00596960` as `Thread::DispatchRequest`; do not create `ProtocolSend.cpp` merely to own this generic queue post helper.
- IDA MCP `py_eval` on 2026-05-25 found all direct writes to `0x0067a7ec` in the Socket constructor/destructor family, so `g_packetSender` storage/lifetime should not be moved into `ProtocolSend.cpp`.
- [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md) are shared scalar/string serialization utilities, not protocol-send wrappers.
- [UID:0001I1][0x00575d90-0x005796c7.SocketTransportCore](by-memory/0x00575d90-0x005796c7.SocketTransportCore.md) owns final encoded packet writes through `Socket::SendEncodedPacket` at `0x00576660-0x00576c75`.
- `simroot_v2` searches show many feature methods calling `QueueAndSendPacket`, but no clean `ProtocolSend` owner file or generic free-function island named that way.

## 2026-06-07 A008 Review

Live IDA MCP was unavailable during this pass after three connection attempts, so no new binary claims are added here. This review uses only existing documentation pages that already record IDA MCP checks, especially the request-sender queue pages, `client_network`, `Socket`, `PacketBuffer`, and `Thread`.

The reviewed pages strengthen the current placeholder decision:

- `QueueAndSendPacket` is broadly used and generic, but the documented body is a queue handoff through `0x00596960`, not a protocol-specific send API surface.
- The adjacent request-sender helpers mix reconnect, terminal, map, and friend-list behavior. That cross-feature shape keeps the source owner question open, but it still does not isolate a cohesive `ProtocolSend.cpp` module.
- `g_packetSender` lifetime evidence remains Socket-owned, while packet serialization and final transport framing already have stronger owners in `PacketBuffer` and `Socket`.
- A future promotion should therefore require new evidence for a source-level interface or free-helper family, not just high fan-in to `0x00574bb0`.

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
| Completion `84` | The page records current negative evidence, explicit `NONE` projected-path status, boundary rules, promotion criteria, and cross-references to the send queue, socket transport, packet buffer, packet transform, and `g_packetSender` lifetime owner. The 2026-06-07 review adds source-owner synthesis for the queue wrapper and adjacent helpers. Completion remains below source-root level because no real source unit or shared protocol-send API has been proven. |
| Confidence `86` | The documented decision to keep this as a placeholder is supported by existing IDA-backed Socket, PacketBuffer, PacketTransform, CashShopRequest, Thread, and client-network pages, plus the absence of a recovered `ProtocolSend` file. Confidence is not higher because live IDA MCP was unavailable on 2026-06-07 and future helper clustering could still promote a real owner. |

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
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md)
- [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0001I1][0x00575d90-0x005796c7.SocketTransportCore](by-memory/0x00575d90-0x005796c7.SocketTransportCore.md)

## Changes

- 2026-06-10 A002: Changed projected reconstruction path from `NexusTK/network/` to `NONE` and raised completion/confidence from `82/82` to `84/86`.
  - Before: the page documented a non-promotion decision but still carried a generated source path, making the placeholder look like a real current source root.
  - After: the page follows the [UID:0000NP][Session](by-file/Session.md) placeholder pattern: no generated root until a distinct `ProtocolSend.cpp` or cohesive shared protocol-send API is proven.
  - Evidence: existing IDA-backed Socket, PacketBuffer, PacketTransform, CashShopRequest, Thread, request-sender, and `client_network` pages already explain the outbound path without a standalone ProtocolSend source unit.
- 2026-06-07 A008: Raised completion/confidence from `80/80` to `82/82` after reviewing existing IDA-backed request-sender, client-network, Socket, PacketBuffer, and Thread documentation. Added an explicit conservative review note: the broad queue wrapper and adjacent non-cash-shop helpers keep the placeholder open, but they still do not prove a standalone `ProtocolSend.cpp`. Live IDA MCP was unavailable after three connection attempts, so no fresh binary claims were added.
- 2026-06-02: Raised completion/confidence from `76/62` to `80/80` and filled the candidate projected path as `NexusTK/network/`. This does not promote `ProtocolSend.cpp` to a proven source unit; it records that the current documented non-promotion decision is well supported while preserving the network placement to use only if future evidence proves a shared protocol-send module.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `76`, confidence `62`.
- Summary/evidence: the page clearly records negative evidence, boundary rules, promotion criteria, and cross-references for a possible future protocol-send owner; confidence remains low because the page itself states no clean original source unit is currently proven.
