// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OU
// Source by-file doc: by-file/TimerPane.md
// UID:0000F3 | by-class/TimerPane.md | Completion:91 | Confidence:93
enum TimerDisplayFormat
{
    kTimerDisplaySeconds = 0,
    kTimerDisplayMinutesSeconds = 1,
    kTimerDisplayHoursMinutesSeconds = 2
};

enum TimerMode
{
    kTimerModeStatic = 0,
    kTimerModeCountUp = 1,
    kTimerModeCountDown = 2,
    kTimerModeInactive = 3
};

class TimerPane : public Pane
{
public:
    TimerPane(int x, int y, TimerDisplayFormat displayFormat);
    virtual ~TimerPane();

    void SetTimer(TimerMode mode, unsigned int seconds);

protected:
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnPaint();

private:
    static Point GetDisplaySize(TimerDisplayFormat displayFormat);
    void DrawDigit(int x, int y, short frameIndex);
    void UpdateDisplaySeconds();

    __time64_t m_startTime;
    __time64_t m_endTime;
    TimerDisplayFormat m_displayFormat;
    int m_positionX;
    int m_positionY;
    TimerMode m_timerMode;
    unsigned int m_displaySeconds;
};

extern TimerPane *g_pTimerPane;

// UID:0004MG | by-memory/0x005986e0-0x00598841.TimerPaneConstructor.md | Completion:90 | Confidence:93
TimerPane::TimerPane(int x, int y, TimerDisplayFormat displayFormat)
    : Pane(1),
      m_displayFormat(displayFormat),
      m_positionX(x),
      m_positionY(y),
      m_timerMode(kTimerModeInactive)
{
    g_pTimerPane = this;

    const Point displaySize = GetDisplaySize(displayFormat);
    RectBounds bounds;

    InitRectBounds(&bounds,
                   x,
                   y,
                   x + displaySize.x,
                   y + displaySize.y);
    AddToLayer(&bounds, 0, 0, g_pStatusPaneLayer);
    SetPaneOrder(0, 0);

    InitRectBounds(&bounds, 0, 0, displaySize.x, displaySize.y);
    UpdateRenderRegion(&bounds);

    _time64(&m_startTime);
    ScheduleTimer(0, 100, 0, 0);
}

// UID:0004MH | by-memory/0x00598850-0x00598878.TimerPaneDestructor.md | Completion:90 | Confidence:93
TimerPane::~TimerPane()
{
    g_pTimerPane = 0;
}

// UID:0004MI | by-memory/0x00598880-0x005988f6.TimerPaneSetTimer.md | Completion:90 | Confidence:93
void TimerPane::SetTimer(TimerMode mode, unsigned int seconds)
{
    m_timerMode = mode;
    m_displaySeconds = seconds;
    _time64(&m_startTime);
    UpdateDisplaySeconds();
    m_endTime = m_startTime + seconds;
}

// UID:0004MJ | by-memory/0x00598900-0x00598959.TimerPaneOnTimer.md | Completion:90 | Confidence:93
bool TimerPane::OnTimer(int timerId, int arg0, int arg1)
{
    __time64_t currentTime;
    _time64(&currentTime);

    if (m_endTime > currentTime) {
        InvalidateRect(0);
        ScheduleTimer(0, 100, 0, 0);
    } else {
        MarkForDeletion();
    }

    return true;
}

// UID:0004MK | by-memory/0x00598960-0x00598ae3.TimerPaneOnPaint.md | Completion:90 | Confidence:93
void TimerPane::OnPaint()
{
    m_drawMode = 0;
    SetDrawColor(0);
    FillRect(&m_bounds);

    UpdateDisplaySeconds();

    const unsigned int hours = m_displaySeconds / 3600;
    const unsigned int minutes = (m_displaySeconds % 3600) / 60;
    const unsigned int seconds = m_displaySeconds % 60;
    int digitX = 0;

    switch (m_displayFormat) {
    case kTimerDisplayHoursMinutesSeconds:
        DrawDigit(digitX, m_positionY, static_cast<short>(hours / 10));
        digitX += 35;
        DrawDigit(digitX, m_positionY, static_cast<short>(hours % 10));
        digitX += 35;
        DrawDigit(digitX, m_positionY, 10);
        digitX += 35;
        // Fall through.
    case kTimerDisplayMinutesSeconds:
        DrawDigit(digitX, m_positionY, static_cast<short>(minutes / 10));
        digitX += 35;
        DrawDigit(digitX, m_positionY, static_cast<short>(minutes % 10));
        digitX += 35;
        DrawDigit(digitX, m_positionY, 10);
        digitX += 35;
        // Fall through.
    case kTimerDisplaySeconds:
        DrawDigit(digitX, m_positionY, static_cast<short>(seconds / 10));
        digitX += 35;
        DrawDigit(digitX, m_positionY, static_cast<short>(seconds % 10));
        break;
    }
}

// UID:0004ML | by-memory/0x00598af0-0x00598b3e.TimerPaneGetDisplaySizeRaw.md | Completion:89 | Confidence:91
Point TimerPane::GetDisplaySize(TimerDisplayFormat displayFormat)
{
    int digitCount;

    switch (displayFormat) {
    case kTimerDisplaySeconds:
        digitCount = 2;
        break;
    case kTimerDisplayMinutesSeconds:
        digitCount = 5;
        break;
    case kTimerDisplayHoursMinutesSeconds:
        digitCount = 8;
        break;
    }

    Point displaySize;
    displaySize.y = 70;
    displaySize.x = digitCount * 35;
    return displaySize;
}

// UID:0004MM | by-memory/0x00598b40-0x00598bd4.TimerPaneDrawDigit.md | Completion:90 | Confidence:93
void TimerPane::DrawDigit(int x, int y, short frameIndex)
{
    EPFTileContext tileContext;

    if (g_useEpfAssets == 1) {
        g_pEPFLib->LoadFrame(L"NUMBER.EPF", frameIndex, &tileContext);
    } else {
        g_pEPFLib->LoadFrame(L"NUMBER.EPD", frameIndex, &tileContext);
    }

    RectBounds destination = tileContext.m_bounds;
    destination.Offset(x, y);
    g_pfnBlitSprite(this,
                    &tileContext,
                    &tileContext.m_bounds,
                    &destination,
                    1,
                    0,
                    0);
}

// UID:0004MN | by-memory/0x00598be0-0x00598c2c.TimerPaneUpdateDisplaySecondsRaw.md | Completion:89 | Confidence:91
void TimerPane::UpdateDisplaySeconds()
{
    __time64_t currentTime;
    _time64(&currentTime);

    if (m_timerMode == kTimerModeCountUp) {
        m_displaySeconds = static_cast<unsigned int>(currentTime - m_startTime);
    } else if (m_timerMode == kTimerModeCountDown) {
        m_displaySeconds = static_cast<unsigned int>(m_endTime - currentTime);
    }
}

// UID:0000SJ | by-global/g_pTimerPane.md | Completion:89 | Confidence:93
TimerPane *g_pTimerPane = 0;
