// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000I3
// Source by-file doc: by-file/ChangePasswordDialogPane.md
// UID:00001L | by-class/ChangePasswordDialogPane.md | Completion:91 | Confidence:92
#pragma once

#include "../ui/core/DialogPane.h"
#include "../util/Singleton.h"

class Event;
class ChangePasswordDialogPane;
extern ChangePasswordDialogPane *g_pChangePasswordDialogPane;

class ChangePasswordDialogPane : public DialogPane,
                                 public Singleton<ChangePasswordDialogPane>
{
public:
    ChangePasswordDialogPane();

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateActionButton();
    virtual bool HandlePacketEvent(Event *event);

private:
    void SubmitPasswordChange();
    bool HandlePasswordChangeReply(const unsigned char *packet);
    bool HandlePasswordChangeReplySimple(const unsigned char *packet);
};
