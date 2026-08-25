// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000HH
// Source by-file doc: by-file/ArgumentedItemInputDialogs.md
// UID:00000G | by-class/ArgumentedItemQuantityInputDialogPane.md | Completion:92 | Confidence:94
#pragma once

#include "../core/DialogPane.h"

class ArgumentedMenuMenuItemList;

class ArgumentedItemQuantityInputDialogPane : public DialogPane
{
public:
    ArgumentedItemQuantityInputDialogPane(
        const wchar_t *promptText,
        ArgumentedMenuMenuItemList *menuContext,
        unsigned int argumentId);

    virtual void OnControlCommand(int controlIndex, int notifyCode);

private:
    ArgumentedMenuMenuItemList *m_menuContext;
    unsigned int m_argumentId;
};

// UID:00000F | by-class/ArgumentedItemConfirmInputDialogPane.md | Completion:92 | Confidence:94
class ArgumentedItemConfirmInputDialogPane : public DialogPane
{
public:
    ArgumentedItemConfirmInputDialogPane(
        const wchar_t *promptText,
        ArgumentedMenuMenuItemList *menuContext,
        unsigned int maxQuantity,
        unsigned int expectedPrice,
        unsigned int argumentId);

    virtual void OnControlCommand(int controlIndex, int notifyCode);

private:
    ArgumentedMenuMenuItemList *m_menuContext;
    unsigned int m_maxQuantity;
    unsigned int m_expectedPrice;
    unsigned int m_argumentId;
};
