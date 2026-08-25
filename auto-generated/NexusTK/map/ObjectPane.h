// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000M5
// Source by-file doc: by-file/ObjectPane.md
// UID:00009R | by-class/ObjectPane.md | Completion:92 | Confidence:94
enum ObjectPaneType
{
    kObjectPaneTypeItem = 0,
    kObjectPaneTypeFlying = 1,
    kObjectPaneTypePrimaryEffect = 2,
    kObjectPaneTypeLiving = 3,
    kObjectPaneTypeSecondaryEffect = 4,
    kObjectPaneTypeStatic = 5,
    kObjectPaneTypeBalloon = 6,
    kObjectPaneTypeHitBar = 7,
    kObjectPaneTypeDamageNumber = 8,
    kObjectPaneTypeObjectInfo = 9,
    kObjectPaneTypeLighting = 10,
    kObjectPaneTypeSound = 11
};

class MapPane;
class ObjectList;
class SoundObjectPane;
class GrafPort;
struct MapPoint;

class ObjectPane : public Pane
{
    friend class MapPane;
    friend class ObjectList;

public:
    ObjectPane(unsigned char objectType,
               int objectId,
               int mapX,
               int mapY);
    virtual ~ObjectPane() = 0;

    MapPoint *GetMapPosition(MapPoint *outPosition) const;
    unsigned char GetObjectType() const
    {
        return m_objectType;
    }
    int GetObjectId() const
    {
        return m_objectId;
    }
    ObjectPane *GetAttachedObject() const;
    void SetSoundObjectPane(SoundObjectPane *soundObjectPane);
    void ClearSoundObjectPane();

    virtual void UpdateRenderRegion(const RectBounds *bounds);
    virtual void InvalidateRect(const RectBounds *bounds);
    virtual void SetBounds(
        const RectBounds *paneBounds,
        const RectBounds *objectDataBounds);
    virtual void AttachObject(ObjectPane *attachedObject);
    virtual void DetachObject();
    virtual void ClearOutputRects(
        RectBounds *paneBounds,
        RectBounds *objectDataBounds);
    virtual void SetObjectData(const RectBounds *objectData);
    virtual RectBounds *GetObjectData(RectBounds *outObjectData) const;
    virtual void RenderFrame(GrafPort *target,
                             const RectBounds *bounds)
    {
    }
    virtual RectBounds *ComputeRenderBounds(RectBounds *outBounds);
    virtual void DrawSpriteFrame(GrafPort *target,
                                 const RectBounds *bounds)
    {
    }
    virtual void SetMapPosition(int mapX, int mapY);

protected:
    unsigned char m_objectType;
    int m_objectId;
    int m_mapX;
    int m_mapY;
    RectBounds m_objectDataRect;
    ObjectPane *m_attachedObject;
    float m_attachmentHeightOffset;
    SoundObjectPane *m_soundObjectPane;
    unsigned char m_transientObjectFlag;
};

[[No Children Attached]]
