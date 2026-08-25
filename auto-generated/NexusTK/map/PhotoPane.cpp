// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MK
// Source by-file doc: by-file/PhotoPane.md
// UID:0000AH | by-class/PictureViewPane.md | Completion:92 | Confidence:94
class Event;

class PictureViewPane : public Pane
{
public:
    PictureViewPane();
    virtual ~PictureViewPane();

    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
};

// UID:0004RL | by-memory/0x00549a30-0x00549ad6.PictureViewPaneConstructor.md | Completion:92 | Confidence:94
PictureViewPane::PictureViewPane()
    : Pane(0)
{
    RectBounds bounds;
    g_activeMapPane->GetBounds(&bounds);
    SetPaneOrder(0, g_activeMapPane);
    AddToLayer(&bounds, 0, g_activeMapPane, g_mainUiLayerSlotsHead);
}

// UID:0004RM | by-memory/0x00549ae0-0x00549aff.PictureViewPaneDestructor.md | Completion:93 | Confidence:95
PictureViewPane::~PictureViewPane()
{
}

// UID:0004RN | by-memory/0x00549b00-0x00549b22.PictureViewPaneHandlePointerOrMouseEvent.md | Completion:92 | Confidence:94
bool PictureViewPane::HandlePointerOrMouseEvent(Event *event)
{
    if (event->m_type == kEventLeftButtonUp ||
        event->m_type == kEventRightButtonUp)
        MarkForDeletion();

    return true;
}

// UID:0004RO | by-memory/0x00549b30-0x00549b4d.PictureViewPaneHandleKeyOrTextEvent.md | Completion:92 | Confidence:94
bool PictureViewPane::HandleKeyOrTextEvent(Event *event)
{
    if (event->m_type == kEventKeyDown)
        MarkForDeletion();

    return true;
}

// UID:0000AG | by-class/PhotoPane.md | Completion:94 | Confidence:95
class PhotoPane : public PictureViewPane
{
public:
    PhotoPane(unsigned short mapId,
              unsigned char avatarShape,
              int avatarTileX,
              int avatarTileY,
              unsigned char avatarDirection);

    virtual void OnPaint();

private:
    GrafPort m_snapshotPort;
};

// UID:0004RJ | by-memory/0x00549620-0x00549911.PhotoPaneConstructor.md | Completion:92 | Confidence:93
namespace
{
struct PhotoMapCell
{
    unsigned short terrainTileId;
    unsigned short reserved;
    unsigned short staticObjectId;
};

struct PhotoMapFileData
{
    unsigned char header[8];
    PhotoMapCell cells[15][17];
};
}

PhotoPane::PhotoPane(unsigned short mapId,
                     unsigned char avatarShape,
                     int avatarTileX,
                     int avatarTileY,
                     unsigned char avatarDirection)
    : PictureViewPane(),
      m_snapshotPort()
{
    SimpleUString mapFileName;
    mapFileName.Format(L"C%04d.MAP", mapId);

    DATFile mapFile;
    mapFile.Open(mapFileName);

    ObjectStatusBlob appearance;
    appearance.m_statusKind = ObjectStatusBlob::HumanObject;
    appearance.m_appearanceId = avatarShape;
    appearance.m_bodyId = 0;
    appearance.m_weaponId = 0xffff;
    appearance.m_shieldOrArrowId = 0x00ff;
    appearance.m_fullBodyId = 0xffff;
    appearance.m_compositionMode = 0;
    appearance.m_displayStatusByte = 0x50;
    appearance.m_faceColor = 0;
    appearance.m_bodyColor = 0;

    const PhotoMapFileData *mapData =
        (const PhotoMapFileData *)mapFile.GetDataPointer();

    RectBounds snapshotBounds;
    InitRectBounds(&snapshotBounds,
                   0,
                   0,
                   18 * g_mapTilePixelWidth,
                   16 * g_mapTilePixelHeight);
    SetBounds(&snapshotBounds, 0);
    OffsetRectBounds(&snapshotBounds,
                     -snapshotBounds.left,
                     -snapshotBounds.top);
    m_snapshotPort.SetBounds(&snapshotBounds);
    m_snapshotPort.UpdateSurfaceInfo();

    int row;
    int column;
    for (row = 0; row < 15; ++row)
    {
        for (column = 0; column < 17; ++column)
        {
            RectBounds tileBounds;
            InitRectBounds(&tileBounds,
                           column * g_mapTilePixelWidth,
                           row * g_mapTilePixelHeight,
                           (column + 1) * g_mapTilePixelWidth,
                           (row + 1) * g_mapTilePixelHeight);

            g_pMapTileImageLib->DrawTile(
                &m_snapshotPort,
                &tileBounds,
                mapData->cells[row][column].terrainTileId);
        }
    }

    for (row = 0; row < 15; ++row)
    {
        for (column = 0; column < 17; ++column)
        {
            const unsigned short staticObjectId =
                mapData->cells[row][column].staticObjectId;
            if (staticObjectId != 0)
            {
                RectBounds objectBounds;
                g_pStaticObjImageLib->GetStaticObjectBounds(
                    staticObjectId,
                    &objectBounds);
                OffsetRectBounds(&objectBounds,
                                 column * g_mapTilePixelWidth,
                                 row * g_mapTilePixelHeight);
                g_pStaticObjImageLib->RenderStaticObject(
                    &m_snapshotPort,
                    &objectBounds,
                    staticObjectId,
                    0,
                    0.0f,
                    false);
            }
        }
    }

    RectBounds avatarBounds;
    g_pNewHumanImageLib->CalculateBounds(
        &appearance,
        avatarDirection,
        0,
        0,
        &avatarBounds,
        0,
        true,
        true,
        0);
    OffsetRectBounds(&avatarBounds,
                     avatarTileX * g_mapTilePixelWidth,
                     avatarTileY * g_mapTilePixelHeight);
    g_pNewHumanImageLib->Draw(
        &m_snapshotPort,
        &avatarBounds,
        &appearance,
        avatarDirection,
        0,
        0,
        0,
        0,
        0,
        0.0f,
        true,
        true,
        0);

    m_snapshotPort.EndPaint();
}

// UID:0004RK | by-memory/0x00549950-0x005499a2.PhotoPaneOnPaint.md | Completion:92 | Confidence:94
void PhotoPane::OnPaint()
{
    RectBounds bounds;
    m_snapshotPort.GetBounds(&bounds);
    EndPaint();
    BlitSurface(&m_snapshotPort, &bounds, &bounds, 0);
    UpdateSurfaceInfo();
}

// UID:0002R8 | by-memory/0x00549920-0x00549950.PhotoPaneCleanupDestructorBodyRaw.md | Completion:92 | Confidence:94
// Compiler-emitted PhotoPane destructor cleanup/unwind body.
// Source-level cleanup is generated from the implicit PhotoPane destructor,
// the embedded GrafPort m_snapshotPort member, and the PictureViewPane base
// destructor; no standalone handwritten helper should be emitted for this
// raw non-function range.

// UID:0003OV | by-memory\0x006220b8-0x006220cc.PhotoPaneMapFilenameFormatString.md | Completion:86 | Confidence:91 | Empty Emitter Marker
