// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IJ
// Source by-file doc: by-file/CreateUserDialogPane.md
// UID:0004Y3 | by-global/g_pCreateUserDialogPane.md | Completion:92 | Confidence:93
class CreateUserDialogPane;

CreateUserDialogPane *g_pCreateUserDialogPane = 0;


// UID:00046E | by-memory/0x0052dd30-0x0052e6eb.CreateUserDialogPaneConstructor.md | Completion:92 | Confidence:93
CreateUserDialogPane::CreateUserDialogPane()
    : DialogPane(L"NE", -1, 4),
      Singleton<CreateUserDialogPane>(),
      m_waitingForCharacterReply(0)
{
    m_createUserExtraText.clear();

    srand((unsigned)_time64(0));

    LoadDialogBackground(L"DLGNEW3.EPF", L"DLGNEW3.PAL");

    CreateChildEditControl(1, RectBounds(232, 132, 414, 144), false);
    CreateChildEditControl(2, RectBounds(232, 168, 414, 180), true);
    CreateChildEditControl(3, RectBounds(232, 206, 414, 218), true);

    CreateGenderButton(4, RectBounds(68, 480, 118, 530), 0);
    CreateGenderButton(5, RectBounds(110, 480, 160, 530), 1);

    const RectBounds hairBounds = {170, 342, 926, 477};
    UserHairSelectControlPane *hairSelector =
        new UserHairSelectControlPane(rand() % 10, 12, 0, &hairBounds, 0);
    AddChildControl(6, hairSelector);

    const RectBounds faceBounds = {170, 545, 676, 662};
    UserFaceSelectControlPane *faceSelector =
        new UserFaceSelectControlPane(rand() % 10, 1, 0, &faceBounds, 0);
    AddChildControl(7, faceSelector);

    AddChildControl(
        8,
        new UserHairColorSelectListPane(
            RectBounds(814, 545, 964, 695),
            this));
    AddChildControl(
        9,
        new UserFaceColorSelectListPane(
            RectBounds(663, 545, 813, 695),
            this));

    CreateBodyShapeButton(10, RectBounds(501, 146, 551, 196), 0);
    CreateBodyShapeButton(11, RectBounds(559, 146, 609, 196), 1);
    CreateBodyShapeButton(12, RectBounds(501, 201, 551, 251), 2);
    CreateBodyShapeButton(13, RectBounds(559, 201, 609, 251), 3);

    CreateDialogLabel(
        14,
        RectBounds(627, 124, 909, 250),
        g_pLanguageMan->GetLocalizedString(m_bodyShapeIndex + 212));

    CreateCommandButton(15, RectBounds(371, 713, 484, 749), 0);
    CreateCommandButton(16, RectBounds(539, 713, 652, 749), 1);
    CreatePreviewDirectionButton(17, RectBounds(85, 541, 135, 591), L"DIREC.EPF");

    m_initialAppearanceRoll = rand() % 2;
    SelectBodyShape((short)(rand() % 4));

    if ((rand() % 2) != 0) {
        SelectMale();
    } else {
        SelectFemale();
    }

    const RectBounds previewBounds = {65, 355, 147, 472};
    AddChildControl(
        18,
        new UserCreatePreviewControlPane(
            faceSelector->GetSelectedFacePartId(),
            faceSelector->GetFaceColorIndex(),
            hairSelector->GetSelectedHairPartFrame(),
            hairSelector->GetHairColorIndex(),
            m_isFemale,
            &previewBounds,
            0));

    SetActiveControl(15);
    SetDefaultControl(16);
    EnableDialogFocusRouting(true);
    SetDialogFrameResource(L"DLGNEW.EPF", 0);
    CreateDialogWindow();
    Show();
}

// UID:00046I | by-memory/0x0052e770-0x0052e832.CreateUserDialogPaneSelectBodyShape.md | Completion:88 | Confidence:90
void CreateUserDialogPane::SelectBodyShape(short bodyShapeIndex)
{
    UserShapeSelectControlPane *bodyShapes[4];

    bodyShapes[0] = GetControl<UserShapeSelectControlPane>(10);
    bodyShapes[1] = GetControl<UserShapeSelectControlPane>(11);
    bodyShapes[2] = GetControl<UserShapeSelectControlPane>(12);
    bodyShapes[3] = GetControl<UserShapeSelectControlPane>(13);

    bodyShapes[m_bodyShapeIndex]->SetActive(false);
    bodyShapes[bodyShapeIndex]->SetActive(true);
    m_bodyShapeIndex = bodyShapeIndex;

    SetDialogLabelText(14, g_pLanguageMan->GetLocalizedString(bodyShapeIndex + 212));
}

// UID:00046K | by-memory/0x0052e850-0x0052e8b7.CreateUserDialogPaneSelectMale.md | Completion:88 | Confidence:90
void CreateUserDialogPane::SelectMale()
{
    m_isFemale = 0;
    SetDialogButtonChecked(4, true);
    SetDialogButtonChecked(5, false);

    UserHairSelectControlPane *hairSelector = GetControl<UserHairSelectControlPane>(6);
    hairSelector->SetMaleMode();

    UserFaceSelectControlPane *faceSelector = GetControl<UserFaceSelectControlPane>(7);
    faceSelector->SetGender(0);
    faceSelector->Invalidate();
}

// UID:00046L | by-memory/0x0052e8c0-0x0052e927.CreateUserDialogPaneSelectFemale.md | Completion:88 | Confidence:90
void CreateUserDialogPane::SelectFemale()
{
    m_isFemale = 1;
    SetDialogButtonChecked(4, false);
    SetDialogButtonChecked(5, true);

    UserHairSelectControlPane *hairSelector = GetControl<UserHairSelectControlPane>(6);
    hairSelector->SetFemaleMode();

    UserFaceSelectControlPane *faceSelector = GetControl<UserFaceSelectControlPane>(7);
    faceSelector->SetGender(1);
    faceSelector->Invalidate();
}

// UID:00046M | by-memory/0x0052e930-0x0052e94f.CreateUserDialogPaneSetHairColorIndex.md | Completion:89 | Confidence:91
unsigned char CreateUserDialogPane::SetHairColorIndex(unsigned char colorIndex)
{
    UserHairSelectControlPane *hairSelector = GetControl<UserHairSelectControlPane>(6);
    hairSelector->SetHairColorIndex(colorIndex);
    return colorIndex;
}

// UID:00046N | by-memory/0x0052e950-0x0052e96f.CreateUserDialogPaneSetFaceColorIndex.md | Completion:89 | Confidence:91
unsigned char CreateUserDialogPane::SetFaceColorIndex(unsigned char colorIndex)
{
    UserFaceSelectControlPane *faceSelector = GetControl<UserFaceSelectControlPane>(7);
    faceSelector->SetFaceColorIndex(colorIndex);
    return colorIndex;
}

// UID:00046O | by-memory/0x0052e970-0x0052ea44.CreateUserDialogPaneOpenNexonclubRegistrationOrSendCharacterRequest.md | Completion:92 | Confidence:94
#include "CreateUserDialogPane.h"
#include "../util/FunctionObjects.h"
#include "../util/StringBase.h"
#include "../ui/dialogs/NexonclubRegistrationDialog.h"

void CreateUserDialogPane::OpenNexonclubRegistrationOrSendCharacterRequest(
    bool openRegistration)
{
    if (!openRegistration) {
        SendCreateCharacterRequest();
        return;
    }

    typedef mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
        RegistrationString;
    typedef void (CreateUserDialogPane::*RegistrationResultCallback)(
        const RegistrationString &);

    FunctionObjectT<const RegistrationString &> *callback =
        new PlainMemberFunctionObjectT<
            RegistrationResultCallback,
            CreateUserDialogPane,
            const RegistrationString &>(
                this,
                &CreateUserDialogPane::OnNexonclubRegistrationResult);

    new NexonclubRegistrationDialog(
        g_pLanguageMan->GetLocalizedString(227),
        callback);
}

// UID:00046P | by-memory/0x0052ea50-0x0052ea7c.CreateUserDialogPaneOnNexonclubRegistrationResult.md | Completion:90 | Confidence:93
void CreateUserDialogPane::OnNexonclubRegistrationResult(
    const mystr::StringBase<
        wchar_t,
        mystr::mychar_traits<wchar_t> > &text)
{
    if (!text.empty()) {
        m_createUserExtraText = text;
    }

    SendCreateCharacterRequest();
}

// UID:00046Q | by-memory/0x0052ea80-0x0052ec80.CreateUserDialogPaneOnDialogAction.md | Completion:88 | Confidence:90
void CreateUserDialogPane::OnDialogAction(int commandId, int action)
{
    UserHairSelectControlPane *hairSelector =
        GetControl<UserHairSelectControlPane>(6);
    UserFaceSelectControlPane *faceSelector =
        GetControl<UserFaceSelectControlPane>(7);
    UserCreatePreviewControlPane *previewPane =
        GetControl<UserCreatePreviewControlPane>(18);

    switch (commandId) {
    case 4:
        SelectMale();
        previewPane->UpdatePreview(
            faceSelector->GetSelectedFacePartId(),
            faceSelector->GetFaceColorIndex(),
            hairSelector->GetSelectedHairPartFrame(),
            hairSelector->GetHairColorIndex(),
            m_isFemale);
        return;

    case 5:
        SelectFemale();
        previewPane->UpdatePreview(
            faceSelector->GetSelectedFacePartId(),
            faceSelector->GetFaceColorIndex(),
            hairSelector->GetSelectedHairPartFrame(),
            hairSelector->GetHairColorIndex(),
            m_isFemale);
        return;

    case 6:
    case 7:
        previewPane->UpdatePreview(
            faceSelector->GetSelectedFacePartId(),
            faceSelector->GetFaceColorIndex(),
            hairSelector->GetSelectedHairPartFrame(),
            hairSelector->GetHairColorIndex(),
            m_isFemale);
        return;

    case 8:
        hairSelector->Invalidate();
        previewPane->UpdatePreview(
            faceSelector->GetSelectedFacePartId(),
            faceSelector->GetFaceColorIndex(),
            hairSelector->GetSelectedHairPartFrame(),
            hairSelector->GetHairColorIndex(),
            m_isFemale);
        return;

    case 9:
        faceSelector->Invalidate();
        previewPane->UpdatePreview(
            faceSelector->GetSelectedFacePartId(),
            faceSelector->GetFaceColorIndex(),
            hairSelector->GetSelectedHairPartFrame(),
            hairSelector->GetHairColorIndex(),
            m_isFemale);
        return;

    case 10:
    case 11:
    case 12:
    case 13:
        SelectBodyShape((short)(commandId - 10));
        return;

    case 15:
        SubmitCreateUser();
        return;

    case 16:
        Close();
        return;

    case 17:
        previewPane->AdvanceDirection();
        return;

    default:
        return;
    }
}

// UID:00046R | by-memory/0x0052ecc0-0x0052ecc9.CreateUserDialogPaneOnKeyEvent.md | Completion:88 | Confidence:90
bool CreateUserDialogPane::OnKeyEvent(KeyEvent *event)
{
    return DialogPane::OnKeyEvent(event);
}

// UID:00046S | by-memory/0x0052ecd0-0x0052ecf6.CreateUserDialogPaneHandlePacketEvent.md | Completion:90 | Confidence:94
bool CreateUserDialogPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet = event->m_payload.m_packet.m_data;

    if (packet[0] != 0x02)
    {
        return false;
    }

    return HandleCreateUserReply(packet);
}

// UID:00046T | by-memory/0x0052ed00-0x0052ed09.CreateUserDialogPaneOnDialogShow.md | Completion:88 | Confidence:91
bool CreateUserDialogPane::OnDialogShow(int reason)
{
    return DialogPane::OnDialogShow(reason);
}

// UID:00046V | by-memory/0x0052ed80-0x0052ef4c.CreateUserDialogPaneSubmitCreateUser.md | Completion:89 | Confidence:90
void CreateUserDialogPane::SubmitCreateUser()
{
    wchar_t accountName[16];
    wchar_t password[16];
    wchar_t confirmPassword[16];

    GetChildEditText(1, accountName, 15);
    GetChildEditText(2, password, 15);
    GetChildEditText(3, confirmPassword, 15);

    bool hasDigit = false;
    for (const wchar_t *scan = password; *scan != L'\0'; ++scan) {
        if (*scan >= L'0' && *scan <= L'9') {
            hasDigit = true;
            break;
        }
    }

    if (!hasDigit) {
        FocusChildControl(2);
        ShowCreateUserAlert(kPasswordMustContainDigitText);
        return;
    }

    if (wcscmp(password, confirmPassword) != 0) {
        FocusChildControl(2);
    ShowCreateUserAlert(g_pLanguageMan->GetLocalizedString(90));
        return;
    }

    CreateCreateUserScreenDimmer();
    SendCreateAccountRequest(accountName, password, kCreateUserDefaultProfileText);
}

// UID:00046X | by-memory/0x0052f160-0x0052f38d.CreateUserDialogPaneSendCreateCharacterRequest.md | Completion:88 | Confidence:90
void CreateUserDialogPane::SendCreateCharacterRequest()
{
    if (g_createUserScreenDimmer == 0) {
        CreateCreateUserScreenDimmer();
    }

    HumanImageRenderParams appearance;
    GetControl<UserCreatePreviewControlPane>(18)->BuildPreviewParams(&appearance);

    PacketBuffer packet;
    packet.WriteByte(0x04);
    packet.WriteWord(appearance.createUserPacketWord);
    packet.WriteByte(appearance.createUserPacketByte0);
    packet.WriteByte(appearance.createUserPacketByte1);
    packet.WriteByte(appearance.createUserPacketByte2);
    packet.WriteByte(appearance.createUserPacketByte3);
    packet.WriteByte(0);
    packet.WriteByte((unsigned char)m_bodyShapeIndex);
    packet.WriteLengthPrefixedMbcString(m_createUserExtraText.c_str());

    g_packetSender->QueueAndSendPacket(packet.Data(), packet.SizeWithoutTerminator());
}

// UID:00046Y | by-memory/0x0052f390-0x0052f6e5.CreateUserDialogPaneHandleCreateUserReply.md | Completion:89 | Confidence:90
namespace
{
SimpleUString DecodeCreateUserReplyMessage(const unsigned char *packet)
{
    return SimpleUString::FromMbcString(packet + 3, packet[2]);
}

bool IsCreateUserNameReplyError(unsigned char result)
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

bool IsCreateUserPasswordReplyError(unsigned char result)
{
    switch (result) {
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 15:
        return true;

    default:
        return false;
    }
}

void ShowCreateUserReplyText(const SimpleUString &message)
{
    if (!message.empty()) {
        ShowCreateUserAlert(message.c_str());
    }
}
}

bool CreateUserDialogPane::HandleCreateUserReply(const unsigned char *packet)
{
    const unsigned char result = packet[1];
    const SimpleUString message = DecodeCreateUserReplyMessage(packet);

    if (!m_waitingForCharacterReply) {
        if (result == 0) {
            wchar_t accountName[16];

            m_waitingForCharacterReply = true;
            SendCreateCharacterRequest();

            GetChildEditText(1, accountName, 15);
            g_newUserDialogCreatedAccountName.Assign(accountName);
            return true;
        }

        DestroyCreateUserScreenDimmer();

        if (IsCreateUserNameReplyError(result)) {
            FocusChildControl(1);
        } else if (IsCreateUserPasswordReplyError(result)) {
            FocusChildControl(2);
        }

        ShowCreateUserReplyText(message);
        return true;
    }

    DestroyCreateUserScreenDimmer();

    if (result != 0) {
        ShowCreateUserReplyText(message);
        return true;
    }

    if (!message.empty()) {
        ShowCreateUserAlert(message.c_str());
    } else {
        ShowCreateUserAlert(kCreateUserCompleteMessage);
    }

    Close();
    return true;
}

// UID:00046W | by-memory/0x0052ef50-0x0052f155.CreateUserDialogPaneSendCreateAccountRequest.md | Completion:88 | Confidence:90
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

// UID:00003B | by-class\CreateUserDialogPane.md | Completion:93 | Confidence:94 | Empty Emitter Marker
