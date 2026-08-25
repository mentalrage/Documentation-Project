// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IO
// Source by-file doc: by-file/DATFileMgr.md
// UID:0000UC | by-item/DATEntryRecord.md | Completion:94 | Confidence:96
// DATEntryRecord is declared only in DATFileMgr.h; no standalone CPP definition is required.

// UID:00003H | by-class/DATFileContainer.md | Completion:92 | Confidence:94
#include "DATFileMgr.h"
#include "DATFile.h"
#include "../util/Error.h"
#include "../util/File.h"
#include "../util/PathUtil.h"
#include <hash_map>
#include <stdio.h>
#include <vector>
#include <wchar.h>

// UID:00043B | by-memory/0x0049be80-0x0049c0c9.DATFileContainerConstructor.md | Completion:88 | Confidence:90
DATFileContainer::DATFileContainer(const wchar_t *path)
    : m_fileHandle(INVALID_HANDLE_VALUE),
      m_mappingHandle(NULL),
      m_mappedView(NULL),
      m_finalPayloadOffset(0),
      m_entryCount(0),
      m_entries(0)
{
    wchar_t retryPath[80] = L"..\\";

    m_fileHandle = CreateFileW(path, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (m_fileHandle == NULL || m_fileHandle == INVALID_HANDLE_VALUE) {
        wcscat_s(retryPath, 80, path);
        m_fileHandle = CreateFileW(retryPath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    }

    if (m_fileHandle == NULL || m_fileHandle == INVALID_HANDLE_VALUE) {
        return;
    }

    m_mappingHandle = CreateFileMappingW(m_fileHandle, NULL, PAGE_READONLY, 0, 0, NULL);
    if (m_mappingHandle == NULL) {
        wchar_t message[176];
        swprintf_s(message, 176, L"UNICreateFileMapping : %s", path);
        MessageBoxW(NULL, message, L"오류", MB_ICONWARNING);
        throw new Win32Error();
    }

    m_mappedView = MapViewOfFile(m_mappingHandle, FILE_MAP_READ, 0, 0, 0);
    if (m_mappedView == NULL) {
        DWORD error = GetLastError();
        wchar_t message[256];
        swprintf_s(message, 256, L"MapViewOfFile : %s Err %d", path, error);
        MessageBoxW(NULL, message, L"오류", MB_ICONWARNING);
        throw new Win32Error();
    }

    m_entryCount = *(unsigned int *)m_mappedView;
    m_entries = (DATEntryRecord *)((char *)m_mappedView + 4);
    m_finalPayloadOffset = m_entries[m_entryCount - 1].startOffset;
}

// UID:00043C | by-memory/0x0049c0d0-0x0049c130.DATFileContainerDestructor.md | Completion:88 | Confidence:91
DATFileContainer::~DATFileContainer()
{
    if (m_mappedView != NULL) {
        UnmapViewOfFile(m_mappedView);
    }
    if (m_mappingHandle != NULL) {
        CloseHandle(m_mappingHandle);
    }
    if (m_fileHandle != INVALID_HANDLE_VALUE) {
        CloseHandle(m_fileHandle);
    }
}

// UID:0003B6 | by-memory/0x00618918-0x00618920.DATFileContainerVtableData.md | Completion:86 | Confidence:92
// This compiler-emitted RTTI/vtable record is covered by the DATFileContainer class declaration and virtual destructor.

// UID:000004 | by-class/_DATFileMgr.md | Completion:94 | Confidence:96
namespace
{
struct DATEntryNameHashCompare
{
    enum { bucket_size = 4, min_buckets = 8 };

    size_t operator()(const StringBaseW &name) const
    {
        size_t hash = 0;
        const wchar_t *current = name.c_str();
        while (*current != L'\0') hash = *current++ + 5 * hash;
        return hash;
    }

    bool operator()(const StringBaseW &left, const StringBaseW &right) const
    {
        return mystr::WideRangeCompare(
            left.c_str(), left.c_str() + left.length(),
            right.c_str(), right.c_str() + right.length()) < 0;
    }
};
}

class _DATFileMgr {
public:
    virtual ~_DATFileMgr();

    bool LoadDATFileIndex(const wchar_t *archivePath);
    bool FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation);

private:
    typedef stdext::hash_map<StringBaseW, DATEntryLocation,
                             DATEntryNameHashCompare> EntryMap;
    EntryMap m_entriesByName;
    std::vector<DATFileContainer *> m_archiveContainers;
};

// UID:00012F | by-memory/0x0049c750-0x0049c7f6._DATFileMgrRawDestructor.md | Completion:88 | Confidence:92
_DATFileMgr::~_DATFileMgr()
{
    for (std::vector<DATFileContainer *>::iterator current =
             m_archiveContainers.begin();
         current != m_archiveContainers.end(); ++current) {
        delete *current;
    }
}

// UID:00043D | by-memory/0x0049c800-0x0049cac4._DATFileMgrLoadDATFileIndex.md | Completion:88 | Confidence:90
bool _DATFileMgr::LoadDATFileIndex(const wchar_t *archivePath)
{
    wchar_t retryPath[80] = L"../";
    wcscat_s(retryPath, 80, archivePath);

    if (!FileExists(archivePath) && !FileExists(retryPath)) {
        return false;
    }

    DATFileContainer *archive = new DATFileContainer(archivePath);
    m_archiveContainers.push_back(archive);

    for (unsigned int index = 0; index < archive->m_entryCount; ++index) {
        StringBaseA narrowName(archive->m_entries[index].name);
        if (narrowName.empty()) continue;
        _strupr_s(narrowName.data(), narrowName.length() + 1);
        StringBaseW normalizedName(narrowName);
        if (m_entriesByName.find(normalizedName) == m_entriesByName.end()) {
            DATEntryLocation location;
            location.archive = archive;
            location.index = index;
            m_entriesByName.insert(EntryMap::value_type(normalizedName, location));
        }
    }

    return true;
}

// UID:00043E | by-memory/0x0049cad0-0x0049cba5._DATFileMgrFindEntryByName.md | Completion:88 | Confidence:91
bool _DATFileMgr::FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation)
{
    StringBaseW normalizedName(entryName);
    _wcsupr_s(normalizedName.data(), normalizedName.length() + 1);
    EntryMap::const_iterator found = m_entriesByName.find(normalizedName);
    if (found == m_entriesByName.end()) return false;
    if (outLocation != NULL) *outLocation = found->second;
    return true;
}

// UID:0002MB | by-memory/0x006189c8-0x006189d0._DATFileMgrVtableData.md | Completion:86 | Confidence:93
// The _DATFileMgr RTTI pointer and one-slot vtable at 0x006189c8-0x006189d0
// are compiler-emitted from the _DATFileMgr class declaration and virtual
// destructor. Do not hand-author this record as a source array.

// UID:00003I | by-class/DATFileMgr.md | Completion:94 | Confidence:95
#include "DATFileMgr.h"
#include "DATFile.h"
#include "../util/Error.h"
#include "../util/File.h"
#include "../util/PathUtil.h"
#include <hash_map>
#include <stdio.h>
#include <vector>
#include <wchar.h>

// UID:000227 | by-memory/0x0049bd20-0x0049bd2c.DATFileMgrFindEntryForwarder.md | Completion:90 | Confidence:91
bool DATFileMgr::FindEntryByName(const wchar_t *entryName, DATEntryLocation *outLocation)
{
    return m_impl->FindEntryByName(entryName, outLocation);
}

// UID:000439 | by-memory/0x0049bd30-0x0049be41.DATFileMgrConstructor.md | Completion:92 | Confidence:94
DATFileMgr::DATFileMgr()
    : Singleton<DATFileMgr>(),
      m_impl(new _DATFileMgr)
{
}

// UID:00043A | by-memory/0x0049be50-0x0049be6d.DATFileMgrDestructor.md | Completion:90 | Confidence:94
DATFileMgr::~DATFileMgr()
{
    delete m_impl;
}

// UID:00012C | by-memory/0x0049be70-0x0049be7c.ForwardLoadDATFileIndex.md | Completion:90 | Confidence:93
bool DATFileMgr::LoadDATFile(const wchar_t *path)
{
    return m_impl->LoadDATFileIndex(path);
}

// UID:0002MA | by-memory/0x00618910-0x00618918.DATFileMgrVtableData.md | Completion:89 | Confidence:95
// The DATFileMgr RTTI pointer and one-slot vtable at 0x00618910-0x00618918
// are compiler-emitted from the DATFileMgr class declaration and virtual
// destructor. Do not hand-author this record as a source array.

// UID:0000QQ | by-global/g_pDATFileMgr.md | Completion:90 | Confidence:94
DATFileMgr *g_pDATFileMgr = 0;
// UID:0001P6 | by-memory/0x0067ab40-0x0067ab44.g_pDATFileMgr.md | Completion:88 | Confidence:91
// Exact storage for g_pDATFileMgr at 0x0067ab40.
// The source definition is emitted by [UID:0000QQ][g_pDATFileMgr](by-global/g_pDATFileMgr.md) g_pDATFileMgr;
// do not duplicate the pointer definition from this storage child.

// UID:00012E | by-memory/0x0049c700-0x0049c71d.HasDATEntry.md | Completion:90 | Confidence:92
bool HasDATEntry(const wchar_t *entryName)
{
    return g_pDATFileMgr != 0 && g_pDATFileMgr->FindEntryByName(entryName, 0);
}
