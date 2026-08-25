// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MT
// Source by-file doc: by-file/ProgressBarControlPane.md
// UID:0000AW | by-class/ProgressBarControlPane.md | Completion:92 | Confidence:93
class ProgressBarControlPane : public ControlPane
{
public:
    ProgressBarControlPane(const RectBounds *bounds, short minValue, short maxValue);

    void SetMinValue(short minValue);
    void SetMaxValue(short maxValue);
    void SetCurrentValue(short value);
    void AddCurrentValue(short delta);

protected:
    virtual void DrawProgressBar();

private:
    enum
    {
        kMaxProgressValue = 30000
    };
};

// UID:000115 | by-memory/0x00494a90-0x00494ae7.ProgressBarControlPaneRangeStartSetter.md | Completion:93 | Confidence:94
void ProgressBarControlPane::SetMinValue(short minValue)
{
    if (minValue < 0)
        minValue = 0;
    else if (minValue > kMaxProgressValue)
        minValue = kMaxProgressValue;

    if (m_rangeStart == minValue)
        return;

    if (m_rangeCurrent < minValue) {
        m_rangeCurrent = minValue;
        InvalidateRect(&m_visibleBounds);
    }

    m_rangeStart = minValue;
    InvalidateRect(&m_visibleBounds);
}

// UID:000117 | by-memory/0x00494af0-0x00494b4b.ProgressBarControlPaneRangeEndSetter.md | Completion:93 | Confidence:94
void ProgressBarControlPane::SetMaxValue(short maxValue)
{
    if (maxValue < 0)
        maxValue = 0;
    else if (maxValue > kMaxProgressValue)
        maxValue = kMaxProgressValue;

    if (m_rangeEnd == maxValue)
        return;

    if (m_rangeCurrent > maxValue) {
        m_rangeCurrent = maxValue;
        InvalidateRect(&m_visibleBounds);
    }

    m_rangeEnd = maxValue;
    InvalidateRect(&m_visibleBounds);
}

// UID:0003N1 | by-memory/0x00494b50-0x00494b77.ProgressBarControlPaneSetCurrentValue.md | Completion:88 | Confidence:91
void ProgressBarControlPane::SetCurrentValue(short value)
{
    if (m_rangeCurrent == value)
        return;

    m_rangeCurrent = value;
    InvalidateRect(&m_visibleBounds);
}

// UID:000119 | by-memory/0x00494c80-0x00494daa.ProgressBarControlPaneConstructor.md | Completion:88 | Confidence:91
ProgressBarControlPane::ProgressBarControlPane(const RectBounds *bounds, short minValue, short maxValue)
    : ControlPane(22, bounds)
{
    if (minValue < 0)
        minValue = 0;
    else if (minValue > kMaxProgressValue)
        minValue = kMaxProgressValue;

    if (m_rangeStart != minValue) {
        if (m_rangeCurrent < minValue) {
            m_rangeCurrent = minValue;
            InvalidateRect(&m_visibleBounds);
        }

        m_rangeStart = minValue;
        InvalidateRect(&m_visibleBounds);
    }

    if (maxValue < 0)
        maxValue = 0;
    else if (maxValue > kMaxProgressValue)
        maxValue = kMaxProgressValue;

    if (m_rangeEnd != maxValue) {
        if (m_rangeCurrent > maxValue) {
            m_rangeCurrent = maxValue;
            InvalidateRect(&m_visibleBounds);
        }

        m_rangeEnd = maxValue;
        InvalidateRect(&m_visibleBounds);
    }

    if (m_rangeCurrent != 0) {
        m_rangeCurrent = 0;
        InvalidateRect(&m_visibleBounds);
    }
}

// UID:00011A | by-memory/0x00494db0-0x00494dde.ProgressBarControlPaneCurrentValueAdder.md | Completion:93 | Confidence:94
void ProgressBarControlPane::AddCurrentValue(short delta)
{
    short value = static_cast<short>(m_rangeCurrent + delta);
    if (m_rangeCurrent == value)
        return;

    m_rangeCurrent = value;
    InvalidateRect(&m_visibleBounds);
}

// UID:00011C | by-memory/0x00494de0-0x00494eb0.ProgressBarControlPaneDrawProgressBar.md | Completion:88 | Confidence:91
void ProgressBarControlPane::DrawProgressBar()
{
    int splitX = m_visibleBounds.left;
    if (m_rangeStart != m_rangeEnd) {
        splitX += ((m_rangeCurrent - m_rangeStart) *
            (m_visibleBounds.right - m_visibleBounds.left)) /
            (m_rangeEnd - m_rangeStart);
    }

    RectBounds filledBounds = m_visibleBounds;
    filledBounds.right = splitX;

    RectBounds emptyBounds = m_visibleBounds;
    emptyBounds.left = splitX;

    m_drawMode = 0;

    SetDrawColor(1);
    FillRect(&filledBounds);

    SetDrawColor(143);
    FillRect(&emptyBounds);

    SetDrawColor(128);
    DrawRectFrame(&m_visibleBounds);
}

// UID:0002OL | by-memory\0x00617b30-0x00617bd4.ProgressBarControlPaneVtableData.md | Completion:89 | Confidence:93 | Empty Emitter Marker

// UID:0001YH | by-type\by-vtable\ProgressBarControlPaneVtables.md | Completion:86 | Confidence:91 | Empty Emitter Marker
