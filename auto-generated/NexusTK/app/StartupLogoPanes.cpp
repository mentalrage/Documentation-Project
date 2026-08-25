// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O4
// Source by-file doc: by-file/StartupLogoPanes.md
// UID:00007G | by-class/LogoPane.md | Completion:93 | Confidence:94
// UID:0002PL | by-memory/0x004f4c10-0x004f4eac.LogoPaneConstructor.md | Completion:90 | Confidence:92
LogoPane::LogoPane(const wchar_t *logoPath, FunctionObject0 *completionCallback)
    : Pane(0)
{
    m_advanceRequestedBeforeReady = false;
    m_logoReady = false;
    m_advanceQueued = false;
    m_completionCallback = completionCallback;

    RectBounds fullScreenBounds;
    fullScreenBounds.SetLTRB(0, 0, g_screenWidth, g_screenHeight);
    SetBounds(&fullScreenBounds);

    m_logoTileContext.ReleaseBuffers();

    FILE *logoFile = g_pfnWideOpenFile(logoPath, L"rb");
    if (logoFile != 0) {
        unsigned int compressedImageSize = 0;
        if (fread(&compressedImageSize, sizeof(compressedImageSize), 1, logoFile) != 1) {
            goto attach_static_logo;
        }

        unsigned char *compressedImage =
            static_cast<unsigned char *>(malloc(compressedImageSize));
        if (fread(compressedImage, 1, compressedImageSize, logoFile) != compressedImageSize) {
            goto attach_static_logo;
        }

        uLongf decodedImageSize = static_cast<uLongf>(g_screenWidth * g_screenHeight);
        unsigned char *decodedImage =
            static_cast<unsigned char *>(malloc(decodedImageSize));
        Uncompress(decodedImage, &decodedImageSize, compressedImage, compressedImageSize);
        free(compressedImage);

        m_logoTileContext.pixelData = decodedImage;
        m_logoTileContext.encodedMaskBytes = 0;
        m_logoTileContext.rowStridePixels = g_screenWidth;
        m_logoTileContext.encodedMaskByteCount = 0;
        m_logoTileContext.bounds.SetLTRB(0, 0, g_screenWidth, g_screenHeight);
        OnBoundsChangedOrInvalidate(0);

        unsigned int paletteSize = 0;
        if (fread(&paletteSize, sizeof(paletteSize), 1, logoFile) != 1) {
            goto attach_static_logo;
        }

        unsigned char *paletteBytes =
            static_cast<unsigned char *>(malloc(paletteSize));
        if (fread(paletteBytes, 1, paletteSize, logoFile) != paletteSize) {
            goto attach_static_logo;
        }

        m_logoPalette.LoadFromBitmapPalette(paletteBytes, paletteSize);
        free(paletteBytes);
        m_logoTileContext.BuildEncodedMask();
        fclose(logoFile);
    }

attach_static_logo:
    AttachSurface(&m_logoTileContext.bounds, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    SetSurfaceOriginOrVisibleState(0, 0);

    typedef void (__thiscall LogoPane::*LogoPaneCallback0)();
    g_pScreenPane->QueueFadeInCallback(
        new PlainMemberFunctionObject0<LogoPaneCallback0, LogoPane>(
            &LogoPane::MarkReadyAndScheduleAdvance, 0, this));
}

// UID:0002PM | by-memory/0x004f4eb0-0x004f4f29.LogoPaneCleanupDestructor.md | Completion:92 | Confidence:95
LogoPane::~LogoPane()
{
    m_logoTileContext.ReleaseBuffers();
    m_logoPalette.FreePaletteData();
}

// UID:0003LF | by-memory/0x004f4f30-0x004f4f61.LogoPaneRawAdvanceRequest.md | Completion:88 | Confidence:90
void LogoPane::RequestAdvance()
{
    if (!m_logoReady || m_advanceQueued) {
        m_advanceRequestedBeforeReady = true;
        return;
    }

    TimerHandler::RemovePendingTimers();
    QueueAdvanceToNextScreen();
}

// UID:0003LG | by-memory/0x004f4f70-0x004f4f94.LogoPaneOnPaint.md | Completion:92 | Confidence:94
void LogoPane::OnPaint()
{
    g_pfnDrawEPFTile(
        &m_logoTileContext,
        &m_logoTileContext.bounds,
        &m_bounds,
        0,
        &m_logoPalette,
        0);
}

// UID:0003LH | by-memory/0x004f4fa0-0x004f4fde.LogoPaneHandleKeyOrTextEvent.md | Completion:92 | Confidence:94
bool LogoPane::HandleKeyOrTextEvent(Event *)
{
    if (!m_logoReady || m_advanceQueued)
    {
        m_advanceRequestedBeforeReady = true;
        return true;
    }

    TimerHandler::RemovePendingTimers();
    QueueAdvanceToNextScreen();
    return true;
}

// UID:0003LI | by-memory/0x004f4fe0-0x004f502c.LogoPaneHandlePointerOrMouseEvent.md | Completion:92 | Confidence:94
bool LogoPane::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type == kEventLeftButtonUp)
    {
        if (m_logoReady && !m_advanceQueued)
        {
            TimerHandler::RemovePendingTimers();
            QueueAdvanceToNextScreen();
            return true;
        }

        m_advanceRequestedBeforeReady = true;
    }

    return true;
}

// UID:0003LJ | by-memory/0x004f5030-0x004f5040.LogoPaneAdvanceToNextScreenCallback.md | Completion:88 | Confidence:91
bool LogoPane::OnTimer(int, int, int)
{
    QueueAdvanceToNextScreen();
    return true;
}

// UID:0003LK | by-memory/0x004f5040-0x004f506a.LogoPaneMarkReadyAndScheduleAdvance.md | Completion:88 | Confidence:91
void LogoPane::MarkReadyAndScheduleAdvance()
{
    m_logoReady = true;

    const int delay = m_advanceRequestedBeforeReady ? 0 : 3000;
    TimerHandler::ScheduleTimer(0, delay, 0, 0);
}

// UID:0003LL | by-memory/0x004f5070-0x004f50a1.LogoPaneAdvanceToNextScreen.md | Completion:88 | Confidence:91
void LogoPane::AdvanceToNextScreen()
{
    m_completionCallback->Invoke();
    delete m_completionCallback;

    g_pScreenPane->ShowCursor();
    MarkForDeletion();
}

// UID:0002PO | by-memory/0x004f50b0-0x004f5246.LogoPaneStaticLogoLoaderHelpers.md | Completion:88 | Confidence:91
void LogoPane::LoadStaticLogoFromFile(const wchar_t *logoPath)
{
    FILE *logoFile = g_pfnWideOpenFile(logoPath, L"rb");
    if (logoFile == 0)
        return;

    unsigned int compressedImageSize = 0;
    if (fread(&compressedImageSize, sizeof(compressedImageSize), 1, logoFile) != 1)
        return;

    unsigned char *compressedImage =
        static_cast<unsigned char *>(malloc(compressedImageSize));
    if (fread(compressedImage, 1, compressedImageSize, logoFile) != compressedImageSize)
        return;

    uLongf decodedImageSize = static_cast<uLongf>(g_screenWidth * g_screenHeight);
    unsigned char *decodedImage =
        static_cast<unsigned char *>(malloc(decodedImageSize));
    Uncompress(decodedImage, &decodedImageSize, compressedImage, compressedImageSize);
    free(compressedImage);

    m_logoTileContext.pixelData = decodedImage;
    m_logoTileContext.encodedMaskBytes = 0;
    m_logoTileContext.rowStridePixels = g_screenWidth;
    m_logoTileContext.encodedMaskByteCount = 0;
    m_logoTileContext.bounds.SetLTRB(0, 0, g_screenWidth, g_screenHeight);
    OnBoundsChangedOrInvalidate(0);

    unsigned int paletteSize = 0;
    if (fread(&paletteSize, sizeof(paletteSize), 1, logoFile) != 1)
        return;

    unsigned char *paletteBytes =
        static_cast<unsigned char *>(malloc(paletteSize));
    if (fread(paletteBytes, 1, paletteSize, logoFile) != paletteSize)
        return;

    m_logoPalette.LoadFromBitmapPalette(paletteBytes, paletteSize);
    free(paletteBytes);
    m_logoTileContext.BuildEncodedMask();
    fclose(logoFile);
}

void LogoPane::AttachStaticLogoSurface()
{
    AttachSurface(&m_logoTileContext.bounds, 0, 0, g_mainUiLayerSlots.overlayPaneLayerContext);
    SetSurfaceOriginOrVisibleState(0, 0);
}

// UID:0002PP | by-memory/0x004f5250-0x004f52de.LogoPaneQueueAdvanceToNextScreen.md | Completion:88 | Confidence:91
void LogoPane::QueueAdvanceToNextScreen()
{
    typedef void (__thiscall LogoPane::*LogoPaneCallback0)();

    m_advanceQueued = true;
    g_pScreenPane->QueueFadeOutCallback(
        new PlainMemberFunctionObject0<LogoPaneCallback0, LogoPane>(
            &LogoPane::AdvanceToNextScreen, 0, this));
}

// UID:0002PR | by-memory/0x004f5300-0x004f53a8.LogoPaneScalarDeletingDestructor.md | Completion:94 | Confidence:96
// Emitted code for this range is covered by [UID:0002PM][0x004f4eb0-0x004f4f29.LogoPaneCleanupDestructor](by-memory/0x004f4eb0-0x004f4f29.LogoPaneCleanupDestructor.md).

// UID:0003OP | by-memory/0x0061cf74-0x0061cffc.LogoPaneVtableData.md | Completion:94 | Confidence:94
// Emitted code for this range is covered by [UID:00007G][LogoPane](by-class/LogoPane.md).

// UID:00007H | by-class/LogoPlayerPane.md | Completion:88 | Confidence:91
class FunctionObject0;
struct KeyEvent;
struct MouseEvent;

class LogoPlayerPane : public VideoPlayerPane
{
public:
    LogoPlayerPane(const wchar_t *moviePath, FunctionObject0 *completionCallback);
    virtual ~LogoPlayerPane();

protected:
    virtual void OnClose();
    virtual bool OnKeyEvent(const KeyEvent *event);
    virtual bool OnMouseEvent(const MouseEvent *event);

private:
    void AdvanceToNextSegment();

    _AUTOBUF<unsigned char> m_movieData;         // +0x100; loaded segmented Bink payload.
    FunctionObject0 *m_completionCallback;       // +0x10c; non-null startup completion callback.
    bool m_hasRequestedSegmentAdvance;           // +0x110; guard set before the second open attempt.
    unsigned char m_reserved111[3];              // +0x111..+0x113 alignment before the saved size.
    unsigned int m_firstSegmentSize;             // +0x114; first payload dword.
};

// UID:0002PS | by-memory/0x004f53b0-0x004f5500.LogoPlayerPaneConstructor.md | Completion:88 | Confidence:91
LogoPlayerPane::LogoPlayerPane(const wchar_t *moviePath, FunctionObject0 *completionCallback)
    : VideoPlayerPane()
    , m_movieData()
    , m_completionCallback(completionCallback)
    , m_hasRequestedSegmentAdvance(false)
{
    StdioFile file;
    file.Open(moviePath);
    file.ReadRemaining(m_movieData);

    const unsigned char *movieData = m_movieData.m_data;
    m_firstSegmentSize = *reinterpret_cast<const unsigned int *>(movieData);

    if (!OpenBinkVideo(movieData + sizeof(unsigned int), m_firstSegmentSize)) {
        LString message(L"%s corrupted", moviePath);
        throw FileError(message);
    }
}

// UID:0002PT | by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md | Completion:88 | Confidence:92
LogoPlayerPane::~LogoPlayerPane()
{
    delete m_completionCallback;
}

// UID:0002PU | by-memory/0x004f5570-0x004f55c8.LogoPlayerPaneAdvanceToNextSegment.md | Completion:87 | Confidence:92
void LogoPlayerPane::AdvanceToNextSegment()
{
    if (m_hasRequestedSegmentAdvance)
        return;

    if (m_binkHandle->FrameNum >= 100)
        return;

    const unsigned int firstSegmentSize = m_firstSegmentSize;
    unsigned char* const nextSegmentData =
        m_movieData.m_data + sizeof(unsigned int) + firstSegmentSize;
    const unsigned int nextSegmentSize =
        m_movieData.m_count - firstSegmentSize - sizeof(unsigned int);

    m_hasRequestedSegmentAdvance = true;

    if (!OpenBinkVideo(nextSegmentData, nextSegmentSize)) {
        MarkForDeletion();
        return;
    }

    StartPlayback();
}

// UID:0002PV | by-memory/0x004f55d0-0x004f561d.LogoPlayerPaneInputSkipHandlers.md | Completion:88 | Confidence:91
bool LogoPlayerPane::OnKeyEvent(const KeyEvent *event)
{
    if (event->type == kEventKeyDown) {
        const unsigned char key = event->keyCode;
        if (key == VK_RETURN || key == VK_ESCAPE || key == VK_SPACE)
            AdvanceToNextSegment();
    }

    return true;
}

bool LogoPlayerPane::OnMouseEvent(const MouseEvent *event)
{
    if (event->type == kEventLeftButtonUp)
        AdvanceToNextSegment();

    return true;
}

// UID:0002PW | by-memory/0x004f5620-0x004f5634.LogoPlayerPaneOnClose.md | Completion:86 | Confidence:91
void LogoPlayerPane::OnClose()
{
    MarkForDeletion();
    m_completionCallback->Invoke();
}

// UID:0002PY | by-memory/0x004f5680-0x004f570c.LogoPlayerPaneScalarDeletingDestructor.md | Completion:87 | Confidence:92
// Emitted code for this range is covered by [UID:0002PT][0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor](by-memory/0x004f5510-0x004f556a.LogoPlayerPaneCleanupDestructor.md).

// UID:0003OR | by-memory/0x0061d014-0x0061d0a8.LogoPlayerPaneVtableData.md | Completion:86 | Confidence:91
// The LogoPlayerPane vtable family beginning at 0x0061d014 is generated
// from the LogoPlayerPane virtual declarations. Do not hand-author this
// compiler-generated table.

// UID:0002ZH | by-global/StartupLogoBinkRestartFlag.md | Completion:88 | Confidence:92
static bool g_startupLogoBinkRestartPending = true;

// UID:0003K6 | by-memory/0x004f5710-0x004f59c6.PlayStartupLogoBinkFile.md | Completion:89 | Confidence:92
static void PlayStartupLogoBinkFile()
{
    g_startupLogoBinkWindow = g_pApplication->GetMainWindowHandle();

    StdioFile file;
    const wchar_t *moviePath = g_useEpfAssets ? L"LOGO.PAK" : L"LOGO.PAD";
    if (!PathExistsViaStat(moviePath))
        return;

    file.Open(moviePath);

    _AUTOBUF<unsigned char> movieData;
    file.ReadRemaining(movieData);

    const unsigned int firstSegmentSize =
        *reinterpret_cast<const unsigned int *>(movieData.m_data);
    unsigned char *firstSegment = movieData.m_data + sizeof(unsigned int);

    g_startupLogoBinkNextSegment = firstSegment + firstSegmentSize;
    g_startupLogoBinkRemainingSegmentSize =
        movieData.m_count - firstSegmentSize - sizeof(unsigned int);

    void *soundSystem = g_pSoundManager->GetBinkSoundSystem();
    if (soundSystem != 0)
        BinkSetSoundSystem(BinkOpenMiles, soundSystem);

    g_startupLogoBinkHandle =
        BinkOpen(firstSegment, BINKFROMMEMORY | BINKNOSKIP);
    g_startupLogoBinkBuffer =
        BinkBufferOpen(
            g_startupLogoBinkWindow,
            g_startupLogoBinkHandle->Width,
            g_startupLogoBinkHandle->Height,
            2);

    if (g_startupLogoBinkBuffer == 0) {
        MessageBoxA(0, BinkBufferGetError(), "Bink Error", MB_ICONERROR);
        BinkClose(g_startupLogoBinkHandle);
        return;
    }

    LONG oldWndProc = SetWindowLongA(
        g_startupLogoBinkWindow,
        GWL_WNDPROC,
        reinterpret_cast<LONG>(StartupLogoBinkWndProc));

    g_startupLogoBinkLoopActive = true;
    do {
        MSG message;
        if (g_pfnPeekMessage(&message, 0, 0, 0, PM_REMOVE)) {
            TranslateMessage(&message);
            g_pfnDispatchMessage(&message);
        } else if (!BinkWait(g_startupLogoBinkHandle)) {
            BinkDoFrame(g_startupLogoBinkHandle);

            if (BinkBufferLock(g_startupLogoBinkBuffer)) {
                BinkCopyToBuffer(
                    g_startupLogoBinkHandle,
                    g_startupLogoBinkBuffer->Buffer,
                    g_startupLogoBinkBuffer->BufferPitch,
                    g_startupLogoBinkBuffer->Height,
                    0,
                    0,
                    g_startupLogoBinkBuffer->SurfaceType);
                BinkBufferUnlock(g_startupLogoBinkBuffer);
            }

            const int rectCount =
                BinkGetRects(g_startupLogoBinkHandle, g_startupLogoBinkBuffer->SurfaceType);
            BinkBufferBlit(
                g_startupLogoBinkBuffer,
                g_startupLogoBinkHandle->FrameRects,
                rectCount);

            if (g_startupLogoBinkHandle->FrameNum == g_startupLogoBinkHandle->Frames)
                g_startupLogoBinkLoopActive = false;
            else
                BinkNextFrame(g_startupLogoBinkHandle);
        }
    } while (g_startupLogoBinkLoopActive);

    SetWindowLongA(g_startupLogoBinkWindow, GWL_WNDPROC, oldWndProc);
    BinkClose(g_startupLogoBinkHandle);
    delete g_startupLogoBinkTeardownCallback;
}

// UID:0003K7 | by-memory/0x004f59d0-0x004f5ac7.StartupLogoBinkWndProc.md | Completion:89 | Confidence:93
static LRESULT CALLBACK StartupLogoBinkWndProc(
    HWND hWnd,
    UINT message,
    WPARAM wParam,
    LPARAM lParam)
{
    switch (message) {
    case WM_ERASEBKGND:
        return 1;

    case WM_DESTROY:
    case WM_CLOSE:
        return 0;

    case WM_PAINT: {
        PAINTSTRUCT paint;
        HDC dc = BeginPaint(hWnd, &paint);
        PatBlt(dc, 0, 0, 4096, 4096, BLACKNESS);
        EndPaint(hWnd, &paint);
        return 0;
    }

    case WM_KEYDOWN:
    case WM_LBUTTONDOWN:
        TryAdvanceStartupLogoBinkSegment();
        return 0;
    }

    return DefWindowProcW(hWnd, message, wParam, lParam);
}

// UID:00022U | by-memory/0x004f5ae0-0x004f5b1e.TryAdvanceStartupLogoBinkSegment.md | Completion:90 | Confidence:94
static void TryAdvanceStartupLogoBinkSegment()
{
    if (!g_startupLogoBinkRestartPending)
        return;

    BINK *bink = g_startupLogoBinkHandle;
    if (bink->FrameNum >= bink->Frames / 2)
        return;

    g_startupLogoBinkRestartPending = false;

    BinkClose(bink);
    g_startupLogoBinkHandle =
        BinkOpen(g_startupLogoBinkNextSegment, BINKFROMMEMORY | BINKNOSKIP);
}


// UID:00029G | by-memory/0x0069b45c-0x0069b480.StartupLogoBinkPlaybackGlobals.md | Completion:88 | Confidence:92
static BINK *g_startupLogoBinkHandle = 0;
static BINKBUFFER *g_startupLogoBinkBuffer = 0;
static unsigned int g_startupLogoBinkReserved0 = 0;
static HWND g_startupLogoBinkWindow = 0;
static bool g_startupLogoBinkLoopActive = false;
static unsigned char g_startupLogoBinkLoopReserved[3] = { 0, 0, 0 };
static FunctionObject0 *g_startupLogoBinkTeardownCallback = 0;
static unsigned char *g_startupLogoBinkNextSegment = 0;
static unsigned int g_startupLogoBinkRemainingSegmentSize = 0;
static unsigned int g_startupLogoBinkReserved1 = 0;

// UID:0003OS | by-memory\0x0061d0a8-0x0061d0f0.StartupLogoResourceStrings.md | Completion:86 | Confidence:91 | Empty Emitter Marker
