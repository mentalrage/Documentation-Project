// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NH
// Source by-file doc: by-file/ScrolledPictureControlPane.md
// UID:0000CH | by-class/ScrolledPictureControlPane.md | Completion:91 | Confidence:93
class ScrolledPictureControlPane : public ControlPane
{
public:
    ScrolledPictureControlPane(
        const RectBounds *bounds,
        const wchar_t *frameResourceName,
        const wchar_t *paletteName,
        int scrollInterval,
        int scrollStep,
        unsigned char scrollDirection);
    virtual ~ScrolledPictureControlPane();
    virtual void OnPaintFrame();
    virtual bool OnTimerEvent(int eventId, int param1, int param2);

private:
    int m_scrollInterval;
    int m_scrollStep;
    unsigned char m_scrollDirection;
    ArchiveMetadataTable *m_frameTable;
    FrameDrawRecord m_frameDrawRecord;
    DLPalette *m_palette;
    RectBounds m_destinationRect;
};

// UID:00019Y | by-memory/0x004ff7d0-0x004ffa9e.ScrolledPictureControlPaneCore.md | Completion:92 | Confidence:93
enum ScrolledPictureDirection {
    kScrollUp = 0,
    kScrollRight = 1,
    kScrollDown = 2,
    kScrollLeft = 3
};

ScrolledPictureControlPane::ScrolledPictureControlPane(
    const RectBounds *bounds,
    const wchar_t *frameResourceName,
    const wchar_t *paletteName,
    int scrollInterval,
    int scrollStep,
    unsigned char scrollDirection)
    : ControlPane(8, bounds),
      m_scrollInterval(scrollInterval),
      m_scrollStep(scrollStep),
      m_scrollDirection(scrollDirection),
      m_frameTable(NULL),
      m_palette(NULL)
{
    memset(&m_frameDrawRecord, 0, sizeof(m_frameDrawRecord));

    m_frameTable = LoadImageFrameTable(frameResourceName, 0);
    LoadFrameDrawRecord(m_frameTable, 0, &m_frameDrawRecord);

    if (paletteName != NULL)
        m_palette = g_pPaletteLib->GetPaletteByName(paletteName);
    else
        m_palette = g_pPaletteLib->GetCurrentPalette();

    int frameWidth = m_frameDrawRecord.sourceRect.right - m_frameDrawRecord.sourceRect.left;
    int frameHeight = m_frameDrawRecord.sourceRect.bottom - m_frameDrawRecord.sourceRect.top;
    int paneWidth = m_bounds.right - m_bounds.left;
    int paneHeight = m_bounds.bottom - m_bounds.top;
    int centeredLeft = (paneWidth / 2) - (frameWidth / 2);
    int centeredTop = (paneHeight / 2) - (frameHeight / 2);

    switch (m_scrollDirection) {
    case kScrollUp:
        InitRectBounds(&m_destinationRect, centeredLeft, m_bounds.bottom,
            centeredLeft + frameWidth, m_bounds.bottom + frameHeight);
        break;
    case kScrollRight:
        InitRectBounds(&m_destinationRect, -frameWidth, centeredTop,
            0, centeredTop + frameHeight);
        break;
    case kScrollDown:
        InitRectBounds(&m_destinationRect, centeredLeft, -frameHeight,
            centeredLeft + frameWidth, 0);
        break;
    case kScrollLeft:
        InitRectBounds(&m_destinationRect, m_bounds.right, centeredTop,
            m_bounds.right + frameWidth, centeredTop + frameHeight);
        break;
    }

    m_timerHandler.ScheduleTimer(0, m_scrollInterval, 0, 0);
}

ScrolledPictureControlPane::~ScrolledPictureControlPane()
{
    DestroyOwnedImageBlock(m_frameTable);
}

bool ScrolledPictureControlPane::OnTimerEvent(int eventId, int param1, int param2)
{
    int dx = 0;
    int dy = 0;

    switch (m_scrollDirection) {
    case kScrollUp:
        dy = -m_scrollStep;
        break;
    case kScrollRight:
        dx = m_scrollStep;
        break;
    case kScrollDown:
        dy = m_scrollStep;
        break;
    case kScrollLeft:
        dx = -m_scrollStep;
        break;
    }

    OffsetRect(&m_destinationRect, dx, dy);
    InvalidateRect(&m_bounds);
    m_timerHandler.ScheduleTimer(0, m_scrollInterval, 0, 0);
    return true;
}

void ScrolledPictureControlPane::OnPaintFrame()
{
    SetDrawColor(0);
    PrepareRenderRegion(this, &m_bounds);
    BlitFrame(this, &m_frameDrawRecord, &m_frameDrawRecord.sourceRect,
        &m_destinationRect, 1, m_palette, 0);
}
