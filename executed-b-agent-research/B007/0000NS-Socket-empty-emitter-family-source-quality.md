** TARGET-REPORT-UID:0000NS **
** AUTHOR-AGENT-ID:B007 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **

# [UID:0000NS] Socket Empty-Emitter Family Source-Quality Report

Assignment: `B007-report-0000NS-Socket-empty-emitter-family-20260630`

Mode: report-only research. No target/support by-* docs, generated files, queue/lock files, IDA DB, validator state, supervisor ledgers, or manual coverage reports were edited.

Report path:

`E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B007\research\0000NS-Socket-empty-emitter-family-source-quality.md`

## Current Target State

Primary target [UID:0000NS] `by-file/Socket.md` currently routes to `auto-generated/NexusTK/network/Socket.cpp` with `COMPLETION:88`, `CONFIDENCE:85`, `CANONICAL_OWNER:FILE`, and projected path `NexusTK/network/`.

Current generated file evidence:

- Generated output: `auto-generated/NexusTK/network/Socket.cpp`
- Header command id: `000000002968`
- Refreshed at: `2026-06-30T14:48:57-04:00`
- Refresh source: `foreground-generated-refresh`
- Source by-file UID: `0000NS`
- Generated output contains one non-empty child, [UID:0000DD] `by-class/Socket.md`, which emits the limited `class Socket : public Thread` declaration plus `extern Socket *g_packetSender;`.
- Generated output then emits 15 empty marker rows for the current assignment family.

The active Socket by-file and by-class pages are already strong source-placement pages. The remaining queue problem is not broad ownership confusion; it is that 15 Socket-owned support entries still have blank formal blocks and therefore still appear as empty emitters.

## MCP Session And Evidence Basis

MCP availability was current and usable for this report:

- Endpoint: `http://127.0.0.1:13337/mcp`
- `initialize`: succeeded; server `ida-pro-mcp` version `1.0.0`.
- Active database: `supervisor_resume_20260629`
- `idb_list`: one active worker session for `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, active and not analyzing.
- `server_health`: `status:"ok"`, module `NexusTK.exe`, input path `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`, imagebase `0x400000`, `auto_analysis_ready:true`, `hexrays_ready:true`, `strings_cache_ready:true`.

Current MCP evidence used directly:

- `lookup_funcs` for `0x005747e0`, `0x005749e0`, `0x00574ae0`, `0x00574b00`, `0x00574b20`, `0x00574b30`, `0x00574b50`, `0x00574b70`, `0x00574bb0`, `0x00574d00`, `0x00574d40`, `0x00574e50`, `0x00575370`, `0x00578b20`, `0x00578c40`, and `0x005794c0`.
- `analyze_component` for the constructor/destructor, send helpers, transform helpers, getter, and cleanup helper.
- `analyze_function` for `QueueAndSendPacket` and `Socket::HandleSocketCommand`.
- `xrefs_to` for raw starts, live helper starts, transform methods, vtable base, sender global, packet table base, and connection-string pointer boundary.
- `get_bytes` for raw helper bytes, cleanup bytes, vtable/literal bytes, packet table head bytes, and connection-string pointer bytes.
- `insn_query` over raw command-13, raw command-14, and raw packet logger ranges.
- `get_string` for `UrkcnItni`, `CONNADDR`, delimiter string, packet logging formats, and packet table strings.

Important current MCP confirmations:

- `0x00574b70` and `0x00574d00` remain no-function raw starts with no xrefs to their starts.
- `0x00574bb0` remains `sub_574BB0`, size `0x63`; it checks `this[240206]`, allocates `packetSize + 1`, copies exactly `packetSize`, writes a local zero terminator, and posts command `8` through `sub_596960`.
- `Socket::HandleSocketCommand` at `0x00575e60`, size `0x344`, still consumes commands `3`, `4`, `5`, `6`, `7`, `8`, `9`, `10`, `11`, `13`, and `14`; command `8` sends and frees the copied packet, command `13` writes transform LUT values, and command `14` calls `BuildHandshakeBlock`.
- `0x00574d40`, `0x00574e50`, and `0x00575370` have the same current xrefs documented by the existing pages: two callers for the status/version packet, three refs for friend-name sync, and three refs for the status-byte getter.
- `0x00578b20` has eight receive-path call sites; `0x00578c40` has three `SendEncodedPacket` call sites.
- `0x005794c0` has exactly one xref, the Socket constructor unwind jump at `0x0060805e`.
- `0x00624f20` has Socket vtable refs from constructor/destructor/scalar-deleting destructor; `0x00625008` is referenced by the raw packet logger; `0x00670258` is referenced by the Socket connection-string parser.

## Prior Reports Treated As Leads

I re-read these executed reports as required leads and revalidated important claims with current MCP:

- `executed-b-agent-research/B006/0000DD-Socket-class-source-quality.md`
- `executed-b-agent-research/B003/0001HS-socket-lifecycle-source-quality.md`
- `executed-b-agent-research/B003/0001I6-ClearPacketSenderGlobal-source-quality.md`
- `executed-b-agent-research/B001/00026H-server-packet-name-table-source-routing.md`
- `executed-b-agent-research/B004/000286-PacketTransformAlternateSizeAndLut-source-quality.md`

Those reports remain valid as historical and support evidence. Current MCP did not contradict their core Socket ownership, raw-helper liveness, sender-global type, packet-table boundary, or transform-global split decisions.

## Empty Emitter Inventory And Dispositions

| UID | Current path | Current score | Current owner/emitter | Current route | Disposition for callback |
| --- | --- | ---: | --- | --- | --- |
| [UID:000242] | `by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md` | `86/90` | owner/emitter [UID:0000DD] | Socket command-post wrappers | Emit first-draft wrapper bodies for modeled commands `3/4/5/6/12`; keep raw command `13` as retained no-route proof comment in same formal block. |
| [UID:0001HU] | `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md` | `89/91` | owner/emitter [UID:0000DD] | Socket queue/send method | Emit first-draft `Socket::QueueAndSendPacket` body. |
| [UID:0001HV] | `by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md` | `87/90` | owner/emitter [UID:0000DD] | Socket raw command-14 helper | Keep retained raw helper, no body; add formal no-code proof comment naming `QueueHandshakeBlock` / `QueuePacketTransformSeedBlock` and rejecting `SendRawData`. |
| [UID:0001HW] | `by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md` | `87/90` | owner/emitter [UID:0000DD] | Socket queued status/version packet helper | Emit first-draft body using a seven-byte payload plus queue scratch terminator. Rename prose role away from player position. |
| [UID:0001HX] | `by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md` | `87/90` | owner/emitter [UID:0000DD] | Socket queued friend-name sync helper | Emit first-draft body with ordered unique-name container and opcode `0x77`. |
| [UID:0001HY] | `by-memory/0x00575370-0x00575377.GetConnectionStatus.md` | `87/90` | owner/emitter [UID:0000DD] | Socket getter | Emit exact source-ready getter body. |
| [UID:0000Q5] | `by-global/g_packetSender.md` | `86/88` | owner/emitter [UID:0000NS] | Canonical sender-global page | Emit canonical global definition `Socket *g_packetSender = nullptr;`. |
| [UID:0001HS] | `by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md` | `88/91` | owner/emitter [UID:0000NS] | Socket constructor/destructor | Emit source-shape constructor/destructor draft that uses the documented field names and helper calls, with layout caveat in prose. |
| [UID:0001I3] | `by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md` | `85/88` | owner/emitter [UID:0000NS] | Socket inbound transform method | Emit first-draft method body using PacketTransform helper names and documented constants. |
| [UID:0001I4] | `by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md` | `86/89` | owner/emitter [UID:0000NS] | Socket outbound transform method | Emit first-draft method body using PacketTransform/MD5 helper names and documented trailer bytes. |
| [UID:0001I6] | `by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md` | `86/92` | owner/emitter [UID:0000NS] | Constructor unwind cleanup | Keep blank of real code; add formal no-code proof comment. |
| [UID:00026G] | `by-memory/0x00624f20-0x00625008.SocketReadOnlyData.md` | `86/90` | owner/emitter [UID:0000NS] | Socket vtable/literals | Do not emit raw vtable; emit source constants for Socket-owned literals and a no-code vtable note. |
| [UID:00026H] | `by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md` | `88/90` | owner/emitter [UID:0000NS] | Socket/protocol debug packet names | Emit first-draft static table declaration or, if supervisor rejects table emission policy, at minimum add formal no-code proof. Preferred callback action is first-draft data declaration using the known 116 nonblank entries and blank reserved slots. |
| [UID:000287] | `by-memory/0x00670258-0x00670260.SocketConnectionStringParsePointers.md` | `86/90` | owner/emitter [UID:0000NS] | Socket parser initialized pointers | Do not duplicate storage; emit formal source-constant alias/proof tying slots to [UID:00026G] strings. |
| [UID:0001P0] | `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md` | `86/89` | owner/emitter [UID:0000NS] | Memory storage for same global | Do not emit a duplicate definition; add formal no-code proof comment saying [UID:0000Q5] emits the canonical declaration/definition. |

## Ownership And Source-Placement Decisions

Accepted source root: [UID:0000NS] `Socket.cpp`.

Accepted direct class owner for method helpers: [UID:0000DD] `Socket`.

Rejected alternatives:

- `CashShopRequest`: stale generated owner for the send corridor. Current MCP and docs show `g_packetSender` lifetime writes are Socket-only, the real cash-shop/file-downloader singleton is separate, and `Socket::HandleSocketCommand` consumes the queued command IDs.
- `Thread`: owns the queue/event/wait-handle primitives, not the Socket command wrappers. `sub_596960` and `sub_596a00` are callees.
- `PacketBuffer`: owns scalar buffer/cursor helpers, not Socket object state or `g_packetSender`.
- `PacketTransform`: owns free transform globals/helpers. Socket owns the stateful inbound/outbound sequencing methods [UID:0001I3] and [UID:0001I4].
- `MapPane`/`ProtocolSend`: packet table labels and feature packet builders are broader protocol consumers, not the owner of low-level Socket transport/debug data.

No new child pages are required for this callback. The accepted split state is already sufficient. If a later callback wants exact scalar deleting destructor or raw logger pages, that should be assigned as a future split task, not created manually in this report-only pass.

## Score And Metadata Recommendations

Recommended by-file and class support changes:

| UID | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| [UID:0000NS] `Socket` file | `88/85` | `90/89` | Current MCP confirms active IDB, exact helper boundaries, Socket-owned sender lifetime, vtable/literal data, transform methods, and data boundaries. Empty-family cleanup will add formal C++/formal no-code dispositions for every current generated marker. Confidence remains below near-final because original folder/header spelling and some helper typedefs remain inferred. |
| [UID:0000DD] `Socket` class | `88/88` | `90/89` | Add declarations for command-post helpers used by new formal bodies, keep `[[CHILDREN]]`, preserve field table and raw helper caveats. Confidence remains below final because full ABI layout is still prose-only. |

Recommended empty-page score changes:

| UID | Current | Recommended | Rationale |
| --- | ---: | ---: | --- |
| [UID:000242] | `86/90` | `89/91` | Current MCP confirms modeled wrapper sizes and raw command-13 bytes/no xrefs; formal wrapper code can be emitted for live wrappers while raw command-13 gets a specific no-route comment. |
| [UID:0001HU] | `89/91` | `91/92` | Current MCP decompile and broad xref fan-in support source-ready first-draft body and exact command-8 ownership. |
| [UID:0001HV] | `87/90` | `88/91` | Current MCP reconfirms raw no-function/no-xref body and command-14 consumer. Completion improves by replacing empty marker with a formal no-code proof and source-facing name decision. |
| [UID:0001HW] | `87/90` | `90/91` | Current MCP confirms boundary, two callers, callees, and Socket guard. First-draft body resolves the empty marker; confidence remains capped by exact original helper name. |
| [UID:0001HX] | `87/90` | `90/91` | Current MCP confirms boundary and three refs. First-draft source with ordered unique container resolves the empty marker; exact typedef/local names remain inferred. |
| [UID:0001HY] | `87/90` | `91/93` | Exact 7-byte getter with three refs; source-ready body is trivial and field role is documented. |
| [UID:0000Q5] | `86/88` | `90/91` | Canonical global can now emit `Socket *g_packetSender = nullptr;`; current MCP confirms `0x0067a7ec` high-fanout refs and Socket lifecycle writes. |
| [UID:0001HS] | `88/91` | `90/92` | Current MCP confirms constructor/destructor sizes, `UrkcnItni`, vtable/global writes, and field roles. First-draft source-shape body can be emitted without pretending the full ABI layout is final. |
| [UID:0001I3] | `85/88` | `88/90` | Current MCP confirms eight callers and transform callees; first-draft source resolves marker while helper prototypes remain source-quality cap. |
| [UID:0001I4] | `86/89` | `89/91` | Current MCP confirms three callers and digest/nonce/transform callees; first-draft source resolves marker while helper prototypes and MD5 representation remain caps. |
| [UID:0001I6] | `86/92` | `87/93` | No real source body should emit, but formal no-code proof is exact: one EH route, no callees, no pointer route, ordinary destructors inline the clear. |
| [UID:00026G] | `86/90` | `88/91` | Current MCP confirms vtable bytes, Socket literals, `CONNADDR`, delimiter, and error text. Source constants can emit while vtable remains compiler-generated. |
| [UID:00026H] | `88/90` | `90/91` | Current MCP confirms packet-table base xref and raw logger; prior PE inventory gives full table. First-draft table declaration resolves marker; retained-debug/no-caller policy keeps confidence capped. |
| [UID:000287] | `86/90` | `88/91` | Current MCP confirms exact pointer bytes and parser xref. Formal block should document aliasing to [UID:00026G] constants rather than duplicate storage. |
| [UID:0001P0] | `86/89` | `87/90` | Source storage remains the same global as [UID:0000Q5]. Completion improves with duplicate-definition no-code proof; confidence capped by possible future sender typedef. |

Do not change [UID:0001HV], [UID:000242] raw command-13, [UID:0001I6], [UID:00026G] vtable bytes, [UID:000287], or [UID:0001P0] into padding/dead code. They are meaningful Socket evidence or source data, not arbitrary filler.

## Formal C++ / Marker Dispositions

The exact callback rule should be: every changed target must get either real formal source or a target-specific formal no-code proof comment in its `RECONSTRUCTION_CPP CODE` block. No useful evidence should remain only in prose.

### [UID:000242] SocketEventDispatchHelpers

Recommended formal block:

```cpp
void Socket::PostConnectWithFallbackCommand(char transportMode, void *endpointData)
{
    DispatchRequest(4, static_cast<unsigned long>(static_cast<signed char>(transportMode)), endpointData);
}

void Socket::PostConnectCommand(char transportMode, void *endpointData)
{
    DispatchRequest(3, static_cast<unsigned long>(static_cast<signed char>(transportMode)), endpointData);
}

void Socket::PostResetConnectionCommand()
{
    DispatchRequest(5, 0, 0);
}

HANDLE Socket::PostConnectionStatusQuery(bool *outConnected)
{
    return DispatchRequestAndReturnEvent(12, outConnected, 1, 0, 0);
}

void Socket::PostReconnectEndpointCommand(unsigned long hostAddress, unsigned short port)
{
    DispatchRequest(6, hostAddress, port);
}

// No standalone body is emitted for raw command-13 at 0x00574b70.
// Current MCP shows no IDA function and zero xrefs to the raw start; the bytes
// post command 13 through Thread::DispatchRequest and remain retained Socket
// support evidence until a live source route or retained-helper policy is accepted.
```

Support change: add declarations for the first five methods to [UID:0000DD] `Socket` if formal method bodies are inserted.

### [UID:0001HU] QueueAndSendPacket

Recommended formal block:

```cpp
void Socket::QueueAndSendPacket(const void *packetData, short packetSize)
{
    if (m_sendDisabled)
        return;

    const int copySize = static_cast<int>(packetSize);
    char *queuedPacket = static_cast<char *>(AllocatePacketQueueMemory(copySize + 1));
    CopyPacketQueueMemory(queuedPacket, packetData, copySize);
    queuedPacket[copySize] = '\0';

    DispatchRequest(8, queuedPacket, static_cast<short>(copySize + 1));
}
```

Implementation caveat: `AllocatePacketQueueMemory` and `CopyPacketQueueMemory` are source-facing placeholders for the existing allocator/copy helpers at `0x00516050` and `0x00516220`; if the project has better helper names at callback time, use those consistently.

### [UID:0001HV] SendRawDataRaw

Recommended formal block:

```cpp
// No standalone C++ body is emitted for raw 0x00574d00 in this pass.
// Current MCP keeps the start unmodeled and xref-free. The raw body allocates
// exactly size bytes, copies the caller buffer, and posts command 14 through
// Thread::DispatchRequest; Socket::HandleSocketCommand consumes command 14 by
// feeding the queued bytes to the handshake/seed builder. Document the source
// role as Socket::QueueHandshakeBlock or Socket::QueuePacketTransformSeedBlock,
// not SendRawData, until a live caller/table route or retained-helper emission
// policy is accepted.
```

### [UID:0001HW] SendPositionUpdate

Recommended formal block:

```cpp
void Socket::QueueClientVersionStatusPacket()
{
    unsigned char packet[7];
    unsigned short first = g_pApplication->GetClientVersionCode();
    const unsigned short second = g_pApplication->GetClientVersionLowWord();

    g_packetSequenceByte = 0;

    if (g_pConfig->ShouldJitterClientVersion() && rand() < 0x1fff)
        --first;

    packet[0] = 0;
    packet[1] = static_cast<unsigned char>(first >> 8);
    packet[2] = static_cast<unsigned char>(first);
    packet[3] = 0xc5;
    packet[4] = static_cast<unsigned char>(second >> 8);
    packet[5] = static_cast<unsigned char>(second);
    packet[6] = g_useEpfAssets;

    QueueAndSendPacket(packet, 7);
}
```

Support change: keep the existing filename as historical, but prose should call this a client-version/status packet helper, not player position coordinates.

### [UID:0001HX] BuildAndSendFriendNameListSync

Recommended formal block:

```cpp
void Socket::BuildAndSendFriendNameListSync()
{
    unsigned char packet[1 + 20 * 13];
    std::set<std::wstring> uniqueNames;
    int packetSize = 2;

    packet[0] = 0x77;

    for (int i = 0; i < 20; ++i) {
        const std::wstring name = g_pConfig->GetFriendNameListEntry(i);
        if (!name.empty())
            uniqueNames.insert(name);
    }

    packet[1] = static_cast<unsigned char>(uniqueNames.size());

    for (std::set<std::wstring>::const_iterator it = uniqueNames.begin();
         it != uniqueNames.end() && packetSize + 13 <= static_cast<int>(sizeof(packet));
         ++it) {
        char narrowName[13] = {};
        WideStringToNarrowFixed(narrowName, *it, 12);
        packet[packetSize++] = 0x0c;
        CopyPacketQueueMemory(packet + packetSize, narrowName, 12);
        packetSize += 12;
    }

    QueueAndSendPacket(packet, static_cast<short>(packetSize));
}
```

Implementation caveat: `GetFriendNameListEntry`, `WideStringToNarrowFixed`, and `CopyPacketQueueMemory` are source-facing placeholders; the callback should preserve the exact offset evidence in prose and use any established helper names already present in current support docs.

### [UID:0001HY] GetConnectionStatus

Recommended formal block:

```cpp
unsigned char Socket::GetConnectionStatus() const
{
    return m_connectionStatus;
}
```

### [UID:0000Q5] g_packetSender

Recommended formal block:

```cpp
Socket *g_packetSender = nullptr;
```

Support change: [UID:0001P0] must not also emit this definition.

### [UID:0001HS] SocketLifecycle

Recommended formal block:

```cpp
Socket::Socket()
    : Thread(0x800),
      m_socket(INVALID_SOCKET),
      m_socketConnected(false),
      m_serialTransportHandle(INVALID_HANDLE_VALUE),
      m_transportMode(0),
      m_protocolModeFlag(0),
      m_connectionFlag(0),
      m_sendDisabled(0),
      m_connectionStatus(0),
      m_connectionRetryDelay(10)
{
    g_packetSender = this;

    srand(static_cast<unsigned int>(time(nullptr)));

    char seed[] = "UrkcnItni";
    BuildHandshakeBlock(sizeof(seed), seed);

    g_processArgList = static_cast<char *>(AllocatePacketQueueMemory(0x401));

    m_activeReadBuffer = m_receiveBufferPrimary;
    m_alternateReadBuffer = m_receiveBufferAlternate;
    ClearSocketReceiveAndFrameState();

    if (g_pConfig->GetTransportMode() == 6) {
        m_transportMode = 6;
        PostMode6StartupMessages();
    }
}

Socket::~Socket()
{
    if (m_socket != INVALID_SOCKET) {
        closesocket(m_socket);
        m_socket = INVALID_SOCKET;
        m_socketConnected = false;
    }

    if (m_serialTransportHandle != INVALID_HANDLE_VALUE)
        CloseTransport();

    if (g_pConfig->GetTransportMode() == 6)
        PostMode6ShutdownMessages();

    if (g_processArgList != nullptr) {
        FreePacketQueueMemory(g_processArgList);
        g_processArgList = nullptr;
    }

    g_packetSender = nullptr;
}
```

This is a source-shape first draft, not a complete ABI layout. The support prose must retain exact offsets and the reason the formal block uses high-probability field names instead of declaring the full 240k-byte object layout.

### [UID:0001I3] SocketTransformFramePayload

Recommended formal block:

```cpp
int Socket::TransformFramePayload(const unsigned char *input,
                                  int inputLength,
                                  unsigned char *output,
                                  bool useAlternateKey)
{
    output[0] = input[0];
    const unsigned char sequence = input[1];

    InitializePacketNonce(static_cast<unsigned short>(((input[inputLength - 1] ^ 0x74) << 8) |
                                                      (input[inputLength - 3] ^ 0x24)),
                          static_cast<unsigned char>(input[inputLength - 2] ^ 0x21));

    const int bodyLength = inputLength - 5;
    if (bodyLength <= 0) {
        output[inputLength - 4] = 0;
        return inputLength - 4;
    }

    XorTransformBuffer(input + 2, bodyLength, output + 1,
                       &g_packetTransformLut[sequence], 1);

    const int stride = g_packetTransformStride;
    const int blockCount = ((bodyLength - 1) / stride) + 1;
    for (int block = 0; block < blockCount; ++block) {
        if (block != sequence) {
            const int offset = block * stride;
            const int count = std::min(stride, bodyLength - offset);
            XorTransformBuffer(output + 1 + offset, count, output + 1 + offset,
                               &g_packetTransformLut[block], 1);
        }
    }

    if (useAlternateKey) {
        XorTransformBuffer(output + 1, bodyLength, output + 1,
                           g_packetXorTableAlternate, g_packetXorAlternateSize);
    } else {
        XorTransformBuffer(output + 1, bodyLength, output + 1,
                           g_packetXorTablePrimary, g_packetTransformStride);
    }

    output[inputLength - 1] = 0;
    return inputLength - 1;
}
```

### [UID:0001I4] SocketBuildEncryptedPacket

Recommended formal block:

```cpp
int Socket::BuildEncryptedPacket(const unsigned char *input,
                                 int inputLength,
                                 unsigned char *output,
                                 bool useAlternateKey)
{
    const unsigned char sequence = g_packetSequenceByte++;
    output[0] = input[0];
    output[1] = sequence;

    const int bodyLength = inputLength - 1;
    if (bodyLength <= 0) {
        output[inputLength + 1] = 0;
        return inputLength + 1;
    }

    unsigned int randomValue = 0;
    rand_s(&randomValue);
    const unsigned short nonce = static_cast<unsigned short>((randomValue & 0xffff) % 0xfefd + 0x100);
    const unsigned char middle = static_cast<unsigned char>(((randomValue >> 16) % 0x9b) + 100);

    InitializePacketNonce(nonce, middle);

    if (useAlternateKey) {
        XorTransformBuffer(input + 1, bodyLength, output + 2,
                           g_packetXorTableAlternate, g_packetXorAlternateSize);
    } else {
        XorTransformBuffer(input + 1, bodyLength, output + 2,
                           g_packetXorTablePrimary, g_packetTransformStride);
    }

    const int stride = g_packetTransformStride;
    const int blockCount = ((bodyLength - 1) / stride) + 1;
    for (int block = 0; block < blockCount; ++block) {
        if (block != sequence) {
            const int offset = block * stride;
            const int count = std::min(stride, bodyLength - offset);
            XorTransformBuffer(output + 2 + offset, count, output + 2 + offset,
                               &g_packetTransformLut[block], 1);
        }
    }

    XorTransformBuffer(output + 2, bodyLength, output + 2,
                       &g_packetTransformLut[sequence], 1);

    unsigned char digest[16];
    BuildPacketDigest(output, inputLength + 1, digest);

    output[inputLength + 1] = digest[13];
    output[inputLength + 2] = digest[3];
    output[inputLength + 3] = digest[11];
    output[inputLength + 4] = digest[7];
    output[inputLength + 5] = static_cast<unsigned char>((nonce & 0xff) ^ 0x61);
    output[inputLength + 6] = static_cast<unsigned char>(middle ^ 0x25);
    output[inputLength + 7] = static_cast<unsigned char>((nonce >> 8) ^ 0x23);
    output[inputLength + 8] = 0;

    return inputLength + 8;
}
```

### [UID:0001I6] ClearPacketSenderGlobal

Recommended formal block:

```cpp
// No standalone C++ body is emitted for 0x005794c0.
// Current MCP shows the body is exactly a constructor-unwind cleanup funclet:
// one EH tail-jump at 0x0060805e reaches it, the body ignores ECX, clears
// g_packetSender, has no callees, and has no vtable/data/pointer route.
// The source effect belongs in Socket construction/destruction, where
// g_packetSender is published and cleared, not in a callable helper API.
```

### [UID:00026G] SocketReadOnlyData

Recommended formal block:

```cpp
namespace {
const char kDefaultSocketHandshakeSeed[] = "UrkcnItni";
const wchar_t kSocketConnectionAddressKey[] = L"CONNADDR";
const char kSocketConnectionDelimiters[] = " :,\t";
const wchar_t kSocketCopyDataTooLongMessage[] = L"Too long data in COPYDATASTRUCT";
}

// The Socket vtable bytes at 0x00624f20 are compiler-generated from the
// Socket class declaration and inherited Thread virtual order; do not emit a
// handwritten vtable object from this page.
```

### [UID:00026H] ServerPacketNameTable

Preferred formal block shape:

```cpp
namespace {
const wchar_t kServerPacketNames[256][63] = {
    L"kServerVersionCheck", L"kServerNewUserCheck", L"kServerLoginCheck",
    L"kServerTileCheck", L"kServerUserPosition", L"kServerUserAppearance",
    L"kServerMap", L"kServerDrawObjects", L"kServerStatus",
    L"kServerNationAndTotemCheck", L"kServerMessage", L"kServerMove",
    L"kServerMoveObject", L"kServerSay", L"kServerRemoveObjects",
    L"kServerAddInventory", L"kServerRemoveInventory", L"kServerChangeDirection",
    L"kServerCollection", L"kServerDamageEffect", L"kServerNewPasswordCheck",
    L"kServerMapSize", L"kServerFlyingObject", L"kServerAddSpell",
    L"kServerRemoveSpell", L"kServerSoundEffect", L"kServerMotion",
    L"kServerEnterEditingMode", L"#28", L"kServerChangeShape", L"#30",
    L"kServerChangeWeather", L"kServerChangeHour", L"kServerSelfSaveOK",
    L"kServerRefreshUserOK", L"kServerOption", L"kServerChangeCondition",
    L"#37", L"kServerMovePosition", L"#39", L"kServerCloseConnection",
    L"kServerEffectLayer", L"#42", L"#43", L"#44", L"#45",
    L"kServerFieldMap", L"kServerScreenMenu", L"kServerPursuitMessage",
    L"kServerBulletin", L"#50", L"#51", L"kServerObjectBubbleInfo",
    L"kServerShowPaper", L"kServerUserList", L"#55", L"#56", L"#57",
    L"#58", L"kServerRequestCRC", L"#60", L"#61", L"#62", L"#63",
    L"#64", L"#65", L"#66", L"#67", L"#68", L"#69", L"#70",
    L"#71", L"#72", L"#73", L"#74", L"#75", L"#76", L"#77",
    L"#78", L"#79", L"#80", L"#81", L"#82", L"kServerServerClose",
    L"#84", L"#85", L"#86", L"#87", L"#88", L"#89", L"#90",
    L"#91", L"#92", L"#93", L"#94", L"#95", L"#96", L"#97",
    L"#98", L"#99", L"#100", L"#101", L"#102", L"#103", L"#104",
    L"#105", L"#106", L"#107", L"#108", L"#109", L"#110", L"#111",
    L"#112", L"#113", L"#114", L"kServerReconnect"
    // Slots 116 through 255 are intentionally blank reserved entries.
};

const wchar_t kPacketLogNumericFormat[] = L"%08x: packet %d\n";
const wchar_t kPacketLogNamedFormat[] = L"%08x: packet %s\n";
}
```

Implementation note: this source block is implementation-ready as first draft but not final-audit exact because C++ aggregate initialization with 116 entries leaves remaining slots value-initialized; the original binary reserves all 256 fixed slots at `0x7e` stride. If the supervisor wants byte-for-byte source-data explicitness, expand entries 116-255 as `L""` during callback. Do not move `UNL.DLL` back into this page.

### [UID:000287] SocketConnectionStringParsePointers

Recommended formal block:

```cpp
// No separate storage definition is emitted for 0x00670258-0x00670260.
// These initialized pointer slots are the compiler/linker representation of
// Socket parser constants: kSocketConnectionAddressKey -> L"CONNADDR" and
// kSocketConnectionDelimiters -> " :,\t", both emitted with Socket read-only
// data. Current MCP confirms bytes a8 4f 62 00 / bc 4f 62 00 and the parser
// xref at 0x005778cf.
```

### [UID:0001P0] g_packetSender Memory Storage

Recommended formal block:

```cpp
// No duplicate global definition is emitted from this exact storage page.
// [UID:0000Q5] by-global/g_packetSender.md emits the canonical source storage:
//     Socket *g_packetSender = nullptr;
// This page documents the 0x0067a7ec zero-initialized memory slot, Socket-only
// lifetime writes, broad read fan-in, and alias rejection evidence.
```

## Claim And Incorporation Ledger

Callback result: every accepted item below was incorporated into target/support docs at report-level detail or resolved with explicit no-code/alias proof. No accepted claim was excluded or blocked.

| Claim | Target/support docs | Callback disposition |
| --- | --- | --- |
| MCP session `supervisor_resume_20260629` was active/healthy and all current claims are MCP-backed. | Report; [UID:0000NS] by-file callback summary. | applied - [UID:0000NS] now records the MCP-backed accepted empty-emitter cleanup and current evidence basis. |
| [UID:0000NS] current baseline is `88/85`; generated `Socket.cpp` command id `000000002968` had one filled class and 15 empty markers. | [UID:0000NS] Changes/source split summary. | applied - [UID:0000NS] is `90/89`, records the former 15-marker generated baseline, and final generated `Socket.cpp` has zero `Empty Emitter Marker` rows. |
| [UID:000242] modeled wrappers are function starts with sizes `0x16`, `0x16`, `0x0c`, `0x17`, `0x16`; raw `0x00574b70` is no-function/no-xref and posts command `13`. | [UID:000242], [UID:0000DD]. | applied - formal wrapper bodies and raw command-13 no-code proof inserted; [UID:0000DD] declarations added. |
| `QueueAndSendPacket` copies caller bytes, appends scratch zero, posts command `8`, and has broad caller fan-in. | [UID:0001HU], [UID:0000DD], [UID:0000Q5]. | applied - formal body inserted with send-disabled guard, copy, scratch terminator, and command `8`; [UID:0001HU] raised to `91/92`. |
| Raw `0x00574d00` posts command `14`, has no function/xrefs, and is not direct raw transport send. | [UID:0001HV], [UID:0000DD], [UID:0000NS]. | applied - formal no-code proof inserted, `QueueHandshakeBlock` / `QueuePacketTransformSeedBlock` naming preserved, stale current blank-C++ wording historicalized. |
| `0x00574d40` is client version/status upload, not player position; callers are `0x005542a9` and `0x0058b42f`. | [UID:0001HW]. | applied - formal `QueueClientVersionStatusPacket` body inserted and support prose records stale filename/name caveat, packet layout, and caller evidence. |
| `0x00574e50` is opcode `0x77` friend-name list sync; current xrefs remain two defined callers plus raw flag-gated ref. | [UID:0001HX]. | applied - formal friend-name sync body inserted with ordered unique-name container and helper-name caveat. |
| `0x00575370` returns `this+0x3aa4f` and has no callees. | [UID:0001HY], [UID:0000DD]. | applied - exact getter body inserted and [UID:0001HY] raised to `91/93`. |
| `g_packetSender` best current source type is `Socket *`; generated `CashShopRequest *`, `Thread *`, and `void *` are rejected/secondary. | [UID:0000Q5], [UID:0001P0], [UID:0000NS], [UID:0000DD]. | applied - [UID:0000Q5] emits `Socket *g_packetSender = nullptr;`; [UID:0001P0] has no-duplicate-definition proof; stale blank-C++ wording historicalized. |
| Socket lifecycle can emit source-shape constructor/destructor but full ABI layout remains prose-only. | [UID:0001HS], [UID:0000DD]. | applied - formal lifecycle draft inserted, [UID:0001HS] raised to `90/92`, and prose still preserves offset/ABI caveats. |
| Inbound/outbound transform methods are Socket stateful methods; PacketTransform owns helper globals/functions. | [UID:0001I3], [UID:0001I4]. | applied - formal transform bodies inserted, scores raised to `88/90` and `89/91`, and helper-prototype/PacketTransform ownership caveats preserved. |
| `ClearPacketSenderGlobal` is constructor-unwind cleanup only, with one EH xref and no callable helper route. | [UID:0001I6], [UID:0000NS], [UID:0000Q5], [UID:0001P0]. | applied - formal no-code proof inserted, [UID:0001I6] raised to `87/93`, and no helper body emitted. |
| Socket vtable bytes are compiler-generated from class declaration; literals in [UID:00026G] are Socket-owned constants. | [UID:00026G], [UID:0000DD]. | applied - formal constants plus vtable no-code note inserted; [UID:00026G] raised to `88/91`. |
| Server packet table remains Socket/protocol debug data, not MapPane/PacketTransform/ProtocolSend. | [UID:00026H], [UID:0000NS]. | applied - accepted first-draft `kServerPacketNames[256][63]` table declaration inserted; stale marker-only/blank policy text replaced; [UID:00026H] raised to `90/91`. |
| [UID:000287] pointer slots alias `CONNADDR` and delimiter constants from [UID:00026G]. | [UID:000287], [UID:00026G]. | applied - formal no-duplicate-storage proof inserted and [UID:000287] raised to `88/91`. |
| [UID:0001P0] exact storage page must not duplicate [UID:0000Q5] canonical global definition. | [UID:0001P0], [UID:0000Q5]. | applied - formal no-duplicate-global proof inserted; generated output has one canonical definition and one class `extern` declaration. |

## Implementation Tracking Checklist

Callback result: all accepted implementation items are complete.

- [x] Lease only the files being edited immediately; do not hold leases across research or waiting. Proof: leased the 17 accepted by-* files as B007 immediately before patching; `unlease` later reported `Rejected[No active lease]` for each because the lease window had expired during validation, and current lease report shows no active B007 lease.
- [x] Update [UID:0000NS] `by-file/Socket.md` score to `90/89`; add report-level summary of this empty-emitter family cleanup and current MCP session evidence. Proof: [UID:0000NS] header is `90/89` and its source split section records the accepted MCP-backed cleanup and former generated marker baseline.
- [x] Update [UID:0000DD] `by-class/Socket.md` score to `90/89`; add declarations required by formal method bodies and keep `[[CHILDREN]]`. Proof: class header is `90/89`, command/version/friend declarations were added, and `[[CHILDREN]]` remains in the formal block.
- [x] Update [UID:000242] formal block, score, wrapper names, raw command-13 no-code proof, and support prose. Proof: [UID:000242] is `89/91` and formal block contains five wrapper bodies plus raw command-13 no-route proof.
- [x] Update [UID:0001HU] formal block, score, send-disabled field name, queue length/scratch terminator proof, and command-8 consumer evidence. Proof: [UID:0001HU] is `91/92` and formal block emits `Socket::QueueAndSendPacket`.
- [x] Update [UID:0001HV] formal no-code proof, score, `QueueHandshakeBlock` naming, and negative raw-route evidence. Proof: [UID:0001HV] is `88/91` and formal block is target-specific no-code proof for raw command `14`.
- [x] Update [UID:0001HW] formal block, score, stale `Position` name caveat, packet layout, and caller evidence. Proof: [UID:0001HW] is `90/91` and formal block emits `QueueClientVersionStatusPacket`.
- [x] Update [UID:0001HX] formal block, score, opcode `0x77` layout, caller/raw-ref evidence, and ordered-string container caveat. Proof: [UID:0001HX] is `90/91` and formal block emits `BuildAndSendFriendNameListSync`.
- [x] Update [UID:0001HY] formal getter block and score. Proof: [UID:0001HY] is `91/93` and formal block emits `GetConnectionStatus`.
- [x] Update [UID:0000Q5] formal global definition and score; ensure [UID:0001P0] does not duplicate it. Proof: [UID:0000Q5] is `90/91` and emits `Socket *g_packetSender = nullptr;`; [UID:0001P0] emits no duplicate.
- [x] Update [UID:0001HS] formal lifecycle source-shape block, score, and preserve field-offset evidence. Proof: [UID:0001HS] is `90/92`, formal constructor/destructor draft inserted, and offset/ABI caveats remain.
- [x] Update [UID:0001I3] formal inbound transform block and score. Proof: [UID:0001I3] is `88/90` and emits `TransformFramePayload`.
- [x] Update [UID:0001I4] formal outbound transform block and score. Proof: [UID:0001I4] is `89/91` and emits `BuildEncryptedPacket`.
- [x] Update [UID:0001I6] formal no-code proof and score. Proof: [UID:0001I6] is `87/93` and emits only constructor-unwind no-code proof.
- [x] Update [UID:00026G] formal constants/vtable no-code note and score. Proof: [UID:00026G] is `88/91` and emits constants plus compiler-generated vtable note.
- [x] Update [UID:00026H] formal packet-table declaration and score. Proof: [UID:00026H] is `90/91` and emits accepted `kServerPacketNames[256][63]` plus packet log format strings; no marker-only fallback used.
- [x] Update [UID:000287] formal no-duplicate-storage proof and score. Proof: [UID:000287] is `88/91` and formal block documents the alias to [UID:00026G] constants.
- [x] Update [UID:0001P0] formal no-duplicate-global proof and score. Proof: [UID:0001P0] is `87/90` and formal block points to [UID:0000Q5] as canonical storage.
- [x] Validate every changed by-* file from `source-3/project-documentation` with scoped validator commands. Proof: all commands below used `python .\tools\validator.py --mode file --file <path> --apply --wait-generated --queue-timeout 240`, exited `0`, and reported `ok: 1`:
  - `by-file/Socket.md`: command `000000003034`, timestamp `2026-06-30T15:20:45-04:00`.
  - `by-class/Socket.md`: command `000000003036`, timestamp `2026-06-30T15:21:04-04:00`.
  - `by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md`: command `000000003038`, timestamp `2026-06-30T15:21:23-04:00`.
  - `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`: command `000000003040`, timestamp `2026-06-30T15:21:44-04:00`.
  - `by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md`: command `000000003042`, timestamp `2026-06-30T15:22:05-04:00`.
  - `by-memory/0x00574d40-0x00574e44.SendPositionUpdate.md`: command `000000003044`, timestamp `2026-06-30T15:22:25-04:00`.
  - `by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md`: command `000000003046`, timestamp `2026-06-30T15:22:43-04:00`.
  - `by-memory/0x00575370-0x00575377.GetConnectionStatus.md`: command `000000003049`, timestamp `2026-06-30T15:23:03-04:00`.
  - `by-global/g_packetSender.md`: command `000000003053`, timestamp `2026-06-30T15:23:33-04:00`.
  - `by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md`: command `000000003057`, timestamp `2026-06-30T15:24:11-04:00`.
  - `by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md`: command `000000003061`, timestamp `2026-06-30T15:24:51-04:00`.
  - `by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md`: command `000000003065`, timestamp `2026-06-30T15:25:31-04:00`.
  - `by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md`: command `000000003069`, timestamp `2026-06-30T15:26:11-04:00`.
  - `by-memory/0x00624f20-0x00625008.SocketReadOnlyData.md`: command `000000003073`, timestamp `2026-06-30T15:26:50-04:00`.
  - `by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md`: command `000000003077`, timestamp `2026-06-30T15:27:31-04:00`.
  - `by-memory/0x00670258-0x00670260.SocketConnectionStringParsePointers.md`: command `000000003081`, timestamp `2026-06-30T15:28:10-04:00`.
  - `by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md`: command `000000003084`, timestamp `2026-06-30T15:28:51-04:00`.
- [x] Run a final file validator for the root. Proof: `python .\tools\validator.py --mode file --file by-file/Socket.md --apply --wait-generated --queue-timeout 240`, command `000000003088`, timestamp `2026-06-30T15:29:34-04:00`, exit `0`, `ok: 1`, `generated_refresh: completed`.
- [x] Inspect `auto-generated/NexusTK/network/Socket.cpp` after generated refresh. Proof: generated header observed at command `000000003107`, refreshed `2026-06-30T15:33:30-04:00`, newer than final validator command `000000003088`; `Empty Emitter Marker` count is `0`, canonical `Socket *g_packetSender = nullptr;` definition count is `1`, and class `extern Socket *g_packetSender;` declaration count is `1`.
- [x] Record warnings and validator-owned side effects. Proof: scoped validators all had `generated_refresh: completed` and refreshed `auto-generated/NexusTK/network/Socket.cpp`; common unrelated warnings were existing `autogen_children_marker_missing` on Error classes. Target-specific missing-ref warnings: [UID:0000NS]/[UID:0000DD] reference missing registry UIDs `0003A6`/`0003A7`; [UID:0001HU]/[UID:0000Q5] reference missing UID `0003UT`; [UID:00026H] references missing UID `0003UU`. These were pre-existing reference-registry warnings and did not block `ok: 1`.
- [x] Release leases immediately after the edit/validator batch; confirm no active leases remain. Proof: `python .\tools\leaser\leaser.py B007 unlease ...` returned `Rejected[No active lease]` for each edited by-* file because leases had expired; current lease report has no B007 rows.
- [x] Supervisor-owned action after verification: execute/archive this report via the validator executed-report workflow; B007 did not manually edit tracker/coverage/generated state.

## Blockers

No MCP blocker remains. MCP was active, healthy, and used for current evidence.

No split UID blocker remains. No new child pages are required for this accepted-empty-family cleanup plan.

Residual source-quality caps that should not block implementation:

- Full `Socket` ABI layout is still prose-only. The lifecycle/body drafts must retain exact offset evidence and not claim a final packed header.
- Some helper names in the formal drafts are source-facing placeholders for documented helper addresses. If the callback finds existing project helper names, use the established names and record the substitution.
- The server packet table declaration name/linkage and retained debug logger policy remain inferred. This caps [UID:00026H] below final-audit quality but does not justify another fallback-only blank emitter.
- Raw command-13, raw command-14, constructor-unwind cleanup, pointer-slot storage, and duplicate sender memory storage should be formal no-code comments, not padding and not deleted.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B007","command_id":"000000004165","destination_path":"executed-b-agent-research/B007/0000NS-Socket-empty-emitter-family-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B007/research/0000NS-Socket-empty-emitter-family-source-quality.md","timestamp":"2026-06-30T15:40:59","uid":"0000NS"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
