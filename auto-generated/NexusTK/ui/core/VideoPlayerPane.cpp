// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000P4
// Source by-file doc: by-file/VideoPlayerPane.md
// UID:0001NT | by-memory/0x005c0040-0x005c045b.VideoPlayerPane.md | Completion:94 | Confidence:96
VideoPlayerPane::VideoPlayerPane()
    : Pane(false),
      m_isPlaying(false),
      m_binkHandle(NULL)
{
}

VideoPlayerPane::~VideoPlayerPane()
{
    g_pApplication->UnregisterChangeListener(this, 'term', false);

    if (m_binkHandle != NULL)
        BinkClose(m_binkHandle);
}

bool VideoPlayerPane::OpenBinkVideo(const void *segmentData, unsigned int segmentSize)
{
    LPDIRECTSOUND directSound = g_pSoundManager->GetDirectSound();
    if (directSound != NULL)
        BinkSetSoundSystem(BinkOpenDirectSound, directSound);

    if (m_binkHandle != NULL)
        BinkClose(m_binkHandle);

    g_pApplication->RegisterChangeListener(this, 'term', false);
    m_binkHandle = BinkOpen(segmentData, BINKFROMMEMORY | BINKNOSKIP);
    return m_binkHandle != NULL;
}

void VideoPlayerPane::CloseBinkVideo()
{
    if (m_binkHandle != NULL)
    {
        StopPlayback();
        BinkClose(m_binkHandle);
    }
}

void VideoPlayerPane::SetBinkSoundEnabled(bool enabled)
{
    if ((m_binkHandle->SoundOn != 0) != enabled)
        BinkSetSoundOnOff(m_binkHandle, true);
}

void VideoPlayerPane::SeekBinkFrame(unsigned int frame)
{
    BinkGoto(m_binkHandle, frame, 0);
}

void VideoPlayerPane::StartPlayback()
{
    m_isVisible = true;
    m_isPlaying = true;
    InvalidateRect(NULL);
}

void VideoPlayerPane::StopPlayback()
{
    m_isPlaying = false;
    InvalidateRect(NULL);
    m_isVisible = false;

    if (m_binkHandle->SoundOn != 0)
        BinkSetSoundOnOff(m_binkHandle, true);

    BinkClose(m_binkHandle);
    m_binkHandle = NULL;
}

void VideoPlayerPane::OnChangeMessage(LObject *owner, Message *message)
{
    if (message->m_type == 'term' && m_binkHandle != NULL)
    {
        StopPlayback();
        BinkClose(m_binkHandle);
    }
}

void VideoPlayerPane::OnPaint()
{
    if (!m_isPlaying)
        return;

    if (!BinkWait(m_binkHandle))
    {
        BinkDoFrame(m_binkHandle);
        BinkCopyToBuffer(
            m_binkHandle,
            m_surfaceContext.pixelData,
            2 * m_surfaceContext.rowStridePixels,
            m_surfaceContext.bounds.bottom - m_surfaceContext.bounds.top,
            0,
            0,
            g_surfaceUsesRgb565Pixels ? BINKSURFACE565 : BINKSURFACE555);

        if (m_binkHandle->FrameNum < m_binkHandle->Frames)
        {
            BinkNextFrame(m_binkHandle);
            BinkService(m_binkHandle);
            return;
        }

        StopPlayback();
        ScheduleTimer('ViSD', 0, 0, 0);
    }

    BinkService(m_binkHandle);
}

bool VideoPlayerPane::OnTimer(int timerId, int arg0, int arg1)
{
    if (timerId != 'ViSD')
        return Pane::OnTimer(timerId, arg0, arg1);

    OnClose();
    return true;
}

// UID:0002Z5 | by-memory/0x0063104c-0x006310dc.VideoPlayerPaneVtableData.md | Completion:95 | Confidence:98
// Covered by the VideoPlayerPane class declaration, virtual methods, and compiler-generated RTTI/vtables.

// UID:0000FV | by-class\VideoPlayerPane.md | Completion:94 | Confidence:96 | Empty Emitter Marker
