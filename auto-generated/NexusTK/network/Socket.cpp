// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NS
// Source by-file doc: by-file/Socket.md
// UID:0000DD | by-class/Socket.md | Completion:94 | Confidence:95
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

// UID:000242 | by-memory/0x00574ae0-0x00574b83.SocketEventDispatchHelpers.md | Completion:93 | Confidence:94
void Socket::PostConnectWithFallbackCommand(char transportMode, void *connectionParameter)
{
    DispatchRequest(4,
                    static_cast<int>(static_cast<signed char>(transportMode)),
                    reinterpret_cast<int>(connectionParameter));
}

void Socket::PostConnectCommand(char transportMode, void *connectionParameter)
{
    DispatchRequest(3,
                    static_cast<int>(static_cast<signed char>(transportMode)),
                    reinterpret_cast<int>(connectionParameter));
}

void Socket::PostResetConnectionCommand()
{
    DispatchRequest(5, 0, 0);
}

HANDLE Socket::PostConnectionStatusQuery(bool *outConnected)
{
    return DispatchRequestAndReturnEvent(
        12, reinterpret_cast<int>(outConnected), 1, 0, 0);
}

void Socket::PostReconnectEndpointCommand(unsigned long hostAddress, unsigned short port)
{
    DispatchRequest(6, static_cast<int>(hostAddress), port);
}

void Socket::PostPacketTransformTableCommand(unsigned char tableMode)
{
    DispatchRequest(13, tableMode, 0);
}

// UID:0003AZ | by-memory/0x00574b90-0x00574ba4.PostSocketReceiveCommand.md | Completion:92 | Confidence:94
void Socket::PostSocketReceiveCommand(void *receiveBuffer, int receiveSize)
{
    DispatchRequest(7, reinterpret_cast<int>(receiveBuffer), receiveSize);
}

// UID:0001HU | by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md | Completion:93 | Confidence:95
void Socket::QueueAndSendPacket(const void *packetData, short packetSize)
{
    if (m_sendDisabled)
        return;

    const int copySize = static_cast<int>(packetSize);
    MemoryMan *memoryMan = GetMemoryMan();
    char *queuedPacket = static_cast<char *>(
        memoryMan->AllocateBufferMemory(copySize + 1));
    memoryMan->MemmoveWrapper(queuedPacket, packetData, copySize);
    queuedPacket[copySize] = '\0';

    DispatchRequest(8, reinterpret_cast<int>(queuedPacket), copySize + 1);
}

// UID:0003B0 | by-memory/0x00574c20-0x00574c35.PostSocketModeByteCommand.md | Completion:92 | Confidence:94
void Socket::PostSocketModeByteCommand(unsigned char mode)
{
    DispatchRequest(9, mode, 0);
}

// UID:0003B1 | by-memory/0x00574c40-0x00574ca1.QueueTransportStringCommand.md | Completion:92 | Confidence:94
void Socket::QueueTransportStringCommand(const char *text)
{
    const size_t length = strlen(text);
    MemoryMan *memoryMan = GetMemoryMan();
    char *queuedText = static_cast<char *>(
        memoryMan->AllocateBufferMemory(length + 1));
    memoryMan->MemmoveWrapper(queuedText, text, length);
    queuedText[length] = '\0';
    DispatchRequest(10, reinterpret_cast<int>(queuedText), 0);
}

// UID:0003B2 | by-memory/0x00574cb0-0x00574cc5.SendSingleByteCommand.md | Completion:92 | Confidence:94
void Socket::SendSingleByteCommand(unsigned char value)
{
    DispatchRequest(11, value, 0);
}

// UID:0003B3 | by-memory/0x00574cd0-0x00574cdb.IsSocketConnectedState.md | Completion:92 | Confidence:94
bool Socket::IsSocketConnectedState() const
{
    return m_transportMode == 5;
}

// UID:0003B4 | by-memory/0x00574ce0-0x00574cf0.SetSocketSendDisabled.md | Completion:92 | Confidence:94
void Socket::SetSocketSendDisabled(unsigned char disabled)
{
    m_sendDisabled = disabled;
}

// UID:0003B5 | by-memory/0x00574cf0-0x00574d00.SetSocketConnectionFlag.md | Completion:92 | Confidence:94
void Socket::SetSocketConnectionFlag(unsigned char value)
{
    m_connectionFlag = value;
}

// UID:0001HV | by-memory/0x00574d00-0x00574d3f.SendRawDataRaw.md | Completion:92 | Confidence:94
void Socket::QueueHandshakeBlock(unsigned int blockSize,
                                 const void *blockData)
{
    MemoryMan *memoryMan = GetMemoryMan();
    void *queuedBlock = memoryMan->AllocateBufferMemory(blockSize);
    memoryMan->MemmoveWrapper(queuedBlock, blockData, blockSize);
    DispatchRequest(14, blockSize, reinterpret_cast<int>(queuedBlock));
}

// UID:0001HW | by-memory/0x00574d40-0x00574e44.QueueClientVersionStatusPacket.md | Completion:94 | Confidence:95
void Socket::QueueClientVersionStatusPacket()
{
    unsigned char packet[7];
    unsigned short versionMajor = g_pApplication->GetVersionMajor();
    const unsigned short versionMinor = g_pApplication->GetVersionMinor();

    g_packetSequenceByte = 0;

    if (g_pConfig->m_clientVersionJitterEnabled && rand() < 0x1fff)
        --versionMajor;

    packet[0] = 0;
    packet[1] = static_cast<unsigned char>(versionMajor >> 8);
    packet[2] = static_cast<unsigned char>(versionMajor);
    packet[3] = 0xc5;
    packet[4] = static_cast<unsigned char>(versionMinor >> 8);
    packet[5] = static_cast<unsigned char>(versionMinor);
    packet[6] = static_cast<unsigned char>(g_useEpfAssets);
    QueueAndSendPacket(packet, 7);
}

// UID:0001HX | by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md | Completion:93 | Confidence:94
void Socket::BuildAndSendFriendNameListSync()
{
    unsigned char packet[1024];
    FriendNameSet countedNames;
    FriendNameSet emittedNames;

    packet[0] = 0x77;
    for (int index = 0; index < 20; ++index) {
        const WideFriendName& friendName = g_pConfig->m_friendNames[index];
        if (!friendName.empty())
            countedNames.insert(friendName);
    }

    packet[1] = static_cast<unsigned char>(countedNames.size());
    int packetSize = 2;
    packet[2] = 0;

    for (int index = 0; index < 20; ++index) {
        const WideFriendName& friendName = g_pConfig->m_friendNames[index];
        if (friendName.empty() || !emittedNames.insert(friendName).second)
            continue;

        const NarrowFriendName narrowName(friendName);
        packet[packetSize++] = 0x0c;
        GetMemoryMan()->MemmoveWrapper(
            packet + packetSize, narrowName.c_str(), 12);
        packetSize += 12;
    }

    QueueAndSendPacket(packet, static_cast<short>(packetSize));
}

// UID:0001HY | by-memory/0x00575370-0x00575377.GetConnectionStatus.md | Completion:91 | Confidence:93
unsigned char Socket::GetConnectionStatus() const
{
    return m_connectionStatus;
}



// UID:0000Q5 | by-global/g_packetSender.md | Completion:90 | Confidence:91
Socket *g_packetSender = NULL;

// UID:0001HS | by-memory/0x005747e0-0x00574ad8.SocketLifecycle.md | Completion:90 | Confidence:92
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

    g_packetTransformKeyText = static_cast<char *>(
        GetMemoryMan()->AllocateBufferMemory(0x401));

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

    if (g_packetTransformKeyText != nullptr) {
        GetMemoryMan()->FreeBufferMemory(g_packetTransformKeyText);
        g_packetTransformKeyText = nullptr;
    }

    g_packetSender = nullptr;
}

// UID:0001I3 | by-memory/0x00578b20-0x00578c40.SocketTransformFramePayload.md | Completion:89 | Confidence:91
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

    XorTransformBuffer(input + 2, output + 1, bodyLength,
                       &g_packetTransformLut[sequence], 1);

    const int stride = g_packetTransformStride;
    const int blockCount = ((bodyLength - 1) / stride) + 1;
    for (int block = 0; block < blockCount; ++block) {
        if (block != sequence) {
            const int offset = block * stride;
            const int count = std::min(stride, bodyLength - offset);
            XorTransformBuffer(output + 1 + offset, output + 1 + offset, count,
                               &g_packetTransformLut[block], 1);
        }
    }

    if (useAlternateKey) {
        XorTransformBuffer(output + 1, output + 1, bodyLength,
                           g_packetXorTableAlternate, g_packetXorAlternateSize);
    } else {
        XorTransformBuffer(output + 1, output + 1, bodyLength,
                           g_packetXorTablePrimary, g_packetTransformStride);
    }

    output[inputLength - 1] = 0;
    return inputLength - 1;
}

// UID:0001I4 | by-memory/0x00578c40-0x00578df1.SocketBuildEncryptedPacket.md | Completion:90 | Confidence:92
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
        XorTransformBuffer(input + 1, output + 2, bodyLength,
                           g_packetXorTableAlternate, g_packetXorAlternateSize);
    } else {
        XorTransformBuffer(input + 1, output + 2, bodyLength,
                           g_packetXorTablePrimary, g_packetTransformStride);
    }

    const int stride = g_packetTransformStride;
    const int blockCount = ((bodyLength - 1) / stride) + 1;
    for (int block = 0; block < blockCount; ++block) {
        if (block != sequence) {
            const int offset = block * stride;
            const int count = std::min(stride, bodyLength - offset);
            XorTransformBuffer(output + 2 + offset, output + 2 + offset, count,
                               &g_packetTransformLut[block], 1);
        }
    }

    XorTransformBuffer(output + 2, output + 2, bodyLength,
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

// UID:0001I6 | by-memory/0x005794c0-0x005794cb.ClearPacketSenderGlobal.md | Completion:87 | Confidence:93
// No standalone C++ body is emitted for 0x005794c0.
// Current MCP shows the body is exactly a constructor-unwind cleanup funclet:
// one EH tail-jump at 0x0060805e reaches it, the body ignores ECX, clears
// g_packetSender, has no callees, and has no vtable/data/pointer route.
// The source effect belongs in Socket construction/destruction, where
// g_packetSender is published and cleared, not in a callable helper API.

// UID:00026G | by-memory/0x00624f20-0x00625008.SocketReadOnlyData.md | Completion:89 | Confidence:93
namespace {
const char kDefaultSocketHandshakeSeed[] = "UrkcnItni";
const wchar_t kSocketConnectionAddressKey[] = L"CONNADDR";
const char kSocketConnectionDelimiters[] = " :,\t";
const wchar_t kSocketCopyDataTooLongMessage[] = L"Too long data in COPYDATASTRUCT";
}

// The Socket vtable bytes at 0x00624f20 are compiler-generated from the
// Socket class declaration and inherited Thread virtual order; do not emit a
// handwritten vtable object from this page.

// UID:00026H | by-memory/0x00625008-0x0062ce50.ServerPacketNameTable.md | Completion:90 | Confidence:91
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

// UID:000287 | by-memory/0x00670258-0x00670260.SocketConnectionStringParsePointers.md | Completion:88 | Confidence:91
// No separate storage definition is emitted for 0x00670258-0x00670260.
// These initialized pointer slots are the compiler/linker representation of
// Socket parser constants: kSocketConnectionAddressKey -> L"CONNADDR" and
// kSocketConnectionDelimiters -> " :,\t", both emitted with Socket read-only
// data. Current MCP confirms bytes a8 4f 62 00 / bc 4f 62 00 and the parser
// xref at 0x005778cf.

// UID:0001P0 | by-memory/0x0067a7ec-0x0067a7f0.g_packetSender.md | Completion:87 | Confidence:90
// No duplicate global definition is emitted from this exact storage page.
// [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) by-global/g_packetSender.md emits the canonical source storage:
//     Socket *g_packetSender = nullptr;
// This page documents the 0x0067a7ec zero-initialized memory slot, Socket-only
// lifetime writes, broad read fan-in, and alias rejection evidence.

// UID:0003A6 | by-memory\0x00576570-0x00576623.SocketReconnectEndpointRaw.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003A7 | by-memory\0x00577610-0x0057779e.SocketOpenSerialTransportRaw.md | Completion:85 | Confidence:88 | Empty Emitter Marker
