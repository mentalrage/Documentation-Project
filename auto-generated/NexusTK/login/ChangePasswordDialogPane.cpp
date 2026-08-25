// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000I3
// Source by-file doc: by-file/ChangePasswordDialogPane.md
// UID:00001L | by-class/ChangePasswordDialogPane.md | Completion:91 | Confidence:92
#include "ChangePasswordDialogPane.h"
#include "MainMenuPane.h"
#include "../app/Application.h"
#include "../app/StartupWindow.h"
#include "../localization/LanguageMan.h"
#include "../network/PacketBuffer.h"
#include "../network/Socket.h"
#include "../ui/MainUiGraph.h"
#include "../ui/controls/ButtonControlPane.h"
#include "../ui/controls/EPFImageControlPane.h"
#include "../ui/controls/TextEditControlPane.h"
#include "../ui/core/Event.h"
#include "../ui/core/RectBounds.h"
#include "../ui/core/ScreenDimmer.h"
#include "../ui/core/ScreenPane.h"
#include "../ui/dialogs/AlertPanes.h"

#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <windows.h>

static void __stdcall SendPasswordChangeRequest(
    const wchar_t *accountName,
    const wchar_t *currentPassword,
    const wchar_t *newPassword);

// UID:0002QA | by-memory/0x004fdd40-0x004fe782.ChangePasswordDialogPaneCore.md | Completion:91 | Confidence:92
ChangePasswordDialogPane::ChangePasswordDialogPane()
    : DialogPane(L"", 0xffff, 4),
      Singleton<ChangePasswordDialogPane>()
{
    RectBounds bounds;

    if (g_useEpfAssets)
    {
        InitRectBounds(&bounds, 0, 0, 275, 232);
        AddControl(new EPFImageControlPane(
            L"DLGPASS.EPF", 0, true, &bounds, L"DLGPASS.PAL"));

        InitRectBounds(&bounds, 62, 197, 125, 221);
        AddControl(new ImageButtonControlPane(14, &bounds));

        InitRectBounds(&bounds, 150, 197, 213, 221);
        AddControl(new ImageButtonControlPane(22, &bounds));

        InitRectBounds(&bounds, 113, 30, 233, 42);
        AddControl(new TextEditControlPane(
            L"", true, 128, 143, &bounds,
            false, false, false, false, 1.0f, 0));

        InitRectBounds(&bounds, 113, 60, 233, 72);
        TextEditControlPane *currentPasswordEdit =
            new TextEditControlPane(
                L"", true, 128, 143, &bounds,
                false, false, false, false, 1.0f, 0);
        AddControl(currentPasswordEdit);
        currentPasswordEdit->EnableMaskedText();

        InitRectBounds(&bounds, 113, 90, 233, 102);
        TextEditControlPane *newPasswordEdit =
            new TextEditControlPane(
                L"", true, 128, 143, &bounds,
                false, false, false, false, 1.0f, 0);
        AddControl(newPasswordEdit);
        newPasswordEdit->EnableMaskedText();

        InitRectBounds(&bounds, 113, 120, 233, 132);
        TextEditControlPane *confirmationEdit =
            new TextEditControlPane(
                L"", true, 128, 143, &bounds,
                false, false, false, false, 1.0f, 0);
        AddControl(confirmationEdit);
        confirmationEdit->EnableMaskedText();

        SetHoverControl(3);
        SetFocusedControl(1);
        SetPendingControl(2);
        SetBackgroundResource(L"DLGPASS.EPF", 0);
        SetMode(4);

        const int left = (g_screenWidth - 275) / 2;
        const int top = (g_screenHeight - 232) / 2;
        InitRectBounds(&bounds, left, top, left + 275, top + 232);
    }
    else
    {
        InitRectBounds(&bounds, 0, 0, 314, 227);
        AddControl(new EPFImageControlPane(
            L"DLGPASS.EPD", 0, true, &bounds, L"NPAL8.PAL"));

        InitRectBounds(&bounds, 83, 177, 155, 193);
        AddControl(new ImageButtonControlPane(14, &bounds));

        InitRectBounds(&bounds, 160, 177, 232, 193);
        AddControl(new ImageButtonControlPane(22, &bounds));

        InitRectBounds(&bounds, 154, 72, 252, 85);
        AddControl(new TextEditControlPane(
            L"", true, 128, 143, &bounds,
            false, false, false, false, 1.0f, 0));

        InitRectBounds(&bounds, 154, 92, 252, 105);
        TextEditControlPane *currentPasswordEdit =
            new TextEditControlPane(
                L"", true, 128, 143, &bounds,
                false, false, false, false, 1.0f, 0);
        AddControl(currentPasswordEdit);
        currentPasswordEdit->EnableMaskedText();

        InitRectBounds(&bounds, 154, 112, 252, 125);
        TextEditControlPane *newPasswordEdit =
            new TextEditControlPane(
                L"", true, 128, 143, &bounds,
                false, false, false, false, 1.0f, 0);
        AddControl(newPasswordEdit);
        newPasswordEdit->EnableMaskedText();

        InitRectBounds(&bounds, 154, 132, 252, 145);
        TextEditControlPane *confirmationEdit =
            new TextEditControlPane(
                L"", true, 128, 143, &bounds,
                false, false, false, false, 1.0f, 0);
        AddControl(confirmationEdit);
        confirmationEdit->EnableMaskedText();

        SetHoverControl(3);
        SetFocusedControl(1);
        SetPendingControl(2);
        SetBackgroundResource(L"DLGPASS.EPD", 0);
        SetMode(4);

        InitRectBounds(&bounds, 326, 191, 640, 418);
    }

    OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pMainMenuPane);
    SlideOpenVertical();
}

void ChangePasswordDialogPane::OnControlCommand(
    int controlIndex,
    int notifyCode)
{
    (void)notifyCode;

    if (controlIndex == 1)
    {
        SubmitPasswordChange();
    }
    else if (controlIndex == 2)
    {
        SlideCloseVertical();
        CloseDialog();
    }
}

void ChangePasswordDialogPane::UpdateActionButton()
{
    ImageButtonControlPane *actionButton =
        GetChild<ImageButtonControlPane>(1);

    if (GetChild<TextEditControlPane>(3)->IsEmpty() ||
        GetChild<TextEditControlPane>(4)->IsEmpty() ||
        GetChild<TextEditControlPane>(5)->IsEmpty() ||
        GetChild<TextEditControlPane>(6)->IsEmpty())
    {
        actionButton->Disable();
    }
    else
    {
        actionButton->Enable();
    }
}

bool ChangePasswordDialogPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);
    if (packet[0] != 2)
        return false;

    return HandlePasswordChangeReply(packet);
}

void ChangePasswordDialogPane::SubmitPasswordChange()
{
    wchar_t accountName[16];
    wchar_t currentPassword[16];
    wchar_t newPassword[16];
    wchar_t passwordConfirmation[16];

    GetChild<TextEditControlPane>(3)->ReadText(accountName, 15);
    GetChild<TextEditControlPane>(4)->ReadText(currentPassword, 15);
    GetChild<TextEditControlPane>(5)->ReadText(newPassword, 15);
    GetChild<TextEditControlPane>(6)->ReadText(passwordConfirmation, 15);

    bool containsDigit = false;
    for (const wchar_t *cursor = newPassword; *cursor != L'\0'; ++cursor)
    {
        if (*cursor >= L'0' && *cursor <= L'9')
        {
            containsDigit = true;
            break;
        }
    }

    if (!containsDigit)
    {
        SetHoverControl(5);
        new AlertPane(
            L"password must containt at least 1 number",
            this,
            L"OK",
            NULL);
        return;
    }

    if (wcscmp(newPassword, passwordConfirmation) != 0)
    {
        SetHoverControl(5);
        new AlertPane(
            g_pLanguageMan->GetLocalizedString(90),
            this,
            L"OK",
            NULL);
        return;
    }

    new ScreenDimmer(5, g_pScreenPane);
    SendPasswordChangeRequest(accountName, currentPassword, newPassword);
}

// UID:0002QB | by-memory/0x004fe790-0x004fe9d1.RawPasswordChangePacketWithAccount.md | Completion:90 | Confidence:90
static void __stdcall SendPasswordChangeRequestWithAccountId(
    const wchar_t* accountName,
    const wchar_t* currentPassword,
    const wchar_t* newPassword,
    const wchar_t* accountIdText)
{
    char packet[0x100];
    char converted[0x100];

    short accountNameLength = static_cast<short>(wcslen(accountName));
    short currentPasswordLength = static_cast<short>(wcslen(currentPassword));
    short newPasswordLength = static_cast<short>(wcslen(newPassword));
    long accountId = _wtol(accountIdText);

    PacketBufferWriteUInt8(0x26, packet);

    int accountNameByteLength = WideCharToMultiByte(0, 0, accountName, accountNameLength, converted, 0x100, NULL, NULL);
    if (accountNameByteLength >= 0x100)
        __report_rangecheckfailure();
    converted[accountNameByteLength] = 0;
    PacketBufferWriteUInt8(accountNameByteLength, packet + 1);
    memmove(packet + 2, converted, accountNameByteLength);

    unsigned int packetLength = static_cast<unsigned int>(accountNameByteLength + 2);

    int currentPasswordByteLength = WideCharToMultiByte(0, 0, currentPassword, currentPasswordLength, converted, 0x100, NULL, NULL);
    if (currentPasswordByteLength >= 0x100)
        __report_rangecheckfailure();
    converted[currentPasswordByteLength] = 0;
    PacketBufferWriteUInt8(currentPasswordByteLength, packet + packetLength);
    memmove(packet + packetLength + 1, converted, currentPasswordByteLength);
    packetLength += static_cast<unsigned int>(currentPasswordByteLength + 1);

    int newPasswordByteLength = WideCharToMultiByte(0, 0, newPassword, newPasswordLength, converted, 0x100, NULL, NULL);
    if (newPasswordByteLength >= 0x100)
        __report_rangecheckfailure();
    converted[newPasswordByteLength] = 0;
    PacketBufferWriteUInt8(newPasswordByteLength, packet + packetLength);
    memmove(packet + packetLength + 1, converted, newPasswordByteLength);
    packetLength += static_cast<unsigned int>(newPasswordByteLength + 1);

    PacketBufferWriteUInt32BE(accountId, packet + packetLength);
    packetLength += 4;
    if (packetLength >= 0x100)
        __report_rangecheckfailure();

    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(
        packet, static_cast<short>(packetLength));
}

// UID:0002QC | by-memory/0x004fe9e0-0x004febe2.SendPasswordChangeRequest.md | Completion:91 | Confidence:91
static void __stdcall SendPasswordChangeRequest(
    const wchar_t* accountName,
    const wchar_t* currentPassword,
    const wchar_t* newPassword)
{
    char packet[0x100];
    char converted[0x100];

    short accountNameLength = static_cast<short>(wcslen(accountName));
    short currentPasswordLength = static_cast<short>(wcslen(currentPassword));
    short newPasswordLength = static_cast<short>(wcslen(newPassword));

    PacketBufferWriteUInt8(0x26, packet);

    int accountNameByteLength = WideCharToMultiByte(0, 0, accountName, accountNameLength, converted, 0x100, NULL, NULL);
    if (accountNameByteLength >= 0x100)
        __report_rangecheckfailure();
    converted[accountNameByteLength] = 0;
    PacketBufferWriteUInt8(accountNameByteLength, packet + 1);
    memmove(packet + 2, converted, accountNameByteLength);

    unsigned int packetLength = static_cast<unsigned int>(accountNameByteLength + 2);

    int currentPasswordByteLength = WideCharToMultiByte(0, 0, currentPassword, currentPasswordLength, converted, 0x100, NULL, NULL);
    if (currentPasswordByteLength >= 0x100)
        __report_rangecheckfailure();
    converted[currentPasswordByteLength] = 0;
    PacketBufferWriteUInt8(currentPasswordByteLength, packet + packetLength);
    memmove(packet + packetLength + 1, converted, currentPasswordByteLength);
    packetLength += static_cast<unsigned int>(currentPasswordByteLength + 1);

    int newPasswordByteLength = WideCharToMultiByte(0, 0, newPassword, newPasswordLength, converted, 0x100, NULL, NULL);
    if (newPasswordByteLength >= 0x100)
        __report_rangecheckfailure();
    converted[newPasswordByteLength] = 0;
    PacketBufferWriteUInt8(newPasswordByteLength, packet + packetLength);
    memmove(packet + packetLength + 1, converted, newPasswordByteLength);
    packetLength += static_cast<unsigned int>(newPasswordByteLength + 1);
    if (packetLength >= 0x100)
        __report_rangecheckfailure();

    packet[packetLength] = 0;
    g_packetSender->QueueAndSendPacket(
        packet, static_cast<short>(packetLength));
}

// UID:0002QD | by-memory/0x004febf0-0x004fee11.HandlePasswordChangeReply.md | Completion:91 | Confidence:92
namespace
{
bool IsPasswordChangeAccountNameReplyError(unsigned char result)
{
    switch (result) {
    case 3:
    case 4:
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

bool IsPasswordChangeCurrentPasswordReplyError(unsigned char result)
{
    return result == 15;
}

bool IsPasswordChangeNewPasswordReplyError(unsigned char result)
{
    switch (result) {
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        return true;

    default:
        return false;
    }
}

}

bool ChangePasswordDialogPane::HandlePasswordChangeReply(const unsigned char *packet)
{
    if (g_pScreenDimmer != NULL) {
        delete g_pScreenDimmer;
    }

    const unsigned char result = packet[1];
    const unsigned char messageLength = packet[2];
    char narrowMessage[0x100];
    wchar_t message[0x100];

    memmove(narrowMessage, packet + 3, messageLength);
    narrowMessage[messageLength] = 0;
    const int wideLength = MultiByteToWideChar(
        CP_ACP, 0, narrowMessage, messageLength, message, 0x100);
    if (wideLength >= 0x100)
        __report_rangecheckfailure();
    message[static_cast<unsigned char>(wideLength)] = L'\0';

    if (result != 0) {
        if (IsPasswordChangeAccountNameReplyError(result)) {
            SetHoverControl(3);
        } else if (IsPasswordChangeCurrentPasswordReplyError(result)) {
            SetHoverControl(4);
        } else if (IsPasswordChangeNewPasswordReplyError(result)) {
            SetHoverControl(5);
        }

        if (message[0] != L'\0')
            new AlertPane(message, this, L"OK", NULL);
        return true;
    }

    if (message[0] != L'\0')
        new AlertPane(message, this, L"OK", NULL);
    SlideCloseVertical();
    CloseDialog();
    return true;
}

// UID:0002QE | by-memory/0x004fee40-0x004ff03f.HandlePasswordChangeReplySimple.md | Completion:90 | Confidence:91
namespace
{
bool IsPasswordChangeSimpleNewPasswordReplyError(unsigned char result)
{
    return result >= 3 && result <= 8;
}
}

bool ChangePasswordDialogPane::HandlePasswordChangeReplySimple(const unsigned char *packet)
{
    if (g_pScreenDimmer != NULL) {
        delete g_pScreenDimmer;
    }

    const unsigned char result = packet[1];
    const unsigned char messageLength = packet[2];
    char narrowMessage[0x100];
    wchar_t message[0x100];

    memmove(narrowMessage, packet + 3, messageLength);
    narrowMessage[messageLength] = 0;
    const int wideLength = MultiByteToWideChar(
        CP_ACP, 0, narrowMessage, messageLength, message, 0x100);
    message[static_cast<unsigned char>(wideLength)] = L'\0';

    if (result != 0) {
        if (IsPasswordChangeSimpleNewPasswordReplyError(result)) {
            SetHoverControl(5);
        }

        if (message[0] != L'\0')
            new AlertPane(message, this, L"OK", NULL);
        return true;
    }

    if (message[0] != L'\0')
        new AlertPane(message, this, L"OK", NULL);
    SlideCloseVertical();
    CloseDialog();
    return true;
}

// UID:0002XM | by-memory/0x0069b48c-0x0069b490.g_pChangePasswordDialogPane.md | Completion:91 | Confidence:92
ChangePasswordDialogPane *g_pChangePasswordDialogPane = NULL;
