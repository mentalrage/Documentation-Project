// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KE
// Source by-file doc: by-file/ItemDialogs.md
// UID:000007 | by-class/AddItemDialog.md | Completion:91 | Confidence:93
#include "ItemDialogs.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ItemObjImageLib.h"
#include "../../render/Surface.h"
#include "../panels/UserPane.h"

class AddItemDialog : public DialogPane
{
public:
    AddItemDialog(unsigned int exchangeSessionId,
                  unsigned char allowMultipleSelection);
    virtual ~AddItemDialog();

    virtual int OnAction(unsigned int actionId);
    virtual int OnClosePacket(const unsigned char *packet);
    virtual void UpdateActionButton();
    void SendSelectedItemPacket(char selectedInventorySlot);

protected:
    unsigned int m_exchangeSessionId;
};

// UID:0004BM | by-memory/0x004ae4c0-0x004ae8f5.AddItemDialogConstructor.md | Completion:92 | Confidence:94
AddItemDialog::AddItemDialog(unsigned int exchangeSessionId,
                             unsigned char allowMultipleSelection)
    : DialogPane(L"", 9, 1)
{
    RectBounds bounds;
    int dialogWidth;
    int dialogHeight;

    if (g_useEpfAssets == 1)
    {
        InitRectBounds(&bounds, 0, 0, 241, 340);
        AddControl(new EPFImageControlPane(L"DLGEXC2.EPF", 0, 1,
                                            &bounds, L"PAL01.PAL"));

        InitRectBounds(&bounds, 55, 303, 118, 327);
        AddControl(new ImageButtonControlPane(36, &bounds));

        InitRectBounds(&bounds, 132, 303, 195, 327);
        AddControl(new ImageButtonControlPane(22, &bounds));

        MyItemListPane *itemList = new MyItemListPane();
        itemList->SetMultipleSelectionEnabled(allowMultipleSelection);

        InitRectBounds(&bounds, 30, 30, 218, 270);
        AddControl(new ScrollableControlPane(&bounds, itemList, 0, 0, 13));

        SetBackgroundResource(L"DLGEXC2.EPF", NULL);
        SetHoverControl(3);
        SetFocusedControl(1);
        SetPendingControl(2);
        dialogWidth = 241;
        dialogHeight = 340;
    }
    else
    {
        InitRectBounds(&bounds, 0, 0, 287, 277);
        AddControl(new EPFImageControlPane(L"DLGEXC2.EPD", 0, 1,
                                            &bounds, L"NPAL8.PAL"));

        InitRectBounds(&bounds, 69, 225, 141, 241);
        AddControl(new ImageButtonControlPane(36, &bounds));

        InitRectBounds(&bounds, 146, 225, 218, 241);
        AddControl(new ImageButtonControlPane(22, &bounds));

        MyItemListPane *itemList = new MyItemListPane();
        itemList->SetMultipleSelectionEnabled(1);

        InitRectBounds(&bounds, 36, 61, 251, 205);
        AddControl(new ScrollableControlPane(&bounds, itemList, 0, 0, 0));

        SetBackgroundResource(L"DLGEXC2.EPD", NULL);
        SetHoverControl(3);
        SetFocusedControl(1);
        SetPendingControl(2);
        dialogWidth = 287;
        dialogHeight = 277;
    }

    m_exchangeSessionId = exchangeSessionId;
    InitRectBounds(&bounds, 0, 0, dialogWidth, dialogHeight);
    OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();
    g_pAddItemDialog = this;
}

// UID:0004BN | by-memory/0x004ae900-0x004ae929.AddItemDialogDestructor.md | Completion:92 | Confidence:94
AddItemDialog::~AddItemDialog()
{
    g_pAddItemDialog = 0;
}

// UID:0004BO | by-memory/0x004ae930-0x004aea3a.AddItemDialogOnAction.md | Completion:88 | Confidence:90
int AddItemDialog::OnAction(unsigned int actionId)
{
    if (actionId == 2)
    {
        CloseDialog();
        return 0;
    }

    if (actionId != 1)
        return 0;

    ScrollableControlPane *itemListControl =
        GetChild<ScrollableControlPane>(3);
    ListPane *itemList =
        static_cast<ListPane *>(itemListControl->GetScrollablePane());
    DialogRow *selectedRows[256] = {};
    const int selectedCount = GetSelectedRows(itemList, selectedRows, 256);

    for (int i = 0; i < selectedCount; ++i)
    {
        const ItemListRow *row = static_cast<const ItemListRow *>(selectedRows[i]);
        if (row == 0)
            continue;

        unsigned char packet[8] = {};
        PacketBufferWriteUInt8(0x4a, packet);
        PacketBufferWriteUInt8(1, packet + 1);
        PacketBufferWriteUInt32BE(m_exchangeSessionId, packet + 2);
        PacketBufferWriteUInt8(row->itemId, packet + 6);
        packet[7] = 0;
        g_packetSender->QueueAndSendPacket(packet, 7);
    }

    CloseDialog();
    return 0;
}

// UID:0004BP | by-memory/0x004aea40-0x004aea7d.AddItemDialogUpdateActionButton.md | Completion:92 | Confidence:94
void AddItemDialog::UpdateActionButton()
{
    ImageButtonControlPane *actionButton =
        GetChild<ImageButtonControlPane>(1);
    ScrollableControlPane *itemListControl =
        GetChild<ScrollableControlPane>(3);
    ListPane *itemList =
        static_cast<ListPane *>(itemListControl->GetScrollablePane());

    if (itemList->GetSelectionCount() > 0)
        actionButton->Enable();
    else
        actionButton->Disable();
}

// UID:00033Q | by-memory/0x004ae4c0-0x004aea7d.AddItemDialogCore.md | Completion:88 | Confidence:92
[[No Children Attached]]

// UID:000317 | by-memory/0x004aea80-0x004aeab0.AddItemDialogExchangePacketCloseHandler.md | Completion:88 | Confidence:90
int AddItemDialog::OnClosePacket(const unsigned char *packet)
{
    if (packet != 0 && packet[0] == 0x42 && packet[1] == 0x04)
    {
        CloseDialogWindow(this);
        CloseDialog();
    }

    return 0;
}

// UID:00033R | by-memory/0x004aeab0-0x004aeb30.AddItemDialogSubmitPacketHelper.md | Completion:88 | Confidence:89
AddItemDialog *GetActiveAddItemDialog()
{
    return g_pAddItemDialog;
}

void AddItemDialog::SendSelectedItemPacket(char selectedInventorySlot)
{
    unsigned char packet[8];

    PacketBufferWriteUInt8(0x4A, packet);
    PacketBufferWriteUInt8(1, packet + 1);
    PacketBufferWriteUInt32BE(m_exchangeSessionId, packet + 2);
    PacketBufferWriteUInt8(selectedInventorySlot, packet + 6);

    packet[7] = 0;
    g_packetSender->QueueAndSendPacket(packet, 7);
}



// UID:00008W | by-class/MyItemListPane.md | Completion:92 | Confidence:93

// UID:0002JO | by-memory/0x004aeb30-0x004aec77.MyItemListPaneConstructor.md | Completion:91 | Confidence:92
MyItemListPane::MyItemListPane()
    : ListPane(
          sizeof(MyItemListEntry),
          8,
          g_useEpfAssets == 1 ? 170 : 205,
          24,
          0,
          true,
          true)
{
    const unsigned char inventorySlotCount =
        g_activeUserStatusPane->m_inventorySlotCount;

    for (char slotIndex = 1;
         slotIndex <= inventorySlotCount;
         ++slotIndex)
    {
        LocalInventorySlotRecord *slot =
            g_pUserPane->GetInventorySlotAddress(slotIndex);
        if (!slot->active)
            continue;

        MyItemListEntry entry;
        entry.slotIndex = slotIndex;
        entry.itemId = slot->itemId;
        entry.iconStyle = slot->iconStyle;
        wcscpy_s(entry.displayName, 0x100, slot->displayName);
        AddEntry(&entry);
    }
}

// UID:0002JP | by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md | Completion:91 | Confidence:93
unsigned char MyItemListPane::GetSelectedSlotIndex()
{
    const MyItemListEntry *entry =
        static_cast<const MyItemListEntry *>(
            GetItem(m_selectedIndex));
    return entry->slotIndex;
}

// UID:0002JQ | by-memory/0x004aec90-0x004af031.MyItemListPaneDrawListEntry.md | Completion:92 | Confidence:93
void MyItemListPane::DrawListEntry(
    int rowIndex,
    void *rowData,
    RectBounds *rowBounds)
{
    const MyItemListEntry *entry =
        static_cast<const MyItemListEntry *>(rowData);
    EPFTileContext tileContext;
    RectBounds drawBounds;
    wchar_t text[256];

    if (g_useEpfAssets == 1)
    {

        if (IsItemSelected(rowIndex))
        {
            SetDrawColor(37);
            g_pfnFillRect(this, rowBounds);
            SetTextColor(128);
        }
        else
        {
            SetTextColor(37);
        }

        g_pItemObjImageLib->GetItemGlyphBounds(
            static_cast<short>(entry->itemId),
            &tileContext.bounds);

        const int glyphWidth =
            tileContext.bounds.right - tileContext.bounds.left;
        const int glyphHeight =
            tileContext.bounds.bottom - tileContext.bounds.top;
        const int rowCenterY =
            (rowBounds->top + rowBounds->bottom) / 2;

        drawBounds.left = 25 - glyphWidth / 4;
        drawBounds.right = drawBounds.left + glyphWidth / 2;
        drawBounds.top = rowCenterY - glyphHeight / 4;
        drawBounds.bottom = drawBounds.top + glyphHeight / 2;

        IntersectRects(&drawBounds, rowBounds, &drawBounds);
        g_pItemObjImageLib->DrawItemImageScaled(
            this,
            &drawBounds,
            static_cast<short>(entry->itemId),
            entry->iconStyle);

        m_textDrawMode = 1;
        SetTextBackColor(0);
        wcscpy_s(text, 0x100, entry->displayName);

        drawBounds.left = 50;
        drawBounds.right = rowBounds->right;
        drawBounds.top = rowCenterY - 6;
        drawBounds.bottom = rowCenterY + 6;

        FitTextAndAppendSuffix(
            text,
            0x100,
            L"...",
            drawBounds.right - 50);
        MoveTo(drawBounds.left, drawBounds.bottom);
        DrawWideText(text, wcslen(text));
    }
    else
    {

        if (IsItemSelected(rowIndex))
        {
            SetDrawColor(37);
            g_pfnFillRect(this, rowBounds);
            SetTextColor(128);
        }
        else
        {
            SetTextColor(37);
        }

        g_pItemObjImageLib->GetItemGlyphBounds(
            static_cast<short>(entry->itemId),
            &tileContext.bounds);

        const int glyphWidth =
            tileContext.bounds.right - tileContext.bounds.left;
        const int glyphHeight =
            tileContext.bounds.bottom - tileContext.bounds.top;
        const int rowCenterY =
            (rowBounds->top + rowBounds->bottom) / 2;

        drawBounds.left = 25 - glyphWidth / 2;
        drawBounds.right = drawBounds.left + glyphWidth;
        drawBounds.top = rowCenterY - glyphHeight / 2;
        drawBounds.bottom = drawBounds.top + glyphHeight;

        g_pItemObjImageLib->DrawItemImage(
            this,
            &drawBounds,
            static_cast<short>(entry->itemId),
            entry->iconStyle,
            NULL,
            0.0f);

        m_textDrawMode = 1;
        SetTextBackColor(0);
        wcscpy_s(text, 0x100, entry->displayName);

        drawBounds.left = 50;
        drawBounds.right = rowBounds->right;
        drawBounds.top = rowCenterY - 6;
        drawBounds.bottom = rowCenterY + 6;

        FitTextAndAppendSuffix(
            text,
            0x100,
            L"...",
            drawBounds.right - 50);
        MoveTo(drawBounds.left, drawBounds.bottom);
        DrawWideText(text, wcslen(text));
    }
}

// UID:000008 | by-class/AddItemWithCountDialog.md | Completion:91 | Confidence:93
class Event;

class AddItemWithCountDialog : public DialogPane
{
public:
    AddItemWithCountDialog(unsigned int exchangeSessionId,
                           char inventorySlot);

    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual bool HandlePacketEvent(Event *event);
    virtual void UpdateActionButton();

private:
    unsigned int m_exchangeSessionId;
    char m_inventorySlot;
};

// UID:0004BQ | by-memory/0x004af040-0x004af371.AddItemWithCountDialogConstructor.md | Completion:92 | Confidence:94
AddItemWithCountDialog::AddItemWithCountDialog(unsigned int exchangeSessionId,
                                               char inventorySlot)
    : DialogPane(L"", 9, 1)
{
    RectBounds bounds;
    wchar_t promptText[256];

    InitRectBounds(&bounds, 0, 0, 239, 283);
    AddControl(new EPFImageControlPane(L"DLGEXC3.EPF", 0, 1,
                                       &bounds, L"PAL01.PAL"));

    InitRectBounds(&bounds, 50, 149, 113, 173);
    AddControl(new ImageButtonControlPane(36, &bounds));

    InitRectBounds(&bounds, 129, 149, 192, 173);
    AddControl(new ImageButtonControlPane(22, &bounds));

    LocalInventorySlotRecord *inventoryItem =
        g_pUserPane->GetInventorySlotAddress(inventorySlot);
    swprintf_s(promptText, 256,
               g_pLanguageMan->GetLocalizedString(158),
               inventoryItem->displayName);

    InitRectBounds(&bounds, 28, 35, 211, 107);
    AddControl(new StaticTextControlPane(promptText, true, 128, 0,
                                         &bounds, false, false));

    InitRectBounds(&bounds, 28, 111, 211, 123);
    AddControl(new TextEditControlPane(L"", true, 128, 0,
                                       &bounds, false, false, false, false,
                                       1.0f, 0));

    SetBackgroundResource(L"DLGEXC3.EPF", NULL);
    SetHoverControl(4);
    SetFocusedControl(1);
    SetPendingControl(2);

    m_exchangeSessionId = exchangeSessionId;
    m_inventorySlot = inventorySlot;

    InitRectBounds(&bounds, 0, 0, 239, 283);
    OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();
}

// UID:0004BR | by-memory/0x004af380-0x004af47a.AddItemWithCountDialogOnControlCommand.md | Completion:92 | Confidence:94
void AddItemWithCountDialog::OnControlCommand(int controlIndex, int notifyCode)
{
    (void)notifyCode;

    if (controlIndex == 1)
    {
        wchar_t countText[16];
        unsigned short parsedCount;
        TextEditControlPane *countInput =
            GetChild<TextEditControlPane>(4);

        countInput->ReadText(countText, 4);
        swscanf(countText, L"%hu", &parsedCount);
        if (parsedCount >= 0xff)
            parsedCount = 0xff;

        unsigned char packet[9];
        PacketBufferWriteUInt8(0x4a, packet);
        PacketBufferWriteUInt8(2, packet + 1);
        PacketBufferWriteUInt32BE(m_exchangeSessionId, packet + 2);
        PacketBufferWriteUInt8(m_inventorySlot, packet + 6);
        PacketBufferWriteUInt8(static_cast<unsigned char>(parsedCount),
                               packet + 7);
        packet[8] = 0;
        g_packetSender->QueueAndSendPacket(packet, 8);
    }
    else if (controlIndex != 2)
    {
        return;
    }

    SlideClose();
    CloseDialog();
}

// UID:0004BS | by-memory/0x004af480-0x004af4b7.AddItemWithCountDialogUpdateActionButton.md | Completion:92 | Confidence:94
void AddItemWithCountDialog::UpdateActionButton()
{
    ImageButtonControlPane *actionButton =
        GetChild<ImageButtonControlPane>(1);
    TextEditControlPane *countInput =
        GetChild<TextEditControlPane>(4);

    if (countInput->IsEmpty())
        actionButton->Disable();
    else
        actionButton->Enable();
}

// UID:000318 | by-memory/0x004af4c0-0x004af4f0.AddItemWithCountDialogHandlePacketEvent.md | Completion:92 | Confidence:94
bool AddItemWithCountDialog::HandlePacketEvent(Event *event)
{
    const unsigned char *packet = event->packet;

    if (packet[0] == 0x42 && packet[1] == 4)
    {
        SlideClose();
        CloseDialog();
    }

    return false;
}

// UID:00033S | by-memory/0x004af040-0x004af4b7.AddItemWithCountDialogCore.md | Completion:91 | Confidence:93
[[No Children Attached]]




// UID:000009 | by-class/AddMixingItemDialog.md | Completion:90 | Confidence:91
// AddMixingItemDialog method bodies are emitted by the constructor and action children.
// UID:0002U1 | by-memory/0x004b0000-0x004b0118.AddMixingItemDialogConstructor.md | Completion:88 | Confidence:90
AddMixingItemDialog::AddMixingItemDialog(MixItemDialog *mixDialog)
    : AddItemDialog(0, 1),
      m_mixDialog(mixDialog)
{
    ListPane *mixList = GetDialogListBySelector(mixDialog, 5);
    ListPane *itemList = GetDialogListBySelector(this, 3);

    const int mixCount = mixList->GetRowCount();
    for (int mixIndex = 0; mixIndex < mixCount; ++mixIndex)
    {
        const MixItemRow *mixRow = static_cast<const MixItemRow *>(mixList->GetRow(mixIndex));
        if (mixRow == 0)
            continue;

        for (int itemIndex = itemList->GetRowCount() - 1; itemIndex >= 0; --itemIndex)
        {
            const ItemListRow *itemRow = static_cast<const ItemListRow *>(itemList->GetRow(itemIndex));
            if (itemRow != 0 && itemRow->itemId == mixRow->itemId)
            {
                itemList->RemoveRow(itemIndex);
                break;
            }
        }
    }
}

// UID:0002U2 | by-memory/0x004b0120-0x004b048a.AddMixingItemDialogOnConfirm.md | Completion:88 | Confidence:90
int AddMixingItemDialog::OnAction(unsigned int actionId)
{
    if (actionId == 2)
    {
        CloseDialog();
        return 0;
    }

    if (actionId != 1)
        return 0;

    ListPane *itemList = GetDialogListBySelector(this, 3);
    DialogRow *selectedRows[256] = {};
    const int selectedCount = GetSelectedRows(itemList, selectedRows, 256);

    for (int i = 0; i < selectedCount; ++i)
    {
        const ItemListRow *itemRow = static_cast<const ItemListRow *>(selectedRows[i]);
        if (itemRow == 0)
            continue;

        InventorySlot *slot = GetInventorySlot(itemRow->itemId);
        if (slot == 0)
            continue;

        if (slot->count <= 1)
        {
            m_mixDialog->OnMixItemQuantity(1, itemRow->itemId, itemRow->style);
            continue;
        }

        DoubleParamMemberFunctionObject *callback =
            new DoubleParamMemberFunctionObject(m_mixDialog, &MixItemDialog::OnMixItemQuantity, itemRow->itemId, itemRow->style);

        NumberInputDialog *dialog =
            new NumberInputDialog(218, 1, slot->count, callback);

        dialog->Show();
    }

    CloseDialog();
    return 0;
}


// UID:00008J | by-class/MixItemDialog.md | Completion:91 | Confidence:93
class MixItemDialog : public DialogPane,
                      public Singleton<MixItemDialog>
{
public:
    MixItemDialog();

    virtual int OnAction(unsigned int actionId);

    void AddMixItem(unsigned char itemId,
                    unsigned short itemSerial,
                    const wchar_t *itemName,
                    unsigned char style);

private:
    void SubmitMixPacket();
    void OnMixItemQuantity(unsigned int count,
                           unsigned char itemId,
                           unsigned char style);
};

// UID:0004BT | by-memory/0x004af570-0x004af8af.MixItemDialogConstructor.md | Completion:92 | Confidence:94
MixItemDialog::MixItemDialog()
    : DialogPane(L"", 9, 1),
      Singleton<MixItemDialog>()
{
    RectBounds bounds;

    InitRectBounds(&bounds, 0, 0, 292, 309);
    AddControl(new EPFImageControlPane(L"MIXITEM.EPF", 0, 1,
                                        &bounds, L"MIXITEM.PAL"));

    InitRectBounds(&bounds, 23, 273, 86, 297);
    AddControl(new ImageButtonControlPane(36, &bounds));

    InitRectBounds(&bounds, 85, 273, 148, 297);
    AddControl(new ImageButtonControlPane(21, &bounds));

    InitRectBounds(&bounds, 147, 273, 210, 297);
    AddControl(new ImageButtonControlPane(14, &bounds));

    InitRectBounds(&bounds, 209, 273, 272, 297);
    AddControl(new ImageButtonControlPane(22, &bounds));

    MyItemListPane *itemList = new MyItemListPane();

    InitRectBounds(&bounds, 37, 68, 264, 236);
    AddControl(new ScrollableControlPane(&bounds, itemList, 0, 0, 0));

    SetBackgroundResource(L"MIXITEM.EPF", NULL);
    SetHoverControl(1);
    SetFocusedControl(3);
    SetPendingControl(4);

    InitRectBounds(&bounds, 0, 0, 292, 309);
    OnCreate(&bounds, 0, NULL,
             g_mainUiLayerSlots.overlayPaneLayerContext);

    for (int itemIndex = itemList->GetItemCount() - 1;
         itemIndex >= 0;
         --itemIndex)
    {
        itemList->RemoveItems(itemIndex, 1);
    }

    OnShow(NULL, NULL);
    SlideOpenVertical();
}

// UID:0004BU | by-memory/0x004af8b0-0x004afb65.MixItemDialogOnAction.md | Completion:88 | Confidence:90
int MixItemDialog::OnAction(unsigned int actionId)
{
    switch (actionId)
    {
    case 1:
        new AddMixingItemDialog(this);
        return 0;

    case 2:
        RemoveSelectedMixItems();
        return 0;

    case 3:
        SendMixPacketFromRows();
        CloseDialog();
        return 0;

    case 4:
        CloseDialog();
        return 0;
    }

    return 0;
}

// UID:00033V | by-memory/0x004afb80-0x004afcc0.MixItemDialogSubmitPacketHelper.md | Completion:88 | Confidence:89
void MixItemDialog::SubmitMixPacket()
{
    ListPane *mixList = GetDialogPage(5)->m_list;
    int itemCount = mixList->GetCount();

    unsigned char packet[0x110];
    int packetLength = 0;

    if (itemCount > 0)
    {
        PacketBufferWriteUInt8(0x6b, packet + packetLength);
        ++packetLength;

        PacketBufferWriteUInt8((unsigned char)itemCount, packet + packetLength);
        ++packetLength;

        for (int index = 0; index < itemCount; ++index)
        {
            MixItemRow *row = (MixItemRow *)mixList->GetItem(index);

            PacketBufferWriteUInt8(row->itemId, packet + packetLength);
            ++packetLength;

            ItemInfo *itemInfo = g_pCollectionData->GetItemInfo(row->itemId);
            if (itemInfo->isStackable)
                PacketBufferAppendUInt8((unsigned char)row->quantity, packet, &packetLength);
        }

        g_packetSender->QueueAndSendPacket(packet, packetLength);
    }

    SlideClose();
    CloseDialog();
}

// UID:000319 | by-memory/0x004afcc0-0x004afe38.MixItemDialogQuantityPromptHelper.md | Completion:88 | Confidence:90
void MixItemDialog::AddMixItem(unsigned char itemId, unsigned short itemSerial, const wchar_t *itemName, unsigned char style)
{
    ListPane *mixList = GetDialogListBySelector(this, 5);
    InventorySlot *slot = GetInventorySlot(itemId);

    if (slot == 0 || slot->count <= 1)
    {
        MixItemRow row = {};
        row.itemId = itemId;
        row.itemSerial = itemSerial;
        row.style = style;
        row.count = 1;
        CopyWideString(row.name, itemName, sizeof(row.name) / sizeof(row.name[0]));
        mixList->AppendRow(&row);
        return;
    }

    DoubleParamMemberFunctionObject *callback =
        new DoubleParamMemberFunctionObject(this, &MixItemDialog::OnMixItemQuantity, itemId, style);

    NumberInputDialog *dialog =
        new NumberInputDialog(218, 1, slot->count, callback);

    dialog->Show();
}

// UID:00031A | by-memory/0x004afe40-0x004afff7.MixItemDialogQuantityCallback.md | Completion:88 | Confidence:90
void MixItemDialog::OnMixItemQuantity(unsigned int count, unsigned char itemId, unsigned char style)
{
    ListPane *mixList = GetDialogListBySelector(this, 5);
    InventorySlot *slot = GetInventorySlot(itemId);

    if (slot == 0)
        return;

    MixItemRow row = {};
    row.itemId = itemId;
    row.itemSerial = GetInventorySlotSerial(slot);
    row.style = style;
    row.count = count;

    FormatWideString(row.countText, sizeof(row.countText) / sizeof(row.countText[0]), L"%d", count);
    CopyWideString(row.name, GetInventorySlotName(slot), sizeof(row.name) / sizeof(row.name[0]));

    mixList->AppendRow(&row);
}

// UID:0002AY | by-memory/0x0069b328-0x0069b330.ItemDialogSingletonGlobals.md | Completion:92 | Confidence:95
static AddItemDialog *g_pAddItemDialog = 0;
static MixItemDialog *g_pMixItemDialog = 0;

// UID:0003NH | by-memory\0x0061a344-0x0061a374.AddItemDialogResourceStrings.md | Completion:85 | Confidence:90 | Empty Emitter Marker

// UID:0003ID | by-type\by-vtable\AddItemDialogVtables.md | Completion:90 | Confidence:93 | Empty Emitter Marker

// UID:0001VE | by-type\by-struct\MyItemListPaneEntryLayouts.md | Completion:90 | Confidence:92 | Empty Emitter Marker

// UID:00033T | by-memory\0x004af4f0-0x004af570.AddItemWithCountDialogSubmitPacketHelper.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003NI | by-memory\0x0061a374-0x0061a37c.AddItemWithCountDialogQuantityFormatString.md | Completion:85 | Confidence:89 | Empty Emitter Marker

// UID:0003IE | by-type\by-vtable\AddItemWithCountDialogVtables.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0003IF | by-type\by-vtable\AddMixingItemDialogVtables.md | Completion:88 | Confidence:92 | Empty Emitter Marker
