// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LS
// Source by-file doc: by-file/NewInventoryPane.md
// UID:000093 | by-class/NewInventoryPane.md | Completion:94 | Confidence:95
#ifndef NEXUSTK_UI_INVENTORY_NEWINVENTORYPANE_H
#define NEXUSTK_UI_INVENTORY_NEWINVENTORYPANE_H

#include "../core/PanelPane.h"

class Event;
class Layer;
class ScrollInventoryPane;

class NewInventoryPane : public PanelPane
{
public:
    NewInventoryPane();
    virtual ~NewInventoryPane();

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void SetBounds(RectBounds *bounds,
                           const RectBounds *previousBounds);
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
    enum InventoryViewMode
    {
        kInventoryViewList = 0,
        kInventoryViewGrid = 1
    };

    void RebuildInventoryList();
    static void __stdcall SendUseItemSlotPacket(unsigned char slot);
    static void __stdcall SendDropItemPacket(unsigned char slot);
    static void __stdcall SendItemToObjectPacket(
        unsigned char slot, unsigned int objectId);
    bool BuildInventorySlotRect(int cell, RectBounds *bounds) const;
    int HitTestInventorySlot(int localX, int localY) const;
    int ResolveVisibleInventorySlot(short visibleOrdinal) const;
    static void __stdcall SendSwapItemPacket(
        signed char destinationSlot, signed char sourceSlot);
    Point *BuildInventorySlotOrigin(Point *origin,
                                    unsigned short cell) const;
    void StopActiveRepeatTimer();
    void ToggleExpandedMode();

    signed char m_scrollPosition;
    unsigned char m_inventoryListCount;
    unsigned char m_reservedFA[2];
    InventoryViewMode m_viewMode;
    int m_unusedState;
    int m_listButtonState;
    int m_gridButtonState;
    int m_expandButtonState;
    int m_actionButtonState;
    ScrollInventoryPane *m_scrollPane;
    unsigned char m_visibleInventorySlots[53];
    signed char m_hoverInventorySlot;
    signed char m_selectedInventorySlot;
    unsigned char m_reserved14F;
    int m_activeRepeatTimer;
    bool m_draggedSincePress;
    bool m_expanded;
    unsigned char m_tailPadding[2];
};

typedef char NewInventoryPane_size_must_be_0x158[
    sizeof(NewInventoryPane) == 0x158 ? 1 : -1];

#endif
