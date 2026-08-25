// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000I9
// Source by-file doc: by-file/ClanBank.md
// UID:000025 | by-class/ClanBankItemListPane.md | Completion:87 | Confidence:90
struct Rect;

struct ClanBankItemEntry
{
    unsigned char slotIndex;
    unsigned char reserved;
    unsigned short itemId;
    wchar_t displayName[256];
    unsigned int count;
    unsigned int flags;
};

class ClanBankItemListPane : public ListPane
{
public:
    explicit ClanBankItemListPane(const unsigned char *packet);
    virtual ~ClanBankItemListPane();

protected:
    virtual void DrawListEntry(int rowIndex, const ClanBankItemEntry *entry, const Rect *bounds);

private:
    void ClearSlotCache();
    void RebuildVisibleRows();
    ClanBankItemEntry m_entries[256];
    int m_visibleRowCount;
};

[[No Children Attached]]

// UID:000026 | by-class/ClanBankPane.md | Completion:87 | Confidence:90
#include "../ui/dialogs/ItemDialogs.h"

class ClanBankItemListPane;

class ClanBankPane : public DialogPane
{
public:
    ClanBankPane(const unsigned char *packet, int action);
    virtual ~ClanBankPane();

protected:
    virtual void OnDialogAction(int controlId, int action, int value);

private:
    void SendClosePacket();
    unsigned char m_bankMode;     // +0x26c, 0 for item bank action 10, 1 for gold bank action 16.
};

extern ClanBankPane *g_pClanBankPane;

[[No Children Attached]]

// UID:000029 | by-class/ClanDepItemDialog.md | Completion:87 | Confidence:90
class ClanDepItemDialog : public ClanItemDialog
{
public:
    explicit ClanDepItemDialog(const unsigned char *packet);
    virtual ~ClanDepItemDialog();

protected:
    virtual void OnButtonClick(int controlId, int action, int value);
    virtual void SendDepositItemPacket(unsigned char slotIndex, unsigned short amount);
};

[[No Children Attached]]

// UID:00002F | by-class/ClanItemDialog.md | Completion:86 | Confidence:90
class ClanItemDialog : public DialogPane
{
public:
    ClanItemDialog();
    virtual ~ClanItemDialog();

protected:
    virtual void UpdateConfirmButtonState();
};

// UID:00021X | by-memory/0x0048a0c0-0x0048a0fb.ClanItemDialogRawConstructor.md | Completion:86 | Confidence:90
// UID00021X is the source-shaped ClanItemDialog raw constructor evidence: current MCP still reports no function object, no decompile, no inbound xrefs, no VA/RVA pointer hits, and no IDA ClanItemDialog type declaration for 0x0048a0c0. The ClanItemDialog class shell may declare ClanItemDialog(), but this range should not emit a standalone constructor body until the project-level raw-constructor/class-declaration policy has a proven source route for no-xref raw constructor islands.

// UID:0002OC | by-memory/0x0048a100-0x0048a11f.ClanItemDialogVtableResetDestructorTail.md | Completion:86 | Confidence:92
// UID0002OC is the ClanItemDialog destructor-tail/vtable-reset body reached only through constructor EH cleanup. Current MCP confirms the exact 0x1f-byte body restores the three ClanItemDialog vtables and tail-jumps to shared DialogPane cleanup at 0x0049d9f0; the local Boost exception label on that target is type/name pollution. Do not emit handwritten C++ for this range: source-level virtual destructors on ClanItemDialog and its derived classes should regenerate the vtable resets, EH cleanup route, and DialogPane base teardown.

// UID:0002OB | by-memory/0x0048a120-0x0048a1be.ClanItemDialogConfirmValidation.md | Completion:87 | Confidence:91
void ClanItemDialog::UpdateConfirmButtonState()
{
    ControlPane *confirmButton = m_controlManager->FindControl(1)->control;
    ControlPane *itemListControl = m_controlManager->FindControl(5)->control;
    TextEditControlPane *quantityEdit =
        static_cast<TextEditControlPane *>(m_controlManager->FindControl(6)->control);

    wchar_t quantityText[128];
    ListPane *itemList = itemListControl->m_embeddedListPane;
    const int selectedIndex = itemList->m_selectedIndex;

    quantityEdit->ReadText(quantityText, 0x7f);

    if (selectedIndex != -1 && quantityText[0] != L'\0')
        confirmButton->Enable();
    else
        confirmButton->Disable();
}

// UID:00002G | by-class/ClanItemListPane.md | Completion:87 | Confidence:90
struct Rect;

struct ClanItemListEntry
{
    unsigned char slotIndex;
    unsigned char reserved;
    unsigned short itemId;
    wchar_t displayName[256];
};

class ClanItemListPane : public ListPane
{
public:
    explicit ClanItemListPane(const unsigned char *packet);
    virtual ~ClanItemListPane();

protected:
    virtual void DrawListItem(int rowIndex, const ClanItemListEntry *entry, const Rect *bounds);

private:
    ClanItemListEntry m_entries[256];
};

// UID:00010Q | by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md | Completion:88 | Confidence:90
ClanItemListPane::ClanItemListPane(const unsigned char *packet)
    : ListPane(516, 8, 205, 24, 0, true, true)
{
    memset(m_entries, 0, sizeof(m_entries));

    const unsigned int count = ReadPacketByte(packet);
    const unsigned char *cursor = packet + 1;

    for (unsigned int i = 0; i < count; ++i)
    {
        const unsigned char slotIndex = ReadPacketByte(cursor++);
        ClanItemListEntry &entry = m_entries[slotIndex];

        entry.slotIndex = slotIndex;
        entry.reserved = 0;
        entry.itemId = ReadPacketUInt16BE(cursor);
        cursor += 2;

        const unsigned int nameLength = ReadPacketByte(cursor++);
        char nameBytes[256];
        memmove(nameBytes, cursor, nameLength);
        nameBytes[nameLength] = '\0';
        cursor += nameLength;

        const int wideLength = MultiByteToWideChar(
            CP_ACP,
            0,
            nameBytes,
            nameLength,
            entry.displayName,
            256);

        if (static_cast<unsigned int>(wideLength) >= 256)
            __report_rangecheckfailure();

        entry.displayName[wideLength] = L'\0';
    }

    for (unsigned int slotIndex = 1; slotIndex < 256; ++slotIndex)
    {
        const ClanItemListEntry &entry = m_entries[slotIndex];
        if (entry.displayName[0] != L'\0')
            AddRow(&entry);
    }
}

// The raw selected-entry byte helper at 0x0048b090-0x0048b09e is source-shaped
// but has no IDA function, xref, VA/RVA pointer, or direct branch route. Its
// behavior is represented by callers using ListPane selection state; do not emit
// a standalone callable body for that raw island in this pass.

void ClanItemListPane::DrawListItem(int rowIndex, const ClanItemListEntry *entry, const Rect *bounds)
{
    int scratch[4];
    BeginListRowDraw(scratch);

    if (IsRowSelected(rowIndex))
    {
        SetTextColor(37);
        DrawSelectedRowBackground(bounds);
        SetTextColor(128);
    }
    else
    {
        SetTextColor(37);
    }

    Rect imageBounds;
    GetItemImageBounds(entry->itemId, &imageBounds);
    m_drawImage = true;
    SetTextBackgroundMode(0);

    wchar_t label[256];
    wcscpy_s(label, 256, entry->displayName);
    FitTextWithEllipsis(label, 256, L"...", bounds->right - 50);

    const int textY = ((bounds->top + bounds->bottom) / 2) + 6;
    MoveTextCursor(50, textY);
    DrawWideText(label, wcslen(label));
}

// UID:0002XJ | by-global/g_pClanBankPane.md | Completion:88 | Confidence:91
ClanBankPane *g_pClanBankPane;

// UID:00010O | by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md | Completion:88 | Confidence:90
ClanDepItemDialog::ClanDepItemDialog(const unsigned char *packet)
    : ClanItemDialog()
{
    char textBytes[256];
    wchar_t titleText[256];
    wchar_t detailText[256];

    const unsigned int titleLength = packet[3];
    memmove(textBytes, packet + 4, titleLength);
    textBytes[titleLength] = '\0';

    int wideLength = MultiByteToWideChar(
        CP_ACP,
        0,
        textBytes,
        titleLength,
        titleText,
        256);

    if (static_cast<unsigned int>(wideLength) >= 256)
        __report_rangecheckfailure();

    titleText[wideLength] = L'\0';

    const unsigned char *detailPacket = packet + 4 + titleLength;
    const unsigned int detailLength = detailPacket[0];
    memmove(textBytes, detailPacket + 1, detailLength);
    textBytes[detailLength] = '\0';

    wideLength = MultiByteToWideChar(
        CP_ACP,
        0,
        textBytes,
        detailLength,
        detailText,
        256);

    if (static_cast<unsigned int>(wideLength) >= 256)
        __report_rangecheckfailure();

    detailText[wideLength] = L'\0';

    AddControl(new EPFImageControlPane(L"DLGCLAN3.EPF", Rect(0, 0, 221, 288), 0, true));
    AddControl(new ImageButtonControlPane(14, Rect(36, 230, 108, 246)));
    AddControl(new ImageButtonControlPane(22, Rect(113, 230, 185, 246)));
    AddControl(new StaticTextControlPane(titleText, true, 128, Rect(27, 50, 195, 70)));
    AddControl(new StaticTextControlPane(detailText, true, 128, Rect(27, 174, 195, 194)));

    MyItemListPane *itemList = new MyItemListPane();
    AddControl(new ScrollControlPane(Rect(27, 72, 195, 168), itemList, 0, 0, 0));
    AddControl(new TextEditControlPane(L"", true, 128, 0, Rect(27, 196, 195, 209), 0, 0, 0, 0, 1.0f, 0));

    SetDefaultControl(5);
    RegisterButtonAction(1);
    RegisterButtonAction(2);
    SetDialogResourceName(L"DLGCLAN3.EPF");
    AttachToDesktop(Rect(212, 12, 433, 300), g_pBackPane);
    OpenOnDisplay(g_pDisplayContext);
    SlideOpen(false);
}

// The vtable-reset/destructor-tail helper at 0x0048a690-0x0048a6af is generated
// cleanup shape and has no direct xrefs. It is covered by the class destructor
// declaration and should not be emitted as a handwritten source method.

void ClanDepItemDialog::OnButtonClick(int controlId, int action, int)
{
    if (action == 1)
    {
        MyItemListPane *itemList =
            static_cast<MyItemListPane *>(FindControl(5)->control->m_embeddedListPane);
        TextEditControlPane *amountEdit =
            static_cast<TextEditControlPane *>(FindControl(6)->control);

        wchar_t amountText[128];
        amountEdit->ReadText(amountText, 127);

        const int selectedIndex = itemList->GetSelectedIndex();
        if (selectedIndex >= 0 && selectedIndex < itemList->GetRowCount())
        {
            const unsigned char slotIndex = itemList->GetSelectedSlotIndex();
            const unsigned short amount =
                static_cast<unsigned short>(_wtol(amountText));

            SendDepositItemPacket(slotIndex, amount);
        }
    }

    if (action == 1 || action == 2)
    {
        SlideClose(controlId);
        CloseDialog();
    }
}

void ClanDepItemDialog::SendDepositItemPacket(unsigned char slotIndex, unsigned short amount)
{
    unsigned char packet[7];
    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(5, packet + 1);
    PacketBufferWriteUInt8(1, packet + 2);
    PacketBufferWriteUInt8(slotIndex, packet + 3);
    PacketBufferWriteUInt16BE(amount, packet + 4);
    packet[6] = 0;

    g_packetSender->QueueAndSendPacket(packet, 6);
}

// UID:00010P | by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md | Completion:88 | Confidence:91
ClanWidItemDialog::ClanWidItemDialog(const unsigned char *packet)
    : ClanItemDialog()
{
    char textBytes[256];
    wchar_t titleText[256];
    wchar_t detailText[256];

    const unsigned int titleLength = packet[3];
    memmove(textBytes, packet + 4, titleLength);
    textBytes[titleLength] = '\0';

    int wideLength = MultiByteToWideChar(
        CP_ACP,
        0,
        textBytes,
        titleLength,
        titleText,
        256);

    if (static_cast<unsigned int>(wideLength) >= 256)
        __report_rangecheckfailure();

    titleText[wideLength] = L'\0';

    const unsigned char *detailPacket = packet + 4 + titleLength;
    const unsigned int detailLength = detailPacket[0];
    memmove(textBytes, detailPacket + 1, detailLength);
    textBytes[detailLength] = '\0';

    wideLength = MultiByteToWideChar(
        CP_ACP,
        0,
        textBytes,
        detailLength,
        detailText,
        256);

    if (static_cast<unsigned int>(wideLength) >= 256)
        __report_rangecheckfailure();

    detailText[wideLength] = L'\0';

    const unsigned char *itemListPacket = detailPacket + 1 + detailLength;

    AddControl(new EPFImageControlPane(L"DLGCLAN3.EPF", Rect(0, 0, 221, 288), 0, true));
    AddControl(new ImageButtonControlPane(14, Rect(36, 230, 108, 246)));
    AddControl(new ImageButtonControlPane(22, Rect(113, 230, 185, 246)));
    AddControl(new StaticTextControlPane(titleText, true, 128, Rect(27, 50, 195, 70)));
    AddControl(new StaticTextControlPane(detailText, true, 128, Rect(27, 174, 195, 194)));

    ClanItemListPane *itemListPane = new ClanItemListPane(itemListPacket);
    AddControl(new ScrollableControlPane(Rect(27, 72, 195, 168), itemListPane, 0, 0, 0));
    AddControl(new TextEditControlPane(L"", true, 128, Rect(27, 196, 195, 209)));

    SelectControl(5);
    SetFocusedControl(1);
    SetCancelControl(2);
    SetBackgroundResource(L"DLGCLAN3.EPF", 0);
    SetDisplayRect(Rect(212, 12, 433, 300));
    ShowDialog(false);
    SlideOpenHorizontal(0);
}

void ClanWidItemDialog::OnDialogAction(int closeContext, int controlId)
{
    if (controlId == 1) {
        ControlPane *itemListControl = GetChildControl(5);
        TextEditControlPane *quantityEdit =
            static_cast<TextEditControlPane *>(GetChildControl(6));

        wchar_t quantityText[128];
        ListPane *itemList = itemListControl->m_embeddedListPane;
        const int selectedIndex = itemList->m_selectedIndex;

        quantityEdit->ReadText(quantityText, 0x7f);

        if (selectedIndex >= 0 && selectedIndex < itemList->GetEntryCount()) {
            const ClanItemListEntry *entry =
                static_cast<const ClanItemListEntry *>(itemList->GetSelectedEntry());

            SendWithdrawRequestPacket(
                entry->slotIndex,
                static_cast<unsigned short>(_wtol(quantityText)));
        }
    } else if (controlId != 2) {
        return;
    }

    SlideCloseHorizontal(closeContext);
    CloseDialog();
}

void ClanWidItemDialog::SendWithdrawRequestPacket(
    unsigned char slotIndex,
    unsigned short quantity)
{
    unsigned char packet[7];

    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(0x0c, packet + 1);
    PacketBufferWriteUInt8(1, packet + 2);
    PacketBufferWriteUInt8(slotIndex, packet + 3);
    PacketBufferWriteUInt16BE(quantity, packet + 4);
    packet[6] = 0;

    QueueAndSendPacket(g_packetSender, packet, 6);
}

// UID:00010R | by-memory/0x0048b1c0-0x0048b7dc.ClanBankPane.md | Completion:88 | Confidence:90
ClanBankPane::ClanBankPane(const unsigned char *packet, int action)
    : DialogPane(L"", -1, true)
{
    g_pClanBankPane = this;

    if (action == 10)
        m_bankMode = 0;
    else if (action == 16)
        m_bankMode = 1;
    else
        return;

    AddControl(new EPFImageControlPane(L"CLANBAN1.EPF", Rect(0, 0, 448, 475), 0, true));
    AddControl(new ImageButtonControlPane(30, Rect(190, 438, 253, 462)));

    if (m_bankMode != 0)
        AddControl(new ImageButtonControlPane(23, Rect(340, 397, 403, 421)));
    else
        AddControl(new ImageButtonControlPane(53, Rect(340, 397, 403, 421)));

    AddControl(new TextEditControlPane(L"1", true, 143, 134, Rect(300, 402, 324, 414), 0, 0, 0, 0, 1.0f, 0));

    ClanBankItemListPane *itemList = new ClanBankItemListPane(packet + 1);
    AddControl(new ScrollControlPane(Rect(15, 95, 415, 375), itemList, 0, 0, 0));

    wchar_t countText[128];
    if (m_bankMode != 0)
        swprintf_s(countText, 128, L"     %d", itemList->GetVisibleRowCount());
    else
        swprintf_s(countText, 128, L"%d / %d", itemList->GetVisibleRowCount(), 255);

    AddControl(new StaticTextControlPane(countText, true, 143, Rect(328, 62, 388, 74)));

    SetDefaultControl(4);
    RegisterButtonAction(1);
    SetDialogResourceName(L"CLANBAN1.EPF");
    AttachToDesktop(Rect(50, 50, 498, 525), g_pBackPane);
    OpenOnDisplay(g_pDisplayContext);
}

// The vtable-reset/destructor-tail helper at 0x0048b600-0x0048b629 is generated
// cleanup shape: it restores ClanBankPane vtables, clears g_pClanBankPane, and
// tail-calls base teardown. It is not emitted as a handwritten source method.

void ClanBankPane::SendClosePacket()
{
    unsigned char packet[3];
    PacketBufferWriteUInt8(0x36, packet + 0);
    PacketBufferWriteUInt8(0x0b, packet + 1);
    packet[2] = 0;
    g_packetSender->QueueAndSendPacket(packet, 2);
}

void ClanBankPane::OnDialogAction(int controlId, int action, int)
{
    if (action == 1)
    {
        SendClosePacket();
        SlideClose(controlId);
        CloseDialog();
        return;
    }

    if (action == 2)
    {
        ClanBankItemListPane *itemList =
            static_cast<ClanBankItemListPane *>(FindControl(4)->control->m_embeddedListPane);
        TextEditControlPane *quantityEdit =
            static_cast<TextEditControlPane *>(FindControl(3)->control);

        wchar_t quantityText[128];
        quantityEdit->ReadText(quantityText, 127);

        const int selectedIndex = itemList->GetSelectedIndex();
        if (selectedIndex >= 0 && selectedIndex < itemList->GetRowCount())
        {
            const unsigned short selectedSlot =
                static_cast<unsigned short>(itemList->GetSelectedSlotIndex());
            unsigned int quantity = static_cast<unsigned int>(_wtol(quantityText));
            if (quantity == 0)
                quantity = 1;

            unsigned char packet[10];
            PacketBufferWriteUInt8(0x36, packet + 0);
            PacketBufferWriteUInt8(
                static_cast<unsigned char>(13 - (m_bankMode != 0)), packet + 1);
            PacketBufferWriteUInt16BE(selectedSlot, packet + 2);
            PacketBufferWriteUInt8(static_cast<unsigned char>(quantity > 1), packet + 4);
            PacketBufferWriteUInt32BE(quantity, packet + 5);
            packet[9] = 0;

            g_packetSender->QueueAndSendPacket(packet, 9);
        }

        SendClosePacket();
        SlideClose(controlId);
        CloseDialog();
    }
}

// UID:00021Y | by-memory/0x0048b7e0-0x0048b8bc.ClanBankPaneRawPacketHelpers.md | Completion:88 | Confidence:90
// UID00021Y is the retained ClanBankPane raw opcode-0x36 helper island. It emits no callable helper body because current MCP and PE evidence show no function objects, no inbound xrefs, no incoming data-flow, and no pointer or rel32 route, while ClanBankPane::OnDialogAction already emits the equivalent submit/close packets inline.

// UID:00010S | by-memory/0x0048b8c0-0x0048c251.ClanBankItemListPane.md | Completion:88 | Confidence:90
ClanBankItemListPane::ClanBankItemListPane(const unsigned char *packet)
    : ListPane(524, 8, 400, 40, 0, true, true),
      m_visibleRowCount(0)
{
    ClearSlotCache();

    const unsigned char opcode = ReadPacketByte(packet);
    if (opcode == 10)
    {
        const unsigned int count = ReadPacketByte(packet + 1);
        const unsigned char *cursor = packet + 2;

        for (unsigned int row = 1; row <= count; ++row)
        {
            const unsigned char slotIndex = ReadPacketByte(cursor++);
            ClanBankItemEntry &entry = m_entries[row];
            entry.slotIndex = slotIndex;
            entry.itemId = ReadPacketUInt16BE(cursor);
            cursor += 2;

            const unsigned int nameLength = ReadPacketByte(cursor++);
            char nameBytes[256];
            memmove(nameBytes, cursor, nameLength);
            nameBytes[nameLength] = '\0';
            cursor += nameLength;

            const int wideLength = MultiByteToWideChar(
                CP_ACP,
                0,
                nameBytes,
                nameLength,
                entry.displayName,
                256);

            if (static_cast<unsigned int>(wideLength) >= 256)
                __report_rangecheckfailure();

            entry.displayName[wideLength] = L'\0';

            const unsigned int detailLength = ReadPacketByte(cursor++);
            cursor += detailLength;
            entry.count = ReadPacketUInt32BE(cursor);
            cursor += 4;

            cursor += 3;
            if (ReadPacketByte(cursor++) != 0)
            {
                const unsigned int extraLength = ReadPacketByte(cursor++);
                cursor += extraLength;
            }

            entry.flags = ReadPacketByte(cursor++);
        }

        std::sort(
            m_entries + 1,
            m_entries + count + 1,
            [](const ClanBankItemEntry &left, const ClanBankItemEntry &right) {
                return right.displayName[0] != L'\0' &&
                       wcscmp(left.displayName, right.displayName) > 0;
            });
    }
    else if (opcode == 15)
    {
        const unsigned char slotIndex = ReadPacketByte(packet + 1);
        m_entries[slotIndex] = ClanBankItemEntry();
    }
    else if (opcode == 16)
    {
        const unsigned int count = ReadPacketUInt16BE(packet + 1);
        const unsigned char *cursor = packet + 3;

        for (unsigned int i = 0; i < count; ++i)
        {
            const unsigned char slotIndex = ReadPacketByte(cursor++);
            ClanBankItemEntry &entry = m_entries[slotIndex];
            entry.slotIndex = slotIndex;
            entry.itemId = ReadPacketUInt16BE(cursor);
            cursor += 2;

            cursor += 1;
            entry.count = ReadPacketUInt32BE(cursor);
            cursor += 4;

            cursor += 1;
            const unsigned int nameLength = ReadPacketByte(cursor++);
            char nameBytes[256];
            memmove(nameBytes, cursor, nameLength);
            nameBytes[nameLength] = '\0';
            cursor += nameLength;

            const int wideLength = MultiByteToWideChar(
                CP_ACP,
                0,
                nameBytes,
                nameLength,
                entry.displayName,
                256);

            if (static_cast<unsigned int>(wideLength) >= 256)
                __report_rangecheckfailure();

            entry.displayName[wideLength] = L'\0';

            const unsigned int detailLength = ReadPacketByte(cursor++);
            cursor += detailLength;
            entry.flags = 0;
        }
    }

    RebuildVisibleRows();
}

void ClanBankItemListPane::ClearSlotCache()
{
    memset(m_entries, 0, sizeof(m_entries));
    m_visibleRowCount = 0;
}

void ClanBankItemListPane::RebuildVisibleRows()
{
    m_visibleRowCount = 0;

    for (unsigned int slotIndex = 1; slotIndex < 256; ++slotIndex)
    {
        ClanBankItemEntry &entry = m_entries[slotIndex];
        if (entry.displayName[0] != L'\0')
        {
            AddRow(&entry);
            ++m_visibleRowCount;
        }
    }
}

void ClanBankItemListPane::DrawListEntry(int rowIndex, const ClanBankItemEntry *entry, const Rect *bounds)
{
    int scratch[4];
    BeginListRowDraw(scratch);

    if (IsRowSelected(rowIndex))
    {
        Rect selectedBounds(bounds->left, bounds->top, bounds->right - 13, bounds->bottom);
        SetTextColor(128);
        DrawSelectedRowBackground(&selectedBounds);
    }

    SetFontColor(143);

    Rect imageBounds;
    GetItemImageBounds(entry->itemId, &imageBounds);
    const int imageLeft = 30 - ((imageBounds.right - imageBounds.left) / 2);
    const int imageTop = ((bounds->top + bounds->bottom) / 2) -
                         ((imageBounds.bottom - imageBounds.top) / 2);

    DrawItemImage(
        g_pItemObjImageLib,
        Rect(imageLeft, imageTop, imageLeft + imageBounds.Width(), imageTop + imageBounds.Height()),
        entry->itemId,
        0,
        0,
        0.0f);

    m_drawImage = true;
    SetTextBackgroundMode(0);

    wchar_t label[256];
    if (entry->count <= 1)
        wcscpy_s(label, 256, entry->displayName);
    else
        swprintf_s(label, 256, L"%s (%d)", entry->displayName, entry->count);

    FitTextWithEllipsis(label, 256, L"...", bounds->right - 70);
    MoveTextCursor(70, ((bounds->top + bounds->bottom) / 2) + 6);
    DrawWideText(label, wcslen(label));
}

// UID:0002MO | by-memory/0x00615fd8-0x006163dc.ClanBankVtableData.md | Completion:87 | Confidence:91
// UID0002MO ClanBank vtable data is compiler-emitted layout evidence for the ClanItemDialog, ClanDepItemDialog, ClanWidItemDialog, ClanItemListPane, ClanBankPane, and ClanBankItemListPane class family. Do not hand-write raw RTTI or vtable dword arrays; final class declarations should regenerate equivalent tables.

// UID:0003BB | by-memory\0x00616468-0x00616484.ClanItemDialogResourceString.md | Completion:85 | Confidence:91 | Empty Emitter Marker

// UID:0003BA | by-memory\0x00616484-0x006164f0.ClanBankResourceStrings.md | Completion:85 | Confidence:91 | Empty Emitter Marker

// UID:0003HF | by-type\by-vtable\ClanBankVtables.md | Completion:87 | Confidence:92 | Empty Emitter Marker
