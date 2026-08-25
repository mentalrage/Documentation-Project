// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KU
// Source by-file doc: by-file/LivingObjectPane.md
// UID:00007B | by-class/LivingObjectPane.md | Completion:92 | Confidence:93
#include "LivingObjectPane.h"
#include "../util/PoolAllocator.h"

// UID:00007C | by-class/LivingObjectPane__BoxRotator.md | Completion:90 | Confidence:93
// Covered by LivingObjectPane::BoxRotator in UID00007B.

// UID:0004QF | by-memory/0x0053aaf0-0x0053ab1a.LivingObjectPaneSetSpriteAttribute.md | Completion:91 | Confidence:93
void LivingObjectPane::SetSpriteAttribute(unsigned char value)
{
    if (m_objectStatus.m_weaponId != value)
    {
        m_objectStatus.m_weaponId = value;
        g_activeMapPane->UpdateObjectPaneScreenBounds(this);
    }
}

// UID:0004QG | by-memory/0x0053ab20-0x0053ab3a.LivingObjectPaneSetMovingState.md | Completion:92 | Confidence:94
void LivingObjectPane::SetMovingState(bool moving)
{
    m_isMoving = moving;
    if (!moving)
        m_moveFrame = 0;
}

// UID:0004QH | by-memory/0x0053ab40-0x0053ad03.LivingObjectPaneDestroyAllLinkedObjects.md | Completion:92 | Confidence:94
void LivingObjectPane::DestroyAllLinkedObjects()
{
    DestroyAttachedObjects();

    delete m_balloonObjectPane;
    m_balloonObjectPane = NULL;

    if (m_primaryEffectObjectPanes != NULL)
    {
        for (int index = m_primaryEffectObjectPanes->GetCount() - 1;
             index >= 0;
             --index)
        {
            EffectObjectPane *pane =
                *static_cast<EffectObjectPane **>(
                    m_primaryEffectObjectPanes->GetElementAt(index));
            pane->SetLivingObjectPane(NULL);
        }
    }

    if (m_secondaryEffectObjectPanes != NULL)
    {
        for (int index = m_secondaryEffectObjectPanes->GetCount() - 1;
             index >= 0;
             --index)
        {
            EffectObjectPane *pane =
                *static_cast<EffectObjectPane **>(
                    m_secondaryEffectObjectPanes->GetElementAt(index));
            pane->SetLivingObjectPane(NULL);
        }
    }

    delete m_hitBarObjectPane;
    m_hitBarObjectPane = NULL;
    delete m_damageNumberObjectPane;
    m_damageNumberObjectPane = NULL;
    delete m_objectInfoObjectPane;
    m_objectInfoObjectPane = NULL;

    if (m_secondaryEffectObjectPanes != NULL)
    {
        const int count = m_secondaryEffectObjectPanes->GetCount();
        for (int index = 0; index < count; ++index)
        {
            EffectObjectPane *pane =
                *static_cast<EffectObjectPane **>(
                    m_secondaryEffectObjectPanes->GetElementAt(index));
            if (pane->m_effectId == 134)
            {
                delete pane;
                break;
            }
        }
    }

    delete m_primaryEffectObjectPanes;
    delete m_secondaryEffectObjectPanes;
    m_secondaryEffectObjectPanes = NULL;
    m_primaryEffectObjectPanes = NULL;
}

// UID:0004QI | by-memory/0x0053ad10-0x0053ad9f.LivingObjectPaneDestroyAttachedObjects.md | Completion:91 | Confidence:92
void LivingObjectPane::DestroyAttachedObjects()
{
    if (m_primaryEffectObjectPanes != NULL)
    {
        for (int index = m_primaryEffectObjectPanes->GetCount() - 1;
             index >= 0;
             --index)
        {
            EffectObjectPane *pane =
                *static_cast<EffectObjectPane **>(
                    m_primaryEffectObjectPanes->GetElementAt(index));
            g_activeMapPane->RemoveObjectPaneIfPresent(pane);
            delete pane;
        }
    }

    if (m_secondaryEffectObjectPanes != NULL)
    {
        for (int index = m_secondaryEffectObjectPanes->GetCount() - 1;
             index >= 0;
             --index)
        {
            EffectObjectPane *pane =
                *static_cast<EffectObjectPane **>(
                    m_secondaryEffectObjectPanes->GetElementAt(index));
            g_activeMapPane->RemoveObjectPaneIfPresent(pane);
            delete pane;
        }
    }
}

// UID:0004QJ | by-memory/0x0053ada0-0x0053adb0.LivingObjectPaneSetBalloonObjectPane.md | Completion:92 | Confidence:94
void LivingObjectPane::SetBalloonObjectPane(BalloonObjectPane *pane)
{
    m_balloonObjectPane = pane;
}

// UID:0004QK | by-memory/0x0053adb0-0x0053ae06.LivingObjectPaneAddPrimaryEffectObjectPane.md | Completion:92 | Confidence:94
void LivingObjectPane::AddPrimaryEffectObjectPane(EffectObjectPane *pane)
{
    for (int index = m_primaryEffectObjectPanes->GetCount() - 1;
         index >= 0;
         --index)
    {
        EffectObjectPane *existing =
            *static_cast<EffectObjectPane **>(
                m_primaryEffectObjectPanes->GetElementAt(index));
        if (existing->m_effectId == pane->m_effectId)
            delete existing;
    }

    m_primaryEffectObjectPanes->Append(1, &pane);
}

// UID:0004QL | by-memory/0x0053ae10-0x0053ae66.LivingObjectPaneAddSecondaryEffectObjectPane.md | Completion:92 | Confidence:94
void LivingObjectPane::AddSecondaryEffectObjectPane(EffectObjectPane *pane)
{
    for (int index = m_secondaryEffectObjectPanes->GetCount() - 1;
         index >= 0;
         --index)
    {
        EffectObjectPane *existing =
            *static_cast<EffectObjectPane **>(
                m_secondaryEffectObjectPanes->GetElementAt(index));
        if (existing->m_effectId == pane->m_effectId)
            delete existing;
    }

    m_secondaryEffectObjectPanes->Append(1, &pane);
}

// UID:0004QM | by-memory/0x0053ae70-0x0053ae80.LivingObjectPaneSetHitBarObjectPane.md | Completion:92 | Confidence:94
void LivingObjectPane::SetHitBarObjectPane(HitBarObjectPane *pane)
{
    m_hitBarObjectPane = pane;
}

// UID:0004QN | by-memory/0x0053ae80-0x0053ae90.LivingObjectPaneSetDamageNumberObjectPane.md | Completion:92 | Confidence:94
void LivingObjectPane::SetDamageNumberObjectPane(DamageNumberObjectPane *pane)
{
    m_damageNumberObjectPane = pane;
}

// UID:0004QO | by-memory/0x0053ae90-0x0053aeb4.LivingObjectPaneSetObjectInfoObjectPane.md | Completion:92 | Confidence:94
void LivingObjectPane::SetObjectInfoObjectPane(ObjectInfoObjectPane *pane)
{
    delete m_objectInfoObjectPane;
    m_objectInfoObjectPane = pane;
}

// UID:0001DF | by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md | Completion:92 | Confidence:93
void LivingObjectPane::UnregisterAttachedObjectPane(AttachedObjectPane *pane)
{
    if (pane == NULL)
        return;

    List *list = NULL;
    switch (pane->GetObjectType())
    {
    case kObjectPaneTypePrimaryEffect:
        list = m_primaryEffectObjectPanes;
        break;

    case kObjectPaneTypeSecondaryEffect:
        list = m_secondaryEffectObjectPanes;
        break;

    case kObjectPaneTypeBalloon:
        m_balloonObjectPane = NULL;
        return;

    case kObjectPaneTypeHitBar:
        m_hitBarObjectPane = NULL;
        return;

    case kObjectPaneTypeDamageNumber:
        if (g_useEpfAssets)
            m_damageNumberObjectPane = NULL;
        return;

    case kObjectPaneTypeObjectInfo:
        m_objectInfoObjectPane = NULL;
        return;

    default:
        return;
    }

    const int count = list->GetCount();
    for (int index = 0; index < count; ++index)
    {
        AttachedObjectPane *entry =
            *static_cast<AttachedObjectPane **>(list->GetElementAt(index));
        if (entry == pane)
        {
            list->RemoveAt(index, 1);
            return;
        }
    }
}

// UID:0003Z5 | by-memory/0x0053b060-0x0053b6b3.LivingObjectPaneEffectMovementAndActionHelpers.md | Completion:90 | Confidence:92
void LivingObjectPane::AddMotion(Motion *effect)
{
    while (m_activeEffects->GetCount() > 2)
    {
        const int index = m_activeEffects->GetCount() - 3;
        Motion *oldEffect = *static_cast<Motion **>(
            m_activeEffects->GetElementAt(index));
        if (oldEffect != 0)
        {
            oldEffect->RemovePendingTimers();
            delete oldEffect;
        }
        m_activeEffects->RemoveAt(index, 1);
        if (m_currentEffect == oldEffect)
            m_currentEffect = 0;
    }

    m_activeEffects->Append(1, &effect);
}

void LivingObjectPane::RemoveMotion(Motion *effect)
{
    const int effectCount = m_activeEffects->GetCount();
    for (int i = 0; i < effectCount; ++i)
    {
        Motion *storedEffect = *static_cast<Motion **>(
            m_activeEffects->GetElementAt(i));
        if (storedEffect == effect)
        {
            m_activeEffects->RemoveAt(i, 1);
            break;
        }
    }
}

void LivingObjectPane::ClearAllEffects()
{
    const int effectCount = m_activeEffects->GetCount();
    for (int i = 0; i < effectCount; ++i)
    {
        Motion *effect = *static_cast<Motion **>(
            m_activeEffects->GetElementAt(i));
        delete effect;
    }
    m_activeEffects->RemoveAll();
    m_renderEffectState = 0;
    m_currentEffect = 0;
}

void LivingObjectPane::SetCurrentMotion(Motion *effect)
{
    if (m_currentEffect != effect)
        m_currentEffect = effect;
}

void LivingObjectPane::SetHighlightState(bool highlighted)
{
    if (m_highlighted == highlighted)
        return;

    m_highlighted = highlighted;
    if (highlighted)
        m_boxRotator.Start();
    else
        m_boxRotator.Stop();
    Invalidate(false);
}

void LivingObjectPane::ShowDamageEffect(int value, short soundId)
{
    g_pSoundManager->PlaySample(soundId, 100);
    if (m_objectStatus.m_statusKind == ObjectStatusBlob::MonsterObject &&
        m_objectStatus.m_appearanceId > 0x8173 &&
        m_objectStatus.m_appearanceId < 0x8187)
        return;

    m_renderEffectState = value;
    Invalidate(&m_bounds);
    g_pTimerMgr->ScheduleTimer(
        static_cast<TimerHandler *>(this),
        kLivingTimerRefresh, 120, 0, 0);
}

bool LivingObjectPane::BeginMoveTo(int x, int y, unsigned char facing, short stepDelay)
{
    m_facing = facing;

    if (m_isMoving)
    {
        CancelTimer(kLivingTimerForwardStep);
        if (TryStepForward())
            return true;

        if (m_highlighted)
        {
            m_highlighted = true;
            m_boxRotator.Start();
            Invalidate(false);
        }

        m_renderEffectState = 0;
    }

    m_facing = facing;
    if (m_mapX != x || m_mapY != y)
        SetMapPosition(x, y);

    m_isMoving = true;
    m_moveFrame = 0;
    g_pTimerMgr->ScheduleTimer(
        static_cast<TimerHandler *>(this),
        kLivingTimerForwardStep, stepDelay, facing, stepDelay);
    return g_pActiveMapPane->InvalidateObject(this);
}

void LivingObjectPane::SetFacing(unsigned char facing)
{
    if (m_isMoving)
    {
        g_pTimerMgr->ScheduleTimer(
            static_cast<TimerHandler *>(this),
            kLivingTimerDirectionDelay,
            m_objectStatus.m_displayStatusByte,
            facing, 0);
        return;
    }

    m_facing = facing;
    if (m_objectStatus.m_statusKind == ObjectStatusBlob::MonsterObject)
        PlayAnimation(facing + 1);
    g_pActiveMapPane->InvalidateObject(this);
}

void LivingObjectPane::PlayActionAnimationOrEffect(unsigned action, int value, unsigned char facing)
{
    if (m_objectStatus.m_statusKind == ObjectStatusBlob::MonsterObject)
    {
        if (m_animationGroup != 0 && m_animationGroup <= 8)
        {
            const bool canPlayActionGroup = (m_nameBuffer[0] == L'\0');
            switch (action)
            {
            case 0:  PlayAnimation(m_facing + 5); break;
            case 1:  PlayAnimation(m_facing + 13); break;
            case 2:  if (canPlayActionGroup) PlayAnimation(m_facing + 17); break;
            case 3:  if (canPlayActionGroup) PlayAnimation(m_facing + 21); break;
            case 4:  if (canPlayActionGroup) PlayAnimation(m_facing + 25); break;
            case 5:  if (canPlayActionGroup) PlayAnimation(m_facing + 29); break;
            case 6:  return;
            case 25: PlayAnimation(m_facing + 9); break;
            default: if (canPlayActionGroup) PlayAnimation(4); break;
            }
        }
        return;
    }

    if (action == 25)
        return;
    if (m_nameVisible && action != 27 && action != 4 && action != 6)
        return;
    if (action == 27)
        ClearAllEffects();

    Motion *effect = 0;
    void *storage = g_motionPool.Allocate();
    if (storage != 0)
        effect = new (storage) Motion(this, action, static_cast<short>(value), facing);

    while (m_activeEffects->GetCount() > 2)
    {
        const int index = m_activeEffects->GetCount() - 3;
        Motion *oldEffect = *static_cast<Motion **>(
            m_activeEffects->GetElementAt(index));
        if (oldEffect != 0)
        {
            oldEffect->RemovePendingTimers();
            delete oldEffect;
        }
        m_activeEffects->RemoveAt(index, 1);
        if (m_currentEffect == oldEffect)
            m_currentEffect = 0;
    }

    m_activeEffects->Append(1, &effect);
    g_pTimerMgr->ScheduleTimer(
        effect != 0 ? static_cast<TimerHandler *>(effect) : 0,
        0, 0, 0, 0);
}

// UID:0002R1 | by-memory/0x0053b700-0x0053baa8.LivingObjectPaneAnimationTimer.md | Completion:88 | Confidence:89
void LivingObjectPane::PlayAnimation(unsigned int animationGroup)
{
    if (m_objectStatus.m_statusKind != ObjectStatusBlob::MonsterObject)
        return;

    CancelTimer(kLivingTimerFrameAnimation);

    MonsterImageEntry *entry =
        g_pMonsterImageLib->GetEntryByIndex(
            m_objectStatus.m_appearanceId - 0x8000);
    ImageAnimationGroup *frameGroup = entry->GetGroup(animationGroup);
    if (frameGroup->frameCount == 0)
    {
        if (animationGroup == 0)
            g_activeMapPane->RemoveObjectPaneById(m_objectId);
        return;
    }

    m_animationFrame = 0;
    m_animationGroup = animationGroup;

    const ImageAnimationFrame *frame = frameGroup->GetFrame(0);
    g_pTimerMgr->ScheduleTimer(
        static_cast<TimerHandler *>(this),
        kLivingTimerFrameAnimation,
        frame->frameDuration,
        0,
        0);
    g_activeMapPane->UpdateObjectPaneScreenBounds(this);
}

void LivingObjectPane::PlayFacingAnimation()
{
    PlayAnimation(m_facing + 1);
}

void LivingObjectPane::PlayDeathAnimation()
{
    m_terminalAnimation = true;
    PlayAnimation(0);
    g_activeMapPane->ClearLivingObjectReferences(this);
}

bool LivingObjectPane::OnTimer(int timerId, int arg0, int arg1)
{
    switch (timerId)
    {
    case kLivingTimerForwardStep:
        m_moveFrame = (m_moveFrame + 1) % 4;
        if (m_moveFrame != 0)
        {
            g_pTimerMgr->ScheduleTimer(
                static_cast<TimerHandler *>(this),
                kLivingTimerForwardStep,
                arg1,
                arg0,
                arg1);
            PropagateLinkedObjectMode(m_facing);
            return true;
        }

        TryStepForward();
        return true;

    case kLivingTimerBoxStep:
        m_boxRotationStep = (m_boxRotationStep + 1) % 6;
        g_pTimerMgr->ScheduleTimer(
            static_cast<TimerHandler *>(this),
            kLivingTimerBoxStep,
            200,
            0,
            0);
        g_activeMapPane->UpdateObjectPaneScreenBounds(this);
        return true;

    case kLivingTimerDirectionDelay:
        if (m_isMoving)
        {
            g_pTimerMgr->ScheduleTimer(
                static_cast<TimerHandler *>(this),
                kLivingTimerDirectionDelay,
                m_objectStatus.m_displayStatusByte,
                arg0,
                0);
            return true;
        }

        m_facing = static_cast<unsigned char>(arg0);
        if (m_objectStatus.m_statusKind == ObjectStatusBlob::MonsterObject)
            PlayAnimation(static_cast<unsigned char>(arg0) + 1);
        g_activeMapPane->UpdateObjectPaneScreenBounds(this);
        return true;

    case kLivingTimerFrameAnimation:
    {
        MonsterImageEntry *entry =
            g_pMonsterImageLib->GetEntryByIndex(
                m_objectStatus.m_appearanceId - 0x8000);
        ImageAnimationGroup *frameGroup =
            entry->GetGroup(m_animationGroup);
        ++m_animationFrame;

        if (m_animationFrame == frameGroup->frameCount)
        {
            if (m_terminalAnimation)
                g_activeMapPane->RemoveObjectPaneById(m_objectId);
            else
            {
                m_animationFrame = 0;
                PlayAnimation(m_facing + 1);
            }
            return true;
        }

        const ImageAnimationFrame *frame =
            frameGroup->GetFrame(m_animationFrame);
        g_pTimerMgr->ScheduleTimer(
            static_cast<TimerHandler *>(this),
            kLivingTimerFrameAnimation,
            frame->frameDuration,
            0,
            0);
        Invalidate(false);
        g_activeMapPane->UpdateObjectPaneScreenBounds(this);
        return true;
    }

    case kLivingTimerRefresh:
        if (m_renderEffectState != 0)
        {
            m_renderEffectState = 0;
            Invalidate(&m_bounds);
        }
        return true;

    default:
        return false;
    }
}

// UID:0003Z6 | by-memory/0x0053bab0-0x0053bb1d.LivingObjectPaneNameplateSpecialEffectHelpers.md | Completion:92 | Confidence:93
void LivingObjectPane::RequestNameplateEffect()
{
    g_activeMapPane->RequestObjectEffect(m_objectId, 135, -2, false);
}

void LivingObjectPane::RemoveSpecialEffect()
{
    if (m_secondaryEffectObjectPanes == NULL)
        return;

    const int count = m_secondaryEffectObjectPanes->GetCount();
    for (int index = 0; index < count; ++index)
    {
        EffectObjectPane *pane =
            *static_cast<EffectObjectPane **>(
                m_secondaryEffectObjectPanes->GetElementAt(index));
        if (pane != NULL && pane->m_effectId == 134)
        {
            delete pane;
            return;
        }
    }
}

// UID:0003NU | by-memory/0x0053bb20-0x0053bd1c.LivingObjectPaneRenderFrame.md | Completion:89 | Confidence:89
void LivingObjectPane::RenderFrame(GrafPort *target, const RectBounds *bounds)
{
    FrameDrawRecord *translatedClipRecord = 0;
    float translatedClipOffset = 0.0f;
    const bool useMapLightOverlay = g_pActiveMapPane->ShouldUseLivingObjectLightOverlay();

    if (m_elevationOffset != 0.0f)
    {
        if (g_pActiveMapPane->ShouldOffsetElevatedLivingObjects())
        {
            translatedClipRecord = target->m_translatedClipRecord;
            translatedClipOffset = target->m_translatedClipOffsetY + m_elevationOffset;
        }
    }

    if (m_objectStatus.m_statusKind != ObjectStatusBlob::HumanObject)
    {
        if (m_animationGroup < 9 && m_isMoving)
        {
            g_pMonsterImageLib->RenderMonsterImage(
                target,
                bounds,
                &m_objectStatus,
                m_facing + 5,
                m_renderEffectState,
                m_moveFrame,
                useMapLightOverlay,
                translatedClipRecord,
                translatedClipOffset);
        }
        else
        {
            g_pMonsterImageLib->RenderMonsterImage(
                target,
                bounds,
                &m_objectStatus,
                m_animationGroup,
                m_renderEffectState,
                m_animationFrame,
                useMapLightOverlay,
                translatedClipRecord,
                translatedClipOffset);
        }
    }
    else
    {
        g_pNewHumanImageLib->Draw(
            target,
            bounds,
            &m_objectStatus,
            m_facing,
            m_currentEffect,
            m_renderEffectState,
            m_moveFrame,
            useMapLightOverlay,
            translatedClipRecord,
            translatedClipOffset,
            0,
            m_isMoving,
            m_boxRotationStep);
    }

    if (m_markerOverlayEnabled)
    {
        const unsigned int *colors = kLivingObjectMarkerFrameColors + m_markerOverlayIndex;

        if (g_pActiveMapPane->UsesAlternateLivingObjectMarkerColors())
        {
            const int colorSet = g_pActiveMapPane->GetLivingObjectMarkerColorSet();
            if (colorSet == 0)
                colors = kLivingObjectMarkerColorSet0 + m_markerOverlayIndex;
            else if (colorSet == 1)
                colors = kLivingObjectMarkerColorSet1 + m_markerOverlayIndex;
        }

        target->m_drawMode = 0;

        RectBounds markerBounds = *bounds;
        target->SetDrawColor(colors[0]);
        target->DrawRectFrame(&markerBounds);

        for (int i = 1; i < 4; ++i)
        {
            markerBounds.Inset(1, 1);
            target->SetDrawColor(colors[i]);
            target->DrawRectFrame(&markerBounds);
        }
    }
}

// UID:0003NV | by-memory/0x0053bd20-0x0053bdb1.LivingObjectPaneDrawSpriteFrame.md | Completion:88 | Confidence:89
void LivingObjectPane::DrawSpriteFrame(GrafPort *target, const RectBounds *bounds)
{
    if (m_objectStatus.m_statusKind != ObjectStatusBlob::HumanObject)
    {
        if (m_animationGroup < 9 && m_isMoving)
        {
            g_pMonsterImageLib->RenderMonster(
                target,
                bounds,
                &m_objectStatus,
                m_facing + 5,
                m_moveFrame);
        }
        else
        {
            g_pMonsterImageLib->RenderMonster(
                target,
                bounds,
                &m_objectStatus,
                m_animationGroup,
                m_animationFrame);
        }
        return;
    }

    g_pNewHumanImageLib->RenderHuman(
        target,
        bounds,
        &m_objectStatus,
        m_facing,
        m_currentEffect,
        m_moveFrame,
        m_isMoving,
        m_boxRotationStep);
}

// UID:0003NW | by-memory/0x0053bdc0-0x0053beb6.LivingObjectPaneComputeRenderBounds.md | Completion:88 | Confidence:89
RectBounds *LivingObjectPane::ComputeRenderBounds(RectBounds *outBounds)
{
    MapCoordinatePair screenPoint;
    RectBounds imageBounds;
    RectBounds renderBounds;

    g_pActiveMapPane->GetObjectScreenPoint(this, &screenPoint);

    if (m_objectStatus.m_statusKind != ObjectStatusBlob::HumanObject)
    {
        if (m_animationGroup < 9 && m_isMoving)
        {
            g_pMonsterImageLib->ComputeRenderBounds(
                &m_objectStatus,
                m_facing + 5,
                m_moveFrame,
                &imageBounds,
                &renderBounds);
        }
        else
        {
            g_pMonsterImageLib->ComputeRenderBounds(
                &m_objectStatus,
                m_animationGroup,
                m_animationFrame,
                &imageBounds,
                &renderBounds);
        }
    }
    else
    {
        g_pNewHumanImageLib->CalculateBounds(
            &m_objectStatus,
            m_facing,
            m_currentEffect,
            m_moveFrame,
            &imageBounds,
            &renderBounds,
            0,
            m_isMoving,
            m_boxRotationStep);
    }

    renderBounds.Offset(screenPoint.x, screenPoint.y);
    *outBounds = renderBounds;
    return outBounds;
}

// UID:0003Z7 | by-memory/0x0053bec0-0x0053c367.LivingObjectPaneLinkedPositionAndModeHelpers.md | Completion:91 | Confidence:93
void LivingObjectPane::SetMapPosition(int x, int y)
{
    if (m_mapX == x && m_mapY == y)
        return;
    g_activeMapPane->MoveObject(this, m_mapY, m_mapX, y, x);
    Invalidate(false);
    m_mapX = x;
    m_mapY = y;
    Invalidate(false);
    CancelTimer(kLivingTimerForwardStep);
    RefreshAllLinkedObjects();
    m_isMoving = false;
}

void LivingObjectPane::ScheduleBoxRotationStep()
{
    CancelTimer(kLivingTimerBoxStep);
    g_pTimerMgr->ScheduleTimer(
        static_cast<TimerHandler *>(this), kLivingTimerBoxStep, 1, 0, 0);
}

void LivingObjectPane::CancelBoxRotationStep()
{
    CancelTimer(kLivingTimerBoxStep);
}

void LivingObjectPane::ApplyLinkedObjectMode(int mode)
{
    PropagateModeToLinkedObject(m_balloonObjectPane, mode);
    PropagateModeToAttachedList(m_primaryEffectObjectPanes, mode);
    PropagateModeToAttachedList(m_secondaryEffectObjectPanes, mode);
    PropagateModeToLinkedObject(m_hitBarObjectPane, mode);
    if (g_useEpfAssets)
        PropagateModeToLinkedObject(m_damageNumberObjectPane, mode);
    PropagateModeToLinkedObject(m_objectInfoObjectPane, mode);
}

void LivingObjectPane::SyncPositionToLinkedObjects()
{
    SyncOneLinkedObjectPosition(m_balloonObjectPane);
    SyncAttachedListPositions(m_primaryEffectObjectPanes);
    SyncAttachedListPositions(m_secondaryEffectObjectPanes);
    SyncOneLinkedObjectPosition(m_hitBarObjectPane);
    if (g_useEpfAssets)
        SyncOneLinkedObjectPosition(m_damageNumberObjectPane);
    SyncOneLinkedObjectPosition(m_objectInfoObjectPane);
}

void LivingObjectPane::RefreshAllLinkedObjects()
{
    RefreshOneLinkedObject(m_balloonObjectPane);
    RefreshAttachedList(m_primaryEffectObjectPanes);
    RefreshAttachedList(m_secondaryEffectObjectPanes);
    RefreshOneLinkedObject(m_hitBarObjectPane);
    if (g_useEpfAssets)
        RefreshOneLinkedObject(m_damageNumberObjectPane);
    RefreshOneLinkedObject(m_objectInfoObjectPane);
}

void LivingObjectPane::PropagateLinkedObjectMode(int mode)
{
    g_activeMapPane->InvalidateObject(this);
    ApplyLinkedObjectMode(mode);
}

// UID:0003Z8 | by-memory/0x0053c390-0x0053c5da.LivingObjectPaneTryStepForward.md | Completion:86 | Confidence:88
bool LivingObjectPane::TryStepForward()
{
    if (!m_isMoving)
        return false;

    m_moveFrame = 0;
    m_isMoving = false;

    NxPoint delta = DirectionToTileDelta(m_facing);
    const int nextX = m_tileX + delta.x;
    const int nextY = m_tileY + delta.y;

    MapBounds bounds;
    g_pActiveMapPane->GetVisibleMapBounds(&bounds);
    if (!IsPointInRect(nextY, nextX, bounds))
    {
        g_pActiveMapPane->RejectMove(m_objectId);
        return true;
    }

    const int oldX = m_tileX;
    const int oldY = m_tileY;
    m_tileX = nextX;
    m_tileY = nextY;

    g_pActiveMapPane->MoveObject(this, oldY, oldX, nextY, nextX);
    OnLinkedObjectModeChanged(m_facing);
    SyncPositionToLinkedObjects();
    RefreshAllLinkedObjects();
    return false;
}

// UID:0002R3 | by-memory/0x0053d430-0x0053d589.LivingObjectPaneScalarDeletingDestructor.md | Completion:90 | Confidence:93
// Emitted code for this range is covered by [UID:0002R0][0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup](by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md).

// UID:0003ZA | by-memory/0x0053d800-0x0053d818.LivingObjectPaneNameVisibilityVtableMethods.md | Completion:86 | Confidence:90
void LivingObjectPane::ShowName()
{
    m_nameVisible = true;
}

void LivingObjectPane::HideName()
{
    m_nameVisible = false;
}


// UID:0002WL | by-memory/0x0069b894-0x0069b8bc.LivingObjectPanePoolStaticStorage.md | Completion:88 | Confidence:93
static PoolAllocator g_livingObjectPanePool(0x20c, 0x20);


// UID:000233 | by-memory/0x00514ea0-0x00514edd.LivingObjectPaneGmNameSuffixCheck.md | Completion:88 | Confidence:92
bool LivingObjectPane::HasGMNameSuffix() const
{
    const wchar_t *end = m_nameBuffer + 2;
    while (*end != L'\0')
        ++end;

    return _wcsicmp(end - 2, L"GM") == 0;
}

// UID:0003Z3 | by-memory/0x0053a6b0-0x0053aae9.LivingObjectPaneSpriteConfigHelpers.md | Completion:88 | Confidence:90
unsigned char RemapMovementDirectionForMapScroll(unsigned char direction)
{
    switch (direction)
    {
    case 1:
        return 3;
    case 2:
        return 0;
    case 3:
        return 1;
    default:
        return 2;
    }
}

// 0x0053a6f0-0x0053a6fb is a no-function/no-xref code-shaped island
// inside the switch-table/padding gap; it is documented but not emitted as
// a callable source helper until a caller or source route is proven.

void LivingObjectPane::GetRenderBounds(NxRect *imageRect, NxRect *screenRect) const
{
    if (g_activeMapPane == 0)
        return;

    if (m_objectStatus.m_statusKind != ObjectStatusBlob::HumanObject)
    {
        if (g_activeMapPane->IsHighResolutionMode())
        {
            if (m_animationGroup < 9 && m_isMoving)
                g_pMonsterImageLib->GetFrameBounds(m_objectStatus, m_facing + 5, m_moveFrame, imageRect, &m_bounds);
            else
                g_pMonsterImageLib->GetFrameBounds(m_objectStatus, m_animationGroup, m_animationFrame, imageRect, &m_bounds);

            OffsetBoundsByObjectAnchor(imageRect, m_bounds);
        }
        else
        {
            g_pMonsterImageLib->GetFrameBounds(m_objectStatus, m_animationGroup, m_animationFrame, imageRect, 0);
        }
    }
    else
    {
        g_pNewHumanImageLib->GetFrameBounds(m_objectStatus,
                                            m_facing,
                                            m_currentEffect,
                                            m_moveFrame,
                                            imageRect,
                                            g_activeMapPane->IsHighResolutionMode() ? &m_bounds : 0,
                                            0,
                                            m_isMoving,
                                            m_boxRotationStep);

        if (g_activeMapPane->IsHighResolutionMode())
            OffsetBoundsByObjectAnchor(imageRect, m_bounds);
    }

    g_activeMapPane->BuildObjectScreenRect(this, imageRect, screenRect);
}

void LivingObjectPane::GetSpriteConfig(ObjectStatusBlob *out) const
{
    *out = m_objectStatus;
}

bool LivingObjectPane::SetSpriteConfig(const ObjectStatusBlob *config, unsigned char facing)
{
    if (m_objectStatus.m_statusKind != config->m_statusKind)
    {
        m_objectStatus = *config;

        if (m_isMoving && TryStepForward())
            return true;
    }

    CancelPendingTimersExceptEvent(kLivingTimerRefresh);
    m_moveFrame = 0;

    if (config->m_statusKind == ObjectStatusBlob::MonsterObject)
        PlayAnimation(facing + 1);

    m_objectStatus = *config;
    m_facing = facing;
    CancelTimer(kLivingTimerDirectionDelay);

    HideName();
    return g_activeMapPane->InvalidateObject(this);
}

void LivingObjectPane::InitializeSpriteConfig(const ObjectStatusBlob *config, unsigned char facing)
{
    m_objectStatus = *config;
    m_facing = facing;
    m_currentEffect = 0;
    m_isMoving = false;
    m_moveFrame = 0;
    m_animationFrame = 0;
    m_terminalAnimation = false;
    m_highlighted = false;

    HideName();

    m_animationGroup = facing + 1;

    if (m_objectStatus.m_statusKind == ObjectStatusBlob::MonsterObject)
    {
        const int delay = g_pMonsterImageLib->GetFrameDelay(m_objectStatus.m_appearanceId - 0x8000,
                                                           m_animationGroup,
                                                           m_animationFrame);
        g_pTimerMgr->ScheduleTimer(
            static_cast<TimerHandler *>(this),
            kLivingTimerFrameAnimation, delay, 0, 0);
    }

    m_nameState = 0;
    m_boxRotationPhase = 0;
    m_boxRotator.m_owner = this;
}

// UID:0003UU | by-memory/0x005ac070-0x005ac1a8.LivingObjectPaneHandleMessageShowPacket.md | Completion:88 | Confidence:90
static bool HandleMessageShowPacket(const unsigned char *packet)
{
    char multiByteText[0x8000];
    wchar_t wideText[0x8000];

    if (packet[1] == 0) {
        if (g_pMessageShowPane != NULL) {
            delete g_pMessageShowPane;
        }

        return true;
    }

    unsigned int textLength = PacketBufferReadUInt16BE(packet + 2);
    memmove(multiByteText, packet + 4, textLength);

    if (textLength >= 0x8000) {
        __report_rangecheckfailure();
    }

    multiByteText[textLength] = '\0';

    unsigned int wideLength = (unsigned short)MultiByteToWideChar(
        0,
        0,
        multiByteText,
        textLength,
        wideText,
        0x8000);

    if (wideLength >= 0x8000) {
        __report_rangecheckfailure();
    }

    wideText[wideLength] = L'\0';

    if (g_pMessageShowPane != NULL) {
        g_pMessageShowPane->SetWrappedText(wideText);
    } else {
        new MessageShowPane(wideText);
    }

    return true;
}

// UID:000358 | by-memory\0x00620978-0x00620a38.LivingObjectPaneVtableData.md | Completion:90 | Confidence:94 | Empty Emitter Marker

// UID:0001TR | by-type\by-struct\AttachedObjectRegistryLayout.md | Completion:92 | Confidence:94 | Empty Emitter Marker

// UID:0003IO | by-memory\0x0061e6f8-0x0061e700.SharedGmWideString.md | Completion:88 | Confidence:93 | Empty Emitter Marker

// UID:0003JN | by-memory\0x006309dc-0x006309f4.UserPaneArrowShortageWarningString.md | Completion:86 | Confidence:92 | Empty Emitter Marker
