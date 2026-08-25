// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O0
// Source by-file doc: by-file/SpellInputPanes.md
// UID:0000DL | by-class/SpellFourArgsInputPane.md | Completion:91 | Confidence:94
#ifndef NEXUSTK_UI_DIALOGS_SPELLINPUTPANES_H
#define NEXUSTK_UI_DIALOGS_SPELLINPUTPANES_H

#include "InputPanes.h"

class SpellFourArgsInputPane : public NumberArgsInputPane
{
public:
    explicit SpellFourArgsInputPane(char spellIndex);
    virtual ~SpellFourArgsInputPane();

protected:
    virtual void OnConfirmInput();

private:
    char m_spellIndex;
};

// UID:0000DR | by-class/SpellOneArgInputPane.md | Completion:91 | Confidence:94
class SpellOneArgInputPane : public NumberArgsInputPane
{
public:
    explicit SpellOneArgInputPane(char spellIndex);
    virtual ~SpellOneArgInputPane();

protected:
    virtual void OnSubmitInput();

private:
    char m_spellIndex;
};

// UID:0000DS | by-class/SpellSlotInputPane.md | Completion:93 | Confidence:94
#include "InputPanes.h"

class Event;

class SpellSlotInputPane : public CharInputPane
{
public:
    explicit SpellSlotInputPane(char spellIndex);
    virtual ~SpellSlotInputPane();

    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void SubmitSpellSlot();

private:
    void SendSpellUsePacket(char inventorySlot);

    char m_spellIndex;
};

// UID:0000DU | by-class/SpellStringInputPane.md | Completion:89 | Confidence:92
class SpellStringInputPane : public LineInputPane
{
public:
    explicit SpellStringInputPane(char spellIndex);
    virtual ~SpellStringInputPane();

protected:
    virtual void OnConfirmInput();

private:
    char m_spellIndex;
};

// UID:0000DV | by-class/SpellThreeArgsInputPane.md | Completion:91 | Confidence:94
class SpellThreeArgsInputPane : public NumberArgsInputPane
{
public:
    explicit SpellThreeArgsInputPane(char spellIndex);
    virtual ~SpellThreeArgsInputPane();

protected:
    virtual void OnConfirmInput();

private:
    char m_spellIndex;
};

// UID:0000DW | by-class/SpellTwoArgsInputPane.md | Completion:91 | Confidence:94
class SpellTwoArgsInputPane : public NumberArgsInputPane
{
public:
    explicit SpellTwoArgsInputPane(char spellIndex);
    virtual ~SpellTwoArgsInputPane();

protected:
    virtual void OnConfirmInput();

private:
    char m_spellIndex;
};

#endif // NEXUSTK_UI_DIALOGS_SPELLINPUTPANES_H
