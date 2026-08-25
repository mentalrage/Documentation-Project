// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LA
// Source by-file doc: by-file/MessageDialogs.md
// UID:000084 | by-class/Message.md | Completion:88 | Confidence:90
typedef unsigned int MessageType;

enum MessageEntryType {
    MessageEntryType_Dword0 = 0,
    MessageEntryType_Dword1 = 1,
    MessageEntryType_Word2 = 2,
    MessageEntryType_Word3 = 3,
    MessageEntryType_Byte4 = 4,
    MessageEntryType_Byte5 = 5,
    MessageEntryType_DwordPair6 = 6,
    MessageEntryType_RectBounds7 = 7,
    MessageEntryType_Dword8 = 8,
    MessageEntryType_Dword9 = 9,
    MessageEntryType_WideString = 10,
    MessageEntryType_Blob = 11
};

struct MessageEntry {
    unsigned int type;
    wchar_t key[0x40];
    unsigned int sequence;
    union {
        unsigned int dwordValue;
        unsigned short wordValue;
        unsigned char byteValue;
        struct {
            unsigned int first;
            unsigned int second;
        } dwordPair;
        unsigned char rectBounds[0x10];
        void *pointerValue;
        struct {
            unsigned int length;
            wchar_t *text;
        } wideString;
        struct {
            unsigned int length;
            void *bytes;
        } blob;
    } payload;
};

class Message : public LObject
{
public:
    explicit Message(MessageType messageType);
    virtual ~Message();

protected:
    MessageType m_type;
    SortedList *m_entries;
};

// UID:0002Y5 | by-memory/0x00520e30-0x00521d94.MessageCore.md | Completion:88 | Confidence:90
// Message method behavior for this exact range is documented here, but the source-facing Message declaration is emitted by [UID:000084][Message](by-class/Message.md). Constructor/destructor/helper bodies remain deferred until exact raw-helper child splits and source names are accepted.

// UID:0000BE | by-class/PursuitMessageDialogPane.md | Completion:92 | Confidence:94
#include "PursuitMessageDialogPane.h"

#include "Event.h"
#include "ObjectStatusBlob.h"
#include "PacketBuffer.h"
#include "Socket.h"

// UID:0001FE | by-memory/0x0054cab0-0x0054cae9.PursuitMessageDialogPaneConstructor.md | Completion:92 | Confidence:94
PursuitMessageDialogPane::PursuitMessageDialogPane()
    : DialogPane(L"", 1, 1)
{
}

// UID:0001FF | by-memory/0x0054caf0-0x0054cc2f.MessageDialogObjectResponseVirtual.md | Completion:94 | Confidence:95
bool PursuitMessageDialogPane::HandlePacketEvent(Event *event)
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

// UID:0001FG | by-memory/0x0054cc30-0x0054ce0f.DialogNavigationPacketHelpers.md | Completion:92 | Confidence:94
void PursuitMessageDialogPane::SendPreviousDialogPacket()
{
    unsigned char packet[11];
    PacketBufferWriteUInt8(0x3a, packet);
    PacketBufferWriteUInt8(m_dialogType, packet + 1);
    PacketBufferWriteUInt32BE(m_dialogId, packet + 2);
    PacketBufferWriteUInt16BE(m_dialogState, packet + 6);
    PacketBufferWriteUInt16BE(
        static_cast<unsigned short>(m_dialogPageIndex - 1),
        packet + 8);
    packet[10] = 0;
    g_packetSender->QueueAndSendPacket(packet, 10);
}

void PursuitMessageDialogPane::SendNextDialogPacket()
{
    unsigned char packet[11];
    PacketBufferWriteUInt8(0x3a, packet);
    PacketBufferWriteUInt8(m_dialogType, packet + 1);
    PacketBufferWriteUInt32BE(m_dialogId, packet + 2);
    PacketBufferWriteUInt16BE(m_dialogState, packet + 6);
    PacketBufferWriteUInt16BE(
        static_cast<unsigned short>(m_dialogPageIndex + 1),
        packet + 8);
    packet[10] = 0;
    g_packetSender->QueueAndSendPacket(packet, 10);
}

void PursuitMessageDialogPane::SendCurrentDialogPacket()
{
    unsigned char packet[11];
    PacketBufferWriteUInt8(0x3a, packet);
    PacketBufferWriteUInt8(m_dialogType, packet + 1);
    PacketBufferWriteUInt32BE(m_dialogId, packet + 2);
    PacketBufferWriteUInt16BE(m_dialogState, packet + 6);
    PacketBufferWriteUInt16BE(m_dialogPageIndex, packet + 8);
    packet[10] = 0;
    g_packetSender->QueueAndSendPacket(packet, 10);
}

// UID:0002OM | by-memory/0x00622424-0x006224c0.PursuitMessageDialogPaneVtableData.md | Completion:86 | Confidence:91
// PursuitMessageDialogPane vtable data is source-declared/generated-binary output from the class declaration and shared virtual interface; do not hand-port .rdata bytes as handwritten source.


// UID:0003IQ | by-memory/0x0061e8ec-0x0061e8fc.PursuitMessageDialogCreatorVtableData.md | Completion:92 | Confidence:94
class PursuitMessageDialogCreator : public LObject
{
public:
    void CreateDialog(const unsigned char *packet);
};

typedef char PursuitMessageDialogCreatorSizeMustBe4[
    sizeof(PursuitMessageDialogCreator) == 4 ? 1 : -1];

// UID:00007Z | by-class/MenuQuestionItemList.md | Completion:86 | Confidence:88
struct MenuQuestionOptionRow
{
    unsigned char optionId;
    unsigned char reserved;
    wchar_t label[0x100];
};

class MenuQuestionItemList : public ListPane
{
public:
    explicit MenuQuestionItemList(MenuQuestionDialog *ownerDialog);
    virtual void ConfirmSelection();
    virtual void DrawRow(const MenuQuestionOptionRow *row, const RectBounds *bounds, bool selected);

private:
    MenuQuestionDialog *m_ownerDialog;
};





// UID:00023M | by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md | Completion:92 | Confidence:94
enum MessageDialogFactorySubtype {
    kMessageDialogWithText = 0,
    kMessageDialogWithoutText = 1,
    kMenuQuestionDialogWithText = 2,
    kMenuQuestionDialogWithoutText = 3,
    kTextDialogWithObject = 4,
    kTextDialogPlain = 5,
    kTextDialogLargeWithObject = 7,
    kTextDialogLargePlain = 8,
    kNexonclubProxyDialog = 9,
    kHeadSelectDialog = 10
};

namespace {

DialogPane *CreateMessageDialog(const unsigned char *payload, bool hasText, bool largerLayout)
{
    if (largerLayout)
        return new MessageDialogLarger(payload, hasText);
    return new MessageDialog(payload, hasText);
}

DialogPane *CreateMenuQuestionDialog(const unsigned char *payload, bool hasDescriptionText, bool largerLayout)
{
    if (largerLayout)
        return new MenuQuestionDialogLarger(payload, hasDescriptionText);
    return new MenuQuestionDialog(payload, hasDescriptionText);
}

} // namespace

void PursuitMessageDialogCreator::CreateDialog(const unsigned char *packet)
{
    const unsigned char selector = packet[1];
    const unsigned char subtype = selector & 0x0f;
    const bool largerLayout = (selector & 0x10) != 0;
    const unsigned char *payload = packet + 2;

    switch (subtype) {
    case kMessageDialogWithText:
        CreateMessageDialog(payload, true, largerLayout);
        break;
    case kMessageDialogWithoutText:
        CreateMessageDialog(payload, false, largerLayout);
        break;
    case kMenuQuestionDialogWithText:
        CreateMenuQuestionDialog(payload, true, largerLayout);
        break;
    case kMenuQuestionDialogWithoutText:
        CreateMenuQuestionDialog(payload, false, largerLayout);
        break;
    case kTextDialogWithObject:
        new TextDialog(payload, true, false);
        break;
    case kTextDialogPlain:
        new TextDialog(payload, false, false);
        break;
    case kTextDialogLargeWithObject:
        new TextDialog(payload, true, true);
        break;
    case kTextDialogLargePlain:
        new TextDialog(payload, false, true);
        break;
    case kNexonclubProxyDialog:
        new NexonclubProxyDialog(payload);
        break;
    case kHeadSelectDialog:
        new HeadSelectDialog(payload);
        break;
    default:
        break;
    }
}

DialogPane *CreateMessageDialogWithText(const unsigned char *payload)
{
    return new MessageDialog(payload, true);
}

DialogPane *CreateMessageDialogWithoutText(const unsigned char *payload)
{
    return new MessageDialog(payload, false);
}

DialogPane *CreateMessageDialogLargerWithText(const unsigned char *payload)
{
    return new MessageDialogLarger(payload, true);
}

DialogPane *CreateMessageDialogLargerWithoutText(const unsigned char *payload)
{
    return new MessageDialogLarger(payload, false);
}

DialogPane *CreateMenuQuestionDialogWithText(const unsigned char *payload)
{
    return new MenuQuestionDialog(payload, true);
}

DialogPane *CreateMenuQuestionDialogWithoutText(const unsigned char *payload)
{
    return new MenuQuestionDialog(payload, false);
}

DialogPane *CreateMenuQuestionDialogLargerWithText(const unsigned char *payload)
{
    return new MenuQuestionDialogLarger(payload, true);
}

DialogPane *CreateMenuQuestionDialogLargerWithoutText(const unsigned char *payload)
{
    return new MenuQuestionDialogLarger(payload, false);
}

DialogPane *CreateTextDialogWithObject(const unsigned char *payload)
{
    return new TextDialog(payload, true, false);
}

DialogPane *CreateTextDialogPlain(const unsigned char *payload)
{
    return new TextDialog(payload, false, false);
}

DialogPane *CreateTextDialogLargeWithObject(const unsigned char *payload)
{
    return new TextDialog(payload, true, true);
}

DialogPane *CreateTextDialogLargePlain(const unsigned char *payload)
{
    return new TextDialog(payload, false, true);
}

DialogPane *CreateNexonclubProxyDialog(const unsigned char *payload)
{
    return new NexonclubProxyDialog(payload);
}

DialogPane *CreateHeadSelectDialog(const unsigned char *payload)
{
    return new HeadSelectDialog(payload);
}

// UID:000080 | by-class/MenuQuestionItemListLarger.md | Completion:87 | Confidence:89
class MenuQuestionItemListLarger : public ListPane
{
public:
    explicit MenuQuestionItemListLarger(MenuQuestionItemList *pairedList);
    virtual void ConfirmSelection();
    virtual void DrawRow(const MenuQuestionOptionRow *row, const RectBounds *bounds, bool selected);

private:
    MenuQuestionItemList *m_pairedList;
};





// UID:000085 | by-class/MessageDialog.md | Completion:87 | Confidence:89
class MessageDialog : public PursuitMessageDialogPane
{
public:
    MessageDialog(const unsigned char *packet, bool hasText);
    virtual bool OnButtonAction(int actionId);
};




// UID:000086 | by-class/MessageDialogLarger.md | Completion:88 | Confidence:90
class MessageDialogLarger : public PursuitMessageDialogPane
{
public:
    MessageDialogLarger(const unsigned char *packet, bool hasText);
    virtual bool OnButtonAction(int actionId);
};




// UID:00007X | by-class/MenuQuestionDialog.md | Completion:87 | Confidence:89
class MenuQuestionDialog : public PursuitMessageDialogPane
{
public:
    MenuQuestionDialog(const unsigned char *packet, bool hasDescriptionText);
    virtual bool OnButtonAction(int actionId, int unused);
    virtual void UpdateConfirmButtonState();
};





// UID:00007Y | by-class/MenuQuestionDialogLarger.md | Completion:86 | Confidence:88
class MenuQuestionDialogLarger : public PursuitMessageDialogPane
{
public:
    MenuQuestionDialogLarger(const unsigned char *packet, bool hasDescriptionText);
    virtual bool OnButtonAction(int actionId);
    virtual void UpdateConfirmButtonState();
};

// UID:0001YI | by-type\by-vtable\PursuitMessageDialogPaneVtables.md | Completion:90 | Confidence:94 | Empty Emitter Marker

// UID:0003W8 | by-memory\0x00550d50-0x00550db4.MenuQuestionItemListConstructor.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003WB | by-memory\0x00550e30-0x00550e3b.MenuQuestionItemListConfirmSelection.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003WC | by-memory\0x00550e40-0x00550ec1.MenuQuestionItemListDrawRow.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003D6 | by-memory\0x00622730-0x006227f4.MenuQuestionItemListVtableData.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0003WD | by-memory\0x00550ed0-0x00550f1f.MenuQuestionItemListLargerConstructor.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003WG | by-memory\0x00550f90-0x00550f9b.MenuQuestionItemListLargerConfirmSelection.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003WH | by-memory\0x00550fa0-0x00551021.MenuQuestionItemListLargerDrawRow.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003D8 | by-memory\0x006227f4-0x006228b8.MenuQuestionItemListLargerVtableData.md | Completion:87 | Confidence:92 | Empty Emitter Marker

// UID:0003VY | by-memory\0x0054ce10-0x0054db3e.MessageDialogConstructor.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003VZ | by-memory\0x0054db40-0x0054db8b.MessageDialogActionHandler.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0003D1 | by-memory\0x006224c0-0x0062255c.MessageDialogVtableData.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0003G8 | by-memory\0x0054db90-0x0054e8c7.MessageDialogLargerConstructor.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003G9 | by-memory\0x0054e8d0-0x0054e91b.MessageDialogLargerActionHandler.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0003D2 | by-memory\0x0062255c-0x006225f8.MessageDialogLargerVtableData.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0003W0 | by-memory\0x0054e920-0x0054f8dd.MenuQuestionDialogConstructor.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003W1 | by-memory\0x0054f8e0-0x0054fa10.MenuQuestionDialogActionHandler.md | Completion:88 | Confidence:91 | Empty Emitter Marker

// UID:0003W2 | by-memory\0x0054fa20-0x0054fa5d.MenuQuestionDialogUpdateConfirmButtonState.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003D3 | by-memory\0x006225f8-0x00622694.MenuQuestionDialogVtableData.md | Completion:87 | Confidence:92 | Empty Emitter Marker

// UID:0003W4 | by-memory\0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003W5 | by-memory\0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md | Completion:88 | Confidence:91 | Empty Emitter Marker

// UID:0003W6 | by-memory\0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003D4 | by-memory\0x00622694-0x00622730.MenuQuestionDialogLargerVtableData.md | Completion:87 | Confidence:92 | Empty Emitter Marker

// UID:0003DD | by-memory\0x006229f0-0x00622c54.DlgmsgResourceStrings.md | Completion:86 | Confidence:91 | Empty Emitter Marker
