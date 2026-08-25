// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MJ
// Source by-file doc: by-file/PhoneBookDialog.md
// UID:00003R | by-class/DialDialog.md | Completion:94 | Confidence:95
// [UID:00003R] DialDialog class support: exact method bodies are emitted by registered by-memory children.
// UID:0004YD | by-memory/0x0058d750-0x0058d9e2.DialDialogConstructor.md | Completion:93 | Confidence:95
DialDialog::DialDialog(const wchar_t *phoneNumber)
    : DialogPane(L"", 15, true)
{
    RectBounds bounds;
    InitRectBounds(&bounds, 0, 0, 284, 187);
    AddControl(new EPFImageControlPane(L"DLGDIAL.EPD", 0, true,
                                      &bounds, L"NPAL8.PAL"));

    InitRectBounds(&bounds, 106, 137, 178, 153);
    AddControl(new ImageButtonControlPane(30, &bounds));

    InitRectBounds(&bounds, 44, 30, 244, 133);
    AddControl(new StaticTextControlPane(
        L"\xC804\xD654\xB97C \xAC78\xACE0 \xC788\xC2B5\xB2C8\xB2E4.",
        true, 128, 0, &bounds, false, false));

    SetBackgroundResource(L"DLGDIAL.EPD", 0);
    SetPendingControl(1);
    InitRectBounds(&bounds, 0, 0, 284, 187);
    OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pTerminalPane);
    SlideOpenVertical();

    wcsncpy_s(m_phoneNumber, 64, phoneNumber, 63);
    m_phoneNumber[63] = L'\0';

    char dialNumber[64];
    const int phoneLength = static_cast<int>(wcslen(m_phoneNumber));
    const int byteCount = WideCharToMultiByte(
        CP_ACP, 0, m_phoneNumber, phoneLength,
        dialNumber, sizeof(dialNumber), NULL, NULL);
    dialNumber[byteCount] = '\0';

    g_packetSender->PostResetConnectionCommand();
    g_packetSender->PostConnectCommand(
        g_pConfig->m_startupConnectionMode,
        reinterpret_cast<void *>(g_pConfig->m_terminalBaudRate));
    g_packetSender->QueueTransportStringCommand("ATX3DT");
    g_packetSender->QueueTransportStringCommand(dialNumber);
    g_packetSender->QueueTransportStringCommand("\n\r");
    m_modemResponseState = 0;
}

// UID:0004YE | by-memory/0x0058d9f0-0x0058da1e.DialDialogOnControlCommand.md | Completion:93 | Confidence:95
void DialDialog::OnControlCommand(int controlIndex, int /*notifyCode*/)
{
    if (controlIndex != 1)
        return;

    g_packetSender->QueueTransportStringCommand("\r");
    SlideCloseVertical();
    CloseDialog();
}

// UID:0001JH | by-memory/0x0058da20-0x0058db94.DialDialogModemResponseParser.md | Completion:92 | Confidence:94
char DialDialog::ParseModemResponse(SocketPacket *packet)
{
    enum ModemResponseState {
        RESPONSE_NONE = 0,
        RESPONSE_CONNECT_C = 1,
        RESPONSE_CONNECT_CO = 2,
        RESPONSE_CONNECT_CON = 3,
        RESPONSE_CONNECT_CONN = 4,
        RESPONSE_CONNECT_CONNE = 5,
        RESPONSE_CONNECT_CONNEC = 6,
        RESPONSE_BUSY_B = 7,
        RESPONSE_BUSY_BU = 8,
        RESPONSE_BUSY_BUS = 9
    };

    const char *data = packet->m_data;
    const int length = packet->m_length;

    if (length > 100) {
        SlideCloseVertical();
        CloseDialog();
        return 0;
    }

    for (int index = 0; index < length; ++index) {
        const char ch = data[index];

        switch (m_modemResponseState) {
        case RESPONSE_NONE:
            if (ch == 'C') {
                m_modemResponseState = RESPONSE_CONNECT_C;
            } else if (ch == 'B') {
                m_modemResponseState = RESPONSE_BUSY_B;
            }
            break;

        case RESPONSE_CONNECT_C:
            m_modemResponseState = (ch == 'O') ? RESPONSE_CONNECT_CO : RESPONSE_NONE;
            break;

        case RESPONSE_CONNECT_CO:
            m_modemResponseState = (ch == 'N') ? RESPONSE_CONNECT_CON : RESPONSE_NONE;
            break;

        case RESPONSE_CONNECT_CON:
            m_modemResponseState = (ch == 'N') ? RESPONSE_CONNECT_CONN : RESPONSE_NONE;
            break;

        case RESPONSE_CONNECT_CONN:
            m_modemResponseState = (ch == 'E') ? RESPONSE_CONNECT_CONNE : RESPONSE_NONE;
            break;

        case RESPONSE_CONNECT_CONNE:
            m_modemResponseState = (ch == 'C') ? RESPONSE_CONNECT_CONNEC : RESPONSE_NONE;
            break;

        case RESPONSE_CONNECT_CONNEC:
            if (ch == 'T') {
                SlideCloseVertical();
                CloseDialog();
            } else {
                m_modemResponseState = RESPONSE_NONE;
            }
            break;

        case RESPONSE_BUSY_B:
            m_modemResponseState = (ch == 'U') ? RESPONSE_BUSY_BU : RESPONSE_NONE;
            break;

        case RESPONSE_BUSY_BU:
            m_modemResponseState = (ch == 'S') ? RESPONSE_BUSY_BUS : RESPONSE_NONE;
            break;

        case RESPONSE_BUSY_BUS:
            if (ch == 'Y') {
                SlideCloseVertical();
                CloseDialog();
            } else {
                m_modemResponseState = RESPONSE_NONE;
            }
            break;

        default:
            break;
        }
    }

    return 0;
}

// UID:0003DT | by-memory/0x0062dd44-0x0062dddc.DialDialogVtableData.md | Completion:92 | Confidence:95
// DialDialog vtable and RTTI bytes are compiler-generated from the DialDialog declaration and exact virtual methods; do not hand-author raw arrays.

// UID:0003GX | by-memory/0x0062df4c-0x0062df90.DialDialogResourceAndModemStrings.md | Completion:92 | Confidence:95
// DialDialog resource/modem literals are emitted by the constructor and OnControlCommand method children; no standalone data definition is required.





// UID:0001JF | by-memory/0x0058cfa0-0x0058cfdb.PhoneBookSelectedEntryHelper.md | Completion:87 | Confidence:90
struct PhoneBookContactEntry
{
    unsigned char entryFlags;
    wchar_t name[64];
    wchar_t phoneNumber[64];
};

unsigned char PhoneBookListPane::GetSelectedEntryData(
    wchar_t *nameOut,
    size_t nameCapacity,
    wchar_t *numberOut,
    size_t numberCapacity)
{
    const PhoneBookContactEntry *entry =
        static_cast<const PhoneBookContactEntry *>(this->GetSelectedEntry());

    wcscpy_s(nameOut, nameCapacity, entry->name);
    wcscpy_s(numberOut, numberCapacity, entry->phoneNumber);
    return entry->entryFlags;
}

// UID:0000AD | by-class\PhoneBookDialog.md | Completion:88 | Confidence:89 | Empty Emitter Marker

// UID:0003DQ | by-memory\0x0062db48-0x0062dbe4.PhoneBookDialogVtableData.md | Completion:87 | Confidence:92 | Empty Emitter Marker

// UID:0003GV | by-memory\0x0062dee8-0x0062df34.PhoneBookDialogResourceStrings.md | Completion:86 | Confidence:91 | Empty Emitter Marker

// UID:0000AE | by-class\PhoneBookListPane.md | Completion:87 | Confidence:89 | Empty Emitter Marker

// UID:0003DR | by-memory\0x0062dbe4-0x0062dca4.PhoneBookListPaneVtableData.md | Completion:87 | Confidence:92 | Empty Emitter Marker

// UID:0000AF | by-class\PhoneEntryDialog.md | Completion:86 | Confidence:89 | Empty Emitter Marker

// UID:0003DS | by-memory\0x0062dca4-0x0062dd44.PhoneEntryDialogVtableData.md | Completion:87 | Confidence:92 | Empty Emitter Marker

// UID:0003GW | by-memory\0x0062df34-0x0062df4c.PhoneEntryDialogResourceStrings.md | Completion:88 | Confidence:93 | Empty Emitter Marker

// UID:0000V7 | by-item\PhoneBookListHelpers_58cfa0_58dcb0.md | Completion:85 | Confidence:90 | Empty Emitter Marker

// UID:0001JE | by-memory\0x0058c350-0x0058d74c.PhoneBookDialogs.md | Completion:88 | Confidence:89 | Empty Emitter Marker
