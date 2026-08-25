// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000I8
// Source by-file doc: by-file/Clan.md
// UID:000023 | by-class/ClanAppearNameInputDialog.md | Completion:93 | Confidence:93
class ClanAppearNameInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanAppearNameInputDialog(const unsigned char *packet);

protected:
    virtual void OnSubmitText(const wchar_t *text);
};

// UID:000024 | by-class/ClanAttrInputDialog.md | Completion:92 | Confidence:93
class ClanAttrInputDialog : public DialogPane
{
public:
    explicit ClanAttrInputDialog(const unsigned char *packet);

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void ValidateInputFields();
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual int OnSubmit() = 0;

    wchar_t m_submittedClanName[256];
    wchar_t m_submittedDescriptionText[256];
    wchar_t m_submittedAttributeText[256];
    unsigned short m_submittedAttributeType;
};

// UID:000027 | by-class/ClanChangeInputDialog.md | Completion:92 | Confidence:93
class ClanChangeInputDialog : public ClanAttrInputDialog
{
public:
    explicit ClanChangeInputDialog(const unsigned char *packet);

protected:
    virtual int OnSubmit();
};

// UID:000028 | by-class/ClanChangeNameInputDialog.md | Completion:85 | Confidence:89
class ClanChangeNameInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanChangeNameInputDialog(const unsigned char *packet);

protected:
    virtual void OnSubmitText(const wchar_t *text);
};

// UID:00002A | by-class/ClanDepMoneyInputDialog.md | Completion:86 | Confidence:90
class ClanDepMoneyInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanDepMoneyInputDialog(const unsigned char *packet);

protected:
    virtual void OnSubmitText(const wchar_t *text);
};

// UID:00002B | by-class/ClanEnlistInputDialog.md | Completion:92 | Confidence:93
class ClanEnlistInputDialog : public ClanAttrInputDialog
{
public:
    explicit ClanEnlistInputDialog(const unsigned char *packet);

protected:
    virtual int OnSubmit();
};

// UID:00002D | by-class/ClanExpelNameInputDialog.md | Completion:86 | Confidence:90
class ClanExpelNameInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanExpelNameInputDialog(const unsigned char *packet);

    virtual void OnSubmitText(const wchar_t *text);
};

// UID:00002E | by-class/ClanInfoListPane.md | Completion:90 | Confidence:93
#include "../ui/controls/TextEditPane.h"

class Event;

class ClanInfoListPane : public TextEditPane
{
public:
    ClanInfoListPane();

protected:
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool OnMouseEvent(Event *event);
};

// UID:00002I | by-class/ClanLeaveConfirmDialog.md | Completion:92 | Confidence:93
class ClanLeaveConfirmDialog : public AlertPane
{
public:
    ClanLeaveConfirmDialog(const wchar_t *messageText,
                           Pane *layoutReference,
                           const wchar_t *primaryButtonText,
                           const wchar_t *secondaryButtonText);

protected:
    virtual void OnConfirm();
    virtual void OnCancel();
};

// UID:00002J | by-class/ClanNameInputDialog.md | Completion:86 | Confidence:89
class ClanNameInputDialog : public DialogPane
{
public:
    explicit ClanNameInputDialog(const unsigned char *packet);

protected:
    virtual void OnSubmitText(const wchar_t *text);
    virtual void OnButtonClick(int closeContext, int controlId);
    virtual void UpdateOkButtonState();
    virtual bool HandlePointerOrMouseEvent(Event *event);
};

// UID:00002K | by-class/ClanStatusPane.md | Completion:89 | Confidence:91
enum ClanStatusView
{
    kClanStatusViewStatus = 0,
    kClanStatusViewManagement = 1,
    kClanStatusViewInfoList = 2,
    kClanStatusViewJoinList = 3,
    kClanStatusViewEnlistList = 4
};

enum ClanStatusRow
{
    kClanStatusRowHeader = 0,
    kClanStatusRowUnused = 1,
    kClanStatusRowEnlistRequest = 2,
    kClanStatusRowJoinList = 3,
    kClanStatusRowLeaveClan = 4,
    kClanStatusRowDepositMoney = 5,
    kClanStatusRowDepositItem = 6,
    kClanStatusRowEnlistList = 7,
    kClanStatusRowExpelMember = 8,
    kClanStatusRowSummonMember = 9,
    kClanStatusRowAppearMember = 10,
    kClanStatusRowChangeName = 11,
    kClanStatusRowWithdrawMoney = 12,
    kClanStatusRowWithdrawItem = 13,
    kClanStatusRowManagementTab = 14,
    kClanStatusRowStatusTab = 15
};

class ClanStatusPane : public Pane
{
public:
    ClanStatusPane();
    virtual ~ClanStatusPane();

    void ParseClanStatusAttributePacket(const unsigned char *packet);
    void RefreshChildPanes();
    void ShowInfoList();
    void ShowEnlistList();
    virtual bool HandlePointerOrMouseEvent(Event *event);

    int SendClanJoinListSelectionPacket(const wchar_t *selectedClanName);
    void SendClanLeaveResponse(bool confirmed);
    int SendClanStatusRowActionPacket(short rowIndex);
    int SendClanEnlistListRefreshPacket();
    int SendClanEnlistListSelectionPacket(const wchar_t *applicantName);
    int SendClanAttributePacket(const wchar_t *clanName, const wchar_t *descriptionText, const wchar_t *attributeText, unsigned short attributeType);
    bool IsRowActionBlocked(short rowIndex);

private:
    void DrawStatusRowText(short rowIndex);
    void GetStatusRowRect(short rowIndex, RectBounds *outBounds);
    short HitTestStatusRow(int y, int x);
};

// UID:00002M | by-class/ClanSummonNameInputDialog.md | Completion:85 | Confidence:89
class ClanSummonNameInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanSummonNameInputDialog(const unsigned char *packet);

protected:
    virtual void OnSubmitText(const wchar_t *text);
};

// UID:00002O | by-class/ClanWidMoneyInputDialog.md | Completion:86 | Confidence:90
class ClanWidMoneyInputDialog : public ClanNameInputDialog
{
public:
    explicit ClanWidMoneyInputDialog(const unsigned char *packet);

protected:
    virtual void OnSubmitText(const wchar_t *text);
};
