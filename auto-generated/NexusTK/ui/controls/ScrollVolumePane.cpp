// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NK
// Source by-file doc: by-file/ScrollVolumePane.md
// UID:0000CO | by-class/ScrollVolumePane.md | Completion:93 | Confidence:94
// UID:0004XQ | by-memory/0x00564710-0x005647b1.ScrollVolumePaneConstructor.md | Completion:92 | Confidence:94
ScrollVolumePane::ScrollVolumePane(unsigned char volumeType)
    : Pane(true),
      m_trackStateWord(0),
      m_scrollStyle(1),
      m_thumbDragActive(false),
      m_volumeType(volumeType),
      m_value(0),
      m_range(0),
      m_enabled(true),
      m_hoverPart(kScrollVolumePartNone),
      m_activePart(kScrollVolumePartNone)
{
    m_thumbDragOffset.y = 0;
    m_thumbDragOffset.x = 0;
}

// UID:00031M | by-memory/0x005647c0-0x005647e7.ScrollVolumePaneSetTrackStateWordRaw.md | Completion:90 | Confidence:92
void ScrollVolumePane::SetTrackStateWord(unsigned short state)
{
    if (m_trackStateWord == state) {
        return;
    }

    m_trackStateWord = state;
    InvalidateRect(&m_bounds);
}

// UID:00031N | by-memory/0x005647f0-0x00564814.ScrollVolumePaneSetScrollStyleRaw.md | Completion:90 | Confidence:92
void ScrollVolumePane::SetScrollStyle(unsigned char style)
{
    if (m_scrollStyle == style) {
        return;
    }

    m_scrollStyle = style;
    InvalidateRect(&m_bounds);
}

// UID:0004XR | by-memory/0x00564820-0x0056487b.ScrollVolumePaneSetRange.md | Completion:92 | Confidence:94
void ScrollVolumePane::SetRange(short range)
{
    if (range < 0) {
        range = 0;
    }
    if (range > 30000) {
        range = 30000;
    }

    if (m_range == range) {
        return;
    }

    if (m_value > range) {
        m_value = range;
        InvalidateRect(&m_visibleBounds);
    }

    m_range = range;
    InvalidateRect(&m_visibleBounds);
}

// UID:0004XS | by-memory/0x00564880-0x005648a7.ScrollVolumePaneSetValue.md | Completion:92 | Confidence:94
void ScrollVolumePane::SetValue(short value)
{
    if (m_value != value) {
        m_value = value;
        InvalidateRect(&m_visibleBounds);
    }
}

// UID:0004XT | by-memory/0x005648b0-0x005648ca.ScrollVolumePaneEnable.md | Completion:91 | Confidence:93
void ScrollVolumePane::Enable()
{
    if (!m_enabled) {
        m_enabled = true;
        InvalidateRect(&m_bounds);
    }
}

// UID:0004XU | by-memory/0x005648d0-0x005648ea.ScrollVolumePaneDisable.md | Completion:91 | Confidence:93
void ScrollVolumePane::Disable()
{
    if (m_enabled) {
        m_enabled = false;
        InvalidateRect(&m_bounds);
    }
}

// UID:00031O | by-memory/0x005648f0-0x0056490a.ScrollVolumePaneCanAdjustRaw.md | Completion:91 | Confidence:93
bool ScrollVolumePane::CanAdjust() const
{
    return m_enabled && m_range > 0;
}

// UID:0004XV | by-memory/0x00564910-0x00564af1.ScrollVolumePaneHandlePointerOrMouseEvent.md | Completion:92 | Confidence:94
bool ScrollVolumePane::HandlePointerOrMouseEvent(Event *event)
{
    bool handled = false;
    RectBounds partRect;
    const int localY = event->m_pointer.m_y;
    const int localX = event->m_pointer.m_x;

    switch (event->m_type) {
    case kEventPointerMove:
        if (m_activePart != kScrollVolumePartNone) {
            InvalidateRect(&m_bounds);
            handled = true;
        }
        break;

    case kEventLeftButtonDown:
        if (!PointInRect(localY, localX, &m_bounds) || !CanAdjust())
            return false;

        if (m_activePart == kScrollVolumePartNone) {
            const ScrollVolumePart part = HitTestPart(localY, localX);
            if (part != kScrollVolumePartNone) {
                CaptureMouse();
                BeginInteraction(part, localY, localX);
                InvalidateRect(&m_bounds);
            }
        }

        m_thumbDragActive = true;
        handled = true;
        break;

    case kEventLeftButtonUp:
        if (m_activePart != kScrollVolumePartNone) {
            ReleaseMouseCapture();
            ResetInteractionState();
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

// UID:0004XW | by-memory/0x00564b00-0x00564b05.ScrollVolumePaneHandleKeyOrTextEvent.md | Completion:92 | Confidence:94
bool ScrollVolumePane::HandleKeyOrTextEvent(Event *)
{
    return false;
}

// UID:0004XX | by-memory/0x00564b10-0x00564b43.ScrollVolumePaneOnTimer.md | Completion:92 | Confidence:94
bool ScrollVolumePane::OnTimer(int timerId, int, int)
{
    if (timerId == 0 && m_activePart != kScrollVolumePartNone) {
        CommitInteraction();
        ScheduleTimer(0, 30, 0, 0);
    }
    return true;
}

// UID:0004XY | by-memory/0x00564b50-0x00564e21.ScrollVolumePaneOnPaint.md | Completion:90 | Confidence:92
void ScrollVolumePane::OnPaint()
{
    EPFTileContext tile;
    RectBounds clipRect;
    RectBounds partRect;
    RectBounds drawRect;

    InitTileContext(&tile);
    GetClipRect(&clipRect);

    if (m_enabled && m_range > 0) {
        GetPartRect(kScrollVolumePartPageBeforeThumb, &partRect);
        if (IntersectRects(&drawRect, &partRect, &clipRect)) {
            SetDrawColor(0);
            FillRect(&drawRect);
            SetDrawColor(128);
        }

        GetPartRect(kScrollVolumePartPageAfterThumb, &partRect);
        if (IntersectRects(&drawRect, &partRect, &clipRect)) {
            SetDrawColor(0);
            FillRect(&drawRect);
            SetDrawColor(128);
        }

        GetPartRect(kScrollVolumePartThumb, &partRect);
        if (IntersectRects(&drawRect, &partRect, &clipRect)) {
            SetDrawColor(0);
            FillRect(&drawRect);
            SetDrawColor(128);

            ResourceLayoutTable::LookupLayoutEntry(
                g_pResourceLayoutTable,
                L"SCRBUTT2.EPF",
                m_hoverPart == kScrollVolumePartThumb ? 1 : 0,
                &tile);
            RenderTileFrame(this, &tile, &drawRect, L"BUTTON.PAL");
        }
        return;
    }

    if (!m_enabled) {
        SetDrawColor(0);
        FillRect(&clipRect);
        SetDrawColor(128);
    }
}

// UID:0001H3 | by-memory/0x00564e30-0x00565006.ScrollVolumePaneHitTestPart.md | Completion:91 | Confidence:93
ScrollVolumePart ScrollVolumePane::HitTestPart(int localY, int localX)
{
    Point cursor;
    Point origin;

    g_pEventMan->GetCursorPosition(&cursor);
    GetScreenOffset(&origin);

    if (origin.y == -1000 && origin.x == -1000)
        return kScrollVolumePartNone;

    cursor.y -= origin.y;
    cursor.x -= origin.x;

    for (int partValue = kScrollVolumePartLeading;
         partValue <= kScrollVolumePartTrailing;
         ++partValue) {
        const ScrollVolumePart part = static_cast<ScrollVolumePart>(partValue);
        RectBounds rect = m_bounds;

        if (part == kScrollVolumePartLeading) {
            rect.right = rect.left;
        } else if (part == kScrollVolumePartTrailing) {
            rect.left = rect.right;
        } else if (m_enabled && m_range > 0) {
            const int trackStart = m_bounds.left;
            const int thumbLimit = m_bounds.right - kThumbSpan;
            int thumbLeft;

            if (m_thumbDragActive) {
                const int cursorAlongTrack = cursor.x;
                const int dragOffsetAlongTrack = m_thumbDragOffset.x;

                thumbLeft = cursorAlongTrack - dragOffsetAlongTrack;

                if (thumbLeft < trackStart) {
                    thumbLeft = trackStart;
                }
                if (thumbLeft > thumbLimit) {
                    thumbLeft = thumbLimit;
                }
            } else {
                thumbLeft = trackStart + ((thumbLimit - trackStart) * m_value) / m_range;
            }

            const int thumbRight = thumbLeft + kThumbSpan;

            if (part == kScrollVolumePartThumb) {
                rect.left = thumbLeft;
                rect.right = thumbRight;
            } else if (part == kScrollVolumePartPageBeforeThumb) {
                rect.right = thumbLeft;
            } else if (part == kScrollVolumePartPageAfterThumb) {
                rect.left = thumbRight;
            }
        } else if (part == kScrollVolumePartThumb) {
            rect.left += kThumbSpan;
            rect.right -= kThumbSpan;
        } else {
            SetRect(&rect, 0, 0, 0, 0);
        }

        if (PointInRect(localY, localX, &rect)) {
            return part;
        }
    }

    return kScrollVolumePartNone;
}

// UID:0004XZ | by-memory/0x00565010-0x0056516b.ScrollVolumePaneGetPartRect.md | Completion:92 | Confidence:94
void ScrollVolumePane::GetPartRect(ScrollVolumePart part,
                                   RectBounds *outRect)
{
    *outRect = m_bounds;

    if (part == kScrollVolumePartLeading) {
        outRect->right = outRect->left;
        return;
    }
    if (part == kScrollVolumePartTrailing) {
        outRect->left = outRect->right;
        return;
    }

    if (!m_enabled || m_range <= 0) {
        if (part == kScrollVolumePartThumb) {
            outRect->left += kThumbSpan;
            outRect->right -= kThumbSpan;
        } else {
            SetRect(outRect, 0, 0, 0, 0);
        }
        return;
    }

    const int trackStart = m_bounds.left;
    const int thumbLimit = m_bounds.right - kThumbSpan;
    int thumbLeft;

    if (m_thumbDragActive) {
        Point cursor;
        Point origin;
        g_pEventMan->GetCursorPosition(&cursor);
        GetScreenOffset(&origin);
        cursor.y -= origin.y;
        cursor.x -= origin.x;
        thumbLeft = cursor.x - m_thumbDragOffset.x;
    } else {
        thumbLeft = trackStart +
            ((thumbLimit - trackStart) * m_value) / m_range;
    }

    if (thumbLeft < trackStart)
        thumbLeft = trackStart;
    if (thumbLeft > thumbLimit)
        thumbLeft = thumbLimit;

    const int thumbRight = thumbLeft + kThumbSpan;
    if (part == kScrollVolumePartPageBeforeThumb) {
        outRect->right = thumbLeft;
    } else if (part == kScrollVolumePartThumb) {
        outRect->left = thumbLeft;
        outRect->right = thumbRight;
    } else if (part == kScrollVolumePartPageAfterThumb) {
        outRect->left = thumbRight;
    }
}

// UID:0002LB | by-memory/0x00565170-0x005651e0.ScrollVolumePaneSetHoverPartRaw.md | Completion:90 | Confidence:92
void ScrollVolumePane::SetHoverPart(ScrollVolumePart part)
{
    RectBounds rect;
    const ScrollVolumePart oldPart =
        static_cast<ScrollVolumePart>(m_hoverPart);

    if (oldPart == part)
        return;

    if (oldPart != kScrollVolumePartNone) {
        GetPartRect(oldPart, &rect);
        InvalidateRect(&rect);
    }

    if (part != kScrollVolumePartNone) {
        GetPartRect(part, &rect);
        InvalidateRect(&rect);
    }

    m_hoverPart = static_cast<signed char>(part);
}

// UID:0002LC | by-memory/0x005651e0-0x0056529f.ScrollVolumePaneBeginInteractionRaw.md | Completion:91 | Confidence:93
void ScrollVolumePane::BeginInteraction(ScrollVolumePart part,
                                        int localY,
                                        int localX)
{
    RectBounds rect;

    if (part == kScrollVolumePartThumb) {
        if (m_hoverPart != kScrollVolumePartThumb) {
            if (m_hoverPart != kScrollVolumePartNone) {
                GetPartRect(static_cast<ScrollVolumePart>(m_hoverPart), &rect);
                InvalidateRect(&rect);
            }

            GetPartRect(kScrollVolumePartThumb, &rect);
            InvalidateRect(&rect);
            m_hoverPart = kScrollVolumePartThumb;
        }

        GetPartRect(kScrollVolumePartThumb, &rect);
        m_thumbDragOffset.y = localY - rect.top;
        m_thumbDragOffset.x = localX - rect.left;
    }

    m_activePart = static_cast<signed char>(part);
    CommitInteraction();
    ScheduleTimer(0, 200, 0, 0);
}

// UID:0001H4 | by-memory/0x005652a0-0x00565360.ScrollVolumePaneCommitInteraction.md | Completion:91 | Confidence:93
void ScrollVolumePane::CommitInteraction()
{
    Point cursor;
    Point origin;
    RectBounds partRect;
    int localY;
    int localX;
    ScrollVolumePart activePart;

    g_pEventMan->GetCursorPosition(&cursor);
    if (cursor.x != -1000 || cursor.y != -1000) {
        GetScreenOffset(&origin);
        localY = cursor.y - origin.y;
        localX = cursor.x - origin.x;

        activePart = static_cast<ScrollVolumePart>(m_activePart);
        if (activePart == kScrollVolumePartThumb) {
            NotifyValueChange(localY, localX);
        } else if (activePart != kScrollVolumePartNone &&
                   HitTestPart(localY, localX) == activePart) {
            NotifyValueChange(localY, localX);
        }
    }

    if (m_hoverPart != kScrollVolumePartNone) {
        GetPartRect(static_cast<ScrollVolumePart>(m_hoverPart), &partRect);
        InvalidateRect(&partRect);
        m_hoverPart = kScrollVolumePartNone;
    }
}

// UID:0001H5 | by-memory/0x00565360-0x00565488.ScrollVolumePaneNotifyValueChange.md | Completion:91 | Confidence:93
void ScrollVolumePane::NotifyValueChange(int localY, int localX)
{
    RectBounds leftRect;
    RectBounds thumbRect;
    RectBounds rightRect;
    short oldValue;
    int leftLimit;
    int rightLimit;
    int thumbWidth;
    int thumbLeft;
    int travel;
    int value;
    NewOptionPane *owner;

    oldValue = m_value;

    GetPartRect(kScrollVolumePartThumb, &thumbRect);
    GetPartRect(kScrollVolumePartLeading, &leftRect);
    GetPartRect(kScrollVolumePartTrailing, &rightRect);

    leftLimit = leftRect.right;
    rightLimit = rightRect.left;
    thumbWidth = thumbRect.right - thumbRect.left;

    thumbLeft = localX - m_thumbDragOffset.x + 1;
    if (thumbLeft < leftLimit) {
        thumbLeft = leftLimit;
    }
    if (thumbLeft > rightLimit - thumbWidth) {
        thumbLeft = rightLimit - thumbWidth;
    }

    travel = rightLimit - leftLimit - thumbWidth;
    value = ((thumbLeft - leftLimit) * (m_range + 1)) / travel;
    if (value > m_range) {
        value = m_range;
    }

    if (oldValue != value) {
        owner = static_cast<NewOptionPane *>(GetParentPane());
        owner->OnVolumeChanged(m_volumeType, oldValue, value);
    }
}

// UID:0002LD | by-memory/0x00565490-0x005654ec.ScrollVolumePaneResetInteractionStateRaw.md | Completion:90 | Confidence:92
void ScrollVolumePane::ResetInteractionState()
{
    RectBounds rect;
    ScrollVolumePart oldPart;

    RemovePendingTimers();

    oldPart = static_cast<ScrollVolumePart>(m_hoverPart);
    m_activePart = static_cast<signed char>(kScrollVolumePartNone);

    if (oldPart != static_cast<signed char>(kScrollVolumePartNone)) {
        GetPartRect(static_cast<ScrollVolumePart>(oldPart), &rect);
        InvalidateRect(&rect);
        m_hoverPart = static_cast<signed char>(kScrollVolumePartNone);
    }
}

// UID:0003CP | by-memory\0x006240b0-0x00624138.ScrollVolumePaneVtableData.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003CR | by-memory\0x00624168-0x00624184.ScrollVolumePaneButtonResourceString.md | Completion:85 | Confidence:90 | Empty Emitter Marker

// UID:0001W2 | by-type\by-struct\ScrollVolumePaneLayout.md | Completion:92 | Confidence:94 | Empty Emitter Marker

// UID:0001YT | by-type\by-vtable\ScrollVolumePaneVtables.md | Completion:91 | Confidence:94 | Empty Emitter Marker
