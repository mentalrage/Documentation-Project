*** UID:00007Q | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000L3 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
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
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# MapPane

## UID00037R Add-To-Layer And Keyboard Command Contract - 2026-08-24

- Exact child [UID:00037R][0x00506d20-0x00507150.MapPaneResizeCommandInputCore](by-memory/0x00506d20-0x00507150.MapPaneResizeCommandInputCore.md) emits the sole `MapPane::AddToLayer(RectBounds *, int, Pane *, Layer *)` and `MapPane::HandleKeyOrTextEvent(Event *)` definitions into `NexusTK/map/MapPane.cpp`. This complete class owns both virtual declarations; the child H channel remains blank.
- `AddToLayer` is the primary-vtable method at `0x0061e74c -> 0x00506d20`. The declaration's first parameter is non-const because the recovered ABI and base delegation use mutable `RectBounds *`; `previousPane` preserves the source role of the third parameter.
- `HandleKeyOrTextEvent` is the secondary EventHandler-facet slot at `0x0061e770 -> 0x00506df0`. It implements queued-state clearing, exact key translation and key-down gating, day/night steps on `-`/`=`, Ctrl+R map refresh, Alt+X quit, name visibility on `n`, and Control alphabetic inventory slots 1..52.
- The complete class continues to own the existing fields and helper declarations used by that source. ObjectList, UserPane, MapRefreshDimmer, QuitDialog, Event/EventMan, Config, packet output, map-tile dimensions, and transfer-dialog state remain dependencies rather than nested MapPane definitions.
- UID00037R remains score-compatible with this class's `93/94` source-ready declaration. Compiler jump/classifier data and vtable entries regenerate from ordinary C++ and are not declared as arrays or raw tables.

## 2026-08-18 Lighting Access And Bounds Contract

The existing complete class remains singular. One `friend class LightingObjectPane;` is inserted immediately inside the class before its first `public:`, and the existing queue declaration is replaced in place by `virtual void QueueMotionMessage(const RectBounds *bounds);`. Existing `class LightingObjectPane;`, `struct RectBounds;`, separate `struct Rect;`, every unrelated declaration/member, and the class closing brace remain unchanged. Friendship reflects direct `m_selectionOverlay` access and avoids inventing an accessor; canonical queue geometry is the exact 16-byte RectBounds.

## UID00037S Pointer-Event Source Contract - 2026-07-29

- [UID:00037S][0x00507150-0x00507c90.MapPaneMouseEventCore](by-memory/0x00507150-0x00507c90.MapPaneMouseEventCore.md) owns the source-complete `HandlePointerOrMouseEvent(Event *)` definition. This class owns the private `MapActionState` constants, `FindItemObjectAtMapPoint(int y, int x)` declaration, exact pointer-event fields at `+0x3a0..+0x3b4`, hovered-object id at `+0x3ec`, and action/tracking fields at `+0x8e8..+0x90e`.
- Natural 32-bit MSVC alignment supplies unnamed gaps at `+0x3a9..+0x3ab`, `+0x3b5..+0x3b7`, `+0x8e9..+0x8eb`, and tail byte `+0x90f`; no source-visible padding arrays are invented. The complete declaration remains exactly `sizeof(MapPane) == 0x910`.
- `RequestObjectInfo(unsigned int)` is an externally linked MapPane source helper declared at global scope so both MapPane and RightButtonMenuPane translation units can call the one UID0003TU definition. Historical `sub_50F4D0` and `MapPaneSendObjectAction43Packet` are retained only as superseded reverse-engineering aliases.
- Historical `m_pendingMovementState`, `m_pendingMapStateToken`, `m_pendingActionModeActive`, `m_pendingActionTileX/Y`, broad byte-array `m_pendingActionState`, deferred-surface fields, and `RefreshDeferredMapSurfacesForTileRegion` were provisional descriptions. The accepted field/branch evidence above replaces them without changing any binary offset or unrelated member.

## UID0001AS Profile Sidecar Refresh Member Contract - 2026-07-28

- [UID:0001AS][0x005063e0-0x00506962.ProfileSidecarRefresh](by-memory/0x005063e0-0x00506962.ProfileSidecarRefresh.md) is the exact MapPane member `void MapPane::RefreshSelectedProfileData()`, not a ProfileStorage function or an unowned file-local helper. The body reads the selected-profile fields at MapPane offsets `+0x3b8` and `+0x3bc`; the optimized machine body does not otherwise consume `this`, which explains IDA's historical cdecl-shaped decompilation without changing source ownership.
- Three independent source call routes agree on a MapPane receiver. [UID:0001DU][0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper](by-memory/0x0053fe90-0x0053fe9b.ProfileDialogRefreshHelper.md) loads [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) from `0x0067a764` and tail-jumps to UID0001AS. The ProfileDialog action path performs the same active-map-pane dispatch. The direct MapPane-side call site already carries the containing object as the receiver. These routes reject ProfileDialog, ProfileStorage, a free helper, and compiler-only ownership.
- The member retains all established sidecar behavior: it probes the five extensions in [UID:00027P][0x0066dd60-0x0066dd78.ImageExtensionPointerTable](by-memory/0x0066dd60-0x0066dd78.ImageExtensionPointerTable.md), builds selected-profile paths, invokes the FaceRipper command when required, reads the `.jpf` sidecar, validates its opcode/length structure, and commits decoded profile fields. [UID:0003IV][0x0061e964-0x0061e9fc.ProfileSidecarImageStrings](by-memory/0x0061e964-0x0061e9fc.ProfileSidecarImageStrings.md) supplies source-generated literals used by this MapPane implementation and does not require an independent emitter.
- Source placement is therefore [UID:0000L3][MapPane](by-file/MapPane.md). UID0001AS owns the member definition; UID00027P owns the one file-local extension table at MapPane position `1`; UID0003IV is non-emitting literal evidence covered by those source constructs; UID0001DU remains the separately emitted ProfileDialog file-local forwarding helper. No definition is duplicated in this class declaration.
- The complete formal declaration was migrated byte-for-text from the incorrect CPP channel to the H channel during the accepted UID0001DU callback. Only `void RefreshSelectedProfileData();` was added, once, in the private helper group. The CPP channel is now blank because exact by-memory children own method and data definitions. The existing includes, forward declarations, inheritance, virtual surface, full member layout, `0x910` size guard, and `[[CHILDREN]]` placement were otherwise preserved.
- Class metadata remains `93/94`, canonical owner/emitter [UID:0000L3][MapPane](by-file/MapPane.md), position `0`, and reconstructable. The correction changes declaration topology and source ownership, not the already-supported class score. Historical B003/B008 ProfileStorage/free-helper interpretations remain useful as rejected assignment-time hypotheses, but they are not the current source route.

## UID000421 Visible Tile Bounds Source Contract - 2026-07-22

- [UID:000421][0x00505310-0x0050534d.MapPaneGetVisibleTileBounds](by-memory/0x00505310-0x0050534d.MapPaneGetVisibleTileBounds.md) is the exact source-ready `void MapPane::GetVisibleTileBounds(MapRect *outBounds) const` member. The existing complete managed declaration already contains this signature after `GetClampedVisibleTileBounds` and before `GetVisibleTileSpan`; the declaration, full class union, `0x910` size guard, closure, and `[[CHILDREN]]` placement remain unchanged.
- Live IDA MCP session `9b0396a3` proves exact range `0x00505310-0x0050534d`, 61 bytes, 23 instructions, one block, no callees, body SHA-256 `600865C16EB020500B7C7E9A0A591A41DFA5784A947D745A503BEB3C5BB084E0`, one direct code xref, and no xref to exclusive end `0x0050534d`. The ABI is one `MapRect *` stack argument with `this` in `ECX` and `retn 4`.
- The method reads exact MapPane layout fields `m_tileOriginX` at `+0x3fc`, `m_tileOriginY` at `+0x400`, `m_visibleTileColumns` at `+0x404`, and `m_visibleTileRows` at `+0x408`. It writes canonical `MapRect`/`RectBounds` edges `left/top/right/bottom` at `+0/+4/+8/+0xc` as `origin - 1` and `origin - 1 + visible span + 2`, yielding unclamped half-open bounds with a one-tile margin.
- The sole caller is [UID:0003U6][0x005a2e00-0x005a36f0.UserPaneProcessMovement](by-memory/0x005a2e00-0x005a36f0.UserPaneProcessMovement.md) at `0x005a301e`. It loads the receiver from `UserPane::m_mapPane`, passes a local `MapRect`, ignores incidental `EAX`, then increments left/top and decrements right/bottom to remove the margin before movement-threshold comparisons. Complete receiver-read/no-write evidence supports source `const`; caller/sibling evidence supports source `void` despite IDA's decompiler-shaped `int`.
- [UID:000420][0x00505290-0x00505304.MapPaneGetClampedVisibleTileBounds](by-memory/0x00505290-0x00505304.MapPaneGetClampedVisibleTileBounds.md) clamped one-tile bounds, [UID:000422][0x00505350-0x0050536b.MapPaneGetVisibleTileSpan](by-memory/0x00505350-0x0050536b.MapPaneGetVisibleTileSpan.md) visible span, [UID:000423][0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds](by-memory/0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds.md) clamped extended bounds, and raw [UID:000424][0x005053f0-0x0050542d.MapPaneGetUnclampedExtendedVisibleTileBounds](by-memory/0x005053f0-0x0050542d.MapPaneGetUnclampedExtendedVisibleTileBounds.md) unclamped extended bounds remain distinct child methods. UID000421 alone owns this exact body; no aggregate wrapper, duplicate declaration, UserPane ownership, FittingRoom placement, standalone helper, or no-owner route is added.
- The historical duplicate UID000421 on FittingRoom thunk bytes was not MapPane evidence. Callback phase A allocated [UID:0004WG][0x00424584-0x0042459a.FittingRoomUserImageControlPaneAdjustorThunks](by-memory/0x00424584-0x0042459a.FittingRoomUserImageControlPaneAdjustorThunks.md), repaired all eight FittingRoom references, and left UID000421 unique to this method before class synchronization.
- Class metadata stays `93/94`, owner/emitter [UID:0000L3][MapPane](by-file/MapPane.md), position `0`, and reconstructable. Exact by-memory children continue to own definitions; this class page owns the complete compile-visible declaration only.

## UID0003TT Object-Status Packet Source Contract - 2026-07-16

- The complete position-zero managed declaration already contains private `bool HandleObjectStatusPacket(const unsigned char *packet)` in exact source order after `HandleAnimationSoundPacket`. The class remains `93/94`, owner/emitter UID0000L3, reconstructable, size `0x910`, and its managed declaration, closure, size guard, and `[[CHILDREN]]` placement remain byte-for-byte unchanged.
- Exact implementation child [UID:0003TT][0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket](by-memory/0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md) is source-ready at `92/94`, owner/emitter UID00007Q, blank position, `Nested:0`, and has the sole opcode-`0x1d` dispatcher call.
- The method parses BE32 object id, full/partial ObjectStatusBlob for selector `0/1`, object-info type, and counted ACP name. Parse/name conversion precedes the ObjectList null test; a lookup miss sends the exact MapPane.cpp file-static object-refresh request.
- Living behavior uses existing `m_objectList` and `m_localPlayerObjectPane`, LivingObjectPane fields, UserPane `m_playerSettingsState[0]` and `m_currentAppearance`, ObjectInfoObjectPane methods, SoundManager, Socket, TimerHandler, and file-static UID0003TW. Those providers remain dependencies and do not transfer ownership or require new class fields.
- Exact living order preserves Human composition rewrite, name/object-info writes, unsafe SetPrimaryName-before-null-test behavior, separate effect and previous-status snapshots, `RemoveSpecialEffect`, exact body/weapon/shield sounds, two-byte `{0x13,0x04}` send, timer cancellation, local appearance copy, `SetSpriteConfig`, and final overlay refresh.
- Item type with appearance at least `0xc000` calls source-ready UID0003HS `ItemObjectPane::UpdateItemStatus`. ItemObjectPane and ObjectStatusBlob retain their own class/file declarations and source ownership.
- The method trusts packet/global/object state, ignores conversion/helper/send/sound/timer/setter results, and returns true on every path. No packet abstraction, guard repair, raw offset, direct TimerMgr declaration, duplicate UID0003TW body, compiler range/security lowering, or ABI scaffolding is added to this class.

## UID0003TS Animation-Sound Packet Source Contract - 2026-07-16

- The complete position-zero managed declaration contains private `bool HandleAnimationSoundPacket(const unsigned char *packet)` in exact packet-handler source order after `HandleFlyingObjectUpdatePacket` and before `HandleObjectStatusPacket`. The class remains `93/94`, owner/emitter UID0000L3, reconstructable, size `0x910`, and otherwise byte-for-byte preserves the full B001/B002/B003/B004/B005/B011 method, field, guard, closure, and `[[CHILDREN]]` union.
- Exact implementation child [UID:0003TS][0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket](by-memory/0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket.md) is source-ready at `92/94`, owner/emitter UID00007Q, blank position, `Nested:0`, and has the sole opcode-`0x19` dispatcher call. UID0001AW remains a non-emitting split/index; the child alone supplies the source method.
- MapPane fields `+0x4d0`, `+0x4d4`, and `+0x4d8` are `m_zoneMusicId`, `m_zoneMusicFallbackTrackIndex`, and `m_zoneMusicVolumeScale`. UID0003TS writes BE16 zone id, BE16 fallback track index, and one-byte volume scale; the constructor supplies exact defaults `0`, `0`, and `100`; MusicControlDialog replays the same three values; SoundManager feeds argument three into `m_currentTrackVolumeScale` and Miles stream volume.
- Historical `m_mapDisplayOriginX`, `m_mapDisplayOriginY`, `m_mapDisplayScalePercent`, and zone-music fade-time interpretations are superseded. The exact writer, constructor defaults, replay route, `PlayMusicByZone` argument order, and downstream volume scaling reject display-coordinate and fade semantics without changing the three four-byte layout slots.
- Subtype zero preserves the Config MIDI-enabled gate, BE16 sample id, and byte volume. Subtype one stores the three class fields and conditionally calls `PlayMusicByZone` with loop count zero. Subtype two selects a nonzero MIDI track or stops playback for zero. Other subtype values continue into framed parsing with source locals intentionally untouched rather than receiving invented defaults.
- Sound, origin, playback, and lifetime records use one-byte types/lengths plus exact BE16/BE32 values. Object origin resolves through `m_objectList`, preserves two ordered `GetMapPosition` calls, and links the new SoundObjectPane to its owner. Coordinate/default origins use packet X/Y or `0,0`. Every nonnull pane is inserted into ObjectList before playback starts.
- The target intentionally trusts the server packet. The class/source contract adds no packet/null/length/range checks, no selector default rejection, no one-call position simplification, and no alternate packet abstraction. SoundObjectPane, ObjectPane, ObjectList, MidiPlayer, SoundManager, Config, and PacketBuffer retain their own source ownership.
- Ordinary `new SoundObjectPane` is source-authored. Pool allocation/free, three constructor-unwind funclets, vptr stores, SEH/cookie state, and byte-reader lowering are compiler/runtime products and do not become class members or handwritten helpers. Retained `0x0050ec30` remains zero-route corroboration and is not declared as a second source method.
- The callback changes only the three accepted field names inside the complete managed block. UID0003TP, UID0004SN, UID0003TQ, UID0004SJ-UID0004SM, UID0003TK, UID0003TO, UID0003TW/UID0003TX, WorldMap/Pursuit routes, and every unrelated current declaration remain intact.

## UID0003TP World-Map Packet Contract - 2026-07-16

- The complete managed class declaration already contains private `bool HandleObjectWorldMapCreationPacket(const unsigned char *packet)` in source/address order; it remains byte-for-byte unchanged with the `0x910` size guard, class closure, `[[CHILDREN]]`, and the entire B002/B003/B004/B005/B011 union including UID0003TQ and its UID0004SJ-UID0004SM dependencies.
- Exact implementation child [UID:0003TP][0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket](by-memory/0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket.md) is now source-ready at `92/94`. Its sole opcode-`0x2e` dispatcher route proves MapPane ownership; WorldMapPane, Layer, ScreenPane, PacketBuffer, MemoryMan, and TimerMgr remain called dependency owners.
- The method uses `m_localPlayerObjectPane` to form the TimerHandler owner removed before parsing. It writes a newly allocated Layer to `m_activeScreenLayer` (`+0x420`), installs the WorldMapPane into full-screen overlay context, and stores the pane in `m_auxiliaryPane` (`+0x41c`). Those exact fields and directions are already present in this complete class layout.
- Trusted packet parsing yields a converted 24-wide-character map identifier, unsigned node count/current index, canonical MapPoint row/column tables, allocated wide node names, destination map IDs/points, and a directed row-major `std::vector<bool>` adjacency matrix. A consumed BE16 field remains intentionally unused.
- When `g_useEpfAssets != 1`, exact whole-string `wcscmp` pairs for `wm`/`WM` through `wm4`/`WM4` overwrite temporary node coordinates before WorldMapPane construction. The comparisons are not suffix, prefix, case-insensitive, or normalized matching, and no custom UInt32Vector/static preset table belongs to this class.
- The target preserves its trusted-server-buffer behavior: no packet-length, count, index, fixed-array, allocation, conversion, global-pointer, or exception guards are introduced. Compiler/STL lowering, raw offsets, and decompiler helper names remain excluded from the class declaration.
- New real child [UID:0004SN][0x00512840-0x0051289f.MapPaneHandlePursuitMessageDialogPacket](by-memory/0x00512840-0x0051289f.MapPaneHandlePursuitMessageDialogPacket.md) is deliberately not a MapPane member. Its machine ABI has no receiver, so it remains a file-local `static bool __stdcall` MapPane.cpp adapter that constructs a MessageDialogs-owned `PursuitMessageDialogCreator`, calls `CreateDialog`, and returns true. Its zero inbound xrefs cap liveness confidence but do not change this class surface.
- Historical target descriptions using `HandleObjectCreatePacket`, custom UInt32Vector, suffix/case-insensitive routing, unresolved MapPane fields, or blank C++ are superseded. The existing private declaration is the accepted source-facing class contract.
- UID00007Q remains `93/94`, canonical owner/emitter UID0000L3, position `0`, and reconstructable; this bounded target synchronization does not inflate class scores or replace any unrelated formal content.

## UID0003TQ Action-Combat Packet Source Contract - 2026-07-16

- The complete managed declaration already contains exact private `bool HandleActionPacket(const unsigned char *packet)` in address/source order; this callback preserves the class block byte-for-byte, including every B002/B003/B004/B005/B011 method, field, forward declaration, `0x910` guard, class closure, and `[[CHILDREN]]` marker.
- Exact child [UID:0003TQ][0x00512960-0x00512ca4.MapPaneHandleActionPacket](by-memory/0x00512960-0x00512ca4.MapPaneHandleActionPacket.md) now emits the sole opcode-`0x13` definition at `92/94`. It retains trusted `const unsigned char *` parsing, rich `g_useEpfAssets == 1` and legacy branches, signed plain-char action semantics, and unconditional true return.
- Rich behavior resolves LivingObjectPane through ObjectList, plays masked damage effect, replaces DamageNumber through [UID:0004SK][0x00539230-0x0053935e.DamageNumberObjectPaneConstructor](by-memory/0x00539230-0x0053935e.DamageNumberObjectPaneConstructor.md), preserves duplicated [UID:0004SM][0x005adba0-0x005adbdc.UserPaneIsGroupMember](by-memory/0x005adba0-0x005adbdc.UserPaneIsGroupMember.md) policy, recreates HitBar through UID0003TH, advances local movement/Bow timing through [UID:0004SL][0x005a8fc0-0x005a8ff2.UserPaneAdvanceMovementSendTick](by-memory/0x005a8fc0-0x005a8ff2.UserPaneAdvanceMovementSendTick.md), and reuses UID0003TO with intentionally unseeded packet byte zero.
- Bow animation storage/setter remains owned by [UID:000011][BowGaugeObjectPane](by-class/BowGaugeObjectPane.md) and [UID:0004SJ][0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick](by-memory/0x00538d00-0x00538d10.BowGaugeObjectPaneSetAnimationStartTick.md). DamageNumber construction/class state remains owned by UID00003F. UserPane owns both private helper bodies. These dependencies do not migrate into MapPane source ownership.
- Compiler pool allocation, vptr stores, EH/cookie state, deleting wrappers, vtables, and adjustor mechanics remain excluded. The source intentionally adds no packet/null/length checks, membership cache, damage clamp, nested-byte-zero initialization, or duplicate child body.
- Class metadata remains `93/94`, owner/emitter UID0000L3, position 0. No score or formal inflation is applied by this target-specific prose synchronization.

## UID0003TX Object-Info Declaration Integration - 2026-07-16

- The complete position-0 `0x910` declaration was rebased callback-last over the stable B003/B005/B004/B011 union. Ordered comparison proves the formal differs from the leased pre-edit block only by the accepted six-line UID0002QN signature correction, removal of `struct ItemObjectImageEntry;`, and removal of the stale five-line image-entry overload; every unrelated declaration, field, size guard, class closure, and `[[CHILDREN]]` line is preserved.
- Public factory ABI is now `CreateOrUpdateObjectPane(int objectId, int mapX, int mapY, unsigned char action, ObjectStatusBlob status)`. Stack cleanup and two callers prove the 68-byte status is passed by value; historical tile-first/const-reference wording is superseded.
- Private `bool HandleObjectInfoPacket(const unsigned char *packet);` remains the opcode-`0x33` member declaration. Its source body owns status parsing, ACP name conversion, expanded visible gate, ObjectInfo type/color selection, replacement/registration, and status/group refresh ordering.
- Existing `AttachObjectLighting(ObjectPane *, int, int, int lightImageIndex)` remains the sole lighting declaration. The removed `ItemObjectImageEntry` overload had no matching current source definition and conflicts with direct ItemInfo `lightImageIndex` consumption.
- The class preserves B003 static-object types/methods, B005 opcode-`0x15` map/effect state, B004 opcode-`0x29` signed effect descriptor/action routes and HitBar work, B011 map-info region declarations, all render/movement/effect/map fields, exact `0x910` size guard, and child order.
- ObjectInfoObjectPane, LivingObjectPane, UserPane, ItemInfo, ItemObjImageLib, and ItemObjectPane declarations supply compile-visible dependencies in their own modules. No duplicate child body, packet aggregate body, file-root metadata, synthetic accessor, or ABI wrapper is added here.
- Unchecked packet/factory/allocation/UI behavior is preserved. Vptr stores, EH/cookies, range-check failure calls, scalar deleting wrappers, vtables, pool/storage operations, and decompiler artifacts remain compiler-generated or exact support-owned.

## UID0003TI / UID0003TJ Static-Object Tile Reconciliation - 2026-07-15

- [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md) is the exact private `StaticObjectPane *MapPane::CreateStaticObjectPaneForTile(int tileX, int tileY, unsigned short staticObjectId, bool skipListInsertion)` definition. It queries StaticObjImageLib bounds and metadata, deliberately discards `IsRectEmptyOrInvalid`'s predicate result, source-constructs a StaticObjectPane, conditionally attaches lighting from signed metadata, updates screen bounds, optionally inserts into ObjectList, and returns the pane. Pool allocation, EH cleanup, and cookies are compiler lowering around ordinary `new`.
- [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md) is the exact private `void MapPane::RefreshStaticObjectTileRegion(const MapRect &tileBounds)` definition. Its row-major loops use half-open top/bottom and left/right bounds, call `GetLegacyAwareMapTileLayerIds`, use typed UID0004SI ObjectList lookup, retain a matching id with no update, preserve duplicated stale/zero invalidate-remove-release-delete sequences, and create a nonzero replacement with final `false`.
- `MapTileLayerIds` is exactly six bytes: unsigned-short `groundTileId`, `flags`, and `staticObjectId`. The tile helper stores those three words only; loader/writer/allocator/saver and UID0004HP independently agree. Historical three-dword `groundTileId/objectNation/flags` wording is superseded, and no packing pragma is needed because each member is naturally 2-byte aligned.
- [UID:0004SI][0x00532eb0-0x00532f67.ObjectListFindStaticObjectPaneAt](by-memory/0x00532eb0-0x00532f67.ObjectListFindStaticObjectPaneAt.md) supplies typed `(tileX, tileY)` static-row lookup. [UID:0000E1][StaticObjectPane](by-class/StaticObjectPane.md) supplies natural inline `GetStaticObjectId()` over its unsigned-short `+0x128` field. These public declarations close private access without raw offsets or friendship-only source.
- UID000425 collision policy is unchanged but now uses `staticObjectId` for `g_objectNationMap` indexing and `(flags & 1) == 0` for the first 16-bit flag bit. The stale `objectNation` name and `0x10000` mask came from the disproven dword view.
- Source excludes EDI/EAX decompiler artifacts, raw offsets, explicit deleting-destructor dispatch/flags, pool free, vptr/base teardown, RTTI/vtable arrays, SEH, and cookies. MapPane owns tile reconciliation/creation policy; ObjectList owns storage lookup; StaticObjectPane owns the object class; StaticObjImageLib owns resource bounds/metadata.

## UID0003TH CreateHitBarObjectPane Source Contract - 2026-07-15

- [UID:0003TH][0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPane](by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPane.md) is the exact private `MapPane::CreateHitBarObjectPane` definition at `[0x0050edd0,0x0050eef5)`. Its complete 293-byte range hashes to `170AE5F6E8296C07A1F831432A64B47FFBA36A9BD6E903F81A73FBAB00316D6F`; it has 14 blocks and only the two direct opcode-`0x13` calls at `0x00512b96` and `0x00512c7f` in UID0003TQ.
- The source signature takes `LivingObjectPane *` plus unsigned-short current and maximum values. Both callers resolve the typed object, prove the parsed current value is at most 100, and pass literal maximum `100`; the target consumes two unsigned words and returns with `ret 0x0c` for the complete three-argument contract.
- The body returns only for a null object, obtains `MapPoint` row/column, and selects constructor style `1` only for `objectPane->m_objectStatus.m_statusKind == ObjectStatusBlob::HumanObject`; every other status kind selects style `0`. Separate ordinary-new branches preserve the binary's distinct allocation/constructor/EH sites.
- The constructed pane is installed through `SetHitBarObjectPane`, registered by `m_objectList->AddObjectPane`, scheduled through `g_pTimerMgr` as its inherited `TimerHandler` view for event `0` after `500` ms, updated, then invalidated using inherited GrafPort bounds. Event `0` reaches the `0x005386a0` callback that deletes the complete HitBarObjectPane.
- Source excludes pool allocation lowering, EH state, security cookies, vptr stores, raw multiple-inheritance adjustment, raw offsets/vtable slots, and deleting-destructor mechanics. There is no value clamp in this helper, no old-pane cleanup, no preexisting-slot read, and no allocation/List/Timer null or result check.
- The historical `CreateHitBarObjectPaneEventOverlay(... unsigned int ...)`, generic `+0x178` state, and blank-C++ account are superseded. The class score, complete union, unrelated fields and methods, ownership, emitter order, inheritance, size guard, and all other formal content remain unchanged.

## Complete Source-Era Declaration Closure - 2026-07-15

- UID00007Q is the complete `MapPane` class/header declaration emitter at position `0`. It is `93/94`, remains canonically owned and emitted by UID0000L3, remains reconstructable, and emits before the exact by-memory method definitions. The managed block declares every `MapPane::` definition currently emitted by `MapPane.cpp`, the supported vtable overrides, the private helper surface required by those bodies, the complete `0x910` field layout, and `[[CHILDREN]]` after the class and size guard.
- The source inheritance is exactly `class MapPane : public Pane`. `Pane` already supplies the leading `GrafPort`, the EventHandler view at `+0xa0`, and the TimerHandler view at `+0xa4`; the three constructor/destructor vptr stores are compiler output for those inherited views, not three explicit MapPane base clauses or handwritten stores. Primary-vtable evidence supports the ordinary destructor, `QueueMotionMessage`, `OnChangeMessage`, `AddToLayer`, and `OnPaint`; the secondary and tertiary tables support event and timer overrides.
- The object-size route is independent and exact. The main-UI construction path allocates `0x910` bytes before calling `MapPane::MapPane`, the constructor initializes the first derived field at `+0xf8`, the 32-element `Motion` array at `+0x118` with `0x14` stride, and the embedded `GrafPort` at `+0x428`; the ordinary destructor destroys that same array and embedded port in reverse order. `MapPaneSizeMustBe0x910` makes layout drift visible.
- Complete-value dependencies are `Pane.h`, `GrafPort.h`, and `Motion.h`; `std::vector` requires `<vector>`. Pointer/reference-only dependencies are forward-declared. `MapPaneTileRecord` is a pointer here and its six-byte definition remains UID0004HP-owned. `ObjectStatusBlob` remains UID00009S/UID0000M6-owned and is passed by reference. These declaration dependencies do not transfer class or method ownership.
- Canonical field names are one name per proven offset. `+0x414` is `m_weatherLayerPane`, `+0x418` is `m_localPlayerObjectPane`, `+0x3f0` is `m_waitingForLocalPlayerStatus`, inherited viewport coordinates remain `m_viewportPixelX/m_viewportPixelY`, and `+0x424/+0x428/+0x4c8` remain `m_objectList`, `m_viewportGrafPort`, and `m_mapFlashColor`. Historical `m_deferredCleanupPane`, `m_activeObjectPane`, `m_objectListDetachPreserve`, `m_pendingLocalObjectRefresh`, and `m_pixelOriginX/m_pixelOriginY` spellings are superseded contextual aliases, not union members.
- MapPane state is public in this reconstruction because accepted Riding, Monster, UserPane, and object-pane source routes compile direct member loads/stores with no out-of-line getter calls. `UpdateObjectPaneScreenBounds` and `UpdateObjectPosition` are likewise public because cross-source object/update callers reach them directly. Private packet/render helpers remain under the private section.
- The unknown original private lexemes do not remain a source-shape blocker. Six dwords at `+0x3a0`, the action-state bytes at `+0x8e0`, and the smaller alignment bytes use bounded behavior-based names in the formal declaration. Their offsets, sizes, constructor writes, consumers, and padding are exact; alternative lexical spellings remain confidence caps only.
- Exact by-memory children continue to own all method bodies. The class page owns declarations only and therefore does not duplicate any definition. Compiler-generated vptr writes, adjustor/scalar deleting destructors, SEH/cookies, STL allocator/EH lowering, and vtable bytes remain excluded from handwritten source.

## UID00037W Paint And Lighting Source Surface

- [UID:00037W][0x0050a500-0x0050ab95.MapPanePaintLightingCore](by-memory/0x0050a500-0x0050ab95.MapPanePaintLightingCore.md) is now a `92/94` non-emitting split index over eight source routines and six alignment spans. It has owner `NONE`, reconstructable false, blank emitter/position/formal C++, and does not represent one broad class method.
- The exact class-member source order is [UID:0004RA][0x0050a500-0x0050a837.MapPaneOnPaint](by-memory/0x0050a500-0x0050a837.MapPaneOnPaint.md), [UID:0004RB][0x0050a840-0x0050a8b0.MapPaneComputeDayNightBrightnessAndTintRaw](by-memory/0x0050a840-0x0050a8b0.MapPaneComputeDayNightBrightnessAndTintRaw.md), [UID:0004RC][0x0050a8b0-0x0050a932.MapPaneSetDayNightFadeTarget](by-memory/0x0050a8b0-0x0050a932.MapPaneSetDayNightFadeTarget.md), [UID:0004RD][0x0050a940-0x0050a9df.MapPaneAttachObjectLighting](by-memory/0x0050a940-0x0050a9df.MapPaneAttachObjectLighting.md), [UID:0004RE][0x0050a9e0-0x0050aaef.MapPaneRenderDayNightOverlayRaw](by-memory/0x0050a9e0-0x0050aaef.MapPaneRenderDayNightOverlayRaw.md), [UID:0004RG][0x0050ab40-0x0050ab65.MapPaneShouldUseLivingObjectLightOverlay](by-memory/0x0050ab40-0x0050ab65.MapPaneShouldUseLivingObjectLightOverlay.md), and [UID:0004RH][0x0050ab70-0x0050ab95.MapPaneShouldOffsetElevatedLivingObjects](by-memory/0x0050ab70-0x0050ab95.MapPaneShouldOffsetElevatedLivingObjects.md).
- The complete class/header union declares `void OnPaint()`, `void ComputeDayNightBrightnessAndTint(unsigned char, float, float, float *, float *) const`, `void SetDayNightFadeTarget(float, float)`, `void AttachObjectLighting(ObjectPane *, int, int, int)`, `void RenderDayNightOverlay(const RectBounds *)`, `bool ShouldUseLivingObjectLightOverlay() const`, and `bool ShouldOffsetElevatedLivingObjects() const` alongside the full established method family. Exact by-memory children remain the sole definition owners.
- [UID:0004RF][0x0050aaf0-0x0050ab3b.HasLightSourceEquipmentRaw](by-memory/0x0050aaf0-0x0050ab3b.HasLightSourceEquipmentRaw.md) is deliberately excluded from the class declaration. Its receiverless `ret 0x44` ABI proves a file-static `HasLightSourceEquipment(ObjectStatusBlob)` helper owned by [UID:0000L3][MapPane](by-file/MapPane.md).

Exact fields required by the accepted methods:

| Offset | Current source-facing member | Exact role |
| --- | --- | --- |
| `+0xf8/+0xfc/+0x100` | `m_screenEffecterCount`, effecter capacity, `m_screenEffecters` | Accepted effect-list triplet; OnPaint reduces the inlined construction policy to `ConfigureScreenEffecterList`. |
| `+0x104` | `LivingObjectPane *m_highlightedObjectPane` | OnPaint clears highlight/pointer for terminal objects or human composition mode 5 with GM suffix. |
| `+0x118` | `Motion m_deferredMotionRecords[32]` | Exact 32-element, `0x14`-stride deferred dirty-motion array. |
| `+0x398/+0x39c` | `m_deferredMotionRecordCount`, `m_deferMotionMessages` | Count and active/defer byte consumed and reset by OnPaint. |
| `+0x3b8` | `m_currentDayNightBrightness` | Baseline for quadratic tint computation. |
| `+0x3c8/+0x3cc` | `m_dayNightTintCurveScale`, `m_dayNightTintCurveBase` | Quadratic tint coefficients. Historical duration names are superseded aliases. |
| `+0x3d0/+0x3d4/+0x3d8` | `m_dayNightTintAmount`, `m_newHumanProjectionDivisor`, `m_newHumanProjectionShear` | Exact scaled-RLE tint/projection roles; setter writes tint, `2.0f`, and `0.8f`. |
| `+0x3dc` | `m_dayNightTargetBrightness` | Setter/render/predicate target brightness. |
| `+0x3e0` | `IntAlphaSurface *m_selectionOverlay` | Pointer-owned day/night shadow/light overlay; allocation/deletion and helper dereferences reject an embedded-object type. |

- UID0004RA is a 252-instruction/41-block vtable method at `0x0050a500`; it clears the highlighted object under exact terminal/human-composition-GM conditions, applies the accepted screen-effecter helper policy, and uses the exact clip/origin/exposed-region deferred-dirty rendering order.
- UID0004RB is a complete raw five-argument mapper with `ret 0x14`; UID0004RC is a live void setter with four caller routes and exact changed-path palette/redraw/queue order. Their second output/argument is tint amount, not transition duration.
- UID0004RD source-constructs `LightingObjectPane`, inserts it into `m_objectList`, then attaches it to the anchor. UID0004RE is the pointer-safe overlay helper used by UID0004QY `RenderMapView`; its raw out-of-line body is an exact inline twin.
- UID0004RG and UID0004RH are the paired strict-low/inclusive-high `0.60000002f` predicates gated by `m_shadowEnabled`. Existing accepted consumers establish their descriptive names.
- Compiler-only effecter allocation/EH lowering, automatic Region cleanup, security cookies, vtable dispatch, by-value copy mechanics, and source inlining are not handwritten. Zero raw-start xrefs for UID0004RB/UID0004RE/UID0004RF cap lexical/liveness confidence but do not make coherent authored policy non-source.
- Historical broad one-emitter, `m_clipRegion` restoration, duration coefficients, embedded overlay, generic attachment/equipment names, and generic shadow predicates are retained only as superseded search context.

## UID00037V Render-View Source Surface

- [UID:00037V][0x00509470-0x0050a4fd.MapPaneRenderViewCore](by-memory/0x00509470-0x0050a4fd.MapPaneRenderViewCore.md) is now a `92/94` non-emitting mixed split index rather than one MapPane method. Its exact children are [UID:0004QW][0x00509470-0x00509478.MapPaneGetCurrentMapId](by-memory/0x00509470-0x00509478.MapPaneGetCurrentMapId.md), [UID:0004QX][0x00509480-0x005094ae.SharedMusicPlaybackTail](by-memory/0x00509480-0x005094ae.SharedMusicPlaybackTail.md), and [UID:0004QY][0x005094b0-0x0050a4fd.MapPaneRenderMapView](by-memory/0x005094b0-0x0050a4fd.MapPaneRenderMapView.md). Internal `[0x00509478,0x00509480)` and `[0x005094ae,0x005094b0)` spans are ignored `cc` alignment.
- UID0004QW is exact source for `unsigned short MapPane::GetCurrentMapId() const`: eight bytes `0f b7 81 f2 03 00 00 c3`, one block, no callees, and six direct code consumers over `m_mapId` at `+0x3f2`. Historical `GetMapId` remains a viable stripped-name alias but does not block the accepted source shape.
- UID0004QY is exact source for `void MapPane::RenderMapView()`: `0x104d` bytes, 191 blocks, 39 direct callee targets, and three calls from successor paint. It preserves flash and waiting-state early exits; blindness mode; shadow-option, palette, day/night and attachment-light processing; cached-surface bounds/blit; living prepass; ObjectList item/flying/row passes; special static and late-effect passes; object-info/balloon/hit-bar/damage overlays; the final clip query; and automatic Region/EH cleanup as compiler lowering rather than handwritten ABI source.
- UID0004QX is executable but not MapPane source. MusicControlDialog and SoundManager predecessor contexts branch into one compiler-folded config/music-zone suffix and shared return; no call, pointer, table, vtable, or independent declaration route supports a third helper. It stays ownerless/non-emitting while the two complete source contexts retain the policy.
- Render-field semantics are represented directly in the complete class block. Byte `+0x3f0` is `m_waitingForLocalPlayerStatus`: initialization/transition producers set it, local-player status creation clears it, and render/weather paths early-out while set. `+0x3e0` remains compatibility-spelled `m_selectionOverlay` but is an `IntAlphaSurface *` used as the day/night shadow/light overlay. `+0x3dc` is target day/night brightness, `+0x418` is `m_localPlayerObjectPane`, `+0x424` is ObjectList, `+0x428` is embedded viewport GrafPort, and `+0x4c8` is `m_mapFlashColor`.
- Cumulative nesting is parent `-4`, getter `+4`, shared tail `0`, render `0`, successor UID00037W `-4`, and independent ProfileStorage UID0001AV `0`. This is validator address-order indentation, not child count.
- Historical whole-range MapPane ownership, raw helper/table treatment, 124-callee count, deferred source body, `m_hasRenderableMap`, and generic overlay-only wording are superseded. The complete parent/children preserve exact hashes, callers/callees, negative evidence, source/no-source placement, lexical caps, and rejected compiler-shaped C++.

## UID00037X Interaction And Map-Change Source Surface

- UID00037X is now a `90/92` non-emitting split index. Exact source-bearing MapPane children, in address order, are UID0004Q8 `GetObjectScreenPoint(ObjectPane *, MapPoint *) const`, UID0004Q9 `FlashMapColor(int)`, UID0004QA `FinishVisibleObjectRefresh()`, UID0004QB `InteractWithObject(LivingObjectPane *)`, UID0004QC `CollectMovementTargetObjectIds(std::vector<unsigned int> &) const`, UID0004QD `SortMovementTargetObjectIdsByDistance(std::vector<unsigned int> &) const`, and UID0004QE `ChangeMap(unsigned short, short, short, unsigned char, unsigned char, int)`.
- `GetObjectScreenPoint` converts ObjectPane map coordinates with `m_tileOriginY/m_tileOriginX`, `g_mapTilePixelHeight/g_mapTilePixelWidth`, and LivingObjectPane movement interpolation divided by `4 * g_movementSubstepScale`. Binary-proven direct ObjectPane/LivingObjectPane field access is represented by MapPane friendship in their complete declarations.
- `FlashMapColor` uses dword `m_mapFlashColor` at `+0x4c8`, two whole-pane invalidation/presentation passes, and `Sleep(100)`. Its unique independent thiscall body and UID0003TO inline opcode-0x29 analog prove retained source even though no inbound entry route is recovered.
- `FinishVisibleObjectRefresh` calls `m_objectList->RemoveMarkedVisibleObjects()` and clears bool `m_visibleObjectRefreshPending` at `+0x4cd`. UID0001AW produces the pending state; UID0001B1 contains the same completion inline; UID0003TK independently consumes/clears it. Its unique independent thiscall body remains source-bearing despite absent inbound entry routes.
- `InteractWithObject` uses bool `m_objectInteractionTimerActive` at `+0x3f1`, ObjectStatusBlob HumanObject, value-first packet writers, six-byte opcode `0x43`/subtype `0x01`/big-endian ID, and timer ID 5/4000. UID0003ZS clears the gate. Nonhuman targets send immediately without the gate.
- Collector state includes map transition byte `m_mapTransitionState` at `+0x40c`, weather bytes/words at `+0x40d/+0x410/+0x414`, object-list pointer `+0x424`, and selected-target external `s_selectObjectTargetId`. It preserves the stale-selected-ID null edge when adjacency expansion is enabled. The sorter performs unchecked in-place squared-distance selection sort with stable equal-distance ties.
- `ChangeMap` conditionally saves cache and resets music only when map ID differs; always detaches/deletes/recreates ObjectList and updates dimensions/transition/id/weather; conditionally loads cache; then draws and invalidates in exact order. Compiler EH/new/delete lowering remains excluded.
- Four exact internal `cc` intervals are ignored; collector-owned NOP/jump-table bytes remain attached. The first child opens cumulative nesting `+4`, later children use `0`, and following UID00037Y closes with `-4`.
- No original private symbols survive for several names, and FlashMapColor/FinishVisibleObjectRefresh lack recovered inbound routes. Those facts cap lexical/liveness confidence only. Historical aggregate, raw/no-code, path-build/compact, generic timer-state, and file-static selected-ID assumptions are superseded.
- This broad class is `93/94`, owner/emitter UID0000L3, reconstructable true, and emits the complete declaration union rather than a target-only shell. Exact children remain the sole definition owners.

## UID0003TO Object Move Effect Packet Source Surface

- [UID:0003TO][0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket](by-memory/0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket.md) is the source-ready `bool MapPane::HandleObjectMoveEffectPacket(const unsigned char *packet)` child at `92/94`. The existing declaration in the complete class formal is exact and remains byte-for-byte unchanged; UID0003TO owns the sole method definition in `NexusTK/map/MapPane.cpp`.
- The child is exactly `[0x00511c90,0x00511dae)`, 286 bytes, with dispatcher opcode-`0x29` caller `0x005082f6` and UID0003TQ action-handler caller `0x00512c04`. It reads a BE32 unsigned object id at packet `+1`, signed BE16 descriptor/action at `+5/+7`, and conditionally zero-extended BE16 column/row at `+9/+11`; no path reads byte `0` and no packet/null/length checks are added.
- Descriptor `134` reaches the exact constant-143 map-flash policy inline. Unique UID0004Q9 retains `MapPane::FlashMapColor(int)` as an independent body with no inbound xref; `FlashMapColor(143)` is the strongest human source call and compiler inlining explains the target's absent call edge. `m_mapFlashColor`, inherited whole-pane invalidation, `g_pScreenPane` presentation, and `Sleep` retain their established providers.
- Only descriptors `160..162` set `renderAfterLivingObjects`. Null `m_objectList` suppresses both routes; zero object id calls `RequestCoordinateEffect`, while nonzero id uses `FindByObjectId` as a truth gate before `RequestObjectEffect`, whose intentional internal lookup remains repeated. Lookup miss is a no-op and every child path returns `true`.
- Packet-buffer readers, ObjectList, UID0003TE/UID000232 effect helpers, Surface presentation, and Win32 Sleep remain dependency owners. The target adds no field or declaration, partial class shell, packet struct, raw offset, helper body, vtable syntax, check, clamp, deduplicated lookup, or compiler lowering to the class formal.
- Historical UID0003TO `86/90`, unsigned-descriptor, blank-C++, source-parallel-only flash, and unresolved packet-declaration statements are superseded. This broad class remains `93/94`, retains its exact `0x910` layout and complete B003/B004/B005/B011 declaration/fact union, and changes no unrelated child route or source body.

## UID0003TK Effect Map-State Packet Source Surface

- [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md) is the source-ready `bool MapPane::HandleEffectMapStatePacket(const unsigned char *packet)` child at `92/94`. The existing declaration in the complete class formal is exact and remains byte-for-byte unchanged; UID0003TK owns the sole method definition.
- The child is reached only from `MapPane::HandlePacket` opcode `0x15` at `0x00507f10`, and that dispatcher case directly returns its bool result. The exact body is `[0x005104d0,0x00510958)`, 1,160 bytes, 304 instructions, 44 blocks, complexity 22, with external nine/eight-byte `cc` alignment.
- Packet order after opcode is unsigned map id, signed short map width/height, flags, transition byte, one-byte-counted ANSI map name, packed day/night word, and final target-selection byte. The handler trusts `13+nameLength` bytes, converts the copied ANSI name through ACP to a wide local but never consumes it, and uses flags `0x01/0x02/0x08`; bit `0x04` is unused.
- `m_mapRuntimeMode` is set before the rebuild predicate. `m_visibleObjectRefreshPending` or changed map id/dimensions clears the pending byte and rebuilds ObjectList state. Map-id change alone saves the old cache, conditionally resets music, and loads the replacement cache. Existing ObjectList detaches `m_localPlayerObjectPane` before delete; replacement uses `m_visibleTileColumns/m_visibleTileRows`.
- Exact rebuild order is map height, inverted `m_mapTransitionState`, map id, map width, `SetMapState(m_weatherType, flags & 1)`, conditional load, `DrawVisibleTiles`, then inherited invalidation. `m_movementStatusTagDisabled` is set only after the branch from packet flag `0x02`; true disables optional movement-history/status tagging for that map.
- Packed day/night quotient/remainder updates `m_dayNightBrightnessScale` and `m_dayNightBrightnessBias`; UID00027Q supplies the current-hour brightness. The result is clamped and `m_dayNightTintCurveScale * delta^2 + m_dayNightTintCurveBase` produces tint amount, not duration, for `SetDayNightFadeTarget`.
- Auxiliary-pane removal/unregistration/delete and active-layer detach/delete share the single `m_auxiliaryPane` guard. The method then sets `m_waitingForLocalPlayerStatus`, preserves two separately rechecked EPF queued-state branches that clear `m_rightButtonTrackingActive` then `m_leftButtonTrackingActive`, unconditionally writes `g_pConfig->m_targetSelectionSuppressed`, and returns true. Historical deferred-primary/deferred-secondary surface names are rejected aliases for these exact tracking bytes.
- Current declarations already supply MapPane fields/methods and Config/ObjectList/SoundManager/ScreenPane/Pane/MemoryMan dependencies. Those providers retain their own ownership; no support declaration, second class shell, packet type page, or class score/route change is required.
- Exact unsafe/negative behavior is preserved: no packet-size/global-null validation, no post-conversion name use, no bit-`0x04` effect, no independent active-layer guard, no same-id save/music/load, no rollback, and an unconditional final Config write. SEH/cookie, allocator, STL byte-reader, vtable, scalar-delete, and raw helper labels remain compiler evidence rather than handwritten source.
- Historical `MapPaneDayNightPacketHandler`, `m_hasRenderableMap`, generic `+0x4cd` dirty names, duration terminology, and blank-body blocker text are superseded for UID0003TK. Private packet-view/local spellings remain inferred and cap lexical confidence only.

## UID000426 Movement-Status Tag Policy Contract - 2026-07-31

- [UID:000426][0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag](by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md) is the exact 11-byte `bool MapPane::AllowsMovementStatusTag() const` predicate. The existing declaration remains singular in this class H block.
- The method returns `!m_movementStatusTagDisabled`. Constructor [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](by-memory/0x00504110-0x00504521.MapPaneInitialize.md) initializes the byte true through the packed `0x00010001` store, and opcode-`0x15` packet bit `0x02` is the sole runtime writer.
- `g_pConfig->m_mapMovementStatusOption` is the global request for optional movement/status tagging; the per-map bool is an independent veto. UserPane send/reply paths and three generations of status panes use the conjunction for bit-7 movement-history/status semantics. BackGroundPane and ConnStatusPane are additional consumers, not owners.
- The method is not day/night or collision logic. Historical `IsDayMode`, `IsMovementGateClear`, `m_movementGate`, and `m_viewportMoveGate` aliases are retained only as disproved history.
- Supervisor catalog entry `0381` applied and read back the accepted IDA state at dated saved-IDB checkpoint SHA256 `5F2679A7C6BFF2CD3E91FE59BDCBD298C1A233EB7988D838C34C05508FC79A21`, `143,192,720` bytes, saved `2026-07-31T05:57:03.6144571-04:00`. The existing `MapPane_AllowsMovementStatusTag` name and `bool __thiscall(const MapPane *this)` declaration were already canonical and remained unchanged.
- The applied function-regular comment is exactly: `Source: bool MapPane::AllowsMovementStatusTag() const; returns true when effect-map-state packet flag 0x02 is clear. Callers combine it with Config::m_mapMovementStatusOption to gate movement-history/status high-bit tags and related status UI handling.` Function-repeatable, address-regular, and address-repeatable comments remain absent.
- Catalog0381 materialized the source-facing UDT member as `+0x40e bool m_movementStatusTagDisabled`. Its width remains one byte, `MapPane` remains size `0x910`, and the exact protected neighbors remain `+0x40c unsigned __int8 m_mapTransitionState`, `+0x40d unsigned __int8 m_weatherMode`, and `+0x40f unsigned __int8 m_dayNightHour`; no overlapping member, collision, range expansion, or layout displacement was introduced.
- Unrelated catalog entry `0382` advanced the shared saved IDB to SHA256 `B7CC899DA786D8D49AE13525B844AA85CCF3C21C73D00DB2AE337FF838058277`, `143,192,751` bytes, saved `2026-07-31T06:21:13.3464834-04:00`. B008's bounded read-only reread found the function identity, exact accepted comment, `+0x40e` bool member, one-byte width, `0x910` class size, and all three neighbors unchanged. The dated catalog0381 transaction remains the action authority; catalog0382 supplies current no-drift evidence rather than a second action.

## Compressed Map Cache Source-Quality Synchronization

- [UID:0002QJ][0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile](by-memory/0x00504b90-0x00504df1.MapPaneLoadCompressedMapFile.md) is the source-ready `MapPane::LoadCompressedMapFile(unsigned short mapId, int unusedLoadOption)` method. Its second integer is present in both live caller ABIs but is not read by the body; the source reconstruction retains it rather than deleting or inventing semantics for it. The method belongs to `NexusTK/map/MapPane.cpp` and uses the existing `MapPane` declaration route rather than a partial replacement class declaration.
- [UID:0004PZ][0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer](by-memory/0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer.md) is the exact private `MapPane::AllocateTileBuffer()` child called only at machine sites `0x00504c8b`, `0x00504d3e`, and `0x00504dc5` by UID0002QJ. It reads canonical fields `m_mapWidth` and `m_mapHeight`, allocates `m_mapWidth * m_mapHeight` six-byte [UID:0004HP][MapPaneTileRecord](by-type/by-struct/MapPaneTileRecord.md) rows into `m_tileBuffer`, and zeroes the full allocation. It never frees pre-existing storage, so Reset/Reallocate/Replace spellings are rejected.
- The class contract uses canonical fields `m_mapWidth` at `+0x3f4`, `m_mapHeight` at `+0x3f6`, and `m_tileBuffer` at `+0x3f8`. Later UID0003TL aliases `m_mapWidthTiles`, `m_mapHeightTiles`, and `m_mapTileRecords` are superseded source-shape assumptions, not concurrent field names. The six-byte tile record and the load body require MapPaneTileRecord, StdioFile, path/stat support, wide path formatting, and bundled zlib `uncompress` dependencies; these dependencies do not transfer source ownership from MapPane.
- The loader builds `Documents\NexusTK\Maps\TK%06d.cmp`, checks the directory and file path, reads the `CMAP` signature plus 16-bit width/height through StdioFile, and inflates exactly `6 * m_mapWidth * m_mapHeight` bytes. Documents/directory failures preserve existing receiver storage. Cache miss, bad signature, or dimension mismatch flows allocate zeroed tile storage. File open may throw; read results and zlib status are intentionally ignored. These distinctions reject the older blanket claim that every failure resets storage.
- [UID:0002QK][0x00504e00-0x00505075.MapPaneSaveCompressedMapFile](by-memory/0x00504e00-0x00505075.MapPaneSaveCompressedMapFile.md) is now the source-ready no-argument `void MapPane::SaveCompressedMapFile()` method at `0x00504e00`, exact size `0x275`, target SHA-256 `595B2258168B19996F00835595DA04821ED0E043FB58082639C605D8FAEAF1BD`. Its four exact calls are cleanup `0x0050458b`, exit-to-menu `0x0050483e`, map-id-change `0x0050bbe7`, and packet map-id-change `0x00510671`; every caller ignores EAX, rejecting IDA's provisional `FILE *` return residue.
- Save uses fixed-260 path formatting, `SHGetFolderPathW`, PlatformApi `g_pfnCreateDirectoryW`, direct `g_pfnWideOpenFile` / `_wfopen` with `L"wb"`, `_fwrite`, `_fclose`, `_AUTOBUF<unsigned char>`, and lowercase zlib `compress`. It writes exactly four `CMAP` bytes, two 16-bit dimensions, then compressed `sizeof(MapPaneTileRecord) * m_mapWidth * m_mapHeight` bytes. The output capacity is explicit `rawBytes * 11 / 10 + 12`, not `compressBound`; `compress` mutates the payload length and its status plus all write/close results are ignored.
- Save's state contract is exact and asymmetric. Null `m_tileBuffer` skips file work and directly calls `g_pMonsterImageLib->ClearLoadedData()` without a null-global guard. Documents, non-`ERROR_ALREADY_EXISTS` directory, and open failures retain receiver tile storage and skip monster clear. After a stream opens, every ordinary CRT/zlib result reaches `m_tileBuffer` free/null, automatic compressed-buffer release, then MonsterImageLib clear, so partial/truncated files can remain and no rollback/retry exists. If AUTOBUF `Resize` allocation throws, compiler unwind releases only the automatic compressed buffer; the raw stream remains open, receiver tile storage remains intact, and monster clear is skipped.
- Paired load remains materially distinct: UID0002QJ uses StdioFile, `PathExistsViaStat`, lowercase `uncompress`, and UID0004PZ allocation/zeroing. Save uses direct CRT/compress and disposal/invalidation. MapPane owns both integration methods and canonical fields; MapPaneTileRecord, StdioFile, AUTOBUF, WideApi/PlatformApi, zlib, CMAP storage, CRT, and MonsterImageLib remain dependency owners rather than owners of either MapPane body.
- Source order on the MapPane route is destructor/teardown callers, UID0002QJ at `0x00504b90`, UID0002QK at `0x00504e00`, later map helpers, exact allocation child UID0004PZ at `0x0050e2a0`, then the existing object-effect child at `0x0050e320`. UID0002QK's lexical AUTOBUF scope expresses the ordinary tile-free/local-release/monster-clear order and exception cleanup; explicit SEH, security cookies, CxxFrameHandler3, allocator/free thunks, destructor calls, and raw return mechanics are compiler consequences and must not appear as class declarations or handwritten method statements.
- The historical description of UID0002QK as a paired blank-formal target awaiting AUTOBUF, return, failure, and helper declarations is superseded by its direct source-quality audit and formal child body. StdioFile-save rewriting, uppercase `Compress`, newer field aliases, four-byte tile rows, added headers/status gates/rollback/pre-open disposal/null-global guard, and compiler-shaped source remain rejected. The complete UID00007Q class emitter now preserves the full accepted method/field surface while UID0002QK remains the sole save-body definition owner.

## ObjectStatusBlob dependency synchronization

- MapPane calls full child UID0004LL at `0x0050fba3/0x00513354` and partial child UID0004LM at `0x0050fbbc/0x0051336d`; tagged child UID0004LK is the shared variable-length API used by other consumers. Return lengths are 43, 5, and tagged 44/4/0.
- The complete 68-byte dependency preserves MapPane's living/item aliases while adding all exact equipment, context, action/display, riding, color, invisibility/face-shape, and padding fields from UID00009S. RidableAnimals and HAIRCOL evidence supersedes title/profile/generic-remap summaries.
- MapPane handlers and object-pane creation consume ObjectStatusBlob; semantic/source ownership remains UID00009S/UID0000M6. No MapPane declaration/body, score, owner, vtable, inheritance, or file route changes in this synchronization.


## Status

- Confidence: strong for class responsibility and coordinate/movement-helper ownership, medium-high for final source split.
- Likely source file: [UID:0000L3][MapPane](by-file/MapPane.md)
- Autogen parent: [UID:0000L3][MapPane](by-file/MapPane.md). UID00007Q now emits the complete source-era class declaration at position `0`; exact method bodies continue to emit only from by-memory children through the `MapPane.cpp` file route. Field, packet-payload, and descriptor uncertainties are closed with the strongest current type/offset evidence and bounded lexical caps rather than deferred.
- Current recovered file: `source-3/simroot_v2/class_MapPane.cpp`
- Current coverage: 124 active methods over many aggregate ranges.
- Evidence basis: Wave3 metadata and targeted IDA MCP checks on 2026-05-23 through 2026-05-25.
- Key global: [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md).
- Coordinate/movement global: [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md), exact storage [UID:00027F][0x0066da96-0x0066da97.g_movementSubstepScale](by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md).

## Class Purpose

`MapPane` is the live game-world pane. It bridges server-driven map/object packets to the rendered world view, owns tile buffers and object indexes, converts between tile and screen coordinates, processes movement and targeting input, manages weather/day-night effects, and triggers map/minimap/world-map transitions.

## Major Method Families

| Family | Representative addresses | Role |
| --- | --- | --- |
| Lifecycle and message routing | `0x00504530`, `0x005046d0`, `0x005047f0`, `0x00504b70` | Cleanup, queued map messages, logout/menu transition, and integration messages. |
| Map persistence | `0x00504b90`, `0x00504e00` | Load/save compressed `.cmp` map files below the user's `Documents/NexusTK/Maps` folder. |
| Coordinates and visible bounds | `0x00505080-0x0050571d` | Tile offsets, world/screen conversion, visible bounds, map-edge clipping, [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md), and [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md) movement substep scaling. |
| Object ownership and indexing | `0x00505940-0x0050637a`, `0x00506970-0x00506cdc` | Adds, finds, updates, and removes tracked living/static/item object panes. |
| Input and timers | `0x00506df0`, [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md), `0x00507150`, [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md), [UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md), [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md) | Keyboard commands, mouse hover/click/drag interactions, bounds-checked target-selection hit testing through `MapPane::HitTestObjectAtPoint(y, x)`, secondary-vtable notify/message handling, adjusted TimerHandler-facet movement/path/action timers, effect-object idle timer setup, and auto-attack polling. |
| Packet dispatch | `0x00507c90`, `0x0050fb00-0x00513da0` | Main map packet switch and packet-specific object/weather/status/action handlers. B011 session `b001-0001I5` reconfirms [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md) as opcode case `0x06`, direct `MapPane` receiver route, map/resource string update, tile-buffer mutation, dirty redraw, and static-object reconciliation. |
| Rendering | `0x005094b0`, `0x0050a500`, [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md), `0x0050d840`, `0x0050d8e0`, `0x0050dd60` | Render map view, paint dirty areas, redraw visible cached tiles, draw cached tiles, and render map objects. |
| Weather and lighting | `0x00503e80`, `0x00503e90`, `0x00503ef0`, `0x005040a0`, `0x0050a8b0`, `0x0050db50`, retained raw duplicate `0x00510400` | Runtime screen-effecter list checks/configuration/cleanup, weather-layer construction, day-night state, lighting effects, and weather packets. MapPane owns orchestration and the `+0xf8/+0xfc/+0x100` effect-list fields; runtime `ScreenEffecter` classes belong with Effects; weather overlay pane implementations belong with the WeatherLayerPane/Raining/Snowing/Swallow map-weather family. `0x00510400` is raw duplicate evidence for dispatcher opcode `0x20`, not an independent migrated method. |
| Map transition and world-map creation | `0x0050bbb0`, `0x0050feb0`, `0x00511db0` | Map changes, server transfer, and construction of world-map UI from object-create packet data. |

## Object Effect Descriptor Dispatch

[UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) is the public `RequestObjectEffect` member declared in the managed class block. It accepts object id, descriptor id, `timerAction`, and `renderAfterLivingObjects`; looks up the object through `m_objectList`; converts the non-null result to `LivingObjectPane *`; copies an exact 52-byte [UID:0001U8][EffectInfo](by-type/by-struct/EffectInfo.md); processes the descriptor secondary sequence before primary; reuses matching looping [UID:000049][EffectObjectPane](by-class/EffectObjectPane.md) children; creates missing panes through [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md); and applies reuse actions through [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md).

[UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md) is the private `RequestCoordinateEffect` member declared in the managed block. It rejects coordinates outside clamped half-open visible bounds, copies one 52-byte EffectInfo, processes secondary before primary, reverse-scans the ObjectList bucket selected by map row, reuses the first same-column/same-effect-id looping pane, or creates a null-target pane with sequence 0/1. Negative descriptor ranges suppress reuse scanning but not creation; the source preserves pointer-slot dereferences without invented null checks or a redundant row comparison.

## Existing EffectObjectPane Timer-Action Source Contract

[UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md) is the source-ready private `ApplyEffectObjectPaneTimerAction` member already declared in the complete managed class block. Exactly four calls come from UID000232 and UID0003TE, and each caller reloads the `MapPane *` receiver in `ECX`; the callee's optimized lack of a `this` read does not make it a free/static helper.

The helper receives an existing reusable `EffectObjectPane *` plus signed `int timerAction`. Null returns, `-1` performs ordinary source-level `delete`, zero is a no-op, and `-2` cancels TimerHandler event 2. Every other signed action, including values below `-2`, enters the replacement path when inferred `EffectObjectPane::m_timerExtensionLocked` is false. It queries event 2's due tick, preserves zero-on-miss and the signed unscaled `timerAction <= dueTick - currentTick` comparison, then cancels before scheduling event 2 with exact delay `1000 * timerAction` and payload `0,0`.

The source uses the typed inherited `TimerHandler *` conversion, not raw `+0xa4` adjustment. `m_timerExtensionLocked +0x14e` is constructor-zeroed and has no observed nonzero direct writer in the bounded family; its spelling is inferred from polarity. It remains distinct from `m_looping +0x14c` and `m_renderAfterLivingObjects +0x14d`. TimerMgr and EffectObjectPane remain dependency/state owners while MapPane owns the reuse action policy. The source order remains UID0003TE, UID0003TF, six-byte alignment, then UID0003TG. Historical generic-callback, positive-only, raw-guard, blank-body, free/static, and behavior-changing unit-fix interpretations are superseded.

The MapRect declaration boundary is now source-complete: canonical `RectBounds` is forward-declared and `typedef RectBounds MapRect;` preserves the existing MapPane source name without creating a duplicate layout or raw cast. `RequestCoordinateEffect` uses `PointInRect(mapRow, mapColumn, &visibleBounds)`, matching the established y/x half-open rectangle helper contract.

[UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md) is the private `CreateEffectObjectPane` member declared in the same managed block. Its exact source contract is `LivingObjectPane *target`, `mapRow`, `mapColumn`, by-value `EffectInfo`, `timerAction`, `sequenceIndex`, and `renderAfterLivingObjects`; the explicit `retn 0x4c` proves the 52-byte by-value descriptor ABI. All four call sites and the EffectObjectPane-to-ObjectPane constructor forwarding prove that row precedes column at this helper boundary. The exact function range is `[0x0050ea30,0x0050eb8a)`, 346 bytes, full-byte SHA256 `EC68940B3FC220422D1D9E592150F4AA49B110A687C809A07EF0935E039E803B`, 22 blocks, complexity 9, and no strings.

Exactly four calls reach the helper: UID000232 passes a non-null `LivingObjectPane *` at `0x0050e3ed` and `0x0050e47e`; [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md) passes null at `0x0050e945` and `0x0050e9e3`. Secondary sequence `0` registers through `LivingObjectPane::AddSecondaryEffectObjectPane`; primary sequence `1` registers through `AddPrimaryEffectObjectPane`; other selector values enter neither target list. Every created pane enters MapPane `m_objectList`, starts event 1, conditionally receives event 2, optionally updates position for a non-null target, then supplies bounds for invalidation.

`timerAction == -1` suppresses creation; positive values become milliseconds; `-2` suppresses only event 2. Event 2 additionally requires both selected descriptor ranges to be nonnegative. Constructor evidence fixes the final boolean as `renderAfterLivingObjects` stored at EffectObjectPane `+0x14d`, not a compact flag; complementary render passes consume it before versus after living objects.

Source uses ordinary `new EffectObjectPane`. Pool allocation, vptr/cookie/EH/failure paths, TimerHandler adjusted-this arithmetic, and virtual-slot syntax are compiler lowering rather than handwritten MapPane source. The class owner/emitter and file route remain UID00007Q -> UID0000L3 `NexusTK/map/MapPane.cpp`, with UID0003TF after UID0003TE and before UID0003TG and no explicit position.

Historical/superseded assumptions are retained for audit only: `ObjectPane *target`, transposed `mapColumn, mapRow` create-helper declarations, `mapX/mapY`, `compactFlag`, generic type-2/type-4 insertion labels, `GetEffectBounds`, blank UID0003TE C++, and a helper-local-body blocker. B008's alternate `ApplyObjectEffect` name and the coordinate sibling's `RequestPositionEffect` alternative are rejected because `Request*Effect` covers lookup, reuse, creation, cancellation, timer replacement, and no-op behavior while `Coordinate` distinguishes map row/column from screen and pane positions. No vector substitution, new source file, EffectObjectPane ownership transfer, or compiler-only target disposition is supported.

## Key Relationships

- Owns an [UID:00009Q][ObjectList](by-class/ObjectList.md) at the `MapPane + 0x424` family for row-bucket, visible-object, render-layer, and cleanup lookups. [UID:0001D2][0x00532530-0x0053272e.ObjectListAccessorMethods](by-memory/0x00532530-0x0053272e.ObjectListAccessorMethods.md) documents the exact accessor child; [UID:00007R][MapPaneSpatialIndex](by-class/MapPaneSpatialIndex.md) remains only a generated compatibility alias.
- UID00037Q implementation splits the former `0x00506970-0x00506cdd` object lookup/traversal family into exact MapPane children. [UID:00037Q][0x00506970-0x00506cdd.MapPaneObjectLookupHelpers](by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md) is now only a non-emitting split/container; exact children own `FindObjectPaneById`, `UpdateObjectPaneScreenBounds`, six target-selection traversal wrappers, and `RemoveObjectPaneIfPresent`. The traversal wrappers are MapPane methods because their receiver and callers are MapPane/target-selection paths, but ObjectList owns `FindByObjectId`, `GetTypedObjectKey`, `MoveKeyTo...`, `ResolveObjectListKey`, and `RemoveObjectPane`.
- The object lookup/traversal child set covers `0x00506970-0x0050697f`, `0x00506980-0x00506ad4`, `0x00506ae0-0x00506b2a`, `0x00506b30-0x00506b7a`, `0x00506b80-0x00506bca`, `0x00506bd0-0x00506c1a`, `0x00506c20-0x00506c6d`, `0x00506c70-0x00506cbd`, and `0x00506cc0-0x00506cdd`, with internal alignment padding recorded in [UID:0000VN][-ignored](by-memory/-ignored.md). This supports `m_objectList` at `+0x424` as the class field name and rejects raw decompiler forms such as `this[265]` or bare `[+0x424]` indexing for source C++.
- Consumes [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md) for map-pane setup and coordinate scaling. These are globals at `0x0066da9c` / `0x0066daa0`, not MapPane fields.
- [UID:00041X][0x00505130-0x0050516a.MapPaneMapToScreenCoords](by-memory/0x00505130-0x0050516a.MapPaneMapToScreenCoords.md) is the source-ready `MapPane::MapToScreenCoords(MapPoint *point) const` child in this coordinate surface. B006 MCP session `60724697` confirms modeled `sub_505130`, exact `0x3a` / 58-byte range, unique bytes, clean `0xcc` alignment, no callees, ten direct code xrefs from MapPane/object/attachment/living-object consumers, zero data/pointer route, reads of `+0x3fc/+0x400` tile-origin fields and `g_mapTilePixelWidth/g_mapTilePixelHeight`, and caller-window proof that the decompiler `int` return is unused.
- [UID:000427][0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll](by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md) is the source-ready `MapPane::ApplyMovementSubstepScroll(unsigned char direction)` child in the same coordinate/movement surface. B012 MCP session `60724697` confirms exact size `0x65` / 101 bytes, prototype `char __thiscall(_DWORD *this, char)`, one-block body, direct calls from `sub_5A83B0` at `0x005a8524` and `0x005a8589`, callees `DirectionToTileOffset` and inferred shifted-region invalidation helper `0x005549d0`, clean `0xcc` padding before successor `0x00505650`, and field order `+0xb0` X/column pixel origin, `+0xac` Y/row pixel origin. UserPane/LivingObjectPane movement paths are consumers, not owners; unrelated RankingDialog UID000427 material is ignored for this MapPane target.
- [UID:000428][0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds](by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md) is the source-ready `MapPane::GetAdjacentVisibleTileBounds(unsigned char direction, MapRect *outBounds) const` child in this coordinate/movement surface at `90/92`. B014 MCP session `60724697` confirms modeled `sub_505650` size `0xce`, code range `0x00505650-0x0050571e`, attached switch material `0x0050571e-0x00505730`, direct callers `0x005a3235` and `0x005ad390`, callee flow through clamped visible bounds / `SetRect` / intersection / checksum helper, `+0x3f4/+0x3f6` map width/height reads, optional 16-byte output copy, no recovered local `MapPane`/`MapRect` UDT, and local PE no-extra-route proof. The attached bytes are `66 90` followed by jump-table dwords `0x00505680`, `0x005056a7`, `0x0050568d`, and `0x0050569a`; successor [UID:000429][0x00505730-0x00505731.MapPaneAfterLocalPlayerWarp](by-memory/0x00505730-0x00505731.MapPaneAfterLocalPlayerWarp.md) remains separate. UserPane/LivingObjectPane caller paths are consumers, and historical RankingDialog UID000428 material is rejected for this exact MapPane target.
- [UID:000429][0x00505730-0x00505731.MapPaneAfterLocalPlayerWarp](by-memory/0x00505730-0x00505731.MapPaneAfterLocalPlayerWarp.md) is the source-ready empty `MapPane::AfterLocalPlayerWarp()` callback in the same coordinate/movement surface at `89/91`. B003 MCP session `nexustk_supervisor_20260704` confirms `0x00505730` is IDA alias `nullsub_12`, size `0x1` / one instruction, byte `C3` / `retn`, while `0x00505731` is not a function and has zero xrefs. The callback has exactly two direct code xrefs, `0x005a79f5` in the live opcode `0x04` server-warp/correction dispatcher case and `0x005ab052` in retained duplicate [UID:0003UO][0x005aaff0-0x005ab084.UserPaneHandleWarpPacket](by-memory/0x005aaff0-0x005ab084.UserPaneHandleWarpPacket.md). Both caller windows call `sub_5A5A90` / `LivingObjectPane::WarpToPosition`, load the cached `MapPane *` receiver from `[ebx+0x1340f8]`, and then call this no-op. `0x00505731-0x00505740` is `0xCC` padding before sibling [UID:00042A][0x00505740-0x00505743.MapPaneObjectCallbackNoOp](by-memory/0x00505740-0x00505743.MapPaneObjectCallbackNoOp.md); exact body signature `C3` is nonunique. UserPane/LivingObjectPane callers are consumers, raw `nullsub_12` is not a source name, and the exact original hook spelling remains inferred with `AfterLocalPlayerWarp` kept as the current project-stable spelling.
- Owns [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md) as a MapPane coordinate/movement scalar. IDA shows its exact storage byte is read by MapPane coordinate helpers and by movement consumers that call back into the MapPane direction/coordinate API.
- Owns [UID:0003ZM][0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants](by-memory/0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants.md) as file-level `MapPane.cpp` legacy map-tile remap constants, not class fields. The `0x0050c120` helper is a `MapPane` instance method because it reads `this+0x3f4/+0x3f6/+0x3f8` map dimension and tile-buffer fields and is called from MapPane movement, visible-tile, tile-draw, render, and static-object refresh helpers.
- Owns a runtime `ScreenEffecter *` pointer array at the `MapPane +0x0f8/+0x0fc/+0x100` triplet. B002's 2026-06-17 source-quality pass names the fields as high-probability `m_screenEffecterCount`, `m_screenEffecterCapacity`, and `m_screenEffecters`; the Layer render traversal uses [UID:0002I2][0x00503e90-0x00503ecd.MapPaneFindActiveEffect](by-memory/0x00503e90-0x00503ecd.MapPaneFindActiveEffect.md) / inferred `MapPane::FindActivePixelEffecter()` to select a pixel/primary `ScreenEffecter` before invoking its apply slot.
- `g_activeMapPane` at `0x0067a764` points to the live instance and is used by minimap, icon/input, targeting, spell-selection, and application cleanup paths.
- [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md) is resolved as the bounds-checked public `MapPane::HitTestObjectAtPoint(y, x)` wrapper. It tests the inherited `Pane::m_bounds` `RectBounds` at `this+0x44` through the shared `PointInRect(y, x, ...)` convention, returns zero outside the pane, and delegates inside points to the inner `0x0050c470` finder now documented as `MapPane::FindObjectAtMapPoint`. Generated BackPane wording for this address is stale provenance only.
- Dispatches map-scoped inbound opcodes tracked in [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md).
- Creates or configures [UID:0000DC][SnowingLayerPane](by-class/SnowingLayerPane.md) through weather state.
- Works with [UID:00007P][MapNamePane](by-class/MapNamePane.md) and [UID:00007S][MapRefreshDimmer](by-class/MapRefreshDimmer.md) as small map UI companions.
- Creates or routes to [UID:0000AG][PhotoPane](by-class/PhotoPane.md) for map-photo/viewer snapshots; `PhotoPane` owns the cached map/avatar image composition.
- Triggers [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md) creation from map/world-map packet handling.
- Consumes render asset libraries such as map tile, static object, effect object, item object, human, monster, and palette libraries; it should not own those render libraries.

## TimerPane Opcode 0x67 Dependency

- Live dispatcher `0x00507c90` owns opcode `0x67` packet parsing. It reads the mode from `packet+1` through the narrow-character helper and an unsigned duration/value from `packet+2` through helper `0x005754c0`.
- If [UID:0000SJ][g_pTimerPane](by-global/g_pTimerPane.md) is null and mode is `0`, MapPane returns handled without allocation. When a pane is required it allocates exactly `0x120` bytes.
- EPF asset mode constructs [UID:0004MG][0x005986e0-0x00598841.TimerPaneConstructor](by-memory/0x005986e0-0x00598841.TimerPaneConstructor.md) at `(325,15)`; legacy mode uses `(312,10)`. Display format is exactly `2 - (seconds < 3600)`, selecting five or eight glyph slots for packet-created panes.
- Mode `0` calls [UID:0004MI][0x00598880-0x005988f6.TimerPaneSetTimer](by-memory/0x00598880-0x005988f6.TimerPaneSetTimer.md) with static mode, mode `1` with count-up, mode `2` with count-down, and mode `3` calls `MarkForDeletion`. Unrecognized modes return handled without a TimerPane method call.
- Retained body `0x005140a0` repeats the same parse/create/switch sequence and returns true, but has no inbound xref and no absolute/RVA pointer hit. It remains retained MapPane-side duplicate source evidence, not a second active dispatcher and not a TimerPane method child.
- Ownership boundary is exact: MapPane owns packet bytes, mode dispatch, asset-dependent positions, allocation, and singleton create/update/delete decisions. [UID:0000F3][TimerPane](by-class/TimerPane.md) owns class layout, timer state, display update, callbacks, painting, digit rendering, singleton source, and all eight source children. Consumer calls do not transfer TimerPane source ownership.
- The TimerPane synchronization changes no TimerPane ownership or behavior. The later 2026-07-15 UID00007Q source-closure pass independently raises MapPane to `93/94` and installs the complete class formal block.

## Lifecycle Source-Quality Notes

B002's 2026-06-17 lifecycle pass resolves [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](by-memory/0x00504110-0x00504521.MapPaneInitialize.md) as the ordinary source constructor `MapPane::MapPane(int visibleTileColumns, int visibleTileRows)` and [UID:0002QF][0x00504530-0x005046c6.MapPaneCleanup](by-memory/0x00504530-0x005046c6.MapPaneCleanup.md) as the ordinary non-deleting `MapPane::~MapPane()`. Their complete first-draft blocks now use the exact inherited expressions `backPane->RegisterChangeListener(this, kMapPaneChangeTag, false)` and `g_pBackPane->UnregisterChangeListener(this, kMapPaneChangeTag, false)`. The old `95/95` blank-C++ reason is stale for those exact targets.

The constructor evidence is the base pane construction, primary and adjusted MapPane vtable installation, fixed 32-entry member-array construction at `+0x118`, embedded [UID:000160][0x004b8bf0-0x004bb8c4.GrafPort](by-memory/0x004b8bf0-0x004bb8c4.GrafPort.md)-style member construction at `+0x428`, [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md) publication, compact `SOBJ.TBL` cache loading through [UID:0000Q3][g_objectNationMap](by-global/g_objectNationMap.md) and [UID:0000Q4][g_objectRecordCount](by-global/g_objectRecordCount.md), inherited BackPane registration under tag `1735356263`, overlay allocation, and creation of the [UID:0000Q1][g_gameServerNationTable](by-global/g_gameServerNationTable.md) helper object. The two direct callers are the `InitializeMainUiGraph` construction sites.

The destructor evidence is the single [UID:0003M4][0x00514de0-0x00514e1b.MapPaneScalarDeletingDestructor](by-memory/0x00514de0-0x00514e1b.MapPaneScalarDeletingDestructor.md) caller, MapPane vtable reseating on entry, effect-list clear, listener unregister, compressed-map save, optional child/layer/list teardown, compact object-nation cache free, overlay and nation-table cleanup, [UID:0001IB][0x0057b020-0x0057b48a.SoundManagerRedbookPlayback](by-memory/0x0057b020-0x0057b48a.SoundManagerRedbookPlayback.md) `SoundManager::CloseRedbookDevice` call through [UID:00028R][0x0067a7d0-0x0067a7d4.g_pSoundManager](by-memory/0x0067a7d0-0x0067a7d4.g_pSoundManager.md), `g_activeMapPane` clear, and compiler/member/base teardown.

## Riding / Monster Scaled-RLE Render Consumer Evidence

- Retained [UID:0002Y1][0x004dc7e0-0x004dca14.RidingImageLibRenderRiding](by-memory/0x004dc7e0-0x004dca14.RidingImageLibRenderRiding.md) and modeled `MonsterImageLib::RenderMonster` both load MapPane floats `+0x3d0`, `+0x3d4`, and `+0x3d8` immediately before calling Surface callback slot 4, `g_pfnBlitScaledRleTint`.
- Fresh decompilation of both concrete slot-4 targets, compat `0x004bdcc0` and RGB565 `0x004c3a50`, establishes the argument roles: `+0x3d0` is passed as float tint amount, `+0x3d4` as float vertical scale/projection divisor, and `+0x3d8` as float horizontal projection shear. The target's centered branch instead passes fixed `1.5f` and `0.0f` for the latter two values.
- The source-facing contextual aliases used by image-library reconstruction are `m_dayNightTintAmount`, `m_newHumanProjectionDivisor`, and `m_newHumanProjectionShear`. They are aliases for the same storage documented by day/night transition evidence below, not duplicate members. Existing setter/curve evidence and original-spelling caveats remain valid.
- RidingImageLib, MonsterImageLib, and NewHumanImageLib are unrelated consumers that compile direct loads of this state with no out-of-line getter calls. Public render-state fields, or equivalently fully inlined public accessors, are therefore the strongest source access model. Protected-only access is impossible; separate friendship for each image library and invented getter calls are weaker alternatives.
- This bounded consumer evidence did not by itself resolve the complete MapPane declaration. The 2026-07-15 source-closure pass supersedes that evidence-time limitation: UID00007Q is now `93/94`, retains UID0000L3 ownership/emission and reconstructable state, and emits the full class formal block.

Field glossary carried forward by the lifecycle pass:

| Offset/family | Source-facing name | Confidence / notes |
| --- | --- | --- |
| inherited `Pane +0x44` | `m_bounds` | strong; 16-byte `RectBounds` inherited from Pane with `left/top/right/bottom`. [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md) passes this address to the shared point predicate as `PointInRect(y, x, &m_bounds)`, preserving the current RectBounds `y, x` source/binary argument order. |
| `+0xf8`, `+0xfc`, `+0x100` | `m_screenEffecterCount`, `m_screenEffecterCapacity`, `m_screenEffecters` | high; shared by effect-list configure/find/reset/clear pages. |
| `+0x118` | `Motion m_deferredMotionRecords[32]` | high; constructor/destructor establish 32 complete `0x14` values, and [UID:0002QG][0x005046d0-0x005047e8.MapPaneQueuedMotionMessage](by-memory/0x005046d0-0x005047e8.MapPaneQueuedMotionMessage.md) appends at `+0x118 + 0x14 * count`. Historical queue/layer aliases are superseded. |
| `+0x398`, `+0x39c` | `m_deferredMotionRecordCount`, `m_deferMotionMessages` | high-probability queue count and deferred-motion active flag used by [UID:0002QG][0x005046d0-0x005047e8.MapPaneQueuedMotionMessage](by-memory/0x005046d0-0x005047e8.MapPaneQueuedMotionMessage.md). |
| `+0x39d` | `m_queuedMapStateRefresh` | Canonical queued movement/map-state timer flag from [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md), [UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md), raw queue children [UID:00042E][0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6](by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md) / [UID:00042G][0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8](by-memory/0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8.md), and modeled clearer [UID:00042F][0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh](by-memory/0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh.md). The raw helpers set it before scheduling timer ids 6/8; the callback and clearer clear it before canceling those timers. Historical `m_movementTimerQueued` wording is a superseded descriptive alias, not a second current field. |
| `+0x39e` | `m_pendingActionPoll` | Canonical bool pending-action-poll flag used by timer event `7` in [UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md), raw queue child [UID:00042H][0x00505da0-0x00505dd2.MapPaneQueueActionPollTimer](by-memory/0x00505da0-0x00505dd2.MapPaneQueueActionPollTimer.md), and modeled clearer [UID:00042I][0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll](by-memory/0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll.md). While set and `GetAsyncKeyState(VK_LBUTTON)` remains active, event `7` calls `g_pUserPane->TryPerformAction()` and reschedules itself at `500` ms; release clears the flag and cancels event `7`. Historical `m_leftButtonActionPending` is a superseded descriptive alias only. |
| `+0x3e0` | `IntAlphaSurface *m_selectionOverlay` | strong pointer type from allocation/deletion and UID0004RE dereferences; the compatibility spelling is retained, but embedded-object and selection-only interpretations are superseded. |
| `+0x3b8`, `+0x3c8`, `+0x3cc`, `+0x3d0`, `+0x3d4`, `+0x3d8`, `+0x3dc`, `+0x3e4`, `+0x3e8`, `+0x40f` | `m_currentDayNightBrightness`, `m_dayNightTintCurveScale`, `m_dayNightTintCurveBase`, `m_dayNightTintAmount` (`+0x3d0`), `m_newHumanProjectionDivisor` (`+0x3d4`), `m_newHumanProjectionShear` (`+0x3d8`), `m_dayNightTargetBrightness`, `m_dayNightBrightnessScale`, `m_dayNightBrightnessBias`, `m_dayNightHour` | day/night lighting fields from opcode `0x20`, [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md), [UID:00027Q][0x0066dd78-0x0066ddd8.MapPaneDayNightFloatTable](by-memory/0x0066dd78-0x0066ddd8.MapPaneDayNightFloatTable.md), UID0004RB, and UID0004RC. UID0002Y1, RenderMonster, and both scaled-RLE callback targets prove `+0x3d0` as float tint, `+0x3d4` as vertical scale/projection divisor, and `+0x3d8` as horizontal shear. Historical duration coefficient names are retained only as superseded aliases; original spelling is not proven. |
| `+0x114` | `m_mapResourceMode` | high-probability source-facing field name from [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md): opcode `0x06` optionally reads the mode byte, compares it with the old value, and calls `ResetMapResourceStateForModeChange` / `sub_5040A0` when it changes. |
| `+0x3f0` | `m_waitingForLocalPlayerStatus` | producer/consumer lifecycle: initialization and map/effect transitions set it; local-player status creation clears it; render/weather paths early-out while it is set. Historical `m_hasRenderableMap` inverted the observed gate and is superseded. |
| `+0x3f2`, `+0x3f4`, `+0x3f6`, `+0x3f8` | `m_mapId`, `m_mapWidth`, `m_mapHeight`, `m_tileBuffer` | Map-cache load/save, UID0004PZ allocation, coordinate/render/collision consumers, and UID0003TL all use these canonical fields. The `+0x3f8` buffer is an array of six-byte [UID:0004HP][MapPaneTileRecord](by-type/by-struct/MapPaneTileRecord.md) rows. Historical `m_mapWidthTiles`, `m_mapHeightTiles`, and `m_mapTileRecords` spellings are superseded aliases rather than additional members. |
| `+0x3fc`, `+0x400` | `m_tileOriginX`, `m_tileOriginY` | high; accepted [UID:0002QM][0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition](by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md) C++ uses these names, `0x00505130` subtracts them for map-to-screen conversion, `0x00505170` adds them for screen-to-map conversion, and [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md) / `0x00505290` use them to build visible tile bounds. |
| `+0xb0`, `+0xac` | inherited `m_viewportPixelX`, `m_viewportPixelY` | high for physical order; [UID:000427][0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll](by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md) writes the width/column delta to `+0xb0` and the height/row delta to `+0xac`; [UID:0002QM][0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition](by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md) repeats those stores. Historical pixel-origin aliases are superseded. |
| `+0x404`, `+0x408` | `m_visibleTileColumns`, `m_visibleTileRows` | high; [UID:000422][0x00505350-0x0050536b.MapPaneGetVisibleTileSpan](by-memory/0x00505350-0x0050536b.MapPaneGetVisibleTileSpan.md) current MCP session `60724697` confirms `+0x404` is stored to the output `MapPoint` column slot at `+4` and `+0x408` is stored to the row slot at `+0`. Exact constructor parameter spelling can still be rechecked at `InitializeMainUiGraph` for final source audits, but the visible-span field order is now established. |
| `+0x40e` | `bool m_movementStatusTagDisabled` | Canonical inverse-polarity movement/status-tag field. [UID:0002I7][0x00504110-0x00504521.MapPaneInitialize](by-memory/0x00504110-0x00504521.MapPaneInitialize.md) initializes it true through packed dword `0x00010001` at `+0x40c`; [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md) is the sole runtime writer and stores `(flags & 0x02) != 0`; [UID:000426][0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag](by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md) is the sole direct reader and returns the inverse. Consumers combine that predicate with the global config option to gate high-bit movement-history/status tags and related status handling. Historical `m_movementGate` / `m_viewportMoveGate` and day/collision interpretations are rejected. |
| `+0x108`, `+0x10c` | `m_selectedObjectActive` / `m_selectedLivingObjectActive`, `m_selectedObjectPane` / `m_selectedLivingObjectPane` | high-probability source names from [UID:0002QO][0x005060f0-0x00506169.MapPaneRemoveObjectPaneById](by-memory/0x005060f0-0x00506169.MapPaneRemoveObjectPaneById.md): when removing a type-3 `LivingObjectPane`, MapPane checks the active flag and pointer, disables the living-object highlight if the pointer equals the removed pane, then clears both fields. Exact original "selected" versus "highlighted" spelling remains open, but the fields are MapPane selection/highlight state, not ObjectPane fields. |
| `+0x414` | `m_weatherLayerPane` | SetMapState creates/replaces this pane and [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md) queues it for deferred deletion. Historical cleanup-pane aliases describe disposition only. |
| `+0x418`, `+0x41c`, `+0x420`, `+0x424` | `m_localPlayerObjectPane`, `m_auxiliaryPane`, `m_activeScreenLayer`, `m_objectList` | `+0x418` is source-typed `UserPane *`: timer paths call UserPane-only `ProcessMovement`, while inherited LivingObjectPane operations remain available. It participates in movement, render, recenter, create/update, and ObjectList detach paths. `+0x41c` is a virtually deleted map-owned auxiliary pane; `+0x420` is removed through `ScreenPane` before virtual cleanup; `+0x424` is the owned ObjectList. Historical active/preserve aliases for `+0x418` are superseded. |
| `+0x428` | `m_viewportGrafPort` | embedded GrafPort-style member; [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md) opens/closes its paint lifecycle when redrawing visible tiles. |
| `+0x4ce` | `m_refreshWholeVisibleMap` | source-facing candidate from UID0003TL: when set, opcode `0x06` clears the byte and refreshes the whole extended visible tile bounds before calling UID0003TJ. |
| `+0x4dc` / `+0x6dc` | `m_mapName[256]` / `m_mapNameLength` | source-facing candidates from UID0003TL: optional packet map-name bytes are copied, converted with `MultiByteToWideChar`, stored in the wide buffer at `this+1244`, and length-counted at `this+1756`. |
| `+0x6de` / `+0x8de` | `m_mapResourceName[256]` / `m_mapResourceNameLength` | source-facing candidates from UID0003TL: optional packet resource/palette bytes are copied, converted, stored in the wide buffer at `this+1758`, length-counted at `this+2270`, and used with `.EPF`/`.PAL` suffix construction. |
| `+0x4c8` and `+0x90c/+0x90e` | `m_mapFlashColor`; UID0003TL deferred map-surface refresh dirty flags at `+0x90c/+0x90e` | UID0004Q9 stores/clears the dword around invalidate/present passes and UID0004QY consumes nonzero values as draw color. UID0003TL separately uses the `+0x90c/+0x90e` pair in the EPF-layout deferred surface refresh branch. |
| `+0x8ec/+0x8f0` | `m_pendingActionRow`, `m_pendingActionColumn` | Raw UID00042E stores the converted map/action destination here, and UID0003ZS event `8` compares object/current coordinates against the pair before action/path behavior. Historical `m_pendingActionTileX/Y` wording is superseded. |
| `+0x8f4/+0x8f8` | current path destination coordinates | descriptive only. Event `8` passes this pair to the `0x0050c790` path scan variant; original field spelling and structure grouping remain open. |
| `+0x904` | pending action mode/state | descriptive only. Event `8` checks modes `5`, `6`, and `15`, and writes mode `6` during auto-action sequencing. |
| `+0x908` | pending action target object id | descriptive only. Event `8` passes this value to [UID:0002CD][0x00532370-0x00532443.ObjectListFindByObjectId](by-memory/0x00532370-0x00532443.ObjectListFindByObjectId.md). |
| `+0x90d` | byte inside bounded `m_pendingActionState` | Bits `4` and `2` select LivingObjectPane action-helper variants from event `8`; exact storage is represented in the complete 20-byte state region without inventing an unsupported standalone original lexeme. |
| `+0x90e` | auto-action/path-follow pending flag | descriptive only. Event `8` uses this byte to decide whether to continue movement/action sequencing; it is not yet a stable final class-field name. |

Compiler artifacts are not source statements: MapPane vtable writes/reseats, scalar deleting destructor flag handling, destructor adjustor thunks, `m_viewportGrafPort` explicit destructor call, deferred-motion record member-array construction/destruction, and base `Pane` destructor call should stay represented as normal C++ class/member/base behavior.

## Tile/Object-Grid Render Cluster Source-Quality Note

[UID:00037Y][0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore](by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md) is a MapPane-owned tile/object-grid/render/path helper aggregate, not one source method. Keep the class owner here and emit future source through exact child pages under [UID:0000L3][MapPane](by-file/MapPane.md), not as one monolithic aggregate body.

B005's 2026-06-19 source-quality implementation resolves the stale raw-tail question and keeps the range reconstructable: `0x0050e2f4-0x0050e300` is twelve `0xcc` alignment bytes, `0x0050e300-0x0050e316` is a route-negative MapPane wrapper that null-checks `m_objectList` at `this+0x424` and tail-jumps to [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md), and `0x0050e316-0x0050e320` is ten `0xcc` bytes before [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md). The former `0x0050e317` start was an off-by-one historical description superseded by exact bytes.

The helper-family roles are now source-quality named as `RefreshScrolledTileData` / `UpdateScrolledTileGrid`, `ComputeVisibleTileChecksum` / `ComputeTileRegionChecksum`, route-negative `UpdateMapTileChecksum16`, `GetLegacyAwareMapTileLayerIds` / `GetTileRenderIds`, `BuildTileScreenRect`, route-negative direction-mask accessors over [UID:00027O][0x0066dd50-0x0066dd60.MapObjectDirectionMasks](by-memory/0x0066dd50-0x0066dd60.MapObjectDirectionMasks.md), inner `FindObjectAtMapPoint` at `0x0050c470`, secondary object/tile hit-test, route-negative `FindSolidStaticObjectAtPoint`, path scan/deque variants at `0x0050c790` and `0x0050d010`, broad cached `DrawVisibleTiles` / `RedrawVisibleTileCache`, `DrawTileAt`, `SetWeatherState` / `SetMapWeather`, private object-grid/map save-load helpers, exact [UID:0004PZ][0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer](by-memory/0x0050e2a0-0x0050e2f4.MapPaneAllocateTileBuffer.md), and the `RefreshStaticObjectLighting` wrapper. Names other than independently resolved children remain source-facing best inferences.

B006's 2026-06-24 hit-test implementation resolves the previous naming collision: [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md) owns `MapPane::HitTestObjectAtPoint(y, x)` because it performs the inherited pane-bounds gate, while `0x0050c470` remains the lower-level `MapPane::FindObjectAtMapPoint` row/object finder used by both the wrapper and direct MapPane mouse-handler sites. The generated BackPane label is rejected as stale ownership pollution, not a class/source route.

The cluster uses the established MapPane fields `m_mapId` (`+0x3f2`), `m_mapWidth` (`+0x3f4`), `m_mapHeight` (`+0x3f6`), `m_tileBuffer` (`+0x3f8`), `m_tileOriginX`/`m_tileOriginY` (`+0x3fc/+0x400`), `m_visibleTileColumns`/`m_visibleTileRows` (`+0x404/+0x408`), `m_localPlayerObjectPane` (`+0x418`), `m_objectList` (`+0x424`), and `m_viewportGrafPort` (`+0x428`). Dependencies remain owned by their own docs: [UID:00027N][0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable](by-memory/0x0066db4c-0x0066dd50.MapPaneChecksumLookupTable.md), [UID:0003ZM][0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants](by-memory/0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants.md), [UID:00027O][0x0066dd50-0x0066dd60.MapObjectDirectionMasks](by-memory/0x0066dd50-0x0066dd60.MapObjectDirectionMasks.md), [UID:000235][0x00514f70-0x005151a9.MapPathDequeSupport](by-memory/0x00514f70-0x005151a9.MapPathDequeSupport.md), [UID:0001D6][0x00537900-0x00537abf.StaticObjectPaneCore](by-memory/0x00537900-0x00537abf.StaticObjectPaneCore.md), and [UID:00023D][0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper](by-memory/0x00530d00-0x00530ed9.ObjectListStaticObjectLightingSyncHelper.md).

Rejected owners for the whole cluster are `StaticObjectPane`, `ObjectList`, `MapPathDequeSupport`, data-table pages, [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md), and the broad parent [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md). Route-negative starts inside 00037Y are not compiler-generated proof and do not make the class non-reconstructable; they are private/raw helper bodies that need exact child policy before C++.

## Notify/Movement Timer Callback Source-Quality Note

[UID:00037U][0x00508f60-0x00509470.MapPaneNotifyTimerCore](by-memory/0x00508f60-0x00509470.MapPaneNotifyTimerCore.md) is now a non-emitting split index, not one `MapPane` method. B013's 2026-06-19 source-quality implementation split the range into [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md), five internal alignment bytes at `0x0050902b-0x00509030`, [UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md), and tail/alignment/raw bytes at `0x00509439-0x00509470`. The successor `0x00509470` is excluded from `00037U` and remains successor `MapPane::GetMapId` / `MapPane::GetCurrentMapId` evidence for byte offset `+0x3f2`.

[UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md) is the exact secondary-EventHandler virtual at slot `0x0061e77c`, source-facing `bool MapPane::HandleSystemOrControlEvent(Event *event)`. It normalizes the secondary receiver to complete `MapPane+0xa0`, drains canonical `m_queuedMapStateRefresh` before the discriminator under `g_useEpfAssets`, cancels inherited TimerHandler ids `6` then `8`, and calls proven `Pane::ReleaseMouseCapture` at `0x005449f0`. It handles only `event->m_type == kEventWorkNotification` (`22`), reads [UID:0000SM][g_pUrlAlertPane](by-global/g_pUrlAlertPane.md) only as an active-alert guard, allocates exactly `0x270` / 624 bytes, and calls [UID:00023O][0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant](by-memory/0x00553c10-0x00553cbf.ConnectionClosedDialogConstructorVariant.md). The machine allocator-null branch still reaches true; human source remains ordinary `new ConnectionClosedDialog`. Historical `OnNotifyMessage`, raw message-block, `m_timerHandler`, `RefreshQueuedMapState`, and UrlAlertPane-construction wording is superseded.

## UID0003ZT System-Control Event And Declaration Closure - 2026-07-23

- The managed class declaration replaces the stale notify signature with `HandleSystemOrControlEvent(Event *)`, removes the invented private `RefreshQueuedMapState`, retains canonical `bool m_queuedMapStateRefresh`, and preserves the complete `0x910` layout, every unrelated declaration, class closure, size guard, position zero, and `[[CHILDREN]]` route.
- Complete source visibility is explicit. Conceptual `MapPane.h` includes `Pane.h`, `GrafPort.h`, `Motion.h`, and `<vector>`, owns the exact two-int `MapPoint` declaration before MapPane, and sees complete inherited Pane/EventHandler/TimerHandler facets. Conceptual `MapPane.cpp` includes `<windows.h>`, `Event.h`, `ObjectStatusBlob.h`, `UserPane.h`, `LivingObjectPane.h`, `ObjectList.h`, `PacketBuffer.h`, `Socket.h`, `AlertPanes.h`, and `ReconnectDialog.h` before the affected definitions.
- `Event.h` owns complete `EventType`, `kEventWorkNotification`, and `Event`, and includes `util/LObject.h` before the base-derived declaration. `EventHandler.h` uses forward declarations only; `EventDispatcher.h` includes TimerHandler/EventHandler before its complete router shell. No unnamed PCH, duplicate Event declaration, or partial EventDispatcher class is assumed.
- `g_useEpfAssets` is declared by an exact source-root `extern bool`; its sole definition remains StartupWindow-owned. `g_pUrlAlertPane` is declared through `AlertPanes.h`; `ConnectionClosedDialog` is complete through `ReconnectDialog.h`; `g_pInputBlockerPane` is declared through the UserPane header contract. Definitions remain singular in their existing owners.
- The field at `+0x418` is `UserPane *m_localPlayerObjectPane`, because timer code invokes UserPane-only movement behavior. ObjectStatusBlob, LivingObjectPane, ObjectList, Win32 input, PacketBuffer, Socket, and `g_packetSender` remain dependencies rather than new MapPane-owned declarations.

[UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md) is the tertiary-vtable TimerHandler-facet callback at slot `0x0061e79c`. Best source-facing name is `MapPane::OnTimerEvent` or `MapPane::HandleMovementTimerEvent`. The raw `this` is the adjusted timer-handler subobject at approximately `MapPane + 0xa4`, and repeated `this - 164` arithmetic recovers the `MapPane` base. Event `5` clears a timer-state byte; event `6` drives queued movement/path stepping; event `7` handles left-button action polling and reschedules at `500` ms while the button remains down; event `8` resolves path/auto-action movement using target coordinates, ObjectList target lookup, sprite config, object coordinates, cursor state, and LivingObjectPane action helpers. Events `6` and `8` reschedule at `44` ms while queued state continues. [UID:0003EE][g_pInputBlockerPane](by-global/g_pInputBlockerPane.md) acts as a modal suppressor: when it is active, movement/action timer paths clear queued state instead of continuing path or action processing.

## 2026-06-25 0001AP Helper Split

The accepted B009 implementation resolves the coordinate/object/timer interior of [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md) into exact child pages. The source-bearing modeled helpers now include file-level [UID:00041W][0x00505080-0x00505100.MapPaneDirectionToTileOffset](by-memory/0x00505080-0x00505100.MapPaneDirectionToTileOffset.md), coordinate methods [UID:00041X][0x00505130-0x0050516a.MapPaneMapToScreenCoords](by-memory/0x00505130-0x0050516a.MapPaneMapToScreenCoords.md) / [UID:00041Y][0x00505170-0x005051bb.MapPaneScreenToMapCoords](by-memory/0x00505170-0x005051bb.MapPaneScreenToMapCoords.md), visible-bounds helpers [UID:000420][0x00505290-0x00505304.MapPaneGetClampedVisibleTileBounds](by-memory/0x00505290-0x00505304.MapPaneGetClampedVisibleTileBounds.md) / [UID:000421][0x00505310-0x0050534d.MapPaneGetVisibleTileBounds](by-memory/0x00505310-0x0050534d.MapPaneGetVisibleTileBounds.md) / [UID:000422][0x00505350-0x0050536b.MapPaneGetVisibleTileSpan](by-memory/0x00505350-0x0050536b.MapPaneGetVisibleTileSpan.md) / [UID:000423][0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds](by-memory/0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds.md) / [UID:000428][0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds](by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md), movement helpers [UID:000425][0x00505430-0x005055ca.MapPaneCheckMovementCollision](by-memory/0x00505430-0x005055ca.MapPaneCheckMovementCollision.md) / [UID:000426][0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag](by-memory/0x005055d0-0x005055db.MapPaneAllowsMovementStatusTag.md) / [UID:000427][0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll](by-memory/0x005055e0-0x00505645.MapPaneApplyMovementSubstepScroll.md), no-op hooks [UID:000429][0x00505730-0x00505731.MapPaneAfterLocalPlayerWarp](by-memory/0x00505730-0x00505731.MapPaneAfterLocalPlayerWarp.md) / [UID:00042A][0x00505740-0x00505743.MapPaneObjectCallbackNoOp](by-memory/0x00505740-0x00505743.MapPaneObjectCallbackNoOp.md), object helper [UID:00042D][0x00505940-0x005059cb.MapPaneReindexObjectPanePosition](by-memory/0x00505940-0x005059cb.MapPaneReindexObjectPanePosition.md), and clearers [UID:00042F][0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh](by-memory/0x00505cc0-0x00505cf9.MapPaneClearQueuedMovementRefresh.md) / [UID:00042I][0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll](by-memory/0x00505de0-0x00505dfe.MapPaneClearPendingActionPoll.md).

## UID00042I Pending-Action Poll Contract - 2026-07-28

- The complete class declaration owns exactly one `void ClearPendingActionPoll();` declaration and one `bool m_pendingActionPoll;` field. UID00042I owns the sole out-of-class definition; its own H channel remains blank to prevent duplicate declarations.
- Five direct calls establish live class ownership. Four UID00037S mouse paths call after recovering complete MapPane from the EventHandler facet where needed; UID0003ZS calls on button release after recovering complete MapPane from its TimerHandler facet.
- The method accepts complete `MapPane *`, tests and clears `m_pendingActionPoll`, then makes a qualified inherited `TimerHandler::CancelTimer(7)` call. The compiler's `+0xa4` adjustment represents multiple-inheritance base conversion, not a source-visible timer-handler member.
- Raw UID00042H supplies the paired set/schedule body but remains non-emitting because no entry route survives. That raw-route caveat does not weaken UID00042I's exact method body, owner, declaration, or source placement.

[UID:00042A][0x00505740-0x00505743.MapPaneObjectCallbackNoOp](by-memory/0x00505740-0x00505743.MapPaneObjectCallbackNoOp.md) is a MapPane empty callback, not a raw no-route blank-C++ child. B006's 2026-07-03 MCP session `e63ee655` confirms exact bytes `c2 04 00` / `retn 4`, `0xcc` padding after `0x00505743`, and one direct raw-code xref from `0x0053c385`. The caller relay at `0x0053c370-0x0053c38d` loads `g_activeMapPane`, calls [UID:0004DS][0x00506980-0x00506ad4.MapPaneUpdateObjectPaneScreenBounds](by-memory/0x00506980-0x00506ad4.MapPaneUpdateObjectPaneScreenBounds.md), then calls the no-op with the same object argument; that relay has no modeled function, decompile, inbound xref to start/end, or absolute pointer route, so it is source-shaped support evidence rather than an unqualified live ObjectPane API proof.

The raw no-route children are [UID:000424][0x005053f0-0x0050542d.MapPaneGetUnclampedExtendedVisibleTileBounds](by-memory/0x005053f0-0x0050542d.MapPaneGetUnclampedExtendedVisibleTileBounds.md), [UID:00042B][0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch](by-memory/0x00505750-0x005057c8.MapPaneRawDirectionBoundsScratch.md), [UID:00042C][0x005057d0-0x005058ac.MapPaneRawObjectCleanupSweep](by-memory/0x005057d0-0x005058ac.MapPaneRawObjectCleanupSweep.md), [UID:00042E][0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6](by-memory/0x00505c00-0x00505cb1.MapPaneQueueMovementRefreshTimer6.md), [UID:00042G][0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8](by-memory/0x00505d00-0x00505d9a.MapPaneQueueMovementRefreshTimer8.md), [UID:00042H][0x00505da0-0x00505dd2.MapPaneQueueActionPollTimer](by-memory/0x00505da0-0x00505dd2.MapPaneQueueActionPollTimer.md), and [UID:00042J][0x005061e0-0x005062e5.MapPaneRefreshNearbyObjectRows](by-memory/0x005061e0-0x005062e5.MapPaneRefreshNearbyObjectRows.md). Current MCP-backed proof says each raw start is not an IDA function, has zero incoming xrefs, and has zero absolute pointer-pattern hits; those pages remain reconstructable MapPane source-shaped evidence but do not emit C++ until a route or retained-helper emission policy is proven.

B005's 2026-07-03 UID000425 callback established the movement-collision child. Evidence-time MCP session `e63ee655` confirmed [UID:000425][0x00505430-0x005055ca.MapPaneCheckMovementCollision](by-memory/0x00505430-0x005055ca.MapPaneCheckMovementCollision.md) as an exact `0x19a`-byte MapPane method with successor UID000426, four caller sites in `0x0050c790`, four in `0x0050d010`, and one local-player movement consumer at `0x005a3207`. The method reads `m_mapWidth`/`m_mapHeight`, unconditionally dereferences `m_localPlayerObjectPane` at `+0x418` to test the byte at `+0x1340fc`, uses `m_objectList` at `+0x424` for a blocking object and `GM` pass-through check, calls the tile-layer helper twice, and consumes `g_objectRecordCount`, `g_objectNationMap`, and UID00027O direction masks. B003's six-byte tile-view correction changes only stale source expressions to `.staticObjectId` and `(flags & 1) == 0`; the exact -1/0/1 policy, object blocking/GM bypass, nine callers, owner, route, score, and every unrelated fact remain unchanged. ObjectList, LivingObjectPane/UserPane, global data pages, and the broad UID0001AP aggregate remain rejected owners.

B003's 2026-07-01 UID00042J recheck refines only [UID:00042J][0x005061e0-0x005062e5.MapPaneRefreshNearbyObjectRows](by-memory/0x005061e0-0x005062e5.MapPaneRefreshNearbyObjectRows.md). Current MCP proves no modeled function at `0x005061e0`/`0x005062e2`/`0x005062e5`, no decompile, no incoming start xrefs, no VA/RVA pointer-byte hits, no local name, no source-declaration/table/vtable/generated-output route, and a unique full-range body signature that proves uniqueness but not reachability. The raw helper remains MapPane-owned/source-family evidence because it uses `m_objectList`, byte `+0x3f0`, clamped visible bounds, `ObjectList::GetBackRowBucket`, object-position filtering, and object bounds/refresh virtual paths; it must stay non-emitting with blank formal C++ until new route evidence appears.

B013's 2026-06-29 UID000424 recheck refines the visible-bounds family specifically: [UID:000424][0x005053f0-0x0050542d.MapPaneGetUnclampedExtendedVisibleTileBounds](by-memory/0x005053f0-0x0050542d.MapPaneGetUnclampedExtendedVisibleTileBounds.md) is the non-emitting raw no-route unclamped sibling of [UID:000423][0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds](by-memory/0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds.md). It reads `m_tileOriginX`/`m_tileOriginY` and `m_visibleTileColumns`/`m_visibleTileRows`, writes an extended output `MapRect`, and omits the map-dimension clamps that UID000423 applies. MapPane remains the owner, but UID000424 must not emit through this class until a caller, pointer/literal VA, table/vtable, source-declaration, or generated-output route is found.

B008's 2026-07-04 UID000422 callback refines the adjacent visible-span getter without changing class metadata. Current MCP session `60724697` confirms [UID:000422][0x00505350-0x0050536b.MapPaneGetVisibleTileSpan](by-memory/0x00505350-0x0050536b.MapPaneGetVisibleTileSpan.md) is the exact `0x1b`-byte `MapPane::GetVisibleTileSpan(MapPoint *outSpan) const` method with bytes `55 8b ec 8b 45 08 8b 91 04 04 00 00 8b 89 08 04 00 00 89 50 04 89 08 5d c2 04 00`, no callees, and two callsites at `0x005a27fc` and `0x005a2afd` in the `UserPane` constructor path. Those callsites load `ecx` from `UserPane +0x1340f8`; [UID:00024A][0x005b83a0-0x005b83a7.UserPaneGetMapPane](by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md) already proves that field is the cached `MapPane *m_mapPane`, so `UserPane` is only a consumer. The method copies `m_visibleTileColumns` from `+0x404` to output `+4` and `m_visibleTileRows` from `+0x408` to output `+0`, has `0xcc` padding before and after, and is not a RankingDialog-owned helper, raw no-route helper, padding span, or extension into successor [UID:000423][0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds](by-memory/0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds.md).

Rejected alternatives: do not fold `0x00509470` into the notify/timer range; do not keep compiler `sub_508F60`/`sub_509030` names in source-facing prose except as IDA evidence; do not route the timer handler to `TimerMgr`, `LivingObjectPane`, `ObjectList`, or cursor/sprite helpers. Those pages own helpers and data consumed by the MapPane callback, while the vtable slots, adjusted-this normalization, and field accesses prove the source owner is UID00007Q via UID0000L3. Exact method bodies belong only on child pages; UID00007Q emits declarations only.

## IDA MCP Evidence

IDA confirmed selected anchor ranges:

- 2026-06-17 B002 source-quality execution for [UID:0002I2][0x00503e90-0x00503ecd.MapPaneFindActiveEffect](by-memory/0x00503e90-0x00503ecd.MapPaneFindActiveEffect.md): resolved the MapPane effect-list triplet to a runtime `ScreenEffecter *` array, inferred `MapPane::FindActivePixelEffecter()` and `ScreenEffecter::IsPixelEffecter()`, tied the sole caller to Layer render traversal at `0x004f1286`, and populated first-draft C++ for the exact finder.
- 2026-06-18 B002 effect-list helper-family source-quality execution: [UID:0002I1][0x00503e80-0x00503e8b.MapPaneHasEffectListEntries](by-memory/0x00503e80-0x00503e8b.MapPaneHasEffectListEntries.md), [UID:0002I3][0x00503ed0-0x00503eef.MapPaneResetEffectListFields](by-memory/0x00503ed0-0x00503eef.MapPaneResetEffectListFields.md), [UID:0002I4][0x00503ef0-0x0050408d.MapPaneConfigureEffectList](by-memory/0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md), and [UID:0002I6][0x005040a0-0x00504102.MapPaneClearEffectList](by-memory/0x005040a0-0x00504102.MapPaneClearEffectList.md) are now documented as `MapPane::HasScreenEffecters() const`, `MapPane::ResetScreenEffecterListFields()`, `MapPane::ConfigureScreenEffecterList(signed char effectMode)`, and `MapPane::ClearScreenEffecterList()` with first-draft C++ on the exact child pages. This pass preserved the PE no-route evidence for reset/configure, accepts mode `1` as `kMapScreenEffectRedWave` (`XWaveEffecter` plus red `SolidColorFilterEffecter`), accepts mode `2` as `kMapScreenEffectWaterFilter`, keeps capacity `10` as `kMapScreenEffecterCapacity`, resolves vtable slot `+0x18` flag `1` cleanup as source-level `delete effecter;`, rejects generic weather/effects/layer ownership for the container, and keeps MapPane as owner of the `m_screenEffecterCount`/`m_screenEffecterCapacity`/`m_screenEffecters` lifecycle while Effects owns the effecter classes.
- 2026-06-18 B002 movement/object-update source-quality execution: [UID:0002QG][0x005046d0-0x005047e8.MapPaneQueuedMotionMessage](by-memory/0x005046d0-0x005047e8.MapPaneQueuedMotionMessage.md), [UID:0002QL][0x005058b0-0x0050593e.MapPaneScrollViewportByDirection](by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md), [UID:0002QM][0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition](by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md), and [UID:0002QN][0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane](by-memory/0x00505e00-0x005060e3.MapPaneCreateOrUpdateObjectPane.md) now carry first-draft C++ and updated source-quality notes. This pass reroutes [UID:0002QG][0x005046d0-0x005047e8.MapPaneQueuedMotionMessage](by-memory/0x005046d0-0x005047e8.MapPaneQueuedMotionMessage.md) from the file root to the `MapPane` class, resolves `+0x118/+0x398/+0x39c` as deferred motion records/count/active flag, uses `+0x418` as the active/local object pointer, preserves `+0x424` as `m_objectList`, distinguishes outbound opcode `0x05` from the inbound server opcode enum, and documents `0x0050a940` as MapPane descriptor-driven lighting/effect attachment rather than generic item drawing.
- 2026-06-18 B002 teardown/object-packet source-quality execution: [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md) is `MapPane::ExitToMenu(bool notifyServer)` / `sendLogoutPacket`; [UID:0002QI][0x00504b70-0x00504b8f.MapPaneTagDetachMessage](by-memory/0x00504b70-0x00504b8f.MapPaneTagDetachMessage.md) is the common LObject override `MapPane::OnChangeMessage(LObject *, Message *)` for `MessageType` tag `0x676f6f67` / `goog` (the former `OnTagDetachMessage`/`TaggedPaneMessage` interpretation is superseded); [UID:0002QO][0x005060f0-0x00506169.MapPaneRemoveObjectPaneById](by-memory/0x005060f0-0x00506169.MapPaneRemoveObjectPaneById.md), [UID:0002QP][0x00506170-0x005061d3.MapPaneDetachObjectPane](by-memory/0x00506170-0x005061d3.MapPaneDetachObjectPane.md), and [UID:0002QQ][0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect](by-memory/0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect.md) are class-owned `RemoveObjectPaneById`, `DetachObjectPane`, and `HasObjectIntersectingRect` methods with first-draft C++; [UID:000231][0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper](by-memory/0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper.md) remains a `MapPane.cpp` file-static outbound object-refresh helper because it has no `this` receiver.
- Historical 2026-06-18 B003 day/night raw-duplicate state: [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md) established the no-route duplicate and live opcode `0x20` route using then-current duration aliases. UID00037W reanalysis supersedes only those aliases with `m_dayNightTintCurveScale`, `m_dayNightTintCurveBase`, and `MapPane::SetDayNightFadeTarget(float targetBrightness, float tintAmount)` while preserving the raw/source ownership decision.
- 2026-06-16 B001 continuation batch8: extended [UID:0003TN][0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket](by-memory/0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket.md) to include its owned switch table, and added exact packet-handler children [UID:0003TO][0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket](by-memory/0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket.md), [UID:0003TP][0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket](by-memory/0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket.md), [UID:0003TQ][0x00512960-0x00512ca4.MapPaneHandleActionPacket](by-memory/0x00512960-0x00512ca4.MapPaneHandleActionPacket.md), [UID:0003TR][0x00512d60-0x00512f1c.MapPaneHandleFlyingObjectUpdatePacket](by-memory/0x00512d60-0x00512f1c.MapPaneHandleFlyingObjectUpdatePacket.md), [UID:0003TS][0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket](by-memory/0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket.md), and [UID:0003TT][0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket](by-memory/0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md). These remain MapPane-owned packet parsers while WorldMapPane, object panes, sound/effect classes, ObjectList, and protocol tables remain dependency or constructed-object owners.
- 2026-06-16 B001 continuation batch9: added direct packet-handler children [UID:0003TX][0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket](by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md) for opcode `0x33` and [UID:0003TY][0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket](by-memory/0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket.md) for opcode `0x03`. The same pass added file-level MapPane protocol helpers [UID:0003TU][0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet](by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md), [UID:0003TV][0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket](by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md), and [UID:0003TW][0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay](by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md) under the MapPane source file because those helpers have no `this` receiver.
- 2026-06-16 B001 continuation batch7: exact children [UID:0003TM][0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket](by-memory/0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md) and [UID:0003TN][0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket](by-memory/0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket.md) split the dispatcher-backed opcode `0x07` draw-objects/spawn path and opcode `0x0d` movement/speech-balloon path from [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md). The first creates/updates visible object panes and dispatches nested object effects; the second constructs/registers BalloonObjectPane overlays while preserving BalloonObjectPane implementation ownership.
- `0x00504530-0x005046c6`: destructor-like cleanup.
- `0x00504b90-0x00504df1`: map file load path.
- `0x00504e00-0x00505075`: map file save path.
- `0x00507c90-0x00508e06`: large map packet dispatcher.
- `0x005094b0-0x0050a4fd`: render map view.
- `0x0050a500-0x0050a837`: paint handler.
- `0x0050bbb0-0x0050bcd8`: map change.
- `0x0050db50-0x0050dcb3`: weather/map state setter.
- `0x00507c90-0x00508e06`: IDA-confirmed `0x1176` byte packet dispatcher with callees into packet readers, dialog constructors, map object handlers, [UID:0000F3][TimerPane](by-class/TimerPane.md), and socket send helpers.
- 2026-05-25 send-helper recheck: IDA MCP callers show `MapPane::HandlePacket` calls [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md) from inbound case `0x6a` at `0x00508b14` after writing [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md) / `g_friendNameListSyncEnabled`; the same dispatcher also calls [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md), and the `0x00511440` spawn/movement/chat handler also calls `GetConnectionStatus`.
- `0x00510400`: raw function-shaped weather-handler bytes, but not currently an IDA function object.
- 2026-05-24 recheck: `0x00510400` is still `Not a function` in IDA, while `0x005104d0` and `0x0050db50` are modeled function starts. Current generated `MapPane::HandlePacket` already inlines the day/night blend body under case `0x20`, so the standalone `HandleWeatherPacket` row should be treated as a boundary/raw duplicate caveat until packet dispatch is reconciled.
- 2026-05-25 recheck: `0x00510400-0x005104c7` disassembles as a normal raw body but has no direct IDA callers or xrefs; `MapPane::HandlePacket` contains the same body inline at `0x00507e45-0x00507f04`.
- 2026-05-26 recheck: generated BackPane helpers at `0x00506ce0` and `0x005388a0` are MapPane/target-selection related by caller evidence. `0x00506ce0` is called from spell/item/select/target mouse-selection paths; `0x005388a0` is called only from MapPane packet/object setup at `0x0050eb14`.
- 2026-05-28 recheck: [UID:000231][0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper](by-memory/0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper.md) is a small MapPane packet helper called from `MapPane::HandlePacket` and object/status update paths when an expected object target is missing.
- 2026-05-28 recheck: [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) is a MapPane object/effect descriptor helper called from spawn/object-create paths and active-map consumers.
- 2026-06-08 B001 ownership audit for [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md) confirms this class's coordinate/movement helper surface as the best source owner. IDA found 23 direct reads of `0x0066da96`, no direct writes, and repeated use of `4 * byte_66DA96` in `0x005055e0`, `0x00506980`, and `0x0050b080` while those helpers call `0x00505080` and consume tile dimensions. The LivingObjectPane/UserPane movement readers call back through MapPane helpers such as `0x005055e0`, `0x005058b0`, `0x005059d0`, and `0x00506980`, making them consumers rather than stronger owners.
- 2026-06-12 A002 Batch 325 resource-string split: exact child [UID:0003IN][0x0061e6f0-0x0061e6f8.MapPaneCmapSignatureString](by-memory/0x0061e6f0-0x0061e6f8.MapPaneCmapSignatureString.md) now carries the ANSI `CMAP` literal at `0x0061e6f0`. MapPane owns it through [UID:0002ZN][0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer](by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md) and the compressed-map load/save methods, while the containing [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md) page remains parentless because it also contains MapNamePane, MiniMapButtonPane, LivingObjectPane, and ObjectList literals.
- 2026-06-12 C001 Batch C001-018/C001-021 split the later [UID:0002ST][0x0061e908-0x0061eadc.MapPaneResourceStrings](by-memory/0x0061e908-0x0061eadc.MapPaneResourceStrings.md) range. MapPane file-owned children now cover cache path/selection-marker data [UID:0003IU][0x0061e924-0x0061e964.MapPaneCachePathStringsAndSelectionMarker](by-memory/0x0061e924-0x0061e964.MapPaneCachePathStringsAndSelectionMarker.md), user face asset path strings [UID:0003IW][0x0061e9fc-0x0061ea24.MapPaneUserFaceAssetPathStrings](by-memory/0x0061e9fc-0x0061ea24.MapPaneUserFaceAssetPathStrings.md), MapPane-only world-map comparison string groups [UID:0003JH][0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings](by-memory/0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings.md) and [UID:0003JJ][0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings](by-memory/0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings.md), and numeric constants [UID:0003J0][0x0061eac0-0x0061ead4.MapPaneNumericConstants](by-memory/0x0061eac0-0x0061ead4.MapPaneNumericConstants.md). Shared [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md), [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md), and runtime/config strings remain unassigned.

## Ownership Notes

`MapPane` is too broad to reduce to a generic UI control. It is the main gameplay world-view module.

The movement substep global should be treated as MapPane coordinate/movement support, not as a `UserPane`, `LivingObjectPane`, `AttachedObjectPane`, or standalone movement-globals declaration. Those systems read or consume the scale, but IDA ties the arithmetic back to MapPane direction, tile, viewport, and object-placement helpers.

Current `simroot_v2/class_MapPane.cpp` also contains generated-owner pollution from shared UI/render code:

- `0x005446e0-0x00544b7d` is [UID:0000MC][Pane](by-file/Pane.md) dirty/motion paint infrastructure used by layer traversal.
- `0x00556ce0-0x00556d41` is [UID:0000NB][ScreenPane](by-file/ScreenPane.md) root layer-list infrastructure used by startup/shutdown and map/world-map layer changes.
- `0x00557140-0x00559aef` is not an unresolved MapPane ownership range. [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md) is a non-emitting mixed-owner container whose exact children route to Surface, ScreenPane, or ScreenshotCapture.

## Resolved / Remaining Source-Quality Work

- Weather/source placement: MapPane owns packet-driven weather/day-night orchestration, `m_screenEffecters`, state changes, and construction calls into weather layers. Runtime effecter classes belong to [UID:0000IZ][Effects](by-file/Effects.md); weather overlay pane implementations belong to the WeatherLayerPane/Raining/Snowing/Swallow map-weather family. Generic render-only weather placement for MapPane methods is rejected.
- Raw `0x00510400`: keep [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md) as retained raw duplicate evidence for dispatcher opcode `0x20`. Do not migrate it as an independent `MapPane::HandleWeatherPacket` method unless new function/xref/table evidence appears.
- Surface presentation: [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md) proves a mixed non-emitting Surface/ScreenPane/ScreenshotCapture container, not MapPane source.
- Packet handlers: exact child pages now split most direct opcode handlers and no-receiver file-static helpers. [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) should remain a class-owned aggregate with blank C++ until final payload structs/opcode names and raw/no-route helper bodies are resolved on exact children.
- Low-grade child priorities: the [UID:0002I1][0x00503e80-0x00503e8b.MapPaneHasEffectListEntries](by-memory/0x00503e80-0x00503e8b.MapPaneHasEffectListEntries.md)/[UID:0002I3][0x00503ed0-0x00503eef.MapPaneResetEffectListFields](by-memory/0x00503ed0-0x00503eef.MapPaneResetEffectListFields.md)/[UID:0002I4][0x00503ef0-0x0050408d.MapPaneConfigureEffectList](by-memory/0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md)/[UID:0002I6][0x005040a0-0x00504102.MapPaneClearEffectList](by-memory/0x005040a0-0x00504102.MapPaneClearEffectList.md) effect-list helper family now has B002 source-quality incorporation for `HasScreenEffecters`, `ResetScreenEffecterListFields`, `ConfigureScreenEffecterList`, `ClearScreenEffecterList`, mode `1` red wave/filter, mode `2` water filter, capacity `10`, scalar-delete-as-`delete effecter;`, PE no-route evidence for reset/configure, rejected weather/effects/layer owner alternatives, and first-draft C++. [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md) is no longer a low-grade priority after B006's MCP-backed implementation. [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md) is also no longer an unsplit coordinate/object backlog item after the B009 accepted helper split; remaining work there is only the documented raw no-route children. Current priorities are descriptor dispatch [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md), exact children under [UID:00037Y][0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore](by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md), and remaining raw/no-route packet bodies under [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) before rename-heavy migrations.
- Class declaration readiness is closed: UID00007Q emits the complete `0x910` class/header block at `93/94`, exact method bodies emit from child pages, and packet/helper types use accepted declarations or bounded behavior-based private state.

## UID0003TC ApplyHitBarObjectPane Integration - 2026-07-15

- [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md) is the exact retained private MapPane method for `[0x0050e690,0x0050e805)`. It takes a `LivingObjectPane *` plus primary/secondary unsigned value/maximum pairs and returns `void`; the varying exit-register residues in the out-of-line copy and the complete inline twin in UID0003TB reject IDA's unsigned-return lead.
- Both percentages are computed before the object null check. Each path uses the observed `10000000` threshold to choose ordinary multiply/divide or the overflow-avoiding quotient/remainder form, then truncates to `unsigned short`. There is no divisor-zero guard, clamp, saturation, or alternate failure path.
- The method reads typed `LivingObjectPane::m_hitBarObjectPane` at `+0x1dc`. If an existing pane reports `IsActive() == 1`, it calls `SetValues(primaryPercent, 100, secondaryPercent, 100)` and returns. Otherwise it removes a stale pane from `m_objectList` at MapPane `+0x424`, source-deletes it, clears/replaces the owner slot through the accepted setter route, and constructs the replacement with owner, map row, map column, both percentages, and both maxima fixed at 100.
- Replacement ordering is exact and behavior-relevant: construct, set owner slot, add to ObjectList, virtual `UpdatePosition`, inherited `GrafPort::GetBounds`, then `InvalidateRect`. The owner map row/column come from `LivingObjectPane::GetMapPosition`; the bounds call is UID000161 `GrafPort::GetBounds`, not a BackPane member.
- Exact target evidence is 373 bytes, SHA256 `1E1A016D5EB8642081823AE3A1D378F3DCBD7291519FECA4D3B8A73B17941C0B`, 19 CFG blocks, complexity 5, 146 instructions, three leading and eleven trailing `0xcc` bytes, no strings, and no inbound IDA/raw rel32/VA/RVA/table route. The complete inlined twin in UID0003TB makes the retained out-of-line source method valid despite the absent inbound route.
- Source placement is a private declaration in the complete MapPane header union and an out-of-line definition in `NexusTK/map/MapPane.cpp`, ordered between UID0003TB and UID0003TD by existing address-path order. `EMITTER_POSITION_OPTIONAL` stays blank because assigning a numeric position would move this child ahead of established no-position MapPane children.
- Ordinary source uses class `new`/`delete`. Pool allocator calls, constructor unwind/free, SEH registration, cookie setup/check, scalar deleting destructor dispatch, vptr stores, RTTI, vtables, and magic-division lowering are compiler/inlined implementation details and must not be handwritten.
- UID0003TC remains the sole owner of its method body. The 2026-07-15 source-closure pass separately raises UID00007Q to `93/94` and emits the complete no-loss class shell; packet/layout dependencies use their accepted types and bounded behavior-based field names rather than remaining broader class blockers.
- Rejected alternatives retained: HitBarObjectPane ownership confuses the constructed object with the method receiver; dead/compiler-outline classification contradicts the coherent source policy and inline twin; a duplicate exact child is unnecessary; health/mana parameter names are unsupported; and no-caller status is a confidence cap rather than a blank-C++ reason.

## UID0003UW Group-Member HitBar Method Integration - 2026-07-15

- The exact group-member method sequence in MapPane source/address order is [UID:0003TB][0x0050e4c0-0x0050e68d.MapPaneRefreshGroupMemberHitBar](by-memory/0x0050e4c0-0x0050e68d.MapPaneRefreshGroupMemberHitBar.md) `RefreshGroupMemberHitBar` at `[0x0050e4c0,0x0050e68d)`, retained [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md) `ApplyHitBarObjectPane` at `[0x0050e690,0x0050e805)`, then [UID:0003TD][0x0050e810-0x0050e848.MapPaneRemoveGroupMemberHitBar](by-memory/0x0050e810-0x0050e848.MapPaneRemoveGroupMemberHitBar.md) `RemoveGroupMemberHitBar` at `[0x0050e810,0x0050e848)`. All three keep blank emitter positions so existing no-position child order remains stable.
- UID0003TB takes a group-member id, excludes the local player, honors `Config::m_groupBarEnabled`, finds [UID:0004R9][0x005adbe0-0x005adc15.UserPaneFindGroupMemberById](by-memory/0x005adbe0-0x005adc15.UserPaneFindGroupMemberById.md) `UserPane::FindGroupMemberById`, resolves a `LivingObjectPane` through MapPane's `ObjectList`, and applies UID0003TC using current/maximum HP and current/maximum MP. Its binary contains a complete inline twin of UID0003TC, so the source-level helper call is the accepted behavior-identical reduction.
- UID0003TD takes a group-member id, resolves the `LivingObjectPane`, reads typed `m_hitBarObjectPane` at `+0x1dc`, requires `IsActive()`, and source-deletes the active pane. The observed slot-zero call with flag `1` is scalar deleting-destructor ABI, not a handwritten activation callback.
- Source-facing private method declarations use the accepted names and signatures represented by those exact child pages. UID00007Q emits the declaration block only; no method body is duplicated from this class page.
- Exact child metadata is UID0003TB `92/93`, UID0003TC `92/93`, and UID0003TD `91/93`, each owner/emitter UID00007Q and reconstructable true. UID00007Q is `93/94`; its owner/emitter route is unchanged.
- Required dependencies are `UserPane`, `GroupMemberRecord`, [UID:0004R9][0x005adbe0-0x005adc15.UserPaneFindGroupMemberById](by-memory/0x005adbe0-0x005adc15.UserPaneFindGroupMemberById.md), `Config`, `ObjectList`, `LivingObjectPane`, and `HitBarObjectPane`. Group/NewGroupPane/UserPane are callers or state providers; MapPane remains the direct semantic owner of map-object and HitBar side effects.
- Historical `ProcessMapEvent` and `ActivateLinkedObjectById` spellings are superseded. Earlier caller, allocation, pool, pointer-registration, padding, and lifecycle facts remain valid evidence; only their generic event/activation interpretation is rejected.
- Compiler exclusions remain explicit: do not handwrite SEH/cookie scaffolding, pooled allocation internals, constructor inlining, scalar deleting-destructor flags, vptr/vtable mechanics, exception cleanup, or duplicate UID0003TC policy.

## Cross-References

- [UID:0000L3][MapPane](by-file/MapPane.md)
- [UID:0000PR][g_activeMapPane](by-global/g_activeMapPane.md)
- [UID:0000T7][MapTilePixelDimensions](by-global/MapTilePixelDimensions.md)
- [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md)
- [UID:00027F][0x0066da96-0x0066da97.g_movementSubstepScale](by-memory/0x0066da96-0x0066da97.g_movementSubstepScale.md)
- [UID:0000VC][ScaleDirectionOffsetToPixels_00505100](by-item/ScaleDirectionOffsetToPixels_00505100.md)
- [UID:0001QG][client_map_system](by-meta/client_map_system.md)
- [UID:0001SO][MapServerPacketOpcode](by-type/by-enum/MapServerPacketOpcode.md)
- [UID:0002I1][0x00503e80-0x00503e8b.MapPaneHasEffectListEntries](by-memory/0x00503e80-0x00503e8b.MapPaneHasEffectListEntries.md)
- [UID:0002I2][0x00503e90-0x00503ecd.MapPaneFindActiveEffect](by-memory/0x00503e90-0x00503ecd.MapPaneFindActiveEffect.md)
- [UID:0002I4][0x00503ef0-0x0050408d.MapPaneConfigureEffectList](by-memory/0x00503ef0-0x0050408d.MapPaneConfigureEffectList.md)
- [UID:0002I6][0x005040a0-0x00504102.MapPaneClearEffectList](by-memory/0x005040a0-0x00504102.MapPaneClearEffectList.md)
- [UID:0000UP][FriendNameListSyncOpcodes](by-item/FriendNameListSyncOpcodes.md)
- [UID:0000PG][g_friendNameListSyncEnabled](by-global/g_friendNameListSyncEnabled.md) / `g_friendNameListSyncEnabled`
- [UID:0001HX][0x00574e50-0x0057536b.BuildAndSendFriendNameListSync](by-memory/0x00574e50-0x0057536b.BuildAndSendFriendNameListSync.md)
- [UID:0001HY][0x00575370-0x00575377.GetConnectionStatus](by-memory/0x00575370-0x00575377.GetConnectionStatus.md)
- [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md)
- [UID:0001AQ][0x00505100-0x00505123.ScaleDirectionOffsetToPixels](by-memory/0x00505100-0x00505123.ScaleDirectionOffsetToPixels.md)
- [UID:0002QL][0x005058b0-0x0050593e.MapPaneScrollViewportByDirection](by-memory/0x005058b0-0x0050593e.MapPaneScrollViewportByDirection.md)
- [UID:0002QM][0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition](by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md)
- [UID:000231][0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper](by-memory/0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper.md)
- [UID:0001AT][0x00506970-0x0050e320.MapPaneInputPacketRenderCore](by-memory/0x00506970-0x0050e320.MapPaneInputPacketRenderCore.md)
- [UID:00037U][0x00508f60-0x00509470.MapPaneNotifyTimerCore](by-memory/0x00508f60-0x00509470.MapPaneNotifyTimerCore.md)
- [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md)
- [UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md)
- [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md)
- [UID:000235][0x00514f70-0x005151a9.MapPathDequeSupport](by-memory/0x00514f70-0x005151a9.MapPathDequeSupport.md)
- [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md)
- [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md)
- [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md)
- [UID:0003TM][0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket](by-memory/0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md)
- [UID:0003TN][0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket](by-memory/0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket.md)
- [UID:0003TO][0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket](by-memory/0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket.md)
- [UID:0003TP][0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket](by-memory/0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket.md)
- [UID:0003TQ][0x00512960-0x00512ca4.MapPaneHandleActionPacket](by-memory/0x00512960-0x00512ca4.MapPaneHandleActionPacket.md)
- [UID:0003TR][0x00512d60-0x00512f1c.MapPaneHandleFlyingObjectUpdatePacket](by-memory/0x00512d60-0x00512f1c.MapPaneHandleFlyingObjectUpdatePacket.md)
- [UID:0003TS][0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket](by-memory/0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket.md)
- [UID:0003TT][0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket](by-memory/0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md)
- [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md)
- [UID:0003TB][0x0050e4c0-0x0050e68d.MapPaneRefreshGroupMemberHitBar](by-memory/0x0050e4c0-0x0050e68d.MapPaneRefreshGroupMemberHitBar.md)
- [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md)
- [UID:0003TD][0x0050e810-0x0050e848.MapPaneRemoveGroupMemberHitBar](by-memory/0x0050e810-0x0050e848.MapPaneRemoveGroupMemberHitBar.md)
- [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md)
- [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md)
- [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md)
- [UID:0003TH][0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPane](by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPane.md)
- [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md)
- [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md)
- [UID:0003TU][0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet](by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md)
- [UID:0003TV][0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket](by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md)
- [UID:0003TW][0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay](by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md)
- [UID:0003TX][0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket](by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md)
- [UID:0003TY][0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket](by-memory/0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket.md)
- [UID:0003M3][0x00514d1e-0x00514d34.MapPaneDestructorAdjustorThunks](by-memory/0x00514d1e-0x00514d34.MapPaneDestructorAdjustorThunks.md)
- [UID:0003M4][0x00514de0-0x00514e1b.MapPaneScalarDeletingDestructor](by-memory/0x00514de0-0x00514e1b.MapPaneScalarDeletingDestructor.md)
- [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md)
- [UID:0001DA][0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer](by-memory/0x005388a0-0x005388b4.EffectObjectPaneStartIdleTimer.md)
- [UID:00009Q][ObjectList](by-class/ObjectList.md)
- [UID:0003IN][0x0061e6f0-0x0061e6f8.MapPaneCmapSignatureString](by-memory/0x0061e6f0-0x0061e6f8.MapPaneCmapSignatureString.md)
- [UID:0000G9][WorldMapPane](by-class/WorldMapPane.md)
- [UID:0000AG][PhotoPane](by-class/PhotoPane.md)
- [UID:00008H][MiniMapVersionManager](by-class/MiniMapVersionManager.md)
- [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md)
- [UID:0003IU][0x0061e924-0x0061e964.MapPaneCachePathStringsAndSelectionMarker](by-memory/0x0061e924-0x0061e964.MapPaneCachePathStringsAndSelectionMarker.md)
- [UID:0003IW][0x0061e9fc-0x0061ea24.MapPaneUserFaceAssetPathStrings](by-memory/0x0061e9fc-0x0061ea24.MapPaneUserFaceAssetPathStrings.md)
- [UID:0003JH][0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings](by-memory/0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings.md)
- [UID:0003JJ][0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings](by-memory/0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings.md)
- [UID:0003J0][0x0061eac0-0x0061ead4.MapPaneNumericConstants](by-memory/0x0061eac0-0x0061ead4.MapPaneNumericConstants.md)
- [UID:0003ZM][0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants](by-memory/0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants.md)

## Changes

- 2026-08-24 Agent-B006 UID00037R callback: corrected the existing `AddToLayer` declaration to non-const `RectBounds *` with `previousPane`, and added the exact two-method source, vtable, behavior, and dependency contract without changing unrelated class layout or declarations.
- 2026-07-16 Agent-B005 UID0003TT callback: preserved `93/94`, owner/emitter UID0000L3, position zero, exact `0x910` layout, and the complete managed declaration byte-for-byte; added only the exact source-ready UID0003TT behavior, dependencies, source order, unsafe semantics, UID0003HS route, and compiler exclusions.
- 2026-07-16 B004 UID0003TQ callback: preserved the complete shared managed class byte-for-byte and added only the exact action/combat packet source contract, four real child dependencies, unsafe behavior, compiler exclusions, and sole-definition route.

- 2026-07-15 Agent-B004 UID0003TO source-quality callback:
  - Added the complete source-ready opcode-`0x29` packet parse/routing surface, exact signed field semantics, conditional read extent, compiler-inlined `FlashMapColor(143)` explanation, ObjectList null/miss/double-lookup behavior, dependencies, source placement, negative evidence, rejected alternatives, and historical correction.
  - Preserved class `93/94`, owner/emitter UID0000L3, position 0, exact 0x910 layout, every B003/B004/B005/B011 declaration and fact, all current fields/methods/history, exact children, and the complete managed class formal byte-for-byte; UID0003TO remains the sole definition owner.

- 2026-07-15 Agent-B005 UID0003TK source-quality callback:
  - Added the complete source-ready opcode-`0x15` packet, cache/ObjectList, weather/movement, day/night, transient/waiting/EPF/config, dependency, negative, compiler, and historical surface.
  - Preserved class `93/94`, owner/emitter UID0000L3, position 0, all current fields/methods/history, exact children, and the complete managed class formal byte-for-byte; UID0003TK remains the sole definition owner.
- 2026-07-15 B003 UID0003TJ accepted source-quality callback:
  - Preserved `93/94`, UID0000L3 owner/emitter route, position `0`, inheritance, exact `0x910` layout, class close/size guard/`[[CHILDREN]]` placement, B004 unsigned-short HitBar contract, and every current declaration/history fact.
  - Applied exact R6 by changing only the disproven three-dword tile view to three unsigned shorts, adding `StaticObjectPane`/`StaticObjEntry` forward declarations, and adding typed `CreateStaticObjectPaneForTile`; `RefreshStaticObjectTileRegion` remains declared once.
  - Added exact UID0003TI/UID0003TJ/UID0004SI behavior, six-byte type, lifetime, source placement, compiler exclusions, ownership boundaries, UID000425 downstream correction, rejected alternatives, and historicalization of stale EDI/EAX/objectNation/0x10000 assumptions.

- 2026-07-15 B004 UID0003TG accepted source-quality callback:
  - Preserved `93/94`, UID0000L3 owner/emitter route, position `0`, exact complete class formal, `MapRect` alias, promoted coordinate-effect parameters, row-before-column create contract, every B005/B001 method/field declaration, and all unrelated content.
  - Added bounded class-level source-role and behavior evidence for private `ApplyEffectObjectPaneTimerAction`, including ordinary delete, full signed action domain, event-2 cancel/query/replace sequence, inferred `m_timerExtensionLocked`, typed TimerHandler conversion, dimensional quirk, source order, dependency boundaries, and superseded alternatives. No declaration, score, layout, source route, or unrelated formal changed.

- 2026-07-15 B005 UID0003TE accepted source-quality callback:
  - Preserved the complete `93/94` class union and exact 0x910 layout while adding only the accepted `typedef RectBounds MapRect`, private `RequestCoordinateEffect` declaration, and row-before-column `CreateEffectObjectPane` contract.
  - Added exact coordinate target behavior, one-caller/source-order evidence, four-call create-helper ABI proof, negative/rejected source alternatives, and compile-surface rationale without moving any method body into the class page.
  - Preserved all unrelated MapPane declarations, fields, children, B001/B002/B003/B004 content, `[[CHILDREN]]` placement, size guard, owner/emitter route, score, and compiler-lowering exclusions.

- 2026-07-15 B001 UID0003TF accepted source-quality callback:
  - Preserved the complete current `93/94` MapPane union and changed only the two accepted declaration surfaces: `renderAfterLivingObjects` on `RequestObjectEffect`, and `LivingObjectPane *target` plus `renderAfterLivingObjects` on `CreateEffectObjectPane`.
  - Synchronized exact target range/hash/ABI/callers, typed owner-list behavior, timer sentinels, ordinary-new lowering, UpdatePosition/bounds/invalidation tail, MapPane.cpp order, owner/emitter decision, rejected owners, negative evidence, and superseded provisional names.
  - Kept all unrelated MapPane methods, fields, scores, metadata, and `[[CHILDREN]]` content unchanged.

- 2026-07-15 B002 UID00037W accepted callback: raised the class to `91/92`; added the real UID0004RA-UID0004RH source inventory, seven complete class-member declaration contracts, exact paint/day-night/light fields and ordering, pointer-safe overlay/tint semantics, raw-helper liveness caps, compiler exclusions, and superseded assumptions while preserving the broad blank class formal and all unrelated MapPane union content.
- 2026-07-15 B002 UID0003UW callback: synchronized the exact MapPane group-member HitBar method names/order, UID0004R9 lookup dependency, typed state and caller roles, UID0003TC inline-equivalence reduction, active-only source delete, compiler exclusions, child scores, and superseded generic-event/activation history without changing broad MapPane metadata or formal C++.

- 2026-07-14 B005 UID00037V accepted source-quality callback: synchronized the exact getter/shared-tail/render split, source/no-source ownership, six getter refs, three paint calls, 191-block/39-callee render profile, complete render order, `+0x3f0` waiting-state lifecycle, `+0x3e0` overlay role, cumulative nesting, compiler exclusions, and superseded assumptions. Class score, owner/emitter route, and blank formal block remain unchanged.
- 2026-07-14 B003 UID0002Y1 bounded render-support synchronization:
  - Added exact RidingImageLib/MonsterImageLib slot-4 consumer evidence for MapPane `+0x3d0/+0x3d4/+0x3d8` as float tint, vertical scale/projection divisor, and horizontal shear.
  - Recorded public render-state access as the strongest source model because three unrelated image-library classes compile direct field loads; rejected protected-only access, per-class friendship, and invented out-of-line getters as weaker alternatives.
  - Preserved all day/night setter/curve history, contextual-alias caveats, `89/89` score, owner/emitter route, blank formal, and unrelated class evidence.

- 2026-07-14 Agent-B005 UID0002QK bounded class synchronization:
  - Preserved `89/89`, UID0000L3 owner/emitter, reconstructable state, blank formal, complete method/field inventory, and all unrelated MapPane detail.
  - Added source-ready `SaveCompressedMapFile` inventory/void ABI, exact hash/range/four ignored-return callers, direct CRT/CMAP/dimension/six-byte tile/zlib capacity flow, ordinary and Resize-exception failure behavior, tile/local-buffer/monster-clear order, paired StdioFile-load distinction, dependency ownership, compiler exclusions, rejected alternatives, and superseded blank-formal history.
- 2026-07-13 B003 UID0001KB bounded support synchronization:
  - Scores/owner/emitter/route/formal remain unchanged.
  - Added exact live opcode `0x67` payload parsing, null/static early return, `0x120` allocation, EPF/legacy positions, display-format expression, SetTimer/Delete mode flow, retained `0x005140a0` no-route duplicate proof, and the MapPane-consumer versus TimerPane-source ownership boundary.

- 2026-07-13 Agent-B003 UID0000ZW listener/callback synchronization:
  - Changed `88/87` to `89/89`; the broad class block remains blank and all exact bodies continue to emit through existing children.
  - Synchronized UID0002I7/UID0002QF inherited BackPane register/unregister expressions and replaced UID0002QI's provisional fake message type/name with `OnChangeMessage(LObject *, Message *)` and `MessageType`.
  - Preserved every unrelated MapPane packet/render/weather/object/helper child, field glossary, source route, ownership split, and open source-name caveat.

- 2026-07-06 Agent-B011 UID0003TL implementation callback:
  - Added packet-dispatch support for [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md): MCP session `b001-0001I5` reconfirmed opcode case `0x06`, `MapPane` receiver route, map/resource string updates, tile-buffer mutation, dirty redraw, and UID0003TJ static-object reconciliation.
  - Historically added source-facing MapPane field candidates used by that first-draft code, including `m_mapWidthTiles`, `m_mapHeightTiles`, and `m_mapTileRecords`. The UID0002QJ callback later superseded only those three aliases with established `m_mapWidth`, `m_mapHeight`, and `m_tileBuffer`; the remaining resource/name/refresh candidates and by-memory emission rule are unchanged.
- 2026-07-04 Agent-B003 UID000429 support sync:
  - Added current source-ready method inventory evidence for [UID:000429][0x00505730-0x00505731.MapPaneAfterLocalPlayerWarp](by-memory/0x00505730-0x00505731.MapPaneAfterLocalPlayerWarp.md): MCP session `nexustk_supervisor_20260704`, exact one-byte `C3` / `retn` body, `0x00505731` not-a-function/zero-xref padding, two direct post-warp callsites `0x005a79f5` and `0x005ab052`, cached `MapPane *` receiver load from `[ebx+0x1340f8]`, sibling/predecessor separation, nonunique one-byte signature caveat, rejected caller-owner/raw-name/padding/merge alternatives, and exact hook-name confidence cap. Class metadata and class-level formal C++ remain unchanged.
- 2026-07-04 Agent-B014 UID000428 support sync:
  - Added current source-ready method inventory evidence for [UID:000428][0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds](by-memory/0x00505650-0x00505730.MapPaneGetAdjacentVisibleTileBounds.md): MCP session `60724697`, exact size/range, child-owned align/jump-table bytes, two direct callers, helper/callee semantics, map width/height field reads, optional output copy, no local `MapPane`/`MapRect` UDT, local PE no-extra-route proof, successor separation, and RankingDialog alias rejection. Class metadata and class-level formal C++ remain unchanged.
- 2026-07-04 Agent-B006 UID00041X support sync:
  - Added current source-ready evidence for [UID:00041X][0x00505130-0x0050516a.MapPaneMapToScreenCoords](by-memory/0x00505130-0x0050516a.MapPaneMapToScreenCoords.md): MCP session `60724697`, exact range/size/bytes/padding, no callees, ten direct code xrefs, zero data/pointer route, `+0x3fc/+0x400` tile-origin and tile-dimension global use, and return-unused proof. Class metadata and blank class-level C++ remain unchanged.
- 2026-07-04 Agent-B008 UID000422 visible-span callback:
  - Refined the `+0x404/+0x408` field glossary and class-level visible-bounds note with current MCP session `60724697` proof for [UID:000422][0x00505350-0x0050536b.MapPaneGetVisibleTileSpan](by-memory/0x00505350-0x0050536b.MapPaneGetVisibleTileSpan.md): exact range/bytes, no callees, two `UserPane` constructor callsites, receiver proof through `UserPane +0x1340f8`, output row/column store order, padding/successor split, and rejected UserPane/RankingDialog/raw/padding/range-extension alternatives. Class metadata and class formal C++ remain unchanged.
- 2026-07-03 B005 UID000425 movement-collision callback: recorded current MCP session `e63ee655` proof for exact range `0x00505430-0x005055ca`, caller set, unconditional `m_activeObjectPane` bypass byte read, object-list/GM/passability gate, tile-layer helper calls, SOBJ globals, direction masks, and rejected ObjectList/LivingObjectPane/global/aggregate owners. Class metadata and class-level formal C++ remain unchanged.
- 2026-07-02 B014 UID00037Q object lookup helper split implementation:
  - Converted [UID:00037Q][0x00506970-0x00506cdd.MapPaneObjectLookupHelpers](by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md) to a non-emitting split/container and created exact MapPane child pages for object-id lookup, object screen-position/bounds update, six ObjectList-backed traversal wrappers, and null-checked object removal.
  - Synchronized class-level ownership: MapPane owns the wrapper/source route and `m_objectList` field access; ObjectList owns `FindByObjectId`, `GetTypedObjectKey`, `MoveKeyTo...`, `ResolveObjectListKey`, `RemoveObjectPane`, encoded-key decoding, storage-tier traversal, and final object-pointer resolution.
  - Score unchanged at `88/87`; the class page remains a high-level owner/source-route document while exact child pages carry method bodies or target-specific blank-C++ proof.
- 2026-07-01 Agent-B003 UID00042J source-quality callback:
  - Added the UID00042J-specific MapPane class note preserving current no-function/decompile/xref/pointer/local-name/generated-route evidence, row-bucket/object-refresh behavior, and blank-C++ non-emitting disposition. No class score or method emission changed.
- 2026-07-03 Agent-B006 UID00042A source-quality callback:
  - Added UID00042A-specific class/source-route wording: exact `c2 04 00` / `retn 4` no-op, one xref from `0x0053c385`, raw relay through `g_activeMapPane` and `MapPane::UpdateObjectPaneScreenBounds`, and no recovered inbound route to the relay. No class score or formal C++ changed.
- 2026-06-29 Agent-B013 UID000424 source-quality callback:
  - Added the coordinate/visible-bounds family note for [UID:000424][0x005053f0-0x0050542d.MapPaneGetUnclampedExtendedVisibleTileBounds](by-memory/0x005053f0-0x0050542d.MapPaneGetUnclampedExtendedVisibleTileBounds.md) as the non-emitting raw no-route unclamped sibling of [UID:000423][0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds](by-memory/0x00505370-0x005053e4.MapPaneGetExtendedVisibleTileBounds.md). No class score or formal C++ change; exact child pages still own method-body emission and UID000424 remains blank until an entry route is proven.
- 2026-06-25 Agent-B009 accepted 0001AP helper split:
  - Added class-level summary of exact coordinate/object/timer children [UID:00041W][0x00505080-0x00505100.MapPaneDirectionToTileOffset](by-memory/0x00505080-0x00505100.MapPaneDirectionToTileOffset.md) through [UID:00042J][0x005061e0-0x005062e5.MapPaneRefreshNearbyObjectRows](by-memory/0x005061e0-0x005062e5.MapPaneRefreshNearbyObjectRows.md), refined `+0x39d`, `+0x39e`, `+0x40e`, and `+0x8ec/+0x8f0` field notes, linked [UID:00042K][MapPaneLayout](by-type/by-struct/MapPaneLayout.md), and removed [UID:0001AP][0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore](by-memory/0x00503ef0-0x0050637a.MapPaneWeatherCoordinateObjectCore.md) from the unresolved coordinate/object interior backlog.
- 2026-06-24 B006 hit-test wrapper implementation:
  - Resolved [UID:0001AU][0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane](by-memory/0x00506ce0-0x00506d15.GeneratedBackPaneHitTestMapPane.md) as the bounds-checked public `MapPane::HitTestObjectAtPoint(y, x)` wrapper over inherited `Pane::m_bounds` / `RectBounds`.
  - Split the source-facing names so `0x0050c470` is the inner `MapPane::FindObjectAtMapPoint` row/object finder, not a duplicate public `HitTestObjectAtPoint`; preserved the `y, x` point order and rejected generated BackPane ownership as stale provenance only.
  - Removed 0001AU from the unresolved low-grade child priorities because the target now has MCP-backed range/body/caller evidence and formal C++.
- 2026-06-20 B007 object-effect descriptor implementation:
  - Added [UID:000232][0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch](by-memory/0x0050e320-0x0050e4b6.MapPaneObjectEffectDescriptorDispatch.md) as `MapPane::RequestObjectEffect(unsigned int objectId, int effectDescriptorId, int timerAction, bool compactFlag)`.
  - Documented helper boundaries for `MapPane::CreateEffectObjectPane` and `MapPane::ApplyEffectObjectPaneTimerAction`, including the by-value `EffectInfo` create-helper ABI, overloaded `timerAction` semantics, and secondary/type-4 before primary/type-2 pass order.
- 2026-06-21 B008 object-effect report incorporation:
  - Added the B008 recheck outcome for UID 000232: local PE/Capstone confirms MapPane class ownership, exact standalone range, caller set, no pointer/table dispatch, no generated destructor/EH content, and no split requirement.
  - Kept `RequestObjectEffect` over the report's `ApplyObjectEffect` recommendation because current source text and callers model request/reuse/cancel/timer behavior.
- 2026-06-19 B013 MapPane notify/timer split implementation:
  - Added class-level source-quality detail for [UID:00037U][0x00508f60-0x00509470.MapPaneNotifyTimerCore](by-memory/0x00508f60-0x00509470.MapPaneNotifyTimerCore.md) as a non-emitting split index with exact children [UID:0003ZT][0x00508f60-0x0050902b.MapPaneNotifyMessageCore](by-memory/0x00508f60-0x0050902b.MapPaneNotifyMessageCore.md) and [UID:0003ZS][0x00509030-0x00509439.MapPaneMovementTimerHandler](by-memory/0x00509030-0x00509439.MapPaneMovementTimerHandler.md).
  - Synchronized the input/timer method family, vtable slot evidence, adjusted TimerHandler-facet interpretation, timer ids `5/6/7/8`, alert guard versus `ConnectionClosedDialog` constructor distinction, field-role caveats for `+0x39d/+0x39e/+0x8ec..+0x90e`, helper ownership boundaries, excluded successor getter `0x00509470`, and child-only C++ emission policy.
- 2026-06-19 B005 MapPane tile/object-grid render core source-quality implementation:
  - Added the [UID:00037Y][0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore](by-memory/0x0050bce0-0x0050e320.MapPaneTileObjectGridRenderCore.md) class-level source-quality note. The note preserves the split-before-C++ policy, exact `0x0050e2f4-0x0050e320` tail split, MapPane field usage, inferred helper names, route-negative/raw helper caveats, dependency ownership, and rejected owner alternatives. The class formal C++ block remains blank; exact child pages own method-body emission.
- 2026-06-18 B005 visible-tile repaint source-quality incorporation:
  - Added [UID:0001AR][0x005051c0-0x00505228.DrawVisibleTilesHelper](by-memory/0x005051c0-0x00505228.DrawVisibleTilesHelper.md) to the class rendering surface as `MapPane::RedrawVisibleTiles()`, added `m_tileOriginX/m_tileOriginY` field-glossary entries, and tied `m_viewportGrafPort` at `+0x428` to the no-clear visible-tile repaint helper. Direct method emission remains on the exact child; the class-level C++ block stays blank pending stable header/class declaration output.
- 2026-06-18 B003 day/night packet raw-body source-quality:
  - Added day/night field glossary entries and synchronized [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md) with the class-level source route: the raw body is retained no-route duplicate evidence and must not emit standalone C++; live dispatcher opcode `0x20` or a future exact dispatcher-case child owns source output.
- 2026-06-18 B002 Rule 26 incorporation for [UID:00027I][0x0066daa2-0x0066daec.LegacyAssetRemapConstantsDataIsland](by-memory/0x0066daa2-0x0066daec.LegacyAssetRemapConstantsDataIsland.md):
  - Added the `0x0050c120` MapPane instance-helper evidence and class-vs-file placement note for [UID:0003ZM][0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants](by-memory/0x0066dabc-0x0066dad4.MapPaneLegacyMapTileRemapConstants.md). The constants are file-level statics, while the helper is an instance method because it reads MapPane dimension and tile-buffer fields.
- 2026-06-18 B002 MapPane class source-quality execution:
  - Raised class metadata to `88/87` while keeping [UID:0000L3][MapPane](by-file/MapPane.md) as canonical owner/emitter and leaving formal C++ blank.
  - Incorporated B002's class-level source-quality decisions without a detail cap: MapPane owns weather/day-night orchestration and `m_screenEffecters`; Effects owns runtime `ScreenEffecter` classes; WeatherLayer/Raining/Snowing/Swallow own overlay pane implementations; [UID:0001AX][0x00510400-0x005104c7.MapPaneDayNightPacketRawBody](by-memory/0x00510400-0x005104c7.MapPaneDayNightPacketRawBody.md) remains raw duplicate opcode `0x20` evidence; [UID:0001G6][0x00557140-0x00559aef.SurfacePresentation](by-memory/0x00557140-0x00559aef.SurfacePresentation.md) is excluded as mixed Surface/ScreenPane/ScreenshotCapture work; exact by-memory children own method-body C++; and the remaining blocker is a stable class/header declaration with final field, payload, descriptor, and generated-output names.
- 2026-06-18 B002 teardown/object-packet source-quality sync:
  - Added selected-object fields `+0x108/+0x10c`, deferred cleanup pane `+0x414`, sharpened `+0x41c/+0x420`, and recorded [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md)/[UID:0002QI][0x00504b70-0x00504b8f.MapPaneTagDetachMessage](by-memory/0x00504b70-0x00504b8f.MapPaneTagDetachMessage.md)/[UID:0002QO][0x005060f0-0x00506169.MapPaneRemoveObjectPaneById](by-memory/0x005060f0-0x00506169.MapPaneRemoveObjectPaneById.md)/[UID:0002QP][0x00506170-0x005061d3.MapPaneDetachObjectPane](by-memory/0x00506170-0x005061d3.MapPaneDetachObjectPane.md)/[UID:0002QQ][0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect](by-memory/0x005062f0-0x0050637a.MapPaneFindObjectIntersectingRect.md)/[UID:000231][0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper](by-memory/0x00506380-0x005063db.MapPaneOpcode0CObjectIdPacketHelper.md) source names, callback tag, class/file ownership split, and first-draft C++ readiness.
- 2026-06-16 B001 continuation split batch9:
  - Score unchanged at `85/85`.
  - Added class-owned packet handlers [UID:0003TX][0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket](by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md) and [UID:0003TY][0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket](by-memory/0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket.md). Related file-level helpers [UID:0003TU][0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet](by-memory/0x0050f4d0-0x0050f52a.MapPaneSendObjectAction43Packet.md), [UID:0003TV][0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket](by-memory/0x0050f9c0-0x0050fa1b.MapPaneSendCoordinate0APacket.md), and [UID:0003TW][0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay](by-memory/0x0050fa90-0x0050faf4.MapPaneRefreshObjectStatusOverlay.md) remain MapPane source-file helpers rather than instance methods. Opcode `0x33` now routes to object-info at `0x0050fb00`; opcode `0x03` remains the transition handler at `0x0050feb0`.
- 2026-06-16 B001 continuation split batch8:
  - Score unchanged at `85/85`.
  - Extended [UID:0003TN][0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket](by-memory/0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket.md) to include its owned switch table and added exact packet-handler children [UID:0003TO][0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket](by-memory/0x00511c90-0x00511dae.MapPaneHandleObjectMoveEffectPacket.md), [UID:0003TP][0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket](by-memory/0x00511db0-0x0051283a.MapPaneHandleObjectWorldMapCreationPacket.md), [UID:0003TQ][0x00512960-0x00512ca4.MapPaneHandleActionPacket](by-memory/0x00512960-0x00512ca4.MapPaneHandleActionPacket.md), [UID:0003TR][0x00512d60-0x00512f1c.MapPaneHandleFlyingObjectUpdatePacket](by-memory/0x00512d60-0x00512f1c.MapPaneHandleFlyingObjectUpdatePacket.md), [UID:0003TS][0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket](by-memory/0x00512f20-0x00513305.MapPaneHandleAnimationSoundPacket.md), and [UID:0003TT][0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket](by-memory/0x00513310-0x0051367b.MapPaneHandleObjectStatusPacket.md). The children document MapPane-owned direct-call opcode handlers while leaving WorldMapPane, object-pane classes, sound/effect classes, ObjectList, and protocol tables as dependencies or constructed-object owners.
- 2026-06-16 B001 continuation split batch7:
  - Score unchanged at `85/85`.
  - Added exact MapPane packet children [UID:0003TM][0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket](by-memory/0x00511440-0x00511703.MapPaneHandleDrawObjectsPacket.md) and [UID:0003TN][0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket](by-memory/0x00511710-0x005119ac.MapPaneHandleMovementSpeechBalloonPacket.md). The children document MapPane-owned draw-object/spawn and movement/speech-balloon packet routes while keeping ObjectList, object-pane classes, BalloonObjectPane, Socket, and protocol tables as dependencies or constructed-object owners.
- 2026-06-16 B001 continuation split batch6:
  - Score unchanged at `85/85`.
  - Added exact MapPane packet children [UID:0003TK][0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket](by-memory/0x005104d0-0x00510958.MapPaneHandleEffectMapStatePacket.md) and [UID:0003TL][0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket](by-memory/0x00510960-0x00511347.MapPaneHandleMapInfoTileRegionPacket.md). The children document MapPane-owned effect/map-state and map-info/tile-region packet routes while keeping ObjectList, StaticObjectPane, resource libraries, and protocol tables as dependencies rather than owners.
- 2026-06-16 B001 continuation split batch5:
  - Score unchanged at `85/85`.
  - Added exact MapPane static-object/tile children [UID:0003TI][0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile](by-memory/0x0050f030-0x0050f130.MapPaneCreateStaticObjectPaneForTile.md) and [UID:0003TJ][0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion](by-memory/0x0050f130-0x0050f26d.MapPaneRefreshStaticObjectTileRegion.md). The children document MapPane-owned tile-region static-object reconciliation while keeping StaticObjectPane, StaticObjImageLib, and ObjectList as constructed-object/provider/storage owners rather than owners of these MapPane helpers.
- 2026-06-16 B001 continuation split batch4:
  - Score unchanged at `85/85`.
  - Added exact MapPane packet/object-event child [UID:0003TH][0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPane](by-memory/0x0050edd0-0x0050eef5.MapPaneCreateHitBarObjectPane.md). The child documents the live combat/status packet route that constructs/registers a `HitBarObjectPane`; HitBarObjectPane and AttachedObjectPane remain the constructed-overlay class/file owners rather than owners of this MapPane packet helper.
- 2026-06-16 B001 continuation split batch3:
  - Score unchanged at `85/85`.
  - Added exact MapPane packet/effect children [UID:0003TE][0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch](by-memory/0x0050e850-0x0050ea30.MapPaneCoordinateEffectDescriptorDispatch.md), [UID:0003TF][0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane](by-memory/0x0050ea30-0x0050eb8a.MapPaneCreateEffectObjectPane.md), and [UID:0003TG][0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction](by-memory/0x0050eb90-0x0050ec2e.MapPaneApplyEffectObjectPaneTimerAction.md). The children document the MapPane-owned coordinate effect descriptor route, effect-object create/apply helper, and existing-effect timer action helper while keeping `EffectObjectPane`, `EffectObjImageLib`, and TimerMgr ownership separate.
- 2026-06-16 B001 continuation split batch:
  - Score unchanged at `85/85`.
  - Added exact MapPane packet/object-event children [UID:0003TC][0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane](by-memory/0x0050e690-0x0050e805.MapPaneApplyHitBarObjectPane.md) and [UID:0003TD][0x0050e810-0x0050e848.MapPaneRemoveGroupMemberHitBar](by-memory/0x0050e810-0x0050e848.MapPaneRemoveGroupMemberHitBar.md). The first child documents MapPane-owned HitBarObjectPane update/create policy, and the second documents MapPane object-id lookup and attached-overlay activation/clear side effects used by group and linked-object marker callers.
- 2026-06-16 B001 executable child-split addendum:
  - Score unchanged at `85/85`.
  - Added exact packet/event child [UID:0003TB][0x0050e4c0-0x0050e68d.MapPaneRefreshGroupMemberHitBar](by-memory/0x0050e4c0-0x0050e68d.MapPaneRefreshGroupMemberHitBar.md), the modeled MapPane process-map-event/object-marker helper that updates or creates HitBarObjectPane overlays while leaving HitBarObjectPane source ownership separate.
- 2026-06-08 B001/supervisor movement-scale ownership application:
  - Before: `COMPLETION:84`, `CONFIDENCE:80`.
  - After: `COMPLETION:85`, `CONFIDENCE:85`.
  - Evidence: B001's IDA pass tied [UID:0002CF][g_movementSubstepScale](by-global/g_movementSubstepScale.md) to this class's coordinate/movement helper surface: 23 read-only refs, no direct writes, `4 * byte_66DA96` coordinate divisors in MapPane helpers, MapTilePixelDimensions overlap in the same coordinate functions, and local-player/UserPane consumers calling back through MapPane movement helpers. Final C++ remains blank because packet structures, field names, and companion splits are still below final-source quality.
- 2026-06-12 A001 Batch 271:
  - Score unchanged at `85/85`.
  - Added the exact [UID:0003C1][0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings](by-memory/0x0061e6c0-0x0061e700.MapNameMiniMapResourceStrings.md) `CMAP` literal context while keeping [UID:0002ZN][0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer](by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md) as the MapPane-owned declaration/storage anchor.
- 2026-06-12 A002 Batch 325:
  - Score unchanged at `85/85`.
  - Updated the broad `CMAP` reference to exact child [UID:0003IN][0x0061e6f0-0x0061e6f8.MapPaneCmapSignatureString](by-memory/0x0061e6f0-0x0061e6f8.MapPaneCmapSignatureString.md), which routes through the same MapPane source-file fallback as [UID:0002ZN][0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer](by-memory/0x0066db48-0x0066db4c.MapPaneCmapSignaturePointer.md).
- 2026-06-12 C001 Batch C001-018:
  - Score unchanged at `85/85`.
  - Added exact MapPane resource-string split children [UID:0003IU][0x0061e924-0x0061e964.MapPaneCachePathStringsAndSelectionMarker](by-memory/0x0061e924-0x0061e964.MapPaneCachePathStringsAndSelectionMarker.md), [UID:0003IW][0x0061e9fc-0x0061ea24.MapPaneUserFaceAssetPathStrings](by-memory/0x0061e9fc-0x0061ea24.MapPaneUserFaceAssetPathStrings.md), and [UID:0003J0][0x0061eac0-0x0061ead4.MapPaneNumericConstants](by-memory/0x0061eac0-0x0061ead4.MapPaneNumericConstants.md) as file-owned MapPane literals/constants.
- 2026-06-12 C001 Batch C001-021:
  - Score unchanged at `85/85`.
  - Added exact MapPane-only resource-string children [UID:0003JH][0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings](by-memory/0x0061ea30-0x0061ea48.MapPaneWorldMapNameComparisonStrings.md) and [UID:0003JJ][0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings](by-memory/0x0061ea50-0x0061ea70.MapPaneWorldMapNameThreeFourStrings.md); shared [UID:0003JG][0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString](by-memory/0x0061ea24-0x0061ea30.SharedMapPaletteSuffixString.md) and [UID:0003JI][0x0061ea48-0x0061ea50.SharedWorldMap2UpperString](by-memory/0x0061ea48-0x0061ea50.SharedWorldMap2UpperString.md) remain parentless under the shared-owner gate.
- 2026-06-12 Agent-C001 Goal 2:
  - Score unchanged at `85/85`.
  - Updated the packet-handler cross-reference after [UID:0001AW][0x0050e4c0-0x00514920.MapPanePacketHandlers](by-memory/0x0050e4c0-0x00514920.MapPanePacketHandlers.md) was narrowed and rerouted to this class. Added exact destructor glue children for [UID:0003M3][0x00514d1e-0x00514d34.MapPaneDestructorAdjustorThunks](by-memory/0x00514d1e-0x00514d34.MapPaneDestructorAdjustorThunks.md) and [UID:0003M4][0x00514de0-0x00514e1b.MapPaneScalarDeletingDestructor](by-memory/0x00514de0-0x00514e1b.MapPaneScalarDeletingDestructor.md). Evidence: live IDA MCP proved the old aggregate tail crossed unrelated MapRefreshDimmer/vector/GameServerConfig ranges.
- 2026-06-07 A005 resolved-name cleanup:
  - Before: map packet evidence referenced the friend-list upload flag only as historical `byte_66DEE0`.
  - After: the page records resolved name `g_friendNameListSyncEnabled` beside the historical label.
  - Evidence: generated resolved-name report maps `byte_66DEE0` to `g_friendNameListSyncEnabled`; existing IDA-backed evidence already ties the flag write to inbound case `0x6a` before the opcode `0x77` upload helper.
- 2026-05-28: Updated the object/indexing family end from `0x00506379` to `0x0050637a` and added the adjacent opcode `0x0c` object-id packet helper. Evidence: IDA MCP reports `sub_5062f0` ending at `0x0050637a`, then a separate `sub_506380` helper at `0x00506380-0x005063db` called from MapPane packet/object paths.
- 2026-05-28: Added `0x0050e320-0x0050e4b6` as `MapPaneObjectEffectDescriptorDispatch` instead of leaving it in the UNKNOWN gap. Evidence: IDA MCP reports `sub_50e320` as a real function called from MapPane spawn/object-create paths and active-map consumers, with only alignment padding before `0x0050e4c0`.
- 2026-05-28: Added [UID:000235][0x00514f70-0x005151a9.MapPathDequeSupport](by-memory/0x00514f70-0x005151a9.MapPathDequeSupport.md) to MapPane cross-references as ignored compiler/STL support for path scanning. Evidence: IDA MCP xrefs to `0x00515110` come from MapPane path/cell scanning functions at `0x0050c790` and `0x0050d010`.
- 2026-05-28: Corrected the shared surface/presentation review bucket from `0x00557140-0x00559a0f` to `0x00557140-0x00559aef`. Evidence: IDA MCP identified `0x00559a10-0x00559aef` as real DirectDraw helper code belonging to the Surface review bucket, not MapPane ownership.
- Completion/confidence score update: existed before as `0/0`; changed to `84/78`. Summary: the live game-world pane is broadly and deeply documented across responsibility, method families, globals, packet/render/weather/map-transition dependencies, IDA anchors, ownership pollution, and open questions, but confidence stays medium because packet opcode splits, weather boundary duplication, source split, and several low-grade child methods remain unresolved. Evidence: linked MapPane memory ranges, IDA-confirmed anchor ranges, `g_activeMapPane`, `ObjectList`, packet opcode/type references, generated BackPane helper rechecks, and explicit ownership-pollution exclusions.
- 2026-06-02 reconstructable parent update:
  - What existed before: `RECONSTRUCTABLE:` and `AUTOGEN_PARENT_UID:` were blank, and confidence was `78`.
  - Changed to: `RECONSTRUCTABLE:TRUE`, `AUTOGEN_PARENT_UID:0000L3`, and `CONFIDENCE:80`.
  - Evidence: [UID:0000L3][MapPane](by-file/MapPane.md) is a validated `NexusTK/map/` source root with 80 confidence, and this class page records the live game-world pane responsibilities, singleton, packet/render/weather/object method families, IDA anchor ranges, and explicit ownership-pollution exclusions. C++ remains blank because final packet structures, field names, and companion file splits are still below the 95+ reconstruction threshold.

## B001 UID0003TY Map-Transition Declaration Synchronization - 2026-07-20

- The complete managed declaration now contains private `bool HandleMapTransitionPacket(const unsigned char *packet)` in exact packet-handler source order after `HandleObjectStatusPacket`. [UID:0003TY][0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket](by-memory/0x0050feb0-0x00510230.MapPaneHandleMapTransitionPacket.md) supplies the sole definition.
- Dispatcher case `0x03`, the sole direct call at `0x00507d13`, MapPane receiver state, and all-true return paths prove class ownership and the Boolean member signature. The method remains distinct from opcode-`0x33` [UID:0003TX][0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket](by-memory/0x0050fb00-0x0050feab.MapPaneHandleObjectInfoPacket.md).
- The target reads `m_localPlayerObjectPane` for transition-timer cancellation and coordinates UI, transport, registry, crash-report, and UserPane cleanup dependencies. Those callees retain their own class/file owners; none becomes a MapPane field or member body.
- The complete `0x910` layout, `m_localPlayerObjectPane` at the accepted position, every B001/B002/B003/B004/B005/B011 declaration and field, inheritance, access sections, score `93/94`, owner/emitter UID0000L3, position 0, class closure, size guard, and `[[CHILDREN]]` placement are preserved.
- Historical references that treated UID0003TY's body, field names, or registry/transport route as unresolved are superseded only for this declaration. No UID0003FV literal array, TransferServerDialogPane ownership transfer, Socket member, compiler EH body, or duplicate target definition is added.
