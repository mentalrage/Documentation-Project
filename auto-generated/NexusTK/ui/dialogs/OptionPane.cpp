// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M7
// Source by-file doc: by-file/OptionPane.md
// UID:00003D | by-class/CScrollBarBackPane.md | Completion:92 | Confidence:94
// UID:0004Y8 | by-memory/0x0053fea0-0x0053fed2.CScrollBarBackPaneConstructor.md | Completion:93 | Confidence:94
CScrollBarBackPane::CScrollBarBackPane()
    : Pane(true)
{
}

// UID:0004Y9 | by-memory/0x0053fee0-0x0053feff.CScrollBarBackPaneOrdinaryDestructor.md | Completion:92 | Confidence:94
CScrollBarBackPane::~CScrollBarBackPane()
{
}

// UID:0004YA | by-memory/0x0053ff00-0x0053ff8d.CScrollBarBackPaneOnPaint.md | Completion:94 | Confidence:94
void CScrollBarBackPane::OnPaint()
{
    MoveTo(0, 2);
    g_pfnDrawLineDelta(this, 4, 0);

    MoveTo(7, 2);
    g_pfnDrawLineDelta(this, 87, 0);
    MoveTo(8, 1);
    g_pfnDrawLineDelta(this, 85, 0);
    MoveTo(8, 3);
    g_pfnDrawLineDelta(this, 85, 0);

    MoveTo(98, 2);
    g_pfnDrawLineDelta(this, 4, 0);
    MoveTo(100, 0);
    g_pfnDrawLineDelta(this, 0, 4);
}

// UID:0001E3 | by-memory/0x00542680-0x005426d5.CScrollBarBackPaneDestructor.md | Completion:90 | Confidence:94
// Emitted code for this range is covered by [UID:00003D][CScrollBarBackPane](by-class/CScrollBarBackPane.md) CScrollBarBackPane.
// MSVC regenerates this scalar deleting destructor wrapper from the virtual destructor and Pane base layout.

// UID:0003LR | by-memory/0x00621018-0x006210a0.CScrollBarBackPaneVtableData.md | Completion:90 | Confidence:94
// CScrollBarBackPane RTTI/vtable bytes are compiler-generated from the class virtual method set; no handwritten table source is emitted.

// UID:000097 | by-class/NewOptionPane.md | Completion:87 | Confidence:89
// UID:0001DW | by-memory/0x0053ff90-0x00541b2b.NewOptionPane.md | Completion:87 | Confidence:88
[[No Children Attached]]

// UID:0003NN | by-memory/0x00540db0-0x00540e4b.NewOptionPaneHandleServerOptionError.md | Completion:88 | Confidence:90
bool NewOptionPane::OnServerOptionError(const PacketEvent *event)
{
    const unsigned char *payload = event->payload;

    if (payload[0] != 0x21)
        return false;

    AlertPane *alert = CreateAlertPane(624);
    if (alert != 0)
        alert->ShowMessage(GetLocalizedString(61), this);

    return true;
}

// UID:0003NP | by-memory/0x00540ef0-0x00540f4d.NewOptionPaneVisibleOptionHitTest.md | Completion:88 | Confidence:91
// Raw retained NewOptionPane visible-option hit-test body at 0x00540ef0 is not emitted as a source helper yet.
// Current MCP reports no function record and no inbound xref/pointer route; NewOptionPane::OnMouseClick contains the live inline-equivalent scan.

// UID:0003NQ | by-memory/0x00540f50-0x00540fdf.NewOptionPaneApplyServerOptions.md | Completion:87 | Confidence:90
// Raw retained NewOptionPane server-option apply body at 0x00540f50 is not emitted as a source helper yet.
// Current MCP reports no function record and no inbound xref/pointer route; payload and Config field declarations are not synchronized for a callable source method.

// UID:0003NR | by-memory/0x00540ff0-0x0054103a.NewOptionPaneRefreshVolumeDisplay.md | Completion:87 | Confidence:90
// Raw retained NewOptionPane volume-display refresh body at 0x00540ff0 is not emitted as a source helper yet.
// MCP session 9600ec5b reports no IDA function record and no inbound xref/pointer route; ApplyVolumeSettings and OnVolumeChanged carry the live modeled volume paths.


// UID:00009V | by-class/OptionPane.md | Completion:87 | Confidence:88
// UID:00040F | by-memory/0x0053d820-0x0053dd4f.OptionPaneConstructor.md | Completion:88 | Confidence:90
OptionPane::OptionPane()
    : DialogPane(L"Option", 3, true)
{
    m_serverOptionBytes[4] = g_pConfig->m_soundEffectsEnabled;

    LoadOptionDialogResources(g_pOptionPaneDlgOptEpd);
    CreateLegacyOptionControls();

    SetOptionChecked(2, !g_pSoundManager->IsMusicDisabled());
    SetOptionChecked(3, !g_pSoundManager->IsSoundEffectsDisabled());
    SetOptionChecked(6, !g_pIconsPane->IsShowingAllIcons());
    SetOptionChecked(8, g_pConfig->m_mapMovementStatusOption == 0);
    SetOptionChecked(9, g_pConfig->m_doubleClick == 0);
    SetOptionChecked(10, g_pConfig->m_shadow == 0);
    SetOptionChecked(11, g_pConfig->m_seeThrough == 0);
    SetOptionChecked(12, g_pConfig->m_sayWithEnter == 0);
    SetOptionChecked(13, g_pConfig->m_hearEmotions == 0);
    SetOptionChecked(14, g_pConfig->m_staticObjectTransparencyEnabled == 0);
    SetOptionChecked(15, g_pConfig->m_mapEffect == 0);

    AddLegacyOptionButtons();
    FinishDialogLayout();
    OptionPaneSendOptionPacket11B(0);
}

// UID:00040G | by-memory/0x0053dd50-0x0053dd6f.OptionPaneDestructor.md | Completion:87 | Confidence:90
OptionPane::~OptionPane()
{
}

// UID:00040H | by-memory/0x0053ddb0-0x0053e191.OptionPaneOnOptionCommand.md | Completion:87 | Confidence:90
void OptionPane::OnOptionCommand(unsigned int commandId, ControlPane *sender)
{
    (void)sender;

    switch (commandId) {
    case 1:
        ApplyLegacyOptionSelections();
        break;

    case 3:
        OptionPaneSendOptionPacket11BSubcommand63(0x0d, IsOptionChecked(3));
        break;

    case 4:
        SendServerOptionIfChanged(4, 1, 5);
        break;

    case 5:
        SendServerOptionIfChanged(5, 0, 6);
        break;

    case 7:
        SendServerOptionIfChanged(7, 2, 4);
        break;

    case 8:
        SendServerOptionIfChanged(8, 3, 9);
        break;

    case 16:
        new SpellMacroDialog;
        break;

    case 17:
        new MacroDialog;
        break;

    case 18:
        new FriendListDialog;
        break;

    case 19:
        new ProfileDialog;
        break;
    }
}

// UID:0001DP | by-memory/0x0053e1e0-0x0053e377.OptionPaneServerOptionResponse.md | Completion:90 | Confidence:90
bool OptionPane::OnServerOptionResponse(const PacketEvent *event)
{
    const unsigned char *payload = event->payload;

    switch (payload[0]) {
    case 0x21:
        ShowLocalizedAlert(61);
        return true;

    case 0x23:
        ApplyServerOptionAvailability(payload);
        return true;
    }

    return false;
}

// UID:00040K | by-memory/0x0053e420-0x0053e520.OptionPaneApplyServerOptionStates.md | Completion:88 | Confidence:89
bool OptionPane::ApplyServerOptionAvailability(const unsigned char *payload)
{
    RadioGroupControlPane *control;

    m_serverOptionState[0] = ReadPacketByte(payload + 1);
    m_serverOptionState[1] = ReadPacketByte(payload + 2);
    m_serverOptionState[2] = ReadPacketByte(payload + 3);
    m_serverOptionState[3] = ReadPacketByte(payload + 4);
    m_serverOptionState[4] = ReadPacketByte(payload + 5);

    control = static_cast<RadioGroupControlPane *>(m_controlManager->GetControl(5));
    control->SetSelectedIndex(m_serverOptionState[0] == 0);

    control = static_cast<RadioGroupControlPane *>(m_controlManager->GetControl(4));
    control->SetSelectedIndex(m_serverOptionState[1] == 0);

    control = static_cast<RadioGroupControlPane *>(m_controlManager->GetControl(7));
    control->SetSelectedIndex(m_serverOptionState[2] == 0);

    control = static_cast<RadioGroupControlPane *>(m_controlManager->GetControl(8));
    control->SetSelectedIndex(m_serverOptionState[3] == 0);

    control = static_cast<RadioGroupControlPane *>(m_controlManager->GetControl(3));
    control->SetSelectedIndex(m_serverOptionState[4] == 0);

    return true;
}


// UID:0001DQ | by-memory/0x0053e380-0x0053e3c1.OptionPaneSendOptionPacket11B.md | Completion:87 | Confidence:90
static void OptionPaneSendOptionPacket11B(unsigned char optionCode)
{
    unsigned char packet[4] = {};
    *reinterpret_cast<unsigned short *>(packet) = 0x011b;
    packet[2] = optionCode;
    g_packetSender->Send(packet, 3);
}

// UID:00040J | by-memory/0x0053e3d0-0x0053e41b.OptionPaneSendOptionPacket11BSubcommand63.md | Completion:88 | Confidence:89
static void OptionPaneSendOptionPacket11BSubcommand63(unsigned char optionCode, unsigned char selectedIndex)
{
    unsigned char packet[6];
    *reinterpret_cast<unsigned short *>(packet) = 0x011b;
    packet[2] = 0x63;
    packet[3] = optionCode;
    packet[4] = selectedIndex;
    packet[5] = 0;

    g_packetSender->QueueAndSendPacket(packet, 5);
}

// UID:0001DY | by-memory/0x00540e50-0x00540e91.SendOptionPacket11B.md | Completion:89 | Confidence:91
static void SendOptionPacket11B(unsigned char optionCode)
{
    unsigned char packet[4] = {};

    *reinterpret_cast<unsigned short *>(packet) = 0x011b;
    packet[2] = optionCode;

    g_packetSender->QueueAndSendPacket(packet, 3);
}

// UID:0003NO | by-memory/0x00540ea0-0x00540ee8.NewOptionPaneSendOptionPacket11BSubcommand63.md | Completion:88 | Confidence:89
static void NewOptionPaneSendOptionPacket11BSubcommand63(unsigned char optionCode, unsigned char selectedIndex)
{
    unsigned char packet[6];
    *reinterpret_cast<unsigned short *>(packet) = 0x011b;
    packet[2] = 0x63;
    packet[3] = optionCode;
    packet[4] = selectedIndex;
    packet[5] = 0;

    g_packetSender->QueueAndSendPacket(packet, 5);
}

// UID:0003NS | by-memory/0x00541040-0x00541114.SendLowHighDisplayModeOption.md | Completion:88 | Confidence:90
static void SendLowHighDisplayModeOption(unsigned char displayMode)
{
    g_pConfig->m_requestedDisplayMode = displayMode;
    if (g_pConfig->m_requestedDisplayMode == 0)
        ResetDisplayEffects(g_pInterfaceEffects);

    g_pConfig->m_shadowDisplayMode = displayMode;
    g_pConfig->m_displayModeMirror = displayMode;

    const bool lowChanged = (g_pConfig->m_serverLowDisplayMode != displayMode);
    const bool highChanged = (g_pConfig->m_serverHighDisplayMode != displayMode);
    if (!lowChanged && !highChanged)
        return;

    unsigned char packet[5] = {};
    unsigned int packetSize = 2;

    packet[0] = 0x1b;
    packet[1] = static_cast<unsigned char>((lowChanged ? 1 : 0) + (highChanged ? 1 : 0));

    if (lowChanged)
        packet[packetSize++] = 5;
    if (highChanged)
        packet[packetSize++] = 6;

    g_packetSender->QueueAndSendPacket(packet, packetSize);
}

// UID:0001DZ | by-memory/0x00541660-0x005416d0.NewOptionPaneDrawBoldText.md | Completion:88 | Confidence:90
static void DrawOptionPaneSectionHeader(GrafPort *port, const wchar_t *text, int x, int y)
{
    port->SetTextColor(128);
    port->MoveTo(x, y);
    port->DrawText(text, wcslen(text));

    port->MoveTo(x + 1, y);
    port->DrawText(text, wcslen(text));
}

// UID:0001E0 | by-memory/0x005416d0-0x00541853.NewOptionPaneDrawOptionButtonItem.md | Completion:88 | Confidence:90
static void DrawOptionPaneButtonItem(NewOptionPane *pane, short optionIndex, short drawSlot)
{
    OptionEntry *entry = pane->GetOptionEntry(optionIndex);

    if (entry->page != pane->m_activePage && entry->page != 0xff)
        return;

    switch (entry->type)
    {
    case 0:
        pane->DrawButtonFrame(drawSlot, entry->bounds, kOptionButtonPalette);
        break;

    case 1:
        pane->DrawPressedButtonFrame(drawSlot, entry->bounds, kOptionButtonPalette);
        break;

    case 3:
        pane->DrawButtonFrame(drawSlot, entry->bounds, L"BU");
        break;

    case 4:
        pane->DrawButtonFrame(drawSlot, entry->bounds, L"RBUTTON.PAL");
        break;
    }

    pane->SetTextColor(6);
    pane->MoveTo(entry->bounds.left + 19, entry->bounds.top + 13);
    pane->DrawText(entry->label, wcslen(entry->label));

    pane->SetTextColor(128);
    pane->MoveTo(entry->bounds.left + 18, entry->bounds.top + 13);
    pane->DrawText(entry->label, wcslen(entry->label));
}

// UID:00027W | by-memory/0x0066decc-0x0066dee0.OptionPaneLegacySizeWordTable_66DECC.md | Completion:87 | Confidence:88
// Source-shaped legacy option-size word table at 0x0066decc is intentionally not emitted yet.
// Current MCP proves row-0 setter writes and no tail-row refs, but no table reader or setter entry route proves the final declaration grouping.

// UID:0002ZC | by-memory/0x0066dee4-0x0066dee8.OptionPaneDlgOptEpdResourcePointer.md | Completion:90 | Confidence:94
static const wchar_t *const kOptionPaneDialogResourceName = L"DLGOPT.EPD";

// UID:00038E | by-memory\0x00542860-0x00542933.NewOptionPaneScalarDeletingDestructor.md | Completion:89 | Confidence:92 | Empty Emitter Marker

// UID:00038F | by-memory\0x00542940-0x00542995.OptionPaneScalarDeletingDestructor.md | Completion:87 | Confidence:92 | Empty Emitter Marker
