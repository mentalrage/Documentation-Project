// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OP
// Source by-file doc: by-file/TextMenuDialogs.md
// UID:000238 | by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md | Completion:94 | Confidence:94
#include "TextMenuDialogs.h"

#include "ArgumentedMenuDialogs.h"
#include "ItemMenuDialogs.h"
#include "SpellMenuDialogs.h"
#include "../controls/ListPane.h"
#include "../controls/TextEditControlPane.h"
#include "../core/ControlPane.h"
#include "../core/DialogPane.h"
#include "../core/RectBounds.h"
#include "../../map/ObjectStatusBlob.h"
#include "../../network/PacketBuffer.h"
#include "../../network/Socket.h"
#include "../../util/StringBase.h"

#include <cstring>
#include <cwchar>
#include <windows.h>

enum MerchantMenuDialogSubtype {
    kTextMenu = 0,
    kTextMenuWithExtraString = 1,
    kTextInputMenu = 2,
    kTextInputMenuWithExtraString = 3,
    kServerItemMenu = 4,
    kClientItemMenu = 5,
    kServerSpellMenu = 6,
    kClientSpellMenu = 8,
    kArgumentedItemMenu = 10
};

namespace {

void InitDlgMerc1Bounds(RectBounds *bounds)
{
    InitRectBounds(bounds, 100, 100, 416, 455);
}

void InitDlgMerc2Bounds(RectBounds *bounds)
{
    InitRectBounds(bounds, 100, 100, 416, 328);
}

void InitCenteredMerchantDialogBounds(RectBounds *bounds)
{
    InitRectBounds(bounds, 160, 20, 480, 420);
}

} // namespace

void CreateMerchantMenuDialog(const unsigned char *packet)
{
    const unsigned char subtype = packet[1];
    const unsigned char *payload = packet + 2;
    RectBounds bounds;

    switch (subtype) {
    case kTextMenu:
        InitDlgMerc1Bounds(&bounds);
        new TextMenuDialog(false, bounds, payload, 0);
        break;
    case kTextMenuWithExtraString:
        InitDlgMerc1Bounds(&bounds);
        new TextMenuDialog(true, bounds, payload, 0);
        break;
    case kTextInputMenu:
        InitDlgMerc2Bounds(&bounds);
        new TextInputMenuDialog(false, bounds, payload, 2);
        break;
    case kTextInputMenuWithExtraString:
        InitDlgMerc2Bounds(&bounds);
        new TextInputMenuDialog(true, bounds, payload, 2);
        break;
    case kServerItemMenu:
        InitDlgMerc1Bounds(&bounds);
        bounds.right = bounds.left + 425;
        bounds.bottom = bounds.top + 354;
        new ServerItemMenuDialog(bounds, payload, 0);
        break;
    case kClientItemMenu:
        InitDlgMerc1Bounds(&bounds);
        new ClientItemMenuDialog(bounds, payload, 0);
        break;
    case kServerSpellMenu:
        InitDlgMerc1Bounds(&bounds);
        new ServerSpellMenuDialog(bounds, payload, 0);
        break;
    case kClientSpellMenu:
        InitDlgMerc1Bounds(&bounds);
        new ClientSpellMenuDialog(bounds, payload, 0);
        break;
    case kArgumentedItemMenu:
        InitDlgMerc1Bounds(&bounds);
        new ArgumentedMenuMenuDialog(bounds, payload, 0);
        break;
    }
}

DialogPane *CreateTextMenuDialog(const unsigned char *payload)
{
    RectBounds bounds;
    InitDlgMerc1Bounds(&bounds);
    return new TextMenuDialog(false, bounds, payload, 0);
}

DialogPane *CreateTextMenuDialogWithExtraString(const unsigned char *payload)
{
    RectBounds bounds;
    InitDlgMerc1Bounds(&bounds);
    return new TextMenuDialog(true, bounds, payload, 0);
}

DialogPane *CreateTextInputMenuDialog(const unsigned char *payload)
{
    RectBounds bounds;
    InitDlgMerc2Bounds(&bounds);
    return new TextInputMenuDialog(false, bounds, payload, 2);
}

DialogPane *CreateTextInputMenuDialogWithExtraString(const unsigned char *payload)
{
    RectBounds bounds;
    InitDlgMerc2Bounds(&bounds);
    return new TextInputMenuDialog(true, bounds, payload, 2);
}

DialogPane *CreateServerItemMenuDialog(const unsigned char *payload)
{
    RectBounds bounds;
    InitDlgMerc1Bounds(&bounds);
    bounds.right = bounds.left + 425;
    bounds.bottom = bounds.top + 354;
    return new ServerItemMenuDialog(bounds, payload, 0);
}

DialogPane *CreateClientItemMenuDialog(const unsigned char *payload)
{
    RectBounds bounds;
    InitDlgMerc1Bounds(&bounds);
    return new ClientItemMenuDialog(bounds, payload, 0);
}

DialogPane *CreateServerSpellMenuDialog(const unsigned char *payload)
{
    RectBounds bounds;
    InitDlgMerc1Bounds(&bounds);
    return new ServerSpellMenuDialog(bounds, payload, 0);
}

DialogPane *CreateClientSpellMenuDialog(const unsigned char *payload)
{
    RectBounds bounds;
    InitDlgMerc1Bounds(&bounds);
    return new ClientSpellMenuDialog(bounds, payload, 0);
}

DialogPane *CreateArgumentedMenuDialog(const unsigned char *payload)
{
    RectBounds bounds;
    InitDlgMerc1Bounds(&bounds);
    return new ArgumentedMenuMenuDialog(bounds, payload, 0);
}

// UID:0000ES | by-class/TextMenuDialog.md | Completion:94 | Confidence:94
namespace {

class TextMenuPayloadReader {
public:
    explicit TextMenuPayloadReader(const unsigned char *payload)
        : m_cursor(payload)
    {
    }

    unsigned char ReadUInt8()
    {
        return *m_cursor++;
    }

    unsigned short ReadUInt16()
    {
        const unsigned short value = PacketBufferReadUInt16BE(m_cursor);
        m_cursor += 2;
        return value;
    }

    unsigned int ReadUInt32()
    {
        const unsigned int value = PacketBufferReadUInt32BE(m_cursor);
        m_cursor += 4;
        return value;
    }

    bool ReadObjectStatus(ObjectStatusBlob *status)
    {
        status->m_displayStatusByte = 0x50;
        const int length = status->ParseTaggedStatus(m_cursor);
        if (length < 0)
            return false;
        m_cursor += length + 4;
        return true;
    }

    void ReadAnsi16(wchar_t *out, unsigned int outCount)
    {
        const unsigned short length = ReadUInt16();
        char text[32768];
        memcpy(text, m_cursor, length);
        m_cursor += length;
        text[length] = '\0';
        const int count = MultiByteToWideChar(
            CP_ACP, 0, text, length, out, outCount - 1);
        out[count] = L'\0';
    }

    void ReadAnsi8(wchar_t *out, unsigned int outCount)
    {
        const unsigned char length = ReadUInt8();
        char text[256];
        memcpy(text, m_cursor, length);
        m_cursor += length;
        text[length] = '\0';
        const int count = MultiByteToWideChar(
            CP_ACP, 0, text, length, out, outCount - 1);
        out[count] = L'\0';
    }

    void ReadWideString8(
        mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> > *out)
    {
        wchar_t text[256];
        ReadAnsi8(text, 256);
        *out = text;
    }

private:
    const unsigned char *m_cursor;
};

} // namespace

// UID:0004HB | by-memory/0x00519110-0x0051920c.TextMenuDialogRawSelectionReplySerializer.md | Completion:94 | Confidence:94
void TextMenuDialog::SendMenuReply(unsigned short optionIndex)
{
    unsigned char packet[0x100];
    int cursor = 0;

    PacketBufferAppendUInt8(0x39, packet, &cursor);
    PacketBufferAppendUInt8(m_replyType, packet, &cursor);
    PacketBufferAppendUInt32BE(m_menuObjectId, packet, &cursor);
    PacketBufferAppendUInt16BE(m_itemIds[optionIndex], packet, &cursor);

    if (m_hasExtraString) {
        PacketBufferAppendAnsiString8(
            m_extraString.c_str(), packet, &cursor);
    }

    packet[cursor] = 0;
    g_packetSender->QueueAndSendPacket(
        packet, static_cast<short>(cursor));
}

// UID:0004H9 | by-memory/0x00517f30-0x00518e17.TextMenuDialogConstructor.md | Completion:94 | Confidence:94
TextMenuDialog::TextMenuDialog(bool hasExtraString,
                               const RectBounds& dialogBounds,
                               const unsigned char *payload,
                               unsigned char merchantDialogType)
    : MerchantDialogPane(merchantDialogType),
      m_replyType(0),
      m_itemCount(0),
      m_hasExtraString(hasExtraString),
      m_extraString()
{
    TextMenuPayloadReader reader(payload);
    ObjectStatusBlob objectStatus;
    wchar_t prompt[32768];

    m_replyType = reader.ReadUInt8();
    m_menuObjectId = reader.ReadUInt32();
    if (!reader.ReadObjectStatus(&objectStatus))
        return;
    reader.ReadAnsi16(prompt, 32768);
    if (m_hasExtraString)
        reader.ReadWideString8(&m_extraString);
    m_itemCount = reader.ReadUInt8();

    TextMenuItemList *list =
        new TextMenuItemList(m_replyType, m_menuObjectId, this);

    if (g_useEpfAssets) {
        AddImageControl(RectBounds(0, 0, 315, 353),
                        L"DLGMERC1.EPF", 0, L"PA");
        AddButtonControl(RectBounds(44, 310, 107, 334), 14);
        AddButtonControl(RectBounds(121, 310, 184, 334), 16);
        AddButtonControl(RectBounds(198, 310, 261, 334), 15);
        AddObjectImageControl(RectBounds(20, 20, 94, 128), objectStatus);
        AddStaticTextControl(RectBounds(105, 40, 276, 128),
                             prompt, true, 128, 143);

        for (unsigned int i = 0; i < m_itemCount; ++i) {
            wchar_t label[256];
            reader.ReadAnsi8(label, 256);
            const unsigned short itemId = reader.ReadUInt16();
            if (i < 6)
                m_itemIds[i] = itemId;
            list->AddTextEntry(itemId, label);
        }

        AddListControl(RectBounds(36, 144, 294, 288), list);
        SetFocusedControl(6);
        SetDefaultControl(1);
        SetPendingControl(3);
        StoreClampRect(&dialogBounds);
        SetBackgroundResource(L"DLGMERC1.EPF", 0);
    } else if (m_itemCount <= 6) {
        AddButtonControl(
            RectBounds(92, 18 * m_itemCount + 192,
                       164, 18 * m_itemCount + 208), 16);
        AddButtonControl(
            RectBounds(169, 18 * m_itemCount + 192,
                       241, 18 * m_itemCount + 208), 15);
        AddObjectImageControl(RectBounds(60, 38, 97, 93), objectStatus);
        AddStaticTextControl(RectBounds(129, 36, 273, 132),
                             prompt, true, 128, 143);

        for (unsigned int i = 0; i < m_itemCount; ++i) {
            wchar_t label[256];
            reader.ReadAnsi8(label, 256);
            m_itemIds[i] = reader.ReadUInt16();
            AddTextButtonControl(
                RectBounds(86, 18 * i + 154,
                           255, 18 * i + 172), label);
        }

        RectBounds smallBounds(
            dialogBounds.left, dialogBounds.top,
            dialogBounds.left + 432,
            dialogBounds.top + 18 * (m_itemCount + 19));
        StoreClampRect(&smallBounds);
        SetDefaultControl(1);
        SetFocusedControl(1);
    } else {
        AddImageControl(RectBounds(0, 0, 314, 356),
                        L"DLGMERC1.EPD", 0, L"NP");
        AddButtonControl(RectBounds(44, 306, 116, 322), 14);
        AddButtonControl(RectBounds(121, 306, 193, 322), 16);
        AddButtonControl(RectBounds(198, 306, 270, 322), 15);
        AddObjectImageControl(RectBounds(35, 37, 72, 92), objectStatus);
        AddStaticTextControl(RectBounds(122, 37, 266, 133),
                             prompt, true, 128, 143);

        for (unsigned int i = 0; i < m_itemCount; ++i) {
            wchar_t label[256];
            reader.ReadAnsi8(label, 256);
            const unsigned short itemId = reader.ReadUInt16();
            list->AddTextEntry(itemId, label);
        }

        AddListControl(RectBounds(36, 141, 278, 285), list);
        SetFocusedControl(6);
        SetDefaultControl(1);
        SetPendingControl(3);
        StoreClampRect(&dialogBounds);
        SetBackgroundResource(L"DLGMERC1.EPD", 0);
    }

    SetMode(1);
    OnCreate(&dialogBounds, 0, 0, g_dialogLayer);
    OnShow(0, g_pBackPane);
}

// UID:0004HA | by-memory/0x00518e20-0x00519102.TextMenuDialogOnPaint.md | Completion:94 | Confidence:94
void TextMenuDialog::OnPaint()
{
    if (g_useEpfAssets)
        return;

    RectBounds top;
    RectBounds middle;
    RectBounds buttonTop;
    RectBounds buttonMiddle;
    RectBounds buttonBottom;
    RectBounds bottom;

    m_shouldFillBackground = false;
    SetTextColor(0);
    DrawCurrentPaneFrame(m_clientRect);
    SetTextColor(128);

    LoadEpdFrame(g_dialogTiles, L"MERTOP.EPD", 0, top);
    LoadEpdFrame(g_dialogTiles, L"MERMID.EPD", 0, middle);
    LoadEpdFrame(g_dialogTiles, L"MERBTOP.EPD", 0, buttonTop);
    LoadEpdFrame(g_dialogTiles, L"MERBUT.EPD", 0, buttonMiddle);
    LoadEpdFrame(g_dialogTiles, L"MERBBOT.EPD", 0, buttonBottom);
    LoadEpdFrame(g_dialogTiles, L"MERBOT.EPD", 0, bottom);

    const int npImage = FindImageResource(g_imageLibrary, L"NP");
    RectBounds dst(0, 0, 332, 100);
    DrawEpdFrame(top, dst, npImage);
    dst.Offset(0, 100);
    dst.SetVerticalFrom(middle.top, middle.bottom + 18);
    DrawEpdFrame(middle, dst, npImage);
    dst.Offset(0, 18);
    DrawEpdFrame(middle, dst, npImage);
    dst.SetVerticalFrom(buttonTop.top, buttonTop.bottom);
    DrawEpdFrame(buttonTop, dst, npImage);
    dst.SetVerticalFrom(buttonMiddle.top, buttonMiddle.bottom);

    for (unsigned int i = 0; i < m_itemCount; ++i) {
        dst.Offset(0, 18);
        DrawEpdFrame(buttonMiddle, dst, npImage);
    }

    dst.Offset(0, 18);
    dst.SetVerticalFrom(buttonBottom.top, buttonBottom.bottom);
    DrawEpdFrame(buttonBottom, dst, npImage);
    dst.Offset(0, 18);
    dst.SetVerticalFrom(bottom.top, bottom.bottom + 70);
    DrawEpdFrame(bottom, dst, npImage);
}

// UID:0004HC | by-memory/0x00519210-0x005194b1.TextMenuDialogOnDialogAction.md | Completion:94 | Confidence:94
void TextMenuDialog::OnControlCommand(int controlIndex, int notifyCode)
{
    (void)controlIndex;

    if (m_itemCount <= 6 && !g_useEpfAssets) {
        if (notifyCode == 0) {
            SendMenuRequestPacket();
            return;
        }
        if (notifyCode == 1 || notifyCode < 4)
            return;
        SendMenuReply(static_cast<unsigned short>(notifyCode - 4));
        CloseDialog();
        return;
    }

    if (notifyCode == 1) {
        TextMenuItemList *list = GetChild<TextMenuItemList>(6);
        list->SendSelectedTextMenuReply();
        CloseDialog();
    } else if (notifyCode == 2) {
        SendMenuRequestPacket();
    } else if (notifyCode == 3) {
        CloseDialog();
    }
}

// UID:0004HD | by-memory/0x005194c0-0x00519511.TextMenuDialogUpdateScrollButtons.md | Completion:94 | Confidence:94
void TextMenuDialog::UpdateActionButton()
{
    if (m_itemCount <= 6 && !g_useEpfAssets)
        return;

    ControlPane *okButton = GetChild<ControlPane>(1);
    TextMenuItemList *list = GetChild<TextMenuItemList>(6);
    if (list->GetSelectionCount() > 0)
        okButton->Activate();
    else
        okButton->Deactivate();
}

// UID:0000ET | by-class/TextMenuItemList.md | Completion:94 | Confidence:94
struct TextMenuItemListEntry {
    unsigned short itemId;
    wchar_t label[256];
};

typedef char TextMenuItemListEntrySizeMustBe514[
    (sizeof(TextMenuItemListEntry) == 0x202) ? 1 : -1];

class TextMenuItemList : public ListPane
{
public:
    TextMenuItemList(unsigned char menuType,
                     unsigned int menuId,
                     TextMenuDialog *ownerDialog);

    void AddTextEntry(unsigned short itemId, const wchar_t *label);
    void SendSelectedTextMenuReply();

protected:
    virtual void OnItemActivated();
    virtual void DrawListEntry(int rowIndex, void *rowData,
                               RectBounds *rowBounds);

private:
    void SendTextMenuReply(unsigned short itemId);

    unsigned char m_menuType;              // +0x14c
    unsigned char m_reserved14d[3];
    unsigned int m_menuId;                 // +0x150
    TextMenuDialog *m_ownerDialog;         // +0x154, non-owning
};

typedef char TextMenuItemListSizeMustBe344[
    (sizeof(TextMenuItemList) == 0x158) ? 1 : -1];

TextMenuItemList::TextMenuItemList(unsigned char menuType,
                                   unsigned int menuId,
                                   TextMenuDialog *ownerDialog)
    : ListPane(sizeof(TextMenuItemListEntry), 16, 228, 12, 0, 1, 1),
      m_menuType(menuType),
      m_menuId(menuId),
      m_ownerDialog(ownerDialog)
{
}

void TextMenuItemList::AddTextEntry(unsigned short itemId,
                                    const wchar_t *label)
{
    TextMenuItemListEntry entry;
    entry.itemId = itemId;
    wcscpy_s(entry.label, 256, label);
    AddEntry(&entry);
}

// UID:0004HE | by-memory/0x005195f0-0x0051971d.TextMenuItemListRawSelectedRowReplySerializer.md | Completion:93 | Confidence:94
void TextMenuItemList::SendSelectedTextMenuReply()
{
    if (m_selectedIndex < 0)
        return;

    const TextMenuItemListEntry *entry =
        static_cast<const TextMenuItemListEntry *>(GetItem(m_selectedIndex));

    SendTextMenuReply(entry->itemId);
}

// UID:0004HF | by-memory/0x00519720-0x0051983a.TextMenuItemListRawExplicitIdReplySerializer.md | Completion:93 | Confidence:94
void TextMenuItemList::SendTextMenuReply(unsigned short itemId)
{
    unsigned char packet[0x100];
    int cursor = 0;

    PacketBufferAppendUInt8(0x39, packet, &cursor);
    PacketBufferAppendUInt8(m_menuType, packet, &cursor);
    PacketBufferAppendUInt32BE(m_menuId, packet, &cursor);
    PacketBufferAppendUInt16BE(itemId, packet, &cursor);

    if (m_ownerDialog->m_hasExtraString) {
        PacketBufferAppendAnsiString8(
            m_ownerDialog->m_extraString.c_str(), packet, &cursor);
    }

    packet[cursor] = 0;
    g_packetSender->QueueAndSendPacket(
        packet, static_cast<short>(cursor));
}

void TextMenuItemList::OnItemActivated()
{
    m_ownerDialog->ActivateFocusedControl();
}

void TextMenuItemList::DrawListEntry(int rowIndex, void *rowData,
                                     RectBounds *rowBounds)
{
    const TextMenuItemListEntry *entry =
        static_cast<const TextMenuItemListEntry *>(rowData);
    int textColor = 37;

    if (IsItemSelected(rowIndex)) {
        SetDrawColor(37);
        g_drawPaneRect(this, rowBounds);
        textColor = 128;
    }

    SetTextColor(textColor);
    SetTextOpaque(1);
    SetTextMode(0);
    MoveTo(rowBounds->left, rowBounds->bottom);
    DrawWideText(entry->label, wcslen(entry->label));
}

// UID:0000ER | by-class/TextInputMenuDialog.md | Completion:94 | Confidence:94
TextInputMenuDialog::TextInputMenuDialog(
    bool hasExtraString,
    const RectBounds& dialogBounds,
    const unsigned char *payload,
    unsigned char merchantDialogType)
    : MerchantDialogPane(merchantDialogType),
      m_replyType(0),
      m_selectedOptionId(0),
      m_hasExtraString(hasExtraString),
      m_extraString()
{
    TextMenuPayloadReader reader(payload);
    ObjectStatusBlob objectStatus;
    wchar_t prompt[32768];

    m_replyType = reader.ReadUInt8();
    m_menuObjectId = reader.ReadUInt32();
    if (!reader.ReadObjectStatus(&objectStatus))
        return;
    reader.ReadAnsi16(prompt, 32768);
    if (m_hasExtraString)
        reader.ReadWideString8(&m_extraString);
    m_selectedOptionId = reader.ReadUInt16();

    RectBounds bounds;
    if (g_useEpfAssets) {
        InitRectBounds(&bounds, 0, 0, 336, 205);
        AddImageControl(bounds, L"DLGMERC2.EPF", 0, L"PA");
        AddButtonControl(RectBounds(60, 169, 123, 193), 14);
        AddButtonControl(RectBounds(137, 169, 200, 193), 16);
        AddButtonControl(RectBounds(214, 169, 277, 193), 15);
        AddObjectImageControl(RectBounds(22, 8, 96, 116), objectStatus);
        AddStaticTextControl(RectBounds(105, 28, 301, 112),
                             prompt, true, 128, 143);
        AddTextEditControl(RectBounds(44, 128, 291, 140),
                           L"", 1, 128, 143, 1.0f);
        SetBackgroundResource(L"DLGMERC2.EPF", 0);
        bounds = RectBounds(0, 0, 336, 205);
    } else {
        InitRectBounds(&bounds, 0, 0, 314, 197);
        AddImageControl(bounds, L"DLGMERC2.EPD", 0, L"NP");
        AddButtonControl(RectBounds(44, 147, 116, 163), 14);
        AddButtonControl(RectBounds(121, 147, 193, 163), 16);
        AddButtonControl(RectBounds(198, 147, 270, 163), 15);
        AddObjectImageControl(RectBounds(35, 37, 72, 92), objectStatus);
        AddStaticTextControl(RectBounds(82, 35, 262, 83),
                             prompt, true, 128, 143);
        AddTextEditControl(RectBounds(56, 113, 257, 125),
                           L"", 1, 128, 143, 1.0f);
        SetBackgroundResource(L"DLGMERC2.EPD", 0);
        bounds = RectBounds(0, 0, 314, 197);
    }

    SetHoverControl(6);
    SetFocusedControl(1);
    SetPendingControl(3);
    StoreClampRect(&dialogBounds);
    SetMode(1);
    OnCreate(&bounds, 0, 0, g_dialogLayer);
    OnShow(0, g_pBackPane);
}

void TextInputMenuDialog::OnControlCommand(int controlIndex, int notifyCode)
{
    (void)notifyCode;

    switch (controlIndex) {
    case 1:
    {
        wchar_t inputText[256];
        GetChild<TextEditControlPane>(6)->ReadText(inputText, 255);
        SendInputReply(inputText);
        CloseDialog();
        break;
    }
    case 2:
        SendMenuRequestPacket();
        break;
    case 3:
        CloseDialog();
        break;
    }
}

void TextInputMenuDialog::UpdateActionButton()
{
    ControlPane *okButton = GetChild<ControlPane>(1);
    TextEditControlPane *input = GetChild<TextEditControlPane>(6);
    if (input->IsEmpty())
        okButton->Deactivate();
    else
        okButton->Activate();
}

// UID:000239 | by-memory/0x0051a420-0x0051a51c.TextInputMenuDialogReplyPacketHelper.md | Completion:93 | Confidence:94
void TextInputMenuDialog::SendInputReply(const wchar_t *inputText)
{
    unsigned char packet[0x208];
    int cursor = 0;

    PacketBufferAppendUInt8(0x39, packet, &cursor);
    PacketBufferAppendUInt8(m_replyType, packet, &cursor);
    PacketBufferAppendUInt32BE(m_menuObjectId, packet, &cursor);
    PacketBufferAppendUInt16BE(m_selectedOptionId, packet, &cursor);

    if (m_hasExtraString) {
        PacketBufferAppendAnsiString8(
            m_extraString.c_str(), packet, &cursor);
    }

    PacketBufferAppendWideStringAsAnsi8(
        inputText, packet, &cursor);
    g_packetSender->QueueAndSendPacket(
        packet, static_cast<short>(cursor));
}

// UID:0003IP | by-memory/0x0061e8dc-0x0061e8ec.MerchantDialogCreatorVtableData.md | Completion:93 | Confidence:94
// Compiler-covered by TextMenuDialog, TextMenuItemList,
// TextInputMenuDialog, and MerchantDialogCreator source declarations.
// No raw vtable, COL, RTTI, thunk, or deleting-destructor arrays are authored.

// UID:00031Y | by-type/by-vtable/TextMenuDialogVtables.md | Completion:93 | Confidence:94
// Compiler-covered by TextMenuDialog, TextMenuItemList,
// TextInputMenuDialog, and MerchantDialogCreator source declarations.
// No raw vtable, COL, RTTI, thunk, or deleting-destructor arrays are authored.
