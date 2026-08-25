// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KA
// Source by-file doc: by-file/InventoryPane.md
// UID:00006R | by-class/InventoryPane.md | Completion:93 | Confidence:94
#ifndef NEXUSTK_UI_INVENTORY_INVENTORYPANE_H
#define NEXUSTK_UI_INVENTORY_INVENTORYPANE_H

#include "../core/PanelPane.h"
#include "../core/Event.h"
#include "../core/RectBounds.h"

class InterfaceEfx;

class InventoryPane : public PanelPane
{
public:
    InventoryPane();
    virtual ~InventoryPane();

    virtual void OnActivate(const unsigned char *packetData);
    virtual void OnPaint();
    virtual bool OnKeyEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
    virtual bool OnServerMessage(Event *message);

private:
    void PlayItemEffect();
    static void GetButtonRect(int button, RectBounds *rect);
    void GetSlotRect(short slot, RectBounds *bounds) const;
    static int HitTestButton(int x, int y);
    int HitTestSlot(int x, int y) const;
    static int VisibleOrdinalToInventorySlot(int ordinal);

    unsigned char m_pageIndex;
    bool m_isLastPage;
    unsigned char m_reservedFA[2];
    int m_viewMode;
    InterfaceEfx *m_itemEffect;
};

// UID:00006S | by-class/InventoryPane2.md | Completion:94 | Confidence:94
class InventoryPane2 : public PanelPane
{
public:
    InventoryPane2();
    virtual ~InventoryPane2();

    virtual void OnActivate(const unsigned char *packetData);
    virtual void OnPaint();
    virtual bool OnKeyEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
    virtual bool OnServerMessage(Event *message);

private:
    void PlayItemEffect();
    void SendUseItemSlotPacketRaw(unsigned char slot);
    void SendDragDropItemPacketRaw(unsigned char slot, unsigned char dragSource);
    void GetButtonRect(short button, RectBounds *rect) const;
    void GetSlotRect(short slot, RectBounds *rect) const;
    short HitTestButton(int y, int x) const;
    int HitTestSlot(int x, int y) const;
    static int VisibleOrdinalToInventorySlot(int ordinal);

    unsigned char m_pageIndex;
    bool m_isLastPage;
    unsigned char m_reservedFA[2];
    int m_viewMode;
    int m_unusedState;
    int m_listButtonState;
    int m_gridButtonState;
};

#endif
