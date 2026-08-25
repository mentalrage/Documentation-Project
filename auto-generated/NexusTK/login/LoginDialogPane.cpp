// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KX
// Source by-file doc: by-file/LoginDialogPane.md
// UID:0000RE | by-global/g_pLoginDialogPane.md | Completion:92 | Confidence:94
// UID:0002XI | by-memory/0x0069b484-0x0069b488.g_pLoginDialogPane.md | Completion:93 | Confidence:94
class LoginDialogPane;

LoginDialogPane *g_pLoginDialogPane = NULL;

// UID:00007F | by-class/LoginDialogPane.md | Completion:92 | Confidence:94
class LoginDialogPane : public DialogPane
{
public:
    LoginDialogPane();
    virtual ~LoginDialogPane();

    virtual void OnControlCommand(int commandId, int notifyCode);
    virtual void UpdateActionButton();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
};

// UID:0004PJ | by-memory/0x004fa7a0-0x004faacd.LoginDialogPaneConstructor.md | Completion:92 | Confidence:94
LoginDialogPane::LoginDialogPane()
    : DialogPane(g_pLanguageMan->GetLocalizedString(91), 0xffff, 1)
{
    RectBounds bounds;

    g_pLoginDialogPane = this;

    InitRectBounds(&bounds, 0, 0, 241, 124);
    AddControl(new EPFImageControlPane(
        L"DLGLOGIN.EPF", 0, 1, &bounds, L"DLGLOGIN.PAL"));

    InitRectBounds(&bounds, 51, 85, 114, 109);
    AddControl(new ImageButtonControlPane(14, &bounds));

    InitRectBounds(&bounds, 135, 85, 198, 109);
    AddControl(new ImageButtonControlPane(22, &bounds));

    InitRectBounds(&bounds, 80, 23, 208, 35);
    TextEditControlPane *accountEdit = new TextEditControlPane(
        L"", true, 128, 128, &bounds,
        false, false, false, false, 1.0f, 0);
    AddControl(accountEdit);
    if (g_pConfig->m_logDataText != NULL)
        accountEdit->SetText(g_pConfig->m_logDataText);

    InitRectBounds(&bounds, 80, 53, 208, 65);
    TextEditControlPane *passwordEdit = new TextEditControlPane(
        L"", true, 128, 128, &bounds,
        false, false, false, false, 1.0f, 0);
    AddControl(passwordEdit);
    passwordEdit->SetMaxLength(8);
    passwordEdit->EnableMaskedText();

    SetHoverControl(3);
    SetFocusedControl(1);
    SetPendingControl(2);
    SetBackgroundResource(L"DLGLOGIN.EPF", NULL);
    SetMode(1);

    const int left = (g_screenWidth - 241) / 2;
    const int top = (g_screenHeight - 124) / 2;
    InitRectBounds(&bounds, left, top, left + 241, top + 124);
    OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pMainMenuPane);
    SlideOpenVertical();
}

// UID:0004PN | by-memory/0x004faad0-0x004fab0f.LoginDialogPaneConstructorUnwindCleanup.md | Completion:92 | Confidence:94
// Compiler-emitted constructor-unwind cleanup for this range is covered by
// [UID:0004PJ][0x004fa7a0-0x004faacd.LoginDialogPaneConstructor](by-memory/0x004fa7a0-0x004faacd.LoginDialogPaneConstructor.md) and [UID:0004PU][0x005027d0-0x00502841.LoginDialogPaneDestructor](by-memory/0x005027d0-0x00502841.LoginDialogPaneDestructor.md).

// UID:0004PQ | by-memory/0x004fab10-0x004face9.LoginDialogPaneHandlePacketEvent.md | Completion:92 | Confidence:94
namespace
{
const unsigned char kLoginReplyPacketType = 2;

bool IsLoginAccountNameReplyError(unsigned char result)
{
    switch (result) {
    case 14:
    case 16:
    case 17:
    case 18:
    case 20:
    case 21:
        return true;

    default:
        return false;
    }
}

bool IsLoginPasswordReplyError(unsigned char result)
{
    return result == 15;
}
}

bool LoginDialogPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);
    if (packet[0] != kLoginReplyPacketType)
        return false;

    const unsigned char result = packet[1];
    if (result != 0) {
        if (g_pScreenDimmer != NULL)
            delete g_pScreenDimmer;

        if (IsLoginAccountNameReplyError(result))
            SetHoverControl(3);
        else if (IsLoginPasswordReplyError(result))
            SetHoverControl(4);

        char narrowText[256];
        wchar_t wideText[256];
        const unsigned int textLength = packet[2];
        memmove(narrowText, packet + 3, textLength);
        narrowText[textLength] = '\0';

        const int wideLength = MultiByteToWideChar(
            CP_ACP, 0, narrowText, textLength, wideText, 256);
        wideText[wideLength] = L'\0';
        if (wideText[0] != L'\0')
            new AlertPane(wideText, this, kDialogOkButtonText, NULL);

        return true;
    }

    SlideCloseVertical();
    CloseDialog();
    g_pMainMenuPane->InitializeMainUiGraph();

    wchar_t accountName[16];
    GetChild<TextEditControlPane>(3)->ReadText(accountName, 15);
    g_pConfig->SetLogData(accountName);
    return true;
}

// UID:0004PR | by-memory/0x004fad00-0x004fae22.LoginDialogPaneOnControlCommand.md | Completion:92 | Confidence:94
namespace
{
enum LoginDialogCommand
{
    kLoginDialogSubmit = 1,
    kLoginDialogCancel = 2
};

const int kLoginScreenDimmerLevel = 5;
}

void LoginDialogPane::OnControlCommand(int commandId, int notifyCode)
{
    (void)notifyCode;

    switch (commandId) {
    case kLoginDialogSubmit:
    {
        wchar_t accountName[16];
        wchar_t password[16];
        GetChild<TextEditControlPane>(3)->ReadText(accountName, 15);
        GetChild<TextEditControlPane>(4)->ReadText(password, 15);

        const wchar_t *accountArgument = accountName;
        const wchar_t *passwordArgument = password;
        if (g_pConfig->m_systemHelperFlags != 0) {
            if (rand() < 3276)
                ++accountArgument;
            if (rand() < 3276)
                ++passwordArgument;
        }

        SendLoginRequest(accountArgument, passwordArgument);
        wcscpy_s(g_pMainMenuPane->m_serverName, 128, accountName);
        new ScreenDimmer(kLoginScreenDimmerLevel, g_pScreenPane);
        break;
    }

    case kLoginDialogCancel:
        CloseDialog();
        break;
    }
}

// UID:0004PS | by-memory/0x004fae30-0x004fae88.LoginDialogPaneUpdateActionButton.md | Completion:92 | Confidence:94
void LoginDialogPane::UpdateActionButton()
{
    ImageButtonControlPane *actionButton =
        GetChild<ImageButtonControlPane>(1);
    if (GetChild<TextEditControlPane>(3)->IsEmpty() ||
        GetChild<TextEditControlPane>(4)->IsEmpty()) {
        actionButton->Disable();
    } else {
        actionButton->Enable();
    }
}

// UID:0004PT | by-memory/0x004fae90-0x004fb2a6.LoginDialogPaneHandlePointerOrMouseEvent.md | Completion:91 | Confidence:93
bool LoginDialogPane::HandlePointerOrMouseEvent(Event *event)
{
    int &mouseY = event->m_payload.m_pointer.m_y;
    int &mouseX = event->m_payload.m_pointer.m_x;
    const int originalY = mouseY;
    const int originalX = mouseX;

    switch (event->m_type) {
    case kEventCursorMove:
        if (m_isTitleDragActive) {
            m_origin.x += mouseX - m_dragOriginX;
            m_origin.y += mouseY - m_dragOriginY;

            if (m_clampDragToBounds) {
                if (m_origin.x < m_dragClampMinX)
                    m_origin.x = m_dragClampMinX;
                if (m_origin.y < m_dragClampMinY)
                    m_origin.y = m_dragClampMinY;

                const int maximumX = m_dragClampMaxX - m_bounds.right;
                const int maximumY = m_dragClampMaxY - m_bounds.bottom;
                if (m_origin.x > maximumX)
                    m_origin.x = maximumX;
                if (m_origin.y > maximumY)
                    m_origin.y = maximumY;
            }
        } else {
            int controlId;
            const char hitType = HitTestControls(mouseY, mouseX, &controlId);
            if (m_pressedControlActive) {
                if (controlId == m_pressedControlId &&
                    hitType == m_pressedHitType) {
                    SetSelectionVisualState(controlId, hitType);
                } else {
                    SetSelectionVisualState(-1, 10);
                }
                DispatchInputToControl(event, m_pressedControlId);
            }
        }
        break;

    case kEventLeftButtonDown:
    {
        int controlId;
        const char hitType = HitTestControls(mouseY, mouseX, &controlId);
        if (hitType != 10 && !m_pressedControlActive && hitType >= 0) {
            if (m_activeControlId != controlId)
                SetHoverControl(controlId);

            m_pressedControlActive = true;
            m_pressedControlId = controlId;
            m_pressedHitType = hitType;
            SetSelectionVisualState(controlId, hitType);
            DispatchInputToControl(event, controlId);
        } else if (hitType == 10 &&
                   !m_isTitleDragActive &&
                   PointInRect(mouseY, mouseX, &m_bounds)) {
            m_dragOriginY = mouseY;
            m_dragOriginX = mouseX;
            m_isTitleDragActive = true;
            m_savedPaneMode = m_mode;
            if (m_mode == 2)
                SetMode(0);
            else if (m_mode == 3)
                SetMode(1);
        }
        break;
    }

    case kEventLeftButtonDoubleClick:
    {
        int controlId;
        HitTestControls(mouseY, mouseX, &controlId);
        if (controlId != -1)
            DispatchInputToControl(event, controlId);
        break;
    }

    case kEventLeftButtonUp:
        if (m_isTitleDragActive) {
            SetMode(m_savedPaneMode);
            if (m_dialogConfigId != 0xffff)
                SavePosition();
            m_isTitleDragActive = false;
        }

        if (m_pressedControlActive) {
            const int pressedControlId = m_pressedControlId;
            const char pressedHitType = m_pressedHitType;
            m_pressedControlActive = false;
            SetSelectionVisualState(-1, 10);
            DispatchInputToControl(event, pressedControlId);
            g_pScreenPane->RenderPresentation();

            int controlId;
            const char hitType = HitTestControls(originalY, originalX, &controlId);
            if (controlId == pressedControlId && hitType == pressedHitType) {
                OnControlCommand(controlId, hitType);
                RedrawSelectedControl();
            }
        }
        break;

    case kEventMouseWheel:
        if (PointInRect(mouseY, mouseX, &m_bounds)) {
            int controlId;
            HitTestControls(mouseY, mouseX, &controlId);
            if (controlId >= 0)
                DispatchInputToControl(event, controlId);
        }
        break;
    }

    if (g_useEpfAssets == 1 &&
        !PointInRect(originalY, originalX, &m_bounds)) {
        RectBounds dialogBounds;
        GetScreenBounds(&dialogBounds);
        mouseX += dialogBounds.left;
        mouseY += dialogBounds.top;

        RectBounds mainMenuBounds;
        g_pMainMenuPane->GetScreenBounds(&mainMenuBounds);
        if (PointInRect(mouseY, mouseX, &mainMenuBounds)) {
            mouseX -= mainMenuBounds.left;
            mouseY -= mainMenuBounds.top;
            g_pMainMenuPane->HandlePointerOrMouseEvent(event);
        }
    }

    return true;
}

// UID:0004PU | by-memory/0x005027d0-0x00502841.LoginDialogPaneDestructor.md | Completion:92 | Confidence:94
LoginDialogPane::~LoginDialogPane()
{
    if (g_pScreenDimmer != NULL)
        delete g_pScreenDimmer;
    g_pLoginDialogPane = NULL;
}

// UID:00019L | by-memory/0x004f8b30-0x004f8b8d.EnsureLoginDialogPane.md | Completion:88 | Confidence:90
static void EnsureLoginDialogPane()
{
    if (g_pLoginDialogPane == NULL) {
        new LoginDialogPane;
    }
}

// UID:0002Q5 | by-memory/0x004fb2d0-0x004fb62a.SendLoginRequest.md | Completion:90 | Confidence:92
#include "../auth/PasswordGuard.h"

static void __stdcall SendLoginRequest(const wchar_t* accountName, const wchar_t* password)
{
    char packet[0x100];
    char converted[0x100];
    unsigned char challenge[13];
    OSVERSIONINFOW versionInfo;
    RECT desktopRect;

    short accountNameLength = static_cast<short>(wcslen(accountName));
    short passwordLength = static_cast<short>(wcslen(password));

    PacketBufferWriteUInt8(0x03, packet);

    int accountNameByteLength = WideCharToMultiByte(0, 0, accountName, accountNameLength, converted, 0x100, NULL, NULL);
    if (accountNameByteLength >= 0x100)
        __report_rangecheckfailure();
    converted[accountNameByteLength] = 0;
    PacketBufferWriteUInt8(accountNameByteLength, packet + 1);
    memmove(packet + 2, converted, accountNameByteLength);

    int passwordByteLength = WideCharToMultiByte(0, 0, password, passwordLength, converted, 0x100, NULL, NULL);
    if (passwordByteLength >= 0x100)
        __report_rangecheckfailure();
    converted[passwordByteLength] = 0;
    PacketBufferWriteUInt8(passwordByteLength, packet + accountNameByteLength + 2);
    memmove(packet + accountNameByteLength + 3, converted, passwordByteLength);

    unsigned int packetLength = static_cast<unsigned int>(accountNameByteLength + passwordByteLength + 3);

    PacketBufferWriteUInt32BE(g_pConfig->m_loginChallengeKey, packet + packetLength);
    packetLength += 4;

    PacketBufferWriteUInt8(0, packet + packetLength);
    ++packetLength;

    versionInfo.dwOSVersionInfoSize = sizeof(versionInfo);
    GetVersionExW(&versionInfo);

    unsigned int osVersion =
        static_cast<unsigned char>(versionInfo.dwMinorVersion) |
        (static_cast<unsigned char>(versionInfo.dwMajorVersion) << 8) |
        (static_cast<unsigned char>(versionInfo.dwPlatformId) << 16);
    PacketBufferWriteUInt32BE(osVersion, packet + packetLength);
    packetLength += 4;

    GetWindowRect(GetDesktopWindow(), &desktopRect);
    PacketBufferWriteUInt8(g_applicationActiveGate == 0, packet + packetLength);
    ++packetLength;

    PacketBufferWriteUInt16BE(static_cast<unsigned short>(desktopRect.right), packet + packetLength);
    packetLength += 2;
    PacketBufferWriteUInt16BE(static_cast<unsigned short>(desktopRect.bottom), packet + packetLength);
    packetLength += 2;

    for (int i = 0; i < 13; ++i)
        challenge[i] = static_cast<unsigned char>(rand());

    memmove(packet + packetLength, challenge, 13);
    packetLength += 13;

    const unsigned char* challengeMask = g_pConfig->m_loginChallengeMask;
    PacketBufferWriteUInt8(challenge[8] ^ challengeMask[4], packet + packetLength);
    ++packetLength;
    PacketBufferWriteUInt8(challenge[4] ^ challengeMask[1], packet + packetLength);
    ++packetLength;
    PacketBufferWriteUInt8(challenge[7] ^ challengeMask[6], packet + packetLength);
    ++packetLength;
    PacketBufferWriteUInt8(challenge[11] ^ challengeMask[12], packet + packetLength);
    ++packetLength;
    PacketBufferWriteUInt8(challenge[3] ^ challengeMask[8], packet + packetLength);
    ++packetLength;
    PacketBufferWriteUInt8(challenge[1] ^ challengeMask[10], packet + packetLength);
    ++packetLength;
    PacketBufferWriteUInt8(challenge[9] ^ challengeMask[14], packet + packetLength);
    ++packetLength;
    PacketBufferWriteUInt8(challenge[2] ^ challengeMask[0], packet + packetLength);
    ++packetLength;

    if (packetLength >= 0x100)
        __report_rangecheckfailure();

    packet[packetLength] = 0;
    Sleep(rand() % 400 + 200);
    QueueAndSendPacket(g_packetSender, packet, packetLength);
    SetProtectedPasswordToken(password);
}
