// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LZ
// Source by-file doc: by-file/NexonclubProxyDialog.md
// UID:00009H | by-class/NexonclubProxyDialog.md | Completion:91 | Confidence:94
#include <string.h>
#include <windows.h>

#include "FunctionObjects.h"
#include "MessageDialogs.h"
#include "NexonclubRegistrationDialog.h"
#include "ObjectStatusBlob.h"
#include "PacketBuffer.h"
#include "Socket.h"
#include "StringBase.h"

namespace
{
class NexonclubProxyDialog : public PursuitMessageDialogPane
{
public:
    explicit NexonclubProxyDialog(unsigned char *packet);

private:
    void OnReplyText(const StringBaseW& text);
};

// UID:0003GL | by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md | Completion:90 | Confidence:94
void NexonclubProxyDialog::OnReplyText(const StringBaseW& text)
{
    if (text.empty()) {
        SendCurrentDialogPacket();
        CloseDialog();
        return;
    }

    unsigned char packet[0x200];
    int packetLength = 0;

    PacketBufferWriteUInt8(0x3a, packet + packetLength);
    packetLength += 1;

    PacketBufferWriteUInt8(m_dialogType, packet + packetLength);
    packetLength += 1;

    PacketBufferWriteUInt32BE(m_dialogId, packet + packetLength);
    packetLength += 4;

    PacketBufferWriteUInt16BE(m_dialogState, packet + packetLength);
    packetLength += 2;

    PacketBufferWriteUInt16BE(m_dialogPageIndex + 1, packet + packetLength);
    packetLength += 2;

    PacketBufferWriteUInt8(2, packet + packetLength);
    packetLength += 1;

    PacketBufferAppendWideStringAsAnsi8(text.c_str(), packet, &packetLength);

    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(packet, static_cast<unsigned short>(packetLength));

    CloseDialog();
}

// UID:0001FK | by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md | Completion:92 | Confidence:94
NexonclubProxyDialog::NexonclubProxyDialog(unsigned char *packet)
    : PursuitMessageDialogPane()
{
    ObjectStatusBlob objectStatus;

    m_dialogType = packet[0];
    m_dialogId = PacketBufferReadUInt32BE(packet + 1);

    if (packet[5] == 2)
        packet[6] = 2;

    objectStatus.m_displayStatusByte = 0x50;

    int statusBytes = objectStatus.ParseTaggedStatus(packet + 6);
    if (statusBytes < 0)
        return;

    unsigned char *cursor = packet + statusBytes + 10;

    m_dialogState = PacketBufferReadUInt16BE(cursor);
    cursor += 2;

    m_dialogPageIndex = PacketBufferReadUInt16BE(cursor);
    cursor += 2;

    unsigned char dialogWidthByte = *cursor++;
    unsigned char dialogHeightByte = *cursor++;
    (void)dialogWidthByte;
    (void)dialogHeightByte;

    unsigned short messageLength = PacketBufferReadUInt16BE(cursor);
    cursor += 2;

    char messageBytes[0x8000];
    wchar_t messageText[0x8000];
    memmove(messageBytes, cursor, messageLength);
    cursor += messageLength;
    messageBytes[messageLength] = '\0';

    int messageChars = MultiByteToWideChar(
        0,
        0,
        messageBytes,
        messageLength,
        messageText,
        _countof(messageText));
    messageText[messageChars] = L'\0';

    unsigned char firstButtonLength = *cursor++;
    char buttonBytes[0x8000];
    wchar_t firstButtonText[256];
    memmove(buttonBytes, cursor, firstButtonLength);
    cursor += firstButtonLength;
    buttonBytes[firstButtonLength] = '\0';

    int firstButtonChars = MultiByteToWideChar(
        0,
        0,
        buttonBytes,
        firstButtonLength,
        firstButtonText,
        _countof(firstButtonText));
    firstButtonText[firstButtonChars] = L'\0';

    unsigned char unusedButtonSeparator = *cursor++;
    (void)unusedButtonSeparator;

    unsigned char secondButtonLength = *cursor++;
    wchar_t secondButtonText[256];
    memmove(buttonBytes, cursor, secondButtonLength);
    buttonBytes[secondButtonLength] = '\0';

    int secondButtonChars = MultiByteToWideChar(
        0,
        0,
        buttonBytes,
        secondButtonLength,
        secondButtonText,
        _countof(secondButtonText));
    secondButtonText[secondButtonChars] = L'\0';

    FunctionObjectT<const StringBaseW&> *callback =
        new PlainMemberFunctionObjectT<NexonclubProxyDialog, const StringBaseW&>(
            this,
            &NexonclubProxyDialog::OnReplyText);

    new NexonclubRegistrationDialog(messageText, callback);
}

}

// UID:0003DE | by-memory\0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData.md | Completion:88 | Confidence:92 | Empty Emitter Marker
