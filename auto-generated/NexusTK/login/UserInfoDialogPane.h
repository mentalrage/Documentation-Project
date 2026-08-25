// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000OY
// Source by-file doc: by-file/UserInfoDialogPane.md
// UID:0000FM | by-class/UserInfoDialogPane.md | Completion:95 | Confidence:94
#ifndef NEXUSTK_LOGIN_USERINFODIALOGPANE_H
#define NEXUSTK_LOGIN_USERINFODIALOGPANE_H

#include "../ui/core/DialogPane.h"

class Event;

enum UserInfoControlId
{
    kUserInfoBackground = 0,
    kUserInfoOkButton = 1,
    kUserInfoCancelButton = 2,
    kUserInfoNameEdit = 3,
    kUserInfoResidentIdPrefixEdit = 4,
    kUserInfoResidentIdSuffixEdit = 5,
    kUserInfoParentNameEdit = 6,
    kUserInfoBloodTypeMenu = 7,
    kUserInfoResidenceMenu = 8,
    kUserInfoPrimaryAccessMethodMenu = 9,
    kUserInfoDiscoveryReasonMenu = 10
};

enum UserInfoValidationResult
{
    kUserInfoNameInvalid = 0,
    kUserInfoResidentIdPrefixInvalid = 1,
    kUserInfoResidentIdSuffixInvalid = 2,
    kUserInfoParentNameInvalid = 3,
    kUserInfoBloodTypeRequired = 4,
    kUserInfoResidenceRequired = 5,
    kUserInfoPrimaryAccessMethodRequired = 6,
    kUserInfoDiscoveryReasonRequired = 7,
    kUserInfoValidationSucceeded = 10
};

class UserInfoDialogPane : public DialogPane
{
public:
    explicit UserInfoDialogPane(const unsigned char *packet);

    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();

protected:
    virtual void SetHoverControl(int controlId);

private:
    UserInfoValidationResult ValidateInput();
    void SendUserInfo();
    wchar_t m_validationMessages[8][128];
};

#endif
