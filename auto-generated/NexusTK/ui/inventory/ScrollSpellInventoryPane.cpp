// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NJ
// Source by-file doc: by-file/ScrollSpellInventoryPane.md
// UID:0000CN | by-class/ScrollSpellInventoryPane.md | Completion:89 | Confidence:91
#include "ScrollSpellInventoryPane.h"

#include "NewSpellInventoryPane.h"
#include "../core/Event.h"
#include "../core/ScrollBar.h"
#include "../../render/EPFTileContext.h"
#include "../../render/ImageLib.h"
#include "../../render/Surface.h"

// UID:000538 | by-memory/0x0055f450-0x0055f4f1.ScrollSpellInventoryPaneConstructor.md | Completion:93 | Confidence:95
ScrollSpellInventoryPane::ScrollSpellInventoryPane(unsigned char orientation)
    : Pane(1),
      m_sizeIndex(0),
      m_scrollStyle(1),
      m_thumbDragActive(false),
      m_orientation(orientation),
      m_scrollPosition(0),
      m_scrollRange(0),
      m_enabled(true),
      m_hoverPart(kScrollSpellInventoryPartNone),
      m_activePart(kScrollSpellInventoryPartNone)
{
    InitPointPair(&m_thumbDragOffset, 0, 0);
}

// UID:000539 | by-memory/0x0055f500-0x0055f527.ScrollSpellInventoryPaneSetSizeIndexRaw.md | Completion:89 | Confidence:91
void ScrollSpellInventoryPane::SetSizeIndex(unsigned short sizeIndex)
{
    if (m_sizeIndex != sizeIndex) {
        m_sizeIndex = sizeIndex;
        InvalidateRect(&m_visibleBounds);
    }
}

// UID:00053A | by-memory/0x0055f530-0x0055f554.ScrollSpellInventoryPaneSetScrollStyleRaw.md | Completion:89 | Confidence:91
void ScrollSpellInventoryPane::SetScrollStyle(unsigned char scrollStyle)
{
    if (m_scrollStyle != scrollStyle) {
        m_scrollStyle = scrollStyle;
        InvalidateRect(&m_visibleBounds);
    }
}

// UID:00053B | by-memory/0x0055f560-0x0055f5bb.ScrollSpellInventoryPaneSetMaxRange.md | Completion:93 | Confidence:95
void ScrollSpellInventoryPane::SetMaxRange(short maxRange)
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

// UID:00053C | by-memory/0x0055f5c0-0x0055f5e7.ScrollSpellInventoryPaneSetScrollPosition.md | Completion:93 | Confidence:95
void ScrollSpellInventoryPane::SetScrollPosition(short position)
{
    if (m_scrollPosition == position) {
        return;
    }
    m_scrollPosition = position;
    InvalidateRect(&m_visibleBounds);
}

// UID:00053D | by-memory/0x0055f5f0-0x0055f60a.ScrollSpellInventoryPaneActivate.md | Completion:90 | Confidence:92
void ScrollSpellInventoryPane::Activate()
{
    if (!m_enabled) {
        m_enabled = true;
        InvalidateRect(&m_visibleBounds);
    }
}

// UID:00053E | by-memory/0x0055f610-0x0055f62a.ScrollSpellInventoryPaneDeactivateRaw.md | Completion:89 | Confidence:91
void ScrollSpellInventoryPane::Deactivate()
{
    if (m_enabled) {
        m_enabled = false;
        InvalidateRect(&m_visibleBounds);
    }
}

// UID:00053F | by-memory/0x0055f630-0x0055f64a.ScrollSpellInventoryPaneCanScrollRaw.md | Completion:92 | Confidence:94
bool ScrollSpellInventoryPane::CanScroll() const
{
    return m_enabled && m_scrollRange > 0;
}

// UID:00053G | by-memory/0x0055f650-0x0055f831.ScrollSpellInventoryPaneHandlePointerOrMouseEvent.md | Completion:90 | Confidence:92
bool ScrollSpellInventoryPane::HandlePointerOrMouseEvent(Event *event)
{
    bool handled = false;
    RectBounds partRect;
    const int mouseY = event->m_payload.m_pointer.m_y;
    const int mouseX = event->m_payload.m_pointer.m_x;

    switch (event->m_type) {
    case kEventCursorMove:
        if (m_activePart != kScrollSpellInventoryPartNone) {
            InvalidateRect(&m_visibleBounds);
            handled = true;
        }
        break;

    case kEventLeftButtonDown:
        if (!PointInRect(mouseY, mouseX, &m_visibleBounds) || !CanScroll()) {
            return false;
        }
        if (m_activePart == kScrollSpellInventoryPartNone) {
            const ScrollSpellInventoryPart part = HitTestPart(mouseY, mouseX);
            if (part != kScrollSpellInventoryPartNone) {
                CaptureMouse();
                BeginInteraction(part, mouseY, mouseX);
                InvalidateRect(&m_visibleBounds);
            }
        }
        m_thumbDragActive = true;
        handled = true;
        break;

    case kEventLeftButtonUp:
        if (m_activePart != kScrollSpellInventoryPartNone) {
            ReleaseMouseCapture();
            RemovePendingTimers();
            const ScrollSpellInventoryPart oldPart =
                static_cast<ScrollSpellInventoryPart>(m_hoverPart);
            m_activePart = kScrollSpellInventoryPartNone;
            if (oldPart != kScrollSpellInventoryPartNone) {
                GetPartRect(oldPart, &partRect);
                InvalidateRect(&partRect);
                m_hoverPart = kScrollSpellInventoryPartNone;
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

// UID:00053H | by-memory/0x0055f840-0x0055f845.ScrollSpellInventoryPaneHandleKeyOrTextEvent.md | Completion:93 | Confidence:95
bool ScrollSpellInventoryPane::HandleKeyOrTextEvent(Event *)
{
    return false;
}

// UID:00053I | by-memory/0x0055f850-0x0055f883.ScrollSpellInventoryPaneOnTimer.md | Completion:93 | Confidence:95
bool ScrollSpellInventoryPane::OnTimer(int timerId, int, int)
{
    if (timerId == 0 && m_activePart != kScrollSpellInventoryPartNone) {
        UpdateDragScroll();
        ScheduleTimer(0, 30, 0, 0);
    }
    return true;
}

// UID:00053J | by-memory/0x0055f890-0x0055ff70.ScrollSpellInventoryPaneOnPaint.md | Completion:90 | Confidence:92
void ScrollSpellInventoryPane::OnPaint()
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
        const ScrollSpellInventoryPart part = pass == 0
            ? kScrollSpellInventoryPartPageBeforeThumb
            : kScrollSpellInventoryPartPageAfterThumb;
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
        g_pEPFLib->LookupLayoutEntry(L"SLIDEBG.EPF", fillFrame, &tile);

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

        g_pEPFLib->LookupLayoutEntry(L"SLIDEBG.EPF", capFrame, &tile);
        RenderTileFrame(&tile, &tile.bounds, &drawRect,
                        1, L"SLIDEBG.PAL", 0);
    }

    GetPartRect(kScrollSpellInventoryPartThumb, &partRect);
    if (IntersectRects(&drawRect, &partRect, &clipRect)) {
        SetDrawColor(0);
        g_pfnFillRect(this, &drawRect);
        SetDrawColor(128);
        g_pEPFLib->LookupLayoutEntry(
            L"SCRBUTT.EPF",
            m_hoverPart == kScrollSpellInventoryPartThumb ? 1 : 0,
            &tile);
        RenderTileFrame(&tile, &tile.bounds, &drawRect,
                        1, L"BUTTON.PAL", 0);
    }
}

// UID:00053K | by-memory/0x0055ff70-0x0056028d.ScrollSpellInventoryPaneHitTestPart.md | Completion:90 | Confidence:92
ScrollSpellInventoryPart ScrollSpellInventoryPane::HitTestPart(int localY,
                                                               int localX)
{
    for (int value = kScrollSpellInventoryPartLeading;
         value <= kScrollSpellInventoryPartTrailing;
         ++value) {
        const ScrollSpellInventoryPart part =
            static_cast<ScrollSpellInventoryPart>(value);
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
                const int thumbSpan = kScrollPanePartExtentBySkin[m_sizeIndex];
                if (part == kScrollSpellInventoryPartLeading) {
                    rect.bottom = rect.top;
                } else if (part == kScrollSpellInventoryPartTrailing) {
                    rect.top = rect.bottom;
                } else if (m_enabled && m_scrollRange > 0) {
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
                    if (part == kScrollSpellInventoryPartThumb) {
                        rect.top = thumbTop;
                        rect.bottom = thumbBottom;
                    } else if (part == kScrollSpellInventoryPartPageBeforeThumb) {
                        rect.bottom = thumbTop;
                    } else if (part == kScrollSpellInventoryPartPageAfterThumb) {
                        rect.top = thumbBottom;
                    }
                } else if (part == kScrollSpellInventoryPartThumb) {
                    rect.top += thumbSpan;
                    rect.bottom -= thumbSpan;
                } else {
                    InitRectBounds(&rect, 0, 0, 0, 0);
                }
            } else {
                const int thumbSpan =
                    m_visibleBounds.bottom - m_visibleBounds.top;
                if (part == kScrollSpellInventoryPartLeading) {
                    rect.right = rect.left;
                } else if (part == kScrollSpellInventoryPartTrailing) {
                    rect.left = rect.right;
                } else if (m_enabled && m_scrollRange > 0) {
                    const int trackLeft = m_visibleBounds.left;
                    const int thumbLimit = m_visibleBounds.right - thumbSpan;
                    const int thumbLeft = trackLeft +
                        ((thumbLimit - trackLeft) * m_scrollPosition) /
                            m_scrollRange;
                    const int thumbRight = thumbLeft + thumbSpan;
                    if (part == kScrollSpellInventoryPartThumb) {
                        rect.left = thumbLeft;
                        rect.right = thumbRight;
                    } else if (part == kScrollSpellInventoryPartPageBeforeThumb) {
                        rect.right = thumbLeft;
                    } else if (part == kScrollSpellInventoryPartPageAfterThumb) {
                        rect.left = thumbRight;
                    }
                } else if (part == kScrollSpellInventoryPartThumb) {
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
    return kScrollSpellInventoryPartNone;
}

// UID:00053L | by-memory/0x00560290-0x00560517.ScrollSpellInventoryPaneGetPartRect.md | Completion:90 | Confidence:92
void ScrollSpellInventoryPane::GetPartRect(ScrollSpellInventoryPart part,
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
        : kScrollPanePartExtentBySkin[m_sizeIndex];

    if (part == kScrollSpellInventoryPartLeading) {
        if (horizontal) {
            bounds->right = bounds->left;
        } else {
            bounds->bottom = bounds->top;
        }
        return;
    }
    if (part == kScrollSpellInventoryPartTrailing) {
        if (horizontal) {
            bounds->left = bounds->right;
        } else {
            bounds->top = bounds->bottom;
        }
        return;
    }

    if (!CanScroll()) {
        if (part == kScrollSpellInventoryPartThumb) {
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
            (m_scrollPosition * (thumbLimit - trackStart)) / m_scrollRange;
        const int thumbEnd = thumbStart + thumbSpan;
        if (part == kScrollSpellInventoryPartThumb) {
            bounds->left = thumbStart;
            bounds->right = thumbEnd;
        } else if (part == kScrollSpellInventoryPartPageBeforeThumb) {
            bounds->right = thumbStart;
        } else if (part == kScrollSpellInventoryPartPageAfterThumb) {
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
                (m_scrollPosition * (thumbLimit - trackStart)) / m_scrollRange;
        }
        const int thumbEnd = thumbStart + thumbSpan;
        if (part == kScrollSpellInventoryPartThumb) {
            bounds->top = thumbStart;
            bounds->bottom = thumbEnd;
        } else if (part == kScrollSpellInventoryPartPageBeforeThumb) {
            bounds->bottom = thumbStart;
        } else if (part == kScrollSpellInventoryPartPageAfterThumb) {
            bounds->top = thumbEnd;
        }
    }
}

// UID:00053M | by-memory/0x00560520-0x00560590.ScrollSpellInventoryPaneSetHoverPartRaw.md | Completion:91 | Confidence:93
void ScrollSpellInventoryPane::SetHoverPart(ScrollSpellInventoryPart part)
{
    RectBounds rect;
    const ScrollSpellInventoryPart oldPart =
        static_cast<ScrollSpellInventoryPart>(m_hoverPart);
    if (oldPart == part) {
        return;
    }
    if (oldPart != kScrollSpellInventoryPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
    }
    if (part != kScrollSpellInventoryPartNone) {
        GetPartRect(part, &rect);
        InvalidateRect(&rect);
    }
    m_hoverPart = static_cast<signed char>(part);
}

// UID:00053N | by-memory/0x00560590-0x0056064f.ScrollSpellInventoryPaneBeginInteractionRaw.md | Completion:91 | Confidence:93
void ScrollSpellInventoryPane::BeginInteraction(ScrollSpellInventoryPart part,
                                                int mouseY,
                                                int mouseX)
{
    RectBounds rect;
    if (part == kScrollSpellInventoryPartThumb) {
        if (m_hoverPart != kScrollSpellInventoryPartThumb) {
            if (m_hoverPart != kScrollSpellInventoryPartNone) {
                GetPartRect(
                    static_cast<ScrollSpellInventoryPart>(m_hoverPart),
                    &rect);
                InvalidateRect(&rect);
            }
            GetPartRect(kScrollSpellInventoryPartThumb, &rect);
            InvalidateRect(&rect);
            m_hoverPart = kScrollSpellInventoryPartThumb;
        }
        GetPartRect(kScrollSpellInventoryPartThumb, &rect);
        InitPointPair(&m_thumbDragOffset,
                      mouseY - rect.top,
                      mouseX - rect.left);
    }
    m_activePart = static_cast<signed char>(part);
    UpdateDragScroll();
    ScheduleTimer(0, 200, 0, 0);
}

// UID:00053O | by-memory/0x00560650-0x00560710.ScrollSpellInventoryPaneUpdateDragScroll.md | Completion:90 | Confidence:92
void ScrollSpellInventoryPane::UpdateDragScroll()
{
    Point cursor;
    Point origin;
    RectBounds rect;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y == -1000 && origin.x == -1000) {
        return;
    }

    const int localY = cursor.y - origin.y;
    const int localX = cursor.x - origin.x;
    const ScrollSpellInventoryPart activePart =
        static_cast<ScrollSpellInventoryPart>(m_activePart);
    if (activePart == kScrollSpellInventoryPartThumb) {
        UpdateFromDrag(localY, localX);
        return;
    }

    if (HitTestPart(localY, localX) == activePart) {
        UpdateFromDrag(localY, localX);
    }

    const ScrollSpellInventoryPart hoverPart =
        static_cast<ScrollSpellInventoryPart>(m_hoverPart);
    if (hoverPart != kScrollSpellInventoryPartNone) {
        GetPartRect(hoverPart, &rect);
        InvalidateRect(&rect);
        m_hoverPart = kScrollSpellInventoryPartNone;
    }
}

// UID:0001GN | by-memory/0x00560710-0x0056089d.ScrollSpellInventoryPaneUpdateFromDrag.md | Completion:91 | Confidence:93
void ScrollSpellInventoryPane::UpdateFromDrag(int localY, int localX)
{
    Point cursor;
    Point origin;
    RectBounds thumbRect;
    RectBounds leadingRect;
    RectBounds trailingRect;
    const short oldPosition = m_scrollPosition;
    short newPosition;
    GetPartRect(kScrollSpellInventoryPartThumb, &thumbRect);

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
        int thumbStart = localX - m_thumbDragOffset.x + 1;
        if (thumbStart < leadingRect.right) {
            thumbStart = leadingRect.right;
        }
        const int maxThumbStart =
            trailingRect.left + thumbRect.left - thumbRect.right;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        const int trackSpan =
            trailingRect.left + thumbRect.left -
            thumbRect.right - leadingRect.right;
        newPosition = static_cast<short>(
            (m_scrollRange * (thumbStart - leadingRect.right)) / trackSpan);
    } else {
        int thumbStart = localY - m_thumbDragOffset.y + 1;
        if (thumbStart < leadingRect.bottom) {
            thumbStart = leadingRect.bottom;
        }
        const int maxThumbStart =
            trailingRect.top + thumbRect.top - thumbRect.bottom;
        if (thumbStart > maxThumbStart) {
            thumbStart = maxThumbStart;
        }

        const int trackSpan =
            trailingRect.top + thumbRect.top -
            thumbRect.bottom - leadingRect.bottom;
        newPosition = static_cast<short>(
            ((m_scrollRange + 1) *
             (thumbStart - leadingRect.bottom)) / trackSpan);

        if (newPosition > m_scrollRange) {
            newPosition = m_scrollRange;
        }
    }

    if (oldPosition != newPosition) {
        static_cast<NewSpellInventoryPane *>(GetParentPane())
            ->OnScrollPositionChanged(m_orientation,
                                      oldPosition,
                                      newPosition);
    }
}

// UID:0001GO | by-memory/0x005608a0-0x005608fc.ScrollSpellInventoryPaneResetScrollStateRaw.md | Completion:93 | Confidence:94
void ScrollSpellInventoryPane::ResetScrollState()
{
    RectBounds rect;
    RemovePendingTimers();
    const ScrollSpellInventoryPart oldPart =
        static_cast<ScrollSpellInventoryPart>(m_hoverPart);
    m_activePart = kScrollSpellInventoryPartNone;
    if (oldPart != kScrollSpellInventoryPartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
        m_hoverPart = kScrollSpellInventoryPartNone;
    }
}
