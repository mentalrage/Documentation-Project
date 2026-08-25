// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JU
// Source by-file doc: by-file/HelpPanes.md
// UID:0000D6 | by-class/SimpleHelpPane.md | Completion:92 | Confidence:94
#ifndef NEXUSTK_UI_CONTROLS_HELPPANES_H
#define NEXUSTK_UI_CONTROLS_HELPPANES_H

#include "../core/Pane.h"
#include "../../util/Singleton.h"

class SimpleHelpPane : public Pane,
                       public Singleton<SimpleHelpPane>
{
public:
    SimpleHelpPane(const wchar_t *text,
                   Pane *owner,
                   int x,
                   int y,
                   int timeoutMs);
    virtual ~SimpleHelpPane();

    void Close(bool immediate);

protected:
    virtual void OnPaintFrame();
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    wchar_t *m_textBuffer;
};

#endif

// UID:00006U | by-class/ItemHelpPane.md | Completion:92 | Confidence:94
class ItemHelpPane : public Pane,
                     public Singleton<ItemHelpPane>
{
public:
    ItemHelpPane(const wchar_t *itemKey,
                 Pane *owner,
                 int x,
                 int y,
                 int timeoutMs,
                 const wchar_t *displayName,
                 int currentDurability,
                 unsigned char protectionCount);
    virtual ~ItemHelpPane();

protected:
    virtual void OnPaintFrame();
    virtual bool OnTimer(int timerId, int arg0, int arg1);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    void PopulateItemData(const wchar_t *itemKey);
    short CountTextLines(const wchar_t *text, short textLength, int width);

    int m_contentWidth;
    int m_lineCount;
    bool m_isEquipmentItem;
    bool m_hasItemInstanceState;
    int m_currentDurability;
    wchar_t m_itemMetaKey[64];
    wchar_t m_itemDisplayName[64];
    wchar_t m_ownerName[64];
    wchar_t m_helpDescription[64];
    int m_protectionCount;
    wchar_t m_statLabels[20][20];
    wchar_t **m_statValueTextBuffers;
};

extern ItemHelpPane *g_pItemHelpPane;

// UID:0000G5 | by-class/WillBeChangedItemPane.md | Completion:92 | Confidence:94
class Event;
struct LocalInventorySlotRecord;

class WillBeChangedItemPane : public Pane,
                              public Singleton<WillBeChangedItemPane>
{
public:
    WillBeChangedItemPane(Pane *owner,
                          char inventorySlot,
                          int y,
                          int x,
                          int pointerY,
                          int pointerX,
                          bool compactDisplay);
    virtual ~WillBeChangedItemPane();

protected:
    virtual void OnPaintFrame();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    LocalInventorySlotRecord *m_inventorySlotRecord;
    char m_inventorySlot;
    bool m_compactDisplay;
    int m_initialPointerY;
    int m_initialPointerX;
    int m_drawY;
    int m_drawX;
};

typedef char WillBeChangedItemPaneSizeMustBe272[
    sizeof(WillBeChangedItemPane) == 0x110 ? 1 : -1];

extern WillBeChangedItemPane *g_pWillBeChangedItemPane;

// UID:0000G6 | by-class/WillBeChangedSpellPane.md | Completion:92 | Confidence:94
class Event;
struct SpellCommandSlotRecord;

class WillBeChangedSpellPane : public Pane
{
public:
    WillBeChangedSpellPane(Pane *owner,
                           char spellSlot,
                           int y,
                           int x,
                           int pointerY,
                           int pointerX);
    virtual ~WillBeChangedSpellPane();

protected:
    virtual void OnPaintFrame();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    SpellCommandSlotRecord *m_spellRecord;
    char m_spellSlot;
    int m_initialPointerY;
    int m_initialPointerX;
    int m_drawY;
    int m_drawX;
};

typedef char WillBeChangedSpellPaneSizeMustBe272[
    sizeof(WillBeChangedSpellPane) == 0x110 ? 1 : -1];

// UID:0000S9 | by-global/g_pSimpleHelpPane.md | Completion:87 | Confidence:90
extern SimpleHelpPane *g_pSimpleHelpPane;
