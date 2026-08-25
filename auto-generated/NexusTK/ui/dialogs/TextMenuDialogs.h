// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OP
// Source by-file doc: by-file/TextMenuDialogs.md
// UID:0000ES | by-class/TextMenuDialog.md | Completion:94 | Confidence:94
#pragma once

#include "MerchantDialogPane.h"
#include "../../core/LObject.h"
#include "../../util/StringBase.h"

class DialogPane;
class TextMenuItemList;

class MerchantDialogCreator : public LObject
{
};

void CreateMerchantMenuDialog(const unsigned char *packet);
DialogPane *CreateTextMenuDialog(const unsigned char *payload);
DialogPane *CreateTextMenuDialogWithExtraString(const unsigned char *payload);
DialogPane *CreateTextInputMenuDialog(const unsigned char *payload);
DialogPane *CreateTextInputMenuDialogWithExtraString(const unsigned char *payload);
DialogPane *CreateServerItemMenuDialog(const unsigned char *payload);
DialogPane *CreateClientItemMenuDialog(const unsigned char *payload);
DialogPane *CreateServerSpellMenuDialog(const unsigned char *payload);
DialogPane *CreateClientSpellMenuDialog(const unsigned char *payload);
DialogPane *CreateArgumentedMenuDialog(const unsigned char *payload);

class TextMenuDialog : public MerchantDialogPane
{
public:
    TextMenuDialog(bool hasExtraString,
                   const RectBounds& bounds,
                   const unsigned char *payload,
                   unsigned char merchantDialogType);

    virtual void OnPaint();
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();

private:
    friend class TextMenuItemList;

    void SendMenuReply(unsigned short optionIndex);

    unsigned char m_replyType;             // +0x274
    unsigned char m_reserved275[3];        // +0x275
    unsigned char m_itemCount;             // +0x278
    bool m_hasExtraString;                 // +0x279
    mystr::StringBase<
        wchar_t, mystr::mychar_traits<wchar_t> > m_extraString; // +0x27c
    unsigned short m_itemIds[6];           // +0x280
};

typedef char TextMenuDialogSizeMustBe652[
    (sizeof(TextMenuDialog) == 0x28c) ? 1 : -1];

// UID:0000ER | by-class/TextInputMenuDialog.md | Completion:94 | Confidence:94
class TextInputMenuDialog : public MerchantDialogPane
{
public:
    TextInputMenuDialog(bool hasExtraString,
                        const RectBounds& bounds,
                        const unsigned char *payload,
                        unsigned char merchantDialogType);

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();

private:
    void SendInputReply(const wchar_t *inputText);

    unsigned int m_reserved274;            // +0x274, retained unknown storage
    unsigned char m_replyType;             // +0x278
    unsigned short m_selectedOptionId;      // +0x27a
    bool m_hasExtraString;                 // +0x27c
    mystr::StringBase<
        wchar_t, mystr::mychar_traits<wchar_t> > m_extraString; // +0x280
};

typedef char TextInputMenuDialogSizeMustBe644[
    (sizeof(TextInputMenuDialog) == 0x284) ? 1 : -1];
