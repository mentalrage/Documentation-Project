// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000K1
// Source by-file doc: by-file/ImageFrameTable.md
// UID:0002P4 | by-memory/0x004d0f50-0x004d15c5.LoadImageFrameTable.md | Completion:89 | Confidence:92
ArchiveMetadataTable *LoadImageFrameTable(const wchar_t *resourcePath, int mergeMode)
{
    struct ImageArchiveShardHeader
    {
        unsigned short frameCount;
        unsigned short maxWidth;
        unsigned short maxHeight;
        unsigned short reserved;
    };

    if (mergeMode == 0)
    {
        DATFile archive;
        ArchiveMetadataTable *table = new ArchiveMetadataTable;

        archive.Open(resourcePath);
        archive.Read(table, 8);

        int recordTableOffset = 0;
        archive.Read(&recordTableOffset, sizeof(recordTableOffset));

        unsigned char *payloadBase = archive.GetDataPointer();
        archive.Seek(recordTableOffset, 1);

        table->records = new PackedArchiveRecord[table->frameCount + 1];
        PackedArchiveRecord *record = table->records;

        for (unsigned int index = 0; index < table->frameCount; ++index, ++record)
        {
            short top = 0;
            short left = 0;
            short bottom = 0;
            short right = 0;
            unsigned int payloadStart = 0;
            unsigned int payloadEnd = 0;

            archive.Read(&top, sizeof(top));
            archive.Read(&left, sizeof(left));
            archive.Read(&bottom, sizeof(bottom));
            archive.Read(&right, sizeof(right));
            archive.Read(&payloadStart, sizeof(payloadStart));
            archive.Read(&payloadEnd, sizeof(payloadEnd));

            InitRectBounds(&record->bounds, top, left, bottom, right);
            record->payloadStart = payloadBase + payloadStart;
            record->payloadEnd = payloadBase + payloadEnd;
        }

        InitRectBounds(&record->bounds, 0, 0, 0, 0);
        record->payloadStart = payloadBase + recordTableOffset;
        record->payloadEnd = payloadBase + recordTableOffset;

        archive.Close();
        return table;
    }

    const wchar_t *prefix = 0;
    switch (mergeMode)
    {
    case 1:
        prefix = L"HEAD";
        break;
    case 2:
        prefix = L"HEADSP";
        break;
    case 3:
        prefix = L"BODY";
        break;
    case 4:
        prefix = L"SWORD";
        break;
    case 5:
        prefix = L"SPEAR";
        break;
    case 6:
        prefix = L"BOW";
        break;
    case 7:
        prefix = L"FAN";
        break;
    case 8:
        prefix = L"SHIELD";
        break;
    case 9:
        prefix = L"ARROW";
        break;
    case 10:
        prefix = L"FACE";
        break;
    case 11:
        prefix = L"HAIR";
        break;
    case 12:
        prefix = L"ACE1";
        break;
    case 13:
        prefix = L"ACE2";
        break;
    case 14:
        prefix = L"HELMET";
        break;
    case 15:
        prefix = L"MANTLE";
        break;
    case 16:
        prefix = L"NECLACE";
        break;
    case 17:
        prefix = L"SHOES";
        break;
    case 18:
        prefix = L"COAT";
        break;
    default:
        return 0;
    }

    int shardCount = 0;
    wchar_t archiveName[20];
    while (shardCount < 100)
    {
        swprintf(archiveName, 20, L"%s%d.EPF", prefix, shardCount);
        if (!HasDATEntry(archiveName))
            break;
        ++shardCount;
    }

    ImageArchiveShardHeader *headers = shardCount != 0 ? new ImageArchiveShardHeader[shardCount] : 0;
    DATFile *archives = shardCount != 0 ? new DATFile[shardCount] : 0;
    ArchiveMetadataTable *table = new ArchiveMetadataTable;
    table->frameCount = 0;
    table->maxWidth = 0;
    table->maxHeight = 0;
    table->reserved = 0;
    table->records = 0;

    for (int shardIndex = 0; shardIndex < shardCount; ++shardIndex)
    {
        swprintf(archiveName, 20, L"%s%d.EPF", prefix, shardIndex);
        archives[shardIndex].Open(archiveName);
        archives[shardIndex].Read(&headers[shardIndex], 8);

        table->frameCount += headers[shardIndex].frameCount;
        if (table->maxWidth < headers[shardIndex].maxWidth)
            table->maxWidth = headers[shardIndex].maxWidth;
        if (table->maxHeight < headers[shardIndex].maxHeight)
            table->maxHeight = headers[shardIndex].maxHeight;
    }

    table->records = new PackedArchiveRecord[table->frameCount + 1];
    PackedArchiveRecord *record = table->records;
    unsigned char *lastPayloadBase = 0;
    int lastRecordTableOffset = 0;

    for (int shardIndex = 0; shardIndex < shardCount; ++shardIndex)
    {
        int recordTableOffset = 0;
        archives[shardIndex].Read(&recordTableOffset, sizeof(recordTableOffset));

        unsigned char *payloadBase = archives[shardIndex].GetDataPointer();
        archives[shardIndex].Seek(recordTableOffset, 1);

        for (unsigned int frameIndex = 0; frameIndex < headers[shardIndex].frameCount; ++frameIndex, ++record)
        {
            short top = 0;
            short left = 0;
            short bottom = 0;
            short right = 0;
            unsigned int payloadStart = 0;
            unsigned int payloadEnd = 0;

            archives[shardIndex].Read(&top, sizeof(top));
            archives[shardIndex].Read(&left, sizeof(left));
            archives[shardIndex].Read(&bottom, sizeof(bottom));
            archives[shardIndex].Read(&right, sizeof(right));
            archives[shardIndex].Read(&payloadStart, sizeof(payloadStart));
            archives[shardIndex].Read(&payloadEnd, sizeof(payloadEnd));

            InitRectBounds(&record->bounds, top, left, bottom, right);
            record->payloadStart = payloadBase + payloadStart;
            record->payloadEnd = payloadBase + payloadEnd;
        }

        lastPayloadBase = payloadBase;
        lastRecordTableOffset = recordTableOffset;
    }

    InitRectBounds(&record->bounds, 0, 0, 0, 0);
    record->payloadStart = lastPayloadBase + lastRecordTableOffset;
    record->payloadEnd = lastPayloadBase + lastRecordTableOffset;

    for (int shardIndex = shardCount - 1; shardIndex >= 0; --shardIndex)
        archives[shardIndex].Close();

    delete [] archives;
    delete [] headers;
    return table;
}

// UID:0002P5 | by-memory/0x004d15d0-0x004d15fc.DestroyOwnedImageBlock.md | Completion:88 | Confidence:92
void DestroyOwnedImageBlock(ArchiveMetadataTable *block)
{
    GetMemoryMan();

    if (block->records != NULL) {
        FreeBufferMemory(block->records);
    }

    FreeBufferMemory(block);
}

// UID:00031T | by-memory/0x004d1660-0x004d1704.FrameRecordPayloadCopyHelper.md | Completion:88 | Confidence:90
void CopyFrameRecordPayloads(const ArchiveMetadataTable *table,
                             int frameIndex,
                             FrameDrawRecord *outRecord)
{
    MemoryMan *memoryMan = GetMemoryMan();

    if (frameIndex < 0 || frameIndex >= table->frameCount) {
        outRecord->payloadStart = NULL;
        outRecord->payloadEnd = NULL;
        return;
    }

    const PackedArchiveRecord *record = &table->records[frameIndex];
    const int firstSpan = (int)(record->payloadEnd - record->payloadStart);
    const int secondSpan = (int)(record[1].payloadStart - record->payloadEnd);

    outRecord->payloadStart =
        (unsigned char *)memoryMan->AllocateBufferMemory(firstSpan);
    memoryMan->MemmoveWrapper(outRecord->payloadStart,
                              record->payloadStart,
                              firstSpan);

    outRecord->width = record->bounds.right - record->bounds.left;
    outRecord->sourceRect = record->bounds;

    outRecord->payloadEnd =
        (unsigned char *)memoryMan->AllocateBufferMemory(secondSpan);
    memoryMan->MemmoveWrapper(outRecord->payloadEnd,
                              record->payloadEnd,
                              secondSpan);
    outRecord->payloadSpan = secondSpan;
}

// UID:00031U | by-memory/0x004d1710-0x004d172d.FrameRecordRectCopyHelper.md | Completion:88 | Confidence:90
void CopyFrameRecordBounds(const ArchiveMetadataTable *table,
                           int frameIndex,
                           RectBounds *outBounds)
{
    const PackedArchiveRecord *record = &table->records[frameIndex];
    *outBounds = record->bounds;
}

// UID:0000UN | by-item\EPFArchiveMetadataTable.md | Completion:90 | Confidence:92 | Empty Emitter Marker
