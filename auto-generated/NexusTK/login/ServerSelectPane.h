// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NO
// Source by-file doc: by-file/ServerSelectPane.md
// UID:0000S8 | by-global/g_pServerSelectPane.md | Completion:92 | Confidence:94
class ServerSelectPane;

extern ServerSelectPane *g_pServerSelectPane;

// UID:0000D2 | by-class/ServerSelectPane.md | Completion:93 | Confidence:95
#pragma once

#include "../ui/core/DialogPane.h"
#include "../util/Singleton.h"

struct ServerSelectDirectory;
class ServerSelectMenuItemList;

class ServerSelectPane : public DialogPane,
                         public Singleton<ServerSelectPane>
{
public:
    ServerSelectPane(ServerSelectDirectory *serverDirectory);

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();

private:
    friend class ServerSelectMenuItemList;

    ServerSelectDirectory *m_serverDirectory;
};

// UID:0000D1 | by-class/ServerSelectMenuItemList.md | Completion:93 | Confidence:95
#include "../config/Config.h"
#include "../ui/controls/ListPane.h"

class ServerSelectPane;

class ServerSelectMenuItemList : public ListPane
{
public:
    ServerSelectMenuItemList(ServerSelectPane *owner);

    void AddServerEntry(ServerSelectEntry *entry);
    void ApplySelectedServer();
    void SelectServerEntryIndex(int index);
    void ApplyServerEntry(const ServerSelectEntry *entry);

protected:
    virtual void OnItemActivated();
    virtual void DrawListEntry(int rowIndex, void *rowData,
                               RectBounds *rowBounds);

private:
    void SendServerSelectPacket(unsigned int serverId,
                                const ServerSelectEntry *entry);

    ServerSelectPane *m_owner;
};

typedef char ServerSelectEntrySizeMustBe24[
    sizeof(ServerSelectEntry) == 0x18 ? 1 : -1];
typedef char ServerSelectMenuItemListSizeMustBe336[
    sizeof(ServerSelectMenuItemList) == 0x150 ? 1 : -1];
