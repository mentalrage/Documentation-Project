// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LP
// Source by-file doc: by-file/NewCreateUserDialogPane.md
// UID:0002X7 | by-global/g_pNewCreateUserDialogPane.md | Completion:92 | Confidence:94
class NewCreateUserDialogPane;

NewCreateUserDialogPane *g_pNewCreateUserDialogPane = 0;


// UID:0002QS | by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md | Completion:88 | Confidence:91
#include "NewCreateUserDialogPane.h"
#include "MainMenuPane.h"
#include "NewUserShapeSelectControlPane.h"
#include "../app/Application.h"
#include "../localization/LanguageMan.h"
#include "../ui/MainUiGraph.h"
#include "../ui/controls/EPFImageControlPane.h"
#include "../ui/controls/PrettyButtonControlPane.h"
#include "../ui/controls/StaticTextControlPane.h"
#include "../ui/controls/TextEditControlPane.h"
#include "../ui/core/RectBounds.h"
#include "../ui/dialogs/NexonclubRegistrationDialog.h"
#include "../util/FunctionObjects.h"
#include "../util/StringBase.h"

#include <stdlib.h>
#include <time.h>

namespace
{
void SendCreateAccountRequest(const wchar_t *accountName,
                              const wchar_t *password,
                              const wchar_t *profileText)
{
    PacketBuffer packet;
    packet.WriteByte(0x02);
    packet.WriteLengthPrefixedMbcString(accountName);
    packet.WriteLengthPrefixedMbcString(password);
    packet.WriteLengthPrefixedMbcString(profileText);
    packet.WriteByte(0);
    g_packetSender->QueueAndSendPacket(packet.Data(), packet.Size());
}
}

NewCreateUserDialogPane::NewCreateUserDialogPane()
    : DialogPane(L"NE", static_cast<unsigned short>(-1), 4),
      m_waitingForCharacterReply(false)
{
    RectBounds bounds;
    PrettyButtonControlPane *nationButtons[2];
    PrettyButtonControlPane *totemButtons[4];

    srand(static_cast<unsigned int>(_time64(0)));

    InitRectBounds(&bounds, 0, 0, g_screenWidth, g_screenHeight);
    AddControl(new EPFImageControlPane(
        L"DLGNEW.EPF", 0, 0, &bounds, L"DLGNEW.PAL"));

    InitRectBounds(&bounds, 470, 358, 652, 370);
    AddControl(new TextEditControlPane(
        L"", true, 128, 143, &bounds,
        false, false, false, false, 1.0f, false));

    InitRectBounds(&bounds, 470, 390, 652, 402);
    TextEditControlPane *passwordControl = new TextEditControlPane(
        L"", true, 128, 143, &bounds,
        false, false, false, false, 1.0f, false);
    AddControl(passwordControl);
    passwordControl->EnableMaskedText();

    InitRectBounds(&bounds, 470, 422, 652, 434);
    TextEditControlPane *confirmationControl = new TextEditControlPane(
        L"", true, 128, 143, &bounds,
        false, false, false, false, 1.0f, false);
    AddControl(confirmationControl);
    confirmationControl->EnableMaskedText();

    InitRectBounds(&bounds, 428, 103, 533, 131);
    AddControl(new PrettyButtonControlPane(
        bounds, L"GENDER.EPF", L"NEWBUTT.PAL", 0, 1, 2, 0));

    InitRectBounds(&bounds, 428, 216, 533, 244);
    AddControl(new PrettyButtonControlPane(
        bounds, L"GENDER.EPF", L"NEWBUTT.PAL", 3, 4, 5, 0));

    InitRectBounds(&bounds, 609, 579, 659, 629);
    AddControl(new PrettyButtonControlPane2(
        bounds, L"DIREC.EPF", L"NEWBUTT.PAL", 3, 9, 3, 6, 0));

    InitRectBounds(&bounds, 843, 579, 893, 629);
    AddControl(new PrettyButtonControlPane2(
        bounds, L"DIREC.EPF", L"NEWBUTT.PAL", 4, 10, 4, 7, 0));

    InitRectBounds(&bounds, 539, 164, 955, 574);
    AddControl(new NewUserShapeSelectControlPane(
        static_cast<short>(rand() % 15), true, &bounds, 0));

    InitRectBounds(&bounds, 63, 351, 113, 401);
    nationButtons[0] = new PrettyButtonControlPane(
        bounds, L"NNATION.EPF", L"NNATION.PAL", 4, 0, 6, 0);
    AddControl(nationButtons[0]);

    InitRectBounds(&bounds, 121, 351, 171, 401);
    nationButtons[1] = new PrettyButtonControlPane(
        bounds, L"NNATION.EPF", L"NNATION.PAL", 5, 1, 7, 0);
    AddControl(nationButtons[1]);

    m_selectedGenderOrNation = rand() % 2;
    nationButtons[m_selectedGenderOrNation]->SetSelected(true);

    InitRectBounds(&bounds, 62, 548, 112, 598);
    totemButtons[0] = new PrettyButtonControlPane(
        bounds, L"NTOTEM.EPF", L"NEWBUTT.PAL", 8, 0, 12, 0);
    AddControl(totemButtons[0]);

    InitRectBounds(&bounds, 121, 548, 171, 598);
    totemButtons[1] = new PrettyButtonControlPane(
        bounds, L"NTOTEM.EPF", L"NEWBUTT.PAL", 9, 1, 13, 0);
    AddControl(totemButtons[1]);

    InitRectBounds(&bounds, 62, 604, 112, 654);
    totemButtons[2] = new PrettyButtonControlPane(
        bounds, L"NTOTEM.EPF", L"NEWBUTT.PAL", 10, 2, 14, 0);
    AddControl(totemButtons[2]);

    InitRectBounds(&bounds, 121, 604, 171, 654);
    totemButtons[3] = new PrettyButtonControlPane(
        bounds, L"NTOTEM.EPF", L"NEWBUTT.PAL", 11, 3, 15, 0);
    AddControl(totemButtons[3]);

    m_selectedTotem = rand() % 4;
    totemButtons[m_selectedTotem]->SetSelected(true);

    InitRectBounds(&bounds, 190, 321, 472, 417);
    AddControl(new StaticTextControlPane(
        g_pLanguageMan->GetLocalizedString(210 + m_selectedGenderOrNation),
        true, 143, 0, &bounds, false, false));

    InitRectBounds(&bounds, 190, 518, 472, 644);
    AddControl(new StaticTextControlPane(
        g_pLanguageMan->GetLocalizedString(212 + m_selectedTotem),
        true, 143, 0, &bounds, false, false));

    InitRectBounds(&bounds, 611, 677, 724, 713);
    AddControl(new PrettyButtonControlPane(
        bounds, L"NEWUSERS.EPF", L"NEWUSERS.PAL", 0, 4, 2, 0));

    InitRectBounds(&bounds, 779, 677, 892, 713);
    AddControl(new PrettyButtonControlPane(
        bounds, L"NEWUSERS.EPF", L"NEWUSERS.PAL", 1, 5, 3, 0));

    InitRectBounds(&bounds, 551, 106, 601, 156);
    AddControl(new PrettyButtonControlPane(
        bounds, L"DIREC.EPF", L"NEWBUTT.PAL", 5, 2, 5, 0));

    SetFocusedControl(17);
    SetPendingControl(18);
    SetHoverControl(1);

    SelectGender(static_cast<short>(rand() % 2));
    SelectTotem(static_cast<short>(rand() % 4));
    if (rand() % 2 == 0) {
        SelectFemale();
    } else {
        SelectMale();
    }

    GetChild<ControlPane>(6)->Disable();
    SetBackgroundResource(L"DLGNEW.EPF", 0);

    InitRectBounds(&bounds, 0, 0, g_screenWidth, g_screenHeight);
    OnCreate(&bounds, 0, NULL, g_mainUiLayerSlots.overlayPaneLayerContext);
    OnShow(NULL, g_pMainMenuPane);
}

void NewCreateUserDialogPane::SelectGender(short genderOrNation)
{
    PrettyButtonControlPane *buttons[2];

    buttons[0] = GetChild<PrettyButtonControlPane>(9);
    buttons[1] = GetChild<PrettyButtonControlPane>(10);
    buttons[m_selectedGenderOrNation]->SetSelected(false);
    buttons[genderOrNation]->SetSelected(true);
    m_selectedGenderOrNation = genderOrNation;
    GetChild<TextEditControlPane>(15)->SetText(
        g_pLanguageMan->GetLocalizedString(genderOrNation + 210));
}

void NewCreateUserDialogPane::SelectTotem(short totem)
{
    PrettyButtonControlPane *buttons[4];

    buttons[0] = GetChild<PrettyButtonControlPane>(11);
    buttons[1] = GetChild<PrettyButtonControlPane>(12);
    buttons[2] = GetChild<PrettyButtonControlPane>(13);
    buttons[3] = GetChild<PrettyButtonControlPane>(14);
    buttons[m_selectedTotem]->SetSelected(false);
    buttons[totem]->SetSelected(true);
    m_selectedTotem = totem;
    GetChild<TextEditControlPane>(16)->SetText(
        g_pLanguageMan->GetLocalizedString(totem + 212));
}

void NewCreateUserDialogPane::SelectMale()
{
    GetChild<PrettyButtonControlPane>(4)->SetSelected(true);
    GetChild<PrettyButtonControlPane>(5)->SetSelected(false);
    GetChild<NewUserShapeSelectControlPane>(8)->SetMaleMode();
}

void NewCreateUserDialogPane::SelectFemale()
{
    GetChild<PrettyButtonControlPane>(4)->SetSelected(false);
    GetChild<PrettyButtonControlPane>(5)->SetSelected(true);
    GetChild<NewUserShapeSelectControlPane>(8)->SetFemaleMode();
}

void NewCreateUserDialogPane::OpenNexonclubRegistrationOrSendCharacterRequest(
    bool openRegistration)
{
    if (!openRegistration) {
        SendCreateCharacterRequest();
        return;
    }

    typedef mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
        RegistrationString;
    typedef void (NewCreateUserDialogPane::*RegistrationResultCallback)(
        const RegistrationString &);

    FunctionObjectT<const RegistrationString &> *callback =
        new PlainMemberFunctionObjectT<
            RegistrationResultCallback,
            NewCreateUserDialogPane,
            const RegistrationString &>(
                this,
                &NewCreateUserDialogPane::OnNexonclubRegistrationResult);

    new NexonclubRegistrationDialog(
        g_pLanguageMan->GetLocalizedString(227),
        callback);
}

void NewCreateUserDialogPane::OnNexonclubRegistrationResult(
    const mystr::StringBase<
        wchar_t,
        mystr::mychar_traits<wchar_t> > &accountName)
{
    if (!accountName.empty()) {
        m_nexonclubAccountName = accountName;
    }

    SendCreateCharacterRequest();
}

void NewCreateUserDialogPane::OnControlCommand(
    int controlIndex,
    int notifyCode)
{
    switch (controlIndex) {
    case 4:
        SelectMale();
        break;
    case 5:
        SelectFemale();
        break;
    case 9:
        SelectGender(0);
        break;
    case 10:
        SelectGender(1);
        break;
    case 11:
        SelectTotem(0);
        break;
    case 12:
        SelectTotem(1);
        break;
    case 13:
        SelectTotem(2);
        break;
    case 14:
        SelectTotem(3);
        break;
    case 17:
        SubmitCreateUser();
        break;
    case 18:
        CloseDialog();
        break;
    case 19:
        GetChild<NewUserShapeSelectControlPane>(8)->AdvanceDirection();
        break;
    }
}

bool NewCreateUserDialogPane::HandleKeyOrTextEvent(Event *event)
{
    return DialogPane::HandleKeyOrTextEvent(event);
}

bool NewCreateUserDialogPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet = event->m_payload.m_packet.m_data;

    if (packet[0] != 0x02) {
        return false;
    }

    return HandleCreateUserReply(packet);
}

bool NewCreateUserDialogPane::HandlePointerOrMouseEvent(Event *event)
{
    return DialogPane::HandlePointerOrMouseEvent(event);
}

void NewCreateUserDialogPane::SubmitCreateUser()
{
    wchar_t accountName[16];
    wchar_t password[16];
    wchar_t confirmPassword[16];

    GetDialogText(1, accountName, 15);
    GetDialogText(2, password, 15);
    GetDialogText(3, confirmPassword, 15);

    if (!PasswordContainsDigit(password)) {
        FocusDialogControl(2);
        ShowCreateUserAlert(kPasswordMustContainDigitText);
        return;
    }

    if (wcscmp(password, confirmPassword) != 0) {
        FocusDialogControl(2);
        ShowCreateUserAlert(g_pLanguageMan->GetLocalizedString(90));
        return;
    }

    g_pScreenPane->CreateScreenDimmer();
    SendCreateAccountRequest(accountName, password, g_sharedEmptyWideStringLiteral);
}

void NewCreateUserDialogPane::SendCreateCharacterRequest()
{
    PacketBuffer packet;
    HumanImageRenderParams appearance;
    NewUserShapeSelectControlPane *shapeSelector =
        GetChild<NewUserShapeSelectControlPane>(8);
    const unsigned char shapeIndex = static_cast<unsigned char>(
        shapeSelector->SelectedShapeSlot() +
        15 * shapeSelector->ShapePage());

    if (!g_pScreenDimmer) {
        g_pScreenPane->CreateScreenDimmer();
    }

    shapeSelector->BuildPreviewParams(&appearance, shapeIndex);

    packet.WriteByte(0x04);
    packet.WriteByte(static_cast<unsigned char>(appearance.shapeIndex));
    packet.WriteByte(appearance.isFemale ? 1 : 0);
    packet.WriteByte(static_cast<unsigned char>(m_selectedGenderOrNation + 1));
    packet.WriteByte(static_cast<unsigned char>(m_selectedTotem));
    packet.WriteLengthPrefixedMbcString(m_nexonclubAccountName.c_str());
    packet.WriteByte(0);
    g_packetSender->QueueAndSendPacket(packet.Data(), packet.Size());
}

bool NewCreateUserDialogPane::HandleCreateUserReply(const unsigned char *packet)
{
    const unsigned char result = packet[1];
    const unsigned char messageLength = packet[2];
    wchar_t messageText[256];

    DecodeCreateUserReplyMessage(packet + 3, messageLength, messageText, 256);

    if (!m_waitingForCharacterReply) {
        if (result == 0) {
            wchar_t accountName[16];

            m_waitingForCharacterReply = 1;
            SendCreateCharacterRequest();
            GetDialogText(1, accountName, 15);
            g_createdAccountName.Assign(accountName);
            return true;
        }

        if (g_pScreenDimmer) {
            g_pScreenDimmer->Close(1);
        }

        if (IsCreateUserNameReplyError(result)) {
            FocusDialogControl(1);
        } else if (IsCreateUserPasswordReplyError(result)) {
            FocusDialogControl(2);
        }

        if (messageText[0] != 0) {
            ShowCreateUserAlert(messageText);
        }
        return true;
    }

    if (g_pScreenDimmer) {
        g_pScreenDimmer->Close(1);
    }

    if (result != 0) {
        if (messageText[0] != 0) {
            ShowCreateUserAlert(messageText);
        }
        return true;
    }

    if (messageText[0] != 0) {
        ShowCreateUserAlert(messageText);
    } else {
        ShowCreateUserAlert(kCreateUserFallbackReplyText);
    }

    CloseDialog();
    return true;
}

// UID:00008Z | by-class\NewCreateUserDialogPane.md | Completion:90 | Confidence:92 | Empty Emitter Marker
