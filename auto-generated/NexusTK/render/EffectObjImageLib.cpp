// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000IY
// Source by-file doc: by-file/EffectObjImageLib.md
// UID:0001U7 | by-type/by-struct/EffectFrameRecord.md | Completion:88 | Confidence:90
struct EffectFrameRecord
{
    int frameResourceId;
    int timerDelayAndRenderArg;
    float renderScalar;
    int lightingAndRenderArg;
};

// UID:0001U8 | by-type/by-struct/EffectInfo.md | Completion:88 | Confidence:90
struct EffectInfo
{
    int effectKeyOrId;
    EffectFrameRecord *primaryFrames;
    int primaryUnknown0;
    unsigned char primaryFlagOrReserved;
    unsigned char primaryPadding[3];
    int primaryFrameCount;
    int primaryRangeStart;
    int primaryRangeEnd;
    EffectFrameRecord *secondaryFrames;
    int secondaryUnknown0;
    unsigned char secondaryFlagOrReserved;
    unsigned char secondaryPadding[3];
    int secondaryFrameCount;
    int secondaryRangeStart;
    int secondaryRangeEnd;
};

// UID:0001UA | by-type/by-struct/EffectPixMapInfo.md | Completion:87 | Confidence:91
struct EffectPixMapInfo
{
    int frameRemapOrPaletteSlot;
};

// UID:0000QT | by-global/g_pEffectObjImageLib.md | Completion:92 | Confidence:94
class EffectObjImageLib;

EffectObjImageLib *g_pEffectObjImageLib = 0;

// UID:00004A | by-class/EffectObjImageLib.md | Completion:92 | Confidence:94
class IntAlphaSurface;
class MapPane;
struct ArchiveMetadataTable;
struct RectBounds;

ArchiveMetadataTable *BuildEffectArchiveTable(const wchar_t *unusedArchiveName);

class EffectObjImageLib;
extern EffectObjImageLib *g_pEffectObjImageLib;

class EffectObjImageLib : public LObject, public Singleton<EffectObjImageLib>
{
public:
    EffectObjImageLib();
    virtual ~EffectObjImageLib();

    int RenderEffectFrame(
        MapPane *mapPaneOrRenderContext,
        RectBounds *destinationBounds,
        int frameResourceId,
        int timerDelayAndRenderArg,
        float renderScalar,
        int lightingAndRenderArg,
        IntAlphaSurface *overlayMaskGate,
        float overlayStrength);
    EffectInfo *GetEffectInfo(EffectInfo *outInfo, int effectId);

private:
    void LoadEffectTables();

    ProtectedArray<EffectInfo> effectInfoArray;
    EffectInfo effectInfoScratch;
    ProtectedArray<EffectPixMapInfo> effectPixMapInfoArray;
    EffectPixMapInfo fallbackFrameRemap;
    ArchiveMetadataTable *effectFileInfo;
};

// UID:0002H9 | by-memory/0x004ddf60-0x004de04e.EffectObjImageLibConstructor.md | Completion:92 | Confidence:94
EffectObjImageLib::EffectObjImageLib()
    : LObject(),
      Singleton<EffectObjImageLib>(),
      effectInfoArray(10),
      effectPixMapInfoArray(10),
      effectFileInfo(0)
{
    LoadEffectTables();

    effectFileInfo = BuildEffectArchiveTable(L"EFFECT.EPF");
    if (effectPixMapInfoArray.count < effectFileInfo->frameCount)
    {
        DestroyDATFileMgr();
        DestroyExceptionHandler();
        MessageBoxW(0, L"Error on Effect File!", L"Data Error", MB_ICONEXCLAMATION);
        __loaddll(0);
    }
}

// UID:00017L | by-memory/0x004de050-0x004de189.EffectObjImageLibDestructor.md | Completion:92 | Confidence:94
EffectObjImageLib::~EffectObjImageLib()
{
    for (int i = 0; i < effectInfoArray.count; ++i)
    {
        EffectInfo *info = &effectInfoArray.entries[i];

        if (info->secondaryFrames != 0)
        {
            delete [] info->secondaryFrames;
        }
        info->secondaryFrames = 0;
        info->secondaryFrameCount = 0;
        info->secondaryRangeStart = -1;
        info->secondaryRangeEnd = -1;

        if (info->primaryFrames != 0)
        {
            delete [] info->primaryFrames;
        }
        info->primaryFrames = 0;
        info->primaryFrameCount = 0;
        info->primaryRangeStart = -1;
        info->primaryRangeEnd = -1;
    }

    if (effectFileInfo != 0)
    {
        if (effectFileInfo->records != 0)
        {
            delete [] effectFileInfo->records;
        }
        delete effectFileInfo;
        effectFileInfo = 0;
    }
}

// UID:00017M | by-memory/0x004de190-0x004de29f.EffectObjImageLibRenderEffectFrame.md | Completion:88 | Confidence:91
int EffectObjImageLib::RenderEffectFrame(
    MapPane *mapPaneOrRenderContext,
    RectBounds *destinationBounds,
    int frameResourceId,
    int timerDelayAndRenderArg,
    float renderScalar,
    int lightingAndRenderArg,
    IntAlphaSurface *overlayMaskGate,
    float overlayStrength)
{
    (void)mapPaneOrRenderContext;
    (void)timerDelayAndRenderArg;
    (void)lightingAndRenderArg;

    int result = reinterpret_cast<int>(overlayMaskGate);
    if (g_imageLibraryLoadErrorFlag)
    {
        return result;
    }

    const EffectPixMapInfo *remap = &fallbackFrameRemap;
    if (frameResourceId >= 0 && frameResourceId < effectPixMapInfoArray.count)
    {
        remap = &effectPixMapInfoArray.entries[frameResourceId];
    }

    FrameDrawRecord frameRecord;
    frameRecord.reserved0 = 1;
    frameRecord.payloadStart = 0;
    frameRecord.reserved8 = 0;
    frameRecord.width = 0;
    InitRectBounds(&frameRecord.sourceRect, 0, 0, 0, 0);
    frameRecord.payloadSpan = 0;
    frameRecord.payloadEnd = 0;

    LoadFrameDrawRecord(effectFileInfo, static_cast<short>(frameResourceId), &frameRecord);

    void *palette = g_pPaletteLib->GetSlotPalette(11, remap->frameRemapOrPaletteSlot, 0);

    struct EffectRenderAlphaParams
    {
        unsigned char enabled;
        float scalar;
    };

    EffectRenderAlphaParams alphaParams;
    EffectRenderAlphaParams *alphaParamsPtr = 0;
    if (renderScalar > 0.0f)
    {
        alphaParams.enabled = 1;
        alphaParams.scalar = renderScalar;
        alphaParamsPtr = &alphaParams;
    }

    result = g_surfaceRenderCallbacks.primaryFrameBlit(
        &frameRecord,
        &frameRecord.sourceRect,
        destinationBounds,
        1,
        palette,
        alphaParamsPtr);

    if (overlayMaskGate != 0)
    {
        const unsigned char overlayByte =
            static_cast<unsigned char>(overlayStrength * 32.0f + 0.5f);

        return DrawEncodedAlphaFrame(
            overlayMaskGate,
            destinationBounds,
            &frameRecord,
            &frameRecord.sourceRect,
            destinationBounds->bottom,
            overlayByte,
            destinationBounds->top,
            0,
            1);
    }

    return result;
}

// UID:0002HA | by-memory/0x004de3e0-0x004de420.EffectObjImageLibGetEffectInfo.md | Completion:90 | Confidence:93
EffectInfo *EffectObjImageLib::GetEffectInfo(EffectInfo *outInfo, int effectId)
{
    const int index = effectId - 1;
    if (index < 0 || index >= effectInfoArray.count)
    {
        *outInfo = effectInfoScratch;
    }
    else
    {
        *outInfo = effectInfoArray.entries[index];
    }

    return outInfo;
}

// UID:0002HB | by-memory/0x004de7d0-0x004dec23.EffectObjImageLibLoadEffectTables.md | Completion:90 | Confidence:91
void EffectObjImageLib::LoadEffectTables()
{
    EffectInfo emptyInfo = {};
    effectInfoScratch = emptyInfo;

    DATFile effectTable;
    effectTable.Open(L"EFFECT.TBL");

    int effectCount = 0;
    if (!effectTable.ReadEncodedTableInt(&effectCount))
    {
        g_imageLibraryLoadErrorFlag = 1;
    }

    if (effectCount > 0)
    {
        effectInfoArray.Resize(effectCount);
    }

    for (int i = 0; i < effectCount; ++i)
    {
        EffectInfo info = {};

        int descriptorReads = 0;
        descriptorReads += effectTable.ReadEncodedTableInt(&info.effectKeyOrId);
        descriptorReads += effectTable.ReadEncodedTableInt(&info.secondaryFrameCount);
        descriptorReads += effectTable.ReadEncodedTableInt(&info.secondaryRangeStart);
        descriptorReads += effectTable.ReadEncodedTableInt(&info.secondaryRangeEnd);
        descriptorReads += effectTable.ReadEncodedTableInt(&info.primaryFrameCount);
        descriptorReads += effectTable.ReadEncodedTableInt(&info.primaryRangeStart);
        descriptorReads += effectTable.ReadEncodedTableInt(&info.primaryRangeEnd);
        if (descriptorReads != 7)
        {
            g_imageLibraryLoadErrorFlag = 1;
        }

        if (info.secondaryFrameCount > 0)
        {
            info.secondaryFrames = new EffectFrameRecord[info.secondaryFrameCount];
            for (int frame = 0; frame < info.secondaryFrameCount; ++frame)
            {
                EffectFrameRecord *record = &info.secondaryFrames[frame];
                int frameReads = 0;
                frameReads += effectTable.ReadEncodedTableInt(&record->frameResourceId);
                frameReads += effectTable.ReadEncodedTableInt(&record->timerDelayAndRenderArg);
                frameReads += effectTable.ReadEncodedTableFloat(&record->renderScalar);
                frameReads += effectTable.ReadEncodedTableInt(&record->lightingAndRenderArg);
                if (frameReads != 4)
                {
                    g_imageLibraryLoadErrorFlag = 1;
                }
            }
        }

        if (info.primaryFrameCount > 0)
        {
            info.primaryFrames = new EffectFrameRecord[info.primaryFrameCount];
            for (int frame = 0; frame < info.primaryFrameCount; ++frame)
            {
                EffectFrameRecord *record = &info.primaryFrames[frame];
                int frameReads = 0;
                frameReads += effectTable.ReadEncodedTableInt(&record->frameResourceId);
                frameReads += effectTable.ReadEncodedTableInt(&record->timerDelayAndRenderArg);
                frameReads += effectTable.ReadEncodedTableFloat(&record->renderScalar);
                frameReads += effectTable.ReadEncodedTableInt(&record->lightingAndRenderArg);
                if (frameReads != 4)
                {
                    g_imageLibraryLoadErrorFlag = 1;
                }
            }
        }

        if (i >= 0 && i < effectInfoArray.count)
        {
            effectInfoArray.entries[i] = info;
        }
        else
        {
            effectInfoScratch = info;
        }
    }

    fallbackFrameRemap.frameRemapOrPaletteSlot = -1;

    DATFile frameTable;
    frameTable.Open(L"EFFECT.FRM");

    int frameRemapCount = 0;
    frameTable.Read(&frameRemapCount, sizeof(frameRemapCount));
    if (frameRemapCount > 0)
    {
        effectPixMapInfoArray.Resize(frameRemapCount);
    }

    for (int i = 0; i < frameRemapCount; ++i)
    {
        EffectPixMapInfo *remap =
            (i >= 0 && i < effectPixMapInfoArray.count)
                ? &effectPixMapInfoArray.entries[i]
                : &fallbackFrameRemap;
        frameTable.Read(remap, sizeof(*remap));
    }

    frameTable.Close();
    effectTable.Close();
}

// UID:0000U4 | by-item/BuildEffectArchiveTable_004DE420.md | Completion:89 | Confidence:92
ArchiveMetadataTable *BuildEffectArchiveTable(const wchar_t *unusedArchiveName)
{
    (void)unusedArchiveName;

    struct EffectArchiveShardHeader
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
        swprintf(archiveName, 20, L"EFFECT%d.EPF", shardCount);
        if (!HasDATEntry(archiveName))
        {
            break;
        }
        ++shardCount;
    }

    EffectArchiveShardHeader *headers =
        shardCount > 0 ? new EffectArchiveShardHeader[shardCount] : 0;
    DATFile *archives = shardCount > 0 ? new DATFile[shardCount] : 0;

    ArchiveMetadataTable *table = new ArchiveMetadataTable;
    table->frameCount = 0;
    table->maxWidth = 0;
    table->maxHeight = 0;
    table->reserved = 0;
    table->records = 0;

    for (int i = 0; i < shardCount; ++i)
    {
        swprintf(archiveName, 20, L"EFFECT%d.EPF", i);
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

// UID:0000UR | by-item/GetSpriteBounds_004DE2A0.md | Completion:88 | Confidence:91
RectBounds *GetSpriteBounds(
    int frameResourceId,
    int timerDelayAndRenderArg,
    float renderScalar,
    int lightingAndRenderArg,
    RectBounds *outBounds)
{
    (void)timerDelayAndRenderArg;
    (void)renderScalar;
    (void)lightingAndRenderArg;

    if (frameResourceId < 0)
    {
        InitRectBounds(outBounds, 0, 0, 0, 0);
        return outBounds;
    }

    if (g_useEpfAssets == 1)
    {
        wchar_t archiveName[20];
        swprintf(archiveName, 20, L"EFFECT%d.EPF", frameResourceId / 200);
        ResourceLayoutTableGetEntryRect(
            g_pEPFLib,
            archiveName,
            static_cast<short>(frameResourceId % 200),
            outBounds);
    }
    else
    {
        ResourceLayoutTableGetEntryRect(
            g_pEPFLib,
            L"EFFECT.EPD",
            static_cast<short>(frameResourceId),
            outBounds);
    }

    OffsetRectBounds(outBounds, g_mapTilePixelWidth / 2, g_mapTilePixelHeight / 2);
    return outBounds;
}
