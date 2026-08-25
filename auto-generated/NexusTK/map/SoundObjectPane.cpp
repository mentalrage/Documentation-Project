// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NW
// Source by-file doc: by-file/SoundObjectPane.md
// UID:0000DH | by-class/SoundObjectPane.md | Completion:92 | Confidence:94
#include "../util/PoolAllocator.h"

class SoundObjectPane : public ObjectPane
{
public:
    struct SoundDescriptor
    {
        int kind;
        unsigned int sampleId;
        int volumeScale;
    };

    struct SoundOrigin
    {
        enum Type
        {
            kObject = 0,
            kMapPosition = 1,
            kNone = 2
        };

        int type;
        union
        {
            ObjectPane *object;
            int mapX;
        };
        int mapY;
    };

    enum PlaybackMode
    {
        kDestroyWithoutPlayback = 0,
        kPlayOnceAndDestroy = 1,
        kPlayOnce = 2,
        kRepeatPlayback = 3,
        kRandomRepeatPlayback = 4
    };

    enum LifetimePolicy
    {
        kPersistent = 0,
        kPlayCount = 1,
        kTimeout = 2
    };

    enum TimerId
    {
        kRepeatTimer = 0,
        kLifetimeTimer = 1
    };

    SoundObjectPane(int mapX,
                    int mapY,
                    const SoundDescriptor &sound,
                    const SoundOrigin &origin,
                    int playbackMode,
                    int repeatDelayMilliseconds,
                    float playProbability,
                    int lifetimePolicy,
                    int lifetimeValue);
    virtual ~SoundObjectPane();

    void StartPlayback();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

private:
    SoundDescriptor m_sound;
    SoundOrigin m_origin;
    int m_playbackMode;
    int m_repeatDelayMilliseconds;
    float m_playProbability;
    int m_lifetimePolicy;
    int m_lifetimeValue;
    int m_remainingPlayCount;
};

// UID:0002WN | by-memory/0x0069b8e4-0x0069b90c.SoundObjectPanePoolStaticStorage.md | Completion:91 | Confidence:94
static PoolAllocator g_soundObjectPanePool(0x158, 0x20);

// UID:0004PV | by-memory/0x0053ca20-0x0053cab4.SoundObjectPaneConstructor.md | Completion:92 | Confidence:94
SoundObjectPane::SoundObjectPane(
    int mapX,
    int mapY,
    const SoundDescriptor &sound,
    const SoundOrigin &origin,
    int playbackMode,
    int repeatDelayMilliseconds,
    float playProbability,
    int lifetimePolicy,
    int lifetimeValue)
    : ObjectPane(11, 0, mapX, mapY),
      m_sound(sound),
      m_origin(origin),
      m_playbackMode(playbackMode),
      m_repeatDelayMilliseconds(repeatDelayMilliseconds),
      m_playProbability(playProbability),
      m_lifetimePolicy(lifetimePolicy),
      m_lifetimeValue(lifetimeValue)
{
}

// UID:0004PW | by-memory/0x0053cac0-0x0053cb48.SoundObjectPaneDestructor.md | Completion:92 | Confidence:94
SoundObjectPane::~SoundObjectPane()
{
    if (m_origin.type == SoundOrigin::kObject &&
        m_origin.object != NULL) {
        m_origin.object->ClearSoundObjectPane();
    }

    g_activeMapPane->RemoveObjectPaneIfPresent(this);
}

// UID:0004PX | by-memory/0x0053cb50-0x0053cc5c.SoundObjectPaneStartPlayback.md | Completion:93 | Confidence:94
void SoundObjectPane::StartPlayback()
{
    switch (m_playbackMode) {
    case kDestroyWithoutPlayback:
        delete this;
        return;

    case kPlayOnceAndDestroy:
        g_pSoundManager->PlaySample(
            m_sound.sampleId, m_sound.volumeScale);
        delete this;
        return;

    case kPlayOnce:
        switch (m_lifetimePolicy) {
        case kPersistent:
            g_pSoundManager->PlaySample(
                m_sound.sampleId, m_sound.volumeScale);
            break;

        case kPlayCount:
            g_pSoundManager->PlaySample(
                m_sound.sampleId, m_sound.volumeScale);
            delete this;
            break;

        case kTimeout:
            g_pSoundManager->PlaySample(
                m_sound.sampleId, m_sound.volumeScale);
            g_pTimerMgr->ScheduleTimer(
                static_cast<TimerHandler *>(this),
                kLifetimeTimer,
                1000 * m_lifetimeValue,
                0,
                0);
            break;
        }
        return;

    case kRepeatPlayback:
    case kRandomRepeatPlayback:
        g_pTimerMgr->ScheduleTimer(
            static_cast<TimerHandler *>(this),
            kRepeatTimer,
            0,
            0,
            0);

        if (m_lifetimePolicy == kPlayCount) {
            m_remainingPlayCount = m_lifetimeValue;
        } else if (m_lifetimePolicy == kTimeout) {
            g_pTimerMgr->ScheduleTimer(
                static_cast<TimerHandler *>(this),
                kLifetimeTimer,
                1000 * m_lifetimeValue,
                0,
                0);
        }
        return;
    }
}

// UID:0004PY | by-memory/0x0053cc70-0x0053ce3c.SoundObjectPaneOnTimer.md | Completion:93 | Confidence:94
bool SoundObjectPane::OnTimer(int timerId, int, int)
{
    if (m_playbackMode == kPlayOnce) {
        if (m_lifetimePolicy == kTimeout &&
            timerId == kLifetimeTimer) {
            delete this;
        }
        return true;
    }

    if (m_playbackMode != kRepeatPlayback &&
        m_playbackMode != kRandomRepeatPlayback) {
        return true;
    }

    if (m_lifetimePolicy == kPersistent) {
        if (timerId == kRepeatTimer) {
            if (m_playbackMode == kRepeatPlayback ||
                m_playProbability * 32767.0f >
                    static_cast<float>(rand())) {
                g_pSoundManager->PlaySample(
                    m_sound.sampleId, m_sound.volumeScale);
            }

            g_pTimerMgr->ScheduleTimer(
                static_cast<TimerHandler *>(this),
                kRepeatTimer,
                m_repeatDelayMilliseconds,
                0,
                0);
        }
        return true;
    }

    if (m_lifetimePolicy == kPlayCount) {
        if (timerId == kRepeatTimer) {
            if (m_remainingPlayCount > 0) {
                if (m_playbackMode == kRepeatPlayback ||
                    m_playProbability * 32767.0f >
                        static_cast<float>(rand())) {
                    g_pSoundManager->PlaySample(
                        m_sound.sampleId, m_sound.volumeScale);
                }

                --m_remainingPlayCount;
                g_pTimerMgr->ScheduleTimer(
                    static_cast<TimerHandler *>(this),
                    kRepeatTimer,
                    m_repeatDelayMilliseconds,
                    0,
                    0);
            } else {
                delete this;
            }
        }
        return true;
    }

    if (m_lifetimePolicy == kTimeout) {
        if (timerId == kRepeatTimer) {
            if (m_playbackMode == kRepeatPlayback ||
                m_playProbability * 32767.0f >
                    static_cast<float>(rand())) {
                g_pSoundManager->PlaySample(
                    m_sound.sampleId, m_sound.volumeScale);
            }

            g_pTimerMgr->ScheduleTimer(
                static_cast<TimerHandler *>(this),
                kRepeatTimer,
                m_repeatDelayMilliseconds,
                0,
                0);
        } else if (timerId == kLifetimeTimer) {
            delete this;
        }
    }

    return true;
}

// UID:00035A | by-memory/0x00620ae4-0x00620b90.SoundObjectPaneVtableData.md | Completion:91 | Confidence:94
// Emitted code for this range is covered by [UID:0000DH][SoundObjectPane](by-class/SoundObjectPane.md).

// UID:0003CB | by-memory/0x00620c6c-0x00620c70.SoundObjectPaneRandomThresholdConstant.md | Completion:91 | Confidence:94
// Emitted code for this range is covered by [UID:0000DH][SoundObjectPane](by-class/SoundObjectPane.md).
