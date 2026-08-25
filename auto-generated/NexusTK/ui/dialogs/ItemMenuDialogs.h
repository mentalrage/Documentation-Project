// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KF
// Source by-file doc: by-file/ItemMenuDialogs.md
// UID:0000CZ | by-class/ServerItemMenuDialog.md | Completion:94 | Confidence:94
#pragma once

#include "MerchantDialogPane.h"
#include "../controls/ListPane.h"

class MouseEvent;

class ServerItemMenuDialog : public MerchantDialogPane
{
public:
    ServerItemMenuDialog(const RectBounds& bounds,
                         const unsigned char *payload,
                         unsigned char menuMode);
    virtual ~ServerItemMenuDialog() {}

    void OnControlCommand(int controlId, int notifyCode) override;
    void UpdateActionButton() override;

private:
    unsigned char m_packetSubtype;
    unsigned char m_reserved[3];
};

// UID:0000D0 | by-class/ServerItemMenuItemList.md | Completion:94 | Confidence:94
struct ServerItemMenuEntry
{
    unsigned short itemId;
    unsigned char itemStyle;
    unsigned char reserved;
    unsigned int value;
    wchar_t name[256];
    wchar_t description[256];
};

class ServerItemMenuItemList : public ListPane
{
public:
    ServerItemMenuItemList(unsigned char packetSubtype,
                           unsigned int menuObjectId,
                           unsigned short menuOptionId,
                           ServerItemMenuDialog *owner);
    virtual ~ServerItemMenuItemList();

    void AppendItem(unsigned short itemId,
                    unsigned char itemStyle,
                    unsigned int value,
                    const wchar_t *name,
                    const wchar_t *description);
    void SendSelectedItemName();
    void SendItemName(const wchar_t *name);

    void OnItemSelected(int rowIndex, int notify) override;
    void OnItemActivated() override;
    bool OnMouseEvent(MouseEvent *event) override;
    void DrawListEntry(int rowIndex, void *rowData,
                       RectBounds *rowBounds) override;

private:
    unsigned char m_packetSubtype;
    unsigned char m_reserved0[3];
    unsigned int m_menuObjectId;
    unsigned short m_menuOptionId;
    unsigned short m_reserved1;
    ServerItemMenuDialog *m_owner;
};

// UID:00002P | by-class/ClientItemMenuDialog.md | Completion:94 | Confidence:94
class ClientItemMenuDialog : public MerchantDialogPane
{
public:
    ClientItemMenuDialog(const RectBounds& bounds,
                         const unsigned char *payload,
                         unsigned char menuMode);
    virtual ~ClientItemMenuDialog() {}

    void OnControlCommand(int controlId, int notifyCode) override;
    void UpdateActionButton() override;

private:
    unsigned char m_packetSubtype;
    unsigned char m_reserved[3];
};

// UID:00002Q | by-class/ClientItemMenuItemList.md | Completion:94 | Confidence:94
struct ClientItemMenuEntry
{
    unsigned char actionId;
    unsigned char reserved0;
    unsigned short itemId;
    unsigned char itemStyle;
    unsigned char reserved1;
    wchar_t name[256];
};

class ClientItemMenuItemList : public ListPane
{
public:
    ClientItemMenuItemList(unsigned char packetSubtype,
                           unsigned int menuObjectId,
                           unsigned short menuOptionId,
                           ClientItemMenuDialog *owner);

    void AppendAction(unsigned char actionId,
                      unsigned short itemId,
                      unsigned char itemStyle,
                      const wchar_t *name);
    void SendSelectedAction();
    void SendAction(unsigned char actionId);

    void OnItemActivated() override;
    void DrawListEntry(int rowIndex, void *rowData,
                       RectBounds *rowBounds) override;

private:
    unsigned char m_packetSubtype;
    unsigned char m_reserved0[3];
    unsigned int m_menuObjectId;
    unsigned short m_menuOptionId;
    unsigned short m_reserved1;
    ClientItemMenuDialog *m_owner;
};
