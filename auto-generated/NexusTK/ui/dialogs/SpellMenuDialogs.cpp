// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O2
// Source by-file doc: by-file/SpellMenuDialogs.md
// UID:0000D3 | by-class/ServerSpellMenuDialog.md | Completion:90 | Confidence:91
#include "SpellMenuDialogs.h"

// UID:0000D4 | by-class/ServerSpellMenuItemList.md | Completion:90 | Confidence:91
// ServerSpellMenuItemList definitions are emitted by source child UID0004Y5.

// UID:00002R | by-class/ClientSpellMenuDialog.md | Completion:90 | Confidence:91
// ClientSpellMenuDialog definitions are emitted by source child UID0004Y6.

// UID:00002S | by-class/ClientSpellMenuItemList.md | Completion:90 | Confidence:91
// ClientSpellMenuItemList definitions are emitted by source child UID0004Y7.

// UID:0004Y4 | by-memory/0x0051ca40-0x0051d6fd.ServerSpellMenuDialogMethods.md | Completion:90 | Confidence:91
ServerSpellMenuDialog::ServerSpellMenuDialog(const RectBounds& bounds,
                                             const unsigned char *payload,
                                             unsigned char menuMode)
    : MerchantDialogPane(menuMode),
      m_packetSubtype(payload[0])
{
    m_menuObjectId = PacketBufferReadUInt32BE(payload + 1);

    ObjectStatusBlob objectStatus;
    const unsigned char *cursor = payload + 6;

    cursor = objectStatus.ParseTaggedStatus(cursor);
    SetObjectImage(objectStatus);

    wchar_t description[256];
    cursor = ReadMenuText(cursor, description, _countof(description));
    SetDialogText(description);

    const unsigned short menuOptionId = PacketBufferReadUInt16BE(cursor);
    cursor += sizeof(unsigned short);

    ServerSpellMenuItemList *list = new ServerSpellMenuItemList(
        m_packetSubtype,
        m_menuObjectId,
        menuOptionId,
        this);

    const unsigned short entryCount = PacketBufferReadUInt16BE(cursor);
    cursor += sizeof(unsigned short);

    for (unsigned int i = 0; i < entryCount; ++i) {
        cursor += 4;

        wchar_t spellName[256];
        cursor = ReadMenuText(cursor, spellName, _countof(spellName));
        list->AppendSpellName(0, spellName);
    }

    CreateSpellMenuLayout(g_useEpfAssets ? kCurrentDlgMerc1Layout
                                         : kLegacyDlgMerc1Layout);
    AddControl(6, list);
    UpdateActionButtonState();
}

void ServerSpellMenuDialog::HandleMenuCommand(int commandId, void *context)
{
    UNREFERENCED_PARAMETER(context);

    switch (commandId) {
    case 1:
        if (ServerSpellMenuItemList *list = GetServerSpellMenuList(6))
            list->SendSelectedSpellName();
        CloseDialog();
        break;

    case 2:
        SendMenuRequestPacket();
        break;

    case 3:
        CloseDialog();
        break;
    }
}

void ServerSpellMenuDialog::UpdateActionButtonState()
{
    ControlPane *actionButton = GetControl(1);
    ServerSpellMenuItemList *list = GetServerSpellMenuList(6);
    const bool hasSelection = list != NULL && list->GetSelectionCount() > 0;

    if (actionButton != NULL)
        actionButton->SetEnabled(hasSelection);
}

// UID:0004Y5 | by-memory/0x0051d700-0x0051db38.ServerSpellMenuItemList.md | Completion:90 | Confidence:91
struct ServerSpellMenuEntry
{
    unsigned short reserved;
    wchar_t name[256];
};

ServerSpellMenuItemList::ServerSpellMenuItemList(
    unsigned char packetSubtype,
    unsigned int menuObjectId,
    unsigned short menuOptionId,
    ServerSpellMenuDialog* owner)
    : ListPane(sizeof(ServerSpellMenuEntry), 0x10, 0xe4, 0x0c, 0, true, true),
      m_packetSubtype(packetSubtype),
      m_menuObjectId(menuObjectId),
      m_menuOptionId(menuOptionId),
      m_owner(owner)
{
}

void ServerSpellMenuItemList::AppendSpellName(unsigned short reserved, const wchar_t* name)
{
    ServerSpellMenuEntry entry;

    entry.reserved = reserved;
    wcscpy_s(entry.name, _countof(entry.name), name != NULL ? name : L"");

    AddEntry(&entry);
}

bool ServerSpellMenuItemList::SendSelectedSpellName()
{
    if (m_selectedIndex < 0 || m_selectedIndex >= GetItemCount())
        return false;

    ServerSpellMenuEntry* entry = static_cast<ServerSpellMenuEntry*>(GetEntryAt(m_selectedIndex));
    if (entry == NULL)
        return false;

    return SendSpellName(entry->name);
}

bool ServerSpellMenuItemList::SendSpellName(const wchar_t* name)
{
    PacketBuffer packet;

    packet.WriteByte(0x39);
    packet.WriteByte(m_packetSubtype);
    packet.WriteDword(m_menuObjectId);
    packet.WriteWord(m_menuOptionId);
    packet.WriteWideStringAsMultiByte(name != NULL ? name : L"");

    SendGamePacket(packet);
    return true;
}

void ServerSpellMenuItemList::NotifyOwnerSpellActivated()
{
    m_owner->UpdateActionButtonState();
}

void ServerSpellMenuItemList::DrawListEntry(
    DrawContext* dc,
    int index,
    const ServerSpellMenuEntry* entry,
    const Rect& bounds)
{
    if (entry == NULL)
        return;

    const bool selected = IsItemSelected(index);
    if (selected)
        dc->FillSelectedListRow(bounds);

    dc->SetTextColor(selected ? kSelectedTextColor : kNormalTextColor);
    dc->SetTransparentTextBackground();

    wchar_t fittedName[256];
    wcscpy_s(fittedName, _countof(fittedName), entry->name);

    Rect textBounds = bounds;
    CenterListTextVertically(textBounds, 12);
    FitWideTextWithEllipsis(dc, fittedName, textBounds.Width());
    dc->DrawText(textBounds, fittedName);
}

// UID:0004Y6 | by-memory/0x0051db40-0x0051e63d.ClientSpellMenuDialogMethods.md | Completion:90 | Confidence:91
ClientSpellMenuDialog::ClientSpellMenuDialog(const RectBounds& bounds,
                                             const unsigned char *payload,
                                             unsigned char menuMode)
    : MerchantDialogPane(menuMode),
      m_packetSubtype(payload[0])
{
    m_menuObjectId = PacketBufferReadUInt32BE(payload + 1);

    ObjectStatusBlob objectStatus;
    const unsigned char *cursor = payload + 6;

    cursor = objectStatus.ParseTaggedStatus(cursor);
    SetObjectImage(objectStatus);

    wchar_t description[256];
    cursor = ReadMenuText(cursor, description, _countof(description));
    SetDialogText(description);

    const unsigned short menuOptionId = PacketBufferReadUInt16BE(cursor);
    cursor += sizeof(unsigned short);

    ClientSpellMenuItemList *list = new ClientSpellMenuItemList(
        m_packetSubtype,
        m_menuObjectId,
        menuOptionId,
        this);

    for (unsigned char slot = 1; slot <= 52; ++slot) {
        const UserPaneSpellSlotRecord *spell = g_pUserPane->GetSpellSlot(slot);
        if (spell != NULL && spell->active)
            list->AppendSpell(slot, 0, spell->name);
    }

    CreateSpellMenuLayout(g_useEpfAssets ? kCurrentDlgMerc1Layout
                                         : kLegacyDlgMerc1Layout);
    AddControl(6, list);
    UpdateActionButtonState();
}

void ClientSpellMenuDialog::HandleMenuCommand(int commandId, void *context)
{
    UNREFERENCED_PARAMETER(context);

    switch (commandId) {
    case 1:
        if (ClientSpellMenuItemList *list = GetClientSpellMenuList(6))
            list->SendSelectedSpell();
        CloseDialog();
        break;

    case 2:
        SendMenuRequestPacket();
        break;

    case 3:
        CloseDialog();
        break;
    }
}

void ClientSpellMenuDialog::UpdateActionButtonState()
{
    ControlPane *actionButton = GetControl(1);
    ClientSpellMenuItemList *list = GetClientSpellMenuList(6);
    const bool hasSelection = list != NULL && list->GetSelectionCount() > 0;

    if (actionButton != NULL)
        actionButton->SetEnabled(hasSelection);
}

// UID:0004Y7 | by-memory/0x0051e640-0x0051e998.ClientSpellMenuItemList.md | Completion:90 | Confidence:91
struct ClientSpellMenuEntry
{
    unsigned char spellSlot;
    unsigned short reserved;
    wchar_t name[256];
};

ClientSpellMenuItemList::ClientSpellMenuItemList(
    unsigned char packetSubtype,
    unsigned int menuObjectId,
    unsigned short menuOptionId,
    ClientSpellMenuDialog* owner)
    : ListPane(sizeof(ClientSpellMenuEntry), 0x10, 0xe4, 0x0c, 0, true, true),
      m_packetSubtype(packetSubtype),
      m_menuObjectId(menuObjectId),
      m_menuOptionId(menuOptionId),
      m_owner(owner)
{
}

void ClientSpellMenuItemList::AppendSpell(
    unsigned char spellSlot,
    unsigned short reserved,
    const wchar_t* name)
{
    ClientSpellMenuEntry entry;

    entry.spellSlot = spellSlot;
    entry.reserved = reserved;
    wcscpy_s(entry.name, _countof(entry.name), name != NULL ? name : L"");

    AddEntry(&entry);
}

bool ClientSpellMenuItemList::SendSelectedSpell()
{
    if (m_selectedIndex < 0 || m_selectedIndex >= GetItemCount())
        return false;

    ClientSpellMenuEntry* entry = static_cast<ClientSpellMenuEntry*>(GetEntryAt(m_selectedIndex));
    if (entry == NULL)
        return false;

    return SendSpell(entry->spellSlot);
}

bool ClientSpellMenuItemList::SendSpell(unsigned char spellSlot)
{
    PacketBuffer packet;

    packet.WriteByte(0x39);
    packet.WriteByte(m_packetSubtype);
    packet.WriteDword(m_menuObjectId);
    packet.WriteWord(m_menuOptionId);
    packet.WriteByte(spellSlot);

    SendGamePacket(packet);
    return true;
}

void ClientSpellMenuItemList::NotifyOwnerSpellActivated()
{
    m_owner->UpdateActionButtonState();
}

void ClientSpellMenuItemList::DrawListEntry(
    DrawContext* dc,
    int index,
    const ClientSpellMenuEntry* entry,
    const Rect& bounds)
{
    if (entry == NULL)
        return;

    const bool selected = IsItemSelected(index);
    if (selected)
        dc->FillSelectedListRow(bounds);

    dc->SetTextColor(selected ? kSelectedTextColor : kNormalTextColor);
    dc->SetTransparentTextBackground();

    wchar_t fittedName[256];
    wcscpy_s(fittedName, _countof(fittedName), entry->name);

    Rect textBounds = bounds;
    CenterListTextVertically(textBounds, 12);
    FitWideTextWithEllipsis(dc, fittedName, textBounds.Width());
    dc->DrawText(textBounds, fittedName);
}
