// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 000577
// Source by-file doc: by-file/AboveFrame.md
// UID:000005 | by-class/AboveFrame.md | Completion:93 | Confidence:95
#include "AboveFrame.h"

// UID:0001P1 | by-memory/0x0067a834-0x0067a874.AboveFrameSlots.md | Completion:95 | Confidence:96
static AboveFrame *g_pAboveFrameTop;
static AboveFrame *g_pAboveFrameRight;
static AboveFrame *g_pAboveFrameLeft;
static AboveFrame *g_pDynamicAboveFrame;

static AboveFrame *g_pLegacyAboveFrameTopLeft;
static AboveFrame *g_pLegacyAboveFrameLeftSide[5];
static AboveFrame *g_pLegacyAboveFrameRightSide[5];

// UID:0000YH | by-memory/0x004610f0-0x0046178a.AboveFrame.md | Completion:89 | Confidence:93
AboveFrame::AboveFrame(int frameIndex, int top, int left)
    : Pane(1),
      m_framePaletteMode(0)
{
    if (g_useEpfAssets) {
        if (frameIndex >= 4) {
            m_framePaletteMode = 1;
            g_pEPFLib->LookupLayoutEntry(
                L"TABS.EPF", frameIndex + (frameIndex - 4 < 2) - 5,
                &m_tileContext);
        } else {
            g_pEPFLib->LookupLayoutEntry(
                L"FRMPART.EPF", frameIndex, &m_tileContext);
        }
    } else {
        g_pEPFLib->LookupLayoutEntry(
            L"FRMPART.EPD", frameIndex, &m_tileContext);
    }

    m_bounds = m_tileContext.bounds;
    m_bounds.Offset(left, top);
    SetBounds(m_bounds, false);
    AddToLayer(m_bounds, 0, 0, g_pMainLayer);
    g_pBackPane->RegisterChangeListener(
        this, kFramePartNotificationTag, false);
}

AboveFrame::~AboveFrame()
{
    g_pBackPane->UnregisterChangeListener(
        this, kFramePartNotificationTag, false);
}

void AboveFrame::OnPaint()
{
    const wchar_t *paletteName;

    if (!g_useEpfAssets)
        paletteName = L"NPAL5.PAL";
    else if (m_framePaletteMode)
        paletteName = L"TABS.PAL";
    else
        paletteName = L"FRMPART.PAL";

    RenderTileFrame(
        &m_tileContext, &m_tileContext.bounds, &m_tileContext.bounds,
        1, paletteName, 0);
}

void AboveFrame::OnChangeMessage(LObject *, Message *message)
{
    if (message->m_type == kFramePartNotificationTag)
        MarkForDeletion();
}

// UID:0000U2 | by-item/BuildAboveFrameBorder_00461310.md | Completion:93 | Confidence:95
void BuildAboveFrameBorder()
{
    if (g_useEpfAssets) {
        g_pAboveFrameTop = new AboveFrame(0, 0, 0);
        g_pAboveFrameLeft = new AboveFrame(1, 9, 0);
        g_pAboveFrameRight = new AboveFrame(2, 9, 0x328);
        g_pDynamicAboveFrame = new AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5, 0x4f, 0x328);
        return;
    }

    g_pLegacyAboveFrameTopLeft = new AboveFrame(0, 0x0c, 0x0e);
    g_pAboveFrameTop = new AboveFrame(1, 0x0c, 0x7d);
    g_pAboveFrameRight = new AboveFrame(2, 0x0c, 0x17a);

    for (int y = 0x5c, i = 0; y != 0x197; y += 0x3f, ++i) {
        g_pLegacyAboveFrameLeftSide[i] = new AboveFrame(3, y + 6, 0x0e);
        g_pLegacyAboveFrameRightSide[i] = new AboveFrame(4, y, 0x1a4);
    }
}

// UID:0000YI | by-memory/0x004615b0-0x00461658.AboveFrameRefreshHelpers.md | Completion:92 | Confidence:95
void ReleaseDynamicAboveFrame()
{
    if (g_pDynamicAboveFrame != 0)
        delete g_pDynamicAboveFrame;
}

void RecreateDynamicAboveFrame()
{
    g_pDynamicAboveFrame = new AboveFrame(g_pGeneralPurposePanel->m_activeChildIndex + 5, 0x4f, 0x328);
}
