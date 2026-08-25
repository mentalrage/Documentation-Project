// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 00036Q
// Source by-file doc: by-file/ScreenFadeOut.md
// UID:0000CA | by-class/ScreenFadeOut.md | Completion:92 | Confidence:94
class ScreenFadeOut : public Pane
{
public:
    ScreenFadeOut(float startAlpha, int duration);
    virtual ~ScreenFadeOut();

    virtual void OnPaint();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    int m_halfSteps;
    float m_fadeStepDelta;
    int m_updatesPerStep;
    float m_currentAlpha;
    int m_isActive;
};

// UID:000395 | by-memory/0x00559e50-0x00559f5e.ScreenFadeOutConstructor.md | Completion:92 | Confidence:94
ScreenFadeOut::ScreenFadeOut(float startAlpha, int duration)
    : Pane(2)
{
    RectBounds bounds;

    m_halfSteps = duration / 2;
    m_isActive = 1;
    m_fadeStepDelta =
        -((1.0f - startAlpha) / static_cast<float>(m_halfSteps));
    m_currentAlpha = 1.0f - m_fadeStepDelta;
    m_updatesPerStep = duration / m_halfSteps;
    ScheduleTimer(0, m_updatesPerStep, 0, 0);
    g_pScreenPane->GetBounds(&bounds);
    AddToLayer(&bounds, 0, NULL, g_pStatusPaneLayer);
}

// UID:000396 | by-memory/0x00559f60-0x0055a003.ScreenFadeOutDestructor.md | Completion:91 | Confidence:94
ScreenFadeOut::~ScreenFadeOut()
{
    RectBounds bounds;

    if (g_pBackPane != NULL) {
        g_pBackPane->GetBounds(&bounds);
        g_pBackPane->InvalidateRect(&bounds);
    } else if (g_pScreenPane != NULL) {
        g_pScreenPane->GetBounds(&bounds);
        g_pScreenPane->InvalidateRect(&bounds);
    }
}

// UID:000397 | by-memory/0x0055a010-0x0055a015.ScreenFadeOutOnTimer.md | Completion:91 | Confidence:94
bool ScreenFadeOut::OnTimer(int timerId, int arg0, int arg1)
{
    return false;
}

// UID:000398 | by-memory/0x0055a020-0x0055a021.ScreenFadeOutOnPaint.md | Completion:91 | Confidence:94
void ScreenFadeOut::OnPaint()
{
}
