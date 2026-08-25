// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OL
// Source by-file doc: by-file/TextDialog.md
// UID:0000EL | by-class/TextDialog.md | Completion:90 | Confidence:93
#include "TextDialog.h"

#include "MemoryMan.h"
#include "PacketBuffer.h"
#include "Socket.h"
#include "TextEditControlPane.h"

#include <windows.h>
#include <wchar.h>


// UID:0003VR | by-memory/0x00553180-0x00553338.TextDialogHandleDialogAction.md | Completion:93 | Confidence:94
void TextDialog::OnControlCommand(int controlIndex, int /*notifyCode*/)
{
    switch (controlIndex)
    {
    case 1:
        {
            wchar_t text[256];
            char convertedText[256];
            unsigned char packet[512];

            GetChild<TextEditControlPane>(6)->ReadText(text, 255);

            MemoryMan *memoryMan = GetMemoryMan();
            const unsigned char textLength =
                static_cast<unsigned char>(wcslen(text));

            PacketBufferWriteUInt8(0x3a, packet);
            PacketBufferWriteUInt8(m_dialogType, packet + 1);
            PacketBufferWriteUInt32BE(m_dialogId, packet + 2);
            PacketBufferWriteUInt16BE(m_dialogState, packet + 6);
            PacketBufferWriteUInt16BE(
                static_cast<unsigned short>(m_dialogPageIndex + 1),
                packet + 8);
            PacketBufferWriteUInt8(2, packet + 10);

            const int convertedLength = WideCharToMultiByte(
                CP_ACP,
                0,
                text,
                textLength,
                convertedText,
                sizeof(convertedText),
                NULL,
                NULL);

            convertedText[convertedLength] = '\0';
            PacketBufferWriteUInt8(
                static_cast<unsigned char>(convertedLength),
                packet + 11);
            memoryMan->MemmoveWrapper(
                packet + 12,
                convertedText,
                convertedLength);

            const int packetLength = convertedLength + 12;
            packet[packetLength] = 0;
            g_packetSender->QueueAndSendPacket(
                packet,
                static_cast<short>(packetLength));
            CloseDialog();
        }
        break;

    case 2:
        SendPreviousDialogPacket();
        CloseDialog();
        break;

    case 3:
        SendNextDialogPacket();
        CloseDialog();
        break;

    case 4:
        SendCurrentDialogPacket();
        CloseDialog();
        break;
    }
}

// UID:0003VQ | by-memory\0x00552110-0x0055317a.TextDialogConstructor.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0003DC | by-memory\0x00622954-0x006229f0.TextDialogVtableData.md | Completion:87 | Confidence:92 | Empty Emitter Marker
