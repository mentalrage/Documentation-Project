// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NG
// Source by-file doc: by-file/ScrollCollectionPane.md
// UID:0000CG | by-class/ScrollCollectionPane.md | Completion:93 | Confidence:93
#pragma once

#include "Pane.h"

class CollectionPane;
class Event;
struct RectBounds;

enum ScrollCollectionPart
{
    kScrollCollectionPartLeading = 0,
    kScrollCollectionPartPageBeforeThumb = 1,
    kScrollCollectionPartThumb = 2,
    kScrollCollectionPartPageAfterThumb = 3,
    kScrollCollectionPartTrailing = 4,
    kScrollCollectionPartNone = -1
};

class ScrollCollectionPane : public Pane
{
public:
    explicit ScrollCollectionPane(unsigned char orientation);

    void SetSkinIndex(unsigned short skinIndex);
    void SetScrollStyle(unsigned char scrollStyle);
    void SetMaxRange(short maxRange);
    void SetScrollPosition(short position);
    void Enable();
    void Disable();
    bool CanScroll() const;

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnPaint();

private:
    friend class CollectionPane;

    ScrollCollectionPart HitTestScrollRegion(int localY, int localX);
    void GetPartRect(ScrollCollectionPart part, RectBounds *bounds);
    void SetHighlightedPart(ScrollCollectionPart part);
    void BeginPartInteraction(ScrollCollectionPart part,
                              int mouseY,
                              int mouseX);
    void UpdateDragScroll();
    void UpdatePositionFromCursor(int localY, int localX);
    void ResetScrollState();

    unsigned short m_scrollSkinIndex;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_orientation;
    short m_scrollPosition;
    short m_scrollRange;
    bool m_scrollEnabled;
    signed char m_highlightPart;
    signed char m_activePart;
    Point m_thumbDragOffset;
};

[[No Children Attached]]
