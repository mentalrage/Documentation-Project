// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KB
// Source by-file doc: by-file/InventoryScrollPane.md
// UID:0000CK | by-class/ScrollInventoryPane.md | Completion:90 | Confidence:93
#include "InventoryScrollPane.h"

#include "NewInventoryPane.h"
#include "../core/Event.h"
#include "../core/ScrollBar.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"
#include "../../render/Surface.h"

// UID:00051C | by-memory/0x00563260-0x00563301.ScrollInventoryPaneConstructor.md | Completion:93 | Confidence:95
ScrollInventoryPane::ScrollInventoryPane(unsigned char orientation)
    : Pane(1),
      m_scrollSkinIndex(0),
      m_scrollStyle(1),
      m_thumbDragActive(false),
      m_orientation(orientation),
      m_scrollPosition(0),
      m_scrollRange(0),
      m_scrollEnabled(true),
      m_highlightPart(kScrollInventoryPartNone),
      m_activePart(kScrollInventoryPartNone)
{
    InitPointPair(&m_thumbDragOffset, 0, 0);
}

// UID:00051D | by-memory/0x00563310-0x00563337.ScrollInventoryPaneSetSkinIndexRaw.md | Completion:89 | Confidence:91
void ScrollInventoryPane::SetSkinIndex(unsigned short skinIndex)
{
    if (m_scrollSkinIndex != skinIndex) {
        m_scrollSkinIndex = skinIndex;
        InvalidateRect(&m_visibleBounds);
    }
}

// UID:00051E | by-memory/0x00563340-0x00563364.ScrollInventoryPaneSetScrollStyleRaw.md | Completion:89 | Confidence:91
void ScrollInventoryPane::SetScrollStyle(unsigned char scrollStyle)
{
    if (m_scrollStyle != scrollStyle) {
        m_scrollStyle = scrollStyle;
        InvalidateRect(&m_visibleBounds);
    }
}

// UID:00051F | by-memory/0x00563370-0x005633cb.ScrollInventoryPaneSetMaxRange.md | Completion:93 | Confidence:95
void ScrollInventoryPane::SetMaxRange(short maxRange)
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

// UID:00051G | by-memory/0x005633d0-0x005633f7.ScrollInventoryPaneSetScrollPosition.md | Completion:93 | Confidence:95
void ScrollInventoryPane::SetScrollPosition(short position)
{
    if (m_scrollPosition == position) {
        return;
    }

    m_scrollPosition = position;
    InvalidateRect(&m_visibleBounds);
}

// UID:00051I | by-memory/0x00563400-0x0056341a.ScrollInventoryPaneEnable.md | Completion:90 | Confidence:92
void ScrollInventoryPane::Enable()
{
    if (!m_scrollEnabled) {
        m_scrollEnabled = true;
        InvalidateRect(&m_visibleBounds);
    }
}

// UID:00051J | by-memory/0x00563420-0x0056343a.ScrollInventoryPaneDisableRaw.md | Completion:89 | Confidence:91
void ScrollInventoryPane::Disable()
{
    if (m_scrollEnabled) {
        m_scrollEnabled = false;
        InvalidateRect(&m_visibleBounds);
    }
}

// UID:00051K | by-memory/0x00563440-0x0056345a.ScrollInventoryPaneCanScrollRaw.md | Completion:92 | Confidence:94
bool ScrollInventoryPane::CanScroll() const
{
    return m_scrollEnabled && m_scrollRange > 0;
}

// UID:00051L | by-memory/0x00563460-0x00563641.ScrollInventoryPaneHandlePointerOrMouseEvent.md | Completion:90 | Confidence:92
bool ScrollInventoryPane::HandlePointerOrMouseEvent(Event *event)
{
    bool handled = false;
    RectBounds partRect;
    const int mouseY = event->m_payload.m_pointer.m_y;
    const int mouseX = event->m_payload.m_pointer.m_x;

    switch (event->m_type) {
    case kEventCursorMove:
        if (m_activePart != kScrollInventoryPartNone) {
            InvalidateRect(&m_visibleBounds);
            handled = true;
        }
        break;

    case kEventLeftButtonDown:
        if (!PointInRect(mouseY, mouseX, &m_visibleBounds) || !CanScroll()) {
            return false;
        }

        if (m_activePart == kScrollInventoryPartNone) {
            const ScrollInventoryPart part =
                HitTestScrollRegion(mouseY, mouseX);
            if (part != kScrollInventoryPartNone) {
                CaptureMouse();
                BeginPartInteraction(part, mouseY, mouseX);
                InvalidateRect(&m_visibleBounds);
            }
        }

        m_thumbDragActive = true;
        handled = true;
        break;

    case kEventLeftButtonUp:
        if (m_activePart != kScrollInventoryPartNone) {
            ReleaseMouseCapture();
            RemovePendingTimers();

            const ScrollInventoryPart oldPart =
                static_cast<ScrollInventoryPart>(m_highlightPart);
            m_activePart = kScrollInventoryPartNone;
            if (oldPart != kScrollInventoryPartNone) {
                GetPartRect(oldPart, &partRect);
                InvalidateRect(&partRect);
                m_highlightPart = kScrollInventoryPartNone;
            }
            handled = true;
        }

        m_thumbDragActive = false;
        InvalidateRect(&m_visibleBounds);
        break;

    default:
        break;
    }

    return handled;
}

// UID:00051M | by-memory/0x00563650-0x00563655.ScrollInventoryPaneHandleKeyOrTextEvent.md | Completion:93 | Confidence:95
bool ScrollInventoryPane::HandleKeyOrTextEvent(Event *)
{
    return false;
}

// UID:00051N | by-memory/0x00563660-0x00563693.ScrollInventoryPaneOnTimer.md | Completion:93 | Confidence:95
bool ScrollInventoryPane::OnTimer(int timerId, int, int)
{
    if (timerId == 0 &&
        m_activePart != kScrollInventoryPartNone) {
        UpdateDragScroll();
        ScheduleTimer(0, 30, 0, 0);
    }
    return true;
}

// UID:00051O | by-memory/0x005636a0-0x00563d80.ScrollInventoryPaneOnPaint.md | Completion:90 | Confidence:92
void ScrollInventoryPane::OnPaint()
{
    EPFTileContext tile;
    RectBounds clipRect;
    RectBounds partRect;
    RectBounds drawRect;
    RectBounds stripRect;

    GetClipRect(&clipRect);
    if (!CanScroll()) {
        return;
    }

    const bool horizontal = (m_orientation != 0);
    for (int pass = 0; pass < 2; ++pass) {
        const ScrollInventoryPart part = pass == 0
            ? kScrollInventoryPartPageBeforeThumb
            : kScrollInventoryPartPageAfterThumb;
        GetPartRect(part, &partRect);
        if (!IntersectRects(&drawRect, &partRect, &clipRect)) {
            continue;
        }

        SetDrawColor(0);
        g_pfnFillRect(this, &drawRect);
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
                RenderTileFrame(&tile, &tile.bounds, &stripRect,
                                1, L"SLIDEBG.PAL", 0);
                OffsetRect(&stripRect, 1, 0);
            }
        } else {
            stripRect.bottom = stripRect.top + 1;
            while (stripRect.top < drawRect.bottom) {
                RenderTileFrame(&tile, &tile.bounds, &stripRect,
                                1, L"SLIDEBG.PAL", 0);
                OffsetRect(&stripRect, 0, 1);
            }
        }

        g_pEPFLib->LookupLayoutEntry(
            L"SLIDEBG.EPF", capFrame, &tile);
        RenderTileFrame(&tile, &tile.bounds, &drawRect,
                        1, L"SLIDEBG.PAL", 0);
    }

    GetPartRect(kScrollInventoryPartThumb, &partRect);
    if (IntersectRects(&drawRect, &partRect, &clipRect)) {
        SetDrawColor(0);
        g_pfnFillRect(this, &drawRect);
        SetDrawColor(128);
        g_pEPFLib->LookupLayoutEntry(
            L"SCRBUTT.EPF",
            m_highlightPart == kScrollInventoryPartThumb ? 1 : 0,
            &tile);
        RenderTileFrame(&tile, &tile.bounds, &drawRect,
                        1, L"BUTTON.PAL", 0);
    }
}

// UID:00051P | by-memory/0x00563d80-0x0056409d.ScrollInventoryPaneHitTestScrollRegion.md | Completion:90 | Confidence:92
ScrollInventoryPart ScrollInventoryPane::HitTestScrollRegion(int localY,
                                                               int localX)
{
    for (int partValue = kScrollInventoryPartLeading;
         partValue <= kScrollInventoryPartTrailing;
         ++partValue) {
        const ScrollInventoryPart part =
            static_cast<ScrollInventoryPart>(partValue);
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
            rect = m_visibleBounds;

            if (m_orientation == 0) {
                const int thumbSpan =
                    kScrollPanePartExtentBySkin[m_scrollSkinIndex];

                if (part == kScrollInventoryPartLeading) {
                    rect.bottom = rect.top;
                } else if (part == kScrollInventoryPartTrailing) {
                    rect.top = rect.bottom;
                } else if (m_scrollEnabled && m_scrollRange > 0) {
                    const int trackTop = m_visibleBounds.top;
                    const int thumbLimit = m_visibleBounds.bottom - thumbSpan;
                    int thumbTop;

                    if (m_thumbDragActive) {
                        thumbTop = m_visibleBounds.top + cursor.y -
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

                    if (part == kScrollInventoryPartThumb) {
                        rect.top = thumbTop;
                        rect.bottom = thumbBottom;
                    } else if (part == kScrollInventoryPartPageBeforeThumb) {
                        rect.bottom = thumbTop;
                    } else if (part == kScrollInventoryPartPageAfterThumb) {
                        rect.top = thumbBottom;
                    }
                } else if (part == kScrollInventoryPartThumb) {
                    rect.top += thumbSpan;
                    rect.bottom -= thumbSpan;
                } else {
                    InitRectBounds(&rect, 0, 0, 0, 0);
                }
            } else {
                const int thumbSpan = m_visibleBounds.bottom - m_visibleBounds.top;

                if (part == kScrollInventoryPartLeading) {
                    rect.right = rect.left;
                } else if (part == kScrollInventoryPartTrailing) {
                    rect.left = rect.right;
                } else if (m_scrollEnabled && m_scrollRange > 0) {
                    const int trackLeft = m_visibleBounds.left;
                    const int thumbLimit = m_visibleBounds.right - thumbSpan;
                    const int thumbLeft = trackLeft +
                        ((thumbLimit - trackLeft) * m_scrollPosition) /
                            m_scrollRange;
                    const int thumbRight = thumbLeft + thumbSpan;

                    if (part == kScrollInventoryPartThumb) {
                        rect.left = thumbLeft;
                        rect.right = thumbRight;
                    } else if (part == kScrollInventoryPartPageBeforeThumb) {
                        rect.right = thumbLeft;
                    } else if (part == kScrollInventoryPartPageAfterThumb) {
                        rect.left = thumbRight;
                    }
                } else if (part == kScrollInventoryPartThumb) {
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

    return kScrollInventoryPartNone;
}

// UID:00051Q | by-memory/0x005640a0-0x00564327.ScrollInventoryPaneGetPartRect.md | Completion:90 | Confidence:92
void ScrollInventoryPane::GetPartRect(ScrollInventoryPart part,
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

    *bounds = m_visibleBounds;
    const bool horizontal = (m_orientation != 0);
    const int thumbSpan = horizontal
        ? m_visibleBounds.bottom - m_visibleBounds.top
        : kScrollPanePartExtentBySkin[m_scrollSkinIndex];

    if (part == kScrollInventoryPartLeading) {
        if (horizontal) {
            bounds->right = bounds->left;
        } else {
            bounds->bottom = bounds->top;
        }
        return;
    }
    if (part == kScrollInventoryPartTrailing) {
        if (horizontal) {
            bounds->left = bounds->right;
        } else {
            bounds->top = bounds->bottom;
        }
        return;
    }

    if (!CanScroll()) {
        if (part == kScrollInventoryPartThumb) {
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
        const int trackStart = m_visibleBounds.left;
        const int thumbLimit = m_visibleBounds.right - thumbSpan;
        const int thumbStart = trackStart +
            (m_scrollPosition * (thumbLimit - trackStart)) /
                m_scrollRange;
        const int thumbEnd = thumbStart + thumbSpan;
        if (part == kScrollInventoryPartThumb) {
            bounds->left = thumbStart;
            bounds->right = thumbEnd;
        } else if (part == kScrollInventoryPartPageBeforeThumb) {
            bounds->right = thumbStart;
        } else if (part == kScrollInventoryPartPageAfterThumb) {
            bounds->left = thumbEnd;
        }
    } else {
        const int trackStart = m_visibleBounds.top;
        const int thumbLimit = m_visibleBounds.bottom - thumbSpan;
        int thumbStart;
        if (m_thumbDragActive) {
            thumbStart = m_visibleBounds.top + cursor.y - m_thumbDragOffset.y;
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
        if (part == kScrollInventoryPartThumb) {
            bounds->top = thumbStart;
            bounds->bottom = thumbEnd;
        } else if (part == kScrollInventoryPartPageBeforeThumb) {
            bounds->bottom = thumbStart;
        } else if (part == kScrollInventoryPartPageAfterThumb) {
            bounds->top = thumbEnd;
        }
    }
}

// UID:00051R | by-memory/0x00564330-0x005643a0.ScrollInventoryPaneSetHighlightedPartRaw.md | Completion:91 | Confidence:93
void ScrollInventoryPane::SetHighlightedPart(ScrollInventoryPart part)
{
    RectBounds rect;
    ScrollInventoryPart oldPart;

    oldPart = static_cast<ScrollInventoryPart>(m_highlightPart);
    if (oldPart == part) {
        return;
    }

    if (oldPart != kScrollInventoryPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
    }

    if (part != kScrollInventoryPartNone) {
        GetPartRect(part, &rect);
        InvalidateRect(&rect);
    }

    m_highlightPart = static_cast<signed char>(part);
}

// UID:00051S | by-memory/0x005643a0-0x0056445f.ScrollInventoryPaneBeginPartInteractionRaw.md | Completion:91 | Confidence:93
void ScrollInventoryPane::BeginPartInteraction(ScrollInventoryPart part, int mouseY, int mouseX)
{
    RectBounds rect;

    if (part == kScrollInventoryPartThumb) {
        if (m_highlightPart != kScrollInventoryPartThumb) {
            if (m_highlightPart != kScrollInventoryPartNone) {
                GetPartRect(static_cast<ScrollInventoryPart>(m_highlightPart), &rect);
                InvalidateRect(&rect);
            }

            GetPartRect(kScrollInventoryPartThumb, &rect);
            InvalidateRect(&rect);
            m_highlightPart = static_cast<signed char>(kScrollInventoryPartThumb);
        }

        GetPartRect(kScrollInventoryPartThumb, &rect);
        InitPointPair(&m_thumbDragOffset, mouseY - rect.top, mouseX - rect.left);
    }

    m_activePart = static_cast<signed char>(part);
    UpdateDragScroll();
    ScheduleTimer(0, 200, 0, 0);
}

// UID:00051T | by-memory/0x00564460-0x00564520.ScrollInventoryPaneUpdateDragScroll.md | Completion:90 | Confidence:92
void ScrollInventoryPane::UpdateDragScroll()
{
    Point cursor;
    Point origin;
    RectBounds rect;
    int localY;
    int localX;
    ScrollInventoryPart activePart;
    ScrollInventoryPart hitPart;
    ScrollInventoryPart highlightPart;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);

    if (origin.y == -1000 && origin.x == -1000) {
        return;
    }

    localY = cursor.y - origin.y;
    localX = cursor.x - origin.x;

    activePart = static_cast<ScrollInventoryPart>(m_activePart);
    if (activePart == kScrollInventoryPartThumb) {
        UpdatePositionFromCursor(localY, localX);
        return;
    }

    hitPart = HitTestScrollRegion(localY, localX);
    if (hitPart == activePart) {
        UpdatePositionFromCursor(localY, localX);
    }

    highlightPart = static_cast<ScrollInventoryPart>(m_highlightPart);
    if (highlightPart != kScrollInventoryPartNone) {
        GetPartRect(highlightPart, &rect);
        InvalidateRect(&rect);
        m_highlightPart = kScrollInventoryPartNone;
    }
}

// UID:0001H0 | by-memory/0x00564520-0x005646ad.ScrollInventoryPaneUpdateFromDrag.md | Completion:91 | Confidence:93
void ScrollInventoryPane::UpdatePositionFromCursor(int localY, int localX)
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
    GetPartRect(kScrollInventoryPartThumb, &thumbRect);

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y != -1000 || origin.x != -1000) {
        leadingRect = m_visibleBounds;
        if (m_orientation != 0) {
            leadingRect.right = leadingRect.left;
        } else {
            leadingRect.bottom = leadingRect.top;
        }
    }

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y != -1000 || origin.x != -1000) {
        trailingRect = m_visibleBounds;
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
        static_cast<NewInventoryPane *>(GetParentPane())
            ->OnScrollPositionChanged(m_orientation,
                                      oldPosition,
                                      newPosition);
    }
}

// UID:0001H1 | by-memory/0x005646b0-0x0056470c.ScrollInventoryPaneResetScrollStateRaw.md | Completion:93 | Confidence:94
void ScrollInventoryPane::ResetScrollState()
{
    RectBounds rect;

    RemovePendingTimers();

    const ScrollInventoryPart oldPart =
        static_cast<ScrollInventoryPart>(m_highlightPart);
    m_activePart = static_cast<signed char>(kScrollInventoryPartNone);

    if (oldPart != kScrollInventoryPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
        m_highlightPart =
            static_cast<signed char>(kScrollInventoryPartNone);
    }
}

// UID:0001GZ | by-memory/0x00563260-0x0056470c.ScrollInventoryPane.md | Completion:91 | Confidence:93
// This aggregate has no standalone source body; exact ScrollInventoryPane method bodies are emitted by exact child pages routed through [UID:0000CK][ScrollInventoryPane](by-class/ScrollInventoryPane.md).

// UID:0003CO | by-memory\0x00624028-0x006240b0.ScrollInventoryPaneVtableData.md | Completion:86 | Confidence:90 | Empty Emitter Marker
