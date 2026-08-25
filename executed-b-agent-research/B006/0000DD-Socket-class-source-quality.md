** TARGET-REPORT-UID:0000DD **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0000DD] Socket class source-quality report

Status: FINISHED report-only research pass.

Target: `E:\NTK\GhidraBridge\source-3\project-documentation\by-class\Socket.md`  
Required report: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B006\research\0000DD-Socket-class-source-quality.md`

Rules followed: `tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, `Agent-B006/goal.md`, and the Implementation Callback Detail Contract. No by-* documentation or `by-memory/-coverage-report.md` was edited.

## Recommendation summary

- Keep canonical owner/emitter unchanged: [UID:0000NS] `by-file/Socket.md`.
- Keep `RECONSTRUCTABLE:TRUE`.
- Raise target score from `COMPLETION:86`, `CONFIDENCE:85` to `COMPLETION:88`, `CONFIDENCE:88` after incorporating the findings below.
- Add a limited source-style Socket class declaration to the target formal C++ block. Do not encode a synthetic full offset layout yet; keep exact offset fields in prose until a layout-specific implementation pass validates them.
- Keep raw no-direct-caller helpers documented as Socket-owned source-shaped helpers, but do not emit standalone first-draft bodies for them yet.
- No `by-memory/-coverage-report.md` replacement row is required for this by-class target.

## Evidence checked

- Read target `by-class/Socket.md`, support `by-file/Socket.md`, `by-file/Thread.md`, `by-class/Thread.md`, `by-file/PacketBuffer.md`, `by-file/PacketTransform.md`, `by-file/CashShopRequest.md`, `by-class/CashShopRequest.md`, `by-global/g_packetSender.md`, and the memory-global page for `g_packetSender`.
- Read Socket child/support docs: `SocketLifecycle`, `SocketEventDispatchHelpers`, `QueueAndSendPacket`, `SendRawDataRaw`, `CashShopRequestSendQueue`, `SendPositionUpdate`, `BuildAndSendFriendNameListSync`, `GetConnectionStatus`, `SocketReconnectEndpointRaw`, `SocketOpenSerialTransportRaw`, `SocketTransportCore`, `SocketTransformFramePayload`, `SocketBuildEncryptedPacket`, `ClearPacketSenderGlobal`, `SocketReadOnlyData`, and `SocketConnectionStringParsePointers`.
- Checked generated output in `source-3/project-documentation/auto-generated/NexusTK/network/Socket.cpp`, `source-3/simroot_v2/class_Socket.cpp`, and `source-3/simroot_v2/class_CashShopRequest.cpp`.
- Checked exported function JSON for `0x005747e0`, `0x00574d00`, `0x00575e60`, `0x00576570`, `0x00577140`, `0x00577610`, `0x00577a80`, and vtable metadata in `resources/exported_data/master_vtables.json`.
- Performed raw PE route scan against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
  - Direct rel32 refs to `0x00574d00`, `0x00576570`, and `0x00577610`: none.
  - Direct rel32 refs to `0x005794c0`: one tail jump at `0x0060805e`, matching Socket constructor EH/unwind cleanup.
  - Direct rel32 refs to `0x005967d0`: two calls at `0x005764cc` and `0x0057773f`, both Socket transport setup routes into Thread wait-handle support.
  - Dword hits for `0x0067a7ec` (`g_packetSender`): 489 VA hits.
  - Dword hits for `0x00624f20` Socket vtable: `0x00574841`, `0x00574a13`, and `0x005795da`.
  - Apparent dword-byte hits for `0x00576570` at `0x0066bce3` and `0x0066be08` are rejected as pointer evidence: both are unaligned bytes inside import-name strings ending in `...TypeW` (`GetStringTypeW`, `GetDriveTypeW`), byte pattern `70 65 57 00`.

## Ownership and source route

`Socket` remains the only defensible source owner for the class, vtable, transport methods, outbound queue helpers, and frame/parser transform methods. [UID:0000NS] `Socket.cpp` remains the emitter. `Thread` owns the message queue, semaphore, wait-handle array, worker dispatch, and queue-post primitive at `0x00596960`; Socket merely calls those support methods.

The old `CashShopRequest::*` route is alias pollution from generated class recovery. It is rejected for all Socket send-corridor helpers because:

- the live global at `0x0067a7ec` is Socket-published and cleared by Socket lifecycle/scalar destructor paths;
- the true nearby stale `g_pCashShopRequest` address is not this global and is currently resolved as `FileDownloader *g_pFileDownloader`;
- `HandleSocketCommand` consumes the queued command IDs inside Socket virtual dispatch;
- direct callers across feature modules use the global sender as a process-level Socket transport, not as a CashShopRequest instance.

## Class and vtable shape

Socket vtable range is `0x00624f20-0x00624f58`, from `SocketReadOnlyData`.

High-confidence vtable slots:

| Slot | RVA | Best role |
|---|---:|---|
| 0 | `0x005795a0` | Socket scalar deleting destructor |
| 1 | `0x004f4b10` | inherited/common object descriptor helper |
| 2 | `0x0041b6c0` | `nullsub_18`, no-op `retn 8` |
| 3 | `0x00596540` | Thread shutdown/wait helper |
| 4 | `0x005965c0` | Thread terminate helper |
| 5 | `0x00575d90` | `Socket::NoOpVirtualHook` |
| 6 | `0x0041b6a0` | guard/check no-op |
| 7 | `0x00596810` | inherited `ThreadProc` |
| 8 | `0x0041b6a0` | guard/check no-op |
| 9 | `0x0041b6a0` | guard/check no-op |
| 10 | `0x00575da0` | `Socket::PollAndReceive` |
| 11 | `0x00575e60` | `Socket::HandleSocketCommand` |
| 12 | `0x00576200` | `Socket::QueryTransportState` |
| 13 | `0x00576250` | `Socket::HandleReceiveEvent` |

The class declaration should show Socket inheriting from `Thread`. The inherited Thread slots should not be re-owned by Socket support docs.

## Field and type recommendations

Recommended high-probability Socket field names:

| Offset | Recommended name | Evidence and notes |
|---:|---|---|
| `+0x68` | `m_activeReadBuffer` | primary pointer passed to overlapped/serial `ReadFile`; constructor allocates the backing buffer family. |
| `+0x6c` | `m_alternateReadBuffer` | paired read buffer pointer. |
| `+0x70` | `m_receiveBufferPrimary` | 60000-byte receive buffer allocation. |
| `+0xead0` | `m_receiveBufferAlternate` | second 60000-byte allocation. |
| `+0x1d530` | `m_receiveByteCount` | reset by reconnect path with other receive counters. |
| `+0x1d534` | `m_receiveCursor` | reset by reconnect path; paired with receive count. |
| `+0x1d53c` | `m_serialTransportHandle` | COM/alternate transport handle; opened by raw serial helper and closed by `CloseTransport`. |
| `+0x1d543` | `m_serialClosing` or `m_serialCancelPending` | cleared by `CloseTransport`; exact source name not safely recoverable. |
| `+0x1d544` | `m_serialReadActive` | set around overlapped read, cleared by `CloseTransport`. |
| `+0x1d54c` | `m_serialReadOverlapped` | `OVERLAPPED` block used by serial read path. |
| `+0x1d55c` | `m_serialReadEvent` | event handle added to Thread wait-handle array. |
| `+0x1d574` | `m_socketConnected` | boolean connection state for Winsock route. |
| `+0x1d578` | `m_socket` | Winsock socket handle, initialized to invalid and closed on teardown. |
| `+0x1d57d` | `m_frameBuffer` | 40000-byte frame scratch allocation. |
| `+0x271c0` | `m_frameByteCount` | reset by reconnect path. |
| `+0x271c4` | `m_frameCursor` | reset by reconnect path. |
| `+0x271c8` | `m_packetBuffer` | second 40000-byte packet/frame scratch allocation. |
| `+0x3aa48` | `m_transportMode` | mode byte: mode 5 is Winsock/TCP, mode 6 is callback/window-message dispatch, lower modes are COM/serial. |
| `+0x3aa49`..`+0x3aa4b` | `m_frameState` bytes | reset by reconnect and initialized as part of a dword with `+0x3aa4c`; keep prose-only until parser state names are validated. |
| `+0x3aa4c` | `m_protocolModeFlag` | command 9 writes this byte; `SendEncodedPacket` branches on binary/text packet framing. |
| `+0x3aa4d` | `m_connectionFlag` | setter child writes this byte. |
| `+0x3aa4e` | `m_sendDisabled` | checked by queue/send helpers; setter child writes this byte. |
| `+0x3aa4f` | `m_connectionStatus` | returned by `GetConnectionStatus`; callers compare it for UI/gate logic. |
| `+0x3aa50` | `m_connectionRetryDelay` or `m_mode5TriggerCount` | constructor initializes to `10`; exact source name remains weaker than adjacent fields. |

Rejected field alternatives:

- `m_connectionState` for `+0x3aa48` is too broad; the byte selects transport mode, not merely connected/disconnected state.
- `m_isConnected` for `+0x3aa4d` is rejected because `+0x1d574` already acts as the Winsock connected boolean and `+0x3aa4d` is written by the explicit connection-flag setter.
- `m_sendPacketFlag` for `+0x3aa4e` is rejected; direct send helpers test it as a disable flag, so `m_sendDisabled` is the better source-facing name.

## Command IDs and helper names

Socket command IDs consumed by `Socket::HandleSocketCommand`:

| Command | Producer/helper | Consumer behavior | Recommendation |
|---:|---|---|---|
| `3` | `0x00574b00` | `InitializeTransport(..., false)` route | `Socket::PostConnectCommand` |
| `4` | `0x00574ae0` | `InitializeTransport(..., true)` route | `Socket::PostConnectWithFallbackCommand` |
| `5` | `0x00574b20` | reset/close connection state | `Socket::PostResetConnectionCommand` |
| `6` | `0x00574b50` | reset and call endpoint connect path | `Socket::PostReconnectEndpointCommand` |
| `7` | `0x00574b90` | receive dispatch path | `Socket::PostReceiveCommand` |
| `8` | `0x00574bb0` and packet-building callers | send encoded packet, then free queued copy | `Socket::QueueAndSendPacket` |
| `9` | `0x00574c20` | write `m_protocolModeFlag` | `Socket::PostProtocolModeCommand` |
| `10` | `0x00574c40` | send queued C string via `SendPacket`, then free | `Socket::QueueTransportStringCommand` |
| `11` | `0x00574cb0` | send one byte through active transport | `Socket::SendSingleByteCommand` |
| `12` | `0x00574b30` | event-backed Thread request helper | keep as event-backed Socket command; exact final name lower-confidence |
| `13` | raw `0x00574b70` | transform/LUT setup command | `Socket::PostPacketTransformTableCommand`; no direct callers found |
| `14` | raw `0x00574d00` | calls handshake/seed block builder with queued bytes | prefer `Socket::QueueHandshakeBlock` over `SendRawData` |

`QueueAndSendPacket` source signature should be:

```cpp
void Socket::QueueAndSendPacket(const void *packetData, short packetSize);
```

It checks `m_sendDisabled`, allocates `packetSize + 1`, copies exactly `packetSize`, writes a zero terminator, and posts command `8` through Thread queue helper `0x00596960`. The terminator is scratch/convenience and not part of the queued binary length.

The raw helper currently named `SendRawDataRaw` should be reframed. The body copies exactly `size` bytes with no terminator and posts command `14`, but the consumer calls the packet handshake/seed builder (`BuildHandshakeBlock`) rather than writing those bytes directly to the socket/serial transport. Best source-facing name is `QueueHandshakeBlock`; second-best is `QueuePacketTransformSeedBlock`. `SendRawData` is rejected as a final source name because it incorrectly implies a direct transport write.

## Raw helper liveness

Raw helper direct-route results:

- `0x00574d00-0x00574d3f`: no IDA function, no direct calls, no pointer refs, no rel32 routes in PE scan. Source-shaped body posts command `14`. Keep documented under Socket as retained/legacy handshake-block queue helper, but do not emit a body until a source route or accepted retained-support policy is found.
- `0x00576570-0x00576623`: no direct calls and no real pointer refs. The only byte-pattern hits are rejected as unaligned import-name string bytes. Behavior is reset-and-reconnect endpoint: disables async select, closes socket, clears transport/counters/frame state, resets `g_packetSequenceByte`, calls `ConnectEndpoint`, and sleeps 1000 ms. Keep as `Socket::ReconnectEndpoint` source-shaped raw helper, no first-draft body yet.
- `0x00577610-0x0057779e`: no direct calls and no pointer refs. Behavior is COM/serial open and prime: closes old handle, formats `COM%d`, calls a CreateFile-like pointer, configures comm state/timeouts, creates event, calls `Thread::AddWaitHandle`, and starts overlapped `ReadFile`. The string formatting is narrow, so support docs should say likely `CreateFileA` or indirect CreateFile-like pointer, not confidently `CreateFileW`.

## g_packetSender and stale aliases

Recommended type: `Socket *g_packetSender`.

Evidence:

- `Socket` constructor publishes `this` to `0x0067a7ec`.
- constructor fallback, destructor, scalar deleting destructor, and EH cleanup clear the same global.
- PE/data scan finds 489 references to `0x0067a7ec`.
- no non-Socket owner writes were found.

Rejected alternatives:

- `CashShopRequest *g_packetSender`: generated/OOAnalyzer alias only; contradicted by Socket lifecycle ownership and command consumer.
- `Thread *g_packetSender`: too broad; callers use Socket command semantics, and Socket-specific destructor/global lifecycle controls the pointer.
- `void *g_packetSender`: acceptable as a decompiler fallback only; support docs should use `Socket *`.
- sender interface abstraction: possible in original project style but not evidenced by binary ownership, vtable, or call sites.

## Thread dependency boundary

`0x00596960` and `0x00596a00` are Thread queue/event helpers. Socket helpers should be documented as posting Socket command records through Thread, not as owning the queue implementation.

`0x005967d0` is `Thread::AddWaitHandle`, not Socket. The PE scan confirms two Socket callers (`0x005764cc`, `0x0057773f`) and no pointer refs. The serial helper supplies the event handle; Thread owns the wait-handle array append and wait-count increment.

`CloseTransport` inlines/removes a wait-handle slot with Thread layout knowledge, but this still belongs to Socket transport cleanup calling into Thread-owned infrastructure, not a separate source class.

## Packet encoding and transform split

Socket owns the stateful packet encode/decode methods:

- `Socket::SendEncodedPacket`
- `Socket::SendPacket`
- `Socket::ProcessQueuedReceiveBlock`
- `Socket::ProcessIncomingTransportData`
- `Socket::ReceiveNetworkData`
- `Socket::ParseFramePayload`
- `Socket::TransformFramePayload`
- `Socket::BuildEncryptedPacket`

PacketBuffer owns scalar cursor and big-endian helpers. PacketTransform owns the free transform helpers and globals:

- `BuildHandshakeBlock`
- string key helpers
- `InitializePacketNonce`
- `XorTransformBuffer`
- `g_packetTransformLut`
- `g_handshakeSeedBytes`
- `g_packetNonceScratch`
- `g_processArgList`
- `g_packetTransformStride`
- `g_packetSequenceByte`
- `g_packetXorTablePrimary`
- `g_packetXorTableAlternate`

Binary packet mode writes prefix `0xaa`, two-byte big-endian length, then payload after optional transform/encryption. Text packet mode writes `*`/`+` records with sequence digits and comma/period continuation markers. This behavior belongs in Socket method prose; PacketTransform docs should retain only reusable transform state/helper behavior.

## First-draft C++ recommendation

Add a limited declaration, not full implementation bodies, to `by-class/Socket.md`. This satisfies the reconstructable class-level target without inventing an unverified complete ABI layout. Suggested first-draft block:

```cpp
class Socket : public Thread {
public:
    Socket();
    virtual ~Socket();

    virtual void NoOpVirtualHook();
    virtual void PollAndReceive();
    virtual void HandleSocketCommand(int commandId, void *payload, unsigned long value);
    virtual int QueryTransportState(int query, unsigned char *outValue);
    virtual void HandleReceiveEvent(char eventCode);

    void QueueAndSendPacket(const void *packetData, short packetSize);
    void QueueTransportStringCommand(const char *text);
    void SendSingleByteCommand(unsigned char value);
    bool IsSocketConnectedState() const;
    void SetSocketSendDisabled(unsigned char disabled);
    void SetSocketConnectionFlag(unsigned char value);
    unsigned char GetConnectionStatus() const;

private:
    void InitializeTransport(char transportMode, void *endpointData, bool useFallback);
    void ResetConnectionState();
    void DispatchReceive();
    void SendEncodedPacket(const void *packetData, unsigned short packetSize);
    void SendPacket(const char *text);
    void ConnectEndpoint(unsigned long hostAddress, unsigned short port, bool useFallback);
    void CloseTransport();
    void ProcessQueuedReceiveBlock(void *block);
    void ProcessIncomingTransportData();
    void ReceiveNetworkData();
    void TransformFramePayload(const unsigned char *input, int inputLength, unsigned char *output, bool useAlternateKey);
    int BuildEncryptedPacket(const unsigned char *input, int inputLength, unsigned char *output, bool useAlternateKey);
};

extern Socket *g_packetSender;

[[CHILDREN]]
```

Do not include `QueueHandshakeBlock`, `ReconnectEndpoint`, or `OpenSerialTransport` in this first class declaration unless the supervisor accepts retained legacy/no-direct-caller helpers for code emission. Keep those raw helpers in prose and support docs for now.

## Exact recommended documentation changes

### `by-class/Socket.md`

- Update metadata to `COMPLETION:88`, `CONFIDENCE:88`; owner/emitter unchanged.
- Replace passive open questions about field naming with the field table above.
- Add the vtable slot table above.
- Add the command ID table above.
- State `g_packetSender` type as `Socket *` and reject `CashShopRequest *`, `Thread *`, and `void *` except as stale/decompiler aliases.
- Replace generic raw-helper uncertainty with the explicit no-direct-route evidence and the rejected unaligned `.rdata` byte-pattern hits.
- Add the first-draft C++ declaration block above.
- Keep raw helper C++ bodies blank until accepted retained-support policy or new route evidence.

### `by-file/Socket.md`

- Add source split: Socket owns class/lifecycle/transport/command framing; Thread owns queue and wait-handle primitives; PacketBuffer owns scalar cursor helpers; PacketTransform owns free transform helpers/globals.
- Add the command ID table and field-name recommendations or link back to the class doc after implementation.
- Clarify that raw serial helper uses a narrow `COM%d` formatted string and a CreateFile-like indirect pointer, likely `CreateFileA`; do not state `CreateFileW` as proven.
- Record PE route scan results for raw helper liveness.

### `SocketLifecycle`

- Add/adjust field names: `m_transportMode`, `m_protocolModeFlag`, `m_connectionFlag`, `m_sendDisabled`, `m_connectionStatus`, `m_socket`, `m_socketConnected`, `m_serialTransportHandle`, `m_serialReadEvent`, `m_serialReadOverlapped`.
- Keep full offset layout prose-only until a layout-specific pass validates exact struct packing.

### `SocketEventDispatchHelpers`

- Add source-facing names for command IDs 3, 4, 5, 6, 12, and 13.
- State that command `13` raw wrapper has no direct callers and should not be emitted yet unless retained support is accepted.

### `QueueAndSendPacket`

- Use signature `void Socket::QueueAndSendPacket(const void *packetData, short packetSize)`.
- Rename field references to `m_sendDisabled`.
- State that command `8` is consumed by `Socket::HandleSocketCommand` and then the queued copy is freed.

### `SendRawDataRaw`

- Rename source-facing role in prose from direct raw send to `QueueHandshakeBlock` or `QueuePacketTransformSeedBlock`.
- State command `14` calls handshake/seed block builder, not direct transport write.
- Keep no direct callers/pointer refs and no first-draft body unless accepted as retained legacy support.

### `SocketReconnectEndpointRaw`

- Add route scan: no direct rel32 refs, no pointer refs; rejected apparent hits at `0x0066bce3` and `0x0066be08` as unaligned import string bytes.
- Keep source-facing role `Socket::ReconnectEndpoint`.
- Keep C++ blank unless retained support/source route is accepted.

### `SocketOpenSerialTransportRaw`

- Add route scan: no direct rel32 refs and no pointer refs.
- Use source-facing role `Socket::OpenSerialTransport`.
- Replace confident `CreateFileW` language with likely ANSI/indirect CreateFile-like pointer because the helper formats narrow `COM%d`.
- Keep C++ blank unless retained support/source route is accepted.

### `SocketTransportCore`

- Keep non-emitting aggregate policy.
- Add the command ID table and owner split between Socket stateful methods and PacketTransform free helpers/globals.
- Note that `0x005967d0` is Thread-owned and only called by Socket.

### `ThreadAddWaitHandleHelper`, `ThreadMessageDispatchHelpers`, `by-file/Thread.md`

- Retain Thread ownership.
- Add Socket caller notes for `0x005764cc` and raw `0x0057773f`.
- Do not move these helpers into Socket.

### `by-global/g_packetSender.md` and memory-global page

- Keep or update best type to `Socket *g_packetSender`.
- Add rejected alias notes for `CashShopRequest *`, `Thread *`, `void *`, and speculative sender interface.
- Add five Socket-family writes: constructor publish, constructor fallback clear, destructor clear, EH cleanup clear, scalar deleting destructor clear.

### `by-file/CashShopRequest.md` and `by-class/CashShopRequest.md`

- Remove Socket send-corridor helpers from active CashShopRequest contents, or mark them as historical/generated search provenance only.
- State that `QueueAndSendPacket`, `SendPositionUpdate`, `BuildAndSendFriendNameListSync`, `GetConnectionStatus`, and adjacent command helpers are Socket-owned.
- State that real `g_pCashShopRequest`/nearby legacy alias confusion should not be used to type `g_packetSender`.

### `PacketTransform` and `PacketBuffer` docs

- No ownership move required.
- Add cross-reference that Socket stateful encode/decode methods call these helpers but remain Socket methods.

### `SocketReadOnlyData`

- Add the vtable slot names listed above if absent.
- Keep vtable/read-only data compiler-emitted/no standalone source declaration.

## IDA rename, type, and comment recommendations

High confidence:

- `dword_67A7EC` -> `g_packetSender`, type `Socket *`.
- `sub_574BB0` -> `Socket::QueueAndSendPacket`.
- `sub_574B90` -> `Socket::PostReceiveCommand`.
- `sub_574C20` -> `Socket::PostProtocolModeCommand`.
- `sub_574C40` -> `Socket::QueueTransportStringCommand`.
- `sub_574CB0` -> `Socket::SendSingleByteCommand`.
- `sub_574CD0` -> `Socket::IsSocketConnectedState`.
- `sub_574CE0` -> `Socket::SetSocketSendDisabled`.
- `sub_574CF0` -> `Socket::SetSocketConnectionFlag`.
- `sub_575E60` -> `Socket::HandleSocketCommand`.
- `sub_576200` -> `Socket::QueryTransportState`.
- `sub_576250` -> `Socket::HandleReceiveEvent`.
- `sub_576290` -> `Socket::InitializeTransport`.
- `sub_576530` -> `Socket::ResetConnectionState`.
- `sub_576660` -> `Socket::SendEncodedPacket`.
- `sub_576D90` -> `Socket::SendPacket`.
- `sub_577140` -> `Socket::ConnectEndpoint`.
- `sub_577A80` -> `Socket::CloseTransport`.
- `sub_5967D0` -> `Thread::AddWaitHandle`.

Medium confidence or raw/no-route:

- raw `0x00574d00` -> create/name only if retained helper modeling is accepted: `Socket::QueueHandshakeBlock`.
- raw `0x00576570` -> `Socket::ReconnectEndpoint`; add comment: no direct refs/pointers; apparent `.rdata` hits are import-string byte patterns.
- raw `0x00577610` -> `Socket::OpenSerialTransport`; add comment: no direct refs/pointers; narrow `COM%d` route, CreateFile-like indirect pointer.
- `0x00574b70` -> `Socket::PostPacketTransformTableCommand`; no direct callers found.

Do not rename Thread queue-post primitives as Socket methods.

## Implementation callback checklist

If the supervisor accepts this report:

1. Lease/update `by-class/Socket.md`.
2. Apply the metadata recommendation: `COMPLETION:88`, `CONFIDENCE:88`, owner/emitter unchanged.
3. Add the vtable slot table, field table, command ID table, raw-route evidence, rejected alternatives, and first-draft C++ declaration.
4. Lease/update support docs listed above. Preserve both positive evidence and negative route evidence.
5. Do not edit `by-memory/-coverage-report.md` for [UID:0000DD]; there is no by-memory coverage row for this by-class target.
6. If any memory child scores are changed during implementation, leave exact replacement rows in implementation notes for supervisor-owned coverage update rather than editing the coverage file directly.
7. Run validators on every edited doc and rerun if the validator applies formatting changes.

## Validation commands for implementation pass

Run after accepted implementation edits:

> Executable block R001 was removed from this report and preserved verbatim in [0000DD-Socket-class-source-quality-removed.md](0000DD-Socket-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Also validate each touched child page, especially `SocketLifecycle`, `SocketEventDispatchHelpers`, `QueueAndSendPacket`, `SendRawDataRaw`, `SocketReconnectEndpointRaw`, `SocketOpenSerialTransportRaw`, `SocketTransportCore`, `ThreadAddWaitHandleHelper`, `ThreadMessageDispatchHelpers`, `CashShopRequest`, `PacketTransform`, `PacketBuffer`, and `SocketReadOnlyData`.

## Exact pending coverage text

No `by-memory/-coverage-report.md` replacement row is required for [UID:0000DD] because the target is `by-class/Socket.md`, not a by-memory row. Do not edit `by-memory/-coverage-report.md` during this report-only pass or the later implementation pass unless the supervisor explicitly owns that update.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0000DD-Socket-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"0000DD"} -->
<!-- {"agent":"B006","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0000DD-Socket-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B006/0000DD-Socket-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0000DD"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
