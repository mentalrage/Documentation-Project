// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M0
// Source by-file doc: by-file/NexonclubRegistrationDialog.md
// UID:00009I | by-class/NexonclubRegistrationDialog.md | Completion:94 | Confidence:95
#pragma once

#include "../core/DialogPane.h"
#include "../../util/FunctionObjects.h"
#include "../../util/StringBase.h"

class Event;
class VersatileAlertPane;

class NexonclubRegistrationDialog : public DialogPane
{
public:
    NexonclubRegistrationDialog(
        const wchar_t *messageText,
        FunctionObjectT<
            const mystr::StringBase<
                wchar_t,
                mystr::mychar_traits<wchar_t> > &> *registrationResultCallback);
    virtual ~NexonclubRegistrationDialog();

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual bool HandleType19Event(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    void OnPendingRegistrationAlertClosed(unsigned long result);
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
        GetAccountText() const;
    void ShowRegistrationResultAlert(int stringId);

    FunctionObjectT<
        const mystr::StringBase<
            wchar_t,
            mystr::mychar_traits<wchar_t> > &> *m_registrationResultCallback;
    bool m_registrationRequestPending;
    unsigned char m_registrationRequestPadding[3];
    VersatileAlertPane *m_pendingStatusAlert;
};
