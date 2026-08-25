// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HI
// Source by-file doc: by-file/ArgumentedMenuDialogs.md
// UID:00000H | by-class/ArgumentedMenuMenuDialog.md | Completion:91 | Confidence:93
#include "ArgumentedMenuDialogs.h"
#include "ArgumentedItemInputDialogs.h"

// UID:0002TW | by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md | Completion:89 | Confidence:91
ArgumentedMenuMenuDialog::ArgumentedMenuMenuDialog(
    const RectBounds& bounds,
    const unsigned char *payload,
    unsigned char menuMode)
    : MerchantDialogPane(menuMode),
      m_commandType(payload[0])
{
    m_menuObjectId = PacketBufferReadUInt32BE(payload + 1);

    MenuObjectImage objectImage;
    const unsigned char *cursor = ReadMenuObjectImage(payload + 6, objectImage);

    wchar_t dialogText[0x8000];
    cursor = ReadMenuText(cursor, dialogText, _countof(dialogText));

    const unsigned short listParameter = PacketBufferReadUInt16BE(cursor);
    cursor += sizeof(unsigned short);

    ArgumentedMenuMenuItemList *list =
        new ArgumentedMenuMenuItemList(m_commandType,
                                       m_menuObjectId,
                                       listParameter,
                                       this);

    const unsigned short itemCount = PacketBufferReadUInt16BE(cursor);
    cursor += sizeof(unsigned short);

    for (unsigned int i = 0; i < itemCount; ++i) {
        const unsigned int argumentId = PacketBufferReadUInt32BE(cursor);
        cursor += sizeof(unsigned int);

        const unsigned short itemId = PacketBufferReadUInt16BE(cursor);
        cursor += sizeof(unsigned short);

        const unsigned char itemStyle = *cursor++;

        const unsigned int price = PacketBufferReadUInt32BE(cursor);
        cursor += sizeof(unsigned int);

        const unsigned char maxQuantity = *cursor++;
        const unsigned char nameLength = *cursor++;

        wchar_t itemName[256];
        cursor = ReadMenuText(cursor, nameLength, itemName, _countof(itemName));

        const unsigned char percentSuffix = *cursor++;
        if (percentSuffix != 0xff) {
            wchar_t suffix[256];
            swprintf_s(suffix, _countof(suffix), L"(%d%%)", percentSuffix);
            wcscat_s(itemName, _countof(itemName), suffix);
        }

        list->AppendItem(itemId,
                         itemStyle,
                         price,
                         itemName,
                         L"",
                         argumentId,
                         maxQuantity);
    }

    CreateArgumentedMenuLayout(kArgumentedMenuLayout,
                               objectImage,
                               dialogText,
                               list);
    SetFocusedControl(6);
    SetDefaultCommand(1);
    SetCancelCommand(3);
    ApplyMenuDialogBounds(bounds, L"DLGMERC3.EPF");
}

void ArgumentedMenuMenuDialog::HandleMenuCommand(int commandId, void *context)
{
    UNREFERENCED_PARAMETER(context);

    switch (commandId) {
    case 1:
        if (ArgumentedMenuMenuItemList *list = GetArgumentedMenuList(6)) {
            const ArgumentedMenuItemEntry *entry = list->GetSelectedEntry();
            if (entry != NULL) {
                wchar_t prompt[128];
                wcscpy_s(prompt,
                         _countof(prompt),
                         L"Do you want to buy this?\n\nConfirm the price.");

                new ArgumentedItemConfirmInputDialogPane(prompt,
                                                         list,
                                                         entry->maxQuantity,
                                                         entry->price,
                                                         entry->argumentId);
            }
        }
        break;

    case 2:
        SendMenuRequestPacket();
        break;

    case 3:
        CloseDialog();
        break;
    }
}

void ArgumentedMenuMenuDialog::UpdateActionButtonState()
{
    ControlPane *actionButton = GetControl(1);
    ArgumentedMenuMenuItemList *list = GetArgumentedMenuList(6);
    const bool hasSelection = list != NULL && list->GetSelectionCount() > 0;

    if (actionButton != NULL)
        actionButton->SetEnabled(hasSelection);
}

// UID:00000I | by-class/ArgumentedMenuMenuItemList.md | Completion:91 | Confidence:93
// UID:0003VF | by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md | Completion:89 | Confidence:92
ArgumentedMenuMenuItemList::ArgumentedMenuMenuItemList(
    const ArgumentedMenuMenuItemList &source)
    : ListPane(0x410, 0x10, 0x16a, 0x18, 0, true, true),
      m_commandType(source.m_commandType),
      m_ownerId(source.m_ownerId),
      m_listParameter(source.m_listParameter),
      m_ownerDialog(source.m_ownerDialog)
{
}

// UID:0003VG | by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md | Completion:87 | Confidence:88
ArgumentedMenuMenuItemList::ArgumentedMenuMenuItemList(
    unsigned char commandType,
    unsigned int ownerId,
    unsigned short listParameter,
    ArgumentedMenuMenuDialog *ownerDialog)
    : ListPane(0x410, 0x10, 0x16a, 0x18, 0, 1, 1)
{
    m_commandType = commandType;
    m_ownerId = ownerId;
    m_listParameter = listParameter;
    m_ownerDialog = ownerDialog;
}

// UID:0003VH | by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md | Completion:88 | Confidence:89
void ArgumentedMenuMenuItemList::AppendItem(
    unsigned short itemId,
    unsigned char itemStyle,
    unsigned int price,
    const wchar_t *name,
    const wchar_t *description,
    unsigned int argumentId,
    unsigned char maxQuantity)
{
    ArgumentedMenuItemEntry entry;

    entry.itemId = itemId;
    entry.itemStyle = itemStyle;
    entry.price = price;
    wcscpy_s(entry.name, _countof(entry.name), name);
    wcscpy_s(entry.description, _countof(entry.description), description);
    entry.argumentId = argumentId;
    entry.maxQuantity = maxQuantity;

    AddEntry(&entry);
}

// UID:0003VI | by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md | Completion:89 | Confidence:91
void ArgumentedMenuMenuItemList::OpenBuyConfirmDialog()
{
    const ArgumentedMenuItemEntry *entry = GetSelectedEntry();

    if (entry != NULL) {
        wchar_t prompt[128];
        wcscpy_s(prompt,
                 _countof(prompt),
                 L"Do you want to buy this?\n\nConfirm the price.");

        new ArgumentedItemConfirmInputDialogPane(prompt,
                                                  this,
                                                  entry->maxQuantity,
                                                  entry->price,
                                                  entry->argumentId);
    }
}

// UID:0003VJ | by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md | Completion:89 | Confidence:91
void ArgumentedMenuMenuItemList::OpenQuantityDialogOrSendSingle(
    unsigned int maxQuantity,
    unsigned int argumentId)
{
    if (maxQuantity <= 1) {
        SendArgumentedItemQuantityPacket(argumentId, 1);
        return;
    }

    new ArgumentedItemQuantityInputDialogPane(
        g_pLanguageMan->GetLocalizedString(246),
        this,
        argumentId);
}

// UID:0003VK | by-memory/0x0051f5b0-0x0051f63d.ArgumentedMenuMenuItemListSelectItemAndUpdateText.md | Completion:86 | Confidence:89
void ArgumentedMenuMenuItemList::OnItemSelected(
    int rowIndex, int notify)
{
    ArgumentedMenuItemEntry *entry =
        static_cast<ArgumentedMenuItemEntry *>(GetItem(rowIndex));
    m_ownerDialog->GetChild<StaticTextControlPane>(7)->SetText(
        entry == NULL ? L"" : entry->description);
    ListPane::OnItemSelected(rowIndex, notify);
}

// UID:0003VL | by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md | Completion:91 | Confidence:93
void ArgumentedMenuMenuItemList::SendArgumentedItemQuantityPacket(
    unsigned int argumentId,
    unsigned char quantity)
{
    m_ownerDialog->CloseDialog();

    unsigned char packet[0x200];
    PacketBufferWriteUInt8(0x39, packet);
    PacketBufferWriteUInt8(m_commandType, packet + 1);
    PacketBufferWriteUInt32BE(m_ownerId, packet + 2);
    PacketBufferWriteUInt16BE(m_listParameter, packet + 6);
    PacketBufferWriteUInt8(1, packet + 8);
    PacketBufferWriteUInt32BE(argumentId, packet + 9);
    PacketBufferWriteUInt8(quantity, packet + 13);
    packet[14] = 0;

    g_packetSender->QueueAndSendPacket(packet, 14);
}

// UID:0003VM | by-memory/0x0051f710-0x0051f71b.ArgumentedMenuMenuItemListForwardOwnerStateUpdate.md | Completion:94 | Confidence:95
void ArgumentedMenuMenuItemList::OnItemActivated()
{
    m_ownerDialog->ActivateFocusedControl();
}

// UID:0003VN | by-memory/0x0051f720-0x0051f840.ArgumentedMenuMenuItemListHandleMouseEvent.md | Completion:86 | Confidence:89
bool ArgumentedMenuMenuItemList::OnMouseEvent(MouseEvent *event)
{
    if (event->code == 1) {
        delete g_pItemHelpPane;
        return true;
    }

    if (event->code != 4)
        return ListPane::OnMouseEvent(event);

    const int rowIndex = HitTestItem(event->x, event->y);
    if (rowIndex < 0) {
        if (g_pItemHelpPane != NULL) {
            delete g_pItemHelpPane;
            return true;
        }
        return ListPane::OnMouseEvent(event);
    }

    ArgumentedMenuItemEntry *entry =
        static_cast<ArgumentedMenuItemEntry *>(GetItem(rowIndex));
    if (g_useEpfAssets && entry != NULL) {
        delete g_pItemHelpPane;
        new ItemHelpPane(entry->name, this, event->y, event->x,
                         5000, NULL, 0, 0);
    }
    return true;
}

// UID:0003VO | by-memory/0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md | Completion:86 | Confidence:88
void ArgumentedMenuMenuItemList::DrawListEntry(
    int rowIndex, void *rowData, RectBounds *rowBounds)
{
    ArgumentedMenuItemEntry *entry =
        static_cast<ArgumentedMenuItemEntry *>(rowData);
    const bool selected = IsItemSelected(rowIndex);

    RectBounds itemBounds = *rowBounds;
    itemBounds.right -= 28;
    if (selected) {
        SetDrawColor(0x25);
        g_pfnFillRect(this, &itemBounds);
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
    RectBounds nameBounds = *rowBounds;
    nameBounds.left = 30;
    nameBounds.right = 186;
    FitTextAndAppendSuffix(
        fittedName, _countof(fittedName), L"...",
        nameBounds.right - nameBounds.left);
    DrawTextInRect(fittedName, wcslen(fittedName), &nameBounds);

    wchar_t countText[16];
    swprintf_s(countText, _countof(countText),
               L"%d", entry->maxQuantity);
    RectBounds countBounds = *rowBounds;
    countBounds.left = 186;
    countBounds.right = 217;
    DrawTextInRect(countText, wcslen(countText), &countBounds);

    wchar_t priceDigits[32];
    swprintf_s(priceDigits, _countof(priceDigits), L"%u", entry->price);
    wchar_t priceText[48];
    wchar_t *output = priceText;
    if (entry->maxQuantity > 1) {
        wcscpy_s(priceText, _countof(priceText), L"1gold ");
        output += wcslen(priceText);
    }
    const size_t digitCount = wcslen(priceDigits);
    for (size_t i = 0; i < digitCount; ++i) {
        if (i != 0 && (digitCount - i) % 3 == 0)
            *output++ = L',';
        *output++ = priceDigits[i];
    }
    *output = L'\0';

    RectBounds priceBounds = *rowBounds;
    priceBounds.left = 217;
    DrawTextInRect(priceText, wcslen(priceText), &priceBounds);
}

// UID:000320 | by-type/by-vtable/ArgumentedMenuDialogVtables.md | Completion:87 | Confidence:91
// Argumented-menu dialog/list vtables and RTTI are compiler-generated from the
// class declarations; do not emit handwritten ABI arrays or wrapper bodies.
