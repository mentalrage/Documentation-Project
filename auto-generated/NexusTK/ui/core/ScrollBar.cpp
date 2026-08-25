// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NF
// Source by-file doc: by-file/ScrollBar.md
// UID:0000CM | by-class/ScrollPane.md | Completion:87 | Confidence:88
#include "ScrollBar.h"

// ScrollPane class routing is documented here; exact constructor, draw, geometry, input, timer, and raw-state source emits through child pages.
// UID:00042V | by-memory/0x0055c200-0x0055c2a1.ScrollPaneConstructor.md | Completion:88 | Confidence:90
ScrollPane::ScrollPane(bool horizontal)
    : Pane(true)
{
    m_scrollSkinIndex = 0;
    m_scrollStyle = 1;
    m_thumbDragActive = false;
    m_orientation = horizontal ? 1 : 0;
    m_scrollPosition = 0;
    m_scrollRange = 0;
    m_enabled = true;
    m_highlightPart = kScrollPanePartNone;
    m_activePart = kScrollPanePartNone;
    InitPointPair(&m_thumbDragOffset, 0, 0);
}

// UID:00042W | by-memory/0x0055c2b0-0x0055c2d7.ScrollPaneRangeSetterRaw.md | Completion:88 | Confidence:90
void ScrollPane::SetSkinIndex(unsigned short skinIndex)
{
    if (m_scrollSkinIndex == skinIndex) {
        return;
    }

    m_scrollSkinIndex = skinIndex;
    InvalidateRect(&m_bounds);
}

// UID:00042X | by-memory/0x0055c2e0-0x0055c304.ScrollPaneByteStateSetterRaw.md | Completion:86 | Confidence:88
// [UID:00042X] retained out-of-line compiler copy of inline ScrollPane::SetScrollStyle.
// The single authored definition is in ScrollPane's formal H; do not emit a second CPP body.

// UID:000432 | by-memory/0x0055c3e0-0x0055c3fa.ScrollPaneIsScrollThumbVisible.md | Completion:89 | Confidence:91
bool ScrollPane::IsScrollThumbVisible()
{
    return m_enabled && m_scrollRange > 0;
}

// UID:000433 | by-memory/0x0055c400-0x0055c5ff.ScrollPaneHandleMouseEvent.md | Completion:91 | Confidence:93
bool ScrollPane::OnMouseEvent(const PaneMouseEvent& event)
{
    bool handled = false;

    if (g_useEpfAssets) {
        switch (event.type) {
        case kPaneMouseMove:
            if (m_activePart != kScrollPanePartNone) {
                InvalidateRect(&m_bounds);
                return true;
            }
            return false;

        case kPaneMouseDown:
            if (!PointInRect(event.y, event.x, &m_bounds)) {
                return false;
            }
            if (!m_enabled || m_scrollRange <= 0) {
                return false;
            }
            if (m_activePart == kScrollPanePartNone) {
                const ScrollPanePart part = HitTestPart(event.y, event.x);
                if (part != kScrollPanePartNone) {
                    CaptureMouse();
                    BeginPartPress(part, event.y, event.x);
                    InvalidateRect(&m_bounds);
                }
            }
            m_thumbDragActive = true;
            return true;

        case kPaneMouseUp:
            if (m_activePart != kScrollPanePartNone) {
                ReleaseMouseCapture();
                ResetScrollState();
                handled = true;
            }
            m_thumbDragActive = false;
            InvalidateRect(&m_bounds);
            return handled;

        default:
            return false;
        }
    }

    switch (event.type) {
    case kPaneMouseMove:
        return m_activePart != kScrollPanePartNone;

    case kPaneMouseDown:
        if (!PointInRect(event.y, event.x, &m_bounds)) {
            return false;
        }
        if (!m_enabled || m_scrollRange <= 0) {
            return false;
        }
        if (m_activePart == kScrollPanePartNone) {
            const ScrollPanePart part = HitTestPart(event.y, event.x);
            if (part != kScrollPanePartNone) {
                CaptureMouse();
                BeginPartPress(part, event.y, event.x);
            }
        }
        return true;

    case kPaneMouseUp:
        if (m_activePart != kScrollPanePartNone) {
            ReleaseMouseCapture();
            ResetScrollState();
            return true;
        }
        return false;

    default:
        return false;
    }
}

// UID:000434 | by-memory/0x0055c600-0x0055c605.ScrollPaneCanScroll.md | Completion:88 | Confidence:92
bool ScrollPane::CanScroll(int)
{
    return false;
}

// UID:000435 | by-memory/0x0055c610-0x0055c643.ScrollPaneOnScrollTimer.md | Completion:88 | Confidence:90
bool ScrollPane::OnTimer(int timerId, int, int)
{
    if (timerId == 0 && m_activePart != kScrollPanePartNone) {
        ProcessActivePart();
        ScheduleTimer(0, 30, 0, 0);
    }

    return true;
}

// UID:0001GI | by-memory/0x0055c650-0x0055d957.ScrollPaneOnDraw.md | Completion:88 | Confidence:90
void ScrollPane::OnDraw()
{
    EPFTileContext tile;
    RectBounds clipRect;
    RectBounds partRect;
    RectBounds drawRect;
    RectBounds stripRect;

    InitTileContext(&tile);
    GetClipRect(&clipRect);

    const bool horizontal = (m_orientation != 0);
    const bool hasThumb = IsScrollThumbVisible();

    if (g_useEpfAssets) {
        if (hasThumb) {
            const ScrollPanePart trackParts[2] = {
                kScrollPanePartPageBeforeThumb,
                kScrollPanePartPageAfterThumb
            };

            for (int i = 0; i < 2; ++i) {
                const ScrollPanePart part = trackParts[i];

                GetScrollPartRect(part, &partRect);
                if (!IntersectRects(&drawRect, &partRect, &clipRect)) {
                    continue;
                }

                SetDrawColor(0);
                PreparePaneRegion(&drawRect);
                SetDrawColor(0x80);

                const int fillFrame = horizontal ? 4 : 1;
                const int capFrame = horizontal
                    ? (part == kScrollPanePartPageBeforeThumb ? 3 : 5)
                    : (part == kScrollPanePartPageBeforeThumb ? 0 : 2);

                g_pEPFLib->LookupLayoutEntry(L"SLIDEBG.EPF", fillFrame, &tile);

                stripRect = drawRect;
                if (horizontal) {
                    stripRect.right = stripRect.left + 1;
                    while (stripRect.left < drawRect.right) {
                        RenderTileFrame(&tile, &tile.bounds, &stripRect, 1, L"SLIDEBG.PAL", 0);
                        OffsetRect(&stripRect, 1, 0);
                    }
                } else {
                    stripRect.bottom = stripRect.top + 1;
                    while (stripRect.top < drawRect.bottom) {
                        RenderTileFrame(&tile, &tile.bounds, &stripRect, 1, L"SLIDEBG.PAL", 0);
                        OffsetRect(&stripRect, 0, 1);
                    }
                }

                g_pEPFLib->LookupLayoutEntry(L"SLIDEBG.EPF", capFrame, &tile);
                RenderTileFrame(&tile, &tile.bounds, &drawRect, 1, L"SLIDEBG.PAL", 0);
            }

            GetScrollPartRect(kScrollPanePartThumb, &partRect);
            if (IntersectRects(&drawRect, &partRect, &clipRect)) {
                SetDrawColor(0);
                PreparePaneRegion(&drawRect);
                SetDrawColor(0x80);

                const int frame = (m_highlightPart == kScrollPanePartThumb) ? 1 : 0;
                g_pEPFLib->LookupLayoutEntry(L"SCRBUTT.EPF", frame, &tile);
                RenderTileFrame(&tile, &tile.bounds, &drawRect, 1, L"BUTTON.PAL", 0);
            }
        } else {
            SetDrawColor(0);
            PreparePaneRegion(&m_bounds);
        }

        return;
    }

    if (hasThumb) {
        const ScrollPanePart parts[5] = {
            kScrollPanePartFirstButton,
            kScrollPanePartPageBeforeThumb,
            kScrollPanePartThumb,
            kScrollPanePartPageAfterThumb,
            kScrollPanePartSecondButton
        };

        for (int i = 0; i < 5; ++i) {
            const ScrollPanePart part = parts[i];

            GetScrollPartRect(part, &partRect);
            if (!IntersectRects(&drawRect, &partRect, &clipRect)) {
                continue;
            }

            const int frame = ResolveClassicScrollFrame(part, horizontal, m_highlightPart, m_scrollStyle);
            g_pResourceLayoutTable->LookupLayoutEntry(L"SCRL001.EPD", frame, &tile);

            if (part == kScrollPanePartPageBeforeThumb ||
                part == kScrollPanePartPageAfterThumb) {
                DrawTiledBackground(&tile, &drawRect, L"SCRL001.PAD");
            } else {
                RenderTileFrame(&tile, &tile.bounds, &drawRect, 0, L"SCRL001.PAD", 0);
            }
        }

        return;
    }

    if (m_scrollStyle != 0) {
        GetScrollPartRect(kScrollPanePartFirstButton, &partRect);
        if (IntersectRects(&drawRect, &partRect, &clipRect)) {
            g_pResourceLayoutTable->LookupLayoutEntry(
                L"SCRL001.EPD",
                ResolveClassicScrollFrame(kScrollPanePartFirstButton, horizontal, m_highlightPart, m_scrollStyle),
                &tile);
            RenderTileFrame(&tile, &tile.bounds, &drawRect, 0, L"SCRL001.PAD", 0);
        }
    }

    SetDrawColor(0);
    m_drawMode = 2;
    PreparePaneRegion(&m_bounds);
}

// UID:0004YF | by-memory/0x0055d960-0x0055d9d6.ScrollPaneHitTestPart.md | Completion:92 | Confidence:94
ScrollPanePart ScrollPane::HitTestPart(int localY, int localX)
{
    for (int value = kScrollPanePartFirstButton;
         value <= kScrollPanePartSecondButton;
         ++value) {
        RectBounds bounds;
        const ScrollPanePart part = static_cast<ScrollPanePart>(value);
        GetScrollPartRect(part, &bounds);
        if (PointInRect(localY, localX, &bounds)) {
            return part;
        }
    }

    return kScrollPanePartNone;
}

// UID:0001GK | by-memory/0x0055d9e0-0x0055de99.ScrollPaneGetScrollPartRect.md | Completion:92 | Confidence:94
void ScrollPane::GetScrollPartRect(ScrollPanePart part, RectBounds *outRect)
{
    if (g_useEpfAssets) {
        Point cursor;
        Point origin;

        g_pEventMan->GetCursorPosition(&cursor);
        GetScreenOffset(&origin);
        if (origin.y == -1000 && origin.x == -1000) {
            return;
        }

        cursor.y -= origin.y;
        cursor.x -= origin.x;

        const RectBounds bounds = m_bounds;
        if (m_orientation != 0) {
            const int thumbExtent = bounds.bottom - bounds.top;

            switch (part) {
            case kScrollPanePartFirstButton:
                *outRect = bounds;
                outRect->right = outRect->left;
                return;

            case kScrollPanePartSecondButton:
                *outRect = bounds;
                outRect->left = outRect->right;
                return;

            default:
                break;
            }

            if (IsScrollThumbVisible()) {
                const int thumbLeft =
                    bounds.left +
                    (m_scrollPosition * (bounds.right - bounds.left - thumbExtent)) /
                        m_scrollRange;
                const int thumbRight = thumbLeft + thumbExtent;

                *outRect = bounds;
                switch (part) {
                case kScrollPanePartThumb:
                    outRect->left = thumbLeft;
                    outRect->right = thumbRight;
                    return;

                case kScrollPanePartPageBeforeThumb:
                    outRect->right = thumbLeft;
                    return;

                case kScrollPanePartPageAfterThumb:
                    outRect->left = thumbRight;
                    return;

                default:
                    return;
                }
            }

            if (part == kScrollPanePartThumb) {
                *outRect = bounds;
                outRect->left += thumbExtent;
                outRect->right -= thumbExtent;
                return;
            }

            if (part == kScrollPanePartPageBeforeThumb ||
                part == kScrollPanePartPageAfterThumb) {
                InitRectBounds(outRect, 0, 0, 0, 0);
            }
            return;
        }

        const int thumbExtent = kScrollPanePartExtentBySkin[m_scrollSkinIndex];

        switch (part) {
        case kScrollPanePartFirstButton:
            *outRect = bounds;
            outRect->bottom = outRect->top;
            return;

        case kScrollPanePartSecondButton:
            *outRect = bounds;
            outRect->top = outRect->bottom;
            return;

        default:
            break;
        }

        if (IsScrollThumbVisible()) {
            const int thumbLimit = bounds.bottom - thumbExtent;
            int thumbTop;

            if (m_thumbDragActive) {
                thumbTop = bounds.top + cursor.y - m_thumbDragOffset.y;
                if (thumbTop < bounds.top) {
                    thumbTop = bounds.top;
                }
                if (thumbTop > thumbLimit) {
                    thumbTop = thumbLimit;
                }
            } else {
                thumbTop =
                    bounds.top +
                    ((thumbLimit - bounds.top) * m_scrollPosition) / m_scrollRange;
            }

            const int thumbBottom = thumbTop + thumbExtent;

            *outRect = bounds;
            switch (part) {
            case kScrollPanePartThumb:
                outRect->top = thumbTop;
                outRect->bottom = thumbBottom;
                return;

            case kScrollPanePartPageBeforeThumb:
                outRect->bottom = thumbTop;
                return;

            case kScrollPanePartPageAfterThumb:
                outRect->top = thumbBottom;
                return;

            default:
                return;
            }
        }

        if (part == kScrollPanePartThumb) {
            *outRect = bounds;
            outRect->top += thumbExtent;
            outRect->bottom -= thumbExtent;
            return;
        }

        if (part == kScrollPanePartPageBeforeThumb ||
            part == kScrollPanePartPageAfterThumb) {
            InitRectBounds(outRect, 0, 0, 0, 0);
        }
        return;
    }

    const RectBounds bounds = m_bounds;
    if (m_orientation != 0) {
        const int extent = bounds.bottom - bounds.top;

        switch (part) {
        case kScrollPanePartFirstButton:
            *outRect = bounds;
            outRect->right = outRect->left + extent;
            return;

        case kScrollPanePartSecondButton:
            *outRect = bounds;
            outRect->left = outRect->right - extent;
            return;

        default:
            break;
        }

        if (IsScrollThumbVisible()) {
            const int thumbLeft =
                bounds.left + extent +
                (m_scrollPosition * (bounds.right - bounds.left - 3 * extent)) /
                    m_scrollRange;
            const int thumbRight = thumbLeft + extent;

            *outRect = bounds;
            switch (part) {
            case kScrollPanePartThumb:
                outRect->left = thumbLeft;
                outRect->right = thumbRight;
                return;

            case kScrollPanePartPageBeforeThumb:
                outRect->left += extent;
                outRect->right = thumbLeft;
                return;

            case kScrollPanePartPageAfterThumb:
                outRect->left = thumbRight;
                outRect->right -= extent;
                return;

            default:
                return;
            }
        }

        if (part == kScrollPanePartThumb) {
            *outRect = bounds;
            outRect->left += extent;
            outRect->right -= extent;
            return;
        }

        if (part == kScrollPanePartPageBeforeThumb ||
            part == kScrollPanePartPageAfterThumb) {
            InitRectBounds(outRect, 0, 0, 0, 0);
        }
        return;
    }

    const int extent = kClassicScrollPanePartExtentBySkin[m_scrollSkinIndex];

    switch (part) {
    case kScrollPanePartFirstButton:
        *outRect = bounds;
        outRect->bottom = outRect->top + extent;
        return;

    case kScrollPanePartSecondButton:
        *outRect = bounds;
        outRect->top = outRect->bottom - extent;
        return;

    default:
        break;
    }

    if (IsScrollThumbVisible()) {
        const int thumbTop =
            bounds.top + extent +
            (m_scrollPosition * (bounds.bottom - bounds.top - 3 * extent)) /
                m_scrollRange;
        const int thumbBottom = thumbTop + extent;

        *outRect = bounds;
        switch (part) {
        case kScrollPanePartThumb:
            outRect->top = thumbTop;
            outRect->bottom = thumbBottom;
            return;

        case kScrollPanePartPageBeforeThumb:
            outRect->top += extent;
            outRect->bottom = thumbTop;
            return;

        case kScrollPanePartPageAfterThumb:
            outRect->top = thumbBottom;
            outRect->bottom -= extent;
            return;

        default:
            return;
        }
    }

    if (part == kScrollPanePartThumb) {
        *outRect = bounds;
        outRect->top += extent;
        outRect->bottom -= extent;
        return;
    }

    if (part == kScrollPanePartPageBeforeThumb ||
        part == kScrollPanePartPageAfterThumb) {
        InitRectBounds(outRect, 0, 0, 0, 0);
    }
}

// UID:0004YI | by-memory/0x0055dea0-0x0055df10.ScrollPaneSetHighlightedPart.md | Completion:92 | Confidence:94
void ScrollPane::SetHighlightedPart(ScrollPanePart part)
{
    if (part == m_highlightPart) {
        return;
    }

    RectBounds bounds;
    if (m_highlightPart != kScrollPanePartNone) {
        GetScrollPartRect(m_highlightPart, &bounds);
        InvalidateRect(&bounds);
    }
    if (part != kScrollPanePartNone) {
        GetScrollPartRect(part, &bounds);
        InvalidateRect(&bounds);
    }

    m_highlightPart = part;
}

// UID:0004YJ | by-memory/0x0055df10-0x0055dfcf.ScrollPaneBeginPartPress.md | Completion:92 | Confidence:94
void ScrollPane::BeginPartPress(
    ScrollPanePart part,
    int localY,
    int localX)
{
    if (part == kScrollPanePartThumb) {
        RectBounds thumbBounds;
        SetHighlightedPart(kScrollPanePartThumb);
        GetScrollPartRect(kScrollPanePartThumb, &thumbBounds);
        m_thumbDragOffset.y = localY - thumbBounds.top;
        m_thumbDragOffset.x = localX - thumbBounds.left;
    }

    m_activePart = part;
    ProcessActivePart();
    ScheduleTimer(0, 200, 0, 0);
}

// UID:0004YL | by-memory/0x0055dfd0-0x0055e1ed.ScrollPaneProcessActivePart.md | Completion:93 | Confidence:94
void ScrollPane::ProcessActivePart()
{
    Point cursor;
    Point origin;
    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);
    if (origin.y == -1000 && origin.x == -1000) {
        return;
    }

    const int localY = cursor.y - origin.y;
    const int localX = cursor.x - origin.x;

    if (m_activePart == kScrollPanePartThumb) {
        UpdatePositionFromCursor(localY, localX);
        return;
    }

    const ScrollPanePart part = HitTestPart(localY, localX);
    if (g_useEpfAssets) {
        if (part == m_activePart) {
            UpdatePositionFromCursor(localY, localX);
        }
        SetHighlightedPart(kScrollPanePartNone);
        return;
    }

    if (part != m_activePart) {
        SetHighlightedPart(kScrollPanePartNone);
        return;
    }

    SetHighlightedPart(part);

    ScrollablePane *owner = static_cast<ScrollablePane *>(GetParentPane());
    const short oldPosition = m_scrollPosition;
    int newPosition = oldPosition;
    switch (m_activePart) {
    case kScrollPanePartFirstButton:
        --newPosition;
        break;
    case kScrollPanePartPageBeforeThumb:
        newPosition -= owner->GetPageSize(m_orientation);
        break;
    case kScrollPanePartPageAfterThumb:
        newPosition += owner->GetPageSize(m_orientation);
        break;
    case kScrollPanePartSecondButton:
        ++newPosition;
        break;
    default:
        return;
    }

    if (newPosition < 0) {
        newPosition = 0;
    } else if (newPosition > m_scrollRange) {
        newPosition = m_scrollRange;
    }

    if (newPosition != oldPosition) {
        owner->ApplyScrollPosition(
            m_orientation,
            oldPosition,
            static_cast<short>(newPosition));
    }
}

// UID:0004YM | by-memory/0x0055e210-0x0055e5f6.ScrollPaneUpdatePositionFromCursor.md | Completion:93 | Confidence:94
void ScrollPane::UpdatePositionFromCursor(int localY, int localX)
{
    RectBounds firstButton;
    RectBounds secondButton;
    RectBounds thumb;
    GetScrollPartRect(kScrollPanePartFirstButton, &firstButton);
    GetScrollPartRect(kScrollPanePartSecondButton, &secondButton);
    GetScrollPartRect(kScrollPanePartThumb, &thumb);

    int thumbStart;
    int lowerBound;
    int upperBound;
    if (m_orientation != 0) {
        thumbStart = localX - m_thumbDragOffset.x;
        if (g_useEpfAssets) {
            ++thumbStart;
        }
        lowerBound = firstButton.right;
        upperBound = secondButton.left + thumb.left - thumb.right;
    } else {
        thumbStart = localY - m_thumbDragOffset.y;
        if (g_useEpfAssets) {
            ++thumbStart;
        }
        lowerBound = firstButton.bottom;
        upperBound = secondButton.top + thumb.top - thumb.bottom;
    }

    if (thumbStart < lowerBound) {
        thumbStart = lowerBound;
    } else if (thumbStart > upperBound) {
        thumbStart = upperBound;
    }

    int newPosition;
    if (m_orientation == 0 && g_useEpfAssets) {
        newPosition =
            ((m_scrollRange + 1) * (thumbStart - lowerBound)) /
            (upperBound - lowerBound);
        if (newPosition > m_scrollRange) {
            newPosition = m_scrollRange;
        }
    } else {
        newPosition =
            (m_scrollRange * (thumbStart - lowerBound)) /
            (upperBound - lowerBound);
    }

    const short oldPosition = m_scrollPosition;
    if (newPosition != oldPosition) {
        ScrollablePane *owner =
            static_cast<ScrollablePane *>(GetParentPane());
        owner->ApplyScrollPosition(
            m_orientation,
            oldPosition,
            static_cast<short>(newPosition));
    }
}

// UID:0004YN | by-memory/0x0055e600-0x0055e65c.ScrollPaneResetScrollState.md | Completion:92 | Confidence:94
void ScrollPane::ResetScrollState()
{
    RemovePendingTimers();
    m_activePart = kScrollPanePartNone;

    if (m_highlightPart != kScrollPanePartNone) {
        RectBounds bounds;
        GetScrollPartRect(m_highlightPart, &bounds);
        InvalidateRect(&bounds);
        m_highlightPart = kScrollPanePartNone;
    }
}

// UID:0003CK | by-memory/0x00623d58-0x00623de0.ScrollPaneVtableData.md | Completion:87 | Confidence:90
// ScrollPane RTTI/vtable bytes are compiler-generated from the class virtual method set; no handwritten table source is emitted.

// UID:0000CP | by-class/ScrollWidget.md | Completion:86 | Confidence:86
// ScrollWidget class routing is documented here; exact target/current/enable/disable method bodies emit through child pages.
// UID:00042Y | by-memory/0x0055c310-0x0055c36b.ScrollWidgetSetScrollTargetValue.md | Completion:90 | Confidence:91
void ScrollWidget::SetScrollTargetValue(short targetPosition)
{
    if (targetPosition < 0)
        targetPosition = 0;
    if (targetPosition > 30000)
        targetPosition = 30000;

    if (m_targetPosition == targetPosition)
        return;

    if (targetPosition < m_currentPosition) {
        m_currentPosition = targetPosition;
        InvalidateRect(&m_bounds);
    }

    m_targetPosition = targetPosition;
    InvalidateRect(&m_bounds);
}

// UID:00042Z | by-memory/0x0055c370-0x0055c397.ScrollWidgetCurrentValueSetterRaw.md | Completion:87 | Confidence:88
void ScrollWidget::SetScrollCurrentValue(short currentPosition)
{
    if (m_currentPosition == currentPosition)
        return;

    m_currentPosition = currentPosition;
    InvalidateRect(&m_bounds);
}

// UID:000430 | by-memory/0x0055c3a0-0x0055c3ba.ScrollWidgetEnable.md | Completion:88 | Confidence:90
void ScrollWidget::Enable()
{
    if (m_enabled)
        return;

    m_enabled = true;
    InvalidateRect(&m_bounds);
}

// UID:000431 | by-memory/0x0055c3c0-0x0055c3da.ScrollWidgetDisable.md | Completion:88 | Confidence:91
void ScrollWidget::Disable()
{
    if (!m_enabled)
        return;

    m_enabled = false;
    InvalidateRect(&m_bounds);
}

// UID:0000CF | by-class/ScrollablePane.md | Completion:93 | Confidence:94
#include "ScrollBar.h"

// UID:0001GL | by-memory/0x0055e660-0x0055f44f.ScrollablePaneCore.md | Completion:91 | Confidence:92
ScrollablePane::ScrollablePane(bool horizontalScrollEnabled,
                               bool verticalScrollEnabled)
    : Pane(1)
{
    m_horizontalScrollBarOffset = 0;
    m_verticalScrollBarOffset = 0;
    m_scrollBarInset = 0;
    m_horizontalScrollEnabled = horizontalScrollEnabled;
    m_horizontalScrollPane = new ScrollPane(true);
    m_verticalScrollEnabled = verticalScrollEnabled;
    m_verticalScrollPane = new ScrollPane(false);
    InitRectBounds(&m_contentRect, 0, 0, 0, 0);
    InitRectBounds(&m_scrollContentRect, 0, 0, 0, 0);
}

ScrollablePane::~ScrollablePane()
{
    delete m_horizontalScrollPane;
    m_horizontalScrollPane = 0;
    delete m_verticalScrollPane;
    m_verticalScrollPane = 0;
}

void ScrollablePane::SetSkinIndex(unsigned short skinIndex)
{
    if (m_horizontalScrollPane != 0)
        m_horizontalScrollPane->SetSkinIndex(skinIndex);
    if (m_verticalScrollPane != 0)
        m_verticalScrollPane->SetSkinIndex(skinIndex);
}

void ScrollablePane::SetScrollbarsVisible(bool visible)
{
    if (m_horizontalScrollPane != 0) {
        m_horizontalScrollPane->SetScrollStyle(
            static_cast<unsigned char>(visible));
    }

    if (m_verticalScrollPane != 0) {
        m_verticalScrollPane->SetScrollStyle(
            static_cast<unsigned char>(visible));
    }
}
// [0x0055e8a0-0x0055e8c7] No code emitted: this raw selected-child target
// setter is covered by the source declaration SetScrollTargetValue and the
// exact ScrollableControlPane wrapper route, but its only callee contract is
// still an undeclared ScrollWidget private setter.
// [0x0055e8d0-0x0055e90c] No code emitted: this raw selected-child current
// setter is covered by SetScrollCurrentValue and its wrapper route, while its
// direct +0xfe write and +0x20 callback require an unresolved private child ABI.
// [0x0055e910-0x0055e949] No code emitted: GetScrollMax is declared and
// target-proven, but reading ScrollPane private +0x100 as a public member would
// invent access not present in the recovered ScrollPane declaration.
// [0x0055e950-0x0055e989] No code emitted: GetScrollPosition is declared and
// target-proven, but its private child +0xfe access has the same unresolved API.
// [0x0055e990-0x0055ead5] No code emitted: SyncScrollbars is declared and its
// exact range/overflow/clamp behavior is documented, but it depends on both
// unresolved private selected-child setters and internal recompute 0x0055f250.
// [0x0055eae0-0x0055ec00] No code emitted: ApplyScrollPosition is declared,
// but the target's Region/GrafPort movement transaction includes unresolved
// UID0004H7 and temporary-region source contracts; a partial body is unsafe.
// [0x0055ec00-0x0055edeb] No code emitted: LayoutScrollbars is declared, but
// exact child bounds/layer APIs and the four mode/skin constant declarations
// are not all available in this formal channel.
// [0x0055edf0-0x0055ee04] No code emitted: raw content-rect copy has no IDA
// function and no current xrefs, so no standalone member is promoted.
// [0x0055ee10-0x0055ef08] No code emitted: layer attach/move is source-shaped,
// but exact base and child +0x28/+0x30 virtual signatures remain unresolved.
// [0x0055ef10-0x0055ef43] No code emitted: detach is source-shaped, but exact
// child +0x38 and base removal signatures remain unresolved.
// [0x0055ef50-0x0055f0ca] No code emitted: EventHandler-adjusted mouse/wheel
// dispatch is target-proven, but complete Event and owner fallback signatures
// are not declared by this class formal.
// [0x0055f0d0-0x0055f128] No code emitted: adjusted key/text dispatch has the
// same unresolved EventHandler child/fallback API boundary.
// [0x0055f130-0x0055f188] No code emitted: key-up dispatch is target-proven,
// but the child and owner key-up virtual signatures remain unresolved.
// [0x0055f190-0x0055f243] No code emitted: update-region hook requires the
// unresolved temporary Region source type and primary +0x6c hook declaration.
// [0x0055f250-0x0055f44f] No code emitted: this private recompute helper is
// reached only from SyncScrollbars/LayoutScrollbars and depends on all of the
// preceding unresolved child/layout contracts; emitting it alone is unsafe.

// UID:0001H6 | by-memory/0x005654ec-0x00565608.ScrollablePaneVirtualDefaults.md | Completion:92 | Confidence:94
short ScrollablePane::GetScrollRange(char axis)
{
    return 0;
}

short ScrollablePane::GetOverflowCount(char axis)
{
    return 0;
}

short ScrollablePane::GetPageSize(char axis)
{
    return 1;
}

short ScrollablePane::GetScrollOffset(char axis, short units)
{
    return 0;
}

Point *ScrollablePane::GetContentSize(Point *outSize)
{
    outSize->y = 0;
    outSize->x = 0;
    return outSize;
}

Point *ScrollablePane::GetScrollDelta(Point *outDelta, char axis,
                                      short oldPosition, short newPosition)
{
    outDelta->y = 0;
    outDelta->x = 0;
    return outDelta;
}

// [0x005654ec-0x005654f7] No code emitted: compiler-generated secondary
// destructor adjustor thunk; the ordinary destructor is emitted by UID0001GL.
// [0x005654f7-0x00565502] No code emitted: compiler-generated tertiary
// destructor adjustor thunk; the ordinary destructor is emitted by UID0001GL.
// [0x00565510-0x0056559a] No code emitted: MSVC scalar deleting destructor
// wrapper. UID0001GL emits the one source-level ScrollablePane destructor.

// UID:0003CL | by-memory/0x00623de0-0x00623e90.ScrollablePaneVtableData.md | Completion:88 | Confidence:91
// ScrollablePane RTTI/vtable bytes are compiler-generated from the class virtual/default method set; no handwritten table source is emitted.

// UID:0003CQ | by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md | Completion:92 | Confidence:93
static const int kScrollPaneWidthBySkin[3] = { 13, 13, 13 };
const int kScrollPanePartExtentBySkin[3] = { 38, 38, 38 };
static const int kClassicScrollPaneWidthBySkin[3] = { 13, 12, 12 };
static const int kClassicScrollPanePartExtentBySkin[3] = { 13, 10, 10 };
