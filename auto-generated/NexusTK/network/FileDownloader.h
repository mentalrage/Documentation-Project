// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000JC
// Source by-file doc: by-file/FileDownloader.md
// UID:00050F | by-class/BaseRequest.md | Completion:93 | Confidence:94
#ifndef NEXUSTK_NETWORK_FILEDOWNLOADER_H
#define NEXUSTK_NETWORK_FILEDOWNLOADER_H

#include <string>
#include "../util/Thread.h"

class BaseRequest
{
public:
    BaseRequest()
        : downloadComplete(false),
          contentLength(0),
          bytesDownloaded(0)
    {
    }

    bool downloadComplete;
    unsigned long contentLength;
    unsigned long bytesDownloaded;
};

// UID:00001I | by-class/CashShopVersionRequest.md | Completion:93 | Confidence:94
class CashShopVersionRequest : public BaseRequest
{
public:
    virtual ~CashShopVersionRequest() {}
};

// UID:00001H | by-class/CashShopRequest.md | Completion:93 | Confidence:94
class CashShopRequest : public BaseRequest
{
public:
    CashShopRequest();
    virtual ~CashShopRequest() {}

    std::string responseText;
};

// UID:00004W | by-class/FileDownloader.md | Completion:93 | Confidence:94
class FileDownloader : public Thread
{
public:
    FileDownloader();
    virtual ~FileDownloader();

    virtual void OnMessage(int messageId, void *payload, int aux);

    bool SubmitMinimapRequest(int mapId,
                              const wchar_t *mapCode,
                              const wchar_t *outputPath);
    void SubmitCashShopCatalogRequest();
    bool SubmitCashShopVersionRequest();
};

#endif
