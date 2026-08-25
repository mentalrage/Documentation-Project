// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000NX
// Source by-file doc: by-file/SoundStatusPane.md
// UID:0000SB | by-global/g_pSoundStatusPane.md | Completion:94 | Confidence:95
#include "SoundStatusPane.h"

SoundStatusPane *g_pSoundStatusPane = NULL;

template <>
Singleton<SoundStatusPane>::Singleton()
{
    g_pSoundStatusPane = static_cast<SoundStatusPane *>(this);
}

template <>
Singleton<SoundStatusPane>::~Singleton()
{
    g_pSoundStatusPane = NULL;
}

// UID:0000DJ | by-class/SoundStatusPane.md | Completion:94 | Confidence:95
#include "../../app/Application.h"
#include "../../audio/MidiPlayer.h"
#include "../../audio/SoundManager.h"
#include "../../config/Config.h"
#include "../../render/Surface.h"
#include "../core/Event.h"
#include "SoundStatusPane.h"

#include <cwchar>

// UID:0001IG | by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md | Completion:94 | Confidence:95
SoundStatusPane::SoundStatusPane()
    : Pane(1), Singleton<SoundStatusPane>()
{
    m_statusLeft = g_screenWidth - 354;
    m_statusRight = m_statusLeft + 114;
    m_statusTop = g_screenHeight - 11;
    m_statusBottom = m_statusTop + 12;

    RectBounds statusBounds;
    InitRectBounds(&statusBounds,
                   m_statusLeft,
                   m_statusTop,
                   m_statusRight,
                   m_statusBottom);
}

SoundStatusPane::~SoundStatusPane()
{
}

bool SoundStatusPane::HandleKeyOrTextEvent(Event *event)
{
    unsigned char modifiers = event->m_payload.m_key.m_modifiers;
    unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        modifiers);

    if (event->m_type != kEventKeyDown) {
        return false;
    }

    if (key == 'm' && modifiers == kEventModifierControl) {
        if (g_pSoundManager->IsSoundEffectsEnabled()) {
            g_pSoundManager->DisableSoundEffects();
            g_pConfig->m_soundEffectsEnabled = 0;
        } else {
            g_pSoundManager->EnableSoundEffects();
            g_pConfig->m_soundEffectsEnabled = 1;
        }
    } else if (key == 'M' &&
               (modifiers & kEventModifierControl) != 0) {
        if (g_pMidiPlayer->IsPlaybackEnabled()) {
            g_pMidiPlayer->DisableMidiPlayback();
            g_pSoundManager->MuteMusic();
        } else {
            g_pMidiPlayer->EnableMidiPlayback();
            g_pSoundManager->UnmuteMusic();
        }
    } else {
        return false;
    }

    InvalidateRect(&m_visibleBounds);
    return true;
}

void SoundStatusPane::OnPaint()
{
    SetDrawMode(0);
    SetDrawColor(0);
    g_pfnFillRect(this, &m_visibleBounds);

    SetTextDrawMode(0);
    SetTextColor(0x8f);
    SetTextBackFillColor(0);
    MoveTo(0, 11);

    const wchar_t *musicStatus =
        g_pSoundManager->IsPlaybackEnabled() ? L"Music On" : L"Music Off";
    const wchar_t *soundStatus =
        g_pSoundManager->IsSoundEffectsEnabled() ? L"Sound On" : L"Sound Off";

    wchar_t statusText[128];
    swprintf_s(statusText, 128, L"%s/%s", soundStatus, musicStatus);
    DrawWideText(statusText, static_cast<int>(wcslen(statusText)));
}
