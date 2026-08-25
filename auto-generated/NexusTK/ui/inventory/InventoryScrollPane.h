// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KB
// Source by-file doc: by-file/InventoryScrollPane.md
// UID:0000CK | by-class/ScrollInventoryPane.md | Completion:90 | Confidence:93
#pragma once

#include "../core/Pane.h"

class NewInventoryPane;
class Event;
struct RectBounds;

enum ScrollInventoryPart
{
    kScrollInventoryPartLeading = 0,
    kScrollInventoryPartPageBeforeThumb = 1,
    kScrollInventoryPartThumb = 2,
    kScrollInventoryPartPageAfterThumb = 3,
    kScrollInventoryPartTrailing = 4,
    kScrollInventoryPartNone = -1
};

class ScrollInventoryPane : public Pane
{
public:
    explicit ScrollInventoryPane(unsigned char orientation);

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
    friend class NewInventoryPane;

    ScrollInventoryPart HitTestScrollRegion(int localY, int localX);
    void GetPartRect(ScrollInventoryPart part, RectBounds *bounds);
    void SetHighlightedPart(ScrollInventoryPart part);
    void BeginPartInteraction(ScrollInventoryPart part,
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
