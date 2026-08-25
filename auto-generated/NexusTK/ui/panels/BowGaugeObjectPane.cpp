// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HU
// Source by-file doc: by-file/BowGaugeObjectPane.md
// UID:0000QA | by-global/g_pBowGaugeObjectPane.md | Completion:92 | Confidence:94
class BowGaugeObjectPane;

BowGaugeObjectPane *g_pBowGaugeObjectPane = 0;

// UID:000011 | by-class/BowGaugeObjectPane.md | Completion:92 | Confidence:94
class BowGaugeObjectPane : public Pane,
                           public Singleton<BowGaugeObjectPane>
{
public:
    BowGaugeObjectPane();
    virtual ~BowGaugeObjectPane() {}

    void StartAnimation(unsigned int startTick);
    void RemovePendingTimers();
    void SetAnimationStartTick(unsigned int startTick);

protected:
    virtual void OnPaint();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    unsigned int m_animationStartTick;
};

typedef char BowGaugeObjectPaneSizeMustBe252[
    sizeof(BowGaugeObjectPane) == 0xfc ? 1 : -1];

extern BowGaugeObjectPane *g_pBowGaugeObjectPane;

// UID:0004VN | by-memory/0x00538bc0-0x00538c0a.BowGaugeObjectPaneConstructor.md | Completion:92 | Confidence:94
BowGaugeObjectPane::BowGaugeObjectPane()
    : Pane(1),
      Singleton<BowGaugeObjectPane>()
{
}

// UID:0004VO | by-memory/0x00538c10-0x00538c3a.BowGaugeObjectPaneStartAnimation.md | Completion:92 | Confidence:94
void BowGaugeObjectPane::StartAnimation(unsigned int startTick)
{
    m_animationStartTick = startTick;
    ScheduleTimer(1, 1, 0, 0);
}

// UID:0001DC | by-memory/0x00538c40-0x00538c4b.BowGaugeObjectPaneRemovePendingTimers.md | Completion:92 | Confidence:94
void BowGaugeObjectPane::RemovePendingTimers()
{
    TimerHandler::RemovePendingTimers();
}

// UID:0004VP | by-memory/0x00538c50-0x00538cfa.BowGaugeObjectPaneOnPaint.md | Completion:92 | Confidence:94
void BowGaugeObjectPane::OnPaint()
{
    RectBounds compositeRect;
    EPFTileContext frame;

    SetDrawColor(0);
    FillRect(&m_visibleBounds);

    if (g_pUserPane->m_nameVisible)
    {
        int frameIndex =
            (timeGetTime() - m_animationStartTick) / 138;
        if (frameIndex > 36)
            frameIndex = 36;

        g_pEPFLib->LookupLayoutEntry(
            L"BGAUGE.EPF", frameIndex, &frame);
        RenderTileFrame(
            &frame,
            &frame.bounds,
            &m_visibleBounds,
            0,
            L"BGAUGE.pal",
            0);
    }

    CompositePixels(&compositeRect);
}

// UID:0004SJ | by-memory/0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick.md | Completion:92 | Confidence:94
void BowGaugeObjectPane::SetAnimationStartTick(unsigned int startTick)
{
    m_animationStartTick = startTick;
}

// UID:0004VQ | by-memory/0x00538d10-0x00538d4b.BowGaugeObjectPaneOnTimer.md | Completion:92 | Confidence:94
bool BowGaugeObjectPane::OnTimer(int, int, int)
{
    InvalidateRect(&m_visibleBounds);
    ScheduleTimer(1, 1, 0, 0);
    return true;
}

// UID:000352 | by-memory/0x006206ac-0x00620734.BowGaugeObjectPaneVtableData.md | Completion:92 | Confidence:94
// Compiler-emitted RTTI/vtable data for BowGaugeObjectPane is regenerated
// from its complete Pane plus Singleton<BowGaugeObjectPane> declaration,
// virtual destructor, OnPaint, OnTimer, and compiler adjustors. Do not emit
// hand-authored ABI arrays or a standalone body for this .rdata range.

// UID:0002YQ | by-memory/0x00620b90-0x00620bc0.BowGaugeResourceStrings.md | Completion:92 | Confidence:94
// The BGAUGE.EPF and BGAUGE.pal literals are emitted by
// BowGaugeObjectPane::OnPaint(). Do not emit duplicate standalone arrays
// for this source-declared/generated-binary .rdata range.
