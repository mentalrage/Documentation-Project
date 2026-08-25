*** UID:0000MV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:97 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NONE" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# ProtocolSend

## Status

- Confidence: very strong for the reviewed negative source-unit decision; no standalone original file, class, header, object, or emitter is supported by current evidence.
- Proposed module: none. Do not create `ProtocolSend.cpp` or `ProtocolSend.h` without materially new direct source provenance.
- Projected path status: `NONE`; canonical owner `NONE`; no emitter; formal CPP and H remain blank.
- Current recovered source: the complete candidate corridor is Socket-owned and emits through [UID:0000NS][Socket](by-file/Socket.md) / [UID:0000DD][Socket](by-class/Socket.md), with dependencies retained by Thread, PacketBuffer, PacketTransform, Config, Application, MemoryMan, and feature-local packet builders.
- Primary notes: [UID:0001QH][client_network](by-meta/client_network.md)

## File Role

This page records a rejected source split rather than a deferred migration target. Exhaustive current evidence assigns every source-shaped unit in `0x00574ae0-0x00575377` to `Socket`, assigns generic queue records to `Thread`, starts scalar serialization at `PacketBuffer` `0x00575380`, keeps transform/handshake support with `PacketTransform`, and leaves feature packet construction in feature sources. [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) is historical generated/search provenance only for this corridor.

The reconstructed outbound path is feature-local packet construction followed by `Socket::QueueAndSendPacket`, inherited `Thread::DispatchRequest` queueing at `0x00596960`, `Socket::HandleSocketCommand` command consumption, and `Socket::SendEncodedPacket` transport framing. No independent ProtocolSend receiver, lifetime, symbol, type, data island, or generated route exists.

Like [UID:0000NP][Session](by-file/Session.md), this documentation page is retained for source-boundary hygiene and to prevent duplicate speculative output. Its `NONE` path is the accepted reconstruction disposition, not an unresolved placeholder.

## Current Evidence

- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) and the non-emitting [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md) resolve the broad queue/send wrapper and all exact children to Socket.
- [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md), [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md), and [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md) are Socket members by receiver, field, dispatcher, lifetime, and contiguous source-order evidence; none proves a ProtocolSend island. Current documentation scores are `96/97` for this rejected source-unit page, `92/94` for the command-helper children, and `94/95` for the Socket file root.
- `Socket::QueueAndSendPacket` checks `m_sendDisabled`, allocates and copies the caller payload plus a local terminator, and posts command `8` through inherited Thread queueing. It has `416` code xrefs across `224` modeled containing functions plus `156` unmodeled sites.
- `QueueClientVersionStatusPacket` has reconnect and terminal/parser callers; `BuildAndSendFriendNameListSync` has map/friend-list callers. Both use Socket and Config state rather than a separate protocol object.
- `Thread::DispatchRequest` at `0x00596960` remains inherited queue infrastructure and is not re-owned here.
- All five direct writes to `g_packetSender` at `0x0067a7ec` occur in Socket construction/destruction/unwind/scalar-destruction paths; the global has `489` xrefs.
- [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md) begins after nine `0xcc` bytes and owns separate scalar/string serialization.
- [UID:0001I1][0x00575d90-0x005797ae.SocketTransportCore](by-memory/0x00575d90-0x005797ae.SocketTransportCore.md) owns final encoded packet writes through `Socket::SendEncodedPacket`.
- Current generated output routes the corridor through `NexusTK/network/Socket.cpp` and `Socket.h`; no ProtocolSend output, empty marker, declaration, or owner route exists.

## 2026-06-14 C001 IDA MCP Review

Current IDA MCP health reports `NexusTK.exe.i64`, image base `0x400000`, auto-analysis ready, Hex-Rays ready, and strings cache ready. This pass adds fresh negative evidence for keeping the page at `PROPOSED_RECONSTRUCTION_PATH:"NONE"` and `CANONICAL_OWNER:NONE`.

- `entity_query` over `0x00574000-0x00575b00` found no function names matching `Protocol`, `protocol`, or `Send`. A broader IDA name query found only OpenSSL-style protocol strings (`aNoProtocolOpti`, `aProtocolError`, `aProtocolNotSup`, `aWrongProtocolT`), not a NexusTK source owner symbol.
- `find_regex` over the IDA strings cache found no `ProtocolSend`, `protocol send`, or `Protocol Send` strings.
- The request-sender neighborhood inventory from `0x00574ae0-0x00575380` contains seventeen `sub_574...`/`sub_575...` functions, including the generic queue wrapper `0x00574bb0`, raw non-function `0x00574d00`, reconnect/terminal position sender `0x00574d40`, friend/name-list sender `0x00574e50`, status getter `0x00575370`, and packet-buffer helpers beginning at `0x00575380`; the names and callers do not isolate a standalone protocol-send API.
- `lookup_funcs` reconfirms `0x00574bb0` size `0x63`, `0x00574d00` is not a function, `0x00574d40` size `0x104`, `0x00574e50` size `0x51b`, `0x00575370` size `0x7`, `0x00575380` size `0x11`, `0x00596960` size `0x50`, and `0x00576660` size `0x615`.
- `xrefs_to 0x00574d00` returns no refs, while `xrefs_to 0x00596960` shows queue post calls from downloader/request helpers and the `0x00574...` cluster. This keeps `0x00596960` with [UID:0000OR][Thread](by-file/Thread.md) and does not justify creating a `ProtocolSend.cpp` source root.
- `analyze_function 0x00574bb0` decompiles the broad wrapper as send-disable check, packet copy with trailing zero, then request code `8` handoff to `0x00596960`. `analyze_function 0x00596960` decompiles as a generic queue/semaphore post. `analyze_function 0x00576660` remains the final transport writer that calls `send`/`WriteFile`, supporting [UID:0000NS][Socket](by-file/Socket.md) ownership for transport.

## 2026-06-07 A008 Review

Live IDA MCP was unavailable during this pass after three connection attempts, so no new binary claims are added here. This review uses only existing documentation pages that already record IDA MCP checks, especially the request-sender queue pages, `client_network`, `Socket`, `PacketBuffer`, and `Thread`.

The reviewed pages strengthened the then-open placeholder decision. This dated A008 reasoning is retained as historical evidence and is superseded by the accepted 2026-08-17 negative source-unit decision:

- `QueueAndSendPacket` is broadly used and generic, but the documented body is a queue handoff through `0x00596960`, not a protocol-specific send API surface.
- At that dated review stage, the adjacent request-sender helpers mixed reconnect, terminal, map, and friend-list behavior and left the source owner open. The later whole-corridor audit resolved the owner as Socket and still found no cohesive `ProtocolSend.cpp` module.
- `g_packetSender` lifetime evidence remains Socket-owned, while packet serialization and final transport framing already have stronger owners in `PacketBuffer` and `Socket`.
- The dated promotion condition required new evidence for a source-level interface or free-helper family, not just high fan-in to `0x00574bb0`; no such evidence was found, and the accepted current disposition is the non-emitting Socket split.

## Boundary Rules

- Do not move `Socket`, packet transform, MD5, or packet-buffer helpers here.
- Do not move `g_packetSender` storage here; its observed lifetime owner is Socket.
- Do not move feature-owned packet builders here solely because they call the shared send funnel.
- Do not move [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md) here. B008's 2026-06-19 source-quality recheck identifies it as a feature-local BlockListen `0x0d/0x01` no-payload helper inside [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), with no proven live caller route and no evidence for a shared `ProtocolSend.cpp` source unit.
- Do not move `Socket::QueueAndSendPacket` here. `CashShopRequest::QueueAndSendPacket` is a historical generated alias, while current receiver, lifetime, dispatcher, source-order, and generated-route evidence resolves the method to Socket.
- Do not move `Thread::DispatchRequest` here; base-thread queueing belongs with [UID:0000OR][Thread](by-file/Thread.md).
- Reopen this page's accepted negative source-unit decision only for materially new direct source evidence of a real shared protocol-send family; additional callers of the existing Socket funnel are insufficient.

## Promotion Criteria

The following are historical reopening criteria, not unfinished work. Reopen the accepted negative source-unit decision only if materially new direct source evidence appears:

- a cluster of non-class, non-feature packet send wrappers with shared naming and adjacent addresses;
- several generated feature files whose only unique code is thin packet-send forwarding that should clearly be centralized;
- import/source provenance or historical project evidence naming a protocol send source/header;
- an interface/base-class cleanup that moves `QueueAndSendPacket` and related dispatch helpers out of [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md).

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `96` | The page records the complete 18-unit candidate inventory, exact boundaries and alignment, command map, source split, current xref/caller accounting, receiver/lifetime evidence, generated route, negative symbol/type/data evidence, and explicit dispositions for every owner/dependency. The command-helper children are `92/94` and the accepted Socket file root is `94/95`; no provisional owner or implementation blocker remains here. |
| Confidence `97` | Socket ownership and the negative ProtocolSend source-unit decision are supported by the same receiver, private fields, Thread base queue, Socket dispatcher, Socket-only global lifetime, contiguous source order, and generated owner. The remaining cap reflects stripped literal historical file/name evidence, not an unresolved implementation blocker or deferred source placement. |

## Cross-References

- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0000NS][Socket](by-file/Socket.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:0000NP][Session](by-file/Session.md)
- [UID:0001HT][0x00574b90-0x00575377.CashShopRequestSendQueue](by-memory/0x00574b90-0x00575377.CashShopRequestSendQueue.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md)
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md)
- [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:0001I1][0x00575d90-0x005797ae.SocketTransportCore](by-memory/0x00575d90-0x005797ae.SocketTransportCore.md)

## 2026-08-17 B003 UID0000MV Accepted Callback

The accepted whole-candidate audit closes this page as a non-emitting negative source-unit record. The candidate corridor contains exactly eighteen source-shaped Socket units in binary order: commands `4`, `3`, `5`, synchronous `12`, `6`, raw retained `13`, command `7`, queue/send command `8`, command `9`, queued string command `10`, single-byte command `11`, connection-state getter, send-disabled setter, connection-flag setter, raw retained command `14`, client-version/status packet builder, friend-name-list packet builder, and connection-status getter. The historical aggregate begins at `0x00574b90` and omits the first six wrappers; it is a documentation slice, not a compilation-unit boundary.

Command ownership is exact: `Socket::HandleSocketCommand` consumes asynchronous commands `3` through `11`, `13`, and `14`; command `12` uses `Thread::DispatchRequestAndReturnEvent`. `Socket::QueueAndSendPacket` has `416` code xrefs across `224` modeled containing functions plus `156` unmodeled sites. `g_packetSender` has `489` xrefs and exactly five writes, all in Socket constructor/destructor/unwind/scalar-destructor paths. Representative callers load `g_packetSender` into `ECX`, proving Socket member dispatch rather than a shared free function.

The complete alignment map is `0x574ad8-0x574ae0`, `0x574af6-0x574b00`, `0x574b16-0x574b20`, `0x574b2c-0x574b30`, `0x574b47-0x574b50`, `0x574b66-0x574b70`, `0x574b83-0x574b90`, `0x574ba4-0x574bb0`, `0x574c13-0x574c20`, `0x574c35-0x574c40`, `0x574ca1-0x574cb0`, `0x574cc5-0x574cd0`, `0x574cdb-0x574ce0`, `0x574d3f-0x574d40`, `0x574e44-0x574e50`, `0x57536b-0x575370`, and `0x575377-0x575380`; every span is `0xcc`. The raw command-13 and command-14 starts have no function object, incoming xref, direct-call route, or VA/RVA pointer hit, but their exact source-shaped bodies and Socket dispatcher consumers justify retained Socket source rather than padding/no-code.

No ProtocolSend-owned global, static, table, string, resource, RTTI object, vtable, compiler thunk, constructor, destructor, UDT, typedef, header-only type, generated file, or independent receiver exists. `g_packetSender` belongs to Socket; queue records belong to Thread; scalar serializers begin at PacketBuffer `0x00575380`; transform state belongs to PacketTransform; opcode/payload builders remain feature-local. CashShopRequest ownership and the old `197`-modeled-caller count are historicalized rather than deleted.

The final source split is `NexusTK/network/Socket.cpp/.h` for the corridor and Socket layout, `NexusTK/util/Thread.cpp/.h` for queue/event machinery, `NexusTK/network/PacketBuffer.cpp/.h` for scalar serialization, `NexusTK/network/PacketTransform.cpp/.h` for transform/handshake support, and feature source files for packet builders. Formal ProtocolSend CPP/H remain blank by design.

## Changes

- 2026-08-17 B003 UID0000MV accepted callback: raised `87/88` to `96/97`, replaced stale placeholder/current CashShopRequest wording with the exhaustive negative source-unit decision, recorded the full Socket corridor, command/xref/lifetime/padding/source split, preserved historical evidence, and kept path/owner/formal channels empty.

- 2026-06-10 A002: Changed projected reconstruction path from `NexusTK/network/` to `NONE` and raised completion/confidence from `82/82` to `84/86`.
  - Before: the page documented a non-promotion decision but still carried a generated source path, making the placeholder look like a real current source root.
  - After: the page follows the [UID:0000NP][Session](by-file/Session.md) placeholder pattern: no generated root until a distinct `ProtocolSend.cpp` or cohesive shared protocol-send API is proven.
  - Evidence: existing IDA-backed Socket, PacketBuffer, PacketTransform, CashShopRequest, Thread, request-sender, and `client_network` pages already explain the outbound path without a standalone ProtocolSend source unit.
- 2026-06-07 A008: Raised completion/confidence from `80/80` to `82/82` after reviewing existing IDA-backed request-sender, client-network, Socket, PacketBuffer, and Thread documentation. Added an explicit conservative review note: the broad queue wrapper and adjacent non-cash-shop helpers keep the placeholder open, but they still do not prove a standalone `ProtocolSend.cpp`. Live IDA MCP was unavailable after three connection attempts, so no fresh binary claims were added.
- 2026-06-02: Raised completion/confidence from `76/62` to `80/80` and filled the candidate projected path as `NexusTK/network/`. This does not promote `ProtocolSend.cpp` to a proven source unit; it records that the current documented non-promotion decision is well supported while preserving the network placement to use only if future evidence proves a shared protocol-send module.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `76`, confidence `62`.
- Summary/evidence: the page clearly records negative evidence, boundary rules, promotion criteria, and cross-references for a possible future protocol-send owner; confidence remains low because the page itself states no clean original source unit is currently proven.
- 2026-06-14 C001: Raised completion/confidence from `84/86` to `87/88`.
  - Before: the page had a well-supported non-promotion decision, but the latest live-IDA evidence on the send cluster was not recorded.
  - After: added current MCP health, no protocol-send name/string evidence, exact request-sender function inventory, raw `0x00574d00` no-function/no-ref status, and decompilation summary for the queue wrapper, generic queue post, and final socket transport writer.
  - Evidence: `entity_query`, `find_regex`, `lookup_funcs`, `xrefs_to`, `analyze_component`, and `analyze_function` support keeping this page non-standalone.
- 2026-06-19 B008 [UID:0002RY][0x005b6c30-0x005b6c7c.SendBlockListenModePacket](by-memory/0x005b6c30-0x005b6c7c.SendBlockListenModePacket.md) support sync: no score change. Added explicit negative ownership guidance that the raw BlockListen `0x0d/0x01` helper remains feature-local to [UID:0000HS][BlockListenInputPanes](by-file/BlockListenInputPanes.md), not `ProtocolSend.cpp`.
