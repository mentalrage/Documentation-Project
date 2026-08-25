// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OV
// Source by-file doc: by-file/TotemFrame.md
// UID:0000SK | by-global/g_pTotemFrame.md | Completion:92 | Confidence:94
class TotemFrame;

TotemFrame *g_pTotemFrame = 0;

// UID:0000F4 | by-class/TotemFrame.md | Completion:92 | Confidence:94
class TotemFrame : public Pane, public Singleton<TotemFrame>
{
public:
    TotemFrame();
    virtual ~TotemFrame();
    virtual void OnPaint();
};

extern TotemFrame *g_pTotemFrame;

// UID:0001KC | by-memory/0x00598cc0-0x00598ecf.TotemFrame.md | Completion:92 | Confidence:94
TotemFrame::TotemFrame()
    : Pane(0),
      Singleton<TotemFrame>()
{
    RectBounds bounds;
    InitRectBounds(&bounds, 435, 11, 627, 299);
    AttachToMainUiLayer(bounds, 0);
    RegisterWithPaneDispatcher(0);
}

TotemFrame::~TotemFrame()
{
}

void TotemFrame::OnPaint()
{
    EPFTileContext tile;
    FrameDrawRecord drawRecord;


    const int frameIndex =
        static_cast<short>(g_pOldUserStatusPane->GetSpiritId());

    g_pEPFLib->LookupLayoutEntry(L"TOTFRAME.EPD", frameIndex, &tile);
    RenderTileFrame(&tile, &drawRecord, &m_bounds, 0, L"NPAL7.PAL", 0);
}

// UID:0003E3 | by-memory\0x0062e3dc-0x0062e460.TotemFrameVtableData.md | Completion:86 | Confidence:92 | Empty Emitter Marker

// UID:0003E4 | by-memory\0x0062e460-0x0062e47c.TotemFrameResourceStringData.md | Completion:87 | Confidence:93 | Empty Emitter Marker
