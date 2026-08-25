// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000L3
// Source by-file doc: by-file/MapPane.md
// UID:00007S | by-class/MapRefreshDimmer.md | Completion:93 | Confidence:94
#include "ScreenDimmer.h"
#include "ScreenPane.h"

class Event;

class MapRefreshDimmer : public ScreenDimmer
{
public:
    MapRefreshDimmer();

    virtual bool HandlePacketEvent(Event *event);
    virtual bool OnTimer(int timerId, int arg0, int arg1);
};

// UID:0002I1 | by-memory/0x00503e80-0x00503e8b.MapPaneHasEffectListEntries.md | Completion:87 | Confidence:91
bool MapPane::HasScreenEffecters() const
{
    return m_screenEffecterCount > 0;
}

// UID:0002I2 | by-memory/0x00503e90-0x00503ecd.MapPaneFindActiveEffect.md | Completion:87 | Confidence:90
ScreenEffecter *MapPane::FindActivePixelEffecter()
{
    for (int index = 0; index < m_screenEffecterCount; ++index) {
        ScreenEffecter *effecter = m_screenEffecters[index];
        if (effecter->IsPixelEffecter()) {
            return effecter;
        }
    }

    return nullptr;
}

// UID:0002I3 | by-memory/0x00503ed0-0x00503eef.MapPaneResetEffectListFields.md | Completion:87 | Confidence:91
void MapPane::ResetScreenEffecterListFields()
{
    m_screenEffecters = NULL;
    m_screenEffecterCount = 0;
    m_screenEffecterCapacity = 0;
}

// UID:0002I4 | by-memory/0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md | Completion:88 | Confidence:91
void MapPane::ConfigureScreenEffecterList(signed char effectMode)
{
    enum {
        kMapScreenEffectRedWave = 1,
        kMapScreenEffectWaterFilter = 2,
        kMapScreenEffecterCapacity = 10
    };

    ClearScreenEffecterList();

    if (effectMode == kMapScreenEffectWaterFilter) {
        m_screenEffecters = new ScreenEffecter *[kMapScreenEffecterCapacity];
        m_screenEffecterCount = 1;
        m_screenEffecterCapacity = kMapScreenEffecterCapacity;
        m_screenEffecters[0] = new WaterFilterEffecter();
        return;
    }

    if (effectMode == kMapScreenEffectRedWave) {
        m_screenEffecters = new ScreenEffecter *[kMapScreenEffecterCapacity];
        m_screenEffecterCount = 2;
        m_screenEffecterCapacity = kMapScreenEffecterCapacity;

        m_screenEffecters[0] = new XWaveEffecter(
            g_mapTilePixelWidth * 6,
            g_mapTilePixelHeight / 10.0f,
            7500);
        m_screenEffecters[1] = new SolidColorFilterEffecter(255, 0, 0, 0.6f);
    }
}

// UID:0001AP | by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md | Completion:90 | Confidence:91
// Emitted code for this aggregate is covered by exact child pages nested under [UID:0001AP].
// [UID:0001AP] is a MapPane source-range aggregate/index, not a monolithic source function.
// Exact child pages own the MapPane.cpp method/helper bodies, jump tables, raw no-route evidence, and alignment classification.

// UID:0002I6 | by-memory/0x005040a0-0x00504102.MapPaneClearEffectList.md | Completion:88 | Confidence:91
void MapPane::ClearScreenEffecterList()
{
    if (m_screenEffecterCount > 0) {
        for (int index = 0; index < m_screenEffecterCount; ++index) {
            ScreenEffecter *effecter = m_screenEffecters[index];
            if (effecter != NULL) {
                delete effecter;
            }
        }

        delete[] m_screenEffecters;
    }

    m_screenEffecters = NULL;
    m_screenEffecterCount = 0;
    m_screenEffecterCapacity = 0;
}

// UID:0002I7 | by-memory/0x00504110-0x00504521.MapPaneInitialize.md | Completion:89 | Confidence:91
MapPane::MapPane(int visibleTileColumns, int visibleTileRows)
    : Pane(0),
      m_viewportGrafPort(),
      m_screenEffecters(NULL),
      m_screenEffecterCount(0),
      m_screenEffecterCapacity(0),
      m_selectionOverlay(NULL),
      m_tileBuffer(NULL),
      m_visibleTileColumns(visibleTileColumns),
      m_visibleTileRows(visibleTileRows),
      m_localPlayerObjectPane(NULL),
      m_auxiliaryPane(NULL),
      m_activeScreenLayer(NULL),
      m_objectList(NULL)
{
    g_activeMapPane = this;

    m_mapId = 0;
    m_mapWidth = 0;
    m_mapHeight = 0;
    m_mapFlashColor = 0;
    m_mapRuntimeMode = 0;
    m_visibleObjectRefreshPending = false;
    m_refreshWholeVisibleMap = false;
    m_zoneMusicId = 0;
    m_zoneMusicFallbackTrackIndex = 0;
    m_zoneMusicVolumeScale = 100;
    m_pendingActionModeActive = false;
    m_deferredPrimarySurfaceDirty = false;
    m_deferredSecondarySurfaceDirty = false;
    m_movementStatusTagDisabled = true;

    Rect mapBounds;
    mapBounds.left = 0;
    mapBounds.top = 0;
    mapBounds.right = g_mapTilePixelWidth * (visibleTileColumns + 2);
    mapBounds.bottom = g_mapTilePixelHeight * (visibleTileRows + 2);
    SetBounds(mapBounds);

    if (g_objectNationMap == NULL) {
        DataFile objectTable;
        if (objectTable.Open("SOBJ.TBL")) {
            std::uint16_t tableHeader = 0;

            objectTable.Read(&g_objectRecordCount, sizeof(g_objectRecordCount));
            objectTable.Read(&tableHeader, sizeof(tableHeader));

            g_objectNationMap = new std::uint8_t[g_objectRecordCount + 1];
            g_objectNationMap[0] = 0;

            for (std::uint32_t index = 1; index < g_objectRecordCount; ++index) {
                std::uint32_t objectId = 0;
                std::uint8_t sourceNationOrClass = 0;
                std::uint8_t objectNation = 0;
                std::uint8_t extraWordCount = 0;

                objectTable.Read(&objectId, sizeof(objectId));
                objectTable.Read(&sourceNationOrClass, sizeof(sourceNationOrClass));
                objectTable.Read(&objectNation, sizeof(objectNation));
                objectTable.Read(&extraWordCount, sizeof(extraWordCount));

                g_objectNationMap[index] = objectNation;

                for (std::uint8_t extraIndex = 0;
                     extraIndex < extraWordCount;
                     ++extraIndex) {
                    std::uint16_t ignoredWord = 0;
                    objectTable.Read(&ignoredWord, sizeof(ignoredWord));
                }
            }
        }
    }

    BackPane *backPane = BackPane::GetActive();
    if (backPane != NULL) {
        Rect backBounds;
        backPane->GetBounds(&backBounds);
        backPane->RegisterChangeListener(this, kMapPaneChangeTag, false);
        m_selectionOverlay = new IntAlphaSurface(backBounds.right - backBounds.left,
                                                 backBounds.bottom - backBounds.top);
    }

    if (g_gameServerNationTable == NULL) {
        g_gameServerNationTable = new GameServerConfig;
    }

    m_screenEffecterCount = 0;
    m_screenEffecterCapacity = 0;
    m_screenEffecters = NULL;
}

// UID:0002QF | by-memory/0x00504530-0x005046c6.MapPaneCleanup.md | Completion:89 | Confidence:92
MapPane::~MapPane()
{
    ClearScreenEffecterList();
    g_pBackPane->UnregisterChangeListener(this, kMapPaneChangeTag, false);
    SaveCompressedMapFile();

    if (m_auxiliaryPane != NULL) {
        delete m_auxiliaryPane;
        m_auxiliaryPane = NULL;
    }

    if (m_activeScreenLayer != NULL) {
        if (g_pScreenPane != NULL) {
            g_pScreenPane->RemoveLayer(m_activeScreenLayer);
        }
        delete m_activeScreenLayer;
        m_activeScreenLayer = NULL;
    }

    if (m_objectList != NULL) {
        m_objectList->DetachAll(m_localPlayerObjectPane);
        m_objectList->DestroyOwnedObjects();
        delete m_objectList;
        m_objectList = NULL;
        m_localPlayerObjectPane = NULL;
    }

    FreeBufferMemory(g_objectNationMap);
    g_objectNationMap = NULL;
    g_objectRecordCount = 0;

    delete m_selectionOverlay;
    m_selectionOverlay = NULL;

    delete g_gameServerNationTable;
    g_gameServerNationTable = NULL;

    if (g_pSoundManager != NULL) {
        g_pSoundManager->CloseRedbookDevice();
    }

    if (g_activeMapPane == this) {
        g_activeMapPane = NULL;
    }
}

// UID:0002QG | by-memory/0x005046d0-0x005047e8.MapPaneQueuedMotionMessage.md | Completion:87 | Confidence:90
void MapPane::QueueMotionMessage(const RectBounds *bounds)
{
    if (!m_deferMotionMessages)
    {
        InvalidateRect(bounds);
        return;
    }

    if (bounds == NULL)
    {
        m_deferMotionMessages = false;
        NotifyDeferredMotionChanged();
        return;
    }

    Region incoming;
    incoming.SetRect(bounds);

    if (m_deferredMotionRecordCount >= 32)
    {
        InvalidateRect(bounds);
        return;
    }

    if (m_deferredMotionRecordCount != 0)
    {
        Motion &last =
            m_deferredMotionRecords[m_deferredMotionRecordCount - 1];

        if (last.Contains(incoming))
            return;

        if (incoming.Contains(last))
        {
            last.CopyRectFrom(incoming);
            NotifyDeferredMotionChanged();
            return;
        }
    }

    m_deferredMotionRecords[m_deferredMotionRecordCount]
        .CopyRectFrom(incoming);
    ++m_deferredMotionRecordCount;
    NotifyDeferredMotionChanged();
}

// UID:0002QH | by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md | Completion:88 | Confidence:90
#include "../ui/core/BlackHole.h"
#include "../profile/ProfileStorage.h"

void MapPane::ExitToMenu(bool notifyServer)
{
    if (g_pApplication != NULL)
        g_pApplication->m_inMapSession = false;

    SaveCompressedMapFile();
    g_pScreenPane->DisablePresentationMode();
    SaveUserSettings();

    if (m_weatherLayerPane != NULL)
    {
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(m_weatherLayerPane);
        m_weatherLayerPane = NULL;
    }

    if (m_auxiliaryPane != NULL)
    {
        m_auxiliaryPane->DeletePane(true);
        m_auxiliaryPane = NULL;
    }

    if (m_activeScreenLayer != NULL)
    {
        g_pScreenPane->RemovePane(m_activeScreenLayer);
        m_activeScreenLayer->DeletePane(true);
        m_activeScreenLayer = NULL;
    }

    DestroyGameplayPanesForExitToMenu(g_useEpfAssets);

    if (notifyServer)
    {
        unsigned char packet[2];
        PacketBufferWriteUInt8(0x0b, packet);
        g_packetSender->QueueAndSendPacket(packet, 1);
    }

    g_packetSender->Lock();
    CashShopRequestWaitDispatch(g_packetSender);
    new MainMenuPane(0);
    g_packetSender->Unlock();
}

// UID:0002QI | by-memory/0x00504b70-0x00504b8f.MapPaneTagDetachMessage.md | Completion:91 | Confidence:94
static const MessageType kPaneTagGoog = 0x676f6f67;

void MapPane::OnChangeMessage(LObject *, Message *message)
{
    if (message->m_type == kPaneTagGoog)
        g_pApplicationCleanupQueue->QueuePaneForDeferredDeletion(this);
}

// UID:0002QJ | by-memory/0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile.md | Completion:92 | Confidence:94
void MapPane::LoadCompressedMapFile(
    unsigned short mapId,
    int /*unusedLoadOption*/)
{
    wchar_t documentsPath[MAX_PATH];
    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) != S_OK)
        return;

    wchar_t mapDirectory[MAX_PATH];
    swprintf_s(mapDirectory, L"%s\\NexusTK", documentsPath);
    if (!g_pfnCreateDirectoryW(mapDirectory, NULL) &&
        GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    swprintf_s(mapDirectory, L"%s\\NexusTK\\Maps", documentsPath);
    if (!g_pfnCreateDirectoryW(mapDirectory, NULL) &&
        GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    wchar_t cachePath[MAX_PATH];
    swprintf_s(cachePath, L"%s\\TK%06d.cmp", mapDirectory, mapId);

    if (!PathExistsViaStat(cachePath))
    {
        AllocateTileBuffer();
        return;
    }

    StdioFile cacheFile;
    cacheFile.Open(cachePath);

    char signature[4];
    cacheFile.Read(signature, sizeof(signature));
    if (strncmp(signature, g_mapPaneCmapSignature, sizeof(signature)) != 0)
    {
        AllocateTileBuffer();
        return;
    }

    unsigned short cachedWidth;
    unsigned short cachedHeight;
    cacheFile.Read(&cachedWidth, sizeof(cachedWidth));
    cacheFile.Read(&cachedHeight, sizeof(cachedHeight));

    if (cachedWidth != m_mapWidth || cachedHeight != m_mapHeight)
    {
        AllocateTileBuffer();
        return;
    }

    AllocateTileBuffer();

    _AUTOBUF<unsigned char> compressedMap;
    cacheFile.ReadRemaining(compressedMap);

    uLongf uncompressedSize =
        sizeof(MapPaneTileRecord) * cachedWidth * cachedHeight;
    uncompress(
        reinterpret_cast<Bytef *>(m_tileBuffer),
        &uncompressedSize,
        compressedMap.m_data,
        compressedMap.m_count);
}

// UID:0002QK | by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md | Completion:92 | Confidence:94
void MapPane::SaveCompressedMapFile()
{
    if (m_tileBuffer == NULL)
    {
        g_pMonsterImageLib->ClearLoadedData();
        return;
    }

    wchar_t documentsPath[MAX_PATH];
    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) != S_OK)
        return;

    wchar_t mapDirectory[MAX_PATH];
    swprintf_s(mapDirectory, L"%s\\NexusTK", documentsPath);
    if (!g_pfnCreateDirectoryW(mapDirectory, NULL) &&
        GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    swprintf_s(mapDirectory, L"%s\\NexusTK\\Maps", documentsPath);
    if (!g_pfnCreateDirectoryW(mapDirectory, NULL) &&
        GetLastError() != ERROR_ALREADY_EXISTS)
        return;

    wchar_t cachePath[MAX_PATH];
    swprintf_s(cachePath, L"%s\\TK%06d.cmp", mapDirectory, m_mapId);

    FILE *cacheFile = g_pfnWideOpenFile(cachePath, L"wb");
    if (cacheFile == NULL)
        return;

    uLong tileDataSize =
        sizeof(MapPaneTileRecord) * m_mapWidth * m_mapHeight;

    fwrite(g_mapPaneCmapSignature, 1, 4, cacheFile);
    fwrite(&m_mapWidth, 1, sizeof(m_mapWidth), cacheFile);
    fwrite(&m_mapHeight, 1, sizeof(m_mapHeight), cacheFile);

    {
        _AUTOBUF<unsigned char> compressedMap;
        uLongf compressedSize = tileDataSize * 11 / 10 + 12;
        compressedMap.Resize(compressedSize);

        compress(
            compressedMap.m_data,
            &compressedSize,
            reinterpret_cast<const Bytef *>(m_tileBuffer),
            tileDataSize);

        fwrite(compressedMap.m_data, 1, compressedSize, cacheFile);
        fclose(cacheFile);

        delete [] m_tileBuffer;
        m_tileBuffer = NULL;
    }

    g_pMonsterImageLib->ClearLoadedData();
}

// UID:00041X | by-memory/0x00505130-0x0050516a.MapPaneMapToScreenCoords.md | Completion:88 | Confidence:91
void MapPane::MapToScreenCoords(MapPoint *point) const
{
    const int row = point->row - m_tileOriginY + 1;

    point->column = (point->column - m_tileOriginX + 1) * g_mapTilePixelWidth;
    point->row = row * g_mapTilePixelHeight;
}

// UID:00041Y | by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md | Completion:88 | Confidence:92
void MapPane::ScreenToMapCoords(MapPoint *point) const
{
    const int row = point->row / g_mapTilePixelHeight;

    point->column = point->column / g_mapTilePixelWidth + m_tileOriginX - 1;
    point->row = row + m_tileOriginY - 1;
}

// UID:0001AR | by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md | Completion:88 | Confidence:90
void MapPane::RedrawVisibleTiles()
{
    MapRect visibleTiles;

    UpdateSurfaceInfo(&m_viewportGrafPort);
    GetClampedVisibleTileBounds(&visibleTiles);

    for (int tileY = visibleTiles.top; tileY < visibleTiles.bottom; ++tileY)
    {
        for (int tileX = visibleTiles.left; tileX < visibleTiles.right; ++tileX)
            DrawTileAt(tileX, tileY, false);
    }

    EndPaint(&m_viewportGrafPort);
}

// UID:00041Z | by-memory/0x00505230-0x00505281.MapPaneValidateMapAndViewportCoords.md | Completion:87 | Confidence:90
bool MapPane::ValidateMapAndViewportCoords(int mapColumn,
                                           int mapRow,
                                           int viewportColumn,
                                           int viewportRow) const
{
    return mapColumn >= 0 &&
           mapColumn < m_mapWidth &&
           mapRow >= 0 &&
           mapRow < m_mapHeight &&
           viewportColumn >= 0 &&
           viewportColumn < m_visibleTileColumns &&
           viewportRow >= 0 &&
           viewportRow < m_visibleTileRows;
}

// UID:000420 | by-memory/0x00505290-0x00505304.MapPaneGetClampedVisibleTileBounds.md | Completion:88 | Confidence:90
void MapPane::GetClampedVisibleTileBounds(MapRect *outBounds) const
{
    outBounds->top = m_tileOriginY - 1;
    outBounds->left = m_tileOriginX - 1;
    outBounds->bottom = outBounds->top + m_visibleTileRows + 2;
    outBounds->right = outBounds->left + m_visibleTileColumns + 2;

    if (outBounds->top < 0)
        outBounds->top = 0;
    if (outBounds->left < 0)
        outBounds->left = 0;
    if (outBounds->bottom > m_mapHeight)
        outBounds->bottom = m_mapHeight;
    if (outBounds->right > m_mapWidth)
        outBounds->right = m_mapWidth;
}

// UID:000421 | by-memory/0x00505310-0x0050534d.MapPaneGetVisibleTileBounds.md | Completion:90 | Confidence:92
void MapPane::GetVisibleTileBounds(MapRect *outBounds) const
{
    outBounds->top = m_tileOriginY - 1;
    outBounds->left = m_tileOriginX - 1;
    outBounds->bottom = outBounds->top + m_visibleTileRows + 2;
    outBounds->right = outBounds->left + m_visibleTileColumns + 2;
}

// UID:000422 | by-memory/0x00505350-0x0050536b.MapPaneGetVisibleTileSpan.md | Completion:88 | Confidence:91
MapPoint *MapPane::GetVisibleTileSpan(MapPoint *outSpan) const
{
    outSpan->row = m_visibleTileRows;
    outSpan->column = m_visibleTileColumns;
    return outSpan;
}

// UID:000423 | by-memory/0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds.md | Completion:88 | Confidence:90
void MapPane::GetExtendedVisibleTileBounds(MapRect *outBounds) const
{
    outBounds->top = m_tileOriginY - 1;
    outBounds->left = m_tileOriginX - 1;
    outBounds->bottom = outBounds->top + m_visibleTileRows + 10;
    outBounds->right = outBounds->left + m_visibleTileColumns + 2;

    if (outBounds->top < 0)
        outBounds->top = 0;
    if (outBounds->left < 0)
        outBounds->left = 0;
    if (outBounds->bottom > m_mapHeight)
        outBounds->bottom = m_mapHeight;
    if (outBounds->right > m_mapWidth)
        outBounds->right = m_mapWidth;
}

// UID:000425 | by-memory/0x00505430-0x005055ca.MapPaneCheckMovementCollision.md | Completion:88 | Confidence:90
int MapPane::CheckMovementCollision(int mapColumn, int mapRow, unsigned char direction)
{
    MapPoint offset;
    DirectionToTileOffset(&offset, direction);

    const int nextColumn = mapColumn + offset.column;
    const int nextRow = mapRow + offset.row;

    MapRect mapBounds;
    SetRect(&mapBounds, 0, 0, m_mapWidth, m_mapHeight);
    if (!PointInRect(nextRow, nextColumn, &mapBounds))
        return -1;

    if (m_localPlayerObjectPane->AllowsMovementCollisionBypass())
        return 1;

    ObjectPane *blockingObject = m_objectList->FindObjectAtMapPoint(nextColumn, nextRow);
    if (blockingObject != NULL)
    {
        if (_wcsicmp(blockingObject->GetObjectName(), L"GM") != 0 &&
            !blockingObject->IsMovementPassable())
        {
            return 0;
        }
    }

    MapTileLayerIds currentTile;
    MapTileLayerIds nextTile;
    GetLegacyAwareMapTileLayerIds(&currentTile, mapColumn, mapRow);
    GetLegacyAwareMapTileLayerIds(&nextTile, nextColumn, nextRow);

    if ((g_objectRecordCount >= currentTile.staticObjectId ||
         g_objectRecordCount >= nextTile.staticObjectId) &&
        (g_objectNationMap[currentTile.staticObjectId] & s_objectDirectionMasks[direction]) == 0 &&
        (g_objectNationMap[nextTile.staticObjectId] & s_objectReverseDirectionMasks[direction]) == 0 &&
        nextTile.groundTileId != 0 &&
        (nextTile.flags & 1) == 0)
    {
        return 1;
    }

    return -1;
}

// UID:000426 | by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md | Completion:92 | Confidence:94
bool MapPane::AllowsMovementStatusTag() const
{
    return !m_movementStatusTagDisabled;
}

// UID:000427 | by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md | Completion:88 | Confidence:91
bool MapPane::ApplyMovementSubstepScroll(unsigned char direction)
{
    MapPoint offset;
    DirectionToTileOffset(&offset, direction);

    const int substepDivisor = 4 * g_movementSubstepScale;
    const int deltaX = offset.column * g_mapTilePixelWidth / substepDivisor;
    const int deltaY = offset.row * g_mapTilePixelHeight / substepDivisor;

    m_viewportPixelX += deltaX;
    m_viewportPixelY += deltaY;

    return InvalidateShiftedMapArea(-deltaX, -deltaY);
}

// UID:000428 | by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md | Completion:90 | Confidence:92
unsigned short MapPane::GetAdjacentVisibleTileBounds(unsigned char direction,
                                                     MapRect *outBounds) const
{
    MapRect bounds;
    GetClampedVisibleTileBounds(&bounds);

    switch (direction)
    {
    case 0:
        bounds.bottom = bounds.top;
        --bounds.top;
        break;

    case 1:
        bounds.left = bounds.right;
        ++bounds.right;
        break;

    case 2:
        bounds.top = bounds.bottom;
        ++bounds.bottom;
        break;

    case 3:
        bounds.right = bounds.left;
        --bounds.left;
        break;

    default:
        SetRect(&bounds, 0, 0, 0, 0);
        break;
    }

    MapRect mapBounds;
    SetRect(&mapBounds, 0, 0, m_mapWidth, m_mapHeight);
    IntersectRect(&bounds, &mapBounds, &bounds);

    if (outBounds != NULL)
        *outBounds = bounds;

    return ComputeTileRectChecksum(&bounds);
}

// UID:000429 | by-memory/0x00505730-0x00505731.MapPaneAfterLocalPlayerWarp.md | Completion:89 | Confidence:91
void MapPane::AfterLocalPlayerWarp()
{
}

// UID:00042A | by-memory/0x00505740-0x00505743.MapPaneObjectCallbackNoOp.md | Completion:88 | Confidence:90
void MapPane::ObjectCallbackNoOp(ObjectPane *)
{
}

// UID:0002QL | by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md | Completion:87 | Confidence:90
void MapPane::ScrollViewportByDirection(unsigned char direction)
{
    unsigned char scrollDirection = RemapMovementDirectionForMapScroll(direction);

    MapPoint tileDelta;
    DirectionToTileOffset(&tileDelta, scrollDirection);

    Point pixelDelta;
    pixelDelta.x = tileDelta.column * g_mapTilePixelWidth;
    pixelDelta.y = tileDelta.row * g_mapTilePixelHeight;

    if (m_objectList != NULL)
        m_objectList->ShiftAll(pixelDelta.x, pixelDelta.y);

    MapPoint objectPosition;
    MapPoint viewportPosition;
    m_localPlayerObjectPane->GetMapPosition(&objectPosition);
    m_localPlayerObjectPane->GetViewportPosition(&viewportPosition);

    RefreshScrolledTileData(objectPosition.column,
                            objectPosition.row,
                            viewportPosition.column,
                            viewportPosition.row,
                            direction);
}

// UID:00042D | by-memory/0x00505940-0x005059cb.MapPaneReindexObjectPanePosition.md | Completion:88 | Confidence:91
void MapPane::ReindexObjectPanePosition(ObjectPane *objectPane,
                                        int removeRow,
                                        int removeColumn,
                                        int addRow,
                                        int addColumn)
{
    if (m_objectList == NULL)
        return;

    if (!m_objectList->HasValidGridOrigin())
        return;

    MapPoint savedPosition;
    objectPane->GetMapPosition(&savedPosition);

    objectPane->m_mapColumn = removeColumn;
    objectPane->m_mapRow = removeRow;
    m_objectList->RemoveObjectPane(objectPane);

    objectPane->m_mapColumn = addColumn;
    objectPane->m_mapRow = addRow;
    m_objectList->AddObjectPane(objectPane);

    objectPane->m_mapColumn = savedPosition.column;
    objectPane->m_mapRow = savedPosition.row;
}

// UID:0002QM | by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md | Completion:88 | Confidence:90
void MapPane::RecenterAndSendPosition(int targetX,
                                      int targetY,
                                      int viewportX,
                                      int viewportY,
                                      bool useActiveObjectViewport)
{
    MapPoint oldViewport;
    oldViewport.column = viewportX;
    oldViewport.row = viewportY;

    if (useActiveObjectViewport && m_localPlayerObjectPane != NULL)
        m_localPlayerObjectPane->GetViewportPosition(&oldViewport);

    if (targetX < 0 || targetY < 0 ||
        targetX >= m_mapWidth || targetY >= m_mapHeight ||
        oldViewport.column < 0 || oldViewport.row < 0 ||
        oldViewport.column >= m_visibleTileColumns ||
        oldViewport.row >= m_visibleTileRows)
    {
        return;
    }

    if (g_useEpfAssets)
    {
        m_viewportPixelX = -g_mapTilePixelWidth;
        m_viewportPixelY = -g_mapTilePixelHeight;
    }
    else
    {
        m_viewportPixelX = 14 - g_mapTilePixelWidth;
        m_viewportPixelY = 12 - g_mapTilePixelHeight;
    }

    Rect bounds;
    SetRect(&bounds,
            m_viewportPixelX,
            m_viewportPixelY,
            m_viewportPixelX + (m_visibleTileColumns + 1) * g_mapTilePixelWidth,
            m_viewportPixelY + (m_visibleTileRows + 1) * g_mapTilePixelHeight);
    SetBounds(&bounds);

    m_tileOriginX = targetX - oldViewport.column;
    m_tileOriginY = targetY - oldViewport.row;

    if (m_objectList != NULL)
        m_objectList->UpdateForViewportOrigin(m_tileOriginX,
                                              m_tileOriginY);

    DrawVisibleTiles();

    MapRect visible;
    GetClampedVisibleTileBounds(&visible);

    unsigned int checksum = ComputeVisibleTileChecksum(visible);

    unsigned char packet[11];
    unsigned char *out = packet;
    *out++ = 0x05;
    PacketBufferWriteUInt16BE(static_cast<unsigned short>(visible.left), out);
    out += 2;
    PacketBufferWriteUInt16BE(static_cast<unsigned short>(visible.top), out);
    out += 2;
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(oldViewport.column - visible.left), out);
    out += 1;
    PacketBufferWriteUInt8(
        static_cast<unsigned char>(oldViewport.row - visible.top), out);
    out += 1;
    PacketBufferWriteUInt24BE(checksum, out);
    out += 3;
    packet[10] = 0;

    g_packetSender->QueueAndSendPacket(packet, 10);

    MapRect objectRefreshBounds;
    GetExtendedVisibleTileBounds(&objectRefreshBounds);
    RefreshStaticObjectTileRegion(objectRefreshBounds);
}

// UID:00042F | by-memory/0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh.md | Completion:90 | Confidence:92
void MapPane::ClearQueuedMapStateRefresh()
{
    if (m_queuedMapStateRefresh)
    {
        m_queuedMapStateRefresh = false;
        TimerHandler::CancelTimer(6);
        TimerHandler::CancelTimer(8);
        ReleaseMouseCapture();
    }
}

// UID:00042I | by-memory/0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll.md | Completion:94 | Confidence:94
void MapPane::ClearPendingActionPoll()
{
    if (m_pendingActionPoll)
    {
        m_pendingActionPoll = false;
        TimerHandler::CancelTimer(7);
    }
}

// UID:0002QN | by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md | Completion:92 | Confidence:94
ObjectPane *MapPane::CreateOrUpdateObjectPane(
    int objectId,
    int mapX,
    int mapY,
    unsigned char action,
    ObjectStatusBlob status)
{
    ObjectPane *objectPane = m_objectList->FindByObjectId(objectId);
    bool alreadyListed = false;

    if (status.m_statusKind == ObjectStatusBlob::ItemObject)
    {
        if (objectPane != NULL)
            DetachObjectPane(objectPane);

        ItemObjectPane *itemObjectPane = new ItemObjectPane(
            objectId,
            mapX,
            mapY,
            status.m_appearanceId,
            status.m_variantOrPalette);
        objectPane = itemObjectPane;

        const ItemInfo *itemInfo =
            g_pItemObjImageLib->m_itemInfos.GetAtOrDefault(
                static_cast<unsigned short>(
                    status.m_appearanceId + 0x4000));
        if (itemInfo->lightImageIndex >= 0)
        {
            AttachObjectLighting(
                itemObjectPane,
                g_mapTilePixelWidth / 2,
                g_mapTilePixelHeight / 2,
                itemInfo->lightImageIndex);
        }
    }
    else if (status.m_statusKind == ObjectStatusBlob::HumanObject ||
             status.m_statusKind == ObjectStatusBlob::MonsterObject)
    {
        if (m_localPlayerObjectPane->GetObjectId() == objectId)
        {
            if (objectPane != NULL)
                m_objectList->RemoveObjectPane(objectPane);

            RecenterAndSendPosition(mapX, mapY, 0, 0, true);

            UserPane *userPane =
                static_cast<UserPane *>(m_localPlayerObjectPane);
            objectPane = userPane;

            if (status.m_statusKind == ObjectStatusBlob::HumanObject &&
                status.m_actionState == 2)
            {
                status.m_actionState = 5;
            }

            userPane->SetSpriteConfig(&status, action);
            if (status.m_statusKind == ObjectStatusBlob::HumanObject)
                userPane->m_currentAppearance = status;

            delete userPane->m_hitBarObjectPane;
            delete userPane->m_damageNumberObjectPane;
            delete userPane->m_balloonObjectPane;

            userPane->m_transientObjectFlag = false;
            if (m_waitingForLocalPlayerStatus == 1)
                m_waitingForLocalPlayerStatus = 0;
        }
        else
        {
            if (static_cast<UserPane *>(
                    m_localPlayerObjectPane)->m_playerSettingsState[0] &&
                status.m_statusKind == ObjectStatusBlob::HumanObject &&
                status.m_actionState == 2)
            {
                status.m_actionState = 5;
            }

            if (objectPane != NULL)
            {
                LivingObjectPane *livingObjectPane =
                    static_cast<LivingObjectPane *>(objectPane);
                livingObjectPane->InitializeSpriteConfig(&status, action);
                livingObjectPane->SetMapPosition(mapX, mapY);
                livingObjectPane->m_transientObjectFlag = false;
                alreadyListed = true;
            }
            else
            {
                objectPane = new LivingObjectPane(
                    objectId,
                    mapX,
                    mapY,
                    status,
                    action);
            }
        }

        static_cast<LivingObjectPane *>(objectPane)->
            ScheduleBoxRotationStep();
    }
    else
    {
        return NULL;
    }

    UpdateObjectPaneScreenBounds(objectPane);
    if (!alreadyListed)
        m_objectList->AddObjectPane(objectPane);

    return objectPane;
}

// UID:0002QO | by-memory/0x005060f0-0x00506169.MapPaneRemoveObjectPaneById.md | Completion:88 | Confidence:90
void MapPane::RemoveObjectPaneById(int objectId)
{
    ObjectPane *objectPane = m_objectList->FindByObjectId(objectId);
    if (objectPane == NULL)
        return;

    if (objectPane->m_objectType == ObjectPaneType::Living)
    {
        LivingObjectPane *livingPane = static_cast<LivingObjectPane *>(objectPane);

        if (m_selectedObjectActive && m_selectedObjectPane == livingPane)
        {
            livingPane->SetHighlighted(false);
            m_selectedObjectActive = false;
            m_selectedObjectPane = NULL;
        }

        livingPane->DestroyAllLinkedObjects();
    }

    m_objectList->RemoveByType(objectPane);
    objectPane->InvalidateObjectDataRect();
    delete objectPane;
}

// UID:0002QP | by-memory/0x00506170-0x005061d3.MapPaneDetachObjectPane.md | Completion:88 | Confidence:90
void MapPane::DetachObjectPane(ObjectPane *objectPane)
{
    Rect oldObjectRect;
    objectPane->GetObjectData(&oldObjectRect);
    InvalidateRect(&oldObjectRect);

    m_objectList->RemoveByType(objectPane);

    if (objectPane->m_objectType != ObjectPaneType::Static)
        GrafPort::ReleaseBackingStore(objectPane);

    delete objectPane;
}

// UID:0002QQ | by-memory/0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect.md | Completion:88 | Confidence:90
bool MapPane::HasObjectIntersectingRect(const Rect *rect) const
{
    List *visibleObjects = m_objectList->GetVisibleObjectList();
    const int count = visibleObjects->GetCount();

    for (int index = 0; index < count; ++index)
    {
        ObjectPane *objectPane = static_cast<ObjectPane *>(visibleObjects->GetElementAt(index));
        Rect objectRect;
        objectPane->GetObjectData(&objectRect);

        if (IntersectRects(rect, &objectRect, NULL))
            return true;
    }

    return false;
}

// UID:0001AS | by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md | Completion:92 | Confidence:94
namespace {

const unsigned char kProfileRefreshOpcode = 79;
const unsigned int kMaxProfileJpfBytes = 0x2710;
const int kProfilePortraitWidth = 48;
const int kProfilePortraitHeight = 56;
const DWORD kFaceRipperWaitMs = 10000;
const int kProfileSidecarExtensionCount = 5;

void SendProfileRefreshPacket(const unsigned char* jpfBytes, unsigned int jpfSize, bool includeJpf)
{
    unsigned char stackPacket[1024];
    AutoBuffer<unsigned char> heapPacket;
    unsigned char* packet = stackPacket;

    if (includeJpf) {
        heapPacket.Allocate(10010);
        packet = heapPacket.Data();
    }

    int cursor = 0;
    PacketBufferAppendUInt8(kProfileRefreshOpcode, packet, &cursor);
    PacketBufferAppendUInt16BE(
        includeJpf ? static_cast<unsigned short>(jpfSize) : 0,
        packet,
        &cursor);

    if (includeJpf) {
        memcpy(packet + cursor, jpfBytes, jpfSize);
        cursor += static_cast<int>(jpfSize);
    }

    PacketBufferAppendWideStringAsAnsi8(
        g_pConfig->userProfile.selectedProfileName,
        packet,
        &cursor);
    QueueAndSendPacket(g_packetSender, packet, cursor);
}

bool CreateDirectoryIfNeeded(const wchar_t* path)
{
    if (CreateDirectoryW(path, NULL)) {
        return true;
    }
    return GetLastError() == ERROR_ALREADY_EXISTS;
}

} // namespace

void MapPane::RefreshSelectedProfileData()
{
    WideString localPlayerName;
    GetLocalPlayerNameString(localPlayerName);

    wchar_t documentsPath[MAX_PATH];
    if (SHGetFolderPathW(NULL, CSIDL_PERSONAL, NULL, 0, documentsPath) != S_OK) {
        return;
    }

    wchar_t nexusDir[MAX_PATH];
    FormatWide(nexusDir, MAX_PATH, L"%s\\NexusTK", documentsPath);
    if (!CreateDirectoryIfNeeded(nexusDir)) {
        return;
    }

    wchar_t usersDir[MAX_PATH];
    FormatWide(usersDir, MAX_PATH, L"%s\\NexusTK\\users", documentsPath);
    if (!CreateDirectoryIfNeeded(usersDir)) {
        return;
    }

    WideString sidecarPath;
    for (int extensionIndex = 0;
         extensionIndex < kProfileSidecarExtensionCount;
         ++extensionIndex) {
        const wchar_t* extension =
            kProfileSidecarExtensions[extensionIndex];
        FormatWide(sidecarPath, L"%s/%s.%s", usersDir, localPlayerName.c_str(), extension);
        if (!FileExists(sidecarPath.c_str())) {
            continue;
        }

        WideString commandLine;
        FormatWide(commandLine, L"FaceRipper.exe %s", sidecarPath.c_str());

        STARTUPINFOW startupInfo = { 0 };
        PROCESS_INFORMATION processInfo = { 0 };
        startupInfo.cb = sizeof(startupInfo);
        if (CreateProcessW(
                NULL,
                const_cast<wchar_t*>(commandLine.c_str()),
                NULL,
                NULL,
                FALSE,
                CREATE_NEW_CONSOLE,
                NULL,
                NULL,
                &startupInfo,
                &processInfo)) {
            WaitForSingleObject(processInfo.hProcess, kFaceRipperWaitMs);
        }
        break;
    }

    WideString jpfPath;
    FormatWide(jpfPath, L"%s/%s.jpf", usersDir, localPlayerName.c_str());
    if (!FileExists(jpfPath.c_str())) {
        FormatWide(jpfPath, L"./users/%s.jpf", localPlayerName.c_str());
        if (!FileExists(jpfPath.c_str())) {
            SendProfileRefreshPacket(NULL, 0, false);
            return;
        }
    }

    FILE* file = OpenBinaryFile(jpfPath.c_str());
    if (file == NULL) {
        SendProfileRefreshPacket(NULL, 0, false);
        return;
    }

    unsigned char ignoredHeader[4];
    fread(ignoredHeader, 1, sizeof(ignoredHeader), file);
    fseek(file, 0, SEEK_END);
    unsigned int jpfSize = static_cast<unsigned int>(ftell(file));

    if (jpfSize >= kMaxProfileJpfBytes) {
        fclose(file);
        SendProfileRefreshPacket(NULL, 0, false);
        return;
    }

    AutoBuffer<unsigned char> packetBytes;
    packetBytes.Allocate(10010);

    int cursor = 0;
    PacketBufferAppendUInt8(kProfileRefreshOpcode, packetBytes.Data(), &cursor);
    PacketBufferAppendUInt16BE(
        static_cast<unsigned short>(jpfSize),
        packetBytes.Data(),
        &cursor);

    fseek(file, 0, SEEK_SET);
    cursor += static_cast<int>(fread(packetBytes.Data() + cursor, 1, jpfSize, file));
    fclose(file);

    ImageDrawContext decodedImage;
    InitializeImageDrawContext(&decodedImage);
    DecodeJpfImageToTileContext(packetBytes.Data() + 3, jpfSize, &decodedImage);

    const bool hasExpectedPortraitBounds =
        decodedImage.bounds.Width() == kProfilePortraitWidth &&
        decodedImage.bounds.Height() == kProfilePortraitHeight;

    if (hasExpectedPortraitBounds) {
        PacketBufferAppendWideStringAsAnsi8(
            g_pConfig->userProfile.selectedProfileName,
            packetBytes.Data(),
            &cursor);
    } else {
        cursor = 1;
        PacketBufferAppendUInt16BE(0, packetBytes.Data(), &cursor);
        PacketBufferAppendWideStringAsAnsi8(
            g_pConfig->userProfile.selectedProfileName,
            packetBytes.Data(),
            &cursor);
    }

    QueueAndSendPacket(g_packetSender, packetBytes.Data(), cursor);
    DestroyImageDrawContext(&decodedImage);
}

// UID:0004DR | by-memory/0x00506970-0x0050697f.MapPaneFindObjectPaneById.md | Completion:88 | Confidence:90
ObjectPane *MapPane::FindObjectPaneById(int objectId)
{
    return m_objectList->FindByObjectId(objectId);
}


// UID:0004DT | by-memory/0x00506ae0-0x00506b2a.MapPaneFindPreviousSelectableObject.md | Completion:88 | Confidence:90
ObjectPane *MapPane::FindPreviousSelectableObject(ObjectPane *current)
{
    unsigned int key = m_objectList->GetTypedObjectKey(current);

    if (m_objectList->MoveKeyToPreviousSelectableObject(&key))
        return m_objectList->ResolveObjectListKey(key);

    return current;
}

// UID:0004DU | by-memory/0x00506b30-0x00506b7a.MapPaneFindNextSelectableObject.md | Completion:88 | Confidence:90
ObjectPane *MapPane::FindNextSelectableObject(ObjectPane *current)
{
    unsigned int key = m_objectList->GetTypedObjectKey(current);

    if (m_objectList->MoveKeyToNextSelectableObject(&key))
        return m_objectList->ResolveObjectListKey(key);

    return current;
}

// UID:0004DV | by-memory/0x00506b80-0x00506bca.MapPaneFindPreviousItemTargetObject.md | Completion:88 | Confidence:90
ObjectPane *MapPane::FindPreviousItemTargetObject(ObjectPane *current)
{
    unsigned int key = m_objectList->GetTypedObjectKey(current);

    if (m_objectList->MoveKeyToPreviousItemTargetObject(&key))
        return m_objectList->ResolveObjectListKey(key);

    return current;
}

// UID:0004DW | by-memory/0x00506bd0-0x00506c1a.MapPaneFindNextItemTargetObject.md | Completion:88 | Confidence:90
ObjectPane *MapPane::FindNextItemTargetObject(ObjectPane *current)
{
    unsigned int key = m_objectList->GetTypedObjectKey(current);

    if (m_objectList->MoveKeyToNextItemTargetObject(&key))
        return m_objectList->ResolveObjectListKey(key);

    return current;
}

// UID:0004DX | by-memory/0x00506c20-0x00506c6d.MapPaneFindPreviousLivingTarget.md | Completion:88 | Confidence:90
ObjectPane *MapPane::FindPreviousLivingTarget(ObjectPane *current, int targetFilter)
{
    unsigned int key = m_objectList->GetTypedObjectKey(current);

    if (m_objectList->MoveKeyToPreviousLivingTarget(&key, targetFilter))
        return m_objectList->ResolveObjectListKey(key);

    return current;
}

// UID:0004DY | by-memory/0x00506c70-0x00506cbd.MapPaneFindNextLivingTarget.md | Completion:88 | Confidence:90
ObjectPane *MapPane::FindNextLivingTarget(ObjectPane *current, int targetFilter)
{
    unsigned int key = m_objectList->GetTypedObjectKey(current);

    if (m_objectList->MoveKeyToNextLivingTarget(&key, targetFilter))
        return m_objectList->ResolveObjectListKey(key);

    return current;
}

// UID:0004DZ | by-memory/0x00506cc0-0x00506cdd.MapPaneRemoveObjectPaneIfPresent.md | Completion:88 | Confidence:90
void MapPane::RemoveObjectPaneIfPresent(ObjectPane *object)
{
    if (object != NULL)
        m_objectList->RemoveObjectPane(object);
}

// UID:0001AU | by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md | Completion:89 | Confidence:91
LivingObjectPane *MapPane::HitTestObjectAtPoint(int y, int x)
{
    if (!PointInRect(y, x, &m_bounds))
        return 0;

    return FindObjectAtMapPoint(y, x);
}

// UID:00037R | by-memory/0x00506d20-0x00507150.MapPaneResizeCommandInputCore.md | Completion:93 | Confidence:94
#include "../ui/dialogs/QuitDialogs.h"

void MapPane::AddToLayer(RectBounds *bounds,
                         int order,
                         Pane *previousPane,
                         Layer *layer)
{
    Pane::AddToLayer(bounds, order, previousPane, layer);

    RectBounds mapBounds;
    InitRectBounds(
        &mapBounds,
        g_mapTilePixelWidth,
        g_mapTilePixelHeight,
        g_mapTilePixelWidth * (m_visibleTileColumns + 1),
        g_mapTilePixelHeight * (m_visibleTileRows + 1));
    GrafPort::UpdateRenderRegion(&mapBounds);

    Region clipRegion;
    clipRegion.SetRect(&m_visibleBounds);
    SetClipRegion(&clipRegion);
}

bool MapPane::HandleKeyOrTextEvent(Event *event)
{
    enum
    {
        kPlayerFeatureMode = 0,
        kDayNightStepCount = 32,
        kMapRefreshRequestOpcode = 0x38
    };

    const unsigned char modifiers = event->m_payload.m_key.m_modifiers;
    if (!m_leftButtonTrackingActive &&
        !m_rightButtonTrackingActive &&
        m_queuedMapStateRefresh &&
        modifiers != kEventModifierControl &&
        modifiers != kEventModifierShift)
    {
        ClearQueuedMapStateRefresh();
    }

    const unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        modifiers);
    if (event->m_type != kEventKeyDown)
        return false;

    switch (key)
    {
    case '-':
    case '=':
        if (m_localPlayerObjectPane != NULL &&
            m_localPlayerObjectPane
                ->m_playerSettingsState[kPlayerFeatureMode] != 0)
        {
            unsigned char brightnessStep =
                static_cast<unsigned char>(
                    static_cast<int>(
                        m_dayNightTargetBrightness *
                            static_cast<float>(kDayNightStepCount) +
                        0.5f));

            if (key == '-')
            {
                if (brightnessStep != 0)
                    --brightnessStep;
                else
                    brightnessStep = kDayNightStepCount;
            }
            else
            {
                ++brightnessStep;
                if (brightnessStep > kDayNightStepCount)
                    brightnessStep = 0;
            }

            const float targetBrightness =
                static_cast<float>(brightnessStep) /
                static_cast<float>(kDayNightStepCount);
            const float delta =
                targetBrightness - m_currentDayNightBrightness;
            SetDayNightFadeTarget(
                targetBrightness,
                m_dayNightTintCurveScale * delta * delta +
                    m_dayNightTintCurveBase);
        }
        break;

    case 'r':
        if (modifiers == kEventModifierControl)
        {
            if (g_pTransferServerDialog == NULL)
            {
                new MapRefreshDimmer;

                unsigned char packet[2];
                PacketBufferWriteUInt8(
                    kMapRefreshRequestOpcode, packet);
                packet[1] = 0;
                g_packetSender->QueueAndSendPacket(packet, 1);

                m_visibleObjectRefreshPending = true;
                m_refreshWholeVisibleMap = true;
                if (m_objectList != NULL)
                {
                    m_objectList->MarkVisibleObjectsForRefresh();
                    m_objectList->PruneMarkedRowObjects();
                }
            }
            return true;
        }
        break;

    case 'x':
        if (modifiers == kEventModifierAlt)
        {
            new QuitDialog;
            return true;
        }
        break;

    case 'n':
        g_pConfig->m_showUserName =
            !g_pConfig->m_showUserName;
        InvalidateRect(&m_visibleBounds);
        return true;
    }

    if (modifiers == kEventModifierControl &&
        key >= 'a' && key <= 'z')
    {
        m_localPlayerObjectPane->UseInventorySlot(
            static_cast<unsigned char>(key - 'a' + 1));
    }
    else if (modifiers ==
                 (kEventModifierControl | kEventModifierShift) &&
             key >= 'A' && key <= 'Z')
    {
        m_localPlayerObjectPane->UseInventorySlot(
            static_cast<unsigned char>(key - 'A' + 27));
    }

    return false;
}

// UID:00037S | by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md | Completion:93 | Confidence:94
static void __stdcall RequestLookAtMapPosition(
    unsigned short column,
    unsigned short row);

bool MapPane::HandlePointerOrMouseEvent(Event *event)
{
    bool clearQueuedState = true;
    bool handled = false;
    MapRect pointerBounds = m_bounds;
    LivingObjectPane *livingObject;
    ObjectPane *itemObject;
    ObjectStatusBlob objectStatus;
    MapPoint point;

    if (m_localPlayerObjectPane->m_inputLocked)
        return false;

    pointerBounds.right -= g_mapTilePixelWidth;
    pointerBounds.bottom -= g_mapTilePixelHeight;

    if (m_waitingForLocalPlayerStatus)
        return false;

    const EventPointerPayload &pointer = event->m_payload.m_pointer;
    const bool insideMap = PointInRect(
        pointer.m_y,
        pointer.m_x,
        &pointerBounds) != 0;

    switch (event->m_type) {
    case kEventCursorMove:
        m_pointerEventY = pointer.m_y;
        m_pointerEventX = pointer.m_x;
        m_pointerEventModifiers = pointer.m_modifiers;
        m_pointerEventDetail = pointer.m_detail;
        m_pointerEventMessageTime = pointer.m_messageTime;
        m_pointerEventType = event->m_type;

        if (m_leftButtonTrackingActive && insideMap) {
            livingObject = FindObjectAtMapPoint(pointer.m_y, pointer.m_x);
            if (livingObject != m_highlightedObjectPane) {
                if (m_highlightedObjectPane != NULL &&
                    !m_selectedObjectActive) {
                    m_highlightedObjectPane->SetHighlightState(false);
                }
                m_highlightedObjectPane = livingObject;
                if (livingObject != NULL)
                    livingObject->SetHighlightState(true);
            }
        }

        if (g_pConfig->m_autoMoveEnabled && m_queuedMapStateRefresh) {
            if (m_rightButtonTrackingActive) {
                point.row = pointer.m_y;
                point.column = pointer.m_x;
                ScreenToMapCoords(&point);
                m_pendingActionRow = point.row;
                m_pendingActionColumn = point.column;
            }
            clearQueuedState = false;
        }

        if (!insideMap)
            return false;

        livingObject = FindObjectAtMapPoint(pointer.m_y, pointer.m_x);
        if (livingObject != NULL && !livingObject->m_terminalAnimation) {
            livingObject->GetSpriteConfig(&objectStatus);
            switch (objectStatus.m_actionState) {
            case kMapActionView:
                g_pScreenPane->SetActiveCursor(
                    ScreenPane::kCursorView,
                    false);
                break;
            case kMapActionSelect:
            case kMapActionInteract:
                g_pScreenPane->SetActiveCursor(
                    ScreenPane::kCursorSelect,
                    false);
                break;
            default:
                g_pScreenPane->SetActiveCursor(
                    ScreenPane::kCursorAttack,
                    false);
                break;
            }
        } else {
            itemObject = FindItemObjectAtMapPoint(pointer.m_y, pointer.m_x);
            g_pScreenPane->SetActiveCursor(
                itemObject != NULL
                    ? ScreenPane::kCursorPut
                    : ScreenPane::kCursorNormal,
                false);
        }

        if (livingObject == NULL ||
            livingObject->m_objectId != m_hoveredObjectId) {
            if (m_hoveredObjectId != 0) {
                LivingObjectPane *oldObject = static_cast<LivingObjectPane *>(
                    m_objectList->FindByObjectId(m_hoveredObjectId));
                if (oldObject != NULL &&
                    oldObject->m_objectInfoObjectPane != NULL &&
                    oldObject->m_objectInfoObjectPane->m_tracksSelectedName) {
                    oldObject->m_objectInfoObjectPane->InvalidateRect(NULL);
                    oldObject->m_objectInfoObjectPane->SetSelectedName(L"");
                    oldObject->m_objectInfoObjectPane->UpdatePosition();
                    oldObject->m_objectInfoObjectPane->InvalidateRect(NULL);
                }
                m_hoveredObjectId = 0;
            }

            if (livingObject != NULL &&
                livingObject->m_objectStatus.m_statusKind ==
                    ObjectStatusBlob::HumanObject &&
                livingObject->m_objectInfoObjectPane != NULL &&
                livingObject->m_objectInfoObjectPane->m_tracksSelectedName) {
                ObjectInfoObjectPane *objectInfo =
                    livingObject->m_objectInfoObjectPane;
                objectInfo->InvalidateRect(NULL);
                objectInfo->SetSelectedName(livingObject->m_name);
                objectInfo->UpdatePosition();
                objectInfo->InvalidateRect(NULL);
                m_hoveredObjectId = livingObject->m_objectId;
            }
        }
        return true;

    case kEventLeftButtonDown:
        if (g_pUserPane->m_nameVisible)
            return true;

        m_leftButtonTrackingActive = true;
        if (m_queuedMapStateRefresh)
            ClearQueuedMapStateRefresh();
        m_pendingActionState = 0;

        if (!insideMap)
            return false;

        if (m_highlightedObjectPane != NULL &&
            !m_selectedObjectActive) {
            m_highlightedObjectPane->SetHighlightState(false);
        }

        livingObject = FindObjectAtMapPoint(pointer.m_y, pointer.m_x);
        if (livingObject != NULL && !livingObject->m_terminalAnimation) {
            livingObject->GetSpriteConfig(&objectStatus);
            m_pendingActionState = objectStatus.m_actionState;

            if (m_pendingActionState == kMapActionView ||
                m_pendingActionState == kMapActionSelect ||
                m_pendingActionState == kMapActionInteract) {
                if (livingObject != m_selectedObjectPane) {
                    livingObject->SetHighlightState(true);
                    m_highlightedObjectPane = livingObject;
                }
                return true;
            }

            m_highlightedObjectPane = NULL;
            m_pendingActionTargetObjectId = livingObject->m_objectId;
        } else {
            itemObject = FindItemObjectAtMapPoint(pointer.m_y, pointer.m_x);
            if (itemObject != NULL) {
                m_pendingActionModifiers = pointer.m_modifiers;
                m_pendingActionState = kMapActionGroundItem;
                m_pendingActionTargetObjectId = itemObject->m_objectId;
            }
        }

        m_actionStartY = pointer.m_y;
        m_actionStartX = pointer.m_x;

        if (g_pConfig->m_clickMoveEnabled) {
            point.row = pointer.m_y;
            point.column = pointer.m_x;
            if (livingObject != NULL &&
                (m_pendingActionState == kMapActionMoveTo ||
                 m_pendingActionState == kMapActionMoveAndUse)) {
                livingObject->GetMapPosition(&point);
                MapToScreenCoords(&point);
            }

            m_pendingActionY = point.row;
            m_pendingActionX = point.column;
            ScreenToMapCoords(&point);
            m_pendingActionRow = point.row;
            m_pendingActionColumn = point.column;

            Sleep(100);
            if (!m_queuedMapStateRefresh && g_pInputBlockerPane == NULL) {
                m_queuedMapStateRefresh = true;
                TimerHandler::ScheduleTimer(8, 44, 0, 0);
                CaptureMouse();
            }
        }
        return false;

    case kEventLeftButtonUp:
        if (insideMap) {
            if (m_highlightedObjectPane != NULL &&
                !m_selectedObjectActive) {
                m_highlightedObjectPane->SetHighlightState(false);
            }

            livingObject = FindObjectAtMapPoint(pointer.m_y, pointer.m_x);
            if (livingObject != NULL &&
                livingObject->m_objectId == m_pendingActionTargetObjectId) {
                if (m_pendingActionState == kMapActionView &&
                    !m_objectInteractionTimerActive) {
                    m_objectInteractionTimerActive = true;
                    RequestObjectInfo(livingObject->m_objectId);
                    TimerHandler::ScheduleTimer(5, 4000, 0, 0);
                    handled = true;
                } else if (m_pendingActionState == kMapActionSelect ||
                           m_pendingActionState == kMapActionInteract) {
                    g_pScreenPane->SetActiveCursor(
                        ScreenPane::kCursorNormal,
                        false);
                    RequestObjectInfo(livingObject->m_objectId);
                    handled = true;
                }
            } else {
                clearQueuedState = false;
                m_leftButtonTrackingActive = false;
                ClearPendingActionPoll();
            }

            m_highlightedObjectPane = NULL;
            ClearPendingActionPoll();
            m_leftButtonTrackingActive = false;
            handled = true;
        }
        break;

    case kEventRightButtonDown:
        if (g_pUserPane->m_nameVisible)
            return true;

        if (m_queuedMapStateRefresh)
            ClearQueuedMapStateRefresh();
        ClearPendingActionPoll();

        if (g_pConfig->m_clickLookEnabled && insideMap) {
            if (m_highlightedObjectPane != NULL &&
                !m_selectedObjectActive) {
                m_highlightedObjectPane->SetHighlightState(false);
            }

            livingObject = FindObjectAtMapPoint(pointer.m_y, pointer.m_x);
            if (livingObject != NULL &&
                !livingObject->m_terminalAnimation) {
                livingObject->GetSpriteConfig(&objectStatus);
                if (objectStatus.m_actionState == kMapActionView) {
                    if (livingObject == m_localPlayerObjectPane) {
                        RequestLocalPlayerStatus(pointer.m_messageTime);
                        m_highlightedObjectPane = NULL;
                        return true;
                    }
                    if (livingObject == m_selectedObjectPane)
                        return true;

                    livingObject->SetHighlightState(true);
                    m_highlightedObjectPane = livingObject;

                    if (g_pRightButtonMenuPane == NULL)
                        new RightButtonMenuPane;

                    g_pRightButtonMenuPane->RemoveFromLayer();
                    g_pRightButtonMenuPane->UnregisterEventHandler();

                    RectBounds menuBounds;
                    InitRectBounds(
                        &menuBounds,
                        pointer.m_x - 50,
                        pointer.m_y - 50,
                        pointer.m_x + 29,
                        pointer.m_y + 76);
                    g_pRightButtonMenuPane->AddToLayer(
                        &menuBounds,
                        0,
                        NULL,
                        g_mainUiLayerSlots.effectPaneLayerContext);
                    g_pRightButtonMenuPane->RegisterEventHandler(0, 0);
                    g_pRightButtonMenuPane->SetTargetNameAndId(
                        livingObject->m_objectId,
                        livingObject->m_name);
                    return true;
                }

                if (objectStatus.m_actionState == kMapActionSelect ||
                    objectStatus.m_actionState == kMapActionInteract ||
                    objectStatus.m_actionState == kMapActionMoveTo ||
                    objectStatus.m_actionState == kMapActionMoveAndUse) {
                    livingObject->GetMapPosition(&point);
                    RequestLookAtMapPosition(
                        static_cast<unsigned short>(point.column),
                        static_cast<unsigned short>(point.row));
                    m_highlightedObjectPane = NULL;
                    return true;
                }
            }

            itemObject = FindItemObjectAtMapPoint(pointer.m_y, pointer.m_x);
            if (itemObject != NULL) {
                itemObject->GetMapPosition(&point);
                RequestLookAtMapPosition(
                    static_cast<unsigned short>(point.column),
                    static_cast<unsigned short>(point.row));
                return true;
            }
        }

        if (insideMap) {
            m_pointerEventY = pointer.m_y;
            m_pointerEventX = pointer.m_x;
            m_pointerEventModifiers = pointer.m_modifiers;
            m_pointerEventDetail = pointer.m_detail;
            m_pointerEventMessageTime = pointer.m_messageTime;
            m_pointerEventType = event->m_type;
            m_rightButtonMovePending = true;

            if (g_useEpfAssets && g_pConfig->m_autoMoveEnabled) {
                point.row = pointer.m_y;
                point.column = pointer.m_x;
                ScreenToMapCoords(&point);
                m_pendingActionRow = point.row;
                m_pendingActionColumn = point.column;
                Sleep(100);
                if (!m_queuedMapStateRefresh &&
                    g_pInputBlockerPane == NULL) {
                    m_queuedMapStateRefresh = true;
                    TimerHandler::ScheduleTimer(6, 44, 0, 0);
                    CaptureMouse();
                }
            }
        }
        m_rightButtonTrackingActive = true;
        break;

    case kEventRightButtonUp:
        m_pointerEventY = pointer.m_y;
        m_pointerEventX = pointer.m_x;
        m_pointerEventModifiers = pointer.m_modifiers;
        m_pointerEventDetail = pointer.m_detail;
        m_pointerEventMessageTime = pointer.m_messageTime;
        m_pointerEventType = event->m_type;

        if (g_pConfig->m_autoMoveEnabled) {
            m_rightButtonMovePending = false;
            clearQueuedState = false;
        } else {
            ClearQueuedMapStateRefresh();
        }
        ClearPendingActionPoll();
        m_rightButtonTrackingActive = false;
        break;

    case kEventLeftButtonDoubleClick:
    case kEventRightButtonDoubleClick:
    case kEventMouseWheel:
    default:
        break;
    }

    if (g_pConfig->m_autoMoveEnabled &&
        clearQueuedState &&
        m_queuedMapStateRefresh) {
        ClearQueuedMapStateRefresh();
    }
    return handled;
}


// UID:0003ZT | by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md | Completion:92 | Confidence:94
bool MapPane::HandleSystemOrControlEvent(Event *event)
{
    if (g_useEpfAssets && m_queuedMapStateRefresh)
    {
        m_queuedMapStateRefresh = false;
        TimerHandler::CancelTimer(6);
        TimerHandler::CancelTimer(8);
        ReleaseMouseCapture();
    }

    if (event->m_type != kEventWorkNotification)
        return false;

    if (g_pUrlAlertPane != NULL)
        return false;

    new ConnectionClosedDialog;
    return true;
}

// UID:0003ZS | by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md | Completion:89 | Confidence:91
bool MapPane::OnTimerEvent(int timerId, int, int)
{
    switch (timerId)
    {
    case 5:
        m_objectInteractionTimerActive = false;
        return true;

    case 7:
        if (m_pendingActionPoll)
        {
            if ((GetAsyncKeyState(VK_LBUTTON) & 0x8000) != 0)
            {
                if (g_pUserPane != NULL)
                    g_pUserPane->TryPerformAction();
                TimerHandler::ScheduleTimer(7, 500, 0, 0);
            }
            else
            {
                ClearPendingActionPoll();
            }
            return true;
        }

        /* fall through to the movement/path timer */
    case 6:
        if (!m_queuedMapStateRefresh)
            return true;

        if (g_pInputBlockerPane != NULL)
        {
            ClearQueuedMapStateRefresh();
            return true;
        }

        if (m_localPlayerObjectPane != NULL)
        {
            int direction = SelectMovementPathStep();
            if (direction >= 0 && direction < 4)
                m_localPlayerObjectPane->ProcessMovement(direction);
        }

        if (ShouldClearMovementTimerState())
            ClearQueuedMapStateRefresh();
        else
            TimerHandler::ScheduleTimer(6, 44, 0, 0);
        return true;

    case 8:
        if (!m_queuedMapStateRefresh)
            return true;

        if (g_pInputBlockerPane != NULL)
        {
            ClearQueuedMapStateRefresh();
            return true;
        }

        if (m_localPlayerObjectPane != NULL)
        {
            MapPoint currentPosition;
            m_localPlayerObjectPane->GetMapPosition(&currentPosition);

            ObjectPane *target = m_objectList != NULL
                ? m_objectList->FindByObjectId(m_pendingActionTargetObjectId)
                : NULL;

            int direction = BuildPathToPendingActionTarget(target, currentPosition);
            if (direction >= 0 && direction < 4)
                m_localPlayerObjectPane->ProcessMovement(direction);
            else
                ResolvePendingActionTarget(target, currentPosition);
        }

        if (ShouldClearMovementTimerState())
            ClearQueuedMapStateRefresh();
        else
            TimerHandler::ScheduleTimer(8, 44, 0, 0);
        return true;

    default:
        return false;
    }
}

// UID:0004QW | by-memory/0x00509470-0x00509478.MapPaneGetCurrentMapId.md | Completion:92 | Confidence:94
unsigned short MapPane::GetCurrentMapId() const
{
    return m_mapId;
}

// UID:0004QY | by-memory/0x005094b0-0x0050a4fd.MapPaneRenderMapView.md | Completion:92 | Confidence:94
namespace
{
    ObjectPane *GetObjectPaneAt(List *objects, int index)
    {
        return *static_cast<ObjectPane **>(objects->GetElementAt(index));
    }

    bool GetVisibleObjectBounds(MapPane *mapPane,
                                ObjectPane *objectPane,
                                RectBounds *objectBounds)
    {
        Region exposedRegion;
        objectPane->GetObjectData(objectBounds);
        mapPane->GetExposedRegion(&exposedRegion);
        return exposedRegion.IntersectWithRect(objectBounds);
    }

    void RenderObjectList(MapPane *mapPane, List *objects)
    {
        for (int index = 0; index < objects->GetCount(); ++index)
        {
            ObjectPane *objectPane = GetObjectPaneAt(objects, index);
            RectBounds objectBounds;
            if (GetVisibleObjectBounds(mapPane, objectPane, &objectBounds))
                objectPane->RenderFrame(mapPane, &objectBounds);
        }
    }

    void RenderEffectList(MapPane *mapPane, List *effects)
    {
        RenderObjectList(mapPane, effects);
    }
}

void MapPane::RenderMapView()
{
    if (m_mapFlashColor != 0)
    {
        RectBounds mapBounds;
        SetDrawColor(m_mapFlashColor);
        GetBounds(&mapBounds);
        g_pfnFillRect(this, &mapBounds);
        return;
    }

    Region exposedRegion;

    const unsigned char blindnessLevel =
        m_localPlayerObjectPane->m_playerSettingsState[4];
    if (m_waitingForLocalPlayerStatus)
        return;

    m_localPlayerObjectPane->UpdateScreenPosition();

    const bool shadowEnabled = g_pConfig->m_shadowEnabled != 0;
    if (g_mapRenderScratchFlag != static_cast<unsigned char>(shadowEnabled))
    {
        g_pPaletteLib->UpdatePaletteFilterTables(m_dayNightTargetBrightness);
        DrawVisibleTiles();
        QueueMotionMessage(NULL);
        g_mapRenderScratchFlag = static_cast<unsigned char>(shadowEnabled);
    }

    if (shadowEnabled && m_dayNightTargetBrightness != 1.0f)
    {
        RectBounds shadowBounds;
        GetClipRect(&shadowBounds);
        RenderDayNightOverlay(&shadowBounds);
    }
    else if (!shadowEnabled)
    {
        g_pPaletteLib->SetPaletteFilterActive(true);
    }

    MapRect visibleTiles;
    GetClampedVisibleTileBounds(&visibleTiles);
    InflateRect(&visibleTiles, -1, -1);
    if (visibleTiles.left < 0)
        visibleTiles.left = 0;
    if (visibleTiles.top < 0)
        visibleTiles.top = 0;
    if (visibleTiles.right > m_mapWidth)
        visibleTiles.right = m_mapWidth;
    if (visibleTiles.bottom > m_mapHeight)
        visibleTiles.bottom = m_mapHeight;

    RectBounds clipBounds;
    GetClipRect(&clipBounds);
    if (!IsRectEmpty(&clipBounds))
    {
        EndPaint();
        BlitSurface(&m_viewportGrafPort, &clipBounds, &clipBounds, 0);
        BeginPaint();
    }

    if (blindnessLevel == 0)
    {
        if (shadowEnabled)
        {
            for (int row = visibleTiles.top; row < visibleTiles.bottom; ++row)
            {
                List *livingObjects = m_objectList->GetFrontRowBucket(row);
                for (int index = 0; index < livingObjects->GetCount(); ++index)
                {
                    ObjectPane *objectPane = GetObjectPaneAt(livingObjects, index);
                    RectBounds renderBounds;
                    RectBounds objectBounds;
                    objectPane->ComputeRenderBounds(&renderBounds);
                    GetExposedRegion(&exposedRegion);
                    if (exposedRegion.IntersectWithRect(&renderBounds))
                    {
                        objectPane->GetObjectData(&objectBounds);
                        objectPane->DrawSpriteFrame(this, &objectBounds);
                    }
                }
            }
        }

        RenderObjectList(this, m_objectList->GetPrimaryCellList());
        RenderObjectList(this, m_objectList->GetSecondaryCellList());

        const unsigned short firstStaticId = g_useEpfAssets ? 14347 : 13968;
        const unsigned short secondStaticId = g_useEpfAssets ? 14349 : 13970;

        for (int row = visibleTiles.top; row < visibleTiles.bottom; ++row)
        {
            RenderEffectList(this, m_objectList->GetPrimaryRowBucket(row));

            List *staticObjects = m_objectList->GetBackRowBucket(row);
            for (int index = 0; index < staticObjects->GetCount(); ++index)
            {
                StaticObjectPane *objectPane = static_cast<StaticObjectPane *>(
                    GetObjectPaneAt(staticObjects, index));
                if (objectPane->m_staticObjectId == firstStaticId ||
                    objectPane->m_staticObjectId == secondStaticId)
                {
                    RectBounds objectBounds;
                    if (GetVisibleObjectBounds(this, objectPane, &objectBounds))
                        objectPane->RenderFrame(this, &objectBounds);
                }
            }

            RenderObjectList(this, m_objectList->GetFrontRowBucket(row));

            for (int index = 0; index < staticObjects->GetCount(); ++index)
            {
                StaticObjectPane *objectPane = static_cast<StaticObjectPane *>(
                    GetObjectPaneAt(staticObjects, index));
                if (objectPane->m_staticObjectId != firstStaticId &&
                    objectPane->m_staticObjectId != secondStaticId)
                {
                    RectBounds objectBounds;
                    if (GetVisibleObjectBounds(this, objectPane, &objectBounds))
                        objectPane->RenderFrame(this, &objectBounds);
                }
            }

            List *secondaryEffects = m_objectList->GetSecondaryRowBucket(row);
            for (int index = 0; index < secondaryEffects->GetCount(); ++index)
            {
                EffectObjectPane *effect = static_cast<EffectObjectPane *>(
                    GetObjectPaneAt(secondaryEffects, index));
                if (!effect->m_renderAfterLivingObjects)
                {
                    RectBounds effectBounds;
                    if (GetVisibleObjectBounds(this, effect, &effectBounds))
                        effect->RenderFrame(this, &effectBounds);
                }
            }
        }

        const int lastBackRow = Min(
            static_cast<int>(m_mapHeight),
            static_cast<int>(m_tileOriginY + m_visibleTileRows + 9));
        for (int row = visibleTiles.bottom; row < lastBackRow; ++row)
            RenderObjectList(this, m_objectList->GetBackRowBucket(row));

        for (int row = visibleTiles.top; row < visibleTiles.bottom; ++row)
        {
            List *secondaryEffects = m_objectList->GetSecondaryRowBucket(row);
            for (int index = 0; index < secondaryEffects->GetCount(); ++index)
            {
                EffectObjectPane *effect = static_cast<EffectObjectPane *>(
                    GetObjectPaneAt(secondaryEffects, index));
                if (effect->m_renderAfterLivingObjects)
                {
                    RectBounds effectBounds;
                    if (GetVisibleObjectBounds(this, effect, &effectBounds))
                        effect->RenderFrame(this, &effectBounds);
                }
            }
        }
    }
    else
    {
        RectBounds mapBounds;
        SetDrawColor(128);
        GetBounds(&mapBounds);
        g_pfnFillRect(this, &mapBounds);

        MapPoint playerPosition;
        m_localPlayerObjectPane->GetMapPosition(&playerPosition);
        if (playerPosition.column >= visibleTiles.left &&
            playerPosition.column < visibleTiles.right &&
            playerPosition.row >= visibleTiles.top &&
            playerPosition.row < visibleTiles.bottom)
        {
            RenderEffectList(
                this, m_localPlayerObjectPane->m_primaryEffectObjectPanes);

            RectBounds playerBounds;
            if (GetVisibleObjectBounds(
                    this, m_localPlayerObjectPane, &playerBounds))
            {
                m_localPlayerObjectPane->RenderFrame(this, &playerBounds);
            }

            RenderEffectList(
                this, m_localPlayerObjectPane->m_secondaryEffectObjectPanes);
        }
    }

    if (shadowEnabled && m_dayNightTargetBrightness != 1.0f)
    {
        RectBounds alphaBounds;
        GetClipRect(&alphaBounds);
        g_pfnBlitAlphaLookup(
            this, m_selectionOverlay, &alphaBounds, &alphaBounds);
    }
    else if (!shadowEnabled)
    {
        g_pPaletteLib->SetPaletteFilterActive(false);
    }

    if (blindnessLevel == 0)
    {
        List *objectInfoObjects = m_objectList->GetTertiaryGlobalList();
        for (int index = 0; index < objectInfoObjects->GetCount(); ++index)
        {
            ObjectInfoObjectPane *objectInfo =
                static_cast<ObjectInfoObjectPane *>(
                    GetObjectPaneAt(objectInfoObjects, index));
            objectInfo->UpdatePosition();
            RectBounds objectBounds;
            if (GetVisibleObjectBounds(this, objectInfo, &objectBounds))
                objectInfo->RenderFrame(this, &objectBounds);
        }

        RenderObjectList(this, m_objectList->GetVisibleObjectList());
        RenderObjectList(this, m_objectList->GetSecondaryGlobalList());
        if (g_pConfig->m_showDamage)
            RenderObjectList(this, m_objectList->GetAlternateGlobalList());
    }

    RectBounds unusedFinalClipBounds;
    GetClipRect(&unusedFinalClipBounds);
}

// UID:0004RA | by-memory/0x0050a500-0x0050a837.MapPaneOnPaint.md | Completion:92 | Confidence:93
void MapPane::OnPaint()
{
    if (m_highlightedObjectPane != NULL &&
        (m_highlightedObjectPane->m_terminalAnimation ||
         (m_highlightedObjectPane->m_objectStatus.m_statusKind ==
              ObjectStatusBlob::HumanObject &&
          m_highlightedObjectPane->m_objectStatus.m_compositionMode == 5 &&
          m_highlightedObjectPane->HasGMNameSuffix())))
    {
        m_highlightedObjectPane->SetHighlighted(false);
        m_highlightedObjectPane = NULL;
    }

    if (m_screenEffecterCount <= 0 &&
        static_cast<signed char>(m_mapResourceMode) > 0 &&
        g_pConfig->m_mapEffectEnabled)
    {
        ConfigureScreenEffecterList(
            static_cast<signed char>(m_mapResourceMode));
    }

    if (m_deferMotionMessages && m_deferredMotionRecordCount > 0)
    {
        unsigned int dirtyArea = 0;
        for (int index = 0; index < m_deferredMotionRecordCount; ++index)
        {
            RectBounds dirtyBounds;
            m_deferredMotionRecords[index].GetRect(&dirtyBounds);
            dirtyArea +=
                (dirtyBounds.right - dirtyBounds.left) *
                (dirtyBounds.bottom - dirtyBounds.top);
        }

        RectBounds clipBounds;
        GetClipRect(&clipBounds);
        const unsigned int clipArea =
            (clipBounds.right - clipBounds.left) *
            (clipBounds.bottom - clipBounds.top);

        Point origin;
        GetOrigin(&origin);

        if (clipArea <= dirtyArea * 2)
        {
            RenderMapView();
        }
        else
        {
            Region savedExposedRegion;
            savedExposedRegion.CopyRectFrom(&m_exposedRegion);

            for (int index = 0; index < m_deferredMotionRecordCount; ++index)
            {
                m_exposedRegion.SetRect(&m_bounds);
                m_exposedRegion.IntersectWith(
                    m_deferredMotionRecords[index]);
                m_exposedRegion.Offset(origin.x, origin.y);
                RenderMapView();
            }

            m_exposedRegion.CopyRectFrom(&savedExposedRegion);
        }
    }
    else
    {
        RenderMapView();
        m_deferMotionMessages = true;
    }

    m_deferredMotionRecordCount = 0;
}

// UID:0004RB | by-memory/0x0050a840-0x0050a8b0.MapPaneComputeDayNightBrightnessAndTintRaw.md | Completion:91 | Confidence:92
void MapPane::ComputeDayNightBrightnessAndTint(
    unsigned char hour,
    float brightnessScale,
    float brightnessBias,
    float *outBrightness,
    float *outTintAmount) const
{
    float brightness =
        (s_dayNightBrightnessByHour[hour] - 0.5f) * brightnessScale +
        0.5f + brightnessBias;

    if (brightness < 0.0f)
        brightness = 0.0f;
    else if (brightness > 1.0f)
        brightness = 1.0f;

    *outBrightness = brightness;

    const float delta = brightness - m_currentDayNightBrightness;
    *outTintAmount =
        m_dayNightTintCurveScale * delta * delta +
        m_dayNightTintCurveBase;
}

// UID:0004RC | by-memory/0x0050a8b0-0x0050a932.MapPaneSetDayNightFadeTarget.md | Completion:92 | Confidence:94
void MapPane::SetDayNightFadeTarget(
    float targetBrightness,
    float tintAmount)
{
    if (targetBrightness != m_dayNightTargetBrightness ||
        tintAmount != m_dayNightTintAmount)
    {
        m_dayNightTargetBrightness = targetBrightness;
        m_dayNightTintAmount = tintAmount;
        m_newHumanProjectionDivisor = 2.0f;
        m_newHumanProjectionShear = 0.8f;

        if (!g_pConfig->m_shadowEnabled)
        {
            g_pPaletteLib->UpdatePaletteFilterTables(targetBrightness);
            DrawVisibleTiles();
        }

        QueueMotionMessage(NULL);
    }
}

// UID:0004RD | by-memory/0x0050a940-0x0050a9df.MapPaneAttachObjectLighting.md | Completion:92 | Confidence:94
void MapPane::AttachObjectLighting(
    ObjectPane *anchorSource,
    int localOffsetX,
    int localOffsetY,
    int lightImageIndex)
{
    MapPoint mapPosition;
    anchorSource->GetMapPosition(&mapPosition);

    LightingObjectPane *light = new LightingObjectPane(
        anchorSource,
        mapPosition.row,
        mapPosition.column,
        localOffsetX,
        localOffsetY,
        lightImageIndex);

    m_objectList->AddObjectPane(light);
    anchorSource->AttachObject(light);
}

// UID:0004RE | by-memory/0x0050a9e0-0x0050aaef.MapPaneRenderDayNightOverlayRaw.md | Completion:91 | Confidence:92
void MapPane::RenderDayNightOverlay(const RectBounds *dirtyBounds)
{
    RectBounds overlayBounds;
    overlayBounds.left = 0;
    overlayBounds.top = 0;
    overlayBounds.right = m_selectionOverlay->m_width;
    overlayBounds.bottom = m_selectionOverlay->m_height;
    IntersectRects(
        &overlayBounds,
        dirtyBounds,
        &m_selectionOverlay->m_bounds);

    const unsigned char alpha = static_cast<unsigned char>(
        static_cast<int>(m_dayNightTargetBrightness * 32.0f + 0.5f));
    m_selectionOverlay->ApplyRectAlpha(NULL, alpha, 0);

    if (m_dayNightTargetBrightness < 0.60000002f &&
        g_pConfig->m_shadowEnabled &&
        m_objectList != NULL)
    {
        List *lights = m_objectList->GetQuaternaryGlobalList();
        for (int index = 0; index < lights->GetCount(); ++index)
        {
            LightingObjectPane *light =
                *static_cast<LightingObjectPane **>(
                    lights->GetElementAt(index));

            RectBounds lightBounds;
            light->GetLightBounds(&lightBounds);
            if (IntersectRects(dirtyBounds, &lightBounds, NULL))
            {
                MapPoint anchorPoint;
                light->GetAnchorScreenPoint(&anchorPoint);
                light->ApplyLightAtAnchor(
                    this, anchorPoint.column, anchorPoint.row);
            }
        }
    }
}

// UID:0004RG | by-memory/0x0050ab40-0x0050ab65.MapPaneShouldUseLivingObjectLightOverlay.md | Completion:92 | Confidence:94
bool MapPane::ShouldUseLivingObjectLightOverlay() const
{
    return m_dayNightTargetBrightness < 0.60000002f &&
           g_pConfig->m_shadowEnabled != 0;
}

// UID:0004RH | by-memory/0x0050ab70-0x0050ab95.MapPaneShouldOffsetElevatedLivingObjects.md | Completion:92 | Confidence:94
bool MapPane::ShouldOffsetElevatedLivingObjects() const
{
    return m_dayNightTargetBrightness >= 0.60000002f &&
           g_pConfig->m_shadowEnabled != 0;
}

// UID:0004Q8 | by-memory/0x0050b080-0x0050b139.MapPaneGetObjectScreenPoint.md | Completion:91 | Confidence:93
MapPoint *MapPane::GetObjectScreenPoint(
    ObjectPane *object,
    MapPoint *outPoint) const
{
    object->GetMapPosition(outPoint);
    outPoint->row =
        (outPoint->row - m_tileOriginY + 1) * g_mapTilePixelHeight;
    outPoint->column =
        (outPoint->column - m_tileOriginX + 1) * g_mapTilePixelWidth;

    if (object->m_objectType == kObjectPaneTypeLiving)
    {
        LivingObjectPane *living = static_cast<LivingObjectPane *>(object);
        if (living->m_isMoving)
        {
            MapPoint step;
            DirectionToTileOffset(&step, living->m_facing);
            const int divisor = 4 * g_movementSubstepScale;
            outPoint->row +=
                living->m_moveFrame * step.row * g_mapTilePixelHeight / divisor;
            outPoint->column +=
                living->m_moveFrame * step.column * g_mapTilePixelWidth / divisor;
        }
    }

    return outPoint;
}

// UID:0004Q9 | by-memory/0x0050b140-0x0050b18c.MapPaneFlashMapColor.md | Completion:90 | Confidence:92
void MapPane::FlashMapColor(int drawColor)
{
    m_mapFlashColor = drawColor;
    InvalidateRect(NULL);
    g_pScreenPane->RenderPresentation();
    Sleep(100);
    m_mapFlashColor = 0;
    InvalidateRect(NULL);
    g_pScreenPane->RenderPresentation();
}

// UID:0004QA | by-memory/0x0050b190-0x0050b1a7.MapPaneFinishVisibleObjectRefresh.md | Completion:90 | Confidence:92
void MapPane::FinishVisibleObjectRefresh()
{
    m_objectList->RemoveMarkedVisibleObjects();
    m_visibleObjectRefreshPending = false;
}

// UID:0004QB | by-memory/0x0050b1b0-0x0050b2af.MapPaneInteractWithObject.md | Completion:92 | Confidence:94
void MapPane::InteractWithObject(LivingObjectPane *target)
{
    ObjectStatusBlob status;
    target->GetSpriteConfig(&status);

    unsigned char packet[80];
    PacketBufferWriteUInt8(0x43, packet);
    PacketBufferWriteUInt8(0x01, packet + 1);
    PacketBufferWriteUInt32BE(target->m_objectId, packet + 2);

    if (status.m_statusKind == ObjectStatusBlob::HumanObject)
    {
        if (m_objectInteractionTimerActive)
            return;

        m_objectInteractionTimerActive = true;
        g_packetSender->QueueAndSendPacket(packet, 6);
        TimerHandler::ScheduleTimer(5, 4000, 0, 0);
        return;
    }

    g_packetSender->QueueAndSendPacket(packet, 6);
}

// UID:0004QC | by-memory/0x0050b2b0-0x0050b990.MapPaneCollectMovementTargetObjectIds.md | Completion:91 | Confidence:93
extern unsigned int s_selectObjectTargetId;

void MapPane::CollectMovementTargetObjectIds(
    std::vector<unsigned int> &objectIds) const
{
    MapPoint userPosition;
    g_pUserPane->GetMapPosition(&userPosition);

    if (g_pUserPane->m_actionMode == 2)
    {
        MapRect visibleBounds;
        GetClampedVisibleTileBounds(&visibleBounds);

        for (int row = visibleBounds.top; row < visibleBounds.bottom; ++row)
        {
            List *objects = m_objectList->GetFrontRowBucket(row);
            for (int index = 0; index < objects->GetCount(); ++index)
            {
                ObjectPane *object =
                    *static_cast<ObjectPane **>(objects->GetElementAt(index));
                MapPoint objectPosition;
                object->GetMapPosition(&objectPosition);

                bool includeObject = false;
                switch (g_pUserPane->m_facing)
                {
                case 0:
                    includeObject = objectPosition.row < userPosition.row &&
                        (objectPosition.column == userPosition.column ||
                         (g_pUserPane->m_includeAdjacentMovementTargets == true &&
                          (objectPosition.column == userPosition.column - 1 ||
                           objectPosition.column == userPosition.column + 1)));
                    break;

                case 1:
                    includeObject = objectPosition.column > userPosition.column &&
                        (objectPosition.row == userPosition.row ||
                         (g_pUserPane->m_includeAdjacentMovementTargets == true &&
                          (objectPosition.row == userPosition.row - 1 ||
                           objectPosition.row == userPosition.row + 1)));
                    break;

                case 2:
                    includeObject = objectPosition.row > userPosition.row &&
                        (objectPosition.column == userPosition.column ||
                         (g_pUserPane->m_includeAdjacentMovementTargets == true &&
                          (objectPosition.column == userPosition.column - 1 ||
                           objectPosition.column == userPosition.column + 1)));
                    break;

                case 3:
                    includeObject = objectPosition.column < userPosition.column &&
                        (objectPosition.row == userPosition.row ||
                         (g_pUserPane->m_includeAdjacentMovementTargets == true &&
                          (objectPosition.row == userPosition.row - 1 ||
                           objectPosition.row == userPosition.row + 1)));
                    break;
                }

                if (includeObject)
                    objectIds.push_back(object->m_objectId);
            }
        }
        return;
    }

    ObjectPane *target = m_objectList->FindByObjectId(s_selectObjectTargetId);
    if (target != NULL)
        objectIds.push_back(target->m_objectId);

    if (g_pUserPane->m_includeAdjacentMovementTargets == true)
    {
        MapPoint targetPosition;
        target->GetMapPosition(&targetPosition);

        MapRect visibleBounds;
        GetClampedVisibleTileBounds(&visibleBounds);
        for (int row = visibleBounds.top; row < visibleBounds.bottom; ++row)
        {
            List *objects = m_objectList->GetFrontRowBucket(row);
            for (int index = 0; index < objects->GetCount(); ++index)
            {
                ObjectPane *object =
                    *static_cast<ObjectPane **>(objects->GetElementAt(index));
                MapPoint objectPosition;
                object->GetMapPosition(&objectPosition);
                if (objectPosition.column >= targetPosition.column - 1 &&
                    objectPosition.column <= targetPosition.column + 1 &&
                    objectPosition.row >= targetPosition.row - 1 &&
                    objectPosition.row <= targetPosition.row + 1 &&
                    (objectPosition.column != targetPosition.column ||
                     objectPosition.row != targetPosition.row))
                {
                    objectIds.push_back(object->m_objectId);
                }
            }
        }
    }
}

// UID:0004QD | by-memory/0x0050b990-0x0050bbb0.MapPaneSortMovementTargetObjectIdsByDistance.md | Completion:91 | Confidence:93
void MapPane::SortMovementTargetObjectIdsByDistance(
    std::vector<unsigned int> &objectIds) const
{
    MapPoint userPosition;
    g_pUserPane->GetMapPosition(&userPosition);

    for (std::vector<unsigned int>::size_type first = 0;
         first + 1 < objectIds.size(); ++first)
    {
        std::vector<unsigned int>::size_type nearest = first;
        ObjectPane *nearestObject =
            m_objectList->FindByObjectId(objectIds[nearest]);
        MapPoint nearestPosition;
        nearestObject->GetMapPosition(&nearestPosition);
        int deltaX = nearestPosition.column - userPosition.column;
        int deltaY = nearestPosition.row - userPosition.row;
        int nearestDistance = deltaX * deltaX + deltaY * deltaY;

        for (std::vector<unsigned int>::size_type candidate = first + 1;
             candidate < objectIds.size(); ++candidate)
        {
            ObjectPane *candidateObject =
                m_objectList->FindByObjectId(objectIds[candidate]);
            MapPoint candidatePosition;
            candidateObject->GetMapPosition(&candidatePosition);
            deltaX = candidatePosition.column - userPosition.column;
            deltaY = candidatePosition.row - userPosition.row;
            const int candidateDistance = deltaX * deltaX + deltaY * deltaY;
            if (candidateDistance < nearestDistance)
            {
                nearest = candidate;
                nearestDistance = candidateDistance;
            }
        }

        if (nearest != first)
            std::swap(objectIds[first], objectIds[nearest]);
    }
}

// UID:0004QE | by-memory/0x0050bbb0-0x0050bcd8.MapPaneChangeMap.md | Completion:91 | Confidence:93
void MapPane::ChangeMap(
    unsigned short mapId,
    short mapWidth,
    short mapHeight,
    unsigned char weatherMode,
    unsigned char transitionState,
    int loadOption)
{
    const bool mapChanged = mapId != m_mapId;
    if (mapChanged)
    {
        SaveCompressedMapFile();
        if (g_pConfig->m_musicSourceMode == 0)
            g_pSoundManager->StopStreamAndResetZone(3000);
    }

    if (m_objectList != NULL)
    {
        m_objectList->DetachAll(m_localPlayerObjectPane);
        delete m_objectList;
    }

    m_objectList = new ObjectList(m_visibleTileColumns, m_visibleTileRows);
    m_mapWidth = mapWidth;
    m_mapHeight = mapHeight;
    m_mapTransitionState = transitionState;
    m_mapId = mapId;
    SetMapState(m_weatherType, weatherMode);

    if (mapChanged)
        LoadCompressedMapFile(mapId, loadOption);

    DrawVisibleTiles();
    InvalidateRect(&m_bounds);
}

// UID:00037Y | by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md | Completion:87 | Confidence:89
// No single C++ body should be emitted for [UID:00037Y].
// This range is a MapPane-owned method cluster. Split exact child helpers first,
// then emit C++ on the child pages that correspond to individual source methods.

// UID:0004YB | by-memory/0x0050c550-0x0050c5d2.MapPaneFindItemObjectAtMapPoint.md | Completion:92 | Confidence:94
ObjectPane *MapPane::FindItemObjectAtMapPoint(int y, int x)
{
    List *itemObjects = m_objectList->GetPrimaryCellList();
    for (int index = itemObjects->GetCount() - 1; index >= 0; --index) {
        ObjectPane *itemObject =
            *static_cast<ObjectPane **>(itemObjects->GetElementAt(index));
        RectBounds bounds;
        itemObject->GetBounds(&bounds);
        if (PointInRect(y, x, &bounds))
            return itemObject;
    }
    return NULL;
}

// UID:0004PZ | by-memory/0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer.md | Completion:92 | Confidence:94
void MapPane::AllocateTileBuffer()
{
    unsigned int tileCount = m_mapWidth * m_mapHeight;
    m_tileBuffer = new MapPaneTileRecord[tileCount];
    memset(
        m_tileBuffer,
        0,
        tileCount * sizeof(MapPaneTileRecord));
}

// UID:000232 | by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md | Completion:92 | Confidence:94
void MapPane::RequestObjectEffect(
    unsigned int objectId,
    int effectDescriptorId,
    int timerAction,
    bool renderAfterLivingObjects)
{
    EffectInfo effectInfo;
    EffectObjImageLibGetEffectInfo(&effectInfo, effectDescriptorId);

    ObjectPane *objectPane = m_objectList->FindByObjectId(objectId);
    if (objectPane == NULL)
        return;

    LivingObjectPane *target =
        static_cast<LivingObjectPane *>(objectPane);

    if (effectInfo.secondaryFrameCount > 0)
    {
        bool reused = false;

        if (effectInfo.secondaryRangeStart >= 0 &&
            effectInfo.secondaryRangeEnd >= 0)
        {
            const int count = target->m_secondaryEffectObjectPanes->GetCount();
            for (int index = count - 1; index >= 0; --index)
            {
                EffectObjectPane *effectObject =
                    *static_cast<EffectObjectPane **>(
                        target->m_secondaryEffectObjectPanes->GetElementAt(index));
                if (effectObject != NULL &&
                    effectObject->m_effectId == effectInfo.effectKeyOrId &&
                    effectObject->IsLooping())
                {
                    ApplyEffectObjectPaneTimerAction(effectObject, timerAction);
                    reused = true;
                    break;
                }
            }
        }

        if (!reused)
        {
            MapPoint position;
            target->GetMapPosition(&position);
            CreateEffectObjectPane(
                target,
                position.row,
                position.column,
                effectInfo,
                timerAction,
                0,
                renderAfterLivingObjects);
        }
    }

    if (effectInfo.primaryFrameCount > 0)
    {
        bool reused = false;

        if (effectInfo.primaryRangeStart >= 0 &&
            effectInfo.primaryRangeEnd >= 0)
        {
            const int count = target->m_primaryEffectObjectPanes->GetCount();
            for (int index = count - 1; index >= 0; --index)
            {
                EffectObjectPane *effectObject =
                    *static_cast<EffectObjectPane **>(
                        target->m_primaryEffectObjectPanes->GetElementAt(index));
                if (effectObject != NULL &&
                    effectObject->m_effectId == effectInfo.effectKeyOrId &&
                    effectObject->IsLooping())
                {
                    ApplyEffectObjectPaneTimerAction(effectObject, timerAction);
                    reused = true;
                    break;
                }
            }
        }

        if (!reused)
        {
            MapPoint position;
            target->GetMapPosition(&position);
            CreateEffectObjectPane(
                target,
                position.row,
                position.column,
                effectInfo,
                timerAction,
                1,
                renderAfterLivingObjects);
        }
    }
}

// UID:0003TB | by-memory/0x0050e4c0-0x0050e68d.MapPaneRefreshGroupMemberHitBar.md | Completion:92 | Confidence:93
void MapPane::RefreshGroupMemberHitBar(unsigned int memberId)
{
    if (g_pUserPane->GetObjectId() == memberId)
        return;

    if (!g_pConfig->m_groupBarEnabled)
        return;

    GroupMemberRecord *member =
        g_pUserPane->FindGroupMemberById(memberId);
    if (!member)
        return;

    LivingObjectPane *objectPane = static_cast<LivingObjectPane *>(
        m_objectList->FindByObjectId(memberId));
    if (!objectPane)
        return;

    ApplyHitBarObjectPane(
        objectPane,
        member->currentHitPoints,
        member->maximumHitPoints,
        member->currentManaPoints,
        member->maximumManaPoints);
}

// UID:0003TC | by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md | Completion:92 | Confidence:93
void MapPane::ApplyHitBarObjectPane(
    LivingObjectPane *objectPane,
    unsigned int primaryValue,
    unsigned int primaryMaximum,
    unsigned int secondaryValue,
    unsigned int secondaryMaximum)
{
    unsigned short primaryPercent;
    if (primaryValue < 10000000)
        primaryPercent = static_cast<unsigned short>(
            primaryValue * 100 / primaryMaximum);
    else
        primaryPercent = static_cast<unsigned short>(
            primaryValue / (primaryMaximum / 100));

    unsigned short secondaryPercent;
    if (secondaryValue < 10000000)
        secondaryPercent = static_cast<unsigned short>(
            secondaryValue * 100 / secondaryMaximum);
    else
        secondaryPercent = static_cast<unsigned short>(
            secondaryValue / (secondaryMaximum / 100));

    if (!objectPane)
        return;

    MapPoint mapPosition;
    objectPane->GetMapPosition(&mapPosition);

    HitBarObjectPane *hitBarObjectPane = objectPane->m_hitBarObjectPane;
    if (hitBarObjectPane)
    {
        if (hitBarObjectPane->IsActive() == true)
        {
            hitBarObjectPane->SetValues(
                primaryPercent,
                100,
                secondaryPercent,
                100);
            return;
        }

        m_objectList->RemoveObjectPane(hitBarObjectPane);
        delete hitBarObjectPane;
    }

    hitBarObjectPane = new HitBarObjectPane(
        objectPane,
        mapPosition.row,
        mapPosition.column,
        primaryPercent,
        100,
        secondaryPercent,
        100);
    objectPane->SetHitBarObjectPane(hitBarObjectPane);
    m_objectList->AddObjectPane(hitBarObjectPane);
    hitBarObjectPane->UpdatePosition();

    RectBounds bounds;
    hitBarObjectPane->GetBounds(&bounds);
    hitBarObjectPane->InvalidateRect(&bounds);
}

// UID:0003TD | by-memory/0x0050e810-0x0050e848.MapPaneRemoveGroupMemberHitBar.md | Completion:91 | Confidence:93
void MapPane::RemoveGroupMemberHitBar(unsigned int memberId)
{
    LivingObjectPane *objectPane = static_cast<LivingObjectPane *>(
        m_objectList->FindByObjectId(memberId));
    if (!objectPane)
        return;

    HitBarObjectPane *hitBarObjectPane = objectPane->m_hitBarObjectPane;
    if (hitBarObjectPane && hitBarObjectPane->IsActive())
        delete hitBarObjectPane;
}

// UID:0003TE | by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md | Completion:92 | Confidence:94
void MapPane::RequestCoordinateEffect(
    int mapColumn,
    int mapRow,
    int effectDescriptorId,
    int timerAction,
    bool renderAfterLivingObjects)
{
    MapRect visibleBounds;
    GetClampedVisibleTileBounds(&visibleBounds);
    if (!PointInRect(mapRow, mapColumn, &visibleBounds))
        return;

    EffectInfo effectInfo;
    EffectObjImageLibGetEffectInfo(&effectInfo, effectDescriptorId);

    if (effectInfo.secondaryFrameCount > 0)
    {
        EffectObjectPane *matchingEffect = NULL;

        if (effectInfo.secondaryRangeStart >= 0 &&
            effectInfo.secondaryRangeEnd >= 0)
        {
            List *effects = m_objectList->GetSecondaryRowBucket(mapRow);
            for (int index = effects->GetCount() - 1; index >= 0; --index)
            {
                EffectObjectPane *effectObject =
                    *static_cast<EffectObjectPane **>(
                        effects->GetElementAt(index));
                MapPoint position;
                effectObject->GetMapPosition(&position);
                if (position.column == mapColumn &&
                    effectObject->m_effectId == effectInfo.effectKeyOrId &&
                    effectObject->IsLooping())
                {
                    matchingEffect = effectObject;
                    break;
                }
            }
        }

        if (matchingEffect != NULL)
        {
            ApplyEffectObjectPaneTimerAction(matchingEffect, timerAction);
        }
        else
        {
            CreateEffectObjectPane(
                NULL,
                mapRow,
                mapColumn,
                effectInfo,
                timerAction,
                0,
                renderAfterLivingObjects);
        }
    }

    if (effectInfo.primaryFrameCount > 0)
    {
        EffectObjectPane *matchingEffect = NULL;

        if (effectInfo.primaryRangeStart >= 0 &&
            effectInfo.primaryRangeEnd >= 0)
        {
            List *effects = m_objectList->GetPrimaryRowBucket(mapRow);
            for (int index = effects->GetCount() - 1; index >= 0; --index)
            {
                EffectObjectPane *effectObject =
                    *static_cast<EffectObjectPane **>(
                        effects->GetElementAt(index));
                MapPoint position;
                effectObject->GetMapPosition(&position);
                if (position.column == mapColumn &&
                    effectObject->m_effectId == effectInfo.effectKeyOrId &&
                    effectObject->IsLooping())
                {
                    matchingEffect = effectObject;
                    break;
                }
            }
        }

        if (matchingEffect != NULL)
        {
            ApplyEffectObjectPaneTimerAction(matchingEffect, timerAction);
        }
        else
        {
            CreateEffectObjectPane(
                NULL,
                mapRow,
                mapColumn,
                effectInfo,
                timerAction,
                1,
                renderAfterLivingObjects);
        }
    }
}

// UID:0003TF | by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md | Completion:92 | Confidence:94
void MapPane::CreateEffectObjectPane(
    LivingObjectPane *target,
    int mapRow,
    int mapColumn,
    EffectInfo effectInfo,
    int timerAction,
    int sequenceIndex,
    bool renderAfterLivingObjects)
{
    if (timerAction == -1)
        return;

    int rangeStart = effectInfo.secondaryRangeStart;
    int rangeEnd = effectInfo.secondaryRangeEnd;
    if (sequenceIndex == 1)
    {
        rangeStart = effectInfo.primaryRangeStart;
        rangeEnd = effectInfo.primaryRangeEnd;
    }

    int timerDelay = timerAction;
    if (timerDelay > 0)
        timerDelay *= 1000;

    EffectObjectPane *effectObjectPane = new EffectObjectPane(
        target,
        mapRow,
        mapColumn,
        effectInfo,
        sequenceIndex,
        renderAfterLivingObjects);

    if (target != NULL)
    {
        if (sequenceIndex == 0)
            target->AddSecondaryEffectObjectPane(effectObjectPane);
        else if (sequenceIndex == 1)
            target->AddPrimaryEffectObjectPane(effectObjectPane);
    }

    m_objectList->AddObjectPane(effectObjectPane);
    effectObjectPane->StartIdleTimer();

    if (timerDelay != -2 &&
        rangeStart >= 0 &&
        rangeEnd >= 0)
    {
        g_pTimerMgr->ScheduleTimer(
            static_cast<TimerHandler *>(effectObjectPane),
            2,
            timerDelay,
            0,
            0);
    }

    if (target != NULL)
        effectObjectPane->UpdatePosition();

    RectBounds bounds;
    effectObjectPane->GetBounds(&bounds);
    effectObjectPane->InvalidateRect(&bounds);
}

// UID:0003TG | by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md | Completion:92 | Confidence:94
void MapPane::ApplyEffectObjectPaneTimerAction(
    EffectObjectPane *effectObjectPane,
    int timerAction)
{
    if (effectObjectPane == NULL)
        return;

    if (timerAction == -1)
    {
        delete effectObjectPane;
        return;
    }

    if (timerAction == 0)
        return;

    TimerHandler *timerHandler =
        static_cast<TimerHandler *>(effectObjectPane);

    if (timerAction == -2)
    {
        g_pTimerMgr->CancelTimer(timerHandler, 2);
        return;
    }

    if (effectObjectPane->m_timerExtensionLocked)
        return;

    DWORD dueTick =
        g_pTimerMgr->FindQueuedTimerDueTick(timerHandler, 2);
    if (dueTick == 0)
        return;

    int remainingTime =
        static_cast<int>(dueTick - g_pTimerMgr->m_currentTick);
    if (timerAction <= remainingTime)
        return;

    g_pTimerMgr->CancelTimer(timerHandler, 2);
    g_pTimerMgr->ScheduleTimer(
        timerHandler,
        2,
        1000 * timerAction,
        0,
        0);
}

// UID:0003TH | by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPane.md | Completion:92 | Confidence:94
void MapPane::CreateHitBarObjectPane(
    LivingObjectPane *objectPane,
    unsigned short currentValue,
    unsigned short maximumValue)
{
    if (objectPane == NULL)
        return;

    MapPoint mapPosition;
    objectPane->GetMapPosition(&mapPosition);

    HitBarObjectPane *hitBarObjectPane;
    if (objectPane->m_objectStatus.m_statusKind ==
        ObjectStatusBlob::HumanObject)
    {
        hitBarObjectPane = new HitBarObjectPane(
            objectPane,
            mapPosition.row,
            mapPosition.column,
            currentValue,
            maximumValue,
            1);
    }
    else
    {
        hitBarObjectPane = new HitBarObjectPane(
            objectPane,
            mapPosition.row,
            mapPosition.column,
            currentValue,
            maximumValue,
            0);
    }

    objectPane->SetHitBarObjectPane(hitBarObjectPane);
    m_objectList->AddObjectPane(hitBarObjectPane);
    g_pTimerMgr->ScheduleTimer(
        static_cast<TimerHandler *>(hitBarObjectPane),
        0,
        500,
        0,
        0);
    hitBarObjectPane->UpdatePosition();

    RectBounds bounds;
    hitBarObjectPane->GetBounds(&bounds);
    hitBarObjectPane->InvalidateRect(&bounds);
}

// UID:0003TI | by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md | Completion:90 | Confidence:93
StaticObjectPane *MapPane::CreateStaticObjectPaneForTile(
    int tileX,
    int tileY,
    unsigned short staticObjectId,
    bool skipListInsertion)
{
    Rect objectBounds;
    g_pStaticObjImageLib->GetStaticObjectBounds(staticObjectId, &objectBounds);
    IsRectEmptyOrInvalid(&objectBounds);

    StaticObjectPane *objectPane =
        new StaticObjectPane(tileX, tileY, staticObjectId);

    StaticObjEntry *entry =
        g_pStaticObjImageLib->GetStaticObjectEntry(staticObjectId);
    if (entry != NULL && entry->lightImageIndex >= 0)
    {
        AttachObjectLighting(
            objectPane,
            g_mapTilePixelWidth,
            g_mapTilePixelHeight / 2 -
                g_mapTilePixelHeight * entry->lightHeightClass,
            entry->lightImageIndex);
    }

    UpdateObjectPaneScreenBounds(objectPane);
    if (!skipListInsertion)
        m_objectList->AddObjectPane(objectPane);

    return objectPane;
}

// UID:0003TJ | by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md | Completion:91 | Confidence:94
void MapPane::RefreshStaticObjectTileRegion(const MapRect &tileBounds)
{
    for (int tileY = tileBounds.top; tileY < tileBounds.bottom; ++tileY)
    {
        for (int tileX = tileBounds.left; tileX < tileBounds.right; ++tileX)
        {
            MapTileLayerIds tile;
            GetLegacyAwareMapTileLayerIds(&tile, tileX, tileY);

            StaticObjectPane *existingObject =
                m_objectList->FindStaticObjectPaneAt(tileX, tileY);

            if (tile.staticObjectId != 0)
            {
                if (existingObject != NULL)
                {
                    if (existingObject->GetStaticObjectId() == tile.staticObjectId)
                        continue;

                    RectBounds bounds;
                    existingObject->GetBounds(&bounds);
                    InvalidateRect(&bounds);
                    m_objectList->RemoveObjectPane(existingObject);
                    if (existingObject->GetObjectType() != kObjectPaneTypeStatic)
                        existingObject->ReleaseBackingStore();
                    delete existingObject;
                }

                CreateStaticObjectPaneForTile(
                    tileX,
                    tileY,
                    tile.staticObjectId,
                    false);
            }
            else if (existingObject != NULL)
            {
                RectBounds bounds;
                existingObject->GetBounds(&bounds);
                InvalidateRect(&bounds);
                m_objectList->RemoveObjectPane(existingObject);
                if (existingObject->GetObjectType() != kObjectPaneTypeStatic)
                    existingObject->ReleaseBackingStore();
                delete existingObject;
            }
        }
    }
}

// UID:0003TX | by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md | Completion:92 | Confidence:94
static void RefreshObjectStatusOverlay(LivingObjectPane *objectPane);

bool MapPane::HandleObjectInfoPacket(const unsigned char *packet)
{
    const int mapX = PacketBufferReadUInt16BE(packet + 1);
    const int mapY = PacketBufferReadUInt16BE(packet + 3);
    const unsigned char action = packet[5];
    const unsigned int objectId = PacketBufferReadUInt32BE(packet + 6);

    ObjectStatusBlob status;
    status.m_displayStatusByte = 80;
    status.m_actionState = 11;

    int statusBytes;
    switch (packet[10])
    {
    case 0:
        statusBytes = status.ParseFullStatus(packet + 11);
        break;

    case 1:
        statusBytes = status.ParsePartialStatus(packet + 11);
        break;

    default:
        return true;
    }

    const unsigned char objectInfoType = packet[11 + statusBytes];
    const unsigned char nameLength = packet[12 + statusBytes];

    wchar_t objectName[33];
    const int objectNameLength = MultiByteToWideChar(
        CP_ACP,
        0,
        reinterpret_cast<const char *>(packet + 13 + statusBytes),
        nameLength,
        objectName,
        32);
    objectName[objectNameLength] = L'\0';

    MapRect visibleBounds;
    GetClampedVisibleTileBounds(&visibleBounds);
    InsetRect(&visibleBounds, -1, -1);
    if (!PointInRect(mapY, mapX, &visibleBounds))
        return true;

    LivingObjectPane *objectPane =
        static_cast<LivingObjectPane *>(
            CreateOrUpdateObjectPane(
                objectId,
                mapX,
                mapY,
                action,
                status));

    wcscpy_s(objectPane->m_nameBuffer, 33, objectName);
    objectPane->m_objectInfoType = objectInfoType;

    if (objectInfoType != 3 || objectPane != m_localPlayerObjectPane)
    {
        ObjectInfoObjectPane *objectInfoPane;

        switch (objectInfoType)
        {
        case 1:
            objectInfoPane = new ObjectInfoObjectPane(
                objectPane,
                mapY,
                mapX,
                objectName,
                12,
                status.m_invisible,
                status.m_faceShape);
            objectInfoPane->SetSelectedName(L"");
            objectInfoPane->m_tracksSelectedName = true;
            break;

        case 2:
            objectInfoPane = new ObjectInfoObjectPane(
                objectPane,
                mapY,
                mapX,
                objectName,
                39,
                status.m_invisible,
                status.m_faceShape);
            objectInfoPane->SetSelectedName(L"");
            objectInfoPane->m_tracksSelectedName = true;
            break;

        case 3:
            objectInfoPane = new ObjectInfoObjectPane(
                objectPane,
                mapY,
                mapX,
                objectName,
                224,
                status.m_invisible,
                status.m_faceShape);
            objectInfoPane->SetSelectedName(L"");
            objectInfoPane->m_tracksSelectedName = true;
            break;

        default:
            objectInfoPane = new ObjectInfoObjectPane(
                objectPane,
                mapY,
                mapX,
                objectName,
                55,
                status.m_invisible,
                status.m_faceShape);
            objectInfoPane->m_tracksSelectedName = false;
            break;
        }

        objectPane->SetObjectInfoObjectPane(objectInfoPane);
        m_objectList->AddObjectPane(objectInfoPane);
        objectInfoPane->UpdatePosition();

        RectBounds bounds;
        objectInfoPane->GetBounds(&bounds);
        objectInfoPane->InvalidateRect(&bounds);
    }

    RefreshObjectStatusOverlay(objectPane);
    RefreshGroupMemberHitBar(objectId);
    return true;
}

// UID:0003TY | by-memory/0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket.md | Completion:92 | Confidence:94
bool MapPane::HandleMapTransitionPacket(const unsigned char *packet)
{
    SelfLookPane *selfLookPane = static_cast<SelfLookPane *>(
        g_pGeneralPurposePanel->GetChildPaneByIndex(0));
    selfLookPane->StopSpelledPaneRefresh();

    NewSystemMessagePane *systemMessagePane =
        static_cast<NewSystemMessagePane *>(
            g_pGeneralPurposePanel2->GetChildPaneByIndex(0));
    systemMessagePane->StopSpelledPaneRefresh();

    DATFile datFile;

    if (m_localPlayerObjectPane != NULL)
    {
        g_pTimerMgr->RemovePendingTimersForOwner(
            &m_localPlayerObjectPane->m_timerHandler);
    }

    if (g_pTransferServerDialog == NULL)
        new TransferServerDialogPane(false);

    unsigned long serverAddress =
        (static_cast<unsigned long>(packet[1]) << 24) |
        (static_cast<unsigned long>(packet[2]) << 16) |
        (static_cast<unsigned long>(packet[3]) << 8) |
        static_cast<unsigned long>(packet[4]);
    unsigned short serverPort = static_cast<unsigned short>(
        (static_cast<unsigned short>(packet[5]) << 8) |
        static_cast<unsigned short>(packet[6]));
    unsigned char tokenLength = packet[7];

    unsigned char transferToken[256];
    GetMemoryMan()->MemmoveWrapper(
        transferToken, packet + 8, tokenLength);
    transferToken[tokenLength] = 0;

    if (serverAddress == 0 && serverPort == 0)
    {
        if (g_pTransferServerDialog == NULL)
            new TransferServerDialogPane(false);
        return true;
    }

    if (g_packetSender->IsSocketConnectedState())
    {
        bool connectionAvailable;
        g_packetSender->PostReconnectEndpointCommand(
            serverAddress, serverPort);
        HANDLE statusEvent =
            g_packetSender->PostConnectionStatusQuery(&connectionAvailable);
        g_packetSender->WaitForResult(statusEvent);

        if (connectionAvailable)
            goto sendTransferPacket;

        HKEY rootKey;
        HKEY installKey;
        DWORD disposition;
        unsigned long fallbackAddress;
        unsigned short fallbackPort;

        LONG result = g_pfnRegCreateKeyExW(
            HKEY_LOCAL_MACHINE,
            L"SOFTWARE\\Nexon\\Kingdom of the Winds",
            0,
            NULL,
            REG_OPTION_NON_VOLATILE,
            KEY_ALL_ACCESS,
            NULL,
            &rootKey,
            &disposition);

        if (result == ERROR_SUCCESS)
        {
            wchar_t currentDirectory[MAX_PATH];
            g_pfnGetCurrentDirectoryW(MAX_PATH, currentDirectory);
            result = g_pfnRegCreateKeyExW(
                rootKey,
                currentDirectory,
                0,
                NULL,
                REG_OPTION_NON_VOLATILE,
                KEY_ALL_ACCESS,
                NULL,
                &installKey,
                &disposition);

            if (result == ERROR_SUCCESS)
            {
                RegCloseKey(installKey);
                fallbackAddress = 0;
                fallbackPort = 0;
            }
            else
            {
                fallbackAddress = reinterpret_cast<unsigned long>(installKey);
                fallbackPort = static_cast<unsigned short>(
                    reinterpret_cast<unsigned long>(installKey));
            }

            RegCloseKey(rootKey);
        }
        else
        {
            fallbackAddress = reinterpret_cast<unsigned long>(installKey);
            fallbackPort = static_cast<unsigned short>(
                reinterpret_cast<unsigned long>(installKey));
        }

        if (fallbackAddress == 0 && fallbackPort == 0)
        {
            new TransferServerDialogPane(true);
            return true;
        }

        bool ignoredConnectionAvailable;
        g_packetSender->PostReconnectEndpointCommand(
            fallbackAddress, fallbackPort);
        statusEvent = g_packetSender->PostConnectionStatusQuery(
            &ignoredConnectionAvailable);
        g_packetSender->WaitForResult(statusEvent);
    }

sendTransferPacket:
    unsigned char outgoingPacket[1024];
    outgoingPacket[0] = 0x10;
    GetMemoryMan()->MemmoveWrapper(
        outgoingPacket + 1, transferToken, tokenLength);
    outgoingPacket[tokenLength + 1] = g_useEpfAssets;
    outgoingPacket[tokenLength + 2] = 0;

    g_packetSender->SetSocketSendDisabled(false);
    g_packetSender->QueueAndSendPacket(
        outgoingPacket, static_cast<short>(tokenLength + 2));
    g_pCrashTarget->SendStoredCrashReportFile();
    g_packetSender->SetSocketSendDisabled(true);
    g_pUserPane->ClearDeferredUserListPacket();
    return true;
}

// UID:0003TK | by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md | Completion:92 | Confidence:94
namespace
{
    enum EffectMapStatePacketFlags
    {
        kEffectMapStateWeatherMode = 0x01,
        kEffectMapStateDisableMovementStatusTag = 0x02,
        kEffectMapStateRuntimeMode = 0x08
    };

    struct EffectMapStatePacketView
    {
        EffectMapStatePacketView(
            const unsigned char *packetBytes,
            MemoryMan *memoryManager)
            : bytes(packetBytes), cursor(1), memoryMan(memoryManager)
        {
        }

        unsigned char ReadByte()
        {
            return bytes[cursor++];
        }

        unsigned short ReadUInt16()
        {
            unsigned short value = PacketBufferReadUInt16BE(bytes + cursor);
            cursor += 2;
            return value;
        }

        int ReadAnsiString(char *buffer)
        {
            int byteCount = ReadByte();
            memoryMan->MemmoveWrapper(buffer, bytes + cursor, byteCount);
            buffer[byteCount] = '\0';
            cursor += byteCount;
            return byteCount;
        }

        const unsigned char *bytes;
        int cursor;
        MemoryMan *memoryMan;
    };
}

bool MapPane::HandleEffectMapStatePacket(const unsigned char *packet)
{
    char mapNameBytes[256];
    wchar_t mapName[256];

    MemoryMan *memoryMan = GetMemoryMan();
    EffectMapStatePacketView packetView(packet, memoryMan);

    unsigned short mapId = packetView.ReadUInt16();
    short mapWidth = static_cast<short>(packetView.ReadUInt16());
    short mapHeight = static_cast<short>(packetView.ReadUInt16());
    unsigned char flags = packetView.ReadByte();
    unsigned char transitionMode = packetView.ReadByte();

    int mapNameByteCount = packetView.ReadAnsiString(mapNameBytes);
    unsigned char mapNameLength = static_cast<unsigned char>(
        MultiByteToWideChar(
            CP_ACP, 0, mapNameBytes, mapNameByteCount, mapName, 256));
    mapName[mapNameLength] = L'\0';

    unsigned short dayNightAdjustment = packetView.ReadUInt16();
    unsigned char targetSelectionSuppressed = packetView.ReadByte();

    m_mapRuntimeMode =
        (flags & kEffectMapStateRuntimeMode) != 0;

    if (m_visibleObjectRefreshPending ||
        mapId != m_mapId ||
        mapWidth != m_mapWidth ||
        mapHeight != m_mapHeight)
    {
        m_visibleObjectRefreshPending = false;

        bool mapChanged = mapId != m_mapId;
        if (mapChanged)
        {
            SaveCompressedMapFile();
            if (g_pConfig->m_musicSourceMode == 0)
                g_pSoundManager->StopStreamAndResetZone(3000);
        }

        if (m_objectList != NULL)
        {
            m_objectList->DetachAll(m_localPlayerObjectPane);
            delete m_objectList;
        }

        m_objectList = new ObjectList(
            m_visibleTileColumns, m_visibleTileRows);
        m_mapHeight = mapHeight;
        m_mapTransitionState = transitionMode == 0;
        m_mapId = mapId;
        m_mapWidth = mapWidth;

        SetMapState(
            m_weatherType,
            static_cast<unsigned char>(
                flags & kEffectMapStateWeatherMode));

        if (mapChanged)
            LoadCompressedMapFile(mapId, 0);

        DrawVisibleTiles();
        InvalidateRect(&m_bounds);
    }

    m_movementStatusTagDisabled =
        (flags & kEffectMapStateDisableMovementStatusTag) != 0;

    unsigned char brightnessScaleCode =
        static_cast<unsigned char>(dayNightAdjustment / 100);
    if (brightnessScaleCode == 0)
        m_dayNightBrightnessScale = 1.0f;
    else
        m_dayNightBrightnessScale =
            (brightnessScaleCode - 1) * 0.25f;

    unsigned char brightnessBiasCode =
        static_cast<unsigned char>(dayNightAdjustment % 100);
    if (brightnessBiasCode == 0)
    {
        m_dayNightBrightnessBias = 0.0f;
    }
    else if (brightnessBiasCode < 16)
    {
        m_dayNightBrightnessBias =
            static_cast<float>(brightnessBiasCode - 16) / 15.0f;
    }
    else
    {
        m_dayNightBrightnessBias =
            static_cast<float>(brightnessBiasCode - 16) * 0.0625f;
    }

    float adjustedBrightness =
        (s_dayNightBrightnessByHour[m_dayNightHour] - 0.5f) *
            m_dayNightBrightnessScale +
        0.5f +
        m_dayNightBrightnessBias;

    float brightness = 0.0f;
    if (adjustedBrightness >= 0.0f)
    {
        brightness = adjustedBrightness;
        if (brightness > 1.0f)
            brightness = 1.0f;
    }

    float brightnessDelta =
        brightness - m_currentDayNightBrightness;
    float tintAmount =
        m_dayNightTintCurveScale *
            brightnessDelta * brightnessDelta +
        m_dayNightTintCurveBase;
    SetDayNightFadeTarget(brightness, tintAmount);

    if (m_auxiliaryPane != NULL)
    {
        m_auxiliaryPane->RemoveFromLayer();
        m_auxiliaryPane->UnregisterEventHandler();
        delete m_auxiliaryPane;
        m_auxiliaryPane = NULL;

        g_pScreenPane->DetachLayerFrame(m_activeScreenLayer);
        delete m_activeScreenLayer;
        m_activeScreenLayer = NULL;
    }

    m_waitingForLocalPlayerStatus = true;

    if (g_useEpfAssets &&
        g_pConfig->m_autoMoveEnabled &&
        m_queuedMapStateRefresh)
    {
        m_rightButtonTrackingActive = false;
        ClearQueuedMapStateRefresh();
    }

    if (g_useEpfAssets &&
        !m_rightButtonTrackingActive &&
        m_queuedMapStateRefresh)
    {
        m_leftButtonTrackingActive = false;
        ClearQueuedMapStateRefresh();
    }

    g_pConfig->m_targetSelectionSuppressed =
        targetSelectionSuppressed;
    return true;
}

// UID:0003TL | by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md | Completion:90 | Confidence:90
namespace
{
    enum MapInfoTileRegionPacketFlags
    {
        kMapInfoTileRegionHasMapName = 0x01,
        kMapInfoTileRegionHasResourceName = 0x02,
        kMapInfoTileRegionHasResourceMode = 0x04
    };

    struct MapInfoTileRegionPacketView
    {
        explicit MapInfoTileRegionPacketView(const unsigned char *packetBytes)
            : bytes(packetBytes), cursor(1)
        {
        }

        unsigned char ReadByte()
        {
            return bytes[cursor++];
        }

        unsigned short ReadUInt16()
        {
            unsigned short value = PacketBufferReadUInt16BE(bytes + cursor);
            cursor += 2;
            return value;
        }

        unsigned short ReadTileWord()
        {
            return PacketBufferReadUInt16BE(bytes, &cursor);
        }

        int ReadAnsiString(char *buffer, int bufferCount)
        {
            int byteCount = ReadByte();
            int copyCount = byteCount;
            if (copyCount >= bufferCount)
                copyCount = bufferCount - 1;

            GetMemoryMan()->MemmoveWrapper(buffer, bytes + cursor, copyCount);
            buffer[copyCount] = '\0';
            cursor += byteCount;
            return copyCount;
        }

        const unsigned char *bytes;
        int cursor;
    };
}

bool MapPane::HandleMapInfoTileRegionPacket(const unsigned char *packet)
{
    char mapNameBytes[256];
    char resourceNameBytes[256];
    wchar_t epfResourceName[260];
    wchar_t palResourceName[260];

    MapInfoTileRegionPacketView packetView(packet);
    unsigned char oldResourceMode = m_mapResourceMode;
    unsigned char flags = packetView.ReadByte();

    m_mapNameLength = 0;
    m_mapResourceNameLength = 0;
    m_mapResourceMode = 0;

    if ((flags & kMapInfoTileRegionHasMapName) != 0)
    {
        int mapNameLength = packetView.ReadAnsiString(mapNameBytes, sizeof(mapNameBytes));
        m_mapNameLength = static_cast<unsigned char>(
            MultiByteToWideChar(CP_ACP, 0, mapNameBytes, mapNameLength, m_mapName, 256));
        m_mapName[m_mapNameLength] = L'\0';
    }

    if ((flags & kMapInfoTileRegionHasResourceName) != 0)
    {
        int resourceNameLength = packetView.ReadAnsiString(resourceNameBytes, sizeof(resourceNameBytes));
        m_mapResourceNameLength = static_cast<unsigned char>(
            MultiByteToWideChar(CP_ACP, 0, resourceNameBytes, resourceNameLength, m_mapResourceName, 256));
        m_mapResourceName[m_mapResourceNameLength] = L'\0';

        wcscpy_s(epfResourceName, _countof(epfResourceName), m_mapResourceName);
        wcscat_s(epfResourceName, _countof(epfResourceName), L".EPF");
        wcscpy_s(palResourceName, _countof(palResourceName), m_mapResourceName);
        wcscat_s(palResourceName, _countof(palResourceName), L".PAL");
    }

    if ((flags & kMapInfoTileRegionHasResourceMode) != 0)
        m_mapResourceMode = packetView.ReadByte();

    if (m_mapResourceMode != oldResourceMode)
        ResetMapResourceStateForModeChange();

    int originTileX = packetView.ReadUInt16();
    int originTileY = packetView.ReadUInt16();
    int tileWidth = packetView.ReadByte();
    int tileHeight = packetView.ReadByte();

    MapRect packetBounds;
    SetRectBounds(&packetBounds, originTileX, originTileY,
        originTileX + tileWidth, originTileY + tileHeight);

    MapRect mapBounds;
    SetRectBounds(&mapBounds, 0, 0, m_mapWidth, m_mapHeight);

    MapRect clippedBounds = packetBounds;
    IntersectRectBounds(&clippedBounds, &mapBounds);

    for (int tileY = clippedBounds.top; tileY < clippedBounds.bottom; ++tileY)
    {
        for (int tileX = clippedBounds.left; tileX < clippedBounds.right; ++tileX)
        {
            MapPaneTileRecord &tile = m_tileBuffer[tileX + tileY * m_mapWidth];
            unsigned short oldGroundTileId = tile.groundTileId;

            tile.groundTileId = packetView.ReadTileWord();
            unsigned short tileFlags = packetView.ReadTileWord();
            tile.flags = static_cast<unsigned short>((tile.flags & ~1) | (tileFlags & 1));
            tile.staticObjectId = packetView.ReadTileWord();

            if (tile.groundTileId != oldGroundTileId)
                DrawTileAt(tileX, tileY, true);
        }
    }

    MapRect refreshBounds;
    if (m_refreshWholeVisibleMap)
    {
        m_refreshWholeVisibleMap = false;
        GetExtendedVisibleTileBounds(&refreshBounds);
    }
    else if (m_waitingForLocalPlayerStatus)
    {
        SetRectBounds(&refreshBounds, 0, 0, 0, 0);
    }
    else
    {
        GetExtendedVisibleTileBounds(&refreshBounds);
        IntersectRectBounds(&refreshBounds, &clippedBounds);
    }

    RefreshStaticObjectTileRegion(refreshBounds);

    if (g_useEpfAssets)
    {
        if (g_pConfig->m_autoMoveEnabled &&
            m_waitingForLocalPlayerStatus &&
            m_queuedMapStateRefresh)
        {
            m_rightButtonTrackingActive = false;
            ClearQueuedMapStateRefresh();
        }

        if (!m_rightButtonTrackingActive &&
            m_waitingForLocalPlayerStatus &&
            m_queuedMapStateRefresh)
        {
            m_leftButtonTrackingActive = false;
            ClearQueuedMapStateRefresh();
        }
    }

    return true;
}



// UID:0003TO | by-memory/0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket.md | Completion:92 | Confidence:94
bool MapPane::HandleObjectMoveEffectPacket(const unsigned char *packet)
{
    const unsigned int objectId = PacketBufferReadUInt32BE(packet + 1);
    const short effectDescriptorId =
        static_cast<short>(PacketBufferReadUInt16BE(packet + 5));
    const short timerAction =
        static_cast<short>(PacketBufferReadUInt16BE(packet + 7));

    if (effectDescriptorId == 134)
    {
        FlashMapColor(143);
        return true;
    }

    const int mapColumn = PacketBufferReadUInt16BE(packet + 9);
    const int mapRow = PacketBufferReadUInt16BE(packet + 11);
    const bool renderAfterLivingObjects =
        effectDescriptorId >= 160 && effectDescriptorId <= 162;

    if (m_objectList != NULL)
    {
        if (objectId == 0)
        {
            RequestCoordinateEffect(
                mapColumn,
                mapRow,
                effectDescriptorId,
                timerAction,
                renderAfterLivingObjects);
        }
        else if (m_objectList->FindByObjectId(objectId) != NULL)
        {
            RequestObjectEffect(
                objectId,
                effectDescriptorId,
                timerAction,
                renderAfterLivingObjects);
        }
    }

    return true;
}

// UID:0003TP | by-memory/0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket.md | Completion:92 | Confidence:94
bool MapPane::HandleObjectWorldMapCreationPacket(const unsigned char *packet)
{
    MemoryMan *memoryMan = GetMemoryMan();
    TimerHandler *timerOwner = m_localPlayerObjectPane != NULL
        ? static_cast<TimerHandler *>(m_localPlayerObjectPane)
        : NULL;
    g_pTimerMgr->RemovePendingTimersForOwner(timerOwner);

    size_t cursor = 1;
    char ansiText[256];
    wchar_t wideText[256];
    wchar_t mapName[24];

    unsigned int textByteCount = packet[cursor++];
    memoryMan->MemmoveWrapper(ansiText, packet + cursor, textByteCount);
    cursor += textByteCount;
    ansiText[textByteCount] = '\0';

    const char mapNameLength = static_cast<char>(
        MultiByteToWideChar(
            CP_ACP,
            0,
            ansiText,
            textByteCount,
            mapName,
            _countof(mapName)));
    mapName[mapNameLength] = L'\0';

    const unsigned short nodeCount = packet[cursor++];
    const unsigned char currentNodeIndex = packet[cursor++];

    std::vector<bool> adjacency(
        static_cast<size_t>(nodeCount) * nodeCount,
        false);
    MapPoint *nodePositions = static_cast<MapPoint *>(
        memoryMan->AllocateBufferMemory(sizeof(MapPoint) * nodeCount));
    wchar_t *nodeNames[384];
    unsigned short destinationMapIds[256];
    MapPoint destinationPositions[256];

    for (unsigned short nodeIndex = 0; nodeIndex < nodeCount; ++nodeIndex)
    {
        nodePositions[nodeIndex].column =
            PacketBufferReadUInt16BE(packet + cursor);
        cursor += 2;
        nodePositions[nodeIndex].row =
            PacketBufferReadUInt16BE(packet + cursor);
        cursor += 2;

        textByteCount = packet[cursor++];
        memoryMan->MemmoveWrapper(ansiText, packet + cursor, textByteCount);
        cursor += textByteCount;
        ansiText[textByteCount] = '\0';

        const char wideLength = static_cast<char>(
            MultiByteToWideChar(
                CP_ACP,
                0,
                ansiText,
                textByteCount,
                wideText,
                _countof(wideText)));
        wideText[wideLength] = L'\0';

        nodeNames[nodeIndex] = static_cast<wchar_t *>(
            memoryMan->AllocateBufferMemory(
                (wideLength + 1) * sizeof(wchar_t)));
        memoryMan->MemmoveWrapper(
            nodeNames[nodeIndex],
            wideText,
            wideLength * sizeof(wchar_t));
        nodeNames[nodeIndex][wideLength] = L'\0';

        const unsigned short unusedNodeValue =
            PacketBufferReadUInt16BE(packet + cursor);
        cursor += 2;
        (void)unusedNodeValue;

        destinationMapIds[nodeIndex] =
            PacketBufferReadUInt16BE(packet + cursor);
        cursor += 2;
        destinationPositions[nodeIndex].column =
            PacketBufferReadUInt16BE(packet + cursor);
        cursor += 2;
        destinationPositions[nodeIndex].row =
            PacketBufferReadUInt16BE(packet + cursor);
        cursor += 2;

        const unsigned short linkCount =
            PacketBufferReadUInt16BE(packet, &cursor);
        for (unsigned short linkIndex = 0;
             linkIndex < linkCount;
             ++linkIndex)
        {
            const unsigned short linkedNodeIndex =
                PacketBufferReadUInt16BE(packet, &cursor);
            adjacency[static_cast<size_t>(nodeIndex) * nodeCount
                      + linkedNodeIndex] = true;
        }
    }

    if (g_useEpfAssets != 1)
    {
        if (wcscmp(mapName, L"wm") == 0 ||
            wcscmp(mapName, L"WM") == 0)
        {
            nodePositions[0].row = 211;
            nodePositions[0].column = 706;
            nodePositions[1].row = 295;
            nodePositions[1].column = 680;
            nodePositions[2].row = 344;
            nodePositions[2].column = 791;
            nodePositions[3].row = 128;
            nodePositions[3].column = 497;
            nodePositions[4].row = 105;
            nodePositions[4].column = 679;
            nodePositions[5].row = 56;
            nodePositions[5].column = 822;
            nodePositions[6].row = 317;
            nodePositions[6].column = 408;
            nodePositions[7].row = 317;
            nodePositions[7].column = 349;
            nodePositions[8].row = 342;
            nodePositions[8].column = 273;
            nodePositions[9].row = 454;
            nodePositions[9].column = 127;
            nodePositions[10].row = 491;
            nodePositions[10].column = 53;
            nodePositions[11].row = 389;
            nodePositions[11].column = 493;
            nodePositions[12].row = 511;
            nodePositions[12].column = 294;
            nodePositions[13].row = 234;
            nodePositions[13].column = 205;
            nodePositions[14].row = 562;
            nodePositions[14].column = 99;
            nodePositions[15].row = 388;
            nodePositions[15].column = 26;
            nodePositions[16].row = 199;
            nodePositions[16].column = 447;
            nodePositions[17].row = 752;
            nodePositions[17].column = 145;
            nodePositions[18].row = 660;
            nodePositions[18].column = 359;
            nodePositions[19].row = 659;
            nodePositions[19].column = 609;
            nodePositions[20].row = 888;
            nodePositions[20].column = 390;
            nodePositions[21].row = 1037;
            nodePositions[21].column = 550;
            nodePositions[22].row = 1038;
            nodePositions[22].column = 292;
            nodePositions[23].row = 1095;
            nodePositions[23].column = 90;
        }
        else if (wcscmp(mapName, L"wm2") == 0 ||
                 wcscmp(mapName, L"WM2") == 0)
        {
            nodePositions[0].row = 220;
            nodePositions[0].column = 89;
            nodePositions[1].row = 373;
            nodePositions[1].column = 110;
            nodePositions[2].row = 542;
            nodePositions[2].column = 562;
            nodePositions[3].row = 132;
            nodePositions[3].column = 524;
            nodePositions[4].row = 620;
            nodePositions[4].column = 455;
            nodePositions[5].row = 630;
            nodePositions[5].column = 330;
        }
        else if (wcscmp(mapName, L"wm3") == 0 ||
                 wcscmp(mapName, L"WM3") == 0)
        {
            nodePositions[0].row = 178;
            nodePositions[0].column = 56;
            nodePositions[1].row = 108;
            nodePositions[1].column = 169;
            nodePositions[2].row = 171;
            nodePositions[2].column = 254;
            nodePositions[3].row = 349;
            nodePositions[3].column = 167;
            nodePositions[4].row = 420;
            nodePositions[4].column = 234;
            nodePositions[5].row = 429;
            nodePositions[5].column = 369;
            nodePositions[6].row = 398;
            nodePositions[6].column = 499;
            nodePositions[7].row = 283;
            nodePositions[7].column = 430;
            nodePositions[8].row = 213;
            nodePositions[8].column = 472;
            nodePositions[9].row = 127;
            nodePositions[9].column = 447;
            nodePositions[10].row = 81;
            nodePositions[10].column = 555;
        }
        else if (wcscmp(mapName, L"wm4") == 0 ||
                 wcscmp(mapName, L"WM4") == 0)
        {
            nodePositions[0].row = 422;
            nodePositions[0].column = 212;
            nodePositions[1].row = 379;
            nodePositions[1].column = 107;
            nodePositions[2].row = 263;
            nodePositions[2].column = 111;
            nodePositions[3].row = 107;
            nodePositions[3].column = 176;
            nodePositions[4].row = 147;
            nodePositions[4].column = 279;
            nodePositions[5].row = 281;
            nodePositions[5].column = 299;
            nodePositions[6].row = 354;
            nodePositions[6].column = 390;
            nodePositions[7].row = 202;
            nodePositions[7].column = 455;
            nodePositions[8].row = 146;
            nodePositions[8].column = 513;
            nodePositions[9].row = 260;
            nodePositions[9].column = 567;
            nodePositions[10].row = 398;
            nodePositions[10].column = 561;
        }
    }

    WorldMapPane *worldMapPane = new WorldMapPane(
        mapName,
        nodeCount,
        currentNodeIndex,
        nodePositions,
        nodeNames,
        destinationMapIds,
        destinationPositions,
        adjacency);

    m_activeScreenLayer = new Layer;
    g_pScreenPane->SetLayerFrame(
        m_activeScreenLayer,
        g_mainUiLayerSlots.overlayPaneLayerContext);

    RectBounds screenBounds;
    InitRectBounds(
        &screenBounds,
        0,
        0,
        g_screenWidth,
        g_screenHeight);
    worldMapPane->AddToLayer(
        &screenBounds,
        0,
        0,
        m_activeScreenLayer);
    worldMapPane->SetPaneOrder(0, 0);
    m_auxiliaryPane = worldMapPane;

    memoryMan->FreeBufferMemory(nodePositions);
    for (unsigned short nodeIndex = 0; nodeIndex < nodeCount; ++nodeIndex)
        memoryMan->FreeBufferMemory(nodeNames[nodeIndex]);

    return true;
}

// UID:0003TQ | by-memory/0x00512960-0x00512ca4.MapPaneHandleActionPacket.md | Completion:92 | Confidence:94
bool MapPane::HandleActionPacket(const unsigned char *packet)
{
    if (g_useEpfAssets == 1)
    {
        const unsigned int objectId = PacketBufferReadUInt32BE(packet + 1);
        const char actionFlags = static_cast<char>(packet[5]);
        const unsigned char currentValue = packet[6];
        const int damageAmount =
            static_cast<int>(PacketBufferReadUInt32BE(packet + 7));
        const bool negativeAction = actionFlags < 0;

        unsigned short nestedEffectTrigger = 0;
        unsigned short nestedEffectDescriptorId = 0;
        if ((actionFlags & 0x20) != 0)
        {
            nestedEffectTrigger = 224;
            nestedEffectDescriptorId = 224;
            if ((actionFlags & 0x40) != 0)
            {
                nestedEffectTrigger = 245;
                nestedEffectDescriptorId = 245;
            }
        }

        if (m_objectList != NULL)
        {
            LivingObjectPane *objectPane =
                static_cast<LivingObjectPane *>(
                    m_objectList->FindByObjectId(objectId));
            if (objectPane != NULL)
            {
                objectPane->ShowDamageEffect(
                    143 - (actionFlags & 0x1f), 0);

                delete objectPane->m_damageNumberObjectPane;
                if (currentValue <= 100)
                {
                    MapPoint mapPosition;
                    objectPane->GetMapPosition(&mapPosition);

                    DamageNumberObjectPane *damageNumberObjectPane;
                    if (objectPane->m_objectStatus.m_statusKind ==
                        ObjectStatusBlob::HumanObject)
                    {
                        damageNumberObjectPane = new DamageNumberObjectPane(
                            objectPane,
                            mapPosition.row,
                            mapPosition.column,
                            damageAmount,
                            1);
                    }
                    else
                    {
                        damageNumberObjectPane = new DamageNumberObjectPane(
                            objectPane,
                            mapPosition.row,
                            mapPosition.column,
                            damageAmount,
                            0);
                    }

                    objectPane->SetDamageNumberObjectPane(
                        damageNumberObjectPane);
                    m_objectList->AddObjectPane(damageNumberObjectPane);
                    g_pTimerMgr->ScheduleTimer(
                        static_cast<TimerHandler *>(damageNumberObjectPane),
                        0,
                        500,
                        0,
                        0);
                    damageNumberObjectPane->UpdatePosition();

                    RectBounds bounds;
                    damageNumberObjectPane->GetBounds(&bounds);
                    damageNumberObjectPane->InvalidateRect(&bounds);
                }

                if (objectId == g_pUserPane->m_objectId ||
                    !g_pUserPane->IsGroupMember(objectId) ||
                    (g_pUserPane->IsGroupMember(objectId) == true &&
                     !g_pConfig->m_groupBarEnabled))
                {
                    delete objectPane->m_hitBarObjectPane;
                    if (currentValue <= 100)
                    {
                        CreateHitBarObjectPane(
                            objectPane, currentValue, 100);
                    }
                }

                if (objectPane == g_pUserPane &&
                    negativeAction &&
                    g_pUserPane->m_nameVisible)
                {
                    g_pUserPane->AdvanceMovementSendTick();
                }

                if (nestedEffectTrigger != 0)
                {
                    unsigned char effectPacket[13];
                    PacketBufferWriteUInt32BE(objectId, effectPacket + 1);
                    PacketBufferWriteUInt16BE(
                        nestedEffectDescriptorId, effectPacket + 5);
                    PacketBufferWriteUInt16BE(0, effectPacket + 7);
                    PacketBufferWriteUInt16BE(0, effectPacket + 9);
                    PacketBufferWriteUInt16BE(0, effectPacket + 11);
                    HandleObjectMoveEffectPacket(effectPacket);
                }
            }
        }

        return true;
    }

    const unsigned int objectId = PacketBufferReadUInt32BE(packet + 1);
    const char actionFlags = static_cast<char>(packet[5]);
    const unsigned char currentValue = packet[6];
    PacketBufferReadUInt32BE(packet + 7);

    if (m_objectList != NULL)
    {
        LivingObjectPane *objectPane =
            static_cast<LivingObjectPane *>(
                m_objectList->FindByObjectId(objectId));
        if (objectPane != NULL)
        {
            objectPane->ShowDamageEffect(143 - actionFlags, 0);
            delete objectPane->m_hitBarObjectPane;
            if (currentValue <= 100)
                CreateHitBarObjectPane(objectPane, currentValue, 100);
        }
    }

    return true;
}


// UID:0003TS | by-memory/0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket.md | Completion:92 | Confidence:94
#include "Config.h"
#include "MidiPlayer.h"
#include "ObjectList.h"
#include "ObjectPane.h"
#include "PacketBuffer.h"
#include "SoundManager.h"
#include "SoundObjectPane.h"

namespace
{
enum AnimationSoundPacketKind
{
    kAnimationSoundObject = 0,
    kAnimationZoneMusic = 1,
    kAnimationMidiTrack = 2
};
}

bool MapPane::HandleAnimationSoundPacket(const unsigned char *packet)
{
    SoundObjectPane::SoundDescriptor sound;
    SoundObjectPane::SoundOrigin origin;
    int playbackMode;
    int repeatDelayMilliseconds;
    float playProbability;
    int lifetimePolicy;
    int lifetimeValue;

    sound.kind = packet[1];
    const unsigned char soundDataLength = packet[2];

    switch (sound.kind)
    {
    case kAnimationSoundObject:
        if (g_pConfig->m_midiEnabled == 0)
            return true;

        sound.sampleId = PacketBufferReadUInt16BE(packet + 3);
        sound.volumeScale = packet[5];
        break;

    case kAnimationZoneMusic:
        m_zoneMusicId = PacketBufferReadUInt16BE(packet + 3);
        m_zoneMusicFallbackTrackIndex =
            PacketBufferReadUInt16BE(packet + 5);
        m_zoneMusicVolumeScale = packet[7];

        if (g_pConfig->musicSourceMode == 0)
        {
            g_pSoundManager->PlayMusicByZone(
                m_zoneMusicId,
                m_zoneMusicFallbackTrackIndex,
                m_zoneMusicVolumeScale,
                0);
        }
        return true;

    case kAnimationMidiTrack:
    {
        const unsigned short trackId =
            PacketBufferReadUInt16BE(packet + 3);
        if (trackId != 0)
            g_pMidiPlayer->SelectTrack(trackId);
        else
            g_pMidiPlayer->StopPlayback();
        return true;
    }
    }

    int offset = 3 + soundDataLength;

    origin.type = packet[offset++];
    const unsigned char originDataLength = packet[offset++];

    switch (origin.type)
    {
    case SoundObjectPane::SoundOrigin::kObject:
        origin.object = m_objectList->FindByObjectId(
            PacketBufferReadUInt32BE(packet + offset));
        break;

    case SoundObjectPane::SoundOrigin::kMapPosition:
        origin.mapX = PacketBufferReadUInt16BE(packet + offset);
        origin.mapY = PacketBufferReadUInt16BE(packet + offset + 2);
        break;
    }

    offset += originDataLength;

    playbackMode = packet[offset++];
    const unsigned char playbackDataLength = packet[offset++];

    switch (playbackMode)
    {
    case SoundObjectPane::kRepeatPlayback:
        repeatDelayMilliseconds =
            PacketBufferReadUInt16BE(packet + offset);
        break;

    case SoundObjectPane::kRandomRepeatPlayback:
        repeatDelayMilliseconds =
            PacketBufferReadUInt16BE(packet + offset);
        playProbability =
            static_cast<float>(
                PacketBufferReadUInt16BE(packet + offset + 2)) /
            100.0f;
        break;
    }

    offset += playbackDataLength;

    lifetimePolicy = packet[offset++];
    const unsigned char lifetimeDataLength = packet[offset++];
    (void)lifetimeDataLength;

    if (lifetimePolicy == SoundObjectPane::kPlayCount ||
        lifetimePolicy == SoundObjectPane::kTimeout)
    {
        lifetimeValue = PacketBufferReadUInt16BE(packet + offset);
    }

    SoundObjectPane *soundObjectPane;

    switch (origin.type)
    {
    case SoundObjectPane::SoundOrigin::kObject:
    {
        if (origin.object == NULL)
            return true;

        MapPoint rowPosition;
        MapPoint columnPosition;
        const int mapY =
            origin.object->GetMapPosition(&rowPosition)->row;
        const int mapX =
            origin.object->GetMapPosition(&columnPosition)->column;

        soundObjectPane = new SoundObjectPane(
            mapX,
            mapY,
            sound,
            origin,
            playbackMode,
            repeatDelayMilliseconds,
            playProbability,
            lifetimePolicy,
            lifetimeValue);
        origin.object->SetSoundObjectPane(soundObjectPane);
        break;
    }

    case SoundObjectPane::SoundOrigin::kMapPosition:
        soundObjectPane = new SoundObjectPane(
            origin.mapX,
            origin.mapY,
            sound,
            origin,
            playbackMode,
            repeatDelayMilliseconds,
            playProbability,
            lifetimePolicy,
            lifetimeValue);
        break;

    default:
        soundObjectPane = new SoundObjectPane(
            0,
            0,
            sound,
            origin,
            playbackMode,
            repeatDelayMilliseconds,
            playProbability,
            lifetimePolicy,
            lifetimeValue);
        break;
    }

    if (soundObjectPane != NULL)
    {
        m_objectList->AddObjectPane(soundObjectPane);
        soundObjectPane->StartPlayback();
    }

    return true;
}

// UID:0003TT | by-memory/0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md | Completion:92 | Confidence:94
bool MapPane::HandleObjectStatusPacket(const unsigned char *packet)
{
    const int objectId =
        static_cast<int>(PacketBufferReadUInt32BE(packet + 1));

    ObjectStatusBlob status;
    status.m_displayStatusByte = 80;

    int statusBytes;
    if (packet[5] == 0)
    {
        statusBytes = status.ParseFullStatus(packet + 6);
    }
    else if (packet[5] == 1)
    {
        statusBytes = status.ParsePartialStatus(packet + 6);
    }
    else
    {
        return true;
    }

    const unsigned char objectInfoType = packet[statusBytes + 6];
    const unsigned char nameLength = packet[statusBytes + 7];

    wchar_t objectName[33];
    const int objectNameLength =
        MultiByteToWideChar(
            CP_ACP,
            0,
            reinterpret_cast<const char *>(packet + statusBytes + 8),
            nameLength,
            objectName,
            32);
    objectName[objectNameLength] = L'\0';

    if (m_objectList == NULL)
        return true;

    ObjectPane *objectPane = m_objectList->FindByObjectId(objectId);
    if (objectPane == NULL)
    {
        SendObjectRefreshRequest(objectId);
        return true;
    }

    const unsigned char objectType = objectPane->GetObjectType();
    if (objectType == kObjectPaneTypeLiving)
    {
        LivingObjectPane *livingObjectPane =
            static_cast<LivingObjectPane *>(objectPane);
        UserPane *localPlayer =
            static_cast<UserPane *>(m_localPlayerObjectPane);

        if (status.m_statusKind == ObjectStatusBlob::HumanObject &&
            status.m_compositionMode == 2 &&
            (localPlayer->m_playerSettingsState[0] ||
             livingObjectPane == m_localPlayerObjectPane))
        {
            status.m_compositionMode = 5;
        }

        wcscpy_s(livingObjectPane->m_nameBuffer, 33, objectName);
        livingObjectPane->m_objectInfoType = objectInfoType;

        ObjectInfoObjectPane *objectInfoPane =
            livingObjectPane->m_objectInfoObjectPane;
        objectInfoPane->SetPrimaryName(objectName);
        if (objectInfoPane != NULL)
            objectInfoPane->SetSpriteAttribute(0);

        ObjectStatusBlob effectStatus;
        effectStatus.m_displayStatusByte = 80;
        livingObjectPane->GetSpriteConfig(&effectStatus);
        if (effectStatus.m_statusKind == ObjectStatusBlob::HumanObject &&
            (effectStatus.m_shieldOrArrowId == 13 ||
             effectStatus.m_shieldOrArrowId == 14 ||
             effectStatus.m_shieldOrArrowId == 15 ||
             effectStatus.m_shieldOrArrowId == 16 ||
             effectStatus.m_shieldOrArrowId == 27 ||
             effectStatus.m_weaponId == 146 ||
             effectStatus.m_weaponId == 161))
        {
            livingObjectPane->RemoveSpecialEffect();
        }

        ObjectStatusBlob previousStatus;
        previousStatus.m_displayStatusByte = 80;
        livingObjectPane->GetSpriteConfig(&previousStatus);

        if (status.m_statusKind == ObjectStatusBlob::HumanObject)
        {
            if (previousStatus.m_bodyId != status.m_bodyId)
            {
                g_pSoundManager->PlaySample(
                    status.m_bodyId <= 1 ? 411 : 410,
                    100);
            }

            if (previousStatus.m_weaponId != status.m_weaponId)
            {
                g_pSoundManager->PlaySample(
                    previousStatus.m_weaponId == 0xffff ? 411 : 410,
                    100);

                if (g_pUserPane->m_nameVisible)
                {
                    unsigned char statusRefreshPacket[3] =
                        { 0x13, 0x04, 0 };
                    g_packetSender->QueueAndSendPacket(
                        statusRefreshPacket,
                        2);
                }
            }

            if (previousStatus.m_shieldOrArrowId !=
                status.m_shieldOrArrowId)
            {
                g_pSoundManager->PlaySample(
                    previousStatus.m_shieldOrArrowId >= 0xff ? 411 : 410,
                    100);
            }
        }

        if (previousStatus.m_statusKind != status.m_statusKind)
        {
            livingObjectPane->CancelPendingTimersExceptEvent(
                LivingObjectPane::kLivingTimerRefresh);
        }

        if (livingObjectPane == m_localPlayerObjectPane &&
            status.m_statusKind == ObjectStatusBlob::HumanObject)
        {
            localPlayer->m_currentAppearance = status;
        }

        livingObjectPane->SetSpriteConfig(
            &status,
            livingObjectPane->m_facing);
        RefreshObjectStatusOverlay(livingObjectPane);
    }
    else if (objectType == kObjectPaneTypeItem &&
             status.m_appearanceId >= 0xc000)
    {
        static_cast<ItemObjectPane *>(objectPane)->UpdateItemStatus(&status);
    }

    return true;
}



// UID:0002SQ | by-memory/0x0061e71c-0x0061e7a0.MapPaneVtableData.md | Completion:88 | Confidence:92
// MapPane vtable bytes are compiler-generated from [UID:00007Q][MapPane](by-class/MapPane.md) and its exact virtual method children; do not emit a hand-authored table here.

// UID:00042K | by-type/by-struct/MapPaneLayout.md | Completion:93 | Confidence:94
// Layout support only. The MapPane class declaration is owned by [UID:00007Q][MapPane](by-class/MapPane.md); no standalone MapPaneLayout C++ is emitted here.

// UID:0004HP | by-type/by-struct/MapPaneTileRecord.md | Completion:90 | Confidence:90
struct MapPaneTileRecord
{
    unsigned short groundTileId;
    unsigned short flags;
    unsigned short staticObjectId;
};

// UID:00027P | by-memory/0x0066dd60-0x0066dd78.ImageExtensionPointerTable.md | Completion:90 | Confidence:93
namespace {

const wchar_t* const kProfileSidecarExtensions[] = {
    L"bmp",
    L"pcx",
    L"jpg",
    L"jpeg",
    L"pnm",
};

} // namespace

// UID:0004VY | by-memory/0x00514920-0x0051499b.MapRefreshDimmerConstructor.md | Completion:92 | Confidence:94
MapRefreshDimmer::MapRefreshDimmer()
    : ScreenDimmer(3, g_pScreenPane)
{
    ScheduleTimer(0, 2000, 0, 0);
}

// UID:0004VZ | by-memory/0x005149a0-0x005149e2.MapRefreshDimmerHandlePacketEvent.md | Completion:93 | Confidence:94
bool MapRefreshDimmer::HandlePacketEvent(Event *event)
{
    if (event->packet[0] != 0x22)
        return false;

    delete this;
    g_activeMapPane->FinishVisibleObjectRefresh();
    return true;
}

// UID:0004W0 | by-memory/0x005149f0-0x00514a0d.MapRefreshDimmerOnTimer.md | Completion:93 | Confidence:94
bool MapRefreshDimmer::OnTimer(int timerId, int, int)
{
    if (timerId == 0)
        delete this;

    return true;
}

// UID:0004R0 | by-type/by-struct/MapPoint.md | Completion:92 | Confidence:93
struct MapPoint
{
    int row;
    int column;
};

typedef char MapPointSizeMustBe8[
    sizeof(MapPoint) == 8 ? 1 : -1];

// UID:0002ZJ | by-global/MapPaneCmapSignaturePointer.md | Completion:90 | Confidence:94
static const char *g_mapPaneCmapSignature = "CMAP";

// UID:0000T7 | by-global/MapTilePixelDimensions.md | Completion:91 | Confidence:92
short g_mapTilePixelWidth = 48;
short g_mapTilePixelHeight = 48;

// UID:0000PR | by-global/g_activeMapPane.md | Completion:91 | Confidence:92
MapPane *g_activeMapPane = NULL;

// UID:0002CF | by-global/g_movementSubstepScale.md | Completion:91 | Confidence:93
static char g_movementSubstepScale = 1;

// UID:0000Q3 | by-global/g_objectNationMap.md | Completion:89 | Confidence:90
static std::uint8_t* g_objectNationMap = NULL;

// UID:0000Q4 | by-global/g_objectRecordCount.md | Completion:89 | Confidence:89
static std::uint32_t g_objectRecordCount = 0;

// UID:0000VC | by-item/ScaleDirectionOffsetToPixels_00505100.md | Completion:86 | Confidence:90
// Emitted code for this helper is covered by [UID:0001AQ][0x00505100-0x00505123.ScaleDirectionOffsetToPixels](by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md).

// UID:00041W | by-memory/0x00505080-0x00505100.MapPaneDirectionToTileOffset.md | Completion:92 | Confidence:93
MapPoint *DirectionToTileOffset(
    MapPoint *outOffset, unsigned char direction)
{
    switch (direction)
    {
    case 0:
        SetPoint(outOffset, -1, 0);
        break;
    case 1:
        SetPoint(outOffset, 0, 1);
        break;
    case 2:
        SetPoint(outOffset, 1, 0);
        break;
    case 3:
        SetPoint(outOffset, 0, -1);
        break;
    default:
        SetPoint(outOffset, 0, 0);
        break;
    }

    return outOffset;
}

// UID:0001AQ | by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md | Completion:88 | Confidence:91
static int __stdcall ScaleDirectionOffsetToPixels(int *tileOffset)
{
    tileOffset[1] *= g_mapTilePixelWidth;
    tileOffset[0] *= g_mapTilePixelHeight;
    return tileOffset[0];
}

// UID:000231 | by-memory/0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper.md | Completion:88 | Confidence:90
static void SendObjectRefreshRequest(int objectId)
{
    unsigned char packet[16];
    int packetLength = 0;

    PacketBufferAppendUInt8(0x0c, packet, &packetLength);
    PacketBufferAppendUInt32BE(
        static_cast<unsigned int>(objectId),
        packet,
        &packetLength);
    g_packetSender->QueueAndSendPacket(packet, packetLength);
}

// UID:0004RF | by-memory/0x0050aaf0-0x0050ab3b.HasLightSourceEquipmentRaw.md | Completion:89 | Confidence:91
static bool HasLightSourceEquipment(ObjectStatusBlob objectStatus)
{
    switch (objectStatus.m_shieldOrArrowId)
    {
    case 13:
    case 14:
    case 15:
    case 16:
    case 27:
        return true;
    }

    return objectStatus.m_weaponId == 0x92 ||
           objectStatus.m_weaponId == 0xa1;
}

// UID:0003TU | by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md | Completion:90 | Confidence:92
void __stdcall RequestObjectInfo(unsigned int objectId)
{
    unsigned char packet[7];
    PacketBufferWriteUInt8(0x43, packet);
    PacketBufferWriteUInt8(1, packet + 1);
    PacketBufferWriteUInt32BE(objectId, packet + 2);
    packet[6] = 0;
    g_packetSender->QueueAndSendPacket(packet, 6);
}

// UID:0003TV | by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md | Completion:90 | Confidence:92
static void __stdcall RequestLookAtMapPosition(
    unsigned short column,
    unsigned short row)
{
    unsigned char packet[6];
    PacketBufferWriteUInt8(0x0a, packet);
    PacketBufferWriteUInt16BE(column, packet + 1);
    PacketBufferWriteUInt16BE(row, packet + 3);
    packet[5] = 0;
    g_packetSender->QueueAndSendPacket(packet, 5);
}

// UID:0003TW | by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md | Completion:91 | Confidence:93
static void RefreshObjectStatusOverlay(LivingObjectPane *objectPane)
{
    ObjectStatusBlob status;
    status.m_displayStatusByte = 80;
    objectPane->GetSpriteConfig(&status);

    if (status.m_statusKind == ObjectStatusBlob::HumanObject &&
        (status.m_shieldOrArrowId == 13 ||
         status.m_shieldOrArrowId == 14 ||
         status.m_shieldOrArrowId == 15 ||
         status.m_shieldOrArrowId == 16 ||
         status.m_shieldOrArrowId == 27 ||
         status.m_weaponId == 146 ||
         status.m_weaponId == 161))
    {
        objectPane->RequestNameplateEffect();
    }
}

// UID:0001AX | by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md | Completion:88 | Confidence:92
// No standalone body: this retained raw duplicate is covered by the live MapPane::HandlePacket opcode 0x20 route in [UID:00037T][0x00507c90-0x00508f60.MapPanePacketDispatcher](by-memory/0x00507c90-0x00508f60.MapPanePacketDispatcher.md).

// UID:0004SN | by-memory/0x00512840-0x0051289f.MapPaneHandlePursuitMessageDialogPacket.md | Completion:90 | Confidence:93
static bool __stdcall HandlePursuitMessageDialogPacket(
    const unsigned char *packet)
{
    PursuitMessageDialogCreator creator;
    creator.CreateDialog(packet);
    return true;
}

// UID:000536 | by-memory/0x005128a0-0x005128fd.HandleEditablePaperPacket.md | Completion:92 | Confidence:93
#include "../ui/dialogs/EditablePaperPane.h"

static bool __stdcall HandleEditablePaperPacket(const unsigned char *packet)
{
    new EditablePaperPane(packet, kPaperOpenEditable);
    return true;
}

// UID:000537 | by-memory/0x00512900-0x0051295d.HandleReadOnlyPaperPacket.md | Completion:92 | Confidence:93
static bool __stdcall HandleReadOnlyPaperPacket(const unsigned char *packet)
{
    new EditablePaperPane(packet, kPaperOpenReadOnly);
    return true;
}

// UID:0001AZ | by-memory/0x00514380-0x005143ba.FriendNameListSyncRawHandler.md | Completion:86 | Confidence:90
// No standalone body: this retained raw duplicate is covered by the live MapPane::HandlePacket opcode 0x6a route in [UID:00037T][0x00507c90-0x00508f60.MapPanePacketDispatcher](by-memory/0x00507c90-0x00508f60.MapPanePacketDispatcher.md).

// UID:0003FV | by-memory/0x006168e8-0x00617420.RegistryConfigChannelStartupStringData.md | Completion:92 | Confidence:94
// Compiler/linker-pooled literals and __uuidof constants are emitted at the exact consumer use sites.
// This physical read-only range has no standalone source declaration or canonical declaration owner.

// UID:0003P9 | by-memory/0x0061a44c-0x0061a458.SharedEpfSuffixString.md | Completion:87 | Confidence:92
// The shared .EPF suffix literal is emitted inline at each proven source use.











// UID:00027F | by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md | Completion:90 | Confidence:93
// Emitted declaration for this storage byte is covered by [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md).

// UID:0003ZM | by-memory/0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants.md | Completion:88 | Confidence:90
namespace
{
    static short g_legacyMapTilePrimaryMaxId = 0x74e2;
    static short g_currentMapTilePrimaryRemapFirstId = 0x7992;
    static short g_currentMapTilePrimaryRemapLastId = 0x79c1;

    static short g_legacyMapTileOverlayMaxId = 0x368e;
    static short g_currentMapTileOverlayRemapFirstId = 0x380a;
    static short g_currentMapTileOverlayRemapLastId = 0x3822;
}

// UID:0002ZN | by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md | Completion:88 | Confidence:93
// Emitted declaration for this signature pointer is covered by [UID:0002ZJ][MapPaneCmapSignaturePointer](by-global/MapPaneCmapSignaturePointer.md).

// UID:00027N | by-memory/0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable.md | Completion:88 | Confidence:92
static const unsigned short s_mapPaneChecksumTable[256] = {
    0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,
    0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef,
    0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,
    0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de,
    0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,
    0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d,
    0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4,
    0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc,
    0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,
    0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b,
    0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12,
    0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
    0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,
    0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49,
    0x7e97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,
    0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78,
    0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f,
    0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,
    0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e,
    0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256,
    0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
    0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
    0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c,
    0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634,
    0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,
    0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3,
    0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,
    0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92,
    0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9,
    0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
    0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,
    0x6e17, 0x7e36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0
};

// UID:00027O | by-memory/0x0066dd50-0x0066dd60.MapObjectDirectionMasks.md | Completion:87 | Confidence:91
static const unsigned char s_objectDirectionMasks[8] = {
    0x02, 0x08, 0x01, 0x04, 0x04, 0x00, 0x00, 0x00
};

static const unsigned char s_objectReverseDirectionMasks[8] = {
    0x01, 0x04, 0x02, 0x08, 0x08, 0x00, 0x00, 0x00
};

// UID:00027Q | by-memory/0x0066dd78-0x0066ddd8.MapPaneDayNightFloatTable.md | Completion:87 | Confidence:91
static const float s_dayNightBrightnessByHour[24] = {
    0.35f, 0.35f, 0.35f, 0.40f,
    0.45f, 0.55f, 0.65f, 0.85f,
    0.90f, 0.95f, 1.00f, 1.00f,
    1.00f, 1.00f, 1.00f, 0.95f,
    0.90f, 0.85f, 0.65f, 0.55f,
    0.45f, 0.40f, 0.35f, 0.35f
};

// UID:0002AZ | by-memory/0x0069b4f8-0x0069b4f9.MapPaneRenderScratchFlag.md | Completion:87 | Confidence:90
static unsigned char s_mapPaneCachedShadowOption = 0;

// UID:00007Q | by-class\MapPane.md | Completion:93 | Confidence:94 | Empty Emitter Marker

// UID:0004DS | by-memory\0x00506980-0x00506ad4.MapPaneUpdateObjectPaneScreenBounds.md | Completion:88 | Confidence:90 | Empty Emitter Marker

// UID:00037T | by-memory\0x00507c90-0x00508f60.MapPanePacketDispatcher.md | Completion:88 | Confidence:90 | Empty Emitter Marker

// UID:0003TM | by-memory\0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003TN | by-memory\0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket.md | Completion:87 | Confidence:91 | Empty Emitter Marker

// UID:0003TR | by-memory\0x00512d60-0x00512f1c.MapPaneHandleFlyingObjectUpdatePacket.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0003M3 | by-memory\0x00514d1e-0x00514d34.MapPaneDestructorAdjustorThunks.md | Completion:86 | Confidence:91 | Empty Emitter Marker

// UID:0003M4 | by-memory\0x00514de0-0x00514e1b.MapPaneScalarDeletingDestructor.md | Completion:87 | Confidence:92 | Empty Emitter Marker

// UID:0003IN | by-memory\0x0061e6f0-0x0061e6f8.MapPaneCmapSignatureString.md | Completion:86 | Confidence:92 | Empty Emitter Marker

// UID:0003IO | by-memory\0x0061e6f8-0x0061e700.SharedGmWideString.md | Completion:88 | Confidence:93 | Empty Emitter Marker

// UID:0003IU | by-memory\0x0061e924-0x0061e964.MapPaneCachePathStringsAndSelectionMarker.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0003IW | by-memory\0x0061e9fc-0x0061ea24.MapPaneUserFaceAssetPathStrings.md | Completion:86 | Confidence:91 | Empty Emitter Marker

// UID:0003JG | by-memory\0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md | Completion:87 | Confidence:93 | Empty Emitter Marker

// UID:0003JH | by-memory\0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings.md | Completion:88 | Confidence:93 | Empty Emitter Marker

// UID:0003JI | by-memory\0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md | Completion:87 | Confidence:93 | Empty Emitter Marker

// UID:0003JJ | by-memory\0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings.md | Completion:88 | Confidence:93 | Empty Emitter Marker

// UID:0003JK | by-memory\0x0061ea70-0x0061ea8c.MapPaneMscfgDllPathFormatString.md | Completion:88 | Confidence:93 | Empty Emitter Marker

// UID:0003J0 | by-memory\0x0061eac0-0x0061ead4.MapPaneNumericConstants.md | Completion:86 | Confidence:90 | Empty Emitter Marker

// UID:0001SO | by-type\by-enum\MapServerPacketOpcode.md | Completion:88 | Confidence:90 | Empty Emitter Marker
