// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OH
// Source by-file doc: by-file/TargetSelectionInputPanes.md
// UID:0001L9 | by-memory/0x005af4f0-0x005af57b.SendTargetedActionPacket.md | Completion:88 | Confidence:90
#ifndef NEXUSTK_UI_DIALOGS_TARGETSELECTIONINPUTPANES_H
#define NEXUSTK_UI_DIALOGS_TARGETSELECTIONINPUTPANES_H

int SendTargetedActionPacket(unsigned char action, unsigned int objectId,
    unsigned short argument1, unsigned short argument2);

// UID:0000DM | by-class/SpellInputPaneState.md | Completion:87 | Confidence:90
class SpellInputPaneState
{
public:
    void SetInputModeFlag(bool active);

private:
    unsigned char m_opaquePrefix[0xfa];
    bool m_spellInputActive;
};

// UID:0000DX | by-class/SpellWhoInputPane.md | Completion:87 | Confidence:88
#include "InputPanes.h"

class KeyEvent;
class MouseEvent;
class PacketEvent;

class SpellWhoInputPane : public LineInputPane
{
public:
    explicit SpellWhoInputPane(char spellIndex);
    virtual ~SpellWhoInputPane();

protected:
    virtual bool OnKeyEvent(KeyEvent *event);
    virtual bool OnMouseEvent(MouseEvent *event);
    virtual bool OnObjectListMessage(const PacketEvent *event);

private:
    char m_spellIndex;
};

#endif // NEXUSTK_UI_DIALOGS_TARGETSELECTIONINPUTPANES_H
