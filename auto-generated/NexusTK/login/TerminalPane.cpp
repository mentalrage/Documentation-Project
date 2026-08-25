// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OI
// Source by-file doc: by-file/TerminalPane.md
// UID:0000EG | by-class/TerminalPane.md | Completion:92 | Confidence:94
class SocketPacket;
class TerminalPane;

extern TerminalPane *g_pTerminalPane;

class TerminalPane : public DialogPane,
                     public Singleton<TerminalPane>
{
public:
    TerminalPane();

    virtual ~TerminalPane()
    {
    }

    virtual void OnClose();
    virtual char ParseTerminalStream(SocketPacket *packet);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

    void OnReconnectOrLeave(unsigned long decision);

private:
    int m_terminalParserState;
};



// UID:0004W3 | by-memory/0x0062dddc-0x0062dde4.TerminalPaneModemResetCommandLiteral.md | Completion:91 | Confidence:94
// The "ATZ\n\r" bytes are emitted by TerminalPane configured-serial-connect source uses.
// Do not emit a duplicate standalone character array for this pooled literal range.

// UID:0004W6 | by-memory/0x0062ddfc-0x0062de34.TerminalPaneStreamParserFormatStrings.md | Completion:92 | Confidence:94
// The registry-escape and Telnet negotiation literals are emitted by TerminalPane::ParseTerminalStream().
// Do not emit duplicate standalone arrays for this source-declared/generated-binary literal range.




// UID:0000SF | by-global/g_pTerminalPane.md | Completion:88 | Confidence:91
class TerminalPane;

TerminalPane *g_pTerminalPane = 0;


// UID:0001JC | by-memory/0x0058b130-0x0058b44b.TerminalPaneStreamParser.md | Completion:88 | Confidence:90
char TerminalPane::ParseTerminalStream(SocketPacket *packet)
{
    if (packet->length <= 0) {
        return 1;
    }

    for (int byteIndex = 0; byteIndex < packet->length; ++byteIndex) {
        const unsigned char value = packet->data[byteIndex];

        switch (m_terminalParserState) {
        case 0:
            if (value == 0x07) {
                putc(0x07, stderr);
            } else if (value == 0x1b) {
                if (strncmp(reinterpret_cast<const char *>(packet->data + 2),
                            "%I\n</RunRegistry=",
                            0x11) == 0) {
                    return 1;
                }
                m_terminalParserState = 1;
            } else if (value == 0xff) {
                m_terminalParserState = 4;
            }
            break;

        case 1:
            if (value == '(' || value == ')' || value == '*' || value == '+') {
                m_terminalParserState = 3;
            } else if (value == 'S') {
                if (!g_pConfig->terminalParserRandomGate || rand() >= 0x1fff) {
                    m_terminalParserState = 6;
                    g_packetSender->SetSocketConnectionFlag(1);
                }
            } else if (value == 'C') {
                if (!g_pConfig->terminalParserRandomGate || rand() >= 0x1fff) {
                    m_terminalParserState = 6;
                    g_packetSender->SetSocketConnectionFlag(0);
                }
            } else {
                m_terminalParserState = 0;
            }
            break;

        case 3:
            m_terminalParserState = 0;
            break;

        case 4:
            m_terminalParserState = (value == 0xfd) ? 5 : 0;
            break;

        case 5: {
            char response[64];
            if (value == 0x18) {
                sprintf_s(response, sizeof(response), "%c%c%c%c%c%c",
                          0xff, 0xfb, 0x18, 0xff, 0xfa, 0x18);
                g_packetSender->QueueTransportStringCommand(response);
                g_packetSender->SendSingleByteCommand(0);
                sprintf_s(response, sizeof(response), "dumb%c%c", 0xff, 0xf0);
            } else {
                sprintf_s(response, sizeof(response), "%c%c%c",
                          0xff, 0xfc, value);
            }
            g_packetSender->QueueTransportStringCommand(response);
            m_terminalParserState = 0;
            break;
        }

        case 6: {
            g_packetSender->PostSocketModeByteCommand(0);
            g_packetSender->WaitForQueueDrain();
            OnDestroy();
            OnHide();

            MainMenuPane *mainMenuPane = new MainMenuPane(1);
            (void)mainMenuPane;

            g_pSoundManager->PlaySample(0x191, 100);

            char outgoingPacket[128];
            sprintf_s(outgoingPacket, sizeof(outgoingPacket), "baram");
            g_packetSender->QueueAndSendPacket(outgoingPacket, 5);
            g_packetSender->SendPositionUpdate();
            CloseDialog();
            return 1;
        }

        default:
            break;
        }
    }

    return 1;
}

// UID:0001JD | by-memory/0x0058b620-0x0058b64f.TerminalPaneReconnectLeaveCallback.md | Completion:91 | Confidence:94
void TerminalPane::OnReconnectOrLeave(unsigned long decision)
{
    if (decision != 0) {
        ScheduleTimer(0, 0, 0, 0);
        return;
    }

    g_pApplication->RequestExit();
}

// UID:0003GS | by-memory\0x0062da0c-0x0062da10.TerminalPaneRttiLocatorPointer.md | Completion:85 | Confidence:90 | Empty Emitter Marker

// UID:0003DO | by-memory\0x0062da10-0x0062daac.TerminalPaneVtableData.md | Completion:92 | Confidence:94 | Empty Emitter Marker

// UID:0000EH | by-class\TerminalSetupPane.md | Completion:85 | Confidence:88 | Empty Emitter Marker

// UID:0003DP | by-memory\0x0062daac-0x0062db48.TerminalSetupPaneVtableData.md | Completion:87 | Confidence:92 | Empty Emitter Marker

// UID:0003GU | by-memory\0x0062de34-0x0062dee8.TerminalSetupPaneResourceStrings.md | Completion:87 | Confidence:92 | Empty Emitter Marker

// UID:0001JB | by-memory\0x0058af50-0x0058c350.TerminalPaneAndSetup.md | Completion:90 | Confidence:92 | Empty Emitter Marker

// UID:0003G3 | by-memory\0x00622f1c-0x00622f28.SharedLeaveWideString.md | Completion:89 | Confidence:94 | Empty Emitter Marker

// UID:0003G4 | by-memory\0x00622f28-0x00622f3c.SharedReconnectWideString.md | Completion:89 | Confidence:94 | Empty Emitter Marker

// UID:0003G7 | by-memory\0x00622f4c-0x00622f54.SharedBaramPacketLiteral.md | Completion:89 | Confidence:94 | Empty Emitter Marker
