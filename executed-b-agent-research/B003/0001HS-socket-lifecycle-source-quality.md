** TARGET-REPORT-UID:0001HS **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# [UID:0001HS] Socket Lifecycle Source-Quality Report

Assignment: `B003-goal2-socket-lifecycle-source-quality-0001HS-20260617`  
Target: [UID:0001HS] `by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md`  
Current target state: `82/88`, owner/emitter [UID:0000NS] `Socket`, `RECONSTRUCTABLE:TRUE`, formal C++ blank.

## Final Recommendation

Raise [UID:0001HS] to `88/91`, keep owner/emitter [UID:0000NS] `Socket`, keep `RECONSTRUCTABLE:TRUE`, and keep formal `RECONSTRUCTION_CPP` blank for now.

The target can clear the 85/85 source-quality gate. The prior blockers are now either resolved or narrowed enough not to cap completion below 85:

- Source-facing signatures: `Socket::Socket()` and `Socket::~Socket()` are the best defensible source signatures. Live IDA decompiles the constructor as `_DWORD *__thiscall sub_5747E0(_DWORD *this)` and the destructor as `int __thiscall sub_5749E0(int this)`, with no user parameters.
- `g_packetSender` type: source-facing declaration should be treated as high-probability `Socket *g_packetSender` owned in `network/Socket.cpp` or declared as `extern Socket *g_packetSender` from the network header. A later interface typedef is possible, but current binary evidence does not support `CashShopRequest *`.
- `UrkcnItni`: best classified as the fixed default packet-transform handshake seed passed to `BuildHandshakeBlock(9, seedBlock)`, not as a socket-mode marker, network packet payload, or serial/proxy token.
- `0x0069ba58` process/key pointer: best classified as packet-transform process/login key-material storage, not an ordinary receive buffer. Socket owns allocation/free; [UID:0000M9] `PacketTransform` owns helper semantics.
- Late Socket fields: high-probability source roles are now strong enough for documentation: `+0x1d578` Winsock socket handle, `+0x1d53c` serial/alternate transport handle, `+0x1d574` connected/active flag, `+0x3aa48` transport mode byte, `+0x3aa4e` send-disabled guard, `+0x68/+0x6c` pointers to the two 60000-byte buffers, and `+0x1d530/+0x1d534/+0x271c0/+0x271c4` buffer/frame counters.
- Queue/send pollution: [UID:0001HU] and surrounding command helpers are Socket command-posting methods over inherited [UID:0000OR] `Thread` queue infrastructure. Generated `CashShopRequest` naming is stale owner pollution for this corridor.
- Adjacent helper ownership: [UID:000242], [UID:0001HU], and [UID:0001HV] are Socket-owned or Socket-semantic helpers. They remain separate children and should not be merged into the lifecycle page.

The score should not go higher than `88/91` until a final Socket class layout/header pass gives source-quality member declarations, helper prototypes, and a policy for the scalar deleting destructor duplication.

## Evidence Checked

Live IDA MCP session `b003_00018a_ime_comp_20260617`:

- `analyze_component` for `0x005747e0`, `0x005749e0`, `0x00574ae0`, `0x00574b00`, `0x00574bb0`, `0x00574d00`, and `0x005794c0`.
- `decompile` and `disasm` for constructor `0x005747e0` and destructor `0x005749e0`.
- `decompile` for `Socket::HandleSocketCommand` at `0x00575e60`.
- `decompile` for transport initialization `0x00576290`, base `Thread` constructor/destructor `0x00596250`/`0x00596400`, and scalar deleting destructor `0x005795a0`.
- `xrefs_to` for `0x005747e0`, `0x005749e0`, `0x005794c0`, `0x00624f20`, and `0x005795a0`.
- `lookup_funcs` for lifecycle endpoints `0x005747e0`, `0x005749d9`, `0x005749e0`, `0x00574ad8`, and `0x00574ae0`.

Documentation reviewed:

- Primary [UID:0001HS].
- [UID:0000DD] `Socket`, [UID:0000NS] `Socket`, [UID:0000Q5] `g_packetSender`, [UID:0001P0] exact `g_packetSender` storage.
- [UID:000242], [UID:0001HU], [UID:0001HV], [UID:0001I1], [UID:0001I3], [UID:0001I4], [UID:0001I6].
- [UID:0000OR] `Thread`, [UID:0000M9] `PacketTransform`, [UID:0000M8] `PacketBuffer`, [UID:0001QH] `client_network`, and [UID:0000I0] `CashShopRequest`.
- Prior executed reports/notes: A003 Batch188, B001 `0001HT-CashShopRequestSendQueue`, A003 singleton/global updates for [UID:0001P0], and B001 shared-packet-literal reports using `QueueAndSendPacket` as a Socket send dependency. No prior completed B report was found for [UID:0001HS] itself.

## Heuristic / Inference Reanalysis And Validation

### Constructor and destructor names/signatures

Best inference:

- Constructor: `Socket::Socket()`.
- Destructor: `Socket::~Socket()`.

Evidence:

- `analyze_component` reports `sub_5747E0` as `_DWORD *__thiscall(_DWORD *this)`, size `505`, with string `UrkcnItni`.
- `decompile 0x005747e0` has only `this`; it constructs the base Thread, publishes `g_packetSender`, installs `Socket::vftable`, seeds packet transform state, initializes buffers/handles/mode fields, and optionally starts mode 6 dispatch.
- `lookup_funcs` confirms `0x005747e0` size `0x1f9`; `0x005749d9` is not a function.
- `xrefs_to 0x005747e0` reports one code xref at `0x0046466b` inside `sub_4639D0`, so the constructor is reachable.
- `decompile 0x005749e0` has only `this`; it restores the Socket vtable, closes the Winsock socket, closes alternate transport via `0x00577a80`, sends mode-6 teardown, frees the process/key buffer, clears `g_packetSender`, and destroys the Thread base.
- `xrefs_to 0x005749e0` reports no direct xrefs, but scalar deleting destructor `0x005795a0` is vtable-referenced through `0x00624f20` and duplicates the same teardown. This is a C++ destructor-family artifact, not evidence against the non-deleting destructor body.

Rejected alternatives:

- `Socket::Init(...)` / `Socket::Shutdown(...)`: rejected because IDA signatures have no user parameters and both methods install/restore vtables and run base ctor/dtor logic.
- A generated free function: rejected because the vtable stores, scalar deleting destructor, and Socket object field writes make this class lifecycle code.

Impact:

- Clears the signature blocker for [UID:0001HS].
- Supports a score raise above 85.
- Does not by itself justify formal C++ because final member declarations are still not source-quality.

### `g_packetSender` type and source placement

Best inference:

- Declare storage with Socket ownership, most likely `Socket *g_packetSender = nullptr;` in `network/Socket.cpp` and `extern Socket *g_packetSender;` in a network header.

Evidence:

- Constructor stores the enclosing `Socket *` into `dword_67A7EC` at `0x00574828`, with a compiler null-adjusted fallback clear at `0x0057482f`.
- Destructor clears it at `0x00574aaf`; unwind helper [UID:0001I6] clears it at `0x005794c0`; scalar deleting destructor clears it at `0x00579676`.
- [UID:0000Q5]/[UID:0001P0] record 489 xrefs and only those five Socket-family writes.
- [UID:0001HU] is now Socket-owned and its queued command `8` is consumed by `Socket::HandleSocketCommand`.
- Real `g_pCashShopRequest` storage is separate at `0x0067a738`.

Rejected alternatives:

- `CashShopRequest *g_packetSender`: rejected by address separation, write ownership, and Socket dispatcher ownership.
- `void *g_packetSender`: rejected as a generated type-loss artifact, useful only until headers are recovered.
- `Thread *g_packetSender`: plausible at the queue primitive boundary but too weak; `Thread` owns `0x00596960`, while Socket owns the helper methods and command consumers.
- Abstract `PacketSender *`: possible later source cleanup, but no vtable/interface/global lifetime evidence currently proves an original interface object.

Impact:

- The type question no longer caps [UID:0001HS] below 85 completion.
- Update [UID:0000Q5], [UID:0001P0], [UID:0000DD], [UID:0000NS], and [UID:0001QH] to state `Socket *` as the best current source-facing type, with only a later-interface caveat.

### Handshake literal and process/key buffer

Best inference:

- `UrkcnItni` is a fixed default packet-transform handshake seed.
- `0x0069ba58` is a pointer to 1025 bytes of process/login key-material text used by packet-transform helpers.

Evidence:

- Constructor allocates 9 bytes, copies `UrkcnItni`, and calls `BuildHandshakeBlock(9, block)` at `0x00574880`.
- [UID:0001I2] documents `BuildHandshakeBlock` as PacketTransform-owned, copying the seed into `g_handshakeSeedBytes`, writing `g_packetTransformStride`, and filling `g_packetXorTablePrimary`.
- Constructor allocates `0x401` bytes and writes the pointer to `0x0069ba58` (`g_processArgList`).
- [UID:000244] documents `PacketTransform_ExpandProcessArgKeyText` filling `g_processArgList` from login/process text, and [UID:0001I0] consumes that pointer for nonce/key setup.
- Destructor frees the pointer if non-null.

Rejected alternatives:

- Network packet payload: rejected because the literal is consumed by `BuildHandshakeBlock` and not passed to send/framing APIs.
- Socket transport-mode marker: rejected because mode setup is controlled by config byte `g_pConfig + 0x28de28` and `+0x3aa48`, not by this string.
- Serial/proxy token: rejected because serial/mode-6 setup uses separate Win32 handles/callback dispatch.
- Ordinary receive buffer: rejected because receive/frame buffers are the object-local 60000/40000 byte arrays, not the global pointer at `0x0069ba58`.

Impact:

- Resolve the handshake/process-key blockers for [UID:0001HS].
- Keep PacketTransform helper ownership separate; only allocation/free sequencing belongs to Socket lifecycle.

### Buffer, handle, mode, and counter fields

Best defensible names/roles:

| Offset | Best current role | Evidence |
| --- | --- | --- |
| `+0x68` | receive buffer A pointer | Constructor sets it to `this+0x70`; Thread queue code uses lower offsets before this. |
| `+0x6c` | receive buffer B pointer | Constructor sets it to `this+0xead0`. |
| `+0x70` | 60000-byte buffer A | Constructor zeroes `0xea60` bytes. |
| `+0xead0` | 60000-byte buffer B | Constructor zeroes `0xea60` bytes. |
| `+0x1d530/+0x1d534` | buffer A cursor/length counters | Zeroed in constructor and reset by command `6`. |
| `+0x1d53c` | serial/alternate transport handle | Initialized `-1`, checked by destructor, closed by `CloseTransport`; transport init writes Win32 handle here. |
| `+0x1d574` | connected/active flag | Cleared in constructor/destructor when socket closes. |
| `+0x1d578` | Winsock `SOCKET` | Initialized `-1`; destructor calls `closesocket` on this field. |
| `+0x1d57d` | 40000-byte frame/receive scratch A | Constructor zeroes `0x9c40` bytes. Exact source name not final. |
| `+0x271c0/+0x271c4` | frame/scratch counters | Zeroed in constructor and command `6` reset. |
| `+0x271c8` | 40000-byte frame/receive scratch B | Constructor zeroes `0x9c40` bytes. Exact source name not final. |
| `+0x3aa48` | active transport mode | Constructor writes `6` only on mode-6 config; transport init writes requested mode. |
| `+0x3aa4d` | connection/protocol state flag byte family | Constructor initializes covering word; `SetSocketConnectionFlag` writes it. |
| `+0x3aa4e` | send-disabled flag | `QueueAndSendPacket` checks this byte before allocating/copying. |
| `+0x3aa4f` | connection/status getter byte | `GetConnectionStatus` returns this byte. |
| `+0x3aa50` | retry/timeout count default | Constructor initializes to `10`; source name not final. |

Rejected alternatives:

- These are not CashShopRequest fields: receiver origin and constructor initialization are Socket-based.
- These are not Thread fields: Thread destructor accesses offsets such as `+12`, `+76`, `+80`, `+84`, `+88`, and `+92`; the large buffer/transport fields are above Socket's post-base object state.
- Do not assign final names like `m_receiveBuffer`/`m_frameBuffer` without a class-layout pass; use role names until the header is reconstructed.

Impact:

- Enough field roles are resolved to raise [UID:0001HS] above 85.
- Lack of exact source declarations still blocks formal C++ population.

### Transport modes

Best inference:

- Mode `5`: Winsock/TCP transport.
- Mode `6`: callback/window dispatch transport using configured callback target and message IDs.
- Modes below `5` except `5/6`: COM/serial transport through Win32 serial APIs.

Evidence:

- Constructor checks `*(byte *)(g_pConfig + 0x28de28) == 6`, writes `this+0x3aa48 = 6`, and posts callback messages `74`, `1052`, and `1985`.
- Destructor, when the same config byte is `6`, sends byte `100` through `SendEncodedPacket`, then posts callback messages `1053` and `1986`.
- `InitializeTransport` at `0x00576290` writes the mode byte to `+0x3aa48`. For `a2 == 5`, it selects a server/port from config and calls `ConnectEndpoint`. For `a2 != 6` and not `5`, it formats `COM%d`, opens the handle, configures comm state/timeouts, registers an event, and starts `ReadFile`.
- `HandleSocketCommand` case `11` sends one byte through `send` for mode `5`, callback dispatch for mode `6`, or `WriteFile` for the serial path.

Rejected alternatives:

- Mode `6` as serial/debug: rejected for mode `6` specifically because serial code is in the `a2 != 6 && a2 != 5` branch; mode `6` uses `unk_69BEC4` callback/message dispatch.
- Mode `5` as generic active socket only: rejected because initialization explicitly uses configured server/port and Winsock connect path.

Impact:

- Resolves mode/serial semantics enough for source-placement and score.
- Does not require merging PacketTransform or PacketBuffer into Socket lifecycle.

### Queue/send interface and generated owner pollution

Best inference:

- [UID:0001HU] `QueueAndSendPacket` is a Socket queue-send method over inherited Thread dispatch. Feature packet builders are consumers; `CashShopRequest` is stale generated-owner pollution for this helper.

Evidence:

- [UID:0001HU] has 416 direct code refs across 197 modeled caller functions, so it is a broad protocol-send funnel.
- Its receiver is the Socket-owned `g_packetSender` storage.
- It checks `this+0x3aa4e`, copies packet bytes, appends a zero, and posts command `8`.
- `Socket::HandleSocketCommand` case `8` calls `SendEncodedPacket` and frees the copied payload.
- [UID:0001HV] posts command `0x0e` and command case `14` calls `BuildHandshakeBlock`; raw-start reachability remains negative but semantic owner is Socket.
- B001 `0001HT` split report created/assigned exact children under Socket and rejected CashShopRequest/Thread as direct owners.

Rejected alternatives:

- CashShopRequest ownership: rejected by `g_packetSender` writes, real `g_pCashShopRequest` address, and Socket dispatcher consumer cases.
- Thread ownership: rejected as direct owner because `Thread` only provides the generic queue primitive.
- ProtocolSend new owner: rejected because no constructor/global/vtable/lifetime anchor exists for such a module.

Impact:

- Clears generated owner pollution as a blocker for [UID:0001HS].
- Support docs need stale wording cleanup but target score can move now.

### Range and split policy

Best inference:

- [UID:0001HS] should remain the exact constructor/destructor lifecycle page `0x005747e0-0x00574ad8`.
- Do not merge adjacent command helpers or later scalar deleting destructor into this page.
- No new split is required for the primary target.

Evidence:

- `lookup_funcs` confirms constructor `0x005747e0-0x005749d9`, destructor `0x005749e0-0x00574ad8`, and next function `0x00574ae0`.
- `0x00574ad8-0x00574ae0` is alignment before [UID:000242].
- [UID:0001I6] is a separate tiny unwind helper at `0x005794c0`.
- Scalar deleting destructor `0x005795a0` belongs in [UID:0001I1] transport aggregate/scalar destructor family.

Rejected alternatives:

- Merge [UID:000242] into lifecycle: rejected because those wrappers have separate command/caller semantics and are already Socket-owned children.
- Split constructor and destructor into separate pages: not necessary; the current page is a coherent source lifecycle cluster, exact boundaries are known, and both methods share the same Socket lifetime evidence.

Impact:

- Keep owner/emitter and range unchanged.
- No safe split exception needs to be used.

### Generated output and final C++ impact

Best inference:

- `auto-generated/NexusTK/network/Socket.cpp` is the correct route, but the formal block for [UID:0001HS] should remain blank.

Evidence:

- [UID:0000NS] has valid `NexusTK/network/` route and source-root evidence.
- Generated `class_Socket.cpp` has known omissions/prototype drift around transform helpers; docs mention `WAVE3 OMITTED METHOD BODY` marker/body mismatch for transform methods and `void *g_packetSender` type loss.
- Socket layout is a large object with base `Thread` fields, two 60000-byte buffers, two 40000-byte buffers, transport handles, global transform state, and mode/callback fields. A formal C++ block would need final field declarations and helper prototypes to avoid encoding misleading source names.
- Non-deleting destructor has no direct xrefs while scalar deleting destructor duplicates the body from vtable reachability; the final source should emit one C++ destructor and let compiler-generated deleting/unwind helpers be represented by source structure.

Rejected alternatives:

- Populate formal C++ with decompiler-style offsets: rejected because the target is now source-quality, and offset-heavy C++ would freeze non-final field names/types into generated source.
- Mark target non-emitting: rejected because constructor/destructor are source-authored Socket lifecycle methods, and the route to `network/Socket.cpp` is valid.

Impact:

- Score can be `88/91`; formal C++ remains blank with explicit reason.

## Recommended Target-Doc Changes

Supervisor should update [UID:0001HS] metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Replace the target `## Open Questions` section with:

```markdown
## Resolved Source-Quality Findings And Remaining C++ Hold

- Source-facing names/signatures are `Socket::Socket()` and `Socket::~Socket()`. Live IDA decompiles both as no-user-parameter `__thiscall` lifecycle methods, and the constructor has a direct code xref at `0x0046466b`.
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) is best typed as `Socket *` in current source-facing documentation. Socket constructor/destructor/unwind/scalar-deleting paths are the only observed writers; generated `CashShopRequest*` aliases are stale owner pollution, and the real `g_pCashShopRequest` storage is separate at `0x0067a738`.
- The constructor literal `UrkcnItni` is the fixed default PacketTransform handshake seed passed to [UID:0001I2][BuildHandshakeBlock](by-memory/0x00577030-0x0057713d.BuildHandshakeBlock.md), not a transport packet, serial token, or mode selector.
- The `0x0069ba58` allocation is PacketTransform process/login key-material storage. Socket owns allocation/free, while [UID:0000M9][PacketTransform](by-file/PacketTransform.md) owns helper semantics.
- High-probability field roles are: `+0x68/+0x6c` buffer pointers; `+0x70/+0xead0` two 60000-byte buffers; `+0x1d530/+0x1d534` and `+0x271c0/+0x271c4` buffer/frame counters; `+0x1d53c` serial/alternate transport handle; `+0x1d574` connected flag; `+0x1d578` Winsock socket handle; `+0x1d57d/+0x271c8` two 40000-byte frame/receive scratch buffers; `+0x3aa48` transport mode; `+0x3aa4d/+0x3aa4e/+0x3aa4f` connection/send/status byte family.
- Transport mode `5` is Winsock/TCP; mode `6` is callback/window-message dispatch using configured message ids; other low modes use COM/serial `CreateFileW`/comm API/overlapped `ReadFile` state.
- Formal C++ remains blank even though the score clears 85/85 because final class field declarations, helper prototypes, and scalar-deleting/unwind emission policy are still not source-final.
```

Append a `## Changes` entry:

```markdown
- 2026-06-17 B003 source-quality report: recommend raising completion/confidence from `82/88` to `88/91`, keeping owner/emitter [UID:0000NS][Socket](by-file/Socket.md), and keeping formal C++ blank.
  - Evidence: live IDA MCP reconfirmed constructor/destructor signatures and bounds, constructor xref at `0x0046466b`, destructor-family scalar deleting path through vtable slot `0x00624f20`, `g_packetSender` Socket-only write set, `UrkcnItni` handshake seed flow into `BuildHandshakeBlock`, `0x0069ba58` process/key allocation/free, transport-mode setup and teardown semantics, `Socket::HandleSocketCommand` cases, adjacent helper ownership, and exact range/padding.
  - Source-quality decision: prior open questions are resolved or narrowed to high-probability field/type roles; C++ is still held until the Socket header/layout and helper prototypes are final-source quality.
```

## Support Docs To Update

Support metadata recommendation: no support-doc score/header changes are required by this B003 pass. Keep [UID:0000NS] `88/85`, [UID:0000DD] `86/85`, [UID:0000Q5] `86/88`, [UID:0001P0] `86/89`, [UID:0000I0] `85/87`, and [UID:0001QH] `-1/-1`. The recommended support edits are wording/source-quality corrections; the by-memory coverage rows below align stale shared rows with current support-page scores and the new [UID:0001HS] target score.

### [UID:0000NS] `by-file/Socket.md`

Replace the sentence in `## Status` that currently says [UID:0001HV] remains unassigned with:

```markdown
[UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md) is assigned to the Socket class by best-defensible command-consumer/source-structure evidence, with its raw-start no-caller caveat preserved; [UID:0001JZ][0x005967d0-0x005967e5.ThreadAddWaitHandleHelper](by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md) is called inherited Thread infrastructure, not Socket-owned source.
```

Replace the `g_packetSender` open-question bullet with:

```markdown
- Treat [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) as high-probability `Socket *` source-facing storage owned by `network/Socket.cpp`; keep only a later-header caveat that a source typedef or narrow sender interface could wrap that pointer if future evidence finds one.
```

### [UID:0000DD] `by-class/Socket.md`

Replace the status/range wording that says [UID:0001HV] is "likely raw" or "unassigned" with:

```markdown
[UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md) is a Socket-owned raw command helper by best-defensible semantic evidence; no caller/table refs currently prove raw-start reachability, so its final C++ stays blank.
```

Replace the `g_packetSender` open-question bullet with:

```markdown
- Current source-facing type for [UID:0000Q5][g_packetSender](by-global/g_packetSender.md): best modeled as `Socket *` based on Socket-only lifetime writes and Socket command consumers. Generated `CashShopRequest*` references are stale aliases unless future header evidence proves an explicit sender interface.
```

### [UID:0000Q5] and [UID:0001P0] `g_packetSender`

Replace the "type unresolved" status wording with:

```markdown
Best current source-facing type: `Socket *`. Socket constructor/destructor/unwind/scalar-deleting paths are the only observed writers, [UID:0001HU][QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) and sibling command helpers are now Socket-owned, and `Socket::HandleSocketCommand` consumes their queued commands. Keep a narrow caveat that a future recovered header may expose this through a sender typedef/interface, but do not use generated `CashShopRequest*` aliases as final type evidence.
```

### [UID:0001QH] `client_network`

Replace the open question:

```markdown
- Final source-facing type for [UID:0000Q5][g_packetSender](by-global/g_packetSender.md). Socket owns its lifetime, but current generated code still inconsistently treats the pointed-to object like `CashShopRequest*`, `Socket*`, or a generic send object.
```

with:

```markdown
- Current best source-facing type for [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) is `Socket *`; Socket owns lifetime and consumes the queued command helpers. A later recovered sender interface remains possible, but generated `CashShopRequest*` aliases are now stale search/provenance only.
```

Also change the `Send Path` step 2 from generated `CashShopRequest::QueueAndSendPacket` wording to:

```markdown
2. Feature/UI code calls the Socket-owned `QueueAndSendPacket` wrapper through `g_packetSender`.
```

### [UID:0000I0] `CashShopRequest`

Replace the Contents bullet that lists Socket send helpers as likely CashShopRequest source contents:

```markdown
- `QueueWindowMessage`, `QueueAndSendPacket`, `SendStringCommand`, and raw/provisional [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md).
```

with:

```markdown
- Stale generated Socket send-corridor references: [UID:0001HT], [UID:0001HU], [UID:0001HV], and sibling `0x00574b90-0x00575377` helpers remain useful search/provenance links only. Their current direct source owner is [UID:0000DD][Socket](by-class/Socket.md), or a parent-blank non-emitting Socket split inventory, while [UID:0000OR][Thread](by-file/Thread.md) owns only the generic queue primitive.
```

## First-Draft C++ Recommendation

Do not populate the formal `RECONSTRUCTION_CPP` block for [UID:0001HS] in this pass.

Reason: the target now clears the numeric gate, but a source-quality C++ body would need final `Socket` member declarations for a 240k-byte object, final helper prototypes for memory allocation/copy/free, callback dispatch, PacketTransform helpers, and final policy for representing the scalar deleting destructor and constructor unwind helper. A decompiler-style draft with raw offsets would be misleading in `network/Socket.cpp`.

Review-only shape, not for formal insertion:

```cpp
Socket::Socket()
    : Thread(0x800)
{
    g_packetSender = this;
    srand(static_cast<unsigned>(time(nullptr)));

    void *seed = Allocate(9);
    Copy(seed, "UrkcnItni", 9);
    BuildHandshakeBlock(9, seed);

    g_processArgList = static_cast<char *>(Allocate(0x401));
    receiveBufferA = receiveStorageA;
    receiveBufferB = receiveStorageB;
    ClearReceiveAndFrameState();
    socketHandle = INVALID_SOCKET;
    serialHandle = INVALID_HANDLE_VALUE;
    sendDisabled = false;

    if (g_pConfig->transportMode == 6) {
        transportMode = 6;
        PostMode6StartupMessages();
    }
}

Socket::~Socket()
{
    if (socketHandle != INVALID_SOCKET) {
        closesocket(socketHandle);
        socketHandle = INVALID_SOCKET;
        connected = false;
    }
    if (serialHandle != INVALID_HANDLE_VALUE)
        CloseTransport();
    if (g_pConfig->transportMode == 6)
        PostMode6ShutdownMessages();
    if (g_processArgList)
        Free(g_processArgList);
    g_packetSender = nullptr;
}
```

## Exact by-memory/-coverage-report.md Rows

Placement: replace the existing rows for these UIDs in `by-memory/-coverage-report.md`. Keep surrounding padding rows unchanged. The [UID:0001P0] row is in the data/global section near `0x0067a7ec`; the other rows are in the Socket code section.

```markdown
    - [UID:0001HS][0x005747e0-0x00574ad8.SocketLifecycle](by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md) 0x005747e0-0x00574ad8 | constructor/destructor cluster | SocketLifecycle : reconstructable : 88% : very-strong : B003 source-quality pass resolved source signatures as `Socket::Socket()`/`Socket::~Socket()`, confirmed constructor xref at `0x0046466b`, destructor-family scalar deleting route through vtable slot `0x00624f20`, Socket-owned `g_packetSender` type/source placement, `UrkcnItni` default PacketTransform seed role, `0x0069ba58` process/key storage lifetime, receive/frame buffer and transport-handle field roles, mode 5/6/serial semantics, queue/send owner pollution, adjacent helper separation, and formal-C++ hold pending final Socket header/helper prototypes.
    - [UID:000242][0x00574ae0-0x00574b83.SocketEventDispatchHelpers](by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md) 0x00574ae0-0x00574b83 | dispatch helper island | SocketEventDispatchHelpers : reconstructable : 86% : very-strong : Socket-owned command-post helper island; current doc confirms modeled wrapper sizes, event ids `3/4/5/6/0x0c`, raw event-`0x0d` wrapper bytes, Thread queue/event callees `0x00596960`/`0x00596a00`, caller fan-in, no direct refs to raw `0x00574b70`, exact `0xcc` internal alignment, and `Socket::HandleSocketCommand` cases as command consumers.
    - [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) 0x00574bb0-0x00574c13 | Socket send helper | QueueAndSendPacket : reconstructable : 89% : very-strong : Assigned to [UID:0000DD][Socket](by-class/Socket.md); live IDA reconfirmed exact boundary, allocator/copy/dispatch callees, send-disabled byte `this+0x3aa4e`, 416 direct refs across 197 modeled callers, surrounding `0xcc` alignment, `g_packetSender` Socket-lifetime write evidence, and `Socket::HandleSocketCommand` case `8` as the queued-packet consumer.
    - [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md) 0x00574d00-0x00574d3f | Socket raw command helper | SendRawDataRaw : reconstructable : 87% : very-strong : Assigned to [UID:0000DD][Socket](by-class/Socket.md) by best-defensible structure; IDA confirms the raw allocate-copy-dispatch body, request code `0x0e`, exact bytes, no modeled function/callers/code refs/data refs/direct `.text` calls/pointer hits to the raw start, one-byte `0xcc` boundary, and `Socket::HandleSocketCommand` case `14` as the matching queued raw-data/handshake consumer.
    - [UID:0001I1][0x00575d90-0x005797ae.SocketTransportCore](by-memory/0x00575d90-0x005797ae.SocketTransportCore.md) 0x00575d90-0x005797ae | Socket transport aggregate | SocketTransportCore : not_reconstructable : 88% : very-strong : Reviewed non-emitting mixed aggregate over Socket transport methods, PacketTransform helpers, exact raw Socket children, scalar deleting destructor, and contained STL support; current doc confirms 31 modeled functions, raw reconnect/serial-open child splits, Socket command/send/receive ownership, PacketTransform/STL exclusions, corrected `0x005797ae` endpoint, and blank formal C++ because exact children own source emission.
    - [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md) 0x00578b20-0x00578c40 | Socket method | SocketTransformFramePayload : reconstructable : 85% : strong : Exact inbound transform method attached to Socket; current doc confirms `0x00578b20-0x00578c40` boundary, three caller functions/eight call sites, nonce/XOR callees, tail-byte nonce decode, primary/alternate transform table use, PE direct-reference count, and blank final C++ pending helper prototypes and source-facing buffer/member names.
    - [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md) 0x00578c40-0x00578df1 | Socket method | SocketBuildEncryptedPacket : reconstructable : 86% : strong : Exact outbound transform/framing method attached to Socket; current doc confirms `0x00578c40-0x00578df1`, three `SendEncodedPacket` callers, sequence byte update, nonce generation/obfuscation, primary/alternate and dword-LUT transform passes, MD5 trailer bytes, endpoint before `XorTransformBuffer`, and blank final C++ pending helper prototypes, Socket field names, and MD5 source representation.
    - [UID:0001P0][0x0067a7ec-0x0067a7f0.g_packetSender](by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md) 0x0067a7ec-0x0067a7f0 | global pointer | g_packetSender : reconstructable : 86% : strong : Socket-owned outbound packet sender pointer with current IDA-confirmed zero storage, 489 xrefs, all five Socket-family lifecycle writes, broad feature/UI reads, QueueAndSendPacket dependency, adjacent pointer/render-data boundaries, Socket owner/emitter route, and blank final C++ while final sender typedef/header representation remains below source-final confidence.
```

## Validation Commands

Run from `source-3/project-documentation` after supervisor applies target/support edits and the shared coverage rows:

> Executable block R001 was removed from this report and preserved verbatim in [0001HS-socket-lifecycle-source-quality-removed.md](0001HS-socket-lifecycle-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

No generated source change is expected for [UID:0001HS] because formal C++ should remain blank.

## Changed / No-Change Scope

This B003 pass is report-only. I did not edit by-* docs, generated reports, source files, IDA DB, generated source, or `by-memory/-coverage-report.md`. No split exception was used; no lease was needed for this research report.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0001HS-socket-lifecycle-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:27","uid":"0001HS"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0001HS-socket-lifecycle-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0001HS-socket-lifecycle-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0001HS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
