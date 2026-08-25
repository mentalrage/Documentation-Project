// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NE
// Source by-file doc: by-file/ScrollableControlPane.md
// UID:0000CE | by-class/ScrollableControlPane.md | Completion:92 | Confidence:94
#include "ScrollableControlPane.h"

// UID:0004KC | by-memory/0x004985a0-0x00498656.ScrollableControlPaneConstructor.md | Completion:92 | Confidence:94
ScrollableControlPane::ScrollableControlPane(
    const RectBounds *bounds,
    ScrollablePane *scrollablePane,
    int horizontalScrollBarOffset,
    int verticalScrollBarOffset,
    int scrollBarInset)
    : ControlPane(4, bounds),
      m_scrollablePane(scrollablePane)
{
    m_scrollablePane->m_horizontalScrollBarOffset = horizontalScrollBarOffset;
    m_scrollablePane->m_verticalScrollBarOffset = verticalScrollBarOffset;
    m_scrollablePane->m_scrollBarInset = scrollBarInset;
    m_scrollablePane->SetBounds(bounds, 0);
    m_controlActive = false;
    m_controlFlags = 1;
}

// UID:0004KD | by-memory/0x00498660-0x00498695.ScrollableControlPaneDestructor.md | Completion:91 | Confidence:94
ScrollableControlPane::~ScrollableControlPane()
{
    delete m_scrollablePane;
}

// UID:0004KE | by-memory/0x004986a0-0x004986af.ScrollableControlPaneSetScrollTargetValueRaw.md | Completion:90 | Confidence:93
void ScrollableControlPane::SetScrollTargetValue(short targetValue, char axis)
{
    m_scrollablePane->SetScrollTargetValue(targetValue, axis);
}

// UID:0004KF | by-memory/0x004986b0-0x004986bf.ScrollableControlPaneSetScrollCurrentValueRaw.md | Completion:90 | Confidence:93
void ScrollableControlPane::SetScrollCurrentValue(short currentValue, char axis)
{
    m_scrollablePane->SetScrollCurrentValue(currentValue, axis);
}

// UID:0004KG | by-memory/0x004986c0-0x004986cf.ScrollableControlPaneGetScrollMaxRaw.md | Completion:90 | Confidence:93
short ScrollableControlPane::GetScrollMax(char axis) const
{
    return m_scrollablePane->GetScrollMax(axis);
}

// UID:0004KH | by-memory/0x004986d0-0x004986df.ScrollableControlPaneGetScrollPositionRaw.md | Completion:90 | Confidence:93
short ScrollableControlPane::GetScrollPosition(char axis) const
{
    return m_scrollablePane->GetScrollPosition(axis);
}

// UID:0004KI | by-memory/0x004986e0-0x004986fb.ScrollableControlPaneUpdateRenderRegion.md | Completion:92 | Confidence:94
void ScrollableControlPane::UpdateRenderRegion(const RectBounds *bounds)
{
    GrafPort::UpdateRenderRegion(bounds);
    m_scrollablePane->UpdateRenderRegion(bounds);
}

// UID:0004KJ | by-memory/0x00498700-0x00498718.ScrollableControlPaneHandlePointerOrMouseEvent.md | Completion:92 | Confidence:94
bool ScrollableControlPane::HandlePointerOrMouseEvent(Event *event)
{
    return m_scrollablePane->HandlePointerOrMouseEvent(event);
}

// UID:0004KK | by-memory/0x00498720-0x00498738.ScrollableControlPaneHandleKeyOrTextEvent.md | Completion:92 | Confidence:94
bool ScrollableControlPane::HandleKeyOrTextEvent(Event *event)
{
    return m_scrollablePane->HandleKeyOrTextEvent(event);
}

// UID:0004KL | by-memory/0x00498740-0x00498758.ScrollableControlPaneHandlePacketEvent.md | Completion:92 | Confidence:94
bool ScrollableControlPane::HandlePacketEvent(Event *event)
{
    return m_scrollablePane->HandlePacketEvent(event);
}

// UID:0004KM | by-memory/0x00498760-0x0049877a.ScrollableControlPaneEnable.md | Completion:91 | Confidence:93
void ScrollableControlPane::Enable()
{
    if (!m_controlVisible)
    {
        m_controlVisible = true;
        InvalidateRect(&m_bounds);
    }
}

// UID:0004KN | by-memory/0x00498780-0x0049879a.ScrollableControlPaneDisable.md | Completion:91 | Confidence:93
void ScrollableControlPane::Disable()
{
    if (m_controlVisible)
    {
        m_controlVisible = false;
        InvalidateRect(&m_bounds);
    }
}

// UID:0004KO | by-memory/0x004987a0-0x0049885c.ScrollableControlPaneAddToLayer.md | Completion:92 | Confidence:94
void ScrollableControlPane::AddToLayer(const RectBounds *bounds,
                                       int order,
                                       Pane *previousPane,
                                       Layer *layer)
{
    Pane::AddToLayer(bounds, order, previousPane, layer);

    RectBounds childBounds = *bounds;
    OffsetRect(&childBounds, -childBounds.left, -childBounds.top);
    GrafPort::UpdateRenderRegion(&childBounds);
    m_scrollablePane->UpdateRenderRegion(&childBounds);

    childBounds = *bounds;
    OffsetRect(&childBounds, -childBounds.left, -childBounds.top);
    m_scrollablePane->AddToLayer(&childBounds, 0, this, layer);
}

// UID:0004KP | by-memory/0x00498860-0x00498876.ScrollableControlPaneRemoveFromLayer.md | Completion:92 | Confidence:94
void ScrollableControlPane::RemoveFromLayer()
{
    m_scrollablePane->RemoveFromLayer();
    Pane::RemoveFromLayer();
}

// UID:0004KQ | by-memory/0x00498880-0x004988cd.ScrollableControlPaneOnPaint.md | Completion:92 | Confidence:94
void ScrollableControlPane::OnPaint()
{
    if (g_useEpfAssets != 1)
    {
        SetDrawColor(0);
        FillRect(&m_bounds);

        if (m_controlVisible && m_controlActive)
        {
            SetDrawColor(128);
            m_drawMode = 0;
            DrawRectFrame(&m_bounds);
        }
    }
}

// UID:0002PE | by-memory/0x0049b900-0x0049b905.ScrollableControlPaneHitTestPart.md | Completion:92 | Confidence:94
unsigned char ScrollableControlPane::HitTestPart(int x, int y)
{
    return 18;
}
