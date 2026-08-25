// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LG
// Source by-file doc: by-file/MiscWorkThread.md
// UID:00008I | by-class/MiscWorkThread.md | Completion:92 | Confidence:94
#ifndef NEXUSTK_APP_MISCWORKTHREAD_H
#define NEXUSTK_APP_MISCWORKTHREAD_H

#include "../util/Thread.h"
#include "../util/Singleton.h"

class MiscWorkThread;
extern MiscWorkThread* g_pMiscWorkThread;

class MiscWorkThread : public Thread,
                       public Singleton<MiscWorkThread>
{
public:
    MiscWorkThread();
    virtual ~MiscWorkThread();

    virtual void OnMessage(int messageId, int payloadValue, int aux);

    void RequestHTTPGet(const wchar_t* url);
    void RequestNCAUpdate(const wchar_t* account, const wchar_t* password);
    void RequestBrowseDirectory(const char* title);
};

#endif

// UID:00008X | by-class/ncauth__Notification.md | Completion:88 | Confidence:90
#ifndef NEXUSTK_APP_NCAUTH_NOTIFICATION_H
#define NEXUSTK_APP_NCAUTH_NOTIFICATION_H

#include "../util/LObject.h"

namespace ncauth {

// UID:0001SQ | by-type/by-enum/NcauthNotificationState.md | Completion:88 | Confidence:93
enum NotificationState
{
    Accepted = 0,
    IdRejected = 1,
    PasswordRejected = 2,
    RejectedOther = 3,
    OpenFailed = 4,
    ReadFailed = 5
};

class Notification : public LObject
{
public:
    explicit Notification(NotificationState state)
        : m_state(state)
    {
    }

    virtual ~Notification()
    {
    }

    NotificationState m_state;
};

} // namespace ncauth

#endif
