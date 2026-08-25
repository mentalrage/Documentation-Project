// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000K2
// Source by-file doc: by-file/ImageLib.md
// UID:00006E | by-class/ImageLib.md | Completion:92 | Confidence:93
#ifndef NEXUSTK_RENDER_IMAGELIB_H
#define NEXUSTK_RENDER_IMAGELIB_H

#include "../util/LObject.h"
#include "../util/List.h"

struct ArchiveMetadataTable;
struct EPFTileContext;
struct FrameDrawRecord;
struct RectBounds;

struct ResourceLayoutEntry
{
    int left;
    int top;
    int right;
    int bottom;
    unsigned char *pixelData;
    unsigned char *encodedMaskData;
};

struct ResourceLayoutNameRecord
{
    wchar_t name[16];
    unsigned short entryCount;
    unsigned short frameWidth;
    unsigned short frameHeight;
    unsigned short reservedHeaderWord;
    ResourceLayoutEntry *entries;
};

class ImageLib : public LObject
{
public:
    ImageLib(int cacheLimit, int);
    virtual ~ImageLib();
    int LoadResourceIndex(const wchar_t *resourceName);
    int FindResourceIndex(const wchar_t *resourceName);
    const ResourceLayoutNameRecord *GetResourceLayout(
        int resourceIndex) const
    {
        return static_cast<ResourceLayoutNameRecord *>(
            m_pEntryList->GetElementAt(resourceIndex));
    }
    void LookupLayoutEntry(
        const wchar_t *resourceName, int frameIndex,
        EPFTileContext *outContext);
    void CopyEntryTileContext(
        const wchar_t *resourceName, int frameIndex,
        EPFTileContext *destination);
    void GetEntryRect(
        const wchar_t *resourceName, int frameIndex,
        RectBounds *bounds);
    void LoadFrameDrawRecord(
        const ArchiveMetadataTable *table, int frameIndex,
        FrameDrawRecord *outRecord);
    void GetFrameSize(
        const wchar_t *resourceName,
        unsigned short *width, unsigned short *height);
    unsigned short GetEntryCount(const wchar_t *resourceName);

private:
    ResourceLayoutEntry *GetEntry(int resourceIndex, int frameIndex);
    int m_refCount;
    int m_cacheLimit;
    List *m_pEntryList;
    int m_maxCacheSize;
};

typedef ImageLib ResourceLayoutTable;
extern ImageLib *g_pEPFLib;
typedef char ImageLibSizeMustBe20[
    sizeof(ImageLib) == 0x14 ? 1 : -1];
typedef char ResourceLayoutEntrySizeMustBe24[
    sizeof(ResourceLayoutEntry) == 0x18 ? 1 : -1];
typedef char ResourceLayoutNameRecordSizeMustBe44[
    sizeof(ResourceLayoutNameRecord) == 0x2c ? 1 : -1];

#endif

// UID:00029J | by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md | Completion:91 | Confidence:94
extern bool g_imageLibraryLoadError;
