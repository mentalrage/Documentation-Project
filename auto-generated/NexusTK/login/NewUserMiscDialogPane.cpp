// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LX
// Source by-file doc: by-file/NewUserMiscDialogPane.md
// UID:00009F | by-class/NewUserMiscDialogPane.md | Completion:92 | Confidence:94
// NewUserMiscDialogPane emits exact method bodies through child pages.
// UID0004GL, UID0004GN, UID0004GO, UID0004GP, UID0004GQ, UID0004GR, and UID0004GX provide source-ready constructor, ordinary destructor, command, packet-event, key-down, control-help, and create-character-reply bodies; compiler-only destructor lowering and sibling raw packet helpers remain excluded where documented.
// UID:0004GP | by-memory/0x004fc5c0-0x004fc5e6.NewUserMiscDialogPaneHandlePacketEvent.md | Completion:93 | Confidence:95
bool NewUserMiscDialogPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packet =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);

    if (packet[0] != 0x02)
    {
        return false;
    }

    return HandleCreateCharacterReply(packet);
}

// UID:0004GL | by-memory/0x004fb630-0x004fbfcf.NewUserMiscDialogPaneConstructor.md | Completion:88 | Confidence:91
#include "../ui/MainUiGraph.h"

NewUserMiscDialogPane::NewUserMiscDialogPane()
    : DialogPane(L"", -1, true)
{
    RectBounds rect;

    g_pNewUserMiscDialogPane = this;

    InitRectBounds(&rect, 0, 0, 402, 373);
    AddControl(new EPFImageControlPane(L"DLGNEW02.EPD", 0, true, rect, NULL));

    InitRectBounds(&rect, 123, 307, 195, 323);
    AddControl(new ImageButtonControlPane(14, rect));

    InitRectBounds(&rect, 201, 307, 273, 323);
    AddControl(new ImageButtonControlPane(22, rect));

    InitRectBounds(&rect, 172, 49, 196, 72);
    AddControl(new GenderButtonControlPane(0, 2, true, rect));

    InitRectBounds(&rect, 200, 49, 224, 72);
    AddControl(new GenderButtonControlPane(1, 0, false, rect));

    const int shapeCount = g_pNewHumanImageLib->GetHeadCount();
    const int firstShapeIndex = rand() % (shapeCount - 3);

    InitRectBounds(&rect, 80, 78, 139, 154);
    UserShapeSelectControlPane *shapeButton =
        new UserShapeSelectControlPane(static_cast<short>(firstShapeIndex), true, &rect, 1);
    AddControl(shapeButton);
    shapeButton->SetSelected(true);

    InitRectBounds(&rect, 139, 78, 198, 154);
    AddControl(new UserShapeSelectControlPane(static_cast<short>(firstShapeIndex + 1),
                                              true,
                                              &rect,
                                              1));

    InitRectBounds(&rect, 198, 78, 257, 154);
    AddControl(new UserShapeSelectControlPane(static_cast<short>(firstShapeIndex + 2),
                                              true,
                                              &rect,
                                              1));

    InitRectBounds(&rect, 257, 78, 316, 154);
    AddControl(new UserShapeSelectControlPane(static_cast<short>(firstShapeIndex + 3),
                                              true,
                                              &rect,
                                              1));

    InitRectBounds(&rect, 56, 107, 72, 123);
    DirectionButtonControlPane *leftButton = new DirectionButtonControlPane(0, rect);
    AddControl(leftButton);
    if (firstShapeIndex == 0) {
        leftButton->Disable();
    }

    InitRectBounds(&rect, 325, 107, 341, 123);
    DirectionButtonControlPane *rightButton = new DirectionButtonControlPane(1, rect);
    AddControl(rightButton);
    if (firstShapeIndex == shapeCount - 4) {
        rightButton->Disable();
    }

    srand((unsigned)_time64(0));

    const int genderChoice = rand() % 2;

    InitRectBounds(&rect, 145, 180, 196, 231);
    SelectBoxControlPane *maleBox = new SelectBoxControlPane(&rect);
    AddControl(maleBox);
    maleBox->SetSelected(genderChoice == 0);

    InitRectBounds(&rect, 200, 180, 251, 231);
    SelectBoxControlPane *femaleBox = new SelectBoxControlPane(&rect);
    AddControl(femaleBox);
    femaleBox->SetSelected(genderChoice != 0);

    const int styleChoice = rand() % 4;

    InitRectBounds(&rect, 90, 235, 141, 286);
    SelectBoxControlPane *styleBox0 = new SelectBoxControlPane(&rect);
    AddControl(styleBox0);
    styleBox0->SetSelected(styleChoice == 0);

    InitRectBounds(&rect, 146, 235, 197, 286);
    SelectBoxControlPane *styleBox1 = new SelectBoxControlPane(&rect);
    AddControl(styleBox1);
    styleBox1->SetSelected(styleChoice == 1);

    InitRectBounds(&rect, 200, 235, 251, 286);
    SelectBoxControlPane *styleBox2 = new SelectBoxControlPane(&rect);
    AddControl(styleBox2);
    styleBox2->SetSelected(styleChoice == 2);

    InitRectBounds(&rect, 255, 235, 306, 286);
    SelectBoxControlPane *styleBox3 = new SelectBoxControlPane(&rect);
    AddControl(styleBox3);
    styleBox3->SetSelected(styleChoice == 3);

    SetHoverControl(5);
    SetFocusedControl(1);
    SetPendingControl(2);
    SetBackgroundResource(L"DLGNEW02.EPD", 0);
    SetMode(1);

    InitRectBounds(&rect, 238, 107, 640, 480);
    Create(rect, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    Show(false, g_pMainMenuPane);
    SlideOpen();
}

// UID:0004GN | by-memory/0x004fbfd0-0x004fc00f.NewUserMiscDialogPaneRawCleanupIsland.md | Completion:90 | Confidence:94
NewUserMiscDialogPane::~NewUserMiscDialogPane()
{
    delete g_pScreenDimmer;
    g_pNewUserMiscDialogPane = 0;
}

// UID:0004GO | by-memory/0x004fc010-0x004fc57e.NewUserMiscDialogPaneHandleCommand.md | Completion:90 | Confidence:92
namespace
{
    enum NewUserMiscCommandId
    {
        kCommandAccept = 1,
        kCommandCancel = 2,
        kCommandMaleMode = 3,
        kCommandFemaleMode = 4,
        kCommandShape0 = 5,
        kCommandShape1 = 6,
        kCommandShape2 = 7,
        kCommandShape3 = 8,
        kCommandPreviousShape = 9,
        kCommandNextShape = 10,
        kCommandMaleBox = 11,
        kCommandFemaleBox = 12,
        kCommandStyle0 = 13,
        kCommandStyle1 = 14,
        kCommandStyle2 = 15,
        kCommandStyle3 = 16
    };

    const unsigned char kCreateMiscCharacterOpcode = 0x04;
    const unsigned char kCancelCreateCharacterOpcode = 0x15;
    const short kCreateMiscCharacterPacketSize = 5;
    const short kCancelCreateCharacterPacketSize = 1;
    const int kCreateMiscDimmerLevel = 5;
}

void NewUserMiscDialogPane::HandleCommand(int commandId, int notifyCode)
{
    (void)notifyCode;

    DirectionButtonControlPane *previousShapeButton =
        static_cast<DirectionButtonControlPane *>(m_controlManager->GetControl(9));
    DirectionButtonControlPane *nextShapeButton =
        static_cast<DirectionButtonControlPane *>(m_controlManager->GetControl(10));

    GenderButtonControlPane *maleModeButton =
        static_cast<GenderButtonControlPane *>(m_controlManager->GetControl(3));
    GenderButtonControlPane *femaleModeButton =
        static_cast<GenderButtonControlPane *>(m_controlManager->GetControl(4));

    UserShapeSelectControlPane *shape0 =
        static_cast<UserShapeSelectControlPane *>(m_controlManager->GetControl(5));
    UserShapeSelectControlPane *shape1 =
        static_cast<UserShapeSelectControlPane *>(m_controlManager->GetControl(6));
    UserShapeSelectControlPane *shape2 =
        static_cast<UserShapeSelectControlPane *>(m_controlManager->GetControl(7));
    UserShapeSelectControlPane *shape3 =
        static_cast<UserShapeSelectControlPane *>(m_controlManager->GetControl(8));

    SelectBoxControlPane *maleBox =
        static_cast<SelectBoxControlPane *>(m_controlManager->GetControl(11));
    SelectBoxControlPane *femaleBox =
        static_cast<SelectBoxControlPane *>(m_controlManager->GetControl(12));
    SelectBoxControlPane *style0 =
        static_cast<SelectBoxControlPane *>(m_controlManager->GetControl(13));
    SelectBoxControlPane *style1 =
        static_cast<SelectBoxControlPane *>(m_controlManager->GetControl(14));
    SelectBoxControlPane *style2 =
        static_cast<SelectBoxControlPane *>(m_controlManager->GetControl(15));
    SelectBoxControlPane *style3 =
        static_cast<SelectBoxControlPane *>(m_controlManager->GetControl(16));

    switch (commandId)
    {
    case kCommandAccept:
    {
        UserShapeSelectControlPane *selectedShape = shape3;
        if (shape0->IsSelected())
            selectedShape = shape0;
        else if (shape1->IsSelected())
            selectedShape = shape1;
        else if (shape2->IsSelected())
            selectedShape = shape2;

        HumanImageRenderParams previewParams;
        selectedShape->BuildPreviewParams(&previewParams);

        unsigned char gender = maleBox->IsSelected() ? 1 : 2;

        unsigned char style = 3;
        if (style0->IsSelected())
            style = 0;
        else if (style1->IsSelected())
            style = 1;
        else if (style2->IsSelected())
            style = 2;

        unsigned char packet[kCreateMiscCharacterPacketSize + 1];
        PacketBufferWriteUInt8(kCreateMiscCharacterOpcode, &packet[0]);
        PacketBufferWriteUInt8(previewParams.shape, &packet[1]);
        PacketBufferWriteUInt8(previewParams.direction, &packet[2]);
        PacketBufferWriteUInt8(gender, &packet[3]);
        PacketBufferWriteUInt8(style, &packet[4]);
        packet[kCreateMiscCharacterPacketSize] = 0;

        g_packetSender->QueueAndSendPacket(packet, kCreateMiscCharacterPacketSize);
        new ScreenDimmer(kCreateMiscDimmerLevel, g_pScreenPane);
        return;
    }

    case kCommandCancel:
    {
        unsigned char packet[kCancelCreateCharacterPacketSize + 1];
        PacketBufferWriteUInt8(kCancelCreateCharacterOpcode, &packet[0]);
        packet[kCancelCreateCharacterPacketSize] = 0;

        g_packetSender->QueueAndSendPacket(packet, kCancelCreateCharacterPacketSize);
        SlideCloseVertical();
        CloseDialog();
        return;
    }

    case kCommandMaleMode:
        shape0->SetMaleShapeBank();
        shape1->SetMaleShapeBank();
        shape2->SetMaleShapeBank();
        shape3->SetMaleShapeBank();
        maleModeButton->SetSelected(true);
        femaleModeButton->SetSelected(false);
        return;

    case kCommandFemaleMode:
        shape0->SetFemaleShapeBank();
        shape1->SetFemaleShapeBank();
        shape2->SetFemaleShapeBank();
        shape3->SetFemaleShapeBank();
        femaleModeButton->SetSelected(true);
        maleModeButton->SetSelected(false);
        return;

    case kCommandShape0:
        shape1->SetSelected(false);
        shape2->SetSelected(false);
        shape3->SetSelected(false);
        return;

    case kCommandShape1:
        shape0->SetSelected(false);
        shape2->SetSelected(false);
        shape3->SetSelected(false);
        return;

    case kCommandShape2:
        shape0->SetSelected(false);
        shape1->SetSelected(false);
        shape3->SetSelected(false);
        return;

    case kCommandShape3:
        shape0->SetSelected(false);
        shape1->SetSelected(false);
        shape2->SetSelected(false);
        return;

    case kCommandPreviousShape:
        if (shape0->StepShapeBackward() == -1)
        {
            shape1->StepShapeBackward();
            shape2->StepShapeBackward();
            shape3->StepShapeBackward();
            previousShapeButton->ClearSelection();
        }
        else
        {
            shape1->StepShapeBackward();
            shape2->StepShapeBackward();
            shape3->StepShapeBackward();
            if (!nextShapeButton->IsSelected())
                nextShapeButton->Select();
        }
        return;

    case kCommandNextShape:
        if (shape3->StepShapeForward() == -1)
        {
            shape0->StepShapeForward();
            shape1->StepShapeForward();
            shape2->StepShapeForward();
            nextShapeButton->ClearSelection();
        }
        else
        {
            shape0->StepShapeForward();
            shape1->StepShapeForward();
            shape2->StepShapeForward();
            if (!previousShapeButton->IsSelected())
                previousShapeButton->Select();
        }
        return;

    case kCommandMaleBox:
        femaleBox->SetSelected(false);
        return;

    case kCommandFemaleBox:
        maleBox->SetSelected(false);
        return;

    case kCommandStyle0:
        style1->SetSelected(false);
        style2->SetSelected(false);
        style3->SetSelected(false);
        return;

    case kCommandStyle1:
        style0->SetSelected(false);
        style2->SetSelected(false);
        style3->SetSelected(false);
        return;

    case kCommandStyle2:
        style0->SetSelected(false);
        style1->SetSelected(false);
        style3->SetSelected(false);
        return;

    case kCommandStyle3:
        style0->SetSelected(false);
        style1->SetSelected(false);
        style2->SetSelected(false);
        return;

    default:
        return;
    }
}

// UID:0004GQ | by-memory/0x004fc5f0-0x004fc77c.NewUserMiscDialogPaneOnKeyDown.md | Completion:89 | Confidence:91
bool NewUserMiscDialogPane::OnKeyDown(KeyEvent *event)
{
    const unsigned char kPreviousShapeKey0 = 0x80;
    const unsigned char kPreviousShapeKey1 = 0x81;
    const unsigned char kNextShapeKey0 = 0x82;
    const unsigned char kNextShapeKey1 = 0x83;
    const unsigned char kEscapeKey = 0x1b;

    ControlPane *previousPageControl = m_controlManager->GetControl(9);
    ControlPane *nextPageControl = m_controlManager->GetControl(10);
    UserShapeSelectControlPane *shapeControl0 =
        static_cast<UserShapeSelectControlPane *>(m_controlManager->GetControl(5));
    UserShapeSelectControlPane *shapeControl1 =
        static_cast<UserShapeSelectControlPane *>(m_controlManager->GetControl(6));
    UserShapeSelectControlPane *shapeControl2 =
        static_cast<UserShapeSelectControlPane *>(m_controlManager->GetControl(7));
    UserShapeSelectControlPane *shapeControl3 =
        static_cast<UserShapeSelectControlPane *>(m_controlManager->GetControl(8));

    const unsigned char key = event->translatedKey;
    if (event->imeState != 0) {
        return true;
    }

    if (event->eventKind == kEventKeyDown &&
        (key == kPreviousShapeKey0 || key == kPreviousShapeKey1))
    {
        if (previousPageControl->IsSelected()) {
            const int edgeResult = shapeControl0->StepShapeBackward();
            shapeControl1->StepShapeBackward();
            shapeControl2->StepShapeBackward();
            shapeControl3->StepShapeBackward();

            if (edgeResult == -1) {
                previousPageControl->ClearSelection();
            } else if (!nextPageControl->IsSelected()) {
                nextPageControl->Select();
            }
        }

        return true;
    }

    if (event->eventKind == kEventKeyDown &&
        (key == kNextShapeKey0 || key == kNextShapeKey1))
    {
        if (!nextPageControl->IsSelected()) {
            return true;
        }

        const int edgeResult = shapeControl3->StepShapeForward();
        shapeControl0->StepShapeForward();
        shapeControl1->StepShapeForward();
        shapeControl2->StepShapeForward();

        if (edgeResult == -1) {
            nextPageControl->ClearSelection();
        } else if (!previousPageControl->IsSelected()) {
            previousPageControl->Select();
        }

        return true;
    }

    if (key == '\r' || key == kEscapeKey) {
        return DialogPane::OnKeyEvent(event);
    }

    return true;
}

// UID:0004GR | by-memory/0x004fc780-0x004fc9e7.NewUserMiscDialogPaneShowControlHelp.md | Completion:89 | Confidence:92
bool NewUserMiscDialogPane::ShowControlHelp(ControlPaneEvent *event)
{
    if (event->type != 4)
        return ControlPane::ShowControlHelp(event);

    int controlIndex = -1;
    const int mouseY = event->y;
    const int mouseX = event->x;

    FindControlAtPoint(mouseY, mouseX, &controlIndex);

    if (g_pSimpleHelpPane != NULL)
        g_pSimpleHelpPane->Close(true);

    int stringId = 178;
    switch (controlIndex)
    {
    case 3:
    case 4:
        stringId = 179;
        break;

    case 5:
    case 6:
    case 7:
    case 8:
        stringId = 180;
        break;

    case 11:
    case 12:
        stringId = 181;
        break;

    case 13:
    case 14:
    case 15:
    case 16:
        stringId = 182;
        break;

    default:
        stringId = 178;
        break;
    }

    new SimpleHelpPane(g_pLanguageMan->GetLocalizedString(stringId),
                       this,
                       mouseX,
                       mouseY,
                       5000);

    return true;
}

// UID:0004GX | by-memory/0x004fcb10-0x004fccee.NewUserMiscDialogPaneHandleCreateCharacterReply.md | Completion:92 | Confidence:94
bool NewUserMiscDialogPane::HandleCreateCharacterReply(const unsigned char *packet)
{
    MemoryMan *memoryMan = GetMemoryMan();
    const unsigned char result = packet[1];

    if (result != 0) {
        if (g_pScreenDimmer != NULL) {
            delete g_pScreenDimmer;

            char narrowText[256];
            wchar_t wideText[256];
            const unsigned int textLength = packet[2];

            memoryMan->MemmoveWrapper(narrowText, packet + 3, textLength);
            narrowText[textLength] = '\0';

            const unsigned char wideLength = static_cast<unsigned char>(
                MultiByteToWideChar(
                    CP_ACP, 0, narrowText, textLength, wideText, 256));
            wideText[wideLength] = L'\0';

            if (wideText[0] != L'\0')
                new AlertPane(wideText, this, kDialogOkButtonText, NULL);
        }

        return true;
    }

    if (g_pScreenDimmer != NULL)
        delete g_pScreenDimmer;

    char narrowText[256];
    wchar_t wideText[256];
    const unsigned int textLength = packet[2];

    memoryMan->MemmoveWrapper(narrowText, packet + 3, textLength);
    narrowText[textLength] = '\0';

    const unsigned char wideLength = static_cast<unsigned char>(
        MultiByteToWideChar(
            CP_ACP, 0, narrowText, textLength, wideText, 256));
    wideText[wideLength] = L'\0';

    if (wideText[0] != L'\0')
        new AlertPane(wideText, this, kDialogOkButtonText, NULL);

    SlideCloseVertical();
    CloseDialog();
    return true;
}

// UID:0002XL | by-memory/0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane.md | Completion:88 | Confidence:90
NewUserMiscDialogPane *g_pNewUserMiscDialogPane;
