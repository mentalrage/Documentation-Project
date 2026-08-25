// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LG
// Source by-file doc: by-file/MiscWorkThread.md
// UID:000012 | by-class/brdir__Notification.md | Completion:87 | Confidence:91
// UID:000012 | brdir::Notification source-level browse-directory payload.
// Emitted before UID:0001CJ so the MiscWorkThread aggregate can use this
// declaration without duplicating the class body.

#include <windows.h>

namespace brdir {

class Notification : public LObject {
public:
    virtual ~Notification()
    {
    }

    char m_path[MAX_PATH];
};

} // namespace brdir

// UID:00008I | by-class/MiscWorkThread.md | Completion:92 | Confidence:94
#include "MiscWorkThread.h"

// UID:0004HM | by-memory/0x0061fb70-0x0061fb74.MiscWorkThreadRttiLocatorPointer.md | Completion:92 | Confidence:95
// Compiler-generated MSVC RTTI complete-object-locator pointer for MiscWorkThread.
// The MiscWorkThread class declaration regenerates this primary vftable[-1] metadata.
// No standalone source object or raw RTTI dword is emitted here.

// UID:0001SP | by-type/by-enum/MiscWorkThreadMessageId.md | Completion:88 | Confidence:91
enum MiscWorkThreadMessageId {
    kMiscWorkBrowseDirectory = 0x42446972, // BDir
    kMiscWorkGetHttp = 0x47654874,         // GeHt
    kMiscWorkNcaUpdate = 0x4e434175        // NCAu request
};

// UID:000069 | by-class/httpget__Notification.md | Completion:88 | Confidence:89
// UID:000069 | httpget::Notification source-level payload declaration.

namespace httpget {

// UID:0001SN | by-type/by-enum/HttpGetNotificationState.md | Completion:88 | Confidence:90
enum NotificationState {
    Started = 0,
    DataChunk = 1,
    Completed = 2,
    ReadOrOpenUrlFailed = 3,
    InternetOpenFailed = 4
};

class Notification : public LObject {
public:
    Notification(NotificationState state, LObject* payload = 0)
        : m_state(state), m_payload(payload)
    {
    }

    virtual ~Notification()
    {
        if ((m_state == DataChunk || m_state == InternetOpenFailed) && m_payload != 0) {
            delete m_payload;
        }
    }

    NotificationState m_state;
    LObject* m_payload;
};

} // namespace httpget

// UID:00008X | by-class/ncauth__Notification.md | Completion:88 | Confidence:90

// UID:0000RQ | by-global/g_pMiscWorkThread.md | Completion:90 | Confidence:94
// UID:0000RQ | MiscWorkThread singleton pointer and Singleton specializations.

MiscWorkThread* g_pMiscWorkThread = 0;

template <>
Singleton<MiscWorkThread>::Singleton()
{
    g_pMiscWorkThread = static_cast<MiscWorkThread *>(this);
}

template <>
Singleton<MiscWorkThread>::~Singleton()
{
    g_pMiscWorkThread = 0;
}

// UID:0001P8 | by-memory/0x0067ab50-0x0067ab54.g_pMiscWorkThread.md | Completion:90 | Confidence:94
// UID:0001P8 | Exact storage for g_pMiscWorkThread at 0x0067ab50.
// The source definition is emitted by UID:0000RQ; do not duplicate the
// singleton pointer definition from this storage child.

// UID:00027S | by-memory/0x0066de30-0x0066de6c.NcauthConfirmUserUrlObfuscated.md | Completion:88 | Confidence:91
// UID:00027S | Bitwise-not encoded NCA confirm-user fallback URL.
// Decodes to:
// http://mail.nexonclub.com/clubadmin/confirmuser?ID=%s&PW=%s

extern const unsigned char g_ncauthConfirmUserUrlObfuscated[] = {
    0x97, 0x8b, 0x8b, 0x8f, 0xc5, 0xd0, 0xd0, 0x92,
    0x9e, 0x96, 0x93, 0xd1, 0x91, 0x9a, 0x87, 0x90,
    0x91, 0x9c, 0x93, 0x8a, 0x9d, 0xd1, 0x9c, 0x90,
    0x92, 0xd0, 0x9c, 0x93, 0x8a, 0x9d, 0x9e, 0x9b,
    0x92, 0x96, 0x91, 0xd0, 0x9c, 0x90, 0x91, 0x99,
    0x96, 0x8d, 0x92, 0x8a, 0x8c, 0x9a, 0x8d, 0xc0,
    0xb6, 0xbb, 0xc2, 0xda, 0x8c, 0xd9, 0xaf, 0xa8,
    0xc2, 0xda, 0x8c, 0xff
};

// UID:00029T | by-memory/0x0069b3d0-0x0069b3d4.MainMenuTextUrlStaticString.md | Completion:90 | Confidence:93
// UID:00029T | NCA confirm-user URL override string storage.

SimpleUString g_ncauthConfirmUserUrlOverride;

// UID:0001CJ | by-memory/0x005277c0-0x005285dd.MiscWorkThreadAndNotifications.md | Completion:90 | Confidence:93
// UID:0001CJ | MiscWorkThread worker helpers and local notifications.

#include <windows.h>
#include <shlobj.h>
#include <wininet.h>
#include <stdio.h>

// UID:0001SP emits MiscWorkThreadMessageId before this worker aggregate.
// UID:000069/UID:0001SN emit httpget::Notification and its state enum.
// UID:00008X/UID:0001SQ emit ncauth::Notification and its state enum.
// Keep this aggregate focused on worker/helper bodies and request wrappers.

enum MiscWorkThreadNotificationId {
    kBrowseDirectoryNotification = 0x42446972,
    kHttpGetNotification = 0x68747470,
    kNcauthNotification = 0x4e634175
};

namespace brdir {

// UID:000012 emits the source-level class declaration before this aggregate.
// Keep the declaration out of this block to avoid duplicate generated classes.

} // namespace brdir

namespace httpget {

// UID:000069 and UID:0001SN emit the source-level class and state enum
// before this aggregate. Keep the declaration out of this block to avoid
// duplicate generated classes.

} // namespace httpget

namespace ncauth {

// UID:00008X and UID:0001SQ emit the source-level class and state enum
// before this aggregate. Keep the declaration out of this block to avoid
// duplicate generated classes.

} // namespace ncauth

extern Application* g_pApplication;
class EventMan {
public:
    void PostNotification(unsigned int channel, LObject* notification);
};
extern EventMan* g_pEventMan;
extern MiscWorkThread* g_pMiscWorkThread;
extern SimpleUString g_ncauthConfirmUserUrlOverride; // UID:00029T
extern const unsigned char g_ncauthConfirmUserUrlObfuscated[]; // UID:00027S

static void PostNotification(unsigned int channel, LObject* notification)
{
    g_pEventMan->PostNotification(channel, notification);
}

static void DecodeNcauthConfirmUserUrl(char* out, size_t outSize)
{
    size_t i = 0;
    while (i + 1 < outSize && g_ncauthConfirmUserUrlObfuscated[i] != 0) {
        out[i] = static_cast<char>(~g_ncauthConfirmUserUrlObfuscated[i]);
        ++i;
    }
    out[i] = 0;
}

static void BrowseForDirectoryAndPost(const char* title)
{
    BROWSEINFOA browseInfo;
    char displayName[MAX_PATH];

    CoInitialize(0);
    ShowCursor(TRUE);

    memset(&browseInfo, 0, sizeof(browseInfo));
    browseInfo.hwndOwner = g_pApplication->GetWindowHandle();
    browseInfo.pszDisplayName = displayName;
    browseInfo.lpszTitle = title;
    browseInfo.ulFlags = BIF_RETURNONLYFSDIRS;

    LPITEMIDLIST pidl = SHBrowseForFolderA(&browseInfo);

    brdir::Notification* notification = new brdir::Notification;
    if (pidl == 0 || !SHGetPathFromIDListA(pidl, notification->m_path)) {
        notification->m_path[0] = 0;
    }

    PostNotification(kBrowseDirectoryNotification, notification);

    ShowCursor(FALSE);
    CoUninitialize();
}

static void FetchHTTPContent(const wchar_t* url)
{
    HINTERNET session = InternetOpenA("Baram", 0, 0, 0, 0);
    if (session == 0) {
        PostNotification(kHttpGetNotification,
                         new httpget::Notification(httpget::InternetOpenFailed,
                                                   new InternetError));
        return;
    }

    SimpleString narrowUrl(url);
    HINTERNET request = InternetOpenUrlA(session, narrowUrl.c_str(), 0, 0, 0, 0);
    if (request == 0) {
        PostNotification(kHttpGetNotification,
                         new httpget::Notification(httpget::ReadOrOpenUrlFailed));
        InternetCloseHandle(session);
        return;
    }

    PostNotification(kHttpGetNotification,
                     new httpget::Notification(httpget::Started));

    BYTE buffer[0x400];
    DWORD bytesRead = 0;
    BOOL ok = InternetReadFile(request, buffer, sizeof(buffer), &bytesRead);
    while (ok && bytesRead != 0) {
        _AUTOBUF<unsigned char>* chunk = new _AUTOBUF<unsigned char>(bytesRead);
        memmove(chunk->data(), buffer, bytesRead);
        PostNotification(kHttpGetNotification,
                         new httpget::Notification(httpget::DataChunk, chunk));
        ok = InternetReadFile(request, buffer, sizeof(buffer), &bytesRead);
    }

    if (!ok) {
        PostNotification(kHttpGetNotification,
                         new httpget::Notification(httpget::ReadOrOpenUrlFailed));
    }

    PostNotification(kHttpGetNotification,
                     new httpget::Notification(httpget::Completed));

    InternetCloseHandle(request);
    InternetCloseHandle(session);
}

static void PostNCAStatus(ncauth::NotificationState state)
{
    PostNotification(kNcauthNotification, new ncauth::Notification(state));
}

static void ProcessNCAUpdate(const SimpleUString& account, const SimpleUString& password)
{
    HINTERNET session = InternetOpenA(0, 0, 0, 0, 0);
    if (session == 0) {
        PostNotification(kNcauthNotification,
                         new ncauth::Notification(ncauth::OpenFailed));
        return;
    }

    char url[0x100];
    if (!g_ncauthConfirmUserUrlOverride.empty()) {
        strcpy_s(url, sizeof(url), g_ncauthConfirmUserUrlOverride.c_str());
    } else {
        char format[0x80];
        SimpleString accountText(account);
        SimpleString passwordText(password);
        DecodeNcauthConfirmUserUrl(format, sizeof(format));
        sprintf_s(url, sizeof(url), format, accountText.c_str(), passwordText.c_str());
    }

    HINTERNET request = InternetOpenUrlA(session, url, Locale, 0, 0, 0);
    if (request == 0) {
        InternetCloseHandle(session);
        PostNCAStatus(ncauth::OpenFailed);
        return;
    }

    char response[0x80];
    DWORD bytesRead = 0;
    if (!InternetReadFile(request, response, sizeof(response), &bytesRead)) {
        PostNCAStatus(ncauth::ReadFailed);
        InternetCloseHandle(request);
        InternetCloseHandle(session);
        return;
    }

    if (response[0] == '1') {
        PostNCAStatus(ncauth::Accepted);
    } else if (response[2] == ' ' && response[3] == 'I' && response[4] == 'D') {
        PostNCAStatus(ncauth::IdRejected);
    } else if (response[2] == 'P' && response[3] == 'W') {
        PostNCAStatus(ncauth::PasswordRejected);
    } else {
        PostNCAStatus(ncauth::RejectedOther);
    }

    InternetCloseHandle(request);
    InternetCloseHandle(session);
}

MiscWorkThread::MiscWorkThread()
    : Thread(100)
{
    StartThread();
}

MiscWorkThread::~MiscWorkThread()
{
    StopThread();
}

void MiscWorkThread::OnMessage(int messageId, int payloadValue, int aux)
{
    void* payload = reinterpret_cast<void*>(payloadValue);

    switch (messageId) {
    case kMiscWorkBrowseDirectory:
        BrowseForDirectoryAndPost(static_cast<const char*>(payload));
        free(payload);
        break;

    case kMiscWorkGetHttp:
        FetchHTTPContent(static_cast<SimpleUString*>(payload)->c_str());
        delete static_cast<SimpleUString*>(payload);
        break;

    case kMiscWorkNcaUpdate:
    {
        SimpleUString* strings = static_cast<SimpleUString*>(payload);
        ProcessNCAUpdate(strings[0], strings[1]);
        strings[1].~SimpleUString();
        strings[0].~SimpleUString();
        operator delete(strings);
        break;
    }

    default:
        Thread::OnMessage(messageId, payloadValue, aux);
        break;
    }
}

void MiscWorkThread::RequestHTTPGet(const wchar_t* url)
{
    DispatchRequest(kMiscWorkGetHttp, new SimpleUString(url), 0);
}

void MiscWorkThread::RequestNCAUpdate(const wchar_t* account, const wchar_t* password)
{
    SimpleUString* strings =
        static_cast<SimpleUString*>(operator new(sizeof(SimpleUString) * 2));
    new (&strings[0]) SimpleUString(account);
    new (&strings[1]) SimpleUString(password);
    DispatchRequest(kMiscWorkNcaUpdate, strings, 0);
}

void MiscWorkThread::RequestBrowseDirectory(const char* title)
{
    DispatchRequest(kMiscWorkBrowseDirectory, _strdup(title), 0);
}

// UID:0001SQ | by-type\by-enum\NcauthNotificationState.md | Completion:88 | Confidence:93 | Empty Emitter Marker

// UID:0003C6 | by-memory\0x0061fbac-0x0061fbdc.WorkThreadNotificationVtableData.md | Completion:87 | Confidence:91 | Empty Emitter Marker
