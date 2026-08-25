// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LU
// Source by-file doc: by-file/NewSpellInventoryPane.md
// UID:00009A | by-class/NewSpellInventoryPane.md | Completion:94 | Confidence:95
#ifndef NEXUSTK_UI_INVENTORY_NEWSPELLINVENTORYPANE_H
#define NEXUSTK_UI_INVENTORY_NEWSPELLINVENTORYPANE_H

#include "../core/PanelPane.h"

class Event;
class Layer;
class ScrollSpellInventoryPane;

class NewSpellInventoryPane : public PanelPane
{
public:
    NewSpellInventoryPane();
    virtual ~NewSpellInventoryPane();

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void SetBounds(RectBounds *bounds, const RectBounds *parentBounds);
    virtual void AddToLayer(const RectBounds *bounds, int order,
                            Pane *previousPane, Layer *layer);
    virtual void RemoveFromLayer();
    virtual void OnPaint();
    virtual void OnActivate(const unsigned char *activationData);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool OnTimer(int timerId, int elapsed, int userData);

    void OnScrollPositionChanged(unsigned char orientation,
                                 short oldPosition, short newPosition);

private:
    void RebuildSpellList();
    void ActivateSpellSlot(int spellSlot);
    bool BuildSpellRowRect(int row, RectBounds *bounds) const;
    int HitTestSpellRow(int localX, int localY) const;
    int ResolveVisibleSpellSlot(short visibleOrdinal) const;
    void BuildSpellRowOrigin(Point *origin, int row) const;
    void StopActiveRepeatTimer();
    void ToggleExpandedMode();

    signed char m_scrollPosition;
    unsigned char m_spellListCount;
    bool m_spellInputActive;
    unsigned char m_reservedFB[5];
    ScrollSpellInventoryPane *m_scrollPane;
    unsigned char m_visibleSpellSlots[53];
    signed char m_hoverSpellSlot;
    signed char m_selectedSpellSlot;
    unsigned char m_reserved13B;
    int m_activeRepeatTimer;
    int m_expandButtonState;
    bool m_expanded;
    bool m_draggedSincePress;
    unsigned char m_tailPadding[2];
};

typedef char NewSpellInventoryPane_size_must_be_0x148[
    sizeof(NewSpellInventoryPane) == 0x148 ? 1 : -1];

#endif
