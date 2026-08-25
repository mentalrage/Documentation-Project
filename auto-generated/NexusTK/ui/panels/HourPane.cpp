// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JX
// Source by-file doc: by-file/HourPane.md
// UID:000068 | by-class/HourPane.md | Completion:92 | Confidence:94
class HourPane : public Pane, public Singleton<HourPane>
{
public:
    HourPane();
    virtual ~HourPane();

    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnPaint();

private:
    bool UpdateHour(const unsigned char *packetData);

    signed char m_currentHour;
};

extern HourPane *g_pHourPane;

// UID:0004NJ | by-memory/0x004cee60-0x004ceeaf.HourPaneConstructor.md | Completion:92 | Confidence:94
HourPane::HourPane()
    : Pane(1),
      m_currentHour(-1)
{
}

// UID:0004NK | by-memory/0x004ceeb0-0x004ceed9.HourPaneDestructor.md | Completion:92 | Confidence:94
HourPane::~HourPane()
{
}

// UID:0004NL | by-memory/0x004ceee0-0x004cef25.HourPaneHandlePacketEvent.md | Completion:92 | Confidence:94
bool HourPane::HandlePacketEvent(Event *event)
{
    const unsigned char *packetData =
        static_cast<const unsigned char *>(event->m_payload.m_packet.m_data);

    if (packetData[0] != 0x20)
        return false;

    return UpdateHour(packetData);
}

// UID:0004NM | by-memory/0x004cef30-0x004cf009.HourPaneHandlePointerOrMouseEvent.md | Completion:91 | Confidence:93
bool HourPane::HandlePointerOrMouseEvent(Event *event)
{
    const int mouseY = event->m_payload.m_pointer.m_y;
    const int mouseX = event->m_payload.m_pointer.m_x;

    if (event->m_type != kEventRightButtonDown)
        return false;

    if (g_pSimpleHelpPane != NULL)
        delete g_pSimpleHelpPane;

    if (!PointInRect(mouseY, mouseX, &m_bounds))
        return false;

    wchar_t helpText[32];
    swprintf_s(helpText, 32, L"%s : %02d",
               g_pLanguageMan->GetLocalizedString(77),
               m_currentHour);

    new SimpleHelpPane(helpText, this, mouseX, mouseY, 5000);
    return true;
}

// UID:0004NN | by-memory/0x004cf010-0x004cf139.HourPaneOnPaint.md | Completion:92 | Confidence:94
void HourPane::OnPaint()
{
    if (g_useEpfAssets == 1) {
        if (m_currentHour == -1) {
            SetDrawColor(0);
            FillRect(&m_bounds);
            return;
        }

        EPFTileContext tileContext;
        g_pEPFLib->LookupLayoutEntry(
            L"TIME.EPF",
            g_hourFrameTable[(m_currentHour / 2) % 12],
            &tileContext);

        if (tileContext.pixelData != NULL) {
            RenderTileFrame(&tileContext,
                            &tileContext.bounds,
                            &m_bounds,
                            0,
                            L"TIME.PAL",
                            NULL);
        }
        return;
    }

    if (m_currentHour == -1) {
        SetDrawColor(128);
        FillRect(&m_bounds);
        return;
    }

    EPFTileContext tileContext;
    g_pEPFLib->LookupLayoutEntry(
        L"TIME.EPD",
        g_hourFrameTable[(m_currentHour / 2) % 12],
        &tileContext);

    if (tileContext.pixelData != NULL) {
        g_pfnBlitSprite(this,
                        &tileContext,
                        &tileContext.bounds,
                        &m_bounds,
                        0,
                        NULL,
                        NULL);
    }
}

// UID:0004NO | by-memory/0x004cf140-0x004cf173.HourPaneUpdateHourRaw.md | Completion:89 | Confidence:91
bool HourPane::UpdateHour(const unsigned char *packetData)
{
    const signed char hour = static_cast<signed char>(packetData[1]);

    if (m_currentHour != hour) {
        m_currentHour = hour;
        InvalidateRect(&m_bounds);
    }

    return false;
}

// UID:0003BM | by-memory/0x0061b36c-0x0061b444.HourPaneVtableResourceData.md | Completion:92 | Confidence:94
// Emitted code for this range is covered by [UID:000068][HourPane](by-class/HourPane.md).

// UID:0002ZE | by-global/g_hourFrameTable.md | Completion:92 | Confidence:94
static short g_hourFrameTable[12] =
{
    10, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
};

// UID:0000R4 | by-global/g_pHourPane.md | Completion:92 | Confidence:94
HourPane *g_pHourPane = NULL;
// UID:00029I | by-memory/0x0069b418-0x0069b41c.g_pHourPane.md | Completion:92 | Confidence:94
// Emitted code for this range is covered by [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md).

// UID:00027K | by-memory/0x0066db04-0x0066db1c.HourPaneFrameTable.md | Completion:92 | Confidence:94
// Emitted code for this range is covered by [UID:0002ZE][g_hourFrameTable](by-global/g_hourFrameTable.md).
