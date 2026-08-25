// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000J9
// Source by-file doc: by-file/ExchangeDialog.md
// UID:00004T | by-class/ExchangeMoneyEditControlPane.md | Completion:93 | Confidence:95
#include "../controls/TextEditControlPane.h"
#include "../core/Event.h"

namespace
{
class ExchangeMoneyEditControlPane : public TextEditControlPane
{
public:
    ExchangeMoneyEditControlPane(const RectBounds &bounds,
                                 const wchar_t *initialText)
        : TextEditControlPane(initialText, true, 128, 0, &bounds,
                              false, false, false, false, 1.0f, true)
    {
    }

    virtual bool HandleKeyOrTextEvent(Event *event);

protected:
    virtual void Activate();
};
}

// UID:000340 | by-memory/0x004b0b40-0x004b0b54.ExchangeMoneyEditControlPaneActivationHelper.md | Completion:94 | Confidence:95
void ExchangeMoneyEditControlPane::Activate()
{
    SetEditActiveState(true, true);
    TextEditControlPane::Activate();
}

// UID:000341 | by-memory/0x004b0b60-0x004b0b96.ExchangeMoneyEditControlPaneDigitKeyHandler.md | Completion:94 | Confidence:95
bool ExchangeMoneyEditControlPane::HandleKeyOrTextEvent(Event *event)
{
    if (event->m_type != kEventTextInput ||
        event->m_payload.m_text.m_length != 1)
        return false;

    const wchar_t inputCharacter = event->m_payload.m_text.m_text[0];
    if (inputCharacter < L'0' || inputCharacter > L'9')
        return false;

    TextEditControlPane::HandleKeyOrTextEvent(event);
    return true;
}


// UID:00004Q | by-class/ExchangeAlertPane.md | Completion:88 | Confidence:90
// ExchangeAlertPane source bodies are carried by exact child pages in this source file route.
// This class marker intentionally does not emit a full member layout because inherited
// DialogPane fields and exact original header order are not source-quality from current evidence.
class ExchangeAlertPane;

// UID:0004CF | by-memory/0x004b0490-0x004b0819.ExchangeAlertPaneConstructor.md | Completion:88 | Confidence:90
// ExchangeAlertPane::ExchangeAlertPane is source-authored, and the named helper
// routes are reconciled to DialogPane, RectBounds, GrafPort/GetBounds, StaticTextControlPane,
// TextButtonControlPane, GetMemoryMan, and alert-layout helpers.
// This exact child intentionally emits no constructor body: the live binary has an
// unexercised right-button-only branch that uses the saved-this/EH local low word
// as the wrapped-text width. All live ExchangeDialog callers pass a left OK button
// and no right button. A plausible C++ body would either invent corrected behavior
// for that branch or transcribe an uninitialized/decompiler-shaped width value.

// UID:0004CG | by-memory/0x004b0820-0x004b0860.ExchangeAlertPaneOnButtonClick.md | Completion:88 | Confidence:91
void ExchangeAlertPane::OnButtonClick(int buttonId)
{
    if (buttonId < 1 || buttonId > 2)
        return;

    SlideClose();

    if (buttonId == 1)
        OnPrimaryButton();
    else
        OnSecondaryButton();

    CloseDialogPane();
}

// UID:0004CH | by-memory/0x004b0860-0x004b086b.ExchangeAlertPaneSingletonClearHelper.md | Completion:88 | Confidence:92
static void ClearExchangeAlertPaneSingleton()
{
    g_pExchangeAlertPane = NULL;
}

// UID:00033Z | by-memory/0x004b0b20-0x004b0b31.ExchangeAlertPaneCloseActiveHelper.md | Completion:88 | Confidence:92
static void CloseActiveExchangeAlertPane()
{
    if (g_pExchangeAlertPane != NULL)
        g_pExchangeAlertPane->Close(1);
}


// UID:0002NF | by-memory/0x0061a1c0-0x0061a260.ExchangeAlertPaneVtableData.md | Completion:88 | Confidence:92
// ExchangeAlertPane vtable data at 0x0061a1c0-0x0061a260 is compiler-generated
// from the class declaration, destructor/thunks, OnButtonClick, and extension slots.
// The source reconstruction must not emit a literal vtable byte array.

// UID:0001XJ | by-type/by-vtable/ExchangeAlertPaneVtables.md | Completion:88 | Confidence:92
// ExchangeAlertPane vtable/type coverage is represented by the class declaration and
// exact vtable-data child; the compiler emits the binary tables.
[[No Children Attached]]

// UID:00004R | by-class/ExchangeDialog.md | Completion:88 | Confidence:90
// ExchangeDialog owns the exact exchange session method bodies emitted by its children.
// This marker intentionally avoids a full class layout because inherited DialogPane
// facets and final member order remain documentation-only, not source-quality C++.
class ExchangeDialog;

// UID:00049P | by-memory/0x004ac8a0-0x004ad0aa.ExchangeDialogConstructor.md | Completion:88 | Confidence:89
ExchangeDialog::ExchangeDialog(const unsigned char *packet)
    : DialogPane(L"", 9, true)
{
    m_exchangeSessionId = PacketReadUInt32BE(packet + 2);

    unsigned int partnerNameLength = PacketReadByte(packet + 6);
    char partnerNameBytes[256] = {0};
    memcpy(partnerNameBytes, packet + 7, partnerNameLength);
    partnerNameBytes[partnerNameLength] = 0;

    wchar_t partnerName[64] = {0};
    int partnerNameChars = MultiByteToWideChar(CP_ACP, 0, partnerNameBytes,
                                               partnerNameLength,
                                               partnerName, 64);
    if (partnerNameChars < 0) {
        partnerNameChars = 0;
    }
    if (partnerNameChars >= 64) {
        partnerNameChars = 63;
    }
    partnerName[partnerNameChars] = 0;

    unsigned int partnerDisplayValue =
        PacketReadUInt16BE(packet + 7 + partnerNameLength);

    AddControl(new EPFImageControlPane(MakeRect(0, 0, 451, 371),
                                       0x14c,
                                       L"DLGEXC1.EPF",
                                       L"DLGEXC1.PAL"));
    AddImageButton(1, Rect(84, 335, 147, 359), 14);
    AddImageButton(2, Rect(188, 335, 251, 359), 36);
    AddImageButton(3, Rect(292, 335, 355, 359), 22);

    wchar_t localName[64] = {0};
    wchar_t localStatusLine[64] = {0};
    wchar_t localLabel[128] = {0};
    g_activeUserStatusPane->CopyNameLineA(localName, 64);
    g_activeUserStatusPane->CopyNameLineB(localStatusLine, 64);
    swprintf_s(localLabel, 128, L"%s(%s)", localName, localStatusLine);
    AddControl(new StaticTextControlPane(Rect(30, 60, 197, 72), localLabel));

    AddControl(5, new ExchangeItemListPane(), Rect(30, 110, 222, 283));

    ExchangeMoneyEditControlPane *moneyEdit =
        new ExchangeMoneyEditControlPane(Rect(73, 295, 197, 307), L"0");
    AddControl(6, moneyEdit);

    AddControl(new StaticTextControlPane(Rect(241, 60, 408, 72), partnerName));
    AddControl(8, new ExchangeItemListPane(), Rect(241, 110, 432, 283));
    AddControl(9, new StaticTextControlPane(Rect(284, 295, 408, 307), L"0"));

    wchar_t amountText[32];
    swprintf_s(amountText, 32, L"%d",
               (int)g_activeUserStatusPane->m_statusClassByte);
    AddControl(new StaticTextControlPane(Rect(82, 83, 210, 95), amountText));

    swprintf_s(amountText, 32, L"%d", partnerDisplayValue);
    AddControl(new StaticTextControlPane(Rect(295, 83, 423, 95), amountText));

    LoadDialogBackground(L"DLGEXC1.EPF");

    if (m_activeControlId == 6 && moneyEdit->m_editActive) {
        wchar_t localAmountText[10];
        moneyEdit->ReadText(localAmountText, 10);

        unsigned int amount = 0;
        if (_wtol(localAmountText) > 0) {
            amount = (unsigned int)_wtol(localAmountText);
        }

        if (amount == 0) {
            moneyEdit->SetText(L"0");
        }

        SubmitExchangeAmount(amount);
    }

    SetDialogMode(2);
    SetActiveControl(1);
    SetCurrentControl(3);

    m_localOfferPending = 0;
    m_localReadyConfirmed = 0;
    m_peerReadyConfirmed = 0;
    m_localExchangeAmount = 0;
    m_amountDecreasePending = 0;

    Rect bounds(0, 0, 451, 371);
    SetFrameRect(&bounds, 0, 0, g_pDefaultParent);
    OnShow(g_pScreenPane, 0);
    Show();
}

// UID:00049Q | by-memory/0x004ad0b0-0x004ad1ca.ExchangeDialogOnButtonAction.md | Completion:87 | Confidence:89
void ExchangeDialog::OnButtonAction(int actionId, int /*unused*/)
{
    if (actionId == 1) {
        unsigned char packet[7];

        PacketBufferWriteUInt8(0x4A, packet);

        if (g_pUserPane->m_itemCommandBusy != 0) {
            PacketBufferWriteUInt8(4, packet + 1);
        } else {
            PacketBufferWriteUInt8(5, packet + 1);
        }

        PacketBufferWriteUInt32BE(m_exchangeSessionId, packet + 2);
        packet[6] = 0;

        g_packetSender->QueueAndSendPacket(packet, 6);
        m_localOfferPending = 1;
        return;
    }

    if (actionId == 2) {
        new AddItemDialog(m_exchangeSessionId, 1);
        return;
    }

    if (actionId == 3) {
        SendCancelPacket();
    }
}

// UID:00049R | by-memory/0x004ad1d0-0x004ad1f4.ExchangeDialogOnClose.md | Completion:86 | Confidence:90
bool ExchangeDialog::OnClose(int /*unused1*/, int /*unused2*/, int /*unused3*/)
{
    ControlPane *confirmButton = GetControl(1);
    confirmButton->SetEnabled(true);

    m_amountDecreasePending = 0;
    return true;
}

// UID:00049S | by-memory/0x004ad200-0x004ad2fd.ExchangeDialogUpdateButtonStates.md | Completion:88 | Confidence:90
void ExchangeDialog::UpdateButtonStates()
{
    ControlPane *confirmButton = GetControl(1);
    ControlPane *cancelButton = GetControl(3);
    ControlPane *addItemButton = GetControl(2);
    ControlPane *moneyEdit = GetControl(6);

    unsigned int state = 0;
    if (m_localOfferPending != 0) {
        state |= 4;
    }
    if (m_localReadyConfirmed != 0) {
        state |= 2;
    }
    if (m_peerReadyConfirmed != 0) {
        state |= 1;
    }

    switch (state) {
    case 0:
        if (m_amountDecreasePending == 0) {
            confirmButton->SetEnabled(true);
        }
        cancelButton->SetEnabled(true);
        addItemButton->SetEnabled(true);
        moneyEdit->SetEnabled(true);
        break;

    case 1:
        if (m_amountDecreasePending == 0) {
            confirmButton->SetEnabled(true);
        }
        cancelButton->SetEnabled(true);
        addItemButton->SetEnabled(false);
        moneyEdit->SetEnabled(false);
        break;

    case 2:
    case 4:
    case 5:
        if (m_amountDecreasePending == 0) {
            confirmButton->SetEnabled(false);
        }
        cancelButton->SetEnabled(true);
        addItemButton->SetEnabled(false);
        moneyEdit->SetEnabled(false);
        break;

    default:
        break;
    }
}

// UID:00014L | by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md | Completion:89 | Confidence:91
bool ExchangeDialog::DispatchExchangePacket(Event *event)
{
    const unsigned char *packet = event->packet;
    if (packet[0] != 0x42) {
        return false;
    }

    switch (packet[1]) {
    case 1: {
        const char inventorySlot =
            static_cast<char>(PacketReadByte(packet + 2));
        new AddItemWithCountDialog(m_exchangeSessionId, inventorySlot);
        return true;
    }

    case 2: {
        const bool remoteSide = PacketReadByte(packet + 2) != 0;
        const unsigned char rowKey = PacketReadByte(packet + 3);
        const unsigned short itemId = PacketReadUInt16BE(packet + 4);
        const unsigned char color = PacketReadByte(packet + 6);
        const unsigned int nameLength = PacketReadByte(packet + 7);

        char nameBytes[256];
        wchar_t nameText[256];
        memcpy(nameBytes, packet + 8, nameLength);
        nameBytes[nameLength] = 0;

        int converted = MultiByteToWideChar(CP_ACP, 0, nameBytes,
                                            nameLength, nameText, 256);
        nameText[static_cast<unsigned char>(converted)] = 0;

        ExchangeItemListPane *list =
            static_cast<ExchangeItemListPane *>(GetControl(remoteSide ? 8 : 5));

        int insertIndex = list->GetRowCount();
        for (int i = 0; i < insertIndex; ++i) {
            const ExchangeItemListRow *existing =
                static_cast<const ExchangeItemListRow *>(list->GetRow(i));
            if (existing->key == rowKey) {
                list->RemoveRows(i, 1);
                insertIndex = i;
                break;
            }
        }

        ExchangeItemListRow row;
        memset(&row, 0, sizeof(row));
        row.key = rowKey;
        row.itemId = itemId;
        row.color = color;
        wcscpy_s(row.name, 256, nameText);
        list->InsertRow(insertIndex, &row);
        return true;
    }

    case 3: {
        const bool remoteSide = PacketReadByte(packet + 2) != 0;
        const unsigned int amount = PacketReadUInt32BE(packet + 3);

        ControlPane *control;
        if (remoteSide) {
            control = GetControl(9);
        } else {
            if (amount == 0) {
                SetExchangeAmount(0);
            }
            control = GetControl(6);
        }

        wchar_t text[32];
        swprintf_s(text, 32, L"%u", amount);
        control->SetText(text);
        return true;
    }

    case 4: {
        char textBytes[256];
        wchar_t message[256];

        const unsigned int length = PacketReadByte(packet + 3);
        memcpy(textBytes, packet + 4, length);
        textBytes[length] = 0;

        int converted = MultiByteToWideChar(CP_ACP, 0, textBytes,
                                            length, message, 256);
        message[static_cast<unsigned char>(converted)] = 0;

        if (g_pExchangeAlertPane != 0) {
            g_pExchangeAlertPane->Close(1);
        }

        new ExchangeAlertPane(message, this, g_szDialogOk, 0);
        SlideClose();
        CloseDialogPane(this);

        if (g_pAddItemDialog != 0) {
            CloseDialogPane(g_pAddItemDialog);
        }
        return true;
    }

    case 5: {
        const bool remoteReady = PacketReadByte(packet + 2) != 0;

        if (remoteReady) {
            m_peerReadyConfirmed = 1;
            if (m_localReadyConfirmed != 1) {
                RefreshSelectedControlAfterStateUpdate();
                return true;
            }
        } else {
            const unsigned char wasPeerReady = m_peerReadyConfirmed;
            m_localOfferPending = 0;
            m_localReadyConfirmed = 1;
            if (wasPeerReady != 1) {
                RefreshSelectedControlAfterStateUpdate();
                return true;
            }
        }

        char textBytes[256];
        wchar_t message[256];

        const unsigned int length = PacketReadByte(packet + 3);
        memcpy(textBytes, packet + 4, length);
        textBytes[length] = 0;

        int converted = MultiByteToWideChar(CP_ACP, 0, textBytes,
                                            length, message, 256);
        message[static_cast<unsigned char>(converted)] = 0;

        if (g_pExchangeAlertPane != 0) {
            CloseActiveExchangeAlertPane();
        }

        new ExchangeAlertPane(message, this, g_szDialogOk, 0);
        SlideClose();
        CloseDialogPane(this);
        return true;
    }

    default:
        return true;
    }
}

// UID:00049T | by-memory/0x004ad7d0-0x004ad85f.ExchangeDialogOnKeyEvent.md | Completion:88 | Confidence:90
bool ExchangeDialog::OnKeyEvent(KeyEvent *event)
{
    const bool handled = DialogPane::OnKeyEvent(event);

    if (event->type == 10 &&
        event->wideChar >= L'0' &&
        event->wideChar <= L'9') {
        wchar_t amountText[10];
        ExchangeMoneyEditControlPane *moneyEdit =
            static_cast<ExchangeMoneyEditControlPane *>(GetControl(6));
        moneyEdit->ReadText(amountText, 10);

        const long parsedAmount = _wtol(amountText);
        const unsigned int amount =
            parsedAmount > 0 ? static_cast<unsigned int>(parsedAmount) : 0;
        SubmitExchangeAmount(amount);
    }

    return handled;
}

// UID:00049U | by-memory/0x004ad900-0x004ad95f.ExchangeDialogSendCancelPacket.md | Completion:88 | Confidence:90
void ExchangeDialog::SendCancelPacket()
{
    unsigned char packet[7];

    PacketBufferWriteUInt8(0x4A, packet);
    PacketBufferWriteUInt8(4, packet + 1);
    PacketBufferWriteUInt32BE(m_exchangeSessionId, packet + 2);
    packet[6] = 0;

    g_packetSender->QueueAndSendPacket(packet, 6);
}

// UID:00049V | by-memory/0x004ad960-0x004ada16.ExchangeDialogSubmitExchangeAmount.md | Completion:88 | Confidence:90
void ExchangeDialog::SubmitExchangeAmount(unsigned int amount)
{
    unsigned char packet[11];

    SetExchangeAmount(amount);

    PacketBufferWriteUInt8(0x4A, packet);

    if (g_pUserPane->m_itemCommandBusy != 0) {
        PacketBufferWriteUInt8(4, packet + 1);
        PacketBufferWriteUInt32BE(m_exchangeSessionId, packet + 2);
        packet[6] = 0;

        g_packetSender->QueueAndSendPacket(packet, 6);
        return;
    }

    PacketBufferWriteUInt8(3, packet + 1);
    PacketBufferWriteUInt32BE(m_exchangeSessionId, packet + 2);
    PacketBufferWriteUInt32BE(amount, packet + 6);
    packet[10] = 0;

    g_packetSender->QueueAndSendPacket(packet, 10);
}

// UID:00049W | by-memory/0x004ada20-0x004ada84.ExchangeDialogSetExchangeAmount.md | Completion:88 | Confidence:90
void ExchangeDialog::SetExchangeAmount(unsigned int amount)
{
    if (m_localExchangeAmount > amount) {
        m_amountDecreasePending = 1;
        GetControl(1)->SetEnabled(false);
        m_timerHandler.CancelTimer(0x1000);
        m_timerHandler.ScheduleTimer(0x1000, 10000, 0, 0);
    }

    m_localExchangeAmount = amount;
}

// UID:00014M | by-memory/0x004ada90-0x004adb02.ExchangeDialogAddItemWithCountHelper.md | Completion:86 | Confidence:90
// Emitted code for this retained no-route add-count helper is covered by [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md case 1.

// UID:00049X | by-memory/0x004adb10-0x004adc96.ExchangeDialogRawItemUpdate.md | Completion:88 | Confidence:91
// Emitted code for this retained raw item-update duplicate is covered by [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md case 2.

// UID:00014N | by-memory/0x004adca0-0x004add34.ExchangeDialogRawMoneyUpdate.md | Completion:88 | Confidence:91
// Emitted code for this retained raw duplicate is covered by [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md case 3.

// UID:00014O | by-memory/0x004add40-0x004ade5e.ExchangeDialogCancelAlertHelper.md | Completion:86 | Confidence:89
// Emitted code for this retained no-route cancel-alert helper is covered by [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md case 4.

// UID:00014P | by-memory/0x004ade60-0x004adfab.ExchangeDialogReadyAlertHelper.md | Completion:86 | Confidence:89
// Emitted code for this retained no-route ready-alert helper is covered by [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md case 5.

// UID:00049Y | by-memory/0x004adfb0-0x004ae053.ExchangeDialogOnControlFocusChange.md | Completion:88 | Confidence:90
void ExchangeDialog::OnControlFocusChange(int controlId)
{
    TextEditControlPane *moneyEdit =
        static_cast<TextEditControlPane *>(GetControl(6));

    if (m_activeControlId == 6 && controlId != 6 && moneyEdit->m_editActive) {
        wchar_t amountText[16];
        moneyEdit->ReadText(amountText, 10);

        unsigned int amount = 0;
        if (_wtol(amountText) > 0) {
            amount = static_cast<unsigned int>(_wtol(amountText));
        }

        if (amount == 0) {
            moneyEdit->SetText(L"0");
        }

        SubmitExchangeAmount(amount);
    }

    SetHoverControl(controlId);
}

// UID:0003NE | by-memory/0x00619d28-0x00619dc4.ExchangeDialogVtableData.md | Completion:88 | Confidence:92
// ExchangeDialog vtable data at 0x00619d28-0x00619dc4 is compiler-generated
// from the ExchangeDialog class and emitted method children. Do not reconstruct it
// as a literal source array.


// UID:00004S | by-class/ExchangeItemListPane.md | Completion:89 | Confidence:90
struct ExchangeItemListRow
{
    unsigned char key;
    unsigned char reserved1;
    unsigned short itemId;
    unsigned char color;
    unsigned char reserved5;
    wchar_t name[256];
};

class ExchangeItemListPane;

// UID:00014Q | by-memory/0x004ae060-0x004ae0a4.ExchangeItemListPaneRawConstructor.md | Completion:88 | Confidence:90
ExchangeItemListPane::ExchangeItemListPane()
    : ListPane(sizeof(ExchangeItemListRow), 8, 0x9c, 0x18, 0, 1, 1)
{
}

// UID:00014R | by-memory/0x004ae0b0-0x004ae167.ExchangeItemListPaneRawUpsertHelper.md | Completion:86 | Confidence:89
// Emitted code for this retained raw no-route upsert helper is covered by [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md case 2.

// UID:00014S | by-memory/0x004ae170-0x004ae1ac.ExchangeItemListPaneRawFindHelper.md | Completion:88 | Confidence:91
// Emitted code for this retained raw no-route helper is covered by [UID:00014L][0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher](by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md) by-memory/0x004ad320-0x004ad7b3.ExchangeDialogPacketDispatcher.md case 2.

// UID:00049Z | by-memory/0x004ae1b0-0x004ae1b3.ExchangeItemListPaneNullVirtual.md | Completion:88 | Confidence:91
void ExchangeItemListPane::OnItemSelected(int, int)
{
}

// UID:0004A0 | by-memory/0x004ae1c0-0x004ae4b6.ExchangeItemListPaneDrawItemEntry.md | Completion:88 | Confidence:90
void ExchangeItemListPane::DrawItemEntry(int, ExchangeItemListRow *row, RectBounds *rowBounds)
{
    EPFTileContext itemContext;
    RectBounds imageBounds;
    wchar_t text[256];

    GetItemGlyphBounds(static_cast<short>(row->itemId), &itemContext.bounds);

    const int itemWidth = itemContext.bounds.right - itemContext.bounds.left;
    const int itemHeight = itemContext.bounds.bottom - itemContext.bounds.top;
    const int rowCenterY = (rowBounds->top + rowBounds->bottom) / 2;

    if (g_useEpfAssets == 1) {
        const int scaledWidth = itemWidth / 2;
        const int scaledHeight = itemHeight / 2;

        imageBounds.left = 25 - scaledWidth / 2;
        imageBounds.top = rowCenterY - scaledHeight / 2;
        imageBounds.right = imageBounds.left + scaledWidth;
        imageBounds.bottom = imageBounds.top + scaledHeight;

        IntersectRects(&imageBounds, rowBounds, &imageBounds);
        g_pItemObjImageLib->DrawItemImageScaled(this, &imageBounds, static_cast<short>(row->itemId), row->color);
    } else {
        imageBounds.left = 25 - itemWidth / 2;
        imageBounds.top = rowCenterY - itemHeight / 2;
        imageBounds.right = imageBounds.left + itemWidth;
        imageBounds.bottom = imageBounds.top + itemHeight;

        g_pItemObjImageLib->DrawItemImage(this, &imageBounds, static_cast<short>(row->itemId), row->color, nullptr, 0.0f);
    }

    m_textDrawMode = 1;
    SetTextColor(37);
    SetTextBackColor(0);

    wcscpy_s(text, 0x100, row->name);
    MoveTo(50, rowCenterY + 6);
    DrawWideText(text, static_cast<int>(wcslen(text)));
}

// UID:0003NF | by-memory/0x00619dc4-0x00619e88.ExchangeItemListPaneVtableData.md | Completion:88 | Confidence:92
// ExchangeItemListPane vtable data at 0x00619dc4-0x00619e88 is compiler-generated
// from the private list-pane declaration, constructor, no-op selection callback,
// and DrawItemEntry override. Do not reconstruct it as a literal source array.

// UID:0000QV | by-global/g_pExchangeAlertPane.md | Completion:88 | Confidence:92
static ExchangeAlertPane *g_pExchangeAlertPane = NULL;

// UID:0002VZ | by-memory/0x0069b330-0x0069b334.g_pExchangeAlertPane.md | Completion:89 | Confidence:92
// Exact storage at 0x0069b330 for g_pExchangeAlertPane is emitted once by
// [UID:0000QV][g_pExchangeAlertPane](by-global/g_pExchangeAlertPane.md). Current MCP bytes are 00 00 00 00, not an explicit 0xffffffff
// initializer.

// UID:0003BK | by-memory\0x0061a260-0x0061a304.ExchangeMoneyEditControlPaneVtableData.md | Completion:90 | Confidence:95 | Empty Emitter Marker

// UID:0003NK | by-memory\0x0061a1bc-0x0061a1c0.ExchangeAlertPaneRttiLocatorPointer.md | Completion:85 | Confidence:90 | Empty Emitter Marker

// UID:0003NG | by-memory\0x0061a304-0x0061a344.ExchangeDialogResourceStrings.md | Completion:86 | Confidence:91 | Empty Emitter Marker
