// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HO
// Source by-file doc: by-file/BackPane.md
// UID:00000R | by-class/BackGroundPane.md | Completion:88 | Confidence:91
class BackGroundPane : public Pane
{
public:
    BackGroundPane();
    virtual ~BackGroundPane();

    char HandleBackgroundPacketEvent(const PacketEvent *event);
    virtual void OnPaint();

    bool IsBackgroundFrameReady() const;
    bool IsMapReadyForBackground() const;
    void MarkBackgroundFrameReady();
    void ClearBackgroundFrameReady();
    void MarkMapReadyForBackground();
    void ClearMapReadyForBackground();

private:
    EPFTileContext m_backgroundTileContext;
    bool m_backgroundFrameReady;
    bool m_mapReadyForBackground;

// UID:00030L | by-memory/0x00467510-0x0046782f.BackGroundPaneCoreMethods.md | Completion:88 | Confidence:91
BackGroundPane::BackGroundPane()
    : Pane(0)
{
    g_pBackGroundPane = this;
    m_backgroundFrameReady = false;
    m_mapReadyForBackground = false;
}

BackGroundPane::~BackGroundPane()
{
    g_pBackGroundPane = NULL;
}

char BackGroundPane::HandleBackgroundPacketEvent(const PacketEvent *event)
{
    const unsigned char eventCode = *event->payload;

    g_pBackGroundPane->m_mapReadyForBackground =
        g_activeMapPane->GetBackgroundBlendAmount() > 0.8f;

    switch (eventCode)
    {
    case 0x04:
    case 0x08:
    case 0x0b:
    case 0x15:
    case 0x26:
        if (g_pConfig->IsBackgroundRefreshEnabled() &&
            g_activeMapPane->CanRefreshBackground())
        {
            InvalidateRect(&m_backgroundBounds);
        }
        break;

    default:
        return 0;
    }

    return 0;
}

void BackGroundPane::OnPaint()
{
    if (m_backgroundFrameReady && m_mapReadyForBackground)
    {
        DrawTileContext(&m_backgroundTileContext,
                        &m_backgroundTileTarget,
                        &m_bounds,
                        0,
                        m_backgroundPaletteName,
                        0);
        return;
    }

    SetMode(0);
    SetDrawColor(128);
    FillRect(&m_bounds);
}

bool BackGroundPane::IsBackgroundFrameReady() const
{
    return m_backgroundFrameReady;
}

bool BackGroundPane::IsMapReadyForBackground() const
{
    return m_mapReadyForBackground;
}

void BackGroundPane::MarkBackgroundFrameReady()
{
    m_backgroundFrameReady = true;
}

void BackGroundPane::ClearBackgroundFrameReady()
{
    m_backgroundFrameReady = false;
}

void BackGroundPane::MarkMapReadyForBackground()
{
    m_mapReadyForBackground = true;
}

void BackGroundPane::ClearMapReadyForBackground()
{
    m_mapReadyForBackground = false;
}

void ClearBackGroundPane()
{
    g_pBackGroundPane = NULL;
}

// The adjustor thunks at 0x004677ab-0x004677c1 and the scalar deleting
// destructor at 0x004677d0-0x0046782f are compiler-generated from
// BackGroundPane::~BackGroundPane(); do not hand-author separate source.
};

// UID:00000S | by-class/BackPane.md | Completion:88 | Confidence:91
#include "BackPane.h"

// UID:00030M | by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md | Completion:88 | Confidence:91
BackPane::BackPane(const wchar_t* frameResourceName)
    : Pane(0)
{
    EPFTileContext* frameContext = &m_frameTileContext;

    g_pBackPane = frameContext != NULL ? this : NULL;

    frameContext->Initialize();
    m_frameWidth = g_screenWidth;
    m_frameHeight = g_screenHeight;
    g_pEPFLib->LookupLayoutEntry(frameResourceName, 0, frameContext);
}

BackPane::~BackPane()
{
    g_pChangeMan->UnregisterObject(this);
    g_pBackPane = NULL;
}

// UID:00030N | by-memory/0x004679c0-0x00467b2d.BackPaneActivatePaintAndDestructor.md | Completion:88 | Confidence:91
bool BackPane::OnActivate(int activateCode)
{
    if (g_useEpfAssets != 1)
        g_pScreenPane->SetCursor(0, 0);

    return true;
}

void BackPane::OnPaint()
{
    RectBounds bounds;
    GetBounds(&bounds);

    const wchar_t *paletteName = (g_useEpfAssets == 1)
        ? L"FRAME.PAL"
        : L"NPAL5.PAL";

    DrawTileContext(&m_frameTileContext,
                    &m_frameTileTarget,
                    &m_bounds,
                    0,
                    paletteName,
                    0);
}

void ClearBackPane()
{
    g_pBackPane = NULL;
}

// The adjustor thunks at 0x00467a5b-0x00467a71 and the scalar deleting
// destructor at 0x00467a80-0x00467b2d are compiler-generated from
// BackPane::~BackPane(); the ordinary destructor body is emitted by
// [UID:00030M][0x00467830-0x0046795c.BackPaneConstructionAndDestruction](by-memory/0x00467830-0x0046795c.BackPaneConstructionAndDestruction.md).

// UID:00018K | by-memory/0x004eaf20-0x004eb044.BackPaneHelpPacketDisplayV1.md | Completion:88 | Confidence:91
void BackPane::ShowHelpFromPacket(const unsigned char *packet)
{
    const int helpId = ReadPacketWord(packet + 1) & 0x3fff;
    const unsigned short textLength = ReadPacketWord(packet + 3);

    if (textLength == 0 || textLength > 1023)
        return;

    wchar_t text[1024];
    const int converted = MultiByteToWideChar(0, 0,
                                              reinterpret_cast<const char *>(packet + 5),
                                              textLength,
                                              text,
                                              1023);
    text[converted] = L'\0';

    RectBounds bounds;
    GetBounds(&bounds);

    if (g_pSimpleHelpPane != NULL)
        g_pSimpleHelpPane->Close(true);

    new SimpleHelpPane(text,
                       this,
                       (bounds.left + bounds.right) / 2,
                       helpId,
                       10000);
}

// UID:00018L | by-memory/0x004ede80-0x004edfa4.BackPaneHelpPacketDisplayV2.md | Completion:88 | Confidence:91
void BackPane::ShowHelpFromPacketV2(const unsigned char *packet)
{
    const int helpId = ReadPacketWord(packet + 1) & 0x3fff;
    const unsigned short textLength = ReadPacketWord(packet + 3);

    if (textLength == 0 || textLength > 1023)
        return;

    wchar_t text[1024];
    const int converted = MultiByteToWideChar(0, 0,
                                              reinterpret_cast<const char *>(packet + 5),
                                              textLength,
                                              text,
                                              1023);
    text[converted] = L'\0';

    RectBounds bounds;
    GetBounds(&bounds);

    if (g_pSimpleHelpPane != NULL)
        g_pSimpleHelpPane->Close(true);

    new SimpleHelpPane(text,
                       this,
                       (bounds.left + bounds.right) / 2,
                       helpId,
                       10000);
}

// UID:00018M | by-memory/0x004ef510-0x004ef62e.BackPaneHelpPacketDisplayV3.md | Completion:88 | Confidence:91
void BackPane::ShowHelpFromPacketV3(const unsigned char *packet)
{
    const int helpId = packet[2];
    const unsigned short textLength = ReadPacketWord(packet + 3);

    if (textLength == 0 || textLength > 1023)
        return;

    wchar_t text[1024];
    const int converted = MultiByteToWideChar(0, 0,
                                              reinterpret_cast<const char *>(packet + 5),
                                              textLength,
                                              text,
                                              1023);
    text[converted] = L'\0';

    RectBounds bounds;
    GetBounds(&bounds);

    if (g_pSimpleHelpPane != NULL)
        g_pSimpleHelpPane->Close(true);

    new SimpleHelpPane(text,
                       this,
                       (bounds.left + bounds.right) / 2,
                       helpId,
                       10000);
}

// UID:000488 | by-memory/0x00612f38-0x00612f3c.BackGroundPaneRttiLocatorPointer.md | Completion:88 | Confidence:93
// Compiler-generated RTTI complete-object-locator pointer for
// BackGroundPane immediately before the BackGroundPane vtable island.
// Generated from the BackGroundPane class definition; no standalone
// source declaration or handwritten dword belongs here.

// UID:00028J | by-memory/0x0067a740-0x0067a744.g_pBackPane.md | Completion:88 | Confidence:92
BackPane *g_pBackPane = NULL;

// UID:0002VV | by-memory/0x0067ab7c-0x0067ab80.g_pBackGroundPane.md | Completion:89 | Confidence:92
BackGroundPane *g_pBackGroundPane = NULL;
