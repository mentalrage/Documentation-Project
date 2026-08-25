// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O1
// Source by-file doc: by-file/SpellInventoryPane.md
// UID:0000DN | by-class/SpellInventoryPane.md | Completion:93 | Confidence:94
#ifndef NEXUSTK_UI_INVENTORY_SPELLINVENTORYPANE_H
#define NEXUSTK_UI_INVENTORY_SPELLINVENTORYPANE_H

#include "../core/PanelPane.h"
#include "../core/Event.h"
#include "../core/RectBounds.h"

class InterfaceEfx;

class SpellInventoryPane : public PanelPane
{
public:
    SpellInventoryPane();
    virtual ~SpellInventoryPane();

    virtual void OnActivate(const unsigned char *activationData);
    virtual void OnPaint();
    virtual bool OnKeyEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
    virtual bool OnServerMessage(Event *event);

private:
    void PlaySpellEffect();
    void ActivateSpellSlot(unsigned char spellSlot);
    void SendDirectSpellPacket(unsigned char spellSlot);
    static void __stdcall BuildPageButtonRect(short button, RectBounds *bounds);
    static void __stdcall BuildSpellRowRect(short row, RectBounds *bounds);
    static short __stdcall HitTestPageButton(int y, int x);
    static short __stdcall HitTestSpellRow(int y, int x);
    static int __stdcall VisibleOrdinalToSpellSlot(short visibleOrdinal);

    unsigned char m_pageIndex;
    bool m_isLastPage;
    bool m_spellInputActive;
    unsigned char m_reservedFB;
    InterfaceEfx *m_spellEffect;
};

typedef char SpellInventoryPane_size_must_be_0x100[
    sizeof(SpellInventoryPane) == 0x100 ? 1 : -1];

// UID:0000DO | by-class/SpellInventoryPane2.md | Completion:93 | Confidence:94
class SpellInventoryPane2 : public PanelPane
{
public:
    SpellInventoryPane2();
    virtual ~SpellInventoryPane2();

    virtual void OnActivate(const unsigned char *activationData);
    virtual void OnPaint();
    virtual bool OnKeyEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
    virtual bool OnServerMessage(Event *event);

private:
    void SetSpellInputActive(bool active);
    void ActivateSpellSlot(unsigned char spellSlot);
    void SendDirectSpellPacket(unsigned char spellSlot);
    static void __stdcall BuildPageButtonRect(short button, RectBounds *bounds);
    static void __stdcall BuildSpellRowRect(short row, RectBounds *bounds);
    static short __stdcall HitTestPageButton(int y, int x);
    static short __stdcall HitTestSpellRow(int y, int x);
    static int __stdcall VisibleOrdinalToSpellSlot(short visibleOrdinal);

    unsigned char m_pageIndex;
    bool m_isLastPage;
    bool m_spellInputActive;
    unsigned char m_reservedFB[5];
};

typedef char SpellInventoryPane2_size_must_be_0x100[
    sizeof(SpellInventoryPane2) == 0x100 ? 1 : -1];

#endif
