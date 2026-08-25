*** UID:0000NS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/network/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# Socket

## UID0000KA Packet-Send Consumer - 2026-08-15

Inventory packet helpers consume the existing `g_packetSender` and `Socket::QueueAndSendPacket(PacketBuffer *, int)` declarations from `network/Socket.h`. Legacy and Pane2 own their exact packet bytes and fixed send lengths; Socket retains queue/thread/global sender ownership. No inventory-local sender, free send wrapper, duplicate global, or score change is introduced.

## 2026-08-14 B003 ChangePassword Dependency Incorporation

- UID0000DD now supplies exact guarded `Socket.h` and CPP include/children formals; UID0000Q5 supplies the source-era `NULL` definition and matching extern. The generated H exposes `QueueAndSendPacket(const void *, short)` and `g_packetSender` without an undocumented free wrapper.
- UID0002QB and UID0002QC remain ChangePasswordDialogPane-owned packet builders and use Socket only as the send API. Packet construction, password validation, and reply logic do not move here. At that dated callback the file metadata remained `90/91`; the current whole-file score is `94/95`.

## Status

- Confidence: very strong for class ownership, source module, Thread-derived virtual order, and the `OnStart`/`OnIdle` override contract; medium-high for exact original folder name and some private transport spellings.
- Proposed module: `network/Socket.cpp`
- Historical generated file: `class_Socket.cpp`; this is provenance only and is not the current source-placement authority.
- Main class: [UID:0000DD][Socket](by-class/Socket.md)
- Main address docs: [UID:0001HS][0x005747e0-0x00574ad8.SocketLifecycle](by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md), [UID:000242][0x00574ae0-0x00574b83.SocketEventDispatchHelpers](by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md), [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md), [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md), [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md), [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md), [UID:0001I1][0x00575d90-0x005797ae.SocketTransportCore](by-memory/0x00575d90-0x005797ae.SocketTransportCore.md), exact raw transport children [UID:0003A6][0x00576570-0x00576623.SocketReconnectEndpointRaw](by-memory/0x00576570-0x00576623.SocketReconnectEndpointRaw.md) and [UID:0003A7][0x00577610-0x0057779e.SocketOpenSerialTransportRaw](by-memory/0x00577610-0x0057779e.SocketOpenSerialTransportRaw.md), [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md), and [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md). [UID:0001JZ][0x005967d0-0x005967e5.ThreadAddWaitHandleHelper](by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md) and sibling `Thread::RemoveLastWaitHandle()` remain inherited Thread infrastructure.
- Evidence basis: current by-* documentation, live IDA MCP function/vtable/call-site evidence, and legacy generated/metadata artifacts retained only as historical provenance.

## Hypothesis

The original client likely had a dedicated socket/transport source file for the `Socket` class. It should not be folded into feature protocol senders, UI dialogs, packet buffer helpers, or free packet transform helpers. `Socket` owns connection lifecycle, TCP/serial transport selection, receive framing, transform sequencing, final outbound packet encoding, the lifetime of the shared packet-sender global, and the command-posting methods that enqueue work for `Socket::HandleSocketCommand`.

The folder name is probably `network/` or `net/`; the source file itself was likely close to `Socket.cpp`.

## Source Split And Boundaries

Current source-placement policy after the B006 Rule 26 pass:

- `Socket.cpp` owns the `Socket` class, vtable-driven transport methods, lifecycle, command wrappers, active transport handles, stateful receive/frame buffers, final packet framing, and the `g_packetSender` lifetime.
- [UID:0000OR][Thread](by-file/Thread.md) owns the generic queue and wait-handle primitives: `Thread::DispatchRequest` at `0x00596960`, `Thread::DispatchRequestAndReturnEvent` at `0x00596a00`, `Thread::AddWaitHandle` at `0x005967d0`, and the remove-last helper reached by `CloseTransport` at tail jump `0x00577aef`.
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md) owns scalar packet cursor/endian/string serialization helpers. These are used by Socket and feature packet builders but do not depend on a `Socket` instance.
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md) owns free transform helpers and globals such as `BuildHandshakeBlock`, `InitializePacketNonce`, `XorTransformBuffer`, `g_packetTransformLut`, `g_handshakeSeedBytes`, `g_packetNonceScratch`, `g_packetTransformStride`, `g_packetSequenceByte`, and the primary/alternate XOR tables.
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) keeps only cash-shop/download payload request behavior. Generated `CashShopRequest::*` names on the Socket send corridor are historical search/provenance only.

Socket owns the stateful methods that call into these helpers: `SendEncodedPacket`, `SendPacket`, `ProcessQueuedReceiveBlock`, `ProcessIncomingTransportData`, `ReceiveNetworkData`, `ParseFramePayload`, `TransformFramePayload`, and `BuildEncryptedPacket`.

The `Socket` declaration overrides inherited `Thread::OnStart()` at `0x00575d90` and `Thread::OnIdle()` at `0x00575da0`. `OnStart` is the empty startup hook selected at Thread vtable offset `+0x14`; `OnIdle` performs nonblocking `select`/receive polling at offset `+0x28` after every non-stopping worker wait iteration. Older names `NoOpVirtualHook` and `PollAndReceive` are retained only as historical/behavior aliases and must not appear as distinct source virtuals.

2026-06-30 B007 implementation callback for [UID:0000NS] accepted MCP-backed empty-emitter cleanup: `supervisor_resume_20260629` was active/healthy, generated `Socket.cpp` command id `000000002968` had one filled class plus fifteen Socket-family empty markers, and every accepted marker now has either formal source or a target-specific formal no-code/data-alias proof in the relevant support page. The score moves from `88/85` to `90/89` because current MCP reconfirmed exact helper boundaries, Socket-owned sender lifetime, vtable/literal data, transform methods, and data boundaries. Confidence remains below final because original folder/header spelling, some helper typedefs, and the full packed `Socket` ABI remain inferred.

## 2026-08-17 UID0000MV Whole-File Closure

The command/packet corridor now contributes exactly eighteen Socket definitions in address/source order: `PostConnectWithFallbackCommand`, `PostConnectCommand`, `PostResetConnectionCommand`, `PostConnectionStatusQuery`, `PostReconnectEndpointCommand`, `PostPacketTransformTableCommand`, `PostSocketReceiveCommand`, `QueueAndSendPacket`, `PostSocketModeByteCommand`, `QueueTransportStringCommand`, `SendSingleByteCommand`, `IsSocketConnectedState`, `SetSocketSendDisabled`, `SetSocketConnectionFlag`, retained `QueueHandshakeBlock`, `QueueClientVersionStatusPacket`, `BuildAndSendFriendNameListSync`, and `GetConnectionStatus`.

The rest of the compilation unit remains the established Socket lifecycle and transport family: constructor/destructor, `OnStart`, `OnIdle`, `HandleSocketCommand`, `QueryTransportState`, `HandleReceiveEvent`, transport initialization/reset/connect/close, receive dispatch/parsing, final packet sends, `TransformFramePayload`, and `BuildEncryptedPacket`. Compiler-generated unwind/deleting-destructor artifacts are represented through owner source or explicit no-standalone-body dispositions. Thread queue helpers, PacketBuffer scalar helpers, PacketTransform free helpers/globals, feature packet builders, and CashShopRequest downloader behavior remain separate.

The generated source/header route is solely `NexusTK/network/Socket.cpp` and `Socket.h`. UID0000MV has no owner/emitter/formal channel and produces no standalone ProtocolSend output or empty marker. The Socket CPP include block declares every consumed Application, Config, StartupWindow, MemoryMan, StringBase, STL, CRT, and PacketTransform dependency; Socket H contains every method declaration and the exact `0x3aa54` field layout.

## Contents

Likely source-level contents:

- `Socket` class implementation, including inherited `Thread::OnStart()` and `Thread::OnIdle()` overrides.
- TCP mode 5 connection setup through Winsock.
- Mode 6 dispatch transport setup through the configured callback target.
- COM/serial transport open/configure/close and overlapped reads.
- Binary and line-based outbound framing in `SendEncodedPacket`.
- Incoming byte/line/frame parsing and calls into packet transform helpers.
- Socket-owned globals such as [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), plus lifecycle/reset work for shared [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md) such as the packet sequence byte and process argument/key material.
- Source-facing command wrappers for command IDs `3` through `14`: connect/fallback connect, reset, reconnect, receive, queued encoded send, protocol-mode byte, queued transport string, single-byte send, event-backed command `12` as `Socket::PostConnectionStatusQuery(bool *outConnected)`, raw transform-table command `13`, and retained raw handshake-block queue command `14`.
- [UID:0001I6][0x005794c0-0x005794cb.ClearPacketSenderGlobal](by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md) is Socket constructor-unwind cleanup evidence, not a source-facing helper API. Raw PE/Capstone recheck on 2026-06-18 confirms it has one EH tail-jump route from `0x0060805e`, clears `g_packetSender`, has no callees or pointer/table refs, and should be represented through Socket lifetime source rather than formal standalone C++.
- The scalar deleting destructor wrapper at `0x005795a0-0x005796c7` is selected by Socket vtable slot `0x00624f20` and physically lies inside the mixed [UID:000245][0x00578f70-0x005797ae.StlTreeStringMapSupport](by-memory/0x00578f70-0x005797ae.StlTreeStringMapSupport.md) tail. Route the source semantics through `Socket::~Socket()` and compiler-generated destructor glue; do not model that body as STL tree support.
- The removed `simroot_v2/class_Socket.cpp` companion historically emitted `WAVE3 OMITTED METHOD BODY` markers before [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md) and [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md), even though bodies followed those markers. That snapshot is dated provenance only; current validator-owned `NexusTK/network/Socket.cpp/.h` is the generated-source authority and contains the accepted bodies and `XorTransformBuffer` contract.

## File Split

Keep these nearby functions out of `Socket.cpp` unless later evidence proves otherwise:

- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md): scalar read/write/append helpers in the `0x00575380-0x00575abb` cluster. These are C-style packet utilities with hundreds of callers and no `Socket` instance dependency.
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md): handshake/nonce table builders and the shared XOR primitive used by Socket's encode/decode methods.
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md): cash-shop/download-specific payload helpers. The broad packet builders that call [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) should stay in their feature modules, but the queue-send wrapper itself is now documented as [UID:0000DD][Socket](by-class/Socket.md) because `g_packetSender` lifetime is Socket-owned and `Socket::HandleSocketCommand` case `8` consumes the queued payload. The companion queue primitive `0x00596960` remains [UID:0000OR][Thread](by-file/Thread.md) infrastructure.
- Feature packet builders such as clan, mail, board, map, item, and chat senders stay in their established feature compilation units. Exhaustive UID0000MV research found no central `ProtocolSend.cpp` source unit, so this is a final split decision rather than a deferred central-file proposal.

## Evidence

- Wave3 reports `Socket` as the only class attached to `class_Socket.cpp`, with 26 included methods and owner file `class_Socket.cpp`.
- IDA MCP confirms key Socket function boundaries: constructor `0x005747e0-0x005749d9`, destructor `0x005749e0-0x00574ad8`, `SendEncodedPacket` `0x00576660-0x00576c75`, and `BuildEncryptedPacket` `0x00578c40-0x00578df1`. The transport setup path calls the inherited Thread wait-handle helper at `0x005967d0-0x005967e5`, but current IDA evidence places that helper with [UID:0000OR][Thread](by-file/Thread.md).
- B006 2026-06-20 route scan found no direct rel32 refs to raw starts `0x00574d00`, `0x00576570`, or `0x00577610`. It found one direct rel32 tail jump to `0x005794c0` at `0x0060805e`, matching Socket constructor EH/unwind cleanup, and exactly two direct calls to `Thread::AddWaitHandle` at `0x005764cc` and raw `0x0057773f`, both Socket transport setup routes into Thread infrastructure.
- B003 2026-06-20 Thread dispatch-helper research adds the paired cleanup route: Socket `CloseTransport` tail-jumps at `0x00577aef` to inherited `Thread::RemoveLastWaitHandle()` at `0x005967f0` after closing/clearing the serial handle. This is Socket caller evidence only.
- B008 2026-08-01 ThreadProc support reanalysis corrects the Socket vtable declarations: cell `0x00624f34 -> 0x00575d90` occupies inherited Thread slot `+0x14` and is `Socket::OnStart`; cell `0x00624f48 -> 0x00575da0` occupies inherited slot `+0x28` and is `Socket::OnIdle`. `Thread::StartThread` calls the first before resuming the worker, while `ThreadProc` calls the second after every non-stopping wait iteration. The nonblocking receive body explains the old `PollAndReceive` alias but does not create a separate virtual contract.
- Wave3 and IDA both report three direct code refs to `SendEncodedPacket` from the destructor/scalar destructor and command dispatcher.
- 2026-06-11 live IDA MCP decompilation of `Socket::HandleSocketCommand` at `0x00575e60` confirms command IDs posted by the nearby helper cluster: cases `3`, `4`, `5`, `6`, `8`, `13`, and `14` consume the queued work. This attaches [UID:000242][0x00574ae0-0x00574b83.SocketEventDispatchHelpers](by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md) and [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) to [UID:0000DD][Socket](by-class/Socket.md); B003's 2026-06-17 recheck also assigns [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md) to Socket by best-defensible command-consumer/source-structure evidence while preserving the no-caller/table-ref caveat for its raw start.
- B001 2026-06-25 command-12 correction resolves `0x00574b30` as `Socket::PostConnectionStatusQuery(bool *outConnected)`: MCP `1005` shows the wrapper posts command `0x0c` through `Thread::DispatchRequestAndReturnEvent`; MCP `1006` shows `Socket::QueryTransportState` at `0x00576200` is the vtable consumer that writes true for mode `6` or a valid socket handle; MCP `1007` confirms command `12` is not an async `HandleSocketCommand` case; and MCP `1010-1015` show UI/login/timer/network callers use the boolean as a reusable connection/transport availability result. The source file should expose the posted-query wrapper while preserving `QueryTransportState` as the internal sync consumer.
- B006 refines command `14`: the raw helper at `0x00574d00` copies exactly caller-provided bytes and posts command `14`, but the dispatcher calls the handshake/seed block builder rather than directly writing the bytes to a transport. Prefer `Socket::QueueHandshakeBlock` or `Socket::QueuePacketTransformSeedBlock`; reject `SendRawData` as a final source name.
- IDA MCP `py_eval` on 2026-05-25 reports 489 xrefs and five direct writes to `0x0067a7ec`; the writer set is entirely the Socket constructor/destructor family, including [UID:0001I6][0x005794c0-0x005794cb.ClearPacketSenderGlobal](by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md) and scalar deleting destructor `0x005795a0`.
- The constructor seeds the handshake/key path, allocates packet buffers, initializes receive/frame state, sets `g_packetSender`, and optionally dispatches mode-6 startup messages.
- `HandleSocketCommand` maps queued request codes into transport initialization, reconnect/reset, receive dispatch, encoded sends, raw text sends, single-byte sends, transform table initialization, and handshake-block setup.
- `SendEncodedPacket` is the final outbound packet encoder: it chooses pass-through or encrypted opcode paths, builds binary `0xaa` frames or text line frames, and writes to Winsock, mode-6 callback dispatch, or serial `WriteFile`.
- Raw serial open [UID:0003A7][0x00577610-0x0057779e.SocketOpenSerialTransportRaw](by-memory/0x00577610-0x0057779e.SocketOpenSerialTransportRaw.md) formats a narrow `"COM%d"` string and calls an indirect CreateFile-like pointer. Document this as likely ANSI/indirect CreateFile-style behavior; do not claim proven `CreateFileW`.
- Raw reconnect [UID:0003A6][0x00576570-0x00576623.SocketReconnectEndpointRaw](by-memory/0x00576570-0x00576623.SocketReconnectEndpointRaw.md) has no direct callers or real pointer refs. Apparent dword-byte hits at `0x0066bce3` and `0x0066be08` are rejected as unaligned bytes inside import-name strings ending in `...TypeW`.

## Proposed Placement

```text
network/
  Socket.h
  Socket.cpp
```

Expected dependencies include `Thread`, `Application`/window access, configuration, memory allocation helpers, Winsock, Win32 serial APIs, and [UID:0000M9][PacketTransform](by-file/PacketTransform.md) helpers/tables. Feature packet construction should depend on this module through the recovered `QueueAndSendPacket`/request-send API or direct transport sends, not own the socket implementation.

## Score Rationale

- Completion `94`: the Socket source root, complete command/packet corridor, lifecycle/transport/receive/transform families, exact H/CPP dependency surface, `0x3aa54` layout, packet-transform/packet-buffer/Thread/feature splits, packet-sender ownership, and generated route are closed.
- Confidence `95`: IDA-backed ownership, exact offsets, vtable cells, command consumers, child formal source, and dependency declarations agree. Remaining uncertainty is limited to original folder spelling and a few inferred private field names.

## Open Questions

- Whether the original folder was named `network`, `net`, or a flatter top-level source file group.
- Treat [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) as high-probability `Socket *` source-facing storage owned by `network/Socket.cpp`; keep only a later-header caveat that a source typedef or narrow sender interface could wrap that pointer if future evidence finds one.
- Mode `6` is now bounded to callback/window-message dispatch using configured message ids; the exact original source-facing purpose/name, such as launcher/proxy versus another legacy dispatch channel, remains open.
- Packet transform free helpers/globals are assigned to separate `PacketTransform.cpp/.h`; Socket owns only stateful member consumers.

## Cross-References

- [UID:0000DD][Socket](by-class/Socket.md)
- [UID:0001HS][0x005747e0-0x00574ad8.SocketLifecycle](by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md)
- [UID:000242][0x00574ae0-0x00574b83.SocketEventDispatchHelpers](by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md)
- [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md)
- [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md)
- [UID:0001I1][0x00575d90-0x005797ae.SocketTransportCore](by-memory/0x00575d90-0x005797ae.SocketTransportCore.md)
- [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md)
- [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md)
- [UID:0001I6][0x005794c0-0x005794cb.ClearPacketSenderGlobal](by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md)
- [UID:0001JZ][0x005967d0-0x005967e5.ThreadAddWaitHandleHelper](by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md)
- [UID:0000M9][PacketTransform](by-file/PacketTransform.md)
- [UID:0000V3][PacketTransformHelpers](by-item/PacketTransformHelpers.md)
- [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md)
- [UID:0001HZ][0x00575380-0x00575abb.PacketBufferHelpers](by-memory/0x00575380-0x00575abb.PacketBufferHelpers.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [UID:0000OR][Thread](by-file/Thread.md)
- [UID:00001H][CashShopRequest](by-class/CashShopRequest.md)
- [UID:0001QH][client_network](by-meta/client_network.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## 2026-08-17 B003 UID0000MV Accepted Callback

- Raised `90/91` to `94/95`, established the exact eighteen-definition command/packet corridor, and closed the remaining lifecycle/transport/support inventory at whole-file depth.
- `Socket.cpp/.h` remain the sole central sender/transport root. ProtocolSend is a reviewed negative source-unit candidate, not a future catch-all file; feature builders stay with their feature owners.
- Socket consumes the new PacketTransform declaration surface and exact Config friend/jitter fields. Thread, PacketBuffer, PacketTransform definitions, feature modules, and CashShopRequest remain separate owners.

## Changes

- 2026-08-17 B003 UID0000MV accepted callback: completed whole-file source/topology/header closure and final ProtocolSend exclusion.

- 2026-08-01 B008 accepted ThreadProc support incorporation:
  - Changed confidence from `89` to `91` while retaining completion `90` and the `NexusTK/network/Socket.cpp` route.
  - Recorded `0x00575d90` as `Socket::OnStart()` and `0x00575da0` as `Socket::OnIdle()` in inherited Thread slots `+0x14` and `+0x28`; preserved `NoOpVirtualHook` and `PollAndReceive` only as historical/behavior aliases.
  - Corrected legacy Wave3/generated wording to historical provenance and synchronized the score rationale with current metadata. Ownership, source split, command map, raw-helper caveats, and packet-sender lifetime remain unchanged.
- 2026-06-25 B001 LegacyMainMenuPacket command-12 sync:
  - Score unchanged at `88/85`.
  - Summary/evidence: synchronized Socket command `0x0c` / `12` support docs with accepted source-facing `Socket::PostConnectionStatusQuery(bool *outConnected)`. Current MCP `1005-1015` proves the producer wrapper, Thread event/wait dependency, `Socket::QueryTransportState` vtable consumer at `0x00576200`, and reusable connection/transport availability semantics across call sites.

- 2026-06-20 B003 Thread dispatch helper support update:
  - Added the Socket `CloseTransport` tail-jump route to `Thread::RemoveLastWaitHandle()` at `0x00577aef` and clarified that both add/remove wait-handle helpers remain inherited [UID:0000OR][Thread](by-file/Thread.md) infrastructure.
- 2026-06-20 B006 Socket source-quality support:
  - Added the explicit Socket/Thread/PacketBuffer/PacketTransform/CashShopRequest source split, command-wrapper inventory, raw helper route-scan results, `QueueHandshakeBlock` naming for command `14`, and the narrow `COM%d` / CreateFile-like serial-open caveat.
  - Evidence: B006 report `0000DD-Socket-class-source-quality.md` checked Socket, Thread, PacketBuffer, PacketTransform, CashShopRequest, `g_packetSender`, memory children, generated output, exported function JSON, vtable metadata, and raw PE route scans.
- 2026-06-11 A003 Batch188 command-posting ownership refresh:
  - Before: the file page treated `QueueAndSendPacket` as a possible non-Socket request-interface boundary and did not list the `0x00574ae0-0x00574d3f` command-posting helper cluster as Socket-owned.
  - After: the page records [UID:000242][0x00574ae0-0x00574b83.SocketEventDispatchHelpers](by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md) and [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) as Socket-owned command-posting helpers, keeps [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md) as likely Socket semantics but unassigned because raw-start reachability is negative, and leaves the `0x00596960` queue primitive with [UID:0000OR][Thread](by-file/Thread.md).
  - Evidence: live IDA MCP decompiled `Socket::HandleSocketCommand` at `0x00575e60` and matched its command cases to the queue-posting wrappers; existing `g_packetSender` lifetime evidence remains Socket-owned.
- 2026-06-17 B003 Socket lifecycle source-quality pass:
  - Before: this file still treated [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md) as likely but unassigned Socket code and left `g_packetSender` type open between Socket/request-thread/CashShop aliases.
  - After: [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md) is documented as Socket-owned by best-defensible command-consumer/source-structure evidence with its negative raw-start reachability caveat preserved, and [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) is treated as high-probability `Socket *` source-facing storage.
  - Evidence: live IDA MCP reconfirmed Socket-only lifetime writes, command-consumer cases in `Socket::HandleSocketCommand`, real `g_pCashShopRequest` separation at `0x0067a738`, and destructor-family lifecycle coverage.
- 2026-06-18 B003 ClearPacketSenderGlobal source-quality pass:
  - Before: this file listed the clear helper only as broad Socket lifetime evidence.
  - After: [UID:0001I6][0x005794c0-0x005794cb.ClearPacketSenderGlobal](by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md) is documented as Socket constructor-unwind cleanup evidence only, not a source-facing helper API, and the no-formal-C++ policy is tied to the one EH tail-jump route and zero pointer/table refs.
  - Evidence: B003 raw PE/Capstone recheck found exact target bytes, one rel32 route at `0x0060805e`, no target pointer hits, no callees, and the five Socket-family `g_packetSender` writes.
- 2026-06-11 A002 Batch190 raw transport split:
  - Added [UID:0003A6][0x00576570-0x00576623.SocketReconnectEndpointRaw](by-memory/0x00576570-0x00576623.SocketReconnectEndpointRaw.md) and [UID:0003A7][0x00577610-0x0057779e.SocketOpenSerialTransportRaw](by-memory/0x00577610-0x0057779e.SocketOpenSerialTransportRaw.md) as exact Socket-owned raw children under the broad transport aggregate.
  - Evidence: live IDA MCP reports no modeled functions/xrefs at these starts, but raw disassembly shows coherent reconnect and serial-open transport bodies bounded by alignment and touching Socket transport fields.
- 2026-06-02 `0x005967d0` source-owner correction.
  - Before: `Socket.md` listed [UID:0001JZ][0x005967d0-0x005967e5.ThreadAddWaitHandleHelper](by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md) under its stale `SocketThreadEvent`/`QueueThreadEvent` interpretation as a main Socket address doc.
  - After: the page treats that range as called inherited [UID:0000OR][Thread](by-file/Thread.md) infrastructure and keeps it only as transport-setup caller context.
  - Evidence: the child memory page now records IDA MCP lookup/decompile/disassembly/caller/callee/xref/raw-byte evidence showing the helper mutates base `Thread` wait-handle fields only.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `88` and confidence to `82`.
  - Evidence: document covers transport hypothesis, source contents, file split exclusions, IDA/Wave3 evidence, packet sender ownership, proposed placement, open questions, and network cross-references; confidence is capped by exact original folder name and unresolved packet-transform/source split boundaries.
- 2026-05-31: Projected reconstruction path changed from blank to `NexusTK/network/`.
  - Before: validator reported the by-file root as missing `PROPOSED_RECONSTRUCTION_PATH`.
  - After: the page stages as `auto-generated/NexusTK/network/Socket.cpp`.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `network/Socket.cpp`, and this page's placement hypothesis uses `network/Socket.cpp` for the stateful transport class and `g_packetSender` lifetime.
- 2026-06-10 A001 strict gate repair:
  - Changed confidence from `82` to `85`.
  - Summary/evidence: the page already documents a coherent Socket source root with constructor/destructor, transport setup, receive/send, transform, `g_packetSender` lifetime, projected path, and explicit file-split exclusions. This clears the direct-parent side of the corrected `85/85` gate for Socket-owned children while keeping final C++ blocked by field names, exact sender interface type, and packet-transform source split questions.
