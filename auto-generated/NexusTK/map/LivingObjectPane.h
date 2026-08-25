// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KU
// Source by-file doc: by-file/LivingObjectPane.md
// UID:00007B | by-class/LivingObjectPane.md | Completion:92 | Confidence:93
#ifndef NEXUSTK_MAP_LIVINGOBJECTPANE_H
#define NEXUSTK_MAP_LIVINGOBJECTPANE_H

#include "ObjectPane.h"
#include "../ui/core/FrameMgr.h"

class Motion;
class List;
class AttachedObjectPane;
class BalloonObjectPane;
class EffectObjectPane;
class HitBarObjectPane;
class DamageNumberObjectPane;
class ObjectInfoObjectPane;
class BowGaugeObjectPane;
class FittingRoomListPane;
class NewInventoryPane;
class GrafPort;
struct NxRect;

class LivingObjectPane : public ObjectPane
{
public:
    enum TimerMessage
    {
        kLivingTimerForwardStep = 0x41645746,
        kLivingTimerBoxStep = 0x41534246,
        kLivingTimerDirectionDelay = 0x43684469,
        kLivingTimerFrameAnimation = 0x446e4146,
        kLivingTimerRefresh = 0x52654461
    };

    class BoxRotator : public FrameHandler
    {
    public:
        explicit BoxRotator(LivingObjectPane *owner) : m_owner(owner) {}
        virtual ~BoxRotator() {}

        virtual void Advance(int frame);
        void Start();
        void Stop();

    private:
        friend class LivingObjectPane;
        LivingObjectPane *m_owner;
    };

    LivingObjectPane(
        int objectId,
        int mapX,
        int mapY,
        const ObjectStatusBlob &objectStatus,
        unsigned char facing);
    LivingObjectPane(int objectId, int mapX, int mapY, unsigned char facing);
    virtual ~LivingObjectPane();

    void GetSpriteConfig(ObjectStatusBlob *out) const;
    bool SetSpriteConfig(const ObjectStatusBlob *objectStatus, unsigned char facing);
    void InitializeSpriteConfig(const ObjectStatusBlob *objectStatus, unsigned char facing);
    bool HasGMNameSuffix() const;

    void SetMovingState(bool moving);
    void DestroyAllLinkedObjects();
    void DestroyAttachedObjects();
    void SetBalloonObjectPane(BalloonObjectPane *pane);
    void AddPrimaryEffectObjectPane(EffectObjectPane *pane);
    void AddSecondaryEffectObjectPane(EffectObjectPane *pane);
    void SetHitBarObjectPane(HitBarObjectPane *pane);
    void SetDamageNumberObjectPane(DamageNumberObjectPane *pane);
    void SetObjectInfoObjectPane(ObjectInfoObjectPane *pane);
    void UnregisterAttachedObjectPane(AttachedObjectPane *pane);

    void AddMotion(Motion *effect);
    void RemoveMotion(Motion *effect);
    void ClearAllEffects();
    void SetCurrentMotion(Motion *effect);
    void SetHighlightState(bool highlighted);
    void ShowDamageEffect(int value, short soundId);
    bool BeginMoveTo(int x, int y, unsigned char facing, short stepDelay);
    void SetFacing(unsigned char facing);
    void PlayAnimation(unsigned int animationGroup);
    void PlayFacingAnimation();
    void PlayDeathAnimation();
    void RequestNameplateEffect();
    void RemoveSpecialEffect();
    void ScheduleBoxRotationStep();
    void CancelBoxRotationStep();
    void ApplyLinkedObjectMode(int mode);
    void SyncPositionToLinkedObjects();
    void RefreshAllLinkedObjects();

    virtual void GetRenderBounds(NxRect *imageRect, NxRect *screenRect) const;
    virtual void RenderFrame(GrafPort *target, const RectBounds *bounds);
    virtual RectBounds *ComputeRenderBounds(RectBounds *outBounds);
    virtual void DrawSpriteFrame(GrafPort *target, const RectBounds *bounds);
    virtual void SetMapPosition(int x, int y);
    virtual void SetSpriteAttribute(unsigned char value);
    virtual void PlayActionAnimationOrEffect(
        unsigned action,
        int value,
        unsigned char facing);
    virtual void ShowName();
    virtual void HideName();
    virtual void PropagateLinkedObjectMode(int mode);
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    friend class MapPane;
    friend class Motion;
    friend class BowGaugeObjectPane;
    friend class FittingRoomListPane;
    friend class NewInventoryPane;

    bool TryStepForward();

protected:
    unsigned char m_nameState;
    wchar_t m_nameBuffer[33];
    unsigned int m_objectInfoType;
    List *m_primaryEffectObjectPanes;
    List *m_secondaryEffectObjectPanes;
    ObjectStatusBlob m_objectStatus;
    List *m_activeEffects;
    Motion *m_currentEffect;
    bool m_isMoving;
    unsigned char m_facing;
    signed char m_moveFrame;
    unsigned int m_animationFrame;
    unsigned int m_animationGroup;
    bool m_terminalAnimation;
    bool m_nameVisible;
    unsigned int m_boxRotationStep;
    BalloonObjectPane *m_balloonObjectPane;
    HitBarObjectPane *m_hitBarObjectPane;
    DamageNumberObjectPane *m_damageNumberObjectPane;
    ObjectInfoObjectPane *m_objectInfoObjectPane;
    bool m_highlighted;
    unsigned int m_boxRotationPhase;
    BoxRotator m_boxRotator;
    unsigned int m_renderEffectState;
    RectBounds m_bounds;
};

typedef char LivingObjectPaneSizeMustBe524[
    sizeof(LivingObjectPane) == 0x20c ? 1 : -1];

#endif // NEXUSTK_MAP_LIVINGOBJECTPANE_H
