// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NI
// Source by-file doc: by-file/ScrolledTextControlPane.md
// UID:0000CI | by-class/ScrolledTextControlPane.md | Completion:92 | Confidence:94
class ScrolledTextControlPane : public ControlPane
{
public:
    ScrolledTextControlPane(const wchar_t *resourceName,
                            const RectBounds *bounds,
                            signed char scrollInterval);
    virtual ~ScrolledTextControlPane();

    virtual bool OnTimerEvent(int eventId, int param1, int param2);
    virtual void OnPaintFrame();

private:
    EPFTileContext m_renderedText;
    GrafPort m_renderPort;
    int m_scrollOffset;
    int m_scrollLimit;
    signed char m_scrollInterval;
};

// UID:0004WP | by-memory/0x004ff040-0x004ff284.ScrolledTextControlPaneConstructor.md | Completion:92 | Confidence:94
ScrolledTextControlPane::ScrolledTextControlPane(
    const wchar_t *resourceName,
    const RectBounds *bounds,
    signed char scrollInterval)
    : ControlPane(8, bounds)
{
    MemoryMan *memoryMan = GetMemoryMan();
    DATFile dataFile;
    TextEditScrap scrap;

    dataFile.Open(resourceName);
    int dataSize = dataFile.GetSize();
    char *data = static_cast<char *>(
        memoryMan->AllocateBufferMemory(1001));
    dataFile.Read(data, dataSize);
    data[dataSize] = '\0';
    dataFile.Close();
    scrap.SetFromClipboardBlock(data, dataSize);
    memoryMan->FreeBufferMemory(data);

    int width = bounds->right - bounds->left;
    int height = bounds->bottom - bounds->top;
    TextEditPane *editor = new TextEditPane(
        width, height, width, height,
        143, 0, 0, 0, 1, IsLegacyAssetMode(), true, false);

    editor->PasteFromClipboard(&scrap);

    RectBounds textBounds;
    InitRectBounds(&textBounds,
                   0,
                   0,
                   width,
                   12 * editor->GetLineCount());
    m_scrollLimit = height + textBounds.bottom - textBounds.top;
    m_scrollOffset = 0;
    m_scrollInterval = scrollInterval;

    editor->UpdateRenderRegion(&textBounds);
    editor->SetViewportBounds(&textBounds);
    editor->SetTextAreaBounds(&textBounds);
    editor->SetEditActiveState(false, false);
    editor->SetMode(1);
    editor->UpdateSurfaceInfo();
    editor->OnDraw();
    editor->GetSurfaceContext()->CopyTo(&m_renderedText);
    m_renderedText.BuildEncodedMask();
    editor->EndPaint();
    delete editor;

    m_timerHandler.ScheduleTimer(0, 1, 0, 0);
}

// UID:0004WQ | by-memory/0x004ff290-0x004ff2fc.ScrolledTextControlPaneDestructor.md | Completion:93 | Confidence:95
ScrolledTextControlPane::~ScrolledTextControlPane()
{
    m_renderedText.ReleaseBuffers();
}

// UID:0004WR | by-memory/0x004ff300-0x004ff357.ScrolledTextControlPaneOnTimerEvent.md | Completion:93 | Confidence:95
bool ScrolledTextControlPane::OnTimerEvent(
    int eventId,
    int,
    int)
{
    if (eventId == 0) {
        ++m_scrollOffset;
        if (m_scrollOffset > m_scrollLimit) {
            m_scrollOffset = 0;
        }

        m_timerHandler.ScheduleTimer(
            0, m_scrollInterval, 0, 0);
        InvalidateRect(&m_bounds);
    }

    return true;
}

// UID:0004WS | by-memory/0x004ff360-0x004ff3fd.ScrolledTextControlPaneOnPaintFrame.md | Completion:93 | Confidence:95
void ScrolledTextControlPane::OnPaintFrame()
{
    SetDrawColor(0);
    FillRect(&m_bounds);

    RectBounds sourceRect = m_renderedText.bounds;
    RectBounds destinationRect = m_bounds;
    int paneHeight = m_bounds.bottom - m_bounds.top;

    if (m_scrollOffset < paneHeight) {
        destinationRect.top =
            destinationRect.bottom - m_scrollOffset;
        destinationRect.bottom =
            destinationRect.top + sourceRect.bottom - sourceRect.top;
    } else {
        sourceRect.top =
            sourceRect.bottom + m_scrollOffset - m_scrollLimit;
        destinationRect.bottom =
            m_scrollLimit - m_scrollOffset;
    }

    g_pfnBlitSprite(this,
                    &m_renderedText,
                    &sourceRect,
                    &destinationRect,
                    0,
                    NULL,
                    NULL);
}

// UID:0000CJ | by-class/ScrolledTextControlPaneForMadeBy.md | Completion:92 | Confidence:94
class ScrolledTextControlPaneForMadeBy : public ControlPane
{
public:
    ScrolledTextControlPaneForMadeBy(const wchar_t *resourceName,
                                     const RectBounds *bounds,
                                     signed char scrollInterval);
    virtual ~ScrolledTextControlPaneForMadeBy();

    virtual bool OnTimerEvent(int eventId, int param1, int param2);
    virtual void OnPaintFrame();

private:
    EPFTileContext m_renderedText;
    GrafPort m_renderPort;
    int m_scrollOffset;
    int m_scrollLimit;
    signed char m_scrollInterval;
};

// UID:0004MA | by-memory/0x004ff400-0x004ff644.ScrolledTextControlPaneForMadeByConstructor.md | Completion:92 | Confidence:94
ScrolledTextControlPaneForMadeBy::ScrolledTextControlPaneForMadeBy(
    const wchar_t *resourceName,
    const RectBounds *bounds,
    signed char scrollInterval)
    : ControlPane(8, bounds)
{

    MemoryMan *memoryMan = GetMemoryMan();
    DATFile dataFile;
    TextEditScrap scrap;

    dataFile.Open(resourceName);
    int dataSize = dataFile.GetSize();
    char *data = static_cast<char *>(
        memoryMan->AllocateBufferMemory(1001));
    dataFile.Read(data, dataSize);
    data[dataSize] = '\0';
    dataFile.Close();
    scrap.SetFromClipboardBlock(data, dataSize);
    memoryMan->FreeBufferMemory(data);

    int width = bounds->right - bounds->left;
    int height = bounds->bottom - bounds->top;
    TextEditPane *editor = new TextEditPane(
        width, height, width, height,
        143, 0, 0, 0, 1, IsLegacyAssetMode(), 0, 0);

    editor->PasteFromClipboard(&scrap);

    RectBounds textBounds;
    InitRectBounds(&textBounds,
                   0,
                   0,
                   width,
                   12 * editor->GetLineCount());
    m_scrollLimit = height + textBounds.bottom - textBounds.top;
    m_scrollOffset = 0;
    m_scrollInterval = scrollInterval;

    editor->UpdateRenderRegion(&textBounds);
    editor->SetViewportBounds(&textBounds);
    editor->SetTextAreaBounds(&textBounds);
    editor->SetEditActiveState(false, false);
    editor->SetMode(1);
    editor->UpdateSurfaceInfo();
    editor->OnDraw();
    editor->GetSurfaceContext()->CopyTo(&m_renderedText);
    m_renderedText.BuildEncodedMask();
    editor->EndPaint();
    delete editor;

    m_timerHandler.ScheduleTimer(0, 1, 0, 0);
}

// UID:0004MB | by-memory/0x004ff650-0x004ff6bc.ScrolledTextControlPaneForMadeByDestructor.md | Completion:93 | Confidence:95
ScrolledTextControlPaneForMadeBy::~ScrolledTextControlPaneForMadeBy()
{
    m_renderedText.ReleaseBuffers();
}

// UID:0004MC | by-memory/0x004ff6c0-0x004ff725.ScrolledTextControlPaneForMadeByOnTimerEvent.md | Completion:93 | Confidence:95
bool ScrolledTextControlPaneForMadeBy::OnTimerEvent(
    int eventId,
    int,
    int)
{
    if (eventId == 0) {
        m_scrollOffset += 2;
        if (m_scrollOffset > m_scrollLimit) {
            m_scrollOffset = 0;
            g_pNewHistoryDialog->CloseDialog();
        }

        m_timerHandler.ScheduleTimer(
            0, m_scrollInterval, 0, 0);
        InvalidateRect(&m_bounds);
    }

    return true;
}

// UID:0004MD | by-memory/0x004ff730-0x004ff7cd.ScrolledTextControlPaneForMadeByOnPaintFrame.md | Completion:93 | Confidence:95
void ScrolledTextControlPaneForMadeBy::OnPaintFrame()
{
    SetDrawColor(0);
    FillRect(&m_bounds);

    RectBounds sourceRect = m_renderedText.bounds;
    RectBounds destinationRect = m_bounds;
    int paneHeight = m_bounds.bottom - m_bounds.top;

    if (m_scrollOffset < paneHeight) {
        destinationRect.top =
            destinationRect.bottom - m_scrollOffset;
        destinationRect.bottom =
            destinationRect.top + sourceRect.bottom - sourceRect.top;
    } else {
        sourceRect.top =
            sourceRect.bottom + m_scrollOffset - m_scrollLimit;
        destinationRect.bottom =
            m_scrollLimit - m_scrollOffset;
    }

    g_pfnBlitSprite(this,
                    &m_renderedText,
                    &sourceRect,
                    &destinationRect,
                    0,
                    NULL,
                    NULL);
}
