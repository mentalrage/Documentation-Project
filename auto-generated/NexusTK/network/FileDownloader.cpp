// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JC
// Source by-file doc: by-file/FileDownloader.md
// UID:00050F | by-class/BaseRequest.md | Completion:93 | Confidence:94
#include "FileDownloader.h"

// UID:00001I | by-class/CashShopVersionRequest.md | Completion:93 | Confidence:94
// UID:0002CN | by-memory/0x0041b5e0-0x0041b604.CashShopVersionRequestScalarDeletingDestructor.md | Completion:88 | Confidence:93
// Compiler-generated scalar deleting destructor for CashShopVersionRequest.
// Emitted code for this range is covered by [UID:00001I][CashShopVersionRequest](by-class/CashShopVersionRequest.md).


// UID:00001H | by-class/CashShopRequest.md | Completion:93 | Confidence:94
// UID:0002CH | by-memory/0x0041a5d0-0x0041a607.CashShopRequestConstructorRaw.md | Completion:94 | Confidence:94
CashShopRequest::CashShopRequest()
    : BaseRequest(),
      responseText()
{
}

// UID:0002CI | by-memory/0x0041a610-0x0041a662.CashShopRequestNonDeletingDestructorRaw.md | Completion:88 | Confidence:91
// Compiler-generated non-deleting destructor for CashShopRequest.
// Regenerated from the CashShopRequest class declaration and embedded response string member.
// Scalar-delete wrapper glue is covered by UID 0002CM; vtable slot data is covered by UID 0003FS.

// UID:0002CM | by-memory/0x0041b570-0x0041b5db.CashShopRequestScalarDeletingDestructor.md | Completion:88 | Confidence:93
// Compiler-generated scalar deleting destructor for CashShopRequest.
// Regenerated from the CashShopRequest class/destructor/vtable route.
// Ordinary cleanup is covered by UID 0002CI; vtable slot data is covered by UID 0003FS.

// UID:0003FS | by-memory/0x0060d79c-0x0060d7a4.CashShopRequestVtableData.md | Completion:94 | Confidence:94
// Emitted code for this range is covered by [UID:00001H][CashShopRequest](by-class/CashShopRequest.md).


// UID:0003FT | by-memory/0x0060d7a4-0x0060d7e0.FileDownloaderVtableData.md | Completion:88 | Confidence:93
// Emitted code for this range is covered by [UID:00004W][FileDownloader](by-class/FileDownloader.md).

// UID:0002TP | by-memory/0x0041a670-0x0041a6e5.FileDownloaderConstructor.md | Completion:88 | Confidence:91
FileDownloader::FileDownloader()
    : Thread(5)
{
    g_pFileDownloader = this;
    StartThread();
}

// UID:0002TQ | by-memory/0x0041a6f0-0x0041a741.FileDownloaderDestructor.md | Completion:88 | Confidence:91
FileDownloader::~FileDownloader()
{
    StopThread();
    g_pFileDownloader = 0;
}

// UID:0002TU | by-memory/0x0041b110-0x0041b180.FileDownloaderOnMessage.md | Completion:88 | Confidence:91
void FileDownloader::OnMessage(int messageId, void *payload, int aux)
{
    switch (messageId) {
    case kDownloadMinimapFileMessage:
        if (payload != NULL) {
            DownloadMinimapFile(static_cast<FileDownloaderMinimapRequest *>(payload));
            operator delete(payload);
        }
        break;

    case kDownloadCashShopCatalogMessage:
        if (payload != NULL) {
            DownloadCashShopCatalog(static_cast<CashShopRequest *>(payload));
        }
        break;

    case kDownloadCashShopVersionMessage:
        if (payload != NULL) {
            CashShopVersionRequest *request =
                static_cast<CashShopVersionRequest *>(payload);
            DownloadCashShopVersion(request);
            delete request;
        }
        break;

    default:
        Thread::OnMessage(messageId, payload, aux);
        break;
    }
}

// UID:0002CJ | by-memory/0x0041b180-0x0041b1f5.FileDownloaderSubmitMinimapRequest.md | Completion:88 | Confidence:90
bool FileDownloader::SubmitMinimapRequest(int mapId,
                                          const wchar_t *mapCode,
                                          const wchar_t *outputPath)
{
    FileDownloaderMinimapRequest *request = new FileDownloaderMinimapRequest;
    request->state = 0;
    request->contentLength = 0;
    request->bytesDownloaded = 0;
    request->mapId = mapId;
    wcscpy_s(request->mapCode, 0x10, mapCode);
    wcscpy_s(request->outputPath, 0x104, outputPath);

    return DispatchRequest(kDownloadMinimapFileMessage, request, 0);
}

// UID:0002CK | by-memory/0x0041b200-0x0041b26d.FileDownloaderSubmitCashShopCatalogRequest.md | Completion:88 | Confidence:90
void FileDownloader::SubmitCashShopCatalogRequest()
{
    CashShopRequest *request = new CashShopRequest;
    DispatchRequest(kDownloadCashShopCatalogMessage, request, 0);

    if (g_pFittingRoomDialog != NULL) {
        g_pFittingRoomDialog->m_activeCatalogRequest = request;
    }
}

// UID:0002CL | by-memory/0x0041b270-0x0041b2c9.FileDownloaderSubmitCashShopVersionRequest.md | Completion:88 | Confidence:90
bool FileDownloader::SubmitCashShopVersionRequest()
{
    CashShopVersionRequest *request = new CashShopVersionRequest;
    return DispatchRequest(kDownloadCashShopVersionMessage, request, 0);
}

// UID:0000QH | by-global/g_pCashShopRequest.md | Completion:90 | Confidence:91
FileDownloader *g_pFileDownloader;

// UID:0002TR | by-memory/0x0041a750-0x0041a9fe.DownloadMinimapFile.md | Completion:88 | Confidence:90
static bool __stdcall DownloadMinimapFile(FileDownloaderMinimapRequest *request)
{
    HINTERNET internet = InternetOpenW(L"HTTPTEST", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    if (internet == NULL) {
        return false;
    }

    wchar_t directory[4];
    wchar_t url[MAX_PATH * 2];

    wsprintfW(directory, L"%03d", request->mapId / 1000);
    wsprintfW(url,
              L"%s%s/%s%s",
              L"https://s3.amazonaws.com/kru-downloads/tk/minimaps/",
              directory,
              request->mapCode,
              L".mnm");

    HINTERNET remoteFile = InternetOpenUrlW(internet, url, NULL, 0, INTERNET_FLAG_RELOAD, 0);
    if (remoteFile == NULL) {
        InternetCloseHandle(internet);
        return false;
    }

    unsigned long statusLength = 16;
    wchar_t statusText[16];
    bool ok = false;

    if (HttpQueryInfoW(remoteFile, HTTP_QUERY_STATUS_CODE, statusText, &statusLength, NULL) &&
        _wtoi(statusText) == HTTP_STATUS_OK) {
        HANDLE localFile = CreateFileW(request->outputPath,
                                       GENERIC_WRITE,
                                       0,
                                       NULL,
                                       CREATE_ALWAYS,
                                       FILE_ATTRIBUTE_NORMAL,
                                       NULL);
        if (localFile != INVALID_HANDLE_VALUE) {
            char buffer[0x4000];
            unsigned long totalBytes = 0;

            for (;;) {
                unsigned long available = 0;
                unsigned long bytesRead = 0;
                unsigned long bytesWritten = 0;

                if (!InternetQueryDataAvailable(remoteFile, &available, 0, 0)) {
                    break;
                }
                if (available == 0) {
                    ok = true;
                    break;
                }
                if (available > sizeof(buffer)) {
                    available = sizeof(buffer);
                }
                if (!InternetReadFile(remoteFile, buffer, available, &bytesRead)) {
                    break;
                }
                if (bytesRead == 0) {
                    ok = true;
                    break;
                }
                if (!WriteFile(localFile, buffer, bytesRead, &bytesWritten, NULL) ||
                    bytesWritten != bytesRead) {
                    break;
                }

                totalBytes += bytesWritten;

                wchar_t progress[64];
                wsprintfW(progress, L"Downloading : %d\n", totalBytes);
                OutputDebugStringW(progress);
            }

            CloseHandle(localFile);
        }
    }

    InternetCloseHandle(remoteFile);
    InternetCloseHandle(internet);

    if (!ok) {
        DeleteFileW(request->outputPath);
    }

    return ok;
}

// UID:0002TS | by-memory/0x0041aa00-0x0041ae1c.DownloadCashShopVersion.md | Completion:91 | Confidence:93
static void __stdcall DownloadCashShopVersion(CashShopVersionRequest *request)
{
    int bytesDownloaded = 0;
    HINTERNET internet = InternetOpenW(L"HTTPTEST", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    if (internet == NULL) {
        return;
    }

    HINTERNET remoteFile = InternetOpenUrlW(internet,
                                            L"https://secure.kru.com/itemshop/data/itemshop.ver",
                                            NULL,
                                            0,
                                            INTERNET_FLAG_RELOAD,
                                            0);
    if (remoteFile == NULL) {
        InternetCloseHandle(internet);
        return;
    }

    DWORD timeout = 3000;
    InternetSetOptionW(remoteFile, INTERNET_OPTION_CONNECT_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_RECEIVE_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_SEND_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_DATA_SEND_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_DATA_RECEIVE_TIMEOUT, &timeout, sizeof(timeout));

    DWORD statusLength = 256;
    wchar_t statusText[128];
    HttpQueryInfoW(remoteFile, HTTP_QUERY_STATUS_CODE, statusText, &statusLength, NULL);

    std::string responseText;
    if (_wtoi(statusText) == HTTP_STATUS_OK) {
        DWORD contentLength = 0;
        DWORD lengthSize = sizeof(contentLength);
        HttpQueryInfoW(remoteFile,
                       HTTP_QUERY_CONTENT_LENGTH | HTTP_QUERY_FLAG_NUMBER,
                       &contentLength,
                       &lengthSize,
                       NULL);
        request->contentLength = contentLength;

        wchar_t progress[256] = {};
        char chunkBuffer[100000];
        DWORD bytesRead = 0;

        do {
            DWORD available = 0;

            if (!InternetQueryDataAvailable(remoteFile, &available, 0, 0) ||
                !InternetReadFile(remoteFile, chunkBuffer, available, &bytesRead)) {
                break;
            }

            chunkBuffer[bytesRead] = '\0';
            responseText.append(chunkBuffer, strlen(chunkBuffer));

            bytesDownloaded += bytesRead;
            request->bytesDownloaded = bytesDownloaded;

            swprintf_s(progress,
                       _countof(progress),
                       L"Downloading : %d / %d\n",
                       bytesDownloaded,
                       contentLength);
            OutputDebugStringW(progress);
        } while (bytesRead != 0);

        Json::Value root;
        Json::Reader reader;
        if (reader.parse(responseText, root, true)) {
            Json::Value versionValue = root.get("version", Json::Value());
            if (!versionValue.isNull()) {
                std::string versionText = versionValue.asString();
                if (g_pFittingRoomDialog != NULL) {
                    g_pFittingRoomDialog->m_itemShopVersion = versionText;
                }

                InternetCloseHandle(remoteFile);
                InternetCloseHandle(internet);
            }
        }
    }
}

// UID:0002TT | by-memory/0x0041ae20-0x0041b10c.DownloadCashShopCatalog.md | Completion:88 | Confidence:90
static void __stdcall DownloadCashShopCatalog(CashShopRequest *request)
{
    HINTERNET internet = InternetOpenW(L"HTTPTEST", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    if (internet == NULL) {
        return;
    }

    HINTERNET remoteFile = InternetOpenUrlW(internet,
                                            L"https://secure.kru.com/itemshop/data/itemshop.json",
                                            NULL,
                                            0,
                                            INTERNET_FLAG_RELOAD,
                                            0);
    if (remoteFile == NULL) {
        InternetCloseHandle(internet);
        return;
    }

    unsigned long timeout = 3000;
    InternetSetOptionW(remoteFile, INTERNET_OPTION_CONNECT_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_RECEIVE_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_SEND_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_DATA_SEND_TIMEOUT, &timeout, sizeof(timeout));
    InternetSetOptionW(remoteFile, INTERNET_OPTION_DATA_RECEIVE_TIMEOUT, &timeout, sizeof(timeout));

    unsigned long statusLength = 16;
    wchar_t statusText[16];

    if (HttpQueryInfoW(remoteFile, HTTP_QUERY_STATUS_CODE, statusText, &statusLength, NULL) &&
        _wtoi(statusText) == HTTP_STATUS_OK) {
        unsigned long lengthSize = sizeof(request->contentLength);
        request->contentLength = 0;
        request->bytesDownloaded = 0;
        HttpQueryInfoW(remoteFile,
                       HTTP_QUERY_CONTENT_LENGTH | HTTP_QUERY_FLAG_NUMBER,
                       &request->contentLength,
                       &lengthSize,
                       NULL);

        char buffer[0x4000];

        for (;;) {
            unsigned long available = 0;
            unsigned long bytesRead = 0;

            if (!InternetQueryDataAvailable(remoteFile, &available, 0, 0)) {
                break;
            }
            if (available == 0) {
                request->downloadComplete = 1;
                break;
            }
            if (available > sizeof(buffer)) {
                available = sizeof(buffer);
            }
            if (!InternetReadFile(remoteFile, buffer, available, &bytesRead) ||
                bytesRead == 0) {
                request->downloadComplete = 1;
                break;
            }

            request->responseText.append(buffer, bytesRead);
            request->bytesDownloaded += bytesRead;

            wchar_t progress[64];
            wsprintfW(progress,
                      L"Downloading : %d / %d\n",
                      request->bytesDownloaded,
                      request->contentLength);
            OutputDebugStringW(progress);
        }
    }

    InternetCloseHandle(remoteFile);
    InternetCloseHandle(internet);

    if (request->downloadComplete &&
        (g_pFittingRoomDialog == NULL ||
         g_pFittingRoomDialog->m_activeCatalogRequest != request)) {
        delete request;
    }
}






// UID:0001OP | by-memory/0x0067a738-0x0067a73c.g_pCashShopRequest.md | Completion:89 | Confidence:91
// Emitted code for this range is covered by [UID:0000QH][g_pCashShopRequest](by-global/g_pCashShopRequest.md).

// UID:0001SF | by-type/by-constant/DownloaderMessageIds.md | Completion:88 | Confidence:90
enum FileDownloaderMessageId {
    kDownloadMinimapFileMessage = 10000,
    kDownloadCashShopCatalogMessage = 10001,
    kDownloadCashShopVersionMessage = 10002
};

// UID:0003FR | by-memory\0x0060d794-0x0060d79c.CashShopVersionRequestVtableData.md | Completion:92 | Confidence:94 | Empty Emitter Marker

// UID:00004W | by-class\FileDownloader.md | Completion:93 | Confidence:94 | Empty Emitter Marker

// UID:0003FY | by-memory\0x0060d7e0-0x0060d7f4.SharedDownloaderUserAgentWideString.md | Completion:88 | Confidence:93 | Empty Emitter Marker

// UID:0003FZ | by-memory\0x0060d7f4-0x0060d8b8.MinimapDownloadWideLiterals.md | Completion:89 | Confidence:93 | Empty Emitter Marker

// UID:0003G0 | by-memory\0x0060d8b8-0x0060d94c.CashShopVersionDownloadWideLiterals.md | Completion:86 | Confidence:91 | Empty Emitter Marker

// UID:0003G1 | by-memory\0x0060d94c-0x0060d958.SharedVersionJsonKey.md | Completion:88 | Confidence:93 | Empty Emitter Marker

// UID:0003G2 | by-memory\0x0060d958-0x0060d9c0.CashShopCatalogDownloadWideUrl.md | Completion:86 | Confidence:92 | Empty Emitter Marker
