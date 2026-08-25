// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OW
// Source by-file doc: by-file/TransferServerDialogPane.md
// UID:0000F7 | by-class/TransferServerDialogPane.md | Completion:92 | Confidence:94
class TransferServerDialogPane : public Pane,
                                 public Singleton<TransferServerDialogPane>
{
public:
    explicit TransferServerDialogPane(bool autoClose);
    virtual ~TransferServerDialogPane();

    void ResetOpacityAndRepaint();

protected:
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnPaint();

private:
    int m_currentFrame;
    int m_frameCount;
};

extern TransferServerDialogPane *g_pTransferServerDialog;

// UID:0004MV | by-memory/0x00598ed0-0x0059921f.TransferServerDialogPaneConstructor.md | Completion:92 | Confidence:94
TransferServerDialogPane::TransferServerDialogPane(bool autoClose)
    : Pane(3),
      m_currentFrame(0),
      m_frameCount(34)
{
    g_pTransferServerDialog = this;
    m_alpha = 0.9f;

    RectBounds frameBounds;
    RectBounds frameRect;
    unsigned short frameCount;

    if (g_useEpfAssets == 1) {
        frameCount = g_pEPFLib->GetEntryCount(L"TRANSSVR.EPF");
        for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex) {
            g_pEPFLib->GetEntryRect(L"TRANSSVR.EPF", frameIndex, &frameRect);
            frameBounds.UnionWith(&frameRect);
        }
    } else {
        frameCount = g_pEPFLib->GetEntryCount(L"TRANSSVR.EPD");
        for (int frameIndex = 0; frameIndex < frameCount; ++frameIndex) {
            g_pEPFLib->GetEntryRect(L"TRANSSVR.EPD", frameIndex, &frameRect);
            frameBounds.UnionWith(&frameRect);
        }
    }

    if (frameBounds.right - frameBounds.left > g_screenWidth)
        frameBounds.right = frameBounds.left + g_screenWidth;
    if (frameBounds.bottom - frameBounds.top > g_screenHeight)
        frameBounds.bottom = frameBounds.top + g_screenHeight;

    if (g_activeMapPane != 0) {
        Point unusedOrigin;
        RectBounds mapBounds;
        g_activeMapPane->GetOrigin(&unusedOrigin);
        g_activeMapPane->GetBounds(&mapBounds);

        int offsetX = (mapBounds.right - mapBounds.left - 144) / 2;
        int offsetY = (mapBounds.bottom - mapBounds.top - 144) / 2;
        if (g_useEpfAssets == 1) {
            offsetX -= 100;
            offsetY -= 100;
        }
        frameBounds.Offset(offsetX, offsetY);
    } else {
        frameBounds.Offset((g_pScreenPane->GetScreenWidth() - 144) / 2,
                           (g_pScreenPane->GetScreenHeight() - 144) / 2);
    }

    AddToLayer(&frameBounds, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    SetPaneOrder(0, 0);
    ScheduleTimer(0, 100, 0, 0);
    if (autoClose)
        ScheduleTimer(1, 5000, 0, 0);
    g_pSoundManager->PlaySound(0x19c, 100);
}

// UID:0004MW | by-memory/0x00599220-0x00599248.TransferServerDialogPaneDestructor.md | Completion:91 | Confidence:94
TransferServerDialogPane::~TransferServerDialogPane()
{
    g_pTransferServerDialog = 0;
}

// UID:0004MX | by-memory/0x00599250-0x00599261.TransferServerDialogPaneResetOpacityAndRepaint.md | Completion:91 | Confidence:93
void TransferServerDialogPane::ResetOpacityAndRepaint()
{
    m_alpha = 0.0f;
    InvalidateRect(0);
}

// UID:0004MY | by-memory/0x00599270-0x005992e8.TransferServerDialogPaneOnTimer.md | Completion:92 | Confidence:95
bool TransferServerDialogPane::OnTimer(int timerId, int arg0, int arg1)
{
    if (timerId == 0) {
        float newAlpha = fmaxf(0.0f, m_alpha - 0.03f);
        if (newAlpha <= 1.0f)
            m_alpha = newAlpha;

        m_currentFrame = (m_currentFrame + 1) % m_frameCount;
        InvalidateRect(0);
        ScheduleTimer(0, 100, 0, 0);
    } else if (timerId == 1) {
        MarkForDeletion();
    }

    return true;
}

// UID:0004MZ | by-memory/0x005992f0-0x005993a5.TransferServerDialogPaneOnPaint.md | Completion:92 | Confidence:95
void TransferServerDialogPane::OnPaint()
{
    EPFTileContext frame;

    void *palette;
    if (g_useEpfAssets == 1) {
        g_pEPFLib->LookupLayoutEntry(L"TRANSSVR.EPF", m_currentFrame, &frame);
        palette = g_pPaletteLib->GetPaletteByName(L"TRANSSVR.PAL");
    } else {
        g_pEPFLib->LookupLayoutEntry(L"TRANSSVR.EPD", m_currentFrame, &frame);
        palette = g_pPaletteLib->GetPaletteByName(L"TRANSSVR.PAD");
    }

    RectBounds destination = frame.bounds;
    destination.Offset(-frame.bounds.left, -frame.bounds.top);
    g_pfnBlitSprite(this,
                    &frame,
                    &frame.bounds,
                    &destination,
                    1,
                    palette,
                    0);
}

// UID:0000SL | by-global/g_pTransferServerDialog.md | Completion:90 | Confidence:93
TransferServerDialogPane *g_pTransferServerDialog = 0;
