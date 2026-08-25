// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KF
// Source by-file doc: by-file/ItemMenuDialogs.md
// UID:0000CZ | by-class/ServerItemMenuDialog.md | Completion:94 | Confidence:94
#include "ItemMenuDialogs.h"

// UID:00040D | by-memory/0x0051a520-0x0051ae8d.ServerItemMenuDialogMethods.md | Completion:94 | Confidence:94
static const unsigned char *ReadItemMenuWideString16(
    const unsigned char *packet, wchar_t *destination,
    std::size_t destinationCount)
{
    const unsigned short byteCount = PacketBufferReadUInt16BE(packet);
    char narrowText[0x8000];
    memcpy(narrowText, packet + 2, byteCount);
    narrowText[byteCount] = '\0';
    const int wideCount = MultiByteToWideChar(
        CP_ACP, 0, narrowText, byteCount, destination,
        static_cast<int>(destinationCount));
    destination[wideCount] = L'\0';
    return packet + 2 + byteCount;
}

static const unsigned char *ReadItemMenuWideString8(
    const unsigned char *packet, wchar_t *destination,
    std::size_t destinationCount)
{
    const unsigned char byteCount = *packet++;
    char narrowText[256];
    memcpy(narrowText, packet, byteCount);
    narrowText[byteCount] = '\0';
    const int wideCount = MultiByteToWideChar(
        CP_ACP, 0, narrowText, byteCount, destination,
        static_cast<int>(destinationCount));
    destination[wideCount] = L'\0';
    return packet + byteCount;
}

ServerItemMenuDialog::ServerItemMenuDialog(const RectBounds& bounds,
                                           const unsigned char *payload,
                                           unsigned char menuMode)
    : MerchantDialogPane(menuMode),
      m_packetSubtype(payload[0])
{
    m_menuObjectId = PacketBufferReadUInt32BE(payload + 1);
    ObjectStatusBlob objectStatus;
    const int objectStatusSize = objectStatus.ParseTaggedStatus(payload + 6);
    const unsigned char *cursor = payload + objectStatusSize + 10;

    wchar_t text[256];
    cursor = ReadItemMenuWideString16(cursor, text, _countof(text));
    const unsigned short menuOptionId = PacketBufferReadUInt16BE(cursor);
    cursor += 2;

    ServerItemMenuItemList *list =
        new ServerItemMenuItemList(m_packetSubtype, m_menuObjectId,
                                   menuOptionId, this);

    const unsigned short itemCount = PacketBufferReadUInt16BE(cursor);
    cursor += 2;
    for (unsigned int i = 0; i < itemCount; ++i) {
        const unsigned short itemId = PacketBufferReadUInt16BE(cursor);
        cursor += 2;
        const unsigned char itemStyle = *cursor++;
        const unsigned int value = PacketBufferReadUInt32BE(cursor);
        cursor += 4;

        wchar_t name[256];
        wchar_t description[256];
        cursor = ReadItemMenuWideString8(cursor, name, _countof(name));
        cursor = ReadItemMenuWideString8(cursor, description,
                                         _countof(description));
        list->AppendItem(itemId, itemStyle, value, name, description);
    }

    RectBounds controlBounds;
    InitRectBounds(&controlBounds, 0, 0, 410, 368);
    AddControl(new EPFImageControlPane(
        L"DLGMERC3.EPF", 0, 1, &controlBounds, L"PA"));
    InitRectBounds(&controlBounds, 104, 332, 167, 356);
    AddControl(new ImageButtonControlPane(14, &controlBounds));
    InitRectBounds(&controlBounds, 181, 332, 244, 356);
    AddControl(new ImageButtonControlPane(16, &controlBounds));
    InitRectBounds(&controlBounds, 258, 332, 321, 356);
    AddControl(new ImageButtonControlPane(15, &controlBounds));
    InitRectBounds(&controlBounds, 26, 13, 100, 121);
    AddControl(new ObjectImageControlPane(&objectStatus, &controlBounds));
    InitRectBounds(&controlBounds, 109, 33, 373, 121);
    AddControl(new StaticTextControlPane(
        text, true, 128, 143, &controlBounds, false, false));
    InitRectBounds(&controlBounds, 36, 129, 391, 273);
    AddControl(new ScrollableControlPane(
        &controlBounds, list, 0, 0, 0));
    InitRectBounds(&controlBounds, 25, 291, 363, 303);
    AddControl(new StaticTextControlPane(
        L"", true, 128, 0, &controlBounds, false, false));
    SetHoverControl(6);
    SetFocusedControl(1);
    SetPendingControl(3);
    StoreClampRect(&bounds);
    SetBackgroundResource(L"DLGMERC3.EPF", 0);
    UpdateActionButton();
}

void ServerItemMenuDialog::OnControlCommand(int controlId, int notifyCode)
{
    if (notifyCode != 0)
        return;

    switch (controlId) {
    case 1:
        GetChild<ServerItemMenuItemList>(6)->SendSelectedItemName();
        CloseDialog();
        break;
    case 2:
        SendMenuRequestPacket();
        break;
    case 3:
        CloseDialog();
        break;
    }
}

void ServerItemMenuDialog::UpdateActionButton()
{
    ControlPane *button = GetChildControl(1);
    ServerItemMenuItemList *list =
        GetChild<ServerItemMenuItemList>(6);

    if (list->GetSelectionCount() != 0)
        button->Enable();
    else
        button->Disable();
}

// UID:0000D0 | by-class/ServerItemMenuItemList.md | Completion:94 | Confidence:94
// ServerItemMenuItemList definitions are emitted by source child UID0001BP.

// UID:0001BP | by-memory/0x0051ae90-0x0051b87a.ServerItemMenuItemList.md | Completion:94 | Confidence:94
ServerItemMenuItemList::ServerItemMenuItemList(
    unsigned char packetSubtype,
    unsigned int menuObjectId,
    unsigned short menuOptionId,
    ServerItemMenuDialog *owner)
    : ListPane(sizeof(ServerItemMenuEntry), 0x10, 0x15c, 0x18,
               false, true, 1),
      m_packetSubtype(packetSubtype),
      m_menuObjectId(menuObjectId),
      m_menuOptionId(menuOptionId),
      m_owner(owner)
{
}

ServerItemMenuItemList::~ServerItemMenuItemList()
{
    delete g_pItemHelpPane;
}

void ServerItemMenuItemList::AppendItem(
    unsigned short itemId, unsigned char itemStyle,
    unsigned int value, const wchar_t *name,
    const wchar_t *description)
{
    ServerItemMenuEntry entry;
    entry.itemId = itemId;
    entry.itemStyle = itemStyle;
    entry.value = value;
    wcscpy_s(entry.name, _countof(entry.name), name);
    wcscpy_s(entry.description, _countof(entry.description), description);
    AddEntry(&entry);
}

void ServerItemMenuItemList::SendSelectedItemName()
{
    if (m_selectedIndex < 0)
        return;

    ServerItemMenuEntry *entry =
        static_cast<ServerItemMenuEntry *>(GetItem(m_selectedIndex));
    SendItemName(entry->name);
}

void ServerItemMenuItemList::SendItemName(const wchar_t *name)
{
    unsigned char packet[0x304];
    char converted[256];
    const int length = WideCharToMultiByte(
        CP_ACP, 0, name, -1, converted, _countof(converted),
        NULL, NULL);
    if (length >= 256)
        _invalid_parameter_noinfo_noreturn();

    PacketBufferWriteUInt8(0x39, packet);
    PacketBufferWriteUInt8(m_packetSubtype, packet + 1);
    PacketBufferWriteUInt32BE(m_menuObjectId, packet + 2);
    PacketBufferWriteUInt16BE(m_menuOptionId, packet + 6);
    PacketBufferWriteUInt8(static_cast<unsigned char>(length - 1),
                           packet + 8);
    memcpy(packet + 9, converted, length - 1);
    g_packetSender->QueueAndSendPacket(packet, length + 8);
}

void ServerItemMenuItemList::OnItemSelected(int rowIndex, int notify)
{
    ServerItemMenuEntry *entry =
        static_cast<ServerItemMenuEntry *>(GetItem(rowIndex));
    m_owner->GetChild<StaticTextControlPane>(7)->SetText(
        entry == NULL ? L"" : entry->description);
    ListPane::OnItemSelected(rowIndex, notify);
}

void ServerItemMenuItemList::OnItemActivated()
{
    m_owner->UpdateActionButton();
}

bool ServerItemMenuItemList::OnMouseEvent(MouseEvent *event)
{
    if (event->code == 1 || event->code == 4)
        delete g_pItemHelpPane;

    const int rowIndex = HitTestItem(event->x, event->y);
    if (rowIndex >= 0 && g_useEpfAssets) {
        ServerItemMenuEntry *entry =
            static_cast<ServerItemMenuEntry *>(GetItem(rowIndex));
        if (entry != NULL) {
            delete g_pItemHelpPane;
            new ItemHelpPane(entry->name, this, event->y, event->x,
                             5000, NULL, 0, 0);
        }
    }
    return ListPane::OnMouseEvent(event);
}

void ServerItemMenuItemList::DrawListEntry(
    int rowIndex, void *rowData, RectBounds *rowBounds)
{
    ServerItemMenuEntry *entry =
        static_cast<ServerItemMenuEntry *>(rowData);
    const bool selected = IsItemSelected(rowIndex);
    if (selected) {
        SetDrawColor(0x25);
        g_pfnFillRect(this, rowBounds);
    }
    SetTextColor(selected ? 0x80 : 0x25);

    RectBounds glyphBounds;
    RectBounds imageBounds;
    g_pItemObjImageLib->GetItemGlyphBounds(entry->itemId, &glyphBounds);
    if (g_useEpfAssets) {
        imageBounds.left = 12 -
            (glyphBounds.right - glyphBounds.left) / 4;
        imageBounds.right = imageBounds.left +
            (glyphBounds.right - glyphBounds.left) / 2;
        imageBounds.top = (rowBounds->top + rowBounds->bottom) / 2 -
            (glyphBounds.bottom - glyphBounds.top) / 4;
        imageBounds.bottom = imageBounds.top +
            (glyphBounds.bottom - glyphBounds.top) / 2;
        IntersectRects(&imageBounds, rowBounds, &imageBounds);
        g_pItemObjImageLib->DrawItemImageScaled(
            this, &imageBounds, entry->itemId, entry->itemStyle);
    } else {
        imageBounds.left = 12 -
            (glyphBounds.right - glyphBounds.left) / 2;
        imageBounds.right = imageBounds.left +
            (glyphBounds.right - glyphBounds.left);
        imageBounds.top = (rowBounds->top + rowBounds->bottom) / 2 -
            (glyphBounds.bottom - glyphBounds.top) / 2;
        imageBounds.bottom = imageBounds.top +
            (glyphBounds.bottom - glyphBounds.top);
        g_pItemObjImageLib->DrawItemImage(
            this, &imageBounds, entry->itemId, entry->itemStyle,
            NULL, 0.0f);
    }

    SetTextDrawMode(1);
    SetTextBackFillColor(0);
    wchar_t fittedName[256];
    wcscpy_s(fittedName, _countof(fittedName), entry->name);
    RectBounds nameBounds;
    nameBounds.left = 50;
    nameBounds.right = rowBounds->right;
    nameBounds.top = (rowBounds->top + rowBounds->bottom) / 2 - 6;
    nameBounds.bottom = nameBounds.top + 12;
    FitTextAndAppendSuffix(
        fittedName, _countof(fittedName), L"...",
        nameBounds.right - nameBounds.left);
    DrawTextInRect(fittedName, wcslen(fittedName), &nameBounds);

    wchar_t valueText[32];
    swprintf_s(valueText, _countof(valueText), L"%10u", entry->value);
    RectBounds valueBounds = *rowBounds;
    valueBounds.left = rowBounds->right - 90;
    valueBounds.right = rowBounds->right - 30;
    DrawTextInRect(valueText, wcslen(valueText), &valueBounds);
}

// UID:00002P | by-class/ClientItemMenuDialog.md | Completion:94 | Confidence:94
// ClientItemMenuDialog definitions are emitted by source child UID00040E.

// UID:00040E | by-memory/0x0051b880-0x0051c46d.ClientItemMenuDialogMethods.md | Completion:94 | Confidence:94
ClientItemMenuDialog::ClientItemMenuDialog(const RectBounds& bounds,
                                           const unsigned char *payload,
                                           unsigned char menuMode)
    : MerchantDialogPane(menuMode),
      m_packetSubtype(payload[0])
{
    m_menuObjectId = PacketBufferReadUInt32BE(payload + 1);
    ObjectStatusBlob objectStatus;
    const int objectStatusSize = objectStatus.ParseTaggedStatus(payload + 6);
    const unsigned char *cursor = payload + objectStatusSize + 10;

    wchar_t text[256];
    cursor = ReadItemMenuWideString16(cursor, text, _countof(text));
    const unsigned short menuOptionId = PacketBufferReadUInt16BE(cursor);
    cursor += 2;

    ClientItemMenuItemList *list =
        new ClientItemMenuItemList(m_packetSubtype, m_menuObjectId,
                                   menuOptionId, this);

    const unsigned char actionCount = *cursor++;
    for (unsigned int i = 0; i < actionCount; ++i) {
        const unsigned char actionId = *cursor++;
        const LocalInventorySlotRecord *item =
            g_pUserPane->GetInventorySlotAddress(actionId);
        if (item->active)
            list->AppendAction(actionId,
                               item->itemId,
                               item->iconStyle,
                               item->displayName);
    }

    RectBounds controlBounds;
    if (g_useEpfAssets) {
        InitRectBounds(&controlBounds, 0, 0, 315, 353);
        AddControl(new EPFImageControlPane(
            L"DLGMERC1.EPF", 0, 1, &controlBounds, L"PA"));
        InitRectBounds(&controlBounds, 44, 310, 107, 334);
        AddControl(new ImageButtonControlPane(14, &controlBounds));
        InitRectBounds(&controlBounds, 121, 310, 184, 334);
        AddControl(new ImageButtonControlPane(16, &controlBounds));
        InitRectBounds(&controlBounds, 198, 310, 261, 334);
        AddControl(new ImageButtonControlPane(15, &controlBounds));
        InitRectBounds(&controlBounds, 20, 20, 94, 128);
        AddControl(new ObjectImageControlPane(&objectStatus, &controlBounds));
        InitRectBounds(&controlBounds, 105, 40, 276, 128);
        AddControl(new StaticTextControlPane(
            text, true, 128, 143, &controlBounds, false, false));
        InitRectBounds(&controlBounds, 36, 144, 294, 288);
        AddControl(new ScrollableControlPane(
            &controlBounds, list, 0, 0, 0));
        SetBackgroundResource(L"DLGMERC1.EPF", 0);
    } else {
        InitRectBounds(&controlBounds, 0, 0, 314, 356);
        AddControl(new EPFImageControlPane(
            L"DLGMERC1.EPD", 0, 1, &controlBounds, L"NP"));
        InitRectBounds(&controlBounds, 44, 306, 116, 322);
        AddControl(new ImageButtonControlPane(14, &controlBounds));
        InitRectBounds(&controlBounds, 121, 306, 193, 322);
        AddControl(new ImageButtonControlPane(16, &controlBounds));
        InitRectBounds(&controlBounds, 198, 306, 270, 322);
        AddControl(new ImageButtonControlPane(15, &controlBounds));
        InitRectBounds(&controlBounds, 35, 37, 72, 92);
        AddControl(new ObjectImageControlPane(&objectStatus, &controlBounds));
        InitRectBounds(&controlBounds, 122, 37, 266, 133);
        AddControl(new StaticTextControlPane(
            text, true, 128, 143, &controlBounds, false, false));
        InitRectBounds(&controlBounds, 36, 141, 278, 285);
        AddControl(new ScrollableControlPane(
            &controlBounds, list, 0, 0, 0));
        SetBackgroundResource(L"DLGMERC1.EPD", 0);
    }

    SetHoverControl(6);
    SetFocusedControl(1);
    SetPendingControl(3);
    StoreClampRect(&bounds);
    UpdateActionButton();
}

void ClientItemMenuDialog::OnControlCommand(int controlId, int notifyCode)
{
    if (notifyCode != 0)
        return;

    switch (controlId) {
    case 1:
        GetChild<ClientItemMenuItemList>(6)->SendSelectedAction();
        CloseDialog();
        break;
    case 2:
        SendMenuRequestPacket();
        break;
    case 3:
        CloseDialog();
        break;
    }
}

void ClientItemMenuDialog::UpdateActionButton()
{
    ControlPane *button = GetChildControl(1);
    ClientItemMenuItemList *list =
        GetChild<ClientItemMenuItemList>(6);

    if (list->GetSelectionCount() != 0)
        button->Enable();
    else
        button->Disable();
}

// UID:00002Q | by-class/ClientItemMenuItemList.md | Completion:94 | Confidence:94
// ClientItemMenuItemList definitions are emitted by source child UID0001BQ.

// UID:0001BQ | by-memory/0x0051c470-0x0051ca3c.ClientItemMenuItemList.md | Completion:94 | Confidence:94
ClientItemMenuItemList::ClientItemMenuItemList(
    unsigned char packetSubtype,
    unsigned int menuObjectId,
    unsigned short menuOptionId,
    ClientItemMenuDialog *owner)
    : ListPane(sizeof(ClientItemMenuEntry), 0x10, 0xe4, 0x18,
               false, true, 1),
      m_packetSubtype(packetSubtype),
      m_menuObjectId(menuObjectId),
      m_menuOptionId(menuOptionId),
      m_owner(owner)
{
}

void ClientItemMenuItemList::AppendAction(
    unsigned char actionId, unsigned short itemId,
    unsigned char itemStyle, const wchar_t *name)
{
    ClientItemMenuEntry entry;
    entry.actionId = actionId;
    entry.itemId = itemId;
    entry.itemStyle = itemStyle;
    wcscpy_s(entry.name, _countof(entry.name), name);
    AddEntry(&entry);
}

void ClientItemMenuItemList::SendSelectedAction()
{
    if (m_selectedIndex < 0)
        return;

    ClientItemMenuEntry *entry =
        static_cast<ClientItemMenuEntry *>(GetItem(m_selectedIndex));
    SendAction(entry->actionId);
}

void ClientItemMenuItemList::SendAction(unsigned char actionId)
{
    unsigned char packet[0x204];
    PacketBufferWriteUInt8(0x39, packet);
    PacketBufferWriteUInt8(m_packetSubtype, packet + 1);
    PacketBufferWriteUInt32BE(m_menuObjectId, packet + 2);
    PacketBufferWriteUInt16BE(m_menuOptionId, packet + 6);
    PacketBufferWriteUInt8(actionId, packet + 8);
    packet[9] = 0;

    g_packetSender->QueueAndSendPacket(packet, 9);
}

void ClientItemMenuItemList::OnItemActivated()
{
    m_owner->UpdateActionButton();
}

void ClientItemMenuItemList::DrawListEntry(
    int rowIndex, void *rowData, RectBounds *rowBounds)
{
    ClientItemMenuEntry *entry =
        static_cast<ClientItemMenuEntry *>(rowData);
    const bool selected = IsItemSelected(rowIndex);
    if (selected) {
        SetDrawColor(0x25);
        g_pfnFillRect(this, rowBounds);
    }
    SetTextColor(selected ? 0x80 : 0x25);

    RectBounds glyphBounds;
    RectBounds imageBounds;
    g_pItemObjImageLib->GetItemGlyphBounds(entry->itemId, &glyphBounds);
    if (g_useEpfAssets) {
        imageBounds.left = 12 -
            (glyphBounds.right - glyphBounds.left) / 4;
        imageBounds.right = imageBounds.left +
            (glyphBounds.right - glyphBounds.left) / 2;
        imageBounds.top = (rowBounds->top + rowBounds->bottom) / 2 -
            (glyphBounds.bottom - glyphBounds.top) / 4;
        imageBounds.bottom = imageBounds.top +
            (glyphBounds.bottom - glyphBounds.top) / 2;
        IntersectRects(&imageBounds, rowBounds, &imageBounds);
        g_pItemObjImageLib->DrawItemImageScaled(
            this, &imageBounds, entry->itemId, entry->itemStyle);
    } else {
        imageBounds.left = 12 -
            (glyphBounds.right - glyphBounds.left) / 2;
        imageBounds.right = imageBounds.left +
            (glyphBounds.right - glyphBounds.left);
        imageBounds.top = (rowBounds->top + rowBounds->bottom) / 2 -
            (glyphBounds.bottom - glyphBounds.top) / 2;
        imageBounds.bottom = imageBounds.top +
            (glyphBounds.bottom - glyphBounds.top);
        g_pItemObjImageLib->DrawItemImage(
            this, &imageBounds, entry->itemId, entry->itemStyle,
            NULL, 0.0f);
    }

    SetTextDrawMode(1);
    SetTextBackFillColor(0);
    wchar_t fittedName[256];
    wcscpy_s(fittedName, _countof(fittedName), entry->name);
    RectBounds nameBounds;
    nameBounds.left = 50;
    nameBounds.right = rowBounds->right;
    nameBounds.top = (rowBounds->top + rowBounds->bottom) / 2 - 6;
    nameBounds.bottom = nameBounds.top + 12;
    FitTextAndAppendSuffix(
        fittedName, _countof(fittedName), L"...",
        nameBounds.right - nameBounds.left);
    DrawTextInRect(fittedName, wcslen(fittedName), &nameBounds);
}
