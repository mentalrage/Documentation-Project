// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O2
// Source by-file doc: by-file/SpellMenuDialogs.md
// UID:0000D3 | by-class/ServerSpellMenuDialog.md | Completion:90 | Confidence:91
#pragma once

#include "MerchantDialogPane.h"
#include "../controls/ListPane.h"

class DrawContext;
struct Rect;

class ServerSpellMenuDialog : public MerchantDialogPane
{
public:
    ServerSpellMenuDialog(const RectBounds& bounds,
                          const unsigned char *payload,
                          unsigned char menuMode);

protected:
    void HandleMenuCommand(int commandId, void *context);
    void UpdateActionButtonState();

private:
    unsigned char m_packetSubtype;        // +0x274
    unsigned char m_reserved275[3];       // +0x275..+0x277
};

typedef char ServerSpellMenuDialogSizeMustBe632[
    (sizeof(ServerSpellMenuDialog) == 0x278) ? 1 : -1];

// UID:0000D4 | by-class/ServerSpellMenuItemList.md | Completion:90 | Confidence:91
struct ServerSpellMenuEntry;

class ServerSpellMenuItemList : public ListPane
{
public:
    ServerSpellMenuItemList(unsigned char packetSubtype,
                            unsigned int menuObjectId,
                            unsigned short menuOptionId,
                            ServerSpellMenuDialog *owner);

    void AppendSpellName(unsigned short reserved, const wchar_t *name);
    bool SendSelectedSpellName();
    bool SendSpellName(const wchar_t *name);

    virtual void NotifyOwnerSpellActivated();
    virtual void DrawListEntry(DrawContext *dc,
                               int index,
                               const ServerSpellMenuEntry *entry,
                               const Rect& bounds);

private:
    unsigned char m_packetSubtype;
    unsigned char m_reserved14d[3];
    unsigned int m_menuObjectId;
    unsigned short m_menuOptionId;
    unsigned short m_reserved156;
    ServerSpellMenuDialog *m_owner;
};

// UID:00002R | by-class/ClientSpellMenuDialog.md | Completion:90 | Confidence:91
#pragma once

#include "MerchantDialogPane.h"

class ClientSpellMenuDialog : public MerchantDialogPane
{
public:
    ClientSpellMenuDialog(const RectBounds& bounds,
                          const unsigned char *payload,
                          unsigned char menuMode);

protected:
    void HandleMenuCommand(int commandId, void *context);
    void UpdateActionButtonState();

private:
    unsigned char m_packetSubtype;        // +0x274
    unsigned char m_reserved275[3];       // +0x275..+0x277
};

typedef char ClientSpellMenuDialogSizeMustBe632[
    (sizeof(ClientSpellMenuDialog) == 0x278) ? 1 : -1];

// UID:00002S | by-class/ClientSpellMenuItemList.md | Completion:90 | Confidence:91
struct ClientSpellMenuEntry;

class ClientSpellMenuItemList : public ListPane
{
public:
    ClientSpellMenuItemList(unsigned char packetSubtype,
                            unsigned int menuObjectId,
                            unsigned short menuOptionId,
                            ClientSpellMenuDialog *owner);

    void AppendSpell(unsigned char spellSlot,
                     unsigned short reserved,
                     const wchar_t *name);
    bool SendSelectedSpell();
    bool SendSpell(unsigned char spellSlot);

    virtual void NotifyOwnerSpellActivated();
    virtual void DrawListEntry(DrawContext *dc,
                               int index,
                               const ClientSpellMenuEntry *entry,
                               const Rect& bounds);

private:
    unsigned char m_packetSubtype;
    unsigned char m_reserved14d[3];
    unsigned int m_menuObjectId;
    unsigned short m_menuOptionId;
    unsigned short m_reserved156;
    ClientSpellMenuDialog *m_owner;
};
