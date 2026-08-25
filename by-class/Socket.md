*** UID:0000DD | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NS | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "Socket.h"
#include "PacketTransform.h"
#include "../app/Application.h"
#include "../app/StartupWindow.h"
#include "../config/Config.h"
#include "../util/MemoryMan.h"
#include "../util/StringBase.h"

#include <set>
#include <stdlib.h>
#include <string.h>

namespace
{
typedef mystr::StringBase<wchar_t> WideFriendName;
typedef mystr::StringBase<char> NarrowFriendName;

struct WideFriendNameLess
{
    bool operator()(const WideFriendName& left,
                    const WideFriendName& right) const
    {
        return mystr::WideRangeCompare(
            left.c_str(), left.c_str() + left.length(),
            right.c_str(), right.c_str() + right.length()) < 0;
    }
};

typedef std::set<WideFriendName, WideFriendNameLess> FriendNameSet;
}

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include <winsock2.h>
#include "../util/Thread.h"

#include <windows.h>

class Socket : public Thread
{
public:
    Socket();
    virtual ~Socket();

    virtual void OnStart();
    virtual void OnIdle();
    virtual void HandleSocketCommand(int commandId, void *payload,
                                     unsigned long value);
    virtual int QueryTransportState(int query, unsigned char *outValue);
    virtual void HandleReceiveEvent(char eventCode);

    void PostConnectWithFallbackCommand(char transportMode,
                                        void *connectionParameter);
    void PostConnectCommand(char transportMode, void *connectionParameter);
    void PostResetConnectionCommand();
    HANDLE PostConnectionStatusQuery(bool *outConnected);
    void PostReconnectEndpointCommand(unsigned long hostAddress,
                                      unsigned short port);
    void PostPacketTransformTableCommand(unsigned char tableMode);
    void PostSocketReceiveCommand(void *receiveBuffer, int receiveSize);
    void QueueAndSendPacket(const void *packetData, short packetSize);
    void PostSocketModeByteCommand(unsigned char mode);
    void QueueTransportStringCommand(const char *text);
    void SendSingleByteCommand(unsigned char value);
    bool IsSocketConnectedState() const;
    void SetSocketSendDisabled(unsigned char disabled);
    void SetSocketConnectionFlag(unsigned char value);
    void QueueHandshakeBlock(unsigned int blockSize, const void *blockData);
    void QueueClientVersionStatusPacket();
    void BuildAndSendFriendNameListSync();
    unsigned char GetConnectionStatus() const;

private:
    void InitializeTransport(char transportMode, void *connectionParameter,
                             bool useFallback);
    void ResetConnectionState();
    void DispatchReceive();
    void SendEncodedPacket(const void *packetData,
                           unsigned short packetSize);
    void SendPacket(const char *text);
    void ConnectEndpoint(unsigned long hostAddress, unsigned short port,
                         bool useFallback);
    void CloseTransport();
    void ProcessQueuedReceiveBlock(void *block);
    void ProcessIncomingTransportData();
    void ReceiveNetworkData();
    int TransformFramePayload(const unsigned char *input, int inputLength,
                              unsigned char *output,
                              bool useAlternateKey);
    int BuildEncryptedPacket(const unsigned char *input, int inputLength,
                             unsigned char *output,
                             bool useAlternateKey);

    unsigned char *m_activeReadBuffer;                 // +0x00068
    unsigned char *m_alternateReadBuffer;              // +0x0006c
    unsigned char m_receiveBufferPrimary[60000];       // +0x00070
    unsigned char m_receiveBufferAlternate[60000];     // +0x0ead0
    int m_receiveByteCount;                            // +0x1d530
    int m_receiveCursor;                               // +0x1d534
    DWORD m_serialBaudRate;                            // +0x1d538
    HANDLE m_serialTransportHandle;                    // +0x1d53c
    unsigned char m_serialByteSize;                    // +0x1d540
    unsigned char m_serialParity;                      // +0x1d541
    unsigned char m_serialStopBits;                    // +0x1d542
    unsigned char m_serialFlowControl;                 // +0x1d543
    unsigned char m_serialReadActive;                  // +0x1d544
    unsigned char m_serialWriteActive;                 // +0x1d545
    unsigned char m_serialState[6];                    // +0x1d546
    OVERLAPPED m_serialReadOverlapped;                 // +0x1d54c
    OVERLAPPED m_serialWriteOverlapped;                // +0x1d560
    bool m_socketConnected;                            // +0x1d574
    SOCKET m_socket;                                   // +0x1d578
    unsigned char m_socketReadPending;                 // +0x1d57c
    unsigned char m_frameBuffer[40000];                // +0x1d57d
    int m_frameByteCount;                              // +0x271c0
    int m_frameCursor;                                 // +0x271c4
    unsigned char m_packetBuffer[40000];               // +0x271c8
    unsigned char m_encodedPacketBuffer[40000];        // +0x30e08
    unsigned char m_transportMode;                     // +0x3aa48
    unsigned char m_frameState[3];                     // +0x3aa49
    unsigned char m_protocolModeFlag;                  // +0x3aa4c
    unsigned char m_connectionFlag;                    // +0x3aa4d
    unsigned char m_sendDisabled;                      // +0x3aa4e
    unsigned char m_connectionStatus;                  // +0x3aa4f
    int m_connectionRetryDelay;                        // +0x3aa50
};

typedef char SocketSizeMustBe240212[
    sizeof(Socket) == 0x3aa54 ? 1 : -1];

*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Socket

## 2026-08-14 B003 Header/API Closure

- The complete Socket declaration moved from CPP into guarded `Socket.h`, with Thread and Win32 dependencies explicit. CPP now includes the header before children.
- `QueueAndSendPacket(const void *, short)` is the source-facing member used by both password-change sender children. The global declaration is independently appended by UID0000Q5; no free-function facade is declared.
- Existing Socket behavior, child inventory, owner, and `91/92` metadata remain unchanged.

## Status

- Confidence: strong for class responsibility and owner file.
- Historical generated alias: `class_Socket.cpp` is stale Wave3 provenance only and is not a current source-route authority. Current ownership routes through [UID:0000NS][Socket](by-file/Socket.md) under `NexusTK/network/`.
- Likely source module: [UID:0000NS][Socket](by-file/Socket.md)
- Current relevant ranges: `0x005747e0-0x00574ad8`, [UID:000242][0x00574ae0-0x00574b83.SocketEventDispatchHelpers](by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md), [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md), Socket-owned raw helper [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md), the broad reviewed aggregate [UID:0001I1][0x00575d90-0x005797ae.SocketTransportCore](by-memory/0x00575d90-0x005797ae.SocketTransportCore.md), exact raw children [UID:0003A6][0x00576570-0x00576623.SocketReconnectEndpointRaw](by-memory/0x00576570-0x00576623.SocketReconnectEndpointRaw.md) and [UID:0003A7][0x00577610-0x0057779e.SocketOpenSerialTransportRaw](by-memory/0x00577610-0x0057779e.SocketOpenSerialTransportRaw.md); `0x005967d0-0x005967e5` / `Thread::AddWaitHandle` and `0x005967f0-0x00596805` / `Thread::RemoveLastWaitHandle` are inherited [UID:0000OR][Thread](by-file/Thread.md) infrastructure used by Socket serial setup/cleanup.
- Evidence basis: `simroot_v2` generated source, Wave3 metadata/xrefs, and IDA MCP lookup/xref checks on 2026-05-23.

## Responsibility

`Socket` is the stateful client transport class. It wraps the thread/message command interface used by queued request senders, owns the small command-posting helpers around `0x00574ae0-0x00574d3f`, manages TCP and alternate serial/dispatch transports, parses incoming frames, transforms packet payloads, and performs final outbound framing and writes.

2026-06-30 B007 implementation callback raised this class page from `88/88` to `90/89` after adding declarations required by accepted formal method bodies while preserving `[[CHILDREN]]`. The declarations remain source-facing reconstructions: command-post helpers are Socket-owned wrappers over inherited Thread dispatch primitives, and transform helper names still depend on prose-level support docs rather than a recovered complete header.

IDA MCP evidence from 2026-05-25 and the B003 2026-06-17 lifecycle pass make Socket the lifetime owner for [UID:0000Q5][g_packetSender](by-global/g_packetSender.md): the constructor writes the global, the normal destructor clears it, the constructor unwind helper [UID:0001I6][0x005794c0-0x005794cb.ClearPacketSenderGlobal](by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md) clears it on failure, and the scalar deleting destructor clears it from the vtable path. The current best source-facing pointer type is `Socket *`; generated `CashShopRequest*` aliases remain stale search/provenance only unless a future recovered header proves a narrow sender interface.

## Class And Vtable Shape

The class declaration models `Socket` as deriving from [UID:0000EV][Thread](by-class/Thread.md). Its first Socket-specific entries at inherited slots `+0x14` and `+0x28` are overrides of `Thread::OnStart()` and `Thread::OnIdle()`, not new Socket-only virtuals. `NoOpVirtualHook` and `PollAndReceive` remain useful historical/behavior aliases for searching older reports, but they are not current source declarations. Other inherited Thread entries remain Thread/common behavior and should not be re-owned by Socket support pages merely because the Socket table references them.

Socket vtable range [UID:00026G][0x00624f20-0x00625008.SocketReadOnlyData](by-memory/0x00624f20-0x00625008.SocketReadOnlyData.md) maps to:

| Slot | Target | Best role |
| ---: | --- | --- |
| 0 | `0x005795a0` | Socket scalar deleting destructor. |
| 1 | `0x004f4b10` | Inherited/common object descriptor helper. |
| 2 | `0x0041b6c0` | `nullsub_18`, no-op `retn 8`. |
| 3 | `0x00596540` | Thread shutdown/wait helper. |
| 4 | `0x005965c0` | Thread terminate helper. |
| 5 | `0x00575d90` | `Socket::OnStart()` empty override; inherited Thread slot `+0x14`, called by `Thread::StartThread` before `ResumeThread`. |
| 6 | `0x0041b6a0` | Inherited `Thread::OnThreadBegin()` folded empty body. |
| 7 | `0x00596810` | Inherited `ThreadProc`. |
| 8 | `0x0041b6a0` | Inherited `Thread::OnThreadEnd()` folded empty body. |
| 9 | `0x0041b6a0` | Inherited `Thread::OnDispatchBegin()` folded empty body. |
| 10 | `0x00575da0` | `Socket::OnIdle()` override; nonblocking transport polling after every non-stopping worker wait iteration. Historical behavior alias: `PollAndReceive`. |
| 11 | `0x00575e60` | `Socket::HandleSocketCommand`. |
| 12 | `0x00576200` | `Socket::QueryTransportState`. |
| 13 | `0x00576250` | `Socket::HandleReceiveEvent`. |

## Field And Type Findings

The following field names are current high-probability source-facing names. Keep the exact offset layout in prose for now; do not encode a synthetic complete ABI layout until a layout-specific implementation pass validates packing and inherited fields.

| Offset | Recommended name | Evidence and notes |
| ---: | --- | --- |
| `+0x68` | `m_activeReadBuffer` | Primary pointer passed to overlapped/serial `ReadFile`; the constructor allocates the backing buffer family. |
| `+0x6c` | `m_alternateReadBuffer` | Paired read-buffer pointer. |
| `+0x70` | `m_receiveBufferPrimary` | First 60000-byte receive buffer allocation. |
| `+0xead0` | `m_receiveBufferAlternate` | Second 60000-byte receive buffer allocation. |
| `+0x1d530` | `m_receiveByteCount` | Reset by reconnect with the receive counters. |
| `+0x1d534` | `m_receiveCursor` | Reset by reconnect; paired with receive byte count. |
| `+0x1d53c` | `m_serialTransportHandle` | COM/alternate transport handle opened by the raw serial helper and closed by `CloseTransport`. |
| `+0x1d543` | `m_serialClosing` / `m_serialCancelPending` | Cleared by `CloseTransport`; exact original name remains weaker than surrounding fields. |
| `+0x1d544` | `m_serialReadActive` | Set around overlapped reads and cleared by `CloseTransport`. |
| `+0x1d54c` | `m_serialReadOverlapped` | `OVERLAPPED` block used by serial read path. |
| `+0x1d55c` | `m_serialReadEvent` | Event handle added to the inherited Thread wait-handle array. |
| `+0x1d574` | `m_socketConnected` | Winsock connection-state boolean. |
| `+0x1d578` | `m_socket` | Winsock socket handle, initialized to invalid and closed during teardown. |
| `+0x1d57d` | `m_frameBuffer` | 40000-byte frame scratch allocation. |
| `+0x271c0` | `m_frameByteCount` | Reset by reconnect. |
| `+0x271c4` | `m_frameCursor` | Reset by reconnect. |
| `+0x271c8` | `m_packetBuffer` | Second 40000-byte packet/frame scratch allocation. |
| `+0x3aa48` | `m_transportMode` | Mode byte: mode `5` is Winsock/TCP, mode `6` is callback/window-message dispatch, lower modes are COM/serial. |
| `+0x3aa49..+0x3aa4b` | `m_frameState` bytes | Reset by reconnect and initialized with `+0x3aa4c`; keep prose-only until parser state names are validated. |
| `+0x3aa4c` | `m_protocolModeFlag` | Command `9` writes this byte; `SendEncodedPacket` branches on binary/text framing. |
| `+0x3aa4d` | `m_connectionFlag` | Explicit connection-flag setter writes this byte. |
| `+0x3aa4e` | `m_sendDisabled` | Queue/send helpers test it as a disable flag; setter writes this byte. |
| `+0x3aa4f` | `m_connectionStatus` | Returned by `GetConnectionStatus`; callers compare it for UI/gate logic. |
| `+0x3aa50` | `m_connectionRetryDelay` / `m_mode5TriggerCount` | Constructor initializes to `10`; exact name remains weaker than adjacent fields. |

Rejected field alternatives: `m_connectionState` is too broad for `+0x3aa48` because the byte selects transport mode, not merely connected/disconnected state. `m_isConnected` is rejected for `+0x3aa4d` because `+0x1d574` is the Winsock connected flag and `+0x3aa4d` is written by a distinct connection-flag setter. `m_sendPacketFlag` is rejected for `+0x3aa4e`; direct send helpers test it as a disable flag, so `m_sendDisabled` is the better source-facing name.

## Socket Command IDs

`Socket::HandleSocketCommand` consumes the command IDs posted by the helper family around `0x00574ae0-0x00574d3f`:

| Command | Producer/helper | Consumer behavior | Source-facing recommendation |
| ---: | --- | --- | --- |
| `3` | `0x00574b00` | `InitializeTransport(..., false)` route. | `Socket::PostConnectCommand` |
| `4` | `0x00574ae0` | `InitializeTransport(..., true)` route. | `Socket::PostConnectWithFallbackCommand` |
| `5` | `0x00574b20` | Reset/close connection state. | `Socket::PostResetConnectionCommand` |
| `6` | `0x00574b50` | Reset and call endpoint connect path. | `Socket::PostReconnectEndpointCommand` |
| `7` | `0x00574b90` | Receive dispatch path. | `Socket::PostSocketReceiveCommand` |
| `8` | `0x00574bb0` and packet-building callers | Send encoded packet, then free queued copy. | `Socket::QueueAndSendPacket` |
| `9` | `0x00574c20` | Write `m_protocolModeFlag`. | `Socket::PostSocketModeByteCommand` |
| `10` | `0x00574c40` | Send queued C string via `SendPacket`, then free. | `Socket::QueueTransportStringCommand` |
| `11` | `0x00574cb0` | Send one byte through the active transport. | `Socket::SendSingleByteCommand` |
| `12` | `0x00574b30` | Event-backed connection/transport availability query; callers wait on the returned event and read the caller-provided boolean. | `Socket::PostConnectionStatusQuery(bool *outConnected)`; preserve `Socket::QueryTransportState` as the vtable consumer at `0x00576200`. |
| `13` | raw `0x00574b70` | Transform/LUT setup command. | `Socket::PostPacketTransformTableCommand`; no direct callers found. |
| `14` | raw `0x00574d00` | Calls the handshake/seed block builder with queued bytes. | Prefer `Socket::QueueHandshakeBlock`; reject `SendRawData` as a final name. |

## Raw Helper Liveness And Source Policy

Raw helper direct-route evidence remains part of the liveness record. It does not automatically suppress an intact function-shaped source body when ownership and consumer semantics are closed:

- `0x00574d00-0x00574d3f`: no IDA function, direct call, pointer ref, or rel32 route was found. The exact body posts command `14`, and `Socket::HandleSocketCommand` uniquely consumes the queued size/buffer through the handshake/seed builder. The accepted retained source is `QueueHandshakeBlock`; the negative route is historical evidence, not an emission blocker.
- `0x00576570-0x00576623`: no direct calls and no real pointer refs. Apparent byte-pattern hits at `0x0066bce3` and `0x0066be08` are unaligned bytes inside import-name strings ending in `...TypeW` (`GetStringTypeW`, `GetDriveTypeW`), so they are rejected as pointer evidence. The role remains `Socket::ReconnectEndpoint`; C++ stays blank until retained-support/source-route policy is accepted.
- `0x00577610-0x0057779e`: no direct calls and no pointer refs. The body formats narrow `"COM%d"` and opens through an indirect CreateFile-like pointer, so documentation should say likely ANSI/indirect CreateFile-like route rather than proven `CreateFileW`. The role remains `Socket::OpenSerialTransport`; C++ stays blank until retained-support/source-route policy is accepted.

The class declaration and child source include `QueueHandshakeBlock`. The separate `ReconnectEndpoint` and `OpenSerialTransport` raw children retain their own current dispositions; this callback does not infer new bodies for them.

## Important Methods

| Address | Current name | Notes |
| --- | --- | --- |
| `0x005747e0` | `Socket` | Initializes `Thread`, handshake/key state, receive/frame buffers, mode defaults, `g_packetSender`, and optional mode-6 dispatch startup. |
| `0x005749e0` | `~Socket` | Closes Winsock/transport handles, sends mode-6 disconnect notifications, releases process argument/key buffer, and tears down base thread. |
| [UID:000242][0x00574ae0-0x00574b83.SocketEventDispatchHelpers](by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md) | Socket command-post helpers | Posts Socket command IDs `3`, `4`, `5`, `6`, source-facing `Socket::PostConnectionStatusQuery(bool *outConnected)` for command `0x0c` / 12, and raw unreferenced command `0x0d` through inherited `Thread` queue/event helpers. |
| [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md) | `QueueAndSendPacket` | Copies caller packet bytes, appends a zero byte, and posts command `8`; `HandleSocketCommand` case `8` sends and frees the copied payload. |
| [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md) | `QueueHandshakeBlock` retained raw body | Exact Socket command-14 allocate-copy-dispatch source; zero route evidence is preserved as liveness history. |
| `0x00575d90` | `OnStart` | One-byte empty override of inherited `Thread::OnStart`; its vtable position and `StartThread` call establish the source contract. Historical `NoOpVirtualHook` is a behavior-only alias. |
| `0x00575da0` | `OnIdle` | Override of inherited `Thread::OnIdle`; performs nonblocking `select` polling and transport-specific receive dispatch after each non-stopping worker wait iteration. Historical `PollAndReceive` is a descriptive behavior alias. |
| `0x00575e60` | `HandleSocketCommand` | Thread command dispatcher for connect, reset, receive, encoded send, raw send, transform-table setup, and handshake setup. |
| `0x00576290` | `InitializeTransport` | Selects TCP mode 5, mode 6 dispatch transport, or COM/serial transport. |
| [UID:0003A6][0x00576570-0x00576623.SocketReconnectEndpointRaw](by-memory/0x00576570-0x00576623.SocketReconnectEndpointRaw.md) | raw `ReconnectEndpoint` body | Source-authored raw Socket helper that closes old socket/transport state, clears frame/transform state, calls `ConnectEndpoint`, and sleeps after reconnect. |
| `0x00576660` | `SendEncodedPacket` | Final packet framing/encoding path before Winsock, callback dispatch, or serial write. |
| `0x00576d90` | `SendPacket` | Sends an already formatted text packet/string through the active transport. |
| `0x00577140` | `ConnectEndpoint` | Winsock connection setup, async select, and fallback handling. |
| [UID:0003A7][0x00577610-0x0057779e.SocketOpenSerialTransportRaw](by-memory/0x00577610-0x0057779e.SocketOpenSerialTransportRaw.md) | raw `OpenSerialTransport` body | Source-authored raw Socket helper that opens/configures a `COM%d` transport handle, registers wait/event state, and starts an overlapped read. |
| `0x00577b00` | `ProcessQueuedReceiveBlock` | Mode-6 receive-block path. |
| `0x00577f40` | `ProcessIncomingTransportData` | Non-TCP/non-mode-6 receive path. |
| `0x00578240` | `ReceiveNetworkData` | Winsock receive path. |
| `0x00578980` | `ParseFramePayload` | Decodes incoming frame payload bytes. |
| `0x00578b20` | `TransformFramePayload` | Applies packet transform table logic; see [UID:0001I3][0x00578b20-0x00578c40.SocketTransformFramePayload](by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md). |
| `0x00578c40` | `BuildEncryptedPacket` | Builds encrypted/transformed outbound payloads; see [UID:0001I4][0x00578c40-0x00578df1.SocketBuildEncryptedPacket](by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md). |
| `0x005794c0` | `ClearPacketSenderGlobal` | Constructor-unwind cleanup funclet that clears `g_packetSender`; not a public/private Socket method and not a vtable slot. The only route is the EH tail-jump at `0x0060805e` after `ECX` is adjusted to `this+0x68`. Formal C++ for this exact helper remains blank; the effect belongs in Socket lifetime source. |
| `0x005795a0` | `ScalarDeletingDestructor` | Vtable deleting destructor path that mirrors teardown and clears `g_packetSender`. B012's [UID:000245][0x00578f70-0x005797ae.StlTreeStringMapSupport](by-memory/0x00578f70-0x005797ae.StlTreeStringMapSupport.md) routing pass confirms the exact body is `0x005795a0-0x005796c7` inside a mixed support tail but belongs to Socket ABI destructor generation, not STL helper code; a later exact child/no-code page may split it. |
| `0x005967d0` | inherited `Thread::AddWaitHandle` call | Stale generated Socket-owned row; current IDA evidence says the helper itself is base `Thread` infrastructure, called from serial transport setup. |
| `0x005967f0` | inherited `Thread::RemoveLastWaitHandle` tail route | Socket `CloseTransport` reaches this base helper by tail jump at `0x00577aef` after closing/clearing the serial handle. It is cleanup caller evidence, not Socket ownership of the helper. |

## Transport Modes

Current generated source suggests:

- Mode `5`: Winsock/TCP path using configured server IP/port offsets and async select.
- Mode `6`: callback/dispatch transport using a configured callback target and message IDs such as `74`, `1052`, `1053`, `1985`, and `1986`.
- Other low modes: COM/serial transport using a narrow `COM%d` string and likely ANSI/indirect CreateFile-like pointer, followed by `SetupComm`, `PurgeComm`, `SetCommTimeouts`, `ReadFile`, `WriteFile`, and overlapped events.

## Packet Encoding

`SendEncodedPacket` has two outbound formats:

- Binary frame format for `m_protocolModeFlag == 0`: optional transform/encryption, frame prefix `0xaa`, two-byte big-endian length, then payload.
- Text line format otherwise: optional transform/encryption, chunks encoded into `*`/`+` line records with sequence digits, comma continuation, and period final marker.

The packet buffer helper functions are separate utilities documented under [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md).

## Ownership Notes

- `Socket` should own transport handles, receive buffers, frame buffers, encryption/transform state, and transport callback state.
- `Socket` should own the lifetime of `g_packetSender`; current generated `CashShopRequest*` uses are queue/send call-site typing evidence, not global ownership evidence.
- `Socket` owns the complete `0x00574ae0-0x00575377` command-post and packet-builder corridor: [UID:000242][0x00574ae0-0x00574b83.SocketEventDispatchHelpers](by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md), [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md), command wrappers [UID:0003B0][0x00574c20-0x00574c35.PostSocketModeByteCommand](by-memory/0x00574c20-0x00574c35.PostSocketModeByteCommand.md), [UID:0003B1][0x00574c40-0x00574ca1.QueueTransportStringCommand](by-memory/0x00574c40-0x00574ca1.QueueTransportStringCommand.md), [UID:0003B2][0x00574cb0-0x00574cc5.SendSingleByteCommand](by-memory/0x00574cb0-0x00574cc5.SendSingleByteCommand.md), accessors/setters [UID:0003B3][0x00574cd0-0x00574cdb.IsSocketConnectedState](by-memory/0x00574cd0-0x00574cdb.IsSocketConnectedState.md), [UID:0003B4][0x00574ce0-0x00574cf0.SetSocketSendDisabled](by-memory/0x00574ce0-0x00574cf0.SetSocketSendDisabled.md), [UID:0003B5][0x00574cf0-0x00574d00.SetSocketConnectionFlag](by-memory/0x00574cf0-0x00574d00.SetSocketConnectionFlag.md), retained [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md), [UID:0001HW][0x00574d40-0x00574e44.QueueClientVersionStatusPacket](by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md), and [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md).
- `Socket` should not own high-level feature packet builders.
- `Socket` owns the stateful encode/decode methods `SendEncodedPacket`, `SendPacket`, `ProcessQueuedReceiveBlock`, `ProcessIncomingTransportData`, `ReceiveNetworkData`, `ParseFramePayload`, `TransformFramePayload`, and `BuildEncryptedPacket`. Reusable free transform helpers and globals remain under [UID:0000M9][PacketTransform](by-file/PacketTransform.md) / [UID:0000TG][PacketTransformGlobals](by-global/PacketTransformGlobals.md), and scalar big-endian helpers remain in [UID:0000M8][PacketBuffer](by-file/PacketBuffer.md).
- `Socket` owns the source semantics for the scalar deleting destructor selected by vtable slot `0x00624f20`; source should declare/define `virtual ~Socket()` and let the compiler regenerate the deleting wrapper. The physical wrapper body at `0x005795a0-0x005796c7` must not be modeled as part of a source-authored STL helper module.
- Socket serial setup/cleanup consumes inherited Thread secondary-wait helpers: setup calls [UID:0001JZ][0x005967d0-0x005967e5.ThreadAddWaitHandleHelper](by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md), and cleanup tail-jumps to `Thread::RemoveLastWaitHandle()` at `0x00577aef`. Keep both helpers with [UID:0000OR][Thread](by-file/Thread.md).

Command `12` is source-facing as `Socket::PostConnectionStatusQuery(bool *outConnected)`. B001 2026-06-25 MCP `1005-1015` confirms the wrapper at `0x00574b30` posts command `0x0c` through `Thread::DispatchRequestAndReturnEvent`, callers pass a boolean output pointer and later wait with `Thread::WaitForResult`, `Socket::HandleSocketCommand` does not consume command `12` in the async switch, and the vtable consumer remains `Socket::QueryTransportState` at `0x00576200`. This rejects target-local `PostReconnectResultRequest`, direct `QueryTransportState` calls from packet helpers, and overloading the separate immediate `IsSocketConnectedState` helper at `0x00574cd0`.

## Assignment Decision

`AUTOGEN_PARENT_UID` remains [UID:0000NS][Socket](by-file/Socket.md). The class is `94/95`; the complete corridor, exact `0x3aa54` field layout, and source-closed CPP/H package emit through that single owner.

## Score Rationale

- Completion `94`: class responsibility, source module, full lifecycle/transport/send/receive/transform families, the complete command corridor, exact `0x3aa54` field layout, source dependencies, formal CPP/H, `g_packetSender` ownership, vtable contract, and raw-helper histories are closed.
- Confidence `95`: live IDA, exact offsets/sizes, caller/consumer evidence, source dependencies, and existing support pages agree on Socket ownership and ABI layout. Remaining uncertainty is limited to inferred human spellings for a small number of internal fields.

## Open Questions

- The complete x86 layout is now formalized through `sizeof(Socket) == 0x3aa54`; six internal field names remain evidence-bounded human inferences and are not blockers.
- Current source-facing type for [UID:0000Q5][g_packetSender](by-global/g_packetSender.md): best modeled as `Socket *` based on Socket-only lifetime writes and Socket command consumers. Generated `CashShopRequest*` references are stale aliases unless future header evidence proves an explicit sender interface.
- Packet transform helpers/globals remain in the separate [UID:0000M9][PacketTransform](by-file/PacketTransform.md) owner; Socket consumes its header declarations.
- `QueueHandshakeBlock` is emitted under the accepted retained-source rule. `ReconnectEndpoint` and `OpenSerialTransport` remain governed by their separate child evidence and are not changed by UID0000MV.

## Cross-References

- [UID:0000NS][Socket](by-file/Socket.md)
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
- [UID:00001H][CashShopRequest](by-class/CashShopRequest.md)
- [UID:0001QH][client_network](by-meta/client_network.md)

## DialDialog Serial-Connect Parameter Clarification - 2026-07-29

- Commands 3 and 4 carry a transport mode plus one mode-dependent dword/pointer payload. `connectionParameter` is the bounded source-facing name: TCP/IP modes can interpret it as endpoint-related data, while serial callers use the same channel for a configured baud-rate dword.
- [UID:0004YD][0x0058d750-0x0058d9e2.DialDialogConstructor](by-memory/0x0058d750-0x0058d9e2.DialDialogConstructor.md) passes `g_pConfig->m_startupConnectionMode` and the terminal baud-rate value before queuing `ATX3DT`. TerminalPane setup callers use the same serial interpretation. This caller evidence rejects a globally endpoint-specific parameter name.
- The formal declarations now use `void *connectionParameter` for both posting helpers and `InitializeTransport`. The type remains the existing generic pointer-sized transport parameter because the binary helper is shared across modes; this callback does not invent a serial-only helper, overload, or new binary function.
- [UID:000242][0x00574ae0-0x00574b83.SocketEventDispatchHelpers](by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md) owns the exact command-posting bodies. DialDialog remains a caller, not a Socket owner or emitter.

## 2026-08-17 B003 UID0000MV Accepted Callback

- Raised `91/92` to `94/95` and closed the full Socket `0x3aa54` x86 object layout, including both 60,000-byte receive buffers, both 40,000-byte frame/packet buffers, transport handles/state, exact late status bytes, and compile-time size assertion.
- Formal CPP now declares every concrete dependency used by child source: PacketTransform, Application, StartupWindow, Config, MemoryMan, StringBase, ordered friend-name sets, CRT random/string support, and then `[[CHILDREN]]` in owner order.
- Formal H preserves every existing API, adds commands 7/9/13/14, and corrects `TransformFramePayload` to return `int`. The sole `g_packetSender` extern is appended by [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), avoiding a duplicate class/global declaration. The complete `0x00574ae0-0x00575377` corridor remains Socket-owned; no ProtocolSend class, namespace, header, or source is introduced.
- UID0001HV's raw-start route remains negative history, but its intact command-14 body now emits as `QueueHandshakeBlock`. UID0001HW is `QueueClientVersionStatusPacket`, and UID0001HX preserves exact two-pass first-occurrence friend-name serialization.

## Changes

- 2026-08-17 B003 UID0000MV accepted callback: completed Socket CPP/H dependency, API, field-layout, and corridor ownership closure at `94/95`; the final physical-header readback also removed the class-local duplicate `g_packetSender` extern because UID0000Q5 already emits the canonical declaration.

- 2026-08-01 B008 accepted ThreadProc support incorporation:
  - Changed `COMPLETION:90` / `CONFIDENCE:89` to `91/92` and corrected formal declarations from `NoOpVirtualHook` / `PollAndReceive` to inherited overrides `OnStart` / `OnIdle`.
  - Replaced generic guard/no-op vtable descriptions with the complete Thread-derived slot contract and documented `0x00575d90` as the empty startup override and `0x00575da0` as the nonblocking idle-poll override.
  - Preserved `NoOpVirtualHook` and `PollAndReceive` only as historical/behavior aliases; no binary body, field layout, owner/emitter route, raw-helper policy, or child ownership changed.
- 2026-07-29 B006 UID0001JG callback: renamed the generic connect payload spelling from `endpointData` to `connectionParameter` in class formals and documented mode-dependent endpoint/serial-baud interpretation from DialDialog and TerminalPane callers without changing helper ownership or inventing a binary function.

- 2026-06-25 B001 LegacyMainMenuPacket command-12 sync:
  - Score unchanged at `88/88`.
  - Summary/evidence: added declaration-level `HANDLE PostConnectionStatusQuery(bool *outConnected)` and synchronized the command ID map with accepted B001 current MCP/correction evidence. The wrapper posts event-backed command `0x0c` / 12 through inherited `Thread::DispatchRequestAndReturnEvent`, callers wait through `Thread::WaitForResult`, and `Socket::QueryTransportState` remains the vtable consumer at `0x00576200`. The accepted name reflects reusable connection/transport availability call sites and rejects a target-local reconnect-result name.

- 2026-06-20 B003 Thread dispatch helper support update:
  - Added Socket cleanup caller evidence for `Thread::RemoveLastWaitHandle()` at tail jump `0x00577aef` and clarified that both add/remove wait-handle helpers remain inherited base `Thread` infrastructure, not Socket-owned source.
- 2026-06-20 B006 Rule 26 source-quality incorporation:
  - Changed completion/confidence from `86/85` to `88/88`, added declaration-level first-draft C++ with `[[CHILDREN]]`, and incorporated vtable slots, field-name recommendations, command ID names, raw-helper route negatives, `QueueHandshakeBlock` naming, and the Socket/Thread/PacketTransform/PacketBuffer/CashShopRequest boundaries.
  - Evidence: B006 raw PE route scans found no direct rel32 routes to `0x00574d00`, `0x00576570`, or `0x00577610`; rejected apparent `0x00576570` pointer hits as unaligned import-string bytes; confirmed 489 `g_packetSender` refs and Socket-only writes; confirmed `0x005967d0` has only Socket setup/serial-open callers while remaining Thread-owned; and tied vtable slots/command consumers back to `Socket::HandleSocketCommand`.
- 2026-06-11 A003 Batch188 command-posting ownership refresh:
  - Before: the class documented Socket lifecycle/transport ownership but did not list the `0x00574ae0-0x00574d3f` queue-posting helper cluster as Socket-owned.
  - After: the page records Socket ownership for [UID:000242][0x00574ae0-0x00574b83.SocketEventDispatchHelpers](by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md) and [UID:0001HU][0x00574bb0-0x00574c13.QueueAndSendPacket](by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md), keeps [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md) as a likely Socket raw helper but unassigned, and clarifies that `Thread` owns the queue primitives rather than the Socket command wrappers.
  - Evidence: live IDA MCP decompiled `Socket::HandleSocketCommand` at `0x00575e60`; its switch consumes command IDs `3`, `4`, `5`, `6`, `8`, `13`, and `14`, matching the helper cluster around `0x00574ae0-0x00574d3f`.
- 2026-06-17 B003 Socket lifecycle source-quality pass:
  - Before: the class still described [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md) as likely raw/unassigned and kept the packet sender type open between Socket/request aliases.
  - After: [UID:0001HV][0x00574d00-0x00574d3f.SendRawDataRaw](by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md) is Socket-owned by best-defensible semantic evidence with raw-start reachability caveat preserved, and [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) is modeled as high-probability `Socket *` source-facing storage.
  - Evidence: B003 live IDA review linked Socket-only global writes, command case `14`, command-post helper structure, and real `g_pCashShopRequest` separation.
- 2026-06-18 B003 ClearPacketSenderGlobal source-quality pass:
  - Before: the method inventory could still read as if `0x005794c0` were a small Socket helper.
  - After: the row explicitly classifies [UID:0001I6][0x005794c0-0x005794cb.ClearPacketSenderGlobal](by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md) as constructor-unwind cleanup only, not a Socket method or vtable slot; the 2026-06-30 callback later added a formal no-code proof on that support page.
  - Evidence: B003 raw PE/Capstone recheck found the sole EH tail-jump at `0x0060805e`, `ECX=this+0x68` setup, no callees, zero pointer/table refs, and the direct `g_packetSender` clear.
- 2026-06-11 A002 Batch190 raw transport split:
  - Added exact raw child pages [UID:0003A6][0x00576570-0x00576623.SocketReconnectEndpointRaw](by-memory/0x00576570-0x00576623.SocketReconnectEndpointRaw.md) and [UID:0003A7][0x00577610-0x0057779e.SocketOpenSerialTransportRaw](by-memory/0x00577610-0x0057779e.SocketOpenSerialTransportRaw.md) as Socket-owned source-authored methods.
  - Evidence: live IDA MCP reports no function objects/xrefs at the raw starts, but disassembly shows coherent Socket reconnect and COM/serial-open method bodies bounded by `0xcc` alignment and surrounded by modeled Socket transport methods.
- 2026-06-05: Changed `RECONSTRUCTABLE` from blank to `TRUE` and assigned parent `0000NS`.
  - Before: The stateful transport class remained unclassified in autogen coverage even though the class and parent file both met the 80/80 attach gate.
  - After: The class contributes to `Socket.cpp` as a reconstructable child without emitting final C++ yet.
  - Evidence: Live IDA MCP lookup confirms Socket lifecycle, command, transport, send/receive, transform, cleanup, and scalar-deleting starts from `0x005747e0` through `0x005795a0`; the inherited wait-handle helper at `0x005967d0` remains documented as base `Thread` infrastructure, not Socket-owned source.

- 2026-06-02 `0x005967d0` ownership update:
  - What existed before: the page listed `QueueThreadEvent` as a Socket method and left an open question about whether it was truly Socket-owned.
  - Changed to: the helper is described as inherited base `Thread` infrastructure called by Socket serial setup.
  - Summary/evidence: [UID:0001JZ][0x005967d0-0x005967e5.ThreadAddWaitHandleHelper](by-memory/0x005967d0-0x005967e5.ThreadAddWaitHandleHelper.md) now records IDA MCP lookup/decompile/disassembly/caller/callee/xref/raw-byte evidence for the Thread wait-handle append helper.
- Before: completion/confidence were unevaluated at `0/0`.
- Changed to: completion `86`, confidence `82`.
- Evidence: the page documents responsibility, owner file, major transport ranges, important methods, transport modes, packet encoding, `g_packetSender` ownership, and subsystem cross-references; confidence remains capped by open field naming and helper/source split questions.
- 2026-06-10 A001 strict gate repair:
  - Changed confidence from `82` to `85`.
  - Summary/evidence: the Socket file parent now scores `90/89`, while this class page documents the transport responsibility, lifecycle, command/send/receive/transform method families, `g_packetSender` lifetime ownership, and inherited Thread helper exclusion. Formal C++ now emits the declaration plus `[[CHILDREN]]`; class fields, exact sender interface type, and packet-transform placement remain below final-source confidence.
