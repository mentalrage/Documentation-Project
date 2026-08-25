// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000L3
// Source by-file doc: by-file/MapPane.md
// UID:00007Q | by-class/MapPane.md | Completion:93 | Confidence:94
#ifndef NEXUSTK_MAP_MAPPANE_H
#define NEXUSTK_MAP_MAPPANE_H

#include <windows.h>

#include "Pane.h"
#include "GrafPort.h"
#include "Motion.h"
#include "Event.h"
#include "ObjectStatusBlob.h"
#include "UserPane.h"
#include "LivingObjectPane.h"
#include "ObjectList.h"
#include "PacketBuffer.h"
#include "Socket.h"
#include "AlertPanes.h"
#include "ReconnectDialog.h"

#include <vector>

class IntAlphaSurface;
class EffectObjectPane;
class Layer;
class LightingObjectPane;
class LObject;
class Message;
class ObjectPane;
class ScreenEffecter;
class StaticObjectPane;
class InputBlockerPane;
struct EffectInfo;
struct StaticObjEntry;
struct MapTileLayerIds
{
    unsigned short groundTileId;
    unsigned short flags;
    unsigned short staticObjectId;
};
struct MapPaneTileRecord;
struct MapPoint
{
    int row;
    int column;
};

typedef char MapPointSizeMustBe8[
    sizeof(MapPoint) == 8 ? 1 : -1];

struct RectBounds;
typedef RectBounds MapRect;

extern bool g_useEpfAssets;
extern InputBlockerPane *g_pInputBlockerPane;
void __stdcall RequestObjectInfo(unsigned int objectId);
struct Rect;

class MapPane : public Pane
{
friend class LightingObjectPane;

public:
    MapPane(int visibleTileColumns, int visibleTileRows);
    virtual ~MapPane();

    virtual void AddToLayer(
        RectBounds *bounds,
        int order,
        Pane *previousPane,
        Layer *layer);
    virtual void QueueMotionMessage(const RectBounds *bounds);
    virtual void OnChangeMessage(LObject *sender, Message *message);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);
    virtual bool HandleSystemOrControlEvent(Event *event);
    virtual bool OnTimerEvent(int timerId, int param1, int param2);
    virtual void OnPaint();

    bool HasScreenEffecters() const;
    ScreenEffecter *FindActivePixelEffecter();
    void ResetScreenEffecterListFields();
    void ConfigureScreenEffecterList(signed char effectMode);
    void ClearScreenEffecterList();
    void ExitToMenu(bool notifyServer);
    void LoadCompressedMapFile(unsigned short mapId, int unusedLoadOption);
    void SaveCompressedMapFile();
    void MapToScreenCoords(MapPoint *point) const;
    void ScreenToMapCoords(MapPoint *point) const;
    void RedrawVisibleTiles();
    bool ValidateMapAndViewportCoords(
        int mapColumn,
        int mapRow,
        int viewportColumn,
        int viewportRow) const;
    void GetClampedVisibleTileBounds(MapRect *outBounds) const;
    void GetVisibleTileBounds(MapRect *outBounds) const;
    MapPoint *GetVisibleTileSpan(MapPoint *outSpan) const;
    void GetExtendedVisibleTileBounds(MapRect *outBounds) const;
    int CheckMovementCollision(
        int mapColumn,
        int mapRow,
        unsigned char direction);
    bool AllowsMovementStatusTag() const;
    bool ApplyMovementSubstepScroll(unsigned char direction);
    unsigned short GetAdjacentVisibleTileBounds(
        unsigned char direction,
        MapRect *outBounds) const;
    void AfterLocalPlayerWarp();
    void ObjectCallbackNoOp(ObjectPane *objectPane);
    void ScrollViewportByDirection(unsigned char direction);
    void ReindexObjectPanePosition(
        ObjectPane *objectPane,
        int removeRow,
        int removeColumn,
        int addRow,
        int addColumn);
    void RecenterAndSendPosition(
        int targetX,
        int targetY,
        int viewportX,
        int viewportY,
        bool useActiveObjectViewport);
    void ClearQueuedMapStateRefresh();
    void ClearPendingActionPoll();
    ObjectPane *CreateOrUpdateObjectPane(
        int objectId,
        int mapX,
        int mapY,
        unsigned char action,
        ObjectStatusBlob status);
    void RemoveObjectPaneById(int objectId);
    void DetachObjectPane(ObjectPane *objectPane);
    bool HasObjectIntersectingRect(const Rect *rect) const;
    ObjectPane *FindObjectPaneById(int objectId);
    ObjectPane *FindPreviousSelectableObject(ObjectPane *current);
    ObjectPane *FindNextSelectableObject(ObjectPane *current);
    ObjectPane *FindPreviousItemTargetObject(ObjectPane *current);
    ObjectPane *FindNextItemTargetObject(ObjectPane *current);
    ObjectPane *FindPreviousLivingTarget(ObjectPane *current, int targetFilter);
    ObjectPane *FindNextLivingTarget(ObjectPane *current, int targetFilter);
    void RemoveObjectPaneIfPresent(ObjectPane *objectPane);
    void UpdateObjectPaneScreenBounds(ObjectPane *objectPane);
    void UpdateObjectPosition(ObjectPane *objectPane);
    LivingObjectPane *HitTestObjectAtPoint(int y, int x);
    unsigned short GetCurrentMapId() const;
    void RenderMapView();
    void ComputeDayNightBrightnessAndTint(
        unsigned char hour,
        float brightnessScale,
        float brightnessBias,
        float *outBrightness,
        float *outTintAmount) const;
    void SetDayNightFadeTarget(float targetBrightness, float tintAmount);
    void AttachObjectLighting(
        ObjectPane *anchorSource,
        int localOffsetX,
        int localOffsetY,
        int lightImageIndex);
    void RenderDayNightOverlay(const RectBounds *dirtyBounds);
    bool ShouldUseLivingObjectLightOverlay() const;
    bool ShouldOffsetElevatedLivingObjects() const;
    MapPoint *GetObjectScreenPoint(
        ObjectPane *objectPane,
        MapPoint *outPoint) const;
    void FlashMapColor(int drawColor);
    void FinishVisibleObjectRefresh();
    void InteractWithObject(LivingObjectPane *target);
    void CollectMovementTargetObjectIds(
        std::vector<unsigned int> &objectIds) const;
    void SortMovementTargetObjectIdsByDistance(
        std::vector<unsigned int> &objectIds) const;
    void ChangeMap(
        unsigned short mapId,
        short mapWidth,
        short mapHeight,
        unsigned char weatherMode,
        unsigned char transitionState,
        int loadOption);
    void AllocateTileBuffer();
    void RequestObjectEffect(
        unsigned int objectId,
        int effectDescriptorId,
        int timerAction,
        bool renderAfterLivingObjects);
    void RefreshGroupMemberHitBar(unsigned int memberId);
    void ApplyHitBarObjectPane(
        LivingObjectPane *objectPane,
        unsigned int primaryValue,
        unsigned int primaryMaximum,
        unsigned int secondaryValue,
        unsigned int secondaryMaximum);
    void RemoveGroupMemberHitBar(unsigned int memberId);
    bool HandleMapInfoTileRegionPacket(const unsigned char *packet);

private:
    enum MapActionState
    {
        kMapActionMoveTo = 5,
        kMapActionMoveAndUse = 6,
        kMapActionView = 11,
        kMapActionSelect = 12,
        kMapActionInteract = 14,
        kMapActionGroundItem = 15
    };

    void NotifyDeferredMotionChanged();
    LivingObjectPane *FindObjectAtMapPoint(int y, int x);
    ObjectPane *FindItemObjectAtMapPoint(int y, int x);
    void DrawVisibleTiles();
    void RefreshSelectedProfileData();
    void DrawTileAt(int tileX, int tileY, bool refreshStaticObjects);
    unsigned short ComputeTileRectChecksum(const MapRect *bounds) const;
    unsigned int ComputeVisibleTileChecksum(const MapRect &bounds) const;
    MapTileLayerIds *GetLegacyAwareMapTileLayerIds(
        MapTileLayerIds *outTile,
        int mapColumn,
        int mapRow) const;
    unsigned char RemapMovementDirectionForMapScroll(
        unsigned char direction) const;
    void RefreshScrolledTileData(
        int objectColumn,
        int objectRow,
        int viewportColumn,
        int viewportRow,
        unsigned char direction);
    int SelectMovementPathStep();
    bool ShouldClearMovementTimerState() const;
    int BuildPathToPendingActionTarget(
        ObjectPane *target,
        const MapPoint &currentPosition);
    void ResolvePendingActionTarget(
        ObjectPane *target,
        const MapPoint &currentPosition);
    void SetMapState(int weatherType, unsigned char weatherMode);
    void RequestCoordinateEffect(
        int mapColumn,
        int mapRow,
        int effectDescriptorId,
        int timerAction,
        bool renderAfterLivingObjects);
    void ApplyEffectObjectPaneTimerAction(
        EffectObjectPane *effectObjectPane,
        int timerAction);
    void CreateEffectObjectPane(
        LivingObjectPane *target,
        int mapRow,
        int mapColumn,
        EffectInfo effectInfo,
        int timerAction,
        int sequenceIndex,
        bool renderAfterLivingObjects);
    void CreateHitBarObjectPane(
        LivingObjectPane *objectPane,
        unsigned short currentValue,
        unsigned short maximumValue);
    StaticObjectPane *CreateStaticObjectPaneForTile(
        int tileX,
        int tileY,
        unsigned short staticObjectId,
        bool skipListInsertion);
    void RefreshStaticObjectTileRegion(const MapRect &tileBounds);
    void ResetMapResourceStateForModeChange();
    bool InvalidateShiftedMapArea(int deltaX, int deltaY);
    bool HandleObjectInfoPacket(const unsigned char *packet);
    bool HandleEffectMapStatePacket(const unsigned char *packet);
    bool HandleDrawObjectsPacket(const unsigned char *packet);
    bool HandleMovementSpeechBalloonPacket(const unsigned char *packet);
    bool HandleObjectMoveEffectPacket(const unsigned char *packet);
    bool HandleObjectWorldMapCreationPacket(const unsigned char *packet);
    bool HandleActionPacket(const unsigned char *packet);
    bool HandleFlyingObjectUpdatePacket(const unsigned char *packet);
    bool HandleAnimationSoundPacket(const unsigned char *packet);
    bool HandleObjectStatusPacket(const unsigned char *packet);
    bool HandleMapTransitionPacket(const unsigned char *packet);

public:
    int m_screenEffecterCount;
    int m_screenEffecterCapacity;
    ScreenEffecter **m_screenEffecters;
    LivingObjectPane *m_highlightedObjectPane;
    bool m_selectedObjectActive;
    unsigned char m_selectedObjectPadding[3];
    LivingObjectPane *m_selectedObjectPane;
    int m_mapResourceMode;
    bool m_mapEffectEnabled;
    unsigned char m_mapEffectPadding[3];
    Motion m_deferredMotionRecords[32];
    int m_deferredMotionRecordCount;
    bool m_deferMotionMessages;
    bool m_queuedMapStateRefresh;
    bool m_pendingActionPoll;
    unsigned char m_deferredStatePadding;
    int m_pointerEventY;
    int m_pointerEventX;
    unsigned char m_pointerEventModifiers;
    int m_pointerEventDetail;
    unsigned int m_pointerEventMessageTime;
    unsigned char m_pointerEventType;
    float m_currentDayNightBrightness;
    float m_dayNightCurrentScale;
    float m_dayNightCurrentBias;
    float m_dayNightCurrentTint;
    float m_dayNightTintCurveScale;
    float m_dayNightTintCurveBase;
    float m_dayNightTintAmount;
    float m_newHumanProjectionDivisor;
    float m_newHumanProjectionShear;
    float m_dayNightTargetBrightness;
    IntAlphaSurface *m_selectionOverlay;
    float m_dayNightBrightnessScale;
    float m_dayNightBrightnessBias;
    unsigned int m_hoveredObjectId;
    bool m_waitingForLocalPlayerStatus;
    bool m_objectInteractionTimerActive;
    unsigned short m_mapId;
    short m_mapWidth;
    short m_mapHeight;
    MapPaneTileRecord *m_tileBuffer;
    int m_tileOriginX;
    int m_tileOriginY;
    int m_visibleTileColumns;
    int m_visibleTileRows;
    unsigned char m_mapTransitionState;
    unsigned char m_weatherMode;
    bool m_movementStatusTagDisabled;
    unsigned char m_dayNightHour;
    int m_weatherType;
    Pane *m_weatherLayerPane;
    UserPane *m_localPlayerObjectPane;
    Pane *m_auxiliaryPane;
    Layer *m_activeScreenLayer;
    ObjectList *m_objectList;
    GrafPort m_viewportGrafPort;
    int m_mapFlashColor;
    unsigned char m_mapRuntimeMode;
    bool m_visibleObjectRefreshPending;
    bool m_refreshWholeVisibleMap;
    unsigned char m_mapRefreshPadding;
    int m_zoneMusicId;
    int m_zoneMusicFallbackTrackIndex;
    int m_zoneMusicVolumeScale;
    wchar_t m_mapName[256];
    unsigned short m_mapNameLength;
    wchar_t m_mapResourceName[256];
    unsigned short m_mapResourceNameLength;
    unsigned char m_actionStatePrefix[8];
    bool m_rightButtonMovePending;
    int m_pendingActionRow;
    int m_pendingActionColumn;
    int m_pendingActionY;
    int m_pendingActionX;
    int m_actionStartY;
    int m_actionStartX;
    int m_pendingActionState;
    unsigned int m_pendingActionTargetObjectId;
    bool m_rightButtonTrackingActive;
    unsigned char m_pendingActionModifiers;
    bool m_leftButtonTrackingActive;
};

typedef char MapPaneSizeMustBe0x910[
    sizeof(MapPane) == 0x910 ? 1 : -1];

// UID:0000T7 | by-global/MapTilePixelDimensions.md | Completion:91 | Confidence:92
extern short g_mapTilePixelWidth;
extern short g_mapTilePixelHeight;

// UID:0000PR | by-global/g_activeMapPane.md | Completion:91 | Confidence:92
class MapPane;

extern MapPane *g_activeMapPane;

#endif // NEXUSTK_MAP_MAPPANE_H
