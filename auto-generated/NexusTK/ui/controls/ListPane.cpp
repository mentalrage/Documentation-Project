// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KT
// Source by-file doc: by-file/ListPane.md
// UID:00007A | by-class/ListPane.md | Completion:95 | Confidence:94
#include "ListPane.h"
#include "../../util/List.h"

// UID:000500 | by-memory/0x004f3bb0-0x004f3bcb.ListPaneGetItemSize.md | Completion:91 | Confidence:92
Point ListPane::GetItemSize() const
{
    return m_itemSize;
}

// UID:000501 | by-memory/0x004f3bd0-0x004f3bdf.ListPaneGetItemCount.md | Completion:92 | Confidence:94
int ListPane::GetItemCount() const
{
    return m_items != NULL ? m_items->GetCount() : 0;
}

// UID:000502 | by-memory/0x004f3be0-0x004f3bfb.ListPaneGetRowCount.md | Completion:91 | Confidence:92
int ListPane::GetRowCount() const
{
    if (m_items == NULL)
        return 0;

    return (m_items->GetCount() - 1) / m_columnCount + 1;
}

// UID:000503 | by-memory/0x004f3c00-0x004f3c4b.ListPaneInsertItem.md | Completion:92 | Confidence:94
void ListPane::InsertItem(int index, void *item)
{
    unsigned char selected = 0;
    m_items->InsertAt(index, 1, item);
    m_selectionFlags->InsertAt(index, 1, &selected);
    SyncScrollbars();
    Invalidate(&m_contentRect);
}

// UID:000504 | by-memory/0x004f3c50-0x004f3ca4.ListPaneAddEntry.md | Completion:92 | Confidence:94
void ListPane::AddEntry(void *item)
{
    int index = m_items != NULL ? m_items->GetCount() : 0;
    unsigned char selected = 0;
    m_items->InsertAt(index, 1, item);
    m_selectionFlags->InsertAt(index, 1, &selected);
    SyncScrollbars();
    Invalidate(&m_contentRect);
}

// UID:000505 | by-memory/0x004f3cb0-0x004f3cfd.ListPaneInsertItems.md | Completion:92 | Confidence:93
void ListPane::InsertItems(int index, int count, void *items)
{
    unsigned char selected = 0;
    m_items->InsertAt(index, count, items);
    m_selectionFlags->InsertAt(index, count, &selected);
    SyncScrollbars();
    Invalidate(&m_contentRect);
}

// UID:000506 | by-memory/0x004f3d00-0x004f3d56.ListPaneAddEntries.md | Completion:92 | Confidence:93
void ListPane::AddEntries(int count, void *items)
{
    int index = m_items != NULL ? m_items->GetCount() : 0;
    unsigned char selected = 0;
    m_items->InsertAt(index, count, items);
    m_selectionFlags->InsertAt(index, count, &selected);
    SyncScrollbars();
    Invalidate(&m_contentRect);
}

// UID:000507 | by-memory/0x004f3d60-0x004f3db7.ListPaneRemoveItems.md | Completion:92 | Confidence:94
void ListPane::RemoveItems(int index, int count)
{
    m_items->RemoveAt(index, count);
    m_selectionFlags->RemoveAt(index, count);
    SyncScrollbars();
    Invalidate(&m_contentRect);
    m_selectedIndex = -1;
    OnItemSelected(-1, false);
}

// UID:000508 | by-memory/0x004f3dc0-0x004f3dcf.ListPaneGetItem.md | Completion:92 | Confidence:94
void *ListPane::GetItem(int index)
{
    return m_items->GetElementAt(index);
}

// UID:0004LX | by-memory/0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled.md | Completion:92 | Confidence:94
void ListPane::SetMultipleSelectionEnabled(unsigned char enabled)
{
    if (m_multipleSelectionEnabled == enabled)
        return;

    m_multipleSelectionEnabled = enabled;
    unsigned char *selectionFlags =
        static_cast<unsigned char *>(m_selectionFlags->GetData());

    for (int i = m_selectionFlags->GetCount() - 1; i >= 0; --i)
        selectionFlags[i] = 0;

    Invalidate(&m_scrollContentRect);
}

// UID:0004M9 | by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md | Completion:92 | Confidence:94
int ListPane::GetSelectionCount() const
{
    if (!m_multipleSelectionEnabled)
        return m_selectedIndex >= 0;

    int selectedCount = 0;
    const unsigned char *selectionFlags =
        static_cast<const unsigned char *>(m_selectionFlags->GetData());

    for (int i = 0; i < m_selectionFlags->GetCount(); ++i)
    {
        if (selectionFlags[i] != 0)
            ++selectedCount;
    }

    return selectedCount;
}

// UID:000509 | by-memory/0x004f3e80-0x004f3ef7.ListPaneGetSelectedIndices.md | Completion:92 | Confidence:94
int ListPane::GetSelectedIndices(int *indices, int maxCount) const
{
    if (!m_multipleSelectionEnabled)
    {
        if (m_selectedIndex < 0 || maxCount <= 0)
            return 0;

        indices[0] = m_selectedIndex;
        return 1;
    }

    int selectedCount = 0;
    const unsigned char *selectionFlags =
        static_cast<const unsigned char *>(m_selectionFlags->GetData());
    for (int index = 0;
         index < m_selectionFlags->GetCount() && selectedCount < maxCount;
         ++index)
    {
        if (selectionFlags[index] != 0)
            indices[selectedCount++] = index;
    }
    return selectedCount;
}

// UID:00050A | by-memory/0x004f3f00-0x004f3f1b.ListPaneIsItemSelected.md | Completion:92 | Confidence:94
bool ListPane::IsItemSelected(int index) const
{
    return *static_cast<unsigned char *>(
               m_selectionFlags->GetElementAt(index)) != 0;
}

// UID:0003U1 | by-memory/0x004f3f20-0x004f4190.ListPaneScrollMetricVirtuals.md | Completion:93 | Confidence:94
short ListPane::GetScrollRange(char axis)
{
    if (axis != 0)
    {
        const int overflowPixels =
            m_itemSize.x - m_contentRect.right + m_contentRect.left - 1;
        return static_cast<short>(overflowPixels / 20 + 1);
    }

    if (m_itemSize.y == 0)
        return 0;

    const int rowCount = GetRowCount();
    const int viewportHeight = m_contentRect.bottom - m_contentRect.top;
    if (rowCount * m_itemSize.y < viewportHeight)
        return 0;

    return static_cast<short>(
        (rowCount * m_itemSize.y - viewportHeight - 1) / m_itemSize.y + 1);
}

short ListPane::GetOverflowCount(char axis)
{
    if (axis != 0)
    {
        if (m_contentRect.left <= m_scrollContentRect.left)
            return 0;
        return static_cast<short>(
            (m_contentRect.left - m_scrollContentRect.left - 1) / 20 + 1);
    }

    if (m_itemSize.y == 0 ||
        m_contentRect.top <= m_scrollContentRect.top)
        return 0;

    return static_cast<short>(
        (m_contentRect.top - m_scrollContentRect.top - 1) / m_itemSize.y + 1);
}

short ListPane::GetPageSize(char axis)
{
    if (axis != 0)
        return 1;
    if (m_itemSize.y == 0)
        return 0;

    return static_cast<short>(
        m_columnCount *
        ((m_contentRect.bottom - m_contentRect.top) / m_itemSize.y) - 1);
}

short ListPane::GetScrollOffset(char axis, short units)
{
    return static_cast<short>(
        units * (axis != 0 ? m_itemSize.x : m_itemSize.y));
}

Point *ListPane::GetContentSize(Point *outSize)
{
    outSize->y = m_itemSize.y * GetRowCount();
    outSize->x = m_columnCount * m_itemSize.x;
    return outSize;
}

Point *ListPane::GetScrollDelta(Point *outDelta, char axis,
                                short oldPosition, short newPosition)
{
    const int positionDelta = oldPosition - newPosition;
    if (axis != 0)
    {
        outDelta->y = 0;
        outDelta->x = 20 * positionDelta;
    }
    else
    {
        outDelta->y = m_itemSize.y * positionDelta;
        outDelta->x = 0;
    }
    return outDelta;
}

// UID:0003U2 | by-memory/0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables.md | Completion:92 | Confidence:93
bool ListPane::OnMouseEvent(MouseEvent *event)
{
    const int x = event->x;
    const int y = event->y;

    switch (event->type)
    {
    case MouseEvent::Move:
        if (!m_dragSelectionActive)
            return false;
        {
            const int itemIndex = HitTestItem(x, y);
            if (itemIndex != -1)
                EnsureItemVisible(itemIndex);
        }
        return true;

    case MouseEvent::LeftButtonDown:
        if (m_dragSelectionActive || !PointInRect(x, y, &m_contentRect))
            return false;
        {
            const int itemIndex = HitTestItem(x, y);
            if (itemIndex == -1)
                return false;
            OnItemSelected(itemIndex, event->modifierFlags);
            m_dragSelectionActive = 1;
            g_pEventMan->CaptureMouse();
        }
        return true;

    case MouseEvent::LeftButtonDoubleClick:
        if (!PointInRect(x, y, &m_contentRect))
            return false;
        {
            const int itemIndex = HitTestItem(x, y);
            if (itemIndex == -1)
                return false;
            OnItemSelected(itemIndex, event->modifierFlags);
            OnItemActivated();
        }
        return true;

    case MouseEvent::LeftButtonUp:
        if (!m_dragSelectionActive)
            return false;
        if (PointInRect(x, y, &m_contentRect))
        {
            const int itemIndex = HitTestItem(x, y);
            if (itemIndex != -1)
                EnsureItemVisible(itemIndex);
        }
        m_dragSelectionActive = 0;
        g_pEventMan->ReleaseMouse();
        return true;

    default:
        return false;
    }
}

bool ListPane::OnKeyEvent(const PaneKeyEvent *event)
{
    const unsigned char key =
        g_pEventMan->TranslateEventKey(event->payload[0], event->keyState);

    switch (key)
    {
    case 0x80:
    case 0x81:
        SelectPreviousItem(event->keyState);
        return true;

    case 0x82:
    case 0x83:
        SelectNextItem(event->keyState);
        return true;

    default:
        return false;
    }
}

// 0x004f42ec and 0x004f43d0 are compiler switch tables for the
// two methods above; no standalone source object is emitted.

// UID:0003U3 | by-memory/0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry.md | Completion:92 | Confidence:93
void ListPane::OnPaint()
{
    SetDrawMode(0);
    SetDrawColor(0);
    FillRect(&m_contentRect);

    const int itemCount = GetItemCount();
    for (int itemIndex = 0; itemIndex < itemCount; ++itemIndex)
    {
        RectBounds itemBounds;
        RectBounds clippedBounds;
        GetItemRect(itemIndex, &itemBounds);
        if (IntersectRects(&itemBounds, &m_contentRect, &clippedBounds))
        {
            DrawListEntry(itemIndex, m_items->GetElementAt(itemIndex),
                          &itemBounds);
        }
    }
}

int ListPane::HitTestItem(int x, int y)
{
    if (x < m_scrollContentRect.left)
        x = m_scrollContentRect.left;
    else if (x >= m_scrollContentRect.right)
        x = m_scrollContentRect.right - 1;

    if (y < m_scrollContentRect.top)
        y = m_scrollContentRect.top;
    else if (y >= m_scrollContentRect.bottom)
        y = m_scrollContentRect.bottom - 1;

    const int itemCount = GetItemCount();
    for (int itemIndex = 0; itemIndex < itemCount; ++itemIndex)
    {
        RectBounds itemBounds;
        GetItemRect(itemIndex, &itemBounds);
        if (PointInRect(x, y, &itemBounds))
            return itemIndex;
    }
    return -1;
}

void ListPane::GetItemRect(int itemIndex, RectBounds *outBounds)
{
    InitRectBounds(outBounds, 0, 0, m_itemSize.x, m_itemSize.y);
    OffsetRect(outBounds,
               (itemIndex % m_columnCount) * m_itemSize.x,
               (itemIndex / m_columnCount) * m_itemSize.y);
    OffsetRect(outBounds, m_scrollContentRect.left,
               m_scrollContentRect.top);
}

// UID:0003U4 | by-memory/0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers.md | Completion:91 | Confidence:92
void ListPane::OnItemSelected(int itemIndex, int modifierFlags)
{
    RectBounds dirtyBounds;
    InitRectBounds(&dirtyBounds, 0, 0, 0, 0);

    unsigned char *selection =
        static_cast<unsigned char *>(m_selectionFlags->GetData());
    const int itemCount = m_selectionFlags->GetCount();

    if (itemIndex >= 0 && itemIndex < itemCount)
    {
        if (m_multipleSelectionEnabled && (modifierFlags & 4) != 0)
        {
            int first = m_selectedIndex < itemIndex ? m_selectedIndex : itemIndex;
            const int last = m_selectedIndex > itemIndex ? m_selectedIndex : itemIndex;
            if (first < 0)
                first = 0;
            for (int index = first; index <= last; ++index)
            {
                if (selection[index] == 0)
                {
                    RectBounds itemBounds;
                    GetItemRect(index, &itemBounds);
                    UnionRects(&itemBounds, &dirtyBounds, &dirtyBounds);
                    selection[index] = 1;
                }
            }
            m_selectedIndex = itemIndex;
        }
        else if (m_multipleSelectionEnabled && (modifierFlags & 2) != 0)
        {
            selection[itemIndex] = selection[itemIndex] == 0;
            GetItemRect(itemIndex, &dirtyBounds);
            m_selectedIndex = itemIndex;
        }
        else
        {
            for (int index = itemCount - 1; index >= 0; --index)
            {
                if (selection[index] != 0)
                {
                    RectBounds itemBounds;
                    GetItemRect(index, &itemBounds);
                    UnionRects(&itemBounds, &dirtyBounds, &dirtyBounds);
                    selection[index] = 0;
                }
            }
            if (selection[itemIndex] == 0)
            {
                RectBounds itemBounds;
                GetItemRect(itemIndex, &itemBounds);
                UnionRects(&itemBounds, &dirtyBounds, &dirtyBounds);
                selection[itemIndex] = 1;
            }
            m_selectedIndex = itemIndex;
        }
    }
    else
    {
        for (int index = itemCount - 1; index >= 0; --index)
        {
            if (selection[index] != 0)
            {
                RectBounds itemBounds;
                GetItemRect(index, &itemBounds);
                UnionRects(&itemBounds, &dirtyBounds, &dirtyBounds);
                selection[index] = 0;
            }
        }
        m_selectedIndex = -1;
    }

    RectBounds clippedBounds;
    if (IntersectRects(&m_scrollContentRect, &dirtyBounds, &clippedBounds))
        InvalidateRect(&clippedBounds);
}

void ListPane::SelectPreviousItem(unsigned char modifierFlags)
{
    const int itemCount = GetItemCount();
    int itemIndex;
    if (m_selectedIndex < 0 || m_selectedIndex >= itemCount)
        itemIndex = itemCount - 1;
    else
        itemIndex = m_selectedIndex > 0 ? m_selectedIndex - 1 : 0;

    if (itemIndex != -1)
    {
        EnsureItemVisible(itemIndex);
        OnItemSelected(itemIndex, modifierFlags);
    }
}

void ListPane::SelectNextItem(unsigned char modifierFlags)
{
    const int itemCount = GetItemCount();
    if (itemCount <= 0)
        return;

    int itemIndex;
    if (m_selectedIndex < 0 || m_selectedIndex >= itemCount)
        itemIndex = 0;
    else
        itemIndex = m_selectedIndex + 1 < itemCount
            ? m_selectedIndex + 1 : itemCount - 1;

    EnsureItemVisible(itemIndex);
    OnItemSelected(itemIndex, modifierFlags);
}

// 0x004f4820-0x004f487c is an unreferenced retained clamp/notify body:
// IDA has no function or xref, and PE has no VA/RVA/relative-branch route.
// Its behavior is already covered by SelectPreviousItem/SelectNextItem and
// EnsureItemVisible, so no speculative standalone member is emitted.
// 0x004f4910-0x004f4919 is a compiler frame shim that tail-jumps to
// SelectNextItem; no standalone source method is emitted.

// UID:0003U5 | by-memory/0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks.md | Completion:92 | Confidence:94
void ListPane::EnsureItemVisible(int itemIndex)
{
    if (m_verticalScrollPane == 0)
        return;

    RectBounds itemBounds;
    GetItemRect(itemIndex, &itemBounds);
    if (itemBounds.top >= m_contentRect.top)
    {
        if (itemBounds.bottom > m_contentRect.bottom)
        {
            const short current = GetScrollPosition(0);
            ApplyScrollPosition(
                0, current,
                static_cast<short>(
                    current +
                    (itemBounds.bottom - m_contentRect.bottom - 1) /
                        m_itemSize.y + 1));
        }
    }
    else
    {
        const short current = GetScrollPosition(0);
        ApplyScrollPosition(
            0, current,
            static_cast<short>(
                current -
                (m_contentRect.top - itemBounds.top - 1) / m_itemSize.y - 1));
    }
}

// 0x004f49e0 and 0x004f49eb are compiler-generated secondary/tertiary
// destructor adjustor thunks. 0x004f4a00 is the scalar deleting wrapper.
// The ordinary ListPane destructor is emitted by UID0003TZ; none of these
// wrappers has a separate source-level definition.

// UID:0003TZ | by-memory/0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md | Completion:91 | Confidence:93
ListPane::ListPane(
    int entrySize,
    int listWidth,
    short viewportHeight,
    short rowHeight,
    bool horizontalScrollEnabled,
    bool verticalScrollEnabled,
    signed char columnCount)
    : ScrollablePane(horizontalScrollEnabled,
                     verticalScrollEnabled),
      m_items(new List(entrySize, listWidth)),
      m_selectedIndex(-1),
      m_selectionFlags(new List(1, listWidth)),
      m_multipleSelectionEnabled(0),
      m_columnCount(columnCount),
      m_dragSelectionActive(0)
{
    m_itemSize.y = rowHeight;
    m_itemSize.x = viewportHeight;
    SetMode(1);
}

ListPane::~ListPane()
{
    delete m_items;
    delete m_selectionFlags;
}

// UID:0003OM | by-memory\0x0061ce84-0x0061cf44.ListPaneVtableData.md | Completion:85 | Confidence:90 | Empty Emitter Marker
