// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LW
// Source by-file doc: by-file/NewUserDialogPane2.md
// UID:0002X3 | by-global/g_pNewUserDialogPane2.md | Completion:92 | Confidence:94
class NewUserDialogPane2;

NewUserDialogPane2 *g_pNewUserDialogPane2 = 0;


// UID:00043K | by-memory/0x0052a540-0x0052b047.NewUserDialogPane2Constructor.md | Completion:90 | Confidence:93
NewUserDialogPane2::NewUserDialogPane2()
    : DialogPane(L"NE", -1, true),
      Singleton<NewUserDialogPane2>(),
      m_selectedNation(0),
      m_selectedTotem(0),
      m_selectedShapeSlot(0),
      m_waitingForCharacterReply(false)
{
    m_nexonclubAccountName.clear();

    srand((unsigned)_time64(0));

    LoadDialogBackground(L"DLGNEW02.EPD");
    CreateAccountEditControls();
    CreateShapeSelectControls(L"DIREC.EPD");
    CreateNationButtons(L"NNATION.EPD");
    CreateTotemButtons(L"NNATION.EPD", L"NPAL3.PAL");
    CreateCreateUserCommandButtons();

    m_selectedShapeSlot = rand() % 4;
    m_selectedNation = rand() % 2;
    m_selectedTotem = rand() % 4;

    if ((rand() & 1) != 0) {
        SelectFemaleMode();
    } else {
        SelectMaleMode();
    }

    SelectShapeSlot(m_selectedShapeSlot);
    SelectNation(m_selectedNation);
    SelectTotem(rand() % 4);
}

// UID:00043M | by-memory/0x0052b090-0x0052b1cb.NewUserDialogPane2ShiftShapesLeft.md | Completion:92 | Confidence:94
void NewUserDialogPane2::ShiftShapesLeft()
{
    UserShapeSelectControlPane *shapeControls[4];

    for (int i = 0; i < 4; ++i) {
        shapeControls[i] = GetChild<UserShapeSelectControlPane>(8 + i);
    }

    ControlPane *previousButton = GetChild<ControlPane>(6);
    ControlPane *nextButton = GetChild<ControlPane>(7);

    if (m_selectedShapeSlot != 0) {
        shapeControls[m_selectedShapeSlot]->SetSelected(false);
        --m_selectedShapeSlot;
        shapeControls[m_selectedShapeSlot]->SetSelected(true);
        return;
    }

    if (!previousButton->IsEnabled()) {
        return;
    }

    short edgeResult = shapeControls[0]->StepShapeBackward();
    shapeControls[1]->StepShapeBackward();
    shapeControls[2]->StepShapeBackward();
    shapeControls[3]->StepShapeBackward();

    if (edgeResult == -1) {
        previousButton->Disable();
    } else {
        nextButton->Enable();
    }
}

// UID:00043N | by-memory/0x0052b1d0-0x0052b30d.NewUserDialogPane2ShiftShapesRight.md | Completion:92 | Confidence:94
void NewUserDialogPane2::ShiftShapesRight()
{
    UserShapeSelectControlPane *shapeControls[4];

    for (int i = 0; i < 4; ++i) {
        shapeControls[i] = GetChild<UserShapeSelectControlPane>(8 + i);
    }

    ControlPane *previousButton = GetChild<ControlPane>(6);
    ControlPane *nextButton = GetChild<ControlPane>(7);

    if (m_selectedShapeSlot != 3) {
        shapeControls[m_selectedShapeSlot]->SetSelected(false);
        ++m_selectedShapeSlot;
        shapeControls[m_selectedShapeSlot]->SetSelected(true);
        return;
    }

    if (!nextButton->IsEnabled()) {
        return;
    }

    short edgeResult = shapeControls[3]->StepShapeForward();
    shapeControls[0]->StepShapeForward();
    shapeControls[1]->StepShapeForward();
    shapeControls[2]->StepShapeForward();

    if (edgeResult == -1) {
        nextButton->Disable();
    } else {
        previousButton->Enable();
    }
}

// UID:00043O | by-memory/0x0052b310-0x0052b395.NewUserDialogPane2SelectNation.md | Completion:88 | Confidence:90
void NewUserDialogPane2::SelectNation(int nation)
{
    if (nation < 0) {
        nation = 0;
    } else if (nation > 1) {
        nation = 1;
    }

    m_selectedNation = nation;
    SetChildButtonChecked(12, nation == 0);
    SetChildButtonChecked(13, nation == 1);
    SetCreateUserDescriptionText(g_pLanguageMan->GetLocalizedString(210 + nation));
}

// UID:00043P | by-memory/0x0052b3a0-0x0052b462.NewUserDialogPane2SelectTotem.md | Completion:96 | Confidence:96
void NewUserDialogPane2::SelectTotem(short totem)
{
    PrettyButtonControlPane *totemButtons[4];

    totemButtons[0] = GetChild<PrettyButtonControlPane>(14);
    totemButtons[1] = GetChild<PrettyButtonControlPane>(15);
    totemButtons[2] = GetChild<PrettyButtonControlPane>(16);
    totemButtons[3] = GetChild<PrettyButtonControlPane>(17);

    totemButtons[m_selectedTotem]->SetSelected(false);
    totemButtons[totem]->SetSelected(true);
    m_selectedTotem = totem;

    GetChild<TextEditControlPane>(19)->SetText(
        g_pLanguageMan->GetLocalizedString(totem + 212));
}

// UID:00043Q | by-memory/0x0052b470-0x0052b52c.NewUserDialogPane2SelectShapeSlot.md | Completion:88 | Confidence:90
void NewUserDialogPane2::SelectShapeSlot(int slot)
{
    if (slot < 0) {
        slot = 0;
    } else if (slot > 3) {
        slot = 3;
    }

    m_selectedShapeSlot = slot;

    for (int i = 0; i < 4; ++i) {
        GetShapeSelectControl(8 + i)->SetSelected(i == slot);
    }
}

// UID:00043R | by-memory/0x0052b530-0x0052b5b8.NewUserDialogPane2SelectMaleMode.md | Completion:93 | Confidence:94
void NewUserDialogPane2::SelectMaleMode()
{
    PrettyButtonControlPane *maleModeButton =
        GetChild<PrettyButtonControlPane>(4);
    PrettyButtonControlPane *femaleModeButton =
        GetChild<PrettyButtonControlPane>(5);

    maleModeButton->SetSelected(true);
    femaleModeButton->SetSelected(false);

    GetChild<UserShapeSelectControlPane>(8)->SetMaleShapeBank();
    GetChild<UserShapeSelectControlPane>(9)->SetMaleShapeBank();
    GetChild<UserShapeSelectControlPane>(10)->SetMaleShapeBank();
    GetChild<UserShapeSelectControlPane>(11)->SetMaleShapeBank();
}

// UID:00043S | by-memory/0x0052b5c0-0x0052b648.NewUserDialogPane2SelectFemaleMode.md | Completion:92 | Confidence:94
void NewUserDialogPane2::SelectFemaleMode()
{
    PrettyButtonControlPane *maleModeButton =
        GetChild<PrettyButtonControlPane>(4);
    PrettyButtonControlPane *femaleModeButton =
        GetChild<PrettyButtonControlPane>(5);

    maleModeButton->SetSelected(false);
    femaleModeButton->SetSelected(true);

    GetChild<UserShapeSelectControlPane>(8)->SetFemaleShapeBank();
    GetChild<UserShapeSelectControlPane>(9)->SetFemaleShapeBank();
    GetChild<UserShapeSelectControlPane>(10)->SetFemaleShapeBank();
    GetChild<UserShapeSelectControlPane>(11)->SetFemaleShapeBank();
}

// UID:00043T | by-memory/0x0052b650-0x0052b724.NewUserDialogPane2OpenNexonclubRegistrationOrSendCharacterRequest.md | Completion:93 | Confidence:94
#include "NewUserDialogPane2.h"
#include "../util/FunctionObjects.h"
#include "../util/StringBase.h"
#include "../ui/dialogs/NexonclubRegistrationDialog.h"

void NewUserDialogPane2::OpenNexonclubRegistrationOrSendCharacterRequest(
    bool openRegistration)
{
    if (!openRegistration) {
        SendCreateCharacterRequest();
        return;
    }

    typedef mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
        RegistrationString;
    typedef void (NewUserDialogPane2::*RegistrationResultCallback)(
        const RegistrationString &);

    FunctionObjectT<const RegistrationString &> *callback =
        new PlainMemberFunctionObjectT<
            RegistrationResultCallback,
            NewUserDialogPane2,
            const RegistrationString &>(
                this,
                &NewUserDialogPane2::OnNexonclubRegistrationResult);

    new NexonclubRegistrationDialog(
        g_pLanguageMan->GetLocalizedString(227),
        callback);
}

// UID:00043U | by-memory/0x0052b730-0x0052b75c.NewUserDialogPane2OnNexonclubRegistrationResult.md | Completion:92 | Confidence:94
void NewUserDialogPane2::OnNexonclubRegistrationResult(
    const mystr::StringBase<
        wchar_t,
        mystr::mychar_traits<wchar_t> > &accountName)
{
    if (!accountName.empty()) {
        m_nexonclubAccountName = accountName;
    }

    SendCreateCharacterRequest();
}

// UID:00043V | by-memory/0x0052b760-0x0052b88c.NewUserDialogPane2OnControlCommand.md | Completion:88 | Confidence:90
void NewUserDialogPane2::OnControlCommand(int controlIndex, int)
{
    switch (controlIndex)
    {
    case 4:
        SelectMaleMode();
        return;

    case 5:
        SelectFemaleMode();
        return;

    case 6:
        ShiftShapesLeft();
        SetHoverControl(8);
        return;

    case 7:
        ShiftShapesRight();
        SetHoverControl(8);
        return;

    case 8:
    case 9:
    case 10:
    case 11:
        SelectShapeSlot(controlIndex - 8);
        return;

    case 12:
    case 13:
        SelectNation(controlIndex - 12);
        return;

    case 14:
    case 15:
    case 16:
    case 17:
        SelectTotem(controlIndex - 14);
        return;

    case 20:
        SubmitCreateUser();
        return;

    case 21:
        Close();
        return;
    }
}

// UID:00043W | by-memory/0x0052b890-0x0052b910.NewUserDialogPane2HandleKeyOrTextEvent.md | Completion:92 | Confidence:94
bool NewUserDialogPane2::HandleKeyOrTextEvent(Event *event)
{
    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        event->m_payload.m_key.m_modifiers);

    if (m_activeControlId >= 8 && m_activeControlId <= 11)
    {
        if ((key == kPaneKeyLeft || key == kPaneKeyUp) &&
            event->m_type == kEventKeyDown)
        {
            ShiftShapesLeft();
            return true;
        }

        if ((key == kPaneKeyRight || key == kPaneKeyDown) &&
            event->m_type == kEventKeyDown)
        {
            ShiftShapesRight();
            return true;
        }
    }

    return DialogPane::HandleKeyOrTextEvent(event);
}

// UID:00043X | by-memory/0x0052b910-0x0052b936.NewUserDialogPane2HandlePacketEvent.md | Completion:93 | Confidence:95
bool NewUserDialogPane2::HandlePacketEvent(Event *event)
{
    const unsigned char *packet = event->m_payload.m_packet.m_data;

    if (packet[0] != 0x02)
    {
        return false;
    }

    return HandleCreateUserReply(packet);
}

// UID:00043Y | by-memory/0x0052b940-0x0052b949.NewUserDialogPane2HandlePointerOrMouseEvent.md | Completion:88 | Confidence:91
bool NewUserDialogPane2::HandlePointerOrMouseEvent(Event *event)
{
    return DialogPane::HandlePointerOrMouseEvent(event);
}

// UID:000441 | by-memory/0x0052b9f0-0x0052bbbc.NewUserDialogPane2SubmitCreateUser.md | Completion:89 | Confidence:90
void NewUserDialogPane2::SubmitCreateUser()
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
        ShowCreateUserAlert(g_pLanguageMan->GetLocalizedString(89));
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

// UID:000443 | by-memory/0x0052bdd0-0x0052bfc2.NewUserDialogPane2SendCreateCharacterRequest.md | Completion:89 | Confidence:90
void NewUserDialogPane2::SendCreateCharacterRequest()
{
    if (g_createUserScreenDimmer == 0) {
        CreateCreateUserScreenDimmer();
    }

    UserShapeSelectControlPane *shapeControl =
        GetShapeSelectControl(8 + m_selectedShapeSlot);
    CreateUserShapePacketData shapeData;
    shapeControl->GetCreateUserShapePacketData(shapeData);

    PacketBuffer packet;
    packet.WriteByte(0x04);
    packet.WriteWord(0x00c8);
    packet.WriteByte(shapeData.shape);
    packet.WriteByte(shapeData.direction);
    packet.WriteByte((unsigned char)(m_selectedNation + 1));
    packet.WriteByte((unsigned char)m_selectedTotem);
    packet.WriteLengthPrefixedMbcString(m_nexonclubAccountName.c_str());

    g_packetSender->QueueAndSendPacket(packet.Data(), packet.SizeWithoutTerminator());
}

// UID:000444 | by-memory/0x0052bfd0-0x0052c325.NewUserDialogPane2HandleCreateUserReply.md | Completion:89 | Confidence:90
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

bool NewUserDialogPane2::HandleCreateUserReply(const unsigned char *packet)
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

// UID:000442 | by-memory/0x0052bbc0-0x0052bdc5.NewUserDialogPane2SendCreateAccountRequest.md | Completion:88 | Confidence:90
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

// UID:00009E | by-class\NewUserDialogPane2.md | Completion:93 | Confidence:95 | Empty Emitter Marker
