// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M0
// Source by-file doc: by-file/NexonclubRegistrationDialog.md
// UID:00009I | by-class/NexonclubRegistrationDialog.md | Completion:94 | Confidence:95
#include "NexonclubRegistrationDialog.h"

[[No Children Attached]]


// UID:0001CU | by-memory/0x00530020-0x0053057b.NexonclubRegistrationSupportHelpers.md | Completion:94 | Confidence:95
#include "NexonclubRegistrationDialog.h"

#include "AlertPanes.h"
#include "../../app/MiscWorkThread.h"
#include "../../localization/LanguageMan.h"
#include "../controls/TextEditControlPane.h"
#include "../core/ScreenDimmer.h"
#include "../../util/StringBase.h"

#include <shellapi.h>

namespace {

const unsigned int kNcauthNotificationChannel = 0x4e634175;
const int kAccountControlId = 2;
const int kPasswordControlId = 3;
const int kSubmitCommand = 4;
const int kCancelCommand = 5;
const int kOpenRegistrationWebCommand = 6;
const int kPendingRegistrationStringId = 233;
const int kRegistrationTimeoutStringId = 234;
const int kRegistrationTimerId = 0;
const int kRegistrationTimeoutMilliseconds = 30000;

typedef mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
    RegistrationString;

}

void NexonclubRegistrationDialog::OnPendingRegistrationAlertClosed(
    unsigned long)
{
    m_registrationRequestPending = false;
    RemovePendingTimers();

    if (m_pendingStatusAlert != NULL) {
        m_pendingStatusAlert->CloseDialog();
        m_pendingStatusAlert = NULL;
    }
}

void NexonclubRegistrationDialog::OnControlCommand(
    int controlIndex,
    int)
{
    switch (controlIndex) {
    case kSubmitCommand:
    {
        RegistrationString account =
            GetChild<TextEditControlPane>(kAccountControlId)->GetInputText();
        RegistrationString password =
            GetChild<TextEditControlPane>(kPasswordControlId)->GetInputText();

        g_pMiscWorkThread->RequestNCAUpdate(
            account.c_str(),
            password.c_str());
        m_registrationRequestPending = true;

        typedef void (NexonclubRegistrationDialog::*PendingAlertCallback)(
            unsigned long);
        FunctionObjectT<unsigned long> *callback =
            new PlainMemberFunctionObject<
                PendingAlertCallback,
                NexonclubRegistrationDialog,
                unsigned long>(
                    &NexonclubRegistrationDialog::
                        OnPendingRegistrationAlertClosed,
                    0,
                    this);

        m_pendingStatusAlert = new VersatileAlertPane(
            g_pLanguageMan->GetLocalizedString(
                kPendingRegistrationStringId),
            this,
            callback,
            L"Cancel",
            NULL);

        ScheduleTimer(
            kRegistrationTimerId,
            kRegistrationTimeoutMilliseconds,
            0,
            0);
        break;
    }

    case kCancelCommand:
    {
        RegistrationString emptyAccount;
        m_registrationResultCallback->Invoke(emptyAccount);
        CloseDialog();
        break;
    }

    case kOpenRegistrationWebCommand:
        ShellExecuteA(
            NULL,
            NULL,
            "http://www.nexon.com/KR/Page/NX.aspx?URL=Login/Register",
            NULL,
            NULL,
            SW_SHOWNORMAL);
        break;
    }
}

bool NexonclubRegistrationDialog::HandleType19Event(Event *event)
{
    if (event->m_payload.m_notification.m_channel !=
            kNcauthNotificationChannel ||
        !m_registrationRequestPending) {
        return false;
    }

    m_registrationRequestPending = false;
    RemovePendingTimers();

    if (m_pendingStatusAlert != NULL) {
        m_pendingStatusAlert->CloseDialog();
        m_pendingStatusAlert = NULL;
    }

    if (g_pScreenDimmer != NULL) {
        delete g_pScreenDimmer;
    }

    if (m_pendingStatusAlert != NULL) {
        m_pendingStatusAlert->CloseDialog();
        m_pendingStatusAlert = NULL;
    }

    const ncauth::Notification *notification =
        static_cast<const ncauth::Notification *>(
            event->m_payload.m_notification.m_payload);

    switch (notification->m_state) {
    case ncauth::Accepted:
    {
        RegistrationString account = GetAccountText();
        m_registrationResultCallback->Invoke(account);
        CloseDialog();
        break;
    }

    case ncauth::IdRejected:
        ShowRegistrationResultAlert(228);
        break;
    case ncauth::PasswordRejected:
        ShowRegistrationResultAlert(229);
        break;
    case ncauth::RejectedOther:
        ShowRegistrationResultAlert(230);
        break;
    case ncauth::OpenFailed:
        ShowRegistrationResultAlert(231);
        break;
    case ncauth::ReadFailed:
        ShowRegistrationResultAlert(232);
        break;
    }

    return true;
}

bool NexonclubRegistrationDialog::OnTimer(int, int, int)
{
    m_registrationRequestPending = false;
    RemovePendingTimers();

    if (m_pendingStatusAlert != NULL) {
        m_pendingStatusAlert->CloseDialog();
        m_pendingStatusAlert = NULL;
    }

    new AlertPane(
        g_pLanguageMan->GetLocalizedString(kRegistrationTimeoutStringId),
        this,
        L"OK",
        NULL);
    return true;
}

mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
NexonclubRegistrationDialog::GetAccountText() const
{
    return GetChild<TextEditControlPane>(
        kAccountControlId)->GetInputText();
}

void NexonclubRegistrationDialog::ShowRegistrationResultAlert(int stringId)
{
    new AlertPane(
        g_pLanguageMan->GetLocalizedString(stringId),
        this,
        L"OK",
        NULL);
}

// The switch table at 0x005303f0 and deleting-destructor adjustors at
// 0x00530565/0x00530570 are compiler-generated from the source above and
// the virtual NexonclubRegistrationDialog declaration.

// UID:0001CT | by-memory\0x0052f950-0x00530636.NexonclubRegistrationDialog.md | Completion:88 | Confidence:92 | Empty Emitter Marker
