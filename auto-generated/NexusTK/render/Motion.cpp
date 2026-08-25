// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000LL
// Source by-file doc: by-file/Motion.md
// UID:00008R | by-class/Motion.md | Completion:92 | Confidence:93
#include "../util/PoolAllocator.h"
#include "../ui/core/BlackHole.h"

class Motion : public LObject, public TimerHandler
{
public:
    Motion(LivingObjectPane *owner, int motionType,
           int timerDelay, char soundOverride);
    Motion(LivingObjectPane *owner, int motionType,
           char terminalFrame, int timerDelay, char soundOverride);
    virtual ~Motion() {}
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    LivingObjectPane *m_owner;
    int m_motionType;
    short m_soundEffectId;
    char m_soundTriggerFrame;
    char m_currentFrame;
    char m_terminalFrame;
    int m_timerDelay;
};
// UID:0002WR | by-memory/0x0069b984-0x0069b9ac.MotionPoolStaticStorage.md | Completion:88 | Confidence:93
static PoolAllocator g_motionPool(0x1c, 0x10);

// UID:0002QW | by-memory/0x00539bc0-0x00539d43.MotionAnimationConstructor.md | Completion:90 | Confidence:92
Motion::Motion(LivingObjectPane *owner, int motionType, int timerDelay, char soundOverride)
    : LObject(),
      TimerHandler()
{
    m_timerDelay = timerDelay;
    m_owner = owner;
    m_motionType = motionType;
    m_currentFrame = -1;

    switch (motionType)
    {
    case 1:
    case 2:
        m_terminalFrame = 2;
        m_soundTriggerFrame = 1;
        break;

    case 22:
        m_terminalFrame = 4;
        m_soundTriggerFrame = 0;
        break;

    case 27:
        m_terminalFrame = 2;
        m_soundTriggerFrame = 1;
        owner->ShowName();
        break;

    case 28:
        m_terminalFrame = 2;
        m_soundTriggerFrame = 0;
        owner->HideName();
        break;

    default:
        if ((motionType >= 3 && motionType <= 21) || motionType == 23 || motionType == 24)
            m_terminalFrame = 1;
        else
            m_terminalFrame = 0;
        m_soundTriggerFrame = 0;
        break;
    }

    if (soundOverride < 0)
    {
        m_soundEffectId = -1;
        return;
    }

    switch (motionType)
    {
    case 2:
        m_soundEffectId = 709;
        break;
    case 4:
        m_soundEffectId = 406;
        break;
    case 8:
        m_soundEffectId = 403;
        break;
    case 9:
        m_soundEffectId = 312;
        break;
    case 10:
        m_soundEffectId = 313;
        break;
    case 11:
        m_soundEffectId = 300;
        break;
    case 12:
    case 23:
        m_soundEffectId = 301;
        break;
    case 13:
        m_soundEffectId = 302;
        break;
    case 14:
    case 24:
        m_soundEffectId = 303;
        break;
    case 15:
        m_soundEffectId = 304;
        break;
    case 16:
        m_soundEffectId = g_pConfig->m_hearSnoreMode ? 305 : -1;
        break;
    case 17:
        m_soundEffectId = 306;
        break;
    case 18:
        m_soundEffectId = 307;
        break;
    case 19:
        m_soundEffectId = 308;
        break;
    case 20:
        m_soundEffectId = 309;
        break;
    case 21:
        m_soundEffectId = 310;
        break;
    case 22:
        m_soundEffectId = 311;
        break;
    default:
        m_soundEffectId = soundOverride;
        break;
    }
}

// UID:0002QX | by-memory/0x00539de0-0x00539f52.MotionAnimationAlternateConstructor.md | Completion:90 | Confidence:92
Motion::Motion(LivingObjectPane *owner, int motionType, char terminalFrame, int timerDelay, char soundOverride)
    : LObject(),
      TimerHandler()
{
    m_owner = owner;
    m_timerDelay = timerDelay;
    m_terminalFrame = terminalFrame;

    char requestedSound = -1;
    if (soundOverride != 0)
        requestedSound = soundOverride;

    m_motionType = motionType;
    m_currentFrame = -1;

    switch (motionType)
    {
    case 1:
    case 2:
        m_soundTriggerFrame = 1;
        break;
    case 27:
    case 28:
        break;
    default:
        m_soundTriggerFrame = 0;
        break;
    }

    if (requestedSound < 0)
    {
        m_soundEffectId = -1;
        return;
    }

    switch (motionType)
    {
    case 2:
        m_soundEffectId = 709;
        break;
    case 4:
        m_soundEffectId = 406;
        break;
    case 8:
        m_soundEffectId = 403;
        break;
    case 9:
        m_soundEffectId = 312;
        break;
    case 10:
        m_soundEffectId = 313;
        break;
    case 11:
        m_soundEffectId = 300;
        break;
    case 12:
        m_soundEffectId = 301;
        break;
    case 13:
        m_soundEffectId = 302;
        break;
    case 14:
        m_soundEffectId = 303;
        break;
    case 15:
        m_soundEffectId = 304;
        break;
    case 16:
        m_soundEffectId = (g_pConfig->m_hearSnoreMode == 1) ? 305 : -1;
        break;
    case 17:
        m_soundEffectId = 306;
        break;
    case 18:
        m_soundEffectId = 307;
        break;
    case 19:
        m_soundEffectId = 308;
        break;
    case 20:
        m_soundEffectId = 309;
        break;
    case 21:
        m_soundEffectId = 310;
        break;
    case 22:
        m_soundEffectId = 311;
        break;
    case 23:
        m_soundEffectId = 314;
        break;
    case 24:
        m_soundEffectId = 315;
        break;
    default:
        m_soundEffectId = requestedSound;
        break;
    }
}

// UID:0002QY | by-memory/0x00539fe0-0x0053a10c.MotionOnTimer.md | Completion:92 | Confidence:94
bool Motion::OnTimer(int timerId, int, int)
{
    if (timerId != 0)
        return true;

    if (m_owner->m_nameVisible != 1 ||
        m_currentFrame < m_terminalFrame - 2)
    {
        ++m_currentFrame;
    }

    if (m_soundEffectId != -1 &&
        m_currentFrame == m_soundTriggerFrame)
    {
        g_pSoundManager->PlaySample(
            m_soundEffectId,
            (4U * g_pSoundManager->GetSampleVolume()) / 5U);
    }

    if (m_currentFrame < m_terminalFrame)
    {
        g_pTimerMgr->ScheduleTimer(this, 0, m_timerDelay, 0, 0);
        if (m_owner->m_currentEffect != this)
            m_owner->m_currentEffect = this;
    }
    else
    {
        const int effectCount = m_owner->m_activeEffects->GetCount();
        for (int i = 0; i < effectCount; ++i)
        {
            Motion *effect = *static_cast<Motion **>(
                m_owner->m_activeEffects->GetElementAt(i));
            if (effect == this)
            {
                m_owner->m_activeEffects->RemoveAt(i, 1);
                break;
            }
        }

        if (m_owner->m_currentEffect != 0)
            m_owner->m_currentEffect = 0;

        g_pApplicationCleanupQueue->EnqueueIfMissing(this);
    }

    g_activeMapPane->UpdateObjectPaneScreenBounds(m_owner);
    return true;
}


// UID:000356 | by-memory/0x00620950-0x0062096c.MotionVtableData.md | Completion:88 | Confidence:92
// Compiler-emitted RTTI/vtable data for [UID:00008R][Motion](by-class/Motion.md) Motion is regenerated from
// the Motion class declaration, virtual destructor/timer slots, and the
// [UID:0000LL][Motion](by-file/Motion.md) Motion.cpp source route. Do not hand-author raw RTTI locator or
// vftable dword arrays for [UID:000356].

// UID:0002QZ | by-memory\0x0053d590-0x0053d614.MotionAnimationScalarDeletingDestructor.md | Completion:88 | Confidence:92 | Empty Emitter Marker
