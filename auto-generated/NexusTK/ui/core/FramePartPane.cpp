// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 000578
// Source by-file doc: by-file/FramePartPane.md
// UID:00005I | by-class/FramePartPane.md | Completion:92 | Confidence:94
#include "FramePartPane.h"
#include "BlackHole.h"

// UID:0001PF | by-memory/0x0069b33c-0x0069b350.FramePartPaneSlots.md | Completion:88 | Confidence:92
static FramePartPane *g_framePartPanes[5];

// UID:00022F | by-memory/0x004b7120-0x004b731f.BuildFramePartPanes.md | Completion:88 | Confidence:89
void BuildFramePartPanes()
{
    RectBounds bounds;

    bounds.Set(0, 0, 198, 6);
    bounds.Offset(118, 12);
    g_framePartPanes[0] = new FramePartPane(4, bounds);

    bounds.Set(0, 0, 56, 93);
    bounds.Offset(14, 12);
    g_framePartPanes[1] = new FramePartPane(0, bounds);

    bounds.Set(0, 0, 57, 93);
    bounds.Offset(365, 12);
    g_framePartPanes[2] = new FramePartPane(1, bounds);

    bounds.Set(0, 0, 77, 37);
    bounds.Offset(14, 335);
    g_framePartPanes[3] = new FramePartPane(2, bounds);

    bounds.Set(0, 0, 79, 39);
    bounds.Offset(343, 333);
    g_framePartPanes[4] = new FramePartPane(3, bounds);
}

// UID:00015N | by-memory/0x004b7320-0x004b73a3.FramePartPaneSlotCleanup.md | Completion:88 | Confidence:90
void ReleaseFramePartPanes()
{
    for (int i = 0; i < 5; ++i) {
        if (g_framePartPanes[i] != 0) {
            delete g_framePartPanes[i];
            g_framePartPanes[i] = 0;
        }
    }
}

// UID:00015O | by-memory/0x004b73b0-0x004b7661.FramePartPane.md | Completion:89 | Confidence:93
void FramePartPane::OnChangeMessage(LObject *, Message *message)
{
    if (message->m_type != kFramePartNotificationTag)
        return;

    g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
    for (int i = 0; i < 5; ++i)
        g_framePartPanes[i] = 0;
}

void FramePartPane::OnPaint()
{
    EPFTileContext tile;
    const wchar_t *resourceName =
        g_useEpfAssets ? L"FRMPART.EPF" : L"FRMPART.EPD";

    g_pEPFLib->LookupLayoutEntry(resourceName, m_partIndex, &tile);

    RenderTileFrame(&tile, &tile.bounds, &m_visibleBounds, 0, 0, 0);
}

FramePartPane::FramePartPane(int partIndex, const RectBounds &bounds)
    : Pane(1),
      m_partIndex(partIndex)
{
    AddToLayer(bounds, 0, 0, g_pMainLayer);
    g_pBackPane->RegisterChangeListener(
        this, kFramePartNotificationTag, false);
}

FramePartPane::~FramePartPane()
{
    g_pBackPane->UnregisterChangeListener(
        this, kFramePartNotificationTag, false);
    RemoveFromLayer();
}
