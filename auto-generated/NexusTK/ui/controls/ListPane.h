// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KT
// Source by-file doc: by-file/ListPane.md
// UID:00007A | by-class/ListPane.md | Completion:95 | Confidence:94
#ifndef NEXUSTK_UI_CONTROLS_LISTPANE_H
#define NEXUSTK_UI_CONTROLS_LISTPANE_H

#include "../core/ScrollBar.h"

class List;
class MouseEvent;
struct PaneKeyEvent;

class ListPane : public ScrollablePane
{
public:
    ListPane(int entrySize, int listWidth,
             short viewportHeight, short rowHeight,
             bool horizontalScrollEnabled,
             bool verticalScrollEnabled,
             signed char columnCount);
    virtual ~ListPane();

    // UID:000500 | by-memory/0x004f3bb0-0x004f3bcb.ListPaneGetItemSize.md | Completion:91 | Confidence:92
Point GetItemSize() const;

// UID:000501 | by-memory/0x004f3bd0-0x004f3bdf.ListPaneGetItemCount.md | Completion:92 | Confidence:94
int GetItemCount() const;

// UID:000502 | by-memory/0x004f3be0-0x004f3bfb.ListPaneGetRowCount.md | Completion:91 | Confidence:92
int GetRowCount() const;

// UID:000503 | by-memory/0x004f3c00-0x004f3c4b.ListPaneInsertItem.md | Completion:92 | Confidence:94
void InsertItem(int index, void *item);

// UID:000504 | by-memory/0x004f3c50-0x004f3ca4.ListPaneAddEntry.md | Completion:92 | Confidence:94
void AddEntry(void *item);

// UID:000505 | by-memory/0x004f3cb0-0x004f3cfd.ListPaneInsertItems.md | Completion:92 | Confidence:93
void InsertItems(int index, int count, void *items);

// UID:000506 | by-memory/0x004f3d00-0x004f3d56.ListPaneAddEntries.md | Completion:92 | Confidence:93
void AddEntries(int count, void *items);

// UID:000507 | by-memory/0x004f3d60-0x004f3db7.ListPaneRemoveItems.md | Completion:92 | Confidence:94
void RemoveItems(int index, int count);

// UID:000508 | by-memory/0x004f3dc0-0x004f3dcf.ListPaneGetItem.md | Completion:92 | Confidence:94
void *GetItem(int index);

// UID:0004LX | by-memory/0x004f3dd0-0x004f3e1c.ListPaneSetMultipleSelectionEnabled.md | Completion:92 | Confidence:94
void SetMultipleSelectionEnabled(unsigned char enabled);

// UID:0004M9 | by-memory/0x004f3e20-0x004f3e74.ListPaneGetSelectionCount.md | Completion:92 | Confidence:94
int GetSelectionCount() const;

// UID:000509 | by-memory/0x004f3e80-0x004f3ef7.ListPaneGetSelectedIndices.md | Completion:92 | Confidence:94
int GetSelectedIndices(int *indices, int maxCount) const;

// UID:00050A | by-memory/0x004f3f00-0x004f3f1b.ListPaneIsItemSelected.md | Completion:92 | Confidence:94
bool IsItemSelected(int index) const;

// UID:0003U1 | by-memory/0x004f3f20-0x004f4190.ListPaneScrollMetricVirtuals.md | Completion:93 | Confidence:94
virtual short GetScrollRange(char axis);
virtual short GetOverflowCount(char axis);
virtual short GetPageSize(char axis);
virtual short GetScrollOffset(char axis, short units);
virtual Point *GetContentSize(Point *outSize);
virtual Point *GetScrollDelta(Point *outDelta, char axis,
                              short oldPosition, short newPosition);

// UID:0003U2 | by-memory/0x004f4190-0x004f43e0.ListPaneInputKeyHandlersAndSwitchTables.md | Completion:92 | Confidence:93
virtual bool OnMouseEvent(MouseEvent *event);
virtual bool OnKeyEvent(const PaneKeyEvent *event);

// UID:0003U3 | by-memory/0x004f43e0-0x004f45b0.ListPanePaintHitTestGeometry.md | Completion:92 | Confidence:93
virtual void OnPaint();
int HitTestItem(int x, int y);

// UID:0003U4 | by-memory/0x004f45b0-0x004f4920.ListPaneSelectionNavigationRawClampHelpers.md | Completion:91 | Confidence:92
void SelectPreviousItem(unsigned char modifierFlags);
void SelectNextItem(unsigned char modifierFlags);

// UID:0003U5 | by-memory/0x004f4920-0x004f4a77.ListPaneEnsureVisibleDestructorThunks.md | Completion:92 | Confidence:94
void EnsureItemVisible(int itemIndex);

protected:
    virtual void OnListAction() {}
    virtual void GetItemRect(int rowIndex, RectBounds *outBounds);
    virtual void OnItemSelected(int rowIndex, int notify);
    virtual void OnItemActivated() {}
    virtual void DrawListEntry(int rowIndex, void *rowData,
                               RectBounds *rowBounds) {}

    List *m_items;
    int m_selectedIndex;
    List *m_selectionFlags;
    unsigned char m_multipleSelectionEnabled;
    Point m_itemSize;
    signed char m_columnCount;
    unsigned char m_dragSelectionActive;
};

typedef char ListPaneSizeMustBe332[
    sizeof(ListPane) == 0x14c ? 1 : -1];

#endif
