// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HI
// Source by-file doc: by-file/ArgumentedMenuDialogs.md
// UID:00000H | by-class/ArgumentedMenuMenuDialog.md | Completion:91 | Confidence:93
#pragma once

#include "MerchantDialogPane.h"

class ArgumentedMenuMenuItemList;

class ArgumentedMenuMenuDialog : public MerchantDialogPane
{
public:
    ArgumentedMenuMenuDialog(const RectBounds& bounds,
                             const unsigned char *payload,
                             unsigned char menuMode);

protected:
    void HandleMenuCommand(int commandId, void *context);
    void UpdateActionButtonState();

private:
    ArgumentedMenuMenuItemList *GetArgumentedMenuList(
        int controlIndex) const;

    unsigned char m_commandType;          // +0x274
    unsigned char m_reserved275[3];       // +0x275..+0x277
};

typedef char ArgumentedMenuMenuDialogSizeMustBe632[
    (sizeof(ArgumentedMenuMenuDialog) == 0x278) ? 1 : -1];

// UID:00000I | by-class/ArgumentedMenuMenuItemList.md | Completion:91 | Confidence:93
class ArgumentedItemQuantityInputDialogPane;
class ArgumentedItemConfirmInputDialogPane;

struct ArgumentedMenuItemEntry
{
    unsigned short itemId;
    unsigned char itemStyle;
    unsigned int price;
    wchar_t name[0x100];
    wchar_t description[0x100];
    unsigned int argumentId;
    unsigned int maxQuantity;
};

class ArgumentedMenuMenuItemList : public ListPane
{
public:
    ArgumentedMenuMenuItemList(
        unsigned char commandType,
        unsigned int ownerId,
        unsigned short listParameter,
        ArgumentedMenuMenuDialog *ownerDialog);
    ArgumentedMenuMenuItemList(
        const ArgumentedMenuMenuItemList &source);
    virtual ~ArgumentedMenuMenuItemList();

    void AppendItem(unsigned short itemId,
                    unsigned char itemStyle,
                    unsigned int price,
                    const wchar_t *name,
                    const wchar_t *description,
                    unsigned int argumentId,
                    unsigned char maxQuantity);
    const ArgumentedMenuItemEntry *GetSelectedEntry() const;

protected:
    virtual void OnItemSelected(int rowIndex, int notify);
    virtual void OnItemActivated();
    virtual bool OnMouseEvent(MouseEvent *event);
    virtual void DrawListEntry(int rowIndex, void *rowData,
                               RectBounds *rowBounds);

private:
    friend class ArgumentedItemQuantityInputDialogPane;
    friend class ArgumentedItemConfirmInputDialogPane;

    void OpenBuyConfirmDialog();
    void OpenQuantityDialogOrSendSingle(
        unsigned int maxQuantity,
        unsigned int argumentId);
    void SendArgumentedItemQuantityPacket(
        unsigned int argumentId,
        unsigned char quantity);

    unsigned char m_commandType;
    unsigned int m_ownerId;
    unsigned short m_listParameter;
    ArgumentedMenuMenuDialog *m_ownerDialog;
};
