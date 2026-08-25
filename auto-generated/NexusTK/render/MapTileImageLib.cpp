// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000L5
// Source by-file doc: by-file/MapTileImageLib.md
// UID:00007T | by-class/MapTileImageLib.md | Completion:92 | Confidence:94
class MapTileImageLib : public LObject, public Singleton<MapTileImageLib>
{
public:
    MapTileImageLib();
    virtual ~MapTileImageLib();

    void DrawTile(void *drawTarget, const RectBounds *destinationRect, unsigned int tileId);

private:
    ArchiveMetadataTable *tileFrameTable;
    MapTileRecord *tileRecords;
};

// UID:0002IZ | by-memory/0x004d1860-0x004d199e.MapTileImageLibConstructor.md | Completion:92 | Confidence:94
MapTileImageLib::MapTileImageLib()
    : Singleton<MapTileImageLib>(),
      tileFrameTable(0),
      tileRecords(0)
{
    tileFrameTable = LoadTileEpfMetadata(L"TILE.EPF");

    DATFile tileTable;
    tileTable.Open(L"TILE.TBL");

    unsigned int tileCount = 0;
    tileTable.Read(&tileCount, sizeof(tileCount));

    if (tileFrameTable == 0 || tileCount != tileFrameTable->frameCount)
    {
        ShowFatalTileFileError(L"Error on Tile File!");
        return;
    }

    tileRecords = tileCount != 0 ? new MapTileRecord[tileCount] : 0;

    for (unsigned int index = 0; index < tileCount; ++index)
    {
        short packedRecord = 0;
        tileTable.Read(&packedRecord, sizeof(packedRecord));

        tileRecords[index].allowPaletteFilter = packedRecord < 0;
        tileRecords[index].paletteIndex =
            static_cast<unsigned short>(packedRecord & 0x7fff);
    }
}

// UID:000178 | by-memory/0x004d19a0-0x004d1a1c.MapTileImageLibDestructor.md | Completion:92 | Confidence:95
MapTileImageLib::~MapTileImageLib()
{
    MemoryManager *memory = GetMemoryMan();

    if (tileFrameTable != 0) {
        if (tileFrameTable->records != 0) {
            memory->Free(tileFrameTable->records);
        }

        memory->Free(tileFrameTable);
    }

    free(tileRecords);
}

// UID:0002J0 | by-memory/0x004d1a20-0x004d1b72.MapTileImageLibDrawTile.md | Completion:88 | Confidence:90
void MapTileImageLib::DrawTile(void *drawTarget,
                               const RectBounds *destinationRect,
                               unsigned int tileId)
{
    if (g_tileRenderingSuspended)
    {
        return;
    }

    const bool paletteFilterActive = PaletteLib_IsFilterActive(g_pPaletteLib);
    EPFTileContext tileContext;
    InitEPFTileContext(&tileContext);

    unsigned int resolvedTileId = tileId;
    if (!g_useTileEpfMetadata)
    {
        DATFile tileBounds;
        tileBounds.Open(L"TILE.TBD");

        unsigned int tileBoundsCount = 0;
        tileBounds.Read(&tileBoundsCount, sizeof(tileBoundsCount));

        if (resolvedTileId >= tileBoundsCount)
        {
            resolvedTileId = 0;
        }
    }

    if (resolvedTileId != 0)
    {
        LoadFrameDrawRecord(tileFrameTable, resolvedTileId, &tileContext);

        if (tileContext.payloadStart != 0)
        {
            const MapTileRecord *tileRecord = &tileRecords[resolvedTileId];
            if (!paletteFilterActive || tileRecord->allowPaletteFilter)
            {
                void *palette =
                    GetPaletteSlotPalette(g_pPaletteLib, 0, tileRecord->paletteIndex, 0);
                BlitTileFrame(&tileContext, destinationRect, 0, palette, 0);
            }
            return;
        }

        if (paletteFilterActive)
        {
            return;
        }
    }

    FillTileTarget(drawTarget, 128);
    DrawTileFallback(drawTarget, destinationRect);
}

// UID:0001V2 | by-type/by-struct/MapTileImageLibLayout.md | Completion:92 | Confidence:96
// No separate layout C++ should be emitted for [UID:0001V2].
// The MapTileImageLib declaration emitted by [UID:00007T][MapTileImageLib](by-class/MapTileImageLib.md) owns the
// LObject base at +0x00, empty Singleton<MapTileImageLib> base at +0x04,
// ArchiveMetadataTable pointer at +0x04, and MapTileRecord pointer at +0x08.
// Direct RTTI PMD +0x04 and the 0x0c complete size prove EBO overlap.

// UID:0001V3 | by-type/by-struct/MapTileRecord.md | Completion:88 | Confidence:91
struct MapTileRecord
{
    unsigned short paletteIndex;
    unsigned char allowPaletteFilter;
    unsigned char reserved;
};

// UID:0001Y3 | by-type/by-vtable/MapTileImageLibVtable.md | Completion:92 | Confidence:96
// No handwritten vtable or RTTI data should be emitted for [UID:0001Y3].
// The MapTileImageLib declaration, virtual destructor, and direct empty
// Singleton<MapTileImageLib> base regenerate the three-slot vtable and
// three-entry MapTileImageLib/LObject/Singleton class hierarchy.

// UID:0000RG | by-global/g_pMapTileImageLib.md | Completion:91 | Confidence:94
MapTileImageLib *g_pMapTileImageLib = 0;

// UID:0000V0 | by-item/LoadTileEpfMetadata_004D1B80.md | Completion:86 | Confidence:90
// LoadTileEpfMetadata is emitted by the exact function page [UID:0002J1][0x004d1b80-0x004d1f22.LoadTileEpfMetadata](by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md).
// This by-item page is an alias/index for 0x004d1b80 and must not duplicate
// the helper body in MapTileImageLib.cpp.

// UID:0002J1 | by-memory/0x004d1b80-0x004d1f22.LoadTileEpfMetadata.md | Completion:89 | Confidence:92
ArchiveMetadataTable *LoadTileEpfMetadata(const wchar_t *unusedArchiveName)
{
    (void)unusedArchiveName;

    struct TileArchiveShardHeader
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
        swprintf(archiveName, 20, L"TILE%d.EPF", shardCount);
        if (!HasDATEntry(archiveName))
        {
            break;
        }
        ++shardCount;
    }

    TileArchiveShardHeader *headers =
        shardCount > 0 ? new TileArchiveShardHeader[shardCount] : 0;
    DATFile *archives = shardCount > 0 ? new DATFile[shardCount] : 0;

    ArchiveMetadataTable *table = new ArchiveMetadataTable;
    table->frameCount = 0;
    table->maxWidth = 0;
    table->maxHeight = 0;
    table->reserved = 0;
    table->records = 0;

    for (int i = 0; i < shardCount; ++i)
    {
        swprintf(archiveName, 20, L"TILE%d.EPF", i);
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
