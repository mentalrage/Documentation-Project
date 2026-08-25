// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000L9
// Source by-file doc: by-file/MerchantDialogPane.md
// UID:000083 | by-class/MerchantDialogPane.md | Completion:94 | Confidence:94
#include "MerchantDialogPane.h"

#include "Event.h"
#include "ObjectStatusBlob.h"
#include "PacketBuffer.h"
#include "Socket.h"

// UID:00041Q | by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md | Completion:89 | Confidence:90
MerchantDialogPane::MerchantDialogPane(unsigned char menuDialogType)
    : DialogPane(L"", 1, 1),
      m_menuDialogType(menuDialogType)
{
}

// UID:0001BM | by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md | Completion:94 | Confidence:95
bool MerchantDialogPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);

    if (packet[0] == '/')
        return true;

    if (packet[0] != '0')
        return false;

    ObjectStatusBlob objectStatus;
    objectStatus.m_displayStatusByte = 0x50;

    const unsigned char responseType = packet[2];
    const unsigned int objectId = PacketBufferReadUInt32BE(packet + 3);
    const unsigned char reserved = packet[7];
    (void)reserved;

    short trailerOffset = 8;
    const int statusLength = objectStatus.ParseTaggedStatus(packet + 8);
    if (statusLength >= 0)
        trailerOffset = static_cast<short>(statusLength + 8);
    trailerOffset = static_cast<short>(trailerOffset + 4);

    const unsigned short responseValue1 =
        PacketBufferReadUInt16BE(packet + trailerOffset);
    const unsigned short responseValue2 =
        PacketBufferReadUInt16BE(packet + static_cast<short>(trailerOffset + 2));

    unsigned char response[256];
    PacketBufferWriteUInt8(0x3a, response);
    PacketBufferWriteUInt8(responseType, response + 1);
    PacketBufferWriteUInt32BE(objectId, response + 2);
    PacketBufferWriteUInt16BE(responseValue1, response + 6);
    PacketBufferWriteUInt16BE(responseValue2, response + 8);
    response[10] = 0;

    g_packetSender->QueueAndSendPacket(response, 10);
    return true;
}

// UID:0004H8 | by-memory/0x00517ec0-0x00517f26.MerchantDialogPaneSendMenuRequestPacket.md | Completion:94 | Confidence:94
void MerchantDialogPane::SendMenuRequestPacket()
{
    unsigned char packet[6];
    PacketBufferWriteUInt8(0x43, packet);
    PacketBufferWriteUInt8(1, packet + 1);
    PacketBufferWriteUInt32BE(m_menuObjectId, packet + 2);
    g_packetSender->QueueAndSendPacket(packet, sizeof(packet));
    CloseDialog();
}
