// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NG
// Source by-file doc: by-file/ScrollCollectionPane.md
// UID:0000CG | by-class/ScrollCollectionPane.md | Completion:93 | Confidence:93
#include "ScrollCollectionPane.h"
#include "ScrollBar.h"

#include "CollectionPane.h"
#include "Event.h"
#include "../../render/EPFTileContext.h"

// UID:0004X3 | by-memory/0x00561db0-0x00561e51.ScrollCollectionPaneConstructor.md | Completion:92 | Confidence:94
ScrollCollectionPane::ScrollCollectionPane(unsigned char orientation)
    : Pane(1),
      m_scrollSkinIndex(0),
      m_scrollStyle(1),
      m_thumbDragActive(false),
      m_orientation(orientation),
      m_scrollPosition(0),
      m_scrollRange(0),
      m_scrollEnabled(true),
      m_highlightPart(kScrollCollectionPartNone),
      m_activePart(kScrollCollectionPartNone)
{
    InitPointPair(&m_thumbDragOffset, 0, 0);
}

// UID:0004X4 | by-memory/0x00561e60-0x00561e87.ScrollCollectionPaneSetSkinIndexRaw.md | Completion:89 | Confidence:92
void ScrollCollectionPane::SetSkinIndex(unsigned short skinIndex)
{
    if (m_scrollSkinIndex != skinIndex) {
        m_scrollSkinIndex = skinIndex;
        InvalidateRect(&m_bounds);
    }
}

// UID:0004X6 | by-memory/0x00561e90-0x00561eb4.ScrollCollectionPaneSetScrollStyleRaw.md | Completion:89 | Confidence:92
void ScrollCollectionPane::SetScrollStyle(unsigned char scrollStyle)
{
    if (m_scrollStyle != scrollStyle) {
        m_scrollStyle = scrollStyle;
        InvalidateRect(&m_bounds);
    }
}

// UID:0004X7 | by-memory/0x00561ec0-0x00561f1b.ScrollCollectionPaneSetMaxRange.md | Completion:92 | Confidence:94
void ScrollCollectionPane::SetMaxRange(short maxRange)
{
    if (maxRange < 0) {
        maxRange = 0;
    }
    if (maxRange > 30000) {
        maxRange = 30000;
    }

    if (m_scrollRange == maxRange) {
        return;
    }

    if (m_scrollPosition > maxRange) {
        m_scrollPosition = maxRange;
        InvalidateRect(&m_visibleBounds);
    }

    m_scrollRange = maxRange;
    InvalidateRect(&m_visibleBounds);
}

// UID:0004X8 | by-memory/0x00561f20-0x00561f47.ScrollCollectionPaneSetScrollPosition.md | Completion:92 | Confidence:94
void ScrollCollectionPane::SetScrollPosition(short position)
{
    if (m_scrollPosition == position) {
        return;
    }

    m_scrollPosition = position;
    InvalidateRect(&m_visibleBounds);
}

// UID:0004X9 | by-memory/0x00561f50-0x00561f6a.ScrollCollectionPaneEnable.md | Completion:91 | Confidence:94
void ScrollCollectionPane::Enable()
{
    if (!m_scrollEnabled) {
        m_scrollEnabled = true;
        InvalidateRect(&m_bounds);
    }
}

// UID:0004XA | by-memory/0x00561f70-0x00561f8a.ScrollCollectionPaneDisableRaw.md | Completion:89 | Confidence:92
void ScrollCollectionPane::Disable()
{
    if (m_scrollEnabled) {
        m_scrollEnabled = false;
        InvalidateRect(&m_bounds);
    }
}

// UID:0004XB | by-memory/0x00561f90-0x00561faa.ScrollCollectionPaneCanScrollRaw.md | Completion:90 | Confidence:93
bool ScrollCollectionPane::CanScroll() const
{
    return m_scrollEnabled && m_scrollRange > 0;
}

// UID:0004XL | by-memory/0x00561fb0-0x00562191.ScrollCollectionPaneHandlePointerOrMouseEvent.md | Completion:92 | Confidence:94
bool ScrollCollectionPane::HandlePointerOrMouseEvent(Event *event)
{
    bool handled = false;
    RectBounds partRect;
    const int mouseY = event->m_pointer.m_y;
    const int mouseX = event->m_pointer.m_x;

    switch (event->m_type) {
    case kEventPointerMove:
        if (m_activePart != kScrollCollectionPartNone) {
            InvalidateRect(&m_bounds);
            handled = true;
        }
        break;

    case kEventLeftButtonDown:
        if (!PointInRect(mouseY, mouseX, &m_bounds) || !CanScroll()) {
            return false;
        }

        if (m_activePart == kScrollCollectionPartNone) {
            const ScrollCollectionPart part =
                HitTestScrollRegion(mouseY, mouseX);
            if (part != kScrollCollectionPartNone) {
                CaptureMouse();
                BeginPartInteraction(part, mouseY, mouseX);
                InvalidateRect(&m_bounds);
            }
        }

        m_thumbDragActive = true;
        handled = true;
        break;

    case kEventLeftButtonUp:
        if (m_activePart != kScrollCollectionPartNone) {
            ReleaseMouseCapture();
            RemovePendingTimers();

            const ScrollCollectionPart oldPart =
                static_cast<ScrollCollectionPart>(m_highlightPart);
            m_activePart = kScrollCollectionPartNone;
            if (oldPart != kScrollCollectionPartNone) {
                GetPartRect(oldPart, &partRect);
                InvalidateRect(&partRect);
                m_highlightPart = kScrollCollectionPartNone;
            }
            handled = true;
        }

        m_thumbDragActive = false;
        InvalidateRect(&m_bounds);
        break;

    default:
        break;
    }

    return handled;
}

// UID:0004XM | by-memory/0x005621a0-0x005621a5.ScrollCollectionPaneHandleKeyOrTextEvent.md | Completion:91 | Confidence:94
bool ScrollCollectionPane::HandleKeyOrTextEvent(Event *)
{
    return false;
}

// UID:0004XN | by-memory/0x005621b0-0x005621e3.ScrollCollectionPaneOnTimer.md | Completion:91 | Confidence:94
bool ScrollCollectionPane::OnTimer(int timerId, int, int)
{
    if (timerId == 0 &&
        m_activePart != kScrollCollectionPartNone) {
        UpdateDragScroll();
        ScheduleTimer(0, 30, 0, 0);
    }
    return true;
}

// UID:0004XO | by-memory/0x005621f0-0x005628d0.ScrollCollectionPaneOnPaint.md | Completion:92 | Confidence:94
void ScrollCollectionPane::OnPaint()
{
    EPFTileContext tile;
    RectBounds clipRect;
    RectBounds partRect;
    RectBounds drawRect;
    RectBounds stripRect;

    EPFTileContext_Initialize(&tile);
    GetClipRect(&clipRect);
    if (!CanScroll()) {
        return;
    }

    const bool horizontal = (m_orientation != 0);
    for (int pass = 0; pass < 2; ++pass) {
        const ScrollCollectionPart part = pass == 0
            ? kScrollCollectionPartPageBeforeThumb
            : kScrollCollectionPartPageAfterThumb;
        GetPartRect(part, &partRect);
        if (!IntersectRects(&drawRect, &partRect, &clipRect)) {
            continue;
        }

        SetDrawColor(0);
        FillRect(&drawRect);
        SetDrawColor(128);

        const int fillFrame = horizontal ? 4 : 1;
        const int capFrame = horizontal
            ? (pass == 0 ? 3 : 5)
            : (pass == 0 ? 0 : 2);
        g_pEPFLib->LookupLayoutEntry(
            L"SLIDEBG.EPF", fillFrame, &tile);

        stripRect = drawRect;
        if (horizontal) {
            stripRect.right = stripRect.left + 1;
            while (stripRect.left < drawRect.right) {
                RenderTileFrame(this, &tile, &stripRect, L"SLIDEBG.PAL");
                OffsetRect(&stripRect, 1, 0);
            }
        } else {
            stripRect.bottom = stripRect.top + 1;
            while (stripRect.top < drawRect.bottom) {
                RenderTileFrame(this, &tile, &stripRect, L"SLIDEBG.PAL");
                OffsetRect(&stripRect, 0, 1);
            }
        }

        g_pEPFLib->LookupLayoutEntry(
            L"SLIDEBG.EPF", capFrame, &tile);
        RenderTileFrame(this, &tile, &drawRect, L"SLIDEBG.PAL");
    }

    GetPartRect(kScrollCollectionPartThumb, &partRect);
    if (IntersectRects(&drawRect, &partRect, &clipRect)) {
        SetDrawColor(0);
        FillRect(&drawRect);
        SetDrawColor(128);
        g_pEPFLib->LookupLayoutEntry(
            L"SCRBUTT.EPF",
            m_highlightPart == kScrollCollectionPartThumb ? 1 : 0,
            &tile);
        RenderTileFrame(this, &tile, &drawRect, L"BUTTON.PAL");
    }
}

// UID:0001GU | by-memory/0x005628d0-0x00562bed.ScrollCollectionPaneHitTestScrollRegion.md | Completion:91 | Confidence:91
ScrollCollectionPart ScrollCollectionPane::HitTestScrollRegion(int localY,
                                                               int localX)
{
    for (int partValue = kScrollCollectionPartLeading;
         partValue <= kScrollCollectionPartTrailing;
         ++partValue) {
        const ScrollCollectionPart part =
            static_cast<ScrollCollectionPart>(partValue);
        Point cursor;
        Point origin;
        RectBounds rect;

        g_pEventMan->GetCursorPosition(&cursor);
        GetScreenOffset(&origin);

        if (origin.x == -1000 && origin.y == -1000) {
            InitRectBounds(&rect, 0, 0, 0, 0);
        } else {
            cursor.x -= origin.x;
            cursor.y -= origin.y;
            rect = m_bounds;

            if (m_orientation == 0) {
                const int thumbSpan =
                    kScrollPanePartExtentBySkin[m_scrollSkinIndex];

                if (part == kScrollCollectionPartLeading) {
                    rect.bottom = rect.top;
                } else if (part == kScrollCollectionPartTrailing) {
                    rect.top = rect.bottom;
                } else if (m_scrollEnabled && m_scrollRange > 0) {
                    const int trackTop = m_bounds.top;
                    const int thumbLimit = m_bounds.bottom - thumbSpan;
                    int thumbTop;

                    if (m_thumbDragActive) {
                        thumbTop = m_bounds.top + cursor.y -
                                   m_thumbDragOffset.y;
                        if (thumbTop < trackTop) {
                            thumbTop = trackTop;
                        }
                        if (thumbTop > thumbLimit) {
                            thumbTop = thumbLimit;
                        }
                    } else {
                        thumbTop = trackTop +
                            ((thumbLimit - trackTop) * m_scrollPosition) /
                                m_scrollRange;
                    }

                    const int thumbBottom = thumbTop + thumbSpan;

                    if (part == kScrollCollectionPartThumb) {
                        rect.top = thumbTop;
                        rect.bottom = thumbBottom;
                    } else if (part == kScrollCollectionPartPageBeforeThumb) {
                        rect.bottom = thumbTop;
                    } else if (part == kScrollCollectionPartPageAfterThumb) {
                        rect.top = thumbBottom;
                    }
                } else if (part == kScrollCollectionPartThumb) {
                    rect.top += thumbSpan;
                    rect.bottom -= thumbSpan;
                } else {
                    InitRectBounds(&rect, 0, 0, 0, 0);
                }
            } else {
                const int thumbSpan = m_bounds.bottom - m_bounds.top;

                if (part == kScrollCollectionPartLeading) {
                    rect.right = rect.left;
                } else if (part == kScrollCollectionPartTrailing) {
                    rect.left = rect.right;
                } else if (m_scrollEnabled && m_scrollRange > 0) {
                    const int trackLeft = m_bounds.left;
                    const int thumbLimit = m_bounds.right - thumbSpan;
                    const int thumbLeft = trackLeft +
                        ((thumbLimit - trackLeft) * m_scrollPosition) /
                            m_scrollRange;
                    const int thumbRight = thumbLeft + thumbSpan;

                    if (part == kScrollCollectionPartThumb) {
                        rect.left = thumbLeft;
                        rect.right = thumbRight;
                    } else if (part == kScrollCollectionPartPageBeforeThumb) {
                        rect.right = thumbLeft;
                    } else if (part == kScrollCollectionPartPageAfterThumb) {
                        rect.left = thumbRight;
                    }
                } else if (part == kScrollCollectionPartThumb) {
                    rect.left += thumbSpan;
                    rect.right -= thumbSpan;
                } else {
                    InitRectBounds(&rect, 0, 0, 0, 0);
                }
            }
        }

        if (PointInRect(localY, localX, &rect)) {
            return part;
        }
    }

    return kScrollCollectionPartNone;
}

// UID:0004XP | by-memory/0x00562bf0-0x00562e77.ScrollCollectionPaneGetPartRect.md | Completion:92 | Confidence:94
void ScrollCollectionPane::GetPartRect(ScrollCollectionPart part,
                                       RectBounds *bounds)
{
    Point cursor;
    Point origin;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.x == -1000 && origin.y == -1000) {
        return;
    }
    cursor.x -= origin.x;
    cursor.y -= origin.y;

    *bounds = m_bounds;
    const bool horizontal = (m_orientation != 0);
    const int thumbSpan = horizontal
        ? m_bounds.bottom - m_bounds.top
        : kScrollPanePartExtentBySkin[m_scrollSkinIndex];

    if (part == kScrollCollectionPartLeading) {
        if (horizontal) {
            bounds->right = bounds->left;
        } else {
            bounds->bottom = bounds->top;
        }
        return;
    }
    if (part == kScrollCollectionPartTrailing) {
        if (horizontal) {
            bounds->left = bounds->right;
        } else {
            bounds->top = bounds->bottom;
        }
        return;
    }

    if (!CanScroll()) {
        if (part == kScrollCollectionPartThumb) {
            if (horizontal) {
                bounds->left += thumbSpan;
                bounds->right -= thumbSpan;
            } else {
                bounds->top += thumbSpan;
                bounds->bottom -= thumbSpan;
            }
        } else {
            InitRectBounds(bounds, 0, 0, 0, 0);
        }
        return;
    }

    if (horizontal) {
        const int trackStart = m_bounds.left;
        const int thumbLimit = m_bounds.right - thumbSpan;
        const int thumbStart = trackStart +
            (m_scrollPosition * (thumbLimit - trackStart)) /
                m_scrollRange;
        const int thumbEnd = thumbStart + thumbSpan;
        if (part == kScrollCollectionPartThumb) {
            bounds->left = thumbStart;
            bounds->right = thumbEnd;
        } else if (part == kScrollCollectionPartPageBeforeThumb) {
            bounds->right = thumbStart;
        } else if (part == kScrollCollectionPartPageAfterThumb) {
            bounds->left = thumbEnd;
        }
    } else {
        const int trackStart = m_bounds.top;
        const int thumbLimit = m_bounds.bottom - thumbSpan;
        int thumbStart;
        if (m_thumbDragActive) {
            thumbStart = m_bounds.top + cursor.y - m_thumbDragOffset.y;
            if (thumbStart < trackStart) {
                thumbStart = trackStart;
            }
            if (thumbStart > thumbLimit) {
                thumbStart = thumbLimit;
            }
        } else {
            thumbStart = trackStart +
                (m_scrollPosition * (thumbLimit - trackStart)) /
                    m_scrollRange;
        }
        const int thumbEnd = thumbStart + thumbSpan;
        if (part == kScrollCollectionPartThumb) {
            bounds->top = thumbStart;
            bounds->bottom = thumbEnd;
        } else if (part == kScrollCollectionPartPageBeforeThumb) {
            bounds->bottom = thumbStart;
        } else if (part == kScrollCollectionPartPageAfterThumb) {
            bounds->top = thumbEnd;
        }
    }
}

// UID:0003MX | by-memory/0x00562e80-0x00562ef0.ScrollCollectionPaneSetHighlightedRegionRaw.md | Completion:90 | Confidence:91
void ScrollCollectionPane::SetHighlightedPart(ScrollCollectionPart part)
{
    RectBounds rect;
    ScrollCollectionPart oldPart;

    oldPart = static_cast<ScrollCollectionPart>(m_highlightPart);
    if (oldPart == part) {
        return;
    }

    if (oldPart != kScrollCollectionPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
    }

    if (part != kScrollCollectionPartNone) {
        GetPartRect(part, &rect);
        InvalidateRect(&rect);
    }

    m_highlightPart = static_cast<signed char>(part);
}

// UID:0003MY | by-memory/0x00562ef0-0x00562fb0.ScrollCollectionPaneSetActiveRegionAndStartDragRaw.md | Completion:90 | Confidence:91
void ScrollCollectionPane::BeginPartInteraction(ScrollCollectionPart part, int mouseY, int mouseX)
{
    RectBounds rect;

    if (part == kScrollCollectionPartThumb) {
        if (m_highlightPart != kScrollCollectionPartThumb) {
            if (m_highlightPart != kScrollCollectionPartNone) {
                GetPartRect(static_cast<ScrollCollectionPart>(m_highlightPart), &rect);
                InvalidateRect(&rect);
            }

            GetPartRect(kScrollCollectionPartThumb, &rect);
            InvalidateRect(&rect);
            m_highlightPart = static_cast<signed char>(kScrollCollectionPartThumb);
        }

        GetPartRect(kScrollCollectionPartThumb, &rect);
        InitPointPair(&m_thumbDragOffset, mouseY - rect.top, mouseX - rect.left);
    }

    m_activePart = static_cast<signed char>(part);
    UpdateDragScroll();
    ScheduleTimer(0, 200, 0, 0);
}

// UID:0001GW | by-memory/0x00562fb0-0x00563070.ScrollCollectionPaneUpdateDragScroll.md | Completion:91 | Confidence:91
void ScrollCollectionPane::UpdateDragScroll()
{
    Point cursor;
    Point origin;
    RectBounds rect;
    int localY;
    int localX;
    ScrollCollectionPart activePart;
    ScrollCollectionPart hitPart;
    ScrollCollectionPart highlightPart;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);

    if (origin.y == -1000 && origin.x == -1000) {
        return;
    }

    localY = cursor.y - origin.y;
    localX = cursor.x - origin.x;

    activePart = static_cast<ScrollCollectionPart>(m_activePart);
    if (activePart == kScrollCollectionPartThumb) {
        UpdatePositionFromCursor(localY, localX);
        return;
    }

    hitPart = HitTestScrollRegion(localY, localX);
    if (hitPart == activePart) {
        UpdatePositionFromCursor(localY, localX);
    }

    highlightPart = static_cast<ScrollCollectionPart>(m_highlightPart);
    if (highlightPart != kScrollCollectionPartNone) {
        GetPartRect(highlightPart, &rect);
        InvalidateRect(&rect);
        m_highlightPart = kScrollCollectionPartNone;
    }
}

// UID:0001GX | by-memory/0x00563070-0x005631fd.ScrollCollectionPaneUpdatePositionFromCursor.md | Completion:92 | Confidence:91
void ScrollCollectionPane::UpdatePositionFromCursor(int localY, int localX)
{
    Point cursor;
    Point origin;
    RectBounds thumbRect;
    RectBounds leadingRect;
    RectBounds trailingRect;
    short oldPosition;
    short newPosition;
    int thumbStart;
    int maxThumbStart;
    int trackStart;
    int trackSpan;

    oldPosition = m_scrollPosition;
    GetPartRect(kScrollCollectionPartThumb, &thumbRect);

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y != -1000 || origin.x != -1000) {
        leadingRect = m_bounds;
        if (m_orientation != 0) {
            leadingRect.right = leadingRect.left;
        } else {
            leadingRect.bottom = leadingRect.top;
        }
    }

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y != -1000 || origin.x != -1000) {
        trailingRect = m_bounds;
        if (m_orientation != 0) {
            trailingRect.left = trailingRect.right;
        } else {
            trailingRect.top = trailingRect.bottom;
        }
    }

    if (m_orientation != 0) {
        thumbStart = localX - m_thumbDragOffset.x + 1;
        trackStart = leadingRect.right;
        if (thumbStart < trackStart) {
            thumbStart = trackStart;
        }

        maxThumbStart = trailingRect.left + thumbRect.left - thumbRect.right;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        trackSpan = trailingRect.left + thumbRect.left -
                    thumbRect.right - leadingRect.right;
        newPosition = static_cast<short>(
            (m_scrollRange * (thumbStart - leadingRect.right)) / trackSpan);
    } else {
        thumbStart = localY - m_thumbDragOffset.y + 1;
        trackStart = leadingRect.bottom;
        if (thumbStart < trackStart) {
            thumbStart = trackStart;
        }

        maxThumbStart = trailingRect.top + thumbRect.top - thumbRect.bottom;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        trackSpan = trailingRect.top + thumbRect.top -
                    thumbRect.bottom - leadingRect.bottom;
        newPosition = static_cast<short>(
            ((m_scrollRange + 1) *
             (thumbStart - leadingRect.bottom)) / trackSpan);

        if (newPosition > m_scrollRange) {
            newPosition = m_scrollRange;
        }
    }

    if (oldPosition != newPosition) {
        static_cast<CollectionPane *>(GetParentPane())
            ->OnScrollPositionChanged(m_orientation,
                                      oldPosition,
                                      newPosition);
    }
}

// UID:0001GY | by-memory/0x00563200-0x0056325c.ScrollCollectionPaneResetScrollStateRaw.md | Completion:90 | Confidence:90
void ScrollCollectionPane::ResetScrollState()
{
    RectBounds rect;

    RemovePendingTimers();

    const ScrollCollectionPart oldPart =
        static_cast<ScrollCollectionPart>(m_highlightPart);
    m_activePart = static_cast<signed char>(kScrollCollectionPartNone);

    if (oldPart != kScrollCollectionPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
        m_highlightPart =
            static_cast<signed char>(kScrollCollectionPartNone);
    }
}

// UID:0001GT | by-memory/0x00561db0-0x0056325c.ScrollCollectionPane.md | Completion:93 | Confidence:93
// Emitted code for this aggregate is covered by [UID:0000CG][ScrollCollectionPane](by-class/ScrollCollectionPane.md);
// exact by-memory children own each ScrollCollectionPane method body.

// UID:0001VZ | by-type\by-struct\ScrollCollectionPaneLayout.md | Completion:92 | Confidence:93 | Empty Emitter Marker
