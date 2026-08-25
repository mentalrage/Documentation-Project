// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LV
// Source by-file doc: by-file/NewUserDialogPane.md
// UID:0004PH | by-memory/0x004fa3a0-0x004fa5a5.SendCreateAccountRequest.md | Completion:92 | Confidence:94
static void __stdcall SendCreateAccountRequest(
    const wchar_t *accountName,
    const wchar_t *password,
    const wchar_t *profileText)
{
    char packet[0x100];
    char converted[0x100];

    short accountNameLength = static_cast<short>(wcslen(accountName));
    short passwordLength = static_cast<short>(wcslen(password));
    short profileTextLength = static_cast<short>(wcslen(profileText));

    PacketBufferWriteUInt8(2, packet);

    int accountNameByteLength = WideCharToMultiByte(
        0, 0, accountName, accountNameLength, converted, 0x100, NULL, NULL);
    if (accountNameByteLength >= 0x100) {
        __report_rangecheckfailure();
    }
    converted[accountNameByteLength] = 0;
    PacketBufferWriteUInt8(accountNameByteLength, packet + 1);
    memmove(packet + 2, converted, accountNameByteLength);

    unsigned int packetLength =
        static_cast<unsigned int>(accountNameByteLength + 2);

    int passwordByteLength = WideCharToMultiByte(
        0, 0, password, passwordLength, converted, 0x100, NULL, NULL);
    if (passwordByteLength >= 0x100) {
        __report_rangecheckfailure();
    }
    converted[passwordByteLength] = 0;
    PacketBufferWriteUInt8(passwordByteLength, packet + packetLength);
    memmove(packet + packetLength + 1, converted, passwordByteLength);
    packetLength += static_cast<unsigned int>(passwordByteLength + 1);

    int profileTextByteLength = WideCharToMultiByte(
        0, 0, profileText, profileTextLength, converted, 0x100, NULL, NULL);
    if (profileTextByteLength >= 0x100) {
        __report_rangecheckfailure();
    }
    converted[profileTextByteLength] = 0;
    PacketBufferWriteUInt8(profileTextByteLength, packet + packetLength);
    memmove(packet + packetLength + 1, converted, profileTextByteLength);
    packetLength += static_cast<unsigned int>(profileTextByteLength + 1);

    if (packetLength >= 0x100) {
        __report_rangecheckfailure();
    }

    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(
        packet, static_cast<short>(packetLength + 1));
}

// UID:00009D | by-class/NewUserDialogPane.md | Completion:92 | Confidence:94
class Event;

class NewUserDialogPane : public DialogPane
{
public:
    NewUserDialogPane();
    virtual ~NewUserDialogPane();

protected:
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateCreateUserButtonEnabledState();

private:
    void SubmitCreateUser();
    bool HandleCreateUserReply(const unsigned char *packet);
};

// UID:0004PB | by-memory/0x004f9d30-0x004fa0a9.NewUserDialogPaneConstructor.md | Completion:91 | Confidence:93
NewUserDialogPane::NewUserDialogPane()
    : DialogPane(g_pLanguageMan->GetLocalizedString(89), static_cast<unsigned short>(-1), true)
{
    RectBounds bounds;

    g_pNewUserDialogPane = this;

    InitRectBounds(&bounds, 0, 0, 316, 202);
    AddControl(new EPFImageControlPane(L"DLGNEW01.EPF", 0, 1, &bounds, NULL));

    InitRectBounds(&bounds, 82, 138, 154, 154);
    AddControl(new ImageButtonControlPane(14, &bounds));

    InitRectBounds(&bounds, 159, 138, 231, 154);
    AddControl(new ImageButtonControlPane(22, &bounds));

    InitRectBounds(&bounds, 134, 48, 253, 60);
    AddControl(new TextEditControlPane(L"", true, 128, 143, &bounds,
                                       false, false, false, false, 1.0f, 0));

    InitRectBounds(&bounds, 134, 65, 253, 77);
    TextEditControlPane *passwordControl =
        new TextEditControlPane(L"", true, 128, 143, &bounds,
                                false, false, false, false, 1.0f, 0);
    AddControl(passwordControl);
    passwordControl->EnableMaskedText();

    InitRectBounds(&bounds, 134, 82, 253, 94);
    TextEditControlPane *confirmationControl =
        new TextEditControlPane(L"", true, 128, 143, &bounds,
                                false, false, false, false, 1.0f, 0);
    AddControl(confirmationControl);
    confirmationControl->EnableMaskedText();

    SetHoverControl(3);
    SetFocusedControl(1);
    SetPendingControl(2);
    SetBackgroundResource(L"DLGNEW01.EPF", NULL);
    SetMode(1);

    InitRectBounds(&bounds, 324, 191, 640, 393);
    OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pMainMenuPane);
    SlideOpenVertical();
}

// UID:0004PO | by-memory/0x00502970-0x005029e1.NewUserDialogPaneDestructor.md | Completion:92 | Confidence:94
NewUserDialogPane::~NewUserDialogPane()
{
    if (g_pScreenDimmer != NULL) {
        delete g_pScreenDimmer;
    }

    g_pNewUserDialogPane = NULL;
}

// UID:0004PD | by-memory/0x004fa0f0-0x004fa116.NewUserDialogPaneHandlePacketEvent.md | Completion:90 | Confidence:93
bool NewUserDialogPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);
    if (packet[0] != 2) {
        return false;
    }

    return HandleCreateUserReply(packet);
}

// UID:0004PE | by-memory/0x004fa120-0x004fa14e.NewUserDialogPaneOnControlCommand.md | Completion:91 | Confidence:93
void NewUserDialogPane::OnControlCommand(int controlIndex, int notifyCode)
{
    (void)notifyCode;

    if (controlIndex == 1) {
        SubmitCreateUser();
    } else if (controlIndex == 2) {
        SlideCloseVertical();
        CloseDialog();
    }
}

// UID:0004PF | by-memory/0x004fa150-0x004fa1c9.NewUserDialogPaneUpdateCreateUserButtonEnabledState.md | Completion:91 | Confidence:93
void NewUserDialogPane::UpdateCreateUserButtonEnabledState()
{
    ImageButtonControlPane *createButton = GetChild<ImageButtonControlPane>(1);

    if (GetChild<TextEditControlPane>(3)->IsEmpty() ||
        GetChild<TextEditControlPane>(4)->IsEmpty() ||
        GetChild<TextEditControlPane>(5)->IsEmpty()) {
        createButton->Disable();
    } else {
        createButton->Enable();
    }
}

// UID:0004PG | by-memory/0x004fa1d0-0x004fa39c.NewUserDialogPaneSubmitCreateUser.md | Completion:92 | Confidence:94
void NewUserDialogPane::SubmitCreateUser()
{
    wchar_t accountName[16];
    wchar_t password[16];
    wchar_t passwordConfirmation[16];

    GetChild<TextEditControlPane>(3)->ReadText(accountName, 15);
    GetChild<TextEditControlPane>(4)->ReadText(password, 15);
    GetChild<TextEditControlPane>(5)->ReadText(passwordConfirmation, 15);

    bool containsDigit = false;
    for (const wchar_t *cursor = password; *cursor != L'\0'; ++cursor) {
        if (*cursor >= L'0' && *cursor <= L'9') {
            containsDigit = true;
            break;
        }
    }

    if (!containsDigit) {
        SetHoverControl(4);
        new AlertPane(L"password must containt at least 1 number",
                      this,
                      kDialogOkButtonText,
                      NULL);
        return;
    }

    if (wcscmp(password, passwordConfirmation) != 0) {
        SetHoverControl(4);
        new AlertPane(g_pLanguageMan->GetLocalizedString(90),
                      this,
                      kDialogOkButtonText,
                      NULL);
        return;
    }

    new ScreenDimmer(5, g_pScreenPane);
    SendCreateAccountRequest(accountName, password, L"");
}

// UID:0004PI | by-memory/0x004fa5b0-0x004fa773.NewUserDialogPaneHandleCreateUserReply.md | Completion:92 | Confidence:94
bool NewUserDialogPane::HandleCreateUserReply(const unsigned char *packet)
{
    const unsigned char result = packet[1];

    if (result != 0) {
        if (g_pScreenDimmer != NULL) {
            delete g_pScreenDimmer;

            switch (result) {
            case 3:
            case 4:
            case 14:
            case 16:
            case 17:
            case 18:
            case 20:
            case 21:
                SetHoverControl(3);
                break;

            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 15:
                SetHoverControl(4);
                break;

            default:
                break;
            }

            char narrowText[256];
            wchar_t wideText[256];
            const unsigned int textLength = packet[2];

            memmove(narrowText, packet + 3, textLength);
            narrowText[textLength] = '\0';

            const unsigned char wideLength = static_cast<unsigned char>(
                MultiByteToWideChar(
                    CP_ACP, 0, narrowText, textLength, wideText, 256));
            wideText[wideLength] = L'\0';
            if (wideText[0] != L'\0') {
                new AlertPane(wideText, this, kDialogOkButtonText, NULL);
            }
        }

        return true;
    }

    if (g_pScreenDimmer != NULL) {
        delete g_pScreenDimmer;
    }

    SlideCloseVertical();
    CloseDialog();

    wchar_t accountName[16];
    GetChild<TextEditControlPane>(3)->ReadText(accountName, 15);
    g_pConfig->SetLogData(accountName);

    new NewUserMiscDialogPane;
    return true;
}

// UID:0002X9 | by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md | Completion:88 | Confidence:90
NewUserDialogPane *g_pNewUserDialogPane;
