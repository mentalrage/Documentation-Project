// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OY
// Source by-file doc: by-file/UserInfoDialogPane.md
// UID:0000FM | by-class/UserInfoDialogPane.md | Completion:95 | Confidence:94
#include "UserInfoDialogPane.h"

// UID:000574 | by-memory/0x0062e6c0-0x0062e8fc.UserInfoDialogPaneLiteralData.md | Completion:96 | Confidence:98
#include <string.h>
#include <windows.h>

#include "../map/BackPane.h"
#include "../network/Socket.h"
#include "../ui/MainUiGraph.h"
#include "../ui/controls/ButtonControlPane.h"
#include "../ui/controls/EPFImageControlPane.h"
#include "../ui/controls/TextEditControlPane.h"
#include "../ui/core/RectBounds.h"
#include "../ui/dialogs/AlertPanes.h"
#include "../ui/menu/PopupMenuControls.h"

namespace
{
const wchar_t kUserInfoTitle[] = L"User Information Dialog Pane";
const wchar_t kUserInfoNameError[] =
    L"\uC774\uB984\uC774 \uC798\uBABB \uC785\uB825\uB418\uC5C8\uC2B5\uB2C8\uB2E4.";
const wchar_t kUserInfoResidentIdError[] =
    L"\uC8FC\uBBFC\uB4F1\uB85D\uBC88\uD638\uAC00 \uC798\uBABB \uC785\uB825\uB418\uC5C8\uC2B5\uB2C8\uB2E4.";
const wchar_t kUserInfoParentNameError[] =
    L"\uBD80\uBAA8\uB2D8 \uC774\uB984\uC774 \uC798\uBABB \uC785\uB825\uB418\uC5C8\uC2B5\uB2C8\uB2E4.";
const wchar_t kUserInfoBloodTypeError[] =
    L"\uD608\uC561\uD615\uC744 \uC785\uB825\uD558\uC2ED\uC2DC\uC694.";
const wchar_t kUserInfoResidenceError[] =
    L"\uAC70\uC8FC\uC9C0\uB97C \uC785\uB825\uD558\uC2ED\uC2DC\uC694.";
const wchar_t kUserInfoAccessMethodError[] =
    L"\uC8FC\uB85C\uD558\uB294 \uBC29\uBC95\uC744 \uC785\uB825\uD558\uC2ED\uC2DC\uC694.";
const wchar_t kUserInfoDiscoveryReasonError[] =
    L"\uCC98\uC74C\uD558\uAC8C\uB41C \uB3D9\uAE30\uB97C \uC785\uB825\uD558\uC2ED\uC2DC\uC694.";
const wchar_t kUserInfoResource[] = L"USERINFO.EPF";

static __forceinline void ReadUserInfoField(
    const unsigned char *packet, int *offset, wchar_t *outText)
{
    char encoded[256];
    const unsigned char length = packet[(*offset)++];
    memcpy(encoded, packet + *offset, length);
    *offset += length;
    encoded[length] = 0;
    const int converted = MultiByteToWideChar(
        CP_ACP, 0, encoded, length, outText, 128);
    outText[converted] = 0;
}

static __forceinline void AppendMenuItem(
    PopupMenuControlPane *menu, const wchar_t *text)
{
    menu->AppendItem(new StringMenuItem(text));
}

static __forceinline void SelectMenuText(
    PopupMenuControlPane *menu, const wchar_t *text)
{
    menu->SetSelectedIndex(-1);
    wchar_t itemText[128];
    for (int index = 0; index < menu->GetItemCount(); ++index)
    {
        static_cast<StringMenuItem *>(menu->GetItem(index))->
            CopyText(itemText, 128);
        if (wcscmp(itemText, text) == 0)
        {
            menu->SetSelectedIndex(index);
            break;
        }
    }
}

static __forceinline int AppendUserInfoField(
    unsigned char *packet, int offset, const wchar_t *text)
{
    char encoded[256];
    const int length = WideCharToMultiByte(
        CP_ACP, 0, text, static_cast<unsigned char>(wcslen(text)),
        encoded, 256, NULL, NULL);
    encoded[length] = 0;
    packet[offset++] = static_cast<unsigned char>(length);
    memcpy(packet + offset, encoded, length);
    return offset + length;
}
}

// UID:00056U | by-memory/0x00599cc0-0x0059aff0.UserInfoDialogPaneConstructor.md | Completion:94 | Confidence:94
UserInfoDialogPane::UserInfoDialogPane(const unsigned char *packet)
    : DialogPane(kUserInfoTitle, 0xffff, 1)
{
    wcscpy_s(m_validationMessages[0], 128, kUserInfoNameError);
    wcscpy_s(m_validationMessages[1], 128, kUserInfoResidentIdError);
    wcscpy_s(m_validationMessages[2], 128, kUserInfoResidentIdError);
    wcscpy_s(m_validationMessages[3], 128, kUserInfoParentNameError);
    wcscpy_s(m_validationMessages[4], 128, kUserInfoBloodTypeError);
    wcscpy_s(m_validationMessages[5], 128, kUserInfoResidenceError);
    wcscpy_s(m_validationMessages[6], 128, kUserInfoAccessMethodError);
    wcscpy_s(m_validationMessages[7], 128, kUserInfoDiscoveryReasonError);

    RectBounds bounds = { 0, 0, 427, 357 };
    AddControl(new EPFImageControlPane(
        kUserInfoResource, 0, 1, &bounds, NULL));
    bounds.SetLTRB(137, 295, 209, 311);
    AddControl(new ImageButtonControlPane(14, &bounds));
    bounds.SetLTRB(214, 295, 286, 311);
    AddControl(new ImageButtonControlPane(22, &bounds));

    int packetOffset = 1;
    wchar_t fieldText[128];
    if (packet[0] == 2)
        ReadUserInfoField(packet, &packetOffset, fieldText);
    else
        fieldText[0] = 0;

    bounds.SetLTRB(195, 127, 287, 143);
    TextEditControlPane *nameEdit = new TextEditControlPane(
        fieldText, true, 128, 143, &bounds,
        false, false, false, false, 1.0f, false);
    AddControl(nameEdit);
    nameEdit->SetMaxLength(8);

    if (packet[0] == 2)
        ReadUserInfoField(packet, &packetOffset, fieldText);
    else
        fieldText[0] = 0;
    bounds.SetLTRB(195, 149, 232, 165);
    TextEditControlPane *residentPrefixEdit = new TextEditControlPane(
        fieldText, true, 128, 143, &bounds,
        false, false, false, false, 1.0f, false);
    AddControl(residentPrefixEdit);
    residentPrefixEdit->SetMaxLength(6);

    if (packet[0] == 2)
        ReadUserInfoField(packet, &packetOffset, fieldText);
    else
        fieldText[0] = 0;
    bounds.SetLTRB(247, 148, 290, 164);
    TextEditControlPane *residentSuffixEdit = new TextEditControlPane(
        fieldText, true, 128, 143, &bounds,
        false, false, false, false, 1.0f, false);
    AddControl(residentSuffixEdit);
    residentSuffixEdit->SetMaxLength(7);

    if (packet[0] == 2)
        ReadUserInfoField(packet, &packetOffset, fieldText);
    else
        fieldText[0] = 0;
    bounds.SetLTRB(195, 169, 287, 185);
    TextEditControlPane *parentNameEdit = new TextEditControlPane(
        fieldText, true, 128, 143, &bounds,
        false, false, false, false, 1.0f, false);
    AddControl(parentNameEdit);
    parentNameEdit->SetMaxLength(8);

    bounds.SetLTRB(195, 189, 275, 205);
    PopupMenuControlPane *bloodMenu =
        new PopupMenuControlPane(this, &bounds);
    AppendMenuItem(bloodMenu, L"A");
    AppendMenuItem(bloodMenu, L"B");
    AppendMenuItem(bloodMenu, L"AB");
    AppendMenuItem(bloodMenu, L"O");
    if (packet[0] == 2)
    {
        ReadUserInfoField(packet, &packetOffset, fieldText);
        SelectMenuText(bloodMenu, fieldText);
    }
    else
        bloodMenu->SetSelectedIndex(-1);
    AddControl(bloodMenu);

    bounds.SetLTRB(195, 210, 275, 226);
    PopupMenuControlPane *residenceMenu =
        new PopupMenuControlPane(this, &bounds);
    AppendMenuItem(residenceMenu, L"\uC11C\uC6B8\uC2DC");
    AppendMenuItem(residenceMenu, L"\uAD11\uC8FC\uC2DC");
    AppendMenuItem(residenceMenu, L"\uB300\uAD6C\uC2DC");
    AppendMenuItem(residenceMenu, L"\uB300\uC804\uC2DC");
    AppendMenuItem(residenceMenu, L"\uBD80\uC0B0\uC2DC");
    AppendMenuItem(residenceMenu, L"\uC6B8\uC0B0\uC2DC");
    AppendMenuItem(residenceMenu, L"\uC778\uCC9C\uC2DC");
    AppendMenuItem(residenceMenu, L"\uAC15\uC6D0\uB3C4");
    AppendMenuItem(residenceMenu, L"\uACBD\uAE30\uB3C4");
    AppendMenuItem(residenceMenu, L"\uACBD\uC0C1\uB3C4");
    AppendMenuItem(residenceMenu, L"\uC804\uB77C\uB3C4");
    AppendMenuItem(residenceMenu, L"\uC81C\uC8FC\uB3C4");
    AppendMenuItem(residenceMenu, L"\uCDA9\uCCAD\uB3C4");
    AppendMenuItem(residenceMenu, L"\uD574\uC678");
    if (packet[0] == 2)
    {
        ReadUserInfoField(packet, &packetOffset, fieldText);
        SelectMenuText(residenceMenu, fieldText);
    }
    else
        residenceMenu->SetSelectedIndex(-1);
    AddControl(residenceMenu);

    bounds.SetLTRB(195, 231, 355, 247);
    PopupMenuControlPane *accessMenu =
        new PopupMenuControlPane(this, &bounds);
    AppendMenuItem(
        accessMenu,
        L"\uAC8C\uC784\uBC29 \uBC0F \uC778\uD130\uB137\uCE74\uD398");
    AppendMenuItem(accessMenu, L"\uD1B5\uC2E0\uC0AC");
    AppendMenuItem(accessMenu, L"\uC778\uD3EC\uC0F5");
    AppendMenuItem(accessMenu, L"\uC778\uD130\uD15F(PPP)");
    if (packet[0] == 2)
    {
        ReadUserInfoField(packet, &packetOffset, fieldText);
        SelectMenuText(accessMenu, fieldText);
    }
    else
        accessMenu->SetSelectedIndex(-1);
    AddControl(accessMenu);

    bounds.SetLTRB(195, 252, 325, 268);
    PopupMenuControlPane *discoveryMenu =
        new PopupMenuControlPane(this, &bounds);
    AppendMenuItem(discoveryMenu, L"\uCE5C\uAD6C");
    AppendMenuItem(discoveryMenu, L"\uAC8C\uC784\uBC29");
    AppendMenuItem(discoveryMenu, L"\uAC80\uC0C9\uC5D4\uC9C4");
    AppendMenuItem(discoveryMenu, L"\uD1B5\uC2E0\uC0AC");
    AppendMenuItem(
        discoveryMenu, L"\uC2E0\uBB38\uC774\uB098 \uC7A1\uC9C0");
    AppendMenuItem(discoveryMenu, L"CD\uBC30\uD3EC");
    if (packet[0] == 2)
    {
        ReadUserInfoField(packet, &packetOffset, fieldText);
        SelectMenuText(discoveryMenu, fieldText);
    }
    else
        discoveryMenu->SetSelectedIndex(-1);
    AddControl(discoveryMenu);

    SetBackgroundResource(kUserInfoResource, 0);
    DialogPane::SetHoverControl(kUserInfoNameEdit);
    UpdateActionButton();
    SetFocusedControl(kUserInfoOkButton);
    SetPendingControl(kUserInfoCancelButton);
    SetMode(1);
    bounds.SetLTRB(50, 50, 463, 407);
    OnCreate(
        &bounds, 0, NULL,
        g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pBackPane);
    SlideOpenVertical();
}

// UID:00056V | by-memory/0x0059b000-0x0059b0ed.UserInfoDialogPaneOnControlCommand.md | Completion:95 | Confidence:96
void UserInfoDialogPane::OnControlCommand(
    int controlIndex, int notifyCode)
{
    (void)notifyCode;
    if (controlIndex == kUserInfoOkButton)
    {
        const UserInfoValidationResult result = ValidateInput();
        if (result == kUserInfoValidationSucceeded)
        {
            SendUserInfo();
            SlideCloseVertical();
            CloseDialog();
        }
        else
        {
            new AlertPane(
                m_validationMessages[result], this, L"OK", NULL);
            SetHoverControl(result + kUserInfoNameEdit);
        }
    }
    else if (controlIndex == kUserInfoCancelButton)
    {
        SlideCloseVertical();
        CloseDialog();
    }
}

// UID:00056W | by-memory/0x0059b0f0-0x0059b110.UserInfoDialogPaneHandlePointerOrMouseEvent.md | Completion:94 | Confidence:95
bool UserInfoDialogPane::HandlePointerOrMouseEvent(Event *event)
{
    RefreshActionButtonState();
    return DialogPane::HandlePointerOrMouseEvent(event);
}

// UID:00056X | by-memory/0x0059b110-0x0059b130.UserInfoDialogPaneHandleKeyOrTextEvent.md | Completion:95 | Confidence:96
bool UserInfoDialogPane::HandleKeyOrTextEvent(Event *event)
{
    RefreshActionButtonState();
    return DialogPane::HandleKeyOrTextEvent(event);
}

// UID:00056Y | by-memory/0x0059b130-0x0059b14a.UserInfoDialogPaneSetHoverControl.md | Completion:95 | Confidence:96
void UserInfoDialogPane::SetHoverControl(int controlId)
{
    DialogPane::SetHoverControl(controlId);
    UpdateActionButton();
}

// UID:00056Z | by-memory/0x0059b150-0x0059b253.UserInfoDialogPaneUpdateActionButton.md | Completion:96 | Confidence:97
void UserInfoDialogPane::UpdateActionButton()
{
    ImageButtonControlPane *okButton =
        GetChild<ImageButtonControlPane>(kUserInfoOkButton);
    const bool canSubmit =
        !GetChild<TextEditControlPane>(kUserInfoNameEdit)->IsEmpty() &&
        !GetChild<TextEditControlPane>(
            kUserInfoResidentIdPrefixEdit)->IsEmpty() &&
        !GetChild<TextEditControlPane>(
            kUserInfoResidentIdSuffixEdit)->IsEmpty() &&
        !GetChild<TextEditControlPane>(
            kUserInfoParentNameEdit)->IsEmpty() &&
        GetChild<PopupMenuControlPane>(
            kUserInfoBloodTypeMenu)->GetSelectedIndex() != -1 &&
        GetChild<PopupMenuControlPane>(
            kUserInfoResidenceMenu)->GetSelectedIndex() != -1 &&
        GetChild<PopupMenuControlPane>(
            kUserInfoPrimaryAccessMethodMenu)->GetSelectedIndex() != -1;
    if (canSubmit) okButton->Enable();
    else okButton->Disable();
}

// UID:000570 | by-memory/0x0059b260-0x0059b5b4.UserInfoDialogPaneValidateInput.md | Completion:96 | Confidence:97
UserInfoValidationResult UserInfoDialogPane::ValidateInput()
{
    wchar_t text[128];
    GetChild<TextEditControlPane>(kUserInfoNameEdit)->
        ReadText(text, 128);
    for (unsigned char i = 0;
         i < static_cast<unsigned char>(wcslen(text)); ++i)
        if (text[i] >= L'0' && text[i] <= L'9')
            return kUserInfoNameInvalid;

    GetChild<TextEditControlPane>(kUserInfoResidentIdPrefixEdit)->
        ReadText(text, 128);
    unsigned short checksum = 0;
    for (unsigned char i = 0;
         i < static_cast<unsigned char>(wcslen(text)); ++i)
    {
        const unsigned short digit =
            static_cast<unsigned short>(text[i] - L'0');
        if (digit > 9) return kUserInfoResidentIdPrefixInvalid;
        checksum += digit * (i + 2);
    }

    GetChild<TextEditControlPane>(kUserInfoResidentIdSuffixEdit)->
        ReadText(text, 128);
    const unsigned char length =
        static_cast<unsigned char>(wcslen(text));
    for (unsigned char i = 0; i < length; ++i)
    {
        const unsigned short digit =
            static_cast<unsigned short>(text[i] - L'0');
        if (digit > 9) return kUserInfoResidentIdSuffixInvalid;
        if (i < length - 1)
            checksum += digit * (i < 2 ? i + 8 : i);
    }
    if (text[6] - L'0' != (11 - checksum % 11) % 10)
        return kUserInfoResidentIdPrefixInvalid;

    GetChild<TextEditControlPane>(kUserInfoParentNameEdit)->
        ReadText(text, 128);
    for (unsigned char i = 0;
         i < static_cast<unsigned char>(wcslen(text)); ++i)
        if (text[i] >= L'0' && text[i] <= L'9')
            return kUserInfoParentNameInvalid;

    if (GetChild<PopupMenuControlPane>(
            kUserInfoBloodTypeMenu)->GetSelectedIndex() == -1)
        return kUserInfoBloodTypeRequired;
    if (GetChild<PopupMenuControlPane>(
            kUserInfoResidenceMenu)->GetSelectedIndex() == -1)
        return kUserInfoResidenceRequired;
    if (GetChild<PopupMenuControlPane>(
            kUserInfoPrimaryAccessMethodMenu)->GetSelectedIndex() == -1)
        return kUserInfoPrimaryAccessMethodRequired;
    if (GetChild<PopupMenuControlPane>(
            kUserInfoDiscoveryReasonMenu)->GetSelectedIndex() == -1)
        return kUserInfoDiscoveryReasonRequired;
    return kUserInfoValidationSucceeded;
}

// UID:000571 | by-memory/0x0059b5c0-0x0059bc2c.UserInfoDialogPaneSendUserInfo.md | Completion:96 | Confidence:97
void UserInfoDialogPane::SendUserInfo()
{
    unsigned char packet[4096];
    packet[0] = 0x53;
    packet[1] = 1;
    int offset = 4;
    wchar_t text[128];

    for (int id = kUserInfoNameEdit;
         id <= kUserInfoParentNameEdit; ++id)
    {
        GetChild<TextEditControlPane>(id)->ReadText(text, 128);
        offset = AppendUserInfoField(packet, offset, text);
    }
    for (int id = kUserInfoBloodTypeMenu;
         id <= kUserInfoDiscoveryReasonMenu; ++id)
    {
        PopupMenuControlPane *menu =
            GetChild<PopupMenuControlPane>(id);
        static_cast<StringMenuItem *>(
            menu->GetItem(menu->GetSelectedIndex()))->
            CopyText(text, 128);
        offset = AppendUserInfoField(packet, offset, text);
    }

    const unsigned short payloadLength =
        static_cast<unsigned short>(offset - 4);
    packet[2] = static_cast<unsigned char>(payloadLength >> 8);
    packet[3] = static_cast<unsigned char>(payloadLength);
    packet[offset] = 0;
    g_packetSender->QueueAndSendPacket(packet, offset);
}
