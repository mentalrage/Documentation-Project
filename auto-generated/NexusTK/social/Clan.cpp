// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000I8
// Source by-file doc: by-file/Clan.md
// UID:000023 | by-class/ClanAppearNameInputDialog.md | Completion:93 | Confidence:93
// UID:0002NZ | by-memory/0x004893a0-0x004893d5.ClanAppearNameInputDialogRawConstructor.md | Completion:92 | Confidence:93
ClanAppearNameInputDialog::ClanAppearNameInputDialog(const unsigned char *packet)
    : ClanNameInputDialog(packet)
{
}

// UID:0002O0 | by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md | Completion:94 | Confidence:94
void ClanAppearNameInputDialog::OnSubmitText(const wchar_t *text)
{
    char convertedName[256];
    unsigned char packet[128];

    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(0x09, packet + 1);
    PacketBufferWriteUInt8(0x01, packet + 2);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP, 0, text, wcslen(text), convertedName, sizeof(convertedName), NULL, NULL);
    convertedName[convertedLength] = 0;
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + 3);
    memmove(packet + 4, convertedName, convertedLength);

    unsigned int packetLength = convertedLength + 4;
    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}

// UID:000024 | by-class/ClanAttrInputDialog.md | Completion:92 | Confidence:93
// UID:0004HH | by-memory/0x00489600-0x00489de1.ClanAttrInputDialogConstructor.md | Completion:90 | Confidence:92
ClanAttrInputDialog::ClanAttrInputDialog(const unsigned char *packet)
    : DialogPane(L"", -1, true)
{
    char textBytes[256];
    wchar_t headingText[256];
    wchar_t clanCaptionText[256];
    wchar_t descriptionPromptText[256];
    wchar_t attributePromptText[256];
    wchar_t attributeTypePromptText[256];

    const unsigned char *textPacket = packet + 3;
    unsigned int textLength = *textPacket++;
    memmove(textBytes, textPacket, textLength);
    textPacket += textLength;
    textBytes[textLength] = '\0';
    unsigned char wideLength = static_cast<unsigned char>(MultiByteToWideChar(
        CP_ACP, 0, textBytes, textLength, m_submittedClanName, 256));
    m_submittedClanName[wideLength] = L'\0';

    textLength = *textPacket++;
    memmove(textBytes, textPacket, textLength);
    textPacket += textLength;
    textBytes[textLength] = '\0';
    wideLength = static_cast<unsigned char>(MultiByteToWideChar(
        CP_ACP, 0, textBytes, textLength, headingText, 256));
    headingText[wideLength] = L'\0';

    textLength = *textPacket++;
    memmove(textBytes, textPacket, textLength);
    textPacket += textLength;
    textBytes[textLength] = '\0';
    wideLength = static_cast<unsigned char>(MultiByteToWideChar(
        CP_ACP, 0, textBytes, textLength, clanCaptionText, 256));
    clanCaptionText[wideLength] = L'\0';

    textLength = *textPacket++;
    memmove(textBytes, textPacket, textLength);
    textPacket += textLength;
    textBytes[textLength] = '\0';
    wideLength = static_cast<unsigned char>(MultiByteToWideChar(
        CP_ACP, 0, textBytes, textLength, descriptionPromptText, 256));
    descriptionPromptText[wideLength] = L'\0';

    textLength = *textPacket++;
    memmove(textBytes, textPacket, textLength);
    textPacket += textLength;
    textBytes[textLength] = '\0';
    wideLength = static_cast<unsigned char>(MultiByteToWideChar(
        CP_ACP, 0, textBytes, textLength, attributePromptText, 256));
    attributePromptText[wideLength] = L'\0';

    textLength = *textPacket++;
    memmove(textBytes, textPacket, textLength);
    textBytes[textLength] = '\0';
    wideLength = static_cast<unsigned char>(MultiByteToWideChar(
        CP_ACP, 0, textBytes, textLength, attributeTypePromptText, 256));
    attributeTypePromptText[wideLength] = L'\0';

    AddControl(new EPFImageControlPane(
        L"DLGCLAN2.EPF", Rect(0, 0, 259, 288), 0, true));
    AddControl(new ImageButtonControlPane(14, Rect(53, 228, 125, 244)));
    AddControl(new ImageButtonControlPane(22, Rect(130, 228, 202, 244)));
    AddControl(new StaticTextControlPane(
        headingText, true, 128, Rect(41, 20, 231, 45)));
    AddControl(new StaticTextControlPane(
        clanCaptionText, true, 128, Rect(41, 49, 231, 74)));
    AddControl(new StaticTextControlPane(
        descriptionPromptText, true, 128, Rect(41, 66, 231, 91)));
    AddControl(new StaticTextControlPane(
        attributePromptText, true, 128, Rect(41, 116, 231, 141)));
    AddControl(new StaticTextControlPane(
        attributeTypePromptText, true, 128, Rect(41, 166, 231, 191)));
    AddControl(new TextEditControlPane(
        L"", true, 128, Rect(41, 91, 218, 104)));
    AddControl(new TextEditControlPane(
        L"", true, 128, Rect(41, 141, 218, 154)));
    AddControl(new TextEditControlPane(
        L"", true, 128, Rect(41, 191, 218, 204)));

    SetHoverControl(8);
    SetFocusedControl(1);
    SetPendingControl(2);
    SetBackgroundResource(L"DLGCLAN2.EPF", NULL);
    SetMode(1);

    RectBounds dialogBounds;
    InitRectBounds(&dialogBounds, 174, 12, 433, 300);
    OnCreate(
        &dialogBounds,
        0,
        NULL,
        g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenHorizontal(0);
}

// UID:0004HI | by-memory/0x00489df0-0x00489eb7.ClanAttrInputDialogOnControlCommand.md | Completion:90 | Confidence:93
void ClanAttrInputDialog::OnControlCommand(int controlIndex, int /*notifyCode*/)
{
    if (controlIndex == 1) {
        TextEditControlPane *descriptionEdit =
            static_cast<TextEditControlPane *>(GetChildControl(8));
        descriptionEdit->ReadText(m_submittedDescriptionText, 255);

        TextEditControlPane *attributeEdit =
            static_cast<TextEditControlPane *>(GetChildControl(9));
        attributeEdit->ReadText(m_submittedAttributeText, 255);

        wchar_t attributeTypeText[256];
        TextEditControlPane *attributeTypeEdit =
            static_cast<TextEditControlPane *>(GetChildControl(10));
        attributeTypeEdit->ReadText(attributeTypeText, 255);
        m_submittedAttributeType =
            static_cast<unsigned short>(_wtol(attributeTypeText));

        OnSubmit();
    } else if (controlIndex != 2) {
        return;
    }

    SlideCloseHorizontal(0);
    CloseDialog();
}

// UID:0004HJ | by-memory/0x00489ec0-0x00489f46.ClanAttrInputDialogValidateInputFields.md | Completion:89 | Confidence:91
void ClanAttrInputDialog::ValidateInputFields()
{
    ImageButtonControlPane *okButton =
        static_cast<ImageButtonControlPane *>(GetChildControl(1));
    TextEditControlPane *descriptionEdit =
        static_cast<TextEditControlPane *>(GetChildControl(8));
    TextEditControlPane *attributeEdit =
        static_cast<TextEditControlPane *>(GetChildControl(9));
    TextEditControlPane *typeEdit =
        static_cast<TextEditControlPane *>(GetChildControl(10));

    okButton->SetEnabled(!descriptionEdit->IsEmpty() &&
        !attributeEdit->IsEmpty() &&
        !typeEdit->IsEmpty());
}

// UID:0004HK | by-memory/0x00489f50-0x00489f80.ClanAttrInputDialogOnInputEvent.md | Completion:89 | Confidence:91
bool ClanAttrInputDialog::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type == 3) {
        g_pClanStatusPane->HandlePointerOrMouseEvent(event);
    }

    return DialogPane::HandlePointerOrMouseEvent(event);
}

// UID:000027 | by-class/ClanChangeInputDialog.md | Completion:92 | Confidence:93
// UID:0002O4 | by-memory/0x00489ff0-0x0048a025.ClanChangeInputDialogRawConstructor.md | Completion:92 | Confidence:93
ClanChangeInputDialog::ClanChangeInputDialog(const unsigned char *packet)
    : ClanAttrInputDialog(packet)
{
}

// UID:0002O5 | by-memory/0x0048a030-0x0048a059.ClanChangeInputDialogOnSubmit.md | Completion:89 | Confidence:93
int ClanChangeInputDialog::OnSubmit()
{
    return SubmitClanChangeHelper(
        m_submittedClanName,
        m_submittedDescriptionText,
        m_submittedAttributeText,
        m_submittedAttributeType);
}

// UID:000028 | by-class/ClanChangeNameInputDialog.md | Completion:85 | Confidence:89
// UID:0002O1 | by-memory/0x004894d0-0x00489505.ClanChangeNameInputDialogRawConstructor.md | Completion:92 | Confidence:93
ClanChangeNameInputDialog::ClanChangeNameInputDialog(const unsigned char *packet)
    : ClanNameInputDialog(packet)
{
}

// UID:0002O2 | by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md | Completion:86 | Confidence:91
void ClanChangeNameInputDialog::OnSubmitText(const wchar_t *text)
{
    char convertedName[256];
    unsigned char packet[128];

    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(0x0a, packet + 1);
    PacketBufferWriteUInt8(0x01, packet + 2);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP, 0, text, wcslen(text), convertedName, sizeof(convertedName), NULL, NULL);
    if (convertedLength >= sizeof(convertedName)) {
        __report_rangecheckfailure();
    }

    convertedName[convertedLength] = 0;
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + 3);
    memmove(packet + 4, convertedName, convertedLength);

    unsigned int packetLength = convertedLength + 4;
    if (packetLength >= sizeof(packet)) {
        __report_rangecheckfailure();
    }

    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}

// UID:00002A | by-class/ClanDepMoneyInputDialog.md | Completion:86 | Confidence:90
// UID:00021V | by-memory/0x00488fa0-0x00488fd5.ClanDepMoneyInputDialogRawConstructor.md | Completion:92 | Confidence:93
ClanDepMoneyInputDialog::ClanDepMoneyInputDialog(const unsigned char *packet)
    : ClanNameInputDialog(packet)
{
}

// UID:0002NS | by-memory/0x00488fe0-0x00489062.ClanDepMoneyInputDialogSubmitDepositMoney.md | Completion:86 | Confidence:91
void ClanDepMoneyInputDialog::OnSubmitText(const wchar_t *text)
{
    unsigned char packet[128];
    unsigned long amount = _wtol(text);

    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(0x04, packet + 1);
    PacketBufferWriteUInt8(0x01, packet + 2);
    PacketBufferWriteUInt32BE(amount, packet + 3);
    packet[7] = 0;

    g_packetSender->QueueAndSendPacket(packet, 7);
}

// UID:00002B | by-class/ClanEnlistInputDialog.md | Completion:92 | Confidence:93
// UID:00021W | by-memory/0x00489f80-0x00489fb5.ClanEnlistInputDialogRawConstructor.md | Completion:92 | Confidence:93
ClanEnlistInputDialog::ClanEnlistInputDialog(const unsigned char *packet)
    : ClanAttrInputDialog(packet)
{
}

// UID:0002O3 | by-memory/0x00489fc0-0x00489fe9.ClanEnlistInputDialogOnSubmit.md | Completion:88 | Confidence:92
int ClanEnlistInputDialog::OnSubmit()
{
    return g_pClanStatusPane->SendClanAttributePacket(
        m_submittedClanName,
        m_submittedDescriptionText,
        m_submittedAttributeText,
        m_submittedAttributeType);
}

// UID:00002C | by-class/ClanEnlistListPane.md | Completion:86 | Confidence:90
class ClanEnlistListPane : public ClanStringListPane
{
public:
    ClanEnlistListPane();

protected:
    virtual int OnSelectedRowAction();
    virtual bool OnKeyEvent(const PaneKeyEvent *event);
};

// UID:000412 | by-memory/0x00488970-0x00488991.ClanEnlistListPaneSelectedRowAction.md | Completion:88 | Confidence:92
int ClanEnlistListPane::OnSelectedRowAction()
{
    const int selectedIndex = m_selectedIndex;
    if (selectedIndex < 0)
        return selectedIndex;

    const wchar_t *applicantName =
        static_cast<const wchar_t *>(GetSelectedEntry(selectedIndex));
    return g_pClanStatusPane->SendClanEnlistListSelectionPacket(applicantName);
}

// UID:000413 | by-memory/0x004889a0-0x00488b3d.ClanEnlistListPaneOnKeyEvent.md | Completion:87 | Confidence:91
bool ClanEnlistListPane::OnKeyEvent(const PaneKeyEvent *event)
{
    if (ListPane::OnKeyEvent(event))
        return true;

    const unsigned char key =
        static_cast<unsigned char>(NarrowPaneKey(event->payload[0], event->keyState));

    const int selectedIndex = m_selectedIndex;
    if (selectedIndex < 0)
        return false;

    const wchar_t *applicantName =
        static_cast<const wchar_t *>(GetSelectedEntry(selectedIndex));

    if (key == kKeyEnter) {
        g_pClanStatusPane->SendClanEnlistListSelectionPacket(applicantName);
        return true;
    }

    constexpr unsigned char kClanEnlistListAction3Key = 0x84;
    if (key != kClanEnlistListAction3Key)
        return false;

    char convertedName[256];
    unsigned char packet[128];

    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(0x06, packet + 1);
    PacketBufferWriteUInt8(0x03, packet + 2);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP, 0, applicantName, wcslen(applicantName), convertedName, sizeof(convertedName), NULL, NULL);
    if (convertedLength >= sizeof(convertedName)) {
        __report_rangecheckfailure();
    }

    convertedName[convertedLength] = 0;
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + 3);
    memmove(packet + 4, convertedName, convertedLength);

    unsigned int packetLength = convertedLength + 4;
    if (packetLength >= sizeof(packet)) {
        __report_rangecheckfailure();
    }

    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
    g_pClanStatusPane->SendClanEnlistListRefreshPacket();
    return true;
}

// UID:00002D | by-class/ClanExpelNameInputDialog.md | Completion:86 | Confidence:90
// UID:0002NV | by-memory/0x00489140-0x00489175.ClanExpelNameInputDialogRawConstructor.md | Completion:92 | Confidence:93
ClanExpelNameInputDialog::ClanExpelNameInputDialog(const unsigned char *packet)
    : ClanNameInputDialog(packet)
{
}

// UID:0002NW | by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md | Completion:94 | Confidence:94
void ClanExpelNameInputDialog::OnSubmitText(const wchar_t *text)
{
    char convertedName[256];
    unsigned char packet[128];

    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(0x07, packet + 1);
    PacketBufferWriteUInt8(0x01, packet + 2);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP, 0, text, wcslen(text), convertedName, sizeof(convertedName), NULL, NULL);
    convertedName[convertedLength] = 0;
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + 3);
    memmove(packet + 4, convertedName, convertedLength);

    unsigned int packetLength = convertedLength + 4;
    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}

// UID:00002E | by-class/ClanInfoListPane.md | Completion:90 | Confidence:93
#include "Clan.h"

// UID:00021T | by-memory/0x004885a0-0x00488602.ClanInfoListPaneRawConstructor.md | Completion:88 | Confidence:91
// Emitted code for this no-route ClanInfoListPane constructor-shaped range is covered by [UID:00010A][0x00484030-0x00484221.ClanStatusPaneConstructor](by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md) ClanStatusPane inline child construction and [UID:00002E][ClanInfoListPane](by-class/ClanInfoListPane.md) ClanInfoListPane class/virtual declarations.

// UID:0002NN | by-memory/0x00488610-0x00488615.ClanInfoListPaneFalseActionVirtual.md | Completion:94 | Confidence:95
bool ClanInfoListPane::HandleKeyOrTextEvent(Event * /*event*/)
{
    return false;
}

// UID:0002NO | by-memory/0x00488620-0x00488625.ClanInfoListPaneFalseAlternateVirtual.md | Completion:94 | Confidence:95
bool ClanInfoListPane::OnMouseEvent(Event * /*event*/)
{
    return false;
}

// UID:00002H | by-class/ClanJoinListPane.md | Completion:86 | Confidence:90
class ClanJoinListPane : public ClanStringListPane
{
public:
    ClanJoinListPane();

protected:
    virtual int OnSelectedRowAction();
    virtual bool OnKeyEvent(const PaneKeyEvent *event);
};

// UID:0002NR | by-memory/0x004888d0-0x004888f1.ClanJoinListPaneSelectedRowAction.md | Completion:87 | Confidence:91
int ClanJoinListPane::OnSelectedRowAction()
{
    const int selectedIndex = m_selectedIndex;
    if (selectedIndex < 0)
        return selectedIndex;

    const wchar_t *selectedName =
        static_cast<const wchar_t *>(GetSelectedEntry(selectedIndex));
    return g_pClanStatusPane->SendClanJoinListSelectionPacket(selectedName);
}

// UID:000411 | by-memory/0x00488900-0x00488968.ClanJoinListPaneOnKeyEvent.md | Completion:87 | Confidence:91
bool ClanJoinListPane::OnKeyEvent(const PaneKeyEvent *event)
{
    if (ListPane::OnKeyEvent(event))
        return true;

    const unsigned char key =
        static_cast<unsigned char>(NarrowPaneKey(event->payload[0], event->keyState));

    const int selectedIndex = m_selectedIndex;
    if (selectedIndex < 0)
        return false;

    const wchar_t *selectedName =
        static_cast<const wchar_t *>(GetSelectedEntry(selectedIndex));
    if (key != kKeyEnter)
        return false;

    g_pClanStatusPane->SendClanJoinListSelectionPacket(selectedName);
    return true;
}

// UID:00002I | by-class/ClanLeaveConfirmDialog.md | Completion:92 | Confidence:93
// UID:0002O6 | by-memory/0x0048a060-0x0048a09e.ClanLeaveConfirmDialogRawConstructor.md | Completion:92 | Confidence:93
ClanLeaveConfirmDialog::ClanLeaveConfirmDialog(
    const wchar_t *messageText,
    Pane *layoutReference,
    const wchar_t *primaryButtonText,
    const wchar_t *secondaryButtonText)
    : AlertPane(messageText,
                layoutReference,
                primaryButtonText,
                secondaryButtonText)
{
}

// UID:0002O7 | by-memory/0x0048a0a0-0x0048a0ae.ClanLeaveConfirmDialogConfirm.md | Completion:88 | Confidence:93
void ClanLeaveConfirmDialog::OnConfirm()
{
    g_pClanStatusPane->SendClanLeaveResponse(true);
}

// UID:0002O8 | by-memory/0x0048a0b0-0x0048a0be.ClanLeaveConfirmDialogCancel.md | Completion:88 | Confidence:93
void ClanLeaveConfirmDialog::OnCancel()
{
    g_pClanStatusPane->SendClanLeaveResponse(false);
}

// UID:00002J | by-class/ClanNameInputDialog.md | Completion:86 | Confidence:89
[[No Children Attached]]

// UID:00002K | by-class/ClanStatusPane.md | Completion:89 | Confidence:91
// UID:00010A | by-memory/0x00484030-0x00484221.ClanStatusPaneConstructor.md | Completion:87 | Confidence:91
ClanStatusPane::ClanStatusPane()
    : Pane(1)
{
    g_pClanStatusPane = this;

    m_infoListPane = new ClanInfoListPane;
    m_infoListPane->SetMode(1);
    m_infoListPane->SetTextEditMode(FALSE, FALSE);

    m_joinListPane = new ClanJoinListPane;
    m_joinListPane->SetMode(1);

    m_enlistListPane = new ClanEnlistListPane;
    m_enlistListPane->SetMode(1);

    m_rawAttributeDataLength = 0;
}

// UID:00010B | by-memory/0x004842b0-0x00484a50.ClanAttributePacketParser.md | Completion:87 | Confidence:90
// Source-local first-draft convention for the repeated inline packet text decode.
// This is not a recovered external helper or a new binary call target.
static inline const unsigned char* ReadClanPacketText8ToWide40(
    const unsigned char* cursor,
    wchar_t* outText,
    size_t outTextCapacity)
{
    char narrowText[40] = {};
    const unsigned char textLength = *cursor++;

    if (textLength >= sizeof(narrowText) || outTextCapacity < 40) {
        __report_rangecheckfailure();
    }

    memmove(narrowText, cursor, textLength);
    cursor += textLength;
    narrowText[textLength] = '\0';

    wchar_t wideText[40] = {};
    const int wideCount = MultiByteToWideChar(
        CP_ACP,
        0,
        narrowText,
        textLength,
        wideText,
        _countof(wideText));

    if (wideCount < 0 || wideCount >= static_cast<int>(_countof(wideText))) {
        __report_rangecheckfailure();
    }

    wideText[wideCount] = L'\0';
    wcscpy_s(outText, outTextCapacity, wideText);
    return cursor;
}

void ClanStatusPane::ParseClanStatusAttributePacket(const unsigned char* packet)
{
    const unsigned char* cursor = packet + 1;
    ++cursor; // subtype 0 was already selected by the dispatcher.

    const unsigned char statusDataVersion = *cursor++;

    wchar_t headerText[40] = {};
    wchar_t statusText0[40] = {};
    wchar_t statusText1[40] = {};
    wchar_t statusText2[40] = {};
    wchar_t statusText3[40] = {};
    wchar_t statusText4[40] = {};
    wchar_t managementText0[40] = {};
    wchar_t managementText1[40] = {};
    wchar_t managementText2[40] = {};
    wchar_t managementText3[40] = {};
    wchar_t managementText4[40] = {};
    wchar_t managementText5[40] = {};
    wchar_t managementText6[40] = {};

    cursor = ReadClanPacketText8ToWide40(cursor, headerText, _countof(headerText));

    const unsigned short rawAttributeDataLength = PacketBufferReadUInt16BE(cursor);
    cursor += sizeof(unsigned short);

    memmove(m_rawAttributeData, cursor, rawAttributeDataLength);
    cursor += rawAttributeDataLength;

    ++cursor; // Reserved/status text group byte; no safe semantic name yet.

    cursor = ReadClanPacketText8ToWide40(cursor, statusText0, _countof(statusText0));
    cursor = ReadClanPacketText8ToWide40(cursor, statusText1, _countof(statusText1));
    cursor = ReadClanPacketText8ToWide40(cursor, statusText2, _countof(statusText2));
    cursor = ReadClanPacketText8ToWide40(cursor, statusText3, _countof(statusText3));
    cursor = ReadClanPacketText8ToWide40(cursor, statusText4, _countof(statusText4));

    if (statusDataVersion >= 2) {
        cursor = ReadClanPacketText8ToWide40(cursor, managementText0, _countof(managementText0));
        cursor = ReadClanPacketText8ToWide40(cursor, managementText1, _countof(managementText1));
        cursor = ReadClanPacketText8ToWide40(cursor, managementText5, _countof(managementText5));
        cursor = ReadClanPacketText8ToWide40(cursor, managementText6, _countof(managementText6));
        cursor = ReadClanPacketText8ToWide40(cursor, managementText4, _countof(managementText4));
        cursor = ReadClanPacketText8ToWide40(cursor, managementText2, _countof(managementText2));
        cursor = ReadClanPacketText8ToWide40(cursor, managementText3, _countof(managementText3));
    }

    RefreshChildPanes();

    m_statusDataVersion = statusDataVersion;
    m_selectedStatusRow = 0xffff;
    m_rawAttributeDataLength = rawAttributeDataLength;
    m_currentClanStatusView = ClanStatusView_Status;

    wcscpy_s(m_statusHeaderText, _countof(m_statusHeaderText), headerText);
    wcscpy_s(m_statusActionText[0], _countof(m_statusActionText[0]), statusText0);
    wcscpy_s(m_statusActionText[1], _countof(m_statusActionText[1]), statusText1);
    wcscpy_s(m_statusActionText[2], _countof(m_statusActionText[2]), statusText2);
    wcscpy_s(m_statusActionText[3], _countof(m_statusActionText[3]), statusText3);
    wcscpy_s(m_statusActionText[4], _countof(m_statusActionText[4]), statusText4);

    if (statusDataVersion >= 2) {
        wcscpy_s(m_managementActionText[0], _countof(m_managementActionText[0]), managementText0);
        wcscpy_s(m_managementActionText[1], _countof(m_managementActionText[1]), managementText1);
        wcscpy_s(m_managementActionText[2], _countof(m_managementActionText[2]), managementText2);
        wcscpy_s(m_managementActionText[3], _countof(m_managementActionText[3]), managementText3);
        wcscpy_s(m_managementActionText[4], _countof(m_managementActionText[4]), managementText4);
        wcscpy_s(m_managementActionText[5], _countof(m_managementActionText[5]), managementText5);
        wcscpy_s(m_managementActionText[6], _countof(m_managementActionText[6]), managementText6);
    }

    Invalidate();
}

// UID:00010C | by-memory/0x00484a60-0x00484f16.ClanStatusPaneFrameAndInput.md | Completion:88 | Confidence:91
// Aggregate only: split into ClanStatusPane::OnPaintFrame (0x00484a60-0x00484cb0), ClanStatusPane::OnKeyInput (0x00484cd0-0x00484da2), and ClanStatusPane::OnMouseEvent (0x00484db0-0x00484f16) before emitting source bodies.

// UID:00021C | by-memory/0x00484f70-0x0048540b.ClanStatusPacketDispatcher.md | Completion:87 | Confidence:90
// No aggregate dispatcher body here: packet subtype control flow is documented, but formal source must first choose inline dialog construction versus retained local opener helpers shared with the 0x004877d0-0x00488594 handler band.

// UID:00021G | by-memory/0x00485590-0x00485682.SendClanJoinListSelectionPacket.md | Completion:88 | Confidence:91
int ClanStatusPane::SendClanJoinListSelectionPacket(const wchar_t *selectedClanName)
{
    char convertedName[256];
    unsigned char packet[128];

    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(0x02, packet + 1);
    PacketBufferWriteUInt8(0x01, packet + 2);

    const char sourceCharCount = static_cast<char>(wcslen(selectedClanName));
    const int convertedLength = WideCharToMultiByte(
        CP_ACP,
        0,
        selectedClanName,
        sourceCharCount,
        convertedName,
        sizeof(convertedName),
        NULL,
        NULL);
    if (static_cast<unsigned int>(convertedLength) >= sizeof(convertedName)) {
        __report_rangecheckfailure();
    }

    convertedName[convertedLength] = '\0';
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + 3);
    memmove(packet + 4, convertedName, convertedLength);

    const int packetLength = convertedLength + 4;
    if (static_cast<unsigned int>(packetLength) >= sizeof(packet)) {
        __report_rangecheckfailure();
    }

    packet[packetLength] = 0;
    return g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}

// UID:00010D | by-memory/0x00485700-0x00485778.SendClanLeaveResponse.md | Completion:88 | Confidence:92
void ClanStatusPane::SendClanLeaveResponse(bool confirmed)
{
    unsigned char packet[5];

    PacketBufferWriteUInt8(0x4b, &packet[0]);
    PacketBufferWriteUInt8(3, &packet[1]);
    PacketBufferWriteUInt8(1, &packet[2]);
    PacketBufferWriteUInt8(confirmed ? 1 : 0, &packet[3]);
    packet[4] = 0;

    g_packetSender->QueueAndSendPacket(packet, 4);
}

// UID:00021K | by-memory/0x00485960-0x00485abe.ClanEnlistListRefreshAndSelectionPacketHelpers.md | Completion:88 | Confidence:91
int ClanStatusPane::SendClanEnlistListRefreshPacket()
{
    unsigned char packet[128];

    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(0x06, packet + 1);
    PacketBufferWriteUInt8(0x00, packet + 2);
    packet[3] = 0;

    return g_packetSender->QueueAndSendPacket(packet, 3);
}

int ClanStatusPane::SendClanEnlistListSelectionPacket(const wchar_t *applicantName)
{
    char convertedName[256];
    unsigned char packet[128];

    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(0x06, packet + 1);
    PacketBufferWriteUInt8(0x01, packet + 2);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP, 0, applicantName, wcslen(applicantName), convertedName, sizeof(convertedName), NULL, NULL);
    if (convertedLength >= sizeof(convertedName)) {
        __report_rangecheckfailure();
    }

    convertedName[convertedLength] = 0;
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + 3);
    memmove(packet + 4, convertedName, convertedLength);

    unsigned int packetLength = convertedLength + 4;
    if (packetLength >= sizeof(packet)) {
        __report_rangecheckfailure();
    }

    packet[packetLength] = 0;
    return g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}

// UID:00010E | by-memory/0x00485ac0-0x00485cbd.SendClanAttributePacket.md | Completion:88 | Confidence:92
int ClanStatusPane::SendClanAttributePacket(
    const wchar_t *clanName,
    const wchar_t *descriptionText,
    const wchar_t *attributeText,
    unsigned short attributeType)
{
    unsigned char packet[0x304];
    char convertedText[0x100];
    unsigned int packetOffset = 0;

    PacketBufferWriteUInt8(0x4b, packet + packetOffset++);
    PacketBufferWriteUInt8(6, packet + packetOffset++);
    PacketBufferWriteUInt8(2, packet + packetOffset++);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP, 0, clanName, wcslen(clanName), convertedText, sizeof(convertedText), NULL, NULL);
    if (convertedLength >= sizeof(convertedText)) {
        __report_rangecheckfailure();
    }
    convertedText[convertedLength] = '\0';
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + packetOffset++);
    memmove(packet + packetOffset, convertedText, convertedLength);
    packetOffset += convertedLength;

    convertedLength = WideCharToMultiByte(
        CP_ACP, 0, descriptionText, wcslen(descriptionText), convertedText, sizeof(convertedText), NULL, NULL);
    if (convertedLength >= sizeof(convertedText)) {
        __report_rangecheckfailure();
    }
    convertedText[convertedLength] = '\0';
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + packetOffset++);
    memmove(packet + packetOffset, convertedText, convertedLength);
    packetOffset += convertedLength;

    convertedLength = WideCharToMultiByte(
        CP_ACP, 0, attributeText, wcslen(attributeText), convertedText, sizeof(convertedText), NULL, NULL);
    if (convertedLength >= sizeof(convertedText)) {
        __report_rangecheckfailure();
    }
    convertedText[convertedLength] = '\0';
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + packetOffset++);
    memmove(packet + packetOffset, convertedText, convertedLength);
    packetOffset += convertedLength;

    PacketBufferWriteUInt16BE(attributeType, packet + packetOffset);
    packetOffset += sizeof(attributeType);

    return g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetOffset));
}

// UID:0004Q5 | by-memory/0x00486800-0x00486cde.ClanStatusPaneDrawStatusRowText.md | Completion:91 | Confidence:93
void ClanStatusPane::DrawStatusRowText(short rowIndex)
{
    const wchar_t *text;
    int baselineY;

    switch (rowIndex) {
    case kClanStatusRowHeader:
        text = m_statusHeaderText;
        baselineY = 61;
        break;
    case kClanStatusRowEnlistRequest:
        text = m_statusActionText[0];
        baselineY = 112;
        break;
    case kClanStatusRowJoinList:
        text = m_statusActionText[1];
        baselineY = 141;
        break;
    case kClanStatusRowLeaveClan:
        text = m_statusActionText[2];
        baselineY = 170;
        break;
    case kClanStatusRowDepositMoney:
        text = m_statusActionText[3];
        baselineY = 199;
        break;
    case kClanStatusRowDepositItem:
        text = m_statusActionText[4];
        baselineY = 228;
        break;
    case kClanStatusRowEnlistList:
        text = m_managementActionText[0];
        baselineY = 83;
        break;
    case kClanStatusRowExpelMember:
        text = m_managementActionText[1];
        baselineY = 112;
        break;
    case kClanStatusRowSummonMember:
        text = m_managementActionText[2];
        baselineY = 141;
        break;
    case kClanStatusRowAppearMember:
        text = m_managementActionText[3];
        baselineY = 170;
        break;
    case kClanStatusRowChangeName:
        text = m_managementActionText[4];
        baselineY = 199;
        break;
    case kClanStatusRowWithdrawMoney:
        text = m_managementActionText[5];
        baselineY = 228;
        break;
    case kClanStatusRowWithdrawItem:
        text = m_managementActionText[6];
        baselineY = 257;
        break;
    default:
        return;
    }

    const int selectedOffset = m_selectedStatusRow == rowIndex ? 2 : 0;
    MoveTo(94 - GetTextWidth(text) / 2 + selectedOffset,
           baselineY + selectedOffset);
    DrawWideText(text, static_cast<int>(wcslen(text)));
}

// UID:0004Q6 | by-memory/0x00486d20-0x00486f3f.ClanStatusPaneGetStatusRowRect.md | Completion:92 | Confidence:94
void ClanStatusPane::GetStatusRowRect(short rowIndex, RectBounds *outBounds)
{
    switch (rowIndex) {
    case kClanStatusRowEnlistRequest:
        if (m_currentClanStatusView == kClanStatusViewStatus) {
            InitRectBounds(outBounds, 16, 98, 175, 116);
            return;
        }
        break;
    case kClanStatusRowJoinList:
        if (m_currentClanStatusView == kClanStatusViewStatus) {
            InitRectBounds(outBounds, 16, 127, 175, 145);
            return;
        }
        break;
    case kClanStatusRowLeaveClan:
        if (m_currentClanStatusView == kClanStatusViewStatus) {
            InitRectBounds(outBounds, 16, 156, 175, 174);
            return;
        }
        break;
    case kClanStatusRowDepositMoney:
        if (m_currentClanStatusView == kClanStatusViewStatus) {
            InitRectBounds(outBounds, 16, 185, 175, 203);
            return;
        }
        break;
    case kClanStatusRowDepositItem:
        if (m_currentClanStatusView == kClanStatusViewStatus) {
            InitRectBounds(outBounds, 16, 214, 175, 232);
            return;
        }
        break;
    case kClanStatusRowEnlistList:
        if (m_currentClanStatusView == kClanStatusViewManagement) {
            InitRectBounds(outBounds, 16, 69, 175, 87);
            return;
        }
        break;
    case kClanStatusRowExpelMember:
        if (m_currentClanStatusView == kClanStatusViewManagement) {
            InitRectBounds(outBounds, 16, 98, 175, 116);
            return;
        }
        break;
    case kClanStatusRowSummonMember:
        if (m_currentClanStatusView == kClanStatusViewManagement) {
            InitRectBounds(outBounds, 16, 127, 175, 145);
            return;
        }
        break;
    case kClanStatusRowAppearMember:
        if (m_currentClanStatusView == kClanStatusViewManagement) {
            InitRectBounds(outBounds, 16, 157, 175, 174);
            return;
        }
        break;
    case kClanStatusRowChangeName:
        if (m_currentClanStatusView == kClanStatusViewManagement) {
            InitRectBounds(outBounds, 16, 185, 175, 203);
            return;
        }
        break;
    case kClanStatusRowWithdrawMoney:
        if (m_currentClanStatusView == kClanStatusViewManagement) {
            InitRectBounds(outBounds, 16, 214, 175, 232);
            return;
        }
        break;
    case kClanStatusRowWithdrawItem:
        if (m_currentClanStatusView == kClanStatusViewManagement) {
            InitRectBounds(outBounds, 16, 243, 175, 261);
            return;
        }
        break;
    case kClanStatusRowManagementTab:
        if (m_currentClanStatusView <= kClanStatusViewManagement) {
            InitRectBounds(outBounds, 96, 270, 108, 282);
            return;
        }
        break;
    case kClanStatusRowStatusTab:
        if (m_currentClanStatusView <= kClanStatusViewManagement) {
            InitRectBounds(outBounds, 84, 270, 96, 282);
            return;
        }
        break;
    }

    InitRectBounds(outBounds, -1, -1, -1, -1);
}

// UID:0004Q7 | by-memory/0x00486f90-0x00487291.ClanStatusPaneHitTestStatusRow.md | Completion:91 | Confidence:93
short ClanStatusPane::HitTestStatusRow(int y, int x)
{
    for (short rowIndex = 0; rowIndex < 16; ++rowIndex) {
        RectBounds bounds;
        GetStatusRowRect(rowIndex, &bounds);
        if (PointInRect(y, x, &bounds))
            return rowIndex;
    }

    return -1;
}

// UID:00021N | by-memory/0x004872e0-0x00487335.ClanStatusPaneRowEligibilityHelper.md | Completion:88 | Confidence:91
bool ClanStatusPane::IsRowActionBlocked(short rowIndex)
{
    switch (rowIndex) {
    case 2:
    case 4:
    case 5:
    case 6:
        return m_statusDataVersion < 1 || m_currentClanStatusView != 0;

    case 3:
        return m_statusDataVersion != 0 || m_currentClanStatusView != 0;

    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 15:
        return m_statusDataVersion < 2 || m_currentClanStatusView != 1;

    case 14:
        return m_statusDataVersion < 2 || m_currentClanStatusView != 0;

    default:
        return true;
    }
}

// UID:00021O | by-memory/0x00487370-0x004873b5.ClanStatusPaneRefreshChildPanes.md | Completion:89 | Confidence:91
void ClanStatusPane::RefreshChildPanes()
{
    m_joinListPane->RemoveFromLayer();
    m_joinListPane->UnregisterEventHandler();

    m_infoListPane->RemoveFromLayer();
    m_infoListPane->UnregisterEventHandler();

    m_enlistListPane->RemoveFromLayer();
    m_enlistListPane->UnregisterEventHandler();
}

// UID:00021P | by-memory/0x004873c0-0x00487475.ClanStatusPaneShowInfoList.md | Completion:87 | Confidence:90
// Retained raw ClanStatusPane info-list view-switch byte island; no standalone source body is emitted for [UID:00021P].
// Current IDA and PE route checks find no function object, inbound xref, VA/RVA pointer, or direct E8/E9 branch to 0x004873c0.
// Behavior is documented on the target page and remains covered by the ClanStatusPane source route until a real call/table route and source-quality child-pane virtual slot names are recovered.

// UID:00021Q | by-memory/0x00487480-0x00487535.ClanStatusPaneShowJoinList.md | Completion:87 | Confidence:90
// Retained raw ClanStatusPane join-list view-switch byte island; no standalone source body is emitted for [UID:00021Q].
// Current IDA and PE route checks find no function object, inbound xref, VA/RVA pointer, or direct E8/E9 branch to 0x00487480.
// Behavior is documented on the target page and remains covered by the ClanStatusPane source route until a real call/table route and source-quality child-pane virtual slot names are recovered.

// UID:00021R | by-memory/0x00487540-0x004875f5.ClanStatusPaneShowEnlistList.md | Completion:87 | Confidence:90
// Retained raw ClanStatusPane enlist-list view-switch byte island; no standalone source body is emitted for [UID:00021R].
// Current IDA and PE route checks find no function object, inbound xref, VA/RVA pointer, or direct E8/E9 branch to 0x00487540.
// Behavior is documented on the target page and remains covered by the ClanStatusPane source route until a real call/table route and source-quality child-pane virtual slot names are recovered.

// UID:00010H | by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md | Completion:88 | Confidence:91
int ClanStatusPane::SendClanStatusRowActionPacket(short rowIndex)
{
    unsigned char packet[128];
    unsigned char subtype;

    switch (rowIndex) {
    case 2:
        subtype = 0x01;
        break;
    case 3:
        subtype = 0x02;
        break;
    case 4:
        subtype = 0x03;
        break;
    case 5:
        subtype = 0x04;
        break;
    case 6:
        subtype = 0x05;
        break;
    case 7:
        return SendClanEnlistListRefreshPacket();
    case 8:
        subtype = 0x07;
        break;
    case 9:
        subtype = 0x08;
        break;
    case 10:
        subtype = 0x09;
        break;
    case 11:
        subtype = 0x0a;
        break;
    case 12:
        subtype = 0x0b;
        break;
    case 13:
        subtype = 0x0c;
        break;
    default:
        return rowIndex - 2;
    }

    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(subtype, packet + 1);
    PacketBufferWriteUInt8(0x00, packet + 2);
    packet[3] = 0;

    return g_packetSender->QueueAndSendPacket(packet, 3);
}

// UID:00030P | by-memory/0x0048c590-0x0048c63f.ClanStatusPaneDestructor.md | Completion:89 | Confidence:91
ClanStatusPane::~ClanStatusPane()
{
    if (m_infoListPane != NULL) {
        delete m_infoListPane;
        m_infoListPane = NULL;
    }

    if (m_joinListPane != NULL) {
        delete m_joinListPane;
        m_joinListPane = NULL;
    }

    if (m_enlistListPane != NULL) {
        delete m_enlistListPane;
        m_enlistListPane = NULL;
    }

    g_pClanStatusPane = NULL;
}

// UID:00002L | by-class/ClanStringListPane.md | Completion:87 | Confidence:90
class ClanStringListPane : public ListPane
{
public:
    ClanStringListPane();

    int InsertOrReplaceText(const wchar_t *text);

private:
    int FindText(const wchar_t *text);

protected:
    virtual void DrawItem(int rowIndex, const wchar_t *rowText, const RectBounds *rowBounds);
};

// UID:0002NP | by-memory/0x00488630-0x00488674.ClanStringListPaneRawConstructor.md | Completion:87 | Confidence:91
// No standalone constructor body for this retained ClanStringListPane constructor-shaped range: current MCP finds no function object or inbound route to 0x00488630, while list-pane construction is represented by class declarations and live inline ClanStatusPane setup.

// UID:00035D | by-memory/0x00488680-0x0048873e.ClanStringListPaneInsertOrReplaceText.md | Completion:89 | Confidence:92
int ClanStringListPane::InsertOrReplaceText(const wchar_t *text)
{
    int insertIndex = GetCount();

    for (int rowIndex = 0; rowIndex < insertIndex; ++rowIndex) {
        if (wcscmp(GetRowText(rowIndex), text) == 0) {
            RemoveRows(rowIndex, 1);
            insertIndex = rowIndex;
            break;
        }
    }

    wchar_t rowText[32];
    wcscpy_s(rowText, _countof(rowText), text);
    return InsertRow(insertIndex, rowText);
}

// UID:00035E | by-memory/0x00488740-0x00488754.ClanStringListPaneClearRowsRaw.md | Completion:87 | Confidence:90
// No standalone source body for this retained ClanStringListPane clear-rows raw helper: MCP session 3a33af0b finds no IDA function object, no decompilable body, no inbound xref, and no VA/RVA pointer-pattern route to 0x00488740/0x00488754; the unique 20-byte body only proves the count-then-remove-all ListPane sequence until a real caller or table route proves a source method declaration.

// UID:00035F | by-memory/0x00488760-0x004887c7.ClanStringListPaneFindTextRaw.md | Completion:88 | Confidence:91
int ClanStringListPane::FindText(const wchar_t *text)
{
    int rowCount = GetCount();

    for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
        if (wcscmp(GetRowText(rowIndex), text) == 0) {
            return rowIndex;
        }
    }

    return -1;
}

// UID:0002NQ | by-memory/0x004887d0-0x004888c1.ClanStringListPaneDrawItem.md | Completion:87 | Confidence:91
void ClanStringListPane::DrawItem(int rowIndex, const wchar_t *rowText, const RectBounds *rowBounds)
{
    EPFTileContext drawContext;
    wchar_t text[256];

    drawContext.InitTileContext();

    if (IsItemSelected(rowIndex)) {
        SetDrawColor(128);
        g_pfnFillOrInvalidateRect(this, rowBounds);
    }

    SetTextColor(143);
    m_textDrawMode = 1;
    SetTextBackColor(0);

    wcscpy_s(text, _countof(text), rowText);

    const int y = ((rowBounds->top + rowBounds->bottom) / 2) + 6;
    FitTextAndAppendSuffix(text, _countof(text), L"...", rowBounds->right - 50);
    MoveTo(50, y);
    DrawWideText(text, static_cast<int>(wcslen(text)));
}

// UID:00002M | by-class/ClanSummonNameInputDialog.md | Completion:85 | Confidence:89
// UID:0002NX | by-memory/0x00489270-0x004892a5.ClanSummonNameInputDialogRawConstructor.md | Completion:92 | Confidence:93
ClanSummonNameInputDialog::ClanSummonNameInputDialog(const unsigned char *packet)
    : ClanNameInputDialog(packet)
{
}

// UID:0002NY | by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md | Completion:94 | Confidence:94
void ClanSummonNameInputDialog::OnSubmitText(const wchar_t *text)
{
    char convertedName[256];
    unsigned char packet[128];

    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(0x08, packet + 1);
    PacketBufferWriteUInt8(0x01, packet + 2);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP, 0, text, wcslen(text), convertedName, sizeof(convertedName), NULL, NULL);
    convertedName[convertedLength] = 0;
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + 3);
    memmove(packet + 4, convertedName, convertedLength);

    unsigned int packetLength = convertedLength + 4;
    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetLength));
}

// UID:00002O | by-class/ClanWidMoneyInputDialog.md | Completion:86 | Confidence:90
// UID:0002NT | by-memory/0x00489070-0x004890a5.ClanWidMoneyInputDialogRawConstructor.md | Completion:92 | Confidence:93
ClanWidMoneyInputDialog::ClanWidMoneyInputDialog(const unsigned char *packet)
    : ClanNameInputDialog(packet)
{
}

// UID:0002NU | by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md | Completion:94 | Confidence:94
void ClanWidMoneyInputDialog::OnSubmitText(const wchar_t *text)
{
    unsigned char packet[128];
    unsigned long amount = _wtol(text);

    PacketBufferWriteUInt8(0x4b, packet + 0);
    PacketBufferWriteUInt8(0x0b, packet + 1);
    PacketBufferWriteUInt8(0x01, packet + 2);
    PacketBufferWriteUInt32BE(amount, packet + 3);
    packet[7] = 0;

    g_packetSender->QueueAndSendPacket(packet, 7);
}

// UID:0002XG | by-global/g_pClanStatusPane.md | Completion:88 | Confidence:92
ClanStatusPane *g_pClanStatusPane = NULL;

// UID:00021D | by-memory/0x00485440-0x004854a5.SendClanStatusRefreshRequestPacket.md | Completion:85 | Confidence:89
// No standalone SendClanStatusRefreshRequestPacket body: the retained raw helper builds opcode 0x4b subtype 0 refresh bytes, but current route scans find no live caller/function route, so emitting it would invent an unused source helper.

// UID:00021E | by-memory/0x004854b0-0x00485518.SendClanEnlistRequestRefreshPacket.md | Completion:85 | Confidence:90
// No standalone SendClanEnlistRequestRefreshPacket body: the retained raw helper builds opcode 0x4b subtype 1 refresh/request bytes, but current route scans find no live caller/function route, so emitting it would invent an unused source helper.

// UID:00021F | by-memory/0x00485520-0x00485588.SendClanJoinListRefreshPacket.md | Completion:85 | Confidence:90
// No standalone SendClanJoinListRefreshPacket body: retained raw bytes build opcode 0x4b subtype 2 action 0, but 2026-07-05 MCP/PE route checks find no function object, caller, pointer, or branch route; live action-0 behavior is represented by ClanStatusPane row-action dispatch, while action-1 selection uses ClanStatusPane::SendClanJoinListSelectionPacket.

// UID:00021H | by-memory/0x00485690-0x004856f9.SendClanLeaveRequestPacket.md | Completion:85 | Confidence:90
// No standalone SendClanLeaveRequestPacket body: the retained raw helper builds opcode 0x4b subtype 3 request bytes, but current route scans find no live caller/function route; live leave confirmation response is emitted by ClanStatusPane::SendClanLeaveResponse.

// UID:00021I | by-memory/0x00485780-0x00485867.ClanDepositMoneyRequestAndSubmitPacketHelpers.md | Completion:85 | Confidence:89
// No standalone deposit-money helper body: the retained subtype 4 helper band has no proved live helper route, and the source-visible deposit-money submit path is already emitted by ClanDepMoneyInputDialog::OnSubmitText.

// UID:00021J | by-memory/0x00485870-0x00485955.ClanDepositItemRequestAndSubmitPacketHelpers.md | Completion:85 | Confidence:89
// No standalone deposit-item helper body: the retained subtype 5 helper band has no proved live helper route, and item dialog source emission is handled by the Clan item dialog pages rather than this empty helper strip.

// UID:00021L | by-memory/0x00485cc0-0x0048632e.ClanNameActionPacketHelpers.md | Completion:86 | Confidence:91
// Emitted code for this retained no-route helper strip is covered by [UID:00010H][0x00487600-0x0048779f.ClanStatusRowActionPacket](by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md), [UID:00021U][0x00488900-0x00488b3d.ClanListPaneInputHandlers](by-memory/0x00488900-0x00488b3d.ClanListPaneInputHandlers.md), [UID:0002NW][0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName](by-memory/0x00489180-0x0048926e.ClanExpelNameInputDialogSubmitName.md), [UID:0002NY][0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName](by-memory/0x004892b0-0x0048939e.ClanSummonNameInputDialogSubmitName.md), [UID:0002O0][0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName](by-memory/0x004893e0-0x004894ce.ClanAppearNameInputDialogSubmitName.md), and [UID:0002O2][0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName](by-memory/0x00489510-0x004895fe.ClanChangeNameInputDialogSubmitName.md).

// UID:00010F | by-memory/0x00486330-0x0048652d.SubmitClanChangeHelper.md | Completion:88 | Confidence:92
static int SubmitClanChangeHelper(
    const wchar_t *clanName,
    const wchar_t *descriptionText,
    const wchar_t *attributeText,
    unsigned short attributeType)
{
    char convertedText[256];
    unsigned char packet[0x200];
    unsigned int packetOffset = 0;

    PacketBufferWriteUInt8(0x4b, packet + packetOffset++);
    PacketBufferWriteUInt8(0x0a, packet + packetOffset++);
    PacketBufferWriteUInt8(0x02, packet + packetOffset++);

    unsigned int convertedLength = WideCharToMultiByte(
        CP_ACP, 0, clanName, wcslen(clanName), convertedText, sizeof(convertedText), NULL, NULL);
    if (convertedLength >= sizeof(convertedText)) {
        __report_rangecheckfailure();
    }
    convertedText[convertedLength] = 0;
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + packetOffset++);
    memmove(packet + packetOffset, convertedText, convertedLength);
    packetOffset += convertedLength;

    convertedLength = WideCharToMultiByte(
        CP_ACP, 0, descriptionText, wcslen(descriptionText), convertedText, sizeof(convertedText), NULL, NULL);
    if (convertedLength >= sizeof(convertedText)) {
        __report_rangecheckfailure();
    }
    convertedText[convertedLength] = 0;
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + packetOffset++);
    memmove(packet + packetOffset, convertedText, convertedLength);
    packetOffset += convertedLength;

    convertedLength = WideCharToMultiByte(
        CP_ACP, 0, attributeText, wcslen(attributeText), convertedText, sizeof(convertedText), NULL, NULL);
    if (convertedLength >= sizeof(convertedText)) {
        __report_rangecheckfailure();
    }
    convertedText[convertedLength] = 0;
    PacketBufferWriteUInt8(static_cast<unsigned char>(convertedLength), packet + packetOffset++);
    memmove(packet + packetOffset, convertedText, convertedLength);
    packetOffset += convertedLength;

    PacketBufferWriteUInt16BE(attributeType, packet + packetOffset);
    packetOffset += sizeof(unsigned short);

    return g_packetSender->QueueAndSendPacket(packet, static_cast<short>(packetOffset));
}

// UID:00021M | by-memory/0x00486530-0x004867f2.ClanWithdrawAndNoticePacketHelpers.md | Completion:88 | Confidence:91
// Retained no-route helper strip: subtype 11/12 live emissions are covered by [UID:00010H][0x00487600-0x0048779f.ClanStatusRowActionPacket](by-memory/0x00487600-0x0048779f.ClanStatusRowActionPacket.md), [UID:0002NU][0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney](by-memory/0x004890b0-0x00489132.ClanWidMoneyInputDialogSubmitWithdrawMoney.md), [UID:00010P][0x0048a810-0x0048ae65.ClanWidItemDialog](by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md), and [UID:00002N][ClanWidItemDialog](by-class/ClanWidItemDialog.md); subtype 13 remains documentation-only packet evidence.

// UID:00021S | by-memory/0x004877d0-0x00488594.ClanStatusPacketDialogHandlers.md | Completion:86 | Confidence:91
// Aggregate only: split the 0x004877d0-0x00488594 dialog-handler band into the exact handler/opener ranges documented on this page before emitting source bodies.

// UID:00010J | by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md | Completion:88 | Confidence:91
ClanNameInputDialog::ClanNameInputDialog(const unsigned char *packet)
    : DialogPane(L"", -1, true)
{
    char promptBytes[0x8000];
    wchar_t promptText[0x8000];

    const unsigned int promptLength = packet[3];
    memmove(promptBytes, packet + 4, promptLength);
    promptBytes[promptLength] = '\0';

    const int wideLength = MultiByteToWideChar(
        CP_ACP,
        0,
        promptBytes,
        promptLength,
        promptText,
        0x8000);

    if (static_cast<unsigned int>(wideLength) >= 0x8000) {
        __report_rangecheckfailure();
    }

    promptText[wideLength] = L'\0';

    AddControl(new EPFImageControlPane(L"DLGCLAN1.EPF", Rect(0, 0, 278, 161), 0, true));
    AddControl(new ImageButtonControlPane(14, Rect(65, 117, 137, 133)));
    AddControl(new ImageButtonControlPane(22, Rect(142, 117, 214, 133)));
    AddControl(new StaticTextControlPane(promptText, true, 128, Rect(51, 38, 228, 88)));
    AddControl(new TextEditControlPane(L"", true, 128, Rect(51, 94, 228, 107)));

    SelectControl(4);
    SetFocusedControl(1);
    SetCancelControl(2);
    SetBackgroundResource(L"DLGCLAN1.EPF", 0);
    SetMode(1);
    SetDisplayRect(Rect(155, 12, 433, 173));
    ShowDialog(false);
}

void ClanNameInputDialog::OnButtonClick(int closeContext, int controlId)
{
    if (controlId == 1) {
        wchar_t text[256];
        TextEditControlPane *textEdit =
            static_cast<TextEditControlPane *>(GetChildControl(4));

        textEdit->GetText(text, 255);
        OnSubmitText(text);
    } else if (controlId != 2) {
        return;
    }

    StartClose(closeContext);
    CloseDialog();
}

void ClanNameInputDialog::UpdateOkButtonState()
{
    ImageButtonControlPane *okButton =
        static_cast<ImageButtonControlPane *>(GetChildControl(1));
    TextEditControlPane *textEdit =
        static_cast<TextEditControlPane *>(GetChildControl(4));

    okButton->SetEnabled(!textEdit->IsEmpty());
}

bool ClanNameInputDialog::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type == 3) {
        g_pClanStatusPane->HandlePointerOrMouseEvent(event);
    }

    return DialogPane::HandlePointerOrMouseEvent(event);
}



// UID:0002B7 | by-memory/0x0067adf0-0x0069adf0.WideCharStrGlobalBuffer.md | Completion:86 | Confidence:88
static wchar_t WideCharStr[0x10000];

// UID:0003B8 | by-memory\0x006163dc-0x00616430.ClanStatusResourceStrings.md | Completion:85 | Confidence:91 | Empty Emitter Marker

// UID:0003B9 | by-memory\0x00616430-0x00616468.ClanModalDialogResourceStrings.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0003HE | by-type\by-vtable\ClanModalDialogVtables.md | Completion:87 | Confidence:92 | Empty Emitter Marker
