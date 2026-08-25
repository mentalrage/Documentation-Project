// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000K2
// Source by-file doc: by-file/ImageLib.md
// UID:00006E | by-class/ImageLib.md | Completion:92 | Confidence:93
#include "ImageLib.h"
#include "EPFTileContext.h"
#include "ImageFrameTable.h"
#include "../archive/DATFile.h"
#include "../ui/core/RectBounds.h"
#include "../util/List.h"
#include "../util/MemoryMan.h"
#include <wchar.h>

// UID:0002IN | by-memory/0x004cffb0-0x004d006f.ImageLibConstructor.md | Completion:91 | Confidence:92
ImageLib::ImageLib(int cacheLimit, int)
    : LObject()
{
    g_pEPFLib = this;
    m_cacheLimit = cacheLimit;
    m_refCount = 0;
    m_maxCacheSize = 1000000;
    m_pEntryList = new List(sizeof(ResourceLayoutNameRecord), 10);
}

// UID:000173 | by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md | Completion:90 | Confidence:92
ImageLib::~ImageLib()
{
    MemoryMan* memoryMan = GetMemoryMan();

    if (m_pEntryList != 0) {
        const int count = m_pEntryList->GetCount();

        for (int index = 0; index < count; ++index) {
            ResourceLayoutNameRecord* record =
                static_cast<ResourceLayoutNameRecord*>(m_pEntryList->GetElementAt(index));

            if (record->entries != 0) {
                record->entries =
                    static_cast<ResourceLayoutEntry*>(memoryMan->FreeBufferMemory(record->entries));
            }
        }

        delete m_pEntryList;
        m_pEntryList = 0;
    }

    g_pEPFLib = 0;
}

// UID:0002IO | by-memory/0x004e64a0-0x004e6572.ImageLibScalarDeletingDestructor.md | Completion:88 | Confidence:92
// Compiler-generated scalar deleting destructor for ImageLib; source cleanup is represented by ImageLib::~ImageLib() [UID:000173][0x004d0070-0x004d011b.ImageLibDestructor](by-memory/0x004d0070-0x004d011b.ImageLibDestructor.md).

// UID:0001US | by-type/by-struct/ImageLibLayout.md | Completion:86 | Confidence:90
// [UID:0001US] no standalone layout C++ body.
// The ImageLib field layout is consumed by the ImageLib lifecycle and ResourceLayoutTable facet children; emitting a duplicate layout struct would conflict with the pending class/facet declaration route.

// UID:0001XR | by-type/by-vtable/ImageLibVtable.md | Completion:88 | Confidence:93
// [UID:0001XR] no standalone vtable C++ body.
// The ImageLib vtable is compiler-emitted from the class declaration; exact slot data is documented by the vtable-data child and scalar deleting destructor route.
// UID:00031R | by-memory/0x0061b650-0x0061b660.ImageLibVtableData.md | Completion:89 | Confidence:93
// [UID:00031R] no standalone C++ body.
// Compiler-emitted ImageLib RTTI/vtable data is covered by the ImageLib class route, vtable type page, and scalar deleting destructor slot.

// UID:0000BY | by-class/ResourceLayoutTable.md | Completion:94 | Confidence:94
// [UID:0000BY] no class-level C++ body.
// UID00006E defines the real class and `typedef ImageLib ResourceLayoutTable`; this page preserves the non-virtual compatibility-facet method family and emits no independent class. Exact method children carry the source bodies.
// UID:0002KO | by-memory/0x004d0120-0x004d02e5.ResourceLayoutTableLoadResourceIndex.md | Completion:94 | Confidence:94
int ResourceLayoutTable::LoadResourceIndex(
    const wchar_t *resourceName)
{
    DATFile file;
    file.Open(resourceName);
    unsigned short header[4];
    int entryTableOffset;
    file.Read(header, sizeof(header));
    file.Read(&entryTableOffset, sizeof(entryTableOffset));
    file.Seek(entryTableOffset, 1);

    const int entryCount = header[0];
    ResourceLayoutEntry *entries =
        static_cast<ResourceLayoutEntry *>(
            GetMemoryMan()->AllocateBufferMemory(
                sizeof(ResourceLayoutEntry) * (entryCount + 1)));
    for (int index = 0; index < entryCount; ++index) {
        short top;
        short left;
        short bottom;
        short right;
        int pixelDataOffset;
        int encodedMaskOffset;
        file.Read(&top, sizeof(top));
        file.Read(&left, sizeof(left));
        file.Read(&bottom, sizeof(bottom));
        file.Read(&right, sizeof(right));
        file.Read(&pixelDataOffset, sizeof(pixelDataOffset));
        file.Read(&encodedMaskOffset, sizeof(encodedMaskOffset));

        InitRectBounds(
            reinterpret_cast<RectBounds *>(&entries[index]),
            left, top, right, bottom);
        entries[index].pixelData =
            reinterpret_cast<unsigned char *>(pixelDataOffset);
        entries[index].encodedMaskData =
            reinterpret_cast<unsigned char *>(encodedMaskOffset);
    }

    file.Seek(0, 0);
    unsigned char *payloadBase =
        static_cast<unsigned char *>(file.GetDataPointer()) + 12;
    for (int index = 0; index < entryCount; ++index) {
        entries[index].pixelData +=
            reinterpret_cast<unsigned int>(payloadBase);
        entries[index].encodedMaskData +=
            reinterpret_cast<unsigned int>(payloadBase);
    }
    InitRectBounds(
        reinterpret_cast<RectBounds *>(&entries[entryCount]),
        0, 0, 0, 0);
    entries[entryCount].pixelData = payloadBase + entryTableOffset;
    entries[entryCount].encodedMaskData =
        payloadBase + entryTableOffset;

    ResourceLayoutNameRecord record;
    wcscpy_s(record.name, 16, resourceName);
    record.entryCount = header[0];
    record.frameWidth = header[1];
    record.frameHeight = header[2];
    record.reservedHeaderWord = header[3];
    record.entries = entries;

    m_pEntryList->Append(1, &record);
    file.Close();
    return m_pEntryList->GetCount() - 1;
}

// UID:0002KP | by-memory/0x004d02f0-0x004d039e.ResourceLayoutTableLookupLayoutEntry.md | Completion:94 | Confidence:95
void ResourceLayoutTable::LookupLayoutEntry(
    const wchar_t *resourceName,
    int frameIndex,
    EPFTileContext *outContext)
{
    int resourceIndex = FindResourceIndex(resourceName);
    if (resourceIndex == -1)
        resourceIndex = LoadResourceIndex(resourceName);
    ResourceLayoutNameRecord *record =
        static_cast<ResourceLayoutNameRecord *>(
            m_pEntryList->GetElementAt(resourceIndex));
    ResourceLayoutEntry *entry = 0;
    if (frameIndex >= 0 && frameIndex < record->entryCount)
        entry = &record->entries[frameIndex];

    if (outContext != 0) {
        if (entry != 0) {
            outContext->pixelData = entry->pixelData;
            outContext->rowStridePixels =
                entry->right - entry->left;
            outContext->bounds =
                *reinterpret_cast<RectBounds *>(entry);
            outContext->encodedMaskByteCount =
                static_cast<int>(
                    record->entries[frameIndex + 1].pixelData -
                    entry->encodedMaskData);
            outContext->encodedMaskBytes = entry->encodedMaskData;
        } else {
            outContext->pixelData = 0;
            outContext->rowStridePixels = 0;
            InitRectBounds(&outContext->bounds, 0, 0, 0, 0);
            outContext->encodedMaskByteCount = 0;
            outContext->encodedMaskBytes = 0;
        }
    }
}

// UID:0002KR | by-memory/0x004d04d0-0x004d0522.ResourceLayoutTableCopyEntryTileContext.md | Completion:90 | Confidence:91
void ResourceLayoutTable::CopyEntryTileContext(
    const wchar_t *resourceName,
    int frameIndex,
    EPFTileContext *destination)
{
    EPFTileContext tileContext;

    LookupLayoutEntry(resourceName, frameIndex, &tileContext);

    if (destination != 0) {
        tileContext.CopyTo(destination);
    }
}

// UID:0002KS | by-memory/0x004d0530-0x004d059b.ResourceLayoutTableGetEntryRect.md | Completion:93 | Confidence:94
void ResourceLayoutTable::GetEntryRect(
    const wchar_t *resourceName,
    int frameIndex,
    RectBounds *bounds)
{
    int resourceIndex = FindResourceIndex(resourceName);
    if (resourceIndex == -1)
        resourceIndex = LoadResourceIndex(resourceName);
    ResourceLayoutNameRecord *record =
        static_cast<ResourceLayoutNameRecord *>(
            m_pEntryList->GetElementAt(resourceIndex));
    if (frameIndex >= 0 && frameIndex < record->entryCount) {
        *bounds = *reinterpret_cast<RectBounds *>(
            &record->entries[frameIndex]);
    } else {
        InitRectBounds(bounds, 0, 0, 0, 0);
    }
}

// UID:0002P6 | by-memory/0x004d1600-0x004d165d.LoadFrameDrawRecord.md | Completion:91 | Confidence:94
void ResourceLayoutTable::LoadFrameDrawRecord(
    const ArchiveMetadataTable *table,
    int frameIndex,
    FrameDrawRecord *outRecord)
{
    if (frameIndex < 0 || frameIndex >= table->frameCount) {
        outRecord->payloadStart = NULL;
        outRecord->payloadEnd = NULL;
        return;
    }

    const PackedArchiveRecord *record = &table->records[frameIndex];
    outRecord->payloadStart = record->payloadStart;
    outRecord->width = record->bounds.right - record->bounds.left;
    outRecord->sourceRect = record->bounds;
    outRecord->payloadEnd = record->payloadEnd;
    outRecord->payloadSpan =
        (int)(record[1].payloadStart - record->payloadEnd);
}

// UID:0002KU | by-memory/0x004d1730-0x004d1773.ResourceLayoutTableGetFrameSize.md | Completion:90 | Confidence:92
void ResourceLayoutTable::GetFrameSize(
    const wchar_t *resourceName,
    unsigned short *width,
    unsigned short *height)
{
    int resourceIndex = FindResourceIndex(resourceName);

    if (resourceIndex == -1) {
        resourceIndex = LoadResourceIndex(resourceName);
    }

    ResourceLayoutNameRecord *record =
        static_cast<ResourceLayoutNameRecord *>(m_pEntryList->GetElementAt(resourceIndex));

    *width = record->frameWidth;
    *height = record->frameHeight;
}

// UID:0002KV | by-memory/0x004d1780-0x004d17b3.ResourceLayoutTableGetEntryCount.md | Completion:90 | Confidence:93
unsigned short ResourceLayoutTable::GetEntryCount(const wchar_t *resourceName)
{
    int resourceIndex = FindResourceIndex(resourceName);

    if (resourceIndex == -1) {
        resourceIndex = LoadResourceIndex(resourceName);
    }

    ResourceLayoutNameRecord *record =
        static_cast<ResourceLayoutNameRecord *>(m_pEntryList->GetElementAt(resourceIndex));

    return record->entryCount;
}

// UID:0002KW | by-memory/0x004d17c0-0x004d182f.ResourceLayoutTableFindResourceIndex.md | Completion:93 | Confidence:95
int ResourceLayoutTable::FindResourceIndex(
    const wchar_t *resourceName)
{
    const int count = m_pEntryList->GetCount();
    ResourceLayoutNameRecord *record =
        static_cast<ResourceLayoutNameRecord *>(
            m_pEntryList->GetElementAt(0));
    for (int index = 0; index < count; ++index, ++record) {
        if (wcscmp(record->name, resourceName) == 0)
            return index;
    }
    return -1;
}

// UID:00054V | by-memory/0x004d1830-0x004d1860.ResourceLayoutTableGetEntry.md | Completion:92 | Confidence:93
ResourceLayoutEntry *ResourceLayoutTable::GetEntry(
    int resourceIndex,
    int frameIndex)
{
    ResourceLayoutNameRecord *record =
        static_cast<ResourceLayoutNameRecord *>(
            m_pEntryList->GetElementAt(resourceIndex));
    if (frameIndex < 0 || frameIndex >= record->entryCount)
        return 0;
    return &record->entries[frameIndex];
}

// UID:0001VT | by-type/by-struct/ResourceLayoutNameRecord.md | Completion:92 | Confidence:94
// ResourceLayoutNameRecord is declared once in ImageLib.h; no separate CPP definition.

// UID:0000QU | by-global/g_pEPFLib.md | Completion:89 | Confidence:88
// [UID:0000QU] no standalone global definition.
// UID00006E owns the sole declaration `extern ImageLib *g_pEPFLib`; this semantic page emits no duplicate definition. Constructor/destructor and storage children carry the concrete writes, clears, and address evidence, while ResourceLayoutTable remains a compatibility typedef/facet over ImageLib.
// UID:0001OQ | by-memory/0x0067a744-0x0067a748.g_pEPFLib.md | Completion:87 | Confidence:91
// [UID:0001OQ] no standalone C++ body.
// Exact storage for g_pEPFLib at 0x0067a744 is covered by the semantic global page and ImageLib lifecycle children.

// UID:0000VB | by-item/ResourceLayoutEntry.md | Completion:92 | Confidence:94
// ResourceLayoutEntry is declared once in ImageLib.h; no separate CPP definition.

// UID:00029J | by-memory/0x0069b420-0x0069b424.ImageLibraryLoadErrorFlag.md | Completion:91 | Confidence:94
bool g_imageLibraryLoadError = false;
