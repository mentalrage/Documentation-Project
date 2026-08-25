// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NJ
// Source by-file doc: by-file/ScrollSpellInventoryPane.md
// UID:0000CN | by-class/ScrollSpellInventoryPane.md | Completion:89 | Confidence:91
#ifndef NEXUSTK_UI_INVENTORY_SCROLLSPELLINVENTORYPANE_H
#define NEXUSTK_UI_INVENTORY_SCROLLSPELLINVENTORYPANE_H

#include "../core/Pane.h"

class Event;
class NewSpellInventoryPane;

enum ScrollSpellInventoryPart {
    kScrollSpellInventoryPartLeading = 0,
    kScrollSpellInventoryPartPageBeforeThumb = 1,
    kScrollSpellInventoryPartThumb = 2,
    kScrollSpellInventoryPartPageAfterThumb = 3,
    kScrollSpellInventoryPartTrailing = 4,
    kScrollSpellInventoryPartNone = -1
};

class ScrollSpellInventoryPane : public Pane
{
public:
    explicit ScrollSpellInventoryPane(unsigned char orientation);

    void SetSizeIndex(unsigned short sizeIndex);
    void SetScrollStyle(unsigned char scrollStyle);
    void SetMaxRange(short maxRange);
    void SetScrollPosition(short position);
    void Activate();
    void Deactivate();
    bool CanScroll() const;

protected:
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual void OnPaint();

private:
    friend class NewSpellInventoryPane;

    ScrollSpellInventoryPart HitTestPart(int localY, int localX);
    void GetPartRect(ScrollSpellInventoryPart part, RectBounds *bounds);
    void SetHoverPart(ScrollSpellInventoryPart part);
    void BeginInteraction(ScrollSpellInventoryPart part,
                          int mouseY,
                          int mouseX);
    void UpdateDragScroll();
    void UpdateFromDrag(int localY, int localX);
    void ResetScrollState();

    unsigned short m_sizeIndex;
    unsigned char m_scrollStyle;
    bool m_thumbDragActive;
    unsigned char m_orientation;
    short m_scrollPosition;
    short m_scrollRange;
    bool m_enabled;
    signed char m_hoverPart;
    signed char m_activePart;
    Point m_thumbDragOffset;
};

typedef char ScrollSpellInventoryPaneSizeMustBe272[
    sizeof(ScrollSpellInventoryPane) == 0x110 ? 1 : -1];

#endif
