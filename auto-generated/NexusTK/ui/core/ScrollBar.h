// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NF
// Source by-file doc: by-file/ScrollBar.md
// UID:0000CM | by-class/ScrollPane.md | Completion:87 | Confidence:88
#ifndef NEXUSTK_UI_CORE_SCROLLBAR_H
#define NEXUSTK_UI_CORE_SCROLLBAR_H

#include "Pane.h"
#include "RectBounds.h"

struct PaneMouseEvent;

typedef signed char ScrollPanePart;

static const ScrollPanePart kScrollPanePartNone = -1;
static const ScrollPanePart kScrollPanePartFirstButton = 0;
static const ScrollPanePart kScrollPanePartPageBeforeThumb = 1;
static const ScrollPanePart kScrollPanePartThumb = 2;
static const ScrollPanePart kScrollPanePartPageAfterThumb = 3;
static const ScrollPanePart kScrollPanePartSecondButton = 4;

class ScrollPane : public Pane
{
public:
    explicit ScrollPane(bool horizontal);
    void SetSkinIndex(unsigned short skinIndex);
    void SetScrollStyle(unsigned char scrollStyle)
    {
        if (m_scrollStyle == scrollStyle)
            return;

        m_scrollStyle = scrollStyle;
        InvalidateRect(&m_visibleBounds);
    }
    bool IsScrollThumbVisible();

protected:
    virtual bool OnMouseEvent(const PaneMouseEvent& event);
    virtual bool CanScroll(int value);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnDraw();

private:
    ScrollPanePart HitTestPart(int localY, int localX);
    void GetScrollPartRect(ScrollPanePart part, RectBounds *outRect);
    void SetHighlightedPart(ScrollPanePart part);
    void BeginPartPress(ScrollPanePart part, int localY, int localX);
    void ProcessActivePart();
    void UpdatePositionFromCursor(int localY, int localX);
    void ResetScrollState();

    unsigned short m_scrollSkinIndex;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_orientation;
    short m_scrollPosition;
    short m_scrollRange;
    bool m_enabled;
    ScrollPanePart m_highlightPart;
    ScrollPanePart m_activePart;
    Point m_thumbDragOffset;
};

// UID:0000CF | by-class/ScrollablePane.md | Completion:93 | Confidence:94
class ScrollablePane : public Pane
{
public:
    ScrollablePane(bool horizontalScrollEnabled,
                   bool verticalScrollEnabled);
    virtual ~ScrollablePane();

    virtual short GetScrollRange(char axis);
    virtual short GetOverflowCount(char axis);
    virtual short GetPageSize(char axis);
    virtual short GetScrollOffset(char axis, short units);
    virtual Point *GetContentSize(Point *outSize);
    virtual Point *GetScrollDelta(Point *outDelta, char axis,
                                  short oldPosition, short newPosition);

    void SetSkinIndex(unsigned short skinIndex);
    void SetScrollbarsVisible(bool visible);
    void SetScrollTargetValue(short targetPosition, char axis);
    void SetScrollCurrentValue(short currentPosition, char axis);
    short GetScrollMax(char axis) const;
    short GetScrollPosition(char axis) const;
    void SyncScrollbars();
    void ApplyScrollPosition(char axis, unsigned short oldPosition,
                             unsigned short targetPosition);
    void LayoutScrollbars();

protected:
    ScrollPane *m_horizontalScrollPane;
    ScrollPane *m_verticalScrollPane;
    int m_horizontalScrollBarOffset;
    int m_verticalScrollBarOffset;
    int m_scrollBarInset;
    bool m_horizontalScrollEnabled;
    bool m_verticalScrollEnabled;
    RectBounds m_contentRect;
    RectBounds m_scrollContentRect;
};

typedef char ScrollablePaneSizeMustBe304[
    sizeof(ScrollablePane) == 0x130 ? 1 : -1];

#endif

// UID:0003CQ | by-memory/0x00624138-0x00624168.ScrollPaneScrollbarConstantData.md | Completion:92 | Confidence:93
extern const int kScrollPanePartExtentBySkin[3];
