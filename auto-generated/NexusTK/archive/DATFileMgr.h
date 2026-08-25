// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IO
// Source by-file doc: by-file/DATFileMgr.md
// UID:0000UC | by-item/DATEntryRecord.md | Completion:94 | Confidence:96
#pragma pack(push, 1)
struct DATEntryRecord
{
    unsigned int startOffset;
    char name[13];
};
#pragma pack(pop)

typedef char DATEntryRecordSizeMustBe0x11[
    sizeof(DATEntryRecord) == 0x11 ? 1 : -1];

// UID:00003H | by-class/DATFileContainer.md | Completion:92 | Confidence:94
#include <windows.h>

class DATFile;
class _DATFileMgr;

class DATFileContainer
{
    friend class DATFile;
    friend class _DATFileMgr;

public:
    DATFileContainer(const wchar_t *path);
    virtual ~DATFileContainer();

private:
    HANDLE m_fileHandle;
    HANDLE m_mappingHandle;
    void *m_mappedView;
    unsigned int m_finalPayloadOffset;
    unsigned int m_entryCount;
    DATEntryRecord *m_entries;
};

struct DATEntryLocation
{
    DATFileContainer *archive;
    unsigned int index;
};

typedef char DATEntryLocationSizeMustBe0x08[
    sizeof(DATEntryLocation) == 0x08 ? 1 : -1];

// UID:00003I | by-class/DATFileMgr.md | Completion:94 | Confidence:95
#ifndef NEXUSTK_ARCHIVE_DATFILEMGR_H
#define NEXUSTK_ARCHIVE_DATFILEMGR_H

#include "../util/Singleton.h"

class _DATFileMgr;
struct DATEntryLocation;

class DATFileMgr : public Singleton<DATFileMgr>
{
public:
    DATFileMgr();
    virtual ~DATFileMgr();

    bool LoadDATFile(const wchar_t *archivePath);
    bool FindEntryByName(const wchar_t *entryName,
                         DATEntryLocation *outLocation);

private:
    _DATFileMgr *m_impl;
};

extern DATFileMgr *g_pDATFileMgr;

typedef char DATFileMgrSizeMustBe0x08[
    sizeof(DATFileMgr) == 0x08 ? 1 : -1];

#endif
