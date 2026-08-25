// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000O7
// Source by-file doc: by-file/StaticObjImageLib.md
// UID:0000E2 | by-class/StaticObjImageLib.md | Completion:92 | Confidence:96
#include "StaticObjImageLib.h"
#include "ImageFrameTable.h"
#include "../util/MemoryMan.h"
#include <stdlib.h>

// UID:00017I | by-memory/0x004dd1e0-0x004dd2be.StaticObjImageLibDestructor.md | Completion:92 | Confidence:96
StaticObjImageLib::~StaticObjImageLib()
{
    MemoryMan *memoryMan = GetMemoryMan();

    if (staticObjEntries != 0) {
        for (int index = 0; index < staticObjCount; ++index) {
            StaticObjEntry *entry = staticObjEntries[index];
            StaticObjEntry *cacheNode = entry->cacheChain;

            if (cacheNode != 0) {
                entry->cacheChain = 0;

                while (cacheNode != 0) {
                    StaticObjEntry *nextNode = cacheNode->cacheChain;
                    memoryMan->FreeBufferMemory(cacheNode);
                    cacheNode = nextNode;
                }
            } else {
                memoryMan->FreeBufferMemory(entry);
            }
        }

        memoryMan->FreeBufferMemory(staticObjEntries);
    }

    ArchiveMetadataTable *catalog = tileCatalog;
    MemoryMan *catalogMemoryMan = GetMemoryMan();
    if (catalog->records != 0) {
        catalogMemoryMan->FreeBufferMemory(catalog->records);
    }
    catalogMemoryMan->FreeBufferMemory(catalog);

    free(tileClasses);
}





// UID:0000SD | by-global/g_pStaticObjImageLib.md | Completion:92 | Confidence:96
StaticObjImageLib *g_pStaticObjImageLib = 0;

// UID:0000U6 | by-item/BuildTilecArchiveTable_004DDA60.md | Completion:89 | Confidence:91
ArchiveMetadataTable *BuildTilecArchiveTable(const wchar_t *unusedArchiveName)
{
    (void)unusedArchiveName;

    struct TilecArchiveShardHeader
    {
        unsigned short frameCount;
        unsigned short maxWidth;
        unsigned short maxHeight;
        unsigned short reserved;
    };

    int shardCount = 0;
    wchar_t archiveName[20];
    while (shardCount < 100)
    {
        swprintf(archiveName, 20, L"TILEC%d.EPF", shardCount);
        if (!HasDATEntry(archiveName))
        {
            break;
        }
        ++shardCount;
    }

    TilecArchiveShardHeader *headers =
        shardCount > 0 ? new TilecArchiveShardHeader[shardCount] : 0;
    DATFile *archives = shardCount > 0 ? new DATFile[shardCount] : 0;

    ArchiveMetadataTable *table = new ArchiveMetadataTable;
    table->frameCount = 0;
    table->maxWidth = 0;
    table->maxHeight = 0;
    table->reserved = 0;
    table->records = 0;

    for (int i = 0; i < shardCount; ++i)
    {
        swprintf(archiveName, 20, L"TILEC%d.EPF", i);
        archives[i].Open(archiveName);
        archives[i].Read(&headers[i], 8);

        table->frameCount =
            static_cast<unsigned short>(table->frameCount + headers[i].frameCount);
        if (table->maxWidth < headers[i].maxWidth)
        {
            table->maxWidth = headers[i].maxWidth;
        }
        if (table->maxHeight < headers[i].maxHeight)
        {
            table->maxHeight = headers[i].maxHeight;
        }
    }

    table->records = new PackedArchiveRecord[table->frameCount + 1];
    PackedArchiveRecord *outRecord = table->records;
    unsigned char *lastPayloadBase = 0;
    int lastRecordTableOffset = 0;

    for (int i = 0; i < shardCount; ++i)
    {
        int recordTableOffset = 0;
        archives[i].Read(&recordTableOffset, sizeof(recordTableOffset));

        unsigned char *payloadBase = archives[i].GetDataPointer();
        lastPayloadBase = payloadBase;
        lastRecordTableOffset = recordTableOffset;

        archives[i].Seek(recordTableOffset, 1);

        for (int recordIndex = 0; recordIndex < headers[i].frameCount; ++recordIndex)
        {
            short top = 0;
            short left = 0;
            short bottom = 0;
            short right = 0;
            int payloadStartOffset = 0;
            int payloadEndOffset = 0;

            archives[i].Read(&top, sizeof(top));
            archives[i].Read(&left, sizeof(left));
            archives[i].Read(&bottom, sizeof(bottom));
            archives[i].Read(&right, sizeof(right));
            archives[i].Read(&payloadStartOffset, sizeof(payloadStartOffset));
            archives[i].Read(&payloadEndOffset, sizeof(payloadEndOffset));

            InitRectBounds(&outRecord->bounds, left, top, right, bottom);
            outRecord->payloadStart = payloadBase + payloadStartOffset;
            outRecord->payloadEnd = payloadBase + payloadEndOffset;
            ++outRecord;
        }
    }

    InitRectBounds(&outRecord->bounds, 0, 0, 0, 0);
    outRecord->payloadStart =
        lastPayloadBase != 0 ? lastPayloadBase + lastRecordTableOffset : 0;
    outRecord->payloadEnd =
        lastPayloadBase != 0 ? lastPayloadBase + lastRecordTableOffset : 0;

    for (int i = shardCount - 1; i >= 0; --i)
    {
        archives[i].Close();
    }

    delete [] archives;
    delete [] headers;

    return table;
}

// UID:00017J | by-memory\0x004dd2c0-0x004dd84a.StaticObjImageLibRenderStaticObject.md | Completion:88 | Confidence:90 | Empty Emitter Marker

// UID:0001W8 | by-type\by-struct\StaticObjEntry.md | Completion:90 | Confidence:94 | Empty Emitter Marker

// UID:0001W9 | by-type\by-struct\StaticObjImageLibLayout.md | Completion:92 | Confidence:97 | Empty Emitter Marker

// UID:0001WC | by-type\by-struct\TileClassEntry.md | Completion:90 | Confidence:95 | Empty Emitter Marker
