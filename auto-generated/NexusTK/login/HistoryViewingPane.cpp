// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JW
// Source by-file doc: by-file/HistoryViewingPane.md
// UID:00054J | by-item/HistoryViewingPaneFileShell.md | Completion:93 | Confidence:94
#include "HistoryViewingPane.h"

#include "../app/Application.h"
#include "../render/EPFTileContext.h"
#include "../render/ImageLib.h"
#include "../ui/MainUiGraph.h"
#include "../ui/core/Event.h"
#include "../ui/core/ScreenPane.h"

// UID:000066 | by-class/HistoryViewingPane.md | Completion:93 | Confidence:95
// UID:0001A0 | by-memory/0x004ffd40-0x004ffd79.HistoryViewingPaneAdvancePage.md | Completion:92 | Confidence:94
void HistoryViewingPane::AdvancePage()
{
    if (m_frameIndex >= m_lastFrameIndex)
        return;

    if (m_frameIndex < 3)
        m_frameIndex = 3;
    else
        ++m_frameIndex;

    InvalidateRect(&m_visibleBounds);
}

// UID:0001A1 | by-memory/0x004ffd80-0x0050008b.HistoryViewingPaneCore.md | Completion:93 | Confidence:95
HistoryViewingPane::HistoryViewingPane(const wchar_t *resourceName)
    : Pane(0),
      m_frameIndex(0),
      m_lastFrameIndex(g_pEPFLib->GetEntryCount(resourceName) - 1),
      m_pageDelayMs(10000)
{
    m_resourceName = resourceName;

    RectBounds bounds;
    bounds.SetLTRB(0, 0, g_screenWidth, g_screenHeight);
    AddToLayer(&bounds, 0, NULL, g_pStatusPaneLayer);
    SetPaneOrder(NULL, g_pScreenPane);
    ScheduleTimer(0, m_pageDelayMs, 0, 0);
}

bool HistoryViewingPane::HandleKeyOrTextEvent(Event *event)
{
    if (event->m_type == kEventKeyDown)
    {
        unsigned char key = g_pEventMan->TranslateEventKey(
            event->m_payload.m_key.m_key,
            event->m_payload.m_key.m_modifiers);

        if (key == '\r' || key == kPaneKeyEscape || key == ' ')
        {
            if (m_frameIndex < m_lastFrameIndex)
            {
                AdvancePage();
                RemovePendingTimers();
                ScheduleTimer(0, m_pageDelayMs, 0, 0);
            }
            else
            {
                MarkForDeletion();
            }
        }
    }

    return true;
}

bool HistoryViewingPane::OnTimer(int, int, int)
{
    return true;
}

bool HistoryViewingPane::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type != kEventLeftButtonUp &&
        event->m_type != kEventRightButtonUp)
        return true;

    if (m_frameIndex >= m_lastFrameIndex)
    {
        MarkForDeletion();
        return true;
    }

    AdvancePage();
    RemovePendingTimers();
    ScheduleTimer(0, m_pageDelayMs, 0, 0);
    return true;
}

void HistoryViewingPane::OnPaint()
{
    EPFTileContext frame;
    g_pEPFLib->LookupLayoutEntry(
        m_resourceName.c_str(), m_frameIndex, &frame);
    RenderTileFrame(
        &frame, &frame.bounds, &m_visibleBounds,
        0, L"NPAL4.PAL", NULL);
}

// UID:0000R3 | by-global/g_pHistoryViewingPane.md | Completion:92 | Confidence:94
HistoryViewingPane *g_pHistoryViewingPane = NULL;

template <>
Singleton<HistoryViewingPane>::Singleton()
{
    g_pHistoryViewingPane = static_cast<HistoryViewingPane *>(this);
}

template <>
Singleton<HistoryViewingPane>::~Singleton()
{
    g_pHistoryViewingPane = NULL;
}
