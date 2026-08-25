// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000J0
// Source by-file doc: by-file/EmployeeDialogPane.md
// UID:000006 | by-class/AddEmployeeItemDialog.md | Completion:88 | Confidence:90
// [UID:000006] AddEmployeeItemDialog class route marker.
// Exact handler/destructor and vtable-data children carry the EmployeeDialogPane.cpp source output; do not duplicate child method bodies here.
// UID:00013A | by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md | Completion:88 | Confidence:90
void AddEmployeeItemDialog::OnButtonClick(int buttonId, int buttonParam)
{
    if (buttonId != 1) {
        AddItemDialog::OnButtonClick(buttonId, buttonParam);
        return;
    }

    ItemSelectionList *list = m_controls->GetControl(3)->m_selectionList;

    unsigned char selectedRows[0x100];
    int selectedCount = list->GetSelectedRows(selectedRows, 0x100);

    if (selectedCount > 1) {
        new AlertPane(
            kCannotAddMultipleEmployeeItemsText,
            this,
            kDialogOkButtonText,
            0);

        SlideClose();
        CloseDialog();
        return;
    }

    SelectionRow *row = list->GetSelectedRow(selectedRows[0]);
    signed char selectedSlot = static_cast<signed char>(row->slot);

    EmployeeDialogPane *owner = m_owner;
    ItemRecord *item = g_pCurrentUserPane->GetInventoryItem(selectedSlot);

    owner->m_pendingQuantity = 0;

    if (item->requiresQuantityPrompt) {
        char prompt[0x100];
        FormatString(prompt, sizeof(prompt), g_resourceManager->GetString(247));

        new EmployeeQuantityInputDialogPane(prompt, owner, selectedSlot);
    } else {
        owner->m_timerHandler.ScheduleTimer(
            5,
            0,
            selectedSlot,
            item->stackCount);
    }

    SlideClose();
    CloseDialog();
}

AddEmployeeItemDialog::~AddEmployeeItemDialog()
{
}

// UID:0002MH | by-memory/0x006190d0-0x0061916c.AddEmployeeItemDialogVtableData.md | Completion:88 | Confidence:93
// Emitted code for this AddEmployeeItemDialog vtable/RTTI range is covered by
// [UID:000006][AddEmployeeItemDialog](by-class/AddEmployeeItemDialog.md) AddEmployeeItemDialog class declarations and [UID:00013A][0x004a4b20-0x004a4d3b.AddEmployeeItemDialog](by-memory/0x004a4b20-0x004a4d3b.AddEmployeeItemDialog.md)
// virtual method/destructor source in EmployeeDialogPane.cpp; do not hand-emit
// raw .rdata vtable bytes.

// UID:0001TN | by-type/by-struct/AddEmployeeItemDialogLayout.md | Completion:85 | Confidence:89
// [UID:0001TN] AddEmployeeItemDialog layout evidence marker.
// The derived owner pointer and vtable views are represented through the class and exact child pages; no standalone layout body is emitted here.
[[No Children Attached]]

// UID:00004C | by-class/EmployeeDialogPane.md | Completion:90 | Confidence:93
// [UID:00004C] EmployeeDialogPane class route marker.
// Exact method, raw-island marker, vtable-data, and resource children carry EmployeeDialogPane.cpp output; broad class declaration C++ is deferred.

// UID:0003KR | by-memory/0x004a22f0-0x004a23a8.EmployeeDialogPaneDestructor.md | Completion:93 | Confidence:96
EmployeeDialogPane::~EmployeeDialogPane()
{
    if (m_employeeRecords != NULL) {
        free(m_employeeRecords);
    }

    unsigned char *packet = m_commandPacketBuffer;
    PacketBufferWriteUInt8(kEmployeePacketOpcode, packet);
    PacketBufferWriteUInt8(kEmployeePacketFamily, packet + 1);
    PacketBufferWriteUInt32BE(m_employeeDialogId, packet + 2);
    PacketBufferWriteUInt8(8, packet + 6);
    g_packetSender->QueueAndSendPacket(packet, 7);
}




// UID:0003KW | by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md | Completion:91 | Confidence:92
bool EmployeeDialogPane::SendCommand(int commandId, unsigned int argument0, unsigned int argument1)
{
    unsigned char *packet = m_commandPacketBuffer;

    switch (commandId) {
    case kEmployeeCommandBytePayload:
        PacketBufferWriteUInt8(kEmployeePacketOpcode, packet);
        PacketBufferWriteUInt8(kEmployeePacketFamily, packet + 1);
        PacketBufferWriteUInt32BE(m_employeeDialogId, packet + 2);
        PacketBufferWriteUInt8(kEmployeeCommandBytePayload, packet + 6);
        PacketBufferWriteUInt8(static_cast<unsigned char>(argument0), packet + 7);
        PacketBufferWriteUInt32BE(argument1, packet + 8);
        packet[12] = 0;
        g_packetSender->QueueAndSendPacket(packet, 12);
        return true;

    case kEmployeeCommandDwordPair:
        PacketBufferWriteUInt8(kEmployeePacketOpcode, packet);
        PacketBufferWriteUInt8(kEmployeePacketFamily, packet + 1);
        PacketBufferWriteUInt32BE(m_employeeDialogId, packet + 2);
        PacketBufferWriteUInt8(kEmployeeCommandDwordPair, packet + 6);
        PacketBufferWriteUInt32BE(argument0, packet + 7);
        PacketBufferWriteUInt32BE(argument1, packet + 11);
        PacketBufferWriteUInt16BE(0, packet + 15);
        PacketBufferWriteUInt16BE(0, packet + 17);
        g_packetSender->QueueAndSendPacket(packet, 19);
        return true;

    case kEmployeeCommandUpdatePropertyPrice:
        PacketBufferWriteUInt8(kEmployeePacketOpcode, packet);
        PacketBufferWriteUInt8(kEmployeePacketFamily, packet + 1);
        PacketBufferWriteUInt32BE(m_employeeDialogId, packet + 2);
        PacketBufferWriteUInt8(kEmployeeCommandUpdatePropertyPrice, packet + 6);
        PacketBufferWriteUInt32BE(argument0, packet + 7);
        PacketBufferWriteUInt32BE(m_pendingPropertyPriceValue, packet + 11);
        PacketBufferWriteUInt32BE(m_pendingPropertyPriceState, packet + 15);
        g_packetSender->QueueAndSendPacket(packet, 19);
        return true;

    case kEmployeeCommandRemovePropertyItem:
        PacketBufferWriteUInt8(kEmployeePacketOpcode, packet);
        PacketBufferWriteUInt8(kEmployeePacketFamily, packet + 1);
        PacketBufferWriteUInt32BE(m_employeeDialogId, packet + 2);
        PacketBufferWriteUInt8(kEmployeeCommandRemovePropertyItem, packet + 6);
        PacketBufferWriteUInt32BE(argument0, packet + 7);
        g_packetSender->QueueAndSendPacket(packet, 11);
        return true;

    case kEmployeeCommandCloseDialog:
        PacketBufferWriteUInt8(kEmployeePacketOpcode, packet);
        PacketBufferWriteUInt8(kEmployeePacketFamily, packet + 1);
        PacketBufferWriteUInt32BE(m_employeeDialogId, packet + 2);
        PacketBufferWriteUInt8(kEmployeeCommandCloseDialog, packet + 6);
        g_packetSender->QueueAndSendPacket(packet, 7);
        SlideClose();
        CloseDialog();
        return true;

    case kEmployeeCommandSubmitQuantity:
        m_pendingQuantitySlot = argument0;
        m_pendingQuantityCount = argument1;

        if (m_pendingQuantity == 0) {
            m_timerHandler.ScheduleTimer(
                kEmployeeCommandBytePayload,
                0,
                argument0,
                argument1);
            return true;
        }

        if (m_pendingQuantity == 1) {
            m_timerHandler.ScheduleTimer(
                kEmployeeCommandDwordPair,
                0,
                m_pendingQuantityFallbackSlot,
                argument1);
        }
        return true;
    }

    return true;
}






// UID:0002ME | by-memory/0x00618efc-0x00618f98.EmployeeDialogPaneVtableData.md | Completion:93 | Confidence:96
// Emitted code for this EmployeeDialogPane vtable/RTTI range is covered by
// [UID:00004C][EmployeeDialogPane](by-class/EmployeeDialogPane.md) EmployeeDialogPane class declarations and the linked virtual
// method children, including [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md) EmployeeDialogPane::SendCommand;
// the source-declared virtual destructor is implemented by [UID:0003KR][0x004a22f0-0x004a23a8.EmployeeDialogPaneDestructor](by-memory/0x004a22f0-0x004a23a8.EmployeeDialogPaneDestructor.md), while [UID:0003L4][0x004a4d40-0x004a4e27.EmployeeDialogPaneScalarDeletingDestructor](by-memory/0x004a4d40-0x004a4e27.EmployeeDialogPaneScalarDeletingDestructor.md) and its adjustor thunks are compiler-generated ABI artifacts;
// do not hand-emit raw .rdata vtable bytes.

// UID:0001UD | by-type/by-struct/EmployeeRecord.md | Completion:88 | Confidence:92
// [UID:0001UD] EmployeeRecord layout evidence marker.
// Exact parser and dialog method children consume this record layout; a standalone final struct declaration is deferred until field names and header placement are source-final.
// EmployeeDialogPane owns a heap array through its final pointer at +0x84c and releases it in the source destructor represented by UID0003KR.
[[No Children Attached]]

// UID:00004D | by-class/EmployeeItemPropertyDialogPane.md | Completion:90 | Confidence:93
// [UID:00004D] EmployeeItemPropertyDialogPane class route marker.
// Exact constructor, paint, command, layout, and vtable-data children carry source or marker output; UID0003L5 is compiler-only evidence and emits nothing.
// UID:0002HE | by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md | Completion:90 | Confidence:91
EmployeeItemPropertyDialogPane::EmployeeItemPropertyDialogPane(
    EmployeeRecord *itemRecord,
    EmployeeDialogPane *owner)
    : DialogPane(L"Property", 20, true)
{
    RectBounds rect;
    wchar_t editPriceText[128];
    wchar_t itemName[256];
    wchar_t priceText[128];

    m_owner = owner;
    m_itemRecord = itemRecord;

    InitRectBounds(&rect, 42, 90, 105, 114);
    AddControl(new ImageButtonControlPane(53, rect));

    InitRectBounds(&rect, 119, 90, 182, 114);
    AddControl(new ImageButtonControlPane(14, rect));

    InitRectBounds(&rect, 196, 90, 259, 114);
    AddControl(new ImageButtonControlPane(22, rect));

    InitRectBounds(&rect, 120, 47, 283, 59);
    swprintf_s(editPriceText, 128, L"%u", m_itemRecord->editablePriceValue);
    AddControl(new TextEditControlPane(editPriceText, true, 143, 128, rect));

    InitRectBounds(&m_itemIconRect, 20, 21, 68, 69);

    wcscpy_s(itemName, 256, m_itemRecord->name);
    InitRectBounds(&rect, 120, 25, 180, 37);
    AddControl(new StaticTextControlPane(itemName, true, 143, 128, rect));

    swprintf_s(priceText, 128, L"%d", m_itemRecord->priceValue);
    InitRectBounds(&rect, 259, 25, 287, 37);
    AddControl(new StaticTextControlPane(priceText, true, 143, 128, rect));

    SetDefaultAction(kEmployeeItemPropertyConfirmAction);
    SetCancelAction(kEmployeeItemPropertyCloseAction);
    SetInitialFocus(kEmployeeItemPropertyPriceEditControlId);

    InitRectBounds(&rect, 0, 0, 307, 124);
    Create(rect, 0, 0, overlayPaneLayerContext);
    Show(false, g_pMainMenuPane);
    SlideOpen();
}

// UID:0002HF | by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md | Completion:89 | Confidence:91
void EmployeeItemPropertyDialogPane::OnPaint()
{
    EPFTileContext sellItemTile;
    EPFTileContext itemGlyphContext;
    RectBounds iconRect;


    DialogPane::OnPaint();
    SetDrawColor(143);
    SetTextColor(143);

    g_pEPFLib->LookupLayoutEntry(L"SELLITEM.EPF", 0, &sellItemTile);
    RenderTileFrame(&sellItemTile,
                    &sellItemTile.bounds,
                    &m_bounds,
                    0,
                    L"SELLITEM.PAL",
                    0);

    GetItemGlyphBounds(m_itemRecord->itemImageId, &itemGlyphContext.bounds);

    iconRect = m_itemIconRect;
    iconRect.right = iconRect.left + 44;
    iconRect.bottom = iconRect.top + 44;

    g_pItemObjImageLib->DrawItemImageIn43x43Slot(
        this,
        &iconRect,
        m_itemRecord->itemImageId,
        m_itemRecord->itemPaletteFlags,
        NULL,
        0.0f);
}

// UID:0002HG | by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md | Completion:88 | Confidence:91
void EmployeeItemPropertyDialogPane::OnCommand(int actionId, int actionParam)
{
    (void)actionParam;

    if (actionId == kEmployeeItemPropertyConfirmAction) {
        if (m_owner != NULL) {
            int price = m_itemRecord->editablePriceValue;
            wchar_t priceText[128];
            TextEditControlPane *priceEdit =
                static_cast<TextEditControlPane *>(
                    m_controlManager->GetControl(kEmployeeItemPropertyPriceEditControlId));

            priceEdit->ReadText(priceText, 128);
            swscanf(priceText, L"%d", &price);

            if (price != 0) {
                m_owner->m_pendingPropertyPriceValue = price;
                m_owner->m_pendingPropertyPriceState = 1;
                m_owner->m_timerHandler.ScheduleTimer(
                    kEmployeeCommandUpdatePropertyPrice,
                    0,
                    m_itemRecord->employeeItemId,
                    0);
                SlideClose();
                CloseDialog();
            }
        }
        return;
    }

    if (actionId == kEmployeeItemPropertyRemoveAction) {
        if (m_owner != NULL) {
            m_owner->m_timerHandler.ScheduleTimer(
                kEmployeeCommandRemovePropertyItem,
                0,
                m_itemRecord->employeeItemId,
                m_itemRecord->priceValue);
        }
        SlideClose();
        CloseDialog();
        return;
    }

    if (actionId == kEmployeeItemPropertyCloseAction) {
        SlideClose();
        CloseDialog();
    }
}

// UID:0002MF | by-memory/0x00618f98-0x00619034.EmployeeItemPropertyDialogPaneVtableData.md | Completion:90 | Confidence:93
// Emitted code for this EmployeeItemPropertyDialogPane vtable/RTTI range is covered by
// [UID:00004D][EmployeeItemPropertyDialogPane](by-class/EmployeeItemPropertyDialogPane.md) EmployeeItemPropertyDialogPane class declarations, [UID:0002HE][0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor](by-memory/0x004a41c0-0x004a456b.EmployeeItemPropertyDialogPaneConstructor.md),
// [UID:0002HF][0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint](by-memory/0x004a4570-0x004a4659.EmployeeItemPropertyDialogPaneOnPaint.md), and [UID:0002HG][0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand](by-memory/0x004a4660-0x004a476e.EmployeeItemPropertyDialogPaneOnCommand.md) method source, with [UID:0003L5][0x004a4e30-0x004a4e6b.EmployeeItemPropertyDialogPaneScalarDeletingDestructor](by-memory/0x004a4e30-0x004a4e6b.EmployeeItemPropertyDialogPaneScalarDeletingDestructor.md) documenting the
// compiler-only, non-emitting deleting-destructor evidence; do not hand-emit raw .rdata vtable bytes or wrapper source.

// UID:0001UB | by-type/by-struct/EmployeeItemPropertyDialogPaneLayout.md | Completion:88 | Confidence:93
// [UID:0001UB] EmployeeItemPropertyDialogPane layout evidence marker.
// Derived tail fields support exact property-dialog method children; no standalone layout/body C++ is emitted here.
[[No Children Attached]]

// UID:00004E | by-class/EmployeeQuantityInputDialogPane.md | Completion:88 | Confidence:91
// [UID:00004E] EmployeeQuantityInputDialogPane class route marker.
// Exact constructor, action, layout, and vtable-data children carry source or marker output; do not duplicate method bodies here.
// UID:0002HH | by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md | Completion:89 | Confidence:91
EmployeeQuantityInputDialogPane::EmployeeQuantityInputDialogPane(
    const wchar_t *promptText,
    EmployeeDialogPane *owner,
    char selectedIndex)
    : DialogPane(L"Quantity", 19, true)
{
    RectBounds rect;

    InitRectBounds(&rect, 0, 0, 239, 283);
    AddControl(new EPFImageControlPane(
        L"DLGEXC3.EPF",
        0,
        true,
        rect,
        L"PAL01.PAL"));

    InitRectBounds(&rect, 50, 149, 113, 173);
    AddControl(new ImageButtonControlPane(14, rect));

    InitRectBounds(&rect, 129, 149, 192, 173);
    AddControl(new ImageButtonControlPane(22, rect));

    InitRectBounds(&rect, 30, 60, 197, 72);
    AddControl(new StaticTextControlPane(promptText, false, 128, rect));

    InitRectBounds(&rect, 28, 111, 211, 123);
    AddControl(new TextEditControlPane(L"", true, 143, rect));

    SetBackgroundResource(L"DLGEXC3.EPF", 0);
    SetDefaultAction(1);
    SetCancelAction(2);
    SetInitialFocus(4);

    m_owner = owner;
    m_selectedIndex = selectedIndex;

    InitRectBounds(&rect, 0, 0, 239, 283);
    Create(rect, 0, 0, dword_69B36C);
    Show(false, g_pMainMenuPane);
    SlideOpen();
}

// UID:0002HI | by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md | Completion:89 | Confidence:92
void EmployeeQuantityInputDialogPane::OnAction(int actionId, int actionParam)
{
    (void)actionParam;

    if (actionId == kEmployeeQuantityConfirmAction) {
        if (m_owner != NULL) {
            int quantity;
            wchar_t quantityText[128];
            TextEditControlPane *quantityEdit =
                static_cast<TextEditControlPane *>(
                    m_controlManager->GetControl(kEmployeeQuantityEditControlId));

            quantityEdit->ReadText(quantityText, 128);
            swscanf(quantityText, L"%d", &quantity);

            m_owner->m_timerHandler.ScheduleTimer(
                kEmployeeCommandSubmitQuantity,
                0,
                m_selectedIndex,
                quantity);
        }

        SlideClose();
        CloseDialog();
        return;
    }

    if (actionId == kEmployeeQuantityCloseAction) {
        SlideClose();
        CloseDialog();
    }
}

// UID:0002MG | by-memory/0x00619034-0x006190d0.EmployeeQuantityInputDialogPaneVtableData.md | Completion:90 | Confidence:93
// Emitted code for this EmployeeQuantityInputDialogPane vtable/RTTI range is covered by
// [UID:00004E][EmployeeQuantityInputDialogPane](by-class/EmployeeQuantityInputDialogPane.md) EmployeeQuantityInputDialogPane class declarations plus [UID:0002HH][0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor](by-memory/0x004a4770-0x004a4a25.EmployeeQuantityInputDialogPaneConstructor.md)
// constructor and [UID:0002HI][0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction](by-memory/0x004a4a30-0x004a4adb.EmployeeQuantityInputDialogPaneOnAction.md) OnAction source in EmployeeDialogPane.cpp; do not
// hand-emit raw .rdata vtable bytes.

// UID:0001UC | by-type/by-struct/EmployeeQuantityInputDialogPaneLayout.md | Completion:86 | Confidence:91
// [UID:0001UC] EmployeeQuantityInputDialogPane layout evidence marker.
// Owner/index tail fields support exact quantity-dialog method children; no standalone layout/body C++ is emitted here.
[[No Children Attached]]

// UID:0000UL | by-item/EmployeeDialogPacketAndRecordHelpers_4a2450_4a3be0.md | Completion:86 | Confidence:89
// [UID:0000UL] no standalone packet/record helper-family body.
// Exact modeled helper children and raw-island marker pages own output; do not emit duplicate raw helper C++ from this grouping page.
[[No Children Attached]]

// UID:000138 | by-memory/0x004a1d70-0x004a4e6b.EmployeeDialogPanes.md | Completion:92 | Confidence:94
// [UID:000138] no monolithic EmployeeDialogPanes body.
// This range is a source-family aggregate; exact class, helper, raw-island, thunk, destructor, vtable, and resource children own generated output.
[[No Children Attached]]


// UID:0002HD | by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md | Completion:90 | Confidence:92
static int __stdcall DeserializeEmployeeRecord(const unsigned char *packet, EmployeeRecord *record)
{
    const unsigned int itemId = PacketBufferReadUInt32BE(packet);
    record->employeeItemId = itemId;

    if (itemId == 0) {
        record->fallbackItemId = PacketBufferReadUInt32BE(packet + 4);
        record->itemImageId = 0;
        return 8;
    }

    char nameBytes[256];
    wchar_t suffix[256];

    record->itemImageId = PacketBufferReadUInt16BE(packet + 4);
    record->itemPaletteFlags = packet[6];

    const unsigned int nameLength = packet[7];
    GetMemoryMan()->MemmoveWrapper(nameBytes, packet + 8, nameLength);
    nameBytes[nameLength] = '\0';

    const int wideLength = MultiByteToWideChar(
        CP_ACP,
        0,
        nameBytes,
        nameLength,
        record->name,
        256);
    record->name[wideLength] = L'\0';

    const unsigned char percent = packet[8 + nameLength];
    if (percent != 0xff) {
        swprintf_s(suffix, 256, L"(%d%%)", percent);
        wcscat_s(record->name, 256, suffix);
    }

    record->statusText[0] = L'\0';
    record->priceValue = PacketBufferReadUInt32BE(packet + nameLength + 9);
    record->editablePriceValue = PacketBufferReadUInt32BE(packet + nameLength + 13);
    record->dataField3 = PacketBufferReadUInt32BE(packet + nameLength + 17);

    return static_cast<int>(nameLength + 21);
}

// UID:0003L0 | by-memory/0x004a3650-0x004a3a90.EmployeeDialogRawPacketHelpers.md | Completion:88 | Confidence:90
// Emitted source for this retained raw packet-helper island is covered by
// [UID:0002HD][0x004a34d0-0x004a3644.DeserializeEmployeeRecord](by-memory/0x004a34d0-0x004a3644.DeserializeEmployeeRecord.md) DeserializeEmployeeRecord and [UID:0003KW][0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand](by-memory/0x004a2c80-0x004a2f5d.EmployeeDialogPaneSendCommand.md) EmployeeDialogPane::SendCommand.
// No callable route to the raw starts in this range is currently proven; do not
// hand-emit duplicate unreferenced helper bodies.

// UID:0003L2 | by-memory/0x004a3be0-0x004a3e10.EmployeeDialogRawRecordMutationHelpers.md | Completion:88 | Confidence:90
// Raw EmployeeDialogPane record-mutation island retained as no-body evidence.
// No standalone C++ helper is emitted because the raw upsert/remove starts have
// no proven callable source entries; do not hand-emit raw helper bodies here.

// UID:000256 | by-memory/0x00618efc-0x0061929c.EmployeeDialogReadOnlyData.md | Completion:90 | Confidence:92
// [UID:000256] no monolithic employee-dialog .rdata body.
// Exact vtable-data and resource-tail children plus consuming declarations own output; do not hand-author one pooled vtable/string table here.
[[No Children Attached]]

// UID:0003V6 | by-memory/0x0061916c-0x0061929c.EmployeeDialogResourceLiteralTail.md | Completion:89 | Confidence:93
// Emitted code for this mixed employee-dialog resource literal tail is covered
// by the consuming EmployeeDialogPane.cpp methods and resource/string
// declarations; do not hand-emit the pooled .rdata tail as one aggregate table.

// UID:0001OE | by-memory/0x0061929c-0x006192c6.AddEmployeeSingleSelectionAlertText.md | Completion:92 | Confidence:94
static const wchar_t kCannotAddMultipleEmployeeItemsText[] =
    L"한번에 여러개를 추가할 수 없습니다.";

// UID:0001XH | by-type/by-vtable/EmployeeDialogPaneVtables.md | Completion:92 | Confidence:95
// [UID:0001XH] no standalone employee-dialog vtable-family body.
// Vtable clusters are compiler-emitted ABI data; exact vtable-data children and class/method declarations own generated output.
[[No Children Attached]]

// UID:0003KQ | by-memory\0x004a1d70-0x004a22ef.EmployeeDialogPaneConstructor.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003KT | by-memory\0x004a2450-0x004a2531.EmployeeInventoryItemCommandHelper.md | Completion:86 | Confidence:88 | Empty Emitter Marker

// UID:0003KU | by-memory\0x004a2560-0x004a2a51.EmployeeDialogPaneOnPaint.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003KV | by-memory\0x004a2a60-0x004a2c78.EmployeeDialogPaneOnMouseInput.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0003KX | by-memory\0x004a2f60-0x004a322c.EmployeeDialogPanePacketDispatcher.md | Completion:87 | Confidence:90 | Empty Emitter Marker

// UID:0003KY | by-memory\0x004a3240-0x004a33d8.EmployeeDialogPaneOnButtonAction.md | Completion:88 | Confidence:90 | Empty Emitter Marker

// UID:0003KZ | by-memory\0x004a33e0-0x004a34cb.EmployeeDialogPaneRebuildSelectionList.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0003L1 | by-memory\0x004a3a90-0x004a3bdf.EmployeeDialogPaneLoadEmployeeData.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0003L3 | by-memory\0x004a3e10-0x004a4057.EmployeeDialogPaneUpdateEmployeeFields.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0003KS | by-memory\0x004a23d0-0x004a23ef.EmployeeDialogPacketLoadPredicate.md | Completion:86 | Confidence:89 | Empty Emitter Marker
