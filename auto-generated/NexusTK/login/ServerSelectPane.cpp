// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NO
// Source by-file doc: by-file/ServerSelectPane.md
// UID:0000S8 | by-global/g_pServerSelectPane.md | Completion:92 | Confidence:94
class ServerSelectPane;

ServerSelectPane *g_pServerSelectPane = NULL;

// UID:0000D2 | by-class/ServerSelectPane.md | Completion:93 | Confidence:95
#include "ServerSelectPane.h"

// UID:0003D7 | by-memory/0x00624d24-0x00624dc0.ServerSelectPaneVtableData.md | Completion:94 | Confidence:98
// ServerSelectPane vtables and RTTI are compiler-generated from the class
// declaration and virtual methods. Do not hand-author the
// 0x00624d24-0x00624dc0 locator or table dwords as C++.

// UID:0000D1 | by-class/ServerSelectMenuItemList.md | Completion:93 | Confidence:95
#include "../app/Application.h"
#include "../app/StartupWindow.h"
#include "../network/PacketBuffer.h"
#include "../network/Socket.h"
#include "../render/Surface.h"

#include <wchar.h>

ServerSelectMenuItemList::ServerSelectMenuItemList(ServerSelectPane *owner)
    : ListPane(sizeof(ServerSelectEntry *), 16, 303, 14,
               g_useEpfAssets != 1, true, 1),
      m_owner(owner)
{
}

void ServerSelectMenuItemList::AddServerEntry(ServerSelectEntry *entry)
{
    AddEntry(&entry);
}

void ServerSelectMenuItemList::ApplySelectedServer()
{
    if (m_selectedIndex == -1)
        return;

    ServerSelectEntry *entry =
        *static_cast<ServerSelectEntry **>(GetItem(m_selectedIndex));

    wcscpy_s(g_pConfig->m_lastServerName, 16, entry->name);
    SendServerSelectPacket(entry->serverId, entry);
}

void ServerSelectMenuItemList::SelectServerEntryIndex(int index)
{
    OnItemSelected(index, 0);
}

void ServerSelectMenuItemList::ApplyServerEntry(
    const ServerSelectEntry *entry)
{
    swprintf_s(g_pApplication->m_currentServerName, 256,
               L"%s", entry->name);
    SendServerSelectPacket(entry->serverId, entry);
}

void ServerSelectMenuItemList::SendServerSelectPacket(
    unsigned int serverId, const ServerSelectEntry *entry)
{
    unsigned char packet[16];

    PacketBufferWriteUInt8(0x57, &packet[0]);
    PacketBufferWriteUInt8(0, &packet[1]);
    PacketBufferWriteUInt8((unsigned char)serverId, &packet[2]);
    g_packetSender->QueueAndSendPacket(packet, 3);

    g_pConfig->m_selectedServerId = serverId;
    if (!g_pConfig->m_alternateServerEndpointActive) {
        swprintf_s(g_pConfig->m_serverEndpointText, 64,
                   L"%d.%d.%d.%d.%d.%d",
                   g_pConfig->m_serverEndpointPrefix,
                   entry->address[0], entry->address[1],
                   entry->address[2], entry->address[3],
                   (short)entry->port);
    }
}

void ServerSelectMenuItemList::OnItemActivated()
{
    m_owner->ActivateFocusedControl();
}

void ServerSelectMenuItemList::DrawListEntry(
    int rowIndex, void *rowData, RectBounds *rowBounds)
{
    ServerSelectEntry *entry =
        *static_cast<ServerSelectEntry **>(rowData);

    if (g_useEpfAssets)
        rowBounds->right -= 10;

    if (IsItemSelected(rowIndex)) {
        SetDrawColor(0x25);
        g_pfnFillRect(this, rowBounds);
        SetTextColor(0x80);
        swprintf_s(g_pApplication->m_currentServerName, 256,
                   L"%s", entry->name);
    } else {
        SetTextColor(0x25);
    }

    wchar_t text[1024];
    swprintf_s(text, 1024, L"%s : %s",
               entry->name, entry->description);
    DrawTextInRect(text, wcslen(text), rowBounds);
}

// UID:0003D9 | by-memory/0x00624dc0-0x00624e84.ServerSelectMenuItemListVtableData.md | Completion:94 | Confidence:98
// ServerSelectMenuItemList vtables and RTTI are compiler-generated from the
// class declaration and virtual methods. Do not hand-author the
// 0x00624dc0-0x00624e84 locator or table dwords as C++.

// UID:0000VG | by-item\ServerSelectHelpers_574510_5745b0.md | Completion:91 | Confidence:94 | Empty Emitter Marker

// UID:0001HR | by-memory\0x00573d20-0x005747df.ServerSelectPane.md | Completion:91 | Confidence:94 | Empty Emitter Marker
